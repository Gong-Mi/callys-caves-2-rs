/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes, the
 * slot lookup's data record and the drawOrder timeline entry points are
 * SYNTHETIC providers.  qemu executes our linked C, never original libyoyo
 * bytes.  Original not executed; this is not an original-equivalence claim.
 *
 * Subject: the drawOrder timeline family of spSkeletonJson_readSkeletonData
 *   B15   0x28e338..0x28e528  (node test, create, two mallocs, -1 fill, the
 *                              offsets -> slot-index build, merge, _free(A))
 *   B15b  0x28e594..0x28e614  ("time" + setFrame + _free(B) loop, publish tail)
 *   E4    0x28e55c..0x28e58c  ("Attachment not found: ", NULL json argument)
 *   NOT here: 0x28e52c..0x28e558 = the path family's spacing island
 *             (c/spine_read_tl_path owns it; 0x28e528 b 0x28e594 skips it).
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem/getString/getInt/getFloat   json_interface
 *   spSkeletonData_findSlotIndex             skeleton_find (0x28b0cc)
 *   _spSkeletonJson_setError                 spine_json_error
 *   spAnimation_dispose / spSkeletonData_dispose   spine_skeleton_data
 *   Json_dispose / ReportSpineError          spine_json_support
 *   _malloc / _free / _calloc                spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture reproduces
 * the disassembled bodies and records every argument):
 *   spDrawOrderTimeline_create 0x282d4c — records (frameCount, slotsCount) and
 *     builds the real 24-byte shape: type 7, +0x08 frameCount, +0x0c times
 *     (frameCount floats, zeroed like _calloc at lines 676), +0x10 drawOrders
 *     (frameCount pointers, zeroed like line 677), +0x14 slotsCount.
 *   spDrawOrderTimeline_setFrame 0x282ddc — the real body's storage order:
 *     times[i] = time; _free(drawOrders[i]); NULL order -> drawOrders[i] = 0;
 *     else _malloc(slotsCount*4, tag, 690) + memcpy, then drawOrders[i] = copy.
 *     The copy pointer and the bytes it copied are recorded, which is what
 *     proves the caller's array is not retained.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_draworder.h"
#include "../../skeleton_find/src/skeleton_find.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 8
#define MAX_SLOTS  8

static struct {
    int create_n;
    int create_frames;
    int create_slots;
    void *timeline;
    int set_n;
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    const int32_t *set_order[MAX_FRAMES];
    int32_t set_order_want[MAX_FRAMES][MAX_SLOTS];
    void *copy_ptr[MAX_FRAMES];            /* setFrame's own line-690 copy */
    int copy_n[MAX_FRAMES];                /* slotsCount elements copied */
    int vdispose_n;
} obs;

static unsigned report_count;
static char reported[512], report_format[128];
static const char *alloc_tag[128];

/* spSkeletonData head this block reads: +0x18 slotsCount, +0x1c slot table.
 * Both words are the same ones spSkeletonData_findSlotIndex (0x28b0d4/0x28b0e0)
 * loads, which is why the fixture can use the REAL lookup. */
typedef struct {
    uint32_t pad[6];        /* +0x00..+0x14 */
    int32_t  slotsCount;    /* +0x18 */
    void**   slots;         /* +0x1c */
} data_tail;

typedef struct {
    uint32_t pad;           /* +0x00 */
    const char *name;       /* +0x04 read by spSkeletonData_findSlotIndex */
} slot_rec;

/* Set by slots_count_reload: the line-442 allocator callback rewrites the
 * count word, exactly the way a real allocation hook could. */
static void *flip_data;
static int32_t flip_slots;

/* Real ReportSpineError sink (adapter lives in reporter_adapter.c). */
void fixture_report_sink(const char *fmt, const char *message)
{
    ++report_count;
    strcpy(report_format, fmt);
    strcpy(reported, message);
}

/* setError imports strncat; the mesh fixture runtime has no strncat. */
char *strncat(char *d, const char *s, size_t n)
{
    char *r = d;
    d += strlen(d);
    while (n-- && *s) *d++ = *s++;
    *d = 0;
    return r;
}

/* Custom allocator: records (bytes, line, tag) so the line-442/445 requests and
 * the line-690 deep copy are all attributable. */
static void *tl_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "drawOrder allocation roster/tag");
    void *p = reserve(n);
    alloc_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
    /* Every re-read of data->slotsCount after this point (0x28e3f0, 0x28e3fc,
     * 0x28e4c4, 0x28e4e0) must observe the new word. */
    if (line == DRAWORDER_LINE_LEFTOVERS && flip_data)
        ((data_tail *)flip_data)->slotsCount = flip_slots;
    return p;
}

static unsigned alloc_count(uint32_t line)
{
    unsigned c = 0;
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) ++c;
    return c;
}
static uint32_t alloc_bytes(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) return aa[i].bytes;
    fail("missing allocation line");
    return 0;
}
static void *alloc_ptr(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) return aa[i].p;
    fail("missing allocation line");
    return 0;
}
static int tag_is(uint32_t line, const char *want)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return alloc_tag[i] && strcmp(alloc_tag[i], want) == 0;
    return 0;
}
static unsigned free_hits(const void *p)
{
    unsigned c = 0;
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) ++c;
    return c;
}
static int free_slot(const void *p)
{
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) return (int)i;
    return -1;
}

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                     */
/* ------------------------------------------------------------------ */
static void *tl_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

static uint32_t tl_vtable_words[2];

/* 0x282d4c: _calloc(1,24,tag,672) ; _spTimeline_init(t,7,vtable) ;
 * +0x08 = frameCount (0x282d94) ; +0x0c = _calloc(count,4,tag,676) ;
 * +0x10 = _calloc(count,4,tag,677) ; +0x14 = slotsCount (0x282dc0). */
void *spDrawOrderTimeline_create(int frameCount, int slotsCount)
{
    int n = frameCount < 1 ? 1 : frameCount;
    spDrawOrderTimelineShape *t = tl_zero(sizeof(*t));

    t->type = 7u;                                   /* 0x282d7c mov r1,#7 */
    t->vtable = tl_vtable_words;
    t->frameCount = frameCount;                     /* 0x282d94 */
    t->times = tl_zero((uint32_t)n * 4u);           /* 0x282da4..0x282db4 */
    t->drawOrders = tl_zero((uint32_t)n * 4u);      /* 0x282db8..0x282dc4 */
    t->slotsCount = slotsCount;                     /* 0x282dc0 */

    ++obs.create_n;
    obs.create_frames = frameCount;
    obs.create_slots = slotsCount;
    obs.timeline = t;
    return t;
}

/* 0x282ddc: r0 = timeline, r1 = frameIndex, r2 = time bits, r3 = int* order.
 *   0x282de4 ldr r1,[r0,#0xc] ; 0x282dec ldr r0,[r0,#0x10]
 *   0x282df4 add r3,r1,r5,lsl#2 ; 0x282df8 ldr r0,[r0,r5,lsl#2]
 *   0x282dfc str r2,[r3]        times[i] = time
 *   0x282e00 bl _free           free the slot's previous array
 *   0x282e04 cmp r6,#0 ; 0x282e08 beq 0x282e48
 *   0x282e0c ldr r0,[r4,#0x14] ; 0x282e20 lsl r0,r0,#2 ; 0x282e24 bl _malloc
 *   0x282e2c mov r1,r6 ; 0x282e30 lsl r2,r2,#2 ; 0x282e44 b memcpy
 *   0x282e34 str r0,[r7,r5,lsl#2]   drawOrders[i] = the copy
 *   0x282e48 str r6,[r3,...]         NULL order -> drawOrders[i] = 0 */
