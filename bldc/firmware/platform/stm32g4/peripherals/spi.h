#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_

#include "bldc/firmware/platform/stm32g4/peripherals/dma.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

class Spi {
 public:
  enum class Port {
    Spi1,
    Spi3,
  };

  enum class ClockPhase {
    FirstEdge,
    SecondEdge,
  };

  enum class IdleState {
    Low,
    High,
  };

  enum class FrameSize {
    EightBit,
    SixteenBit,
  };

  enum class NssMode {
    Soft,
    Hard,
  };

  Spi(Gpio::Pin chip_select, Gpio::Pin clock, Gpio::Pin mosi, Gpio::Pin miso);

  void Init(Port port);

  // Attempts to set the closest prescalar value to the kiven kbps baud rate.
  // Returns the actual baud rate set.
  uint32_t SetBaud(uint32_t kbps);

  void Configure(ClockPhase data_capture, IdleState clock_idle_state,
                 FrameSize frame_size);
  void SetNssMode(NssMode mode);

  void BlockingTransfer(uint16_t write, uint16_t* read);

  void EnableStreaming(Dma::Stream& spi_enable, Dma::Stream& spi_disable);

  void StreamingTransfer(Dma::Stream& command_stream,
                         Dma::Stream& response_stream,
                         const uint16_t* command_source,
                         const uint16_t* response_dest,
                         const uint32_t transfer_size);

 private:
  void AutoPoll();
  struct SPI_TypeDefI;
  SPI_TypeDefI* ll_port_;
  Gpio::Pin cs_;
  Gpio::Pin clk_;
  Gpio::Pin mosi_;
  Gpio::Pin miso_;
  NssMode nss_mode_;

  constexpr static uint32_t kSpiDisable = 0x135;
  constexpr static uint32_t kSpiEnable =
      kSpiDisable | (0x1UL << 6) /* SPI_CR1_SPE */;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
