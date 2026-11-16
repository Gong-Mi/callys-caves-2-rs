/*
 * instance_ctor.c — static C translation of
 * _ZN9CInstanceC2Effiib @0x001994dc in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 249 instructions + 8 literal-pool words, 1028 B, nine-register frame.
 *
 *   CInstance *CInstance::CInstance(float x, float y, int id, int objindex,
 *                                   bool addToObject)
 *
 * sizeof(CInstance) = 0x1b0: the only call site, CRoom::AddInstance 0x1ab194,
 * does `mov r0, #432` + operator new immediately before it, and passes
 * (r1 = x, r2 = y, r3 = ++room_maxid, [sp] = objindex, [sp+4] = 1).
 *
 * The body is a straight-line initialiser with three loops and one cold path:
 *   base class -> vtable -> three self-ring sentinels -> create-counter
 *   snapshot -> 107 field stores -> alarm[12] := 0 -> alarm[12] := -1 ->
 *   SetObjectIndex(objindex, addToObject) -> image/position/kinematics ->
 *   path/timeline/layer -> global instance-table slot -> builtin property
 *   registration -> +0x48 = 1, +0x10 = +0x14 = 0.
 *
 * Two facts decide how this file has to be read:
 *
 * 1. operator new runs with its fourth argument = 1, i.e. it memsets the block
 *    to zero before the constructor starts.  Every zero store below is an
 *    overwrite of zero.  The slots the body never touches (0x144, 0x148,
 *    0x178, 0x17c) are therefore 0 by construction, and the fixture proves it
 *    by staging 0xa5 there for the repeated-construction cases.
 * 2. +0x80 is cleared at 0x19964c BEFORE SetObjectIndex is called, so the
 *    RemoveInstance branch inside it cannot run on a fresh object - and cannot
 *    run on a REUSED block either, which is the observable difference between
 *    clearing the field and leaving it alone.
 *
 * Callees: YYObjectBase::YYObjectBase, isGlobalBuiltinVar,
 * JS_SetupBuiltinProperty, YYObjectBase::Add, YYRealloc and memset are
 * unrecovered and stubbed identically on both arms.  SetObjectIndex IS
 * recovered: arm A executes the original bytes at 0x19324c, arm B executes
 * src/set_object_index.c, so no part of the object-index path is stubbed.
 *
 * The object hash, the instance table and the builtin table are staged by the
 * fixture; instance_ctor.h names every global and every offset.
 */
#include "instance_ctor.h"

