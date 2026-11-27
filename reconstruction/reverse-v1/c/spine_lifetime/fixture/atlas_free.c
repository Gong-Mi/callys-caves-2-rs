/* fixture/atlas_free.c — spAtlas_dispose 的具名正例/安全语义负控夹具
 *
 * 无 libc：host 走 fx.h（mmap 低地址 + write），ARM32 走 fx.h 的静态 BSS + svc #0，
 * 运行期只由 arm32_support.c 提供 memcpy/memset/memmove。不含 printf/assert。
 *
 * 两种构建：
 *   -DYY_ATLAS_HELPERS_EXTERN  边界构建：spAtlasPage_dispose/spAtlasRegion_dispose
 *                              由夹具替身提供（NULL 安全 + 记录事件 + 按块表清零，
 *                              模拟"dispose 会释放/复用该节点"）。负控都在此构建跑。
 *   默认                       复原件构建：两个 helper 来自 atlas_dispose.c，
 *                              夹具只替 _free 与 _spAtlasPage_disposeTexture。
 *
 * 退出码：0 全 PASS；1 有具名 FAIL；90/91/92/93 夹具自身故障（arena/表溢出）。
 */
#include <stdint.h>
#include <stddef.h>
#include "fx.h"
#include "atlas_dispose.h"

#define MAXEV  64
#define MAXBLK 48

#define EV_PAGE   1u
#define EV_REGION 2u

#define RENDERER_SENTINEL 0x0BADF00Du

static uint32_t g_blk_a[MAXBLK], g_blk_n[MAXBLK];
static int      g_blk_c;

static uint32_t g_free[MAXEV], g_free_seq[MAXEV];
static int      g_free_n;
/* Shared monotonic clock across free and dispose observations. Separate logs
 * without this clock cannot prove that the container was freed last. */
static uint32_t g_sequence;

static int g_fail;

#ifdef YY_ATLAS_HELPERS_EXTERN
static uint32_t g_evk[MAXEV], g_evv[MAXEV], g_ev_seq[MAXEV];
static int      g_ev_n;
static uint32_t g_null_dispose;
#else
static uint32_t g_tex_calls;
#endif

static uint32_t g_atlasA, g_atlasB;
static uint32_t g_p[3], g_nm[3];
static uint32_t g_r[2], g_rn[2], g_rs[2], g_rp[2];

static void chk(int ok, const char *name)
{
    if (ok) fx_puts("[PASS] ");
    else { fx_puts("[FAIL] "); g_fail++; }
    fx_puts(name);
    fx_puts("\n");
}

static uint32_t ts_alloc(uint32_t n)
{
    uint32_t a = fx_alloc(n);
    if (g_blk_c >= MAXBLK) { fx_puts("FAIL block table overflow\n"); fx_exit(92); }
    g_blk_a[g_blk_c] = a;
    g_blk_n[g_blk_c] = n;
    g_blk_c++;
    return a;
}

static uint32_t ts_size(uint32_t a)
{
    int i;
    for (i = 0; i < g_blk_c; i++) if (g_blk_a[i] == a) return g_blk_n[i];
    return 0u;
}

/* 释放后清零（只清该块自己的字节数）：模型化"释放后字节不确定"，
 * 取 0 是为了让错误顺序以断言失败暴露，而不是让夹具崩溃。 */
static void ts_scrub(uint32_t a)
{
    uint32_t n = ts_size(a), i;
    volatile uint8_t *p = (volatile uint8_t *)(uintptr_t)a;
    for (i = 0; i < n; i++) p[i] = 0;
}

static void free_push(uint32_t a)
{
    if (g_free_n >= MAXEV) { fx_puts("FAIL free log overflow\n"); fx_exit(93); }
    g_free_seq[g_free_n] = ++g_sequence;
    g_free[g_free_n++] = a;
}

void _free(void *p)
{
    uint32_t a = (uint32_t)(uintptr_t)p;
    free_push(a);
    if (a != 0u) ts_scrub(a);
}

static int count_free(uint32_t a)
{
    int i, c = 0;
    for (i = 0; i < g_free_n; i++) if (g_free[i] == a) c++;
    return c;
}

