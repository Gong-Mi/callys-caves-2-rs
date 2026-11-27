/*
 * spine_read_tl_deform.h — the deform timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B14   0x28e060..0x28e338  728 B / 182 insns — the largest block of the
 *         segment.  deform map -> skin node -> slot node -> attachment node
 *         ("timeline" node, its JSON name is the attachment name) -> frames.
 *         It owns the weighted/non-weighted vertex-count split (0x28e114..
 *         0x28e140), the line-388 _malloc (0x28e154), spDeformTimeline_create
 *         (0x28e164), the +0x1c/+0x20 stores (0x28e178/0x28e17c), the frame
 *         loop head 0x28e19c and its readCurve call site 0x28e2a8, the
 *         per-timeline _free (0x28e2c8) and the one-float-frame-stride publish
 *         tail (0x28e2cc..0x28e308).
 *   B14b  0x28e820..0x28e880   96 B / 24 insns — out-of-line island: the
 *         "vertices" key absent branch (weighted -> memset the whole buffer,
 *         non-weighted -> reuse attachment->vertices at +0x1c) and the
 *         scale != 1.0f copy that multiplies every frame element by
 *         parser->scale (0x28e848..0x28e87c).
 *   E6    0x28e8ac..0x28e8ec   64 B / 16 insns — "Slot not found: ".
 *         MEASURED CORRECTION to the task label: E6 is NOT on the deform path.
 *         Its only predecessor in the whole 13044-byte function is
 *         0x28e464 `beq 0x28e8ac`, inside the drawOrder offsets loop (B15),
 *         where findSlotIndex returned -1.  B14 stores the findSlotIndex
 *         result at [sp+0x3c] and at 0x28e0fc feeds it to spSkin_getAttachment
 *         with NO -1 test, so the deform family has no slot-not-found error.
 *         E6 is recovered here because this module owns its bytes; its caller
 *         context (r11 = animation from [sp+0x38], r8 = parser from
 *         [sp+0x20], r7 = the offsets node, [sp+0x34] = "slot") is read from
 *         the B15 instructions and documented per line in the .c.
 *
 * Out-of-scope neighbour that B14 branches to but this module does NOT
 * translate:
 *   E4  0x28e55c..0x28e590  "Attachment not found: " — reached by 0x28e110
 *       `beq 0x28e55c` when spSkin_getAttachment returns NULL.  The driver
 *       reports DEFORM_TL_HANDOFF_ATTACHMENT instead of translating it.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries
 * the original instruction address it comes from.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getItem / Json_getInt / Json_getFloat / Json_getString
 *                                        c/json_interface
 *   readCurve                            c/spine_read_curve (0x28b34c,
 *                                        anonymous; call site 0x28e2a8)
 *   spSkeletonData_findSkin / findSlotIndex
 *                                        c/skeleton_find (0x28b124 / 0x28b0cc)
 *   spSkin_getAttachment                 c/spine_skin (0x28ed00)
 *   _spSkeletonJson_setError             c/spine_json_error (0x28b784)
 *   spAnimation_dispose / spSkeletonData_dispose
 *                                        c/spine_skeleton_data
 *   _malloc / _free                     c/spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them and records the argument sequence):
 *   spDeformTimeline_create       0x282e58 / 160 B
 *        calloc(1,36,tag,0x30f); _spCurveTimeline_init(t, 8, frameCount, ...);
 *        +0x0c = frameCount (0x282eac), +0x10 = calloc(frameCount,4,tag,0x312)
 *        (0x282eb4..0x282ecc), +0x14 = the SECOND argument (0x282ed8),
 *        +0x18 = calloc(frameCount,4,tag,0x313) (0x282ed0..0x282edc).
 *   spDeformTimeline_setFrame     0x282ef8 / 124 B
 *        r0 = timeline, r1 = frameIndex, r2 = time bits, r3 = vertices ptr.
 *        frames[i] = time (0x282f18); free(old vertices[i]) (0x282f14/0x282f1c);
 *        vertices[i] = NULL for a NULL argument (0x282f68), otherwise
 *        _malloc(timeline->+0x14 * 4, tag, 799) + memcpy (0x282f3c..0x282f60).
 *        So +0x14 — the create argument this module computes — is the exact
 *        per-frame float count the timeline copies.
 */

