/* generated from CODE 233 (gml_Object_obj_bat_Destroy_0), source start 4032648, end 4032732. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0233(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4032648 load */
    /* @4032656 constant */
    /* @4032660 add */
    /* @4032664 store */
    v1 = GM_ADD(GM_READ(vm, -5, "batskilled"), VAL(1));
    GM_WRITE(vm, -5, "batskilled", v1);
    /* @4032672 load */
    /* @4032680 constant */
    /* @4032684 add */
    /* @4032688 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @4032696 constant */
    /* @4032700 cast */
    /* @4032704 load */
    /* @4032712 load */
    /* @4032720 call */
    GM_SITE(vm, 233, 4032720);
    /* @4032728 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_4032732: ;
    return;
}
