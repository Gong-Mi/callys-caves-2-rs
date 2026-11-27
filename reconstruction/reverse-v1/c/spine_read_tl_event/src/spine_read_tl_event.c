/*
 * spine_read_tl_event.c — event-timeline family (B16), "Event not found"
 * (E5) and the animations-segment tail (B18) of
 * spSkeletonJson_readSkeletonData @0x28b84c, libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B16   0x28e614..0x28e7a4  (100 insns)  ""events"" node test, create,
 *                                          per-frame findEvent + event build
 *                                          + line-494 name copy + setFrame,
 *                                          timeline publish/duration, and the
 *                                          animationsCount/array publish.
 *   E5    0x28e7b4..0x28e7f4  ( 16 insns)  ""Event not found: "", NULL json.
 *   B18   0x28e7a4..0x28e7b4  (  4 insns)  Json_dispose(ROOT) ; return data.
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted — keys, field offsets, the malloc line and both
 * publish orders are read off the instruction stream (census §2.8 / §3.1 /
 * §5.4 / §6 / §7 open #7 and #10).  PASS on this file is acceptance of the
 * reconstructed C, never an original-equivalence claim.
 */

#include "spine_read_tl_event.h"

#include "../../spine_json_error/src/spine_json_error.h"    /* setError 0x28b784 */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h" /* dispose pair */

/* 0x28e7d8 ldr r2,[pc,#0x320] -> pool 0x28eb00 -> va 0x357f5c. */
#define ERR_EVENT_NOT_FOUND "Event not found: "

/* libc imports of the original: 0xb6538 strlen@plt, 0xb65a4 strcpy@plt. */
extern size_t strlen(const char* s);
extern char* strcpy(char* dst, const char* src);

