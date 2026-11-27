/*
 * spine_read_tl_bones.h — the bones timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B6    0x28d640..0x28d740  256 B / 64 insns
 *         bones child-list loop head: Json_getItem("bones") result NULL check,
 *         bones->child NULL check, the five key-pointer caches
 *         ("rotate" [sp+0x3c], "scale" [sp+0x40], "translate" [sp+0x48],
 *          "shear" [sp+0x54], "time" [sp+0x30] — the last one overwrites the
 *          spilled bones node at 0x28d694), the REAL
 *         spSkeletonData_findBoneIndex call, the cmp -1 test, and the
 *         strcmp(type, rotate/scale/translate/shear) dispatch.
 *   B6b   0x28d740..0x28d840  256 B / 64 insns
 *         shared translate/scale/shear frame loop: "time", "x", "y", the
 *         s16 coordinate multiplier, spTranslateTimeline_setFrame, readCurve,
 *         publish tail with a THREE-float frame stride, and the shared
 *         timeline->next / bone->next back edges.
 *   B9    0x28da54..0x28da74   32 B / 8 insns
 *         translate selection: s16 = parser->scale (vldr s16,[parser]),
 *         spTranslateTimeline_create(declared), jump into B6b.
 *   B10   0x28da74..0x28db48  212 B / 53 insns
 *         rotate timeline: create, boneIndex at +0x14, frame loop with
 *         "time"+"angle" (NOT x/y), readCurve, publish tail with a TWO-float
 *         stride.
 *   B11   0x28db48..0x28db5c   20 B / 5 insns
 *         scale selection: vmov.f32 s16,#1.0, spScaleTimeline_create, B6b.
 *   B11b  0x28dbb4..0x28dbc4   16 B / 4 insns of the census' 7-insn range
 *         shear selection: spShearTimeline_create, vmov.f32 s16,#1.0, B6b.
 *         (Census correction: 0x28dbc8/0x28dbcc inside the listed
 *          0x28dbb4..0x28dbd0 range are the IK pointer-scan "index 0" store
 *          `mov r3,#0; str r3,[r6,#0x14]`, reached only from 0x28d8bc. The
 *          shear block ends with the unconditional b 0x28d740 at 0x28dbc4, so
 *          it never falls into them. Not reconstructed here.)
 *   E2    0x28db5c..0x28db88   44 B / 11 insns
 *         "Bone not found: " -> spAnimation_dispose -> setError(parser,
 *         ANIMATION JSON NODE, literal, boneNode->name) -> common error tail
 *         0x28da44 (spSkeletonData_dispose(data); return 0).
 *   E3    0x28db88..0x28dbb4   44 B / 11 insns
 *         "Invalid timeline type for a bone: " -> spAnimation_dispose ->
 *         setError(parser, NULL, literal, timelineNode->name) -> same tail.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from; no stock spine-c source was
 * consulted for behaviour.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getItem/getFloat                 c/json_interface     0x2873c4/0x287444
 *   readCurve                             c/spine_read_curve   0x28b34c
 *   _spSkeletonJson_setError              c/spine_json_error   0x28b784
 *   ReportSpineError / Json_dispose       c/spine_json_support 0xc4404/0x2872c8
 *   spAnimation_dispose / spSkeletonData_dispose
 *                                         c/spine_skeleton_data 0x28147c/0x28adf8
 *   _malloc / _free                       c/spine_alloc
 *   spSkeletonData_findBoneIndex          0x28b018/88 B — RECOVERED IN THIS
 *     MODULE because no existing module owns it (c/skeleton_find covers
 *     findBone/findSlotIndex/findSkin only).  It is a full .dynsym symbol,
 *     translated from its 21 instructions at the bottom of the .c.  If
 *     c/skeleton_find later recovers it, drop this copy to avoid a duplicate.
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spTranslateTimeline_create    0x282abc / 24 B (tail -> _spBaseTimeline_create
 *                                 with frameStep 3)
 *   spRotateTimeline_create       0x282a90 / 24 B (frameStep 2)
 *   spScaleTimeline_create        0x282b04 / 24 B (frameStep 3)
 *   spShearTimeline_create        0x282b20 / 24 B (frameStep 3)
 *   spTranslateTimeline_setFrame  0x282ad4 / 48 B
 *   spRotateTimeline_setFrame     0x282aa8 / 20 B
 *   NOTE: spScaleTimeline_setFrame (0x282b1c) and spShearTimeline_setFrame
 *   (0x282b38) are 4-byte `b spTranslateTimeline_setFrame` thunks (.dynsym
 *   size 4).  The caller therefore has exactly ONE setFrame call site
 *   (0x28d7c0) for all three XY timeline kinds — see the static thunk proof
 *   in tools/check_tl_bones.py.
 */
