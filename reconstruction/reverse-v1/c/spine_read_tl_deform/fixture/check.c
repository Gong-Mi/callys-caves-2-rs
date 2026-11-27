/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes and
 * the deform timeline entry points are SYNTHETIC providers.  qemu executes our
 * linked C, never original libyoyo bytes.  Original not executed; this is not
 * an original-equivalence claim.
 *
 * Subject: the deform timeline family of spSkeletonJson_readSkeletonData
 *   B14   0x28e060..0x28e338  (deform map -> skin -> slot -> attachment-name
 *                              node -> frames; weighted split; line-388
 *                              malloc; create; publish tail)
 *   B14b  0x28e820..0x28e880  (vertices-key-absent branch + the scale != 1
 *                              copy)
 *   E6    0x28e8ac..0x28e8ec  ("Slot not found: "; measured caller: the
 *                              drawOrder offsets loop at 0x28e464)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem / Json_getInt / Json_getFloat / Json_getString
 *                                            json_interface
 *   readCurve                              spine_read_curve
 *   spSkeletonData_findSkin / findSlotIndex skeleton_find
 *   spSkin_getAttachment / spSkin_create / spSkin_addAttachment
 *                                            spine_skin
 *   _spSkeletonJson_setError                spine_json_error
 *   spAnimation_dispose / spSkeletonData_dispose / spTimeline_dispose
 *                                            spine_skeleton_data
 *   Json_dispose / ReportSpineError         spine_json_support
 *   _malloc / _free / _calloc               spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spDeformTimeline_create 0x282e58 — builds the 36-byte record with the
 *     disassembled shape (type 8, +0x0c frameCount, +0x10 frames,
 *     +0x14 vertexFloatCount = create's SECOND argument, +0x18 pointer array).
 *   spDeformTimeline_setFrame 0x282ef8 — stores frames[i] = time and records
 *     (timeline, i, time, vertices, timeline->+0x14).  The real body's
 *     free/malloc/memcpy of the per-frame vertex copy (0x282f1c..0x282f60) is
 *     pinned statically by the checker's word pins, not re-executed here: the
 *     INT_MIN boundary makes +0x14*4 wrap to 2.8 GB, which no fixture heap can
 *     host.  Pointer identity and the copy count are what the test reads.
 *   spCurveTimeline_setStepped/setCurve (0x2817c0/0x2817d8) — recorders.
 *   fixture heap/allocator roster, libc providers, hand-built Json nodes.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_deform.h"
#include "../../spine_read_curve/src/spine_read_curve.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"
#include "../../spine_skin/src/spine_skin.h"
#include "../../spine_alloc/src/spine_alloc.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 16
#define MAX_TL 8
#define SENTINEL 0x5a5a5a5a
#define ATT_SENTINEL ((void *)(uintptr_t)0x5a5a5a5a)

static struct {
    int create_n;
    int create_frames;
    int create_count_arg;
    void *last_timeline;
    int set_n;
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    const void *set_vertices[MAX_FRAMES];
    void *set_tl[MAX_FRAMES];
    int set_count_seen[MAX_FRAMES];
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

/* Custom allocator: records (bytes, line, tag) so the line-388 request and the
 * setError line-90 copy are observable. */
static void *tl_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "deform allocation roster/tag");
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
static const struct alloc *alloc_at_line(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) return &aa[i];
    return 0;
}
static const struct alloc *alloc_last_at_line(uint32_t line)
{
    for (unsigned i = na; i-- > 0; ) if (aa[i].line == line) return &aa[i];
    return 0;
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

static void *tl_reserve_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

/* ------------------------------------------------------------------ */
/* synthetic timeline entry points                                     */
/* ------------------------------------------------------------------ */
void *spDeformTimeline_create(int frameCount, int vertexFloatCount)
{
    int n = frameCount < 1 ? 1 : frameCount;
    spDeformTimelineShape *t = tl_reserve_zero(sizeof(*t));

    if (obs.create_n >= MAX_TL) fail("deform create roster exhausted");
    if (frameCount > MAX_FRAMES) fail("deform frame count above test cap");
    /* 0x282e90 mov r1,#8 -> _spCurveTimeline_init type word */
    t->type = 8u;
    t->vtable = tl_vtable_words;
    t->curves = 0;                     /* readCurve's setCurve recorders only record */
    t->frameCount = frameCount;        /* 0x282eac str r5,[r4,#0xc] */
    t->frames = tl_reserve_zero((uint32_t)n * 4u);   /* 0x282ec4..0x282ecc */
    t->vertexFloatCount = vertexFloatCount;          /* 0x282ed8 str r7,[r4,#0x14] */
    t->vertices = tl_reserve_zero((uint32_t)n * 4u); /* 0x282ed0..0x282edc */
    t->slotIndex = (int32_t)SENTINEL;                /* must be overwritten by B14 */
    t->attachment = ATT_SENTINEL;
    obs.create_n++;
    obs.create_frames = frameCount;
    obs.create_count_arg = vertexFloatCount;
    obs.last_timeline = t;
    return t;
}

void spDeformTimeline_setFrame(void *timeline, int frameIndex, float time,
                               const void *vertices)
{
    spDeformTimelineShape *t = (spDeformTimelineShape *)timeline;
    if (obs.set_n >= MAX_FRAMES) fail("deform setFrame table exhausted");
    if (frameIndex < 0 || frameIndex >= MAX_FRAMES) fail("deform setFrame index");
    /* 0x282f18 str r2,[r3] -> frames[frameIndex] = time */
    t->frames[frameIndex] = time;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(time);
    obs.set_vertices[obs.set_n] = vertices;
    obs.set_tl[obs.set_n] = timeline;
    obs.set_count_seen[obs.set_n] = t->vertexFloatCount;
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

/* spSkeletonData words this family's real lookups read:
 *   +0x18 slotsCount / +0x1c slots  (spSkeletonData_findSlotIndex 0x28b0d4/0x28b0e0)
 *   +0x20 skinsCount / +0x24 skins  (spSkeletonData_findSkin 0x28b12c/0x28b138)
 * spSkeletonData_create is the real calloc(1,84,tag,37). */
static spSkeletonData *make_data(void **slots, int slotCount,
                                 void **skins, int skinCount)
{
    spSkeletonData *d = spSkeletonData_create();
    d->words[6] = (uint32_t)slotCount;
    d->words[7] = (uint32_t)(uintptr_t)slots;
    d->words[8] = (uint32_t)skinCount;
    d->words[9] = (uint32_t)(uintptr_t)skins;
    return d;
}

/* findSlotIndex reads the slot name at [slot+4] (skeleton_find 0x28b0f4). */
static void *slot_record(const char *name)
{
    void **s = tl_reserve_zero(8);
    s[1] = (void *)(uintptr_t)name;
    return s;
}

/* spVertexAttachment head this block reads: +0x14 bones gate, +0x18 float
 * count, +0x1c vertex stream.  `bones` is only tested for NULL. */
static spVertexAttachmentDeformShape *attachment_record(int has_bones,
                                                        int32_t verticesCount,
                                                        const float *vertices)
{
    spVertexAttachmentDeformShape *a = tl_reserve_zero(sizeof(*a));
    a->bones = has_bones ? (void *)(uintptr_t)0x1u : 0;
    a->verticesCount = verticesCount;
    a->vertices = vertices;
    return a;
}

static spAnimationDeformShape *make_animation(void)
{
    spAnimationDeformShape *a = tl_reserve_zero(sizeof(*a));
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
static Json *int_key(const char *key, int32_t value)
{
    Json *n = node(key);
    n->unk_08 = 3;                     /* number */
    n->int_value = value;              /* Json_getInt reads +0x14 */
    return n;
}
static Json *str_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->unk_08 = 4;                     /* string */
    n->string_value = value;
    return n;
}
/* attachment node: its name is the attachment key, +0x0c the declared frame
 * count (Json_getInt is not used for it; B14 loads +0x0c directly at 0x28e160
 * and 0x28e2e0). */
static Json *attachment_node(const char *name, int declared)
{
    Json *n = node(name);
    n->unk_0c = (uint32_t)declared;
    return n;
}
static Json *frame_node(float time, const char *extra_key, int32_t extra)
{
    Json *f = node(0);
    add(f, num_key("time", time));
    if (extra_key) add(f, int_key(extra_key, extra));
    return f;
}

static spDeformTimelineShape *last_timeline(void)
{
    return (spDeformTimelineShape *)obs.last_timeline;
}

/* ================================================================== */
/* 1. no "deform" value at all                                        */
/* ================================================================== */
static void deform_absent(void)
{
    tl_begin("deform_absent");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1, 0, 0);
    spAnimationDeformShape *a = make_animation();

    CK(readSkeletonData_deformTimelines(0, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "B14 with a NULL deform node falls through to the drawOrder block");
    CK(obs.create_n == 0 && a->timelineCount == 0 && alloc_count(388) == 0,
       "B14 with a NULL deform node never allocates nor creates a timeline");
    pass("deform_absent");
}

/* ================================================================== */
/* 2. "deform" present but empty                                      */
/* ================================================================== */
static void deform_without_skins(void)
{
    tl_begin("deform_without_skins");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1, 0, 0);
    spAnimationDeformShape *a = make_animation();
    Json *deform = node("deform");     /* no children */

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "an empty deform object returns to the drawOrder block");
    CK(obs.create_n == 0 && a->timelineCount == 0 && alloc_count(388) == 0,
       "an empty deform object creates and allocates nothing");
    pass("deform_without_skins");
}

