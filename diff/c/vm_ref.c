/* diff/c/vm_ref.c — C reference implementation for the milestone-1 opcode diff.
 *
 * tier: host_authored
 *
 * 这不是原版复制品。原版是 libyoyo.so 里的 32 个 Do* 汇编处理器（armv7）；
 * 本文件照 reconstruction/reverse-v1/cards/ 的逆向卡重写语义，用来和 Rust VM 逐字节
 * 差分。它不含原版机器码、不链接原版、不驱动原版进程；注释里的 @0x... 全是卡片抄录
 * 的指令地址，不是本文件生成的代码地址。
 *
 * 类比的卡片（语义权威）：
 *   cards/DoAdd.c            双操作数存储类 nibble、102 路分派、结果落点 off-w
 *   cards/DoAnd.c            10 条内核（含 bool 短路与）、实数走 __fixdfdi
 *   cards/DoConv.c           44 个转换叶、flags 三路、src=5 按 tag 改写
 *   cards/DoDiv.c            9 条内核、整数除零软错误、实数不判零
 *   cards/DoDup.c            n=(arg&0x7FFF)+1、宽度表、swap 模式
 *   cards/DoMod.c            __aeabi_idivmod 取余、1e-10 阈值、mode1 的 NaN 边角
 *   cards/DoMul.c            pair 6/38 字符串重复、9 条算术核
 *   cards/DoNeg.c            mode 0/1/2 三形态、cls 5 的 14 路 tag 表
 *   cards/DoNot.c            ! / ~ / 强类型位取反三形态
 *   cards/DoOr.c             实数按 ToInt64 再 orr、bool|bool → tag 13
 *   cards/DoPushImmediate.c  sxth + str [sp,#-4]!
 *   cards/DoRem.c            9 条内核写回**商**（卡已证名字与实现不符）、|B| 截断判零
 *   cards/DoSet.c            K=1..6 六种比较、1e-05 容差、未支持组合给值不给错
 *   cards/DoShl.c            快路径不掩码移位量、慢路径 and #31
 *   cards/DoShr.c            asr、pair 35 符号扩展到 64 位
 *   cards/DoSub.c            与 DoAdd 同构的双格式码分派、rsb 取 A-B
 *
 * 协议：reconstruction/contracts/opcode-diff-protocol.md
 *   <binary> < cases.jsonl > out.jsonl；逐行读、逐行写、每行 flush。
 *
 * ── 镜像编码（与 diff/gen_cases.py 的 Encoding contract 一致）──
 *   +0..+11 载荷；+12..+15 u32，低 24 位是 tag（高 8 位标志恒 0）。
 *   tag 0/13 f64；7 i32；10 i64；1 内联 ASCII（NUL 填充，≤11 B）；
 *   5 undefined；0x00FFFFFF 未解析占位；2/3/4/6/8/9/11/12/14 是错误路径 tag。
 *
 *   ⚠ 原版的字符串是 YYString/_RefThing{ptr,refcnt,len} 指向堆缓冲（DoAdd 卡
 *   「0x66 拼接」段、DoDup 卡 tag1 计数在对象 +4）。16 字节镜像装不下堆内容，两个
 *   独立实现也无法共享指针，所以里程碑 1 的镜像把 ≤11 B ASCII 内联。本文件按该
 *   镜像契约**读和写**字符串：结果串也是内联编码，不真分配 —— 原文的
 *   「operator new(12) + YYAlloc(len+1)」退化成静态缓冲里的一次 memcpy。
 *   这是 host_authored 约定，不是原件布局（known deviation #1）。
 */

#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ═══════════════════════════ 1. RValue ═══════════════════════════ */

typedef struct { unsigned char b[16]; } RVal;

#define TAG_MASK 0x00FFFFFFu
#define TAG_REAL 0u
#define TAG_STR  1u
#define TAG_I32  7u
#define TAG_I64  10u
#define TAG_BOOL 13u

/* 卡（DoAdd）：tag = +12 字的低 24 位，高 8 位是标志。 */
static uint32_t rv_tag(const RVal *v)
{
    uint32_t t;
    memcpy(&t, v->b + 12, 4);
    return t & TAG_MASK;
}

static void rv_set_tag(RVal *v, uint32_t t)
{
    uint32_t cur;
    memcpy(&cur, v->b + 12, 4);
    cur = (cur & 0xFF000000u) | (t & TAG_MASK);
    memcpy(v->b + 12, &cur, 4);
}

static void rv_clear(RVal *v) { memset(v->b, 0, sizeof v->b); }
static void rv_copy(RVal *d, const RVal *s) { memcpy(d->b, s->b, 16); }

static double rv_f64(const RVal *v) { double d; memcpy(&d, v->b, 8); return d; }
static int64_t rv_i64(const RVal *v) { int64_t x; memcpy(&x, v->b, 8); return x; }
static int32_t rv_i32(const RVal *v) { int32_t x; memcpy(&x, v->b, 4); return x; }

static void rv_set_f64(RVal *v, double d)
{
    rv_clear(v);
    memcpy(v->b, &d, 8);
    rv_set_tag(v, TAG_REAL);
}

static void rv_set_i64(RVal *v, int64_t x)
{
    rv_clear(v);
    memcpy(v->b, &x, 8);
    rv_set_tag(v, TAG_I64);
}

static void rv_set_i32(RVal *v, int32_t x)
{
    rv_clear(v);
    memcpy(v->b, &x, 4);
    rv_set_tag(v, TAG_I32);
}

/* bool 在 RValue 里就是 8 字节 double 的 0.0/1.0，只换 tag
 * （DoConv 卡 dst=5 叶子写 tag 13；DoAnd/DoXor 的 bool 内核 mov r12,#13）。 */
static void rv_set_bool(RVal *v, int truth)
{
    rv_clear(v);
    double d = truth ? 1.0 : 0.0;
    memcpy(v->b, &d, 8);
    rv_set_tag(v, TAG_BOOL);
}

/* 字符串：内联 ASCII，NUL 填充（≤11 B）。见文件头。 */
static void rv_set_text(RVal *v, const char *s, size_t n)
{
    rv_clear(v);
    if (n > 11) n = 11;
    if (n) memcpy(v->b, s, n);
    rv_set_tag(v, TAG_STR);
}

static size_t rv_text(const RVal *v, char *out, size_t cap)
{
    size_t n = 0;
    while (n < 12 && v->b[n] != 0 && n + 1 < cap) {
        out[n] = (char)v->b[n];
        n++;
    }
    out[n] = '\0';
    return n;
}

/* ═══════════════════════════ 2. 错误 ═══════════════════════════ */

/* 一条输入用例（协议 §输入行）。 */
typedef struct {
    char id[48];        /* 原样回显 */
    char op[32];
    long mode;
    int type;
    RVal a, b;
} Case;

typedef struct {
    int ok;
    long sp;            /* sp_new - sp_old：负=下移、正=上移 */
    RVal res;
    char err[192];
} Out;

static void ofail(Out *o, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(o->err, sizeof o->err, fmt, ap);
    va_end(ap);
    o->ok = 0;
}

static const char *op_prefix(const char *op)
{
    if (!strcmp(op, "push_immediate")) return "DoPushImmediate";
    if (!strcmp(op, "dup"))  return "DoDup";
    if (!strcmp(op, "conv")) return "DoConv";
    if (!strcmp(op, "add"))  return "DoAdd";
    if (!strcmp(op, "sub"))  return "DoSub";
    if (!strcmp(op, "mul"))  return "DoMul";
    if (!strcmp(op, "div"))  return "DoDiv";
    if (!strcmp(op, "rem"))  return "DoRem";
    if (!strcmp(op, "mod"))  return "DoMod";
    if (!strcmp(op, "and"))  return "DoAnd";
    if (!strcmp(op, "or"))   return "DoOr";
    if (!strcmp(op, "xor"))  return "DoXor";
    if (!strcmp(op, "shl"))  return "DoShl";
    if (!strcmp(op, "shr"))  return "DoShr";
    if (!strcmp(op, "neg"))  return "DoNeg";
    if (!strcmp(op, "not"))  return "DoNot";
    if (!strncmp(op, "set_", 4)) return "DoSet";
    return "DoUnknown";
}

/* "<Op> :: Execution Error"。DoSub 的 .rodata 原文是双冒号无空格
 * （DoSub 卡 literal pool 抄录 'DoSub:: Execution Error'），按原文保留。 */
static const char *exec_msg(const char *op)
{
    static char buf[64];
    if (!strcmp(op, "sub")) return "DoSub:: Execution Error";
    snprintf(buf, sizeof buf, "%s :: Execution Error", op_prefix(op));
    return buf;
}

