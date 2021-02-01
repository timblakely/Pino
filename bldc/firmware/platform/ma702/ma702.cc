
#include "bldc/firmware/platform/ma702/ma702.h"

using platform::stm32g4::Dma;
using platform::stm32g4::Spi;

namespace platform {
namespace ma702 {

Ma702::Ma702(Spi* spi) : spi_(spi) {}

void Ma702::Init() {
  spi_->SetBaud(1000);
  spi_->Configure(Spi::ClockPhase::SecondEdge, Spi::IdleState::High,
                  Spi::FrameSize::SixteenBit);
  spi_->SetNssMode(Spi::NssMode::Hard);

// Register values hardcoded for now.
// TODO(blakely): Correct this
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  uint16_t status = 0;
  status = BlockingReadRegister(Register::ZLow);
  status = BlockingReadRegister(Register::ZHigh);
  status = BlockingReadRegister(Register::BiasCurrentTrimming);
  status = BlockingReadRegister(Register::EnableTrimming);
  status = BlockingReadRegister(Register::AbzConfig1);
  status = BlockingReadRegister(Register::AbzConfig2);
  status = BlockingReadRegister(Register::MagFieldThreshold);
  status = BlockingReadRegister(Register::RotationDirection);
  status = BlockingReadRegister(Register::MagFieldStatus);
  status = 0;
#pragma GCC diagnostic pop
}

uint16_t Ma702::BlockingReadRegister(Register reg) {
  uint16_t value = 0;
// TODO(blakely): Correct this
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
  uint16_t outbound = kReadRegister | (static_cast<uint16_t>(reg) << 8);
#pragma GCC diagnostic pop
  // First read's resposne is the angle...
  spi_->BlockingTransfer(outbound, &value);
  // Second read's resposne is the resulting register value.
  outbound = 0;
  spi_->BlockingTransfer(outbound, &value);
  value = value >> 8U;

  return value;
}

uint16_t Ma702::Update() {
  constexpr static uint16_t command = 0;
  spi_->BlockingTransfer(command, &angle_);
  return angle_;
}

void Ma702::AutoPoll(Dma::Stream& command_stream, Dma::Stream& angle_stream) {
  command_stream.Configure(Dma::Mode::Circular, Dma::Increment::No,
                           Dma::Increment::No, Dma::TransferSize::Word);
  angle_stream.Configure(Dma::Mode::Circular, Dma::Increment::No,
                         Dma::Increment::No, Dma::TransferSize::Word);

  spi_->StreamingTransfer(command_stream, angle_stream, &kReadAngle, &angle_,
                          1);
}

}  // namespace ma702
}  // namespace platform