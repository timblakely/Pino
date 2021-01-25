#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"

namespace platform {
namespace stm32g4 {

struct DebugFrame : public FDFrame<3> {
  using Header = FDFrame::Header<0xD>;

  DebugFrame() {
    data_[0] = 0x0;
    data_[1] = 0x13;
    data_[2] = 0x0;
  };
};

struct AngleFrame : public FDFrame<2> {
  using Header = FDFrame::Header<0xA>;

  AngleFrame(uint16_t angle) { *reinterpret_cast<uint16_t*>(data_) = angle; }
};

struct SimpleReceiveFrame : public FDFrame<2> {
  using Header = FDFrame::Header<0x10>;

  SimpleReceiveFrame() = delete;
  SimpleReceiveFrame(SimpleReceiveFrame&) = delete;
  SimpleReceiveFrame(SimpleReceiveFrame&&) = delete;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
