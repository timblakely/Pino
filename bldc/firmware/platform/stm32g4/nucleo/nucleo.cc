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
}

void Nucleo::SetupClocks() { Rcc::SetupClocks(); }

void Nucleo::OnFatal() {
  Tim2 tim2;
  tim2.Enable();
  tim2.Configure();
  tim2.EnableOutputChannel();
  tim2.Start();
  user_led_->Blink();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform