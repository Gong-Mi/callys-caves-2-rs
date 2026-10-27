/* generated from CODE 465 (gml_Object_obj_dodged_Create_0), source start 4644344, end 4644440. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0465(GmVM* vm) {
    Val v1;
    /* @4644344 constant */
    /* @4644348 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4644356 constant */
    /* @4644360 cast */
    /* @4644364 constant */
    /* @4644368 cast */
    /* @4644372 call */
    GM_SITE(vm, 465, 4644372);
    /* @4644380 store */
    v1 = GM_CALL(vm, "random_range", 2, VAL(60), VAL(120));
    GM_WRITE(vm, -1, "range", v1);
    /* @4644388 load */
    /* @4644396 store */
    GM_WRITE(vm, -1, "direction", GM_READ(vm, -1, "range"));
    /* @4644404 constant */
    /* @4644408 store */
    GM_WRITE(vm, -1, "speed", VAL(4));
    /* @4644416 constant */
    /* @4644420 store */
    GM_WRITE(vm, -1, "damage", VAL(0));
    /* @4644428 constant */
    /* @4644432 store */
    GM_WRITE(vm, -1, "alpha", VAL(1));
    L_4644440: ;
    return;
}
