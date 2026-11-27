/* Reconstructed ARM32 consumers only.  The heap, libc strings, JSON tree
 * nodes, the reporter and every timeline creator/setter below are SYNTHETIC
 * providers; qemu executes our linked C, never original libyoyo bytes.
 * Original not executed; this is not an original-equivalence claim.
 *
 * Subject: the per-animation loop of spSkeletonJson_readSkeletonData
 * (0x28d318 outer head .. 0x28e79c back edge) assembled from the recovered
 * B1..B4 entry blocks and the nine timeline-family modules, plus the one
 * previously unowned block at 0x28ea10 (B5 slot-not-found).
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem/getString/getFloat/getInt   json_interface
 *   readCurve                                spine_read_curve
 *   toColor                                  spine_color
 *   _spSkeletonJson_setError                 spine_json_error
 *   Json_dispose / ReportSpineError          spine_json_support
 *   spAnimation_dispose / spSkeletonData_dispose / *_dispose
 *                                            spine_skeleton_data
 *   spSkeletonData_findBoneIndex             spine_read_tl_bones
 *   spSkeletonData_findBone/findSlotIndex/findSkin
 *                                            skeleton_find
 *   spSkin_getAttachment                     spine_skin
 *   _malloc/_calloc/_free                    spine_alloc
 *   all nine family drivers                  spine_read_tl_*
 *   B3/B4                                    spine_read_animations
 *
 * Declared synthetic boundaries (bodies NOT recovered; double models of the
 * disassembled stores, recording every argument):
 *   spAnimation_create 0x2812b4, spEventData_create 0x285b94,
 *   spEvent_create 0x285b44,
 *   spAttachmentTimeline_create/setFrame 0x282b94/0x282c1c,
 *   spColorTimeline_create/setFrame 0x282b3c/0x282b54,
 *   spTranslateTimeline_create 0x282abc, spRotateTimeline_create 0x282a90,
 *   spScaleTimeline_create 0x282b04, spShearTimeline_create 0x282b20,
 *   spTranslateTimeline_setFrame 0x282ad4, spRotateTimeline_setFrame 0x282aa8,
 *   spIkConstraintTimeline_create/setFrame 0x282f74/0x282f8c,
 *   spTransformConstraintTimeline_create/setFrame 0x282fb8/0x282fd0,
 *   spPathConstraintPositionTimeline_create 0x283010,
 *   spPathConstraintSpacingTimeline_create 0x28303c,
 *   spPathConstraintPositionTimeline_setFrame 0x283028,
 *   spPathConstraintMixTimeline_create/setFrame 0x283068/0x283080,
 *   spDeformTimeline_create/setFrame 0x282e58/0x282ef8,
 *   spDrawOrderTimeline_create/setFrame 0x282d4c/0x282ddc,
 *   spEventTimeline_create/setFrame 0x282c8c/0x282d14,
 *   spCurveTimeline_setStepped/setCurve (readCurve's recorders),
 *   spSkeletonData_findEvent/findIkConstraint/findTransformConstraint/
 *   findPathConstraint (linear scans with the same count/array/name shape).
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_animations_loop.h"
#include "family_includes.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../skeleton_find/src/skeleton_find.h"
#include "../../spine_skin/src/spine_skin.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

#define LOOP_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"
#define ANIM_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/Animation.c"
#define EVENT_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/Event.c"
#define CURVE_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/CurveTimeline.c"

/* ------------------------------------------------------------------ */
/* observation                                                         */
/* ------------------------------------------------------------------ */
#define MAX_MADE 64
#define MAX_CURVE 64

static struct {
    int disposed;                    /* vtable walks (timeline dispose probe) */
    int attach_disposed;             /* attachment dispose probe               */
    int curve_n;
    int curve_kind[MAX_CURVE];       /* 1 stepped, 2 curve                    */
    int curve_frame[MAX_CURVE];
    void *curve_tl[MAX_CURVE];
    uint32_t curve_args[MAX_CURVE][4];
    char creates[MAX_MADE + 1];      /* create() order, by kind letter        */
    int create_n;
    int acreate_n;
    int32_t acreate_count[8];        /* spAnimation_create arg 2              */
    void *anim[8];
    int devents_n;
    uint32_t devents_time[MAX_MADE];
    void *devents_data[MAX_MADE];
} obs;

static unsigned report_count;
static char reported[512], report_format[128];
static const char *g_tag[128];
static spSkeletonJson g_parser;

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

static void *loop_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "loop allocation roster/tag");
    void *p = reserve(n);
    g_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
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
static unsigned free_hits(const void *p)
{
    unsigned c = 0;
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) ++c;
    return c;
}

static void loop_begin(const char *name)
{
    begin(name);                       /* heap cursor, rosters, _setFree(free) */
    _setDebugMalloc(loop_alloc);
    memset(&obs, 0, sizeof(obs));
    memset(&g_parser, 0, sizeof(g_parser));
    g_parser.scale = bits(1.0f);       /* 0x28b720 writes 0x3f800000 */
    report_count = 0;
    reported[0] = report_format[0] = 0;
}

/* ------------------------------------------------------------------ */
/* synthetic timeline records (vtable -> dispose probe)                */
/* ------------------------------------------------------------------ */
static uint32_t g_tl_vtable[2];
static uint32_t g_attach_vtable[1];

static void tl_dispose_probe(spTimeline *self) { (void)self; ++obs.disposed; }
static void attach_dispose_probe(spAttachment *self) { (void)self; ++obs.attach_disposed; }

static void *tzero(size_t bytes)
{
    void *p = reserve((uint32_t)bytes);
    memset(p, 0, bytes);
    return p;
}

static void note_create(char kind, int frames, void *p)
{
    if (obs.create_n < MAX_MADE) obs.creates[obs.create_n] = kind;
    ++obs.create_n;
    (void)frames;
    (void)p;
}

/* every timeline record starts type(+0) vtable(+4); the probe does not free. */
static void tl_init(void *rec, uint32_t type, int frames, char kind)
{
    uint32_t *w = (uint32_t *)rec;
    w[0] = type;
    w[1] = (uint32_t)(uintptr_t)g_tl_vtable;
    note_create(kind, frames, rec);
}

/* ------------------------------------------------------------------ */
/* synthetic boundary entry points                                     */
/* ------------------------------------------------------------------ */

/* 0x2812b4: _calloc(1,16,tag,38); +0x00 name copy (strcpy), +0x08 count,
 * +0x0c _malloc(count<<2, tag, 41). B4 then zeroes +0x08 (0x28d4d4). */
spAnimation *spAnimation_create(const char *name, int32_t timelineCount)
{
    struct probe_anim { spAnimation anim; int32_t argc; uint32_t idx; };
    static struct probe_anim probes[8];
    struct probe_anim *p;

    if (obs.acreate_n >= 8) fail("animation probe table exhausted");
    p = &probes[obs.acreate_n];
    memset(p, 0, sizeof(*p));
    p->idx = (uint32_t)obs.acreate_n;
    p->argc = timelineCount;
    p->anim.name = (const char *)_malloc((uint32_t)strlen(name) + 1u, LOOP_TAG, 38u);
    strcpy((char *)p->anim.name, name);
    p->anim.timelineCount = timelineCount;
    p->anim.timelines = _malloc((uint32_t)timelineCount * 4u, LOOP_TAG, 41u);
    obs.acreate_count[obs.acreate_n] = timelineCount;
    obs.anim[obs.acreate_n] = &p->anim;
    ++obs.acreate_n;
    return &p->anim;
}

/* 0x285b94: _calloc(1,16,EventData.c,36); name copy line 37. */
spEventData *spEventData_create(const char *name)
{
    spEventData *e = (spEventData *)_calloc(1, 16, EVENT_TAG, 36u);
    e->name = (const char *)_malloc((uint32_t)strlen(name) + 1u, EVENT_TAG, 37u);
    strcpy((char *)e->name, name);
    return e;
}

/* 0x285b44: _calloc(1,20,Event.c,36); +0x00 data, +0x04 time. */
void *spEvent_create(float time, const void *data)
{
    spEventShape *e = (spEventShape *)_calloc(1, 20, EVENT_TAG, 36u);
    e->data = data;
    e->time = time;
    obs.devents_time[obs.devents_n] = bits(time);
    obs.devents_data[obs.devents_n] = (void *)data;
    ++obs.devents_n;
    return e;
}

