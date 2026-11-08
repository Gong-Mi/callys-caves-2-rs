/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes,
 * the reporter and spEventData_create are SYNTHETIC providers. qemu executes
 * our linked C, never original libyoyo bytes. Original not executed; this is
 * not an original-equivalence claim.
 *
 * Subject: caller blocks B1 (0x28d19c..0x28d290, events array + EventData loop)
 * and B2 (0x28d290..0x28d2d4, animations array) of
 * spSkeletonJson_readSkeletonData.
 *
 * Synthetic boundary: spEventData_create (EventData.c, 0x285b94) is NOT
 * recovered here. The probe table stands in and records the single name
 * argument it receives; the module itself writes +0x04/+0x08/+0x0c.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start
#include "spine_read_animations.h"

struct ProbeEvent { spEventData ev; uint32_t index; };
static struct ProbeEvent probes[8];
static uint32_t creator_calls;
static const char *alloc_tag[128];
static void anim_probe_reset(void);

/* Synthetic EventData creator boundary: one argument, 16-byte zeroed record,
 * no deep copy of the name (the real 0x285b94 does strcpy its own copy, which
 * this block never observes). */
spEventData *spEventData_create(const char *name)
{
    if (creator_calls >= 8) fail("probe table exhausted");
    struct ProbeEvent *p = &probes[creator_calls];
    memset(p, 0, sizeof(*p));
    p->index = creator_calls;
    p->ev.name = name;
    ++creator_calls;
    return &p->ev;
}

/* Custom allocator: records (bytes, line, tag) so the three malloc anchors are
 * observable. Fixture reserve() oversizes blocks, as in the mesh/slots
 * precedents; no real-capacity claim is made. */
static void *anim_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "allocation roster/tag");
    void *p = reserve(n);
    alloc_tag[na] = tag;
    aa[na++] = (struct alloc){p, n, line};
    return p;
}

static void anim_begin(const char *name)
{
    begin(name);                 /* resets aa/na/nf and installs record_alloc */
    _setDebugMalloc(anim_alloc);
    _setFree(free);
    memset(probes, 0, sizeof(probes));
    creator_calls = 0;
    anim_probe_reset();
}

static uint32_t data_words[21];
static uint32_t *data_reset(void)
{
    memset(data_words, 0, sizeof(data_words));
    return data_words;
}
static struct alloc *line_entry(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return &aa[i];
    return 0;
}
static uint32_t tag_matches(uint32_t line, const char *want)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return alloc_tag[i] && strcmp(alloc_tag[i], want) == 0;
    return 0;
}
static Json *events_node(uint32_t declared)
{
    Json *e = node("events");
    e->unk_0c = declared;
    return e;
}
static Json *int_field(const char *key, int32_t v)
{
    Json *j = node(key);
    j->int_value = v;
    return j;
}
static Json *float_field(const char *key, float v)
{
    Json *j = node(key);
    j->float_value = v;
    return j;
}
static Json *animations_node(uint32_t declared)
{
    Json *a = node("animations");
    a->unk_0c = declared;
    return a;
}

static const char *TAG_WANT =
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c";

static void events_absent(void)
{
    anim_begin("events_absent");
    Json *tree = node(0);                    /* no "events" key at all */
    uint32_t *d = data_reset();
    d[11] = 0xaaaaaaaau; d[12] = 0xbbbbbbbbu;
    readSkeletonData_eventsSegment(tree, d);
    CK(d[11] == 0xaaaaaaaau && d[12] == 0xbbbbbbbbu,
       "B1 absent events leaves +0x2c/+0x30 untouched");
    CK(na == 0, "B1 absent events performs no allocation");
    CK(creator_calls == 0, "B1 absent events creates no EventData");
    pass("events_absent");
}

