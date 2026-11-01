/* fixture_clear.c — CSprite::Clear() 译文的有区分力 fixture
 *
 * 目的：用**真实回调改写对象状态**的测试，验证译文是否保留了原件的重读次序：
 *   - TPE 循环：每次 MemoryManager::Free 返回后重读 self+0x44 与 self+0x54；
 *   - 位图循环：每次 D0 返回后重读 self+0x44 与 self+0x48（零写用重读后的基址）。
 * 另有两个变异体（tools/mutants/）必须在同一 fixture 上被杀掉：
 *   M1 把 TPE 的表/上界提到循环外；M2 把位图数组基址提到循环外。
 * 没有区分力的“检查通过”不算证据，所以这里断言的是**回调可观测的差异**：
 * 被 Free 的地址序列、被清零的数组槽、最终字段值、调用顺序。
 *
 * 边界（必须一起读）：
 *   - 所有依赖都是本文件里的替身（stub），只记录调用并可选地改写对象；
 *     它们的内部语义（MemoryManager 的真实分配器、CBitmap32 的真实 D0、
 *     FreeTexture/FreeMask/ClearSWFData 的真实释放树）不在本 fixture 的证明范围。
 *   - fixture 证明的是“译文实现了从原件指令读出的数据流”，不是“原件运行时
 *     一定如此”，也不是与原件的行为等价。原件从未执行（任务禁止）。
 *   - 指针字段在 CSprite 里是 uint32_t，所以 host 构建把整个测试堆放在 4 GiB
 *     以下的固定映射（0x20000000）；ARM32 构建用静态 arena。两者都不改变
 *     CSprite 的偏移（header 的 offsetof 断言在两种构建下都编译）。
 *
 * 构建/运行：tools/run_fixtures.sh
 */
#include "csprite_clear.h"

/* 位图路径通过 32 位槽里的 vptr 做 `blx`：只有当代码地址本身 < 4 GiB 时才能建模。
 * ARM32 构建天然满足；host（aarch64/x86_64 PIE，代码在 0x6... ）不满足，
 * 因此 host 构建跳过依赖该路径的用例，并在输出里显式记 SKIP（不冒充 PASS）。 */
#if defined(HARNESS_FREESTANDING) || UINTPTR_MAX <= 0xFFFFFFFFu
#  define LOW_CODE 1
#else
#  define LOW_CODE 0
#endif

#if defined(HARNESS_FREESTANDING)
#  define HF 1
#else
#  define HF 0
#  include <stdio.h>
#  include <string.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <sys/mman.h>
#endif

/* ---------------------------------------------------------------- 输出 */
#if HF
static long h_sys3(long n, long a, long b, long c)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r7 __asm__("r7") = n;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}
static void h_exit(int code)
{
    h_sys3(1, code, 0, 0);
    for (;;) { }
}
static void h_write(const char *s, unsigned n) { h_sys3(4, 1, (long)s, (long)n); }
#else
static void h_exit(int code) { exit(code); }
static void h_write(const char *s, unsigned n) { fwrite(s, 1, n, stdout); fflush(stdout); }
#endif

static void h_puts(const char *s) { unsigned n = 0; while (s[n]) ++n; h_write(s, n); }
static void h_puthex(uint32_t v)
{
    char b[11];
    b[0] = '0'; b[1] = 'x';
    for (int i = 0; i < 8; ++i) {
        unsigned d = (v >> (28 - 4 * i)) & 15u;
        b[2 + i] = (char)(d < 10 ? ('0' + d) : ('a' + d - 10));
    }
    h_write(b, 10);
}
static void h_putint(int v)
{
    char b[12]; int i = 11; int neg = v < 0;
    unsigned u = neg ? (unsigned)(-(v + 1)) + 1u : (unsigned)v;
    b[i] = 0;
    do { b[--i] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) b[--i] = '-';
    h_puts(&b[i]);
}

#if HF
/* freestanding：自己提供 memset（同时供 CSprite::Clear 的 bbox 清零使用）。 */
void *memset(void *d, int c, size_t n);
#endif

