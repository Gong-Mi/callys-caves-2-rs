/* DoNeg — C reconstruction of libyoyo's strong-typed arm (mode 0).
 *
 * Scope (deliberate, see harness/do_neg_diff.py): the `mode == 0` path plus the
 * fall-through for mode 3..15.  mode 1 (generic negate) and mode 2 (plain
 * numeric coercion) call boxType / F_JS_ToNumber and are NOT covered here.
 *
 * Signature is the original one:
 *     unsigned char *DoNeg(uint32 arg, unsigned char *sp,
 *                          const unsigned char *base, void *exec)
 * arg bits: mode = (arg >> 8) & 0xF, cls = (arg >> 16) & 0xF.
 * Returns the new value-stack pointer (sp is unchanged on every covered path).
 *
 * RValue = 16 bytes; the tag word sits at +0xC and is compared as a whole word
 * against 13 (ARM `cmp r2,#13` / `addls`), so a tag word above 13 - including
 * one with a non-zero high byte - lands on the "Malformed variable" arm.
 * Payload widths come from the caller's cls: 0/5-RValue 8B, 1 float 4B,
 * 2/4 int32 4B, 3 int64 8B, 6 string 4B.
 *
 * Built with -ffp-contract=off: vneg is a sign-bit flip, never an arithmetic
 * expression clang could fuse.
 */
#include <stdint.h>
#include <string.h>

#define TAG_STRING_T   1u
#define TAG_ARRAY      2u
#define TAG_POINTER    3u
#define TAG_UNDEFINED  5u
#define TAG_INT32      7u
#define TAG_INT64     10u
#define TAG_REAL      13u

/* Error text, byte-for-byte from .rodata (see harness receipt `errors_seen`).
 * Kept in one table so no build (mutant or not) trips -Wunused-const-variable. */
enum { ERR_CLS6, ERR_POINTER, ERR_UNDEFINED, ERR_STRING, ERR_ARRAY, ERR_MALFORMED,
       ERR_REF_UNARY, ERR_TYPE_UNARY };

static const char *const k_errors[] = {
    "DoNeg :: Execution Engine - Cannot operate on string type",
    "DoNeg :1: illegal pointer use",
    "DoNeg :1: undefined value",
    "DoNeg :1: Execution Engine - Cannot operate on string type",
    "DoNeg :1: illegal array use",
    "DoNeg :1: Malformed variable",
    "could not find lhs variable in unary-",
    "Unary - could not convert expr to a number",
};

/* The oracle records the emitted text; the C side reports it the same way so a
 * string can never drift silently. */
static const char *g_error;

const char *do_neg_last_error(void) { return g_error; }

static void set_err(int idx) { g_error = k_errors[idx]; }

/* ── 判别性反例（TEETH）────────────────────────────────────────────────────
 * Each mutant must make the differential go RED. A green mutant means the case
 * set never exercises that decision, i.e. the "identical" result was toothless.
 * Built only with -DMUTANT=n; the production build has none of them. */
#ifdef MUTANT
#if MUTANT == 1
#  define M_CLS2_NO_WRAP 1        /* int32 negate without the INT32_MIN wrap */
#elif MUTANT == 2
#  define M_TAG_REAL_LOW 1        /* flip the LOW word of a real instead of high */
#elif MUTANT == 3
#  define M_INT64_AS_I32 1        /* int64 negate done as 32-bit */
#elif MUTANT == 4
#  define M_WRITE_ON_PASSTHRU 1   /* cls 7..15 zero the slot */
#elif MUTANT == 5
#  define M_SILENT_STRING 1       /* cls 6 reports no error */
#else
#  error "unknown MUTANT"
#endif
#endif

static int32_t neg_i32(uint32_t v) { return (int32_t)(0u - v); }
static int64_t neg_i64(uint64_t v) { return (int64_t)(0ull - v); }

/* ── mode 1 / mode 2 ────────────────────────────────────────────────────────
 * Both call boxType() then F_JS_ToNumber(); mode 1 negates, mode 2 does not.
 * F_JS_ToNumber's C side below is the part measured against the original, not
 * assumed: real/int32/int64 convert, undefined and null give 0.0, and the
 * non-numeric tags (array/pointer/bool/undefined-8/9/11/14) are a silent no-op
 * that leaves the caller's zeroed slot alone. Strings (tag 1) need strtod and
 * are OUT of the domain; tag 6 (object) faults on the convert path in the
 * original itself, so it cannot be exercised here either. */
extern unsigned char *boxType(unsigned char *dst, unsigned type, const unsigned char *src);

static int js_to_number(unsigned char *dst, const unsigned char *src)
{
    uint32_t tag;
    memcpy(&tag, src + 12, 4);
    switch (tag) {
    case 0:
    case 13: {
        memcpy(dst, src, 8);
        return 0;
    }
    case 7: {
        int32_t v;
        memcpy(&v, src, 4);
        double d = (double)v;
        memcpy(dst, &d, 8);
        return 0;
    }
    case 10: {
        int64_t v;
        memcpy(&v, src, 8);
        double d = (double)v;
        memcpy(dst, &d, 8);
        return 0;
    }
    case 5:
    case 12: {
        double d = 0.0;
        memcpy(dst, &d, 8);
        return 0;
    }
    default:
        return 0;                       /* silent no-op, dst stays as caller left it */
    }
}