/* ================================================================== */
/* 3. a skin node with no slot children                               */
/* ================================================================== */
static void skin_without_slots(void)
{
    tl_begin("skin_without_slots");
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    Json *deform = node("deform");
    Json *skin = node("s0");           /* real findSkin matches; no children */

    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "a skin node without slots advances to the next skin and returns");
    CK(obs.create_n == 0 && alloc_count(388) == 0,
       "a skin node without slots never reaches the line-388 allocation");
    pass("skin_without_slots");
}

/* ================================================================== */
/* 4. a slot node with no attachment children                         */
/* ================================================================== */
static void slot_without_attachments(void)
{
    tl_begin("slot_without_attachments");
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");

    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "a slot node without timelines advances and returns");
    CK(obs.create_n == 0 && alloc_count(388) == 0,
       "a slot node without timelines never allocates the frame buffer");
    pass("slot_without_attachments");
}

/* ================================================================== */
/* 5. getAttachment miss: E4 is OUT OF SCOPE -> handoff code          */
/* ================================================================== */
static void attachment_not_found_handoff(void)
{
    tl_begin("attachment_not_found_handoff");
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("ghost", 1);

    add(tl, frame_node(0.0f, 0, 0));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_HANDOFF_ATTACHMENT,
       "a NULL spSkin_getAttachment leaves B14 at 0x28e110 for E4 (0x28e55c)");
    CK(obs.create_n == 0 && obs.set_n == 0 && a->timelineCount == 0,
       "the E4 handoff creates, frames and publishes nothing");
    CK(alloc_count(388) == 0,
       "the E4 handoff happens before the line-388 allocation");
    pass("attachment_not_found_handoff");
}

