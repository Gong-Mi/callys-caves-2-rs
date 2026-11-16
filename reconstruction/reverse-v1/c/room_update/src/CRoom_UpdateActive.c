/*
 * CRoom_UpdateActive.c — static C translation of
 * _ZN5CRoom12UpdateActiveEv @0x001abd9c in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 116 instructions, no literal-pool words, 0x1abd9c..0x1abf6c = 464 B, no
 * stack-frame extension (the body pushes r4/r5/r6/lr and nothing else).
 *
 * This is the body that decides, every frame, WHICH instances take part in
 * collision and which are dormant.  Two phases, walked in opposite directions,
 * each of them unlink-then-reinsert:
 *
 *   phase 1  cursor = room+0x8c (the DORMANT chain's TAIL), walk via +0x178
 *            (prev), and for every node with inst+0x69 == 0: unlink it from the
 *            dormant chain, decrement room+0x94, increment room+0x88, insert it
 *            into the ACTIVE chain by depth (walking from room+0x84), then
 *            CObjectGM::AddInstance(*(inst+0x80), inst).
 *   phase 2  cursor = room+0x80 (the ACTIVE chain's TAIL), walk via +0x178, and
 *            for every node with inst+0x69 != 0: unlink it, decrement
 *            room+0x88, increment room+0x94, HEAD-insert it into the dormant
 *            chain, then CObjectGM::RemoveInstance(*(inst+0x80), inst).
 *
 * Four branch pairs, all of them proven by the differential (COVER below):
 *   1 B->A  phase 1, +0x69 == 0                        (0x1abdcc / 0x1abdd0..)
 *   2 stay B phase 1, +0x69 != 0 -> only the cursor moves (0x1abdb4)
 *   3 A->B  phase 2, +0x69 != 0                        (0x1abe90 / 0x1abe94..)
 *   4 stay A phase 2, +0x69 == 0 -> only the cursor moves (0x1abe78)
 * The two predicates are complementary and +0x69 has NO write point in this
 * body (no strb anywhere), so an instance is moved at most once per call --
 * but phase 2 still walks the nodes phase 1 inserted (they hit branch 4).
 *
 * Three insert flavours on the active chain, all of them copying +0x180 into
 * +0x184 at insert time:
 *   0x1abf50  chain empty: head = tail = inst, links 0, and the copy is a
 *             WORD copy (`ldr r2,[r1,#0x180]` / `str r2,[r1,#0x184]`), not a
 *             float operation
 *   0x1abf1c  in front of the first node whose +0x184 <= inst+0x180
 *             (`vcmpe.f32 s15,s14` + `bls`).  MEASURED: `ls` is true only for
 *             an ORDERED <=, so an equal-depth node ends up AFTER the new one
 *             and a NaN on either side walks on exactly like "greater" does --
 *             a NaN depth sinks to the tail, it does not jump to the front.
 *             The C model is `a <= b`; `!(a > b)` is true for NaN and wrong
 *   0x1abe3c  the walk ran off the end: link after the old tail, republish
 *             room+0x80
 * The dormant chain has only two: empty (head and tail both become inst) and
 * head insert.  It never sorts and never touches +0x184.
 *
 * What the bytes make explicit and C makes implicit: both `bl`s take the
 * CObjectGM* read out of inst+0x80 in r0 and rely on r1 STILL holding the
 * instance pointer (no instruction between 0x1abe00 and 0x1abe54 writes r1).
 * The translation passes `cur` as the second argument, which is the same
 * register allocation the ARM ABI would have produced.
 */
#include "room_update.h"

