/* generated from CODE 386 (gml_Object_obj_shotgun_Create_0), source start 4516596, end 4516688. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0386(GmVM* vm) {
    /* @4516596 constant */
    /* @4516600 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4516608 load */
    /* @4516616 constant */
    /* @4516620 cmp */
    /* @4516624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(1)))) goto L_4516644;
    /* @4516628 call */
    GM_SITE(vm, 386, 4516628);
    /* @4516636 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4516640 b */
    goto L_4516688;
    L_4516644: ;
    /* @4516644 constant */
    /* @4516648 cast */
    /* @4516652 load */
    /* @4516660 constant */
    /* @4516664 sub */
    /* @4516668 load */
    /* @4516676 call */
    GM_SITE(vm, 386, 4516676);
    /* @4516684 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4516688: ;
    return;
}
