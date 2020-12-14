#include "bldc/firmware/platform/stm32g4/devboard/devboard.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Devboard kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Devboard::Devboard() {}

void Devboard::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });

  red_ = new Led({Gpio::Port::B, 6});
  green_ = new Led({Gpio::Port::B, 9});
  blue_ = new Led({Gpio::Port::B, 7});

  green_->On();
}

void Devboard::SetupClocks() { Rcc::SetupClocks(); }

void Devboard::OnFatal() {
  green_->Off();
  Tim3 tim3;
  tim3.Configure();
  tim3.EnableOutputChannel();
  tim3.Start();
  blue_->Blink();
  // blue_->On();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform