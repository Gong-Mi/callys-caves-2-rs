/*
 * driver.c — the C arm of the Variable_SetValue differential.
 *
 * Built freestanding for ARMv7 and run under qemu-arm (never host-compiled:
 * a 64-bit host build would move every pointer to 8 bytes and every one of the
 * hard-coded field offsets in variable_set.c would stop being the offsets the
 * original reads).
 *
 * It is a *fixture*, not a reconstruction: it stages the hash tables, the
 * CObjectGM instance chain, the two fallback containers and the active list,
 * then calls the translated body once per case and prints a record stream that
 * harness/var_set_diff.py reproduces on the original arm.
 *
 * Case line (stdin):
 *     <sel> <var> <index> <f_s2> <f_c1> <f_c2> <f_s5> <f_s1>
 * Record stream (stdout), per case:
 *     CASE <the 8 fields again>
 *     RET <i32>
 *     D <inst index> <var> <index> <value offset from the staged buffer>
 *     E <NAME|INDEX> <first vararg> <second vararg or "-">
 *     CALLS <n>
 *
 * All staged buffers are zeroed per case and every knob is applied on every
 * case, so a mutant that walks the wrong path still sees readable memory and
 * shows up as a field mismatch instead of a crash.
 */
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);

#include "variable_set.h"

#define NINST      8
#define INST_SIZE  0x180
#define NBUCK      8
#define MARK_WORD  0x5A1E0001u
#define NCH        4

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
static void print_i(int v);
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

uintptr_t __stack_chk_guard = 0xc2331111u;
void __stack_chk_fail(void) { quit(3); }

void *memcpy(void *d, const void *s, size_t n)
{
    unsigned char *a = d; const unsigned char *b = s;
    while (n--) *a++ = *b++;
    return d;
}
void *memset(void *d, int c, size_t n)
{
    unsigned char *a = d;
    while (n--) *a++ = (unsigned char)c;
    return d;
}

/* AEABI aliases: at higher optimisation levels clang emits these instead of
 * the plain mem* calls, and a freestanding image has to answer them itself. */
void *__aeabi_memcpy(void *d, const void *s, size_t n) { return memcpy(d, s, n); }
void *__aeabi_memcpy4(void *d, const void *s, size_t n) { return memcpy(d, s, n); }
void *__aeabi_memcpy8(void *d, const void *s, size_t n) { return memcpy(d, s, n); }
void *__aeabi_memset(void *d, size_t n, int c) { return memset(d, c, n); }
void *__aeabi_memclr(void *d, size_t n) { return memset(d, 0, n); }
void *__aeabi_memclr4(void *d, size_t n) { return memset(d, 0, n); }
void *__aeabi_memclr8(void *d, size_t n) { return memset(d, 0, n); }

static void wr32(void *p, uint32_t w) { memcpy(p, &w, 4); }
static void wr8(void *p, unsigned v) { *(unsigned char *)p = (unsigned char)v; }

static void print_i(int v)
{
    char b[16];
    int i = 0, neg = 0;
    unsigned int u = (unsigned int)v;
    if (v < 0) { neg = 1; u = (unsigned int)(-(long)v); }
    do { b[i++] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) out("-", 1);
    while (i) out(&b[--i], 1);
}
static void print_s(const char *s) { while (*s) { out(s, 1); s++; } }

/* ── staged memory ─────────────────────────────────────────────────────── */
static unsigned char g_inst[NINST * INST_SIZE];
static unsigned char g_objgm[0x100];   /* must span +0xd0 */
static unsigned char g_runtime[0x88];
static unsigned char g_value[16];
static unsigned char g_bucket_obj[NBUCK * 8];
static unsigned char g_bucket_inst[NBUCK * 8];
static unsigned char g_objnodes[3 * 16];
static unsigned char g_instnodes[3 * 16];
static unsigned char g_s2chain[4 * 12];
static unsigned char g_ch1[NCH * 0x50];
static unsigned char g_ch2[NCH * 0x50];
static char g_name[] = "OBJNAME";

static void *g_c1items[2];
static void *g_c2items[2];

static var_hash_table g_tbl_obj;
static var_container   g_cont1;
static var_container   g_cont2;

/* the five globals the translation reads (see variable_set.h) */
void          *g_setvalue_object_table;
var_hash_table g_setvalue_inst_table;
var_container  g_setvalue_container_c1;
var_container  g_setvalue_container_c2;
void          *g_setvalue_runtime;

static int n_calls;

