/* generated from CODE 544 (gml_Object_obj_youhavedied_Draw_0), source start 4841268, end 4844940. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0544(GmVM* vm) {
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
    /* @4841268 load */
    /* @4841276 constant */
    /* @4841280 cmp */
    /* @4841284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4841848;
    /* @4841288 constant */
    /* @4841292 load */
    /* @4841300 cast */
    /* @4841304 load */
    /* @4841312 constant */
    /* @4841316 sub */
    /* @4841320 constant */
    /* @4841324 load */
    /* @4841332 cast */
    /* @4841336 load */
    /* @4841344 constant */
    /* @4841348 sub */
    /* @4841352 constant */
    /* @4841356 cast */
    /* @4841360 constant */
    /* @4841364 cast */
    /* @4841368 call */
    GM_SITE(vm, 544, 4841368);
    /* @4841376 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(163), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @4841380 constant */
    /* @4841384 cast */
    /* @4841388 call */
    GM_SITE(vm, 544, 4841388);
    /* @4841396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4841400 constant */
    /* @4841408 cast */
    /* @4841412 call */
    GM_SITE(vm, 544, 4841412);
    /* @4841420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4841424 string */
    /* @4841432 cast */
    /* @4841436 constant */
    /* @4841440 constant */
    /* @4841444 load */
    /* @4841452 constant */
    /* @4841456 add */
    /* @4841460 constant */
    /* @4841464 constant */
    /* @4841468 load */
    /* @4841476 constant */
    /* @4841480 add */
    /* @4841484 call */
    GM_SITE(vm, 544, 4841484);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(5));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(8));
    /* @4841492 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(1019)));
    /* @4841496 load */
    /* @4841504 call */
    GM_SITE(vm, 544, 4841504);
    /* @4841512 constant */
    /* @4841516 constant */
    /* @4841520 load */
    /* @4841528 constant */
    /* @4841532 add */
    /* @4841536 constant */
    /* @4841540 constant */
    /* @4841544 load */
    /* @4841552 constant */
    /* @4841556 add */
    /* @4841560 call */
    GM_SITE(vm, 544, 4841560);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(15));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(10));
    v5 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4841568 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, v4, v5));
    /* @4841572 constant */
    /* @4841576 constant */
    /* @4841580 load */
    /* @4841588 constant */
    /* @4841592 add */
    /* @4841596 constant */
    /* @4841600 constant */
    /* @4841604 load */
    /* @4841612 constant */
    /* @4841616 add */
    /* @4841620 constant */
    /* @4841624 cast */
    /* @4841628 constant */
    /* @4841632 cast */
    /* @4841636 call */
    GM_SITE(vm, 544, 4841636);
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(45));
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(27));
    /* @4841644 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v6, v7));
    /* @4841648 constant */
    /* @4841652 load */
    /* @4841660 cast */
    /* @4841664 load */
    /* @4841672 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4841680 constant */
    /* @4841684 load */
    /* @4841692 cast */
    /* @4841696 load */
    /* @4841704 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4841712 load */
    /* @4841720 constant */
    /* @4841724 cmp */
    /* @4841728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4841848;
    /* @4841732 constant */
    /* @4841736 cast */
    /* @4841740 call */
    GM_SITE(vm, 544, 4841740);
    /* @4841748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4841752 constant */
    /* @4841760 cast */
    /* @4841764 call */
    GM_SITE(vm, 544, 4841764);
    /* @4841772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4841776 string */
    /* @4841784 cast */
    /* @4841788 constant */
    /* @4841792 constant */
    /* @4841796 load */
    /* @4841804 constant */
    /* @4841808 add */
    /* @4841812 constant */
    /* @4841816 constant */
    /* @4841820 load */
    /* @4841828 constant */
    /* @4841832 add */
    /* @4841836 call */
    GM_SITE(vm, 544, 4841836);
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(140));
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(220));
    /* @4841844 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(743)));
    L_4841848: ;
    /* @4841848 load */
    /* @4841856 constant */
    /* @4841860 cmp */
    /* @4841864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4842468;
    /* @4841868 constant */
    /* @4841872 cast */
    /* @4841876 constant */
    /* @4841880 cast */
    /* @4841884 constant */
    /* @4841888 cast */
    /* @4841892 constant */
    /* @4841904 cast */
    /* @4841908 constant */
    /* @4841920 cast */
    /* @4841924 constant */
    /* @4841928 load */
    /* @4841936 cast */
    /* @4841940 load */
    /* @4841948 constant */
    /* @4841952 load */
    /* @4841960 cast */
    /* @4841964 load */
    /* @4841972 constant */
    /* @4841976 cast */
    /* @4841980 constant */
    /* @4841984 cast */
    /* @4841988 call */
    GM_SITE(vm, 544, 4841988);
    /* @4841996 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(163), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4842000 constant */
    /* @4842004 cast */
    /* @4842008 call */
    GM_SITE(vm, 544, 4842008);
    /* @4842016 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4842020 constant */
    /* @4842028 cast */
    /* @4842032 call */
    GM_SITE(vm, 544, 4842032);
    /* @4842040 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4842044 string */
    /* @4842052 cast */
    /* @4842056 constant */
    /* @4842060 constant */
    /* @4842064 load */
    /* @4842072 constant */
    /* @4842076 add */
    /* @4842080 constant */
    /* @4842084 constant */
    /* @4842088 load */
    /* @4842096 constant */
    /* @4842100 add */
    /* @4842104 call */
    GM_SITE(vm, 544, 4842104);
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(5));
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(10));
    /* @4842112 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(1019)));
    /* @4842116 load */
    /* @4842124 call */
    GM_SITE(vm, 544, 4842124);
    /* @4842132 constant */
    /* @4842136 constant */
    /* @4842140 load */
    /* @4842148 constant */
    /* @4842152 add */
    /* @4842156 constant */
    /* @4842160 constant */
    /* @4842164 load */
    /* @4842172 constant */
    /* @4842176 add */
    /* @4842180 call */
    GM_SITE(vm, 544, 4842180);
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(15));
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(10));
    v14 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4842188 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v12, v13, v14));
    /* @4842192 constant */
    /* @4842196 constant */
    /* @4842200 load */
    /* @4842208 constant */
    /* @4842212 add */
    /* @4842216 constant */
    /* @4842220 constant */
    /* @4842224 load */
    /* @4842232 constant */
    /* @4842236 add */
    /* @4842240 constant */
    /* @4842244 cast */
    /* @4842248 constant */
    /* @4842252 cast */
    /* @4842256 call */
    GM_SITE(vm, 544, 4842256);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(28));
    /* @4842264 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v15, v16));
    /* @4842268 constant */
    /* @4842272 load */
    /* @4842280 cast */
    /* @4842284 load */
    /* @4842292 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4842300 constant */
    /* @4842304 load */
    /* @4842312 cast */
    /* @4842316 load */
    /* @4842324 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4842332 load */
    /* @4842340 constant */
    /* @4842344 cmp */
    /* @4842348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4842468;
    /* @4842352 constant */
    /* @4842356 cast */
    /* @4842360 call */
    GM_SITE(vm, 544, 4842360);
    /* @4842368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4842372 constant */
    /* @4842380 cast */
    /* @4842384 call */
    GM_SITE(vm, 544, 4842384);
    /* @4842392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4842396 string */
    /* @4842404 cast */
    /* @4842408 constant */
    /* @4842412 constant */
    /* @4842416 load */
    /* @4842424 constant */
    /* @4842428 add */
    /* @4842432 constant */
    /* @4842436 constant */
    /* @4842440 load */
    /* @4842448 constant */
    /* @4842452 add */
    /* @4842456 call */
    GM_SITE(vm, 544, 4842456);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4842464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4842468: ;
    /* @4842468 load */
    /* @4842476 constant */
    /* @4842480 cmp */
    /* @4842484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4843096;
    /* @4842488 constant */
    /* @4842492 cast */
    /* @4842496 constant */
    /* @4842500 cast */
    /* @4842504 constant */
    /* @4842508 cast */
    /* @4842512 constant */
    /* @4842524 cast */
    /* @4842528 constant */
    /* @4842540 cast */
    /* @4842544 constant */
    /* @4842548 load */
    /* @4842556 cast */
    /* @4842560 load */
    /* @4842568 constant */
    /* @4842572 load */
    /* @4842580 cast */
    /* @4842584 load */
    /* @4842592 constant */
    /* @4842596 sub */
    /* @4842600 constant */
    /* @4842604 cast */
    /* @4842608 constant */
    /* @4842612 cast */
    /* @4842616 call */
    GM_SITE(vm, 544, 4842616);
    /* @4842624 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(163), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(25)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4842628 constant */
    /* @4842632 cast */
    /* @4842636 call */
    GM_SITE(vm, 544, 4842636);
    /* @4842644 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4842648 constant */
    /* @4842656 cast */
    /* @4842660 call */
    GM_SITE(vm, 544, 4842660);
    /* @4842668 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4842672 string */
    /* @4842680 cast */
    /* @4842684 constant */
    /* @4842688 constant */
    /* @4842692 load */
    /* @4842700 constant */
    /* @4842704 add */
    /* @4842708 constant */
    /* @4842712 constant */
    /* @4842716 load */
    /* @4842724 constant */
    /* @4842728 add */
    /* @4842732 call */
    GM_SITE(vm, 544, 4842732);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(5));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(10));
    /* @4842740 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v19, v20, STR_REF(1019)));
    /* @4842744 load */
    /* @4842752 call */
    GM_SITE(vm, 544, 4842752);
    /* @4842760 constant */
    /* @4842764 constant */
    /* @4842768 load */
    /* @4842776 constant */
    /* @4842780 add */
    /* @4842784 constant */
    /* @4842788 constant */
    /* @4842792 load */
    /* @4842800 constant */
    /* @4842804 add */
    /* @4842808 call */
    GM_SITE(vm, 544, 4842808);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(15));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(10));
    v23 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4842816 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v21, v22, v23));
    /* @4842820 constant */
    /* @4842824 constant */
    /* @4842828 load */
    /* @4842836 constant */
    /* @4842840 add */
    /* @4842844 constant */
    /* @4842848 constant */
    /* @4842852 load */
    /* @4842860 constant */
    /* @4842864 add */
    /* @4842868 constant */
    /* @4842872 cast */
    /* @4842876 constant */
    /* @4842880 cast */
    /* @4842884 call */
    GM_SITE(vm, 544, 4842884);
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(45));
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(28));
    /* @4842892 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v24, v25));
    /* @4842896 constant */
    /* @4842900 load */
    /* @4842908 cast */
    /* @4842912 load */
    /* @4842920 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4842928 constant */
    /* @4842932 load */
    /* @4842940 cast */
    /* @4842944 load */
    /* @4842952 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4842960 load */
    /* @4842968 constant */
    /* @4842972 cmp */
    /* @4842976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4843096;
    /* @4842980 constant */
    /* @4842984 cast */
    /* @4842988 call */
    GM_SITE(vm, 544, 4842988);
    /* @4842996 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4843000 constant */
    /* @4843008 cast */
    /* @4843012 call */
    GM_SITE(vm, 544, 4843012);
    /* @4843020 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4843024 string */
    /* @4843032 cast */
    /* @4843036 constant */
    /* @4843040 constant */
    /* @4843044 load */
    /* @4843052 constant */
    /* @4843056 add */
    /* @4843060 constant */
    /* @4843064 constant */
    /* @4843068 load */
    /* @4843076 constant */
    /* @4843080 add */
    /* @4843084 call */
    GM_SITE(vm, 544, 4843084);
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4843092 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(743)));
    L_4843096: ;
    /* @4843096 load */
    /* @4843104 constant */
    /* @4843108 cmp */
    /* @4843112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4843724;
    /* @4843116 constant */
    /* @4843120 cast */
    /* @4843124 constant */
    /* @4843128 cast */
    /* @4843132 constant */
    /* @4843136 cast */
    /* @4843140 constant */
    /* @4843152 cast */
    /* @4843156 constant */
    /* @4843168 cast */
    /* @4843172 constant */
    /* @4843176 load */
    /* @4843184 cast */
    /* @4843188 load */
    /* @4843196 constant */
    /* @4843200 load */
    /* @4843208 cast */
    /* @4843212 load */
    /* @4843220 constant */
    /* @4843224 sub */
    /* @4843228 constant */
    /* @4843232 cast */
    /* @4843236 constant */
    /* @4843240 cast */
    /* @4843244 call */
    GM_SITE(vm, 544, 4843244);
    /* @4843252 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(163), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(25)), GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4843256 constant */
    /* @4843260 cast */
    /* @4843264 call */
    GM_SITE(vm, 544, 4843264);
    /* @4843272 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4843276 constant */
    /* @4843284 cast */
    /* @4843288 call */
    GM_SITE(vm, 544, 4843288);
    /* @4843296 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4843300 string */
    /* @4843308 cast */
    /* @4843312 constant */
    /* @4843316 constant */
    /* @4843320 load */
    /* @4843328 constant */
    /* @4843332 add */
    /* @4843336 constant */
    /* @4843340 constant */
    /* @4843344 load */
    /* @4843352 constant */
    /* @4843356 add */
    /* @4843360 call */
    GM_SITE(vm, 544, 4843360);
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(5));
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(10));
    /* @4843368 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v28, v29, STR_REF(1019)));
    /* @4843372 load */
    /* @4843380 call */
    GM_SITE(vm, 544, 4843380);
    /* @4843388 constant */
    /* @4843392 constant */
    /* @4843396 load */
    /* @4843404 constant */
    /* @4843408 add */
    /* @4843412 constant */
    /* @4843416 constant */
    /* @4843420 load */
    /* @4843428 constant */
    /* @4843432 add */
    /* @4843436 call */
    GM_SITE(vm, 544, 4843436);
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(15));
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(10));
    v32 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4843444 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v30, v31, v32));
    /* @4843448 constant */
    /* @4843452 constant */
    /* @4843456 load */
    /* @4843464 constant */
    /* @4843468 add */
    /* @4843472 constant */
    /* @4843476 constant */
    /* @4843480 load */
    /* @4843488 constant */
    /* @4843492 add */
    /* @4843496 constant */
    /* @4843500 cast */
    /* @4843504 constant */
    /* @4843508 cast */
    /* @4843512 call */
    GM_SITE(vm, 544, 4843512);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(45));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(28));
    /* @4843520 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v33, v34));
    /* @4843524 constant */
    /* @4843528 load */
    /* @4843536 cast */
    /* @4843540 load */
    /* @4843548 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4843556 constant */
    /* @4843560 load */
    /* @4843568 cast */
    /* @4843572 load */
    /* @4843580 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4843588 load */
    /* @4843596 constant */
    /* @4843600 cmp */
    /* @4843604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4843724;
    /* @4843608 constant */
    /* @4843612 cast */
    /* @4843616 call */
    GM_SITE(vm, 544, 4843616);
    /* @4843624 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4843628 constant */
    /* @4843636 cast */
    /* @4843640 call */
    GM_SITE(vm, 544, 4843640);
    /* @4843648 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4843652 string */
    /* @4843660 cast */
    /* @4843664 constant */
    /* @4843668 constant */
    /* @4843672 load */
    /* @4843680 constant */
    /* @4843684 add */
    /* @4843688 constant */
    /* @4843692 constant */
    /* @4843696 load */
    /* @4843704 constant */
    /* @4843708 add */
    /* @4843712 call */
    GM_SITE(vm, 544, 4843712);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4843720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4843724: ;
    /* @4843724 load */
    /* @4843732 constant */
    /* @4843736 cmp */
    /* @4843740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4844304;
    /* @4843744 constant */
    /* @4843748 load */
    /* @4843756 cast */
    /* @4843760 load */
    /* @4843768 constant */
    /* @4843772 sub */
    /* @4843776 constant */
    /* @4843780 load */
    /* @4843788 cast */
    /* @4843792 load */
    /* @4843800 constant */
    /* @4843804 sub */
    /* @4843808 constant */
    /* @4843812 cast */
    /* @4843816 constant */
    /* @4843820 cast */
    /* @4843824 call */
    GM_SITE(vm, 544, 4843824);
    /* @4843832 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(163), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(20)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10))));
    /* @4843836 constant */
    /* @4843840 cast */
    /* @4843844 call */
    GM_SITE(vm, 544, 4843844);
    /* @4843852 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4843856 constant */
    /* @4843864 cast */
    /* @4843868 call */
    GM_SITE(vm, 544, 4843868);
    /* @4843876 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4843880 string */
    /* @4843888 cast */
    /* @4843892 constant */
    /* @4843896 constant */
    /* @4843900 load */
    /* @4843908 constant */
    /* @4843912 add */
    /* @4843916 constant */
    /* @4843920 constant */
    /* @4843924 load */
    /* @4843932 constant */
    /* @4843936 add */
    /* @4843940 call */
    GM_SITE(vm, 544, 4843940);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(5));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(8));
    /* @4843948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1019)));
    /* @4843952 load */
    /* @4843960 call */
    GM_SITE(vm, 544, 4843960);
    /* @4843968 constant */
    /* @4843972 constant */
    /* @4843976 load */
    /* @4843984 constant */
    /* @4843988 add */
    /* @4843992 constant */
    /* @4843996 constant */
    /* @4844000 load */
    /* @4844008 constant */
    /* @4844012 add */
    /* @4844016 call */
    GM_SITE(vm, 544, 4844016);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(15));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(10));
    v41 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4844024 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, v41));
    /* @4844028 constant */
    /* @4844032 constant */
    /* @4844036 load */
    /* @4844044 constant */
    /* @4844048 add */
    /* @4844052 constant */
    /* @4844056 constant */
    /* @4844060 load */
    /* @4844068 constant */
    /* @4844072 add */
    /* @4844076 constant */
    /* @4844080 cast */
    /* @4844084 constant */
    /* @4844088 cast */
    /* @4844092 call */
    GM_SITE(vm, 544, 4844092);
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(45));
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(27));
    /* @4844100 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v42, v43));
    /* @4844104 constant */
    /* @4844108 load */
    /* @4844116 cast */
    /* @4844120 load */
    /* @4844128 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4844136 constant */
    /* @4844140 load */
    /* @4844148 cast */
    /* @4844152 load */
    /* @4844160 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4844168 load */
    /* @4844176 constant */
    /* @4844180 cmp */
    /* @4844184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4844304;
    /* @4844188 constant */
    /* @4844192 cast */
    /* @4844196 call */
    GM_SITE(vm, 544, 4844196);
    /* @4844204 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4844208 constant */
    /* @4844216 cast */
    /* @4844220 call */
    GM_SITE(vm, 544, 4844220);
    /* @4844228 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4844232 string */
    /* @4844240 cast */
    /* @4844244 constant */
    /* @4844248 constant */
    /* @4844252 load */
    /* @4844260 constant */
    /* @4844264 add */
    /* @4844268 constant */
    /* @4844272 constant */
    /* @4844276 load */
    /* @4844284 constant */
    /* @4844288 add */
    /* @4844292 call */
    GM_SITE(vm, 544, 4844292);
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(140));
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(220));
    /* @4844300 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v44, v45, STR_REF(743)));
    L_4844304: ;
    /* @4844304 load */
    /* @4844312 constant */
    /* @4844316 cmp */
    /* @4844320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4844940;
    /* @4844324 constant */
    /* @4844328 cast */
    /* @4844332 constant */
    /* @4844336 cast */
    /* @4844340 constant */
    /* @4844344 cast */
    /* @4844348 constant */
    /* @4844360 cast */
    /* @4844364 constant */
    /* @4844376 cast */
    /* @4844380 constant */
    /* @4844384 load */
    /* @4844392 cast */
    /* @4844396 load */
    /* @4844404 constant */
    /* @4844408 sub */
    /* @4844412 constant */
    /* @4844416 load */
    /* @4844424 cast */
    /* @4844428 load */
    /* @4844436 constant */
    /* @4844440 sub */
    /* @4844444 constant */
    /* @4844448 cast */
    /* @4844452 constant */
    /* @4844456 cast */
    /* @4844460 call */
    GM_SITE(vm, 544, 4844460);
    /* @4844468 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(163), VAL(0), (GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(30)), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(10)), VAL(1.1), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4844472 constant */
    /* @4844476 cast */
    /* @4844480 call */
    GM_SITE(vm, 544, 4844480);
    /* @4844488 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4844492 constant */
    /* @4844500 cast */
    /* @4844504 call */
    GM_SITE(vm, 544, 4844504);
    /* @4844512 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4844516 string */
    /* @4844524 cast */
    /* @4844528 constant */
    /* @4844532 constant */
    /* @4844536 load */
    /* @4844544 constant */
    /* @4844548 add */
    /* @4844552 constant */
    /* @4844556 constant */
    /* @4844560 load */
    /* @4844568 constant */
    /* @4844572 add */
    /* @4844576 call */
    GM_SITE(vm, 544, 4844576);
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(5));
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(8));
    /* @4844584 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v46, v47, STR_REF(1019)));
    /* @4844588 load */
    /* @4844596 call */
    GM_SITE(vm, 544, 4844596);
    /* @4844604 constant */
    /* @4844608 constant */
    /* @4844612 load */
    /* @4844620 constant */
    /* @4844624 add */
    /* @4844628 constant */
    /* @4844632 constant */
    /* @4844636 load */
    /* @4844644 constant */
    /* @4844648 add */
    /* @4844652 call */
    GM_SITE(vm, 544, 4844652);
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(15));
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(10));
    v50 = GM_CALL(vm, "string", 1, GM_READ(vm, -1, "str1"));
    /* @4844660 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v48, v49, v50));
    /* @4844664 constant */
    /* @4844668 constant */
    /* @4844672 load */
    /* @4844680 constant */
    /* @4844684 add */
    /* @4844688 constant */
    /* @4844692 constant */
    /* @4844696 load */
    /* @4844704 constant */
    /* @4844708 add */
    /* @4844712 constant */
    /* @4844716 cast */
    /* @4844720 constant */
    /* @4844724 cast */
    /* @4844728 call */
    GM_SITE(vm, 544, 4844728);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(45));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(27));
    /* @4844736 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(88), VAL(0), v51, v52));
    /* @4844740 constant */
    /* @4844744 load */
    /* @4844752 cast */
    /* @4844756 load */
    /* @4844764 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4844772 constant */
    /* @4844776 load */
    /* @4844784 cast */
    /* @4844788 load */
    /* @4844796 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4844804 load */
    /* @4844812 constant */
    /* @4844816 cmp */
    /* @4844820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4844940;
    /* @4844824 constant */
    /* @4844828 cast */
    /* @4844832 call */
    GM_SITE(vm, 544, 4844832);
    /* @4844840 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4844844 constant */
    /* @4844852 cast */
    /* @4844856 call */
    GM_SITE(vm, 544, 4844856);
    /* @4844864 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4844868 string */
    /* @4844876 cast */
    /* @4844880 constant */
    /* @4844884 constant */
    /* @4844888 load */
    /* @4844896 constant */
    /* @4844900 add */
    /* @4844904 constant */
    /* @4844908 constant */
    /* @4844912 load */
    /* @4844920 constant */
    /* @4844924 add */
    /* @4844928 call */
    GM_SITE(vm, 544, 4844928);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(150));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(220));
    /* @4844936 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(743)));
    L_4844940: ;
    return;
}
