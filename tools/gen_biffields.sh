#! /bin/bash
BAZEL_ROOT="$(bazel info | grep -ioP "(?<=workspace: ).*")"
cd ${BAZEL_ROOT}

bazel run //tools:gen_biffields -- \
  --svd_path="${BAZEL_ROOT}"/third_party/stm32cubeg4/STM32G474xx.svd \
  --svd_yaml_patch="${BAZEL_ROOT}"/third_party/stm32cubeg4/svd_patches/stm32g474xx.yaml \
  --peripheral=tim1 \
  --output_path="${BAZEL_ROOT}"/bldc/firmware/platform/stm32g4/peripherals/timer/adv_timer_memory.inl \
  --drop=CCMR1_Input,CCMR2_Input \
  --rename=CCMR1_Output=CCMR1,CCMR2_Output=CCMR2