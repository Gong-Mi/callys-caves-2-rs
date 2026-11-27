/*
 * do_variable_instance_exists.c — static C translation of
 * _Z24DoVariableInstanceExistsP9CInstancePKc @0x001178b8 in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 33 instructions, no literal pool (0x001178b8..0x0011793c, 132 B).  Every
 * instruction, in address order:
 *
 *   0x1178b8 push {r4, r5, lr}      20 B frame = 16 B RValue + 4 B pad
 *   0x1178bc mov  r5, r0            r5 = inst
 *   0x1178c0 sub  sp, sp, #20
 *   0x1178c4 mov  r0, r1            arg = name  (inst is NOT passed on)
 *   0x1178c8 mov  r4, r1            r4 = name
 *   0x1178cc bl   0x1f3a5c          Variable_BuiltIn_Find(name)
 *   0x1178d0 subs r1, r0, #0        sets the flags on the answer
 *   0x1178d4 blt  0x117918          id < 0 -> "not a builtin", try the slot table
 *
 *   -- the shared tail: zero the RValue, read it, answer 0/1 --------------
 *   0x1178d8 mov  r3, sp            out = &v
 *   0x1178dc mov  r0, r5            obj = inst
 *   0x1178e0 mov  r2, #-2147483648  arrindex = INT_MIN ("not an array read")
 *   0x1178e4 mov  r12, #0
 *   0x1178e8 str  r12, [sp]         v.w0 = 0
 *   0x1178ec str  r12, [sp, #0x4]   v.w1 = 0
 *   0x1178f0 str  r12, [sp, #0x8]   v.w2 = 0
 *   0x1178f4 str  r12, [sp, #0xc]   v.w3 = 0  <-- the tag word, cleared last
 *   0x1178f8 bl   0x1f3b8c         Variable_GetValue_Direct(inst, id, INT_MIN, &v)
 *   0x1178fc ldr  r0, [sp, #0xc]    tag
 *   0x117900 mvn  r3, #-16777216    r3 = 0x00ffffff
 *   0x117904 and  r0, r0, r3        tag & 0x00ffffff
 *   0x117908 subs r0, r0, r3        0 exactly when the masked tag IS 0x00ffffff
 *   0x11790c movne r0, #1
 *   0x117910 add  sp, sp, #20
 *   0x117914 pop  {r4, r5, pc}      (r0 survives: the answer)
 *
 *   -- the instance-name path --------------------------------------------
 *   0x117918 mov  r1, r4            name
 *   0x11791c mov  r0, r5            self
 *   0x117920 bl   0x0d21ec          Code_Variable_Find_Slot_From_Name(self,name)
 *   0x117924 cmp  r0, #0
 *   0x117928 movlt r0, #0           slot < 0 -> answer 0 ...
 *   0x11792c blt  0x117910          ... and return WITHOUT touching the RValue
 *   0x117930 add  r1, r0, #99328    slot + 99328
 *   0x117934 add  r1, r1, #672      ... + 672 = slot + 100000
 *   0x117938 b    0x1178d8          back into the shared tail
 *
 * Three things this body does NOT do, and the translation keeps true:
 *   * it never reads `inst` beyond forwarding it (0x1178bc/0x1178dc/0x11791c);
 *     no object field is touched here at all;
 *   * on the "neither builtin nor instance" exit (0x117928) it never zeroes,
 *     let alone writes, the RValue - the frame is torn down straight away;
 *   * the answer is not "does the slot exist" but "is the tag we read back
 *     different from 0x00ffffff".  A name that resolves to an UNSET value
 *     answers 0 (card conclusion 2).
 *
 * The third argument 0x80000000 is the library-wide "scalar, not an array
 * element" sentinel: GET_RValue compares against -2147483648 and only then
 * skips its "index on a non-array" error (0x0d13e4/0x0d13e8).
 *
 * Callee status: Variable_BuiltIn_Find (0x1f3a5c) is UNRECOVERED and is an
 * identical stub on both arms.  Code_Variable_Find_Slot_From_Name (0x0d21ec)
 * and Variable_GetValue_Direct (0x1f3b8c) are RECOVERED (c/variable_names,
 * c/variable_direct) and are linked for real on both arms, so this differential
 * also covers their dispatch.  Everything one level below them (GET_RValue
 * 0x0d13bc, InternalGetYYVar 0x196a70, the builtin getter fn, the two name
 * lookups 0x0d1f74 / 0x0d2054) is stubbed identically on both arms.
 */
