#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_

namespace stm32g474 {
namespace drivers {

class Rcc {
 public:
  static void SetupClocks();

  // Note: currently hardcoded SysClock source to PLLCLK
  static uint32_t GetCoreClockFrequency();

 private:
  // Based on board design.
  static constexpr uint32_t kHSEOscillatorSpeed = 24'000'000;
  // From system_stm32g4xx.c
  static constexpr uint8_t AHBPrescTable[16] = {0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
                                                1U, 2U, 3U, 4U, 6U, 7U, 8U, 9U};
  static constexpr uint8_t APBPrescTable[8] = {0U, 0U, 0U, 0U, 1U, 2U, 3U, 4U};
};

}  // namespace drivers
}  // namespace stm32g474

#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_RCC_H_
