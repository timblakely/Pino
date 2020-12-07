#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

// using stm32g474::Led;
// using stm32g474::drivers::Tim3;

// using stm32g474::drivers::Gpio;

using platform::BldcPlatform;

using stm32g474::drivers::SysTickTimer;

// Led kRed({Gpio::Port::B, 6});
// Led kGreen({Gpio::Port::B, 9});
// Led kBlue({Gpio::Port::B, 7});

// Tim3 tim3;

int main() {
  auto* platform = BldcPlatform::Instance();
  platform->Startup();
  // stm32g474::Startup();
  // stm32g474::OnFatal([] {
  //   kRed.On();
  //   while (true) {
  //     asm("nop");
  //   }
  // });

  // kBlue.Blink(&tim3, 1000000, 1000000);

  // // tim3.Enable();
  // // tim3.Configure();
  // // tim3.Start();

  uint32_t i = 0;
  while (true) {
    ++i;
    asm("nop");
    //   // kGreen.On();
    SysTickTimer::BlockingWait(1000000 * 1);
    //   // kGreen.Off();
    //   // SysTickTimer::BlockingWait(1000000 * 1);
    //   // kGreen.On();
    //   // SysTickTimer::BlockingWait(1000000 * 1);
    //   // kGreen.Off();
    //   // SysTickTimer::BlockingWait(1000000 * 1);
    //   // kGreen.On();
    //   // SysTickTimer::BlockingWait(1000000 * 1);
    //   // kGreen.Off();
    platform->Fatal();
  }
}