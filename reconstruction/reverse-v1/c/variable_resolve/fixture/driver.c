/*
 * driver.c — the C arm of the Variable_GetValue differential.
 *
 * Freestanding ARMv7 under qemu-arm, like the other Level A arms: every offset
 * this body uses (0x4 next / 0x8 key / 0xc value / 0x18 index / 0x48 parent /
 * 0x68 / 0x69 / 0x80 / 0xd0 / 0x178) is a literal, the buckets are addressed
 * with `lsl #3` and the list items with `lsl #2`.  A host build moves pointers
 * to 8 bytes and every one of those offsets stops testing what the original
 * does.
 *
 * The staging is not a hand-written mirror of the Python arm: both arms
 * interpret the SAME case program, a list of writes
 *
 *     <region> <index> <offset> <kind> <a> <b>
 *
 * where the address is base(region) + index*stride(region) + offset, and
 * kind 0 stores `a`, kind 1 stores the address base(a) + b*stride(a) - i.e. a
 * cross-region pointer.  Each arm supplies its own region bases (the original
 * arm uses the mapped image's own .bss addresses, this arm its own globals),
 * so the two arms stage the same object graph at different addresses, which is
 * exactly what makes pointers non-comparable and record normalisation
 * mandatory.
 *
 * Record stream (stdout), identical on both arms:
 *     CASE <n> <p1> <p2> <p3>
 *     RET  <i32>
 *     OUT  <32 hex chars>            the 16 destination bytes
 *     FLAG <0|1>                     the 1-byte failure flag after the call
 *     CALLS <n>                      stub invocations
 *     G <inst> <arrindex> <srcoff>   GET_RValue (srcoff relative to region S)
 *     B <inst> <arrindex>            builtin-variable getter
 *     I <slot>                       InternalGetYYVar (not reached: every staged
 *                                    instance has a non-NULL variable table)
 * No raw pointer is ever printed.
 */
#include <stdint.h>
#include <stddef.h>

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);

#include "variable_resolve.h"
#include "variable_direct.h"

#define NINST 8
#define INST_BYTES 0x180
#define NOGM 4
#define OGM_BYTES 0x100
#define NNODE 8
#define NODE_BYTES 0x10
#define NCHAIN 6
#define CHAIN_BYTES 0x0c
#define NITEM 8
#define SLOTN 8
#define SLOT_BYTES 0x40
#define NBUCK 512
#define MARK_BYTE 0xA0
#define OUT_PRESET 0x00FFFFFFu

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

uintptr_t __stack_chk_guard = 0xc2332222u;
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

static void wr32(void *p, uint32_t w) { memcpy(p, &w, 4); }

/* ── the six .bss globals, plus the staged regions ─────────────────────── */
unsigned char g_var_resolve_failed;
var_hash_table g_inst_table;
var_hash_table *g_object_hash;
var_scan_list g_scan_list1;
var_scan_list g_scan_list2;
void *g_run_room;

static unsigned char inst_buf[NINST * INST_BYTES];
static unsigned char ogm_buf[NOGM * OGM_BYTES];
static unsigned char node_buf[NNODE * NODE_BYTES];
static unsigned char chain_buf[NCHAIN * CHAIN_BYTES];
static unsigned char item_buf[NITEM * 4];
static unsigned char slot_buf[SLOTN * SLOT_BYTES];
static unsigned char objtab_buf[0x0c];
static unsigned char instbk_buf[NBUCK * 8];
static unsigned char objbk_buf[NBUCK * 8];
static unsigned char room_buf[0x88];
static unsigned char out_buf[0x10];

typedef struct {
    char id;
    unsigned char *base;
    unsigned count;
    unsigned stride;
} region_t;

static const region_t REG[] = {
    {'I', inst_buf, NINST, INST_BYTES},
    {'O', ogm_buf, NOGM, OGM_BYTES},
    {'B', node_buf, NNODE, NODE_BYTES},
    {'C', chain_buf, NCHAIN, CHAIN_BYTES},
    {'L', item_buf, NITEM, 4},
    {'S', slot_buf, SLOTN, SLOT_BYTES},
    {'T', (unsigned char *)&g_inst_table, 1, 0x0c},
    {'U', objtab_buf, 1, 0x0c},
    {'K', instbk_buf, NBUCK, 8},
    {'V', objbk_buf, NBUCK, 8},
    {'R', room_buf, 1, 0x88},
    {'Q', (unsigned char *)&g_scan_list1, 1, 0x0c},
    {'W', (unsigned char *)&g_scan_list2, 1, 0x0c},
    {'G', (unsigned char *)&g_object_hash, 1, 4},
    {'Y', (unsigned char *)&g_run_room, 1, 4},
    {'X', out_buf, 1, 0x10},
};

static const region_t *reg(char c)
{
    for (unsigned i = 0; i < sizeof REG / sizeof REG[0]; i++)
        if (REG[i].id == c)
            return &REG[i];
    quit(4);
}

typedef struct {
    char reg;
    int idx, off, kind;
    int a, b;
} wr_t;

static void apply_writes(const wr_t *w, int n)
{
    for (int i = 0; i < n; i++) {
        const region_t *r = reg(w[i].reg);
        uintptr_t addr = (uintptr_t)r->base + (unsigned)w[i].idx * r->stride +
                         (unsigned)w[i].off;
        uint32_t v;
        if (w[i].kind) {
            const region_t *s = reg((char)w[i].a);
            v = (uint32_t)((uintptr_t)s->base + (unsigned)w[i].b * s->stride);
        } else {
            v = (uint32_t)w[i].a;
        }
        wr32((void *)addr, v);
    }
}

