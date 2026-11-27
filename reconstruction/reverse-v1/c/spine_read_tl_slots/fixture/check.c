/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the reporter and the four timeline entry points are SYNTHETIC providers.
 * qemu executes our linked C, never original libyoyo bytes.  Original not
 * executed; this is not an original-equivalence claim.
 *
 * Subject: the slots timeline family of spSkeletonJson_readSkeletonData
 *   B5  0x28d4ec..0x28d640  (dispatch + attachment frames + attachment tail)
 *   B8  0x28d8dc..0x28d9d4  (color frames, hex string -> real toColor x4)
 *   B8b 0x28d9d4..0x28da18  (color publish/duration tail, 5-float stride)
 *   E1  0x28da18..0x28da54  (Invalid timeline type for a slot)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem/getString/getFloat   json_interface
 *   spSkeletonData_findSlotIndex      skeleton_find
 *   toColor                           spine_color
 *   readCurve                         spine_read_curve
 *   _spSkeletonJson_setError          spine_json_error
 *   Json_dispose / ReportSpineError   spine_json_support
 *   spAnimation_dispose / spSkeletonData_dispose / spSlotData_dispose
 *   _malloc / _free                   spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered):
 *   spAttachmentTimeline_create/setFrame 0x282b94 / 0x282c1c
 *   spColorTimeline_create/setFrame      0x282b3c / 0x282b54
 *     The setFrame doubles model the disassembled original stores exactly
 *     (attachment: frames[i]=time, names[i]=name; color: frames[i*5+{0..4}] =
 *     time,r,g,b,a) so the B5/B8b tails read the same shape the real setters
 *     produce, and additionally record every argument word.
 *   spCurveTimeline_setStepped/setCurve (0x2817c0 / 0x2817d8) — argument
 *     recorders; bodies are readCurve's dependency, not this family's.
 *   fixture heap/allocator roster, libc string providers, hand-built Json
 *   nodes (node types set exactly as the real parser 0x28677c writes them).
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_slots.h"
#include "../../spine_read_curve/src/spine_read_curve.h"
#include "../../spine_json_error/src/spine_json_error.h"
#include "../../skeleton_find/src/skeleton_find.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 8
#define MAX_TIMELINES 8

static struct {
    int acreate, ccreate;            /* create() call counts                */
    int acreate_frames, ccreate_frames;
    int aset_n, cset_n;
    int aset_index[MAX_FRAMES];
    uint32_t aset_time[MAX_FRAMES];
    const char *aset_name[MAX_FRAMES];
    int cset_index[MAX_FRAMES];
    uint32_t cset_time[MAX_FRAMES];
    uint32_t cset_rgba[MAX_FRAMES][4];
    int curve_n, curve_kind[MAX_FRAMES], curve_frame[MAX_FRAMES];
    void *curve_tl[MAX_FRAMES];
    uint32_t curve_args[MAX_FRAMES][4];
    int vdispose_n;
    void *last_timeline;
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

/* Custom allocator: records (bytes, line, tag) so the line-90 error copy and
 * the SkelletonData.c create are observable. */
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

void *spAttachmentTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spAttachmentTimelineShape *t = tl_reserve_zero(sizeof(*t));
    t->type = 0x11u;
    t->vtable = tl_vtable_words;
    t->frameCount = frameCount;
    t->frames = tl_reserve_zero(n * 4u);
    t->attachmentNames = tl_reserve_zero(n * 4u);
    ++obs.acreate;
    obs.acreate_frames = frameCount;
    obs.last_timeline = t;
    return t;
}

void spAttachmentTimeline_setFrame(void *timeline, int frameIndex,
                                   float time, const char *attachmentName)
{
    spAttachmentTimelineShape *t = (spAttachmentTimelineShape *)timeline;
    if (obs.aset_n >= MAX_FRAMES) fail("attachment setFrame table exhausted");
    /* 0x282c38/0x282c3c: frames[frameIndex] = time ; names[frameIndex] = name
     * (the real body frees + strdups the name; the double borrows it so the
     * caller's pointer identity is observable). */
    t->frames[frameIndex] = time;
    t->attachmentNames[frameIndex] = (char *)attachmentName;
    obs.aset_index[obs.aset_n] = frameIndex;
    obs.aset_time[obs.aset_n] = bits(time);
    obs.aset_name[obs.aset_n] = attachmentName;
    ++obs.aset_n;
}

