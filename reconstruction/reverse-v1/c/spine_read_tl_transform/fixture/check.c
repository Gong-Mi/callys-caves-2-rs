/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the transform lookup and the two timeline entry points are SYNTHETIC
 * providers.  qemu executes our linked C, never original libyoyo bytes.
 * Original not executed; this is not an original-equivalence claim.
 *
 * Subject: the transform-constraint timeline family of
 * spSkeletonJson_readSkeletonData
 *   B12  0x28dca8..0x28de74  (loop head + create + pointer linear scan +
 *                             five-key frame loop + setFrame + readCurve +
 *                             publish/duration tail)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getFloat   json_interface
 *   readCurve       spine_read_curve
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spSkeletonData_findTransformConstraint 0x28b294 — returns a scripted
 *     per-call pointer (NULL allowed) and records the name it was asked for,
 *     so both "B12 never null-tests the result" and "the key is the JSON
 *     member key" are observable.
 *   spTransformConstraintTimeline_create  0x282fb8 — record double with a
 *     24-byte shape; +0x14 is filled with SENTINEL, a fixture device.
 *   spTransformConstraintTimeline_setFrame 0x282fd0 — stores the
 *     disassembled shape (frames[i*5+0] = time, +1 = rotateMix,
 *     +2 = translateMix, +3 = scaleMix, +4 = shearMix) and records every
 *     argument word, including the three stack-passed mix values.
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

#include "spine_read_tl_transform.h"
#include "../../spine_read_curve/src/spine_read_curve.h"

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 8
#define MAX_NODES 8
#define MAX_SETS (MAX_FRAMES * MAX_NODES)
#define SENTINEL 0x5a5a5a5a

static struct {
    int create_n;
    int create_frames[MAX_NODES];
    int set_n;
    int set_index[MAX_SETS];
    uint32_t set_time[MAX_SETS];
    uint32_t set_rotate[MAX_SETS];
    uint32_t set_translate[MAX_SETS];
    uint32_t set_scale[MAX_SETS];
    uint32_t set_shear[MAX_SETS];
    int curve_n, curve_kind[MAX_SETS], curve_frame[MAX_SETS];
    void *curve_tl[MAX_SETS];
    uint32_t curve_args[MAX_SETS][4];
    void *lookup_ret[MAX_NODES];         /* scripted findTransformConstraint result */
    int lookup_n;
    const char *lookup_name[MAX_NODES];
    void *last_timeline;
} obs;

/* only here so the record has a plausible +0x04 word; this family never walks
 * the vtable (no dispose call site exists in B12). */
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

void *spSkeletonData_findTransformConstraint(void *data, const char *name)
{
    void *r;
    (void)data;
    if (obs.lookup_n >= MAX_NODES) fail("transform lookup roster exhausted");
    r = obs.lookup_ret[obs.lookup_n];
    obs.lookup_name[obs.lookup_n] = name;
    ++obs.lookup_n;
    return r;                          /* may be NULL: B12 does not test it */
}

void *spTransformConstraintTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spTransformConstraintTimelineShape *t = tz_reserve(sizeof(*t));
    if (obs.create_n >= MAX_NODES) fail("transform create roster exhausted");
    t->type = 0x0Au;                   /* 0x282fbc mov r1,#10 */
    t->vtable = tl_vtable_words;
    t->curves = 0;
    t->frameFloatCount = frameCount * 5;    /* 0x282fc0 mov r2,#5 ; 0x282a60 mul */
    t->frames = tz_reserve(n * 5u * 4u);    /* 0x282a78 str r0,[r4,#0x10] */
    t->transformConstraintIndex = (int32_t)SENTINEL;
    obs.create_frames[obs.create_n] = frameCount;
    ++obs.create_n;
    obs.last_timeline = t;
    return t;
}

