/* generated from CODE 113 (gml_Object_obj_hulkingbandit_Destroy_0), source start 3942440, end 3942524. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0113(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3942440 load */
    /* @3942448 constant */
    /* @3942452 add */
    /* @3942456 store */
    v1 = GM_ADD(GM_READ(vm, -5, "hulkingbanditskilled"), VAL(1));
    GM_WRITE(vm, -5, "hulkingbanditskilled", v1);
    /* @3942464 load */
    /* @3942472 constant */
    /* @3942476 add */
    /* @3942480 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3942488 constant */
    /* @3942492 cast */
    /* @3942496 load */
    /* @3942504 load */
    /* @3942512 call */
    GM_SITE(vm, 113, 3942512);
    /* @3942520 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(188)));
    L_3942524: ;
    return;
}
