#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_

namespace platform {
namespace stm32g4 {

class Fpu {
 public:
  // Enable the hardware FPU. Technically it's enabled by -mfloat-abi=hard
  // combined with -mfpu=fpv4-sp-d16, but this function additionally unlocks the
  // control registers.
  static void EnableHardwareFPU();
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_