/*
 * spine_read_tl_transform.c — transform-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B12  0x28dca8..0x28de74   115 insns  transform loop head + find + create
 *                                        + pointer linear scan + five-key
 *                                        frame loop + setFrame + readCurve
 *                                        + publish/duration tail + back edge
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted: the key set
 * ("time"/"rotateMix"/"translateMix"/"scaleMix"/"shearMix"), the FIVE-float
 * frame stride, the +0x44/+0x48 data words and the +0x14 write are all read
 * off the instruction stream (census §2.6 / §6 / §7 open #6).
 */

#include "spine_read_tl_transform.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */

/*
 * ---------------------------------------------------------------------------
 * B12 index scan: 0x28dd1c..0x28dd68.  The hit store is 0x28dd64, in-line
 * (unlike the ik family's out-of-line island at 0x28dbc8/0x28dbcc); the
 * index-0 hit reaches it through 0x28dd40 b 0x28dd60 / 0x28dd60 mov r3,#0.
 *
 *   0x28dd1c ldr r0,[sp,#0x18]       r0 = data          (spill reload)
 *   0x28dd20 ldr r1,[r0,#0x44]       r1 = data->transformConstraintsCount
 *                                    (SNAPSHOT: read once, never re-read)
 *   0x28dd24 cmp r1,#0
 *   0x28dd28 ble 0x28dd68            SIGNED count <= 0 -> no scan, no +0x14
 *                                    write, straight to the frame-load at
 *                                    0x28dd68.  The +0x48 array word is NOT
 *                                    read at all.
 *   0x28dd2c ldr r2,[r0,#0x48]       r2 = data->transformConstraints
 *   0x28dd30 ldr r3,[r2]             e = array[0]; r3 is reused as the element
 *                                    register (this is why the [0] hit needs
 *                                    the 0x28dd60 clear before the store)
 *   0x28dd34 cmp r4,r3               compare the findTransformConstraint result
 *   0x28dd38 movne r3,#0             index = 0            (element test failed)
 *   0x28dd3c bne 0x28dd50            -> increment path
 *   0x28dd40 b 0x28dd60              element 0 matched: r3 still holds the
 *                                    POINTER here
 *   0x28dd60 mov r3,#0               index = 0
 *   0x28dd64 str r3,[r6,#0x14]       timeline->constraintIndex = index
 *   --- walk (r3 == index of the element about to be loaded) ---
 *   0x28dd44 ldr r0,[r2,#0x4]!       r2 += 4; e = *r2   (pre-index writeback:
 *                                    the element is re-read from memory on
 *                                    every iteration, the array is not cached)
 *   0x28dd48 cmp r4,r0
 *   0x28dd4c beq 0x28dd64            matched -> store r3 (the current index)
 *   0x28dd50 add r3,r3,#1            index++
 *   0x28dd54 cmp r3,r1               compare against the count SNAPSHOT
 *   0x28dd58 bne 0x28dd44            equality only: `bne`, not `blt`
 *   0x28dd5c b 0x28dd68              miss -> frame load, +0x14 untouched
 *
 * Consequences that follow from the instruction stream and are exercised by
 * the fixture:
 *   - the lookup result is never null-tested (0x28dd0c mov r4,r0 is followed
 *     directly by 0x28dd10 ldr r0,[r5,#0xc] and the create call), so a NULL
 *     result simply never compares equal to a non-NULL array element and the
 *     scan misses — unless a NULL slot exists in the vector, which matches;
 *   - count <= 0 (including a negative count) skips the scan entirely, and
 *     data->transformConstraints may then be NULL or garbage without a fault;
 *   - a hit at element 0 must store 0, a hit at element i must store i;
 *   - a miss stores NOTHING: +0x14 keeps whatever create left there.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_transformConstraintIndex(void* data_raw, void* transform_raw,
                                          void* timeline_raw)
{
    spSkeletonDataTransformShape* data = (spSkeletonDataTransformShape*)data_raw;
    spTransformConstraintTimelineShape* timeline =
        (spTransformConstraintTimelineShape*)timeline_raw;
    void* transform = transform_raw;                    /* 0x28dd0c mov r4,r0 */
    int32_t count;
    void** array;
    void* element;
    int32_t index;

    count = data->transformConstraintsCount;            /* 0x28dd20 */
    if (count <= 0)                                     /* 0x28dd24 cmp / 0x28dd28 ble */
        return 0;                                       /* 0x28dd28 ble 0x28dd68 */

    array = data->transformConstraints;                 /* 0x28dd2c */
    element = array[0];                                 /* 0x28dd30 ldr r3,[r2] */
    if (transform == element) {                         /* 0x28dd34 cmp r4,r3 */
        timeline->transformConstraintIndex = 0;         /* 0x28dd40 b 0x28dd60 ; 0x28dd60 mov r3,#0 ; 0x28dd64 str */
        return 1;                                       /* 0x28dd40 b 0x28dd60 */
    }

    index = 0;                                          /* 0x28dd38 movne r3,#0 */
    for (;;) {
        ++index;                                        /* 0x28dd50 add r3,r3,#1 */
        if (index == count)                             /* 0x28dd54 cmp r3,r1 */
            return 0;                                   /* 0x28dd58 bne fall-through -> 0x28dd5c */
        element = array[index];                         /* 0x28dd44 ldr r0,[r2,#0x4]! */
        if (transform == element) {                     /* 0x28dd48 cmp r4,r0 */
            timeline->transformConstraintIndex = index; /* 0x28dd4c beq 0x28dd64 ; 0x28dd64 str r3,[r6,#0x14] */
            return 1;
        }
    }
}