static void events_empty_children(void)
{
    anim_begin("events_empty_children");
    Json *tree = node(0);
    Json *events = events_node(2);           /* declared count, no child list */
    add(tree, events);
    uint32_t *d = data_reset();
    readSkeletonData_eventsSegment(tree, d);
    CK(d[11] == 2, "B1 publishes the declared events count (+0x2c)");
    CK(d[12] != 0, "B1 publishes the events array (+0x30) even with no children");
    CK(na == 1 && line_entry(1028) && line_entry(1028)->bytes == 8,
       "B1 empty children still allocates count*4 at line 1028");
    CK(tag_matches(1028, TAG_WANT), "B1 events allocation carries the SkeletonJson.c tag");
    CK(creator_calls == 0, "B1 empty children skips the EventData loop");
    pass("events_empty_children");
}

static void events_zero_count(void)
{
    anim_begin("events_zero_count");
    Json *tree = node(0);
    Json *events = events_node(0);
    add(tree, events);
    uint32_t *d = data_reset();
    d[11] = 0x12345678u; d[12] = 0x87654321u;
    readSkeletonData_eventsSegment(tree, d);
    CK(d[11] == 0, "B1 zero declared count overwrites +0x2c");
    CK(d[12] != 0 && d[12] != 0x87654321u,
       "B1 zero count still publishes the (malloc 0) array");
    CK(na == 1 && line_entry(1028) && line_entry(1028)->bytes == 0,
       "B1 zero count requests malloc(0) at line 1028");
    pass("events_zero_count");
}

static void events_multiple_fields(void)
{
    anim_begin("events_multiple_fields");
    Json *tree = node(0);
    Json *events = events_node(2);
    Json *e0 = node("footstep");
    add(e0, int_field("int", 7));
    add(e0, float_field("float", 2.5f));
    Json *s0 = string("string", "boom");
    add(e0, s0);
    Json *e1 = node("land");
    add(e1, int_field("int", 3));
    add(events, e0);
    add(events, e1);
    add(tree, events);

    uint32_t *d = data_reset();
    readSkeletonData_eventsSegment(tree, d);

    CK(d[11] == 2, "B1 publishes the declared count for two events");
    CK(creator_calls == 2, "one EventData per event child in list order");
    CK(na == 2 && line_entry(1028) && line_entry(1028)->bytes == 8,
       "B1 events array is a line-1028 allocation of count*4 bytes");
    CK(probes[0].ev.name != 0 && strcmp(probes[0].ev.name, "footstep") == 0
       && probes[0].ev.name == e0->name,
       "creator receives the Json member key as the event name");
    CK(strcmp(probes[1].ev.name, "land") == 0,
       "second creator call receives the second member key");

    CK(probes[0].ev.intValue == 7 && bits(probes[0].ev.floatValue) == 0x40200000u,
       "int lands at +0x04 and float bits at +0x08");
    CK(probes[0].ev.stringValue != 0
       && strcmp(probes[0].ev.stringValue, "boom") == 0
       && probes[0].ev.stringValue != s0->string_value,
       "string at +0x0c is an owned deep copy");
    CK(line_entry(1034) && line_entry(1034)->bytes == 5,
       "string deep copy is a line-1034 allocation of strlen+1 bytes");
    CK(tag_matches(1034, TAG_WANT), "string copy carries the SkeletonJson.c tag");

    CK(probes[1].ev.intValue == 3 && bits(probes[1].ev.floatValue) == 0
       && probes[1].ev.stringValue == 0,
       "absent float/string keys leave defaults and allocate nothing");
    CK(na == 2, "only one line-1034 allocation for the one present string");

    void **arr = (void **)(uintptr_t)d[12];
    CK(arr[0] == &probes[0].ev && arr[1] == &probes[1].ev,
       "B1 publishes EventData records in list order");
    pass("events_multiple_fields");
}

static void events_count_is_allocation_only(void)
{
    /* Declared count 0 while two children exist. The original loop is driven
     * by the child list (0x28d284..0x28d28c); the count is only the malloc
     * size argument. The fixture reserve() oversizes the zero-byte request so
     * the writes are observable; this asserts control flow, not capacity. */
    anim_begin("events_count_is_allocation_only");
    Json *tree = node(0);
    Json *events = events_node(0);
    add(events, node("a"));
    add(events, node("b"));
    add(tree, events);

    uint32_t *d = data_reset();
    readSkeletonData_eventsSegment(tree, d);
    CK(na == 1 && line_entry(1028) && line_entry(1028)->bytes == 0,
       "B1 allocates from the declared count, not the child count");
    CK(creator_calls == 2, "B1 loop is driven by the child list, not the declared count");
    void **arr = (void **)(uintptr_t)d[12];
    CK(arr[0] == &probes[0].ev && arr[1] == &probes[1].ev,
       "B1 publishes every child even past the declared count");
    pass("events_count_is_allocation_only");
}

