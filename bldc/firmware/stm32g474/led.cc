#include "bldc/firmware/stm32g474/led.h"

namespace stm32g474 {

using drivers::Gpio;
using drivers::GpioOutputMode;
using drivers::GpioPullup;

Led::Led(drivers::GpioPort port, uint32_t pin) : port_(port), pin_(pin) {
  ConfigurePin();
}

void Led::On() { Gpio::SetOutputPin(port_, pin_); }

void Led::Off() { Gpio::ClearOutputPin(port_, pin_); }

void Led::ConfigurePin() {
  Gpio::ConfigureOutputPin(port_, pin_, GpioPullup::None,
                           GpioOutputMode::PushPull);
}

}  // namespace stm32g474