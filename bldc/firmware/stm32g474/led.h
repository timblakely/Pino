#ifndef BLDC_FIRMWARE_STM32G474_LED_H_
#define BLDC_FIRMWARE_STM32G474_LED_H_

#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/timer.h"

namespace stm32g474 {

class Led {
 public:
  enum class Mode {
    Uninitalized,
    OnOff,
    Blink,
  };

  Led(drivers::Gpio::Pin& pin, Mode mode = Mode::Uninitalized);
  Led(drivers::Gpio::Pin&& pin, Mode mode = Mode::Uninitalized);

  drivers::Gpio::Pin& Pin() { return pin_; }

  void On();
  void Off();
  void Blink(drivers::Tim3* tim, uint32_t off_us, uint32_t on_us);

 private:
  void SetMode(Mode mode);
  void ConfigureBlink();
  void ConfigureOnOff();
  drivers::Gpio::Pin pin_;
  Mode mode_;
};

}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_LED_H_
