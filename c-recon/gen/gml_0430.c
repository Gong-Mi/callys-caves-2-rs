/* generated from CODE 430 (gml_Object_obj_energywaveupgrade_Draw_0), source start 4604696, end 4608048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0430(GmVM* vm) {
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
    /* @4604696 load */
    /* @4604704 constant */
    /* @4604708 cmp */
    /* @4604712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4605200;
    /* @4604716 constant */
    /* @4604720 cast */
    /* @4604724 constant */
    /* @4604728 cast */
    /* @4604732 constant */
    /* @4604736 cast */
    /* @4604740 constant */
    /* @4604752 cast */
    /* @4604756 constant */
    /* @4604768 cast */
    /* @4604772 load */
    /* @4604780 load */
    /* @4604788 constant */
    /* @4604792 cast */
    /* @4604796 constant */
    /* @4604800 cast */
    /* @4604804 call */
    GM_SITE(vm, 430, 4604804);
    /* @4604812 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4604816 constant */
    /* @4604820 cast */
    /* @4604824 call */
    GM_SITE(vm, 430, 4604824);
    /* @4604832 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4604836 constant */
    /* @4604844 cast */
    /* @4604848 call */
    GM_SITE(vm, 430, 4604848);
    /* @4604856 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4604860 string */
    /* @4604868 cast */
    /* @4604872 load */
    /* @4604880 load */
    /* @4604888 constant */
    /* @4604892 add */
    /* @4604896 call */
    GM_SITE(vm, 430, 4604896);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4604904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(809)));
    /* @4604908 string */
    /* @4604916 cast */
    /* @4604920 load */
    /* @4604928 constant */
    /* @4604932 add */
    /* @4604936 load */
    /* @4604944 constant */
    /* @4604948 add */
    /* @4604952 call */
    GM_SITE(vm, 430, 4604952);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4604960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(810)));
    /* @4604964 constant */
    /* @4604968 cast */
    /* @4604972 constant */
    /* @4604976 cast */
    /* @4604980 constant */
    /* @4604984 cast */
    /* @4604988 constant */
    /* @4605000 cast */
    /* @4605004 constant */
    /* @4605016 cast */
    /* @4605020 load */
    /* @4605028 constant */
    /* @4605032 add */
    /* @4605036 load */
    /* @4605044 constant */
    /* @4605048 add */
    /* @4605052 constant */
    /* @4605056 cast */
    /* @4605060 constant */
    /* @4605064 cast */
    /* @4605068 call */
    GM_SITE(vm, 430, 4605068);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4605076 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4605080 load */
    /* @4605088 constant */
    /* @4605092 cmp */
    /* @4605096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4605200;
    /* @4605100 constant */
    /* @4605104 cast */
    /* @4605108 constant */
    /* @4605112 cast */
    /* @4605116 constant */
    /* @4605120 cast */
    /* @4605124 constant */
    /* @4605136 cast */
    /* @4605140 constant */
    /* @4605152 cast */
    /* @4605156 load */
    /* @4605164 load */
    /* @4605172 constant */
    /* @4605176 cast */
    /* @4605180 constant */
    /* @4605184 cast */
    /* @4605188 call */
    GM_SITE(vm, 430, 4605188);
    /* @4605196 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4605200: ;
    /* @4605200 load */
    /* @4605208 constant */
    /* @4605212 cmp */
    /* @4605216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4605760;
    /* @4605220 constant */
    /* @4605224 constant */
    /* @4605228 load */
    /* @4605236 constant */
    /* @4605240 add */
    /* @4605244 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4605252 constant */
    /* @4605256 constant */
    /* @4605260 load */
    /* @4605268 constant */
    /* @4605272 add */
    /* @4605276 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    GM_WRITE(vm, -1, "y", v7);
    /* @4605284 constant */
    /* @4605288 cast */
    /* @4605292 constant */
    /* @4605296 cast */
    /* @4605300 constant */
    /* @4605304 cast */
    /* @4605308 constant */
    /* @4605312 cast */
    /* @4605316 constant */
    /* @4605320 cast */
    /* @4605324 load */
    /* @4605332 load */
    /* @4605340 constant */
    /* @4605344 cast */
    /* @4605348 constant */
    /* @4605352 cast */
    /* @4605356 call */
    GM_SITE(vm, 430, 4605356);
    /* @4605364 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4605368 constant */
    /* @4605372 cast */
    /* @4605376 call */
    GM_SITE(vm, 430, 4605376);
    /* @4605384 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4605388 constant */
    /* @4605396 cast */
    /* @4605400 call */
    GM_SITE(vm, 430, 4605400);
    /* @4605408 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4605412 string */
    /* @4605420 cast */
    /* @4605424 load */
    /* @4605432 constant */
    /* @4605436 add */
    /* @4605440 load */
    /* @4605448 constant */
    /* @4605452 add */
    /* @4605456 call */
    GM_SITE(vm, 430, 4605456);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4605464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(809)));
    /* @4605468 string */
    /* @4605476 cast */
    /* @4605480 load */
    /* @4605488 constant */
    /* @4605492 add */
    /* @4605496 load */
    /* @4605504 constant */
    /* @4605508 add */
    /* @4605512 call */
    GM_SITE(vm, 430, 4605512);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4605520 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(810)));
    /* @4605524 constant */
    /* @4605528 cast */
    /* @4605532 constant */
    /* @4605536 cast */
    /* @4605540 constant */
    /* @4605544 cast */
    /* @4605548 constant */
    /* @4605560 cast */
    /* @4605564 constant */
    /* @4605576 cast */
    /* @4605580 load */
    /* @4605588 constant */
    /* @4605592 add */
    /* @4605596 load */
    /* @4605604 constant */
    /* @4605608 add */
    /* @4605612 constant */
    /* @4605616 cast */
    /* @4605620 constant */
    /* @4605624 cast */
    /* @4605628 call */
    GM_SITE(vm, 430, 4605628);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4605636 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v12, v13, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4605640 load */
    /* @4605648 constant */
    /* @4605652 cmp */
    /* @4605656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4605760;
    /* @4605660 constant */
    /* @4605664 cast */
    /* @4605668 constant */
    /* @4605672 cast */
    /* @4605676 constant */
    /* @4605680 cast */
    /* @4605684 constant */
    /* @4605696 cast */
    /* @4605700 constant */
    /* @4605712 cast */
    /* @4605716 load */
    /* @4605724 load */
    /* @4605732 constant */
    /* @4605736 cast */
    /* @4605740 constant */
    /* @4605744 cast */
    /* @4605748 call */
    GM_SITE(vm, 430, 4605748);
    /* @4605756 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4605760: ;
    /* @4605760 load */
    /* @4605768 constant */
    /* @4605772 cmp */
    /* @4605776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4606336;
    /* @4605780 constant */
    /* @4605784 constant */
    /* @4605788 load */
    /* @4605796 constant */
    /* @4605800 add */
    /* @4605804 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4605812 constant */
    /* @4605816 constant */
    /* @4605820 load */
    /* @4605828 constant */
    /* @4605832 add */
    /* @4605836 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    GM_WRITE(vm, -1, "y", v15);
    /* @4605844 constant */
    /* @4605848 cast */
    /* @4605852 constant */
    /* @4605856 cast */
    /* @4605860 constant */
    /* @4605864 cast */
    /* @4605868 constant */
    /* @4605880 cast */
    /* @4605884 constant */
    /* @4605896 cast */
    /* @4605900 load */
    /* @4605908 load */
    /* @4605916 constant */
    /* @4605920 cast */
    /* @4605924 constant */
    /* @4605928 cast */
    /* @4605932 call */
    GM_SITE(vm, 430, 4605932);
    /* @4605940 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4605944 constant */
    /* @4605948 cast */
    /* @4605952 call */
    GM_SITE(vm, 430, 4605952);
    /* @4605960 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4605964 constant */
    /* @4605972 cast */
    /* @4605976 call */
    GM_SITE(vm, 430, 4605976);
    /* @4605984 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4605988 string */
    /* @4605996 cast */
    /* @4606000 load */
    /* @4606008 constant */
    /* @4606012 add */
    /* @4606016 load */
    /* @4606024 constant */
    /* @4606028 add */
    /* @4606032 call */
    GM_SITE(vm, 430, 4606032);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4606040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(809)));
    /* @4606044 string */
    /* @4606052 cast */
    /* @4606056 load */
    /* @4606064 constant */
    /* @4606068 add */
    /* @4606072 load */
    /* @4606080 constant */
    /* @4606084 add */
    /* @4606088 call */
    GM_SITE(vm, 430, 4606088);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4606096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(810)));
    /* @4606100 constant */
    /* @4606104 cast */
    /* @4606108 constant */
    /* @4606112 cast */
    /* @4606116 constant */
    /* @4606120 cast */
    /* @4606124 constant */
    /* @4606136 cast */
    /* @4606140 constant */
    /* @4606152 cast */
    /* @4606156 load */
    /* @4606164 constant */
    /* @4606168 add */
    /* @4606172 load */
    /* @4606180 constant */
    /* @4606184 add */
    /* @4606188 constant */
    /* @4606192 cast */
    /* @4606196 constant */
    /* @4606200 cast */
    /* @4606204 call */
    GM_SITE(vm, 430, 4606204);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(19));
    /* @4606212 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4606216 load */
    /* @4606224 constant */
    /* @4606228 cmp */
    /* @4606232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4606336;
    /* @4606236 constant */
    /* @4606240 cast */
    /* @4606244 constant */
    /* @4606248 cast */
    /* @4606252 constant */
    /* @4606256 cast */
    /* @4606260 constant */
    /* @4606272 cast */
    /* @4606276 constant */
    /* @4606288 cast */
    /* @4606292 load */
    /* @4606300 load */
    /* @4606308 constant */
    /* @4606312 cast */
    /* @4606316 constant */
    /* @4606320 cast */
    /* @4606324 call */
    GM_SITE(vm, 430, 4606324);
    /* @4606332 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4606336: ;
    /* @4606336 load */
    /* @4606344 constant */
    /* @4606348 cmp */
    /* @4606352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4606912;
    /* @4606356 constant */
    /* @4606360 constant */
    /* @4606364 load */
    /* @4606372 constant */
    /* @4606376 add */
    /* @4606380 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4606388 constant */
    /* @4606392 constant */
    /* @4606396 load */
    /* @4606404 constant */
    /* @4606408 add */
    /* @4606412 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(140));
    GM_WRITE(vm, -1, "y", v23);
    /* @4606420 constant */
    /* @4606424 cast */
    /* @4606428 constant */
    /* @4606432 cast */
    /* @4606436 constant */
    /* @4606440 cast */
    /* @4606444 constant */
    /* @4606456 cast */
    /* @4606460 constant */
    /* @4606472 cast */
    /* @4606476 load */
    /* @4606484 load */
    /* @4606492 constant */
    /* @4606496 cast */
    /* @4606500 constant */
    /* @4606504 cast */
    /* @4606508 call */
    GM_SITE(vm, 430, 4606508);
    /* @4606516 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4606520 constant */
    /* @4606524 cast */
    /* @4606528 call */
    GM_SITE(vm, 430, 4606528);
    /* @4606536 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4606540 constant */
    /* @4606548 cast */
    /* @4606552 call */
    GM_SITE(vm, 430, 4606552);
    /* @4606560 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4606564 string */
    /* @4606572 cast */
    /* @4606576 load */
    /* @4606584 constant */
    /* @4606588 add */
    /* @4606592 load */
    /* @4606600 constant */
    /* @4606604 add */
    /* @4606608 call */
    GM_SITE(vm, 430, 4606608);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4606616 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(809)));
    /* @4606620 string */
    /* @4606628 cast */
    /* @4606632 load */
    /* @4606640 constant */
    /* @4606644 add */
    /* @4606648 load */
    /* @4606656 constant */
    /* @4606660 add */
    /* @4606664 call */
    GM_SITE(vm, 430, 4606664);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4606672 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(810)));
    /* @4606676 constant */
    /* @4606680 cast */
    /* @4606684 constant */
    /* @4606688 cast */
    /* @4606692 constant */
    /* @4606696 cast */
    /* @4606700 constant */
    /* @4606712 cast */
    /* @4606716 constant */
    /* @4606728 cast */
    /* @4606732 load */
    /* @4606740 constant */
    /* @4606744 add */
    /* @4606748 load */
    /* @4606756 constant */
    /* @4606760 add */
    /* @4606764 constant */
    /* @4606768 cast */
    /* @4606772 constant */
    /* @4606776 cast */
    /* @4606780 call */
    GM_SITE(vm, 430, 4606780);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(19));
    /* @4606788 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v28, v29, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4606792 load */
    /* @4606800 constant */
    /* @4606804 cmp */
    /* @4606808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4606912;
    /* @4606812 constant */
    /* @4606816 cast */
    /* @4606820 constant */
    /* @4606824 cast */
    /* @4606828 constant */
    /* @4606832 cast */
    /* @4606836 constant */
    /* @4606848 cast */
    /* @4606852 constant */
    /* @4606864 cast */
    /* @4606868 load */
    /* @4606876 load */
    /* @4606884 constant */
    /* @4606888 cast */
    /* @4606892 constant */
    /* @4606896 cast */
    /* @4606900 call */
    GM_SITE(vm, 430, 4606900);
    /* @4606908 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4606912: ;
    /* @4606912 load */
    /* @4606920 constant */
    /* @4606924 cmp */
    /* @4606928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4607480;
    /* @4606932 constant */
    /* @4606936 constant */
    /* @4606940 load */
    /* @4606948 constant */
    /* @4606952 add */
    /* @4606956 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4606964 constant */
    /* @4606968 constant */
    /* @4606972 load */
    /* @4606980 constant */
    /* @4606984 add */
    /* @4606988 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    GM_WRITE(vm, -1, "y", v31);
    /* @4606996 constant */
    /* @4607000 cast */
    /* @4607004 constant */
    /* @4607008 cast */
    /* @4607012 constant */
    /* @4607016 cast */
    /* @4607020 constant */
    /* @4607032 cast */
    /* @4607036 constant */
    /* @4607048 cast */
    /* @4607052 load */
    /* @4607060 load */
    /* @4607068 constant */
    /* @4607072 cast */
    /* @4607076 constant */
    /* @4607080 cast */
    /* @4607084 call */
    GM_SITE(vm, 430, 4607084);
    /* @4607092 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4607096 constant */
    /* @4607100 cast */
    /* @4607104 call */
    GM_SITE(vm, 430, 4607104);
    /* @4607112 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4607116 constant */
    /* @4607124 cast */
    /* @4607128 call */
    GM_SITE(vm, 430, 4607128);
    /* @4607136 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4607140 string */
    /* @4607148 cast */
    /* @4607152 load */
    /* @4607160 load */
    /* @4607168 constant */
    /* @4607172 add */
    /* @4607176 call */
    GM_SITE(vm, 430, 4607176);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4607184 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(809)));
    /* @4607188 string */
    /* @4607196 cast */
    /* @4607200 load */
    /* @4607208 constant */
    /* @4607212 add */
    /* @4607216 load */
    /* @4607224 constant */
    /* @4607228 add */
    /* @4607232 call */
    GM_SITE(vm, 430, 4607232);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4607240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(810)));
    /* @4607244 constant */
    /* @4607248 cast */
    /* @4607252 constant */
    /* @4607256 cast */
    /* @4607260 constant */
    /* @4607264 cast */
    /* @4607268 constant */
    /* @4607280 cast */
    /* @4607284 constant */
    /* @4607296 cast */
    /* @4607300 load */
    /* @4607308 constant */
    /* @4607312 add */
    /* @4607316 load */
    /* @4607324 constant */
    /* @4607328 add */
    /* @4607332 constant */
    /* @4607336 cast */
    /* @4607340 constant */
    /* @4607344 cast */
    /* @4607348 call */
    GM_SITE(vm, 430, 4607348);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4607356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4607360 load */
    /* @4607368 constant */
    /* @4607372 cmp */
    /* @4607376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4607480;
    /* @4607380 constant */
    /* @4607384 cast */
    /* @4607388 constant */
    /* @4607392 cast */
    /* @4607396 constant */
    /* @4607400 cast */
    /* @4607404 constant */
    /* @4607416 cast */
    /* @4607420 constant */
    /* @4607432 cast */
    /* @4607436 load */
    /* @4607444 load */
    /* @4607452 constant */
    /* @4607456 cast */
    /* @4607460 constant */
    /* @4607464 cast */
    /* @4607468 call */
    GM_SITE(vm, 430, 4607468);
    /* @4607476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4607480: ;
    /* @4607480 load */
    /* @4607488 constant */
    /* @4607492 cmp */
    /* @4607496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4608048;
    /* @4607500 constant */
    /* @4607504 constant */
    /* @4607508 load */
    /* @4607516 constant */
    /* @4607520 add */
    /* @4607524 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4607532 constant */
    /* @4607536 constant */
    /* @4607540 load */
    /* @4607548 constant */
    /* @4607552 add */
    /* @4607556 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    GM_WRITE(vm, -1, "y", v38);
    /* @4607564 constant */
    /* @4607568 cast */
    /* @4607572 constant */
    /* @4607576 cast */
    /* @4607580 constant */
    /* @4607584 cast */
    /* @4607588 constant */
    /* @4607600 cast */
    /* @4607604 constant */
    /* @4607616 cast */
    /* @4607620 load */
    /* @4607628 load */
    /* @4607636 constant */
    /* @4607640 cast */
    /* @4607644 constant */
    /* @4607648 cast */
    /* @4607652 call */
    GM_SITE(vm, 430, 4607652);
    /* @4607660 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4607664 constant */
    /* @4607668 cast */
    /* @4607672 call */
    GM_SITE(vm, 430, 4607672);
    /* @4607680 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4607684 constant */
    /* @4607692 cast */
    /* @4607696 call */
    GM_SITE(vm, 430, 4607696);
    /* @4607704 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4607708 string */
    /* @4607716 cast */
    /* @4607720 load */
    /* @4607728 load */
    /* @4607736 constant */
    /* @4607740 add */
    /* @4607744 call */
    GM_SITE(vm, 430, 4607744);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4607752 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(809)));
    /* @4607756 string */
    /* @4607764 cast */
    /* @4607768 load */
    /* @4607776 constant */
    /* @4607780 add */
    /* @4607784 load */
    /* @4607792 constant */
    /* @4607796 add */
    /* @4607800 call */
    GM_SITE(vm, 430, 4607800);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4607808 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(810)));
    /* @4607812 constant */
    /* @4607816 cast */
    /* @4607820 constant */
    /* @4607824 cast */
    /* @4607828 constant */
    /* @4607832 cast */
    /* @4607836 constant */
    /* @4607848 cast */
    /* @4607852 constant */
    /* @4607864 cast */
    /* @4607868 load */
    /* @4607876 constant */
    /* @4607880 add */
    /* @4607884 load */
    /* @4607892 constant */
    /* @4607896 add */
    /* @4607900 constant */
    /* @4607904 cast */
    /* @4607908 constant */
    /* @4607912 cast */
    /* @4607916 call */
    GM_SITE(vm, 430, 4607916);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4607924 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(150), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4607928 load */
    /* @4607936 constant */
    /* @4607940 cmp */
    /* @4607944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "energywavebought") == VAL(1)))) goto L_4608048;
    /* @4607948 constant */
    /* @4607952 cast */
    /* @4607956 constant */
    /* @4607960 cast */
    /* @4607964 constant */
    /* @4607968 cast */
    /* @4607972 constant */
    /* @4607984 cast */
    /* @4607988 constant */
    /* @4608000 cast */
    /* @4608004 load */
    /* @4608012 load */
    /* @4608020 constant */
    /* @4608024 cast */
    /* @4608028 constant */
    /* @4608032 cast */
    /* @4608036 call */
    GM_SITE(vm, 430, 4608036);
    /* @4608044 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4608048: ;
    return;
}
