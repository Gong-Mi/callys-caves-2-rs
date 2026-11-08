/*
 * spine_read_tl_path_mix.h — the path-constraint MIX timeline block of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 *   B17  0x28e8ec..0x28ea0c  73 insns / 292 B
 *        Reached ONLY from B13's 0x28e538 `bne 0x28e8ec`: every path
 *        sub-key that is neither "position" nor "spacing" lands here.
 *        Loop head 0x28e948, readCurve call site 0x28e9b0, its own
 *        create/setFrame pair 0x283068/0x283080, a THREE-float frame
 *        stride (0x28e9e8 add r2,r2,r2,lsl#1) and its own publish tail
 *        0x28e9cc..0x28ea0c before jumping back to the shared node
 *        advance 0x28e048.
 *
 * The census block 0x28e8ec..0x28ea88 (412 B / 103 insns) is NOT one
 * block.  This module translates only the 73 instructions above; the other
 * 30 are out-of-line islands owned by earlier blocks, each entered from a
 * branch OUTSIDE the range (verified in the instruction stream):
 *
 *   0x28ea10..0x28ea3c (12)  B5 slot-not-found error block, entered from
 *                            0x28d538 beq 0x28ea10 (r2 = [sp+0x2c] is the
 *                            slot Json node there, 0x28ea2c ldr r3,[r2,#0x1c])
 *   0x28ea40..0x28ea44 (2)   B4 timeline-count dispatch island, entered from
 *                            0x28d3c8 beq 0x28ea40 (r3 = 0)
 *   0x28ea48..0x28ea70 (11)  E7 "Path constraint not found: ", entered from
 *                            0x28dee4 beq 0x28ea48; already translated by
 *                            c/spine_read_tl_path
 *   0x28ea74..0x28ea7c (3)   B13 spacing-scale island (parser->scale), entered
 *                            from 0x28e550 bls 0x28ea74; already translated by
 *                            c/spine_read_tl_path
 *   0x28ea80..0x28ea84 (2)   B4 dispatch island (r3 = [sp+0x30]), entered from
 *                            0x28d3bc beq 0x28ea80
 *
 * Consequently B17 has NO error block of its own: its BL roster is only
 * strcmp / create / Json_getFloat x3 / setFrame / readCurve (pinned by the
 * checker).  It also has NO constraint lookup and NO index scan: it consumes
 * the [sp+0x2c] cell that B13's scan wrote (0x28e914 ldr r0,[sp,#0x2c]) and
 * stores it into the new timeline (0x28e918 str r0,[r6,#0x14]) BEFORE the
 * frame-list NULL test.
 *
 * ---------------------------------------------------------------------------
 * THE "name == mix IS SKIPPED" PUZZLE — DETERMINED FROM THE INSTRUCTION STREAM
 * ---------------------------------------------------------------------------
 * B13's dispatch:
 *   0x28df54 bne 0x28e52c        name != "position"  -> re-test spacing
 *   0x28e530 bl strcmp(name,"spacing")
 *   0x28e538 bne 0x28e8ec        name != "spacing"   -> B17
 * B17's first sequence:
 *   0x28e8ec mov r0,r6           r6 = timelineNode->name
 *   0x28e8f0 ldr r1,[sp,#0x48]   [sp+0x48] = "mix" (B13 spilled it at 0x28ded0)
 *   0x28e8f4 bl strcmp
 *   0x28e8f8 cmp r0,#0
 *   0x28e8fc beq 0x28e048        EQUAL -> the shared timeline-node advance
 *   0x28e048 ldr r4,[r4]         timelineNode = timelineNode->next
 *   0x28e04c cmp r4,#0
 *   0x28e050 bne 0x28df3c        B13's inner loop head
 *
 * So the answer is: NOBODY handles a sub-key named exactly "mix".
 *   0x28e8fc's target is not another handler; it is the same node-advance
 *   instruction (0x28e048 ldr r4,[r4]) that every published timeline tail
 *   jumps to (0x28e9cc..0x28ea0c falls into it).  A "mix" node is silently
 *   skipped: no create, no setFrame, no readCurve, no publish, no duration
 *   update, no error.  The inverse is the sharper half: every OTHER
 *   unresolvable name ("rotate", "bogus", a typo, ...) falls through and is
 *   loaded as a mix timeline.  The compiled guard is literally
 *   `if (strcmp(name,"mix") == 0) goto next;` i.e. the body runs when the
 *   name is NOT "mix" — a missing `== 0` at source level is the natural
 *   explanation, recorded here as a hypothesis about intent, not as bytecode
 *   evidence.  The instruction-level conclusion does not depend on it.
 *
 * The fixture pins both directions at run time: a "mix" child contributes
 * nothing, while a sibling named anything else is created and published; the
 * two orders ("mix" before / after the other name) give the same result.
 *
 * ---------------------------------------------------------------------------
 * KEY LITERALS — the "+4 suffix" claim does NOT hold
 * ---------------------------------------------------------------------------
 * All three loop keys are materialised at 0x28e920..0x28e944 and spilled:
 *   pool        load       add        PC base     resolved VA   text
 *   0x28eb10    0x28e920   0x28e934   0x28e93c    0x34c1d4      "time"
 *   0x28eb14    0x28e928   0x28e938   0x28e940    0x357cc0      "rotateMix"
 *   0x28eb18    0x28e930   0x28e940   0x28e948    0x357ccc      "translateMix"
 * The add site for the second key is 0x28e938 (`add r1,pc,r1`), whose PC base
 * is 0x28e940; 0x28e93c is `str r1,[sp,#0x30]`, not an add.  Therefore the
 * resolved pointer is the START of "rotateMix" (0x357cc0), shared with B12's
 * transform family, and NOT "rotateMix"+4 ("teMix" @0x357cc4).  The earlier
 * c/spine_read_tl_path checker used 0x28e93c as the add site and consequently
 * reported a +4 suffix; that was an off-by-one-instruction decode.  This
 * module's checker pins the true add site and additionally re-resolves the
 * B12 site 0x28dcd8 (pool 0x28ea9c) to 0x357cc0, proving plain string sharing.
 *
 * Defaults, read from the `mov r2,#imm` operands at the three call sites:
 *   "time"         default 0.0f  (0x28e950 mov r2,#0)
 *   "rotateMix"    default 1.0f  (0x28e960 mov r2,#1065353216)
 *   "translateMix" default 1.0f  (0x28e978 mov r2,#1065353216)
 *
 * Evidence tier: bytecode_anchored; the original was never executed and no
 * original-equivalence claim is made.  Every statement in the .c carries the
 * original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getFloat                 c/json_interface
 *   readCurve                     c/spine_read_curve (0x28b34c, anonymous)
 *   _malloc/_free/_calloc         c/spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spPathConstraintMixTimeline_create 0x283068 / 24 B
 *        tail call _spBaseTimeline_create(count, 13, 3, tag):
 *        0x28306c mov r1,#13 (timeline type word)
 *        0x283070 mov r2,#3  (frame step = 3 floats per frame)
 *        0x283078 b 0x282a10
 *   spPathConstraintMixTimeline_setFrame 0x283080 / 48 B
 *        ABI read off the body: r0 = timeline, r1 = frameIndex, r2 = time bits,
 *        r3 = rotateMix bits, [sp] = translateMix bits (5th AAPCS word).
 *        Store shape (0x283080..0x2830ac), stride 3:
 *          frames[i*3+0] = time
 *          frames[i*3+1] = rotateMix   (0x2830a4 str r3,[r0])
 *          frames[i*3+2] = translateMix(0x2830a0 str r4,[r0,#0x4])
 *        (the original stores the 5th argument before the 4th; order is not
 *        observable, the fixture records both words.)
 *   spCurveTimeline_setStepped / spCurveTimeline_setCurve (0x2817c0/0x2817d8)
 *        readCurve's dependencies, defined as recorders by the fixture.
 */

