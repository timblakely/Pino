#include "bldc/firmware/platform/stm32g4/peripherals/flash.h"
#include "bldc/firmware/platform/stm32g4/peripherals/fpu.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "bldc/firmware/platform/system.h"
#include "bldc/firmware/stm32g474/led.h"

using stm32g474::Led;
using stm32g474::stm32g4Flash;
using stm32g474::stm32g4Fpu;
using stm32g474::stm32g4Gpio;
using stm32g474::stm32g4Nvic;
using stm32g474::stm32g4Rcc;

using stm32g474::stm32g4Interrupt;

namespace platform {

Led kUserLed({Gpio::Port::A, 5});

void Platform::Startup() {
  Fpu::EnableHardwareFPU();
  Nvic::Init(/* Default interrupt handler */ [] {
    while (true) {
      asm("nop");  //
    }
  });
  // Note: Might need to come after clock setup.
  Flash::EnableDataCache();
  Flash::EnableInstructionCache();
  Flash::EnablePrefetchBuffer();

  Rcc::SetupClocks();

  Nvic::SetInterruptHandler(Interrupt::HardFault, [] {
    kUserLed.On();
    while (true) {
      asm("nop");
    }
  });
}

void Platform::Fatal() {
  // Intentionally read the beef!
  volatile auto deadbeef = *(volatile uint32_t *)0xdeadbeef;
  // Get rid of compiler warning.
  (void)deadbeef;
}

}  // namespace platform
