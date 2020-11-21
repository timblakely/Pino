#include "bldc/firmware/stm32g474/drivers/nvic.h"

namespace st {
#include "third_party/stm32cubeg4/stm32g4xx.h"
}

namespace stm32g474 {
namespace drivers {

void Nvic::Init() {
  // Set 8 bits for primary group, 2 bits for sub-priority
  st::__NVIC_SetPriorityGrouping(0b100);
}

}  // namespace drivers
}  // namespace stm32g474