/* ================================================================== */
/* 6. weighted: 2*(vertexCount/3), the line-388 malloc and both stores */
/* ================================================================== */
static void weighted_count_and_malloc(void)
{
    tl_begin("weighted_count_and_malloc");
    static const float verts[6] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(1, 6, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(tl, frame_node(0.0f, 0, 0));   /* no vertices key: count-only contract */
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "weighted deform run returns 1");
    /* 0x28e128..0x28e140: 6/3 = 2, x2 = 4 */
    CK(obs.create_count_arg == 4 && obs.create_frames == 1,
       "weighted vertexCount 6 reaches create as 2*(6/3) = 4 floats");
    CK(obs.set_count_seen[0] == 4,
       "the timeline's +0x14 (the setFrame copy count) is the same 4");
    CK(alloc_count(388) == 1 && alloc_at_line(388) && alloc_at_line(388)->bytes == 16,
       "the line-388 malloc asks for floatCount*4 = 16 bytes");
    CK(tag_is(388, "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
       "the line-388 allocation carries the SkeletonJson.c tag");
    CK(obs.set_vertices[0] == alloc_at_line(388)->p,
       "the frame publishes the malloc'd buffer, not the attachment stream");
    CK(free_hits(alloc_at_line(388)->p) == 1,
       "0x28e2c8 _free releases the frame buffer exactly once");
    CK(word(obs.set_vertices[0], 0) == 0u && word(obs.set_vertices[0], 3) == 0u,
       "the weighted absent-key branch memsets the whole buffer at 0x28e840");
    CK(last_timeline()->slotIndex == 0 && last_timeline()->attachment == (void *)att,
       "B14 stores slotIndex at +0x1c and the attachment at +0x20");
    CK(last_timeline()->slotIndex != (int32_t)SENTINEL,
       "the +0x1c store really ran (the create-time sentinel is gone)");
    pass("weighted_count_and_malloc");
}

/* ================================================================== */
/* 7. weighted non-multiples of 3 (truncation toward zero)            */
/* ================================================================== */
static void weighted_nonmultiples(void)
{
    static const struct { int32_t vc; int32_t want; } cases[3] = {
        { 5, 2 }, { 7, 4 }, { 8, 4 }
    };
    tl_begin("weighted_nonmultiples");
    for (unsigned k = 0; k < 3; ++k) {
        void *slots[1] = { slot_record("body") };
        spSkin *s = spSkin_create("s0");
        void *skins[1] = { s };
        spSkeletonData *d = make_data(slots, 1, skins, 1);
        spAnimationDeformShape *a = make_animation();
        float verts[4] = { 0, 0, 0, 0 };
        spVertexAttachmentDeformShape *att = attachment_record(1, cases[k].vc, verts);
        Json *deform = node("deform");
        Json *skin = node("s0");
        Json *slot = node("body");
        Json *tl = attachment_node("mesh", 1);

        spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
        add(tl, frame_node(0.0f, 0, 0));   /* no vertices key -> weighted memset path */
        add(slot, tl);
        add(skin, slot);
        add(deform, skin);
        obs.create_n = obs.set_n = 0;

        CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
           "weighted non-multiple run returns 1");
        CK(obs.create_count_arg == cases[k].want,
           "weighted vertexCount 5/7/8 truncates: 2*(5/3)=2, 2*(7/3)=4, 2*(8/3)=4");
        CK(alloc_last_at_line(388) && alloc_last_at_line(388)->bytes == (uint32_t)cases[k].want * 4u,
           "the line-388 size follows the truncated count (8, 16, 16 bytes)");
    }
    pass("weighted_nonmultiples");
}

