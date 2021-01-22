#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_

#include "bldc/firmware/platform/stm32g4/peripherals/can/base_frame.h"

namespace platform {
namespace stm32g4 {

using TestFrame = impl::FrameHeader<true, 0xD, 3, 123, true, true>;

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
