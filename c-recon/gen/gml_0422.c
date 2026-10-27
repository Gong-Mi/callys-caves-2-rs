/* generated from CODE 422 (gml_Object_obj_triplejump_Draw_0), source start 4590564, end 4593836. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0422(GmVM* vm) {
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
    /* @4590564 load */
    /* @4590572 constant */
    /* @4590576 cmp */
    /* @4590580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4591052;
    /* @4590584 constant */
    /* @4590588 cast */
    /* @4590592 constant */
    /* @4590596 cast */
    /* @4590600 constant */
    /* @4590604 cast */
    /* @4590608 constant */
    /* @4590620 cast */
    /* @4590624 constant */
    /* @4590636 cast */
    /* @4590640 load */
    /* @4590648 load */
    /* @4590656 constant */
    /* @4590660 cast */
    /* @4590664 constant */
    /* @4590668 cast */
    /* @4590672 call */
    GM_SITE(vm, 422, 4590672);
    /* @4590680 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4590684 constant */
    /* @4590688 cast */
    /* @4590692 call */
    GM_SITE(vm, 422, 4590692);
    /* @4590700 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4590704 constant */
    /* @4590712 cast */
    /* @4590716 call */
    GM_SITE(vm, 422, 4590716);
    /* @4590724 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4590728 string */
    /* @4590736 cast */
    /* @4590740 load */
    /* @4590748 load */
    /* @4590756 constant */
    /* @4590760 add */
    /* @4590764 call */
    GM_SITE(vm, 422, 4590764);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4590772 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(802)));
    /* @4590776 string */
    /* @4590784 cast */
    /* @4590788 load */
    /* @4590796 constant */
    /* @4590800 add */
    /* @4590804 load */
    /* @4590812 constant */
    /* @4590816 add */
    /* @4590820 call */
    GM_SITE(vm, 422, 4590820);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4590828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(803)));
    /* @4590832 constant */
    /* @4590836 cast */
    /* @4590840 constant */
    /* @4590844 cast */
    /* @4590848 constant */
    /* @4590852 cast */
    /* @4590856 constant */
    /* @4590860 cast */
    /* @4590864 constant */
    /* @4590868 cast */
    /* @4590872 load */
    /* @4590880 constant */
    /* @4590884 add */
    /* @4590888 load */
    /* @4590896 constant */
    /* @4590900 add */
    /* @4590904 constant */
    /* @4590908 cast */
    /* @4590912 constant */
    /* @4590916 cast */
    /* @4590920 call */
    GM_SITE(vm, 422, 4590920);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4590928 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4590932 load */
    /* @4590940 constant */
    /* @4590944 cmp */
    /* @4590948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4591052;
    /* @4590952 constant */
    /* @4590956 cast */
    /* @4590960 constant */
    /* @4590964 cast */
    /* @4590968 constant */
    /* @4590972 cast */
    /* @4590976 constant */
    /* @4590988 cast */
    /* @4590992 constant */
    /* @4591004 cast */
    /* @4591008 load */
    /* @4591016 load */
    /* @4591024 constant */
    /* @4591028 cast */
    /* @4591032 constant */
    /* @4591036 cast */
    /* @4591040 call */
    GM_SITE(vm, 422, 4591040);
    /* @4591048 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4591052: ;
    /* @4591052 load */
    /* @4591060 constant */
    /* @4591064 cmp */
    /* @4591068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4591612;
    /* @4591072 constant */
    /* @4591076 constant */
    /* @4591080 load */
    /* @4591088 constant */
    /* @4591092 add */
    /* @4591096 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4591104 constant */
    /* @4591108 constant */
    /* @4591112 load */
    /* @4591120 constant */
    /* @4591124 add */
    /* @4591128 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    GM_WRITE(vm, -1, "y", v7);
    /* @4591136 constant */
    /* @4591140 cast */
    /* @4591144 constant */
    /* @4591148 cast */
    /* @4591152 constant */
    /* @4591156 cast */
    /* @4591160 constant */
    /* @4591164 cast */
    /* @4591168 constant */
    /* @4591172 cast */
    /* @4591176 load */
    /* @4591184 load */
    /* @4591192 constant */
    /* @4591196 cast */
    /* @4591200 constant */
    /* @4591204 cast */
    /* @4591208 call */
    GM_SITE(vm, 422, 4591208);
    /* @4591216 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4591220 constant */
    /* @4591224 cast */
    /* @4591228 call */
    GM_SITE(vm, 422, 4591228);
    /* @4591236 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4591240 constant */
    /* @4591248 cast */
    /* @4591252 call */
    GM_SITE(vm, 422, 4591252);
    /* @4591260 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4591264 string */
    /* @4591272 cast */
    /* @4591276 load */
    /* @4591284 constant */
    /* @4591288 add */
    /* @4591292 load */
    /* @4591300 constant */
    /* @4591304 add */
    /* @4591308 call */
    GM_SITE(vm, 422, 4591308);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4591316 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(802)));
    /* @4591320 string */
    /* @4591328 cast */
    /* @4591332 load */
    /* @4591340 constant */
    /* @4591344 add */
    /* @4591348 load */
    /* @4591356 constant */
    /* @4591360 add */
    /* @4591364 call */
    GM_SITE(vm, 422, 4591364);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4591372 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(803)));
    /* @4591376 constant */
    /* @4591380 cast */
    /* @4591384 constant */
    /* @4591388 cast */
    /* @4591392 constant */
    /* @4591396 cast */
    /* @4591400 constant */
    /* @4591412 cast */
    /* @4591416 constant */
    /* @4591428 cast */
    /* @4591432 load */
    /* @4591440 constant */
    /* @4591444 add */
    /* @4591448 load */
    /* @4591456 constant */
    /* @4591460 add */
    /* @4591464 constant */
    /* @4591468 cast */
    /* @4591472 constant */
    /* @4591476 cast */
    /* @4591480 call */
    GM_SITE(vm, 422, 4591480);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4591488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4591492 load */
    /* @4591500 constant */
    /* @4591504 cmp */
    /* @4591508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4591612;
    /* @4591512 constant */
    /* @4591516 cast */
    /* @4591520 constant */
    /* @4591524 cast */
    /* @4591528 constant */
    /* @4591532 cast */
    /* @4591536 constant */
    /* @4591548 cast */
    /* @4591552 constant */
    /* @4591564 cast */
    /* @4591568 load */
    /* @4591576 load */
    /* @4591584 constant */
    /* @4591588 cast */
    /* @4591592 constant */
    /* @4591596 cast */
    /* @4591600 call */
    GM_SITE(vm, 422, 4591600);
    /* @4591608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4591612: ;
    /* @4591612 load */
    /* @4591620 constant */
    /* @4591624 cmp */
    /* @4591628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4592172;
    /* @4591632 constant */
    /* @4591636 constant */
    /* @4591640 load */
    /* @4591648 constant */
    /* @4591652 add */
    /* @4591656 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4591664 constant */
    /* @4591668 constant */
    /* @4591672 load */
    /* @4591680 constant */
    /* @4591684 add */
    /* @4591688 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    GM_WRITE(vm, -1, "y", v15);
    /* @4591696 constant */
    /* @4591700 cast */
    /* @4591704 constant */
    /* @4591708 cast */
    /* @4591712 constant */
    /* @4591716 cast */
    /* @4591720 constant */
    /* @4591732 cast */
    /* @4591736 constant */
    /* @4591748 cast */
    /* @4591752 load */
    /* @4591760 load */
    /* @4591768 constant */
    /* @4591772 cast */
    /* @4591776 constant */
    /* @4591780 cast */
    /* @4591784 call */
    GM_SITE(vm, 422, 4591784);
    /* @4591792 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4591796 constant */
    /* @4591800 cast */
    /* @4591804 call */
    GM_SITE(vm, 422, 4591804);
    /* @4591812 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4591816 constant */
    /* @4591824 cast */
    /* @4591828 call */
    GM_SITE(vm, 422, 4591828);
    /* @4591836 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4591840 string */
    /* @4591848 cast */
    /* @4591852 load */
    /* @4591860 constant */
    /* @4591864 add */
    /* @4591868 load */
    /* @4591876 constant */
    /* @4591880 add */
    /* @4591884 call */
    GM_SITE(vm, 422, 4591884);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4591892 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(802)));
    /* @4591896 string */
    /* @4591904 cast */
    /* @4591908 load */
    /* @4591916 constant */
    /* @4591920 add */
    /* @4591924 load */
    /* @4591932 constant */
    /* @4591936 add */
    /* @4591940 call */
    GM_SITE(vm, 422, 4591940);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4591948 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(803)));
    /* @4591952 constant */
    /* @4591956 cast */
    /* @4591960 constant */
    /* @4591964 cast */
    /* @4591968 constant */
    /* @4591972 cast */
    /* @4591976 constant */
    /* @4591980 cast */
    /* @4591984 constant */
    /* @4591988 cast */
    /* @4591992 load */
    /* @4592000 constant */
    /* @4592004 add */
    /* @4592008 load */
    /* @4592016 constant */
    /* @4592020 add */
    /* @4592024 constant */
    /* @4592028 cast */
    /* @4592032 constant */
    /* @4592036 cast */
    /* @4592040 call */
    GM_SITE(vm, 422, 4592040);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(18));
    /* @4592048 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4592052 load */
    /* @4592060 constant */
    /* @4592064 cmp */
    /* @4592068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4592172;
    /* @4592072 constant */
    /* @4592076 cast */
    /* @4592080 constant */
    /* @4592084 cast */
    /* @4592088 constant */
    /* @4592092 cast */
    /* @4592096 constant */
    /* @4592108 cast */
    /* @4592112 constant */
    /* @4592124 cast */
    /* @4592128 load */
    /* @4592136 load */
    /* @4592144 constant */
    /* @4592148 cast */
    /* @4592152 constant */
    /* @4592156 cast */
    /* @4592160 call */
    GM_SITE(vm, 422, 4592160);
    /* @4592168 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4592172: ;
    /* @4592172 load */
    /* @4592180 constant */
    /* @4592184 cmp */
    /* @4592188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4592732;
    /* @4592192 constant */
    /* @4592196 constant */
    /* @4592200 load */
    /* @4592208 constant */
    /* @4592212 add */
    /* @4592216 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4592224 constant */
    /* @4592228 constant */
    /* @4592232 load */
    /* @4592240 constant */
    /* @4592244 add */
    /* @4592248 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(140));
    GM_WRITE(vm, -1, "y", v23);
    /* @4592256 constant */
    /* @4592260 cast */
    /* @4592264 constant */
    /* @4592268 cast */
    /* @4592272 constant */
    /* @4592276 cast */
    /* @4592280 constant */
    /* @4592292 cast */
    /* @4592296 constant */
    /* @4592308 cast */
    /* @4592312 load */
    /* @4592320 load */
    /* @4592328 constant */
    /* @4592332 cast */
    /* @4592336 constant */
    /* @4592340 cast */
    /* @4592344 call */
    GM_SITE(vm, 422, 4592344);
    /* @4592352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4592356 constant */
    /* @4592360 cast */
    /* @4592364 call */
    GM_SITE(vm, 422, 4592364);
    /* @4592372 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4592376 constant */
    /* @4592384 cast */
    /* @4592388 call */
    GM_SITE(vm, 422, 4592388);
    /* @4592396 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4592400 string */
    /* @4592408 cast */
    /* @4592412 load */
    /* @4592420 constant */
    /* @4592424 add */
    /* @4592428 load */
    /* @4592436 constant */
    /* @4592440 add */
    /* @4592444 call */
    GM_SITE(vm, 422, 4592444);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4592452 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(802)));
    /* @4592456 string */
    /* @4592464 cast */
    /* @4592468 load */
    /* @4592476 constant */
    /* @4592480 add */
    /* @4592484 load */
    /* @4592492 constant */
    /* @4592496 add */
    /* @4592500 call */
    GM_SITE(vm, 422, 4592500);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4592508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(803)));
    /* @4592512 constant */
    /* @4592516 cast */
    /* @4592520 constant */
    /* @4592524 cast */
    /* @4592528 constant */
    /* @4592532 cast */
    /* @4592536 constant */
    /* @4592540 cast */
    /* @4592544 constant */
    /* @4592548 cast */
    /* @4592552 load */
    /* @4592560 constant */
    /* @4592564 add */
    /* @4592568 load */
    /* @4592576 constant */
    /* @4592580 add */
    /* @4592584 constant */
    /* @4592588 cast */
    /* @4592592 constant */
    /* @4592596 cast */
    /* @4592600 call */
    GM_SITE(vm, 422, 4592600);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(18));
    /* @4592608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v28, v29, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4592612 load */
    /* @4592620 constant */
    /* @4592624 cmp */
    /* @4592628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4592732;
    /* @4592632 constant */
    /* @4592636 cast */
    /* @4592640 constant */
    /* @4592644 cast */
    /* @4592648 constant */
    /* @4592652 cast */
    /* @4592656 constant */
    /* @4592668 cast */
    /* @4592672 constant */
    /* @4592684 cast */
    /* @4592688 load */
    /* @4592696 load */
    /* @4592704 constant */
    /* @4592708 cast */
    /* @4592712 constant */
    /* @4592716 cast */
    /* @4592720 call */
    GM_SITE(vm, 422, 4592720);
    /* @4592728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4592732: ;
    /* @4592732 load */
    /* @4592740 constant */
    /* @4592744 cmp */
    /* @4592748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4593284;
    /* @4592752 constant */
    /* @4592756 constant */
    /* @4592760 load */
    /* @4592768 constant */
    /* @4592772 add */
    /* @4592776 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4592784 constant */
    /* @4592788 constant */
    /* @4592792 load */
    /* @4592800 constant */
    /* @4592804 add */
    /* @4592808 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    GM_WRITE(vm, -1, "y", v31);
    /* @4592816 constant */
    /* @4592820 cast */
    /* @4592824 constant */
    /* @4592828 cast */
    /* @4592832 constant */
    /* @4592836 cast */
    /* @4592840 constant */
    /* @4592852 cast */
    /* @4592856 constant */
    /* @4592868 cast */
    /* @4592872 load */
    /* @4592880 load */
    /* @4592888 constant */
    /* @4592892 cast */
    /* @4592896 constant */
    /* @4592900 cast */
    /* @4592904 call */
    GM_SITE(vm, 422, 4592904);
    /* @4592912 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4592916 constant */
    /* @4592920 cast */
    /* @4592924 call */
    GM_SITE(vm, 422, 4592924);
    /* @4592932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4592936 constant */
    /* @4592944 cast */
    /* @4592948 call */
    GM_SITE(vm, 422, 4592948);
    /* @4592956 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4592960 string */
    /* @4592968 cast */
    /* @4592972 load */
    /* @4592980 load */
    /* @4592988 constant */
    /* @4592992 add */
    /* @4592996 call */
    GM_SITE(vm, 422, 4592996);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4593004 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(802)));
    /* @4593008 string */
    /* @4593016 cast */
    /* @4593020 load */
    /* @4593028 constant */
    /* @4593032 add */
    /* @4593036 load */
    /* @4593044 constant */
    /* @4593048 add */
    /* @4593052 call */
    GM_SITE(vm, 422, 4593052);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4593060 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(803)));
    /* @4593064 constant */
    /* @4593068 cast */
    /* @4593072 constant */
    /* @4593076 cast */
    /* @4593080 constant */
    /* @4593084 cast */
    /* @4593088 constant */
    /* @4593092 cast */
    /* @4593096 constant */
    /* @4593100 cast */
    /* @4593104 load */
    /* @4593112 constant */
    /* @4593116 add */
    /* @4593120 load */
    /* @4593128 constant */
    /* @4593132 add */
    /* @4593136 constant */
    /* @4593140 cast */
    /* @4593144 constant */
    /* @4593148 cast */
    /* @4593152 call */
    GM_SITE(vm, 422, 4593152);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4593160 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4593164 load */
    /* @4593172 constant */
    /* @4593176 cmp */
    /* @4593180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4593284;
    /* @4593184 constant */
    /* @4593188 cast */
    /* @4593192 constant */
    /* @4593196 cast */
    /* @4593200 constant */
    /* @4593204 cast */
    /* @4593208 constant */
    /* @4593220 cast */
    /* @4593224 constant */
    /* @4593236 cast */
    /* @4593240 load */
    /* @4593248 load */
    /* @4593256 constant */
    /* @4593260 cast */
    /* @4593264 constant */
    /* @4593268 cast */
    /* @4593272 call */
    GM_SITE(vm, 422, 4593272);
    /* @4593280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4593284: ;
    /* @4593284 load */
    /* @4593292 constant */
    /* @4593296 cmp */
    /* @4593300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4593836;
    /* @4593304 constant */
    /* @4593308 constant */
    /* @4593312 load */
    /* @4593320 constant */
    /* @4593324 add */
    /* @4593328 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4593336 constant */
    /* @4593340 constant */
    /* @4593344 load */
    /* @4593352 constant */
    /* @4593356 add */
    /* @4593360 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    GM_WRITE(vm, -1, "y", v38);
    /* @4593368 constant */
    /* @4593372 cast */
    /* @4593376 constant */
    /* @4593380 cast */
    /* @4593384 constant */
    /* @4593388 cast */
    /* @4593392 constant */
    /* @4593404 cast */
    /* @4593408 constant */
    /* @4593420 cast */
    /* @4593424 load */
    /* @4593432 load */
    /* @4593440 constant */
    /* @4593444 cast */
    /* @4593448 constant */
    /* @4593452 cast */
    /* @4593456 call */
    GM_SITE(vm, 422, 4593456);
    /* @4593464 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4593468 constant */
    /* @4593472 cast */
    /* @4593476 call */
    GM_SITE(vm, 422, 4593476);
    /* @4593484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4593488 constant */
    /* @4593496 cast */
    /* @4593500 call */
    GM_SITE(vm, 422, 4593500);
    /* @4593508 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4593512 string */
    /* @4593520 cast */
    /* @4593524 load */
    /* @4593532 load */
    /* @4593540 constant */
    /* @4593544 add */
    /* @4593548 call */
    GM_SITE(vm, 422, 4593548);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4593556 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(802)));
    /* @4593560 string */
    /* @4593568 cast */
    /* @4593572 load */
    /* @4593580 constant */
    /* @4593584 add */
    /* @4593588 load */
    /* @4593596 constant */
    /* @4593600 add */
    /* @4593604 call */
    GM_SITE(vm, 422, 4593604);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4593612 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(803)));
    /* @4593616 constant */
    /* @4593620 cast */
    /* @4593624 constant */
    /* @4593628 cast */
    /* @4593632 constant */
    /* @4593636 cast */
    /* @4593640 constant */
    /* @4593644 cast */
    /* @4593648 constant */
    /* @4593652 cast */
    /* @4593656 load */
    /* @4593664 constant */
    /* @4593668 add */
    /* @4593672 load */
    /* @4593680 constant */
    /* @4593684 add */
    /* @4593688 constant */
    /* @4593692 cast */
    /* @4593696 constant */
    /* @4593700 cast */
    /* @4593704 call */
    GM_SITE(vm, 422, 4593704);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(132));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4593712 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(149), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4593716 load */
    /* @4593724 constant */
    /* @4593728 cmp */
    /* @4593732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(1)))) goto L_4593836;
    /* @4593736 constant */
    /* @4593740 cast */
    /* @4593744 constant */
    /* @4593748 cast */
    /* @4593752 constant */
    /* @4593756 cast */
    /* @4593760 constant */
    /* @4593772 cast */
    /* @4593776 constant */
    /* @4593788 cast */
    /* @4593792 load */
    /* @4593800 load */
    /* @4593808 constant */
    /* @4593812 cast */
    /* @4593816 constant */
    /* @4593820 cast */
    /* @4593824 call */
    GM_SITE(vm, 422, 4593824);
    /* @4593832 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4593836: ;
    return;
}