static void animations_absent(void)
{
    anim_begin("animations_absent");
    Json *tree = node(0);                    /* no "animations" key */
    uint32_t *d = data_reset();
    d[13] = 0xccccccccu; d[14] = 0xddddddddu;
    Json *first = readSkeletonData_animationsArray(tree, d);
    CK(first == 0, "B2 absent animations returns NULL");
    CK(d[13] == 0xccccccccu && d[14] == 0xddddddddu,
       "B2 absent animations leaves +0x34/+0x38 untouched");
    CK(na == 0, "B2 absent animations performs no allocation");
    pass("animations_absent");
}

static void animations_empty_children(void)
{
    anim_begin("animations_empty_children");
    Json *tree = node(0);
    Json *anims = animations_node(2);        /* declared count, no child */
    add(tree, anims);
    uint32_t *d = data_reset();
    d[13] = 0xdeadbeefu;
    Json *first = readSkeletonData_animationsArray(tree, d);
    CK(first == 0, "B2 empty children returns NULL");
    CK(d[14] != 0, "B2 publishes the animations array (+0x38)");
    CK(d[13] == 0xdeadbeefu, "B2 does not write animationsCount (+0x34)");
    CK(na == 1 && line_entry(1043) && line_entry(1043)->bytes == 8,
       "B2 empty children allocates count*4 at line 1043");
    CK(tag_matches(1043, TAG_WANT), "B2 animations allocation carries the SkeletonJson.c tag");
    pass("animations_empty_children");
}

static void animations_children(void)
{
    anim_begin("animations_children");
    Json *tree = node(0);
    Json *anims = animations_node(3);
    Json *walk = node("walk");
    Json *idle = node("idle");
    Json *run = node("run");
    add(anims, walk);
    add(anims, idle);
    add(anims, run);
    add(tree, anims);

    uint32_t *d = data_reset();
    d[13] = 0xdeadbeefu;
    Json *first = readSkeletonData_animationsArray(tree, d);
    CK(first == walk, "B2 returns animations->child (first animation)");
    CK(d[14] != 0, "B2 publishes the animations array at +0x38");
    CK(d[13] == 0xdeadbeefu, "B2 leaves animationsCount (+0x34) to the per-animation loop");
    CK(na == 1 && line_entry(1043) && line_entry(1043)->bytes == 12,
       "B2 array is a line-1043 allocation of count*4 bytes");
    pass("animations_children");
}

static void chain_order(void)
{
    anim_begin("chain_order");
    Json *tree = node(0);
    Json *events = events_node(1);
    Json *cue = node("cue");
    add(cue, int_field("int", 1));
    add(cue, string("string", "x"));
    add(events, cue);
    Json *anims = animations_node(2);
    Json *a0 = node("a");
    Json *a1 = node("b");
    add(anims, a0);
    add(anims, a1);
    add(tree, events);
    add(tree, anims);

    uint32_t *d = data_reset();
    readSkeletonData_eventsSegment(tree, d);      /* B1 then */
    Json *first = readSkeletonData_animationsArray(tree, d); /* B2 */

    CK(creator_calls == 1 && d[11] == 1 && d[12] != 0,
       "B1 runs to completion before B2");
    CK(first == a0 && d[14] != 0, "B2 sees the same tree after B1");
    CK(d[13] == 0, "B2 leaves animationsCount at its pre-existing value");
    CK(na == 3 && line_entry(1028) && line_entry(1028)->bytes == 4
       && line_entry(1034) && line_entry(1034)->bytes == 2
       && line_entry(1043) && line_entry(1043)->bytes == 8,
       "all three malloc anchors hit with the original request sizes");
    pass("chain_order");
}

