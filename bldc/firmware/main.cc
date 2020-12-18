#include "bldc/firmware/platform/bldc_platform.h"

using platform::BldcPlatform;

int main() {
  auto* platform = BldcPlatform::Instance();
  platform->Startup();

  while (true) {
    asm("nop");
    // platform->BlockingWait(1e6);
    // platform->Fatal();
  }
}