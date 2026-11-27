/*
 * spine_animations_loop.c — the per-animation loop of
 * spSkeletonJson_readSkeletonData @0x28b84c, libyoyo_armv7.so
 * SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a.
 *
 * Assembly only: every timeline byte belongs to one of the nine recovered
 * family modules; the B3/B4 bytes belong to c/spine_read_animations.  This
 * file owns the outer loop and the four handoff completions documented in the
 * header, including the previously unowned 0x28ea10 slot-not-found block.
 *
 * Evidence tier: bytecode_anchored; the original was never executed and no
 * original-equivalence claim is made.  Every branch below carries the
 * instruction address it mirrors.
 */

#include "spine_animations_loop.h"
#include "family_includes.h"

#include "../../spine_json_error/src/spine_json_error.h"     /* setError 0x28b784 */
#include "../../skeleton_find/src/skeleton_find.h"           /* findSlotIndex 0x28b0cc */
#include "../../spine_skin/src/spine_skin.h"                 /* getAttachment 0x28ed00 */

/* 0x357e7c — the exact B5 literal (pool 0x28eb1c, add site 0x28ea34,
 * pc 0x28ea3c + 0x000ca440).  Same text as E6, different call site. */
static const char* const ERR_SLOT_NOT_FOUND_B5 = "Slot not found: ";

/*
 * ---------------------------------------------------------------------------
 * 0x28ea10..0x28ea3c — B5 slot-not-found terminal (see header for the full
 * instruction listing).  Order matters and is the original order: dispose the
 * animation, read the slot name from the CURRENT slot node ([sp+0x2c], which
 * B5 refreshes at 0x28d638), then setError, then the shared 0x28da44 tail.
 * ---------------------------------------------------------------------------
 */
int
readSkeletonData_animationsSlotNotFound(Json* slotNode, Json* animationJson,
                                        void* data_raw, void* animation_raw,
                                        void* parser_raw)
{
    spAnimation_dispose((spAnimation*)animation_raw);              /* 0x28ea1c */
    _spSkeletonJson_setError((spSkeletonJson*)parser_raw,
                             animationJson,                        /* 0x28ea28 */
                             ERR_SLOT_NOT_FOUND_B5,                /* 0x28ea30/0x28ea34 */
                             slotNode->name);                      /* 0x28ea2c */
    spSkeletonData_dispose((spSkeletonData*)data_raw);             /* 0x28ea3c -> 0x28da48 */
    return 0;                                                      /* 0x28da4c/0x28da50 */
}

/*
 * ---------------------------------------------------------------------------
 * Handoff resolution helpers.
 *
 * Each one re-walks the SAME JSON list that the family driver just walked, in
 * the same order, using the same lookup functions, and returns the node the
 * driver stopped on.  They never build a timeline and never publish; the
 * semantic work stays in the family module and in the owner of the error
 * block.  (The alternative — teaching the family module to return the node —
 * is impossible without editing it, and the ABI is frozen for this batch.)
 * ---------------------------------------------------------------------------
 */

/* Slots: 0x28d520..0x28d538 `findSlotIndex(slotMap->name) == -1`.  Only
 * consulted when the family returned 0 and parser->error is still NULL, i.e.
 * the silent -1 branch rather than E1 (which always runs setError). */
static Json*
slot_index_miss(Json* slotMap, void* data_raw)
{
    while (slotMap != 0) {
        if (spSkeletonData_findSlotIndex((spSkeletonData*)data_raw, slotMap->name) == -1)
            return slotMap;
        slotMap = slotMap->next;
    }
    return 0;
}

/* Deform: B14's triple loop 0x28e0b4/0x28e0dc/0x28e0fc, stopping at the first
 * spSkin_getAttachment() == NULL (0x28e10c/0x28e110 beq 0x28e55c). */
