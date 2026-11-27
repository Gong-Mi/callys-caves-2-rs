/* Recovered C source for the soft-float double->64-bit-integer converters.
 *
 * tier: bytecode_anchored.  Anchors in libyoyo_armv7.so (image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *   0x3194a0, 68 bytes: __fixdfdi, ARM-EABI alias __aeabi_d2lz (same entry).
 *   0x319550, 104 bytes: __fixunsdfdi, alias __aeabi_d2ulz (same entry).
 *   0x3195b0/0x3195b4 literal pool: high words 0x3df00000/0x41f00000 with
 *   low words supplied by "mov r2, #0" -> doubles 2^-32 and 2^32.
 *
 * gap: these are software-runtime C implementations whose callees
 * (__aeabi_dcmplt, __muldf3, __fixunsdfsi, __floatunsidf, __subdf3) remain
 * internal debt until separately recovered; the exception/bad-domain
 * behaviour of the original helpers is unverified.  The original source-file
 * spelling cannot be inferred from the exported C symbols alone, so the
 * header's tier note stands.  This source is a readable semantic model, not
 * a per-register transcription; the base-AAPCS core-register boundary
 * (r0:r1 for doubles and 64-bit returns) is what the softfp flags re-create.
 */

#include "conversions.h"

/* __fixdfdi @ 0x3194a0.
 * 0x3194b4 bl __aeabi_dcmplt(x, 0.0); the result is tested only for
 * non-zero (0x3194b8 cmp r0,#0 / beq).  Unordered NaN comparisons make
 * __aeabi_dcmplt return 0, so NaN follows the non-negative path and the
 * raw x is handed to the unsigned helper, exactly as the original does
 * (0x3194d8 mov r1, r4; tail b 0x319550).
 */
int64_t __fixdfdi(double x)
{
    union { double d; uint32_t w[2]; } bits; /* little-endian IEEE-754 double */
    union { uint64_t q; int64_t s; } ret;

    if (__aeabi_dcmplt(x, 0.0) != 0) {
        /* Negative magnitude path.  0x3194c4 add r1, r4, #-2147483648 is a
         * 32-bit-wrapping ADD of bit31 to the high word of x's bitmap (i.e.
         * a sign-bit flip); the low word r0 is kept.  Unsigned arithmetic
         * keeps this wrap well-defined without touching floating point.
         */
        bits.d = x;
        bits.w[1] += 0x80000000u;

        /* 0x3194cc/0x3194d0 rsbs r0,r0,#0 + rsc r1,r1,#0 negate the 64-bit
         * helper result modulo 2^64; subtraction from unsigned zero wraps
         * by definition, and the raw bits are returned as int64.
         */
        ret.q = 0ull - __fixunsdfdi(bits.d);
    } else {
        /* Non-negative (or NaN) path: 0x3194e0 tail-branches to
         * __fixunsdfdi with the unmodified x.
         */
        ret.q = __fixunsdfdi(x);
    }
    return ret.s;
}

/* __fixunsdfdi @ 0x319550 (kept noinline via the header so the signed
 * wrapper retains its real helper-call boundary, as at 0x3194c8).
 * The split-and-recover chain calls the original software helpers --
 * two __muldf3, two __fixunsdfsi, one __floatunsidf, one __subdf3 --
 * rather than any native double multiply/subtract or bit-exponent math.
 */
uint64_t __fixunsdfdi(double x)
{
    union { double d; uint32_t w[2]; } scale;
    union { uint64_t q; uint32_t w[2]; } split;
    uint32_t upper;
    uint32_t lower;
    double upper_scaled;

    /* 0x319554 mov r2,#0 + 0x319558 ldr r3,[pc,#0x50] (=0x3df00000):
     * the double 2^-32 from the literal pool.
     */
    scale.w[0] = 0u;
    scale.w[1] = 0x3df00000u;

    /* 0x319564/0x319568: __fixunsdfsi(__muldf3(x, 2^-32)) -> upper 32 bits. */
    upper = __fixunsdfsi(__muldf3(x, scale.d));

    /* 0x319570 __floatunsidf(upper), then 0x319574/0x31957c:
     * __muldf3(that, 2^32) using pool word 0x41f00000 with r2=0.
     */
    scale.w[0] = 0u;
    scale.w[1] = 0x41f00000u;
    upper_scaled = __muldf3(__floatunsidf(upper), scale.d);

    /* 0x319580..0x319598: __subdf3(x, upper_scaled), then the second
     * __fixunsdfsi -> lower 32 bits of the remainder.
     */
    lower = __fixunsdfsi(__subdf3(x, upper_scaled));

    /* 0x3195a0..0x3195a8: r1=upper, r0=lower (orr with r2=0); the 64-bit
     * result in core registers r0:r1 is upper:lower per little-endian.
     */
    split.w[0] = lower;
    split.w[1] = upper;
    return split.q;
}

/* ARM EABI aliases: the same function address, not forwarding wrappers.
 * Both were GLOBAL entry symbols in the original image, each counted once
 * toward the two-function anchor budget above.
 */
int64_t __aeabi_d2lz(double) __attribute__((alias("__fixdfdi")));
uint64_t __aeabi_d2ulz(double) __attribute__((alias("__fixunsdfdi")));
