#ifndef COMMON_INTERRUPT_TABLE_H_
#define COMMON_INTERRUPT_TABLE_H_

#include <memory>
#include <utility>

#include "third_party/sg14/inplace_function_wrapper.h"

// TODO(blakely): find a more appropriate place for this
namespace common {

// some metaprogramming utility code
namespace utility {
template <std::size_t... Is>
constexpr auto index_over(std::index_sequence<Is...>) {
  return [](auto&& f) -> decltype(auto) {
    return f(std::integral_constant<std::size_t, Is>{}...);
  };
}
template <std::size_t N>
constexpr auto index_upto(std::integral_constant<std::size_t, N> = {}) {
  return index_over(std::make_index_sequence<N>{});
}
}  // namespace utility

template <int NumInterrupts>
class InterruptTable {
 public:
  using ISR = void (*)();
  using Callback = stdext::Callback<void()>;
  InterruptTable() = delete;

  // Creates an array of ISRs that invoke the associated handler. This is
  // equivalent to copy-pasting void global_isr_N() { global_handler_N(); } N
  // times.
  constexpr static std::array<ISR, NumInterrupts> make_isrs() {
    return utility::index_upto<NumInterrupts>()(
        [](auto... Is) -> std::array<ISR, NumInterrupts> {
          return {{[] {
            const uint32_t irq_number = decltype(Is)::value;
            handlers[irq_number]();  //
          }...}};
        });
  }

 protected:
  constexpr static inline std::array<ISR, NumInterrupts> isrs = make_isrs();
  static inline std::array<Callback, NumInterrupts> handlers = {{}};
};

}  // namespace common

#endif  // COMMON_INTERRUPT_TABLE_H_
