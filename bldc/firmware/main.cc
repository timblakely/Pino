#include <stdint.h>

// #include "third_party/stm32cubeg4/stm32g474xx.h"

#include "bldc/firmware/stm32g474/drivers/fpu.h"

using stm32g474::drivers::Fpu;

int main() {
  Fpu::EnableHardwareFPU();
  while (true) {
    asm("nop");
  }
}