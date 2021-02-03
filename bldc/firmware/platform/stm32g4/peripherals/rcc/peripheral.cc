#include "bldc/firmware/platform/stm32g4/peripherals/rcc/peripheral.h"

#include "bldc/firmware/platform/stm32g4/peripherals/timer/peripheral.h"

namespace platform {
namespace stm32g4 {

namespace rcc {

using Timer = timer::Instance;

template <>
void Peripheral::EnableClock<Timer::Tim2>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM2EN(1); });
}

template <>
void Peripheral::EnableClock<Timer::Tim3>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM3EN(1); });
}

template <>
void Peripheral::EnableClock<Timer::Tim4>() {
  update_APB1ENR1([](APB1ENR1 v) { return v.with_TIM4EN(1); });
}

}  // namespace rcc
}  // namespace stm32g4
}  // namespace platform