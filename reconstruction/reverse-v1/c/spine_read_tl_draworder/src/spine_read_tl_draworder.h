/*
 * spine_read_tl_draworder.h — the drawOrder timeline family of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * (SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a).
 *
 * Recovered caller blocks (addresses end-exclusive, census §6):
 *   B15   0x28e338..0x28e55c  548 B / 137 insns — but 12 of those instructions
 *         (0x28e52c..0x28e558) are the path family's out-of-line spacing
 *         island, already recovered by c/spine_read_tl_path.  This module
 *         translates the other 125: the "drawOrder" node read, the create call,
 *         the frame-list loop head, the TWO mallocs (lines 442 / 445), the -1
 *         fill, the offsets->slot-index build, the leftover merge and the
 *         _free of the line-442 array.  0x28e528 `b 0x28e594` is the
 *         unconditional branch that steps over the island, which is how the
 *         boundary is proven from the instruction stream rather than assumed.
 *   B15b  0x28e594..0x28e614  128 B /  32 insns — the shared per-frame tail
 *         (Json_getFloat "time", spDrawOrderTimeline_setFrame, _free of the
 *         line-445 array, frame advance, back edge to 0x28e3b4) and the
 *         publish/duration tail (animation->timelineCount++, timelines[count],
 *         duration = max(duration, times[declared-1])).
 *   E4    0x28e55c..0x28e594   56 B /  14 insns — "Attachment not found: ":
 *         spAnimation_dispose, _spSkeletonJson_setError with a NULL json
 *         argument, then the common error tail 0x28da44 (spSkeletonData_dispose,
 *         return NULL).  Its 14th instruction, 0x28e590 `mov r6,r4`, is NOT part
 *         of the error block: it is the drawOrder frame loop's "no offsets"
 *         join (r4 = 0 there), translated in readSkeletonData_drawOrderFrame.
 *         E4 is entered from the DEFORM block at 0x28e110 `beq 0x28e55c`, not
 *         from this family — it is translated here because the census address
 *         partition puts it in this window, and the .c states that boundary.
 *
 * Evidence tier: bytecode_anchored.  The original was not executed and no
 * claim of original equivalence is made.  Every statement in the .c carries the
 * original instruction address it comes from; no stock spine source was read.
 *
 * Real recovered bodies this module links against (not re-implemented here):
 *   Json_getItem / Json_getString / Json_getInt / Json_getFloat
 *                                        c/json_interface
 *   spSkeletonData_findSlotIndex         c/skeleton_find (0x28b0cc)
 *   _spSkeletonJson_setError             c/spine_json_error (0x28b784)
 *   spAnimation_dispose                  c/spine_skeleton_data (0x28147c)
 *   spSkeletonData_dispose               c/spine_skeleton_data (0x28adf8)
 *   _malloc / _free                      c/spine_alloc
 *
 * Declared synthetic boundaries (bodies NOT recovered; the fixture provides
 * them from the disassembled bodies and records every argument):
 *   spDrawOrderTimeline_create    0x282d4c / 144 B
 *        _calloc(1,24,tag,672) -> _spTimeline_init(t,7,vtable) (0x282d7c
 *        mov r1,#7 = the timeline type word), +0x08 = frameCount (0x282d94),
 *        +0x0c = _calloc(frameCount,4,tag,676)  times (0x282da4/0x282db4),
 *        +0x10 = _calloc(frameCount,4,tag,677)  drawOrders (0x282db8/0x282dc4),
 *        +0x14 = slotsCount (0x282dc0).
 *   spDrawOrderTimeline_setFrame 0x282ddc / 124 B
 *        ABI read off the body: r0 = timeline, r1 = frameIndex, r2 = time bits,
 *        r3 = int* drawOrder.
 *          +0x0c times[i] = time            [0x282df4/0x282dfc]
 *          _free(drawOrders[i])             [0x282df8/0x282e00]  (0 on 1st call)
 *          drawOrder == 0 -> drawOrders[i] = 0 and return  [0x282e04/0x282e08,
 *                                                       0x282e48/0x282e4c]
 *          else _malloc(slotsCount*4, tag, 690) + memcpy  [0x282e0c..0x282e44]
 *          -> drawOrders[i] = copy         [0x282e34]
 *        The copy is the whole ownership answer: setFrame NEVER keeps the
 *        caller's array, so the caller must free it (0x28e5c0).
 */

