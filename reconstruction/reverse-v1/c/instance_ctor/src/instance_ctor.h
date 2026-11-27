/*
 * instance_ctor.h — CInstance identity/handle allocation, libyoyo ARMv7.
 *
 *   CInstance::SetObjectIndex(int, bool)        @0x0019324c
 *       0x0019324c..0x00193368, 0x11c = 284 B: 70 instructions + 1 literal-pool
 *       word at 0x00193364 (0x0025a9a8, the GOT displacement of g_ObjectHash).
 *       Symbol in the pinned image: _ZN9CInstance14SetObjectIndexEib.
 *
 *   CInstance::CInstance(float,float,int,int,bool)   @0x001994dc
 *       0x001994dc..0x001998e0, 0x404 = 1028 B: 249 instructions + 8 literal-pool
 *       words at 0x001998c0..0x001998dc.  Symbol: _ZN9CInstanceC2Effiib.
 *       The CRoom::AddInstance call site allocates 432 = 0x1b0 bytes before it,
 *       so sizeof(CInstance) = 0x1b0.
 *
 * Pinned image: 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 * (reconstruction/live-mem/libyoyo_armv7.so).
 *
 * Callee status — this is the scope of the differential, stated per callee:
 *
 *   CALLED BY SetObjectIndex
 *     0x0019e0fc  _ZN9CObjectGM14RemoveInstanceEP9CInstance   UNRECOVERED -> stub
 *     0x0019e02c  _ZN9CObjectGM11AddInstanceEP9CInstance      UNRECOVERED -> stub
 *     0x001931c0  _ZN9CInstance14SetSpriteIndexEi             UNRECOVERED -> stub
 *     0x001cc1d0  _Z18CollisionMarkDirtyP9CInstance           UNRECOVERED -> stub
 *
 *   CALLED BY the constructor
 *     0x0019188c  _ZN12YYObjectBaseC2Eii                      UNRECOVERED -> stub
 *     0x0019324c  _ZN9CInstance14SetObjectIndexEib            RECOVERED -> linked
 *                 for real on both arms: arm A runs the original bytes, arm B
 *                 runs src/set_object_index.c.  Nothing is stubbed there.
 *     0x0023f8f0  _Z18isGlobalBuiltinVarPKc                   UNRECOVERED -> stub
 *     0x0023ffac  _Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_
 *                                                             UNRECOVERED -> stub
 *     0x0019946c  _ZN12YYObjectBase3AddEPKcPS_i               UNRECOVERED -> stub
 *     0x000cef64  _Z9YYReallocPvi                             UNRECOVERED -> stub
 *     0x000b65b0  memset@plt                                  libc      -> stub
 *
 * Every stub is a fixture: it records its call and returns a fixed answer, and
 * the SAME behaviour is implemented on both arms (Python hook on arm A, the C
 * function below on arm B).  A green run therefore proves dispatch, field
 * offsets, constants, the object-hash walk, the instance-table scan/grow, the
 * builtin-registration loop and the argument plumbing of these two bodies — not
 * one byte of any callee, and not device behaviour.
 *
 * ── CInstance layout (the offsets these two bodies address) ────────────────
 *   0x000  u32  vtable (arm A: 0x3ebaf8; the fixture's own head+8 on arm B;
 *              the record normalises both to one symbol token)
 *   0x010  u32  creation stack trace 1   (base ctor writes when its gate is on;
 *   0x014  u32  creation stack trace 2    this ctor clears both at the end)
 *   0x044  i32  global instance-table slot (-1 when the table has no capacity)
 *   0x048  i32  1 at exit (base ctor leaves 0)
 *   0x064  u8   bbox dirty            (SetObjectIndex hit path only)
 *   0x065  u8   visible      <- obj flags bit1
 *   0x066  u8   solid        <- obj flags bit0
 *   0x067  u8   persistent   <- obj flags bit2
 *   0x068  u8   skip / 0x069 deactivated / 0x06a hard-destroy / 0x06b / 0x06c
 *   0x070  u64  ms_CurrentCreateCounter snapshot (ldrd/strd, lo at +0x70)
 *   0x078  i32  id (ctor argument 3)            0x07c  i32  objindex
 *   0x080  i32  CObjectGM* (0 when the hash misses; re-read after AddInstance)
 *   0x084  u32  physics / 0x088 skeleton (both 0 at exit)
 *   0x08c  i32  sprite index (written through SetSpriteIndex, not directly)
 *   0x090  i32  image_index      0x094 f32 image_speed   0x098 f32 image_xscale
 *   0x09c  f32  image_yscale     0x0a0 f32 image_angle   0x0a4 f32 image_alpha
 *   0x0a8  u32  image_blend (0x00ffffff)                 0x0ac i32 mask index
 *   0x0b4  f32  x    0x0b8 y    0x0bc xstart 0x0c0 ystart
 *   0x0c4  f32  xprevious 0x0c8 yprevious
 *   0x0cc  f32  direction 0x0d0 speed 0x0d4 friction 0x0d8 gravity_direction
 *   0x0dc  f32  gravity   0x0e0 hspeed 0x0e4 vspeed   0x0e8/0x0ec/0x0f0/0x0f4
 *   0x0f8  i32[12] alarm[0..11]  (0 after the first pass, -1 after the second)
 *   0x128  i32  path_index (-1)  0x12c/0x130/0x134 path position/speed (0)
 *   0x138  f32  path_scale (1.0f)  0x13c path_orientation (0)  0x140 path_endaction (0)
 *   0x144  u32  NOT WRITTEN by either body   0x148 u32 NOT WRITTEN
 *   0x14c  i32  timeline_index (-1)  0x150 (0)  0x154 timeline_position (0)
 *   0x158  f32  timeline_speed (1.0f)  0x15c/0x15d timeline running/loop (0)
 *   0x15e  u8   (0)   0x160/0x164 (0)  0x168 (0)  0x16c i32 = 2
 *   0x170  i32  layer (-1)  0x174 u8 (0)
 *   0x180  f32  depth (obj+0x08 through vcvt.f32.s32)  0x184 u32 (0)
 *   0x188  i32  -1   0x18c/0x190 collision-test list link (self ring), 0x194 head=0
 *   0x198/0x19c collision-dirty list link (self ring), 0x1a0 head=0
 *   0x1a4/0x1a8 handle list link (self ring), 0x1ac head=0
 *   0x1b0  end of the object (sizeof)
 *
 * ── CObjectGM, as these bodies address it ─────────────────────────────────
 *   +0x00 u32 flags (bit0 solid, bit1 visible, bit2 persistent; bits 3+ unused
 *              here)   +0x04 i32 sprite   +0x08 i32 depth (int, not float:
 *              one vldr + one vcvt.f32.s32)   +0x10 i32 mask
 *
 * ── the global object hash (g_ObjectHash, 0x00542374) ─────────────────────
 *   A POINTER variable reached through GOT 0x003edc44: [0x542374] -> table.
 *   table { +0x00 ic_bucket *buckets; +0x04 u32 mask }.  Bucket stride 8 B
 *   (ldr r3,[r3,r1,lsl #3]) and only the first word of a bucket is the chain
 *   head.  Node { +0x04 next; +0x08 i32 key; +0x0c value }.  +0x00 is never
 *   touched by these bodies (kept for the 16-byte stride the allocator uses).
 */
