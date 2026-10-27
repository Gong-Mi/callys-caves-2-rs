/* generated from CODE 482 (gml_Object_obj_norestoredata_Draw_0), source start 4674116, end 4675500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0482(GmVM* vm) {
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
    /* @4674116 load */
    /* @4674124 constant */
    /* @4674128 cmp */
    /* @4674132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4674336;
    /* @4674136 constant */
    /* @4674140 constant */
    /* @4674144 load */
    /* @4674152 constant */
    /* @4674156 add */
    /* @4674160 store */
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(180));
    GM_WRITE(vm, -1, "x", v1);
    /* @4674168 constant */
    /* @4674172 constant */
    /* @4674176 load */
    /* @4674184 constant */
    /* @4674188 add */
    /* @4674192 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(155));
    GM_WRITE(vm, -1, "y", v2);
    /* @4674200 load */
    /* @4674208 load */
    /* @4674216 constant */
    /* @4674220 cast */
    /* @4674224 constant */
    /* @4674228 cast */
    /* @4674232 call */
    GM_SITE(vm, 482, 4674232);
    /* @4674240 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4674244 constant */
    /* @4674248 cast */
    /* @4674252 call */
    GM_SITE(vm, 482, 4674252);
    /* @4674260 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4674264 constant */
    /* @4674272 cast */
    /* @4674276 call */
    GM_SITE(vm, 482, 4674276);
    /* @4674284 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4674288 string */
    /* @4674296 cast */
    /* @4674300 load */
    /* @4674308 load */
    /* @4674316 constant */
    /* @4674320 add */
    /* @4674324 call */
    GM_SITE(vm, 482, 4674324);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(46));
    /* @4674332 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, GM_READ(vm, -1, "y"), STR_REF(870)));
    L_4674336: ;
    /* @4674336 load */
    /* @4674344 constant */
    /* @4674348 cmp */
    /* @4674352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4674620;
    /* @4674356 constant */
    /* @4674360 constant */
    /* @4674364 load */
    /* @4674372 constant */
    /* @4674376 add */
    /* @4674380 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(200));
    GM_WRITE(vm, -1, "x", v4);
    /* @4674388 constant */
    /* @4674392 constant */
    /* @4674396 load */
    /* @4674404 constant */
    /* @4674408 add */
    /* @4674412 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    GM_WRITE(vm, -1, "y", v5);
    /* @4674420 constant */
    /* @4674424 cast */
    /* @4674428 constant */
    /* @4674432 cast */
    /* @4674436 constant */
    /* @4674440 cast */
    /* @4674444 constant */
    /* @4674456 cast */
    /* @4674460 constant */
    /* @4674472 cast */
    /* @4674476 load */
    /* @4674484 load */
    /* @4674492 constant */
    /* @4674496 cast */
    /* @4674500 constant */
    /* @4674504 cast */
    /* @4674508 call */
    GM_SITE(vm, 482, 4674508);
    /* @4674516 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4674520 constant */
    /* @4674524 cast */
    /* @4674528 call */
    GM_SITE(vm, 482, 4674528);
    /* @4674536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4674540 constant */
    /* @4674548 cast */
    /* @4674552 call */
    GM_SITE(vm, 482, 4674552);
    /* @4674560 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4674564 string */
    /* @4674572 cast */
    /* @4674576 load */
    /* @4674584 constant */
    /* @4674588 add */
    /* @4674592 load */
    /* @4674600 constant */
    /* @4674604 add */
    /* @4674608 call */
    GM_SITE(vm, 482, 4674608);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4674616 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, v7, STR_REF(870)));
    L_4674620: ;
    /* @4674620 load */
    /* @4674628 constant */
    /* @4674632 cmp */
    /* @4674636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4674840;
    /* @4674640 constant */
    /* @4674644 constant */
    /* @4674648 load */
    /* @4674656 constant */
    /* @4674660 add */
    /* @4674664 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v8);
    /* @4674672 constant */
    /* @4674676 constant */
    /* @4674680 load */
    /* @4674688 constant */
    /* @4674692 add */
    /* @4674696 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(240));
    GM_WRITE(vm, -1, "y", v9);
    /* @4674704 load */
    /* @4674712 load */
    /* @4674720 constant */
    /* @4674724 cast */
    /* @4674728 constant */
    /* @4674732 cast */
    /* @4674736 call */
    GM_SITE(vm, 482, 4674736);
    /* @4674744 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4674748 constant */
    /* @4674752 cast */
    /* @4674756 call */
    GM_SITE(vm, 482, 4674756);
    /* @4674764 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4674768 constant */
    /* @4674776 cast */
    /* @4674780 call */
    GM_SITE(vm, 482, 4674780);
    /* @4674788 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4674792 string */
    /* @4674800 cast */
    /* @4674804 load */
    /* @4674812 load */
    /* @4674820 constant */
    /* @4674824 add */
    /* @4674828 call */
    GM_SITE(vm, 482, 4674828);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(46));
    /* @4674836 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(870)));
    L_4674840: ;
    /* @4674840 load */
    /* @4674848 constant */
    /* @4674852 cmp */
    /* @4674856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4675060;
    /* @4674860 constant */
    /* @4674864 constant */
    /* @4674868 load */
    /* @4674876 constant */
    /* @4674880 add */
    /* @4674884 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v11);
    /* @4674892 constant */
    /* @4674896 constant */
    /* @4674900 load */
    /* @4674908 constant */
    /* @4674912 add */
    /* @4674916 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(240));
    GM_WRITE(vm, -1, "y", v12);
    /* @4674924 load */
    /* @4674932 load */
    /* @4674940 constant */
    /* @4674944 cast */
    /* @4674948 constant */
    /* @4674952 cast */
    /* @4674956 call */
    GM_SITE(vm, 482, 4674956);
    /* @4674964 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4674968 constant */
    /* @4674972 cast */
    /* @4674976 call */
    GM_SITE(vm, 482, 4674976);
    /* @4674984 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4674988 constant */
    /* @4674996 cast */
    /* @4675000 call */
    GM_SITE(vm, 482, 4675000);
    /* @4675008 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4675012 string */
    /* @4675020 cast */
    /* @4675024 load */
    /* @4675032 load */
    /* @4675040 constant */
    /* @4675044 add */
    /* @4675048 call */
    GM_SITE(vm, 482, 4675048);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(46));
    /* @4675056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(870)));
    L_4675060: ;
    /* @4675060 load */
    /* @4675068 constant */
    /* @4675072 cmp */
    /* @4675076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4675280;
    /* @4675080 constant */
    /* @4675084 constant */
    /* @4675088 load */
    /* @4675096 constant */
    /* @4675100 add */
    /* @4675104 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(180));
    GM_WRITE(vm, -1, "x", v14);
    /* @4675112 constant */
    /* @4675116 constant */
    /* @4675120 load */
    /* @4675128 constant */
    /* @4675132 add */
    /* @4675136 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(155));
    GM_WRITE(vm, -1, "y", v15);
    /* @4675144 load */
    /* @4675152 load */
    /* @4675160 constant */
    /* @4675164 cast */
    /* @4675168 constant */
    /* @4675172 cast */
    /* @4675176 call */
    GM_SITE(vm, 482, 4675176);
    /* @4675184 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4675188 constant */
    /* @4675192 cast */
    /* @4675196 call */
    GM_SITE(vm, 482, 4675196);
    /* @4675204 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4675208 constant */
    /* @4675216 cast */
    /* @4675220 call */
    GM_SITE(vm, 482, 4675220);
    /* @4675228 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4675232 string */
    /* @4675240 cast */
    /* @4675244 load */
    /* @4675252 load */
    /* @4675260 constant */
    /* @4675264 add */
    /* @4675268 call */
    GM_SITE(vm, 482, 4675268);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(46));
    /* @4675276 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(870)));
    L_4675280: ;
    /* @4675280 load */
    /* @4675288 constant */
    /* @4675292 cmp */
    /* @4675296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4675500;
    /* @4675300 constant */
    /* @4675304 constant */
    /* @4675308 load */
    /* @4675316 constant */
    /* @4675320 add */
    /* @4675324 store */
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(180));
    GM_WRITE(vm, -1, "x", v17);
    /* @4675332 constant */
    /* @4675336 constant */
    /* @4675340 load */
    /* @4675348 constant */
    /* @4675352 add */
    /* @4675356 store */
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(155));
    GM_WRITE(vm, -1, "y", v18);
    /* @4675364 load */
    /* @4675372 load */
    /* @4675380 constant */
    /* @4675384 cast */
    /* @4675388 constant */
    /* @4675392 cast */
    /* @4675396 call */
    GM_SITE(vm, 482, 4675396);
    /* @4675404 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4675408 constant */
    /* @4675412 cast */
    /* @4675416 call */
    GM_SITE(vm, 482, 4675416);
    /* @4675424 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4675428 constant */
    /* @4675436 cast */
    /* @4675440 call */
    GM_SITE(vm, 482, 4675440);
    /* @4675448 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4675452 string */
    /* @4675460 cast */
    /* @4675464 load */
    /* @4675472 load */
    /* @4675480 constant */
    /* @4675484 add */
    /* @4675488 call */
    GM_SITE(vm, 482, 4675488);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(46));
    /* @4675496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v19, GM_READ(vm, -1, "y"), STR_REF(870)));
    L_4675500: ;
    return;
}