/*
 * ---------------------------------------------------------------------------
 * B12 frame loop, 0x28dd68..0x28de24 (r5 = the current transform-constraint
 * node, r6 = the timeline, r12/[sp+0x14] = the node preserved across the loop,
 * [sp+0x2c] = "time", [sp+0x30] = "rotateMix", [sp+0x34] = "translateMix",
 * [sp+0x38] = "scaleMix", [sp+0x3c] = "shearMix"):
 *
 *   0x28dd68 ldr r4,[r5,#0x4]        frame = constraintNode->child
 *   0x28dd6c cmp r4,#0
 *   0x28dd70 movne r7,#0             frameIndex = 0 only when frames exist
 *   0x28dd74 movne r12,r5            node preserved for the tail
 *   0x28dd78 beq 0x28de28            no frames -> tail
 *   0x28dd7c mov r0,r4               frame
 *   0x28dd80 ldr r1,[sp,#0x2c]       "time"
 *   0x28dd84 mov r2,#0               default 0.0f
 *   0x28dd8c bl Json_getFloat        time              -> r9 (0x28dd98)
 *   0x28dd90..0x28dda0               "rotateMix", default 1.0f (0x28dd94
 *                                    mov r2,#1065353216) -> r8 (0x28ddac)
 *   0x28dda4..0x28ddb4               "translateMix", default 1.0f -> r5 (0x28ddc0)
 *   0x28ddb8..0x28ddc8               "scaleMix", default 1.0f -> r10 (0x28ddd4)
 *   0x28ddcc..0x28dddc               "shearMix", default 1.0f -> r0 (stays)
 *   0x28dde0 mov r1,r7               arg2 = frameIndex
 *   0x28dde4 mov r2,r9               arg3 = time bits
 *   0x28dde8 mov r3,r8               arg4 = rotateMix bits
 *   0x28ddec str r5,[sp]             arg5 (stack) = translateMix bits
 *   0x28ddf0 str r10,[sp,#0x4]       arg6 (stack) = scaleMix bits
 *   0x28ddf4 str r0,[sp,#0x8]        arg7 (stack) = shearMix bits
 *   0x28ddf8 mov r0,r6               arg1 = timeline
 *   0x28ddfc bl spTransformConstraintTimeline_setFrame
 *   0x28de00 mov r0,r4               readCurve(frame, ...)
 *   0x28de04 mov r2,r7               ... frameIndex)
 *   0x28de08 mov r1,r6               ... timeline)
 *   0x28de0c bl readCurve            anonymous 0x28b34c
 *   0x28de10 ldr r4,[r4]             frame = frame->next
 *   0x28de14 add r7,r7,#1            frameIndex++
 *   0x28de18 ldr r12,[sp,#0x14]      restore the node (r5 held translateMix)
 *   0x28de1c cmp r4,#0
 *   0x28de20 bne 0x28dd7c            loop on the frame list, not on the count
 *   0x28de24 mov r5,r12              r5 = constraint node for the tail
 *
 * Difference against the ik frame loop worth stating: r5 is used as the
 * translateMix scratch register (0x28ddc0), so the node has to survive in r12
 * and be restored on the loop exit.  A no-frames node never executes the
 * movne r12,r5 at 0x28dd74 and reaches the tail with r5 still the node.
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_transformTimelineFrames(Json* constraintNode, void* timeline_raw)
{
    spTransformConstraintTimelineShape* timeline =
        (spTransformConstraintTimelineShape*)timeline_raw;
    Json* frame = constraintNode->child;                /* 0x28dd68 ldr r4,[r5,#0x4] */
    int frameIndex;

    if (frame != 0) {                                   /* 0x28dd6c / 0x28dd78 beq */
        frameIndex = 0;                                 /* 0x28dd70 movne r7,#0 */
        do {
            float time = Json_getFloat(frame, "time", 0.0f);              /* 0x28dd7c..0x28dd8c */
            float rotateMix = Json_getFloat(frame, "rotateMix", 1.0f);    /* 0x28dd90..0x28dda0 */
            float translateMix = Json_getFloat(frame, "translateMix", 1.0f); /* 0x28dda4..0x28ddb4 */
            float scaleMix = Json_getFloat(frame, "scaleMix", 1.0f);      /* 0x28ddb8..0x28ddc8 */
            float shearMix = Json_getFloat(frame, "shearMix", 1.0f);      /* 0x28ddcc..0x28dddc */

            spTransformConstraintTimeline_setFrame((void*)timeline, frameIndex, /* 0x28dde0..0x28ddf8 */
                                                   time, rotateMix,
                                                   translateMix, scaleMix,
                                                   shearMix);              /* 0x28ddec..0x28ddf4 */
            readCurve(frame, (void*)timeline, frameIndex);                 /* 0x28de00..0x28de0c */
            frame = frame->next;                                            /* 0x28de10 ldr r4,[r4] */
            ++frameIndex;                                                   /* 0x28de14 add r7,r7,#1 */
        } while (frame != 0);                                              /* 0x28de1c / 0x28de20 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * B12 driver, 0x28dca8..0x28de74.
 *
 *   0x28dca8 ldr r0,[sp,#0x38]       transformMap = the "transform" JSON child
 *   0x28dcac cmp r0,#0
 *   0x28dcb0 beq 0x28de74            no "transform" member -> path block
 *   0x28dcb4 ldr r2,[sp,#0x38]       (redundant reload, kept as the child load)
 *   0x28dcb8 ldr r5,[r2,#0x4]        node = transformMap->child
 *   0x28dcbc cmp r5,#0
 *   0x28dcc0 beq 0x28de74            no constraints -> path block
 *   0x28dcc4..0x28dcfc               five key literals materialised once,
 *                                    outside the loop:
 *                                      [sp+0x2c] = "time"         (0x28dcd4)
 *                                      [sp+0x30] = "rotateMix"    (0x28dcec)
 *                                      [sp+0x34] = "translateMix" (0x28dcf4)
 *                                      [sp+0x38] = "scaleMix"     (0x28dcf8)
 *                                      [sp+0x3c] = "shearMix"     (0x28dcfc)
 *                                    (note 0x28dcf8 overwrites the transformMap
 *                                     stack slot only after its last read)
 *   --- constraint loop, head 0x28dd00, back edge 0x28de70 ---
 *   0x28dd00 ldr r1,[r5,#0x1c]       name = node->name (the member key)
 *   0x28dd04 ldr r0,[sp,#0x18]       data
 *   0x28dd08 bl spSkeletonData_findTransformConstraint
 *   0x28dd0c mov r4,r0               result kept in r4, NO NULL TEST
 *   0x28dd10 ldr r0,[r5,#0xc]        declared frame count
 *   0x28dd14 bl spTransformConstraintTimeline_create
 *   0x28dd18 mov r6,r0               timeline
 *   (scan 0x28dd1c..0x28dd68, then frames 0x28dd68..0x28de24)
 *   --- tail 0x28de28..0x28de70 ---
 *   0x28de28 ldr r2,[r5,#0xc]        declared frame count
 *   0x28de2c vldr s14,[r11,#4]       duration
 *   0x28de30 ldr r3,[r11,#0x8]       timelineCount
 *   0x28de34 ldr r1,[r11,#0xc]       timelines
 *   0x28de38 sub r2,r2,#1            frameCount-1 (unsigned wrap preserved)
 *   0x28de3c add r0,r3,#1
 *   0x28de40 str r0,[r11,#0x8]       timelineCount = count+1
 *   0x28de44 add r2,r2,r2,lsl#2      (frameCount-1)*5  <- FIVEFOLD stride
 *   0x28de48 str r6,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28de4c ldr r3,[r6,#0x10]       frames
 *   0x28de50 ldr r5,[r5]             node = node->next
 *   0x28de54 add r3,r3,r2,lsl#2      &frames[(frameCount-1)*5]
 *   0x28de58 vldr s15,[r3]           last
 *   0x28de5c/0x28de60 vcmpe.f32 s14,s15 / vmrs APSR_nzcv,fpscr
 *   0x28de64 vmovgt.f32 s15,s14      duration keeps the larger value
 *   0x28de68 cmp r5,#0               the next pointer is tested AFTER the
 *   0x28de6c vstr s15,[r11,#4]       duration store — the store is
 *                                    unconditional on the last iteration
 *   0x28de70 bne 0x28dd00
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_transformTimelines(Json* transformMap, void* data_raw,
                                    void* animation_raw)
{
    spAnimationTransformShape* animation = (spAnimationTransformShape*)animation_raw;
    Json* constraintNode;

    if (transformMap == 0)                              /* 0x28dca8..0x28dcb0 */
        return 1;                                       /* 0x28dcb0 beq 0x28de74 */
    constraintNode = transformMap->child;               /* 0x28dcb4..0x28dcb8 */
    if (constraintNode == 0)                            /* 0x28dcbc cmp */
        return 1;                                       /* 0x28dcc0 beq 0x28de74 */

    while (constraintNode != 0) {                       /* 0x28dd00 head / 0x28de70 bne */
        void* transform;
        spTransformConstraintTimelineShape* timeline;
        Json* next;
        int32_t count;
        uint32_t declared;
        uint32_t word_index;
        float duration;
        float last;
        void** timelines;

        transform = spSkeletonData_findTransformConstraint(data_raw, constraintNode->name); /* 0x28dd00..0x28dd08 */
        timeline = (spTransformConstraintTimelineShape*)
            spTransformConstraintTimeline_create((int)constraintNode->unk_0c);              /* 0x28dd10..0x28dd14 */

        /* 0x28dd1c..0x28dd64: both exits of the scan fall through to 0x28dd68.
         * The return value is not part of the original ABI. */
        (void)readSkeletonData_transformConstraintIndex(data_raw, transform, (void*)timeline);

        readSkeletonData_transformTimelineFrames(constraintNode, (void*)timeline);          /* 0x28dd68..0x28de24 */

        declared = constraintNode->unk_0c;              /* 0x28de28 ldr r2,[r5,#0xc] */
        duration = animation->duration;                 /* 0x28de2c vldr s14,[r11,#4] */
        count = animation->timelineCount;               /* 0x28de30 ldr r3,[r11,#0x8] */
        timelines = animation->timelines;               /* 0x28de34 ldr r1,[r11,#0xc] */
        next = constraintNode->next;                    /* 0x28de50 ldr r5,[r5] */
        word_index = (declared - 1u) * 5u;              /* 0x28de38 sub / 0x28de44 add r2,r2,lsl#2 */

        animation->timelineCount = count + 1;           /* 0x28de3c / 0x28de40 */
        timelines[count] = (void*)timeline;             /* 0x28de48 str r6,[r1,r3,lsl#2] */
        last = timeline->frames[word_index];            /* 0x28de4c..0x28de58 */
        animation->duration = (duration > last) ? duration : last; /* 0x28de5c..0x28de6c */

        constraintNode = next;                          /* 0x28de50 */
    }
    return 1;                                           /* 0x28de70 not taken -> 0x28de74 */
}
