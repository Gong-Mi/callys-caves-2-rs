/* chain.c — 合成链路：LoadFromChunk 译文 + **真实 Clear 译文** 同一 TU 树、同一 ABI
 *
 * 目的（REVIEW-r2 的「不能只看链接」）：证明两份候选在**同一个 CSprite 定义**下
 * 编译、链接、并真的互相调用，而不是靠符号名对上。
 *
 * 做法：
 *   1. 先 include csprite_clear.h，再 include csprite_loadfromchunk.h（后者在合并形态里
 *      又 include 同一个 header，靠同名 guard 只保留一份定义）；本文件因此能用同一个
 *      CSprite 类型同时调用 CSprite_Clear 与 CSprite_LoadFromChunk。
 *   2. 依赖（MemoryManager::Free / _ZdlPv / D2 / ClearSWFData / FreeTexture / FreeMask）
 *      全部是**替身**：只记录调用，FreeMask 按 Clear 卡记录的尾部三写建模。
 *   3. 跑三段：Load → Clear（真实译文）→ 再 Load；检查字段与「谁被释放」。
 *
 * 不主张：这是原版行为差分。Clear 的文字语义由 clear 线自己的 fixture 负责，
 * 这里只验证跨 TU 的类型/ABI/调用链能成立，以及两条候选对同一对象的交接是否正确。
 */
#include "csprite_clear.h"
#include "csprite_loadfromchunk.h"
#include "test_doubles.h"

#include <stddef.h>
#include <stdint.h>

/* ── 输出（与 driver.c 同一套最简实现）────────────────────────────────── */
#if defined(HARNESS_FREESTANDING)
static long c_sys3(long n, long a, long b, long c)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r7 __asm__("r7") = n;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}
static void c_exit(int code) { c_sys3(1, code, 0, 0); for (;;) { } }
static void c_write(const char *s, unsigned n) { c_sys3(4, 1, (long)s, (long)n); }
#else
#include <stdio.h>
#include <stdlib.h>
__attribute__((unused)) static void c_exit(int code) { exit(code); }
static void c_write(const char *s, unsigned n) { fwrite(s, 1, n, stdout); fflush(stdout); }
#endif

static void c_puts(const char *s) { unsigned n = 0; while (s[n]) ++n; c_write(s, n); }
static void c_putint(int v)
{
    char b[12]; int i = 11, neg = v < 0;
    unsigned u = neg ? (unsigned)(-(v + 1)) + 1u : (unsigned)v;
    b[i] = 0;
    do { b[--i] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) b[--i] = '-';
    c_puts(&b[i]);
}
static void c_puthex(uint32_t v)
{
    char b[11]; b[0] = '0'; b[1] = 'x';
    for (int i = 0; i < 8; ++i) {
        unsigned d = (v >> (28 - 4 * i)) & 15u;
        b[2 + i] = (char)(d < 10 ? ('0' + d) : ('a' + d - 10));
    }
    c_write(b, 10);
}

