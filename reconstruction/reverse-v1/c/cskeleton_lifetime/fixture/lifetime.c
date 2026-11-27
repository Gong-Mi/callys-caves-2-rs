/* fixture_skeleton_lifetime.c — C2/D2 译文的合成夹具（不跑原件、不用 ART/Unicorn）
 *
 * 只做两件事：
 *   1) 用桩替换 C2/D2 的外部依赖，记录调用顺序、实参与当时的全局状态；
 *   2) 用**具名断言**比对「原件机器码规定的行为」，断言名即失败报告的行首。
 *
 * 行为依据见 src/skeleton_lifetime.c 的逐句锚点与 SEMANTICS.md。
 * 每个断言都对应一条能从原件反汇编直接读出的约束，而不是"跑一下不崩"。
 */
#include <stddef.h>
#include <stdint.h>
#if !defined(YY_FIXTURE_ARM)
#include <stdio.h>
#include <string.h>
static void emit(const char *s) { fputs(s, stdout); }
#else
extern void *memcpy(void *, const void *, size_t);
extern void *memset(void *, int, size_t);
static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7),"r"(r1),"r"(r2) : "memory");
    return r0;
}
static void emit(const char *s) { size_t n=0; while(s[n])++n; sys3(4,1,(long)s,n); }
#endif
static size_t fixture_strlen(const char *s) { size_t n=0; while(s[n])++n; return n; }

#include "yy_skel_deps.h"

/* ── 被测 TU 需要在 .bss 里看到的两个全局（原件 .bss）──────────────── */
yy_glob_479c98 g_yy_479c98;
volatile uint8_t g_bFreeingSpineSprite;   /* 0x479ca8，.dynsym GLOBAL OBJECT 1 B */

/* ── 事件日志 ─────────────────────────────────────────────────────────── */
enum {
    EV_DECODE = 1, EV_ATLAS_CREATE, EV_JSON_CREATE, EV_READ_DATA,
    EV_DATA_DISPOSE, EV_JSON_DISPOSE, EV_ATLAS_DISPOSE, EV_DELETE, EV_FREE
};
enum { EV_MAX = 64 };

static int     ev_n;
static int     ev_code[EV_MAX];
static uint8_t ev_flag[EV_MAX];

static void ev_push(int code)
{
    if (ev_n < EV_MAX) {
        ev_code[ev_n] = code;
        ev_flag[ev_n] = g_bFreeingSpineSprite;
        ev_n++;
    }
}
static void ev_reset(void)
{
    ev_n = 0;
    memset(ev_code, 0, sizeof ev_code);
    memset(ev_flag, 0, sizeof ev_flag);
}

/* ── 桩：SimpleDecode（非静态成员函数，mangled 名）──────────────────────
 * 原件 0xbd840 的语义：r1=buf、r2=len，len<=0 直接返回，否则逐字节
 * buf[i] -= key，key 递推 key = key*key + key，初值 42。这里照抄，
 * 但断言只看「谁被调用、实参是什么」，不看解出来的字节。 */
static int      dec_n;
static void    *dec_buf[8];
static int      dec_len[8];
static uint32_t dec_slot0[8], dec_slot1[8], dec_slot2[8], dec_globend[8];

void CSkeletonSprite_SimpleDecode(void *self, unsigned char *buf, int len)
        __asm__("_ZN15CSkeletonSprite12SimpleDecodeEPhi");
void CSkeletonSprite_SimpleDecode(void *self, unsigned char *buf, int len)
{
    yy_skel12 *o = (yy_skel12 *)self;      /* self 在原函数体里是死参数，仅记录用 */
    if (dec_n < 8) {
        dec_buf[dec_n]     = buf;
        dec_len[dec_n]     = len;
        dec_slot0[dec_n]   = o->slot_00_json;
        dec_slot1[dec_n]   = o->slot_04_data;
        dec_slot2[dec_n]   = o->slot_08_atlas;
        dec_globend[dec_n] = g_yy_479c98.end;
    }
    dec_n++;
    ev_push(EV_DECODE);
    if (len > 0) {
        unsigned char key = 42;
        for (int i = 0; i < len; i++) {
            buf[i] = (unsigned char)(buf[i] - key);
            key = (unsigned char)(key * key + key);
        }
    }
}

/* ── 桩：spine（原件 .dynsym 里的 C 名，不是 mangled）──────────────────── */
static spAtlas        *ret_atlas;
static spSkeletonJson *ret_json;
static spSkeletonData *ret_data;