#ifndef YY_SPINE_READ_TL_PATH_MIX_H
#define YY_SPINE_READ_TL_PATH_MIX_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spPathConstraintTimeline as observed by B17 and by the real creator pair:
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0]]
 *   +0x04 vtable object   [0x281354 str r0,[r4,#0x4]]
 *   +0x08 float* curves   [_spCurveTimeline_init 0x281710, (frameCount-1)*19]
 *   +0x0c frameFloatCount [0x282a70 str r0,[r4,#0xc] = frameCount * step]
 *   +0x10 float* frames   [0x282a78 str r0,[r4,#0x10]; 3 floats per frame]
 *   +0x14 int32 pathConstraintIndex  [B17 writer: 0x28e918 str r0,[r6,#0x14]]
 *
 * +0x14 is inside the creator's calloc(1,24,tag,233) (0x282a30/0x282a40) and
 * none of _spBaseTimeline_create (0x282a10..0x282a88), _spCurveTimeline_init
 * (0x2816d8..0x281714) or _spTimeline_init (0x281328..0x28135c) stores to it;
 * the create-time value is the calloc zero fill.  B17 overwrites it
 * unconditionally (the store runs before the frame-list NULL test at
 * 0x28e91c), so no path leaves the create-time value in place.
 */
typedef struct spPathConstraintTimelineMixShape {
    uint32_t type;                 /* +0x00 */
    void*    vtable;               /* +0x04 */
    float*   curves;               /* +0x08 (frameCount-1)*19 floats */
    int32_t  frameFloatCount;      /* +0x0c frameCount * 3 */
    float*   frames;               /* +0x10 3 floats per frame */
    int32_t  pathConstraintIndex;  /* +0x14 written unconditionally at 0x28e918 */
} spPathConstraintTimelineMixShape;

/*
 * spAnimation fields touched by the tail.  Full record owned by
 * spAnimation_create/spAnimation_dispose (c/spine_skeleton_data).
 */
typedef struct spAnimationMixShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read at 0x28e9d0, written at 0x28ea08 */
    int32_t timelineCount;  /* +0x08 read at 0x28e9d4, written at 0x28e9e4 */
    void**  timelines;      /* +0x0c read at 0x28e9d8, written at 0x28e9ec */
} spAnimationMixShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spPathConstraintTimelineMixShape, frames) == 0x10,
               "0x28e9f0 ldr r3,[r6,#0x10] / 0x283084 ldr r0,[r0,#0x10]");
_Static_assert(offsetof(spPathConstraintTimelineMixShape, pathConstraintIndex) == 0x14,
               "0x28e918 str r0,[r6,#0x14]");
_Static_assert(sizeof(spPathConstraintTimelineMixShape) == 24,
               "0x282a30 mov r1,#24 calloc");
_Static_assert(offsetof(spAnimationMixShape, duration) == 0x04,
               "0x28e9d0 vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationMixShape, timelineCount) == 0x08,
               "0x28e9d4 ldr r3,[r11,#0x8]");
_Static_assert(offsetof(spAnimationMixShape, timelines) == 0x0c,
               "0x28e9d8 ldr r1,[r11,#0xc]");
#endif

/* The creator's own type/step words (0x28306c mov r1,#13 / 0x283070 mov r2,#3). */
#define SPINE_MIX_TIMELINE_TYPE 13
#define SPINE_MIX_FRAME_STEP    3

/* Declared synthetic boundaries (see the block comment above). */
extern void* spPathConstraintMixTimeline_create(int frameCount);
extern void spPathConstraintMixTimeline_setFrame(void* timeline, int frameIndex,
                                                 float time, float rotateMix,
                                                 float translateMix);

/* Driver return codes.  Both original exits go to the shared node advance
 * 0x28e048 (ldr r4,[r4]); the code only makes the two paths observable. */
#define MIX_TL_SKIPPED   0   /* 0x28e8fc beq 0x28e048: name IS "mix" */
#define MIX_TL_PUBLISHED 1   /* 0x28ea0c b 0x28e048: timeline created/published */

/*
 * B17, 0x28e8ec..0x28ea0c.
 *   timelineNode        : the path sub-timeline Json node (B13's r4).  Reads
 *                         +0x1c name, +0x0c declared count, +0x04 child list.
 *   path_constraint_index: models the [sp+0x2c] stack cell written by B13's
 *                         scan (0x28df2c).  B17 only reads it (0x28e914) and
 *                         stores it at timeline+0x14 (0x28e918); a miss value
 *                         carried over from a previous constraint arrives here
 *                         unchanged, exactly as it would on the stack.
 *   animation_raw       : spAnimation* (B13's r11) — duration, timelineCount,
 *                         timelines.  No spSkeletonData and no spSkeletonJson
 *                         argument exists for this block.
 * Returns MIX_TL_SKIPPED or MIX_TL_PUBLISHED.
 */
int readSkeletonData_pathMixTimeline(Json* timelineNode,
                                     int32_t path_constraint_index,
                                     void* animation_raw);

#endif /* YY_SPINE_READ_TL_PATH_MIX_H */
