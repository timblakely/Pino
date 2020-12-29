#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

#include <utility>

#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_spi.h"

namespace platform {
namespace stm32g4 {

// Getting around the anonymous struct issue.
struct Spi::SPI_TypeDefI : public SPI_TypeDef {};

Spi::Spi(Gpio::Pin chip_select, Gpio::Pin clock, Gpio::Pin mosi, Gpio::Pin miso)
    : cs_(chip_select), clk_(clock), mosi_(mosi), miso_(miso) {}

void Spi::Init(Port port) {
  Gpio::AlternateFunction af;
  // TODO(blakely): This doesn't map directly, since SPI2/3 are also on AF5 :(
  switch (port) {
    case Port::Spi3:
      af = Gpio::AlternateFunction::AF6;
      ll_port_ = static_cast<SPI_TypeDefI*>(SPI3);
      LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI3);
      break;
  }
  cs_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::PullUp, af);
  clk_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  mosi_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  // TODO(blakely): Should this be OD instead? Can't really set it as Hi-Z in AF
  // mode.
  miso_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);

  // Configuration according to 39.5.7 of reference manual
  // Default is full duplex.
  // CR1 config
  // Set baud rate to slowest by default.
  LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV256);
  // Need CPHA=1 for capture on second edge, and CPOL=0 for capture on fall
  // starting low.
  LL_SPI_SetClockPhase(ll_port_, LL_SPI_PHASE_2EDGE);
  LL_SPI_SetClockPolarity(ll_port_, LL_SPI_POLARITY_LOW);
  LL_SPI_DisableCRC(ll_port_);
  LL_SPI_SetMode(ll_port_, LL_SPI_MODE_MASTER);

  // CR2 config
  LL_SPI_SetDataWidth(ll_port_, LL_SPI_DATAWIDTH_16BIT);
  LL_SPI_SetStandard(ll_port_, LL_SPI_PROTOCOL_MOTOROLA);
  LL_SPI_SetNSSMode(ll_port_, LL_SPI_NSS_HARD_OUTPUT);
}

uint32_t Spi::SetBaud(uint32_t kbps) {
  const auto ahb_freq = Rcc::GetHClockFrequency() / 1000;
  uint32_t low = 2;
  uint32_t high = 4;
  while (ahb_freq / high > kbps && high < 256) {
    low = high;
    high = high << 1;
  }
  uint32_t prescalar = high;
  if (ahb_freq / low - kbps < kbps - ahb_freq / high) {
    prescalar = low;
  }

  switch (prescalar) {
    case 2:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV2);
      break;
    case 4:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV4);
      break;
    case 8:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV8);
      break;
    case 16:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV16);
      break;
    case 32:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV32);
      break;
    case 64:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV64);
      break;
    case 128:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV128);
      break;
    case 256:
      LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV256);
      break;
  }
  return ahb_freq / prescalar;
}

void Spi::BlockingTransfer(uint16_t write, uint16_t* read) {
  LL_SPI_TransmitData16(ll_port_, write);
  LL_SPI_Enable(ll_port_);
  while (LL_SPI_GetTxFIFOLevel(ll_port_) > 0) {
  }
  while (LL_SPI_IsActiveFlag_BSY(ll_port_) > 0) {
  }
  LL_SPI_Disable(ll_port_);
  do {
    *read = LL_SPI_ReceiveData16(ll_port_);
  } while (LL_SPI_GetRxFIFOLevel(ll_port_) > 0);
}

Drv::Drv(Gpio::Pin enable, Spi* spi) : enable_(std::move(enable)), spi_(spi) {}

void Drv::Init() {
  // Configure DRV_EN as general purpose GPIO.
  enable_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  // TODO(blakely): Register configuration.
  // TODO(blakely): Support 5MBit (32 prescalar). Requires stronger pullup on
  // DRV MISO line.
  spi_->SetBaud(1000);
}

void Drv::Enable() { enable_.High(); }

void Drv::Disable() { enable_.Low(); }

uint16_t Drv::BlockingReadRegister(Register reg) {
  uint16_t value = 0;
  uint16_t data = kReadMask | (static_cast<uint16_t>(reg) << 11);
  spi_->BlockingTransfer(data, &value);
  return value;
}

}  // namespace stm32g4
}  // namespace platform