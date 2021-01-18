#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_

namespace platform {
namespace stm32g4 {

namespace impl {

struct StandardFilter {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/standard_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

 private:
  using FLSSA = FLSSA_value_t;

 public:
  using FilterType = FLSSA::SFT_t;
  using Action = FLSSA::SFEC_t;

  void SetFilter(FilterType type, Action action, uint8_t id1, uint8_t id2);
};

}  // namespace impl

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_
