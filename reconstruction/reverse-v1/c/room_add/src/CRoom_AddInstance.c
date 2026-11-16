/*
 * CRoom_AddInstance.c — static C translation of
 * _ZN5CRoom11AddInstanceEP9CInstance @0x001ab654 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 79 instructions + 2 literal-pool words (0x1ab790, 0x1ab794), 0x1ab654..
 * 0x1ab798 = 324 B.  This is the "object already exists" entry of the family:
 * it allocates nothing, builds no physics body and writes no field of the
 * instance except the three chain words +0x178 / +0x17c / +0x184.
 *
 * What it does, in order:
 *   1. room+0x88 += 1 -- unconditionally, before the empty-chain branch
 *      (0x1ab670/0x1ab674), so the count is right even for the first node;
 *   2. insert `inst` into the depth-DESCENDING chain at room+0x84 (head) /
 *      room+0x80 (tail): walk from the head while cur->+0x184 > inst->+0x180,
 *      then either tail-append (walk ran off the end) or splice in front of the
 *      first node whose snapshot is <= the new depth.  The comparison is
 *      vcmpe.f32/bls, i.e. "<= or unordered", so an equal-depth node is placed
 *      AFTER the new one: the new node goes in front;
 *   3. append a 16 B node to the id hash table ms_ID2InstanceE, at the bucket
 *      TAIL, with no duplicate check;
 *   4. bl CLayerManager::AddInstance(room, inst) -- the layer registration;
 *   5. pop the frame and `b CollisionInsert(inst)`.
 *
 * The two things this body does NOT do, which the differential pins:
 *   * it never reads inst+0x184 before writing it, and it never re-reads
 *     inst+0x180 after the first load: the sort key it publishes is a SNAPSHOT
 *     of +0x180 taken at entry (0x1ab66c / 0x1ab774);
 *   * it does not return `inst`.  0x1ab734 seeds r0 = inst, then 0x1ab73c is a
 *     `b` into CollisionInsert after the frame is popped -- so the caller
 *     receives CollisionInsert's r0.  With a void CollisionInsert that is `inst`
 *     in practice; the body guarantees nothing of the sort, and the harness's
 *     stub returns a distinctive word so both arms prove the pass-through.
 *
 * The id-hash insert (0x1ab6f8..0x1ab720) is a single predicated run: the flags
 * come from `cmp r1,#0` at 0x1ab6e4 and are not touched again, so every store
 * in it belongs to the same "was the bucket empty" decision.  The translation
 * keeps the machine order with one `if (head != 0)` per store instead of
 * merging them into an if/else, because the two halves interleave with the
 * unconditional 0x1ab70c / 0x1ab718 loads.
 */
#include "room_add.h"

/* The layer-registration step (0x1ab730) and the tail-jumped collision insert
 * (0x1ab73c).  Both are linked translations/stubs in the harness. */
u32 CLayerManager_AddInstance(void *room, void *inst);
u32 CollisionInsert(void *inst);

