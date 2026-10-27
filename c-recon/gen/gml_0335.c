/* generated from CODE 335 (gml_Object_obj_boss3projectile_Create_0), source start 4195160, end 4195244. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0335(GmVM* vm) {
    Val v1;
    /* @4195160 constant */
    /* @4195164 store */
    GM_WRITE(vm, -1, "speed", VAL(-5));
    /* @4195172 constant */
    /* @4195176 cast */
    /* @4195180 constant */
    /* @4195184 cast */
    /* @4195188 constant */
    /* @4195192 cast */
    /* @4195196 constant */
    /* @4195200 cast */
    /* @4195204 constant */
    /* @4195208 cast */
    /* @4195212 constant */
    /* @4195216 cast */
    /* @4195220 constant */
    /* @4195224 cast */
    /* @4195228 call */
    GM_SITE(vm, 335, 4195228);
    /* @4195236 store */
    v1 = GM_CALL(vm, "choose", 7, VAL(-30), VAL(-15), VAL(0), VAL(15), VAL(30), VAL(45), VAL(60));
    GM_WRITE(vm, -1, "direction", v1);
    L_4195244: ;
    return;
}
