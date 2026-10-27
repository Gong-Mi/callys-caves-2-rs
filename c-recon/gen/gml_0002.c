/* generated from CODE 2 (gml_Object_obj_player_Alarm_10), source start 3764368, end 3764412. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0002(GmVM* vm) {
    Val v1;
    /* @3764368 load */
    /* @3764376 constant */
    /* @3764380 add */
    /* @3764384 store */
    v1 = GM_ADD(GM_READ(vm, -5, "timeplayed"), VAL(1));
    GM_WRITE(vm, -5, "timeplayed", v1);
    /* @3764392 constant */
    /* @3764396 constant */
    /* @3764400 constant */
    /* @3764404 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(10), VAL(30));
    L_3764412: ;
    return;
}
