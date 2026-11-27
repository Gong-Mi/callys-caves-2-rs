/*
 * spine_read_tl_event.h — the event-timeline family (B16), its "Event not
 * found" error block (E5) and the animations-segment tail (B18) of
 * spSkeletonJson_readSkeletonData @0x28b84c (13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B16  0x28e614..0x28e7a4  400 B / 100 insns — the ""events"" node test, the
 *        spEventTimeline_create call, the per-frame body (findEvent by name,
 *        "time"/"int"/"float"/"string" keys, spEvent_create, the SECOND string
 *        copy at malloc line 494 into event+0x10, setFrame, frame advance,
 *        back edge 0x28e734), the timeline publish/duration tail
 *        (0x28e738..0x28e770) AND the per-animation publish pair
 *        (0x28e774..0x28e79c: animationsCount++ then animations[old]).
 *   E5   0x28e7b4..0x28e7f4   64 B /  16 insns — ""Event not found: "":
 *        spAnimation_dispose, Json_getString(frame,"name",NULL),
 *        setError(parser, NULL, msg, name), common tail 0x28da44
 *        (spSkeletonData_dispose, return NULL).  Entered only from
 *        0x28e6a0 `beq 0x28e7b4` (the findEvent miss).
 *   B18  0x28e7a4..0x28e7b4   16 B /   4 insns — ldr r0,[sp,#0x24] (the ROOT
 *        Json tree) ; Json_dispose ; mov r0,r9 (data) ; b 0x28bdcc (the
 *        function's shared return).  Reached by the B2 "no animations" edges
 *        (0x28d2a4/0x28d2d0 beq 0x28e7a4) and by fall-through from 0x28e7a0
 *        (outer animation loop exhausted).
 *
 * Evidence tier: bytecode_anchored.  The original was never executed and no
 * original-equivalence claim is made.  Every semantic statement in the .c
 * carries the address of the instruction it was read from; the key set
 * (""events""/""name""/""time""/""int""/""float""/""string"") is read from the
 * pc-relative literals at 0x357d94/0x330810/0x34c1d4/0x357e58/0x330828/0x330830,
 * never from a stock spine source.
 *
 * Real recovered bodies linked (not re-implemented here):
 *   Json_getItem/getString/getInt/getFloat      c/json_interface
 *   Json_dispose                                c/spine_json_support (B18)
 *   _spSkeletonJson_setError                    c/spine_json_error  (E5)
 *   spAnimation_dispose / spSkeletonData_dispose c/spine_skeleton_data (E5 tail)
 *   _malloc                                     c/spine_alloc (line 494)
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture reproduces
 * the disassembled bodies and records every argument):
 *   spSkeletonData_findEvent      0x28b180 / 92 B, linear strcmp scan over
 *        data->events (count +0x2c, array +0x30, name at event+0x00), NULL on
 *        miss.  No module owns 0x28b180 yet, so the fixture stands in with the
 *        exact body (see the header comment on the extern below).
 *   spEvent_create                0x285b44 / 52 B, _calloc(1,20,tag,36) with
 *        +0x00 = data, +0x04 = time; +0x08/+0x0c/+0x10 stay zero.
 *   spEvent_dispose               0x285b78 / 28 B, _free(+0x10) then _free(self).
 *   spEventTimeline_create        0x282c8c / 136 B, _calloc(1,20,tag,611),
 *        type 6, +0x08 frameCount, +0x0c times = _calloc(n,4,tag,615),
 *        +0x10 events = _calloc(n,4,tag,616).
 *   spEventTimeline_setFrame      0x282d14 / 56 B, times[i] = event->time
 *        (bits at event+0x04), _free(events[i]), events[i] = event.
 */
#ifndef YY_SPINE_READ_TL_EVENT_H
#define YY_SPINE_READ_TL_EVENT_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spSkeletonData (84 B, calloc(1,84,tag,37) at 0x28ade4) as seen by this
 * family.  Only the two vectors at +0x2c..+0x38 are read here:
 *   +0x2c eventsCount      read by spSkeletonData_findEvent 0x28b188
 *   +0x30 events array     read by spSkeletonData_findEvent 0x28b194
 *   +0x34 animationsCount  read 0x28e778, written 0x28e784
 *   +0x38 animations array read 0x28e77c, element written 0x28e78c
 * B1 (c/spine_read_animations) publishes +0x2c/+0x30; B2 publishes +0x38 only,
 * which is why +0x34 can still be zero on the first publish here.
 */
