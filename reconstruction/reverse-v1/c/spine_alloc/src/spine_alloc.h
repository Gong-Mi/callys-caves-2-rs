/*
 * spine_alloc.h - yoyo/spine allocation entry points, reconstructed from
 * libyoyo_armv7.so (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Original layout facts (static, byte-anchored):
 *   _malloc          0x285c10  size 0x3c  ARM
 *   _calloc          0x285c4c  size 0x34  ARM
 *   _free            0x285c80  size 0x1c  ARM
 *   _setDebugMalloc  0x285c9c  size 0x14  ARM
 *   _setMalloc       0x285cb0  size 0x14  ARM
 *   _setFree         0x285cc4  size 0x14  ARM
 *
 * Global storage (two separate objects, not one table):
 *   0x3f7790  malloc callback  .data  R_ARM_ABS32 -> imported malloc (addend 0)
 *   0x3f7794  free callback    .data  R_ARM_ABS32 -> imported free   (addend 0)
 *   0x756bc4  debug malloc cb  .bss   no relocation, zero at load
 *
 * The two .data slots are adjacent and accessed as base+0 / base+4; the
 * debug slot is a separate 4-byte object.  Both original addresses are
 * 4-byte aligned.  This translation unit preserves the 32-bit pointer
 * width and those offsets; there is no 64-bit approximation.
 */

#ifndef YOYO_SPINE_ALLOC_H
#define YOYO_SPINE_ALLOC_H

#include <stdint.h>
#include <stddef.h>

#if !defined(__arm__) || defined(__aarch64__)
#error "yoyo spine allocation is ARM32 (ILP32, AAPCS) only"
#endif
#if !defined(__clang__)
#error "spine allocator reconstruction requires Clang call-boundary attributes"
#else
#if !__has_attribute(disable_tail_calls)
#error "spine allocator reconstruction requires disable_tail_calls"
#endif
#endif
#if !defined(__SOFTFP__)
#error "spine allocator reconstruction supports ARM32 soft-float only"
#endif

_Static_assert(sizeof(void *) == 4, "ARM32 pointer width required");
_Static_assert(sizeof(uint32_t) == 4, "uint32_t must be 32 bits");

/*
 * Original callback contracts, recovered from the call sites:
 *   malloc callback: r0=size in bytes, r1=source tag (const char *),
 *                    r2=source line; returns pointer in r0.
 *   free callback:   r0=pointer, forwarded unconditionally (NULL included).
 */
typedef void *(*yoyo_malloc_fn)(uint32_t size, const char *tag, uint32_t line);
typedef void (*yoyo_free_fn)(void *ptr);

struct yoyo_allocator_slots {
    uint32_t malloc_fn; /* raw AAPCS32 code address; original +0x00 */
    yoyo_free_fn free_fn;     /* original VA 0x3f7794, offset +0x04 */
};

/*
 * Both globals were local (not present in .dynsym) in the original, so the
 * compiler is told they are not preemptible; this keeps accesses pc-relative
 * instead of routing them through the GOT.
 */
#if defined(__clang__) || defined(__GNUC__)
#define YOYO_LOCAL __attribute__((visibility("hidden")))
#define YOYO_NOINLINE __attribute__((noinline))
#else
#define YOYO_LOCAL
#define YOYO_NOINLINE
#endif

#if defined(__clang__) && __has_attribute(disable_tail_calls)
/* The original calls its callback with blx from inside _malloc/_free and only
 * then returns.  A tail call would hand the callback its caller's return
 * address instead of the address inside _malloc/_free, so keep the frame. */
#define YOYO_NO_TAIL __attribute__((disable_tail_calls))
#else
#define YOYO_NO_TAIL
#endif

YOYO_LOCAL extern struct yoyo_allocator_slots g_yoyo_allocator;
YOYO_LOCAL extern yoyo_malloc_fn g_yoyo_debug_malloc; /* original VA 0x756bc4 */

_Static_assert(sizeof(yoyo_malloc_fn) == 4, "32-bit function pointer required");
_Static_assert(sizeof(yoyo_free_fn) == 4, "32-bit function pointer required");
_Static_assert(offsetof(struct yoyo_allocator_slots, malloc_fn) == 0x00,
               "malloc callback must stay at +0x00");
_Static_assert(offsetof(struct yoyo_allocator_slots, free_fn) == 0x04,
               "free callback must stay at +0x04");
_Static_assert(sizeof(struct yoyo_allocator_slots) == 8,
               "allocator slot pair must be two 32-bit pointers");

/*
 * ABI (all six are STB_GLOBAL / STV_DEFAULT in the original .dynsym):
 *   _malloc(size, tag, line)          -> pointer
 *   _calloc(nmemb, size, tag, line)   -> pointer (nmemb*size wraps at 32 bits)
 *   _free(ptr)                        -> void
 *   _setDebugMalloc(fn)               -> void
 *   _setMalloc(fn)                    -> void
 *   _setFree(fn)                      -> void
 *
 * _malloc is kept out of line because _calloc has a real bl to 0x285c10 in
 * the original; inlining it would erase that documented call boundary.
 * _malloc/_free keep a frame so their callbacks see a return address inside
 * the entry point, exactly like the original blx sites at 0x285c28/0x285c3c
 * and 0x285c90.
 */
YOYO_NOINLINE YOYO_NO_TAIL void *_malloc(uint32_t size, const char *tag, uint32_t line);
void *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line);
YOYO_NO_TAIL void _free(void *ptr);
void _setDebugMalloc(yoyo_malloc_fn fn);
void _setMalloc(yoyo_malloc_fn fn);
void _setFree(yoyo_free_fn fn);

#endif /* YOYO_SPINE_ALLOC_H */
