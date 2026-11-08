/*
 * spine_read_tl_draworder.c — drawOrder timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B15   0x28e338..0x28e528  (125 insns)  node test, create, frame-frame
 *                                          offsets -> slot indices with the TWO
 *                                          mallocs (lines 442/445), the -1 fill,
 *                                          the leftover merge and _free(A)
 *   B15b  0x28e594..0x28e614  ( 32 insns)  "time" + setFrame + _free(B) loop,
 *                                          back edge 0x28e5cc, publish tail
 *   E4    0x28e55c..0x28e58c  ( 13 insns)  "Attachment not found: "
 *   0x28e52c..0x28e558        ( 12 insns)  PATH family island — NOT translated
 *                                          here (c/spine_read_tl_path owns it);
 *                                          0x28e528 `b 0x28e594` steps over it.
 *   0x28e590                  (  1 insn)  the "no offsets" join, inside E4's
 *                                          address window, translated below.
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted: the key set ("offsets"/"slot"/"offset"/"time"),
 * the two size formulas, the -1 fill, the merge direction, the setFrame call
 * shape and the NULL json argument of E4 are all read off the instruction
 * stream (census §2.7 / §3.1 / §6 B15,B15b,E4 / §7 open #4).
 */

#include "spine_read_tl_draworder.h"

#include "../../skeleton_find/src/skeleton_find.h"          /* findSlotIndex 0x28b0cc */
#include "../../spine_json_error/src/spine_json_error.h"    /* setError 0x28b784 */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h" /* dispose pair */

/* 0x28e574/0x28e584 -> pool 0x28eae4 -> 0x357f2c. */
#define ERR_ATTACHMENT_NOT_FOUND "Attachment not found: "

