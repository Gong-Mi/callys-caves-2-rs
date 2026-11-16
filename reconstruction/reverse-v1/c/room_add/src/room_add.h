/*
 * room_add.h — the instance-registration chain of libyoyo ARMv7.
 *
 * Three bodies, one chain (all from the pinned image
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *
 *   F1  _ZN5CRoom11AddInstanceEP9CInstance                       @0x001ab654
 *       79 instructions + 2 literal-pool words  (0x1ab790/0x1ab794)
 *       u32 CRoom::AddInstance(CInstance*)            <- r0 = CRoom*, r1 = inst
 *   F2  _ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance        @0x001c5d18
 *       40 instructions + 1 literal-pool word   (0x1c5db8)
 *       u32 CLayerManager::AddInstance(CRoom*, CInstance*)  (declared void)
 *   F3  _ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance
 *       @0x001c5a38, 179 instructions + 5 literal-pool words (0x1c5d04..0x1c5d14)
 *       u32 CLayerManager::AddInstanceToLayer(CRoom*, CLayer*, CInstance*)
 *
 * F1 bls F2 (0x1ab730), F2 tail-jumps F3 (0x1c5d78), F3 tail-jumps
 * AddElementToLayer / UpdateInstanceActivation, and F1 tail-jumps
 * CollisionInsert (0x1ab73c).  The two tail jumps are `b`, not `bl`: the frame
 * is popped first, so the callee returns straight to F1's caller and the WORD
 * THIS CHAIN RETURNS IS THE TAIL-CALLEE'S r0, not `inst`.  F1's `mov r0, r4`
 * (0x1ab734) only seeds the register.
 *
 * r0 as a return value
 * --------------------
 * Every translation below keeps a variable named `r0` that mirrors the register
 * and returns it at the body's single exit, because the differential compares
 * the returned word on both arms.  For the three gate exits of F2 and the four
 * of F3 that word is r0 RESIDUE (the function is void: 0x1c5d18 never writes r0
 * on those paths, so it still holds the first argument).  This is not part of
 * anyone's contract; it is reproduced because it is what the bytes do, and a
 * future edit that "cleans it up" to `return 0` is exactly the kind of drift the
 * receipt is meant to show.
 *
 * The globals, and why the offsets are read rather than guessed
 * ------------------------------------------------------------
 * The three bodies reach five .bss cells through their own .got.  Every GOT
 * slot carries its R_ARM_RELATIVE addend in the FILE, so the cell addresses
 * below are read off the image (harness/room_add_diff.py re-reads them at run
 * time and refuses to grade if they moved):
 *
 *   slot 0x3edc4c -> 0x536f28  ms_ID2InstanceE, the id hash table
 *   slot 0x3ed92c -> 0x5428e8  the byte the F2 first gate reads (Zeus/debugger
 *                              presence, cards/LayerHelpers.c)
 *   slot 0x3f086c -> 0x542678  the 36 B CLayerInstanceElement pool
 *   slot 0x3f0ae8 -> 0x5425f0  the global element uid counter
 *   slot 0x3ed71c -> 0x3eb70c  a POINTER VARIABLE: *cell is the object whose
 *                              vtable+0xc is called on the too-many-variables
 *                              path (0x1c5c94..0x1c5cb4).  NOTE: the card says
 *                              0x3ed718 -> 0x479a94; the pc-relative arithmetic
 *                              in the body (pc 0x1c5ca4 + 0x00227a78) lands on
 *                              0x3ed71c, one slot earlier, and 0x3ed71c holds
 *                              0x3eb70c.  The harness stages THAT cell and
 *                              re-derives the slot from the bytes in binding()
 *
 * The pool cell and the uid cell are addressed through the GOT in F3 and both
 * are the structure itself (no second load); the error host is the only one of
 * the five with the extra indirection.
 *
 * VFP
 * ---
 * Two conversions matter and neither is a C cast:
 *   vcvt.s32.f32  (F2 0x1c5d80/0x1c5da0)  float -> int, truncate toward zero,
 *                 saturate to INT_MIN/INT_MAX, NaN -> 0.  C's (int) cast is
 *                 undefined out of range, so it is modelled bit-exactly in
 *                 vfp_f2i_trunc() below; the differential stages 0.9f, -0.9f,
 *                 2.9f, -2.9f, 2^31, -2^31, inf and NaN on +0x180 to grade it.
 *   vcvt.f32.s32  (F3 0x1c5bf8/0x1c5cd8)  int -> float, round to nearest even.
 *                 (float)(s32) is exactly that in C for every int32, so the
 *                 translation uses the cast and the differential pins its bit
 *                 pattern through the store to +0x180.
 *   vcmpe.f32 + vmrs + bls  (F1 0x1ab680..0x1ab688)  "cur_snapshot <= new_depth
 *                 OR unordered".  `!(a > b)` is the same predicate.
 */
