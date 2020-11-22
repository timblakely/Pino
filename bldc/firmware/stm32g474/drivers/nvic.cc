#include "bldc/firmware/stm32g474/drivers/nvic.h"

#include <cstring>

#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace cortex {
// Needed for vendor-specific definitions, otherwise we'd include cortex_m4.h
// directly. :/
#include "third_party/stm32cubeg4/stm32g4xx.h"
}  // namespace cortex

namespace stm32g474 {
namespace drivers {

constexpr cortex::IRQn_Type ToCmsis(uint32_t interrupt) {
  // The IRQn_Type is indexed at -16.
  return static_cast<cortex::IRQn_Type>(interrupt - 16);
}

void Nvic::Init() {
  // Set 8 bits for primary group, 2 bits for sub-priority
  cortex::__NVIC_SetPriorityGrouping(0b100);
  RelocateInterruptsToSram();
}

void Nvic::Init(Callback default_handler) {
  Init();
  ResetAllWithDefault(default_handler);
}

int i = 0;

extern "C" {
void SysTick_Handler() {
  asm("nop");  //
  ++i;
}
}

void Nvic::RelocateInterruptsToSram() {
  DisableInterrupts();
  memcpy(reinterpret_cast<void*>(SRAM1_BASE),
         reinterpret_cast<void*>(FLASH_BASE), 0x1D8 /* 118 * 4 */);
  // We need this explicit declaration here instead of just referencing SCB
  // directly because of ST's terribly polluted namespace :(
  ((cortex::SCB_Type*)SCB_BASE)->VTOR =
      SRAM1_BASE | 0x00UL;  // Must be multiple of 0x200
  EnableInterrupts();
}

void Nvic::DisableInterrupts() { cortex::__disable_irq(); }

void Nvic::EnableInterrupts() { cortex::__enable_irq(); }

void Nvic::SetSysTickMicros(uint32_t microseconds) {
  // Set tick priority as a lower priority than most.
  cortex::__NVIC_SetPriority(cortex::SysTick_IRQn, 4);
  const uint32_t core_clock_freq = Rcc::GetCoreClockFrequency();
  cortex::SysTick_Config(core_clock_freq * (microseconds / 1e6));
}

template <>
void Nvic::SetInterrupt(CortexInterrupt interrupt, uint32_t priority,
                        uint32_t subpriority, Callback handler) {
  SetInterrupt(static_cast<uint32_t>(interrupt), priority, subpriority,
               handler);
}

template <>
void Nvic::SetInterrupt(MaskableInterrupt interrupt, uint32_t priority,
                        uint32_t subpriority, Callback handler) {
  SetInterrupt(static_cast<uint32_t>(interrupt) + 16, priority, subpriority,
               handler);
}

template <>
void Nvic::SetInterruptHandler(CortexInterrupt interrupt, Callback handler) {
  SetInterruptHandler(static_cast<uint32_t>(interrupt), handler);
}

template <>
void Nvic::SetInterruptHandler(MaskableInterrupt interrupt, Callback handler) {
  SetInterruptHandler(static_cast<uint32_t>(interrupt) + 16, handler);
}

void Nvic::SetInterrupt(uint32_t interrupt, uint32_t priority,
                        uint32_t subpriority, Callback handler) {
  SetInterruptHandler(static_cast<uint32_t>(interrupt), handler);
  const uint32_t prioritygroup = cortex::__NVIC_GetPriorityGrouping();
  cortex::NVIC_SetPriority(
      ToCmsis(interrupt),
      cortex::NVIC_EncodePriority(prioritygroup, priority, subpriority));
}

void Nvic::SetInterruptHandler(uint32_t interrupt, Callback handler) {
  handlers[interrupt] = handler;
  auto global_isr = isrs[interrupt];
  cortex::NVIC_SetVector(ToCmsis(interrupt),
                         reinterpret_cast<uint32_t>(global_isr));
}

void Nvic::ResetAllWithDefault(Callback handler) {
  for (uint32_t irqn = 0; irqn < kTotalNumInterrupts; ++irqn) {
    SetInterruptHandler(irqn, handler);
  }
}

}  // namespace drivers
}  // namespace stm32g474