void *spColorTimeline_create(int frameCount)
{
    uint32_t n = (uint32_t)(frameCount < 1 ? 1 : frameCount);
    spColorTimelineShape *t = tl_reserve_zero(sizeof(*t));
    t->type = 0x22u;
    t->vtable = tl_vtable_words;
    /* color +0x08 is the curves array in the real record; this fixture does
     * not model curves (readCurve's doubles only record), so it stays NULL. */
    t->curves = 0;
    t->frameFloatCount = frameCount * 5;
    t->frames = tl_reserve_zero(n * 5u * 4u);
    ++obs.ccreate;
    obs.ccreate_frames = frameCount;
    obs.last_timeline = t;
    return t;
}

void spColorTimeline_setFrame(void *timeline, int frameIndex, float time,
                              float r, float g, float b, float a)
{
    spColorTimelineShape *t = (spColorTimelineShape *)timeline;
    uint32_t base = (uint32_t)frameIndex * 5u;
    if (obs.cset_n >= MAX_FRAMES) fail("color setFrame table exhausted");
    /* 0x282b78/0x282b7c/0x282b80/0x282b84/0x282b88 store order:
     * frames[base+0]=time, [+1]=r, [+2]=g, [+3]=b, [+4]=a */
    t->frames[base + 0u] = time;
    t->frames[base + 1u] = r;
    t->frames[base + 2u] = g;
    t->frames[base + 3u] = b;
    t->frames[base + 4u] = a;
    obs.cset_index[obs.cset_n] = frameIndex;
    obs.cset_time[obs.cset_n] = bits(time);
    obs.cset_rgba[obs.cset_n][0] = bits(r);
    obs.cset_rgba[obs.cset_n][1] = bits(g);
    obs.cset_rgba[obs.cset_n][2] = bits(b);
    obs.cset_rgba[obs.cset_n][3] = bits(a);
    ++obs.cset_n;
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
    report_count = 0;
    reported[0] = report_format[0] = 0;
    tl_vtable_words[0] = 0u;
    tl_vtable_words[1] = (uint32_t)(uintptr_t)tl_dispose_probe;
}

static void *slot_record(const char *name)
{
    void **s = tl_reserve_zero(8);
    s[1] = (void *)(uintptr_t)name;    /* findSlotIndex reads [slot+4] */
    return s;
}

static spSkeletonData *make_data(void **slots, int count)
{
    spSkeletonData *d = spSkeletonData_create();   /* real calloc(1,84,tag,37) */
    d->words[6] = (uint32_t)count;                 /* +0x18 slotsCount */
    d->words[7] = (uint32_t)(uintptr_t)slots;      /* +0x1c slots array */
    return d;
}

static spAnimationShape *make_animation(void)
{
    spAnimationShape *a = tl_reserve_zero(sizeof(*a));
    a->timelines = tl_reserve_zero(4u * MAX_TIMELINES);
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
static Json *false_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->unk_08 = 2;                     /* false: the kind B5 tests for */
    n->string_value = value;
    return n;
}
static Json *timeline_node(const char *type, int declared)
{
    Json *n = node(type);
    n->unk_0c = (uint32_t)declared;
    return n;
}
static Json *slot_node(const char *name)
{
    return node(name);                 /* name is the JSON member key (+0x1c) */
}

/* ================================================================== */
/* 1. a slot with no timeline children                                  */
/* ================================================================== */
static void dispatch_no_timelines(void)
{
    tl_begin("dispatch_no_timelines");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slots_json = node("slots");
    Json *slot = slot_node("body");
    add(slots_json, slot);             /* slot->next stays NULL: one slot */

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 slot without timelines returns 1 (falls through to the bones block)");
    CK(obs.acreate == 0 && obs.ccreate == 0,
       "B5 no timeline children creates no timeline");
    CK(a->timelineCount == 0, "B5 no timeline children publishes nothing");
    CK(na == 1, "B5 no timeline children allocates nothing beyond the data record");
    CK(report_count == 0, "B5 no timeline children reports nothing");
    pass("dispatch_no_timelines");
}

