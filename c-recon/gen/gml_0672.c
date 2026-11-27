/* generated from CODE 672 (gml_Object_obj_lloyd_Alarm_2), source start 5013380, end 5013440. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0672(GmVM* vm) {
    /* @5013380 load */
    /* @5013388 constant */
    /* @5013392 cmp */
    /* @5013396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "startlloyd") == VAL(1)))) goto L_5013420;
    /* @5013400 constant */
    /* @5013404 constant */
    /* @5013408 constant */
    /* @5013412 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    L_5013420: ;
    /* @5013420 constant */
    /* @5013424 constant */
    /* @5013428 constant */
    /* @5013432 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(30));
    L_5013440: ;
    return;
}
