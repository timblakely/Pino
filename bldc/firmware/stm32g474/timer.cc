#include "bldc/firmware/stm32g474/timer.h"

#include "bldc/firmware/stm32g474/drivers/nvic.h"
#include "bldc/firmware/stm32g474/drivers/rcc.h"

namespace cortex {
// Needed for vendor-specific definitions, otherwise we'd include cortex_m4.h
// directly. :/
#include "third_party/stm32cubeg4/stm32g4xx.h"
}  // namespace cortex

namespace stm32g474 {

using drivers::Nvic;
using drivers::Rcc;

}  // namespace stm32g474