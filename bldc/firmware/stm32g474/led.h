#ifndef BLDC_FIRMWARE_STM32G474_LED_H_
#define BLDC_FIRMWARE_STM32G474_LED_H_

#include "bldc/firmware/stm32g474/drivers/gpio.h"

namespace stm32g474 {

class Led {
 public:
  // enum class Mode {
  //   OnOff,
  //   Blinking,
  // };

  Led(drivers::Gpio::Pin* pin);

  void On();
  void Off();

 private:
  drivers::Gpio::Pin* pin_;
  // Mode mode_;
};
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_LED_H_
