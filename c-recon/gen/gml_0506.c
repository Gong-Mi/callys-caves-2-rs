/* generated from CODE 506 (gml_Object_obj_restoreiap_Draw_0), source start 4698060, end 4699820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0506(GmVM* vm) {
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
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    /* @4698060 load */
    /* @4698068 constant */
    /* @4698072 cmp */
    /* @4698076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4698300;
    /* @4698080 load */
    /* @4698088 load */
    /* @4698096 constant */
    /* @4698100 cast */
    /* @4698104 constant */
    /* @4698108 cast */
    /* @4698112 call */
    GM_SITE(vm, 506, 4698112);
    /* @4698120 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4698124 constant */
    /* @4698128 cast */
    /* @4698132 call */
    GM_SITE(vm, 506, 4698132);
    /* @4698140 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4698144 constant */
    /* @4698152 cast */
    /* @4698156 call */
    GM_SITE(vm, 506, 4698156);
    /* @4698164 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4698168 string */
    /* @4698176 cast */
    /* @4698180 load */
    /* @4698188 constant */
    /* @4698192 add */
    /* @4698196 load */
    /* @4698204 constant */
    /* @4698208 add */
    /* @4698212 call */
    GM_SITE(vm, 506, 4698212);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4698220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(996)));
    /* @4698224 load */
    /* @4698232 constant */
    /* @4698236 cmp */
    /* @4698240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4698300;
    /* @4698244 string */
    /* @4698252 cast */
    /* @4698256 load */
    /* @4698264 constant */
    /* @4698268 sub */
    /* @4698272 load */
    /* @4698280 constant */
    /* @4698284 add */
    /* @4698288 call */
    GM_SITE(vm, 506, 4698288);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4698296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4698300: ;
    /* @4698300 load */
    /* @4698308 constant */
    /* @4698312 cmp */
    /* @4698316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4698604;
    /* @4698320 constant */
    /* @4698324 constant */
    /* @4698328 load */
    /* @4698336 constant */
    /* @4698340 add */
    /* @4698344 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(30));
    GM_WRITE(vm, -1, "x", v4);
    /* @4698352 constant */
    /* @4698356 constant */
    /* @4698360 load */
    /* @4698368 constant */
    /* @4698372 add */
    /* @4698376 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    GM_WRITE(vm, -1, "y", v5);
    /* @4698384 load */
    /* @4698392 load */
    /* @4698400 constant */
    /* @4698404 cast */
    /* @4698408 constant */
    /* @4698412 cast */
    /* @4698416 call */
    GM_SITE(vm, 506, 4698416);
    /* @4698424 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4698428 constant */
    /* @4698432 cast */
    /* @4698436 call */
    GM_SITE(vm, 506, 4698436);
    /* @4698444 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4698448 constant */
    /* @4698456 cast */
    /* @4698460 call */
    GM_SITE(vm, 506, 4698460);
    /* @4698468 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4698472 string */
    /* @4698480 cast */
    /* @4698484 load */
    /* @4698492 constant */
    /* @4698496 add */
    /* @4698500 load */
    /* @4698508 constant */
    /* @4698512 add */
    /* @4698516 call */
    GM_SITE(vm, 506, 4698516);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4698524 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, v7, STR_REF(996)));
    /* @4698528 load */
    /* @4698536 constant */
    /* @4698540 cmp */
    /* @4698544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4698604;
    /* @4698548 string */
    /* @4698556 cast */
    /* @4698560 load */
    /* @4698568 constant */
    /* @4698572 sub */
    /* @4698576 load */
    /* @4698584 constant */
    /* @4698588 add */
    /* @4698592 call */
    GM_SITE(vm, 506, 4698592);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4698600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4698604: ;
    /* @4698604 load */
    /* @4698612 constant */
    /* @4698616 cmp */
    /* @4698620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4698908;
    /* @4698624 constant */
    /* @4698628 constant */
    /* @4698632 load */
    /* @4698640 constant */
    /* @4698644 add */
    /* @4698648 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(50));
    GM_WRITE(vm, -1, "x", v9);
    /* @4698656 constant */
    /* @4698660 constant */
    /* @4698664 load */
    /* @4698672 constant */
    /* @4698676 add */
    /* @4698680 store */
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "y", v10);
    /* @4698688 load */
    /* @4698696 load */
    /* @4698704 constant */
    /* @4698708 cast */
    /* @4698712 constant */
    /* @4698716 cast */
    /* @4698720 call */
    GM_SITE(vm, 506, 4698720);
    /* @4698728 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4698732 constant */
    /* @4698736 cast */
    /* @4698740 call */
    GM_SITE(vm, 506, 4698740);
    /* @4698748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4698752 constant */
    /* @4698760 cast */
    /* @4698764 call */
    GM_SITE(vm, 506, 4698764);
    /* @4698772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4698776 string */
    /* @4698784 cast */
    /* @4698788 load */
    /* @4698796 constant */
    /* @4698800 add */
    /* @4698804 load */
    /* @4698812 constant */
    /* @4698816 add */
    /* @4698820 call */
    GM_SITE(vm, 506, 4698820);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v12 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4698828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(996)));
    /* @4698832 load */
    /* @4698840 constant */
    /* @4698844 cmp */
    /* @4698848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4698908;
    /* @4698852 string */
    /* @4698860 cast */
    /* @4698864 load */
    /* @4698872 constant */
    /* @4698876 sub */
    /* @4698880 load */
    /* @4698888 constant */
    /* @4698892 add */
    /* @4698896 call */
    GM_SITE(vm, 506, 4698896);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4698904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4698908: ;
    /* @4698908 load */
    /* @4698916 constant */
    /* @4698920 cmp */
    /* @4698924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4699212;
    /* @4698928 constant */
    /* @4698932 constant */
    /* @4698936 load */
    /* @4698944 constant */
    /* @4698948 add */
    /* @4698952 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(50));
    GM_WRITE(vm, -1, "x", v14);
    /* @4698960 constant */
    /* @4698964 constant */
    /* @4698968 load */
    /* @4698976 constant */
    /* @4698980 add */
    /* @4698984 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "y", v15);
    /* @4698992 load */
    /* @4699000 load */
    /* @4699008 constant */
    /* @4699012 cast */
    /* @4699016 constant */
    /* @4699020 cast */
    /* @4699024 call */
    GM_SITE(vm, 506, 4699024);
    /* @4699032 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4699036 constant */
    /* @4699040 cast */
    /* @4699044 call */
    GM_SITE(vm, 506, 4699044);
    /* @4699052 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4699056 constant */
    /* @4699064 cast */
    /* @4699068 call */
    GM_SITE(vm, 506, 4699068);
    /* @4699076 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4699080 string */
    /* @4699088 cast */
    /* @4699092 load */
    /* @4699100 constant */
    /* @4699104 add */
    /* @4699108 load */
    /* @4699116 constant */
    /* @4699120 add */
    /* @4699124 call */
    GM_SITE(vm, 506, 4699124);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4699132 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(996)));
    /* @4699136 load */
    /* @4699144 constant */
    /* @4699148 cmp */
    /* @4699152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4699212;
    /* @4699156 string */
    /* @4699164 cast */
    /* @4699168 load */
    /* @4699176 constant */
    /* @4699180 sub */
    /* @4699184 load */
    /* @4699192 constant */
    /* @4699196 add */
    /* @4699200 call */
    GM_SITE(vm, 506, 4699200);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4699208 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4699212: ;
    /* @4699212 load */
    /* @4699220 constant */
    /* @4699224 cmp */
    /* @4699228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4699516;
    /* @4699232 constant */
    /* @4699236 constant */
    /* @4699240 load */
    /* @4699248 constant */
    /* @4699252 add */
    /* @4699256 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    GM_WRITE(vm, -1, "x", v19);
    /* @4699264 constant */
    /* @4699268 constant */
    /* @4699272 load */
    /* @4699280 constant */
    /* @4699284 add */
    /* @4699288 store */
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v20);
    /* @4699296 load */
    /* @4699304 load */
    /* @4699312 constant */
    /* @4699316 cast */
    /* @4699320 constant */
    /* @4699324 cast */
    /* @4699328 call */
    GM_SITE(vm, 506, 4699328);
    /* @4699336 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4699340 constant */
    /* @4699344 cast */
    /* @4699348 call */
    GM_SITE(vm, 506, 4699348);
    /* @4699356 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4699360 constant */
    /* @4699368 cast */
    /* @4699372 call */
    GM_SITE(vm, 506, 4699372);
    /* @4699380 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4699384 string */
    /* @4699392 cast */
    /* @4699396 load */
    /* @4699404 constant */
    /* @4699408 add */
    /* @4699412 load */
    /* @4699420 constant */
    /* @4699424 add */
    /* @4699428 call */
    GM_SITE(vm, 506, 4699428);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v22 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4699436 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, v22, STR_REF(996)));
    /* @4699440 load */
    /* @4699448 constant */
    /* @4699452 cmp */
    /* @4699456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4699516;
    /* @4699460 string */
    /* @4699468 cast */
    /* @4699472 load */
    /* @4699480 constant */
    /* @4699484 sub */
    /* @4699488 load */
    /* @4699496 constant */
    /* @4699500 add */
    /* @4699504 call */
    GM_SITE(vm, 506, 4699504);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4699512 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4699516: ;
    /* @4699516 load */
    /* @4699524 constant */
    /* @4699528 cmp */
    /* @4699532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4699820;
    /* @4699536 constant */
    /* @4699540 constant */
    /* @4699544 load */
    /* @4699552 constant */
    /* @4699556 add */
    /* @4699560 store */
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    GM_WRITE(vm, -1, "x", v24);
    /* @4699568 constant */
    /* @4699572 constant */
    /* @4699576 load */
    /* @4699584 constant */
    /* @4699588 add */
    /* @4699592 store */
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    GM_WRITE(vm, -1, "y", v25);
    /* @4699600 load */
    /* @4699608 load */
    /* @4699616 constant */
    /* @4699620 cast */
    /* @4699624 constant */
    /* @4699628 cast */
    /* @4699632 call */
    GM_SITE(vm, 506, 4699632);
    /* @4699640 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4699644 constant */
    /* @4699648 cast */
    /* @4699652 call */
    GM_SITE(vm, 506, 4699652);
    /* @4699660 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4699664 constant */
    /* @4699672 cast */
    /* @4699676 call */
    GM_SITE(vm, 506, 4699676);
    /* @4699684 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4699688 string */
    /* @4699696 cast */
    /* @4699700 load */
    /* @4699708 constant */
    /* @4699712 add */
    /* @4699716 load */
    /* @4699724 constant */
    /* @4699728 add */
    /* @4699732 call */
    GM_SITE(vm, 506, 4699732);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(5));
    /* @4699740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(996)));
    /* @4699744 load */
    /* @4699752 constant */
    /* @4699756 cmp */
    /* @4699760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpurchase") == VAL(1)))) goto L_4699820;
    /* @4699764 string */
    /* @4699772 cast */
    /* @4699776 load */
    /* @4699784 constant */
    /* @4699788 sub */
    /* @4699792 load */
    /* @4699800 constant */
    /* @4699804 add */
    /* @4699808 call */
    GM_SITE(vm, 506, 4699808);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4699816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v28, (GM_READ(vm, -1, "y") - VAL(25)), STR_REF(997)));
    L_4699820: ;
    return;
}
