/*
 * spine_read_tl_path.c — path-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B), libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 *   B13  0x28de74..0x28e060  123 insns  paths loop head + findPathConstraint
 *                                        -> pointer linear scan -> strcmp
 *                                        dispatch (position / spacing) ->
 *                                        shared frame loop + publish tail
 *        islands            0x28e52c..0x28e558 and 0x28ea74 (spacing create and
 *                           the two scale selects)
 *
 * B13 stops at 0x28e538 `bne 0x28e8ec`: the third sub-key belongs to the mix
 * block B17 (0x28e8ec..0x28ea88), which has its own loop head 0x28e948, its own
 * readCurve call site 0x28e9b0 and a three-float frame stride (0x28e9e8
 * add r2,r2,r2,lsl#1) instead of B13's two (0x28e030 add r3,r3,r2,lsl#3).
 * This module therefore REPORTS that handoff (PATH_TL_HANDOFF_MIX) instead of
 * translating B17.
 *
 * Evidence tier: bytecode_anchored; the original was never executed.  No stock
 * spine-c source was consulted: the key set ("position"/"spacing"/"time"), the
 * value-key-is-the-node-name trick, the two-float frame stride, the
 * +0x4c/+0x50 data words and the +0x14 store are all read off the instruction
 * stream (census §2.6 / §6 B13 / §7 opens #6, #12).
 */

#include "spine_read_tl_path.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */
#include "../../spine_json_error/src/spine_json_error.h"   /* _spSkeletonJson_setError 0x28b784 */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h" /* dispose pair */

#define ERR_PATH_NOT_FOUND "Path constraint not found: "

/* The two frame strides, both fixed by the creators' own tail calls. */
#define PATH_POSITION_STEP 2   /* 0x283018 mov r2,#2 */
#define PATH_SPACING_STEP  2   /* 0x283044 mov r2,#2 */

/*
 * ---------------------------------------------------------------------------
 * B13 index scan: 0x28dee8..0x28df30.  The hit store at 0x28df2c is inline
 * (unlike ik's 0x28dbc8 island: here `mov r3,#0` at 0x28df04 is shared with the
 * miss path, so the store can be reached straight from 0x28df0c / 0x28df18).
 *
 *   0x28dee8 ldr r2,[sp,#0x18]       r2 = data          (spill reload)
 *   0x28deec ldr r1,[r2,#0x4c]       r1 = data->pathConstraintsCount  (SNAPSHOT)
 *   0x28def0 cmp r1,#0
 *   0x28def4 ble 0x28df30            SIGNED count <= 0 -> no scan, the cell is
 *                                    left as it was, +0x50 is NOT read
 *   0x28def8 ldr r2,[r2,#0x50]       r2 = data->pathConstraints
 *   0x28defc ldr r3,[r2]             e = array[0]
 *   0x28df00 cmp r9,r3               r9 = the findPathConstraint result
 *   0x28df04 mov r3,#0               index = 0   (ALWAYS executed)
 *   0x28df08 bne 0x28df1c            element test failed -> increment path
 *   0x28df0c b 0x28df2c              element 0 matched: r3 already holds 0
 *   --- walk ---
 *   0x28df10 ldr r0,[r2,#0x4]!       r2 += 4; e = *r2 (pre-index writeback)
 *   0x28df14 cmp r9,r0
 *   0x28df18 beq 0x28df2c            matched -> store the current index
 *   0x28df1c add r3,r3,#1            index++
 *   0x28df20 cmp r3,r1               against the count SNAPSHOT
 *   0x28df24 bne 0x28df10            equality only
 *   0x28df28 b 0x28df30              miss -> frame prologue
 *   0x28df2c str r3,[sp,#0x2c]       THE CELL, not the timeline
 *
 * Consequences the fixture pins:
 *   - a hit at element 0 stores 0 (0x28df04 already cleared r3, no fixup needed);
 *   - a hit at element i stores i;
 *   - a hit at the LAST element (i == count-1) still stores, because the
 *     `bne` at 0x28df24 is only evaluated after the increment;
 *   - a miss stores nothing, so the cell keeps the value the PREVIOUS path
 *     constraint left there — 0 for the first one, a stale index afterwards;
 *   - count <= 0 skips everything, so the +0x50 array word is never read.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_pathConstraintIndex(void* data_raw, void* pc_raw,
                                     int32_t* index_cell)
{
    spSkeletonDataPathShape* data = (spSkeletonDataPathShape*)data_raw;
    int32_t count;
    void** array;
    void* element;
    int32_t index;

    count = data->pathConstraintsCount;                /* 0x28deec */
    if (count <= 0)                                    /* 0x28def0 cmp / 0x28def4 ble */
        return 0;                                      /* 0x28def4 ble 0x28df30 */

    array = data->pathConstraints;                     /* 0x28def8 */
    element = array[0];                                /* 0x28defc */
    if (pc_raw == element) {                           /* 0x28df00 cmp r9,r3 */
        *index_cell = 0;                               /* 0x28df04 mov r3,#0 ; 0x28df2c str */
        return 1;                                      /* 0x28df0c b 0x28df2c */
    }

    index = 0;                                         /* 0x28df04 */
    for (;;) {
        ++index;                                       /* 0x28df1c */
        if (index == count)                            /* 0x28df20 */
            return 0;                                  /* 0x28df28 b 0x28df30 */
        element = array[index];                        /* 0x28df10 ldr r0,[r2,#0x4]! */
        if (pc_raw == element) {                       /* 0x28df14 */
            *index_cell = index;                       /* 0x28df18 beq 0x28df2c ; 0x28df2c str */
            return 1;
        }
    }
}