static Json*
deform_attachment_miss(Json* deform_map, void* data_raw)
{
    Json* skinNode;

    if (deform_map == 0) return 0;                     /* 0x28e068 beq */
    for (skinNode = deform_map->child; skinNode != 0; skinNode = skinNode->next) {
        spSkin* skin = spSkeletonData_findSkin((spSkeletonData*)data_raw, skinNode->name);
        Json* slotNode;
        for (slotNode = skinNode->child; slotNode != 0; slotNode = slotNode->next) {
            int32_t slotIndex = spSkeletonData_findSlotIndex((spSkeletonData*)data_raw,
                                                             slotNode->name);
            Json* tlNode;
            for (tlNode = slotNode->child; tlNode != 0; tlNode = tlNode->next) {
                if (spSkin_getAttachment(skin, (uint32_t)slotIndex, tlNode->name) == 0)
                    return tlNode;                     /* 0x28e110 */
            }
        }
    }
    return 0;
}

/* drawOrder: B15's offsets loop 0x28e3b4..0x28e464, stopping at the first
 * entry whose "slot" name misses (0x28e45c/0x28e464 beq 0x28e8ac). */
static Json*
draworder_slot_miss(Json* drawOrder_json, void* data_raw)
{
    Json* frame;

    if (drawOrder_json == 0) return 0;                 /* 0x28e338/0x28e340 */
    for (frame = drawOrder_json->child; frame != 0; frame = frame->next) {
        Json* offsets = Json_getItem(frame, "offsets"); /* 0x28e3b4..0x28e3bc */
        Json* entry;
        if (offsets == 0) continue;                     /* 0x28e3c4 beq */
        for (entry = offsets->child; entry != 0; entry = entry->next) {
            const char* name = Json_getString(entry, "slot", 0);  /* 0x28e440..0x28e44c */
            if (spSkeletonData_findSlotIndex((spSkeletonData*)data_raw, name) == -1)
                return entry;                           /* 0x28e464 */
        }
    }
    return 0;
}

/*
 * Paths stage: B13 with B17 interleaved.
 *
 * B13's driver (c/spine_read_tl_path) processes a whole "paths" map and stops
 * at the first sub-key that is neither "position" nor "spacing", returning
 * PATH_TL_HANDOFF_MIX.  In the original that node is handled by B17 and
 * control returns to the SHARED node advance 0x28e048, still inside B13's
 * inner loop — later siblings and later constraints keep being processed.
 * The driver's ABI cannot be resumed mid-constraint, so this stage re-enters
 * it with synthetic wrapper nodes:
 *
 *   - a synthetic map whose ->child is the node to (re)start from;
 *   - after a handoff with a remaining sibling T->next, a synthetic
 *     constraint whose ->name is the real constraint's member key (B13 looks
 *     it up by name at 0x28ded8) and whose ->child is T->next.
 *
 * Only B13/B17 see these wrappers, and they read nothing else from a map or
 * constraint node (map: +0x04 child; constraint: +0x1c name, +0x04 child,
 * +0x00 next).  Every timeline node handed to create/setFrame/readCurve is
 * the real JSON node.
 *
 * The index-cell argument: B13 keeps one int cell [sp+0x2c] for the WHOLE
 * paths map (initialised at 0x28de94/0x28dea0) and B17 reads it at 0x28e914.
 * A re-entry restarts the driver's local cell at 0, so this stage recomputes
 * the cell for the offending constraint with the same scan
 * (readSkeletonData_pathConstraintIndex).  That is exact for every reachable
 * state: spSkeletonData_findPathConstraint returns an element of the very
 * array the scan compares against (0x28b2f0: linear scan over +0x4c/+0x50),
 * or NULL (which B13 turns into E7 before any timeline is built), so a
 * successful lookup always makes the scan hit and overwrite the cell.  A
 * stale cell could only survive a scan MISS after a successful lookup, which
 * that function cannot produce.
 */
