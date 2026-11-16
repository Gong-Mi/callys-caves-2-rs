/*
 * driver.c — the C arm of the CInstance SetObjectIndex / constructor
 * differential.
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm, so a pointer
 * is 4 bytes and every `lsl #3` / `lsl #2` / `strd` in the original means what
 * the translation says it means.  A host build would move all of it by 4 and
 * quietly stop testing it.
 *
 * It is a fixture, not a reconstruction: it stages the .bss objects the two
 * bodies reach through the .got (the object hash, the instance table, the
 * builtin table), provides identical stubs for every unrecovered callee, and
 * calls the translated body once per case, printing the record stream that
 * harness/instance_ctor_diff.py reproduces from the original bytes.
 *
 * Case line (stdin), 9 integers: fn p0 p1 p2 p3 p4 p5 p6 p7
 *
 *   fn=1  CInstance_SetObjectIndex
 *     p0 = objindex (int32, any value incl. -1 / INT_MIN)
 *     p1 = addToObject (0 is the only false value: 2 is true)
 *     p2 = old-object / probe mode
 *            0  +0x80 = 0, no probe
 *            1  +0x80 = OBJ2
 *            2  +0x80 = OBJ2, and the RemoveInstance stub scribbles
 *               inst+0x7c = 0x0000beef while it runs
 *            3  +0x80 = 0, and the AddInstance stub re-points inst+0x80 at OBJ3
 *            4  both probes at once
 *     p3 = hash scenario
 *            0  all buckets empty
 *            1  the target bucket holds one node: key = objindex, value = OBJ1
 *            2  the target bucket holds a two-node chain; the target is second
 *            3  a two-node chain with no matching key
 *            4  one node with key = objindex and value = 0
 *            5  bucket 7 holds one node with key = -1 and value = OBJ1
 *            6  the bucket of key 0 holds one node: key 0, value = OBJ1
 *            7  first node key = objindex value = OBJ2, second node key =
 *               objindex value = OBJ1 (the first match must win)
 *     p4 = OBJ1 flags word (bit0 solid, bit1 visible, bit2 persistent, bits 3+
 *          must not reach anything)
 *     p5 = OBJ1 sprite
 *     p6 = OBJ1 depth (int32; the body converts it with vcvt.f32.s32)
 *     p7 = OBJ1 mask
 *
 *   fn=2  CInstance_ctor
 *     p0 = prefill of the 0x1b0-byte block
 *            0  zeros (what operator new leaves)
 *            1  0xa5 in every byte
 *            2  a stale live instance: +0x80 = OBJ3, +0x44 = 3, +0x10/+0x14 and
 *               the list rings set to junk
 *     p1 = x as raw float bits      p2 = y as raw float bits
 *     p3 = id           p4 = objindex           p5 = addToObject
 *     p6 = instance-table / builtin scenario
 *            0  cap 0 (slot -1)                    1  slot 1
 *            2  slot 3                             3  next_free = cap -> clamp
 *            4  full -> grow 4 -> 6, slot 4        5  full -> grow 2 -> 3, slot 2
 *            6  gate on, 2 entries, none global    7  gate on, first is global
 *            8  gate on, both global               9  gate on, count 0
 *           10  gate OFF but two entries staged
 *     p7 = bits: bit0 base-ctor stack-trace gate
 *                bit1 stage the object hash so objindex hits
 *                bit2 base-ctor argument 1 = INT_MIN instead of 0x00012345
 *
 * Record stream (stdout): CASE / RET / C... / CALLS / EXT / MEM, one record
 * per case.
 *
 * No raw pointer is ever printed.  Every 32-bit word in MEM becomes an 8-char
 * token: "00000000" for zero, "A" + 7 hex digits inside the arena, "S0000001"
 * for the vtable value, else 8 hex digits of the word itself.
 */
#include <stdint.h>
#include <stddef.h>

#include "instance_ctor.h"

#define IC_MARK 0xcc

static uint8_t arena[IC_ARENA_SIZE] __attribute__((aligned(16)));

