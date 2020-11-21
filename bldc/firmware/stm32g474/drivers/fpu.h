#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_

namespace stm32g474 {
namespace drivers {

class Fpu {
 public:
  // Enable the hardware FPU. Technically it's enabled by -mfloat-abi=hard
  // combined with -mfpu=fpv4-sp-d16, but this function additionally unlocks the
  // control registers.
  static void EnableHardwareFPU();
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_FPU_H_