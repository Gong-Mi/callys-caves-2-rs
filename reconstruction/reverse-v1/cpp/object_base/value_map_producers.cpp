#include "value_map_producers.hpp"

/* Producers for the canonical 20B _rvalue page pool and the AllocVars raw
 * map prefix. Recovered bodies, this TU only:
 *   GetRValue()               _Z9GetRValuev            0x190dc0, 196B, 49 words
 *   YYObjectBase::AllocVars() _ZN12YYObjectBase9AllocVarsEv 0x1917dc, 176B, 44 words
 * tier: bytecode_anchored; fixed ARMv7 image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Per-word ownership from intake scratch cally-loop-value-map-debug-48ciklkb
 * original-0x190dc0.asm.txt / original-0x1917dc.asm.txt with index TSVs.
 * anchors: GetRValue reaches the inline 20B _rvalue pool (0x536d88) through
 * the GOT literal word at 0x190e80; pool+0x04 pageHead, +0x08 freeHead,
 * +0x0c activeCount, +0x10 freeCount, each node linked on its first word —
 * the exact counterpart of the recovered FreeRValue in value_pool.cpp.
 * AllocVars keeps the original call order: this+0x5c cleared BEFORE
 * operator new(20); prefix words written raw (8/7/0), MemoryManager::Alloc
 * (96, "jni/../jni/yoyo/../../../Platform/MemoryManager.h" @0x331038, line
 * 70, true) publishes header+0x10, memset 96, then capacity and buckets are
 * RE-READ LIVE after the calls and the threshold comes from the preserved
 * VFP sequence value_map_wire::threshold (factor bits 0x3f19999a), not a C
 * cast or a constant.
 * gap: faults (bad_alloc, null buckets store), FPSCR/trap behaviour, unwind,
 * concurrency, the initial pool/global producers and the complete HashMap/
 * RValue classes remain unproved; no equivalence claim between this source
 * and the original machine code, and the original was never executed.
 */

namespace {
inline void *asPointer(uint32_t address)
{
    return reinterpret_cast<void *>(static_cast<uintptr_t>(address));
}
inline RValue *asRValue(uint32_t address)
{
    return reinterpret_cast<RValue *>(static_cast<uintptr_t>(address));
}
inline uint8_t *asBytePointer(uint32_t address)
{
    return reinterpret_cast<uint8_t *>(static_cast<uintptr_t>(address));
}
inline VMStackPagePrefix *asPagePointer(uint32_t address)
{
    return reinterpret_cast<VMStackPagePrefix *>(static_cast<uintptr_t>(address));
}
/* 0x331038 string literal consumed by MemoryManager::Alloc (r1 at 0x191820
 * via the pc-relative add at 0x191800, literal word 0x191888). */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";
} // namespace

static_assert(sizeof(rvalue_state::RValuePagePool) == 20, "inline _rvalue pool is 20B");

