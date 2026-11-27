/* generated from CODE 49 (gml_Object_obj_knifebandit_Create_0), source start 3895324, end 3896148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0049(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3895324 constant */
    /* @3895328 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3895336 constant */
    /* @3895340 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3895348 constant */
    /* @3895352 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3895360 constant */
    /* @3895364 cast */
    /* @3895368 constant */
    /* @3895372 cast */
    /* @3895376 constant */
    /* @3895380 cast */
    /* @3895384 constant */
    /* @3895388 cast */
    /* @3895392 constant */
    /* @3895396 cast */
    /* @3895400 call */
    GM_SITE(vm, 49, 3895400);
    /* @3895408 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3895416 constant */
    /* @3895420 cast */
    /* @3895424 constant */
    /* @3895428 cast */
    /* @3895432 constant */
    /* @3895436 cast */
    /* @3895440 constant */
    /* @3895444 cast */
    /* @3895448 constant */
    /* @3895452 cast */
    /* @3895456 call */
    GM_SITE(vm, 49, 3895456);
    /* @3895464 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3895472 constant */
    /* @3895476 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3895484 constant */
    /* @3895488 store */
    GM_WRITE(vm, -1, "knifehsp", VAL(0));
    /* @3895496 constant */
    /* @3895500 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3895508 constant */
    /* @3895512 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3895520 constant */
    /* @3895524 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3895532 constant */
    /* @3895536 store */
    GM_WRITE(vm, -1, "hpfrozen", VAL(0));
    /* @3895544 load */
    /* @3895552 constant */
    /* @3895556 cmp */
    /* @3895560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3895696;
    /* @3895564 load */
    /* @3895572 constant */
    /* @3895576 cmp */
    /* @3895580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3895596;
    /* @3895584 constant */
    /* @3895588 store */
    GM_WRITE(vm, -1, "hpknife", VAL(15));
    L_3895596: ;
    /* @3895596 load */
    /* @3895604 constant */
    /* @3895608 cmp */
    /* @3895612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3895628;
    /* @3895616 constant */
    /* @3895620 store */
    GM_WRITE(vm, -1, "hpknife", VAL(14));
    L_3895628: ;
    /* @3895628 load */
    /* @3895636 constant */
    /* @3895640 cmp */
    /* @3895644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3895660;
    /* @3895648 constant */
    /* @3895652 store */
    GM_WRITE(vm, -1, "hpknife", VAL(12));
    L_3895660: ;
    /* @3895660 load */
    /* @3895668 constant */
    /* @3895672 cmp */
    /* @3895676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3895692;
    /* @3895680 constant */
    /* @3895684 store */
    GM_WRITE(vm, -1, "hpknife", VAL(11));
    L_3895692: ;
    /* @3895692 b */
    goto L_3896148;
    L_3895696: ;
    /* @3895696 load */
    /* @3895704 constant */
    /* @3895708 cmp */
    /* @3895712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3895848;
    /* @3895716 load */
    /* @3895724 constant */
    /* @3895728 cmp */
    /* @3895732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3895748;
    /* @3895736 constant */
    /* @3895740 store */
    GM_WRITE(vm, -1, "hpknife", VAL(20));
    L_3895748: ;
    /* @3895748 load */
    /* @3895756 constant */
    /* @3895760 cmp */
    /* @3895764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3895780;
    /* @3895768 constant */
    /* @3895772 store */
    GM_WRITE(vm, -1, "hpknife", VAL(17));
    L_3895780: ;
    /* @3895780 load */
    /* @3895788 constant */
    /* @3895792 cmp */
    /* @3895796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3895812;
    /* @3895800 constant */
    /* @3895804 store */
    GM_WRITE(vm, -1, "hpknife", VAL(15));
    L_3895812: ;
    /* @3895812 load */
    /* @3895820 constant */
    /* @3895824 cmp */
    /* @3895828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3895844;
    /* @3895832 constant */
    /* @3895836 store */
    GM_WRITE(vm, -1, "hpknife", VAL(12));
    L_3895844: ;
    /* @3895844 b */
    goto L_3896148;
    L_3895848: ;
    /* @3895848 load */
    /* @3895856 constant */
    /* @3895860 cmp */
    /* @3895864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3896000;
    /* @3895868 load */
    /* @3895876 constant */
    /* @3895880 cmp */
    /* @3895884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3895900;
    /* @3895888 constant */
    /* @3895892 store */
    GM_WRITE(vm, -1, "hpknife", VAL(30));
    L_3895900: ;
    /* @3895900 load */
    /* @3895908 constant */
    /* @3895912 cmp */
    /* @3895916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3895932;
    /* @3895920 constant */
    /* @3895924 store */
    GM_WRITE(vm, -1, "hpknife", VAL(23));
    L_3895932: ;
    /* @3895932 load */
    /* @3895940 constant */
    /* @3895944 cmp */
    /* @3895948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3895964;
    /* @3895952 constant */
    /* @3895956 store */
    GM_WRITE(vm, -1, "hpknife", VAL(20));
    L_3895964: ;
    /* @3895964 load */
    /* @3895972 constant */
    /* @3895976 cmp */
    /* @3895980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3895996;
    /* @3895984 constant */
    /* @3895988 store */
    GM_WRITE(vm, -1, "hpknife", VAL(17));
    L_3895996: ;
    /* @3895996 b */
    goto L_3896148;
    L_3896000: ;
    /* @3896000 load */
    /* @3896008 constant */
    /* @3896012 cmp */
    /* @3896016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3896148;
    /* @3896020 load */
    /* @3896028 constant */
    /* @3896032 cmp */
    /* @3896036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3896052;
    /* @3896040 constant */
    /* @3896044 store */
    GM_WRITE(vm, -1, "hpknife", VAL(35));
    L_3896052: ;
    /* @3896052 load */
    /* @3896060 constant */
    /* @3896064 cmp */
    /* @3896068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3896084;
    /* @3896072 constant */
    /* @3896076 store */
    GM_WRITE(vm, -1, "hpknife", VAL(30));
    L_3896084: ;
    /* @3896084 load */
    /* @3896092 constant */
    /* @3896096 cmp */
    /* @3896100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3896116;
    /* @3896104 constant */
    /* @3896108 store */
    GM_WRITE(vm, -1, "hpknife", VAL(25));
    L_3896116: ;
    /* @3896116 load */
    /* @3896124 constant */
    /* @3896128 cmp */
    /* @3896132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3896148;
    /* @3896136 constant */
    /* @3896140 store */
    GM_WRITE(vm, -1, "hpknife", VAL(20));
    L_3896148: ;
    return;
}
