/* string.h — the three declarations this arm needs, and nothing else.
 *
 * The claim arm is built for armv7a-none-eabi with no libc headers on the
 * include path, and c/box_type.c (recovered separately, not ours to edit)
 * includes <string.h> for memcpy/memset.  This shim is what that include finds:
 * prototypes only, so the compiler can emit the calls the driver implements.
 */
#ifndef DO_ADD_STRING_SHIM_H
#define DO_ADD_STRING_SHIM_H

#include <stddef.h>

void *memcpy(void *dst, const void *src, unsigned n);
void *memset(void *dst, int c, unsigned n);
int memcmp(const void *a, const void *b, unsigned n);
char *strcpy(char *dst, const char *src);
size_t strlen(const char *s);

#endif