#ifndef YY_SPINE_READ_TL_DRAWORDER_H
#define YY_SPINE_READ_TL_DRAWORDER_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"

/*
 * spSkeletonData as observed by this block: only slotsCount is read, at +0x18
 *   [0x28e350 ldr r1,[r3,#0x18]   create arg 2
 *    0x28e3d0 ldr r0,[r8,#0x18]   line-442 size base
 *    0x28e3f0 ldr r0,[r8,#0x18]   line-445 size
 *    0x28e3fc/0x28e4c4/0x28e4e0   fill count, tail-fill bound]
 * Corroborated independently by spSkeletonData_findSlotIndex 0x28b0d4
 * (ldr count,[s,#0x18]) and 0x28b0e0 (ldr table,[s,#0x1c]) — the slot vector is
 * the word pair right after it.  The record is calloc(1,84,tag,37) (0x28ade4),
 * so only the head is modelled here, with the padding kept explicit.
 */
typedef struct spSkeletonDataDrawOrderShape {
    uint32_t pad[6];        /* +0x00..+0x14 */
    int32_t  slotsCount;    /* +0x18 */
} spSkeletonDataDrawOrderShape;      /* 28 B */

/*
 * spDrawOrderTimeline, 24 B, from the create body 0x282d4c:
 *   +0x00 type            [_spTimeline_init 0x281338 str r1,[r0]; r1 = 7]
 *   +0x04 vtable object   [0x281354]
 *   +0x08 frameCount      [0x282d94 str r5,[r4,#0x8], r5 = create's arg 0]
 *   +0x0c float* times    [0x282da4 _calloc(count,4,tag,676) -> 0x282db4]
 *                          B15b reads it at 0x28e5f8 and indexes it with the
 *                          DECLARED count at 0x28e5fc/0x28e600.
 *   +0x10 int** drawOrders[0x282dbc _calloc(count,4,tag,677) -> 0x282dc4]
 *   +0x14 slotsCount      [0x282dc0 str r7,[r4,#0x14], r7 = create's arg 1]
 */
typedef struct spDrawOrderTimelineShape {
    uint32_t type;          /* +0x00 = 7 */
    void*    vtable;        /* +0x04 */
    int32_t  frameCount;    /* +0x08 */
    float*   times;         /* +0x0c one time float per frame */
    int32_t** drawOrders;   /* +0x10 one int* per frame, owned by setFrame */
    int32_t  slotsCount;    /* +0x14 */
} spDrawOrderTimelineShape; /* 24 B */

/*
 * spAnimation fields touched by the publish tail.  Full record owned by
 * spAnimation_create / spAnimation_dispose (c/spine_skeleton_data).
 */
typedef struct spAnimationDrawOrderShape {
    char*   name;           /* +0x00 */
    float   duration;       /* +0x04 read at 0x28e5d8, written at 0x28e610 */
    int32_t timelineCount;  /* +0x08 read 0x28e5dc, written 0x28e5ec */
    void**  timelines;      /* +0x0c read 0x28e5e0, written 0x28e5f4 */
} spAnimationDrawOrderShape;

#if defined(__arm__) && !defined(__aarch64__)
_Static_assert(offsetof(spSkeletonDataDrawOrderShape, slotsCount) == 0x18,
               "0x28e350 ldr r1,[r3,#0x18] / 0x28e3d0 ldr r0,[r8,#0x18]");
_Static_assert(sizeof(spSkeletonDataDrawOrderShape) == 0x1c,
               "head of the 84-byte spSkeletonData record (0x28ade4 calloc(1,84))");
_Static_assert(offsetof(spDrawOrderTimelineShape, frameCount) == 0x08,
               "0x282d94 str r5,[r4,#0x8]");
_Static_assert(offsetof(spDrawOrderTimelineShape, times) == 0x0c,
               "0x282db4 str r0,[r4,#0xc] / 0x28e5f8 ldr r3,[r0,#0xc]");
