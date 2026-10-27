/* generated from CODE 492 (gml_Object_obj_storepageswitch2_Mouse_7), source start 4679756, end 4679816. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0492(GmVM* vm) {
    /* @4679756 constant */
    /* @4679760 pushenv */
    if (!GM_PUSHENV(vm, VAL(123))) goto L_4679776;
    L_4679764: ;
    /* @4679764 call */
    GM_SITE(vm, 492, 4679764);
    /* @4679772 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4679776: ;
    /* @4679776 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4679764;
    /* @4679780 constant */
    /* @4679784 cast */
    /* @4679788 load */
    /* @4679796 load */
    /* @4679804 call */
    GM_SITE(vm, 492, 4679804);
    /* @4679812 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(122)));
    L_4679816: ;
    return;
}
