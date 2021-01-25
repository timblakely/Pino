#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_NVIC_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_NVIC_H_

#include "bldc/firmware/interrupt_table.hpp"
#include "third_party/sg14/inplace_function.h"

namespace platform {
namespace stm32g4 {

static const uint32_t kNumCortexInterrupts = 16;
static const uint32_t kNumMaskableInterrupts = 102;
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
  Tim1_CaptureCompare = 27,

  Tim5 = 50,

  Comp7 = 66,
};

using InterruptCallback = common::InterruptTable<kTotalNumInterrupts>::Callback;

class Nvic : public common::InterruptTable<kTotalNumInterrupts> {
 public:
  static void Init();
  static void Init(InterruptCallback default_handler);

  static void ResetAllWithDefault(InterruptCallback handler);
  static void ResetAllExceptSysTickWithDefault(InterruptCallback handler);

  static void SetInterrupt(Interrupt interrupt, uint32_t priority,
                           uint32_t subpriority, InterruptCallback handler);
  static void SetInterruptHandler(Interrupt interrupt,
                                  InterruptCallback handler);

  // TODO(blakely): SetPriority

  static void DisableInterrupts();

  static void EnableInterrupts();
  static void EnableInterrupt(Interrupt interrupt);
  static void DisableInterrupt(Interrupt interrupt);

  static void SetSysTickMicros(uint32_t microseconds);
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_NVIC_H_
