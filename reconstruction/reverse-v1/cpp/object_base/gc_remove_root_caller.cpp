/* tier: bytecode_anchored
 * _Z12RemoveGCRootP12YYObjectBase, original window 0xd5b60..0xd5ba8 (72B,
 * including the tail pool word at 0xd5ba4 whose decode
 * "eorseq r8, r1, r4, ror #1" is literal-pool DATA, not code), pinned
 * ARMv7 image libyoyo-armv7.so SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * The intake manifest gc-object-lifecycle-prepared-intake.json SHA256
 * 7696e5192d163be83e1fffdfec4341899729813192377d5bd94875c08bce0245 owns the
 * frozen seam; this TU defines the RemoveGCRoot body ONLY and adds no new
 * global, helper or backing store.
 * Word order mirrors the disassembly literally:
 *  - 0xd5b60 ldr r3,[r0,#56]: the FIRST observable action is one raw 32-bit
 *    signed read of object+0x38, taken before the push at 0xd5b64.
 *  - 0xd5b68/0xd5b70 cmp r3,#0 + poplt: a signed negative first read returns
 *    immediately. There is NO NULL gate on the object pointer anywhere in the
 *    original window, so none is invented here; the caller contract that
 *    keeps object valid is unproved.
 *  - 0xd5b74/0xd5b7c: the GOT-style double load resolves once at entry to
 *    slot 0x3edc68 -> g_GCGens @0x536da8 (bindings.json "remove_gc_root",
 *    verified R_ARM_RELATIVE pair). The loop cursor starts at the ORIGINAL
 *    g_GCGens begin; the slot is never re-read per iteration — the cursor
 *    advances by integer +88 (0xd5b94), preserving ARM32 address width.
 *  - 0xd5b80..0xd5b88 do-while body: this = cursor, r1 = object, bl
 *    0x1911c8 = the REAL _ZN13CGCGeneration10RemoveRootEP12YYObjectBase
 *    (dynsym GLOBAL; body defined separately in gc_remove_root.cpp). The
 *    first generation is called UNCONDITIONALLY — the negative early exit
 *    aside, at least one RemoveRoot call always happens (generation 0).
 *  - 0xd5b8c ldr r3,[r6,#56]: after each return the SAME object+0x38 raw
 *    word is RE-READ live; 0xd5b90 index += 1; 0xd5b94 cursor += 88;
 *    0xd5b98/0xd5b9c cmp r3,r5 + bge: signed liveBound >= index decides
 *    whether to run another generation.
 *  - NO clamp to the 4-instance array is present in the original: the live
 *    bound word alone drives the walk, so a bound >= 4 moves the cursor past
 *    the 352-byte g_GCGens array; whatever storage lies behind it, the final
 *    address reached, and any producer that writes object+0x38 >= 4 are
 *    unproved here; this TU reproduces the observed dispatch arithmetic
 *    exactly and does not sanitize it.
 * g_GCGens stays the extern declaration from gc_generation.hpp (image
 * startup line owns the definition); each generation is accessed through the
 * canonical liveGeneration(GCGenerationStorage &), and the +0x38 field via
 * the existing object_wire raw helpers.
 * gap: faults (the live +0x38 re-read assumes object stays dereferenceable
 * across each call), unwind/EHABI records, exceptions, concurrency and any
 * equivalence-by-execution claim remain unproved; the original was never run
 * for this recovery. Normal-state words/ABI above are byte-literal.
 */
#include "gc_object_lifecycle.hpp"

void RemoveGCRoot(YYObjectBase *object) {
    /* 0xd5b60: raw signed first read of object+0x38 (ARM r3 lives across the
     * push at 0xd5b64; ordering is observationally identical). */
    const uint32_t objectWord = object_wire::address(object);
    int32_t liveBound = static_cast<int32_t>(object_wire::read(objectWord, 0x38u));

    /* 0xd5b68/0xd5b70: signed <0 early exit; no NULL gate exists to add. */
    if (liveBound < 0) {
        return;
    }

    /* 0xd5b74/0xd5b7c: entry-time double load -> &g_GCGens[0] @0x536da8
     * (slot 0x3edc68). 0xd5b78: r5 index = 0. */
    uint32_t cursor = object_wire::address(&g_GCGens[0]);
    uint32_t index = 0u;

    do {
        /* 0xd5b80..0xd5b88: real CGCGeneration::RemoveRoot on the cursor
         * generation; the do-while shape keeps the unconditional first
         * dispatch on generation 0 exactly as the original. */
        liveGeneration(*reinterpret_cast<GCGenerationStorage *>(
                           static_cast<uintptr_t>(cursor)))
            .RemoveRoot(object);

        /* 0xd5b8c RE-READ of the same object+0x38 word, 0xd5b90 index+1,
         * 0xd5b94 cursor+88 (32-bit wrapping), 0xd5b98/0xd5b9c signed
         * liveBound >= index; no clamp to the 4-instance array. */
        liveBound = static_cast<int32_t>(object_wire::read(objectWord, 0x38u));
        index += 1u;
        cursor += 88u;
    } while (liveBound >= static_cast<int32_t>(index));
}
