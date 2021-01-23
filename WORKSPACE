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

""

local_repository(
    name = "arm_gcc",
    path = "/home/tim/git/stm32g4/arm_gcc",
)

load("@arm_gcc//:repository.bzl", "local_arm_gcc")

# local_arm_gcc("/home/tim/gcc_arm_none_eabi/gcc-arm-none-eabi-9-2019-q4-major")
local_arm_gcc("/home/tim/gcc_arm_none_eabi/gcc-arm-none-eabi-10-2020-q4-major")

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

new_git_repository(
    name = "etl",
    build_file = "//third_party/etl:repo.BUILD",
    commit = "2d00ac79ec13632e6c10df11f4623938cfdc2dd4",
    patch_cmds = [
        "rm biffield/BUILD",
        "find ./ -type f -exec sed -i 's|#include \"etl|#include \"third_party/etl|g' {} \\;",
    ],
    remote = "https://github.com/cbiffle/etl",
    shallow_since = "1464883496 -0700",
)

http_archive(
    name = "bazel_skylib",
    sha256 = "97e70364e9249702246c0e9444bccdc4b847bed1eb03c5a3ece4f83dfe6abc44",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
        "https://github.com/bazelbuild/bazel-skylib/releases/download/1.0.2/bazel-skylib-1.0.2.tar.gz",
    ],
)

load("@bazel_skylib//:workspace.bzl", "bazel_skylib_workspace")

bazel_skylib_workspace()

http_archive(
    name = "rules_python",
    sha256 = "b6d46438523a3ec0f3cead544190ee13223a52f6a6765a29eae7b7cc24cc83a0",
    url = "https://github.com/bazelbuild/rules_python/releases/download/0.1.0/rules_python-0.1.0.tar.gz",
)

load("@rules_python//python:pip.bzl", "pip_install")

pip_install(
    requirements = "//:requirements.txt",
)