/*
 * ---------------------------------------------------------------------------
 * position scale select, 0x28df68..0x28df88 (reached only from the "position"
 * branch of the dispatch; the two instructions at 0x28e554/0x28e558 are the
 * shared 1.0f arm used by both selects).
 *
 *   0x28df68 ldr r0,[r4,#0xc]      declared frame count
 *   0x28df6c bl spPathConstraintPositionTimeline_create
 *   0x28df70 ldr r3,[r9,#0x10]     positionMode
 *   0x28df74 cmp r3,#0
 *   0x28df78 mov r8,r0             timeline (r8 for the rest of the iteration)
 *   0x28df7c bne 0x28e554          NON-zero mode -> 1.0f
 *   0x28df80 ldr r1,[sp,#0x20]     parser
 *   0x28df84 vldr s16,[r1]         s16 = parser->scale (+0x00)
 *   ...
 *   0x28e554 vmov.f32 s16,#1.0
 *   0x28e558 b 0x28df88
 *
 * So a position timeline is scaled by the skeleton scale only in mode 0; the
 * "percent" mode (1) is already relative and must not be scaled again.
 * ---------------------------------------------------------------------------
 */
float
readSkeletonData_pathPositionScale(const void* parser_raw, const void* pc_raw)
{
    const spPathConstraintDataPathShape* pc = (const spPathConstraintDataPathShape*)pc_raw;

    if (pc->positionMode != 0)                         /* 0x28df70 / 0x28df74 / 0x28df7c bne */
        return 1.0f;                                   /* 0x28e554 vmov.f32 s16,#1.0 */
    return spSkeletonJson_path_scale_float((const spSkeletonJson*)parser_raw);
                                                       /* 0x28df80 ldr r1,[sp,#0x20] ; 0x28df84 vldr s16,[r1] */
}

/*
 * ---------------------------------------------------------------------------
 * spacing scale select, 0x28e52c..0x28e558 and 0x28ea74..0x28ea7c.
 *
 *   0x28e52c ldr r1,[sp,#0x44]     the second "spacing" literal
 *   0x28e530 bl strcmp             strcmp(node->name, "spacing")
 *   0x28e534 cmp r0,#0
 *   0x28e538 bne 0x28e8ec          NOT "spacing" -> B17 (mix family)
 *   0x28e53c ldr r0,[r4,#0xc]      declared frame count
 *   0x28e540 bl spPathConstraintSpacingTimeline_create
 *   0x28e544 ldr r3,[r9,#0x14]     spacingMode
 *   0x28e548 cmp r3,#1
 *   0x28e54c mov r8,r0             timeline
 *   0x28e550 bls 0x28ea74          UNSIGNED mode <= 1 -> parser->scale
 *   0x28e554 vmov.f32 s16,#1.0     (fall-through for mode >= 2)
 *   0x28e558 b 0x28df88
 *   ...
 *   0x28ea74 ldr r0,[sp,#0x20]     parser
 *   0x28ea78 vldr s16,[r0]         s16 = parser->scale
 *   0x28ea7c b 0x28df88
 *
 * `bls` is unsigned, so mode 0 (length) and 1 (fixed) scale, while 2 (percent),
 * 3 (proportional) and any negative value do not.
 * ---------------------------------------------------------------------------
 */