/* 字符串不能参与该算子（DoSub/DoDiv/DoRem/DoMod/DoAnd/DoOr/DoXor/DoShl/DoShr）。 */
static const char *str_msg(const char *op)
{
    static char buf[96];
    snprintf(buf, sizeof buf,
             "%s :: Execution Engine - Cannot operate on string type",
             op_prefix(op));
    return buf;
}

static int has_str_err(const char *op)
{
    return !strcmp(op, "sub") || !strcmp(op, "div") || !strcmp(op, "rem") ||
           !strcmp(op, "mod") || !strcmp(op, "and") || !strcmp(op, "or") ||
           !strcmp(op, "xor") || !strcmp(op, "shl") || !strcmp(op, "shr");
}

/* 卡里同一句话有两份拷贝，前缀带站点号（'DoSub :1: illegal array use' /
 * 'DoSub :2: ...'，见 DoSub 卡 literal pool）。哪一侧是 :1: 卡里没明说 —— 本实现
 * 定 a(左)=1、b(右)=2（deviation #7）。DoAdd/DoMul/DoMod/DoOr/DoNot 的卡只抄到
 * 不带站点号的形式，那几条走 "::"。 */
static int site_style(const char *op)
{
    return !strcmp(op, "sub") || !strcmp(op, "div") || !strcmp(op, "rem") ||
           !strcmp(op, "xor") || !strcmp(op, "and") || !strcmp(op, "shl") ||
           !strcmp(op, "shr") || !strcmp(op, "conv") || !strcmp(op, "neg") ||
           !strncmp(op, "set_", 4);
}

static void ofail_tag(Out *o, const char *op, int side, const char *what)
{
    const char *p = op_prefix(op);
    if (site_style(op))
        ofail(o, "%s :%d: %s", p, side, what);
    else
        ofail(o, "%s :: %s", p, what);
}

/* ═══════════════════════════ 3. 存储类 ═══════════════════════════
 *
 * 卡里的『格式码 / 存储类 / kind』（DoAdd 卡 T1/T2、DoDup 卡宽度表、DoConv 卡类型码）：
 *   0 = 8B double   1 = 4B float32  2 = 4B int32  3 = 8B int64
 *   4 = 4B bool     5 = 16B RValue（按 +12 tag 反推真实类）
 *   6 = 4B string   7..15 = 表外（无 dest）
 */
static int slot_w(int cls)
{
    switch (cls) {
    case 0: case 3: return 8;
    case 1: case 2: case 4: case 6: return 4;
    case 5: return 16;
    default: return 0;
    }
}

/* tag → 存储类（DoShr 卡结论 2 / DoMul 卡结论 3 / DoNeg、DoConv 的 14 路 tag 表）：
 * 0/13→real、7→int32、10→int64、1→string、2→array、3→pointer、5→undefined（+=0.0）、12→null（=0.0）、
 * 其余（4/6/8/9/11/12/14/>13，含 0x00FFFFFF 占位）→ Malformed variable。
 * DoAdd 卡 open：占位在 mode0 里不查，落到 Malformed —— 与这里一致。 */
static int cls_of_tag(const char *op, int side, const RVal *v, Out *o)
{
    switch (rv_tag(v)) {
    case 0: case 13: return 0;
    case 7:  return 2;
    case 10: return 3;
    case 1:  return 6;
    case 2: ofail_tag(o, op, side, "illegal array use"); return -1;
    case 3: ofail_tag(o, op, side, "illegal pointer use"); return -1;
    case 5: ofail_tag(o, op, side, "undefined value"); return -1;
    default: ofail_tag(o, op, side, "Malformed variable"); return -1;
    }
}

/* nibble → 具体类；5 走 tag 表；>6 是表外格式码 → Execution Error
 * （DoAdd 卡 T3 无 dest；DoShl 卡「非法类型（字符串/未发射组合）→ Execution Error」）。 */
static int cls_resolve(const char *op, int side, int nib, const RVal *v, Out *o)
{
    if (nib == 5) return cls_of_tag(op, side, v, o);
    if (nib <= 6) return nib;
    ofail(o, "%s", exec_msg(op));
    return -1;
}

/* ── 数值读：按**声明类**解释载荷。快路径不看 tag，卡里读的就是裸槽。── */

static int64_t f2i64(double d)          /* __fixdfdi：向零截断，NaN 给 INT64_MIN */
{
    if (isnan(d)) return INT64_MIN;
    if (d >= 9223372036854775808.0) return INT64_MAX;
    if (d <= -9223372036854775808.0) return INT64_MIN;
    return (int64_t)d;
}

static int32_t f2i32(double d)          /* vcvt.s32：向零截断，NaN → 0 */
{
    if (isnan(d)) return 0;
    if (d >= 2147483648.0) return INT32_MAX;
    if (d <= -2147483648.0) return INT32_MIN;
    return (int32_t)d;
}

static double as_f64(const RVal *v, int cls)
{
    float f;
    switch (cls) {
    case 0: return rv_f64(v);
    case 1: memcpy(&f, v->b, 4); return (double)f;
    case 2: return (double)rv_i32(v);
    case 3: return (double)rv_i64(v);
    case 4: return rv_i32(v) ? 1.0 : 0.0;
    default: return 0.0;
    }
}

static int64_t as_i64(const RVal *v, int cls)
{
    float f;
    switch (cls) {
    case 0: return f2i64(rv_f64(v));
    case 1: memcpy(&f, v->b, 4); return f2i64((double)f);
    case 2: return (int64_t)rv_i32(v);
    case 4: return (int64_t)(rv_i32(v) ? 1 : 0);
    case 3: return rv_i64(v);
    default: return 0;
    }
}

static int32_t as_i32(const RVal *v, int cls)
{
    float f;
    switch (cls) {
    case 0: return f2i32(rv_f64(v));
    case 1: memcpy(&f, v->b, 4); return f2i32((double)f);
    case 2: return rv_i32(v);
    case 4: return rv_i32(v) ? 1 : 0;
    case 3: return (int32_t)rv_i64(v);      /* DoConv dst2←3：截断取低 32 位 */
    default: return 0;
    }
}

/* JS_ToBoolean（DoNot mode1、DoConv flag1）：tag1 看串长，数组/指针恒真。 */
static int truthy(const RVal *v, int cls)
{
    char t[16];
    if (cls == 6) return rv_text(v, t, sizeof t) > 0;
    if (cls == 4) return rv_i32(v) != 0;
    return as_f64(v, cls) != 0.0;
}

/* ═══════════════════════ 4. JS 强制转换（慢路径）═══════════════════════ */

/* 卡里的 JS 路（DoAdd mode1/2、DoSub/DoDiv 的 bits[11:8] 路、DoNeg mode1/2）
 * 都是 boxType + F_JS_ToNumber；这里直接对 16 字节镜像做同一件事。 */
static int js_tonumber(const char *op, int side, const RVal *v, double *out, Out *o)
{
    char t[16];
    switch (rv_tag(v)) {
    case 0: case 13: *out = rv_f64(v); return 0;
    case 7:  *out = (double)rv_i32(v); return 0;
    case 10: *out = (double)rv_i64(v); return 0;
    case 1:  rv_text(v, t, sizeof t); *out = strtod(t, NULL); return 0;
    case 5: case 12: *out = 0.0; return 0;      /* undefined / null 数值化 */
    case 0x00FFFFFF:
        ofail(o, "%s :%d: could not find variable", op_prefix(op), side);
        return -1;
    case 2: ofail_tag(o, op, side, "illegal array use"); return -1;
    case 3: ofail_tag(o, op, side, "illegal pointer use"); return -1;
    default: ofail_tag(o, op, side, "Malformed variable"); return -1;
    }
}

static int js_toint32(const char *op, int side, const RVal *v, int32_t *out, Out *o)
{
    double d;
    if (js_tonumber(op, side, v, &d, o)) return -1;
    *out = f2i32(d);
    return 0;
}

static int js_tostring(const char *op, int side, const RVal *v,
                       char *buf, size_t cap, Out *o)
{
    switch (rv_tag(v)) {
    case 1: rv_text(v, buf, cap); return 0;
    case 0: case 13: snprintf(buf, cap, "%g", rv_f64(v)); return 0;
    case 7:  snprintf(buf, cap, "%d", rv_i32(v)); return 0;
    case 10: snprintf(buf, cap, "%" PRId64, rv_i64(v)); return 0;
    case 5:  snprintf(buf, cap, "undefined"); return 0;
    case 12: snprintf(buf, cap, "null"); return 0;
    case 0x00FFFFFF:
        ofail(o, "%s :%d: could not find variable", op_prefix(op), side);
        return -1;
    case 2: ofail_tag(o, op, side, "illegal array use"); return -1;
    case 3: ofail_tag(o, op, side, "illegal pointer use"); return -1;
    default: ofail_tag(o, op, side, "Malformed variable"); return -1;
    }
}

