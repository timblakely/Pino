#include "bldc/firmware/platform/bldc_platform.h"

using platform::BldcPlatform;

extern uint32_t kSpiReceive;

int main() {
  auto* platform = BldcPlatform::Instance();
  platform->Startup();

  // uint32_t angle = 0;

  while (true) {
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    // angle = platform->Angle();
    // platform->BlockingWait(1e6);
    // platform->Fatal();
  }
}