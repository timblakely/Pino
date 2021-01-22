#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_

#include <array>

namespace platform {
namespace stm32g4 {

namespace impl {

struct TxBuffer {
#define ETL_BFF_DEFINITION_FILE \
  "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE

 protected:
  using T0 = T0_value_t;
  using T1 = T1_value_t;
  using FrameSize = T1::DLC_t;

  uint32_t data_[16];
  void CopyData(uint8_t* data, uint8_t size);
};

template <bool IsFD, uint32_t Id, uint8_t FrameSizeBytes, uint8_t MessageMarker,
          bool StoreTxEvent, bool BitrateSwitching>
struct BaseCanFrame : public TxBuffer {
  BaseCanFrame() = delete;
  BaseCanFrame(BaseCanFrame&) = delete;

  inline void Build(uint8_t* data) {
    update_T0([](T0 v) {
      // TODO(blakely): Templatize
      return v.with_ESI(0).with_XTD(IsFD).with_RTR(0).with_ID(ID());
    });
    update_T1([](T1 v) {
      return v.with_MM(MessageMarker)
          .with_EFC(StoreTxEvent)
          .with_FDF(IsFD)
          .with_BRS(BitrateSwitching)
          .with_DLC(DataLength());
    });
    CopyData(data, FrameSizeBytes);
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
};

}  // namespace impl

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_TX_BUFFER_MEMORY_H_
