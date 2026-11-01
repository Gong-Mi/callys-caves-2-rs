/* free_resources_tests.c — FreeMask / FreeTexture 的纯合成夹具
 *
 * 只链接译文 + 替身：不加载 libyoyo_armv7.so，不执行原件，不使用 ART/Unicorn。
 * 替身是真实符号 _ZN13MemoryManager4FreeEPKv 与 _Z15GR_Texture_Freei，
 * 记录调用参数并可在“外调进行中”注入字段改写，用来观测译文是否按原件重读。
 *
 * 地址模型：CSprite 字段是 uint32_t（ARM32 指针宽度）。为了让 64 位 host 上的
 * 指针往返不被截断，所有被 CSprite 引用的表都从一块 <4GiB 的 mmap 池里分配。
 * 这不是原件分配器，只是让 offset/解引用语义在 host 上可执行。
 *
 * 退出码：0 = PASS；20 = 具名断言失败（stderr: ASSERT_FAIL:<test>:<check>:...）；
 *         21 = 夹具用法/内部错误。
 */
#include "csprite_clear.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

/* GR_Texture_Free 不在共享头里；与译文使用同一 mangled 绑定。 */
void GR_Texture_Free(int id) __asm__("_Z15GR_Texture_Freei");

#define MAXC 16
#define FAKE_BASE ((void *)(uintptr_t)0x20000000u)
#define FAKE_SIZE 0x10000u

#ifndef MAP_FIXED_NOREPLACE
#define MAP_FIXED_NOREPLACE 0x100000
#endif

static unsigned char *g_pool;
static size_t g_pool_used;

