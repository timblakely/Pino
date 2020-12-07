#include "bldc/firmware/platform/system.h"

#include "bldc/firmware/stm32g474/drivers/flash.h"
#include "bldc/firmware/stm32g474/drivers/fpu.h"
#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/nvic.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"
#include "bldc/firmware/stm32g474/led.h"

using stm32g474::Led;
using stm32g474::drivers::Flash;
using stm32g474::drivers::Fpu;
using stm32g474::drivers::Gpio;
using stm32g474::drivers::Nvic;
using stm32g474::drivers::Rcc;

using stm32g474::drivers::Interrupt;

namespace platform {

// Led kRed({Gpio::Port::B, 6});
// Led kGreen({Gpio::Port::B, 9});

void G4Platform::Setup() {
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

  // TODO(blakely): Move this to platform-specific code.
  Rcc::SetupClocks();
}

void G4Platform::Fatal() {
  // Intentionally read the beef!
  volatile auto deadbeef = *(volatile uint32_t*)0xdeadbeef;
  // Get rid of compiler warning.
  (void)deadbeef;
}

}  // namespace platform
