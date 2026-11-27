/* generated from CODE 257 (gml_Object_obj_fireslime_Destroy_0), source start 4048892, end 4048976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0257(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4048892 load */
    /* @4048900 constant */
    /* @4048904 add */
    /* @4048908 store */
    v1 = GM_ADD(GM_READ(vm, -5, "fireslimeskilled"), VAL(1));
    GM_WRITE(vm, -5, "fireslimeskilled", v1);
    /* @4048916 load */
    /* @4048924 constant */
    /* @4048928 add */
    /* @4048932 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @4048940 constant */
    /* @4048944 cast */
    /* @4048948 load */
    /* @4048956 load */
    /* @4048964 call */
    GM_SITE(vm, 257, 4048964);
    /* @4048972 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4048976: ;
    return;
}
