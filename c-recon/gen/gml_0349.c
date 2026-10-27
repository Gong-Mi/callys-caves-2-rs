/* generated from CODE 349 (gml_Object_obj_health_Create_0), source start 4198448, end 4198640. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0349(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4198448 constant */
    /* @4198452 cast */
    /* @4198456 constant */
    /* @4198460 cast */
    /* @4198464 call */
    GM_SITE(vm, 349, 4198464);
    /* @4198472 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(1), VAL(2));
    GM_WRITE(vm, -1, "healthrange", v1);
    /* @4198480 constant */
    /* @4198492 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.4));
    /* @4198500 constant */
    /* @4198504 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-2));
    /* @4198512 constant */
    /* @4198516 store */
    GM_WRITE(vm, -1, "type", VAL(5));
    /* @4198524 constant */
    /* @4198536 store */
    GM_WRITE(vm, -1, "friction", VAL(0.3));
    /* @4198544 constant */
    /* @4198548 cast */
    /* @4198552 load */
    /* @4198560 constant */
    /* @4198564 sub */
    /* @4198568 load */
    /* @4198576 call */
    GM_SITE(vm, 349, 4198576);
    /* @4198584 cast */
    /* @4198588 not */
    /* @4198592 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(1)), VAL(34))));
    if (!TRUTH(v2)) goto L_4198616;
    /* @4198596 load */
    /* @4198604 store */
    GM_WRITE(vm, -1, "yorigin", GM_READ(vm, -1, "y"));
    /* @4198612 b */
    goto L_4198640;
    L_4198616: ;
    /* @4198616 load */
    /* @4198624 constant */
    /* @4198628 add */
    /* @4198632 store */
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "yorigin", v3);
    L_4198640: ;
    return;
}
