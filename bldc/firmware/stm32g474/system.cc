#include "bldc/firmware/stm32g474/system.h"

#include "bldc/firmware/platform/stm32g4/peripherals/flash.h"
#include "bldc/firmware/platform/stm32g4/peripherals/fpu.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx.h"

using stm32g474::drivers::Flash;
using stm32g474::drivers::Fpu;
using stm32g474::drivers::Nvic;
using stm32g474::drivers::Rcc;

extern "C" {
// Dummy so we don't have to modify the startup script.
void SystemInit(void) {}
}

namespace stm32g474 {

using drivers::InterruptCallback;

void Startup() {
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
}

void OnFatal(InterruptCallback &&callback) {
  Nvic::SetInterruptHandler(drivers::Interrupt::HardFault, callback);
}

void Fatal() {
  // Intentionally read the beef!
  volatile auto deadbeef = *(volatile uint32_t *)0xdeadbeef;
  // Get rid of compiler warning.
  (void)deadbeef;
}
}  // namespace stm32g474