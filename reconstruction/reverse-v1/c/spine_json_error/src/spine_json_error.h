/*
 * spine_json_error.h — error formatting and file wrapper for spine JSON.
 *
 * Original image: libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Recovered here:
 *   _spSkeletonJson_setError             0x28b784  200 B
 *   spSkeletonJson_readSkeletonDataFile  0x28eb40  120 B
 *
 * Shared parser layout is the canonical 28-byte record in spine_json_layout.h;
 * Json is the canonical 32-byte record in json_interface.h.  Non-recovered
 * file I/O and the full loader remain explicit boundaries.
 */
#ifndef YY_SPINE_JSON_ERROR_H
#define YY_SPINE_JSON_ERROR_H

#include <stdint.h>
#include <stddef.h>

struct spSkeletonData;
typedef struct spSkeletonData spSkeletonData;

#include "../../spine_json_layout.h"
#include "../../spine_json_support/src/spine_json_support.h"

/* libc string providers (bare-metal declarations; calls are real PLT calls
 * strcpy 0xb65a4, strlen 0xb6538, strncat 0xb6c1c in the original). */
extern size_t strlen(const char *s);
extern char *strcpy(char *dst, const char *src);
extern char *strncat(char *dst, const char *src, size_t n);

/*
 * Canonical spine_alloc prototypes.  Keep the exact uint32_t size/line types
 * of c/spine_alloc/src/spine_alloc.h; the old int/int spelling conflicts.
 * _malloc 0x285c10, _free 0x285c80 — both real reconstructed functions.
 */
#include "../../spine_alloc/src/spine_alloc.h"

/*
 * Named file-I/O gap, deliberately not recovered in this batch:
 *   0xbd83c _spUtil_readFile is one ARM instruction: b 0x285cd8 (_readFile).
 *   0x285cd8 _readFile body is NOT present in spine_alloc.c (that module ends
 *   at _setFree 0x285cc4/0x285cd8).  The fixture provider used to exercise
 *   the wrapper is synthetic and is not an original-function recovery.
 */
extern void *_readFile(const char *path, int32_t *out_size);

/* Named 13 KB loader gap (0x28b84c, 3261 instructions), not recovered here. */
extern spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *self,
                                                       const char *data);

/* Public API (matches .dynsym). */
__attribute__((noinline, disable_tail_calls))
void _spSkeletonJson_setError(spSkeletonJson *self, void *json,
                              const char *message, const char *extra);
spSkeletonData *spSkeletonJson_readSkeletonDataFile(spSkeletonJson *self,
                                                    const char *path);

#endif /* YY_SPINE_JSON_ERROR_H */
