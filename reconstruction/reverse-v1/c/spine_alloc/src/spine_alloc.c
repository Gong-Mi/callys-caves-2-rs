/*
 * spine_alloc.c - byte-anchored C reconstruction of the six allocation
 * entry points in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Evidence tier: bytecode_anchored.  Every branch, load, store and literal
 * below is tied to the original instruction address.  The original was not
 * executed for this file (stage gate: static semantics first).
 *
 * The six symbols sit contiguously:
 *   0x285c10 _malloc (0x3c bytes, ends exactly at _calloc)
 *   0x285c4c _calloc (0x34 bytes, ends exactly at _free)
 *   0x285c80 _free   (0x1c bytes, ends exactly at _setDebugMalloc)
 *   0x285c9c _setDebugMalloc (0x14 bytes, ends exactly at _setMalloc)
 *   0x285cb0 _setMalloc      (0x14 bytes, ends exactly at _setFree)
 *   0x285cc4 _setFree        (0x14 bytes, ends exactly at _readFile 0x285cd8)
 *
 * Literal-pool words inside those ranges are data, not instructions:
 *   0x285c44 0x004d0fa4   0x285c48 0x00171b54
 *   0x285c98 0x00171b00
 *   0x285cac 0x004d0f1c
 *   0x285cc0 0x00171ad4   0x285cd4 0x00171ac0
 * A linear disassembler prints some of them as subeq/andseq/ldrsbeq; they are
 * never executed and are only used by the preceding ldr r3,[pc,#imm].
 */

#include "spine_alloc.h"

/*
 * Imported libc providers.  The original does not call these through the PLT
 * for allocation: 0x3f7790/0x3f7794 are R_ARM_ABS32 data relocations whose
 * symbols are the undefined .dynsym entries malloc (#167) and free (#169).
 * The loader therefore writes the resolved function addresses into the two
 * slots, with addend 0 (the file bytes are zero).
 *
 * Typing malloc as three arguments would misstate the imported symbol; the
 * default slot is a raw four-byte code address, not a mis-typed C function
 * pointer. The inlined BLX bridge forwards the observed AAPCS registers;
 * the one-argument libc declaration remains accurate.
 */
extern void *malloc(uint32_t size);
extern void free(void *ptr);

/* _calloc reaches memset through the PLT: bl 0xb65b0 -> GOT 0x3f1ca0,
 * .rel.plt entry 15, R_ARM_JUMP_SLOT, symbol memset. */
extern void *memset(void *dst, int value, uint32_t count);

/*
 * +0x00: original 0x3f7790, .data, R_ARM_ABS32 malloc (addend 0).
 * +0x04: original 0x3f7794, .data, R_ARM_ABS32 free   (addend 0).
 * Static initialization by the linker reproduces the loader's initial state.
 *
 * Keep the actual imported function address in this slot. Dispatch below
 * uses the ARM32 call boundary, never an incompatible C function-pointer
 * call or a diagnostic suppression.
 */
struct yoyo_allocator_slots g_yoyo_allocator = {
    (uint32_t)(uintptr_t)malloc,
    free,
};

/* ABI-only inlined BLX: the raw slot initially targets one-argument libc
 * malloc but registered callbacks may consume r1/r2. Do not call libc through
 * an incompatible three-argument C function-pointer type. ARM32/soft-float
 * only; this leaf helper always inlines inside the non-inlined _malloc. */
static __attribute__((always_inline)) inline void *call_alloc_wire(
        uint32_t target, uint32_t size, const char *tag, uint32_t line)
{
    register uint32_t a0 __asm__("r0") = size;
    register const char *a1 __asm__("r1") = tag;
    register uint32_t a2 __asm__("r2") = line;
    register uint32_t a3 __asm__("r3") = target;
    __asm__ __volatile__("blx r3" : "+r"(a0), "+r"(a1), "+r"(a2), "+r"(a3)
                         : : "r12", "lr", "cc", "memory");
    return (void *)(uintptr_t)a0;
}

/* Original 0x756bc4, .bss, no relocation: zero until _setDebugMalloc runs.
 * A full .text scan found no internal writer other than _setDebugMalloc. */
yoyo_malloc_fn g_yoyo_debug_malloc;