void spDrawOrderTimeline_setFrame(void *timeline, int frameIndex, float time,
                                  const int32_t *order)
{
    spDrawOrderTimelineShape *t = (spDrawOrderTimelineShape *)timeline;

    if (obs.set_n >= MAX_FRAMES) fail("drawOrder setFrame table exhausted");
    t->times[frameIndex] = time;                    /* 0x282dfc */
    _free(t->drawOrders[frameIndex]);               /* 0x282e00 */
    if (order == 0) {
        t->drawOrders[frameIndex] = 0;              /* 0x282e48 */
    } else {
        int32_t *copy = _malloc((uint32_t)t->slotsCount * 4u,
                                SPINE_JSON_SOURCE_TAG, 690u);  /* 0x282e24 */
        memcpy(copy, order, (uint32_t)t->slotsCount * 4u);     /* 0x282e44 */
        t->drawOrders[frameIndex] = copy;           /* 0x282e34 */
        obs.copy_ptr[obs.set_n] = copy;
        obs.copy_n[obs.set_n] = t->slotsCount;
    }
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_order[obs.set_n] = order;
    ++obs.set_n;
}

/* ------------------------------------------------------------------ */
/* scaffolding                                                         */
/* ------------------------------------------------------------------ */
static spSkeletonJson parser_obj;

static void tl_begin(const char *name)
{
    begin(name);                       /* resets aa/na/nf and installs a cb */
    _setDebugMalloc(tl_alloc);
    memset(&obs, 0, sizeof(obs));
    memset(&parser_obj, 0, sizeof(parser_obj));
    report_count = 0;
    flip_data = 0;
    flip_slots = 0;
    reported[0] = report_format[0] = 0;
    tl_vtable_words[0] = 0u;
    tl_vtable_words[1] = 0x282ddcu;    /* the real setFrame entry, as a marker */
}

static spSkeletonData *make_data(int32_t n, const char *const *names)
{
    spSkeletonData *d = spSkeletonData_create();   /* real calloc(1,84,tag,37) */
    data_tail *t = (data_tail *)d;
    void **tab = n > 0 ? (void **)tl_zero((uint32_t)n * 4u) : 0;

    for (int i = 0; i < n; ++i) {
        slot_rec *s = (slot_rec *)tl_zero(sizeof(*s));
        s->name = names[i];
        tab[i] = s;
    }
    t->slotsCount = n;                             /* 0x28b0d4 */
    t->slots = tab;                                /* 0x28b0e0 */
    return d;
}

static spAnimationDrawOrderShape *make_animation(void)
{
    spAnimationDrawOrderShape *a = (spAnimationDrawOrderShape *)tl_zero(sizeof(*a));
    a->timelines = (void **)tl_zero(4u * MAX_FRAMES);
    a->name = 0;
    return a;
}

/* Json helpers: Json_getItem matches on +0x1c with strcasecmp and ignores
 * +0x08, so the value words are all these builders need to set. */
static Json *num_key(const char *key, float value)
{
    Json *n = node(key);
    n->float_value = value;
    return n;
}
static Json *int_key(const char *key, int32_t value)
{
    Json *n = node(key);
    n->int_value = value;
    return n;
}
static Json *str_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->string_value = value;
    return n;
}
/* an "offsets" array: +0x0c is the DECLARED element count (may exceed the
 * number of children — that is exactly the underflow input) */
static Json *offsets_node(int32_t declared)
{
    Json *o = node("offsets");
    o->unk_0c = (uint32_t)declared;
    return o;
}
static Json *offset_entry(const char *slot, int32_t offset)
{
    Json *e = node(0);
    add(e, str_key("slot", slot));
    add(e, int_key("offset", offset));
    return e;
}
static Json *frame_node(float time, int with_time, Json *offsets)
{
    Json *f = node(0);
    if (with_time) add(f, num_key("time", time));
    if (offsets) add(f, offsets);
    return f;
}
/* the "drawOrder" node: +0x0c is the DECLARED frame count handed to create */
static Json *draworder_node(int32_t declared)
{
    Json *n = node("drawOrder");
    n->unk_0c = (uint32_t)declared;
    return n;
}

