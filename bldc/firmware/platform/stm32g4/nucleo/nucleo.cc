#include "bldc/firmware/platform/stm32g4/nucleo/nucleo.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Nucleo kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Nucleo::Nucleo() {}

void tim1_irh() {
  GPIOC->BSRR = 1U << 3;

  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  asm("nop");
  GPIOC->BSRR = 1U << (16 + 3);
  // blip_->High();
  // blip_->Low();
  TIM1->SR &= ~(1U << 4);
  // timer_.ClearCCInterrupt(Tim1::Channel::Ch4);
  // ClearCC
};

void Nucleo::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });
  // Nvic::SetInterrupt(Interrupt::Tim1_CaptureCompare, 0, 0, [this] {
  //   GPIOC->BSRR = 1U << 3;
  //   // blip_->High();
  //   // blip_->Low();
  //   timer_.ClearCCInterrupt(Tim1::Channel::Ch4);
  //   // ClearCC
  // });
  // Nvic::SetInterrupt(Interrupt::Tim1_CaptureCompare, 0, 0, [] {
  //   GPIOC->BSRR = 1U << 3;

  //   asm("nop");
  //   asm("nop");
  //   asm("nop");
  //   asm("nop");
  //   asm("nop");
  //   GPIOC->BSRR = 1U << (16 + 3);
  //   // blip_->High();
  //   // blip_->Low();
  //   TIM1->SR &= ~(1U << 4);
  //   // timer_.ClearCCInterrupt(Tim1::Channel::Ch4);
  //   // ClearCC
  // });
  NVIC_SetVector(IRQn_Type::TIM1_CC_IRQn,
                 reinterpret_cast<uint32_t>(&tim1_irh));

  user_led_ = new Led({Gpio::Port::A, 5});
  user_led_->On();

  pwm_a_ = new Gpio::Pin({Gpio::Port::C, 0});
  pwm_a_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                    Gpio::AlternateFunction::AF2, Gpio::Speed::VeryHigh);
  pwm_b_ = new Gpio::Pin({Gpio::Port::C, 1});
  pwm_b_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                    Gpio::AlternateFunction::AF2, Gpio::Speed::High);
  pwm_c_ = new Gpio::Pin({Gpio::Port::C, 2});
  pwm_c_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                    Gpio::AlternateFunction::AF2, Gpio::Speed::High);
  blip_ = new Gpio::Pin({Gpio::Port::C, 3});
  blip_->Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                   Gpio::Speed::VeryHigh);

  timer_.Configure();
  timer_.EnableOutput(Tim1::Channel::Ch1);
  timer_.SetPwmDuty(Tim1::Channel::Ch1, 0.25);
  timer_.EnableOutput(Tim1::Channel::Ch2);
  timer_.SetPwmDuty(Tim1::Channel::Ch2, 0.5);
  timer_.EnableOutput(Tim1::Channel::Ch3);
  timer_.SetPwmDuty(Tim1::Channel::Ch3, 1);
  timer_.EnableOutput(Tim1::Channel::Ch4);
  // timer_.SetCaptureCompare(Tim1::Channel::Ch4, timer_.Period() - 1);
  // timer_.SetPwmDuty(Tim1::Channel::Ch4, 0.25);
  timer_.EnableCCInterrupt(Tim1::Channel::Ch4);

  timer_.SetCaptureCompare(Tim1::Channel::Ch1, 1000);
  timer_.SetCaptureCompare(Tim1::Channel::Ch4, 1000);

  timer_.EnableDeadtimeInsertion(0.95);
  timer_.Start();
}

// void Nucleo::SetupClocks() { Rcc::SetupClocks(); }

void Nucleo::OnFatal() {
  Tim2 timer;
  timer.Configure();
  timer.EnableOutput(Tim2::Channel::Ch1);
  timer.Start();
  user_led_->Pin().Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                             Gpio::AlternateFunction::AF1);
  // user_led_->Blink();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform