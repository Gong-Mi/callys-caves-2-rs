/* Reconstructed ARM32 consumer only. Heap, libc strings, JSON nodes, the
 * mix-timeline creator/setFrame and the curve recorders are SYNTHETIC
 * providers. qemu executes our linked C, never original libyoyo bytes.
 * Original not executed; this is not an original-equivalence claim.
 *
 * Subject: B17, the path-constraint MIX timeline block of
 * spSkeletonJson_readSkeletonData (0x28b84c)
 *   0x28e8ec..0x28ea0c  73 insns, reached only from B13's
 *   0x28e538 `bne 0x28e8ec`; loop head 0x28e948; readCurve 0x28e9b0;
 *   create 0x283068 (type 13, step 3); setFrame 0x283080; key literals
 *   "time"/"rotateMix"/"translateMix"; three-float publish tail
 *   0x28e9cc..0x28ea0c back to the shared node advance 0x28e048.
 *
 * THE PUZZLE UNDER TEST: 0x28e8fc `beq 0x28e048` skips a node whose name is
 * exactly "mix" — the one name that looks like the intended key.  The fixture
 * pins BOTH directions at run time: "mix" contributes no timeline (and no
 * error, no duration change), while any other unresolved name IS loaded as a
 * mix timeline.  The tests also drive both orders inside one path node, which
 * is the only observable distinction a "continue" makes.
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getFloat / Json_getItem        c/json_interface
 *   readCurve                           c/spine_read_curve
 *   _malloc / _free / _calloc           c/spine_alloc
 *   _spSkeletonJson_setError / ReportSpineError, spAnimation_dispose, etc.
 *       are linked too (same roster as the sibling path module) so the
 *       "B17 reports nothing" assertion runs against the real error chain.
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spPathConstraintMixTimeline_create 0x283068 — records the declared count
 *     and builds a zeroed 24-byte record with the real layout: type 13,
 *     frameFloatCount = count*3, frames = count*3 floats, +0x14 SENTINEL.
 *   spPathConstraintMixTimeline_setFrame 0x283080 — stores the disassembled
 *     shape frames[i*3+0..2] = time, rotateMix, translateMix and records all
 *     five argument words (the 5th is a stack word in AAPCS).
 *   spCurveTimeline_setStepped/setCurve (0x2817c0/0x2817d8) — recorders.
 *   fixture heap/allocator roster, libc providers, hand-built Json nodes.
 *
 * SENTINEL note: 0x28e918 stores the index BEFORE the frame-list test, so no
 * path may leave the create-time word in place; the fixture starts it at
 * 0x5a5a5a5a so "the store really ran" is distinguishable even with zero
 * frames.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_path_mix.h"
#include "../../spine_read_curve/src/spine_read_curve.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 16
#define MAX_TL 8
#define SENTINEL 0x5a5a5a5a

static struct {
    int create_n;
    int create_frames;
    void *last_timeline;
    void *made[MAX_TL];
    int made_n;
    int set_n;
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    uint32_t set_rot[MAX_FRAMES];
    uint32_t set_tra[MAX_FRAMES];
    void *set_tl[MAX_FRAMES];
    int curve_n, curve_kind[MAX_FRAMES], curve_frame[MAX_FRAMES];
    void *curve_tl[MAX_FRAMES];
    uint32_t curve_args[MAX_FRAMES][4];
    int ret_n;
    int ret_kind[MAX_TL];
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

/* Custom allocator: records (bytes, line, tag) so any unexpected allocation
 * (B17 should make none of its own) is visible. */
static void *mix_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "mix allocation roster/tag");
    void *p = reserve(n);
    alloc_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
    return p;
}

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                     */
/* ------------------------------------------------------------------ */
static void *tl_reserve_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

/* The real creator tail-calls _spBaseTimeline_create(count, 13, 3, tag)
 * (0x283068: 0x28306c mov r1,#13 / 0x283070 mov r2,#3 / 0x283078 b 0x282a10):
 * +0x0c = count*3, +0x10 = calloc(count*3,4).  The double keeps that layout. */
