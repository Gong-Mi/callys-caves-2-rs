/* spine_json_fixture.c — spSkeletonJson_create/dispose 的合成夹具（host + ARM32/qemu）
 *
 * 只执行自建译文 + 合成替身；原件一次都没被加载、执行或 mmap。
 * 替身就是原件里的外部符号（spAtlasAttachmentLoader_create / spAttachmentLoader_dispose /
 * _calloc / _free），夹具只记录调用序列与参数，用来判「译文是否按原件那样调」。
 *
 * 退出码：0 全通过；1 有具名 [FAIL]；90 夹具自身初始化失败（不是被测实现的错）。
 * 任何崩溃都不算「杀死变异体」——run_tests.py 只认 rc==1 且有具名失败。
 */
#include <stdint.h>
#include <stddef.h>
#include "fx.h"

typedef struct spAtlas spAtlas;
typedef struct spSkeletonJson spSkeletonJson;

spSkeletonJson *spSkeletonJson_create(spAtlas *atlas);
void            spSkeletonJson_dispose(spSkeletonJson *j);
void           *spAtlasAttachmentLoader_create(spAtlas *atlas);
void            spAttachmentLoader_dispose(void *loader);
void           *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line);
void            _free(void *p);

/* ── 调用轨迹 ─────────────────────────────────────────────────────────── */
static struct {
    uint32_t lc_calls;       /* spAtlasAttachmentLoader_create 调用次数 */
    uint32_t lc_atlas;       /* 收到的 atlas 实参 */
    uint32_t loader;         /* 返回的 loader 句柄 */

    uint32_t ld_calls;       /* spAttachmentLoader_dispose 调用次数 */
    uint32_t ld_arg;

    uint32_t calloc_calls;
    uint32_t calloc_nmemb, calloc_size, calloc_tag, calloc_line, calloc_tag_matches;
    uint32_t calloc_ret;

    uint32_t free_n;
    uint32_t free_log[8];
} tr;

void *spAtlasAttachmentLoader_create(spAtlas *atlas)
{
    tr.lc_calls++;
    tr.lc_atlas = (uint32_t)(uintptr_t)atlas;
    tr.loader = fx_alloc(16);
    return (void *)(uintptr_t)tr.loader;
}

void spAttachmentLoader_dispose(void *loader)
{
    tr.ld_calls++;
    tr.ld_arg = (uint32_t)(uintptr_t)loader;
}

void *_calloc(uint32_t nmemb, uint32_t size, const char *tag, uint32_t line)
{
    tr.calloc_calls++;
    tr.calloc_nmemb = nmemb;
    tr.calloc_size  = size;
    tr.calloc_tag   = (uint32_t)(uintptr_t)tag;
    tr.calloc_line  = line;
    static const char expected_tag[]="jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";
    tr.calloc_tag_matches = tag != NULL;
    if (tag) for (size_t i=0; i<sizeof expected_tag; ++i)
        if (tag[i]!=expected_tag[i]) { tr.calloc_tag_matches=0; break; }
    uint32_t n = nmemb * size;
    uint32_t a = fx_alloc(n ? n : 1u);
    volatile uint8_t *p = (volatile uint8_t *)(uintptr_t)a;
    for (uint32_t i = 0; i < n; ++i) p[i] = 0;   /* calloc 语义 */
    tr.calloc_ret = a;
    return (void *)(uintptr_t)a;
}

void _free(void *p)
{
    if (tr.free_n < 8u) tr.free_log[tr.free_n] = (uint32_t)(uintptr_t)p;
    tr.free_n++;
}

/* ── 小工具 ───────────────────────────────────────────────────────────── */
static int g_fail;

static void chk(int ok, const char *name)
{
    fx_puts(ok ? "[PASS] " : "[FAIL] ");
    fx_puts(name);
    fx_puts("\n");
    if (!ok) g_fail++;
}

static void zero28(uint32_t a)
{
    volatile uint8_t *p = (volatile uint8_t *)(uintptr_t)a;
    for (uint32_t i = 0; i < 28u; ++i) p[i] = 0;
}

/* 造一个 28 字节的合成句柄：owns=+0x0c, loader=+0x04, p08=+0x08, p18=+0x18 */
static uint32_t mk_json(uint32_t owns, uint32_t loader, uint32_t p08, uint32_t p18)
{
    uint32_t a = fx_alloc(28);
    zero28(a);
    fx_w32(a + 0x04, loader);
    fx_w32(a + 0x08, p08);
    fx_w32(a + 0x0c, owns);
    fx_w32(a + 0x18, p18);
    return a;
}

