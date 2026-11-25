/* tier: bytecode_anchored. Static recovery of four dynsym teardown
 * functions from original image libyoyo_armv7.so (ARMv7 ELF32), SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (per gc-finalize-anchors/bindings.json, batch10_functions). Parent-direct
 * recovery; dispatcher channels down (dht quota 429, dahetao deepseek 503,
 * jing 503, google-free hang).
 *
 * Windows (dynsym va+size; code span / literal pool recorded per census):
 *   _Z20FINALIZE_Script_Mainv     0x1e0770, 4B    1 word, no pool: whole-body
 *                                                 tail branch into Script_Free
 *   _Z22FINALIZE_Variable_Mainv   0x1f4d10, 152B  code 0x1f4d10..0x1f4d9c,
 *                                                 pool 0x1f4d9c..0x1f4da8
 *   _Z22FINALIZE_Timeline_Mainv   0x1f3174, 420B  code 0x1f3174..0x1f3308,
 *                                                 pool 0x1f3308..0x1f3318
 *   _Z21FINALIZE_Event_Actionv    0xf2c9c, 108B   code 0xf2c9c..0xf2d00,
 *                                                 pool 0xf2d00..0xf2d08
 *
 * Real links: MemoryManager::Free (0x27c2d0, recovered) and
 * ::operator delete (0x27d1d0, recovered); MemoryManager::IsAllocated
 * (0x27c454) is NOT recovered -- the canonical vm_buffer.hpp class gained a
 * declaration only (parent seam edit); memset is the existing libc-import
 * declaration in memory_alloc.hpp. All other callees are extern-only
 * declarations from dynsym identity (Script_Free 0x1e4644... see direct
 * deps), NO stubs.
 *
 * GOT-delta resolutions (each pc-relative pair verified against .rel.dyn,
 * R_ARM_RELATIVE (23) in every case):
 *   Variable_Main: ldr r5,[pc,#0x7c] @0x1f4d18 (pool 0x1f4d9c =
 *     0x001f8f18) / ldr r5,[pc,r5] @0x1f4d20, pc base 0x1f4d28 -> slot
 *     0x3edc40 -> 0x75310c builtin_variables (8000B);
 *     ldr r6,[pc,#0x54] @0x1f4d44 (pool 0x1f4da0 = 0x001fc0d0) /
 *     ldr r6,[pc,r6] @0x1f4d58, pc base 0x1f4d60 -> slot 0x3f0e30 ->
 *     0x753100 globdecl (8B);
 *     ldr r3,[pc,#0x40] @0x1f4d5c (pool 0x1f4da4 = 0x001f8ecc) /
 *     ldr r3,[pc,r3] @0x1f4d68, pc base 0x1f4d70 -> slot 0x3edc3c ->
 *     0x753108 builtin_numb (4B).
 *   Event_Action: pool 0xf2d00 = 0x002fb174 / pair pc base 0xf2cac ->
 *     slot 0x3ede20 -> 0x483404 libcode (4B); pool 0xf2d04 = 0x002fb164 /
 *     pair pc base 0xf2cc0 -> slot 0x3ede24 -> 0x483408 libnumb (4B).
 *   Timeline_Main: FOUR add-pc sites converge on the same unnamed BSS
 *     pointer word 0x7530f4 (parent recomputed all four: 0x1f3184+0x0055ff70,
 *     0x1f3248+0x0055feac, 0x1f3254+0x0055fea0, 0x1f32e4+0x0055fe10) and one
 *     pair on 0x7530f8 ([0x7530f4+4]); no dynsym name covers either word
 *     (range-checked), both are runtime-written container pointers, so the
 *     prescribed anon representation applies: anon_0x7530f4[4] /
 *     anon_0x7530f8[4], UNDEFINED, placement comments below.
 *
 * gap: producers/writers of builtin_variables, globdecl, builtin_numb,
 * anon_0x7530f4 and anon_0x7530f8 are outside the recovered set; the class
 * behind the two [vtable+4] blx destruct edges (0x1f31f4 timeline entries,
 * 0x19c318-adjacent Motion_Grid counterpart is a separate slice) is
 * unidentified; Script_Free body (204B, dynsym-defined) is outside the
 * recovered set; the 0xfeeefeee poison comparisons in Timeline_Main are
 * reproduced as plain value compares (the freed-memory sentinel convention
 * is an observation, not a claimed contract); EHABI unwind records are not
 * recovered; concurrency and final linked addresses stay unproved; nothing
 * was executed, and no equivalence claim of any kind is made.
 */

