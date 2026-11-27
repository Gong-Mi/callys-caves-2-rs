/* Reconstructed ARM32 consumers only. Heap, libc strings, JSON tree nodes, the
 * event-data table and the event-timeline entry points are SYNTHETIC providers.
 * qemu executes our linked C, never original libyoyo bytes.  Original not
 * executed; this is not an original-equivalence claim.
 *
 * Subject: the event-timeline family of spSkeletonJson_readSkeletonData
 *   B16  0x28e614..0x28e7a4  ("events" node test, spEventTimeline_create,
 *                             per-frame findEvent + event build + line-494
 *                             stringValue copy + setFrame, timeline publish /
 *                             duration tail, animationsCount publish pair)
 *   E5   0x28e7b4..0x28e7f4  ("Event not found: ", NULL setError json argument)
 *   B18  0x28e7a4..0x28e7b4  (Json_dispose(ROOT) then return data)
 *
 * REAL recovered bodies linked here (no stubs):
 *   Json_getItem/getString/getInt/getFloat   json_interface
 *   Json_dispose / ReportSpineError          spine_json_support
 *   _spSkeletonJson_setError                 spine_json_error
 *   spAnimation_dispose / spSkeletonData_dispose / spEventData_dispose
 *                                            spine_skeleton_data
 *   _malloc / _free / _calloc                spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture reproduces
 * the disassembled bodies and records every argument):
 *   spSkeletonData_findEvent 0x28b180 — linear strcmp scan over data->events
 *     (count +0x2c, array +0x30, name at event+0x00; NULL on miss).
 *   spEvent_create 0x285b44 — _calloc(1,20,Event.c,36); +0x00 = data,
 *     +0x04 = time; the other three words stay zero.
 *   spEvent_dispose 0x285b78 — _free(event+0x10) then _free(event) (the tail
 *     `b _free` at 0x285b90 frees self).
 *   spEventTimeline_create 0x282c8c — _calloc(1,20,Animation.c,611), type 6,
 *     +0x08 frameCount, +0x0c times = _calloc(n,4,tag,615),
 *     +0x10 events = _calloc(n,4,tag,616).
 *   spEventTimeline_setFrame 0x282d14 — times[i] = event->time (bits at
 *     event+0x04), _free(events[i]), events[i] = event.
 */
#define _start mesh_fixture_unused_start
#include "../../spine_read_mesh/fixture/check.c"
#undef _start

#include "spine_read_tl_event.h"
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"
#include "../../spine_json_error/src/spine_json_error.h"

/* Console adapter lives in spine_linked_postpass/fixture/reporter_adapter.c */
extern void fixture_install_error_reporter(void);

#define EVENT_TIMELINE_SOURCE_TAG \
    "jni/../jni/yoyo/../../../spine-c/src/spine/Animation.c"

/* ------------------------------------------------------------------ */
/* observation tables                                                  */
/* ------------------------------------------------------------------ */
#define MAX_FRAMES 8
#define MAX_EVENTS 4

static struct {
    int create_n;
    int create_frames;
    void *timeline;
    int set_n;
    int set_index[MAX_FRAMES];
    uint32_t set_time[MAX_FRAMES];
    void *set_event[MAX_FRAMES];
    int ev_n;
    uint32_t ev_time[MAX_FRAMES];
    const void *ev_data[MAX_FRAMES];
    void *ev_ptr[MAX_FRAMES];
    int find_n;
    const char *find_name[MAX_FRAMES];
    void *find_ret[MAX_FRAMES];
    int cmp_n;
    int dispose_n;
    void *dispose_ptr[MAX_FRAMES];
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

/* Allocator roster: records (bytes, line, tag) for every _malloc/_calloc so
 * the line-494 copy and the timeline's 611/615/616 callocs are attributable. */
static void *ev_alloc(uint32_t n, const char *tag, uint32_t line)
{
    CK(na < 128 && tag, "event allocation roster/tag");
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
static uint32_t alloc_bytes(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) return aa[i].bytes;
    fail("missing allocation line");
    return 0;
}
static int tag_is(uint32_t line, const char *want)
{
    for (unsigned i = 0; i < na; ++i)
        if (aa[i].line == line) return alloc_tag[i] && strcmp(alloc_tag[i], want) == 0;
    return 0;
}
static unsigned free_hits(const void *p)
{
    unsigned c = 0;
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) ++c;
    return c;
}
static int free_slot(const void *p)
{
    for (unsigned i = 0; i < nf; ++i) if (ff[i] == p) return (int)i;
    return -1;
}
/* Position in the ALLOCATION roster (allocation order, not free order). */
static int alloc_slot(uint32_t line)
{
    for (unsigned i = 0; i < na; ++i) if (aa[i].line == line) return (int)i;
    return -1;
}

