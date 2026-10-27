/* generated from CODE 256 (gml_Object_obj_fireslime_Create_0), source start 4047992, end 4048892. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0256(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4047992 constant */
    /* @4047996 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4048004 constant */
    /* @4048008 cast */
    /* @4048012 constant */
    /* @4048016 cast */
    /* @4048020 constant */
    /* @4048024 cast */
    /* @4048028 constant */
    /* @4048032 cast */
    /* @4048036 constant */
    /* @4048040 cast */
    /* @4048044 call */
    GM_SITE(vm, 256, 4048044);
    /* @4048052 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @4048060 constant */
    /* @4048064 cast */
    /* @4048068 constant */
    /* @4048072 cast */
    /* @4048076 constant */
    /* @4048080 cast */
    /* @4048084 constant */
    /* @4048088 cast */
    /* @4048092 constant */
    /* @4048096 cast */
    /* @4048100 call */
    GM_SITE(vm, 256, 4048100);
    /* @4048108 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @4048116 constant */
    /* @4048120 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4048128 constant */
    /* @4048132 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4048140 constant */
    /* @4048144 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4048152 constant */
    /* @4048156 store */
    GM_WRITE(vm, -1, "blobjump", VAL(45));
    /* @4048164 constant */
    /* @4048168 constant */
    /* @4048172 constant */
    /* @4048176 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    /* @4048184 constant */
    /* @4048188 constant */
    /* @4048192 constant */
    /* @4048196 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(40));
    /* @4048204 constant */
    /* @4048208 cast */
    /* @4048212 constant */
    /* @4048216 cast */
    /* @4048220 call */
    GM_SITE(vm, 256, 4048220);
    /* @4048228 store */
    v3 = GM_CALL(vm, "choose", 2, VAL(-3), VAL(3));
    GM_WRITE(vm, -1, "slimedirection", v3);
    /* @4048236 constant */
    /* @4048240 store */
    GM_WRITE(vm, -1, "hpfireslimefrozen", VAL(0));
    /* @4048248 load */
    /* @4048256 store */
    GM_WRITE(vm, -1, "hspeed", GM_READ(vm, -1, "slimedirection"));
    /* @4048264 constant */
    /* @4048268 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @4048276 constant */
    /* @4048280 store */
    GM_WRITE(vm, -1, "jumping", VAL(0));
    /* @4048288 load */
    /* @4048296 constant */
    /* @4048300 cmp */
    /* @4048304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_4048440;
    /* @4048308 load */
    /* @4048316 constant */
    /* @4048320 cmp */
    /* @4048324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4048340;
    /* @4048328 constant */
    /* @4048332 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(80));
    L_4048340: ;
    /* @4048340 load */
    /* @4048348 constant */
    /* @4048352 cmp */
    /* @4048356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4048372;
    /* @4048360 constant */
    /* @4048364 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(75));
    L_4048372: ;
    /* @4048372 load */
    /* @4048380 constant */
    /* @4048384 cmp */
    /* @4048388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4048404;
    /* @4048392 constant */
    /* @4048396 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(70));
    L_4048404: ;
    /* @4048404 load */
    /* @4048412 constant */
    /* @4048416 cmp */
    /* @4048420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4048436;
    /* @4048424 constant */
    /* @4048428 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(60));
    L_4048436: ;
    /* @4048436 b */
    goto L_4048892;
    L_4048440: ;
    /* @4048440 load */
    /* @4048448 constant */
    /* @4048452 cmp */
    /* @4048456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_4048592;
    /* @4048460 load */
    /* @4048468 constant */
    /* @4048472 cmp */
    /* @4048476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4048492;
    /* @4048480 constant */
    /* @4048484 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(86));
    L_4048492: ;
    /* @4048492 load */
    /* @4048500 constant */
    /* @4048504 cmp */
    /* @4048508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4048524;
    /* @4048512 constant */
    /* @4048516 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(80));
    L_4048524: ;
    /* @4048524 load */
    /* @4048532 constant */
    /* @4048536 cmp */
    /* @4048540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4048556;
    /* @4048544 constant */
    /* @4048548 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(76));
    L_4048556: ;
    /* @4048556 load */
    /* @4048564 constant */
    /* @4048568 cmp */
    /* @4048572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4048588;
    /* @4048576 constant */
    /* @4048580 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(68));
    L_4048588: ;
    /* @4048588 b */
    goto L_4048892;
    L_4048592: ;
    /* @4048592 load */
    /* @4048600 constant */
    /* @4048604 cmp */
    /* @4048608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_4048744;
    /* @4048612 load */
    /* @4048620 constant */
    /* @4048624 cmp */
    /* @4048628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4048644;
    /* @4048632 constant */
    /* @4048636 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(95));
    L_4048644: ;
    /* @4048644 load */
    /* @4048652 constant */
    /* @4048656 cmp */
    /* @4048660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4048676;
    /* @4048664 constant */
    /* @4048668 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(88));
    L_4048676: ;
    /* @4048676 load */
    /* @4048684 constant */
    /* @4048688 cmp */
    /* @4048692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4048708;
    /* @4048696 constant */
    /* @4048700 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(82));
    L_4048708: ;
    /* @4048708 load */
    /* @4048716 constant */
    /* @4048720 cmp */
    /* @4048724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4048740;
    /* @4048728 constant */
    /* @4048732 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(78));
    L_4048740: ;
    /* @4048740 b */
    goto L_4048892;
    L_4048744: ;
    /* @4048744 load */
    /* @4048752 constant */
    /* @4048756 cmp */
    /* @4048760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_4048892;
    /* @4048764 load */
    /* @4048772 constant */
    /* @4048776 cmp */
    /* @4048780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4048796;
    /* @4048784 constant */
    /* @4048788 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(110));
    L_4048796: ;
    /* @4048796 load */
    /* @4048804 constant */
    /* @4048808 cmp */
    /* @4048812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4048828;
    /* @4048816 constant */
    /* @4048820 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(98));
    L_4048828: ;
    /* @4048828 load */
    /* @4048836 constant */
    /* @4048840 cmp */
    /* @4048844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4048860;
    /* @4048848 constant */
    /* @4048852 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(90));
    L_4048860: ;
    /* @4048860 load */
    /* @4048868 constant */
    /* @4048872 cmp */
    /* @4048876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4048892;
    /* @4048880 constant */
    /* @4048884 store */
    GM_WRITE(vm, -1, "hpfireslime", VAL(85));
    L_4048892: ;
    return;
}