#ifndef INSTANCE_CTOR_H
#define INSTANCE_CTOR_H

#include <stdint.h>

/* ── arena layout: mirrored by harness/instance_ctor_diff.py, and checked ── */
#define IC_INST        0x000u     /* 0x1b0-byte CInstance, the `this` block   */
#define IC_OBJ1        0x200u     /* CObjectGM #1 (the one the hash answers)   */
#define IC_OBJ2        0x280u     /* CObjectGM #2 (a live old object)          */
#define IC_OBJ3        0x300u     /* CObjectGM #3 (the AddInstance probe)      */
#define IC_HASH        0x380u     /* hash table struct {buckets, mask}          */
#define IC_BUCKETS     0x3c0u     /* 8 buckets x 8 B                            */
#define IC_NODES       0x400u     /* 8 nodes x 16 B                             */
#define IC_TABLE       0x480u     /* global instance table {base,cap,count,next}*/
#define IC_TBLARR      0x4a0u     /* its slot array (4 B slots)                 */
#define IC_BPROPS      0x4c0u     /* reserved: the real builtin table lives at
                                     0x0075310c in the image, not in the arena;
                                     this span is only crossed by the slot-array
                                     clear and is never read                    */
#define IC_NAMES       0x500u     /* the entry names                            */
#define IC_PS          0x540u     /* the PS the JS_SetupBuiltinProperty stub
                                     answers with                               */