static void *tl_zero(uint32_t bytes)
{
    void *p = reserve(bytes);
    memset(p, 0, bytes);
    return p;
}

static char *ev_strdup(const char *s, const char *tag, uint32_t line)
{
    uint32_t n = (uint32_t)strlen(s) + 1u;
    char *p = (char *)_malloc(n, tag, line);
    strcpy(p, s);
    return p;
}

/* ------------------------------------------------------------------ */
/* synthetic entry points (bodies read off the disassembly)            */
/* ------------------------------------------------------------------ */
static uint32_t ev_vtable_words[2];

/* 0x28b180: r7 = count(+0x2c); ble -> NULL; r6 = array(+0x30); scan with
 * strcmp on event+0x00; increment i BEFORE the count compare. */
void *spSkeletonData_findEvent(void *data_raw, const char *name)
{
    spSkeletonDataEventShape *d = (spSkeletonDataEventShape *)data_raw;
    int32_t count = d->eventsCount;
    void *found = 0;

    if (obs.find_n < MAX_FRAMES) {
        obs.find_name[obs.find_n] = name;
        obs.find_ret[obs.find_n] = 0;
    }
    if (count > 0) {
        int32_t i = 0;
        do {
            spEventDataEventShape *ev = d->events[i];
            ++i;
            ++obs.cmp_n;
            if (strcmp(ev->name, name) == 0) { found = ev; break; }
        } while (i < count);
    }
    if (obs.find_n < MAX_FRAMES) obs.find_ret[obs.find_n] = found;
    ++obs.find_n;
    return found;
}

/* 0x285b44: _calloc(1,20,Event.c,36) ; +0x00 = data ; +0x04 = time. */
void *spEvent_create(float time, const void *data)
{
    spEventShape *e = (spEventShape *)_calloc(1, 20, EVENT_SOURCE_TAG, 36u);

    e->data = data;
    e->time = time;
    if (obs.ev_n < MAX_FRAMES) {
        obs.ev_time[obs.ev_n] = bits(time);
        obs.ev_data[obs.ev_n] = data;
        obs.ev_ptr[obs.ev_n] = e;
    }
    ++obs.ev_n;
    return e;
}

/* 0x285b78: ldr r0,[r0,#0x10] (0x285b80) ; bl _free (0x285b84) ;
 * b _free (0x285b90) with r0 = self. */
void spEvent_dispose(void *event)
{
    spEventShape *e = (spEventShape *)event;

    _free(e->stringValue);                 /* 0x285b80/0x285b84 */
    _free(e);                              /* 0x285b90 b _free */
    if (obs.dispose_n < MAX_FRAMES) obs.dispose_ptr[obs.dispose_n] = event;
    ++obs.dispose_n;
}

/* 0x282c8c: _calloc(1,20,Animation.c,611) ; type 6 ; +0x08 frameCount ;
 * +0x0c _calloc(n,4,tag,615) ; +0x10 _calloc(n,4,tag,616). */
