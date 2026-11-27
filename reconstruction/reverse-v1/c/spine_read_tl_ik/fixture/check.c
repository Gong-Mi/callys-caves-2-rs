/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the ik lookup and the two timeline entry points are SYNTHETIC providers.
 * qemu executes our linked C, never original libyoyo bytes.  Original not
 * executed; this is not an original-equivalence claim.
 *
 * Subject: the ik-constraint timeline family of spSkeletonJson_readSkeletonData
 *   B7   0x28d840..0x28d8dc  (ik loop head + create + pointer linear scan)
 *   B7b  0x28dbd0..0x28dca8  (frame loop + setFrame + readCurve + tail)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getFloat / Json_getInt   json_interface
 *   readCurve                     spine_read_curve
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spSkeletonData_findIkConstraint 0x28b238 — returns a scripted per-call
 *     pointer (NULL allowed) and records the name it was asked for, so both
 *     "B7 never null-tests the result" and "the key is the JSON member key"
 *     are observable.
 *   spIkConstraintTimeline_create  0x282f74 — record double with a 24-byte
 *     shape; +0x14 is filled with SENTINEL, a fixture device (see below).
 *   spIkConstraintTimeline_setFrame 0x282f8c — stores the disassembled shape
 *     (frames[i*3] = time, [i*3+1] = mix, [i*3+2] = (float)(int)bend) and
 *     records every argument word, including the stack-passed bend enum.
 *   spCurveTimeline_setStepped/setCurve (0x2817c0/0x2817d8) — recorders.
 *   fixture heap/allocator roster, libc providers, hand-built Json nodes
 *     (node types set exactly as the real parser 0x28677c writes them).
 *
 * SENTINEL note: the original's creator is calloc(1,24,tag,233) and neither
 * _spBaseTimeline_create (0x282a10..0x282a88) nor _spCurveTimeline_init
 * (0x2816d8..0x281714) nor _spTimeline_init (0x281328..0x28135c) stores to
 * +0x14, so the original's create-time value is the calloc zero fill (0).
 * The fixture deliberately starts the word at a value that is neither 0 nor
 * -1, so that "the scan wrote nothing on a miss" is distinguishable from
 * "the scan wrote 0".
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_ik.h"
#include "../../spine_read_curve/src/spine_read_curve.h"

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 8
#define MAX_IK 8
#define SENTINEL 0x5a5a5a5a

static struct {
    int create_n;
    int create_frames[MAX_IK];
    int set_n;
    int set_index[MAX_FRAMES * MAX_IK];
    uint32_t set_time[MAX_FRAMES * MAX_IK];
    uint32_t set_mix[MAX_FRAMES * MAX_IK];
    int set_bend[MAX_FRAMES * MAX_IK];
    int curve_n, curve_kind[MAX_FRAMES], curve_frame[MAX_FRAMES];
    void *curve_tl[MAX_FRAMES];
    uint32_t curve_args[MAX_FRAMES][4];
    void *lookup_ret[MAX_IK];         /* scripted findIkConstraint result */
    int lookup_n;
    const char *lookup_name[MAX_IK];
    void *last_timeline;
} obs;

/* only here so the record has a plausible +0x04 word; this family never walks
 * the vtable (no dispose call site exists in B7/B7b). */
static uint32_t tl_vtable_words[2];

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                      */
/* ------------------------------------------------------------------ */
static void *tz_reserve(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

void *spSkeletonData_findIkConstraint(void *data, const char *name)
{
    void *r;
    (void)data;
    if (obs.lookup_n >= MAX_IK) fail("ik lookup roster exhausted");
    r = obs.lookup_ret[obs.lookup_n];
    obs.lookup_name[obs.lookup_n] = name;
    ++obs.lookup_n;
    return r;                          /* may be NULL: B7 does not test it */
}

void *spIkConstraintTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spIkConstraintTimelineShape *t = tz_reserve(sizeof(*t));
    if (obs.create_n >= MAX_IK) fail("ik create roster exhausted");
    t->type = 0x09u;                   /* 0x282f78 mov r1,#9 */
    t->vtable = tl_vtable_words;
    t->curves = 0;
    t->frameFloatCount = frameCount * 3;    /* 0x282a60 mul r0,r7,r5, step 3 */
    t->frames = tz_reserve(n * 3u * 4u);    /* 0x282a78 str r0,[r4,#0x10] */
    t->ikConstraintIndex = (int32_t)SENTINEL;
    obs.create_frames[obs.create_n] = frameCount;
    ++obs.create_n;
    obs.last_timeline = t;
    return t;
}