u32 CRoom_UpdateActive(void *room)
{
    u8 *const rm = (u8 *)room;   /* r4  this */
    u8 *cur;                     /* r1  cursor; also the 2nd argument of a bl */
    u8 *prev;                    /* r5  the node's +0x178, saved BEFORE unlink */
    u8 *r3p;                     /* r3  next / cur / chain head / 0 */
    u32 r0v;                     /* r0  the count, then the CObjectGM* */
    u32 r2v;                     /* r2  counts, then cur->+0x178 */
    u32 s14 = 0;                 /* the word at inst+0x180 of the node moving */
    u32 r6 = 0;                  /* the zero register phase 2 head-inserts with */
    u32 deact;                   /* r3's byte before r3 is reused */
    int peq;                     /* the "cur->prev == 0" predicate of 0x1abf20 */
    int pz;                      /* the "dormant head == 0" predicate of 0x1abecc */

    r0v = (u32)(uintptr_t)room;  /* r0 enters as the argument; nothing writes it
                                  * until 0x1abe54 / 0x1abf08, so an untouched
                                  * body returns `room` -- the residue rule */
    /* @0x1abd9c ldr r1, [r0, #0x8c] */
    cur = (u8 *)(uintptr_t)rd32(rm + ROOM_B_TAIL);
    /* @0x1abda0 push {r4, r5, r6, lr} */
    /* @0x1abda4 cmp r1, #0 */
    /* @0x1abda8 mov r4, r0 */
    /* @0x1abdac bne 0x1abdc0 */
    if (cur == 0) goto P2_ENTRY;
    /* @0x1abdb0 b 0x1abe64 */
    goto P1_BODY;                /* the dormant chain is empty */

    /* ── phase 1: the branch-2 landing pad (cursor only) ───────────────── */
P1_SKIP:
    /* @0x1abdb4 cmp r5, #0 */
    /* @0x1abdb8 beq 0x1abe64 */
    if (prev == 0) goto P2_ENTRY;
    /* @0x1abdbc mov r1, r5 */
    cur = prev;

    /* ── phase 1 body: read the flag and prev, then decide ─────────────── */
P1_BODY:
    /* @0x1abdc0 ldrb r3, [r1, #0x69] */
    deact = rd8(cur + INST_DEACT);
    /* @0x1abdc4 ldr r5, [r1, #0x178] */
    prev = (u8 *)(uintptr_t)rd32(cur + INST_PREV);
    /* @0x1abdc8 cmp r3, #0 */
    /* @0x1abdcc bne 0x1abdb4 */
    if (deact != 0) goto P1_SKIP;   /* branch 2: dormant, leave it */

    /* ── unlink from the DORMANT chain: next==0 -> tail, prev==0 -> head ──
     * 0x1abde8/0x1abdec is the compiler merging both predicate arms of
     * `ldrne r2,[r1,#0x178]` / `moveq r2,r5`: r5 IS prev in both, so r2 is
     * simply prev and no branch is needed.  Same for r3 (next). */
    /* @0x1abdd0 ldr r3, [r1, #0x17c] */
    r3p = (u8 *)(uintptr_t)rd32(cur + INST_NEXT);
    /* @0x1abdd4 ldr r0, [r4, #0x94] */
    r0v = rd32(rm + ROOM_B_COUNT);
    /* @0x1abdd8 cmp r3, #0 */
    /* @0x1abddc streq r5, [r4, #0x8c] */
    if (r3p == 0) wr32(rm + ROOM_B_TAIL, (u32)(uintptr_t)prev);
    /* @0x1abde0 strne r5, [r3, #0x178] */
    if (r3p != 0) wr32(r3p + INST_PREV, (u32)(uintptr_t)prev);
    /* @0x1abde4 sub r0, r0, #1 */
    r0v -= 1;                        /* the dormant count */
    /* @0x1abde8 ldrne r2, [r1, #0x178] */
    /* @0x1abdec moveq r2, r5 */
    r2v = (u32)(uintptr_t)prev;
    /* @0x1abdf0 ldrne r3, [r1, #0x17c] */
    /* @0x1abdf4 cmp r2, #0 */
    /* @0x1abdf8 streq r3, [r4, #0x90] */
    if (r2v == 0) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)r3p);
    /* @0x1abdfc strne r3, [r2, #0x17c] */
    if (r2v != 0) wr32((u8 *)(uintptr_t)r2v + INST_NEXT,
                                (u32)(uintptr_t)r3p);

    /* ── the ACTIVE-chain insert, common front end ────────────────────────
     * The depth is loaded with `vldrne`, i.e. only when the chain is
     * non-empty; both counts are written unconditionally, before the
     * branch, and in this order (dormant first, then active). */
    /* @0x1abe00 ldr r3, [r4, #0x84] */
    r3p = (u8 *)(uintptr_t)rd32(rm + ROOM_A_HEAD);
    /* @0x1abe04 ldr r2, [r4, #0x88] */
    r2v = rd32(rm + ROOM_A_COUNT);
    /* @0x1abe08 cmp r3, #0 */
    /* @0x1abe0c str r0, [r4, #0x94] */
    wr32(rm + ROOM_B_COUNT, r0v);
    /* @0x1abe10 add r2, r2, #1 */
    r2v += 1;
    /* @0x1abe14 vldrne s14, [r1, #384] */
    if (r3p != 0) s14 = rd32(cur + INST_DEPTH);
    /* @0x1abe18 str r2, [r4, #0x88] */
    wr32(rm + ROOM_A_COUNT, r2v);
    /* @0x1abe1c beq 0x1abf50 */
    if (r3p == 0) goto A_EMPTY;

    /* ── the depth walk ───────────────────────────────────────────────────
     * `vcmpe.f32 s15, s14` compares the CURSOR SNAPSHOT (+0x184) against
     * the new node's LIVE depth (+0x180), then `bls`.  MEASURED, not
     * assumed: VCMP leaves FPSCR = 0110 on equal, 0010 on greater,
     * 1000 on less and 0011 on UNORDERED (C=1, Z=0), so `ls` is true only
     * for an ORDERED cur <= new.  An unordered compare walks on exactly
     * like "greater" does, which is `a <= b` in C -- `!(a > b)` would be
     * wrong: it is true for NaN and would insert the node at the front.
     * See scratch wlROOMUPD_fpflags2.py for the 7-row measurement. */
