#include "object_helpers.hpp"

/* FreeRValue leaf recovery, 0x190e84..0x190ef0 (108B, 27 words incl. one
 * GOT-literal word) in libyoyo_armv7.so, SHA-256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * tier: bytecode_anchored. anchors: the global _rvalue is a 20B inline page
 * pool object at 0x536d88 reached through GOT slot 0x3f0678 (0x190e84/0x190e88),
 * pageHead at pool+0x04, freeHead +0x08, count0c +0x0c, count10 +0x10; every
 * pool node links at +0x00 and owns the half-open data range
 * [page+0x08, page+0x100008).
 * gap: the page producer, bad/cyclic chains (a cycle spins here forever, as in
 * the original), concurrency and unwind are unproved.
 * The second and third parameters are not consumed by the original: r1/r2 are
 * overwritten at 0x190e98/0x190e9c before use, so no out-link is invented.
 * This is pool-specific reclaim, not a generic free: no kind check, no
 * destructor, no MMFree, no clearing of words other than value+0x00.
 */
void FreeRValue(RValue *value, RValue **, RValue **) {
    // 0x190e8c..0x190e94: load pageHead (+0x04); null pageHead returns untouched.
    for (VMStackPagePrefix *page = rvalue_state::pages.pageHead;
         page != nullptr;
         page = static_cast<volatile VMStackPagePrefix *>(page)->next) { // live +0x00 after a miss
        const uint32_t pageAddr = object_wire::address(page);
        // 0x190e98 add r1,r3,#8 / 0x190e9c+0x190ea4 add r2,r3,#0x100000 then +8:
        // two separate wrapping uint32 adds, kept as such.
        const uint32_t lo = pageAddr + 0x8u;
        const uint32_t hi = (pageAddr + 0x100000u) + 0x8u;
        const uint32_t v = object_wire::address(value);
        if (v < lo) { // 0x190ea0 cmp / 0x190ea8 blo: below the page, scan next
            continue;
        }
        if (v >= hi) { // 0x190eac cmp r2,r0 / 0x190eb0 bhi miss: above it too
            continue;
        }
        // Hit: only value inside [page+0x08, page+0x100008) is reclaimed.
        volatile RValuePagePoolPrefix &pool = rvalue_state::pages;
        const uint32_t oldFree = object_wire::address(pool.freeHead); // 0x190ec4 +0x08
        const uint32_t newCount10 = pool.count10 + 1u; // 0x190ec8 +0x10, 0x190ed0 add
        const uint32_t newCount0c = pool.count0c - 1u; // 0x190ecc +0x0c, 0x190ed8 sub
        object_wire::write(v, 0x0u, oldFree); // 0x190ed4: first word = old freeHead
        pool.freeHead = reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(v)); // 0x190edc
        pool.count10 = newCount10; // 0x190ee0
        pool.count0c = newCount0c; // 0x190ee4
        return;                    // 0x190ee8
    }
    // Chain exhausted: original bx lr with every pool field and the value
    // left exactly as found.
}
