/* DoNot — C reconstruction of libyoyo's strong-typed arm (mode 0).
 *
 * Scope: mode 0 and the mode 3..15 fall-through. mode 1 (`!`) and mode 2 (`~`)
 * call boxType / JS_ToBoolean / F_JS_ToInt32 and are NOT covered here.
 *
 * Unlike DoNeg, `~` on a real is NOT a sign flip: the original goes
 *     double -> __fixdfdi (truncating, saturating) -> bitwise NOT -> __floatdidf
 * so -0.5 -> 0 -> -1 -> -1.0, and NaN/Inf collapse to an integer first. The C
 * below states that model explicitly and the differential decides the
 * out-of-range corners (the oracle is the judge, not this comment).
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

/* Only three distinct texts exist in this handler: the pooled
 * "string" text serves both cls 6 and tag 1, array has its own, and every
 * other bad tag (3/4/5/6/8/9/11/12/>13) lands on "Malformed variable".
 * The card's short form "Cannot operate on string type" is not the real text. */
enum { ERR_STRING, ERR_ARRAY, ERR_MALFORMED };

static const char *const k_errors[] = {
    "DoNot :: Execution Engine - Cannot operate on string type",
    "DoNot :: illegal array use",
    "DoNot :: Malformed variable",
};

/* TEETH: each mutant must make the differential go RED (-DMUTANT=n only). */
#ifdef MUTANT
#if MUTANT == 1
#  define M_CLS0_SIGNFLIP 1
#elif MUTANT == 2
#  define M_CLS4_SIGNED 1
#elif MUTANT == 3
#  define M_TAG_REAL_SIGNFLIP 1
#elif MUTANT == 4
#  define M_CLS2_WRITE8 1
#elif MUTANT == 5
#  define M_SILENT_STRING 1
#else
#  error "unknown MUTANT"
#endif
#endif

static const char *g_error;
const char *do_not_last_error(void) { return g_error; }
static void set_err(int idx) { g_error = k_errors[idx]; }

/* __fixdfdi @0x3194a0 is NOT standard saturation - it is this build's own
 * wrapper around __fixunsdfdi @0x319550:
 *
 *     if (x < 0.0) return -(int64_t)fixuns((bits with high word += 0x80000000));
 *     return (int64_t)fixuns(x);
 *
 * and __fixunsdfdi truncates toward zero, answers 0 for x < 0 or NaN and
 * UINT64_MAX for x >= 2**64. Consequences the differential pins down:
 * +Inf -> UINT64_MAX -> -1, -Inf -> (x+2^63 = +Inf) -> negate(UINT64_MAX) = +1,
 * 2**63 -> INT64_MIN, DBL_MAX -> -1, NaN -> 0. */
static uint64_t fixuns(uint64_t bits)
{
    double d;
    memcpy(&d, &bits, 8);
    if (!(d >= 0.0))                 /* negatives and NaN */
        return 0;
    if (d >= 18446744073709551616.0)
        return UINT64_MAX;
    return (uint64_t)d;
}

static int64_t d2lz(uint64_t bits)
{
    double d;
    memcpy(&d, &bits, 8);
    if (d < 0.0) {
        uint64_t hi = (bits >> 32) + 0x80000000ull;   /* x + 2**63, high word only */
        uint64_t b2 = ((hi & 0xffffffffull) << 32) | (bits & 0xffffffffull);
        return (int64_t)(0ull - fixuns(b2));
    }
    return (int64_t)fixuns(bits);
}

/* __floatdidf (__aeabi_l2d): round-to-nearest-even, the VFP conversion. */
static uint64_t l2d(int64_t v)
{
    double d = (double)v;
    uint64_t bits;
    memcpy(&bits, &d, 8);
    return bits;
}

/* vcvt.s32.f32: truncate toward zero, saturate (VFP non-trapping mode). */
static int32_t f2s32(uint32_t bits)
{
    float f;
    memcpy(&f, &bits, 4);
    if (f != f)
        return 0;
    if (f >= 2147483648.0f)
        return INT32_MAX;
    if (f <= -2147483649.0f)
        return INT32_MIN;
    return (int32_t)f;
}

static uint32_t s322f(int32_t v)
{
    float f = (float)v;
    uint32_t bits;
    memcpy(&bits, &f, 4);
    return bits;
}

unsigned char *DoNot(uint32_t arg, unsigned char *sp,
                     const unsigned char *base, void *exec)
{
    (void)base;
    (void)exec;
    g_error = 0;
    unsigned mode = (arg >> 8) & 0xFu;
    unsigned cls = (arg >> 16) & 0xFu;

    if (mode != 0 && mode <= 2)
        return sp;

    switch (cls) {
    case 0: {
        uint64_t bits;
        memcpy(&bits, sp, 8);
#ifdef M_CLS0_SIGNFLIP
        bits ^= 0x8000000000000000ull;
#else
        int64_t v = ~d2lz(bits);
        bits = l2d(v);
#endif
        memcpy(sp, &bits, 8);
        return sp;
    }
    case 1: {
        uint32_t bits;
        memcpy(&bits, sp, 4);
        int32_t v = ~f2s32(bits);
        bits = s322f(v);
        memcpy(sp, &bits, 4);
        return sp;
    }
    case 2: {
        uint32_t v;
        memcpy(&v, sp, 4);
        v = ~v;
#ifdef M_CLS2_WRITE8
        {
            uint64_t w = v;
            memcpy(sp, &w, 8);
        }
#else
        memcpy(sp, &v, 4);
#endif
        return sp;
    }
    case 3: {
        uint64_t v;
        memcpy(&v, sp, 8);
        v = ~v;
        memcpy(sp, &v, 8);
        return sp;
    }
    case 4: {
        /* rsbs r3,r3,#1 ; movlo r3,#0  -> (x <= 1) ? 1-x : 0, unsigned compare */
        uint32_t v;
        memcpy(&v, sp, 4);
#ifdef M_CLS4_SIGNED
        v = ((int32_t)v <= 1) ? (uint32_t)(1 - (int32_t)v) : 0u;
#else
        v = (v <= 1u) ? (1u - v) : 0u;
#endif
        memcpy(sp, &v, 4);
        return sp;
    }
    case 5: {
        uint32_t tag;
        memcpy(&tag, sp + 12, 4);
        switch (tag) {
        case 0:
        case TAG_REAL: {
            uint64_t bits;
            memcpy(&bits, sp, 8);
#ifdef M_TAG_REAL_SIGNFLIP
            bits ^= 0x8000000000000000ull;
#else
            int64_t v = ~d2lz(bits);
            bits = l2d(v);
#endif
            memcpy(sp, &bits, 8);
            return sp;
        }
        case TAG_INT32: {
            uint32_t v;
            memcpy(&v, sp, 4);
            v = ~v;
            memcpy(sp, &v, 4);
            return sp;
        }
        case TAG_INT64: {
            uint64_t v;
            memcpy(&v, sp, 8);
            v = ~v;
            memcpy(sp, &v, 8);
            return sp;
        }
        case TAG_STRING_T: set_err(ERR_STRING); return sp;
        case TAG_ARRAY: set_err(ERR_ARRAY); return sp;
        default: set_err(ERR_MALFORMED); return sp;   /* 3/4/5/6/8/9/11/12/>13 */
        }
    }
    case 6:
#ifdef M_SILENT_STRING
        return sp;
#else
        set_err(ERR_STRING);
        return sp;
#endif
    default:
        return sp;
    }
}
