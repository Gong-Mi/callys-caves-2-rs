/*
 * CLayerManager_AddInstanceToLayer.c — static C translation of
 * _ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance
 * @0x001c5a38 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 179 instructions + 5 literal-pool words (0x1c5d04..0x1c5d14),
 * 0x1c5a38..0x1c5d18 = 736 B.  Put ONE instance on ONE named layer.
 *
 * Shape of the body:
 *   gates    layer == 0 || room == 0, then instance == 0, then
 *            instance+0x174 != 0 -- the last one is the same idempotence byte F2
 *            uses, so "already on a layer" exits here and changes nothing.
 *   lookup   0x1c5a74..0x1c5ac0: hash the instance id (instance+0x78) through
 *            CHashMapCalculateHash, clear bit 31, index table 3 with
 *            room+0x118 (mask) and room+0x120 (12 B buckets {key, value, hash}),
 *            and compare only the 31-bit HASH at +0x08 -- never the key.
 *   probe    0x1c5c1c..0x1c5c60: robin-hood style walk.  On a hash mismatch the
 *            occupant's probe distance (masked) is compared with ours; if the
 *            occupant is closer (0x1c5c28 blt) a new element is made here,
 *            otherwise the probe advances.  An empty bucket during the walk also
 *            means "make a new element".
 *            NOTE ON 0x1c5abc/0x1c5ac0: the early-out
 *            `tst r2,r4 ; bpl` can only fall through when bit 31 of (r2 & mask)
 *            is set, i.e. when the MASK itself has bit 31.  With any sane mask
 *            (this harness stages 15) the probe always advances, so the
 *            fall-through into 0x1c5ac4 never runs from here.  It is kept in the
 *            translation because the instruction is there, and the differential
 *            says so in its receipt rather than pretending to cover it.
 *   take     0x1c5c64..0x1c5c90: index == -1 is impossible, then the bucket
 *            value; a NULL value means "no element yet" (new), a non-NULL one
 *            splits into REUSE (elem+0x20 == 0, the element is in the table but
 *            carries no instance) and the ERROR path (elem+0x20 != 0, i.e. the
 *            instance already owns a live element).
 *   new      0x1c5ac4..0x1c5c18: the 36 B CLayerInstanceElement pool.  If the
 *            free count is 0 the pool is grown ONCE by `capacity` elements
 *            (Alloc(36, Room_Layers.h, 63, 1) per element, each pushed on the
 *            free list by head insertion through +0x18/+0x14), then the capacity
 *            is DOUBLED unconditionally (0x1c5b7c..0x1c5b84) -- including on the
 *            `capacity <= 0` path, which allocates nothing and only doubles.
 *            The element is popped from the free-list HEAD, its eight fields are
 *            seeded, the three instance fields are written
 *            (+0x170 layer id, +0x174 1, +0x180 (float)layer depth) and the
 *            body tail-jumps AddElementToLayer(room, layer, elem,
 *            instance+0x69).
 *   reerror   0x1c5c94..0x1c5cbc: the error path loads the host object from the
 *            POINTER VARIABLE 0x3eb70c (GOT 0x3ed71c), takes vtable+0xc and
 *            calls it with (host, "Attempting to add instance %d multiple times
 *            to a layer", instance+0x78), then returns without touching a
 *            single field (fail-soft, not assert).
 *   reuse     0x1c5cc0..0x1c5d00: only six field writes -- elem+0x20 = instance,
 *            elem+0x08 = 1, instance+0x170/+0x174/+0x180 -- and then, if the
 *            instance is deactivated, a tail jump to UpdateInstanceActivation.
 *            It does NOT call AddElementToLayer: no chain insert, no table 2, no
 *            table 3, and layer+0x58/+0x5c/+0x60 are untouched.
 *
 * The observable difference between the two entry paths is the point of the
 * function, so it is spelled out at both tail calls.
 *
 * Every exit is a tail jump (`b`), so the word this body returns is the tail
 * callee's r0; on the three early exits and on the reuse exit it is r0 residue
 * (0x1c5cc0 left layer->+0x00 in r0).  room_add.h has the reasoning.
 */
