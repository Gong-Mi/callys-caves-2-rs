/* generated from CODE 268 (gml_Object_obj_flame_Create_0), source start 4055860, end 4055968. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0268(GmVM* vm) {
    /* @4055860 constant */
    /* @4055864 constant */
    /* @4055868 constant */
    /* @4055872 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(9));
    /* @4055880 load */
    /* @4055888 constant */
    /* @4055892 cmp */
    /* @4055896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4055924;
    /* @4055900 constant */
    /* @4055904 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-15));
    /* @4055912 constant */
    /* @4055916 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-1));
    L_4055924: ;
    /* @4055924 load */
    /* @4055932 constant */
    /* @4055936 cmp */
    /* @4055940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4055968;
    /* @4055944 constant */
    /* @4055948 store */
    GM_WRITE(vm, -1, "hspeed", VAL(15));
    /* @4055956 constant */
    /* @4055960 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-1));
    L_4055968: ;
    return;
}
