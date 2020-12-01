#include "bldc/firmware/stm32g474/led.h"

namespace stm32g474 {

using drivers::Gpio;

Led::Led(Gpio::Pin* pin) : pin_(pin) {}

void Led::On() { pin_->High(); }

void Led::Off() { pin_->Low(); }

}  // namespace stm32g474