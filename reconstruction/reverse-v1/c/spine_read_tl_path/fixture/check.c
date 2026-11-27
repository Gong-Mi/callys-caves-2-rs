/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the path lookup and the two timeline entry points are SYNTHETIC providers.
 * qemu executes our linked C, never original libyoyo bytes.  Original not
 * executed; this is not an original-equivalence claim.
 *
 * Subject: the path-constraint timeline family of spSkeletonJson_readSkeletonData
 *   B13  0x28de74..0x28e060  (paths loop head + findPathConstraint + pointer
 *                             linear scan into [sp+0x2c] + position/spacing
 *                             dispatch + shared frame loop + publish tail)
 *   islands 0x28e52c..0x28e558 (spacing create + mode select), 0x28ea74
 *           (spacing scale), 0x28e554 (1.0f arm), 0x28ea48..0x28ea70 (E7)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getFloat                    json_interface
 *   readCurve                        spine_read_curve
 *   _spSkeletonJson_setError         spine_json_error
 *   spAnimation_dispose / spSkeletonData_dispose / spTimeline_dispose
 *       (via spAnimation_dispose's vtable walk)   spine_skeleton_data
 *   Json_dispose / ReportSpineError  spine_json_support
 *   _malloc / _free / _calloc        spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spSkeletonData_findPathConstraint 0x28b2f0 — returns a scripted per-call
 *     pointer (NULL allowed) and records the name it was asked for, so both
 *     "B13 null-tests the result" and "the key is the JSON member key" are
 *     observable.
 *   spPathConstraintPositionTimeline_create / ...SpacingTimeline_create —
 *     record doubles with the real 24-byte shape (frameFloatCount = count*2,
 *     frames = count*2 floats) and +0x14 filled with SENTINEL.
 *   spPathConstraintPositionTimeline_setFrame 0x283028 — stores the
 *     disassembled shape (frames[i*2] = time, frames[i*2+1] = value) and
 *     records every argument word.  This is the family's ONLY setFrame: the
 *     spacing symbol 0x283054 is deliberately NOT defined here, so a
 *     reconstruction that calls it cannot link.
 *   spCurveTimeline_setStepped/setCurve (0x2817c0/0x2817d8) — recorders.
 *   fixture heap/allocator roster, libc providers, hand-built Json nodes.
 *
 * SENTINEL note: unlike ik/transform, B13 stores index into +0x14
 * UNCONDITIONALLY (0x28df94), so the create-time value must never survive any
 * path through this block.  The fixture still starts the word at a value that
 * is neither 0 nor -1 so that "the store really happened" is distinguishable
 * from "the store never ran".
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_path.h"
#include "../../spine_read_curve/src/spine_read_curve.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 16
#define MAX_TL 8
#define SENTINEL 0x5a5a5a5a

enum { K_POS = 0, K_SPA = 1 };

static struct {
    int create_n[2];
    int create_frames[2];
    void *last_timeline[2];
    void *made[MAX_TL];
    int made_n;
    int set_n;
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    uint32_t set_value[MAX_FRAMES];
    void *set_tl[MAX_FRAMES];
    int curve_n, curve_kind[MAX_FRAMES], curve_frame[MAX_FRAMES];
    void *curve_tl[MAX_FRAMES];
    uint32_t curve_args[MAX_FRAMES][4];
    void *lookup_ret[MAX_TL];         /* scripted findPathConstraint result */
    const char *lookup_name[MAX_TL];
    int lookup_n;
    void *flip_data;                  /* scripted data-record edit ... */
    int32_t flip_count;               /* ... applied right before lookup #flip_at */
    int flip_at;
    int vdispose_n;
} obs;

static unsigned report_count;
static char reported[512], report_format[128];
static const char *alloc_tag[128];

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

/* Custom allocator: records (bytes, line, tag) so setError's line-90 copy is
 * observable. */
static void *tl_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "path allocation roster/tag");
    void *p = reserve(n);
    alloc_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
    return p;
}

static unsigned alloc_count(uint32_t line)
{
    unsigned c = 0;
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) ++c;
    return c;
}
static unsigned free_hits(const void *p)
{
    unsigned c = 0;
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) ++c;
    return c;
}
static int tag_is(uint32_t line, const char *want)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return alloc_tag[i] && strcmp(alloc_tag[i], want) == 0;
    return 0;
}

/* ------------------------------------------------------------------ */
/* timeline vtable: spAnimation_dispose -> spTimeline_dispose (0x281468) */
/* reads [[self+4]+4] and blx's it; the probe only counts the walk.     */
/* ------------------------------------------------------------------ */
static uint32_t tl_vtable_words[2];

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                     */
/* ------------------------------------------------------------------ */
static void *tl_reserve_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

