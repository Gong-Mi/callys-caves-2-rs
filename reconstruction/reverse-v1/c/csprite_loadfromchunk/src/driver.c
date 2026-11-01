/* driver.c — CSprite::LoadFromChunk 译文的**自洽**测试（不是原版行为等价测试）
 *
 * 每个用例：在低地址 arena 里拼一张 WAD 影像 → 调 CSprite_LoadFromChunk →
 * 检查 CSprite 落位、WAD 指针回填、掩码块指针、依赖收到的实参。
 *
 * 期望值来源：
 *   · 字段落位 / 指针 / 掩码 —— 来自 asm 目录里的逐条注解；
 *   · 半径 —— 按「int32 平方 → float32 相加 → sqrtf → ceilf」在 Python 里独立算
 *     （notes/radius-vectors.txt），与本文件里的常量一一对应。
 * 这些期望值不是「运行原版测出来的」：原件从未执行。
 *
 * 两条构建：
 *   · host（不定义 HARNESS_FREESTANDING）：用 libc/libm，arena 走 mmap 固定映射；
 *   · ARM32（-DHARNESS_FREESTANDING -nostdlib -static）：qemu-arm 跑，与原件同一
 *     AAPCS/softfp ABI，指针槽天然 4 B。
 *
 * ★ 本套件**不做任何无效内存访问**：count>0 且分配为 NULL 的那条「写表基址」
 *   路径（原版 0x1e99ac）不在默认用例里执行；只验证它的两个前提（闸给出的长度、
 *   分配返回 NULL），崩溃本身记为不可证路径（见 README）。
 */
#include <stddef.h>
#include <stdint.h>

#include "csprite_loadfromchunk.h"
#include "test_doubles.h"

/* ── 输出 ─────────────────────────────────────────────────────────────── */
#if defined(HARNESS_FREESTANDING)
static long h_sys3(long n, long a, long b, long c)
{
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    register long r7 __asm__("r7") = n;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r7) : "memory");
    return r0;
}
static void h_exit(int code) { h_sys3(1, code, 0, 0); for (;;) { } }
static void h_write(const char *s, unsigned n) { h_sys3(4, 1, (long)s, (long)n); }
#else
#include <stdio.h>
#include <stdlib.h>
static void h_exit(int code) { exit(code); }
static void h_write(const char *s, unsigned n) { fwrite(s, 1, n, stdout); fflush(stdout); }
#endif

static void h_puts(const char *s) { unsigned n = 0; while (s[n]) ++n; h_write(s, n); }
static void h_putint(int v)
{
    char b[12];
    int i = 11, neg = v < 0;
    unsigned u = neg ? (unsigned)(-(v + 1)) + 1u : (unsigned)v;
    b[i] = 0;
    do { b[--i] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) b[--i] = '-';
    h_puts(&b[i]);
}
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

/* ── 断言 ─────────────────────────────────────────────────────────────── */
static int g_case_failed;
static int g_checks;
static const char *g_case = "?";

static void fail(const char *what, uint32_t a, uint32_t b)
{
    if (!g_case_failed) {
        h_puts("      first failure: ");
        h_puts(what);
        h_puts(" got="); h_puthex(a);
        h_puts(" want="); h_puthex(b);
        h_puts("\n");
    }
    g_case_failed = 1;
}

#define CHECK(cond) do { g_checks++; if (!(cond)) fail(#cond, 0, 0); } while (0)
/* 一律先经 uintptr_t 再取低 32 位：这样指针实参也能比，且不触发
 * pointer-to-int-cast 警告（32 位 ABI 下这个截断正是原件的行为）。 */
