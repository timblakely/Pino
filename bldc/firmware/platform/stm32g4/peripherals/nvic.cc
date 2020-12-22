#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"

#include <cstring>

#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx.h"

namespace platform {
namespace stm32g4 {

constexpr IRQn_Type ToCmsis(Interrupt interrupt) {
  return static_cast<IRQn_Type>(interrupt);
}

constexpr uint32_t ToIdx(Interrupt interrupt) {
  return static_cast<int32_t>(interrupt) + 16;
}

void Nvic::Init() {
  // Set 8 bits for primary group, 2 bits for sub-priority
  // RelocateInterruptsToCCMRAM();
  // kITableLocation =  ORIGIN(CCMRAM) + LENGTH(CCMRAM) - 0x200;
  DisableInterrupts();
  SCB->VTOR = reinterpret_cast<uint32_t>(0x10007E00UL);
  // SCB->VTOR = reinterpret_cast<uint32_t>(0x2001FE00UL);
  EnableInterrupts();
  __NVIC_SetPriorityGrouping(0b100);
}

void Nvic::Init(InterruptCallback default_handler) {
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

void Nvic::RelocateInterruptsToSRAM() { RelocateInterrupts(SRAM1_BASE); }

void Nvic::RelocateInterruptsToCCMRAM() { RelocateInterrupts(CCMSRAM_BASE); }

void Nvic::RelocateInterrupts(uint32_t address) {
  DisableInterrupts();
  ((SCB_Type*)SCB_BASE)->VTOR = address | 0x00UL;
  EnableInterrupts();
}

void Nvic::DisableInterrupts() { __disable_irq(); }

void Nvic::EnableInterrupts() { __enable_irq(); }

void Nvic::SetSysTickMicros(uint32_t microseconds) {
  // Set tick priority as a lower priority than most.
  __NVIC_SetPriority(SysTick_IRQn, 4);
  const uint32_t core_clock_freq = Rcc::GetSysClockFrequency();
  SysTick_Config(core_clock_freq * (microseconds / 1e6));
}

void Nvic::SetInterrupt(Interrupt interrupt, uint32_t priority,
                        uint32_t subpriority, InterruptCallback handler) {
  SetInterruptHandler(interrupt, handler);
  const uint32_t prioritygroup = __NVIC_GetPriorityGrouping();
  NVIC_SetPriority(ToCmsis(interrupt),
                   NVIC_EncodePriority(prioritygroup, priority, subpriority));
}

void Nvic::SetInterruptHandler(Interrupt interrupt, InterruptCallback handler) {
  const auto irqn = ToIdx(interrupt);
  handlers[irqn] = handler;
  auto global_isr = isrs[irqn];
  NVIC_SetVector(ToCmsis(interrupt), reinterpret_cast<uint32_t>(global_isr));
}

void Nvic::ResetAllWithDefault(InterruptCallback handler) {
  for (uint32_t irqn = 0; irqn < kTotalNumInterrupts; ++irqn) {
    SetInterruptHandler(static_cast<Interrupt>(static_cast<int32_t>(irqn) - 16),
                        handler);
  }
}

void Nvic::ResetAllExceptSysTickWithDefault(InterruptCallback handler) {
  for (uint32_t irqn = 0; irqn < kTotalNumInterrupts; ++irqn) {
    if (irqn == 15) {
      continue;
    }
    SetInterruptHandler(static_cast<Interrupt>(static_cast<int32_t>(irqn) - 16),
                        handler);
  }
}

void Nvic::EnableInterrupt(Interrupt interrupt) {
  NVIC_EnableIRQ(ToCmsis(interrupt));
}

void Nvic::DisableInterrupt(Interrupt interrupt) {
  NVIC_DisableIRQ(ToCmsis(interrupt));
}

}  // namespace stm32g4
}  // namespace platform