void spIkConstraintTimeline_setFrame(void *timeline, int frameIndex,
                                     float time, float mix, int bend)
{
    spIkConstraintTimelineShape *t = (spIkConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 3u;
    if (obs.set_n >= (int)(sizeof(obs.set_index) / sizeof(obs.set_index[0])))
        fail("ik setFrame table exhausted");
    /* 0x282f94 add r1,r1,r1,lsl#1 / 0x282fa8 str r2,[r1] /
     * 0x282fac str r3,[r0] / 0x282fb0 vstr s15,[r0,#4]  (s15 = (float)bend) */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = mix;
    t->frames[base + 2u] = (float)bend;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_mix[obs.set_n] = bits(mix);
    obs.set_bend[obs.set_n] = bend;
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
static void ik_begin(const char *name)
{
    begin(name);                       /* resets aa/na/nf and installs a cb */
    memset(&obs, 0, sizeof(obs));
    tl_vtable_words[0] = 0u;
    tl_vtable_words[1] = 0xdeadbeefu;
}

/* the array element identity: the tests only compare pointers, never deref */
static void *constraint_record(const char *name)
{
    return (void *)(uintptr_t)name;
}

/* spSkeletonData is calloc(1,84,tag,37) in the original (0x28ade4); the two
 * words this family reads are +0x3c (count) and +0x40 (array). */
static spSkeletonDataIkShape *make_data(int32_t count, void **array)
{
    spSkeletonDataIkShape *d = tz_reserve(sizeof(*d));
    d->ikConstraintsCount = count;
    d->ikConstraints = array;
    return d;
}

static spAnimationIkShape *make_animation(void)
{
    spAnimationIkShape *a = tz_reserve(sizeof(*a));
    a->timelines = tz_reserve(4u * MAX_IK);
    return a;
}

/* Json helpers: node types match the parser's enum (json_interface). */
static Json *str_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->unk_08 = 4;                     /* string */
    n->string_value = value;
    return n;
}
static Json *num_key(const char *key, float value)
{
    Json *n = node(key);
    n->unk_08 = 3;                     /* number */
    n->float_value = value;
    return n;
}
static Json *int_key(const char *key, int32_t value)
{
    Json *n = node(key);
    n->unk_08 = 3;                     /* number node carrying the int field */
    n->int_value = value;
    return n;
}
static Json *ik_node(const char *name, int declared)
{
    Json *n = node(name);              /* name is the JSON member key (+0x1c) */
    n->unk_0c = (uint32_t)declared;
    return n;
}
/* one frame object with a "time" key only */
static Json *plain_frame(float t)
{
    Json *f = node(0);
    add(f, num_key("time", t));
    return f;
}

/* ================================================================== */
/* 1. no "ik" member at all                                            */
/* ================================================================== */
static void map_absent(void)
{
    ik_begin("map_absent");
    spSkeletonDataIkShape *d = make_data(2, 0);
    spAnimationIkShape *a = make_animation();

    CK(readSkeletonData_ikTimelines(0, d, a) == 1,
       "B7 with a NULL ik node falls through to the transform block");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.lookup_n == 0,
       "B7 with a NULL ik node never looks up, creates or reads frames");
    CK(a->timelineCount == 0, "B7 with a NULL ik node publishes nothing");
    CK(d->ikConstraintsCount == 2, "B7 with a NULL ik node never touches the ik vector");
    pass("map_absent");
}

/* ================================================================== */
/* 2. "ik" member present but empty                                    */
/* ================================================================== */
static void map_without_constraints(void)
{
    ik_begin("map_without_constraints");
    spSkeletonDataIkShape *d = make_data(3, 0);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");                       /* no children */

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1,
       "B7 with an empty ik object returns to the transform block");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.lookup_n == 0,
       "B7 with an empty ik object creates no timeline");
    CK(a->timelineCount == 0, "B7 with an empty ik object publishes nothing");
    pass("map_without_constraints");
}

