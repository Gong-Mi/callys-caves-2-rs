/*
 * room_update.h — the per-frame activation/deactivation machinery of libyoyo
 * ARMv7 (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Three bodies, one call chain, all recovered here and all running for real on
 * BOTH arms of harness/room_update_diff.py:
 *
 *   F1  _ZN5CRoom12UpdateActiveEv                     @0x001abd9c
 *       116 instructions, no literal pool, no stack-frame extension, 464 B.
 *       void CRoom::UpdateActive()      with r0 = this (CRoom*)
 *   F2  _Z17UpdateActiveListsv                        @0x001d30a4
 *       42 instructions + 6 literal-pool words (0x1d314c..0x1d3160), 192 B.
 *       void UpdateActiveLists()        no arguments
 *   F3  _Z27ProcessActivateDeactveListsv              @0x001d3074
 *       10 instructions + 2 literal-pool words (0x1d309c/0x1d30a0), 48 B.
 *       void ProcessActivateDeactveLists()   no arguments
 *
 * F2 is the frame's queue flusher: it checks three 12 B deferred lists and runs
 * F3 / ChangeInstanceTypes / ChangeInstanceDepths when their +8 count is
 * non-zero.  F3 is the only caller of F1 in the whole image (0x1d3084), and it
 * clears F1's queue count immediately afterwards (0x1d3094) — so F3 is included
 * here: it is 10 instructions, it is what makes the "which instances take part
 * in collision / activation this frame" story run end to end, and stubbing it
 * would have hidden the only cross-body link either card can prove.
 *
 * ── the two instance chains (rev1 cards/CRoom_UpdateActive.c) ───────────────
 *   A chain (ACTIVE)   head room+0x84, tail room+0x80, count room+0x88
 *                      depth DESCENDING; the sort key is the SNAPSHOT at
 *                      inst+0x184, never the live depth at inst+0x180
 *   B chain (DORMANT)  head room+0x90, tail room+0x8c, count room+0x94
 *                      head-inserted, unordered, no sort key
 *   instance           +0x178 prev, +0x17c next (shared by both chains, so an
 *                      instance is on exactly one of them)
 *                      +0x69  u8 "not active" flag, READ ONLY by F1
 *                      +0x80  CObjectGM* (the 1st argument of the two bls)
 *   The two phases are complementary (phase 1 moves only ACTIVE instances
 *   B -> A, phase 2 only INACTIVE ones A -> B) and the flag has no write point
 *   inside F1, so a given instance is moved at most once per call -- but phase
 *   2 walks the WHOLE A chain, including the nodes phase 1 just inserted.
 *
 * ── the three deferred lists (rev1 cards/UpdateActiveLists.c) ──────────────
 *   12 B each, {items@+0, aux@+4, count@+8}, in one .bss cluster:
 *     0x542a4c  A: instances whose activation changed  -> ProcessActivateDeactveLists
 *     0x542a58  C: instances whose depth changed       -> ChangeInstanceDepths
 *     0x542a64  B: instances whose object type changed -> ChangeInstanceTypes
 *   The three addresses were not taken from the names: each handler body
 *   re-derives its own list through its own .got slot, and the two derivations
 *   agree (see GOT_DERIVATION in the harness).  The count is tested with
 *   `cmp / bne`, i.e. NON-ZERO rather than positive: a negative count flushes
 *   the queue exactly like a positive one (teeth: ual_count_positive_only).
 *
 * ── globals: five named cells, all in .bss ─────────────────────────────────
 *   slot 0x3edb70 -> 0x757e7c   u8 profile switch (read at entry AND at exit)
 *   slot 0x3edb74 -> 0x757e80   the CProfiler object (address == `this`)
 *   slot 0x3edc50 -> 0x542a4c   list A
 *   slot 0x3edc48 -> 0x542a64   list B
 *   slot 0x3ee0ac -> 0x542a58   list C
 *   slot 0x3ed930 -> 0x54298c   `Run_Room`: a POINTER cell, *cell is the CRoom*
 *   The bodies reach all of them through one .got anchor (r4 = pc 0x1d30b8 +
 *   0x0021eba0 = 0x3f1c58) plus negative offsets for F2 and positive pc-relative
 *   words for F3; every slot is R_ARM_RELATIVE, so the targets are this
 *   module's own .bss and cannot be resolved from a symbol table.
 *
 * ── r0 residue ─────────────────────────────────────────────────────────────
 * None of the three bodies has a meaningful return value.  All three keep a
 * `r0` that mirrors the machine register and is what the harness compares as
 * `ret`, because the machine register is observable: F1 leaves either `room`
 * (nothing moved) or the CObjectGM* it last passed (0x1abe54 / 0x1abf08), F2
 * leaves the last handler's r0, F3 passes F1's r0 straight through.  A future
 * "clean-up" to `return 0` is exactly the drift this file is meant to expose.
 */
