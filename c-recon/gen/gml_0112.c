/* generated from CODE 112 (gml_Object_obj_hulkingbandit_Create_0), source start 3941584, end 3942440. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0112(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3941584 constant */
    /* @3941588 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3941596 constant */
    /* @3941600 cast */
    /* @3941604 constant */
    /* @3941608 cast */
    /* @3941612 constant */
    /* @3941616 cast */
    /* @3941620 constant */
    /* @3941624 cast */
    /* @3941628 constant */
    /* @3941632 cast */
    /* @3941636 call */
    GM_SITE(vm, 112, 3941636);
    /* @3941644 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3941652 constant */
    /* @3941656 cast */
    /* @3941660 constant */
    /* @3941664 cast */
    /* @3941668 constant */
    /* @3941672 cast */
    /* @3941676 constant */
    /* @3941680 cast */
    /* @3941684 constant */
    /* @3941688 cast */
    /* @3941692 call */
    GM_SITE(vm, 112, 3941692);
    /* @3941700 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3941708 constant */
    /* @3941712 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3941720 constant */
    /* @3941724 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3941732 constant */
    /* @3941736 store */
    GM_WRITE(vm, -1, "hphulkingbanditfrozen", VAL(0));
    /* @3941744 constant */
    /* @3941748 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3941756 constant */
    /* @3941760 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3941768 constant */
    /* @3941772 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3941780 constant */
    /* @3941784 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3941792 constant */
    /* @3941796 constant */
    /* @3941800 constant */
    /* @3941804 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    /* @3941812 constant */
    /* @3941816 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3941824 constant */
    /* @3941828 store */
    GM_WRITE(vm, -1, "shooting", VAL(0));
    /* @3941836 load */
    /* @3941844 constant */
    /* @3941848 cmp */
    /* @3941852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3941988;
    /* @3941856 load */
    /* @3941864 constant */
    /* @3941868 cmp */
    /* @3941872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3941888;
    /* @3941876 constant */
    /* @3941880 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(100));
    L_3941888: ;
    /* @3941888 load */
    /* @3941896 constant */
    /* @3941900 cmp */
    /* @3941904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3941920;
    /* @3941908 constant */
    /* @3941912 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(95));
    L_3941920: ;
    /* @3941920 load */
    /* @3941928 constant */
    /* @3941932 cmp */
    /* @3941936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3941952;
    /* @3941940 constant */
    /* @3941944 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(90));
    L_3941952: ;
    /* @3941952 load */
    /* @3941960 constant */
    /* @3941964 cmp */
    /* @3941968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3941984;
    /* @3941972 constant */
    /* @3941976 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(85));
    L_3941984: ;
    /* @3941984 b */
    goto L_3942440;
    L_3941988: ;
    /* @3941988 load */
    /* @3941996 constant */
    /* @3942000 cmp */
    /* @3942004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3942140;
    /* @3942008 load */
    /* @3942016 constant */
    /* @3942020 cmp */
    /* @3942024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3942040;
    /* @3942028 constant */
    /* @3942032 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(100));
    L_3942040: ;
    /* @3942040 load */
    /* @3942048 constant */
    /* @3942052 cmp */
    /* @3942056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3942072;
    /* @3942060 constant */
    /* @3942064 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(95));
    L_3942072: ;
    /* @3942072 load */
    /* @3942080 constant */
    /* @3942084 cmp */
    /* @3942088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3942104;
    /* @3942092 constant */
    /* @3942096 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(90));
    L_3942104: ;
    /* @3942104 load */
    /* @3942112 constant */
    /* @3942116 cmp */
    /* @3942120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3942136;
    /* @3942124 constant */
    /* @3942128 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(85));
    L_3942136: ;
    /* @3942136 b */
    goto L_3942440;
    L_3942140: ;
    /* @3942140 load */
    /* @3942148 constant */
    /* @3942152 cmp */
    /* @3942156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3942292;
    /* @3942160 load */
    /* @3942168 constant */
    /* @3942172 cmp */
    /* @3942176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3942192;
    /* @3942180 constant */
    /* @3942184 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(120));
    L_3942192: ;
    /* @3942192 load */
    /* @3942200 constant */
    /* @3942204 cmp */
    /* @3942208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3942224;
    /* @3942212 constant */
    /* @3942216 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(115));
    L_3942224: ;
    /* @3942224 load */
    /* @3942232 constant */
    /* @3942236 cmp */
    /* @3942240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3942256;
    /* @3942244 constant */
    /* @3942248 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(110));
    L_3942256: ;
    /* @3942256 load */
    /* @3942264 constant */
    /* @3942268 cmp */
    /* @3942272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3942288;
    /* @3942276 constant */
    /* @3942280 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(105));
    L_3942288: ;
    /* @3942288 b */
    goto L_3942440;
    L_3942292: ;
    /* @3942292 load */
    /* @3942300 constant */
    /* @3942304 cmp */
    /* @3942308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3942440;
    /* @3942312 load */
    /* @3942320 constant */
    /* @3942324 cmp */
    /* @3942328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3942344;
    /* @3942332 constant */
    /* @3942336 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(130));
    L_3942344: ;
    /* @3942344 load */
    /* @3942352 constant */
    /* @3942356 cmp */
    /* @3942360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3942376;
    /* @3942364 constant */
    /* @3942368 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(125));
    L_3942376: ;
    /* @3942376 load */
    /* @3942384 constant */
    /* @3942388 cmp */
    /* @3942392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3942408;
    /* @3942396 constant */
    /* @3942400 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(118));
    L_3942408: ;
    /* @3942408 load */
    /* @3942416 constant */
    /* @3942420 cmp */
    /* @3942424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3942440;
    /* @3942428 constant */
    /* @3942432 store */
    GM_WRITE(vm, -1, "hphulkingbandit", VAL(113));
    L_3942440: ;
    return;
}