void *spSkeletonData_findPathConstraint(void *data, const char *name)
{
    void *r;
    (void)data;
    if (obs.lookup_n >= MAX_TL) fail("path lookup roster exhausted");
    r = obs.lookup_ret[obs.lookup_n];
    obs.lookup_name[obs.lookup_n] = name;
    ++obs.lookup_n;
    /* The original re-reads data+0x4c inside the outer loop (0x28deec), so a
     * change of the count word between iterations is a legal input change. */
    if (obs.flip_at && obs.lookup_n == obs.flip_at && obs.flip_data)
        ((spSkeletonDataPathShape *)obs.flip_data)->pathConstraintsCount = obs.flip_count;
    return r;                          /* may be NULL: B13 DOES test it */
}

/* The real creators tail-call _spBaseTimeline_create(count, type, step, tag)
 * (0x282a10): frameFloatCount = count*step at +0x0c, calloc'd frames at +0x10,
 * curves at +0x08.  The double keeps that layout. */
static void *path_timeline_create(int kind, int frameCount, int frameStep)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spPathConstraintTimelineShape *t = tl_reserve_zero(sizeof(*t));
    if (obs.create_n[kind] >= MAX_TL || obs.made_n >= MAX_TL)
        fail("path create roster exhausted");
    t->type = (kind == K_POS) ? 11u : 12u;   /* 0x283014 mov r1,#11 (position) /
                                              * 0x283040 mov r1,#12 (spacing) */
    t->vtable = tl_vtable_words;
    t->curves = 0;                     /* readCurve doubles only record */
    t->frameFloatCount = frameCount * frameStep;
    t->frames = tl_reserve_zero(n * (uint32_t)frameStep * 4u);
    t->pathConstraintIndex = (int32_t)SENTINEL;
    ++obs.create_n[kind];
    obs.create_frames[kind] = frameCount;
    obs.last_timeline[kind] = t;
    obs.made[obs.made_n++] = t;
    return t;
}

void *spPathConstraintPositionTimeline_create(int frameCount)
{
    return path_timeline_create(K_POS, frameCount, 2);   /* 0x283014/0x283018 */
}
void *spPathConstraintSpacingTimeline_create(int frameCount)
{
    return path_timeline_create(K_SPA, frameCount, 2);    /* 0x283040/0x283044 */
}

void spPathConstraintPositionTimeline_setFrame(void *timeline, int frameIndex,
                                               float time, float value)
{
    spPathConstraintTimelineShape *t = (spPathConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 2u;
    if (obs.set_n >= MAX_FRAMES) fail("path setFrame table exhausted");
    /* 0x283028 ldr r0,[r0,#0x10] ; 0x28302c add r12,r0,r1,lsl#3 ;
     * 0x283030 str r2,[r12] ; 0x283034 str r3,[r12,#0x4] */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = value;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_value[obs.set_n] = bits(value);
    obs.set_tl[obs.set_n] = timeline;
    ++obs.set_n;
}

/* spPathConstraintSpacingTimeline_setFrame (0x283054) is intentionally absent:
 * its body is byte-identical to 0x283028 (e5900010 e080c181 e58c2000
 * e58c3004 e12fff1e) but 0x28dfe4 is the family's only call site. */

void spCurveTimeline_setStepped(void *curveTimeline, int frameIndex)
{
    if (obs.curve_n >= MAX_FRAMES) fail("curve table exhausted");
    obs.curve_kind[obs.curve_n] = 1;
    obs.curve_frame[obs.curve_n] = frameIndex;
    obs.curve_tl[obs.curve_n] = curveTimeline;
    ++obs.curve_n;
}

void spCurveTimeline_setCurve(void *curveTimeline, int frameIndex,
                              float cx1, float cy1, float cx2, float cy2)
{
    if (obs.curve_n >= MAX_FRAMES) fail("curve table exhausted");
    obs.curve_kind[obs.curve_n] = 2;
    obs.curve_frame[obs.curve_n] = frameIndex;
    obs.curve_tl[obs.curve_n] = curveTimeline;
    obs.curve_args[obs.curve_n][0] = bits(cx1);
    obs.curve_args[obs.curve_n][1] = bits(cy1);
    obs.curve_args[obs.curve_n][2] = bits(cx2);
    obs.curve_args[obs.curve_n][3] = bits(cy2);
    ++obs.curve_n;
}

/* The parameter type must stay spTimeline* so the indirect call through
 * spTimeline_dispose's typedef matches under -fsanitize=function. */
static void tl_dispose_probe(spTimeline *self) { (void)self; ++obs.vdispose_n; }

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
    parser_obj.scale = bits(1.0f);
    report_count = 0;
    reported[0] = report_format[0] = 0;
    tl_vtable_words[0] = 0u;
    tl_vtable_words[1] = (uint32_t)(uintptr_t)tl_dispose_probe;
}

/* spPathConstraintData head this block reads: +0x10 positionMode, +0x14
 * spacingMode.  Pointer identity is what the scan compares. */
