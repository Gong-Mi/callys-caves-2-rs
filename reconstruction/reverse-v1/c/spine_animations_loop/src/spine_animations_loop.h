/*
 * spine_animations_loop.h — the per-animation loop of
 * spSkeletonJson_readSkeletonData (0x28b84c, 13044 B) in libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * This module owns NO new timeline bytes.  It is the assembly layer that the
 * nine recovered family modules and the B1..B4 entry blocks were built for:
 * it walks the animations child list once (outer loop head 0x28d318, back
 * edge 0x28e79c) and, per animation, runs
 *
 *   B3  readSkeletonData_animationKeys         0x28d318..0x28d3b4
 *   B4  readSkeletonData_animationTimelines    0x28d3b4..0x28d4ec
 *   B5  readSkeletonData_slotTimelines         0x28d4ec..0x28d640
 *   B6  readSkeletonData_boneTimelines         0x28d640..0x28d840
 *   B7  readSkeletonData_ikTimelines           0x28d840..0x28dca8
 *   B12 readSkeletonData_transformTimelines    0x28dca8..0x28de74
 *   B13 readSkeletonData_pathTimelines         0x28de74..0x28e060
 *   B17 readSkeletonData_pathMixTimeline       0x28e8ec..0x28ea0c (interleaved)
 *   B14 readSkeletonData_deformTimelines       0x28e060..0x28e338
 *   B15 readSkeletonData_drawOrderTimelines    0x28e338..0x28e614
 *   B16 readSkeletonData_eventTimelines        0x28e614..0x28e774
 *   --  readSkeletonData_publishAnimation      0x28e774..0x28e79c
 *
 * FAMILY ORDER IS READ OFF THE CONTROL FLOW, NOT OFF ADDRESSES
 * ------------------------------------------------------------
 * The stage order above is not "lowest address first"; it is the chain of
 * fall-throughs and branches that B4 enters after `spAnimation_create`:
 *
 *   0x28d4e8 beq 0x28d640   (no slots child -> bones directly)
 *   0x28d640 ldr r3,[sp,#0x30]  B6 head; 0x28d648 beq 0x28d840
 *   0x28d840 ldr r3,[sp,#0x34]  B7 head; 0x28d848 beq 0x28dca8
 *   0x28dca8 ldr r0,[sp,#0x38]  B12 head; 0x28dcb0 beq 0x28de74
 *   0x28de74 ldr r1,[sp,#0x44]  B13 head; 0x28de7c beq 0x28e060
 *   0x28e060 ldr r1,[sp,#0x50]  B14 head; 0x28e068 beq 0x28e338
 *   0x28e338 ldr r3,[sp,#0x28]  B15 head; 0x28e340 beq 0x28e614
 *   0x28e614 ldr r2,[sp,#0x4c]  B16 head; 0x28e61c beq 0x28e774
 *   0x28e774..0x28e79c          publish, advance, bne 0x28d318
 *
 * so the sequence is slots -> bones -> ik -> transform -> paths -> deform ->
 * drawOrder -> events.  B17 is not a separate stage: it is entered from
 * B13's 0x28e538 `bne 0x28e8ec` for every path sub-key that is neither
 * "position" nor "spacing", and returns to B13's shared node advance at
 * 0x28e048.  The assembly therefore interleaves it inside the paths stage.
 *
 * THREE HANDOFFS HAVE TO BE COMPLETED HERE
 * ----------------------------------------
 * The family modules deliberately stop at seams that the census attributes to
 * a different address window, and report a handoff code instead of calling a
 * body they do not own.  This module resolves each handoff by re-walking the
 * same JSON list in the same order and handing the exact node to the owner:
 *
 *   slots   rc==0 with parser->error==0   -> B5 slot index == -1
 *           0x28d538 beq 0x28ea10; the 13-instruction block at 0x28ea10 is
 *           owned by no family module, so it is recovered here
 *           (readSkeletonData_animationsSlotNotFound).
 *   path    PATH_TL_HANDOFF_MIX           -> B17 (c/spine_read_tl_path_mix),
 *           then continue B13 at the node's next sibling (0x28e048), which
 *           needs a synthetic one-constraint segment because the B13 driver
 *           only takes a map node.  See the .c for the index-cell argument.
 *   deform  DEFORM_TL_HANDOFF_ATTACHMENT  -> E4 (c/spine_read_tl_draworder)
 *           with the failing attachment timeline node (0x28e110 beq 0x28e55c).
 *   drawOrder DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND -> E6
 *           (c/spine_read_tl_deform) with the failing offsets entry
 *           (0x28e464 beq 0x28e8ac).
 *
 * ITERATION STATE
 * ---------------
 * B4 writes frame->slotsChild only when the "slots" node is present
 * (0x28d4dc/0x28d4e4) and branches to bones when it is absent or childless
 * (0x28d4c8/0x28d4d8/0x28d4e8).  The loop must therefore gate the slots stage
 * on the CURRENT animation's slots node, never on a stale frame->slotsChild
 * left by the previous animation.
 *
 * Evidence tier: bytecode_anchored.  The original was never executed and no
 * original-equivalence claim is made.
 */
