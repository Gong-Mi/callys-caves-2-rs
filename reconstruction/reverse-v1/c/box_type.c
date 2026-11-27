/* boxType — C reconstruction of libyoyo's operand boxing (0xd7784, 97 insns).
 *
 *     uchar *boxType(RValue& dst, eVM_Type type, uchar *src)
 *
 * Packs an already-decoded operand into a 16-byte RValue and returns the
 * advanced source pointer, so the return value is "src + consumed bytes".
 * The type table is the one cards/boxType.c decoded; the corners that matter
 * for every generic path in this engine are:
 *
 *   k  read  writes dst            tag            consume
 *   0   8B   [0],[4]               0  real        8   copy, no conversion
 *   1   4B   [0],[4]               0  real        4   float -> double
 *   2   4B   [0],[4]               0  real        4   int32 -> double
 *   3   8B   [0],[4]               0  real        8   int64 -> double
 *   4   4B   [0],[4]              13  bool        4   int32 -> double, NOT 0/1-normalised
 *   5  16B   [0],[4],[8],[0xc]    原样           16   whole RValue copy
 *   6   4B   [0]                   1  string      4   [4]/[8] untouched
 *   7/8  -    none                 none           0   no-op
 *   9   0    [0]=[4]=0             5  undefined    0
 *   >9   -    none                 none           0   no-op
 *
 * Unknown types are not an error here - unlike DoConv, boxType never throws;
 * it silently no-ops and leaves the caller to judge the tag.
 */
#include <stdint.h>
#include <string.h>

#define TAG_REAL      0u
#define TAG_STRING    1u
#define TAG_UNDEFINED 5u
#define TAG_BOOL     13u

#ifdef MUTANT
#if MUTANT == 1
#  define M_K9_WRITES_8 1      /* k9 clears [8] too */
#elif MUTANT == 2
#  define M_K6_WRITES_4 1      /* k6 also writes [4] */
#elif MUTANT == 3
#  define M_K4_NORMALISE 1     /* k4 normalises to 0/1 (a plausible-looking bug) */
#elif MUTANT == 4
#  define M_K5_CONSUME_8 1     /* k5 consumes only 8 bytes */
#elif MUTANT == 5
#  define M_DEFAULT_NOOP_WRITES 1  /* k7/8/>9 zero the destination */
#else
#  error "unknown MUTANT"
#endif
#endif

static void put_double(unsigned char *dst, double d)
{
    memcpy(dst, &d, 8);
}

static void set_tag(unsigned char *dst, uint32_t tag)
{
    memcpy(dst + 12, &tag, 4);
}

unsigned char *boxType(unsigned char *dst, unsigned type, const unsigned char *src)
{
    unsigned char *s = (unsigned char *)src;
    switch (type) {
    case 0:
        memcpy(dst, s, 8);
        set_tag(dst, TAG_REAL);
        return s + 8;
    case 1: {
        float f;
        memcpy(&f, s, 4);
        put_double(dst, (double)f);
        set_tag(dst, TAG_REAL);
        return s + 4;
    }
    case 2: {
        int32_t v;
        memcpy(&v, s, 4);
        put_double(dst, (double)v);
        set_tag(dst, TAG_REAL);
        return s + 4;
    }
    case 3: {
        int64_t v;
        memcpy(&v, s, 8);
        put_double(dst, (double)v);
        set_tag(dst, TAG_REAL);
        return s + 8;
    }
    case 4: {
        int32_t v;
        memcpy(&v, s, 4);
#ifdef M_K4_NORMALISE
        v = (v != 0);
#endif
        put_double(dst, (double)v);
        set_tag(dst, TAG_BOOL);
        return s + 4;
    }
    case 5:
        memcpy(dst, s, 16);
#ifdef M_K5_CONSUME_8
        return s + 8;
#else
        return s + 16;
#endif
    case 6:
        memcpy(dst, s, 4);
#ifdef M_K6_WRITES_4
        memcpy(dst + 4, s + 4, 4);
#endif
        set_tag(dst, TAG_STRING);
        return s + 4;
    case 9:
        memset(dst, 0, 8);
#ifdef M_K9_WRITES_8
        memset(dst + 8, 0, 1);
#endif
        set_tag(dst, TAG_UNDEFINED);
        return s;
    default:                       /* 7, 8, >9 */
#ifdef M_DEFAULT_NOOP_WRITES
        memset(dst, 0, 16);
#endif
        return s;
    }
}
