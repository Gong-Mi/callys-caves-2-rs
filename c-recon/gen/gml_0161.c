/* generated from CODE 161 (gml_Object_obj_trex_Step_0), source start 3982416, end 3983164. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0161(GmVM* vm) {
    Val v1;
    Val v2;
    Val p3982800_0;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    /* @3982416 load */
    /* @3982424 constant */
    /* @3982428 cmp */
    /* @3982432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptrex") >= VAL(0)))) goto L_3982456;
    /* @3982436 constant */
    /* @3982440 constant */
    /* @3982444 constant */
    /* @3982448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3982456: ;
    /* @3982456 load */
    /* @3982464 constant */
    /* @3982468 cmp */
    /* @3982472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptrex") <= VAL(0)))) goto L_3982496;
    /* @3982476 constant */
    /* @3982480 constant */
    /* @3982484 constant */
    /* @3982488 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3982496: ;
    /* @3982496 constant */
    /* @3982500 constant */
    /* @3982504 load */
    /* @3982512 constant */
    /* @3982516 cmp */
    /* @3982520 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(1)) <= VAL(0)))) goto L_3982544;
    /* @3982524 constant */
    /* @3982528 constant */
    /* @3982532 constant */
    /* @3982536 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    L_3982544: ;
    /* @3982544 constant */
    /* @3982548 cast */
    /* @3982552 load */
    /* @3982560 constant */
    /* @3982564 add */
    /* @3982568 load */
    /* @3982576 call */
    GM_SITE(vm, 161, 3982576);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3982584 cast */
    /* @3982588 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3982632;
    /* @3982592 constant */
    /* @3982596 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3982604 constant */
    /* @3982608 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3982616 constant */
    /* @3982620 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3982628 b */
    goto L_3982664;
    L_3982632: ;
    /* @3982632 constant */
    /* @3982644 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3982652 constant */
    /* @3982656 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3982664: ;
    /* @3982664 load */
    /* @3982672 constant */
    /* @3982676 cmp */
    /* @3982680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3982708;
    /* @3982684 constant */
    /* @3982688 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-3));
    /* @3982696 constant */
    /* @3982700 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3982708: ;
    /* @3982708 load */
    /* @3982716 constant */
    /* @3982720 cmp */
    /* @3982724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3982752;
    /* @3982728 constant */
    /* @3982732 store */
    GM_WRITE(vm, -1, "hspeed", VAL(3));
    /* @3982740 constant */
    /* @3982744 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3982752: ;
    /* @3982752 load */
    /* @3982760 constant */
    /* @3982764 cmp */
    /* @3982768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "y") >= VAL(320)))) goto L_3982796;
    /* @3982772 load */
    /* @3982780 load */
    /* @3982788 cmp */
    /* @3982792 b */
    p3982800_0 = NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x"));
    goto L_3982800;
    L_3982796: ;
    /* @3982796 constant */
    p3982800_0 = VAL(0);
    L_3982800: ;
    /* @3982800 bf */
    if (!TRUTH(p3982800_0)) goto L_3982816;
    /* @3982804 constant */
    /* @3982808 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3982816: ;
    /* @3982816 constant */
    /* @3982820 cast */
    /* @3982824 load */
    /* @3982832 load */
    /* @3982840 constant */
    /* @3982844 add */
    /* @3982848 call */
    GM_SITE(vm, 161, 3982848);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3982856 cast */
    /* @3982860 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_3982896;
    /* @3982864 load */
    /* @3982872 constant */
    /* @3982876 cmp */
    /* @3982880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 34, "type") != VAL(2)))) goto L_3982896;
    /* @3982884 constant */
    /* @3982888 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3982896: ;
    /* @3982896 constant */
    /* @3982900 cast */
    /* @3982904 load */
    /* @3982912 load */
    /* @3982920 constant */
    /* @3982924 sub */
    /* @3982928 call */
    GM_SITE(vm, 161, 3982928);
    /* @3982936 cast */
    /* @3982940 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(30)), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v5)) goto L_3982976;
    /* @3982944 load */
    /* @3982952 constant */
    /* @3982956 cmp */
    /* @3982960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 34, "type") != VAL(2)))) goto L_3982976;
    /* @3982964 constant */
    /* @3982968 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3982976: ;
    /* @3982976 load */
    /* @3982984 constant */
    /* @3982988 cmp */
    /* @3982992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptrex") <= VAL(10)))) goto L_3983008;
    /* @3982996 constant */
    /* @3983000 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(55));
    L_3983008: ;
    /* @3983008 load */
    /* @3983016 constant */
    /* @3983020 cmp */
    /* @3983024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3983084;
    /* @3983028 constant */
    /* @3983032 cast */
    /* @3983036 constant */
    /* @3983040 cast */
    /* @3983044 call */
    GM_SITE(vm, 161, 3983044);
    /* @3983052 store */
    v6 = GM_CALL(vm, "choose", 2, VAL(55), VAL(56));
    GM_WRITE(vm, -1, "sprite_index", v6);
    /* @3983060 constant */
    /* @3983064 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3983072 constant */
    /* @3983076 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3983084: ;
    /* @3983084 load */
    /* @3983092 constant */
    /* @3983096 cmp */
    /* @3983100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3983120;
    /* @3983104 constant */
    /* @3983112 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3983120: ;
    /* @3983120 load */
    /* @3983128 constant */
    /* @3983132 cmp */
    /* @3983136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3983164;
    /* @3983140 constant */
    /* @3983144 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3983152 constant */
    /* @3983156 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3983164: ;
    return;
}
