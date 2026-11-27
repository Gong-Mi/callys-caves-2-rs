/*
 * spine_read_tl_ik.h — the ik-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B7   0x28d840..0x28d8dc  156 B / 39 insns
 *        ik child-list loop head: findIkConstraint (0x28d884, result NEVER
 *        null-tested), spIkConstraintTimeline_create (0x28d890), and the
 *        pointer linear scan over data->ikConstraints[0..count-1] that writes
 *        timeline+0x14 (hit store island 0x28dbc8/0x28dbcc).
 *   B7b  0x28dbd0..0x28dca8  216 B / 54 insns
 *        per-constraint frame loop (head 0x28dbe0): getFloat "time" (default
 *        0), getFloat "mix" (default 1.0f), getInt "bendPositive" (default 1)
 *        -> enum (-1/1) on the stack -> spIkConstraintTimeline_setFrame
 *        (0x28dc38) -> readCurve (0x28dc48) -> next frame, frameIndex++.
 *        Tail 0x28dc5c..0x28dca4: publish timelines[count++] with a THREEFOLD
 *        frame stride, extend animation->duration, advance the constraint node
 *        (0x28dc84) and branch back to 0x28d87c.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getFloat / Json_getInt           c/json_interface
 *   readCurve                             c/spine_read_curve
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spSkeletonData_findIkConstraint       0x28b238 / 92 B
 *   spIkConstraintTimeline_create         0x282f74 / 24 B
 *     -> tail call _spBaseTimeline_create(count, 9, 3, tag):
 *        0x282f78 mov r1,#9        (timeline type word)
 *        0x282f7c mov r2,#3        (frame step = 3 floats per frame)
 *        0x282f84 b 0x282a10       (_spBaseTimeline_create)
 *   spIkConstraintTimeline_setFrame       0x282f8c / 44 B
 *        ABI read off the body: r0 = timeline, r1 = frameIndex, r2 = time bits,
 *        r3 = mix bits, [sp] = bend enum (int32 -1 or +1).
 *        Store shape (0x282f94..0x282fb0): stride 3,
 *          frames[i*3+0] = time, frames[i*3+1] = mix,
 *          frames[i*3+2] = (float)(int)bend   [_vcvt.f32.s32 at 0x282f90]
 */

