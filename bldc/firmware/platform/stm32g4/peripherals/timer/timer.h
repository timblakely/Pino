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

class Timer {
 public:
  virtual void Enable() = 0;
  virtual void Configure(){};
  void Start();
  void Stop();

  uint32_t Prescalar() { return prescalar_; }
  uint32_t Period() { return arr_period_; }

  enum class ClockDivision : uint32_t {
    DIV1,  // Consistent with LL_TIM_CLOCKDIVISION_DIV1
    DIV2,
    DIV4,
  };

  void ConfigureClock(ClockDivision division, uint32_t prescalar,
                      uint32_t period, uint32_t repetition);

  inline void SetDivision(ClockDivision division);
  inline void SetPrescalar(uint32_t prescalar);
  inline void SetPeriod(uint32_t period);
  inline void SetRepetition(uint32_t repetition);
  virtual void ConfigureChannel(uint32_t channel);

 protected:
  // Workaround for the STM libraries using typedef'd anonymous structs.
  struct TIM_TypeDefI;

  Timer(TIM_TypeDefI* timer);
  TIM_TypeDefI* timer_;
  ClockDivision division_;
  uint32_t prescalar_;
  uint32_t arr_period_;
  uint32_t repetition_counter_;
};

class Tim3 : public Timer {
 public:
  Tim3();
  enum class Channel {
    Ch4,
  };
  virtual void Enable() override;
  virtual void Configure() override;
  void EnableOutput(Channel channel);
};

class Tim2 : public Timer {
 public:
  Tim2();
  enum class Channel {
    Ch1,
  };
  virtual void Enable() override;
  virtual void Configure() override;
  void EnableOutput(Channel channel);
};

class Tim1 : public Timer {
 public:
  Tim1();
  enum class Channel {
    Ch1,
    Ch2,
    Ch3,
    Ch4,

    // Output compare only, no external.
    Ch5,
  };

  virtual void Enable() override;
  virtual void Configure() override;
  void EnableOutput(Channel channel);

  virtual void ConfigureChannel(uint32_t channel) override;
  void SetPwmDuty(Channel channel, float duty);
  void SetCaptureCompare(Channel channel, uint32_t value);

  void EnableDeadtimeInsertion(float duty);
  void EnableCCInterrupt(Channel channel);
  void ClearCCInterrupt(Channel channel);
};

// 32-bit timer.
class Tim5 : public Timer {
 public:
  Tim5();
  enum class Channel {
    Ch1,
    Ch2,
    Ch3,
    Ch4,
  };
  virtual void Enable() override;
  void EnableChannel(Channel channel, uint32_t compare_value);
  void EnableChannel(Channel channel, float duty_cycle);
  void EnableChannelIRQ(Channel channel);
  void DisableChannelIRQ(Channel channel);
  void ClearChannelIRQ(Channel channel);
  void EnableChannelDMA(Channel channel);
  void DisableChannelDMA(Channel channel);
};

class AdvancedTimer {
 public:
  enum class Instance : uint32_t {
    Tim1 = 0x4001'2C00,
    Tim8 = 0x4001'3400,
    Tim20 = 0x4001'5000,
  };
  AdvancedTimer(Instance instance);

 private:
  timer::AdvancedPeripheral* peripheral_;
};

// old size: 53540

template <timer::ATimer Instance>
class GeneralPurposeATimer {
 public:
  GeneralPurposeATimer(timer::Instance instance)
      : peripheral_(reinterpret_cast<Instance*>(instance)),
        instance_(instance) {}

  // Will attempt to set the timer to the most accurate resolution possible at
  // the given frequency. Caution: Uses an iterative solver. For frequencies
  // that cannot be computed directly for current clock frequency, this function
  // has the potential to take tens of thousands of clock cycles. This scenario
  // tends to occur more frequently when hz < f_clk / 2^16. If this is an issue,
  // increase the tolerance limit. Returns whether the exact frequency was able
  // to be set.
  bool SetFrequency(float hz, float tolerance = 0.00001f) {
    peripheral_->InternalClock();
    const uint32_t clock_freq = Rcc::GetSysClockFrequency();
    uint16_t prescalar = 1;
    uint16_t closest_prescalar = 1;
    uint16_t closest_arr = (1 << 16) - 1;
    float diff = std::numeric_limits<float>::infinity();
    while (prescalar < ((1 << 16) - 1)) {
      uint32_t arr =
          static_cast<uint32_t>(ceil(static_cast<float>(clock_freq) /
                                     (hz * static_cast<float>(prescalar))));
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

  void OutputPWM(uint8_t channel, float duty_cycle) {
    peripheral_->EnableOutput(channel);
    peripheral_->Up();
    peripheral_->SetCompare(channel, peripheral_->GetResetValue() * duty_cycle);
  }

  void OutputToggle(uint8_t channel) {
    peripheral_->EnableOutputToggle(static_cast<uint8_t>(channel));
    peripheral_->Up();
    peripheral_->SetCompare(static_cast<uint8_t>(channel),
                            peripheral_->GetResetValue());
  }

  inline void Start() { peripheral_->Enable(); }

  inline void Stop() { peripheral_->Disable(); }

  inline void EnableClock(bool enable) { Rcc::EnableClock(instance_, enable); }

  inline void ConfigureTimer(uint16_t prescalar, uint16_t auto_reset) {
    peripheral_->ConfigureTimer(prescalar, auto_reset);
  }

 private:
  Instance* peripheral_;
  timer::Instance instance_;
};

template <timer::Instance T>
constexpr static auto TimerType = [] {
  if constexpr (T == timer::Instance::Tim3) {
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
