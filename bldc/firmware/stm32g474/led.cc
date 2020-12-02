#include "bldc/firmware/stm32g474/led.h"

#include <utility>

#include "bldc/firmware/stm32g474/drivers/gpio.h"

namespace stm32g474 {

using drivers::Gpio;

Led::Led(Gpio::Pin& pin, Mode mode) : pin_(pin), mode_(mode) {}
Led::Led(Gpio::Pin&& pin, Mode mode) : pin_(std::move(pin)), mode_(mode) {
  int i = 0;  //
}

void Led::SetMode(Mode mode) {
  if (mode_ == mode) {
    return;
  }
  switch (mode) {
    case Mode::Blink:
      ConfigureBlink();
      break;
    case Mode::OnOff:
      ConfigureOnOff();
      break;
    case Mode::Uninitalized:
      break;
  }
  mode_ = mode;
}

void Led::ConfigureBlink() {
  pin_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                 Gpio::AlternateFunction::AF10);
}

void Led::ConfigureOnOff() {
  pin_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
}

void Led::On() {
  SetMode(Mode::OnOff);
  pin_.High();
}

void Led::Off() {
  SetMode(Mode::OnOff);
  pin_.Low();
}

}  // namespace stm32g474