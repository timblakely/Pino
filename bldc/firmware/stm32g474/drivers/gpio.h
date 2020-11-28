#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_

#include "bldc/firmware/stm32g474/drivers/gpio_defines.h"

namespace stm32g474 {
namespace drivers {

class Gpio {
 public:
  static void ConfigureInputPin(GpioPort port, uint32_t pin, GpioPullup pullup);
  static void ConfigureOutputPin(GpioPort port, uint32_t pin, GpioPullup pullup,
                                 GpioOutputMode mode);
  static void SetOutputPin(GpioPort port, uint32_t pin);
  static void ConfigurePeripheralPin(GpioPort port, uint8_t pin,
                                     GpioPullup pullup,
                                     GpioAlternateFunction alternate_function);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_H_
