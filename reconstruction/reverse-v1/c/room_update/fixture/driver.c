/*
 * driver.c — the C arm of the room_update differential
 * (F1 CRoom::UpdateActive, F2 UpdateActiveLists, F3 ProcessActivateDeactveLists).
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm: a pointer is
 * 4 bytes, CInstance is really 0x188 apart in the staged array, +0x178/+0x17c
 * really are prev/next, +0x184 really is the second word after +0x180, and the
 * three deferred-list cells really are 12 B with the count at +8.  A 64-bit
 * host build moves every one of those and quietly stops testing the offsets the
 * bodies use.
 *
 * It is a *fixture*, not a reconstruction: it stages the same object graph the
 * original-bytes arm stages, answers every unrecovered callee with the same
 * stub as that arm, calls the entry once per case and prints the record stream
 * harness/room_update_diff.py reproduces from the original bytes.
 *
 * Case line (stdin):
 *   fn a b c nw
 *   <reg> <idx> <off> <kind> <a> <b>      x nw
 *
 *   fn=1  CRoom_UpdateActive(r0 = &R)                  a/b/c unused
 *   fn=2  UpdateActiveLists(r0 = SEED)                 room from the S cell
 *   fn=3  ProcessActivateDeactveLists(r0 = SEED)       room from the S cell
 *   c != 0 is reserved; indices are the region's own array index
 *   kind 0 stores <a>; kind 1 stores base(<a>) + b*stride(<a>)
 *
 * Record stream (stdout), pointers RAW and normalised by the harness:
 *   BASE <reg> <addr>           this arm's own region addresses
 *   CASE <fn> <a> <b> <c> <nw>
 *   RAW <reg> <hexbytes>        every staged region, in the harness's order
 *   ALLOC <i> <addr> <size>     every RoomUpdate_Alloc in call order
 *   RAWA <i> <hexbytes>         the block's bytes
 *   C <NAME> <args...>          the ordered callee log
 *   RET <hex32>                 the word the entry returned
 *   END                          (once, at the end of the stream)
 *
 * The heap model is shared with the original-bytes arm, cell for cell:
 *   * a bump arena, 16-byte alignment, reset per case, every block prefilled
 *     with 0xA5 over the WHOLE aligned block.  Neither of the two bodies under
 *     judgement allocates; the arena is exercised only by the handler stubs'
 *     GROW model (see below), so that when a container does grow it grows
 *     through the same allocator and the same fill on both arms.
 *
 * Stubs, and what they are not:
 *   CObjectGM::AddInstance / RemoveInstance   log (this, instance) and return a
 *       distinctive constant.  The two arguments are the real observable --
 *       `this` is READ OUT OF inst+0x80 by the body, and the instance is what
 *       r1 happens to hold -- so the log proves the register plumbing, not the
 *       callee's semantics.
 *   ChangeInstanceTypes / ChangeInstanceDepths   log their list, run the GROW
 *       model, honour the AUX_FLIP knob and clear the count.  The count clear
 *       and the knob are MODEL, not recovered behaviour: the real bodies do
 *       clear +8 (their cards' cross-evidence shows it), the knob does not
 *       exist at all -- it stands in for "some handler may switch profiling off
 *       mid-frame", which is the only way the exit's re-read becomes
 *       observable.
 *   CProfiler::Push / Pop   log (this, a, b) / (this) and return constants.
 *   RoomUpdate_Alloc   the bump arena above.
 * Nothing here proves a callee; see the harness scope block.
 */
#include <stdint.h>
#include <stddef.h>

#include "room_update.h"

#define FILL_BYTE 0xA5u
#define ARENA_SIZE 0x4000u
#define NI 8                     /* instances */
#define NO 8                     /* CObjectGM cells, one per instance */
#define NA 8                     /* entries in each deferred-list array */
#define IST 0x188u               /* instance stride */
#define OST 0x10u                /* CObjectGM cell stride */
#define AST 4u                   /* array entry stride */
#define SEED 0x5a5a5a5au         /* r0 for the two argument-less entries */

#define MAGIC_ADD 0x0B1EC7A1u
#define MAGIC_REM 0x0B1EC7B2u
#define MAGIC_TYP 0x0C7A0001u
#define MAGIC_DEP 0x0CDE0002u
#define MAGIC_PSH 0x0C9F0003u
#define MAGIC_POP 0x0C9F0004u

/* ── the six .bss cells the bodies reach through the .got ───────────────── */
u8 g_list_activate[12] __attribute__((aligned(8)));   /* 0x542a4c */
u8 g_list_depth[12] __attribute__((aligned(8)));      /* 0x542a58 */
u8 g_list_type[12] __attribute__((aligned(8)));       /* 0x542a64 */
u8 g_profile_switch;                                  /* 0x757e7c */
u8 g_profiler[4] __attribute__((aligned(8)));         /* 0x757e80 */
u32 g_run_room;                                       /* 0x54298c */

