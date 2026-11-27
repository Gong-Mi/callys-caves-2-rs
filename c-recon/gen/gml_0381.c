/* generated from CODE 381 (gml_Object_obj_pickupflare_Alarm_0), source start 4515816, end 4515876. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0381(GmVM* vm) {
    Val v1;
    /* @4515816 constant */
    /* @4515820 constant */
    /* @4515824 constant */
    /* @4515828 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    /* @4515836 constant */
    /* @4515840 cast */
    /* @4515844 call */
    GM_SITE(vm, 381, 4515844);
    /* @4515852 constant */
    /* @4515856 cmp */
    /* @4515860 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(30));
    if (!TRUTH(v1)) goto L_4515876;
    /* @4515864 call */
    GM_SITE(vm, 381, 4515864);
    /* @4515872 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4515876: ;
    return;
}
