#include "bldc/firmware/platform/bldc_platform.h"

using platform::BldcPlatform;

int main() {
  auto* platform = BldcPlatform::Instance();
  platform->Startup();

  uint32_t i = 0;
  while (true) {
    ++i;
    asm("nop");
    // platform->BlockingWait(1e6);
    // platform->Fatal();
  }
}