/* ═══════════════════════════ 5. 二元算子骨架 ═══════════════════════════ */

/* (左类, 右类) 合法表。type 字节 = (左<<4)|右（gen_cases.py 契约）。
 * 每张表逐条抄自对应卡的分派结论，不是一条公式。 */
#define PB(l, r) (1ull << ((l) * 7 + (r)))
#define P9 \
    (PB(0,0)|PB(0,2)|PB(0,3)|PB(2,0)|PB(2,2)|PB(2,3)|PB(3,0)|PB(3,2)|PB(3,3))

static const uint64_t ADD_OK = P9 | PB(6,6);        /* DoAdd：9 组合 + 0x66 */
static const uint64_t SUB_OK = P9;                  /* DoSub */
static const uint64_t DIV_OK = P9;                  /* DoDiv */
static const uint64_t REM_OK = P9;                  /* DoRem */
static const uint64_t MOD_OK = P9;                  /* DoMod */
/* DoMul：pair=kA|kB<<4，kA(低)=串侧、kB(高)=次数侧 → 串只能是右操作数。 */
static const uint64_t MUL_OK = P9 | PB(0,6) | PB(2,6);
/* DoAnd：9 组合 + bool×bool + bool 与 real 混算；bool 与 int32/int64 直接组合
 * （卡里 36/66）不发射 → VMError。DoOr 同构（pair 4 的槽位异常见 deviation #6）。 */
static const uint64_t AND_OK = P9 | PB(0,4) | PB(4,0) | PB(4,4);
static const uint64_t OR_OK  = P9 | PB(0,4) | PB(4,0) | PB(4,4);
static const uint64_t XOR_OK = P9 | PB(4,4);        /* DoXor：只有 (4,4) */
/* DoShl：表4 只有 7 条内核（(real,int32)/(real,int64) 合并、(int64,int32)/
 * (int64,int64) 合并）→ 8 个合法 pair。 */
static const uint64_t SHL_OK =
    PB(0,0)|PB(0,2)|PB(0,3)|PB(2,0)|PB(2,2)|PB(3,0)|PB(3,2)|PB(3,3);
/* DoShr：pair∈{0,2,3,32,34,35,48,50,51}。 */
static const uint64_t SHR_OK =
    PB(0,0)|PB(2,0)|PB(3,0)|PB(0,2)|PB(2,2)|PB(3,2)|PB(0,3)|PB(2,3)|PB(3,3);

static int pair_ok(uint64_t mask, int l, int r)
{
    return (int)((mask >> (l * 7 + r)) & 1ull);
}

typedef struct { int la, lb, wa, wb; } Ops2;

/* 解两侧存储类 → 查合法表 → 报错。失败返回非 0 且 o 已填错误串。 */
static int prep2(const char *op, const RVal *a, const RVal *b, int typ,
                 uint64_t ok_mask, Ops2 *p, Out *o)
{
    int ha = (typ >> 4) & 0xF, hb = typ & 0xF;
    int la, lb;

    p->wa = slot_w(ha);
    p->wb = slot_w(hb);
    la = cls_resolve(op, 1, ha, a, o);
    if (la < 0) return -1;
    lb = cls_resolve(op, 2, hb, b, o);
    if (lb < 0) return -1;
    p->la = la;
    p->lb = lb;
    if (!pair_ok(ok_mask, la, lb)) {
        if ((la == 6 || lb == 6) && has_str_err(op))
            ofail(o, "%s", str_msg(op));
        else
            ofail(o, "%s", exec_msg(op));
        return -1;
    }
    return 0;
}

/* ═══════════════════════ 6. 各 op 实现 ═══════════════════════ */

/* mode≠0 的 JS 慢路径：两侧操作数被 boxType 装箱后消耗，结果是一个 16 B RValue
 * （DoAdd 卡：mode1/2 的成功返回都是 r8-16；DoSub/DoDiv：bits[11:8]==1 走 box）。 */
static long js_delta16(const Case *c)
{
    return (long)slot_w((c->type >> 4) & 0xF) + slot_w(c->type & 0xF) - 16;
}

/* ── add：DoAdd 卡：0x22 → 32 位、含 3 → 64 位、含 0 → double、
 *          0x66 → 字符串拼接（tag 1）。结果落点 off-w。 ── */
