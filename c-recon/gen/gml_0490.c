/* generated from CODE 490 (gml_Object_obj_storepageswitch_Draw_0), source start 4678216, end 4679744. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0490(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    /* @4678216 load */
    /* @4678224 constant */
    /* @4678228 cmp */
    /* @4678232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4678444;
    /* @4678236 constant */
    /* @4678240 cast */
    /* @4678244 constant */
    /* @4678248 cast */
    /* @4678252 constant */
    /* @4678256 cast */
    /* @4678260 constant */
    /* @4678264 cast */
    /* @4678268 constant */
    /* @4678272 cast */
    /* @4678276 constant */
    /* @4678280 constant */
    /* @4678284 load */
    /* @4678292 constant */
    /* @4678296 add */
    /* @4678300 constant */
    /* @4678304 constant */
    /* @4678308 load */
    /* @4678316 constant */
    /* @4678320 add */
    /* @4678324 constant */
    /* @4678328 cast */
    /* @4678332 constant */
    /* @4678336 cast */
    /* @4678340 call */
    GM_SITE(vm, 490, 4678340);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4678348 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), v1, v2, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4678352 constant */
    /* @4678356 cast */
    /* @4678360 call */
    GM_SITE(vm, 490, 4678360);
    /* @4678368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4678372 constant */
    /* @4678380 cast */
    /* @4678384 call */
    GM_SITE(vm, 490, 4678384);
    /* @4678392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4678396 string */
    /* @4678404 cast */
    /* @4678408 load */
    /* @4678416 load */
    /* @4678424 constant */
    /* @4678428 add */
    /* @4678432 call */
    GM_SITE(vm, 490, 4678432);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4678440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4678444: ;
    /* @4678444 load */
    /* @4678452 constant */
    /* @4678456 cmp */
    /* @4678460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4678720;
    /* @4678464 constant */
    /* @4678468 constant */
    /* @4678472 load */
    /* @4678480 constant */
    /* @4678484 add */
    /* @4678488 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    GM_WRITE(vm, -1, "x", v4);
    /* @4678496 constant */
    /* @4678500 constant */
    /* @4678504 load */
    /* @4678512 constant */
    /* @4678516 add */
    /* @4678520 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "y", v5);
    /* @4678528 constant */
    /* @4678532 cast */
    /* @4678536 constant */
    /* @4678540 cast */
    /* @4678544 constant */
    /* @4678548 cast */
    /* @4678552 constant */
    /* @4678564 cast */
    /* @4678568 constant */
    /* @4678580 cast */
    /* @4678584 load */
    /* @4678592 load */
    /* @4678600 constant */
    /* @4678604 cast */
    /* @4678608 constant */
    /* @4678612 cast */
    /* @4678616 call */
    GM_SITE(vm, 490, 4678616);
    /* @4678624 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4678628 constant */
    /* @4678632 cast */
    /* @4678636 call */
    GM_SITE(vm, 490, 4678636);
    /* @4678644 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4678648 constant */
    /* @4678656 cast */
    /* @4678660 call */
    GM_SITE(vm, 490, 4678660);
    /* @4678668 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4678672 string */
    /* @4678680 cast */
    /* @4678684 load */
    /* @4678692 load */
    /* @4678700 constant */
    /* @4678704 add */
    /* @4678708 call */
    GM_SITE(vm, 490, 4678708);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4678716 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4678720: ;
    /* @4678720 load */
    /* @4678728 constant */
    /* @4678732 cmp */
    /* @4678736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4678940;
    /* @4678740 constant */
    /* @4678744 constant */
    /* @4678748 load */
    /* @4678756 constant */
    /* @4678760 add */
    /* @4678764 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(170));
    GM_WRITE(vm, -1, "x", v7);
    /* @4678772 constant */
    /* @4678776 constant */
    /* @4678780 load */
    /* @4678788 constant */
    /* @4678792 add */
    /* @4678796 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "y", v8);
    /* @4678804 load */
    /* @4678812 load */
    /* @4678820 constant */
    /* @4678824 cast */
    /* @4678828 constant */
    /* @4678832 cast */
    /* @4678836 call */
    GM_SITE(vm, 490, 4678836);
    /* @4678844 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4678848 constant */
    /* @4678852 cast */
    /* @4678856 call */
    GM_SITE(vm, 490, 4678856);
    /* @4678864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4678868 constant */
    /* @4678876 cast */
    /* @4678880 call */
    GM_SITE(vm, 490, 4678880);
    /* @4678888 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4678892 string */
    /* @4678900 cast */
    /* @4678904 load */
    /* @4678912 load */
    /* @4678920 constant */
    /* @4678924 add */
    /* @4678928 call */
    GM_SITE(vm, 490, 4678928);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(13));
    /* @4678936 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v9, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4678940: ;
    /* @4678940 load */
    /* @4678948 constant */
    /* @4678952 cmp */
    /* @4678956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4679160;
    /* @4678960 constant */
    /* @4678964 constant */
    /* @4678968 load */
    /* @4678976 constant */
    /* @4678980 add */
    /* @4678984 store */
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(170));
    GM_WRITE(vm, -1, "x", v10);
    /* @4678992 constant */
    /* @4678996 constant */
    /* @4679000 load */
    /* @4679008 constant */
    /* @4679012 add */
    /* @4679016 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "y", v11);
    /* @4679024 load */
    /* @4679032 load */
    /* @4679040 constant */
    /* @4679044 cast */
    /* @4679048 constant */
    /* @4679052 cast */
    /* @4679056 call */
    GM_SITE(vm, 490, 4679056);
    /* @4679064 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4679068 constant */
    /* @4679072 cast */
    /* @4679076 call */
    GM_SITE(vm, 490, 4679076);
    /* @4679084 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4679088 constant */
    /* @4679096 cast */
    /* @4679100 call */
    GM_SITE(vm, 490, 4679100);
    /* @4679108 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4679112 string */
    /* @4679120 cast */
    /* @4679124 load */
    /* @4679132 load */
    /* @4679140 constant */
    /* @4679144 add */
    /* @4679148 call */
    GM_SITE(vm, 490, 4679148);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(13));
    /* @4679156 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v12, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4679160: ;
    /* @4679160 load */
    /* @4679168 constant */
    /* @4679172 cmp */
    /* @4679176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4679452;
    /* @4679180 constant */
    /* @4679184 constant */
    /* @4679188 load */
    /* @4679196 constant */
    /* @4679200 add */
    /* @4679204 store */
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    GM_WRITE(vm, -1, "x", v13);
    /* @4679212 constant */
    /* @4679216 constant */
    /* @4679220 load */
    /* @4679228 constant */
    /* @4679232 add */
    /* @4679236 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v14);
    /* @4679244 constant */
    /* @4679248 cast */
    /* @4679252 constant */
    /* @4679256 cast */
    /* @4679260 constant */
    /* @4679264 cast */
    /* @4679268 constant */
    /* @4679272 cast */
    /* @4679276 constant */
    /* @4679280 cast */
    /* @4679284 constant */
    /* @4679288 constant */
    /* @4679292 load */
    /* @4679300 constant */
    /* @4679304 add */
    /* @4679308 constant */
    /* @4679312 constant */
    /* @4679316 load */
    /* @4679324 constant */
    /* @4679328 add */
    /* @4679332 constant */
    /* @4679336 cast */
    /* @4679340 constant */
    /* @4679344 cast */
    /* @4679348 call */
    GM_SITE(vm, 490, 4679348);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4679356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), v15, v16, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4679360 constant */
    /* @4679364 cast */
    /* @4679368 call */
    GM_SITE(vm, 490, 4679368);
    /* @4679376 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4679380 constant */
    /* @4679388 cast */
    /* @4679392 call */
    GM_SITE(vm, 490, 4679392);
    /* @4679400 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4679404 string */
    /* @4679412 cast */
    /* @4679416 load */
    /* @4679424 load */
    /* @4679432 constant */
    /* @4679436 add */
    /* @4679440 call */
    GM_SITE(vm, 490, 4679440);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4679448 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4679452: ;
    /* @4679452 load */
    /* @4679460 constant */
    /* @4679464 cmp */
    /* @4679468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4679744;
    /* @4679472 constant */
    /* @4679476 constant */
    /* @4679480 load */
    /* @4679488 constant */
    /* @4679492 add */
    /* @4679496 store */
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(150));
    GM_WRITE(vm, -1, "x", v18);
    /* @4679504 constant */
    /* @4679508 constant */
    /* @4679512 load */
    /* @4679520 constant */
    /* @4679524 add */
    /* @4679528 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    GM_WRITE(vm, -1, "y", v19);
    /* @4679536 constant */
    /* @4679540 cast */
    /* @4679544 constant */
    /* @4679548 cast */
    /* @4679552 constant */
    /* @4679556 cast */
    /* @4679560 constant */
    /* @4679564 cast */
    /* @4679568 constant */
    /* @4679572 cast */
    /* @4679576 constant */
    /* @4679580 constant */
    /* @4679584 load */
    /* @4679592 constant */
    /* @4679596 add */
    /* @4679600 constant */
    /* @4679604 constant */
    /* @4679608 load */
    /* @4679616 constant */
    /* @4679620 add */
    /* @4679624 constant */
    /* @4679628 cast */
    /* @4679632 constant */
    /* @4679636 cast */
    /* @4679640 call */
    GM_SITE(vm, 490, 4679640);
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(150));
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    /* @4679648 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4679652 constant */
    /* @4679656 cast */
    /* @4679660 call */
    GM_SITE(vm, 490, 4679660);
    /* @4679668 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4679672 constant */
    /* @4679680 cast */
    /* @4679684 call */
    GM_SITE(vm, 490, 4679684);
    /* @4679692 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4679696 string */
    /* @4679704 cast */
    /* @4679708 load */
    /* @4679716 load */
    /* @4679724 constant */
    /* @4679728 add */
    /* @4679732 call */
    GM_SITE(vm, 490, 4679732);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4679740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v22, GM_READ(vm, -1, "y"), STR_REF(874)));
    L_4679744: ;
    return;
}
