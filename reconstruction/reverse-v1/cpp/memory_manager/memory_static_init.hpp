#ifndef CALLY_MEMORY_STATIC_INIT_HPP
#define CALLY_MEMORY_STATIC_INIT_HPP

#include "memory_buckets.hpp"

/* tier: bytecode_anchored; 0xba3e4 image initializer and 0x27c42c D1/D2.
 * Data layout: g_memStringsMap .bss 0x756798/20B. The Insert body at
 * 0x27d260 is not recovered here; its accesses confirm key/value/hash
 * offsets independently of the initializer (0x27d2d0..0x27d2ec).
 * gap: Insert and final link/load/termination order of the replacement. */
template <typename K, typename V, int N> class CHashMap;

template<> class CHashMap<const char *, int, 3> {
public:
    struct Entry { const char *key; int value; uint32_t hash; };

    // The original's D1/D2 are weak same-entry names, with no injected catch.
    ~CHashMap() noexcept(false) __attribute__((weak));

    int32_t capacity;
    int32_t count;
    uint32_t mask;
    int32_t growThreshold;
    Entry *entries;
};
using MemoryStringsMap = CHashMap<const char *, int, 3>;
static_assert(sizeof(MemoryStringsMap) == 20 && alignof(MemoryStringsMap) == 4 &&
              offsetof(MemoryStringsMap, count) == 4 && offsetof(MemoryStringsMap, mask) == 8 &&
              offsetof(MemoryStringsMap, growThreshold) == 12 && offsetof(MemoryStringsMap, entries) == 16,
              "memory-map startup record");
static_assert(sizeof(MemoryStringsMap::Entry) == 12 &&
              offsetof(MemoryStringsMap::Entry, value) == 4 &&
              offsetof(MemoryStringsMap::Entry, hash) == 8, "map bucket record");

// Storage remains BSS and has no independent compiler-generated destructor registration.
alignas(MemoryStringsMap) extern unsigned char g_memStringsMap[sizeof(MemoryStringsMap)];

namespace memory_startup {
struct Placement { void *address; };
}

// This helper is non-allocating; it is not the original allocating operator new.
inline __attribute__((always_inline)) void *operator new(size_t, memory_startup::Placement placement) noexcept {
    return placement.address;
}

#endif
