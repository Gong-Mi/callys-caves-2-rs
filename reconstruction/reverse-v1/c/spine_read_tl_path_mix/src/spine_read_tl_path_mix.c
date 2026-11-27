/*
 * spine_read_tl_path_mix.c — B17, the path-constraint MIX timeline block of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 *   0x28e8ec..0x28ea0c  73 instructions / 292 B, reached only through
 *   B13's 0x28e538 `bne 0x28e8ec` (any path sub-key that is neither
 *   "position" nor "spacing").
 *
 * The puzzle — "a node named exactly 'mix' is skipped by the block that
 * builds mix timelines" — is answered by 0x28e8fc `beq 0x28e048`: the target
 * is the shared timeline-node advance (0x28e048 ldr r4,[r4]; 0x28e04c cmp;
 * 0x28e050 bne back to 0x28df3c), i.e. a silent `continue`.  No other block
 * in the function looks at the name "mix" for a path node, and B13 only
 * compares "position"/"spacing", so a "mix" child is handled by NOBODY.  Every
 * other name falls through and IS loaded as a mix timeline.  See the header
 * for the full derivation, including the corrected key-literal arithmetic
 * (0x357cc0 "rotateMix", not a +4 "teMix").
 *
 * Evidence tier: bytecode_anchored.  The original was never executed; PASS on
 * the fixture is a scoped reconstructed-consumer verdict, not an
 * original-equivalence claim.  No stock spine-c source was consulted.
 */

#include "spine_read_tl_path_mix.h"

#include "../../spine_read_curve/src/spine_read_curve.h"   /* readCurve 0x28b34c */

