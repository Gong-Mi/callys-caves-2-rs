/*
 * driver.c — the C arm of the variable-instruction differential
 * (Code_Variable_Find_Name, DoConvIntToVariable, DoPopLocalVariable).
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm: a pointer is
 * 4 bytes, so RValue slots are really 16 B and `lsl #4` in DoPopLocalVariable
 * really means 16, the tag really sits at +0xc, and the 12-byte write of
 * DoConvIntToVariable really lands 12 bytes below the stack top.  A host build
 * would move every one of those and quietly stop testing them.
 *
 * It is a fixture, not a reconstruction: it stages one contiguous arena at the
 * same offsets the Python arm stages (see AO_* in variable_ops.h), answers all
 * callees with stubs identical to the Python arm's, calls the translated body
 * once per case and prints a record stream that harness/var_ops_diff.py
 * reproduces from the original bytes.
 *
 * Case line (stdin), 8 integers:
 *   fn=1  id type name_tag ret_mode 0 0 0
 *         name_tag 0 "alpha" / 1 "" / 2 NULL / 3 "beta"
 *         ret_mode 0 -> callee answers with AO_RETSTR, 1 -> AO_RETSTR+16,
 *                  2 -> NULL, 3 -> the AO_NAME pointer itself
 *   fn=2  value arg 0 0 0 0 0
 *   fn=3  raw self_mode tag instance_id arg 0 0
 *         self_mode 0 = exec->[0x10] == 0
 *                   1 = self, [0x24] == 0                     (no store)
 *                   2 = self, [0x24] != 0, [0x4] = table      (direct store)
 *                   3 = self, [0x24] != 0, [0x4] = 0          (InternalGetYYVar)
 *
 * Record stream (stdout):
 *   CASE <fn> <p0..p6>
 *   B <id>                                  built-in callee: the argument it got
 *   S <len> <hex> <type> <id>               scope callee: name bytes + both ints
 *   P <off> / Q                             PushContextStack / PopContextStack
 *   F <off>                                 FREE_RValue__Pre: the slot it got
 *   R <dst> <src> <instance>                SET_RValue: destination, source, id
 *   G <off> <idx>                           InternalGetYYVar: answer + argument
 *   RET <off|OUT|NULL> <hex>                returned pointer as an arena offset
 *                                           plus the string bytes there ('-' if
 *                                           empty; meaningless for fn 2/3)
 *   CALLS <n>
 *   MEM <hex>                               the three evidence windows, verbatim
 *   SPDLT <n>                               fn=3: returned sp - incoming sp
 *
 * No raw pointer is ever printed: every pointer becomes an offset from the
 * arena, so the two arms' unrelated base addresses never enter the record.
 */
#include <stdint.h>
#include <stddef.h>

#include "variable_ops.h"

#define NAME_MAXLEN 32
#define MARK        0xcc    /* "no instruction of this body wrote here" */
#define TAGM_A      0xa5

/* ── raw syscalls (no libc in a freestanding armv7 image) ───────────────── */
static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0)
                     : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}
static void out(const char *s, uint32_t n) { sys3(4, 1, (long)(uintptr_t)s, n); }
__attribute__((noreturn)) static void quit(int code)
{
    sys3(1, code, 0, 0);
    for (;;) { }
}
static long read_all(char *buf, long cap)
{
    long total = 0;
    while (total < cap) {
        long n = sys3(3, 0, (long)(uintptr_t)(buf + total), cap - total);
        if (n <= 0)
            break;
        total += n;
    }
    return total;
}

uintptr_t __stack_chk_guard = 0xc0de0001u;
void __stack_chk_fail(void) { quit(3); }