/* ================================================================== */
/* 3/4/5. the scan finds the element at position 0 / 2 / 4             */
/* ================================================================== */
static void scan_at(const char *name, int want, const char *why)
{
    static const char *const elements[5] = { "e0", "e1", "e2", "e3", "e4" };
    void *array[5];
    spSkeletonDataIkShape *d;
    spAnimationIkShape *a;
    Json *ik, *cn;
    spIkConstraintTimelineShape *t;

    ik_begin(name);
    for (int i = 0; i < 5; ++i) array[i] = constraint_record(elements[i]);
    d = make_data(5, array);
    a = make_animation();
    ik = node("ik");
    cn = ik_node("c0", 2);
    add(cn, plain_frame(0.0f));
    add(cn, plain_frame(0.5f));
    add(ik, cn);
    obs.lookup_ret[0] = array[want];

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "scan run returns 1");
    CK(obs.lookup_n == 1, "one findIkConstraint call per constraint node");
    CK(strcmp(obs.lookup_name[0], "c0") == 0,
       "findIkConstraint receives the JSON member key at +0x1c");
    CK(obs.create_n == 1 && obs.create_frames[0] == 2,
       "create receives the declared frame count from Json+0x0c");
    t = (spIkConstraintTimelineShape *)obs.last_timeline;
    CK(t->ikConstraintIndex == want, why);
    CK(obs.set_n == 2, "the frame loop still runs after a successful scan");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "the timeline is published at the animation cursor");
    pass(name);
}

static void scan_element_zero(void)
{
    scan_at("scan_element_zero", 0,
            "a hit on ikConstraints[0] stores index 0 (0x28dbc8 clears r3)");
}
static void scan_element_middle(void)
{
    scan_at("scan_element_middle", 2,
            "a hit on ikConstraints[2] stores index 2");
}
static void scan_element_last(void)
{
    scan_at("scan_element_last", 4,
            "a hit on the last element stores index 4");
}

/* ================================================================== */
/* 6. the scan misses                                                  */
/* ================================================================== */
static void scan_miss(void)
{
    ik_begin("scan_miss");
    void *array[3] = { constraint_record("a"), constraint_record("b"),
                       constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(3, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("nope", 1);
    spIkConstraintTimelineShape *t;

    add(n, plain_frame(0.25f));
    add(ik, n);
    obs.lookup_ret[0] = constraint_record("missing");   /* not in the array */

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "miss run returns 1");
    CK(obs.create_n == 1, "the timeline is created before the scan");
    t = (spIkConstraintTimelineShape *)obs.last_timeline;
    CK(t->ikConstraintIndex == (int32_t)SENTINEL,
       "a miss stores nothing and +0x14 keeps the create-time value");
    CK(obs.set_n == 1, "a miss still reads the frames (0x28d8d8 -> 0x28dbd0)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "a miss still publishes the timeline");
    pass("scan_miss");
}

/* ================================================================== */
/* 7. the count is signed and the array is not read when count <= 0     */
/* ================================================================== */
static void scan_nonpositive_count(void)
{
    ik_begin("scan_nonpositive_count");
    void *array1[1] = { constraint_record("only") };
    Json *ik = node("ik");
    Json *n = ik_node("only", 1);
    add(n, plain_frame(0.0f));
    add(ik, n);
    obs.lookup_ret[0] = array1[0];      /* would match if the scan ran */

    /* count == 0, array NULL: the +0x40 word is never read */
    {
        spSkeletonDataIkShape *d = make_data(0, 0);
        spAnimationIkShape *a = make_animation();
        CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "count 0 run returns 1");
        CK(((spIkConstraintTimelineShape *)obs.last_timeline)->ikConstraintIndex
           == (int32_t)SENTINEL,
           "count 0 skips the scan even with a NULL array");
        CK(obs.set_n == 1 && a->timelineCount == 1,
           "count 0 still reaches the frame loop and the tail");
    }
    /* count == -1, array[0] would match: the compare is signed `ble` */
    {
        spSkeletonDataIkShape *d = make_data(-1, array1);
        spAnimationIkShape *a = make_animation();
        obs.set_n = 0;
        CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "count -1 run returns 1");
        CK(((spIkConstraintTimelineShape *)obs.last_timeline)->ikConstraintIndex
           == (int32_t)SENTINEL,
           "a negative count skips the scan (ble, not bne)");
        CK(obs.set_n == 1, "count -1 still reaches the frame loop");
    }
    pass("scan_nonpositive_count");
}