float
readSkeletonData_pathSpacingScale(const void* parser_raw, const void* pc_raw)
{
    const spPathConstraintDataPathShape* pc = (const spPathConstraintDataPathShape*)pc_raw;

    if ((uint32_t)pc->spacingMode <= 1u)               /* 0x28e544 / 0x28e548 / 0x28e550 bls */
        return spSkeletonJson_path_scale_float((const spSkeletonJson*)parser_raw);
                                                       /* 0x28ea74 / 0x28ea78 */
    return 1.0f;                                       /* 0x28e554 */
}

/*
 * ---------------------------------------------------------------------------
 * B13 frame loop, 0x28dfa4..0x28e00c (r5 = the current frame, r8 = the
 * timeline, s16 = the scale, r6 = the sub-key name, r7 = frameIndex):
 *
 *   0x28dfa4 mov r0,r5              frame
 *   0x28dfa8 ldr r1,[sp,#0x3c]      "time"
 *   0x28dfac mov r2,#0              default 0.0f
 *   0x28dfb0 str r12,[sp,#0x14]     spill the timeline node (r4 is reused below)
 *   0x28dfb4 bl Json_getFloat       time
 *   0x28dfb8 mov r1,r6              VALUE KEY = the sub-key name ("position"/"spacing")
 *   0x28dfbc mov r2,#0              default 0.0f
 *   0x28dfc0 mov r4,r0              r4 = time bits
 *   0x28dfc4 mov r0,r5              frame
 *   0x28dfc8 bl Json_getFloat       value
 *   0x28dfcc mov r1,r7              arg2 = frameIndex
 *   0x28dfd0 mov r2,r4              arg3 = time bits
 *   0x28dfd4 vmov s14,r0            s14 = value
 *   0x28dfd8 mov r0,r8              arg1 = timeline
 *   0x28dfdc vmul.f32 s15,s14,s16   value * scale  (executed even for 1.0f)
 *   0x28dfe0 vmov r3,s15            arg4 = scaled value bits
 *   0x28dfe4 bl spPathConstraintPositionTimeline_setFrame
 *   0x28dfe8 mov r0,r5              readCurve(frame, ...)
 *   0x28dfec mov r2,r7              ... frameIndex)
 *   0x28dff0 mov r1,r8              ... timeline)
 *   0x28dff4 bl readCurve           anonymous 0x28b34c
 *   0x28dff8 ldr r5,[r5]            frame = frame->next
 *   0x28dffc add r7,r7,#1           frameIndex++
 *   0x28e000 ldr r12,[sp,#0x14]
 *   0x28e004 cmp r5,#0
 *   0x28e008 bne 0x28dfa4           loop on the frame list, not on the count
 *
 * The setFrame call target is the POSITION symbol for both families (see the
 * header): the spacing family's own 0x283054 body is byte-identical
 * (e5900010 e080c181 e58c2000 e58c3004 e12fff1e) but is never called here.
 * ---------------------------------------------------------------------------
 */
void
readSkeletonData_pathTimelineFrames(Json* timelineNode, void* timeline_raw,
                                    float scale)
{
    spPathConstraintTimelineShape* timeline = (spPathConstraintTimelineShape*)timeline_raw;
    Json* frame = timelineNode->child;                 /* 0x28df88 ldr r5,[r4,#0x4] */
    int frameIndex;

    if (frame != 0) {                                  /* 0x28df90 cmp / 0x28dfa0 beq */
        frameIndex = 0;                                /* 0x28df98 movne r7,#0 */
        do {
            float time = Json_getFloat(frame, "time", 0.0f);            /* 0x28dfa4..0x28dfb4 */
            float value = Json_getFloat(frame, timelineNode->name, 0.0f); /* 0x28dfb8..0x28dfc8 */
            float scaled = value * scale;                               /* 0x28dfdc */

            spPathConstraintPositionTimeline_setFrame((void*)timeline, frameIndex,
                                                      time, scaled);    /* 0x28dfe4 */
            readCurve(frame, (void*)timeline, frameIndex);              /* 0x28dff4 */
            frame = frame->next;                                        /* 0x28dff8 */
            ++frameIndex;                                               /* 0x28dffc */
        } while (frame != 0);                                           /* 0x28e008 */
    }
}