static void pool_init(void)
{
    if (!g_pool) {
        void *p = mmap(FAKE_BASE, FAKE_SIZE, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE,
                       -1, 0);
        if (p == MAP_FAILED) {
            p = mmap(FAKE_BASE, FAKE_SIZE, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        }
        if (p == MAP_FAILED || (uintptr_t)p > 0xffffffffu) {
            fprintf(stderr, "ASSERT_FAIL:setup:FAKE_POOL_ADDR\n");
            exit(21);
        }
        g_pool = p;
    }
    memset(g_pool, 0, FAKE_SIZE);
    g_pool_used = 0;
}

static void *fake_alloc(size_t n)
{
    n = (n + 15u) & ~(size_t)15u;
    if (g_pool_used + n > FAKE_SIZE) {
        fprintf(stderr, "ASSERT_FAIL:setup:FAKE_POOL_OVF\n");
        exit(21);
    }
    void *p = g_pool + g_pool_used;
    g_pool_used += n;
    return p;
}

static uint32_t ptr32(const void *p)
{
    uintptr_t v = (uintptr_t)p;
    if (v > 0xffffffffu) {
        fprintf(stderr, "ASSERT_FAIL:setup:PTR_TRUNCATED\n");
        exit(21);
    }
    return (uint32_t)v;
}

static const void *g_mfree[MAXC];
static int g_nmfree;
static int g_gfree[MAXC];
static int g_ngfree;

static void (*g_mhook)(int idx);
static void (*g_ghook)(int idx);
static CSprite *g_self;
static const char *g_test = "?";

static void failf(const char *id, const char *fmt, ...)
{
    va_list ap;
    fprintf(stderr, "ASSERT_FAIL:%s:%s:", g_test, id);
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fputc('\n', stderr);
    exit(20);
}

#define CHECK(cond, id) \
    do { if (!(cond)) failf((id), "%s", #cond); } while (0)

#define CHECK_EQ(id, got, want) \
    do { \
        unsigned long long g_ = (unsigned long long)(got); \
        unsigned long long w_ = (unsigned long long)(want); \
        if (g_ != w_) failf((id), "got=%llu want=%llu", g_, w_); \
    } while (0)

/* ---- 外部依赖替身（真实 mangled 名，由链接器绑定） ---- */

void MemoryManager_Free(const void *p)
{
    int i = g_nmfree++;
    if (i < MAXC) {
        g_mfree[i] = p;
    }
    if (g_mhook) {
        g_mhook(i);
    }
}

void GR_Texture_Free(int id)
{
    int i = g_ngfree++;
    if (i < MAXC) {
        g_gfree[i] = id;
    }
    if (g_ghook) {
        g_ghook(i);
    }
}

static void setup(CSprite *s)
{
    pool_init();
    memset(s, 0, sizeof *s);
    memset(g_mfree, 0, sizeof g_mfree);
    memset(g_gfree, 0, sizeof g_gfree);
    g_nmfree = 0;
    g_ngfree = 0;
    g_mhook = NULL;
    g_ghook = NULL;
    g_self = s;
}

/* ---- FreeMask ---- */

/* 门关闭：一个字节都不写，也不外调。 */
static void t_fm_hasmask0_noop(void)
{
    CSprite s;
    setup(&s);
    uint32_t *rows = fake_alloc(8);
    s.has_mask = 0;
    s.mask_count = 3;
    s.mask_rows = ptr32(rows);

    CSprite_FreeMask(&s);

    CHECK_EQ("FM_NOOP_CALLS", g_nmfree, 0);
    CHECK_EQ("FM_NOOP_ROWS", s.mask_rows, ptr32(rows));
    CHECK_EQ("FM_NOOP_COUNT", s.mask_count, 3);
    CHECK_EQ("FM_NOOP_GATE", s.has_mask, 0);
}

static uint32_t *t2_rows;

static void t2_hook(int idx)
{
    if (idx == 0) {
        CHECK_EQ("FM_ORDER_FIRST_PTR", (uintptr_t)g_mfree[0], 0x1000u);
        /* 行数据 Free 进行中：本行两字还没清零，门/计数/表指针都还没清。 */
        CHECK_EQ("FM_ORDER_CLEAR_AFTER_FREE", t2_rows[1], 0x1000u);
        CHECK_EQ("FM_ORDER_SIZE_ALIVE", t2_rows[0], 0xAAu);
        CHECK_EQ("FM_ORDER_GATE_ALIVE", g_self->has_mask, 1);
    }
    if (idx == 1) {
        CHECK_EQ("FM_ORDER_NULL_FREED", (uintptr_t)g_mfree[1], 0u);
        CHECK_EQ("FM_ORDER_PREV_ROW_ZEROED_LO", t2_rows[0], 0u);
        CHECK_EQ("FM_ORDER_PREV_ROW_ZEROED_HI", t2_rows[1], 0u);
        CHECK_EQ("FM_ORDER_NULL_ROW_SIZE_ALIVE", t2_rows[2], 0xBBu);
    }
    if (idx == 2) {
        CHECK_EQ("FM_ORDER_THIRD_PTR", (uintptr_t)g_mfree[2], 0x3000u);
        /* NULL 行也必须在 Free 返回后清零。 */
        CHECK_EQ("FM_ORDER_NULL_ROW_ZEROED", t2_rows[2] | t2_rows[3], 0u);
        CHECK_EQ("FM_ORDER_LAST_ROW_ALIVE", t2_rows[5], 0x3000u);
    }
    if (idx == 3) {
        CHECK_EQ("FM_CLEAR_AFTER_BASE_PTR", (uintptr_t)g_mfree[3],
                 (uintptr_t)t2_rows);
        CHECK_EQ("FM_CLEAR_AFTER_BASE_ROWS",
                 t2_rows[0] | t2_rows[1] | t2_rows[2] | t2_rows[3] |
                 t2_rows[4] | t2_rows[5], 0u);
        /* 循环外 Free(rows) 期间：0x40/0x3c/0x31 尚未清零。 */
        CHECK_EQ("FM_CLEAR_AFTER_BASE_FIELD", g_self->mask_rows, ptr32(t2_rows));
        CHECK_EQ("FM_CLEAR_AFTER_BASE_COUNT", g_self->mask_count, 3);
        CHECK_EQ("FM_CLEAR_AFTER_BASE_GATE", g_self->has_mask, 1);
    }
}

/* 三个行：普通指针 / NULL 数据 / 普通指针；验证清零窗与外调顺序。 */
static void t_fm_order_null_entry(void)
{
    CSprite s;
    setup(&s);
    t2_rows = fake_alloc(6 * 4);
    t2_rows[0] = 0xAA;
    t2_rows[1] = 0x1000;
    t2_rows[2] = 0xBB;
    t2_rows[3] = 0;
    t2_rows[4] = 0xCC;
    t2_rows[5] = 0x3000;
    s.has_mask = 1;
    s.mask_count = 3;
    s.mask_rows = ptr32(t2_rows);
    g_mhook = t2_hook;

    CSprite_FreeMask(&s);

    CHECK_EQ("FM_ORDER_CALLS", g_nmfree, 4);
    CHECK_EQ("FM_ORDER_TOTAL_ROW0", t2_rows[0] | t2_rows[1], 0u);
    CHECK_EQ("FM_ORDER_TOTAL_ROW2", t2_rows[4] | t2_rows[5], 0u);
    CHECK_EQ("FM_FINAL_ROWS", s.mask_rows, 0);
    CHECK_EQ("FM_FINAL_COUNT", s.mask_count, 0);
    CHECK_EQ("FM_FINAL_GATE", s.has_mask, 0);
}

static uint32_t *t3_rows;

static void t3_hook(int idx)
{
    if (idx == 0) {
        g_self->mask_count = 1;   /* 回调把计数从 3 改成 1 */
    }
}

/* 外调后重读计数：第二轮起必须按新计数 1 收尾。 */
static void t_fm_count_reread_shrink(void)
{
    CSprite s;
    setup(&s);
    t3_rows = fake_alloc(6 * 4);
    t3_rows[0] = 1; t3_rows[1] = 0x1000;
    t3_rows[2] = 1; t3_rows[3] = 0x2000;
    t3_rows[4] = 1; t3_rows[5] = 0x3000;
    s.has_mask = 1;
    s.mask_count = 3;
    s.mask_rows = ptr32(t3_rows);
    g_mhook = t3_hook;

    CSprite_FreeMask(&s);

    CHECK_EQ("FM_COUNT_REREAD_CALLS", g_nmfree, 2);
    CHECK_EQ("FM_COUNT_REREAD_SECOND", (uintptr_t)g_mfree[1],
             (uintptr_t)t3_rows);
    CHECK_EQ("FM_COUNT_REREAD_UNTOUCHED_HI", t3_rows[3], 0x2000u);
    CHECK_EQ("FM_COUNT_REREAD_UNTOUCHED_LAST", t3_rows[5], 0x3000u);
    CHECK_EQ("FM_COUNT_REREAD_FINAL", s.mask_count, 0);
}

static uint32_t *t4_rows1;
static uint32_t *t4_rows2;

static void t4_hook(int idx)
{
    if (idx == 0) {
        g_self->mask_rows = ptr32(t4_rows2);  /* 换表 */
    }
}

/* 外调后重读行表基址：第二轮要按新表取指针、清零并释放新表。 */
static void t_fm_base_reread(void)
{
    CSprite s;
    setup(&s);
    t4_rows1 = fake_alloc(4 * 4);
    t4_rows2 = fake_alloc(4 * 4);
    t4_rows1[0] = 1; t4_rows1[1] = 0x1000;
    t4_rows1[2] = 1; t4_rows1[3] = 0x2000;
    t4_rows2[0] = 1; t4_rows2[1] = 0;
    t4_rows2[2] = 1; t4_rows2[3] = 0x3000;
    s.has_mask = 1;
    s.mask_count = 2;
    s.mask_rows = ptr32(t4_rows1);
    g_mhook = t4_hook;

    CSprite_FreeMask(&s);

    CHECK_EQ("FM_BASE_REREAD_CALLS", g_nmfree, 3);
    CHECK_EQ("FM_BASE_REREAD_SECOND", (uintptr_t)g_mfree[1], 0x3000u);
    CHECK_EQ("FM_BASE_REREAD_BASE", (uintptr_t)g_mfree[2],
             (uintptr_t)t4_rows2);
    CHECK_EQ("FM_BASE_REREAD_OLD_UNTOUCHED_LO", t4_rows1[1], 0x1000u);
    CHECK_EQ("FM_BASE_REREAD_OLD_UNTOUCHED_HI", t4_rows1[3], 0x2000u);
    CHECK_EQ("FM_BASE_REREAD_NEW_ZEROED",
             t4_rows2[0] | t4_rows2[1] | t4_rows2[2] | t4_rows2[3], 0u);
}

/* 负计数：不进行循环，但仍 Free(rows) 并清三字段。 */
static void t_fm_negative_count(void)
{
    CSprite s;
    setup(&s);
    uint32_t *rows = fake_alloc(2 * 4);
    rows[0] = 1;
    rows[1] = 0x1000;
    s.has_mask = 1;
    s.mask_count = -1;
    s.mask_rows = ptr32(rows);

    CSprite_FreeMask(&s);

    CHECK_EQ("FM_NEG_ONLY_BASE", g_nmfree, 1);
    CHECK_EQ("FM_NEG_BASE_PTR", (uintptr_t)g_mfree[0], (uintptr_t)rows);
    CHECK_EQ("FM_NEG_ROW_KEPT_LO", rows[0], 1u);
    CHECK_EQ("FM_NEG_ROW_KEPT_HI", rows[1], 0x1000u);
    CHECK_EQ("FM_NEG_FINAL_ROWS", s.mask_rows, 0);
    CHECK_EQ("FM_NEG_FINAL_COUNT", s.mask_count, 0);
    CHECK_EQ("FM_NEG_FINAL_GATE", s.has_mask, 0);
}

/* ---- FreeTexture ---- */

static void t_ft_zero_count_noop(void)
{
    CSprite s;
    setup(&s);
    int32_t *ids = fake_alloc(2 * 4);
    ids[0] = 7;
    ids[1] = 8;
    s.texture_count = 0;
    s.texture_ids = ptr32(ids);

    CSprite_FreeTexture(&s);

    CHECK_EQ("FT_ZERO_CALLS", g_ngfree, 0);
    CHECK_EQ("FT_ZERO_ID0", ids[0], 7);
    CHECK_EQ("FT_ZERO_ID1", ids[1], 8);
    CHECK_EQ("FT_ZERO_COUNT", s.texture_count, 0);
}

static int32_t *t7_ids;

static void t7_hook(int idx)
{
    if (idx == 0) {
        /* 0x50[i] = -1 必须发生在外调返回之后。 */
        CHECK_EQ("FT_ORDER_CLEAR_AFTER_FREE", t7_ids[1], 7);
        CHECK_EQ("FT_ORDER_COUNT_ALIVE", g_self->texture_count, 3);
        CHECK_EQ("FT_ORDER_SLOT0", t7_ids[0], -1);
    }
}

/* 负数 id 跳过、-1 写在外调之后、计数/表指针保全。 */
static void t_ft_order_skip(void)
{
    CSprite s;
    setup(&s);
    t7_ids = fake_alloc(3 * 4);
    t7_ids[0] = -1;
    t7_ids[1] = 7;
    t7_ids[2] = -2;
    s.texture_count = 3;
    s.texture_ids = ptr32(t7_ids);
    g_ghook = t7_hook;

    CSprite_FreeTexture(&s);

    CHECK_EQ("FT_ORDER_CALLS", g_ngfree, 1);
    CHECK_EQ("FT_ORDER_ID", g_gfree[0], 7);
    CHECK_EQ("FT_ORDER_FINAL0", t7_ids[0], -1);
    CHECK_EQ("FT_ORDER_FINAL1", t7_ids[1], -1);
    CHECK_EQ("FT_ORDER_FINAL2", t7_ids[2], -2);
    CHECK_EQ("FT_ORDER_FINAL_COUNT", s.texture_count, 3);
    CHECK_EQ("FT_ORDER_FINAL_PTR", s.texture_ids, ptr32(t7_ids));
}

static int32_t *t8_ids;

static void t8_hook(int idx)
{
    if (idx == 0) {
        g_self->texture_count = 1;   /* 回调把计数从 3 缩到 1 */
    }
}

/* 外调后重读计数：只处理第一槽。 */
static void t_ft_count_reread(void)
{
    CSprite s;
    setup(&s);
    t8_ids = fake_alloc(3 * 4);
    t8_ids[0] = 7;
    t8_ids[1] = 8;
    t8_ids[2] = 9;
    s.texture_count = 3;
    s.texture_ids = ptr32(t8_ids);
    g_ghook = t8_hook;

    CSprite_FreeTexture(&s);

    CHECK_EQ("FT_COUNT_REREAD_CALLS", g_ngfree, 1);
    CHECK_EQ("FT_COUNT_REREAD_ID", g_gfree[0], 7);
    CHECK_EQ("FT_COUNT_REREAD_SLOT0", t8_ids[0], -1);
    CHECK_EQ("FT_COUNT_REREAD_SLOT1", t8_ids[1], 8);
    CHECK_EQ("FT_COUNT_REREAD_SLOT2", t8_ids[2], 9);
    CHECK_EQ("FT_COUNT_REREAD_FIELD", s.texture_count, 1);
}

/* 0x1e570c pople: negative count returns without any texture access. */
static void t_ft_negative_count(void)
{
    CSprite s;
    setup(&s);
    int32_t *ids = fake_alloc(2 * 4);
    ids[0] = 7;
    ids[1] = 9;
    s.texture_count = -1;
    s.texture_ids = ptr32(ids);

    CSprite_FreeTexture(&s);

    CHECK_EQ("FT_NEG_NO_CALL", g_ngfree, 0);
    CHECK_EQ("FT_NEG_SLOT0", ids[0], 7);
    CHECK_EQ("FT_NEG_SLOT1", ids[1], 9);
    CHECK_EQ("FT_NEG_FIELD", s.texture_count, -1);
}

static int32_t *t10_ids1;
static int32_t *t10_ids2;

static void t10_hook(int idx)
{
    if (idx == 0) {
        g_self->texture_ids = ptr32(t10_ids2);  /* 换数组 */
    }
}

/* 外调后重读 id 数组基址：-1 写到新数组，第二轮按新数组继续。 */
static void t_ft_base_reread(void)
{
    CSprite s;
    setup(&s);
    t10_ids1 = fake_alloc(2 * 4);
    t10_ids2 = fake_alloc(2 * 4);
    t10_ids1[0] = 7;
    t10_ids1[1] = 8;
    t10_ids2[0] = 0x55;
    t10_ids2[1] = 9;
    s.texture_count = 2;
    s.texture_ids = ptr32(t10_ids1);
    g_ghook = t10_hook;

    CSprite_FreeTexture(&s);

    CHECK_EQ("FT_BASE_REREAD_CALLS", g_ngfree, 2);
    CHECK_EQ("FT_BASE_REREAD_IDS", g_gfree[0] | (g_gfree[1] << 8), 7 | (9 << 8));
    CHECK_EQ("FT_BASE_REREAD_OLD0", t10_ids1[0], 7);
    CHECK_EQ("FT_BASE_REREAD_OLD1", t10_ids1[1], 8);
    CHECK_EQ("FT_BASE_REREAD_NEW0", t10_ids2[0], -1);
    CHECK_EQ("FT_BASE_REREAD_NEW1", t10_ids2[1], -1);
    CHECK_EQ("FT_BASE_REREAD_COUNT", s.texture_count, 2);
}

/* ---- 注册表 ---- */

typedef struct {
    const char *name;
    void (*fn)(void);
} Test;

static const Test TESTS[] = {
    {"fm_hasmask0_noop",       t_fm_hasmask0_noop},
    {"fm_order_null_entry",    t_fm_order_null_entry},
    {"fm_count_reread_shrink", t_fm_count_reread_shrink},
    {"fm_base_reread",         t_fm_base_reread},
    {"fm_negative_count",      t_fm_negative_count},
    {"ft_zero_count_noop",     t_ft_zero_count_noop},
    {"ft_order_skip",          t_ft_order_skip},
    {"ft_count_reread",        t_ft_count_reread},
    {"ft_negative_count",      t_ft_negative_count},
    {"ft_base_reread",         t_ft_base_reread},
};

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "usage: %s <test-name>\n", argv[0]);
        return 21;
    }
    for (size_t i = 0; i < sizeof TESTS / sizeof TESTS[0]; i++) {
        if (strcmp(TESTS[i].name, argv[1]) == 0) {
            g_test = TESTS[i].name;
            TESTS[i].fn();
            printf("PASS:%s\n", TESTS[i].name);
            return 0;
        }
    }
    fprintf(stderr, "ASSERT_FAIL:registry:UNKNOWN_TEST:%s\n", argv[1]);
    return 21;
}
