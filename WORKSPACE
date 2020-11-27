workspace(name = "pino")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "stm32cubeg4",
    build_file = "@//third_party/stm32cubeg4:repo.BUILD",
    sha256 = "c6088f3ca0417e9b411b7769fc76582c0dc7057db44a83109e527462f0b601e6",
    strip_prefix = "STM32CubeG4-1.3.0",
    urls = ["https://github.com/STMicroelectronics/STM32CubeG4/archive/v1.3.0.zip"],
)

http_archive(
    name = "cmsis",
    build_file = "@//third_party/cmsis:repo.BUILD",
    sha256 = "3150de0ad42b01052bbb8bad562c9c292fef3bc7d4ac1c16acee63d8af696875",
    strip_prefix = "CMSIS_5-5.7.0",
    urls = ["https://github.com/ARM-software/CMSIS_5/archive/5.7.0.zip"],
)

local_repository(
    name = "arm_gcc",
    path = "/home/tim/git/stm32g4/arm_gcc",
)

load("@arm_gcc//:repository.bzl", "local_arm_gcc")

local_arm_gcc("/home/tim/gcc_arm_none_eabi/gcc-arm-none-eabi-9-2019-q4-major")

local_repository(
    name = "stm32g4xx_hal",
    path = "/home/tim/git/stm32g4/stm32g4_hal",
)

load(
    "@bazel_tools//tools/build_defs/repo:git.bzl",
    "new_git_repository",
)

new_git_repository(
    name = "sg14",
    build_file = "//third_party/sg14:repo.BUILD",
    commit = "014fbbb43e63ffde629b155139b85375a04c191f",
    remote = "https://github.com/WG21-SG14/SG14",
    shallow_since = "1586132753 +1200",
)

new_git_repository(
    name = "mapbox_eternal",
    build_file = "//third_party/mapbox/eternal:repo.BUILD",
    commit = "756ff2e049bd57d75f3bf869240e641095575b80",
    remote = "https://github.com/mapbox/eternal",
    shallow_since = "1603709757 +0200",
)
