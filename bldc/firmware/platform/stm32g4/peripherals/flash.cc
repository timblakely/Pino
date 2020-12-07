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

void Flash::UpdateWaitStates(uint32_t core_clock_frequency) {
  // TODO(blakely): assuming Boost mode 1 here.
  if (core_clock_frequency < 34'000'000U) {
    system::LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  } else if (core_clock_frequency < 68'000'000U) {
    system::LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);
  } else if (core_clock_frequency < 102'000'000U) {
    system::LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
  } else if (core_clock_frequency < 136'000'000U) {
    system::LL_FLASH_SetLatency(LL_FLASH_LATENCY_3);
  } else {
    // <= 170MHz
    system::LL_FLASH_SetLatency(LL_FLASH_LATENCY_4);
  }
}

}  // namespace drivers
}  // namespace stm32g474