#ifdef YY_ATLAS_HELPERS_EXTERN
static int count_ev(uint32_t k, uint32_t a)
{
    int i, c = 0;
    for (i = 0; i < g_ev_n; i++) if (g_evk[i] == k && g_evv[i] == a) c++;
    return c;
}

static void ev_push(uint32_t k, uint32_t a)
{
    if (g_ev_n >= MAXEV) { fx_puts("FAIL event log overflow\n"); fx_exit(93); }
    g_ev_seq[g_ev_n] = ++g_sequence;
    g_evk[g_ev_n] = k;
    g_evv[g_ev_n] = a;
    g_ev_n++;
}

/* 边界替身：原件里这两个 helper 会释放节点，所以这里按块表清零同一块；
 * NULL 不崩，只记账，好让"漏 NULL 预检"是具名断言而不是段错误。 */
void spAtlasPage_dispose(spAtlasPage *page)
{
    uint32_t a = (uint32_t)(uintptr_t)page;
    ev_push(EV_PAGE, a);
    if (a == 0u) { g_null_dispose++; return; }
    ts_scrub(a);
}

void spAtlasRegion_dispose(spAtlasRegion *region)
{
    uint32_t a = (uint32_t)(uintptr_t)region;
    ev_push(EV_REGION, a);
    if (a == 0u) { g_null_dispose++; return; }
    ts_scrub(a);
}
#else
static int idx_free(uint32_t a)
{
    int i;
    for (i = 0; i < g_free_n; i++) if (g_free[i] == a) return i;
    return -1;
}

void _spAtlasPage_disposeTexture(spAtlasPage *page)
{
    (void)page;
    g_tex_calls++;
}
#endif

static void build_graph_a(void)
{
    int i;
    g_atlasA = ts_alloc(SPATLAS_SIZE);
    for (i = 0; i < 3; i++) {
        g_p[i]  = ts_alloc(SPATPAGE_SIZE);
        g_nm[i] = ts_alloc(8u);
        fx_w32(g_p[i] + SPATPAGE_ATLAS, g_atlasA);
        fx_w32(g_p[i] + SPATPAGE_NAME,  g_nm[i]);
    }
    for (i = 0; i < 2; i++) {
        g_r[i]  = ts_alloc(SPATREGION_SIZE);
        g_rn[i] = ts_alloc(8u);
        g_rs[i] = ts_alloc(16u);
        g_rp[i] = ts_alloc(16u);
        fx_w32(g_r[i] + SPATREGION_NAME,   g_rn[i]);
        fx_w32(g_r[i] + SPATREGION_SPLITS, g_rs[i]);
        fx_w32(g_r[i] + SPATREGION_PADS,   g_rp[i]);
        fx_w32(g_r[i] + SPATREGION_PAGE,   g_p[i]);
    }
    fx_w32(g_p[0] + SPATPAGE_NEXT, g_p[1]);
    fx_w32(g_p[1] + SPATPAGE_NEXT, g_p[2]);
    fx_w32(g_p[2] + SPATPAGE_NEXT, 0u);
    fx_w32(g_r[0] + SPATREGION_NEXT, g_r[1]);
    fx_w32(g_r[1] + SPATREGION_NEXT, 0u);
    fx_w32(g_atlasA + SPATLAS_PAGES,    g_p[0]);
    fx_w32(g_atlasA + SPATLAS_REGIONS,  g_r[0]);
    fx_w32(g_atlasA + SPATLAS_RENDERER, RENDERER_SENTINEL);
}

