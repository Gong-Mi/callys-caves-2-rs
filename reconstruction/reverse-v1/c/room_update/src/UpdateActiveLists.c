/*
 * UpdateActiveLists.c — static C translation of _Z17UpdateActiveListsv
 * @0x001d30a4 (42 instructions + 6 literal-pool words, 192 B).
 *
 * The per-frame flusher of the three deferred lists.  No loop, no early exit:
 * the shape is
 *
 *     entry -> [profile ? CProfiler::Push(this,6,7)] -> A? -> B? -> C?
 *           -> [profile ? CProfiler::Pop(this)] -> return
 *
 * and each check is `count = [list+8]; if (count != 0) handler();` followed by a
 * fall-through to the NEXT check (0x1d3130, 0x1d3128, 0x1d3120 are b-into-the-
 * next-check, not loop edges).  A frame therefore runs each handler at most
 * once, in the fixed order A (activation) -> B (object type) -> C (depth).
 *
 * Two things the bytes insist on, and the differential grades:
 *   * the test is `cmp / bne`, i.e. NON-ZERO.  A negative count -- the shape a
 *     `count` field takes after an underflow -- flushes the queue exactly like
 *     a positive one, and 0x80000000 does too.  `if (count > 0)` is wrong.
 *   * the profile byte is read TWICE, at 0x1d30b8 and again at 0x1d3100, and
 *     the second read is what decides Pop.  A handler that cleared the byte
 *     between the two (the real ones are free to; F3 does not) yields a Push
 *     with no Pop.  Case UL-j stages exactly that through the stub model.
 *
 * Global addressing: r4 = .got anchor (pc 0x1d30b8 + 0x0021eba0 = 0x3f1c58),
 * then each global is `ldr rX,[pc,#imm]` (a NEGATIVE pool word) added to r4.
 * In this translation the five cells are named globals and the pool words are
 * only documented; harness/room_update_diff.py re-derives every slot from the
 * bytes (anchor + word) and refuses to grade if one moved.
 */
#include "room_update.h"

