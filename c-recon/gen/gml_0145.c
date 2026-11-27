/* generated from CODE 145 (gml_Object_obj_ghost_Create_0), source start 3965532, end 3966332. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0145(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3965532 constant */
    /* @3965536 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3965544 constant */
    /* @3965548 cast */
    /* @3965552 constant */
    /* @3965556 cast */
    /* @3965560 constant */
    /* @3965564 cast */
    /* @3965568 constant */
    /* @3965572 cast */
    /* @3965576 constant */
    /* @3965580 cast */
    /* @3965584 call */
    GM_SITE(vm, 145, 3965584);
    /* @3965592 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3965600 constant */
    /* @3965604 cast */
    /* @3965608 constant */
    /* @3965612 cast */
    /* @3965616 constant */
    /* @3965620 cast */
    /* @3965624 constant */
    /* @3965628 cast */
    /* @3965632 constant */
    /* @3965636 cast */
    /* @3965640 call */
    GM_SITE(vm, 145, 3965640);
    /* @3965648 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3965656 constant */
    /* @3965660 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3965668 constant */
    /* @3965672 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3965680 constant */
    /* @3965684 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3965692 constant */
    /* @3965696 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3965704 constant */
    /* @3965708 store */
    GM_WRITE(vm, -1, "hpghostfrozen", VAL(0));
    /* @3965716 constant */
    /* @3965720 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3965728 load */
    /* @3965736 constant */
    /* @3965740 cmp */
    /* @3965744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3965880;
    /* @3965748 load */
    /* @3965756 constant */
    /* @3965760 cmp */
    /* @3965764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3965780;
    /* @3965768 constant */
    /* @3965772 store */
    GM_WRITE(vm, -1, "hpghost", VAL(45));
    L_3965780: ;
    /* @3965780 load */
    /* @3965788 constant */
    /* @3965792 cmp */
    /* @3965796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3965812;
    /* @3965800 constant */
    /* @3965804 store */
    GM_WRITE(vm, -1, "hpghost", VAL(42));
    L_3965812: ;
    /* @3965812 load */
    /* @3965820 constant */
    /* @3965824 cmp */
    /* @3965828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3965844;
    /* @3965832 constant */
    /* @3965836 store */
    GM_WRITE(vm, -1, "hpghost", VAL(39));
    L_3965844: ;
    /* @3965844 load */
    /* @3965852 constant */
    /* @3965856 cmp */
    /* @3965860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3965876;
    /* @3965864 constant */
    /* @3965868 store */
    GM_WRITE(vm, -1, "hpghost", VAL(35));
    L_3965876: ;
    /* @3965876 b */
    goto L_3966332;
    L_3965880: ;
    /* @3965880 load */
    /* @3965888 constant */
    /* @3965892 cmp */
    /* @3965896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3966032;
    /* @3965900 load */
    /* @3965908 constant */
    /* @3965912 cmp */
    /* @3965916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3965932;
    /* @3965920 constant */
    /* @3965924 store */
    GM_WRITE(vm, -1, "hpghost", VAL(47));
    L_3965932: ;
    /* @3965932 load */
    /* @3965940 constant */
    /* @3965944 cmp */
    /* @3965948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3965964;
    /* @3965952 constant */
    /* @3965956 store */
    GM_WRITE(vm, -1, "hpghost", VAL(44));
    L_3965964: ;
    /* @3965964 load */
    /* @3965972 constant */
    /* @3965976 cmp */
    /* @3965980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3965996;
    /* @3965984 constant */
    /* @3965988 store */
    GM_WRITE(vm, -1, "hpghost", VAL(41));
    L_3965996: ;
    /* @3965996 load */
    /* @3966004 constant */
    /* @3966008 cmp */
    /* @3966012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3966028;
    /* @3966016 constant */
    /* @3966020 store */
    GM_WRITE(vm, -1, "hpghost", VAL(37));
    L_3966028: ;
    /* @3966028 b */
    goto L_3966332;
    L_3966032: ;
    /* @3966032 load */
    /* @3966040 constant */
    /* @3966044 cmp */
    /* @3966048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3966184;
    /* @3966052 load */
    /* @3966060 constant */
    /* @3966064 cmp */
    /* @3966068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3966084;
    /* @3966072 constant */
    /* @3966076 store */
    GM_WRITE(vm, -1, "hpghost", VAL(55));
    L_3966084: ;
    /* @3966084 load */
    /* @3966092 constant */
    /* @3966096 cmp */
    /* @3966100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3966116;
    /* @3966104 constant */
    /* @3966108 store */
    GM_WRITE(vm, -1, "hpghost", VAL(51));
    L_3966116: ;
    /* @3966116 load */
    /* @3966124 constant */
    /* @3966128 cmp */
    /* @3966132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3966148;
    /* @3966136 constant */
    /* @3966140 store */
    GM_WRITE(vm, -1, "hpghost", VAL(48));
    L_3966148: ;
    /* @3966148 load */
    /* @3966156 constant */
    /* @3966160 cmp */
    /* @3966164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3966180;
    /* @3966168 constant */
    /* @3966172 store */
    GM_WRITE(vm, -1, "hpghost", VAL(44));
    L_3966180: ;
    /* @3966180 b */
    goto L_3966332;
    L_3966184: ;
    /* @3966184 load */
    /* @3966192 constant */
    /* @3966196 cmp */
    /* @3966200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3966332;
    /* @3966204 load */
    /* @3966212 constant */
    /* @3966216 cmp */
    /* @3966220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3966236;
    /* @3966224 constant */
    /* @3966228 store */
    GM_WRITE(vm, -1, "hpghost", VAL(60));
    L_3966236: ;
    /* @3966236 load */
    /* @3966244 constant */
    /* @3966248 cmp */
    /* @3966252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3966268;
    /* @3966256 constant */
    /* @3966260 store */
    GM_WRITE(vm, -1, "hpghost", VAL(55));
    L_3966268: ;
    /* @3966268 load */
    /* @3966276 constant */
    /* @3966280 cmp */
    /* @3966284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3966300;
    /* @3966288 constant */
    /* @3966292 store */
    GM_WRITE(vm, -1, "hpghost", VAL(51));
    L_3966300: ;
    /* @3966300 load */
    /* @3966308 constant */
    /* @3966312 cmp */
    /* @3966316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3966332;
    /* @3966320 constant */
    /* @3966324 store */
    GM_WRITE(vm, -1, "hpghost", VAL(48));
    L_3966332: ;
    return;
}
