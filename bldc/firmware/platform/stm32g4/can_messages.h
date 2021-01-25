#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"

namespace platform {
namespace stm32g4 {

struct DebugFrame : public FDFrame {
  using Header = FDFrame::Header<0xD, 3>;

  virtual void Pack(uint32_t* buffer) override {
    buffer[0] = 0x0 << 16 | 0x13 << 8 | 0x0;
  };
};

struct AngleFrame : public FDFrame {
  using Header = FDFrame::Header<0xA, 2>;

  AngleFrame(uint16_t angle) : angle_(angle) {}

  virtual void Pack(uint32_t* buffer) override { buffer[0] = angle_; };

 private:
  uint16_t angle_;
};

struct SimpleReceiveFrame : public FDFrame {
  using Header = FDFrame::Header<0x10, 2>;

  SimpleReceiveFrame() = delete;
  SimpleReceiveFrame(SimpleReceiveFrame&) = delete;
  SimpleReceiveFrame(SimpleReceiveFrame&&) = delete;
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
