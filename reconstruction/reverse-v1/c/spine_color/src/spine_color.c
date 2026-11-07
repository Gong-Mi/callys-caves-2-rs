/* tier: bytecode_anchored. Read-only original 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 * toColor range 0x28b680..0x28b700; code ends 0x28b6fc, final 4B=255.0f.
 * No NULL/index guard exists. Imported strtoul owns whitespace/sign handling;
 * replacing it by a hex-digit loop changes accepted strings ("+1", " 1"). */
#include "spine_color.h"
#include <stdint.h>
#include <stddef.h>
extern size_t strlen(const char *);
extern unsigned long strtoul(const char *, char **, int);
float toColor(const char *value, int index) {
    char digits[3], *end;
    if (strlen(value) != 8u) return -1.0f; /* 0x28b690..0x28b6a4 */
    uint32_t offset = (uint32_t)index << 1; /* 0x28b6a8/6ac: ARM32 wrap */
    const unsigned char *p = (const unsigned char *)(uintptr_t)
        ((uint32_t)(uintptr_t)value + offset);
    digits[0] = (char)p[0]; digits[1] = (char)p[1]; digits[2] = 0;
    uint32_t color = (uint32_t)strtoul(digits, &end, 16); /* 0x28b6d0 */
    if (*end != 0) return -1.0f; /* 0x28b6d4..0x28b6e0 */
    float converted, result;
    /* strtoul returns unsigned, but ORIGINAL explicitly uses signed VCVT.
     * A two-character "-1" is 0xffffffff -> -1.0f, NOT 4294967296.0f. */
    __asm__ volatile("vmov %0, %1\n\tvcvt.f32.s32 %0, %0"
        : "=&t"(converted) : "r"(color) : "memory"); /* 0x28b6e4/6e8 */
    __asm__ volatile("vdiv.f32 %0, %1, %2" : "=t"(result)
        : "t"(converted), "t"(255.0f) : "memory"); /* 0x28b6f0 */
    return result;
}
