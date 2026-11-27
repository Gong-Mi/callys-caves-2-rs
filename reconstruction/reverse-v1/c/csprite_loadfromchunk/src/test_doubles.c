/* test_doubles.c — 【测试替身 / 依赖模型，不是原版实现】
 *
 * 这里提供的 CSprite_Clear / CSprite_BuildSWFData / CSkeletonSprite_ctor /
 * yy_operator_new / yy_operator_new_array / g_isZeus / g_pWADBaseAddress / arena
 * 只用于把译文跑起来、观察控制流与字段落位。
 *
 * ★ 它们**不代表**原版语义，也不是对未恢复依赖的补写：
 *   - CSprite_Clear 只做「清 0 + 按 Clear 卡实测的默认值落几格」，并把 +0x35 故意
 *     写成哨兵 0xAA（原版 ctor 是 1），这样任何一次写入都能被看出来；
 *   - BuildSWFData / CSkeletonSprite 构造只记录实参，不产生任何对象；
 *   - 分配器按 MemoryManager::Alloc 的静态合同建模（0x27ce78 / 0x27cd54）：
 *       size == 0            → NULL（27ce7c/27ce84）
 *       size >= 0xFFFFFFEF   → NULL（27cda8..27cdc4：size+16 > 0xFFFFFFFE）
 *       替身 arena 装不下     → NULL（对应原版 malloc 失败那条 27cdd4）
 *       否则                  → 一块**已清零**的 arena 切片（27ced0 memset）
 *     不模拟 C++ 异常，也不 abort —— 静态追下来这两条不在可见路径上（见头文件）。
 *   - arena 只在低 4 GiB：CSprite 的指针槽是 4 B，64 位宿主必须把对象放低地址，
 *     否则 yy_slot_set 截断。host 构建用 mmap 固定映射，ARM32 用静态数组。
 *
 * 因此本目录的测试结论只到「译文自身分支/偏移/算式与原版指令一致」，
 * 不构成「与原版二进制行为等价」的证据。
 */
#include "csprite_loadfromchunk.h"
#include "test_doubles.h"

#include <stddef.h>
#include <stdint.h>

/* 不 include <string.h>：armv7a-none-eabi 的 freestanding 头里没有它。
 * 这两个函数 host 构建来自 libc，ARM 构建由本文件末尾提供。 */
void *memset(void *d, int c, size_t n);
void *memcpy(void *d, const void *s, size_t n);

/* ── 被观测的全局 ─────────────────────────────────────────────────────── */
uint8_t g_isZeus = 0;
unsigned char *g_pWADBaseAddress = 0;

/* ── 记账 ─────────────────────────────────────────────────────────────── */
td_log_t td;
void (*td_alloc_hook)(void);

/* ── 低地址 arena ─────────────────────────────────────────────────────── */
#define TD_ARENA_SIZE  (1u << 20)
#define TD_FIXTURE_END (64u << 10)      /* [0,64K) 夹具；[64K,1M) 分配器 */

