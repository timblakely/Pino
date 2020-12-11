#ifndef BLDC_FIRMWARE_STM32G474_LED_H_
#define BLDC_FIRMWARE_STM32G474_LED_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

namespace platform {

class Led {
 public:
  enum class Mode {
    Uninitalized,
    OnOff,
    Blink,
  };

  Led(stm32g4::Gpio::Pin& pin, Mode mode = Mode::Uninitalized);
  Led(stm32g4::Gpio::Pin&& pin, Mode mode = Mode::Uninitalized);

  stm32g4::Gpio::Pin& Pin() { return pin_; }

  void On();
  void Off();
  void Blink(stm32g4::Tim3* tim, uint32_t off_us, uint32_t on_us);

 private:
  void SetMode(Mode mode);
  void ConfigureBlink();
  void ConfigureOnOff();
  stm32g4::Gpio::Pin pin_;
  Mode mode_;
};

}  // namespace platform

#endif  // BLDC_FIRMWARE_STM32G474_LED_H_