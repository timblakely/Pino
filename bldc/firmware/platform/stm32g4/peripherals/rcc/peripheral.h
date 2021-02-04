#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_

#include <functional>
#include <iostream>
#include <tuple>
#include <type_traits>

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

namespace map {
using Timer = timer::Instance;

// template <auto I, typename T>
// struct ct_pair {
//   using type = T;

//   static ct_pair get_pair(decltype(I)) { return {}; }
// };

// template <typename... Ps>
// struct ct_map : public Ps... {
//   using Ps::get_pair...;

//   template <auto I>
//   using find_type = typename decltype(get_pair(I))::type;
// };

template <auto I, typename T>
struct ct_pair {
  using type = T;

  static ct_pair get_pair(
      std::integral_constant<std::size_t, static_cast<uint32_t>(I)>) {
    return {};
  }
};

template <typename... Ps>
struct ct_map : public Ps... {
  using Ps::get_pair...;

  template <auto I>
  using find_type = typename decltype(get_pair(
      std::integral_constant<std::size_t, static_cast<uint32_t>(I)>{}))::type;
};

using bus_map = ct_map<ct_pair<Timer::Tim2, Peripheral::APB1ENR1>,  //
                       ct_pair<Timer::Tim3, Peripheral::APB1ENR1>,
                       ct_pair<Timer::Tim4, Peripheral::APB1ENR1>>;

// template <auto R>
// using bus_map = false;

// template <>
// using bus_map<Timer::Tim2> = Peripheral::APB1ENR1;
// template <>
// using bus_map<Timer::Tim3> = Peripheral::APB1ENR1;
// template <>
// using bus_map<Timer::Tim4> = Peripheral::APB1ENR1;

template <auto T>
static constexpr auto clock_bit = nullptr;

template <>
constexpr auto clock_bit<Timer::Tim2> = &Peripheral::APB1ENR1::with_TIM2EN;
template <>
constexpr auto clock_bit<Timer::Tim3> = &Peripheral::APB1ENR1::with_TIM3EN;
template <>
// constexpr auto clock_bit<Timer::Tim4> = &Peripheral::APB1ENR1::with_TIM4EN;
constexpr auto clock_bit<Timer::Tim4> =
    &bus_map::find_type<Timer::Tim4>::with_TIM4EN;
}  // namespace map

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim2>() {
  // update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM2EN(1); });
  update_APB1ENR1([](APB1ENR1 v) {
    return std::invoke(map::clock_bit<map::Timer::Tim2>, v, 1);
  });
}

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim3>() {
  update_APB1ENR1([](APB1ENR1 v) {
    return std::invoke(map::clock_bit<map::Timer::Tim3>, v, 1);
  });
}

template <>
inline void Peripheral::EnableClock<timer::Instance::Tim4>() {
  // update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM4EN(1); });
  update_APB1ENR1([](APB1ENR1 v) {
    return std::invoke(map::clock_bit<map::Timer::Tim4>, v, 1);
  });
}

}  // namespace rcc

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_RCC_PERIPHERAL_H_
