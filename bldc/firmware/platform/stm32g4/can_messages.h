#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/frame.h"

namespace platform {
namespace stm32g4 {

struct DebugFrame : public FDFrame<0xD, 3> {
  DebugFrame() {
    data_[0] = 0x0;
    data_[1] = 0x13;
    data_[2] = 0x0;
  };
};

struct AngleFrame : public FDFrame<0xA, 2> {
  AngleFrame(uint16_t angle) { *reinterpret_cast<uint16_t*>(data_) = angle; }
};

struct SimpleReceiveFrame : public FDFrame<0x10, 2> {
  uint8_t foo() { return data_[0]; };
  uint8_t bar() { return data_[1]; };
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_CAN_MESSAGES_H_