void spTransformConstraintTimeline_setFrame(void *timeline, int frameIndex,
                                            float time, float rotateMix,
                                            float translateMix, float scaleMix,
                                            float shearMix)
{
    spTransformConstraintTimelineShape *t = (spTransformConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 5u;   /* 0x282fd0 add r1,r1,r1,lsl#2 */
    if (obs.set_n >= MAX_SETS) fail("transform setFrame table exhausted");
    /* 0x282ff4 str r2,[r1] / 0x283000 str r3,[r0] / 0x282ff8 str r5,[r0,#4] /
     * 0x282ffc str r4,[r0,#8] / 0x283004 str r12,[r0,#0xc] */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = rotateMix;
    t->frames[base + 2u] = translateMix;
    t->frames[base + 3u] = scaleMix;
    t->frames[base + 4u] = shearMix;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_rotate[obs.set_n] = bits(rotateMix);
    obs.set_translate[obs.set_n] = bits(translateMix);
    obs.set_scale[obs.set_n] = bits(scaleMix);
    obs.set_shear[obs.set_n] = bits(shearMix);
    ++obs.set_n;
}

void spCurveTimeline_setStepped(void *curveTimeline, int frameIndex)
{
    if (obs.curve_n >= MAX_SETS) fail("curve table exhausted");
    obs.curve_kind[obs.curve_n] = 1;
    obs.curve_frame[obs.curve_n] = frameIndex;
    obs.curve_tl[obs.curve_n] = curveTimeline;
    ++obs.curve_n;
}

void spCurveTimeline_setCurve(void *curveTimeline, int frameIndex,
                              float cx1, float cy1, float cx2, float cy2)
{
    if (obs.curve_n >= MAX_SETS) fail("curve table exhausted");
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
static void tf_begin(const char *name)
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
 * words this family reads are +0x44 (count) and +0x48 (array). */
static spSkeletonDataTransformShape *make_data(int32_t count, void **array)
{
    spSkeletonDataTransformShape *d = tz_reserve(sizeof(*d));
    d->transformConstraintsCount = count;
    d->transformConstraints = array;
    return d;
}

static spAnimationTransformShape *make_animation(void)
{
    spAnimationTransformShape *a = tz_reserve(sizeof(*a));
    a->timelines = tz_reserve(4u * MAX_NODES);
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
static Json *tf_node(const char *name, int declared)
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
/* 1. no "transform" member at all                                     */
/* ================================================================== */
static void map_absent(void)
{
    tf_begin("map_absent");
    spSkeletonDataTransformShape *d = make_data(2, 0);
    spAnimationTransformShape *a = make_animation();

    CK(readSkeletonData_transformTimelines(0, d, a) == 1,
       "B12 with a NULL transform node falls through to the path block");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.lookup_n == 0,
       "B12 with a NULL transform node never looks up, creates or reads frames");
    CK(a->timelineCount == 0, "B12 with a NULL transform node publishes nothing");
    CK(d->transformConstraintsCount == 2,
       "B12 with a NULL transform node never touches the transform vector");
    pass("map_absent");
}

/* ================================================================== */
/* 2. "transform" member present but empty                             */
/* ================================================================== */
static void map_without_constraints(void)
{
    tf_begin("map_without_constraints");
    spSkeletonDataTransformShape *d = make_data(3, 0);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");               /* no children */

    CK(readSkeletonData_transformTimelines(map, d, a) == 1,
       "B12 with an empty transform object returns to the path block");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.lookup_n == 0,
       "B12 with an empty transform object creates no timeline");
    CK(a->timelineCount == 0, "B12 with an empty transform object publishes nothing");
    pass("map_without_constraints");
}

/* ================================================================== */
/* 3/4/5. the scan finds the element at position 0 / 2 / 4             */
/* ================================================================== */
static void scan_at(const char *name, int want, const char *why)
{
    static const char *const elements[5] = { "e0", "e1", "e2", "e3", "e4" };
    void *array[5];
    spSkeletonDataTransformShape *d;
    spAnimationTransformShape *a;
    Json *map, *cn;
    spTransformConstraintTimelineShape *t;

    tf_begin(name);
    for (int i = 0; i < 5; ++i) array[i] = constraint_record(elements[i]);
    d = make_data(5, array);
    a = make_animation();
    map = node("transform");
    cn = tf_node("c0", 2);
    add(cn, plain_frame(0.0f));
    add(cn, plain_frame(0.5f));
    add(map, cn);
    obs.lookup_ret[0] = array[want];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "scan run returns 1");
    CK(obs.lookup_n == 1, "one findTransformConstraint call per constraint node");
    CK(strcmp(obs.lookup_name[0], "c0") == 0,
       "findTransformConstraint receives the JSON member key at +0x1c");
    CK(obs.create_n == 1 && obs.create_frames[0] == 2,
       "create receives the declared frame count from Json+0x0c");
    t = (spTransformConstraintTimelineShape *)obs.last_timeline;
    CK(t->transformConstraintIndex == want, why);
    CK(obs.set_n == 2, "the frame loop still runs after a successful scan");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "the timeline is published at the animation cursor");
    pass(name);
}

