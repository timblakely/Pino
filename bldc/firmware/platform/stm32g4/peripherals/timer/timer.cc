#include "bldc/firmware/platform/stm32g4/peripherals/timer/timer.h"

#include <math.h>

#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"
#include "third_party/stm32cubeg4/stm32g474xx.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_tim.h"

namespace platform {
namespace stm32g4 {

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

void Timer::ConfigureClock(ClockDivision division, uint32_t prescalar,
                           uint32_t period, uint32_t repetition) {
  SetDivision(division);
  SetPrescalar(prescalar);
  SetPeriod(period);
  SetRepetition(repetition);
}

void Timer::SetDivision(ClockDivision division) {
  division_ = division;
  switch (division_) {
    case ClockDivision::DIV1:
      LL_TIM_SetClockDivision(timer_, LL_TIM_CLOCKDIVISION_DIV1);
      break;
    case ClockDivision::DIV2:
      LL_TIM_SetClockDivision(timer_, LL_TIM_CLOCKDIVISION_DIV2);
      break;
    case ClockDivision::DIV4:
      LL_TIM_SetClockDivision(timer_, LL_TIM_CLOCKDIVISION_DIV4);
      break;
  }
}

void Timer::SetPrescalar(uint32_t prescalar) {
  prescalar_ = prescalar;
  LL_TIM_SetPrescaler(timer_, prescalar_);
}

void Timer::SetPeriod(uint32_t period) {
  arr_period_ = period;
  LL_TIM_SetAutoReload(timer_, arr_period_);
}

void Timer::SetRepetition(uint32_t repetition) {
  repetition_counter_ = repetition;
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

void Tim3::Enable() { LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3); }

void Tim3::Configure() {
  Enable();
  ConfigureClock(ClockDivision::DIV1, 17000, 5000, 0);
}

void Tim3::EnableOutput(Channel channel) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch4:
      ll_chan = LL_TIM_CHANNEL_CH4;
      LL_TIM_OC_SetCompareCH4(timer_, static_cast<uint32_t>(arr_period_ * .95));
      break;
  };
  ConfigureChannel(ll_chan);
}

Tim2::Tim2() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM2)) {}

void Tim2::Enable() { LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM2); }

void Tim2::Configure() {
  Enable();
  ConfigureClock(ClockDivision::DIV1, 17000, 2000, 0);
}

void Tim2::EnableOutput(Channel channel) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch1:
      ll_chan = LL_TIM_CHANNEL_CH1;
      LL_TIM_OC_SetCompareCH1(timer_, static_cast<uint32_t>(arr_period_ * .5));
      break;
  };
  ConfigureChannel(ll_chan);
}

Tim1::Tim1() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM1)) {}

void Tim1::Enable() {
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_TIM1);
  LL_TIM_EnableAllOutputs(timer_);
}

void Tim1::Configure() {
  Enable();
  ConfigureClock(ClockDivision::DIV1, 0, 2125, 0);
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
  return SetCaptureCompare(
      channel, static_cast<uint32_t>(static_cast<float>(arr_period_) * duty));
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

Tim5::Tim5() : Timer(reinterpret_cast<TIM_TypeDefI*>(TIM5)) {}

void Tim5::Enable() { LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM5); }

void Tim5::EnableChannel(Channel channel, uint32_t compare_value) {
  uint32_t ll_chan = 0;
  switch (channel) {
    case Channel::Ch1:
      ll_chan = LL_TIM_CHANNEL_CH1;
      LL_TIM_OC_SetCompareCH1(timer_, compare_value);
      break;
    case Channel::Ch2:
      ll_chan = LL_TIM_CHANNEL_CH2;
      LL_TIM_OC_SetCompareCH2(timer_, compare_value);
      break;
    case Channel::Ch3:
      ll_chan = LL_TIM_CHANNEL_CH3;
      LL_TIM_OC_SetCompareCH3(timer_, compare_value);
      break;
    case Channel::Ch4:
      ll_chan = LL_TIM_CHANNEL_CH4;
      LL_TIM_OC_SetCompareCH4(timer_, compare_value);
      break;
  }

  LL_TIM_CC_EnableChannel(timer_, ll_chan);
  // TODO(blakely): Make this configurable.
  LL_TIM_OC_ConfigOutput(timer_, ll_chan,
                         LL_TIM_OCIDLESTATE_LOW | LL_TIM_OCPOLARITY_HIGH);
  LL_TIM_OC_SetMode(timer_, ll_chan, LL_TIM_OCMODE_PWM2);
}