/* ── the globals ────────────────────────────────────────────────────────── */
ic_hash *g_object_hash;
ic_instance_table g_instance_table;
uint64_t g_create_counter;
uint8_t g_builtin_gate;
int32_t g_builtin_numb;
/* 0x0075310c is the table itself (16-byte entries), not a pointer variable. */
ic_builtin_entry g_builtin_table[500];
int32_t g_base_ctor_arg1;
uint32_t g_cinstance_vtable_head[4] = {0x5a5a5a5a, 0x5a5a5a5b,
                                       0x5a5a5a5c, 0x5a5a5a5d};

static uint32_t g_vt(void)
{
    return (uint32_t)(uintptr_t)((uint8_t *)g_cinstance_vtable_head +
                                 IC_VTABLE_OFF);
}

/* ── raw syscalls (no libc in a freestanding armv7 image) ───────────────── */
static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}
static void syswrite(const char *s, uint32_t n)
{
    sys3(4, 1, (long)(uintptr_t)s, n);
}
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

uintptr_t __stack_chk_guard = 0xc2331111u;
void __stack_chk_fail(void) { quit(3); }

void *memset(void *d, int c, unsigned int n)
{
    unsigned char *a = d;
    while (n--)
        *a++ = (unsigned char)c;
    return d;
}

/* The ARM EABI front-end may lower a zeroing loop to these, and a freestanding
 * image has no libc to answer them.  Note the argument order: the aeabi
 * variants take the length before the fill byte. */
void __aeabi_memclr(void *d, size_t n) { memset(d, 0, (unsigned int)n); }
void __aeabi_memclr4(void *d, size_t n) { memset(d, 0, (unsigned int)n); }
void __aeabi_memclr8(void *d, size_t n) { memset(d, 0, (unsigned int)n); }
void __aeabi_memset(void *d, size_t n, int c) { memset(d, c, (unsigned int)n); }
void __aeabi_memset4(void *d, size_t n, int c) { memset(d, c, (unsigned int)n); }
void __aeabi_memset8(void *d, size_t n, int c) { memset(d, c, (unsigned int)n); }
void __aeabi_memcpy(void *d, const void *s, size_t n)
{
    unsigned char *a = d;
    const unsigned char *b = s;
    while (n--)
        *a++ = *b++;
}
void __aeabi_memcpy4(void *d, const void *s, size_t n) { __aeabi_memcpy(d, s, n); }
void __aeabi_memcpy8(void *d, const void *s, size_t n) { __aeabi_memcpy(d, s, n); }

/* ── buffered printing: the call log has to be re-ordered after RET, so all
 *    output goes through one of two sinks ────────────────────────────────── */
typedef struct {
    char *b;
    int   n;
    int   cap;
} sink;

static char rec_buf[8192];
static char log_buf[2048];
static sink S_REC = {rec_buf, 0, (int)sizeof(rec_buf)};
static sink S_LOG = {log_buf, 0, (int)sizeof(log_buf)};
static sink *cur = &S_REC;

static void wch(char c)
{
    if (cur->n < cur->cap - 1)
        cur->b[cur->n++] = c;
}
static void ws(const char *s)
{
    while (*s)
        wch(*s++);
}
static void pi(int32_t v)
{
    char b[12];
    int i = 12;
    uint32_t u;

    if (v < 0) {
        wch('-');
        u = (uint32_t)0 - (uint32_t)v;
    } else {
        u = (uint32_t)v;
    }
    do {
        b[--i] = (char)('0' + (u % 10u));
        u /= 10u;
    } while (u);
    while (i < 12)
        wch(b[i++]);
}
static void phex(uint32_t v, int digits)
{
    static const char hx[] = "0123456789abcdef";
    char b[8];
    for (int i = digits - 1; i >= 0; i--) {
        b[i] = hx[v & 0xfu];
        v >>= 4;
    }
    for (int i = 0; i < digits; i++)
        wch(b[i]);
}
/* One 8-char token per 32-bit word: no raw address ever leaves this file. */
static void ptok(uint32_t w)
{
    uintptr_t base = (uintptr_t)arena;
    if (w == 0) {
        ws("00000000");
    } else if (w >= base && w < base + IC_ARENA_SIZE) {
        wch('A');
        phex(w - (uint32_t)base, 7);
    } else if (w == g_vt()) {
        ws("S0000001");
    } else {
        phex(w, 8);
    }
}
static void sep(void) { wch(' '); }
static void nl(void) { wch('\n'); }
static void sink_flush(sink *s)
{
    if (s->n > 0) {
        syswrite(s->b, (uint32_t)s->n);
        s->n = 0;
    }
}

