/* generated from CODE 575 (gml_Object_obj_lloydtutorial3_Draw_0), source start 4870636, end 4876956. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0575(GmVM* vm) {
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
    Val v59;
    Val v60;
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val p4876940_0;
    Val v85;
    /* @4870636 constant */
    /* @4870640 load */
    /* @4870648 cast */
    /* @4870652 load */
    /* @4870660 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4870668 constant */
    /* @4870672 load */
    /* @4870680 cast */
    /* @4870684 load */
    /* @4870692 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4870700 load */
    /* @4870708 constant */
    /* @4870712 cmp */
    /* @4870716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4871244;
    /* @4870720 constant */
    /* @4870724 cast */
    /* @4870728 constant */
    /* @4870732 cast */
    /* @4870736 constant */
    /* @4870740 cast */
    /* @4870744 constant */
    /* @4870756 cast */
    /* @4870760 constant */
    /* @4870772 cast */
    /* @4870776 constant */
    /* @4870780 constant */
    /* @4870784 load */
    /* @4870792 constant */
    /* @4870796 constant */
    /* @4870800 load */
    /* @4870808 constant */
    /* @4870812 sub */
    /* @4870816 constant */
    /* @4870820 cast */
    /* @4870824 constant */
    /* @4870828 cast */
    /* @4870832 call */
    GM_SITE(vm, 575, 4870832);
    /* @4870840 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4870844 constant */
    /* @4870848 cast */
    /* @4870852 constant */
    /* @4870856 cast */
    /* @4870860 constant */
    /* @4870864 cast */
    /* @4870868 constant */
    /* @4870872 cast */
    /* @4870876 constant */
    /* @4870880 cast */
    /* @4870884 constant */
    /* @4870888 load */
    /* @4870896 cast */
    /* @4870900 load */
    /* @4870908 constant */
    /* @4870912 add */
    /* @4870916 constant */
    /* @4870920 load */
    /* @4870928 cast */
    /* @4870932 load */
    /* @4870940 constant */
    /* @4870944 add */
    /* @4870948 constant */
    /* @4870952 cast */
    /* @4870956 constant */
    /* @4870960 cast */
    /* @4870964 call */
    GM_SITE(vm, 575, 4870964);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4870972 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4870976 constant */
    /* @4870980 cast */
    /* @4870984 constant */
    /* @4870988 cast */
    /* @4870992 constant */
    /* @4870996 cast */
    /* @4871000 constant */
    /* @4871004 cast */
    /* @4871008 constant */
    /* @4871012 cast */
    /* @4871016 constant */
    /* @4871020 load */
    /* @4871028 cast */
    /* @4871032 load */
    /* @4871040 constant */
    /* @4871044 add */
    /* @4871048 constant */
    /* @4871052 load */
    /* @4871060 cast */
    /* @4871064 load */
    /* @4871072 constant */
    /* @4871076 add */
    /* @4871080 constant */
    /* @4871084 cast */
    /* @4871088 constant */
    /* @4871092 cast */
    /* @4871096 call */
    GM_SITE(vm, 575, 4871096);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4871104 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4871108 load */
    /* @4871116 constant */
    /* @4871120 cmp */
    /* @4871124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4871244;
    /* @4871128 constant */
    /* @4871132 cast */
    /* @4871136 call */
    GM_SITE(vm, 575, 4871136);
    /* @4871144 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4871148 constant */
    /* @4871156 cast */
    /* @4871160 call */
    GM_SITE(vm, 575, 4871160);
    /* @4871168 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4871172 string */
    /* @4871180 cast */
    /* @4871184 constant */
    /* @4871188 constant */
    /* @4871192 load */
    /* @4871200 constant */
    /* @4871204 add */
    /* @4871208 constant */
    /* @4871212 constant */
    /* @4871216 load */
    /* @4871224 constant */
    /* @4871228 add */
    /* @4871232 call */
    GM_SITE(vm, 575, 4871232);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4871240 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4871244: ;
    /* @4871244 load */
    /* @4871252 constant */
    /* @4871256 cmp */
    /* @4871260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4871788;
    /* @4871264 constant */
    /* @4871268 cast */
    /* @4871272 constant */
    /* @4871276 cast */
    /* @4871280 constant */
    /* @4871284 cast */
    /* @4871288 constant */
    /* @4871300 cast */
    /* @4871304 constant */
    /* @4871316 cast */
    /* @4871320 constant */
    /* @4871324 constant */
    /* @4871328 load */
    /* @4871336 constant */
    /* @4871340 constant */
    /* @4871344 load */
    /* @4871352 constant */
    /* @4871356 sub */
    /* @4871360 constant */
    /* @4871364 cast */
    /* @4871368 constant */
    /* @4871372 cast */
    /* @4871376 call */
    GM_SITE(vm, 575, 4871376);
    /* @4871384 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4871388 constant */
    /* @4871392 cast */
    /* @4871396 constant */
    /* @4871400 cast */
    /* @4871404 constant */
    /* @4871408 cast */
    /* @4871412 constant */
    /* @4871416 cast */
    /* @4871420 constant */
    /* @4871424 cast */
    /* @4871428 constant */
    /* @4871432 load */
    /* @4871440 cast */
    /* @4871444 load */
    /* @4871452 constant */
    /* @4871456 add */
    /* @4871460 constant */
    /* @4871464 load */
    /* @4871472 cast */
    /* @4871476 load */
    /* @4871484 constant */
    /* @4871488 add */
    /* @4871492 constant */
    /* @4871496 cast */
    /* @4871500 constant */
    /* @4871504 cast */
    /* @4871508 call */
    GM_SITE(vm, 575, 4871508);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4871516 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4871520 constant */
    /* @4871524 cast */
    /* @4871528 constant */
    /* @4871532 cast */
    /* @4871536 constant */
    /* @4871540 cast */
    /* @4871544 constant */
    /* @4871548 cast */
    /* @4871552 constant */
    /* @4871556 cast */
    /* @4871560 constant */
    /* @4871564 load */
    /* @4871572 cast */
    /* @4871576 load */
    /* @4871584 constant */
    /* @4871588 add */
    /* @4871592 constant */
    /* @4871596 load */
    /* @4871604 cast */
    /* @4871608 load */
    /* @4871616 constant */
    /* @4871620 add */
    /* @4871624 constant */
    /* @4871628 cast */
    /* @4871632 constant */
    /* @4871636 cast */
    /* @4871640 call */
    GM_SITE(vm, 575, 4871640);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4871648 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4871652 load */
    /* @4871660 constant */
    /* @4871664 cmp */
    /* @4871668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4871788;
    /* @4871672 constant */
    /* @4871676 cast */
    /* @4871680 call */
    GM_SITE(vm, 575, 4871680);
    /* @4871688 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4871692 constant */
    /* @4871700 cast */
    /* @4871704 call */
    GM_SITE(vm, 575, 4871704);
    /* @4871712 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4871716 string */
    /* @4871724 cast */
    /* @4871728 constant */
    /* @4871732 constant */
    /* @4871736 load */
    /* @4871744 constant */
    /* @4871748 add */
    /* @4871752 constant */
    /* @4871756 constant */
    /* @4871760 load */
    /* @4871768 constant */
    /* @4871772 add */
    /* @4871776 call */
    GM_SITE(vm, 575, 4871776);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4871784 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4871788: ;
    /* @4871788 load */
    /* @4871796 constant */
    /* @4871800 cmp */
    /* @4871804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4872332;
    /* @4871808 constant */
    /* @4871812 cast */
    /* @4871816 constant */
    /* @4871820 cast */
    /* @4871824 constant */
    /* @4871828 cast */
    /* @4871832 constant */
    /* @4871844 cast */
    /* @4871848 constant */
    /* @4871860 cast */
    /* @4871864 constant */
    /* @4871868 constant */
    /* @4871872 load */
    /* @4871880 constant */
    /* @4871884 constant */
    /* @4871888 load */
    /* @4871896 constant */
    /* @4871900 sub */
    /* @4871904 constant */
    /* @4871908 cast */
    /* @4871912 constant */
    /* @4871916 cast */
    /* @4871920 call */
    GM_SITE(vm, 575, 4871920);
    /* @4871928 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4871932 constant */
    /* @4871936 cast */
    /* @4871940 constant */
    /* @4871944 cast */
    /* @4871948 constant */
    /* @4871952 cast */
    /* @4871956 constant */
    /* @4871960 cast */
    /* @4871964 constant */
    /* @4871968 cast */
    /* @4871972 constant */
    /* @4871976 load */
    /* @4871984 cast */
    /* @4871988 load */
    /* @4871996 constant */
    /* @4872000 add */
    /* @4872004 constant */
    /* @4872008 load */
    /* @4872016 cast */
    /* @4872020 load */
    /* @4872028 constant */
    /* @4872032 add */
    /* @4872036 constant */
    /* @4872040 cast */
    /* @4872044 constant */
    /* @4872048 cast */
    /* @4872052 call */
    GM_SITE(vm, 575, 4872052);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4872060 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4872064 constant */
    /* @4872068 cast */
    /* @4872072 constant */
    /* @4872076 cast */
    /* @4872080 constant */
    /* @4872084 cast */
    /* @4872088 constant */
    /* @4872092 cast */
    /* @4872096 constant */
    /* @4872100 cast */
    /* @4872104 constant */
    /* @4872108 load */
    /* @4872116 cast */
    /* @4872120 load */
    /* @4872128 constant */
    /* @4872132 add */
    /* @4872136 constant */
    /* @4872140 load */
    /* @4872148 cast */
    /* @4872152 load */
    /* @4872160 constant */
    /* @4872164 add */
    /* @4872168 constant */
    /* @4872172 cast */
    /* @4872176 constant */
    /* @4872180 cast */
    /* @4872184 call */
    GM_SITE(vm, 575, 4872184);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4872192 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4872196 load */
    /* @4872204 constant */
    /* @4872208 cmp */
    /* @4872212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4872332;
    /* @4872216 constant */
    /* @4872220 cast */
    /* @4872224 call */
    GM_SITE(vm, 575, 4872224);
    /* @4872232 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4872236 constant */
    /* @4872244 cast */
    /* @4872248 call */
    GM_SITE(vm, 575, 4872248);
    /* @4872256 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4872260 string */
    /* @4872268 cast */
    /* @4872272 constant */
    /* @4872276 constant */
    /* @4872280 load */
    /* @4872288 constant */
    /* @4872292 add */
    /* @4872296 constant */
    /* @4872300 constant */
    /* @4872304 load */
    /* @4872312 constant */
    /* @4872316 add */
    /* @4872320 call */
    GM_SITE(vm, 575, 4872320);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4872328 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4872332: ;
    /* @4872332 load */
    /* @4872340 constant */
    /* @4872344 cmp */
    /* @4872348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4872876;
    /* @4872352 constant */
    /* @4872356 cast */
    /* @4872360 constant */
    /* @4872364 cast */
    /* @4872368 constant */
    /* @4872372 cast */
    /* @4872376 constant */
    /* @4872388 cast */
    /* @4872392 constant */
    /* @4872404 cast */
    /* @4872408 constant */
    /* @4872412 constant */
    /* @4872416 load */
    /* @4872424 constant */
    /* @4872428 constant */
    /* @4872432 load */
    /* @4872440 constant */
    /* @4872444 sub */
    /* @4872448 constant */
    /* @4872452 cast */
    /* @4872456 constant */
    /* @4872460 cast */
    /* @4872464 call */
    GM_SITE(vm, 575, 4872464);
    /* @4872472 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4872476 constant */
    /* @4872480 cast */
    /* @4872484 constant */
    /* @4872488 cast */
    /* @4872492 constant */
    /* @4872496 cast */
    /* @4872500 constant */
    /* @4872504 cast */
    /* @4872508 constant */
    /* @4872512 cast */
    /* @4872516 constant */
    /* @4872520 load */
    /* @4872528 cast */
    /* @4872532 load */
    /* @4872540 constant */
    /* @4872544 add */
    /* @4872548 constant */
    /* @4872552 load */
    /* @4872560 cast */
    /* @4872564 load */
    /* @4872572 constant */
    /* @4872576 add */
    /* @4872580 constant */
    /* @4872584 cast */
    /* @4872588 constant */
    /* @4872592 cast */
    /* @4872596 call */
    GM_SITE(vm, 575, 4872596);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4872604 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4872608 constant */
    /* @4872612 cast */
    /* @4872616 constant */
    /* @4872620 cast */
    /* @4872624 constant */
    /* @4872628 cast */
    /* @4872632 constant */
    /* @4872636 cast */
    /* @4872640 constant */
    /* @4872644 cast */
    /* @4872648 constant */
    /* @4872652 load */
    /* @4872660 cast */
    /* @4872664 load */
    /* @4872672 constant */
    /* @4872676 add */
    /* @4872680 constant */
    /* @4872684 load */
    /* @4872692 cast */
    /* @4872696 load */
    /* @4872704 constant */
    /* @4872708 add */
    /* @4872712 constant */
    /* @4872716 cast */
    /* @4872720 constant */
    /* @4872724 cast */
    /* @4872728 call */
    GM_SITE(vm, 575, 4872728);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4872736 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4872740 load */
    /* @4872748 constant */
    /* @4872752 cmp */
    /* @4872756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4872876;
    /* @4872760 constant */
    /* @4872764 cast */
    /* @4872768 call */
    GM_SITE(vm, 575, 4872768);
    /* @4872776 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4872780 constant */
    /* @4872788 cast */
    /* @4872792 call */
    GM_SITE(vm, 575, 4872792);
    /* @4872800 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4872804 string */
    /* @4872812 cast */
    /* @4872816 constant */
    /* @4872820 constant */
    /* @4872824 load */
    /* @4872832 constant */
    /* @4872836 add */
    /* @4872840 constant */
    /* @4872844 constant */
    /* @4872848 load */
    /* @4872856 constant */
    /* @4872860 add */
    /* @4872864 call */
    GM_SITE(vm, 575, 4872864);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4872872 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4872876: ;
    /* @4872876 load */
    /* @4872884 constant */
    /* @4872888 cmp */
    /* @4872892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4873420;
    /* @4872896 constant */
    /* @4872900 cast */
    /* @4872904 constant */
    /* @4872908 cast */
    /* @4872912 constant */
    /* @4872916 cast */
    /* @4872920 constant */
    /* @4872932 cast */
    /* @4872936 constant */
    /* @4872948 cast */
    /* @4872952 constant */
    /* @4872956 constant */
    /* @4872960 load */
    /* @4872968 constant */
    /* @4872972 constant */
    /* @4872976 load */
    /* @4872984 constant */
    /* @4872988 sub */
    /* @4872992 constant */
    /* @4872996 cast */
    /* @4873000 constant */
    /* @4873004 cast */
    /* @4873008 call */
    GM_SITE(vm, 575, 4873008);
    /* @4873016 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4873020 constant */
    /* @4873024 cast */
    /* @4873028 constant */
    /* @4873032 cast */
    /* @4873036 constant */
    /* @4873040 cast */
    /* @4873044 constant */
    /* @4873048 cast */
    /* @4873052 constant */
    /* @4873056 cast */
    /* @4873060 constant */
    /* @4873064 load */
    /* @4873072 cast */
    /* @4873076 load */
    /* @4873084 constant */
    /* @4873088 add */
    /* @4873092 constant */
    /* @4873096 load */
    /* @4873104 cast */
    /* @4873108 load */
    /* @4873116 constant */
    /* @4873120 add */
    /* @4873124 constant */
    /* @4873128 cast */
    /* @4873132 constant */
    /* @4873136 cast */
    /* @4873140 call */
    GM_SITE(vm, 575, 4873140);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4873148 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4873152 constant */
    /* @4873156 cast */
    /* @4873160 constant */
    /* @4873164 cast */
    /* @4873168 constant */
    /* @4873172 cast */
    /* @4873176 constant */
    /* @4873180 cast */
    /* @4873184 constant */
    /* @4873188 cast */
    /* @4873192 constant */
    /* @4873196 load */
    /* @4873204 cast */
    /* @4873208 load */
    /* @4873216 constant */
    /* @4873220 add */
    /* @4873224 constant */
    /* @4873228 load */
    /* @4873236 cast */
    /* @4873240 load */
    /* @4873248 constant */
    /* @4873252 add */
    /* @4873256 constant */
    /* @4873260 cast */
    /* @4873264 constant */
    /* @4873268 cast */
    /* @4873272 call */
    GM_SITE(vm, 575, 4873272);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4873280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4873284 load */
    /* @4873292 constant */
    /* @4873296 cmp */
    /* @4873300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4873420;
    /* @4873304 constant */
    /* @4873308 cast */
    /* @4873312 call */
    GM_SITE(vm, 575, 4873312);
    /* @4873320 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4873324 constant */
    /* @4873332 cast */
    /* @4873336 call */
    GM_SITE(vm, 575, 4873336);
    /* @4873344 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4873348 string */
    /* @4873356 cast */
    /* @4873360 constant */
    /* @4873364 constant */
    /* @4873368 load */
    /* @4873376 constant */
    /* @4873380 add */
    /* @4873384 constant */
    /* @4873388 constant */
    /* @4873392 load */
    /* @4873400 constant */
    /* @4873404 add */
    /* @4873408 call */
    GM_SITE(vm, 575, 4873408);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4873416 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4873420: ;
    /* @4873420 load */
    /* @4873428 constant */
    /* @4873432 cmp */
    /* @4873436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4873964;
    /* @4873440 constant */
    /* @4873444 cast */
    /* @4873448 constant */
    /* @4873452 cast */
    /* @4873456 constant */
    /* @4873460 cast */
    /* @4873464 constant */
    /* @4873476 cast */
    /* @4873480 constant */
    /* @4873492 cast */
    /* @4873496 constant */
    /* @4873500 constant */
    /* @4873504 load */
    /* @4873512 constant */
    /* @4873516 constant */
    /* @4873520 load */
    /* @4873528 constant */
    /* @4873532 sub */
    /* @4873536 constant */
    /* @4873540 cast */
    /* @4873544 constant */
    /* @4873548 cast */
    /* @4873552 call */
    GM_SITE(vm, 575, 4873552);
    /* @4873560 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4873564 constant */
    /* @4873568 cast */
    /* @4873572 constant */
    /* @4873576 cast */
    /* @4873580 constant */
    /* @4873584 cast */
    /* @4873588 constant */
    /* @4873592 cast */
    /* @4873596 constant */
    /* @4873600 cast */
    /* @4873604 constant */
    /* @4873608 load */
    /* @4873616 cast */
    /* @4873620 load */
    /* @4873628 constant */
    /* @4873632 add */
    /* @4873636 constant */
    /* @4873640 load */
    /* @4873648 cast */
    /* @4873652 load */
    /* @4873660 constant */
    /* @4873664 add */
    /* @4873668 constant */
    /* @4873672 cast */
    /* @4873676 constant */
    /* @4873680 cast */
    /* @4873684 call */
    GM_SITE(vm, 575, 4873684);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4873692 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4873696 constant */
    /* @4873700 cast */
    /* @4873704 constant */
    /* @4873708 cast */
    /* @4873712 constant */
    /* @4873716 cast */
    /* @4873720 constant */
    /* @4873724 cast */
    /* @4873728 constant */
    /* @4873732 cast */
    /* @4873736 constant */
    /* @4873740 load */
    /* @4873748 cast */
    /* @4873752 load */
    /* @4873760 constant */
    /* @4873764 add */
    /* @4873768 constant */
    /* @4873772 load */
    /* @4873780 cast */
    /* @4873784 load */
    /* @4873792 constant */
    /* @4873796 add */
    /* @4873800 constant */
    /* @4873804 cast */
    /* @4873808 constant */
    /* @4873812 cast */
    /* @4873816 call */
    GM_SITE(vm, 575, 4873816);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4873824 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4873828 load */
    /* @4873836 constant */
    /* @4873840 cmp */
    /* @4873844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4873964;
    /* @4873848 constant */
    /* @4873852 cast */
    /* @4873856 call */
    GM_SITE(vm, 575, 4873856);
    /* @4873864 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4873868 constant */
    /* @4873876 cast */
    /* @4873880 call */
    GM_SITE(vm, 575, 4873880);
    /* @4873888 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4873892 string */
    /* @4873900 cast */
    /* @4873904 constant */
    /* @4873908 constant */
    /* @4873912 load */
    /* @4873920 constant */
    /* @4873924 add */
    /* @4873928 constant */
    /* @4873932 constant */
    /* @4873936 load */
    /* @4873944 constant */
    /* @4873948 add */
    /* @4873952 call */
    GM_SITE(vm, 575, 4873952);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4873960 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4873964: ;
    /* @4873964 load */
    /* @4873972 constant */
    /* @4873976 cmp */
    /* @4873980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4875424;
    /* @4873984 load */
    /* @4873992 constant */
    /* @4873996 cmp */
    /* @4874000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4874224;
    /* @4874004 constant */
    /* @4874008 cast */
    /* @4874012 call */
    GM_SITE(vm, 575, 4874012);
    /* @4874020 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4874024 constant */
    /* @4874032 cast */
    /* @4874036 call */
    GM_SITE(vm, 575, 4874036);
    /* @4874044 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4874048 string */
    /* @4874056 cast */
    /* @4874060 constant */
    /* @4874064 load */
    /* @4874072 cast */
    /* @4874076 load */
    /* @4874084 constant */
    /* @4874088 add */
    /* @4874092 constant */
    /* @4874096 load */
    /* @4874104 cast */
    /* @4874108 load */
    /* @4874116 constant */
    /* @4874120 add */
    /* @4874124 call */
    GM_SITE(vm, 575, 4874124);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4874132 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1054)));
    /* @4874136 string */
    /* @4874144 cast */
    /* @4874148 constant */
    /* @4874152 load */
    /* @4874160 cast */
    /* @4874164 load */
    /* @4874172 constant */
    /* @4874176 add */
    /* @4874180 constant */
    /* @4874184 load */
    /* @4874192 cast */
    /* @4874196 load */
    /* @4874204 constant */
    /* @4874208 add */
    /* @4874212 call */
    GM_SITE(vm, 575, 4874212);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4874220 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1055)));
    L_4874224: ;
    /* @4874224 load */
    /* @4874232 constant */
    /* @4874236 cmp */
    /* @4874240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4874464;
    /* @4874244 constant */
    /* @4874248 cast */
    /* @4874252 call */
    GM_SITE(vm, 575, 4874252);
    /* @4874260 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4874264 constant */
    /* @4874272 cast */
    /* @4874276 call */
    GM_SITE(vm, 575, 4874276);
    /* @4874284 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4874288 string */
    /* @4874296 cast */
    /* @4874300 constant */
    /* @4874304 load */
    /* @4874312 cast */
    /* @4874316 load */
    /* @4874324 constant */
    /* @4874328 add */
    /* @4874332 constant */
    /* @4874336 load */
    /* @4874344 cast */
    /* @4874348 load */
    /* @4874356 constant */
    /* @4874360 add */
    /* @4874364 call */
    GM_SITE(vm, 575, 4874364);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4874372 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1054)));
    /* @4874376 string */
    /* @4874384 cast */
    /* @4874388 constant */
    /* @4874392 load */
    /* @4874400 cast */
    /* @4874404 load */
    /* @4874412 constant */
    /* @4874416 add */
    /* @4874420 constant */
    /* @4874424 load */
    /* @4874432 cast */
    /* @4874436 load */
    /* @4874444 constant */
    /* @4874448 add */
    /* @4874452 call */
    GM_SITE(vm, 575, 4874452);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4874460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1055)));
    L_4874464: ;
    /* @4874464 load */
    /* @4874472 constant */
    /* @4874476 cmp */
    /* @4874480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4874704;
    /* @4874484 constant */
    /* @4874488 cast */
    /* @4874492 call */
    GM_SITE(vm, 575, 4874492);
    /* @4874500 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4874504 constant */
    /* @4874512 cast */
    /* @4874516 call */
    GM_SITE(vm, 575, 4874516);
    /* @4874524 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4874528 string */
    /* @4874536 cast */
    /* @4874540 constant */
    /* @4874544 load */
    /* @4874552 cast */
    /* @4874556 load */
    /* @4874564 constant */
    /* @4874568 add */
    /* @4874572 constant */
    /* @4874576 load */
    /* @4874584 cast */
    /* @4874588 load */
    /* @4874596 constant */
    /* @4874600 add */
    /* @4874604 call */
    GM_SITE(vm, 575, 4874604);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4874612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1054)));
    /* @4874616 string */
    /* @4874624 cast */
    /* @4874628 constant */
    /* @4874632 load */
    /* @4874640 cast */
    /* @4874644 load */
    /* @4874652 constant */
    /* @4874656 add */
    /* @4874660 constant */
    /* @4874664 load */
    /* @4874672 cast */
    /* @4874676 load */
    /* @4874684 constant */
    /* @4874688 add */
    /* @4874692 call */
    GM_SITE(vm, 575, 4874692);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4874700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1055)));
    L_4874704: ;
    /* @4874704 load */
    /* @4874712 constant */
    /* @4874716 cmp */
    /* @4874720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4874944;
    /* @4874724 constant */
    /* @4874728 cast */
    /* @4874732 call */
    GM_SITE(vm, 575, 4874732);
    /* @4874740 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4874744 constant */
    /* @4874752 cast */
    /* @4874756 call */
    GM_SITE(vm, 575, 4874756);
    /* @4874764 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4874768 string */
    /* @4874776 cast */
    /* @4874780 constant */
    /* @4874784 load */
    /* @4874792 cast */
    /* @4874796 load */
    /* @4874804 constant */
    /* @4874808 add */
    /* @4874812 constant */
    /* @4874816 load */
    /* @4874824 cast */
    /* @4874828 load */
    /* @4874836 constant */
    /* @4874840 add */
    /* @4874844 call */
    GM_SITE(vm, 575, 4874844);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4874852 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1054)));
    /* @4874856 string */
    /* @4874864 cast */
    /* @4874868 constant */
    /* @4874872 load */
    /* @4874880 cast */
    /* @4874884 load */
    /* @4874892 constant */
    /* @4874896 add */
    /* @4874900 constant */
    /* @4874904 load */
    /* @4874912 cast */
    /* @4874916 load */
    /* @4874924 constant */
    /* @4874928 add */
    /* @4874932 call */
    GM_SITE(vm, 575, 4874932);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4874940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1055)));
    L_4874944: ;
    /* @4874944 load */
    /* @4874952 constant */
    /* @4874956 cmp */
    /* @4874960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4875184;
    /* @4874964 constant */
    /* @4874968 cast */
    /* @4874972 call */
    GM_SITE(vm, 575, 4874972);
    /* @4874980 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4874984 constant */
    /* @4874992 cast */
    /* @4874996 call */
    GM_SITE(vm, 575, 4874996);
    /* @4875004 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4875008 string */
    /* @4875016 cast */
    /* @4875020 constant */
    /* @4875024 load */
    /* @4875032 cast */
    /* @4875036 load */
    /* @4875044 constant */
    /* @4875048 add */
    /* @4875052 constant */
    /* @4875056 load */
    /* @4875064 cast */
    /* @4875068 load */
    /* @4875076 constant */
    /* @4875080 add */
    /* @4875084 call */
    GM_SITE(vm, 575, 4875084);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4875092 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1054)));
    /* @4875096 string */
    /* @4875104 cast */
    /* @4875108 constant */
    /* @4875112 load */
    /* @4875120 cast */
    /* @4875124 load */
    /* @4875132 constant */
    /* @4875136 add */
    /* @4875140 constant */
    /* @4875144 load */
    /* @4875152 cast */
    /* @4875156 load */
    /* @4875164 constant */
    /* @4875168 add */
    /* @4875172 call */
    GM_SITE(vm, 575, 4875172);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4875180 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1055)));
    L_4875184: ;
    /* @4875184 load */
    /* @4875192 constant */
    /* @4875196 cmp */
    /* @4875200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4875424;
    /* @4875204 constant */
    /* @4875208 cast */
    /* @4875212 call */
    GM_SITE(vm, 575, 4875212);
    /* @4875220 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4875224 constant */
    /* @4875232 cast */
    /* @4875236 call */
    GM_SITE(vm, 575, 4875236);
    /* @4875244 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4875248 string */
    /* @4875256 cast */
    /* @4875260 constant */
    /* @4875264 load */
    /* @4875272 cast */
    /* @4875276 load */
    /* @4875284 constant */
    /* @4875288 add */
    /* @4875292 constant */
    /* @4875296 load */
    /* @4875304 cast */
    /* @4875308 load */
    /* @4875316 constant */
    /* @4875320 add */
    /* @4875324 call */
    GM_SITE(vm, 575, 4875324);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4875332 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1054)));
    /* @4875336 string */
    /* @4875344 cast */
    /* @4875348 constant */
    /* @4875352 load */
    /* @4875360 cast */
    /* @4875364 load */
    /* @4875372 constant */
    /* @4875376 add */
    /* @4875380 constant */
    /* @4875384 load */
    /* @4875392 cast */
    /* @4875396 load */
    /* @4875404 constant */
    /* @4875408 add */
    /* @4875412 call */
    GM_SITE(vm, 575, 4875412);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4875420 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1055)));
    L_4875424: ;
    /* @4875424 load */
    /* @4875432 constant */
    /* @4875436 cmp */
    /* @4875440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4876884;
    /* @4875444 load */
    /* @4875452 constant */
    /* @4875456 cmp */
    /* @4875460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4875684;
    /* @4875464 constant */
    /* @4875468 cast */
    /* @4875472 call */
    GM_SITE(vm, 575, 4875472);
    /* @4875480 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4875484 constant */
    /* @4875492 cast */
    /* @4875496 call */
    GM_SITE(vm, 575, 4875496);
    /* @4875504 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4875508 string */
    /* @4875516 cast */
    /* @4875520 constant */
    /* @4875524 load */
    /* @4875532 cast */
    /* @4875536 load */
    /* @4875544 constant */
    /* @4875548 add */
    /* @4875552 constant */
    /* @4875556 load */
    /* @4875564 cast */
    /* @4875568 load */
    /* @4875576 constant */
    /* @4875580 add */
    /* @4875584 call */
    GM_SITE(vm, 575, 4875584);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4875592 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1056)));
    /* @4875596 string */
    /* @4875604 cast */
    /* @4875608 constant */
    /* @4875612 load */
    /* @4875620 cast */
    /* @4875624 load */
    /* @4875632 constant */
    /* @4875636 add */
    /* @4875640 constant */
    /* @4875644 load */
    /* @4875652 cast */
    /* @4875656 load */
    /* @4875664 constant */
    /* @4875668 add */
    /* @4875672 call */
    GM_SITE(vm, 575, 4875672);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4875680 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1057)));
    L_4875684: ;
    /* @4875684 load */
    /* @4875692 constant */
    /* @4875696 cmp */
    /* @4875700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4875924;
    /* @4875704 constant */
    /* @4875708 cast */
    /* @4875712 call */
    GM_SITE(vm, 575, 4875712);
    /* @4875720 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4875724 constant */
    /* @4875732 cast */
    /* @4875736 call */
    GM_SITE(vm, 575, 4875736);
    /* @4875744 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4875748 string */
    /* @4875756 cast */
    /* @4875760 constant */
    /* @4875764 load */
    /* @4875772 cast */
    /* @4875776 load */
    /* @4875784 constant */
    /* @4875788 add */
    /* @4875792 constant */
    /* @4875796 load */
    /* @4875804 cast */
    /* @4875808 load */
    /* @4875816 constant */
    /* @4875820 add */
    /* @4875824 call */
    GM_SITE(vm, 575, 4875824);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4875832 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1056)));
    /* @4875836 string */
    /* @4875844 cast */
    /* @4875848 constant */
    /* @4875852 load */
    /* @4875860 cast */
    /* @4875864 load */
    /* @4875872 constant */
    /* @4875876 add */
    /* @4875880 constant */
    /* @4875884 load */
    /* @4875892 cast */
    /* @4875896 load */
    /* @4875904 constant */
    /* @4875908 add */
    /* @4875912 call */
    GM_SITE(vm, 575, 4875912);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4875920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1057)));
    L_4875924: ;
    /* @4875924 load */
    /* @4875932 constant */
    /* @4875936 cmp */
    /* @4875940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4876164;
    /* @4875944 constant */
    /* @4875948 cast */
    /* @4875952 call */
    GM_SITE(vm, 575, 4875952);
    /* @4875960 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4875964 constant */
    /* @4875972 cast */
    /* @4875976 call */
    GM_SITE(vm, 575, 4875976);
    /* @4875984 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4875988 string */
    /* @4875996 cast */
    /* @4876000 constant */
    /* @4876004 load */
    /* @4876012 cast */
    /* @4876016 load */
    /* @4876024 constant */
    /* @4876028 add */
    /* @4876032 constant */
    /* @4876036 load */
    /* @4876044 cast */
    /* @4876048 load */
    /* @4876056 constant */
    /* @4876060 add */
    /* @4876064 call */
    GM_SITE(vm, 575, 4876064);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4876072 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1056)));
    /* @4876076 string */
    /* @4876084 cast */
    /* @4876088 constant */
    /* @4876092 load */
    /* @4876100 cast */
    /* @4876104 load */
    /* @4876112 constant */
    /* @4876116 add */
    /* @4876120 constant */
    /* @4876124 load */
    /* @4876132 cast */
    /* @4876136 load */
    /* @4876144 constant */
    /* @4876148 add */
    /* @4876152 call */
    GM_SITE(vm, 575, 4876152);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4876160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1057)));
    L_4876164: ;
    /* @4876164 load */
    /* @4876172 constant */
    /* @4876176 cmp */
    /* @4876180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4876404;
    /* @4876184 constant */
    /* @4876188 cast */
    /* @4876192 call */
    GM_SITE(vm, 575, 4876192);
    /* @4876200 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4876204 constant */
    /* @4876212 cast */
    /* @4876216 call */
    GM_SITE(vm, 575, 4876216);
    /* @4876224 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4876228 string */
    /* @4876236 cast */
    /* @4876240 constant */
    /* @4876244 load */
    /* @4876252 cast */
    /* @4876256 load */
    /* @4876264 constant */
    /* @4876268 add */
    /* @4876272 constant */
    /* @4876276 load */
    /* @4876284 cast */
    /* @4876288 load */
    /* @4876296 constant */
    /* @4876300 add */
    /* @4876304 call */
    GM_SITE(vm, 575, 4876304);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4876312 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1056)));
    /* @4876316 string */
    /* @4876324 cast */
    /* @4876328 constant */
    /* @4876332 load */
    /* @4876340 cast */
    /* @4876344 load */
    /* @4876352 constant */
    /* @4876356 add */
    /* @4876360 constant */
    /* @4876364 load */
    /* @4876372 cast */
    /* @4876376 load */
    /* @4876384 constant */
    /* @4876388 add */
    /* @4876392 call */
    GM_SITE(vm, 575, 4876392);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4876400 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1057)));
    L_4876404: ;
    /* @4876404 load */
    /* @4876412 constant */
    /* @4876416 cmp */
    /* @4876420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4876644;
    /* @4876424 constant */
    /* @4876428 cast */
    /* @4876432 call */
    GM_SITE(vm, 575, 4876432);
    /* @4876440 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4876444 constant */
    /* @4876452 cast */
    /* @4876456 call */
    GM_SITE(vm, 575, 4876456);
    /* @4876464 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4876468 string */
    /* @4876476 cast */
    /* @4876480 constant */
    /* @4876484 load */
    /* @4876492 cast */
    /* @4876496 load */
    /* @4876504 constant */
    /* @4876508 add */
    /* @4876512 constant */
    /* @4876516 load */
    /* @4876524 cast */
    /* @4876528 load */
    /* @4876536 constant */
    /* @4876540 add */
    /* @4876544 call */
    GM_SITE(vm, 575, 4876544);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4876552 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1056)));
    /* @4876556 string */
    /* @4876564 cast */
    /* @4876568 constant */
    /* @4876572 load */
    /* @4876580 cast */
    /* @4876584 load */
    /* @4876592 constant */
    /* @4876596 add */
    /* @4876600 constant */
    /* @4876604 load */
    /* @4876612 cast */
    /* @4876616 load */
    /* @4876624 constant */
    /* @4876628 add */
    /* @4876632 call */
    GM_SITE(vm, 575, 4876632);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4876640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1057)));
    L_4876644: ;
    /* @4876644 load */
    /* @4876652 constant */
    /* @4876656 cmp */
    /* @4876660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4876884;
    /* @4876664 constant */
    /* @4876668 cast */
    /* @4876672 call */
    GM_SITE(vm, 575, 4876672);
    /* @4876680 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4876684 constant */
    /* @4876692 cast */
    /* @4876696 call */
    GM_SITE(vm, 575, 4876696);
    /* @4876704 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4876708 string */
    /* @4876716 cast */
    /* @4876720 constant */
    /* @4876724 load */
    /* @4876732 cast */
    /* @4876736 load */
    /* @4876744 constant */
    /* @4876748 add */
    /* @4876752 constant */
    /* @4876756 load */
    /* @4876764 cast */
    /* @4876768 load */
    /* @4876776 constant */
    /* @4876780 add */
    /* @4876784 call */
    GM_SITE(vm, 575, 4876784);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4876792 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1056)));
    /* @4876796 string */
    /* @4876804 cast */
    /* @4876808 constant */
    /* @4876812 load */
    /* @4876820 cast */
    /* @4876824 load */
    /* @4876832 constant */
    /* @4876836 add */
    /* @4876840 constant */
    /* @4876844 load */
    /* @4876852 cast */
    /* @4876856 load */
    /* @4876864 constant */
    /* @4876868 add */
    /* @4876872 call */
    GM_SITE(vm, 575, 4876872);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4876880 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1057)));
    L_4876884: ;
    /* @4876884 load */
    /* @4876892 constant */
    /* @4876896 cmp */
    /* @4876900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4876936;
    /* @4876904 constant */
    /* @4876908 cast */
    /* @4876912 constant */
    /* @4876916 cast */
    /* @4876920 call */
    GM_SITE(vm, 575, 4876920);
    /* @4876928 cast */
    /* @4876932 b */
    v85 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4876940_0 = v85;
    goto L_4876940;
    L_4876936: ;
    /* @4876936 constant */
    p4876940_0 = VAL(0);
    L_4876940: ;
    /* @4876940 bf */
    if (!TRUTH(p4876940_0)) goto L_4876956;
    /* @4876944 call */
    GM_SITE(vm, 575, 4876944);
    /* @4876952 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4876956: ;
    return;
}
