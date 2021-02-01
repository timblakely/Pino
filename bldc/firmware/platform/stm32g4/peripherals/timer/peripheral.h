#ifndef BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_
#define BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_

namespace platform {
namespace stm32g4 {

namespace timer {

// clang-format off
struct AdvancedPeripheral {
  AdvancedPeripheral() = delete;
  AdvancedPeripheral(AdvancedPeripheral&) = delete;
  AdvancedPeripheral(AdvancedPeripheral&&) = delete;
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_adv_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
};

struct GPAPeripheral {
  GPAPeripheral() = delete;
  GPAPeripheral(GPAPeripheral&) = delete;
  GPAPeripheral(GPAPeripheral&&) = delete;
  // clang-format off
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_a_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  // clang-format on

  using CR1 = CR1_value_t;
  using SMCR = SMCR_value_t;
  using PSC = PSC_value_t;
  using ARR = ARR_value_t;
  using CCER = CCER_value_t;
  using CCMR1 = CCMR1_value_t;
  using CCMR2 = CCMR2_value_t;
  using CCR1 = CCR1_value_t;
  using CCR2 = CCR2_value_t;
  using CCR3 = CCR3_value_t;
  using CCR4 = CCR4_value_t;

  inline uint32_t GetResetValue() { return read_ARR().get_ARR(); }

  inline void InternalClock() {
    update_SMCR(
        [](SMCR v) { return v.with_SMS(SMCR::SMS_t::disabled).with_SMS_3(0); });
  }

  inline void ConfigureTimer(uint16_t prescalar, uint16_t auto_reset) {
    update_PSC([&prescalar](PSC v) { return v.with_PSC(prescalar); });
    update_ARR([&auto_reset](ARR v) { return v.with_ARR(auto_reset); });
  }

  // TODO(blakely): Handle different output types than PWM1
  inline void EnableOutput(uint8_t channel) {
    // CCSx bits are only writable if channel is off.
    update_CCER([&](CCER v) {
      switch (channel) {
        case 1:
          return v.with_CC1E(0);
        case 2:
          return v.with_CC2E(0);
        case 3:
          return v.with_CC3E(0);
        case 4:
          return v.with_CC4E(0);
      }
      return v;
    });
    if (channel <= 2) {
      update_CCMR1([&](CCMR1 v) {
        switch (channel) {
          case 1:
            return v.with_OC1M(0b110).with_OC1M_3(0).with_CC1S(
                CCMR1::CC1S_t::output);
          case 2:
            return v.with_OC2M(0b110).with_OC2M_3(0).with_CC2S(
                CCMR1::CC2S_t::output);
        }
        return v;
      });
    } else {
      update_CCMR2([&](CCMR2 v) {
        switch (channel) {
          case 3:
            return v.with_OC3M(0b110).with_OC3M_3(0).with_CC3S(
                CCMR2::CC3S_t::output);
          case 4:
            // return v.with_OC4M(0b110).with_OC4M_3(0).with_CC4S(
            //     CCMR2::CC4S_t::output);
            return v.with_OC4M(0b111).with_OC4M_3(0).with_CC4S(
                CCMR2::CC4S_t::output);
        }
        return v;
      });
    }

    update_CCER([&](CCER v) {
      switch (channel) {
        case 1:
          return v.with_CC1E(1);
        case 2:
          return v.with_CC2E(1);
        case 3:
          return v.with_CC3E(1);
        case 4:
          return v.with_CC4E(1);
      }
      return v;
    });
  }

  inline void Up() {
    update_CR1(
        [](CR1 v) { return v.with_DIR(0).with_CMS(CR1::CMS_t::up_down); });
  }

  inline void Down() {
    update_CR1(
        [](CR1 v) { return v.with_DIR(1).with_CMS(CR1::CMS_t::up_down); });
  }

  inline void Center(bool up_interrupt, bool down_interrupt) {
    update_CR1([&](CR1 v) {
      if (!up_interrupt) {
        return v.with_CMS(CR1::CMS_t::center_interrupt_down);
      } else if (!down_interrupt) {
        return v.with_CMS(CR1::CMS_t::center_interrupt_up);
      } else {
        return v.with_CMS(CR1::CMS_t::center_interrupt_both);
      }
    });
  }

  inline void Enable() {
    update_CR1([](CR1 v) { return v.with_CEN(1); });
  }

  inline void Disable() {
    update_CR1([](CR1 v) { return v.with_CEN(0); });
  }

  inline void SetCompare(uint8_t channel, uint16_t value) {
    switch (channel) {
      case 1:
        update_CCR1([&value](CCR1 v) { return v.with_CCR1(value); });
        break;
      case 2:
        update_CCR2([&value](CCR2 v) { return v.with_CCR2(value); });
        break;
      case 3:
        update_CCR3([&value](CCR3 v) { return v.with_CCR3(value); });
        break;
      case 4:
        update_CCR4([&value](CCR4 v) { return v.with_CCR4(value); });
        break;
    }
  }
};

struct GPBPeripheral {
  GPBPeripheral() = delete;
  GPBPeripheral(GPBPeripheral&) = delete;
  GPBPeripheral(GPBPeripheral&&) = delete;
  // clang-format off
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_b_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  // clang-format on
};

struct BasicPeripheral {
  BasicPeripheral() = delete;
  BasicPeripheral(BasicPeripheral&) = delete;
  BasicPeripheral(BasicPeripheral&&) = delete;
  // clang-format off
#define ETL_BFF_DEFINITION_FILE                                  \
  "bldc/firmware/platform/stm32g4/peripherals/timer/timer_basic_memory.inl"
#include "third_party/etl/biffield/generate.h"
#undef ETL_BFF_DEFINITION_FILE
  // clang-format on
};

}  // namespace timer

}  // namespace stm32g4
}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_STM32G4_PERIPHERALS_TIMER_PERIPHERAL_H_