/* ================================================================== */
/* 8. non-weighted: vertexCount used verbatim                         */
/* ================================================================== */
static void unweighted_count_verbatim(void)
{
    tl_begin("unweighted_count_verbatim");
    static const float verts[4] = { 10.0f, 20.0f, 30.0f, 40.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 4, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(tl, frame_node(0.0f, 0, 0));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "non-weighted deform run returns 1");
    CK(obs.create_count_arg == 4,
       "non-weighted vertexCount 4 reaches create unchanged (0x28e130 ldreq)");
    CK(alloc_at_line(388) && alloc_at_line(388)->bytes == 16,
       "the non-weighted line-388 request is 4 floats = 16 bytes");
    CK(obs.set_vertices[0] == (const void *)verts,
       "with no vertices key the non-weighted path publishes attachment+0x1c (0x28e828)");
    pass("unweighted_count_verbatim");
}

/* ================================================================== */
/* 9. the 0x55555556 magic: 25-value identity chain                   */
/* ================================================================== */
static int32_t trunc_div3(int32_t v)
{
    /* C99 signed division truncates toward zero; INT_MIN / 3 is in range. */
    return v / 3;
}
/* Bit-exact model of 0x28e134 smull + 0x28e13c sub ... asr#31. */
static int32_t magic_div3(int32_t v)
{
    uint64_t u = (uint64_t)((int64_t)(int32_t)0x55555556 * (int64_t)v);
    int32_t hi = (int32_t)(uint32_t)(u >> 32);
    int32_t corr = v < 0 ? -1 : 0;
    return hi - corr;
}
static void magic_identity_25(void)
{
    static const int32_t cases[25] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 30, 100, 999, 12345,
        -1, -2, -3, -4, -5, -6, -7, -9, 2147483647, -2147483648
    };
    tl_begin("magic_identity_25");
    for (unsigned i = 0; i < 25; ++i) {
        int32_t v = cases[i];
        CK(magic_div3(v) == trunc_div3(v),
           "the smull/asr#31 model itself truncates toward zero");
        CK(readSkeletonData_deformWeightedDivide3(v) == 2 * magic_div3(v),
           "2*(v/3) equals the 0x55555556 smull/asr#31 sequence over 25 values");
    }
    CK(readSkeletonData_deformWeightedDivide3(-2147483648) == -1431655764,
       "INT_MIN: 2*(INT_MIN/3) = -1431655764");
    CK((uint32_t)readSkeletonData_deformWeightedDivide3(-2147483648) * 4u == 0xAAAAAAB0u,
       "INT_MIN: the lsl#2 size wraps to 0xAAAAAAB0");
    pass("magic_identity_25");
}

