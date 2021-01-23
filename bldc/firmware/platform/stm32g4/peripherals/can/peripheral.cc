#include "bldc/firmware/platform/stm32g4/peripherals/can/peripheral.h"

namespace platform {
namespace stm32g4 {
namespace can {

void Peripheral::InitMode() {
  // Enter init mode.
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::init); });
  // Wait for ACK to init mode, in case we're already transmitting.
  while (read_CCCR().get_INIT() == CCCR::INIT_t::run) {
  }
  // Enable config writing
  update_CCCR([](CCCR v) { return v.with_CCE(CCCR::CCE_t::readwrite); });
}

void Peripheral::Initialize() {
  update_CCCR([](CCCR v) {
    return v
        // Enable Tx pause
        .with_TXP(0)
        // No edge filtering
        .with_EFBI(0)
        // Protocol exception handling disalbed
        .with_PXHD(0)
        // Enable bit rate switching
        .with_BRSE(1)
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

void Peripheral::SetBitTiming() {
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

    return v.with_NBRP(4)
        .with_NTSEG1(21)
        .with_NTSEG2(10)
        // Jump width of 4
        .with_NSJW(5);
  });

  update_DBTP([](DBTP v) {
    // TODO(blakely): Pull actual clock source and freq from RCC. This
    // assumes PCLK1@170MHz, aiming for 1MBit

    // DBRP = 1
    // DTSEG1 = 4
    // DTSEG2 = 3
    // DSJW = 2

    // tq = (DBRP + 1) * t_fdcan_clk = (1 + 1) * 5.88235ns = 11.67ns
    // t_syncseg = 1 * tq = 11.67ns
    // bs1 = tq * (DTSEG1 + 1) = 11.67ns * (4 + 1) = 58.82 ns
    // bs2 = tq * (DTSEG2 + 1) = 11.67ns * (3 + 1) = 47.06 ns
    // Bit time = 11.67 + 58.82 + 47.06 = 117.65 ns
    // Baud = 1e9 / (117.65) = 8.5 MBit

    // return v.with_DBRP(1).with_DTSEG1(4).with_DTSEG2(3).with_DSJW(2);
    return v.with_DBRP(0).with_DTSEG1(21).with_DTSEG2(10).with_DSJW(10);
  });
}

void Peripheral::EnableQueueMode() {
  update_TXBC([](TXBC v) { return v.with_TFQM(TXBC::TFQM_t::fifo); });
}

void Peripheral::SetClockDivider() {
  update_CKDIV([](CKDIV v) { return v.with_PDIV(CKDIV::PDIV_t::div1); });
}

void Peripheral::EnableLoopbackMode() {
  update_CCCR([](CCCR v) {
    return v.with_TEST(CCCR::TEST_t::test)
        .with_MON(0)
        .with_ASM(CCCR::ASM_t::normal);
  });
  update_TEST([](TEST v) { return v.with_LBCK(1); });
}

void Peripheral::Start() {
  update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::run); });
}

uint8_t Peripheral::TxPut() { return read_TXFQS().get_TFQPI(); }

uint8_t Peripheral::TxGet() { return read_TXFQS().get_TFGI(); }

void Peripheral::TransmitBuffer(uint8_t idx) {
  update_TXBAR([&idx](TXBAR v) { return v.with_AR(1 << idx); });
}

}  // namespace can
}  // namespace stm32g4
}  // namespace platform