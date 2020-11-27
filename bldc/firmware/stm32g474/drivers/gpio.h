#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

#include "bldc/firmware/stm32g474/drivers/gpio_defines.h"

namespace stm32g474 {
namespace drivers {

class Gpio {
 public:
  static void ConfigurePin(GpioPort port, uint8_t pin, GpioMode mode,
                           GpioPullup pullup);
  static void ConfigurePinAlternateFunction(
      GpioPort port, uint8_t pin, GpioMode mode, GpioPullup pullup,
      GpioAlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