#define CHECK_EQ(a, b) do { g_checks++; \
    uint32_t va_ = (uint32_t)(uintptr_t)(a), vb_ = (uint32_t)(uintptr_t)(b); \
    if (va_ != vb_) fail(#a, va_, vb_); } while (0)

/* ── WAD 影像（低地址 arena）───────────────────────────────────────────── */
#define IMG_SIZE 1024
static unsigned char *g_img;

/* 只重置夹具与记账，不动 g_case_failed（一个用例内做多段时用）*/
static void fresh(void)
{
    td_fixture_reset();
    g_img = (unsigned char *)td_fixture_alloc(IMG_SIZE);
    td_reset();
    if (!g_img) { h_puts("FATAL arena\n"); h_exit(91); }
    for (int i = 0; i < IMG_SIZE; ++i) g_img[i] = 0xEE;
    g_pWADBaseAddress = g_img;
    g_isZeus = 0;
}

static void begin(const char *name)
{
    g_case = name;
    g_case_failed = 0;
    fresh();
}

static void end(void)
{
    if (g_case_failed) { h_puts("FAIL  "); } else { h_puts("PASS  "); }
    h_puts(g_case);
    h_puts("\n");
}

static YYSprite *yy(void) { return (YYSprite *)g_img; }

static void wr32(unsigned off, uint32_t v) { memcpy(g_img + off, &v, 4); }
static uint32_t rdidx32(const void *p) { uint32_t v; memcpy(&v, p, 4); return v; }

/* 默认头：宽 32 高 48、原点 8/12、若干可区分的配置值 */
static void head(int32_t w, int32_t h, int32_t ox, int32_t oy, int32_t count)
{
    yy()->width = w;
    yy()->height = h;
    yy()->bboxLeft = 0x11111111;
    yy()->bboxRight = 0x22222222;
    yy()->bboxBottom = 0x33333333;
    yy()->bboxTop = 0x44444444;
    yy()->transparent = 0x100;      /* 非 0 也不是 1：验证 (x != 0) 归一化 */
    yy()->smooth = 0;
    yy()->preload = -7;
    yy()->bboxMode = 2;
    yy()->sepMasks = 1;
    yy()->originX = ox;
    yy()->originY = oy;
    yy()->textureCount = count;
}

static uint32_t table_at(const CSprite *s, unsigned i)
{
    return *(const uint32_t *)(uintptr_t)(uint32_t)(s->local_tpe + i * 4u);
}

/* ══════════════════════════════ 用例 ══════════════════════════════════ */

/* T01 主路径：3 帧 + 3 掩码 */
static void t01(void)
{
    CSprite s;
    begin("T01 main 3frames/mask=3");
    head(32, 48, 8, 12, 3);
    wr32(0x3c, 0x100);          /* 帧 0 → g_pWADBaseAddress + 0x100 */
    wr32(0x40, 0);              /* 帧 1 → 0 ⇒ NULL */
    wr32(0x44, 0x200);          /* 帧 2 → +0x200 */
    wr32(0x48, 3);              /* maskCount */
    wr32(0x4c, 0xAAAA5555);     /* 掩码块头（内容无关） */
    CHECK_EQ(CSprite_LoadFromChunk(&s, yy(), g_img), 1);

    CHECK_EQ(td.clear_calls, 1);
    CHECK_EQ(s.frame_count, 3);
    CHECK_EQ(s.width, 32);
    CHECK_EQ(s.height, 48);
    CHECK_EQ(s.field_24, 8);
    CHECK_EQ(s.field_28, 12);
    CHECK_EQ(s.bbox_mode, 2);
    /* 四格落位是「交叉」的：YY(left,right,bottom,top) → bbox[0..3] = 0x08,0x0c,0x10,0x14 */
    CHECK_EQ(s.bbox[0], 0x11111111);
    CHECK_EQ(s.bbox[1], 0x44444444);
    CHECK_EQ(s.bbox[2], 0x22222222);
    CHECK_EQ(s.bbox[3], 0x33333333);
    CHECK_EQ(s.flag_32, 1);
    CHECK_EQ(s.flag_33, 0);
    CHECK_EQ(s.flag_34, 1);
    CHECK_EQ(s.flag_30, 1);
    CHECK_EQ(s.type, 0);
    CHECK_EQ(s.field_78, 0);
    CHECK_EQ(s.field_2c, 44);            /* corners 15,27,37,44 */
    CHECK_EQ(td.new_array_calls, 1);
    CHECK_EQ(td.new_array_size, 12);
    CHECK_EQ(td.new_scalar_calls, 0);
    CHECK(s.local_tpe != 0);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x100);
    CHECK_EQ(table_at(&s, 1), 0);
    CHECK_EQ(table_at(&s, 2), (uint32_t)(uintptr_t)g_img + 0x200);
    CHECK_EQ(s.field_64, 3);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x4c);
    CHECK_EQ(s.flag_35, 1);
    CHECK_EQ(td.build_calls, 0);
    CHECK_EQ(td.skel_calls, 0);
    end();
}

