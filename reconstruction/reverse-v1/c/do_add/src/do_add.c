/* ═══════════════════════════════════════════════════════════════════════════
 * do_add.c — C translation of _Z5DoAddjPhPKhP6VMExec (DoAdd), libyoyo ARMv7.
 *
 *   image  reconstruction/live-mem/libyoyo_armv7.so
 *          SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *   body   0xdc524..0xdd4b4 = 996 instructions, then 19 literal-pool words
 *          (0xdd4b4..0xdd500); total 4060 B.  cards/DoAdd.c counts 1015
 *          "instructions" because it read the pool as instructions too.
 *
 * EVERY instruction of the body appears below as an `@0xADDR <operands>` anchor,
 * exactly once, with the operand text llvm-objdump prints for the pinned image.
 * The anchors are generated from the image by tools/gen_ledger.py, never typed
 * from memory, and harness/do_add_diff.py re-derives them from the bytes: a
 * missing line, a duplicated address or a single changed digit turns the census
 * gate red.
 *
 * ── What the handler is ────────────────────────────────────────────────────
 * `arg` = (cls << 16) | (mode << 8) | flags.  Two operands sit packed back to
 * back on the value stack starting at `sp`; the handler computes
 *
 *   r10 = sp                     (the value-stack pointer)
 *   r7  = sp + size(T)           (where the second operand starts)
 *   r8  = r7 + size(U)           (one past the second operand)
 *
 * where T = cls & 15, U = cls >> 4 are type nibbles, size 8 for real/int64,
 * 16 for a boxed RValue, else 4.  Then a three-level dispatch on the pair byte:
 *
 *   table 1 (0xdc564, 7 entries, index T) -> where the second operand starts
 *   table 5 (0xdc964, 14 entries, index the TAG of a boxed first operand)
 *   table 2 (0xdc598, 7 entries, index U) -> where the second operand ends
 *   table 4 (0xdc908, 14 entries, index the TAG of a boxed second operand)
 *   table 3 (0xdc5c4, 103 entries, index the ORIGINAL cls byte 0..102)
 *       0xdc8a0  r8 -= 8   (8-byte result, no tag store)
 *       0xdc890  r8 -= 16  (16-byte boxed result, tag stored at +0xC)
 *       0xdc760  r8 -= 4   (4-byte result, no tag store)
 *       0xdc9cc  r5 = 0    (not a legal pair; no pair that lands here is one
 *                           the tail accepts, so r5 is never dereferenced)
 *
 * Table 3 is indexed by the cls byte the CALLER passed, not by the pair byte
 * the tag tables produced.  That is the one structural trap in this body: the
 * boxed-operand resolution rewrites the type nibble for the arithmetic but the
 * result SLOT still comes from the original byte.
 *
 * r4 is the boxed-result pointer; only the 16-byte routing sets it, and only
 * then does the epilogue (`cmp r4,#0 ; strne r12,[r4,#0xc]`) store a tag word.
 * The handler returns r8, so the caller sees the stack shrink by
 * size(T)+size(U)-result size.
 *
 * ── The type tower ─────────────────────────────────────────────────────────
 * Type nibbles: 0 real (8 B), 1 float (4 B), 2 int32 (4 B), 3 int64 (8 B),
 * 4 bool (4 B), 5 boxed RValue (16 B), 6 string (4 B).  1 and 7..15 have no
 * legal arithmetic pair; they reach `DoAdd :: Execution Error`.
 * Boxed operands resolve by tag: 0/13 -> real, 1 -> string, 7 -> int32,
 * 10 -> int64; 2 (array), 3 (pointer), 5 (undefined) and everything else report
 * a :1:/:2: message and leave the pair byte alone, so the tail refuses the pair
 * a second time with `DoAdd :: Execution Error`.
 *
 * The card's correction is reproduced here: DoAdd has BOTH the vadd.f64 limbs
 * (0xdc8dc, 0xdc9c0, 0xdc9e8, 0xdcc0c, 0xdccf8, 0xdcd80) and the wrapping
 * 64-bit integer limbs (0xdccd8, 0xdcd10, 0xdcd2c: adds/adc; 0xdcd48: a 32-bit
 * add for int32+int32 that keeps tag 7; 0xdcd3c likewise).  The 32-bit side of
 * an int32+int64 pair is sign-extended into the 64-bit add (`adc r3,r3,r1,asr
 * #31`), which is what makes INT64 wraparound reachable from a 4-byte operand.
 *
 * ── Scope, stated up front ─────────────────────────────────────────────────
 * covered     mode 0 and the mode 3..15 fall-through: the whole arm, every pair
 *             byte 0..102, every RValue tag 0..15 in both operand positions.
 *             mode 1 / mode 2: the numeric limb (types 0/2/3/4, and type 9 in
 *             the second slot) plus the ReferenceError limb (types 7/8/>9, the
 *             ones boxType leaves untagged).
 *             string + string (pair 0x66): concat order, length arithmetic, the
 *             result object and the input refcount decrement.
 * NOT claimed mode 1's string limb (0xdd180..0xdd2ac: F_JS_ToString twice, then
 *             the same concat) — F_JS_ToString is not recovered.
 *             the free branch of the string path (0xdcea0 / 0xdcef8: YYFree +
 *             _RefThing<const char*>::dec + operator delete) — not recovered;
 *             the differential stages refcount >= 2 so it never runs.
 *             modes 1/2 with a string / array / pointer / object operand: that
 *             needs strtod and the JS object hooks, neither recovered.
 * ── Callees ───────────────────────────────────────────────────────────────
 * REAL, linked from its own C body: boxType @0xd7784 (c/box_type.c).
 * MODELLED here and named as such: F_JS_ToNumber @0x24cfac and
 * F_JS_ToPrimitive @0x24cd64, both only over the tags boxType can emit for the
 * staged types (0, 13, 5).  The differential judges the model against the
 * original's own bytes; a wrong model goes red, it does not pass quietly.
 * ─────────────────────────────────────────────────────────────────────────── */
#include "do_add.h"

#include <string.h>

/* ── every string the handler can hand to VMError / JSThrow* ──────────────── */
enum {
    E_GENERIC = 0,   /* 0x332fc0  DoAdd :: Execution Error                   */
    E1_POINTER,      /* 0x332ed0  DoAdd :1: illegal pointer use              */
    E1_UNDEF,        /* 0x332ef0  DoAdd :1: undefined value                  */
    E1_ARRAY,        /* 0x332f0c  DoAdd :1: illegal array use                */
    E1_MALFORMED,    /* 0x332f28  DoAdd :1: Malformed variable               */
    E2_POINTER,      /* 0x332f48  DoAdd :2: illegal pointer use              */
    E2_UNDEF,        /* 0x332f68  DoAdd :2: undefined value                  */
    E2_ARRAY,        /* 0x332f84  DoAdd :2: illegal array use                */
    E2_MALFORMED,    /* 0x332fa0  DoAdd :2: Malformed variable               */
    E_REF_BEFORE1,   /* 0x332ca4  could not find variable before '+' operator */
    E_REF_AFTER1,    /* 0x332cd0  could not find variable after '+' operator  */
    E_REF_BEFORE2,   /* 0x332e00  could not find variable before '+'          */
    E_REF_AFTER2,    /* 0x332e24  could not find variable after '+'           */
    E_PRIM_LEFT,     /* 0x332cfc  left-hand-side  ... to a primitive          */
    E_PRIM_RIGHT,    /* 0x332d3c  right-hand-side ... to a primitive          */
    E_NUM_LEFT1,     /* 0x332d80  left-hand-side  ... to a number             */
    E_NUM_RIGHT1,    /* 0x332dc0  right-hand-side ... to a number             */
    E_NUM_LEFT2,     /* 0x332e48  left-hand-side  ... to a number # 2         */
    E_NUM_RIGHT2,    /* 0x332e8c  right-hand-side ... to a number # 2         */
    E_MODE1_STRING   /* not an original string: declared gap, see the header  */
};

static const char *const k_err[] = {
    "DoAdd :: Execution Error",
    "DoAdd :1: illegal pointer use",
    "DoAdd :1: undefined value",
    "DoAdd :1: illegal array use",
    "DoAdd :1: Malformed variable",
    "DoAdd :2: illegal pointer use",
    "DoAdd :2: undefined value",
    "DoAdd :2: illegal array use",
    "DoAdd :2: Malformed variable",
    "could not find variable before '+' operator",
    "could not find variable after '+' operator",
    "could not find variable before '+'",
    "could not find variable after '+'",
    "Could not convert left-hand-side of add operator to a primitive",
    "Could not convert right-hand-side of add operator to a primitive",
    "Could not convert left-hand-side of add operator to a number",
    "Could not convert right-hand-side of add operator to a number",
    "Could not convert left-hand-side of add operator to a number # 2",
    "Could not convert right-hand-side of add operator to a number # 2",
    "MODE1 STRING LIMB NOT TRANSLATED"
};

static const char *g_error;

const char *do_add_last_error(void) { return g_error; }

/* The original can report twice on one call: a boxed operand whose tag is not
 * arithmetic emits a :1:/:2: message and then the tail refuses the pair and
 * emits `DoAdd :: Execution Error`.  The differential (and any reader of the
 * first VMError frame) sees the FIRST one, so this keeps the first. */
#ifdef MUTANT
#  error "do_add.c no longer uses -DMUTANT: use -DDO_ADD_MUTANT (box_type.c owns MUTANT)"
#endif

static void set_err(int idx)
{
    if (!g_error)
        g_error = k_err[idx];
}

/* ── 判别性反例（TEETH）────────────────────────────────────────────────────
 * Each mutant must turn the differential RED on at least one named case.  A
 * green mutant means the case set never exercises that decision, i.e. the
 * "identical" result was toothless.  Only -DMUTANT=n builds contain them. */
#ifdef DO_ADD_MUTANT
#if DO_ADD_MUTANT == 1
#  define M_SEXT_NONE 1            /* int32 -> int64 without sign extension */
#elif DO_ADD_MUTANT == 2
#  define M_I32_AS_U32 1           /* int32 promoted to double as unsigned */
#elif DO_ADD_MUTANT == 3
#  define M_SIZES_SWAPPED 1        /* first/second operand sizes swapped */
#elif DO_ADD_MUTANT == 4
#  define M_TAIL_SIZES_FROM_PAIR 1 /* result slot from the pair, not from cls */
#elif DO_ADD_MUTANT == 5
#  define M_NO_TAG_STORE 1         /* the r4 tag store dropped */
#elif DO_ADD_MUTANT == 6
#  define M_TAG_ALWAYS 1           /* tag stored even when r4 == 0 */
#elif DO_ADD_MUTANT == 7
#  define M_TAG14_REAL 1           /* RValue tag 14 treated as real */
#elif DO_ADD_MUTANT == 8
#  define M_REAL_SUB 1             /* real limb subtracts */
#elif DO_ADD_MUTANT == 9
#  define M_FLOATDIDF_TRUNC 1      /* int64 -> double through int32 */
#elif DO_ADD_MUTANT == 10
#  define M_ERR12_SWAP 1           /* the :1: and :2: strings swapped */
#elif DO_ADD_MUTANT == 11
#  define M_CONCAT_ORDER 1         /* concat lhs then rhs */
#elif DO_ADD_MUTANT == 12
#  define M_MODE2_AT_R8 1          /* mode 2 result at r8, not r8-16 */
#elif DO_ADD_MUTANT == 13
#  define M_VARIANT_NO_ADVANCE 1   /* boxed first operand consumes 0 bytes */
#elif DO_ADD_MUTANT == 14
#  define M_NO_REFCOUNT 1          /* input string refcounts left alone */
#elif DO_ADD_MUTANT == 15
#  define M_I64_AS_I32 1           /* int64 pairs done in 32 bits */
#else
#  error "unknown DO_ADD_MUTANT"
#endif
#endif

/* ── byte-level accessors (the handler is pure byte surgery) ─────────────── */
static uint32_t rd32(const unsigned char *p)
{
    uint32_t v;
    memcpy(&v, p, 4);
    return v;
}

static void wr32(unsigned char *p, uint32_t v) { memcpy(p, &v, 4); }

static uint64_t rd64(const unsigned char *p)
{
    uint64_t v;
    memcpy(&v, p, 8);
    return v;
}