void *spEventTimeline_create(int frameCount)
{
    int n = frameCount < 1 ? 1 : frameCount;
    spEventTimelineShape *t =
        (spEventTimelineShape *)_calloc(1, 20, EVENT_TIMELINE_SOURCE_TAG, 611u);

    t->type = 6u;                          /* 0x282cb8 mov r1,#6 */
    t->vtable = ev_vtable_words;
    t->frameCount = frameCount;            /* 0x282cd0 */
    t->times = (float *)_calloc((uint32_t)n, 4u, EVENT_TIMELINE_SOURCE_TAG, 615u);
                                           /* 0x282cd8..0x282cf0 */
    t->events = (spEventShape **)_calloc((uint32_t)n, 4u,
                                         EVENT_TIMELINE_SOURCE_TAG, 616u);
                                           /* 0x282cf8..0x282cfc */
    ++obs.create_n;
    obs.create_frames = frameCount;
    obs.timeline = t;
    return t;
}

/* 0x282d14: r0 = timeline, r1 = i, r2 = event.
 *   0x282d28 ldr r2,[r2,#0x4]     event->time bits
 *   0x282d2c/0x282d38             times[i] = time
 *   0x282d34/0x282d3c             _free(events[i])
 *   0x282d40/0x282d44             events[i] = event
 */
void spEventTimeline_setFrame(void *timeline, int frameIndex, void *event)
{
    spEventTimelineShape *t = (spEventTimelineShape *)timeline;
    spEventShape *e = (spEventShape *)event;

    if (obs.set_n >= MAX_FRAMES) fail("event setFrame table exhausted");
    t->times[frameIndex] = e->time;
    _free(t->events[frameIndex]);
    t->events[frameIndex] = e;
    obs.set_index[obs.set_n] = frameIndex;
    obs.set_time[obs.set_n] = bits(e->time);
    obs.set_event[obs.set_n] = event;
    ++obs.set_n;
}

/* ------------------------------------------------------------------ */
/* scaffolding                                                         */
/* ------------------------------------------------------------------ */
static spSkeletonJson parser_obj;

static void ev_begin(const char *name)
{
    begin(name);                    /* resets aa/na/nf, installs a callback */
    _setDebugMalloc(ev_alloc);
    memset(&obs, 0, sizeof(obs));
    memset(&parser_obj, 0, sizeof(parser_obj));
    report_count = 0;
    reported[0] = report_format[0] = 0;
    ev_vtable_words[0] = 0u;
    ev_vtable_words[1] = 0x282d14u; /* the real setFrame entry, as a marker */
}

/* spSkeletonData: real 84-byte calloc(1,84,SkeletonData.c,37). */
static spSkeletonDataEventShape *make_data(void)
{
    return (spSkeletonDataEventShape *)spSkeletonData_create();
}

/* B1's shape: count at +0x2c, array = _malloc(count*4, SkeletonJson.c, 1028). */
static void attach_events(spSkeletonDataEventShape *d, int n,
                          spEventDataEventShape **tab)
{
    void **array = 0;

    if (n > 0) {
        array = (void **)_malloc((uint32_t)n * 4u, SPINE_JSON_SOURCE_TAG, 1028u);
        for (int i = 0; i < n; ++i) array[i] = tab[i];
    }
    d->eventsCount = n;
    d->events = (spEventDataEventShape **)array;
}

/* spEventData_create 0x285b94: _calloc(1,16,EventData.c,36), name = _malloc
 * (strlen+1, EventData.c, 37) + strcpy.  B1 adds string = line 1034. */
static spEventDataEventShape *make_event_data(const char *name, int32_t intv,
                                              float floatv, const char *str)
{
    spEventDataEventShape *ed = (spEventDataEventShape *)tl_zero(sizeof(*ed));

    ed->name = ev_strdup(name, EVENTDATA_SOURCE_TAG, 37u);
    ed->intValue = intv;
    ed->floatValue = floatv;
    if (str != 0)
        ed->stringValue = ev_strdup(str, SPINE_JSON_SOURCE_TAG, 1034u);
    return ed;
}