_Static_assert(offsetof(spDrawOrderTimelineShape, drawOrders) == 0x10,
               "0x282dc4 str r0,[r4,#0x10]");
_Static_assert(offsetof(spDrawOrderTimelineShape, slotsCount) == 0x14,
               "0x282dc0 str r7,[r4,#0x14]");
_Static_assert(sizeof(spDrawOrderTimelineShape) == 24,
               "0x282d60 mov r1,#24 ; _calloc(1,24,tag,672)");
_Static_assert(offsetof(spAnimationDrawOrderShape, duration) == 0x04,
               "0x28e5d8 vldr s14,[r11,#4] / 0x28e610 vstr s15,[r11,#4]");
_Static_assert(offsetof(spAnimationDrawOrderShape, timelineCount) == 0x08,
               "0x28e5dc ldr r3,[r11,#0x8]");
_Static_assert(offsetof(spAnimationDrawOrderShape, timelines) == 0x0c,
               "0x28e5e0 ldr r1,[r11,#0xc]");
#endif

/*
 * The malloc tag every allocation in this family passes: 0x28e37c ldr r2,
 * [pc,#0x750] -> pool 0x28ead4 -> 0x357b08, spilled to [sp+0x30] and reloaded
 * at 0x28e3d4 and 0x28e3e4.  Same literal setError uses (0x28b7f8).
 */
#define SPINE_JSON_SOURCE_TAG "jni/../jni/yoyo/../../../spine-c/src/spine/SkeletonJson.c"

/* Malloc source lines, read from the two movw immediates:
 * 0x28e3cc movw r2,#0x1ba = 442 ; 0x28e3e8 movw r2,#0x1bd = 445. */
#define DRAWORDER_LINE_LEFTOVERS 442u
#define DRAWORDER_LINE_ORDER     445u

/*
 * Declared synthetic boundaries.  Bodies NOT recovered; see the block comment.
 *   spDrawOrderTimeline_create(frameCount, slotsCount)      0x282d4c
 *   spDrawOrderTimeline_setFrame(timeline, frameIndex, time, drawOrder) 0x282ddc
 */
extern void* spDrawOrderTimeline_create(int frameCount, int slotsCount);
extern void  spDrawOrderTimeline_setFrame(void* timeline, int frameIndex,
                                          float time, const int32_t* drawOrder);

/* spSkeletonData_findSlotIndex (0x28b0cc / 88 B) is a REAL recovered body in
 * c/skeleton_find; this module links it rather than declaring a boundary.  Its
 * own +0x18 count load corroborates the slotsCount offset used here. */

/* Driver return codes.  The original has exactly these exits from the
 * family: fall through to the event block, or leave for the out-of-range
 * slot-miss error block, or (from E4) return NULL through the common tail. */
#define DRAWORDER_TL_OK         1  /* 0x28e340 / 0x28e5d4..0x28e610 -> 0x28e614 */
#define DRAWORDER_TL_ERROR      0  /* E4: 0x28e58c b 0x28da44 -> NULL */
#define DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND 2
                                   /* 0x28e464 beq 0x28e8ac — outside this
                                    * window, so the driver only reports it */

/*
 * One frame's draw order, 0x28e3b4..0x28e528 plus the 0x28e590 join.
 *
 * Two allocations, both owned by the CALLER (the original frees each in a
 * different place and neither pointer survives the iteration):
 *   A = _malloc((slotsCount - jsonOffsetsSize) * 4, tag, 442)
 *       the "leftover" slot indices, 0x28e3cc..0x28e3e0; freed at 0x28e524
 *       once the merge has copied what it needs.  Never leaves this function.
 *   B = _malloc(slotsCount * 4, tag, 445), every element set to -1
 *       0x28e3e8..0x28e420 (mvnpl r0,#0 ; 0x28e418 str r0,[r2,#-0x4]!);
 *       handed back through *out_order so the caller can pass it to setFrame
 *       (0x28e5b4/0x28e5b8) and then _free it (0x28e5bc/0x28e5c0).
 *
 * *out_order = 0 when the frame has no "offsets" member (0x28e3c0 beq
 * 0x28e590, where r4 = 0).  A slot-name miss returns
 * DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND with BOTH arrays still allocated: the
 * original jumps to 0x28e8ac without a _free, so the leak is reproduced, not
 * repaired.
 */