/* --------------------------------------------------------------- arena */
#if HF
static unsigned char g_arena_store[256 * 1024] __attribute__((aligned(64)));
static unsigned char *g_arena = g_arena_store;
static void arena_init(void) { }
#else
static unsigned char *g_arena;
static void arena_init(void)
{
    static const uintptr_t bases[] = { 0x20000000u, 0x30000000u, 0x40000000u,
                                       0x50000000u, 0x10000000u };
    for (unsigned i = 0; i < sizeof bases / sizeof bases[0]; ++i) {
        void *p = mmap((void *)bases[i], 1u << 20, PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED_NOREPLACE, -1, 0);
        if (p != MAP_FAILED) { g_arena = (unsigned char *)p; return; }
    }
    h_puts("FATAL: cannot mmap a low (<4GiB) arena for the 32-bit pointer model\n");
    h_exit(90);
}
#endif
static size_t g_arena_used;
static void *h_alloc(size_t n)
{
    size_t off = (g_arena_used + 15u) & ~(size_t)15u;
    void *p = g_arena + off;
    g_arena_used = off + n;
    if (g_arena_used > 256u * 1024u) { h_puts("FATAL: arena exhausted\n"); h_exit(91); }
    if ((uintptr_t)p > 0xFFFFFFFFu) { h_puts("FATAL: pointer above 4GiB\n"); h_exit(92); }
    memset(p, 0, n);
    return p;
}

/* ----------------------------------------------------------- event log */
enum { EV_SWF = 1, EV_D2, EV_DEL, EV_FREE, EV_D0, EV_FTEX, EV_FMASK };
static int g_ev_kind[1024];
static uint32_t g_ev_arg[1024];
static int g_ev_n;

static void ev(int k, uint32_t a)
{
    if (g_ev_n < 1024) { g_ev_kind[g_ev_n] = k; g_ev_arg[g_ev_n] = a; ++g_ev_n; }
}
static void reset_log(void) { g_ev_n = 0; }
static int ev_count(int k)
{
    int c = 0;
    for (int i = 0; i < g_ev_n; ++i) if (g_ev_kind[i] == k) ++c;
    return c;
}
static int ev_index(int k)
{
    for (int i = 0; i < g_ev_n; ++i) if (g_ev_kind[i] == k) return i;
    return -1;
}
static int ev_nth_kind(int k, int n)
{
    int c = 0;
    for (int i = 0; i < g_ev_n; ++i) if (g_ev_kind[i] == k) { if (c == n) return i; ++c; }
    return -1;
}
static int free_seq_is(const uint32_t *want, int n)
{
    int c = 0;
    for (int i = 0; i < g_ev_n; ++i) {
        if (g_ev_kind[i] != EV_FREE) continue;
        if (c >= n || g_ev_arg[i] != want[c]) return 0;
        ++c;
    }
    return c == n;
}
static void dump_free_seq(void)
{
    int c = 0;
    h_puts("      free seq:");
    for (int i = 0; i < g_ev_n; ++i) {
        if (g_ev_kind[i] != EV_FREE) continue;
        h_puts(" "); h_puthex(g_ev_arg[i]); ++c;
    }
    if (!c) h_puts(" (none)");
    h_puts("\n");
}

/* ------------------------------------------------------------- stubs */
/* 回调钩子：在记录一次 Free 之后调用（测试可实现“外调改写本对象”）。 */
static void (*g_free_hook)(uint32_t p);
static void (*g_d0_hook)(uint32_t id);
static int g_d1_called;
static int g_d1_short_circuit;   /* 置 1 时 D1（错误槽）直接跳过 */

void mm_free_stub(const void *p) __asm__("_ZN13MemoryManager4FreeEPKv");
void mm_free_stub(const void *p)
{
    uint32_t a = (uint32_t)(uintptr_t)p;
    ev(EV_FREE, a);
    if (g_free_hook) g_free_hook(a);
}

void swf_stub(CSprite *s) __asm__("_ZN7CSprite12ClearSWFDataEv");
void swf_stub(CSprite *s) { (void)s; ev(EV_SWF, 0); }

void ftex_stub(CSprite *s) __asm__("_ZN7CSprite11FreeTextureEv");
void ftex_stub(CSprite *s) { (void)s; ev(EV_FTEX, 0); }