static int
path_stage(spAnimationFrame* frame, void* data_raw, void* animation_raw,
           void* parser_raw)
{
    Json* cur;
    Json* resume = 0;
    Json sub = {0};

    if (frame->paths == 0)                             /* 0x28de74..0x28de7c */
        return 1;
    cur = frame->paths->child;                         /* 0x28de80..0x28de84 */
    if (cur == 0)                                      /* 0x28de88..0x28de8c */
        return 1;

    while (cur != 0) {
        /* Only ->child of a map node and ->name/->child/->next of a
         * constraint node are ever read by B13/B17; the rest of the wrapper
         * is zeroed so no uninitialised word can leak into a future reader. */
        Json segment = {0};
        int rc;

        segment.child = cur;

        rc = readSkeletonData_pathTimelines(&segment, frame->animation,
                                            data_raw, animation_raw, parser_raw);
        if (rc == PATH_TL_REACHED_DEFORM) {            /* 0x28e060 fall-through */
            if (resume == 0)
                return 1;
            cur = resume;
            resume = 0;
            continue;
        }
        if (rc == PATH_TL_ERROR)                       /* 0x28ea48 E7 already ran */
            return 0;

        /* PATH_TL_HANDOFF_MIX: 0x28e538 bne 0x28e8ec.  Locate the exact node
         * the driver stopped on (first sub-key not position/spacing, in
         * document order) and its constraint. */
        {
            Json* c;
            Json* hit = 0;
            Json* t = 0;
            const char* constraint_name;
            int32_t cell = 0;
            void* pc;

            for (c = cur; c != 0; c = c->next) {
                Json* x;
                for (x = c->child; x != 0; x = x->next) {
                    if (strcmp(x->name, "position") != 0 &&
                        strcmp(x->name, "spacing") != 0) {
                        t = x;
                        break;
                    }
                }
                if (t != 0) {
                    hit = c;
                    break;
                }
            }
            if (t == 0 || hit == 0)
                return 0;                              /* cannot happen: driver handed off */
            constraint_name = hit->name;

            /* B13 stored the constraint's hit index in [sp+0x2c] before the
             * inner loop; recompute it with the same scan. */
            pc = spSkeletonData_findPathConstraint(data_raw, constraint_name);
            if (pc != 0)
                (void)readSkeletonData_pathConstraintIndex(data_raw, pc, &cell);

            /* 0x28e8ec..0x28ea0c.  "mix" itself is skipped inside B17. */
            (void)readSkeletonData_pathMixTimeline(t, cell, animation_raw);

            if (t->next != 0) {
                /* Resume B13's inner loop at 0x28e048 for this constraint. */
                sub.name = constraint_name;
                sub.child = t->next;
                if (resume == 0)
                    resume = hit->next;
                cur = &sub;
            } else {
                /* Tail of 0x28e9cc..0x28ea0c falls into 0x28e048 and then
                 * 0x28e054: next constraint. */
                cur = (resume != 0) ? resume : hit->next;
                resume = 0;
            }
        }
    }
    return 1;
}

/*
 * ---------------------------------------------------------------------------
 * One animation, 0x28d318..0x28e79c.
 * ---------------------------------------------------------------------------
 */
