/* generated from CODE 194 (gml_Object_obj_boss4_Alarm_2), source start 4006192, end 4006320. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0194(GmVM* vm) {
    Val v1;
    /* @4006192 constant */
    /* @4006196 store */
    GM_WRITE(vm, -1, "swinging", VAL(0));
    /* @4006204 load */
    /* @4006212 constant */
    /* @4006216 cmp */
    /* @4006220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(1)))) goto L_4006320;
    /* @4006224 constant */
    /* @4006228 cast */
    /* @4006232 load */
    /* @4006240 constant */
    /* @4006244 sub */
    /* @4006248 load */
    /* @4006256 constant */
    /* @4006260 add */
    /* @4006264 call */
    GM_SITE(vm, 194, 4006264);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4006272 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(10)), VAL(54)));
    /* @4006276 constant */
    /* @4006280 cast */
    /* @4006284 load */
    /* @4006292 load */
    /* @4006300 constant */
    /* @4006304 sub */
    /* @4006308 call */
    GM_SITE(vm, 194, 4006308);
    /* @4006316 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(54)));
    L_4006320: ;
    return;
}