void *spAttachmentTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spAttachmentTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x11u, frameCount, 'A');
    t->frameCount = frameCount;
    t->frames = tzero(n * 4u);
    t->attachmentNames = tzero(n * 4u);
    return t;
}
void spAttachmentTimeline_setFrame(void *timeline, int frameIndex, float time,
                                   const char *attachmentName)
{
    spAttachmentTimelineShape *t = (spAttachmentTimelineShape *)timeline;
    t->frames[frameIndex] = time;
    t->attachmentNames[frameIndex] = (char *)attachmentName;
}

void *spColorTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spColorTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x22u, frameCount, 'C');
    t->frameFloatCount = frameCount * 5;
    t->frames = tzero(n * 5u * 4u);
    return t;
}
void spColorTimeline_setFrame(void *timeline, int frameIndex, float time,
                              float r, float g, float b, float a)
{
    spColorTimelineShape *t = (spColorTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 5u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = r;
    t->frames[base + 2u] = g;
    t->frames[base + 3u] = b;
    t->frames[base + 4u] = a;
}

void *spRotateTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spBoneTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x31u, frameCount, 'R');
    t->frameFloatCount = frameCount * 2;
    t->frames = tzero(n * 2u * 4u);
    return t;
}
void *spTranslateTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spBoneTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x32u, frameCount, 'T');
    t->frameFloatCount = frameCount * 3;
    t->frames = tzero(n * 3u * 4u);
    return t;
}
void *spScaleTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spBoneTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x33u, frameCount, 'S');
    t->frameFloatCount = frameCount * 3;
    t->frames = tzero(n * 3u * 4u);
    return t;
}
void *spShearTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spBoneTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 0x34u, frameCount, 'H');
    t->frameFloatCount = frameCount * 3;
    t->frames = tzero(n * 3u * 4u);
    return t;
}
/* 0x282ad4: stride 3 (time, x, y).  Also the target of the 4-byte
 * spScaleTimeline_setFrame / spShearTimeline_setFrame thunks. */
void spTranslateTimeline_setFrame(void *timeline, int frameIndex, float time,
                                  float x, float y)
{
    spBoneTimelineShape *t = (spBoneTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 3u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = x;
    t->frames[base + 2u] = y;
}
void spRotateTimeline_setFrame(void *timeline, int frameIndex, float time,
                               float angle)
{
    spBoneTimelineShape *t = (spBoneTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 2u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = angle;
}

void *spIkConstraintTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spIkConstraintTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 9u, frameCount, 'K');
    t->frameFloatCount = frameCount * 3;
    t->frames = tzero(n * 3u * 4u);
    t->ikConstraintIndex = 0x7f7f7f7f;          /* create-time calloc word */
    return t;
}
void spIkConstraintTimeline_setFrame(void *timeline, int frameIndex, float time,
                                     float mix, int bend)
{
    spIkConstraintTimelineShape *t = (spIkConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 3u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = mix;
    t->frames[base + 2u] = (float)bend;         /* 0x282f90 vcvt.f32.s32 */
}

void *spTransformConstraintTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spTransformConstraintTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 10u, frameCount, 'X');
    t->frameFloatCount = frameCount * 5;
    t->frames = tzero(n * 5u * 4u);
    t->transformConstraintIndex = 0x7f7f7f7f;
    return t;
}
void spTransformConstraintTimeline_setFrame(void *timeline, int frameIndex,
                                            float time, float rotateMix,
                                            float translateMix, float scaleMix,
                                            float shearMix)
{
    spTransformConstraintTimelineShape *t = (spTransformConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 5u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = rotateMix;
    t->frames[base + 2u] = translateMix;
    t->frames[base + 3u] = scaleMix;
    t->frames[base + 4u] = shearMix;
}

static void *path_timeline_create(uint32_t type, int frameCount, char kind)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spPathConstraintTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, type, frameCount, kind);
    t->frameFloatCount = frameCount * 2;
    t->frames = tzero(n * 2u * 4u);
    t->pathConstraintIndex = 0x7f7f7f7f;
    return t;
}
void *spPathConstraintPositionTimeline_create(int frameCount)
{
    return path_timeline_create(11u, frameCount, 'P');
}
void *spPathConstraintSpacingTimeline_create(int frameCount)
{
    return path_timeline_create(12u, frameCount, 'Q');
}
void spPathConstraintPositionTimeline_setFrame(void *timeline, int frameIndex,
                                               float time, float value)
{
    spPathConstraintTimelineShape *t = (spPathConstraintTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 2u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = value;
}

void *spPathConstraintMixTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spPathConstraintTimelineMixShape *t = tzero(sizeof(*t));
    tl_init(t, 13u, frameCount, 'M');
    t->frameFloatCount = frameCount * 3;
    t->frames = tzero(n * 3u * 4u);
    t->pathConstraintIndex = 0x7f7f7f7f;
    return t;
}
void spPathConstraintMixTimeline_setFrame(void *timeline, int frameIndex,
                                          float time, float rotateMix,
                                          float translateMix)
{
    spPathConstraintTimelineMixShape *t = (spPathConstraintTimelineMixShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 3u;
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = rotateMix;
    t->frames[base + 2u] = translateMix;
}

void *spDeformTimeline_create(int frameCount, int vertexFloatCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spDeformTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 8u, frameCount, 'D');
    t->frameCount = frameCount;
    t->frames = tzero(n * 4u);
    t->vertexFloatCount = vertexFloatCount;
    t->vertices = tzero(n * 4u);
    return t;
}
void spDeformTimeline_setFrame(void *timeline, int frameIndex, float time,
                               const void *vertices)
{
    spDeformTimelineShape *t = (spDeformTimelineShape *)timeline;
    uint32_t bytes = (uint32_t)t->vertexFloatCount * 4u;
    t->frames[frameIndex] = time;
    _free(t->vertices[frameIndex]);
    if (vertices == 0) {
        t->vertices[frameIndex] = 0;
        return;
    }
    t->vertices[frameIndex] = _malloc(bytes, LOOP_TAG, 799u);
    memcpy(t->vertices[frameIndex], vertices, bytes);
}

void *spDrawOrderTimeline_create(int frameCount, int slotsCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spDrawOrderTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 7u, frameCount, 'O');
    t->frameCount = frameCount;
    t->times = tzero(n * 4u);
    t->drawOrders = tzero(n * 4u);
    t->slotsCount = slotsCount;
    return t;
}
void spDrawOrderTimeline_setFrame(void *timeline, int frameIndex, float time,
                                  const int32_t *drawOrder)
{
    spDrawOrderTimelineShape *t = (spDrawOrderTimelineShape *)timeline;
    t->times[frameIndex] = time;
    _free(t->drawOrders[frameIndex]);
    if (drawOrder == 0) {
        t->drawOrders[frameIndex] = 0;
        return;
    }
    t->drawOrders[frameIndex] = _malloc((uint32_t)t->slotsCount * 4u, LOOP_TAG, 690u);
    memcpy(t->drawOrders[frameIndex], drawOrder, (uint32_t)t->slotsCount * 4u);
}

void *spEventTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spEventTimelineShape *t = tzero(sizeof(*t));
    tl_init(t, 6u, frameCount, 'E');
    t->frameCount = frameCount;
    t->times = tzero(n * 4u);
    t->events = tzero(n * 4u);
    return t;
}
void spEventTimeline_setFrame(void *timeline, int frameIndex, void *event)
{
    spEventTimelineShape *t = (spEventTimelineShape *)timeline;
    spEventShape *e = (spEventShape *)event;
    t->times[frameIndex] = e->time;
    _free(t->events[frameIndex]);
    t->events[frameIndex] = (spEventShape *)event;
}

