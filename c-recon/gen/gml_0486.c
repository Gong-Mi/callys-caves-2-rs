/* generated from CODE 486 (gml_Object_obj_restoredata_Mouse_7), source start 4676656, end 4676704. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0486(GmVM* vm) {
    /* @4676656 constant */
    /* @4676660 cast */
    /* @4676664 load */
    /* @4676672 load */
    /* @4676680 call */
    GM_SITE(vm, 486, 4676680);
    /* @4676688 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(114)));
    /* @4676692 call */
    GM_SITE(vm, 486, 4676692);
    /* @4676700 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4676704: ;
    return;
}
