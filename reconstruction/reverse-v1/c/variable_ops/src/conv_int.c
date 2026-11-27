/*
 * conv_int.c — static C translation of
 * _Z19DoConvIntToVariablejPhPKhP6VMExec @0x000d773c in libyoyo ARMv7
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Nine instructions, 36 bytes, no literal pool, no frame, no call: a leaf.
 *
 *   r1 (the second parameter, a Ph = unsigned char*) is the value-stack top.
 *   The body reads the int32 sitting there, widens it to a double, and writes
 *   a 16-byte RValue starting 12 bytes BELOW that word:
 *
 *     0xd773c vldr        s15, [r1]        the int32, loaded into s15
 *     0xd7740 vcvt.f64.s32 d7, s15         d7 = (double)s15; d7 = {s14, s15}
 *     0xd7744 mov         r0, r1           r0 = the base for the post-index
 *     0xd7748 mov         r12, #0          the tag word
 *     0xd774c vmov        r2, r3, d7       r2 = low word, r3 = high word
 *     0xd7750 vstr        s14, [r1, #-12]  +0 = low word  (s14 IS d7's low half)
 *     0xd7754 str         r3, [r1, #-0x8]  +4 = high word
 *     0xd7758 str         r12, [r0], #-12  +0xc = 0, then r0 = r1 - 12
 *     0xd775c bx          lr               return r0 = r1 - 12
 *
 * The trap this body sets, and the reason it is worth a differential: the
 * literal text of the card says "s14 未在本函数内定义" and "写 12 字节对象",
 * but 0xd7740 writes d7, and d7's low half *is* s14 — so 0xd7750 stores the
 * double's low word, not a residual register.  Read as a 16-byte object at
 * r1-12 the layout is:
 *
 *     +0x0  low  word of the double   (0xd7750)
 *     +0x4  high word of the double   (0xd7754)
 *     +0x8  *** never written ***      (no instruction addresses r1-4)
 *     +0xc  tag word 0                (0xd7758)
 *
 * The +8 hole is real: the encoding is 12 bytes of stores at three of four
 * words, and the harness compares the untouched bytes around the object so a
 * translation that helpfully zeroes +8 is red.
 *
 * r2 is loaded (0xd774c) and then never used — a dead half of the vmov.
 * arg (r0 on entry) and base/exec (r2/r3 on entry) are never read.
 *
 * Tag 0 means this produces a "real"; DoPopLocalVariable writes tag 5 for the
 * empty result.  The two constants are checked against the bytes by the
 * harness (0xe1fc8 mov r2, #5 vs 0xd7748 mov r12, #0).
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

unsigned char *DoConvIntToVariable(unsigned int arg, unsigned char *sp,
                                   const unsigned char *base, void *exec)
{
    union { double d; uint32_t w[2]; } bits;
    unsigned char *p;
    uint32_t zero = 0;
    int32_t v;

    (void)arg;                     /* r0 on entry is overwritten at 0xd7744 */
    (void)base;                    /* r2 on entry is never read             */
    (void)exec;                    /* r3 on entry is never read             */

    /* @0xd773c vldr s15, [r1] */
    v = (int32_t)rd32(sp);

    /* @0xd7740 vcvt.f64.s32 d7, s15 */
    /* s32 -> f64 is exact for every int32, so the two words below are the
     * IEEE-754 encoding of v with no rounding to argue about. */
    bits.d = (double)v;

    /* @0xd7744 mov r0, r1 */
    p = sp;
    /* @0xd7748 mov r12, #0 */
    /* @0xd774c vmov r2, r3, d7 */
    /* r2 (the low word) is loaded and discarded by the original: only r3 is
     * ever stored.  The low word reaches memory through s14 at 0xd7750. */
    /* @0xd7750 vstr s14, [r1, #-12] */
    wr32(sp - 12, bits.w[0]);
    /* @0xd7754 str r3, [r1, #-0x8] */
    wr32(sp - 8, bits.w[1]);
    /* @0xd7758 str r12, [r0], #-12 */
    /* The store happens at r0 == r1 (the OLD stack top), and only then does
     * the writeback subtract 12 — so the zero word is the object's +0xc tag,
     * and the return value is r1-12. */
    wr32(p, zero);
    /* @0xd775c bx lr */
    return p - 12;
}
