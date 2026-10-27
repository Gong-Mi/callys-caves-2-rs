/* generated from CODE 365 (gml_Object_obj_UI_Create_0), source start 4218520, end 4219028. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0365(GmVM* vm) {
    Val v1;
    Val v2;
    Val loc_i;
    /* @4218520 constant */
    /* @4218524 cast */
    /* @4218528 constant */
    /* @4218532 cast */
    /* @4218536 call */
    GM_SITE(vm, 365, 4218536);
    /* @4218544 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(19), VAL(20));
    GM_WRITE(vm, -5, "coinsound", v1);
    /* @4218552 constant */
    /* @4218556 cast */
    /* @4218560 constant */
    /* @4218564 cast */
    /* @4218568 call */
    GM_SITE(vm, 365, 4218568);
    /* @4218576 store */
    v2 = GM_CALL(vm, "choose", 2, VAL(13), VAL(14));
    GM_WRITE(vm, -5, "swordsound", v2);
    /* @4218584 call */
    GM_SITE(vm, 365, 4218584);
    /* @4218592 popz */
    (void)(GM_CALL(vm, "randomize", 0));
    /* @4218596 constant */
    /* @4218600 cast */
    /* @4218604 constant */
    /* @4218608 cast */
    /* @4218612 call */
    GM_SITE(vm, 365, 4218612);
    /* @4218620 store_local */
    loc_i = GM_CALL(vm, "irandom_range", 2, VAL(1), VAL(10));
    /* @4218628 load_local */
    /* @4218636 store */
    GM_WRITE(vm, -5, "playlist", loc_i);
    /* @4218644 constant */
    /* @4218648 cast */
    /* @4218652 load */
    /* @4218660 load */
    /* @4218668 call */
    GM_SITE(vm, 365, 4218668);
    /* @4218676 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(133)));
    /* @4218680 constant */
    /* @4218684 cast */
    /* @4218688 load */
    /* @4218696 load */
    /* @4218704 call */
    GM_SITE(vm, 365, 4218704);
    /* @4218712 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(128)));
    /* @4218716 constant */
    /* @4218720 cast */
    /* @4218724 load */
    /* @4218732 load */
    /* @4218740 call */
    GM_SITE(vm, 365, 4218740);
    /* @4218748 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(127)));
    /* @4218752 constant */
    /* @4218756 cast */
    /* @4218760 load */
    /* @4218768 load */
    /* @4218776 call */
    GM_SITE(vm, 365, 4218776);
    /* @4218784 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(129)));
    /* @4218788 constant */
    /* @4218792 cast */
    /* @4218796 load */
    /* @4218804 load */
    /* @4218812 call */
    GM_SITE(vm, 365, 4218812);
    /* @4218820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4218824 constant */
    /* @4218828 cast */
    /* @4218832 load */
    /* @4218840 load */
    /* @4218848 call */
    GM_SITE(vm, 365, 4218848);
    /* @4218856 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4218860 constant */
    /* @4218864 store */
    GM_WRITE(vm, -5, "firing", VAL(0));
    /* @4218872 constant */
    /* @4218876 cast */
    /* @4218880 load */
    /* @4218888 load */
    /* @4218896 call */
    GM_SITE(vm, 365, 4218896);
    /* @4218904 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(125)));
    /* @4218908 constant */
    /* @4218912 constant */
    /* @4218916 constant */
    /* @4218920 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(3));
    /* @4218928 constant */
    /* @4218932 constant */
    /* @4218936 constant */
    /* @4218940 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(5));
    /* @4218948 constant */
    /* @4218952 store */
    GM_WRITE(vm, -5, "timespaused", VAL(0));
    /* @4218960 constant */
    /* @4218964 store */
    GM_WRITE(vm, -1, "drawboss1", VAL(0));
    /* @4218972 constant */
    /* @4218976 store */
    GM_WRITE(vm, -1, "drawboss2", VAL(0));
    /* @4218984 constant */
    /* @4218988 store */
    GM_WRITE(vm, -1, "drawboss3", VAL(0));
    /* @4218996 constant */
    /* @4219000 store */
    GM_WRITE(vm, -1, "drawboss4", VAL(0));
    /* @4219008 constant */
    /* @4219012 constant */
    /* @4219016 constant */
    /* @4219020 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    L_4219028: ;
    return;
}