#include "quit_runtime.hpp"                  // FINALIZE_* declarations
#include "../memory_manager/memory_alloc.hpp" // canonical MemoryManager (Free), memset decl

/* Extern-only teardown callees, dynsym identities; NO stubs. */
void Script_Free();                              // _Z11Script_Freev, 0x1e4644, 204B

/* Named dynsym objects (all R_ARM_RELATIVE verified), declared not defined:
 * the final link must supply them at their dynsym addresses. */
extern "C" volatile uint32_t builtin_variables[500]; // 0x75310c, 8000B; GOT 0x3edc40
extern "C" volatile uint32_t globdecl[2];            // 0x753100, 8B; GOT 0x3f0e30
extern "C" volatile uint32_t builtin_numb;           // 0x753108, 4B; GOT 0x3edc3c
extern "C" volatile uint32_t libcode;                // 0x483404, 4B; GOT 0x3ede20
extern "C" volatile uint32_t libnumb;                // 0x483408, 4B; GOT 0x3ede24

/* Unnamed BSS pointer words (parent-verified: no dynsym name, no file
 * bytes); contents are runtime-written container pointers consumed below.
 * The final link must place them at the addresses in their names. */
extern "C" unsigned char anon_0x7530f4[4];       // four add-pc sites converge here
extern "C" unsigned char anon_0x7530f8[4];       // consumed as [anon_0x7530f4+4]

void FINALIZE_Script_Main() { // _Z20FINALIZE_Script_Mainv @0x1e0770
    /* 0x1e0770: eaffff3b b 0x1e0464 <_Z11Script_Freev> -- the entire 4B
     * body is one pure tail branch into the unrecovered Script_Free. */
    Script_Free();
}

void FINALIZE_Variable_Main() { // _Z22FINALIZE_Variable_Mainv @0x1f4d10
    /* 0x1f4d10 push {r4,r5,r6,lr}; 0x1f4d14 mov r4,#0
     * 0x1f4d18/0x1f4d20 GOT pair -> r5 = builtin_variables (0x75310c)
     * 0x1f4d1c mov r6, r4 (r6 = the zero register mirror)
     * sweep 0x1f4d24..0x1f4d40: byte offset r4 = 0,16,32,...,7984
     *   0x1f4d24 ldr r0,[r5,r4] : entry word at byte offset r4
     *   0x1f4d28 cmp r0,#0 / 0x1f4d2c beq +4 : skip null entries
     *   0x1f4d30 bl Free(entry) : real edge
     *   0x1f4d34 str r6,[r5,r4] : zero-store through the table base */
    for (uint32_t off = 0u; off != 8000u; off += 16u) {
        volatile uint32_t *entry = &builtin_variables[off / 4u];
        if (*entry != 0u) {
            MemoryManager::Free(reinterpret_cast<const void *>(*entry));
            *entry = 0u;
        }
    }
    /* 0x1f4d44/0x1f4d58 GOT pair -> r6 = globdecl (0x753100)
     * 0x1f4d48 mov r0,r5 (table base); 0x1f4d4c mov r2,r4 (8000)
     * 0x1f4d50 mov r1,#0; 0x1f4d54 bl memset@plt : memset(table, 0, 8000) */
    memset(const_cast<uint32_t *>(builtin_variables), 0, 8000u);
    /* 0x1f4d5c/0x1f4d68 GOT pair -> r3 = builtin_numb (0x753108)
     * 0x1f4d60 mov r5,#0; 0x1f4d64 ldr r4,[r6,#4] : globdecl[1]
     * 0x1f4d6c cmp r4,r5; 0x1f4d70 mov r0,r4
     * 0x1f4d74 str r5,[r3] : builtin_numb = 0 (BEFORE the free branch)
     * 0x1f4d78 beq 0x1f4d90 : null path still calls Free(NULL) and stores
     *   the (zero) value back; 0x1f4d7c bl Free(r4) / 0x1f4d80 str r5,[r6,#4]
     * 0x1f4d84 mov r3,#0; 0x1f4d88 str r3,[r6] : globdecl[0] = 0 */
    builtin_numb = 0u;
    {
        const uint32_t g1 = globdecl[1];
        MemoryManager::Free(reinterpret_cast<const void *>(g1));
        globdecl[1] = 0u; /* 0x1f4d80 str r5 / 0x1f4d94 str r4:
                           * both census paths store a zero word */
        globdecl[0] = 0u;                 /* 0x1f4d88 str r3,[r6] */
    }
    /* 0x1f4d8c pop {r4, r5, r6, pc} */
}