#ifndef YY_SPINE_ANIMATIONS_LOOP_H
#define YY_SPINE_ANIMATIONS_LOOP_H

#include <stdint.h>
#include <stddef.h>

#include "json_interface.h"
#include "spine_read_animations.h"

/*
 * readSkeletonData_animationsLoop
 *   firstAnimation : the node B2 returned (animations->child), which B2 also
 *                    spilled into frame->animation at 0x28d2c8.  NULL means
 *                    B2's 0x28d2d0 `beq 0x28e7a4`: the loader goes straight to
 *                    B18 (Json_dispose + return data) and this loop does
 *                    nothing.
 *   frame          : the B3/B4 frame slice, already owned by the caller; this
 *                    function runs readSkeletonData_animationFrameInit() once
 *                    (the B3 preamble that follows B2's non-NULL fall-through)
 *                    and then re-initialises the eight node slots per
 *                    animation through readSkeletonData_animationKeys().
 *   data_raw       : spSkeletonData* (payload +0x34 animationsCount, +0x38
 *                    animations array).
 *   parser_raw     : spSkeletonJson* (payload +0x08 error).
 *
 * Returns data_raw when the outer loop is exhausted (the caller then runs B18:
 * readSkeletonData_finishAnimations(root, data)).  Returns NULL as soon as any
 * family reports an error; in that case the owning error block has already
 * disposed the animation and the whole skeleton data (0x28da44 tail), exactly
 * like the original's shared epilogue at 0x28bdcc, and B18 must NOT run.
 *
 * The loop is a pure consumer of the family modules: it threads their
 * heterogeneous ABIs (frame slots vs map/data/parser) without changing any of
 * them.
 */
void* readSkeletonData_animationsLoop(Json* firstAnimation, spAnimationFrame* frame,
                                      void* data_raw, void* parser_raw);

/*
 * B5 slot-not-found terminal, 0x28ea10..0x28ea3c (13 instructions) plus the
 * shared tail 0x28da44..0x28da50.  Entered only from 0x28d538
 * `beq 0x28ea10` when spSkeletonData_findSlotIndex returned -1; the family
 * module stops at that branch because the block sits outside its window and
 * is unowned by any other module.
 *
 *   0x28ea10 mov  r0,r11          animation
 *   0x28ea14 ldr  r8,[sp,#0x20]   parser
 *   0x28ea18 ldr  r9,[sp,#0x18]   data
 *   0x28ea1c bl   spAnimation_dispose
 *   0x28ea20 ldr  r2,[sp,#0x2c]   the CURRENT slot node (B5 rewrites that slot
 *                                 at 0x28d638 on every iteration)
 *   0x28ea24 mov  r0,r8           parser
 *   0x28ea28 ldr  r1,[sp,#0x1c]   json argument = the CURRENT ANIMATION node
 *   0x28ea2c ldr  r3,[r2,#0x1c]   extra = the slot node's member key
 *   0x28ea30/0x28ea34             r2 = "Slot not found: " @0x357e7c
 *   0x28ea38 bl   _spSkeletonJson_setError
 *   0x28ea3c b    0x28da44        spSkeletonData_dispose(data); return NULL
 */
int readSkeletonData_animationsSlotNotFound(Json* slotNode, Json* animationJson,
                                            void* data_raw, void* animation_raw,
                                            void* parser_raw);

#endif /* YY_SPINE_ANIMATIONS_LOOP_H */