void fmask_stub(CSprite *s) __asm__("_ZN7CSprite8FreeMaskEv");
void fmask_stub(CSprite *s) { (void)s; ev(EV_FMASK, 0); }

void *skel_d2_stub(void *p) __asm__("_ZN15CSkeletonSpriteD2Ev");
void *skel_d2_stub(void *p) { ev(EV_D2, (uint32_t)(uintptr_t)p); return p; }

/* 真实 _ZdlPv 是 `b MemoryManager::Free`；这里按同一语义转发。 */
void del_stub(void *p) __asm__("_ZdlPv");
void del_stub(void *p)
{
    ev(EV_DEL, (uint32_t)(uintptr_t)p);
    mm_free_stub(p);
}

/* 假 CBitmap32：vptr 指向两槽表；slot0 是错的 D1 探针，slot1 是 D0。
 * slot1 的 D0 按真实语义（D2 + operator delete）转发到 Free。 */
struct fake_bmp { uint32_t vptr; uint32_t id; };

static void bmp_d1_wrong(void *p)
{
    (void)p;
    g_d1_called = 1;
    if (!g_d1_short_circuit) { h_puts("FATAL: D1 (slot 0) was called\n"); h_exit(93); }
}
static void bmp_d0(void *p)
{
    struct fake_bmp *b = (struct fake_bmp *)p;
    uint32_t id = b->id;
    ev(EV_D0, id);
    mm_free_stub(p);                 /* D0 = D2 + operator delete */
    if (g_d0_hook) g_d0_hook(id);
}
static uint32_t g_vt[4];
static void vt_init(void)
{
    g_vt[0] = (uint32_t)(uintptr_t)&bmp_d1_wrong;
    g_vt[1] = (uint32_t)(uintptr_t)&bmp_d0;
}
static struct fake_bmp *new_bmp(uint32_t id)
{
    struct fake_bmp *b = (struct fake_bmp *)h_alloc(sizeof *b);
    b->vptr = (uint32_t)(uintptr_t)&g_vt[0];
    b->id = id;
    return b;
}

#if HF
void *memset(void *d, int c, size_t n)
{
    unsigned char *p = (unsigned char *)d;
    while (n--) *p++ = (unsigned char)c;
    return d;
}
#endif

/* ------------------------------------------------------------- 工具 */
static CSprite *new_obj(void)
{
    CSprite *s = (CSprite *)h_alloc(sizeof *s);
    memset(s, 0, sizeof *s);
    s->vptr = 0xC0DEF00Du;
    s->flag_35 = 0xA5;
    s->pad_37 = 0x5A;
    s->local_tpe_count = 0x11223344;
    s->field_2c = 0x2C2C2C2Cu;
    s->field_5c = 0x5C5C5C5Cu;
    s->field_60 = 0x60606060u;
    s->field_64 = 0x64646464;
    s->field_68 = 0x68686868;
    s->field_6c = 30.0f;
    s->field_70 = 0x70707070u;
    s->field_78 = 0x78;
    return s;
}
static int untouched_ok(const CSprite *s)
{
    return s->vptr == 0xC0DEF00Du &&
           s->flag_35 == 0xA5 && s->pad_37 == 0x5A &&
           s->local_tpe_count == 0x11223344 &&
           s->field_2c == 0x2C2C2C2Cu &&
           s->field_64 == 0x64646464 &&
           s->field_68 == 0x68686868 &&
           s->field_70 == 0x70707070u && s->field_78 == 0x78;
}
static int reset_ok(const CSprite *s)
{
    return s->bbox_mode == 0 &&
           s->bbox[0] == 0 && s->bbox[1] == 0 && s->bbox[2] == 0 && s->bbox[3] == 0 &&
           s->frame_count == 0 && s->width == 1 && s->height == 1 &&
           s->field_24 == 0 && s->field_28 == 0 &&
           s->flag_33 == 0 && s->flag_32 == 1 && s->flag_34 == 1 && s->flag_30 == 1 &&
           s->bitmap_count == 0 && s->bitmaps == 0 &&
           s->texture_count == 0 && s->texture_ids == 0 &&
           s->local_tpe == 0 && s->skeleton == 0 &&
           s->field_5c == 0 && s->field_60 == 0 && s->type == 0;
}
/* 一致性要求：0x44 同时是位图数组的长度，所以 TPE 测试也必须给出同样多的
 * 空位图槽（原件对 NULL 基址不设防，测试不制造这种不一致对象）。 */
