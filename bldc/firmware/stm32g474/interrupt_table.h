#ifndef BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_
#define BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_

#include "bldc/firmware/interrupt_table.hpp"

namespace stm32g474 {

const uint32_t kNumInterrupts = 118;

template <int InplaceFunctionStorageSize = 10>
class Stm32g474reInterruptTable
    : public common::InterruptTable<kNumInterrupts,
                                    InplaceFunctionStorageSize> {
 public:
  using Callback = common::InterruptTable<kNumInterrupts,
                                          InplaceFunctionStorageSize>::Callback;

  static void relocate_vector_table_to_sram();
  static void reset_with_default(Callback handler);
  static void set_interrupt(IRQn_Type interrupt, int P, int SP,
                            Callback handler);
};

using Interrupts = Stm32g474reInterruptTable<>;

}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_