/* ================================================================== */
/* 10. scaled frame copy: scale != 1 multiplies every element         */
/* ================================================================== */
static void frame_scaled_copy(void)
{
    tl_begin("frame_scaled_copy");
    static const float verts[4] = { 1.5f, -0.75f, 0.0f, 0.0f };
    static const float src[2] = { 1.5f, -0.75f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(1, 6, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);
    Json *frame = frame_node(0.25f, "offset", 1);

    parser_obj.scale = bits(2.0f);
    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(frame, floats("vertices", src, 2, 2));
    add(tl, frame);
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "scaled deform run returns 1");
    CK(obs.set_n == 1 && obs.set_index[0] == 0,
       "the first frame is stored at index 0");
    CK(obs.set_time[0] == 0x3e800000u,
       "setFrame receives the frame \"time\" bits (0.25f)");
    CK(word(obs.set_vertices[0], 0) == 0u,
       "the offset slot before the copied data stays zero");
    CK(word(obs.set_vertices[0], 1) == bits(3.0f) && word(obs.set_vertices[0], 2) == bits(-1.5f),
       "scale 2.0 multiplies both frame values (1.5*2, -0.75*2) at 0x28e864");
    CK(word(obs.set_vertices[0], 3) == 0u,
       "the tail past the copied region is zero-filled (0x28e228..0x28e238)");
    pass("frame_scaled_copy");
}

/* ================================================================== */
/* 11. unscaled frame copy at the same shape                           */
/* ================================================================== */
static void frame_unscaled_copy(void)
{
    tl_begin("frame_unscaled_copy");
    static const float verts[4] = { 1.5f, -0.75f, 0.0f, 0.0f };
    static const float src[2] = { 1.5f, -0.75f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(1, 6, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);
    Json *frame = frame_node(0.25f, "offset", 1);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(frame, floats("vertices", src, 2, 2));
    add(tl, frame);
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "unscaled deform run returns 1");
    CK(word(obs.set_vertices[0], 1) == bits(1.5f) && word(obs.set_vertices[0], 2) == bits(-0.75f),
       "scale 1.0f copies the float bits unchanged (0x28e20c..0x28e21c)");
    pass("frame_unscaled_copy");
}

/* ================================================================== */
/* 12. offset gap (weighted, so the base addend is skipped)           */
/* ================================================================== */
static void frame_offset_gap(void)
{
    tl_begin("frame_offset_gap");
    static const float verts[4] = { 9.0f, 9.0f, 9.0f, 9.0f };
    static const float delta[2] = { 1.0f, 2.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(1, 6, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);
    Json *frame = frame_node(0.0f, "offset", 2);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(frame, floats("vertices", delta, 2, 2));
    add(tl, frame);
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "offset deform run returns 1");
    CK(word(obs.set_vertices[0], 0) == 0u && word(obs.set_vertices[0], 1) == 0u,
       "offset 2 leaves the first two floats zero (0x28e1c8..0x28e1dc)");
    CK(word(obs.set_vertices[0], 2) == bits(1.0f) && word(obs.set_vertices[0], 3) == bits(2.0f),
       "the two frame deltas land at offset 2 (0x28e208 add r3,r4,r3)");
    pass("frame_offset_gap");
}

/* ================================================================== */
/* 12b. non-weighted base addend across the whole floatCount          */
/* ================================================================== */
static void frame_base_add(void)
{
    tl_begin("frame_base_add");
    static const float base[4] = { 10.0f, 20.0f, 30.0f, 40.0f };
    static const float delta[2] = { 1.0f, 2.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 4, base);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);
    Json *frame = frame_node(0.0f, 0, 0);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(frame, floats("vertices", delta, 2, 2));
    add(tl, frame);
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "base-addend deform run returns 1");
    CK(word(obs.set_vertices[0], 0) == bits(11.0f) && word(obs.set_vertices[0], 1) == bits(22.0f),
       "the two deltas are added to base[0..1] (0x28e258..0x28e270)");
    CK(word(obs.set_vertices[0], 2) == bits(30.0f) && word(obs.set_vertices[0], 3) == bits(40.0f),
       "the zero-filled tail is still added to the base stream, not left zero");
    pass("frame_base_add");
}