static char      atlas_dir_seen[32];
static int       atlas_dir_is_empty;
static const char *atlas_data_seen;
static int       atlas_len_seen;
static void     *atlas_renderer_seen;

static spAtlas        *json_create_arg;
static spSkeletonJson *read_arg_json;
static const char     *read_arg_text;

spAtlas *spAtlas_create(const char *data, int dataLen, const char *dir, void *renderer)
{
    ev_push(EV_ATLAS_CREATE);
    atlas_data_seen = data;
    atlas_len_seen  = dataLen;
    atlas_renderer_seen = renderer;
    atlas_dir_is_empty = (dir != NULL);
    if (dir != NULL) {
        size_t n = fixture_strlen(dir);
        if (n >= sizeof atlas_dir_seen) n = sizeof atlas_dir_seen - 1;
        memcpy(atlas_dir_seen, dir, n);
        atlas_dir_seen[n] = '\0';
        atlas_dir_is_empty = (n == 0);
    } else {
        atlas_dir_seen[0] = '\0';
    }
    return ret_atlas;
}

void spAtlas_dispose(spAtlas *a)
{
    (void)a;
    ev_push(EV_ATLAS_DISPOSE);
}

spSkeletonJson *spSkeletonJson_create(spAtlas *atlas)
{
    ev_push(EV_JSON_CREATE);
    json_create_arg = atlas;
    return ret_json;
}

void spSkeletonJson_dispose(spSkeletonJson *j)
{
    (void)j;
    ev_push(EV_JSON_DISPOSE);
}

spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *j, const char *text)
{
    ev_push(EV_READ_DATA);
    read_arg_json = j;
    read_arg_text = text;
    return ret_data;
}

void spSkeletonData_dispose(spSkeletonData *d)
{
    (void)d;
    ev_push(EV_DATA_DISPOSE);
}

/* 守卫：D2 不应该自己去 delete 对象（那是 CSprite::Clear 的活） */
static int g_delete_calls, g_free_calls;
void yy_stub_delete(void *p)             __asm__("_ZdlPv");
void yy_stub_delete(void *p)             { (void)p; g_delete_calls++; ev_push(EV_DELETE); }
void yy_stub_mm_free(const void *p)      __asm__("_ZN13MemoryManager4FreeEPKv");
void yy_stub_mm_free(const void *p)      { (void)p; g_free_calls++;  ev_push(EV_FREE); }

/* ── 断言 ─────────────────────────────────────────────────────────────── */
static int g_checks, g_fails;
#define CHECK(cond, name)                                                      \
    do {                                                                       \
        g_checks++;                                                            \
        if (cond) {                                                            \
            emit("[PASS] "); emit(name); emit("\n");                                     \
        } else {                                                               \
            g_fails++;                                                         \
            emit("[FAIL] "); emit(name); emit("\n");                                     \
        }                                                                      \
    } while (0)

/* 64 位宿主上，槽只有 32 位：所有被测对象必须在低 4 GiB。
 * 原件是 ARM32（uintptr_t 就是 32 位），这是夹具的认证域限制，不是被测代码的。 */
static yy_skel12 g_obj __attribute__((aligned(4)));

