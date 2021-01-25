#ifndef THIRD_PARTY_SG14_INPLACE_FUNCTION_WRAPPER_H_
#define THIRD_PARTY_SG14_INPLACE_FUNCTION_WRAPPER_H_

// Disable exception throwing
#ifndef SG14_INPLACE_FUNCTION_THROW
#define SG14_INPLACE_FUNCTION_THROW(x)
#endif

#include "third_party/sg14/inplace_function.h"

namespace stdext {

static const uint32_t kInplaceFunctionStorageSize = 10;

template <typename T>
using Callback = inplace_function<T, kInplaceFunctionStorageSize>;

}  // namespace stdext

#endif  // THIRD_PARTY_SG14_INPLACE_FUNCTION_WRAPPER_H_