static spPathConstraintDataPathShape *pc_record(void)
{
    return tl_reserve_zero(sizeof(spPathConstraintDataPathShape));
}

/* spSkeletonData is calloc(1,84,tag,37) in the original (0x28ade4); the two
 * words this family reads are +0x4c (count) and +0x50 (array). */
static spSkeletonData *make_data(int32_t count, void **array)
{
    spSkeletonData *d = spSkeletonData_create();   /* real calloc(1,84,tag,37) */
    spSkeletonDataPathShape *s = (spSkeletonDataPathShape *)d;
    s->pathConstraintsCount = count;
    s->pathConstraints = array;
    return d;
}

static spAnimationPathShape *make_animation(void)
{
    spAnimationPathShape *a = tl_reserve_zero(sizeof(*a));
    a->timelines = tl_reserve_zero(4u * MAX_TL);
    return a;
}

/* Json helpers: node types match the parser's enum (json_interface/readCurve). */
static Json *num_key(const char *key, float value)
{
    Json *n = node(key);
    n->unk_08 = 3;                     /* number */
    n->float_value = value;
    return n;
}
static Json *str_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->unk_08 = 4;                     /* string */
    n->string_value = value;
    return n;
}
/* a path constraint node (name = the member key) or a timeline node
 * (name = "position"/"spacing"/..., +0x0c = declared frame count) */
static Json *tl_node(const char *name, int declared)
{
    Json *n = node(name);
    n->unk_0c = (uint32_t)declared;
    return n;
}
static Json *frame_bt(float time, const char *value_key, float value)
{
    Json *f = node(0);
    add(f, num_key("time", time));
    if (value_key) add(f, num_key(value_key, value));
    return f;
}

/* the timeline made by the most recent create of `kind` */
static spPathConstraintTimelineShape *last_tl(int kind)
{
    return (spPathConstraintTimelineShape *)obs.last_timeline[kind];
}

/* ================================================================== */
/* 1. no "paths" value at all                                          */
/* ================================================================== */
static void paths_absent(void)
{
    tl_begin("paths_absent");
    void *arr[1] = { pc_record() };
    spSkeletonData *d = make_data(1, arr);
    spAnimationPathShape *a = make_animation();

    CK(readSkeletonData_pathTimelines(0, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "B13 with a NULL paths node falls through to the deform block");
    CK(obs.lookup_n == 0 && obs.create_n[K_POS] == 0 && obs.create_n[K_SPA] == 0,
       "B13 with a NULL paths node never looks up nor creates a timeline");
    CK(a->timelineCount == 0, "B13 with a NULL paths node publishes nothing");
    pass("paths_absent");
}

/* ================================================================== */
/* 2. "paths" present but empty                                        */
/* ================================================================== */
static void paths_without_children(void)
{
    tl_begin("paths_without_children");
    void *arr[1] = { pc_record() };
    spSkeletonData *d = make_data(1, arr);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");       /* no children */

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "B13 with an empty paths object returns to the deform block");
    CK(obs.lookup_n == 0 && obs.create_n[K_POS] == 0 && obs.create_n[K_SPA] == 0
       && a->timelineCount == 0,
       "B13 with an empty paths object creates and publishes nothing");
    pass("paths_without_children");
}

/* ================================================================== */
/* 3. E7: path constraint not found (json argument = animation node)   */
/* ================================================================== */
static void constraint_not_found(void)
{
    tl_begin("constraint_not_found");
    spPathConstraintDataPathShape *known = pc_record();
    void *arr[1] = { known };
    spSkeletonData *d = make_data(1, arr);
    spAnimationPathShape *a = make_animation();
    void **anim_table = a->timelines;
    Json *anim = node(0);
    Json *paths = node("paths");
    Json *p0 = tl_node("c0", 0);
    Json *p1 = tl_node("ghost", 0);
    Json *t0 = tl_node("position", 1);
    Json *f0 = frame_bt(0.5f, "position", 1.0f);

    add(t0, f0);
    add(p0, t0);
    add(p1, tl_node("position", 1));
    add(paths, p0);
    add(paths, p1);
    add(anim, paths);
    obs.lookup_ret[0] = known;         /* "c0" resolves */
    obs.lookup_ret[1] = 0;             /* "ghost" -> NULL -> E7 */

    CK(readSkeletonData_pathTimelines(paths, anim, d, a, &parser_obj) == PATH_TL_ERROR,
       "E7 returns 0 so the parent loader returns NULL");
    CK(obs.lookup_n == 2
       && strcmp(obs.lookup_name[0], "c0") == 0
       && strcmp(obs.lookup_name[1], "ghost") == 0,
       "the outer loop advances through the paths child list and passes the member key");
    CK(obs.create_n[K_POS] == 1 && a->timelineCount == 1,
       "the first path constraint was processed and published before the miss");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E7 reports through the real console vcall");
    CK(strcmp(reported, "Path constraint not found: ghost") == 0,
       "E7 message is the exact original literal plus the path node key");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error,
                 "Path constraint not found: ghost") == 0,
       "E7 stores the formatted message in parser->error");
    CK(alloc_count(90) == 1
       && tag_is(90, "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
       "E7 error copy is a line-90 SkeletonJson.c allocation");
    CK(obs.vdispose_n == 1,
       "E7 disposes the animation first: the published timeline is walked");
    CK(free_hits(a) == 1 && free_hits(anim_table) == 1,
       "E7 animation dispose frees the timeline table and the record");
    CK(free_hits(anim) == 1,
       "E7 passes the CURRENT ANIMATION NODE as the setError json argument");
    CK(free_hits(paths) == 1 && free_hits(p0) == 1 && free_hits(p1) == 1,
       "E7 Json_dispose walks the animation node's children (paths, both constraints)");
    CK(free_hits(d) == 1, "E7 disposes the skeleton data exactly once");
    pass("constraint_not_found");
}