/* T02 maskCount=2 < count=3 ⇒ +0x35 = 0 */
static void t02(void)
{
    CSprite s;
    begin("T02 mask=2 < count=3");
    head(32, 48, 8, 12, 3);
    wr32(0x3c, 0x100); wr32(0x40, 0x104); wr32(0x44, 0x108);
    wr32(0x48, 2);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_64, 2);
    CHECK_EQ(s.flag_35, 0);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x4c);
    end();
}

/* T03 maskCount=0 ⇒ +0x68=0，+0x35 一个字节都不写 */
static void t03(void)
{
    CSprite s;
    begin("T03 mask=0 keeps +0x35");
    head(32, 48, 8, 12, 2);
    wr32(0x3c, 0x100); wr32(0x40, 0x104); wr32(0x44, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_64, 0);
    CHECK_EQ(s.field_68, 0);
    CHECK_EQ(s.flag_35, 0xAA);           /* 替身 Clear 的哨兵原样保留 ⇒ 未被写 */
    CHECK_EQ(s.field_2c, 44);
    end();
}

/* T04 maskCount=-5 ⇒ 同 T03（有符号比较） */
static void t04(void)
{
    CSprite s;
    begin("T04 mask=-5");
    head(32, 48, 8, 12, 2);
    wr32(0x3c, 0x100); wr32(0x40, 0x104); wr32(0x44, (uint32_t)-5);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_64, (uint32_t)-5);
    CHECK_EQ(s.field_68, 0);
    CHECK_EQ(s.flag_35, 0xAA);
    end();
}

/* T05 zeus && 头里 count==0 ⇒ 尾部多读一个 dword 作 count */
static void t05(void)
{
    CSprite s;
    begin("T05 zeus count in tail");
    g_isZeus = 1;
    head(32, 48, 8, 12, 0);
    wr32(0x3c, 2);              /* 真 count */
    wr32(0x40, 0x180);
    wr32(0x44, 0x184);
    wr32(0x48, 1);              /* maskCount */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.frame_count, 2);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x180);
    CHECK_EQ(table_at(&s, 1), (uint32_t)(uintptr_t)g_img + 0x184);
    CHECK_EQ(s.field_64, 1);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x4c);
    CHECK_EQ(s.flag_35, 0);
    end();
}

/* T06 zeus && 头里 count!=0 ⇒ 不吃额外 dword */
static void t06(void)
{
    CSprite s;
    begin("T06 zeus count in header");
    g_isZeus = 1;
    head(32, 48, 8, 12, 2);
    wr32(0x3c, 0x180);
    wr32(0x40, 0x184);
    wr32(0x44, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.frame_count, 2);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x180);
    CHECK_EQ(s.field_64, 0);
    CHECK_EQ(td.new_array_size, 8);
    end();
}

