/* fixture_clear_swf.c — CSprite::ClearSWFData 的合成夹具（无原件、无 ART、无 Unicorn）
 *
 * 手法：用一台 bump 分配器在 4 GiB 以下造出“按本函数实际 ldr 偏移解释”的 SWF
 * 对象图，把 MemoryManager::Free / GR_Texture_Free 换成记录型替身，然后断言
 *   1) 释放调用序列（含顺序、次数、NULL 门）；
 *   2) 纹理 id 序列与顺序；
 *   3) 三个字段（0x7c/0x80/0x84）的终值；
 *   4) CSprite 其余字节一个都不许动（快照比对）。
 *
 * 具名退出码：断言失败 → 打印 "FAIL <测试名> @ <断言>" 并以该测试序号退出
 * （1..10）。崩溃不算 kill；本夹具不依赖任何越界访问来“测出”差异。
 *
 * 变异体通过 -DCLEAR_SWF_MUTANT=n 编进译文：
 *   1 = dictionary 数组/计数提到循环外（语义变异，安全）
 *   2 = 容器条目数组基址提到循环外（语义变异，安全）
 *   3 = 尾部两个零写交换顺序（no-op，必须全部通过）
 */
#include "fx.h"
#include "csprite_clear.h"

extern void *memcpy(void *dst, const void *src, size_t n);
extern void *memset(void *dst, int c, size_t n);

#define MAXLOG 256

static uint32_t g_free[MAXLOG];
static int      g_nfree;
static int      g_tex[64];
static int      g_ntex;
static void   (*g_hook)(int nth, uint32_t addr);
static CSprite *g_self;

/* ---- 外部依赖替身：只记录，不真的释放；不触碰被释放内存，变异体不会崩 ---- */
void MemoryManager_Free(const void *p)
{
    int nth = g_nfree;
    if (g_nfree < MAXLOG)
        g_free[g_nfree++] = (uint32_t)(uintptr_t)p;
    if (g_hook)
        g_hook(nth, (uint32_t)(uintptr_t)p);
}

void GR_Texture_Free(int id) __asm__("_Z15GR_Texture_Freei");
void GR_Texture_Free(int id)
{
    if (g_ntex < 64)
        g_tex[g_ntex++] = id;
}

/* ---- 断言脚手架 ---- */
static const char *g_name;

static void put_u32(uint32_t v)
{
    /* 十六进制：只需要移位，避免 armv7-a 上的 __aeabi_uidiv 依赖 */
    char b[11];
    b[0] = '0'; b[1] = 'x';
    for (int i = 0; i < 8; ++i) {
        uint32_t nib = (v >> (uint32_t)(28 - i * 4)) & 0xfu;
        b[2 + i] = (char)(nib < 10u ? ('0' + nib) : ('a' + (nib - 10u)));
    }
    b[10] = 0;
    fx_puts(b);
}

static void begin(const char *name)
{
    g_name = name;
    g_nfree = 0;
    g_ntex = 0;
    g_hook = 0;
    g_self = 0;
}

static void fail(int code, const char *msg)
{
    fx_puts("FAIL ");
    fx_puts(g_name);
    fx_puts(" @ ");
    fx_puts(msg);
    fx_puts("\n");
    fx_exit(code);
}

#define CHK(code, cond, msg) do { if (!(cond)) fail(code, msg); } while (0)

static void pass(void)
{
    fx_puts("PASS ");
    fx_puts(g_name);
    fx_puts("\n");
}

/* ---- 图构造 ---- */
static uint32_t new_obj(uint32_t tag)      { uint32_t o = fx_alloc(0x60); fx_w32(o, tag); return o; }
static uint32_t new_slots(int n)           { return fx_alloc((uint32_t)n * 4u); }
static uint32_t new_ents(int n)            { return fx_alloc((uint32_t)n * 24u); }
static uint32_t new_recs(int n)            { return fx_alloc((uint32_t)n * 84u); }

