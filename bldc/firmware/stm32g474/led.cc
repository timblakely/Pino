#include "bldc/firmware/stm32g474/led.h"

namespace stm32g474 {

using drivers::Gpio;

Led::Led(Gpio::Port port, uint32_t pin) : port_(port), pin_(pin) {
  ConfigurePin();
}

void Led::On() { Gpio::SetOutputPin(port_, pin_); }

void Led::Off() { Gpio::ClearOutputPin(port_, pin_); }

void Led::ConfigurePin() {
  Gpio::ConfigureOutputPin(port_, pin_, Gpio::Pullup::None,
                           Gpio::OutputMode::PushPull);
}

}  // namespace stm32g474