/*
 * spine_read_tl_transform.h — the transform-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller block (addresses end-exclusive, census §6):
 *   B12  0x28dca8..0x28de74  460 B / 115 insns
 *        transform child-list loop: findTransformConstraint (0x28dd08,
 *        result NEVER null-tested), spTransformConstraintTimeline_create
 *        (0x28dd14), the pointer linear scan over data->transformConstraints
 *        (+0x44 count / +0x48 array) that writes timeline+0x14 (store
 *        0x28dd64, word 0xe5863014 — the same source sentence as the ik
 *        family's 0x28dbcc), the FIVE-key frame loop (head 0x28dd7c) with
 *        setFrame (0x28ddfc) and readCurve (0x28de0c), and the publish/
 *        duration tail with a FIVE-float frame stride (0x28de44) and back
 *        edge 0x28de70.  Both early exits (0x28dcb0 / 0x28dcc0 beq 0x28de74)
 *        fall through to the path block B13.
 *
 * Error path: NONE.  The block has no _spSkeletonJson_setError call site, no
 * spAnimation_dispose and no spSkeletonData_dispose call site.  Its complete
 * bl target list is: spSkeletonData_findTransformConstraint (0x28dd08),
 * spTransformConstraintTimeline_create (0x28dd14), Json_getFloat ×5
 * (0x28dd8c/0x28dda0/0x28ddb4/0x28ddc8/0x28dddc),
 * spTransformConstraintTimeline_setFrame (0x28ddfc), readCurve (0x28de0c).
 * The census §5.4 set of error blocks contains no transform entry and the
 * segment contains no "Transform constraint not found" literal — the lookup
 * result is compared against the vector elements, never null-tested.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getFloat                        c/json_interface   (0x287444)
 *   readCurve                            c/spine_read_curve (anonymous 0x28b34c)
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spSkeletonData_findTransformConstraint 0x28b294 / 92 B
 *       (data, name) -> vector element or NULL; signed count guard at
 *       0x28b2a0/0x28b2a4 is the same 92-byte shape as findIkConstraint.
 *   spTransformConstraintTimeline_create   0x282fb8 / 24 B
 *       tail-calls _spBaseTimeline_create(count, 10, 5, tag):
 *         0x282fbc mov r1,#10   (timeline type word)
 *         0x282fc0 mov r2,#5    (frame step = FIVE floats per frame)
 *       _spBaseTimeline_create (0x282a10) does
 *         calloc(1,24,tag,233)            -> +0x14 stays 0 (calloc fill),
 *         _spCurveTimeline_init(...,type,count,step,...) -> +0x08 curves,
 *         0x282a60 mul r0,r7,r5 ; 0x282a70 str r0,[r4,#0xc]  -> frameFloatCount
 *         = count*step, 0x282a78 str r0,[r4,#0x10]           -> frames.
 *   spTransformConstraintTimeline_setFrame 0x282fd0 / 64 B
 *       ABI read off the body: r0 = timeline, r1 = frameIndex, r2 = time,
 *       r3 = rotateMix, [sp] = translateMix, [sp,#4] = scaleMix,
 *       [sp,#8] = shearMix.  Store shape (0x282fd0..0x283004), stride 5:
 *         frames[i*5+0] = time         0x282ff4 str r2,[r1]
 *         frames[i*5+1] = rotateMix    0x283000 str r3,[r0]
 *         frames[i*5+2] = translateMix 0x282ff8 str r5,[r0,#4]
 *         frames[i*5+3] = scaleMix     0x282ffc str r4,[r0,#8]
 *         frames[i*5+4] = shearMix     0x283004 str r12,[r0,#0xc]
 *       (the two add sites 0x282fd0 add r1,r1,r1,lsl#2 and 0x282fe0
 *        add r1,r0,r1,lsl#2 produce i*5 and the word address; 0x282fd8
 *        add r12,r1,#1 seeds the rotate/translate/scale/shear block at
 *        frames+i*5+1.)
 */

