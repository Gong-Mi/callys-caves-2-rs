/*
 * pop_local.c — static C translation of
 * _Z18DoPopLocalVariablejPhPKhP6VMExec @0x000e1f5c in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * 46 instructions, 184 bytes, no literal pool, one six-register frame, five
 * callees, and two ways to reach the shared epilogue.
 *
 * This is the pop form of "local variable = value":
 *
 *   r1 = the value-stack top.  It grows/shrinks as a pure pointer argument —
 *        the CPU sp is only used by the frame push/pop.
 *   r2 = the code stream; the operand word at [r2] is the variable id.
 *   r3 = VMExec; [r3+0x10] is the object the local belongs to.
 *   r0 = dead (no instruction reads r0 before 0xe1f88 overwrites it).
 *
 * Decode of the operand word (0xe1f6c..0xe1f7c), the same two flags DoPop uses
 * at 0xe68b4..0xe68c4:
 *   bit31 clear -> an instance id word is on the value stack: r7 = *r4, r4 += 4
 *   bit31 set   -> r7 = 0x80000000, the "self" sentinel, nothing popped
 *   bit29 clear -> one more word is consumed (r4 += 4) and becomes the source
 *                  RValue slot; bit29 set -> that word is absent
 *   low 28 bits -> (raw & 0x0fffffff) - 99328 - 672 = variable id - 100000
 *
 * Then, with self = exec->[0x10]:
 *   self == 0                      -> straight to the epilogue, no context
 *   self != 0                      -> PushContextStack(self)
 *     self->[0x24] == 0            -> PopContextStack, then the epilogue:
 *                                     nothing is stored (the table is not
 *                                     materialised yet)
 *     self->[0x24] != 0            -> dst = self->[4] + idx*16, or
 *                                     InternalGetYYVar(self, idx) when
 *                                     self->[4] == 0; SET_RValue(dst, slot,
 *                                     instance); PopContextStack
 *
 * The epilogue always runs, and always rewrites the consumed slot into the
 * tag-5 empty result {+0 = 0, +8 = 0, +0xc = 5}, leaving +4 alone, then
 * returns slot+16.  So the net stack effect of the whole body is
 *   16 + 4*[bit31 clear] + 4*[bit29 clear]
 * i.e. 16, 20 or 24 bytes — never 0, and never negative.
 *
 * The FREE_RValue__Pre gate is not "tag != 0": 0xe1fa4..0xe1fac does
 *   t = tag - 1; t &= 0x00ffffff; t &= ~3
 * so the callee runs exactly when tag-1 has no bits above 1, i.e. tag in 1..4.
 * tag 0x40000001 (bits 24..31 are masked off before the test) also qualifies;
 * tag 0x105 does not.
 *
 * Callees: none of the five is recovered, so all five are stubbed, identically
 * on both arms.  SET_RValue is the one that performs the actual copy, so this
 * arm proves the destination address, the source slot and the instance id that
 * are handed to it — not the store itself.
 */
#include "variable_ops.h"

