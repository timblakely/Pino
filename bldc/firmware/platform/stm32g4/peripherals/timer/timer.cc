#include "bldc/firmware/platform/stm32g4/peripherals/timer/timer.h"

#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_tim.h"

namespace platform {
namespace stm32g4 {}  // namespace stm32g4
}  // namespace platform