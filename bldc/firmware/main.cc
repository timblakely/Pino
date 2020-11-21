#include <stdint.h>

// #include "third_party/stm32cubeg4/stm32g474xx.h"

#include "bldc/firmware/stm32g474/drivers/fpu.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"

using stm32g474::drivers::Fpu;
using stm32g474::drivers::Rcc;

int main() {
  Fpu::EnableHardwareFPU();
  Rcc::SetupClocks();
  while (true) {
    asm("nop");
  }
}