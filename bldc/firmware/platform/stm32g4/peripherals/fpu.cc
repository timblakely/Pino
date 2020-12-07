#include "bldc/firmware/platform/stm32g4/peripherals/fpu.h"

#include "third_party/stm32cubeg4/stm32g474xx.h"

namespace platform {
namespace stm32g4 {

void Fpu::EnableHardwareFPU() {
  SCB->CPACR |= ((3UL << (10 * 2)) |
                 (3UL << (11 * 2))); /* set CP10 and CP 1 Full Access */
}

}  // namespace stm32g4
}  // namespace platform