static void wr64(unsigned char *p, uint64_t v) { memcpy(p, &v, 8); }

static double rd_d(const unsigned char *p)
{
    double d;
    memcpy(&d, p, 8);
    return d;
}

static void wr_d(unsigned char *p, double d) { memcpy(p, &d, 8); }

/* `vstr s10,[r8,#-16]` + `str r3,[r8,#-0xc]`: a double leaves the VFP as two
 * separate 32-bit stores, and a poisoned destination can see the difference
 * between that and one 8-byte store. */
static void st_d_words(unsigned char *dst, double d)
{
    uint64_t bits;
    memcpy(&bits, &d, 8);
    wr32(dst, (uint32_t)bits);
    wr32(dst + 4, (uint32_t)(bits >> 32));
}

/* boxType @0xd7784 — recovered separately (c/box_type.c), linked for real */
extern unsigned char *boxType(unsigned char *dst, unsigned type,
                              const unsigned char *src);

/* ── the string objects the concat path allocates ──────────────────────────
 * `operator new(12)` for the header, `YYAlloc(total+1)` for the characters.  A
 * bump pool stands in for both; the differential normalises the resulting
 * pointer, so only the header's three fields and the characters are compared. */
#define STRPOOL_BYTES 0x4000u
static unsigned char g_strpool[STRPOOL_BYTES] __attribute__((aligned(16)));
static unsigned g_strpool_used;

static void *strpool_alloc(unsigned n)
{
    void *p;
    n = (n + 15u) & ~15u;
    if (g_strpool_used + n > STRPOOL_BYTES)
        return 0;
    p = g_strpool + g_strpool_used;
    g_strpool_used += n;
    return p;
}

/* ── F_JS_ToNumber @0x24cfac, modelled over the tags that can reach it ─────
 * JS_OK when the conversion happened, JS_THREW when the original would throw
 * JSThrowTypeError (an unparseable string - out of the staged domain), JS_NOOP
 * for the "nothing written" tags the original answers with 0.  The real
 * function is NOT recovered; the differential judges this model. */
enum { JS_OK = 0, JS_THREW = 1, JS_NOOP = 2 };

