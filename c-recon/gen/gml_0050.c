/* generated from CODE 50 (gml_Object_obj_knifebandit_Destroy_0), source start 3896148, end 3896240. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0050(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @3896148 load */
    /* @3896156 constant */
    /* @3896160 add */
    /* @3896164 store */
    v1 = GM_ADD(GM_READ(vm, -5, "knifebanditskilled"), VAL(1));
    GM_WRITE(vm, -5, "knifebanditskilled", v1);
    /* @3896172 load */
    /* @3896180 constant */
    /* @3896184 add */
    /* @3896188 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3896196 constant */
    /* @3896200 cast */
    /* @3896204 load */
    /* @3896212 constant */
    /* @3896216 add */
    /* @3896220 load */
    /* @3896228 call */
    GM_SITE(vm, 50, 3896228);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(4));
    /* @3896236 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v3, VAL(187)));
    L_3896240: ;
    return;
}
