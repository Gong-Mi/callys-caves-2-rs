/* generated from CODE 70 (gml_Object_obj_skeleton_Destroy_0), source start 3910828, end 3910912. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0070(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3910828 load */
    /* @3910836 constant */
    /* @3910840 add */
    /* @3910844 store */
    v1 = GM_ADD(GM_READ(vm, -5, "skeletonskilled"), VAL(1));
    GM_WRITE(vm, -5, "skeletonskilled", v1);
    /* @3910852 load */
    /* @3910860 constant */
    /* @3910864 add */
    /* @3910868 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3910876 constant */
    /* @3910880 cast */
    /* @3910884 load */
    /* @3910892 load */
    /* @3910900 call */
    GM_SITE(vm, 70, 3910900);
    /* @3910908 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3910912: ;
    return;
}