/* ===================================================================== */
/* B3 / B3b / B4 fixtures                                                */
/* ===================================================================== */

/* Synthetic spAnimation_create boundary (0x2812b4, 116 B, NOT recovered).
 * It records the two register arguments in the order the block passes them
 * (r0 = animation->name from [sp,#0x1c]->+0x1c, r1 = timelineCount) and hands
 * back a zeroed 16-byte record. The count argument is kept separately so the
 * module's own +0x08 reset (0x28d4d4) stays observable. */
struct ProbeAnimation { spAnimation anim; int32_t arg_count; uint32_t index; };
static struct ProbeAnimation aprobes[8];
static uint32_t acreate_calls;

spAnimation *spAnimation_create(const char *name, int32_t timelineCount)
{
    if (acreate_calls >= 8) fail("animation probe table exhausted");
    struct ProbeAnimation *p = &aprobes[acreate_calls];
    memset(p, 0, sizeof(*p));
    p->index = acreate_calls;
    p->arg_count = timelineCount;
    p->anim.name = name;
    p->anim.timelineCount = timelineCount;
    /* +0x0c (timelines) stays NULL: the creator would malloc it, the block
     * under test must never touch it. */
    ++acreate_calls;
    return &p->anim;
}

static void anim_probe_reset(void)
{
    memset(aprobes, 0, sizeof(aprobes));
    acreate_calls = 0;
}

/* One Json child: node(key) with the +0x0c size word the sum loop reads. */
static Json *child_node(Json *parent, const char *key, uint32_t size)
{
    Json *n = node(key);
    n->unk_0c = size;
    add(parent, n);
    return n;
}

/* Frame with every slot zeroed except the ones a test wants to watch.
 * `sentinel` is stored in +0x2c (slotsChild) so "untouched" is observable. */
static void frame_reset(spAnimationFrame *f, Json *animation, Json *sentinel)
{
    memset(f, 0, sizeof(*f));
    f->animation = animation;
    f->slotsChild = sentinel;
}

/* --------------------------------- B3 -------------------------------- */

static void animation_frame_init(void)
{
    anim_begin("animation_frame_init");
    Json *anim = node("walk");
    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    int32_t data_slot[2] = {(int32_t)0x11111111, (int32_t)0x22222222};
    int32_t json_slot = (int32_t)0x33333333;

    readSkeletonData_animationFrameInit(&f, data_slot, &json_slot);

    CK(f.div3_magic == 0x55555556u,
       "B3 writes 0x55555556 into the sp+0x60 slot");
    CK(f.bonesKey != 0 && strcmp(f.bonesKey, "bones") == 0
       && f.slotsKey != 0 && strcmp(f.slotsKey, "slots") == 0
       && f.ikKey != 0 && strcmp(f.ikKey, "ik") == 0
       && f.transformKey != 0 && strcmp(f.transformKey, "transform") == 0,
       "cached key pointers are bones, slots, ik, transform in slot order");
    CK(f.data == data_slot && f.skeletonJson == &json_slot,
       "B3 spills data (r9) and the spSkeletonJson pointer (r8)");
    CK(f.animation == anim && f.slotsChild == 0,
       "B3 leaves the B2 animation slot and the slotsChild slot alone");
    CK(nf == 0 && na == 0, "B3 preamble performs no allocation and no free");
    CK(offsetof(spAnimationFrame, div3_magic) == 0x48
       && offsetof(spAnimationFrame, bonesKey) == 0x4c
       && offsetof(spAnimationFrame, slotsKey) == 0x50
       && offsetof(spAnimationFrame, ikKey) == 0x54
       && offsetof(spAnimationFrame, transformKey) == 0x58
       && offsetof(spAnimationFrame, bones) == 0x18
       && offsetof(spAnimationFrame, ik) == 0x1c
       && offsetof(spAnimationFrame, transform) == 0x20
       && offsetof(spAnimationFrame, paths) == 0x2c
       && offsetof(spAnimationFrame, deform) == 0x38
       && offsetof(spAnimationFrame, drawOrder) == 0x10
       && offsetof(spAnimationFrame, events) == 0x34
       && offsetof(spAnimationFrame, slotsChild) == 0x14
       && sizeof(spAnimationFrame) == 0x60,
       "frame slice keeps the original [sp,#0x18]..[sp,#0x74] slot offsets");
    pass("animation_frame_init");
}

