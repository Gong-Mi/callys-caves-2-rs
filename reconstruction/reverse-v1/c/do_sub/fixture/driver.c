/* driver.c — the C arm of the DoSub differential.
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm: the body
 * treats the value stack as a pointer-packed RValue array, and a 64-bit host
 * build moves every operand offset it computes from the type nibbles.
 *
 * Protocol (text, one case per line):
 *   in    IN <arg-hex> <arena-hex>
 *         the value-stack pointer handed to DoSub is arena + SLOT; everything
 *         below SLOT is the caller's poisoned play area, everything above is
 *         the operand span, both compared afterwards.
 *   out   R <ret-delta> <arena-hex> <err-hex> <arena-base-hex>
 *   END
 */
#include <stdint.h>
#include <stddef.h>

#include "do_sub.h"

#define ARENA 0x180u
#define SLOT 0x100u

static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}

void *memcpy(void *d, const void *s, unsigned n)
{
    unsigned char *a = (unsigned char *)d;
    const unsigned char *b = (const unsigned char *)s;
    while (n--)
        *a++ = *b++;
    return d;
}

void *memset(void *d, int c, unsigned n)
{
    unsigned char *a = (unsigned char *)d;
    while (n--)
        *a++ = (unsigned char)c;
    return d;
}

char *strcpy(char *d, const char *s)
{
    char *a = d;
    while ((*a++ = *s++) != 0)
        ;
    return d;
}

int memcmp(const void *a, const void *b, unsigned n)
{
    const unsigned char *x = (const unsigned char *)a;
    const unsigned char *y = (const unsigned char *)b;
    while (n--) {
        if (*x != *y)
            return (int)*x - (int)*y;
        x++;
        y++;
    }
    return 0;
}

uint32_t __stack_chk_guard = 0x5a5a5a5au;

/* -nostdlib: no compiler-rt, and clang lowers (double)int64 to __aeabi_l2d.
 * The bits are built by hand — round to nearest even on a 53-bit mantissa,
 * which is the correctly rounded result of the exact integer. */
static double u64_to_d(unsigned long long u)
{
    uint64_t bits;
    unsigned e;
    double d;
    if (u == 0)
        return 0.0;
    e = 63u - (unsigned)__builtin_clzll(u);
    if (e <= 52u) {
        bits = ((uint64_t)(e + 1023u) << 52) | ((u << (52u - e)) & 0xFFFFFFFFFFFFFull);
    } else {
        unsigned sh = e - 52u;
        uint64_t m = u >> sh;
        uint64_t rem = u & ((1ull << sh) - 1ull);
        uint64_t half = 1ull << (sh - 1u);
        if (rem > half || (rem == half && (m & 1u)))
            m++;
        if (m == (1ull << 53)) {
            m >>= 1;
            e++;
        }
        bits = ((uint64_t)(e + 1023u) << 52) | (m & 0xFFFFFFFFFFFFFull);
    }
    memcpy(&d, &bits, 8);
    return d;
}

double __aeabi_ui2d(unsigned v) { return u64_to_d(v); }

double __aeabi_i2d(int v)
{
    return (v < 0) ? -u64_to_d((unsigned long long)(-(v + 1)) + 1ull)
                   : u64_to_d((unsigned)v);
}

double __aeabi_l2d(long long v)
{
    if (v < 0)
        return -u64_to_d((unsigned long long)(-(v + 1)) + 1ull);
    return u64_to_d((unsigned long long)v);
}

double __aeabi_ul2d(unsigned long long v) { return u64_to_d(v); }

/* ── text IO ────────────────────────────────────────────────────────────── */
static char obuf[1 << 16];
static unsigned olen;

static void flush(void)
{
    unsigned done = 0;
    while (done < olen) {
        long n = sys3(4, 1, (long)(uintptr_t)(obuf + done), olen - done);
        if (n <= 0)
            break;
        done += (unsigned)n;
    }
    olen = 0;
}

