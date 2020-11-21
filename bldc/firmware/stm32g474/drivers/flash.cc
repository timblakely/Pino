#include "bldc/firmware/stm32g474/drivers/flash.h"

#include "third_party/stm32cubeg4/stm32g474xx.h"

namespace system {
#include "third_party/stm32cubeg4/stm32g4xx_ll_system.h"
}

namespace stm32g474 {
namespace drivers {

void Flash::EnableInstructionCache() { system::LL_FLASH_EnableInstCache(); }

void Flash::EnableDataCache() { system::LL_FLASH_EnableDataCache(); }

void Flash::EnablePrefetchBuffer() { system::LL_FLASH_EnablePrefetch(); }

}  // namespace drivers
}  // namespace stm32g474