static void animation_keys_eight(void)
{
    anim_begin("animation_keys_eight");
    Json *anim = node("walk");
    /* Deliberately scrambled child order: what pins the block is the slot each
     * result lands in, not the order the children appear in the Json list. */
    Json *events = child_node(anim, "events", 1);
    Json *deform = child_node(anim, "deform", 1);
    Json *bones = child_node(anim, "bones", 1);
    Json *paths = child_node(anim, "paths", 1);
    Json *drawOrder = child_node(anim, "drawOrder", 1);
    Json *ik = child_node(anim, "ik", 1);
    Json *transform = child_node(anim, "transform", 1);
    Json *slots = child_node(anim, "slots", 1);

    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *got_slots = readSkeletonData_animationKeys(&f);

    CK(f.bones == bones, "B3 bones slot holds the node named bones");
    CK(f.ik == ik, "B3 ik slot holds the node named ik");
    CK(f.transform == transform, "B3 transform slot holds the node named transform");
    CK(f.paths == paths, "B3 paths slot holds the node named paths");
    CK(f.deform == deform, "B3 deform slot holds the node named deform");
    CK(f.drawOrder == drawOrder, "B3 drawOrder slot holds the node named drawOrder");
    CK(f.events == events, "B3 events slot holds the node named events");
    CK(got_slots == slots, "B3 returns the slots node in r4");
    CK(f.bones != f.ik && f.ik != f.transform && f.paths != f.deform
       && f.drawOrder != f.events && f.bones != 0 && f.slotsChild == 0,
       "the eight results are distinct nodes and no other slot is written");
    CK(f.div3_magic == 0x55555556u && strcmp(f.bonesKey, "bones") == 0,
       "B3 lookup leaves the cached 0x55555556 word and key literals intact");
    CK(na == 0 && nf == 0, "B3 lookup performs no allocation");
    pass("animation_keys_eight");
}

static void animation_keys_missing(void)
{
    anim_begin("animation_keys_missing");
    Json *anim = node("walk");              /* no sub-nodes at all */
    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *slots = readSkeletonData_animationKeys(&f);

    CK(slots == 0 && f.bones == 0 && f.ik == 0 && f.transform == 0
       && f.paths == 0 && f.deform == 0 && f.drawOrder == 0 && f.events == 0,
       "B3 publishes NULL for all eight missing sub-nodes");
    CK(f.div3_magic == 0x55555556u && f.animation == anim,
       "B3 miss path keeps the frame contract");
    pass("animation_keys_missing");
}

static void animation_magic_signed_div3(void)
{
    /* 0x28d2d8 movw 0x5556 / 0x28d2e0 movt 0x5555 = 0x55555556. Its only
     * reader (0x28e128, deform) is NOT recovered, so the constant is pinned
     * here by the arithmetic identity the reader needs: for the ARM sequence
     *   smull r1,r2,r1,r3 (0x28e134) ; sub r3,r2,r3,asr#31 (0x28e13c)
     * the quotient is trunc(v/3) for every int32 v. */
    anim_begin("animation_magic_signed_div3");
    spAnimationFrame f;
    frame_reset(&f, 0, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    const int32_t v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 99, 100, -1, -2, -3, -4,
                         -7, -99, -100, 123456789, -123456789,
                         2147483647, 2147483646, -2147483647, -2147483647 - 1};
    for (unsigned i = 0; i < sizeof(v) / sizeof(v[0]); ++i) {
        int64_t product = (int64_t)v[i] * (int64_t)f.div3_magic;
        int32_t hi = (int32_t)(product >> 32);
        int32_t quotient = (int32_t)(hi - (v[i] >> 31));
        CK(quotient == v[i] / 3,
           "0x55555556 is the truncating signed /3 magic at 0x28e134/0x28e13c");
    }
    CK(f.div3_magic == 0x55555556u, "the magic word is the exact 32-bit constant");
    pass("animation_magic_signed_div3");
}

