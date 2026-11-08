/*
 * spine_read_tl_path.h — the path-constraint timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6 B13):
 *   B13  0x28de74..0x28e060  492 B / 123 insns
 *        paths child-list loop head, spSkeletonData_findPathConstraint (0x28dedc,
 *        result IS null-tested at 0x28dee0), the pointer linear scan over
 *        data->pathConstraints (+0x4c count / +0x50 array) whose hit writes the
 *        shared stack cell [sp+0x2c] (0x28df2c), the "position"/"spacing"
 *        strcmp dispatch, the shared frame loop (head 0x28dfa4, readCurve at
 *        0x28dff4) and the two-float publish/duration tail (0x28e010..0x28e050).
 *
 * Out-of-line islands that belong to B13 but sit outside its address range
 * (the census partition is address-contiguous, so these bytes are currently
 * attributed to B15 / B17 in §6 — see functions.json census_cross_check):
 *   0x28e52c..0x28e558  the third strcmp ("spacing") + spPathConstraintSpacing-
 *                       Timeline_create + the spacing-mode scale select
 *                       (inside census B15's span 0x28e338..0x28e55c)
 *   0x28e554            s16 = 1.0f  (shared by both scale selects)
 *   0x28ea74..0x28ea7c  s16 = parser->scale for the spacing path
 *                       (inside census B17's span 0x28e8ec..0x28ea88)
 *
 * B13 does NOT own the third sub-key: 0x28e538 `bne 0x28e8ec` hands any name
 * that is neither "position" nor "spacing" to the path-MIX block B17
 * (0x28e8ec..0x28ea88, its own loop head 0x28e948 and its own readCurve call
 * site 0x28e9b0).  B17 is out of scope for this module; see
 * PATH_TL_HANDOFF_MIX below and the boundary notes in the .c.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getFloat                        c/json_interface
 *   readCurve                            c/spine_read_curve (0x28b34c, anonymous)
 *   _spSkeletonJson_setError             c/spine_json_error (0x28b784)
 *   spAnimation_dispose                  c/spine_skeleton_data (0x28147c)
 *   spSkeletonData_dispose               c/spine_skeleton_data (0x28adf8)
 *   _malloc/_free/_calloc                c/spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spSkeletonData_findPathConstraint    0x28b2f0 / 92 B
 *        Returns NULL on a count<=0 or a name miss (0x28b300 ble -> 0x28b340
 *        mov r5,#0).  B13 tests it, unlike the ik/transform families.
 *   spPathConstraintPositionTimeline_create  0x283010 / 24 B
 *        tail call _spBaseTimeline_create(count, 11, 2, tag):
 *        0x283014 mov r1,#11 (timeline type word)
 *        0x283018 mov r2,#2  (frame step = 2 floats per frame)
 *        0x283020 b 0x282a10
 *   spPathConstraintSpacingTimeline_create   0x28303c / 24 B
 *        same shape with type 12 and frame step 2 (0x283040/0x283044).
 *   spPathConstraintPositionTimeline_setFrame 0x283028 / 20 B
 *        ABI read off the body: r0 = timeline, r1 = frameIndex, r2 = time bits,
 *        r3 = value bits.
 *        Store shape (0x283028..0x283038): stride 2,
 *          frames[i*2+0] = time, frames[i*2+1] = value.
 *        Both the position AND the spacing path call THIS symbol: 0x28dfe4
 *        `bl 0x283028` is the family's only setFrame call site.  The spacing
 *        family's own symbol (0x283054, 20 B) has a byte-identical body but is
 *        never called; the fixture deliberately does not define it so that a
 *        reconstruction that calls it cannot link.
 */

#ifndef YY_SPINE_READ_TL_PATH_H
#define YY_SPINE_READ_TL_PATH_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"
#include "../../spine_json_layout.h"   /* spSkeletonJson (+0x00 scale, +0x08 error) */

/*
 * spSkeletonData as observed by this block and by spSkeletonData_findPath-
 * Constraint:
 *   +0x4c pathConstraintsCount  [B13 0x28deec ldr r1,[r2,#0x4c];
 *                                findPathConstraint 0x28b2f8 ldr r7,[r0,#0x4c]]
 *   +0x50 pathConstraints array [B13 0x28def8 ldr r2,[r2,#0x50];
 *                                findPathConstraint 0x28b304 ldr r6,[r0,#0x50]]
 * The record is calloc(1,84,tag,37) (0x28ade4) and is 0x54 bytes, so the two
 * path words are its LAST two — the ik family (+0x3c/+0x40) and the transform
 * family (+0x44/+0x48) come before them in the same 21-word record.
 * Owned by c/spine_skeleton_data; modelled whole so the compiler pins the
 * offsets.
 */
