#include "bldc/firmware/platform/stm32g4/peripherals/can.h"

#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"

namespace platform {
namespace stm32g4 {

using registers::CCCR;

Can::Can(Gpio::Pin tx, Gpio::Pin rx) : tx_(tx), rx_(rx) {}

void Can::Init(Can::Instance instance) {
  can_ = reinterpret_cast<CanInstance*>(instance);
  // TODO(blakely): Assumes FDCAN1 on PA11/PA12 for RX/TX respectively.

  rx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF10);
  tx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None,
                Gpio::AlternateFunction::AF10);

  // rx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  // rx_.High();
  // tx_.Configure(Gpio::OutputMode::PushPull, Gpio::Pullup::None);
  // tx_.High();

  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_FDCAN);

  // TODO(blakely): Set SynSeg, BS1, and BS2
  // Baud = 1 / bit_time = t_ss + t_bs1 + t_bs2
  // Controlled by FDCAN_NBTP.NBRP, FDCAN_NBTP.NTSEG1, and FDCAN_NBTP.NTSEG2

  // TODO(blakely): Do we need to read FDCAN_ENDN?

  // First, make sure we're in init mode.
  can_->CCCR.INIT = CCCR::InitMode::Enabled;

  // Then enable configuration.
  can_->CCCR.CCE = CCCR::ConfigMode::ReadWrite;

  // Enable retransmission on error.
  // can_->CCCR.DAR = CCCR::AutomaticRetransmission::Enabled;
  // *((uint32_t*)(0x40006418)) = 0b1000011;
  // *((uint32_t*)(&can_->CCCR)) = 0b1000011;
  // *((uint32_t*)(&can_->CCCR)) &= (0b11111111111111111111111110111111U);
  can_->CCCR.DAR = true;

  // Pause between transmissions.
  can_->CCCR.TXP = CCCR::TransmitPause::Enabled;

  // Exception handling.
  can_->CCCR.PXHD = CCCR::ProtocolExceptionHandling::Disabled;

  // TODO(blakely): Enable bit rate switching

  // Normal, non-test mode. Would normally set CCCR.(TEST|MON|ASM) here for
  // debugging and monitoring. Would also set TEST.LBCK if loopback is
  // necessary.

  // Enable FD operation
  can_->CCCR.FDOE = CCCR::FDMode::Enabled;

  // Configure bit timing.
  // TODO(blakely): Pull actual clock source and freq from RCC. This assumes
  // PCLK1@170MHz, aiming for 1MBit
  // tq = (NBRP + 1) * t_fdcan_clk = (6 + 1) * 5.88235ns = 41.176ns
  // t_syncseg = 1 * tq = 41.176ns
  // bs1 = tq * (NTSEG1 + 1) = 41.176ns * (11 + 1) = 494.41 ns
  // bs2 = tq * (NTSEG2 + 1) = 41.176ns * (10 + 1) = 452.94 ns
  // Bit speed = 1e9 / (41.176+494.41+452.94) = 1.0116 MBit
  can_->NBTP.NBRP = 6;
  can_->NBTP.NTSEG1 = 11;
  can_->NBTP.NTSEG2 = 10;
  // Setting jump width to 4 because it's the maximum available to standard CAN.
  can_->NBTP.NSJW = 4;

  // TODO(blakely): Set DBTP. 8.01MBit is 2/2/2

  can_->CCCR.INIT = CCCR::InitMode::Disabled;
  while (can_->CCCR.INIT == CCCR::InitMode::Enabled) {
    asm("nop");
  }
}

}  // namespace stm32g4
}  // namespace platform