#include "room_add.h"

u32 CLayerManager_AddElementToLayer(void *room, void *layer, void *elem,
                                    int flag);
u32 CLayerManager_UpdateInstanceActivation(void *room, void *inst);

u32 CLayerManager_AddInstanceToLayer(void *room, void *layer, void *inst)
{
    u8 *const rm = (u8 *)room;        /* r9  */
    u8 *const ly = (u8 *)layer;       /* r10 */
    u8 *const in = (u8 *)inst;        /* r8  */
    u32 r0 = (u32)(uintptr_t)room;    /* r0, mirrored: see room_add.h */
    u32 buckets;                      /* r1  room+0x120, then a bucket address */
    u32 r1;                           /* r1  the deactivated byte in REUSE */
    u32 r2;                           /* r2  scratch (occupant hash, value, id) */
    u32 r3;                           /* r3  scratch (index, capacity, value) */
    u32 mask;                         /* r4  room+0x118, then the pool pointer */
    u32 probe;                        /* r5  probe distance / the zero fill */
    u32 twice;                        /* r6  2*idx, then the new uid */
    u32 dist;                         /* r7  layer id, then the occupant distance */
    u32 cap;                          /* r11 room+0x110, then the free count */
    u32 avail;                        /* r2  the free count while growing */
    u32 head;                         /* r3  the pool head while growing */
    u32 occ;                          /* r12 an occupant hash, then the element */
    u8 *pool;                         /* r4  the 36 B pool header */
    u8 *elem = 0;                     /* r12 the element being handed out */
    u32 s15;                          /* the VFP register, held as a raw word */
    u32 one = 1;                      /* r4  after 0x1c5bcc */
    /* ── three gates.  0x1c5a38/0x1c5a3c are a cmp/cmpne pair: the second
     * compare only runs when r1 (layer) is non-zero, so the beq at 0x1c5a54
     * means "layer == 0 OR room == 0". */
    /* @0x1c5a38 cmp r1, #0 */
    /* @0x1c5a3c cmpne r0, #0 */
    /* @0x1c5a40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0x1c5a44 mov r9, r0 */
    /* @0x1c5a48 sub sp, sp, #4 */
    /* @0x1c5a4c mov r10, r1 */
    /* @0x1c5a50 mov r8, r2 */
    /* @0x1c5a54 beq 0x1c5a6c */
    if (layer == 0 || room == 0) goto EXIT;
    /* @0x1c5a58 cmp r2, #0 */
    /* @0x1c5a5c beq 0x1c5a6c */
    if (inst == 0) goto EXIT;
    /* @0x1c5a60 ldrb r5, [r2, #0x174] */
    probe = rd8(in + INST_IN_LAYER);
    /* @0x1c5a64 cmp r5, #0 */
    /* @0x1c5a68 beq 0x1c5a74 */
    if (probe == 0) goto LOOKUP;    /* 0x1c5a68 is beq: 0 -> keep going */
    /* non-zero: already on a layer, nothing to do */
    goto EXIT;

    /* ── the ONE exit of the four non-tail paths.  r0 is whatever the path
     * left in it: the first argument on the three gates, layer+0x00 on the
     * reuse path (0x1c5cc0), the error callee on the error path. */
EXIT:
    /* @0x1c5a6c add sp, sp, #4 */
    /* @0x1c5a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return r0;

    /* ── table 3 lookup: hash, mask, first bucket ────────────────────────
     * 0x1c5a84 clears bit 31, 0x1c5a88 masks into the bucket index, and the
     * 12 B stride is built as (idx*2 + idx) * 4 -- 0x1c5a8c/0x1c5a90/0x1c5a94. */
LOOKUP:
    /* @0x1c5a74 ldr r0, [r2, #0x78] */
    r0 = rd32(in + INST_ID);
    /* @0x1c5a78 bl 0x1b6e44 */
    r0 = CHashMapCalculateHash((int)r0);
    /* @0x1c5a7c ldr r4, [r9, #0x118] */
    mask = rd32(rm + ROOM_T3_MASK);
    /* @0x1c5a80 ldr r1, [r9, #0x120] */
    buckets = rd32(rm + ROOM_T3_BUCKETS);
    /* @0x1c5a84 bic r0, r0, #-2147483648 */
    r0 &= 0x7fffffffu;
    /* @0x1c5a88 and r3, r0, r4 */
    r3 = r0 & mask;                     /* bucket index */
    /* @0x1c5a8c lsl r6, r3, #1 */
    twice = r3 << 1;
    /* @0x1c5a90 add r2, r6, r3 */
    /* @0x1c5a94 add r2, r1, r2, lsl #2 */
    /* (twice + idx) * 4 == 12 * idx, the bucket stride. */
    /* @0x1c5a98 ldr r2, [r2, #0x8] */
    r2 = rd32((u8 *)(uintptr_t)(buckets + (twice + r3) * 4) + T3_HASH);
    /* @0x1c5a9c cmp r2, #0 */
    /* @0x1c5aa0 beq 0x1c5ac4 */
    if (r2 == 0) goto NEW;              /* empty bucket */
    /* @0x1c5aa4 cmp r0, r2 */
    /* @0x1c5aa8 beq 0x1c5c6c */
    if (r0 == r2) goto TAKE;            /* hash match: use the slot */
    /* @0x1c5aac ldr r11, [r9, #0x110] */
    cap = rd32(rm + ROOM_T3_CAPACITY);
    /* @0x1c5ab0 and r2, r4, r2 */
    r2 = mask & r2;
    /* @0x1c5ab4 add r12, r11, r3 */
    occ = cap + r3;                     /* (r12) capacity + idx */
    /* @0x1c5ab8 rsb r2, r2, r12 */
    r2 = occ - r2;
    /* @0x1c5abc tst r2, r4 */
    /* @0x1c5ac0 bpl 0x1c5c2c */
    if ((r2 & mask) < 0x80000000u) goto PROBE;
    /* fall through: only reachable when mask has bit 31 (see the header). */

    /* ── a new element out of the 36 B pool ──────────────────────────────
     * 0x1c5ac4/0x1c5ac8: pool word 0x1c5d04 = 0x0022ad9c added to pc
     * 0x1c5ad0 -> GOT 0x3f086c -> .bss 0x542678, the pool header itself. */
NEW:
    /* @0x1c5ac4 ldr r4, [pc, #0x238] */
    /* @0x1c5ac8 ldr r4, [pc, r4] */
    pool = (u8 *)g_element_pool;
    /* @0x1c5acc ldr r11, [r4, #0x8] */
    cap = rd32(pool + POOL_AVAIL);      /* r11 = free count */
    /* @0x1c5ad0 cmp r11, #0 */
    /* @0x1c5ad4 bne 0x1c5b88 */
    if (cap != 0) goto POP;
    /* @0x1c5ad8 ldr r3, [r4, #0x10] */
    r3 = rd32(pool + POOL_CAPACITY);
    /* @0x1c5adc cmp r3, #0 */
    /* @0x1c5ae0 ble 0x1c5b80 */
    if ((s32)r3 <= 0) goto DOUBLE;      /* nothing to allocate: just double */
    /* @0x1c5ae4 ldr r7, [pc, #0x21c] */
    /* @0x1c5ae8 mov r5, r11 */
    probe = cap;                        /* r5 := 0 == the zero fill */
    /* @0x1c5aec mvn r6, #0 */
    twice = 0xffffffffu;                /* r6 := -1 == the unset fill */
    /* @0x1c5af0 add r7, pc, r7 */
    /* r7 := 0x34d69c, the Alloc site string. */
LOOP:
    /* @0x1c5af4 mov r3, #1 */
    r3 = 1;                             /* -> element+0x00 (type) */
    /* @0x1c5af8 mov r0, #36 */
    /* @0x1c5afc mov r1, r7 */
    /* @0x1c5b00 mov r2, #63 */
    /* @0x1c5b04 bl 0x27ce78 */
    r0 = MemoryManager_Alloc(
        ELEM_SIZE, "jni/../jni/yoyo/../../../Files/Room/Room_Layers.h",
        63, 1);
    /* @0x1c5b08 mov r3, #2 */
    r3 = 2;                             /* element type 2 == instance */
    /* @0x1c5b0c cmp r0, #0 */
    /* @0x1c5b10 beq 0x1c5b38 */
    if (r0 == 0) goto LINK;             /* the NULL branch: no field writes */
    elem = (u8 *)(uintptr_t)r0;
    /* @0x1c5b14 strb r5, [r0, #0x8] */
    wr8(elem + ELEM_FLAG, (u8)probe);   /* strb: the byte only */
    /* @0x1c5b18 str r5, [r0, #0xc] */
    wr32(elem + 0x0c, probe);
    /* @0x1c5b1c str r5, [r0, #0x10] */
    wr32(elem + 0x10, probe);
    /* @0x1c5b20 str r5, [r0, #0x14] */
    wr32(elem + ELEM_NEXT, probe);
    /* @0x1c5b24 str r5, [r0, #0x18] */
    wr32(elem + ELEM_PREV, probe);
    /* @0x1c5b28 str r6, [r0, #0x4] */
    wr32(elem + ELEM_UID, twice);       /* -1 */
    /* @0x1c5b2c str r6, [r0, #0x1c] */
    wr32(elem + ELEM_INST_ID, twice);   /* -1 */
    /* @0x1c5b30 str r5, [r0, #0x20] */
    wr32(elem + ELEM_INSTANCE, probe);  /* 0 */
    /* @0x1c5b34 str r3, [r0] */
    wr32(elem + ELEM_TYPE, r3);         /* 2 */

    /* ── push it on the free list (head insertion via +0x18/+0x14) ──────
     * Every store 0x1c5b48..0x1c5b6c is predicated on the ONE `cmp r3,#0`
     * at 0x1c5b44 (r3 = old head).  0x1c5b60 reloads r3 with the capacity
     * WITHOUT disturbing those flags -- hence the separate `empty` test. */
LINK:
    /* @0x1c5b38 ldr r3, [r4] */
    head = rd32(pool + POOL_HEAD);      /* r3 := the old head */
    /* @0x1c5b3c add r11, r11, #1 */
    cap += 1;
    /* @0x1c5b40 ldr r2, [r4, #0x8] */
    avail = rd32(pool + POOL_AVAIL);    /* r2 := the old free count... */
    /* @0x1c5b44 cmp r3, #0 */
    /* head == 0 ? */
    /* @0x1c5b48 streq r0, [r4, #0x4] */
    if (head == 0) wr32(pool + POOL_TAIL, r0);
    /* @0x1c5b4c strne r0, [r3, #0x18] */
    if (head != 0) wr32((u8 *)(uintptr_t)head + ELEM_PREV, r0);
    /* @0x1c5b50 add r2, r2, #1 */
    avail += 1;                         /* ...and then becomes count+1 */
    /* @0x1c5b54 streq r3, [r0, #0x18] */
    if (head == 0) wr32((u8 *)(uintptr_t)r0 + ELEM_PREV, head);
    /* @0x1c5b58 streq r3, [r0, #0x14] */
    if (head == 0) wr32((u8 *)(uintptr_t)r0 + ELEM_NEXT, head);
    /* @0x1c5b5c strne r3, [r0, #0x14] */
    if (head != 0) wr32((u8 *)(uintptr_t)r0 + ELEM_NEXT, head);
    /* @0x1c5b60 ldr r3, [r4, #0x10] */
    r3 = rd32(pool + POOL_CAPACITY);
    /* @0x1c5b64 streq r0, [r4] */
    if (head == 0) wr32(pool + POOL_HEAD, r0);
    /* @0x1c5b68 strne r0, [r4] */
    if (head != 0) wr32(pool + POOL_HEAD, r0);
    /* @0x1c5b6c strne r5, [r0, #0x18] */
    if (head != 0) wr32((u8 *)(uintptr_t)r0 + ELEM_PREV, probe);
    /* @0x1c5b70 cmp r11, r3 */
    /* cmp r11, r3 : the running count against the capacity */
    /* @0x1c5b74 str r2, [r4, #0x8] */
    wr32(pool + POOL_AVAIL, avail);
    /* @0x1c5b78 blt 0x1c5af4 */
    if ((s32)cap < (s32)r3) goto LOOP;
    /* @0x1c5b7c ldr r11, [r4, #0x8] */
    cap = rd32(pool + POOL_AVAIL);      /* reload before the fall-through */

    /* ── capacity doubling.  Reached by fall-through from 0x1c5b7c and by
     * the branch at 0x1c5ae0; both arrive with r3 = the OLD capacity. */
DOUBLE:
    /* @0x1c5b80 lsl r3, r3, #1 */
    r3 <<= 1;
    /* @0x1c5b84 str r3, [r4, #0x10] */
    wr32(pool + POOL_CAPACITY, r3);

    /* ── pop the free-list head and deliver it ───────────────────────────
     * The free list is doubly linked through +0x14(next)/+0x18(prev), with
     * prev == 0 at the head and next == 0 at the tail.  r4 is the pool. */
POP:
    /* @0x1c5b88 ldr r12, [r4] */
    occ = rd32(pool + POOL_HEAD);       /* r12 := the element */
    /* @0x1c5b8c sub r11, r11, #1 */
    cap -= 1;
    /* @0x1c5b90 ldr r5, [pc, #0x174] */
    /* @0x1c5b94 mov r0, r9 */
    r0 = (u32)(uintptr_t)rm;
    /* @0x1c5b98 ldr r7, [r10] */
    dist = rd32(ly + LAYER_ID);         /* r7 := the layer id */
    /* @0x1c5b9c mov r1, r10 */
    buckets = (u32)(uintptr_t)ly;       /* r1 := layer (the 3rd arg) */
    /* @0x1c5ba0 ldr r3, [r12, #0x18] */
    r3 = rd32((u8 *)(uintptr_t)occ + ELEM_PREV);   /* prev */
    /* @0x1c5ba4 ldr r5, [pc, r5] */
    /* r5 := the uid counter cell (0x3f0ae8 -> .bss 0x5425f0).  r5 stops
     * being the zero fill here -- r5 was only ever 0 on this path. */
    /* @0x1c5ba8 ldr r2, [r12, #0x14] */
    r2 = rd32((u8 *)(uintptr_t)occ + ELEM_NEXT);   /* next */
    /* @0x1c5bac cmp r3, #0 */
    /* @0x1c5bb0 str r11, [r4, #0x8] */
    wr32(pool + POOL_AVAIL, cap);
    /* @0x1c5bb4 strne r2, [r3, #0x14] */
    if (r3 != 0) wr32((u8 *)(uintptr_t)r3 + ELEM_NEXT, r2);
    /* @0x1c5bb8 ldrne r2, [r12, #0x14] */
    if (r3 != 0) r2 = rd32((u8 *)(uintptr_t)occ + ELEM_NEXT);
    /* @0x1c5bbc ldrne r3, [r12, #0x18] */
    if (r3 != 0) r3 = rd32((u8 *)(uintptr_t)occ + ELEM_PREV);
    /* @0x1c5bc0 streq r2, [r4] */
    if (r3 == 0) wr32(pool + POOL_HEAD, r2);      /* flags: 0x1c5bac */
    /* @0x1c5bc4 cmp r2, #0 */
    /* @0x1c5bc8 streq r3, [r4, #0x4] */
    if (r2 == 0) wr32(pool + POOL_TAIL, r3);      /* flags: 0x1c5bc4 */
    /* @0x1c5bcc mov r4, #1 */
    one = 1;                            /* r4 := 1, no longer the pool */
    /* @0x1c5bd0 strne r3, [r2, #0x18] */
    if (r2 != 0) wr32((u8 *)(uintptr_t)r2 + ELEM_PREV, r3);
    /* @0x1c5bd4 ldr r3, [r5] */
    r3 = rd32(&g_element_uid);          /* the OLD uid */
    /* @0x1c5bd8 ldr r2, [r8, #0x78] */
    r2 = rd32(in + INST_ID);
    /* @0x1c5bdc str r8, [r12, #0x20] */
    wr32((u8 *)(uintptr_t)occ + ELEM_INSTANCE, (u32)(uintptr_t)in);
    /* @0x1c5be0 add r6, r3, r4 */
    twice = r3 + one;                   /* uid + 1 */
    /* @0x1c5be4 str r3, [r12, #0x4] */
    wr32((u8 *)(uintptr_t)occ + ELEM_UID, r3);
    /* @0x1c5be8 str r2, [r12, #0x1c] */
    wr32((u8 *)(uintptr_t)occ + ELEM_INST_ID, r2);
    /* @0x1c5bec mov r2, r12 */
    r2 = occ;                           /* r2 := the element (r12) */
    elem = (u8 *)(uintptr_t)occ;        /* the tail call takes r12 */
    /* @0x1c5bf0 str r7, [r8, #0x170] */
    wr32(in + INST_LAYER_ID, dist);
    /* @0x1c5bf4 vldr s15, [r10, #4] */
    s15 = rd32(ly + LAYER_DEPTH);       /* the layer depth, as an int */
    /* @0x1c5bf8 vcvt.f32.s32 s15, s15 */
    s15 = f32bits((float)(s32)s15);     /* vcvt.f32.s32 */
    /* @0x1c5bfc strb r4, [r8, #0x174] */
    wr8(in + INST_IN_LAYER, (u8)one);
    /* @0x1c5c00 ldrb r3, [r8, #0x69] */
    r3 = rd8(in + INST_DEACTIVATED);    /* the 4th argument of the tail call */
    /* @0x1c5c04 str r6, [r5] */
    wr32(&g_element_uid, twice);        /* publish uid + 1 */
    /* @0x1c5c08 vstr s15, [r8, #384] */
    wr32(in + INST_DEPTH, s15);         /* the converted layer depth */
    /* @0x1c5c0c strb r4, [r12, #0x8] */
    wr8((u8 *)(uintptr_t)occ + ELEM_FLAG, (u8)one);
    /* @0x1c5c10 add sp, sp, #4 */
    /* @0x1c5c14 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0x1c5c18 b 0x1c451c */
    /* TAIL CALL.  The 4th argument is instance+0x69: AddElementToLayer
     * head-inserts when it is 0 and tail-inserts when it is 1, which is
     * why the argument is read here and not inside the callee. */
    return CLayerManager_AddElementToLayer(room, layer, elem, (int)r3);

    /* ── probe walk.  These two blocks are laid out in ADDRESS order, so the
     * fall-through at 0x1c5c28 into 0x1c5c2c becomes an explicit `goto PROBE`
     * and 0x1c5c5c jumps back into the block above. */
CHECK:
    /* @0x1c5c1c cmp r0, r12 */
    /* @0x1c5c20 beq 0x1c5c64 */
    if (r0 == occ) goto TAKE_AT;        /* same 31-bit hash */
    /* @0x1c5c24 cmp r7, r5 */
    /* @0x1c5c28 blt 0x1c5ac4 */
    if ((s32)dist < (s32)probe) goto NEW;   /* occupant is closer: insert here */
    goto PROBE;
PROBE:
    /* @0x1c5c2c add r3, r3, #1 */
    r3 += 1;
    /* @0x1c5c30 add r5, r5, #1 */
    probe += 1;
    /* @0x1c5c34 and r3, r4, r3 */
    r3 &= mask;                         /* modulo the table */
    /* @0x1c5c38 add r7, r11, r3 */
    dist = cap + r3;                    /* (r7) capacity + idx */
    /* @0x1c5c3c lsl r6, r3, #1 */
    twice = r3 << 1;
    /* @0x1c5c40 add r2, r6, r3 */
    /* @0x1c5c44 add r2, r1, r2, lsl #2 */
    /* @0x1c5c48 ldr r12, [r2, #0x8] */
    occ = rd32((u8 *)(uintptr_t)(buckets + (twice + r3) * 4) + T3_HASH);
    /* @0x1c5c4c and r2, r4, r12 */
    r2 = mask & occ;
    /* @0x1c5c50 cmp r12, #0 */
    /* @0x1c5c54 rsb r7, r2, r7 */
    dist -= r2;                         /* rsb r7, r2, r7 */
    /* @0x1c5c58 and r7, r7, r4 */
    dist &= mask;
    /* @0x1c5c5c bne 0x1c5c1c */
    /* @0x1c5c60 b 0x1c5ac4 */
    if (occ != 0) goto CHECK;
    goto NEW;                           /* walked into an empty bucket */

    /* ── the hash matched: is there an element behind it? ────────────────
     * 0x1c5c64 tests idx == -1 (cannot happen), 0x1c5c74 tests the bucket
     * address against -4 (cannot happen either): both are dead guards the
     * translation keeps because the instructions are there. */
TAKE_AT:
    /* @0x1c5c64 cmn r3, #1 */
    /* @0x1c5c68 beq 0x1c5ac4 */
    if (r3 == 0xffffffffu) goto NEW;
TAKE:
    /* @0x1c5c6c add r3, r6, r3 */
    r3 = twice + r3;                    /* 3 * idx */
    /* @0x1c5c70 add r1, r1, r3, lsl #2 */
    buckets = buckets + r3 * 4;         /* the bucket address */
    /* @0x1c5c74 cmn r1, #4 */
    /* @0x1c5c78 beq 0x1c5ac4 */
    if (buckets == 0xfffffffcu) goto NEW;
    /* @0x1c5c7c ldr r3, [r1, #0x4] */
    r3 = rd32((u8 *)(uintptr_t)buckets + T3_VALUE);
    /* @0x1c5c80 cmp r3, #0 */
    /* @0x1c5c84 beq 0x1c5ac4 */
    if (r3 == 0) goto NEW;              /* hash hit, no element */
    /* @0x1c5c88 ldr r2, [r3, #0x20] */
    r2 = rd32((u8 *)(uintptr_t)r3 + ELEM_INSTANCE);
    /* @0x1c5c8c cmp r2, #0 */
    /* @0x1c5c90 beq 0x1c5cc0 */
    if (r2 == 0) goto REUSE;            /* element is in the table, unowned */

    /* ── ERROR: this instance already owns a live element ────────────────
     * 0x1c5c9c is a real indirection: pc 0x1c5ca4 + pool word 0x00227a78 =
     * GOT 0x3ed71c, which holds 0x3eb70c -- a pointer VARIABLE, so *0x3eb70c
     * is the host object.  vtable+0xc is
     * called with (host, "Attempting to add instance %d multiple times to a
     * layer", id).  Nothing
     * is written afterwards -- fail-soft, the instance keeps its element. */
    /* @0x1c5c94 ldr r3, [pc, #0x74] */
    /* @0x1c5c98 ldr r1, [pc, #0x74] */
    /* @0x1c5c9c ldr r3, [pc, r3] */
    /* @0x1c5ca0 ldr r2, [r8, #0x78] */
    r2 = rd32(in + INST_ID);
    /* @0x1c5ca4 add r1, pc, r1 */
    /* r1 := 0x350864, the message string (see the pool words below) */
    /* @0x1c5ca8 ldr r0, [r3] */
    r0 = rd32(&g_error_host_cell);      /* the host object */
    /* @0x1c5cac ldr r3, [r0] */
    /* @0x1c5cb0 ldr r3, [r3, #0xc] */
    /* @0x1c5cb4 blx r3 */
    r0 = ((u32 (*)(void *, const char *, int))
          (*(void ***)(uintptr_t)r0)[3])(
        (void *)(uintptr_t)r0,
        "Attempting to add instance %d multiple times to a layer",
        (int)r2);
    /* @0x1c5cb8 add sp, sp, #4 */
    /* @0x1c5cbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    return r0;                          /* the callee r0, nothing written */

    /* ── REUSE: the element exists but carries no instance ───────────────
     * Six writes and NO AddElementToLayer: no chain insert, no table 2, no
     * table 3, no layer counter.  r3 still holds the element from
     * 0x1c5c7c, r0 takes layer+0x00 and is what the plain exit returns. */
REUSE:
    /* @0x1c5cc0 ldr r0, [r10] */
    r0 = rd32(ly + LAYER_ID);
    /* @0x1c5cc4 mov r2, #1 */
    r2 = 1;
    /* @0x1c5cc8 str r8, [r3, #0x20] */
    wr32((u8 *)(uintptr_t)r3 + ELEM_INSTANCE, (u32)(uintptr_t)in);
    /* @0x1c5ccc ldrb r1, [r8, #0x69] */
    r1 = rd8(in + INST_DEACTIVATED);
    /* @0x1c5cd0 str r0, [r8, #0x170] */
    wr32(in + INST_LAYER_ID, r0);
    /* @0x1c5cd4 vldr s15, [r10, #4] */
    s15 = rd32(ly + LAYER_DEPTH);
    /* @0x1c5cd8 vcvt.f32.s32 s15, s15 */
    s15 = f32bits((float)(s32)s15);
    /* @0x1c5cdc cmp r1, #0 */
    /* @0x1c5ce0 strb r2, [r8, #0x174] */
    wr8(in + INST_IN_LAYER, 1);
    /* @0x1c5ce4 vstr s15, [r8, #384] */
    wr32(in + INST_DEPTH, s15);
    /* @0x1c5ce8 strb r2, [r3, #0x8] */
    wr8((u8 *)(uintptr_t)r3 + ELEM_FLAG, 1);   /* elem+0x08, via r3 */
    /* @0x1c5cec beq 0x1c5a6c */
    if (r1 == 0) goto EXIT;             /* not deactivated: plain return */
    /* @0x1c5cf0 mov r0, r9 */
    /* @0x1c5cf4 mov r1, r8 */
    /* @0x1c5cf8 add sp, sp, #4 */
    /* @0x1c5cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0x1c5d00 b 0x1b8a28 */
    /* the deactivated-instance exit: refresh the activation tables. */
    return CLayerManager_UpdateInstanceActivation(room, inst);
}

    /* ── literal pool (5 words) ─────────────────────────────────────────
     * 0x1c5d04 = 0x0022ad9c  pc 0x1c5acc -> GOT 0x3f086c -> 0x542678 pool
     * 0x1c5d08 = 0x00187ba4  pc 0x1c5af8 -> 0x34d69c Room_Layers.h
     * 0x1c5d0c = 0x0022af3c  pc 0x1c5bac -> GOT 0x3f0ae8 -> 0x5425f0 uid
     * 0x1c5d10 = 0x00227a78  pc 0x1c5ca4 -> GOT 0x3ed71c -> 0x3eb70c host*
     * 0x1c5d14 = 0x0018abb8  pc 0x1c5cac -> 0x350864 the error string
     * llvm-objdump decodes all five as instructions; the census gate
     * documents them as words. */
    /* @0x1c5d04 .word 0x0022ad9c */
    /* @0x1c5d08 .word 0x00187ba4 */
    /* @0x1c5d0c .word 0x0022af3c */
    /* @0x1c5d10 .word 0x00227a78 */
    /* @0x1c5d14 .word 0x0018abb8 */
