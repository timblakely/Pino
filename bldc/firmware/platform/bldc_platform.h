#ifndef BLDC_FIRMWARE_PLATFORM_SETUP_H_
#define BLDC_FIRMWARE_PLATFORM_SETUP_H_

namespace platform {

class BldcPlatform {
 public:
  static BldcPlatform* Create();

  // Virtual is okay here since we're okay eating the single instruction
  // indirection; these aren't called in any types of loops.
  virtual void Startup() = 0;
  virtual void Fatal() = 0;

 private:
};

}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_SETUP_H_