typedef struct spSkeletonDataPathShape {
    uint32_t pad[19];                /* +0x00..+0x48 */
    int32_t  pathConstraintsCount;   /* +0x4c */
    void**   pathConstraints;        /* +0x50 */
} spSkeletonDataPathShape;           /* 84 B, ends at 0x54 */

/*
 * spPathConstraintData, the two words this block consumes:
 *   +0x10 positionMode  [0x28df70 ldr r3,[r9,#0x10] ; 0x28df74 cmp r3,#0]
 *   +0x14 spacingMode   [0x28e544 ldr r3,[r9,#0x14] ; 0x28e548 cmp r3,#1]
 * Names and enum meanings are taken from the sibling recovered block
 * c/spine_read_path (0x28c274..0x28c5ec), which parses both keys and pins the
 * same offsets: positionMode fixed=0 / percent=1 (JSON default "percent" -> 1),
 * spacingMode length=0 / fixed=1 / percent=2 (default "length" -> 0).  B13
 * itself only proves the word's zero/non-zero and <=1 branches; the enum
 * labels are cross-module corroboration, not an inference of this block.
 * The record is 88 B (spPathConstraintData_create 0x288edc), so only these two
 * words are modelled, with the padding kept explicit.
 */
typedef struct spPathConstraintDataPathShape {
    uint32_t pad[4];                 /* +0x00..+0x0c */
    int32_t  positionMode;           /* +0x10 */
    int32_t  spacingMode;            /* +0x14 */
} spPathConstraintDataPathShape;

/*
 * spPathConstraintTimeline as observed by B13 and by the real creator pair:
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0], reached from
 *                          _spCurveTimeline_init 0x2816ec bl 0x281328]
 *   +0x04 vtable object   [0x281354 str r0,[r4,#0x4]]
 *   +0x08 float* curves   [_spCurveTimeline_init 0x281700..0x281710:
 *                          calloc((frameCount-1)*19, 4) -> str r0,[r4,#0x8];
 *                          this is the readCurve target]
 *   +0x0c frameFloatCount [0x282a70 str r0,[r4,#0xc] = frameCount * 2]
 *   +0x10 float* frames   [0x282a78 str r0,[r4,#0x10]; 2 floats per frame]
 *   +0x14 int32 pathConstraintIndex  [B13 ONLY writer: 0x28df94 str r2,[r8,#0x14]]
 *
 * +0x14 is inside the creator's calloc(1,24,tag,233) (0x282a30/0x282a40) and
 * neither _spBaseTimeline_create (0x282a10..0x282a88), nor _spCurveTimeline_init
 * (0x2816d8..0x281714), nor _spTimeline_init (0x281328..0x28135c) stores to it,
 * so the create-time value is the calloc zero fill.  It does not matter here:
 * unlike ik/transform, B13 stores the index UNCONDITIONALLY (0x28df94 runs on
 * every path of the create, outside the frame-count test).
 */
typedef struct spPathConstraintTimelineShape {
    uint32_t type;                 /* +0x00 */
    void*    vtable;               /* +0x04 */
    float*   curves;               /* +0x08 (frameCount-1)*19 floats */
    int32_t  frameFloatCount;      /* +0x0c frameCount * 2 */
    float*   frames;               /* +0x10 2 floats per frame */
    int32_t  pathConstraintIndex;  /* +0x14 written unconditionally at 0x28df94 */
} spPathConstraintTimelineShape;

/*
 * spAnimation fields touched by the tail.  Full record owned by
 * spAnimation_create/spAnimation_dispose (c/spine_skeleton_data).
 */
typedef struct spAnimationPathShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by the tail */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationPathShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spSkeletonDataPathShape, pathConstraintsCount) == 0x4c,
               "0x28deec ldr r1,[r2,#0x4c]");
_Static_assert(offsetof(spSkeletonDataPathShape, pathConstraints) == 0x50,
               "0x28def8 ldr r2,[r2,#0x50]");