static int run_all(void)
{
    if (fx_map_arena()) { fx_puts("FIXTURE arena map failed\n"); fx_exit(90); }

    const uint32_t atlas = fx_alloc(32);
    const char *N;

    /* ── create ──────────────────────────────────────────────────────── */
    spSkeletonJson *j = spSkeletonJson_create((spAtlas *)(uintptr_t)atlas);
    const uint32_t j1 = (uint32_t)(uintptr_t)j;
    const uint32_t loader1 = tr.loader;

    N = "create_returns_calloc_block_at_28_bytes";
    chk(tr.calloc_calls == 1u && tr.calloc_nmemb == 1u && tr.calloc_size == 28u
        && tr.calloc_line == 62u && j1 != 0u && j1 == tr.calloc_ret, N);

    N = "calloc_uses_original_metadata";
    chk(tr.calloc_tag_matches, N);

    N = "create_forwards_atlas_to_attachment_loader";
    chk(tr.lc_calls == 1u && tr.lc_atlas == atlas, N);

    N = "create_stores_loader_at_0x04";
    chk(fx_r32(j1 + 0x04u) == loader1 && loader1 != 0u, N);

    N = "create_sets_scale_to_1f_at_0x00";
    chk(fx_r32(j1 + 0x00u) == 0x3f800000u, N);

    N = "create_sets_owns_loader_at_0x0c";
    chk(fx_r32(j1 + 0x0cu) == 1u, N);

    N = "create_leaves_other_words_untouched";
    chk(fx_r32(j1 + 0x08u) == 0u && fx_r32(j1 + 0x10u) == 0u
        && fx_r32(j1 + 0x14u) == 0u && fx_r32(j1 + 0x18u) == 0u, N);

    /* create → dispose 端到端：ctor 链里就是这么配对的 */
    tr.free_n = 0u; tr.ld_calls = 0u; tr.ld_arg = 0u;
    spSkeletonJson_dispose(j);
    N = "create_then_dispose_disposes_created_loader";
    chk(tr.ld_calls == 1u && tr.ld_arg == loader1 && tr.free_n == 3u
        && tr.free_log[0] == 0u && tr.free_log[1] == 0u && tr.free_log[2] == j1, N);

    /* NULL atlas：原件把 r0 原样交给 loader 工厂，不判空、也不判 helper 返回值 */
    spSkeletonJson *jn = spSkeletonJson_create((spAtlas *)0);
    N = "create_with_null_atlas_forwards_null";
    chk(jn != (spSkeletonJson *)0 && tr.lc_atlas == 0u && tr.lc_calls == 2u
        && (uint32_t)(uintptr_t)jn == tr.calloc_ret, N);

    /* ── dispose 的三个独立面 ────────────────────────────────────────── */
    const uint32_t L = fx_alloc(16);
    const uint32_t p08 = fx_alloc(8);
    const uint32_t p18 = fx_alloc(8);

    uint32_t ja = mk_json(1u, L, p08, p18);
    tr.free_n = 0u; tr.ld_calls = 0u; tr.ld_arg = 0u;
    spSkeletonJson_dispose((spSkeletonJson *)(uintptr_t)ja);
    N = "dispose_with_flag_set_disposes_loader";
    chk(tr.ld_calls == 1u && tr.ld_arg == L, N);

    uint32_t jb = mk_json(0u, L, p08, p18);
    tr.free_n = 0u; tr.ld_calls = 0u; tr.ld_arg = 0u;
    spSkeletonJson_dispose((spSkeletonJson *)(uintptr_t)jb);
    N = "dispose_with_flag_clear_skips_loader";
    chk(tr.ld_calls == 0u && tr.ld_arg == 0u, N);

    uint32_t jc = mk_json(1u, L, p08, p18);
    tr.free_n = 0u; tr.ld_calls = 0u; tr.ld_arg = 0u;
    spSkeletonJson_dispose((spSkeletonJson *)(uintptr_t)jc);
    N = "dispose_free_order_is_18_then_08_then_self";
    chk(tr.free_n == 3u && tr.free_log[0] == p18 && tr.free_log[1] == p08
        && tr.free_log[2] == jc, N);

    uint32_t jd = mk_json(0u, L, 0u, 0u);
    uint8_t snap[28];
    {
        const volatile uint8_t *p = (const volatile uint8_t *)(uintptr_t)jd;
        for (uint32_t i = 0; i < 28u; ++i) snap[i] = p[i];
    }
    tr.free_n = 0u;
    spSkeletonJson_dispose((spSkeletonJson *)(uintptr_t)jd);
    int same = 1;
    {
        const volatile uint8_t *p = (const volatile uint8_t *)(uintptr_t)jd;
        for (uint32_t i = 0; i < 28u; ++i) if (snap[i] != p[i]) same = 0;
    }
    N = "dispose_does_not_rewrite_fields";
    chk(same, N);

    return g_fail ? 1 : 0;
}

#ifdef FX_FREESTANDING
void _start(void) { fx_exit(run_all()); }
#endif

int main(void) { return run_all(); }
