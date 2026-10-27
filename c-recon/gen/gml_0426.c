/* generated from CODE 426 (gml_Object_obj_swordupgrade2_Draw_0), source start 4597620, end 4600972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0426(GmVM* vm) {
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
    /* @4597620 load */
    /* @4597628 constant */
    /* @4597632 cmp */
    /* @4597636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4598124;
    /* @4597640 constant */
    /* @4597644 cast */
    /* @4597648 constant */
    /* @4597652 cast */
    /* @4597656 constant */
    /* @4597660 cast */
    /* @4597664 constant */
    /* @4597676 cast */
    /* @4597680 constant */
    /* @4597692 cast */
    /* @4597696 load */
    /* @4597704 load */
    /* @4597712 constant */
    /* @4597716 cast */
    /* @4597720 constant */
    /* @4597724 cast */
    /* @4597728 call */
    GM_SITE(vm, 426, 4597728);
    /* @4597736 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4597740 constant */
    /* @4597744 cast */
    /* @4597748 call */
    GM_SITE(vm, 426, 4597748);
    /* @4597756 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4597760 constant */
    /* @4597768 cast */
    /* @4597772 call */
    GM_SITE(vm, 426, 4597772);
    /* @4597780 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4597784 string */
    /* @4597792 cast */
    /* @4597796 load */
    /* @4597804 load */
    /* @4597812 constant */
    /* @4597816 add */
    /* @4597820 call */
    GM_SITE(vm, 426, 4597820);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4597828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(805)));
    /* @4597832 string */
    /* @4597840 cast */
    /* @4597844 load */
    /* @4597852 constant */
    /* @4597856 add */
    /* @4597860 load */
    /* @4597868 constant */
    /* @4597872 add */
    /* @4597876 call */
    GM_SITE(vm, 426, 4597876);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4597884 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(806)));
    /* @4597888 constant */
    /* @4597892 cast */
    /* @4597896 constant */
    /* @4597900 cast */
    /* @4597904 constant */
    /* @4597908 cast */
    /* @4597912 constant */
    /* @4597924 cast */
    /* @4597928 constant */
    /* @4597940 cast */
    /* @4597944 load */
    /* @4597952 constant */
    /* @4597956 add */
    /* @4597960 load */
    /* @4597968 constant */
    /* @4597972 add */
    /* @4597976 constant */
    /* @4597980 cast */
    /* @4597984 constant */
    /* @4597988 cast */
    /* @4597992 call */
    GM_SITE(vm, 426, 4597992);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4598000 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4598004 load */
    /* @4598012 constant */
    /* @4598016 cmp */
    /* @4598020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4598124;
    /* @4598024 constant */
    /* @4598028 cast */
    /* @4598032 constant */
    /* @4598036 cast */
    /* @4598040 constant */
    /* @4598044 cast */
    /* @4598048 constant */
    /* @4598060 cast */
    /* @4598064 constant */
    /* @4598076 cast */
    /* @4598080 load */
    /* @4598088 load */
    /* @4598096 constant */
    /* @4598100 cast */
    /* @4598104 constant */
    /* @4598108 cast */
    /* @4598112 call */
    GM_SITE(vm, 426, 4598112);
    /* @4598120 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4598124: ;
    /* @4598124 load */
    /* @4598132 constant */
    /* @4598136 cmp */
    /* @4598140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4598684;
    /* @4598144 constant */
    /* @4598148 constant */
    /* @4598152 load */
    /* @4598160 constant */
    /* @4598164 add */
    /* @4598168 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4598176 constant */
    /* @4598180 constant */
    /* @4598184 load */
    /* @4598192 constant */
    /* @4598196 add */
    /* @4598200 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    GM_WRITE(vm, -1, "y", v7);
    /* @4598208 constant */
    /* @4598212 cast */
    /* @4598216 constant */
    /* @4598220 cast */
    /* @4598224 constant */
    /* @4598228 cast */
    /* @4598232 constant */
    /* @4598236 cast */
    /* @4598240 constant */
    /* @4598244 cast */
    /* @4598248 load */
    /* @4598256 load */
    /* @4598264 constant */
    /* @4598268 cast */
    /* @4598272 constant */
    /* @4598276 cast */
    /* @4598280 call */
    GM_SITE(vm, 426, 4598280);
    /* @4598288 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4598292 constant */
    /* @4598296 cast */
    /* @4598300 call */
    GM_SITE(vm, 426, 4598300);
    /* @4598308 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4598312 constant */
    /* @4598320 cast */
    /* @4598324 call */
    GM_SITE(vm, 426, 4598324);
    /* @4598332 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4598336 string */
    /* @4598344 cast */
    /* @4598348 load */
    /* @4598356 constant */
    /* @4598360 add */
    /* @4598364 load */
    /* @4598372 constant */
    /* @4598376 add */
    /* @4598380 call */
    GM_SITE(vm, 426, 4598380);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4598388 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(805)));
    /* @4598392 string */
    /* @4598400 cast */
    /* @4598404 load */
    /* @4598412 constant */
    /* @4598416 add */
    /* @4598420 load */
    /* @4598428 constant */
    /* @4598432 add */
    /* @4598436 call */
    GM_SITE(vm, 426, 4598436);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4598444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(806)));
    /* @4598448 constant */
    /* @4598452 cast */
    /* @4598456 constant */
    /* @4598460 cast */
    /* @4598464 constant */
    /* @4598468 cast */
    /* @4598472 constant */
    /* @4598484 cast */
    /* @4598488 constant */
    /* @4598500 cast */
    /* @4598504 load */
    /* @4598512 constant */
    /* @4598516 add */
    /* @4598520 load */
    /* @4598528 constant */
    /* @4598532 add */
    /* @4598536 constant */
    /* @4598540 cast */
    /* @4598544 constant */
    /* @4598548 cast */
    /* @4598552 call */
    GM_SITE(vm, 426, 4598552);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4598560 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v12, v13, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4598564 load */
    /* @4598572 constant */
    /* @4598576 cmp */
    /* @4598580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4598684;
    /* @4598584 constant */
    /* @4598588 cast */
    /* @4598592 constant */
    /* @4598596 cast */
    /* @4598600 constant */
    /* @4598604 cast */
    /* @4598608 constant */
    /* @4598620 cast */
    /* @4598624 constant */
    /* @4598636 cast */
    /* @4598640 load */
    /* @4598648 load */
    /* @4598656 constant */
    /* @4598660 cast */
    /* @4598664 constant */
    /* @4598668 cast */
    /* @4598672 call */
    GM_SITE(vm, 426, 4598672);
    /* @4598680 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4598684: ;
    /* @4598684 load */
    /* @4598692 constant */
    /* @4598696 cmp */
    /* @4598700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4599260;
    /* @4598704 constant */
    /* @4598708 constant */
    /* @4598712 load */
    /* @4598720 constant */
    /* @4598724 add */
    /* @4598728 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4598736 constant */
    /* @4598740 constant */
    /* @4598744 load */
    /* @4598752 constant */
    /* @4598756 add */
    /* @4598760 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    GM_WRITE(vm, -1, "y", v15);
    /* @4598768 constant */
    /* @4598772 cast */
    /* @4598776 constant */
    /* @4598780 cast */
    /* @4598784 constant */
    /* @4598788 cast */
    /* @4598792 constant */
    /* @4598804 cast */
    /* @4598808 constant */
    /* @4598820 cast */
    /* @4598824 load */
    /* @4598832 load */
    /* @4598840 constant */
    /* @4598844 cast */
    /* @4598848 constant */
    /* @4598852 cast */
    /* @4598856 call */
    GM_SITE(vm, 426, 4598856);
    /* @4598864 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4598868 constant */
    /* @4598872 cast */
    /* @4598876 call */
    GM_SITE(vm, 426, 4598876);
    /* @4598884 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4598888 constant */
    /* @4598896 cast */
    /* @4598900 call */
    GM_SITE(vm, 426, 4598900);
    /* @4598908 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4598912 string */
    /* @4598920 cast */
    /* @4598924 load */
    /* @4598932 constant */
    /* @4598936 add */
    /* @4598940 load */
    /* @4598948 constant */
    /* @4598952 add */
    /* @4598956 call */
    GM_SITE(vm, 426, 4598956);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4598964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(805)));
    /* @4598968 string */
    /* @4598976 cast */
    /* @4598980 load */
    /* @4598988 constant */
    /* @4598992 add */
    /* @4598996 load */
    /* @4599004 constant */
    /* @4599008 add */
    /* @4599012 call */
    GM_SITE(vm, 426, 4599012);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4599020 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(806)));
    /* @4599024 constant */
    /* @4599028 cast */
    /* @4599032 constant */
    /* @4599036 cast */
    /* @4599040 constant */
    /* @4599044 cast */
    /* @4599048 constant */
    /* @4599060 cast */
    /* @4599064 constant */
    /* @4599076 cast */
    /* @4599080 load */
    /* @4599088 constant */
    /* @4599092 add */
    /* @4599096 load */
    /* @4599104 constant */
    /* @4599108 add */
    /* @4599112 constant */
    /* @4599116 cast */
    /* @4599120 constant */
    /* @4599124 cast */
    /* @4599128 call */
    GM_SITE(vm, 426, 4599128);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4599136 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4599140 load */
    /* @4599148 constant */
    /* @4599152 cmp */
    /* @4599156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4599260;
    /* @4599160 constant */
    /* @4599164 cast */
    /* @4599168 constant */
    /* @4599172 cast */
    /* @4599176 constant */
    /* @4599180 cast */
    /* @4599184 constant */
    /* @4599196 cast */
    /* @4599200 constant */
    /* @4599212 cast */
    /* @4599216 load */
    /* @4599224 load */
    /* @4599232 constant */
    /* @4599236 cast */
    /* @4599240 constant */
    /* @4599244 cast */
    /* @4599248 call */
    GM_SITE(vm, 426, 4599248);
    /* @4599256 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4599260: ;
    /* @4599260 load */
    /* @4599268 constant */
    /* @4599272 cmp */
    /* @4599276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4599836;
    /* @4599280 constant */
    /* @4599284 constant */
    /* @4599288 load */
    /* @4599296 constant */
    /* @4599300 add */
    /* @4599304 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4599312 constant */
    /* @4599316 constant */
    /* @4599320 load */
    /* @4599328 constant */
    /* @4599332 add */
    /* @4599336 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(140));
    GM_WRITE(vm, -1, "y", v23);
    /* @4599344 constant */
    /* @4599348 cast */
    /* @4599352 constant */
    /* @4599356 cast */
    /* @4599360 constant */
    /* @4599364 cast */
    /* @4599368 constant */
    /* @4599380 cast */
    /* @4599384 constant */
    /* @4599396 cast */
    /* @4599400 load */
    /* @4599408 load */
    /* @4599416 constant */
    /* @4599420 cast */
    /* @4599424 constant */
    /* @4599428 cast */
    /* @4599432 call */
    GM_SITE(vm, 426, 4599432);
    /* @4599440 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4599444 constant */
    /* @4599448 cast */
    /* @4599452 call */
    GM_SITE(vm, 426, 4599452);
    /* @4599460 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4599464 constant */
    /* @4599472 cast */
    /* @4599476 call */
    GM_SITE(vm, 426, 4599476);
    /* @4599484 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4599488 string */
    /* @4599496 cast */
    /* @4599500 load */
    /* @4599508 constant */
    /* @4599512 add */
    /* @4599516 load */
    /* @4599524 constant */
    /* @4599528 add */
    /* @4599532 call */
    GM_SITE(vm, 426, 4599532);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4599540 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(805)));
    /* @4599544 string */
    /* @4599552 cast */
    /* @4599556 load */
    /* @4599564 constant */
    /* @4599568 add */
    /* @4599572 load */
    /* @4599580 constant */
    /* @4599584 add */
    /* @4599588 call */
    GM_SITE(vm, 426, 4599588);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4599596 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(806)));
    /* @4599600 constant */
    /* @4599604 cast */
    /* @4599608 constant */
    /* @4599612 cast */
    /* @4599616 constant */
    /* @4599620 cast */
    /* @4599624 constant */
    /* @4599636 cast */
    /* @4599640 constant */
    /* @4599652 cast */
    /* @4599656 load */
    /* @4599664 constant */
    /* @4599668 add */
    /* @4599672 load */
    /* @4599680 constant */
    /* @4599684 add */
    /* @4599688 constant */
    /* @4599692 cast */
    /* @4599696 constant */
    /* @4599700 cast */
    /* @4599704 call */
    GM_SITE(vm, 426, 4599704);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4599712 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v28, v29, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4599716 load */
    /* @4599724 constant */
    /* @4599728 cmp */
    /* @4599732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4599836;
    /* @4599736 constant */
    /* @4599740 cast */
    /* @4599744 constant */
    /* @4599748 cast */
    /* @4599752 constant */
    /* @4599756 cast */
    /* @4599760 constant */
    /* @4599772 cast */
    /* @4599776 constant */
    /* @4599788 cast */
    /* @4599792 load */
    /* @4599800 load */
    /* @4599808 constant */
    /* @4599812 cast */
    /* @4599816 constant */
    /* @4599820 cast */
    /* @4599824 call */
    GM_SITE(vm, 426, 4599824);
    /* @4599832 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4599836: ;
    /* @4599836 load */
    /* @4599844 constant */
    /* @4599848 cmp */
    /* @4599852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4600404;
    /* @4599856 constant */
    /* @4599860 constant */
    /* @4599864 load */
    /* @4599872 constant */
    /* @4599876 add */
    /* @4599880 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4599888 constant */
    /* @4599892 constant */
    /* @4599896 load */
    /* @4599904 constant */
    /* @4599908 add */
    /* @4599912 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    GM_WRITE(vm, -1, "y", v31);
    /* @4599920 constant */
    /* @4599924 cast */
    /* @4599928 constant */
    /* @4599932 cast */
    /* @4599936 constant */
    /* @4599940 cast */
    /* @4599944 constant */
    /* @4599956 cast */
    /* @4599960 constant */
    /* @4599972 cast */
    /* @4599976 load */
    /* @4599984 load */
    /* @4599992 constant */
    /* @4599996 cast */
    /* @4600000 constant */
    /* @4600004 cast */
    /* @4600008 call */
    GM_SITE(vm, 426, 4600008);
    /* @4600016 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4600020 constant */
    /* @4600024 cast */
    /* @4600028 call */
    GM_SITE(vm, 426, 4600028);
    /* @4600036 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4600040 constant */
    /* @4600048 cast */
    /* @4600052 call */
    GM_SITE(vm, 426, 4600052);
    /* @4600060 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4600064 string */
    /* @4600072 cast */
    /* @4600076 load */
    /* @4600084 load */
    /* @4600092 constant */
    /* @4600096 add */
    /* @4600100 call */
    GM_SITE(vm, 426, 4600100);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4600108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(805)));
    /* @4600112 string */
    /* @4600120 cast */
    /* @4600124 load */
    /* @4600132 constant */
    /* @4600136 add */
    /* @4600140 load */
    /* @4600148 constant */
    /* @4600152 add */
    /* @4600156 call */
    GM_SITE(vm, 426, 4600156);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4600164 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(806)));
    /* @4600168 constant */
    /* @4600172 cast */
    /* @4600176 constant */
    /* @4600180 cast */
    /* @4600184 constant */
    /* @4600188 cast */
    /* @4600192 constant */
    /* @4600204 cast */
    /* @4600208 constant */
    /* @4600220 cast */
    /* @4600224 load */
    /* @4600232 constant */
    /* @4600236 add */
    /* @4600240 load */
    /* @4600248 constant */
    /* @4600252 add */
    /* @4600256 constant */
    /* @4600260 cast */
    /* @4600264 constant */
    /* @4600268 cast */
    /* @4600272 call */
    GM_SITE(vm, 426, 4600272);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4600280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4600284 load */
    /* @4600292 constant */
    /* @4600296 cmp */
    /* @4600300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4600404;
    /* @4600304 constant */
    /* @4600308 cast */
    /* @4600312 constant */
    /* @4600316 cast */
    /* @4600320 constant */
    /* @4600324 cast */
    /* @4600328 constant */
    /* @4600340 cast */
    /* @4600344 constant */
    /* @4600356 cast */
    /* @4600360 load */
    /* @4600368 load */
    /* @4600376 constant */
    /* @4600380 cast */
    /* @4600384 constant */
    /* @4600388 cast */
    /* @4600392 call */
    GM_SITE(vm, 426, 4600392);
    /* @4600400 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4600404: ;
    /* @4600404 load */
    /* @4600412 constant */
    /* @4600416 cmp */
    /* @4600420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4600972;
    /* @4600424 constant */
    /* @4600428 constant */
    /* @4600432 load */
    /* @4600440 constant */
    /* @4600444 add */
    /* @4600448 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4600456 constant */
    /* @4600460 constant */
    /* @4600464 load */
    /* @4600472 constant */
    /* @4600476 add */
    /* @4600480 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    GM_WRITE(vm, -1, "y", v38);
    /* @4600488 constant */
    /* @4600492 cast */
    /* @4600496 constant */
    /* @4600500 cast */
    /* @4600504 constant */
    /* @4600508 cast */
    /* @4600512 constant */
    /* @4600524 cast */
    /* @4600528 constant */
    /* @4600540 cast */
    /* @4600544 load */
    /* @4600552 load */
    /* @4600560 constant */
    /* @4600564 cast */
    /* @4600568 constant */
    /* @4600572 cast */
    /* @4600576 call */
    GM_SITE(vm, 426, 4600576);
    /* @4600584 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4600588 constant */
    /* @4600592 cast */
    /* @4600596 call */
    GM_SITE(vm, 426, 4600596);
    /* @4600604 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4600608 constant */
    /* @4600616 cast */
    /* @4600620 call */
    GM_SITE(vm, 426, 4600620);
    /* @4600628 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4600632 string */
    /* @4600640 cast */
    /* @4600644 load */
    /* @4600652 load */
    /* @4600660 constant */
    /* @4600664 add */
    /* @4600668 call */
    GM_SITE(vm, 426, 4600668);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4600676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(805)));
    /* @4600680 string */
    /* @4600688 cast */
    /* @4600692 load */
    /* @4600700 constant */
    /* @4600704 add */
    /* @4600708 load */
    /* @4600716 constant */
    /* @4600720 add */
    /* @4600724 call */
    GM_SITE(vm, 426, 4600724);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4600732 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(806)));
    /* @4600736 constant */
    /* @4600740 cast */
    /* @4600744 constant */
    /* @4600748 cast */
    /* @4600752 constant */
    /* @4600756 cast */
    /* @4600760 constant */
    /* @4600772 cast */
    /* @4600776 constant */
    /* @4600788 cast */
    /* @4600792 load */
    /* @4600800 constant */
    /* @4600804 add */
    /* @4600808 load */
    /* @4600816 constant */
    /* @4600820 add */
    /* @4600824 constant */
    /* @4600828 cast */
    /* @4600832 constant */
    /* @4600836 cast */
    /* @4600840 call */
    GM_SITE(vm, 426, 4600840);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4600848 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(47), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4600852 load */
    /* @4600860 constant */
    /* @4600864 cmp */
    /* @4600868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_4600972;
    /* @4600872 constant */
    /* @4600876 cast */
    /* @4600880 constant */
    /* @4600884 cast */
    /* @4600888 constant */
    /* @4600892 cast */
    /* @4600896 constant */
    /* @4600908 cast */
    /* @4600912 constant */
    /* @4600924 cast */
    /* @4600928 load */
    /* @4600936 load */
    /* @4600944 constant */
    /* @4600948 cast */
    /* @4600952 constant */
    /* @4600956 cast */
    /* @4600960 call */
    GM_SITE(vm, 426, 4600960);
    /* @4600968 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4600972: ;
    return;
}