/* ------------------------------ B3b / B4 ----------------------------- */

static void animation_timelines_empty(void)
{
    anim_begin("animation_timelines_empty");
    Json *anim = node("idle");
    Json *sentinel = node("sentinel");
    spAnimationFrame f;
    frame_reset(&f, anim, sentinel);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *slots = readSkeletonData_animationKeys(&f);   /* all NULL */
    spAnimation *an = readSkeletonData_animationTimelines(&f, slots);

    CK(acreate_calls == 1, "B4 calls spAnimation_create exactly once");
    CK(aprobes[0].anim.name == anim->name,
       "create receives the animation member key as its name");
    CK(aprobes[0].arg_count == 0, "B4 empty animation counts zero timelines");
    CK(an == &aprobes[0].anim, "B4 returns the created spAnimation");
    /* The +0x08 reset is only observable with a non-zero create argument; the
     * sums case (65 -> 0) carries that assertion. */
    CK(an->timelines == 0 && an->opaque_04 == 0,
       "B4 never touches the timelines word (+0x0c) nor +0x04");
    CK(f.slotsChild == sentinel, "B4 leaves sp+0x2c alone when the slots node is absent");
    CK(f.div3_magic == 0x55555556u,
       "B4 does not write the sp+0x60 slot written by B3");
    CK(na == 0 && nf == 0, "B4 performs no allocation");
    pass("animation_timelines_empty");
}

static void animation_timelines_sums(void)
{
    anim_begin("animation_timelines_sums");
    Json *anim = node("walk");
    Json *bones = node("bones");
    child_node(bones, 0, 1);
    child_node(bones, 0, 2);
    Json *slots = node("slots");
    child_node(slots, 0, 4);
    Json *ik = child_node(anim, "ik", 5);
    Json *transform = child_node(anim, "transform", 6);
    Json *paths = node("paths");
    child_node(paths, 0, 7);
    child_node(paths, 0, 8);
    Json *deform = node("deform");
    Json *skin1 = node(0);
    child_node(skin1, 0, 9);
    child_node(skin1, 0, 10);
    Json *skin2 = node(0);
    child_node(skin2, 0, 11);
    Json *skin3 = node(0);                 /* skin with no slots: adds nothing */
    add(deform, skin1);
    add(deform, skin2);
    add(deform, skin3);
    Json *drawOrder = child_node(anim, "drawOrder", 0xdead);
    Json *events = child_node(anim, "events", 0xbeef);
    add(anim, bones);
    add(anim, slots);
    add(anim, paths);
    add(anim, deform);

    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *got_slots = readSkeletonData_animationKeys(&f);
    spAnimation *an = readSkeletonData_animationTimelines(&f, got_slots);

    /* 1+2 bones, 4 slots, 5 ik, 6 transform, 7+8 paths, 9+10+11 deform, +1 +1 */
    CK(aprobes[0].arg_count == 65,
       "B4 sums bones/slots/paths/deform child sizes plus ik/transform fields plus drawOrder/events");
    CK(f.bones == bones && f.paths == paths && f.deform == deform
       && f.drawOrder == drawOrder && f.events == events && f.ik == ik
       && f.transform == transform,
       "the sum reads the eight slots B3 published");
    CK(an == &aprobes[0].anim && an->timelineCount == 0,
       "B4 returns the created record with +0x08 reset");
    CK(f.slotsChild == slots->child,
       "B4 publishes slots->child into the sp+0x2c slot");
    CK(na == 0 && nf == 0, "the sum path allocates nothing");
    pass("animation_timelines_sums");
}

