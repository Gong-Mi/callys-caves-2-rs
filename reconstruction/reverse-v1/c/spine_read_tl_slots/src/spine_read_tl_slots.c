/*
 * spine_read_tl_slots.c — slots timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B5   0x28d4ec..0x28d640   85 insns  slots loop + dispatch + attachment
 *   B8   0x28d8dc..0x28d9d4   62 insns  color timeline frames (hex channel)
 *   B8b  0x28d9d4..0x28da18   17 insns  color publish/duration tail
 *   E1   0x28da18..0x28da54   15 insns  "Invalid timeline type for a slot: "
 *
 * Evidence tier: bytecode_anchored; original never executed.  No stock
 * spine-c source was consulted for behaviour: this build's key set, field
 * offsets and the hex color channel were read from the instruction stream
 * (census §2.3 / §7).
 */

#include "spine_read_tl_slots.h"

#include "../../spine_color/src/spine_color.h"                 /* toColor  0x28b680 */
#include "../../spine_read_curve/src/spine_read_curve.h"       /* readCurve 0x28b34c */
#include "../../spine_json_error/src/spine_json_error.h"       /* _spSkeletonJson_setError */
#include "../../skeleton_find/src/skeleton_find.h"             /* findSlotIndex 0x28b0cc */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h" /* dispose 0x28adf8 */

/* 0x357e90 — the exact literal, trailing space included (pool 0x28ca58,
 * add site 0x28da3c: pc 0x28da44 + word 0x000ca44c). */
static const char* const ERR_INVALID_SLOT_TIMELINE =
    "Invalid timeline type for a slot: ";