A_WALK:
    /* @0x1abe20 vldr s15, [r3, #388] */
    /* @0x1abe24 vcmpe.f32 s15, s14 */
    /* @0x1abe28 vmrs APSR_nzcv, fpscr */
    /* @0x1abe2c bls 0x1abf1c */
    if (f32(rd32(r3p + INST_SNAP)) <= f32(s14)) goto A_FRONT;
    /* @0x1abe30 ldr r3, [r3, #0x17c] */
    r3p = (u8 *)(uintptr_t)rd32(r3p + INST_NEXT);
    /* @0x1abe34 cmp r3, #0 */
    /* @0x1abe38 bne 0x1abe20 */
    if (r3p != 0) goto A_WALK;
            else goto T_APPEND;  /* bne not taken: fall into the tail */

    /* ── tail append (the walk ran off the end) ──────────────────────────
     * room+0x80 is the TAIL: link after the old tail and republish it.
     * `str r3,[r1,#0x17c]` stores the 0 the loop exit left in r3. */
T_APPEND:
    /* @0x1abe3c ldr r2, [r4, #0x80] */
    r2v = rd32(rm + ROOM_A_TAIL);
    /* @0x1abe40 vstr s14, [r1, #388] */
    wr32(cur + INST_SNAP, s14);      /* publish the snapshot */
    /* @0x1abe44 str r1, [r2, #0x17c] */
    wr32((u8 *)(uintptr_t)r2v + INST_NEXT, (u32)(uintptr_t)cur);
    /* @0x1abe48 str r2, [r1, #0x178] */
    wr32(cur + INST_PREV, r2v);
    /* @0x1abe4c str r1, [r4, #0x80] */
    wr32(rm + ROOM_A_TAIL, (u32)(uintptr_t)cur);
    /* @0x1abe50 str r3, [r1, #0x17c] */
    wr32(cur + INST_NEXT, 0);        /* r3 == 0 here */

    /* ── AddInstance(*(inst+0x80), inst) and the phase-1 loop edge ──────── */
A_ADD:
    /* @0x1abe54 ldr r0, [r1, #0x80] */
    r0v = rd32(cur + INST_GM);
    /* @0x1abe58 bl 0x19e02c */
    r0v = CObjectGM_AddInstance((void *)(uintptr_t)r0v, cur);
    /* @0x1abe5c cmp r5, #0 */
    /* @0x1abe60 bne 0x1abdbc */
    if (prev != 0) { cur = prev; goto P1_BODY; }

    /* ── phase 2: A -> B ─────────────────────────────────────────────────
     * Entry re-reads the ACTIVE TAIL.  On an empty one the body pops and
     * returns with whatever r0 holds (the last bl's result, or `room`). */
P2_ENTRY:
    /* @0x1abe64 ldr r1, [r4, #0x80] */
    cur = (u8 *)(uintptr_t)rd32(rm + ROOM_A_TAIL);
    /* @0x1abe68 cmp r1, #0 */
    /* @0x1abe6c popeq {r4, r5, r6, pc} */
    if (cur == 0) return r0v;
    /* @0x1abe70 mov r6, #0 */
    r6 = 0;                          /* the zero register */
    /* @0x1abe74 b 0x1abe84 */
    goto P2_BODY;
P2_SKIP:
    /* @0x1abe78 cmp r5, #0 */
    /* @0x1abe7c popeq {r4, r5, r6, pc} */
    if (prev == 0) return r0v;
    /* @0x1abe80 mov r1, r5 */
    cur = prev;
