#! /bin/bash
BAZEL_ROOT="$(bazel info | grep -ioP "(?<=workspace: ).*")"
cd ${BAZEL_ROOT}

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
  
bazel run //tools:gen_biffields -- \
  --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
  --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
  \
  --peripheral=dmamux \
  --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/dmamux/dmamux_memory.inl"
  
bazel run //tools:gen_biffields -- \
  --svd_path="${BAZEL_ROOT}/third_party/stm32cubeg4/STM32G474xx.svd" \
  --svd_yaml_patch="${BAZEL_ROOT}/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml" \
  \
  --peripheral=flash \
  --output_path="${BAZEL_ROOT}/bldc/firmware/platform/stm32g4/peripherals/flash/flash_memory.inl"