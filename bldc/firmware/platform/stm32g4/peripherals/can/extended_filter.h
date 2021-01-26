#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_EXTENDED_FILTER_MEMORY_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_EXTENDED_FILTER_MEMORY_H_

namespace platform {
namespace stm32g4 {

template <bool FDFrame, uint32_t Id, uint8_t FrameSizeBytes>
struct FrameHeader;

namespace can {
struct ExtendedFilter {
  ExtendedFilter() = delete;
  ExtendedFilter(ExtendedFilter&) = delete;
  ExtendedFilter(ExtendedFilter&&) = delete;
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/extended_filter_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  using F0 = F0_value_t;
  using F1 = F1_value_t;

  // template <bool FDFrame, uint32_t Id, uint8_t FrameSizeBytes>
  // void SetFilter(FrameHeader<FDFrame, Id, FrameSizeBytes>& header) {
  template <typename FrameHeader>
  void SetFilter() {
    update_F0([](F0 v) {
      return v.with_EFEC(F0::EFEC_t::store_fifo0).with_EFID1(FrameHeader::Id);
    });
    update_F1([](F1 v) {
      return v.with_EFT(F1::EFT_t::classic_with_mask).with_EFID2(0xFFF'FFFF);
    });
  }
};

}  // namespace can

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_EXTENDED_FILTER_MEMORY_H_