/* ================================================================== */
/* 2. slot lookup miss                                                  */
/* ================================================================== */
static void slot_not_found(void)
{
    tl_begin("slot_not_found");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("missing");
    Json *tl = timeline_node("attachment", 1);
    add(tl, str_key("name", "arm"));
    add(tl, num_key("time", 0.0f));
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 0,
       "B5 unknown slot name reports the -1 branch (0x28ea10, out of block)");
    CK(obs.acreate == 0 && obs.ccreate == 0,
       "B5 unknown slot creates no timeline");
    CK(a->timelineCount == 0, "B5 unknown slot publishes nothing");
    CK(report_count == 0, "B5 unknown slot does not report here (error block is outside this module)");
    pass("slot_not_found");
}

/* ================================================================== */
/* 3. attachment frames: name/time -> setFrame arguments                 */
/* ================================================================== */
static void attachment_frames(void)
{
    tl_begin("attachment_frames");
    void *slots[2] = { slot_record("other"), slot_record("body") };
    spSkeletonData *d = make_data(slots, 2);   /* "body" resolves to index 1 */
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("attachment", 2);
    Json *f0 = node(0), *f1 = node(0);
    Json *n0 = str_key("name", "arm"), *n1 = str_key("name", "leg");
    add(f0, n0); add(f0, num_key("time", 0.0f));
    add(f1, n1); add(f1, num_key("time", 0.5f));
    add(tl, f0); add(tl, f1);
    add(slot, tl);
    Json *tree = node(0);
    add(tree, slot);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 attachment slot completes");
    CK(obs.acreate == 1 && obs.acreate_frames == 2,
       "attachment create receives the declared frame count");
    CK(obs.aset_n == 2, "one setFrame per frame child");
    CK(obs.aset_index[0] == 0 && obs.aset_index[1] == 1,
       "attachment frame index starts at 0 and increments per frame");
    CK(obs.aset_time[0] == 0u && obs.aset_time[1] == 0x3f000000u,
       "attachment setFrame receives the frame time bits");
    CK(obs.aset_name[0] == n0->string_value && obs.aset_name[1] == n1->string_value,
       "attachment name comes from getItem(\"name\")->string_value");
    CK(strcmp(obs.aset_name[0], "arm") == 0 && strcmp(obs.aset_name[1], "leg") == 0,
       "attachment name text is the Json string value");

    spAttachmentTimelineShape *t = (spAttachmentTimelineShape *)obs.last_timeline;
    CK(t->slotIndex == 1, "attachment timeline stores the slot index at +0x10");
    CK(t->frames[0] == 0.0f && t->frames[1] == 0.5f,
       "attachment frames array holds one time float per frame");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "B5 tail publishes the timeline at the animation cursor");
    CK(bits(a->duration) == 0x3f000000u,
       "B5 tail extends the animation duration to the last frame time");
    pass("attachment_frames");
}

/* ================================================================== */
/* 4. the +0x08 == 2 discriminator on the name node                     */
/* ================================================================== */
static void attachment_name_kind(void)
{
    tl_begin("attachment_name_kind");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("attachment", 2);
    Json *f0 = node(0), *f1 = node(0);
    Json *n0 = false_key("name", "ignored");   /* type word 2 */
    Json *n1 = num_key("name", 1.0f);          /* type word 3, string_value set below */
    n1->string_value = "kept";
    add(f0, n0); add(f0, num_key("time", 0.0f));
    add(f1, n1); add(f1, num_key("time", 1.0f));
    add(tl, f0); add(tl, f1);
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 attachment slot with a false name node completes");
    CK(obs.aset_n == 2, "both frames reach setFrame");
    CK(obs.aset_name[0] == 0,
       "a name node whose +0x08 word is 2 suppresses the attachment name");
    CK(obs.aset_name[1] != 0 && strcmp(obs.aset_name[1], "kept") == 0,
       "every other node kind forwards string_value verbatim");
    pass("attachment_name_kind");
}