/*
 * ---------------------------------------------------------------------------
 * One frame: 0x28e674..0x28e734.
 *
 * Register map read off the block: r10 = frame, r11 = animation (not used
 * here), r6 = timeline, r5 = frameIndex, r8 = spEventData* then reused for
 * the Json_getString("string") result, r4 = the spEvent*, r7/r9 and
 * [sp+0x28]/[sp+0x2c]/[sp+0x30] = the cached key literals.
 *
 *   0x28e674 mov r2,#0 ; 0x28e678 mov r1,r7 ; 0x28e67c mov r0,r10
 *   0x28e680 bl Json_getString(frame,"name",NULL)
 *   0x28e684 mov r1,r0 ; 0x28e688 ldr r0,[sp,#0x18](data)
 *   0x28e68c bl spSkeletonData_findEvent(data,name)
 *   0x28e690 mov r2,#0 ; 0x28e694 ldr r1,[sp,#0x28]("time")
 *   0x28e698 subs r8,r0,#0
 *   0x28e69c mov r0,r10
 *   0x28e6a0 beq 0x28e7b4            -> E5 (r8 == 0)
 *   0x28e6a4 bl Json_getFloat(frame,"time",0.0f)
 *   0x28e6a8 mov r1,r8 ; 0x28e6ac bl spEvent_create(time,eventData)
 *   0x28e6b0 ldr r2,[r8,#0x4]        default int from the EventData
 *   0x28e6b4 mov r1,r9("int") ; 0x28e6b8 mov r4,r0 ; 0x28e6bc mov r0,r10
 *   0x28e6c0 bl Json_getInt
 *   0x28e6c4 ldr r2,[r8,#0x8]        default float from the EventData
 *   0x28e6c8 ldr r1,[sp,#0x2c]("float")
 *   0x28e6cc str r0,[r4,#0x8]        event->intValue
 *   0x28e6d0 mov r0,r10 ; 0x28e6d4 bl Json_getFloat
 *   0x28e6d8 ldr r2,[r8,#0xc]        default string from the EventData
 *   0x28e6dc ldr r1,[sp,#0x30]("string")
 *   0x28e6e0 str r0,[r4,#0xc]        event->floatValue
 *   0x28e6e4 mov r0,r10 ; 0x28e6e8 bl Json_getString
 *   0x28e6ec subs r8,r0,#0
 *   0x28e6f0 beq 0x28e718            no string at all -> leave +0x10 zero
 *   0x28e6f4 bl strlen
 *   0x28e6f8 ldr r1,[pc,#0x3fc] -> pool 0x28eafc -> SkeletonJson.c tag
 *   0x28e6fc movw r2,#0x1ee        line 494
 *   0x28e700 add r1,pc,r1
 *   0x28e704 add r0,r0,#1          len + 1
 *   0x28e708 bl _malloc
 *   0x28e70c mov r1,r8              source
 *   0x28e710 str r0,[r4,#0x10]      event->stringValue = the new block
 *   0x28e714 bl strcpy
 *   0x28e718 mov r1,r5              frameIndex
 *   0x28e71c mov r2,r4              the event
 *   0x28e720 mov r0,r6              the timeline
 *   0x28e724 add r5,r5,#1           frameIndex++ (after the argument staging)
 *   0x28e728 bl spEventTimeline_setFrame
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_eventFrame(Json* frame, void* data_raw, void* timeline_raw,
                            int32_t frame_index, void** out_event)
{
    spEventDataEventShape* event_data;
    spEventShape* event;
    const char* value;
    float time;

    /* 0x28e674..0x28e68c: Json_getString "name" with a NULL default, then the
     * linear scan over data->events (spSkeletonData_findEvent 0x28b180). */
    event_data = (spEventDataEventShape*)spSkeletonData_findEvent(
        data_raw, Json_getString(frame, "name", 0));

    if (event_data == 0)                               /* 0x28e698 / 0x28e6a0 */
        return EVENT_TL_HANDOFF_EVENT_NOT_FOUND;

    time = Json_getFloat(frame, "time", 0.0f);         /* 0x28e690/0x28e694/0x28e6a4 */

    /* 0x28e6a8/0x28e6ac: spEvent_create(time, eventData) — the event's +0x04
     * is the frame time; +0x08/+0x0c/+0x10 are zeroed by its _calloc(1,20). */
    event = (spEventShape*)spEvent_create(time, event_data);

    /* 0x28e6b0..0x28e6cc: the DEFAULT comes from the EventData (+0x04), and
     * the store happens before the next Json call. */
    event->intValue = Json_getInt(frame, "int", event_data->intValue);

    /* 0x28e6c4..0x28e6e0: default from EventData +0x08, store to event +0x0c. */
    event->floatValue = Json_getFloat(frame, "float", event_data->floatValue);

    /* 0x28e6d8/0x28e6dc/0x28e6e4/0x28e6e8: default = EventData's OWN string
     * (+0x0c), which B1 allocated at line 1034. */
    value = Json_getString(frame, "string", event_data->stringValue);

    if (value != 0) {                                  /* 0x28e6ec / 0x28e6f0 */
        uint32_t length = (uint32_t)strlen(value);     /* 0x28e6f4 */
        /* 0x28e6fc..0x28e708: _malloc(strlen(s)+1, SkeletonJson.c, 494).
         * Census open #7: this SECOND copy goes to event+0x10, which is
         * spEvent.stringValue (the only word left in a 20-byte record whose
         * +0/+4 are written by create and whose +8/+0xc are written just
         * above).  It is taken whenever s != NULL, so it also covers the
         * EventData default — event+0x10 can never alias eventData+0x0c. */
        char* copy = (char*)_malloc(length + 1u, SPINE_JSON_SOURCE_TAG,
                                    EVENT_LINE_STRING);
        event->stringValue = copy;                     /* 0x28e710 */
        strcpy(copy, value);                           /* 0x28e70c/0x28e714 */
    }

    /* 0x28e718..0x28e728: setFrame(timeline, frameIndex, event).  The event
     * pointer is stored in timeline->events[frameIndex]; the timeline owns it
     * from here on (spEventTimeline_setFrame keeps the pointer, 0x282d44) and
     * later hands it to spEvent_dispose from _spEventTimeline_dispose
     * (0x2813c0 loop, 0x2813e8 bl 0x285b78), which is the single free of the
     * line-494 block and of the event itself. */
    spEventTimeline_setFrame(timeline_raw, frame_index, event);

    if (out_event != 0)                                /* fixture observation */
        *out_event = event;
    return EVENT_TL_OK;
}

/*
 * ---------------------------------------------------------------------------
 * Frame-list loop, 0x28e628..0x28e734.
 *
 *   0x28e628 ldr r3,[sp,#0x4c]     the "events" node
 *   0x28e62c ldr r10,[r3,#0x4]     frame = node->child
 *   0x28e630 cmp r10,#0 ; 0x28e634 mov r6,r0 ; 0x28e638 beq 0x28e738
 *   0x28e640 mov r5,#0             frameIndex = 0
 *   (frame body)
 *   0x28e72c ldr r10,[r10]         frame = frame->next
 *   0x28e730 cmp r10,#0 ; 0x28e734 bne 0x28e674
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_eventTimelineFrames(Json* events_json, void* data_raw,
                                     void* animation_raw, void* parser_raw,
                                     void* timeline_raw)
{
    Json* frame = events_json->child;                  /* 0x28e62c */
    int32_t frame_index;

    if (frame == 0)                                    /* 0x28e630/0x28e638 */
        return EVENT_TL_OK;

    frame_index = 0;                                   /* 0x28e640 */
    do {
        int rc = readSkeletonData_eventFrame(frame, data_raw, timeline_raw,
                                             frame_index, 0);
        if (rc != EVENT_TL_OK) {                       /* 0x28e6a0 beq 0x28e7b4 */
            /* E5 is cold code at 0x28e7b4 and never returns to the loop; it
             * disposes the animation and the whole data and reports. */
            (void)readSkeletonData_eventNotFound(frame, data_raw, animation_raw,
                                                 parser_raw);
            return EVENT_TL_ERROR;
        }
        ++frame_index;                                 /* 0x28e724 */
        frame = frame->next;                           /* 0x28e72c */
    } while (frame != 0);                              /* 0x28e730/0x28e734 */

    return EVENT_TL_OK;
}