#ifndef YY_SPINE_READ_TL_TRANSFORM_H
#define YY_SPINE_READ_TL_TRANSFORM_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spSkeletonData as observed by this block and by
 * spSkeletonData_findTransformConstraint:
 *   +0x44 transformConstraintsCount  [B12 0x28dd20 ldr r1,[r0,#0x44];
 *                                     findTransformConstraint 0x28b29c]
 *   +0x48 transformConstraints array [B12 0x28dd2c ldr r2,[r0,#0x48];
 *                                     findTransformConstraint 0x28b2a8]
 * The record itself is calloc(1,84,tag,37) (0x28ade4) and is owned by
 * c/spine_skeleton_data; only the two words above are consumed here, and the
 * whole record is modelled so the offsets are pinned by the compiler.
 */
typedef struct spSkeletonDataTransformShape {
    uint32_t pad[17];                    /* +0x00..+0x43 */
    int32_t  transformConstraintsCount;  /* +0x44 */
    void**   transformConstraints;       /* +0x48 */
    uint32_t tail[2];                    /* +0x4c..+0x53 (record ends at 0x54) */
} spSkeletonDataTransformShape;

/*
 * spTransformConstraintTimeline as observed by B12 and by the real creator
 * pair (the layout is the common spCurveTimeline base, identical to
 * spIkConstraintTimeline):
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0]; 10 for this family]
 *   +0x04 vtable object   [0x281354 str r0,[r4,#0x4]; 0x281358 stm r0,{r5,r6}]
 *   +0x08 float* curves   [_spCurveTimeline_init 0x281710 str r0,[r4,#0x8];
 *                          (frameCount-1)*19 floats, the readCurve target]
 *   +0x0c frameFloatCount [0x282a70 str r0,[r4,#0xc] = frameCount * 5]
 *   +0x10 float* frames   [0x282a78 str r0,[r4,#0x10]; 5 floats per frame]
 *   +0x14 int constraintIndex  [B12 ONLY writer: 0x28dd64 str r3,[r6,#0x14]]
 *
 * +0x14 is inside the creator's calloc(1,24,tag,233) (0x282a30/0x282a40) and
 * neither _spBaseTimeline_create (0x282a10..0x282a88), nor
 * _spCurveTimeline_init (0x2816d8..0x281714), nor _spTimeline_init
 * (0x281328..0x28135c) stores to it.  A miss therefore leaves +0x14 == 0,
 * NOT -1: the field's create-time value is the calloc zero fill.
 */
typedef struct spTransformConstraintTimelineShape {
    uint32_t type;                 /* +0x00 */
    void*    vtable;               /* +0x04 */
    float*   curves;               /* +0x08 (frameCount-1)*19 floats */
    int32_t  frameFloatCount;      /* +0x0c frameCount * 5 */
    float*   frames;               /* +0x10 5 floats per frame */
    int32_t  transformConstraintIndex; /* +0x14 written by the scan only */
} spTransformConstraintTimelineShape;

/*
 * spAnimation fields touched by the tail.  Full record owned by
 * spAnimation_create/spAnimation_dispose (c/spine_skeleton_data).
 */
typedef struct spAnimationTransformShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by the tail */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationTransformShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spSkeletonDataTransformShape, transformConstraintsCount) == 0x44,
               "0x28dd20 ldr r1,[r0,#0x44]");
_Static_assert(offsetof(spSkeletonDataTransformShape, transformConstraints) == 0x48,
               "0x28dd2c ldr r2,[r0,#0x48]");
_Static_assert(sizeof(spSkeletonDataTransformShape) == 84, "0x28ade4 calloc(1,84,tag,37)");
_Static_assert(offsetof(spTransformConstraintTimelineShape, frames) == 0x10,
               "0x28de4c ldr r3,[r6,#0x10] / 0x282fd4 ldr r0,[r0,#0x10]");
_Static_assert(offsetof(spTransformConstraintTimelineShape, transformConstraintIndex) == 0x14,
               "0x28dd64 str r3,[r6,#0x14]");
