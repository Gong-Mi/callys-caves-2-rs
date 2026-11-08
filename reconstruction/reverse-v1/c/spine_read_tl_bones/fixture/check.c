/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the reporter and the six timeline entry points are SYNTHETIC providers.
 * qemu executes our linked C, never original libyoyo bytes.  Original not
 * executed; this is not an original-equivalence claim.
 *
 * Subject: the bones timeline family of spSkeletonJson_readSkeletonData
 *   B6   0x28d640..0x28d740  (bones loop + real findBoneIndex + strcmp dispatch)
 *   B6b  0x28d740..0x28d840  (translate/scale/shear frames + publish tail)
 *   B9   0x28da54..0x28da74  (translate select: s16 = parser->scale)
 *   B10  0x28da74..0x28db48  (rotate frames: time + angle + publish tail)
 *   B11  0x28db48..0x28db5c  (scale select: s16 = 1.0)
 *   B11b 0x28dbb4..0x28dbc4  (shear select: s16 = 1.0)
 *   E2   0x28db5c..0x28db88  (Bone not found: , json arg = animation node)
 *   E3   0x28db88..0x28dbb4  (Invalid timeline type for a bone: , json arg = 0)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem/getFloat             json_interface
 *   readCurve                         spine_read_curve (setStepped/setCurve doubles
 *                                     below record its two call paths)
 *   _spSkeletonJson_setError          spine_json_error
 *   Json_dispose / ReportSpineError   spine_json_support
 *   spAnimation_dispose / spSkeletonData_dispose / spBoneData_dispose
 *                                     spine_skeleton_data
 *   _malloc / _free / _calloc         spine_alloc
 *   spSkeletonData_findBoneIndex      spine_read_tl_bones (0x28b018, recovered
 *                                     in the module under test, not a stub)
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spTranslateTimeline_create / spRotateTimeline_create / spScaleTimeline_create
 *   / spShearTimeline_create and spTranslateTimeline_setFrame /
 *   spRotateTimeline_setFrame.  The setter doubles model the disassembled
 *   store shapes exactly (rotate: frames[i*2+{0,1}] = time,angle; xy:
 *   frames[i*3+{0,1,2}] = time,x,y) so the publish tails read what the real
 *   setters produce, and additionally record every argument word.
 *   spScaleTimeline_setFrame / spShearTimeline_setFrame are deliberately NOT
 *   defined: in the original they are 4-byte `b spTranslateTimeline_setFrame`
 *   thunks (0x282b1c / 0x282b38) and the caller has a single call site at
 *   0x28d7c0, so any call to them from the reconstruction must fail the link.
 *   spCurveTimeline_setStepped/setCurve (0x2817c0 / 0x2817d8) recorders.
 *   fixture heap/allocator roster, libc string providers, hand-built Json nodes.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_bones.h"
#include "../../spine_read_curve/src/spine_read_curve.h"
#include "../../spine_json_error/src/spine_json_error.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 12
#define MAX_TL 8

enum { K_TR = 0, K_RO = 1, K_SC = 2, K_SH = 3 };
enum { SET_ROTATE = 1, SET_XY = 2 };

static struct {
    int create_n[4];
    int create_frames[4];
    void *last_timeline[4];
    int set_n;
    int set_kind[MAX_FRAMES];        /* SET_ROTATE / SET_XY                   */
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    uint32_t set_a[MAX_FRAMES];      /* x (xy) / angle (rotate)               */
    uint32_t set_b[MAX_FRAMES];      /* y (xy only)                           */
    void *set_tl[MAX_FRAMES];
    int curve_n, curve_kind[MAX_FRAMES], curve_frame[MAX_FRAMES];
    void *curve_tl[MAX_FRAMES];
    uint32_t curve_args[MAX_FRAMES][4];
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

/* Custom allocator: records (bytes, line, tag) so the line-90 error copy is
 * observable. */
static void *tl_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "tl allocation roster/tag");
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
/* timeline vtable: spAnimation_dispose -> spTimeline_dispose reads     */
/* [[self+4]+4] and calls it.  The probe only counts the walk.          */
/* ------------------------------------------------------------------ */
static uint32_t tl_vtable_words[2];

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                      */
/* ------------------------------------------------------------------ */
static void *tl_reserve_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

