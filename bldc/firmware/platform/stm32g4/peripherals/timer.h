#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_

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
  virtual void Configure() = 0;
  void Start();
  void Stop();

 protected:
  // Workaround for the STM libraries using typedef'd anonymous structs.
  struct TIM_TypeDefI;

  Timer(TIM_TypeDefI* timer);

  enum class ClockDivision : uint32_t {
    DIV1 = 0,  // Consistent with LL_TIM_CLOCKDIVISION_DIV1
  };

  void ConfigureClock();
  virtual void ConfigureChannel(uint32_t channel);
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
  };
  virtual void Enable() override;
  virtual void Configure() override;
  void EnableOutput(Channel channel);

  virtual void ConfigureChannel(uint32_t channel) override;
  void SetPwmDuty(Channel channel, float cycle);
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_TIMER_H_
