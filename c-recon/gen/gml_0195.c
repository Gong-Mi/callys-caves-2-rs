/* generated from CODE 195 (gml_Object_obj_boss4_Alarm_1), source start 4006320, end 4006448. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0195(GmVM* vm) {
    /* @4006320 load */
    /* @4006328 constant */
    /* @4006332 cmp */
    /* @4006336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4006448;
    /* @4006340 load */
    /* @4006348 constant */
    /* @4006352 cmp */
    /* @4006356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swinging") == VAL(1)))) goto L_4006396;
    /* @4006360 constant */
    /* @4006364 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(77));
    /* @4006372 constant */
    /* @4006376 constant */
    /* @4006380 constant */
    /* @4006384 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(10));
    /* @4006392 b */
    goto L_4006428;
    L_4006396: ;
    /* @4006396 load */
    /* @4006404 constant */
    /* @4006408 cmp */
    /* @4006412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swinging") == VAL(0)))) goto L_4006428;
    /* @4006416 constant */
    /* @4006420 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(76));
    L_4006428: ;
    /* @4006428 constant */
    /* @4006432 constant */
    /* @4006436 constant */
    /* @4006440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    L_4006448: ;
    return;
}
