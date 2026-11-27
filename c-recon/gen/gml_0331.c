/* generated from CODE 331 (gml_Object_obj_firehulkflame_Create_0), source start 4193048, end 4193108. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0331(GmVM* vm) {
    Val v1;
    /* @4193048 load */
    /* @4193056 load */
    /* @4193064 load */
    /* @4193072 load */
    /* @4193080 call */
    GM_SITE(vm, 331, 4193080);
    /* @4193088 store */
    v1 = GM_CALL(vm, "point_direction", 4, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"));
    GM_WRITE(vm, -1, "direction", v1);
    /* @4193096 constant */
    /* @4193100 store */
    GM_WRITE(vm, -1, "speed", VAL(6));
    L_4193108: ;
    return;
}
