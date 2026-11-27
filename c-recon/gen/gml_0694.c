/* generated from CODE 694 (gml_Object_obj_final_Create_0), source start 5018208, end 5018336. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0694(GmVM* vm) {
    /* @5018208 constant */
    /* @5018212 cast */
    /* @5018216 call */
    GM_SITE(vm, 694, 5018216);
    /* @5018224 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @5018228 constant */
    /* @5018232 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @5018240 constant */
    /* @5018244 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @5018252 constant */
    /* @5018256 store */
    GM_WRITE(vm, -1, "drawpanel2", VAL(0));
    /* @5018264 constant */
    /* @5018268 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @5018276 constant */
    /* @5018280 constant */
    /* @5018284 constant */
    /* @5018288 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(100));
    /* @5018296 constant */
    /* @5018300 constant */
    /* @5018304 constant */
    /* @5018308 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(300));
    /* @5018316 constant */
    /* @5018320 constant */
    /* @5018324 constant */
    /* @5018328 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(300));
    L_5018336: ;
    return;
}
