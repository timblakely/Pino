#include "bldc/firmware/stm32g474/led.h"

#include <utility>

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"

namespace stm32g474 {

using drivers::Gpio;
using drivers::Tim3;

Led::Led(Gpio::Pin& pin, Mode mode) : pin_(pin), mode_(mode) {}
Led::Led(Gpio::Pin&& pin, Mode mode) : pin_(std::move(pin)), mode_(mode) {}

void Led::On() {
  SetMode(Mode::OnOff);
  pin_.High();
}

void Led::Off() {
  SetMode(Mode::OnOff);
  pin_.Low();
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
  // TODO(blakely): Pull AF from GPIO somewhere... maybe pin?
  pin_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                 Gpio::AlternateFunction::AF10);
}

void Led::ConfigureOnOff() {
  pin_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
}

void Led::Blink(Tim3* tim, uint32_t off_us, uint32_t on_us) {
  SetMode(Mode::Blink);
  tim->Enable();
  tim->Configure();
  tim->EnableOutputChannel(Tim3::Channel::CH4);
  tim->Start();
}

}  // namespace stm32g474