/* T07 count==0（非 zeus）⇒ new[](0) 返回 NULL，掩码块从 YY+0x3c 起 */
static void t07(void)
{
    CSprite s;
    begin("T07 count=0 non-zeus");
    head(32, 48, 8, 12, 0);
    wr32(0x3c, 0x1234);         /* 这里被当 maskCount 读 */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.new_array_size, 0);
    CHECK_EQ(td.new_array_null, 1);
    CHECK_EQ(s.local_tpe, 0);
    CHECK_EQ(s.field_64, 0x1234);
    CHECK_EQ(s.flag_35, 0);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x40);
    end();
}

/* T08 count=-2 ⇒ 闸给 0xFFFFFFFF；掩码索引是 32 位左移：YY+0x3c-8 = YY+0x34 */
static void t08(void)
{
    CSprite s;
    begin("T08 count=-2 guard+neg index");
    head(32, 48, 8, 0x55, -2);  /* YY+0x34 = 0x55 ⇒ maskCount */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.new_array_size, 0xFFFFFFFFu);
    CHECK_EQ(s.local_tpe, 0);           /* Alloc(0xFFFFFFFF) ⇒ NULL，不抛 */
    CHECK_EQ(s.field_64, 0x55);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x38);
    CHECK_EQ(s.flag_35, 0);             /* 0x55 != -2 */
    end();
}

/* T09 长度闸边界（0x1FC00000 / +1）——只在 helper 层测，不加载整个函数。
 * 理由：count 取这两个值时 count>0 恒成立，函数体会进回填循环去写 0x7F000000 个
 * 槽位；本套件不做无效写，所以「函数级边界」记为不可证路径（README），这里钉的
 * 是 0x1e9814..0x1e9824 一对一外提出来的 yy_new_array_checked。 */
static void t09(void)
{
    begin("T09 gate boundary (helper)");
    CHECK_EQ(yy_new_array_checked(0x1FC00000), 0);   /* 闸内：长度 0x7F000000 */
    CHECK_EQ(td.new_array_size, 0x7F000000u);
    CHECK_EQ(td.new_array_null, 1);                   /* 替身 arena 装不下 ⇒ NULL */
    td_reset();
    CHECK_EQ(yy_new_array_checked(0x1FC00001), 0);   /* 闸外：长度 0xFFFFFFFF */
    CHECK_EQ(td.new_array_size, 0xFFFFFFFFu);
    CHECK_EQ(td.new_array_null, 1);
    td_reset();
    CHECK(yy_new_array_checked(3) != 0);              /* 正常值仍是 count*4 */
    CHECK_EQ(td.new_array_size, 12);
    end();
}

/* T10 kind==1（textureCount==-1 且 YY+0x40==1），v<=7：data = tail+4 */
static void t10(void)
{
    CSprite s;
    begin("T10 kind1 short form");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 1);              /* kind */
    wr32(0x44, 3);              /* v = 3 <= 7 */
    wr32(0x48, 0xCAFE);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.type, 1);
    CHECK_EQ(s.local_tpe, 0);
    CHECK_EQ(s.field_78, 1);
    CHECK_EQ(td.build_calls, 1);
    CHECK_EQ(td.build_data, (uint32_t)(uintptr_t)g_img + 0x48);
    CHECK_EQ(td.build_w, 8);
    CHECK_EQ(td.build_h, 12);
    CHECK_EQ(td.new_array_calls, 0);
    end();
}

/* T11 kind==1，v=8>7：n=tail[1]、建表、data = tail+8+n*4 */
static void t11(void)
{
    CSprite s;
    begin("T11 kind1 table form");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 1);
    wr32(0x44, 9);              /* v = 9 > 7 */
    wr32(0x48, 2);              /* n = 2 */
    wr32(0x4c, 0x40);           /* 表项 0 */
    wr32(0x50, 0x80);           /* 表项 1 */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.new_array_size, 8);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x40);
    CHECK_EQ(table_at(&s, 1), (uint32_t)(uintptr_t)g_img + 0x80);
    CHECK_EQ(td.build_data, (uint32_t)(uintptr_t)g_img + 0x54);  /* 0x44+8+2*4 */
    CHECK_EQ(s.field_78, 1);
    CHECK_EQ(td.build_w, 8);
    end();
}