static void scan_element_zero(void)
{
    scan_at("scan_element_zero", 0,
            "a hit on transformConstraints[0] stores index 0 (0x28dd60 clears r3)");
}
static void scan_element_middle(void)
{
    scan_at("scan_element_middle", 2,
            "a hit on transformConstraints[2] stores index 2");
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
    tf_begin("scan_miss");
    void *array[3] = { constraint_record("a"), constraint_record("b"),
                       constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(3, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("nope", 1);
    spTransformConstraintTimelineShape *t;

    add(n, plain_frame(0.25f));
    add(map, n);
    obs.lookup_ret[0] = constraint_record("missing");   /* not in the array */

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "miss run returns 1");
    CK(obs.create_n == 1, "the timeline is created before the scan");
    t = (spTransformConstraintTimelineShape *)obs.last_timeline;
    CK(t->transformConstraintIndex == (int32_t)SENTINEL,
       "a miss stores nothing and +0x14 keeps the create-time value");
    CK(obs.set_n == 1, "a miss still reads the frames (0x28dd5c -> 0x28dd68)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "a miss still publishes the timeline");
    pass("scan_miss");
}

/* ================================================================== */
/* 7. the count is signed and the array is not read when count <= 0     */
/* ================================================================== */
static void scan_nonpositive_count(void)
{
    tf_begin("scan_nonpositive_count");
    void *array1[1] = { constraint_record("only") };
    Json *map = node("transform");
    Json *n = tf_node("only", 1);
    add(n, plain_frame(0.0f));
    add(map, n);
    obs.lookup_ret[0] = array1[0];      /* would match if the scan ran */

    /* count == 0, array NULL: the +0x48 word is never read */
    {
        spSkeletonDataTransformShape *d = make_data(0, 0);
        spAnimationTransformShape *a = make_animation();
        CK(readSkeletonData_transformTimelines(map, d, a) == 1, "count 0 run returns 1");
        CK(((spTransformConstraintTimelineShape *)obs.last_timeline)->transformConstraintIndex
           == (int32_t)SENTINEL,
           "count 0 skips the scan even with a NULL array");
        CK(obs.set_n == 1 && a->timelineCount == 1,
           "count 0 still reaches the frame loop and the tail");
    }
    /* count == -1, array[0] would match: the compare is signed `ble` */
    {
        spSkeletonDataTransformShape *d = make_data(-1, array1);
        spAnimationTransformShape *a = make_animation();
        obs.set_n = 0;
        CK(readSkeletonData_transformTimelines(map, d, a) == 1, "count -1 run returns 1");
        CK(((spTransformConstraintTimelineShape *)obs.last_timeline)->transformConstraintIndex
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
    tf_begin("lookup_null_matches_null_slot");
    void *array[3] = { constraint_record("a"), 0, constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(3, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("absent", 1);
    add(n, plain_frame(0.0f));
    add(map, n);
    obs.lookup_ret[0] = 0;              /* findTransformConstraint miss -> NULL */

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "NULL lookup run returns 1");
    CK(obs.lookup_n == 1 && obs.lookup_ret[0] == 0,
       "findTransformConstraint is allowed to return NULL and B12 does not branch on it");
    CK(((spTransformConstraintTimelineShape *)obs.last_timeline)->transformConstraintIndex == 1,
       "NULL equals the NULL array slot, so index 1 is written");
    CK(obs.set_n == 1, "the frame loop runs regardless of the lookup result");

    /* the same NULL lookup against an array without a NULL slot simply misses */
    {
        void *array2[2] = { constraint_record("a"), constraint_record("b") };
        spSkeletonDataTransformShape *d2 = make_data(2, array2);
        spAnimationTransformShape *a2 = make_animation();
        obs.set_n = 0;
        CK(readSkeletonData_transformTimelines(map, d2, a2) == 1, "second NULL lookup returns 1");
        CK(((spTransformConstraintTimelineShape *)obs.last_timeline)->transformConstraintIndex
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
    tf_begin("frame_defaults");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(1, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("c", 1);
    add(n, node(0));                   /* a frame with no keys at all */
    add(map, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "default frame run returns 1");
    CK(obs.set_n == 1, "a keyless frame still reaches setFrame");
    CK(obs.set_index[0] == 0, "the first frame index is 0");
    CK(obs.set_time[0] == 0u,
       "an absent \"time\" yields the 0.0f default");
    CK(obs.set_rotate[0] == 0x3f800000u,
       "an absent \"rotateMix\" yields the 1.0f default (0x28dd94 mov r2,#1065353216)");
    CK(obs.set_translate[0] == 0x3f800000u,
       "an absent \"translateMix\" yields the 1.0f default (0x28dda8)");
    CK(obs.set_scale[0] == 0x3f800000u,
       "an absent \"scaleMix\" yields the 1.0f default (0x28ddbc)");
    CK(obs.set_shear[0] == 0x3f800000u,
       "an absent \"shearMix\" yields the 1.0f default (0x28ddd0)");
    CK(obs.curve_n == 0, "a frame without a \"curve\" key writes no curve");
    pass("frame_defaults");
}

/* ================================================================== */
/* 10. frame values, index sequence, five-float store shape            */
/* ================================================================== */
static void frame_values(void)
{
    tf_begin("frame_values");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(1, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("c", 3);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0);
    spTransformConstraintTimelineShape *t;

    add(f0, num_key("time", 0.25f));
    add(f0, num_key("rotateMix", 0.5f));
    add(f0, num_key("translateMix", 0.75f));
    add(f0, num_key("scaleMix", 1.25f));
    add(f0, num_key("shearMix", 1.5f));
    add(f1, num_key("time", 1.5f));
    add(f1, num_key("rotateMix", 2.0f));   /* only rotateMix; rest default */
    add(f2, num_key("time", 2.5f));        /* no mix keys at all */
    add(n, f0); add(n, f1); add(n, f2);
    add(map, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "three-frame run returns 1");
    CK(obs.set_n == 3, "one setFrame per frame child");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1 && obs.set_index[2] == 2,
       "the frame index starts at 0 and increments per frame");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_time[1] == 0x3fc00000u
       && obs.set_time[2] == 0x40200000u,
       "setFrame receives the frame \"time\" bits");
    CK(obs.set_rotate[0] == 0x3f000000u && obs.set_rotate[1] == 0x40000000u
       && obs.set_rotate[2] == 0x3f800000u,
       "setFrame receives the frame \"rotateMix\" bits and its 1.0f fallback");
    CK(obs.set_translate[0] == 0x3f400000u && obs.set_translate[1] == 0x3f800000u
       && obs.set_translate[2] == 0x3f800000u,
       "setFrame receives the frame \"translateMix\" bits and its 1.0f fallback");
    CK(obs.set_scale[0] == 0x3fa00000u && obs.set_scale[1] == 0x3f800000u
       && obs.set_scale[2] == 0x3f800000u,
       "setFrame receives the frame \"scaleMix\" bits and its 1.0f fallback");
    CK(obs.set_shear[0] == 0x3fc00000u && obs.set_shear[1] == 0x3f800000u
       && obs.set_shear[2] == 0x3f800000u,
       "setFrame receives the frame \"shearMix\" bits and its 1.0f fallback");

    t = (spTransformConstraintTimelineShape *)obs.last_timeline;
    CK(t->frameFloatCount == 15,
       "the synthetic create sized five floats per frame (0x282fc0 mov r2,#5)");
    CK(t->frames[0] == 0.25f && t->frames[1] == 0.5f && t->frames[2] == 0.75f
       && t->frames[3] == 1.25f && t->frames[4] == 1.5f,
       "frame 0 stores time, rotateMix, translateMix, scaleMix, shearMix at stride 5");
    CK(t->frames[5] == 1.5f && t->frames[6] == 2.0f && t->frames[7] == 1.0f
       && t->frames[8] == 1.0f && t->frames[9] == 1.0f,
       "frame 1 falls back to translate/scale/shear 1.0");
    CK(t->frames[10] == 2.5f && t->frames[11] == 1.0f && t->frames[12] == 1.0f
       && t->frames[13] == 1.0f && t->frames[14] == 1.0f,
       "frame 2 falls back to all four mix values 1.0");
    pass("frame_values");
}

/* ================================================================== */
/* 11. each mix key is read independently                              */
/* ================================================================== */
static void key_isolation(void)
{
    tf_begin("key_isolation");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(1, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("c", 4);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0), *f3 = node(0);
    spTransformConstraintTimelineShape *t;

    add(f0, num_key("time", 0.0f)); add(f0, num_key("rotateMix", 0.125f));
    add(f1, num_key("time", 0.0f)); add(f1, num_key("translateMix", 0.25f));
    add(f2, num_key("time", 0.0f)); add(f2, num_key("scaleMix", 0.375f));
    add(f3, num_key("time", 0.0f)); add(f3, num_key("shearMix", 0.5f));
    add(n, f0); add(n, f1); add(n, f2); add(n, f3);
    add(map, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "key isolation run returns 1");
    CK(obs.set_n == 4, "four single-key frames reach setFrame");
    CK(obs.set_rotate[0] == 0x3e000000u && obs.set_translate[0] == 0x3f800000u
       && obs.set_scale[0] == 0x3f800000u && obs.set_shear[0] == 0x3f800000u,
       "a lone \"rotateMix\" drives only the rotate slot");
    CK(obs.set_translate[1] == 0x3e800000u && obs.set_rotate[1] == 0x3f800000u
       && obs.set_scale[1] == 0x3f800000u && obs.set_shear[1] == 0x3f800000u,
       "a lone \"translateMix\" drives only the translate slot");
    CK(obs.set_scale[2] == 0x3ec00000u && obs.set_rotate[2] == 0x3f800000u
       && obs.set_translate[2] == 0x3f800000u && obs.set_shear[2] == 0x3f800000u,
       "a lone \"scaleMix\" drives only the scale slot");
    CK(obs.set_shear[3] == 0x3f000000u && obs.set_rotate[3] == 0x3f800000u
       && obs.set_translate[3] == 0x3f800000u && obs.set_scale[3] == 0x3f800000u,
       "a lone \"shearMix\" drives only the shear slot");

    t = (spTransformConstraintTimelineShape *)obs.last_timeline;
    CK(t->frames[1] == 0.125f && t->frames[2] == 1.0f && t->frames[3] == 1.0f
       && t->frames[4] == 1.0f,
       "the independent-key mapping lands at the five-float offsets");
    CK(t->frames[19] == 0.5f && t->frames[16] == 1.0f,
       "the fourth frame's shearMix lands at frame base 15 + 4");
    pass("key_isolation");
}

/* ================================================================== */
/* 12. readCurve wiring through the real implementation                 */
/* ================================================================== */
static void read_curve_paths(void)
{
    tf_begin("read_curve_paths");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(1, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("c", 2);
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
    add(map, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "curve run returns 1");
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
/* 13. two constraints: cursor, duration, per-node lookup                */
/* ================================================================== */
static void two_constraints(void)
{
    tf_begin("two_constraints");
    void *array[2] = { constraint_record("a"), constraint_record("b") };
    spSkeletonDataTransformShape *d = make_data(2, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n0 = tf_node("a", 1);
    Json *n1 = tf_node("b", 2);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0);

    add(f0, num_key("time", 0.4f));
    add(n0, f0);
    add(f1, num_key("time", 0.9f));
    add(f2, num_key("time", 1.7f));
    add(n1, f1); add(n1, f2);
    add(map, n0); add(map, n1);        /* sibling list the parent walks */
    obs.lookup_ret[0] = array[0];      /* node "a" -> transformConstraints[0] */
    obs.lookup_ret[1] = array[1];      /* node "b" -> transformConstraints[1] */

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "two-constraint run returns 1");
    CK(obs.lookup_n == 2, "one lookup per transform constraint node");
    CK(strcmp(obs.lookup_name[0], "a") == 0 && strcmp(obs.lookup_name[1], "b") == 0,
       "the loop advances through the transform child list");
    CK(obs.create_n == 2 && obs.create_frames[0] == 1 && obs.create_frames[1] == 2,
       "each node creates its own timeline with its own count");
    CK(obs.set_n == 3 && obs.set_index[1] == 0 && obs.set_index[2] == 1,
       "the frame index restarts at 0 for the second timeline");
    CK(a->timelineCount == 2 && a->timelines[0] != a->timelines[1],
       "both timelines are published at successive cursor slots");
    CK(bits(a->duration) == 0x3fd9999au,
       "duration keeps the larger last frame time (1.7 over 0.4)");
    CK(((spTransformConstraintTimelineShape *)a->timelines[0])->transformConstraintIndex == 0
       && ((spTransformConstraintTimelineShape *)a->timelines[1])->transformConstraintIndex == 1,
       "each constraint writes its own index into its own timeline");
    pass("two_constraints");
}

/* ================================================================== */
/* 14. loop driven by the child list, tail by the declared count        */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    tf_begin("declared_vs_child_count");
    void *array[1] = { constraint_record("c") };
    spSkeletonDataTransformShape *d = make_data(1, array);
    spAnimationTransformShape *a = make_animation();
    Json *map = node("transform");
    Json *n = tf_node("c", 3);         /* declares 3, carries 1 */
    spTransformConstraintTimelineShape *t;

    add(n, plain_frame(0.4f));
    add(map, n);
    obs.lookup_ret[0] = array[0];

    CK(readSkeletonData_transformTimelines(map, d, a) == 1, "one-frame declared-three run returns 1");
    CK(obs.set_n == 1, "the loop follows the child list");
    CK(obs.create_frames[0] == 3, "create still receives the declared count");
    t = (spTransformConstraintTimelineShape *)obs.last_timeline;
    CK(bits(t->frames[0]) == 0x3ecccccdu, "the single frame time is stored at index 0");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[(3-1)*5] (=0, never written), not frames[0]");
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
    frame_defaults();
    frame_values();
    key_isolation();
    read_curve_paths();
    two_constraints();
    declared_vs_child_count();
    out("SUMMARY all declared transform timeline family contracts passed\n");
    quit(0);
}
