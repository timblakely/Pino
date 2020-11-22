#include "bldc/firmware/stm32g474/drivers/nvic.h"

#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace cortex {
// Needed for vendor-specific definitions.
#include "third_party/stm32cubeg4/stm32g4xx.h"
}  // namespace cortex

namespace stm32g474 {
namespace drivers {

void Nvic::Init() {
  // Set 8 bits for primary group, 2 bits for sub-priority
  cortex::__NVIC_SetPriorityGrouping(0b100);
  // Relocate vector table to sram.
  DisableInterrupts();
  EnableInterrupts();
}

int i = 0;

extern "C" {
void SysTick_Handler() {
  asm("nop");  //
  ++i;
}
}

void Nvic::DisableInterrupts() { cortex::__disable_irq(); }

void Nvic::EnableInterrupts() { cortex::__enable_irq(); }

void Nvic::SetSysTickMicros(uint32_t microseconds) {
  // Set tick priority as a lower priority than most.
  cortex::__NVIC_SetPriority(cortex::SysTick_IRQn, 4);
  const uint32_t core_clock_freq = Rcc::GetCoreClockFrequency();
  cortex::SysTick_Config(core_clock_freq * (microseconds / 1e6));
}

}  // namespace drivers
}  // namespace stm32g474