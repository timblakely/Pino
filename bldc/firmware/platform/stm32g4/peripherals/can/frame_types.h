#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/base_frame.h"

namespace platform {
namespace stm32g4 {

template <uint32_t Id, uint8_t FrameSizeBytes>
using FDFrameHeader = impl::FrameHeader<true, Id, FrameSizeBytes>;

using TestFrame = FDFrameHeader<0xD, 3>;

struct CanFrame {
  virtual void Pack(uint32_t* buffer) = 0;
};

template <typename Header>
struct FDFrame : public CanFrame {
  using HeaderType = Header;
};

struct HardcodedFrame : FDFrame<TestFrame> {
  virtual void Pack(uint32_t* buffer) override {
    buffer[0] = 0x0 << 16 | 0x13 << 8 | 0x0;
  };
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