_Static_assert(sizeof(spSkeletonDataPathShape) == 84, "0x28ade4 calloc(1,84,tag,37)");
_Static_assert(offsetof(spPathConstraintDataPathShape, positionMode) == 0x10,
               "0x28df70 ldr r3,[r9,#0x10]");
_Static_assert(offsetof(spPathConstraintDataPathShape, spacingMode) == 0x14,
               "0x28e544 ldr r3,[r9,#0x14]");
_Static_assert(sizeof(spPathConstraintDataPathShape) == 0x18,
               "spPathConstraintData_create 0x288edc: 88 B record, modelled head only");
_Static_assert(offsetof(spPathConstraintTimelineShape, frames) == 0x10,
               "0x28e02c ldr r3,[r8,#0x10] / 0x28302c ldr r0,[r0,#0x10]");
_Static_assert(offsetof(spPathConstraintTimelineShape, pathConstraintIndex) == 0x14,
               "0x28df94 str r2,[r8,#0x14]");
_Static_assert(sizeof(spPathConstraintTimelineShape) == 24, "0x282a30 mov r1,#24 calloc");
_Static_assert(offsetof(spAnimationPathShape, duration) == 0x04,
               "0x28e014 vldr s14,[r11,#4]");
_Static_assert(offsetof(spAnimationPathShape, timelineCount) == 0x08,
               "0x28e010 ldr r3,[r11,#0x8]");
_Static_assert(offsetof(spAnimationPathShape, timelines) == 0x0c,
               "0x28e018 ldr r1,[r11,#0xc]");
_Static_assert(offsetof(spSkeletonJson, scale) == 0x00,
               "0x28df84 vldr s16,[r1] with r1 = parser");
#endif

/* Binary32 reinterpretation of spSkeletonJson.scale: exactly the word 0x28df84
 * (and 0x28ea78) load with vldr s16,[r1].  spSkeletonJson_createWithLoader
 * writes 0x3f800000 there at 0x28b720/0x28b728. */
static inline float spSkeletonJson_path_scale_float(const spSkeletonJson* parser)
{
    float f;
    __builtin_memcpy(&f, &parser->scale, sizeof f);
    return f;
}

/* Declared synthetic boundary: body NOT recovered.  Call site 0x28dedc
 * (r0 = spSkeletonData*, r1 = the path node's member key at Json+0x1c).
 * Returns the array element pointer, or NULL when count <= 0 (0x28b300 ble)
 * or when no name matches (0x28b340 mov r5,#0).  B13 DOES test the result. */
extern void* spSkeletonData_findPathConstraint(void* data, const char* name);

/* Declared synthetic boundaries (see the block comment above). */
extern void* spPathConstraintPositionTimeline_create(int frameCount);
extern void* spPathConstraintSpacingTimeline_create(int frameCount);
extern void  spPathConstraintPositionTimeline_setFrame(void* timeline, int frameIndex,
                                                       float time, float value);
/* Deliberately NOT declared: spPathConstraintSpacingTimeline_setFrame (0x283054).
 * 0x28dfe4 calls the POSITION symbol for both families; naming the spacing
 * symbol here would invite a reconstruction that drifts from the call target. */

/* Driver return codes.  The original has three distinct exits from B13: */
#define PATH_TL_REACHED_DEFORM 1   /* 0x28de7c / 0x28de8c / 0x28e05c fall-through */
#define PATH_TL_ERROR          0   /* 0x28ea48: dispose, setError, data dispose, NULL */
#define PATH_TL_HANDOFF_MIX    2   /* 0x28e538 bne 0x28e8ec: B17 owns the rest */

/*
 * B13 index scan, 0x28dee8..0x28df30 (the hit store island 0x28df2c is inline).
 *   count snapshot at 0x28deec, signed `ble 0x28df30` at 0x28def4,
 *   array base at 0x28def8, element 0 pre-loaded at 0x28defc,
 *   walk by pre-incremented pointer 0x28df10, index/count compare 0x28df20.
 *
 * index_cell models the [sp+0x2c] stack word.  It is initialised ONCE before
 * the outer loop (0x28dea0) and NOT re-initialised per constraint: a miss
 * leaves the previous constraint's index in place, and the driver then stores
 * that stale value into the next timeline's +0x14 (0x28df94).  This is the
 * sharpest difference from the ik and transform families, where a miss leaves
 * the timeline's own create-time word alone.
 *
 * Returns 1 when it updated *index_cell, 0 when it fell through.  The value is
 * a reconstruction artefact: both original exits go to 0x28df30.
 */