#ifndef YY_SPINE_READ_TL_BONES_H
#define YY_SPINE_READ_TL_BONES_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"
#include "../../spine_json_layout.h"                 /* spSkeletonJson (+0x00 scale) */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h" /* spSkeletonData words */

/*
 * The common bone-timeline record, as observed by B6b/B10 and by the real
 * creator (`_spBaseTimeline_create` 0x282a10) and setter bodies:
 *   +0x00 uint32 type             [_spCurveTimeline_init 0x2816d8 receives it]
 *   +0x04 void*  vtable           [spTimeline_dispose reads [[self+4]+4]]
 *   +0x08 float* curves           [_spCurveTimeline_init: (frameCount-1)*19 floats]
 *   +0x0c int32  frameFloatCount  [0x282a60 mul r0,r7,r5 ; 0x282a70 str [r4,#0xc]]
 *                                 = frameCount * frameStep (2 or 3)
 *   +0x10 float* frames           [0x282a78 str r0,[r4,#0x10]; calloc(frameFloatCount,4)]
 *   +0x14 int32  boneIndex        [B6b 0x28d744 str r8,[r4,#0x14];
 *                                  B10 0x28da88 str r8,[r0,#0x14]]
 * Frame layout written by the real setters (used by the publish tails):
 *   rotate     frames[i*2 + 0] = time, [+1] = angle   (0x282ab0/0x282ab4)
 *   translate  frames[i*3 + 0] = time, [+1] = x, [+2] = y
 *              (scale/shear reach the same body through 0x282b1c/0x282b38)
 */
typedef struct spBoneTimelineShape {
    uint32_t type;              /* +0x00 */
    void*    vtable;            /* +0x04 */
    float*   curves;            /* +0x08 */
    int32_t  frameFloatCount;   /* +0x0c */
    float*   frames;            /* +0x10 */
    int32_t  boneIndex;         /* +0x14 written by this family only */
} spBoneTimelineShape;

/*
 * spAnimation fields touched by this family.  The record is owned by
 * spAnimation_create/spAnimation_dispose (0x2812b4 / 0x28147c); dispose walks
 * [count +0x08, table +0x0c] with spTimeline_dispose, then frees the timeline
 * table, the name and the record.
 */
