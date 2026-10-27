/* generated from CODE 91 (gml_Object_obj_zombie_Create_0), source start 3926308, end 3927048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0091(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @3926308 constant */
    /* @3926312 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3926320 constant */
    /* @3926324 cast */
    /* @3926328 constant */
    /* @3926332 cast */
    /* @3926336 call */
    GM_SITE(vm, 91, 3926336);
    /* @3926344 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(109), VAL(107));
    GM_WRITE(vm, -1, "zombiesprite", v1);
    /* @3926352 load */
    /* @3926360 store */
    GM_WRITE(vm, -1, "sprite_index", GM_READ(vm, -1, "zombiesprite"));
    /* @3926368 constant */
    /* @3926372 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3926380 constant */
    /* @3926384 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3926392 constant */
    /* @3926396 cast */
    /* @3926400 constant */
    /* @3926404 cast */
    /* @3926408 constant */
    /* @3926412 cast */
    /* @3926416 constant */
    /* @3926420 cast */
    /* @3926424 constant */
    /* @3926428 cast */
    /* @3926432 call */
    GM_SITE(vm, 91, 3926432);
    /* @3926440 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v2);
    /* @3926448 constant */
    /* @3926452 cast */
    /* @3926456 constant */
    /* @3926460 cast */
    /* @3926464 constant */
    /* @3926468 cast */
    /* @3926472 constant */
    /* @3926476 cast */
    /* @3926480 constant */
    /* @3926484 cast */
    /* @3926488 constant */
    /* @3926492 cast */
    /* @3926496 call */
    GM_SITE(vm, 91, 3926496);
    /* @3926504 store */
    v3 = GM_CALL(vm, "choose", 6, VAL(0), VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v3);
    /* @3926512 constant */
    /* @3926516 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3926524 constant */
    /* @3926528 store */
    GM_WRITE(vm, -1, "chasing", VAL(0));
    /* @3926536 constant */
    /* @3926540 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3926548 constant */
    /* @3926552 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3926560 constant */
    /* @3926564 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3926572 constant */
    /* @3926576 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3926584 constant */
    /* @3926588 store */
    GM_WRITE(vm, -1, "hpzombiefrozen", VAL(0));
    /* @3926596 load */
    /* @3926604 constant */
    /* @3926608 cmp */
    /* @3926612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3926748;
    /* @3926616 load */
    /* @3926624 constant */
    /* @3926628 cmp */
    /* @3926632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3926648;
    /* @3926636 constant */
    /* @3926640 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(60));
    L_3926648: ;
    /* @3926648 load */
    /* @3926656 constant */
    /* @3926660 cmp */
    /* @3926664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3926680;
    /* @3926668 constant */
    /* @3926672 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(56));
    L_3926680: ;
    /* @3926680 load */
    /* @3926688 constant */
    /* @3926692 cmp */
    /* @3926696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3926712;
    /* @3926700 constant */
    /* @3926704 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(52));
    L_3926712: ;
    /* @3926712 load */
    /* @3926720 constant */
    /* @3926724 cmp */
    /* @3926728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3926744;
    /* @3926732 constant */
    /* @3926736 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(45));
    L_3926744: ;
    /* @3926744 b */
    goto L_3927048;
    L_3926748: ;
    /* @3926748 load */
    /* @3926756 constant */
    /* @3926760 cmp */
    /* @3926764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3926900;
    /* @3926768 load */
    /* @3926776 constant */
    /* @3926780 cmp */
    /* @3926784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3926800;
    /* @3926788 constant */
    /* @3926792 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(70));
    L_3926800: ;
    /* @3926800 load */
    /* @3926808 constant */
    /* @3926812 cmp */
    /* @3926816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3926832;
    /* @3926820 constant */
    /* @3926824 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(65));
    L_3926832: ;
    /* @3926832 load */
    /* @3926840 constant */
    /* @3926844 cmp */
    /* @3926848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3926864;
    /* @3926852 constant */
    /* @3926856 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(60));
    L_3926864: ;
    /* @3926864 load */
    /* @3926872 constant */
    /* @3926876 cmp */
    /* @3926880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3926896;
    /* @3926884 constant */
    /* @3926888 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(54));
    L_3926896: ;
    /* @3926896 b */
    goto L_3927048;
    L_3926900: ;
    /* @3926900 load */
    /* @3926908 constant */
    /* @3926912 cmp */
    /* @3926916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3927048;
    /* @3926920 load */
    /* @3926928 constant */
    /* @3926932 cmp */
    /* @3926936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3926952;
    /* @3926940 constant */
    /* @3926944 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(80));
    L_3926952: ;
    /* @3926952 load */
    /* @3926960 constant */
    /* @3926964 cmp */
    /* @3926968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3926984;
    /* @3926972 constant */
    /* @3926976 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(70));
    L_3926984: ;
    /* @3926984 load */
    /* @3926992 constant */
    /* @3926996 cmp */
    /* @3927000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3927016;
    /* @3927004 constant */
    /* @3927008 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(65));
    L_3927016: ;
    /* @3927016 load */
    /* @3927024 constant */
    /* @3927028 cmp */
    /* @3927032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3927048;
    /* @3927036 constant */
    /* @3927040 store */
    GM_WRITE(vm, -1, "hpzombie", VAL(60));
    L_3927048: ;
    return;
}
