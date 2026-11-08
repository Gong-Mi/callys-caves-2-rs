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
    out("SUMMARY all declared animations entry contracts passed\n");
    quit(0);
}