/*
 * ---------------------------------------------------------------------------
 * E7, 0x28ea48..0x28ea70 plus the shared tail 0x28da44..0x28da50.
 * Read per block: the json argument is the CURRENT ANIMATION NODE (r1 =
 * [sp+0x1c], which 0x28d2c8 set to animations->child), not the root tree and
 * not NULL; the extra string is the path node's member key (r3 = [r10,#0x1c]).
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_pathConstraintNotFound(Json* pathNode, Json* animationJson,
                                        void* data_raw, void* animation_raw,
                                        void* parser_raw)
{
    spAnimation_dispose((spAnimation*)animation_raw);               /* 0x28ea54 */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             animationJson,                         /* 0x28ea60 ldr r1,[sp,#0x1c] */
                             ERR_PATH_NOT_FOUND,                    /* 0x28ea58 / 0x28ea68 */
                             pathNode->name);                       /* 0x28ea64 ldr r3,[r10,#0x1c] */
    spSkeletonData_dispose((spSkeletonData*)data_raw);              /* 0x28da48 */
    return PATH_TL_ERROR;                                           /* 0x28da4c..0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * B13 driver: 0x28de74..0x28e060 and the out-of-line islands.
 *
 *   0x28de74 ldr r1,[sp,#0x44]     paths node
 *   0x28de78 cmp r1,#0
 *   0x28de7c beq 0x28e060          absent -> deform block
 *   0x28de80 ldr r2,[sp,#0x44]     (redundant reload, kept as the load it is)
 *   0x28de84 ldr r10,[r2,#0x4]     pathNode = paths->child
 *   0x28de88 cmp r10,#0
 *   0x28de8c beq 0x28e060          no children -> deform block
 *   0x28de90..0x28ded0             five key literals materialised once:
 *       [sp+0x38] "position" (0x28de90/0x28de9c, pool 0x28eaac -> 0x357d80)
 *       [sp+0x3c] "time"     (0x28de98/0x28dea8, pool 0x28eab0 -> 0x34c1d4)
 *       [sp+0x40] "spacing"  (0x28deac/0x28deb8, pool 0x28eab4 -> 0x357d8c)
 *       [sp+0x44] "spacing"  (0x28deb0/0x28debc, pool 0x28eab8 -> 0x357d8c)
 *       [sp+0x48] "mix"      (0x28deb4/0x28dec4, pool 0x28eabc -> 0x357c98)
 *   0x28de94/0x28dea0 mov r0,#0 ; str r0,[sp,#0x2c]   index cell = 0, ONCE
 *   --- outer loop, head 0x28ded4, back edge 0x28e05c ---
 *   0x28ded4 ldr r0,[sp,#0x18]     data
 *   0x28ded8 ldr r1,[r10,#0x1c]    pathNode->name
 *   0x28dedc bl spSkeletonData_findPathConstraint
 *   0x28dee0 subs r9,r0,#0         <-- NULL TEST (ik/transform have none)
 *   0x28dee4 beq 0x28ea48          E7 error path
 *   (scan writes [sp+0x2c])
 *   0x28df30 ldr r4,[r10,#0x4]     timelineNode = pathNode->child
 *   --- inner loop, head 0x28df3c, back edge 0x28e050 ---
 *   0x28df3c ldr r6,[r4,#0x1c]     sub-key
 *   0x28df40..0x28df54             strcmp(name,"position"); non-zero -> 0x28e52c
 *   0x28df58..0x28df64             strcmp(name,"spacing");  zero -> 0x28e53c
 *        (0x28e52c..0x28e538 re-tests "spacing" and sends everything else to
 *         0x28e8ec, i.e. to B17 — the two "spacing" literals exist because the
 *         compiler duplicated the compare for the two entry points)
 *   --- per-timeline prologue 0x28df88 ---
 *   0x28df88 ldr r5,[r4,#0x4]      frames
 *   0x28df8c ldr r2,[sp,#0x2c]     index cell
 *   0x28df90 cmp r5,#0
 *   0x28df94 str r2,[r8,#0x14]     pathConstraintIndex — UNCONDITIONAL
 *   0x28df98/0x28df9c              frameIndex = 0, save the node in r12
 *   0x28dfa0 beq 0x28e010          no frames -> tail (the +0x14 store still ran)
 *   (frame loop 0x28dfa4..0x28e00c)
 *   --- tail 0x28e010..0x28e050 ---
 *   0x28e010 ldr r3,[r11,#0x8]     timelineCount
 *   0x28e014 vldr s14,[r11,#4]     duration
 *   0x28e018 ldr r1,[r11,#0xc]     timelines
 *   0x28e01c/0x28e020              timelineCount = count+1
 *   0x28e024 ldr r2,[r4,#0xc]      DECLARED frame count
 *   0x28e028 str r8,[r1,r3,lsl#2]  timelines[count] = timeline
 *   0x28e02c ldr r3,[r8,#0x10]     frames
 *   0x28e030 add r3,r3,r2,lsl#3    frames + declared*8  <- TWO-float stride
 *   0x28e034 vldr s15,[r3,#-8]     frames[(declared-1)*2]
 *   0x28e038/0x28e03c vcmpe/vmrs
 *   0x28e040 vmovgt.f32 s15,s14
 *   0x28e044 vstr s15,[r11,#4]     duration = max
 *   0x28e048 ldr r4,[r4]           timelineNode = timelineNode->next
 *   0x28e04c cmp / 0x28e050 bne    inner loop
 *   0x28e054 ldr r10,[r10]         pathNode = pathNode->next
 *   0x28e058 cmp / 0x28e05c bne    outer loop
 *   0x28e060                       deform block (not this module)
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_pathTimelines(Json* paths_map, Json* animation_json,
                               void* data_raw, void* animation_raw,
                               void* parser_raw)
{
    spAnimationPathShape* animation = (spAnimationPathShape*)animation_raw;
    Json* pathNode;
    int32_t index_cell;

    if (paths_map == 0)                                /* 0x28de74..0x28de7c */
        return PATH_TL_REACHED_DEFORM;                 /* 0x28de7c beq 0x28e060 */

    pathNode = paths_map->child;                       /* 0x28de80..0x28de84 */
    if (pathNode == 0)                                 /* 0x28de88 cmp */
        return PATH_TL_REACHED_DEFORM;                 /* 0x28de8c beq 0x28e060 */

    index_cell = 0;                                    /* 0x28de94 mov r0,#0 ; 0x28dea0 str */

    while (pathNode != 0) {                            /* 0x28ded4 head / 0x28e05c bne */
        void* pc;
        Json* timelineNode;

        pc = spSkeletonData_findPathConstraint(data_raw, pathNode->name);
                                                       /* 0x28ded4..0x28dedc */
        if (pc == 0)                                   /* 0x28dee0 subs r9,r0,#0 */
            return readSkeletonData_pathConstraintNotFound(pathNode, animation_json,
                                                           data_raw, animation_raw,
                                                           parser_raw);  /* 0x28ea48 */

        (void)readSkeletonData_pathConstraintIndex(data_raw, pc, &index_cell);
                                                       /* 0x28dee8..0x28df2c */

        timelineNode = pathNode->child;                /* 0x28df30 */
        while (timelineNode != 0) {                    /* 0x28df3c / 0x28e050 bne */
            spPathConstraintTimelineShape* timeline;
            float scale;

            if (strcmp(timelineNode->name, "position") == 0) {
                                                       /* 0x28df40..0x28df54 */
                timeline = (spPathConstraintTimelineShape*)
                    spPathConstraintPositionTimeline_create((int)timelineNode->unk_0c);
                                                       /* 0x28df68..0x28df6c */
                scale = readSkeletonData_pathPositionScale(parser_raw, pc);
                                                       /* 0x28df70..0x28df84 */
            } else if (strcmp(timelineNode->name, "spacing") == 0) {
                                                       /* 0x28df58..0x28df64 */
                timeline = (spPathConstraintTimelineShape*)
                    spPathConstraintSpacingTimeline_create((int)timelineNode->unk_0c);
                                                       /* 0x28e53c..0x28e540 */
                scale = readSkeletonData_pathSpacingScale(parser_raw, pc);
                                                       /* 0x28e544..0x28e550 / 0x28ea74 */
            } else {
                return PATH_TL_HANDOFF_MIX;            /* 0x28e538 bne 0x28e8ec (B17) */
            }

            timeline->pathConstraintIndex = index_cell; /* 0x28df8c ldr r2,[sp,#0x2c] ;
                                                        * 0x28df94 str r2,[r8,#0x14] */
            readSkeletonData_pathTimelineFrames(timelineNode, (void*)timeline, scale);
                                                       /* 0x28df88..0x28e00c */

            {
                /* tail 0x28e010..0x28e044 */
                int32_t count = animation->timelineCount;      /* 0x28e010 */
                float duration = animation->duration;          /* 0x28e014 */
                void** timelines = animation->timelines;       /* 0x28e018 */
                uint32_t declared = timelineNode->unk_0c;      /* 0x28e024 */
                float last;

                animation->timelineCount = count + 1;          /* 0x28e01c/0x28e020 */
                timelines[count] = (void*)timeline;            /* 0x28e028 */
                last = timeline->frames[declared * 2u - 2u];   /* 0x28e02c..0x28e034 */
                animation->duration = (duration > last) ? duration : last;
                                                               /* 0x28e038..0x28e044 */
            }

            timelineNode = timelineNode->next;         /* 0x28e048 */
        }

        pathNode = pathNode->next;                     /* 0x28e054 */
    }

    return PATH_TL_REACHED_DEFORM;                     /* 0x28e058 / 0x28e05c not taken */
}