/* ── integer / byte output ─────────────────────────────────────────────── */
static void print_i(int32_t v)
{
    char b[16];
    int i = 0;
    uint32_t u;
    if (v < 0) {
        out("-", 1);
        u = (uint32_t)(-(int64_t)v);
    } else {
        u = (uint32_t)v;
    }
    do { b[i++] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    while (i)
        out(&b[--i], 1);
}

static void print_hex(const unsigned char *p, int n)
{
    static const char hex[] = "0123456789abcdef";
    if (n <= 0) {
        out("-", 1);
        return;
    }
    for (int i = 0; i < n; i++) {
        char two[2];
        two[0] = hex[(p[i] >> 4) & 0xf];
        two[1] = hex[p[i] & 0xf];
        out(two, 2);
    }
}

/* ── the arena ─────────────────────────────────────────────────────────── */
static unsigned char arena[ARENA_SIZE];

/* The canned callee answers of fn=1, staged once (identical bytes on the
 * Python arm). */
static void stage_retstrings(void)
{
    static const char a[] = "builtin-answer";
    static const char b[] = "scope-answer";
    for (unsigned i = 0; i < 16; i++)
        arena[AO_RETSTR + i] = 0;
    for (unsigned i = 0; i < sizeof a; i++)
        arena[AO_RETSTR + i] = (unsigned char)a[i];
    for (unsigned i = 0; i < sizeof b; i++)
        arena[AO_RETSTR + 16 + i] = (unsigned char)b[i];
}

static int32_t cstr_len(const unsigned char *p, int cap)
{
    int n = 0;
    while (n < cap && p[n] != 0)
        n++;
    return n;
}

static int32_t off_of(const void *p)
{
    uintptr_t a = (uintptr_t)(const unsigned char *)p;
    uintptr_t base = (uintptr_t)arena;
    if (p == 0)
        return INT32_MIN;
    if (a < base || a >= base + ARENA_SIZE)
        return -1;                        /* OUT: outside the arena */
    return (int32_t)(a - base);
}

/* ── stubs: identical on the Python arm ────────────────────────────────── */
static int n_calls;
static int g_ret_mode;

static const char *answer(void)
{
    switch (g_ret_mode) {
    case 0: return (const char *)(arena + AO_RETSTR);
    case 1: return (const char *)(arena + AO_RETSTR + 16);
    case 2: return 0;
    default: return (const char *)(arena + AO_NAME);
    }
}

const char *Variable_BuiltIn_Find_Name(int id)
{
    n_calls++;
    out("B ", 2); print_i(id); out("\n", 1);
    return answer();
}

const char *Variable_GetName_Scope(const char *name, int type, int id)
{
    int n = name ? cstr_len((const unsigned char *)name, NAME_MAXLEN) : -1;

    n_calls++;
    out("S ", 2); print_i(n); out(" ", 1);
    if (n > 0)
        print_hex((const unsigned char *)name, n);
    else
        out("-", 1);
    out(" ", 1); print_i(type); out(" ", 1); print_i(id); out("\n", 1);
    return answer();
}

static void print_off(const void *p)
{
    int32_t o = off_of(p);
    if (o == INT32_MIN)
        out("NULL", 4);
    else
        print_i(o);
}

void PushContextStack(void *self)
{
    n_calls++;
    out("P ", 2); print_off(self); out("\n", 1);
}

void PopContextStack(void)
{
    n_calls++;
    out("Q\n", 2);
}

void FREE_RValue__Pre(void *rv)
{
    n_calls++;
    out("F ", 2); print_off(rv); out("\n", 1);
    /* deliberately no memory effect: what the original does to the slot is
     * that callee's business, and nothing here assumes it */
}

void SET_RValue(void *dst, void *src, int instance)
{
    n_calls++;
    out("R ", 2); print_off(dst); out(" ", 1); print_off(src);
    out(" ", 1); print_i(instance); out("\n", 1);
    /* no copy: see FREE_RValue__Pre above.  This arm proves the three
     * arguments, not the store. */
}

void *InternalGetYYVar(void *self, int idx)
{
    n_calls++;
    out("G ", 2); print_off(arena + AO_DYN); out(" ", 1); print_i(idx); out("\n", 1);
    (void)self;
    return arena + AO_DYN;
}

/* ── the evidence windows, printed verbatim by both arms ───────────────── */
static void print_mem(void)
{
    out("MEM ", 4);
    print_hex(arena + AO_W1, AO_W1LEN);
    print_hex(arena + AO_W2, AO_W2LEN);
    print_hex(arena + AO_W3, AO_W3LEN);
    out("\n", 1);
}

/* ── input ─────────────────────────────────────────────────────────────── */
static int32_t read_i32(const char **pp)
{
    const char *p = *pp;
    int neg = 0;
    unsigned long long v = 0;

    while (*p == ' ' || *p == '\t' || *p == '\n')
        p++;
    if (*p == '-') { neg = 1; p++; }
    while (*p >= '0' && *p <= '9') {
        if (v < 0xffffffffull)
            v = v * 10ull + (unsigned long long)(*p - '0');
        p++;
    }
    *pp = p;
    return neg ? (int32_t)(-(int64_t)v) : (int32_t)v;
}

static const char *name_by_tag(int tag)
{
    static const char alpha[] = "alpha";
    static const char beta[] = "beta";
    switch (tag) {
    case 0: (void)beta; return alpha;
    case 1: return "";
    case 3: return beta;
    default: return 0;                 /* NULL */
    }
}

static void wr32(unsigned char *p, uint32_t w)
{
    p[0] = (unsigned char)(w & 0xffu);
    p[1] = (unsigned char)((w >> 8) & 0xffu);
    p[2] = (unsigned char)((w >> 16) & 0xffu);
    p[3] = (unsigned char)((w >> 24) & 0xffu);
}

static void fill(unsigned char *p, int n, unsigned char b)
{
    for (int i = 0; i < n; i++)
        p[i] = b;
}

static void print_ret(const void *p, int want_text)
{
    unsigned char buf[NAME_MAXLEN];
    int n = 0;

    out("RET ", 4);
    print_off(p);
    if (p != 0 && want_text) {
        const unsigned char *c = p;
        n = cstr_len(c, NAME_MAXLEN);
        for (int i = 0; i < n; i++)
            buf[i] = c[i];
    }
    out(" ", 1);
    print_hex(buf, n);
    out("\n", 1);
}

int main(void)
{
    static char inbuf[8192];
    long n = read_all(inbuf, (long)sizeof inbuf - 1);
    const char *p;

    if (n <= 0)
        quit(2);
    inbuf[n] = 0;

    /* compile-time-ish layout guard: the windows must live inside the arena */
    if (AO_W1 + AO_W1LEN > ARENA_SIZE || AO_W2 + AO_W2LEN > ARENA_SIZE ||
        AO_W3 + AO_W3LEN > ARENA_SIZE || AO_SP + 0x40 > ARENA_SIZE)
        quit(5);

    stage_retstrings();
    p = inbuf;

    while (*p) {
        int32_t fn = read_i32(&p);
        int32_t p0 = read_i32(&p), p1 = read_i32(&p), p2 = read_i32(&p);
        int32_t p3 = read_i32(&p), p4 = read_i32(&p), p5 = read_i32(&p);
        int32_t p6 = read_i32(&p);

        if (fn == 0)
            break;

        out("CASE ", 5);
        print_i(fn); out(" ", 1);
        print_i(p0); out(" ", 1); print_i(p1); out(" ", 1);
        print_i(p2); out(" ", 1); print_i(p3); out(" ", 1);
        print_i(p4); out(" ", 1); print_i(p5); out(" ", 1);
        print_i(p6); out("\n", 1);

        n_calls = 0;
        fill(arena, ARENA_SIZE, MARK);

        if (fn == 1) {
            const char *name = name_by_tag(p2);
            const char *ret;
            uintptr_t q;

            fill(arena + AO_NAME, 48, 0);
            if (name == 0) {
                /* NULL name: recorded as a NULL pointer, not as offset 0 — the
                 * arena starts at AO_NAME = 0, so "0" would be ambiguous */
                q = 0;
            } else {
                int len = cstr_len((const unsigned char *)name, NAME_MAXLEN);
                for (int i = 0; i < len; i++)
                    arena[AO_NAME + i] = (unsigned char)name[i];
                arena[AO_NAME + len] = 0;
                q = (uintptr_t)(arena + AO_NAME);
            }
            stage_retstrings();
            g_ret_mode = p3;
            ret = Code_Variable_Find_Name((const char *)q, p1, p0);
            print_ret(ret, 1);
        } else if (fn == 2) {
            unsigned char *ret;

            wr32(arena + AO_SP, (uint32_t)p0);
            ret = DoConvIntToVariable((unsigned int)p1, arena + AO_SP,
                                      arena + AO_CODE, arena + AO_EXEC);
            print_ret(ret, 0);          /* fn 2/3: the offset is the record */
        } else if (fn == 3) {
            uint32_t raw = (uint32_t)p0;
            int have_id = ((int32_t)raw >= 0);
            int one_word = ((raw & CODE_ONE_WORD) != 0);
            unsigned int slot = AO_SP + (have_id ? 4u : 0u) + (one_word ? 0u : 4u);
            unsigned char *self = 0;
            unsigned char *ret;
            int32_t d;

            fill(arena + AO_VSTACK, 0x40, TAGM_A);
            wr32(arena + AO_VSTACK, 0);            /* id word / slot staging */
            wr32(arena + AO_SP, (uint32_t)p3);     /* the instance id, if read */
            /* the source RValue slot the body will consume */
            wr32(arena + slot, 0x11111111u);
            wr32(arena + slot + 4, 0x33333333u);
            wr32(arena + slot + 8, 0x22222222u);
            wr32(arena + slot + 12, (uint32_t)p2);

            fill(arena + AO_TABLE, 0x80, MARK);
            fill(arena + AO_DYN, 0x30, TAGM_A);
            wr32(arena + AO_CODE, raw);

            if (p1 != 0) {
                self = arena + AO_SELF;
                fill(self, 0x40, 0);
                if (p1 >= 2) {
                    wr32(self + YYB_CTX_GATE, 1);
                    if (p1 == 2)
                        wr32(self + YYB_VAR_TABLE, (uint32_t)(uintptr_t)(arena + AO_TABLE));
                }
            }
            wr32(arena + AO_EXEC + EXEC_SELF, (uint32_t)(uintptr_t)self);

            ret = DoPopLocalVariable((unsigned int)p4, arena + AO_SP,
                                     arena + AO_CODE, arena + AO_EXEC);
            print_ret(ret, 0);
            out("SPDLT ", 6);
            d = (int32_t)((uintptr_t)ret - (uintptr_t)(arena + AO_SP));
            print_i(d);
            out("\n", 1);
        } else {
            quit(4);                       /* malformed case line, loudly */
        }

        out("CALLS ", 6); print_i(n_calls); out("\n", 1);
        if (fn != 1)
            print_mem();
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