#ifndef YY_SPINE_READ_TL_IK_H
#define YY_SPINE_READ_TL_IK_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spSkeletonData as observed by this block and by spSkeletonData_findIkConstraint:
 *   +0x3c ikConstraintsCount   [B7 0x28d89c ldr r1,[r0,#0x3c];
 *                               findIkConstraint 0x28b240 ldr r7,[r0,#0x3c]]
 *   +0x40 ikConstraints array  [B7 0x28d8a8 ldr r2,[r0,#0x40];
 *                               findIkConstraint 0x28b24c ldr r6,[r0,#0x40]]
 * The record itself is calloc(1,84,tag,37) (0x28ade4) and is owned by
 * c/spine_skeleton_data; only the two words above are consumed here, and the
 * whole record is modelled so the offsets are pinned by the compiler.
 */
typedef struct spSkeletonDataIkShape {
    uint32_t pad[15];            /* +0x00..+0x38 */
    int32_t  ikConstraintsCount; /* +0x3c */
    void**   ikConstraints;      /* +0x40 */
    uint32_t tail[4];            /* +0x44..+0x50 (record ends at 0x54) */
} spSkeletonDataIkShape;

/*
 * spIkConstraintTimeline as observed by B7/B7b and by the real creator pair:
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0]]
 *   +0x04 vtable object   [0x281354 str r0,[r4,#0x4]; 0x281358 stm r0,{r5,r6}]
 *   +0x08 float* curves   [_spCurveTimeline_init 0x281710 str r0,[r4,#0x8];
 *                          (frameCount-1)*19 floats, the readCurve target]
 *   +0x0c frameFloatCount [0x282a70 str r0,[r4,#0xc] = frameCount * 3]
 *   +0x10 float* frames   [0x282a78 str r0,[r4,#0x10]; 3 floats per frame]
 *   +0x14 int constraintIndex  [B7 ONLY writer: 0x28dbcc str r3,[r6,#0x14]]
 *
 * +0x14 is inside the creator's calloc(1,24,tag,233) (0x282a30/0x282a40) and
 * neither _spBaseTimeline_create (0x282a10..0x282a88), nor
 * _spCurveTimeline_init (0x2816d8..0x281714), nor _spTimeline_init
 * (0x281328..0x28135c) stores to it.  A miss therefore leaves +0x14 == 0,
 * NOT -1: the field's create-time value is the calloc zero fill.
 */
typedef struct spIkConstraintTimelineShape {
    uint32_t type;              /* +0x00 */
    void*    vtable;            /* +0x04 */
    float*   curves;            /* +0x08 (frameCount-1)*19 floats */
    int32_t  frameFloatCount;   /* +0x0c frameCount * 3 */
    float*   frames;            /* +0x10 3 floats per frame */
    int32_t  ikConstraintIndex; /* +0x14 written by the scan only */
} spIkConstraintTimelineShape;

/*
 * spAnimation fields touched by the tail.  Full record owned by
 * spAnimation_create/spAnimation_dispose (c/spine_skeleton_data).
 */
typedef struct spAnimationIkShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by the tail */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationIkShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spSkeletonDataIkShape, ikConstraintsCount) == 0x3c,
               "0x28d89c ldr r1,[r0,#0x3c]");
_Static_assert(offsetof(spSkeletonDataIkShape, ikConstraints) == 0x40,
               "0x28d8a8 ldr r2,[r0,#0x40]");
_Static_assert(sizeof(spSkeletonDataIkShape) == 84, "0x28ade4 calloc(1,84,tag,37)");
_Static_assert(offsetof(spIkConstraintTimelineShape, frames) == 0x10,
               "0x28dc80 ldr r3,[r6,#0x10] / 0x282f98 ldr r12,[r0,#0x10]");
_Static_assert(offsetof(spIkConstraintTimelineShape, ikConstraintIndex) == 0x14,
               "0x28dbcc str r3,[r6,#0x14]");
_Static_assert(sizeof(spIkConstraintTimelineShape) == 24, "0x282a30 mov r1,#24 calloc");
_Static_assert(offsetof(spAnimationIkShape, duration) == 0x04,
               "0x28dc60 vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationIkShape, timelineCount) == 0x08,
               "0x28dc64 ldr r3,[r11,#0x8]");
_Static_assert(offsetof(spAnimationIkShape, timelines) == 0x0c,
               "0x28dc68 ldr r1,[r11,#0xc]");
#endif

/* Declared synthetic boundary: body NOT recovered.  Call site 0x28d884
 * (r0 = spSkeletonData*, r1 = the constraint member key at Json+0x1c).
 * Returns the array element pointer, or NULL when count <= 0 or no name
 * matches (0x28b288 mov r5,#0) — B7 does NOT test the result. */
extern void* spSkeletonData_findIkConstraint(void* data, const char* name);

/* Declared synthetic boundaries (see the block comment above). */
extern void* spIkConstraintTimeline_create(int frameCount);
extern void spIkConstraintTimeline_setFrame(void* timeline, int frameIndex,
                                           float time, float mix, int bend);

/*
 * B7 index scan, 0x28d898..0x28d8dc (the hit island 0x28dbc8/0x28dbcc).
 *   count snapshot at 0x28d89c, signed `ble 0x28dbd0` at 0x28d8a4,
 *   array base at 0x28d8a8, element 0 pre-loaded at 0x28d8ac,
 *   walk by pre-incremented pointer 0x28d8c0, index/count compare 0x28d8d0.
 * Returns 1 when it wrote timeline->ikConstraintIndex, 0 when it fell through
 * to the frame loop without writing.  The value is a reconstruction artefact:
 * both exits of the original go to 0x28dbd0, and the driver ignores it.
 */
int readSkeletonData_ikConstraintIndex(void* data_raw, void* ik_raw,
                                       void* timeline_raw);

/*
 * B7b frame loop, 0x28dbd0..0x28dc58.  Keys and defaults come from the
 * instruction stream, not from any stock spine source:
 *   "time"         @0x34c1d4 (pool 0x28ca48, add 0x28d868) default 0.0f
 *   "mix"          @0x357c98 (pool 0x28ca4c, add 0x28d86c) default 1.0f
 *   "bendPositive" @0x357c88 (pool 0x28ca50, add 0x28d874) default 1
 * The layout key is "bendPositive" (0x357c88), NOT "bendDirection"; the
 * integer read is converted at 0x28dc2c/0x28dc30 into the signed enum
 * (-1 when 0, +1 otherwise) before it is passed on the stack.
 */
void readSkeletonData_ikTimelineFrames(Json* constraintNode, void* timeline_raw);

/*
 * B7 + B7b driver: 0x28d840..0x28d8dc then 0x28dbd0..0x28dca8.
 *   ikMap : the "ik" JSON child (parent B3 caches it at [sp+0x34], 0x28d348;
 *           B7 loads it at 0x28d840).
 *   data_raw : spSkeletonData* (parent [sp+0x18]).
 *   animation_raw : spAnimation* (parent r11).
 * Returns 1: both early exits (0x28d848 / 0x28d858 beq 0x28dca8) and the loop
 * exit land on the transform block.  There is NO error path in this family:
 * no setError call site exists in B7/B7b.
 */
int readSkeletonData_ikTimelines(Json* ikMap, void* data_raw, void* animation_raw);

#endif /* YY_SPINE_READ_TL_IK_H */