static uint32_t rd32(const unsigned char *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void wr32(unsigned char *p, uint32_t w)
{
    p[0] = (unsigned char)(w & 0xffu);
    p[1] = (unsigned char)((w >> 8) & 0xffu);
    p[2] = (unsigned char)((w >> 16) & 0xffu);
    p[3] = (unsigned char)((w >> 24) & 0xffu);
}

unsigned char *DoPopLocalVariable(unsigned int arg, unsigned char *sp,
                                  const unsigned char *base, void *exec)
{
    unsigned char *r4;
    unsigned char *self;
    uint32_t r6, r7, tag;

    (void)arg;              /* r0 on entry is dead: 0xe1f88 overwrites it */

    /* @0xe1f5c push {r3, r4, r5, r6, r7, lr} */
    /* Six registers: the frame is 24 B and it is popped at 0xe1fd8 with pc in
     * lr's place, so there is no second exit to keep in sync. */
    /* @0xe1f60 mov r4, r1 */
    r4 = sp;
    /* @0xe1f64 ldr r6, [r2] */
    /* The operand comes from the code stream, never from the value stack. */
    r6 = rd32(base);
    /* @0xe1f68 ldr r5, [r3, #0x10] */
    self = *(unsigned char **)((unsigned char *)exec + EXEC_SELF);

    /* @0xe1f6c cmp r6, #0 */
    if ((int32_t)r6 >= 0) {
        /* @0xe1f70 ldrge r7, [r4], #4 */
        /* bit31 clear: a live instance id is on the stack, and it is consumed
         * here (pre-indexed load, post-indexed bump). */
        r7 = rd32(r4);
        r4 += 4;
    } else {
        /* @0xe1f74 movlt r7, #-2147483648 */
        /* bit31 set: nothing to pop, the store is explicitly "for self". */
        r7 = INSTANCE_SELF;
    }
    /* @0xe1f78 tst r6, #536870912 */
    /* @0xe1f7c addeq r4, r4, #4 */
    if ((r6 & CODE_ONE_WORD) == 0)
        /* bit29 clear: one more word on the stack, which is the source RValue
         * slot.  It is skipped, not read. */
        r4 += 4;

    /* @0xe1f80 cmp r5, #0 */
    /* @0xe1f84 beq 0xe1fa0 */
    if (self != 0) {
        /* @0xe1f88 mov r0, r5 */
        /* @0xe1f8c bl 0xd3968 */
        PushContextStack(self);

        /* @0xe1f90 ldr r3, [r5, #0x24] */
        /* @0xe1f94 cmp r3, #0 */
        /* @0xe1f98 bne 0xe1fdc */
        if (*(uint32_t *)(self + YYB_CTX_GATE) != 0) {
            unsigned char *tbl, *dst;

            /* @0xe1fdc ldr r3, [r5, #0x4] */
            tbl = *(unsigned char **)(self + YYB_VAR_TABLE);
            /* @0xe1fe0 bic r6, r6, #-268435456 */
            r6 &= CODE_VARID_MASK;
            /* @0xe1fe4 sub r6, r6, #99328 */
            r6 -= 99328;
            /* @0xe1fec sub r1, r6, #672 */
            r6 -= 672;
            /* 99328 + 672 = 100000: the variable-id base, third independent
             * sighting of the constant in this batch. */

            /* @0xe1fe8 cmp r3, #0 */
            /* @0xe1ff0 beq 0xe2008 */
            if (tbl != 0) {
                /* @0xe1ff4 add r0, r3, r1, lsl #4 */
                dst = tbl + (r6 << 4);
            } else {
                /* @0xe2008 mov r0, r5 */
                /* @0xe200c bl 0x196a70 */
                /* @0xe2010 b 0xe1ff8 */
                dst = (unsigned char *)InternalGetYYVar(self, (int32_t)r6);
            }
            /* @0xe1ff8 mov r2, r7 */
            /* @0xe1ffc mov r1, r4 */
            /* @0xe2000 bl 0xd0b24 */
            SET_RValue(dst, r4, (int32_t)r7);
            /* @0xe2004 b 0xe1f9c */
        }
        /* @0xe1f9c bl 0xd3a34 */
        /* Shared by both paths: the fall-through from the gate test and the
         * branch at 0xe2004 both land here. */
        PopContextStack();
    }

    /* ── epilogue: shared by every path (0xe1fa0) ──────────────────────── */
    /* @0xe1fa0 ldr r3, [r4, #0xc] */
    tag = rd32(r4 + RV_TAG);
    /* @0xe1fa4 sub r3, r3, #1 */
    tag -= 1;
    /* @0xe1fa8 bic r3, r3, #-16777216 */
    tag &= 0x00ffffffu;
    /* @0xe1fac bic r3, r3, #3 */
    tag &= ~3u;
    /* @0xe1fb0 cmp r3, #0 */
    /* @0xe1fb4 bne 0xe1fc0 */
    if (tag == 0) {
        /* @0xe1fb8 mov r0, r4 */
        /* @0xe1fbc bl 0xc0a7c */
        FREE_RValue__Pre(r4);
    }
    /* @0xe1fc0 mov r0, r4 */
    /* @0xe1fc4 mov r3, #0 */
    /* @0xe1fc8 mov r2, #5 */
    /* @0xe1fcc str r3, [r4, #0x8] */
    /* @0xe1fd0 str r2, [r4, #0xc] */
    /* @0xe1fd4 str r3, [r0], #16 */
    /* The consumed slot becomes the tag-5 empty result and r0 walks past it:
     * +8 and +0xc and +0 are written, +4 is left exactly as the caller put it. */
    wr32(r4 + 8, 0);
    wr32(r4 + 12, 5);
    wr32(r4, 0);
    /* @0xe1fd8 pop {r3, r4, r5, r6, r7, pc} */
    return r4 + 16;
}