#include "variable_misc.h"

int DoVariableInstanceExists(void *inst, const char *name)
{
    vm_rvalue v;        /* 16 B at sp+0 */
    int id;             /* r0 / r1 through the tail */
    int slot;

    /* 0x1178bc..0x1178cc: only the NAME goes to the lookup; inst is parked in
     * r5 and used again only at 0x1178dc and 0x11791c. */
    /* @0x1178b8 push {r4, r5, lr} */
    /* @0x1178bc mov r5, r0 */
    /* @0x1178c0 sub sp, sp, #20 */
    /* @0x1178c4 mov r0, r1 */
    /* @0x1178c8 mov r4, r1 */
    /* @0x1178cc bl 0x1f3a5c */
    /* @0x1178d0 subs r1, r0, #0 */
    id = Variable_BuiltIn_Find(name);

    /* 0x1178d4 is `blt`: strictly less than zero means "not a builtin name".
     * Note the order - the RValue is zeroed only AFTER this decision, so the
     * early exit below leaves the frame untouched. */
    /* @0x1178d4 blt 0x117918 */
    if (id < 0) {
        /* @0x117918 mov r1, r4 */
        /* @0x11791c mov r0, r5 */
        /* @0x117920 bl 0xd21ec */
        slot = Code_Variable_Find_Slot_From_Name(inst, name);

        /* @0x117924 cmp r0, #0 */
        /* @0x117928 movlt r0, #0 */
        /* @0x11792c blt 0x117910 */
        if (slot < 0)
            return 0;               /* nothing read, nothing written */

        /* 0x117930/0x117934: the library-wide variable-id base, added in two
         * steps exactly as the two `add`s do it. */
        /* @0x117930 add r1, r0, #99328 */
        /* @0x117934 add r1, r1, #672 */
        id = slot + 99328;
        id = id + 672;

        /* and back into the shared tail - the one `b` in this body */
        /* @0x117938 b 0x1178d8 */
    }

    /* The shared tail: four word stores, in ascending order, the tag word
     * (+0xc) last.  A callee that reads `out` therefore sees an all-zero
     * RValue - which is what the fixture's getter stub records. */
    /* @0x1178d8 mov r3, sp */
    /* @0x1178dc mov r0, r5 */
    /* @0x1178e0 mov r2, #-2147483648 */
    /* @0x1178e4 mov r12, #0 */
    /* @0x1178e8 str r12, [sp] */
    /* @0x1178ec str r12, [sp, #0x4] */
    /* @0x1178f0 str r12, [sp, #0x8] */
    /* @0x1178f4 str r12, [sp, #0xc] */
    v.w[0] = 0;
    v.w[1] = 0;
    v.w[2] = 0;
    v.w[3] = 0;

    /* @0x1178f8 bl 0x1f3b8c */
    Variable_GetValue_Direct(inst, id, VM_ARR_SCALAR, &v);

    /* 0x117900 mvn r3,#-16777216 is 0x00ffffff, and 0x117908 is `subs` so the
     * equal case leaves r0 at 0 rather than needing a separate mov. */
    /* @0x1178fc ldr r0, [sp, #0xc] */
    /* @0x117900 mvn r3, #-16777216 */
    /* @0x117904 and r0, r0, r3 */
    /* @0x117908 subs r0, r0, r3 */
    /* @0x11790c movne r0, #1 */
    /* @0x117910 add sp, sp, #20 */
    /* @0x117914 pop {r4, r5, pc} */
    return (v.w[3] & 0x00ffffffu) != VM_RV_UNSET;
}