/* ── evidence windows (mirrored by the harness) ─────────────────────────── */
typedef struct {
    uint32_t off;
    uint32_t len;
} window;
static const window WINDOWS[] = {
    {IC_INST, IC_INST_SIZE},        /* the whole CInstance                      */
    {IC_OBJ1, 0x100},               /* OBJ1, OBJ2, OBJ3                         */
    {IC_TABLE, 0x40},               /* table struct + the old slot array        */
    {IC_HEAP, 0x100},               /* the bump heap: grown table + guard word  */
};
#define NWINDOW ((int)(sizeof(WINDOWS) / sizeof(WINDOWS[0])))

static void dump_mem(void)
{
    ws("MEM");
    sep();
    for (int wi = 0; wi < NWINDOW; wi++) {
        for (uint32_t o = 0; o < WINDOWS[wi].len; o += 4) {
            const uint8_t *p = arena + WINDOWS[wi].off + o;
            uint32_t w = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                         ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
            ptok(w);
        }
    }
    nl();
}

/* ── stubs: identical on both arms ─────────────────────────────────────── */
static int probe_rm_scribble;
static int probe_ai_repoint;
static int base_gate;
static int ncalls;
static int gb_answer[IC_BPROPS_MAX];

#define LOG_BEGIN()      sink *save__ = cur; cur = &S_LOG
#define LOG_END()        cur = save__
#define LOG_TAG(t)       do { if (ncalls++) nl(); ws(t); } while (0)

void CObjectGM_RemoveInstance(struct ic_objectgm *obj, struct ic_instance *inst)
{
    LOG_BEGIN();
    LOG_TAG("RM");
    sep();
    ptok((uint32_t)(uintptr_t)obj);
    sep();
    ptok((uint32_t)(uintptr_t)inst);
    LOG_END();
    if (probe_rm_scribble)
        ic_st_i32(inst, 0x7c, 0xbeef);
}

void CObjectGM_AddInstance(struct ic_objectgm *obj, struct ic_instance *inst)
{
    LOG_BEGIN();
    LOG_TAG("AI");
    sep();
    ptok((uint32_t)(uintptr_t)obj);
    sep();
    ptok((uint32_t)(uintptr_t)inst);
    LOG_END();
    if (probe_ai_repoint)
        ic_st_ptr(inst, 0x80, arena + IC_OBJ3);
}

void CInstance_SetSpriteIndex(struct ic_instance *self, int32_t sprite)
{
    LOG_BEGIN();
    LOG_TAG("SI");
    sep();
    pi(sprite);
    LOG_END();
    ic_st_i32(self, 0x8c, sprite);
}

void CollisionMarkDirty(struct ic_instance *self)
{
    LOG_BEGIN();
    LOG_TAG("CM");
    sep();
    ptok((uint32_t)(uintptr_t)self);
    LOG_END();
}