void spCurveTimeline_setStepped(void *curveTimeline, int frameIndex)
{
    if (obs.curve_n >= MAX_CURVE) fail("curve roster");
    obs.curve_kind[obs.curve_n] = 1;
    obs.curve_frame[obs.curve_n] = frameIndex;
    obs.curve_tl[obs.curve_n] = curveTimeline;
    ++obs.curve_n;
}
void spCurveTimeline_setCurve(void *curveTimeline, int frameIndex, float cx1,
                              float cy1, float cx2, float cy2)
{
    if (obs.curve_n >= MAX_CURVE) fail("curve roster");
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
/* synthetic find* boundaries (same count/array/name scan shape)       */
/* ------------------------------------------------------------------ */
static uint32_t word_at(const void *p, unsigned i)
{
    uint32_t w;
    memcpy(&w, (const char *)p + i * 4u, 4u);
    return w;
}

/* names at +0x00 for ik/transform/path constraint records (fixture layout) */
static void *scan_named(void *data_raw, const char *name, unsigned count_off,
                        unsigned array_off, unsigned name_off)
{
    int32_t count = (int32_t)word_at(data_raw, count_off / 4u);
    void **array;
    if (count <= 0) return 0;
    array = (void **)(uintptr_t)word_at(data_raw, array_off / 4u);
    for (int32_t i = 0; i < count; ++i) {
        void *rec = array[i];
        const char *n = (const char *)(uintptr_t)word_at(rec, name_off / 4u);
        if (strcmp(n, name) == 0) return rec;
    }
    return 0;
}
void *spSkeletonData_findIkConstraint(void *data, const char *name)
{
    return scan_named(data, name, 0x3cu, 0x40u, 0x00u);
}
void *spSkeletonData_findTransformConstraint(void *data, const char *name)
{
    return scan_named(data, name, 0x44u, 0x48u, 0x00u);
}
void *spSkeletonData_findPathConstraint(void *data, const char *name)
{
    return scan_named(data, name, 0x4cu, 0x50u, 0x00u);
}
/* 0x28b180: events +0x2c/+0x30, EventData name +0x00, signed count guard. */
void *spSkeletonData_findEvent(void *data, const char *name)
{
    return scan_named(data, name, 0x2cu, 0x30u, 0x00u);
}

/* Named gaps only reached by spine_json_error's file wrapper. */
spSkeletonData *spSkeletonJson_readSkeletonData(spSkeletonJson *self, const char *data)
{
    (void)self; (void)data;
    return 0;
}
void *_readFile(const char *path, int32_t *out_size)
{
    (void)path; if (out_size) *out_size = 0;
    return 0;
}

/* ------------------------------------------------------------------ */
/* data records                                                        */
/* ------------------------------------------------------------------ */
static spSkeletonData g_data;
static void *g_slots_arr[2];
static void *g_bones_arr[2];
static void *g_skins_arr[1];
static void *g_events_arr[1];
static void *g_anim_arr[8];
static void *g_ik_arr[2];
static void *g_tr_arr[2];
static void *g_path_arr[2];
static void *g_base_vertices;
static void *g_attachment;
static void *g_skin;

static void *named_record(const char *name, unsigned name_off)
{
    uint32_t *r = (uint32_t *)tzero(16);
    r[name_off / 4u] = (uint32_t)(uintptr_t)name;
    return r;
}

static void build_data(void)
{
    memset(&g_data, 0, sizeof(g_data));

    g_slots_arr[0] = named_record("slotA", 4u);
    g_slots_arr[1] = named_record("slotB", 4u);
    g_bones_arr[0] = named_record("arm", 4u);
    g_bones_arr[1] = named_record("leg", 4u);
    g_events_arr[0] = tzero(sizeof(spEventDataEventShape));
    {
        spEventDataEventShape *e = (spEventDataEventShape *)g_events_arr[0];
        e->name = (char *)"footstep";
        e->intValue = 7;
        e->floatValue = 2.5f;
        e->stringValue = (char *)"def";
    }
    g_ik_arr[0] = named_record("ik0", 0u);
    g_ik_arr[1] = named_record("ik1", 0u);
    g_tr_arr[0] = named_record("tr0", 0u);
    g_tr_arr[1] = named_record("tr1", 0u);
    /* the two path records carry the 24-byte spPathConstraintData head the
     * family reads (+0x10 positionMode, +0x14 spacingMode); name at +0x00 */
    g_path_arr[0] = tzero(sizeof(spPathConstraintDataPathShape));
    g_path_arr[1] = tzero(sizeof(spPathConstraintDataPathShape));
    {
        spPathConstraintDataPathShape *p0 = (spPathConstraintDataPathShape *)g_path_arr[0];
        spPathConstraintDataPathShape *p1 = (spPathConstraintDataPathShape *)g_path_arr[1];
        p0->positionMode = 0;
        p0->spacingMode = 0;
        p1->positionMode = 0;
        p1->spacingMode = 0;
        ((uint32_t *)g_path_arr[0])[0] = (uint32_t)(uintptr_t)"p0";
        ((uint32_t *)g_path_arr[1])[0] = (uint32_t)(uintptr_t)"p1";
    }

    g_base_vertices = tzero(4u * 4u);
    ((float *)g_base_vertices)[0] = 10.0f;
    ((float *)g_base_vertices)[1] = 20.0f;
    ((float *)g_base_vertices)[2] = 30.0f;
    ((float *)g_base_vertices)[3] = 40.0f;

    g_attachment = tzero(0x24u);
    {
        spVertexAttachmentDeformShape *a = (spVertexAttachmentDeformShape *)g_attachment;
        a->bones = 0;                                  /* non-weighted */
        a->verticesCount = 4;
        a->vertices = (const float *)g_base_vertices;
        ((uint32_t *)g_attachment)[2] = (uint32_t)(uintptr_t)g_attach_vtable;
    }
    g_attach_vtable[0] = (uint32_t)(uintptr_t)attach_dispose_probe;

    g_skin = tzero(8u);
    {
        uint32_t *s = (uint32_t *)g_skin;
        uint32_t *entry;
        s[0] = (uint32_t)(uintptr_t)"default";
        entry = (uint32_t *)tzero(16u);
        entry[0] = 0u;                                 /* slotIndex */
        entry[1] = (uint32_t)(uintptr_t)"atlas";
        entry[2] = (uint32_t)(uintptr_t)g_attachment;
        entry[3] = 0u;                                 /* next */
        s[1] = (uint32_t)(uintptr_t)entry;
    }
    g_skins_arr[0] = g_skin;

    for (unsigned i = 0; i < 8; ++i) g_anim_arr[i] = 0;

    ((uint32_t *)&g_data)[4] = 2u;  ((uint32_t *)&g_data)[5] = (uint32_t)(uintptr_t)g_bones_arr;
    ((uint32_t *)&g_data)[6] = 2u;  ((uint32_t *)&g_data)[7] = (uint32_t)(uintptr_t)g_slots_arr;
    ((uint32_t *)&g_data)[8] = 1u;  ((uint32_t *)&g_data)[9] = (uint32_t)(uintptr_t)g_skins_arr;
    ((uint32_t *)&g_data)[11] = 1u; ((uint32_t *)&g_data)[12] = (uint32_t)(uintptr_t)g_events_arr;
    ((uint32_t *)&g_data)[13] = 0u; ((uint32_t *)&g_data)[14] = (uint32_t)(uintptr_t)g_anim_arr;
    ((uint32_t *)&g_data)[15] = 2u; ((uint32_t *)&g_data)[16] = (uint32_t)(uintptr_t)g_ik_arr;
    ((uint32_t *)&g_data)[17] = 2u; ((uint32_t *)&g_data)[18] = (uint32_t)(uintptr_t)g_tr_arr;
    ((uint32_t *)&g_data)[19] = 2u; ((uint32_t *)&g_data)[20] = (uint32_t)(uintptr_t)g_path_arr;
}

/* ------------------------------------------------------------------ */
/* JSON builders                                                       */
/* ------------------------------------------------------------------ */
static Json *jmap(const char *key, uint32_t size)
{
    Json *n = node(key);
    n->unk_0c = size;
    return n;
}
static Json *jnum(const char *key, float v)
{
    Json *n = node(key);
    n->float_value = v;
    return n;
}
static Json *jint(const char *key, int32_t v)
{
    Json *n = node(key);
    n->int_value = v;
    return n;
}
static Json *jstr(const char *key, const char *v) { return string(key, v); }
static Json *jfalse(const char *key)
{
    Json *n = node(key);
    n->unk_08 = 2u;                    /* Json false */
    return n;
}
static Json *jcurve(void)
{
    Json *a = node("curve");
    a->unk_08 = 5u;                    /* Json array */
    const float v[4] = {0.125f, 0.25f, 0.375f, 0.5f};
    for (unsigned i = 0; i < 4; ++i) {
        Json *n = node(0);
        n->float_value = v[i];
        add(a, n);
    }
    return a;
}
static Json *jstepped(void)
{
    Json *n = node("curve");
    n->unk_08 = 4u;                    /* Json string */
    n->string_value = "stepped";
    return n;
}
static Json *jfloats(const char *key, const float *v, unsigned count)
{
    Json *a = node(key);
    a->unk_0c = count;
    for (unsigned i = 0; i < count; ++i) {
        Json *n = node(0);
        n->float_value = v[i];
        add(a, n);
    }
    return a;
}
/* one timeline frame = a Json object (no key) holding the given members */
static Json *jframe(void) { return node(0); }

/* ------------------------------------------------------------------ */
/* animation trees                                                     */
/* ------------------------------------------------------------------ */

/* the animation of loop_full_nine_families: every family, every bone kind,
 * one skipped "mix" plus one foreign-named path mix, two deform frames. */
#define F_BONES 1u
#define F_SLOTS 2u
#define F_IK 4u
#define F_TR 8u
#define F_PATH 16u
#define F_DEFORM 32u
#define F_DRAW 64u
#define F_EVENT 128u
static Json *full_animation_mask(const char *name, unsigned mask)
{
    Json *a = node(name);
    Json *bones = jmap("bones", 5);
    Json *slots = jmap("slots", 2);
    Json *ik = jmap("ik", 1);
    Json *transform = jmap("transform", 1);
    Json *paths = jmap("paths", 3);
    Json *deform = jmap("deform", 1);
    Json *drawOrder = jmap("drawOrder", 1);
    Json *events = jmap("events", 1);
    Json *n, *m, *t;

    /* bones: arm has 4 timelines, leg 1 */
    Json *arm = jmap("arm", 4);
    t = jmap("rotate", 2);
    m = jframe(); add(m, jnum("time", 0.25f)); add(m, jnum("angle", 30.0f));
    add(m, jcurve()); add(t, m);
    m = jframe(); add(m, jnum("time", 0.5f)); add(m, jnum("angle", 60.0f)); add(t, m);
    add(arm, t);
    t = jmap("translate", 2);
    m = jframe(); add(m, jnum("time", 0.375f)); add(m, jnum("x", 1.0f));
    add(m, jnum("y", 2.0f)); add(t, m);
    m = jframe(); add(m, jnum("time", 0.625f)); add(m, jnum("x", 3.0f));
    add(m, jnum("y", 4.0f)); add(t, m);
    add(arm, t);
    t = jmap("scale", 2);
    m = jframe(); add(m, jnum("time", 0.5f)); add(m, jnum("x", 2.0f));
    add(m, jnum("y", 2.0f)); add(t, m);
    m = jframe(); add(m, jnum("time", 0.875f)); add(m, jnum("x", 2.0f));
    add(m, jnum("y", 2.0f)); add(t, m);
    add(arm, t);
    t = jmap("shear", 1);
    m = jframe(); add(m, jnum("time", 1.0f)); add(m, jnum("x", 5.0f));
    add(m, jnum("y", 6.0f)); add(t, m);
    add(arm, t);
    add(bones, arm);
    Json *leg = jmap("leg", 1);
    t = jmap("rotate", 1);
    m = jframe(); add(m, jnum("time", 0.75f)); add(m, jnum("angle", -10.0f));
    add(t, m);
    add(leg, t);
    add(bones, leg);

    /* slots: attachment (string + false) and color (stepped curve) */
    Json *slotA = jmap("slotA", 2);
    t = jmap("attachment", 2);
    m = jframe(); add(m, jstr("name", "atlas")); add(m, jnum("time", 0.125f));
    add(t, m);
    m = jframe(); add(m, jfalse("name")); add(m, jnum("time", 0.25f)); add(t, m);
    add(slotA, t);
    t = jmap("color", 1);
    m = jframe(); add(m, jnum("time", 0.75f)); add(m, jstr("color", "80ff00ff"));
    add(m, jstepped()); add(t, m);
    add(slotA, t);
    add(slots, slotA);

    /* ik: bendPositive 0 -> -1 */
    t = jmap("ik1", 1);
    m = jframe(); add(m, jnum("time", 0.875f)); add(m, jnum("mix", 0.5f));
    add(m, jint("bendPositive", 0)); add(t, m);
    add(ik, t);

    /* transform */
    t = jmap("tr1", 1);
    m = jframe(); add(m, jnum("time", 0.9375f));
    add(m, jnum("rotateMix", 0.1f)); add(m, jnum("translateMix", 0.2f));
    add(m, jnum("scaleMix", 0.3f)); add(m, jnum("shearMix", 0.4f));
    add(t, m);
    add(transform, t);

    /* paths: position, a foreign-named mix (publishes), spacing */
    Json *path1 = jmap("p1", 3);
    t = jmap("position", 2);
    m = jframe(); add(m, jnum("time", 0.25f)); add(m, jnum("position", 5.0f));
    add(t, m);
    m = jframe(); add(m, jnum("time", 0.5f)); add(m, jnum("position", 7.0f));
    add(t, m);
    add(path1, t);
    t = jmap("translateMix", 1);
    m = jframe(); add(m, jnum("time", 1.125f)); add(m, jnum("rotateMix", 0.6f));
    add(m, jnum("translateMix", 0.7f)); add(t, m);
    add(path1, t);
    t = jmap("spacing", 1);
    m = jframe(); add(m, jnum("time", 0.625f)); add(m, jnum("spacing", 3.0f));
    add(t, m);
    add(path1, t);
    add(paths, path1);

    /* deform: default -> slotA -> attachment "atlas", two frames */
    Json *skin = jmap("default", 1);
    Json *dslot = jmap("slotA", 1);
    t = jmap("atlas", 2);
    {
        const float v0[4] = {1.0f, 2.0f, 3.0f, 4.0f};
        const float v1[4] = {5.0f, 6.0f, 7.0f, 8.0f};
        m = jframe(); add(m, jfloats("vertices", v0, 4)); add(m, jint("offset", 0));
        add(m, jnum("time", 0.25f)); add(t, m);
        m = jframe(); add(m, jfloats("vertices", v1, 4)); add(m, jint("offset", 0));
        add(m, jnum("time", 0.5f)); add(t, m);
    }
    add(dslot, t);
    add(skin, dslot);
    add(deform, skin);

    /* drawOrder: the node's children ARE the frames (no timeline wrapper) */
    m = jframe();
    n = jmap("offsets", 1);
    {
        Json *e = node(0);
        add(e, jstr("slot", "slotA"));
        add(e, jint("offset", 0));
        add(n, e);
    }
    add(m, n);
    add(m, jnum("time", 0.875f));
    add(drawOrder, m);

    /* events: likewise, one child frame; the string copy is line 494 */
    m = jframe();
    add(m, jstr("name", "footstep"));
    add(m, jnum("time", 0.125f));
    add(m, jint("int", 3));
    add(m, jnum("float", 1.5f));
    add(m, jstr("string", "boom"));
    add(events, m);

    if (mask & F_BONES) add(a, bones);
    if (mask & F_SLOTS) add(a, slots);
    if (mask & F_IK) add(a, ik);
    if (mask & F_TR) add(a, transform);
    if (mask & F_PATH) add(a, paths);
    if (mask & F_DEFORM) add(a, deform);
    if (mask & F_DRAW) add(a, drawOrder);
    if (mask & F_EVENT) add(a, events);
    return a;
}
static Json *full_animation(const char *name) { return full_animation_mask(name, 0xffu); }

static spAnimationFrame g_frame;

/* run the loop over one animation; returns the loop result */
static void *run_loop(Json *animation)
{
    spAnimationFrame *f = &g_frame;
    memset(f, 0, sizeof(*f));
    f->animation = animation;
    return readSkeletonData_animationsLoop(animation, f, &g_data, &g_parser);
}

/* kind letter of timeline i via the make-order table (pointer identity) */
static char made_kind(const void *p)
{
    /* probe_anim records only animation pointers; timeline records are
     * identified by their type word, which the synthetic creators set. */
    uint32_t type = word_at(p, 0);
    switch (type) {
    case 0x11u: return 'A';
    case 0x22u: return 'C';
    case 0x31u: return 'R';
    case 0x32u: return 'T';
    case 0x33u: return 'S';
    case 0x34u: return 'H';
    case 9u:    return 'K';
    case 10u:   return 'X';
    case 11u:   return 'P';
    case 12u:   return 'Q';
    case 13u:   return 'M';
    case 8u:    return 'D';
    case 7u:    return 'O';
    case 6u:    return 'E';
    default:    return '?';
    }
}

static void timeline_kinds(const spAnimation *a, char *out)
{
    for (int32_t i = 0; i < a->timelineCount; ++i)
        out[i] = made_kind(((void **)(void *)a->timelines)[i]);
    out[a->timelineCount > 0 ? a->timelineCount : 0] = 0;
}

/* ================================================================== */
/* tests                                                              */
/* ================================================================== */

/* 1. the full nine-family animation: creates, publications, indices */
static void loop_full_nine_families(void)
{
    loop_begin("loop_full_nine_families");
    build_data();
    Json *a = full_animation("walk");
    void *r = run_loop(a);
    char kinds[32];

    CK(r == &g_data, "loop returns the data pointer when the outer loop ends");
    CK(obs.acreate_n == 1 && obs.acreate_count[0] == 15,
       "B4 hands spAnimation_create the asymmetric sum (5 bones + 2 slots + 1 ik + 1 transform + 3 paths + 1 deform + 1 drawOrder + 1 events = 15)");
    CK(alloc_count(41) == 1 && alloc_bytes(41) == 15u * 4u,
       "the timeline array is the line-41 malloc of count*4 bytes");
    CK(obs.create_n == 15, "all nine families created 15 timelines");
    CK(strcmp(obs.creates, "ACRTSHRKXPMQDOE") == 0,
       "family call order is slots, bones, ik, transform, paths(+mix), deform, drawOrder, events");
    CK(g_frame.animation == 0, "the outer cursor advances past the only animation");
    CK(g_frame.bonesKey != 0 && strcmp(g_frame.bonesKey, "bones") == 0 &&
       g_frame.slotsKey != 0 && strcmp(g_frame.slotsKey, "slots") == 0 &&
       g_frame.ikKey != 0 && strcmp(g_frame.ikKey, "ik") == 0 &&
       g_frame.transformKey != 0 && strcmp(g_frame.transformKey, "transform") == 0,
       "B3 preamble cached the four loop-invariant key pointers in the frame");
    CK(g_frame.bones != 0 && strcmp(g_frame.bones->name, "bones") == 0 &&
       g_frame.ik != 0 && strcmp(g_frame.ik->name, "ik") == 0 &&
       g_frame.transform != 0 && strcmp(g_frame.transform->name, "transform") == 0 &&
       g_frame.paths != 0 && strcmp(g_frame.paths->name, "paths") == 0 &&
       g_frame.deform != 0 && strcmp(g_frame.deform->name, "deform") == 0 &&
       g_frame.drawOrder != 0 && strcmp(g_frame.drawOrder->name, "drawOrder") == 0 &&
       g_frame.events != 0 && strcmp(g_frame.events->name, "events") == 0,
       "the eight Json_getItem results land in their own frame slots");
    CK(g_frame.slotsChild != 0 && strcmp(g_frame.slotsChild->name, "slotA") == 0,
       "B4 spills the slots child list (not the slots node) for B5");
    CK(((spSkeletonDataEventShape *)&g_data)->animationsCount == 1,
       "exactly one animation is published");
    CK(((void **)(uintptr_t)word_at(&g_data, 14))[0] == obs.anim[0],
       "animations[0] is the record spAnimation_create returned");

    spAnimation *anim = (spAnimation *)obs.anim[0];
    CK(anim->timelineCount == 15, "all 15 timelines are published");
    timeline_kinds(anim, kinds);
    CK(strcmp(kinds, "ACRTSHRKXPMQDOE") == 0,
       "timelines[] preserves the family/publication order");
    CK(((spAnimationPathShape *)anim)->duration == 1.125f,
       "duration is the max of every family's last frame time");

    /* indices written through the real lookup/scan chains */
    void **tl = (void **)(void *)anim->timelines;
    CK(((spAttachmentTimelineShape *)tl[0])->slotIndex == 0,
       "attachment timeline +0x10 = findSlotIndex(slotA) == 0");
    CK(((spColorTimelineShape *)tl[1])->slotIndex == 0,
       "color timeline +0x14 = the same slot index");
    CK(((spBoneTimelineShape *)tl[2])->boneIndex == 0 &&
       ((spBoneTimelineShape *)tl[6])->boneIndex == 1,
       "rotate timelines carry findBoneIndex(arm)==0 and (leg)==1");
    CK(((spIkConstraintTimelineShape *)tl[7])->ikConstraintIndex == 1,
       "ik timeline +0x14 = the pointer-scan index 1 (ik1 is array[1])");
    CK(((spTransformConstraintTimelineShape *)tl[8])->transformConstraintIndex == 1,
       "transform timeline +0x14 = the pointer-scan index 1 (tr1 is array[1])");
    CK(((spPathConstraintTimelineShape *)tl[9])->pathConstraintIndex == 1 &&
       ((spPathConstraintTimelineMixShape *)tl[10])->pathConstraintIndex == 1 &&
       ((spPathConstraintTimelineShape *)tl[11])->pathConstraintIndex == 1,
       "all three path timelines carry the [sp+0x2c] cell index 1 (p1 is array[1])");
    CK(((spDeformTimelineShape *)tl[12])->slotIndex == 0 &&
       ((spDeformTimelineShape *)tl[12])->attachment == g_attachment,
       "deform timeline +0x1c/+0x20 = slot index and attachment pointer");
    CK(((spDrawOrderTimelineShape *)tl[13])->slotsCount == 2,
       "drawOrder create received data->slotsCount == 2");

    /* frame values through the synthetic setters */
    {
        spBoneTimelineShape *rot = (spBoneTimelineShape *)tl[2];
        CK(rot->frames[0] == 0.25f && rot->frames[1] == 30.0f &&
           rot->frames[2] == 0.5f && rot->frames[3] == 60.0f,
           "rotate setFrame stores time/angle with a two-float stride");
        spBoneTimelineShape *trn = (spBoneTimelineShape *)tl[3];
        CK(trn->frames[0] == 0.375f && trn->frames[1] == 1.0f &&
           trn->frames[2] == 2.0f,
           "translate setFrame receives x/y multiplied by parser->scale (1.0 here)");
        spColorTimelineShape *col = (spColorTimelineShape *)tl[1];
        CK(col->frames[0] == 0.75f && bits(col->frames[1]) == bits(toColor("80ff00ff", 0)) &&
           bits(col->frames[2]) == bits(toColor("80ff00ff", 1)) &&
           bits(col->frames[3]) == bits(toColor("80ff00ff", 2)) &&
           bits(col->frames[4]) == bits(toColor("80ff00ff", 3)),
           "color setFrame stores time plus the four toColor channels");
        spIkConstraintTimelineShape *ik = (spIkConstraintTimelineShape *)tl[7];
        CK(ik->frames[0] == 0.875f && ik->frames[1] == 0.5f &&
           ik->frames[2] == -1.0f,
           "ik setFrame stores time/mix and bendPositive 0 -> -1.0f");
        spPathConstraintTimelineShape *pp = (spPathConstraintTimelineShape *)tl[9];
        CK(pp->frames[0] == 0.25f && pp->frames[1] == 5.0f &&
           pp->frames[2] == 0.5f && pp->frames[3] == 7.0f,
           "path position frames store time/value (positionMode 0 -> parser->scale)");
        spDeformTimelineShape *df = (spDeformTimelineShape *)tl[12];
        CK(df->frames[0] == 0.25f && df->frames[1] == 0.5f,
           "deform frames store their times");
        CK(((float *)df->vertices[0])[0] == 11.0f &&
           ((float *)df->vertices[0])[1] == 22.0f &&
           ((float *)df->vertices[0])[2] == 33.0f &&
           ((float *)df->vertices[0])[3] == 44.0f,
           "deform runtime adds attachment->vertices to the frame vertices (10+1, 20+2, ...)");
        spDrawOrderTimelineShape *dor = (spDrawOrderTimelineShape *)tl[13];
        CK(dor->times[0] == 0.875f && dor->drawOrders[0][0] == 0 &&
           dor->drawOrders[0][1] == 1,
           "drawOrder setFrame receives the merged order {0,1}");
        spEventTimelineShape *ev = (spEventTimelineShape *)tl[14];
        CK(ev->times[0] == 0.125f && ev->events[0]->intValue == 3 &&
           ev->events[0]->floatValue == 1.5f &&
           strcmp(ev->events[0]->stringValue, "boom") == 0,
           "event frame builds spEvent(time, EventData) and overrides int/float/string");
        CK(strcmp((const char *)ev->events[0]->data, "footstep") == 0 ||
           ((spEventDataEventShape *)ev->events[0]->data)->name != 0,
           "event data pointer is the findEvent result");
    }
    pass("loop_full_nine_families");
}

/* ------------------------------------------------------------------ */
/* small tree helpers                                                  */
/* ------------------------------------------------------------------ */
static int contains(const char *hay, const char *needle)
{
    size_t ln = strlen(needle);
    for (; *hay; ++hay) {
        size_t i = 0;
        while (i < ln && hay[i] == needle[i]) ++i;
        if (i == ln) return 1;
    }
    return ln == 0;
}
static void sib(Json *a, Json *b) { a->next = b; }
static Json *one_frame(const char *key, float value, float t)
{
    Json *f = jframe();
    add(f, jnum("time", t));
    add(f, jnum(key, value));
    return f;
}
/* a single-bone rotate animation; returns the animation node */
static Json *mini_bones(const char *name, const char *bone, float t, float angle)
{
    Json *a = node(name);
    Json *bones = jmap("bones", 1);
    Json *b = jmap(bone, 1);
    Json *tl = jmap("rotate", 1);
    add(tl, one_frame("angle", angle, t));
    add(b, tl);
    add(bones, b);
    add(a, bones);
    return a;
}
/* a map with `n` children carrying only the +0x0c size word B4 reads */
static Json *sized_children(const char *key, const uint32_t *sizes,
                            const char *const *names, unsigned n)
{
    Json *m = jmap(key, 0);
    for (unsigned i = 0; i < n; ++i) add(m, jmap(names[i], sizes[i]));
    return m;
}

/* 2. B4's four sum shapes: child loops (bones/slots/paths), single field
 * reads (ik/transform), the deform skin->slot double loop, and +1 for
 * drawOrder/events. */
static void loop_b4_sum_asymmetry(void)
{
    {
        loop_begin("loop_b4_sum_asymmetry");
        build_data();
        Json *a = node("sums");
        const uint32_t bs[2] = {3, 2};
        const char *bn[2] = {"arm", "leg"};
        const uint32_t ss[2] = {1, 1};
        const char *sn[2] = {"slotA", "slotB"};
        const uint32_t ps[2] = {1, 3};
        const char *pn[2] = {"p0", "p1"};
        Json *deform = jmap("deform", 1);
        Json *skin = jmap("default", 1);
        Json *dslot = jmap("slotA", 2);          /* slot size 2 */
        add(skin, dslot);
        add(deform, skin);
        add(a, sized_children("bones", bs, bn, 2));
        add(a, sized_children("slots", ss, sn, 2));
        add(a, jmap("ik", 2));                    /* single field read */
        add(a, jmap("transform", 3));             /* single field read */
        add(a, sized_children("paths", ps, pn, 2));
        add(a, deform);
        add(a, jmap("drawOrder", 1));             /* +1, declared 1 */
        add(a, jmap("events", 1));                /* +1, declared 1 */
        void *r = run_loop(a);
        CK(r == &g_data, "sum case A completes");
        CK(obs.acreate_count[0] == 20,
           "B4 sums 3+2 bones, 1+1 slots, ik field 2, transform field 3, 1+3 paths, deform skin->slot 2, drawOrder 1, events 1 = 20");
        CK(alloc_bytes(41) == 20u * 4u,
           "the line-41 allocation is the summed capacity, not the published count");
        CK(((spSkeletonDataEventShape *)&g_data)->animationsCount == 1 &&
           ((spAnimation *)obs.anim[0])->timelineCount == 2 &&
           obs.create_n == 2 && obs.creates[0] == 'O' && obs.creates[1] == 'E',
           "the four child/field shapes declare capacity; only drawOrder/events (node presence) publish");
    }
    {
        loop_begin("loop_b4_sum_asymmetry");
        build_data();
        Json *a = node("ikonly");
        add(a, jmap("ik", 7));
        (void)run_loop(a);
        CK(obs.acreate_count[0] == 7,
           "an ik-only animation takes the field read (7), never a child loop");
        CK(alloc_bytes(41) == 7u * 4u, "ik-only capacity is 7 words");
    }
    {
        loop_begin("loop_b4_sum_asymmetry");
        build_data();
        Json *a = node("none");
        (void)run_loop(a);
        CK(obs.acreate_count[0] == 0, "an animation with no keys sums zero");
        CK(alloc_bytes(41) == 0u, "zero capacity requests malloc(0) at line 41");
        CK(obs.create_n == 0, "an empty animation publishes nothing");
    }
    pass("loop_b4_sum_asymmetry");
}

/* 3. the outer loop publishes one animation per pass and advances the cursor */
static void loop_two_animations(void)
{
    loop_begin("loop_two_animations");
    build_data();
    Json *a1 = mini_bones("walkA", "arm", 0.5f, 10.0f);
    Json *a2 = mini_bones("walkB", "leg", 0.75f, -5.0f);
    sib(a1, a2);
    void *r = run_loop(a1);
    CK(r == &g_data, "two animations complete");
    CK(obs.acreate_n == 2 && obs.acreate_count[0] == 1 && obs.acreate_count[1] == 1,
       "B3/B4 run once per animation");
    CK(strcmp(obs.anim[0] != 0 ? ((spAnimation *)obs.anim[0])->name : "", "walkA") == 0 &&
       strcmp(((spAnimation *)obs.anim[1])->name, "walkB") == 0,
       "spAnimation_create receives each animation's Json member key");
    CK(((spSkeletonDataEventShape *)&g_data)->animationsCount == 2,
       "animationsCount advances once per animation");
    CK(((void **)(uintptr_t)word_at(&g_data, 14))[0] == obs.anim[0] &&
       ((void **)(uintptr_t)word_at(&g_data, 14))[1] == obs.anim[1],
       "the array keeps publish order with the old cursor as the index");
    CK(((spAnimationPathShape *)obs.anim[0])->duration == 0.5f &&
       ((spAnimationPathShape *)obs.anim[1])->duration == 0.75f,
       "each animation's duration is its own");
    CK(g_frame.animation == 0 && g_frame.bones != 0 && g_frame.slotsChild == 0 &&
       g_frame.paths == 0 && g_frame.ik == 0,
       "per-animation key slots are re-read, not carried over");
    CK(obs.create_n == 2 && strcmp(obs.creates, "RR") == 0,
       "one rotate timeline per animation, in iteration order");
    pass("loop_two_animations");
}

/* 4. an animation whose eight key lookups all miss */
static void loop_empty_animation(void)
{
    loop_begin("loop_empty_animation");
    build_data();
    Json *a = node("empty");
    void *r = run_loop(a);
    CK(r == &g_data, "empty animation completes");
    CK(obs.acreate_n == 1 && obs.acreate_count[0] == 0,
       "spAnimation_create is still called, with count 0");
    CK(obs.create_n == 0 && ((spAnimation *)obs.anim[0])->timelineCount == 0,
       "no family publishes anything");
    CK(((spAnimationPathShape *)obs.anim[0])->duration == 0.0f,
       "duration stays at the calloc zero");
    CK(g_frame.bones == 0 && g_frame.slotsChild == 0 && g_frame.paths == 0 &&
       g_frame.deform == 0 && g_frame.drawOrder == 0 && g_frame.events == 0,
       "all eight node slots are NULL after the key pass");
    pass("loop_empty_animation");
}

/* 5. only two families present: the rest are skipped, not stubbed */
static void loop_partial_families(void)
{
    loop_begin("loop_partial_families");
    build_data();
    Json *a = node("partial");
    Json *ik = jmap("ik", 1);
    Json *c = jmap("ik1", 1);
    Json *f = jframe();
    add(f, jnum("time", 0.9f));
    add(f, jnum("mix", 0.25f));
    add(c, f);
    add(ik, c);
    Json *events = jmap("events", 1);
    Json *ef = jframe();
    add(ef, jstr("name", "footstep"));
    add(ef, jnum("time", 0.2f));
    add(events, ef);
    add(a, ik);
    add(a, events);
    void *r = run_loop(a);
    CK(r == &g_data, "partial animation completes");
    CK(obs.acreate_count[0] == 2, "B4 counts only the two present families");
    CK(obs.create_n == 2 && strcmp(obs.creates, "KE") == 0,
       "ik runs before events and the absent families contribute nothing");
    CK(((spAnimation *)obs.anim[0])->timelineCount == 2,
       "two timelines are published");
    CK(((spAnimationPathShape *)obs.anim[0])->duration == 0.9f,
       "duration comes from the ik frames, the later event time is smaller");
    pass("loop_partial_families");
}

/* 6. a path child literally named "mix" is silently skipped by B17 */
static void loop_path_mix_skip(void)
{
    loop_begin("loop_path_mix_skip");
    build_data();
    Json *a = node("skip");
    Json *paths = jmap("paths", 3);
    Json *p1 = jmap("p1", 3);
    Json *pos = jmap("position", 1);
    add(pos, one_frame("position", 5.0f, 0.25f));
    add(p1, pos);
    Json *mix = jmap("mix", 1);
    Json *mf = jframe();
    add(mf, jnum("time", 1.125f));
    add(mf, jnum("rotateMix", 0.6f));
    add(mf, jnum("translateMix", 0.7f));
    add(mix, mf);
    add(p1, mix);
    Json *sp = jmap("spacing", 1);
    add(sp, one_frame("spacing", 3.0f, 0.625f));
    add(p1, sp);
    add(paths, p1);
    add(a, paths);
    void *r = run_loop(a);
    CK(r == &g_data, "mix-skip animation completes");
    CK(obs.acreate_count[0] == 3,
       "B4 still counts the skipped node (paths child size 3)");
    CK(obs.create_n == 2 && strcmp(obs.creates, "PQ") == 0,
       "a child named exactly mix creates nothing; position and spacing still publish");
    CK(((spAnimation *)obs.anim[0])->timelineCount == 2,
       "only the two real timelines are published");
    CK(((spAnimationPathShape *)obs.anim[0])->duration == 0.625f,
       "the skipped mix frame time 1.125 does NOT extend the duration");
    pass("loop_path_mix_skip");
}

/* 7. every other path sub-key falls through to B17, and B13 resumes at
 * 0x28e048 so later siblings and later constraints are still processed. */
static void loop_path_handoff_continue(void)
{
    loop_begin("loop_path_handoff_continue");
    build_data();
    Json *a = node("handoff");
    Json *paths = jmap("paths", 4);
    Json *p1 = jmap("p1", 3);
    Json *pos = jmap("position", 1);
    add(pos, one_frame("position", 5.0f, 0.5f));
    add(p1, pos);
    Json *foreign = jmap("translateMix", 1);
    Json *ff = jframe();
    add(ff, jnum("time", 1.125f));
    add(ff, jnum("rotateMix", 0.6f));
    add(ff, jnum("translateMix", 0.7f));
    add(foreign, ff);
    add(p1, foreign);
    Json *sp = jmap("spacing", 1);
    add(sp, one_frame("spacing", 4.0f, 0.625f));
    add(p1, sp);
    add(paths, p1);
    /* a second constraint whose only child is "mix": handoff then done */
    Json *p0 = jmap("p0", 1);
    Json *mix = jmap("mix", 1);
    add(mix, one_frame("rotateMix", 0.1f, 0.5f));
    add(p0, mix);
    add(paths, p0);
    add(a, paths);
    void *r = run_loop(a);
    CK(r == &g_data, "handoff animation completes");
    CK(obs.acreate_count[0] == 4, "B4 counts both constraints' children (3+1)");
    CK(obs.create_n == 3 && strcmp(obs.creates, "PMQ") == 0,
       "position, foreign-named mix, then spacing: the stage resumes after the B17 handoff");
    CK(((spAnimation *)obs.anim[0])->timelineCount == 3,
       "three path timelines are published");
    CK(((spAnimationPathShape *)obs.anim[0])->duration == 1.125f,
       "the mix timeline extends the duration");
    {
        void **tl = (void **)(void *)((spAnimation *)obs.anim[0])->timelines;
        CK(((spPathConstraintTimelineMixShape *)tl[1])->frames[0] == 1.125f &&
           ((spPathConstraintTimelineMixShape *)tl[1])->frames[1] == 0.6f &&
           ((spPathConstraintTimelineMixShape *)tl[1])->frames[2] == 0.7f,
           "B17 setFrame stores time/rotateMix/translateMix with a three-float stride");
        CK(((spPathConstraintTimelineMixShape *)tl[1])->pathConstraintIndex == 1,
           "B17 receives the index cell of the constraint it belongs to");
        CK(((spPathConstraintTimelineShape *)tl[2])->frames[1] == 4.0f,
           "the spacing sibling after the handoff still gets its value");
    }
    pass("loop_path_handoff_continue");
}

/* 8. readCurve is driven for every interpolatable frame of the full tree */
static void loop_curve_both_kinds(void)
{
    loop_begin("loop_curve_both_kinds");
    build_data();
    Json *a = full_animation("curves");
    (void)run_loop(a);
    int stepped = 0, arrays = 0;
    int stepped_i = -1, array_i = -1;
    for (int i = 0; i < obs.curve_n; ++i) {
        if (obs.curve_kind[i] == 1) { ++stepped; stepped_i = i; }
        else if (obs.curve_kind[i] == 2) { ++arrays; array_i = i; }
    }
    CK(obs.curve_n == 2 && stepped == 1 && arrays == 1,
       "both curve forms reach the setters: one stepped string (color) and one four-value array (rotate)");
    {
        void **tl = (void **)(void *)((spAnimation *)obs.anim[0])->timelines;
        CK(stepped_i >= 0 && obs.curve_tl[stepped_i] == tl[1],
           "the stepped curve is applied to the color timeline being built");
        CK(array_i >= 0 && obs.curve_tl[array_i] == tl[2],
           "the array curve is applied to the first rotate timeline");
        CK(obs.curve_frame[array_i] == 0,
           "the frame index passed to readCurve is the timeline-local index");
        CK(obs.curve_args[array_i][0] == bits(0.125f) &&
           obs.curve_args[array_i][1] == bits(0.25f) &&
           obs.curve_args[array_i][2] == bits(0.375f) &&
           obs.curve_args[array_i][3] == bits(0.5f),
           "the four array values reach spCurveTimeline_setCurve in order");
    }
    /* the other 15 interpolatable frames carry no "curve" key: readCurve is a
     * no-op for them, which is why only two setter calls are observed. */
    CK(obs.create_n == 15, "all 15 timelines were built while the curve paths ran");
    pass("loop_curve_both_kinds");
}

/* ------------------------------------------------------------------ */
/* error family: every family's error must dispose animation + data    */
/* ------------------------------------------------------------------ */
static void expect_error(const char *message, const char *why)
{
    CK(report_count == 1, why);
    CK(contains(reported, message), "setError text matches the block literal");
    CK(free_hits(g_anim_arr) == 1, "the shared tail disposes the whole skeleton data");
    CK(free_hits(((spAnimation *)obs.anim[0])->timelines) == 1,
       "spAnimation_dispose releases the animation's timeline array");
}

/* 9. E1: invalid timeline type for a slot */
static void loop_error_invalid_slot_type(void)
{
    loop_begin("loop_error_invalid_slot_type");
    build_data();
    Json *a = node("badtype");
    Json *slots = jmap("slots", 1);
    Json *s = jmap("slotA", 1);
    Json *tl = jmap("bogus", 1);
    add(tl, one_frame("time", 0.5f, 0.5f));
    add(s, tl);
    add(slots, s);
    add(a, slots);
    CK(run_loop(a) == 0, "E1 returns NULL through the shared epilogue");
    expect_error("Invalid timeline type for a slot: bogus",
                 "E1 reports the offending timeline member key");
    CK(obs.disposed == 0, "nothing was published before E1");
    CK(g_frame.animation == a, "the outer cursor did not advance");
    pass("loop_error_invalid_slot_type");
}

/* 10. B5 slot index -1: the 0x28ea10 block recovered in this module */
static void loop_error_slot_not_found(void)
{
    loop_begin("loop_error_slot_not_found");
    build_data();
    Json *a = node("badslot");
    Json *slots = jmap("slots", 1);
    Json *s = jmap("ghostslot", 1);
    Json *tl = jmap("attachment", 1);
    add(tl, one_frame("time", 0.5f, 0.5f));
    add(s, tl);
    add(slots, s);
    add(a, slots);
    CK(run_loop(a) == 0, "slot-not-found returns NULL");
    expect_error("Slot not found: ghostslot",
                 "0x28ea10 reads the failing slot's member key from [sp+0x2c]");
    CK(obs.disposed == 0, "no timeline was published");
    pass("loop_error_slot_not_found");
}

/* 11. E2: bone not found */
static void loop_error_bone_not_found(void)
{
    loop_begin("loop_error_bone_not_found");
    build_data();
    Json *a = node("badbone");
    Json *bones = jmap("bones", 1);
    Json *b = jmap("ghostbone", 1);
    Json *tl = jmap("rotate", 1);
    add(tl, one_frame("angle", 1.0f, 0.5f));
    add(b, tl);
    add(bones, b);
    add(a, bones);
    CK(run_loop(a) == 0, "bone-not-found returns NULL");
    expect_error("Bone not found: ghostbone",
                 "E2 reports the bone node's member key");
    pass("loop_error_bone_not_found");
}

/* 12. E7: path constraint not found */
static void loop_error_path_not_found(void)
{
    loop_begin("loop_error_path_not_found");
    build_data();
    Json *a = node("badpath");
    Json *paths = jmap("paths", 1);
    Json *p = jmap("ghostpath", 1);
    Json *tl = jmap("position", 1);
    add(tl, one_frame("position", 1.0f, 0.5f));
    add(p, tl);
    add(paths, p);
    add(a, paths);
    CK(run_loop(a) == 0, "path-not-found returns NULL");
    expect_error("Path constraint not found: ghostpath",
                 "E7 reports the path node's member key");
    pass("loop_error_path_not_found");
}

/* 13. deform hands off to E4 ("Attachment not found") in draworder's module */
static void loop_error_deform_attachment(void)
{
    loop_begin("loop_error_deform_attachment");
    build_data();
    Json *a = node("baddeform");
    Json *deform = jmap("deform", 1);
    Json *skin = jmap("default", 1);
    Json *slot = jmap("slotA", 1);
    Json *tl = jmap("nope", 1);
    add(tl, one_frame("time", 0.5f, 0.5f));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);
    add(a, deform);
    CK(run_loop(a) == 0, "deform attachment handoff returns NULL");
    expect_error("Attachment not found: nope",
                 "E4 reports the attachment timeline node's key");
    CK(obs.disposed == 0, "the failure happens before any deform timeline is published");
    pass("loop_error_deform_attachment");
}