#ifndef ROOM_ADD_H
#define ROOM_ADD_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;

/* ── raw accessors ───────────────────────────────────────────────────────────
 * Deliberately byte-wise: unsigned char may alias anything, so the compiler is
 * not allowed to cache one field across a store to another.  That keeps the
 * machine order of the predicated store runs intact (see F1's 0x1ab6f8 block).
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

static inline u32 f32bits(float f)
{
    union { u32 u; float f; } c;
    c.f = f;
    return c.u;
}

/* VFP vcvt.s32.f32, bit for bit: truncate toward zero, saturate, NaN -> 0. */
static inline s32 vfp_f2i_trunc(u32 b)
{
    u32 sign = b >> 31;
    u32 expo = (b >> 23) & 0xffu;
    u32 man = b & 0x7fffffu;
    s32 e;
    u64 m, v;

    if (expo == 0xffu)
        return man ? 0 : (sign ? (s32)0x80000000 : (s32)0x7fffffff);
    if (expo == 0)
        return 0;                       /* zero or subnormal: |v| < 1 */
    e = (s32)expo - 127;
    if (e < 0)
        return 0;                       /* |v| < 1 */
    m = (u64)(man | 0x800000u);
    if (e < 23)
        v = m >> (23 - e);
    else if (e <= 40)
        v = m << (e - 23);
    else
        v = 0x100000000ull;             /* >= 2^32: saturate below */
    if (v > 0x7fffffffull)
        return sign ? (s32)0x80000000 : (s32)0x7fffffff;
    return sign ? -(s32)v : (s32)v;
}

/* ── CRoom ──────────────────────────────────────────────────────────────────
 * The instance chain is the depth-descending list at +0x80/+0x84/+0x88; the
 * sort key is the SNAPSHOT +0x184, never the live depth +0x180.
 */
#define ROOM_INST_TAIL    0x80u
#define ROOM_INST_HEAD    0x84u
#define ROOM_INST_COUNT   0x88u

/* Table 3, the int -> CLayerInstanceElement map: a 20 B cluster at +0x110 and
 * 12 B buckets {key@0, value@4, hash@8}.  F3 reads the mask at +0x118 and the
 * bucket array at +0x120; the probe step uses the capacity at +0x110. */
#define ROOM_T3_CAPACITY  0x110u
#define ROOM_T3_USED      0x114u
#define ROOM_T3_MASK      0x118u
#define ROOM_T3_THRESHOLD 0x11cu
#define ROOM_T3_BUCKETS   0x120u
#define T3_BUCKET_STRIDE  12
#define T3_KEY            0x0u
#define T3_VALUE          0x4u
#define T3_HASH           0x8u

/* ── CLayer ────────────────────────────────────────────────────────────────
 * +0x00 is the layer id (it becomes instance+0x170), +0x04 the layer depth as
 * an int (it becomes (float)instance+0x180).  Neither field name is proven.
 */
#define LAYER_ID     0x00u
#define LAYER_DEPTH  0x04u