#if defined(HARNESS_FREESTANDING)
static unsigned char td_arena_store[TD_ARENA_SIZE] __attribute__((aligned(64)));
static unsigned char *td_arena = td_arena_store;
static void td_arena_init(void) { }
#else
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
static unsigned char *td_arena;
static void td_arena_init(void)
{
    static const uintptr_t bases[] = { 0x20000000u, 0x30000000u, 0x40000000u,
                                       0x10000000u, 0x50000000u };
    for (unsigned i = 0; i < sizeof bases / sizeof bases[0]; ++i) {
        void *p = mmap((void *)bases[i], TD_ARENA_SIZE, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
        if (p != MAP_FAILED) { td_arena = (unsigned char *)p; return; }
    }
    fprintf(stderr, "FATAL: 无法映射低 4 GiB arena（32 位指针模型跑不了）\n");
    exit(90);
}
#endif

static uint32_t td_fix_used;
static uint32_t td_alloc_used;

static void *td_bump(uint32_t *cur, uint32_t n, uint32_t limit, const char *who)
{
    uint32_t off = (*cur + 15u) & ~15u;
    void *p = td_arena + off;
    if (off + n > limit || (uintptr_t)p + n > 0xFFFFFFFFu) {
        (void)who;
        return NULL;
    }
    *cur = off + (uint32_t)n;
    memset(p, 0, n);
    return p;
}

static void td_arena_guard(void)
{
    static int inited;
    if (!inited) { td_arena_init(); inited = 1; td_fix_used = 0; td_alloc_used = TD_FIXTURE_END; }
}

void td_fixture_reset(void)
{
    td_arena_guard();
    td_fix_used = 0;
}

void *td_fixture_alloc(uint32_t n)
{
    td_arena_guard();
    return td_bump(&td_fix_used, n, TD_FIXTURE_END, "fixture");
}

void td_reset(void)
{
    td_arena_guard();
    memset(&td, 0, sizeof(td));
    td_alloc_used = TD_FIXTURE_END;   /* 每个用例从分配器区开头切 */
    td_alloc_hook = 0;
}

/* ── 替身：CSprite::Clear 0x1e6b4c（只到「清场 + 默认值」这一层）──────────
 * 合成链路（integration/）里链接的是**真实的 Clear 译文**，那时用
 * -DCSPRITE_CHAIN_WITH_REAL_CLEAR 把这份替身编译掉，避免重复定义。 */
#if !defined(CSPRITE_CHAIN_WITH_REAL_CLEAR)
void CSprite_Clear(CSprite *self)
{
    td.clear_calls++;
    memset(self, 0, sizeof(*self));
    /* Clear 0x1e6c28..0x1e6c64 实测落位：宽高=1、三个 bool=1、+0x74=0。
     * +0x35 用哨兵 0xAA 代替 1（原版 Clear 不写这格），见文件头。*/
    self->width = 1;
    self->height = 1;
    self->flag_30 = 1;
    self->flag_32 = 1;
    self->flag_33 = 1;
    self->flag_34 = 1;
    self->flag_35 = 0xAA;      /* ← 故意不是 1 */
    self->owns_local_tpe = 0;
    self->type = 0;
    self->field_78 = 0;
}
#endif /* !CSPRITE_CHAIN_WITH_REAL_CLEAR */

/* ── 替身：CSprite::BuildSWFData 0x1e838c（只记实参）───────────────────── */
int CSprite_BuildSWFData(CSprite *self, char *data, int w, int h)
{
    td.build_calls++;
    td.build_self = self;
    td.build_data = data;
    td.build_w = w;
    td.build_h = h;
    return 1;
}

/* ── 替身：CSkeletonSprite::CSkeletonSprite(char*, u32×5) 0xbd86c（只记实参）*/
#if !defined(CSPRITE_CHAIN_WITH_REAL_SKELETON)
void *CSkeletonSprite_ctor(void *self, char *name,
                          unsigned a, unsigned b, unsigned c,
                          unsigned d, unsigned e)
{
    td.skel_calls++;
    td.skel_self = self;
    td.skel_name = name;
    td.skel_a = a; td.skel_b = b; td.skel_c = c; td.skel_d = d; td.skel_e = e;
    return self;
}
#endif /* !CSPRITE_CHAIN_WITH_REAL_SKELETON */

/* ── 分配器替身：MemoryManager::Alloc 的静态合同 ─────────────────────── */
static void *td_alloc_contract(uint32_t size)
{
    if (size == 0)
        return NULL;                      /* 27ce7c..27ce84 */
    if (size >= 0xFFFFFFEFu)
        return NULL;                      /* 27cda8..27cdc4 */
    return td_bump(&td_alloc_used, size, TD_ARENA_SIZE, "alloc");
}

void *yy_operator_new(uint32_t size)
{
    void *p;
    td.new_scalar_calls++;
    td.new_scalar_size = size;
    p = td_alloc_contract(size);
    td.new_scalar_ptr32 = (uint32_t)(uintptr_t)p;
    if (td_alloc_hook) { td.alloc_hook_calls++; td_alloc_hook(); }
    return p;
}

void *yy_operator_new_array(uint32_t size)
{
    void *p;
    td.new_array_calls++;
    td.new_array_size = size;             /* 记原版实参，不记宿主放大后的尺寸 */
    p = td_alloc_contract(size);
    td.new_array_ptr32 = (uint32_t)(uintptr_t)p;
    td.new_array_null = (p == NULL);
    if (td_alloc_hook) { td.alloc_hook_calls++; td_alloc_hook(); }
    return p;
}

/* ── freestanding 运行时（只用于 ARM32 静态二进制）──────────────────────── */
#if defined(HARNESS_FREESTANDING)

float sqrtf(float x)
{
    /* vsqrt.f32 的正确舍入结果；负数给 NaN（与原版走上慢路径后的结果同域）。
     * 这里不用 libm，避免 -nostdlib 下没有实现。 */
    float r;
    __asm__("vsqrt.f32 %0, %1" : "=t"(r) : "t"(x));
    return r;
}

float ceilf(float x)
{
    union { float f; uint32_t u; } v;
    uint32_t sign, exp, frac_mask, t;
    int32_t e;
    float base;

    v.f = x;
    sign = v.u & 0x80000000u;
    exp = (v.u >> 23) & 0xFFu;
    if (exp == 0xFFu)
        return x;                     /* inf / NaN 原样 */
    e = (int32_t)exp - 127;
    if (e >= 23)
        return x;                     /* 已是整数 */
    if (e < 0) {                      /* |x| < 1 */
        if ((v.u & 0x7FFFFFFFu) == 0)
            return x;                 /* ±0 */
        v.u = sign ? 0x80000000u : 0x3F800000u;   /* -0.0 / 1.0 */
        return v.f;
    }
    frac_mask = (1u << (23 - e)) - 1u;
    if ((v.u & frac_mask) == 0)
        return x;                     /* 已经是整数 */
    t = v.u & ~frac_mask;
    memcpy(&base, &t, 4);
    return sign ? base : base + 1.0f;  /* 向 +inf */
}

void *memset(void *d, int c, size_t n)
{
    unsigned char *p = (unsigned char *)d;
    size_t i;
    for (i = 0; i < n; ++i) p[i] = (unsigned char)c;
    return d;
}

void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *p = (unsigned char *)d;
    const unsigned char *q = (const unsigned char *)s;
    size_t i;
    for (i = 0; i < n; ++i) p[i] = q[i];
    return d;
}

void *memmove(void *d, const void *s, size_t n)
{
    unsigned char *p = (unsigned char *)d;
    const unsigned char *q = (const unsigned char *)s;
    size_t i;
    if (p <= q) {
        for (i = 0; i < n; ++i) p[i] = q[i];
    } else {
        for (i = n; i != 0; --i) p[i - 1] = q[i - 1];
    }
    return d;
}

int memcmp(const void *a, const void *b, size_t n)
{
    const unsigned char *p = (const unsigned char *)a, *q = (const unsigned char *)b;
    size_t i;
    for (i = 0; i < n; ++i)
        if (p[i] != q[i]) return (int)p[i] - (int)q[i];
    return 0;
}

#endif /* HARNESS_FREESTANDING */