/*
 * ---------------------------------------------------------------------------
 * One frame's draw order: 0x28e3b4..0x28e528 plus the 0x28e590 join.
 *
 * Register map, read off the block: r9 = frame, r4 = offsets node then reused
 * as `original`, r7 = offsets entry, r11 = A (line 442), r6 = B (line 445),
 * r5 = `unmoved` (the A write cursor), r8 = data, r10 = frameIndex.
 *
 *   0x28e3b4 mov r0,r9 ; 0x28e3b8 ldr r1,[sp,#0x3c] ; 0x28e3bc bl Json_getItem
 *   0x28e3c0 subs r4,r0,#0
 *   0x28e3c4 beq 0x28e590          no "offsets" -> r4 == 0 -> r6 = 0 at 0x28e590
 *   0x28e3c8 ldr r3,[r4,#0xc]      jsonOffsetsSize (the offsets array count)
 *   0x28e3cc movw r2,#0x1ba        line 442
 *   0x28e3d0 ldr r0,[r8,#0x18]     slotsCount
 *   0x28e3d4 ldr r1,[sp,#0x30]     malloc tag
 *   0x28e3d8 rsb r0,r3,r0          slotsCount - jsonOffsetsSize
 *   0x28e3dc lsl r0,r0,#2          * 4        (32-bit wrap, NOT clamped)
 *   0x28e3e0 bl _malloc            A = leftovers
 *   0x28e3e4 ldr r1,[sp,#0x30]
 *   0x28e3e8 movw r2,#0x1bd        line 445
 *   0x28e3ec mov r11,r0            A
 *   0x28e3f0 ldr r0,[r8,#0x18]     slotsCount
 *   0x28e3f4 lsl r0,r0,#2          slotsCount * 4
 *   0x28e3f8 bl _malloc            B = order
 *   0x28e3fc ldr r2,[r8,#0x18]     slotsCount
 *   0x28e400 subs r1,r2,#1
 *   0x28e404 mov r6,r0             B
 *   0x28e408 addpl r2,r0,r2,lsl#2  end pointer = B + slotsCount*4
 *   0x28e40c mvnpl r0,#0           fill word = -1
 *   0x28e410 bmi 0x28e424          slotsCount-1 < 0 -> no fill at all
 *   0x28e414 sub r1,r1,#1
 *   0x28e418 str r0,[r2,#-0x4]!    *--p = -1
 *   0x28e41c cmn r1,#1
 *   0x28e420 bne 0x28e414          exactly slotsCount stores
 *   0x28e424 ldr r7,[r4,#0x4]      first offsets entry
 *   0x28e428 cmp r7,#0
 *   0x28e42c moveq r5,r7  0x28e430 moveq r4,r5   0x28e434 beq 0x28e4c4
 *   0x28e438 mov r5,#0    0x28e43c mov r4,r5      unmoved = 0, original = 0
 *   --- per entry, head 0x28e440, back edge 0x28e4c0 ---
 *   0x28e440..0x28e44c  Json_getString(entry,"slot",NULL)
 *   0x28e454..0x28e458  spSkeletonData_findSlotIndex(data,name)
 *   0x28e45c cmn r0,#1
 *   0x28e464 beq 0x28e8ac          slot miss -> OUT OF RANGE (E6), see below
 *   0x28e468 cmp r0,r4
 *   0x28e46c subne r1,r5,#-1073741823   r1 = r5*4 - 4 (the immediate trick)
 *   0x28e470 movne r2,r4
 *   0x28e474 addne r1,r11,r1,lsl#2      r1 = A + r5*4 - 4
 *   0x28e478 beq 0x28e49c          same slot as the previous entry: no run
 *   0x28e47c add r0,r2,#1
 *   0x28e480 str r2,[r1,#0x4]!     A[unmoved++] = original++
 *   0x28e484 cmp r0,r3             until original == slotIndex
 *   0x28e488 mov r2,r0
 *   0x28e48c bne 0x28e47c
 *   0x28e490 add r5,r3,r5          unmoved += slotIndex (the run length is
 *   0x28e494 rsb r5,r4,r5           already counted by the pointer advance)
 *   0x28e498 mov r4,r3             original = slotIndex
 *   0x28e49c..0x28e4a8  Json_getInt(entry,"offset",0)
 *   0x28e4ac ldr r7,[r7]           entry = entry->next
 *   0x28e4b4 add r0,r4,r0          slotIndex + offset
 *   0x28e4b8 str r4,[r6,r0,lsl#2]  B[slotIndex+offset] = slotIndex
 *   0x28e4bc add r4,r4,#1          original = slotIndex + 1
 *   0x28e4c0 bne 0x28e440
 *   --- tail fill: the slots no entry mentioned, in slot order ---
 *   0x28e4c4 ldr r2,[r8,#0x18]     slotsCount
 *   0x28e4c8 cmp r4,r2
 *   0x28e4cc bge 0x28e4f4          SIGNED: original >= slotsCount -> done
 *   0x28e4d0..0x28e4d8            A[unmoved++] = original++ (same immediate trick)
 *   0x28e4e0 ldr r2,[r8,#0x18]
 *   0x28e4ec cmp r3,r2
 *   0x28e4f0 blt 0x28e4d8
 *   --- merge: every -1 in B is replaced by the LAST unused A entry ---
 *   0x28e4f4 subs r1,r2,#1         i = slotsCount-1
 *   0x28e4f8 addpl r2,r6,r2,lsl#2  p = B + slotsCount*4
 *   0x28e4fc bmi 0x28e520          slotsCount <= 0 -> no merge
 *   0x28e500 ldr r3,[r2,#-0x4]!    r3 = B[--i]
 *   0x28e508 cmn r3,#1
 *   0x28e50c subeq r5,r5,#1        unmoved--
 *   0x28e510 ldreq r3,[r11,r5,lsl#2]  r3 = A[unmoved]
 *   0x28e514 streq r3,[r2]         B[i] = A[unmoved]
 *   0x28e51c bne 0x28e500          runs exactly slotsCount times
 *   0x28e520 mov r0,r11
 *   0x28e524 bl _free              A is released HERE, before setFrame
 *   0x28e528 b 0x28e594            steps over the path island AND over E4
 *   (0x28e590 mov r6,r4 — the "no offsets" join, r4 == 0 there)
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_drawOrderFrame(Json* frame, void* data_raw, int32_t** out_order)
{
    spSkeletonDataDrawOrderShape* data = (spSkeletonDataDrawOrderShape*)data_raw;
    Json* offsets;
    Json* entry;
    int32_t* leftovers;
    int32_t* order;
    int32_t json_offsets_size;
    int32_t fill_count;
    int32_t bound;
    int32_t original;
    int32_t unmoved;

    offsets = Json_getItem(frame, "offsets");          /* 0x28e3b4..0x28e3bc */
    if (offsets == 0) {                                /* 0x28e3c0 / 0x28e3c4 */
        *out_order = 0;                                /* 0x28e590 mov r6,r4 */
        return DRAWORDER_TL_OK;
    }

    json_offsets_size = (int32_t)offsets->unk_0c;      /* 0x28e3c8 */

    /* 0x28e3cc..0x28e3e0: (slotsCount - jsonOffsetsSize) * 4, 32-bit wrap.
     * The subtraction and the shift are both unsigned in the original (rsb,
     * lsl), so a jsonOffsetsSize larger than slotsCount hands _malloc a huge
     * 32-bit size.  Reproduced, not clamped; the fixture records the word.
     * slotsCount is re-read here (0x28e3d0) rather than cached: the allocator
     * callback runs INSIDE _malloc and could change the word. */
    leftovers = (int32_t*)_malloc(
        ((uint32_t)data->slotsCount - (uint32_t)json_offsets_size) * 4u,
        SPINE_JSON_SOURCE_TAG, DRAWORDER_LINE_LEFTOVERS);

    /* 0x28e3e8..0x28e3f8: slotsCount * 4 (re-read at 0x28e3f0). */
    order = (int32_t*)_malloc((uint32_t)data->slotsCount * 4u,
                              SPINE_JSON_SOURCE_TAG, DRAWORDER_LINE_ORDER);

    fill_count = data->slotsCount;                     /* 0x28e3fc (third read) */
    if (fill_count > 0) {                              /* 0x28e400 / 0x28e410 bmi */
        uint32_t k = (uint32_t)fill_count;             /* 0x28e408 addpl end ptr */
        while (k != 0u) {                              /* 0x28e41c cmn / 0x28e420 bne */
            --k;
            order[k] = -1;                             /* 0x28e40c mvn r0,#0 ; 0x28e418 */
        }
    }

    original = 0;                                      /* 0x28e430 / 0x28e43c */
    unmoved = 0;                                       /* 0x28e42c / 0x28e438 */
    entry = offsets->child;                            /* 0x28e424 */

    while (entry != 0) {                               /* 0x28e428 / 0x28e4c0 bne */
        const char* name = Json_getString(entry, "slot", 0);   /* 0x28e440..0x28e44c */
        int32_t slot_index = spSkeletonData_findSlotIndex(data_raw, name);
                                                       /* 0x28e454..0x28e458 */

        if (slot_index == -1)                          /* 0x28e45c cmn r0,#1 */
            return DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND;
            /* 0x28e464 beq 0x28e8ac: the "Slot not found: " block lives at
             * 0x28e8ac..0x28e8ec, outside this module's window.  A and B are
             * still allocated on that path — the original does not free them
             * either (no _free between 0x28e3e0 and the branch), so the leak is
             * part of the behaviour, not a reconstruction slip. */

        if (slot_index != original) {                  /* 0x28e468 cmp / 0x28e478 beq */
            int32_t walk = original;                   /* 0x28e470 movne r2,r4 */
            do {
                leftovers[unmoved] = walk;             /* 0x28e480 str r2,[r1,#0x4]! */
                ++unmoved;
                ++walk;                                /* 0x28e47c add r0,r2,#1 */
            } while (walk != slot_index);              /* 0x28e48c bne 0x28e47c */
            /* 0x28e490/0x28e494 add up the run length without a second counter:
             * the pointer advance above already covered it. */
            original = slot_index;                     /* 0x28e498 mov r4,r3 */
        }

        {
            int32_t offset = Json_getInt(entry, "offset", 0);  /* 0x28e49c..0x28e4a8 */
            order[(uint32_t)original + (uint32_t)offset] = original;
                                                       /* 0x28e4b4 add / 0x28e4b8 str */
            ++original;                                /* 0x28e4bc add r4,r4,#1 */
        }

        entry = entry->next;                           /* 0x28e4ac ldr r7,[r7] */
    }

    /* 0x28e4c4..0x28e4f0: append every slot index no entry mentioned.  The
     * bound word is re-loaded on every iteration (0x28e4c4 outside, 0x28e4e0
     * inside) and the merge at 0x28e4f4 uses whichever read happened last, so
     * the loop below carries the bound in `bound` instead of re-testing a
     * cached constant. */
    bound = data->slotsCount;                           /* 0x28e4c4 */
    while (original < bound) {                          /* 0x28e4c8 / 0x28e4cc bge */
        leftovers[unmoved] = original;                  /* 0x28e4d8 str r4,[r1,#0x4]! */
        ++unmoved;
        ++original;                                     /* 0x28e4dc / 0x28e4e8 */
        bound = data->slotsCount;                       /* 0x28e4e0 */
    }

    /* 0x28e4f4..0x28e51c: fill the -1 holes from the TAIL of A backwards, so
     * the leftovers keep their ascending order in the final array. */
    if (bound > 0) {                                    /* 0x28e4f4 / 0x28e4fc bmi */
        uint32_t i = (uint32_t)bound;
        while (i != 0u) {                               /* 0x28e51c bne 0x28e500 */
            --i;                                        /* 0x28e500 ldr r3,[r2,#-0x4]! */
            if (order[i] == -1) {                       /* 0x28e508 cmn r3,#1 */
                --unmoved;                              /* 0x28e50c subeq */
                order[i] = leftovers[unmoved];          /* 0x28e510 / 0x28e514 */
            }
        }
    }

    _free(leftovers);                                   /* 0x28e520 / 0x28e524 */
    *out_order = order;                                 /* r6 survives to 0x28e5b8 */
    return DRAWORDER_TL_OK;
}