static void putc_(char c)
{
    if (olen == sizeof obuf)
        flush();
    obuf[olen++] = c;
}

static void pstr(const char *s)
{
    while (*s)
        putc_(*s++);
}

static void phex32(uint32_t v)
{
    static const char hx[] = "0123456789abcdef";
    int k;
    for (k = 7; k >= 0; k--)
        putc_(hx[(v >> (k * 4)) & 0xf]);
}

static void pbytes(const unsigned char *p, unsigned n)
{
    static const char hx[] = "0123456789abcdef";
    unsigned i;
    for (i = 0; i < n; i++) {
        putc_(hx[p[i] >> 4]);
        putc_(hx[p[i] & 0xf]);
    }
}

static void pdec(int v)
{
    char t[12];
    int n = 0;
    unsigned u;
    if (v < 0) {
        putc_('-');
        u = (unsigned)(-(v + 1)) + 1u;
    } else {
        u = (unsigned)v;
    }
    if (!u) {
        putc_('0');
        return;
    }
    while (u) {
        t[n++] = (char)('0' + (u % 10));
        u /= 10;
    }
    while (n)
        putc_(t[--n]);
}

void __stack_chk_fail(void)
{
    pstr("STACK SMASHED\n");
    flush();
    sys3(1, 6, 0, 0);
    for (;;) {
    }
}

/* ── input ──────────────────────────────────────────────────────────────── */
static char ibuf[1 << 20];
static unsigned ilen, ipos;

static int nib(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

static int next_line(void)
{
    unsigned n = 0;
    for (;;) {
        if (ipos >= ilen)
            return 0;
        if (ibuf[ipos] == '\n') {
            ipos++;
            ibuf[n] = 0;
            return 1;
        }
        ibuf[n++] = ibuf[ipos++];
    }
}

int main(void)
{
    unsigned char arena[ARENA];
    for (;;) {
        long n = sys3(3, 0, (long)(uintptr_t)(ibuf + ilen),
                      (long)(sizeof ibuf) - 1u - ilen);
        if (n <= 0)
            break;
        ilen += (unsigned)n;
        if (ilen >= sizeof ibuf - 1u)
            break;
    }
    ibuf[ilen] = 0;
    ipos = 0;
    while (next_line()) {
        uint32_t arg = 0;
        unsigned char *slotp;
        unsigned char *ret;
        const char *err;
        unsigned i, p;
        if (memcmp(ibuf, "IN ", 3) != 0)
            continue;
        p = 3;
        while (p < 64 && nib(ibuf[p]) >= 0) {
            arg = (arg << 4) | (uint32_t)nib(ibuf[p]);
            p++;
        }
        while (p < 8192 && (ibuf[p] == ' ' || ibuf[p] == '\t'))
            p++;
        for (i = 0; i < ARENA && p + 1 < 8192; i++) {
            int hi = nib(ibuf[p]), lo = nib(ibuf[p + 1]);
            if (hi < 0 || lo < 0)
                break;
            arena[i] = (unsigned char)((hi << 4) | lo);
            p += 2;
        }
        slotp = arena + SLOT;
        ret = DoSub(arg, slotp, 0, 0);
        err = do_sub_last_error();
        pstr("R ");
        pdec((int)(ret - slotp));
        putc_(' ');
        pbytes(arena, ARENA);
        putc_(' ');
        if (err) {
            const char *e = err;
            static const char hx[] = "0123456789abcdef";
            while (*e) {
                putc_(hx[((unsigned char)*e) >> 4]);
                putc_(hx[((unsigned char)*e) & 0xf]);
                e++;
            }
        } else {
            putc_('-');
        }
        putc_(' ');
        phex32((uint32_t)(uintptr_t)arena);
        putc_('\n');
        flush();                    /* one write per case: a crash names the case */
    }
    pstr("END\n");
    flush();
    sys3(1, 0, 0, 0);
    for (;;) {
    }
}