void YYObjectBase_ctor(struct ic_instance *self, int32_t arg1, int32_t arg2)
{
    LOG_BEGIN();
    LOG_TAG("YB");
    sep();
    pi(arg1);
    sep();
    pi(arg2);
    LOG_END();
    /* The write set documented in cards/CInstance_ctor.c.  This is a fixture
     * assumption, not a recovered body: the ctor overwrites +0x00, +0x44 and
     * +0x48, so only the leftovers (+0x04, +0x18..+0x30, +0x34/+0x3c, +0x58,
     * +0x60) are observable.  +0x10/+0x14 are written only when the case's
     * base-gate bit is set, which is what makes the ctor's final clear of both
     * words observable instead of tautological. */
    ic_st_u32(self, 0x00, 0x10000000u);
    ic_st_i32(self, 0x04, 0);
    ic_st_i32(self, 0x18, 0);
    ic_st_i32(self, 0x1c, 0);
    ic_st_i32(self, 0x20, 0);
    ic_st_i32(self, 0x24, arg1);
    ic_st_i32(self, 0x28, 1);
    ic_st_i32(self, 0x2c, arg1);
    ic_st_i32(self, 0x30, 0);
    ic_st_ptr(self, 0x34, arena + IC_GT1);
    ic_st_i32(self, 0x38, 0);
    ic_st_ptr(self, 0x3c, arena + IC_GT1);
    ic_st_i32(self, 0x44, -1);
    ic_st_i32(self, 0x48, 0);
    ic_st_i32(self, 0x4c, 0);
    ic_st_i32(self, 0x58, arg2);
    ic_st_i32(self, 0x60, 0);
    if (base_gate) {
        ic_st_ptr(self, 0x10, arena + IC_GT2);
        ic_st_ptr(self, 0x14, arena + IC_GT2 + 4);
    }
}

int isGlobalBuiltinVar(const char *name)
{
    int r = 0;

    for (int i = 0; i < IC_BPROPS_MAX; i++) {
        const char *n = g_builtin_table[i].name;
        int same;

        if (n == 0 || name == 0)
            continue;
        same = 1;
        for (int k = 0; n[k] || name[k]; k++) {
            if (n[k] != name[k]) {
                same = 0;
                break;
            }
        }
        if (same) {
            r = gb_answer[i];
            break;
        }
    }
    LOG_BEGIN();
    LOG_TAG("GB");
    sep();
    ws(name == 0 ? "-(null)" : name);
    sep();
    pi(r);
    LOG_END();
    return r;
}

void *JS_SetupBuiltinProperty(void *getter, void *setter)
{
    LOG_BEGIN();
    LOG_TAG("JS");
    sep();
    ptok((uint32_t)(uintptr_t)getter);
    sep();
    ptok((uint32_t)(uintptr_t)setter);
    LOG_END();
    return arena + IC_PS;
}

void YYObjectBase_Add(struct ic_instance *self, const char *name, void *psv,
                      int32_t flag)
{
    LOG_BEGIN();
    LOG_TAG("BA");
    sep();
    ws(name == 0 ? "-(null)" : name);
    sep();
    ptok((uint32_t)(uintptr_t)psv);
    sep();
    pi(flag);
    sep();
    ptok((uint32_t)(uintptr_t)self);
    LOG_END();
}

/* The body branches to the memset PLT entry; a freestanding image has no libc,
 * so this is the stub of that import.  It records, then fills for real - the
 * zeroed tail is part of the evidence window. */
void *memset_plt(void *d, int c, unsigned int n)
{
    LOG_BEGIN();
    LOG_TAG("MS");
    sep();
    ptok((uint32_t)(uintptr_t)d);
    sep();
    pi(c);
    sep();
    pi((int32_t)n);
    LOG_END();
    return memset(d, c, n);
}

/* Bump allocator: same base, same fill byte, same guard as the arm-A model.
 * FILL is invisible in a correct run by construction (the body zeroes the
 * whole tail it asks for); it becomes visible exactly when a translation
 * mis-sizes the memset or the copy. */
static uint32_t heap_bump;

void *YYRealloc(void *p, int32_t bytes)
{
    uint32_t n = (uint32_t)bytes;
    uint32_t size = (n + 15u) & ~15u;
    uint8_t *blk = arena + IC_HEAP + heap_bump;

    LOG_BEGIN();
    LOG_TAG("RA");
    sep();
    ptok((uint32_t)(uintptr_t)p);
    sep();
    pi(bytes);
    LOG_END();
    memset(blk, IC_HEAP_FILL, size);
    if (p != 0 && n != 0) {
        const uint8_t *src = (const uint8_t *)p;
        uint32_t k = n < size ? n : size;
        for (uint32_t i = 0; i < k; i++)
            blk[i] = src[i];
    }
    ic_st_u32(blk + size, 0, IC_HEAP_GUARD);
    heap_bump += size + 16u;
    return blk;
}

