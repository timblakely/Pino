#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
#include "bldc/firmware/platform/bldc_platform.h"

namespace platform {
namespace stm32g4 {

class G4Platform : public BldcPlatform {
 public:
  G4Platform();
  void Startup() override;
  void Fatal() override;
  virtual void Init() = 0;
  void BlockingWait(uint32_t micros) override;

 protected:
  virtual void SetupClocks();
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_G4_PLATFORM_H_