int readSkeletonData_pathConstraintIndex(void* data_raw, void* pc_raw,
                                         int32_t* index_cell);

/*
 * The scale selects.  Both produce the s16 multiplier consumed at 0x28dfdc
 * (`vmul.f32 s15,s14,s16` = value * scale) and both end at 0x28df88.
 *
 *   position, 0x28df70..0x28df88:  positionMode != 0 -> 1.0f (0x28e554),
 *                                  positionMode == 0 -> parser->scale (0x28df84)
 *   spacing,  0x28e544..0x28e558:  (uint32)spacingMode <= 1 -> parser->scale
 *                                  (0x28ea74), otherwise 1.0f (0x28e554)
 * The spacing test is `bls` (unsigned <=), so a negative spacingMode value is
 * NOT <= 1 and takes the 1.0f branch.
 */
float readSkeletonData_pathPositionScale(const void* parser_raw, const void* pc_raw);
float readSkeletonData_pathSpacingScale(const void* parser_raw, const void* pc_raw);

/*
 * B13 frame loop, 0x28dfa4..0x28e00c.
 * Keys and defaults come from the instruction stream, not from any stock
 * spine source:
 *   "time"          @0x34c1d4 (pool 0x28eab0, add 0x28dea8 -> [sp+0x3c])
 *                   default 0.0f (0x28dfac mov r2,#0)
 *   <timelineNode->name>  r6, i.e. the sub-key itself ("position" or
 *                   "spacing"); default 0.0f (0x28dfbc mov r2,#0)
 * The value key is therefore NOT a literal: the same code reads "position"
 * for a position timeline and "spacing" for a spacing one.
 * The multiplier s16 is applied here (0x28dfdc) even when it is exactly 1.0f.
 */
void readSkeletonData_pathTimelineFrames(Json* timelineNode, void* timeline_raw,
                                         float scale);

/*
 * E7 (census §5.4 "0x28ea48"): `Path constraint not found: `.
 *   0x28ea48 ldr  r8,[sp,#0x20]   parser
 *   0x28ea4c mov  r0,r11          animation
 *   0x28ea50 ldr  r9,[sp,#0x18]   data
 *   0x28ea54 bl   spAnimation_dispose
 *   0x28ea58 ldr  r2,[pc,#0xc0]   pool 0x28eb20 -> 0x357f10
 *   0x28ea5c mov  r0,r8           parser
 *   0x28ea60 ldr  r1,[sp,#0x1c]   json argument = CURRENT ANIMATION NODE
 *   0x28ea64 ldr  r3,[r10,#0x1c]  extra = the path node's member key
 *   0x28ea68 add  r2,pc,r2
 *   0x28ea6c bl   _spSkeletonJson_setError
 *   0x28ea70 b    0x28da44        common tail: spSkeletonData_dispose, NULL
 * The json argument is the animation node (0x28d2c8 stored animations->child
 * there), the SAME shape the bones family uses for "Bone not found: ", and
 * unlike the slot family's root/NULL forms — read from this block's own
 * instructions, not assumed.
 */
int readSkeletonData_pathConstraintNotFound(Json* pathNode, Json* animationJson,
                                            void* data_raw, void* animation_raw,
                                            void* parser_raw);

/*
 * B13 driver: 0x28de74..0x28e060 plus the out-of-line spacing/islands.
 *   paths_map    : the "paths" JSON child (parent B3 caches it at [sp+0x44] at
 *                  0x28d370; B13 loads it at 0x28de74 before reusing that slot
 *                  for the second "spacing" literal).
 *   animation_json: the current animation JSON node (parent [sp+0x1c], set at
 *                  0x28d2c8).  Only the E7 error path consumes it, as the
 *                  setError json argument (0x28ea60 ldr r1,[sp,#0x1c]).
 *   data_raw     : spSkeletonData* (parent [sp+0x18]).
 *   animation_raw: spAnimation* (parent r11).
 *   parser_raw   : spSkeletonJson* (parent [sp+0x20], 0x28d314; +0x00 scale).
 * Returns PATH_TL_REACHED_DEFORM, PATH_TL_ERROR or PATH_TL_HANDOFF_MIX.
 */
int readSkeletonData_pathTimelines(Json* paths_map, Json* animation_json,
                                   void* data_raw, void* animation_raw,
                                   void* parser_raw);

#endif /* YY_SPINE_READ_TL_PATH_H */