/* The real creators tail-call _spBaseTimeline_create(count, type, frameStep,
 * tag) (0x282a10): frameFloatCount = count*frameStep at +0x0c, calloc'd
 * frames at +0x10, curves array at +0x08.  The double keeps that layout and
 * allocates frameStep floats per frame. */
static void *bone_timeline_create(int kind, int frameCount, int frameStep)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spBoneTimelineShape *t = tl_reserve_zero(sizeof(*t));
    t->type = (uint32_t)kind;      /* fixture tag; the real word is the internal
                                    * timeline-type enum passed at 0x282a50 */
    t->vtable = tl_vtable_words;
    t->curves = 0;                 /* (count-1)*19 floats; readCurve doubles
                                    * only record, so it stays NULL */
    t->frameFloatCount = frameCount * frameStep;
    t->frames = tl_reserve_zero(n * (uint32_t)frameStep * 4u);
    ++obs.create_n[kind];
    obs.create_frames[kind] = frameCount;
    obs.last_timeline[kind] = t;
    return t;
}

void *spTranslateTimeline_create(int frameCount)
{
    return bone_timeline_create(K_TR, frameCount, 3);
}
void *spRotateTimeline_create(int frameCount)
{
    return bone_timeline_create(K_RO, frameCount, 2);
}
void *spScaleTimeline_create(int frameCount)
{
    return bone_timeline_create(K_SC, frameCount, 3);
}
void *spShearTimeline_create(int frameCount)
{
    return bone_timeline_create(K_SH, frameCount, 3);
}

