#include "gc_generation.hpp"

// Observe exactly the original words: slot+8 hash, slot+0 key, slot+4 value.
typedef uint32_t GCRootHashWord __attribute__((may_alias));

/* Short-batch B: CGCGeneration::RemoveRoot @0x1911c8 (window
 * 0x1911c8..0x19135c, 404B) plus only the pointer CompareKeys specialization
 * it actually calls, _Z19CHashMapCompareKeysIP12YYObjectBaseEbT_S2_ @0x190f48
 * (window 0x190f48..0x190f58, 16B). Pinned ARMv7 image libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * The hash specialization @0x190f34 is declared by the frozen header and
 * DEFINED by gc_root_lookup.cpp; it is called, never redefined here, so the
 * pair has one strong definition each. RemoveRoot is not IsRoot: it calls the
 * real CompareKeys on every hash match (0x19126c, first slot included, since
 * 0x191214 b 0x19125c enters the shared test), gates the found exit with the
 * wrapping -1 check on the hit path itself (0x19127c), and deletes by
 * backward-shift backfill plus hash-word clear and count--. No value-address
 * gate, no IsRoot-style fast first-slot path. gap: faults, unwind/exceptions
 * and concurrency remain unproved (as in the seam).
 */

/* 0x190f48: subs r3,r1,r0 / rsbs r0,r3,#0 / adcs r0,r0,r3.
 * rsbs sets C iff r3==0 (0 -u r3 borrows for any r3>0), so the adcs yields
 * exactly 1 when the two pointer words compare equal, 0 otherwise: pointer
 * identity via 32-bit wrapping difference, no field is read. noinline keeps
 * the real external-call edge of 0x19126c under -O2. */
template <>
__attribute__((noinline)) bool
CHashMapCompareKeys<YYObjectBase *>(YYObjectBase *slotKey,
                                   YYObjectBase *probeKey) {
    const uint32_t diff =
        reinterpret_cast<uint32_t>(probeKey) - reinterpret_cast<uint32_t>(slotKey);
    return diff == 0u;
}

/* 0x1911c8 _ZN13CGCGeneration10RemoveRootEP12YYObjectBase.
 * The original checks only obj for null (0x1911cc/0x1911d8): no rootMap or
 * entries guard exists in the window and none is added. Index/address
 * arithmetic is kept in uint32_t wrapping form; map/entries/mask/capacity are
 * re-read live exactly where the original reloads them, and the held
 * this->rootMap word (0x1911e0) is read BEFORE the hash call that follows. */
