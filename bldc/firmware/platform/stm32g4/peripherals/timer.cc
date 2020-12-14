#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
// #include "bldc/firmware/stm32g474/system.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"
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

TIM_TypeDef* AsLL(AdvancedTimer timer) {
  switch (timer) {
    case AdvancedTimer::Tim1:
    default:
      return TIM1;
    case AdvancedTimer::Tim8:
      return TIM8;
    case AdvancedTimer::Tim20:
      return TIM20;
  }
}

AdvancedTimerImpl::AdvancedTimerImpl(AdvancedTimer timer)
    : timer_instance_(timer) {
  Rcc::Enable(timer);
}

void AdvancedTimerImpl::SetPrescalar(uint32_t prescalar) {
  LL_TIM_SetPrescaler(AsLL(timer_instance_), prescalar);
}

// void AdvancedTimerImpl::SetCountMode(CountMode mode) {
//   auto ll_timer = GetLLTimer(timer_instance_);
//   LL_TIM_SetPrescaler(ll_timer, prescalar);
// }

Tim3::Tim3() {}

void Tim3::Enable() { Rcc::EnableTim3(); }

void Tim3::Configure() {
  Enable();
  // Timer-wide settings
  LL_TIM_SetClockDivision(TIM3, LL_TIM_CLOCKDIVISION_DIV1);
  LL_TIM_SetPrescaler(TIM3, 17000);
  const uint32_t period = 10000;
  LL_TIM_SetAutoReload(TIM3, period);
  LL_TIM_SetRepetitionCounter(TIM3, 0);
  LL_TIM_OC_SetCompareCH4(TIM3, period * .5);
}

void Tim3::Start() { LL_TIM_EnableCounter(TIM3); }

void Tim3::EnableOutputChannel(Channel channel) {
  // TODO(blakely): support more than just ch4.
  // CH4 settings.
  LL_TIM_CC_EnableChannel(TIM3, LL_TIM_CHANNEL_CH4);
  LL_TIM_OC_ConfigOutput(TIM3, LL_TIM_CHANNEL_CH4,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  // LL_TIM_OC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH4, LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(TIM3, LL_TIM_CHANNEL_CH4, LL_TIM_OCMODE_PWM2);
}

void Tim2::Enable() { Rcc::EnableTim2(); }

void Tim2::Configure() {
  Enable();
  // Timer-wide settings
  LL_TIM_SetClockDivision(TIM2, LL_TIM_CLOCKDIVISION_DIV1);
  LL_TIM_SetPrescaler(TIM2, 17000);
  const uint32_t period = 10000;
  LL_TIM_SetAutoReload(TIM2, period);
  LL_TIM_SetRepetitionCounter(TIM2, 0);
  LL_TIM_OC_SetCompareCH2(TIM2, period * .5);
}

void Tim2::Start() { LL_TIM_EnableCounter(TIM2); }

void Tim2::EnableOutputChannel() {
  // TODO(blakely): support more than just ch1.
  LL_TIM_CC_EnableChannel(TIM2, LL_TIM_CHANNEL_CH1);
  LL_TIM_OC_ConfigOutput(TIM2, LL_TIM_CHANNEL_CH1,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(TIM2, LL_TIM_CHANNEL_CH1, LL_TIM_OCMODE_PWM2);
}

}  // namespace stm32g4
}  // namespace platform