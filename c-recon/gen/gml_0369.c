/* generated from CODE 369 (gml_Object_obj_UI_Step_0), source start 4228760, end 4228800. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0369(GmVM* vm) {
    Val v1;
    /* @4228760 constant */
    /* @4228764 cast */
    /* @4228768 call */
    GM_SITE(vm, 369, 4228768);
    /* @4228776 cast */
    /* @4228780 not */
    /* @4228784 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(132))));
    if (!TRUTH(v1)) goto L_4228800;
    /* @4228788 constant */
    /* @4228792 store */
    GM_WRITE(vm, -5, "coinpickup", VAL(0));
    L_4228800: ;
    return;
}