/* 14. drawOrder hands off to E6 ("Slot not found") in deform's module */
static void loop_error_draworder_slot(void)
{
    loop_begin("loop_error_draworder_slot");
    build_data();
    Json *a = node("baddraw");
    Json *draw = jmap("drawOrder", 1);
    Json *f = jframe();
    Json *offsets = jmap("offsets", 1);
    Json *e = node(0);
    add(e, jstr("slot", "ghostdo"));
    add(e, jint("offset", 0));
    add(offsets, e);
    add(f, offsets);
    add(f, jnum("time", 0.5f));
    add(draw, f);
    add(a, draw);
    CK(run_loop(a) == 0, "drawOrder slot handoff returns NULL");
    expect_error("Slot not found: ghostdo",
                 "E6 re-reads the failing offsets entry's \"slot\" string");
    CK(alloc_count(442) == 1 && alloc_count(445) == 1,
       "B15 allocates lines 442 and 445 before the miss (the original leaks both)");
    pass("loop_error_draworder_slot");
}

/* 15. E5 runs inside the event family and still disposes everything */
static void loop_error_event_not_found(void)
{
    loop_begin("loop_error_event_not_found");
    build_data();
    Json *a = node("badevent");
    Json *events = jmap("events", 1);
    Json *f = jframe();
    add(f, jstr("name", "ghostevent"));
    add(f, jnum("time", 0.5f));
    add(events, f);
    add(a, events);
    CK(run_loop(a) == 0, "event-not-found returns NULL");
    expect_error("Event not found: ghostevent",
                 "E5 reports the frame's \"name\" value");
    pass("loop_error_event_not_found");
}