/* ================================================================== */
/* 8. the lookup result is never null-tested                           */
/* ================================================================== */
static void lookup_null_matches_null_slot(void)
{
    ik_begin("lookup_null_matches_null_slot");
    void *array[3] = { constraint_record("a"), 0, constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(3, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("absent", 1);
    add(n, plain_frame(0.0f));
    add(ik, n);
    obs.lookup_ret[0] = 0;              /* findIkConstraint miss -> NULL */

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "NULL lookup run returns 1");
    CK(obs.lookup_n == 1 && obs.lookup_ret[0] == 0,
       "findIkConstraint is allowed to return NULL and B7 does not branch on it");
    CK(((spIkConstraintTimelineShape *)obs.last_timeline)->ikConstraintIndex == 1,
       "NULL equals the NULL array slot, so index 1 is written");
    CK(obs.set_n == 1, "the frame loop runs regardless of the lookup result");

    /* the same NULL lookup against an array without a NULL slot simply misses */
    {
        void *array2[2] = { constraint_record("a"), constraint_record("b") };
        spSkeletonDataIkShape *d2 = make_data(2, array2);
        spAnimationIkShape *a2 = make_animation();
        obs.set_n = 0;
        CK(readSkeletonData_ikTimelines(ik, d2, a2) == 1, "second NULL lookup returns 1");
        CK(((spIkConstraintTimelineShape *)obs.last_timeline)->ikConstraintIndex
           == (int32_t)SENTINEL,
           "a NULL lookup with no NULL slot leaves +0x14 alone");
    }
    pass("lookup_null_matches_null_slot");
}

/* ================================================================== */
/* 9. frame defaults                                                   */
/* ================================================================== */
static void frame_defaults(void)
{
    ik_begin("frame_defaults");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(1, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("c", 1);
    add(n, node(0));                   /* a frame with no keys at all */
    add(ik, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "default frame run returns 1");
    CK(obs.set_n == 1, "a keyless frame still reaches setFrame");
    CK(obs.set_index[0] == 0, "the first frame index is 0");
    CK(obs.set_time[0] == 0u,
       "an absent \"time\" yields the 0.0f default");
    CK(obs.set_mix[0] == 0x3f800000u,
       "an absent \"mix\" yields the 1.0f default (0x28dbf4 mov r2,#1065353216)");
    CK(obs.set_bend[0] == 1,
       "an absent \"bendPositive\" yields the 1 default (0x28dc08)");
    pass("frame_defaults");
}

/* ================================================================== */
/* 10. frame values, index sequence, bend polarity, store shape         */
/* ================================================================== */
static void frame_values_and_bend(void)
{
    ik_begin("frame_values_and_bend");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(1, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("c", 3);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0);
    spIkConstraintTimelineShape *t;

    add(f0, num_key("time", 0.25f));
    add(f0, num_key("mix", 0.5f));
    add(f0, int_key("bendPositive", 0));
    add(f1, num_key("time", 1.5f));
    add(f1, num_key("mix", 2.0f));
    add(f1, int_key("bendPositive", 5));
    add(f2, num_key("time", 2.5f));    /* no mix, no bendPositive */
    add(n, f0); add(n, f1); add(n, f2);
    add(ik, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "three-frame run returns 1");
    CK(obs.set_n == 3, "one setFrame per frame child");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1 && obs.set_index[2] == 2,
       "the frame index starts at 0 and increments per frame");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_time[1] == 0x3fc00000u
       && obs.set_time[2] == 0x40200000u,
       "setFrame receives the frame \"time\" bits");
    CK(obs.set_mix[0] == 0x3f000000u && obs.set_mix[1] == 0x40000000u,
       "setFrame receives the frame \"mix\" bits");
    CK(obs.set_bend[0] == -1 && obs.set_bend[1] == 1 && obs.set_bend[2] == 1,
       "bendPositive 0 -> -1, any non-zero -> +1 (0x28dc24..0x28dc30)");

    t = (spIkConstraintTimelineShape *)obs.last_timeline;
    CK(t->frames[0] == 0.25f && t->frames[1] == 0.5f && t->frames[2] == -1.0f,
       "frame 0 stores time, mix and (float)-1 at stride 3");
    CK(t->frames[3] == 1.5f && t->frames[4] == 2.0f && t->frames[5] == 1.0f,
       "frame 1 stores the (float)(int)5 bend as 1.0");
    CK(bits(t->frames[6]) == 0x40200000u && bits(t->frames[7]) == 0x3f800000u
       && bits(t->frames[8]) == 0x3f800000u,
       "frame 2 falls back to mix 1.0 and bend 1.0");
    pass("frame_values_and_bend");
}

