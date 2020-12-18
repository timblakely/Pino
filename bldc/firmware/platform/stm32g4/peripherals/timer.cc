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

void Timer::Start() {
  LL_TIM_EnableCounter(timer_);  //
}

void Timer::Stop() { LL_TIM_DisableCounter(timer_); }

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
      LL_TIM_OC_SetCompareCH4(timer_, arr_period_ * .95);
      break;
  };
  ConfigureChannel(ll_chan);
}

Tim2::Tim2() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM2)) {}

void Tim2::Enable() { Rcc::EnableTim2(); }

void Tim2::Configure() {
  Enable();
  division_ = ClockDivision::DIV1;
  prescalar_ = 17000;
  arr_period_ = 2000;
  repetition_counter_ = 0;
  ConfigureClock();
}

void Tim2::EnableOutput(Channel channel) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch1:
      ll_chan = LL_TIM_CHANNEL_CH1;
      LL_TIM_OC_SetCompareCH1(timer_, arr_period_ * .5);
      break;
  };
  ConfigureChannel(ll_chan);
}

Tim1::Tim1() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM1)) {}

void Tim1::Enable() {
  Rcc::EnableTim1();
  LL_TIM_EnableAllOutputs(timer_);
}

void Tim1::Configure() {
  Enable();
  division_ = ClockDivision::DIV1;
  prescalar_ = 0;
  // arr_period_ = 4250;  // 40kHz
  arr_period_ = 2125;  // 80kHz
  repetition_counter_ = 0;
  ConfigureClock();
  LL_TIM_SetCounterMode(timer_, LL_TIM_COUNTERMODE_CENTER_DOWN);
}

void Tim1::EnableOutput(Channel channel) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch1:
      ll_chan = LL_TIM_CHANNEL_CH1;
      break;
    case Channel::Ch2:
      ll_chan = LL_TIM_CHANNEL_CH2;
      break;
    case Channel::Ch3:
      ll_chan = LL_TIM_CHANNEL_CH3;
      break;
    case Channel::Ch4:
      ll_chan = LL_TIM_CHANNEL_CH4;
      break;
    case Channel::Ch5:
      ll_chan = LL_TIM_CHANNEL_CH5;
      break;
  };
  SetPwmDuty(channel, 0.5);
  ConfigureChannel(ll_chan);
}

void Tim1::SetPwmDuty(Channel channel, float duty) {
  return SetCaptureCompare(channel, arr_period_ * duty);
}

void Tim1::SetCaptureCompare(Channel channel, uint32_t value) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_OC_SetCompareCH1(timer_, value);
    case Channel::Ch2:
      return LL_TIM_OC_SetCompareCH2(timer_, value);
    case Channel::Ch3:
      return LL_TIM_OC_SetCompareCH3(timer_, value);
    case Channel::Ch4:
      return LL_TIM_OC_SetCompareCH4(timer_, value);
    case Channel::Ch5:
      // This is actually broken. The ST headers have TIM_CCR5_CCR5_Msk set to
      // 0xFFFFFFFF, when it should only be 0xFFFFF. That effectively wipes out
      // the GC5Cx bits when it's set.
      timer_->CCR5 = (timer_->CCR5 & ~(0xFFFFF)) | static_cast<uint32_t>(value);
      return;
  };
}

void Tim1::ConfigureChannel(uint32_t channel) {
  LL_TIM_CC_EnableChannel(timer_, channel);
  LL_TIM_OC_ConfigOutput(timer_, channel,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(timer_, channel, LL_TIM_OCMODE_PWM1);
}

void Tim1::EnableDeadtimeInsertion(float max_duty) {
  LL_TIM_CC_EnableChannel(timer_, LL_TIM_CHANNEL_CH5);
  LL_TIM_OC_ConfigOutput(timer_, LL_TIM_CHANNEL_CH5,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(timer_, LL_TIM_CHANNEL_CH5, LL_TIM_OCMODE_PWM1);
  LL_TIM_SetCH5CombinedChannels(timer_, LL_TIM_GROUPCH5_OC1REFC |
                                            LL_TIM_GROUPCH5_OC2REFC |
                                            LL_TIM_GROUPCH5_OC3REFC);
  SetPwmDuty(Channel::Ch5, max_duty);
}

void Tim1::EnableCCInterrupt(Channel channel) {
  Nvic::EnableInterrupt(Interrupt::Tim1_CaptureCompare);
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_EnableIT_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_EnableIT_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_EnableIT_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_EnableIT_CC4(timer_);
    case Channel::Ch5:
      break;
  };
}

void Tim1::ClearCCInterrupt(Channel channel) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_ClearFlag_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_ClearFlag_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_ClearFlag_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_ClearFlag_CC4(timer_);
    case Channel::Ch5:
      break;
  };
}

}  // namespace stm32g4
}  // namespace platform