/*
 * spine_read_curve.c — readCurve @0x28b34c..0x28b3f8 (end-exclusive 0x28b3fc).
 *
 * Original image: libyoyo_armv7.so
 *   SHA256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *
 * Evidence tier: bytecode_anchored.  Every branch, load and call below carries
 * the original instruction address it came from.  The original was not
 * executed; nothing here is an original-equivalence claim.
 *
 * Symbol: none.  The function is anonymous in .dynsym/.symtab (objdump labels
 * 0x28b34c as spSkeletonData_findPathConstraint+0x5c); 0x28b3f0 is its pop and
 * 0x28b3f4/0x28b3f8 are its two literal-pool words.
 *
 * Recovered shape:
 *   0x28b34c  push {r4,r5,lr}
 *   0x28b350  mov  r5, r1                  ; timeline
 *   0x28b354  ldr  r1, [pc,#0x98]          ; pool 0x28b3f4 -> 0x000cc784
 *   0x28b358  sub  sp, sp, #12             ; 2 stack args + alignment
 *   0x28b35c  mov  r4, r2                  ; frameIndex
 *   0x28b360  add  r1, pc, r1              ; 0x28b368 + 0xcc784 = 0x357aec "curve"
 *   0x28b364  bl   Json_getItem            ; (frame, "curve")
 *   0x28b368  cmp  r0, #0
 *   0x28b36c  beq  0x28b384                ; absent -> plain return
 *   0x28b370  ldr  r3, [r0,#0x8]           ; node type
 *   0x28b374  cmp  r3, #4
 *   0x28b378  beq  0x28b38c                ; string
 *   0x28b37c  cmp  r3, #5
 *   0x28b380  beq  0x28b3b8                ; array
 *   0x28b384  add  sp, sp, #12 / pop {r4,r5,pc}   ; every other type: no-op
 *
 * string branch:
 *   0x28b38c  ldr  r1, [pc,#0x64]          ; pool 0x28b3f8 -> 0x000cc758
 *   0x28b390  ldr  r0, [r0,#0x10]          ; node->string_value
 *   0x28b394  add  r1, pc, r1              ; 0x28b39c + 0xcc758 = 0x357af4 "stepped"
 *   0x28b398  bl   strcmp                  ; CASE-SENSITIVE (Json_getItem above is not)
 *   0x28b3a0  bne  0x28b384                ; anything else "stepped" -> no write
 *   0x28b3a4/0x28b3a8  r0=timeline, r1=frameIndex
 *   0x28b3b0  pop  {r4,r5,lr}
 *   0x28b3b4  b    0x2817c0                ; tail call spCurveTimeline_setStepped
 *
 * array branch:
 *   0x28b3b8  ldr  r3, [r0,#0x4]           ; curve->child
 *   0x28b3c4  ldr  r12,[r3]                ; child->next
 *   0x28b3c8  ldr  r2, [r3,#0x18]          ; child->float_value      -> cx1 (arg 3)
 *   0x28b3cc  ldr  r3, [r12,#0x18]         ; next->float_value       -> cy1 (arg 4)
 *   0x28b3d0  ldr  r12,[r12]               ; next->next
 *   0x28b3d4  ldr  lr, [r12,#0x18]         ; float_value             -> cx2 (arg 5, [sp])
 *   0x28b3dc  ldr  r12,[r12]               ; next->next
 *   0x28b3e0  ldr  r12,[r12,#0x18]         ; float_value             -> cy2 (arg 6, [sp,#4])
 *   0x28b3e8  bl   spCurveTimeline_setCurve
 *   0x28b3f0  pop  {r4,r5,pc}
 *
 * Curve data shape (this is the census open question, now pinned):
 *   "curve" is EITHER the string "stepped" (nothing else is accepted) OR a
 *   JSON ARRAY of numbers.  The array's declared length (Json+0x0c, the
 *   unk_0c field) is NEVER read: four nodes are followed through ->next, with
 *   no bounds check and no per-element type check.  Fewer than four nodes
 *   means the 4th load walks into whatever node follows in memory (NULL in a
 *   well-formed tree => fault); more than four means the tail is ignored.  The
 *   four values map 1:1 onto spCurveTimeline_setCurve's (cx1, cy1, cx2, cy2).
 */