#ifndef ROOM_UPDATE_H
#define ROOM_UPDATE_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;

/* ── raw accessors ───────────────────────────────────────────────────────────
 * Byte-wise on purpose: `unsigned char` may alias anything, so the compiler may
 * not cache one field across a store to another.  F1's predicated store runs
 * re-read fields they just wrote (0x1abde8 / 0x1abf2c) and the machine order has
 * to survive.
 */
static inline u32 rd32(const void *p)
{
    const u8 *b = (const u8 *)p;
    return (u32)b[0] | ((u32)b[1] << 8) | ((u32)b[2] << 16) | ((u32)b[3] << 24);
}

static inline void wr32(void *p, u32 v)
{
    u8 *b = (u8 *)p;
    b[0] = (u8)v;
    b[1] = (u8)(v >> 8);
    b[2] = (u8)(v >> 16);
    b[3] = (u8)(v >> 24);
}

static inline u8 rd8(const void *p) { return *(const u8 *)p; }
static inline void wr8(void *p, u8 v) { *(u8 *)p = v; }

static inline float f32(u32 bits)
{
    union { u32 u; float f; } c;
    c.u = bits;
    return c.f;
}

/* ── CRoom ────────────────────────────────────────────────────────────────── */
#define ROOM_A_TAIL   0x80u    /* room+0x80  active chain tail   */
#define ROOM_A_HEAD   0x84u    /* room+0x84  active chain head   */
#define ROOM_A_COUNT  0x88u    /* room+0x88  active chain count  */
#define ROOM_B_TAIL   0x8cu    /* room+0x8c  dormant chain tail  */
#define ROOM_B_HEAD   0x90u    /* room+0x90  dormant chain head  */
#define ROOM_B_COUNT  0x94u    /* room+0x94  dormant chain count */

/* ── CInstance, the six fields this chain touches ─────────────────────────── */
#define INST_DEACT    0x69u    /* u8: non-zero == NOT active (read only) */
#define INST_GM       0x80u    /* CObjectGM*: first argument of both bls */
#define INST_PREV     0x178u
#define INST_NEXT     0x17cu
#define INST_DEPTH    0x180u   /* f32, live depth (read only here) */
#define INST_SNAP     0x184u   /* f32, the insertion-time copy A sorts by */

/* ── the 12 B deferred-list cell ──────────────────────────────────────────── */
#define LIST_ITEMS    0x00u    /* u32[count] of CInstance* */
#define LIST_AUX      0x04u    /* unused by the three bodies (never read) */
#define LIST_COUNT    0x08u    /* u32, tested NON-ZERO */

/* ── the six globals, one per cell the bodies reach through the .got ──────── */
extern u8  g_list_activate[12];   /* 0x542a4c  F2 list A / F3 clears +8 */
extern u8  g_list_depth[12];      /* 0x542a58  F2 list C (ChangeInstanceDepths) */
extern u8  g_list_type[12];       /* 0x542a64  F2 list B (ChangeInstanceTypes) */
extern u8  g_profile_switch;      /* 0x757e7c  1 byte, read at entry and exit */
extern u8  g_profiler[4];         /* 0x757e80  the CProfiler object itself */
extern u32 g_run_room;            /* 0x54298c  *cell == the CRoom* */

/* ── the three bodies ───────────────────────────────────────────────────────
 * The two argument-less ones take r0 as a real C argument: r0 IS the first
 * argument register, so seeding it from the caller reproduces the machine
 * register they inherit, and returning it reproduces the residue.
 */
u32 CRoom_UpdateActive(void *room);
u32 UpdateActiveLists(u32 r0);
u32 ProcessActivateDeactveLists(u32 r0);

/* ── callees ───────────────────────────────────────────────────────────────
 * Every one of these is UNRECOVERED and runs as an identical stub on both
 * arms; see room_update_diff.py for what each stub is and is not allowed to
 * assume.  They return u32 so the r0 pass-through stays observable.
 */
u32 CObjectGM_AddInstance(void *gm, void *inst);      /* 0x19e02c */
u32 CObjectGM_RemoveInstance(void *gm, void *inst);   /* 0x19e0fc */
u32 ChangeInstanceTypes(void);                        /* 0x1d2ea0 */
u32 ChangeInstanceDepths(void);                       /* 0x1d2ee8 */
u32 CProfiler_Push(void *self, int a, int b);         /* 0x2a0738 */
u32 CProfiler_Pop(void *self);                        /* 0x2a08ac */
u32 RoomUpdate_Alloc(u32 size);                       /* the shared bump arena */

#endif /* ROOM_UPDATE_H */
