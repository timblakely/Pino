#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace platform {
namespace stm32g4 {

class Spi {
 public:
  enum class Port {
    Spi3,
  };

  Spi(Gpio::Pin chip_select, Gpio::Pin clock, Gpio::Pin mosi, Gpio::Pin miso);

  void Init(Port port);

  void BlockingTransfer(uint16_t write, uint16_t* read);

 private:
  struct SPI_TypeDefI;
  SPI_TypeDefI* ll_port_;
  Gpio::Pin cs_;
  Gpio::Pin clk_;
  Gpio::Pin mosi_;
  Gpio::Pin miso_;
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

// class Ma702 {
//  public:
//   enum class Register : uint8_t {
//     FaultStatus1 = 0,
//     FaultStatus2 = 1,
//     DriverControl = 2,
//     GateDriveHigh = 3,
//     GateDriveLow = 4,
//     OverCurrentControl = 5,
//     CurrentSenseAmpControl = 6,
//   };

//   explicit Ma702(Spi* spi);
//   uint16_t BlockingReadRegister(Register reg);

//  private:
//   Spi* spi_;
//   constexpr static uint16_t kReadMask = (1U << 15);
//   constexpr static uint16_t kWriteMask = (0U << 15);
// };

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
