/*
 * spine_json_error.c — error formatting and file wrapper for the spine JSON
 * chain, reconstructed from libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to an original instruction address.  The original was not
 * executed.
 *
 *   0x28b784 _spSkeletonJson_setError             200 B (192 code + 8 pool)
 *   0x28eb40 spSkeletonJson_readSkeletonDataFile  120 B (116 code + 4 pool)
 *
 * Corrected versus the earlier draft:
 *   - _malloc tag is the complete original literal at 0x357b08, not a short
 *     "spine_json_err" placeholder.  The address is formed at 0x28b7f8:
 *     PC (0x28b800) + pool 0xcc308 = 0x357b08; line is 0x5a = 90.
 *   - file failure text is the original 0x357f70
 *     "Unable to read skeleton file: ", not "Error reading skeleton file: ".
 *
 * Still open, named boundaries:
 *   0x28b84c spSkeletonJson_readSkeletonData  13044 B, 3261 insns (not here)
 *   0x285cd8 _readFile                        body not recovered (not here);
 *            0xbd83c _spUtil_readFile is one tail branch to it.
 *   stack canary is retained by required -fstack-protector-strong/global.
 *   disable_tail_calls keeps its comparison AFTER optional Json_dispose;
 *   exact original frame offsets and malformed-buffer faults are not certified.
 */

#include "spine_json_error.h"
#if !defined(__SSP_STRONG__) && !defined(__SSP_ALL__)
#error "setError requires real stack-protector-strong/global code generation"
#endif

/*
 * _spSkeletonJson_setError — formats message + optional extra, stores an owned
 * copy in self->error, reports it, then optionally disposes json.
 *
 * Original ABI: r0=self, r1=json_to_dispose, r2=message, r3=extra_append.
 * Stack: 256-byte buffer at sp+4, canary at sp+0x104.
 *
 * Exact order from 0x28b784:
 *   _free(self->error)                      @0x28b7a4..0x28b7b4
 *   strcpy(buffer, message)                 @0x28b7b8..0x28b7c0
 *   strlen(message); if extra strncat(...)  @0x28b7c4..0x28b7e4
 *   _malloc(strlen(buffer)+1, tag, 90)      @0x28b7e8..0x28b800
 *   self->error = result                    @0x28b808
 *   strcpy(self->error, buffer)             @0x28b80c
 *   ReportSpineError(buffer)                @0x28b814
 *   if (json) Json_dispose(json)            @0x28b818..0x28b824
 */
void
_spSkeletonJson_setError(spSkeletonJson* self, void* json,
                         const char* message, const char* extra)
{
    /* 0x28b790 sub sp, sp, #0x10c -> 256-byte buffer + canary */
    char buffer[256];

    /* 0x28b7a4 ldr r0,[r0,#8]; 0x28b7b4 bl _free: unconditional, NULL ok */
    _free((void *)(uintptr_t)self->error);

    /* 0x28b7b8 mov r1,r7; 0x28b7bc mov r0,r4; 0x28b7c0 bl strcpy */
    strcpy(buffer, message);

    /* 0x28b7c4 strlen; 0x28b7cc cmp r9,#0; 0x28b7d4 beq skip;
     * 0x28b7e0 rsb r2,r2,#0xff; 0x28b7e4 bl strncat.
     * The bound is 255 - strlen(message), wrapping at 32 bits exactly like
     * the original rsb if message is longer than 255. */
    uint32_t message_length = (uint32_t)strlen(message); /*0x28b7c4/c8, ALWAYS*/
    if (extra != NULL) {
        char *append_at = (char *)(uintptr_t)
            ((uint32_t)(uintptr_t)buffer + message_length); /*0x28b7dc*/
        strncat(append_at, extra, 255u - message_length); /*0x28b7e0/e4*/
    }

    /* 0x28b7e8 strlen(buffer); 0x28b7f0 ldr r1,[pc,#0x50];
     * 0x28b7f4 mov r2,#0x5a; 0x28b7f8 add r1,pc,r1 -> 0x357b08;
     * 0x28b7fc add r0,r0,#1; 0x28b800 bl _malloc. */
    char *allocated = _malloc(
        (uint32_t)(strlen(buffer) + 1u),
        "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c",
        90u);

    /* 0x28b804 mov r1,r4; 0x28b808 str r0,[r6,#8]; 0x28b80c bl strcpy */
    self->error = (uint32_t)(uintptr_t)allocated;
    strcpy(allocated, buffer);

    /* 0x28b810 mov r0,r4; 0x28b814 bl ReportSpineError */
    ReportSpineError(buffer);

    /* 0x28b818 cmp r8,#0; 0x28b81c beq skip; 0x28b820 mov r0,r8;
     * 0x28b824 bl Json_dispose */
    if (json != NULL) {
        Json_dispose((Json *)json);
    }

    /* 0x28b828..0x28b840: compiler-generated global canary check AFTER disposal. */
}

/*
 * spSkeletonJson_readSkeletonDataFile — reads a skeleton JSON file and
 * delegates to spSkeletonJson_readSkeletonData.
 *
 * Original ABI: r0=self, r1=path.
 * 0x28eb48 sub sp,sp,#8; 0x28eb50 add r1,sp,#4 (int32_t size uninitialised)
 * 0x28eb58 bl 0xbd83c (_spUtil_readFile -> b 0x285cd8 _readFile)
 * 0x28eb5c ldr r3,[sp,#4]; cmp #0; beq error
 * 0x28eb70 cmp r4,#0; beq error
 * 0x28eb7c bl 0x28b84c (unrecovered loader)
 * 0x28eb88 bl _free(data)
 */
/* Original 0x28eb40 has no stack canary (the canary is only in
 * _spSkeletonJson_setError).  Keep that per-function frame shape. */
__attribute__((no_stack_protector))
spSkeletonData*
spSkeletonJson_readSkeletonDataFile(spSkeletonJson* self, const char* path)
{
    /* 0x28eb48..0x28eb50 only reserve the slot: there is no store of zero.
     * The earlier draft's "= 0" changed the original uninitialised local. */
    int32_t size;

    /* 0x28eb54 mov r0,r5; 0x28eb58 bl _spUtil_readFile(path,&size) */
    void* data = _readFile(path, &size);

    /* 0x28eb5c..0x28eb74: size check first, data check second.  The error
     * branch does not free a non-NULL data returned with size == 0. */
    if (size == 0 || data == NULL) {
        /* 0x28eb98 ldr r2,[pc,#0x14] -> 0x28ebb4 + PC 0x28ebac = 0x357f70;
         * 0x28eb9c mov r3,r5(path); 0x28eba0 mov r1,#0;
         * 0x28eba8 bl 0x28b784. */
        _spSkeletonJson_setError(self, NULL,
                                 "Unable to read skeleton file: ", path);
        /* 0x28ebac mov r0,#0 */
        return NULL;
    }

    /* 0x28eb78 mov r1,r4; 0x28eb7c bl spSkeletonJson_readSkeletonData */
    spSkeletonData* result = spSkeletonJson_readSkeletonData(self, data);

    /* 0x28eb84 mov r0,r4; 0x28eb88 bl _free */
    _free(data);

    /* 0x28eb8c mov r0,r5; 0x28eb90..0x28eb94 epilogue */
    return result;
}