/* ================================================================== */
/* 4/5/6. the scan finds the element at position 0 / 2 / 4             */
/* ================================================================== */
static void scan_at(const char *name, int want)
{
    spPathConstraintDataPathShape *array[5];
    void *raw[5];
    spSkeletonData *d;
    spAnimationPathShape *a;
    Json *paths = node("paths");
    Json *pn = node("c0");
    Json *tn = tl_node("position", 1);
    spPathConstraintTimelineShape *t;

    tl_begin(name);
    for (int i = 0; i < 5; ++i) {
        array[i] = pc_record();
        raw[i] = array[i];
    }
    d = make_data(5, raw);
    a = make_animation();
    add(tn, frame_bt(0.0f, "position", 1.0f));
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = raw[want];

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "scan run returns 1 (deform block)");
    CK(obs.lookup_n == 1, "one findPathConstraint call per path node");
    CK(strcmp(obs.lookup_name[0], "c0") == 0,
       "findPathConstraint receives the JSON member key at +0x1c");
    CK(obs.create_n[K_POS] == 1 && obs.create_frames[K_POS] == 1,
       "create receives the declared frame count from Json+0x0c");
    t = last_tl(K_POS);
    CK(t->pathConstraintIndex != (int32_t)SENTINEL,
       "the +0x14 store at 0x28df94 really ran (the create-time sentinel is gone)");
    CK(t->pathConstraintIndex == want, "the scan stores the matching element index");
    CK(obs.set_n == 1 && a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "the timeline is published at the animation cursor");
    pass(name);
}

static void scan_element_zero(void)
{
    scan_at("scan_element_zero", 0);
}
static void scan_element_middle(void)
{
    scan_at("scan_element_middle", 2);
}
static void scan_element_last(void)
{
    scan_at("scan_element_last", 4);
}

/* ================================================================== */
/* 7. a miss stores the untouched cell (0 for the first constraint)    */
/* ================================================================== */
static void scan_miss_leaves_cell(void)
{
    tl_begin("scan_miss_leaves_cell");
    spPathConstraintDataPathShape *array[3];
    void *raw[3];
    spPathConstraintDataPathShape *missing = pc_record();
    spSkeletonData *d;
    spAnimationPathShape *a;
    Json *paths = node("paths");
    Json *pn = node("nope");
    Json *tn = tl_node("position", 1);
    spPathConstraintTimelineShape *t;

    for (int i = 0; i < 3; ++i) { array[i] = pc_record(); raw[i] = array[i]; }
    d = make_data(3, raw);
    a = make_animation();
    add(tn, frame_bt(0.25f, "position", 1.0f));
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = missing;       /* not in the array */

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "miss run returns 1");
    t = last_tl(K_POS);
    CK(t->pathConstraintIndex == 0,
       "a miss still stores the cell, which is 0 for the first constraint");
    CK(obs.set_n == 1 && a->timelineCount == 1,
       "a miss still reads the frames and publishes the timeline");
    pass("scan_miss_leaves_cell");
}

