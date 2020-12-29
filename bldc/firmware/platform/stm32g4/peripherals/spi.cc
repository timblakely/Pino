#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

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
      break;
  }
  cs_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::PullUp, af);
  clk_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  mosi_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);
  // TODO(blakely): Should this be OD instead? Can't really set it as Hi-Z in AF
  // mode.
  miso_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None, af);

  // Configure DRV_EN as general purpose GPIO, then set it to high.

  auto drv_en = Gpio::Pin({Gpio::Port::C, 6});
  drv_en.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  drv_en.High();

  // Start the clock.
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI3);

  // Configuration according to 39.5.7 of reference manual
  // Default is full duplex.
  // CR1 config
  // TODO(blakely): Support 5MBit (32 prescalar). Requires stronger pullup on
  // DRV MISO line.
  LL_SPI_SetBaudRatePrescaler(ll_port_, LL_SPI_BAUDRATEPRESCALER_DIV128);
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

Drv::Drv(Spi* spi) : spi_(spi) {}

uint16_t Drv::BlockingReadRegister(Register reg) {
  uint16_t value = 0;
  uint16_t data = kReadMask | (static_cast<uint16_t>(reg) << 11);
  spi_->BlockingTransfer(data, &value);
  return value;
}

}  // namespace stm32g4
}  // namespace platform