/* ── regions (the staged object graph) ──────────────────────────────────── */
static u32 R_reg[0x120 / 4] __attribute__((aligned(8)));
static u32 I_reg[NI * IST / 4] __attribute__((aligned(8)));
static u32 O_reg[NO * OST / 4] __attribute__((aligned(8)));
static u32 A_reg[NA] __attribute__((aligned(8)));   /* list A items */
static u32 T_reg[NA] __attribute__((aligned(8)));   /* list B items */
static u32 D_reg[NA] __attribute__((aligned(8)));   /* list C items */

struct region {
    char id;
    u8 *base;
    u32 count;
    u32 stride;
};

static const struct region REGIONS[] = {
    {'R', (u8 *)R_reg, 1, 0x120},
    {'I', (u8 *)I_reg, NI, IST},
    {'O', (u8 *)O_reg, NO, OST},
    {'A', (u8 *)A_reg, NA, AST},
    {'T', (u8 *)T_reg, NA, AST},
    {'D', (u8 *)D_reg, NA, AST},
    {'Q', (u8 *)g_list_activate, 1, 12},
    {'C', (u8 *)g_list_depth, 1, 12},
    {'B', (u8 *)g_list_type, 1, 12},
    {'W', (u8 *)&g_profile_switch, 1, 4},
    {'F', (u8 *)g_profiler, 1, 4},
    {'S', (u8 *)&g_run_room, 1, 4},
};
#define NREG ((int)(sizeof(REGIONS) / sizeof(REGIONS[0])))

/* ── freestanding IO ────────────────────────────────────────────────────── */
static long sys3(long nr, long a, long b, long c)
{
    register long r7 __asm__("r7") = nr;
    register long r0 __asm__("r0") = a;
    register long r1 __asm__("r1") = b;
    register long r2 __asm__("r2") = c;
    __asm__ volatile("svc #0" : "+r"(r0) : "r"(r7), "r"(r1), "r"(r2) : "memory");
    return r0;
}

/* -fstack-protector-strong is kept (both arms are built with the same flags as
 * the rest of this line); a freestanding image has to define the two symbols
 * the protector references.  The guard is irrelevant to the bodies under
 * judgement -- it only has to be a stable non-zero word. */
u32 __stack_chk_guard = 0x5a5a5a5au;

static char obuf[1 << 16];
static u32 olen;

static void flush(void)
{
    u32 done = 0;
    while (done < olen) {
        long n = sys3(4, 1, (long)(uintptr_t)(obuf + done), olen - done);
        if (n <= 0)
            break;
        done += (u32)n;
    }
    olen = 0;
}

static void putc_(char c)
{
    if (olen == sizeof(obuf))
        flush();
    obuf[olen++] = c;
}

static void pstr(const char *s)
{
    while (*s)
        putc_(*s++);
}

void __stack_chk_fail(void)
{
    pstr("STACK SMASHED\n");
    flush();
    sys3(1, 6, 0, 0);
    for (;;) { }
}

static void pdec(u32 v)
{
    char t[12];
    int n = 0;
    if (v == 0) {
        putc_('0');
        return;
    }
    while (v) {
        t[n++] = (char)('0' + (v % 10));
        v /= 10;
    }
    while (n)
        putc_(t[--n]);
}

static void phex(u32 v)
{
    static const char hx[] = "0123456789abcdef";
    int k;
    for (k = 7; k >= 0; k--)
        putc_(hx[(v >> (k * 4)) & 0xf]);
}

static void pbytes(const u8 *p, u32 n)
{
    static const char hx[] = "0123456789abcdef";
    u32 i;
    for (i = 0; i < n; i++) {
        putc_(hx[p[i] >> 4]);
        putc_(hx[p[i] & 0xf]);
    }
}

/* the call log of one case, flushed after RAW/ALLOC so the record order is
 * independent of when the body called the stub */
static char cbuf[1 << 14];
static u32 clen;

static void cput(char c)
{
    if (clen < sizeof(cbuf))
        cbuf[clen++] = c;
}

static void cpstr(const char *s)
{
    while (*s)
        cput(*s++);
}

static void cphex(u32 v)
{
    static const char hx[] = "0123456789abcdef";
    int k;
    for (k = 7; k >= 0; k--)
        cput(hx[(v >> (k * 4)) & 0xf]);
}

static void cbegin(const char *name)
{
    if (clen)
        cput('\n');
    cput('C');
    cput(' ');
    cpstr(name);
}

/* ── the bump arena ─────────────────────────────────────────────────────── */
static u8 arena[ARENA_SIZE] __attribute__((aligned(16)));
static u32 arena_used;
static u32 alloc_n;
static u32 alloc_addr[64];
static u32 alloc_size[64];