/* ================================================================== */
/* 8. the cell CARRIES OVER between constraints (unlike ik/transform)  */
/* ================================================================== */
static void scan_index_carries(void)
{
    tl_begin("scan_index_carries");
    spPathConstraintDataPathShape *array[3];
    void *raw[3];
    spPathConstraintDataPathShape *missing = pc_record();
    spSkeletonData *d;
    spAnimationPathShape *a;
    Json *paths = node("paths");
    Json *p0 = node("a");
    Json *p1 = node("b");
    Json *t0 = tl_node("position", 1);
    Json *t1 = tl_node("position", 1);
    spPathConstraintTimelineShape *first;

    for (int i = 0; i < 3; ++i) { array[i] = pc_record(); raw[i] = array[i]; }
    d = make_data(3, raw);
    a = make_animation();
    add(t0, frame_bt(0.0f, "position", 1.0f));
    add(t1, frame_bt(0.0f, "position", 2.0f));
    add(p0, t0);
    add(p1, t1);
    add(paths, p0);
    add(paths, p1);
    obs.lookup_ret[0] = raw[2];        /* "a" hits element 2 */
    obs.lookup_ret[1] = missing;       /* "b" misses */

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "two-constraint run returns 1");
    CK(obs.create_n[K_POS] == 2 && a->timelineCount == 2,
       "both timelines are created and published");
    first = (spPathConstraintTimelineShape *)obs.made[0];
    CK(first->pathConstraintIndex == 2,
       "the first constraint stores its hit index 2");
    CK(((spPathConstraintTimelineShape *)obs.made[1])->pathConstraintIndex == 2,
       "the second constraint MISSES and stores the stale cell 2, not 0 and not a sentinel");
    pass("scan_index_carries");
}

/* ================================================================== */
/* 9. the count is signed and the array is not read when count <= 0    */
/* ================================================================== */
static void scan_nonpositive_count(void)
{
    tl_begin("scan_nonpositive_count");
    spPathConstraintDataPathShape *only = pc_record();
    Json *paths = node("paths");
    Json *pn = node("only");
    Json *tn = tl_node("position", 1);

    add(tn, frame_bt(0.0f, "position", 1.0f));
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = only;          /* would match if the scan ran */

    /* A. count == 0 with a NULL array: 0x28def4 ble skips, so the +0x50 word
     * is never loaded and the cell stays 0. */
    {
        spSkeletonData *d = make_data(0, 0);
        spAnimationPathShape *a = make_animation();
        CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
           "count 0 run returns 1");
        CK(last_tl(K_POS)->pathConstraintIndex == 0,
           "count 0 skips the scan and the cell stays 0");
        CK(obs.set_n == 1 && a->timelineCount == 1,
           "count 0 still reaches the frame loop and the tail");
    }
    /* B. count == -1 while a matching element 0 exists.  The cell already holds
     * 2 from constraint "a"; `ble` must leave it there.  If the compare were
     * `== 0` (a beq reading of 0x28def4) the scan would run, element 0 would
     * match and the cell would drop to 0 -- that is the only observable
     * difference, so the assertion is on the STALE 2.
     * The fixture flips the count word before the second lookup returns; the
     * original re-reads data+0x4c on every iteration (0x28deec inside the
     * outer loop), so this is a legal change of input between iterations. */
    {
        spPathConstraintDataPathShape *array[3];
        void *raw[3];
        spSkeletonData *d;
        spAnimationPathShape *a;
        Json *paths2 = node("paths");
        Json *p0 = node("a");
        Json *p1 = node("b");
        Json *t0 = tl_node("position", 1);
        Json *t1 = tl_node("position", 1);
        int base;

        for (int i = 0; i < 3; ++i) { array[i] = pc_record(); raw[i] = array[i]; }
        d = make_data(3, raw);
        a = make_animation();
        add(t0, frame_bt(0.0f, "position", 1.0f));
        add(t1, frame_bt(0.0f, "position", 2.0f));
        add(p0, t0);
        add(p1, t1);
        add(paths2, p0);
        add(paths2, p1);
        obs.lookup_ret[obs.lookup_n] = raw[2];      /* "a" hits element 2 -> cell 2 */
        obs.lookup_ret[obs.lookup_n + 1] = raw[0];  /* "b" would hit element 0 */
        obs.flip_data = d;
        obs.flip_count = -1;
        obs.flip_at = obs.lookup_n + 2;             /* before the 2nd lookup returns */
        obs.set_n = 0;
        base = obs.made_n;

        CK(readSkeletonData_pathTimelines(paths2, 0, d, a, &parser_obj)
           == PATH_TL_REACHED_DEFORM, "count -1 run returns 1");
        CK(obs.made_n == base + 2, "both constraints created a timeline");
        CK(((spPathConstraintTimelineShape *)obs.made[base])->pathConstraintIndex == 2,
           "the first constraint stored its hit index 2");
        CK(((spPathConstraintTimelineShape *)obs.made[base + 1])->pathConstraintIndex == 2,
           "a negative count skips the scan (ble, not bne)");
        CK(obs.set_n == 2, "count -1 still reaches the frame loop");
        obs.flip_at = 0;
    }
    pass("scan_nonpositive_count");
}


