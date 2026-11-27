/* generated from CODE 497 (gml_Object_obj_firstpause_Draw_0), source start 4687664, end 4690904. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0497(GmVM* vm) {
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
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val v39;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    /* @4687664 load */
    /* @4687672 constant */
    /* @4687676 cmp */
    /* @4687680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4688204;
    /* @4687684 constant */
    /* @4687688 cast */
    /* @4687692 constant */
    /* @4687696 cast */
    /* @4687700 constant */
    /* @4687704 cast */
    /* @4687708 constant */
    /* @4687720 cast */
    /* @4687724 constant */
    /* @4687736 cast */
    /* @4687740 constant */
    /* @4687744 constant */
    /* @4687748 load */
    /* @4687756 constant */
    /* @4687760 constant */
    /* @4687764 load */
    /* @4687772 constant */
    /* @4687776 sub */
    /* @4687780 constant */
    /* @4687784 cast */
    /* @4687788 constant */
    /* @4687792 cast */
    /* @4687796 call */
    GM_SITE(vm, 497, 4687796);
    /* @4687804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4687808 constant */
    /* @4687812 cast */
    /* @4687816 call */
    GM_SITE(vm, 497, 4687816);
    /* @4687824 cast */
    /* @4687828 not */
    /* @4687832 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v1)) goto L_4688204;
    /* @4687836 constant */
    /* @4687844 cast */
    /* @4687848 call */
    GM_SITE(vm, 497, 4687848);
    /* @4687856 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4687860 constant */
    /* @4687864 cast */
    /* @4687868 call */
    GM_SITE(vm, 497, 4687868);
    /* @4687876 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4687880 constant */
    /* @4687884 cast */
    /* @4687888 constant */
    /* @4687892 cast */
    /* @4687896 constant */
    /* @4687900 cast */
    /* @4687904 constant */
    /* @4687908 cast */
    /* @4687912 constant */
    /* @4687916 cast */
    /* @4687920 constant */
    /* @4687924 constant */
    /* @4687928 load */
    /* @4687936 constant */
    /* @4687940 add */
    /* @4687944 constant */
    /* @4687948 constant */
    /* @4687952 load */
    /* @4687960 constant */
    /* @4687964 add */
    /* @4687968 constant */
    /* @4687972 cast */
    /* @4687976 constant */
    /* @4687980 cast */
    /* @4687984 call */
    GM_SITE(vm, 497, 4687984);
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(70));
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4687992 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v2, v3, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4687996 string */
    /* @4688004 cast */
    /* @4688008 constant */
    /* @4688012 constant */
    /* @4688016 load */
    /* @4688024 constant */
    /* @4688028 add */
    /* @4688032 constant */
    /* @4688036 constant */
    /* @4688040 load */
    /* @4688048 constant */
    /* @4688052 add */
    /* @4688056 call */
    GM_SITE(vm, 497, 4688056);
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(90));
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(135));
    /* @4688064 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, v5, STR_REF(970)));
    /* @4688068 load */
    /* @4688076 constant */
    /* @4688080 constant */
    /* @4688084 load */
    /* @4688092 constant */
    /* @4688096 add */
    /* @4688100 constant */
    /* @4688104 constant */
    /* @4688108 load */
    /* @4688116 constant */
    /* @4688120 add */
    /* @4688124 call */
    GM_SITE(vm, 497, 4688124);
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(90));
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4688132 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, v7, GM_READ(vm, -1, "tips1")));
    /* @4688136 load */
    /* @4688144 constant */
    /* @4688148 constant */
    /* @4688152 load */
    /* @4688160 constant */
    /* @4688164 add */
    /* @4688168 constant */
    /* @4688172 constant */
    /* @4688176 load */
    /* @4688184 constant */
    /* @4688188 add */
    /* @4688192 call */
    GM_SITE(vm, 497, 4688192);
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(90));
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(165));
    /* @4688200 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, GM_READ(vm, -1, "tips2")));
    L_4688204: ;
    /* @4688204 load */
    /* @4688212 constant */
    /* @4688216 cmp */
    /* @4688220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4688744;
    /* @4688224 constant */
    /* @4688228 cast */
    /* @4688232 constant */
    /* @4688236 cast */
    /* @4688240 constant */
    /* @4688244 cast */
    /* @4688248 constant */
    /* @4688260 cast */
    /* @4688264 constant */
    /* @4688276 cast */
    /* @4688280 constant */
    /* @4688284 constant */
    /* @4688288 load */
    /* @4688296 constant */
    /* @4688300 constant */
    /* @4688304 load */
    /* @4688312 constant */
    /* @4688316 sub */
    /* @4688320 constant */
    /* @4688324 cast */
    /* @4688328 constant */
    /* @4688332 cast */
    /* @4688336 call */
    GM_SITE(vm, 497, 4688336);
    /* @4688344 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4688348 constant */
    /* @4688352 cast */
    /* @4688356 call */
    GM_SITE(vm, 497, 4688356);
    /* @4688364 cast */
    /* @4688368 not */
    /* @4688372 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v10)) goto L_4688744;
    /* @4688376 constant */
    /* @4688384 cast */
    /* @4688388 call */
    GM_SITE(vm, 497, 4688388);
    /* @4688396 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4688400 constant */
    /* @4688404 cast */
    /* @4688408 call */
    GM_SITE(vm, 497, 4688408);
    /* @4688416 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4688420 constant */
    /* @4688424 cast */
    /* @4688428 constant */
    /* @4688432 cast */
    /* @4688436 constant */
    /* @4688440 cast */
    /* @4688444 constant */
    /* @4688448 cast */
    /* @4688452 constant */
    /* @4688456 cast */
    /* @4688460 constant */
    /* @4688464 constant */
    /* @4688468 load */
    /* @4688476 constant */
    /* @4688480 add */
    /* @4688484 constant */
    /* @4688488 constant */
    /* @4688492 load */
    /* @4688500 constant */
    /* @4688504 add */
    /* @4688508 constant */
    /* @4688512 cast */
    /* @4688516 constant */
    /* @4688520 cast */
    /* @4688524 call */
    GM_SITE(vm, 497, 4688524);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(70));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(155));
    /* @4688532 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v11, v12, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4688536 string */
    /* @4688544 cast */
    /* @4688548 constant */
    /* @4688552 constant */
    /* @4688556 load */
    /* @4688564 constant */
    /* @4688568 add */
    /* @4688572 constant */
    /* @4688576 constant */
    /* @4688580 load */
    /* @4688588 constant */
    /* @4688592 add */
    /* @4688596 call */
    GM_SITE(vm, 497, 4688596);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(90));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(145));
    /* @4688604 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, v14, STR_REF(970)));
    /* @4688608 load */
    /* @4688616 constant */
    /* @4688620 constant */
    /* @4688624 load */
    /* @4688632 constant */
    /* @4688636 add */
    /* @4688640 constant */
    /* @4688644 constant */
    /* @4688648 load */
    /* @4688656 constant */
    /* @4688660 add */
    /* @4688664 call */
    GM_SITE(vm, 497, 4688664);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(90));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    /* @4688672 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v15, v16, GM_READ(vm, -1, "tips1")));
    /* @4688676 load */
    /* @4688684 constant */
    /* @4688688 constant */
    /* @4688692 load */
    /* @4688700 constant */
    /* @4688704 add */
    /* @4688708 constant */
    /* @4688712 constant */
    /* @4688716 load */
    /* @4688724 constant */
    /* @4688728 add */
    /* @4688732 call */
    GM_SITE(vm, 497, 4688732);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(90));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(175));
    /* @4688740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, GM_READ(vm, -1, "tips2")));
    L_4688744: ;
    /* @4688744 load */
    /* @4688752 constant */
    /* @4688756 cmp */
    /* @4688760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4689284;
    /* @4688764 constant */
    /* @4688768 cast */
    /* @4688772 constant */
    /* @4688776 cast */
    /* @4688780 constant */
    /* @4688784 cast */
    /* @4688788 constant */
    /* @4688800 cast */
    /* @4688804 constant */
    /* @4688816 cast */
    /* @4688820 constant */
    /* @4688824 constant */
    /* @4688828 load */
    /* @4688836 constant */
    /* @4688840 constant */
    /* @4688844 load */
    /* @4688852 constant */
    /* @4688856 sub */
    /* @4688860 constant */
    /* @4688864 cast */
    /* @4688868 constant */
    /* @4688872 cast */
    /* @4688876 call */
    GM_SITE(vm, 497, 4688876);
    /* @4688884 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4688888 constant */
    /* @4688892 cast */
    /* @4688896 call */
    GM_SITE(vm, 497, 4688896);
    /* @4688904 cast */
    /* @4688908 not */
    /* @4688912 bf */
    v19 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v19)) goto L_4689284;
    /* @4688916 constant */
    /* @4688924 cast */
    /* @4688928 call */
    GM_SITE(vm, 497, 4688928);
    /* @4688936 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4688940 constant */
    /* @4688944 cast */
    /* @4688948 call */
    GM_SITE(vm, 497, 4688948);
    /* @4688956 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4688960 constant */
    /* @4688964 cast */
    /* @4688968 constant */
    /* @4688972 cast */
    /* @4688976 constant */
    /* @4688980 cast */
    /* @4688984 constant */
    /* @4688988 cast */
    /* @4688992 constant */
    /* @4688996 cast */
    /* @4689000 constant */
    /* @4689004 constant */
    /* @4689008 load */
    /* @4689016 constant */
    /* @4689020 add */
    /* @4689024 constant */
    /* @4689028 constant */
    /* @4689032 load */
    /* @4689040 constant */
    /* @4689044 add */
    /* @4689048 constant */
    /* @4689052 cast */
    /* @4689056 constant */
    /* @4689060 cast */
    /* @4689064 call */
    GM_SITE(vm, 497, 4689064);
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(100));
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(240));
    /* @4689072 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4689076 string */
    /* @4689084 cast */
    /* @4689088 constant */
    /* @4689092 constant */
    /* @4689096 load */
    /* @4689104 constant */
    /* @4689108 add */
    /* @4689112 constant */
    /* @4689116 constant */
    /* @4689120 load */
    /* @4689128 constant */
    /* @4689132 add */
    /* @4689136 call */
    GM_SITE(vm, 497, 4689136);
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(120));
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(225));
    /* @4689144 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v22, v23, STR_REF(970)));
    /* @4689148 load */
    /* @4689156 constant */
    /* @4689160 constant */
    /* @4689164 load */
    /* @4689172 constant */
    /* @4689176 add */
    /* @4689180 constant */
    /* @4689184 constant */
    /* @4689188 load */
    /* @4689196 constant */
    /* @4689200 add */
    /* @4689204 call */
    GM_SITE(vm, 497, 4689204);
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(120));
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(240));
    /* @4689212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, GM_READ(vm, -1, "tips1")));
    /* @4689216 load */
    /* @4689224 constant */
    /* @4689228 constant */
    /* @4689232 load */
    /* @4689240 constant */
    /* @4689244 add */
    /* @4689248 constant */
    /* @4689252 constant */
    /* @4689256 load */
    /* @4689264 constant */
    /* @4689268 add */
    /* @4689272 call */
    GM_SITE(vm, 497, 4689272);
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(120));
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(255));
    /* @4689280 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, GM_READ(vm, -1, "tips2")));
    L_4689284: ;
    /* @4689284 load */
    /* @4689292 constant */
    /* @4689296 cmp */
    /* @4689300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4689824;
    /* @4689304 constant */
    /* @4689308 cast */
    /* @4689312 constant */
    /* @4689316 cast */
    /* @4689320 constant */
    /* @4689324 cast */
    /* @4689328 constant */
    /* @4689340 cast */
    /* @4689344 constant */
    /* @4689356 cast */
    /* @4689360 constant */
    /* @4689364 constant */
    /* @4689368 load */
    /* @4689376 constant */
    /* @4689380 constant */
    /* @4689384 load */
    /* @4689392 constant */
    /* @4689396 sub */
    /* @4689400 constant */
    /* @4689404 cast */
    /* @4689408 constant */
    /* @4689412 cast */
    /* @4689416 call */
    GM_SITE(vm, 497, 4689416);
    /* @4689424 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4689428 constant */
    /* @4689432 cast */
    /* @4689436 call */
    GM_SITE(vm, 497, 4689436);
    /* @4689444 cast */
    /* @4689448 not */
    /* @4689452 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v28)) goto L_4689824;
    /* @4689456 constant */
    /* @4689464 cast */
    /* @4689468 call */
    GM_SITE(vm, 497, 4689468);
    /* @4689476 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4689480 constant */
    /* @4689484 cast */
    /* @4689488 call */
    GM_SITE(vm, 497, 4689488);
    /* @4689496 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4689500 constant */
    /* @4689504 cast */
    /* @4689508 constant */
    /* @4689512 cast */
    /* @4689516 constant */
    /* @4689520 cast */
    /* @4689524 constant */
    /* @4689528 cast */
    /* @4689532 constant */
    /* @4689536 cast */
    /* @4689540 constant */
    /* @4689544 constant */
    /* @4689548 load */
    /* @4689556 constant */
    /* @4689560 add */
    /* @4689564 constant */
    /* @4689568 constant */
    /* @4689572 load */
    /* @4689580 constant */
    /* @4689584 add */
    /* @4689588 constant */
    /* @4689592 cast */
    /* @4689596 constant */
    /* @4689600 cast */
    /* @4689604 call */
    GM_SITE(vm, 497, 4689604);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(100));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(240));
    /* @4689612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v29, v30, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4689616 string */
    /* @4689624 cast */
    /* @4689628 constant */
    /* @4689632 constant */
    /* @4689636 load */
    /* @4689644 constant */
    /* @4689648 add */
    /* @4689652 constant */
    /* @4689656 constant */
    /* @4689660 load */
    /* @4689668 constant */
    /* @4689672 add */
    /* @4689676 call */
    GM_SITE(vm, 497, 4689676);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(120));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(225));
    /* @4689684 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v31, v32, STR_REF(970)));
    /* @4689688 load */
    /* @4689696 constant */
    /* @4689700 constant */
    /* @4689704 load */
    /* @4689712 constant */
    /* @4689716 add */
    /* @4689720 constant */
    /* @4689724 constant */
    /* @4689728 load */
    /* @4689736 constant */
    /* @4689740 add */
    /* @4689744 call */
    GM_SITE(vm, 497, 4689744);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(120));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(240));
    /* @4689752 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, GM_READ(vm, -1, "tips1")));
    /* @4689756 load */
    /* @4689764 constant */
    /* @4689768 constant */
    /* @4689772 load */
    /* @4689780 constant */
    /* @4689784 add */
    /* @4689788 constant */
    /* @4689792 constant */
    /* @4689796 load */
    /* @4689804 constant */
    /* @4689808 add */
    /* @4689812 call */
    GM_SITE(vm, 497, 4689812);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(120));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(255));
    /* @4689820 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, GM_READ(vm, -1, "tips2")));
    L_4689824: ;
    /* @4689824 load */
    /* @4689832 constant */
    /* @4689836 cmp */
    /* @4689840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4690364;
    /* @4689844 constant */
    /* @4689848 cast */
    /* @4689852 constant */
    /* @4689856 cast */
    /* @4689860 constant */
    /* @4689864 cast */
    /* @4689868 constant */
    /* @4689880 cast */
    /* @4689884 constant */
    /* @4689896 cast */
    /* @4689900 constant */
    /* @4689904 constant */
    /* @4689908 load */
    /* @4689916 constant */
    /* @4689920 constant */
    /* @4689924 load */
    /* @4689932 constant */
    /* @4689936 sub */
    /* @4689940 constant */
    /* @4689944 cast */
    /* @4689948 constant */
    /* @4689952 cast */
    /* @4689956 call */
    GM_SITE(vm, 497, 4689956);
    /* @4689964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4689968 constant */
    /* @4689972 cast */
    /* @4689976 call */
    GM_SITE(vm, 497, 4689976);
    /* @4689984 cast */
    /* @4689988 not */
    /* @4689992 bf */
    v37 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v37)) goto L_4690364;
    /* @4689996 constant */
    /* @4690004 cast */
    /* @4690008 call */
    GM_SITE(vm, 497, 4690008);
    /* @4690016 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4690020 constant */
    /* @4690024 cast */
    /* @4690028 call */
    GM_SITE(vm, 497, 4690028);
    /* @4690036 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4690040 constant */
    /* @4690044 cast */
    /* @4690048 constant */
    /* @4690052 cast */
    /* @4690056 constant */
    /* @4690060 cast */
    /* @4690064 constant */
    /* @4690068 cast */
    /* @4690072 constant */
    /* @4690076 cast */
    /* @4690080 constant */
    /* @4690084 constant */
    /* @4690088 load */
    /* @4690096 constant */
    /* @4690100 add */
    /* @4690104 constant */
    /* @4690108 constant */
    /* @4690112 load */
    /* @4690120 constant */
    /* @4690124 add */
    /* @4690128 constant */
    /* @4690132 cast */
    /* @4690136 constant */
    /* @4690140 cast */
    /* @4690144 call */
    GM_SITE(vm, 497, 4690144);
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(70));
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @4690152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v38, v39, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4690156 string */
    /* @4690164 cast */
    /* @4690168 constant */
    /* @4690172 constant */
    /* @4690176 load */
    /* @4690184 constant */
    /* @4690188 add */
    /* @4690192 constant */
    /* @4690196 constant */
    /* @4690200 load */
    /* @4690208 constant */
    /* @4690212 add */
    /* @4690216 call */
    GM_SITE(vm, 497, 4690216);
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(90));
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(135));
    /* @4690224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(970)));
    /* @4690228 load */
    /* @4690236 constant */
    /* @4690240 constant */
    /* @4690244 load */
    /* @4690252 constant */
    /* @4690256 add */
    /* @4690260 constant */
    /* @4690264 constant */
    /* @4690268 load */
    /* @4690276 constant */
    /* @4690280 add */
    /* @4690284 call */
    GM_SITE(vm, 497, 4690284);
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(90));
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @4690292 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v42, v43, GM_READ(vm, -1, "tips1")));
    /* @4690296 load */
    /* @4690304 constant */
    /* @4690308 constant */
    /* @4690312 load */
    /* @4690320 constant */
    /* @4690324 add */
    /* @4690328 constant */
    /* @4690332 constant */
    /* @4690336 load */
    /* @4690344 constant */
    /* @4690348 add */
    /* @4690352 call */
    GM_SITE(vm, 497, 4690352);
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(90));
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(165));
    /* @4690360 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v44, v45, GM_READ(vm, -1, "tips2")));
    L_4690364: ;
    /* @4690364 load */
    /* @4690372 constant */
    /* @4690376 cmp */
    /* @4690380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4690904;
    /* @4690384 constant */
    /* @4690388 cast */
    /* @4690392 constant */
    /* @4690396 cast */
    /* @4690400 constant */
    /* @4690404 cast */
    /* @4690408 constant */
    /* @4690420 cast */
    /* @4690424 constant */
    /* @4690436 cast */
    /* @4690440 constant */
    /* @4690444 constant */
    /* @4690448 load */
    /* @4690456 constant */
    /* @4690460 constant */
    /* @4690464 load */
    /* @4690472 constant */
    /* @4690476 sub */
    /* @4690480 constant */
    /* @4690484 cast */
    /* @4690488 constant */
    /* @4690492 cast */
    /* @4690496 call */
    GM_SITE(vm, 497, 4690496);
    /* @4690504 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4690508 constant */
    /* @4690512 cast */
    /* @4690516 call */
    GM_SITE(vm, 497, 4690516);
    /* @4690524 cast */
    /* @4690528 not */
    /* @4690532 bf */
    v46 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114))));
    if (!TRUTH(v46)) goto L_4690904;
    /* @4690536 constant */
    /* @4690544 cast */
    /* @4690548 call */
    GM_SITE(vm, 497, 4690548);
    /* @4690556 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4690560 constant */
    /* @4690564 cast */
    /* @4690568 call */
    GM_SITE(vm, 497, 4690568);
    /* @4690576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4690580 constant */
    /* @4690584 cast */
    /* @4690588 constant */
    /* @4690592 cast */
    /* @4690596 constant */
    /* @4690600 cast */
    /* @4690604 constant */
    /* @4690608 cast */
    /* @4690612 constant */
    /* @4690616 cast */
    /* @4690620 constant */
    /* @4690624 constant */
    /* @4690628 load */
    /* @4690636 constant */
    /* @4690640 add */
    /* @4690644 constant */
    /* @4690648 constant */
    /* @4690652 load */
    /* @4690660 constant */
    /* @4690664 add */
    /* @4690668 constant */
    /* @4690672 cast */
    /* @4690676 constant */
    /* @4690680 cast */
    /* @4690684 call */
    GM_SITE(vm, 497, 4690684);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(70));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    /* @4690692 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v47, v48, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4690696 string */
    /* @4690704 cast */
    /* @4690708 constant */
    /* @4690712 constant */
    /* @4690716 load */
    /* @4690724 constant */
    /* @4690728 add */
    /* @4690732 constant */
    /* @4690736 constant */
    /* @4690740 load */
    /* @4690748 constant */
    /* @4690752 add */
    /* @4690756 call */
    GM_SITE(vm, 497, 4690756);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(90));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(135));
    /* @4690764 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(970)));
    /* @4690768 load */
    /* @4690776 constant */
    /* @4690780 constant */
    /* @4690784 load */
    /* @4690792 constant */
    /* @4690796 add */
    /* @4690800 constant */
    /* @4690804 constant */
    /* @4690808 load */
    /* @4690816 constant */
    /* @4690820 add */
    /* @4690824 call */
    GM_SITE(vm, 497, 4690824);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(90));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    /* @4690832 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, GM_READ(vm, -1, "tips1")));
    /* @4690836 load */
    /* @4690844 constant */
    /* @4690848 constant */
    /* @4690852 load */
    /* @4690860 constant */
    /* @4690864 add */
    /* @4690868 constant */
    /* @4690872 constant */
    /* @4690876 load */
    /* @4690884 constant */
    /* @4690888 add */
    /* @4690892 call */
    GM_SITE(vm, 497, 4690892);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(90));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(165));
    /* @4690900 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, GM_READ(vm, -1, "tips2")));
    L_4690904: ;
    return;
}
