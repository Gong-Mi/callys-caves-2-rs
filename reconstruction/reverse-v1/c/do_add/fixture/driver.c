/* driver.c — the C arm of the DoAdd/DoSub differential.
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm, because the
 * body under judgement treats the value stack as a pointer-packed RValue array:
 * a 4-byte operand is a char*, a 16-byte operand is a whole RValue, and the
 * string limb stores a pointer into a 4-byte slot.  A 64-bit host build moves
 * every one of those and quietly stops testing what the handler does.
 *
 * Protocol (text, one case per line, so a failing case is readable):
 *
 *   in    IN <arg-hex> <arena-hex>
 *         arena is ARENA bytes; the value-stack pointer handed to DoAdd is
 *         arena + SLOT.  Everything below SLOT is the callee frame's play area,
 *         everything above it is the operand span; both are staged by the
 *         harness and both are compared afterwards.
 *   out   R <ret-delta> <arena-hex> <err-hex> <obj-rc> <obj-len> <obj-text-hex>
 *         ret-delta  returned pointer minus the slot address, signed
 *         arena      the ARENA bytes as they stand after the call
 *         err        the text DoAdd handed to VMError/JSThrow*, hex, or "-"
 *         obj-*      for the string pair: the {refcount, len, text} of the
 *                    object the result slot points at, or 0/0/- when the call
 *                    result is not an object
 *   END
 *
 * freestanding: the four libc symbols clang emits for this code are here.
 */
#include <stdint.h>
#include <stddef.h>

#include "do_add.h"

#define ARENA 0x180u
#define SLOT 0x100u

/* ── freestanding IO ─────────────────────────────────────────────────────── */
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

/* -nostdlib means no compiler-rt, and clang lowers `(double)int64` to
 * __aeabi_l2d on this target: VFPv3 has 32-bit integer conversions only, so the
 * 64-bit form is a libcall there too.  Built from the one exact instruction:
 * hi*2^32 is exact in double, adding lo rounds once, which is the correctly
 * rounded result of the exact integer.  No recursion: only the 32-bit asm. */
/* The bits are built by hand: round-to-nearest-even on a 53-bit mantissa, which
 * is exactly what the ABI helper computes.  No floating-point instruction is
 * used, so nothing here can call itself. */
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

/* ── small text helpers ─────────────────────────────────────────────────── */
static char obuf[1 << 16];
static unsigned olen;

