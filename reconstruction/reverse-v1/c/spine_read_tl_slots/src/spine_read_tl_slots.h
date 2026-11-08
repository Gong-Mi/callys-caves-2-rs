/*
 * spine_read_tl_slots.h — the slots timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in
 * libyoyo_armv7.so (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B5   0x28d4ec..0x28d640  340 B / 85 insns
 *        slots child-list loop, findSlotIndex, per-slot timeline dispatch
 *        (strcmp "color" -> B8, strcmp "attachment" -> attachment reader),
 *        attachment frame loop (getItem "name" + getFloat "time") and the
 *        attachment copy of the publish/duration tail at 0x28d5e8.
 *   B8   0x28d8dc..0x28d9d4  248 B / 62 insns
 *        color timeline: create, slotIndex at +0x14, frame loop with the
 *        hex-string channel Json_getString("color") -> toColor(0x28b680) x4
 *        -> spColorTimeline_setFrame(t, i, time, r, g, b, a) -> readCurve.
 *   B8b  0x28d9d4..0x28da18   68 B / 17 insns
 *        the color path's publish/duration tail (frames at +0x10, 5 floats
 *        per frame) and the back edge b 0x28d620.
 *   E1   0x28da18..0x28da54   60 B / 15 insns
 *        "Invalid timeline type for a slot: " error: spAnimation_dispose,
 *        _spSkeletonJson_setError(parser, NULL, message, type name),
 *        spSkeletonData_dispose, return NULL.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getItem/getString/getFloat      c/json_interface
 *   spSkeletonData_findSlotIndex         c/skeleton_find
 *   toColor                              c/spine_color
 *   readCurve                            c/spine_read_curve
 *   _spSkeletonJson_setError             c/spine_json_error
 *   spAnimation_dispose/spSkeletonData_dispose, Json_dispose/ReportSpineError
 *                                        c/spine_skeleton_data, c/spine_json_support
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spAttachmentTimeline_create  0x282b94 / 136 B
 *   spAttachmentTimeline_setFrame 0x282c1c / 112 B
 *   spColorTimeline_create       0x282b3c / 24 B (tail-calls
 *                                _spBaseTimeline_create(count, 4, 5, tag))
 *   spColorTimeline_setFrame     0x282b54 / 64 B
 */