static spAnimationEventShape *make_animation(void)
{
    spAnimationEventShape *a =
        (spAnimationEventShape *)tl_zero(sizeof(*a));
    a->timelines = (void **)tl_zero(4u * MAX_FRAMES);
    return a;
}

/* Json helpers: Json_getItem matches on +0x1c with strcasecmp. */
static Json *num_key(const char *key, float value)
{
    Json *n = node(key);
    n->float_value = value;
    return n;
}
static Json *int_key(const char *key, int32_t value)
{
    Json *n = node(key);
    n->int_value = value;
    return n;
}
static Json *str_key(const char *key, const char *value)
{
    Json *n = node(key);
    n->string_value = value;
    return n;
}
/* the "events" member: +0x0c is the DECLARED frame count handed to create */
static Json *events_node(int32_t declared)
{
    Json *n = node("events");
    n->unk_0c = (uint32_t)declared;
    return n;
}

/* ================================================================== */
/* 1. no "events" member at all                                        */
/* ================================================================== */
static void event_absent(void)
{
    ev_begin("event_absent");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();

    CK(readSkeletonData_eventTimelines(0, d, a, &parser_obj) == EVENT_TL_OK,
       "B16 with a NULL events node returns 1 and publishes nothing here");
    CK(obs.create_n == 0 && obs.set_n == 0 && obs.ev_n == 0 && obs.find_n == 0,
       "a NULL events node never creates a timeline, never looks up a name");
    CK(a->timelineCount == 0 && alloc_count(611u) == 0,
       "nothing is published and no timeline record is allocated");
    pass("event_absent");
}

/* ================================================================== */
/* 2. "events" present with no frames: create still runs               */
/* ================================================================== */
static void event_without_frames(void)
{
    ev_begin("event_without_frames");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    Json *events = events_node(2);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "an empty events object returns 1");
    CK(obs.create_n == 1 && obs.create_frames == 2,
       "create receives the DECLARED frame count from node+0x0c (0x28e620)");
    CK(alloc_bytes(611u) == 20u && tag_is(611u, EVENT_TIMELINE_SOURCE_TAG),
       "the timeline record is _calloc(1,20,Animation.c,611)");
    CK(alloc_bytes(615u) == 8u && alloc_bytes(616u) == 8u,
       "times and events are _calloc(declared,4,tag,615/616)");
    CK(obs.set_n == 0 && obs.ev_n == 0, "no frame -> no event, no setFrame");
    CK(a->timelineCount == 1 && a->timelines[0] == obs.timeline,
       "the zero-frame timeline is still published at the old cursor (0x28e750/0x28e754)");
    CK(bits(a->duration) == 0u,
       "duration reads times[declared-1] (zero) and keeps the initial 0.0f");
    pass("event_without_frames");
}

/* ================================================================== */
/* 3. absent int/float/string take the EventData defaults              */
/* ================================================================== */
static void frame_defaults_from_eventdata(void)
{
    ev_begin("frame_defaults_from_eventdata");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 7, 0.5f, "dflt");
    spEventShape *event;
    Json *events = events_node(1);
    Json *frame = node(0);

    attach_events(d, 1, &ed);
    add(frame, str_key("name", "hit"));
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "a one-frame hit returns 1");
    CK(obs.ev_n == 1 && obs.set_n == 1 && obs.set_index[0] == 0,
       "one event is created and published at index 0");
    event = (spEventShape *)obs.set_event[0];
    CK(event->data == ed, "the event points at the EventData the lookup returned");
    CK(event->intValue == 7,
       "an absent \"int\" takes the EventData +0x04 default (0x28e6b0)");
    CK(bits(event->floatValue) == 0x3f000000u,
       "an absent \"float\" takes the EventData +0x08 default (0x28e6c4)");
    CK(bits(event->time) == 0u,
       "an absent \"time\" yields the 0.0f default (0x28e690)");
    CK(event->stringValue != 0 && event->stringValue != ed->stringValue,
       "an absent \"string\" still produces a fresh copy of the EventData +0x0c value");
    CK(strcmp(event->stringValue, "dflt") == 0 && strlen(event->stringValue) == 4,
       "the copy holds the EventData string bytes, not a pointer");
    CK(alloc_count(494u) == 1 && alloc_bytes(494u) == 5u,
       "the line-494 request is strlen(default)+1 = 5");
    pass("frame_defaults_from_eventdata");
}

