/* generated from CODE 159 (gml_Object_obj_trex_Alarm_2), source start 3973192, end 3973280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0159(GmVM* vm) {
    /* @3973192 load */
    /* @3973200 constant */
    /* @3973204 cmp */
    /* @3973208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3973216;
    /* @3973212 b */
    goto L_3973280;
    L_3973216: ;
    /* @3973216 load */
    /* @3973224 constant */
    /* @3973228 cmp */
    /* @3973232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_3973280;
    /* @3973236 constant */
    /* @3973240 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(54));
    /* @3973248 constant */
    /* @3973252 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-3));
    /* @3973260 constant */
    /* @3973264 constant */
    /* @3973268 constant */
    /* @3973272 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(90));
    L_3973280: ;
    return;
}