static void animation_timelines_partial(void)
{
    anim_begin("animation_timelines_partial");
    Json *anim = node("run");
    Json *ik = child_node(anim, "ik", 3);
    Json *transform = child_node(anim, "transform", 2);
    Json *sentinel = node("sentinel");

    spAnimationFrame f;
    frame_reset(&f, anim, sentinel);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *slots = readSkeletonData_animationKeys(&f);
    spAnimation *an = readSkeletonData_animationTimelines(&f, slots);

    CK(slots == 0 && f.bones == 0 && f.ik == ik && f.transform == transform,
       "absent bones/slots publish NULL nodes while ik/transform still resolve");
    CK(aprobes[0].arg_count == 5,
       "B4 counts only the present ik/transform fields (3+2)");
    CK(f.slotsChild == sentinel && an->timelineCount == 0,
       "absent slots leaves sp+0x2c untouched and still resets +0x08");
    pass("animation_timelines_partial");
}

static void animation_deform_nested(void)
{
    anim_begin("animation_deform_nested");
    Json *anim = node("cast");
    Json *deform = node("deform");
    Json *skinA = node("skinA");
    child_node(skinA, 0, 20);
    child_node(skinA, 0, 1);
    Json *skinB = node("skinB");
    child_node(skinB, 0, 2);
    Json *skinC = node("skinC");           /* no slot children */
    add(deform, skinA);
    add(deform, skinB);
    add(deform, skinC);
    add(anim, deform);

    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    Json *slots = readSkeletonData_animationKeys(&f);
    readSkeletonData_animationTimelines(&f, slots);

    CK(aprobes[0].arg_count == 23,
       "B4 deform loop sums every skin's slot children (20+1+2)");
    pass("animation_deform_nested");
}

static void animation_legacy_both_keys(void)
{
    /* Json_getItem compares with strcasecmp (0x287414 bl strcasecmp@plt), so
     * "drawOrder" and "draworder" are the SAME query and the FIRST matching
     * child wins. "new key priority" is therefore really child order. */
    anim_begin("animation_legacy_both_keys");
    Json *animA = node("a");
    Json *legacy_first = child_node(animA, "draworder", 0);
    Json *new_second = child_node(animA, "drawOrder", 0);
    spAnimationFrame f;
    frame_reset(&f, animA, 0);
    readSkeletonData_animationFrameInit(&f, 0, 0);
    readSkeletonData_animationKeys(&f);
    CK(f.drawOrder == legacy_first && f.drawOrder != new_second,
       "first matching child wins when both draw-order spellings exist");

    Json *animB = node("b");
    Json *new_first = child_node(animB, "drawOrder", 0);
    Json *legacy_second = child_node(animB, "draworder", 0);
    spAnimationFrame g;
    frame_reset(&g, animB, 0);
    readSkeletonData_animationFrameInit(&g, 0, 0);
    readSkeletonData_animationKeys(&g);
    CK(g.drawOrder == new_first && g.drawOrder != legacy_second,
       "the other child order selects the drawOrder-spelled node");
    pass("animation_legacy_both_keys");
}

static void animation_legacy_fallback(void)
{
    anim_begin("animation_legacy_fallback");
    Json *stale = node("stale");

    /* (a) B3b hit: a lowercase-only child is found through strcasecmp. */
    Json *anim = node("walk");
    Json *legacy = child_node(anim, "draworder", 0);
    spAnimationFrame f;
    frame_reset(&f, anim, 0);
    f.drawOrder = stale;
    readSkeletonData_animationLegacyDrawOrder(&f);
    CK(f.drawOrder == legacy,
       "B3b publishes the legacy node into the drawOrder slot");
    CK(f.bones == 0 && f.events == 0 && f.paths == 0,
       "B3b writes only the drawOrder slot");

    /* (b) B3b miss: the store at 0x28eb38 is unconditional, so a stale slot
     * becomes NULL. This is the only observable effect of the retry. */
    Json *anim2 = node("idle");
    spAnimationFrame g;
    frame_reset(&g, anim2, 0);
    g.drawOrder = stale;
    readSkeletonData_animationLegacyDrawOrder(&g);
    CK(g.drawOrder == 0,
       "B3b miss overwrites a stale drawOrder with NULL");

    /* (c) keys() on a lowercase-only child: the 0x28d38c lookup already hits
     * (case-insensitive getItem), so the legacy retry is never reached. */
    Json *anim3 = node("run");
    Json *lower = child_node(anim3, "draworder", 0);
    spAnimationFrame h;
    frame_reset(&h, anim3, 0);
    readSkeletonData_animationFrameInit(&h, 0, 0);
    Json *slots = readSkeletonData_animationKeys(&h);
    CK(slots == 0 && h.drawOrder == lower,
       "case-insensitive Json_getItem finds the legacy spelling in the drawOrder lookup");

    /* (d) keys() with no draw-order child at all: the retry runs and stores
     * the NULL the first lookup produced. */
    Json *anim4 = node("jump");
    spAnimationFrame k;
    frame_reset(&k, anim4, 0);
    readSkeletonData_animationFrameInit(&k, 0, 0);
    readSkeletonData_animationKeys(&k);
    CK(k.drawOrder == 0, "drawOrder stays NULL when neither spelling exists");
    pass("animation_legacy_fallback");
}