/* ================================================================== */
/* 4. all four keys present: exact field stores                        */
/* ================================================================== */
static void frame_all_keys(void)
{
    ev_begin("frame_all_keys");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, 0);
    spEventShape *event;
    Json *events = events_node(1);
    Json *frame = node(0);
    Json *strnode;

    attach_events(d, 1, &ed);
    add(frame, str_key("name", "hit"));
    add(frame, num_key("time", 1.5f));
    add(frame, int_key("int", -3));
    add(frame, num_key("float", 2.25f));
    add(frame, str_key("string", "boom"));
    strnode = frame->child->next->next->next->next;  /* the "string" member */
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "the all-keys frame returns 1");
    CK(obs.set_n == 1 && obs.set_time[0] == 0x3fc00000u,
       "setFrame receives the frame's \"time\" bits (1.5)");
    event = (spEventShape *)obs.set_event[0];
    CK(bits(event->time) == 0x3fc00000u,
       "event+0x04 = the frame time handed to spEvent_create (0x28e6ac)");
    CK(event->intValue == -3,
       "event+0x08 = Json_getInt \"int\" (0x28e6cc)");
    CK(bits(event->floatValue) == 0x40100000u,
       "event+0x0c = Json_getFloat \"float\" (0x28e6e0)");
    CK(event->stringValue != 0 && strcmp(strnode->string_value, "boom") == 0,
       "the frame's \"string\" member is the real Json string_value");
    CK(event->stringValue != strnode->string_value,
       "the line-494 copy is stored at event+0x10 and is NOT the Json pointer");
    CK(strcmp(event->stringValue, "boom") == 0 && strlen(event->stringValue) == 4,
       "the copy holds the exact bytes of the Json string");
    CK(alloc_bytes(494u) == 5u && tag_is(494u, SPINE_JSON_SOURCE_TAG),
       "the copy is strlen+1 bytes with the SkeletonJson.c tag");
    CK(alloc_slot(36u) >= 0 && alloc_slot(36u) < alloc_slot(494u),
       "spEvent_create's _calloc(1,20,line 36) happens before the line-494 copy");
    pass("frame_all_keys");
}

/* ================================================================== */
/* 5. the lookup is a linear strcmp scan over data->events             */
/* ================================================================== */
static void event_lookup_scan(void)
{
    ev_begin("event_lookup_scan");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *eds[3];
    spEventShape *event;
    Json *events = events_node(1);
    Json *frame = node(0);

    eds[0] = make_event_data("alpha", 1, 0.0f, 0);
    eds[1] = make_event_data("hit", 2, 0.0f, 0);
    eds[2] = make_event_data("zeta", 3, 0.0f, 0);
    attach_events(d, 3, eds);
    add(frame, str_key("name", "hit"));
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "a three-entry table still returns 1");
    CK(obs.find_n == 1 && obs.cmp_n == 2,
       "the scan strcmp's entries until the match (second entry, 0x28b1bc)");
    CK(obs.find_ret[0] == eds[1],
       "spSkeletonData_findEvent returns the matching EventData pointer");
    event = (spEventShape *)obs.set_event[0];
    CK(event->data == eds[1] && event->intValue == 2,
       "the event is built from that EventData's defaults");
    pass("event_lookup_scan");
}

