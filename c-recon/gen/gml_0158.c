/* generated from CODE 158 (gml_Object_obj_trex_Alarm_3), source start 3973104, end 3973192. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0158(GmVM* vm) {
    /* @3973104 load */
    /* @3973112 constant */
    /* @3973116 cmp */
    /* @3973120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3973128;
    /* @3973124 b */
    goto L_3973192;
    L_3973128: ;
    /* @3973128 load */
    /* @3973136 constant */
    /* @3973140 cmp */
    /* @3973144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_3973192;
    /* @3973148 constant */
    /* @3973152 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(56));
    /* @3973160 constant */
    /* @3973164 constant */
    /* @3973168 constant */
    /* @3973172 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(90));
    /* @3973180 constant */
    /* @3973184 store */
    GM_WRITE(vm, -1, "hspeed", VAL(3));
    L_3973192: ;
    return;
}
