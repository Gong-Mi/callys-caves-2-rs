/*
 * CLayerManager_AddInstance.c — static C translation of
 * _ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance @0x001c5d18 in libyoyo
 * ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 40 instructions + 1 literal-pool word (0x1c5db8), 0x1c5d18..0x1c5dbc = 164 B.
 * The layer half of instance registration: four gates, then a three-level
 * "which layer does this instance belong to" decision, then a tail jump.
 *
 * The four gates, in machine order (order is semantics here):
 *   1. byte 0x5428e8 == 0          -> return   (0x1c5d2c..0x1c5d34)
 *      The cell is a POINTER-VARIABLE-free indirection: 0x1c5d20 loads the pool
 *      word 0x1c5db8, 0x1c5d28 adds it to pc 0x1c5d30 -> GOT 0x3ed92c, and the
 *      GOT slot's own addend 0x5428e8 IS the byte's address (no second load).
 *      Value 0 means "no debugger / not that mode" and the instance is NOT put
 *      on a layer at all -- cards/CLayerManager_AddInstance.c records that an
 *      earlier revision had this polarity backwards.
 *   2. room == 0                   -> return   (0x1c5d38)
 *   3. instance == 0               -> return   (0x1c5d40)
 *      Gates 2 and 3 test r0/r1, the ORIGINAL arguments, not the r5/r4 copies.
 *   4. instance+0x174 != 0         -> return   (0x1c5d48..0x1c5d50)
 *      "already on some layer's element chain".  Same byte F3 uses, so the pair
 *      (AddInstance, AddInstanceToLayer) is idempotent: a second call does
 *      nothing.
 *
 * The three levels, and the fact that all three end in the SAME tail jump:
 *   L1  0x1c5d54 takes instance+0x170 (the layer id the instance records).
 *       0x1c5d58 is `cmn r1,#1`, i.e. "is it -1?" -- the sentinel for "no layer
 *       recorded", which skips L1 entirely.  Otherwise GetLayerFromID(room, id);
 *       a non-NULL answer goes straight to the merge point.
 *   L2  0x1c5d7c loads instance+0x180 (a float) and 0x1c5d80 converts it with
 *       vcvt.s32.f32 (TRUNCATION toward zero, saturating, NaN -> 0 -- modelled
 *       bit-exactly by vfp_f2i_trunc), then GetLayerWithDepth(room, d, TRUE).
 *       The third argument is a hard `mov r2,#1`; with it the callee only
 *       accepts a layer whose +0x19 byte is set.  A NULL answer falls to L3.
 *   L3  0x1c5d9c repeats the same load and conversion and calls
 *       AddDynamicLayer(room, d), then keeps the result in r1.
 *   merge 0x1c5d6c..0x1c5d78: r0 = room, r2 = instance, pop, `b
 *       AddInstanceToLayer`.  r1 already holds the layer on every path (L1 via
 *       `subs r1,r0,#0`, L2 via `subs r1,r0,#0` + the bne, L3 via `mov r1,r0`).
 *
 * Note what the body does NOT do: it never re-reads +0x180 after the first load
 * inside each level, and it never writes a field of either structure.  All state
 * changes belong to F3.
 *
 * Return value: the function is DECLARED void, and everything past the merge
 * point is a tail jump, so its caller receives the tail callee's r0.  On the
 * four gate exits r0 is untouched residue (still the first argument).  The
 * translation mirrors r0 in a variable and returns it from each exit for the
 * reason spelled out in room_add.h -- the differential compares the word.
 */
#include "room_add.h"

/* Body below (0x1c5a38) and the three stubs this one dispatches to. */
u32 CLayerManager_AddInstanceToLayer(void *room, void *layer, void *inst);
u32 CLayerManager_GetLayerFromID(void *room, int id);
u32 CLayerManager_GetLayerWithDepth(void *room, int depth, int flag);
u32 CLayerManager_AddDynamicLayer(void *room, int depth);

