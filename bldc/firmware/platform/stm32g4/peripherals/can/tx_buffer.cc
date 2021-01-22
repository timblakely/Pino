#include "bldc/firmware/platform/stm32g4/peripherals/can/tx_buffer.h"

namespace platform {
namespace stm32g4 {
namespace impl {


void TxBuffer::CopyData(uint8_t* data, uint8_t size) {
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