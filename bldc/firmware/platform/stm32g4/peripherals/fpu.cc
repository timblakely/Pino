#include "bldc/firmware/stm32g474/drivers/fpu.h"

#include "third_party/stm32cubeg4/stm32g474xx.h"

namespace stm32g474 {
namespace drivers {

void Fpu::EnableHardwareFPU() {
  SCB->CPACR |= ((3UL << (10 * 2)) |
                 (3UL << (11 * 2))); /* set CP10 and CP 1 Full Access */
}

}  // namespace drivers
}  // namespace stm32g474