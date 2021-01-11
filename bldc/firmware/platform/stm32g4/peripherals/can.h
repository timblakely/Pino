#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_

namespace platform {
namespace stm32g4 {

namespace registers {

// Core release
struct CREL {
  uint8_t DAY : 8;
  uint8_t MON : 8;
  uint8_t YEAR : 4;
  uint8_t SUBSTEP : 4;
  uint8_t STEP : 4;
  uint8_t REL : 4;
};

// Endian
struct ENDN {
  uint32_t EVT;
  operator uint32_t() { return reinterpret_cast<uint32_t>(EVT); }
};

// Data bit timing and prescalar
struct DBTP {
  enum class TransceiverDelayCompensation : bool {
    Disable = 0,
    Enable = 1,
  };

  uint8_t DSJW : 4;
  uint8_t DTSEG2 : 4;
  uint8_t DTSEG1 : 5;
  unsigned : 3;  // Reserved
  uint8_t DBRP : 5;
  unsigned : 2;  // Reserved
  TransceiverDelayCompensation TDC : 1;
};

// Test mode. Must be enabled by setting bit `CCCR[TEST]` to 1.
struct TEST {
  enum class LoopbackMode : bool {
    Disabled = 0,
    Enabled = 1,
  };

  enum class TransmitPin : uint8_t {
    Default = 0b00U,      // Normal operation; updated at end of CAN bit time.
    SamplePoint = 0b01U,  // Updated at sample point.
    Dominant = 0b10U,     // Dominant (0) level at ping FDCANx_TX
    Recessive = 0b11U,    // Recessive
  };

  enum class ReceivePin : uint8_t {
    Dominant = 0b0U,
    Recessive = 0b1U,
  };

  unsigned : 4;  // Reserved
  LoopbackMode LBCK : 1;
  TransmitPin TX : 2;
  ReceivePin RX : 1;
};

// RAM watchdog
struct RWD {
  uint8_t WDC : 8;
  uint8_t WDV : 8;
};

// CC control.
struct CCCR {
  enum class InitMode : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class ConfigMode : uint8_t {
    ReadOnly = 0b0U,
    ReadWrite = 0b1U,
  };

  enum class RestrictedMode : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class ClockStopAck : uint8_t {
    NoAck = 0b0U,
    Ack = 0b1U,
  };

  enum class ClockStopRequest : uint8_t {
    No = 0b0U,
    Yes = 0b1U,
  };

  enum class BusMonitoringMode : uint8_t {
    Normal = 0b0U,
    Monitoring = 0b1U,
  };

  enum class AutomaticRetransmission : uint8_t {
    Enabled = 0b0U,
    Disabled = 0b1U,
  };

  enum class TestMode : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class FDMode : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class FDBitrateSwitching : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class ProtocolExceptionHandling : uint8_t {
    Enabled = 0b0U,
    Disabled = 0b1U,
  };

  enum class EdgeFiltering : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class TransmitPause : uint8_t {
    Disabled = 0b0U,
    Enabled = 0b1U,
  };

  enum class ISOMode : uint8_t {
    ISO11898_1 = 0b0U,
    Bosch = 0b1U,
  };

  // Initialization
  InitMode INIT : 1;
  // Configuration change enable
  ConfigMode CCE : 1;
  // ASM restricted operation mode
  RestrictedMode ASM : 1;
  // Clock stop acknowledge
  ClockStopAck CSA : 1;
  // Clock stop request
  ClockStopRequest CSR : 1;
  // Bus monitoring mode
  BusMonitoringMode MON : 1;
  // Disable automatic retransmission
  AutomaticRetransmission DAR : 1;
  // Test mode
  TestMode TEST : 1;
  // FD mode
  FDMode FDOE : 1;
  // FD bit rate switching
  FDBitrateSwitching BSRE : 1;
  unsigned : 2;  // Reserved
  // Protocol exception handling
  ProtocolExceptionHandling PXHD : 1;
  // Edge filtering during bus integration
  EdgeFiltering EFBI : 1;
  // Pause before starting next transmission
  TransmitPause TXP : 1;
  // Non-ISO mode
  ISOMode NISO : 1;
};

}  // namespace registers

class Can {
 public:
  enum class Instance : uint32_t {
    // Note: these are the actual addresses in memory of each peripheral.
    Fdcan1 = 0x40006400UL,
    Fdcan2 = 0x40006800UL,
    Fdcan3 = 0x40006C00UL,
  };

  Can(Can::Instance instance);

  void Init();

 private:
  struct CanInstance {
    // Core release
    registers::CREL CREL;
    uint32_t r1;  // Reserved
    // Endian
    registers::ENDN ENDN;
    // Data bit timing and prescalar
    registers::DBTP DBTP;
    // Test mode. Must be enabled by setting bit `CCCR[TEST]` to 1.
    registers::TEST TEST;
    // RAM watchdog
    registers::RWD RWD;
    // CC control.
    registers::CCCR CCCR;
  };

  CanInstance *can_;
};

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_CAN_H_
