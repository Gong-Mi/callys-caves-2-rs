/* generated from CODE 484 (gml_Object_obj_areyousure_Draw_0), source start 4675636, end 4676644. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0484(GmVM* vm) {
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
    /* @4675636 load */
    /* @4675644 constant */
    /* @4675648 cmp */
    /* @4675652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4675772;
    /* @4675656 constant */
    /* @4675660 cast */
    /* @4675664 call */
    GM_SITE(vm, 484, 4675664);
    /* @4675672 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4675676 constant */
    /* @4675684 cast */
    /* @4675688 call */
    GM_SITE(vm, 484, 4675688);
    /* @4675696 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4675700 string */
    /* @4675708 cast */
    /* @4675712 constant */
    /* @4675716 constant */
    /* @4675720 load */
    /* @4675728 constant */
    /* @4675732 add */
    /* @4675736 constant */
    /* @4675740 constant */
    /* @4675744 load */
    /* @4675752 constant */
    /* @4675756 add */
    /* @4675760 call */
    GM_SITE(vm, 484, 4675760);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(125));
    /* @4675768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, v2, STR_REF(871)));
    L_4675772: ;
    /* @4675772 load */
    /* @4675780 constant */
    /* @4675784 cmp */
    /* @4675788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4675972;
    /* @4675792 constant */
    /* @4675796 cast */
    /* @4675800 call */
    GM_SITE(vm, 484, 4675800);
    /* @4675808 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4675812 constant */
    /* @4675820 cast */
    /* @4675824 call */
    GM_SITE(vm, 484, 4675824);
    /* @4675832 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4675836 string */
    /* @4675844 cast */
    /* @4675848 constant */
    /* @4675852 constant */
    /* @4675856 load */
    /* @4675864 constant */
    /* @4675868 add */
    /* @4675872 constant */
    /* @4675876 constant */
    /* @4675880 load */
    /* @4675888 constant */
    /* @4675892 add */
    /* @4675896 call */
    GM_SITE(vm, 484, 4675896);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(30));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(135));
    /* @4675904 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, v4, STR_REF(871)));
    /* @4675908 constant */
    /* @4675912 constant */
    /* @4675916 load */
    /* @4675924 constant */
    /* @4675928 add */
    /* @4675932 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(30));
    GM_WRITE(vm, -1, "x", v5);
    /* @4675940 constant */
    /* @4675944 constant */
    /* @4675948 load */
    /* @4675956 constant */
    /* @4675960 add */
    /* @4675964 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(135));
    GM_WRITE(vm, -1, "y", v6);
    L_4675972: ;
    /* @4675972 load */
    /* @4675980 constant */
    /* @4675984 cmp */
    /* @4675988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4676172;
    /* @4675992 constant */
    /* @4675996 cast */
    /* @4676000 call */
    GM_SITE(vm, 484, 4676000);
    /* @4676008 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4676012 constant */
    /* @4676020 cast */
    /* @4676024 call */
    GM_SITE(vm, 484, 4676024);
    /* @4676032 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4676036 string */
    /* @4676044 cast */
    /* @4676048 constant */
    /* @4676052 constant */
    /* @4676056 load */
    /* @4676064 constant */
    /* @4676068 add */
    /* @4676072 constant */
    /* @4676076 constant */
    /* @4676080 load */
    /* @4676088 constant */
    /* @4676092 add */
    /* @4676096 call */
    GM_SITE(vm, 484, 4676096);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(200));
    /* @4676104 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, v8, STR_REF(871)));
    /* @4676108 constant */
    /* @4676112 constant */
    /* @4676116 load */
    /* @4676124 constant */
    /* @4676128 add */
    /* @4676132 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(50));
    GM_WRITE(vm, -1, "x", v9);
    /* @4676140 constant */
    /* @4676144 constant */
    /* @4676148 load */
    /* @4676156 constant */
    /* @4676160 add */
    /* @4676164 store */
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(200));
    GM_WRITE(vm, -1, "y", v10);
    L_4676172: ;
    /* @4676172 load */
    /* @4676180 constant */
    /* @4676184 cmp */
    /* @4676188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4676372;
    /* @4676192 constant */
    /* @4676196 cast */
    /* @4676200 call */
    GM_SITE(vm, 484, 4676200);
    /* @4676208 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4676212 constant */
    /* @4676220 cast */
    /* @4676224 call */
    GM_SITE(vm, 484, 4676224);
    /* @4676232 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4676236 string */
    /* @4676244 cast */
    /* @4676248 constant */
    /* @4676252 constant */
    /* @4676256 load */
    /* @4676264 constant */
    /* @4676268 add */
    /* @4676272 constant */
    /* @4676276 constant */
    /* @4676280 load */
    /* @4676288 constant */
    /* @4676292 add */
    /* @4676296 call */
    GM_SITE(vm, 484, 4676296);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(50));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(200));
    /* @4676304 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(871)));
    /* @4676308 constant */
    /* @4676312 constant */
    /* @4676316 load */
    /* @4676324 constant */
    /* @4676328 add */
    /* @4676332 store */
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(50));
    GM_WRITE(vm, -1, "x", v13);
    /* @4676340 constant */
    /* @4676344 constant */
    /* @4676348 load */
    /* @4676356 constant */
    /* @4676360 add */
    /* @4676364 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(200));
    GM_WRITE(vm, -1, "y", v14);
    L_4676372: ;
    /* @4676372 load */
    /* @4676380 constant */
    /* @4676384 cmp */
    /* @4676388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4676508;
    /* @4676392 constant */
    /* @4676396 cast */
    /* @4676400 call */
    GM_SITE(vm, 484, 4676400);
    /* @4676408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4676412 constant */
    /* @4676420 cast */
    /* @4676424 call */
    GM_SITE(vm, 484, 4676424);
    /* @4676432 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4676436 string */
    /* @4676444 cast */
    /* @4676448 constant */
    /* @4676452 constant */
    /* @4676456 load */
    /* @4676464 constant */
    /* @4676468 add */
    /* @4676472 constant */
    /* @4676476 constant */
    /* @4676480 load */
    /* @4676488 constant */
    /* @4676492 add */
    /* @4676496 call */
    GM_SITE(vm, 484, 4676496);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(125));
    /* @4676504 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v15, v16, STR_REF(871)));
    L_4676508: ;
    /* @4676508 load */
    /* @4676516 constant */
    /* @4676520 cmp */
    /* @4676524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4676644;
    /* @4676528 constant */
    /* @4676532 cast */
    /* @4676536 call */
    GM_SITE(vm, 484, 4676536);
    /* @4676544 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4676548 constant */
    /* @4676556 cast */
    /* @4676560 call */
    GM_SITE(vm, 484, 4676560);
    /* @4676568 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4676572 string */
    /* @4676580 cast */
    /* @4676584 constant */
    /* @4676588 constant */
    /* @4676592 load */
    /* @4676600 constant */
    /* @4676604 add */
    /* @4676608 constant */
    /* @4676612 constant */
    /* @4676616 load */
    /* @4676624 constant */
    /* @4676628 add */
    /* @4676632 call */
    GM_SITE(vm, 484, 4676632);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(125));
    /* @4676640 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(871)));
    L_4676644: ;
    return;
}