void Tim5::EnableChannel(Channel channel, float duty_cycle) {
  EnableChannel(channel, static_cast<uint32_t>(static_cast<float>(arr_period_) *
                                               duty_cycle));
}

void Tim5::EnableChannelIRQ(Channel channel) {
  Nvic::EnableInterrupt(Interrupt::Tim5);
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_EnableIT_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_EnableIT_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_EnableIT_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_EnableIT_CC4(timer_);
  }
}

void Tim5::DisableChannelIRQ(Channel channel) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_DisableIT_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_DisableIT_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_DisableIT_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_DisableIT_CC4(timer_);
  }
}

void Tim5::ClearChannelIRQ(Channel channel) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_ClearFlag_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_ClearFlag_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_ClearFlag_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_ClearFlag_CC4(timer_);
  }
}

void Tim5::EnableChannelDMA(Channel channel) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_EnableDMAReq_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_EnableDMAReq_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_EnableDMAReq_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_EnableDMAReq_CC4(timer_);
  }
}

void Tim5::DisableChannelDMA(Channel channel) {
  switch (channel) {
    case Channel::Ch1:
      return LL_TIM_DisableDMAReq_CC1(timer_);
    case Channel::Ch2:
      return LL_TIM_DisableDMAReq_CC2(timer_);
    case Channel::Ch3:
      return LL_TIM_DisableDMAReq_CC3(timer_);
    case Channel::Ch4:
      return LL_TIM_DisableDMAReq_CC4(timer_);
  }
}

AdvancedTimer::AdvancedTimer(Instance instance)
    : peripheral_(reinterpret_cast<timer::AdvancedPeripheral*>(instance)) {}

GeneralPurposeATimer::GeneralPurposeATimer(timer::Instance instance)
    : peripheral_(reinterpret_cast<timer::GPAPeripheral*>(instance)) {
}

bool GeneralPurposeATimer::SetFrequency(float hz, float tolerance) {
  peripheral_->InternalClock();
  const uint32_t clock_freq = Rcc::GetSysClockFrequency();
  uint16_t prescalar = 1;
  uint16_t closest_prescalar = 1;
  uint16_t closest_arr = (1 << 16) - 1;
  float diff = std::numeric_limits<float>::infinity();
  while (prescalar < ((1 << 16) - 1)) {
    uint32_t arr = static_cast<uint32_t>(ceil(
        static_cast<float>(clock_freq) / (hz * static_cast<float>(prescalar))));
    if (arr > (1 << 16) - 1) {
      ++prescalar;
      continue;
    }
    float current_diff = abs(float(clock_freq) / float(prescalar * arr) - hz);
    if (current_diff < diff) {
      closest_prescalar = prescalar;
      closest_arr = arr;
      diff = current_diff;
    }
    if (diff < tolerance) {
      closest_prescalar = prescalar;
      closest_arr = static_cast<uint16_t>(arr);
      break;
    }
    ++prescalar;
  }
  ConfigureTimer(closest_prescalar, closest_arr);
  return diff == 0;
}

void GeneralPurposeATimer::OutputPWM(uint8_t channel, float duty_cycle) {
  peripheral_->EnableOutput(channel);
  peripheral_->Up();
  peripheral_->SetCompare(channel, peripheral_->GetResetValue() * duty_cycle);
}

void GeneralPurposeATimer::OutputToggle(uint8_t channel) {
  peripheral_->EnableOutputToggle(static_cast<uint8_t>(channel));
  peripheral_->Up();
  peripheral_->SetCompare(static_cast<uint8_t>(channel),
                          peripheral_->GetResetValue());
}

}  // namespace stm32g4
}  // namespace platform