/*
 * ---------------------------------------------------------------------------
 * B16 driver: 0x28e614..0x28e624 (node test + create), the frame loop, then
 * the publish/duration tail 0x28e738..0x28e770.
 *
 *   0x28e614 ldr r2,[sp,#0x4c]
 *   0x28e618 cmp r2,#0 ; 0x28e61c beq 0x28e774   absent -> animation publish
 *   0x28e620 ldr r0,[r2,#0xc]                    DECLARED frame count
 *   0x28e624 bl spEventTimeline_create
 *   0x28e634 mov r6,r0                           the handle
 *   (frame loop)
 *   0x28e738 ldr r0,[sp,#0x4c]
 *   0x28e73c vldr s14,[r11,#4]                   animation->duration
 *   0x28e740 ldr r3,[r11,#0x8]                   timelineCount
 *   0x28e744 ldr r1,[r11,#0xc]                   timelines
 *   0x28e748 ldr r2,[r0,#0xc]                    declared count
 *   0x28e74c add r0,r3,#1
 *   0x28e750 str r0,[r11,#0x8]                   count = old + 1  (FIRST)
 *   0x28e754 str r6,[r1,r3,lsl#2]                timelines[OLD count]
 *   0x28e758 ldr r3,[r6,#0xc]                    timeline->times
 *   0x28e75c add r3,r3,r2,lsl#2                  + declared*4 (FOUR-byte stride)
 *   0x28e760 vldr s15,[r3,#-4]                   times[declared-1]
 *   0x28e764 vcmpe.f32 s14,s15
 *   0x28e768 vmrs APSR_nzcv,fpscr
 *   0x28e76c vmovgt.f32 s15,s14
 *   0x28e770 vstr s15,[r11,#4]                   duration = max(duration,last)
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_eventTimelines(Json* events_json, void* data_raw,
                                void* animation_raw, void* parser_raw)
{
    spAnimationEventShape* animation = (spAnimationEventShape*)animation_raw;
    spEventTimelineShape* timeline;
    int rc;

    if (events_json == 0)                              /* 0x28e614..0x28e61c */
        return EVENT_TL_OK;

    /* 0x28e620/0x28e624: the one argument is the node's +0x0c, the DECLARED
     * frame count (the loop follows the child list instead). */
    timeline = (spEventTimelineShape*)spEventTimeline_create(
        (int)events_json->unk_0c);

    /* 0x28e628..0x28e734.  A zero-frame node returns OK here and still runs
     * the publish tail below (0x28e638 beq 0x28e738). */
    rc = readSkeletonData_eventTimelineFrames(events_json, data_raw,
                                              animation_raw, parser_raw,
                                              (void*)timeline);
    if (rc != EVENT_TL_OK)
        return rc;                                     /* E5 already ran */

    {
        int32_t count = animation->timelineCount;      /* 0x28e740 */
        void** timelines = animation->timelines;       /* 0x28e744 */
        uint32_t declared = events_json->unk_0c;       /* 0x28e748 */
        float duration = animation->duration;          /* 0x28e73c */
        float last;

        animation->timelineCount = count + 1;          /* 0x28e74c/0x28e750 */
        timelines[count] = (void*)timeline;            /* 0x28e754 (old cursor) */

        /* 0x28e758..0x28e760.  declared == 0 wraps to times[0xffffffff]; the
         * original indexes it blindly and the fixture never drives it. */
        last = timeline->times[declared - 1u];

        /* 0x28e764..0x28e770: vmovgt only on strictly-greater, so a NaN on
         * either side keeps `last` — same shape as the drawOrder tail. */
        animation->duration = (duration > last) ? duration : last;
    }

    return EVENT_TL_OK;
}