static uint32_t *zero_slots(int n)
{
    uint32_t *a = (uint32_t *)h_alloc((size_t)n * 4);
    for (int i = 0; i < n; ++i) a[i] = 0;
    return a;
}

/* 避免软浮点运行时助手（__aeabi_fcmpeq）：按位比较 30.0f == 0x41F00000。 */
static uint32_t f32_bits(float f) { union { float f; uint32_t u; } v; v.f = f; return v.u; }

static int g_test_failed;
static void fail(const char *why) { g_test_failed = 1; h_puts("    FAIL: "); h_puts(why); h_puts("\n"); }
#define CHK(cond, why) do { if (!(cond)) { fail(why); return; } } while (0)

/* ------------------------------------------------------------- tests */
/* T1 类型分流：只有 type==1 调 ClearSWFData，且在任何释放之前。 */
static void t_type_gate(void)
{
    CSprite *s = new_obj();
    s->type = 0;
    CSprite_Clear(s);
    CHK(ev_count(EV_SWF) == 0, "type=0 must not call ClearSWFData");
    CHK(s->type == 0, "type must end 0");

    s->type = 1;
    reset_log();
    CSprite_Clear(s);
    CHK(ev_count(EV_SWF) == 1, "type=1 must call ClearSWFData once");
    CHK(ev_index(EV_SWF) == 0, "ClearSWFData must be the first call");
    CHK(s->type == 0, "type must end 0 after the SWF path");
    CHK(untouched_ok(s) && reset_ok(s), "postcondition/untouched fields");
}

/* T2 骨架：D2 → operator delete → 置空，顺序固定。 */
static void t_skeleton(void)
{
    CSprite *s = new_obj();
    s->skeleton = 0x00008000u;
    CSprite_Clear(s);
    CHK(ev_nth_kind(EV_D2, 0) >= 0 && g_ev_arg[ev_nth_kind(EV_D2, 0)] == 0x8000u, "D2(skeleton)");
    CHK(ev_nth_kind(EV_DEL, 0) >= 0 && g_ev_arg[ev_nth_kind(EV_DEL, 0)] == 0x8000u, "delete(skeleton)");
    CHK(ev_index(EV_D2) < ev_index(EV_DEL), "D2 before delete");
    CHK(s->skeleton == 0, "skeleton must be nulled");
}

/* T3 TPE：第 1 次 Free 后基址被回调改写 → 下一轮必须从新基址取条目。
 *    缓存基址的变异体 M1 会 Free 旧表的 A2，本测试即杀它。 */
static CSprite *g_cur_s;
static uint32_t *g_swap_to;
static void hook_swap_tpe(uint32_t p)
{
    if (p == 0xA1u && g_swap_to) { g_cur_s->local_tpe = (uint32_t)(uintptr_t)g_swap_to; g_swap_to = 0; }
}
static void t_tpe_base_reread(void)
{
    CSprite *s = new_obj();
    uint32_t *A = (uint32_t *)h_alloc(3 * 4);
    uint32_t *B = (uint32_t *)h_alloc(3 * 4);
    A[0] = 0xA1; A[1] = 0xA2; A[2] = 0xA3;
    B[0] = 0xB1; B[1] = 0xB2; B[2] = 0xB3;
    uint32_t *slots = zero_slots(2);
    s->local_tpe = (uint32_t)(uintptr_t)A;
    s->bitmaps = (uint32_t)(uintptr_t)slots;
    s->bitmap_count = 2;
    s->owns_local_tpe = 1;
    g_cur_s = s; g_swap_to = B; g_free_hook = hook_swap_tpe;

    CSprite_Clear(s);
    g_free_hook = 0; g_cur_s = 0;

    {
        const uint32_t want[] = { 0xA1u, 0xB2u, (uint32_t)(uintptr_t)B,
                                  (uint32_t)(uintptr_t)slots, 0u };
        if (!free_seq_is(want, 5)) { dump_free_seq(); fail("expected A1, B2, Free(B), Free(bitmap array), Free(0)"); return; }
    }
    CHK(s->local_tpe == 0, "0x54 zeroed");
    CHK(s->owns_local_tpe == 0, "0x36 zeroed");
}