void spTranslateTimeline_setFrame(void *timeline, int frameIndex,
                                  float time, float x, float y)
{
    spBoneTimelineShape *t = (spBoneTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 3u;
    if (obs.set_n >= MAX_FRAMES) fail("xy setFrame table exhausted");
    /* 0x282af0..0x282af8: frames[i*3]=time, [+1]=x, [+2]=y */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = x;
    t->frames[base + 2u] = y;
    obs.set_kind[obs.set_n] = SET_XY;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_a[obs.set_n] = bits(x);
    obs.set_b[obs.set_n] = bits(y);
    obs.set_tl[obs.set_n] = timeline;
    ++obs.set_n;
}

void spRotateTimeline_setFrame(void *timeline, int frameIndex,
                               float time, float angle)
{
    spBoneTimelineShape *t = (spBoneTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 2u;
    if (obs.set_n >= MAX_FRAMES) fail("rotate setFrame table exhausted");
    /* 0x282ab0/0x282ab4: frames[i*2]=time, [+1]=angle */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = angle;
    obs.set_kind[obs.set_n] = SET_ROTATE;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_a[obs.set_n] = bits(angle);
    obs.set_b[obs.set_n] = 0u;
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

/* the animation dispose path calls into the vtable; record the walk.
 * The parameter type must stay spTimeline* so the indirect call through
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

/* spBoneData record as findBoneIndex/dispose see it: +0x04 name. */
static void *bone_record(const char *name)
{
    void **b = tl_reserve_zero(8);
    b[1] = (void *)(uintptr_t)name;
    return b;
}

static spSkeletonData *make_data(void **bones, int count)
{
    spSkeletonData *d = spSkeletonData_create();   /* real calloc(1,84,tag,37) */
    d->words[4] = (uint32_t)count;                 /* +0x10 bonesCount */
    d->words[5] = (uint32_t)(uintptr_t)bones;      /* +0x14 bones array */
    return d;
}

static spAnimationShape *make_animation(void)
{
    spAnimationShape *a = tl_reserve_zero(sizeof(*a));
    a->timelines = tl_reserve_zero(4u * MAX_TL);
    return a;
}

/* Json helpers: node types match the parser's enum (json_interface/readCurve). */
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
static Json *timeline_node(const char *type, int declared)
{
    Json *n = node(type);
    n->unk_0c = (uint32_t)declared;
    return n;
}
static Json *bone_node(const char *name)
{
    return node(name);                 /* name is the JSON member key (+0x1c) */
}
static Json *xy_frame(float time, float x, float y)
{
    Json *f = node(0);
    add(f, num_key("time", time));
    add(f, num_key("x", x));
    add(f, num_key("y", y));
    return f;
}
static Json *rot_frame(float time, float angle)
{
    Json *f = node(0);
    add(f, num_key("time", time));
    add(f, num_key("angle", angle));
    return f;
}

/* ================================================================== */
/* 1. no "bones" value at all                                           */
/* ================================================================== */
static void bones_key_absent(void)
{
    tl_begin("bones_key_absent");
    spSkeletonData *d = make_data(0, 0);
    spAnimationShape *a = make_animation();

    CK(readSkeletonData_boneTimelines(0, 0, d, a, &parser_obj) == 1,
       "B6 absent bones value returns 1 (falls through to the ik block)");
    CK(obs.create_n[K_TR] == 0 && obs.create_n[K_RO] == 0
       && obs.create_n[K_SC] == 0 && obs.create_n[K_SH] == 0,
       "B6 absent bones value creates no timeline");
    CK(a->timelineCount == 0 && report_count == 0,
       "B6 absent bones value publishes and reports nothing");
    pass("bones_key_absent");
}

/* ================================================================== */
/* 2. bones object with no children                                     */
/* ================================================================== */
static void bones_without_children(void)
{
    tl_begin("bones_without_children");
    spSkeletonData *d = make_data(0, 0);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 empty bones object returns 1");
    CK(obs.create_n[K_TR] == 0 && a->timelineCount == 0,
       "B6 empty bones object creates and publishes nothing");
    pass("bones_without_children");
}

/* ================================================================== */
/* 3. a bone with no timelines does not stop the child-list walk         */
/* ================================================================== */
static void bone_without_timelines_then_next(void)
{
    tl_begin("bone_without_timelines_then_next");
    void *bones_arr[2] = { bone_record("a"), bone_record("b") };
    spSkeletonData *d = make_data(bones_arr, 2);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *ba = bone_node("a");
    Json *bb = bone_node("b");
    Json *tl = timeline_node("translate", 1);
    add(bb, tl);
    add(tl, xy_frame(0.0f, 2.0f, 4.0f));
    add(bones, ba);                    /* "a" has no children */
    add(bones, bb);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 bone without timelines completes");
    CK(obs.create_n[K_TR] == 1 && obs.set_n == 1,
       "the second bone's translate timeline is still read");
    CK(((spBoneTimelineShape *)obs.last_timeline[K_TR])->boneIndex == 1,
       "the second bone resolves to index 1 through the real findBoneIndex");
    pass("bone_without_timelines_then_next");
}

/* ================================================================== */
/* 4. duplicate bone names: the FIRST match wins                        */
/* ================================================================== */
static void bone_index_first_of_duplicates(void)
{
    tl_begin("bone_index_first_of_duplicates");
    void *bones_arr[3] = { bone_record("arm"), bone_record("leg"), bone_record("arm") };
    spSkeletonData *d = make_data(bones_arr, 3);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("arm");
    Json *tl = timeline_node("rotate", 1);
    add(tl, rot_frame(0.0f, 10.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 duplicate bone name completes");
    CK(((spBoneTimelineShape *)obs.last_timeline[K_RO])->boneIndex == 0,
       "duplicate bone names resolve to the first index (0, not 2)");
    pass("bone_index_first_of_duplicates");
}

/* ================================================================== */
/* 5. a different bone resolves to its own index                        */
/* ================================================================== */
static void bone_index_second(void)
{
    tl_begin("bone_index_second");
    void *bones_arr[3] = { bone_record("arm"), bone_record("leg"), bone_record("arm") };
    spSkeletonData *d = make_data(bones_arr, 3);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("leg");
    Json *tl = timeline_node("rotate", 1);
    add(tl, rot_frame(0.0f, 10.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 second bone completes");
    CK(((spBoneTimelineShape *)obs.last_timeline[K_RO])->boneIndex == 1,
       "a non-duplicate bone name resolves to its own index");
    pass("bone_index_second");
}

/* ================================================================== */
/* 6. empty bone table: every name is a miss -> E2                      */
/* ================================================================== */
static void bone_index_empty_data(void)
{
    tl_begin("bone_index_empty_data");
    spSkeletonData *d = make_data(0, 0);           /* bonesCount == 0 */
    spAnimationShape *a = make_animation();
    Json *anim = node(0);
    Json *bones = node("bones");
    Json *b = bone_node("anything");
    add(bones, b);
    add(anim, bones);

    CK(readSkeletonData_boneTimelines(bones, anim, d, a, &parser_obj) == 0,
       "B6 empty bone table takes the E2 exit");
    CK(obs.create_n[K_TR] == 0 && obs.create_n[K_RO] == 0
       && obs.create_n[K_SC] == 0 && obs.create_n[K_SH] == 0,
       "B6 empty bone table creates no timeline");
    pass("bone_index_empty_data");
}

/* ================================================================== */
/* 7. translate frames: x/y multiplied by parser->scale                 */
/* ================================================================== */
static void translate_frames_scaled(void)
{
    tl_begin("translate_frames_scaled");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    parser_obj.scale = bits(2.0f);                 /* s16 from 0x28da5c */
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("translate", 2);
    add(tl, xy_frame(0.0f, 1.0f, 3.0f));
    add(tl, xy_frame(0.5f, -2.0f, 4.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 translate timeline completes");
    CK(obs.create_n[K_TR] == 1 && obs.create_frames[K_TR] == 2,
       "translate create receives the declared frame count");
    CK(obs.set_n == 2 && obs.set_kind[0] == SET_XY && obs.set_kind[1] == SET_XY,
       "one xy setFrame per frame child");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "translate frame index starts at 0 and increments");
    CK(obs.set_time[0] == 0u && obs.set_time[1] == 0x3f000000u,
       "translate setFrame receives the frame time bits");
    CK(obs.set_a[0] == 0x40000000u && obs.set_b[0] == 0x40c00000u,
       "translate multiplies x and y by parser->scale (1*2, 3*2)");
    CK(obs.set_a[1] == 0xc0800000u && obs.set_b[1] == 0x41000000u,
       "translate multiplies the second frame too (-2*2, 4*2)");

    spBoneTimelineShape *t = (spBoneTimelineShape *)obs.last_timeline[K_TR];
    CK(t->boneIndex == 0, "translate timeline stores the bone index at +0x14");
    CK(t->frames[0] == 0.0f && t->frames[1] == 2.0f && t->frames[2] == 6.0f
       && t->frames[3] == 0.5f && t->frames[4] == -4.0f && t->frames[5] == 8.0f,
       "translate frames array is 3 floats per frame (time,x,y)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "B6b tail publishes the translate timeline");
    CK(bits(a->duration) == 0x3f000000u,
       "B6b tail reads frames[3*(count-1)] for the last frame time");
    pass("translate_frames_scaled");
}

/* ================================================================== */
/* 8. scale frames: s16 forced to 1.0 at 0x28db48                       */
/* ================================================================== */
static void scale_frames_not_scaled(void)
{
    tl_begin("scale_frames_not_scaled");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    parser_obj.scale = bits(2.0f);                 /* must NOT reach scale */
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("scale", 1);
    add(tl, xy_frame(0.25f, 5.0f, 6.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 scale timeline completes");
    CK(obs.create_n[K_SC] == 1 && obs.create_n[K_TR] == 0,
       "scale selects spScaleTimeline_create, not translate");
    CK(obs.set_n == 1 && obs.set_a[0] == 0x40a00000u && obs.set_b[0] == 0x40c00000u,
       "scale x/y reach setFrame unscaled (s16 = 1.0, not parser->scale)");
    spBoneTimelineShape *t = (spBoneTimelineShape *)obs.last_timeline[K_SC];
    CK(t->frames[1] == 5.0f && t->frames[2] == 6.0f,
       "scale frames array holds the unscaled values");
    CK(bits(a->duration) == 0x3e800000u, "scale duration is the last frame time");
    pass("scale_frames_not_scaled");
}

/* ================================================================== */
/* 9. shear frames: s16 forced to 1.0 at 0x28dbb8                       */
/* ================================================================== */
static void shear_frames_not_scaled(void)
{
    tl_begin("shear_frames_not_scaled");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    parser_obj.scale = bits(2.0f);
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("shear", 1);
    add(tl, xy_frame(0.75f, -1.0f, 2.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 shear timeline completes");
    CK(obs.create_n[K_SH] == 1 && obs.create_n[K_TR] == 0 && obs.create_n[K_SC] == 0,
       "shear selects spShearTimeline_create");
    CK(obs.set_n == 1 && obs.set_a[0] == 0xbf800000u && obs.set_b[0] == 0x40000000u,
       "shear x/y reach setFrame unscaled (s16 = 1.0)");
    CK(((spBoneTimelineShape *)obs.last_timeline[K_SH])->boneIndex == 0,
       "shear timeline stores the bone index at +0x14");
    pass("shear_frames_not_scaled");
}

/* ================================================================== */
/* 10. rotate frames: time + angle, two-float stride                    */
/* ================================================================== */
static void rotate_frames_angle(void)
{
    tl_begin("rotate_frames_angle");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("rotate", 2);
    add(tl, rot_frame(0.0f, 30.0f));
    add(tl, rot_frame(0.5f, -45.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 rotate timeline completes");
    CK(obs.create_n[K_RO] == 1 && obs.create_frames[K_RO] == 2,
       "rotate create receives the declared frame count");
    CK(obs.set_n == 2 && obs.set_kind[0] == SET_ROTATE && obs.set_kind[1] == SET_ROTATE,
       "one rotate setFrame per frame child");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "rotate frame index starts at 0 and increments");
    CK(obs.set_a[0] == 0x41f00000u && obs.set_a[1] == 0xc2340000u,
       "rotate reads the \\\"angle\\\" key, not x (30, -45)");
    CK(obs.set_time[0] == 0u && obs.set_time[1] == 0x3f000000u,
       "rotate setFrame receives the frame time bits");

    spBoneTimelineShape *t = (spBoneTimelineShape *)obs.last_timeline[K_RO];
    CK(t->boneIndex == 0, "rotate timeline stores the bone index at +0x14");
    CK(t->frames[0] == 0.0f && t->frames[1] == 30.0f
       && t->frames[2] == 0.5f && t->frames[3] == -45.0f,
       "rotate frames array is 2 floats per frame (time,angle)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "B10 tail publishes the rotate timeline");
    CK(bits(a->duration) == 0x3f000000u,
       "B10 tail reads frames[2*(count-1)] for the last frame time");
    pass("rotate_frames_angle");
}

/* ================================================================== */
/* 11. readCurve wiring: stepped string and 4-number array              */
/* ================================================================== */
static void curve_wiring(void)
{
    tl_begin("curve_wiring");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("translate", 2);
    Json *f0 = xy_frame(0.0f, 0.0f, 0.0f);
    Json *f1 = xy_frame(1.0f, 1.0f, 2.0f);
    const float cv[4] = { 0.25f, 0.5f, 0.75f, 1.0f };
    Json *curve_arr;
    add(f0, str_key("curve", "stepped"));
    curve_arr = floats("curve", cv, 4, 4);
    curve_arr->unk_08 = 5;                 /* array */
    add(f1, curve_arr);
    add(tl, f0);
    add(tl, f1);
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 translate timeline with curves completes");
    CK(obs.set_n == 2 && obs.curve_n == 2,
       "readCurve runs once per frame after setFrame");
    CK(obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \\\"stepped\\\" curve string reaches setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches setCurve at frame 1");
    CK(obs.curve_tl[0] == obs.last_timeline[K_TR]
       && obs.curve_tl[1] == obs.last_timeline[K_TR],
       "readCurve receives the timeline pointer that setFrame received");
    CK(obs.curve_args[1][0] == 0x3e800000u && obs.curve_args[1][1] == 0x3f000000u
       && obs.curve_args[1][2] == 0x3f400000u && obs.curve_args[1][3] == 0x3f800000u,
       "curve control points reach setCurve bit-exact");
    pass("curve_wiring");
}

/* ================================================================== */
/* 12. the frame loop follows the child list, the tail the declared count */
/* ================================================================== */
static void declared_vs_child_xy(void)
{
    tl_begin("declared_vs_child_xy");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("translate", 3);      /* declares 3, has 1 */
    add(tl, xy_frame(0.4f, 1.0f, 1.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 one-frame declared-three translate completes");
    CK(obs.set_n == 1, "the frame loop follows the child list, not the count");
    CK(obs.create_frames[K_TR] == 3, "the creator still receives the declared count");
    CK(bits(a->duration) == 0u,
       "B6b reads frames[3*(declared-1)] (=0, never written), not frames[0]=0.4");
    pass("declared_vs_child_xy");
}

/* ================================================================== */
/* 13. rotate variant of declared-vs-child                              */
/* ================================================================== */
static void declared_vs_child_rotate(void)
{
    tl_begin("declared_vs_child_rotate");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("rotate", 4);         /* declares 4, has 1 */
    add(tl, rot_frame(0.9f, 7.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 one-frame declared-four rotate completes");
    CK(obs.set_n == 1 && obs.create_frames[K_RO] == 4,
       "rotate frame loop follows the children, creator the declared count");
    CK(bits(a->duration) == 0u,
       "B10 reads frames[(declared-1)*2] (=0, never written), not frames[1]=7");
    pass("declared_vs_child_rotate");
}

/* ================================================================== */
/* 14. one bone with all four timeline kinds                            */
/* ================================================================== */
static void dispatch_all_four(void)
{
    tl_begin("dispatch_all_four");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tr = timeline_node("translate", 1);
    Json *ro = timeline_node("rotate", 1);
    Json *sc = timeline_node("scale", 1);
    Json *sh = timeline_node("shear", 1);
    add(tr, xy_frame(0.2f, 1.0f, 1.0f));
    add(ro, rot_frame(0.1f, 10.0f));
    add(sc, xy_frame(0.3f, 2.0f, 2.0f));
    add(sh, xy_frame(0.4f, 3.0f, 3.0f));
    add(b, tr);
    add(b, ro);
    add(b, sc);
    add(b, sh);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 four-kind bone completes");
    CK(obs.create_n[K_TR] == 1 && obs.create_n[K_RO] == 1
       && obs.create_n[K_SC] == 1 && obs.create_n[K_SH] == 1,
       "each of the four types selects its own creator exactly once");
    CK(a->timelineCount == 4, "all four timelines are published");
    CK(a->timelines[0] == obs.last_timeline[K_TR]
       && a->timelines[1] == obs.last_timeline[K_RO]
       && a->timelines[2] == obs.last_timeline[K_SC]
       && a->timelines[3] == obs.last_timeline[K_SH],
       "publish order follows the JSON child order (translate,rotate,scale,shear)");
    for (int i = 0; i < 4; ++i)
        CK(((spBoneTimelineShape *)a->timelines[i])->boneIndex == 0,
           "every timeline of the bone stores the same bone index");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 0
       && obs.set_index[2] == 0 && obs.set_index[3] == 0,
       "the frame index restarts at 0 for every timeline");
    CK(bits(a->duration) == 0x3ecccccdU,
       "duration keeps the largest last frame time (0.4)");
    pass("dispatch_all_four");
}

/* ================================================================== */
/* 15. E3: invalid timeline type for a bone                             */
/* ================================================================== */
static void invalid_type_e3(void)
{
    tl_begin("invalid_type_e3");
    void *bones_arr[1] = { bone_record("body") };
    void *bone0 = bones_arr[0];
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    void **anim_table = a->timelines;
    Json *root = node(0);
    Json *anim = node(0);
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *ok = timeline_node("translate", 1);
    Json *bad = timeline_node("paths", 1);
    add(ok, xy_frame(0.0f, 1.0f, 1.0f));
    add(b, ok);
    add(b, bad);
    add(bones, b);
    add(anim, bones);
    add(root, anim);

    CK(readSkeletonData_boneTimelines(bones, anim, d, a, &parser_obj) == 0,
       "E3 returns 0 so the parent loader returns NULL");
    CK(obs.create_n[K_TR] == 1 && a->timelines[0] == obs.last_timeline[K_TR],
       "the valid timeline before the bad type was processed and published");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E3 reports through the real console vcall");
    CK(strcmp(reported, "Invalid timeline type for a bone: paths") == 0,
       "E3 message is the exact original literal plus the timeline key");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error,
                 "Invalid timeline type for a bone: paths") == 0,
       "E3 stores the formatted message in parser->error");
    CK(alloc_count(90) == 1 && tag_is(90, "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
       "E3 error copy is a line-90 SkeletonJson.c allocation");
    CK(obs.vdispose_n == 1,
       "E3 disposes the animation first: the published timeline is walked");
    CK(free_hits(a) == 1 && free_hits(anim_table) == 1,
       "E3 animation dispose frees the timeline table and the record");
    CK(free_hits(d) == 1 && free_hits(bone0) == 1,
       "E3 disposes the skeleton data (and its bone record) exactly once");
    CK(free_hits(root) == 0 && free_hits(anim) == 0 && free_hits(b) == 0
       && free_hits(ok) == 0 && free_hits(bad) == 0,
       "E3 passes a NULL json argument to setError (r4 == 0), tree untouched");
    pass("invalid_type_e3");
}

/* ================================================================== */
/* 16. E2: bone not found                                               */
/* ================================================================== */
static void bone_not_found_e2(void)
{
    tl_begin("bone_not_found_e2");
    void *bones_arr[1] = { bone_record("body") };
    void *bone0 = bones_arr[0];
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    void **anim_table = a->timelines;
    Json *root = node(0);
    Json *anim = node(0);
    Json *bones = node("bones");
    Json *b = bone_node("nope");
    Json *tl = timeline_node("translate", 1);
    add(tl, xy_frame(0.0f, 1.0f, 1.0f));
    add(b, tl);
    add(bones, b);
    add(anim, bones);
    add(root, anim);

    CK(readSkeletonData_boneTimelines(bones, anim, d, a, &parser_obj) == 0,
       "E2 returns 0 so the parent loader returns NULL");
    CK(obs.create_n[K_TR] == 0 && obs.set_n == 0,
       "E2 creates no timeline for the unknown bone");
    CK(strcmp(reported, "Bone not found: nope") == 0,
       "E2 message is the exact original literal plus the bone name");
    CK(strcmp(report_format, "Spine Error:%s\n") == 0 && report_count == 1,
       "E2 reports once through the real console vcall");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error, "Bone not found: nope") == 0,
       "E2 stores the formatted message in parser->error");
    CK(obs.vdispose_n == 0,
       "E2 disposes the animation before any timeline was published");
    CK(free_hits(a) == 1 && free_hits(anim_table) == 1,
       "E2 animation dispose still frees the timeline table and the record");
    CK(free_hits(anim) == 1,
       "E2 passes the CURRENT ANIMATION NODE as the setError json argument");
    CK(free_hits(bones) == 1 && free_hits(b) == 1,
       "E2 Json_dispose walks the animation node's children (bones, bone)");
    CK(free_hits(root) == 0,
       "E2 does not dispose the root tree (the json argument is the animation)");
    CK(free_hits(d) == 1 && free_hits(bone0) == 1,
       "E2 disposes the skeleton data (and its bone record) exactly once");
    pass("bone_not_found_e2");
}

/* ================================================================== */
/* 17. the duration only ever grows                                     */
/* ================================================================== */
static void duration_keeps_animation(void)
{
    tl_begin("duration_keeps_animation");
    void *bones_arr[1] = { bone_record("body") };
    spSkeletonData *d = make_data(bones_arr, 1);
    spAnimationShape *a = make_animation();
    a->duration = 9.0f;
    Json *bones = node("bones");
    Json *b = bone_node("body");
    Json *tl = timeline_node("rotate", 1);
    add(tl, rot_frame(0.5f, 1.0f));
    add(b, tl);
    add(bones, b);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 rotate over a longer animation completes");
    CK(bits(a->duration) == 0x41100000u,
       "the publish tail keeps the larger animation duration (9.0 over 0.5)");
    pass("duration_keeps_animation");
}

/* ================================================================== */
/* 18. two bones: independent lookup and per-timeline frame restart      */
/* ================================================================== */
static void two_bones(void)
{
    tl_begin("two_bones");
    void *bones_arr[2] = { bone_record("body"), bone_record("gear") };
    spSkeletonData *d = make_data(bones_arr, 2);
    spAnimationShape *a = make_animation();
    Json *bones = node("bones");
    Json *b0 = bone_node("body");
    Json *b1 = bone_node("gear");
    Json *t0 = timeline_node("rotate", 2);
    Json *t1 = timeline_node("translate", 1);
    add(t0, rot_frame(0.0f, 1.0f));
    add(t0, rot_frame(0.5f, 2.0f));
    add(t1, xy_frame(0.25f, 4.0f, 5.0f));
    add(b0, t0);
    add(b1, t1);
    add(bones, b0);
    add(bones, b1);

    CK(readSkeletonData_boneTimelines(bones, 0, d, a, &parser_obj) == 1,
       "B6 two-bone walk completes");
    CK(a->timelineCount == 2, "one timeline per bone is published");
    CK(((spBoneTimelineShape *)a->timelines[0])->boneIndex == 0
       && ((spBoneTimelineShape *)a->timelines[1])->boneIndex == 1,
       "each bone resolves to its own index through the real findBoneIndex");
    CK(obs.set_index[0] == 0 && obs.set_index[1] == 1 && obs.set_index[2] == 0,
       "the frame index restarts at 0 for the second bone's timeline");
    CK(bits(a->duration) == 0x3f000000u,
       "the larger last frame time wins (0.5 over 0.25)");
    pass("two_bones");
}

void _start(void)
{
    test = "startup"; init_heap();
    fixture_install_error_reporter();
    bones_key_absent();
    bones_without_children();
    bone_without_timelines_then_next();
    bone_index_first_of_duplicates();
    bone_index_second();
    bone_index_empty_data();
    translate_frames_scaled();
    scale_frames_not_scaled();
    shear_frames_not_scaled();
    rotate_frames_angle();
    curve_wiring();
    declared_vs_child_xy();
    declared_vs_child_rotate();
    dispatch_all_four();
    invalid_type_e3();
    bone_not_found_e2();
    duration_keeps_animation();
    two_bones();
    out("SUMMARY all declared bones timeline family contracts passed\n");
    quit(0);
}
