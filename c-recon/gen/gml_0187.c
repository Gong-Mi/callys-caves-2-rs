/* generated from CODE 187 (gml_Object_obj_boss4_Create_0), source start 4005448, end 4005884. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0187(GmVM* vm) {
    Val v1;
    /* @4005448 constant */
    /* @4005452 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4005460 constant */
    /* @4005464 store */
    GM_WRITE(vm, -1, "chasing", VAL(1));
    /* @4005472 constant */
    /* @4005476 constant */
    /* @4005480 constant */
    /* @4005484 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(60));
    /* @4005492 constant */
    /* @4005496 store */
    GM_WRITE(vm, -1, "movelock", VAL(0));
    /* @4005504 constant */
    /* @4005508 constant */
    /* @4005512 constant */
    /* @4005516 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(30));
    /* @4005524 constant */
    /* @4005528 store */
    GM_WRITE(vm, -1, "swinging", VAL(0));
    /* @4005536 constant */
    /* @4005540 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4005548 constant */
    /* @4005552 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4005560 constant */
    /* @4005564 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4005572 constant */
    /* @4005576 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @4005584 constant */
    /* @4005588 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @4005596 constant */
    /* @4005600 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4005608 constant */
    /* @4005612 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @4005620 constant */
    /* @4005624 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @4005632 constant */
    /* @4005636 constant */
    /* @4005640 constant */
    /* @4005644 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(90));
    /* @4005652 constant */
    /* @4005656 cast */
    /* @4005660 constant */
    /* @4005664 cast */
    /* @4005668 constant */
    /* @4005672 cast */
    /* @4005676 constant */
    /* @4005680 cast */
    /* @4005684 constant */
    /* @4005688 cast */
    /* @4005692 call */
    GM_SITE(vm, 187, 4005692);
    /* @4005700 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @4005708 load */
    /* @4005716 constant */
    /* @4005720 cmp */
    /* @4005724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4005752;
    /* @4005728 constant */
    /* @4005732 store */
    GM_WRITE(vm, -1, "hpboss4", VAL(950));
    /* @4005740 constant */
    /* @4005744 store */
    GM_WRITE(vm, -1, "boss4maxhp", VAL(950));
    L_4005752: ;
    /* @4005752 load */
    /* @4005760 constant */
    /* @4005764 cmp */
    /* @4005768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4005796;
    /* @4005772 constant */
    /* @4005776 store */
    GM_WRITE(vm, -1, "hpboss4", VAL(900));
    /* @4005784 constant */
    /* @4005788 store */
    GM_WRITE(vm, -1, "boss4maxhp", VAL(900));
    L_4005796: ;
    /* @4005796 load */
    /* @4005804 constant */
    /* @4005808 cmp */
    /* @4005812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4005840;
    /* @4005816 constant */
    /* @4005820 store */
    GM_WRITE(vm, -1, "hpboss4", VAL(825));
    /* @4005828 constant */
    /* @4005832 store */
    GM_WRITE(vm, -1, "boss4maxhp", VAL(825));
    L_4005840: ;
    /* @4005840 load */
    /* @4005848 constant */
    /* @4005852 cmp */
    /* @4005856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4005884;
    /* @4005860 constant */
    /* @4005864 store */
    GM_WRITE(vm, -1, "hpboss4", VAL(700));
    /* @4005872 constant */
    /* @4005876 store */
    GM_WRITE(vm, -1, "boss4maxhp", VAL(700));
    L_4005884: ;
    return;
}