/*
 * ---------------------------------------------------------------------------
 * B5 attachment branch, 0x28d578..0x28d61c.
 *
 *   0x28d578 ldr r0,[r9,#0xc]        frameCount = timelineJson->unk_0c
 *   0x28d57c bl  spAttachmentTimeline_create(frameCount)
 *   0x28d580 ldr r4,[r9,#0x4]        frame = timelineJson->child
 *   0x28d584 ldr r2,[sp,#0x3c]       slotIndex (published by 0x28d534)
 *   0x28d588 cmp r4,#0
 *   0x28d58c mov r8,r0               timeline
 *   0x28d590 str r2,[r0,#0x10]       timeline->slotIndex = slotIndex
 *   0x28d594 beq 0x28d5e8            no frames -> tail
 *
 *   0x28d598..0x28d5a0  name_node = Json_getItem(frame,"name")   [r7 = "name"]
 *   0x28d5a4..0x28d5b4  time      = Json_getFloat(frame,"time",0) [r6 = "time"]
 *   0x28d5b8 ldr r3,[r10,#0x8]       kind = name_node->unk_08  (NO NULL test)
 *   0x28d5bc mov r1,r5               arg2 = frameIndex (old)
 *   0x28d5c0 add r5,r5,#1            frameIndex++
 *   0x28d5c4 cmp r3,#2
 *   0x28d5c8 ldrne r3,[r10,#0x10]    name = name_node->string_value
 *   0x28d5cc moveq r3,#0             kind == 2 -> name = NULL
 *   0x28d5d0 mov r2,r0               arg3 = time bits
 *   0x28d5d4 mov r0,r8               arg1 = timeline
 *   0x28d5d8 bl  spAttachmentTimeline_setFrame
 *   0x28d5dc ldr r4,[r4]             frame = frame->next
 *   0x28d5e0 cmp r4,#0
 *   0x28d5e4 bne 0x28d598            loop on the frame list, not on the count
 *
 * Tail (shared shape with B8b, but this copy is 1-float-stride):
 *   0x28d5e8 ldr r3,[r11,#0x8]       count = animation->timelineCount
 *   0x28d5ec vldr s14,[r11,#4]       duration = animation->duration
 *   0x28d5f0 ldr r1,[r11,#0xc]       timelines = animation->timelines
 *   0x28d5f4 add r2,r3,#1
 *   0x28d5f8 str r2,[r11,#0x8]       animation->timelineCount = count + 1
 *   0x28d5fc ldr r2,[r9,#0xc]        declared frameCount (the JSON size)
 *   0x28d600 str r8,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28d604 ldr r3,[r8,#0xc]        frames
 *   0x28d608 add r3,r3,r2,lsl#2      &frames[frameCount]
 *   0x28d60c vldr s15,[r3,#-4]       last = frames[frameCount-1]
 *   0x28d610 vcmpe.f32 s14,s15
 *   0x28d618 vmovgt.f32 s15,s14
 *   0x28d61c vstr s15,[r11,#4]       duration = (duration > last) ? duration : last
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_attachmentTimeline(Json* timelineJson, void* animation_raw, int slotIndex)
{
    spAnimationShape* animation = (spAnimationShape*)animation_raw;
    spAttachmentTimelineShape* timeline;
    Json* frame;
    /* 0x28d55c/0x28d570: the dispatch's matching strcmp left r5 == 0, and
     * this branch is only entered on that match, so the loop starts at 0
     * without an explicit clear instruction. */
    int frameIndex = 0;

    /* 0x28d578/0x28d57c: create with the DECLARED JSON count */
    timeline = (spAttachmentTimelineShape*)spAttachmentTimeline_create((int)timelineJson->unk_0c);
    frame = timelineJson->child;                     /* 0x28d580 */
    timeline->slotIndex = slotIndex;                 /* 0x28d590 */

    if (frame != 0) {                                /* 0x28d588 / 0x28d594 */
        do {
            Json* name_node = Json_getItem(frame, "name");        /* 0x28d598..0x28d5a0 */
            float time = Json_getFloat(frame, "time", 0.0f);      /* 0x28d5a4..0x28d5b4 */
            uint32_t kind = name_node->unk_08;                    /* 0x28d5b8 */
            int index = frameIndex;                               /* 0x28d5bc */
            const char* attachment_name;

            frameIndex = index + 1;                               /* 0x28d5c0 */
            attachment_name = (kind == 2u) ? 0 : name_node->string_value; /* 0x28d5c4..0x28d5cc */

            spAttachmentTimeline_setFrame((void*)timeline, index, time,
                                          attachment_name);        /* 0x28d5d0..0x28d5d8 */
            frame = frame->next;                                   /* 0x28d5dc */
        } while (frame != 0);                                      /* 0x28d5e0 / 0x28d5e4 */
    }

    /* 0x28d5e8..0x28d61c: publish and extend the animation duration. */
    {
        int32_t count = animation->timelineCount;        /* 0x28d5e8 */
        float duration = animation->duration;            /* 0x28d5ec */
        void** timelines = animation->timelines;         /* 0x28d5f0 */
        uint32_t declared = timelineJson->unk_0c;        /* 0x28d5fc */
        uint32_t last_index = declared - 1u;             /* wraps like the original */
        float last;

        animation->timelineCount = count + 1;            /* 0x28d5f4 / 0x28d5f8 */
        timelines[count] = (void*)timeline;              /* 0x28d600 */
        last = timeline->frames[last_index];             /* 0x28d604..0x28d60c */
        animation->duration = (duration > last) ? duration : last; /* 0x28d610..0x28d61c */
    }
}

