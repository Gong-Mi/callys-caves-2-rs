#include "gc_generation.hpp"

// Observe exactly the slot-hash word; no key or value is fetched on a hit.
typedef uint32_t GCRootHashWord __attribute__((may_alias));

/* Short-batch A: CGCGeneration::IsRoot @0x1910e8 (window 0x1910e8..0x1911c8,
 * 224B) plus only the pointer-hash specialization it actually calls,
 * _Z21CHashMapCalculateHashIP12YYObjectBaseEjT_ @0x190f34 (12B). Pinned ARMv7
 * image libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * The int instantiation @0x190f40 and _Z19CHashMapCompareKeysIP12YYObjectBaseEbT_S2_
 * @0x190f48 belong to other lines: the IsRoot body never calls CompareKeys and
 * never reads a value/key word on hit, so neither is declared or emitted here.
 * gap: faults, unwind/exceptions and concurrency remain unproved (as in the seam).
 */

template <typename KeyType> uint32_t CHashMapCalculateHash(KeyType key);

/* 0x190f34: asr r0,r0,#8 ; add r0,r0,#1 ; bx lr.
 * ASR is an ARITHMETIC shift (sign-extending), not a logical one; for keys with
 * bit31 set the result differs. noinline keeps the real external-call edge of
 * 0x191100 (bl 0x190f34) under -O2 instead of inlining the probe helper. */
template <>
__attribute__((noinline)) uint32_t
CHashMapCalculateHash<YYObjectBase *>(YYObjectBase *key) {
    const int32_t asSigned = reinterpret_cast<int32_t>(key);
    return static_cast<uint32_t>(asSigned >> 8) + 1u;
}

/* 0x1910e8 _ZN13CGCGeneration6IsRootEP12YYObjectBase.
 * 12B-slot open-addressed rootMap; slot+8 is the stored hash (the only word C1
 * clears), slot+4 is the value word whose ADDRESS (not content) decides the
 * result on hash equality. Address arithmetic is kept in uint32_t because the
 * original probes with 32-bit wrapping adds (0x19113c..40 rsb / 0x1911a8..b0).
 * The original checks only obj for null: no rootMap/entries null guard exists
 * in 0x1910e8..0x1911c8, and none is added here. */
bool CGCGeneration::IsRoot(YYObjectBase *obj) {
    if (obj == nullptr) return false;                                // 0x1910e8 cmp r1,#0 / 0x1910f8 beq
    const volatile CGCGeneration &self = *this;
    const volatile GCGenRootMapHeader *const map = self.rootMap;                         // 0x1910fc ldr r5,[r3]: map HELD BEFORE the hash call
    uint32_t hash = CHashMapCalculateHash(obj);                      // 0x191100 bl 0x190f34: real call edge
    const uint32_t mask = map->mask;                                 // 0x191104 ldr +8 AFTER the call
    const uint32_t entries = reinterpret_cast<uint32_t>(map->entries); // 0x191108 ldr +10 after the call, same held map
    hash &= 0x7fffffffu;                                             // 0x19110c bic r0,r0,#0x80000000
    uint32_t index = hash & mask;                                    // 0x191110 and r3,r0,r1
    uint32_t slot = entries + index * 12u;                           // 0x191114..1c lsl#1/add/add lsl#2 = entries+idx*12
    uint32_t slotHash = *reinterpret_cast<const volatile GCRootHashWord *>(slot + 8u); // 0x191120 first read: slot+8 hash only
    if (slotHash == 0u) return false;                                // 0x191124/28 hash word 0 = empty slot, immediate miss
    if (hash == slotHash) return (slot + 4u) != 0u;                  // 0x19112c..30 first-slot hit goes straight to 0x1911a8: NO -1 guard
    const uint32_t capacity = map->capacity;                         // 0x191134 ldr +0: read only on the collision path
    uint32_t distance = (index + capacity - (slotHash & mask)) & mask; // 0x191138..40 and/add/rsb, 32-bit wrap
    if (static_cast<int32_t>(distance) < 0) return false;            // 0x191144 tst r2,r1 + 0x191148 bmi: TOP BIT ONLY, not "any nonzero"
    uint32_t probe = 0u;                                             // 0x19114c mov ip,#0
    for (;;) {                                                       // 0x191150 b 0x191164
        index = (index + 1u) & mask;                                 // 0x191164..6c add#1/add#1/and: wrap
        probe += 1u;
        slot = entries + index * 12u;                                // 0x191170..7c
        slotHash = *reinterpret_cast<const volatile GCRootHashWord *>(slot + 8u);   // 0x191180
        distance = (index + capacity - (slotHash & mask)) & mask;    // 0x191184..90 and/rsb/and
        if (slotHash == 0u) return false;                            // 0x191188 cmp #0 + 0x191194 bne fallthrough -> 0x191198
        if (hash == slotHash) {                                      // 0x191154..58: slot-hash equality tested FIRST
            if (static_cast<int32_t>(index) == -1) return false;     // 0x1911a0 cmn r3,#1: exists only on this collision-hit branch
            return (slot + 4u) != 0u;                                // 0x1911a8..b4 adds r0,#4/movne r0,#1: value ADDRESS nonzero
        }
        if (static_cast<int32_t>(distance) < static_cast<int32_t>(probe)) return false; // 0x19115c..60 cmp/blt: SIGNED distance < probe
    }
}