/* ── staging ───────────────────────────────────────────────────────────── */
static void stage_object(uint32_t off, uint32_t flags, int32_t sprite,
                         int32_t depth, int32_t mask)
{
    ic_st_u32(arena + off, 0x00, flags);
    ic_st_i32(arena + off, 0x04, sprite);
    ic_st_i32(arena + off, 0x08, depth);
    ic_st_i32(arena + off, 0x10, mask);
    ic_st_u32(arena + off, 0x20, 0);
    ic_st_u32(arena + off, 0x24, 0x5a5a5a5au);
}

static void stage_hash(int scenario, int32_t objindex)
{
    ic_hash *t = (ic_hash *)(void *)(arena + IC_HASH);
    ic_hash_node *nd = (ic_hash_node *)(void *)(arena + IC_NODES);
    uint32_t idx = (uint32_t)objindex & IC_HASH_MASK;

    t->buckets = (ic_bucket *)(void *)(arena + IC_BUCKETS);
    t->mask = IC_HASH_MASK;

    for (uint32_t i = 0; i < IC_NBUCKET * IC_BUCKET_STRIDE; i++)
        arena[IC_BUCKETS + i] = 0;
    for (int i = 0; i < IC_NNODE; i++) {
        nd[i].unused0 = 0x11110000u + (uint32_t)i;
        nd[i].next = 0;
        nd[i].key = 0x7f7f0000 + i;
        nd[i].value = 0;
    }

    switch (scenario) {
    case 1:
        ic_st_ptr(arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].key = objindex;
        nd[0].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    case 2:
        ic_st_ptr(arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].next = &nd[1];
        nd[0].key = objindex ^ 0x11110000;
        nd[1].key = objindex;
        nd[1].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    case 3:
        ic_st_ptr(arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].next = &nd[1];
        nd[0].key = objindex ^ 1;
        nd[1].key = objindex ^ 2;
        nd[1].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    case 4:
        ic_st_ptr(arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].key = objindex;
        nd[0].value = 0;
        break;
    case 5:
        ic_st_ptr(arena + IC_BUCKETS + 7u * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].key = -1;
        nd[0].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    case 6:
        ic_st_ptr(arena + IC_BUCKETS, 0, arena + IC_NODES);
        nd[0].key = 0;
        nd[0].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    case 7:
        ic_st_ptr(arena + IC_BUCKETS + idx * IC_BUCKET_STRIDE, 0,
                  arena + IC_NODES);
        nd[0].next = &nd[1];
        nd[0].key = objindex;
        nd[0].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ2);
        nd[1].key = objindex;
        nd[1].value = (struct ic_objectgm *)(void *)(arena + IC_OBJ1);
        break;
    default:
        break;
    }
}

static void stage_table(int scenario)
{
    ic_instance_table *t = &g_instance_table;
    uint8_t *slots = arena + IC_TBLARR;
    uint32_t dummy = (uint32_t)(uintptr_t)(arena + IC_OBJ2);

    t->base = slots;
    t->next_free = 0;
    for (int i = 0; i < IC_TBLCAP_MAX; i++)
        ic_st_u32(slots, (unsigned)(i * 4), 0);

    switch (scenario) {
    case 0:
        t->cap = 0;
        t->count = 0;
        break;
    case 1:
        t->cap = 4;
        t->count = 1;
        t->next_free = 1;
        ic_st_u32(slots, 0, dummy);
        break;
    case 2:
        t->cap = 4;
        t->count = 2;
        t->next_free = 2;
        ic_st_u32(slots, 4, dummy);
        ic_st_u32(slots, 8, dummy);
        break;
    case 3:
        t->cap = 4;
        t->count = 0;
        t->next_free = 4;         /* >= cap: the clamp at 0x19979c must fire */
        break;
    case 4:
        t->cap = 4;
        t->count = 4;             /* full: grow 4 -> 6, all four slots busy */
        t->next_free = 0;
        ic_st_u32(slots, 0, dummy);
        ic_st_u32(slots, 4, dummy);
        ic_st_u32(slots, 8, dummy);
        ic_st_u32(slots, 12, dummy);
        break;
    case 5:
        t->cap = 2;
        t->count = 2;             /* full: grow 2 -> 3 */
        t->next_free = 1;
        ic_st_u32(slots, 0, dummy);
        ic_st_u32(slots, 4, dummy);
        break;
    default:
        t->cap = 4;
        t->count = 0;
        t->next_free = 0;
        break;
    }
}

