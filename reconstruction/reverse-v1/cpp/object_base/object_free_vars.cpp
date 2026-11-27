#include "object_internal.hpp"

/* YYObjectBase::FreeVars: original C++ static member
 * _ZN12YYObjectBase8FreeVarsEPS_PP6RValueS3_PP9RVariableS6_ at
 * 0x198dac..0x198f88 (117 instructions + 2 literal-pool words, 476 bytes).
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Per-instruction ownership: intake scratch cally-loop-object-u32-fmv_pr30
 * original-0x198dac.asm.txt / index-0x198dac.tsv (body SHA256 3fc0ad1a...).
 * Internal dependencies are real declarations with calls, not defaults:
 * FREE_RValue__Pre 0xc0a7c, FreeRValue 0x190e84, MemoryManager::Free 0x27c2d0
 * (body already recovered), ::operator delete 0x27d1d0, and the volatile
 * function-pointer variable pcre_free at 0x3f76dc (two independent GOT-slot
 * reads). The last two RVariable** parameters are never consumed by the
 * original and stay unused here.
 * gap: original fault, concurrency and unwind domains are unproved; RValue
 * elements and buckets are raw word/buffer views, not complete types. No
 * equivalence between this source and the original machine code is claimed.
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
/* ((kind-1) & ~0xFF000000 & ~3) == 0, the exact SUB/BIC/BIC tag window. */
inline bool inTagWindow(uint32_t kind)
{
    return ((kind - 1u) & 0x00FFFFFCu) == 0u;
}
}

void YYObjectBase::FreeVars(YYObjectBase *object,
                            RValue **heldOut1, RValue **heldOut2,
                            RVariable ** /* r3: never consumed */,
                            RVariable ** /* [sp]: never consumed */)
{
    const uint32_t self = object_wire::address(object);

    /* Dense RValue table block, 0x198db4..0x198e30. obj+0x24 (signed count)
     * is only read when obj+0x04 is non-null; a null table skips the whole
     * block and does NOT clear +0x04/+0x2C/+0x24 afterwards. */
    uint32_t table = object_wire::read(self, 0x04u);
    if (table != 0u) {
        const int32_t heldCount =
            static_cast<int32_t>(object_wire::read(self, 0x24u));
        if (heldCount <= 0) {
            /* 0x198f70: ble jumps straight to the bl with the originally
             * held table pointer, no reload. */
            MemoryManager::Free(asPointer(table));
        } else {
            /* 0x198de4..0x198e18 held traverser: window test first, then
             * subs, +8=0, +0C=5, +00=0 (+04 kept), post-advance #16, beq. */
            uint32_t remaining = static_cast<uint32_t>(heldCount);
            for (;;) {
                if (inTagWindow(object_wire::read(table, 0x0Cu)))
                    FREE_RValue__Pre(asRValue(table));
                remaining -= 1;                        /* 0x198de4 subs */
                object_wire::write(table, 0x08u, 0u);
                object_wire::write(table, 0x0Cu, 5u);
                object_wire::write(table, 0x00u, 0u);
                table += 16u;                          /* str r6,[r4],#16 */
                if (remaining == 0)
                    break;                             /* 0x198df4 beq */
            }
            /* 0x198e1c: after the positive-count loop the LIVE obj+0x04 is
             * reloaded as the MemoryManager::Free argument. */
            MemoryManager::Free(asPointer(object_wire::read(self, 0x04u)));
        }
        object_wire::write(self, 0x04u, 0u);           /* 0x198e28 */
        object_wire::write(self, 0x2Cu, 0u);           /* 0x198e2c */
        object_wire::write(self, 0x24u, 0u);           /* 0x198e30 */
    }

    /* Variable map block, 0x198e34..0x198ebc. */
    uint32_t map = object_wire::read(self, 0x60u);
    if (map != 0u) {
        const int32_t word04 = static_cast<int32_t>(object_wire::read(map, 0x04u));
        uint32_t buckets;
        if (word04 < 0) {
            /* 0x198f78: signed-negative word04 bypasses the whole scan and
             * jumps into the tail with the freshly read bucket array. */
            buckets = object_wire::read(map, 0x10u);
        } else {
            /* Exact index/word00/decrement CFG (0x198e4c..0x198e90): this is
             * not a plain foreach. r4 starts at 0 and is incremented BEFORE
             * the index<=word00 test, so bucket index-1 is processed; the
             * rebase label recomputes the byte cursor from the current r4
             * without resetting it; scan exit consumes rounds (the original
             * subs r7,#1 / bhs carry chain) and out-of-range passes only
             * burn rounds without any dereference. */
            uint32_t bucketCount = object_wire::read(map, 0x00u);
            buckets = object_wire::read(map, 0x10u);
            uint32_t index = 0;
            uint32_t rounds = static_cast<uint32_t>(word04);
            uint32_t bucketBase;
            uint32_t bucket;
            int32_t bucketState;
        rebase:  /* 0x198e60 add r3,r4,r4 lsl 1 / add r3,r0,r3 lsl 2 */
            bucketBase = buckets + static_cast<uint32_t>(index) * 12u;
        step:    /* 0x198e78 */
            index += 1;
            bucket = bucketBase;
            bucketBase += 12u;
            if (static_cast<int32_t>(index) <= static_cast<int32_t>(bucketCount)) { /* cmp r4,r1; ble */
                bucketState =
                    static_cast<int32_t>(object_wire::read(bucket, 0x08u));
                if (bucketState > 0) {  /* 0x198e74 bgt -> 0x198f18 */
                    uint32_t captured = object_wire::read(bucket, 0x04u);
                    if (inTagWindow(object_wire::read(captured, 0x0Cu))) {
                        const uint32_t spilled = captured;  /* str r3,[sp,#4] */
                        FREE_RValue__Pre(asRValue(captured));
                        captured = spilled;                 /* ldr r3,[sp,#4] */
                    }
                    /* 0x198f44..0x198f5c: clear the original captured value
                     * first (+00=0), THEN reload bucket+0x04 as the real
                     * FreeRValue argument, then +08=0 and +0C=5. */
                    object_wire::write(captured, 0x00u, 0u);
                    const uint32_t freeArg =
                        object_wire::read(bucket, 0x04u);
                    object_wire::write(captured, 0x08u, 0u);
                    object_wire::write(captured, 0x0Cu, 5u);
                    FreeRValue(asRValue(freeArg), heldOut1, heldOut2);
                    /* 0x198f60: r12/r1/r0 come from the LIVE obj+0x60 map;
                     * r4 (index) and r7 (rounds) are NOT reset. */
                    map = object_wire::read(self, 0x60u);
                    bucketCount = object_wire::read(map, 0x00u);
                    buckets = object_wire::read(map, 0x10u);
                    goto rebase;
                }
                goto step;  /* 0x198e6c fall through back to 0x198e78 */
            }
            /* 0x198e8c subs r7,r7,#1; bhs: continue while the old r7 was
             * non-zero (unsigned carry), exactly as the decrement chain. */
            if (rounds-- != 0)
                goto rebase;
        }
        /* 0x198e94 tail: MM::Free only for a non-null held bucket array,
         * using the spilled held map for the +0x10 clear... */
        if (buckets != 0u) {
            const uint32_t heldMap = map;            /* str r12,[sp,#4] */
            MemoryManager::Free(asPointer(buckets));
            map = heldMap;                           /* ldr r12,[sp,#4] */
            object_wire::write(map, 0x10u, 0u);      /* 0x198eac */
        }
        /* ...then the unconditional raw ::operator delete (0x27d1d0) of the
         * held map even when the bucket array was null, and obj+0x60 clear. */
        ::operator delete(asPointer(map));           /* 0x198eb4 */
        object_wire::write(self, 0x60u, 0u);         /* 0x198ebc */
    }

    /* PCRE release block, 0x198ec0..0x198f04: obj+0x1C and obj+0x20 are two
     * separate sites, each reading the live pcre_free function-pointer
     * variable (both sites resolve GOT slot 0x3f0690 -> 0x3f76dc).
     * The two calls deliberately share no cached value. */
    const uint32_t regexEntry1c = object_wire::read(self, 0x1Cu);
    if (regexEntry1c != 0u) {
        const PcreFreeEntry freeEntry = pcre_free;
        freeEntry(asPointer(regexEntry1c));
        object_wire::write(self, 0x1Cu, 0u);         /* 0x198ee0 */
    }
    const uint32_t regexEntry20 = object_wire::read(self, 0x20u);
    if (regexEntry20 != 0u) {
        const PcreFreeEntry freeEntry = pcre_free;
        freeEntry(asPointer(regexEntry20));
        object_wire::write(self, 0x20u, 0u);         /* 0x198f04 */
    }
    object_wire::write(self, 0x18u, 0u);             /* 0x198f0c */
}
