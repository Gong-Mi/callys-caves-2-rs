/*
 * driver.c — the C arm of the variable-name differential.
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm, so a pointer
 * is 4 bytes: vn_node's key really lands at +8 and the instance field at +0xc,
 * the bucket really is 8 B, and `lsl #3` in the original means what the
 * translation says it means.  A host build would move every one of those
 * offsets by 4 and quietly stop testing them.
 *
 * It is a *fixture*, not a reconstruction: it stages the two .bss globals of
 * Find_Slot_From_Name, the instance table / room chain / failure byte of
 * GetObjectName, and identical stubs for the three unrecovered callees, then
 * calls the translated body once per case and prints a record stream that
 * harness/var_names_diff.py reproduces from the original bytes.
 *
 * Case line (stdin), 8 integers:
 *   fn=1  self_kind mode host_kind local_ret global_ret name_tag unused
 *         self_kind 0 = self is the host object, 1 = some other object,
 *                   2 = NULL
 *         host_kind 0 = *g_varname_host is the host object, 1 = NULL
 *         name_tag  0 "alpha" / 1 "" (empty) / 2 "beta" / 3 NULL
 *   fn=2  id varid bucket_mode room_mode objindex mask_override
 *         bucket_mode 0 none, 1 hit, 2 hit in another bucket, 3 chain end,
 *                     4 walk-then-hit, 5 NULL instance, 6 destroyed instance,
 *                     7 deactivated instance (+0x69 only)
 *         room_mode   0 empty room, 1 single live, 2 destroyed then live,
 *                     3 deactivated then live, 4 destroyed+deact then live,
 *                     5 all dead, 6 live head with a live next
 *
 * Record stream (stdout):
 *   CASE <fn> <p0..p6>
 *   RET <i32>                      fn=1: the returned slot
 *   RET <CLS> <hexbytes>           fn=2: class + the bytes at the returned pointer
 *   CALLS <n>
 *   L <len> <text>   / G <len> <text>        Find_Slot callee: the name it got
 *   O <objindex>                             Object_Name callee: the index it got
 *   FLAG <0|1>                               the 0x75505c byte after the call
 *
 * No raw pointer is ever printed: fn=2's return is normalised to its content,
 * and the classes are UNK (the "<unknown_object>" literal), NAME (a string the
 * Object_Name stub minted), RAW (anything else) and NULL.
 */
#include <stdint.h>
#include <stddef.h>

void *memcpy(void *d, const void *s, size_t n);
void *memset(void *d, int c, size_t n);

#include "variable_names.h"

#define NINST 4
#define INST_SIZE 0x180
#define NBUCK 8
#define NNODE 4
#define MARK 0x5c

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

/* ── the two .bss globals of Find_Slot_From_Name ──────────────────────── */
void *g_varname_host = 0;
unsigned char g_varname_mode = 0;

/* ── the three .bss globals of Variable_GetObjectName ─────────────────── */
vn_hash_table g_objname_inst_table;
void *g_run_room = 0;
unsigned char g_objname_fail = 0;

/* ── staged memory ─────────────────────────────────────────────────────── */
static unsigned char host_obj[0x40];
static unsigned char other_obj[0x40];
static unsigned char buckets[NBUCK * 8];
static vn_node nodes[NNODE];
static unsigned char insts[NINST * INST_SIZE];
static unsigned char room[0x88];
static int n_calls;
static int g_local_ret, g_global_ret;

/* ── stubs (identical on the Python arm) ───────────────────────────────── */
/* "<len> <text>" with len == -1 for a NULL pointer, so a NULL name and an
 * empty name are different records.  Only printable bytes are echoed. */
static void print_stub_name(const char *p)
{
    int n = -1;

    if (p != 0) {
        n = 0;
        while (p[n] && n < 40)
            n++;
    }
    out(" ", 1);
    print_i(n);
    out(" ", 1);
    for (int i = 0; i < n; i++) {
        char c = p[i];
        if (c < 0x20 || c > 0x7e)
            c = '?';
        out(&c, 1);
    }
}

int Code_Variable_Find_Slot_From_Local_Name(const char *name)
{
    n_calls++;
    out("L", 1);
    print_stub_name(name);
    out("\n", 1);
    return g_local_ret;
}

int Code_Variable_Find_Slot_From_Global_Name(const char *name)
{
    n_calls++;
    out("G", 1);
    print_stub_name(name);
    out("\n", 1);
    return g_global_ret;
}

static char objname_buf[24];

