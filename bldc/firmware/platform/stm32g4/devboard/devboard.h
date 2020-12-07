#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_CUSTOM_V1_CUSTOM_V1_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_CUSTOM_V1_CUSTOM_V1_H_

#include "bldc/firmware/platform/stm32g4/g4_platform.h"

namespace platform {
namespace stm32g4 {

class CustomV1Platform : G4Platform {
 public:
  CustomV1Platform();
};

}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_CUSTOM_V1_CUSTOM_V1_H_