RValue *GetRValue()
{
    volatile rvalue_state::RValuePagePool &pool = rvalue_state::livePages();

    /* 0x190dc4..0x190dcc: two literal/GOT words resolve r4 to the pool; the
     * model binds the same object through the _rvalue alias. freeHead read. */
    const uint32_t held = object_wire::address(pool.freeHead); // +0x08
    if (held != 0u) {
        /* Non-empty path, 0x190dd8..0x190ddc: freeCount and the held node's
         * first word are read BEFORE the shared publish entry at 0x190de0. */
        const uint32_t freeCount = pool.freeCount;               // 0x190dd8 +0x10
        const uint32_t next = object_wire::read(held, 0u);     // 0x190ddc node.firstWord
        /* Shared tail 0x190de0..0x190df8: activeCount read live, freeCount-1,
         * publish freeHead=next, then freeCount, then activeCount+1. Only
         * pool words are written: no other node word is touched and no
         * RValue construction happens; the held node address returns raw. */
        const uint32_t activeCount = pool.activeCount;             // 0x190de0 +0x0c
        pool.freeHead = asBytePointer(next);                   // 0x190de8 (wraps as raw ARM32 address)
        pool.freeCount = freeCount - 1u;                         // 0x190de4/0x190dec u32 wrap
        pool.activeCount = activeCount + 1u;                       // 0x190df0/0x190df4 u32 wrap
        return asRValue(held);                                 // 0x190df8 pop {pc}, r0 held
    }

    /* Empty path, 0x190dfc..: exactly 0x100018 bytes via the original
     * operator new 0x27c524, then memset(base+8, 0x78, 0x100010) at
     * memset@plt 0xb65b0. The fill and the 0x78 pattern are not optional. */
    const uint32_t base = object_wire::address(operator new(0x100018u)); // r5 held
    memset(asPointer(base + 8u), 0x78, 0x100010u);

    /* Snapshot AFTER new/memset returned: 0x190e20 ldmib loads pageHead(+0x04)
     * into r7 and freeHead(+0x08) into r8; 0x190e28 re-reads count10 live. */
    const uint32_t oldPage = object_wire::address(pool.pageHead); // 0x190e20 r7
    const uint32_t oldFree = object_wire::address(pool.freeHead); // 0x190e20 r8
    const uint32_t oldCount = pool.freeCount;                       // 0x190e28
    const uint32_t first = (base + 24u) & ~15u;                   // 0x190e24/0x190e2c bic #15
    /* The original keeps two separate wrapping adds on r0: 0x190e30 +0xFF000
     * then 0x190e38 +0xFF0 for the loop end and 0x190e74 +0xFE0 for the
     * returned last block. */
    const uint32_t spanBase = first + 0x000FF000u;                // 0x190e30 ADD #1044480 = 0xff000
    const uint32_t loopEnd = spanBase + 0x00000FF0u;              // 0x190e38 r12 = first+0xFFFF0

    object_wire::write(base, 0u, oldPage);                        // 0x190e34 [r5]=oldPage
    pool.pageHead = asPagePointer(base);                          // 0x190e40 [r4,#4]
    uint32_t cursor = first + 16u;                                // 0x190e44 r3
    object_wire::write(first, 0u, oldFree);                       // 0x190e48 first.next=oldFree
    uint32_t previous = first;                                    // 0x190e4c r2
    pool.freeHead = asBytePointer(first);                         // 0x190e50 [r4,#8]
    pool.freeCount = oldCount + 1u;                                 // 0x190e54 [r4,#0x10]

    /* 0x190e58 b jumps over the first mov r2,r1: do/while over 16B links,
     * store previous at cursor, cursor+=16, stop when cursor == loopEnd.
     * On exit r2/previous holds the value written into the last block
     * (= the block before it); the original never re-reads that word. */
    for (;;) {
        const uint32_t current = cursor;                          // 0x190e60 r1=r3
        object_wire::write(current, 0u, previous);                // 0x190e64 str r2,[r3],#16
        cursor = current + 16u;
        if (cursor == loopEnd) {                                  // 0x190e68/0x190e6c
            break;
        }
        previous = current;                                       // 0x190e5c mov r2,r1
    }

    /* 0x190e70..0x190e7c: r0=first+0xFFFE0 (returned last block),
     * r3=oldCount+0xFF00+0xFF. The b to 0x190de0 SKIPS the freeCount and
     * node-word reads, so countBase-1 is the net +0xFFFE; activeCount is
     * still read live at the shared entry and published in original order. */
    const uint32_t countBase = (oldCount + 0x0000FF00u) + 0x000000FFu; // 0x190e70/0x190e78
    const uint32_t heldNode = spanBase + 0x00000FE0u;             // 0x190e74 r0 = first+0xFFFE0
    const uint32_t activeCount = pool.activeCount;                    // 0x190de0 live +0x0c
    pool.freeHead = asBytePointer(previous);                      // 0x190de8 retained r2 = prev block
    pool.freeCount = countBase - 1u;                                // 0x190de4/0x190dec net +0xFFFE u32
    pool.activeCount = activeCount + 1u;                              // 0x190df0/0x190df4
    return asRValue(heldNode);                                    // 0x190df8
}

