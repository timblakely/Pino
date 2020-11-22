#include "bldc/firmware/stm32g474/interrupt_table.h"

#include "bldc/firmware/stm32g474/drivers/nvic.h"

namespace stm32g474 {

template <>
void Stm32g474reInterruptTable<>::set_interrupt(
    drivers::InterruptType interrupt, int P, int SP, Callback handler) {
  auto irq = static_cast<int32_t>(interrupt);
  handlers[irq + 16] = handler;
  auto isr = isrs[irq + 16];
  NVIC_SetVector(irq, reinterpret_cast<uint32_t>(isr));
  HAL_NVIC_SetPriority(irq, P, SP);
  HAL_NVIC_EnableIRQ(irq);
}

template <>
void Stm32g474reInterruptTable<>::relocate_vector_table_to_sram() {
  // Relocate VTOR table to SRAM
  __disable_irq();
  std::memcpy(reinterpret_cast<void*>(SRAM1_BASE),
              reinterpret_cast<void*>(FLASH_BASE), 0x1D8 /* 118 * 4 */);
  SCB->VTOR = SRAM1_BASE | 0x00UL;  // Must be multiple of 0x200
  __enable_irq();
}

template <>
void Stm32g474reInterruptTable<>::reset_with_default(Callback handler) {
  for (int i = -15; i < 102; ++i) {
    set_interrupt(static_cast<IRQn_Type>(i), 0, 0, handler);
  }
}

}  // namespace stm32g474