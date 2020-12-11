#include "bldc/firmware/platform/stm32g4/devboard/devboard.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Devboard kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Devboard::Devboard() {
  kRed = new Led({Gpio::Port::B, 6});
  kGreen = new Led({Gpio::Port::B, 9});
  kBlue = new Led({Gpio::Port::B, 7});

  kBlue->On();
}

void Devboard::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { kRed->On(); });
}

void Devboard::SetupClocks() {}

}  // namespace stm32g4
}  // namespace platform