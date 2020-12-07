#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/timer.h"
#include "bldc/firmware/stm32g474/led.h"
#include "bldc/firmware/stm32g474/system.h"

using stm32g474::Led;
using stm32g474::drivers::Tim3;

using stm32g474::drivers::Gpio;

using stm32g474::drivers::SysTickTimer;

Led kRed({Gpio::Port::B, 6});
Led kGreen({Gpio::Port::B, 9});
Led kBlue({Gpio::Port::B, 7});

Tim3 tim3;

int main() {
  stm32g474::Startup();
  stm32g474::OnFatal([] {
    kRed.On();
    while (true) {
      asm("nop");
    }
  });

  kBlue.Blink(&tim3, 1000000, 1000000);

  // tim3.Enable();
  // tim3.Configure();
  // tim3.Start();

  uint32_t i = 0;
  while (true) {
    ++i;
    asm("nop");
    // kGreen.On();
    // SysTickTimer::BlockingWait(1000000 * 1);
    // kGreen.Off();
    // SysTickTimer::BlockingWait(1000000 * 1);
    // kGreen.On();
    // SysTickTimer::BlockingWait(1000000 * 1);
    // kGreen.Off();
    // SysTickTimer::BlockingWait(1000000 * 1);
    // kGreen.On();
    // SysTickTimer::BlockingWait(1000000 * 1);
    // kGreen.Off();
    // stm32g474::Fatal();
  }
}