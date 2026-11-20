#ifndef CALLY_PROFILER_PUSH_WIRE_HPP
#define CALLY_PROFILER_PUSH_WIRE_HPP
#include "../object_base/object_internal.hpp"
#include "../timing/timing.hpp"

/* tier: bytecode_anchored. CProfiler::Push 0x2a0738..0x2a0870, pinned
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Only three stack-image words are initially defined by the original.
 * gap: original private-stack garbage values, invalid pointers, unwind and
 * paired-transfer atomicity are not certified. Never fill the tail with zero.
 */
struct alignas(8) ProfilerPushFrameImage {
    uint32_t kind;
    uint32_t id;
    uint32_t nodeIndex;
    uint8_t uninitializedTail[12];
};
static_assert(sizeof(ProfilerPushFrameImage) == 24, "observed stack frame image");
static_assert(offsetof(ProfilerPushFrameImage, uninitializedTail) == 12, "original undefined tail");

namespace profiler_push_wire {
/* Raw byte transport avoids numeric C++ reads of indeterminate words and
 * keeps the original LDM4 / STR2 / LDM2 / STR4 access shape. This small
 * supporting primitive is not an additional original recovered function.
 */
inline void copyFrame24(uint32_t destination, const volatile ProfilerPushFrameImage *source) {
    const volatile ProfilerPushFrameImage *cursor = source;
    __asm__ volatile(
        "ldmia %0!, {r0, r1, r2, r3}\n\t"
        "str r0, [%1]\n\t"
        "str r1, [%1, #4]\n\t"
        "ldmia %0!, {r0, r1}\n\t"
        "str r2, [%1, #8]\n\t"
        "str r3, [%1, #12]\n\t"
        "str r0, [%1, #16]\n\t"
        "str r1, [%1, #20]"
        : "+&r"(cursor) : "r"(destination) : "r0", "r1", "r2", "r3", "memory");
}
}
#endif