void *spPathConstraintMixTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spPathConstraintTimelineMixShape *t = tl_reserve_zero(sizeof(*t));

    if (obs.create_n >= MAX_TL || obs.made_n >= MAX_TL)
        fail("mix create roster exhausted");
    t->type = SPINE_MIX_TIMELINE_TYPE;              /* 0x28306c mov r1,#13 */
    t->vtable = 0;
    t->curves = 0;                                  /* readCurve doubles record only */
    t->frameFloatCount = frameCount * SPINE_MIX_FRAME_STEP;  /* 0x282a70 */
    t->frames = tl_reserve_zero(n * (uint32_t)SPINE_MIX_FRAME_STEP * 4u);
    t->pathConstraintIndex = (int32_t)SENTINEL;     /* 0x28e918 must overwrite */
    ++obs.create_n;
    obs.create_frames = frameCount;
    obs.last_timeline = t;
    obs.made[obs.made_n++] = t;
    return t;
}

void spPathConstraintMixTimeline_setFrame(void *timeline, int frameIndex,
                                         float time, float rotateMix,
                                         float translateMix)
{
    spPathConstraintTimelineMixShape *t =
        (spPathConstraintTimelineMixShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * (uint32_t)SPINE_MIX_FRAME_STEP;

    if (obs.set_n >= MAX_FRAMES) fail("mix setFrame table exhausted");
    /* 0x283080 add r1,r1,r1,lsl#1 (i*3) ; 0x283094 &frames[i*3] ;
     * 0x28309c str r2,[r1] (time) ; 0x2830a4 str r3,[r0] (rotateMix) ;
     * 0x2830a0 str r4,[r0,#0x4] (translateMix, 5th stack arg). */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = rotateMix;
    t->frames[base + 2u] = translateMix;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_rot[obs.set_n] = bits(rotateMix);
    obs.set_tra[obs.set_n] = bits(translateMix);
    obs.set_tl[obs.set_n] = timeline;
    ++obs.set_n;
}

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

/* ------------------------------------------------------------------ */
/* scaffolding                                                         */
/* ------------------------------------------------------------------ */
static void tl_begin(const char *name)
{
    begin(name);                       /* resets aa/na/nf and installs a cb */
    _setDebugMalloc(mix_alloc);
    memset(&obs, 0, sizeof(obs));
    report_count = 0;
    reported[0] = report_format[0] = 0;
}

static spAnimationMixShape *make_animation(float duration)
{
    spAnimationMixShape *a = tl_reserve_zero(sizeof(*a));
    a->timelines = tl_reserve_zero(4u * MAX_TL);
    a->duration = duration;
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
/* a path sub-timeline node: name is the dispatch key, +0x0c the declared count */
static Json *tl_node(const char *name, int declared)
{
    Json *n = node(name);
    n->unk_0c = (uint32_t)declared;
    return n;
}
/* one complete mix frame: time + rotateMix + translateMix */
static Json *mix_frame(float time, float rot, float tra)
{
    Json *f = node(0);
    add(f, num_key("time", time));
    add(f, num_key("rotateMix", rot));
    add(f, num_key("translateMix", tra));
    return f;
}

static int run_node(Json *timelineNode, int32_t index, void *animation)
{
    int r = readSkeletonData_pathMixTimeline(timelineNode, index, animation);
    CK(obs.ret_n < MAX_TL, "return-code roster exhausted");
    obs.ret_kind[obs.ret_n++] = r;
    return r;
}

/* B13's dispatch, modelled exactly: "position"/"spacing" are B13's branches
 * (0x28df54 / 0x28df64), everything else leaves through 0x28e538 bne 0x28e8ec
 * and is handed to B17.  Only used for the multi-child puzzle tests. */
static void drive_b13_then_b17(Json *pathNode, int32_t index, void *animation)
{
    for (Json *n = pathNode->child; n != 0; n = n->next) {
        if (strcmp(n->name, "position") == 0 || strcmp(n->name, "spacing") == 0)
            continue;                  /* B13 owns these two names */
        (void)run_node(n, index, animation);
    }
}

/* the timeline made by the most recent create */
static spPathConstraintTimelineMixShape *last_tl(void)
{
    return (spPathConstraintTimelineMixShape *)obs.last_timeline;
}

/* ================================================================== */
/* 1. the puzzle, direction A: a node named exactly "mix" is skipped   */
/* ================================================================== */
static void mix_name_skipped(void)
{
    tl_begin("mix_name_skipped");
    spAnimationMixShape *a = make_animation(0.5f);
    Json *n = tl_node("mix", 2);

    add(n, mix_frame(0.25f, 0.5f, 0.75f));
    add(n, mix_frame(0.5f, -0.25f, 0.125f));

    CK(run_node(n, 3, a) == MIX_TL_SKIPPED,
       "a sub-key named exactly \"mix\" exits through 0x28e8fc beq 0x28e048");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.curve_n == 0,
       "\"mix\" creates no timeline, runs no setFrame and no readCurve");
    CK(a->timelineCount == 0 && a->timelines[0] == 0
       && bits(a->duration) == bits(0.5f),
       "\"mix\" publishes nothing and leaves the animation duration alone");
    CK(report_count == 0,
       "\"mix\" is skipped silently: the real error chain is never entered");
    CK(na == 0,
       "\"mix\" allocates nothing: no spine_alloc line is recorded");
    pass("mix_name_skipped");
}

/* ================================================================== */
/* 2. the puzzle, direction B: any other name IS a mix timeline         */
/* ================================================================== */
static void other_name_creates_mix(void)
{
    tl_begin("other_name_creates_mix");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("bogus", 2);
    spPathConstraintTimelineMixShape *t;

    add(n, mix_frame(0.25f, 0.5f, 0.75f));
    add(n, mix_frame(0.5f, -0.25f, 0.125f));

    CK(run_node(n, 4, a) == MIX_TL_PUBLISHED,
       "a non-\"mix\" sub-key falls through and publishes a mix timeline");
    CK(obs.create_n == 1 && obs.create_frames == 2,
       "create receives the declared count from Json+0x0c (0x28e900)");
    t = last_tl();
    CK(t->type == SPINE_MIX_TIMELINE_TYPE
       && t->frameFloatCount == 2 * SPINE_MIX_FRAME_STEP,
       "create passed type 13 and three floats per frame (0x28306c/0x283070)");
    CK(t->pathConstraintIndex == 4,
       "the [sp+0x2c] cell value is stored at timeline+0x14 (0x28e918)");
    CK(obs.set_n == 2 && obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "setFrame runs once per frame with a 0-based incrementing index");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_rot[0] == 0x3f000000u
       && obs.set_tra[0] == 0x3f400000u,
       "setFrame receives (time, rotateMix, translateMix) in AAPCS order");
    CK(obs.set_time[1] == 0x3f000000u && obs.set_rot[1] == 0xbe800000u
       && obs.set_tra[1] == 0x3e000000u,
       "the second frame's three floats arrive bit-exact");
    CK(obs.set_tl[0] == (void *)t && obs.set_tl[1] == (void *)t,
       "setFrame receives the timeline the creator returned");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "the timeline is published at the animation cursor");
    CK(bits(a->duration) == bits(0.5f),
       "duration reads frames[(declared-1)*3] = the last frame's TIME");
    pass("other_name_creates_mix");
}