/* T12 kind==2：骨骼分支 */
static void t12(void)
{
    CSprite s;
    begin("T12 kind2 skeleton");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 2);
    wr32(0x44, 0x11); wr32(0x48, 0x22); wr32(0x4c, 0x33);
    wr32(0x50, 0x44); wr32(0x54, 0x55); wr32(0x58, 0x66);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.type, 2);
    CHECK_EQ(s.local_tpe, 0);
    CHECK_EQ(td.new_scalar_calls, 1);
    CHECK_EQ(td.new_scalar_size, 12);
    CHECK_EQ(s.skeleton, td.new_scalar_ptr32);
    CHECK_EQ(s.frame_count, 0x7FFFFFFF);
    CHECK_EQ(td.skel_calls, 1);
    CHECK_EQ(td.skel_name, (uint32_t)(uintptr_t)g_img + 0x44 + 24); /* cur+24 */
    CHECK_EQ(td.skel_a, 0x22);  /* cur = YY+0x44；cur[1] = YY+0x48 */
    CHECK_EQ(td.skel_b, 0x33);
    CHECK_EQ(td.skel_c, 0x44);
    CHECK_EQ(td.skel_d, 0x55);
    CHECK_EQ(td.skel_e, 0x66);
    end();
}

/* T13 kind ∉ {0,1,2}：什么都不建 */
static void t13(void)
{
    CSprite s;
    begin("T13 kind3 nothing built");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 3);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.type, 3);
    CHECK_EQ(s.frame_count, 0);
    CHECK_EQ(td.new_array_calls, 0);
    CHECK_EQ(td.new_scalar_calls, 0);
    CHECK_EQ(td.build_calls, 0);
    CHECK_EQ(td.skel_calls, 0);
    end();
}

/* T14 special + zeus：尾部从 YY+0x4c 开始，+0x6c/+0x70 = YY+0x44/0x48 的**裸位型** */
static void t14(void)
{
    CSprite s;
    begin("T14 special zeus tail+bits");
    g_isZeus = 1;
    head(32, 48, 8, 12, -1);
    wr32(0x40, 0);
    wr32(0x44, 0x7FC00001u);    /* NaN 位型：若译文写浮点赋值，这里会被改掉 */
    wr32(0x48, 0x12345678);
    wr32(0x4c, 2);              /* count（zeus 时尾部从 0x4c 起） */
    wr32(0x50, 0x300);
    wr32(0x54, 0x304);
    wr32(0x58, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(rdidx32(&s.field_6c), 0x7FC00001u);
    CHECK_EQ(rdidx32(&s.field_70), 0x12345678u);
    CHECK_EQ(s.frame_count, 2);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x300);
    CHECK_EQ(s.field_64, 0);    /* 掩码计数读自 YY+0x4c+8 = 0x54 */
    end();
}

/* T15 special + 非 zeus：尾部从 YY+0x44 起（比 zeus 少两个 dword），
 * 且 +0x6c/+0x70 不被写。用 kind==1 的短格式来观测游标起点：
 * data = cur+4，所以 build_data 直接指出 cur。 */
static void t15(void)
{
    CSprite s;
    begin("T15 special non-zeus tail");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 1);              /* kind=1 */
    wr32(0x44, 3);              /* v=3 <= 7 ⇒ 短格式 */
    wr32(0x48, 0xCAFE);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.build_data, (uint32_t)(uintptr_t)g_img + 0x48);  /* 0x44 + 4 */
    CHECK_EQ(rdidx32(&s.field_6c), 0);   /* Clear 清 0 后没人再写 */
    CHECK_EQ(rdidx32(&s.field_70), 0);
    CHECK_EQ(s.frame_count, 0);          /* 特殊分支无条件先把子图数清 0 */
    end();
}