#ifndef YY_SPINE_READ_TL_DEFORM_H
#define YY_SPINE_READ_TL_DEFORM_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"
#include "../../spine_json_layout.h"          /* spSkeletonJson (+0x00 scale) */
#include "../../spine_skeleton_data/src/spine_skeleton_data.h"
#include "../../skeleton_find/src/skeleton_find.h"  /* real findSkin/findSlotIndex */

/*
 * The three spVertexAttachment words B14 reads (canonical record:
 * c/spine_atlas_attachment/src/spine_atlas_attachment.h, 0x24 B):
 *   +0x14 bones           [0x28e114 ldr r3,[r8,#0x14] — NULL/NULL test is the
 *                          weighted gate; non-NULL means the weight/bone stream
 *                          exists]
 *   +0x18 verticesCount   [0x28e12c ldrne r3,[r8,#0x18] ; 0x28e130 ldreq r11,
 *                          [r8,#0x18]] — the float count of the +0x1c stream
 *   +0x1c vertices        [0x28e24c ldr r2,[r8,#0x1c] (base addend) ;
 *                          0x28e828 ldreq r6,[r8,#0x1c] (frame pointer)]
 * +0x10 (boneCount) and +0x20 (worldVerticesLength) are not read by B14; they
 * are kept so the offsets and the 0x24 size are pinned rather than padded.
 */
typedef struct spVertexAttachmentDeformShape {
    uint32_t     pad[4];            /* +0x00..+0x0c spAttachment super */
    uint32_t     boneCount;         /* +0x10 (not read here) */
    void*        bones;             /* +0x14 weighted gate */
    int32_t      verticesCount;     /* +0x18 vertex/weight float count */
    const float* vertices;          /* +0x1c base vertex/weight stream */
    uint32_t     worldVerticesLength; /* +0x20 (not read here) */
} spVertexAttachmentDeformShape;   /* 0x24 B */

/*
 * spDeformTimeline as observed by B14 and by the creator/setFrame pair:
 *   +0x00 type            [_spCurveTimeline_init -> _spTimeline_init 0x281338
 *                          str r1,[r0], r1 = 8 from 0x282e90]
 *   +0x04 vtable object   [0x281354 str r0,[r4,#0x4]]
 *   +0x08 float* curves   [_spCurveTimeline_init 0x281700..0x281710]
 *   +0x0c int frameCount  [0x282eac str r5,[r4,#0xc]]
 *   +0x10 float* frames   [0x282ec4 ldr? calloc -> 0x282ecc str [r4,#0x10];
 *                          ONE float (time) per frame — 0x28e2f0 add
 *                          r3,r3,r2,lsl#2 and 0x28e2f4 vldr [r3,#-4]]
 *   +0x14 int vertexFloatCount [0x282ed8 str r7,[r4,#0x14] = create's arg 2;
 *                          the count setFrame copies at 0x282f3c/0x282f4c]
 *   +0x18 void** vertices [0x282edc str r0,[r4,#0x18]; one pointer per frame]
 *   +0x1c int slotIndex   [B14 ONLY writer: 0x28e178 str r3,[r0,#0x1c]]
 *   +0x20 void* attachment[B14 ONLY writer: 0x28e17c str r8,[r0,#0x20]]
 * The 36-byte size is calloc(1,36,tag,0x30f) at 0x282e74/0x282e78.
 */
typedef struct spDeformTimelineShape {
    uint32_t type;             /* +0x00 */
    void*    vtable;           /* +0x04 */
    float*   curves;           /* +0x08 */
    int32_t  frameCount;       /* +0x0c */
    float*   frames;           /* +0x10 1 float per frame */
    int32_t  vertexFloatCount; /* +0x14 create arg 2, the per-frame copy count */
    void**   vertices;         /* +0x18 1 pointer per frame */
    int32_t  slotIndex;        /* +0x1c */
    void*    attachment;       /* +0x20 */
} spDeformTimelineShape;       /* 36 B */

/* spAnimation fields touched by the publish tail (same shape as the other
 * timeline families; the record is owned by spAnimation_create/dispose). */
typedef struct spAnimationDeformShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read/extended by the tail */
    int32_t timelineCount;  /* +0x08 */
    void**  timelines;      /* +0x0c */
} spAnimationDeformShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spVertexAttachmentDeformShape, bones) == 0x14,
               "0x28e114 ldr r3,[r8,#0x14]");
_Static_assert(offsetof(spVertexAttachmentDeformShape, verticesCount) == 0x18,
               "0x28e12c ldrne r3,[r8,#0x18] / 0x28e130 ldreq r11,[r8,#0x18]");
