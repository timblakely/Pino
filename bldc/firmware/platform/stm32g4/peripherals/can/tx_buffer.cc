#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"

namespace platform {
namespace stm32g4 {
namespace impl {

using FrameSize = TxBuffer::FrameSize;

uint8_t FrameSizeBytes(TxBuffer::FrameSize size) {
  switch (size) {
    case FrameSize::fdcan0:
    case FrameSize::fdcan1:
    case FrameSize::fdcan2:
    case FrameSize::fdcan3:
    case FrameSize::fdcan4:
    case FrameSize::fdcan5:
    case FrameSize::fdcan6:
    case FrameSize::fdcan7:
    case FrameSize::fdcan8:
      return static_cast<uint8_t>(size);
    case FrameSize::fdcan12:
      return 12;
    case FrameSize::fdcan16:
      return 16;
    case FrameSize::fdcan20:
      return 20;
    case FrameSize::fdcan24:
      return 24;
    case FrameSize::fdcan32:
      return 32;
    case FrameSize::fdcan48:
      return 48;
    case FrameSize::fdcan64:
    default:
      return 64;
  };
}

void TxBuffer::DataFrame(uint8_t id, uint8_t* data, FrameSize frame_size) {
  update_T0([&id](T0 v) {
    return v
        // ESI only on error active
        .with_ESI(0)
        // Standard
        .with_XTD(0)
        // Data frame
        .with_RTR(0)
        // Set message ID
        .with_SID(id);
  });

  update_T1([&frame_size](T1 v) {
    return v
        // Set message marker
        .with_MM(123)
        // Store tx events
        .with_EFC(1)
        // Transmit as FD
        .with_FDF(1)
        // Don't use bitrate switching
        .with_BRS(0)
        // Data length code
        .with_DLC(frame_size);
  });

  const uint8_t size = FrameSizeBytes(frame_size);
  const uint8_t words = size / sizeof(uint32_t);
  uint32_t* src = reinterpret_cast<uint32_t*>(data);
  uint32_t* dest = data_;
  const uint32_t* fence = dest + words;
  while (dest != fence) {
    *dest = *src;
    ++dest;
    ++src;
  }
  const uint8_t remainder = size - words * 4;
  const uint8_t* remainder_src = reinterpret_cast<uint8_t*>(src);
  if (remainder == 1) {
    *dest = 0xFFU & remainder_src[0];
  } else if (remainder == 2) {
    *dest = 0xFFFFU & (remainder_src[1] << 8 | remainder_src[0]);
  } else if (remainder == 3) {
    *dest = 0xFFFFFFU &
            (remainder_src[2] << 16 | remainder_src[1] << 8 | remainder_src[0]);
  }
}

}  // namespace impl
}  // namespace stm32g4
}  // namespace platform