/* ================================================================== */
/* 13. weighted frame with no vertices key: whole buffer zeroed       */
/* ================================================================== */
static void frame_no_vertices_weighted(void)
{
    tl_begin("frame_no_vertices_weighted");
    static const float verts[4] = { 9.0f, 9.0f, 9.0f, 9.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(1, 6, verts);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(tl, frame_node(0.0f, 0, 0));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "weighted no-vertices run returns 1");
    CK(obs.set_vertices[0] == alloc_at_line(388)->p,
       "the weighted absent-key branch still publishes the buffer");
    CK(word(obs.set_vertices[0], 0) == 0u && word(obs.set_vertices[0], 3) == 0u,
       "the weighted absent-key branch memsets the whole buffer at 0x28e840");
    pass("frame_no_vertices_weighted");
}

/* ================================================================== */
/* 14. non-weighted frame with no vertices key: base stream published */
/* ================================================================== */
static void frame_no_vertices_unweighted(void)
{
    tl_begin("frame_no_vertices_unweighted");
    static const float base[4] = { 7.0f, 8.0f, 9.0f, 10.0f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 4, base);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 1);

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(tl, frame_node(0.0f, 0, 0));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "non-weighted no-vertices run returns 1");
    CK(obs.set_vertices[0] == (const void *)base,
       "the non-weighted absent-key branch publishes attachment+0x1c unchanged");
    pass("frame_no_vertices_unweighted");
}

/* ================================================================== */
/* 15. frame list, frame index and readCurve wiring                   */
/* ================================================================== */
static void frame_time_and_curve(void)
{
    tl_begin("frame_time_and_curve");
    static const float base[4] = { 0, 0, 0, 0 };
    static const float curve_values[4] = { 0.1f, 0.2f, 0.3f, 0.4f };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 4, base);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 2);
    Json *f0 = frame_node(0.0f, 0, 0);
    Json *f1 = frame_node(1.0f, 0, 0);
    Json *curve_arr;

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(f0, str_key("curve", "stepped"));
    curve_arr = floats("curve", curve_values, 4, 4);
    curve_arr->unk_08 = 5;             /* array */
    add(f1, curve_arr);
    add(tl, f0);
    add(tl, f1);
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "two-frame deform run returns 1");
    CK(obs.set_n == 2 && obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "the frame index starts at 0 and increments per frame child");
    CK(obs.set_time[0] == 0u && obs.set_time[1] == 0x3f800000u,
       "setFrame receives each frame's \"time\" bits");
    CK(obs.curve_n == 2 && obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \"stepped\" curve string reaches spCurveTimeline_setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches spCurveTimeline_setCurve at frame 1");
    CK(obs.curve_tl[0] == obs.last_timeline && obs.curve_tl[1] == obs.last_timeline,
       "readCurve receives the same timeline pointer setFrame received (0x28e2a8)");
    pass("frame_time_and_curve");
}

/* ================================================================== */
/* 16. publish tail: cursor, one-float stride, duration max           */
/* ================================================================== */
static void publish_tail_duration(void)
{
    tl_begin("publish_tail_duration");
    static const float base[2] = { 0, 0 };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 2, base);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *t0 = attachment_node("m0", 2);
    Json *t1 = attachment_node("m1", 2);
    Json *f0 = frame_node(0.25f, 0, 0);
    Json *f1 = frame_node(0.5f, 0, 0);
    Json *f2 = frame_node(1.0f, 0, 0);
    Json *f3 = frame_node(1.7f, 0, 0);

    spSkin_addAttachment(s, 0, "m0", (spAttachment *)att);
    spSkin_addAttachment(s, 0, "m1", (spAttachment *)att);
    add(t0, f0); add(t0, f1);
    add(t1, f2); add(t1, f3);
    add(slot, t0); add(slot, t1);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "two-timeline deform run returns 1");
    CK(obs.create_n == 2 && obs.create_frames == 2,
       "each attachment node creates its own timeline with its own declared count");
    CK(a->timelineCount == 2 && a->timelines[0] != a->timelines[1],
       "both timelines are published at successive animation cursor slots");
    CK(bits(a->duration) == 0x3fd9999au,
       "duration reads frames[declared-1] with a ONE-float stride (1.7 over 0.5)");
    pass("publish_tail_duration");
}