typedef struct spEventDataEventShape {
    char*    name;          /* +0x00 owned copy, EventData.c malloc line 37 */
    int32_t  intValue;      /* +0x04 default for a frame's ""int"" */
    float    floatValue;    /* +0x08 default for a frame's ""float"" */
    char*    stringValue;   /* +0x0c owned copy, SkeletonJson.c line 1034 */
} spEventDataEventShape;    /* 16 B */

typedef struct spSkeletonDataEventShape {
    uint32_t pad[11];                    /* +0x00..+0x28 */
    int32_t  eventsCount;                /* +0x2c */
    spEventDataEventShape** events;      /* +0x30 */
    int32_t  animationsCount;            /* +0x34 */
    void**   animations;                 /* +0x38 */
    uint32_t tail[6];                    /* +0x3c..+0x53, rest of the 84-B record */
} spSkeletonDataEventShape;              /* 84 B */

/*
 * spEvent, 20 B, from spEvent_create's _calloc(1,20,tag,36):
 *   +0x00 data         [0x285b68 str r5,[r0]]
 *   +0x04 time (float) [0x285b6c str r4,[r0,#0x4]]
 *   +0x08 intValue     [0x28e6cc str r0,[r4,#0x8]]
 *   +0x0c floatValue   [0x28e6e0 str r0,[r4,#0xc]]
 *   +0x10 stringValue  [0x28e710 str r0,[r4,#0x10]]  <-- census open #7
 * The five words are exhaustive (20 = 5*4), and create writes only the first
 * two; +0x08/+0x0c/+0x10 are zero from _calloc.  Therefore +0x10 is the ONLY
 * field left for the second copy — stringValue — and spEvent_dispose's
 * `ldr r0,[r0,#0x10] ; bl _free ; ... ; b _free` (self) is exactly the
 * destroy-[stringValue, self] pair.  Open #7 is closed by this trio.
 *
 * The runtime owner is _spEventTimeline_dispose 0x2813c0: it walks
 * frameCount (+0x08) and calls spEvent_dispose on every events[i]
 * (0x2813e8 bl 0x285b78), then frees the events array (+0x10) and times
 * (+0x0c).  One spEvent_dispose per event => one free of the line-494 block.
 * (No NULL guard there: a declared count above the number of parsed frames
 * leaves NULL slots and the original would fault — recorded, not driven.)
 */
typedef struct spEventShape {
    const void* data;        /* +0x00 spEventData* */
    float       time;        /* +0x04 */
    int32_t     intValue;    /* +0x08 */
    float       floatValue;  /* +0x0c */
    char*       stringValue; /* +0x10 owned copy, SkeletonJson.c line 494 */
} spEventShape;              /* 20 B */

/*
 * spEventTimeline, 20 B, from spEventTimeline_create (0x282c8c):
 *   +0x00 type        [_spTimeline_init(t,6,...) 0x282cb8 mov r1,#6]
 *   +0x04 vtable      [0x282cc8]
 *   +0x08 frameCount  [0x282cd0 str r5,[r4,#0x8]]
 *   +0x0c float* times[_calloc(n,4,tag,615) 0x282ce0 -> 0x282cf0]
 *   +0x10 spEvent** events [_calloc(n,4,tag,616) 0x282cf8 -> 0x282cfc]
 * B16's publish tail indexes times with the DECLARED count:
 *   0x28e758 ldr r3,[r6,#0xc] ; 0x28e75c add r3,r3,r2,lsl#2 ; 0x28e760 vldr.
 */
typedef struct spEventTimelineShape {
    uint32_t       type;        /* +0x00 = 6 */
    void*          vtable;      /* +0x04 */
    int32_t        frameCount;  /* +0x08 */
    float*         times;       /* +0x0c */
    spEventShape** events;      /* +0x10 */
} spEventTimelineShape;         /* 20 B */

/* spAnimation fields touched by the two publish tails (+4 duration, +8 count,
 * +0xc array; name at +0 is not read here).  The full record belongs to
 * spAnimation_create / spAnimation_dispose (c/spine_read_animations,
 * c/spine_skeleton_data). */
typedef struct spAnimationEventShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationEventShape;     /* 16 B */

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(sizeof(spSkeletonDataEventShape) == 84,
               "0x28ade4 _calloc(1,84,tag,37)");
_Static_assert(offsetof(spSkeletonDataEventShape, eventsCount) == 0x2c,
               "0x28b188 ldr r7,[r0,#0x2c] / 0x28d1c0 str r0,[r9,#0x2c]");
