/* generated from CODE 355 (gml_Object_obj_levelup_Step_0), source start 4199172, end 4199244. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0355(GmVM* vm) {
    Val v1;
    /* @4199172 load */
    /* @4199180 constant */
    /* @4199184 sub */
    /* @4199188 store */
    GM_WRITE(vm, -1, "x", (GM_READ(vm, 0, "x") - VAL(48)));
    /* @4199196 load */
    /* @4199204 constant */
    /* @4199208 sub */
    /* @4199212 store */
    GM_WRITE(vm, -1, "y", (GM_READ(vm, 0, "y") - VAL(80)));
    /* @4199220 load */
    /* @4199228 constant */
    /* @4199232 add */
    /* @4199236 store */
    v1 = GM_ADD(GM_READ(vm, -1, "xposition"), VAL(2));
    GM_WRITE(vm, -1, "xposition", v1);
    L_4199244: ;
    return;
}