/*
 * ---------------------------------------------------------------------------
 * The frame-list loop, 0x28e35c..0x28e5d0.  Same block as B15's tail; the loop
 * head is 0x28e3b4, which is inside readSkeletonData_drawOrderFrame, so this
 * function is the driver of the whole chain.
 *
 *   0x28e35c ldr r0,[sp,#0x28]     "drawOrder" node
 *   0x28e360 ldr r9,[r0,#0x4]      frame = drawOrderNode->child
 *   0x28e364 cmp r9,#0
 *   0x28e368 beq 0x28e5d4          no frames -> publish a zero-frame timeline
 *   0x28e370 mov r10,#0            frameIndex = 0
 *   --- head 0x28e3b4, back edge 0x28e5cc ---
 *   0x28e3b4..0x28e528             readSkeletonData_drawOrderFrame
 *   0x28e590 mov r6,r4             (only on the "no offsets" join, r6 = 0)
 *   0x28e594 mov r0,r9             frame
 *   0x28e598 ldr r1,[sp,#0x44]     "time"
 *   0x28e59c mov r2,#0             default 0.0f
 *   0x28e5a0 bl Json_getFloat
 *   0x28e5a4 mov r1,r10            arg2 = frameIndex (PRE-increment)
 *   0x28e5a8 mov r3,r6             arg4 = the order array (or NULL)
 *   0x28e5ac add r10,r10,#1        frameIndex++
 *   0x28e5b0 mov r2,r0             arg3 = time bits
 *   0x28e5b4 ldr r0,[sp,#0x2c]     arg1 = timeline
 *   0x28e5b8 bl spDrawOrderTimeline_setFrame
 *   0x28e5bc mov r0,r6
 *   0x28e5c0 bl _free              B is released immediately after the call —
 *                                  setFrame must have copied it (line 690)
 *   0x28e5c4 ldr r9,[r9]           frame = frame->next
 *   0x28e5c8 cmp r9,#0
 *   0x28e5cc bne 0x28e3b4
 *   0x28e5d0 ldr r11,[sp,#0x38]    restore the animation pointer
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_drawOrderTimelineFrames(Json* drawOrder_json, void* data_raw,
                                         void* timeline_raw)
{
    Json* frame;
    int32_t frame_index;

    frame = drawOrder_json->child;                     /* 0x28e35c / 0x28e360 */
    if (frame == 0)                                    /* 0x28e364 / 0x28e368 */
        return DRAWORDER_TL_OK;

    frame_index = 0;                                   /* 0x28e370 mov r10,#0 */
    do {
        int32_t* order;
        float time;
        int rc;

        rc = readSkeletonData_drawOrderFrame(frame, data_raw, &order);
                                                       /* 0x28e3b4..0x28e528 */
        if (rc != DRAWORDER_TL_OK)
            return rc;                                 /* 0x28e464 -> 0x28e8ac */

        time = Json_getFloat(frame, "time", 0.0f);      /* 0x28e594..0x28e5a0 */
        spDrawOrderTimeline_setFrame(timeline_raw, frame_index, time, order);
                                                       /* 0x28e5a4..0x28e5b8 */
        _free(order);                                   /* 0x28e5bc / 0x28e5c0 */
        ++frame_index;                                  /* 0x28e5ac */
        frame = frame->next;                            /* 0x28e5c4 */
    } while (frame != 0);                               /* 0x28e5c8 / 0x28e5cc */

    return DRAWORDER_TL_OK;
}

