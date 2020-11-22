#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_

namespace stm32g474 {
namespace drivers {

class Nvic {
 public:
  static void Init();
  static void DisableInterrupts();
  static void EnableInterrupts();
  static void SetSysTickMicros(uint32_t microseconds);
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_NVIC_H_
