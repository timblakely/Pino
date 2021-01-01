#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_

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

  void AutoPoll();

 private:
  struct SPI_TypeDefI;
  SPI_TypeDefI* ll_port_;
  Gpio::Pin cs_;
  Gpio::Pin clk_;
  Gpio::Pin mosi_;
  Gpio::Pin miso_;
  NssMode nss_mode_;
};

class Drv {
 public:
  enum class Register : uint8_t {
    FaultStatus1 = 0,
    FaultStatus2 = 1,
    DriverControl = 2,
    GateDriveHigh = 3,
    GateDriveLow = 4,
    OverCurrentControl = 5,
    CurrentSenseAmpControl = 6,
  };

  explicit Drv(Gpio::Pin enable, Spi* spi);

  void Init();

  uint16_t BlockingReadRegister(Register reg);

  void Enable();
  void Disable();

 private:
  Gpio::Pin enable_;
  Spi* spi_;
  constexpr static uint16_t kReadMask = (1U << 15);
  constexpr static uint16_t kWriteMask = (0U << 15);
};

class Ma702 {
 public:
  enum class Register : uint8_t {
    ZLow = 0x0,
    ZHigh = 0x1,
    BiasCurrentTrimming = 0x2,
    EnableTrimming = 0x3,
    AbzConfig1 = 0x4,
    AbzConfig2 = 0x5,
    MagFieldThreshold = 0x6,
    RotationDirection = 0x9,
    MagFieldStatus = 0x1B,
  };

  explicit Ma702(Spi* spi);

  void Init();

  uint16_t BlockingReadRegister(Register reg);

 private:
  Spi* spi_;
  constexpr static uint16_t kReadAngle = (0b000 << 13);
  constexpr static uint16_t kReadRegister = (0b010 << 13);
  constexpr static uint16_t kWriteRegister = (0b100 << 13);
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
