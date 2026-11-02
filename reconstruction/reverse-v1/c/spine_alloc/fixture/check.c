/*
 * One-fixture self-check for the reconstructed six spine allocation entries.
 * Not an oracle for the original binary (stage gate forbids executing it);
 * it only exercises the C translation's own contracts and 32-bit paths.
 *
 * Build/run (single command pair):
 *   clang --target=armv7a-none-eabi -march=armv7a -marm -mfloat-abi=soft \
 *     -std=c11 -O2 -fPIC -ffreestanding -fno-builtin -fno-stack-protector \
 *     -nostdlib -Wl,-e,_start -Wl,--build-id=none \
 *     src/spine_alloc.c src/selfcheck.c -o build/selfcheck.arm
 *   qemu-arm build/selfcheck.arm
 */
#include "spine_alloc.h"

static char obuf[1024];
static unsigned olen;
static int failures;

static void oc(char c) { if (olen < sizeof obuf) obuf[olen++] = c; }
static void os(const char *s) { while (*s != 0) oc(*s++); }
static void nl(void) { oc('\n'); }
static void ck(int cond, const char *name)
{
    os(cond ? "OK " : "FAIL ");
    os(name);
    nl();
    if (!cond) failures++;
}

/* qemu-arm user mode: r7=4 write, r7=1 exit. */
static long sys3(long nr, long a, long b, long c)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r7 __asm__("r7") = nr;
    __asm__ __volatile__("svc #0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}

static unsigned char arena0[32], arena1[64], arena2[32];
static uint32_t n_malloc0, n_def, n_dbg, n_free0, n_free_fake, n_free_alt, n_memset;
static uint32_t sz0, sz_def, sz_dbg, line_def, line_dbg, memset_n;
static const char *tag_def, *tag_dbg;
static void *memset_dst, *last_free;

/* Initial providers: these are the symbols referenced by the reconstructed
 * .data initializer (original R_ARM_ABS32 -> malloc/free). */
void *malloc(uint32_t size) { n_malloc0++; sz0 = size; return arena0; }
void free(void *ptr) { n_free0++; last_free = ptr; }

static void *def_malloc(uint32_t size, const char *tag, uint32_t line)
{
    n_def++; sz_def = size; tag_def = tag; line_def = line;
    if (size == 0xDEADBEEFu) return 0;
    return arena1;
}
static void *dbg_malloc(uint32_t size, const char *tag, uint32_t line)
{
    n_dbg++; sz_dbg = size; tag_dbg = tag; line_dbg = line;
    return arena2;
}
static void fake_free(void *ptr) { n_free_fake++; last_free = ptr; }
static void alt_free(void *ptr) { (void)ptr; n_free_alt++; }

/* _calloc's dependency; also records zero-length calls, which must not be
 * elided on the non-NULL path. */
void *memset(void *dst, int value, uint32_t count)
{
    n_memset++; memset_n = count; memset_dst = dst;
    unsigned char *p = (unsigned char *)dst;
    for (uint32_t i = 0; i < count; i++) p[i] = (unsigned char)value;
    return dst;
}

static int run(void)
{
    const char *A = "tag/A", *B = "tag/B", *C = "tag/C";
    void *p;

    ck(g_yoyo_debug_malloc == 0, "debug slot zero at load");
    ck((void *)g_yoyo_allocator.malloc_fn == (void *)malloc, "initial malloc provider");
    ck((void *)g_yoyo_allocator.free_fn == (void *)free, "initial free provider");
    ck((char *)&g_yoyo_allocator.free_fn - (char *)&g_yoyo_allocator.malloc_fn == 4,
       "free callback at +4");

    p = _malloc(0x11, A, 7);
    ck(p == arena0 && n_malloc0 == 1 && sz0 == 0x11, "malloc -> initial provider");
    _free(arena0);
    ck(n_free0 == 1 && last_free == arena0, "free -> initial provider");

    _setMalloc(def_malloc);
    _setFree(fake_free);
    p = _malloc(0x22, A, 8);
    ck(p == arena1 && n_def == 1 && sz_def == 0x22 && tag_def == A && line_def == 8,
       "malloc -> default provider with tag/line");

    _setDebugMalloc(dbg_malloc);
    p = _malloc(0x33, B, 9);
    ck(p == arena2 && n_dbg == 1 && n_def == 1 && sz_dbg == 0x33 &&
       tag_dbg == B && line_dbg == 9, "debug malloc wins dispatch");
    _setDebugMalloc(0);
    p = _malloc(0x44, A, 10);
    ck(p == arena1 && n_def == 2 && n_dbg == 1, "debug cleared -> default again");

    for (uint32_t i = 0; i < 32; i++) arena1[i] = 0xAA;
    n_memset = 0; memset_n = 0xFFFFFFFFu;
    p = _calloc(3, 5, C, 11);
    ck(p == arena1 && sz_def == 15 && tag_def == C && line_def == 11, "calloc args forwarded");
    ck(n_memset == 1 && memset_n == 15 && memset_dst == arena1, "calloc memset length");
    ck(arena1[0] == 0 && arena1[14] == 0 && arena1[15] == 0xAA, "calloc zeroes exactly total");

    n_memset = 0; memset_n = 0xFFFFFFFFu;
    p = _calloc(0x40000001u, 4, C, 12);
    ck(p == arena1 && sz_def == 4, "calloc product wraps at 32 bits");
    ck(n_memset == 1 && memset_n == 4, "calloc wrap memset length");

    n_memset = 0; memset_n = 0xFFFFFFFFu;
    p = _calloc(0, 0xFFFFFFFFu, C, 13);
    ck(p == arena1 && sz_def == 0, "calloc zero total, non-NULL");
    ck(n_memset == 1 && memset_n == 0, "zero-length memset still called");

    n_memset = 0; memset_n = 0xFFFFFFFFu;
    p = _calloc(0xDEADBEEFu, 1, C, 14);
    ck(p == 0 && sz_def == 0xDEADBEEFu, "calloc NULL result");
    ck(n_memset == 0, "NULL path skips memset");

    uint32_t f0 = n_free_fake;
    _free(0);
    ck(n_free_fake == f0 + 1 && last_free == 0, "free forwards NULL");
    _free(arena2);
    ck(n_free_fake == f0 + 2 && last_free == arena2, "free forwards pointer");

    _setFree(alt_free);
    _free(arena0);
    ck(n_free_alt == 1 && n_free_fake == f0 + 2, "setFree replaces callback");

    _setMalloc(0);
    ck(g_yoyo_allocator.malloc_fn == 0, "setMalloc stores NULL");
    _setFree(0);
    ck(g_yoyo_allocator.free_fn == 0, "setFree stores NULL");
    _setMalloc(def_malloc);
    _setFree(fake_free);
    return failures;
}

void _start(void)
{
    int rc = run();
    if (olen != 0) (void)sys3(4, 1, (long)obuf, (long)olen);
    (void)sys3(1, rc ? 1 : 0, 0, 0);
    for (;;) { }
}
