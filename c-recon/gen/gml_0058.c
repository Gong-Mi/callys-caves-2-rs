/* generated from CODE 58 (gml_Object_obj_shooter1_Create_0), source start 3902280, end 3903132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0058(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3902280 constant */
    /* @3902284 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3902292 constant */
    /* @3902296 cast */
    /* @3902300 constant */
    /* @3902304 cast */
    /* @3902308 constant */
    /* @3902312 cast */
    /* @3902316 constant */
    /* @3902320 cast */
    /* @3902324 constant */
    /* @3902328 cast */
    /* @3902332 call */
    GM_SITE(vm, 58, 3902332);
    /* @3902340 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3902348 constant */
    /* @3902352 cast */
    /* @3902356 constant */
    /* @3902360 cast */
    /* @3902364 constant */
    /* @3902368 cast */
    /* @3902372 constant */
    /* @3902376 cast */
    /* @3902380 constant */
    /* @3902384 cast */
    /* @3902388 constant */
    /* @3902392 cast */
    /* @3902396 call */
    GM_SITE(vm, 58, 3902396);
    /* @3902404 store */
    v2 = GM_CALL(vm, "choose", 6, VAL(0), VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v2);
    /* @3902412 constant */
    /* @3902416 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3902424 constant */
    /* @3902428 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3902436 constant */
    /* @3902440 store */
    GM_WRITE(vm, -1, "stunned", VAL(0));
    /* @3902448 constant */
    /* @3902452 store */
    GM_WRITE(vm, -1, "enemy1hsp", VAL(0));
    /* @3902460 constant */
    /* @3902464 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3902472 constant */
    /* @3902476 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3902484 constant */
    /* @3902488 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3902496 constant */
    /* @3902500 store */
    GM_WRITE(vm, -1, "hpshooter1frozen", VAL(0));
    /* @3902508 constant */
    /* @3902512 constant */
    /* @3902516 constant */
    /* @3902520 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    /* @3902528 load */
    /* @3902536 constant */
    /* @3902540 cmp */
    /* @3902544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(5)))) goto L_3902680;
    /* @3902548 load */
    /* @3902556 constant */
    /* @3902560 cmp */
    /* @3902564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3902580;
    /* @3902568 constant */
    /* @3902572 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(35));
    L_3902580: ;
    /* @3902580 load */
    /* @3902588 constant */
    /* @3902592 cmp */
    /* @3902596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3902612;
    /* @3902600 constant */
    /* @3902604 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(33));
    L_3902612: ;
    /* @3902612 load */
    /* @3902620 constant */
    /* @3902624 cmp */
    /* @3902628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3902644;
    /* @3902632 constant */
    /* @3902636 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(31));
    L_3902644: ;
    /* @3902644 load */
    /* @3902652 constant */
    /* @3902656 cmp */
    /* @3902660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3902676;
    /* @3902664 constant */
    /* @3902668 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(28));
    L_3902676: ;
    /* @3902676 b */
    goto L_3903132;
    L_3902680: ;
    /* @3902680 load */
    /* @3902688 constant */
    /* @3902692 cmp */
    /* @3902696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(10)))) goto L_3902832;
    /* @3902700 load */
    /* @3902708 constant */
    /* @3902712 cmp */
    /* @3902716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3902732;
    /* @3902720 constant */
    /* @3902724 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(40));
    L_3902732: ;
    /* @3902732 load */
    /* @3902740 constant */
    /* @3902744 cmp */
    /* @3902748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3902764;
    /* @3902752 constant */
    /* @3902756 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(35));
    L_3902764: ;
    /* @3902764 load */
    /* @3902772 constant */
    /* @3902776 cmp */
    /* @3902780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3902796;
    /* @3902784 constant */
    /* @3902788 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(34));
    L_3902796: ;
    /* @3902796 load */
    /* @3902804 constant */
    /* @3902808 cmp */
    /* @3902812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3902828;
    /* @3902816 constant */
    /* @3902820 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(31));
    L_3902828: ;
    /* @3902828 b */
    goto L_3903132;
    L_3902832: ;
    /* @3902832 load */
    /* @3902840 constant */
    /* @3902844 cmp */
    /* @3902848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(15)))) goto L_3902984;
    /* @3902852 load */
    /* @3902860 constant */
    /* @3902864 cmp */
    /* @3902868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3902884;
    /* @3902872 constant */
    /* @3902876 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(50));
    L_3902884: ;
    /* @3902884 load */
    /* @3902892 constant */
    /* @3902896 cmp */
    /* @3902900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3902916;
    /* @3902904 constant */
    /* @3902908 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(45));
    L_3902916: ;
    /* @3902916 load */
    /* @3902924 constant */
    /* @3902928 cmp */
    /* @3902932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3902948;
    /* @3902936 constant */
    /* @3902940 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(40));
    L_3902948: ;
    /* @3902948 load */
    /* @3902956 constant */
    /* @3902960 cmp */
    /* @3902964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3902980;
    /* @3902968 constant */
    /* @3902972 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(38));
    L_3902980: ;
    /* @3902980 b */
    goto L_3903132;
    L_3902984: ;
    /* @3902984 load */
    /* @3902992 constant */
    /* @3902996 cmp */
    /* @3903000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_3903132;
    /* @3903004 load */
    /* @3903012 constant */
    /* @3903016 cmp */
    /* @3903020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3903036;
    /* @3903024 constant */
    /* @3903028 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(60));
    L_3903036: ;
    /* @3903036 load */
    /* @3903044 constant */
    /* @3903048 cmp */
    /* @3903052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3903068;
    /* @3903056 constant */
    /* @3903060 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(55));
    L_3903068: ;
    /* @3903068 load */
    /* @3903076 constant */
    /* @3903080 cmp */
    /* @3903084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3903100;
    /* @3903088 constant */
    /* @3903092 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(50));
    L_3903100: ;
    /* @3903100 load */
    /* @3903108 constant */
    /* @3903112 cmp */
    /* @3903116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3903132;
    /* @3903120 constant */
    /* @3903124 store */
    GM_WRITE(vm, -1, "hpshooter1", VAL(45));
    L_3903132: ;
    return;
}