static unsigned char *INST(int i) { return g_inst + (unsigned)i * INST_SIZE; }
static unsigned char *OBJN(int i) { return g_objnodes + (unsigned)i * 16; }
static unsigned char *INSN(int i) { return g_instnodes + (unsigned)i * 16; }
static unsigned char *S2N(int i) { return g_s2chain + (unsigned)i * 12; }
static unsigned char *CH1(int i) { return g_ch1 + (unsigned)i * 0x50; }
static unsigned char *CH2(int i) { return g_ch2 + (unsigned)i * 0x50; }

static uint32_t P(const void *p) { return (uint32_t)(uintptr_t)p; }

/* object/instance-table node {+0 unread, +4 next, +8 key, +0xc value} */
static void put_node(unsigned char *n, const void *next, int32_t key,
                     const void *value)
{
    wr32(n + 0x0, 0u);
    wr32(n + 0x4, P(next));
    wr32(n + 0x8, (uint32_t)key);
    wr32(n + 0xc, P(value));
}

/* CObjectGM instance-chain node {+0 next, +8 instance} */
static void put_inst_node(unsigned char *n, const void *next, const void *inst)
{
    wr32(n + 0x0, P(next));
    wr32(n + 0x4, 0u);
    wr32(n + 0x8, P(inst));
}

/* fallback-container element chain node {+0x18 key, +0x48 next} */
static void put_chain_node(unsigned char *n, int32_t key, const void *next)
{
    wr32(n + KE_KEY, (uint32_t)key);
    wr32(n + KE_NEXT, P(next));
}

static void zero_all(void)
{
    memset(g_inst, 0, sizeof g_inst);
    memset(g_objgm, 0, sizeof g_objgm);
    memset(g_runtime, 0, sizeof g_runtime);
    memset(g_value, 0, sizeof g_value);
    memset(g_bucket_obj, 0, sizeof g_bucket_obj);
    memset(g_bucket_inst, 0, sizeof g_bucket_inst);
    memset(g_objnodes, 0, sizeof g_objnodes);
    memset(g_instnodes, 0, sizeof g_instnodes);
    memset(g_s2chain, 0, sizeof g_s2chain);
    memset(g_ch1, 0, sizeof g_ch1);
    memset(g_ch2, 0, sizeof g_ch2);
}

