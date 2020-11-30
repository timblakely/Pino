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

enum class Interrupt : int32_t {
  // Index at -16 so that MaskableInterrupts can match the "position" field in
  // the NVIC documentation.
  IReset = -15,
  INMI = -14,
  HardFault = -13,
  IMemManage = -12,
  IBusFault = -11,
  IUsageFault = -10,
  IPendSV = -2,
  ISysTick = -1,  // Note: Should be SysTick, but ST #defined SysTick... *sigh*

  WWDG = 0,
  Comp7 = 66,
};

using InterruptCallback =
    common::InterruptTable<kTotalNumInterrupts,
                           kInplaceFunctionStorageSize>::Callback;

class Nvic : public common::InterruptTable<kTotalNumInterrupts,
                                           kInplaceFunctionStorageSize> {
 public:
  static void Init();
  static void Init(InterruptCallback default_handler);

  static void RelocateInterruptsToSram();
  static void ResetAllWithDefault(InterruptCallback handler);
  static void ResetAllExceptSysTickWithDefault(InterruptCallback handler);

  static void SetInterrupt(Interrupt interrupt, uint32_t priority,
                           uint32_t subpriority, InterruptCallback handler);
  static void SetInterruptHandler(Interrupt interrupt,
                                  InterruptCallback handler);

  // TODO(blakely): SetPriority

  static void DisableInterrupts();

  static void EnableInterrupts();

  static void SetSysTickMicros(uint32_t microseconds);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_