/* ================================================================== */
/* 17. declared count > child count: duration reads the unwritten slot */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    tl_begin("declared_vs_child_count");
    static const float base[2] = { 0, 0 };
    void *slots[1] = { slot_record("body") };
    spSkin *s = spSkin_create("s0");
    void *skins[1] = { s };
    spSkeletonData *d = make_data(slots, 1, skins, 1);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *att = attachment_record(0, 2, base);
    Json *deform = node("deform");
    Json *skin = node("s0");
    Json *slot = node("body");
    Json *tl = attachment_node("mesh", 3);   /* declares 3, carries 1 */

    spSkin_addAttachment(s, 0, "mesh", (spAttachment *)att);
    add(tl, frame_node(0.4f, 0, 0));
    add(slot, tl);
    add(skin, slot);
    add(deform, skin);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "declared-three one-frame run returns 1");
    CK(obs.set_n == 1 && obs.create_frames == 3,
       "the loop follows the child list while create receives the declared count 3");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[(3-1)] (=0, never written), not frames[0]");
    pass("declared_vs_child_count");
}

/* ================================================================== */
/* 18. two skins x slots: real findSkin/getAttachment routing         */
/* ================================================================== */
static void two_skins_slot_indices(void)
{
    tl_begin("two_skins_slot_indices");
    static const float base[2] = { 0, 0 };
    void *slots[2] = { slot_record("a"), slot_record("b") };
    spSkin *s0 = spSkin_create("s0");
    spSkin *s1 = spSkin_create("s1");
    void *skins[2] = { s0, s1 };
    spSkeletonData *d = make_data(slots, 2, skins, 2);
    spAnimationDeformShape *a = make_animation();
    spVertexAttachmentDeformShape *m0 = attachment_record(0, 2, base);
    spVertexAttachmentDeformShape *m1 = attachment_record(0, 2, base);
    spVertexAttachmentDeformShape *m2 = attachment_record(0, 2, base);
    spVertexAttachmentDeformShape *m3 = attachment_record(0, 2, base);
    Json *deform = node("deform");
    Json *skin0 = node("s0");
    Json *skin1 = node("s1");
    Json *slotA = node("a");
    Json *slotB = node("b");
    Json *slotA2 = node("a");          /* same slot name under the second skin */
    Json *ta = attachment_node("m0", 1);
    Json *tb = attachment_node("m1", 1);
    Json *tc = attachment_node("m2", 1);
    Json *td = attachment_node("m3", 1);

    /* s0/a -> m0,m1 (both registered at slot 0); s0/b -> m2 (slot 1);
     * s1/a -> m3 (registered on the second skin at slot 0). */
    spSkin_addAttachment(s0, 0, "m0", (spAttachment *)m0);
    spSkin_addAttachment(s0, 0, "m1", (spAttachment *)m1);
    spSkin_addAttachment(s0, 1, "m2", (spAttachment *)m2);
    spSkin_addAttachment(s1, 0, "m3", (spAttachment *)m3);
    add(ta, frame_node(0.0f, 0, 0));
    add(tb, frame_node(0.0f, 0, 0));
    add(tc, frame_node(0.0f, 0, 0));
    add(td, frame_node(0.0f, 0, 0));
    add(slotA, ta);
    add(slotA, tb);
    add(slotB, tc);
    add(slotA2, td);
    add(skin0, slotA);
    add(skin0, slotB);
    add(skin1, slotA2);
    add(deform, skin0);
    add(deform, skin1);

    CK(readSkeletonData_deformTimelines(deform, d, a, &parser_obj) == DEFORM_TL_REACHED_DRAWORDER,
       "two-skin run returns 1");
    CK(a->timelineCount == 4,
       "all four resolvable attachment nodes publish a timeline");
    CK(((spDeformTimelineShape *)a->timelines[0])->slotIndex == 0
       && ((spDeformTimelineShape *)a->timelines[0])->attachment == (void *)m0,
       "s0 slot a's first timeline carries index 0 and m0");
    CK(((spDeformTimelineShape *)a->timelines[1])->slotIndex == 0
       && ((spDeformTimelineShape *)a->timelines[1])->attachment == (void *)m1,
       "s0 slot a's second timeline carries index 0 and m1");
    CK(((spDeformTimelineShape *)a->timelines[2])->slotIndex == 1
       && ((spDeformTimelineShape *)a->timelines[2])->attachment == (void *)m2,
       "s0 slot b resolves its name to slot index 1 and m2");
    CK(((spDeformTimelineShape *)a->timelines[3])->slotIndex == 0
       && ((spDeformTimelineShape *)a->timelines[3])->attachment == (void *)m3,
       "s1's slot a resolves against the SECOND skin object, not the first");
    pass("two_skins_slot_indices");
}