#define IC_GT1         0x560u     /* base ctor: the "+0x34/+0x3c global"        */
#define IC_GT2         0x564u     /* base ctor: creation stack trace slot       */
#define IC_HEAP        0x600u     /* bump allocator used by the YYRealloc stub  */
#define IC_ARENA_SIZE  0x1000u
#define IC_INST_SIZE   0x1b0u
#define IC_NBUCKET     8
#define IC_NNODE       8
#define IC_TBLCAP_MAX  8
#define IC_BPROPS_MAX  4
#define IC_HEAP_SIZE   0x400u
#define IC_HEAP_FILL   0x5bu      /* every byte the bump allocator hands out,
                                     before the caller writes it               */
#define IC_HEAP_GUARD  0xdeadbeefu/* written at block+size; a memset that runs
                                     past the block clobbers it                 */
#define IC_HASH_MASK   7u         /* IC_NBUCKET - 1                             */
#define IC_BUCKET_STRIDE 8
#define IC_NODE_STRIDE   16
#define IC_TBL_SLOT      4
#define IC_TBL_STRIDE    16       /* table struct: base, cap, count, next_free  */
#define IC_BPROP_STRIDE  16
#define IC_ALARM_BASE    0xf8u
#define IC_ALARM_COUNT   12
#define IC_ALARM_STRIDE  4
#define IC_VTABLE_OFF    8u       /* GOT 0x003f0694 -> 0x003ebaf0, +8            */
#define IC_BASE_ARG2     0x00ffffffu
#define IC_F_270         0x43870000u  /* 270.0f                                 */
#define IC_F_ONE         0x3f800000u  /* 1.0f                                   */
#define IC_SLOT_NONE     (-1)
#define IC_OBJINDEX_NONE 0
#define IC_TBL_LINE_GROW 3        /* cap*3/2                                   */

/* ── the two bodies ─────────────────────────────────────────────────────── */
struct ic_instance;      /* CInstance, fields by offset (see above)         */
struct ic_objectgm;      /* CObjectGM                                       */

/* void CInstance::SetObjectIndex(int objindex, bool addToObject) */
void CInstance_SetObjectIndex(struct ic_instance *self, int32_t objindex,
                              int32_t add_to_object);

/* CInstance *CInstance::CInstance(float x, float y, int id, int objindex,
 *                                 bool addToObject) */
struct ic_instance *CInstance_ctor(struct ic_instance *self, uint32_t x_bits,
                                   uint32_t y_bits, int32_t id, int32_t objindex,
                                   int32_t add_to_object);

/* ── the object hash and the global instance table ──────────────────────── */
typedef struct ic_hash_node {
    uint32_t               unused0;   /* +0x00: never read by these bodies  */
    struct ic_hash_node   *next;      /* +0x04                              */
    int32_t                key;       /* +0x08                              */
    struct ic_objectgm    *value;     /* +0x0c                              */
} ic_hash_node;

typedef struct {
    ic_hash_node *head;               /* +0x00; +0x04 is never touched      */
    uint32_t      unused4;
} ic_bucket;

typedef struct {
    ic_bucket *buckets;               /* +0x00 */
    uint32_t   mask;                  /* +0x04 */
} ic_hash;

typedef struct {
    uint8_t  *base;                   /* +0x00 slot array                   */
    int32_t   cap;                    /* +0x04                              */
    int32_t   count;                  /* +0x08                              */
    int32_t   next_free;              /* +0x0c                              */
} ic_instance_table;

