#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_H_

#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

namespace platform {
namespace stm32g4 {

class Rcc {
 public:
  static void SetupClocks();

  static uint32_t GetSysClockFrequency();
  static uint32_t GetHClockFrequency();

  static void Enable(Gpio::Port port);
  static void Enable(AdvancedTimer timer);
  static void EnableTim3();
  static void EnableTim2();

 private:
  // Based on board design.
  static constexpr uint32_t kHSEOscillatorSpeed = 24'000'000;
  // From system_stm32g4xx.c
  static constexpr uint8_t AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
                                                1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
  static constexpr uint8_t APBPrescTable[8] = {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_H_