static int g_fail, g_checks;
static const char *g_case = "?";
static void fail(const char *what, uint32_t a, uint32_t b)
{
    if (!g_fail) {
        c_puts("      first failure: "); c_puts(what);
        c_puts(" got="); c_puthex(a); c_puts(" want="); c_puthex(b); c_puts("\n");
    }
    g_fail = 1;
}
#define CHECK(cond) do { g_checks++; if (!(cond)) fail(#cond, 0, 0); } while (0)
#define CHECK_EQ(a, b) do { g_checks++; \
    uint32_t va_ = (uint32_t)(uintptr_t)(a), vb_ = (uint32_t)(uintptr_t)(b); \
    if (va_ != vb_) fail(#a, va_, vb_); } while (0)

/* ── Clear 的依赖替身（只记调用 + FreeMask 的尾部三写）──────────────────── */
static int   g_free_calls, g_free_hit_table;
static uint32_t g_free_args[8];
static int   g_fmask_calls, g_ftex_calls, g_swf_calls, g_d2_calls, g_del_calls;

void mm_free_stub(const void *p) __asm__("_ZN13MemoryManager4FreeEPKv");
void mm_free_stub(const void *p)
{
    uint32_t a = (uint32_t)(uintptr_t)p;
    if (g_free_calls < 8) g_free_args[g_free_calls] = a;
    ++g_free_calls;
    (void)g_free_hit_table;
}

void dlpv_stub(void *p) __asm__("_ZdlPv");
void dlpv_stub(void *p) { (void)p; ++g_del_calls; }

void *d2_stub(void *p) __asm__("_ZN15CSkeletonSpriteD2Ev");
void *d2_stub(void *p) { ++g_d2_calls; return p; }

void swf_stub(CSprite *s) __asm__("_ZN7CSprite12ClearSWFDataEv");
void swf_stub(CSprite *s) { (void)s; ++g_swf_calls; }

void ftex_stub(CSprite *s) __asm__("_ZN7CSprite11FreeTextureEv");
void ftex_stub(CSprite *s) { (void)s; ++g_ftex_calls; }

/* FreeMask 的合同尾部（Clear 卡 §0x1e6c58）：0x40=0、0x3c=0、0x31=0。
 * 真正的释放树不在这里建模；只保证这三个收尾写与卡一致，避免链路上出现
 * 「替身没写 → 断言以为 Clear 写了」的假象。 */
void fmask_stub(CSprite *s) __asm__("_ZN7CSprite8FreeMaskEv");
void fmask_stub(CSprite *s)
{
    ++g_fmask_calls;
    s->mask_rows = 0;
    s->mask_count = 0;
    s->has_mask = 0;
}

/* ── 夹具 ─────────────────────────────────────────────────────────────── */
#define IMG_SIZE 1024
static unsigned char *g_img;

static void wr32(unsigned off, uint32_t v) { memcpy(g_img + off, &v, 4); }
static YYSprite *yy(void) { return (YYSprite *)g_img; }
static uint32_t table_at(const CSprite *s, unsigned i)
{
    return *(const uint32_t *)(uintptr_t)(uint32_t)(s->local_tpe + i * 4u);
}

static void reset(const char *name)
{
    g_case = name;
    g_fail = 0;
    g_free_calls = g_fmask_calls = g_ftex_calls = g_swf_calls = 0;
    g_d2_calls = g_del_calls = 0;
    td_fixture_reset();
    g_img = (unsigned char *)td_fixture_alloc(IMG_SIZE);
    td_reset();
    if (!g_img) { c_puts("FATAL arena\n"); c_exit(91); }
    for (int i = 0; i < IMG_SIZE; ++i) g_img[i] = 0xEE;
    g_pWADBaseAddress = g_img;
    g_isZeus = 0;
}

static void done(void)
{
    if (g_fail) { c_puts("FAIL  "); g_fail = 1; } else { c_puts("PASS  "); }
    c_puts(g_case);
    c_puts("\n");
}

/* ── C1：Load → 检查落位（Clear 走的是真实译文）────────────────────────── */
static CSprite *g_s;

static void c1(void)
{
    reset("C1 load with real Clear");
    /* 模拟 operator new(136) 的零填充 + ctor 的默认值：+0x35 = 1、0x6c = 30.0f */
    g_s = (CSprite *)td_fixture_alloc(sizeof(CSprite));
    memset(g_s, 0, sizeof(*g_s));
    g_s->flag_35 = 1;
    { uint32_t bits = 0x41F00000u; memcpy(&g_s->field_6c, &bits, 4); }

    yy()->textureCount = 3;
    yy()->width = 32; yy()->height = 48;
    yy()->bboxLeft = 1; yy()->bboxRight = 2; yy()->bboxBottom = 3; yy()->bboxTop = 4;
    yy()->transparent = 1; yy()->smooth = 1; yy()->preload = 1;
    yy()->bboxMode = 2; yy()->sepMasks = 1;
    yy()->originX = 8; yy()->originY = 12;
    wr32(0x3c, 0x100); wr32(0x40, 0x200); wr32(0x44, 0x300);
    wr32(0x48, 3); wr32(0x4c, 0);

    CHECK_EQ(CSprite_LoadFromChunk(g_s, yy(), g_img), 1);
    CHECK_EQ(g_s->frame_count, 3);
    CHECK_EQ(g_s->width, 32);
    CHECK_EQ(g_s->height, 48);
    CHECK_EQ(g_s->field_24, 8);
    CHECK_EQ(g_s->field_28, 12);
    CHECK_EQ(g_s->type, 0);
    CHECK_EQ(table_at(g_s, 0), (uint32_t)(uintptr_t)g_img + 0x100);
    CHECK_EQ(table_at(g_s, 2), (uint32_t)(uintptr_t)g_img + 0x300);
    CHECK_EQ(g_s->field_64, 3);
    CHECK_EQ(g_s->flag_35, 1);
    CHECK_EQ(g_s->field_2c, 44);
    /* 真实 Clear 的副作用可见：它把 0x6c 清了吗？不——Clear 不写 0x6c。
     * 所以 ctor 的 30.0f 必须还在（这就是两条候选交接时的一个真实约束）。 */
    { uint32_t bits; memcpy(&bits, &g_s->field_6c, 4); CHECK_EQ(bits, 0x41F00000u); }
    /* Clear 释放了 0x48/0x50（本对象都是 0 ⇒ 释放 NULL），不应释放刚分配的表 */
    CHECK_EQ(g_fmask_calls, 1);
    CHECK_EQ(g_ftex_calls, 1);
    CHECK_EQ(g_swf_calls, 0);       /* type==0，不走 ClearSWFData */
    CHECK_EQ(g_d2_calls, 0);        /* 没有骨骼对象 */
    CHECK_EQ(g_del_calls, 0);
    done();
}

/* ── C2：真实 Clear 接手（同一对象、同一类型）───────────────────────────── */
static void c2(void)
{
    uint32_t table;
    reset("C2 real Clear after load");
    g_s = (CSprite *)td_fixture_alloc(sizeof(CSprite));
    memset(g_s, 0, sizeof(*g_s));
    g_s->flag_35 = 1;
    yy()->textureCount = 2;
    yy()->width = 10; yy()->height = 10; yy()->originX = 0; yy()->originY = 0;
    wr32(0x3c, 0x100); wr32(0x40, 0x200); wr32(0x44, 0);     /* maskCount=0 */
    (void)CSprite_LoadFromChunk(g_s, yy(), g_img);
    table = g_s->local_tpe;
    CHECK(table != 0);
    CHECK_EQ(g_s->field_64, 0);

    g_free_calls = 0;
    CSprite_Clear(g_s);                       /* ← 真实译文（stage 里的 csprite_clear.c） */

    CHECK_EQ(g_s->frame_count, 0);
    CHECK_EQ(g_s->width, 1);
    CHECK_EQ(g_s->height, 1);
    CHECK_EQ(g_s->type, 0);
    CHECK_EQ(g_s->local_tpe, 0);
    CHECK_EQ(g_s->field_24, 0);
    CHECK_EQ(g_s->field_28, 0);
    CHECK_EQ(g_s->flag_30, 1);
    CHECK_EQ(g_s->flag_32, 1);
    CHECK_EQ(g_s->flag_33, 0);
    CHECK_EQ(g_s->flag_34, 1);
    /* ★ 已知的所有权缺口（静态可读、这里被链路实测确认）：
     *   LoadFromChunk 往 +0x54 放了 new[] 的表，但**从不置 +0x36**；
     *   Clear 只在 +0x36 != 0 时释放 +0x54 —— 于是这张表被泄漏，
     *   而且 Clear 无条件把 +0x54 清 0（0x1e6c40）。 */
    {
        int freed_table = 0;
        for (int i = 0; i < g_free_calls && i < 8; ++i)
            if (g_free_args[i] == table) freed_table = 1;
        CHECK_EQ(freed_table, 0);
    }
    done();
}

/* ── C3：同一对象再 Load 一次（Clear 在入口先跑）────────────────────────── */
static void c3(void)
{
    reset("C3 reload after real Clear");
    g_s = (CSprite *)td_fixture_alloc(sizeof(CSprite));
    memset(g_s, 0, sizeof(*g_s));
    yy()->textureCount = 4;
    yy()->width = 1; yy()->height = 2; yy()->originX = 0; yy()->originY = 0;
    wr32(0x3c, 0x40); wr32(0x40, 0x44); wr32(0x44, 0x48); wr32(0x48, 0x4c);
    wr32(0x4c, 4);                           /* maskCount = 4 == count */
    (void)CSprite_LoadFromChunk(g_s, yy(), g_img);
    CHECK_EQ(g_s->frame_count, 4);
    CHECK_EQ(g_s->flag_35, 1);               /* 4 == 4 */

    yy()->textureCount = 1;
    yy()->width = 64; yy()->height = 80; yy()->originX = 3; yy()->originY = 4;
    wr32(0x3c, 0x300);
    wr32(0x40, 0);                           /* maskCount = 0 */
    (void)CSprite_LoadFromChunk(g_s, yy(), g_img);
    CHECK_EQ(g_s->frame_count, 1);
    CHECK_EQ(g_s->width, 64);
    CHECK_EQ(g_s->height, 80);
    CHECK_EQ(g_s->field_24, 3);
    CHECK_EQ(g_s->field_64, 0);
    CHECK_EQ(table_at(g_s, 0), (uint32_t)(uintptr_t)g_img + 0x300);
    done();
}

int main(void)
{
    int fails = 0;
    c1(); if (g_fail) ++fails;
    c2(); if (g_fail) ++fails;
    c3(); if (g_fail) ++fails;
    c_puts("chain summary: ");
    c_putint(3 - fails); c_puts(" passed, ");
    c_putint(fails); c_puts(" failed, ");
    c_putint(g_checks); c_puts(" checks\n");
    return fails;
}

#if defined(HARNESS_FREESTANDING)
void _start(void) { c_exit(main()); }
#endif