/* T4 TPE：Free 回调把 0x44 从 1 改成 3 → 必须释放 3 条（重读上界）。
 *    缓存上界的变异体只释放 1 条。 */
static void hook_grow_count(uint32_t p)
{
    if (p == 0xA1u) g_cur_s->bitmap_count = 3;
}
static void t_tpe_count_grow(void)
{
    CSprite *s = new_obj();
    uint32_t *A = (uint32_t *)h_alloc(3 * 4);
    A[0] = 0xA1; A[1] = 0xA2; A[2] = 0xA3;
    uint32_t *slots = zero_slots(3);
    s->local_tpe = (uint32_t)(uintptr_t)A;
    s->bitmaps = (uint32_t)(uintptr_t)slots;
    s->bitmap_count = 1;
    s->owns_local_tpe = 1;
    g_cur_s = s; g_free_hook = hook_grow_count;

    CSprite_Clear(s);
    g_free_hook = 0; g_cur_s = 0;

    {
        const uint32_t want[] = { 0xA1u, 0xA2u, 0xA3u, (uint32_t)(uintptr_t)A,
                                  (uint32_t)(uintptr_t)slots, 0u };
        if (!free_seq_is(want, 6)) { dump_free_seq(); fail("count growth 1->3 must free 3 entries"); return; }
    }
}

/* T5 TPE：Free 回调把 0x44 清零 → 必须立刻停止（重读上界）。
 *    缓存上界的变异体会继续释放 A2/A3。 */
static void hook_shrink_count(uint32_t p)
{
    if (p == 0xA1u) g_cur_s->bitmap_count = 0;
}
static void t_tpe_count_shrink(void)
{
    CSprite *s = new_obj();
    uint32_t *A = (uint32_t *)h_alloc(3 * 4);
    A[0] = 0xA1; A[1] = 0xA2; A[2] = 0xA3;
    uint32_t *slots = zero_slots(3);
    s->local_tpe = (uint32_t)(uintptr_t)A;
    s->bitmaps = (uint32_t)(uintptr_t)slots;
    s->bitmap_count = 3;
    s->owns_local_tpe = 1;
    g_cur_s = s; g_free_hook = hook_shrink_count;

    CSprite_Clear(s);
    g_free_hook = 0; g_cur_s = 0;

    {
        const uint32_t want[] = { 0xA1u, (uint32_t)(uintptr_t)A,
                                  (uint32_t)(uintptr_t)slots, 0u };
        if (!free_seq_is(want, 4)) { dump_free_seq(); fail("count shrink 3->0 must stop after 1 entry"); return; }
    }
}

/* T6 借用路径：0x36==0 → 一条 TPE 都不释放，0x54 仍被丢弃。 */
static void t_tpe_borrowed(void)
{
    CSprite *s = new_obj();
    uint32_t *A = (uint32_t *)h_alloc(2 * 4);
    A[0] = 0xA1; A[1] = 0xA2;
    uint32_t *slots = zero_slots(2);
    s->local_tpe = (uint32_t)(uintptr_t)A;
    s->bitmaps = (uint32_t)(uintptr_t)slots;
    s->bitmap_count = 2;
    s->owns_local_tpe = 0;
    CSprite_Clear(s);
    {
        const uint32_t want[] = { (uint32_t)(uintptr_t)slots, 0u };
        if (!free_seq_is(want, 2)) { dump_free_seq(); fail("borrowed: no entry/table free"); return; }
    }
    CHK(s->local_tpe == 0, "borrowed pointer still dropped");
    CHK(s->owns_local_tpe == 0, "owns stays 0");
}

/* T7 0x54==0 且 0x36==1：整块被跳过 → 0x36 保持 1（原件不写 0x1e6ca0）。
 *    这条同时钉住 docs/01 的后置条件例外；无条件清 0x36 的实现在此失败。 */
