/*
 * spine_read_tl_ik.c — ik-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B7   0x28d840..0x28d8dc   39 insns  ik loop head + findIkConstraint +
 *                                        create + pointer linear scan
 *   B7b  0x28dbd0..0x28dca8   54 insns  frame loop + setFrame + readCurve +
 *                                        publish/duration tail + back edge
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted: the key set ("time"/"mix"/"bendPositive"), the
 * threefold frame stride, the +0x3c/+0x40 data words and the +0x14 write are
 * all read off the instruction stream (census §2.5 / §6 / §7 open #6).
 */

#include "spine_read_tl_ik.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */

/*
 * ---------------------------------------------------------------------------
 * B7 index scan: 0x28d898..0x28d8dc, with the hit store island at
 * 0x28dbc8/0x28dbcc (placed after the shear-timeline block, which ends with an
 * unconditional `b 0x28d740` at 0x28dbc4, so the two words are reachable only
 * by branch).
 *
 *   0x28d898 ldr r0,[sp,#0x18]       r0 = data          (spill reload)
 *   0x28d89c ldr r1,[r0,#0x3c]       r1 = data->ikConstraintsCount  (SNAPSHOT:
 *                                    read once, never re-read in the loop)
 *   0x28d8a0 cmp r1,#0
 *   0x28d8a4 ble 0x28dbd0            SIGNED count <= 0 -> no scan, no +0x14
 *                                    write, straight to the frame loop.  The
 *                                    array word at +0x40 is NOT read at all.
 *   0x28d8a8 ldr r2,[r0,#0x40]       r2 = data->ikConstraints
 *   0x28d8ac ldr r3,[r2]             e = array[0]; r3 is reused as the element
 *                                    register (this is why the [0] hit needs
 *                                    the out-of-line store island)
 *   0x28d8b0 cmp r5,r3               compare the findIkConstraint result
 *   0x28d8b4 movne r3,#0             index = 0            (element test failed)
 *   0x28d8b8 bne 0x28d8cc            -> increment path
 *   0x28d8bc b 0x28dbc8              element 0 matched: r3 still holds the
 *                                    POINTER here, so the island must clear it
 *   0x28dbc8 mov r3,#0               index = 0
 *   0x28dbcc str r3,[r6,#0x14]       timeline->constraintIndex = index
 *   --- walk (r3 == index of the element about to be loaded) ---
 *   0x28d8c0 ldr r0,[r2,#0x4]!       r2 += 4; e = *r2   (pre-index writeback:
 *                                    the element is re-read from memory on
 *                                    every iteration, the array is not cached)
 *   0x28d8c4 cmp r5,r0
 *   0x28d8c8 beq 0x28dbcc            matched -> store r3 (the current index)
 *   0x28d8cc add r3,r3,#1            index++
 *   0x28d8d0 cmp r3,r1               compare against the count SNAPSHOT
 *   0x28d8d4 bne 0x28d8c0            equality only: `bne`, not `blt`
 *   0x28d8d8 b 0x28dbd0              miss -> frame loop, +0x14 untouched
 *
 * Consequences that follow from the instruction stream and are exercised by
 * the fixture:
 *   - the lookup result is never null-tested (0x28d888 mov r5,r0 is followed
 *     directly by the create call), so a NULL result simply never compares
 *     equal to a non-NULL array element and the scan misses;
 *   - count <= 0 (including a negative count) skips the scan entirely, and
 *     data->ikConstraints may then be NULL or garbage without a fault;
 *   - a hit at element 0 must store 0, a hit at element i must store i;
 *   - a miss stores NOTHING: +0x14 keeps whatever create left there.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_ikConstraintIndex(void* data_raw, void* ik_raw, void* timeline_raw)
{
    spSkeletonDataIkShape* data = (spSkeletonDataIkShape*)data_raw;
    spIkConstraintTimelineShape* timeline = (spIkConstraintTimelineShape*)timeline_raw;
    void* ik = ik_raw;                                  /* 0x28d888 mov r5,r0 */
    int32_t count;
    void** array;
    void* element;
    int32_t index;

    count = data->ikConstraintsCount;                   /* 0x28d898 / 0x28d89c */
    if (count <= 0)                                     /* 0x28d8a0 cmp / 0x28d8a4 ble */
        return 0;                                       /* 0x28d8a4 ble 0x28dbd0 */

    array = data->ikConstraints;                        /* 0x28d8a8 */
    element = array[0];                                 /* 0x28d8ac */
    if (ik == element) {                                /* 0x28d8b0 cmp r5,r3 */
        timeline->ikConstraintIndex = 0;                /* 0x28dbc8 mov r3,#0 ; 0x28dbcc str */
        return 1;                                       /* 0x28d8bc b 0x28dbc8 */
    }

    index = 0;                                          /* 0x28d8b4 movne r3,#0 */
    for (;;) {
        ++index;                                        /* 0x28d8cc add r3,r3,#1 */
        if (index == count)                             /* 0x28d8d0 cmp r3,r1 */
            return 0;                                   /* 0x28d8d4 bne fall-through -> 0x28d8d8 */
        element = array[index];                         /* 0x28d8c0 ldr r0,[r2,#0x4]! */
        if (ik == element) {                            /* 0x28d8c4 cmp r5,r0 */
            timeline->ikConstraintIndex = index;        /* 0x28d8c8 beq 0x28dbcc ; 0x28dbcc str */
            return 1;
        }
    }
}

