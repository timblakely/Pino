#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
#include "bldc/firmware/platform/bldc_platform.h"

namespace platform {
namespace stm32g4 {

class G4Platform : BldcPlatform {
 public:
  void Startup() override;
  void Fatal() override;

 protected:
  virtual BldcPlatform* CreateInstance();
  virtual void SetupClocks() = 0;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