/* T16 半径 3-4-5 */
static void t16(void)
{
    CSprite s;
    begin("T16 radius 3-4-5");
    head(3, 4, 3, 4, 0);
    wr32(0x3c, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_2c, 5);
    end();
}

/* T17 半径：四角取最大（10×10，原点 0,0 ⇒ ceil(sqrt(200))=15） */
static void t17(void)
{
    CSprite s;
    begin("T17 radius max of four");
    head(10, 10, 0, 0, 0);
    wr32(0x3c, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_2c, 15);
    end();
}

/* T18 半径：46341² 负和 ⇒ NaN ⇒ 该角 0（REVIEW 点名的可达 NaN） */
static void t18(void)
{
    CSprite s;
    begin("T18 radius 46341 NaN corner");
    head(46341, 0, 46341, 0, 0);
    wr32(0x3c, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    /* 角1 sqrt(-2147479015+0)=NaN→0；dw=0,dh=0 ⇒ 其余角 0 */
    CHECK_EQ(s.field_2c, 0);
    end();
}

/* T19 半径：100×100 原点 100,100 ⇒ ceil(sqrt(20000)) = 142 */
static void t19(void)
{
    CSprite s;
    begin("T19 radius 100 square");
    head(100, 100, 100, 100, 0);
    wr32(0x3c, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(s.field_2c, 142);
    end();
}

/* T20 pWAD 是死参数：NULL 与 g_img 得到同一份状态 */
static void t20(void)
{
    CSprite a, b;
    int same = 1;
    begin("T20 pWAD dead parameter");
    head(32, 48, 8, 12, 3);
    wr32(0x3c, 0x100); wr32(0x40, 0); wr32(0x44, 0x200); wr32(0x48, 3);
    (void)CSprite_LoadFromChunk(&a, yy(), g_img);
    (void)CSprite_LoadFromChunk(&b, yy(), NULL);

    same &= a.bbox_mode == b.bbox_mode;
    same &= a.bbox[0] == b.bbox[0] && a.bbox[1] == b.bbox[1];
    same &= a.bbox[2] == b.bbox[2] && a.bbox[3] == b.bbox[3];
    same &= a.frame_count == b.frame_count;
    same &= a.width == b.width && a.height == b.height;
    same &= a.field_24 == b.field_24 && a.field_28 == b.field_28;
    same &= a.field_2c == b.field_2c;
    same &= a.flag_30 == b.flag_30 && a.flag_32 == b.flag_32;
    same &= a.flag_33 == b.flag_33 && a.flag_34 == b.flag_34;
    same &= a.flag_35 == b.flag_35;
    same &= a.field_64 == b.field_64 && a.field_68 == b.field_68;
    same &= rdidx32(&a.field_6c) == rdidx32(&b.field_6c);
    same &= a.field_70 == b.field_70 && a.type == b.type && a.field_78 == b.field_78;
    for (unsigned k = 0; k < 3; ++k)
        same &= table_at(&a, k) == table_at(&b, k);
    CHECK(same);
    end();
}

/* T21 vcvt helper 的可达域语义 + 死分支合同 */
static void t21(void)
{
    begin("T21 vcvt contract");
    CHECK_EQ(yy_vcvt_s32_f32(2.9f), 2);
    CHECK_EQ(yy_vcvt_s32_f32(-2.9f), (uint32_t)-2);
    CHECK_EQ(yy_vcvt_s32_f32(65536.0f), 65536);
    {
        float zero = 0.0f;
        float nan = zero / zero;
        CHECK_EQ(yy_vcvt_s32_f32(nan), 0);
    }
    CHECK_EQ(yy_vcvt_s32_f32(3.0e9f), 0x80000000u);
    CHECK_EQ(yy_vcvt_s32_f32(-3.0e9f), 0x80000000u);
    end();
}

/* T22 分配之后**重读 this+0x18**：钩子把 count 改成 2，循环上界与掩码偏移都要跟着变 */
static CSprite *g_hook_sprite;
static void hook_shrink(void) { g_hook_sprite->frame_count = 2; }

static void t22(void)
{
    CSprite s;
    begin("T22 count re-read after alloc");
    head(32, 48, 8, 12, 3);
    wr32(0x3c, 0x100); wr32(0x40, 0x200); wr32(0x44, 0x300);
    wr32(0x48, 7);              /* 若不重读，掩码计数会从这里读 */
    g_hook_sprite = &s;
    td_alloc_hook = hook_shrink;
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    td_alloc_hook = 0;
    CHECK_EQ(td.alloc_hook_calls, 1);
    CHECK_EQ(s.frame_count, 2);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x100);
    CHECK_EQ(table_at(&s, 1), (uint32_t)(uintptr_t)g_img + 0x200);
    /* 掩码计数读自 cur + (2<<2) = YY+0x3c+8 = 0x44 ⇒ 0x300（不是 0x48 的 7） */
    CHECK_EQ(s.field_64, 0x300);
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x48);
    end();
}

