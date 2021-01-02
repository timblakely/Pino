#include "bldc/firmware/platform/stm32g4/devboard/devboard.h"

#include "bldc/firmware/platform/bldc_platform.h"
#include "bldc/firmware/platform/stm32g4/peripherals/dma.h"
#include "bldc/firmware/platform/stm32g4/peripherals/gpio.h"
#include "bldc/firmware/platform/stm32g4/peripherals/nvic.h"
#include "bldc/firmware/platform/stm32g4/peripherals/rcc.h"
#include "bldc/firmware/platform/stm32g4/peripherals/timer.h"

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
      drv_({Gpio::Port::C, 6}, &spi3_) {}

void Devboard::Init() {
  Nvic::SetInterruptHandler(Interrupt::HardFault, [this] { OnFatal(); });

  red_ = new Led({Gpio::Port::B, 6});
  // green_ = new Led({Gpio::Port::B, 9});  // Correct for v0 board
  // blue_ = new Led({Gpio::Port::B, 7});
  green_ = new Led({Gpio::Port::B, 7});
  blue_ = new Led({Gpio::Port::B, 9});

  Dma dma1(Dma::Instance::Dma1);
  dma1.Init();

  spi1_.Init(Spi::Port::Spi1);
  auto spi1_stream_start =
      dma1.CreateStream(Dma::Channel::Ch1, Dma::Request::Tim5Ch1);
  auto spi1_stream_end = dma1.CreateStream(Dma::Channel::Ch4, Dma::Request::Tim5Ch4);
  spi1_.EnableStreaming(spi1_stream_start, spi1_stream_end);
  ma702_.Init();

  spi3_.Init(Spi::Port::Spi3);
  // spi3_.AutoPoll();

  drv_.Init();
  drv_.Enable();
  SysTickTimer::BlockingWait(1000);
  uint16_t value = 0;
  // value = drv_.BlockingReadRegister(Drv::Register::GateDriveHigh);

  Tim5 tim5;
  tim5.Enable();
  // tim5.ConfigureClock(Timer::ClockDivision::DIV1, 0, 170000, 0);
  tim5.ConfigureClock(Timer::ClockDivision::DIV1, 0, 170000, 0);
  tim5.EnableChannel(Tim5::Channel::Ch1, 1UL);
  tim5.EnableChannel(Tim5::Channel::Ch4, 2048UL + 128 * 1);
  // tim5.ConfigureClock(Timer::ClockDivision::DIV1, 0, 340000000, 0);
  // tim5.EnableChannel(Tim5::Channel::Ch1, 170000000UL);
  // tim5.EnableChannelIRQ(Tim5::Channel::Ch1);
  tim5.EnableChannelDMA(Tim5::Channel::Ch1);
  tim5.EnableChannelDMA(Tim5::Channel::Ch4);
  Nvic::SetInterrupt(Interrupt::Tim5, 1, 1, [] {
    while (true) {
      asm("nop");
    }
  });
  tim5.Start();

  blue_->On();
}

void Devboard::OnFatal() {
  drv_.Disable();
  blue_->Off();
  Tim3 timer;
  timer.Configure();
  timer.EnableOutput(Tim3::Channel::Ch4);
  timer.Start();
  green_->Blink();
  // blue_->On();
  while (true) asm("nop");
}

}  // namespace stm32g4
}  // namespace platform