#ifndef YY_SPINE_READ_TL_SLOTS_H
#define YY_SPINE_READ_TL_SLOTS_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spAttachmentTimeline as observed by B5 and by the real creator/destructor
 * pair (pin sources in brackets):
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0]]
 *   +0x04 vtable object   [0x281354/0x281358]
 *   +0x08 frameCount      [0x282bd8 str r5,[r4,#0x8]  = create's r0]
 *   +0x0c float* frames   [0x282be8 calloc(count,4) -> 0x282bf8 str [r4,#0xc]]
 *   +0x10 slotIndex       [B5 0x28d590 str r2,[r0,#0x10]]
 *   +0x14 char** names    [0x282c00 calloc(count,4) -> 0x282c04 str [r4,#0x14]]
 */
typedef struct spAttachmentTimelineShape {
    uint32_t type;             /* +0x00 */
    void*    vtable;           /* +0x04 */
    int32_t  frameCount;       /* +0x08 */
    float*   frames;           /* +0x0c one time float per frame */
    int32_t  slotIndex;        /* +0x10 written by B5 only */
    char**   attachmentNames;  /* +0x14 */
} spAttachmentTimelineShape;

/*
 * spColorTimeline as observed by B8/B8b and by the real create/setFrame
 * bodies:
 *   +0x00 type / +0x04 vtable   [_spTimeline_init 0x281338/0x281354]
 *   +0x08 float* curves         [_spCurveTimeline_init 0x2816d8: r12 =
 *                               frameCount-1, 0x281700 `add r0,r12,r12,lsl#3`
 *                               then 0x281708 `add r0,r12,r0,lsl#1` = 19*r12,
 *                               calloc(19*r12,4,tag,121) -> 0x281710 str [r4,#0x8]
 *                               i.e. (frameCount-1)*19 floats, the array
 *                               spCurveTimeline_setStepped indexes as
 *                               curves[frameIndex*19]]
 *   +0x0c int frameFloatCount   [0x282a60 mul r0,r7,r5 ; 0x282a70 str [r4,#0xc]]
 *                               = frameCount * frameStep, frameStep = 5
 *   +0x10 float* frames         [0x282a74 calloc(count,4) -> 0x282a78 str [r4,#0x10]]
 *                               5 floats per frame: time,r,g,b,a
 *                               [spColorTimeline_setFrame 0x282b58 ldr r0,[r0,#0x10]]
 *   +0x14 slotIndex             [B8 0x28d8f4 str r1,[r0,#0x14]]
 * Note the +0x08 divergence from spAttachmentTimeline, whose +0x08 IS the
 * frame count and whose +0x14 is the attachment-name table.
 */
typedef struct spColorTimelineShape {
    uint32_t type;             /* +0x00 */
    void*    vtable;           /* +0x04 */
    float*   curves;           /* +0x08 (frameCount-1)*19 floats, readCurve target */
    int32_t  frameFloatCount;  /* +0x0c frameCount * 5 */
    float*   frames;           /* +0x10 5 floats per frame */
    int32_t  slotIndex;        /* +0x14 written by B8 only */
} spColorTimelineShape;

/*
 * spAnimation fields touched by this family.  The full record is owned by
 * spAnimation_create/spAnimation_dispose (0x2812b4 / 0x28147c); dispose walks
 * [count +0x08, table +0x0c] with spTimeline_dispose, then frees +0x00 and
 * the record (c/spine_skeleton_data.c, DISPOSE_VECTOR(self,8,0xc,...)).
 */
typedef struct spAnimationShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by both tails */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spAttachmentTimelineShape, frames) == 0x0c, "0x28d604 ldr r3,[r8,#0xc]");
_Static_assert(offsetof(spAttachmentTimelineShape, slotIndex) == 0x10, "0x28d590 str r2,[r0,#0x10]");
_Static_assert(offsetof(spAttachmentTimelineShape, attachmentNames) == 0x14, "0x282c04 str r0,[r4,#0x14]");
_Static_assert(offsetof(spColorTimelineShape, curves) == 0x08, "0x281710 str r0,[r4,#0x8]");
_Static_assert(offsetof(spColorTimelineShape, frames) == 0x10, "0x28d9f8 / 0x282b58 ldr [.,#0x10]");
_Static_assert(offsetof(spColorTimelineShape, slotIndex) == 0x14, "0x28d8f4 str r1,[r0,#0x14]");
_Static_assert(offsetof(spAnimationShape, duration) == 0x04, "0x28d5ec / 0x28d9d8 vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationShape, timelineCount) == 0x08, "0x28d5e8 / 0x28d9dc ldr [r11,#0x8]");
_Static_assert(offsetof(spAnimationShape, timelines) == 0x0c, "0x28d5f0 / 0x28d9e0 ldr [r11,#0xc]");
_Static_assert(sizeof(spAnimationShape) == 16, "0x2812b4 creator record");
#endif

/* Declared synthetic boundaries.  Signatures are read off the call sites:
 *   create(frameCount)                   0x28d57c / 0x28d8e0
 *   attachment setFrame(t, i, time, name) r0,r1,r2,r3   0x28d5d8
 *   color setFrame(t, i, time, r, g, b, a) r0,r1,r2,r3,[sp],[sp+4],[sp+8] 0x28d9a0
 */
extern void* spAttachmentTimeline_create(int frameCount);
extern void spAttachmentTimeline_setFrame(void* timeline, int frameIndex,
                                          float time, const char* attachmentName);
extern void* spColorTimeline_create(int frameCount);
extern void spColorTimeline_setFrame(void* timeline, int frameIndex, float time,
                                     float r, float g, float b, float a);

/*
 * B5 (0x28d4ec..0x28d640): walks the "slots" JSON child list, resolves each
 * slot name with the REAL spSkeletonData_findSlotIndex, and dispatches every
 * timeline of that slot by the exact strcmp chain
 *   "color"      -> readSkeletonData_colorTimeline        (0x28d560 beq 0x28d8dc)
 *   "attachment" -> readSkeletonData_attachmentTimeline   (0x28d574 bne 0x28da18)
 *   anything else-> readSkeletonData_invalidTimelineTypeForSlot (E1)
 *
 * slotMap    : first node of the slots child list (parent spill [sp+0x2c],
 *              loaded at 0x28d520 and advanced at 0x28d62c..0x28d63c).
 * data_raw   : spSkeletonData* (parent [sp+0x18], 0x28d524).
 * animation_raw : spAnimation* (parent r11, 0x28d4d0).
 * parser_raw : spSkeletonJson* (parent [sp+0x20], 0x28da18).
 *
 * Returns 1 when the block falls through to the bones block at 0x28d640, and
 * 0 when it leaves through one of the two out-of-block error paths:
 *   - slot index == -1  -> 0x28d538 beq 0x28ea10 ("Slot not found: ", the
 *     shared block used by the deform/drawOrder era; NOT part of this module,
 *     so this function only reports the branch and touches nothing else)
 *   - invalid timeline type -> E1, which disposes animation + data and returns
 *     NULL from the parent loader (0x28da50 b 0x28bdcc).
 *
 * NOTE on the frame index: B5/B8 contain no `mov r5,#0`.  The dispatch reuses
 * r5 as the strcmp result (0x28d55c / 0x28d570 `subs r5,r0,#0`) and both
 * branches are only entered when that result is 0, so every frame loop starts
 * at frameIndex 0 by construction.  The blocks never carry an index across
 * timelines.
 */
int readSkeletonData_slotTimelines(Json* slotMap, void* data_raw,
                                   void* animation_raw, void* parser_raw);

/*
 * B5 attachment branch + its tail (0x28d578..0x28d61c).
 * Key literals: "name" @0x330810 (Json_getItem, not getString), "time"
 * @0x34c1d4 (Json_getFloat).  The attachment name is
 *   kind = name_node->unk_08;  name = (kind == 2) ? NULL : name_node->string_value
 * (0x28d5b8..0x28d5cc) — the node word +0x08 is the parser's type field, so a
 * literal `false` node is treated as "no attachment".  There is NO NULL guard
 * on the Json_getItem result before the +0x08 load.
 * Tail: timelines[count++] = timeline; animation->duration =
 * max(duration, frames[declaredFrameCount-1]) with a one-float frame stride.
 */
void readSkeletonData_attachmentTimeline(Json* timelineJson, void* animation_raw,
                                         int slotIndex);

/*
 * B8 + B8b (0x28d8dc..0x28da14).
 * Keys: "color" @0x357c18 via Json_getString, "time" @0x34c1d4 via
 * Json_getFloat, then FOUR toColor(color, 0..3) calls (0x28d950/60/70/80) in
 * r,g,b,a order.  No length/format check and no NULL guard exists here: a
 * frame without "color" reaches toColor(NULL, .) and a malformed string
 * arrives as -1.0f in every component.
 * Tail: timelines[count++] = timeline; animation->duration =
 * max(duration, frames[(declaredFrameCount-1)*5]) with a five-float stride.
 */
void readSkeletonData_colorTimeline(Json* timelineJson, void* animation_raw,
                                    int slotIndex);

/*
 * E1 (0x28da18..0x28da50): exact order
 *   type = timelineJson->name                       0x28da34
 *   spAnimation_dispose(animation)                  0x28da28
 *   _spSkeletonJson_setError(parser, NULL, "Invalid timeline type for a slot: ", type)
 *                                                   0x28da30..0x28da40
 *   spSkeletonData_dispose(data)                    0x28da44..0x28da48
 *   return 0 (parent: b 0x28bdcc)                   0x28da4c..0x28da50
 * The json argument to setError is r1 = 0 (0x28da38 mov r1,#0), so unlike the
 * slots-bone error at 0x28bdc4 the root tree is NOT disposed here.
 */
int readSkeletonData_invalidTimelineTypeForSlot(void* animation_raw, Json* timelineJson,
                                                void* data_raw, void* parser_raw);

#endif /* YY_SPINE_READ_TL_SLOTS_H */
