#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_

#include <functional>

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

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_TIMER_H_