/* ================================================================== */
/* 6. E5: "Event not found: " with a NULL setError json argument       */
/* ================================================================== */
static void event_not_found_e5(void)
{
    ev_begin("event_not_found_e5");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, 0);
    Json *root, *events, *frame;
    spEventTimelineShape *t;

    attach_events(d, 1, &ed);
    root = node(0);
    events = events_node(1);
    frame = node(0);
    add(frame, str_key("name", "ghost"));
    add(events, frame);
    add(root, events);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_ERROR,
       "a name miss leaves through E5 and returns 0 (the loader yields NULL)");
    CK(obs.set_n == 0 && obs.ev_n == 0,
       "no event is created and setFrame is never reached on the miss");
    CK(report_count == 1 && strcmp(report_format, "Spine Error:%s\n") == 0,
       "E5 reports through the real console vcall");
    CK(strcmp(reported, "Event not found: ghost") == 0,
       "E5 message is the exact literal plus the frame's \"name\"");
    CK(parser_obj.error != 0
       && strcmp((char *)(uintptr_t)parser_obj.error,
                 "Event not found: ghost") == 0,
       "E5 stores the formatted message in parser->error (line 90)");
    CK(free_hits(root) == 0 && free_hits(events) == 0 && free_hits(frame) == 0,
       "E5 passes NULL as the setError json argument: NO Json node is disposed");
    CK(free_hits(a) == 1 && free_slot(a) >= 0 && free_slot(d) > free_slot(a),
       "E5 disposes the animation BEFORE the skeleton data (0x28e7c4 then 0x28da48)");
    CK(free_hits(d) == 1, "E5 disposes the skeleton data exactly once");
    t = (spEventTimelineShape *)obs.timeline;
    CK(a->timelineCount == 0 && free_hits(t->times) == 0 && free_hits(t->events) == 0,
       "the created timeline is never published and its arrays leak (original has no _free)");
    pass("event_not_found_e5");
}

/* ================================================================== */
/* 7. open #7: event+0x10 is a distinct owned stringValue block        */
/* ================================================================== */
static void open7_string_copy_ownership(void)
{
    ev_begin("open7_string_copy_ownership");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, "dflt");
    spEventShape *event;
    Json *events = events_node(1);
    Json *frame = node(0);
    Json *strnode;
    void *block;

    attach_events(d, 1, &ed);
    add(frame, str_key("name", "hit"));
    add(frame, str_key("string", "frame-str"));
    strnode = frame->child->next;
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "the frame with its own string returns 1");
    event = (spEventShape *)obs.set_event[0];
    block = event->stringValue;
    CK(block != 0 && block != (void *)ed->stringValue,
       "event+0x10 is a NEW block, not the EventData +0x0c pointer");
    CK(block != (void *)strnode->string_value,
       "event+0x10 is not the Json string_value pointer either");
    CK(strcmp((char *)block, "frame-str") == 0 && strlen((char *)block) == 9,
       "the block holds the exact 9 bytes of the frame string");
    CK(alloc_count(494u) == 1 && alloc_bytes(494u) == 10u,
       "the line-494 request is strlen+1 = 10");

    /* What the timeline does at disposal time: spEvent_dispose(event), then
     * spEventData_dispose(eventData) when the skeleton data goes away. */
    spEvent_dispose(event);
    CK(free_hits(block) == 1,
       "spEvent_dispose frees event+0x10 exactly once (0x285b80)");
    CK(free_slot(event) == free_slot(block) + 1,
       "the self free follows the stringValue free (0x285b90 b _free)");
    CK(free_hits(event) == 1, "the event object itself is freed exactly once");
    spEventData_dispose((spEventData *)ed);
    CK(free_hits(ed->stringValue) == 1,
       "spEventData_dispose frees EventData+0x0c exactly once (line-1034 block)");
    CK(free_hits(block) == 1 && ed->stringValue != (char *)block,
       "the two blocks are distinct: no double free between spEvent and spEventData");
    pass("open7_string_copy_ownership");
}

