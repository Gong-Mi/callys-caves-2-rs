/* generated from CODE 69 (gml_Object_obj_skeleton_Create_0), source start 3910108, end 3910828. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0069(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3910108 constant */
    /* @3910112 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3910120 constant */
    /* @3910124 cast */
    /* @3910128 constant */
    /* @3910132 cast */
    /* @3910136 constant */
    /* @3910140 cast */
    /* @3910144 constant */
    /* @3910148 cast */
    /* @3910152 constant */
    /* @3910156 cast */
    /* @3910160 call */
    GM_SITE(vm, 69, 3910160);
    /* @3910168 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3910176 constant */
    /* @3910180 cast */
    /* @3910184 constant */
    /* @3910188 cast */
    /* @3910192 constant */
    /* @3910196 cast */
    /* @3910200 constant */
    /* @3910204 cast */
    /* @3910208 constant */
    /* @3910212 cast */
    /* @3910216 constant */
    /* @3910220 cast */
    /* @3910224 call */
    GM_SITE(vm, 69, 3910224);
    /* @3910232 store */
    v2 = GM_CALL(vm, "choose", 6, VAL(0), VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3910240 constant */
    /* @3910244 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3910252 constant */
    /* @3910256 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3910264 constant */
    /* @3910268 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3910276 constant */
    /* @3910280 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3910288 constant */
    /* @3910292 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3910300 constant */
    /* @3910304 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3910312 constant */
    /* @3910316 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3910324 constant */
    /* @3910328 store */
    GM_WRITE(vm, -1, "hpskeletonfrozen", VAL(0));
    /* @3910336 constant */
    /* @3910340 constant */
    /* @3910344 constant */
    /* @3910348 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(60));
    /* @3910356 constant */
    /* @3910360 constant */
    /* @3910364 constant */
    /* @3910368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(56));
    /* @3910376 load */
    /* @3910384 constant */
    /* @3910388 cmp */
    /* @3910392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3910528;
    /* @3910396 load */
    /* @3910404 constant */
    /* @3910408 cmp */
    /* @3910412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3910428;
    /* @3910416 constant */
    /* @3910420 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(60));
    L_3910428: ;
    /* @3910428 load */
    /* @3910436 constant */
    /* @3910440 cmp */
    /* @3910444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3910460;
    /* @3910448 constant */
    /* @3910452 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(55));
    L_3910460: ;
    /* @3910460 load */
    /* @3910468 constant */
    /* @3910472 cmp */
    /* @3910476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3910492;
    /* @3910480 constant */
    /* @3910484 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(50));
    L_3910492: ;
    /* @3910492 load */
    /* @3910500 constant */
    /* @3910504 cmp */
    /* @3910508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3910524;
    /* @3910512 constant */
    /* @3910516 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(45));
    L_3910524: ;
    /* @3910524 b */
    goto L_3910828;
    L_3910528: ;
    /* @3910528 load */
    /* @3910536 constant */
    /* @3910540 cmp */
    /* @3910544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3910680;
    /* @3910548 load */
    /* @3910556 constant */
    /* @3910560 cmp */
    /* @3910564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3910580;
    /* @3910568 constant */
    /* @3910572 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(70));
    L_3910580: ;
    /* @3910580 load */
    /* @3910588 constant */
    /* @3910592 cmp */
    /* @3910596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3910612;
    /* @3910600 constant */
    /* @3910604 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(65));
    L_3910612: ;
    /* @3910612 load */
    /* @3910620 constant */
    /* @3910624 cmp */
    /* @3910628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3910644;
    /* @3910632 constant */
    /* @3910636 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(60));
    L_3910644: ;
    /* @3910644 load */
    /* @3910652 constant */
    /* @3910656 cmp */
    /* @3910660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3910676;
    /* @3910664 constant */
    /* @3910668 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(55));
    L_3910676: ;
    /* @3910676 b */
    goto L_3910828;
    L_3910680: ;
    /* @3910680 load */
    /* @3910688 constant */
    /* @3910692 cmp */
    /* @3910696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3910828;
    /* @3910700 load */
    /* @3910708 constant */
    /* @3910712 cmp */
    /* @3910716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3910732;
    /* @3910720 constant */
    /* @3910724 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(80));
    L_3910732: ;
    /* @3910732 load */
    /* @3910740 constant */
    /* @3910744 cmp */
    /* @3910748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3910764;
    /* @3910752 constant */
    /* @3910756 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(75));
    L_3910764: ;
    /* @3910764 load */
    /* @3910772 constant */
    /* @3910776 cmp */
    /* @3910780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3910796;
    /* @3910784 constant */
    /* @3910788 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(70));
    L_3910796: ;
    /* @3910796 load */
    /* @3910804 constant */
    /* @3910808 cmp */
    /* @3910812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3910828;
    /* @3910816 constant */
    /* @3910820 store */
    GM_WRITE(vm, -1, "hpskeleton", VAL(65));
    L_3910828: ;
    return;
}
