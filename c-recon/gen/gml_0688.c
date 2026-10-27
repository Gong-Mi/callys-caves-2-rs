/* generated from CODE 688 (gml_Object_obj_iceblock_Step_0), source start 5016536, end 5016652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0688(GmVM* vm) {
    /* @5016536 load */
    /* @5016544 constant */
    /* @5016548 cmp */
    /* @5016552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "melting") == VAL(1)))) goto L_5016620;
    /* @5016556 load */
    /* @5016564 constant */
    /* @5016576 sub */
    /* @5016580 store */
    GM_WRITE(vm, -1, "image_xscale", (GM_READ(vm, -1, "image_xscale") - VAL(0.1)));
    /* @5016588 load */
    /* @5016596 constant */
    /* @5016608 sub */
    /* @5016612 store */
    GM_WRITE(vm, -1, "image_yscale", (GM_READ(vm, -1, "image_yscale") - VAL(0.1)));
    L_5016620: ;
    /* @5016620 load */
    /* @5016628 constant */
    /* @5016632 cmp */
    /* @5016636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "image_xscale") == VAL(0)))) goto L_5016652;
    /* @5016640 call */
    GM_SITE(vm, 688, 5016640);
    /* @5016648 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5016652: ;
    return;
}
