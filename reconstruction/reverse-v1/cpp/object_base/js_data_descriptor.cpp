#include "object_helpers.hpp"

namespace {
constexpr uint32_t kUnresolvedKind = 0x00ffffffu;
}

// This follows the raw descriptor fields consumed by the ARMv7 body. It does
// not infer a complete descriptor-object or YYObjectBase layout.
uint32_t JS_IsDataDescriptor(RValue *descriptor) {
    const uint32_t kind =
        object_wire::read(object_wire::address(descriptor), 0x0c) & 0x00ffffffu;
    if (kind == kUnresolvedKind) {
        return 0;
    }
    if (kind != 6u) {
        return 1;
    }

    const uint32_t payload = object_wire::read(object_wire::address(descriptor), 0x00);
    const uint32_t flags = object_wire::read(payload, 0x48);
    return flags == 2u ? 0u : 1u;
}
