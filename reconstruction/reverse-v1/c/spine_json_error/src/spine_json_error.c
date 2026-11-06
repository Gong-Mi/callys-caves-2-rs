/*
 * spine_json_error.c — error reporting and file wrapper for the spine JSON chain.
 *
 * Original image:
 *   libyoyo_armv7.so SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to the original instruction address.  The original was not
 * executed.
 *
 * Symbols:
 *   0x28b784  _spSkeletonJson_setError           200 B   50 insns
 *   0x28eb40  spSkeletonJson_readSkeletonDataFile 120 B   30 insns
 *
 * The 13044 B readSkeletonData body (0x28b84c, 3261 insns) is NOT recovered
 * here — it is the next named gap.  This module provides the error path
 * and the file-loading wrapper that it depends on.
 *
 * _spUtil_readFile (0xbd83c, 4 B, 1 insn) is a tail call to _readFile
 * (0x285cd8) — already recovered in spine_alloc.
 *
 * Dependencies (named boundaries):
 *   _malloc 0x285c10   _free 0x285c80   _readFile 0x285cd8
 *   strcpy/strlen/strncat via PLT
 *   ReportSpineError 0xc4404
 *   Json_dispose 0x2872c8
 *   spSkeletonJson_readSkeletonData 0x28b84c  (the 13 KB gap)
 *
 * spSkeletonJson layout (28 B / 7 slots, from spine_json_lifetime.c):
 *   +0x00 scale         +0x04 loader
 *   +0x08 error string  +0x0c owns_loader
 *   +0x10 unused        +0x14 unused        +0x18 unknown (freed)
 */

#include "spine_json_error.h"

/*
 * _spSkeletonJson_setError — formats and stores an error message, optionally
 * disposing the json object.
 *
 * Original ABI: r0=self, r1=json_to_dispose, r2=message, r3=extra_append
 * Stack: 256-byte local buffer + canary.
 */
void
_spSkeletonJson_setError(spSkeletonJson* self, void* json,
                         const char* message, const char* extra)
{
    /* 0x28b790 sub sp, sp, #268 → 256B buffer + 4B canary + alignment */
    char buffer[256];

    /* 0x28b7a4 ldr r0, [r0, #8]; 0x28b7b4 bl _free */
    _free(self->error);

    /* 0x28b7b8 mov r1,r7; 0x28b7bc mov r0,r4; 0x28b7c0 bl strcpy */
    strcpy(buffer, message);

    /* 0x28b7c4 strlen; 0x28b7cc cmp r9,#0; 0x28b7d0 mov r2,r0 */
    /* 0x28b7d4 beq skip; 0x28b7d8 mov r1,r9; 0x28b7dc add r0,r4,r0 */
    /* 0x28b7e0 rsb r2,r2,#255; 0x28b7e4 bl strncat */
    if (extra != NULL) {
        strncat(buffer, extra, 255 - strlen(buffer));
    }

    /* 0x28b7e8 strlen(buffer); 0x28b7fc add r0,r0,#1; 0x28b800 bl _malloc */
    /* 0x28b808 str r0,[r6,#8]  self->error = new string */
    self->error = _malloc(strlen(buffer) + 1, "spine_json_err", 90);

    /* 0x28b80c bl strcpy  copy buffer to self->error */
    strcpy(self->error, buffer);

    /* 0x28b814 bl ReportSpineError(buffer) */
    ReportSpineError(buffer);

    /* 0x28b818 cmp r8,#0; 0x28b81c beq skip; 0x28b820 mov r0,r8 */
    /* 0x28b824 bl Json_dispose */
    if (json != NULL) {
        Json_dispose(json);
    }

    /* 0x28b828-0x28b83c: canary check + pop {r4-r9,pc} */
}

/*
 * spSkeletonJson_readSkeletonDataFile — reads a skeleton JSON file and
 * delegates to spSkeletonJson_readSkeletonData.
 *
 * Original ABI: r0=self, r1=path
 */
spSkeletonData*
spSkeletonJson_readSkeletonDataFile(spSkeletonJson* self, const char* path)
{
    /* 0x28eb48 sub sp,sp,#8; 0x28eb50 add r1,sp,#4 */
    int size = 0;

    /* 0x28eb54 mov r0,r5(path); 0x28eb58 bl _spUtil_readFile(path,&size) */
    /* _spUtil_readFile is a 1-insn tail call to _readFile (0x285cd8) */
    void* data = _readFile(path, &size);

    /* 0x28eb5c ldr r3,[sp,#4]; 0x28eb60 cmp r3,#0; 0x28eb64 mov r4,r0 */
    /* 0x28eb68 mov r0,r6(self); 0x28eb6c beq 0x28eb98 (error path) */
    /* 0x28eb70 cmp r4,#0; 0x28eb74 beq 0x28eb98 */
    if (size == 0 || data == NULL) {
        /* 0x28eb98-0x28eba8: setError(self, 0, "Error reading skeleton file: ", path) */
        _spSkeletonJson_setError(self, 0, "Error reading skeleton file: ", path);
        /* 0x28ebac mov r0,#0 */
        return NULL;
    }

    /* 0x28eb78 mov r1,r4(data); 0x28eb7c bl readSkeletonData(self, data) */
    spSkeletonData* result = spSkeletonJson_readSkeletonData(self, data);

    /* 0x28eb84 mov r0,r4; 0x28eb88 bl _free(data) */
    _free(data);

    /* 0x28eb8c mov r0,r5; 0x28eb90 add sp,sp,#8; 0x28eb94 pop */
    return result;
}
