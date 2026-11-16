/*
 * driver.c — the C arm of the room_add differential (F1 CRoom::AddInstance,
 * F2 CLayerManager::AddInstance, F3 CLayerManager::AddInstanceToLayer).
 *
 * Built freestanding for armv7a-none-eabi and run under qemu-arm: a pointer is
 * 4 bytes, CInstance is really 0x188 apart in the staged array, the id-hash
 * node is 16 B with key@8, the 36 B element has its free-list links at +0x14 /
 * +0x18, and the table-3 bucket really is 12 B.  A 64-bit host build moves
 * every one of those and quietly stops testing the offsets the bodies use.
 *
 * It is a *fixture*, not a reconstruction: it stages the same object graph the
 * original-bytes arm stages, answers every unrecovered callee with the same
 * stub as that arm, calls the entry once per case and prints the record stream
 * harness/room_add_diff.py reproduces from the original bytes.
 *
 * Case line (stdin):
 *   fn a b c nw
 *   <reg> <idx> <off> <kind> <a> <b>      x nw
 *
 *   fn=1  CRoom_AddInstance(room, inst)              inst = a
 *   fn=2  CLayerManager_AddInstance(room, inst)      inst = a
 *   fn=3  CLayerManager_AddInstanceToLayer(room, l, i)  l = a, i = b
 *   c != 0 -> the room argument is NULL (gate cases)
 *   an index of 0x7f -> the object argument is NULL
 *   kind 0 stores <a>; kind 1 stores base(<a>) + b*stride(<a>)
 *
 * Record stream (stdout), pointers RAW and normalised by the harness:
 *   CASE <fn> <a> <b> <c> <nw>
 *   RAW <reg> <hexbytes>        every staged region, in the harness's order
 *   ALLOC <i> <addr> <size>     every MemoryManager::Alloc in call order
 *   RAWA <i> <hexbytes>         the block's bytes
 *   C <NAME> <args...>          the ordered callee log
 *   RET <hex32>                 the word the entry returned
 *   END                          (once, at the end of the stream)
 *
 * The heap model is shared with the original-bytes arm, cell for cell:
 *   * a bump arena, 16-byte alignment, reset per case, blocks prefilled with
 *     0xA5.  Both arms use 0xA5 and both prefill the WHOLE aligned block, so
 *     bytes the bodies never write compare equal instead of depending on the
 *     allocator's history.  (An earlier Level A batch lost a day to two arms
 *     filling with different bytes.)
 *
 * Stubs, and what they are not:
 *   CHashMapCalculateHash  returns key * 2654435761u -- a documented model, not
 *                          the real function.  It only has to be the SAME on
 *                          both arms; the cases stage table entries consistent
 *                          with it to reach every probe state.
 *   GetLayerFromID / GetLayerWithDepth / AddDynamicLayer  return whatever the
 *   case wrote into the answer cells X+0 / X+4 / X+8, and log their arguments.
 *                          The arguments are the real observable (the id, the
 *                          truncated depth, the bool); the return is staged.
 *   AddElementToLayer / UpdateInstanceActivation / CollisionInsert  log their
 *                          arguments and return a distinctive constant, which is
 *                          how the three tail-call pass-throughs become
 *                          observable on both arms.
 *   the error host       is a fixture object whose vtable+0xc is err_call().
 *   MemoryManager::Alloc is the bump arena above.
 * Nothing here proves a callee; see the harness scope block.
 */
#include <stdint.h>
#include <stddef.h>

#include "room_add.h"

#define FILL_BYTE 0xA5u
#define ARENA_SIZE 0x4000u
#define NI 6                     /* instances */
#define NL 4                     /* layers */
#define NB 16                    /* buckets in both tables (mask 0xf) */
#define NE 8                     /* pre-staged pool elements */
#define IST 0x188u               /* instance stride */
#define LST 0x28u                /* layer stride */

/* ── the five .bss cells the bodies reach through the .got ───────────────── */
u32 g_id_table[3];               /* 0x536f28 */
u32 g_zeus_byte;                 /* 0x5428e8 */
u32 g_element_pool[5];           /* 0x542678 */
u32 g_element_uid;               /* 0x5425f0 */
u32 g_error_host_cell;           /* 0x3eb70c: holds the host object* */

/* ── regions (the staged object graph) ──────────────────────────────────── */
static u32 R_reg[0x130 / 4] __attribute__((aligned(8)));
static u32 I_reg[NI * IST / 4] __attribute__((aligned(8)));
static u32 L_reg[NL * LST / 4] __attribute__((aligned(8)));
static u32 T_reg[NB * 12 / 4] __attribute__((aligned(8)));
static u32 K_reg[NB * 8 / 4] __attribute__((aligned(8)));
static u32 E_reg[NE * ELEM_SIZE / 4] __attribute__((aligned(8)));
static u32 X_reg[3] __attribute__((aligned(8)));

static u32 g_err_host[1];                 /* the fixture host object    */
static u32 g_err_vtable[4] __attribute__((aligned(8)));

struct region {
    char id;
    u8 *base;
    u32 count;
    u32 stride;
};