_Static_assert(offsetof(spSkeletonDataEventShape, events) == 0x30,
               "0x28b194 ldr r6,[r0,#0x30] / 0x28d1d8 str r0,[r9,#0x30]");
_Static_assert(offsetof(spSkeletonDataEventShape, animationsCount) == 0x34,
               "0x28e778 ldr r3,[r0,#0x34] ; 0x28e784 str r1,[r0,#0x34]");
_Static_assert(offsetof(spSkeletonDataEventShape, animations) == 0x38,
               "0x28e77c ldr r2,[r0,#0x38] ; 0x28e78c str r11,[r2,r3,lsl#2]");
_Static_assert(sizeof(spEventDataEventShape) == 16,
               "0x285ba4 _calloc(1,16,tag,36) in spEventData_create");
_Static_assert(offsetof(spEventDataEventShape, intValue) == 0x04,
               "0x28e6b0 ldr r2,[r8,#0x4] (default for the frame's int)");
_Static_assert(offsetof(spEventDataEventShape, floatValue) == 0x08,
               "0x28e6c4 ldr r2,[r8,#0x8] (default for the frame's float)");
_Static_assert(offsetof(spEventDataEventShape, stringValue) == 0x0c,
               "0x28e6dc ldr r2,[r8,#0xc] (default for the frame's string)");
_Static_assert(sizeof(spEventShape) == 20,
               "0x285b58 mov r3,#36 ; 0x285b5c mov r1,#20 ; bl _calloc");
_Static_assert(offsetof(spEventShape, data) == 0x00, "0x285b68 str r5,[r0]");
_Static_assert(offsetof(spEventShape, time) == 0x04, "0x285b6c str r4,[r0,#0x4]");
_Static_assert(offsetof(spEventShape, intValue) == 0x08, "0x28e6cc str r0,[r4,#0x8]");
_Static_assert(offsetof(spEventShape, floatValue) == 0x0c, "0x28e6e0 str r0,[r4,#0xc]");
_Static_assert(offsetof(spEventShape, stringValue) == 0x10, "0x28e710 str r0,[r4,#0x10]");
_Static_assert(sizeof(spEventTimelineShape) == 20,
               "0x282c90 mov r1,#20 ; bl _calloc(1,20,tag,611)");
_Static_assert(offsetof(spEventTimelineShape, frameCount) == 0x08,
               "0x282cd0 str r5,[r4,#0x8]");
_Static_assert(offsetof(spEventTimelineShape, times) == 0x0c,
               "0x282cf0 str r0,[r4,#0xc] / 0x28e758 ldr r3,[r6,#0xc]");
_Static_assert(offsetof(spEventTimelineShape, events) == 0x10,
               "0x282cfc str r0,[r4,#0x10]");
_Static_assert(offsetof(spAnimationEventShape, duration) == 0x04,
               "0x28e73c vldr s14,[r11,#4] ; 0x28e770 vstr s15,[r11,#4]");
_Static_assert(offsetof(spAnimationEventShape, timelineCount) == 0x08,
               "0x28e740 ldr r3,[r11,#0x8] ; 0x28e750 str r0,[r11,#0x8]");
_Static_assert(offsetof(spAnimationEventShape, timelines) == 0x0c,
               "0x28e744 ldr r1,[r11,#0xc] ; 0x28e754 str r6,[r1,r3,lsl#2]");
#endif

/* Malloc tag at 0x357b08, resolved at 0x28e6f8 -> add pc -> 0x28e700. */
#define SPINE_JSON_SOURCE_TAG \
    "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* Malloc line read off 0x28e6fc `movw r2,#0x1ee` = 494. */
#define EVENT_LINE_STRING 494u

/* Malloc tag of EventData.c (0x3577d4) / Event.c (0x3577a0), used by the
 * synthetic creators' _calloc so the fixture's roster matches the original
 * allocation sites (lines 37 and 36 respectively). */
#define EVENTDATA_SOURCE_TAG \
    "jni/../jni/yoyo/../../../spine-c/src/spine/EventData.c"
#define EVENT_SOURCE_TAG \
    "jni/../jni/yoyo/../../../spine-c/src/spine/Event.c"