static void op_add(const Case *c, Out *o)
{
    Ops2 p;

    /* DoAdd 卡：mode==1 走 ToPrimitive→(两侧都是串则拼接，否则 ToNumber+vadd.f64)；
     * mode==2 直接 ToNumber+vadd.f64（不拼串）；0 与 3..15 与 mode0 同路。 */
    if (c->mode == 1 || c->mode == 2) {
        double x, y;
        if (c->mode == 1 &&
            (rv_tag(&c->a) == TAG_STR || rv_tag(&c->b) == TAG_STR)) {
            char ta[32], tb[32], buf[64];
            size_t na, nb;
            if (js_tostring("add", 1, &c->a, ta, sizeof ta, o)) return;
            if (js_tostring("add", 2, &c->b, tb, sizeof tb, o)) return;
            na = strlen(ta);
            nb = strlen(tb);
            memcpy(buf, ta, na);
            memcpy(buf + na, tb, nb);
            rv_set_text(&o->res, buf, na + nb);
        } else {
            if (js_tonumber("add", 1, &c->a, &x, o)) return;
            if (js_tonumber("add", 2, &c->b, &y, o)) return;
            rv_set_f64(&o->res, x + y);
        }
        o->sp = js_delta16(c);
        o->ok = 1;
        return;
    }

    if (prep2("add", &c->a, &c->b, c->type, ADD_OK, &p, o)) return;

    if (p.la == 6 && p.lb == 6) {
        char ta[16], tb[16], buf[32];
        size_t na = rv_text(&c->a, ta, sizeof ta);
        size_t nb = rv_text(&c->b, tb, sizeof tb);
        memcpy(buf, ta, na);
        memcpy(buf + na, tb, nb);
        rv_set_text(&o->res, buf, na + nb);     /* 超出 11 B 按镜像契约截断 */
        o->sp = (long)p.wa + p.wb - 16;
    } else if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, as_f64(&c->a, p.la) + as_f64(&c->b, p.lb));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, (int64_t)((uint64_t)as_i64(&c->a, p.la) +
                                      (uint64_t)as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, (int32_t)((uint32_t)as_i32(&c->a, p.la) +
                                      (uint32_t)as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── sub：rsb/subs 取 A-B；无字符串路径（DoSub 卡）。 ── */
static void op_sub(const Case *c, Out *o)
{
    Ops2 p;

    /* DoSub 卡：慢路径开关是 bits[11:8] **恰等于 1**（不是"非零"），
     * 走 boxType×2 + F_JS_ToNumber×2 + vsub → 结果恒 double、tag 0。 */
    if (c->mode == 1) {
        double x, y;
        if (js_tonumber("sub", 1, &c->a, &x, o)) return;
        if (js_tonumber("sub", 2, &c->b, &y, o)) return;
        rv_set_f64(&o->res, x - y);
        o->sp = js_delta16(c);
        o->ok = 1;
        return;
    }

    if (prep2("sub", &c->a, &c->b, c->type, SUB_OK, &p, o)) return;

    if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, as_f64(&c->a, p.la) - as_f64(&c->b, p.lb));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, (int64_t)((uint64_t)as_i64(&c->a, p.la) -
                                      (uint64_t)as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, (int32_t)((uint32_t)as_i32(&c->a, p.la) -
                                      (uint32_t)as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── mul：DoMul 卡 pair 6/38 = 字符串重复（次数在左、串在右），
 *          次数 class 0 走 vcvt.s32.f64、class 2 直接 int32。 ── */
static void op_mul(const Case *c, Out *o)
{
    Ops2 p;
    if (prep2("mul", &c->a, &c->b, c->type, MUL_OK, &p, o)) return;

    if (p.lb == 6) {
        char t[16], buf[12];
        size_t n = rv_text(&c->b, t, sizeof t);
        int64_t cnt = (p.la == 0) ? (int64_t)f2i32(rv_f64(&c->a))
                                  : (int64_t)as_i32(&c->a, p.la);
        size_t want, i;
        if (cnt < 0) cnt = 0;
        want = n * (size_t)cnt;
        if (want > 11) want = 11;
        for (i = 0; i < want && n; i++) buf[i] = t[i % n];
        rv_set_text(&o->res, buf, want);
        o->sp = (long)p.wa + p.wb - 16;
    } else if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, as_f64(&c->a, p.la) * as_f64(&c->b, p.lb));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, (int64_t)((uint64_t)as_i64(&c->a, p.la) *
                                      (uint64_t)as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, (int32_t)((uint32_t)as_i32(&c->a, p.la) *
                                      (uint32_t)as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── div：DoDiv 卡：实数 vdiv.f64 **不判零**（IEEE ±inf/NaN）；整数判零后
 *          走 __divsi3 / __aeabi_ldivmod，除零是软错误 "DoDiv :: Divide by zero"。 ── */
static void op_div(const Case *c, Out *o)
{
    Ops2 p;

    /* DoDiv 卡：bits[11:8]==1 走 F_JS_ToNumber×2 + vdiv.f64 —— 慢路径上实数一律
     * 不判零（IEEE ±inf/NaN），所以这里也不报 "Divide by zero"。 */
    if (c->mode == 1) {
        double x, y;
        if (js_tonumber("div", 1, &c->a, &x, o)) return;
        if (js_tonumber("div", 2, &c->b, &y, o)) return;
        rv_set_f64(&o->res, x / y);
        o->sp = js_delta16(c);
        o->ok = 1;
        return;
    }

    if (prep2("div", &c->a, &c->b, c->type, DIV_OK, &p, o)) return;

    if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, as_f64(&c->a, p.la) / as_f64(&c->b, p.lb));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        int64_t d = as_i64(&c->b, p.lb), n = as_i64(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoDiv :: Divide by zero");
            return;
        }
        rv_set_i64(&o->res, (d == -1) ? (int64_t)(0ull - (uint64_t)n) : (n / d));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        int32_t d = as_i32(&c->b, p.lb), n = as_i32(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoDiv :: Divide by zero");
            return;
        }
        rv_set_i32(&o->res, (d == -1) ? (int32_t)(0u - (uint32_t)n)
                                      : (int32_t)(n / d));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── rem：DoRem 卡结论 2 —— 这个名字与实现不符：9 条内核写回的是**商**
 *          （int32 走 __divsi3、int64 取 ldivmod 的 r0:r1、real 先 __fixdfdi 截断再
 *          整数除再回 double）。零检查比 DoDiv 多一条：real 的 |B| 先 vabs 再
 *          vcvt.s32.f64，截断为 0 就报错 —— 所以 0.5 也算除零（卡结论 3）。 ── */
static void op_rem(const Case *c, Out *o)
{
    Ops2 p;
    if (prep2("rem", &c->a, &c->b, c->type, REM_OK, &p, o)) return;

    if (p.la == 0 || p.lb == 0) {
        double d = as_f64(&c->b, p.lb);
        int64_t n, dv, q;
        if (f2i32(fabs(d)) == 0) {              /* @0xd4728 vabs + vcvt.s32.f64 */
            ofail(o, "DoRem :: Divide by zero");
            return;
        }
        n = as_i64(&c->a, p.la);
        dv = as_i64(&c->b, p.lb);
        q = (dv == -1) ? (int64_t)(0ull - (uint64_t)n) : (n / dv);
        rv_set_f64(&o->res, (double)q);
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        int64_t d = as_i64(&c->b, p.lb), n = as_i64(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoRem :: Divide by zero");
            return;
        }
        rv_set_i64(&o->res, (d == -1) ? (int64_t)(0ull - (uint64_t)n) : (n / d));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        int32_t d = as_i32(&c->b, p.lb), n = as_i32(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoRem :: Divide by zero");
            return;
        }
        rv_set_i32(&o->res, (d == -1) ? (int32_t)(0u - (uint32_t)n)
                                      : (int32_t)(n / d));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── mod：DoMod 卡：整数走 __aeabi_idivmod / __aeabi_ldivmod 取余；
 *          real 的除零阈值是 1e-10（常量池 0x3DDB7CDFD9D7BDBB）；
 *          mode==1 的常量路径把 NaN/∞/±0 的边角折成 0x7FFFFFFFFFFFFFFF 的 NaN
 *          位型而**不报错** —— 与 mode 0 的报错策略不同（卡结论 5）。 ── */
static void op_mod(const Case *c, Out *o)
{
    Ops2 p;
    int konst;
    if (prep2("mod", &c->a, &c->b, c->type, MOD_OK, &p, o)) return;
    konst = (c->mode == 1);

    if (p.la == 0 || p.lb == 0) {
        double nv = as_f64(&c->a, p.la), dv = as_f64(&c->b, p.lb);
        if (konst) {
            if (!isfinite(nv) || !isfinite(dv) || dv == 0.0) {
                uint64_t bits = 0x7FFFFFFFFFFFFFFFull;
                rv_clear(&o->res);
                memcpy(o->res.b, &bits, 8);
                rv_set_tag(&o->res, TAG_REAL);
            } else {
                rv_set_f64(&o->res, fmod(nv, dv));
            }
        } else {
            if (fabs(dv) < 1e-10) {             /* @0xde9c4 vabs + vcmpe 1e-10 */
                ofail(o, "DoMod :: Divide by zero");
                return;
            }
            rv_set_f64(&o->res, fmod(nv, dv));
        }
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        int64_t d = as_i64(&c->b, p.lb), n = as_i64(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoMod :: Divide by zero");
            return;
        }
        rv_set_i64(&o->res, (d == -1) ? 0 : (n % d));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        int32_t d = as_i32(&c->b, p.lb), n = as_i32(&c->a, p.la);
        if (d == 0) {
            ofail(o, "DoMod :: Divide by zero");
            return;
        }
        rv_set_i32(&o->res, (d == -1) ? 0 : (int32_t)(n % d));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

enum { BIT_AND = 0, BIT_OR = 1, BIT_XOR = 2 };

static int64_t bitop(int kind, int64_t x, int64_t y)
{
    uint64_t r = (kind == BIT_AND) ? ((uint64_t)x & (uint64_t)y)
              : (kind == BIT_OR)  ? ((uint64_t)x | (uint64_t)y)
                                  : ((uint64_t)x ^ (uint64_t)y);
    return (int64_t)r;
}

/* ── and / or / xor：DoAnd/DoOr/DoXor 卡。
 *   · bool×bool 是**逻辑**语义、写 tag 13（And 短路、Or 归一、Xor eorne）；
 *   · 实数参与时先 __fixdfdi 截断成 int64 再按位算，结果 __floatdidf 回 double、tag 0
 *     —— 即 GML 的位算 = ToInt64(lhs) op ToInt64(rhs)，不是浮点位；
 *   · int32×int32 写 4 字节 tag 7，任一侧 int64 写 8 字节 tag 10；
 *   · mode≠0 走慢路径：两侧 F_JS_ToInt32 后做 32 位运算（会截断到 32 位），
 *     DoXor 卡「32 位 eor + 回 double」→ 结果 16 字节 double、tag 0。 ── */
static void bitwise(const char *op, const Case *c, Out *o, uint64_t mask, int kind)
{
    Ops2 p;
    if (prep2(op, &c->a, &c->b, c->type, mask, &p, o)) return;

    if (c->mode != 0) {
        int32_t x, y;
        uint32_t r;
        if (js_toint32(op, 1, &c->a, &x, o)) return;
        if (js_toint32(op, 2, &c->b, &y, o)) return;
        r = (kind == BIT_AND) ? ((uint32_t)x & (uint32_t)y)
          : (kind == BIT_OR)  ? ((uint32_t)x | (uint32_t)y)
                              : ((uint32_t)x ^ (uint32_t)y);
        rv_set_f64(&o->res, (double)(int32_t)r);
        o->sp = (long)p.wa + p.wb - 16;
        o->ok = 1;
        return;
    }

    if (p.la == 4 && p.lb == 4) {
        int x = rv_i32(&c->a) != 0, y = rv_i32(&c->b) != 0, t;
        if (kind == BIT_AND)
            t = rv_i32(&c->a) == 0 ? 0 : y;     /* 短路：A==0 直接写回 A */
        else if (kind == BIT_OR)
            t = x || y;
        else
            t = x ^ y;
        rv_set_bool(&o->res, t);
        o->sp = (long)p.wa + p.wb - 4;          /* bool 槽 4 字节 */
        o->ok = 1;
        return;
    }
    if (p.la == 4 || p.lb == 4) {
        /* bool 与 real 混算：real 走 __fixdfdi，bool 归一成 0/1，结果 double tag 0。 */
        int64_t iv = (p.la == 4) ? as_i64(&c->b, p.lb) : as_i64(&c->a, p.la);
        int64_t bv = (p.la == 4) ? (rv_i32(&c->a) ? 1 : 0)
                                 : (rv_i32(&c->b) ? 1 : 0);
        rv_set_f64(&o->res, (double)bitop(kind, iv, bv));
        o->sp = (long)p.wa + p.wb - 8;
        o->ok = 1;
        return;
    }
    if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, (double)bitop(kind, as_i64(&c->a, p.la),
                                          as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, bitop(kind, as_i64(&c->a, p.la), as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, (int32_t)bitop(kind, (int64_t)as_i32(&c->a, p.la),
                                           (int64_t)as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* 快路径的移位量：ARM 的 lsl/asr 用寄存器低 8 位；n≥32 时 32 位结果按符号/零填。 */
static int32_t shl32(int32_t v, int32_t n)
{
    uint32_t u = (uint32_t)n & 0xFFu;
    return (u >= 32) ? 0 : (int32_t)((uint32_t)v << u);
}

static int32_t shr32(int32_t v, int32_t n)
{
    uint32_t u = (uint32_t)n & 0xFFu;
    if (u >= 32) return (v < 0) ? -1 : 0;
    if (v < 0) return (int32_t)~(~(uint32_t)v >> u);
    return (int32_t)((uint32_t)v >> u);
}

static int64_t shl64(int64_t v, int64_t n)
{
    if (n < 0 || n >= 64) return 0;
    return (int64_t)((uint64_t)v << (unsigned)n);
}

static int64_t shr64(int64_t v, int64_t n)
{
    if (n < 0 || n >= 64) return (v < 0) ? -1 : 0;
    if (v < 0) return (int64_t)~(~(uint64_t)v >> (unsigned)n);
    return (int64_t)((uint64_t)v >> (unsigned)n);
}

/* ── shl：DoShl 卡：A(高 nibble)=被移位值、B(低)=位移量。快路径**不掩码**；
 *         real 参与时两侧 __fixdfdi、结果 __floatdidf 回 double。 ── */
static void op_shl(const Case *c, Out *o)
{
    Ops2 p;
    if (prep2("shl", &c->a, &c->b, c->type, SHL_OK, &p, o)) return;

    if (c->mode != 0) {                     /* 慢路径：ToInt32×2 + and #31（@0xe1344） */
        int32_t x, y;
        if (js_toint32("shl", 1, &c->a, &x, o)) return;
        if (js_toint32("shl", 2, &c->b, &y, o)) return;
        rv_set_f64(&o->res, (double)shl32(x, y & 31));
        o->sp = (long)p.wa + p.wb - 16;
        o->ok = 1;
        return;
    }
    if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, (double)shl64(as_i64(&c->a, p.la), as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, shl64(as_i64(&c->a, p.la), as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, shl32(as_i32(&c->a, p.la), as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── shr：DoShr 卡：pair 34 走 asr（32 位，tag 7）、pair 35 符号扩展成 64 位（tag 10）、
 *          real 参与时经 __fixdfdi/__floatundidf 中转。 ── */
static void op_shr(const Case *c, Out *o)
{
    Ops2 p;
    if (prep2("shr", &c->a, &c->b, c->type, SHR_OK, &p, o)) return;

    if (c->mode != 0) {                     /* 常量路径：ToInt32（bit15 未带，取 >> ） */
        int32_t x, y;
        if (js_toint32("shr", 1, &c->a, &x, o)) return;
        if (js_toint32("shr", 2, &c->b, &y, o)) return;
        rv_set_f64(&o->res, (double)shr32(x, y));
        o->sp = (long)p.wa + p.wb - 16;
        o->ok = 1;
        return;
    }
    if (p.la == 0 || p.lb == 0) {
        rv_set_f64(&o->res, (double)shr64(as_i64(&c->a, p.la), as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else if (p.la == 3 || p.lb == 3) {
        rv_set_i64(&o->res, shr64(as_i64(&c->a, p.la), as_i64(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 8;
    } else {
        rv_set_i32(&o->res, shr32(as_i32(&c->a, p.la), as_i32(&c->b, p.lb)));
        o->sp = (long)p.wa + p.wb - 4;
    }
    o->ok = 1;
}

/* ── set_lt .. set_gt：DoSet 卡。K = 1..6 取 op 名（协议 op 表）。
 *   数值路径先算 d = 左 - 右，再与全局常量 1e-05 比（卡结论 3：== 是
 *   |d| <= 1e-5，不是位相等）；字符串路径用 strcmp 独立复现同一 K 顺序；
 *   未支持的类型组合**不报错**：K=4 得 1、其余得 0（卡 e33c0 结论）。 ── */
#define SET_EPS 1e-5

static int set_k(const char *op)
{
    if (!strcmp(op, "set_lt")) return 1;
    if (!strcmp(op, "set_le")) return 2;
    if (!strcmp(op, "set_eq")) return 3;
    if (!strcmp(op, "set_ne")) return 4;
    if (!strcmp(op, "set_ge")) return 5;
    return 6;
}

/* 卡里 17 个已列出的类型组合（含 0xFF = 两侧都是 16B RValue）。 */
static const uint64_t SET_TYPES_OK =
    PB(0,0)|PB(0,2)|PB(0,4)|PB(2,0)|PB(2,2)|PB(2,3)|PB(2,4)|PB(3,0)|PB(3,2)|
    PB(3,3)|PB(4,0)|PB(4,2)|PB(4,4)|PB(4,6)|PB(6,4)|PB(6,6);

static int cmp_k(int k, int cmp)
{
    switch (k) {
    case 1: return cmp < 0;
    case 2: return cmp <= 0;
    case 3: return cmp == 0;
    case 4: return cmp != 0;
    case 5: return cmp >= 0;
    default: return cmp > 0;
    }
}

static void op_set(const char *op, const Case *c, Out *o)
{
    int k = set_k(op);
    int ha = (c->type == 0xFF) ? 5 : ((c->type >> 4) & 0xF);
    int hb = (c->type == 0xFF) ? 5 : (c->type & 0xF);
    int wa = slot_w(ha), wb = slot_w(hb);
    int la, lb, r;

    /* 表外格式码（7..15，0xFF 除外）没有 dest 表项 → DoSet 给值不给错。 */
    if (ha > 6 || hb > 6) {
        rv_set_i32(&o->res, (k == 4) ? 1 : 0);
        o->sp = (long)wa + wb - 4;
        o->ok = 1;
        return;
    }
    /* class 5 是先按 +12 tag 归一再查表（DoSet 卡 e26f0..e2888 的归一化改写规则）。 */
    la = cls_resolve(op, 1, ha, &c->a, o);
    if (la < 0) return;
    lb = cls_resolve(op, 2, hb, &c->b, o);
    if (lb < 0) return;
    if (!pair_ok(SET_TYPES_OK, la, lb)) {
        /* 未支持组合：只有 K=4(!=) 得 1，其余得 0（卡 e33f0/e33e8）。 */
        rv_set_i32(&o->res, (k == 4) ? 1 : 0);
        o->sp = (long)wa + wb - 4;
        o->ok = 1;
        return;
    }

    if (la == 6 && lb == 6) {
        char ta[16], tb[16];
        rv_text(&c->a, ta, sizeof ta);
        rv_text(&c->b, tb, sizeof tb);
        rv_set_i32(&o->res, cmp_k(k, strcmp(ta, tb)));
    } else if (la == 6 || lb == 6) {
        /* (bool,string)/(string,bool)：卡里可达但语义未展开（open）→ 按未支持组合给值。 */
        rv_set_i32(&o->res, (k == 4) ? 1 : 0);
    } else {
        double d = as_f64(&c->a, la) - as_f64(&c->b, lb);
        if (isnan(d)) {                     /* 卡里 vcmpe 为无序时走 movls/movge 一侧 */
            r = (k == 4) ? 1 : 0;
        } else {
            switch (k) {
            case 1: r = d < -SET_EPS; break;
            case 2: r = d <= SET_EPS; break;
            case 3: r = fabs(d) <= SET_EPS; break;
            case 4: r = fabs(d) > SET_EPS; break;
            case 5: r = d >= -SET_EPS; break;
            default: r = d > SET_EPS; break;
            }
        }
        rv_set_i32(&o->res, r);
    }
    o->sp = (long)wa + wb - 4;
    o->ok = 1;
}

/* ── conv：DoConv 卡。type = (dst<<4)|src，flags = arg[15:8]，44 个叶。 ── */
static void op_conv(const Case *c, Out *o)
{
    int src = c->type & 0xF, dst = (c->type >> 4) & 0xF;
    int flags = (int)(c->mode & 0xFF);
    int scls, wsrc, wdst;
    char tbuf[32];
    double d;

    if (src > 6) { ofail(o, "%s", exec_msg("conv")); return; }
    wsrc = (src == 0 || src == 3) ? 8 : (src == 5 ? 16 : 4);

    if (src == 5) {                          /* 动态源：按 tag 改写 src（@0xeb64c） */
        switch (rv_tag(&c->a)) {
        case 0: case 13: scls = 0; break;
        case 7:  scls = 2; break;
        case 10: scls = 3; break;
        case 1:  scls = 6; break;
        case 5: case 12: scls = 4; break;    /* tag5=undefined、tag12=null：DoConv 都把它们派到
                                              src 4 叶子；**不是 bool 语义**，只是同一个数值零叶子
                                              （claims RVALUE-004：tag5 复制 .bss 零常量 +0.0、tag12 是显式 0.0） */
        case 2: ofail_tag(o, "conv", 1, "illegal array use"); return;
        case 3: ofail_tag(o, "conv", 1, "illegal pointer use"); return;
        case 0x00FFFFFF: ofail(o, "DoConv :1: Could not find variable"); return;
        default: ofail_tag(o, "conv", 1, "Malformed variable"); return;
        }
    } else {
        scls = src;
    }

    wdst = (dst == 0 || dst == 3) ? 8 : (dst == 5 ? 16 : (dst <= 6 ? 4 : 0));
    if (dst > 6 || (dst == 5 && src == 5)) { /* (5,5) 缺项 + dst 7..15 → Execution Error */
        ofail(o, "%s", exec_msg("conv"));
        return;
    }

    /* flags 三路（@0xeb414..0xeb438）：bit8=ToBoolean、bit9=ToNumber、其余落回直通。 */
    if (flags & 1) {
        rv_set_i32(&o->res, truthy(&c->a, scls));
        o->sp = wsrc - 4;
        o->ok = 1;
        return;
    }
    if (flags & 2) {
        if (js_tonumber("conv", 1, &c->a, &d, o)) return;
        rv_set_f64(&o->res, d);
        o->sp = wsrc - 16;
        o->ok = 1;
        return;
    }

    switch (dst) {
    case 0:                                   /* real */
        switch (scls) {
        case 0: d = rv_f64(&c->a); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); d = (double)f2i32((double)f); break; } /* vcvt.s32.f32 → f64.s32 */
        case 2: d = (double)rv_i32(&c->a); break;
        case 3: d = (double)rv_i64(&c->a); break;
        case 4: d = rv_i32(&c->a) ? 1.0 : 0.0; break;
        default:                              /* 6: strtod(text) */
            rv_text(&c->a, tbuf, sizeof tbuf);
            d = strtod(tbuf, NULL);
            break;
        }
        rv_set_f64(&o->res, d);
        break;

    case 1:                                   /* float32 —— 无 RValue tag，宽到 double tag 0 */
        switch (scls) {
        case 0: d = rv_f64(&c->a); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); d = (double)f; break; }
        case 2: d = (double)rv_i32(&c->a); break;
        case 3: d = (double)rv_i64(&c->a); break;
        case 4: d = rv_i32(&c->a) ? 1.0 : 0.0; break;
        default:
            rv_text(&c->a, tbuf, sizeof tbuf);
            d = strtod(tbuf, NULL);
            break;
        }
        rv_set_f64(&o->res, (double)(float)d);
        break;

    case 2:                                   /* int32 */
        switch (scls) {
        case 0: rv_set_i32(&o->res, f2i32(rv_f64(&c->a))); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); rv_set_i32(&o->res, f2i32((double)f)); break; }
        case 2: rv_set_i32(&o->res, rv_i32(&c->a)); break;
        case 3: rv_set_i32(&o->res, (int32_t)rv_i64(&c->a)); break;
        case 4: rv_set_i32(&o->res, rv_i32(&c->a) ? 1 : 0); break;
        default:                              /* atoi(text) */
            rv_text(&c->a, tbuf, sizeof tbuf);
            rv_set_i32(&o->res, (int32_t)atoi(tbuf));
            break;
        }
        break;

    case 3:                                   /* int64 */
        switch (scls) {
        case 0: rv_set_i64(&o->res, f2i64(rv_f64(&c->a))); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); rv_set_i64(&o->res, f2i64((double)f)); break; }
        case 2: rv_set_i64(&o->res, (int64_t)rv_i32(&c->a)); break;
        case 3: rv_set_i64(&o->res, rv_i64(&c->a)); break;
        case 4: rv_set_i64(&o->res, rv_i32(&c->a) ? 1 : 0); break;
        default:                              /* atol(text) */
            rv_text(&c->a, tbuf, sizeof tbuf);
            rv_set_i64(&o->res, (int64_t)strtoll(tbuf, NULL, 10));
            break;
        }
        break;

    case 4: {                                 /* bool */
        int b;
        switch (scls) {
        case 0: b = rv_f64(&c->a) > 0.5; break;
        case 1: { float f; memcpy(&f, c->a.b, 4); b = (double)f > 0.5; break; }
        case 2: b = rv_i32(&c->a) > 0; break;
        case 3: b = rv_i64(&c->a) >= 1; break;
        case 4: b = rv_i32(&c->a) != 0; break;
        default:                              /* strcmp(text,"true")==0 */
            rv_text(&c->a, tbuf, sizeof tbuf);
            b = strcmp(tbuf, "true") == 0;
            break;
        }
        rv_set_bool(&o->res, b);
        break;
    }

    case 5:                                   /* 16B RValue，写显式 tag */
        switch (scls) {
        case 0: rv_set_f64(&o->res, rv_f64(&c->a)); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); rv_set_f64(&o->res, (double)f); break; }
        case 2: rv_set_f64(&o->res, (double)rv_i32(&c->a)); break;
        case 3: rv_set_i64(&o->res, rv_i64(&c->a)); break;
        case 4: rv_set_bool(&o->res, rv_i32(&c->a) != 0); break;
        default: rv_set_text(&o->res, (const char *)c->a.b, rv_text(&c->a, tbuf, sizeof tbuf)); break;
        }
        break;

    default:                                  /* 6: string，snprintf 后内联 */
        switch (scls) {
        case 0: snprintf(tbuf, sizeof tbuf, "%g", rv_f64(&c->a)); break;
        case 1: { float f; memcpy(&f, c->a.b, 4); snprintf(tbuf, sizeof tbuf, "%g", (double)f); break; }
        case 2: snprintf(tbuf, sizeof tbuf, "%d", rv_i32(&c->a)); break;
        case 3: snprintf(tbuf, sizeof tbuf, "%" PRId64, rv_i64(&c->a)); break;
        case 4: snprintf(tbuf, sizeof tbuf, "%s", rv_i32(&c->a) ? "true" : "false"); break;
        default: rv_text(&c->a, tbuf, sizeof tbuf); break;
        }
        rv_set_text(&o->res, tbuf, strlen(tbuf));
        break;
    }
    o->sp = wsrc - wdst;
    o->ok = 1;
}

/* ── neg：DoNeg 卡。mode 0/3..15 = 强类型取负（就地改载荷、sp 不动）；
 *         mode 1 = 通用取负（box + ToNumber + vneg，NaN 显式规范成
 *         0x7FFFFFFF_FFFFFFFF）；mode 2 = 纯数值化（不取负）。 ── */
static void op_neg(const Case *c, Out *o)
{
    int h = c->type & 0xF, cls;

    if (c->mode == 1 || c->mode == 2) {
        double d, r;
        if (js_tonumber("neg", 1, &c->a, &d, o)) return;
        r = (c->mode == 1) ? -d : d;
        if (isnan(r)) {
            uint64_t bits = 0x7FFFFFFFFFFFFFFFull;
            rv_clear(&o->res);
            memcpy(o->res.b, &bits, 8);
            rv_set_tag(&o->res, TAG_REAL);
        } else {
            rv_set_f64(&o->res, r);
        }
        o->sp = slot_w(h) - 16;
        o->ok = 1;
        return;
    }

    cls = cls_resolve("neg", 1, h, &c->a, o);
    if (cls < 0) return;
    if (cls > 6) { rv_copy(&o->res, &c->a); o->sp = 0; o->ok = 1; return; }
    if (cls == 6) {
        ofail(o, "DoNeg :1: Execution Engine - Cannot operate on string type");
        return;
    }
    switch (cls) {
    case 0: rv_set_f64(&o->res, -rv_f64(&c->a)); break;
    case 1: { float f; memcpy(&f, c->a.b, 4); rv_set_f64(&o->res, -(double)f); break; }
    case 3: rv_set_i64(&o->res, (int64_t)(0ull - (uint64_t)rv_i64(&c->a))); break;
    case 2:
    case 4: rv_set_i32(&o->res, (int32_t)(0u - (uint32_t)rv_i32(&c->a))); break;
    }
    o->sp = 0;                                 /* 就地改载荷，sp 不动 */
    o->ok = 1;
}

/* ── not：DoNot 卡。mode 1 = 逻辑非 !（写 4 B、返回 boxed_sp-4）；
 *         mode 2 = 按位取反 ~（vcvt.s32 → mvn → vcvt.f64.s32，16 B tag 0）；
 *         mode 0/3..15 = 强类型位取反（cls 0 double 经 __fixdfdi/mvn/__floatdidf、
 *         7 int32 mvn、10 int64 mvn 双字、4 bool 是 1-x 且负数归 0）。 ── */
static void op_not(const Case *c, Out *o)
{
    int h = c->type & 0xF, cls;

    if (c->mode == 1) {
        int cls0 = cls_resolve("not", 1, h, &c->a, o);
        if (cls0 < 0) return;
        rv_set_i32(&o->res, truthy(&c->a, cls0) ? 0 : 1);
        o->ok = 1;                              /* JS_ToBoolean → r0^1 → uxtb 写 4 B */
        o->sp = slot_w(h) - 4;
        return;
    }
    if (c->mode == 2) {
        int32_t v;
        if (js_toint32("not", 1, &c->a, &v, o)) return;
        rv_set_f64(&o->res, (double)(int32_t)~v);
        o->sp = slot_w(h) - 16;
        o->ok = 1;
        return;
    }

    cls = cls_resolve("not", 1, h, &c->a, o);
    if (cls < 0) return;
    if (cls > 6) { rv_copy(&o->res, &c->a); o->sp = 0; o->ok = 1; return; }
    if (cls == 6) {
        ofail(o, "DoNot :: Execution Engine - Cannot operate on string type");
        return;
    }
    switch (cls) {
    case 0: rv_set_f64(&o->res, (double)~as_i64(&c->a, 0)); break;
    case 1: { float f; memcpy(&f, c->a.b, 4); rv_set_f64(&o->res, (double)(int32_t)~f2i32((double)f)); break; }
    case 3: rv_set_i64(&o->res, (int64_t)~(uint64_t)rv_i64(&c->a)); break;
    case 4: { int32_t v = rv_i32(&c->a); int32_t r = 1 - v; if (r < 0) r = 0; rv_set_i32(&o->res, r); break; }
    case 2: rv_set_i32(&o->res, (int32_t)~(uint32_t)rv_i32(&c->a)); break;
    }
    o->sp = 0;
    o->ok = 1;
}

/* ── dup：DoDup 卡。mode 0（arg&0xFF00==0）= 普通复制：n=(arg&0x7FFF)+1，协议只带
 *   bits[11:8]，低位计数不可见 → n=1；宽度由 type 字节（0..6）定；返回 sp-n*size。
 *   mode≠0 = swap 模式：只许 type==5，n=(arg&0xF0)/16、m=arg&0x0F —— m 不在协议里，
 *   按 0 处理（交换空操作，deviation #8）。 ── */
static void op_dup(const Case *c, Out *o)
{
    int type = (int)(c->type & 0xFF);
    int w;

    if (c->mode != 0) {
        if (type != 5) {
            /* DoDup 卡：.rodata 0x332aa8 原文就是这句，不带 "DoDup :: " 前缀。 */
            ofail(o, "Argument type %d currently unhandled by "
                     "DoDup swap mode", type);
            return;
        }
        rv_copy(&o->res, &c->a);
        o->sp = 0;
        o->ok = 1;
        return;
    }
    if (type > 6) {                            /* @0xd5600 直接返回，不动栈 */
        rv_copy(&o->res, &c->a);
        o->sp = 0;
        o->ok = 1;
        return;
    }
    w = slot_w(type);
    rv_copy(&o->res, &c->a);
    o->sp = -(long)w;
    o->ok = 1;
}

/* ── push_immediate：DoPushImmediate 卡 —— sxth 后 str r0,[sp,#-4]!，
 *   16 位立即数符号扩展成 4 字节、sp 下移 4。 ── */
static void op_push_immediate(const Case *c, Out *o)
{
    int16_t imm = (int16_t)(c->mode & 0xFFFF);
    rv_set_i32(&o->res, (int32_t)imm);
    o->sp = -4;
    o->ok = 1;
}

/* ═══════════════════════ 7. JSONL 输入 ═══════════════════════ */

/* 在 [s,e) 里找 "key" 并返回 ':' 之后的值起点；找不到返回 NULL。 */
static const char *find_key(const char *s, const char *e, const char *key)
{
    size_t kl = strlen(key);
    const char *p;
    for (p = s; p + kl + 2 < e; p++) {
        const char *q;
        if (*p != '"') continue;
        if (strncmp(p + 1, key, kl) != 0) continue;
        if (p[1 + kl] != '"') continue;
        q = p + 2 + kl;
        while (q < e && (*q == ' ' || *q == '\t' || *q == '\n' || *q == '\r')) q++;
        if (q < e && *q == ':') {
            q++;
            while (q < e && (*q == ' ' || *q == '\t' || *q == '\n' || *q == '\r')) q++;
            return q;
        }
    }
    return NULL;
}

/* '{' 起的花括号配对位置（不含嵌套字符串里的花括号；本协议值里没有）。 */
static const char *obj_end(const char *p, const char *e)
{
    int depth = 0;
    for (; p < e; p++) {
        if (*p == '{') depth++;
        else if (*p == '}') {
            depth--;
            if (depth == 0) return p;
        }
    }
    return e;
}

static int hexval(int c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

static void parse_hex16(const char *s, const char *e, RVal *v)
{
    int i;
    rv_clear(v);
    for (i = 0; i < 16; i++) {
        int hi, lo;
        if (s + 2 > e) break;
        hi = hexval((unsigned char)s[0]);
        lo = hexval((unsigned char)s[1]);
        if (hi < 0 || lo < 0) break;
        v->b[i] = (unsigned char)((hi << 4) | lo);
        s += 2;
    }
}

static void parse_rv(const char *p, const char *e, RVal *v)
{
    const char *end = obj_end(p, e);
    const char *q;

    rv_clear(v);
    q = find_key(p, end, "bytes");
    if (q && *q == '"') parse_hex16(q + 1, end, v);
    q = find_key(p, end, "tag");
    if (q) {
        long t = strtol(q, NULL, 0);
        rv_set_tag(v, (uint32_t)t);
    }
}

static int parse_case(const char *line, const char *e, Case *c)
{
    const char *p, *pend;
    char *q;

    memset(c, 0, sizeof *c);
    p = find_key(line, e, "id");
    if (!p) return 0;
    {
        size_t n = 0;
        if (*p == '"') {
            c->id[n++] = *p++;
            while (p < e && *p != '"' && n + 2 < sizeof c->id) c->id[n++] = *p++;
            if (p < e && *p == '"') c->id[n++] = *p++;
        } else {
            while (p < e && *p != ',' && *p != '}' && *p != ' ' && *p != '\n' &&
                   n + 1 < sizeof c->id)
                c->id[n++] = *p++;
        }
        c->id[n] = '\0';
        if (!c->id[0]) snprintf(c->id, sizeof c->id, "-1");
    }
    p = find_key(line, e, "op");
    if (!p || *p != '"') return 0;
    p++;
    q = c->op;
    while (p < e && *p != '"' && (size_t)(q - c->op) + 1 < sizeof c->op) *q++ = *p++;
    *q = '\0';

    p = find_key(line, e, "mode");
    if (p) c->mode = strtol(p, NULL, 0);
    p = find_key(line, e, "type");
    if (p) c->type = (int)(strtol(p, NULL, 0) & 0xFF);

    p = find_key(line, e, "a");
    if (p) {
        pend = (*p == '{') ? obj_end(p, e) : e;
        parse_rv(p, pend, &c->a);
    }
    p = find_key(line, e, "b");
    if (p) {
        pend = (*p == '{') ? obj_end(p, e) : e;
        parse_rv(p, pend, &c->b);
    }
    return 1;
}

/* ═══════════════════════ 8. 输出 ═══════════════════════ */

static void emit_escaped(const char *s)
{
    for (; *s; s++) {
        unsigned char ch = (unsigned char)*s;
        if (ch == '"' || ch == '\\') putchar('\\'), putchar(ch);
        else if (ch == '\n') fputs("\\n", stdout);
        else if (ch < 0x20) printf("\\u%04x", ch);
        else putchar(ch);
    }
}

static void emit_ok(const Case *c, const Out *o)
{
    char hex[33];
    int i;
    for (i = 0; i < 16; i++) snprintf(hex + 2 * i, 3, "%02x", o->res.b[i]);
    printf("{\"id\":%s,\"ok\":true,\"sp\":%ld,\"result\":{\"bytes\":\"%s\",\"tag\":%u}}\n",
           c->id, o->sp, hex, rv_tag(&o->res));
}

static void emit_err(const Case *c, const Out *o)
{
    /* 协议：失败时 sp 记 0（diff/run_diff.py 的 parse_record 硬要求 sp == 0）。 */
    printf("{\"id\":%s,\"ok\":false,\"sp\":0,\"error\":\"", c->id);
    emit_escaped(o->err);
    fputs("\"}\n", stdout);
}

/* ═══════════════════════ 9. 分派 ═══════════════════════ */

static void dispatch(const Case *c, Out *o)
{
    rv_clear(&o->res);
    o->ok = 1;
    o->sp = 0;
    o->err[0] = '\0';

    if (!strcmp(c->op, "push_immediate")) { op_push_immediate(c, o); return; }
    if (!strcmp(c->op, "dup"))            { op_dup(c, o); return; }
    if (!strcmp(c->op, "conv"))           { op_conv(c, o); return; }
    if (!strcmp(c->op, "add"))            { op_add(c, o); return; }
    if (!strcmp(c->op, "sub"))            { op_sub(c, o); return; }
    if (!strcmp(c->op, "mul"))            { op_mul(c, o); return; }
    if (!strcmp(c->op, "div"))            { op_div(c, o); return; }
    if (!strcmp(c->op, "rem"))            { op_rem(c, o); return; }
    if (!strcmp(c->op, "mod"))            { op_mod(c, o); return; }
    if (!strcmp(c->op, "and"))            { bitwise("and", c, o, AND_OK, BIT_AND); return; }
    if (!strcmp(c->op, "or"))             { bitwise("or",  c, o, OR_OK,  BIT_OR);  return; }
    if (!strcmp(c->op, "xor"))            { bitwise("xor", c, o, XOR_OK, BIT_XOR); return; }
    if (!strcmp(c->op, "shl"))            { op_shl(c, o); return; }
    if (!strcmp(c->op, "shr"))            { op_shr(c, o); return; }
    if (!strcmp(c->op, "neg"))            { op_neg(c, o); return; }
    if (!strcmp(c->op, "not"))            { op_not(c, o); return; }
    if (!strncmp(c->op, "set_", 4))       { op_set(c->op, c, o); return; }

    ofail(o, "vm_ref: unsupported op '%s'", c->op);
}

/* ═══════════════════════ 10. main ═══════════════════════ */

int main(void)
{
    char *line = NULL;
    size_t cap = 0;
    ssize_t n;

    setvbuf(stdout, NULL, _IOLBF, 0);

    while ((n = getline(&line, &cap, stdin)) >= 0) {
        Case c;
        Out o;
        while (n > 0 && (line[n - 1] == '\n' || line[n - 1] == '\r')) line[--n] = '\0';
        if (n == 0) continue;
        if (!parse_case(line, line + n, &c)) continue;
        dispatch(&c, &o);
        if (o.ok) emit_ok(&c, &o);
        else {
            o.sp = 0;
            emit_err(&c, &o);
        }
        fflush(stdout);
    }
    free(line);
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════════
 * known deviations —— 卡片没钉死、或卡与协议冲突的地方：本实现的选择 + 对应 open
 *
 *  #1 字符串载荷。原版是 _RefThing{ptr,refcnt,len} 指向堆缓冲（DoAdd 卡「0x66 拼接」
 *     段、DoDup 卡 tag1 计数在对象 +4）；16 字节镜像装不下堆内容，两个独立实现也不
 *     可能共享指针，所以里程碑 1 的镜像把 ≤11 B ASCII 内联（gen_cases.py 的
 *     Encoding contract）。本实现读写都按内联：拼接/重复结果直接落在 +0..+11，超长
 *     截断；不做 operator new(12)/YYAlloc/refcount 增减。原版的 refcount 语义
 *     （pre-copy 时 ++、销毁时 --）在差分里不可观测，未实现。
 *     对应 open：DoAdd「空串/null 串跳过 strcpy 的所有权约定」、DoDup「type 1/4 元素名」。
 *
 *  #2 sp（栈顶位移）。按卡的统一落点公式：sp_new = sp + 右宽 + 左宽 - 结果宽
 *     （DoAdd 卡「结果落点」段）。所以 pop 两个 4B 槽、push 一个 4B 结果是 +4，
 *     字符串结果（16B RValue）在 0x66 下是 4+4-16 = -8。协议只说「负数=下移」，
 *     没说是否取反，本实现取地址差的字面值。若 Rust 侧用相反符号约定 → 全部行差号。
 *
 *  #3 DoRem 写回的是**商**不是余数（DoRem 卡结论 2，逐指令已证：int32 调 __divsi3、
 *     int64 取 ldivmod 的 r0:r1）。本实现照卡实现，于是 rem 与 div 在整数域等价；
 *     真正取余的是 mod（__aeabi_idivmod / __aeabi_ldivmod 的余数）。卡自己也把这条
 *     列进 open（「既然写回商，DoRem 对应的应是 div」），语义归属待 upstream 修。
 *     另外 DoRem 的 real 除零判定是「|B| 截断为 0」（0.5 也算除零），已按卡实现。
 *
 *  #4 浮点结果与 4 字节槽的 tag。快路径的 4/8 B 裸槽**不写 tag**（DoAdd 卡：
 *     「只有 w=16 的那一路 r4≠0 才把 tag 写回 +0xc」），但输出必须是 16 B RValue，
 *     所以本实现按宽度补规范的 tag：4B → 7(int32)、8B real → 0、8B int64 → 10、
 *     bool 结果 → 13。float32（存储类 1）在 RValue 里没有 tag，本实现宽成 double、
 *     tag 0（DoConv dst1、DoNeg/DoNot 的 cls1 路径）。这两条是编码补全，不是卡的事实。
 *     对应 open：DoNeg「cls 4 在强类型路按 32 位整数取负，而 boxType 的 cls 4 分支
 *     产出 tag 13 + double，两处类型名需统一」—— 本实现 fast path 的 cls4 一律给 tag 7。
 *
 *  #5 mode≠0 的慢路径栈效应。卡给的是 boxType 协议（boxType(dst=sp, cls, sp) 返回
 *     消耗后的 sp），本实现记成：消耗 operands 的槽宽、产出 16 B（或 not 的 ! 4 B）。
 *     即 delta = Σ槽宽 - 产出宽。DoNeg mode1/2、DoNot mode1/2、conv flags、以及
 *     add/sub/div/mod 的 JS 路都按这条。原版的返回值口径本身就是各卡 open
 *     （DoSub/DoDiv「返回值是新 sp 还是新 ip 未定」）。
 *
 *  #6 DoOr 的 pair 4（bool,real）。卡结论 3 明说这个核读的是 opB 槽而非 opA 槽、
 *     与 pair 64/68 的对称性不符、「语义待证」。本实现按 pair 64 的对称语义处理
 *     （bool 归一 0/1 后与 int64(real) orr）。DoAnd 的 (4,·) 混算同理。
 *
 *  #7 tag 表错误串的站点号。卡里每句有两份拷贝（'DoSub :1: illegal array use' /
 *     ':2:'），但没写哪侧是 1。本实现定 a(左)=:1:、b(右)=:2:。DoAdd/DoMul/DoMod/DoOr/
 *     DoNot 的卡只抄到不带站点号的形式 → 走 "<Op> :: ..."。DoNeg 的串型错误按卡原文
 *     带 ':1:'，DoNot 的按卡原文不带。
 *
 *  #8 dup 的 swap 模式。n=(arg&0xF0)/16、m=(arg&0x0F)，协议只暴露 bits[11:8]
 *     （当作 mode）→ n=mode、m=0，交换退化成空操作（返回 sp 不变、结果=栈顶）。
 *     普通 dup 的 n 同理只能取 1（低位计数不在协议里）。
 *
 *  #9 DoSet 的未支持组合给**值**不给错（卡 e33c0：K=4 得 1、其余得 0），本实现照做；
 *     (4,6)/(6,4) 这两条 bool×string 组合卡里可达但语义未展开（open「15 路 RValue-tag
 *     表未逐个展开」）→ 本实现归到「未支持组合」给 0/1。
 *     K=7..15（JS 抽象关系比较、in、==、===）不在协议的 op 表里，未实现；set_* 的 K
 *     一律取 op 名，mode≠0 当作「走卡的通用装箱路径」但结果与快路径同真值。
 *
 * #10 DoShl/DoShr 的移位量越界。快路径 int32 用 ARM 的 lsl/asr（低 8 位、≥32 按符号/
 *     零填）；int64 的 n≥64 卡未覆盖（open），本实现给 0 / 符号填充。慢路径 shl 才
 *     and #31（卡结论 2），shr 的 bit15（>> 还是 >>>）协议没带，按 ToInt32 的 >>
 *     实现（卡 open：bit15 到底选哪个未定）。
 *
 * #11 F_JS_ToNumber/ToInt32 的边角。NaN→int32 给 0、NaN→int64 给 INT64_MIN
 *     （AAPCS __fixdfdi），±Inf/越界饱和。卡没写这些边角，属实现定义。
 *
 * #12 push_immediate 的 mode 超出 16 位时按 (int16_t) 截断（sxth 的语义）。
 * ═══════════════════════════════════════════════════════════════════════════ */
