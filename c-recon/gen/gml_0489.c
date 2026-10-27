/* generated from CODE 489 (gml_Object_obj_storepageswitch_Mouse_7), source start 4678156, end 4678216. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0489(GmVM* vm) {
    /* @4678156 constant */
    /* @4678160 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_4678176;
    L_4678164: ;
    /* @4678164 call */
    GM_SITE(vm, 489, 4678164);
    /* @4678172 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4678176: ;
    /* @4678176 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4678164;
    /* @4678180 constant */
    /* @4678184 cast */
    /* @4678188 load */
    /* @4678196 load */
    /* @4678204 call */
    GM_SITE(vm, 489, 4678204);
    /* @4678212 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(123)));
    L_4678216: ;
    return;
}