static void t_tpe_null_table_owner_flag(void)
{
    CSprite *s = new_obj();
    uint32_t *slots = zero_slots(5);
    s->local_tpe = 0;
    s->bitmaps = (uint32_t)(uintptr_t)slots;
    s->bitmap_count = 5;
    s->owns_local_tpe = 1;
    CSprite_Clear(s);
    {
        const uint32_t want[] = { (uint32_t)(uintptr_t)slots, 0u };
        if (!free_seq_is(want, 2)) { dump_free_seq(); fail("null table: only the two unconditional frees"); return; }
    }
    CHK(s->owns_local_tpe == 1, "0x36 must stay 1 when 0x54 was null");
}

/* T8 位图：第 1 个 D0 回调把 0x48 换成另一数组 → 零写与下一轮取元素都必须用新基址。
 *    缓存数组基址的变异体 M2 会清旧表 A[0] 并读旧表 A[1]。 */
static CSprite *g_bmp_s;
static uint32_t *g_bmp_swap_to;
static void hook_swap_bitmaps(uint32_t id)
{
    if (id == 1u && g_bmp_swap_to) { g_bmp_s->bitmaps = (uint32_t)(uintptr_t)g_bmp_swap_to; g_bmp_swap_to = 0; }
}
static void t_bmp_base_reread(void)
{
    CSprite *s = new_obj();
    struct fake_bmp *p1 = new_bmp(1), *p2 = new_bmp(2);
    uint32_t *A = (uint32_t *)h_alloc(2 * 4);
    uint32_t *B = (uint32_t *)h_alloc(2 * 4);
    A[0] = (uint32_t)(uintptr_t)p1; A[1] = (uint32_t)(uintptr_t)p2;
    B[0] = (uint32_t)(uintptr_t)p1; B[1] = (uint32_t)(uintptr_t)p2;
    s->bitmaps = (uint32_t)(uintptr_t)A;
    s->bitmap_count = 2;
    g_bmp_s = s; g_bmp_swap_to = B; g_d0_hook = hook_swap_bitmaps;

    CSprite_Clear(s);
    g_d0_hook = 0; g_bmp_s = 0;

    CHK(ev_count(EV_D0) == 2, "two D0 calls");
    CHK(A[0] == (uint32_t)(uintptr_t)p1, "old array slot must NOT be zeroed (base was reloaded)");
    CHK(B[0] == 0 && B[1] == 0, "new array slots must be zeroed via reloaded base");
    CHK(s->bitmaps == 0, "0x48 zeroed at the end");
}

/* T9 位图：第 1 个 D0 回调把 0x44 从 1 改成 2 → 必须再析构第 2 个槽。 */
static void hook_grow_bmp(uint32_t id)
{
    if (id == 1u) g_bmp_s->bitmap_count = 2;
}
static void t_bmp_count_grow(void)
{
    CSprite *s = new_obj();
    struct fake_bmp *p1 = new_bmp(1), *p2 = new_bmp(2);
    uint32_t *A = (uint32_t *)h_alloc(2 * 4);
    A[0] = (uint32_t)(uintptr_t)p1; A[1] = (uint32_t)(uintptr_t)p2;
    s->bitmaps = (uint32_t)(uintptr_t)A;
    s->bitmap_count = 1;
    g_bmp_s = s; g_d0_hook = hook_grow_bmp;

    CSprite_Clear(s);
    g_d0_hook = 0; g_bmp_s = 0;

    CHK(ev_count(EV_D0) == 2, "count growth 1->2 must destroy the second slot");
    CHK(A[0] == 0 && A[1] == 0, "both slots zeroed");
    CHK(!g_d1_called, "slot 0 (D1) must never be called");
}

