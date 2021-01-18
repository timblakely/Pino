#include "bldc/firmware/platform/stm32g4/peripherals/can.h"

#include <cstring>

#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"

namespace platform {
namespace stm32g4 {

namespace can {

// Ensure memory addresses are at expected locations.
static_assert(sizeof(Periph) == 0x104);
static_assert(sizeof(StandardFilter) == 1 * 4);
static constexpr uint32_t kStandardFilterMemOffset = 0x0;
static_assert(kStandardFilterMemOffset == 0x0000);
static_assert(sizeof(ExtendedFilter) == 2 * 4);
static constexpr uint32_t kExtendedFilterMemOffset =
    kStandardFilterMemOffset + sizeof(StandardFilter) * 28;
static_assert(kExtendedFilterMemOffset == 0x0070);
static_assert(sizeof(RxBuffer) == 18 * 4);
static constexpr uint32_t kRxFIFO0MemOffset =
    kExtendedFilterMemOffset + sizeof(ExtendedFilter) * 8;
static_assert(kRxFIFO0MemOffset == 0x00B0);
static constexpr uint32_t kRxFIFO1MemOffset =
    kRxFIFO0MemOffset + sizeof(RxBuffer) * 3;
static_assert(kRxFIFO1MemOffset == 0x0188);
static_assert(sizeof(TxEvent) == 2 * 4);
static constexpr uint32_t kTxEventFifoMemOffset =
    kRxFIFO1MemOffset + sizeof(RxBuffer) * 3;
static_assert(kTxEventFifoMemOffset == 0x0260);
static_assert(sizeof(TxBuffer) == 18 * 4);
static constexpr uint32_t kTxBufferMemOffset =
    kTxEventFifoMemOffset + sizeof(TxEvent) * 3;
static_assert(kTxBufferMemOffset == 0x0278);

// Final memory accounting
static_assert(kMRAMBankSize ==
              (sizeof(StandardFilter) * 28 + sizeof(ExtendedFilter) * 8 +
               sizeof(RxBuffer) * 3 + sizeof(RxBuffer) * 3 +
               sizeof(TxEvent) * 3 + sizeof(TxBuffer) * 3));

// Implementation

void Periph::InitMode() {
  // Enter init mode.
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::init); });
  // Wait for ACK to init mode, in case we're already transmitting.
  while (read_CCCR().get_INIT() == CCCR::INIT_t::run) {
  }
  // Enable config writing
  update_CCCR([](CCCR v) { return v.with_CCE(CCCR::CCE_t::readwrite); });
}

void Periph::Initialize() {
  update_CCCR([](CCCR v) {
    return v
        // Enable Tx pause
        .with_TXP(1)
        // No edge filtering
        .with_EFBI(0)
        // Protocol exception handling disalbed
        .with_PXHD(0)
        // TODO(blakely): Enable bit rate switching eventually.
        // No bit rate switching
        .with_BRSE(0)
        // Enable FDCAN mode
        .with_FDOE(1)
        // No test mode
        .with_TEST(CCCR::TEST_t::normal)
        // Enable automatic retransmission
        .with_DAR(CCCR::DAR_t::retransmit)
        // No bus monitoring
        .with_MON(0)
        // No restricted mode
        .with_ASM(CCCR::ASM_t::normal)
        // Make sure we're not in sleep mode.
        .with_CSR(0);
  });
}

void Periph::SetBitTiming() {
  update_NBTP([](NBTP v) {
    // TODO(blakely): Pull actual clock source and freq from RCC. This
    // assumes PCLK1@170MHz, aiming for 1MBit

    // NBRP = 6
    // NTSEG1 = 11
    // NTSEG2 = 10
    // NSJW = 4

    // tq = (NBRP + 1) * t_fdcan_clk = (6 + 1) * 5.88235ns = 41.176ns
    // t_syncseg = 1 * tq = 41.176ns
    // bs1 = tq * (NTSEG1 + 1) = 41.176ns * (11 + 1) = 494.41 ns
    // bs2 = tq * (NTSEG2 + 1) = 41.176ns * (10 + 1) = 452.94 ns
    // Bit time = 41.176 + 494.41 + 452.94 = 988.235 ns
    // Baud = 1e9 / (988.235) = 1.0116 MBit

    return v.with_NBRP(6)
        .with_NTSEG1(11)
        .with_NTSEG2(10)
        // Jump width of 4
        .with_NSJW(4);
  });
}

void Periph::EnableQueueMode() {
  update_TXBC([](TXBC v) { return v.with_TFQM(TXBC::TFQM_t::fifo); });
}

void Periph::SetClockDivider() {
  update_CKDIV([](CKDIV v) { return v.with_PDIV(CKDIV::PDIV_t::div1); });
}

void Periph::EnableLoopbackMode() {
  update_CCCR([](CCCR v) {
    return v.with_TEST(CCCR::TEST_t::test)
        .with_MON(0)
        .with_ASM(CCCR::ASM_t::normal);
  });
  update_TEST([](TEST v) { return v.with_LBCK(1); });
}

void Periph::Start() {
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::run); });
}

uint8_t Periph::TxPut() { return read_TXFQS().get_TFQPI(); }

