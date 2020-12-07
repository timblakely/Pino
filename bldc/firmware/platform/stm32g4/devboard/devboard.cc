#include "bldc/firmware/platform/stm32g4/custom_v1/custom_v1.h"

#include "bldc/firmware/platform/bldc_platform.h"

namespace platform {
namespace stm32g4 {

void CustomV1Platform::CustomV1Platform() {}

BldcPlatform* BldcPlatform::Create() {
  static CustomV1Platform kPlatform;
  return &kPlatform;
}

}  // namespace stm32g4
}  // namespace platform