/* T10 全量对象：完整调用序列 + 后置条件 + 未触碰字段。 */
static void t_full_order_and_post(void)
{
    CSprite *s = new_obj();
    struct fake_bmp *p1 = new_bmp(11), *p2 = new_bmp(12);
    uint32_t *tpe = (uint32_t *)h_alloc(2 * 4);
    uint32_t *bmp = (uint32_t *)h_alloc(2 * 4);
    int32_t  *tex = (int32_t *)h_alloc(2 * 4);
    tpe[0] = 0x5401; tpe[1] = 0x5402;
    bmp[0] = (uint32_t)(uintptr_t)p1; bmp[1] = (uint32_t)(uintptr_t)p2;
    tex[0] = 5; tex[1] = -1;

    s->type = 1;
    s->swf_objects = 0x7001; s->swf_object_count = 1; s->swf_dictionary = 0x7002;
    s->skeleton = 0x8000;
    s->local_tpe = (uint32_t)(uintptr_t)tpe; s->owns_local_tpe = 1; s->bitmap_count = 2;
    s->bitmaps = (uint32_t)(uintptr_t)bmp;
    s->texture_ids = (uint32_t)(uintptr_t)tex; s->texture_count = 2;
    s->has_mask = 1; s->mask_count = 2; s->mask_rows = 0x9000;
    s->bbox[0] = 1; s->bbox[1] = 2; s->bbox[2] = 3; s->bbox[3] = 4;
    s->field_5c = 0x5C; s->field_60 = 0x60;
    s->width = 99; s->height = 98;

    CSprite_Clear(s);

    /* 期望：SWF, D2, DEL(+FREE skel), FREE(tpe0), FREE(tpe1), FREE(tpe),
     *       D0(11), FREE(p1), D0(12), FREE(p2), FTEX, FREE(bmp), FREE(tex), FMASK */
    {
        const int want_k[] = { EV_SWF, EV_D2, EV_DEL, EV_FREE, EV_FREE, EV_FREE,
                               EV_FREE, EV_D0, EV_FREE, EV_D0, EV_FREE, EV_FTEX,
                               EV_FREE, EV_FREE, EV_FMASK };
        const int n = (int)(sizeof want_k / sizeof want_k[0]);
        int ok = (g_ev_n == n);
        for (int i = 0; ok && i < n; ++i) ok = (g_ev_kind[i] == want_k[i]);
        if (!ok) {
            h_puts("    got:");
            for (int i = 0; i < g_ev_n; ++i) { h_puts(" "); h_putint(g_ev_kind[i]); }
            h_puts("\n");
            fail("call sequence mismatch");
            return;
        }
    }
    {
        const uint32_t want[] = { 0x8000u, 0x5401u, 0x5402u, (uint32_t)(uintptr_t)tpe,
                                  (uint32_t)(uintptr_t)p1, (uint32_t)(uintptr_t)p2,
                                  (uint32_t)(uintptr_t)bmp, (uint32_t)(uintptr_t)tex };
        if (!free_seq_is(want, 8)) { dump_free_seq(); fail("free argument sequence"); return; }
    }
    CHK(g_ev_arg[ev_nth_kind(EV_D0, 0)] == 11u && g_ev_arg[ev_nth_kind(EV_D0, 1)] == 12u, "D0 ids");
    CHK(bmp[0] == 0 && bmp[1] == 0, "bitmap slots zeroed");
    CHK(!g_d1_called, "D1 never called");
    CHK(reset_ok(s), "field postconditions");
    CHK(untouched_ok(s), "untouched fields");
    CHK(f32_bits(s->field_6c) == 0x41F00000u, "0x6c float 30.0f untouched");
    CHK(s->has_mask == 1 && s->mask_count == 2 && s->mask_rows == 0x9000,
        "mask fields are FreeMask's business; stub must not change them");
}

/* T11 二次 Clear：幂等，不得二次释放。 */
static void t_idempotent(void)
{
    CSprite *s = new_obj();
    struct fake_bmp *p1 = new_bmp(21);
    uint32_t *bmp = (uint32_t *)h_alloc(1 * 4);
    bmp[0] = (uint32_t)(uintptr_t)p1;
    s->bitmaps = (uint32_t)(uintptr_t)bmp; s->bitmap_count = 1;
    CSprite_Clear(s);
    reset_log();
    CSprite_Clear(s);
    {
        const uint32_t want[] = { 0u, 0u };
        if (!free_seq_is(want, 2)) { dump_free_seq(); fail("second Clear must only Free(NULL) x2"); return; }
    }
    CHK(ev_count(EV_D0) == 0 && ev_count(EV_D2) == 0, "no destructor on the second run");
    CHK(reset_ok(s), "still reset");
}