static void stage_builtins(int scenario)
{
    static const char *names[IC_BPROPS_MAX] = {"hp", "mp", "score", "speed"};

    g_builtin_gate = 0;
    g_builtin_numb = 0;
    for (int i = 0; i < IC_BPROPS_MAX; i++) {
        uint8_t *e = (uint8_t *)(void *)&g_builtin_table[i];
        uint8_t *nm = arena + IC_NAMES + 8u * (uint32_t)i;

        for (int k = 0; k < 8; k++)
            nm[k] = 0;
        for (int k = 0; names[i][k]; k++)
            nm[k] = (uint8_t)names[i][k];
        ic_st_ptr(e, 0x00, nm);
        ic_st_u32(e, 0x04, 0xa0000000u + (uint32_t)i);
        ic_st_u32(e, 0x08, 0xb0000000u + (uint32_t)i);
        ic_st_u32(e, 0x0c, 0xccccccccu);
        gb_answer[i] = 0;
    }

    if (scenario < 6)
        return;
    g_builtin_gate = 1;
    switch (scenario) {
    case 6:                       /* two entries, neither global */
        g_builtin_numb = 2;
        break;
    case 7:                       /* the first entry is a global builtin */
        g_builtin_numb = 2;
        gb_answer[0] = 1;
        break;
    case 8:                       /* both are global builtins */
        g_builtin_numb = 2;
        gb_answer[0] = 1;
        gb_answer[1] = 1;
        break;
    case 9:                       /* gate on, nothing registered yet */
        g_builtin_numb = 0;
        break;
    default:                      /* builtins staged but the gate is off */
        g_builtin_gate = 0;
        g_builtin_numb = 2;
        break;
    }
}

static void stage_case(const int32_t *raw)
{
    const int32_t *p = raw + 1;      /* p[0] = p0 ... p[7] = p7 */
    int32_t fn = raw[0];

    for (uint32_t i = 0; i < IC_ARENA_SIZE; i++)
        arena[i] = (uint8_t)IC_MARK;
    ncalls = 0;
    heap_bump = 0;
    probe_rm_scribble = 0;
    probe_ai_repoint = 0;
    base_gate = 0;
    g_base_ctor_arg1 = 0x00012345;
    g_create_counter = 0x5566778899aabbccull;
    g_object_hash = (ic_hash *)(void *)(arena + IC_HASH);

    if (fn == 1) {
        stage_object(IC_OBJ1, (uint32_t)p[4], p[5], p[6], p[7]);
    } else {
        stage_object(IC_OBJ1, 0x7u, 11, -12345, 0x5);
    }
    stage_object(IC_OBJ2, 0x0du, 21, -777, 0x33);
    stage_object(IC_OBJ3, 0x02u, 31, 9, 0x44);

    if (fn == 1) {
        for (uint32_t i = 0; i < IC_INST_SIZE; i++)
            arena[IC_INST + i] = 0xa5;
        /* 0xa5 everywhere EXCEPT the object pointer: a garbage +0x80 would make
         * every case take the RemoveInstance branch, which is not what the
         * no-old-object cases are for. */
        ic_st_i32(arena + IC_INST, 0x80, 0);
        stage_hash(p[3], p[0]);
        if (p[2] == 1 || p[2] == 2 || p[2] == 4)
            ic_st_ptr(arena + IC_INST, 0x80, arena + IC_OBJ2);
        probe_rm_scribble = (p[2] == 2 || p[2] == 4);
        probe_ai_repoint = (p[2] == 3 || p[2] == 4);
        stage_table(1);
        stage_builtins(0);
    } else {
        uint8_t *s = arena + IC_INST;

        if (p[0] == 0) {
            for (uint32_t i = 0; i < IC_INST_SIZE; i++)
                s[i] = 0;
        } else if (p[0] == 1) {
            for (uint32_t i = 0; i < IC_INST_SIZE; i++)
                s[i] = 0xa5;
        } else {
            for (uint32_t i = 0; i < IC_INST_SIZE; i++)
                s[i] = 0xa5;
            ic_st_ptr(s, 0x80, arena + IC_OBJ3);
            ic_st_i32(s, 0x44, 3);
            ic_st_i32(s, 0x10, 0x0000c0de);
            ic_st_i32(s, 0x14, 0x0000c0df);
            ic_st_ptr(s, 0x18c, 0);
            ic_st_ptr(s, 0x190, 0);
            ic_st_ptr(s, 0x198, 0);
            ic_st_i32(s, 0x64, 1);
            ic_st_i32(s, 0x7c, 0x77);
            ic_st_i32(s, 0x8c, 0x99);
            ic_st_i32(s, 0xac, 0x66);
            ic_st_i32(s, 0x180, 0x55);
        }
        stage_hash((p[7] & 2) ? 1 : 0, p[4]);
        stage_table(p[6]);
        stage_builtins(p[6]);
        base_gate = p[7] & 1;
        if (p[7] & 4)
            g_base_ctor_arg1 = (int32_t)0x80000000;
    }
}

