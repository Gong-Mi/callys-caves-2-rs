/* tier: bytecode_anchored
 * Original image libyoyo_armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * This TU recovers exactly one body, word-ordered against the full window
 * of its original ARM window:
 *   CGCGeneration::AddRoot  _ZN13CGCGeneration7AddRootEP12YYObjectBase
 *                           0x196210..0x1963fc, 504B span including the
 *                           two tail pool words 0x196400 (F32 0x3f19999a)
 *                           and 0x196404 (pc-relative addend to the
 *                           .rodata path string @0x331038).
 * Structure recovered verbatim: the NULL gate (0x196214-0x196218), the
 * SIGNED count>growThreshold grow entry (0x196228-0x19622c), the
 * pre-increment of count stored BEFORE the real CHashMapCalculateHash edge
 * (0x196230-0x19623c), the hash&~0x80000000 mask and the inline
 * open-addressing probe with the 0x196274 three-field (hash/key/value)
 * displacement swap, the raw pointer key compare at 0x1962dc (NO
 * CHashMapCompareKeys edge exists in this body), the zero-hash empty-slot
 * flag with hash published LAST on every insert (0x196304/0x196308,
 * 0x196260/0x196300), and the tail path (0x196310-0x1963fc): capacity and
 * mask published BEFORE Alloc, entries published after Alloc but BEFORE
 * memset, count cleared at 0x196368, the growThreshold stored
 * UNCONDITIONALLY at 0x19637c before the signed capacity test drives the
 * hash-word clear loop, the per-slot rehash through the CANONICAL
 * map->Insert(key,value) real dependency at 0x1963c8 (body 0x195ba8 stays
 * with its own line; this TU keeps the undefined reference), the
 * unconditional MemoryManager::Free of the OLD entries at 0x1963dc, the
 * second growThreshold recompute at 0x1963f8 from the live capacity word
 * with the live count (0x1963ec) held across it, and the fall-back into
 * the fast path at 0x196230 with that held count and NO second threshold
 * test.
 * gap: faults (Alloc/memset/Free/Insert edges, NULL this->rootMap, the
 * hash-0 entry colliding with the empty marker is original behaviour),
 * unwind tables, FPSCR/trap behaviour, concurrency and any
 * equivalence-by-execution claim remain unproved; the original was never
 * run for this recovery.
 */
#include "gc_generation.hpp"

namespace {

typedef uint32_t RawWord __attribute__((may_alias));

/* 12B-stride raw word observation, the seam's precedent (gc_generation.cpp
 * writeRawWord, gc_mutable_roots.cpp readRawWord): no Entry object walk. */
inline void writeRawWord(uint32_t address, uint32_t value) {
    *reinterpret_cast<volatile RawWord *>(static_cast<uintptr_t>(address)) = value;
}
inline uint32_t readRawWord(uint32_t address) {
    return *reinterpret_cast<volatile RawWord *>(static_cast<uintptr_t>(address));
}

/* 0x196404 pool word + pc gives the same .rodata string the seam's Alloc
 * edges publish: "jni/../jni/yoyo/../../../Platform/MemoryManager.h". */
const char memoryManagerHeaderSourcePath[] =
    "jni/../jni/yoyo/../../../Platform/MemoryManager.h";

constexpr int kMapLine = 70;                  /* 0x19631c mov r2, #70 */
constexpr float kGrowRatio = 0x1.333334p-1f;  /* pool 0x196400 = 0x3f19999a */
constexpr uint32_t kEntryStride = 12u;        /* (i+i<<1)<<2 addressing */

} // namespace

