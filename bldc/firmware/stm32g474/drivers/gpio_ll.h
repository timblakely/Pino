#ifndef BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_LL_H_
#define BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_LL_H_

#include "bldc/firmware/stm32g474/drivers/gpio.h"
#include "bldc/firmware/stm32g474/drivers/gpio_defines.h"
#include "third_party/mapbox/eternal/eternal.hpp"
#include "third_party/stm32cubeg4/stm32g4xx_ll_gpio.h"

namespace stm32g474 {
namespace drivers {
namespace ll {

static constexpr auto kLLPortMap = mapbox::eternal::map<GpioPort, uint32_t>({
    {GpioPort::A, GPIOA_BASE},
    {GpioPort::B, GPIOB_BASE},
    {GpioPort::C, GPIOC_BASE},
    {GpioPort::D, GPIOD_BASE},
    {GpioPort::E, GPIOE_BASE},
});

auto Port(GpioPort port) {
  return reinterpret_cast<GPIO_TypeDef*>(kLLPortMap.at(port));
}

static constexpr auto kLLPinMap = mapbox::eternal::map<uint32_t, uint32_t>({
    {0, LL_GPIO_PIN_0},
    {1, LL_GPIO_PIN_1},
    {2, LL_GPIO_PIN_2},
    {3, LL_GPIO_PIN_3},
    {4, LL_GPIO_PIN_4},
    {5, LL_GPIO_PIN_5},
    {6, LL_GPIO_PIN_6},
    {7, LL_GPIO_PIN_7},
    {8, LL_GPIO_PIN_8},
    {9, LL_GPIO_PIN_9},
    {10, LL_GPIO_PIN_10},
    {11, LL_GPIO_PIN_11},
    {12, LL_GPIO_PIN_12},
    {13, LL_GPIO_PIN_13},
    {14, LL_GPIO_PIN_14},
    {15, LL_GPIO_PIN_15},
});

auto Pin(uint32_t pin) { return kLLPinMap.at(pin); }

static constexpr auto kLLPinMode = mapbox::eternal::map<GpioMode, uint32_t>({
  {GpioMode::Input, LL_GPIO_MODE_INPUT},
      {GpioMode:: : Output, LL_GPIO_MODE_OUTPUT},
  //     {1, LL_GPIO_PIN_1},
  //     {2, LL_GPIO_PIN_2},
  //     {3, LL_GPIO_PIN_3},
  //     {4, LL_GPIO_PIN_4},
  //     {5, LL_GPIO_PIN_5},
  //     {6, LL_GPIO_PIN_6},
  //     {7, LL_GPIO_PIN_7},
  //     {8, LL_GPIO_PIN_8},
  //     {9, LL_GPIO_PIN_9},
  //     {10, LL_GPIO_PIN_10},
  //     {11, LL_GPIO_PIN_11},
  //     {12, LL_GPIO_PIN_12},
  //     {13, LL_GPIO_PIN_13},
  //     {14, LL_GPIO_PIN_14},
  //     {15, LL_GPIO_PIN_15},
  // });

  // auto pin_mode(GpioPort port) {
  //   return reinterpret_cast<GPIO_TypeDef*>(kLLPinMap.at(port));
  // }

}  // namespace ll
}  // namespace ll
}  // namespace drivers
#endif  // BLDC_FIRMWARE_STM32G474_DRIVERS_GPIO_LL_H_