void YYObjectBase::AllocVars()
{
    const uint32_t self = object_wire::address(this);

    /* 0x1917e4..0x1917f0: this+0x5c is zeroed BEFORE operator new(20); the
     * raw 20B map prefix (r4) is held, never a constructed class object. */
    object_wire::write(self, 0x5cu, 0u);                          // 0x1917ec
    ObjectVariableMapPrefix *const map =
        static_cast<ObjectVariableMapPrefix *>(operator new(20u)); // 0x1917e8/#20, 0x1917f0
    const uint32_t mapAddr = object_wire::address(map);

    /* 0x191808..0x191814: raw prefix words — capacity(+0x00)=8, mask
     * (+0x08)=7, buckets(+0x10)=0 — with r5=0, before any call. */
    object_wire::write(mapAddr, 0x00u, 8u);                       // 0x191808
    object_wire::write(mapAddr, 0x08u, 7u);                       // 0x19180c
    object_wire::write(mapAddr, 0x10u, 0u);                       // 0x191814

    /* 0x19181c..0x19182c: Alloc(96, "jni/../jni/yoyo/../../../Platform/
     * MemoryManager.h"@0x331038, line 70, true); the returned bucket block
     * is published at header+0x10 BEFORE memset(returned, 0, 96) runs. */
    void *const buckets = MemoryManager::Alloc(
        96u, memoryManagerHeaderSourcePath, 70, true);            // 0x191820 -> 0x27ce78
    object_wire::write(mapAddr, 0x10u, object_wire::address(buckets)); // 0x19182c
    memset(buckets, 0, 96u);                                      // 0x191830 r1=0 r2=#96

    /* 0x191834: capacity is RE-READ live from the header after the calls —
     * no earlier caching. count(+0x04)=0 at 0x19183c. The threshold is the
     * real VFP chain (vmov/vcvt.f32.s32/vmul/vcvt.s32.f32, factor
     * 0x3f19999a) over that live signed capacity and stores to +0x0c
     * UNCONDITIONALLY, before the 0x191840 signed cmp reaches its branch. */
    const int32_t capacityLive =
        static_cast<int32_t>(object_wire::read(mapAddr, 0x00u));  // 0x191834 r2
    object_wire::write(mapAddr, 0x04u, 0u);                       // 0x19183c
    const int32_t threshold = value_map_wire::threshold(capacityLive); // 0x191838..0x191854
    object_wire::write(mapAddr, 0x0Cu, static_cast<uint32_t>(threshold)); // 0x191854 vstr

    if (capacityLive > 0) {
        /* 0x19185c..0x191878: stop = buckets + wrap(cap*3)*4 = buckets +
         * wrap(cap*12) in u32; buckets is RE-READ live at 0x191860, so an
         * external change to header+0x10 is honored exactly as in the
         * original. Each 12B bucket gets ONLY +0x08=0; no null guard is
         * invented, but actual fault behavior is not certified here. */
        uint32_t strideBytes = static_cast<uint32_t>(capacityLive);
        strideBytes = strideBytes + (strideBytes << 1);           // 0x19185c add r2,r2,r2 lsl #1
        uint32_t bucket = object_wire::read(mapAddr, 0x10u);      // 0x191860 r3 live
        const uint32_t stop = bucket + (strideBytes << 2);        // 0x191868 add r2,r3,r2 lsl #2
        do {                                                      // 0x19186c..0x191878
            object_wire::write(bucket, 0x08u, 0u);                // str r1,[r3,#8]
            bucket += 12u;                                        // 0x191870
        } while (bucket != stop);                                 // 0x191874/0x191878
    }

    object_wire::write(self, 0x60u, mapAddr);                     // 0x19187c: HELD raw header, not realloc'd
}