static void animation_chain_two(void)
{
    anim_begin("animation_chain_two");
    Json *anims = node(0);
    Json *a0 = node("walk");
    Json *b0 = child_node(a0, "bones", 1);
    Json *dk0 = child_node(a0, "drawOrder", 0);
    Json *a1 = node("run");
    Json *b1 = child_node(a1, "bones", 3);
    child_node(b1, 0, 3);            /* one bone entry: its +0x0c is what the sum reads */
    Json *ik1 = child_node(a1, "ik", 2);
    add(anims, a0);
    add(anims, a1);

    int32_t data_slot[1] = {0x7f};
    spAnimationFrame f;
    frame_reset(&f, anims->child, 0);        /* B2 0x28d2c8 stored animations->child */
    readSkeletonData_animationFrameInit(&f, data_slot, 0);

    Json *s0 = readSkeletonData_animationKeys(&f);
    spAnimation *an0 = readSkeletonData_animationTimelines(&f, s0);
    /* loop tail 0x28e788..0x28e798 (fixture-side, NOT recovered here): the
     * animation node slot advances to ->next and the tail publishes the record. */
    f.animation = f.animation->next;
    Json *s1 = readSkeletonData_animationKeys(&f);
    spAnimation *an1 = readSkeletonData_animationTimelines(&f, s1);

    CK(acreate_calls == 2, "one spAnimation per animation node");
    CK(aprobes[0].anim.name == a0->name && aprobes[1].anim.name == a1->name,
       "each create receives its own animation member key");
    CK(aprobes[0].arg_count == 1 && aprobes[1].arg_count == 5,
       "each animation gets its own timeline count (drawOrder 1; bone 3 + ik 2)");
    CK(an0 == &aprobes[0].anim && an1 == &aprobes[1].anim && an0 != an1,
       "B4 returns a distinct record per animation");
    CK(f.bones == b1 && f.ik == ik1 && f.drawOrder == 0,
       "the second iteration re-queries the sub-nodes for the next animation");
    CK(f.div3_magic == 0x55555556u && f.data == data_slot,
       "the loop-invariant cache and input spills survive both iterations");
    CK(dk0 != 0 && b0 != b1 && an0->timelineCount == 0 && an1->timelineCount == 0,
       "both records are reset to +0x08 == 0");
    pass("animation_chain_two");
}

void _start(void)
{
    test = "startup"; init_heap();
    events_absent();
    events_empty_children();
    events_zero_count();
    events_multiple_fields();
    events_count_is_allocation_only();
    animations_absent();
    animations_empty_children();
    animations_children();
    chain_order();
    animation_frame_init();
    animation_keys_eight();
    animation_keys_missing();
    animation_magic_signed_div3();
    animation_timelines_empty();
    animation_timelines_sums();
    animation_timelines_partial();
    animation_deform_nested();
    animation_legacy_both_keys();
    animation_legacy_fallback();
    animation_chain_two();
    out("SUMMARY all declared animations entry and per-animation contracts passed\n");
    quit(0);
}