/* ================================================================== */
/* 3. the puzzle, both orders inside one path node                     */
/* ================================================================== */
static void mix_between_others(void)
{
    static const char *orders[2][2] = {
        { "mix", "bogus" }, { "bogus", "mix" },
    };
    tl_begin("mix_between_others");

    for (int k = 0; k < 2; ++k) {
        spAnimationMixShape *a = make_animation(0.0f);
        Json *path = node("path");
        Json *n0 = tl_node(orders[k][0], 1);
        Json *n1 = tl_node(orders[k][1], 1);
        spPathConstraintTimelineMixShape *t;

        /* distinguishable payloads: only the non-"mix" node may land */
        add(n0, mix_frame(0.1f, 0.11f, 0.12f));
        add(n1, mix_frame(0.2f, 0.21f, 0.22f));
        add(path, n0);
        add(path, n1);
        obs.set_n = 0;
        obs.curve_n = 0;
        obs.ret_n = 0;

        drive_b13_then_b17(path, 7, a);

        CK(obs.ret_n == 2, "two sub-keys reach the dispatch (one of them B17-skipped)");
        CK(obs.create_n == 1 && obs.set_n == 1 && a->timelineCount == 1,
           "exactly one mix timeline is created from the pair");
        t = last_tl();
        CK(t->pathConstraintIndex == 7,
           "the one created timeline took the index cell 7");
        /* n0 carries 0.1, n1 carries 0.2; only the non-"mix" node may land, so
         * the expected payload depends on which slot the non-mix name took. */
        CK(obs.set_time[0] == (k == 0 ? bits(0.2f) : bits(0.1f))
           && obs.set_rot[0] == (k == 0 ? bits(0.21f) : bits(0.11f))
           && obs.set_tra[0] == (k == 0 ? bits(0.22f) : bits(0.12f)),
           "the created timeline belongs to the NON-\"mix\" node, in either order");
        CK(obs.ret_kind[k == 0 ? 0 : 1] == MIX_TL_SKIPPED
           && obs.ret_kind[k == 0 ? 1 : 0] == MIX_TL_PUBLISHED,
           "the \"mix\" child is the one that returns through 0x28e8fc");

        /* reset the per-K counters that are read cumulatively */
        obs.create_n = 0;
        obs.made_n = 0;
        obs.last_timeline = 0;
    }
    pass("mix_between_others");
}