static void stage(int sel, int f_s2, int f_c1, int f_c2, int f_s5, int f_s1)
{
    uint32_t b = ((uint32_t)sel) & (NBUCK - 1);
    int alt = sel ^ 0x4000;      /* a key that never equals sel */

    zero_all();

    wr32(g_value, MARK_WORD);
    wr32(g_objgm + YYB_NAME, P(g_name));

    g_tbl_obj.buckets = g_bucket_obj;
    g_tbl_obj.mask = NBUCK - 1;
    g_setvalue_inst_table.buckets = g_bucket_inst;
    g_setvalue_inst_table.mask = NBUCK - 1;
    g_setvalue_object_table = &g_tbl_obj;
    g_setvalue_runtime = g_runtime;

    /* containers: items always staged (a count mutant must find real memory),
     * count and gates per knob */
    g_c1items[0] = INST(3); g_c1items[1] = INST(4);
    g_c2items[0] = INST(5); g_c2items[1] = INST(6);
    g_cont1.items = g_c1items; g_cont1.pad = 0; g_cont1.count = 0;
    g_cont2.items = g_c2items; g_cont2.pad = 0; g_cont2.count = 0;
    g_setvalue_container_c1 = g_cont1;
    g_setvalue_container_c2 = g_cont2;

    /* default element chains: INST(3)/INST(5) match sel, INST(4)/INST(6) miss */
    wr32(INST(3) + YYB_ACTIVE_CHAIN, P(CH1(0)));
    wr32(INST(4) + YYB_ACTIVE_CHAIN, P(CH1(1)));
    wr32(INST(5) + YYB_ACTIVE_CHAIN, P(CH2(0)));
    wr32(INST(6) + YYB_ACTIVE_CHAIN, P(CH2(1)));
    put_chain_node(CH1(0), sel, 0);
    put_chain_node(CH1(1), alt, 0);
    put_chain_node(CH2(0), sel, 0);
    put_chain_node(CH2(1), alt, 0);
    put_chain_node(CH1(2), alt, CH1(3));
    put_chain_node(CH1(3), sel, 0);
    put_chain_node(CH2(2), alt, CH2(3));
    put_chain_node(CH2(3), sel, 0);

    /* ── S2 knob: object table -> CObjectGM -> instance chain ─────────── */
    switch (f_s2) {
    case 0:                                     /* empty bucket */
        break;
    case 1:                                     /* chain, key never matches */
        put_node(OBJN(0), 0, alt, &g_objgm);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    case 2:                                     /* key hit, value NULL */
        put_node(OBJN(0), OBJN(1), alt, &g_objgm);
        put_node(OBJN(1), 0, sel, 0);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    case 3:                                     /* key hit, no instance chain */
        put_node(OBJN(0), 0, sel, &g_objgm);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    case 4:                                     /* chain head without an instance */
        put_node(OBJN(0), 0, sel, &g_objgm);
        wr32(g_objgm + YYB_INST_CHAIN, P(S2N(0)));
        put_inst_node(S2N(0), 0, 0);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    case 5:                                     /* three nodes: ok, dead, off */
        put_node(OBJN(0), 0, sel, &g_objgm);
        wr32(g_objgm + YYB_INST_CHAIN, P(S2N(0)));
        put_inst_node(S2N(0), S2N(1), INST(0));
        put_inst_node(S2N(1), S2N(2), INST(1));
        put_inst_node(S2N(2), 0, INST(2));
        wr8(INST(1) + YYB_DESTROYED, 1);
        wr8(INST(2) + YYB_DEACT, 1);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    case 6:                                     /* dead instance, then no instance */
        put_node(OBJN(0), 0, sel, &g_objgm);
        wr32(g_objgm + YYB_INST_CHAIN, P(S2N(0)));
        put_inst_node(S2N(0), S2N(1), INST(1));
        put_inst_node(S2N(1), 0, 0);
        wr8(INST(1) + YYB_DESTROYED, 1);
        wr32(g_bucket_obj + b * 8, P(OBJN(0)));
        break;
    default:
        break;
    }

    /* ── C1 knob ─────────────────────────────────────────────────────── */
    switch (f_c1) {
    case 0: g_cont1.count = 0; break;
    case 1:                                     /* element without a chain, then a miss */
        g_cont1.count = 2;
        wr32(INST(3) + YYB_ACTIVE_CHAIN, 0u);
        break;
    case 2: g_cont1.count = 1; break;
    case 3: g_cont1.count = 1; wr8(INST(3) + YYB_DESTROYED, 1); break;
    case 4: g_cont1.count = 1; wr8(INST(3) + YYB_DEACT, 1); break;
    case 5:                                     /* first gated, second matches */
        g_cont1.count = 2;
        wr8(INST(3) + YYB_DESTROYED, 1);
        wr32(INST(4) + YYB_ACTIVE_CHAIN, P(CH1(0)));
        break;
    case 6:                                     /* two-node chain: miss then hit */
        g_cont1.count = 1;
        wr32(INST(3) + YYB_ACTIVE_CHAIN, P(CH1(2)));
        break;
    case 7: g_cont1.count = -1; break;           /* signed count <= 0 */
    default: break;
    }
    g_setvalue_container_c1 = g_cont1;

    /* ── C2 knob ─────────────────────────────────────────────────────── */
    switch (f_c2) {
    case 0: g_cont2.count = 0; break;
    case 1:
        g_cont2.count = 2;
        wr32(INST(5) + YYB_ACTIVE_CHAIN, 0u);
        break;
    case 2: g_cont2.count = 1; break;
    case 3: g_cont2.count = 1; wr8(INST(5) + YYB_DESTROYED, 1); break;
    case 4: g_cont2.count = 1; wr8(INST(5) + YYB_DEACT, 1); break;
    case 5:                                     /* first gated, second matches */
        g_cont2.count = 2;
        wr8(INST(5) + YYB_DESTROYED, 1);
        wr32(INST(6) + YYB_ACTIVE_CHAIN, P(CH2(0)));
        break;
    case 6:
        g_cont2.count = 1;
        wr32(INST(5) + YYB_ACTIVE_CHAIN, P(CH2(2)));
        break;
    case 7: g_cont2.count = -1; break;
    default: break;
    }
    g_setvalue_container_c2 = g_cont2;

    /* ── S5 knob: instance table -> instance, tail call ───────────────── */
    switch (f_s5) {
    case 0:
        break;
    case 1:
        put_node(INSN(0), 0, alt, INST(7));
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    case 2:
        put_node(INSN(0), 0, sel, 0);
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    case 3:
        put_node(INSN(0), 0, sel, INST(7));
        wr8(INST(7) + YYB_DESTROYED, 1);
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    case 4:
        put_node(INSN(0), 0, sel, INST(7));
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    case 5:                                     /* miss then hit */
        put_node(INSN(0), INSN(1), alt, INST(7));
        put_node(INSN(1), 0, sel, INST(7));
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    case 6:                                     /* +0x69 set: S5 ignores it */
        put_node(INSN(0), 0, sel, INST(7));
        wr8(INST(7) + YYB_DEACT, 1);
        wr32(g_bucket_inst + b * 8, P(INSN(0)));
        break;
    default:
        break;
    }

    /* ── S1 knob: active list ─────────────────────────────────────────── */
    switch (f_s1) {
    case 0:
        break;
    case 1:                                     /* both gated */
        wr8(INST(0) + YYB_DESTROYED, 1);
        wr8(INST(1) + YYB_DEACT, 1);
        wr32(INST(0) + YYB_NEXT, P(INST(1)));
        wr32(INST(1) + YYB_NEXT, 0u);
        wr32(g_runtime + YYB_ACTIVE_CHAIN, P(INST(0)));
        break;
    case 2:                                     /* ok, dead, ok */
        wr8(INST(1) + YYB_DESTROYED, 1);
        wr32(INST(0) + YYB_NEXT, P(INST(1)));
        wr32(INST(1) + YYB_NEXT, P(INST(2)));
        wr32(INST(2) + YYB_NEXT, 0u);
        wr32(g_runtime + YYB_ACTIVE_CHAIN, P(INST(0)));
        break;
    case 3:                                     /* one live instance */
        wr32(INST(0) + YYB_NEXT, 0u);
        wr32(g_runtime + YYB_ACTIVE_CHAIN, P(INST(0)));
        break;
    default:
        break;
    }
}