static int order_is(const int32_t *got, const int32_t *want, int n)
{
    for (int i = 0; i < n; ++i) if (got[i] != want[i]) return 0;
    return 1;
}

/* ================================================================== */
/* 1. no "drawOrder" member at all                                     */
/* ================================================================== */
static void draworder_absent(void)
{
    static const char *names[3] = { "a", "b", "c" };
    tl_begin("draworder_absent");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();

    CK(readSkeletonData_drawOrderTimelines(0, d, a) == DRAWORDER_TL_OK,
       "B15 with a NULL drawOrder node falls through to the event block");
    CK(obs.create_n == 0 && obs.set_n == 0,
       "a NULL drawOrder node never creates a timeline");
    CK(a->timelineCount == 0 && alloc_count(442u) == 0 && alloc_count(445u) == 0,
       "nothing is published and neither draw-order array is allocated");
    pass("draworder_absent");
}

/* ================================================================== */
/* 2. "drawOrder" present with no frames: create still runs           */
/* ================================================================== */
static void draworder_without_frames(void)
{
    static const char *names[3] = { "a", "b", "c" };
    tl_begin("draworder_without_frames");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(2);

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "B15 with an empty drawOrder object returns 1");
    CK(obs.create_n == 1 && obs.create_frames == 2 && obs.create_slots == 3,
       "create receives the DECLARED frame count (0x28e34c) and slotsCount (0x28e350)");
    CK(obs.set_n == 0, "no frame -> no setFrame");
    CK(a->timelineCount == 1 && a->timelines[0] == obs.timeline,
       "the zero-frame timeline is still published at the animation cursor");
    CK(bits(a->duration) == 0u,
       "duration reads times[declared-1] (zero) and keeps 0.0f");
    pass("draworder_without_frames");
}

/* ================================================================== */
/* 3. a frame with no "offsets": setFrame gets NULL, no malloc        */
/* ================================================================== */
static void frame_without_offsets(void)
{
    static const char *names[3] = { "a", "b", "c" };
    tl_begin("frame_without_offsets");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    spDrawOrderTimelineShape *t;

    add(do_node, frame_node(0.5f, 1, 0));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "an offsets-less frame returns 1");
    CK(obs.set_n == 1 && obs.set_index[0] == 0,
       "the frame still reaches setFrame at index 0");
    CK(obs.set_time[0] == 0x3f000000u, "setFrame receives the frame \"time\" bits");
    CK(obs.set_order[0] == 0,
       "a frame without \"offsets\" passes a NULL draw order (0x28e590)");
    CK(alloc_count(442u) == 0 && alloc_count(445u) == 0,
       "neither the line-442 nor the line-445 array is allocated");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(t->drawOrders[0] == 0, "setFrame stores NULL for that frame (0x282e48)");
    CK(nf == 2 && ff[0] == 0 && ff[1] == 0,
       "two unconditional _free(NULL) calls: setFrame's old slot (0x282e00) then "
       "the reader's line-445 pointer (0x28e5c0)");
    CK(a->timelineCount == 1 && bits(a->duration) == 0x3f000000u,
       "duration = times[declared-1] = times[0] = 0.5 beats the initial 0.0f");
    pass("frame_without_offsets");
}

