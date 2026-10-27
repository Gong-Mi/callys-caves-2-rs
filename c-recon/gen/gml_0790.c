/* generated from CODE 790 (gml_Object_obj_finalbosspuff_Alarm_1), source start 5041592, end 5041768. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0790(GmVM* vm) {
    Val v1;
    /* @5041592 constant */
    /* @5041596 cast */
    /* @5041600 load */
    /* @5041608 load */
    /* @5041616 constant */
    /* @5041620 add */
    /* @5041624 call */
    GM_SITE(vm, 790, 5041624);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(60));
    /* @5041632 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041636 constant */
    /* @5041640 cast */
    /* @5041644 load */
    /* @5041652 load */
    /* @5041660 constant */
    /* @5041664 sub */
    /* @5041668 call */
    GM_SITE(vm, 790, 5041668);
    /* @5041676 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(60)), GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041680 constant */
    /* @5041684 cast */
    /* @5041688 load */
    /* @5041696 load */
    /* @5041704 constant */
    /* @5041708 sub */
    /* @5041712 call */
    GM_SITE(vm, 790, 5041712);
    /* @5041720 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(60)), GM_READ(vm, -1, "y"), VAL(190)));
    /* @5041724 constant */
    /* @5041728 cast */
    /* @5041732 load */
    /* @5041740 constant */
    /* @5041744 sub */
    /* @5041748 load */
    /* @5041756 call */
    GM_SITE(vm, 790, 5041756);
    /* @5041764 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(60)), VAL(190)));
    L_5041768: ;
    return;
}
