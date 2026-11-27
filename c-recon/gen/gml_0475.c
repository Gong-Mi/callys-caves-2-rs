/* generated from CODE 475 (gml_Object_obj_store_Draw_0), source start 4651364, end 4652652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0475(GmVM* vm) {
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
    /* @4651364 load */
    /* @4651372 constant */
    /* @4651376 cmp */
    /* @4651380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4651536;
    /* @4651384 constant */
    /* @4651388 cast */
    /* @4651392 constant */
    /* @4651396 cast */
    /* @4651400 constant */
    /* @4651404 cast */
    /* @4651408 constant */
    /* @4651412 cast */
    /* @4651416 constant */
    /* @4651420 cast */
    /* @4651424 load */
    /* @4651432 load */
    /* @4651440 constant */
    /* @4651444 cast */
    /* @4651448 constant */
    /* @4651452 cast */
    /* @4651456 call */
    GM_SITE(vm, 475, 4651456);
    /* @4651464 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4651468 constant */
    /* @4651472 cast */
    /* @4651476 call */
    GM_SITE(vm, 475, 4651476);
    /* @4651484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4651488 string */
    /* @4651496 cast */
    /* @4651500 load */
    /* @4651508 load */
    /* @4651516 constant */
    /* @4651520 add */
    /* @4651524 call */
    GM_SITE(vm, 475, 4651524);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(37));
    /* @4651532 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4651536: ;
    /* @4651536 load */
    /* @4651544 constant */
    /* @4651548 cmp */
    /* @4651552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4651788;
    /* @4651556 constant */
    /* @4651560 constant */
    /* @4651564 load */
    /* @4651572 constant */
    /* @4651576 add */
    /* @4651580 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(202));
    GM_WRITE(vm, -1, "x", v2);
    /* @4651588 constant */
    /* @4651592 constant */
    /* @4651596 load */
    /* @4651604 constant */
    /* @4651608 add */
    /* @4651612 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(80));
    GM_WRITE(vm, -1, "y", v3);
    /* @4651620 constant */
    /* @4651624 cast */
    /* @4651628 constant */
    /* @4651632 cast */
    /* @4651636 constant */
    /* @4651640 cast */
    /* @4651644 constant */
    /* @4651656 cast */
    /* @4651660 constant */
    /* @4651672 cast */
    /* @4651676 load */
    /* @4651684 load */
    /* @4651692 constant */
    /* @4651696 cast */
    /* @4651700 constant */
    /* @4651704 cast */
    /* @4651708 call */
    GM_SITE(vm, 475, 4651708);
    /* @4651716 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4651720 constant */
    /* @4651724 cast */
    /* @4651728 call */
    GM_SITE(vm, 475, 4651728);
    /* @4651736 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4651740 string */
    /* @4651748 cast */
    /* @4651752 load */
    /* @4651760 load */
    /* @4651768 constant */
    /* @4651772 add */
    /* @4651776 call */
    GM_SITE(vm, 475, 4651776);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    /* @4651784 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4651788: ;
    /* @4651788 load */
    /* @4651796 constant */
    /* @4651800 cmp */
    /* @4651804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4651984;
    /* @4651808 constant */
    /* @4651812 constant */
    /* @4651816 load */
    /* @4651824 constant */
    /* @4651828 add */
    /* @4651832 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(190));
    GM_WRITE(vm, -1, "x", v5);
    /* @4651840 constant */
    /* @4651844 constant */
    /* @4651848 load */
    /* @4651856 constant */
    /* @4651860 add */
    /* @4651864 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(150));
    GM_WRITE(vm, -1, "y", v6);
    /* @4651872 load */
    /* @4651880 load */
    /* @4651888 constant */
    /* @4651892 cast */
    /* @4651896 constant */
    /* @4651900 cast */
    /* @4651904 call */
    GM_SITE(vm, 475, 4651904);
    /* @4651912 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4651916 constant */
    /* @4651920 cast */
    /* @4651924 call */
    GM_SITE(vm, 475, 4651924);
    /* @4651932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4651936 string */
    /* @4651944 cast */
    /* @4651948 load */
    /* @4651956 load */
    /* @4651964 constant */
    /* @4651968 add */
    /* @4651972 call */
    GM_SITE(vm, 475, 4651972);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(38));
    /* @4651980 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4651984: ;
    /* @4651984 load */
    /* @4651992 constant */
    /* @4651996 cmp */
    /* @4652000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4652180;
    /* @4652004 constant */
    /* @4652008 constant */
    /* @4652012 load */
    /* @4652020 constant */
    /* @4652024 add */
    /* @4652028 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(190));
    GM_WRITE(vm, -1, "x", v8);
    /* @4652036 constant */
    /* @4652040 constant */
    /* @4652044 load */
    /* @4652052 constant */
    /* @4652056 add */
    /* @4652060 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(150));
    GM_WRITE(vm, -1, "y", v9);
    /* @4652068 load */
    /* @4652076 load */
    /* @4652084 constant */
    /* @4652088 cast */
    /* @4652092 constant */
    /* @4652096 cast */
    /* @4652100 call */
    GM_SITE(vm, 475, 4652100);
    /* @4652108 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4652112 constant */
    /* @4652116 cast */
    /* @4652120 call */
    GM_SITE(vm, 475, 4652120);
    /* @4652128 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4652132 string */
    /* @4652140 cast */
    /* @4652144 load */
    /* @4652152 load */
    /* @4652160 constant */
    /* @4652164 add */
    /* @4652168 call */
    GM_SITE(vm, 475, 4652168);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(38));
    /* @4652176 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4652180: ;
    /* @4652180 load */
    /* @4652188 constant */
    /* @4652192 cmp */
    /* @4652196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4652416;
    /* @4652200 constant */
    /* @4652204 constant */
    /* @4652208 load */
    /* @4652216 constant */
    /* @4652220 add */
    /* @4652224 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    GM_WRITE(vm, -1, "x", v11);
    /* @4652232 constant */
    /* @4652236 constant */
    /* @4652240 load */
    /* @4652248 constant */
    /* @4652252 add */
    /* @4652256 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(60));
    GM_WRITE(vm, -1, "y", v12);
    /* @4652264 constant */
    /* @4652268 cast */
    /* @4652272 constant */
    /* @4652276 cast */
    /* @4652280 constant */
    /* @4652284 cast */
    /* @4652288 constant */
    /* @4652292 cast */
    /* @4652296 constant */
    /* @4652300 cast */
    /* @4652304 load */
    /* @4652312 load */
    /* @4652320 constant */
    /* @4652324 cast */
    /* @4652328 constant */
    /* @4652332 cast */
    /* @4652336 call */
    GM_SITE(vm, 475, 4652336);
    /* @4652344 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4652348 constant */
    /* @4652352 cast */
    /* @4652356 call */
    GM_SITE(vm, 475, 4652356);
    /* @4652364 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4652368 string */
    /* @4652376 cast */
    /* @4652380 load */
    /* @4652388 load */
    /* @4652396 constant */
    /* @4652400 add */
    /* @4652404 call */
    GM_SITE(vm, 475, 4652404);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(37));
    /* @4652412 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4652416: ;
    /* @4652416 load */
    /* @4652424 constant */
    /* @4652428 cmp */
    /* @4652432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4652652;
    /* @4652436 constant */
    /* @4652440 constant */
    /* @4652444 load */
    /* @4652452 constant */
    /* @4652456 add */
    /* @4652460 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    GM_WRITE(vm, -1, "x", v14);
    /* @4652468 constant */
    /* @4652472 constant */
    /* @4652476 load */
    /* @4652484 constant */
    /* @4652488 add */
    /* @4652492 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(60));
    GM_WRITE(vm, -1, "y", v15);
    /* @4652500 constant */
    /* @4652504 cast */
    /* @4652508 constant */
    /* @4652512 cast */
    /* @4652516 constant */
    /* @4652520 cast */
    /* @4652524 constant */
    /* @4652528 cast */
    /* @4652532 constant */
    /* @4652536 cast */
    /* @4652540 load */
    /* @4652548 load */
    /* @4652556 constant */
    /* @4652560 cast */
    /* @4652564 constant */
    /* @4652568 cast */
    /* @4652572 call */
    GM_SITE(vm, 475, 4652572);
    /* @4652580 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4652584 constant */
    /* @4652588 cast */
    /* @4652592 call */
    GM_SITE(vm, 475, 4652592);
    /* @4652600 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4652604 string */
    /* @4652612 cast */
    /* @4652616 load */
    /* @4652624 load */
    /* @4652632 constant */
    /* @4652636 add */
    /* @4652640 call */
    GM_SITE(vm, 475, 4652640);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(37));
    /* @4652648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(862)));
    L_4652652: ;
    return;
}
