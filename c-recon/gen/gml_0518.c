/* generated from CODE 518 (gml_Object_obj_pausebutton_Draw_0), source start 4714600, end 4715676. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0518(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    /* @4714600 load */
    /* @4714608 constant */
    /* @4714612 cmp */
    /* @4714616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4714776;
    /* @4714620 constant */
    /* @4714624 constant */
    /* @4714628 load */
    /* @4714636 constant */
    /* @4714640 add */
    /* @4714644 store */
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(320));
    GM_WRITE(vm, -1, "x", v1);
    /* @4714652 constant */
    /* @4714656 constant */
    /* @4714660 load */
    /* @4714668 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)));
    /* @4714676 constant */
    /* @4714680 cast */
    /* @4714684 constant */
    /* @4714688 cast */
    /* @4714692 constant */
    /* @4714696 cast */
    /* @4714700 constant */
    /* @4714712 cast */
    /* @4714716 constant */
    /* @4714728 cast */
    /* @4714732 load */
    /* @4714740 load */
    /* @4714748 constant */
    /* @4714752 cast */
    /* @4714756 constant */
    /* @4714760 cast */
    /* @4714764 call */
    GM_SITE(vm, 518, 4714764);
    /* @4714772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(122), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4714776: ;
    /* @4714776 load */
    /* @4714784 constant */
    /* @4714788 cmp */
    /* @4714792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4714952;
    /* @4714796 constant */
    /* @4714800 constant */
    /* @4714804 load */
    /* @4714812 constant */
    /* @4714816 add */
    /* @4714820 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(270));
    GM_WRITE(vm, -1, "x", v2);
    /* @4714828 constant */
    /* @4714832 constant */
    /* @4714836 load */
    /* @4714844 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)));
    /* @4714852 constant */
    /* @4714856 cast */
    /* @4714860 constant */
    /* @4714864 cast */
    /* @4714868 constant */
    /* @4714872 cast */
    /* @4714876 constant */
    /* @4714888 cast */
    /* @4714892 constant */
    /* @4714904 cast */
    /* @4714908 load */
    /* @4714916 load */
    /* @4714924 constant */
    /* @4714928 cast */
    /* @4714932 constant */
    /* @4714936 cast */
    /* @4714940 call */
    GM_SITE(vm, 518, 4714940);
    /* @4714948 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(122), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4714952: ;
    /* @4714952 load */
    /* @4714960 constant */
    /* @4714964 cmp */
    /* @4714968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4714972;
    L_4714972: ;
    /* @4714972 load */
    /* @4714980 constant */
    /* @4714984 cmp */
    /* @4714988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4715148;
    /* @4714992 constant */
    /* @4714996 constant */
    /* @4715000 load */
    /* @4715008 constant */
    /* @4715012 add */
    /* @4715016 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(340));
    GM_WRITE(vm, -1, "x", v3);
    /* @4715024 constant */
    /* @4715028 constant */
    /* @4715032 load */
    /* @4715040 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)));
    /* @4715048 constant */
    /* @4715052 cast */
    /* @4715056 constant */
    /* @4715060 cast */
    /* @4715064 constant */
    /* @4715068 cast */
    /* @4715072 constant */
    /* @4715084 cast */
    /* @4715088 constant */
    /* @4715100 cast */
    /* @4715104 load */
    /* @4715112 load */
    /* @4715120 constant */
    /* @4715124 cast */
    /* @4715128 constant */
    /* @4715132 cast */
    /* @4715136 call */
    GM_SITE(vm, 518, 4715136);
    /* @4715144 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(122), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4715148: ;
    /* @4715148 load */
    /* @4715156 constant */
    /* @4715160 cmp */
    /* @4715164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4715324;
    /* @4715168 constant */
    /* @4715172 constant */
    /* @4715176 load */
    /* @4715184 constant */
    /* @4715188 add */
    /* @4715192 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(340));
    GM_WRITE(vm, -1, "x", v4);
    /* @4715200 constant */
    /* @4715204 constant */
    /* @4715208 load */
    /* @4715216 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)));
    /* @4715224 constant */
    /* @4715228 cast */
    /* @4715232 constant */
    /* @4715236 cast */
    /* @4715240 constant */
    /* @4715244 cast */
    /* @4715248 constant */
    /* @4715260 cast */
    /* @4715264 constant */
    /* @4715276 cast */
    /* @4715280 load */
    /* @4715288 load */
    /* @4715296 constant */
    /* @4715300 cast */
    /* @4715304 constant */
    /* @4715308 cast */
    /* @4715312 call */
    GM_SITE(vm, 518, 4715312);
    /* @4715320 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(122), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4715324: ;
    /* @4715324 load */
    /* @4715332 constant */
    /* @4715336 cmp */
    /* @4715340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4715500;
    /* @4715344 constant */
    /* @4715348 constant */
    /* @4715352 load */
    /* @4715360 constant */
    /* @4715364 add */
    /* @4715368 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(320));
    GM_WRITE(vm, -1, "x", v5);
    /* @4715376 constant */
    /* @4715380 constant */
    /* @4715384 load */
    /* @4715392 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)));
    /* @4715400 constant */
    /* @4715404 cast */
    /* @4715408 constant */
    /* @4715412 cast */
    /* @4715416 constant */
    /* @4715420 cast */
    /* @4715424 constant */
    /* @4715436 cast */
    /* @4715440 constant */
    /* @4715452 cast */
    /* @4715456 load */
    /* @4715464 load */
    /* @4715472 constant */
    /* @4715476 cast */
    /* @4715480 constant */
    /* @4715484 cast */
    /* @4715488 call */
    GM_SITE(vm, 518, 4715488);
    /* @4715496 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(121), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4715500: ;
    /* @4715500 load */
    /* @4715508 constant */
    /* @4715512 cmp */
    /* @4715516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4715676;
    /* @4715520 constant */
    /* @4715524 constant */
    /* @4715528 load */
    /* @4715536 constant */
    /* @4715540 add */
    /* @4715544 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(350));
    GM_WRITE(vm, -1, "x", v6);
    /* @4715552 constant */
    /* @4715556 constant */
    /* @4715560 load */
    /* @4715568 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)));
    /* @4715576 constant */
    /* @4715580 cast */
    /* @4715584 constant */
    /* @4715588 cast */
    /* @4715592 constant */
    /* @4715596 cast */
    /* @4715600 constant */
    /* @4715612 cast */
    /* @4715616 constant */
    /* @4715628 cast */
    /* @4715632 load */
    /* @4715640 load */
    /* @4715648 constant */
    /* @4715652 cast */
    /* @4715656 constant */
    /* @4715660 cast */
    /* @4715664 call */
    GM_SITE(vm, 518, 4715664);
    /* @4715672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(122), VAL(0), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    L_4715676: ;
    return;
}