static void ext_table(void)
{
    ic_instance_table *t = &g_instance_table;

    ws("EXT");
    sep();
    ws("tbl_base");
    sep();
    ptok((uint32_t)(uintptr_t)t->base);
    nl();
    ws("EXT");
    sep();
    ws("tbl_cap");
    sep();
    pi(t->cap);
    nl();
    ws("EXT");
    sep();
    ws("tbl_count");
    sep();
    pi(t->count);
    nl();
    ws("EXT");
    sep();
    ws("tbl_nextfree");
    sep();
    pi(t->next_free);
    nl();
    ws("EXT");
    sep();
    ws("heap_off");
    sep();
    pi((int32_t)heap_bump);
    nl();
}

static void run_case(const int32_t *raw)
{
    const int32_t *p = raw + 1;      /* p[0] = p0 ... p[7] = p7 */

    stage_case(raw);

    ws("CASE");
    for (int i = 0; i < 9; i++) {
        sep();
        pi(raw[i]);
    }
    nl();

    if (raw[0] == 1) {
        CInstance_SetObjectIndex(
            (struct ic_instance *)(void *)(arena + IC_INST), p[0], p[1]);
        ws("RET");
        sep();
        ws("void");
        nl();
    } else {
        struct ic_instance *r =
            CInstance_ctor((struct ic_instance *)(void *)(arena + IC_INST),
                           (uint32_t)p[1], (uint32_t)p[2], p[3], p[4], p[5]);
        ws("RET");
        sep();
        ptok((uint32_t)(uintptr_t)r);
        nl();
    }
    sink_flush(&S_REC);
    sink_flush(&S_LOG);
    if (ncalls)
        nl();
    ws("CALLS");
    sep();
    pi(ncalls);
    nl();
    ext_table();
    dump_mem();
    sink_flush(&S_REC);
}

int main(void)
{
    static char in[65536];
    long n = read_all(in, (long)sizeof(in));
    int32_t p[9];
    int idx = 0;
    int cases = 0;
    long i = 0;

    while (i < n) {
        char c = in[i];
        int neg = 0;
        uint32_t v = 0;

        if (c == '-') {
            neg = 1;
            i++;
            if (i >= n)
                break;
            c = in[i];
        }
        if (c < '0' || c > '9') {
            i++;
            continue;
        }
        while (i < n && in[i] >= '0' && in[i] <= '9') {
            v = v * 10u + (uint32_t)(in[i] - '0');
            i++;
        }
        p[idx++] = neg ? (int32_t)((uint32_t)0 - v) : (int32_t)v;
        if (idx == 9) {
            run_case(p);
            idx = 0;
            cases++;
        }
    }
    quit(cases ? 0 : 2);
}
