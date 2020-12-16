#include "bldc/firmware/platform/stm32g4/nucleo/nucleo.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Nucleo kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Nucleo::Nucleo() {}

void Nucleo::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });

  user_led_ = new Led({Gpio::Port::A, 5});
  user_led_->On();

  pwm_output_ = new Gpio::Pin({Gpio::Port::C, 0});
  // pwm_output_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  // pwm_output_->High();
  pwm_output_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                         Gpio::AlternateFunction::AF2);

  Tim1 timer;
  timer.Configure();
  timer.EnableOutput(Tim1::Channel::Ch1);
  timer.Start();
}

// void Nucleo::SetupClocks() { Rcc::SetupClocks(); }

void Nucleo::OnFatal() {
  Tim2 timer;
  timer.Configure();
  timer.EnableOutput(Tim2::Channel::Ch1);
  timer.Start();
  user_led_->Pin().Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                             Gpio::AlternateFunction::AF1);
  // user_led_->Blink();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform