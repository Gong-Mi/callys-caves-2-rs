#include "object_alloc_internal.hpp"

/* YYObjectBase::Alloc / InternalGetYYVar + ordinary hash / YYRealloc helpers,
 * original C++ static/members and ordinary C++ helpers recovered from the fixed ARMv7
 * image SHA-256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a:
 * _ZN12YYObjectBase5AllocEjib 0x19198c..0x191bac (544B, 136 words, body SHA256
 * 51a61e17...), _ZN12YYObjectBase16InternalGetYYVarEi 0x196a70..0x196b84 (276B,
 * 69 words, 742f0d4d...), _Z21CHashMapCalculateHashi 0x1b6e44 (8B, 2 words),
 * _Z9YYReallocPvi 0xcef64..0xcef90 (44B, 11 words, ab501b8f...).
 * Per-instruction ownership: intake scratch cally-loop-alloc-grow-qd9m4jup
 * original-0x*.asm.txt / index-0x*.tsv. tier: bytecode_anchored.
 * The nominal empty YYObjectBase is never new/deleted: the fresh path asks the
 * original operator new (0x27c524) for exactly 100 bytes and runs the real C1
 * ABI on that raw storage; the 256B constructor body (0x19188c), GetRValue
 * (0x190dc0), AllocVars (0x1917dc) and CHashMap<int,RValue*,3>::Insert
 * (0x196408) stay the named debt of their own lines and are called, not stubbed.
 * gap: complete class/object layout and lifetime, bad/cyclic input, faults,
 * concurrency and unwind are unproved; no equivalence claim against the machine
 * code beyond the anchored words. Wire access below is raw word I/O.
 */

/* _Z21CHashMapCalculateHashi 0x1b6e44: "add r0,r0,#1; bx lr". This is the
 * ordinary overloaded function, NOT a template specialization: plain uint32
 * id+1 wraparound, no mask, and the header pins noinline so callers keep the
 * real call edge. */
unsigned int CHashMapCalculateHash(int id) {
    return static_cast<unsigned int>(id) + 1u; /* 0x1b6e44 */
}

/* _Z9YYReallocPvi 0xcef64: str lr,[sp,#-4]!; sub sp,#12; the stack fifth
 * argument is zero at 0xcef74..0xcef74 (str r3,[sp], r3=#0); line is 0x512 =
 * 1298 (movw r3,#0x512 @0xcef78); tag is the pc-relative string at
 * vaddr 0x332204, verified byte-for-byte in the pinned image; r1 (the int
 * bytes argument) is forwarded to the unsigned size parameter with no
 * conversion at all; r0 returns straight to the caller. */
void *YYRealloc(void *buffer, int bytes) {
    return MemoryManager::ReAlloc(
        buffer, static_cast<unsigned int>(bytes),
        "jni/../jni/yoyo/../../../Files/Code/Code_Main.cpp", 1298, false);
}

/* _ZN12YYObjectBase5AllocEjib 0x19198c — static YYObjectBase *
 * Alloc(unsigned int requested, int tag, bool needDense).
 * Pool head ms_pFreeList is read through its GOT slot at 0x19198c..0x1919a0;
 * that is the same _ZN12YYObjectBase12ms_pFreeListE object_free.cpp pushes,
 * so the recycle path below consumes the exact producer, no invented pool. */
YYObjectBase *YYObjectBase::Alloc(unsigned int requested, int tag,
                                  bool needDense) {
    YYObjectBase *object = object_state::freeList; /* ldr r3,[pc,r3]; r5=[r3] 0x1919a0 */
    if (object != nullptr) {
        /* 0x1919b4..0x1919c4 recycle path: capacity/+08 reads first, the
         * freeList republish is unconditional here (str before the branch),
         * then the UNSIGNED old-capacity < requested grow test. */
        const uint32_t self = object_wire::address(object);
        const uint32_t heldCapacity = object_wire::read(self, 0x2cu); /* 0x1919b4 */
        const uint32_t next = object_wire::read(self, 0x08u);         /* 0x1919b8 */
        object_state::freeList =                                      /* 0x1919c0 */
            reinterpret_cast<YYObjectBase *>(static_cast<uintptr_t>(next));
        if (heldCapacity < requested) {                               /* blo 0x1919c4 */
            object_wire::write(self, 0x2cu, requested);               /* 0x191ab8 */
            if (needDense) {                                          /* 0x191abc */
                /* Live +0x04 read AFTER the call-site setup, requested<<4
                 * wraps as the unsigned size, tag vaddr 0x331038 verified,
                 * line #74 (mov r3,#0x4a), stack bool zero (str r3,[sp]). */
                void *dense = reinterpret_cast<void *>(static_cast<uintptr_t>(
                    object_wire::read(self, 0x04u)));                 /* 0x191ac8 */
                dense = MemoryManager::ReAlloc(
                    dense, requested << 4,
                    "jni/../jni/yoyo/../../../Platform/MemoryManager.h",
                    74, false);                                       /* bl 0x27cedc */
                object_wire::write(self, 0x04u,
                                   object_wire::address(dense));      /* 0x191ae0 */
            }
        }
        /* 0x1919c8 shared recycled reset: +24 = requested, +58 = tag,
         * +48 = 0, published in that order on every non-fresh path. */
        object_wire::write(self, 0x24u, requested);
        object_wire::write(self, 0x58u, static_cast<uint32_t>(tag));
        object_wire::write(self, 0x48u, 0u);                          /* 0x1919d8 */
        if (tag != 5) {                        /* cmp #5; beq 0x191a08 0x1919dc */
            const uint32_t dense = object_wire::read(self, 0x04u);    /* 0x1919e0 */
            /* live dense non-null AND signed requested > 0 gate the writes;
             * the loop is the SUBS count-- edge (0x1919f8..0x191a04), not a
             * pointer-null walk: exactly `requested` 16-byte strides, each
             * writing only kind at +0x0c. */
            if (dense != 0u && static_cast<int32_t>(requested) > 0) { /* 0x1919e8/0x1919f4 */
                for (uint32_t i = 0u; i != requested; ++i) {
                    object_wire::write(dense, (i << 4) + 0xcu,
                                       static_cast<uint32_t>(tag));
                }
            }
        }
    } else {
        /* 0x191b2c..0x191b44 fresh path: operator new(100) exact size, real
         * C1 ABI (r1 = requested bits, r2 = tag) on the raw storage, then the
         * branch lands directly on ensure-dense — the recycled reset block is
         * NOT run and no extra fields are cleared or written here; whatever
         * the unresolved constructor initialized stays. */
        object = static_cast<YYObjectBase *>(operator new(100u));     /* 0x27c524 */
        constructYYObjectBaseRaw(object, static_cast<int>(requested), tag);
    }

    const uint32_t self = object_wire::address(object);

    /* 0x191a08 ensure-dense, common to both paths: only needDense and a
     * STILL-live +0x04 == 0 reach the NULL ReAlloc (this re-runs the grow on a
     * failed realloc above instead of returning early). On return +2c and +4
     * publish FIRST, then tag!=5 && grown!=0 gates the write loop whose count
     * is the LIVE obj+0x24 reload (0x191b78) — different source than the
     * earlier requested register, kept as such. With needDense false the
     * metadata capacity can still grow above the old buffer (earlier blo
     * branch) and the tag may be written beyond it: original behaviour, no
     * safety guard is added. */
    if (needDense && object_wire::read(self, 0x04u) == 0u) {          /* 0x191a08..0x191a18 */
        void *grown = MemoryManager::ReAlloc(                         /* 0x191b48: r0 live == 0 */
            nullptr, requested << 4,
            "jni/../jni/yoyo/../../../Platform/MemoryManager.h", 74, false);
        object_wire::write(self, 0x2cu, requested);                   /* 0x191b64 */
        object_wire::write(self, 0x04u, object_wire::address(grown)); /* 0x191b68 */
        const uint32_t grownAddr = object_wire::address(grown);
        if (tag != 5 && grownAddr != 0u) {                            /* 0x191b6c/0x191b74 */
            const uint32_t denseCount = object_wire::read(self, 0x24u); /* LIVE 0x191b78 */
            if (static_cast<int32_t>(denseCount) > 0) {               /* ble 0x191a1c */
                for (uint32_t i = 0u; i != denseCount; ++i) {         /* subs 0x191b84 */
                    object_wire::write(grownAddr, (i << 4) + 0xcu,
                                       static_cast<uint32_t>(tag));
                }
            }
        }
    }

    /* 0x191a1c..0x191a2c registry: the inline 16B g_slotObjects is reached
     * through GOT and ldmib loads the capacity/count pair (+4/+8) together.
     * The occupancy test is a SIGNED compare (bge), grow happens at most
     * once, and after the grow the scan is entered directly — the
     * count>=capacity test is never re-run. */
    uint32_t capacity = liveObjectSlots().capacity;                       /* 0x191a24 LDMIB r6,{r4,r7}: +4 */
    uint32_t heldCount = liveObjectSlots().count;                         /* same LDMIB snapshot: +8 */
    if (static_cast<int32_t>(heldCount) >= static_cast<int32_t>(capacity)) {
        /* 0x191ae8..0x191af4: newcap = arshift1(wrap(3*cap) + (wrap(3*cap) lsr
         * 31)) — division by 2 of the wrapped 3x toward zero. NOT a signed
         * multiply-and-shift or floating 1.5x; cap 0 yields 0, no min cap. */
        uint32_t three = capacity * 3u;                               /* add r4,r4,r4,lsl#1 wraps */
        three = three + (three >> 31);                                /* add r4,r4,r4,lsr#31 */
        const uint32_t newCap = (three >> 1) | (three & 0x80000000u); /* defined ASR #1 bit image */
        YYObjectBase *volatile *const liveSlots = liveObjectSlots().slots; /* ldr r0,[r6] 0x191aec */
        void *grownSlots = YYRealloc(                                 /* bl 0xcef64 */
            reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(liveSlots)),
            static_cast<int>(static_cast<uint32_t>(newCap) << 2));    /* lsl r1 0x191af8 */
        /* 0x191b04: OLD capacity is re-read LIVE after the call; slots publish
         * before memset; tail address and length are the wrapping word adds;
         * count is re-read LIVE after memset returns, then capacity=newCap. */
        const uint32_t oldCapLive = liveObjectSlots().capacity;
        liveObjectSlots().slots =
            reinterpret_cast<YYObjectBase *volatile *>(grownSlots);   /* 0x191b14 */
        const uint32_t grownBase = object_wire::address(grownSlots);
        memset(reinterpret_cast<void *>(static_cast<uintptr_t>(grownBase + (oldCapLive << 2))),
               0, static_cast<size_t>((static_cast<uint32_t>(newCap) - oldCapLive) << 2));
        heldCount = liveObjectSlots().count;                              /* 0x191b20 LIVE */
        liveObjectSlots().capacity = static_cast<uint32_t>(newCap);       /* 0x191b24 */
        capacity = static_cast<uint32_t>(newCap);                     /* mov r4,r8 */
    }

    /* 0x191a30..0x191a80 scan: firstFree at +0xc is read even when the signed
     * capacity is <= 0 (then index = -1 straight away); the slots base is only
     * touched when signed capacity > 0. index starts at the RAW firstFree
     * bits — negative values are not normalized to zero; only signed
     * capacity <= index clamps the current index to 0 for this probe, and the
     * slot address is wrapping u32 arithmetic (0xFFFFFFFC etc. stay live),
     * never C++ negative-pointer arithmetic or a modulo fixup. */
    int32_t index = liveObjectSlots().firstFree;                          /* 0x191a34 */
    if (static_cast<int32_t>(capacity) <= 0) {                         /* ble → 0x191a80 */
        index = -1;
    } else {
        const uint32_t slotBase = static_cast<uint32_t>(              /* 0x191a3c */
            reinterpret_cast<uintptr_t>(liveObjectSlots().slots));
        uint32_t remaining = capacity;                                /* mov r1,r4 0x191a40 */
        for (;;) {
            if (static_cast<int32_t>(capacity) <= index) {            /* movle 0x191a5c */
                index = 0;
            }
            const uint32_t slotOff = static_cast<uint32_t>(index) << 2; /* lsl wraps */
            const uint32_t occupant = object_wire::read(slotBase, slotOff);
            if (occupant == 0u) {                                     /* free hit 0x191a74 */
                object_wire::write(slotBase, slotOff, object_wire::address(object));
                liveObjectSlots().firstFree = index;                      /* 0x191a78 */
                break;
            }
            remaining -= 1u;                                          /* subs 0x191a48 */
            index = static_cast<int32_t>(static_cast<uint32_t>(index) + 1u); /* ARM32 wrap */
            if (remaining == 0u) {                                    /* beq 0x191a50 */
                index = -1;                                           /* mvn 0x191a80 */
                break;
            }
        }
    }

    /* 0x191a84 tail: obj+44 = index (raw bits), obj+38 = 0, registry count =
     * heldCount + 1 (wrapping), then the LIVE _ZN12YYObjectBase17ms_currentCounterE
     * read (0x191aa4, after the count store) is copied to obj+3c unchanged —
     * Alloc never increments the counter. Returns the object in r0. */
    const uint32_t publishCount = heldCount + 1u;                     /* 0x191a88 */
    object_wire::write(self, 0x44u, static_cast<uint32_t>(index));
    object_wire::write(self, 0x38u, 0u);                              /* 0x191a98 */
    liveObjectSlots().count = publishCount;                               /* 0x191aa0 */
    const uint32_t counter = object_state::currentCounter;            /* 0x191aa4 */
    object_wire::write(self, 0x3cu, counter);                         /* 0x191aa8 */
    return object;
}