uint8_t Periph::TxGet() { return read_TXFQS().get_TFGI(); }

}  // namespace can

using can::ExtendedFilter;
using can::kExtendedFilterMemOffset;
using can::kMRAMAddress;
using can::kMRAMBankSize;
using can::kRxFIFO0MemOffset;
using can::kRxFIFO1MemOffset;
using can::kTxBufferMemOffset;
using can::kTxEventFifoMemOffset;
using can::Periph;
using can::RxBuffer;
using can::StandardFilter;
using can::TxBuffer;
using can::TxEvent;

Can::Can(Gpio::Pin tx, Gpio::Pin rx) : tx_(tx), rx_(rx) {}

void Can::Init(Can::Instance instance) {
  instance_ = instance;
  can_ = reinterpret_cast<can::Periph*>(instance);
  switch (instance) {
    case Instance::Fdcan1:
      standard_filters_ = reinterpret_cast<StandardFilter*>(kMRAMAddress);
      break;
    case Instance::Fdcan2:
      standard_filters_ =
          reinterpret_cast<StandardFilter*>(kMRAMAddress + kMRAMBankSize);
      break;
    case Instance::Fdcan3:
      standard_filters_ =
          reinterpret_cast<StandardFilter*>(kMRAMAddress + kMRAMBankSize * 2);
      break;
  }
  uint8_t* base_addr = reinterpret_cast<uint8_t*>(standard_filters_);
  extended_filters_ =
      reinterpret_cast<ExtendedFilter*>(base_addr + kExtendedFilterMemOffset);
  rx_fifo0_ = reinterpret_cast<RxBuffer*>(base_addr + kRxFIFO0MemOffset);
  rx_fifo1_ = reinterpret_cast<RxBuffer*>(base_addr + kRxFIFO1MemOffset);
  tx_event_fifo_ =
      reinterpret_cast<TxEvent*>(base_addr + kTxEventFifoMemOffset);
  tx_buffer_ = reinterpret_cast<TxBuffer*>(base_addr + kTxBufferMemOffset);

  // TODO(blakely): Assumes FDCAN1 on PA11/PA12 for RX/TX respectively.

  rx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF9);
  tx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF9);

  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_FDCAN);

  // Zero out the memory. Note: Must be done *after* enabling the FDCAN clock!
  memset(reinterpret_cast<void*>(kMRAMAddress), 0, kMRAMBankSize * 3);

  // TODO(blakely): Set SynSeg, BS1, and BS2
  // Baud = 1 / bit_time = t_ss + t_bs1 + t_bs2
  // Controlled by FDCAN_NBTP.NBRP, FDCAN_NBTP.NTSEG1, and FDCAN_NBTP.NTSEG2

  // TODO(blakely): Do we need to read FDCAN_ENDN?

  // Init and control configuration.
  can_->InitMode();
  can_->Initialize();
  can_->SetBitTiming();
  can_->EnableQueueMode();
  can_->EnableLoopbackMode();
  // TODO(blakely): Set DBTP. 8.01MBit is 2/2/2
  can_->SetClockDivider();

  // TODO(blakely): Configure this though an enum to Init()

  // Set the first filter.
  {
    using FLSSA = can::StandardFilter::FLSSA_value_t;
    standard_filters_[0].update_FLSSA([](FLSSA v) {
      return v.with_SFT(FLSSA::SFT_t::dual_id)
          .with_SFEC(FLSSA::SFEC_t::store_fifo0)
          .with_SFID1(13)
          .with_SFID2(37);
    });
  }
  can_->Start();
}

void Can::TransmitData(uint8_t* data, uint8_t size) {
  const auto idx = can_->TxPut();
  auto buffer = &(tx_buffer_[idx]);

  {
    using T0 = can::TxBuffer::T0_value_t;
    buffer->update_T0([](T0 v) {
      return v
          // ESI only on error active
          .with_ESI(0)
          // Standard
          .with_XTD(0)
          // Data frame
          .with_RTR(0)
          // Set message ID
          .with_ID(13);
    });
  }

  {
    using T1 = can::TxBuffer::T1_value_t;
    buffer->update_T1([](T1 v) {
      return v
          // Set message marker
          .with_MM(123)
          // Store tx events
          .with_EFC(1)
          // Transmit as FD
          .with_FDF(1)
          // Don't use bitrate switching
          .with_BRS(0)
          // Data length code HACKHACKHACK
          .with_DLC(T1::DLC_t::can3);
    });
  }

  // Copy memory into buffer. MRAM is must be written in 32-bit chunks, so use
  // memcpy for most of it then manually copy the remainder.
  const uint8_t words = size / sizeof(uint32_t);
  uint32_t* src = reinterpret_cast<uint32_t*>(data);
  uint32_t* dest = buffer->data;
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

  // memcpy(reinterpret_cast<void*>(buffer->data), data, size);

  // Notify periphal of transmit request
  {
    using TXBAR = can::Periph::TXBAR_value_t;
    can_->update_TXBAR([&idx](TXBAR v) { return v.with_AR(1 << idx); });
  }
  int i = 0;
  ++i;
}

}  // namespace stm32g4
}  // namespace platform