#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
// #include "bldc/firmware/stm32g474/system.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_tim.h"

namespace platform {
namespace stm32g4 {

uint32_t SysTickTimer::period_micros_ = 1000;
uint32_t SysTickTimer::tick_count_ = 0;

void SysTickTimer::SetPeriod(uint32_t micros) {
  period_micros_ = micros;
  UpdatePeriod();
}

void SysTickTimer::UpdatePeriod() {
  // TODO(blakely): Determine if we need to disable interrupts here.
  Nvic::SetInterrupt(stm32g4::Interrupt::ISysTick, 2, 0,
                     [] { SysTickHandler(); });
  const uint32_t core_clock_freq = Rcc::GetHClockFrequency();
  SysTick_Config((core_clock_freq / 1'000'000U) * period_micros_);
  ResetCount();
}

void SysTickTimer::ResetCount() { tick_count_ = 0; }

void SysTickTimer::SysTickHandler() {
  ++tick_count_;  //
}

void SysTickTimer::BlockingWait(uint32_t micros) {
  ResetCount();
  while (tick_count_ * period_micros_ < micros) {
    asm("nop");
  }
}

struct Timer::TIM_TypeDefI : public TIM_TypeDef {};

Timer::Timer(TIM_TypeDefI* timer)
    : timer_(timer),
      division_(ClockDivision::DIV1),
      prescalar_(0),
      arr_period_(0),
      repetition_counter_(0) {}

void Timer::Start() { LL_TIM_EnableCounter(timer_); }

void Timer::ConfigureClock() {
  LL_TIM_SetClockDivision(timer_, static_cast<uint32_t>(division_));
  LL_TIM_SetPrescaler(timer_, prescalar_);
  LL_TIM_SetAutoReload(timer_, arr_period_);
  LL_TIM_SetRepetitionCounter(timer_, repetition_counter_);
}

void Timer::ConfigureChannel(uint32_t channel) {
  LL_TIM_CC_EnableChannel(timer_, channel);
  LL_TIM_OC_ConfigOutput(timer_, channel,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  // LL_TIM_OC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH4, LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(timer_, channel, LL_TIM_OCMODE_PWM2);
}

Tim3::Tim3() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM3)) {}

void Tim3::Enable() { Rcc::EnableTim3(); }

void Tim3::Configure() {
  Enable();
  division_ = ClockDivision::DIV1;
  prescalar_ = 17000;
  arr_period_ = 5000;
  repetition_counter_ = 0;
  ConfigureClock();
}

void Tim3::EnableOutput(Channel channel) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch4:
      ll_chan = LL_TIM_CHANNEL_CH4;
      LL_TIM_OC_SetCompareCH4(timer_, arr_period_ * .75);
      break;
  };
  ConfigureChannel(ll_chan);
}

// void Tim2::Enable() { Rcc::EnableTim2(); }

// void Tim2::Configure() {
//   Enable();
//   // Timer-wide settings
//   LL_TIM_SetClockDivision(TIM2, LL_TIM_CLOCKDIVISION_DIV1);
//   LL_TIM_SetPrescaler(TIM2, 17000);
//   const uint32_t period = 10000;
//   LL_TIM_SetAutoReload(TIM2, period);
//   LL_TIM_SetRepetitionCounter(TIM2, 0);
//   LL_TIM_OC_SetCompareCH2(TIM2, period * .5);
// }

// void Tim2::Start() { LL_TIM_EnableCounter(TIM2); }

// void Tim2::EnableOutputChannel() {
//   // TODO(blakely): support more than just ch1.
//   LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);
//   LL_TIM_OC_ConfigOutput(TIM2, LL_TIM_CHANNEL_CH1,
//                          LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
//   LL_TIM_OC_SetMode(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM2);
// }

// // Getting around the anonymous struct issue.
// struct Timer::TIM_TypeDefI : TIM_TypeDef {};

// Timer::Timer(TimerInstance instance)
//     : instance_(instance), prescalar_(17000), period_(10000) {
//   switch (instance) {
//     case TimerInstance::Tim2:
//       timer_ = reinterpret_cast<TIM_TypeDefI*>(TIM2);
//       break;
//     case TimerInstance::Tim3:
//       timer_ = reinterpret_cast<TIM_TypeDefI*>(TIM3);
//       break;
//     case TimerInstance::Tim4:
//       timer_ = reinterpret_cast<TIM_TypeDefI*>(TIM4);
//       break;
//   }
// }

// void Timer::Enable() {
//   switch (instance_) {
//     case TimerInstance::Tim2:
//       return LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2);
//     case TimerInstance::Tim3:
//       return LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);
//     case TimerInstance::Tim4:
//       return LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);
//   }
// }

// void Timer::Configure() {
//   Enable();
//   // Timer-wide settings
//   LL_TIM_SetClockDivision(timer_, LL_TIM_CLOCKDIVISION_DIV1);
//   LL_TIM_SetPrescaler(timer_, prescalar_);
//   LL_TIM_SetAutoReload(timer_, period_);
//   LL_TIM_SetRepetitionCounter(timer_, 0);
// }

// void Timer::Start() { LL_TIM_EnableCounter(timer_); }

// void Timer::EnableOutput() {
//   // TODO(blakely): support more than just ch4.
//   const uint32_t channel = LL_TIM_CHANNEL_CH4;
//   LL_TIM_OC_SetCompareCH4(timer_, period_ * .5);
//   LL_TIM_CC_EnableChannel(timer_, channel);
//   LL_TIM_OC_ConfigOutput(timer_, channel,
//                          LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
//   LL_TIM_OC_SetMode(timer_, channel, LL_TIM_OCMODE_PWM2);
// }

}  // namespace stm32g4
}  // namespace platform