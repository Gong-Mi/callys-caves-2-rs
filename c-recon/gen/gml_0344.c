/* generated from CODE 344 (gml_Object_obj_silvercoin_Create_0), source start 4197580, end 4197708. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0344(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4197580 constant */
    /* @4197592 store */
    GM_WRITE(vm, -1, "friction", VAL(0.3));
    /* @4197600 constant */
    /* @4197604 store */
    GM_WRITE(vm, -1, "type", VAL(3));
    /* @4197612 constant */
    /* @4197616 cast */
    /* @4197620 load */
    /* @4197628 constant */
    /* @4197632 sub */
    /* @4197636 load */
    /* @4197644 call */
    GM_SITE(vm, 344, 4197644);
    /* @4197652 cast */
    /* @4197656 not */
    /* @4197660 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(1)), VAL(34))));
    if (!TRUTH(v1)) goto L_4197684;
    /* @4197664 load */
    /* @4197672 store */
    GM_WRITE(vm, -1, "yorigin", GM_READ(vm, -1, "y"));
    /* @4197680 b */
    goto L_4197708;
    L_4197684: ;
    /* @4197684 load */
    /* @4197692 constant */
    /* @4197696 add */
    /* @4197700 store */
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "yorigin", v2);
    L_4197708: ;
    return;
}