static int frees_eq(const uint32_t *exp, int n)
{
    if (g_nfree != n) return 0;
    for (int i = 0; i < n; ++i)
        if (g_free[i] != exp[i]) return 0;
    return 1;
}

static void frees_report(const uint32_t *exp, int n)
{
    fx_puts("FAIL ");
    fx_puts(g_name);
    fx_puts(" @ free sequence: expected ");
    put_u32((uint32_t)n);
    fx_puts(" got ");
    put_u32((uint32_t)g_nfree);
    fx_puts("\n");
    for (int i = 0; i < g_nfree; ++i) {
        fx_puts("  free[");
        put_u32((uint32_t)i);
        fx_puts("] = ");
        put_u32(g_free[i]);
        if (i < n) { fx_puts(" expect "); put_u32(exp[i]); }
        fx_puts("\n");
    }
}

#define CHK_FREES(code, exp, n) do { if (!frees_eq((exp), (n))) { frees_report((exp), (n)); fx_exit(code); } } while (0)

/* 除 0x7c..0x87 之外的字节必须与快照一致 */
static uint8_t g_before[sizeof(CSprite)];
static void snap(const CSprite *s) { memcpy(g_before, s, sizeof *s); }
static int stray(const CSprite *s)
{
    const uint8_t *b = (const uint8_t *)s;
    for (size_t i = 0; i < sizeof(CSprite); ++i) {
        if (i >= 0x7c && i < 0x88) continue;
        if (b[i] != g_before[i]) return (int)i + 1;
    }
    return 0;
}

static void sprite_init(CSprite *s, uint32_t objs, int32_t cnt, uint32_t dict)
{
    memset(s, 0x5A, sizeof *s);
    s->swf_objects      = objs;
    s->swf_object_count = cnt;
    s->swf_dictionary   = dict;
}

/* =========================== 测试 =========================== */

/* t1：0x7c==0 → 直接跳到 dictionary；0x80 的脏值必须原样保留 */
static void t1(void)
{
    begin("t1 null_objects_early_out");
    static CSprite s;
    sprite_init(&s, 0, 7, 0);
    snap(&s);
    CSprite_ClearSWFData(&s);
    CHK(1, g_nfree == 0, "expected no Free call");
    CHK(1, s.swf_objects == 0, "0x7c must stay 0");
    CHK(1, s.swf_object_count == 7, "0x80 must NOT be cleared on early-out");
    CHK(1, stray(&s) == 0, "stray write outside 0x7c/0x80/0x84");
    pass();
}

/* t2：count<=0（有符号 ble）→ 只释放数组，然后 zero 两字段 */
static void t2(void)
{
    begin("t2 nonpositive_count_frees_array_only");
    static CSprite s;
    uint32_t arr = new_slots(2);
    fx_w32(arr, 0x11111111u);
    fx_w32(arr + 4, 0x22222222u);

    for (int round = 0; round < 2; ++round) {
        int32_t cnt = (round == 0) ? 0 : -3;
        g_nfree = 0; g_ntex = 0;
        sprite_init(&s, arr, cnt, 0);
        snap(&s);
        CSprite_ClearSWFData(&s);
        { const uint32_t exp[1] = { arr };
          CHK(2, frees_eq(exp, 1), "count<=0 must free array exactly once"); }
        CHK(2, g_ntex == 0, "no texture free on this path");
        CHK(2, s.swf_objects == 0 && s.swf_object_count == 0, "0x7c/0x80 zeroed");
        CHK(2, stray(&s) == 0, "stray write");
    }
    pass();
}

/* t3：tag==1 全图：7 指针记录 → 条目 → 元素(tag2: +0x50 & 纹理) → 元素数组 →
 *     单指针 → 空条目 → 条目数组 → obj → 对象数组 */