/*
 * ---------------------------------------------------------------------------
 * B15 driver: 0x28e338..0x28e358, the frame loop, then the publish tail
 * 0x28e5d4..0x28e610.
 *
 *   0x28e338 ldr r3,[sp,#0x28]     "drawOrder" node
 *   0x28e33c cmp r3,#0
 *   0x28e340 beq 0x28e614          absent -> the event block
 *   0x28e344 ldr r2,[sp,#0x28]
 *   0x28e348 ldr r3,[sp,#0x18]     data
 *   0x28e34c ldr r0,[r2,#0xc]      DECLARED frame count
 *   0x28e350 ldr r1,[r3,#0x18]     slotsCount
 *   0x28e354 bl spDrawOrderTimeline_create
 *   0x28e358 str r0,[sp,#0x2c]     the timeline lives in [sp+0x2c]
 *   (frame loop)
 *   0x28e5d4 ldr r0,[sp,#0x28]
 *   0x28e5d8 vldr s14,[r11,#4]     animation->duration
 *   0x28e5dc ldr r3,[r11,#0x8]     timelineCount
 *   0x28e5e0 ldr r1,[r11,#0xc]     timelines
 *   0x28e5e4 ldr r2,[r0,#0xc]      declared frame count
 *   0x28e5e8 add r0,r3,#1
 *   0x28e5ec str r0,[r11,#0x8]     timelineCount = count + 1 (stored FIRST)
 *   0x28e5f0 ldr r0,[sp,#0x2c]
 *   0x28e5f4 str r0,[r1,r3,lsl#2]  timelines[count] = timeline (OLD count)
 *   0x28e5f8 ldr r3,[r0,#0xc]      timeline->times
 *   0x28e5fc add r3,r3,r2,lsl#2    + declared*4  (FOUR-byte stride, not 8)
 *   0x28e600 vldr s15,[r3,#-4]     times[declared-1] = the last TIME
 *   0x28e604 vcmpe.f32 s14,s15
 *   0x28e608 vmrs APSR_nzcv,fpscr
 *   0x28e60c vmovgt.f32 s15,s14
 *   0x28e610 vstr s15,[r11,#4]     duration = max
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_drawOrderTimelines(Json* drawOrder_json, void* data_raw,
                                    void* animation_raw)
{
    spSkeletonDataDrawOrderShape* data = (spSkeletonDataDrawOrderShape*)data_raw;
    spAnimationDrawOrderShape* animation = (spAnimationDrawOrderShape*)animation_raw;
    spDrawOrderTimelineShape* timeline;
    int rc;

    if (drawOrder_json == 0)                           /* 0x28e338..0x28e340 */
        return DRAWORDER_TL_OK;

    timeline = (spDrawOrderTimelineShape*)spDrawOrderTimeline_create(
        (int)drawOrder_json->unk_0c,                   /* declared frame count */
        data->slotsCount);                             /* 0x28e344..0x28e358 */

    rc = readSkeletonData_drawOrderTimelineFrames(drawOrder_json, data_raw,
                                                  (void*)timeline);
    if (rc != DRAWORDER_TL_OK)
        return rc;                                     /* 0x28e464 -> 0x28e8ac */

    {
        int32_t count = animation->timelineCount;      /* 0x28e5dc */
        float duration = animation->duration;          /* 0x28e5d8 */
        void** timelines = animation->timelines;       /* 0x28e5e0 */
        uint32_t declared = drawOrder_json->unk_0c;    /* 0x28e5e4 */
        float last;

        animation->timelineCount = count + 1;          /* 0x28e5e8 / 0x28e5ec */
        timelines[count] = (void*)timeline;            /* 0x28e5f4 */

        /* 0x28e5f8..0x28e600.  declared == 0 wraps to times[0xffffffff]; the
         * original indexes it blindly and the fixture never drives it. */
        last = timeline->times[declared - 1u];
        animation->duration = (duration > last) ? duration : last;
                                                       /* 0x28e604..0x28e610 */
    }

    return DRAWORDER_TL_OK;                            /* 0x28e614 */
}

