#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_DEFINES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_DEFINES_H_

namespace platform {
namespace stm32g4 {

namespace timer {

enum class Instance : uint32_t {
  Tim1 = 0x4001'2C00,
  Tim2 = 0x4000'0000,
  Tim3 = 0x4000'0400,
  Tim4 = 0x4000'0800,
  Tim5 = 0x4000'0C00,
  Tim6 = 0x4000'1000,
  Tim7 = 0x4000'1400,
  Tim8 = 0x4001'3400,
  Tim15 = 0x4001'4000,
  Tim16 = 0x4001'4400,
  Tim17 = 0x4001'4800,
  Tim20 = 0x4001'5000,
};

}

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_DEFINES_H_