static void t3(void)
{
    begin("t3 tag1_full_graph");
    static CSprite s;

    uint32_t recs = new_recs(2);
    uint32_t p[7];
    for (int k = 0; k < 7; ++k) { p[k] = fx_alloc(8); fx_w32(recs + (uint32_t)k * 4u, p[k]); }
    /* recs[1] 全 0：验证 if(!=0) 门 */

    uint32_t p50  = fx_alloc(8);
    uint32_t elem0 = new_obj(2);
    fx_w32(elem0 + 0x50, p50);
    fx_w32(elem0 + 0x54, 7);
    uint32_t elem1 = new_obj(0);
    uint32_t sub2  = new_slots(2);
    fx_w32(sub2, elem0);
    fx_w32(sub2 + 4, elem1);

    uint32_t one = fx_alloc(8);
    uint32_t ents = new_ents(2);
    fx_w32(ents + 0,  recs);
    fx_w32(ents + 0x0c, 2);
    fx_w32(ents + 4,  sub2);
    fx_w32(ents + 0x10, 2);
    fx_w32(ents + 8,  one);
    /* 第二个条目 24 字节全 0：记录数 0 → 直接 Free(条目) */

    uint32_t obj = new_obj(1);
    fx_w32(obj + 0x08, ents);
    fx_w32(obj + 0x1c, 2);

    uint32_t objs = new_slots(1);
    fx_w32(objs, obj);

    sprite_init(&s, objs, 1, 0);
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = {
        p[0], p[1], p[2], p[3], p[4], p[5], p[6],
        recs,                 /* 0x1e69f0：条目本体 = 记录数组基址 */
        p50,                  /* 0x1e6a54：elem+0x50 */
        elem0,                /* 0x1e6a18 */
        elem1,                /* 0x1e6a18 */
        sub2,                 /* 0x1e6a6c */
        one,                  /* 0x1e6a7c */
        /* 第二个条目 +0x00 为 0：ent==0，整块跳过，不产生任何 Free */
        ents,                 /* 0x1e6a98：条目数组 */
        obj,                  /* 0x1e68e8 */
        objs                  /* 0x1e6aa0：对象数组 */
    };
    CHK_FREES(3, exp, (int)(sizeof exp / sizeof exp[0]));
    CHK(3, g_ntex == 1 && g_tex[0] == 7, "exactly one GR_Texture_Free(7)");
    CHK(3, s.swf_objects == 0 && s.swf_object_count == 0 && s.swf_dictionary == 0, "fields");
    CHK(3, stray(&s) == 0, "stray write");
    pass();
}

/* t4：tag==2 → GR_Texture_Free(obj+8) 先于 Free(obj)，无 NULL 门 */
static void t4(void)
{
    begin("t4 tag2_texture_then_object");
    static CSprite s;
    uint32_t obj = new_obj(2);
    fx_w32(obj + 0x08, 5);
    uint32_t objs = new_slots(1);
    fx_w32(objs, obj);

    sprite_init(&s, objs, 1, 0);
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { obj, objs };
    CHK_FREES(4, exp, 2);
    CHK(4, g_ntex == 1 && g_tex[0] == 5, "GR_Texture_Free(5)");
    CHK(4, stray(&s) == 0, "stray write");
    pass();
}

/* t5：tag 既非 1 也非 2 → 只 Free(obj) */
static void t5(void)
{
    begin("t5 tag_other_plain_free");
    static CSprite s;
    uint32_t obj = new_obj(0);
    fx_w32(obj + 0x08, 0x33333333u);   /* 非 tag1/2 时 +8 不被当纹理 id 解释 */
    uint32_t objs = new_slots(1);
    fx_w32(objs, obj);

    sprite_init(&s, objs, 1, 0);
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { obj, objs };
    CHK_FREES(5, exp, 2);
    CHK(5, g_ntex == 0, "no texture free for tag 0");
    CHK(5, stray(&s) == 0, "stray write");
    pass();
}

