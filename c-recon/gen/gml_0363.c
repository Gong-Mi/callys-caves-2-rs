/* generated from CODE 363 (gml_Object_obj_bg_Step_0), source start 4217008, end 4217056. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0363(GmVM* vm) {
    /* @4217008 constant */
    /* @4217012 constant */
    /* @4217016 load */
    /* @4217024 constant */
    /* @4217028 cmp */
    /* @4217032 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(2)) < VAL(0)))) goto L_4217056;
    /* @4217036 constant */
    /* @4217040 constant */
    /* @4217044 constant */
    /* @4217048 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(15));
    L_4217056: ;
    return;
}
