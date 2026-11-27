/* Original internal ARM32 toColor@0x28b680: r0/r1 inputs, s0 result. */
#ifndef YY_SPINE_COLOR_H
#define YY_SPINE_COLOR_H
#if !defined(__arm__) || !defined(__ARM_FP) || defined(__ARM_PCS_VFP)
#error "spine color requires ARM32 VFP softfp translation units"
#endif
/* Original internal helper returns float in s0, unlike public Json_getFloat
 * (r0 bit-pattern return). A per-function PCS preserves that actual boundary. */
__attribute__((pcs("aapcs-vfp"), noinline, no_stack_protector))
float toColor(const char *value, int index);
#endif