void *_malloc(uint32_t size, const char *tag, uint32_t line)
{
    /* @0x285c10 push {r3, lr}                       (8-byte call alignment) */
    /* @0x285c14 ldr r3, [pc, #0x28]                 -> literal 0x004d0fa4  */
    /* @0x285c18 add r3, pc, r3                      -> 0x756bc4           */
    /* @0x285c1c ldr r3, [r3]                        -> G_DEBUG_MALLOC     */
    yoyo_malloc_fn debug_malloc = g_yoyo_debug_malloc;

    /* @0x285c20 cmp r3, #0                                                  */
    /* @0x285c24 beq 0x285c30                                                */
    if (debug_malloc != NULL) {
        /* @0x285c28 blx r3; r0/r1/r2 unchanged: (size, tag, line)          */
        /* @0x285c2c pop {r3, pc}: callback's r0 is the result              */
        return debug_malloc(size, tag, line);
    }

    /* @0x285c30 ldr r3, [pc, #0x10]                 -> literal 0x00171b54  */
    /* @0x285c34 add r3, pc, r3                      -> 0x3f7790           */
    /* @0x285c38 ldr r3, [r3]                        -> G_MALLOC            */
    /* @0x285c3c blx r3                                                      */
    /* @0x285c40 pop {r3, pc}                                                */
    /* No NULL test: ABS32 supplies the initial libc address, but a setter
     * may later replace it, including with zero. */
    __asm__ __volatile__("" ::: "memory"); /* keep the default-slot load on the
                                            * fall-through path, as in the
                                            * original read order */
    return call_alloc_wire(g_yoyo_allocator.malloc_fn, size, tag, line);
}

void *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line)
{
    /* @0x285c4c push {r3, r4, r5, lr}                                      */
    /* @0x285c50 mul r4, r1, r0: low 32 bits of nmemb*size, wraps, no check */
    uint32_t total = nmemb * size;

    /* @0x285c54 mov r1, r2   (tag)                                          */
    /* @0x285c58 mov r2, r3   (line)                                         */
    /* @0x285c5c mov r0, r4   (total)                                        */
    /* @0x285c60 bl 0x285c10  (_malloc)                                      */
    void *ptr = _malloc(total, tag, line);

    /* @0x285c64 subs r5, r0, #0                                             */
    /* @0x285c68 beq 0x285c78                                                */
    if (ptr != NULL) {
        /* @0x285c6c mov r2, r4   (total, including zero)                    */
        /* @0x285c70 mov r1, #0                                              */
        /* @0x285c74 bl 0xb65b0   (memset@plt)                               */
        /* memset's return value is discarded by the next instruction.       */
        memset(ptr, 0, total);
    }

    /* @0x285c78 mov r0, r5                                                 */
    /* @0x285c7c pop {r3, r4, r5, pc}                                       */
    return ptr;
}

void _free(void *ptr)
{
    /* @0x285c80 push {r3, lr}                                              */
    /* @0x285c84 ldr r3, [pc, #0xc]                  -> literal 0x00171b00  */
    /* @0x285c88 add r3, pc, r3                      -> 0x3f7790           */
    /* @0x285c8c ldr r3, [r3, #4]                    -> G_FREE              */
    /* @0x285c90 blx r3                                                     */
    /* @0x285c94 pop {r3, pc}                                               */
    /* Unconditional: no debug slot check, no NULL test.                    */
    g_yoyo_allocator.free_fn(ptr);
}

void _setDebugMalloc(yoyo_malloc_fn fn)
{
    /* @0x285c9c ldr r3, [pc, #8]                    -> literal 0x004d0f1c  */
    /* @0x285ca0 add r3, pc, r3                      -> 0x756bc4           */
    /* @0x285ca4 str r0, [r3]                                               */
    /* @0x285ca8 bx lr                                                       */
    g_yoyo_debug_malloc = fn;
}

void _setMalloc(yoyo_malloc_fn fn)
{
    /* @0x285cb0 ldr r3, [pc, #8]                    -> literal 0x00171ad4  */
    /* @0x285cb4 add r3, pc, r3                      -> 0x3f7790           */
    /* @0x285cb8 str r0, [r3]                                               */
    /* @0x285cbc bx lr                                                       */
    g_yoyo_allocator.malloc_fn = (uint32_t)(uintptr_t)fn;
}

void _setFree(yoyo_free_fn fn)
{
    /* @0x285cc4 ldr r3, [pc, #8]                    -> literal 0x00171ac0  */
    /* @0x285cc8 add r3, pc, r3                      -> 0x3f7790           */
    /* @0x285ccc str r0, [r3, #4]                                           */
    /* @0x285cd0 bx lr                                                       */
    g_yoyo_allocator.free_fn = fn;
}
