/*
 * spine_read_curve.h — readCurve, the anonymous 'curve'/'stepped' helper that
 * every interpolatable timeline frame loop calls before moving to the next
 * frame.
 *
 * Original image libyoyo_armv7.so (SHA256
 * 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a):
 *   0x28b34c..0x28b3f8   44 instructions, 176 bytes
 *                         (last two words 0x28b3f4/0x28b3f8 are the literal
 *                          pool; 0x28b3fc is _readVertices, NOT this function)
 *   No .dynsym/.symtab entry — objdump renders the address as
 *   spSkeletonData_findPathConstraint+0x5c. Recovered from bytes only; the
 *   original was never executed.
 *
 * ABI (recovered from the 8 call sites inside spSkeletonJson_readSkeletonData,
 * 0x28d7d0 / 0x28d9b0 / 0x28daf0 / 0x28dc48 / 0x28de0c / 0x28dff4 /
 * 0x28e2a8 / 0x28e9b0):
 *   readCurve(Json* frame, void* curveTimeline, int frameIndex) -> void
 *     r0 = the per-frame JSON object (the call sites reload frame->next and
 *          bump frameIndex right after the call)
 *     r1 = the timeline just handed to <Type>Timeline_setFrame
 *     r2 = the 0-based frame index, whole 32-bit word
 *     r0 on return is never read by any of the 8 callers.
 */
#ifndef SPINE_READ_CURVE_H
#define SPINE_READ_CURVE_H

#include "json_interface.h"

/*
 * Json node type values, written by the JSON parser at 0x28677c into
 * [node + 0x08] and read here at 0x28b370:
 *   0x2868c0 mov r3,#4 + 0x2868c8 str r3,[r8]   -> string literal (after '"')
 *   0x286f98 mov r3,#3 + 0x286f9c str r3,[r5,#8]-> number (strtod + vcvt)
 *   0x287170 str r0(=0),[r5,#8]                 -> null
 *   0x2871a4 mov r3,#2                          -> false
 *   0x2871d4 mov r3,#1 (and int 1 at +0x14)     -> true
 *   0x286fb4 mov r3,#5 + 0x286fb8 ... ; 0x286fec cmp r3,#93 (']')  -> array
 *   0x286c98 mov r3,#6 + 0x286c9c ... ; 0x286cd0 cmp r3,#125 ('}') -> object
 */
enum {
    CURVE_JSON_NULL   = 0,
    CURVE_JSON_TRUE   = 1,
    CURVE_JSON_FALSE  = 2,
    CURVE_JSON_NUMBER = 3,
    CURVE_JSON_STRING = 4,
    CURVE_JSON_ARRAY  = 5,
    CURVE_JSON_OBJECT = 6
};

/*
 * frame        : JSON object of one timeline frame (the "curve" key is a
 *                property of the frame, not of the animation root).
 * curveTimeline: spCurveTimeline*, passed through untouched.
 * frameIndex   : frame slot index, passed through untouched.
 *
 * No return value. Absent "curve", non-string/non-array "curve", or any
 * string other than the exact lowercase "stepped" produce no timeline write.
 */
void readCurve(Json* frame, void* curveTimeline, int frameIndex);

#endif /* SPINE_READ_CURVE_H */
