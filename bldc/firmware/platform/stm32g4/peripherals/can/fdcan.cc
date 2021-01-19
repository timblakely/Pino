#include "bldc/firmware/platform/stm32g4/peripherals/can/fdcan.h"

namespace platform {
namespace stm32g4 {
namespace impl {

void Fdcan::InitMode() {
  // Enter init mode.
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::init); });
  // Wait for ACK to init mode, in case we're already transmitting.
  while (read_CCCR().get_INIT() == CCCR::INIT_t::run) {
  }
  // Enable config writing
  update_CCCR([](CCCR v) { return v.with_CCE(CCCR::CCE_t::readwrite); });
}

void Fdcan::Initialize() {
  update_CCCR([](CCCR v) {
    return v
        // Enable Tx pause
        .with_TXP(0)
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

void Fdcan::SetBitTiming() {
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

void Fdcan::EnableQueueMode() {
  update_TXBC([](TXBC v) { return v.with_TFQM(TXBC::TFQM_t::fifo); });
}

void Fdcan::SetClockDivider() {
  update_CKDIV([](CKDIV v) { return v.with_PDIV(CKDIV::PDIV_t::div1); });
}

void Fdcan::EnableLoopbackMode() {
  update_CCCR([](CCCR v) {
    return v.with_TEST(CCCR::TEST_t::test)
        .with_MON(0)
        .with_ASM(CCCR::ASM_t::normal);
  });
  update_TEST([](TEST v) { return v.with_LBCK(1); });
}

void Fdcan::Start() {
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::run); });
}

uint8_t Fdcan::TxPut() { return read_TXFQS().get_TFQPI(); }

uint8_t Fdcan::TxGet() { return read_TXFQS().get_TFGI(); }

void Fdcan::TransmitBuffer(uint8_t idx) {
  update_TXBAR([&idx](TXBAR v) { return v.with_AR(1 << idx); });
}

}  // namespace impl
}  // namespace stm32g4
}  // namespace platform