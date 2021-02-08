#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_

#include <math.h>

#include <functional>

#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer/peripheral.h"

namespace platform {
namespace stm32g4 {

class SysTickTimer {
 public:
  static void SetPeriod(uint32_t micros);
  // Update period, assuming the clock changed.
  static void UpdatePeriod();
  static void ResetCount();
  static void BlockingWait(uint32_t micros);

 private:
  static void SysTickHandler();
  static uint32_t period_micros_;
  static uint32_t tick_count_;
};

////

// old size: 53540

template <timer::ATimer Instance>
class GeneralPurposeATimer {
 public:
  using BitDepth = Instance::BitDepth;
  constexpr static BitDepth kMaxResetValue = static_cast<BitDepth>(0) - 1;
  constexpr static BitDepth kMaxPrescalar = static_cast<uint16_t>(0) - 1;

  GeneralPurposeATimer(timer::Instance instance)
      : peripheral_(reinterpret_cast<Instance*>(instance)),
        instance_(instance) {}

  void EnableChannel(uint8_t channel, BitDepth occ_value) {
    peripheral_->EnableChannel(channel, true);
    peripheral_->SetCompare(channel, occ_value);
  }

  void EnableClock(bool enable) { Rcc::EnableClock(instance_, enable); }

  void OutputPWM(uint8_t channel, float duty_cycle) {
    peripheral_->Up();
    EnableChannel(channel, peripheral_->GetResetValue() * duty_cycle);
    peripheral_->EnableOutput(channel);
  }

  void OutputToggle(uint8_t channel) {
    peripheral_->Up();
    EnableChannel(channel, peripheral_->GetResetValue());
    peripheral_->EnableOutputToggle(channel);
  }

  inline void Start() { peripheral_->Enable(); }

  inline void Stop() { peripheral_->Disable(); }

  inline void ConfigureTimer(uint16_t prescalar, BitDepth auto_reset) {
    peripheral_->ConfigureTimer(prescalar, auto_reset);
  }

  inline void EnableDMARequest(uint8_t channel) {
    peripheral_->EnableDMARequest(channel, true);
  }

  bool SetFrequency(float hz, float tolerance = 0.00001f) {
    peripheral_->InternalClock();
    const uint32_t clock_freq = Rcc::GetSysClockFrequency();
    uint16_t prescalar = 1;
    uint16_t closest_prescalar = 0;
    uint32_t closest_arr = kMaxResetValue;
    float diff = std::numeric_limits<float>::infinity();
    while (prescalar < kMaxPrescalar - 1) {
      uint32_t arr =
          static_cast<uint32_t>(ceil(static_cast<float>(clock_freq) /
                                     (hz * static_cast<float>(prescalar))));
      if (arr > kMaxResetValue) {
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
        closest_arr = static_cast<BitDepth>(arr);
        break;
      }
      ++prescalar;
    }
    ConfigureTimer(closest_prescalar, closest_arr);
    return diff == 0;
  }

  inline auto GetResetValue() { return peripheral_->GetResetValue(); }

 private:
  Instance* peripheral_;
  timer::Instance instance_;
};

template <timer::Instance T>
constexpr static auto TimerType = [] {
  if constexpr (T == timer::Instance::Tim1) {
    return GeneralPurposeATimer<timer::AdvancedPeripheral>(
        timer::Instance::Tim1);
  } else if constexpr (T == timer::Instance::Tim3) {
    return GeneralPurposeATimer<timer::GPAPeripheral<uint16_t>>(
        timer::Instance::Tim3);
  } else if constexpr (T == timer::Instance::Tim4) {
    return GeneralPurposeATimer<timer::GPAPeripheral<uint16_t>>(
        timer::Instance::Tim4);
  } else if constexpr (T == timer::Instance::Tim5) {
    return GeneralPurposeATimer<timer::GPAPeripheral<uint32_t>>(
        timer::Instance::Tim5);
  }
};

template <timer::Instance T>
constexpr static auto Timer = [] {
  auto timer = TimerType<T>();
  timer.EnableClock(true);
  return timer;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_
