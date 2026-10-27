/* generated from CODE 398 (gml_Object_obj_bombgun_Create_0), source start 4518748, end 4518848. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0398(GmVM* vm) {
    Val v1;
    /* @4518748 constant */
    /* @4518752 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4518760 load */
    /* @4518768 constant */
    /* @4518772 cmp */
    /* @4518776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(1)))) goto L_4518796;
    /* @4518780 call */
    GM_SITE(vm, 398, 4518780);
    /* @4518788 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4518792 b */
    goto L_4518848;
    L_4518796: ;
    /* @4518796 constant */
    /* @4518800 cast */
    /* @4518804 load */
    /* @4518812 constant */
    /* @4518816 sub */
    /* @4518820 load */
    /* @4518828 constant */
    /* @4518832 add */
    /* @4518836 call */
    GM_SITE(vm, 398, 4518836);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4518844 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4518848: ;
    return;
}