/* ================================================================== */
/* 4. the +0x14 store runs before the frame-list NULL test             */
/* ================================================================== */
static void empty_frames_index_store(void)
{
    tl_begin("empty_frames_index_store");
    spAnimationMixShape *a = make_animation(0.75f);
    Json *n = tl_node("rotate", 2);    /* declares two frames, carries none */

    CK(run_node(n, 0x2a, a) == MIX_TL_PUBLISHED,
       "a frame-less mix node still reaches the publish tail");
    CK(obs.create_n == 1 && obs.create_frames == 2,
       "create still receives the declared count");
    CK(obs.set_n == 0 && obs.curve_n == 0,
       "the frame loop is skipped when timelineNode->child is NULL (0x28e91c)");
    CK(last_tl()->pathConstraintIndex == 0x2a,
       "the +0x14 index store runs BEFORE the NULL test (0x28e918 precedes 0x28e91c)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)last_tl(),
       "the frame-less timeline is published");
    CK(bits(a->duration) == bits(0.75f),
       "duration compares against frames[(declared-1)*3] (still 0) and keeps 0.75");
    pass("empty_frames_index_store");
}

/* ================================================================== */
/* 5. frame values, defaults and the three-float store shape           */
/* ================================================================== */
static void frame_values_and_defaults(void)
{
    tl_begin("frame_values_and_defaults");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("shear", 2);
    Json *f0 = mix_frame(0.25f, 0.5f, 0.75f);
    Json *f1 = node(0);               /* no keys at all */
    spPathConstraintTimelineMixShape *t;

    add(n, f0);
    add(n, f1);

    CK(run_node(n, 1, a) == MIX_TL_PUBLISHED, "mixed default run returns 1");
    CK(obs.set_n == 2, "both frame children reach setFrame");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_rot[0] == 0x3f000000u
       && obs.set_tra[0] == 0x3f400000u,
       "a complete frame passes its three stored floats");
    CK(obs.set_time[1] == 0u,
       "an absent \"time\" yields the 0.0f default (0x28e950 mov r2,#0)");
    CK(obs.set_rot[1] == 0x3f800000u,
       "an absent \"rotateMix\" yields the 1.0f default (0x28e960 mov r2,#1065353216)");
    CK(obs.set_tra[1] == 0x3f800000u,
       "an absent \"translateMix\" yields the 1.0f default (0x28e978 mov r2,#1065353216)");
    t = last_tl();
    CK(bits(t->frames[0]) == 0x3e800000u && bits(t->frames[1]) == 0x3f000000u
       && bits(t->frames[2]) == 0x3f400000u,
       "frame 0 stores time,rotateMix,translateMix at stride 3 (0x28309c/0x2830a4/0x2830a0)");
    CK(bits(t->frames[3]) == 0u && bits(t->frames[4]) == 0x3f800000u
       && bits(t->frames[5]) == 0x3f800000u,
       "frame 1's defaults land in the next three slots");
    CK(t->frameFloatCount == 6 && t->type == SPINE_MIX_TIMELINE_TYPE,
       "the record advertises count*3 floats and type 13");
    pass("frame_values_and_defaults");
}

