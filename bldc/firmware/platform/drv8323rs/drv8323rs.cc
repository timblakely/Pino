#include "bldc/firmware/platform/drv8323rs/drv8323rs.h"

#include <utility>

using platform::stm32g4::Gpio;
using platform::stm32g4::Spi;

namespace platform {
namespace drv8323rs {

Drv::Drv(Gpio::Pin enable, Spi* spi) : enable_(std::move(enable)), spi_(spi) {}

void Drv::Init() {
  // Configure DRV_EN as general purpose GPIO.
  enable_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  // TODO(blakely): Register configuration.
  // TODO(blakely): Support 5MBit (32 prescalar). Requires stronger pullup on
  // DRV MISO line.
  spi_->SetBaud(1000);
  spi_->Configure(Spi::ClockPhase::SecondEdge, Spi::IdleState::Low,
                  Spi::FrameSize::SixteenBit);
  spi_->SetNssMode(Spi::NssMode::Hard);
}

void Drv::Enable() { enable_.High(); }

void Drv::Disable() { enable_.Low(); }

uint16_t Drv::BlockingReadRegister(Register reg) {
  uint16_t value = 0;
// TODO(blakely): Correct this
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
  uint16_t data = kReadMask | (static_cast<uint16_t>(reg) << 11);
#pragma GCC diagnostic pop
  spi_->BlockingTransfer(data, &value);
  return value;
}

}  // namespace drv8323rs
}  // namespace platform