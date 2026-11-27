/* Recovered C source for the unsigned32 software conversion leaf.
 *
 * tier: bytecode_anchored.  Anchor in libyoyo_armv7.so (image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *   0x31b0d0..0x31b124, 84 bytes, 21 ARM words, no literal pool:
 *   __fixunsdfsi, exported base-AAPCS soft-float leaf with the real
 *   same-address same-section GLOBAL alias __aeabi_d2uiz.
 *   body SHA256 ea88ee603a88b5fa2df3d09c7f876e7912d00bac3e65084b1c8cb6201f579b69.
 *
 * The original leaf calls nothing: no literal pool, no other runtime
 * helper.  This model reproduces that closure -- it uses no float->int
 * cast and no native FP comparison or arithmetic; every domain decision is
 * made on the raw double bitmap with wrapping uint32 arithmetic, one step
 * per original instruction, so the failure domains (negative, |x|<1,
 * +inf, +NaN, overflow, exact shift amounts) stay separately visible
 * instead of being collapsed into one generic saturating cast.
 *
 * gap: the original source-file spelling is not inferable from the C ABI
 * alone, and full-domain behavioural equivalence is not certified here --
 * the original was never executed on target.  This is a readable,
 * instruction-anchored semantic model, not a per-register transcription
 * and not proof of codegen identity.
 */

#include "conversions.h"

uint32_t __fixunsdfsi(double x)
{
    union { double d; uint32_t w[2]; } bits; /* little-endian IEEE-754 words */
    uint32_t low, high, shifted, summed, asr21, neg_shift, significand, amount;

    /* Double arrives in r0:r1 (base AAPCS): w[0]=r0=low, w[1]=r1=high.
     * Store/load through the union keeps the bitmap in place; no FP op.
     */
    bits.d = x;
    low  = bits.w[0];
    high = bits.w[1];

    /* 0x31b0d0 lsls r2, r1, #1 -- the LSL carry-out is the old bit31,
     * i.e. the sign of x.  0x31b0d4 bhs 0x31b104: carry set -> mov r0,#0.
     * Every negative bitmap yields 0, including -NaN and -inf, before
     * any other domain test runs.
     */
    shifted = high << 1;              /* uint32 wrap == ARM LSL */
    if (high & 0x80000000u)
        return 0u;

    /* 0x31b0d8 adds r2, r2, #2097152 (0x00200000).  shifted holds
     * exp<<21 | mantissa_high<<1, so the +0x00200000 bumps exp by one;
     * the 32-bit ADD carry fires exactly when the biased exponent field
     * is all ones (exp+1 == 0x800, i.e. +inf or +NaN at this point).
     */
    summed = shifted + 0x00200000u;   /* uint32 wrap == ARM ADDS */
    if (summed < shifted) {
        /* 0x31b0dc bhs 0x31b10c */
        /* 0x31b10c orrs r0, r0, r1, lsl #12: low | (high<<12) keeps every
         * mantissa bit (for exp==0x7FF, high<<12 shifts the exponent field
         * out of the 32-bit result, leaving only the top mantissa bits);
         * non-zero means a mantissa survives -> +NaN -> mov r0,#0.
         */
        if ((low | (high << 12)) != 0u)
            return 0u;                /* 0x31b11c: +NaN -> 0 */
        return 0xFFFFFFFFu;           /* 0x31b114 mvn r0,#0: exact +inf -> ~0 */
    }

    /* 0x31b0e0 bpl 0x31b104: after ADDS the N flag is bit31 of summed,
     * i.e. (exp+1) >= 0x400.  N clear means exp <= 1022 (including
     * subnormals and zero), |x| < 1, which truncates to 0.
     */
    if (summed < 0x80000000u)
        return 0u;

    /* 0x31b0e4 mvn r3, #992 (r3 = ~0x3E0 = 0xFFFFFC1F == -993) and
     * 0x31b0e8 subs r2, r3, r2, asr #21.  summed has bit31 set here, so
     * the ARM ASR #21 sign-extends: the value is (exp+1)-2048.  Adding
     * -993-(that) yields 1054-exp == (0x3FF+0x1F)-exp, the complement of
     * the usual compiler-rt shift amount.
     */
    asr21 = (summed >> 21) | 0xFFFFF800u; /* bit31=1: replicate sign over top 21 bits */
    neg_shift = 0xFFFFFC1Fu - asr21;      /* uint32 wrap == ARM SUBS */

    /* 0x31b0ec bmi 0x31b114: neg_shift negative (exp > 1054, |x| >= 2^32)
     * -> mvn r0,#0 -> 0xFFFFFFFF.  This is the overflow saturation
     * domain and it is deliberately distinct from the +inf exit above
     * only in path, and from NaN (0) in value.
     */
    if (neg_shift & 0x80000000u)
        return 0xFFFFFFFFu;

    /* 0x31b0f0 lsl r3, r1, #11; 0x31b0f4 orr r3, r3, #-2147483648;
     * 0x31b0f8 orr r3, r3, r0, lsr #21: build the top 32 bits of the
     * 53-bit significand, [1][mant_hi(20)][mant_lo(11)].  (high<<11)
     * wraps the exponent bits out of place exactly as ARM LSL does;
     * the forced bit31 swallows the stray (exp&1)<<31, so no masking
     * of the shifted exponent is needed.
     */
    significand = (high << 11) | 0x80000000u | (low >> 21);

    /* 0x31b0fc lsr r0, r3, r2 -- ARM register-shift semantics, stated
     * without leaning on C's out-of-range-shift UB: the shift amount is
     * the low byte of the register; 0 means "no shift" (result passes
     * through); >= 32 (but < 256) yields 0.  Provable here: fallthrough
     * forces neg_shift in [0,31], so the branches mirror the ISA rule
     * rather than widen behaviour.
     */
    amount = neg_shift & 0xFFu;
    if (amount == 0u)
        return significand;
    if (amount >= 32u)
        return 0u;
    return significand >> amount;
}

/* __aeabi_d2uiz is the ARM EABI entry for this same leaf (original: one
 * 84-byte body, two GLOBAL FUNC symbols at 0x31b0d0).  Model it as a real
 * same-address alias, not a tail-calling wrapper.
 */
uint32_t __aeabi_d2uiz(double) __attribute__((alias("__fixunsdfsi")));