/*
 * spSkeletonData_findEvent — original 0x28b180 / 92 B, NOT recovered by this
 * batch (no module owns it).  Exact body, instruction for instruction:
 *   0x28b188 ldr r7,[r0,#0x2c]   count
 *   0x28b18c cmp r7,#0 ; 0x28b190 ble -> NULL
 *   0x28b194 ldr r6,[r0,#0x30]   array
 *   0x28b198 mov r4,#0 ; 0x28b19c sub r6,r6,#4
 *   0x28b1ac ldr r5,[r6,#0x4]!   ev = *++p
 *   0x28b1b4 add r4,r4,#1        i++ BEFORE the compare
 *   0x28b1b8 ldr r0,[r5]         ev->name (+0x00)
 *   0x28b1bc bl strcmp
 *   0x28b1c4 bne -> 0x28b1a4 (cmp i,count ; beq NULL)
 *   returns ev on equality, NULL otherwise.
 * The fixture provides this body (an argument-recording copy) until a module
 * claims 0x28b180; the checker pins its words in the original.
 */
extern void* spSkeletonData_findEvent(void* data_raw, const char* name);

/* Declared synthetic boundaries — see the block comment. */
extern void* spEvent_create(float time, const void* data);
extern void  spEvent_dispose(void* event);
extern void* spEventTimeline_create(int frameCount);
extern void  spEventTimeline_setFrame(void* timeline, int frameIndex,
                                      void* event);

/* Driver return codes.  Exactly three exits exist from this family:
 *   OK      -> 0x28e774 (events node absent) or the publish tail's fall-through
 *   ERROR   -> E5's `b 0x28da44` (return NULL from the loader)
 *   HANDOFF -> the frame body's `beq 0x28e7b4`, consumed by the driver itself
 *              (E5 lives in this module, so the handoff never escapes it) */
#define EVENT_TL_OK        1
#define EVENT_TL_ERROR     0
#define EVENT_TL_HANDOFF_EVENT_NOT_FOUND 2

/*
 * One frame, 0x28e674..0x28e734 (loop head 0x28e674, back edge 0x28e734).
 * Pointers into the frame are re-read on every call; the key literals were
 * cached by the original in r7 ("name"), r9 ("int") and [sp+0x28]/[sp+0x2c]/
 * [sp+0x30] ("time"/"float"/"string") at 0x28e63c..0x28e670, outside the loop.
 *
 *   findEvent(data, Json_getString(frame,"name",NULL))   0x28e674..0x28e68c
 *     miss -> return EVENT_TL_HANDOFF_EVENT_NOT_FOUND     0x28e6a0 beq
 *   time = Json_getFloat(frame,"time",0.0f)              0x28e690..0x28e6a4
 *   event = spEvent_create(time, eventData)              0x28e6a8/0x28e6ac
 *   event->intValue   = Json_getInt  (...,"int",   ed->intValue)   0x28e6b0..0x28e6cc
 *   event->floatValue = Json_getFloat(...,"float", ed->floatValue) 0x28e6c4..0x28e6e0
 *   s = Json_getString(frame,"string", ed->stringValue)  0x28e6d8..0x28e6e8
 *   if (s != NULL) {                                     0x28e6ec/0x28e6f0
 *       n = strlen(s);                                   0x28e6f4
 *       p = _malloc(n+1, SkeletonJson.c, 494);           0x28e6fc/0x28e700/0x28e704/0x28e708
 *       event->stringValue = p;                          0x28e710
 *       strcpy(p, s);                                    0x28e70c/0x28e714
 *   }
 *   spEventTimeline_setFrame(t, frameIndex, event);      0x28e718..0x28e728
 *   *out_event = event (fixture observation only)         (no original store)
 *
 * The copy is UNCONDITIONAL on s != NULL, whatever produced s: a JSON member
 * value or the EventData default.  That is the whole answer to open #7 — no
 * alias to eventData->stringValue can survive, so spEvent_dispose's free of
 * event+0x10 can never double-free with spEventData_dispose's free of
 * eventData+0x0c.
 */
int readSkeletonData_eventFrame(Json* frame, void* data_raw, void* timeline_raw,
                                int32_t frame_index, void** out_event);

/*
 * The frame-list loop, 0x28e628..0x28e734: frame = events_node->child
 * (0x28e62c), NULL -> OK (0x28e630/0x28e638 beq 0x28e738), frameIndex = 0
 * (0x28e640), one readSkeletonData_eventFrame per frame, ++frameIndex
 * (0x28e724), frame = frame->next (0x28e72c), back edge 0x28e734.
 * On a miss the E5 block is run with the FAILING frame (0x28e7b4) and ERROR is
 * returned; the timeline created by the driver is never published and its two
 * calloc'd arrays leak, exactly as in the original.
 */