/* ================================================================== */
/* 6. three frames: index sequence and per-frame stride                */
/* ================================================================== */
static void frame_index_and_stride(void)
{
    tl_begin("frame_index_and_stride");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("mixx", 3);
    spPathConstraintTimelineMixShape *t;

    add(n, mix_frame(0.1f, 0.2f, 0.3f));
    add(n, mix_frame(0.4f, 0.5f, 0.6f));
    add(n, mix_frame(0.7f, 0.8f, 0.9f));

    CK(run_node(n, 0, a) == MIX_TL_PUBLISHED, "three-frame run returns 1");
    CK(obs.set_n == 3 && obs.set_index[0] == 0 && obs.set_index[1] == 1
       && obs.set_index[2] == 2,
       "the frame index is 0,1,2 (0x28e924 clears r7, 0x28e9b8 increments)");
    t = last_tl();
    CK(bits(t->frames[6]) == 0x3f333333u && bits(t->frames[7]) == 0x3f4ccccdu
       && bits(t->frames[8]) == 0x3f666666u,
       "frame 2 occupies frames[6..8] — stride 3, not 2");
    CK(t->frameFloatCount == 9, "frameFloatCount is count*3");
    CK(bits(a->duration) == bits(0.7f),
       "duration reads frames[(3-1)*3] = frames[6], the last TIME");
    pass("frame_index_and_stride");
}

/* ================================================================== */
/* 7. readCurve wiring through the real implementation                 */
/* ================================================================== */
static void read_curve_paths(void)
{
    tl_begin("read_curve_paths");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("translate", 2);
    Json *f0 = mix_frame(0.0f, 0.5f, 0.5f);
    Json *f1 = mix_frame(1.0f, 1.5f, 1.5f);
    const float curve_values[4] = { 0.1f, 0.2f, 0.3f, 0.4f };
    Json *curve_arr;

    add(f0, str_key("curve", "stepped"));
    curve_arr = floats("curve", curve_values, 4, 4);
    curve_arr->unk_08 = 5;             /* array */
    add(f1, curve_arr);
    add(n, f0);
    add(n, f1);

    CK(run_node(n, 0, a) == MIX_TL_PUBLISHED, "curve run returns 1");
    CK(obs.set_n == 2 && obs.curve_n == 2,
       "readCurve runs once per frame after setFrame (0x28e9b0)");
    CK(obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \"stepped\" curve string reaches spCurveTimeline_setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches spCurveTimeline_setCurve at frame 1");
    CK(obs.curve_tl[0] == (void *)last_tl() && obs.curve_tl[1] == (void *)last_tl(),
       "readCurve receives the same timeline pointer setFrame received");
    CK(obs.curve_args[1][0] == 0x3dcccccdu && obs.curve_args[1][1] == 0x3e4ccccdu
       && obs.curve_args[1][2] == 0x3e99999au && obs.curve_args[1][3] == 0x3ecccccd,
       "the four curve values arrive bit-exact");
    pass("read_curve_paths");
}