/* ── stubs (identical on the Python arm) ───────────────────────────────── */
int Variable_SetValue_Direct(void *obj, int var, int index, void *value)
{
    int idx = 0xFF;
    for (int i = 0; i < NINST; i++)
        if ((void *)INST(i) == obj) { idx = i; break; }
    n_calls++;
    out("D ", 2); print_i(idx); out(" ", 1); print_i(var);
    out(" ", 1); print_i(index);
    out(" ", 1); print_i((int)(long)((unsigned char *)value - g_value));
    out("\n", 1);
    return 0x1000 + n_calls * 0x100 + (idx == 0xFF ? 0 : idx);
}

int YYError(const char *fmt, ...)
{
    int a1 = 0;
    const char *a2 = "-";
    int is_name, is_plain;
    const char *kind;
    va_list ap;

    /* classify by the text of the format string, not by its address */
    {
        const char *p = fmt, *q = MSG_NO_INSTANCE_NAME;
        while (*p && *p == *q) { p++; q++; }
        is_name = (*p == 0 && *q == 0);
    }
    {
        const char *p = fmt, *q = MSG_NO_INSTANCE;
        while (*p && *p == *q) { p++; q++; }
        is_plain = (*p == 0 && *q == 0);
    }
    kind = is_name ? "NAME" : (is_plain ? "INDEX" : "OTHER");
    va_start(ap, fmt);
    a1 = va_arg(ap, int);
    if (is_name)
        a2 = va_arg(ap, const char *);
    va_end(ap);
    n_calls++;
    out("E ", 2); print_s(kind); out(" ", 1);
    print_i(a1); out(" ", 1); print_s(a2 ? a2 : "-"); out("\n", 1);
    return 0xEEEE;
}

/* ── case loop ─────────────────────────────────────────────────────────── */
static int read_int(const char **pp)
{
    const char *p = *pp;
    int neg = 0, v = 0;
    while (*p == ' ' || *p == '\t' || *p == '\n') p++;
    if (*p == '-') { neg = 1; p++; }
    while (*p >= '0' && *p <= '9') { v = v * 10 + (*p - '0'); p++; }
    *pp = p;
    return neg ? -v : v;
}

int main(void)
{
    static char inbuf[8192];
    long n = read_all(inbuf, (long)sizeof inbuf - 1);
    if (n <= 0) quit(2);
    inbuf[n] = 0;
    const char *p = inbuf;

    while (*p) {
        int sel = read_int(&p);
        int var = read_int(&p);
        int index = read_int(&p);
        int f_s2 = read_int(&p);
        int f_c1 = read_int(&p);
        int f_c2 = read_int(&p);
        int f_s5 = read_int(&p);
        int f_s1 = read_int(&p);
        if (*p == 0 && sel == 0 && var == 0 && index == 0 && f_s2 == 0 &&
            f_c1 == 0 && f_c2 == 0 && f_s5 == 0 && f_s1 == 0)
            break;

        stage(sel, f_s2, f_c1, f_c2, f_s5, f_s1);
        n_calls = 0;

        out("CASE ", 5);
        print_i(sel); out(" ", 1); print_i(var); out(" ", 1);
        print_i(index); out(" ", 1);
        print_i(f_s2); out(" ", 1); print_i(f_c1); out(" ", 1);
        print_i(f_c2); out(" ", 1); print_i(f_s5); out(" ", 1);
        print_i(f_s1); out("\n", 1);

        int ret = Variable_SetValue(sel, var, index, g_value);

        out("RET ", 4); print_i(ret); out("\n", 1);
        out("CALLS ", 6); print_i(n_calls); out("\n", 1);
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