/*
 * ---------------------------------------------------------------------------
 * B17 body, instruction by instruction.
 *
 * Entry state handed over by B13:
 *   r4  = timelineNode          [0x28df30 ldr r4,[r10,#0x4]; 0x28df3c ldr r6,[r4,#0x1c]]
 *   r6  = timelineNode->name    (+0x1c)
 *   r11 = animation
 *   [sp+0x2c] = the index cell written by B13's scan (0x28df2c), read here at
 *               0x28e914 — B17 never rewrites it.
 *   [sp+0x48] = "mix" (0x357c98; B13 materialised it at 0x28deb4/0x28dec4 and
 *               spilled it at 0x28ded0)
 *
 *   0x28e8ec mov r0,r6             strcmp(name, "mix")
 *   0x28e8f0 ldr r1,[sp,#0x48]
 *   0x28e8f4 bl strcmp
 *   0x28e8f8 cmp r0,#0
 *   0x28e8fc beq 0x28e048         name == "mix" -> node advance, no timeline
 *   --- create ---
 *   0x28e900 ldr r0,[r4,#0xc]     declared frame count (Json+0x0c)
 *   0x28e904 bl spPathConstraintMixTimeline_create
 *   0x28e908 ldr r5,[r4,#0x4]     frame = timelineNode->child
 *   0x28e90c cmp r5,#0
 *   0x28e910 mov r6,r0            r6 = timeline
 *   0x28e914 ldr r0,[sp,#0x2c]    the B13 cell
 *   0x28e918 str r0,[r6,#0x14]    +0x14 store runs BEFORE the NULL test
 *   0x28e91c beq 0x28e9cc         no frames -> publish tail
 *   --- key material, once ---
 *   0x28e920 ldr r8,[pc,#0x1e8] / 0x28e934 add r8,pc,r8     "time"       (0x34c1d4)
 *   0x28e928 ldr r1,[pc,#0x1e4] / 0x28e938 add r1,pc,r1     "rotateMix"  (0x357cc0)
 *   0x28e930 ldr r2,[pc,#0x1e0] / 0x28e940 add r2,pc,r2     "translateMix"(0x357ccc)
 *   0x28e93c str r1,[sp,#0x30] / 0x28e944 str r2,[sp,#0x34]
 *   0x28e924 mov r7,#0            frameIndex = 0
 *   0x28e92c mov r12,r4           node kept for the tail
 *   --- frame loop, head 0x28e948, back edge 0x28e9c4 ---
 *   0x28e948 mov r0,r5 / 0x28e94c mov r1,r8 / 0x28e950 mov r2,#0
 *   0x28e954 str r12,[sp,#0x14] / 0x28e958 bl Json_getFloat   time (0.0f default)
 *   0x28e95c ldr r1,[sp,#0x30] / 0x28e960 mov r2,#1065353216
 *   0x28e964 mov r3,r0 / 0x28e968 mov r0,r5 / 0x28e96c str r3,[sp,#0x10]
 *   0x28e970 bl Json_getFloat                                  rotateMix (1.0f default)
 *   0x28e974 ldr r1,[sp,#0x34] / 0x28e978 mov r2,#1065353216
 *   0x28e97c mov r4,r0 / 0x28e980 mov r0,r5
 *   0x28e984 bl Json_getFloat                                  translateMix (1.0f default)
 *   0x28e988 ldr r3,[sp,#0x10] / 0x28e98c mov r1,r7 / 0x28e990 mov r2,r3
 *   0x28e994 mov r3,r4 / 0x28e998 str r0,[sp] / 0x28e99c mov r0,r6
 *   0x28e9a0 bl spPathConstraintMixTimeline_setFrame(timeline, frameIndex,
 *                                                     time, rotateMix, translateMix)
 *   0x28e9a4 mov r0,r5 / 0x28e9a8 mov r2,r7 / 0x28e9ac mov r1,r6
 *   0x28e9b0 bl readCurve(frame, timeline, frameIndex)
 *   0x28e9b4 ldr r5,[r5]          frame = frame->next
 *   0x28e9b8 add r7,r7,#1
 *   0x28e9bc ldr r12,[sp,#0x14] / 0x28e9c0 cmp r5,#0 / 0x28e9c4 bne 0x28e948
 *   --- publish/duration tail 0x28e9cc..0x28ea0c ---
 *   0x28e9cc ldr r2,[r4,#0xc]     declared count (re-read, not cached)
 *   0x28e9d0 vldr s14,[r11,#4]    animation->duration
 *   0x28e9d4 ldr r3,[r11,#0x8]    animation->timelineCount
 *   0x28e9d8 ldr r1,[r11,#0xc]    animation->timelines
 *   0x28e9dc sub r2,r2,#1
 *   0x28e9e0 add r0,r3,#1 / 0x28e9e4 str r0,[r11,#0x8]
 *   0x28e9e8 add r2,r2,r2,lsl#1   (declared-1)*3  <-- THREE-float stride
 *   0x28e9ec str r6,[r1,r3,lsl#2] timelines[count] = timeline
 *   0x28e9f0 ldr r3,[r6,#0x10]    frames
 *   0x28e9f4 add r3,r3,r2,lsl#2   &frames[(declared-1)*3]
 *   0x28e9f8 vldr s15,[r3]        last = the last frame's TIME
 *   0x28e9fc vcmpe.f32 s14,s15 / 0x28ea00 vmrs / 0x28ea04 vmovgt.f32
 *   0x28ea08 vstr s15,[r11,#4]    duration = max(duration, last)
 *   0x28ea0c b 0x28e048           shared node advance
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_pathMixTimeline(Json* timelineNode,
                                 int32_t path_constraint_index,
                                 void* animation_raw)
{
    spAnimationMixShape* animation = (spAnimationMixShape*)animation_raw;
    spPathConstraintTimelineMixShape* timeline;
    Json* frame;
    int frameIndex;

    /* 0x28e8ec mov r0,r6 ; 0x28e8f0 ldr r1,[sp,#0x48] ;
     * 0x28e8f4 bl strcmp ; 0x28e8f8 cmp r0,#0 ; 0x28e8fc beq 0x28e048.
     * Every other name falls through.  This guard is the puzzle: see header. */
    if (strcmp(timelineNode->name, "mix") == 0)
        return MIX_TL_SKIPPED;

    /* 0x28e900 ldr r0,[r4,#0xc] ; 0x28e904 bl
     * spPathConstraintMixTimeline_create(declared) */
    timeline = (spPathConstraintTimelineMixShape*)
        spPathConstraintMixTimeline_create((int)timelineNode->unk_0c);

    /* 0x28e908 ldr r5,[r4,#0x4] — timelineNode->child.
     * 0x28e910 mov r6,r0 — r6 is the timeline from here on.
     * 0x28e914 ldr r0,[sp,#0x2c] / 0x28e918 str r0,[r6,#0x14] — the index
     * store is UNCONDITIONAL: it precedes the frame-list test at 0x28e91c. */
    frame = timelineNode->child;
    timeline->pathConstraintIndex = path_constraint_index;

    /* 0x28e90c cmp r5,#0 ; 0x28e91c beq 0x28e9cc — no frames: publish only. */
    if (frame != 0) {
        frameIndex = 0;                                  /* 0x28e924 mov r7,#0 */
        do {
            /* 0x28e948..0x28e958 — "time", default 0.0f (0x28e950 mov r2,#0) */
            float time = Json_getFloat(frame, "time", 0.0f);

            /* 0x28e95c..0x28e970 — "rotateMix", default 1.0f
             * (0x28e960 mov r2,#1065353216).  Key VA 0x357cc0, resolved from
             * pool 0x28eb14 by the add at 0x28e938 (PC base 0x28e940). */
            float rotateMix = Json_getFloat(frame, "rotateMix", 1.0f);

            /* 0x28e974..0x28e984 — "translateMix", default 1.0f
             * (0x28e978 mov r2,#1065353216).  Key VA 0x357ccc, pool 0x28eb18,
             * add 0x28e940 (PC base 0x28e948). */
            float translateMix = Json_getFloat(frame, "translateMix", 1.0f);

            /* 0x28e988..0x28e9a0 — r0=timeline r1=frameIndex r2=time
             * r3=rotateMix [sp]=translateMix; 5th AAPCS word on the stack. */
            spPathConstraintMixTimeline_setFrame((void*)timeline, frameIndex,
                                                 time, rotateMix, translateMix);

            /* 0x28e9a4..0x28e9b0 — readCurve(frame, timeline, frameIndex),
             * the anonymous 0x28b34c.  This is B17's OWN call site; B13's is
             * 0x28dff4. */
            readCurve(frame, (void*)timeline, frameIndex);

            frame = frame->next;                         /* 0x28e9b4 ldr r5,[r5] */
            ++frameIndex;                                /* 0x28e9b8 add r7,r7,#1 */
        } while (frame != 0);                            /* 0x28e9c0 cmp / 0x28e9c4 bne */
    }

    {
        /* 0x28e9cc ldr r2,[r4,#0xc] — declared count, re-read after the loop. */
        uint32_t declared = timelineNode->unk_0c;
        float duration = animation->duration;            /* 0x28e9d0 vldr s14,[r11,#4] */
        int32_t count = animation->timelineCount;        /* 0x28e9d4 ldr r3,[r11,#8] */
        void** timelines = animation->timelines;         /* 0x28e9d8 ldr r1,[r11,#0xc] */
        uint32_t word_index;
        float last;

        animation->timelineCount = count + 1;            /* 0x28e9e0 add / 0x28e9e4 str */
        timelines[count] = (void*)timeline;              /* 0x28e9ec str r6,[r1,r3,lsl#2] */

        /* 0x28e9dc sub r2,r2,#1 ; 0x28e9e8 add r2,r2,r2,lsl#1 ; 0x28e9f4 lsl#2
         * — the three-float stride.  declared == 0 wraps to frames[-3]. */
        word_index = (declared - 1u) * 3u;
        last = timeline->frames[word_index];             /* 0x28e9f0..0x28e9f8 */

        /* 0x28e9fc vcmpe.f32 s14,s15 ; 0x28ea04 vmovgt.f32 s15,s14 —
         * strictly greater only; an unordered compare (NaN) keeps `last`. */
        if (duration > last)
            last = duration;

        animation->duration = last;                      /* 0x28ea08 vstr s15,[r11,#4] */
    }

    return MIX_TL_PUBLISHED;                             /* 0x28ea0c b 0x28e048 */
}