static int run_all(void)
{
    uint32_t before;
    int ok, i;

    if (fx_map_arena() != 0) { fx_puts("FAIL arena map\n"); return 90; }

    /* 尾字不变量：next 是 44/80 字节块的最后 4 字节（不得放宽成 8 字节指针对齐） */
    chk(SPATPAGE_NEXT + 4u == SPATPAGE_SIZE && SPATREGION_NEXT + 4u == SPATREGION_SIZE,
        "next_slot_offsets_are_tail_words");

    build_graph_a();
    g_free_n = 0;

    spAtlas_dispose((spAtlas *)(uintptr_t)g_atlasA);

#ifdef YY_ATLAS_HELPERS_EXTERN
    ok = g_ev_n >= 3;
    for (i = 0; i < 3 && ok; i++) ok = (g_evk[i] == EV_PAGE && g_evv[i] == g_p[i]);
    chk(ok, "page_list_disposed_in_list_order");

    ok = (g_ev_n == 5) && g_evk[3] == EV_REGION && g_evv[3] == g_r[0]
                        && g_evk[4] == EV_REGION && g_evv[4] == g_r[1];
    chk(ok, "region_list_disposed_in_list_order");

    /* 边界构建里节点释放发生在替身内部，故"容器最后释放"要靠事件序判定：
     * 最后一个 dispose 事件必须是 region 链尾，且 atlas 只 free 一次；
     * 共用时钟还必须证明它晚于最后一个 region（分别数两个日志不够）。 */
    chk(g_free_n == 1 && g_free[0] == g_atlasA && count_free(g_atlasA) == 1
        && g_ev_n == 5 && g_evk[4] == EV_REGION && g_evv[4] == g_r[1]
        && g_free_seq[0] > g_ev_seq[4],
        "atlas_freed_exactly_once_and_last");

    ok = (g_ev_n == 5);
    for (i = 0; i < 3 && ok; i++) ok = (count_ev(EV_PAGE, g_p[i]) == 1);
    for (i = 0; i < 2 && ok; i++) ok = (count_ev(EV_REGION, g_r[i]) == 1);
    chk(ok, "every_node_disposed_exactly_once");
#else
    ok = 1;
    for (i = 0; i < 3 && ok; i++) {
        int in = idx_free(g_nm[i]), ip = idx_free(g_p[i]);
        ok = (in >= 0 && ip == in + 1);
    }
    chk(ok, "page_helper_frees_name_then_page");

    ok = 1;
    for (i = 0; i < 2 && ok; i++) {
        int b = idx_free(g_rn[i]);
        ok = (b >= 0 && idx_free(g_rs[i]) == b + 1 && idx_free(g_rp[i]) == b + 2
              && idx_free(g_r[i]) == b + 3);
    }
    chk(ok, "region_helper_frees_name_splits_pads_then_region");

    ok = (g_free_n == 15);
    {
        const uint32_t want[15] = {
            g_nm[0], g_p[0], g_nm[1], g_p[1], g_nm[2], g_p[2],
            g_rn[0], g_rs[0], g_rp[0], g_r[0],
            g_rn[1], g_rs[1], g_rp[1], g_r[1], g_atlasA
        };
        for (i = 0; i < 15 && ok; i++) ok = (g_free[i] == want[i]);
    }
    chk(ok, "full_free_log_matches_instruction_order");

    chk(g_free_n == 15 && g_free[14] == g_atlasA && count_free(g_atlasA) == 1,
        "atlas_freed_exactly_once_and_last");

    ok = (g_free_n == 15);
    for (i = 0; i < 15 && ok; i++) ok = (count_free(g_free[i]) == 1);
    chk(ok, "every_block_freed_exactly_once");
#endif

    chk(count_free(RENDERER_SENTINEL) == 0, "renderer_slot_not_freed");

    /* no-op 场景：pages/regions 都为 NULL 的 atlas 只释放自身 */
    before = (uint32_t)g_free_n;
    g_atlasB = ts_alloc(SPATLAS_SIZE);
#ifdef YY_ATLAS_HELPERS_EXTERN
    g_ev_n = 0;
    g_null_dispose = 0;
#endif
    spAtlas_dispose((spAtlas *)(uintptr_t)g_atlasB);
#ifdef YY_ATLAS_HELPERS_EXTERN
    chk(g_free_n == (int)before + 1 && g_free[before] == g_atlasB && g_ev_n == 0
        && g_null_dispose == 0u,
        "empty_atlas_frees_only_atlas");
    chk(g_null_dispose == 0u && count_free(0u) == 0,
        "no_dispose_on_null_terminator");
#else
    chk(g_free_n == (int)before + 1 && g_free[before] == g_atlasB
        && g_tex_calls == 3u && count_free(0u) == 0,
        "empty_atlas_frees_only_atlas");
#endif

    fx_puts("[DONE] assertions=");
    if (g_fail) fx_puts("FAILED\n"); else fx_puts("ALL PASS\n");
    return g_fail ? 1 : 0;
}

#ifdef YY_FIXTURE_ARM
void _start(void)
{
    fx_exit(run_all());
    for (;;) { }
}
#else
int main(void)
{
    return run_all();
}
#endif