/* T23 32 位偏移：count=0xC0000001 ⇒ (uint32)count<<2 = 4，读 YY+0x40（在界内） */
static void t23(void)
{
    CSprite s;
    begin("T23 offset32 0xC0000001 -> +4");
    CHECK_EQ(yy_offset32(-2), 0xFFFFFFF8u);
    CHECK_EQ(yy_offset32((int32_t)0xC0000001u), 4u);
    head(32, 48, 8, 12, (int32_t)0xC0000001u);
    wr32(0x40, 7);
    wr32(0x44, 0x600d);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.new_array_size, 0xFFFFFFFFu);
    CHECK_EQ(s.local_tpe, 0);
    CHECK_EQ(s.field_64, 7);    /* *(YY+0x40) */
    CHECK_EQ(s.field_68, (uint32_t)(uintptr_t)g_img + 0x44);
    CHECK_EQ(s.flag_35, 0);
    end();
}

/* T24 分配器的两个边界（不触碰 NULL 表写入） */
static void t24(void)
{
    begin("T24 allocator boundaries");
    CHECK_EQ(yy_new_array_checked(0), 0);
    {
        void *p = yy_new_array_checked(3);
        CHECK(p != 0);
        CHECK_EQ(yy_slot_get(td.new_array_ptr32) == p, 1);
        CHECK_EQ(td.new_array_size, 12);
    }
    /* count>0 且闸越界 ⇒ 长度 0xFFFFFFFF ⇒ 分配 NULL。这里只验证**闸与分配**，
     * 不执行后续的 NULL 表写入（那是一次无效写，见 README §不可证路径）。 */
    td_reset();
    CHECK_EQ(yy_new_array_checked(0x20000000), 0);
    CHECK_EQ(td.new_array_size, 0xFFFFFFFFu);
    CHECK_EQ(td.new_array_null, 1);
    end();
}

/* T25 重入：同一个对象再 Load 一次，必须先 Clear 再重建 */
static void t25(void)
{
    CSprite s;
    begin("T25 re-entry clears first");
    head(32, 48, 8, 12, 2);
    wr32(0x3c, 0x100); wr32(0x40, 0x200); wr32(0x44, 0);
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.clear_calls, 1);
    CHECK_EQ(s.field_64, 0);
    CHECK_EQ(s.flag_35, 0xAA);     /* maskCount<=0 ⇒ +0x35 根本不写 */

    head(64, 80, 1, 2, 1);
    wr32(0x3c, 0x300);
    wr32(0x40, 1);                 /* maskCount = 1 == count */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(td.clear_calls, 2);
    CHECK_EQ(s.frame_count, 1);
    CHECK_EQ(s.width, 64);
    CHECK_EQ(s.height, 80);
    CHECK_EQ(s.field_24, 1);
    CHECK_EQ(s.field_64, 1);
    CHECK_EQ(s.flag_35, 1);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x300);
    end();
}