/* ================================================================== */
/* 8. open #7 the other way: absent string + NULL EventData default    */
/* ================================================================== */
static void open7_null_string_no_copy(void)
{
    ev_begin("open7_null_string_no_copy");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, 0);
    spEventShape *event;
    Json *events = events_node(1);
    Json *frame = node(0);

    attach_events(d, 1, &ed);
    add(frame, str_key("name", "hit"));
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "a frame with no string and no EventData default returns 1");
    event = (spEventShape *)obs.set_event[0];
    CK(event->stringValue == 0,
       "event+0x10 stays zero from the _calloc when both strings are NULL (0x28e6f0)");
    CK(alloc_count(494u) == 0,
       "no line-494 allocation happens for a NULL string");
    spEvent_dispose(event);
    CK(free_hits(0) >= 1, "spEvent_dispose forwards the NULL string to _free");
    pass("open7_null_string_no_copy");
}

/* ================================================================== */
/* 9. two frames: cursor, per-frame events                             */
/* ================================================================== */
static void two_frames_cursor(void)
{
    ev_begin("two_frames_cursor");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, 0);
    spEventTimelineShape *t;
    Json *events = events_node(2);
    Json *f0 = node(0), *f1 = node(0);

    attach_events(d, 1, &ed);
    add(f0, str_key("name", "hit"));
    add(f0, num_key("time", 0.25f));
    add(f1, str_key("name", "hit"));
    add(f1, num_key("time", 0.75f));
    add(events, f0);
    add(events, f1);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "the two-frame run returns 1");
    CK(obs.set_n == 2 && obs.set_index[0] == 0 && obs.set_index[1] == 1,
       "frameIndex starts at 0 and increments once per frame (0x28e724)");
    CK(obs.set_time[0] == 0x3e800000u && obs.set_time[1] == 0x3f400000u,
       "each setFrame gets its own frame's time bits");
    CK(obs.set_event[0] != obs.set_event[1] && obs.ev_n == 2,
       "each frame allocates its own spEvent");
    t = (spEventTimelineShape *)obs.timeline;
    CK(t->events[0] == obs.set_event[0] && t->events[1] == obs.set_event[1],
       "setFrame stores the event pointers in the timeline's +0x10 array");
    CK(bits(t->times[0]) == 0x3e800000u && bits(t->times[1]) == 0x3f400000u,
       "setFrame copies the event time into times[] (0x282d38)");
    CK(bits(a->duration) == 0x3f400000u,
       "duration = the larger last-frame time (0.75)");
    pass("two_frames_cursor");
}

/* ================================================================== */
/* 10. the duration index is declared-1, and only a larger value wins  */
/* ================================================================== */
static void declared_vs_child_count(void)
{
    ev_begin("declared_vs_child_count");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    spEventDataEventShape *ed = make_event_data("hit", 0, 0.0f, 0);
    Json *events = events_node(3);       /* declares 3, carries 1 */
    Json *frame = node(0);
    Json *events2;
    Json *frame2;

    attach_events(d, 1, &ed);
    add(frame, str_key("name", "hit"));
    add(frame, num_key("time", 0.5f));
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_OK,
       "declared-three run returns 1");
    CK(obs.create_frames == 3 && obs.set_n == 1,
       "create still receives the declared count, the loop follows the child list");
    CK(bits(a->duration) == 0u,
       "duration reads times[declared-1] = times[2] (zero), not times[0] (0x28e75c/0x28e760)");

    events2 = events_node(1);
    frame2 = node(0);
    add(frame2, str_key("name", "hit"));
    add(frame2, num_key("time", 0.5f));
    add(events2, frame2);
    a->duration = 9.0f;
    CK(readSkeletonData_eventTimelines(events2, d, a, &parser_obj) == EVENT_TL_OK,
       "the second publish returns 1");
    CK(bits(a->duration) == 0x41100000u,
       "a larger existing duration is kept (vmovgt only on strictly greater)");
    CK(a->timelineCount == 2 && a->timelines[1] == obs.timeline,
       "the second timeline lands at cursor 1");
    pass("declared_vs_child_count");
}