/*
 * ---------------------------------------------------------------------------
 * B7b frame loop, 0x28dbd0..0x28dc58 (r4 = the current ik constraint node,
 * r6 = the timeline, r10 = "time" cached at 0x28d868, [sp+0x2c] = "mix",
 * [sp+0x30] = "bendPositive"):
 *
 *   0x28dbd0 ldr r5,[r4,#0x4]        frame = constraintNode->child
 *   0x28dbd4 cmp r5,#0
 *   0x28dbd8 movne r7,#0             frameIndex = 0 only when frames exist
 *   0x28dbdc beq 0x28dc5c            no frames -> tail
 *   0x28dbe0 mov r0,r5               frame
 *   0x28dbe4 mov r1,r10              "time"
 *   0x28dbe8 mov r2,#0               default 0.0f
 *   0x28dbec bl Json_getFloat        time
 *   0x28dbf0 ldr r1,[sp,#0x2c]       "mix"
 *   0x28dbf4 mov r2,#1065353216      default 1.0f (0x3f800000)
 *   0x28dbfc..0x28dc00 bl Json_getFloat    mix
 *   0x28dc04 ldr r1,[sp,#0x30]       "bendPositive"
 *   0x28dc08 mov r2,#1               default 1
 *   0x28dc14 bl Json_getInt          bend key read
 *   0x28dc18 mov r1,r7               arg2 = frameIndex
 *   0x28dc1c mov r2,r9               arg3 = time bits
 *   0x28dc20 mov r3,r8               arg4 = mix bits
 *   0x28dc24 cmp r0,#0
 *   0x28dc28 mov r0,r6               arg1 = timeline
 *   0x28dc2c mvneq r12,#0            bend == 0 -> -1
 *   0x28dc30 movne r12,#1            otherwise  -> +1
 *   0x28dc34 str r12,[sp]            arg5 (stack) = the signed enum
 *   0x28dc38 bl spIkConstraintTimeline_setFrame
 *   0x28dc3c mov r0,r5               readCurve(frame, ...)
 *   0x28dc40 mov r2,r7               ... frameIndex)
 *   0x28dc44 mov r1,r6               ... timeline)
 *   0x28dc48 bl readCurve            anonymous 0x28b34c
 *   0x28dc4c ldr r5,[r5]             frame = frame->next
 *   0x28dc50 add r7,r7,#1            frameIndex++
 *   0x28dc54 cmp r5,#0
 *   0x28dc58 bne 0x28dbe0            loop on the frame list, not on the count
 *
 * The enum stored into frames[i*3+2] is (float)(int)bend, applied inside the
 * synthetic setFrame (0x282f90 vcvt.f32.s32).  The B7b caller therefore has to
 * pass an INTEGER -1/+1, never a float: the compare at 0x28dc24 is on the raw
 * getInt result, so any non-zero value (e.g. 5) becomes +1.
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_ikTimelineFrames(Json* constraintNode, void* timeline_raw)
{
    spIkConstraintTimelineShape* timeline = (spIkConstraintTimelineShape*)timeline_raw;
    Json* frame = constraintNode->child;                /* 0x28dbd0 */
    int frameIndex;

    if (frame != 0) {                                   /* 0x28dbd4 / 0x28dbdc beq */
        frameIndex = 0;                                 /* 0x28dbd8 movne r7,#0 */
        do {
            float time = Json_getFloat(frame, "time", 0.0f);        /* 0x28dbe0..0x28dbec */
            float mix = Json_getFloat(frame, "mix", 1.0f);          /* 0x28dbf0..0x28dc00 */
            int bend = Json_getInt(frame, "bendPositive", 1);       /* 0x28dc04..0x28dc14 */
            int bend_enum = (bend == 0) ? -1 : 1;                   /* 0x28dc24..0x28dc30 */

            spIkConstraintTimeline_setFrame((void*)timeline, frameIndex, /* 0x28dc18..0x28dc28 */
                                            time, mix, bend_enum);       /* 0x28dc1c/0x28dc20/0x28dc34 */
            readCurve(frame, (void*)timeline, frameIndex);         /* 0x28dc3c..0x28dc48 */
            frame = frame->next;                                   /* 0x28dc4c ldr r5,[r5] */
            ++frameIndex;                                          /* 0x28dc50 add r7,r7,#1 */
        } while (frame != 0);                                      /* 0x28dc54 / 0x28dc58 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * B7 head + B7b tail driver, 0x28d840..0x28d8dc and 0x28dbd0..0x28dca8.
 *
 *   0x28d840 ldr r3,[sp,#0x34]       ikMap = the "ik" JSON child
 *   0x28d844 cmp r3,#0
 *   0x28d848 beq 0x28dca8            no "ik" member -> transform block
 *   0x28d84c ldr r1,[sp,#0x34]       (redundant reload, kept in the C as the
 *   0x28d850 ldr r4,[r1,#0x4]         child load it is)
 *   0x28d854 cmp r4,#0
 *   0x28d858 beq 0x28dca8            no constraints -> transform block
 *   0x28d85c..0x28d878               three key literals materialised once,
 *                                    outside the loop:
 *                                      r10         = "time"         (0x28d868,
 *                                                    pool 0x28ca48 -> 0x34c1d4)
 *                                      [sp+0x2c]   = "mix"          (0x28d870,
 *                                                    pool 0x28ca4c -> 0x357c98)
 *                                      [sp+0x30]   = "bendPositive" (0x28d878,
 *                                                    pool 0x28ca50 -> 0x357c88)
 *   --- constraint loop, head 0x28d87c, back edge 0x28dca4 ---
 *   0x28d87c ldr r1,[r4,#0x1c]       name = ikMap->name (the member key)
 *   0x28d880 ldr r0,[sp,#0x18]       data
 *   0x28d884 bl spSkeletonData_findIkConstraint
 *   0x28d888 mov r5,r0               result kept in r5, NO NULL TEST
 *   0x28d88c ldr r0,[r4,#0xc]        declared frame count
 *   0x28d890 bl spIkConstraintTimeline_create
 *   0x28d894 mov r6,r0               timeline
 *   (scan, then frames — both under the same loop iteration)
 *   --- tail 0x28dc5c..0x28dca4 ---
 *   0x28dc5c ldr r2,[r4,#0xc]        declared frame count
 *   0x28dc60 vldr s14,[r11,#4]       duration
 *   0x28dc64 ldr r3,[r11,#0x8]       timelineCount
 *   0x28dc68 ldr r1,[r11,#0xc]       timelines
 *   0x28dc6c sub r2,r2,#1            frameCount-1 (unsigned wrap preserved)
 *   0x28dc70 add r0,r3,#1
 *   0x28dc74 str r0,[r11,#0x8]       timelineCount = count+1
 *   0x28dc78 add r2,r2,r2,lsl#1      (frameCount-1)*3  <- THREEFOLD stride
 *   0x28dc7c str r6,[r1,r3,lsl#2]    timelines[count] = timeline
 *   0x28dc80 ldr r3,[r6,#0x10]       frames
 *   0x28dc84 ldr r4,[r4]             ikMap = ikMap->next
 *   0x28dc88 add r3,r3,r2,lsl#2      &frames[(frameCount-1)*3]
 *   0x28dc8c vldr s15,[r3]           last
 *   0x28dc90/0x28dc94 vcmpe/vmrs
 *   0x28dc98 vmovgt.f32 s15,s14      duration keeps the larger value
 *   0x28dc9c cmp r4,#0               the next pointer is tested AFTER the
 *   0x28dca0 vstr s15,[r11,#4]       duration store — the store is
 *                                    unconditional on the last iteration
 *   0x28dca4 bne 0x28d87c
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_ikTimelines(Json* ikMap, void* data_raw, void* animation_raw)
{
    spAnimationIkShape* animation = (spAnimationIkShape*)animation_raw;
    Json* constraintNode;

    if (ikMap == 0)                                     /* 0x28d840..0x28d848 */
        return 1;                                       /* 0x28d848 beq 0x28dca8 */
    constraintNode = ikMap->child;                      /* 0x28d84c..0x28d850 */
    if (constraintNode == 0)                            /* 0x28d854 cmp */
        return 1;                                       /* 0x28d858 beq 0x28dca8 */

    while (constraintNode != 0) {                       /* 0x28d87c head / 0x28dca4 bne */
        void* ik;
        spIkConstraintTimelineShape* timeline;
        Json* next;
        int32_t count;
        uint32_t declared;
        uint32_t word_index;
        float duration;
        float last;
        void** timelines;

        ik = spSkeletonData_findIkConstraint(data_raw, constraintNode->name); /* 0x28d87c..0x28d884 */
        timeline = (spIkConstraintTimelineShape*)
            spIkConstraintTimeline_create((int)constraintNode->unk_0c);      /* 0x28d88c..0x28d894 */

        /* 0x28d898..0x28d8d8: both exits of the scan fall through to 0x28dbd0.
         * The return value is not part of the original ABI. */
        (void)readSkeletonData_ikConstraintIndex(data_raw, ik, (void*)timeline);

        readSkeletonData_ikTimelineFrames(constraintNode, (void*)timeline);   /* 0x28dbd0..0x28dc58 */

        declared = constraintNode->unk_0c;              /* 0x28dc5c ldr r2,[r4,#0xc] */
        duration = animation->duration;                 /* 0x28dc60 vldr s14,[r11,#4] */
        count = animation->timelineCount;               /* 0x28dc64 ldr r3,[r11,#0x8] */
        timelines = animation->timelines;               /* 0x28dc68 ldr r1,[r11,#0xc] */
        next = constraintNode->next;                    /* 0x28dc84 ldr r4,[r4] */
        word_index = (declared - 1u) * 3u;              /* 0x28dc6c sub / 0x28dc78 add r2,r2,r2,lsl#1 */

        animation->timelineCount = count + 1;           /* 0x28dc70 / 0x28dc74 */
        timelines[count] = (void*)timeline;             /* 0x28dc7c str r6,[r1,r3,lsl#2] */
        last = timeline->frames[word_index];            /* 0x28dc80..0x28dc8c */
        animation->duration = (duration > last) ? duration : last; /* 0x28dc90..0x28dca0 */

        constraintNode = next;                          /* 0x28dc84 */
    }
    return 1;                                           /* 0x28dca4 not taken */
}
