/*
 * spine_json_error.h — error path and file wrapper for spine JSON.
 * No system includes: bare-metal ARM32, all externs declared manually.
 */
#ifndef YY_SPINE_JSON_ERROR_H
#define YY_SPINE_JSON_ERROR_H

#include <stdint.h>
#include <stddef.h>

/* Forward declarations (layout in spine_json_lifetime.c). */
struct spSkeletonData;

typedef struct spSkeletonData spSkeletonData;

/* One complete parser record for creation, error handling and mesh queues. */
#include "../../spine_json_layout.h"

/* libc string functions (bare-metal declarations). */
extern size_t strlen(const char* s);
extern char* strcpy(char* dst, const char* src);
extern char* strncat(char* dst, const char* src, size_t n);

/* Named-boundary externs. */
extern void* _malloc(int size, const char* tag, int line);
extern void  _free(void* p);
extern void* _readFile(const char* path, int* out_size);
extern void  ReportSpineError(const char* message);
extern void  Json_dispose(void* json);

/* The 13 KB gap — not recovered here. */
extern spSkeletonData* spSkeletonJson_readSkeletonData(spSkeletonJson* self, void* data);

/* Public API (matches dynsym). */
void _spSkeletonJson_setError(spSkeletonJson* self, void* json,
                              const char* message, const char* extra);
spSkeletonData* spSkeletonJson_readSkeletonDataFile(spSkeletonJson* self, const char* path);

#endif /* YY_SPINE_JSON_ERROR_H */