typedef struct {
    const char *name;                 /* +0x00 */
    void       *getter;               /* +0x04 */
    void       *setter;               /* +0x08 */
    uint32_t    unused12;             /* +0x0c: this loop never reads it    */
} ic_builtin_entry;

/* Globals, each with the shape the instructions actually address.
 * 0x00542374 is a POINTER variable; the ctor's seven are plain objects whose
 * ADDRESS the GOT cell holds. */
extern ic_hash           *g_object_hash;      /* 0x00542374 */
extern ic_instance_table  g_instance_table;   /* 0x00536f0c */
extern uint64_t           g_create_counter;   /* 0x00536f20, 8 B  */
extern uint8_t            g_builtin_gate;     /* 0x0047f295, byte */
extern int32_t            g_builtin_numb;     /* 0x00753108       */
/* 0x0075310c is the TABLE ITSELF, 16-byte entries: the GOT cell holds that
 * address and `ldr r4,[r8,r3]` is the one dereference that gets there.  Only
 * the entries' name pointers live in the arena. */
extern ic_builtin_entry   g_builtin_table[500];
extern int32_t            g_base_ctor_arg1;   /* 0x00544b48       */
extern uint32_t           g_cinstance_vtable_head[4]; /* 0x003ebaf0; +8 is
                                              the vtable value the ctor stores */

/* ── callees: all stubs, identical on both arms ─────────────────────────── */
void CObjectGM_RemoveInstance(struct ic_objectgm *obj, struct ic_instance *inst);
void CObjectGM_AddInstance(struct ic_objectgm *obj, struct ic_instance *inst);
void CInstance_SetSpriteIndex(struct ic_instance *self, int32_t sprite);
void CollisionMarkDirty(struct ic_instance *self);
void YYObjectBase_ctor(struct ic_instance *self, int32_t arg1, int32_t arg2);
int  isGlobalBuiltinVar(const char *name);
void *JS_SetupBuiltinProperty(void *getter, void *setter);
void YYObjectBase_Add(struct ic_instance *self, const char *name, void *ps,
                      int32_t flag);
void *YYRealloc(void *p, int32_t bytes);
/* 0x000b65b0 memset@plt — the import the table-grow path branches to.  A
 * freestanding image has no libc, so the fixture records the call and fills. */
void *memset_plt(void *d, int c, unsigned int n);

/* ── field accessors (memcpy-based so no strict-aliasing assumption is made,
 *    and so a 32-bit build is the only build that can compile this) ─────── */
static inline int32_t ic_ld_i32(const void *p, unsigned off)
{
    int32_t v;
    __builtin_memcpy(&v, (const uint8_t *)p + off, 4);
    return v;
}
static inline void ic_st_i32(void *p, unsigned off, int32_t v)
{
    __builtin_memcpy((uint8_t *)p + off, &v, 4);
}
static inline uint32_t ic_ld_u32(const void *p, unsigned off)
{
    uint32_t v;
    __builtin_memcpy(&v, (const uint8_t *)p + off, 4);
    return v;
}
static inline void ic_st_u32(void *p, unsigned off, uint32_t v)
{
    __builtin_memcpy((uint8_t *)p + off, &v, 4);
}
static inline void ic_st_u64(void *p, unsigned off, uint64_t v)
{
    __builtin_memcpy((uint8_t *)p + off, &v, 8);
}
static inline void *ic_ld_ptr(const void *p, unsigned off)
{
    void *v;
    __builtin_memcpy(&v, (const uint8_t *)p + off, 4);
    return v;
}
static inline void ic_st_ptr(void *p, unsigned off, const void *v)
{
    uintptr_t w = (uintptr_t)v;
    __builtin_memcpy((uint8_t *)p + off, &w, 4);
}
static inline void ic_st_u8(void *p, unsigned off, uint32_t v)
{
    ((uint8_t *)p)[off] = (uint8_t)v;
}
static inline void ic_st_f32(void *p, unsigned off, uint32_t bits)
{
    __builtin_memcpy((uint8_t *)p + off, &bits, 4);
}
static inline void ic_st_float(void *p, unsigned off, float v)
{
    __builtin_memcpy((uint8_t *)p + off, &v, 4);
}

#endif /* INSTANCE_CTOR_H */
