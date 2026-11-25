#include "object_helpers.hpp"

namespace {
constexpr uint32_t kKindMask = 0x00ffffffu;
constexpr uint32_t kUndefinedKind = 5u;
}

// Retain the observed predicate order and calls; do not infer a broader
// descriptor model from the function's source-level name.
uint32_t JS_IsGenericDescriptor(RValue *descriptor) {
    const uint32_t kind =
        object_wire::read(object_wire::address(descriptor), 0x0c) & kKindMask;
    if (kind == kUndefinedKind) {
        return 0;
    }
    if (JS_IsDataDescriptor(descriptor) != 0u) {
        return 0;
    }
    if (JS_IsAccessorDescriptor(descriptor) != 0u) {
        return 0;
    }
    return 1;
}
