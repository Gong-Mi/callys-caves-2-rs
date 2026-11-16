/*
 * set_object_index.c — static C translation of
 * _ZN9CInstance14SetObjectIndexEib @0x0019324c in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 70 instructions + one literal-pool word, 284 B, one four-register frame.
 *
 *   void CInstance::SetObjectIndex(int objindex, bool addToObject)
 *
 * What it does, in the order the bytes do it:
 *   1. +0x7c = objindex, unconditionally, BEFORE the old object is touched.
 *   2. if +0x80 (the old CObjectGM*) is non-zero: old->RemoveInstance(this),
 *      then +0x80 = 0 and the index is RE-READ from +0x7c (the callee is free to
 *      have written it; that is what makes the reload observable).
 *   3. if that index is -1 the stored field is rewritten to 0.  The lookup below
 *      still uses the ORIGINAL argument, so -1 and 0 are not the same request.
 *   4. g_ObjectHash: [0x542374] -> {buckets, mask}; bucket = objindex & mask,
 *      stride 8 B; node {+4 next, +8 key, +0xc value}.  First match wins.
 *   5. no match OR a matched node with value 0: +0x80 = 0 and return.  Nothing
 *      else is written - no bbox dirty bit, no CollisionMarkDirty.
 *   6. otherwise +0x80 = value; if addToObject, AddInstance(obj, this) first,
 *      then +0x80 is RE-READ (again: callee may have re-pointed it) and the six
 *      fields are copied from whatever object is now in +0x80.
 *   7. +0x64 = 1 and CollisionMarkDirty(this) as a tail branch, so the callee's
 *      return value is this function's.
 *
 * Field/flag mapping (see instance_ctor.h for the whole layout): mask_index
 * <- obj+0x10; visible <- flags bit1; solid <- flags bit0; persistent <- flags
 * bit2; depth <- (float)(int)obj+0x08; sprite <- SetSpriteIndex(obj+0x04).
 *
 * Callees: all four are unrecovered and stubbed identically on both arms;
 * see instance_ctor.h for the list and what each stub does.
 */
#include "instance_ctor.h"