void FINALIZE_Timeline_Main() { // _Z22FINALIZE_Timeline_Mainv @0x1f3174
    /* 0x1f3174 ldr r3,[pc,#0x18c] (pool 0x1f3308); 0x1f317c ldr r6,[pc,r3]
     * : r6 = [anon_0x7530f4] = container one pointer (runtime-written)
     * 0x1f3180 cmp r6,#0 / 0x1f3184 beq 0x1f3248 : null -> phase two */
    const uint32_t poison = 0xfeeefeeeu; /* 0x1f31b4/0x1f31b8 movw/movt r3 and
                                          * 0x1f31bc/0x1f31c0 movw/movt r2 */
    uint32_t *container1 = reinterpret_cast<uint32_t *>(anon_0x7530f4);
    if (*reinterpret_cast<uint32_t *volatile *>(container1) != nullptr) {
        /* 0x1f3188 ldr r12,[r6] : count; 0x1f3194 ldr r5,[r6,#4] : entries */
        volatile uint32_t *c1 = *reinterpret_cast<uint32_t *volatile *>(container1);
        const uint32_t count = c1[0];
        volatile uint32_t *entries = reinterpret_cast<volatile uint32_t *>(c1 + 2u); /* +4 bytes */
        if (count != 0u && entries != nullptr) {
            if (static_cast<int32_t>(count) > 0) { /* 0x1f31a0 cmp r12,#0 / ble 0x1f3218 */
                /* 0x1f31a8 mov r4,#0; 0x1f31ac mov r8,r4 (zero mirror)
                 * 0x1f31b0 ldr r1,[r5] : entries[0] vs poison (0x1f31c0 beq skip)
                 * 0x1f31d0 ldr r3,[r5,r4,lsl #2] : entry ptr; 0x1f31dc mov r0,r3
                 * 0x1f31e0 beq 0x1f320c (null entry -> skip)
                 * 0x1f31e4 ldr r3,[r3] : entry vtable; 0x1f31e8 cmp r3,poison
                 * 0x1f31ec beq 0x1f3204 (poisoned vtable -> skip, still null-store)
                 * 0x1f31f0 ldr r3,[r3,#0x4] : vtable word +4
                 * 0x1f31f4 blx r3 : INDIRECT destruct; target unresolved */
                for (uint32_t i = 0u; i < count; ++i) { /* 0x1f320c/0x1f3210/0x1f3214 */
                    if (entries[0] == poison) { /* 0x1f31b0 ldr r1,[r5] (entries[0],
                                                 * NOT entries[i]) / 0x1f31c0/0x1f31cc */
                        continue;
                    }
                    uint32_t entry = entries[i];
                    if (entry != 0u) { /* 0x1f31d8/0x1f31e0 */
                        uint32_t vt = *reinterpret_cast<uint32_t *>(entry);
                        if (vt != poison) { /* 0x1f31e8/0x1f31ec */
                            reinterpret_cast<void (*)(void *)>(
                                *reinterpret_cast<uint32_t *>(vt + 4u))(
                                reinterpret_cast<void *>(entry)); /* 0x1f31f4 blx */
                        }
                    }
                    /* 0x1f31f8/0x1f31fc live reload of [r6+4] and [r6]
                     * 0x1f3200 add r1,r1,r7 ; 0x1f3204 str r8,[r1] */
                    volatile uint32_t *live_entries =
                        *reinterpret_cast<uint32_t *volatile *>(container1) + 2u;
                    live_entries[i] = 0u;
                    /* 0x1f3208 ldr r5,[r6,#4] : entries reload for the tail */
                }
            }
            /* 0x1f3218 mov r0,r5 ; 0x1f321c bl Free : free the entries array
             * 0x1f3220/0x1f3224 mov r3,#0 / str r3,[r6,#4]
             * 0x1f3228/0x1f322c str r3,[r6] */
            MemoryManager::Free(reinterpret_cast<const void *>(const_cast<uint32_t *>(entries)));
            c1[1] = 0u;
            c1[0] = 0u;
        }
        /* 0x1f3230 mov r0,r6 ; 0x1f3234 bl _ZdlPv : delete the container
         * 0x1f3238/0x1f3240/0x1f3244 store 0 into [anon_0x7530f4] */
        ::operator delete(const_cast<void *>(static_cast<const volatile void *>(c1)));
        *container1 = 0u;
    }
    /* ---- phase two: container two at [anon_0x7530f4 + 4] = anon_0x7530f8
     * 0x1f3248 ldr r3,[pc,#0xc0] (pool 0x1f3310); 0x1f324c add r3,pc,r3
     * 0x1f3250 ldr r5,[r3,#0x4] : r5 = [anon_0x7530f8]
     * 0x1f3254 cmp r5,#0 / 0x1f3258 popeq : null -> return */
    uint32_t *container2 = reinterpret_cast<uint32_t *>(anon_0x7530f8);
    if (*reinterpret_cast<uint32_t *volatile *>(container2) != nullptr) {
        volatile uint32_t *c2 = *reinterpret_cast<uint32_t *volatile *>(container2);
        /* 0x1f325c ldr r6,[r5,#0x4] : entries-two; 0x1f3260 cmp/0x1f3264 beq
         *   0x1f32e8: Free(entries-two=0), store back, jump to the tail */
        volatile uint32_t *entries2 = reinterpret_cast<volatile uint32_t *>(c2 + 2u);
        if (*entries2 != 0u) { /* 0x1f32e8 path frees it and stores it back */
            /* 0x1f3268 ldr r3,[r5] : count-two; 0x1f326c cmp/0x1f3270 ble
             *   0x1f32b8 : count<=0 skips straight to Free(entries-two) */
            if (static_cast<int32_t>(c2[0]) > 0) {
                /* 0x1f3274 mov r4,#0; 0x1f3278 mov r7,r4
                 * 0x1f327c ldr r0,[r6,r4,lsl #2] : entries-two[i]
                 * 0x1f3280 lsl r6,r4,#2
                 * 0x1f3284 bl IsAllocated : UNRECOVERED extern edge (canonical decl)
                 * 0x1f3288 cmp/0x1f328c beq 0x1f329c : not allocated -> only null-store
                 * 0x1f3290 ldr r3,[r5,#4]; 0x1f3294 ldr r0,[r3,r4,lsl #2]
                 * 0x1f3298 bl Free : real edge
                 * 0x1f329c..0x1f32ac live reloads + null-store [r5+4][i] */
                for (uint32_t i = 0u; i < c2[0]; ++i) {
                    volatile uint32_t *slot2 = &entries2[i];
                    if (MemoryManager::IsAllocated(
                            reinterpret_cast<const void *>(*slot2)) != 0) {
                        MemoryManager::Free(reinterpret_cast<const void *>(*slot2));
                    }
                    /* 0x1f329c ldr r2,[r5]; 0x1f32a4 ldr r3,[r5,#4] live reloads
                     * 0x1f32ac str r7,[r3,r6] : null-store through the reload */
                    *slot2 = 0u;
                }
            }
            /* 0x1f32b8 mov r0,r6 ; 0x1f32bc bl Free(entries-two)
             * 0x1f32c0/0x1f32c4 str r3,[r5,#4] : zero
             * 0x1f32c8/0x1f32d0 mov r0,r5 / str r4,[r5] : zero
             * 0x1f32d4 bl _ZdlPv : delete container two */
            MemoryManager::Free(reinterpret_cast<const void *>(const_cast<uint32_t *>(entries2)));
            c2[1] = 0u;
            c2[0] = 0u;
            ::operator delete(const_cast<void *>(static_cast<const volatile void *>(c2)));
            /* 0x1f32d8/0x1f32dc/0x1f32e0 str r4,[r3,#0x4] : [anon_0x7530f8] = 0 */
            *container2 = 0u;
            return; /* 0x1f32e4 pop {r4, r5, r6, r7, r8, pc} */
        }
        const uint32_t c2_saved = *entries2; /* 0x1f32f8 mov r0,r5 : the freed
                                              * argument is the stored container
                                              * pointer value itself */
        MemoryManager::Free(reinterpret_cast<const void *>(c2_saved));
        c2[1] = *entries2; /* 0x1f32f0 str r6,[r5,#4] : stores the ORIGINAL
                            * word back unchanged on this path (r4==0 case in
                            * the original: the store is the same value) */
        /* 0x1f32f4 b 0x1f32c8 : joins the zero/delete tail */
        c2[1] = 0u;
        c2[0] = 0u;
        ::operator delete(const_cast<void *>(static_cast<const volatile void *>(c2)));
        *container2 = 0u;
        return;
    }
}