/* ================================================================== */
/* 5. color frames through the real toColor (hex string channel)        */
/* ================================================================== */
static void color_frames_hex(void)
{
    tl_begin("color_frames_hex");
    void *slots[2] = { slot_record("other"), slot_record("body") };
    spSkeletonData *d = make_data(slots, 2);   /* "body" resolves to index 1 */
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("color", 2);
    Json *f0 = node(0), *f1 = node(0);
    add(f0, str_key("color", "ff800000")); add(f0, num_key("time", 0.0f));
    add(f1, str_key("color", "00ff0080")); add(f1, num_key("time", 1.5f));
    add(tl, f0); add(tl, f1);
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 color slot completes");
    CK(obs.ccreate == 1 && obs.ccreate_frames == 2,
       "color create receives the declared frame count");
    CK(obs.cset_n == 2, "one color setFrame per frame child");
    CK(obs.cset_index[0] == 0 && obs.cset_index[1] == 1,
       "color frame index starts at 0 and increments per frame");
    CK(obs.cset_rgba[0][0] == 0x3f800000u && obs.cset_rgba[0][1] == 0x3f008081u
       && obs.cset_rgba[0][2] == 0x00000000u && obs.cset_rgba[0][3] == 0x00000000u,
       "color frame 0 hex ff800000 -> r=1, g=0x80/255, b=0, a=0 through real toColor");
    CK(obs.cset_rgba[1][0] == 0x00000000u && obs.cset_rgba[1][1] == 0x3f800000u
       && obs.cset_rgba[1][2] == 0x00000000u && obs.cset_rgba[1][3] == 0x3f008081u,
       "color frame 1 hex 00ff0080 -> r=0, g=1, b=0, a=0x80/255");
    CK(obs.cset_time[0] == 0u && obs.cset_time[1] == 0x3fc00000u,
       "color setFrame receives the frame time bits");

    spColorTimelineShape *t = (spColorTimelineShape *)obs.last_timeline;
    CK(t->slotIndex == 1, "color timeline stores the slot index at +0x14");
    CK(t->frames[0] == 0.0f && t->frames[1] == 1.0f && t->frames[5] == 1.5f,
       "color frames array is 5 floats per frame (time,r,g,b,a)");
    CK(a->timelineCount == 1 && a->timelines[0] == (void *)t,
       "B8b tail publishes the color timeline");
    CK(bits(a->duration) == 0x3fc00000u,
       "B8b tail reads frames[(count-1)*5] for the last frame time");
    pass("color_frames_hex");
}

/* ================================================================== */
/* 6. malformed / short hex strings reach setFrame unvalidated          */
/* ================================================================== */
static void color_hex_malformed(void)
{
    tl_begin("color_hex_malformed");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("color", 3);
    Json *f0 = node(0), *f1 = node(0), *f2 = node(0);
    add(f0, str_key("color", "123"));        add(f0, num_key("time", 0.0f));
    add(f1, str_key("color", "zzzzzzzz"));   add(f1, num_key("time", 1.0f));
    add(f2, str_key("color", "-1000000"));   add(f2, num_key("time", 2.0f));
    add(tl, f0); add(tl, f1); add(tl, f2);
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 color slot with malformed hex completes");
    CK(obs.cset_n == 3, "every frame reaches setFrame even with bad hex");
    for (int k = 0; k < 4; ++k) {
        CK(obs.cset_rgba[0][k] == 0xbf800000u,
           "too-short hex gives -1.0 from toColor in all four components");
        CK(obs.cset_rgba[1][k] == 0xbf800000u,
           "non-hex hex gives -1.0 from toColor in all four components");
    }
    CK(obs.cset_rgba[2][0] == 0xbb808081u,
       "two-char \"-1\" converts through signed VCVT to -1/255");
    CK(obs.cset_rgba[2][1] == 0x00000000u && obs.cset_rgba[2][2] == 0x00000000u,
       "remaining components of \"-1000000\" are zero");
    pass("color_hex_malformed");
}

