/* generated from CODE 493 (gml_Object_obj_storepageswitch2_Draw_0), source start 4679816, end 4681248. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0493(GmVM* vm) {
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
    /* @4679816 load */
    /* @4679824 constant */
    /* @4679828 cmp */
    /* @4679832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4680012;
    /* @4679836 constant */
    /* @4679840 cast */
    /* @4679844 constant */
    /* @4679848 cast */
    /* @4679852 constant */
    /* @4679856 cast */
    /* @4679860 constant */
    /* @4679864 cast */
    /* @4679868 constant */
    /* @4679872 cast */
    /* @4679876 load */
    /* @4679884 load */
    /* @4679892 constant */
    /* @4679896 cast */
    /* @4679900 constant */
    /* @4679904 cast */
    /* @4679908 call */
    GM_SITE(vm, 493, 4679908);
    /* @4679916 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4679920 constant */
    /* @4679924 cast */
    /* @4679928 call */
    GM_SITE(vm, 493, 4679928);
    /* @4679936 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4679940 constant */
    /* @4679948 cast */
    /* @4679952 call */
    GM_SITE(vm, 493, 4679952);
    /* @4679960 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4679964 string */
    /* @4679972 cast */
    /* @4679976 load */
    /* @4679984 load */
    /* @4679992 constant */
    /* @4679996 add */
    /* @4680000 call */
    GM_SITE(vm, 493, 4680000);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4680008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4680012: ;
    /* @4680012 load */
    /* @4680020 constant */
    /* @4680024 cmp */
    /* @4680028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4680288;
    /* @4680032 constant */
    /* @4680036 constant */
    /* @4680040 load */
    /* @4680048 constant */
    /* @4680052 add */
    /* @4680056 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(1));
    GM_WRITE(vm, -1, "x", v2);
    /* @4680064 constant */
    /* @4680068 constant */
    /* @4680072 load */
    /* @4680080 constant */
    /* @4680084 add */
    /* @4680088 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "y", v3);
    /* @4680096 constant */
    /* @4680100 cast */
    /* @4680104 constant */
    /* @4680108 cast */
    /* @4680112 constant */
    /* @4680116 cast */
    /* @4680120 constant */
    /* @4680132 cast */
    /* @4680136 constant */
    /* @4680148 cast */
    /* @4680152 load */
    /* @4680160 load */
    /* @4680168 constant */
    /* @4680172 cast */
    /* @4680176 constant */
    /* @4680180 cast */
    /* @4680184 call */
    GM_SITE(vm, 493, 4680184);
    /* @4680192 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4680196 constant */
    /* @4680200 cast */
    /* @4680204 call */
    GM_SITE(vm, 493, 4680204);
    /* @4680212 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4680216 constant */
    /* @4680224 cast */
    /* @4680228 call */
    GM_SITE(vm, 493, 4680228);
    /* @4680236 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4680240 string */
    /* @4680248 cast */
    /* @4680252 load */
    /* @4680260 load */
    /* @4680268 constant */
    /* @4680272 add */
    /* @4680276 call */
    GM_SITE(vm, 493, 4680276);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(13));
    /* @4680284 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4680288: ;
    /* @4680288 load */
    /* @4680296 constant */
    /* @4680300 cmp */
    /* @4680304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4680508;
    /* @4680308 constant */
    /* @4680312 constant */
    /* @4680316 load */
    /* @4680324 constant */
    /* @4680328 add */
    /* @4680332 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    GM_WRITE(vm, -1, "x", v5);
    /* @4680340 constant */
    /* @4680344 constant */
    /* @4680348 load */
    /* @4680356 constant */
    /* @4680360 add */
    /* @4680364 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "y", v6);
    /* @4680372 load */
    /* @4680380 load */
    /* @4680388 constant */
    /* @4680392 cast */
    /* @4680396 constant */
    /* @4680400 cast */
    /* @4680404 call */
    GM_SITE(vm, 493, 4680404);
    /* @4680412 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4680416 constant */
    /* @4680420 cast */
    /* @4680424 call */
    GM_SITE(vm, 493, 4680424);
    /* @4680432 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4680436 constant */
    /* @4680444 cast */
    /* @4680448 call */
    GM_SITE(vm, 493, 4680448);
    /* @4680456 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4680460 string */
    /* @4680468 cast */
    /* @4680472 load */
    /* @4680480 load */
    /* @4680488 constant */
    /* @4680492 add */
    /* @4680496 call */
    GM_SITE(vm, 493, 4680496);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(17));
    /* @4680504 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4680508: ;
    /* @4680508 load */
    /* @4680516 constant */
    /* @4680520 cmp */
    /* @4680524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4680728;
    /* @4680528 constant */
    /* @4680532 constant */
    /* @4680536 load */
    /* @4680544 constant */
    /* @4680548 add */
    /* @4680552 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    GM_WRITE(vm, -1, "x", v8);
    /* @4680560 constant */
    /* @4680564 constant */
    /* @4680568 load */
    /* @4680576 constant */
    /* @4680580 add */
    /* @4680584 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "y", v9);
    /* @4680592 load */
    /* @4680600 load */
    /* @4680608 constant */
    /* @4680612 cast */
    /* @4680616 constant */
    /* @4680620 cast */
    /* @4680624 call */
    GM_SITE(vm, 493, 4680624);
    /* @4680632 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4680636 constant */
    /* @4680640 cast */
    /* @4680644 call */
    GM_SITE(vm, 493, 4680644);
    /* @4680652 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4680656 constant */
    /* @4680664 cast */
    /* @4680668 call */
    GM_SITE(vm, 493, 4680668);
    /* @4680676 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4680680 string */
    /* @4680688 cast */
    /* @4680692 load */
    /* @4680700 load */
    /* @4680708 constant */
    /* @4680712 add */
    /* @4680716 call */
    GM_SITE(vm, 493, 4680716);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(17));
    /* @4680724 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4680728: ;
    /* @4680728 load */
    /* @4680736 constant */
    /* @4680740 cmp */
    /* @4680744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4680988;
    /* @4680748 constant */
    /* @4680752 constant */
    /* @4680756 load */
    /* @4680764 constant */
    /* @4680768 add */
    /* @4680772 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(5));
    GM_WRITE(vm, -1, "x", v11);
    /* @4680780 constant */
    /* @4680784 constant */
    /* @4680788 load */
    /* @4680796 constant */
    /* @4680800 add */
    /* @4680804 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v12);
    /* @4680812 constant */
    /* @4680816 cast */
    /* @4680820 constant */
    /* @4680824 cast */
    /* @4680828 constant */
    /* @4680832 cast */
    /* @4680836 constant */
    /* @4680840 cast */
    /* @4680844 constant */
    /* @4680848 cast */
    /* @4680852 load */
    /* @4680860 load */
    /* @4680868 constant */
    /* @4680872 cast */
    /* @4680876 constant */
    /* @4680880 cast */
    /* @4680884 call */
    GM_SITE(vm, 493, 4680884);
    /* @4680892 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4680896 constant */
    /* @4680900 cast */
    /* @4680904 call */
    GM_SITE(vm, 493, 4680904);
    /* @4680912 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4680916 constant */
    /* @4680924 cast */
    /* @4680928 call */
    GM_SITE(vm, 493, 4680928);
    /* @4680936 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4680940 string */
    /* @4680948 cast */
    /* @4680952 load */
    /* @4680960 load */
    /* @4680968 constant */
    /* @4680972 add */
    /* @4680976 call */
    GM_SITE(vm, 493, 4680976);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4680984 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4680988: ;
    /* @4680988 load */
    /* @4680996 constant */
    /* @4681000 cmp */
    /* @4681004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4681248;
    /* @4681008 constant */
    /* @4681012 constant */
    /* @4681016 load */
    /* @4681024 constant */
    /* @4681028 add */
    /* @4681032 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(5));
    GM_WRITE(vm, -1, "x", v14);
    /* @4681040 constant */
    /* @4681044 constant */
    /* @4681048 load */
    /* @4681056 constant */
    /* @4681060 add */
    /* @4681064 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    GM_WRITE(vm, -1, "y", v15);
    /* @4681072 constant */
    /* @4681076 cast */
    /* @4681080 constant */
    /* @4681084 cast */
    /* @4681088 constant */
    /* @4681092 cast */
    /* @4681096 constant */
    /* @4681100 cast */
    /* @4681104 constant */
    /* @4681108 cast */
    /* @4681112 load */
    /* @4681120 load */
    /* @4681128 constant */
    /* @4681132 cast */
    /* @4681136 constant */
    /* @4681140 cast */
    /* @4681144 call */
    GM_SITE(vm, 493, 4681144);
    /* @4681152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4681156 constant */
    /* @4681160 cast */
    /* @4681164 call */
    GM_SITE(vm, 493, 4681164);
    /* @4681172 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4681176 constant */
    /* @4681184 cast */
    /* @4681188 call */
    GM_SITE(vm, 493, 4681188);
    /* @4681196 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4681200 string */
    /* @4681208 cast */
    /* @4681212 load */
    /* @4681220 load */
    /* @4681228 constant */
    /* @4681232 add */
    /* @4681236 call */
    GM_SITE(vm, 493, 4681236);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4681244 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(875)));
    L_4681248: ;
    return;
}