/* ── CInstance, the eight fields this chain touches ───────────────────────── */
#define INST_DEACTIVATED  0x69u
#define INST_ID           0x78u
#define INST_LAYER_ID     0x170u
#define INST_IN_LAYER     0x174u
#define INST_PREV         0x178u
#define INST_NEXT         0x17cu
#define INST_DEPTH        0x180u
#define INST_DEPTH_SNAP   0x184u

/* ── ms_ID2InstanceE ───────────────────────────────────────────────────────
 * Header 12 B {buckets@0, mask@4, count@8}; bucket 8 B {head@0, tail@4};
 * node 16 B {prev@0, next@4, key@8, value@0xc}, Alloc(16, Hash.h, 306, true),
 * inserted at the bucket TAIL with no duplicate check.
 */
#define IDT_BUCKETS        0x00u
#define IDT_MASK           0x04u
#define IDT_COUNT          0x08u
#define IDT_BUCKET_STRIDE  8
#define IDT_BUCKET_HEAD    0x0u
#define IDT_BUCKET_TAIL    0x4u
#define HNODE_PREV         0x0u
#define HNODE_NEXT         0x4u
#define HNODE_KEY          0x8u
#define HNODE_VALUE        0xcu
#define HNODE_SIZE         16

/* ── the 36 B CLayerInstanceElement pool ───────────────────────────────────
 * Pool header {head@0, tail@4, avail@8, capacity@0x10} (+0x0c is unused); the
 * free list is doubly linked through +0x14(next)/+0x18(prev) - the same pair
 * the live element chain uses.  Element {type@0, uid@4, flag@8(byte),
 * ?, next@0x14, prev@0x18, instance id@0x1c, instance@0x20}.
 */
#define POOL_HEAD       0x00u
#define POOL_TAIL       0x04u
#define POOL_AVAIL      0x08u
#define POOL_CAPACITY   0x10u
#define ELEM_TYPE       0x00u
#define ELEM_UID        0x04u
#define ELEM_FLAG       0x08u
#define ELEM_NEXT       0x14u
#define ELEM_PREV       0x18u
#define ELEM_INST_ID    0x1cu
#define ELEM_INSTANCE   0x20u
#define ELEM_SIZE       36u

/* ── the five cells, one per body that reads them ──────────────────────────
 * The driver defines them; the harness stages them at the same five .bss
 * addresses on the original-bytes arm.
 */
extern u32 g_id_table[3];        /* 0x536f28  F1 */
extern u32 g_zeus_byte;          /* 0x5428e8  F2 (only its low byte is read) */
extern u32 g_element_pool[5];    /* 0x542678  F3 */
extern u32 g_element_uid;        /* 0x5425f0  F3 */
extern u32 g_error_host_cell;    /* 0x3eb70c  F3, holds the host object* */

/* ── the three bodies ─────────────────────────────────────────────────────── */
u32 CRoom_AddInstance(void *room, void *inst);
u32 CLayerManager_AddInstance(void *room, void *inst);
u32 CLayerManager_AddInstanceToLayer(void *room, void *layer, void *inst);

/* ── callees ───────────────────────────────────────────────────────────────
 * Every one of these is UNRECOVERED and runs as an identical stub on both
 * arms; see room_add_diff.py for what each stub is and is not allowed to
 * assume.  They return u32 so the tail-call pass-through is observable.
 */
u32 MemoryManager_Alloc(u32 size, const char *file, int line, int flag);
u32 CHashMapCalculateHash(int key);
u32 CLayerManager_GetLayerFromID(void *room, int id);
u32 CLayerManager_GetLayerWithDepth(void *room, int depth, int flag);
u32 CLayerManager_AddDynamicLayer(void *room, int depth);
u32 CLayerManager_AddElementToLayer(void *room, void *layer, void *elem,
                                    int flag);
u32 CLayerManager_UpdateInstanceActivation(void *room, void *inst);
u32 CollisionInsert(void *inst);

#endif /* ROOM_ADD_H */
