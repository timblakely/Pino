#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_

#include <array>

#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"

namespace platform {
namespace stm32g4 {

template <bool FDFrame, uint32_t MessageId, uint8_t FrameSizeBytes>
struct FrameHeader : public can::TxHeader {
  static constexpr auto Id = MessageId;
  static constexpr auto IsFD = FDFrame;

  FrameHeader() = delete;
  FrameHeader(FrameHeader&) = delete;
  FrameHeader(FrameHeader&&) = delete;

  template <bool BitrateSwitching, bool StoreTxEvent>
  inline void Apply(uint8_t message_marker) {
    update_T0([](T0 v) {
      return v.with_ESI(0).with_XTD(IsFD).with_RTR(0).with_ID(MsgId());
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

  static constexpr uint32_t MsgId() {
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

struct BaseCanFrame {};

template <bool IsFd, uint32_t Id, uint8_t SizeBytes>
struct CanFrame : public BaseCanFrame {
  using Header = FrameHeader<IsFd, Id, SizeBytes>;

 protected:
  uint8_t data_[SizeBytes];

 private:
  void CopyToSRAM(uint32_t* buffer) {
    const uint8_t words = SizeBytes / sizeof(uint32_t);
    uint32_t* src = reinterpret_cast<uint32_t*>(data_);
    uint32_t* dest = buffer;
    const uint32_t* fence = dest + words;
    while (dest != fence) {
      *dest = *src;
      ++dest;
      ++src;
    }
    const uint8_t remainder = SizeBytes - words * 4;
    const uint8_t* remainder_src = reinterpret_cast<uint8_t*>(src);
    if (remainder == 1) {
      *dest = 0xFFU & remainder_src[0];
    } else if (remainder == 2) {
      *dest = 0xFFFFU & (remainder_src[1] << 8 | remainder_src[0]);
    } else if (remainder == 3) {
      *dest = 0xFFFFFFU & (remainder_src[2] << 16 | remainder_src[1] << 8 |
                           remainder_src[0]);
    }
  }

  void CopyFromSRAM(uint32_t* buffer) {
    auto src = reinterpret_cast<uint8_t*>(buffer);
    auto dest = data_;
    uint8_t remaining = SizeBytes;
    while (remaining > 0) {
      *dest = *src;
      dest++;
      src++;
      --remaining;
    }
  }

  friend class Can;
};  // namespace stm32g4

template <uint8_t Id, uint8_t Size>
struct StandardFrame : public CanFrame<false, Id, Size> {};

template <uint32_t Id, uint8_t Size>
struct FDFrame : public CanFrame<true, Id, Size> {};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_FRAME_TYPES_H_
