#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_

#include <stdint.h>

namespace stm32g474 {
namespace drivers {

class Rcc {
 public:
  static constexpr uint32_t kHSEOscillatorSpeed = 24'000'000;
  static void SetupClocks();
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_