/* _ZN12YYObjectBase16InternalGetYYVarEi 0x196a70..0x196b84. Robin-Hood
 * CHashMap<int,RValue*,3> probe recovered instruction-for-instruction; the
 * map is the raw 0x60 word view (word00 delta at +0x00, mask at +0x08,
 * buckets at +0x10, 12-byte entries {aux?, value@+4, hashWord@+8}), NOT an
 * instantiated container. Hit verdicts use ONLY state/hash — no key
 * comparison is invented; a hit whose value word is null returns that null
 * (it is not folded into the create path). */
RValue *YYObjectBase::InternalGetYYVar(int id) {
    const uint32_t self = object_wire::address(this);
    uint32_t map = object_wire::read(self, 0x60u);                    /* r4 0x196a78 */
    if (map == 0u) {                                                  /* 0x196a84 */
        AllocVars();                                                  /* 0x196b78 bl 0x1917dc */
        map = object_wire::read(self, 0x60u);                         /* 0x196b7c reload,
                                                                       * no second null guard */
    }
    /* 0x196a8c real call into the ordinary overload at 0x1b6e44. */
    uint32_t hash = CHashMapCalculateHash(id);
    const uint32_t mask = object_wire::read(map, 0x08u);              /* r12 0x196a90 */
    const uint32_t data = object_wire::read(map, 0x10u);              /* r9  0x196a94 */
    hash &= 0x7fffffffu;                           /* bic #-0x80000000 clears sign bit */
    int32_t index = static_cast<int32_t>(mask & hash);                /* r3 0x196a9c */
    /* 0x196aa0..0x196aac: entry = data + (2*index + index) << 2, hash word at +8. */
    uint32_t index3 = (static_cast<uint32_t>(index) << 1) + static_cast<uint32_t>(index);
    uint32_t slotHash = object_wire::read(data, (index3 << 2) + 8u);
    if (slotHash == 0u) {                                             /* 0x196ab4 */
        goto create;
    }
    if (hash == slotHash) {                                           /* 0x196abc */
        goto hit;
    }
    {
        /* 0x196ac0: word00 (r10) is loaded live, only on this probe-miss edge,
         * once before the loop, exactly like the register. */
        const uint32_t word00 = object_wire::read(map, 0x00u);
        /* 0x196ac4..0x196d0: first masked distance (index + word00) -
         * (slotHash & mask); the early-out is the tst/bmi sign of that raw
         * difference AND mask — not a pointer test, not a modulo. */
        const uint32_t dist0 = static_cast<uint32_t>(index) + word00 - (slotHash & mask);
        if (static_cast<int32_t>(dist0 & mask) < 0) {                 /* bmi 0x196ad4 */
            goto create;
        }
        uint32_t round = 0u;                                          /* mov r4,#0 0x196ad8 */
        for (;;) {
            /* 0x196af0..0x196b20 write order: index++, round++, index&=mask,
             * base = data + 3*index words, slot hash load, then the masked
             * distance and the cmp r2,#0 flags consumed by the fall-through. */
            index = static_cast<int32_t>(static_cast<uint32_t>(index) + 1u);
            round += 1u;
            index = static_cast<int32_t>(static_cast<uint32_t>(index) & mask);
            index3 = (static_cast<uint32_t>(index) << 1) + static_cast<uint32_t>(index);
            slotHash = object_wire::read(data, (index3 << 2) + 8u);
            const uint32_t dist =
                (static_cast<uint32_t>(index) + word00 - (slotHash & mask)) & mask;
            if (slotHash != 0u) {                                     /* bne 0x196b20 */
                if (hash == slotHash) {                               /* 0x196ae4 */
                    /* 0x196b54: late "index == -1" is a real create exit. */
                    if (index == -1) {
                        goto create;
                    }
                    goto hit;
                }
                if (static_cast<int32_t>(dist) < static_cast<int32_t>(round)) { /* blt 0x196aec */
                    goto create;
                }
                continue;
            }
            goto create;                                 /* empty bucket (hash word 0) */
        }
    }

hit:
    /* 0x196b5c..0x196b6c: recompute the entry address from the current index;
     * the cmn #4 beq is the wrapped "entry+4 == 0" bucketAddress == -4
     * sentinel routed to create, otherwise load +4 and return it as-is
     * (null included). */
    {
        const uint32_t entry = data + (((static_cast<uint32_t>(index) << 1) +
                                        static_cast<uint32_t>(index)) << 2);
        if (entry + 4u == 0u) {
            goto create;
        }
        return reinterpret_cast<RValue *>(static_cast<uintptr_t>(
            object_wire::read(entry, 4u)));                            /* mov r0,r4; pop 0x196b70 */
    }

create:
    /* 0x196b24..0x196b50: real GetRValue() 0x190dc0 (body owed there), then the
     * slot is prepared low+0 = 0, high+4 = 0, kind = LIVE obj+0x58 read at
     * 0x196b34 BEFORE those stores, auxiliary +8 untouched. The Insert
     * receiver is the LIVE obj+0x60 reload at 0x196b48 (post-call refetch),
     * and the returned RValue is the held r4, not Insert's result. */
    RValue *value = GetRValue();
    const uint32_t valueAddr = object_wire::address(value);
    const uint32_t kind = object_wire::read(self, 0x58u);              /* 0x196b34 */
    object_wire::write(valueAddr, 0x00u, 0u);                          /* 0x196b3c */
    object_wire::write(valueAddr, 0x04u, 0u);                          /* 0x196b40 */
    object_wire::write(valueAddr, 0x0cu, kind);                        /* 0x196b44 */
    const uint32_t mapLive = object_wire::read(self, 0x60u);           /* 0x196b48 */
    reinterpret_cast<CHashMap<int, RValue *, 3> *>(
        static_cast<uintptr_t>(mapLive))->Insert(id, value);           /* bl 0x196408 */
    return value;
}