/*
 * ---------------------------------------------------------------------------
 * E4, 0x28e55c..0x28e58c plus the common tail 0x28da44..0x28da50.
 *
 *   0x28e55c mov r5,r8            r8 == 0 (0x28e10c subs r8,r0,#0 ;
 *                                 0x28e110 beq 0x28e55c)
 *   0x28e560 mov r0,r10           animation
 *   0x28e564 ldr r8,[sp,#0x20]    parser
 *   0x28e568 mov r7,r9            the attachment timeline node
 *   0x28e56c ldr r9,[sp,#0x18]    data
 *   0x28e570 bl spAnimation_dispose
 *   0x28e574 ldr r2,[pc,#0x568]   pool 0x28eae4 -> 0x357f2c
 *   0x28e578 mov r1,r5            json argument = NULL
 *   0x28e57c mov r0,r8            parser
 *   0x28e580 ldr r3,[r7,#0x1c]    extra = the attachment timeline's name
 *   0x28e584 add r2,pc,r2
 *   0x28e588 bl _spSkeletonJson_setError
 *   0x28e58c b 0x28da44           -> 0x28da48 spSkeletonData_dispose(data)
 *                                    0x28da4c mov r0,#0 ; b 0x28bdcc (NULL)
 *
 * The json argument is NULL, not the animation node (the bones/path shape) and
 * not the root tree (the slots shape for E1): r5 is loaded from r8, and r8 can
 * only be 0 on the single edge that reaches this block.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_attachmentNotFound(Json* attachmentNode, void* data_raw,
                                    void* animation_raw, void* parser_raw)
{
    spAnimation_dispose((spAnimation*)animation_raw);              /* 0x28e570 */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             0,                                    /* 0x28e578 */
                             ERR_ATTACHMENT_NOT_FOUND,             /* 0x28e574/0x28e584 */
                             attachmentNode->name);                /* 0x28e580 */
    spSkeletonData_dispose((spSkeletonData*)data_raw);             /* 0x28da48 */
    return DRAWORDER_TL_ERROR;                                     /* 0x28da4c/0x28da50 */
}
