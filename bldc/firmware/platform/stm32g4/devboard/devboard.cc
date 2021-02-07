#include "bldc/firmware/platform/stm32g4/devboard/devboard.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/can_messages.h"
#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"
#include "bldc/firmware/platform/stm32g4/peripherals/dma.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc/rcc.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer/timer.h"

using platform::stm32g4::Dma;

namespace platform {

BldcPlatform* BldcPlatform::Instance() {
  static stm32g4::Devboard kPlatform;
  return &kPlatform;
}

namespace stm32g4 {

Devboard::Devboard()
    : spi1_({Gpio::Port::A, 4}, {Gpio::Port::A, 5}, {Gpio::Port::A, 7},
            {Gpio::Port::A, 6}),
      ma702_(&spi1_),
      spi3_({Gpio::Port::A, 15}, {Gpio::Port::C, 10}, {Gpio::Port::B, 5},
            {Gpio::Port::C, 11}),
      drv_({Gpio::Port::C, 6}, &spi3_),
      can_({Gpio::Port::A, 12}, {Gpio::Port::A, 11}) {}

void Devboard::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });

  red_ = new Led({Gpio::Port::B, 6});
  green_ = new Led({Gpio::Port::B, 7});
  blue_ = new Led({Gpio::Port::B, 9});

  auto t4 = Timer<timer::Instance::Tim4>();
  t4.SetFrequency(2, 0.05f);
  t4.OutputToggle(1);
  t4.OutputPWM(4, 0.5);
  t4.Start();
  red_->Blink();
  blue_->Blink();

  auto t3 = Timer<timer::Instance::Tim3>();
  t3.SetFrequency(1, 0.05f);
  t3.OutputToggle(4);
  t3.Start();

  auto t5 = Timer<timer::Instance::Tim5>();
  (void)t5;
  (void)t5.GetResetValue();
  // auto t1 = Timer<timer::Instance::Tim1>();
  // (void)t1;
  // (void)t1.GetResetValue();
  green_->Blink();
  while (true) {
    asm("nop");
  }

  Dma dma1(Dma::Instance::Dma1);
  dma1.Init();

  spi1_.Init(Spi::Port::Spi1);
  auto enable = dma1.CreateStream(Dma::Channel::Ch1, Dma::Request::Tim5Ch1);
  auto spi1_command =
      dma1.CreateStream(Dma::Channel::Ch2, Dma::Request::Tim5Ch1);
  auto spi1_response =
      dma1.CreateStream(Dma::Channel::Ch3, Dma::Request::Tim5Ch4);
  auto spi1_disable =
      dma1.CreateStream(Dma::Channel::Ch4, Dma::Request::Tim5Ch4);

  spi1_.EnableStreaming(enable, spi1_disable);
  ma702_.Init();
  ma702_.AutoPoll(spi1_command, spi1_response);

  spi3_.Init(Spi::Port::Spi3);

  drv_.Init();
  drv_.Enable();
  SysTickTimer::BlockingWait(1000);
  // uint16_t value = 0;
  // value = drv_.BlockingReadRegister(Drv::Register::GateDriveHigh);

  Tim5 tim5;
  tim5.Enable();
  tim5.ConfigureClock(Timer::ClockDivision::DIV1, 0, 170000, 0);
  tim5.EnableChannel(Tim5::Channel::Ch1, 1UL);
  tim5.EnableChannel(Tim5::Channel::Ch4, 2048UL + 128 * 1);
  tim5.EnableChannelDMA(Tim5::Channel::Ch1);
  tim5.EnableChannelDMA(Tim5::Channel::Ch4);
  Nvic::SetInterrupt(Interrupt::Tim5, 1, 1, [] {
    while (true) {
      asm("nop");
    }
  });
  tim5.Start();

  can_.Init(Can::Instance::Fdcan1);

  // can ext 10 1234 FBr
  can_.SetHandler<0>([](SimpleReceiveFrame& f) {
    auto foo = f.foo();
    (void)foo;
    auto bar = f.bar();
    ++bar;
  });

  tim3.Configure();
  tim3.EnableOutput(Tim3::Channel::Ch4);
  tim3.Start();
  green_->Blink();
  // blue_->On();
  while (true) asm("nop");

  while (true) {
    AngleFrame frame(ma702_.Angle());
    can_.SendFrame(frame);
    SysTickTimer::BlockingWait(100000);
  }

  blue_->On();
}

void Devboard::InitializeTimers() {
  // Tim3 is LED blinker, but nothing to do for now.
}

uint16_t Devboard::Angle() { return ma702_.Angle(); }

void Devboard::OnFatal() {
  drv_.Disable();
  blue_->Off();
  tim3.Configure();
  tim3.EnableOutput(Tim3::Channel::Ch4);
  tim3.Start();
  green_->Blink();
  // blue_->On();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform