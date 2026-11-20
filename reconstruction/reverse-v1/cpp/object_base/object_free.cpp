#include "object_internal.hpp"

/* YYObjectBase::Free: original C++ static member _ZN12YYObjectBase4FreeEPS_ at
 * 0x198f88..0x199110 (93 instructions + 5 literal-pool words, 392 bytes).
 * tier: bytecode_anchored; original ARMv7 ELF SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * Per-instruction ownership: intake scratch cally-loop-object-u32-fmv_pr30
 * original-0x198f88.asm.txt / index-0x198f88.tsv (body SHA256 f90fdf37...).
 * The JS helpers (JS_GetProperty 0x2418dc, JS_IsCallable 0x24076c,
 * Call_RValue 0x249860) and the deleteSelf slot target still owe bodies;
 * FreeVars has a separate real source in this module. No delete-expression
 * on the nominal empty YYObjectBase is used:
 * the kind-3 destruction goes through the object's own vtable+0x04 entry.
 * gap: original fault, concurrency and unwind domains are unproved; the wire
 * views below are raw word access, not complete-object instantiation. No
 * equivalence between this source and the original machine code is claimed.
 */

void YYObjectBase::Free(YYObjectBase *object)
{
    /* 0x198f88: object+0x48 is the very first read. The source keeps this
     * read unguarded; fault equivalence is not certified. */
    const uint32_t self = object_wire::address(object);
    const uint32_t kind = object_wire::read(self, 0x48u);

    if (kind == 3u) {
        /* 0x1990b8..0x1990f8 kind-3 branch: slot detach and count/firstFree
         * bookkeeping only; the destruction is the object's own deleteSelf
         * (vptr+0x04, loaded at 0x1990d4 AFTER the slot null store). No
         * +0x38/+0x40/+0x18 clear, no FreeVars call, no pool push. */
        const int32_t slotId = static_cast<int32_t>(object_wire::read(self, 0x44u));
        YYObjectBase *volatile *const slots = g_slotObjects.slots;
        const int32_t heldFirstFree = g_slotObjects.firstFree;
        const uint32_t heldCount = g_slotObjects.count;
        const uint32_t slotBase = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(slots));
        object_wire::write(slotBase, static_cast<uint32_t>(slotId) << 2, 0u); /* 0x1990d0 */
        const uint32_t vptr = object_wire::read(self, 0x00u);  /* 0x1990d4 */
        g_slotObjects.firstFree =                                  /* strle/strgt 0x1990e0 */
            (heldFirstFree <= slotId) ? heldFirstFree : slotId;
        g_slotObjects.count = heldCount - 1u;                      /* 0x1990e8 sub #1 */
        const volatile ObjectDeleteTablePrefix *deleteTable =
            reinterpret_cast<const volatile ObjectDeleteTablePrefix *>(
                static_cast<uintptr_t>(vptr));
        deleteTable->deleteSelf(object);  /* 0x1990ec ldr r3,[r1,#4]; 0x1990f0 blx r3 */
        return;
    }

    /* 0x198fac..0x198fe8 ordinary path, original order: registry snapshot
     * loads (firstFree/slots/count at 0x198fbc/0x198fc0/0x198fc4) precede every
     * write; then slot null store, signed minimum firstFree, +0x38 clear,
     * +0x44 = -1 (mvn lr), wrapping count writeback (add r4, lr). */
    const int32_t slotId = static_cast<int32_t>(object_wire::read(self, 0x44u));
    const int32_t heldFirstFree = g_slotObjects.firstFree;
    YYObjectBase *volatile *const slots = g_slotObjects.slots;
    const uint32_t heldCount = g_slotObjects.count;
    const uint32_t minusOne = 0xFFFFFFFFu;  /* 0x198fb8 mvn lr, #0 */
    const uint32_t slotBase = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(slots));
    object_wire::write(slotBase, static_cast<uint32_t>(slotId) << 2, 0u); /* 0x198fc8 */
    g_slotObjects.firstFree =                   /* strle/strgt 0x198fd0/0x198fd4 */
        (heldFirstFree <= slotId) ? heldFirstFree : slotId;
    object_wire::write(self, 0x38u, 0u);    /* 0x198fdc */
    object_wire::write(self, 0x44u, minusOne); /* 0x198fe4 */
    g_slotObjects.count = heldCount + minusOne; /* 0x198fe8 wrapping decrement */

    if (kind == 0u) {
        /* 0x199034: the dispose probe requires the OLD kind==0 (flags from
         * 0x198fd8), object+0x04==0, and the 1-byte g_ShouldDispose flag at
         * 0x3f5050 (NOT the VM JSGC variable). Reads stay lazy in asm order. */
        const uint32_t heldWord4 = object_wire::read(self, 0x04u);
        if (heldWord4 == 0u && g_ShouldDispose != 0u) {
            /* 0x199054..0x199078: one 16-byte local raw image, written in the
             * original word order sp+0x10 (str r8), sp+0x08..0x0f (strd),
             * sp+0x14 (mvn #-16777216). No RValue ctor/dtor, no refresh, no
             * extra cleanup; the same image address is used for all three
             * calls below. The kind sentinel is 0x00FFFFFF, not 5. */
            ObjectValueImage image;
            image.auxiliary = heldWord4;  /* proven 0 on this path */
            image.low = 0u;
            image.high = 0u;
            image.kind = 0x00FFFFFFu;
            RValue *const probe = reinterpret_cast<RValue *>(&image);
            JS_GetProperty(object, probe, "dispose"); /* 0x19907c, result word ignored */
            if (object_wire::read(object_wire::address(&image), 0x0cu) != 0x00FFFFFFu && /* 0x199084 */
                JS_IsCallable(*probe) != 0u) {        /* 0x199094 tests full r0 */
                /* 0x19909c: r1/r3/[sp] all carry the proven-zero r8 word:
                 * Call_RValue(obj, null, &image, 0, null). */
                Call_RValue(object, static_cast<RValue *>(nullptr), probe, 0,
                            static_cast<RValue *>(nullptr));
            }
        }
    }

    /* 0x198ff0 epilogue shared by every non-kind-3 exit (fall-through,
     * word4 != 0, flag 0, sentinel preserved, non-callable, post-call). */
    object_wire::write(self, 0x40u, 0u);    /* 0x198ff8 */
    object_wire::write(self, 0x18u, 0u);    /* 0x199000 */
    FreeVars(object, static_cast<RValue **>(nullptr),
             static_cast<RValue **>(nullptr),
             static_cast<RVariable **>(nullptr),
             static_cast<RVariable **>(nullptr)); /* r1..r3 + [sp] all null, 0x199010 */

    /* 0x199014..0x199028 pool push: clear +0x0C, read the old head, publish
     * freeList = object BEFORE obj+0x08 receives the old head. freeList is
     * the class static _ZN12YYObjectBase12ms_pFreeListE, reached here through
     * its GOT slot exactly as in the original. */
    object_wire::write(self, 0x0Cu, 0u);    /* 0x19901c */
    YYObjectBase *const oldHead = object_state::freeList; /* ldr r2,[r3] */
    object_state::freeList = object;                       /* str r6,[r3] */
    object_wire::write(self, 0x08u, object_wire::address(oldHead)); /* str r2,[r6,#8] */
}