static void putc_(char c)
{
    if (olen == sizeof obuf) {
        sys3(4, 1, (long)(uintptr_t)obuf, olen);
        olen = 0;
    }
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

void __stack_chk_fail(void)
{
    pstr("STACK SMASHED\n");
    flush();
    sys3(1, 6, 0, 0);
    for (;;) {
    }
}

/* ── input parsing ──────────────────────────────────────────────────────── */
static int nib(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    return -1;
}

static char ibuf[1 << 20];
static unsigned ilen, ipos;

static int next_line(void)
{
    unsigned n = 0;
    char c;
    for (;;) {
        if (ipos >= ilen)
            return 0;
        c = ibuf[ipos++];
        if (c == '\n') {
            ibuf[n] = 0;
            return 1;
        }
        ibuf[n++] = c;
    }
}

int main(void)
{
    ibuf[ilen] = 0;
    for (;;) {
        unsigned done = 0;
        long n = sys3(3, 0, (long)(uintptr_t)(ibuf + ilen),
                      (long)(sizeof ibuf) - 1u - ilen);
        if (n <= 0)
            break;
        ilen += (unsigned)n;
        if (ilen >= sizeof ibuf - 1u)
            break;
        done = 1;
        (void)done;
    }
    ibuf[ilen] = 0;
    ipos = 0;
    while (next_line()) {
        unsigned char arena[ARENA];
        uint32_t arg = 0;
        unsigned char *slotp;
        unsigned char *ret;
        const char *err;
        unsigned i, obj_rc = 0, obj_len = 0;
        unsigned char *obj;
        int objslot = -1;
        /* IN <arg> <arena> */
        if (memcmp(ibuf, "IN ", 3) != 0)
            continue;
        {
            unsigned p = 3;
            arg = 0;
            while (p < 64 && nib(ibuf[p]) >= 0) {
                arg = (arg << 4) | (uint32_t)nib(ibuf[p]);
                p++;
            }
            while (p < 64 && ibuf[p] == ' ')
                p++;
            for (i = 0; i < ARENA && p + 1 < 8192; i++) {
                int hi = nib(ibuf[p]), lo = nib(ibuf[p + 1]);
                if (hi < 0 || lo < 0)
                    break;
                arena[i] = (unsigned char)((hi << 4) | lo);
                p += 2;
            }
            /* relocation list: <arena offset>:<target offset>,...  A pointer the
             * case staged is written as base+target, so both arms run with their
             * OWN arena address and the harness still compares offsets. */
            while (p < 8192 && ibuf[p] == ' ')
                p++;
            while (p < 8192 && ibuf[p] != 0 && ibuf[p] != ';') {
                unsigned off = 0, tgt = 0;
                int any = 0;
                while (p < 8192 && nib(ibuf[p]) >= 0) {
                    off = (off << 4) | (unsigned)nib(ibuf[p]);
                    p++;
                    any = 1;
                }
                if (!any)
                    break;
                if (ibuf[p] != ':') {
                    /* a lone number is treated as "target == offset" */
                    tgt = off;
                } else {
                    p++;
                    while (p < 8192 && nib(ibuf[p]) >= 0) {
                        tgt = (tgt << 4) | (unsigned)nib(ibuf[p]);
                        p++;
                    }
                }
                if (off + 4 <= ARENA)
                    *(uint32_t *)(void *)(arena + off) =
                        (uint32_t)(uintptr_t)(arena + tgt);
                while (p < 8192 && (ibuf[p] == ',' || ibuf[p] == ' '))
                    p++;
            }
            /* after ';': the arena offset that will hold the RESULT object
             * pointer for the string pair, or '-' when the case has none. */
            while (p < 8192 && ibuf[p] != ';' && ibuf[p] != 0)
                p++;
            if (p < 8192 && ibuf[p] == ';')
                p++;
            while (p < 8192 && ibuf[p] == ' ')
                p++;
            if (p < 8192 && nib(ibuf[p]) >= 0) {
                int v = 0;
                while (p < 8192 && nib(ibuf[p]) >= 0) {
                    v = (v << 4) | nib(ibuf[p]);
                    p++;
                }
                objslot = v;
            }
        }
        slotp = arena + SLOT;
        ret = DoAdd(arg, slotp, 0, 0);
        err = do_add_last_error();
        if (objslot >= 0 &&
            *(uint32_t *)(void *)(arena + objslot) >= 0x1000u) {
            obj = (unsigned char *)(uintptr_t)(*(uint32_t *)(void *)(arena + objslot));
            obj_rc = *(uint32_t *)(void *)(obj + 4);
            obj_len = *(uint32_t *)(void *)(obj + 8);
            pstr("R ");
            pdec((int)(ret - slotp));
            putc_(' ');
            pbytes(arena, ARENA);
            putc_(' ');
            if (err) {
                const char *e = err;
                while (*e) {
                    static const char hx[] = "0123456789abcdef";
                    putc_(hx[((unsigned char)*e) >> 4]);
                    putc_(hx[((unsigned char)*e) & 0xf]);
                    e++;
                }
            } else {
                putc_('-');
            }
            putc_(' ');
            pdec((int)obj_rc);
            putc_(' ');
            pdec((int)obj_len);
            putc_(' ');
            if (obj_len)
                pbytes((const unsigned char *)(uintptr_t)(*(uint32_t *)(void *)obj),
                       obj_len);
            else
                putc_('-');
            putc_(' ');
            phex32((uint32_t)(uintptr_t)arena);
            putc_('\n');
            flush();                 /* one write per case: a crash names the case */
            continue;
        }
        pstr("R ");
        pdec((int)(ret - slotp));
        putc_(' ');
        pbytes(arena, ARENA);
        putc_(' ');
        if (err) {
            const char *e = err;
            while (*e) {
                static const char hx[] = "0123456789abcdef";
                putc_(hx[((unsigned char)*e) >> 4]);
                putc_(hx[((unsigned char)*e) & 0xf]);
                e++;
            }
        } else {
            putc_('-');
        }
        pstr(" 0 0 - ");
        phex32((uint32_t)(uintptr_t)arena);
        putc_('\n');
        flush();
    }
    pstr("END\n");
    flush();
    sys3(1, 0, 0, 0);            /* -e main: there is no crt0 to return to */
    for (;;)
        ;
}