typedef struct spAnimationShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by all three tails */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spBoneTimelineShape, frameFloatCount) == 0x0c, "0x282a70 str r0,[r4,#0xc]");
_Static_assert(offsetof(spBoneTimelineShape, frames) == 0x10, "0x28d808 / 0x28db28 ldr r3,[.,#0x10]");
_Static_assert(offsetof(spBoneTimelineShape, boneIndex) == 0x14, "0x28d744 / 0x28da88 str r8,[.,#0x14]");
_Static_assert(offsetof(spAnimationShape, duration) == 0x04, "0x28d7e8 / 0x28db10 vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationShape, timelineCount) == 0x08, "0x28d7ec / 0x28db0c ldr [r11,#0x8]");
_Static_assert(offsetof(spAnimationShape, timelines) == 0x0c, "0x28d7f0 / 0x28db14 ldr [r11,#0xc]");
_Static_assert(sizeof(spAnimationShape) == 16, "0x2812b4 creator record");
_Static_assert(offsetof(spSkeletonData, words) + 4 * 4 == 0x10, "0x28b020 ldr r6,[r0,#0x10] bonesCount");
_Static_assert(offsetof(spSkeletonData, words) + 5 * 4 == 0x14, "0x28b02c ldr r5,[r0,#0x14] bones");
_Static_assert(offsetof(spSkeletonJson, scale) == 0x00, "0x28da5c vldr s16,[parser] = parser->scale");
#endif

/* Binary32 reinterpretation of spSkeletonJson.scale, exactly the word the
 * original loads with `vldr s16,[r2]` at 0x28da5c. */
static inline float spSkeletonJson_scale_float(const spSkeletonJson* parser)
{
    float f;
    __builtin_memcpy(&f, &parser->scale, sizeof f);
    return f;
}

/* Declared synthetic boundaries.  Signatures read off the call sites:
 *   create(frameCount)                          r0 only  0x28da68/0x28da78/0x28db50/0x28dbbc
 *   rotate setFrame(t, i, time, angle)          r0..r3   0x28dae0
 *   xy     setFrame(t, i, time, x, y)           r0..r3,[sp] 0x28d7c0
 */
extern void* spTranslateTimeline_create(int frameCount);
extern void* spRotateTimeline_create(int frameCount);
extern void* spScaleTimeline_create(int frameCount);
extern void* spShearTimeline_create(int frameCount);
extern void spTranslateTimeline_setFrame(void* timeline, int frameIndex,
                                         float time, float x, float y);
extern void spRotateTimeline_setFrame(void* timeline, int frameIndex,
                                      float time, float angle);

/*
 * spSkeletonData_findBoneIndex — 0x28b018..0x28b06c, 88 B / 21 insns.
 * Recovered in this module (see the file comment).  Not the same function as
 * spSkeletonData_findBone (0x28afbc), which returns a POINTER.  This one
 * returns the 0-based INDEX and -1 on miss:
 *   count = [data+0x10]; if ((int32_t)count <= 0) return -1;  0x28b020..0x28b028
 *   table = [data+0x14]; i = 0;                                0x28b02c/0x28b030
 *   do { if (strcmp([table[i]+4], name) == 0) return i; ++i; } 0x28b03c..0x28b060
 *   while (i != count); return -1;                             0x28b040..0x28b068
 */
int spSkeletonData_findBoneIndex(spSkeletonData* data, const char* name);

/*
 * B6 (0x28d640..0x28d740) + the shared loops at 0x28d824..0x28d83c.
 *
 * bonesJson     : the Json value of the animation's "bones" key (parent spill
 *                 [sp+0x30] written at 0x28d328; the block reads it first and
 *                 then OVERWRITES that slot with the "time" literal at
 *                 0x28d694, so the C keeps the node in a parameter).
 * animationJson : the CURRENT animation node, [sp+0x1c] (written once at
 *                 0x28d2c8, advanced at 0x28e790..0x28e798).  E2 passes it to
 *                 setError; E3 does not.
 * data_raw      : spSkeletonData*  ([sp+0x18])
 * animation_raw : spAnimation*     (r11)
 * parser_raw    : spSkeletonJson*  ([sp+0x20])
 *
 * Returns 1 when the block falls through to the ik block at 0x28d840 and 0
 * when it leaves through E2/E3 (the parent then returns NULL from 0x28bdcc).
 *
 * Dispatch (all four comparisons are performed by the original, in the order
 * rotate @0x28d6cc, scale @0x28d6e0, translate @0x28d6f4, shear @0x28d708;
 * the branch priority is rotate -> translate -> scale -> shear):
 *   "rotate"    -> readSkeletonData_boneRotateTimeline      (0x28d6d4 beq 0x28da74)
 *   "translate" -> spTranslateTimeline_create + B6b, s16 = parser->scale
 *                                                           (0x28d724 bne 0x28da54)
 *   "scale"     -> spScaleTimeline_create + B6b, s16 = 1.0   (0x28d72c bne 0x28db48)
 *   "shear"     -> spShearTimeline_create + B6b, s16 = 1.0    (0x28d73c bne 0x28dbb4)
 *   anything else -> E3                                      (0x28d71c beq 0x28db88)
 */
int readSkeletonData_boneTimelines(Json* bonesJson, Json* animationJson,
                                   void* data_raw, void* animation_raw,
                                   void* parser_raw);

/*
 * B6b (0x28d740..0x28d840): the frame loop and publish tail shared by the
 * translate, scale and shear timelines.  The caller has already created the
 * timeline with the declared Json count.
 *   timelineJson : the timeline node (r7)
 *   animation_raw: spAnimation* (r11)
 *   boneIndex    : real findBoneIndex result (r8), stored at timeline+0x14
 *   coordScale   : s16 — parser->scale for translate (0x28da5c),
 *                  1.0f for scale (0x28db48) and shear (0x28dbb8)
 *   timeline_raw : the created record (r4)
 * Keys: "time"/"x"/"y" @0x34c1d4/0x33087c/0x330880 through Json_getFloat.
 * Frames: spTranslateTimeline_setFrame(t, i, time, x*s16, s16*y) @0x28d7c0,
 *         then readCurve(frame, t, i) @0x28d7d0.
 * Tail: timelines[count++] = t; duration = max(duration,
 *       frames[3*(declared-1)]) (three-float stride, frames at +0x10).
 */
void readSkeletonData_boneXYTimeline(Json* timelineJson, void* animation_raw,
                                     int boneIndex, float coordScale,
                                     void* timeline_raw);

/*
 * B10 (0x28da74..0x28db48): the rotate timeline.  Creates its own record.
 * Keys: "time" @0x34c1d4 (pool 0x28ea88) and "angle" @0x330884 (pool 0x28ea8c)
 *       through Json_getFloat; there is no x/y read on this path.
 * Frames: spRotateTimeline_setFrame(t, i, time, angle) @0x28dae0, then
 *         readCurve(frame, t, i) @0x28daf0.
 * Tail: duration = max(duration, frames[2*(declared-1)]).
 * The 0-based frame index arrives as r9, which the dispatch left at 0
 * (0x28d6d0 `subs r9,r0,#0` with r0 == 0 on the rotate branch).
 */
void readSkeletonData_boneRotateTimeline(Json* timelineJson, void* animation_raw,
                                         int boneIndex);

/*
 * E2 (0x28db5c..0x28db88 + the shared tail 0x28da44..0x28da50).
 *   spAnimation_dispose(animation)                    0x28db68
 *   _spSkeletonJson_setError(parser, animationJson,   0x28db70..0x28db80
 *     "Bone not found: ", boneNode->name)
 *   spSkeletonData_dispose(data)                      0x28da48
 *   return 0                                          0x28da4c -> b 0x28bdcc
 * The json argument is [sp+0x1c] (0x28db74 `ldr r1,[sp,#0x1c]`), i.e. the
 * CURRENT ANIMATION NODE — unlike E1's explicit NULL.  setError therefore
 * Json_disposes that node and its siblings; the root tree is untouched.
 * The offending text is boneNode->name (+0x1c), 0x28db78.
 */
int readSkeletonData_boneNotFound(Json* boneNode, Json* animationJson,
                                  void* data_raw, void* animation_raw,
                                  void* parser_raw);

/*
 * E3 (0x28db88..0x28dbb4 + the same tail).
 *   spAnimation_dispose(animation)                    0x28db94
 *   _spSkeletonJson_setError(parser, NULL,            0x28db9c `mov r1,r4`
 *     "Invalid timeline type for a bone: ", timelineJson->name)   0x28dba4
 *   spSkeletonData_dispose(data); return 0
 * r4 is 0 at this call: it is the OR of the four strcmp match flags
 * (`orrs r4,r0,r4` @0x28d718) and the branch is taken only when that OR is
 * zero.  So, like E1, this path does NOT dispose the Json tree.
 */
int readSkeletonData_invalidTimelineTypeForBone(Json* timelineJson,
                                                void* data_raw,
                                                void* animation_raw,
                                                void* parser_raw);

#endif /* YY_SPINE_READ_TL_BONES_H */
