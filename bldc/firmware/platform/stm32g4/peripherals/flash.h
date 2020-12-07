#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_

namespace platform {
namespace stm32g4 {

class Flash {
 public:
  static void EnableInstructionCache();
  static void EnableDataCache();
  static void EnablePrefetchBuffer();

  static void UpdateWaitStates(uint32_t core_clock_frequency);
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_