static u32 arena_alloc(u32 size)
{
    u32 al = (size + 15u) & ~15u;
    u32 addr = (u32)(uintptr_t)(arena + arena_used);
    u32 i;
    if (arena_used + al > ARENA_SIZE) {
        pstr("ARENA OVERFLOW\n");
        flush();
        sys3(1, 3, 0, 0);
    }
    for (i = 0; i < al; i++)
        arena[arena_used + i] = (u8)FILL_BYTE;
    arena_used += al;
    if (alloc_n < 64) {
        alloc_addr[alloc_n] = addr;
        alloc_size[alloc_n] = al;
    }
    alloc_n++;
    return addr;
}

/* ── the stubs ──────────────────────────────────────────────────────────── */
/* The allocator itself writes no log line: the block list is printed as the
 * ALLOC/RAWA record pair, and the caller (the GROW model) names the block in its
 * own record.  The original-bytes arm records the block in exactly the same two
 * places, which is what makes the two alloc logs comparable. */
u32 RoomUpdate_Alloc(u32 size)
{
    return arena_alloc(size);
}

u32 CObjectGM_AddInstance(void *gm, void *inst)
{
    cbegin("CGAI");
    cput(' ');
    cphex((u32)(uintptr_t)gm);
    cput(' ');
    cphex((u32)(uintptr_t)inst);
    return MAGIC_ADD;
}

u32 CObjectGM_RemoveInstance(void *gm, void *inst)
{
    cbegin("CGRI");
    cput(' ');
    cphex((u32)(uintptr_t)gm);
    cput(' ');
    cphex((u32)(uintptr_t)inst);
    return MAGIC_REM;
}

u32 CProfiler_Push(void *self, int a, int b)
{
    cbegin("CPUSH");
    cput(' ');
    cphex((u32)(uintptr_t)self);
    cput(' ');
    cphex((u32)a);
    cput(' ');
    cphex((u32)b);
    return MAGIC_PSH;
}

u32 CProfiler_Pop(void *self)
{
    cbegin("CPOP");
    cput(' ');
    cphex((u32)(uintptr_t)self);
    return MAGIC_POP;
}

/* The AUX knob: a handler that switches profiling off mid-frame.  +0x4 is a
 * field neither body nor F3 reads, so staging 0x5017 there is an input, not a
 * claim about the callee. */
#define AUX_FLIP 0x5017u
#define GROW_MAX 8

/* The GROW model, identical on both arms: if the queue holds 1..GROW_MAX
 * entries and its array pointer is non-NULL, copy that many pointers into a
 * bump-arena block.  The block's bytes (0xA5 outside the copied words) are
 * compared by the identity gate, which is what makes "same allocator, same
 * fill" a graded fact rather than a comment. */
static void grow_model(u8 *list)
{
    u32 items = rd32(list + LIST_ITEMS);
    u32 aux = rd32(list + LIST_AUX);
    u32 count = rd32(list + LIST_COUNT);
    u32 n = (count >= 1u && count <= (u32)GROW_MAX) ? count : 0u;
    u32 p = 0;
    u32 i;

    /* allocate FIRST, log once: the record has to be one line on both arms */
    if (n && items) {
        p = RoomUpdate_Alloc(n * 4u);
        for (i = 0; i < n; i++)
            wr32((u8 *)(uintptr_t)p + i * 4u, rd32((u8 *)(uintptr_t)items + i * 4u));
    }
    cbegin("GROW");
    cput(' ');
    cphex(items);
    cput(' ');
    cphex(count);
    cput(' ');
    cphex(n);
    cput(' ');
    cphex(p);
    if (aux == AUX_FLIP) {
        cbegin("SWOFF");
        wr8(&g_profile_switch, 0);
    }
}

u32 ChangeInstanceTypes(void)
{
    cbegin("CTYP");
    cput(' ');
    cphex((u32)(uintptr_t)g_list_type);
    grow_model(g_list_type);
    wr32(g_list_type + LIST_COUNT, 0);
    return MAGIC_TYP;
}

u32 ChangeInstanceDepths(void)
{
    cbegin("CDEP");
    cput(' ');
    cphex((u32)(uintptr_t)g_list_depth);
    grow_model(g_list_depth);
    wr32(g_list_depth + LIST_COUNT, 0);
    return MAGIC_DEP;
}

/* ── staging ────────────────────────────────────────────────────────────── */
static void stage_reset(void)
{
    int r;
    u32 i;
    for (r = 0; r < NREG; r++)
        for (i = 0; i < REGIONS[r].count * REGIONS[r].stride; i++)
            REGIONS[r].base[i] = 0;
    arena_used = 0;
    alloc_n = 0;
    clen = 0;
}

static const struct region *find_region(char id)
{
    int r;
    for (r = 0; r < NREG; r++)
        if (REGIONS[r].id == id)
            return &REGIONS[r];
    return 0;
}