/* ================================================================== */
/* 19. E6: "Slot not found: " with a NULL setError json argument      */
/* ================================================================== */
static void e6_slot_not_found(void)
{
    tl_begin("e6_slot_not_found");
    spSkeletonData *d = spSkeletonData_create();   /* all-zero record: dispose is cheap */
    spAnimationDeformShape *a = make_animation();
    Json *offsets = node(0);
    void *tl;

    add(offsets, str_key("slot", "ghost"));
    add(offsets, int_key("offset", 1));
    tl = spDeformTimeline_create(1, 2);            /* so dispose walks a timeline */
    a->timelines[0] = tl;
    a->timelineCount = 1;
    obs.create_n = 0;

    CK(readSkeletonData_drawOrderSlotNotFound(offsets, d, a, &parser_obj) == 0,
       "E6 returns 0 so the parent loader returns NULL");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E6 reports through the real console vcall");
    CK(strcmp(reported, "Slot not found: ghost") == 0,
       "E6 message is the exact original literal plus Json_getString(\"slot\")");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error, "Slot not found: ghost") == 0,
       "E6 stores the formatted message in parser->error");
    CK(alloc_count(90) == 1
       && tag_is(90, "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
       "E6 error copy is a line-90 SkeletonJson.c allocation");
    CK(obs.vdispose_n == 1,
       "E6 disposes the animation first: the published timeline is walked");
    CK(free_hits(a) == 1,
       "E6 animation dispose frees the animation record");
    CK(free_hits(d) == 1,
       "E6 disposes the skeleton data exactly once through the shared 0x28da44 tail");
    CK(free_hits(offsets) == 0,
       "E6 passes NULL (not the offsets node, not the root) as the setError json argument");
    pass("e6_slot_not_found");
}

/* ================================================================== */
/* 20. E6 still runs when the offsets node has no "slot" key          */
/* ================================================================== */
static void e6_missing_slot_key(void)
{
    tl_begin("e6_missing_slot_key");
    spSkeletonData *d = spSkeletonData_create();
    spAnimationDeformShape *a = make_animation();
    Json *offsets = node(0);

    add(offsets, int_key("offset", 3));

    CK(readSkeletonData_drawOrderSlotNotFound(offsets, d, a, &parser_obj) == 0,
       "E6 with an absent slot key still returns 0");
    CK(strcmp(reported, "Slot not found: ") == 0,
       "Json_getString default NULL leaves the message with an empty tail");
    CK(obs.vdispose_n == 0 && free_hits(a) == 1,
       "an animation with no timelines is disposed without a vtable walk");
    CK(free_hits(offsets) == 0,
       "the NULL json argument never disposes the offsets node");
    pass("e6_missing_slot_key");
}

void _start(void)
{
    test = "startup"; init_heap(); fixture_install_error_reporter();
    deform_absent();
    deform_without_skins();
    skin_without_slots();
    slot_without_attachments();
    attachment_not_found_handoff();
    weighted_count_and_malloc();
    weighted_nonmultiples();
    unweighted_count_verbatim();
    magic_identity_25();
    frame_scaled_copy();
    frame_unscaled_copy();
    frame_offset_gap();
    frame_base_add();
    frame_no_vertices_weighted();
    frame_no_vertices_unweighted();
    frame_time_and_curve();
    publish_tail_duration();
    declared_vs_child_count();
    two_skins_slot_indices();
    e6_slot_not_found();
    e6_missing_slot_key();
    out("SUMMARY all declared deform timeline family contracts passed\n");
    quit(0);
}