#include "spine_read_curve.h"

/* The type word is the one Json field json_interface.h leaves unnamed. */
_Static_assert(offsetof(Json, unk_08) == 0x08, "Json type word must stay at +0x08");
_Static_assert(offsetof(Json, child) == 0x04, "Json child must stay at +0x04");
_Static_assert(offsetof(Json, float_value) == 0x18, "Json float_value must stay at +0x18");
_Static_assert(offsetof(Json, string_value) == 0x10, "Json string_value must stay at +0x10");

/*
 * Called boundaries — NOT recovered in this module:
 *   0x2817c0 spCurveTimeline_setStepped (24 B):
 *     0x2817c0 ldr r3,[r0,#0x8]  -> self->curves (float*)
 *     0x2817c4 mov r2,#76        -> 19 * 4
 *     0x2817c8 mov r12,#1065353216 -> 1.0f
 *     0x2817cc mla r1,r2,r1,r3   -> &curves[frameIndex*19]
 *     0x2817d0 str r12,[r1]      -> curves[frameIndex*19 + 0] = 1.0f
 *   0x2817d8 spCurveTimeline_setCurve (264 B): six AAPCS words
 *     (self, frameIndex, cx1, cy1, cx2, cy2); the four floats are consumed as
 *     r2, r3, [sp], [sp,#4] — which is exactly how the caller above feeds them,
 *     confirming float args 3..6 are cx1, cy1, cx2, cy2 in that order.
 */
extern void spCurveTimeline_setStepped(void* curveTimeline, int frameIndex);
extern void spCurveTimeline_setCurve(void* curveTimeline, int frameIndex,
                                     float cx1, float cy1, float cx2, float cy2);

void
readCurve(Json* frame, void* curveTimeline, int frameIndex)
{
    /* 0x28b364 bl Json_getItem(frame, "curve") */
    Json* curve = Json_getItem(frame, "curve");

    /* 0x28b368 cmp r0,#0 ; 0x28b36c beq 0x28b384 */
    if (curve == NULL)
        return;

    /* 0x28b370 ldr r3,[r0,#0x8] — node type */
    if (curve->unk_08 == CURVE_JSON_STRING) {
        /* 0x28b390 ldr r0,[r0,#0x10] — string_value
         * 0x28b398 bl strcmp ; 0x28b3a0 bne 0x28b384 — exact, case-sensitive */
        if (strcmp(curve->string_value, "stepped") == 0)
            /* 0x28b3a4/0x28b3a8 mov r0,r5 / mov r1,r4
             * 0x28b3b0 pop {r4,r5,lr} ; 0x28b3b4 b 0x2817c0 (tail call) */
            spCurveTimeline_setStepped(curveTimeline, frameIndex);
    } else if (curve->unk_08 == CURVE_JSON_ARRAY) {
        /* Load order follows the original exactly; no NULL check on any node
         * (0x28b3b8 loads child and 0x28b3c8 immediately dereferences it). */
        Json* c0 = curve->child;              /* 0x28b3b8 ldr r3,[r0,#0x4] */
        Json* c1 = c0->next;                  /* 0x28b3c4 ldr r12,[r3] */
        float cx1 = c0->float_value;          /* 0x28b3c8 ldr r2,[r3,#0x18] */
        float cy1 = c1->float_value;          /* 0x28b3cc ldr r3,[r12,#0x18] */
        Json* c2 = c1->next;                  /* 0x28b3d0 ldr r12,[r12] */
        float cx2 = c2->float_value;          /* 0x28b3d4 ldr lr,[r12,#0x18] */
        Json* c3 = c2->next;                  /* 0x28b3dc ldr r12,[r12] */
        float cy2 = c3->float_value;          /* 0x28b3e0 ldr r12,[r12,#0x18] */

        /* 0x28b3d8 str lr,[sp] / 0x28b3e4 str r12,[sp,#4] are the two stack
         * arguments; 0x28b3e8 bl spCurveTimeline_setCurve. */
        spCurveTimeline_setCurve(curveTimeline, frameIndex, cx1, cy1, cx2, cy2);
    }
    /* anything else falls straight into 0x28b384's epilogue */
}