static void reset_regions(void)
{
    for (unsigned i = 0; i < sizeof REG / sizeof REG[0]; i++)
        memset(REG[i].base, 0, REG[i].count * REG[i].stride);
    memset(out_buf, 0xee, sizeof out_buf);
    wr32(out_buf, OUT_PRESET);   /* the caller's "not resolved" tag */
}

static int inst_index(const void *p)
{
    uintptr_t a = (uintptr_t)p;
    for (int i = 0; i < NINST; i++)
        if ((uintptr_t)inst_buf + (unsigned)i * INST_BYTES == a)
            return i;
    return -1;
}

/* ── staged call targets ───────────────────────────────────────────────── */
static unsigned char bvar_storage[10000 * RV_SLOT_STRIDE];
void *const g_builtin_var_table_slot = (void *)bvar_storage;

static int n_calls;

static void fill_marker(void *dst, unsigned char base)
{
    unsigned char *p = dst;
    for (int i = 0; i < RV_SLOT_STRIDE; i++)
        p[i] = (unsigned char)(base + i);
}

static unsigned char marker_base(int inst)
{
    return (unsigned char)(inst < 0 ? 0x30 : 0x50 + inst);
}

static int stub_bvar_getter(void *obj, int arrindex, void *o)
{
    n_calls++;
    out("B ", 2); print_i(inst_index(obj)); out(" ", 1);
    print_i(arrindex); out("\n", 1);
    fill_marker(o, marker_base(inst_index(obj)));
    return 0x1111;
}

int GET_RValue(void *dst, void *src, int arrindex)
{
    /* Direct passes (out, slot, arrindex), so the instance is not an argument.
     * It is still identified: every instance's variable table is its own 0x40 B
     * window of region S, so the delta src - S_base encodes (instance, slot) -
     * and keeps encoding it when the slot index is negative and the address
     * lands below the region. */
    long off = (long)((uintptr_t)src - (uintptr_t)slot_buf);
    n_calls++;
    out("G ", 2); print_i(arrindex); out(" ", 1); print_i((int)off); out("\n", 1);
    fill_marker(dst, marker_base(-1));
    return 0x2222;
}

void *InternalGetYYVar(void *self, int slot)
{
    (void)self;
    n_calls++;
    out("I ", 2); print_i(slot); out("\n", 1);
    fill_marker(slot_buf + (SLOTN - 1) * SLOT_BYTES, 0x80);
    return slot_buf + (SLOTN - 1) * SLOT_BYTES;
}

/* ── integer formatting (no printf here) ───────────────────────────────── */
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

/* ── case program ──────────────────────────────────────────────────────── */
static int read_int(const char **pp)
{
    /* Unsigned accumulation: 2147483648 has to survive into INT_MIN, and
     * signed accumulation would be UB before the sign is applied. */
    const char *p = *pp;
    int neg = 0;
    unsigned v = 0;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') p++;
    if (*p == '-') { neg = 1; p++; }
    while (*p >= '0' && *p <= '9') { v = v * 10u + (unsigned)(*p - '0'); p++; }
    *pp = p;
    return (int)(neg ? 0u - v : v);
}

static char read_reg(const char **pp)
{
    const char *p = *pp;
    while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') p++;
    *pp = p + 1;
    return *p;
}

static char inbuf[192 * 1024];   /* the whole case program in one read */
static wr_t writes[256];

int main(void)
{
    long n = read_all(inbuf, (long)sizeof inbuf - 1);
    if (n <= 0) quit(2);
    inbuf[n] = 0;
    const char *p = inbuf;

    for (int i = 0; i < 10000; i++) {
        wr32(bvar_storage + i * RV_SLOT_STRIDE, 0u);
        wr32(bvar_storage + i * RV_SLOT_STRIDE + 4,
             (uint32_t)(uintptr_t)stub_bvar_getter);
    }

    for (int k = 0; k < 512; k++) {
        while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r') p++;
        if (!*p)
            break;
        int p1 = read_int(&p);
        int p2 = read_int(&p);
        int p3 = read_int(&p);
        int nw = read_int(&p);
        if (nw < 0 || nw > 256) quit(5);
        for (int i = 0; i < nw; i++) {
            writes[i].reg = read_reg(&p);
            writes[i].idx = read_int(&p);
            writes[i].off = read_int(&p);
            writes[i].kind = read_int(&p);
            writes[i].a = read_int(&p);
            writes[i].b = read_int(&p);
        }
        reset_regions();
        apply_writes(writes, nw);
        n_calls = 0;

        out("CASE ", 5); print_i(k); out(" ", 1);
        print_i(p1); out(" ", 1); print_i(p2); out(" ", 1); print_i(p3);
        out("\n", 1);

        int ret = Variable_GetValue(p1, p2, p3, out_buf);

        out("RET ", 4); print_i(ret); out("\n", 1);
        out("OUT ", 4);
        for (int i = 0; i < RV_SLOT_STRIDE; i++) {
            static const char hex[] = "0123456789abcdef";
            char two[2];
            two[0] = hex[(out_buf[i] >> 4) & 0xf];
            two[1] = hex[out_buf[i] & 0xf];
            out(two, 2);
        }
        out("\nFLAG ", 6); print_i(g_var_resolve_failed); out("\n", 1);
        out("CALLS ", 6); print_i(n_calls); out("\n", 1);
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