/* t6：tag==1 但 obj+8==0 → 不释放数组，只 Free(obj)（0x80 的脏值仍被清零） */
static void t6(void)
{
    begin("t6 tag1_null_array");
    static CSprite s;
    uint32_t obj = new_obj(1);
    fx_w32(obj + 0x1c, 5);
    uint32_t objs = new_slots(1);
    fx_w32(objs, obj);

    sprite_init(&s, objs, 1, 0);
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { obj, objs };
    CHK_FREES(6, exp, 2);
    CHK(6, s.swf_objects == 0 && s.swf_object_count == 0, "0x7c/0x80 zeroed");
    CHK(6, stray(&s) == 0, "stray write");
    pass();
}

/* t7：对象数组的基址/计数在 Free 之后重读（回调把 base 换掉、计数改成 1） */
static uint32_t g_t7_alt;

static void t7_hook2(int nth, uint32_t addr)
{
    (void)addr;
    if (nth == 0) {
        g_self->swf_objects      = g_t7_alt;
        g_self->swf_object_count = 1;
    }
}

static void t7(void)
{
    begin("t7 object_array_reread");
    static CSprite s;
    uint32_t a = new_obj(0);
    uint32_t b = new_obj(0);
    uint32_t arr  = new_slots(2);
    fx_w32(arr, a);
    fx_w32(arr + 4, b);
    uint32_t alt_obj = new_obj(0);
    g_t7_alt = new_slots(1);
    fx_w32(g_t7_alt, alt_obj);

    sprite_init(&s, arr, 2, 0);
    g_self = &s;
    g_hook = t7_hook2;
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { a, g_t7_alt };
    CHK_FREES(7, exp, 2);
    CHK(7, s.swf_objects == 0 && s.swf_object_count == 0, "0x7c/0x80 zeroed");
    pass();
}

/* t8：容器条目循环里，条目数组基址与计数在外调后重读 */
static uint32_t g_t8_alt_ents;
static uint32_t g_t8_obj;

static void t8_hook(int nth, uint32_t addr)
{
    (void)addr;
    if (nth == 0) {                       /* 第一个记录指针释放后改写容器 */
        fx_w32(g_t8_obj + 0x08, g_t8_alt_ents);
        fx_w32(g_t8_obj + 0x1c, 1);
    }
}

static void t8(void)
{
    begin("t8 container_array_reread");
    static CSprite s;
    uint32_t recs = new_recs(1);
    uint32_t p0 = fx_alloc(8);
    fx_w32(recs, p0);
    uint32_t ents = new_ents(2);
    fx_w32(ents + 0, recs);
    fx_w32(ents + 0x0c, 1);
    /* 第二个条目：有记录数组但计数 1，触发第二轮 */
    uint32_t recs2 = new_recs(1);
    fx_w32(recs2, fx_alloc(8));
    fx_w32(ents + 24 + 0, recs2);
    fx_w32(ents + 24 + 0x0c, 1);

    g_t8_alt_ents = new_ents(1);          /* 回调换上的“新条目数组”，全 0 */

    g_t8_obj = new_obj(1);
    fx_w32(g_t8_obj + 0x08, ents);
    fx_w32(g_t8_obj + 0x1c, 2);
    uint32_t objs = new_slots(1);
    fx_w32(objs, g_t8_obj);

    sprite_init(&s, objs, 1, 0);
    g_self = &s;
    g_hook = t8_hook;
    snap(&s);
    CSprite_ClearSWFData(&s);

    /* 原语义：只处理第一条目（计数被改成 1），最后释放的是新数组基址 */
    const uint32_t exp[] = {
        p0,
        recs,                /* 0x1e69f0：条目本体 = 记录数组基址 */
        g_t8_alt_ents,       /* 0x1e6a98：重读后的条目数组基址 */
        g_t8_obj, objs
    };
    CHK_FREES(8, exp, 5);
    CHK(8, s.swf_objects == 0 && s.swf_object_count == 0, "0x7c/0x80 zeroed");
    pass();
}

/* t9：dictionary 条目循环里，数组基址与计数在外调后重读 */
static uint32_t g_t9_dict, g_t9_alt;

static void t9_hook(int nth, uint32_t addr)
{
    (void)addr;
    if (nth == 0) {
        fx_w32(g_t9_dict + 0x00, g_t9_alt);
        fx_w32(g_t9_dict + 0x18, 1);
    }
}

