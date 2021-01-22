#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_BASE_FRAME_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_BASE_FRAME_H_

#include <array>

#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"

namespace platform {
namespace stm32g4 {
namespace impl {

template <bool IsFD, uint32_t Id, uint8_t FrameSizeBytes>
struct FrameHeader : public TxHeader {
  FrameHeader() = delete;
  FrameHeader(FrameHeader&) = delete;

  template <bool BitrateSwitching, bool StoreTxEvent>
  inline void Apply(uint8_t message_marker) {
    update_T0([](T0 v) {
      return v.with_ESI(0).with_XTD(IsFD).with_RTR(0).with_ID(ID());
    });
    update_T1([&](T1 v) {
      return v.with_MM(message_marker)
          .with_EFC(StoreTxEvent)
          .with_FDF(IsFD)
          .with_BRS(BitrateSwitching)
          .with_DLC(DataLength());
    });
  }

 private:
  constexpr static std::array<uint8_t, 16> fd_frame_sizes_ = {
      0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

  static constexpr uint32_t ID() {
    if (IsFD) {
      return Id;
    } else {
      return Id << 18;
    }
  }

  static constexpr bool ValidFrameSize() {
    for (const auto& v : fd_frame_sizes_) {
      if (FrameSizeBytes == v) {
        return true;
      }
    }
    return false;
  }

  static constexpr FrameSize FDDataLength() {
    static_assert(ValidFrameSize());

    if (FrameSizeBytes <= 8) {
      return static_cast<FrameSize>(FrameSizeBytes);
    }
    switch (FrameSizeBytes) {
      case 12:
        return FrameSize::fdcan12;
      case 16:
        return FrameSize::fdcan16;
      case 20:
        return FrameSize::fdcan20;
      case 24:
        return FrameSize::fdcan24;
      case 32:
        return FrameSize::fdcan32;
      case 64:
        return FrameSize::fdcan64;
      default:
        return FrameSize::fdcan0;
    }
  }

  static constexpr FrameSize StdDataLength() {
    static_assert(FrameSizeBytes <= 8);
    return static_cast<FrameSize>(FrameSizeBytes);
  }

  static constexpr FrameSize DataLength() {
    if (IsFD) {
      return FDDataLength();
    } else {
      return StdDataLength();
    }
  }
};  // namespace impl

}  // namespace impl
}  // namespace stm32g4
}  // namespace platform
#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_BASE_FRAME_H_