u32 CLayerManager_AddInstance(void *room, void *inst)
{
    u8 *const r5 = (u8 *)room;
    u8 *const r4 = (u8 *)inst;
    u32 r0 = (u32)(uintptr_t)room;   /* r0, mirrored for the exits */
    u32 r1 = (u32)(uintptr_t)inst;   /* r1: instance, then the layer id, then layer */
    u32 r3;                          /* r3: the Zeus byte, then +0x174 */
    u32 layer;                       /* what L1/L2/L3 answered */
    s32 depth;                       /* vcvt.s32.f32 of instance+0x180 */
    /* @0x1c5d18 push {r3, r4, r5, lr} */
    /* @0x1c5d1c mov r4, r1 */
    /* @0x1c5d20 ldr r3, [pc, #0x90] */
    /* @0x1c5d24 mov r5, r0 */
    /* @0x1c5d28 ldr r3, [pc, r3] */
    /* @0x1c5d2c ldrb r3, [r3] */
    /* 0x1c5d2c is `ldrb`: the GOT addend is the BYTE's own address. */
    r3 = rd8((const u8 *)&g_zeus_byte);
    /* @0x1c5d30 cmp r3, #0 */
    /* @0x1c5d34 popeq {r3, r4, r5, pc} */
    if (r3 == 0) return r0;              /* byte 0 -> not registered */
    /* @0x1c5d38 cmp r0, #0 */
    /* @0x1c5d3c popeq {r3, r4, r5, pc} */
    if (room == 0) return r0;
    /* @0x1c5d40 cmp r1, #0 */
    /* @0x1c5d44 popeq {r3, r4, r5, pc} */
    if (inst == 0) return r0;
    /* @0x1c5d48 ldrb r3, [r1, #0x174] */
    r3 = rd8(r4 + INST_IN_LAYER);
    /* @0x1c5d4c cmp r3, #0 */
    /* @0x1c5d50 popne {r3, r4, r5, pc} */
    if (r3 != 0) return r0;              /* idempotence gate */

    /* ── L1: the layer id the instance records ──────────────────────────── */
    /* @0x1c5d54 ldr r1, [r1, #0x170] */
    r1 = rd32(r4 + INST_LAYER_ID);
    /* @0x1c5d58 cmn r1, #1 */
    /* @0x1c5d5c beq 0x1c5d7c */
    if (r1 == 0xffffffffu) goto LEVEL2;  /* -1 == "use the depth instead" */
    /* @0x1c5d60 bl 0x1b8868 */
    layer = CLayerManager_GetLayerFromID(room, (int)r1);
    /* @0x1c5d64 subs r1, r0, #0 */
    r1 = layer;                          /* subs r1, r0, #0 */
    /* @0x1c5d68 beq 0x1c5d7c */
    if (layer == 0) goto LEVEL2;

    /* ── merge: all three levels arrive here with the layer in r1 ───────── */
MERGE:
    /* @0x1c5d6c mov r0, r5 */
    r0 = (u32)(uintptr_t)r5;
    /* @0x1c5d70 mov r2, r4 */
    /* @0x1c5d74 pop {r3, r4, r5, lr} */
    /* @0x1c5d78 b 0x1c5a38 */
    return CLayerManager_AddInstanceToLayer(room, (void *)(uintptr_t)r1, r4);

    /* ── L2: the dynamic layer that already sits at this instance depth ─── */
LEVEL2:
    /* @0x1c5d7c vldr s15, [r4, #384] */
    r3 = rd32(r4 + INST_DEPTH);          /* the float, as a raw word */
    /* @0x1c5d80 vcvt.s32.f32 s15, s15 */
    depth = vfp_f2i_trunc(r3);            /* truncate toward zero */
    /* @0x1c5d84 mov r0, r5 */
    r0 = (u32)(uintptr_t)r5;
    /* @0x1c5d88 mov r2, #1 */
    /* @0x1c5d8c vmov r1, s15 */
    r1 = (u32)depth;                      /* vmov r1, s15 */
    /* @0x1c5d90 bl 0x1b87f4 */
    layer = CLayerManager_GetLayerWithDepth(room, (int)r1, 1);
    /* @0x1c5d94 subs r1, r0, #0 */
    r1 = layer;
    /* @0x1c5d98 bne 0x1c5d6c */
    if (layer != 0) goto MERGE;

    /* ── L3: no layer at that depth -> create one ────────────────────────── */
    /* @0x1c5d9c vldr s15, [r4, #384] */
    r3 = rd32(r4 + INST_DEPTH);          /* the same word, loaded again */
    /* @0x1c5da0 vcvt.s32.f32 s15, s15 */
    depth = vfp_f2i_trunc(r3);
    /* @0x1c5da4 mov r0, r5 */
    r0 = (u32)(uintptr_t)r5;
    /* @0x1c5da8 vmov r1, s15 */
    r1 = (u32)depth;
    /* @0x1c5dac bl 0x1c33e4 */
    layer = CLayerManager_AddDynamicLayer(room, (int)r1);
    /* @0x1c5db0 mov r1, r0 */
    r1 = layer;                          /* mov r1, r0 */
    /* @0x1c5db4 b 0x1c5d6c */
    goto MERGE;
}

    /* ── literal pool (1 word) ──────────────────────────────────────────
     * 0x1c5db8 = 0x00227bfc, added to pc 0x1c5d30 -> GOT 0x3ed92c, whose
     * addend 0x5428e8 is the Zeus byte.  llvm-objdump prints it as
     * `<unknown>`: it is the only word past the end of the body. */
    /* @0x1c5db8 .word 0x00227bfc */
