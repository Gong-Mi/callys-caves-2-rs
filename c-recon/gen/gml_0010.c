/* generated from CODE 10 (gml_Object_obj_player_Alarm_1), source start 3764556, end 3764972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0010(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3764556 load */
    /* @3764564 constant */
    /* @3764568 cmp */
    /* @3764572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(31)))) goto L_3764600;
    /* @3764576 constant */
    /* @3764580 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @3764588 constant */
    /* @3764592 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(31));
    L_3764600: ;
    /* @3764600 load */
    /* @3764608 constant */
    /* @3764612 cmp */
    /* @3764616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swing") == VAL(1)))) goto L_3764972;
    /* @3764620 load */
    /* @3764628 constant */
    /* @3764632 cmp */
    /* @3764636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3764796;
    /* @3764640 constant */
    /* @3764644 cast */
    /* @3764648 load */
    /* @3764656 constant */
    /* @3764660 sub */
    /* @3764664 load */
    /* @3764672 constant */
    /* @3764676 add */
    /* @3764680 call */
    GM_SITE(vm, 10, 3764680);
    v1 = GM_ADD(GM_READ(vm, 0, "x"), VAL(15));
    /* @3764688 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, 0, "y") - VAL(15)), VAL(46)));
    /* @3764692 constant */
    /* @3764696 store */
    GM_WRITE(vm, -5, "swing", VAL(0));
    /* @3764704 constant */
    /* @3764708 constant */
    /* @3764712 constant */
    /* @3764716 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(9));
    /* @3764724 load */
    /* @3764732 constant */
    /* @3764736 cmp */
    /* @3764740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_3764796;
    /* @3764744 constant */
    /* @3764748 cast */
    /* @3764752 load */
    /* @3764760 constant */
    /* @3764764 sub */
    /* @3764768 load */
    /* @3764776 constant */
    /* @3764780 add */
    /* @3764784 call */
    GM_SITE(vm, 10, 3764784);
    v2 = GM_ADD(GM_READ(vm, 0, "x"), VAL(15));
    /* @3764792 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, 0, "y") - VAL(5)), VAL(45)));
    L_3764796: ;
    /* @3764796 load */
    /* @3764804 constant */
    /* @3764808 cmp */
    /* @3764812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3764972;
    /* @3764816 constant */
    /* @3764820 cast */
    /* @3764824 load */
    /* @3764832 constant */
    /* @3764836 sub */
    /* @3764840 load */
    /* @3764848 constant */
    /* @3764852 sub */
    /* @3764856 call */
    GM_SITE(vm, 10, 3764856);
    /* @3764864 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, 0, "x") - VAL(15)), (GM_READ(vm, 0, "y") - VAL(15)), VAL(46)));
    /* @3764868 constant */
    /* @3764872 store */
    GM_WRITE(vm, -5, "swing", VAL(0));
    /* @3764880 constant */
    /* @3764884 constant */
    /* @3764888 constant */
    /* @3764892 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(9));
    /* @3764900 load */
    /* @3764908 constant */
    /* @3764912 cmp */
    /* @3764916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_3764972;
    /* @3764920 constant */
    /* @3764924 cast */
    /* @3764928 load */
    /* @3764936 constant */
    /* @3764940 sub */
    /* @3764944 load */
    /* @3764952 constant */
    /* @3764956 sub */
    /* @3764960 call */
    GM_SITE(vm, 10, 3764960);
    /* @3764968 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, 0, "x") - VAL(15)), (GM_READ(vm, 0, "y") - VAL(5)), VAL(45)));
    L_3764972: ;
    return;
}