void CInstance_SetObjectIndex(struct ic_instance *self, int32_t objindex,
                              int32_t add_to_object)
{
    struct ic_objectgm *old;
    struct ic_objectgm *obj;
    ic_hash *t;
    ic_bucket *buckets;
    uint32_t mask;
    ic_hash_node *n;
    int32_t idx;
    float depth;
    uint32_t flags;
/*
 * ── 1. entry: r5 = this, r4 = objindex, r6 = addToObject; +0x7c gets the raw
 *    argument before anything else.  The store is NOT conditional and NOT
 *    normalised here.
 */

/* @0x19324c push {r4, r5, r6, lr} */
/* @0x193250 mov r5, r0 */
/* @0x193254 ldr r0, [r0, #0x80] */
/* @0x193258 mov r4, r1 */
/* @0x19325c mov r6, r2 */
/* @0x193260 str r1, [r5, #0x7c] */
    old = (struct ic_objectgm *)ic_ld_ptr(self, 0x80);
    ic_st_i32(self, 0x7c, objindex);

/*
 * ── 2. unlink the old object.  The r3 seed at 0x193268 (moveq r3, r1) is the
 *    not-taken side of 0x19326c; the taken side re-reads +0x7c after the call, so
 *    the C keeps both and lets the branch pick.
 */

/* @0x193264 cmp r0, #0 */
/* @0x193268 moveq r3, r1 */
/* @0x19326c beq 0x193284 */
/* @0x193270 mov r1, r5 */
/* @0x193274 bl 0x19e0fc */
/* @0x193278 ldr r3, [r5, #0x7c] */
/* @0x19327c mov r2, #0 */
/* @0x193280 str r2, [r5, #0x80] */
    idx = objindex;
    if (old != 0) {
        CObjectGM_RemoveInstance(old, self);
        idx = ic_ld_i32(self, 0x7c);
        ic_st_ptr(self, 0x80, 0);
    }

/*
 * ── 3. -1 normalisation, storage only.  0x1932a4 still ands the ARGUMENT
 *    (r4), never this field.
 */

/* @0x193284 cmn r3, #1 */
/* @0x193288 moveq r3, #0 */
/* @0x19328c streq r3, [r5, #0x7c] */
    if (idx == -1)
        ic_st_i32(self, 0x7c, 0);

/*
 * ── 4. g_ObjectHash, three dereferences: the pool word is the pc-relative
 *    displacement of the GOT cell, the cell holds the address of the pointer
 *    variable (0x00542374), and the pointer variable holds the table.  The mask
 *    is read before the bucket base (they are the same struct).
 */

/* @0x193290 ldr r3, [pc, #0xcc] */
/* @0x193294 ldr r3, [pc, r3] */
/* @0x193298 ldr r3, [r3] */
/* @0x19329c ldr r1, [r3, #0x4] */
/* @0x1932a0 ldr r3, [r3] */
    t = g_object_hash;
    mask = t->mask;
    buckets = t->buckets;

/*
 * ── 5. bucket index = objindex & mask (the raw argument), bucket stride 8 B,
 *    chain walk.  Two entry points into the same comparison: the head is tested
 *    at 0x1932b4 and every subsequent node at 0x1932c4.
 */

/* @0x1932a4 and r1, r4, r1 */
/* @0x1932a8 ldr r3, [r3, r1, lsl #3] */
/* @0x1932ac cmp r3, #0 */
/* @0x1932b0 beq 0x1932dc */
/* @0x1932b4 ldr r2, [r3, #0x8] */
/* @0x1932b8 cmp r4, r2 */
/* @0x1932bc bne 0x1932d0 */
/* @0x1932c0 b 0x1932e8 */
/* @0x1932c4 ldr r12, [r3, #0x8] */
/* @0x1932c8 cmp r4, r12 */
/* @0x1932cc beq 0x1932e8 */
/* @0x1932d0 ldr r3, [r3, #0x4] */
/* @0x1932d4 cmp r3, #0 */
/* @0x1932d8 bne 0x1932c4 */
    n = buckets[objindex & mask].head;
    while (n != 0 && n->key != objindex)
        n = n->next;

/*
 * ── 6. no match: +0x80 = 0 and out.  Every other field keeps its old value —
 *    the bbox dirty bit is not set and CollisionMarkDirty is not called.
 */

/* @0x1932dc mov r3, #0 */
/* @0x1932e0 str r3, [r5, #0x80] */
/* @0x1932e4 pop {r4, r5, r6, pc} */
    if (n == 0) {
        ic_st_ptr(self, 0x80, 0);
        return;
    }

/*
 * ── 7. match: the node's value is stored even when it is 0, and a 0 value
 *    returns immediately (popeq) — the six fields are not copied.
 */

/* @0x1932e8 ldr r3, [r3, #0xc] */
/* @0x1932ec cmp r3, #0 */
/* @0x1932f0 str r3, [r5, #0x80] */
/* @0x1932f4 popeq {r4, r5, r6, pc} */
    obj = n->value;
    ic_st_ptr(self, 0x80, obj);
    if (obj == 0)
        return;

/*
 * ── 8. addToObject gate.  The five instructions below sit at 0x193350 AFTER the
 *    epilogue in the binary; they are written here because this is where the
 *    decision is taken (0x1932fc bne 0x193350) and they fall back into the copy
 *    block at 0x193300.  The +0x80 re-read at 0x19335c is the second place a
 *    callee can change what the copy sees.
 */

/* @0x1932f8 cmp r6, #0 */
/* @0x1932fc bne 0x193350 */
    if (add_to_object != 0) {
/* @0x193350 mov r0, r3 */
/* @0x193354 mov r1, r5 */
/* @0x193358 bl 0x19e02c */
        CObjectGM_AddInstance(obj, self);
/* @0x19335c ldr r3, [r5, #0x80] */
        obj = (struct ic_objectgm *)ic_ld_ptr(self, 0x80);
/* @0x193360 b 0x193300 */
    }

/*
 * ── 9. the six-field copy.  0x193300 vldr + 0x193304 vcvt.f32.s32 is one
 *    int-to-float conversion, so obj+0x08 is an int (a float field would need two
 *    instructions); 0x193338 hands obj+0x04 to SetSpriteIndex instead of storing
 *    +0x8c directly.
 */

/* @0x193300 vldr s14, [r3, #8] */
    depth = (float)*(const int32_t *)((const uint8_t *)obj + 0x08);
/* @0x193304 vcvt.f32.s32 s15, s14 */
/* @0x193308 ldr r12, [r3, #0x10] */
    flags = *(const uint32_t *)((const uint8_t *)obj + 0x00);
/* @0x19330c mov r0, r5 */
/* @0x193310 ldr r2, [r3] */
/* @0x193314 ldr r1, [r3, #0x4] */
/* @0x193318 ubfx r3, r2, #0x1, #0x1 */
/* @0x19331c str r12, [r5, #0xac] */
    ic_st_i32(self, 0xac, *(const int32_t *)((const uint8_t *)obj + 0x10));
    ic_st_u8(self, 0x65, (flags >> 1) & 1u);
    ic_st_u8(self, 0x66, flags & 1u);
    ic_st_u8(self, 0x67, (flags >> 2) & 1u);
/* @0x193320 strb r3, [r5, #0x65] */
/* @0x193324 and r12, r2, #1 */
/* @0x193328 ubfx r2, r2, #0x2, #0x1 */
/* @0x19332c strb r12, [r5, #0x66] */
/* @0x193330 strb r2, [r5, #0x67] */
/* @0x193334 vstr s15, [r5, #384] */
    ic_st_float(self, 0x180, depth);
/* @0x193338 bl 0x1931c0 */
    CInstance_SetSpriteIndex(
        self, *(const int32_t *)((const uint8_t *)obj + 0x04));

/*
 * ── 10. tail.  The frame is popped and the last instruction is a `b`, so
 *    CollisionMarkDirty returns straight to this function's caller.
 */

/* @0x19333c mov r3, #1 */
/* @0x193340 mov r0, r5 */
/* @0x193344 strb r3, [r5, #0x64] */
/* @0x193348 pop {r4, r5, r6, lr} */
/* @0x19334c b 0x1cc1d0 */
    ic_st_u8(self, 0x64, 1);
    CollisionMarkDirty(self);
}

/*
 * ── 11. literal pool (one word, not an instruction): the pc-relative
 *    displacement 0x0025a9a8 of the g_ObjectHash GOT cell 0x003edc44, which holds
 *    0x00542374.
 */

/* @0x193364 .word 0x0025a9a8 */
