#include "bldc/firmware/stm32g474/drivers/flash.h"
#include "bldc/firmware/stm32g474/drivers/fpu.h"
#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/nvic.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"
#include "bldc/firmware/stm32g474/drivers/timer.h"
#include "bldc/firmware/stm32g474/led.h"

using stm32g474::Led;
using stm32g474::drivers::CortexInterrupt;
using stm32g474::drivers::Flash;
using stm32g474::drivers::Fpu;
using stm32g474::drivers::Gpio;
using stm32g474::drivers::GpioOutputMode;
using stm32g474::drivers::GpioPort;
using stm32g474::drivers::GpioPullup;
using stm32g474::drivers::Nvic;
using stm32g474::drivers::Rcc;
using stm32g474::drivers::SysTickTimer;

Led kRedLED(GpioPort::B, 6);
Led kGreenLED(GpioPort::B, 9);
Led kBlueLED(GpioPort::B, 7);

int main() {
  Fpu::EnableHardwareFPU();
  Nvic::Init([] {
    // Default handler.
    while (true) {
      asm("nop");  //
    }
  });

  Rcc::SetupClocks();

  Flash::EnableDataCache();
  Flash::EnableInstructionCache();
  Flash::EnablePrefetchBuffer();

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