/* ================================================================== */
/* 10. position frames: scale multiplier, indices, store shape         */
/* ================================================================== */
static void position_frames_scaled(void)
{
    tl_begin("position_frames_scaled");
    spPathConstraintDataPathShape *pc = pc_record();
    void *raw[1] = { pc };
    spSkeletonData *d = make_data(1, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *pn = node("c");
    Json *tn = tl_node("position", 2);
    spPathConstraintTimelineShape *t;

    pc->positionMode = 0;              /* fixed: 0x28df74 cmp #0 -> scale */
    parser_obj.scale = bits(2.0f);     /* 0x28df84 vldr s16,[parser] */
    add(tn, frame_bt(0.25f, "position", 1.5f));
    add(tn, frame_bt(0.5f, "position", -0.75f));
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = pc;

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "position run returns 1");
    CK(obs.set_n == 2, "one setFrame per frame child");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "the frame index starts at 0 and increments per frame");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_time[1] == 0x3f000000u,
       "setFrame receives the frame \"time\" bits");
    CK(obs.set_value[0] == 0x40400000u,
       "positionMode 0 multiplies the \"position\" value by parser->scale (1.5*2)");
    CK(obs.set_value[1] == 0xbfc00000u,
       "the scaled value keeps its sign (-0.75*2 = -1.5)");
    t = last_tl(K_POS);
    CK(bits(t->frames[0]) == 0x3e800000u && bits(t->frames[1]) == 0x40400000u
       && bits(t->frames[2]) == 0x3f000000u && bits(t->frames[3]) == 0xbfc00000u,
       "frame 0 stores time then value at stride 2 (0x283030/0x283034)");
    CK(t->frameFloatCount == 4 && t->type == 11u,
       "create receives count*2 floats and the position type word 11 (0x283014)");
    CK(bits(a->duration) == 0x3f000000u,
       "duration reads frames[(declared-1)*2] = the last TIME, not a value");
    pass("position_frames_scaled");
}

/* ================================================================== */
/* 11. positionMode != 0 keeps the multiplier at 1.0                   */
/* ================================================================== */
static void position_percent_unscaled(void)
{
    static const int32_t modes[2] = { 1, 5 };
    tl_begin("position_percent_unscaled");
    for (unsigned k = 0; k < 2; ++k) {
        spPathConstraintDataPathShape *pc = pc_record();
        void *raw[1] = { pc };
        spSkeletonData *d = make_data(1, raw);
        spAnimationPathShape *a = make_animation();
        Json *paths = node("paths");
        Json *pn = node("c");
        Json *tn = tl_node("position", 1);

        pc->positionMode = modes[k];
        parser_obj.scale = bits(2.0f);
        add(tn, frame_bt(0.0f, "position", 1.5f));
        add(pn, tn);
        add(paths, pn);
        obs.set_n = 0;
        obs.lookup_ret[obs.lookup_n] = pc;

        CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj)
           == PATH_TL_REACHED_DEFORM, "non-zero positionMode run returns 1");
        CK(obs.set_value[0] == 0x3fc00000u,
           "any non-zero positionMode uses the 1.0f arm (0x28df7c -> 0x28e554)");
    }
    pass("position_percent_unscaled");
}

/* ================================================================== */
/* 12. spacingMode matrix: the test is UNSIGNED <= 1                   */
/* ================================================================== */
static void spacing_mode_matrix(void)
{
    /* mode, multiplier applied (2.0f parser scale) */
    static const int32_t modes[5] = { 0, 1, 2, 3, -1 };
    static const uint32_t want[5] = { 0x40400000u, 0x40400000u, 0x3fc00000u,
                                      0x3fc00000u, 0x3fc00000u };
    tl_begin("spacing_mode_matrix");
    for (unsigned k = 0; k < 5; ++k) {
        spPathConstraintDataPathShape *pc = pc_record();
        void *raw[1] = { pc };
        spSkeletonData *d = make_data(1, raw);
        spAnimationPathShape *a = make_animation();
        Json *paths = node("paths");
        Json *pn = node("c");
        Json *tn = tl_node("spacing", 1);

        pc->spacingMode = modes[k];
        parser_obj.scale = bits(2.0f);
        add(tn, frame_bt(0.0f, "spacing", 1.5f));
        add(pn, tn);
        add(paths, pn);
        obs.set_n = 0;
        obs.lookup_ret[obs.lookup_n] = pc;

        CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj)
           == PATH_TL_REACHED_DEFORM, "spacing run returns 1");
        CK(obs.create_n[K_SPA] >= 1 && obs.create_frames[K_SPA] == 1,
           "the spacing branch creates the SPACING timeline (0x28e540)");
        CK(last_tl(K_SPA)->type == 12u && last_tl(K_SPA)->frameFloatCount == 2,
           "the spacing creator passes type 12 and two floats per frame (0x283040/0x283044)");
        CK(obs.set_value[0] == want[k],
           "spacingMode 0/1 scale, 2/3/negative do not (0x28e550 bls is unsigned)");
    }
    CK(obs.create_n[K_POS] == 0, "no position timeline is created for a spacing key");
    pass("spacing_mode_matrix");
}

