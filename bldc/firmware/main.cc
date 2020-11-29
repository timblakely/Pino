#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/timer.h"
#include "bldc/firmware/stm32g474/init.h"
#include "bldc/firmware/stm32g474/led.h"

using stm32g474::Led;

using stm32g474::drivers::Gpio;
using stm32g474::drivers::GpioOutputMode;
using stm32g474::drivers::GpioPort;
using stm32g474::drivers::GpioPullup;

using stm32g474::drivers::SysTickTimer;

Led kRedLED(GpioPort::B, 6);
Led kGreenLED(GpioPort::B, 9);
Led kBlueLED(GpioPort::B, 7);

int main() {
  stm32g474::Startup();
  kRedLED.On();

  uint32_t i = 0;
  while (true) {
    ++i;
    kBlueLED.On();
    SysTickTimer::BlockingWait(1000000 * 1);
    kBlueLED.Off();
    SysTickTimer::BlockingWait(1000000 * 1);
  }
}