u32 CRoom_AddInstance(void *room, void *inst)
{
    u8 *const r6 = (u8 *)room;
    u8 *const r4 = (u8 *)inst;
    u8 *cur;            /* r3  the walk cursor, then the freed 0 of the exits */
    u32 cnt;            /* r2  room+0x88, then the hash bucket page */
    u32 s14 = 0;        /* the VFP register: inst+0x180 as a raw word */
    u8 *map;            /* r5  ms_ID2InstanceE */
    u8 *node;           /* r0/r3 the new 16 B node */
    u8 *bucket;         /* r2  buckets + 8*idx */
    u8 *head;           /* r1  bucket->head, then bucket->tail */
    u32 id;             /* r9  inst+0x78 */
    u32 idx;            /* r8  id & mask */
    int empty;          /* the "bucket was empty" predicate of 0x1ab6e4 */
    int peq;            /* the "cur->prev == 0" predicate of 0x1ab744 */
    /* @0x1ab654 push {r3, r4, r5, r6, r7, r8, r9, lr} */
    /* @0x1ab658 mov r6, r0 */

    /* @0x1ab65c ldr r3, [r0, #0x84] */
    cur = (u8 *)(uintptr_t)rd32(r6 + ROOM_INST_HEAD);
    /* @0x1ab660 mov r4, r1 */
    /* @0x1ab664 ldr r2, [r0, #0x88] */
    cnt = rd32(r6 + ROOM_INST_COUNT);
    /* 0x1ab668: the head test.  Everything between here and 0x1ab674 is
     * predicated on it: the depth load is `vldrne`, the count update is not. */
    /* @0x1ab668 cmp r3, #0 */
    /* @0x1ab66c vldrne s14, [r1, #384] */
    if (cur != 0) s14 = rd32(r4 + INST_DEPTH);
    /* @0x1ab670 add r2, r2, #1 */
    cnt += 1;
    /* @0x1ab674 str r2, [r0, #0x88] */
    wr32(r6 + ROOM_INST_COUNT, cnt);
    /* @0x1ab678 beq 0x1ab774 */
    if (cur == 0) goto EMPTY;

    /* ── the ordered walk ────────────────────────────────────────────────
     * `vcmpe.f32 s15, s14` (cur snapshot vs new depth) then `bls`: taken
     * when cur <= new OR unordered.  Unconditional-clear (no `e`) keeps the
     * unordered case on the bls side, which is what !(a > b) says in C. */
    /* @0x1ab67c vldr s15, [r3, #388] */
    /* @0x1ab680 vcmpe.f32 s15, s14 */
    /* @0x1ab684 vmrs APSR_nzcv, fpscr */
    /* @0x1ab688 bls 0x1ab740 */
    for (;;) {
        if (!(f32(rd32(cur + INST_DEPTH_SNAP)) > f32(s14))) goto BEFORE;
        /* @0x1ab68c ldr r3, [r3, #0x17c] */
        cur = (u8 *)(uintptr_t)rd32(cur + INST_NEXT);
        /* @0x1ab690 cmp r3, #0 */
        /* @0x1ab694 bne 0x1ab67c */
        if (cur == 0) break;
    }

    /* ── tail append: the walk ran off the end (r3 == 0) ──────────────────
     * room+0x80 is the TAIL pointer, so this links after the old tail and
     * republishes room+0x80; room+0x84 is untouched. */
    /* @0x1ab698 ldr r2, [r6, #0x80] */
    cur = (u8 *)(uintptr_t)rd32(r6 + ROOM_INST_TAIL);
    /* @0x1ab69c vstr s14, [r4, #388] */
    wr32(r4 + INST_DEPTH_SNAP, s14);
    /* @0x1ab6a0 str r4, [r2, #0x17c] */
    wr32(cur + INST_NEXT, (u32)(uintptr_t)r4);
    /* @0x1ab6a4 str r2, [r4, #0x178] */
    wr32(r4 + INST_PREV, (u32)(uintptr_t)cur);
    /* @0x1ab6a8 str r4, [r6, #0x80] */
    wr32(r6 + ROOM_INST_TAIL, (u32)(uintptr_t)r4);
    /* @0x1ab6ac str r3, [r4, #0x17c] */
    wr32(r4 + INST_NEXT, 0);        /* r3, which the loop exit left at 0 */

    /* ── the id hash insert ───────────────────────────────────────────────
     * 0x1ab6b0 loads the pool word 0x1ab790 = 0x00242584 and 0x1ab6c0 adds
     * it to pc 0x1ab6c8 -> GOT 0x3edc4c -> .bss 0x536f28: the cell IS the
     * 12 B header, hence the single `ldm r5, {r7, r8}` that fetches the
     * bucket array and the mask together. */
HASH:
    /* @0x1ab6b0 ldr r5, [pc, #0xd8] */
    /* @0x1ab6b4 movw r2, #0x132 */
    /* @0x1ab6b8 ldr r1, [pc, #0xd4] */
    /* @0x1ab6bc mov r3, #1 */
    /* @0x1ab6c0 ldr r5, [pc, r5] */
    map = (u8 *)g_id_table;
    /* @0x1ab6c4 mov r0, #16 */
    /* @0x1ab6c8 add r1, pc, r1 */
    /* @0x1ab6cc ldr r9, [r4, #0x78] */
    id = rd32(r4 + INST_ID);
    /* @0x1ab6d0 ldm r5, {r7, r8} */
    bucket = (u8 *)(uintptr_t)rd32(map + IDT_BUCKETS);   /* r7 */
    idx = rd32(map + IDT_MASK);                          /* r8, then the index */
    /* @0x1ab6d4 bl 0x27ce78 */
    node = (u8 *)(uintptr_t)MemoryManager_Alloc(
        HNODE_SIZE, "jni/../jni/yoyo/../../../Platform/Hash.h", 0x132,
        1);
    /* @0x1ab6d8 and r8, r9, r8 */
    idx = id & idx;
    /* @0x1ab6dc ldr r1, [r7, r8, lsl #3] */
    head = (u8 *)(uintptr_t)rd32(bucket + idx * IDT_BUCKET_STRIDE);
    /* @0x1ab6e0 add r2, r7, r8, lsl #3 */
    bucket = bucket + idx * IDT_BUCKET_STRIDE;
    /* @0x1ab6e4 cmp r1, #0 */
    /* @0x1ab6e8 ldrne r1, [r2, #0x4] */
    empty = (head == 0);
    if (!empty) head = (u8 *)(uintptr_t)rd32(bucket + IDT_BUCKET_TAIL);
    /* @0x1ab6ec mov r3, r0 */
    /* r3 := node.  From 0x1ab6ec on, `r3` names the node and `r0` is
     * either the node (empty bucket) or 0 (non-empty) -- see 0x1ab6f8. */
    /* @0x1ab6f0 str r9, [r0, #0x8] */
    wr32(node + HNODE_KEY, id);
    /* @0x1ab6f4 str r4, [r0, #0xc] */
    wr32(node + HNODE_VALUE, (u32)(uintptr_t)r4);
    /* @0x1ab6f8 movne r0, #0 */
    /* @0x1ab6fc strne r1, [r3] */
    if (!empty) wr32(node + HNODE_PREV, (u32)(uintptr_t)head);
    /* @0x1ab700 strne r3, [r1, #0x4] */
    if (!empty) wr32(head + HNODE_NEXT, (u32)(uintptr_t)node);
    /* @0x1ab704 strne r3, [r2, #0x4] */
    if (!empty) wr32(bucket + IDT_BUCKET_TAIL, (u32)(uintptr_t)node);
    /* @0x1ab708 strne r0, [r3, #0x4] */
    if (!empty) wr32(node + HNODE_NEXT, 0);      /* r0 after `movne r0,#0` */
    /* @0x1ab70c ldr r3, [r5, #0x8] */
    cnt = rd32(map + IDT_COUNT);
    /* @0x1ab710 streq r0, [r2, #0x4] */
    if (empty) wr32(bucket + IDT_BUCKET_TAIL, (u32)(uintptr_t)node);
    /* @0x1ab714 streq r0, [r7, r8, lsl #3] */
    if (empty) wr32(bucket + IDT_BUCKET_HEAD, (u32)(uintptr_t)node);
    /* @0x1ab718 add r3, r3, #1 */
    cnt += 1;
    /* @0x1ab71c streq r1, [r0, #0x4] */
    if (empty) wr32(node + HNODE_NEXT, (u32)(uintptr_t)head);   /* head == 0 */
    /* @0x1ab720 streq r1, [r0] */
    if (empty) wr32(node + HNODE_PREV, (u32)(uintptr_t)head);   /* head == 0 */
    /* @0x1ab724 mov r0, r6 */
    /* @0x1ab728 mov r1, r4 */
    /* @0x1ab72c str r3, [r5, #0x8] */
    wr32(map + IDT_COUNT, cnt);
    /* @0x1ab730 bl 0x1c5d18 */
    (void)CLayerManager_AddInstance(room, inst);
    /* @0x1ab734 mov r0, r4 */
    /* @0x1ab738 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
    /* @0x1ab73c b 0x1cc494 */
    /* THE RETURN VALUE IS THE TAIL CALLEE'S: 0x1ab734 seeds r0 = inst and
     * 0x1ab73c is `b`, not `bl`, after the frame is popped. */
    return CollisionInsert(inst);

    /* ── splice in FRONT of cur: cur->+0x184 <= inst->+0x180 ─────────────
     * Every store from 0x1ab748 to 0x1ab768 is predicated on the ONE
     * `cmp r2,#0` at 0x1ab744 (r2 = cur->prev), which no instruction in
     * between re-tests -- hence the single `peq` predicate below.  When
     * cur is the head (prev == 0) the room head is republished; otherwise
     * the new node is spliced between prev and cur. */
BEFORE:
    /* @0x1ab740 ldr r2, [r3, #0x178] */
    head = (u8 *)(uintptr_t)rd32(cur + INST_PREV);
    /* @0x1ab744 cmp r2, #0 */
    peq = (head == 0);
    /* @0x1ab748 streq r3, [r4, #0x17c] */
        if (peq) wr32(r4 + INST_NEXT, (u32)(uintptr_t)cur);
    /* @0x1ab74c strne r2, [r4, #0x178] */
        if (!peq) wr32(r4 + INST_PREV, (u32)(uintptr_t)head);
    /* @0x1ab750 ldrne r2, [r3, #0x178] */
        if (!peq) head = (u8 *)(uintptr_t)rd32(cur + INST_PREV);  /* same word */
    /* @0x1ab754 streq r4, [r3, #0x178] */
        if (peq) wr32(cur + INST_PREV, (u32)(uintptr_t)r4);
    /* @0x1ab758 strne r3, [r4, #0x17c] */
        if (!peq) wr32(r4 + INST_NEXT, (u32)(uintptr_t)cur);
    /* @0x1ab75c streq r4, [r6, #0x84] */
        if (peq) wr32(r6 + ROOM_INST_HEAD, (u32)(uintptr_t)r4);
    /* @0x1ab760 strne r4, [r2, #0x17c] */
        if (!peq) wr32(head + INST_NEXT, (u32)(uintptr_t)r4);
    /* @0x1ab764 streq r2, [r4, #0x178] */
        if (peq) wr32(r4 + INST_PREV, (u32)(uintptr_t)head);
    /* @0x1ab768 strne r4, [r3, #0x178] */
        if (!peq) wr32(cur + INST_PREV, (u32)(uintptr_t)r4);
    /* @0x1ab76c vstr s14, [r4, #388] */
    wr32(r4 + INST_DEPTH_SNAP, s14);
    /* @0x1ab770 b 0x1ab6b0 */
    goto HASH;

    /* ── empty chain: head = tail = inst, snapshot = +0x180, links 0 ────
     * 0x1ab774 loads +0x180 as a WORD (`ldr`, not `vldr`) and stores it
     * verbatim into +0x184: the empty-chain branch copies the bit pattern,
     * it does not go through a float operation. */
EMPTY:
    /* @0x1ab774 ldr r2, [r1, #0x180] */
    cnt = rd32(r4 + INST_DEPTH);
    /* @0x1ab778 str r1, [r6, #0x84] */
    wr32(r6 + ROOM_INST_HEAD, (u32)(uintptr_t)r4);
    /* @0x1ab77c str r1, [r6, #0x80] */
    wr32(r6 + ROOM_INST_TAIL, (u32)(uintptr_t)r4);
    /* @0x1ab780 str r2, [r1, #0x184] */
    wr32(r4 + INST_DEPTH_SNAP, cnt);
    /* @0x1ab784 str r3, [r1, #0x17c] */
    wr32(r4 + INST_NEXT, 0);        /* r3 == 0 from the 0x1ab668 test */
    /* @0x1ab788 str r3, [r1, #0x178] */
    wr32(r4 + INST_PREV, 0);
    /* @0x1ab78c b 0x1ab6b0 */
    goto HASH;
}

    /* ── literal pool of the body ───────────────────────────────────────
     * 0x1ab790 = 0x00242584: added to pc 0x1ab6c8 -> GOT 0x3edc4c
     *             -> .bss 0x536f28 = ms_ID2InstanceE
     * 0x1ab794 = 0x001a15e4: added to pc 0x1ab6d0 -> 0x34ccb4
     *             = ".../Platform/Hash.h", the Alloc site string
     * Both are decoded as instructions by llvm-objdump (`eoreq`/`andseq`);
     * the census gate documents them as words. */
    /* @0x1ab790 .word 0x00242584 */
    /* @0x1ab794 .word 0x001a15e4 */