/* 16. a failure in the second animation disposes the first one too */
static void loop_error_second_animation(void)
{
    loop_begin("loop_error_second_animation");
    build_data();
    Json *a1 = mini_bones("good", "arm", 0.5f, 10.0f);
    Json *a2 = node("bad");
    Json *bones = jmap("bones", 1);
    Json *b = jmap("ghostbone", 1);
    Json *tl = jmap("rotate", 1);
    add(tl, one_frame("angle", 1.0f, 0.5f));
    add(b, tl);
    add(bones, b);
    add(a2, bones);
    sib(a1, a2);
    CK(run_loop(a1) == 0, "the second animation's error aborts the loop");
    CK(report_count == 1 && contains(reported, "Bone not found: ghostbone"),
       "the failing animation is reported once");
    CK(((spSkeletonDataEventShape *)&g_data)->animationsCount == 1,
       "the first animation had already been published");
    CK(obs.disposed == 1,
       "spSkeletonData_dispose walks the published animation and its one timeline");
    CK(free_hits(g_anim_arr) == 1,
       "the whole data record is disposed, not just the failing animation");
    pass("loop_error_second_animation");
}

/* 17. legacy "draworder": Json_getItem is case-insensitive, so the first
 * lookup finds it (the 0x28eb28 retry can never add a node). */
