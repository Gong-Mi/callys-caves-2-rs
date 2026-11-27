#ifndef CALLY_MEMORY_ALLOC_HPP
#define CALLY_MEMORY_ALLOC_HPP
#include "memory_internal.hpp"

/* tier: bytecode_anchored; static MemoryManager::_Alloc0x27cd54/292B,
 * Alloc0x27ce78/100B; pinned ARMv7 SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Canonical class remains in vm_buffer.hpp. The ABI retains file/line even
 * though _Alloc does not consume them. No fake bucket provider or globals.
 * gap: bucketAlloc body, complete buckets, original LR/fault/unwind and
 * concurrency, raw noncanonical bool entry states remain unproved.
 */
struct StandardAllocationHeaderPrefix {
    uint32_t requestedSize; // +0
    uint32_t magic04;       // +4 = deadc0de
    uint32_t cookie08;      // +8 = baadb00b
    uint32_t backref0c;     // +c = held failed bucket result (zero)
};
static_assert(sizeof(StandardAllocationHeaderPrefix) == 16, "standard header16");
static_assert(offsetof(StandardAllocationHeaderPrefix, backref0c) == 12, "backref+c");
void *bucketAlloc(unsigned int, bool); // real 0x27c53c; declaration debt only
extern "C" void *memset(void *, int, size_t); // actual libc import for Alloc zero-fill
#endif
