/* generated from CODE 675 (gml_Object_obj_lloyd_Step_0), source start 5015220, end 5015356. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0675(GmVM* vm) {
    Val v1;
    /* @5015220 constant */
    /* @5015224 cast */
    /* @5015228 call */
    GM_SITE(vm, 675, 5015228);
    /* @5015236 constant */
    /* @5015240 cmp */
    /* @5015244 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(100));
    if (!TRUTH(v1)) goto L_5015356;
    /* @5015248 constant */
    /* @5015252 store */
    GM_WRITE(vm, -5, "roomstart", VAL(1));
    /* @5015260 constant */
    /* @5015264 pushenv */
    if (!GM_PUSHENV(vm, VAL(130))) goto L_5015280;
    L_5015268: ;
    /* @5015268 call */
    GM_SITE(vm, 675, 5015268);
    /* @5015276 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5015280: ;
    /* @5015280 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5015268;
    /* @5015284 constant */
    /* @5015288 pushenv */
    if (!GM_PUSHENV(vm, VAL(131))) goto L_5015304;
    L_5015292: ;
    /* @5015292 call */
    GM_SITE(vm, 675, 5015292);
    /* @5015300 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5015304: ;
    /* @5015304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5015292;
    /* @5015308 constant */
    /* @5015312 store */
    GM_WRITE(vm, 0, "hspeed", VAL(0));
    /* @5015320 constant */
    /* @5015324 store */
    GM_WRITE(vm, 0, "vspeed", VAL(0));
    /* @5015332 constant */
    /* @5015336 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @5015344 constant */
    /* @5015348 store */
    GM_WRITE(vm, -1, "startlloyd", VAL(1));
    L_5015356: ;
    return;
}