/* T12 全空对象：只有两个无条件 Free(NULL)，无析构。 */
static void t_empty(void)
{
    CSprite *s = new_obj();
    CSprite_Clear(s);
    {
        const uint32_t want[] = { 0u, 0u };
        if (!free_seq_is(want, 2)) { dump_free_seq(); fail("empty object: Free(NULL) x2"); return; }
    }
    CHK(ev_count(EV_D2) == 0 && ev_count(EV_DEL) == 0 && ev_count(EV_D0) == 0 && ev_count(EV_SWF) == 0,
        "no destructor calls on an empty object");
    CHK(ev_count(EV_FTEX) == 1 && ev_count(EV_FMASK) == 1, "FreeTexture/FreeMask always called");
    CHK(reset_ok(s) && untouched_ok(s), "postconditions");
}

/* T13: Free(bitmap table) may change +0x50; the following Free must use
 * the post-callback value, not the stale value captured before the call. */
static void hook_swap_texture_ids(uint32_t p)
{
    if (p == 0x1110u) g_cur_s->texture_ids = 0x3330u;
}
static void t_texture_ids_reread(void)
{
    CSprite *s = new_obj();
    s->bitmaps = 0x1110u;
    s->texture_ids = 0x2220u;
    g_cur_s = s; g_free_hook = hook_swap_texture_ids;
    CSprite_Clear(s);
    g_free_hook = 0; g_cur_s = 0;
    const uint32_t want[] = { 0x1110u, 0x3330u };
    if (!free_seq_is(want, 2)) { dump_free_seq(); fail("texture_ids must be read after bitmap free"); }
}

/* ------------------------------------------------------------- runner */
struct tcase { const char *name; void (*fn)(void); int needs_low_code; };
static const struct tcase g_tests[] = {
    { "T1_type_gate",              t_type_gate,             0 },
    { "T2_skeleton_d2_then_delete",t_skeleton,              0 },
    { "T3_tpe_base_reread",        t_tpe_base_reread,       0 },
    { "T4_tpe_count_grow",         t_tpe_count_grow,        0 },
    { "T5_tpe_count_shrink",       t_tpe_count_shrink,      0 },
    { "T6_tpe_borrowed",           t_tpe_borrowed,          0 },
    { "T7_tpe_null_table_owns",    t_tpe_null_table_owner_flag, 0 },
    { "T8_bmp_base_reread",        t_bmp_base_reread,       1 },
    { "T9_bmp_count_grow",         t_bmp_count_grow,        1 },
    { "T10_full_order_post",       t_full_order_and_post,   1 },
    { "T11_idempotent",            t_idempotent,            1 },
    { "T12_empty",                 t_empty,                 0 },
    { "T13_texture_ids_reread",    t_texture_ids_reread,    0 },
};

static int harness_main(void)
{
    int fails = 0, skips = 0;
    arena_init();
    vt_init();
    for (unsigned i = 0; i < sizeof g_tests / sizeof g_tests[0]; ++i) {
        if (g_tests[i].needs_low_code && !LOW_CODE) {
            h_puts("SKIP  ");
            h_puts(g_tests[i].name);
            h_puts("  (host code addresses > 4GiB; run the ARM32 build for this path)\n");
            ++skips;
            continue;
        }
        g_test_failed = 0;
        g_ev_n = 0;
        g_free_hook = 0; g_d0_hook = 0;
        g_d1_called = 0; g_d1_short_circuit = 0;
        g_cur_s = 0; g_swap_to = 0; g_bmp_s = 0; g_bmp_swap_to = 0;
        g_tests[i].fn();
        if (g_test_failed) { ++fails; h_puts("FAIL  "); }
        else { h_puts("PASS  "); }
        h_puts(g_tests[i].name);
        h_puts("\n");
    }
    h_puts("summary: ");
    h_putint((int)(sizeof g_tests / sizeof g_tests[0]) - fails - skips);
    h_puts(" passed, ");
    h_putint(skips);
    h_puts(" skipped, ");
    h_putint(fails);
    h_puts(" failed\n");
    return fails;
}

#if HF
void _start(void)
{
    h_exit(harness_main());
}
#else
int main(void) { return harness_main(); }
#endif
