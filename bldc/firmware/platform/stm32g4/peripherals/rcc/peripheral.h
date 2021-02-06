#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_

#include <functional>

namespace platform {
namespace stm32g4 {

namespace rcc {

constexpr uint32_t kRccInstance = 0x4002'1000;

struct Peripheral {
  Peripheral() = delete;
  Peripheral(Peripheral&) = delete;
  Peripheral(Peripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  using APB1ENR1 = APB1ENR1_value_t;

  inline void EnableTim2(bool enable) {
    EnableAPB1Clock(&APB1ENR1::with_TIM2EN, enable);
  };
  inline void EnableTim3(bool enable) {
    EnableAPB1Clock(&APB1ENR1::with_TIM3EN, enable);
  };
  inline void EnableTim4(bool enable) {
    EnableAPB1Clock(&APB1ENR1::with_TIM4EN, enable);
  };
  inline void EnableTim5(bool enable) {
    EnableAPB1Clock(&APB1ENR1::with_TIM5EN, enable);
  };

 private:
  inline void EnableAPB1Clock(auto bit_selector, bool enable) {
    update_APB1ENR1(
        [&](APB1ENR1 v) { return std::invoke(bit_selector, v, enable); });
  }
};

}  // namespace rcc

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