int readSkeletonData_eventTimelineFrames(Json* events_json, void* data_raw,
                                         void* animation_raw, void* parser_raw,
                                         void* timeline_raw);

/*
 * B16 driver, 0x28e614..0x28e770:
 *   events_json == NULL -> OK and NOTHING is created (0x28e614..0x28e61c; the
 *        original jumps straight to 0x28e774, the animation publish, which is
 *        the caller's job here).
 *   timeline = spEventTimeline_create(events_json->unk_0c)  (declared count,
 *        0x28e620/0x28e624; the handle survives in r6).
 *   frame loop (above), then the publish/duration tail:
 *        count     = animation->timelineCount   0x28e740
 *        timelines = animation->timelines       0x28e744
 *        declared  = events_json->unk_0c        0x28e748
 *        duration  = animation->duration        0x28e73c
 *        animation->timelineCount = count + 1   0x28e74c/0x28e750 (stored FIRST)
 *        timelines[count] = timeline            0x28e754 (OLD cursor)
 *        last      = timeline->times[declared-1] 0x28e758..0x28e760 (4-byte stride)
 *        animation->duration = (duration > last) ? duration : last
 *                                               0x28e764..0x28e770
 *   This runs for a zero-frame "events" node too (0x28e638 beq 0x28e738).
 */
int readSkeletonData_eventTimelines(Json* events_json, void* data_raw,
                                    void* animation_raw, void* parser_raw);

/*
 * The per-animation publish pair, 0x28e774..0x28e79c (census open #10):
 *   r0 = data ; r3 = data->animationsCount (+0x34) ; r2 = data->animations (+0x38)
 *   0x28e780 add r1,r3,#1
 *   0x28e784 str r1,[r0,#0x34]      count = old + 1     <-- FIRST
 *   0x28e788 ldr r1,[sp,#0x1c]      (outer cursor reload)
 *   0x28e78c str r11,[r2,r3,lsl#2]  animations[OLD count] = animation
 * The element index is the PRE-increment count.  The loop cursor advance and
 * `bne 0x28d318` (0x28e790..0x28e79c) belong to the outer animation loop and
 * are not part of this write pair.
 */
void readSkeletonData_publishAnimation(void* data_raw, void* animation_raw);

/*
 * B18, 0x28e7a4..0x28e7b4:
 *   0x28e7a0 mov r9,r0              data survives (r0 = [sp,#0x18] at 0x28e774)
 *   0x28e7a4 ldr r0,[sp,#0x24]      the ROOT Json tree (Json_create result,
 *                                   stored at 0x28b8ac), not the events node
 *   0x28e7a8 bl Json_dispose        real body in c/spine_json_support
 *   0x28e7ac mov r0,r9              return value = data
 *   0x28e7b0 b 0x28bdcc             the loader's shared epilogue
 * Returns data_raw.
 */
void* readSkeletonData_finishAnimations(Json* root, void* data_raw);

/*
 * E5, 0x28e7b4..0x28e7f0 plus the common tail 0x28da44..0x28da50:
 * "Event not found: ".
 *   0x28e7b4 mov r4,r8              r8 == 0: 0x28e698 subs r8,r0,#0 ;
 *                                   0x28e6a0 beq is the only edge here
 *   0x28e7b8 mov r0,r11             animation
 *   0x28e7bc ldr r8,[sp,#0x20]      parser
 *   0x28e7c0 ldr r9,[sp,#0x18]      data
 *   0x28e7c4 bl spAnimation_dispose animation FIRST
 *   0x28e7c8..0x28e7d4 Json_getString(frame,"name",NULL) — the name is re-read
 *                                    after the dispose, with a NULL default
 *   0x28e7d8 ldr r2,[pc,#0x320] -> 0x357f5c "Event not found: "
 *   0x28e7dc mov r1,r4              JSON ARGUMENT = NULL (r4 = r8 = 0), so
 *                                   setError disposes no Json node
 *   0x28e7e4 mov r3,r0              extra = the frame's "name"
 *   0x28e7ec bl _spSkeletonJson_setError
 *   0x28e7f0 b 0x28da44             spSkeletonData_dispose(data) ; return NULL
 * Returns EVENT_TL_ERROR.
 */
int readSkeletonData_eventNotFound(Json* frame, void* data_raw,
                                   void* animation_raw, void* parser_raw);

#endif /* YY_SPINE_READ_TL_EVENT_H */