u32 UpdateActiveLists(u32 r0)
{
    u8 *r5p;   /* r5  &g_profile_switch (the cell's ADDRESS, not its value) */

    /* @0x1d30a4 push {r3, r4, r5, lr} */
    /* @0x1d30a8 ldr r4, [pc, #0x9c] */
    /* @0x1d30ac ldr r3, [pc, #0x9c] */
    /* @0x1d30b0 add r4, pc, r4 */
    /* @0x1d30b4 ldr r5, [r4, r3] */
    r5p = &g_profile_switch;
    /* @0x1d30b8 ldrb r3, [r5] */
    /* @0x1d30bc cmp r3, #0 */
    /* @0x1d30c0 bne 0x1d3134 */
    if (rd8(r5p) != 0) goto PUSH;

    /* ── check A: the activation queue (0x542a4c) ───────────────────────── */
CKA:
    /* @0x1d30c4 ldr r3, [pc, #0x88] */
    /* @0x1d30c8 ldr r3, [r4, r3] */
    /* @0x1d30cc ldr r3, [r3, #0x8] */
    /* @0x1d30d0 cmp r3, #0 */
    /* @0x1d30d4 bne 0x1d312c */
    if (rd32(g_list_activate + LIST_COUNT) != 0) goto HANDLER_A;

    /* ── check B: the object-type queue (0x542a64) ──────────────────────── */
CKB:
    /* @0x1d30d8 ldr r3, [pc, #0x78] */
    /* @0x1d30dc ldr r3, [r4, r3] */
    /* @0x1d30e0 ldr r3, [r3, #0x8] */
    /* @0x1d30e4 cmp r3, #0 */
    /* @0x1d30e8 bne 0x1d3124 */
    if (rd32(g_list_type + LIST_COUNT) != 0) goto HANDLER_B;

    /* ── check C: the depth queue (0x542a58) ────────────────────────────── */
CKC:
    /* @0x1d30ec ldr r3, [pc, #0x68] */
    /* @0x1d30f0 ldr r3, [r4, r3] */
    /* @0x1d30f4 ldr r3, [r3, #0x8] */
    /* @0x1d30f8 cmp r3, #0 */
    /* @0x1d30fc bne 0x1d311c */
    if (rd32(g_list_depth + LIST_COUNT) != 0) goto HANDLER_C;

    /* ── the exit: the switch byte is RE-READ here, not reused ──────────── */
EXIT:
    /* @0x1d3100 ldrb r3, [r5] */
    /* @0x1d3104 cmp r3, #0 */
    /* @0x1d3108 popeq {r3, r4, r5, pc} */
    if (rd8(r5p) == 0) return r0;
    /* @0x1d310c ldr r3, [pc, #0x4c] */
    /* @0x1d3110 ldr r0, [r4, r3] */
    r0 = (u32)(uintptr_t)&g_profiler[0];
    /* @0x1d3114 pop {r3, r4, r5, lr} */
    /* @0x1d3118 b 0x2a08ac */
    return CProfiler_Pop(&g_profiler[0]);   /* tail jump */

    /* ── the three handlers; each returns into the NEXT check ───────────── */
HANDLER_C:
    /* @0x1d311c bl 0x1d2ee8 */
    r0 = ChangeInstanceDepths();
    /* @0x1d3120 b 0x1d3100 */
    goto EXIT;
HANDLER_B:
    /* @0x1d3124 bl 0x1d2ea0 */
    r0 = ChangeInstanceTypes();
    /* @0x1d3128 b 0x1d30ec */
    goto CKC;
HANDLER_A:
    /* @0x1d312c bl 0x1d3074 */
    r0 = ProcessActivateDeactveLists(r0);
    /* @0x1d3130 b 0x1d30d8 */
    goto CKB;

    /* ── the profile push: (6, 7) are section / sub-item numbers ─────────── */
PUSH:
    /* @0x1d3134 ldr r3, [pc, #0x24] */
    /* @0x1d3138 mov r1, #6 */
    /* @0x1d313c mov r2, #7 */
    /* @0x1d3140 ldr r0, [r4, r3] */
    r0 = (u32)(uintptr_t)&g_profiler[0];
    /* @0x1d3144 bl 0x2a0738 */
    r0 = CProfiler_Push(&g_profiler[0], 6, 7);
    /* @0x1d3148 b 0x1d30c4 */
    goto CKA;

    /* ── literal pool ────────────────────────────────────────────────────
     * 0x1d314c = 0x0021eba0  the .got anchor offset (added to pc 0x1d30b8)
     * 0x1d3150 = 0xffffbf18  -0x40e8 -> slot 0x3edb70 -> 0x757e7c
     * 0x1d3154 = 0xffffbff8  -0x4008 -> slot 0x3edc50 -> 0x542a4c
     * 0x1d3158 = 0xffffbff0  -0x4010 -> slot 0x3edc48 -> 0x542a64
     * 0x1d315c = 0xffffc454  -0x3bac -> slot 0x3ee0ac -> 0x542a58
     * 0x1d3160 = 0xffffbf1c  -0x40e4 -> slot 0x3edb74 -> 0x757e80
     *            (one word, used by BOTH the Push at 0x1d3134 and the Pop
     *             at 0x1d310c -- same slot, which is why they pair up)
     * llvm-objdump decodes the first as `eoreq lr, r1, r0, lsr #23` and the
     * rest as <unknown>; the census documents them as words. */
    /* @0x1d314c .word 0x0021eba0 */
    /* @0x1d3150 .word 0xffffbf18 */
    /* @0x1d3154 .word 0xffffbff8 */
    /* @0x1d3158 .word 0xffffbff0 */
    /* @0x1d315c .word 0xffffc454 */
    /* @0x1d3160 .word 0xffffbf1c */
}
