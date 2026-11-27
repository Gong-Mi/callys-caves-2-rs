#ifndef CALLY_VALUE_MAP_PRODUCERS_HPP
#define CALLY_VALUE_MAP_PRODUCERS_HPP
#include "object_alloc_internal.hpp"

/* tier: bytecode_anchored; GetRValue0x190dc0/196B and
 * YYObjectBase::AllocVars0x1917dc/176B, original ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Reuse the canonical _rvalue20B pool and ObjectVariableMapPrefix20B raw
 * image. No RValue/HashMap object construction or destructor is invented.
 * gap: full class, initial pool/global producers, failures/trap/unwind,
 * bad pointers and paired-transfer concurrency remain unproved.
 */
static_assert(sizeof(ObjectVariableMapPrefix) == 20, "AllocVars new20 map image");
namespace value_map_wire {
/* Original 191844..191854: signed capacity to F32, multiply by the exact
 * binary 0x3f19999a factor, truncate to S32. Preserve actual VFP operations,
 * not a host FP expression/cast; FPSCR trap/unwind domain remains unproved.
 */
inline int32_t threshold(int32_t capacity) {
    const uint32_t factor = 0x3f19999au;
    int32_t result;
    __asm__ volatile(
        "vmov s15, %1\n\t"
        "vmov s13, %2\n\t"
        "vcvt.f32.s32 s14, s13\n\t"
        "vmul.f32 s15, s14, s15\n\t"
        "vcvt.s32.f32 s15, s15\n\t"
        "vmov %0, s15"
        : "=r"(result) : "r"(factor), "r"(capacity) : "d6", "d7", "memory");
    return result;
}
}
#endif
