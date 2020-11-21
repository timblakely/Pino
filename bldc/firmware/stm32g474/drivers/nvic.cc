#include "bldc/firmware/stm32g474/drivers/nvic.h"

#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace st {
#include "third_party/stm32cubeg4/stm32g4xx.h"
}

namespace stm32g474 {
namespace drivers {

void Nvic::Init() {
  // Set 8 bits for primary group, 2 bits for sub-priority
  st::__NVIC_SetPriorityGrouping(0b100);
}

void Nvic::SetSysTickMicros(uint32_t microseconds) {
  // Set tick priority as a lower priority than most.
  st::__NVIC_SetPriority(st::IRQn_Type::SysTick_IRQn, 4);
  const uint32_t core_clock_freq = Rcc::GetCoreClockFrequency();
  st::SysTick_Config(core_clock_freq * (microseconds / 1e6));
}

}  // namespace drivers
}  // namespace stm32g474