static int js_to_number(unsigned char *dst, const unsigned char *src)
{
    uint32_t tag = rd32(src + 12);
    switch (tag) {
    case 0:                     /* already a real */
    case 13: {                  /* bool: boxType stored the double itself */
        double d = rd_d(src);
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 7: {
        double d = (double)(int32_t)rd32(src);
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 10: {
        double d = (double)(int64_t)rd64(src);
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 5:                     /* undefined */
    case 12: {                  /* null */
        double d = 0.0;
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    default:
        return JS_NOOP;
    }
}

/* ── F_JS_ToPrimitive @0x24cd64, modelled over the same tags ───────────────
 * For a real or a bool the primitive IS the value: a 16-byte copy.  Strings and
 * objects are out of the staged domain and return JS_NOOP. */
static int js_to_primitive(unsigned char *dst, const unsigned char *src)
{
    uint32_t tag = rd32(src + 12);
    switch (tag) {
    case 0:                     /* real   */
    case 13:                    /* bool   */
    case 5:                     /* undefined: already a primitive */
    case 12:                    /* null      already a primitive */
        memcpy(dst, src, 16);
        return JS_OK;
    case 7: {
        double d = (double)(int32_t)rd32(src);
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 10: {
        double d = (double)(int64_t)rd64(src);
        wr_d(dst, d);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    default:
        return JS_NOOP;
    }
}

/* mode 1 and mode 2 share the numeric tail's result placement. */
static unsigned char *numeric_out(unsigned char *fr, unsigned char *r8)
{
    double d = rd_d(fr + 88) + rd_d(fr + 104);
    wr32(r8 - 4, 0);
#ifdef M_MODE2_AT_R8
    st_d_words(r8, d);
    return r8;
#else
    st_d_words(r8 - 16, d);
    return r8 - 16;
#endif
}

/* ═══ mode 0 — the strong-typed arm (also reached by mode 3..15) ════════════
 * Block order below follows EXECUTION order, which is not address order: a
 * boxed first operand is resolved at 0xdc954 before control jumps back to the
 * second-operand dispatch at 0xdc580.  Each block header carries its address. */
static unsigned char *mode0(unsigned cls, unsigned char *sp)
{
    unsigned char *const r10 = sp;
    unsigned char *r7 = sp;
    unsigned char *r8 = sp;
    unsigned char *r4 = 0;
    unsigned char *r5 = 0;
    unsigned pair = cls;
    unsigned T = cls & 15u;
    unsigned U;
    uint32_t tagv = 0;

    /* ── 表 1 @0xdc564..0xdc57c：首操作数尺寸 ────────────────────────────
     * 0/3 -> sp+8, 1/2/4/6 -> sp+4, 5 -> 装箱（由 0xdc954 那个标签派发决定
     * 类型后把 r7 定在 sp+16），>6 没有入口，落到 0xdd4a0（下面是 U 块）。 */
    /* @0xdc554 and r2, r9, #15 */
    /* @0xdc558 cmp r2, #6 */
    /* @0xdc55c addls pc, pc, r2, lsl #2 */
    /* @0xdc560 b 0xdd4a0 */
    /* @0xdc564 b 0xdc948 */
    /* @0xdc568 b 0xdc580 */
    /* @0xdc56c b 0xdc580 */
    /* @0xdc570 b 0xdc948 */
    /* @0xdc574 b 0xdc580 */
    /* @0xdc578 b 0xdc954 */
    /* @0xdc57c b 0xdc580 */
    if (T <= 6u) {
#ifdef M_SIZES_SWAPPED
        r7 = (T == 0u || T == 3u) ? r10 + 4 : r10 + 8;
#else
        if (T == 0u || T == 3u)
            r7 = r10 + 8;
        else if (T == 5u)
            r7 = r10 + 16;      /* 0xdcd94 / 0xdcd8c: add r7, r10, #16 */
        else
            r7 = r10 + 4;
#endif
    } else {
        r7 = r10;               /* 0xdd4a0: mov r7, r10 */
    }

    /* ── 0xdd4a0 / 0xdd4ac：两个 "超范围类型" 的桩 ────────────────────────
     * 首操作数类型 > 6 时 0xdd4a0 只把 r6 = cls、r7 = sp 就回到第二个操作数
     * 的派发；第二操作数类型 > 6 时 0xdd4ac 只把 r8 = r7，表 3 照旧按 cls 选
     * 槽位，算术尾巴随后以 `DoAdd :: Execution Error` 收场。 */
    /* @0xdd4a0 mov r6, r9 */
    /* @0xdd4a4 mov r7, r10 */
    /* @0xdd4a8 b 0xdc588 */
    /* @0xdd4ac mov r8, r7 */
    /* @0xdd4b0 b 0xdc5b8 */

    /* ── 表 5 @0xdc964..0xdc998 + 它的处理体：首操作数是装箱 RValue ───────
     * 只改 pair 的**低**四位（处理体用 r0 = 原始 cls 的高半字节），错误体
     * (0xdcd9c/0xdcdbc/0xdcddc/0xdcf94) 用 `mov r6, r9` 把 pair 还原成原始
     * 字节，于是尾部会再拒一次。所有体都以 0xdcd94 的 `add r7,r10,#16` 结束，
     * 然后回到 0xdc588 重新派发第二操作数。 */
    /* @0xdcd8c and r0, r0, #240 */
    /* @0xdcd90 orr r6, r0, #3 */
    /* @0xdcd94 add r7, r10, #16 */
    /* @0xdcd98 b 0xdc588 */
    /* @0xdcd9c ldr r1, [pc, #0x714] */
    /* @0xdcda0 mov r0, r3 */
    /* @0xdcda4 str r3, [sp, #0x4] */
    /* @0xdcda8 mov r6, r9 */
    /* @0xdcdac add r1, pc, r1 */
    /* @0xdcdb0 bl 0xd4210 */
    /* @0xdcdb4 ldr r3, [sp, #0x4] */
    /* @0xdcdb8 b 0xdcd94 */
    /* @0xdcdbc ldr r1, [pc, #0x6f8] */
    /* @0xdcdc0 mov r0, r3 */
    /* @0xdcdc4 str r3, [sp, #0x4] */
    /* @0xdcdc8 mov r6, r9 */
    /* @0xdcdcc add r1, pc, r1 */
    /* @0xdcdd0 bl 0xd4210 */
    /* @0xdcdd4 ldr r3, [sp, #0x4] */
    /* @0xdcdd8 b 0xdcd94 */
    /* @0xdcddc ldr r1, [pc, #0x6dc] */
    /* @0xdcde0 mov r0, r3 */
    /* @0xdcde4 str r3, [sp, #0x4] */
    /* @0xdcde8 mov r6, r9 */
    /* @0xdcdec add r1, pc, r1 */
    /* @0xdcdf0 bl 0xd4210 */
    /* @0xdcdf4 ldr r3, [sp, #0x4] */
    /* @0xdcdf8 b 0xdcd94 */
    /* @0xdcdfc and r0, r0, #240 */
    /* @0xdce00 orr r6, r0, #6 */
    /* @0xdce04 b 0xdcd94 */
    /* @0xdce08 and r0, r0, #240 */
    /* @0xdce0c orr r6, r0, #2 */
    /* @0xdce10 b 0xdcd94 */
    /* @0xdce14 and r6, r9, #240 */
    /* @0xdce18 b 0xdcd94 */
    if (T == 5u) {
        uint32_t tag = rd32(r10 + 12);
        pair = cls;
        switch (tag) {
        case 0:
        case 13:
            pair = cls & 0xF0u;                     /* 0xdce14 */
            break;
        case 1:
            pair = (cls & 0xF0u) | 6u;              /* 0xdcdfc */
            break;
        case 7:
            pair = (cls & 0xF0u) | 2u;              /* 0xdce08 */
            break;
        case 10:
            pair = (cls & 0xF0u) | 3u;              /* 0xdcd8c */
            break;
#ifdef M_TAG14_REAL
        case 14:
            pair = cls & 0xF0u;                     /* MUTANT: 14 is not real */
            break;
#endif
        case 2:
#ifdef M_ERR12_SWAP
            set_err(E2_ARRAY);
#else
            set_err(E1_ARRAY);                      /* 0xdcddc */
#endif
            break;
        case 3:
#ifdef M_ERR12_SWAP
            set_err(E2_POINTER);
#else
            set_err(E1_POINTER);                    /* 0xdcdbc */
#endif
            break;
        case 5:
#ifdef M_ERR12_SWAP
            set_err(E2_UNDEF);
#else
            set_err(E1_UNDEF);                      /* 0xdcd9c */
#endif
            break;
        default:
#ifdef M_ERR12_SWAP
            set_err(E2_MALFORMED);
#else
            set_err(E1_MALFORMED);                  /* 0xdcf94 */
#endif
            break;
        }
#ifdef M_VARIANT_NO_ADVANCE
        r7 = r10;                                   /* MUTANT: no advance */
#else
        r7 = r10 + 16;                              /* 0xdcd94 */
#endif
    }

    U = (pair >> 4) & 15u;

    /* ── 表 2 @0xdc598..0xdc5b0：第二操作数尺寸 ──────────────────────────
     * 索引是 pair 的**高**四位：0/3 -> +8（0xdc940），1/2/4/6 -> +4（0xdc5b4），
     * 5 -> 表 4 定类型后 +16（0xdce24），>6 -> 0xdd4ac 的 `mov r8, r7`。 */
    /* @0xdc580 add r7, r10, #4 */
    /* @0xdc584 mov r6, r9 */
    /* @0xdc588 asr r2, r6, #4 */
    /* @0xdc58c cmp r2, #6 */
    /* @0xdc590 addls pc, pc, r2, lsl #2 */
    /* @0xdc594 b 0xdd4ac */
    /* @0xdc598 b 0xdc940 */
    /* @0xdc59c b 0xdc5b4 */
    /* @0xdc5a0 b 0xdc5b4 */
    /* @0xdc5a4 b 0xdc940 */
    /* @0xdc5a8 b 0xdc5b4 */
    /* @0xdc5ac b 0xdc8f8 */
    /* @0xdc5b0 b 0xdc5b4 */
    /* @0xdc5b4 add r8, r7, #4 */
    if (U == 5u) {
        /* ── 表 4 @0xdc908..0xdc93c + 处理体 0xdce1c..0xdce94 ──────────────
         * 改的是 pair 的**高**四位；0xdce24 的 `add r8,r7,#16` 是共同出口。 */
    /* @0xdce1c and r6, r6, #15 */
    /* @0xdce20 orr r6, r6, #48 */
    /* @0xdce24 add r8, r7, #16 */
    /* @0xdce28 b 0xdc5b8 */
    /* @0xdce2c and r6, r6, #15 */
    /* @0xdce30 orr r6, r6, #32 */
    /* @0xdce34 b 0xdce24 */
    /* @0xdce38 ldr r1, [pc, #0x684] */
    /* @0xdce3c mov r0, r3 */
    /* @0xdce40 str r3, [sp, #0x4] */
    /* @0xdce44 add r1, pc, r1 */
    /* @0xdce48 bl 0xd4210 */
    /* @0xdce4c ldr r3, [sp, #0x4] */
    /* @0xdce50 b 0xdce24 */
    /* @0xdce54 ldr r1, [pc, #0x66c] */
    /* @0xdce58 mov r0, r3 */
    /* @0xdce5c str r3, [sp, #0x4] */
    /* @0xdce60 add r1, pc, r1 */
    /* @0xdce64 bl 0xd4210 */
    /* @0xdce68 ldr r3, [sp, #0x4] */
    /* @0xdce6c b 0xdce24 */
    /* @0xdce70 ldr r1, [pc, #0x654] */
    /* @0xdce74 mov r0, r3 */
    /* @0xdce78 str r3, [sp, #0x4] */
    /* @0xdce7c add r1, pc, r1 */
    /* @0xdce80 bl 0xd4210 */
    /* @0xdce84 ldr r3, [sp, #0x4] */
    /* @0xdce88 b 0xdce24 */
    /* @0xdce8c and r6, r6, #15 */
    /* @0xdce90 orr r6, r6, #96 */
    /* @0xdce94 b 0xdce24 */
    /* @0xdce98 and r6, r6, #15 */
        uint32_t tag = rd32(r7 + 12);
        switch (tag) {
        case 0:
        case 13:
            pair &= 15u;                            /* 0xdce98 */
            break;
        case 1:
            pair = (pair & 15u) | 0x60u;            /* 0xdce8c */
            break;
        case 7:
            pair = (pair & 15u) | 0x20u;            /* 0xdce2c */
            break;
        case 10:
            pair = (pair & 15u) | 0x30u;            /* 0xdce1c */
            break;
#ifdef M_TAG14_REAL
        case 14:
            pair &= 15u;
            break;
#endif
        case 2:
            set_err(E2_ARRAY);                      /* 0xdce70 */
            break;
        case 3:
            set_err(E2_POINTER);                    /* 0xdce54 */
            break;
        case 5:
            set_err(E2_UNDEF);                      /* 0xdce38 */
            break;
        default:
            set_err(E2_MALFORMED);                  /* 0xdcf78 */
            break;
        }
        r8 = r7 + 16;                               /* 0xdce24 */
    } else if (U <= 6u) {
        r8 = r7 + ((U == 0u || U == 3u) ? 8 : 4);
    } else {
        r8 = r7;                                    /* 0xdd4ac */
    }

    /* ── 表 3 @0xdc5c4..0xdc75c：103 个入口，索引是**原始** cls 字节 ──────
     *   0  2  3 32 35 48 50 51       -> 0xdc8a0  r8 -= 8   (r4 = 0)
     *   5 37 53 80 82 83 85 86 101  -> 0xdc890  r8 -= 16  (r4 = r8)
     *   34 102                      -> 0xdc760  r8 -= 4   (r4 = 0)
     *   其余（含 >102）               -> 0xdc9cc  r5 = r4 = 0
     * 合法 pair 恰好都落在前三组，所以 r5 = 0 永远不会被当作目的地。 */
    /* @0xdc5b8 cmp r9, #102 */
    /* @0xdc5bc addls pc, pc, r9, lsl #2 */
    /* @0xdc5c0 b 0xdc9cc */
    /* @0xdc5c4 b 0xdc8a0 */
    /* @0xdc5c8 b 0xdc9cc */
    /* @0xdc5cc b 0xdc8a0 */
    /* @0xdc5d0 b 0xdc8a0 */
    /* @0xdc5d4 b 0xdc9cc */
    /* @0xdc5d8 b 0xdc890 */
    /* @0xdc5dc b 0xdc9cc */
    /* @0xdc5e0 b 0xdc9cc */
    /* @0xdc5e4 b 0xdc9cc */
    /* @0xdc5e8 b 0xdc9cc */
    /* @0xdc5ec b 0xdc9cc */
    /* @0xdc5f0 b 0xdc9cc */
    /* @0xdc5f4 b 0xdc9cc */
    /* @0xdc5f8 b 0xdc9cc */
    /* @0xdc5fc b 0xdc9cc */
    /* @0xdc600 b 0xdc9cc */
    /* @0xdc604 b 0xdc9cc */
    /* @0xdc608 b 0xdc9cc */
    /* @0xdc60c b 0xdc9cc */
    /* @0xdc610 b 0xdc9cc */
    /* @0xdc614 b 0xdc9cc */
    /* @0xdc618 b 0xdc9cc */
    /* @0xdc61c b 0xdc9cc */
    /* @0xdc620 b 0xdc9cc */
    /* @0xdc624 b 0xdc9cc */
    /* @0xdc628 b 0xdc9cc */
    /* @0xdc62c b 0xdc9cc */
    /* @0xdc630 b 0xdc9cc */
    /* @0xdc634 b 0xdc9cc */
    /* @0xdc638 b 0xdc9cc */
    /* @0xdc63c b 0xdc9cc */
    /* @0xdc640 b 0xdc9cc */
    /* @0xdc644 b 0xdc8a0 */
    /* @0xdc648 b 0xdc9cc */
    /* @0xdc64c b 0xdc760 */
    /* @0xdc650 b 0xdc8a0 */
    /* @0xdc654 b 0xdc9cc */
    /* @0xdc658 b 0xdc890 */
    /* @0xdc65c b 0xdc9cc */
    /* @0xdc660 b 0xdc9cc */
    /* @0xdc664 b 0xdc9cc */
    /* @0xdc668 b 0xdc9cc */
    /* @0xdc66c b 0xdc9cc */
    /* @0xdc670 b 0xdc9cc */
    /* @0xdc674 b 0xdc9cc */
    /* @0xdc678 b 0xdc9cc */
    /* @0xdc67c b 0xdc9cc */
    /* @0xdc680 b 0xdc9cc */
    /* @0xdc684 b 0xdc8a0 */
    /* @0xdc688 b 0xdc9cc */
    /* @0xdc68c b 0xdc8a0 */
    /* @0xdc690 b 0xdc8a0 */
    /* @0xdc694 b 0xdc9cc */
    /* @0xdc698 b 0xdc890 */
    /* @0xdc69c b 0xdc9cc */
    /* @0xdc6a0 b 0xdc9cc */
    /* @0xdc6a4 b 0xdc9cc */
    /* @0xdc6a8 b 0xdc9cc */
    /* @0xdc6ac b 0xdc9cc */
    /* @0xdc6b0 b 0xdc9cc */
    /* @0xdc6b4 b 0xdc9cc */
    /* @0xdc6b8 b 0xdc9cc */
    /* @0xdc6bc b 0xdc9cc */
    /* @0xdc6c0 b 0xdc9cc */
    /* @0xdc6c4 b 0xdc9cc */
    /* @0xdc6c8 b 0xdc9cc */
    /* @0xdc6cc b 0xdc9cc */
    /* @0xdc6d0 b 0xdc9cc */
    /* @0xdc6d4 b 0xdc9cc */
    /* @0xdc6d8 b 0xdc9cc */
    /* @0xdc6dc b 0xdc9cc */
    /* @0xdc6e0 b 0xdc9cc */
    /* @0xdc6e4 b 0xdc9cc */
    /* @0xdc6e8 b 0xdc9cc */
    /* @0xdc6ec b 0xdc9cc */
    /* @0xdc6f0 b 0xdc9cc */
    /* @0xdc6f4 b 0xdc9cc */
    /* @0xdc6f8 b 0xdc9cc */
    /* @0xdc6fc b 0xdc9cc */
    /* @0xdc700 b 0xdc9cc */
    /* @0xdc704 b 0xdc890 */
    /* @0xdc708 b 0xdc9cc */
    /* @0xdc70c b 0xdc890 */
    /* @0xdc710 b 0xdc890 */
    /* @0xdc714 b 0xdc9cc */
    /* @0xdc718 b 0xdc890 */
    /* @0xdc71c b 0xdc890 */
    /* @0xdc720 b 0xdc9cc */
    /* @0xdc724 b 0xdc9cc */
    /* @0xdc728 b 0xdc9cc */
    /* @0xdc72c b 0xdc9cc */
    /* @0xdc730 b 0xdc9cc */
    /* @0xdc734 b 0xdc9cc */
    /* @0xdc738 b 0xdc9cc */
    /* @0xdc73c b 0xdc9cc */
    /* @0xdc740 b 0xdc9cc */
    /* @0xdc744 b 0xdc9cc */
    /* @0xdc748 b 0xdc9cc */
    /* @0xdc74c b 0xdc9cc */
    /* @0xdc750 b 0xdc9cc */
    /* @0xdc754 b 0xdc9cc */
    /* @0xdc758 b 0xdc890 */
    /* @0xdc75c b 0xdc760 */
    {
        int placed = 0;
#ifdef M_TAIL_SIZES_FROM_PAIR
        unsigned key = pair;
#else
        unsigned key = cls;
#endif
        if (key <= 102u) {
            switch (key) {
            case 0:
            case 2:
            case 3:
            case 32:
            case 35:
            case 48:
            case 50:
            case 51:
                r8 -= 8;
                placed = 1;
                break;
            case 5:
            case 37:
            case 53:
            case 80:
            case 82:
            case 83:
            case 85:
            case 86:
            case 101:
                r8 -= 16;
                r4 = r8;
                placed = 1;
                break;
            case 34:
            case 102:
                r8 -= 4;
                placed = 1;
                break;
            default:
                break;
            }
        }
        r5 = placed ? r8 : 0;
    }

    /* ── 0xdc890 / 0xdc8a0：表 3 的两个尺寸桩 ────────────────────────────
     * 只做 `sub r8,r8,#16 ; mov r4,r5,r8` 与 `sub r8,r8,#8 ; mov r4,#0 ;
     * mov r5,r8`，效果已在上面表 3 的 switch 里落地。 */
    /* @0xdc890 sub r4, r8, #16 */
    /* @0xdc894 mov r5, r4 */
    /* @0xdc898 mov r8, r4 */
    /* @0xdc89c b 0xdc76c */
    /* @0xdc8a0 sub r8, r8, #8 */
    /* @0xdc8a4 mov r4, #0 */
    /* @0xdc8a8 mov r5, r8 */
    /* @0xdc8ac b 0xdc76c */

    /* ── 尾部头 @0xdc760..0xdc790：按**解析后**的 pair 选算术 ────────────
     * 0xdc760 是表 3 里 cls 34/102 的目标（`sub r8,r8,#4`，已在表 3 落地）；
     * 0xdc764..0xdc790 是 r6 与 34/50/51/102 的四次比较 —— 下面 switch 的
     * 标签顺序与机器里的比较顺序一致。 */
    /* @0xdc760 sub r8, r8, #4 */
    /* @0xdc764 mov r4, #0 */
    /* @0xdc768 mov r5, r8 */
    /* @0xdc76c cmp r6, #34 */
    /* @0xdc770 beq 0xdcd3c */
    /* @0xdc774 bls 0xdc8b0 */
    /* @0xdc778 cmp r6, #50 */
    /* @0xdc77c beq 0xdcd20 */
    /* @0xdc780 bls 0xdc99c */
    /* @0xdc784 cmp r6, #51 */
    /* @0xdc788 beq 0xdcd04 */
    /* @0xdc78c cmp r6, #102 */
    /* @0xdc790 bne 0xdcd54 */
    switch (pair) {
    case 0x66:                      /* 0xdc794：string + string */
        goto string_pair;

    /* ── 0xdc8b0..0xdc8cc：pair < 0x22 的分派头 + 0xdc8e4 收尾 ──────────
     * `cmp r6,#2 / beq 0xdcce8`、`cmp r6,#3 / beq 0xdcd6c`、`cmp r6,#0x20 /
     * bne 0xdcd54`，以及尾巴共同经过的 0xdc8e4..0xdc8f4（tag 写回、返回 r8）。 */
    /* @0xdc8b0 cmp r6, #2 */
    /* @0xdc8b4 beq 0xdcce8 */
    /* @0xdc8b8 bls 0xdc9d8 */
    /* @0xdc8bc cmp r6, #3 */
    /* @0xdc8c0 beq 0xdcd6c */
    /* @0xdc8c4 cmp r6, #32 */
    /* @0xdc8c8 bne 0xdcd54 */
    /* @0xdc8cc vldr s14, [r7] */
    /* @0xdc8d0 vcvt.f64.s32 d7, s14 */
    /* @0xdc8d4 vldr d6, [r10] */
    /* @0xdc8d8 mov r12, #0 */
    /* @0xdc8dc vadd.f64 d7, d7, d6 */
    /* @0xdc8e0 vstr d7, [r5] */
    /* @0xdc8e4 cmp r4, #0 */
    /* @0xdc8e8 strne r12, [r4, #0xc] */
    /* @0xdc8ec mov r0, r8 */
    /* @0xdc8f0 add sp, sp, #124 */
    /* @0xdc8f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    /* @0xdc8f8 ldr r2, [r7, #0xc] */
    /* @0xdc8fc cmp r2, #13 */
    /* @0xdc900 addls pc, pc, r2, lsl #2 */
    /* @0xdc904 b 0xdcf78 */
    /* @0xdc908 b 0xdce98 */
    /* @0xdc90c b 0xdce8c */
    /* @0xdc910 b 0xdce70 */
    /* @0xdc914 b 0xdce54 */
    /* @0xdc918 b 0xdcf78 */
    /* @0xdc91c b 0xdce38 */
    /* @0xdc920 b 0xdcf78 */
    /* @0xdc924 b 0xdce2c */
    /* @0xdc928 b 0xdcf78 */
    /* @0xdc92c b 0xdcf78 */
    /* @0xdc930 b 0xdce1c */
    /* @0xdc934 b 0xdcf78 */
    /* @0xdc938 b 0xdcf78 */
    /* @0xdc93c b 0xdce98 */
    /* @0xdc940 add r8, r7, #8 */
    /* @0xdc944 b 0xdc5b8 */
    case 0x00: {                    /* 0xdc9d8: vldr/vldr/vadd.f64/vstr */
        double d = rd_d(r10);
#ifdef M_REAL_SUB
        d = d - rd_d(r7);
#else
        d = d + rd_d(r7);
#endif
        st_d_words(r5, d);
        tagv = 0;                   /* 0xdc9ec: mov r12, r6 (r6 == 0) */
        break;
    }
    case 0x02: {                    /* 0xdcce8: vcvt.f64.s32 + vadd.f64 */
        double a;
#if M_I32_AS_U32
        a = (double)rd32(r10);
#else
        a = (double)(int32_t)rd32(r10);
#endif
        st_d_words(r5, a + rd_d(r7));
        tagv = 0;
        break;
    }

    /* ── 0xdcd6c：int64 + real（0xdc948 那组的 0xdc99c 分支）────────────── */
    /* @0xdcd6c ldrd r0, r1, [r10] */
    /* @0xdcd70 bl 0x319164 */
    /* @0xdcd74 vldr d7, [r7] */
    /* @0xdcd78 mov r12, #0 */
    /* @0xdcd7c vmov d5, r0, r1 */
    /* @0xdcd80 vadd.f64 d7, d7, d5 */
    /* @0xdcd84 vstr d7, [r5] */
    /* @0xdcd88 b 0xdc8e4 */
    case 0x03: {                    /* __floatdidf(int64) + real */
        double a = (double)(int64_t)rd64(r10);
        st_d_words(r5, a + rd_d(r7));
        tagv = 0;
        break;
    }

    /* ── 0xdc8cc：real + int32（0xdc8b0 链的 cmp #0x20 分支）─────────────── */
    case 0x20: {
        double b;
#if M_I32_AS_U32
        b = (double)rd32(r7);
#else
        b = (double)(int32_t)rd32(r7);
#endif
        st_d_words(r5, rd_d(r10) + b);
        tagv = 0;
        break;
    }

    /* ── 0xdc948..0xdc9f8：表 5 的表头、0xdc99c 的 pair 0x30、0xdc9cc 的
     * "非法 pair" 出口、0xdc9d8 的 pair 0x00 实数路 ─────────────────────── */
    /* @0xdc948 add r7, r10, #8 */
    /* @0xdc94c mov r6, r9 */
    /* @0xdc950 b 0xdc588 */
    /* @0xdc954 ldr r2, [r10, #0xc] */
    /* @0xdc958 cmp r2, #13 */
    /* @0xdc95c addls pc, pc, r2, lsl #2 */
    /* @0xdc960 b 0xdcf94 */
    /* @0xdc964 b 0xdce14 */
    /* @0xdc968 b 0xdcdfc */
    /* @0xdc96c b 0xdcddc */
    /* @0xdc970 b 0xdcdbc */
    /* @0xdc974 b 0xdcf94 */
    /* @0xdc978 b 0xdcd9c */
    /* @0xdc97c b 0xdcf94 */
    /* @0xdc980 b 0xdce08 */
    /* @0xdc984 b 0xdcf94 */
    /* @0xdc988 b 0xdcf94 */
    /* @0xdc98c b 0xdcd8c */
    /* @0xdc990 b 0xdcf94 */
    /* @0xdc994 b 0xdcf94 */
    /* @0xdc998 b 0xdce14 */
    /* @0xdc99c cmp r6, #35 */
    /* @0xdc9a0 beq 0xdcccc */
    /* @0xdc9a4 cmp r6, #48 */
    /* @0xdc9a8 bne 0xdcd54 */
    /* @0xdc9ac ldrd r0, r1, [r7] */
    /* @0xdc9b0 bl 0x319164 */
    /* @0xdc9b4 vldr d7, [r10] */
    /* @0xdc9b8 mov r12, #0 */
    /* @0xdc9bc vmov d6, r0, r1 */
    /* @0xdc9c0 vadd.f64 d7, d6, d7 */
    /* @0xdc9c4 vstr d7, [r5] */
    /* @0xdc9c8 b 0xdc8e4 */
    /* @0xdc9cc mov r5, #0 */
    /* @0xdc9d0 mov r4, r5 */
    /* @0xdc9d4 b 0xdc76c */
    /* @0xdc9d8 cmp r6, #0 */
    /* @0xdc9dc bne 0xdcd54 */
    /* @0xdc9e0 vldr d6, [r7] */
    /* @0xdc9e4 vldr d7, [r10] */
    /* @0xdc9e8 vadd.f64 d7, d6, d7 */
    /* @0xdc9ec mov r12, r6 */
    /* @0xdc9f0 vstr d7, [r5] */
    /* @0xdc9f4 b 0xdc8e4 */

    /* ── 0xdccc0..0xdcd50：四个整数尾巴 ─────────────────────────────────
     * 0xdcccc  int64 + sext(int32)   (pair 0x23)
     * 0xdcd04  int64 + int64         (pair 0x33)
     * 0xdcd20  sext(int32) + int64   (pair 0x32)
     * 0xdcd3c  int32 + int32         (pair 0x22)  —— tag 7，不含进位 */
    /* @0xdccc0 bl 0xc0a7c */
    /* @0xdccc4 mov r0, r5 */
    /* @0xdccc8 b 0xdc8f0 */
    /* @0xdcccc ldr r1, [r7] */
    /* @0xdccd0 mov r12, #10 */
    /* @0xdccd4 ldrd r2, r3, [r10] */
    /* @0xdccd8 adds r2, r2, r1 */
    /* @0xdccdc adc r3, r3, r1, asr #31 */
    /* @0xdcce0 strd r2, r3, [r5] */
    /* @0xdcce4 b 0xdc8e4 */
    /* @0xdcce8 vldr s14, [r10] */
    /* @0xdccec vcvt.f64.s32 d7, s14 */
    /* @0xdccf0 vldr d6, [r7] */
    /* @0xdccf4 mov r12, #0 */
    /* @0xdccf8 vadd.f64 d7, d6, d7 */
    /* @0xdccfc vstr d7, [r5] */
    /* @0xdcd00 b 0xdc8e4 */
    /* @0xdcd04 ldrd r0, r1, [r7] */
    /* @0xdcd08 mov r12, #10 */
    /* @0xdcd0c ldrd r2, r3, [r10] */
    /* @0xdcd10 adds r2, r2, r0 */
    /* @0xdcd14 adc r3, r3, r1 */
    /* @0xdcd18 strd r2, r3, [r5] */
    /* @0xdcd1c b 0xdc8e4 */
    /* @0xdcd20 ldr r1, [r10] */
    /* @0xdcd24 mov r12, #10 */
    /* @0xdcd28 ldrd r2, r3, [r7] */
    /* @0xdcd2c adds r2, r2, r1 */
    /* @0xdcd30 adc r3, r3, r1, asr #31 */
    /* @0xdcd34 strd r2, r3, [r5] */
    /* @0xdcd38 b 0xdc8e4 */
    /* @0xdcd3c ldr r2, [r7] */
    /* @0xdcd40 mov r12, #7 */
    /* @0xdcd44 ldr r3, [r10] */
    /* @0xdcd48 add r3, r2, r3 */
    /* @0xdcd4c str r3, [r5] */
    /* @0xdcd50 b 0xdc8e4 */
    case 0x23: {
        int64_t a = (int64_t)rd64(r10);
#if M_SEXT_NONE
        int64_t b = (int64_t)(uint64_t)rd32(r7);
#else
        int64_t b = (int64_t)(int32_t)rd32(r7);
#endif
#ifdef M_I64_AS_I32
        wr64(r5, (uint64_t)(int64_t)(int32_t)((int32_t)a + (int32_t)b));
#else
        wr64(r5, (uint64_t)(a + b));
#endif
        tagv = 10;
        break;
    }
    case 0x30: {                    /* 0xdc9ac: __floatdidf(int64) + real */
        double b;
#ifdef M_FLOATDIDF_TRUNC
        b = (double)(int32_t)rd64(r7);
#else
        b = (double)(int64_t)rd64(r7);
#endif
        st_d_words(r5, rd_d(r10) + b);
        tagv = 0;
        break;
    }
    case 0x32: {
        int64_t b = (int64_t)rd64(r7);
#if M_SEXT_NONE
        int64_t a = (int64_t)(uint64_t)rd32(r10);
#else
        int64_t a = (int64_t)(int32_t)rd32(r10);
#endif
#ifdef M_I64_AS_I32
        wr64(r5, (uint64_t)(int64_t)(int32_t)((int32_t)a + (int32_t)b));
#else
        wr64(r5, (uint64_t)(a + b));
#endif
        tagv = 10;
        break;
    }
    case 0x33: {
#ifdef M_I64_AS_I32
        wr64(r5, (uint64_t)(int64_t)(int32_t)((int32_t)rd32(r10) +
                                             (int32_t)rd32(r7)));
#else
        wr64(r5, rd64(r10) + rd64(r7));
#endif
        tagv = 10;
        break;
    }
    case 0x22: {                    /* 0xdcd3c: 32 位加法，回绕，tag 7 */
        uint32_t v = rd32(r7) + rd32(r10);
        wr32(r5, v);
        tagv = 7;
        break;
    }

    /* ── 0xdcd54：其余一切 pair 的出口 ──────────────────────────────────
     * `VMError(exec, "DoAdd :: Execution Error")` 之后仍然走 0xdc8e4 的收尾，
     * 所以 16 字节装箱路由下这个 tag 0 会被写进结果槽。 */
    /* @0xdcd54 ldr r1, [pc, #0x758] */
    /* @0xdcd58 mov r0, r3 */
    /* @0xdcd5c add r1, pc, r1 */
    /* @0xdcd60 bl 0xd4210 */
    /* @0xdcd64 mov r12, #0 */
    /* @0xdcd68 b 0xdc8e4 */
    default:
        set_err(E_GENERIC);
        tagv = 0;                   /* 0xdcd64: mov r12, #0 */
        break;
    }
    goto epilogue;

    /* ── 字符串 + 字符串（pair 0x66，0xdc794..0xdc88c）────────────────────
     * 结果 object = {char*, refcount = 1, len}；字符缓冲先放**第二**个操作数
     * （r7 指的那个）再放第一个 —— 表达式里先压栈的一侧在结果的**后面**。
     * 两个输入 object 的 refcount 各减一；减到 0 的释放链没恢复（见头注）。 */
string_pair:
    {
        /* 0xdc538 的 124 字节帧属于被调方自己的栈，不属于调用方的值栈：
         * 原版的 sp 在 STACK 区，这里用一块同样大小的局部帧代替。帧里每个字节
         * 在用之前都被写过（零 + tag 0x00FFFFFF），所以两臂不必共享帧内容。 */
        unsigned char frame[124] __attribute__((aligned(8)));
        unsigned char *const fr = frame;
        unsigned char *lhs;
        unsigned char *rhs;
        unsigned char *obj;
        char *buf;
        char *rhs_txt;
        uint32_t len1;
        uint32_t total;
    /* @0xdc794 ldr r9, [r10] */
    /* @0xdc798 mov r0, #12 */
    /* @0xdc79c ldr r6, [r7] */
    /* @0xdc7a0 cmp r9, #0 */
    /* @0xdc7a4 streq r9, [sp, #0x8] */
    /* @0xdc7a8 ldrne r2, [r9] */
    /* @0xdc7ac strne r2, [sp, #0x8] */
    /* @0xdc7b0 cmp r6, #0 */
    /* @0xdc7b4 ldrne r1, [r6] */
    /* @0xdc7b8 moveq r1, r6 */
    /* @0xdc7bc cmp r9, #0 */
    /* @0xdc7c0 ldrne r7, [r9, #0x8] */
    /* @0xdc7c4 moveq r7, r9 */
    /* @0xdc7c8 cmp r6, #0 */
    /* @0xdc7cc streq r6, [sp, #0xc] */
    /* @0xdc7d0 ldrne r3, [r6, #0x8] */
    /* @0xdc7d4 str r1, [sp, #0x4] */
    /* @0xdc7d8 strne r3, [sp, #0xc] */
    /* @0xdc7dc ldr r2, [sp, #0xc] */
    /* @0xdc7e0 add r7, r2, r7 */
    /* @0xdc7e4 bl 0x27c524 */
    /* @0xdc7e8 mov r10, r0 */
    /* @0xdc7ec add r0, r7, #1 */
    /* @0xdc7f0 bl 0xcef4c */
    /* @0xdc7f4 ldr r1, [sp, #0x4] */
    /* @0xdc7f8 mov r12, #1 */
    /* @0xdc7fc str r7, [r10, #0x8] */
    /* @0xdc800 cmp r1, #0 */
    /* @0xdc804 mov r11, r0 */
    /* @0xdc808 stm r10, {r11, r12} */
    /* @0xdc80c beq 0xdc814 */
    /* @0xdc810 bl 0xb65a4 */
    /* @0xdc814 ldr r3, [sp, #0x8] */
    /* @0xdc818 cmp r3, #0 */
    /* @0xdc81c beq 0xdc830 */
    /* @0xdc820 ldr r2, [sp, #0xc] */
    /* @0xdc824 mov r1, r3 */
    /* @0xdc828 add r0, r11, r2 */
    /* @0xdc82c bl 0xb65a4 */
    /* @0xdc830 cmp r9, #0 */
    /* @0xdc834 mov r1, #0 */
    /* @0xdc838 strb r1, [r11, r7] */
    /* @0xdc83c str r10, [r5] */
    /* @0xdc840 beq 0xdc860 */
    /* @0xdc844 bl 0x190f2c */
    /* @0xdc848 ldr r5, [r9, #0x4] */
    /* @0xdc84c sub r5, r5, #1 */
    /* @0xdc850 str r5, [r9, #0x4] */
    /* @0xdc854 cmp r5, #0 */
    /* @0xdc858 beq 0xdcea0 */
    /* @0xdc85c bl 0x190f30 */
    /* @0xdc860 cmp r6, #0 */
    /* @0xdc864 moveq r12, #1 */
    /* @0xdc868 beq 0xdc8e4 */
    /* @0xdc86c bl 0x190f2c */
    /* @0xdc870 ldr r5, [r6, #0x4] */
    /* @0xdc874 sub r5, r5, #1 */
    /* @0xdc878 str r5, [r6, #0x4] */
    /* @0xdc87c cmp r5, #0 */
    /* @0xdc880 beq 0xdcef8 */
    /* @0xdc884 bl 0x190f30 */
    /* @0xdc888 mov r12, #1 */
    /* @0xdc88c b 0xdc8e4 */
        lhs = (unsigned char *)(uintptr_t)rd32(r10);
        rhs = (unsigned char *)(uintptr_t)rd32(r7);
        if (lhs)
            wr32(fr + 8, rd32(lhs));
        else
            wr32(fr + 8, 0);                        /* streq r9,[sp,#8] */
        rhs_txt = rhs ? (char *)(uintptr_t)rd32(rhs) : (char *)rhs;
        len1 = lhs ? rd32(lhs + 8) : 0;             /* ldrne r7,[r9,#8] */
        if (rhs)
            wr32(fr + 12, rd32(rhs + 8));
        else
            wr32(fr + 12, 0);                       /* streq r6,[sp,#0xc] */
        wr32(fr + 4, (uint32_t)(uintptr_t)rhs_txt);
        total = rd32(fr + 12) + len1;               /* add r7, r2, r7 */

        obj = (unsigned char *)strpool_alloc(12);
        buf = (char *)strpool_alloc(total + 1u);
        wr32(obj + 8, total);                       /* str r7,[r10,#8] */
        wr32(obj, (uint32_t)(uintptr_t)buf);        /* stm r10,{r11,r12} */
        wr32(obj + 4, 1u);
#if M_CONCAT_ORDER
        if (rd32(fr + 8))
            strcpy(buf, (char *)(uintptr_t)rd32(fr + 8));
        if (rhs_txt)
            strcpy(buf + len1, rhs_txt);
#else
        if (rhs_txt)
            strcpy(buf, rhs_txt);
        if (rd32(fr + 8))
            strcpy(buf + rd32(fr + 12), (char *)(uintptr_t)rd32(fr + 8));
#endif
        buf[total] = 0;                             /* strb r1,[r11,r7] */
        wr32(r5, (uint32_t)(uintptr_t)obj);         /* str r10,[r5] */
#ifndef M_NO_REFCOUNT
        if (lhs)
            wr32(lhs + 4, rd32(lhs + 4) - 1u);
        if (rhs)
            wr32(rhs + 4, rd32(rhs + 4) - 1u);
#endif
        tagv = 1;                                   /* mov r12, #1 */
    }

epilogue:
    /* 0xdc8e4: `cmp r4,#0 ; strne r12,[r4,#0xc]` —— 只有 16 字节装箱结果带
     * tag 写回；4/8 字节结果的 tag 由调用方的 cls 隐含。 */
#if defined(M_TAG_ALWAYS)
    wr32((r4 ? r4 : r8) + 12, tagv);        /* MUTANT: unconditional tag store */
#elif defined(M_NO_TAG_STORE)
    (void)r4;                               /* MUTANT: the tag store is gone */
    (void)tagv;
#else
    if (r4)
        wr32(r4 + 12, tagv);
#endif
    return r8;
}

/* ═══ mode 1 — generic `+`: boxType, ToPrimitive, then number or string ════
 * The 124-byte frame the entry reserves; six 16-byte slots at sp+24, +40, +56,
 * +72, +88 and +104 (the CALLEE's sp, so strictly below the caller's stack).
 * The first boxType takes the caller's sp and the second takes its return, so
 * the pair's size nibbles decide where the boxes read from. */
static unsigned char *mode1(unsigned cls, unsigned char *sp)
{
    unsigned char frame[124] __attribute__((aligned(8)));
    unsigned char *const fr = frame;
    unsigned char *r8;
    unsigned T = cls & 15u;
    unsigned U = (cls >> 4) & 15u;
    int rc;

    /* @0xdc9f8 add r7, sp, #40 */
    /* @0xdc9fc mov r2, r1 */
    /* @0xdca00 and r1, r9, #15 */
    /* @0xdca04 mov r3, #0 */
    /* @0xdca08 mov r0, r7 */
    /* @0xdca0c mvn r6, #-16777216 */
    /* @0xdca10 str r3, [sp, #0x20] */
    /* @0xdca14 mov r10, #0 */
    /* @0xdca18 str r3, [sp, #0x30] */
    /* @0xdca1c mov r11, #0 */
    /* @0xdca20 str r3, [sp, #0x4] */
    /* @0xdca24 add r5, sp, #24 */
    /* @0xdca28 strd r10, r11, [sp, #24] */
    /* @0xdca2c strd r10, r11, [sp, #40] */
    /* @0xdca30 str r6, [sp, #0x24] */
    /* @0xdca34 str r6, [sp, #0x34] */
    /* @0xdca38 bl 0xd7784 */
    /* @0xdca3c lsr r1, r9, #4 */
    /* @0xdca40 mov r2, r0 */
    /* @0xdca44 mov r0, r5 */
    /* @0xdca48 bl 0xd7784 */
    /* @0xdca4c ldr r2, [sp, #0x24] */
    /* @0xdca50 ldr r3, [sp, #0x4] */
    /* @0xdca54 and r2, r2, r6 */
    /* @0xdca58 cmp r2, r6 */
    /* @0xdca5c mov r8, r0 */
    /* @0xdca60 beq 0xdd064 */
    /* @0xdca64 ldr r2, [sp, #0x34] */
    /* @0xdca68 bic r2, r2, #-16777216 */
    /* @0xdca6c cmp r2, r6 */
    /* @0xdca70 beq 0xdcf50 */
    /* @0xdca74 add r4, sp, #56 */
    /* @0xdca78 mov r2, r3 */
    /* @0xdca7c mov r1, r5 */
    /* @0xdca80 strd r10, r11, [sp, #56] */
    /* @0xdca84 mov r0, r4 */
    /* @0xdca88 str r3, [sp, #0x40] */
    /* @0xdca8c str r6, [sp, #0x44] */
    /* @0xdca90 strd r10, r11, [sp, #72] */
    /* @0xdca94 str r3, [sp, #0x50] */
    /* @0xdca98 str r6, [sp, #0x54] */
    /* @0xdca9c bl 0x24cd64 */
    /* @0xdcaa0 cmp r0, #1 */
    /* @0xdcaa4 beq 0xdd15c */
    /* @0xdcaa8 cmp r0, #0 */
    /* @0xdcaac beq 0xdcfb4 */
    /* @0xdcab0 ldr r3, [sp, #0x24] */
    /* @0xdcab4 sub r3, r3, #1 */
    /* @0xdcab8 bic r3, r3, #-16777216 */
    /* @0xdcabc bic r3, r3, #3 */
    /* @0xdcac0 cmp r3, #0 */
    /* @0xdcac4 beq 0xdd084 */
    /* @0xdcac8 ldr r1, [sp, #0x34] */
    /* @0xdcacc mov r3, #0 */
    /* @0xdcad0 str r3, [sp, #0x20] */
    /* @0xdcad4 mov r2, #5 */
    /* @0xdcad8 sub r1, r1, #1 */
    /* @0xdcadc str r3, [sp, #0x18] */
    /* @0xdcae0 bic r3, r1, #-16777216 */
    /* @0xdcae4 str r2, [sp, #0x24] */
    /* @0xdcae8 bic r3, r3, #3 */
    /* @0xdcaec cmp r3, #0 */
    /* @0xdcaf0 beq 0xdd078 */
    /* @0xdcaf4 ldr r1, [sp, #0x44] */
    /* @0xdcaf8 mov r3, #0 */
    /* @0xdcafc str r3, [sp, #0x30] */
    /* @0xdcb00 mov r2, #5 */
    /* @0xdcb04 sub r1, r1, #1 */
    /* @0xdcb08 str r3, [sp, #0x28] */
    /* @0xdcb0c bic r3, r1, #-16777216 */
    /* @0xdcb10 str r2, [sp, #0x34] */
    /* @0xdcb14 bic r3, r3, #3 */
    /* @0xdcb18 cmp r3, #0 */
    /* @0xdcb1c bne 0xdc8ec */
    /* @0xdcb20 mov r0, r4 */
    /* @0xdcb24 bl 0xc0a7c */
    /* @0xdcb28 mov r0, r8 */
    /* @0xdcb2c b 0xdc8f0 */
    wr32(fr + 0x20, 0);
    wr32(fr + 0x30, 0);
    wr32(fr + 0x04, 0);
    wr64(fr + 24, 0);
    wr64(fr + 40, 0);
    wr32(fr + 36, 0x00FFFFFFu);          /* 0xdca30 */
    wr32(fr + 52, 0x00FFFFFFu);          /* 0xdca34 */

    r8 = boxType(fr + 40, T, sp);        /* 0xdca38 */
    r8 = boxType(fr + 24, U, r8);        /* 0xdca48 */

    if ((rd32(fr + 36) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_BEFORE1);          /* 0xdd064 */
        return r8;
    }
    if ((rd32(fr + 52) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_AFTER1);           /* 0xdcf50 */
        return r8;
    }

    wr64(fr + 56, 0);
    wr64(fr + 72, 0);
    wr32(fr + 64, 0);
    wr32(fr + 80, 0);
    wr32(fr + 68, 0x00FFFFFFu);
    wr32(fr + 84, 0x00FFFFFFu);

    rc = js_to_primitive(fr + 56, fr + 24);
    if (rc != JS_OK) {
        if (rc == JS_THREW)
            set_err(E_PRIM_LEFT);        /* 0xdd15c */
        return r8;                       /* 0xdcab0 释放临时量后返回 */
    }
    rc = js_to_primitive(fr + 72, fr + 40);
    if (rc != JS_OK) {
        if (rc == JS_THREW)
            set_err(E_PRIM_RIGHT);       /* 0xdd0a4 */
        return r8;
    }
    if ((rd32(fr + 68) & 0x00FFFFFFu) == 1u ||
        (rd32(fr + 84) & 0x00FFFFFFu) == 1u) {
        /* 0xdd180..0xdd2ac: F_JS_ToString + 同一个拼接。F_JS_ToString 未恢复，
         * 不做翻译；回执把这个缺口列出来，用例集也不生成这个分支。 */
        set_err(E_MODE1_STRING);
        return r8;
    }

    wr64(fr + 88, 0);
    wr64(fr + 104, 0);
    wr32(fr + 96, 0);
    wr32(fr + 112, 0);
    wr32(fr + 100, 0x00FFFFFFu);
    wr32(fr + 116, 0x00FFFFFFu);

    if (js_to_number(fr + 88, fr + 56) == JS_THREW) {
        set_err(E_NUM_LEFT1);            /* 0xdd480 */
        return r8;
    }
    if (js_to_number(fr + 104, fr + 72) == JS_THREW) {
        set_err(E_NUM_RIGHT1);           /* 0xdd490 */
        return r8;
    }
    /* 0xdd438: `str r0,[r8,#-4]` 先落 tag 0，然后两半 4 字节存 double 到
     * r8-16；返回 r8-16。 */
    return numeric_out(fr, r8);
}

/* ═══ mode 2 — plain numeric coercion: boxType then F_JS_ToNumber twice ════ */
static unsigned char *mode2(unsigned cls, unsigned char *sp)
{
    unsigned char frame[124] __attribute__((aligned(8)));
    unsigned char *const fr = frame;
    unsigned char *r8;
    unsigned T = cls & 15u;
    unsigned U = (cls >> 4) & 15u;

    /* @0xdcb30 add r6, sp, #72 */
    /* @0xdcb34 mov r2, r1 */
    /* @0xdcb38 and r1, r9, #15 */
    /* @0xdcb3c mvn r5, #-16777216 */
    /* @0xdcb40 mov r0, r6 */
    /* @0xdcb44 mov r10, #0 */
    /* @0xdcb48 mov r11, #0 */
    /* @0xdcb4c mov r7, #0 */
    /* @0xdcb50 strd r10, r11, [sp, #56] */
    /* @0xdcb54 add r4, sp, #56 */
    /* @0xdcb58 strd r10, r11, [sp, #72] */
    /* @0xdcb5c str r7, [sp, #0x40] */
    /* @0xdcb60 str r7, [sp, #0x50] */
    /* @0xdcb64 str r5, [sp, #0x44] */
    /* @0xdcb68 str r5, [sp, #0x54] */
    /* @0xdcb6c bl 0xd7784 */
    /* @0xdcb70 lsr r1, r9, #4 */
    /* @0xdcb74 mov r2, r0 */
    /* @0xdcb78 mov r0, r4 */
    /* @0xdcb7c bl 0xd7784 */
    /* @0xdcb80 ldr r3, [sp, #0x44] */
    /* @0xdcb84 and r3, r3, r5 */
    /* @0xdcb88 cmp r3, r5 */
    /* @0xdcb8c mov r8, r0 */
    /* @0xdcb90 beq 0xdd090 */
    /* @0xdcb94 ldr r3, [sp, #0x54] */
    /* @0xdcb98 bic r3, r3, #-16777216 */
    /* @0xdcb9c cmp r3, r5 */
    /* @0xdcba0 beq 0xdcf64 */
    /* @0xdcba4 add r9, sp, #88 */
    /* @0xdcba8 mov r1, r4 */
    /* @0xdcbac strd r10, r11, [sp, #88] */
    /* @0xdcbb0 mov r0, r9 */
    /* @0xdcbb4 str r7, [sp, #0x60] */
    /* @0xdcbb8 str r5, [sp, #0x64] */
    /* @0xdcbbc strd r10, r11, [sp, #104] */
    /* @0xdcbc0 str r7, [sp, #0x70] */
    /* @0xdcbc4 str r5, [sp, #0x74] */
    /* @0xdcbc8 bl 0x24cfac */
    /* @0xdcbcc cmp r0, #1 */
    /* @0xdcbd0 beq 0xdd16c */
    /* @0xdcbd4 cmp r0, #0 */
    /* @0xdcbd8 bne 0xdc8ec */
    /* @0xdcbdc add r10, sp, #104 */
    /* @0xdcbe0 mov r1, r6 */
    /* @0xdcbe4 mov r0, r10 */
    /* @0xdcbe8 bl 0x24cfac */
    /* @0xdcbec cmp r0, #1 */
    /* @0xdcbf0 beq 0xdd3b0 */
    /* @0xdcbf4 cmp r0, #0 */
    /* @0xdcbf8 bne 0xdc8ec */
    /* @0xdcbfc str r0, [r8, #-0x4] */
    /* @0xdcc00 sub r5, r8, #16 */
    /* @0xdcc04 vldr d6, [sp, #88] */
    /* @0xdcc08 vldr d7, [sp, #104] */
    /* @0xdcc0c vadd.f64 d5, d6, d7 */
    /* @0xdcc10 ldr r1, [sp, #0x44] */
    /* @0xdcc14 sub r1, r1, #1 */
    /* @0xdcc18 bic r1, r1, #-16777216 */
    /* @0xdcc1c bic r1, r1, #3 */
    /* @0xdcc20 cmp r1, #0 */
    /* @0xdcc24 vmov r2, r3, d5 */
    /* @0xdcc28 vstr s10, [r8, #-16] */
    /* @0xdcc2c str r3, [r8, #-0xc] */
    /* @0xdcc30 beq 0xdd398 */
    /* @0xdcc34 ldr r1, [sp, #0x54] */
    /* @0xdcc38 mov r3, #0 */
    /* @0xdcc3c str r3, [sp, #0x40] */
    /* @0xdcc40 mov r2, #5 */
    /* @0xdcc44 sub r1, r1, #1 */
    /* @0xdcc48 str r3, [sp, #0x38] */
    /* @0xdcc4c bic r3, r1, #-16777216 */
    /* @0xdcc50 str r2, [sp, #0x44] */
    /* @0xdcc54 bic r3, r3, #3 */
    /* @0xdcc58 cmp r3, #0 */
    /* @0xdcc5c beq 0xdd38c */
    /* @0xdcc60 ldr r1, [sp, #0x64] */
    /* @0xdcc64 mov r3, #0 */
    /* @0xdcc68 str r3, [sp, #0x50] */
    /* @0xdcc6c mov r2, #5 */
    /* @0xdcc70 sub r1, r1, #1 */
    /* @0xdcc74 str r3, [sp, #0x48] */
    /* @0xdcc78 bic r3, r1, #-16777216 */
    /* @0xdcc7c str r2, [sp, #0x54] */
    /* @0xdcc80 bic r3, r3, #3 */
    /* @0xdcc84 cmp r3, #0 */
    /* @0xdcc88 beq 0xdd3a4 */
    /* @0xdcc8c ldr r1, [sp, #0x74] */
    /* @0xdcc90 mov r3, #0 */
    /* @0xdcc94 str r3, [sp, #0x60] */
    /* @0xdcc98 mov r2, #5 */
    /* @0xdcc9c sub r1, r1, #1 */
    /* @0xdcca0 str r3, [sp, #0x58] */
    /* @0xdcca4 bic r3, r1, #-16777216 */
    /* @0xdcca8 str r2, [sp, #0x64] */
    /* @0xdccac bic r3, r3, #3 */
    /* @0xdccb0 cmp r3, #0 */
    /* @0xdccb4 movne r0, r5 */
    /* @0xdccb8 bne 0xdc8f0 */
    /* @0xdccbc mov r0, r10 */
    wr64(fr + 56, 0);
    wr64(fr + 72, 0);
    wr32(fr + 64, 0);
    wr32(fr + 80, 0);
    wr32(fr + 68, 0x00FFFFFFu);          /* 0xdcb64 */
    wr32(fr + 84, 0x00FFFFFFu);          /* 0xdcb68 */

    r8 = boxType(fr + 72, T, sp);        /* 0xdcb6c */
    r8 = boxType(fr + 56, U, r8);        /* 0xdcb7c */

    if ((rd32(fr + 68) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_BEFORE2);          /* 0xdd090 */
        return r8;
    }
    if ((rd32(fr + 84) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_AFTER2);           /* 0xdcf64 */
        return r8;
    }

    wr64(fr + 88, 0);
    wr64(fr + 104, 0);
    wr32(fr + 96, 0);
    wr32(fr + 112, 0);
    wr32(fr + 100, 0x00FFFFFFu);
    wr32(fr + 116, 0x00FFFFFFu);

    if (js_to_number(fr + 88, fr + 56) == JS_THREW) {
        set_err(E_NUM_LEFT2);            /* 0xdd16c */
        return r8;
    }
    if (js_to_number(fr + 104, fr + 72) == JS_THREW) {
        set_err(E_NUM_RIGHT2);           /* 0xdd3b0 */
        return r8;
    }
    /* 0xdcbfc: tag 0 at r8-4, then the double at r8-16; return r8-16. */
    return numeric_out(fr, r8);
}

/* ═══ entry ════════════════════════════════════════════════════════════════
 * 0xdc524: mode = (arg >> 8) & 15 ; r9 = uxtb(arg >> 16) = the pair byte.
 * 0xdc540: mode 0 -> 0xdc554; 0xdc544/0xdc548: mode 1 -> 0xdc9f8;
 * 0xdc54c/0xdc550: mode 2 -> 0xdcb30; EVERYTHING ELSE FALLS THROUGH to 0xdc554,
 * i.e. modes 3..15 run the strong-typed arm. */
    /* @0xdc524 ubfx r2, r0, #0x8, #0x4 */
    /* @0xdc528 lsr r0, r0, #16 */
    /* @0xdc52c cmp r2, #0 */
    /* @0xdc530 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0xdc534 mov r10, r1 */
    /* @0xdc538 sub sp, sp, #124 */
    /* @0xdc53c uxtb r9, r0 */
    /* @0xdc540 beq 0xdc554 */
    /* @0xdc544 cmp r2, #1 */
    /* @0xdc548 beq 0xdc9f8 */
    /* @0xdc54c cmp r2, #2 */
    /* @0xdc550 beq 0xdcb30 */
unsigned char *DoAdd(uint32_t arg, unsigned char *sp, const unsigned char *base,
                     void *exec)
{
    unsigned mode = (arg >> 8) & 0xFu;
    unsigned cls = (arg >> 16) & 0xFFu;

    (void)base;
    (void)exec;
    g_error = 0;
    g_strpool_used = 0;
    if (mode == 1u)
        return mode1(cls, sp);
    if (mode == 2u)
        return mode2(cls, sp);
    return mode0(cls, sp);
}

/* ═══ 共享错误桩 ═══════════════════════════════════════════════════════════
 * These four stubs live in DoAdd's tail (0xdcf50..0xdd0b0) but belong to the
 * mode-1/mode-2 reference and conversion gates: each one calls VMError or
 * JSThrow* and then returns the SAME r8 the gate already had.  They are
 * annotated here because the C above reaches them from three different
 * functions, an arrangement the addresses cannot express. */
    /* @0xdcf50 ldr r0, [pc, #0x578] */
    /* @0xdcf54 add r0, pc, r0 */
    /* @0xdcf58 bl 0x254b04 */
    /* @0xdcf5c mov r0, r8 */
    /* @0xdcf60 b 0xdc8f0 */
    /* @0xdcf64 ldr r0, [pc, #0x568] */
    /* @0xdcf68 add r0, pc, r0 */
    /* @0xdcf6c bl 0x254b04 */
    /* @0xdcf70 mov r0, r8 */
    /* @0xdcf74 b 0xdc8f0 */
    /* @0xdcf78 ldr r1, [pc, #0x558] */
    /* @0xdcf7c mov r0, r3 */
    /* @0xdcf80 str r3, [sp, #0x4] */
    /* @0xdcf84 add r1, pc, r1 */
    /* @0xdcf88 bl 0xd4210 */
    /* @0xdcf8c ldr r3, [sp, #0x4] */
    /* @0xdcf90 b 0xdce24 */
    /* @0xdcf94 ldr r1, [pc, #0x540] */
    /* @0xdcf98 mov r0, r3 */
    /* @0xdcf9c str r3, [sp, #0x4] */
    /* @0xdd064 ldr r0, [pc, #0x474] */
    /* @0xdd068 add r0, pc, r0 */
    /* @0xdd06c bl 0x254b04 */
    /* @0xdd070 mov r0, r8 */
    /* @0xdd074 b 0xdc8f0 */
    /* @0xdd078 mov r0, r7 */
    /* @0xdd07c bl 0xc0a7c */
    /* @0xdd080 b 0xdcaf4 */
    /* @0xdd084 mov r0, r5 */
    /* @0xdd088 bl 0xc0a7c */
    /* @0xdd08c b 0xdcac8 */
    /* @0xdd090 ldr r0, [pc, #0x44c] */
    /* @0xdd094 add r0, pc, r0 */
    /* @0xdd098 bl 0x254b04 */
    /* @0xdd09c mov r0, r8 */
    /* @0xdd0a0 b 0xdc8f0 */
    /* @0xdd0a4 ldr r0, [pc, #0x43c] */
    /* @0xdd0a8 add r0, pc, r0 */
    /* @0xdd0ac bl 0x24e58c */
    /* @0xdd15c ldr r0, [pc, #0x388] */
    /* @0xdd160 add r0, pc, r0 */
    /* @0xdd164 bl 0x24e58c */
    /* @0xdd168 b 0xdcab0 */
    /* @0xdd16c ldr r0, [pc, #0x37c] */
    /* @0xdd170 add r0, pc, r0 */
    /* @0xdd174 bl 0x24e58c */
    /* @0xdd178 mov r0, r8 */
    /* @0xdd17c b 0xdc8f0 */
    /* @0xdd3b0 ldr r0, [pc, #0x13c] */
    /* @0xdd3b4 add r0, pc, r0 */
    /* @0xdd3b8 bl 0x24e58c */
    /* @0xdd3bc mov r0, r8 */
    /* @0xdd3c0 b 0xdc8f0 */
    /* @0xdd480 ldr r0, [pc, #0x70] */
    /* @0xdd484 add r0, pc, r0 */
    /* @0xdd488 bl 0x24e58c */
    /* @0xdd48c b 0xdd040 */
    /* @0xdd490 ldr r0, [pc, #0x64] */
    /* @0xdd494 add r0, pc, r0 */
    /* @0xdd498 bl 0x24e58c */
    /* @0xdd49c b 0xdd040 */

/* ════ 逐指令台账（自动生成，勿手改）════════════════════════════════════
 * 上面每个 //@@BLOCK 段已就地标注它实现的那段原版指令；下面这段是同一函数里
 * 没有 C 语句的指令：跳转表项、错误桩、以及 DoAdd 里未被本译文执行的路径
 * （例如字符串对象的释放链，依赖尚未恢复的 RefThing/YYFree）。每一条都在
 * 这里出现且只出现一次，操作数逐字取自 llvm-objdump；census 门会把这份台账
 * 与原版字节逐条比对，多一条、少一条、改一个操作数都会红。
 */
/* @0xdce9c b 0xdce24 */
/* @0xdcea0 ldr r0, [r9] */
/* @0xdcea4 bl 0xcef90 */
/* @0xdcea8 str r5, [r9] */
/* @0xdceac str r5, [r9, #0x8] */
/* @0xdceb0 bl 0x190f2c */
/* @0xdceb4 ldr r5, [r9, #0x4] */
/* @0xdceb8 sub r5, r5, #1 */
/* @0xdcebc str r5, [r9, #0x4] */
/* @0xdcec0 cmp r5, #0 */
/* @0xdcec4 bne 0xdcee8 */
/* @0xdcec8 ldr r0, [r9] */
/* @0xdcecc bl 0xcef90 */
/* @0xdced0 mov r0, r9 */
/* @0xdced4 str r5, [r9] */
/* @0xdced8 str r5, [r9, #0x8] */
/* @0xdcedc bl 0xc09f8 */
/* @0xdcee0 mov r0, r9 */
/* @0xdcee4 bl 0x27d1d0 */
/* @0xdcee8 bl 0x190f30 */
/* @0xdceec mov r0, r9 */
/* @0xdcef0 bl 0x27d1d0 */
/* @0xdcef4 b 0xdc85c */
/* @0xdcef8 ldr r0, [r6] */
/* @0xdcefc bl 0xcef90 */
/* @0xdcf00 str r5, [r6] */
/* @0xdcf04 str r5, [r6, #0x8] */
/* @0xdcf08 bl 0x190f2c */
/* @0xdcf0c ldr r5, [r6, #0x4] */
/* @0xdcf10 sub r5, r5, #1 */
/* @0xdcf14 str r5, [r6, #0x4] */
/* @0xdcf18 cmp r5, #0 */
/* @0xdcf1c bne 0xdcf40 */
/* @0xdcf20 ldr r0, [r6] */
/* @0xdcf24 bl 0xcef90 */
/* @0xdcf28 mov r0, r6 */
/* @0xdcf2c str r5, [r6] */
/* @0xdcf30 str r5, [r6, #0x8] */
/* @0xdcf34 bl 0xc09f8 */
/* @0xdcf38 mov r0, r6 */
/* @0xdcf3c bl 0x27d1d0 */
/* @0xdcf40 bl 0x190f30 */
/* @0xdcf44 mov r0, r6 */
/* @0xdcf48 bl 0x27d1d0 */
/* @0xdcf4c b 0xdc884 */

/* @0xdcfa0 mov r6, r9 */
/* @0xdcfa4 add r1, pc, r1 */
/* @0xdcfa8 bl 0xd4210 */
/* @0xdcfac ldr r3, [sp, #0x4] */
/* @0xdcfb0 b 0xdcd94 */
/* @0xdcfb4 add r6, sp, #72 */
/* @0xdcfb8 mov r2, r0 */
/* @0xdcfbc mov r1, r7 */
/* @0xdcfc0 mov r0, r6 */
/* @0xdcfc4 bl 0x24cd64 */
/* @0xdcfc8 cmp r0, #1 */
/* @0xdcfcc beq 0xdd0a4 */
/* @0xdcfd0 cmp r0, #0 */
/* @0xdcfd4 bne 0xdd0b0 */
/* @0xdcfd8 ldr r3, [sp, #0x44] */
/* @0xdcfdc bic r3, r3, #-16777216 */
/* @0xdcfe0 cmp r3, #1 */
/* @0xdcfe4 beq 0xdd180 */
/* @0xdcfe8 ldr r3, [sp, #0x54] */
/* @0xdcfec bic r3, r3, #-16777216 */
/* @0xdcff0 cmp r3, #1 */
/* @0xdcff4 beq 0xdd180 */
/* @0xdcff8 add r9, sp, #88 */
/* @0xdcffc mov r1, r4 */
/* @0xdd000 mov r2, #0 */
/* @0xdd004 mov r3, #0 */
/* @0xdd008 mov r0, r9 */
/* @0xdd00c mov r12, #0 */
/* @0xdd010 strd r2, r3, [sp, #88] */
/* @0xdd014 strd r2, r3, [sp, #104] */
/* @0xdd018 mvn r3, #-16777216 */
/* @0xdd01c str r12, [sp, #0x60] */
/* @0xdd020 str r12, [sp, #0x70] */
/* @0xdd024 str r3, [sp, #0x64] */
/* @0xdd028 str r3, [sp, #0x74] */
/* @0xdd02c bl 0x24cfac */
/* @0xdd030 cmp r0, #1 */
/* @0xdd034 beq 0xdd480 */
/* @0xdd038 cmp r0, #0 */
/* @0xdd03c beq 0xdd418 */
/* @0xdd040 ldr r3, [sp, #0x44] */
/* @0xdd044 sub r3, r3, #1 */
/* @0xdd048 bic r3, r3, #-16777216 */
/* @0xdd04c bic r3, r3, #3 */
/* @0xdd050 cmp r3, #0 */
/* @0xdd054 bne 0xdc8ec */
/* @0xdd058 mov r0, r4 */
/* @0xdd05c bl 0xc0a7c */
/* @0xdd060 b 0xdc8ec */

/* @0xdd0b0 ldr r3, [sp, #0x24] */
/* @0xdd0b4 sub r3, r3, #1 */
/* @0xdd0b8 bic r3, r3, #-16777216 */
/* @0xdd0bc bic r3, r3, #3 */
/* @0xdd0c0 cmp r3, #0 */
/* @0xdd0c4 beq 0xdd3dc */
/* @0xdd0c8 ldr r1, [sp, #0x34] */
/* @0xdd0cc mov r3, #0 */
/* @0xdd0d0 str r3, [sp, #0x20] */
/* @0xdd0d4 mov r2, #5 */
/* @0xdd0d8 sub r1, r1, #1 */
/* @0xdd0dc str r3, [sp, #0x18] */
/* @0xdd0e0 bic r3, r1, #-16777216 */
/* @0xdd0e4 str r2, [sp, #0x24] */
/* @0xdd0e8 bic r3, r3, #3 */
/* @0xdd0ec cmp r3, #0 */
/* @0xdd0f0 beq 0xdd3d0 */
/* @0xdd0f4 ldr r1, [sp, #0x44] */
/* @0xdd0f8 mov r3, #0 */
/* @0xdd0fc str r3, [sp, #0x30] */
/* @0xdd100 mov r2, #5 */
/* @0xdd104 sub r1, r1, #1 */
/* @0xdd108 str r3, [sp, #0x28] */
/* @0xdd10c bic r3, r1, #-16777216 */
/* @0xdd110 str r2, [sp, #0x34] */
/* @0xdd114 bic r3, r3, #3 */
/* @0xdd118 cmp r3, #0 */
/* @0xdd11c beq 0xdd3c4 */
/* @0xdd120 ldr r1, [sp, #0x54] */
/* @0xdd124 mov r3, #0 */
/* @0xdd128 str r3, [sp, #0x40] */
/* @0xdd12c mov r2, #5 */
/* @0xdd130 sub r1, r1, #1 */
/* @0xdd134 str r3, [sp, #0x38] */
/* @0xdd138 bic r3, r1, #-16777216 */
/* @0xdd13c str r2, [sp, #0x44] */
/* @0xdd140 bic r3, r3, #3 */
/* @0xdd144 cmp r3, #0 */
/* @0xdd148 bne 0xdc8ec */
/* @0xdd14c mov r0, r6 */
/* @0xdd150 bl 0xc0a7c */
/* @0xdd154 mov r0, r8 */
/* @0xdd158 b 0xdc8f0 */
/* @0xdd180 add r9, sp, #88 */
/* @0xdd184 add r10, sp, #104 */
/* @0xdd188 mov r1, r4 */
/* @0xdd18c mov r2, #0 */
/* @0xdd190 mov r0, r9 */
/* @0xdd194 mov r3, #0 */
/* @0xdd198 strd r2, r3, [sp, #88] */
/* @0xdd19c strd r2, r3, [sp, #104] */
/* @0xdd1a0 mvn r3, #-16777216 */
/* @0xdd1a4 mov r2, #0 */
/* @0xdd1a8 str r3, [sp, #0x64] */
/* @0xdd1ac str r3, [sp, #0x74] */
/* @0xdd1b0 str r2, [sp, #0x60] */
/* @0xdd1b4 str r2, [sp, #0x70] */
/* @0xdd1b8 sub r2, r8, #16 */
/* @0xdd1bc str r2, [sp, #0x14] */
/* @0xdd1c0 bl 0x24dd3c */
/* @0xdd1c4 mov r1, r6 */
/* @0xdd1c8 mov r0, r10 */
/* @0xdd1cc bl 0x24dd3c */
/* @0xdd1d0 ldr r2, [sp, #0x68] */
/* @0xdd1d4 mov r1, #1 */
/* @0xdd1d8 ldr r3, [sp, #0x58] */
/* @0xdd1dc cmp r2, #0 */
/* @0xdd1e0 str r1, [r8, #-0x4] */
/* @0xdd1e4 streq r2, [sp, #0xc] */
/* @0xdd1e8 ldrne r1, [r2] */
/* @0xdd1ec strne r1, [sp, #0xc] */
/* @0xdd1f0 cmp r3, #0 */
/* @0xdd1f4 mov r0, #12 */
/* @0xdd1f8 ldrne r1, [r3] */
/* @0xdd1fc moveq r1, r3 */
/* @0xdd200 cmp r2, #0 */
/* @0xdd204 ldrne r2, [r2, #0x8] */
/* @0xdd208 cmp r3, #0 */
/* @0xdd20c ldrne r3, [r3, #0x8] */
/* @0xdd210 str r1, [sp, #0x4] */
/* @0xdd214 str r3, [sp, #0x10] */
/* @0xdd218 ldr r3, [sp, #0x10] */
/* @0xdd21c add r2, r3, r2 */
/* @0xdd220 str r2, [sp, #0x8] */
/* @0xdd224 bl 0x27c524 */
/* @0xdd228 ldr r2, [sp, #0x8] */
/* @0xdd22c mov r11, r0 */
/* @0xdd230 add r0, r2, #1 */
/* @0xdd234 bl 0xcef4c */
/* @0xdd238 ldr r1, [sp, #0x4] */
/* @0xdd23c ldr r3, [sp, #0x8] */
/* @0xdd240 mov r12, #1 */
/* @0xdd244 cmp r1, #0 */
/* @0xdd248 str r3, [r11, #0x8] */
/* @0xdd24c mov r2, r0 */
/* @0xdd250 stm r11, {r2, r12} */
/* @0xdd254 beq 0xdd264 */
/* @0xdd258 str r0, [sp, #0x4] */
/* @0xdd25c bl 0xb65a4 */
/* @0xdd260 ldr r2, [sp, #0x4] */
/* @0xdd264 ldr r3, [sp, #0xc] */
/* @0xdd268 cmp r3, #0 */
/* @0xdd26c beq 0xdd288 */
/* @0xdd270 ldr r3, [sp, #0x10] */
/* @0xdd274 ldr r1, [sp, #0xc] */
/* @0xdd278 add r0, r2, r3 */
/* @0xdd27c str r2, [sp, #0x4] */
/* @0xdd280 bl 0xb65a4 */
/* @0xdd284 ldr r2, [sp, #0x4] */
/* @0xdd288 ldr r3, [sp, #0x8] */
/* @0xdd28c mov r1, #0 */
/* @0xdd290 strb r1, [r2, r3] */
/* @0xdd294 ldr r2, [sp, #0x64] */
/* @0xdd298 str r11, [r8, #-0x10] */
/* @0xdd29c sub r3, r2, #1 */
/* @0xdd2a0 bic r3, r3, #-16777216 */
/* @0xdd2a4 bic r3, r3, #3 */
/* @0xdd2a8 cmp r3, r1 */
/* @0xdd2ac beq 0xdd474 */
/* @0xdd2b0 ldr r1, [sp, #0x74] */
/* @0xdd2b4 mov r3, #0 */
/* @0xdd2b8 str r3, [sp, #0x60] */
/* @0xdd2bc mov r2, #5 */
/* @0xdd2c0 sub r1, r1, #1 */
/* @0xdd2c4 str r3, [sp, #0x58] */
/* @0xdd2c8 bic r3, r1, #-16777216 */
/* @0xdd2cc str r2, [sp, #0x64] */
/* @0xdd2d0 bic r3, r3, #3 */
/* @0xdd2d4 cmp r3, #0 */
/* @0xdd2d8 beq 0xdd40c */
/* @0xdd2dc ldr r3, [sp, #0x24] */
/* @0xdd2e0 sub r3, r3, #1 */
/* @0xdd2e4 bic r3, r3, #-16777216 */
/* @0xdd2e8 bic r3, r3, #3 */
/* @0xdd2ec cmp r3, #0 */
/* @0xdd2f0 beq 0xdd400 */
/* @0xdd2f4 ldr r1, [sp, #0x34] */
/* @0xdd2f8 mov r3, #0 */
/* @0xdd2fc str r3, [sp, #0x20] */
/* @0xdd300 mov r2, #5 */
/* @0xdd304 sub r1, r1, #1 */
/* @0xdd308 str r3, [sp, #0x18] */
/* @0xdd30c bic r3, r1, #-16777216 */
/* @0xdd310 str r2, [sp, #0x24] */
/* @0xdd314 bic r3, r3, #3 */
/* @0xdd318 cmp r3, #0 */
/* @0xdd31c beq 0xdd3f4 */
/* @0xdd320 ldr r1, [sp, #0x44] */
/* @0xdd324 mov r3, #0 */
/* @0xdd328 str r3, [sp, #0x30] */
/* @0xdd32c mov r2, #5 */
/* @0xdd330 sub r1, r1, #1 */
/* @0xdd334 str r3, [sp, #0x28] */
/* @0xdd338 bic r3, r1, #-16777216 */
/* @0xdd33c str r2, [sp, #0x34] */
/* @0xdd340 bic r3, r3, #3 */
/* @0xdd344 cmp r3, #0 */
/* @0xdd348 beq 0xdd3e8 */
/* @0xdd34c ldr r1, [sp, #0x54] */
/* @0xdd350 mov r3, #0 */
/* @0xdd354 str r3, [sp, #0x40] */
/* @0xdd358 mov r2, #5 */
/* @0xdd35c sub r1, r1, #1 */
/* @0xdd360 str r3, [sp, #0x38] */
/* @0xdd364 bic r3, r1, #-16777216 */
/* @0xdd368 str r2, [sp, #0x44] */
/* @0xdd36c bic r3, r3, #3 */
/* @0xdd370 cmp r3, #0 */
/* @0xdd374 ldrne r0, [sp, #0x14] */
/* @0xdd378 bne 0xdc8f0 */
/* @0xdd37c mov r0, r6 */
/* @0xdd380 bl 0xc0a7c */
/* @0xdd384 ldr r0, [sp, #0x14] */
/* @0xdd388 b 0xdc8f0 */
/* @0xdd38c mov r0, r6 */
/* @0xdd390 bl 0xc0a7c */
/* @0xdd394 b 0xdcc60 */
/* @0xdd398 mov r0, r4 */
/* @0xdd39c bl 0xc0a7c */
/* @0xdd3a0 b 0xdcc34 */
/* @0xdd3a4 mov r0, r9 */
/* @0xdd3a8 bl 0xc0a7c */
/* @0xdd3ac b 0xdcc8c */
/* @0xdd3c4 mov r0, r4 */
/* @0xdd3c8 bl 0xc0a7c */
/* @0xdd3cc b 0xdd120 */
/* @0xdd3d0 mov r0, r7 */
/* @0xdd3d4 bl 0xc0a7c */
/* @0xdd3d8 b 0xdd0f4 */
/* @0xdd3dc mov r0, r5 */
/* @0xdd3e0 bl 0xc0a7c */
/* @0xdd3e4 b 0xdd0c8 */
/* @0xdd3e8 mov r0, r4 */
/* @0xdd3ec bl 0xc0a7c */
/* @0xdd3f0 b 0xdd34c */
/* @0xdd3f4 mov r0, r7 */
/* @0xdd3f8 bl 0xc0a7c */
/* @0xdd3fc b 0xdd320 */
/* @0xdd400 mov r0, r5 */
/* @0xdd404 bl 0xc0a7c */
/* @0xdd408 b 0xdd2f4 */
/* @0xdd40c mov r0, r10 */
/* @0xdd410 bl 0xc0a7c */
/* @0xdd414 b 0xdd2dc */
/* @0xdd418 add r10, sp, #104 */
/* @0xdd41c mov r1, r6 */
/* @0xdd420 mov r0, r10 */
/* @0xdd424 bl 0x24cfac */
/* @0xdd428 cmp r0, #1 */
/* @0xdd42c beq 0xdd490 */
/* @0xdd430 cmp r0, #0 */
/* @0xdd434 bne 0xdd040 */
/* @0xdd438 str r0, [r8, #-0x4] */
/* @0xdd43c sub r2, r8, #16 */
/* @0xdd440 vldr d6, [sp, #88] */
/* @0xdd444 vldr d7, [sp, #104] */
/* @0xdd448 vadd.f64 d5, d6, d7 */
/* @0xdd44c str r2, [sp, #0x14] */
/* @0xdd450 ldr r1, [sp, #0x64] */
/* @0xdd454 sub r1, r1, #1 */
/* @0xdd458 bic r1, r1, #-16777216 */
/* @0xdd45c bic r1, r1, #3 */
/* @0xdd460 cmp r1, #0 */
/* @0xdd464 vmov r2, r3, d5 */
/* @0xdd468 vstr s10, [r8, #-16] */
/* @0xdd46c str r3, [r8, #-0xc] */
/* @0xdd470 bne 0xdd2b0 */
/* @0xdd474 mov r0, r9 */
/* @0xdd478 bl 0xc0a7c */
/* @0xdd47c b 0xdd2b0 */

/* ── 字面量池 0xdd4b4..0xdd500（19 个字，全函数唯一的 PC 相对数据）──────
 * 上面每条错误的 VMError/JSThrow 都靠 ldr rX,[pc,#..] 从这里取字符串偏移；
 * census 门同时核对这 19 个字的数值，改一个字就会红。 */
/* @0xdd4b4 .word 0x0025625c */
/* @0xdd4b8 .word 0x0025613c */
/* @0xdd4bc .word 0x002560fc */
/* @0xdd4c0 .word 0x00256118 */
/* @0xdd4c4 .word 0x0025611c */
/* @0xdd4c8 .word 0x002560e0 */
/* @0xdd4cc .word 0x00256100 */
/* @0xdd4d0 .word 0x00255d74 */
/* @0xdd4d4 .word 0x00255eb4 */
/* @0xdd4d8 .word 0x00256014 */
/* @0xdd4dc .word 0x00255f7c */
/* @0xdd4e0 .word 0x00255c34 */
/* @0xdd4e4 .word 0x00255d64 */
/* @0xdd4e8 .word 0x00255c8c */
/* @0xdd4ec .word 0x00255b94 */
/* @0xdd4f0 .word 0x00255cd0 */
/* @0xdd4f4 .word 0x00255ad0 */
/* @0xdd4f8 .word 0x002558f4 */
/* @0xdd4fc .word 0x00255924 */
/* ════ 台账结束 ═══════════════════════════════════════════════════════ */
