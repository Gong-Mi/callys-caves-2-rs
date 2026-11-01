/* fx.h — 夹具运行时（host: mmap 低地址 + POSIX write；ARM32: 静态 BSS + 原生 syscall）
 *
 * 为什么必须有“低地址”约束：csprite_clear.h 用 uint32_t 承载指针以锁 ARM32 偏移。
 * 译文和夹具都把图节点地址装进这些字段，所以整张图必须落在 4 GiB 以下。
 * host 用 MAP_FIXED_NOREPLACE 在 0x20000000 开 1 MiB；ARM32 用 .bss 静态数组
 * （qemu-user 的 ET_EXEC 镜像在 0x10000 起，天然 < 4 GiB）。
 */
#ifndef FX_H
#define FX_H

#include <stdint.h>
#include <stddef.h>

#ifdef FX_FREESTANDING
/* ---------- ARM32 freestanding ---------- */
static uint8_t fx_arena_mem[1u << 20] __attribute__((aligned(16)));

static long fx_sys3(long n, long a, long b, long c)
{
    register long r7 __asm__("r7") = n;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}

static void fx_puts(const char *s)
{
    size_t n = 0;
    while (s[n]) ++n;
    if (n) fx_sys3(4 /*write*/, 1, (long)(uintptr_t)s, (long)n);
}

static void fx_exit(int code) __attribute__((noreturn));
static void fx_exit(int code)
{
    fx_sys3(1 /*exit*/, code, 0, 0);
    for (;;) { }
}

static int fx_map_arena(void) { return 0; }
#define FX_ARENA_BASE ((uintptr_t)fx_arena_mem)

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);
void *memmove(void *d, const void *s, size_t n);

#else
/* ---------- host ---------- */
#include <sys/mman.h>
#include <unistd.h>

static void fx_puts(const char *s)
{
    size_t n = 0;
    while (s[n]) ++n;
    if (n) { ssize_t w = write(1, s, n); (void)w; }
}

static void fx_exit(int code) __attribute__((noreturn));
static void fx_exit(int code) { _exit(code); for (;;) { } }

static uintptr_t fx_arena_base;
#define FX_ARENA_BASE (fx_arena_base)

static int fx_map_arena(void)
{
    const uintptr_t want = 0x20000000u;
    const size_t    len  = 1u << 20;
    /* 0x100000 = MAP_FIXED_NOREPLACE：不覆盖既有映射，占用则失败 */
    void *p = mmap((void *)want, len, PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS | 0x100000, -1, 0);
    if (p == (void *)want) { fx_arena_base = want; return 0; }
    if (p != MAP_FAILED) munmap(p, len);
    p = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (p == MAP_FAILED) return -1;
    fx_arena_base = (uintptr_t)p;
    if (fx_arena_base + len > 0x100000000ull) return -1;  /* 32 位字段装不下 */
    return 0;
}
#endif

static uint32_t fx_bump;

static uint32_t fx_alloc(uint32_t n)
{
    uint32_t a = (uint32_t)FX_ARENA_BASE + fx_bump;
    fx_bump = (fx_bump + n + 7u) & ~7u;
    if (fx_bump > (1u << 20)) { fx_puts("FAIL arena overflow\n"); fx_exit(91); }
    return a;
}

static inline uint32_t fx_r32(uint32_t a) { return *(volatile uint32_t *)(uintptr_t)a; }
static void fx_w32(uint32_t a, uint32_t v) { *(volatile uint32_t *)(uintptr_t)a = v; }

#endif /* FX_H */
