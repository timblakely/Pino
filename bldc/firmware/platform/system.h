#ifndef BLDC_FIRMWARE_PLATFORM_SETUP_H_
#define BLDC_FIRMWARE_PLATFORM_SETUP_H_

namespace platform {

class Platform {
 public:
  static void Startup();
  static void Fatal();
};

}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_SETUP_H_