static char *rd_all;

static u32 grab(void)
{
    u32 v = 0;
    while (*rd_all == ' ' || *rd_all == '\n' || *rd_all == '\r' ||
           *rd_all == '\t')
        rd_all++;
    while (*rd_all >= '0' && *rd_all <= '9') {
        v = v * 10u + (u32)(*rd_all - '0');
        rd_all++;
    }
    return v;
}

static void dump_region(const struct region *rg)
{
    pstr("RAW ");
    putc_(rg->id);
    putc_(' ');
    pbytes(rg->base, rg->count * rg->stride);
    putc_('\n');
}

int main(void)
{
    static char in[1 << 18];
    long total = 0;
    char *cur;
    int q;

    while (total < (long)sizeof(in)) {
        long n = sys3(3, 0, (long)(uintptr_t)(in + total),
                      (long)sizeof(in) - total);
        if (n <= 0)
            break;
        total += n;
    }
    in[total < (long)sizeof(in) ? total : (long)sizeof(in) - 1] = 0;
    cur = in;

    /* The harness needs this arm's own region addresses to normalise pointers:
     * the two arms never agree on raw addresses, only on what they point at. */
    for (q = 0; q < NREG; q++) {
        pstr("BASE ");
        putc_(REGIONS[q].id);
        putc_(' ');
        phex((u32)(uintptr_t)REGIONS[q].base);
        putc_('\n');
    }
    flush();

    for (;;) {
        u32 fn, a, b, c, nw, k, ret;
        void *room;
        struct region *rg;
        u32 j;

        rd_all = cur;
        while (*rd_all == ' ' || *rd_all == '\n' || *rd_all == '\r' ||
               *rd_all == '\t')
            rd_all++;
        if (!*rd_all)
            break;
        fn = grab();
        a = grab();
        b = grab();
        c = grab();
        nw = grab();
        cur = rd_all;

        stage_reset();
        for (k = 0; k < nw; k++) {
            rd_all = cur;
            while (*rd_all == ' ' || *rd_all == '\n' || *rd_all == '\r' ||
                   *rd_all == '\t')
                rd_all++;
            {
                char id = *rd_all;
                u32 idx, off, kind, va, vb;
                rd_all++;
                idx = grab();
                off = grab();
                kind = grab();
                va = grab();
                vb = grab();
                cur = rd_all;
                rg = (struct region *)find_region(id);
                if (!rg) {
                    pstr("BADREGION\n");
                    flush();
                    sys3(1, 4, 0, 0);
                }
                if (kind) {
                    /* `va` is the SOURCE REGION'S LETTER CODE (the field is read
                     * as an integer, so a region travels as its code). */
                    const struct region *src = find_region((char)va);
                    if (!src) {
                        pstr("BADSRC\n");
                        flush();
                        sys3(1, 7, 0, 0);
                    }
                    wr32(rg->base + idx * rg->stride + off,
                         (u32)(uintptr_t)src->base + vb * src->stride);
                } else {
                    wr32(rg->base + idx * rg->stride + off, va);
                }
            }
        }

        pstr("CASE ");
        pdec(fn);
        putc_(' ');
        pdec(a);
        putc_(' ');
        pdec(b);
        putc_(' ');
        pdec(c);
        putc_(' ');
        pdec(nw);
        putc_('\n');

        (void)c;
        room = (void *)(uintptr_t)R_reg;

        if (fn == 1)
            ret = CRoom_UpdateActive(room);
        else if (fn == 2)
            ret = UpdateActiveLists(SEED);
        else if (fn == 3)
            ret = ProcessActivateDeactveLists(SEED);
        else {
            pstr("BADFN\n");
            flush();
            sys3(1, 5, 0, 0);
            for (;;) { }
        }

        for (j = 0; j < (u32)NREG; j++)
            dump_region(&REGIONS[j]);
        for (j = 0; j < alloc_n && j < 64; j++) {
            pstr("ALLOC ");
            pdec(j);
            putc_(' ');
            phex(alloc_addr[j]);
            putc_(' ');
            pdec(alloc_size[j]);
            putc_('\n');
            pstr("RAWA ");
            pdec(j);
            putc_(' ');
            pbytes((const u8 *)(uintptr_t)alloc_addr[j], alloc_size[j]);
            putc_('\n');
        }
        flush();
        if (clen) {
            u32 w = 0;
            while (w < clen) {
                putc_(cbuf[w++]);
                if (olen == sizeof(obuf))
                    flush();
            }
            putc_('\n');
        }
        pstr("RET ");
        phex(ret);
        putc_('\n');
    }
    pstr("END\n");
    flush();
    /* no libc: returning from the entry point would `bx lr` into nothing */
    sys3(1, 0, 0, 0);
    for (;;) { }
}
