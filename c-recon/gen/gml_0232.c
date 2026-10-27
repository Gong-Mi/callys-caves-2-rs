/* generated from CODE 232 (gml_Object_obj_bat_Create_0), source start 4031740, end 4032648. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0232(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4031740 constant */
    /* @4031744 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4031752 constant */
    /* @4031756 constant */
    /* @4031760 constant */
    /* @4031764 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(30));
    /* @4031772 constant */
    /* @4031776 cast */
    /* @4031780 constant */
    /* @4031784 cast */
    /* @4031788 constant */
    /* @4031792 cast */
    /* @4031796 constant */
    /* @4031800 cast */
    /* @4031804 constant */
    /* @4031808 cast */
    /* @4031812 call */
    GM_SITE(vm, 232, 4031812);
    /* @4031820 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @4031828 constant */
    /* @4031832 cast */
    /* @4031836 constant */
    /* @4031840 cast */
    /* @4031844 constant */
    /* @4031848 cast */
    /* @4031852 constant */
    /* @4031856 cast */
    /* @4031860 call */
    GM_SITE(vm, 232, 4031860);
    /* @4031868 store */
    v2 = GM_CALL(vm, "choose", 4, VAL(1), VAL(2), VAL(3), VAL(4));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @4031876 constant */
    /* @4031880 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4031888 constant */
    /* @4031892 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4031900 constant */
    /* @4031904 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4031912 constant */
    /* @4031916 cast */
    /* @4031920 constant */
    /* @4031924 cast */
    /* @4031928 constant */
    /* @4031932 cast */
    /* @4031936 constant */
    /* @4031940 cast */
    /* @4031944 constant */
    /* @4031948 cast */
    /* @4031952 constant */
    /* @4031956 cast */
    /* @4031960 constant */
    /* @4031964 cast */
    /* @4031968 call */
    GM_SITE(vm, 232, 4031968);
    /* @4031976 store */
    v3 = GM_CALL(vm, "choose", 7, VAL(0), VAL(60), VAL(120), VAL(180), VAL(240), VAL(300), VAL(360));
    GM_WRITE(vm, -1, "batdirection", v3);
    /* @4031984 constant */
    /* @4031988 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(66));
    /* @4031996 constant */
    /* @4032000 store */
    GM_WRITE(vm, -1, "moving", VAL(0));
    /* @4032008 constant */
    /* @4032012 store */
    GM_WRITE(vm, -1, "awake", VAL(0));
    /* @4032020 constant */
    /* @4032024 store */
    GM_WRITE(vm, -1, "hpfourfrozen", VAL(0));
    /* @4032032 constant */
    /* @4032036 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @4032044 load */
    /* @4032052 constant */
    /* @4032056 cmp */
    /* @4032060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_4032196;
    /* @4032064 load */
    /* @4032072 constant */
    /* @4032076 cmp */
    /* @4032080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4032096;
    /* @4032084 constant */
    /* @4032088 store */
    GM_WRITE(vm, -1, "hpfour", VAL(12));
    L_4032096: ;
    /* @4032096 load */
    /* @4032104 constant */
    /* @4032108 cmp */
    /* @4032112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4032128;
    /* @4032116 constant */
    /* @4032120 store */
    GM_WRITE(vm, -1, "hpfour", VAL(11));
    L_4032128: ;
    /* @4032128 load */
    /* @4032136 constant */
    /* @4032140 cmp */
    /* @4032144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4032160;
    /* @4032148 constant */
    /* @4032152 store */
    GM_WRITE(vm, -1, "hpfour", VAL(10));
    L_4032160: ;
    /* @4032160 load */
    /* @4032168 constant */
    /* @4032172 cmp */
    /* @4032176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4032192;
    /* @4032180 constant */
    /* @4032184 store */
    GM_WRITE(vm, -1, "hpfour", VAL(9));
    L_4032192: ;
    /* @4032192 b */
    goto L_4032648;
    L_4032196: ;
    /* @4032196 load */
    /* @4032204 constant */
    /* @4032208 cmp */
    /* @4032212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_4032348;
    /* @4032216 load */
    /* @4032224 constant */
    /* @4032228 cmp */
    /* @4032232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4032248;
    /* @4032236 constant */
    /* @4032240 store */
    GM_WRITE(vm, -1, "hpfour", VAL(14));
    L_4032248: ;
    /* @4032248 load */
    /* @4032256 constant */
    /* @4032260 cmp */
    /* @4032264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4032280;
    /* @4032268 constant */
    /* @4032272 store */
    GM_WRITE(vm, -1, "hpfour", VAL(12));
    L_4032280: ;
    /* @4032280 load */
    /* @4032288 constant */
    /* @4032292 cmp */
    /* @4032296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4032312;
    /* @4032300 constant */
    /* @4032304 store */
    GM_WRITE(vm, -1, "hpfour", VAL(11));
    L_4032312: ;
    /* @4032312 load */
    /* @4032320 constant */
    /* @4032324 cmp */
    /* @4032328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4032344;
    /* @4032332 constant */
    /* @4032336 store */
    GM_WRITE(vm, -1, "hpfour", VAL(10));
    L_4032344: ;
    /* @4032344 b */
    goto L_4032648;
    L_4032348: ;
    /* @4032348 load */
    /* @4032356 constant */
    /* @4032360 cmp */
    /* @4032364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_4032500;
    /* @4032368 load */
    /* @4032376 constant */
    /* @4032380 cmp */
    /* @4032384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4032400;
    /* @4032388 constant */
    /* @4032392 store */
    GM_WRITE(vm, -1, "hpfour", VAL(18));
    L_4032400: ;
    /* @4032400 load */
    /* @4032408 constant */
    /* @4032412 cmp */
    /* @4032416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4032432;
    /* @4032420 constant */
    /* @4032424 store */
    GM_WRITE(vm, -1, "hpfour", VAL(16));
    L_4032432: ;
    /* @4032432 load */
    /* @4032440 constant */
    /* @4032444 cmp */
    /* @4032448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4032464;
    /* @4032452 constant */
    /* @4032456 store */
    GM_WRITE(vm, -1, "hpfour", VAL(15));
    L_4032464: ;
    /* @4032464 load */
    /* @4032472 constant */
    /* @4032476 cmp */
    /* @4032480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4032496;
    /* @4032484 constant */
    /* @4032488 store */
    GM_WRITE(vm, -1, "hpfour", VAL(14));
    L_4032496: ;
    /* @4032496 b */
    goto L_4032648;
    L_4032500: ;
    /* @4032500 load */
    /* @4032508 constant */
    /* @4032512 cmp */
    /* @4032516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_4032648;
    /* @4032520 load */
    /* @4032528 constant */
    /* @4032532 cmp */
    /* @4032536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4032552;
    /* @4032540 constant */
    /* @4032544 store */
    GM_WRITE(vm, -1, "hpfour", VAL(22));
    L_4032552: ;
    /* @4032552 load */
    /* @4032560 constant */
    /* @4032564 cmp */
    /* @4032568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4032584;
    /* @4032572 constant */
    /* @4032576 store */
    GM_WRITE(vm, -1, "hpfour", VAL(20));
    L_4032584: ;
    /* @4032584 load */
    /* @4032592 constant */
    /* @4032596 cmp */
    /* @4032600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4032616;
    /* @4032604 constant */
    /* @4032608 store */
    GM_WRITE(vm, -1, "hpfour", VAL(18));
    L_4032616: ;
    /* @4032616 load */
    /* @4032624 constant */
    /* @4032628 cmp */
    /* @4032632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4032648;
    /* @4032636 constant */
    /* @4032640 store */
    GM_WRITE(vm, -1, "hpfour", VAL(16));
    L_4032648: ;
    return;
}
