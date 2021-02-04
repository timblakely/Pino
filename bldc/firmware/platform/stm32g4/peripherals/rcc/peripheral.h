#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_

#include "bldc/firmware/platform/stm32g4/peripherals/timer/peripheral.h"

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

  template <auto Peripheral>
  inline void EnableClock();
};

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim2>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM2EN(1); });
}

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim3>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM3EN(1); });
}

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim4>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM4EN(1); });
}

}  // namespace rcc

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