struct ic_instance *CInstance_ctor(struct ic_instance *self, uint32_t x_bits,
                                   uint32_t y_bits, int32_t id, int32_t objindex,
                                   int32_t add_to_object)
{
    int32_t base_arg1;
    uint64_t cc;
    int32_t *alarm;
    ic_instance_table *tp;
    int32_t count;
    int32_t cap;
    int32_t slot;
    void **base;
    int32_t left;

/*
 * ── 1. entry.  r11 = x, r9 = y, r10 = id, [sp+0x30] = objindex, [sp+0x34] =
 *    addToObject (reloaded as a byte at 0x1994f8 and spilled again at 0x19951c),
 *    r8 = GOT base, r4 = -1, r7 = 12, r2 = 0x00ffffff.  Nothing is validated.
 */

/* @0x1994dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1994e0 mov r11, r1 */
/* @0x1994e4 ldr r8, [pc, #0x3d4] */
/* @0x1994e8 sub sp, sp, #12 */
/* @0x1994ec ldr r1, [pc, #0x3d0] */
/* @0x1994f0 mov r10, r3 */
/* @0x1994f4 add r8, pc, r8 */
/* @0x1994f8 ldrb r3, [sp, #0x34] */
/* @0x1994fc mov r9, r2 */
/* @0x199500 mvn r2, #-16777216 */
/* @0x199504 ldr r1, [r8, r1] */
/* @0x199508 mov r6, r0 */
/* @0x19950c ldr r5, [pc, #0x3b4] */
/* @0x199510 mvn r4, #0 */
/* @0x199514 mov r7, #12 */
/* @0x199518 ldr r1, [r1] */
    base_arg1 = g_base_ctor_arg1;
/* @0x19951c str r3, [sp, #0x4] */

/*
 * ── 2. base class: YYObjectBase(this, *(int*)0x544b48, 0x00FFFFFF).  It sets
 *    +0x00 to its own vtable and +0x48 = 0 among other things; both are overwritten
 *    below.  The whole base write set is a fixture assumption, named in
 *    instance_ctor.h and in the receipt.
 */

/* @0x199520 bl 0x19188c */
    YYObjectBase_ctor(self, base_arg1, (int32_t)IC_BASE_ARG2);

/*
 * ── 3. vtable and the three self-referential list sentinels.  r4 = -1 (0x199510)
 *    lands in +0x188 first; the two ring pointers and the three "owner" words are
 *    the intrusive-list idiom: an empty chain points at itself, and the head slot
 *    is 0 until something links this object in.  The stores at 0x199538..0x199574
 *    are issued interleaved with the address arithmetic, so they are grouped here
 *    by what they mean, not by the order the adder wrote them.
 */

/* @0x199524 ldr r1, [pc, #0x3a0] */
    uint32_t vt = (uint32_t)(uintptr_t)((const uint8_t *)g_cinstance_vtable_head + IC_VTABLE_OFF);
/* @0x199528 mov lr, #0 */
/* @0x19952c add r2, r6, #396 */
/* @0x199530 ldr r0, [r8, r1] */
/* @0x199534 add r1, r6, #408 */
/* @0x199538 str r4, [r6, #0x188] */
    ic_st_i32(self, 0x188, -1);
/* @0x19953c add r4, r6, #420 */
/* @0x199540 str r2, [r6, #0x18c] */
    ic_st_ptr(self, 0x18c, (uint8_t *)self + 0x18c);
    ic_st_ptr(self, 0x190, (uint8_t *)self + 0x18c);
/* @0x199544 add r0, r0, #8 */
/* @0x199548 str r2, [r6, #0x190] */
/* @0x19954c mov r2, r6 */
/* @0x199550 str r0, [r6] */
    ic_st_u32(self, 0x00, vt);
/* @0x199554 mov r0, lr */
/* @0x199558 str r1, [r6, #0x198] */
    ic_st_ptr(self, 0x198, (uint8_t *)self + 0x198);
    ic_st_ptr(self, 0x19c, (uint8_t *)self + 0x198);
/* @0x19955c str r1, [r6, #0x19c] */
/* @0x199560 mov r1, #0 */
/* @0x199564 str lr, [r6, #0x194] */
    ic_st_ptr(self, 0x194, 0);
    ic_st_ptr(self, 0x1a0, 0);
    ic_st_ptr(self, 0x1ac, 0);
/* @0x199568 str lr, [r6, #0x1a0] */
/* @0x19956c str lr, [r6, #0x1ac] */
/* @0x199570 str r4, [r6, #0x1a4] */
    ic_st_ptr(self, 0x1a4, (uint8_t *)self + 0x1a4);
    ic_st_ptr(self, 0x1a8, (uint8_t *)self + 0x1a4);
/* @0x199574 str r4, [r6, #0x1a8] */

/*
 * ── 4. the create-counter snapshot (ldrd/strd, 8 bytes at +0x70) and the first
 *    clear batch.  Every store here writes 0 (r1 was zeroed at 0x199560, lr at
 *    0x199528); the only value with information in it is the 8-byte counter.
 */

/* @0x199578 ldr r4, [r8, r5] */
/* @0x19957c str r1, [r6, #0xb4] */
    ic_st_i32(self, 0xb4, 0);
/* @0x199580 str lr, [r6, #0x78] */
    ic_st_i32(self, 0x78, 0);
/* @0x199584 ldrd r4, r5, [r4] */
    cc = g_create_counter;
/* @0x199588 str r1, [r6, #0xb8] */
    ic_st_i32(self, 0xb8, 0);
/* @0x19958c strb lr, [r6, #0x6b] */
    ic_st_u8(self, 0x6b, 0);
/* @0x199590 str r1, [r6, #0x180] */
    ic_st_i32(self, 0x180, 0);
/* @0x199594 str r1, [r6, #0x184] */
    ic_st_i32(self, 0x184, 0);
/* @0x199598 strb lr, [r6, #0x6c] */
    ic_st_u8(self, 0x6c, 0);
/* @0x19959c str r1, [r6, #0x90] */
    ic_st_i32(self, 0x90, 0);
/* @0x1995a0 strb lr, [r6, #0x6a] */
    ic_st_u8(self, 0x6a, 0);
/* @0x1995a4 str r1, [r6, #0x94] */
    ic_st_i32(self, 0x94, 0);
/* @0x1995a8 str lr, [r6, #0xa8] */
    ic_st_i32(self, 0xa8, 0);
/* @0x1995ac str r1, [r6, #0x98] */
    ic_st_i32(self, 0x98, 0);
/* @0x1995b0 strd r4, r5, [r6, #112] */
    ic_st_u64(self, 0x70, cc);
/* @0x1995b4 str r1, [r6, #0x9c] */
    ic_st_i32(self, 0x9c, 0);
/* @0x1995b8 str r1, [r6, #0xa0] */
    ic_st_i32(self, 0xa0, 0);
/* @0x1995bc str r1, [r6, #0xa4] */
    ic_st_i32(self, 0xa4, 0);
/* @0x1995c0 str r1, [r6, #0xbc] */
    ic_st_i32(self, 0xbc, 0);
/* @0x1995c4 str r1, [r6, #0xc0] */
    ic_st_i32(self, 0xc0, 0);
/* @0x1995c8 str r1, [r6, #0xc4] */
    ic_st_i32(self, 0xc4, 0);
/* @0x1995cc str r1, [r6, #0xc8] */
    ic_st_i32(self, 0xc8, 0);
/* @0x1995d0 ldr r3, [sp, #0x4] */
/* @0x1995d4 str r1, [r6, #0xcc] */
    ic_st_i32(self, 0xcc, 0);
/* @0x1995d8 str r1, [r6, #0xd0] */
    ic_st_i32(self, 0xd0, 0);
/* @0x1995dc str r1, [r6, #0xe0] */
    ic_st_i32(self, 0xe0, 0);
/* @0x1995e0 str r1, [r6, #0xe4] */
    ic_st_i32(self, 0xe4, 0);
/* @0x1995e4 str r1, [r6, #0xd4] */
    ic_st_i32(self, 0xd4, 0);
/* @0x1995e8 str r1, [r6, #0xd8] */
    ic_st_i32(self, 0xd8, 0);
/* @0x1995ec str r1, [r6, #0xdc] */
    ic_st_i32(self, 0xdc, 0);

/*
 * ── 5. alarm[0..11], first pass: twelve zeros.  The adder counts r7 down from 12
 *    while the cursor r2 walks up from `this`, i.e. +0xf8 + 4*i; the second pass at
 *    0x1996d0 writes -1 over the same range.  GetTimer/SetTimer 0x193134/0x193148
 *    independently pin base, stride and the bound of 12.
 */

/* @0x1995f0 subs r7, r7, #1 */
    alarm = (int32_t *)(void *)((uint8_t *)self + IC_ALARM_BASE);
    for (int32_t i = 0; i < IC_ALARM_COUNT; i++)
/* @0x1995f4 str r0, [r2, #0xf8] */
        alarm[i] = 0;
/* @0x1995f8 add r2, r2, #4 */
/* @0x1995fc bne 0x1995f0 */

/*
 * ── 6. second clear batch, then the object-index call.  r7 has counted down to
 *    0 in the loop above, which is why every `str r7` here is a zero store; r4 is
 *    0 as well.  +0x80 is cleared at 0x19964c - that store is what keeps
 *    SetObjectIndex's RemoveInstance branch from running even when the block is a
 *    reused instance.
 */

/* @0x199600 mov r4, #0 */
/* @0x199604 mov r2, r3 */
/* @0x199608 ldr r1, [sp, #0x30] */
/* @0x19960c mov r0, r6 */
/* @0x199610 strb r7, [r6, #0x68] */
    ic_st_u8(self, 0x68, 0);
/* @0x199614 strb r7, [r6, #0x69] */
    ic_st_u8(self, 0x69, 0);
/* @0x199618 str r7, [r6, #0x160] */
    ic_st_i32(self, 0x160, 0);
/* @0x19961c str r7, [r6, #0x164] */
    ic_st_i32(self, 0x164, 0);
/* @0x199620 str r4, [r6, #0x12c] */
    ic_st_i32(self, 0x12c, 0);
/* @0x199624 str r7, [r6, #0x128] */
    ic_st_i32(self, 0x128, 0);
/* @0x199628 str r4, [r6, #0x130] */
    ic_st_i32(self, 0x130, 0);
/* @0x19962c str r7, [r6, #0x140] */
    ic_st_i32(self, 0x140, 0);
/* @0x199630 str r4, [r6, #0x134] */
    ic_st_i32(self, 0x134, 0);
/* @0x199634 str r7, [r6, #0x14c] */
    ic_st_i32(self, 0x14c, 0);
/* @0x199638 str r4, [r6, #0x138] */
    ic_st_i32(self, 0x138, 0);
/* @0x19963c strb r7, [r6, #0x15c] */
    ic_st_u8(self, 0x15c, 0);
/* @0x199640 str r4, [r6, #0x13c] */
    ic_st_i32(self, 0x13c, 0);
/* @0x199644 strb r7, [r6, #0x15d] */
    ic_st_u8(self, 0x15d, 0);
/* @0x199648 str r4, [r6, #0x150] */
    ic_st_i32(self, 0x150, 0);
/* @0x19964c str r7, [r6, #0x80] */
    ic_st_i32(self, 0x80, 0);
/* @0x199650 str r4, [r6, #0x154] */
    ic_st_i32(self, 0x154, 0);
/* @0x199654 str r7, [r6, #0x84] */
    ic_st_i32(self, 0x84, 0);
/* @0x199658 str r4, [r6, #0x158] */
    ic_st_i32(self, 0x158, 0);
/* @0x19965c str r7, [r6, #0x88] */
    ic_st_i32(self, 0x88, 0);

/*
 * ── 7. the one call that decides the instance's object.  It runs BEFORE the
 *    image/position block below, so a hit overwrites +0xac/+0x65/+0x66/+0x67/
 *    +0x180/+0x8c/+0x64 first and those defaults stay what the object says.
 */

/* @0x199660 bl 0x19324c */
    CInstance_SetObjectIndex(self, objindex, add_to_object);

/*
 * ── 8. image, position and motion defaults, then alarm pass 2.  r2 = 1.0f, r0 =
 *    270.0f (mov 0 + movt 0x4387), r1 = -1, r4 = 0.  x/y/id are written three
 *    times (position, start, previous) from r11/r9/r10; +0x78 is the id.
 */

/* @0x199664 mov r3, r6 */
/* @0x199668 mvn r1, #0 */
/* @0x19966c mov r2, #1065353216 */
/* @0x199670 mov r0, #0 */
/* @0x199674 str r2, [r6, #0x94] */
    ic_st_f32(self, 0x94, IC_F_ONE);
    ic_st_f32(self, 0x98, IC_F_ONE);
/* @0x199678 str r2, [r6, #0x98] */
/* @0x19967c movt r0, #0x4387 */
/* @0x199680 str r2, [r6, #0x9c] */
    ic_st_f32(self, 0x9c, IC_F_ONE);
    ic_st_f32(self, 0xa4, IC_F_ONE);
/* @0x199684 str r2, [r6, #0xa4] */
/* @0x199688 mvn r2, #-16777216 */
/* @0x19968c str r4, [r6, #0x90] */
    ic_st_i32(self, 0x90, 0);
/* @0x199690 str r4, [r6, #0xa0] */
    ic_st_i32(self, 0xa0, 0);
/* @0x199694 str r4, [r6, #0xcc] */
    ic_st_i32(self, 0xcc, 0);
/* @0x199698 str r4, [r6, #0xd0] */
    ic_st_i32(self, 0xd0, 0);
/* @0x19969c str r4, [r6, #0xe0] */
    ic_st_i32(self, 0xe0, 0);
/* @0x1996a0 str r4, [r6, #0xe4] */
    ic_st_i32(self, 0xe4, 0);
/* @0x1996a4 str r4, [r6, #0xd4] */
    ic_st_i32(self, 0xd4, 0);
/* @0x1996a8 str r4, [r6, #0xdc] */
    ic_st_i32(self, 0xdc, 0);
/* @0x1996ac str r11, [r6, #0xb4] */
    ic_st_u32(self, 0xb4, x_bits);
    ic_st_u32(self, 0xb8, y_bits);
/* @0x1996b0 str r9, [r6, #0xb8] */
/* @0x1996b4 str r10, [r6, #0x78] */
    ic_st_i32(self, 0x78, id);
/* @0x1996b8 str r11, [r6, #0xbc] */
    ic_st_u32(self, 0xbc, x_bits);
    ic_st_u32(self, 0xc0, y_bits);
/* @0x1996bc str r9, [r6, #0xc0] */
/* @0x1996c0 str r11, [r6, #0xc4] */
    ic_st_u32(self, 0xc4, x_bits);
    ic_st_u32(self, 0xc8, y_bits);
/* @0x1996c4 str r9, [r6, #0xc8] */
/* @0x1996c8 str r2, [r6, #0xa8] */
    ic_st_u32(self, 0xa8, IC_BASE_ARG2);
/* @0x1996cc str r0, [r6, #0xd8] */
    ic_st_u32(self, 0xd8, IC_F_270);
/* @0x1996d0 add r7, r7, #1 */
    for (int32_t i = 0; i < IC_ALARM_COUNT; i++)
/* @0x1996d4 str r1, [r3, #0xf8] */
        alarm[i] = -1;
/* @0x1996d8 cmp r7, #12 */
/* @0x1996dc add r3, r3, #4 */
/* @0x1996e0 mvn r2, #0 */
/* @0x1996e4 bne 0x1996d0 */

/*
 * ── 9. the third batch: path, timeline and layer terminal values.  -1 is r2
 *    (mvn r0/#0 outside the loop), 1.0f is r1, 0 is r4/r3, and 2 is written to
 *    +0x16c once - the only 2 in the whole function.
 */

/* @0x1996e8 ldr r0, [pc, #0x1e0] */
/* @0x1996ec mov r4, #0 */
/* @0x1996f0 mov r3, #0 */
/* @0x1996f4 mov r1, #1065353216 */
/* @0x1996f8 str r3, [r6, #0x12c] */
    ic_st_i32(self, 0x12c, 0);
/* @0x1996fc str r3, [r6, #0x130] */
    ic_st_i32(self, 0x130, 0);
/* @0x199700 str r3, [r6, #0x134] */
    ic_st_i32(self, 0x134, 0);
/* @0x199704 str r3, [r6, #0x13c] */
    ic_st_i32(self, 0x13c, 0);
/* @0x199708 str r3, [r6, #0x150] */
    ic_st_i32(self, 0x150, 0);
/* @0x19970c str r3, [r6, #0x154] */
    ic_st_i32(self, 0x154, 0);
/* @0x199710 mov r3, #2 */
/* @0x199714 str r2, [r6, #0x128] */
    ic_st_i32(self, 0x128, -1);
/* @0x199718 str r2, [r6, #0x14c] */
    ic_st_i32(self, 0x14c, -1);
/* @0x19971c str r2, [r6, #0x170] */
    ic_st_i32(self, 0x170, -1);
/* @0x199720 str r4, [r6, #0xf4] */
    ic_st_i32(self, 0xf4, 0);
/* @0x199724 str r4, [r6, #0xe8] */
    ic_st_i32(self, 0xe8, 0);
/* @0x199728 str r4, [r6, #0xf0] */
    ic_st_i32(self, 0xf0, 0);
/* @0x19972c str r4, [r6, #0xec] */
    ic_st_i32(self, 0xec, 0);
/* @0x199730 strb r4, [r6, #0x68] */
    ic_st_u8(self, 0x68, 0);
    ic_st_u8(self, 0x69, 0);
/* @0x199734 strb r4, [r6, #0x69] */
/* @0x199738 str r1, [r6, #0x138] */
    ic_st_f32(self, 0x138, IC_F_ONE);
/* @0x19973c str r1, [r6, #0x158] */
    ic_st_f32(self, 0x158, IC_F_ONE);
/* @0x199740 str r4, [r6, #0x140] */
    ic_st_i32(self, 0x140, 0);
/* @0x199744 str r4, [r6, #0x160] */
    ic_st_i32(self, 0x160, 0);
/* @0x199748 str r4, [r6, #0x164] */
    ic_st_i32(self, 0x164, 0);
/* @0x19974c str r4, [r6, #0x168] */
    ic_st_i32(self, 0x168, 0);
/* @0x199750 strb r4, [r6, #0x15e] */
    ic_st_u8(self, 0x15e, 0);
/* @0x199754 strb r4, [r6, #0x174] */
    ic_st_u8(self, 0x174, 0);
/* @0x199758 str r3, [r6, #0x16c] */
    ic_st_i32(self, 0x16c, 2);

/*
 * ── 10. the global instance table (0x00536f0c: base, cap, count, next_free).
 *    Normal path: count < cap, so walk from next_free, clamp to 0 when the index
 *    reaches cap (signed compare), take the first empty slot, write `this` there,
 *    remember the slot as the new next_free, count++, and the slot number goes to
 *    +0x44.  cap <= 0 short-circuits to slot = -1 but still counts the instance.
 *    The annotations are listed in address order first and the C follows, because
 *    the adder put the "try the next slot" block (0x199788) before the body it
 *    follows in the source.
 */

/* @0x19975c ldr r5, [r8, r0] */
/* @0x199760 ldr r7, [r5, #0x8] */
/* @0x199764 ldr r12, [r5, #0x4] */
/* @0x199768 cmp r7, r12 */
/* @0x19976c bge 0x19987c */
/* @0x199770 cmp r12, #0 */
/* @0x199774 ldr r3, [r5, #0xc] */
/* @0x199778 ble 0x1997c0 */
/* @0x19977c ldr r0, [r5] */
/* @0x199780 mov r1, r12 */
/* @0x199784 b 0x199794 */
/* @0x199788 subs r1, r1, #1 */
/* @0x19978c add r3, r3, #1 */
/* @0x199790 beq 0x1997c0 */
/* @0x199794 cmp r12, r3 */
/* @0x199798 lsl r2, r3, #2 */
/* @0x19979c movle r3, #0 */
/* @0x1997a0 movle r2, r3 */
/* @0x1997a4 add r4, r0, r2 */
/* @0x1997a8 ldr r2, [r0, r2] */
/* @0x1997ac cmp r2, #0 */
/* @0x1997b0 bne 0x199788 */
/* @0x1997b4 str r6, [r4] */
/* @0x1997b8 str r3, [r5, #0xc] */
/* @0x1997bc b 0x1997c4 */
/* @0x1997c0 mvn r3, #0 */
/* @0x1997c4 ldr r2, [pc, #0x108] */
/* @0x1997c8 add r7, r7, #1 */
/* @0x1997cc str r3, [r6, #0x44] */
/* @0x1997d0 str r7, [r5, #0x8] */
    tp = &g_instance_table;
    count = tp->count;
    cap = tp->cap;
    if (count >= cap)
        goto insert_grow;
insert_scan:
    slot = tp->next_free;
    if (cap <= 0)
        goto insert_no_slot;
    base = (void **)(void *)tp->base;
    left = cap;
    for (;;) {
        if (cap <= slot)
            slot = 0;
        if (base[slot] == 0) {
            base[slot] = self;
            tp->next_free = slot;
            goto insert_store;
        }
        left--;
        slot++;
        if (left == 0)
            goto insert_no_slot;
    }
insert_no_slot:
    slot = -1;
insert_store:
    count = count + 1;
    ic_st_i32(self, 0x44, slot);
    tp->count = count;
    goto insert_done;                 /* 0x1997d0 falls through to 0x1997d4 */

/*
 * ── 11. the grow path, which the binary lays out AFTER the epilogue (0x19987c..
 *    0x1998bc) and which only the `bge` at 0x19976c can enter.  newcap = cap*3/2
 *    rounded toward zero, done as (x + (x >>u 31)) >>a 1; YYRealloc, then memset
 *    zeroes the new tail only.  r4 is still 0 here (it is only turned into a slot
 *    address inside the scan), which is why memset's fill byte is 0.  After the
 *    grow the scan restarts at 0x199770, skipping the count>=cap test.
 */

/* @0x19987c add r12, r12, r12, lsl #1 */
/* @0x199880 ldr r0, [r5] */
/* @0x199884 add r12, r12, r12, lsr #31 */
/* @0x199888 asr r7, r12, #1 */
/* @0x19988c lsl r1, r7, #2 */
/* @0x199890 bl 0xcef64 */
/* @0x199894 ldr r3, [r5, #0x4] */
/* @0x199898 mov r1, r4 */
/* @0x19989c rsb r2, r3, r7 */
/* @0x1998a0 lsl r2, r2, #2 */
/* @0x1998a4 str r0, [r5] */
/* @0x1998a8 add r0, r0, r3, lsl #2 */
/* @0x1998ac bl 0xb65b0 */
/* @0x1998b0 str r7, [r5, #0x4] */
/* @0x1998b4 mov r12, r7 */
/* @0x1998b8 ldr r7, [r5, #0x8] */
/* @0x1998bc b 0x199770 */
insert_grow:
    {
        uint32_t x = (uint32_t)cap * 3u;
        int32_t newcap;
        void *nb;
        int32_t oldcap;

        x += x >> 31;
        newcap = (int32_t)x >> 1;
        nb = YYRealloc(tp->base, (int32_t)((uint32_t)newcap << 2));
        oldcap = tp->cap;
        memset_plt((uint8_t *)nb + oldcap * 4, 0,
                   (uint32_t)(newcap - oldcap) << 2);
        tp->base = (uint8_t *)nb;
        tp->cap = newcap;
        cap = newcap;
        count = tp->count;
        goto insert_scan;
    }

/*
 * ── 12. builtin property registration.  Gate byte 0x0047f295; count at
 *    0x00753108; the table POINTER lives at 0x0075310c (the GOT cell holds that
 *    address, so the code loads the variable and then dereferences it).  Each
 *    entry is 16 B: +0 name, +4 getter, +8 setter, +0xc never read.  Entries whose
 *    name isGlobalBuiltinVar() are skipped; the rest get
 *    JS_SetupBuiltinProperty(getter, setter) and YYObjectBase::Add(name, ps, 1).
 *    Count is re-read every iteration (0x19980c and 0x199850), so a callee could
 *    grow or shrink the loop; the table base is read once at 0x199800 and cached.
 */

/* @0x1997d4 ldr r3, [r8, r2] */
/* @0x1997d8 ldrb r3, [r3] */
/* @0x1997dc cmp r3, #0 */
/* @0x1997e0 beq 0x19985c */
/* @0x1997e4 ldr r3, [pc, #0xec] */
/* @0x1997e8 ldr r7, [r8, r3] */
/* @0x1997ec ldr r3, [r7] */
/* @0x1997f0 cmp r3, #0 */
/* @0x1997f4 ble 0x19985c */
/* @0x1997f8 ldr r3, [pc, #0xdc] */
/* @0x1997fc mov r5, #0 */
/* @0x199800 ldr r4, [r8, r3] */
/* @0x199804 add r4, r4, #8 */
/* @0x199808 b 0x19981c */
/* @0x19980c ldr r3, [r7] */
/* @0x199810 add r4, r4, #16 */
/* @0x199814 cmp r3, r5 */
/* @0x199818 ble 0x19985c */
/* @0x19981c ldr r0, [r4, #-0x8] */
/* @0x199820 add r5, r5, #1 */
/* @0x199824 bl 0x23f8f0 */
/* @0x199828 cmp r0, #0 */
/* @0x19982c bne 0x19980c */
/* @0x199830 ldmda r4, {r0, r1} */
/* @0x199834 add r4, r4, #16 */
/* @0x199838 bl 0x23ffac */
/* @0x19983c ldr r1, [r4, #-0x18] */
/* @0x199840 mov r3, #1 */
/* @0x199844 mov r2, r0 */
/* @0x199848 mov r0, r6 */
/* @0x19984c bl 0x19946c */
/* @0x199850 ldr r3, [r7] */
/* @0x199854 cmp r3, r5 */
/* @0x199858 bgt 0x19981c */
insert_done:
    if (g_builtin_gate != 0) {
        int32_t numb = g_builtin_numb;
        if (numb > 0) {
            const ic_builtin_entry *e = g_builtin_table;
            int32_t i = 0;

            for (;;) {
                const char *nm = e[i].name;

                i++;
                if (isGlobalBuiltinVar(nm) == 0) {
                    void *ps = JS_SetupBuiltinProperty(e[i - 1].getter,
                                                       e[i - 1].setter);
                    YYObjectBase_Add(self, e[i - 1].name, ps, 1);
                }
                if (g_builtin_numb <= i)
                    break;
            }
        }
    }

/*
 * ── 13. epilogue: +0x48 = 1 (the base constructor left it 0), the two creation
 *    stack-trace words cleared, r0 = this, one pop for the nine-register frame.
 */

/* @0x19985c mov r3, #0 */
/* @0x199860 mov r2, #1 */
/* @0x199864 mov r0, r6 */
/* @0x199868 str r2, [r6, #0x48] */
/* @0x19986c str r3, [r6, #0x10] */
/* @0x199870 str r3, [r6, #0x14] */
/* @0x199874 add sp, sp, #12 */
/* @0x199878 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    ic_st_i32(self, 0x48, 1);
    ic_st_i32(self, 0x10, 0);
    ic_st_i32(self, 0x14, 0);
    return self;
}

/*
 * ── 14. literal pool (8 words, data).  Each is the pc-relative displacement of a
 *    GOT cell; the cell's contents are the addresses named on the right.
 *      0x1998c0 0x0025875c -> 0x003f1c58  GOT base (r8)
 *      0x1998c4 0xffffc0c4 -> 0x003edd1c -> 0x00544b48  base ctor argument 1
 *      0x1998c8 0xffffdeb4 -> 0x003efb0c -> 0x00536f20  create counter (8 B)
 *      0x1998cc 0xffffea3c -> 0x003f0694 -> 0x003ebaf0  vtable head, +8 is the value
 *      0x1998d0 0xffffc014 -> 0x003edc6c -> 0x00536f0c  instance table
 *      0x1998d4 0xffffbf68 -> 0x003edbc0 -> 0x0047f295  builtin gate byte
 *      0x1998d8 0xffffbfe4 -> 0x003edc3c -> 0x00753108  builtin count
 *      0x1998dc 0xffffbfe8 -> 0x003edc40 -> 0x0075310c  builtin table pointer
 */

/* @0x1998c0 .word 0x0025875c */
/* @0x1998c4 .word 0xffffc0c4 */
/* @0x1998c8 .word 0xffffdeb4 */
/* @0x1998cc .word 0xffffea3c */
/* @0x1998d0 .word 0xffffc014 */
/* @0x1998d4 .word 0xffffbf68 */
/* @0x1998d8 .word 0xffffbfe4 */
/* @0x1998dc .word 0xffffbfe8 */