_Static_assert(sizeof(spTransformConstraintTimelineShape) == 24, "0x282a30 mov r1,#24 calloc");
_Static_assert(offsetof(spAnimationTransformShape, duration) == 0x04,
               "0x28de2c vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationTransformShape, timelineCount) == 0x08,
               "0x28de30 ldr r3,[r11,#0x8]");
_Static_assert(offsetof(spAnimationTransformShape, timelines) == 0x0c,
               "0x28de34 ldr r1,[r11,#0xc]");
#endif

/* Declared synthetic boundary: body NOT recovered.  Call site 0x28dd08
 * (r0 = spSkeletonData*, r1 = the constraint member key at Json+0x1c).
 * Returns the array element pointer, or NULL when count <= 0 or no name
 * matches (0x28b2e4 mov r5,#0) — B12 does NOT test the result. */
extern void* spSkeletonData_findTransformConstraint(void* data, const char* name);

/* Declared synthetic boundaries (see the block comment above). */
extern void* spTransformConstraintTimeline_create(int frameCount);
extern void spTransformConstraintTimeline_setFrame(void* timeline, int frameIndex,
                                                   float time, float rotateMix,
                                                   float translateMix, float scaleMix,
                                                   float shearMix);

/*
 * B12 index scan, 0x28dd1c..0x28dd68 (the hit store is the in-line word
 * 0x28dd64; the index-0 path clears r3 at 0x28dd60 first).
 *   count snapshot at 0x28dd20, signed `ble 0x28dd68` at 0x28dd28,
 *   array base at 0x28dd2c, element 0 pre-loaded at 0x28dd30,
 *   walk by pre-incremented pointer 0x28dd44, index/count compare 0x28dd54.
 * Returns 1 when it wrote timeline->transformConstraintIndex, 0 when it fell
 * through to the frame loop without writing.  The value is a reconstruction
 * artefact: both exits of the original go to 0x28dd68, and the driver
 * ignores it.
 */
int readSkeletonData_transformConstraintIndex(void* data_raw, void* transform_raw,
                                              void* timeline_raw);

/*
 * B12 frame loop, 0x28dd68..0x28de24.  Keys and defaults come from the
 * instruction stream, not from any stock spine source:
 *   "time"         @0x34c1d4 (pool 0x28ea98, add 0x28dccc) default 0.0f
 *   "rotateMix"    @0x357cc0 (pool 0x28ea9c, add 0x28dcd8) default 1.0f
 *   "translateMix" @0x357ccc (pool 0x28eaa0, add 0x28dce0) default 1.0f
 *   "scaleMix"     @0x357cdc (pool 0x28eaa4, add 0x28dce8) default 1.0f
 *   "shearMix"     @0x357ce8 (pool 0x28eaa8, add 0x28dcf0) default 1.0f
 * setFrame argument order at the call site (0x28dde0..0x28ddf8):
 *   r1 = frameIndex, r2 = time, r3 = rotateMix,
 *   [sp] = translateMix, [sp+4] = scaleMix, [sp+8] = shearMix.
 */
void readSkeletonData_transformTimelineFrames(Json* constraintNode, void* timeline_raw);

/*
 * B12 driver: 0x28dca8..0x28de74.
 *   transformMap : the "transform" JSON child (parent B3 caches it at
 *                  [sp+0x38] via 0x28d35c; B12 loads it at 0x28dca8).
 *   data_raw     : spSkeletonData* (parent [sp+0x18]).
 *   animation_raw: spAnimation* (parent r11).
 * Returns 1: both early exits (0x28dcb0 / 0x28dcc0 beq 0x28de74) and the
 * loop exit land on the path block B13.  There is NO error path in this
 * family: no setError call site exists in B12.
 */
int readSkeletonData_transformTimelines(Json* transformMap, void* data_raw,
                                        void* animation_raw);

#endif /* YY_SPINE_READ_TL_TRANSFORM_H */
