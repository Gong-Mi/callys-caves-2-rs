/* generated from CODE 329 (gml_Object_obj_fireball_Create_0), source start 4192080, end 4192156. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0329(GmVM* vm) {
    Val v1;
    /* @4192080 constant */
    /* @4192084 cast */
    /* @4192088 load */
    /* @4192096 constant */
    /* @4192100 cast */
    /* @4192104 call */
    GM_SITE(vm, 329, 4192104);
    /* @4192112 constant */
    /* @4192116 cast */
    /* @4192120 constant */
    /* @4192124 cast */
    /* @4192128 call */
    GM_SITE(vm, 329, 4192128);
    /* @4192136 mul */
    /* @4192140 add */
    /* @4192144 call */
    GM_SITE(vm, 329, 4192144);
    v1 = GM_ADD(GM_READ(vm, -1, "image_angle"), (GM_CALL(vm, "random", 1, VAL(25)) * GM_CALL(vm, "choose", 2, VAL(1), VAL(-1))));
    /* @4192152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, v1, VAL(-10)));
    L_4192156: ;
    return;
}
