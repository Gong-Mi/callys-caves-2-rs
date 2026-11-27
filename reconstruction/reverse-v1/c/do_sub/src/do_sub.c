/* ═══════════════════════════════════════════════════════════════════════════
 * do_sub.c — C translation of _Z5DoSubjPhPKhP6VMExec (DoSub), libyoyo ARMv7.
 *
 *   image  reconstruction/live-mem/libyoyo_armv7.so
 *          SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *   body   0xdd500..0xddd24 = 521 instructions, then 17 literal-pool words
 *          (0xddd24..0xddd68); total 2152 B = 538 words.
 *
 * EVERY instruction of the body appears below as an `@0xADDR <operands>` anchor,
 * exactly once, with the operand text llvm-objdump prints for the pinned image.
 * The anchors are generated from the image by tools/gen_ledger.py; the census
 * gate in harness/do_sub_diff.py re-derives them from the bytes.
 *
 * ── Shape ──────────────────────────────────────────────────────────────────
 *   r9 = sp                        (the operand at sp; the SUBTRAHEND)
 *   r10 = sp + size(T)             (the second operand; the MINUEND)
 *   r6 = r10 + size(U)             (one past both; the returned stack pointer)
 *   r7 = the tag slot of a boxed result, or 0
 *   r8 = the result slot (== r6, or r6-16 for a boxed result)
 *   r4 = the cls byte              r5 = the pair byte being resolved
 *   r11 = exec (argument 3)
 *
 *   table 1 (0xdd534, 7 entries, index T) -> where the second operand starts
 *   table 6 (0xdd8d4, 14 entries, index the TAG of a boxed first operand)
 *   table 2 (0xdd578, 7 entries, index U) -> where it ends
 *   table 5 (0xdd864, 14 entries, index the TAG of a boxed second operand)
 *   table 3 (0xdd5b4, 102 entries, index the ORIGINAL cls byte 0..101)
 *       0xdd844  r6 -= 8   (8-byte result, no tag store)
 *       0xdd834  r6 -= 16  (16-byte boxed result, tag stored at +0xC)
 *       0xdd74c  r6 -= 4   (4-byte result, no tag store)
 *       0xdd90c  r8 = 0    (not a legal pair)
 *   table 4 (0xdd764, 52 entries, index the resolved pair) -> the arithmetic
 *
 * The entry tests ONLY `mode == 1`: mode 0 and modes 2..15 all run the
 * strong-typed arm, so `DoSub` has no numeric-coercion mode at all (unlike
 * DoAdd, which has three).
 *
 * ── The subtraction ────────────────────────────────────────────────────────
 * pair 0x00  d7 = [r10] − [r9]                       (vsub.f64)
 * pair 0x02  d7 = [r10] − (double)int32[r9]
 * pair 0x03  d7 = [r10] − (double)int64[r9]          (__floatdidf on the subtrahend)
 * pair 0x20  d7 = (double)int32[r10] − [r9]
 * pair 0x22  r3 = [r10] − [r9]                        (rsb, 32-bit wrap, tag 7)
 * pair 0x23  i64 = sext(int32[r10]) − int64[r9]       (rsbs/rsc)
 * pair 0x30  d7 = (double)int64[r10] − [r9]
 * pair 0x32  i64 = int64[r10] − sext(int32[r9])       (subs/sbc)
 * pair 0x33  i64 = int64[r10] − int64[r9]             (subs/sbc)
 * every other pair: VMError(exec, "DoSub:: Execution Error") and the epilogue.
 * The card's warning holds here too: the integer limbs are inline adds-with-
 * borrow, not vadd/vcvt helpers, and the int32 side of an int32/int64 pair is
 * sign-extended with `rsc r3, r3, r1, asr #31`.
 *
 * ── Type nibbles ──────────────────────────────────────────────────────────
 * 0 real (8 B), 1 float (4 B), 2 int32 (4 B), 3 int64 (8 B), 4 bool (4 B),
 * 5 boxed RValue (16 B), 6 string (4 B).  A string in either position is
 * refused with "DoSub :: Execution Engine - Cannot operate on string type",
 * after which the dispatch continues and the tail usually refuses the pair a
 * second time.  Boxed operands resolve by tag: 0/13 -> real, 7 -> int32,
 * 10 -> int64, 1 -> string, 2 -> array, 3 -> pointer, 5 -> undefined, the rest
 * -> "Malformed variable"; every one of those errors leaves the pair byte
 * alone, so the tail refuses it too.
 * ─────────────────────────────────────────────────────────────────────────── */
#include "do_sub.h"

#include <string.h>

/* ── every string the handler can hand to VMError / JSThrow* ──────────────── */
enum {
    E_STRING = 0,     /* 0x3330b4  DoSub :: Execution Engine - Cannot operate
                                    on string type                          */
    E_GENERIC,        /* 0x3331e0  DoSub:: Execution Error                   */
    E1_UNDEF,         /* 0x333110  DoSub :1: undefined value                 */
    E1_POINTER,       /* 0x3330f0  DoSub :1: illegal pointer use             */
    E1_ARRAY,         /* 0x33312c  DoSub :1: illegal array use               */
    E1_MALFORMED,     /* 0x333148  DoSub :1: Malformed variable              */
    E2_UNDEF,         /* 0x333188  DoSub :2: undefined value                 */
    E2_POINTER,       /* 0x333168  DoSub :2: illegal pointer use             */
    E2_ARRAY,         /* 0x3331a4  DoSub :2: illegal array use               */
    E2_MALFORMED,     /* 0x3331c0  DoSub :2: Malformed variable              */
    E_REF_AFTER,      /* 0x333000  could not find variable after '-'         */
    E_REF_BEFORE,     /* 0x332fdc  could not find variable before '-'        */
    E_NUM_LEFT,       /* 0x333024  left-hand-side ... to a number            */
    E_NUM_RIGHT       /* 0x33306c  right-hand-side ... to a number           */
};

static const char *const k_err[] = {
    "DoSub :: Execution Engine - Cannot operate on string type",
    "DoSub:: Execution Error",
    "DoSub :1: undefined value",
    "DoSub :1: illegal pointer use",
    "DoSub :1: illegal array use",
    "DoSub :1: Malformed variable",
    "DoSub :2: undefined value",
    "DoSub :2: illegal pointer use",
    "DoSub :2: illegal array use",
    "DoSub :2: Malformed variable",
    "could not find variable after '-'",
    "could not find variable before '-'",
    "Could not convert left-hand-side of subtraction operator to a number",
    "Could not convert right-hand-side of subtraction operator to a number"
};

static const char *g_error;

const char *do_sub_last_error(void) { return g_error; }

/* The original can report twice per call (a boxed operand whose tag is not
 * arithmetic reports a :1:/:2: message, then the tail refuses the pair).  The
 * differential sees the FIRST VMError, so this keeps the first. */
static void set_err(int idx)
{
    if (!g_error)
        g_error = k_err[idx];
}

/* ── 判别性反例（TEETH）────────────────────────────────────────────────────
 * Each mutant must turn the differential RED on at least one named case.  The
 * selector is not plain MUTANT because c/box_type.c is linked for real and
 * owns that name. */