/* ================================================================== */
/* 8. duration: THREE-float stride, last frame's TIME, strict max      */
/* ================================================================== */
static void duration_stride_three(void)
{
    tl_begin("duration_stride_three");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("rotate", 2);

    /* mixes are huge on purpose: a stride-2 tail would read 9.0 here */
    add(n, mix_frame(0.4f, 9.0f, 7.0f));
    add(n, mix_frame(1.7f, 8.0f, 6.0f));

    CK(run_node(n, 0, a) == MIX_TL_PUBLISHED, "duration run returns 1");
    CK(bits(a->duration) == bits(1.7f),
       "duration is frames[(2-1)*3] = 1.7 (last TIME), not frames[2] = 9.0");
    pass("duration_stride_three");
}

/* ================================================================== */
/* 9. loop follows the child list, tail uses the declared count        */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    tl_begin("declared_vs_child_count");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("rotate", 3);    /* declares 3, carries 1 */
    spPathConstraintTimelineMixShape *t;

    add(n, mix_frame(0.4f, 5.0f, 6.0f));

    CK(run_node(n, 0, a) == MIX_TL_PUBLISHED, "one-frame declared-three run returns 1");
    CK(obs.set_n == 1, "the loop follows the child list");
    CK(obs.create_frames == 3, "create still receives the declared count");
    t = last_tl();
    CK(bits(t->frames[0]) == bits(0.4f) && bits(t->frames[1]) == bits(5.0f)
       && bits(t->frames[2]) == bits(6.0f),
       "the single frame is stored at index 0");
    CK(bits(t->frames[6]) == 0u && bits(t->frames[7]) == 0u
       && bits(t->frames[8]) == 0u,
       "the two unwritten frames stay zero");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[(3-1)*3] (=0, never written), not frames[0]");
    pass("declared_vs_child_count");
}

/* ================================================================== */
/* 10. duration only grows, and only on a strict greater-than          */
/* ================================================================== */
static void duration_max(void)
{
    tl_begin("duration_max");
    spAnimationMixShape *a = make_animation(5.0f);
    Json *n1 = tl_node("a", 1);
    Json *n2 = tl_node("b", 1);
    Json *n3 = tl_node("c", 1);

    add(n1, mix_frame(1.7f, 0.0f, 0.0f));
    add(n2, mix_frame(1.0f, 0.0f, 0.0f));
    add(n3, mix_frame(2.0f, 0.0f, 0.0f));

    CK(run_node(n1, 0, a) == MIX_TL_PUBLISHED, "first duration run returns 1");
    CK(bits(a->duration) == bits(5.0f),
       "a smaller last frame (1.7) leaves the pre-set duration 5.0 alone");
    a->duration = 0.2f;
    CK(run_node(n2, 0, a) == MIX_TL_PUBLISHED, "second duration run returns 1");
    CK(bits(a->duration) == bits(1.0f),
       "a larger last frame (1.0 over 0.2) replaces the duration");
    CK(run_node(n3, 0, a) == MIX_TL_PUBLISHED, "third duration run returns 1");
    CK(bits(a->duration) == bits(2.0f),
       "the third timeline extends the duration again (2.0 over 1.0)");
    CK(a->timelineCount == 3 && a->timelines[0] != a->timelines[1]
       && a->timelines[1] != a->timelines[2],
       "each publish consumes the next cursor slot");
    pass("duration_max");
}

