/* generated from CODE 392 (gml_Object_obj_bladegun_Create_0), source start 4517668, end 4517768. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0392(GmVM* vm) {
    /* @4517668 constant */
    /* @4517672 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4517680 load */
    /* @4517688 constant */
    /* @4517692 cmp */
    /* @4517696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunbought") == VAL(1)))) goto L_4517716;
    /* @4517700 call */
    GM_SITE(vm, 392, 4517700);
    /* @4517708 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4517712 b */
    goto L_4517768;
    L_4517716: ;
    /* @4517716 constant */
    /* @4517720 cast */
    /* @4517724 load */
    /* @4517732 constant */
    /* @4517736 sub */
    /* @4517740 load */
    /* @4517748 constant */
    /* @4517752 sub */
    /* @4517756 call */
    GM_SITE(vm, 392, 4517756);
    /* @4517764 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4517768: ;
    return;
}