int fixture_main(void)
{
    /* 槽只有 32 位。宿主地址高于 4 GiB 时，槽里的值会被截断——本夹具对槽一律按
     * 32 位比较（(uint32_t)(uintptr_t)p），且从不把槽里的值解引用回对象，所以
     * 高地址宿主仍然可用；只是"槽 → 真实指针"这一步只在 ARM32 上无损。 */


    /* 桩句柄：低地址假指针，避免与真实堆地址混淆 */
    ret_atlas = (spAtlas *)(uintptr_t)0x1001u;
    ret_json  = (spSkeletonJson *)(uintptr_t)0x1002u;
    ret_data  = (spSkeletonData *)(uintptr_t)0x1003u;

    /* ── 场景 1：构造。a=8、b=5、c/d/e 取三个可区分值 ─────────────────── */
    static char name[64];
    const unsigned A = 8u, B = 5u, C = 0xAAAA1111u, D = 0xBBBB2222u, E = 0xCCCC3333u;
    memset(name, 0x5A, sizeof name);
    memset(&g_obj, 0xEE, sizeof g_obj);       /* 脏值：ctor 必须先清零 */
    memset(&g_yy_479c98, 0xEE, sizeof g_yy_479c98);
    g_bFreeingSpineSprite = 0;
    ev_reset(); dec_n = 0;

    void *ctor_return = CSkeletonSprite_ctor(&g_obj, name, A, B, C, D, E);
    CHECK(ctor_return == &g_obj, "ctor_returns_this");

    CHECK(dec_n == 2
          && dec_slot0[0] == 0 && dec_slot1[0] == 0 && dec_slot2[0] == 0,
          "ctor_zeroes_three_slots_before_first_decode");
    CHECK(dec_n == 2 && dec_globend[0] == (uint32_t)(uintptr_t)(name + A + B),
          "ctor_writes_global_after_slots_before_first_decode");
    CHECK(dec_n == 2 && dec_buf[0] == (void *)name && dec_len[0] == (int)A
          && dec_buf[1] == (void *)(name + A) && dec_len[1] == (int)B,
          "ctor_decodes_base_a_then_name_plus_a_b");
    CHECK(g_yy_479c98.end == (uint32_t)(uintptr_t)(name + A + B)
          && g_yy_479c98.w04 == C && g_yy_479c98.w08 == D && g_yy_479c98.w0c == E,
          "ctor_global_is_end_and_three_words");
    CHECK(atlas_data_seen == name + A && atlas_len_seen == (int)B
          && atlas_dir_is_empty && atlas_renderer_seen == NULL,
          "ctor_atlas_gets_second_segment_and_empty_dir");
    CHECK(json_create_arg == ret_atlas
          && g_obj.slot_08_atlas == (uint32_t)(uintptr_t)ret_atlas
          && g_obj.slot_00_json == (uint32_t)(uintptr_t)ret_json,
          "ctor_json_slot_from_create_atlas");
    CHECK(read_arg_json == ret_json
          && read_arg_text == name                    /* 基址，不是 name+A */
          && g_obj.slot_04_data == (uint32_t)(uintptr_t)ret_data,
          "ctor_read_data_uses_base_pointer");
    CHECK(ev_n == 5
          && ev_code[0] == EV_DECODE && ev_code[1] == EV_DECODE
          && ev_code[2] == EV_ATLAS_CREATE && ev_code[3] == EV_JSON_CREATE
          && ev_code[4] == EV_READ_DATA,
          "ctor_event_order_decode_decode_atlas_json_read");

    /* ── 场景 2：析构，三个槽都非 0 ────────────────────────────────────── */
    ev_reset(); g_bFreeingSpineSprite = 0;
    yy_skel12 keep = g_obj;

    void *dtor_return = CSkeletonSprite_D2(&g_obj);
    CHECK(dtor_return == &g_obj, "dtor_returns_this");

    CHECK(ev_n == 3 && ev_code[0] == EV_DATA_DISPOSE
          && ev_code[1] == EV_JSON_DISPOSE && ev_code[2] == EV_ATLAS_DISPOSE,
          "dtor_dispose_order_data_json_atlas");
    CHECK(ev_flag[0] == 0 && ev_flag[1] == 0 && ev_flag[2] == 1,
          "dtor_flag_is_zero_for_data_json_and_one_for_atlas");
    CHECK(g_obj.slot_00_json == keep.slot_00_json
          && g_obj.slot_04_data == keep.slot_04_data
          && g_obj.slot_08_atlas == keep.slot_08_atlas,
          "dtor_leaves_slots_untouched");
    CHECK(g_delete_calls == 0 && g_free_calls == 0,
          "dtor_does_not_delete_the_object");

    /* ── 场景 3：析构，全 0 槽 + 旗标预置 1 ─────────────────────────────── */
    yy_skel12 zero;
    memset(&zero, 0, sizeof zero);
    g_bFreeingSpineSprite = 1;      /* 预置成 1：强制写成 0 才算对 */
    ev_reset();
    CSkeletonSprite_D2(&zero);
    CHECK(ev_n == 0, "dtor_skips_all_dispose_when_slots_null");
    CHECK(g_bFreeingSpineSprite == 0, "dtor_clears_flag_when_atlas_is_null");

    /* ── 场景 4：旗标不恢复旧值（预置 1、atlas 非 0）────────────────────── */
    g_bFreeingSpineSprite = 1;
    ev_reset();
    CSkeletonSprite_D2(&g_obj);
    CHECK(ev_n == 3 && g_bFreeingSpineSprite == 0,
          "dtor_forces_flag_zero_without_restoring_previous");

    emit(g_checks == 17 && !g_fails ? "SKELETON OK 17\n" : "SKELETON FAILED\n");
    return g_fails ? 1 : 0;
}

#if defined(YY_FIXTURE_ARM)
void _start(void) { sys3(1,fixture_main(),0,0); for(;;){} }
#else
int main(void) { return fixture_main(); }
#endif
