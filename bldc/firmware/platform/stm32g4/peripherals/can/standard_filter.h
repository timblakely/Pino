#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_

namespace platform {
namespace stm32g4 {

template <bool FDFrame, uint32_t Id, uint8_t FrameSizeBytes>
struct FrameHeader;

namespace can {

struct StandardFilter {
  StandardFilter() = delete;
  StandardFilter(StandardFilter&) = delete;
  StandardFilter(StandardFilter&&) = delete;
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/standard_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

  using FLSSA = FLSSA_value_t;

  // TODO(blakely): templatize for CONSTEXPR evalulation
  // void SetFilter(FilterType type, Action action, uint8_t id1, uint8_t id2);
  template <typename FrameHeader>
  void SetFilter() {
    update_FLSSA([&](FLSSA v) {
      return v.with_SFT(FLSSA::SFT_t::classic_with_mask)
          .with_SFEC(FLSSA::SFEC_t::priority_store_fifo0)
          .with_SFID1(FrameHeader::Id)
          .with_SFID2(0x3FF);
    });
  }
};

}  // namespace can

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_STANDARD_FILTER_H_
