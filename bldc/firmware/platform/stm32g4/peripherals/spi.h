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

 private:
  struct SPI_TypeDefI;
  SPI_TypeDefI* ll_port_;
  Gpio::Pin cs_;
  Gpio::Pin clk_;
  Gpio::Pin mosi_;
  Gpio::Pin miso_;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_SPI_H_