static int
animation_pass(spAnimationFrame* frame, void* data_raw, void* parser_raw)
{
    Json* slotsNode;
    spAnimation* animation;

    slotsNode = readSkeletonData_animationKeys(frame);   /* 0x28d318..0x28d3b4 */
    animation = readSkeletonData_animationTimelines(frame, slotsNode);
                                                         /* 0x28d3b4..0x28d4ec */

    /* B5 slots, 0x28d4ec..0x28d640.  Gate on the CURRENT animation's slots
     * node: 0x28d4c8 beq 0x28d640 (node absent) and 0x28d4e8 beq 0x28d640
     * (childless) both skip the stage, and frame->slotsChild is only written
     * by 0x28d4e4 on the surviving path. */
    if (slotsNode != 0 && slotsNode->child != 0) {
        int rc = readSkeletonData_slotTimelines(frame->slotsChild, data_raw,
                                                animation, parser_raw);
        if (rc == 0) {
            /* Two original exits share the 0 return: E1 (already disposed and
             * reported through setError) and the silent index == -1 branch
             * (0x28d538 beq 0x28ea10).  parser->error tells them apart. */
            spSkeletonJson* parser = (spSkeletonJson*)parser_raw;
            if (parser->error == 0) {
                Json* miss = slot_index_miss(frame->slotsChild, data_raw);
                if (miss == 0)
                    return 0;
                (void)readSkeletonData_animationsSlotNotFound(miss, frame->animation,
                                                              data_raw, animation,
                                                              parser_raw);
            }
            return 0;
        }
    }

    /* B6 bones, 0x28d640..0x28d840. */
    if (readSkeletonData_boneTimelines(frame->bones, frame->animation, data_raw,
                                       animation, parser_raw) == 0)
        return 0;

    /* B7 ik, 0x28d840..0x28dca8 (no error path in the family). */
    if (readSkeletonData_ikTimelines(frame->ik, data_raw, animation) == 0)
        return 0;

    /* B12 transform, 0x28dca8..0x28de74 (no error path in the family). */
    if (readSkeletonData_transformTimelines(frame->transform, data_raw,
                                            animation) == 0)
        return 0;

    /* B13 + B17 paths, 0x28de74..0x28e060 / 0x28e8ec..0x28ea0c. */
    if (path_stage(frame, data_raw, animation, parser_raw) == 0)
        return 0;

    /* B14 deform, 0x28e060..0x28e338. */
    {
        int rc = readSkeletonData_deformTimelines(frame->deform, data_raw,
                                                  animation, parser_raw);
        if (rc == DEFORM_TL_HANDOFF_ATTACHMENT) {
            Json* miss = deform_attachment_miss(frame->deform, data_raw);
            if (miss == 0)
                return 0;
            (void)readSkeletonData_attachmentNotFound(miss, data_raw, animation,
                                                      parser_raw);   /* E4 */
            return 0;
        }
        if (rc != DEFORM_TL_REACHED_DRAWORDER)
            return 0;
    }

    /* B15 drawOrder, 0x28e338..0x28e614. */
    {
        int rc = readSkeletonData_drawOrderTimelines(frame->drawOrder, data_raw,
                                                     animation);
        if (rc == DRAWORDER_TL_HANDOFF_SLOT_NOT_FOUND) {
            Json* miss = draworder_slot_miss(frame->drawOrder, data_raw);
            if (miss == 0)
                return 0;
            (void)readSkeletonData_drawOrderSlotNotFound(miss, data_raw, animation,
                                                         parser_raw); /* E6 */
            return 0;
        }
        if (rc != DRAWORDER_TL_OK)
            return 0;
    }

    /* B16 events, 0x28e614..0x28e774 (E5 runs inside the family). */
    if (readSkeletonData_eventTimelines(frame->events, data_raw, animation,
                                        parser_raw) != EVENT_TL_OK)
        return 0;

    /* 0x28e774..0x28e79c: animations[old] = animation, then advance the outer
     * cursor and loop while non-NULL. */
    readSkeletonData_publishAnimation(data_raw, animation);
    frame->animation = frame->animation->next;     /* 0x28e790 / 0x28e798 */
    return 1;
}

void*
readSkeletonData_animationsLoop(Json* firstAnimation, spAnimationFrame* frame,
                                void* data_raw, void* parser_raw)
{
    /* B2's 0x28d2d0 beq 0x28e7a4: no animations at all -> B18, no preamble. */
    if (firstAnimation == 0)
        return data_raw;

    /* B3 preamble, 0x28d2d4..0x28d314: once per animations array, straight
     * after B2's non-NULL fall-through. */
    readSkeletonData_animationFrameInit(frame, data_raw, parser_raw);

    while (frame->animation != 0) {                    /* 0x28d318 / 0x28e79c */
        if (animation_pass(frame, data_raw, parser_raw) == 0)
            return 0;
    }
    return data_raw;
}
