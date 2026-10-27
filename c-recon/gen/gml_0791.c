/* generated from CODE 791 (gml_Object_obj_finalbosspuff_Alarm_0), source start 5041768, end 5041944. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0791(GmVM* vm) {
    Val v1;
    Val v2;
    /* @5041768 constant */
    /* @5041772 cast */
    /* @5041776 load */
    /* @5041784 load */
    /* @5041792 constant */
    /* @5041796 add */
    /* @5041800 call */
    GM_SITE(vm, 791, 5041800);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    /* @5041808 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041812 constant */
    /* @5041816 cast */
    /* @5041820 load */
    /* @5041828 load */
    /* @5041836 constant */
    /* @5041840 sub */
    /* @5041844 call */
    GM_SITE(vm, 791, 5041844);
    /* @5041852 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(40)), GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041856 constant */
    /* @5041860 cast */
    /* @5041864 load */
    /* @5041872 load */
    /* @5041880 constant */
    /* @5041884 add */
    /* @5041888 call */
    GM_SITE(vm, 791, 5041888);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(60));
    /* @5041896 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v2, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041900 constant */
    /* @5041904 cast */
    /* @5041908 load */
    /* @5041916 constant */
    /* @5041920 sub */
    /* @5041924 load */
    /* @5041932 call */
    GM_SITE(vm, 791, 5041932);
    /* @5041940 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(40)), VAL(190)));
    L_5041944: ;
    return;
}
