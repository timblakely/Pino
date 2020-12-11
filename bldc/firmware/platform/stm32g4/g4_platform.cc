#include "bldc/firmware/platform/stm32g4/g4_platform.h"

#include "bldc/firmware/platform/stm32g4/peripherals/flash.h"
#include "bldc/firmware/platform/stm32g4/peripherals/fpu.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "bldc/firmware/stm32g474/led.h"

namespace platform {
namespace stm32g4 {

G4Platform::G4Platform() {
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
}

void G4Platform::Startup() {
  SetupClocks();
  Init();
}

void G4Platform::Fatal() {
  // Intentionally read the beef!
  volatile auto deadbeef = *(volatile uint32_t*)0xdeadbeef;
  // Get rid of compiler warning.
  (void)deadbeef;
}

}  // namespace stm32g4
}  // namespace platform