/* ================================================================== */
/* 13. the value key is the timeline node's own name, not a literal    */
/* ================================================================== */
static void value_key_is_timeline_name(void)
{
    tl_begin("value_key_is_timeline_name");
    /* both keys present on one frame, at different values */
    for (int k = 0; k < 2; ++k) {
        spPathConstraintDataPathShape *pc = pc_record();
        void *raw[1] = { pc };
        spSkeletonData *d = make_data(1, raw);
        spAnimationPathShape *a = make_animation();
        Json *paths = node("paths");
        Json *pn = node("c");
        Json *tn = tl_node(k == 0 ? "position" : "spacing", 1);
        Json *f = node(0);

        pc->positionMode = 1;          /* no scaling: read the raw values */
        pc->spacingMode = 2;
        add(f, num_key("time", 0.0f));
        add(f, num_key("position", 2.0f));
        add(f, num_key("spacing", 9.0f));
        add(tn, f);
        add(pn, tn);
        add(paths, pn);
        obs.set_n = 0;
        obs.lookup_ret[obs.lookup_n] = pc;

        CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj)
           == PATH_TL_REACHED_DEFORM, "both sub-key names reach the deform block");
        CK(obs.set_value[0] == (k == 0 ? 0x40000000u : 0x41100000u),
           "the value key is timelineNode->name (0x28dfb8 mov r1,r6), not a literal");
    }
    pass("value_key_is_timeline_name");
}

/* ================================================================== */
/* 14. frame defaults                                                  */
/* ================================================================== */
static void frame_defaults(void)
{
    tl_begin("frame_defaults");
    spPathConstraintDataPathShape *pc = pc_record();
    void *raw[1] = { pc };
    spSkeletonData *d = make_data(1, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *pn = node("c");
    Json *tn = tl_node("position", 1);

    pc->positionMode = 0;
    parser_obj.scale = bits(2.0f);
    add(tn, node(0));                  /* a frame with no keys at all */
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = pc;

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "default frame run returns 1");
    CK(obs.set_n == 1 && obs.set_index[0] == 0, "a keyless frame still reaches setFrame at index 0");
    CK(obs.set_time[0] == 0u, "an absent \"time\" yields the 0.0f default (0x28dfac)");
    CK(obs.set_value[0] == 0u,
       "an absent value key yields 0.0f, and 0.0f*scale is still +0.0f");
    pass("frame_defaults");
}

/* ================================================================== */
/* 15. readCurve wiring through the real implementation                */
/* ================================================================== */
static void read_curve_paths(void)
{
    tl_begin("read_curve_paths");
    spPathConstraintDataPathShape *pc = pc_record();
    void *raw[1] = { pc };
    spSkeletonData *d = make_data(1, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *pn = node("c");
    Json *tn = tl_node("position", 2);
    Json *f0 = node(0), *f1 = node(0);
    const float curve_values[4] = { 0.1f, 0.2f, 0.3f, 0.4f };
    Json *curve_arr;

    add(f0, num_key("time", 0.0f));
    add(f0, num_key("position", 0.5f));
    add(f0, str_key("curve", "stepped"));
    add(f1, num_key("time", 1.0f));
    add(f1, num_key("position", 1.5f));
    curve_arr = floats("curve", curve_values, 4, 4);
    curve_arr->unk_08 = 5;             /* array */
    add(f1, curve_arr);
    add(tn, f0); add(tn, f1);
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = pc;

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "curve run returns 1");
    CK(obs.set_n == 2 && obs.curve_n == 2,
       "readCurve runs once per frame after setFrame");
    CK(obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \"stepped\" curve string reaches spCurveTimeline_setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches spCurveTimeline_setCurve at frame 1");
    CK(obs.curve_tl[0] == obs.last_timeline[K_POS] && obs.curve_tl[1] == obs.last_timeline[K_POS],
       "readCurve receives the same timeline pointer setFrame received");
    CK(obs.curve_args[1][0] == 0x3dcccccdu && obs.curve_args[1][1] == 0x3e4ccccdu
       && obs.curve_args[1][2] == 0x3e99999au && obs.curve_args[1][3] == 0x3ecccccd,
       "the four curve values arrive bit-exact");
    pass("read_curve_paths");
}

/* ================================================================== */
/* 16. a "mix" sub-key leaves B13 at 0x28e538                          */
/* ================================================================== */
static void mix_subkey_hands_off(void)
{
    tl_begin("mix_subkey_hands_off");
    spPathConstraintDataPathShape *pc = pc_record();
    void *raw[1] = { pc };
    spSkeletonData *d = make_data(1, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *pn = node("c");
    Json *pos = tl_node("position", 1);
    Json *mix = tl_node("mix", 1);
    Json *mf = node(0);
    spPathConstraintTimelineShape *t;

    add(pos, frame_bt(0.0f, "position", 1.0f));
    add(mf, num_key("time", 0.0f));
    add(mf, num_key("rotateMix", 0.25f));
    add(mf, num_key("translateMix", 0.75f));
    add(mix, mf);
    add(pn, pos);
    add(pn, mix);
    add(paths, pn);
    obs.lookup_ret[0] = pc;

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_HANDOFF_MIX,
       "a \"mix\" sub-key is handed to B17 at 0x28e538 (bne 0x28e8ec)");
    CK(obs.create_n[K_POS] == 1 && obs.create_n[K_SPA] == 0,
       "the position sibling before the mix key was still created");
    t = last_tl(K_POS);
    CK(t->pathConstraintIndex == 0 && obs.set_n == 1,
       "the position sibling ran its scan store, frames and tail before the handoff");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "B13 publishes nothing for the mix key itself");
    pass("mix_subkey_hands_off");
}

