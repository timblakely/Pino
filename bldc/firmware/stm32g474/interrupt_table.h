#ifndef BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_
#define BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_

#include "bldc/firmware/interrupt_table.hpp"
#include "bldc/firmware/stm32g474/drivers/nvic.h"

namespace stm32g474 {

template <int InplaceFunctionStorageSize = 10>
class Stm32g474reInterruptTable
    : public common::InterruptTable<drivers::Nvic::kNumInterrupts,
                                    InplaceFunctionStorageSize> {
 public:
  using Callback = common::InterruptTable<drivers::Nvic::kNumInterrupts,
                                          InplaceFunctionStorageSize>::Callback;

  static void reset_with_default(Callback handler);
  static void set_interrupt(drivers::InterruptType interrupt, int P, int SP,
                            Callback handler);
};

using Interrupts = Stm32g474reInterruptTable<>;

}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_INTERRUPT_TABLE_H_