P2_BODY:
    /* @0x1abe84 ldrb r3, [r1, #0x69] */
    deact = rd8(cur + INST_DEACT);
    /* @0x1abe88 ldr r5, [r1, #0x178] */
    prev = (u8 *)(uintptr_t)rd32(cur + INST_PREV);
    /* @0x1abe8c cmp r3, #0 */
    /* @0x1abe90 beq 0x1abe78 */
    if (deact == 0) goto P2_SKIP;   /* branch 4: still active */

    /* ── unlink from the ACTIVE chain (mirror of the phase-1 unlink) ─────── */
    /* @0x1abe94 ldr r3, [r1, #0x17c] */
    r3p = (u8 *)(uintptr_t)rd32(cur + INST_NEXT);
    /* @0x1abe98 ldr r0, [r4, #0x88] */
    r0v = rd32(rm + ROOM_A_COUNT);
    /* @0x1abe9c cmp r3, #0 */
    /* @0x1abea0 streq r5, [r4, #0x80] */
    if (r3p == 0) wr32(rm + ROOM_A_TAIL, (u32)(uintptr_t)prev);
    /* @0x1abea4 strne r5, [r3, #0x178] */
    if (r3p != 0) wr32(r3p + INST_PREV, (u32)(uintptr_t)prev);
    /* @0x1abea8 sub r0, r0, #1 */
    r0v -= 1;
    /* @0x1abeac ldrne r2, [r1, #0x178] */
    /* @0x1abeb0 moveq r2, r5 */
    r2v = (u32)(uintptr_t)prev;
    /* @0x1abeb4 ldrne r3, [r1, #0x17c] */
    /* @0x1abeb8 cmp r2, #0 */
    /* @0x1abebc streq r3, [r4, #0x84] */
    if (r2v == 0) wr32(rm + ROOM_A_HEAD, (u32)(uintptr_t)r3p);
    /* @0x1abec0 strne r3, [r2, #0x17c] */
    if (r2v != 0) wr32((u8 *)(uintptr_t)r2v + INST_NEXT,
                                (u32)(uintptr_t)r3p);

    /* ── the DORMANT-chain head insert ───────────────────────────────────
     * Both link words are cleared first, unconditionally (r6 == 0), and
     * then the one `cmp r3,#0` at 0x1abecc drives every remaining store:
     * non-empty republishes the head only, empty publishes head AND tail.
     * 0x1abee8 re-reads room+0x90 into r3 -- same value, the compiler
     * reusing the register after the predicated store. */
    /* @0x1abec4 ldr r3, [r4, #0x90] */
    r3p = (u8 *)(uintptr_t)rd32(rm + ROOM_B_HEAD);
    /* @0x1abec8 ldr r2, [r4, #0x94] */
    r2v = rd32(rm + ROOM_B_COUNT);
    /* @0x1abecc cmp r3, #0 */
    pz = (r3p == 0);
    /* @0x1abed0 str r6, [r1, #0x178] */
    wr32(cur + INST_PREV, r6);
    /* @0x1abed4 str r6, [r1, #0x17c] */
    wr32(cur + INST_NEXT, r6);
    /* @0x1abed8 add r2, r2, #1 */
    r2v += 1;                        /* the dormant count */
    /* @0x1abedc str r0, [r4, #0x88] */
    wr32(rm + ROOM_A_COUNT, r0v);
    /* @0x1abee0 str r2, [r4, #0x94] */
    wr32(rm + ROOM_B_COUNT, r2v);
    /* @0x1abee4 strne r1, [r3, #0x178] */
    if (!pz) wr32(r3p + INST_PREV, (u32)(uintptr_t)cur);
    /* @0x1abee8 ldrne r3, [r4, #0x90] */
    if (!pz) r3p = (u8 *)(uintptr_t)rd32(rm + ROOM_B_HEAD);
    /* @0x1abeec streq r1, [r4, #0x90] */
    if (pz) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)cur);
    /* @0x1abef0 streq r1, [r4, #0x8c] */
    if (pz) wr32(rm + ROOM_B_TAIL, (u32)(uintptr_t)cur);
    /* @0x1abef4 strne r3, [r1, #0x17c] */
    if (!pz) wr32(cur + INST_NEXT, (u32)(uintptr_t)r3p);
    /* @0x1abef8 streq r3, [r1, #0x17c] */
    if (pz) wr32(cur + INST_NEXT, (u32)(uintptr_t)r3p);
    /* @0x1abefc strne r1, [r4, #0x90] */
    if (!pz) wr32(rm + ROOM_B_HEAD, (u32)(uintptr_t)cur);
    /* @0x1abf00 streq r3, [r1, #0x178] */
    if (pz) wr32(cur + INST_PREV, (u32)(uintptr_t)r3p);
    /* @0x1abf04 strne r6, [r1, #0x178] */
    if (!pz) wr32(cur + INST_PREV, r6);

    /* ── RemoveInstance(*(inst+0x80), inst) and the exits ───────────────── */
    /* @0x1abf08 ldr r0, [r1, #0x80] */
    r0v = rd32(cur + INST_GM);
    /* @0x1abf0c bl 0x19e0fc */
    r0v = CObjectGM_RemoveInstance((void *)(uintptr_t)r0v, cur);
    /* @0x1abf10 cmp r5, #0 */
    /* @0x1abf14 bne 0x1abe80 */
    if (prev != 0) { cur = prev; goto P2_BODY; }
    /* @0x1abf18 pop {r4, r5, r6, pc} */
    return r0v;

    /* ── the "insert in front of cur" half, when cur->prev == 0 it is the
     * head and the room head moves; otherwise it is spliced behind
     * cur->prev.  Note 0x1abf2c re-reads cur->prev into r2 for the
     * `strne r1,[r2,#0x17c]` at 0x1abf3c. */