_Static_assert(offsetof(spVertexAttachmentDeformShape, vertices) == 0x1c,
               "0x28e24c ldr r2,[r8,#0x1c] / 0x28e828 ldreq r6,[r8,#0x1c]");
_Static_assert(sizeof(spVertexAttachmentDeformShape) == 0x24,
               "canonical spVertexAttachment is 0x24 B");
_Static_assert(offsetof(spDeformTimelineShape, frameCount) == 0x0c,
               "0x282eac str r5,[r4,#0xc]");
_Static_assert(offsetof(spDeformTimelineShape, frames) == 0x10,
               "0x282ecc str r0,[r4,#0x10] / 0x28e2e8 ldr r3,[r7,#0x10]");
_Static_assert(offsetof(spDeformTimelineShape, vertexFloatCount) == 0x14,
               "0x282ed8 str r7,[r4,#0x14]");
_Static_assert(offsetof(spDeformTimelineShape, vertices) == 0x18,
               "0x282edc str r0,[r4,#0x18]");
_Static_assert(offsetof(spDeformTimelineShape, slotIndex) == 0x1c,
               "0x28e178 str r3,[r0,#0x1c]");
_Static_assert(offsetof(spDeformTimelineShape, attachment) == 0x20,
               "0x28e17c str r8,[r0,#0x20]");
_Static_assert(sizeof(spDeformTimelineShape) == 36,
               "0x282e74/0x282e78 calloc(1,36,tag,0x30f)");
_Static_assert(offsetof(spAnimationDeformShape, duration) == 0x04,
               "0x28e2d4 vldr s14,[r10,#4]");
_Static_assert(offsetof(spAnimationDeformShape, timelineCount) == 0x08,
               "0x28e2cc ldr r3,[r10,#0x8]");
_Static_assert(offsetof(spAnimationDeformShape, timelines) == 0x0c,
               "0x28e2d0 ldr r1,[r10,#0xc]");
_Static_assert(offsetof(spSkeletonJson, scale) == 0x00,
               "0x28e1e4 vldr s15,[r0] with r0 = parser");
#endif

/* Binary32 reinterpretation of spSkeletonJson.scale: the word 0x28e1e4 loads.
 * spSkeletonJson_createWithLoader writes 0x3f800000 at 0x28b720/0x28b728. */
static inline float spSkeletonJson_deform_scale_float(const spSkeletonJson* parser)
{
    float f;
    __builtin_memcpy(&f, &parser->scale, sizeof f);
    return f;
}

/* Declared synthetic boundaries (see the block comment above). */
extern void* spDeformTimeline_create(int frameCount, int vertexFloatCount);
extern void  spDeformTimeline_setFrame(void* timeline, int frameIndex,
                                       float time, const void* vertices);

/* Driver return codes.  B14 has three exits: */
#define DEFORM_TL_REACHED_DRAWORDER   1  /* 0x28e068 / 0x28e07c / 0x28e334 */
#define DEFORM_TL_ERROR               0  /* not produced by B14 itself */
#define DEFORM_TL_HANDOFF_ATTACHMENT  3  /* 0x28e110 beq 0x28e55c -> E4 */

/*
 * B14's vertex-count conversion, 0x28e114..0x28e140.
 *
 *   weighted = (attachment->bones != NULL)            0x28e114..0x28e124
 *   weighted:  r11 = 2 * (signed)(verticesCount / 3)  0x28e128..0x28e140
 *   else:      r11 = verticesCount                    0x28e130
 *
 * The division is the 0x55555556 magic that B3 materialises into [sp+0x60]
 * (0x28d2d8 movw r1,#0x5556 ; 0x28d2e0 movt r1,#0x5555 ; 0x28d304 str
 * r1,[sp,#0x60]) and B14 is its ONLY reader in the whole function:
 *   0x28e134 smullne r1,r2,r1,r3       ; r2 = high word of magic * v
 *   0x28e13c subne   r3,r2,r3,asr#31   ; q = high - (v >> 31) = v / 3 (trunc)
 *   0x28e140 lslne   r11,r3,#1         ; 2*q
 * Signed right shift by 31 gives -1 for negative v, so the correction makes
 * the division truncate toward zero exactly like C's `/`.  The checker drives
 * 25 values (including INT_MIN) through readSkeletonData_deformWeightedDivide3
 * and compares them with a bit-exact model of the smull sequence.
 */
int32_t readSkeletonData_deformWeightedDivide3(int32_t vertexCount);

