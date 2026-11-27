/*
 * ProcessActivateDeactveLists.c — static C translation of
 * _Z27ProcessActivateDeactveListsv @0x001d3074
 * (10 instructions + 2 literal-pool words, 48 B).
 *
 * The only caller of CRoom::UpdateActive in the whole image, and the reason
 * that body runs at all: UpdateActiveLists calls this when the activation
 * queue's count is non-zero, this reads the CRoom singleton out of .bss
 * (slot 0x3ed930 -> 0x54298c, *cell == the room), calls UpdateActive, and then
 * clears the queue's count (0x1d3094, slot 0x3edc50 -> 0x542a4c, +8) so the
 * next frame's flush is a no-op.
 *
 * It is 10 instructions, it is fully determined by its two pool words, and
 * stubbing it would have left the "queue count -> which instances move this
 * frame" link untested.  It is therefore recovered and real-linked on BOTH
 * arms: the judge arm runs these bytes, the claim arm runs this translation,
 * and the judge arm's `bl 0x1abd9c` lands in the original UpdateActive while
 * the claim arm's call lands in the C one.
 *
 * r0: reads *0x54298c, passes it to UpdateActive, returns UpdateActive's r0
 * untouched (`pop {r3, pc}` right after the count store).  Callers ignore it;
 * the differential compares it, because "ignored" is not "unchanged".
 */
#include "room_update.h"

u32 ProcessActivateDeactveLists(u32 r0)
{
    /* r0 arrives unused: 0x1d3080 overwrites it with *0x54298c.  Case F3-c
     * stages a caller r0 that differs from the cell to prove the body does not
     * keep it. */
    /* @0x1d3074 push {r3, lr} */
    /* @0x1d3078 ldr r3, [pc, #0x1c] */
    /* @0x1d307c ldr r3, [pc, r3] */
    /* @0x1d3080 ldr r0, [r3] */
    r0 = rd32(&g_run_room);          /* *0x54298c == the CRoom* */
    /* @0x1d3084 bl 0x1abd9c */
    r0 = CRoom_UpdateActive((void *)(uintptr_t)r0);
    /* @0x1d3088 ldr r3, [pc, #0x10] */
    /* @0x1d308c mov r2, #0 */
    /* @0x1d3090 ldr r3, [pc, r3] */
    /* @0x1d3094 str r2, [r3, #0x8] */
    wr32(g_list_activate + LIST_COUNT, 0);
    /* @0x1d3098 pop {r3, pc} */
    return r0;

    /* ── literal pool ────────────────────────────────────────────────────
     * 0x1d309c = 0x0021a8ac: added to pc 0x1d3084 -> .got 0x3ed930
     *             -> .bss 0x54298c (Run_Room, a POINTER cell)
     * 0x1d30a0 = 0x0021abb8: added to pc 0x1d3098 -> .got 0x3edc50
     *             -> .bss 0x542a4c (the activation queue, the same cell
     *                check A of UpdateActiveLists reads) */
    /* @0x1d309c .word 0x0021a8ac */
    /* @0x1d30a0 .word 0x0021abb8 */
}