#ifdef DO_SUB_MUTANT
#if DO_SUB_MUTANT == 1
#  define M_SEXT_NONE 1            /* int32 -> int64 without sign extension */
#elif DO_SUB_MUTANT == 2
#  define M_I32_AS_U32 1           /* int32 promoted to double as unsigned */
#elif DO_SUB_MUTANT == 3
#  define M_SIZES_SWAPPED 1        /* first/second operand sizes swapped */
#elif DO_SUB_MUTANT == 4
#  define M_TAIL_SIZES_FROM_PAIR 1 /* result slot from the pair, not from cls */
#elif DO_SUB_MUTANT == 5
#  define M_NO_TAG_STORE 1         /* the r7 tag store dropped */
#elif DO_SUB_MUTANT == 6
#  define M_TAG_ALWAYS 1           /* tag stored even when r7 == 0 */
#elif DO_SUB_MUTANT == 7
#  define M_TAG14_REAL 1           /* RValue tag 14 treated as real */
#elif DO_SUB_MUTANT == 8
#  define M_ORDER 1                /* subtrahend and minuend swapped */
#elif DO_SUB_MUTANT == 9
#  define M_FLOATDIDF_TRUNC 1      /* int64 -> double through int32 */
#elif DO_SUB_MUTANT == 10
#  define M_ERR12_SWAP 1           /* the :1: and :2: strings swapped */
#elif DO_SUB_MUTANT == 11
#  define M_MODE1_AT_R6 1          /* mode 1 result at r6, not r6-16 */
#elif DO_SUB_MUTANT == 12
#  define M_VARIANT_NO_ADVANCE 1   /* boxed first operand consumes 0 bytes */
#elif DO_SUB_MUTANT == 13
#  define M_I64_AS_I32 1           /* int64 pairs done in 32 bits */
#elif DO_SUB_MUTANT == 14
#  define M_INT32_ORDER 1          /* int32 pair: [r9] - [r10] */
#else
#  error "unknown DO_SUB_MUTANT"
#endif
#endif
#ifdef MUTANT
#  error "do_sub.c does not use -DMUTANT: use -DDO_SUB_MUTANT (box_type.c owns MUTANT)"
#endif

/* ── byte-level accessors ─────────────────────────────────────────────────── */
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

/* `vstr s10,[r6,#-16]` + `str r3,[r6,#-0xc]`: the two halves of a double leave
 * the VFP as two 32-bit stores. */
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

/* ── F_JS_ToNumber @0x24cfac, modelled over the tags that can reach it ─────
 * JS_OK when the conversion happened, JS_THREW when the original would throw
 * JSThrowTypeError (an unparseable string — out of the staged domain), JS_NOOP
 * for the "nothing written" tags the original answers with 0. */
enum { JS_OK = 0, JS_THREW = 1, JS_NOOP = 2 };

