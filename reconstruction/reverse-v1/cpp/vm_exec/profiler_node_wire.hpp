#ifndef CALLY_PROFILER_NODE_WIRE_HPP
#define CALLY_PROFILER_NODE_WIRE_HPP
#include "../object_base/object_internal.hpp"

/* tier: bytecode_anchored; CProfiler::FindOrCreateNode 0x2a04f4..0x2a06d0,
 * pinned ARMv7 SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * The stats header is capacity+0/count+4/data+8 (different from Push stack
 * header data+0/count+4/cap+8). Records stride 40, packed kind4/id28 at +0,
 * child index+0x18/sibling+0x1c, +4..7 and+0x24..27 left untouched.
 * gap: complete containers, producers, reentrant field mutation, bad/cyclic
 * tables, fault/unwind/concurrency remain unproved. No default data defined.
 */
namespace profiler_node_wire {
using Byte = uint8_t __attribute__((may_alias));
inline uint8_t readByte(uint32_t base, uint32_t offset) {
    return *reinterpret_cast<const volatile Byte *>(static_cast<uintptr_t>(base + offset));
}
inline void writeByte(uint32_t base, uint32_t offset, uint8_t value) {
    *reinterpret_cast<volatile Byte *>(static_cast<uintptr_t>(base + offset)) = value;
}
}
#endif
