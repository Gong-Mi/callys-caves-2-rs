/* generated from CODE 516 (gml_Object_obj_IAPstore_Draw_0), source start 4713440, end 4714540. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0516(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    /* @4713440 load */
    /* @4713448 constant */
    /* @4713452 cmp */
    /* @4713456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4713616;
    /* @4713460 constant */
    /* @4713464 constant */
    /* @4713468 load */
    /* @4713476 constant */
    /* @4713480 add */
    /* @4713484 store */
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(315));
    GM_WRITE(vm, -1, "x", v1);
    /* @4713492 constant */
    /* @4713496 constant */
    /* @4713500 load */
    /* @4713508 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)));
    /* @4713516 constant */
    /* @4713520 cast */
    /* @4713524 constant */
    /* @4713528 cast */
    /* @4713532 constant */
    /* @4713536 cast */
    /* @4713540 constant */
    /* @4713552 cast */
    /* @4713556 constant */
    /* @4713568 cast */
    /* @4713572 load */
    /* @4713580 load */
    /* @4713588 constant */
    /* @4713592 cast */
    /* @4713596 constant */
    /* @4713600 cast */
    /* @4713604 call */
    GM_SITE(vm, 516, 4713604);
    /* @4713612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4713616: ;
    /* @4713616 load */
    /* @4713624 constant */
    /* @4713628 cmp */
    /* @4713632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4713800;
    /* @4713636 constant */
    /* @4713640 constant */
    /* @4713644 load */
    /* @4713652 constant */
    /* @4713656 add */
    /* @4713660 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(265));
    GM_WRITE(vm, -1, "x", v2);
    /* @4713668 constant */
    /* @4713672 constant */
    /* @4713676 load */
    /* @4713684 constant */
    /* @4713688 add */
    /* @4713692 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(1));
    GM_WRITE(vm, -1, "y", v3);
    /* @4713700 constant */
    /* @4713704 cast */
    /* @4713708 constant */
    /* @4713712 cast */
    /* @4713716 constant */
    /* @4713720 cast */
    /* @4713724 constant */
    /* @4713736 cast */
    /* @4713740 constant */
    /* @4713752 cast */
    /* @4713756 load */
    /* @4713764 load */
    /* @4713772 constant */
    /* @4713776 cast */
    /* @4713780 constant */
    /* @4713784 cast */
    /* @4713788 call */
    GM_SITE(vm, 516, 4713788);
    /* @4713796 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4713800: ;
    /* @4713800 load */
    /* @4713808 constant */
    /* @4713812 cmp */
    /* @4713816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4713820;
    L_4713820: ;
    /* @4713820 load */
    /* @4713828 constant */
    /* @4713832 cmp */
    /* @4713836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4714004;
    /* @4713840 constant */
    /* @4713844 constant */
    /* @4713848 load */
    /* @4713856 constant */
    /* @4713860 add */
    /* @4713864 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(340));
    GM_WRITE(vm, -1, "x", v4);
    /* @4713872 constant */
    /* @4713876 constant */
    /* @4713880 load */
    /* @4713888 constant */
    /* @4713892 add */
    /* @4713896 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1));
    GM_WRITE(vm, -1, "y", v5);
    /* @4713904 constant */
    /* @4713908 cast */
    /* @4713912 constant */
    /* @4713916 cast */
    /* @4713920 constant */
    /* @4713924 cast */
    /* @4713928 constant */
    /* @4713940 cast */
    /* @4713944 constant */
    /* @4713956 cast */
    /* @4713960 load */
    /* @4713968 load */
    /* @4713976 constant */
    /* @4713980 cast */
    /* @4713984 constant */
    /* @4713988 cast */
    /* @4713992 call */
    GM_SITE(vm, 516, 4713992);
    /* @4714000 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4714004: ;
    /* @4714004 load */
    /* @4714012 constant */
    /* @4714016 cmp */
    /* @4714020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4714188;
    /* @4714024 constant */
    /* @4714028 constant */
    /* @4714032 load */
    /* @4714040 constant */
    /* @4714044 add */
    /* @4714048 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(340));
    GM_WRITE(vm, -1, "x", v6);
    /* @4714056 constant */
    /* @4714060 constant */
    /* @4714064 load */
    /* @4714072 constant */
    /* @4714076 add */
    /* @4714080 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1));
    GM_WRITE(vm, -1, "y", v7);
    /* @4714088 constant */
    /* @4714092 cast */
    /* @4714096 constant */
    /* @4714100 cast */
    /* @4714104 constant */
    /* @4714108 cast */
    /* @4714112 constant */
    /* @4714124 cast */
    /* @4714128 constant */
    /* @4714140 cast */
    /* @4714144 load */
    /* @4714152 load */
    /* @4714160 constant */
    /* @4714164 cast */
    /* @4714168 constant */
    /* @4714172 cast */
    /* @4714176 call */
    GM_SITE(vm, 516, 4714176);
    /* @4714184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4714188: ;
    /* @4714188 load */
    /* @4714196 constant */
    /* @4714200 cmp */
    /* @4714204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4714364;
    /* @4714208 constant */
    /* @4714212 constant */
    /* @4714216 load */
    /* @4714224 constant */
    /* @4714228 add */
    /* @4714232 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(315));
    GM_WRITE(vm, -1, "x", v8);
    /* @4714240 constant */
    /* @4714244 constant */
    /* @4714248 load */
    /* @4714256 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)));
    /* @4714264 constant */
    /* @4714268 cast */
    /* @4714272 constant */
    /* @4714276 cast */
    /* @4714280 constant */
    /* @4714284 cast */
    /* @4714288 constant */
    /* @4714300 cast */
    /* @4714304 constant */
    /* @4714316 cast */
    /* @4714320 load */
    /* @4714328 load */
    /* @4714336 constant */
    /* @4714340 cast */
    /* @4714344 constant */
    /* @4714348 cast */
    /* @4714352 call */
    GM_SITE(vm, 516, 4714352);
    /* @4714360 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4714364: ;
    /* @4714364 load */
    /* @4714372 constant */
    /* @4714376 cmp */
    /* @4714380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4714540;
    /* @4714384 constant */
    /* @4714388 constant */
    /* @4714392 load */
    /* @4714400 constant */
    /* @4714404 add */
    /* @4714408 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(345));
    GM_WRITE(vm, -1, "x", v9);
    /* @4714416 constant */
    /* @4714420 constant */
    /* @4714424 load */
    /* @4714432 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)));
    /* @4714440 constant */
    /* @4714444 cast */
    /* @4714448 constant */
    /* @4714452 cast */
    /* @4714456 constant */
    /* @4714460 cast */
    /* @4714464 constant */
    /* @4714476 cast */
    /* @4714480 constant */
    /* @4714492 cast */
    /* @4714496 load */
    /* @4714504 load */
    /* @4714512 constant */
    /* @4714516 cast */
    /* @4714520 constant */
    /* @4714524 cast */
    /* @4714528 call */
    GM_SITE(vm, 516, 4714528);
    /* @4714536 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4714540: ;
    return;
}