int readSkeletonData_drawOrderFrame(Json* frame, void* data_raw,
                                    int32_t** out_order);

/*
 * The frame-list loop, 0x28e35c..0x28e5d0 (head 0x28e3b4, back edge 0x28e5cc).
 * For every frame: build the order array (above), Json_getFloat "time" with a
 * 0.0f default (0x28e594..0x28e5a0), setFrame (0x28e5b8), _free(order)
 * (0x28e5c0), frameIndex++ (0x28e5ac), frame = frame->next (0x28e5c4).
 * There is NO readCurve call in this family (census §2.9: the 8 readCurve
 * sites do not include this block), so this driver has no curve link gate.
 */
int readSkeletonData_drawOrderTimelineFrames(Json* drawOrder_json, void* data_raw,
                                             void* timeline_raw);

/*
 * B15 driver: 0x28e338..0x28e358 (node test + create), the frame loop and the
 * publish tail 0x28e5d4..0x28e610.
 *   drawOrder_json : the "drawOrder" JSON child (parent B3 picks "drawOrder"
 *                    first and falls back to the legacy "draworder" at
 *                    0x28eb28; both land here with the node in [sp+0x28]).
 *                    Its +0x0c is the DECLARED frame count handed to create
 *                    (0x28e34c) and used again for the duration index
 *                    (0x28e5e4/0x28e5fc).
 *   data_raw       : spSkeletonData* — +0x18 slotsCount only.
 *   animation_raw  : spAnimation* — +0x04/+0x08/+0x0c.
 * Returns DRAWORDER_TL_OK (event block) or the slot-miss handoff.
 */
int readSkeletonData_drawOrderTimelines(Json* drawOrder_json, void* data_raw,
                                        void* animation_raw);

/*
 * E4, 0x28e55c..0x28e58c plus the common tail 0x28da44..0x28da50:
 * "Attachment not found: ".
 *   0x28e55c mov r5,r8     r8 is the spSkin_getAttachment result, and the
 *                          only way here is 0x28e10c subs r8,r0,#0 ;
 *                          0x28e110 beq 0x28e55c -> r8 == 0.
 *   0x28e560 mov r0,r10    animation
 *   0x28e564 ldr r8,[sp,#0x20]   parser
 *   0x28e568 mov r7,r9     the attachment timeline node
 *   0x28e56c ldr r9,[sp,#0x18]   data
 *   0x28e570 bl spAnimation_dispose
 *   0x28e574/0x28e584 "Attachment not found: "
 *   0x28e578 mov r1,r5     JSON ARGUMENT = NULL (r5 = 0 above), not the
 *                          animation node, not the root tree
 *   0x28e580 ldr r3,[r7,#0x1c]   extra = the attachment timeline's name
 *   0x28e588 bl _spSkeletonJson_setError
 *   0x28e58c b 0x28da44    spSkeletonData_dispose(data) then return NULL
 * Returns DRAWORDER_TL_ERROR.
 */
int readSkeletonData_attachmentNotFound(Json* attachmentNode, void* data_raw,
                                        void* animation_raw, void* parser_raw);

/* ------------------------------------------------------------------ */
/* Ownership summary (census §7 open #4) — closed by the two bodies:  */
/*   A (line 442) : caller-owned scratch.  _free at 0x28e524 inside   */
/*                  readSkeletonData_drawOrderFrame, before setFrame. */
/*   B (line 445) : caller-owned, -1 filled, passed to setFrame at    */
/*                  0x28e5b8 and _free'd at 0x28e5c0 RIGHT AFTER.     */
/*   setFrame     : keeps neither.  It frees the slot's previous      */
/*                  pointer, then mallocs its own slotsCount*4 copy   */
/*                  (line 690) and memcpys B into it.                 */
/* So the timeline owns a private copy; the reader owns both mallocs  */
/* and releases them in the same iteration.                           */
/* ------------------------------------------------------------------ */

#endif /* YY_SPINE_READ_TL_DRAWORDER_H */
