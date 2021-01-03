#ifndef BLDC_FIRMWARE_PLATFORM_SETUP_H_
#define BLDC_FIRMWARE_PLATFORM_SETUP_H_

namespace platform {

class BldcPlatform {
 public:
  static BldcPlatform* Instance();

  // Virtual is okay here since we're okay eating the single instruction
  // indirection; these aren't called in any types of loops.
  virtual void Startup() = 0;
  virtual void Fatal() = 0;

  // TODO(blakely): move to template metaprogramming eventually for
  // time-sensitive functions.
  virtual void BlockingWait(uint32_t micros) = 0;

 private:
  uint16_t angle_ = 0;
};

}  // namespace platform

#endif  // BLDC_FIRMWARE_PLATFORM_SETUP_H_
