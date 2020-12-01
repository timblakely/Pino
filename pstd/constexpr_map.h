#ifndef BLDC_FIRMWARE_CONSTEXPR_MAP_H_
#define BLDC_FIRMWARE_CONSTEXPR_MAP_H_

#include "third_party/mapbox/eternal/eternal.hpp"

namespace pstd {

template <typename Key, typename Value, std::size_t N>
static constexpr auto ConstexprMap(
    const std::pair<const Key, const Value> (&items)[N]) noexcept {
  return mapbox::eternal::impl::map<mapbox::eternal::impl::element<Key, Value>,
                                    N>(items);
}

}  // namespace pstd

#endif  // BLDC_FIRMWARE_CONSTEXPR_MAP_H_
