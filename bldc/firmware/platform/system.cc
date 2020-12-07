#include "bldc/firmware/platform/system.h"

extern "C" {
// Dummy so we don't have to modify the startup script.
void SystemInit(void) {}
}

namespace bldc {
namespace firmware {
namespace platform {}
}  // namespace firmware
}  // namespace bldc