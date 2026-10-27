/* generated from CODE 681 (gml_Object_obj_busterrockparts_Create_0), source start 5015976, end 5016104. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0681(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @5015976 constant */
    /* @5015980 cast */
    /* @5015984 constant */
    /* @5015988 cast */
    /* @5015992 call */
    GM_SITE(vm, 681, 5015992);
    /* @5016000 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(1), VAL(-1));
    GM_WRITE(vm, -1, "image_xscale", v1);
    /* @5016008 constant */
    /* @5016012 cast */
    /* @5016016 constant */
    /* @5016020 cast */
    /* @5016024 call */
    GM_SITE(vm, 681, 5016024);
    /* @5016032 store */
    v2 = GM_CALL(vm, "choose", 2, VAL(1), VAL(-1));
    GM_WRITE(vm, -1, "image_yscale", v2);
    /* @5016040 constant */
    /* @5016044 store */
    GM_WRITE(vm, -1, "speed", VAL(7));
    /* @5016052 constant */
    /* @5016056 cast */
    /* @5016060 constant */
    /* @5016064 cast */
    /* @5016068 call */
    GM_SITE(vm, 681, 5016068);
    /* @5016076 store */
    v3 = GM_CALL(vm, "choose", 2, VAL(70), VAL(110));
    GM_WRITE(vm, -1, "direction", v3);
    /* @5016084 constant */
    /* @5016088 constant */
    /* @5016092 constant */
    /* @5016096 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_5016104: ;
    return;
}