const char *Object_Name(int objindex)
{
    int i = 0, neg = 0;
    unsigned int u;
    n_calls++;
    out("O ", 2); print_i(objindex); out("\n", 1);
    objname_buf[i++] = 'O';
    objname_buf[i++] = 'B';
    objname_buf[i++] = 'J';
    u = (unsigned int)objindex;
    if (objindex < 0) {
        neg = 1;
        u = (unsigned int)(-(long)objindex);
    }
    char tmp[12];
    int t = 0;
    do { tmp[t++] = (char)('0' + (u % 10u)); u /= 10u; } while (u);
    if (neg) objname_buf[i++] = '-';
    while (t)
        objname_buf[i++] = tmp[--t];
    objname_buf[i] = 0;
    return objname_buf;
}

/* ── the three names a case can pass ──────────────────────────────────── */
static const char *name_by_tag(int tag)
{
    static const char alpha[] = "alpha";
    static const char beta[] = "beta";
    static const char empty[] = "";
    switch (tag) {
    case 0: return alpha;
    case 1: return empty;
    case 2: return beta;
    default: return 0;                 /* NULL */
    }
}

/* ── integer formatting (no printf here) ──────────────────────────────── */
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

static void print_hex(const char *p, int n)
{
    static const char hex[] = "0123456789abcdef";
    for (int i = 0; i < n; i++) {
        char two[2];
        unsigned char b = (unsigned char)p[i];
        two[0] = hex[(b >> 4) & 0xf];
        two[1] = hex[b & 0xf];
        out(two, 2);
    }
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

static void stage_instances(int objindex)
{
    unsigned char *p;

    for (unsigned i = 0; i < sizeof insts; i++)
        insts[i] = 0;
    for (int i = 0; i < NINST; i++) {
        p = insts + i * INST_SIZE;
        wr32(p + YYB_OBJINDEX, (uint32_t)(objindex + i));
        wr32(p + YYB_NEXT, 0u);
    }
}

static unsigned char *inst(int i) { return insts + i * INST_SIZE; }

static void stage_room(int room_mode)
{
    unsigned char *head;
    wr32(room + ROOM_INST_CHAIN, 0u);
    if (room_mode == 0)
        return;
    head = inst(0);
    wr32(room + ROOM_INST_CHAIN, (uint32_t)(uintptr_t)head);
    switch (room_mode) {
    case 1:                                    /* single live instance */
        break;
    case 2:                                    /* destroyed, then live */
        inst(0)[YYB_DESTROYED] = 1;
        wr32(inst(0) + YYB_NEXT, (uint32_t)(uintptr_t)inst(1));
        break;
    case 3:                                    /* deactivated, then live */
        inst(0)[YYB_DEACT] = 1;
        wr32(inst(0) + YYB_NEXT, (uint32_t)(uintptr_t)inst(1));
        break;
    case 4:                                    /* destroyed + deact, then live */
        inst(0)[YYB_DESTROYED] = 1;
        wr32(inst(0) + YYB_NEXT, (uint32_t)(uintptr_t)inst(1));
        inst(1)[YYB_DEACT] = 1;
        wr32(inst(1) + YYB_NEXT, (uint32_t)(uintptr_t)inst(2));
        break;
    case 5:                                    /* every instance dead */
        inst(0)[YYB_DESTROYED] = 1;
        wr32(inst(0) + YYB_NEXT, (uint32_t)(uintptr_t)inst(1));
        inst(1)[YYB_DESTROYED] = 1;
        break;
    case 6:                                    /* live head with a live next */
        wr32(inst(0) + YYB_NEXT, (uint32_t)(uintptr_t)inst(1));
        break;
    default:
        break;
    }
}

static void stage_buckets(int bucket_mode, int id, uint32_t mask)
{
    uint32_t b;
    unsigned char *hi = inst(NINST - 1);   /* the hash path's own instance, so a
                                            * bucket case cannot perturb the room
                                            * chain a room case stages */
    for (unsigned i = 0; i < sizeof buckets; i++)
        buckets[i] = 0;
    for (int i = 0; i < NNODE; i++) {
        nodes[i].f0 = 0;
        nodes[i].next = 0;
        nodes[i].key = 0;
        nodes[i].value = 0;
    }
    if (bucket_mode == 0)
        return;
    b = (uint32_t)id & mask;
    if (bucket_mode == 2)
        b ^= 1u;                                /* the *other* bucket */
    switch (bucket_mode) {
    case 1:
        nodes[0].key = id;
        nodes[0].value = hi;
        break;
    case 2:
        nodes[0].key = id;
        nodes[0].value = hi;
        break;
    case 3:                                    /* chain of one, wrong key */
        nodes[0].key = id + 1;
        break;
    case 4:                                    /* walk, then hit */
        nodes[0].key = id + 1;
        nodes[0].next = &nodes[1];
        nodes[1].key = id;
        nodes[1].value = hi;
        break;
    case 5:                                    /* node with a NULL instance */
        nodes[0].key = id;
        break;
    case 6:                                    /* node whose instance is destroyed */
        hi[YYB_DESTROYED] = 1;
        nodes[0].key = id;
        nodes[0].value = hi;
        break;
    case 7:                                    /* +0x69 only: still a name */
        hi[YYB_DEACT] = 1;
        nodes[0].key = id;
        nodes[0].value = hi;
        break;
    default:
        break;
    }
    wr32(buckets + (b % NBUCK) * 8u, (uint32_t)(uintptr_t)&nodes[0]);
}

static int str_len(const char *p)
{
    int n = 0;
    if (p == 0)
        return -1;
    while (p[n] && n < 40)
        n++;
    return n;
}

/* UNK  the shared "<unknown_object>" literal of the five failure exits
 * NAME a string the Object_Name stub minted
 * RAW  anything else - an arm-specific pointer that is neither
 * NULL the stub handed back 0 (cannot happen in this body; kept so it cannot
 *      be silently confused with the others) */
static const char *ret_class(const char *p, int *len)
{
    int n = str_len(p);
    int u = str_len(MSG_UNKNOWN_OBJECT);

    *len = n < 0 ? 0 : n;
    if (n < 0)
        return "NULL";
    if (n == u) {
        int same = 1;
        for (int i = 0; i < n; i++)
            if (p[i] != MSG_UNKNOWN_OBJECT[i]) { same = 0; break; }
        if (same)
            return "UNK";
    }
    if (n >= 3 && p[0] == 'O' && p[1] == 'B' && p[2] == 'J')
        return "NAME";
    return "RAW";
}

static void out_s(const char *s)
{
    uint32_t n = 0;
    while (s[n])
        n++;
    out(s, n);
}

int main(void)
{
    static char inbuf[8192];
    long n = read_all(inbuf, (long)sizeof inbuf - 1);
    if (n <= 0) quit(2);
    inbuf[n] = 0;
    const char *p = inbuf;

    while (*p) {
        int fn = read_int(&p);
        int p0 = read_int(&p), p1 = read_int(&p), p2 = read_int(&p);
        int p3 = read_int(&p), p4 = read_int(&p), p5 = read_int(&p);
        int p6 = read_int(&p);
        if (*p == 0 && fn == 0)
            break;
        if (fn != 1 && fn != 2)
            quit(4);                       /* malformed case line, loudly */

        for (unsigned i = 0; i < sizeof host_obj; i++) host_obj[i] = 0x11;
        for (unsigned i = 0; i < sizeof other_obj; i++) other_obj[i] = 0x22;
        for (unsigned i = 0; i < sizeof room; i++) room[i] = 0;
        g_objname_fail = 0;
        n_calls = 0;

        out("CASE ", 5);
        print_i(fn); out(" ", 1);
        print_i(p0); out(" ", 1); print_i(p1); out(" ", 1);
        print_i(p2); out(" ", 1); print_i(p3); out(" ", 1);
        print_i(p4); out(" ", 1); print_i(p5); out(" ", 1);
        print_i(p6); out("\n", 1);

        if (fn == 1) {
            void *self;
            const char *name;
            int ret;

            g_varname_host = p2 ? 0 : (void *)host_obj;
            g_varname_mode = (unsigned char)p1;
            g_local_ret = p3;
            g_global_ret = p4;
            self = (p0 == 0) ? g_varname_host : (p0 == 1 ? (void *)other_obj : 0);
            name = name_by_tag(p5);

            ret = Code_Variable_Find_Slot_From_Name(self, name);
            out("RET ", 4); print_i(ret); out("\n", 1);
        } else {
            const char *r;
            int len = 0;
            const char *cls;

            g_objname_inst_table.buckets = buckets;
            g_objname_inst_table.mask = p5 ? (uint32_t)p5 : (uint32_t)(NBUCK - 1);
            stage_instances(p4);
            stage_room(p3);
            stage_buckets(p2, p0, g_objname_inst_table.mask);
            g_run_room = (void *)room;

            r = Variable_GetObjectName(p0, p1);
            cls = ret_class(r, &len);
            out("RET ", 4); out_s(cls);
            out(" ", 1); print_hex(r, len); out("\n", 1);
        }

        out("CALLS ", 6); print_i(n_calls); out("\n", 1);
        out("FLAG ", 5); print_i(g_objname_fail ? 1 : 0); out("\n", 1);
    }
    quit(0);            /* no CRT: returning from main would jump to nothing */
}
