#include "bldc/firmware/platform/stm32g4/peripherals/spi.h"

#include "bldc/firmware/platform/stm32g4/peripherals/dma.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_dma.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_spi.h"

namespace platform {
namespace stm32g4 {

// Getting around the anonymous struct issue.
struct Spi::SPI_TypeDefI : public SPI_TypeDef {};

Spi::Spi(Gpio::Pin chip_select, Gpio::Pin clock, Gpio::Pin mosi, Gpio::Pin miso)
    : cs_(chip_select),
      clk_(clock),
      mosi_(mosi),
      miso_(miso),
      nss_mode_(NssMode::Soft) {}

void Spi::Init(Port port) {
  Gpio::AlternateFunction af;
  switch (port) {
    case Port::Spi1:
      af = Gpio::AlternateFunction::AF5;
      ll_port_ = static_cast<SPI_TypeDefI*>(SPI1);
      LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);
      break;
    case Port::Spi3:
      // TODO(blakely): This doesn't map directly, since SPI2/3 are also on AF5
      // :(
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
  // LL_SPI_SetClockPhase(ll_port_, LL_SPI_PHASE_2EDGE);
  // LL_SPI_SetClockPolarity(ll_port_, LL_SPI_POLARITY_LOW);
  LL_SPI_DisableCRC(ll_port_);
  LL_SPI_SetMode(ll_port_, LL_SPI_MODE_MASTER);

  // CR2 config
  // LL_SPI_SetDataWidth(ll_port_, LL_SPI_DATAWIDTH_16BIT);
  LL_SPI_SetStandard(ll_port_, LL_SPI_PROTOCOL_MOTOROLA);
  // LL_SPI_SetNSSMode(ll_port_, LL_SPI_NSS_HARD_OUTPUT);
}

void Spi::Configure(ClockPhase data_capture, IdleState clock_idle_state,
                    FrameSize frame_size) {
  switch (data_capture) {
    case ClockPhase::FirstEdge:
      LL_SPI_SetClockPhase(ll_port_, LL_SPI_PHASE_1EDGE);
      break;
    case ClockPhase::SecondEdge:
      LL_SPI_SetClockPhase(ll_port_, LL_SPI_PHASE_2EDGE);
      break;
  }
  switch (clock_idle_state) {
    case IdleState::Low:
      LL_SPI_SetClockPolarity(ll_port_, LL_SPI_POLARITY_LOW);
      break;
    case IdleState::High:
      LL_SPI_SetClockPolarity(ll_port_, LL_SPI_POLARITY_HIGH);
      break;
  }
  switch (frame_size) {
    case FrameSize::EightBit:
      LL_SPI_SetDataWidth(ll_port_, LL_SPI_DATAWIDTH_8BIT);
      break;
    case FrameSize::SixteenBit:
      LL_SPI_SetDataWidth(ll_port_, LL_SPI_DATAWIDTH_16BIT);
      break;
  }
}

void Spi::SetNssMode(NssMode mode) {
  nss_mode_ = mode;
  switch (mode) {
    case NssMode::Hard:
      LL_SPI_SetNSSMode(ll_port_, LL_SPI_NSS_HARD_OUTPUT);
      break;
    case NssMode::Soft:
      cs_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
      cs_.High();
      LL_SPI_SetNSSMode(ll_port_, LL_SPI_NSS_SOFT);
      break;
  }
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
  if (nss_mode_ == NssMode::Soft) {
    cs_.Low();
  }
  LL_SPI_Enable(ll_port_);
  while (LL_SPI_GetTxFIFOLevel(ll_port_) > 0) {
  }
  while (LL_SPI_IsActiveFlag_BSY(ll_port_) > 0) {
  }
  LL_SPI_Disable(ll_port_);
  do {
    *read = LL_SPI_ReceiveData16(ll_port_);
  } while (LL_SPI_GetRxFIFOLevel(ll_port_) > 0);
  cs_.High();
}

void SetupDMA(uint32_t dma_chan, uint32_t dmamux_signal) {
  // TODO(blakely): Move into DMA configuration object.
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMAMUX1);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_DMA1);

  LL_DMA_SetPeriphRequest(DMA1, dma_chan, dmamux_signal);

  LL_DMA_SetDataTransferDirection(DMA1, dma_chan,
                                  LL_DMA_DIRECTION_MEMORY_TO_PERIPH);

  LL_DMA_SetChannelPriorityLevel(DMA1, dma_chan, LL_DMA_PRIORITY_HIGH);

  LL_DMA_SetMode(DMA1, dma_chan, LL_DMA_MODE_CIRCULAR);

  LL_DMA_SetPeriphIncMode(DMA1, dma_chan, LL_DMA_PERIPH_NOINCREMENT);

  LL_DMA_SetPeriphIncMode(DMA1, dma_chan, LL_DMA_MEMORY_NOINCREMENT);

  LL_DMA_SetPeriphSize(DMA1, dma_chan, LL_DMA_PDATAALIGN_WORD);

  LL_DMA_SetMemorySize(DMA1, dma_chan, LL_DMA_MDATAALIGN_WORD);
}

// Setup for SPI3 for DRV chip.

extern "C" {
uint32_t kSpiReceive = 0;
}
const uint32_t kSpiDisable = 0x135;
const uint32_t kSpiEnable = kSpiDisable | SPI_CR1_SPE;

void Spi::EnableStreaming(Dma::Stream& spi_enable, Dma::Stream& spi_disable) {
  spi_enable.Configure(Dma::Mode::Circular, Dma::Increment::No,
                       Dma::Increment::No, Dma::TransferSize::Word);
  spi_enable.Start(&kSpiEnable, (const uint32_t*)(&(ll_port_->CR1)), 1);

  spi_disable.Configure(Dma::Mode::Circular, Dma::Increment::No,
                        Dma::Increment::No, Dma::TransferSize::Word);
  spi_disable.Start(&kSpiDisable, (const uint32_t*)(&(ll_port_->CR1)), 1);
}

void Spi::StreamingTransfer(Dma::Stream& command_stream,
                            Dma::Stream& response_stream,
                            const uint16_t* command_source,
                            const uint16_t* response_dest,
                            uint32_t transfer_size) {
  // TODO(blakely): Careful, we might be clobbering stuff with the cast to
  // uint32 here...
  command_stream.Start(reinterpret_cast<const uint32_t*>(command_source),
                       (const uint32_t*)(&(ll_port_->DR)), transfer_size);
  response_stream.Start((const uint32_t*)(&(ll_port_->DR)),
                        reinterpret_cast<const uint32_t*>(response_dest),
                        transfer_size);
}

}  // namespace stm32g4
}  // namespace platform