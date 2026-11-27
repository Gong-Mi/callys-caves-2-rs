/* generated from CODE 459 (gml_Object_obj_damage_Create_0), source start 4642664, end 4642760. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0459(GmVM* vm) {
    Val v1;
    /* @4642664 constant */
    /* @4642668 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4642676 constant */
    /* @4642680 cast */
    /* @4642684 constant */
    /* @4642688 cast */
    /* @4642692 call */
    GM_SITE(vm, 459, 4642692);
    /* @4642700 store */
    v1 = GM_CALL(vm, "random_range", 2, VAL(60), VAL(120));
    GM_WRITE(vm, -1, "range", v1);
    /* @4642708 load */
    /* @4642716 store */
    GM_WRITE(vm, -1, "direction", GM_READ(vm, -1, "range"));
    /* @4642724 constant */
    /* @4642728 store */
    GM_WRITE(vm, -1, "speed", VAL(4));
    /* @4642736 constant */
    /* @4642740 store */
    GM_WRITE(vm, -1, "damage", VAL(0));
    /* @4642748 constant */
    /* @4642752 store */
    GM_WRITE(vm, -1, "alpha", VAL(1));
    L_4642760: ;
    return;
}