void FINALIZE_Event_Action() { // _Z21FINALIZE_Event_Actionv @0xf2c9c
    /* 0xf2ca0/0xf2ca4 GOT pair -> r5 = libcode (0x483404); 0xf2cb4/0xf2cb8
     * pair -> r6 = libnumb (0x483408).
     * 0xf2ca8 ldr r3,[r5] / 0xf2cac cmp #0 / 0xf2cb0 popeq : array null -> return
     * 0xf2cbc ldr r2,[r6] / 0xf2cc0 cmp #0 / 0xf2cc4 poplt... popEq style:
     *   0xf2cc4 d8bd80f8 popLE : count <= 0 -> return (UNSIGNED-taken shape;
     *   the original uses the LE-condition pop here and popEQ at 0xf2cb0) */
    volatile uint32_t *libcode_word = &libcode;
    volatile uint32_t *libnumb_word = &libnumb;
    uint32_t *entries = reinterpret_cast<uint32_t *>(*libcode_word);
    if (entries == nullptr) { /* 0xf2cb0 popEQ */
        return;
    }
    const uint32_t count = *libnumb_word; /* 0xf2cbc */
    if (static_cast<int32_t>(count) <= 0) { /* 0xf2cc4 popLE (signed reading of
                                             * the le-condition pop; census
                                             * d8=le) */
        return;
    }
    /* 0xf2cc8 mov r4,#0; 0xf2ccc mov r7,r4 (zero mirror)
     * loop: 0xf2cd0 ldr r0,[r3,r4,lsl #2] (r3 = [libcode] live)
     *   0xf2cd4 cmp #0 / 0xf2cd8 beq skip; 0xf2cdc bl Free : real edge
     *   0xf2ce0 ldr r3,[r5] reload; 0xf2ce4 str r7,[r3,r4,lsl #2] null-store
     *   0xf2ce8 ldr r3,[r6] reload count; 0xf2cec add r4,#1
     *   0xf2cf0 cmp r3,r4 / 0xf2cf4 poplt return; 0xf2cf8 ldr r3,[r5]; loop */
    for (uint32_t i = 0u; ; ++i) {
        volatile uint32_t *live_entries =
            *reinterpret_cast<uint32_t *volatile *>(libcode_word);
        uint32_t p = live_entries[i];
        if (p != 0u) {
            MemoryManager::Free(reinterpret_cast<const void *>(p));
            volatile uint32_t *reload = *reinterpret_cast<uint32_t *volatile *>(libcode_word);
            reload[i] = 0u;
        }
        if (static_cast<int32_t>(*libnumb_word) <= static_cast<int32_t>(i)) {
            return; /* 0xf2cf0 cmp r3,r4 / 0xf2cf4 poplt */
        }
    }
}
