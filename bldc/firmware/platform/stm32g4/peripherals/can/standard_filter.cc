#include "bldc/firmware/platform/stm32g4/peripherals/can/standard_filter.h"

namespace platform {
namespace stm32g4 {
namespace impl {

void StandardFilter::SetFilter(FilterType type, Action action, uint8_t id1,
                               uint8_t id2) {
  update_FLSSA([&](FLSSA v) {
    return v.with_SFT(type).with_SFEC(action).with_SFID1(id1).with_SFID2(id2);
  });
}

}  // namespace impl
}  // namespace stm32g4
}  // namespace platform