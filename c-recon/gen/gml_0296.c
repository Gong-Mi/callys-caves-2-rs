/* generated from CODE 296 (gml_Object_obj_boomerangthrow_Alarm_1), source start 4140920, end 4140980. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0296(GmVM* vm) {
    Val v1;
    /* @4140920 load */
    /* @4140928 load */
    /* @4140936 load */
    /* @4140944 load */
    /* @4140952 call */
    GM_SITE(vm, 296, 4140952);
    /* @4140960 store */
    v1 = GM_CALL(vm, "point_direction", 4, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"));
    GM_WRITE(vm, -1, "direction", v1);
    /* @4140968 constant */
    /* @4140972 store */
    GM_WRITE(vm, -1, "boomerangreturn", VAL(1));
    L_4140980: ;
    return;
}
