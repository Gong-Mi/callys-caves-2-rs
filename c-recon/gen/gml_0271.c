/* generated from CODE 271 (gml_Object_obj_blade_Create_0), source start 4064472, end 4064556. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0271(GmVM* vm) {
    /* @4064472 constant */
    /* @4064476 constant */
    /* @4064480 constant */
    /* @4064484 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(40));
    /* @4064492 load */
    /* @4064500 constant */
    /* @4064504 cmp */
    /* @4064508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4064524;
    /* @4064512 constant */
    /* @4064516 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-20));
    L_4064524: ;
    /* @4064524 load */
    /* @4064532 constant */
    /* @4064536 cmp */
    /* @4064540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4064556;
    /* @4064544 constant */
    /* @4064548 store */
    GM_WRITE(vm, -1, "hspeed", VAL(20));
    L_4064556: ;
    return;
}