void CGCGeneration::AddRoot(YYObjectBase *obj) {
    /* 0x196214-0x196218: the NULL gate on the argument itself; pops and
     * returns before rootMap is even read. */
    if (obj == nullptr) {
        return;
    }
    volatile CGCGeneration &self = *this;
    GCGenRootMapHeader *const map = self.rootMap; /* 0x19621c ldr r8, [r0] */
    volatile GCGenRootMapHeader &live = *map;

    uint32_t count = live.count;                  /* 0x196220 r3 */
    /* 0x196224-0x19622c: SIGNED count > growThreshold entry (cmp/bgt). */
    if (static_cast<int32_t>(count) >
        static_cast<int32_t>(live.growThreshold)) {
        /* 0x196310-0x1963dc: growth tail. old capacity (0x196310) and old
         * entries (0x196320) are each taken exactly once, live. */
        const uint32_t oldCapacity = live.capacity;      /* 0x196310 r6 */
        GCRootMapEntry *const oldEntries = live.entries; /* 0x196320 r9 */
        const uint32_t newCapacity = oldCapacity << 1u;  /* 0x196324 lsl r3=1 */
        live.capacity = newCapacity;                     /* 0x196330 BEFORE Alloc */
        live.mask = newCapacity - 1u;                    /* 0x196334-0x196338 */
        /* 0x19632c add r4,r0,r6 lsl #2 + 0x19633c lsl r4,#2: the original
         * (newCap + oldCap*4)*4 u32-wrapping shape — numerically 12*newCap
         * since newCap == 2*oldCap, kept in the original arithmetic. */
        const uint32_t bytes =
            (newCapacity + (oldCapacity << 2u)) << 2u;
        /* 0x196344: real Alloc(size, path@0x331038, 70, true) edge
         * (r3=#1 double-duty as shift amount and the bool argument). */
        void *const held = MemoryManager::Alloc(
            bytes, memoryManagerHeaderSourcePath, kMapLine, true);
        live.entries = static_cast<GCRootMapEntry *>(held); /* 0x196350 publish BEFORE memset */
        memset(held, 0, bytes);                             /* 0x196354 real libc import */

        /* 0x196358-0x19637c: LIVE capacity reload after the calls; count
         * cleared at 0x196368; growThreshold = trunc(f32(capacity)*0.6f)
         * (vcvt.f32.s32 / vmul / vcvt.s32.f32, -ffp-contract=off) stored
         * UNCONDITIONALLY before the signed test picks the clear loop. */
        const int32_t capWord = static_cast<int32_t>(live.capacity); /* 0x196358 */
        live.count = 0u;                                             /* 0x196368 */
        live.growThreshold =
            static_cast<int32_t>(static_cast<float>(capWord) * kGrowRatio); /* 0x19637c */
        /* 0x196380 ble: signed capacity <= 0 skips the hash-word clear. */
        if (capWord > 0) {
            /* 0x196384-0x19639c: do/while over the LIVE entries word
             * (0x196388 re-read) with u32 wrapping end arithmetic
             * cap*3<<2; each 12B entry gets ONLY its +0x08 word zeroed. */
            const uint32_t begin = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(live.entries));
            const uint32_t end =
                begin + (static_cast<uint32_t>(capWord) +
                         (static_cast<uint32_t>(capWord) << 1u)) *
                            4u;
            uint32_t cursor = begin;
            do {
                writeRawWord(cursor + 8u, 0u); /* 0x196390 str r1, [r3, #8] */
                cursor += kEntryStride;        /* 0x196394 add r3, r3, #12 */
            } while (cursor != end);           /* 0x196398-0x19639c cmp/bne */
        }

        /* 0x1963a0-0x1963d4: rehash the OLD table only when oldCapacity is
         * SIGNED positive; index++ sits BEFORE the skip branch, exactly as
         * the original add r5,r5,#1 at 0x1963b8. */
        if (static_cast<int32_t>(oldCapacity) > 0) {
            uint32_t cursor = static_cast<uint32_t>(
                reinterpret_cast<uintptr_t>(oldEntries));
            uint32_t index = 0u;
            do {
                const uint32_t heldHash =
                    readRawWord(cursor + 8u);      /* 0x1963b0 ldr r3,[r4,#8] */
                index += 1u;                       /* 0x1963b8 add r5,r5,#1 */
                /* 0x1963bc-0x1963c0: SIGNED cmp/ble — only hash > 0 (the
                 * zero flag marks an empty slot) re-enters the map. */
                if (static_cast<int32_t>(heldHash) > 0) {
                    /* 0x1963c4 ldm r4,{r1,r2}: key/value raw words; 0x1963c8
                     * the CANONICAL map->Insert dependency (0x195ba8, body
                     * owed to its own line — real undefined reference, no
                     * stub here). */
                    YYObjectBase *const key = reinterpret_cast<YYObjectBase *>(
                        static_cast<uintptr_t>(readRawWord(cursor)));
                    YYObjectBase *const value = reinterpret_cast<YYObjectBase *>(
                        static_cast<uintptr_t>(readRawWord(cursor + 4u)));
                    map->Insert(key, value);
                }
                cursor += kEntryStride;            /* 0x1963d0 add r4,r4,#12 */
            } while (index != oldCapacity);        /* 0x1963cc cmp r5,r6/bne */
        }
        /* 0x1963d8-0x1963dc: Free(old entries) UNCONDITIONALLY (also on the
         * oldCapacity <= 0 and never-allocated paths; fault behaviour
         * unproved). The held pointer is the 0x196320 one-time read. */
        MemoryManager::Free(oldEntries);

        /* 0x1963e0/0x1963ec: after Free, read the live capacity FIRST,
         * then the live count. Keep both snapshots through the threshold
         * store before re-entering the fast path, without re-testing it. */
        const int32_t postFreeCapacity = static_cast<int32_t>(live.capacity);
        count = live.count;
        live.growThreshold = static_cast<int32_t>(
            static_cast<float>(postFreeCapacity) * kGrowRatio);
    }

    /* 0x196230-0x196238: pre-increment (u32 wrapping) stored to +0x04
     * BEFORE the hash edge; a found-existing key undoes it below. */
    count += 1u;
    live.count = count;

    /* 0x19623c: the REAL pointer hash call (0x190f34), then 0x196248 bic
     * clearing bit 31 — the stored-hash domain the zero flag lives in. */
    uint32_t pendingHash = CHashMapCalculateHash<YYObjectBase *>(obj);
    pendingHash &= 0x7fffffffu;
    const uint32_t mask = live.mask;               /* 0x196240 r5 */
    GCRootMapEntry *const entries = live.entries;  /* 0x196244 r9 */
    const uintptr_t base = reinterpret_cast<uintptr_t>(entries);
    const auto slotAt = [base](uint32_t index) {
        return reinterpret_cast<volatile GCRootMapEntry *>(base + index * kEntryStride);
    };
    uint32_t i = pendingHash & mask;               /* 0x19624c r3 */
    volatile GCRootMapEntry *entry = slotAt(i);  /* 0x196250-0x196254 */
    uint32_t ip = entry->hash;                     /* 0x196258 ip */
    if (ip == 0u) {
        /* 0x196260 -> 0x196300/0x196304: empty slot on the FIRST probe;
         * stm {r1=r7=obj} key/value, then hash last. */
        entry->key = obj;
        entry->value = obj;
        entry->hash = pendingHash;
        return;
    }

    /* 0x196264-0x196270: capacity becomes live only after the first probe
     * missed; the pending triple starts as (obj, obj, maskedHash) with
     * distance 0. */
    const uint32_t capacity = live.capacity;
    YYObjectBase *pendingKey = obj;    /* r1 */
    YYObjectBase *pendingValue = obj;  /* r7 (unchanged since the gate) */
    uint32_t dist = 0u;                /* r6 */
    for (;;) {
        /* 0x1962b4-0x1962c0: occupant probe distance
         * ((capacity + i) - (ip & mask)) & mask, u32 wrapping. */
        uint32_t odist = (capacity + i) - (ip & mask);
        odist &= mask;
        if (static_cast<int32_t>(odist) < static_cast<int32_t>(dist)) {
            /* 0x196274-0x196290: the displacement swap — reads first,
             * then stores in ORIGINAL order hash, key, value; the
             * displaced triple (ip, key, value) continues probing. */
            YYObjectBase *const displacedKey = entry->key;    /* 0x196274 */
            YYObjectBase *const displacedValue = entry->value;/* 0x196278 */
            entry->hash = pendingHash;                        /* 0x19627c */
            pendingHash = ip;                                 /* 0x196280 */
            entry->key = pendingKey;                          /* 0x196284 */
            pendingKey = displacedKey;                        /* 0x196288 */
            entry->value = pendingValue;                      /* 0x19628c */
            pendingValue = displacedValue;                    /* 0x196290 */
            /* fall into the advance at 0x196294 with the ORIGINAL odist */
        } else if (odist != dist) {
            /* 0x1962cc movne r4, r6 + 0x1962d0 bne: odist := dist, advance */
            odist = dist;
        } else if (ip != pendingHash || pendingKey != entry->key) {
            /* 0x1962d4-0x1962e4: equal distance, different hash OR
             * different key (RAW pointer compare — the original has no
             * CHashMapCompareKeys edge) both branch to the same advance. */
        } else {
            /* 0x1962e8-0x1962f8: existing key — reload count LIVE
             * (0x1962e8), overwrite key/value (0x1962ec stm), store the
             * occupant's own hash (0x1962f4, equal in value to
             * pendingHash) and UNDO the pre-increment (0x1962f0/0x1962f8). */
            const uint32_t fresh = live.count;
            entry->key = pendingKey;
            entry->value = pendingValue;
            entry->hash = ip;
            live.count = fresh - 1u;
            return;
        }
        /* 0x196294-0x1962a8: advance with wrapping index and dist=odist+1. */
        i = (i + 1u) & mask;
        dist = odist + 1u;
        entry = slotAt(i);
        ip = entry->hash;
        if (ip == 0u) {
            /* 0x1962b0 -> 0x196304: empty slot on an ADVANCED probe; the
             * pending triple may have changed through swaps — no
             * 0x196300 mov r1,r7 re-entry here. */
            entry->key = pendingKey;
            entry->value = pendingValue;
            entry->hash = pendingHash;
            return;
        }
    }
}