/*
 * ---------------------------------------------------------------------------
 * B8 color timeline frames + B8b tail, 0x28d8dc..0x28da14.
 *
 *   0x28d8dc ldr r0,[r9,#0xc]        frameCount = timelineJson->unk_0c
 *   0x28d8e0 bl  spColorTimeline_create(frameCount)
 *   0x28d8e4 ldr r10,[r9,#0x4]       frame = timelineJson->child
 *   0x28d8e8 ldr r1,[sp,#0x3c]       slotIndex
 *   0x28d8f0 mov r8,r0               timeline
 *   0x28d8f4 str r1,[r0,#0x14]       timeline->slotIndex (color: +0x14!)
 *   0x28d8f8 beq 0x28d9d4            no frames -> tail
 *   0x28d8fc ldr r12,[pc,#-0xeb0]    pool 0x28ca54 -> 0x34c1d4 "time"
 *   (0x28d900..0x28d91c: r7=frame, r6="color" from [sp+0x54], r11="time",
 *    r9/timelineJson and the animation spilled for the loop)
 *
 *   0x28d920..0x28d92c  color = Json_getString(frame,"color",0)
 *   0x28d930..0x28d940  time  = Json_getFloat(frame,"time",0)
 *   0x28d944..0x28d950  toColor(color,0)  -> r  (0x28b680)
 *   0x28d954..0x28d960  toColor(color,1)  -> g  (kept in s17)
 *   0x28d964..0x28d970  toColor(color,2)  -> b  (kept in s16)
 *   0x28d974..0x28d980  toColor(color,3)  -> a  (s0)
 *   0x28d984 mov r1,r5               frameIndex
 *   0x28d988 mov r2,r9               time bits
 *   0x28d98c mov r0,r8               timeline
 *   0x28d990 ldr r3,[sp,#0x10]       arg4 = r (the first toColor spill)
 *   0x28d994 vstr s17,[sp]           arg5 = g
 *   0x28d998 vstr s16,[sp,#4]        arg6 = b
 *   0x28d99c vstr s0,[sp,#8]         arg7 = a
 *   0x28d9a0 bl  spColorTimeline_setFrame(t,i,time,r,g,b,a)
 *   0x28d9a4..0x28d9b0 bl readCurve(frame,t,i)  [r0=frame r1=r8 r2=r5]
 *   0x28d9b4 ldr r7,[r7]             frame = frame->next
 *   0x28d9b8 add r5,r5,#1            frameIndex++
 *   0x28d9bc/0x28d9c0                loop
 *
 *   0x28d9c4..0x28d9d0 restore r11/r6/r9/r7
 * Tail B8b:
 *   0x28d9d4 ldr r2,[r9,#0xc]        declared frameCount
 *   0x28d9d8 vldr s14,[r11,#4]       duration
 *   0x28d9dc ldr r3,[r11,#0x8]       timelineCount
 *   0x28d9e0 ldr r1,[r11,#0xc]       timelines
 *   0x28d9e4 sub r2,r2,#1            frameCount-1
 *   0x28d9e8/0x28d9ec                timelineCount = count+1
 *   0x28d9f0 add r2,r2,r2,lsl#2      (frameCount-1)*5
 *   0x28d9f4 str r8,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28d9f8 ldr r3,[r8,#0x10]       frames (color: +0x10, stride 5)
 *   0x28d9fc add r3,r3,r2,lsl#2      &frames[(frameCount-1)*5]
 *   0x28da00 vldr s15,[r3]           last
 *   0x28da04..0x28da10               duration = (duration > last) ? duration : last
 *   0x28da14 b 0x28d620              back edge: next timeline of this slot
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_colorTimeline(Json* timelineJson, void* animation_raw, int slotIndex)
{
    spAnimationShape* animation = (spAnimationShape*)animation_raw;
    spColorTimelineShape* timeline;
    Json* frame;
    int frameIndex = 0;                              /* 0x28d55c/0x28d570 match */

    timeline = (spColorTimelineShape*)spColorTimeline_create((int)timelineJson->unk_0c); /* 0x28d8dc/d8e0 */
    frame = timelineJson->child;                     /* 0x28d8e4 */
    timeline->slotIndex = slotIndex;                 /* 0x28d8f4 */

    if (frame != 0) {                                /* 0x28d8ec / 0x28d8f8 */
        do {
            /* 0x28d920..0x28d92c: the hex string channel, not an rgba array */
            const char* color = Json_getString(frame, "color", 0);
            /* 0x28d930..0x28d940 */
            float time = Json_getFloat(frame, "time", 0.0f);
            /* 0x28d944..0x28d980: four independent toColor calls, no checks */
            float r = toColor(color, 0);
            float g = toColor(color, 1);
            float b = toColor(color, 2);
            float a = toColor(color, 3);

            spColorTimeline_setFrame((void*)timeline, frameIndex, time,
                                     r, g, b, a);        /* 0x28d984..0x28d9a0 */
            readCurve(frame, (void*)timeline, frameIndex); /* 0x28d9a4..0x28d9b0 */
            frame = frame->next;                          /* 0x28d9b4 */
            ++frameIndex;                                 /* 0x28d9b8 */
        } while (frame != 0);                             /* 0x28d9bc / 0x28d9c0 */
    }

    /* 0x28d9d4..0x28da10: publish and extend, 5-float frame stride. */
    {
        uint32_t declared = timelineJson->unk_0c;        /* 0x28d9d4 */
        float duration = animation->duration;            /* 0x28d9d8 */
        int32_t count = animation->timelineCount;        /* 0x28d9dc */
        void** timelines = animation->timelines;         /* 0x28d9e0 */
        uint32_t word_index = (declared - 1u) * 5u;      /* 0x28d9e4 / 0x28d9f0 */
        float last;

        animation->timelineCount = count + 1;            /* 0x28d9e8 / 0x28d9ec */
        timelines[count] = (void*)timeline;              /* 0x28d9f4 */
        last = timeline->frames[word_index];             /* 0x28d9f8..0x28da00 */
        animation->duration = (duration > last) ? duration : last; /* 0x28da04..0x28da10 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * E1, 0x28da18..0x28da50.
 *
 *   0x28da18 ldr r8,[sp,#0x20]       parser (stored at 0x28d314 mov r8,self)
 *   0x28da1c mov r0,r11              animation
 *   0x28da20 mov r4,r9               timelineJson
 *   0x28da24 ldr r9,[sp,#0x18]       data
 *   0x28da28 bl  spAnimation_dispose(animation)
 *   0x28da2c ldr r2,[pc,#-0xfdc]     pool 0x28ca58 -> 0x357e90
 *   0x28da30 mov r0,r8               arg1 = parser
 *   0x28da34 ldr r3,[r4,#0x1c]       arg4 = timelineJson->name (the type text)
 *   0x28da38 mov r1,#0               arg2 = NULL  -> no Json_dispose of the tree
 *   0x28da3c add r2,pc,r2            arg3 = "Invalid timeline type for a slot: "
 *   0x28da40 bl  _spSkeletonJson_setError
 *   0x28da44 mov r0,r9
 *   0x28da48 bl  spSkeletonData_dispose(data)
 *   0x28da4c mov r0,#0
 *   0x28da50 b   0x28bdcc            parent returns NULL
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_invalidTimelineTypeForSlot(void* animation_raw, Json* timelineJson,
                                            void* data_raw, void* parser_raw)
{
    /* 0x28da34: the offending text is the timeline's JSON member key */
    const char* type = timelineJson->name;

    spAnimation_dispose((spAnimation*)animation_raw);            /* 0x28da28 */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw, 0,      /* 0x28da30..0x28da40 */
                             ERR_INVALID_SLOT_TIMELINE, type);
    spSkeletonData_dispose((spSkeletonData*)data_raw);            /* 0x28da44..0x28da48 */
    return 0;                                                     /* 0x28da4c / 0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * B5 dispatch, 0x28d4ec..0x28d640.
 *
 * Key-pointer cache (0x28d4ec..0x28d51c) — the original materialises five
 * literals once per entry and spills three of them:
 *   0x28d4ec/0x28d4f8  r7            = "name"       @0x330810 (pool 0x28ca18)
 *   0x28d4f0/0x28d500  r6            = "time"       @0x34c1d4 (pool 0x28ca1c)
 *   0x28d4f4/0x28d508  r0 -> [sp+40] = "color"      @0x357c18 (pool 0x28ca20)
 *   0x28d4fc/0x28d50c  r1 -> [sp+48] = "attachment" @0x330944 (pool 0x28ca24)
 *   0x28d504/0x28d514  r2 -> [sp+54] = "color"      @0x357c18 (pool 0x28ca28)
 * The two "color" copies are the same literal address: [sp+0x40] feeds the
 * type strcmp, [sp+0x54] feeds Json_getString inside B8.  No behavioural
 * difference follows, so the C below uses one literal per role.
 *
 *   0x28d520 ldr r3,[sp,#0x2c]       slotMap = [sp+0x2c]
 *   0x28d524 ldr r0,[sp,#0x18]       data
 *   0x28d528 ldr r1,[r3,#0x1c]       slotMap->name (the member key)
 *   0x28d52c bl  spSkeletonData_findSlotIndex(data, name)
 *   0x28d530 cmn r0,#1
 *   0x28d534 str r0,[sp,#0x3c]       slotIndex spilled for both branches
 *   0x28d538 beq 0x28ea10            -1 -> "Slot not found:" block (out of scope)
 *   0x28d53c ldr r3,[sp,#0x2c]
 *   0x28d540 ldr r9,[r3,#0x4]        timelineJson = slotMap->child
 *   0x28d544/0x28d548                none -> next slot
 *
 *   0x28d54c ldr r4,[r9,#0x1c]       type = timelineJson->name
 *   0x28d550..0x28d560               strcmp(type,"color") == 0 -> 0x28d8dc (B8)
 *   0x28d564..0x28d570               strcmp(type,"attachment") == 0
 *   0x28d574 bne 0x28da18            neither -> E1
 *   (0x28d578 -> attachment reader, see above)
 *   0x28d620 ldr r9,[r9]             timelineJson = timelineJson->next
 *   0x28d624/0x28d628                loop while non-NULL
 *
 *   0x28d62c..0x28d63c  slotMap = slotMap->next; loop while non-NULL
 *   fall-through 0x28d640            bones block (out of scope)
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_slotTimelines(Json* slotMap, void* data_raw, void* animation_raw,
                               void* parser_raw)
{
    while (slotMap != 0) {                       /* 0x28d520 head / 0x28d63c back edge */
        int slotIndex = spSkeletonData_findSlotIndex((spSkeletonData*)data_raw,
                                                     slotMap->name); /* 0x28d524..0x28d52c */
        Json* timelineJson;

        if (slotIndex == -1)                     /* 0x28d530 cmn r0,#1 */
            return 0;                            /* 0x28d538 beq 0x28ea10 (out of block) */

        timelineJson = slotMap->child;           /* 0x28d53c / 0x28d540 */
        if (timelineJson != 0) {                 /* 0x28d544 / 0x28d548 */
            do {
                const char* type = timelineJson->name;             /* 0x28d54c */
                if (strcmp(type, "color") == 0) {                  /* 0x28d550..0x28d560 */
                    readSkeletonData_colorTimeline(timelineJson, animation_raw, slotIndex);
                } else if (strcmp(type, "attachment") == 0) {      /* 0x28d564..0x28d570 */
                    readSkeletonData_attachmentTimeline(timelineJson, animation_raw, slotIndex);
                } else {
                    /* 0x28d574 bne 0x28da18 */
                    return readSkeletonData_invalidTimelineTypeForSlot(
                        animation_raw, timelineJson, data_raw, parser_raw);
                }
                timelineJson = timelineJson->next;                 /* 0x28d620 */
            } while (timelineJson != 0);                           /* 0x28d624 / 0x28d628 */
        }
        slotMap = slotMap->next;                 /* 0x28d62c..0x28d638 */
    }
    return 1;                                    /* 0x28d640 fall-through */
}
