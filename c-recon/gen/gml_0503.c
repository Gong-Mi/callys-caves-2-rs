/* generated from CODE 503 (gml_Object_obj_poisoniap_Draw_0), source start 4694744, end 4698048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0503(GmVM* vm) {
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
    Val v55;
    Val v56;
    Val v57;
    Val v58;
    /* @4694744 load */
    /* @4694752 constant */
    /* @4694756 cmp */
    /* @4694760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4695236;
    /* @4694764 constant */
    /* @4694768 cast */
    /* @4694772 constant */
    /* @4694776 cast */
    /* @4694780 constant */
    /* @4694784 cast */
    /* @4694788 constant */
    /* @4694800 cast */
    /* @4694804 constant */
    /* @4694816 cast */
    /* @4694820 load */
    /* @4694828 load */
    /* @4694836 constant */
    /* @4694840 cast */
    /* @4694844 constant */
    /* @4694848 cast */
    /* @4694852 call */
    GM_SITE(vm, 503, 4694852);
    /* @4694860 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.7), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4694864 constant */
    /* @4694868 cast */
    /* @4694872 call */
    GM_SITE(vm, 503, 4694872);
    /* @4694880 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4694884 constant */
    /* @4694892 cast */
    /* @4694896 call */
    GM_SITE(vm, 503, 4694896);
    /* @4694904 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4694908 string */
    /* @4694916 cast */
    /* @4694920 load */
    /* @4694928 constant */
    /* @4694932 add */
    /* @4694936 load */
    /* @4694944 constant */
    /* @4694948 add */
    /* @4694952 call */
    GM_SITE(vm, 503, 4694952);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4694960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(992)));
    /* @4694964 string */
    /* @4694972 cast */
    /* @4694976 load */
    /* @4694984 constant */
    /* @4694988 add */
    /* @4694992 load */
    /* @4695000 constant */
    /* @4695004 add */
    /* @4695008 call */
    GM_SITE(vm, 503, 4695008);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v4 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4695016 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, v4, STR_REF(993)));
    /* @4695020 constant */
    /* @4695024 cast */
    /* @4695028 constant */
    /* @4695032 cast */
    /* @4695036 constant */
    /* @4695040 cast */
    /* @4695044 constant */
    /* @4695048 cast */
    /* @4695052 constant */
    /* @4695056 cast */
    /* @4695060 load */
    /* @4695068 constant */
    /* @4695072 add */
    /* @4695076 load */
    /* @4695084 constant */
    /* @4695088 add */
    /* @4695092 constant */
    /* @4695096 cast */
    /* @4695100 constant */
    /* @4695104 cast */
    /* @4695108 call */
    GM_SITE(vm, 503, 4695108);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v6 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4695116 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v5, v6, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4695120 constant */
    /* @4695124 cast */
    /* @4695128 constant */
    /* @4695132 cast */
    /* @4695136 constant */
    /* @4695140 cast */
    /* @4695144 constant */
    /* @4695156 cast */
    /* @4695160 constant */
    /* @4695172 cast */
    /* @4695176 load */
    /* @4695184 constant */
    /* @4695188 add */
    /* @4695192 load */
    /* @4695200 constant */
    /* @4695204 add */
    /* @4695208 constant */
    /* @4695212 cast */
    /* @4695216 constant */
    /* @4695220 cast */
    /* @4695224 call */
    GM_SITE(vm, 503, 4695224);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v8 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4695232 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v7, v8, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4695236: ;
    /* @4695236 load */
    /* @4695244 constant */
    /* @4695248 cmp */
    /* @4695252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4695792;
    /* @4695256 constant */
    /* @4695260 constant */
    /* @4695264 load */
    /* @4695272 constant */
    /* @4695276 add */
    /* @4695280 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(80));
    GM_WRITE(vm, -1, "x", v9);
    /* @4695288 constant */
    /* @4695292 constant */
    /* @4695296 load */
    /* @4695304 constant */
    /* @4695308 add */
    /* @4695312 store */
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(85));
    GM_WRITE(vm, -1, "y", v10);
    /* @4695320 constant */
    /* @4695324 cast */
    /* @4695328 constant */
    /* @4695332 cast */
    /* @4695336 constant */
    /* @4695340 cast */
    /* @4695344 constant */
    /* @4695356 cast */
    /* @4695360 constant */
    /* @4695372 cast */
    /* @4695376 load */
    /* @4695384 load */
    /* @4695392 constant */
    /* @4695396 cast */
    /* @4695400 constant */
    /* @4695404 cast */
    /* @4695408 call */
    GM_SITE(vm, 503, 4695408);
    /* @4695416 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.7), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4695420 constant */
    /* @4695424 cast */
    /* @4695428 call */
    GM_SITE(vm, 503, 4695428);
    /* @4695436 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4695440 constant */
    /* @4695448 cast */
    /* @4695452 call */
    GM_SITE(vm, 503, 4695452);
    /* @4695460 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4695464 string */
    /* @4695472 cast */
    /* @4695476 load */
    /* @4695484 constant */
    /* @4695488 add */
    /* @4695492 load */
    /* @4695500 constant */
    /* @4695504 add */
    /* @4695508 call */
    GM_SITE(vm, 503, 4695508);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v12 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4695516 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(994)));
    /* @4695520 string */
    /* @4695528 cast */
    /* @4695532 load */
    /* @4695540 constant */
    /* @4695544 add */
    /* @4695548 load */
    /* @4695556 constant */
    /* @4695560 add */
    /* @4695564 call */
    GM_SITE(vm, 503, 4695564);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4695572 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, v14, STR_REF(993)));
    /* @4695576 constant */
    /* @4695580 cast */
    /* @4695584 constant */
    /* @4695588 cast */
    /* @4695592 constant */
    /* @4695596 cast */
    /* @4695600 constant */
    /* @4695604 cast */
    /* @4695608 constant */
    /* @4695612 cast */
    /* @4695616 load */
    /* @4695624 constant */
    /* @4695628 add */
    /* @4695632 load */
    /* @4695640 constant */
    /* @4695644 add */
    /* @4695648 constant */
    /* @4695652 cast */
    /* @4695656 constant */
    /* @4695660 cast */
    /* @4695664 call */
    GM_SITE(vm, 503, 4695664);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v16 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4695672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v15, v16, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4695676 constant */
    /* @4695680 cast */
    /* @4695684 constant */
    /* @4695688 cast */
    /* @4695692 constant */
    /* @4695696 cast */
    /* @4695700 constant */
    /* @4695712 cast */
    /* @4695716 constant */
    /* @4695728 cast */
    /* @4695732 load */
    /* @4695740 constant */
    /* @4695744 add */
    /* @4695748 load */
    /* @4695756 constant */
    /* @4695760 add */
    /* @4695764 constant */
    /* @4695768 cast */
    /* @4695772 constant */
    /* @4695776 cast */
    /* @4695780 call */
    GM_SITE(vm, 503, 4695780);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v18 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4695788 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v17, v18, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4695792: ;
    /* @4695792 load */
    /* @4695800 constant */
    /* @4695804 cmp */
    /* @4695808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4696364;
    /* @4695812 constant */
    /* @4695816 constant */
    /* @4695820 load */
    /* @4695828 constant */
    /* @4695832 add */
    /* @4695836 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(150));
    GM_WRITE(vm, -1, "x", v19);
    /* @4695844 constant */
    /* @4695848 constant */
    /* @4695852 load */
    /* @4695860 constant */
    /* @4695864 add */
    /* @4695868 store */
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(160));
    GM_WRITE(vm, -1, "y", v20);
    /* @4695876 constant */
    /* @4695880 cast */
    /* @4695884 constant */
    /* @4695888 cast */
    /* @4695892 constant */
    /* @4695896 cast */
    /* @4695900 constant */
    /* @4695912 cast */
    /* @4695916 constant */
    /* @4695928 cast */
    /* @4695932 load */
    /* @4695940 load */
    /* @4695948 constant */
    /* @4695952 cast */
    /* @4695956 constant */
    /* @4695960 cast */
    /* @4695964 call */
    GM_SITE(vm, 503, 4695964);
    /* @4695972 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.65), VAL(1.65), VAL(0), VAL(-1), VAL(1)));
    /* @4695976 constant */
    /* @4695980 cast */
    /* @4695984 call */
    GM_SITE(vm, 503, 4695984);
    /* @4695992 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4695996 constant */
    /* @4696004 cast */
    /* @4696008 call */
    GM_SITE(vm, 503, 4696008);
    /* @4696016 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4696020 string */
    /* @4696028 cast */
    /* @4696032 load */
    /* @4696040 constant */
    /* @4696044 add */
    /* @4696048 load */
    /* @4696056 constant */
    /* @4696060 add */
    /* @4696064 call */
    GM_SITE(vm, 503, 4696064);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v22 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4696072 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, v22, STR_REF(994)));
    /* @4696076 string */
    /* @4696084 cast */
    /* @4696088 load */
    /* @4696096 constant */
    /* @4696100 add */
    /* @4696104 load */
    /* @4696112 constant */
    /* @4696116 add */
    /* @4696120 call */
    GM_SITE(vm, 503, 4696120);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v24 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4696128 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(993)));
    /* @4696132 constant */
    /* @4696136 cast */
    /* @4696140 constant */
    /* @4696144 cast */
    /* @4696148 constant */
    /* @4696152 cast */
    /* @4696156 constant */
    /* @4696168 cast */
    /* @4696172 constant */
    /* @4696184 cast */
    /* @4696188 load */
    /* @4696196 constant */
    /* @4696200 add */
    /* @4696204 load */
    /* @4696212 constant */
    /* @4696216 add */
    /* @4696220 constant */
    /* @4696224 cast */
    /* @4696228 constant */
    /* @4696232 cast */
    /* @4696236 call */
    GM_SITE(vm, 503, 4696236);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v26 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4696244 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v25, v26, VAL(1.5), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4696248 constant */
    /* @4696252 cast */
    /* @4696256 constant */
    /* @4696260 cast */
    /* @4696264 constant */
    /* @4696268 cast */
    /* @4696272 constant */
    /* @4696284 cast */
    /* @4696288 constant */
    /* @4696300 cast */
    /* @4696304 load */
    /* @4696312 constant */
    /* @4696316 add */
    /* @4696320 load */
    /* @4696328 constant */
    /* @4696332 add */
    /* @4696336 constant */
    /* @4696340 cast */
    /* @4696344 constant */
    /* @4696348 cast */
    /* @4696352 call */
    GM_SITE(vm, 503, 4696352);
    v27 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v28 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4696360 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v27, v28, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4696364: ;
    /* @4696364 load */
    /* @4696372 constant */
    /* @4696376 cmp */
    /* @4696380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4696936;
    /* @4696384 constant */
    /* @4696388 constant */
    /* @4696392 load */
    /* @4696400 constant */
    /* @4696404 add */
    /* @4696408 store */
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(150));
    GM_WRITE(vm, -1, "x", v29);
    /* @4696416 constant */
    /* @4696420 constant */
    /* @4696424 load */
    /* @4696432 constant */
    /* @4696436 add */
    /* @4696440 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(160));
    GM_WRITE(vm, -1, "y", v30);
    /* @4696448 constant */
    /* @4696452 cast */
    /* @4696456 constant */
    /* @4696460 cast */
    /* @4696464 constant */
    /* @4696468 cast */
    /* @4696472 constant */
    /* @4696484 cast */
    /* @4696488 constant */
    /* @4696500 cast */
    /* @4696504 load */
    /* @4696512 load */
    /* @4696520 constant */
    /* @4696524 cast */
    /* @4696528 constant */
    /* @4696532 cast */
    /* @4696536 call */
    GM_SITE(vm, 503, 4696536);
    /* @4696544 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.65), VAL(1.65), VAL(0), VAL(-1), VAL(1)));
    /* @4696548 constant */
    /* @4696552 cast */
    /* @4696556 call */
    GM_SITE(vm, 503, 4696556);
    /* @4696564 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4696568 constant */
    /* @4696576 cast */
    /* @4696580 call */
    GM_SITE(vm, 503, 4696580);
    /* @4696588 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4696592 string */
    /* @4696600 cast */
    /* @4696604 load */
    /* @4696612 constant */
    /* @4696616 add */
    /* @4696620 load */
    /* @4696628 constant */
    /* @4696632 add */
    /* @4696636 call */
    GM_SITE(vm, 503, 4696636);
    v31 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v32 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4696644 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v31, v32, STR_REF(994)));
    /* @4696648 string */
    /* @4696656 cast */
    /* @4696660 load */
    /* @4696668 constant */
    /* @4696672 add */
    /* @4696676 load */
    /* @4696684 constant */
    /* @4696688 add */
    /* @4696692 call */
    GM_SITE(vm, 503, 4696692);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4696700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(993)));
    /* @4696704 constant */
    /* @4696708 cast */
    /* @4696712 constant */
    /* @4696716 cast */
    /* @4696720 constant */
    /* @4696724 cast */
    /* @4696728 constant */
    /* @4696740 cast */
    /* @4696744 constant */
    /* @4696756 cast */
    /* @4696760 load */
    /* @4696768 constant */
    /* @4696772 add */
    /* @4696776 load */
    /* @4696784 constant */
    /* @4696788 add */
    /* @4696792 constant */
    /* @4696796 cast */
    /* @4696800 constant */
    /* @4696804 cast */
    /* @4696808 call */
    GM_SITE(vm, 503, 4696808);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4696816 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v35, v36, VAL(1.5), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4696820 constant */
    /* @4696824 cast */
    /* @4696828 constant */
    /* @4696832 cast */
    /* @4696836 constant */
    /* @4696840 cast */
    /* @4696844 constant */
    /* @4696856 cast */
    /* @4696860 constant */
    /* @4696872 cast */
    /* @4696876 load */
    /* @4696884 constant */
    /* @4696888 add */
    /* @4696892 load */
    /* @4696900 constant */
    /* @4696904 add */
    /* @4696908 constant */
    /* @4696912 cast */
    /* @4696916 constant */
    /* @4696920 cast */
    /* @4696924 call */
    GM_SITE(vm, 503, 4696924);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v38 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4696932 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v37, v38, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4696936: ;
    /* @4696936 load */
    /* @4696944 constant */
    /* @4696948 cmp */
    /* @4696952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4697492;
    /* @4696956 constant */
    /* @4696960 constant */
    /* @4696964 load */
    /* @4696972 constant */
    /* @4696976 add */
    /* @4696980 store */
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(120));
    GM_WRITE(vm, -1, "x", v39);
    /* @4696988 constant */
    /* @4696992 constant */
    /* @4696996 load */
    /* @4697004 constant */
    /* @4697008 add */
    /* @4697012 store */
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(100));
    GM_WRITE(vm, -1, "y", v40);
    /* @4697020 constant */
    /* @4697024 cast */
    /* @4697028 constant */
    /* @4697032 cast */
    /* @4697036 constant */
    /* @4697040 cast */
    /* @4697044 constant */
    /* @4697056 cast */
    /* @4697060 constant */
    /* @4697072 cast */
    /* @4697076 load */
    /* @4697084 load */
    /* @4697092 constant */
    /* @4697096 cast */
    /* @4697100 constant */
    /* @4697104 cast */
    /* @4697108 call */
    GM_SITE(vm, 503, 4697108);
    /* @4697116 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.7), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4697120 constant */
    /* @4697124 cast */
    /* @4697128 call */
    GM_SITE(vm, 503, 4697128);
    /* @4697136 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4697140 constant */
    /* @4697148 cast */
    /* @4697152 call */
    GM_SITE(vm, 503, 4697152);
    /* @4697160 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4697164 string */
    /* @4697172 cast */
    /* @4697176 load */
    /* @4697184 constant */
    /* @4697188 add */
    /* @4697192 load */
    /* @4697200 constant */
    /* @4697204 add */
    /* @4697208 call */
    GM_SITE(vm, 503, 4697208);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v42 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4697216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(992)));
    /* @4697220 string */
    /* @4697228 cast */
    /* @4697232 load */
    /* @4697240 constant */
    /* @4697244 add */
    /* @4697248 load */
    /* @4697256 constant */
    /* @4697260 add */
    /* @4697264 call */
    GM_SITE(vm, 503, 4697264);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v44 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4697272 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(993)));
    /* @4697276 constant */
    /* @4697280 cast */
    /* @4697284 constant */
    /* @4697288 cast */
    /* @4697292 constant */
    /* @4697296 cast */
    /* @4697300 constant */
    /* @4697304 cast */
    /* @4697308 constant */
    /* @4697312 cast */
    /* @4697316 load */
    /* @4697324 constant */
    /* @4697328 add */
    /* @4697332 load */
    /* @4697340 constant */
    /* @4697344 add */
    /* @4697348 constant */
    /* @4697352 cast */
    /* @4697356 constant */
    /* @4697360 cast */
    /* @4697364 call */
    GM_SITE(vm, 503, 4697364);
    v45 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v46 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4697372 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v45, v46, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4697376 constant */
    /* @4697380 cast */
    /* @4697384 constant */
    /* @4697388 cast */
    /* @4697392 constant */
    /* @4697396 cast */
    /* @4697400 constant */
    /* @4697412 cast */
    /* @4697416 constant */
    /* @4697428 cast */
    /* @4697432 load */
    /* @4697440 constant */
    /* @4697444 add */
    /* @4697448 load */
    /* @4697456 constant */
    /* @4697460 add */
    /* @4697464 constant */
    /* @4697468 cast */
    /* @4697472 constant */
    /* @4697476 cast */
    /* @4697480 call */
    GM_SITE(vm, 503, 4697480);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v48 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4697488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v47, v48, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4697492: ;
    /* @4697492 load */
    /* @4697500 constant */
    /* @4697504 cmp */
    /* @4697508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4698048;
    /* @4697512 constant */
    /* @4697516 constant */
    /* @4697520 load */
    /* @4697528 constant */
    /* @4697532 add */
    /* @4697536 store */
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(120));
    GM_WRITE(vm, -1, "x", v49);
    /* @4697544 constant */
    /* @4697548 constant */
    /* @4697552 load */
    /* @4697560 constant */
    /* @4697564 add */
    /* @4697568 store */
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(100));
    GM_WRITE(vm, -1, "y", v50);
    /* @4697576 constant */
    /* @4697580 cast */
    /* @4697584 constant */
    /* @4697588 cast */
    /* @4697592 constant */
    /* @4697596 cast */
    /* @4697600 constant */
    /* @4697612 cast */
    /* @4697616 constant */
    /* @4697628 cast */
    /* @4697632 load */
    /* @4697640 load */
    /* @4697648 constant */
    /* @4697652 cast */
    /* @4697656 constant */
    /* @4697660 cast */
    /* @4697664 call */
    GM_SITE(vm, 503, 4697664);
    /* @4697672 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.7), VAL(1.5), VAL(0), VAL(-1), VAL(1)));
    /* @4697676 constant */
    /* @4697680 cast */
    /* @4697684 call */
    GM_SITE(vm, 503, 4697684);
    /* @4697692 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4697696 constant */
    /* @4697704 cast */
    /* @4697708 call */
    GM_SITE(vm, 503, 4697708);
    /* @4697716 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4697720 string */
    /* @4697728 cast */
    /* @4697732 load */
    /* @4697740 constant */
    /* @4697744 add */
    /* @4697748 load */
    /* @4697756 constant */
    /* @4697760 add */
    /* @4697764 call */
    GM_SITE(vm, 503, 4697764);
    v51 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v52 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4697772 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(992)));
    /* @4697776 string */
    /* @4697784 cast */
    /* @4697788 load */
    /* @4697796 constant */
    /* @4697800 add */
    /* @4697804 load */
    /* @4697812 constant */
    /* @4697816 add */
    /* @4697820 call */
    GM_SITE(vm, 503, 4697820);
    v53 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v54 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4697828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(993)));
    /* @4697832 constant */
    /* @4697836 cast */
    /* @4697840 constant */
    /* @4697844 cast */
    /* @4697848 constant */
    /* @4697852 cast */
    /* @4697856 constant */
    /* @4697860 cast */
    /* @4697864 constant */
    /* @4697868 cast */
    /* @4697872 load */
    /* @4697880 constant */
    /* @4697884 add */
    /* @4697888 load */
    /* @4697896 constant */
    /* @4697900 add */
    /* @4697904 constant */
    /* @4697908 cast */
    /* @4697912 constant */
    /* @4697916 cast */
    /* @4697920 call */
    GM_SITE(vm, 503, 4697920);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(170));
    v56 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4697928 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(40), VAL(1), v55, v56, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4697932 constant */
    /* @4697936 cast */
    /* @4697940 constant */
    /* @4697944 cast */
    /* @4697948 constant */
    /* @4697952 cast */
    /* @4697956 constant */
    /* @4697968 cast */
    /* @4697972 constant */
    /* @4697984 cast */
    /* @4697988 load */
    /* @4697996 constant */
    /* @4698000 add */
    /* @4698004 load */
    /* @4698012 constant */
    /* @4698016 add */
    /* @4698020 constant */
    /* @4698024 cast */
    /* @4698028 constant */
    /* @4698032 cast */
    /* @4698036 call */
    GM_SITE(vm, 503, 4698036);
    v57 = GM_ADD(GM_READ(vm, -1, "x"), VAL(190));
    v58 = GM_ADD(GM_READ(vm, -1, "y"), VAL(30));
    /* @4698044 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(152), VAL(1), v57, v58, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4698048: ;
    return;
}
