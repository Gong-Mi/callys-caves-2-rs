/* generated from CODE 169 (gml_Object_obj_boss2_Step_0), source start 3993464, end 3994020. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0169(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3993464 load */
    /* @3993472 constant */
    /* @3993476 cmp */
    /* @3993480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss2") >= VAL(0)))) goto L_3993504;
    /* @3993484 constant */
    /* @3993488 constant */
    /* @3993492 constant */
    /* @3993496 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3993504: ;
    /* @3993504 load */
    /* @3993512 constant */
    /* @3993516 cmp */
    /* @3993520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpboss2") <= VAL(0)))) goto L_3993544;
    /* @3993524 constant */
    /* @3993528 constant */
    /* @3993532 constant */
    /* @3993536 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3993544: ;
    /* @3993544 constant */
    /* @3993548 constant */
    /* @3993552 load */
    /* @3993560 constant */
    /* @3993564 cmp */
    /* @3993568 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(1)) <= VAL(0)))) goto L_3993592;
    /* @3993572 constant */
    /* @3993576 constant */
    /* @3993580 constant */
    /* @3993584 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(200));
    L_3993592: ;
    /* @3993592 constant */
    /* @3993596 cast */
    /* @3993600 load */
    /* @3993608 load */
    /* @3993616 add */
    /* @3993620 load */
    /* @3993628 call */
    GM_SITE(vm, 169, 3993628);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3993636 cast */
    /* @3993640 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3993684;
    /* @3993644 constant */
    /* @3993648 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3993656 constant */
    /* @3993660 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3993668 constant */
    /* @3993672 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3993680 b */
    goto L_3993716;
    L_3993684: ;
    /* @3993684 constant */
    /* @3993696 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3993704 constant */
    /* @3993708 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3993716: ;
    /* @3993716 load */
    /* @3993724 constant */
    /* @3993728 cmp */
    /* @3993732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > VAL(800)))) goto L_3993748;
    /* @3993736 constant */
    /* @3993740 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3993748: ;
    /* @3993748 load */
    /* @3993756 constant */
    /* @3993760 cmp */
    /* @3993764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < VAL(512)))) goto L_3993780;
    /* @3993768 constant */
    /* @3993772 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3993780: ;
    /* @3993780 load */
    /* @3993788 constant */
    /* @3993792 cmp */
    /* @3993796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3993832;
    /* @3993800 constant */
    /* @3993812 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-0.3));
    /* @3993820 constant */
    /* @3993824 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3993832: ;
    /* @3993832 load */
    /* @3993840 constant */
    /* @3993844 cmp */
    /* @3993848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3993884;
    /* @3993852 constant */
    /* @3993864 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0.3));
    /* @3993872 constant */
    /* @3993876 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3993884: ;
    /* @3993884 load */
    /* @3993892 constant */
    /* @3993896 cmp */
    /* @3993900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3993940;
    /* @3993904 constant */
    /* @3993908 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    /* @3993916 constant */
    /* @3993920 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3993928 constant */
    /* @3993932 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3993940: ;
    /* @3993940 load */
    /* @3993948 constant */
    /* @3993952 cmp */
    /* @3993956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3993976;
    /* @3993960 constant */
    /* @3993968 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3993976: ;
    /* @3993976 load */
    /* @3993984 constant */
    /* @3993988 cmp */
    /* @3993992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3994020;
    /* @3993996 constant */
    /* @3994000 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3994008 constant */
    /* @3994012 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3994020: ;
    return;
}
