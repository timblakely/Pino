#include "bldc/firmware/platform/stm32g4/peripherals/can.h"

#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"

namespace platform {
namespace stm32g4 {

Can::Can(Gpio::Pin tx, Gpio::Pin rx) : tx_(tx), rx_(rx) {}

void Can::Init(Can::Instance instance) {
  instance_ = instance;
  can_ = reinterpret_cast<Periph*>(instance_);
  // TODO(blakely): Assumes FDCAN1 on PA11/PA12 for RX/TX respectively.

  rx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF10);
  tx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF10);

  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_FDCAN);

  // TODO(blakely): Set SynSeg, BS1, and BS2
  // Baud = 1 / bit_time = t_ss + t_bs1 + t_bs2
  // Controlled by FDCAN_NBTP.NBRP, FDCAN_NBTP.NTSEG1, and FDCAN_NBTP.NTSEG2

  // TODO(blakely): Do we need to read FDCAN_ENDN?

  // Init and control configuration.
  {
    using CCCR = Can::Periph::CCCR_value_t;
    // TODO(blakely): Is this staged start necessary, or can we write CCCR INT,
    // CCE, and other bits all at once?
    // First, Update CCCR to enter init mode.
    can_->update_CCCR([](CCCR v) { return v.with_INIT(CCCR::INIT_t::init); });

    // Wait for ACK to init mode, in case we're already transmitting.
    while (can_->read_CCCR().get_INIT() == CCCR::INIT_t::run) {
    }

    // Next, enable configuration readwrite.
    can_->update_CCCR(
        [](CCCR v) { return v.with_CCE(CCCR::CCE_t::readwrite); });

    // Now set the various CCCR fields.
    can_->update_CCCR([](CCCR v) {
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

  // Configure bit timing.
  {
    using NBTP = Can::Periph::NBTP_value_t;
    can_->update_NBTP([](NBTP v) {
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

  // TODO(blakely): Set DBTP. 8.01MBit is 2/2/2

  // Configure for TxFIFO usage
  {
    using TXBC = Can::Periph::TXBC_value_t;
    can_->update_TXBC([](TXBC v) { return v.with_TFQM(TXBC::TFQM_t::fifo); });
  }

  // Set clock divider
  {
    using CKDIV = Can::Periph::CKDIV_value_t;
    can_->update_CKDIV(
        [](CKDIV v) { return v.with_PDIV(CKDIV::PDIV_t::div1); });
  }

  // TODO(blakely): Configure this though an enum to Init()
  // Disable loopback mode
  {
    using CCCR = Can::Periph::CCCR_value_t;
    using TEST = Can::Periph::TEST_value_t;
    // Enable access to TEST register.
    can_->update_CCCR([](CCCR v) { return v.with_TEST(CCCR::TEST_t::test); });
    can_->update_TEST(
        [](TEST v) { return v.with_LBCK(0).with_TX(TEST::TX_t::can_core); });
    // Disable access to TEST register.
    can_->update_CCCR([](CCCR v) { return v.with_TEST(CCCR::TEST_t::normal); });
  }

  int i = 0;

  ++i;
}

}  // namespace stm32g4
}  // namespace platform