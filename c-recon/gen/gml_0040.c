/* generated from CODE 40 (gml_Object_obj_enemy_Create_0), source start 3889016, end 3889840. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0040(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3889016 constant */
    /* @3889020 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3889028 constant */
    /* @3889032 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3889040 constant */
    /* @3889044 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3889052 constant */
    /* @3889056 cast */
    /* @3889060 constant */
    /* @3889064 cast */
    /* @3889068 constant */
    /* @3889072 cast */
    /* @3889076 constant */
    /* @3889080 cast */
    /* @3889084 constant */
    /* @3889088 cast */
    /* @3889092 call */
    GM_SITE(vm, 40, 3889092);
    /* @3889100 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3889108 constant */
    /* @3889112 cast */
    /* @3889116 constant */
    /* @3889120 cast */
    /* @3889124 constant */
    /* @3889128 cast */
    /* @3889132 constant */
    /* @3889136 cast */
    /* @3889140 constant */
    /* @3889144 cast */
    /* @3889148 call */
    GM_SITE(vm, 40, 3889148);
    /* @3889156 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3889164 constant */
    /* @3889168 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3889176 constant */
    /* @3889180 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3889188 constant */
    /* @3889192 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3889200 constant */
    /* @3889204 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3889212 constant */
    /* @3889216 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3889224 constant */
    /* @3889228 store */
    GM_WRITE(vm, -1, "hpfrozen", VAL(0));
    /* @3889236 load */
    /* @3889244 constant */
    /* @3889248 cmp */
    /* @3889252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3889388;
    /* @3889256 load */
    /* @3889264 constant */
    /* @3889268 cmp */
    /* @3889272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3889288;
    /* @3889276 constant */
    /* @3889280 store */
    GM_WRITE(vm, -1, "hp", VAL(10));
    L_3889288: ;
    /* @3889288 load */
    /* @3889296 constant */
    /* @3889300 cmp */
    /* @3889304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3889320;
    /* @3889308 constant */
    /* @3889312 store */
    GM_WRITE(vm, -1, "hp", VAL(9));
    L_3889320: ;
    /* @3889320 load */
    /* @3889328 constant */
    /* @3889332 cmp */
    /* @3889336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3889352;
    /* @3889340 constant */
    /* @3889344 store */
    GM_WRITE(vm, -1, "hp", VAL(8));
    L_3889352: ;
    /* @3889352 load */
    /* @3889360 constant */
    /* @3889364 cmp */
    /* @3889368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3889384;
    /* @3889372 constant */
    /* @3889376 store */
    GM_WRITE(vm, -1, "hp", VAL(7));
    L_3889384: ;
    /* @3889384 b */
    goto L_3889840;
    L_3889388: ;
    /* @3889388 load */
    /* @3889396 constant */
    /* @3889400 cmp */
    /* @3889404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3889540;
    /* @3889408 load */
    /* @3889416 constant */
    /* @3889420 cmp */
    /* @3889424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3889440;
    /* @3889428 constant */
    /* @3889432 store */
    GM_WRITE(vm, -1, "hp", VAL(15));
    L_3889440: ;
    /* @3889440 load */
    /* @3889448 constant */
    /* @3889452 cmp */
    /* @3889456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3889472;
    /* @3889460 constant */
    /* @3889464 store */
    GM_WRITE(vm, -1, "hp", VAL(13));
    L_3889472: ;
    /* @3889472 load */
    /* @3889480 constant */
    /* @3889484 cmp */
    /* @3889488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3889504;
    /* @3889492 constant */
    /* @3889496 store */
    GM_WRITE(vm, -1, "hp", VAL(11));
    L_3889504: ;
    /* @3889504 load */
    /* @3889512 constant */
    /* @3889516 cmp */
    /* @3889520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3889536;
    /* @3889524 constant */
    /* @3889528 store */
    GM_WRITE(vm, -1, "hp", VAL(8));
    L_3889536: ;
    /* @3889536 b */
    goto L_3889840;
    L_3889540: ;
    /* @3889540 load */
    /* @3889548 constant */
    /* @3889552 cmp */
    /* @3889556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3889692;
    /* @3889560 load */
    /* @3889568 constant */
    /* @3889572 cmp */
    /* @3889576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3889592;
    /* @3889580 constant */
    /* @3889584 store */
    GM_WRITE(vm, -1, "hp", VAL(25));
    L_3889592: ;
    /* @3889592 load */
    /* @3889600 constant */
    /* @3889604 cmp */
    /* @3889608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3889624;
    /* @3889612 constant */
    /* @3889616 store */
    GM_WRITE(vm, -1, "hp", VAL(22));
    L_3889624: ;
    /* @3889624 load */
    /* @3889632 constant */
    /* @3889636 cmp */
    /* @3889640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3889656;
    /* @3889644 constant */
    /* @3889648 store */
    GM_WRITE(vm, -1, "hp", VAL(16));
    L_3889656: ;
    /* @3889656 load */
    /* @3889664 constant */
    /* @3889668 cmp */
    /* @3889672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3889688;
    /* @3889676 constant */
    /* @3889680 store */
    GM_WRITE(vm, -1, "hp", VAL(12));
    L_3889688: ;
    /* @3889688 b */
    goto L_3889840;
    L_3889692: ;
    /* @3889692 load */
    /* @3889700 constant */
    /* @3889704 cmp */
    /* @3889708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3889840;
    /* @3889712 load */
    /* @3889720 constant */
    /* @3889724 cmp */
    /* @3889728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3889744;
    /* @3889732 constant */
    /* @3889736 store */
    GM_WRITE(vm, -1, "hp", VAL(35));
    L_3889744: ;
    /* @3889744 load */
    /* @3889752 constant */
    /* @3889756 cmp */
    /* @3889760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3889776;
    /* @3889764 constant */
    /* @3889768 store */
    GM_WRITE(vm, -1, "hp", VAL(28));
    L_3889776: ;
    /* @3889776 load */
    /* @3889784 constant */
    /* @3889788 cmp */
    /* @3889792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3889808;
    /* @3889796 constant */
    /* @3889800 store */
    GM_WRITE(vm, -1, "hp", VAL(22));
    L_3889808: ;
    /* @3889808 load */
    /* @3889816 constant */
    /* @3889820 cmp */
    /* @3889824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3889840;
    /* @3889828 constant */
    /* @3889832 store */
    GM_WRITE(vm, -1, "hp", VAL(16));
    L_3889840: ;
    return;
}