/* The full branch: weighted -> 2*(v/3), non-weighted -> v. */
int32_t readSkeletonData_deformVertexFloatCount(const void* attachment_raw);

/*
 * B14 frame loop, 0x28e19c..0x28e2c0 plus the B14b islands.
 * Keys (all literal, resolved by the checker):
 *   "vertices" @0x357afc (0x28e1a4 Json_getItem)
 *   "offset"   @0x357f44 (0x28e1c0 Json_getInt, default 0)
 *   "time"     @0x34c1d4 (0x28e284 Json_getFloat, default 0.0f)
 * Per frame:
 *   verticesJson = getItem(frame,"vertices"); offset = getInt(frame,"offset",0);
 *   memset(buffer, 0, offset*4)                              0x28e1c8..0x28e1dc
 *   if verticesJson == NULL:                                0x28e1ac beq
 *       weighted  -> memset(buffer,0,floatCount*4), src=buffer  0x28e830..0x28e844
 *       otherwise -> src=attachment->vertices (+0x1c)           0x28e828
 *   else:
 *       dst = buffer + offset;
 *       scale == 1.0f ? copy float bits : copy scale*value  0x28e1f8..0x28e878
 *       memset(buffer + written, 0, (floatCount - written)*4)   0x28e224..0x28e238
 *       src = buffer
 *   if !weighted && floatCount > 0:
 *       buffer[i] += attachment->vertices[i] for all i     0x28e23c..0x28e270
 *   setFrame(timeline, frameIndex, time, src)              0x28e288..0x28e298
 *   readCurve(frame, timeline, frameIndex)                 0x28e29c..0x28e2a8
 * The loop follows frame->next, not the declared count (0x28e2ac/0x28e2c0).
 */
void readSkeletonData_deformTimelineFrames(Json* timelineNode,
                                           const void* attachment_raw,
                                           void* timeline_raw, float* buffer,
                                           int32_t floatCount, int32_t weighted,
                                           const void* parser_raw);

/*
 * B14 driver, 0x28e060..0x28e338.
 *   deform_map : the "deform" JSON child (parent B3 caches it at [sp+0x50];
 *                B14 loads it at 0x28e060 and REUSES that slot for the malloc
 *                tag at 0x28e0a0).
 *   data_raw   : spSkeletonData* (parent [sp+0x18]) — real findSkin /
 *                findSlotIndex / getAttachment walk it.
 *   animation_raw : spAnimation* (parent r11, saved in r10 at 0x28e084).
 *   parser_raw : spSkeletonJson* (parent [sp+0x20], +0x00 scale).
 * Return: DEFORM_TL_REACHED_DRAWORDER when the block falls into 0x28e338,
 *         DEFORM_TL_HANDOFF_ATTACHMENT at 0x28e110 (E4 owns the rest).
 */
int readSkeletonData_deformTimelines(Json* deform_map, void* data_raw,
                                     void* animation_raw, void* parser_raw);

/*
 * E6 (census §5.4 "0x28e8ac"): `Slot not found: `.
 * Measured caller: B15 drawOrder offsets loop, 0x28e464 `beq 0x28e8ac`, when
 * spSkeletonData_findSlotIndex returned -1 (0x28e45c cmn r0,#1).
 *   0x28e8ac ldr  r11,[sp,#0x38]   animation (stored at 0x28e3b0)
 *   0x28e8b4 ldr  r8,[sp,#0x20]    parser
 *   0x28e8b8/0x28e8bc              spAnimation_dispose(animation)
 *   0x28e8c0 ldr  r1,[sp,#0x34]    "slot" (materialised at 0x28e39c..0x28e3a4)
 *   0x28e8c4 mov  r0,r7            r7 = the failing offsets array element
 *   0x28e8cc bl   Json_getString(node,"slot",0)
 *   0x28e8d4 mov  r1,#0            json argument = NULL (not root, not node)
 *   0x28e8e4 bl   _spSkeletonJson_setError(parser,NULL,"Slot not found: ",name)
 *   0x28e8e8 b    0x28da44         spSkeletonData_dispose(data); return NULL
 * The "slot" key literal lives in the caller's frame but is read by this
 * block's own Json_getString call, so the function takes it as a literal.
 */
int readSkeletonData_drawOrderSlotNotFound(Json* offsetsNode, void* data_raw,
                                           void* animation_raw, void* parser_raw);

#endif /* YY_SPINE_READ_TL_DEFORM_H */
