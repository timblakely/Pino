#include "bldc/firmware/platform/stm32g4/peripherals/can.h"

#include "third_party/stm32cubeg4/stm32g4xx_ll_bus.h"

namespace platform {
namespace stm32g4 {

using registers::CCCR;

Can::Can(Can::Instance instance)
    : can_(reinterpret_cast<CanInstance*>(instance)) {}

void Can::Init() {
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_FDCAN);

  // TODO(blakely): Set SynSeg, BS1, and BS2
  // Baud = 1 / bit_time = t_ss + t_bs1 + t_bs2
  // Controlled by FDCAN_NBTP.NBRP, FDCAN_NBTP.NTSEG1, and FDCAN_NBTP.NTSEG2

  // TODO(blakely): Do we need to read FDCAN_ENDN?

  // First, make sure we're in init mode.
  can_->CCCR.INIT = CCCR::InitMode::Enabled;

  // Enable retransmission on error.
  can_->CCCR.DAR = CCCR::AutomaticRetransmission::Enabled;

  // Pause between transmissions.
  can_->CCCR.TXP = CCCR::TransmitPause::Enabled;

  // Exception handling.
  can_->CCCR.PXHD = CCCR::ProtocolExceptionHandling::Disabled;

  // Normal, non-test mode. Would normally set CCCR.(TEST|MON|ASM) here for
  // debugging and monitoring. Would also set TEST.LBCK if loopback is
  // necessary.

  // Enable FD operation
  can_->CCCR.FDOE = CCCR::FDMode::Enabled;
}

}  // namespace stm32g4
}  // namespace platform