/* ================================================================== */
/* 11. the index cell: hit values, stale values, and the skip          */
/* ================================================================== */
static void index_cell_values(void)
{
    static const int32_t cells[3] = { 0, 2, 0x7fffffff };
    tl_begin("index_cell_values");

    for (unsigned k = 0; k < 3; ++k) {
        spAnimationMixShape *a = make_animation(0.0f);
        Json *n = tl_node("rotate", 1);
        add(n, mix_frame(0.0f, 0.5f, 0.5f));
        obs.create_n = 0;
        obs.made_n = 0;
        obs.set_n = 0;
        CK(run_node(n, cells[k], a) == MIX_TL_PUBLISHED,
           "a non-mix node with a cell value returns 1");
        CK(last_tl()->pathConstraintIndex == cells[k],
           "the [sp+0x2c] cell is stored verbatim, including stale hit/miss values");
    }
    {
        spAnimationMixShape *a = make_animation(0.0f);
        Json *mix = tl_node("mix", 1);
        add(mix, mix_frame(0.0f, 0.5f, 0.5f));
        obs.create_n = 0;
        obs.made_n = 0;
        obs.last_timeline = 0;
        CK(run_node(mix, 0x2a, a) == MIX_TL_SKIPPED,
           "a \"mix\" node with the same cell value is still skipped");
        CK(obs.create_n == 0 && obs.last_timeline == 0 && a->timelineCount == 0,
           "the skipped node stores nothing and publishes nothing");
    }
    pass("index_cell_values");
}

/* ================================================================== */
/* 12. the key literals are exact: decoys never match                  */
/* ================================================================== */
static void key_literals_exact(void)
{
    tl_begin("key_literals_exact");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *n = tl_node("rotate", 2);
    Json *decoy = node(0);
    Json *real = node(0);

    add(decoy, num_key("timex", 7.0f));
    add(decoy, num_key("rotateMixx", 8.0f));
    add(decoy, num_key("translateMixx", 9.0f));
    add(decoy, num_key("mix", 10.0f));
    add(real, num_key("time", 0.5f));
    add(real, num_key("rotateMix", 0.25f));
    add(real, num_key("translateMix", 0.75f));
    add(n, decoy);
    add(n, real);

    CK(run_node(n, 0, a) == MIX_TL_PUBLISHED, "decoy run returns 1");
    CK(obs.set_time[0] == 0u && obs.set_rot[0] == 0x3f800000u
       && obs.set_tra[0] == 0x3f800000u,
       "decoy keys do not match: \"time\"/\"rotateMix\"/\"translateMix\" are exact literals");
    CK(obs.set_time[1] == 0x3f000000u && obs.set_rot[1] == 0x3e800000u
       && obs.set_tra[1] == 0x3f400000u,
       "the exact keys on the next frame are read normally");
    pass("key_literals_exact");
}

/* ================================================================== */
/* 13. a skipped mix node does not consume a cursor slot or index      */
/* ================================================================== */
static void skip_is_transparent(void)
{
    tl_begin("skip_is_transparent");
    spAnimationMixShape *a = make_animation(0.0f);
    Json *mix = tl_node("mix", 1);
    Json *pos = tl_node("position", 1);   /* B13's, not ours */
    Json *oth = tl_node("bogus", 1);

    add(mix, mix_frame(0.9f, 0.9f, 0.9f));
    add(pos, mix_frame(0.8f, 0.8f, 0.8f));
    add(oth, mix_frame(0.1f, 0.2f, 0.3f));

    CK(run_node(mix, 0, a) == MIX_TL_SKIPPED, "the mix node is skipped");
    CK(run_node(oth, 1, a) == MIX_TL_PUBLISHED, "the other node publishes");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)last_tl(),
       "the skipped node consumed no cursor slot: the other timeline is at 0");
    CK(bits(a->duration) == bits(0.1f),
       "the skipped node's 0.9 never reaches the duration");
    CK(obs.set_n == 1 && obs.set_time[0] == bits(0.1f),
       "only the other node's frame reached setFrame");
    (void)pos;                         /* B13 would have consumed it before us */
    pass("skip_is_transparent");
}

void _start(void)
{
    test = "startup"; init_heap(); fixture_install_error_reporter();
    mix_name_skipped();
    other_name_creates_mix();
    mix_between_others();
    empty_frames_index_store();
    frame_values_and_defaults();
    frame_index_and_stride();
    read_curve_paths();
    duration_stride_three();
    declared_vs_child_count();
    duration_max();
    index_cell_values();
    key_literals_exact();
    skip_is_transparent();
    out("SUMMARY all declared path-mix timeline family contracts passed\n");
    quit(0);
}
