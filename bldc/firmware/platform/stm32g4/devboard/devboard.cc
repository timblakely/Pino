#include "bldc/firmware/platform/stm32g4/devboard/devboard.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Devboard kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Devboard::Devboard()
    : spi3_({Gpio::Port::A, 15}, {Gpio::Port::C, 10}, {Gpio::Port::B, 5},
            {Gpio::Port::C, 11}),
      drv_({Gpio::Port::C, 6}, &spi3_) {}

void Devboard::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });

  red_ = new Led({Gpio::Port::B, 6});
  // green_ = new Led({Gpio::Port::B, 9}); // Correct for v0 board
  // blue_ = new Led({Gpio::Port::B, 7});
  green_ = new Led({Gpio::Port::B, 7});
  blue_ = new Led({Gpio::Port::B, 9});

  spi3_.Init(Spi::Port::Spi3);
  drv_.Init();

  drv_.Enable();
  SysTickTimer::BlockingWait(1000);
  uint16_t value = 0;
  value = drv_.BlockingReadRegister(Drv::Register::GateDriveHigh);

  green_->On();
}

void Devboard::OnFatal() {
  green_->Off();
  Tim3 timer;
  timer.Configure();
  timer.EnableOutput(Tim3::Channel::Ch4);
  timer.Start();
  blue_->Blink();
  // blue_->On();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform