#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_

#include "bldc/firmware/interrupt_table.hpp"
#include "third_party/sg14/inplace_function.h"

namespace stm32g474 {
namespace drivers {

static const uint32_t kNumCortexInterrupts = 16;
static const uint32_t kNumMaskableInterrupts = 102;
static const uint32_t kInplaceFunctionStorageSize = 10;
static const uint32_t kTotalNumInterrupts =
    kNumCortexInterrupts + kNumMaskableInterrupts;

enum class CortexInterrupt : int32_t {
  IReset = 1,
  INMI = 2,
  IHard = 3,
  IMemManage = 4,
  IBusFault = 5,
  IUsageFault = 6,
  IPendSV = 14,
  ISysTick = 15,  // Note: Should be SysTick, but ST #defined SysTick... *sigh*
};

enum class MaskableInterrupt : int32_t {
  WWDG = 0,
};

class Nvic : public common::InterruptTable<kTotalNumInterrupts,
                                           kInplaceFunctionStorageSize> {
 public:
  using Callback =
      common::InterruptTable<kTotalNumInterrupts,
                             kInplaceFunctionStorageSize>::Callback;

  static void Init();
  static void Init(Callback default_handler);

  static void RelocateInterruptsToSram();
  static void ResetAllWithDefault(Callback handler);

  template <typename InterruptType>
  static void SetInterrupt(InterruptType interrupt, uint32_t priority,
                           uint32_t subpriority, Callback handler);
  template <typename InterruptType>
  static void SetInterruptHandler(InterruptType interrupt, Callback handler);

  // TODO(blakely): SetPriority

  static void DisableInterrupts();

  static void EnableInterrupts();

  static void SetSysTickMicros(uint32_t microseconds);

 private:
  static void SetInterruptHandler(uint32_t interrupt, Callback handler);
  static void SetInterrupt(uint32_t interrupt, uint32_t priority,
                           uint32_t subpriority, Callback handler);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_