unsigned char *DoNeg(uint32_t arg, unsigned char *sp,
                     const unsigned char *base, void *exec)
{
    (void)base;
    (void)exec;
    g_error = 0;
    unsigned mode = (arg >> 8) & 0xFu;
    unsigned cls = (arg >> 16) & 0xFu;

    if (mode == 1 || mode == 2) {
        /* 36-byte frame: [0..15] boxed operand, [16..31] converted value,
         * [0x1c] is the converted slot's tag (the handler pre-sets it). */
        unsigned char frame[36];
        memset(frame, 0, sizeof frame);
        unsigned char *boxed = boxType(frame, cls, sp);
        uint32_t tagw;
        memcpy(&tagw, frame + 12, 4);
        if ((tagw & 0x00FFFFFFu) == 0x00FFFFFFu) {
            set_err(ERR_REF_UNARY);     /* JSThrowReferenceError */
            return boxed;
        }
        memcpy(frame + 28, "\xff\xff\xff\x00", 4);   /* out tag = 0x00FFFFFF */
        double out = 0.0;
        memcpy(frame + 16, &out, 8);
        int rc = js_to_number(frame + 16, frame);
        if (rc == 1) {
            set_err(ERR_TYPE_UNARY);    /* JSThrowTypeError */
            return boxed;               /* cleanup path: no write */
        }
        if (rc != 0)
            return boxed;
        uint64_t bits;
        memcpy(&bits, frame + 16, 8);
        if (mode == 1) {
            double d;
            memcpy(&d, &bits, 8);
            if (d != d)                 /* unordered: 0x7FFFFFFF_FFFFFFFF */
                bits = 0x7FFFFFFFffffffffull;
            else
                bits ^= 0x8000000000000000ull;
        }
        memcpy(boxed - 16, &bits, 8);
        uint32_t zero = 0;
        memcpy(boxed - 4, &zero, 4);
        return boxed - 16;
    }

    switch (cls) {
    case 0: {                           /* double: vneg.f64 = sign flip */
        uint64_t v;
        memcpy(&v, sp, 8);
        v ^= 0x8000000000000000ull;
        memcpy(sp, &v, 8);
        return sp;
    }
    case 1: {                           /* float: vneg.f32 = sign flip */
        uint32_t v;
        memcpy(&v, sp, 4);
        v ^= 0x80000000u;
        memcpy(sp, &v, 4);
        return sp;
    }
    case 2:                             /* int32: rsb r3,r3,#0 */
    case 4: {                           /* cls 4 shares the int32 arm */
        uint32_t v;
        memcpy(&v, sp, 4);
#ifdef M_CLS2_NO_WRAP
        v = (v == 0x80000000u) ? 0u : (uint32_t)(-(int32_t)v);
#else
        v = (uint32_t)neg_i32(v);
#endif
        memcpy(sp, &v, 4);
        return sp;
    }
    case 3: {                           /* int64: rsbs/rsc, wraps at INT64_MIN */
        uint64_t v;
        memcpy(&v, sp, 8);
#ifdef M_INT64_AS_I32
        v = (uint64_t)(uint32_t)(-(int32_t)(uint32_t)v);
#else
        v = (uint64_t)neg_i64(v);
#endif
        memcpy(sp, &v, 8);
        return sp;
    }
    case 5: {                           /* RValue: dispatch on the tag word */
        uint32_t tag;
        memcpy(&tag, sp + 12, 4);
        switch (tag) {
        case 0:                         /* real: flip the sign bit of the
                                         * high word only (low word untouched) */
        case TAG_REAL: {
            uint32_t lo, hi;
            memcpy(&lo, sp, 4);
            memcpy(&hi, sp + 4, 4);
#ifdef M_TAG_REAL_LOW
            lo ^= 0x80000000u;
#else
            hi ^= 0x80000000u;
#endif
            memcpy(sp, &lo, 4);
            memcpy(sp + 4, &hi, 4);
            return sp;
        }
        case TAG_INT64: {
            uint64_t v;
            memcpy(&v, sp, 8);
            v = (uint64_t)neg_i64(v);
            memcpy(sp, &v, 8);
            return sp;
        }
        case TAG_INT32: {
            uint32_t v;
            memcpy(&v, sp, 4);
            v = (uint32_t)neg_i32(v);
            memcpy(sp, &v, 4);
            return sp;
        }
        case TAG_STRING_T: set_err(ERR_STRING); return sp;
        case TAG_ARRAY: set_err(ERR_ARRAY); return sp;
        case TAG_POINTER: set_err(ERR_POINTER); return sp;
        case TAG_UNDEFINED: set_err(ERR_UNDEFINED); return sp;
        default: set_err(ERR_MALFORMED); return sp;
        }
    }
    case 6:                             /* string: error only, no write */
#ifdef M_SILENT_STRING
        return sp;
#else
        set_err(ERR_CLS6);
        return sp;
#endif
    default:                            /* cls 7..15: untouched */
#ifdef M_WRITE_ON_PASSTHRU
        memset(sp, 0, 16);
#endif
        return sp;
    }
}
