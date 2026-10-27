/* generated from CODE 170 (gml_Object_obj_boss2_Draw_0), source start 3994020, end 3994212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0170(GmVM* vm) {
    /* @3994020 load */
    /* @3994028 constant */
    /* @3994032 cmp */
    /* @3994036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3994148;
    /* @3994040 constant */
    /* @3994044 cast */
    /* @3994048 constant */
    /* @3994052 cast */
    /* @3994056 constant */
    /* @3994064 cast */
    /* @3994068 constant */
    /* @3994072 cast */
    /* @3994076 call */
    GM_SITE(vm, 170, 3994076);
    /* @3994084 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3994088 call */
    GM_SITE(vm, 170, 3994088);
    /* @3994096 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3994100 constant */
    /* @3994104 cast */
    /* @3994108 constant */
    /* @3994112 cast */
    /* @3994116 constant */
    /* @3994120 cast */
    /* @3994124 constant */
    /* @3994128 cast */
    /* @3994132 call */
    GM_SITE(vm, 170, 3994132);
    /* @3994140 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3994144 b */
    goto L_3994180;
    L_3994148: ;
    /* @3994148 load */
    /* @3994156 constant */
    /* @3994160 cmp */
    /* @3994164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3994180;
    /* @3994168 call */
    GM_SITE(vm, 170, 3994168);
    /* @3994176 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3994180: ;
    /* @3994180 load */
    /* @3994188 constant */
    /* @3994192 cmp */
    /* @3994196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3994212;
    /* @3994200 constant */
    /* @3994204 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3994212: ;
    return;
}