/* ================================================================== */
/* 11. readCurve wiring through the real implementation                 */
/* ================================================================== */
static void read_curve_paths(void)
{
    ik_begin("read_curve_paths");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(1, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("c", 2);
    Json *f0 = node(0), *f1 = node(0);
    const float curve_values[4] = { 0.1f, 0.2f, 0.3f, 0.4f };
    Json *curve_arr;

    add(f0, num_key("time", 0.0f));
    add(f0, str_key("curve", "stepped"));
    add(f1, num_key("time", 1.0f));
    curve_arr = floats("curve", curve_values, 4, 4);
    curve_arr->unk_08 = 5;             /* array */
    add(f1, curve_arr);
    add(n, f0); add(n, f1);
    add(ik, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "curve run returns 1");
    CK(obs.set_n == 2 && obs.curve_n == 2,
       "readCurve runs once per frame after setFrame");
    CK(obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \"stepped\" curve string reaches spCurveTimeline_setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches spCurveTimeline_setCurve at frame 1");
    CK(obs.curve_tl[0] == obs.last_timeline && obs.curve_tl[1] == obs.last_timeline,
       "readCurve receives the same timeline pointer setFrame received");
    CK(obs.curve_args[1][0] == 0x3dcccccdu && obs.curve_args[1][1] == 0x3e4ccccdu
       && obs.curve_args[1][2] == 0x3e99999au && obs.curve_args[1][3] == 0x3ecccccd,
       "the four curve values arrive bit-exact");
    pass("read_curve_paths");
}

/* ================================================================== */
/* 12. two constraints: cursor, duration, per-node lookup                */
/* ================================================================== */
static void two_constraints(void)
{
    ik_begin("two_constraints");
    void *array[2] = { constraint_record("a"), constraint_record("b") };
    spSkeletonDataIkShape *d = make_data(2, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n0 = ik_node("a", 1);
    Json *n1 = ik_node("b", 2);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0);

    add(f0, num_key("time", 0.4f));
    add(n0, f0);
    add(f1, num_key("time", 0.9f));
    add(f2, num_key("time", 1.7f));
    add(n1, f1); add(n1, f2);
    add(ik, n0); add(ik, n1);          /* sibling list the parent walks */
    obs.lookup_ret[0] = array[0];      /* node "a" -> ikConstraints[0] */
    obs.lookup_ret[1] = array[1];      /* node "b" -> ikConstraints[1] */

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "two-constraint run returns 1");
    CK(obs.lookup_n == 2, "one lookup per ik constraint node");
    CK(strcmp(obs.lookup_name[0], "a") == 0 && strcmp(obs.lookup_name[1], "b") == 0,
       "the loop advances through the ik child list");
    CK(obs.create_n == 2 && obs.create_frames[0] == 1 && obs.create_frames[1] == 2,
       "each node creates its own timeline with its own count");
    CK(obs.set_n == 3 && obs.set_index[1] == 0 && obs.set_index[2] == 1,
       "the frame index restarts at 0 for the second timeline");
    CK(a->timelineCount == 2 && a->timelines[0] != a->timelines[1],
       "both timelines are published at successive cursor slots");
    CK(bits(a->duration) == 0x3fd9999au,
       "duration keeps the larger last frame time (1.7 over 0.4)");
    CK(((spIkConstraintTimelineShape *)a->timelines[0])->ikConstraintIndex == 0
       && ((spIkConstraintTimelineShape *)a->timelines[1])->ikConstraintIndex == 1,
       "each constraint writes its own index into its own timeline");
    pass("two_constraints");
}

/* ================================================================== */
/* 13. loop driven by the child list, tail by the declared count        */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    ik_begin("declared_vs_child_count");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataIkShape *d = make_data(1, array);
    spAnimationIkShape *a = make_animation();
    Json *ik = node("ik");
    Json *n = ik_node("c", 3);         /* declares 3, carries 1 */
    spIkConstraintTimelineShape *t;

    add(n, plain_frame(0.4f));
    add(ik, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_ikTimelines(ik, d, a) == 1, "one-frame declared-three run returns 1");
    CK(obs.set_n == 1, "the loop follows the child list");
    CK(obs.create_frames[0] == 3, "create still receives the declared count");
    t = (spIkConstraintTimelineShape *)obs.last_timeline;
    CK(bits(t->frames[0]) == 0x3ecccccdu, "the single frame time is stored at index 0");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[(3-1)*3] (=0, never written), not frames[0]");
    pass("declared_vs_child_count");
}

void _start(void)
{
    test = "startup"; init_heap();
    map_absent();
    map_without_constraints();
    scan_element_zero();
    scan_element_middle();
    scan_element_last();
    scan_miss();
    scan_nonpositive_count();
    lookup_null_matches_null_slot();
    frame_values_and_bend();
    frame_defaults();
    read_curve_paths();
    two_constraints();
    declared_vs_child_count();
    out("SUMMARY all declared ik timeline family contracts passed\n");
    quit(0);
}