/* ================================================================== */
/* 17. two path constraints: cursor, duration, per-node lookup         */
/* ================================================================== */
static void two_paths_cursor_duration(void)
{
    tl_begin("two_paths_cursor_duration");
    spPathConstraintDataPathShape *ca = pc_record();
    spPathConstraintDataPathShape *cb = pc_record();
    void *raw[2] = { ca, cb };
    spSkeletonData *d = make_data(2, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *p0 = node("a");
    Json *p1 = node("b");
    Json *t0 = tl_node("position", 2);
    Json *t1 = tl_node("position", 1);

    add(t0, frame_bt(0.25f, "position", -7.0f));
    add(t0, frame_bt(0.5f, "position", -9.0f));
    add(t1, frame_bt(1.7f, "position", 4.0f));
    add(p0, t0);
    add(p1, t1);
    add(paths, p0);
    add(paths, p1);
    obs.lookup_ret[0] = ca;            /* "a" -> element 0 */
    obs.lookup_ret[1] = cb;            /* "b" -> element 1 */

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "two-constraint run returns 1");
    CK(obs.lookup_n == 2 && strcmp(obs.lookup_name[0], "a") == 0
       && strcmp(obs.lookup_name[1], "b") == 0,
       "the loop advances through the paths child list");
    CK(obs.create_n[K_POS] == 2 && obs.create_frames[K_POS] == 1,
       "each node creates its own timeline with its own declared count");
    CK(obs.set_index[2] == 0, "the frame index restarts at 0 for the second timeline");
    CK(a->timelineCount == 2 && a->timelines[0] != a->timelines[1],
       "both timelines are published at successive cursor slots");
    CK(bits(a->duration) == 0x3fd9999au,
       "duration keeps the larger last frame time (1.7 over 0.5)");
    CK(((spPathConstraintTimelineShape *)a->timelines[0])->pathConstraintIndex == 0
       && ((spPathConstraintTimelineShape *)a->timelines[1])->pathConstraintIndex == 1,
       "each constraint writes its own index into its own timeline");
    pass("two_paths_cursor_duration");
}

/* ================================================================== */
/* 18. loop driven by the child list, tail by the declared count       */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    tl_begin("declared_vs_child_count");
    spPathConstraintDataPathShape *pc = pc_record();
    void *raw[1] = { pc };
    spSkeletonData *d = make_data(1, raw);
    spAnimationPathShape *a = make_animation();
    Json *paths = node("paths");
    Json *pn = node("c");
    Json *tn = tl_node("position", 3);   /* declares 3, carries 1 */
    spPathConstraintTimelineShape *t;

    add(tn, frame_bt(0.4f, "position", 5.0f));
    add(pn, tn);
    add(paths, pn);
    obs.lookup_ret[0] = pc;

    CK(readSkeletonData_pathTimelines(paths, 0, d, a, &parser_obj) == PATH_TL_REACHED_DEFORM,
       "one-frame declared-three run returns 1");
    CK(obs.set_n == 1, "the loop follows the child list");
    CK(obs.create_frames[K_POS] == 3, "create still receives the declared count");
    t = last_tl(K_POS);
    CK(bits(t->frames[0]) == 0x3ecccccdu, "the single frame time is stored at index 0");
    CK(bits(t->frames[2]) == 0u && bits(t->frames[4]) == 0u,
       "the two unwritten frames stay zero");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[(3-1)*2] (=0, never written), not frames[0]");
    pass("declared_vs_child_count");
}

void _start(void)
{
    test = "startup"; init_heap(); fixture_install_error_reporter();
    paths_absent();
    paths_without_children();
    constraint_not_found();
    scan_element_zero();
    scan_element_middle();
    scan_element_last();
    scan_miss_leaves_cell();
    scan_index_carries();
    scan_nonpositive_count();
    position_frames_scaled();
    position_percent_unscaled();
    value_key_is_timeline_name();
    spacing_mode_matrix();
    frame_defaults();
    read_curve_paths();
    mix_subkey_hands_off();
    two_paths_cursor_duration();
    declared_vs_child_count();
    out("SUMMARY all declared path timeline family contracts passed\n");
    quit(0);
}
