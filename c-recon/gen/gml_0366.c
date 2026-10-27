/* generated from CODE 366 (gml_Object_obj_UI_Alarm_7), source start 4219028, end 4219172. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0366(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4219028 load */
    /* @4219036 constant */
    /* @4219040 cmp */
    /* @4219044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4219100;
    /* @4219048 constant */
    /* @4219052 cast */
    /* @4219056 constant */
    /* @4219060 cast */
    /* @4219064 constant */
    /* @4219068 cast */
    /* @4219072 constant */
    /* @4219076 cast */
    /* @4219080 call */
    GM_SITE(vm, 366, 4219080);
    /* @4219088 store */
    v1 = GM_CALL(vm, "choose", 4, VAL(1), VAL(2), VAL(3), VAL(4));
    GM_WRITE(vm, -5, "rebuff", v1);
    /* @4219096 b */
    goto L_4219152;
    L_4219100: ;
    /* @4219100 load */
    /* @4219108 constant */
    /* @4219112 cmp */
    /* @4219116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(1)))) goto L_4219152;
    /* @4219120 constant */
    /* @4219124 cast */
    /* @4219128 constant */
    /* @4219132 cast */
    /* @4219136 call */
    GM_SITE(vm, 366, 4219136);
    /* @4219144 store */
    v2 = GM_CALL(vm, "choose", 2, VAL(1), VAL(2));
    GM_WRITE(vm, -5, "rebuff", v2);
    L_4219152: ;
    /* @4219152 constant */
    /* @4219156 constant */
    /* @4219160 constant */
    /* @4219164 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(3));
    L_4219172: ;
    return;
}