/* ================================================================== */
/* 11. open #10: animationsCount first, element at the OLD cursor      */
/* ================================================================== */
static void publish_animation_order(void)
{
    ev_begin("publish_animation_order");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a1 = make_animation();
    spAnimationEventShape *a2 = make_animation();
    void **table = (void **)tl_zero(8u);

    d->animations = table;
    CK(d->animationsCount == 0, "the freshly calloc'd data starts with count 0");

    readSkeletonData_publishAnimation(d, a1);
    CK(d->animationsCount == 1,
       "animationsCount becomes old+1 (0x28e780/0x28e784)");
    CK(table[0] == (void *)a1,
       "the animation lands at the OLD cursor (0x28e78c uses r3 before the bump)");

    readSkeletonData_publishAnimation(d, a2);
    CK(d->animationsCount == 2 && table[1] == (void *)a2,
       "the second animation lands at cursor 1");
    CK(table[0] == (void *)a1 && table[1] != table[0],
       "the two published animations never share a slot");
    pass("publish_animation_order");
}

/* ================================================================== */
/* 12. B18: Json_dispose gets the ROOT tree and data comes back        */
/* ================================================================== */
static void finish_disposes_root(void)
{
    ev_begin("finish_disposes_root");
    spSkeletonDataEventShape *d = make_data();
    Json *root = node(0);
    Json *events = events_node(1);
    Json *frame = node(0);
    void *ret;

    add(frame, str_key("name", "hit"));
    add(events, frame);
    add(root, events);

    ret = readSkeletonData_finishAnimations(root, d);
    CK(ret == (void *)d, "B18 returns the skeleton data (0x28e7ac mov r0,r9)");
    CK(free_hits(root) == 1,
       "B18 disposes the ROOT Json tree from [sp+0x24] (0x28e7a4/0x28e7a8)");
    CK(free_hits(events) == 1 && free_hits(frame) == 1,
       "the events member and its frame are freed as root's descendants");
    CK(free_slot(frame) < free_slot(events) && free_slot(events) < free_slot(root),
       "Json_dispose releases children before their parent");
    CK(free_hits(d) == 0,
       "the returned skeleton data is NOT disposed here");
    pass("finish_disposes_root");
}

/* ================================================================== */
/* 13. lookup on an empty events table: the count<=0 guard             */
/* ================================================================== */
static void e5_empty_event_table(void)
{
    ev_begin("e5_empty_event_table");
    spSkeletonDataEventShape *d = make_data();
    spAnimationEventShape *a = make_animation();
    Json *events = events_node(1);
    Json *frame = node(0);

    d->eventsCount = 0;
    d->events = 0;
    add(frame, str_key("name", "any"));
    add(events, frame);

    CK(readSkeletonData_eventTimelines(events, d, a, &parser_obj) == EVENT_TL_ERROR,
       "an empty event table turns any name into E5");
    CK(obs.find_n == 1 && obs.find_ret[0] == 0 && obs.cmp_n == 0,
       "findEvent returns NULL without a single strcmp (count <= 0 guard, 0x28b190)");
    CK(strcmp(reported, "Event not found: any") == 0,
       "the message still carries the frame name");
    pass("e5_empty_event_table");
}

void _start(void)
{
    test = "startup"; init_heap(); fixture_install_error_reporter();
    event_absent();
    event_without_frames();
    frame_defaults_from_eventdata();
    frame_all_keys();
    event_lookup_scan();
    event_not_found_e5();
    open7_string_copy_ownership();
    open7_null_string_no_copy();
    declared_vs_child_count();
    two_frames_cursor();
    publish_animation_order();
    finish_disposes_root();
    e5_empty_event_table();
    out("SUMMARY all declared event timeline family contracts passed\n");
    quit(0);
}