static void loop_legacy_draworder(void)
{
    loop_begin("loop_legacy_draworder");
    build_data();
    Json *a = node("legacy");
    Json *draw = jmap("draworder", 1);          /* lower-case key only */
    Json *f = jframe();
    Json *offsets = jmap("offsets", 1);
    Json *e = node(0);
    add(e, jstr("slot", "slotA"));
    add(e, jint("offset", 0));
    add(offsets, e);
    add(f, offsets);
    add(f, jnum("time", 0.5f));
    add(draw, f);
    add(a, draw);
    void *r = run_loop(a);
    CK(r == &g_data, "legacy draworder animation completes");
    CK(obs.acreate_count[0] == 1, "B4 counts the legacy node as one timeline");
    CK(obs.create_n == 1 && obs.creates[0] == 'O',
       "the drawOrder stage runs for the lower-case key");
    CK(g_frame.drawOrder == draw, "frame->drawOrder holds the legacy node");
    pass("loop_legacy_draworder");
}


void _start(void)
{
    test = "startup";
    init_heap();
    fixture_install_error_reporter();
    g_tl_vtable[0] = 0u;
    g_tl_vtable[1] = (uint32_t)(uintptr_t)tl_dispose_probe;
    loop_full_nine_families();
    loop_b4_sum_asymmetry();
    loop_two_animations();
    loop_empty_animation();
    loop_partial_families();
    loop_path_mix_skip();
    loop_path_handoff_continue();
    loop_curve_both_kinds();
    loop_error_invalid_slot_type();
    loop_error_slot_not_found();
    loop_error_bone_not_found();
    loop_error_path_not_found();
    loop_error_deform_attachment();
    loop_error_draworder_slot();
    loop_error_event_not_found();
    loop_error_second_animation();
    loop_legacy_draworder();
    out("SUMMARY all declared animations loop contracts passed\n");
    quit(0);
}