/*
 * ---------------------------------------------------------------------------
 * 0x28e774..0x28e79c — the per-animation publish pair (open #10).
 *
 *   0x28e774 ldr r0,[sp,#0x18]     data
 *   0x28e778 ldr r3,[r0,#0x34]     animationsCount
 *   0x28e77c ldr r2,[r0,#0x38]     animations array
 *   0x28e780 add r1,r3,#1
 *   0x28e784 str r1,[r0,#0x34]     count := old + 1          <-- stored FIRST
 *   0x28e788 ldr r1,[sp,#0x1c]     (outer animation cursor; not used here)
 *   0x28e78c str r11,[r2,r3,lsl#2] animations[old] = animation   <-- then publish
 *   0x28e790 ldr r1,[r1] ; 0x28e794 cmp r1,#0 ; 0x28e798 str r1,[sp,#0x1c] ;
 *   0x28e79c bne 0x28d318          the outer loop, owned by B2/B3's module.
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_publishAnimation(void* data_raw, void* animation_raw)
{
    spSkeletonDataEventShape* data = (spSkeletonDataEventShape*)data_raw;
    int32_t count = data->animationsCount;             /* 0x28e778 */
    void** table = data->animations;                   /* 0x28e77c */

    data->animationsCount = count + 1;                 /* 0x28e780/0x28e784 */
    table[count] = animation_raw;                      /* 0x28e78c */
}

/*
 * ---------------------------------------------------------------------------
 * E5, 0x28e7b4..0x28e7f0 plus the common tail 0x28da44..0x28da50.
 *
 *   0x28e7b4 mov r4,r8              r8 == 0 (only entry: 0x28e6a0 beq)
 *   0x28e7b8 mov r0,r11             animation
 *   0x28e7bc ldr r8,[sp,#0x20]      parser
 *   0x28e7c0 ldr r9,[sp,#0x18]      data
 *   0x28e7c4 bl spAnimation_dispose ANIMATION FIRST — before the name re-read
 *   0x28e7c8 mov r1,r7("name") ; 0x28e7cc mov r2,r4(NULL) ; 0x28e7d0 mov r0,r10
 *   0x28e7d4 bl Json_getString(frame,"name",NULL)
 *   0x28e7d8 ldr r2,[pc,#0x320] -> 0x357f5c
 *   0x28e7dc mov r1,r4              json argument = NULL
 *   0x28e7e0 add r2,pc,r2
 *   0x28e7e4 mov r3,r0              extra = the frame name
 *   0x28e7e8 mov r0,r8              parser
 *   0x28e7ec bl _spSkeletonJson_setError
 *   0x28e7f0 b 0x28da44             -> 0x28da48 spSkeletonData_dispose(data)
 *                                     0x28da4c mov r0,#0 ; b 0x28bdcc
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_eventNotFound(Json* frame, void* data_raw,
                               void* animation_raw, void* parser_raw)
{
    const char* name;

    spAnimation_dispose((spAnimation*)animation_raw);  /* 0x28e7c4 */

    /* 0x28e7c8..0x28e7d4: the name is re-read from the frame with a NULL
     * default (r2 = r4 = 0), after the animation was disposed. */
    name = Json_getString(frame, "name", 0);

    /* 0x28e7d8..0x28e7ec.  The json argument is NULL: r4 was loaded from r8,
     * which the miss edge proved zero.  This is NOT the root tree (the slot
     * family's shape) and NOT the animation node (the bones family's shape). */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             0,                        /* 0x28e7dc */
                             ERR_EVENT_NOT_FOUND,      /* 0x28e7d8/0x28e7e0 */
                             name);                    /* 0x28e7e4 */

    spSkeletonData_dispose((spSkeletonData*)data_raw); /* 0x28da48 */
    return EVENT_TL_ERROR;                             /* 0x28da4c/0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * B18, 0x28e7a4..0x28e7b4.
 *
 *   0x28e7a0 mov r9,r0              data (r0 = [sp,#0x18] since 0x28e774)
 *   0x28e7a4 ldr r0,[sp,#0x24]      the ROOT tree from Json_create (0x28b8ac)
 *   0x28e7a8 bl Json_dispose
 *   0x28e7ac mov r0,r9
 *   0x28e7b0 b 0x28bdcc             shared epilogue; returns r0 = data
 *
 * Why the root and not the events node: every timeline string was copied out
 * of the tree (event->stringValue at line 494, EventData->name/string at lines
 * 37/1034 in B1), so disposing the whole parse tree here leaves the returned
 * data self-contained.  That is also why the line-494 copy is mandatory.
 * ---------------------------------------------------------------------------
 */
void*
readSkeletonData_finishAnimations(Json* root, void* data_raw)
{
    Json_dispose(root);                                /* 0x28e7a4/0x28e7a8 */
    return data_raw;                                   /* 0x28e7ac/0x28e7b0 */
}
