#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/timer.h"
#include "bldc/firmware/stm32g474/led.h"
#include "bldc/firmware/stm32g474/system.h"

using stm32g474::Led;

using stm32g474::drivers::Gpio;

Gpio::Pin PB6{Gpio::Port::B, 6};
Gpio::Pin PB7{Gpio::Port::B, 7};
Gpio::Pin PB9{Gpio::Port::B, 9};

using stm32g474::drivers::SysTickTimer;

Led kRedLED(&PB6);
Led kGreenLED(&PB9);
Led kBlueLED(&PB7);

void ConfigureGpioPins() {
  PB6.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  PB7.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  PB9.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
}

int main() {
  stm32g474::Startup();
  stm32g474::OnFatal([] {
    kRedLED.On();
    while (true) {
      asm("nop");
    }
  });

  ConfigureGpioPins();

  uint32_t i = 0;
  while (true) {
    ++i;
    kGreenLED.On();
    kBlueLED.On();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.Off();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.On();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.Off();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.On();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.Off();
    kGreenLED.Off();
    stm32g474::Fatal();
  }
}