void CGCGeneration::RemoveRoot(YYObjectBase *obj) {
    if (obj == nullptr) return;                                        // 0x1911d8 beq -> epilogue
    const volatile CGCGeneration &self = *this;
    volatile GCGenRootMapHeader *const map = self.rootMap;             // 0x1911e0 ldr r6,[r3]: HELD before the hash call; not const-qualified because the tail writes +4 (0x191348)
    uint32_t hash = CHashMapCalculateHash(obj);                        // 0x1911e4 bl 0x190f34: real call edge
    uint32_t mask = map->mask;                                         // 0x1911e8 ldr +8 AFTER the call
    uint32_t entries = reinterpret_cast<uint32_t>(map->entries);       // 0x1911ec ldr +10 after the call, same held map
    hash &= 0x7fffffffu;                                               // 0x1911f0 bic r0,r0,#0x80000000
    uint32_t index = hash & mask;                                      // 0x1911f4 and r4,sl,r3
    uint32_t slot = entries + index * 12u;                             // 0x1911f8..191200 lsl#1/add/add lsl#2 = entries+idx*12
    uint32_t slotHash = *reinterpret_cast<const volatile GCRootHashWord *>(slot + 8u); // 0x191204 first read: slot+8 hash only
    if (slotHash == 0u) return;                                        // 0x191208/0c hash word 0 = empty slot, absent
    uint32_t probe = 0u;                                               // 0x191210 mov r8,#0
    for (;;) {                                                         // 0x191214 b 0x19125c: first slot joins the shared test
        if (slotHash == hash) {                                        // 0x19125c cmp sl,r7: slot-hash equality tested FIRST
            YYObjectBase *slotKey =                                    // 0x191264 ldr r0,[r2]: real key word at slot+0
                *reinterpret_cast<YYObjectBase *volatile *>(slot);
            if (CHashMapCompareKeys<YYObjectBase *>(slotKey, obj))     // 0x19126c bl 0x190f48: the real CompareKeys edge
                break;                                                 // 0x191278 bne -> 0x19127c (found)
            mask = map->mask;                                          // 0x191274 ldreq: live reload ONLY on the false-call edge
        }
        const uint32_t capacity = map->capacity;                       // 0x191218 ldr r2,[r6]: live reload per probe step
        const uint32_t distance =                                      // 0x19121c..30 and/add(191224)/rsb/and, 32-bit wrap
            (index + capacity - (slotHash & mask)) & mask;             //   home = storedHash & mask, using the OLD index
        index = (index + 1u) & mask;                                   // 0x191220/28 add#1/and: advance before the signed test
        if (static_cast<int32_t>(distance) < static_cast<int32_t>(probe)) // 0x191238/44 cmp/blt: SIGNED distance < probe
            return;                                                    //   ordered entry cannot lie further ahead
        probe += 1u;                                                   // 0x191240
        entries = reinterpret_cast<uint32_t>(map->entries);            // 0x191248 ldr +10: live reload on the continue edge
        slot = entries + index * 12u;                                  // 0x19123c/4c 3*index then lsl #2
        slotHash = *reinterpret_cast<const volatile GCRootHashWord *>(slot + 8u); // 0x191250
        if (slotHash == 0u) return;                                    // 0x191254/58 empty slot reached: absent
    }

    /* Found at `index`. 0x19127c cmn r4,#1 / 0x191280 beq: exits without any
     * write when index+1 wraps to 0 (index == 0xFFFFFFFF), which a masked
     * index can only produce with mask == 0xFFFFFFFF. Restored literally; it
     * gates the backfill below, and unlike IsRoot (whose guard sits inside the
     * collision-hit branch at 0x1911a0) this one guards every found exit. */
    if (static_cast<int32_t>(index) == -1) return;                     // 0x19127c/80
    mask = map->mask;                                                  // 0x191284 ldr ip,+8: live reload
    entries = reinterpret_cast<uint32_t>(map->entries);                // 0x19128c ldr sl,+10: reload; stays the table base through 0x19133c
    uint32_t src = (index + 1u) & mask;                                // 0x191288/90 r0
    uint32_t srcSlot = entries + src * 12u;                            // 0x191294/98 r1
    uint32_t srcHash = *reinterpret_cast<const volatile GCRootHashWord *>(srcSlot + 8u); // 0x19129c r2
    uint32_t hole = index;                                             // 0x191354 mov r0,r4: no-move tails clear the found slot
    if (srcHash != 0u) {                                               // 0x1912a0/a4 cmp/beq -> tail: next slot empty
        const uint32_t capacity = map->capacity;                       // 0x1912a8 ldr+0; spilled to [sp] once, re-read from the spill at 0x1912f0
        const uint32_t rawDistance = capacity + src - (srcHash & mask);// 0x1912b0..bc and/add/rsb: NOT masked before the test
        if ((rawDistance & mask) != 0u) {                              // 0x1912c0 tst r3,ip / 0x1912cc: next entry not in its home slot -> backfill
            uint32_t dest = index;                                     // 0x1912e0 r5+r4 = 3*found-index on the first pass
            for (;;) {                                                 // 0x1912d8 -> 0x1912dc
                const uint32_t nextSrc = (src + 1u) & mask;            // 0x1912dc/e4 r3
                const uint32_t destSlot = entries + dest * 12u;        // 0x1912e0/ec r6 = sl+(2*dest+dest)*4
                YYObjectBase *key =                                    // 0x1912e8 ldr fp,[r1]: key word of the moved entry
                    *reinterpret_cast<YYObjectBase *volatile *>(srcSlot);
                *reinterpret_cast<volatile GCRootHashWord *>(destSlot + 8u) = srcHash; // 0x1912fc str r2,[r6,#8]: hash stored FIRST
                *reinterpret_cast<YYObjectBase *volatile *>(destSlot) = key;            // 0x191304 str fp: key
                YYObjectBase *value =                                  // 0x19130c ldr r7,[r1,#4]: value word read from the source
                    *reinterpret_cast<YYObjectBase *volatile *>(srcSlot + 4u);
                const uint32_t nextSlot = entries + nextSrc * 12u;     // 0x191310 r1 walks to the next candidate
                const uint32_t nextHash =                              // 0x191314 r2
                    *reinterpret_cast<const volatile GCRootHashWord *>(nextSlot + 8u);
                *reinterpret_cast<YYObjectBase *volatile *>(destSlot + 4u) = value;    // 0x191318 str r7,[r6,#4]: value stored LAST
                dest = src;                                            // 0x191308 mov r4,r0: this pass's source becomes the next hole
                if (nextHash == 0u) {                                  // 0x19131c/cmp + 0x191328 bne fallthrough -> 0x19132c
                    hole = src;                                        //   stop: clear the slot just moved out of
                    break;
                }
                const uint32_t nextDistance =                          // 0x191320..24 and/rsb, same unwrapped shape
                    capacity + nextSrc - (nextHash & mask);
                if ((nextDistance & mask) == 0u) {                     // 0x1912d0 tst r8,ip / 0x1912d4 beq
                    hole = src;                                        //   next entry is in its home slot: stop here
                    break;
                }
                src = nextSrc;                                         // 0x1912d8 mov r0,r3: keep shifting the chain left
                srcSlot = nextSlot;
                srcHash = nextHash;
            }
        }
    }
    const uint32_t count = map->count;                                 // 0x191334 ldr +4: live read AFTER the moves
    *reinterpret_cast<volatile GCRootHashWord *>(entries + hole * 12u + 8u) = 0u; // 0x191344 str #0,[r0,#8]: hash word cleared FIRST
    map->count = count - 1u;                                           // 0x191348 then count-- (wrapping write-back)
}