/* ================================================================== */
/* 7. readCurve wiring through the real implementation                  */
/* ================================================================== */
static void read_curve_both_paths(void)
{
    tl_begin("read_curve_both_paths");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("color", 2);
    Json *f0 = node(0), *f1 = node(0);
    const float curve_values[4] = { 0.1f, 0.2f, 0.3f, 0.4f };
    Json *curve_arr;
    add(f0, str_key("color", "ff0000ff")); add(f0, num_key("time", 0.0f));
    add(f0, str_key("curve", "stepped"));
    add(f1, str_key("color", "00ff00ff")); add(f1, num_key("time", 1.0f));
    curve_arr = floats("curve", curve_values, 4, 4);
    curve_arr->unk_08 = 5;                 /* array */
    add(f1, curve_arr);
    add(tl, f0); add(tl, f1);
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 color slot with curves completes");
    CK(obs.cset_n == 2 && obs.curve_n == 2,
       "readCurve runs once per frame after setFrame");
    CK(obs.curve_kind[0] == 1 && obs.curve_frame[0] == 0,
       "a \"stepped\" curve string reaches spCurveTimeline_setStepped at frame 0");
    CK(obs.curve_kind[1] == 2 && obs.curve_frame[1] == 1,
       "a curve array reaches spCurveTimeline_setCurve at frame 1");
    CK(obs.curve_tl[0] == obs.last_timeline && obs.curve_tl[1] == obs.last_timeline,
       "readCurve receives the timeline pointer that setFrame received");
    CK(obs.curve_args[1][0] == 0x3dcccccdu, "curve cx1 bit-exact");
    CK(obs.curve_args[1][1] == 0x3e4ccccdu, "curve cy1 bit-exact");
    CK(obs.curve_args[1][2] == 0x3e99999au, "curve cx2 bit-exact");
    CK(obs.curve_args[1][3] == 0x3ecccccd, "curve cy2 bit-exact");
    pass("read_curve_both_paths");
}

/* ================================================================== */
/* 8. duration / cursor across two timelines in one slot                */
/* ================================================================== */
static void duration_and_cursor(void)
{
    tl_begin("duration_and_cursor");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *att = timeline_node("attachment", 2);
    Json *f0 = node(0), *f1 = node(0);
    Json *col = timeline_node("color", 1);
    Json *g0 = node(0);
    add(f0, str_key("name", "a")); add(f0, num_key("time", 0.0f));
    add(f1, str_key("name", "b")); add(f1, num_key("time", 0.9f));
    add(att, f0); add(att, f1);
    add(g0, str_key("color", "ffffffff")); add(g0, num_key("time", 0.25f));
    add(col, g0);
    add(slot, att); add(slot, col);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 mixed slot completes");
    CK(obs.acreate == 1 && obs.ccreate == 1, "both timeline kinds are created");
    CK(obs.aset_index[0] == 0 && obs.aset_index[1] == 1
       && obs.cset_index[0] == 0,
       "the frame index restarts at 0 for every timeline");
    CK(a->timelineCount == 2 && a->timelines[0] != a->timelines[1],
       "both timelines are published at successive cursor slots");
    CK(bits(a->duration) == 0x3f666666u,
       "duration keeps the larger last frame time (0.9 over 0.25)");
    pass("duration_and_cursor");
}

/* ================================================================== */
/* 9. E1: invalid timeline type for a slot                             */
/* ================================================================== */
static void invalid_type_e1(void)
{
    tl_begin("invalid_type_e1");
    void *slot0 = slot_record("body");
    void *slots[1] = { slot0 };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    void **anim_table = a->timelines;
    Json *slot = slot_node("body");
    Json *col = timeline_node("color", 1);
    Json *g0 = node(0);
    Json *bad = timeline_node("rotate", 1);
    add(g0, str_key("color", "ffffffff")); add(g0, num_key("time", 0.0f));
    add(col, g0);
    add(slot, col);
    add(slot, bad);
    Json *tree = node(0);
    add(tree, slot);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 0,
       "E1 returns 0 so the parent loader returns NULL");
    CK(obs.cset_n == 1 && a->timelines[0] == obs.last_timeline,
       "the valid color timeline was processed before the bad type");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E1 reports through the real console vcall");
    CK(strcmp(reported, "Invalid timeline type for a slot: rotate") == 0,
       "E1 message is the exact original literal plus the timeline key");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error,
                 "Invalid timeline type for a slot: rotate") == 0,
       "E1 stores the formatted message in parser->error");
    CK(alloc_count(90) == 1 && tag_is(90, "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"),
       "E1 error copy is a line-90 SkeletonJson.c allocation");
    CK(obs.vdispose_n == 1,
       "E1 disposes the animation first: published timelines walked via spTimeline_dispose");
    CK(free_hits(a) == 1 && free_hits(anim_table) == 1,
       "E1 animation dispose frees the timeline table and the record");
    CK(free_hits(d) == 1,
       "E1 passes a NULL json argument to setError (data disposed exactly once)");
    CK(free_hits(slot0) == 1,
       "E1 data dispose frees the published slot record");
    CK(free_hits(tree) == 0,
       "E1 does not dispose the root Json tree (r1 is 0 at 0x28da38)");
    pass("invalid_type_e1");
}

