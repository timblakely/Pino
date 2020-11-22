#include "bldc/firmware/stm32g474/drivers/flash.h"
#include "bldc/firmware/stm32g474/drivers/fpu.h"
#include "bldc/firmware/stm32g474/drivers/nvic.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"

using stm32g474::drivers::Flash;
using stm32g474::drivers::Fpu;
using stm32g474::drivers::Nvic;
using stm32g474::drivers::Rcc;

int main() {
  Fpu::EnableHardwareFPU();
  Nvic::Init();
  Nvic::SetSysTickMicros(1000);

  Rcc::SetupClocks();

  Flash::EnableDataCache();
  Flash::EnableInstructionCache();
  Flash::EnablePrefetchBuffer();

  uint32_t i = 0;
  while (true) {
    ++i;
  }
}