A_FRONT:
    /* @0x1abf1c ldr r2, [r3, #0x178] */
    r2v = rd32(r3p + INST_PREV);
    /* @0x1abf20 cmp r2, #0 */
    peq = (r2v == 0);
    /* @0x1abf24 streq r3, [r1, #0x17c] */
    if (peq) wr32(cur + INST_NEXT, (u32)(uintptr_t)r3p);
    /* @0x1abf28 strne r2, [r1, #0x178] */
    if (!peq) wr32(cur + INST_PREV, r2v);
    /* @0x1abf2c ldrne r2, [r3, #0x178] */
    if (!peq) r2v = rd32(r3p + INST_PREV);   /* same word */
    /* @0x1abf30 streq r1, [r3, #0x178] */
    if (peq) wr32(r3p + INST_PREV, (u32)(uintptr_t)cur);
    /* @0x1abf34 strne r3, [r1, #0x17c] */
    if (!peq) wr32(cur + INST_NEXT, (u32)(uintptr_t)r3p);
    /* @0x1abf38 streq r1, [r4, #0x84] */
    if (peq) wr32(rm + ROOM_A_HEAD, (u32)(uintptr_t)cur);
    /* @0x1abf3c strne r1, [r2, #0x17c] */
    if (!peq) wr32((u8 *)(uintptr_t)r2v + INST_NEXT,
                                 (u32)(uintptr_t)cur);
    /* @0x1abf40 streq r2, [r1, #0x178] */
    if (peq) wr32(cur + INST_PREV, r2v);      /* r2 == 0 */
    /* @0x1abf44 strne r1, [r3, #0x178] */
    if (!peq) wr32(r3p + INST_PREV, (u32)(uintptr_t)cur);
    /* @0x1abf48 vstr s14, [r1, #388] */
    wr32(cur + INST_SNAP, s14);
    /* @0x1abf4c b 0x1abe54 */
    goto A_ADD;

    /* ── the empty-chain first insert: WORD copy of +0x180 into +0x184 ──── */
A_EMPTY:
    /* @0x1abf50 ldr r2, [r1, #0x180] */
    r2v = rd32(cur + INST_DEPTH);
    /* @0x1abf54 str r1, [r4, #0x84] */
    wr32(rm + ROOM_A_HEAD, (u32)(uintptr_t)cur);
    /* @0x1abf58 str r1, [r4, #0x80] */
    wr32(rm + ROOM_A_TAIL, (u32)(uintptr_t)cur);
    /* @0x1abf5c str r2, [r1, #0x184] */
    wr32(cur + INST_SNAP, r2v);
    /* @0x1abf60 str r3, [r1, #0x17c] */
    wr32(cur + INST_NEXT, 0);        /* r3 == 0 */
    /* @0x1abf64 str r3, [r1, #0x178] */
    wr32(cur + INST_PREV, 0);
    /* @0x1abf68 b 0x1abe54 */
    goto A_ADD;
}
