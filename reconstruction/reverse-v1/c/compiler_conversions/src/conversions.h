#ifndef CALLY_COMPILER_CONVERSIONS_H
#define CALLY_COMPILER_CONVERSIONS_H
#include <stdint.h>

/* Original soft conversion interfaces; no invented saturating cast/provider.
 * tier: bytecode_anchored, ARM image SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * The helper pair is reconstructed in C with its exported C/ARM EABI aliases;
 * original source-file spelling is not inferred from the C ABI alone.
 * gap: software arithmetic/comparison callees and their exception domains
 * remain internal debt until separately recovered. No target execution here.
 */
#if !defined(__arm__) || __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error "Original conversion helpers require little-endian ARM32"
#endif
#if defined(__ARM_PCS_VFP)
#error "Original helper boundary uses base AAPCS core-register floating arguments"
#endif
#ifdef __cplusplus
extern "C" {
#endif
int64_t __fixdfdi(double);
int64_t __aeabi_d2lz(double);
uint64_t __fixunsdfdi(double) __attribute__((noinline)); /* preserve the signed wrapper's helper boundary */
uint64_t __aeabi_d2ulz(double);
int32_t __aeabi_dcmplt(double, double);
double __muldf3(double, double);
uint32_t __fixunsdfsi(double);
double __floatunsidf(uint32_t);
double __subdf3(double, double);
#ifdef __cplusplus
}
#else
_Static_assert(sizeof(void *) == 4 && sizeof(double) == 8 && sizeof(uint64_t) == 8,
               "original ARM32 scalar ABI");
#endif
#endif