/* ================================================================== */
/* 10. two slots: independent lookup, per-slot slot index               */
/* ================================================================== */
static void two_slots(void)
{
    tl_begin("two_slots");
    void *slots[2] = { slot_record("body"), slot_record("gear") };
    spSkeletonData *d = make_data(slots, 2);
    spAnimationShape *a = make_animation();
    Json *s0 = slot_node("body");
    Json *s1 = slot_node("gear");
    Json *t0 = timeline_node("attachment", 1);
    Json *t1 = timeline_node("color", 1);
    Json *f0 = node(0), *f1 = node(0);
    add(f0, str_key("name", "arm")); add(f0, num_key("time", 0.0f));
    add(t0, f0);
    add(f1, str_key("color", "ff0000ff")); add(f1, num_key("time", 0.5f));
    add(t1, f1);
    add(s0, t0);
    add(s1, t1);
    s0->next = s1;                     /* the slots child list the parent walks */

    CK(readSkeletonData_slotTimelines(s0, d, a, &parser_obj) == 1,
       "B5 two-slot walk completes");
    CK(obs.acreate == 1 && obs.ccreate == 1 && a->timelineCount == 2,
       "one timeline per slot, both published");
    CK(((spAttachmentTimelineShape *)a->timelines[0])->slotIndex == 0,
       "first slot resolves to index 0 through the real findSlotIndex");
    CK(((spColorTimelineShape *)a->timelines[1])->slotIndex == 1,
       "second slot resolves to index 1 through the real findSlotIndex");
    CK(obs.aset_index[0] == 0 && obs.cset_index[0] == 0,
       "each timeline's frame index restarts at 0");
    pass("two_slots");
}

/* ================================================================== */
/* 11. loop is driven by the child list, the tail by the declared count */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    tl_begin("declared_vs_child_count");
    void *slots[1] = { slot_record("body") };
    spSkeletonData *d = make_data(slots, 1);
    spAnimationShape *a = make_animation();
    Json *slot = slot_node("body");
    Json *tl = timeline_node("attachment", 3);      /* declares 3, has 1 */
    Json *f0 = node(0);
    add(f0, str_key("name", "arm")); add(f0, num_key("time", 0.4f));
    add(tl, f0);
    add(slot, tl);

    CK(readSkeletonData_slotTimelines(slot, d, a, &parser_obj) == 1,
       "B5 one-frame declared-three slot completes");
    CK(obs.aset_n == 1, "the frame loop follows the child list, not the declared count");
    CK(obs.acreate_frames == 3, "the creator still receives the declared count");
    CK(bits(a->duration) == 0u,
       "the tail reads frames[declared-1] (=0, never written), not frames[0]=0.4");
    pass("declared_vs_child_count");
}

void _start(void)
{
    test = "startup"; init_heap();
    fixture_install_error_reporter();
    dispatch_no_timelines();
    slot_not_found();
    attachment_frames();
    attachment_name_kind();
    color_frames_hex();
    color_hex_malformed();
    read_curve_both_paths();
    duration_and_cursor();
    invalid_type_e1();
    two_slots();
    declared_vs_child_count();
    out("SUMMARY all declared slots timeline family contracts passed\n");
    quit(0);
}
