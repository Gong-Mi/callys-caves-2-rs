/* generated from CODE 92 (gml_Object_obj_zombie_Destroy_0), source start 3927048, end 3927140. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0092(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @3927048 load */
    /* @3927056 constant */
    /* @3927060 add */
    /* @3927064 store */
    v1 = GM_ADD(GM_READ(vm, -5, "zombieskilled"), VAL(1));
    GM_WRITE(vm, -5, "zombieskilled", v1);
    /* @3927072 load */
    /* @3927080 constant */
    /* @3927084 add */
    /* @3927088 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3927096 constant */
    /* @3927100 cast */
    /* @3927104 load */
    /* @3927112 constant */
    /* @3927116 add */
    /* @3927120 load */
    /* @3927128 call */
    GM_SITE(vm, 92, 3927128);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(12));
    /* @3927136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v3, VAL(187)));
    L_3927140: ;
    return;
}