static int js_to_number(unsigned char *dst, const unsigned char *src)
{
    uint32_t tag = rd32(src + 12);
    switch (tag) {
    case 0:                     /* already a real */
    case 13: {                  /* bool: boxType stored the double itself */
        double d = rd_d(src);
        memcpy(dst, &d, 8);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 7: {
        double d = (double)(int32_t)rd32(src);
        memcpy(dst, &d, 8);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 10: {
        double d = (double)(int64_t)rd64(src);
        memcpy(dst, &d, 8);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    case 5:                     /* undefined */
    case 12: {                  /* null */
        double d = 0.0;
        memcpy(dst, &d, 8);
        wr32(dst + 12, 0);
        return JS_OK;
    }
    default:
        return JS_NOOP;
    }
}

/* ═══ the strong-typed arm (mode 0 and modes 2..15) ════════════════════════
 * Block order follows EXECUTION order, which is not address order: a boxed
 * first operand is resolved at 0xdd8c4, and its handlers jump back to the
 * second-operand dispatch at 0xdd568. */
static unsigned char *strong(unsigned cls, unsigned char *sp, void *exec)
{
    const unsigned char *const r9 = sp;
    unsigned char *r10 = sp;
    unsigned char *r6 = sp;
    unsigned char *r7 = 0;
    unsigned char *r8 = sp;
    unsigned pair = cls;
    unsigned T = cls & 15u;
    unsigned U;
    uint32_t tagv = 0;

    /* ── 表 1 @0xdd534..0xdd548：首操作数尺寸 ────────────────────────────
     * 0/3 -> sp+8（0xdd8ac），1/2/4 -> sp+4（0xdd8b8），5 -> 装箱（0xdd8c4，
     * 解出 tag 后 r10 = sp+16），6 -> 先报字符串错再 r10 = sp（0xdd550），
     * >6 -> 0xddd10 的 `mov r5,r4 ; mov r10,r1`。 */
    /* @0xdd524 and r2, r4, #15 */
    /* @0xdd528 cmp r2, #6 */
    /* @0xdd52c addls pc, pc, r2, lsl #2 */
    /* @0xdd530 b 0xddd10 */
    /* @0xdd534 b 0xdd8ac */
    /* @0xdd538 b 0xdd8b8 */
    /* @0xdd53c b 0xdd8b8 */
    /* @0xdd540 b 0xdd8ac */
    /* @0xdd544 b 0xdd8b8 */
    /* @0xdd548 b 0xdd8c4 */
    /* @0xdd54c b 0xdd550 */
    /* ── 0xdd550..0xdd564：首操作数是字符串时的报错体 ──────────────────
     * `VMError(exec, "DoSub :: Execution Engine - Cannot operate on string
     * type")` 之后 `mov r5,r4` / `mov r10,r9`，然后照常派发第二操作数。 */
    /* @0xdd550 ldr r1, [pc, #0x7cc] */
    /* @0xdd554 mov r0, r3 */
    /* @0xdd558 mov r5, r4 */
    /* @0xdd55c mov r10, r9 */
    /* @0xdd560 add r1, pc, r1 */
    /* @0xdd564 bl 0xd4210 */
    if (T <= 6u) {
#ifdef M_SIZES_SWAPPED
        r10 = (T == 0u || T == 3u) ? sp + 4 : sp + 8;
#else
        if (T == 0u || T == 3u)
            r10 = sp + 8;
        else if (T == 5u)
            r10 = sp + 16;              /* 0xddba0: add r10, r9, #16 */
        else if (T == 6u) {
            set_err(E_STRING);          /* 0xdd550 */
            pair = cls;
            r10 = sp;                   /* 0xdd55c: mov r10, r9 */
        } else
            r10 = sp + 4;
#endif
    } else {
        /* ── 0xddd10 / 0xddd1c：两个"超范围类型"桩 ──────────────────────
         * 首操作数 > 6：`mov r5,r4 ; mov r10,r1`，回到第二操作数派发；
         * 第二操作数 > 6：`mov r6,r10`，表 3 照旧按 cls 选槽，尾部报错。 */
    /* @0xddd10 mov r5, r4 */
    /* @0xddd14 mov r10, r1 */
    /* @0xddd18 b 0xdd568 */
    /* @0xddd1c mov r6, r10 */
    /* @0xddd20 b 0xdd5a8 */
        pair = cls;
        r10 = sp;
    }

    /* ── 表 6 @0xdd8d4..0xdd908 + 处理体 0xddb98..0xddcb4：首操作数是装箱
     * RValue。只改 pair 的**低**四位（用 r4 = 原始 cls 的高半字节），错误体
     * 用 `mov r5, r4` 把 pair 还原，然后一律 `add r10, r9, #16` 回到第二操作数
     * 的派发。 */
    /* @0xdd8c4 ldr r3, [r1, #0xc] */
    /* @0xdd8c8 cmp r3, #13 */
    /* @0xdd8cc addls pc, pc, r3, lsl #2 */
    /* @0xdd8d0 b 0xddca0 */
    /* @0xdd8d4 b 0xddc14 */
    /* @0xdd8d8 b 0xddbfc */
    /* @0xdd8dc b 0xddbe4 */
    /* @0xdd8e0 b 0xddbcc */
    /* @0xdd8e4 b 0xddca0 */
    /* @0xdd8e8 b 0xddbb4 */
    /* @0xdd8ec b 0xddca0 */
    /* @0xdd8f0 b 0xddba8 */
    /* @0xdd8f4 b 0xddca0 */
    /* @0xdd8f8 b 0xddca0 */
    /* @0xdd8fc b 0xddb98 */
    /* @0xdd900 b 0xddca0 */
    /* @0xdd904 b 0xddca0 */
    /* @0xdd908 b 0xddc14 */
    if (T == 5u) {
        uint32_t tag = rd32(sp + 12);
        pair = cls;
        switch (tag) {
        case 0:
        case 13:
            pair = cls & 0xF0u;             /* 0xddc14 */
            break;
        case 1:
            set_err(E_STRING);              /* 0xddbfc */
            break;
        case 2:
#ifdef M_ERR12_SWAP
            set_err(E2_ARRAY);
#else
            set_err(E1_ARRAY);              /* 0xddbe4 */
#endif
            break;
        case 3:
#ifdef M_ERR12_SWAP
            set_err(E2_POINTER);
#else
            set_err(E1_POINTER);            /* 0xddbcc */
#endif
            break;
        case 5:
#ifdef M_ERR12_SWAP
            set_err(E2_UNDEF);
#else
            set_err(E1_UNDEF);              /* 0xddbb4 */
#endif
            break;
        case 7:
            pair = (cls & 0xF0u) | 2u;      /* 0xddba8 */
            break;
        case 10:
            pair = (cls & 0xF0u) | 3u;      /* 0xddb98 */
            break;
#ifdef M_TAG14_REAL
        case 14:
            pair = cls & 0xF0u;
            break;
#endif
        default:
#ifdef M_ERR12_SWAP
            set_err(E2_MALFORMED);
#else
            set_err(E1_MALFORMED);          /* 0xddca0 */
#endif
            break;
        }
#ifdef M_VARIANT_NO_ADVANCE
        r10 = sp;                           /* MUTANT: no advance */
#else
        r10 = sp + 16;                      /* 0xddba0 */
#endif
    }

    U = (pair >> 4) & 15u;

    /* ── 表 2 @0xdd578..0xdd588：第二操作数尺寸 ──────────────────────────
     * 0/3 -> r6 = r10+8（0xdd8a4），1/2/4 -> r6 = r10+4（0xdd89c），5 -> 表 5
     * 解出 tag 后 r6 = r10+16（0xddc24），6 -> 先报字符串错再走表 3（0xdd594），
     * >6 -> 0xddd1c 的 `mov r6, r10`。 */
    /* @0xdd568 asr r2, r5, #4 */
    /* @0xdd56c cmp r2, #6 */
    /* @0xdd570 addls pc, pc, r2, lsl #2 */
    /* @0xdd574 b 0xddd1c */
    /* @0xdd578 b 0xdd8a4 */
    /* @0xdd57c b 0xdd89c */
    /* @0xdd580 b 0xdd89c */
    /* @0xdd584 b 0xdd8a4 */
    /* @0xdd588 b 0xdd89c */
    /* @0xdd58c b 0xdd854 */
    /* @0xdd590 b 0xdd594 */
    /* @0xdd594 ldr r1, [pc, #0x78c] */
    /* @0xdd598 mov r0, r11 */
    /* @0xdd59c mov r6, r10 */
    /* @0xdd5a0 add r1, pc, r1 */
    /* @0xdd5a4 bl 0xd4210 */
    /* @0xdd5a8 cmp r4, #101 */
    /* ── 0xdd89c / 0xdd8a4：表 2 的两个尺寸目标（r6 = r10+4 / r10+8）───── */
    /* @0xdd89c add r6, r10, #4 */
    /* @0xdd8a0 b 0xdd5a8 */
    /* @0xdd8a4 add r6, r10, #8 */
    /* @0xdd8a8 b 0xdd5a8 */
    /* @0xdd8ac add r10, r1, #8 */
    /* @0xdd8b0 mov r5, r4 */
    /* @0xdd8b4 b 0xdd568 */
    /* @0xdd8b8 add r10, r1, #4 */
    /* @0xdd8bc mov r5, r4 */
    /* @0xdd8c0 b 0xdd568 */
    if (U == 5u) {
        /* ── 表 5 @0xdd864..0xdd898 + 处理体 0xddc1c..0xddcc4 ─────────────
         * 改 pair 的**高**四位；0xddc24 的 `add r6,r10,#16` 是共同出口。 */
    /* @0xdd854 ldr r3, [r10, #0xc] */
    /* @0xdd858 cmp r3, #13 */
    /* @0xdd85c addls pc, pc, r3, lsl #2 */
    /* @0xdd860 b 0xddcb8 */
    /* @0xdd864 b 0xddc88 */
    /* @0xdd868 b 0xddc74 */
    /* @0xdd86c b 0xddc60 */
    /* @0xdd870 b 0xddc4c */
    /* @0xdd874 b 0xddcb8 */
    /* @0xdd878 b 0xddc38 */
    /* @0xdd87c b 0xddcb8 */
    /* @0xdd880 b 0xddc2c */
    /* @0xdd884 b 0xddcb8 */
    /* @0xdd888 b 0xddcb8 */
    /* @0xdd88c b 0xddc1c */
    /* @0xdd890 b 0xddcb8 */
    /* @0xdd894 b 0xddcb8 */
    /* @0xdd898 b 0xddc88 */
        uint32_t tag = rd32(r10 + 12);
        switch (tag) {
        case 0:
        case 13:
            pair &= 15u;                    /* 0xddc88 */
            break;
        case 1:
            set_err(E_STRING);              /* 0xddc74 */
            break;
        case 2:
            set_err(E2_ARRAY);              /* 0xddc60 */
            break;
        case 3:
            set_err(E2_POINTER);            /* 0xddc4c */
            break;
        case 5:
            set_err(E2_UNDEF);              /* 0xddc38 */
            break;
        case 7:
            pair = (pair & 15u) | 0x20u;    /* 0xddc2c */
            break;
        case 10:
            pair = (pair & 15u) | 0x30u;    /* 0xddc1c */
            break;
#ifdef M_TAG14_REAL
        case 14:
            pair &= 15u;
            break;
#endif
        default:
            set_err(E2_MALFORMED);          /* 0xddcb8 */
            break;
        }
        r6 = r10 + 16;                      /* 0xddc24 */
    } else if (U == 6u) {
        set_err(E_STRING);                  /* 0xdd594 */
        r6 = r10;                           /* 0xdd59c: mov r6, r10 */
    } else if (U <= 6u) {
        r6 = r10 + ((U == 0u || U == 3u) ? 8 : 4);
    } else {
        r6 = r10;                           /* 0xddd1c */
    }

    /* ── 表 3 @0xdd5b4..0xdd748：102 个入口，索引是**原始** cls 字节 ─────
     *   0  2  3 32 35 48 50 51       -> 0xdd844  r6 -= 8   (r7 = 0)
     *   5 37 53 80 82 83 85 86 101  -> 0xdd834  r6 -= 16  (r7 = r6, tag 槽)
     *   34                          -> 0xdd74c  r6 -= 4   (r7 = 0)
     *   其余（含 >101）              -> 0xdd90c  r8 = r7 = 0
     * 合法的 pair 恰好都落在前三组。 */
    /* ── 0xdd834 / 0xdd844：装箱与 8 字节结果桩 ────────────────────────
     * 0xdd834 `sub r7,r6,#16 ; mov r8,r7 ; mov r6,r7`（r7 即 tag 槽），
     * 0xdd844 `sub r6,r6,#8 ; mov r7,#0 ; mov r8,r6`。 */
    /* @0xdd834 sub r7, r6, #16 */
    /* @0xdd838 mov r8, r7 */
    /* @0xdd83c mov r6, r7 */
    /* @0xdd840 b 0xdd758 */
    /* @0xdd844 sub r6, r6, #8 */
    /* @0xdd848 mov r7, #0 */
    /* @0xdd84c mov r8, r6 */
    /* @0xdd850 b 0xdd758 */
    {
        int placed = 1;
#ifdef M_TAIL_SIZES_FROM_PAIR
        unsigned key = pair;
#else
        unsigned key = cls;
#endif
        if (key > 101u) {
            placed = 0;
        } else {
            switch (key) {
            case 0:
            case 2:
            case 3:
            case 32:
            case 35:
            case 48:
            case 50:
            case 51:
                r6 -= 8;
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
                r6 -= 16;
                r7 = r6;
                break;
            case 34:
                r6 -= 4;
                break;
            default:
                placed = 0;
                break;
            }
        }
        if (!placed)
            r8 = 0;
        else
            r8 = r6;
    }

    /* ── 0xdd90c：不合法 pair 的出口（r8 = r7 = 0）───────────────────── */
    /* @0xdd90c mov r8, #0 */
    /* @0xdd910 mov r7, r8 */
    /* @0xdd914 b 0xdd758 */

    /* ── 尾部：表 4 @0xdd764..0xdd830 按**解析后**的 pair 选算术 ─────────
     * 索引 0..51，其余（含 pair > 51）一律 0xdda28 的通用错。 */
    /* @0xdd758 cmp r5, #51 */
    /* @0xdd75c addls pc, pc, r5, lsl #2 */
    /* @0xdd760 b 0xdda28 */
    /* ── 0xdd92c..0xdd940：收尾 ────────────────────────────────────────
     * `cmp r7,#0 ; beq return` 否则 `str r12,[r7,#0xc]`；返回 r6。 */
    /* @0xdd92c cmp r7, #0 */
    /* @0xdd930 beq 0xdda64 */
    /* @0xdd934 mov r0, r6 */
    /* @0xdd938 str r12, [r7, #0xc] */
    /* @0xdd93c add sp, sp, #68 */
    /* @0xdd940 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
    if (pair > 51u) {                       /* 0xdda28 的入口条件 */
        set_err(E_GENERIC);
        tagv = 0;
        goto epilogue;
    }
    switch (pair) {
    /* @0xdd764 b 0xdd918 */
    /* @0xdd768 b 0xdda28 */
    /* @0xdd76c b 0xdd9b4 */
    /* @0xdd770 b 0xdd994 */
    /* @0xdd774 b 0xdda28 */
    /* @0xdd778 b 0xdda28 */
    /* @0xdd77c b 0xdda28 */
    /* @0xdd780 b 0xdda28 */
    /* @0xdd784 b 0xdda28 */
    /* @0xdd788 b 0xdda28 */
    /* @0xdd78c b 0xdda28 */
    /* @0xdd790 b 0xdda28 */
    /* @0xdd794 b 0xdda28 */
    /* @0xdd798 b 0xdda28 */
    /* @0xdd79c b 0xdda28 */
    /* @0xdd7a0 b 0xdda28 */
    /* @0xdd7a4 b 0xdda28 */
    /* @0xdd7a8 b 0xdda28 */
    /* @0xdd7ac b 0xdda28 */
    /* @0xdd7b0 b 0xdda28 */
    /* @0xdd7b4 b 0xdda28 */
    /* @0xdd7b8 b 0xdda28 */
    /* @0xdd7bc b 0xdda28 */
    /* @0xdd7c0 b 0xdda28 */
    /* @0xdd7c4 b 0xdda28 */
    /* @0xdd7c8 b 0xdda28 */
    /* @0xdd7cc b 0xdda28 */
    /* @0xdd7d0 b 0xdda28 */
    /* @0xdd7d4 b 0xdda28 */
    /* @0xdd7d8 b 0xdda28 */
    /* @0xdd7dc b 0xdda28 */
    /* @0xdd7e0 b 0xdda28 */
    /* @0xdd7e4 b 0xdd978 */
    /* @0xdd7e8 b 0xdda28 */
    /* @0xdd7ec b 0xdd960 */
    /* @0xdd7f0 b 0xdd9f0 */
    /* @0xdd7f4 b 0xdda28 */
    /* @0xdd7f8 b 0xdda28 */
    /* @0xdd7fc b 0xdda28 */
    /* @0xdd800 b 0xdda28 */
    /* @0xdd804 b 0xdda28 */
    /* @0xdd808 b 0xdda28 */
    /* @0xdd80c b 0xdda28 */
    /* @0xdd810 b 0xdda28 */
    /* @0xdd814 b 0xdda28 */
    /* @0xdd818 b 0xdda28 */
    /* @0xdd81c b 0xdda28 */
    /* @0xdd820 b 0xdda28 */
    /* @0xdd824 b 0xdd9d0 */
    /* @0xdd828 b 0xdda28 */
    /* @0xdd82c b 0xdda0c */
    /* @0xdd830 b 0xdd944 */
    case 0x00: {                            /* 0xdd918: vsub.f64 d7 = [r10]-[r9] */
        double a = rd_d(r10);
        double b = rd_d(r9);
#ifdef M_ORDER
        st_d_words(r8, b - a);
#else
        st_d_words(r8, a - b);
#endif
        tagv = 0;
        break;
    }
    case 0x02: {                            /* 0xdd9b4 */
        double b;
#ifdef M_I32_AS_U32
        b = (double)rd32(r9);
#else
        b = (double)(int32_t)rd32(r9);
#endif
        double a = rd_d(r10);
#ifdef M_ORDER
        st_d_words(r8, b - a);
#else
        st_d_words(r8, a - b);
#endif
        tagv = 0;
        break;
    }
    case 0x03: {                            /* 0xdd994 */
#ifdef M_FLOATDIDF_TRUNC
        double b = (double)(int32_t)rd64(r9);
#else
        double b = (double)(int64_t)rd64(r9);
#endif
        double a = rd_d(r10);
#ifdef M_ORDER
        st_d_words(r8, b - a);
#else
        st_d_words(r8, a - b);
#endif
        tagv = 0;
        break;
    }
    case 0x20: {                            /* 0xdd978 */
        double a;
#ifdef M_I32_AS_U32
        a = (double)rd32(r10);
#else
        a = (double)(int32_t)rd32(r10);
#endif
        double b = rd_d(r9);
#ifdef M_ORDER
        st_d_words(r8, b - a);
#else
        st_d_words(r8, a - b);
#endif
        tagv = 0;
        break;
    }
    case 0x22: {                            /* 0xdd960: rsb r3, r3, r2 */
        uint32_t a = rd32(r10);
        uint32_t b = rd32(r9);
#ifdef M_INT32_ORDER
        wr32(r8, b - a);
#else
        wr32(r8, a - b);
#endif
        tagv = 7;
        break;
    }
    case 0x23: {                            /* 0xdd9f0: sext(i32[r10]) - i64[r9] */
        uint32_t a = rd32(r10);
        int64_t b = (int64_t)rd64(r9);
#ifdef M_SEXT_NONE
        int64_t sa = (int64_t)(uint64_t)a;
#else
        int64_t sa = (int64_t)(int32_t)a;
#endif
#ifdef M_I64_AS_I32
        wr64(r8, (uint64_t)(int64_t)(int32_t)((int32_t)sa - (int32_t)b));
#else
        wr64(r8, (uint64_t)(sa - b));
#endif
        tagv = 10;
        break;
    }
    case 0x30: {                            /* 0xdd9d0 */
#ifdef M_FLOATDIDF_TRUNC
        double a = (double)(int32_t)rd64(r10);
#else
        double a = (double)(int64_t)rd64(r10);
#endif
        double b = rd_d(r9);
#ifdef M_ORDER
        st_d_words(r8, b - a);
#else
        st_d_words(r8, a - b);
#endif
        tagv = 0;
        break;
    }
    case 0x32: {                            /* 0xdda0c: i64[r10] - sext(i32[r9]) */
        int64_t a = (int64_t)rd64(r10);
        uint32_t b = rd32(r9);
#ifdef M_SEXT_NONE
        int64_t sb = (int64_t)(uint64_t)b;
#else
        int64_t sb = (int64_t)(int32_t)b;
#endif
#ifdef M_I64_AS_I32
        wr64(r8, (uint64_t)(int64_t)(int32_t)((int32_t)a - (int32_t)sb));
#else
        wr64(r8, (uint64_t)(a - sb));
#endif
        tagv = 10;
        break;
    }
    case 0x33: {                            /* 0xdd944 */
#ifdef M_I64_AS_I32
        wr64(r8, (uint64_t)(int64_t)(int32_t)((int32_t)rd32(r10) -
                                             (int32_t)rd32(r9)));
#else
        wr64(r8, rd64(r10) - rd64(r9));
#endif
        tagv = 10;
        break;
    }
    default:                                /* 0xdda28 */
        set_err(E_GENERIC);
        tagv = 0;
        break;
    }

epilogue:
    /* 0xdd92c: `cmp r7,#0 ; beq return ; str r12,[r7,#0xc]` */
#if defined(M_TAG_ALWAYS)
    wr32((r7 ? r7 : r6) + 12, tagv);        /* MUTANT: unconditional tag store */
#elif defined(M_NO_TAG_STORE)
    (void)r7;
    (void)tagv;
#else
    if (r7)
        wr32(r7 + 12, tagv);
#endif
    (void)exec;
    return r6;
}

/* ═══ mode 1 — generic `-`: boxType, F_JS_ToNumber twice, then subtract ═══
 * The 68-byte frame the entry reserves belongs to the callee, not to the
 * caller's value stack, so it is a local here.  Box of the FIRST operand at
 * frame+16, box of the second at frame+0, the two converted numbers at
 * frame+32 and frame+48, and the result at r6-16 (r6 = where boxType's second
 * call stopped). */
static unsigned char *mode1(unsigned cls, unsigned char *sp)
{
    unsigned char frame[68] __attribute__((aligned(8)));
    unsigned char *const fr = frame;
    unsigned char *r6;
    unsigned T = cls & 15u;
    unsigned U = (cls >> 4) & 15u;
    double a;
    double b;

    /* @0xdda70 add r5, sp, #16 */
    /* @0xdda74 mov r2, r1 */
    /* @0xdda78 and r1, r4, #15 */
    /* @0xdda7c mov r0, r5 */
    /* @0xdda80 bl 0xd7784 */
    /* @0xdda84 lsr r1, r4, #4 */
    /* @0xdda88 mov r2, r0 */
    /* @0xdda8c mov r0, sp */
    /* @0xdda90 bl 0xd7784 */
    /* @0xdda94 ldr r3, [sp, #0xc] */
    /* @0xdda98 mvn r12, #-16777216 */
    /* @0xdda9c and r3, r3, r12 */
    /* @0xddaa0 cmp r3, r12 */
    /* @0xddaa4 mov r6, r0 */
    /* @0xddaa8 beq 0xddce0 */
    /* @0xddaac ldr r3, [sp, #0x1c] */
    /* @0xddab0 bic r3, r3, #-16777216 */
    /* @0xddab4 cmp r3, r12 */
    /* @0xddab8 beq 0xddccc */
    /* @0xddabc add r4, sp, #32 */
    /* @0xddac0 mov r1, sp */
    /* @0xddac4 mov r2, #0 */
    /* @0xddac8 mov r3, #0 */
    /* @0xddacc mov r0, r4 */
    /* @0xddad0 str r12, [sp, #0x2c] */
    /* @0xddad4 str r12, [sp, #0x3c] */
    /* @0xddad8 mov r12, #0 */
    /* @0xddadc strd r2, r3, [sp, #32] */
    /* @0xddae0 strd r2, r3, [sp, #48] */
    /* @0xddae4 str r12, [sp, #0x28] */
    /* @0xddae8 str r12, [sp, #0x38] */
    /* @0xddaec bl 0x24cfac */
    /* @0xddaf0 cmp r0, #1 */
    /* @0xddaf4 beq 0xddcf4 */
    /* @0xddaf8 cmp r0, #0 */
    /* @0xddafc bne 0xdda4c */
    /* @0xddb00 add r7, sp, #48 */
    /* @0xddb04 mov r1, r5 */
    /* @0xddb08 mov r0, r7 */
    /* @0xddb0c bl 0x24cfac */
    /* @0xddb10 cmp r0, #1 */
    /* @0xddb14 beq 0xdda40 */
    /* @0xddb18 cmp r0, #0 */
    /* @0xddb1c bne 0xdda4c */
    /* @0xddb20 str r0, [r6, #-0x4] */
    /* @0xddb24 sub r5, r6, #16 */
    /* @0xddb28 vldr d6, [sp, #32] */
    /* @0xddb2c vldr d7, [sp, #48] */
    /* @0xddb30 vsub.f64 d5, d6, d7 */
    /* @0xddb34 ldr r1, [sp, #0x2c] */
    /* @0xddb38 sub r1, r1, #1 */
    /* @0xddb3c bic r1, r1, #-16777216 */
    /* @0xddb40 bic r1, r1, #3 */
    /* @0xddb44 cmp r1, #0 */
    /* @0xddb48 vmov r2, r3, d5 */
    /* @0xddb4c vstr s10, [r6, #-16] */
    /* @0xddb50 str r3, [r6, #-0xc] */
    /* @0xddb54 beq 0xddd04 */
    /* @0xddb58 ldr r1, [sp, #0x3c] */
    /* @0xddb5c mov r3, #0 */
    /* @0xddb60 str r3, [sp, #0x28] */
    /* @0xddb64 mov r2, #5 */
    /* @0xddb68 sub r1, r1, #1 */
    /* @0xddb6c str r3, [sp, #0x20] */
    /* @0xddb70 bic r3, r1, #-16777216 */
    /* @0xddb74 str r2, [sp, #0x2c] */
    /* @0xddb78 bic r3, r3, #3 */
    /* @0xddb7c cmp r3, #0 */
    /* @0xddb80 movne r0, r5 */
    /* @0xddb84 bne 0xdd93c */
    /* @0xddb88 mov r0, r7 */
    /* @0xddb8c bl 0xc0a7c */
    /* @0xddb90 mov r0, r5 */
    /* @0xddb94 b 0xdd93c */
    r6 = boxType(fr + 16, T, sp);           /* 0xdda80 */
    r6 = boxType(fr + 0, U, r6);            /* 0xdda90 */

    if ((rd32(fr + 12) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_BEFORE);              /* 0xddce0 */
        return r6;
    }
    if ((rd32(fr + 28) & 0x00FFFFFFu) == 0x00FFFFFFu) {
        set_err(E_REF_AFTER);               /* 0xddccc */
        return r6;
    }

    wr64(fr + 32, 0);
    wr64(fr + 48, 0);
    wr32(fr + 40, 0);
    wr32(fr + 56, 0);
    wr32(fr + 44, 0x00FFFFFFu);             /* 0xddad0 */
    wr32(fr + 60, 0x00FFFFFFu);             /* 0xddad4 */

    /* 0xddaec: the SECOND operand's box is converted first, and its failure is
     * the "right-hand-side" message. */
    if (js_to_number(fr + 32, fr + 0) == JS_THREW) {
        set_err(E_NUM_RIGHT);               /* 0xddcf4 */
        return r6;
    }
    if (js_to_number(fr + 48, fr + 16) == JS_THREW) {
        set_err(E_NUM_LEFT);                /* 0xdda40 */
        return r6;
    }

    /* 0xddb20: tag 0 at r6-4, then d5 = num(second) - num(first) stored as two
     * 32-bit halves at r6-16 / r6-12. */
    a = rd_d(fr + 32);
    b = rd_d(fr + 48);
    wr32(r6 - 4, 0);
#ifdef M_MODE1_AT_R6
    st_d_words(r6, a - b);
#else
    st_d_words(r6 - 16, a - b);
#endif
#ifdef M_MODE1_AT_R6
    return r6;
#else
    return r6 - 16;
#endif
}

/* ═══ entry ════════════════════════════════════════════════════════════════
 * 0xdd500: mode = (arg >> 8) & 15 ; r4 = uxtb(arg >> 16) = the pair byte.
 * 0xdd508: ONLY `cmp r2, #1 ; beq 0xdda70` — mode 0 and modes 2..15 fall
 * through to the strong-typed arm at 0xdd524. */
    /* @0xdd500 ubfx r2, r0, #0x8, #0x4 */
    /* @0xdd504 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
    /* @0xdd508 cmp r2, #1 */
    /* @0xdd50c lsr r5, r0, #16 */
    /* @0xdd510 sub sp, sp, #68 */
    /* @0xdd514 mov r9, r1 */
    /* @0xdd518 mov r11, r3 */
    /* @0xdd51c uxtb r4, r5 */
    /* @0xdd520 beq 0xdda70 */
unsigned char *DoSub(uint32_t arg, unsigned char *sp, const unsigned char *base,
                     void *exec)
{
    unsigned mode = (arg >> 8) & 0xFu;
    unsigned cls = (arg >> 16) & 0xFFu;

    (void)base;
    g_error = 0;
    if (mode == 1u)
        return mode1(cls, sp);
    return strong(cls, sp, exec);
}

/* ════ 逐指令台账（自动生成，勿手改）════════════════════════════════════
 * 上面每个 //@@BLOCK 段已就地标注它实现的那段原版指令；下面这段是同一函数里
 * 没有 C 语句的指令：跳转表项、错误桩、以及 DoAdd 里未被本译文执行的路径
 * （例如字符串对象的释放链，依赖尚未恢复的 RefThing/YYFree）。每一条都在
 * 这里出现且只出现一次，操作数逐字取自 llvm-objdump；census 门会把这份台账
 * 与原版字节逐条比对，多一条、少一条、改一个操作数都会红。
 */
/* @0xdd5ac addls pc, pc, r4, lsl #2 */
/* @0xdd5b0 b 0xdd90c */
/* @0xdd5b4 b 0xdd844 */
/* @0xdd5b8 b 0xdd90c */
/* @0xdd5bc b 0xdd844 */
/* @0xdd5c0 b 0xdd844 */
/* @0xdd5c4 b 0xdd90c */
/* @0xdd5c8 b 0xdd834 */
/* @0xdd5cc b 0xdd90c */
/* @0xdd5d0 b 0xdd90c */
/* @0xdd5d4 b 0xdd90c */
/* @0xdd5d8 b 0xdd90c */
/* @0xdd5dc b 0xdd90c */
/* @0xdd5e0 b 0xdd90c */
/* @0xdd5e4 b 0xdd90c */
/* @0xdd5e8 b 0xdd90c */
/* @0xdd5ec b 0xdd90c */
/* @0xdd5f0 b 0xdd90c */
/* @0xdd5f4 b 0xdd90c */
/* @0xdd5f8 b 0xdd90c */
/* @0xdd5fc b 0xdd90c */
/* @0xdd600 b 0xdd90c */
/* @0xdd604 b 0xdd90c */
/* @0xdd608 b 0xdd90c */
/* @0xdd60c b 0xdd90c */
/* @0xdd610 b 0xdd90c */
/* @0xdd614 b 0xdd90c */
/* @0xdd618 b 0xdd90c */
/* @0xdd61c b 0xdd90c */
/* @0xdd620 b 0xdd90c */
/* @0xdd624 b 0xdd90c */
/* @0xdd628 b 0xdd90c */
/* @0xdd62c b 0xdd90c */
/* @0xdd630 b 0xdd90c */
/* @0xdd634 b 0xdd844 */
/* @0xdd638 b 0xdd90c */
/* @0xdd63c b 0xdd74c */
/* @0xdd640 b 0xdd844 */
/* @0xdd644 b 0xdd90c */
/* @0xdd648 b 0xdd834 */
/* @0xdd64c b 0xdd90c */
/* @0xdd650 b 0xdd90c */
/* @0xdd654 b 0xdd90c */
/* @0xdd658 b 0xdd90c */
/* @0xdd65c b 0xdd90c */
/* @0xdd660 b 0xdd90c */
/* @0xdd664 b 0xdd90c */
/* @0xdd668 b 0xdd90c */
/* @0xdd66c b 0xdd90c */
/* @0xdd670 b 0xdd90c */
/* @0xdd674 b 0xdd844 */
/* @0xdd678 b 0xdd90c */
/* @0xdd67c b 0xdd844 */
/* @0xdd680 b 0xdd844 */
/* @0xdd684 b 0xdd90c */
/* @0xdd688 b 0xdd834 */
/* @0xdd68c b 0xdd90c */
/* @0xdd690 b 0xdd90c */
/* @0xdd694 b 0xdd90c */
/* @0xdd698 b 0xdd90c */
/* @0xdd69c b 0xdd90c */
/* @0xdd6a0 b 0xdd90c */
/* @0xdd6a4 b 0xdd90c */
/* @0xdd6a8 b 0xdd90c */
/* @0xdd6ac b 0xdd90c */
/* @0xdd6b0 b 0xdd90c */
/* @0xdd6b4 b 0xdd90c */
/* @0xdd6b8 b 0xdd90c */
/* @0xdd6bc b 0xdd90c */
/* @0xdd6c0 b 0xdd90c */
/* @0xdd6c4 b 0xdd90c */
/* @0xdd6c8 b 0xdd90c */
/* @0xdd6cc b 0xdd90c */
/* @0xdd6d0 b 0xdd90c */
/* @0xdd6d4 b 0xdd90c */
/* @0xdd6d8 b 0xdd90c */
/* @0xdd6dc b 0xdd90c */
/* @0xdd6e0 b 0xdd90c */
/* @0xdd6e4 b 0xdd90c */
/* @0xdd6e8 b 0xdd90c */
/* @0xdd6ec b 0xdd90c */
/* @0xdd6f0 b 0xdd90c */
/* @0xdd6f4 b 0xdd834 */
/* @0xdd6f8 b 0xdd90c */
/* @0xdd6fc b 0xdd834 */
/* @0xdd700 b 0xdd834 */
/* @0xdd704 b 0xdd90c */
/* @0xdd708 b 0xdd834 */
/* @0xdd70c b 0xdd834 */
/* @0xdd710 b 0xdd90c */
/* @0xdd714 b 0xdd90c */
/* @0xdd718 b 0xdd90c */
/* @0xdd71c b 0xdd90c */
/* @0xdd720 b 0xdd90c */
/* @0xdd724 b 0xdd90c */
/* @0xdd728 b 0xdd90c */
/* @0xdd72c b 0xdd90c */
/* @0xdd730 b 0xdd90c */
/* @0xdd734 b 0xdd90c */
/* @0xdd738 b 0xdd90c */
/* @0xdd73c b 0xdd90c */
/* @0xdd740 b 0xdd90c */
/* @0xdd744 b 0xdd90c */
/* @0xdd748 b 0xdd834 */
/* @0xdd74c sub r6, r6, #4 */
/* @0xdd750 mov r7, #0 */
/* @0xdd754 mov r8, r6 */

/* @0xdd918 vldr d6, [r10] */
/* @0xdd91c vldr d7, [r9] */
/* @0xdd920 vsub.f64 d7, d6, d7 */
/* @0xdd924 mov r12, #0 */
/* @0xdd928 vstr d7, [r8] */
/* @0xdd944 ldrd r4, r5, [r10] */
/* @0xdd948 mov r12, #10 */
/* @0xdd94c ldrd r2, r3, [r9] */
/* @0xdd950 subs r4, r4, r2 */
/* @0xdd954 sbc r5, r5, r3 */
/* @0xdd958 strd r4, r5, [r8] */
/* @0xdd95c b 0xdd92c */
/* @0xdd960 ldr r2, [r10] */
/* @0xdd964 mov r12, #7 */
/* @0xdd968 ldr r3, [r9] */
/* @0xdd96c rsb r3, r3, r2 */
/* @0xdd970 str r3, [r8] */
/* @0xdd974 b 0xdd92c */
/* @0xdd978 vldr s14, [r10] */
/* @0xdd97c vcvt.f64.s32 d7, s14 */
/* @0xdd980 vldr d6, [r9] */
/* @0xdd984 mov r12, #0 */
/* @0xdd988 vsub.f64 d7, d7, d6 */
/* @0xdd98c vstr d7, [r8] */
/* @0xdd990 b 0xdd92c */
/* @0xdd994 ldrd r0, r1, [r9] */
/* @0xdd998 bl 0x319164 */
/* @0xdd99c vldr d7, [r10] */
/* @0xdd9a0 mov r12, #0 */
/* @0xdd9a4 vmov d5, r0, r1 */
/* @0xdd9a8 vsub.f64 d7, d7, d5 */
/* @0xdd9ac vstr d7, [r8] */
/* @0xdd9b0 b 0xdd92c */
/* @0xdd9b4 vldr s14, [r9] */
/* @0xdd9b8 vcvt.f64.s32 d7, s14 */
/* @0xdd9bc vldr d6, [r10] */
/* @0xdd9c0 mov r12, #0 */
/* @0xdd9c4 vsub.f64 d7, d6, d7 */
/* @0xdd9c8 vstr d7, [r8] */
/* @0xdd9cc b 0xdd92c */
/* @0xdd9d0 ldrd r0, r1, [r10] */
/* @0xdd9d4 bl 0x319164 */
/* @0xdd9d8 vldr d7, [r9] */
/* @0xdd9dc mov r12, #0 */
/* @0xdd9e0 vmov d6, r0, r1 */
/* @0xdd9e4 vsub.f64 d7, d6, d7 */
/* @0xdd9e8 vstr d7, [r8] */
/* @0xdd9ec b 0xdd92c */
/* @0xdd9f0 ldr r1, [r10] */
/* @0xdd9f4 mov r12, #10 */
/* @0xdd9f8 ldrd r2, r3, [r9] */
/* @0xdd9fc rsbs r2, r2, r1 */
/* @0xdda00 rsc r3, r3, r1, asr #31 */
/* @0xdda04 strd r2, r3, [r8] */
/* @0xdda08 b 0xdd92c */
/* @0xdda0c ldr r1, [r9] */
/* @0xdda10 mov r12, #10 */
/* @0xdda14 ldrd r2, r3, [r10] */
/* @0xdda18 subs r2, r2, r1 */
/* @0xdda1c sbc r3, r3, r1, asr #31 */
/* @0xdda20 strd r2, r3, [r8] */
/* @0xdda24 b 0xdd92c */
/* @0xdda28 ldr r1, [pc, #0x2fc] */
/* @0xdda2c mov r0, r11 */
/* @0xdda30 add r1, pc, r1 */
/* @0xdda34 bl 0xd4210 */
/* @0xdda38 mov r12, #0 */
/* @0xdda3c b 0xdd92c */
/* @0xdda40 ldr r0, [pc, #0x2e8] */
/* @0xdda44 add r0, pc, r0 */
/* @0xdda48 bl 0x24e58c */
/* @0xdda4c ldr r3, [sp, #0x2c] */
/* @0xdda50 sub r3, r3, #1 */
/* @0xdda54 bic r3, r3, #-16777216 */
/* @0xdda58 bic r3, r3, #3 */
/* @0xdda5c cmp r3, #0 */
/* @0xdda60 beq 0xddc90 */
/* @0xdda64 mov r0, r6 */
/* @0xdda68 add sp, sp, #68 */
/* @0xdda6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* @0xddb98 and r5, r5, #240 */
/* @0xddb9c orr r5, r5, #3 */
/* @0xddba0 add r10, r9, #16 */
/* @0xddba4 b 0xdd568 */
/* @0xddba8 and r5, r5, #240 */
/* @0xddbac orr r5, r5, #2 */
/* @0xddbb0 b 0xddba0 */
/* @0xddbb4 ldr r1, [pc, #0x178] */
/* @0xddbb8 mov r0, r11 */
/* @0xddbbc mov r5, r4 */
/* @0xddbc0 add r1, pc, r1 */
/* @0xddbc4 bl 0xd4210 */
/* @0xddbc8 b 0xddba0 */
/* @0xddbcc ldr r1, [pc, #0x164] */
/* @0xddbd0 mov r0, r11 */
/* @0xddbd4 mov r5, r4 */
/* @0xddbd8 add r1, pc, r1 */
/* @0xddbdc bl 0xd4210 */
/* @0xddbe0 b 0xddba0 */
/* @0xddbe4 ldr r1, [pc, #0x150] */
/* @0xddbe8 mov r0, r11 */
/* @0xddbec mov r5, r4 */
/* @0xddbf0 add r1, pc, r1 */
/* @0xddbf4 bl 0xd4210 */
/* @0xddbf8 b 0xddba0 */
/* @0xddbfc ldr r1, [pc, #0x13c] */
/* @0xddc00 mov r0, r11 */
/* @0xddc04 mov r5, r4 */
/* @0xddc08 add r1, pc, r1 */
/* @0xddc0c bl 0xd4210 */
/* @0xddc10 b 0xddba0 */
/* @0xddc14 and r5, r4, #240 */
/* @0xddc18 b 0xddba0 */
/* @0xddc1c and r5, r5, #15 */
/* @0xddc20 orr r5, r5, #48 */
/* @0xddc24 add r6, r10, #16 */
/* @0xddc28 b 0xdd5a8 */
/* @0xddc2c and r5, r5, #15 */
/* @0xddc30 orr r5, r5, #32 */
/* @0xddc34 b 0xddc24 */
/* @0xddc38 ldr r1, [pc, #0x104] */
/* @0xddc3c mov r0, r11 */
/* @0xddc40 add r1, pc, r1 */
/* @0xddc44 bl 0xd4210 */
/* @0xddc48 b 0xddc24 */
/* @0xddc4c ldr r1, [pc, #0xf4] */
/* @0xddc50 mov r0, r11 */
/* @0xddc54 add r1, pc, r1 */
/* @0xddc58 bl 0xd4210 */
/* @0xddc5c b 0xddc24 */
/* @0xddc60 ldr r1, [pc, #0xe4] */
/* @0xddc64 mov r0, r11 */
/* @0xddc68 add r1, pc, r1 */
/* @0xddc6c bl 0xd4210 */
/* @0xddc70 b 0xddc24 */
/* @0xddc74 ldr r1, [pc, #0xd4] */
/* @0xddc78 mov r0, r11 */
/* @0xddc7c add r1, pc, r1 */
/* @0xddc80 bl 0xd4210 */
/* @0xddc84 b 0xddc24 */
/* @0xddc88 and r5, r5, #15 */
/* @0xddc8c b 0xddc24 */
/* @0xddc90 mov r0, r4 */
/* @0xddc94 bl 0xc0a7c */
/* @0xddc98 mov r0, r6 */
/* @0xddc9c b 0xdd93c */
/* @0xddca0 ldr r1, [pc, #0xac] */
/* @0xddca4 mov r0, r11 */
/* @0xddca8 mov r5, r4 */
/* @0xddcac add r1, pc, r1 */
/* @0xddcb0 bl 0xd4210 */
/* @0xddcb4 b 0xddba0 */
/* @0xddcb8 ldr r1, [pc, #0x98] */
/* @0xddcbc mov r0, r11 */
/* @0xddcc0 add r1, pc, r1 */
/* @0xddcc4 bl 0xd4210 */
/* @0xddcc8 b 0xddc24 */
/* @0xddccc ldr r0, [pc, #0x88] */
/* @0xddcd0 add r0, pc, r0 */
/* @0xddcd4 bl 0x254b04 */
/* @0xddcd8 mov r0, r6 */
/* @0xddcdc b 0xdd93c */
/* @0xddce0 ldr r0, [pc, #0x78] */
/* @0xddce4 add r0, pc, r0 */
/* @0xddce8 bl 0x254b04 */
/* @0xddcec mov r0, r6 */
/* @0xddcf0 b 0xdd93c */
/* @0xddcf4 ldr r0, [pc, #0x68] */
/* @0xddcf8 add r0, pc, r0 */
/* @0xddcfc bl 0x24e58c */
/* @0xddd00 b 0xdda4c */
/* @0xddd04 mov r0, r4 */
/* @0xddd08 bl 0xc0a7c */
/* @0xddd0c b 0xddb58 */

/* ── 字面量池 0xddd24..0xddd68（17 个字，全函数唯一的 PC 相对数据）──────
 * 上面每条错误的 VMError/JSThrow 都靠 ldr rX,[pc,#..] 从这里取字符串偏移；
 * census 门同时核对这 17 个字的数值，改一个字就会红。 */
/* @0xddd24 .word 0x00255b4c */
/* @0xddd28 .word 0x00255b0c */
/* @0xddd2c .word 0x002557a8 */
/* @0xddd30 .word 0x00255620 */
/* @0xddd34 .word 0x00255548 */
/* @0xddd38 .word 0x00255510 */
/* @0xddd3c .word 0x00255534 */
/* @0xddd40 .word 0x002554a4 */
/* @0xddd44 .word 0x00255540 */
/* @0xddd48 .word 0x0025550c */
/* @0xddd4c .word 0x00255534 */
/* @0xddd50 .word 0x00255430 */
/* @0xddd54 .word 0x00255494 */
/* @0xddd58 .word 0x002554f8 */
/* @0xddd5c .word 0x00255328 */
/* @0xddd60 .word 0x002552f0 */
/* @0xddd64 .word 0x00255324 */
/* ════ 台账结束 ═══════════════════════════════════════════════════════ */
