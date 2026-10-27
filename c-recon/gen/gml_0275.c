/* generated from CODE 275 (gml_Object_obj_bomb_Create_0), source start 4073340, end 4073448. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0275(GmVM* vm) {
    /* @4073340 constant */
    /* @4073344 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4073352 constant */
    /* @4073356 store */
    GM_WRITE(vm, -1, "hitwall", VAL(0));
    /* @4073364 load */
    /* @4073372 constant */
    /* @4073376 cmp */
    /* @4073380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4073396;
    /* @4073384 constant */
    /* @4073388 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-8));
    L_4073396: ;
    /* @4073396 load */
    /* @4073404 constant */
    /* @4073408 cmp */
    /* @4073412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4073428;
    /* @4073416 constant */
    /* @4073420 store */
    GM_WRITE(vm, -1, "hspeed", VAL(8));
    L_4073428: ;
    /* @4073428 constant */
    /* @4073432 constant */
    /* @4073436 constant */
    /* @4073440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_4073448: ;
    return;
}
