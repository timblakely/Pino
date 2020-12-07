#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_

namespace stm32g474 {
namespace drivers {

class Flash {
 public:
  static void EnableInstructionCache();
  static void EnableDataCache();
  static void EnablePrefetchBuffer();

  static void UpdateWaitStates(uint32_t core_clock_frequency);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_FLASH_H_
