/*
 * driver.c — the C arm of the Variable_GetValue_Direct differential.
 *
 * Built the same way as the other Level A arms: freestanding ARMv7 under
 * qemu-arm, so pointers are 4 bytes and the builtin-variable table entry really
 * is 16 B with its getter at +4 (0x1f3bf8 ldr r3,[r12,#0x4]).  A host build
 * would silently move that field to +8 and stop testing the offset.
 *
 * It is a *fixture*, not a reconstruction: it stages the object, the slot table
 * and identical stubs for the three library-internal callees, then calls the
 * translated body once per case and prints a record stream that
 * harness/var_direct_diff.py reproduces on the original arm.
 *
 * Case line (stdin):  <varid> <arrindex> <flag24> <table_mode> <intget_slot>
 * Record stream (stdout):
 *     CASE <varid> <arrindex> <flag24> <table_mode> <intget_slot>
 *     RET <i32>
 *     OUT <32 hex chars>
 *     CALLS <n>
 *     B <arrindex> <ret>
 *     G <table_offset|L|NULL> <arrindex> <ret>
 *     I <slot>
 * Addresses are never printed: offsets are relative to the staged slot table.
 */
#include <stdint.h>
#include <stddef.h>

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);

#include "variable_direct.h"

#define NSLOTS 256
#define NBVAR 10000
#define MARK_BYTE 0xA0

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

static void wr32(void *p, uint32_t w) { memcpy(p, &w, 4); }

/* ── staged memory ─────────────────────────────────────────────────────── */
static unsigned char obj_buf[0x40];
static unsigned char slot_table[NSLOTS * RV_SLOT_STRIDE];
static unsigned char lazy_slot[RV_SLOT_STRIDE];
static unsigned char out_buf[RV_SLOT_STRIDE];
static unsigned char bvar_storage[NBVAR * RV_SLOT_STRIDE];
static int n_calls;
static int intget_called;

void *const g_builtin_var_table_slot = (void *)bvar_storage;

static void fill_marker(void *dst, unsigned char base)
{
    unsigned char *p = (unsigned char *)dst;
    for (int i = 0; i < RV_SLOT_STRIDE; i++)
        p[i] = (unsigned char)(base + i);
}

/* ── stubs (identical on the Python arm) ───────────────────────────────── */
static int stub_bvar_getter(void *obj, int arrindex, void *o)
{
    (void)obj;
    n_calls++;
    out("B ", 2); print_i(arrindex); out(" 4369\n", 6);
    fill_marker(o, MARK_BYTE);
    return 0x1111;
}

int GET_RValue(void *dst, void *src, int arrindex)
{
    long off = 0;
    n_calls++;
    out("G ", 2);
    if (src == NULL) {
        out("NULL", 4);
    } else if (intget_called && src == lazy_slot) {
        out("L", 1);
    } else {
        off = (long)((unsigned char *)src - slot_table);
        print_i((int)off);
    }
    out(" ", 1); print_i(arrindex); out(" 8738\n", 6);
    fill_marker(dst, (unsigned char)(0x40 + (off & 0x1f)));
    return 0x2222;
}

void *InternalGetYYVar(void *self, int slot)
{
    (void)self;
    n_calls++;
    intget_called = 1;
    out("I ", 2); print_i(slot); out("\n", 1);
    fill_marker(lazy_slot, 0x80);
    return lazy_slot;
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
        int varid = read_int(&p);
        int arrindex = read_int(&p);
        int flag24 = read_int(&p);
        int table_mode = read_int(&p);
        int intget_slot = read_int(&p);
        if (*p == 0 && varid == 0 && arrindex == 0 && flag24 == 0 &&
            table_mode == 0 && intget_slot == 0)
            break;

        for (unsigned i = 0; i < sizeof obj_buf; i++) obj_buf[i] = 0;
        for (unsigned i = 0; i < sizeof slot_table; i++) slot_table[i] = 0x5c;
        for (unsigned i = 0; i < sizeof lazy_slot; i++) lazy_slot[i] = 0;
        for (unsigned i = 0; i < sizeof out_buf; i++) out_buf[i] = 0xee;

        wr32(obj_buf + YYB_VAR_FLAG, (uint32_t)flag24);
        wr32(obj_buf + YYB_VAR_TABLE, table_mode ? (uint32_t)(uintptr_t)slot_table : 0u);

        for (int i = 0; i < NBVAR; i++) {
            wr32(bvar_storage + i * RV_SLOT_STRIDE, 0u);
            wr32(bvar_storage + i * RV_SLOT_STRIDE + 4, (uint32_t)(uintptr_t)stub_bvar_getter);
        }

        n_calls = 0;
        intget_called = 0;
        out("CASE ", 5);
        print_i(varid); out(" ", 1); print_i(arrindex); out(" ", 1);
        print_i(flag24); out(" ", 1); print_i(table_mode); out(" ", 1);
        print_i(intget_slot); out("\n", 1);

        int ret = Variable_GetValue_Direct(obj_buf, varid, arrindex, out_buf);

        out("RET ", 4); print_i(ret); out("\n", 1);
        out("OUT ", 4);
        for (int i = 0; i < RV_SLOT_STRIDE; i++) {
            static const char hex[] = "0123456789abcdef";
            char two[2];
            two[0] = hex[(out_buf[i] >> 4) & 0xf];
            two[1] = hex[out_buf[i] & 0xf];
            out(two, 2);
        }
        out("\nCALLS ", 7); print_i(n_calls); out("\n", 1);
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