static void t9(void)
{
    begin("t9 dict_reread");
    static CSprite s;
    uint32_t p0 = fx_alloc(8), p1 = fx_alloc(8);
    uint32_t darr = fx_alloc(2 * 24);
    fx_w32(darr + 0, p0);
    fx_w32(darr + 24, p1);

    g_t9_alt = fx_alloc(24);
    uint32_t p2 = fx_alloc(8);
    fx_w32(g_t9_alt, p2);

    g_t9_dict = fx_alloc(0x20);
    fx_w32(g_t9_dict + 0x00, darr);
    fx_w32(g_t9_dict + 0x18, 2);

    sprite_init(&s, 0, 0, g_t9_dict);
    g_self = &s;
    g_hook = t9_hook;
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { p0, g_t9_alt, g_t9_dict };
    CHK_FREES(9, exp, 3);
    CHK(9, s.swf_dictionary == 0, "0x84 zeroed");
    CHK(9, stray(&s) == 0, "stray write");
    pass();
}

/* t10：dictionary 有对象但条目数组为 0 → 只 Free(dict)，0x84 清 0 */
static void t10(void)
{
    begin("t10 dict_null_array");
    static CSprite s;
    uint32_t dict = fx_alloc(0x20);
    fx_w32(dict + 0x18, 9);
    sprite_init(&s, 0, 0, dict);
    snap(&s);
    CSprite_ClearSWFData(&s);

    const uint32_t exp[] = { dict };
    CHK_FREES(10, exp, 1);
    CHK(10, s.swf_dictionary == 0, "0x84 zeroed");
    CHK(10, stray(&s) == 0, "stray write");
    pass();
}

/* Parent regressions are driven by the original beq/Free sites. */
static void t11(void)
{
    begin("t11 zero_records_free_base");
    static CSprite s;
    uint32_t rec = new_recs(1), ents = new_ents(1), obj = new_obj(1), objs = new_slots(1);
    fx_w32(ents, rec); fx_w32(ents + 0x0c, 0);
    fx_w32(obj + 8, ents); fx_w32(obj + 0x1c, 1); fx_w32(objs, obj);
    sprite_init(&s, objs, 1, 0);
    CSprite_ClearSWFData(&s);
    const uint32_t exp[] = {rec, ents, obj, objs};
    CHK_FREES(11, exp, 4);
    pass();
}
static uint32_t g_t12_obj, g_t12_one;
static void t12_hook(int nth, uint32_t addr)
{
    (void)nth;
    if (addr == g_t12_one) fx_w32(g_t12_obj + 0x1c, 0);
}
static void t12(void)
{
    begin("t12 negative_container_count");
    static CSprite s;
    uint32_t ents = new_ents(1), objs = new_slots(1);
    g_t12_obj = new_obj(1); g_t12_one = fx_alloc(8);
    fx_w32(ents + 8, g_t12_one); fx_w32(g_t12_obj + 8, ents);
    fx_w32(g_t12_obj + 0x1c, 0xffffffffu); fx_w32(objs, g_t12_obj);
    sprite_init(&s, objs, 1, 0); g_hook = t12_hook;
    CSprite_ClearSWFData(&s);
    const uint32_t exp[] = {g_t12_one, ents, g_t12_obj, objs};
    CHK_FREES(12, exp, 4);
    pass();
}

int fx_main(void)
{
    if (fx_map_arena() != 0) {
        fx_puts("FAIL arena must map below 4GiB\n");
        fx_exit(90);
    }
#if defined(TEST_T12)
    t12();
#else
    t1(); t2(); t3(); t4(); t5(); t6(); t7(); t8(); t9(); t10();
    t11(); t12();
#endif
    fx_puts("ALL OK\n");
    return 0;
}

#ifdef FX_FREESTANDING
void _start(void) { fx_exit(fx_main()); }
#else
int main(void) { return fx_main(); }
#endif
