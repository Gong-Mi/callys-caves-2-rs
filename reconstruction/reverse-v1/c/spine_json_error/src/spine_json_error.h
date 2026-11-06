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

/* spSkeletonJson: 28 B / 7 slots (from spine_json_lifetime.c static evidence). */
struct spSkeletonJson {
    uint32_t scale;        /* +0x00 float 1.0f */
    uint32_t loader;       /* +0x04 spAttachmentLoader* */
    char*   error;         /* +0x08 dispose free; setError writes */
    uint32_t owns_loader;  /* +0x0c create sets 1 */
    uint32_t unk_10;       /* +0x10 */
    uint32_t unk_14;       /* +0x14 */
    uint32_t unk_18;       /* +0x18 dispose free */
};
typedef struct spSkeletonJson spSkeletonJson;

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
