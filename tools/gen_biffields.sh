#! /bin/bash
BAZEL_ROOT="$(bazel info | grep -ioP "(?<=workspace: ).*")"
cd ${BAZEL_ROOT}

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=fdcan1 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/can/fdcan_memory.inl"

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=cordic \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/cordic/cordic_memory.inl"

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=dma1 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/dma/dma_memory.inl"
  
# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=dmamux \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/dmamux/dmamux_memory.inl"
  
# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=flash \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/flash/flash_memory.inl"

# for GPIO in gpioa gpiob gpioc gpiod gpioe gpiof gpiog;
# do
#   bazel run //tools:gen_biffields -- \
#     --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#     --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#     \
#     --peripheral="${GPIO}" \
#     --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/gpio/${GPIO}_memory.inl"
# done

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=nvic \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/nvic/nvic_memory.inl"

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=rcc \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/rcc/rcc_memory.inl"

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=spi1 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/spi/spi_memory.inl"

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=stk \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/systick/stk_memory.inl"
  
# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=tim1 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/timer/adv_timer_memory.inl" \
#   --drop=CCMR1_Input,CCMR2_Input \
#   --rename=CCMR1_Output=CCMR1,CCMR2_Output=CCMR2

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=tim2 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_A_memory.inl" \
#   --drop=CCMR1_Input,CCMR2_Input \
#   --rename=CCMR1_Output=CCMR1,CCMR2_Output=CCMR2

# bazel run //tools:gen_biffields -- \
#   --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
#   --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
#   \
#   --peripheral=tim15 \
#   --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/timer/timer_gp_B_memory.inl" \
#   --drop=CCMR1_Input,CCMR2_Input \
#   --rename=CCMR1_Output=CCMR1,CCMR2_Output=CCMR2

bazel run //tools:gen_biffields -- \
  --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
  --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
  \
  --peripheral=tim6 \
  --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/timer/timer_basic_memory.inl"