/* ================================================================== */
/* 4. the whole ownership chain, on one entry at slot 1, offset 0      */
/* ================================================================== */
static void single_entry_identity(void)
{
    static const char *names[3] = { "a", "b", "c" };
    static const int32_t want_order[3] = { 0, 1, 2 };
    tl_begin("single_entry_identity");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;
    void *leftovers, *order;

    add(offs, offset_entry("b", 0));
    add(do_node, frame_node(0.25f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "one-entry run returns 1");
    CK(obs.create_n == 1 && obs.set_n == 1, "one create, one setFrame");
    CK(alloc_count(442u) == 1 && alloc_count(445u) == 1,
       "exactly one line-442 and one line-445 allocation per frame");
    CK(alloc_bytes(442u) == (3u - 1u) * 4u,
       "(slotsCount - jsonOffsetsSize) * 4 = 8 for the leftovers (0x28e3d8/0x28e3dc)");
    CK(alloc_bytes(445u) == 3u * 4u,
       "slotsCount * 4 = 12 for the order array (0x28e3f4)");
    CK(tag_is(442u, SPINE_JSON_SOURCE_TAG) && tag_is(445u, SPINE_JSON_SOURCE_TAG),
       "both mallocs carry the SkeletonJson.c tag from 0x357b08");
    leftovers = alloc_ptr(442u);
    order = alloc_ptr(445u);
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(obs.set_order[0] == order,
       "the pointer handed to setFrame is the line-445 array, not the line-442 one");
    CK(free_slot(leftovers) == 0,
       "the line-442 array is freed FIRST, inside the frame builder (0x28e524)");
    CK(nf == 3 && ff[1] == 0,
       "then setFrame frees the slot's previous (NULL) array (0x282e00)");
    CK(free_slot(order) == 2,
       "the line-445 array is freed LAST, right after setFrame returns (0x28e5c0)");
    CK(free_hits(leftovers) == 1 && free_hits(order) == 1,
       "each malloc is freed exactly once by the reader");
    CK(obs.copy_ptr[0] != order && obs.copy_ptr[0] != leftovers,
       "setFrame keeps neither pointer: it stores its own copy (0x282e34)");
    CK(obs.copy_n[0] == 3 && alloc_bytes(690u) == 12u,
       "the copy is slotsCount*4 bytes (0x282e0c/0x282e20/0x282e24)");
    CK(t->drawOrders[0] == obs.copy_ptr[0]
       && order_is(t->drawOrders[0], want_order, 3),
       "the timeline's private copy holds the final order [0,1,2]");
    CK(free_hits(obs.copy_ptr[0]) == 0,
       "the reader does NOT free setFrame's copy — the timeline owns it");
    CK(bits(t->times[0]) == 0x3e800000u && t->frameCount == 1 && t->slotsCount == 3,
       "create/ setFrame shape: one time slot, three slots");
    CK(obs.vdispose_n == 0, "no vtable walk happens on the success path");
    pass("single_entry_identity");
}

/* ================================================================== */
/* 5. offset -1 moves a slot up                                        */
/* ================================================================== */
static void offset_moves_slot_up(void)
{
    static const char *names[3] = { "a", "b", "c" };
    static const int32_t want[3] = { 1, 0, 2 };
    tl_begin("offset_moves_slot_up");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;

    add(offs, offset_entry("b", -1));
    add(do_node, frame_node(1.0f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "offset -1 run returns 1");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(order_is(t->drawOrders[0], want, 3),
       "B[slotIndex+offset] = slotIndex (0x28e4b4/0x28e4b8) moves \"b\" to the front");
    CK(order_is(t->drawOrders[0], want, 3) && t->drawOrders[0][2] == 2,
       "the untouched slot keeps its index");
    pass("offset_moves_slot_up");
}

/* ================================================================== */
/* 6. offset +2 moves a slot down                                      */
/* ================================================================== */
static void offset_moves_slot_down(void)
{
    static const char *names[3] = { "a", "b", "c" };
    static const int32_t want[3] = { 1, 2, 0 };
    tl_begin("offset_moves_slot_down");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;

    add(offs, offset_entry("a", 2));
    add(do_node, frame_node(1.0f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "offset +2 run returns 1");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(order_is(t->drawOrders[0], want, 3),
       "B[slotIndex+offset] leaves the two holes for the leftover merge");
    pass("offset_moves_slot_down");
}

/* ================================================================== */
/* 7. two frames: cursor, per-frame arrays, private copies             */
/* ================================================================== */
static void two_frames_cursor(void)
{
    static const char *names[4] = { "a", "b", "c", "d" };
    static const int32_t want0[4] = { 1, 0, 2, 3 };
    static const int32_t want1[4] = { 0, 1, 3, 2 };
    tl_begin("two_frames_cursor");
    spSkeletonData *d = make_data(4, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(2);
    Json *o0 = offsets_node(1);
    Json *o1 = offsets_node(1);
    spDrawOrderTimelineShape *t;

    add(o0, offset_entry("b", -1));
    add(o1, offset_entry("d", -1));
    add(do_node, frame_node(0.25f, 1, o0));
    add(do_node, frame_node(0.75f, 1, o1));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "two-frame run returns 1");
    CK(obs.set_n == 2 && obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "frameIndex starts at 0 and increments once per frame (0x28e5ac)");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_time[1] == 0x3f400000u,
       "each setFrame gets its own frame's \"time\" bits");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(order_is(t->drawOrders[0], want0, 4) && order_is(t->drawOrders[1], want1, 4),
       "each frame gets its own order array, copied into its own slot");
    CK(t->drawOrders[0] != t->drawOrders[1]
       && obs.copy_ptr[0] != obs.copy_ptr[1],
       "the two frames never share a draw-order array");
    CK(alloc_count(442u) == 2 && alloc_count(445u) == 2,
       "two frames -> two line-442 and two line-445 allocations");
    CK(free_slot(alloc_ptr(442u)) >= 0 && nf >= 4,
       "every reader-owned buffer is released");
    CK(bits(a->duration) == 0x3f400000u,
       "duration = the larger last-frame time (0.75)");
    pass("two_frames_cursor");
}

/* ================================================================== */
/* 8. the leftovers land in ascending order                            */
/* ================================================================== */
static void leftover_merge_order(void)
{
    static const char *names[3] = { "a", "b", "c" };
    static const int32_t want[3] = { 2, 0, 1 };
    tl_begin("leftover_merge_order");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;

    add(offs, offset_entry("c", -2));
    add(do_node, frame_node(1.0f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "leftover run returns 1");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(order_is(t->drawOrders[0], want, 3),
       "the -1 holes are filled from the tail of A, preserving ascending order");
    pass("leftover_merge_order");
}

/* ================================================================== */
/* 9. jsonOffsetsSize > slotsCount: the wrapped size is reproduced     */
/* ================================================================== */
static void offsets_size_underflow(void)
{
    static const char *names[2] = { "a", "b" };
    static const int32_t want[2] = { 0, 1 };
    tl_begin("offsets_size_underflow");
    spSkeletonData *d = make_data(2, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(3);       /* DECLARED 3, one child */
    spDrawOrderTimelineShape *t;

    add(offs, offset_entry("a", 0));
    add(do_node, frame_node(0.0f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "underflow run returns 1");
    CK(alloc_bytes(442u) == (uint32_t)((2 - 3) * 4),
       "the line-442 request is (slotsCount - jsonOffsetsSize) * 4 with rsb/lsl wrap");
    CK(alloc_bytes(442u) == 0xfffffffcu,
       "jsonOffsetsSize > slotsCount hands _malloc 0xfffffffc, unclamped and recorded");
    CK(alloc_bytes(445u) == 8u, "the line-445 request is unaffected");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(t->drawOrders[0] != 0 && order_is(t->drawOrders[0], want, 2),
       "the merge still produces a complete order for the slots that exist");
    pass("offsets_size_underflow");
}

/* ================================================================== */
/* 9b. slotsCount is re-read after each malloc, never cached           */
/* ================================================================== */
static void slots_count_reload(void)
{
    static const char *names[3] = { "a", "b", "c" };
    static const int32_t want[2] = { 0, 1 };
    tl_begin("slots_count_reload");
    spSkeletonData *d = make_data(3, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;

    add(offs, offset_entry("a", 0));
    add(do_node, frame_node(0.0f, 1, offs));
    flip_data = d;                 /* rewritten inside the line-442 _malloc */
    flip_slots = 2;

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "count-flip run returns 1");
    CK(obs.create_slots == 3,
       "create saw the original slotsCount (0x28e350, before any allocation)");
    CK(alloc_bytes(442u) == (3u - 1u) * 4u,
       "the line-442 size uses the count read at 0x28e3d0, i.e. BEFORE the callback ran");
    CK(alloc_bytes(445u) == 2u * 4u,
       "the line-445 size re-reads slotsCount at 0x28e3f0 and sees 2*4, not 3*4");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(t->slotsCount == 3 && obs.copy_n[0] == 3,
       "setFrame's copy still uses the timeline's own +0x14 (create's 3)");
    CK(t->drawOrders[0] != 0 && order_is(t->drawOrders[0], want, 2),
       "the -1 fill and the merge used the re-read count 2, so only two slots are written");
    pass("slots_count_reload");
}

/* ================================================================== */
/* 10. a miss leaves for 0x28e8ac: handoff, and BOTH arrays leak       */
/* ================================================================== */
static void slot_not_found_handoff(void)
{
    static const char *names[2] = { "a", "b" };
    tl_begin("slot_not_found_handoff");
    spSkeletonData *d = make_data(2, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);
    spDrawOrderTimelineShape *t;
    void *leftovers, *order;

    add(offs, offset_entry("ghost", 0));
    add(do_node, frame_node(0.0f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a)
       == DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND,
       "a slot miss leaves through 0x28e464 beq 0x28e8ac, reported not translated");
    CK(obs.create_n == 1 && obs.set_n == 0,
       "the timeline was created, but no frame was published");
    CK(a->timelineCount == 0, "nothing is published on the handoff path");
    CK(alloc_count(442u) == 1 && alloc_count(445u) == 1,
       "both arrays were already allocated when the miss happened");
    leftovers = alloc_ptr(442u);
    order = alloc_ptr(445u);
    CK(free_hits(leftovers) == 0 && free_hits(order) == 0,
       "the original frees NEITHER array on the miss path; the leak is reproduced");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(t->drawOrders[0] == 0, "the created timeline was never written");
    pass("slot_not_found_handoff");
}

/* ================================================================== */
/* 11. an absent "time" defaults to 0.0f                               */
/* ================================================================== */
static void frame_time_default(void)
{
    static const char *names[2] = { "a", "b" };
    tl_begin("frame_time_default");
    spSkeletonData *d = make_data(2, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(0);

    add(do_node, frame_node(0.0f, 0, offs));    /* "offsets" present, no "time" */

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "default-time run returns 1");
    CK(obs.set_n == 1 && obs.set_time[0] == 0u,
       "an absent \"time\" yields the 0.0f default (0x28e59c)");
    CK(obs.set_order[0] != 0, "an empty offsets array still builds an order");
    pass("frame_time_default");
}

/* ================================================================== */
/* 12. E4: "Attachment not found: " with a NULL json argument          */
/* ================================================================== */
static void attachment_not_found(void)
{
    tl_begin("attachment_not_found");
    static const char *names1[1] = { "body" };
    spSkeletonData *d = make_data(1, names1);
    spAnimationDrawOrderShape *a = make_animation();
    Json *root = node("skeleton");
    Json *slot = node("body");
    Json *deform = node("hand");
    Json *frame = node(0);

    add(frame, num_key("time", 0.5f));
    add(deform, frame);
    add(slot, deform);
    add(root, slot);

    CK(readSkeletonData_attachmentNotFound(deform, d, a, &parser_obj)
       == DRAWORDER_TL_ERROR,
       "E4 returns 0 so the loader unwinds to NULL");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E4 reports through the real console vcall");
    CK(strcmp(reported, "Attachment not found: hand") == 0,
       "E4 message is the exact literal plus the attachment timeline's name");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error,
                 "Attachment not found: hand") == 0,
       "E4 stores the formatted message in parser->error");
    CK(alloc_count(90u) == 1 && tag_is(90u, SPINE_JSON_SOURCE_TAG),
       "E4 error copy is a line-90 SkeletonJson.c allocation");
    CK(free_hits(root) == 0 && free_hits(slot) == 0
       && free_hits(deform) == 0 && free_hits(frame) == 0,
       "E4 passes NULL as the setError json argument: NO Json node is disposed");
    CK(free_hits(a) == 1 && free_hits(a->timelines) == 1,
       "E4 disposes the animation before reporting (0x28e570)");
    CK(obs.vdispose_n == 0, "the animation had published nothing to walk");
    CK(free_slot(a) >= 0 && free_slot(d) > free_slot(a),
       "E4 disposes the animation BEFORE the skeleton data (0x28e570 then 0x28da48)");
    CK(free_hits(d) == 1, "E4 disposes the skeleton data exactly once (0x28da48)");
    pass("attachment_not_found");
}

/* ================================================================== */
/* 13. publish cursor and duration max                                 */
/* ================================================================== */
static void publish_cursor_duration(void)
{
    static const char *names[2] = { "a", "b" };
    tl_begin("publish_cursor_duration");
    spSkeletonData *d = make_data(2, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(1);
    Json *offs = offsets_node(1);

    add(offs, offset_entry("a", 0));
    add(do_node, frame_node(2.5f, 1, offs));
    a->duration = 0.5f;

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "duration run returns 1");
    CK(a->timelineCount == 1 && a->timelines[0] == obs.timeline,
       "timelines[count] is written at the OLD cursor and the count is bumped");
    CK(bits(a->duration) == 0x40200000u,
       "duration = max(0.5, last time 2.5) (0x28e604..0x28e610)");

    /* second run: the existing duration wins */
    obs.set_n = 0;
    a->duration = 9.0f;
    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "second publish returns 1");
    CK(bits(a->duration) == 0x41100000u,
       "a larger existing duration is kept (vmovgt only on strictly greater)");
    CK(a->timelineCount == 2 && a->timelines[1] == obs.timeline,
       "the second timeline lands at cursor 1");
    pass("publish_cursor_duration");
}

/* ================================================================== */
/* 14. the tail indexes times[] with the DECLARED count                */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    static const char *names[2] = { "a", "b" };
    tl_begin("declared_vs_child_count");
    spSkeletonData *d = make_data(2, names);
    spAnimationDrawOrderShape *a = make_animation();
    Json *do_node = draworder_node(3);      /* declares 3, carries 1 */
    Json *offs = offsets_node(0);
    spDrawOrderTimelineShape *t;

    add(do_node, frame_node(0.5f, 1, offs));

    CK(readSkeletonData_drawOrderTimelines(do_node, d, a) == DRAWORDER_TL_OK,
       "declared-three run returns 1");
    CK(obs.create_frames == 3 && obs.set_n == 1,
       "create still receives the declared count, the loop follows the child list");
    t = (spDrawOrderTimelineShape *)obs.timeline;
    CK(bits(t->times[0]) == 0x3f000000u && bits(t->times[1]) == 0u
       && bits(t->times[2]) == 0u,
       "only frame 0 was written; the calloc-zeroed slots stay 0");
    CK(bits(a->duration) == 0u,
       "the tail reads times[(3-1)] (=0), not times[0] (0x28e5fc add ... lsl#2)");
    pass("declared_vs_child_count");
}

void _start(void)
{
    test = "startup"; init_heap(); fixture_install_error_reporter();
    draworder_absent();
    draworder_without_frames();
    frame_without_offsets();
    single_entry_identity();
    offset_moves_slot_up();
    offset_moves_slot_down();
    two_frames_cursor();
    leftover_merge_order();
    offsets_size_underflow();
    slots_count_reload();
    slot_not_found_handoff();
    frame_time_default();
    attachment_not_found();
    publish_cursor_duration();
    declared_vs_child_count();
    out("SUMMARY all declared drawOrder timeline family contracts passed\n");
    quit(0);
}
