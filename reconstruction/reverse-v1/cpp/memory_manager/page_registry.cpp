#include "page_registry.hpp"

/* tier: bytecode_anchored
 * addPageToGlobalPageList(void*, void*) 0x27bcf8..0x27be34, 316 B
 * (75 ARM instructions and 4 pool words), _Z23addPageToGlobalPageListPvS_.
 * original libyoyo_armv7.so 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * body d9c440ddbdf0472ad15aa8dd7eb1ee86ff2aaf1c2d2e5735159e4a678ed5c85b
 * GOT PC+8 base at 0x27bd04 from pool word 0x27be24; next three pool
 * words bind count (3f1830), capacity (3f1834), and array cell (3f1838).
 * gap: initial/other producers, ownership outside this routine, faults on
 * invalid storage/failed imports, unwind and concurrent effects unproved.
 * No stub/default globals, failed-allocation guard or zeroing is added.
 */
namespace {
using BoundaryWord = uint32_t __attribute__((may_alias));

__attribute__((always_inline)) inline uint32_t readBoundary(uintptr_t address) {
    return *reinterpret_cast<const volatile BoundaryWord *>(address);
}
__attribute__((always_inline)) inline void writeBoundary(uintptr_t address, uint32_t value) {
    *reinterpret_cast<volatile BoundaryWord *>(address) = value;
}
} // namespace

void addPageToGlobalPageList(void *page, void *last) {
    uint32_t count = g_bucketNumPages;        // 0x27bd1c
    const uint32_t capacity = pagedata_size;  // 0x27bd20
    uintptr_t base;
    if (static_cast<int32_t>(count + 1u) >= static_cast<int32_t>(capacity)) { // 0x27bd24..2c
        const uint32_t tripled = capacity + (capacity << 1); // 0x27bdd4
        const uint32_t biased = tripled + (tripled >> 31);  // 0x27bddc
        const uint32_t grown = (biased >> 1) | (biased & 0x80000000u); // raw ASR1 @ 0x27bde0
        pagedata_size = grown;                              // 0x27bde4, publish before old pointer read
        void *const held = const_cast<uint32_t *>(g_pages); // 0x27bdf0
        void *const grown_array = realloc(held, static_cast<size_t>(grown << 3)); // 0x27bdec/0x27bdf4
        count = g_bucketNumPages;                           // 0x27bdf8, before g_pages publish
        g_pages = static_cast<const volatile uint32_t *>(grown_array); // 0x27be00
        base = reinterpret_cast<uintptr_t>(grown_array);    // 0x27bdfc/0x27be04: use held r0, no readback
    } else {
        base = reinterpret_cast<uintptr_t>(g_pages);        // 0x27bd30..38: read current array once
    }

    const uintptr_t key = reinterpret_cast<uintptr_t>(page);
    uint32_t index = 0u;
    uintptr_t slot = base;
    bool shift = false;
    if (static_cast<int32_t>(count) > 0) { // 0x27bd3c..40: count<=0 selects base with no element read
        const uint32_t first = readBoundary(base); // 0x27bd44
        if (key < first) {                          // 0x27bd48..4c / 0x27be10..20: unsigned, index 0
            shift = true;
        } else if (first != 0u) {                   // 0x27bd50..54: empty word uses base directly
            uintptr_t cursor = base + 8u;          // 0x27bd58..60
            for (;;) {
                ++index;                            // 0x27bd7c
                slot = cursor;                      // 0x27bd80
                if (index == count) {               // 0x27bd84..8c: no read at end of scan
                    slot = base + (count << 3);     // 0x27bd90
                    break;
                }
                const uint32_t begin = readBoundary(cursor); // 0x27bd64
                cursor += 8u;                         // 0x27bd68
                if (begin > key) {                    // 0x27bd6c..70: unsigned, checked before zero
                    shift = true;
                    break;
                }
                if (begin == 0u) {                    // 0x27bd74..78, preserve this row as store target
                    break;
                }
            }
        }
    }

    if (shift) {
        /* 0x27bda8..0x27bdc0: make room at held index; returned r0 not
         * consumed. Offset and byte count both use uint32 shifts. */
        const uintptr_t dest = base + ((index + 1u) << 3);
        const size_t size = static_cast<size_t>((count - index) << 3);
        memmove(reinterpret_cast<void *>(dest), reinterpret_cast<const void *>(slot), size);
        const uintptr_t live_base = reinterpret_cast<uintptr_t>(g_pages); // 0x27bdc4 first
        count = g_bucketNumPages;                                         // 0x27bdc8 second
        slot = live_base + (index << 3);                                  // 0x27bdcc from held index
    }

    writeBoundary(slot, static_cast<uint32_t>(key)); // 0x27bd94
    writeBoundary(slot + 4u, static_cast<uint32_t>(reinterpret_cast<uintptr_t>(last))); // 0x27bd9c
    g_bucketNumPages = count + 1u;                  // 0x27bd98/0x27bda0, publish count last
}