static const struct region REGIONS[] = {
    {'R', (u8 *)R_reg, 1, 0x130},
    {'I', (u8 *)I_reg, NI, IST},
    {'L', (u8 *)L_reg, NL, LST},
    {'T', (u8 *)T_reg, NB, 12},
    {'K', (u8 *)K_reg, NB, 8},
    {'E', (u8 *)E_reg, NE, ELEM_SIZE},
    {'H', (u8 *)g_id_table, 1, 0xc},
    {'Z', (u8 *)&g_zeus_byte, 1, 4},
    {'G', (u8 *)&g_element_uid, 1, 4},
    {'P', (u8 *)g_element_pool, 1, 0x14},
    {'X', (u8 *)X_reg, 1, 0xc},
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

/* -fstack-protector-strong is kept (the harness builds both arms with the same
 * flags as the rest of this line); a freestanding image has to define the two
 * symbols the protector references.  The guard value is irrelevant to the
 * bodies under judgement -- it only has to be a stable non-zero word. */
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

static void cpdec(u32 v)
{
    char t[12];
    int n = 0;
    if (!v) {
        cput('0');
        return;
    }
    while (v) {
        t[n++] = (char)('0' + (v % 10));
        v /= 10;
    }
    while (n)
        cput(t[--n]);
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

/* ── stubs ──────────────────────────────────────────────────────────────── */
u32 MemoryManager_Alloc(u32 size, const char *file, int line, int flag)
{
    u32 addr = arena_alloc(size);
    const char *p = file;
    cbegin("ALLOC");
    cput(' ');
    cpdec(alloc_n - 1);
    cput(' ');
    cpdec(size);
    cput(' ');
    cpdec((u32)line);
    cput(' ');
    cpdec((u32)flag);
    cput(' ');
    /* the path has no spaces (so it survives the line-oriented stream) and it
     * DOES contain underscores: it is emitted verbatim, unlike the error
     * message below. */
    for (; *p; p++)
        cput(*p);
    return addr;
}

u32 CHashMapCalculateHash(int key)
{
    cbegin("HASH");
    cput(' ');
    cphex((u32)key);
    return (u32)key * 2654435761u;
}

u32 CLayerManager_GetLayerFromID(void *room, int id)
{
    cbegin("GLID");
    cput(' ');
    cphex((u32)(uintptr_t)room);
    cput(' ');
    cphex((u32)id);
    return rd32(&X_reg[0]);
}

u32 CLayerManager_GetLayerWithDepth(void *room, int depth, int flag)
{
    cbegin("GLWD");
    cput(' ');
    cphex((u32)(uintptr_t)room);
    cput(' ');
    cphex((u32)depth);
    cput(' ');
    cpdec((u32)flag);
    return rd32(&X_reg[1]);
}

u32 CLayerManager_AddDynamicLayer(void *room, int depth)
{
    cbegin("ADDL");
    cput(' ');
    cphex((u32)(uintptr_t)room);
    cput(' ');
    cphex((u32)depth);
    return rd32(&X_reg[2]);
}

u32 CLayerManager_AddElementToLayer(void *room, void *layer, void *elem,
                                    int flag)
{
    cbegin("AEL");
    cput(' ');
    cphex((u32)(uintptr_t)room);
    cput(' ');
    cphex((u32)(uintptr_t)layer);
    cput(' ');
    cphex((u32)(uintptr_t)elem);
    cput(' ');
    cpdec((u32)flag);
    return 0xAE1AE1AEu;
}

u32 CLayerManager_UpdateInstanceActivation(void *room, void *inst)
{
    cbegin("UIA");
    cput(' ');
    cphex((u32)(uintptr_t)room);
    cput(' ');
    cphex((u32)(uintptr_t)inst);
    return 0x0A1A0A1Au;
}

u32 CollisionInsert(void *inst)
{
    cbegin("COLL");
    cput(' ');
    cphex((u32)(uintptr_t)inst);
    return 0xC0111DE5u;
}

static u32 err_call(void *host, const char *msg, int id)
{
    const char *p = msg;
    cbegin("ERR");
    cput(' ');
    cphex((u32)(uintptr_t)host);
    cput(' ');
    for (; *p; p++)
        cput(*p == ' ' ? '_' : *p);
    cput(' ');
    cphex((u32)id);
    return 0xE44E44E4u;
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
    /* the error-host fixture: cell -> host object -> vtable -> err_call */
    g_err_host[0] = 0;
    g_err_vtable[0] = 0;
    g_err_vtable[1] = 0;
    g_err_vtable[2] = 0;
    g_err_vtable[3] = (u32)(uintptr_t)&err_call;
    g_err_host[0] = (u32)(uintptr_t)&g_err_vtable[0];
    g_error_host_cell = (u32)(uintptr_t)&g_err_host[0];
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
    pstr("FIX HOST ");
    phex((u32)(uintptr_t)&g_err_host[0]);
    pstr(" VT ");
    phex((u32)(uintptr_t)&g_err_vtable[0]);
    pstr(" ERRFN ");
    phex((u32)(uintptr_t)&err_call);
    putc_('\n');
    flush();

    for (;;) {
        u32 fn, a, b, c, nw, k, ret;
        void *room, *layer, *inst;
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

        room = c ? (void *)0 : (void *)(uintptr_t)R_reg;
        inst = (a == 0x7f) ? (void *)0
                           : (void *)(uintptr_t)((u8 *)I_reg + a * IST);
        layer = (a == 0x7f) ? (void *)0
                            : (void *)(uintptr_t)((u8 *)L_reg + a * LST);

        if (fn == 1)
            ret = CRoom_AddInstance(room, inst);
        else if (fn == 2)
            ret = CLayerManager_AddInstance(room, inst);
        else if (fn == 3)
            ret = CLayerManager_AddInstanceToLayer(room, layer,
                                                   (b == 0x7f)
                                                       ? (void *)0
                                                       : (void *)(uintptr_t)(
                                                             (u8 *)I_reg +
                                                             b * IST));
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