/* T26 field_6c 是 float 类型但必须是**裸 32 位搬移**：非规格化位型原样保留 */
static void t26(void)
{
    CSprite s;
    begin("T26 field_6c bit-copy");
    g_isZeus = 1;
    head(32, 48, 8, 12, -1);
    wr32(0x40, 3);                 /* kind=3 ⇒ 立刻返回，只留下 +0x6c/+0x70 */
    wr32(0x44, 0x00000001u);       /* 最小非规格化数：若做浮点转换会被刷成 0 */
    wr32(0x48, 0xFFFFFFFFu);       /* 全 1 位型（NaN） */
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(rdidx32(&s.field_6c), 0x00000001u);
    CHECK_EQ(rdidx32(&s.field_70), 0xFFFFFFFFu);
    end();
}

/* Parent regression: the table is ARM32 slots even on a 64-bit host.
 * Guard is inside the mapped arena, so a wide store gives a named mismatch,
 * not an invalid-address crash. */
static void table_guard_hook(void)
{
    const uint32_t guard = 0x6A5BC7D8u;
    memcpy((void *)(uintptr_t)(td.new_array_ptr32 + td.new_array_size), &guard, 4);
}
static void t27(void)
{
    CSprite s;
    begin("T27 main table end guard");
    head(32, 48, 8, 12, 1);
    wr32(0x3c, 0x100); wr32(0x40, 0);
    td_alloc_hook = table_guard_hook;
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(rdidx32((const void *)(uintptr_t)(s.local_tpe + 4)), 0x6A5BC7D8u);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x100);
    end();
}
static void t28(void)
{
    CSprite s;
    begin("T28 swf table end guard");
    head(32, 48, 8, 12, -1);
    wr32(0x40, 1); wr32(0x44, 8); wr32(0x48, 1); wr32(0x4c, 0x100);
    td_alloc_hook = table_guard_hook;
    (void)CSprite_LoadFromChunk(&s, yy(), g_img);
    CHECK_EQ(rdidx32((const void *)(uintptr_t)(s.local_tpe + 4)), 0x6A5BC7D8u);
    CHECK_EQ(table_at(&s, 0), (uint32_t)(uintptr_t)g_img + 0x100);
    end();
}

/* ── 运行器 ───────────────────────────────────────────────────────────── */
typedef void (*test_fn)(void);
static const struct { const char *name; test_fn fn; } g_tests[] = {
    { "T01", t01 }, { "T02", t02 }, { "T03", t03 }, { "T04", t04 },
    { "T05", t05 }, { "T06", t06 }, { "T07", t07 }, { "T08", t08 },
    { "T09", t09 }, { "T10", t10 }, { "T11", t11 }, { "T12", t12 },
    { "T13", t13 }, { "T14", t14 }, { "T15", t15 }, { "T16", t16 },
    { "T17", t17 }, { "T18", t18 }, { "T19", t19 }, { "T20", t20 },
    { "T21", t21 }, { "T22", t22 }, { "T23", t23 }, { "T24", t24 },
    { "T25", t25 }, { "T26", t26 }, { "T27", t27 }, { "T28", t28 },
};

static int harness_main(void)
{
    int fails = 0;
    unsigned n = sizeof g_tests / sizeof g_tests[0];
    for (unsigned i = 0; i < n; ++i) {
        g_tests[i].fn();
        if (g_case_failed) ++fails;
    }
    h_puts("summary: ");
    h_putint((int)n - fails); h_puts(" passed, ");
    h_putint(fails); h_puts(" failed, ");
    h_putint(g_checks); h_puts(" checks\n");
    return fails;
}

#if defined(HARNESS_FREESTANDING)
void _start(void) { h_exit(harness_main()); }
#else
int main(void) { return harness_main(); }
#endif
