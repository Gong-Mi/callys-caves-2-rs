/* generated from CODE 471 (gml_Object_obj_backtogame_Draw_0), source start 4648032, end 4649464. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0471(GmVM* vm) {
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
    /* @4648032 load */
    /* @4648040 constant */
    /* @4648044 cmp */
    /* @4648048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4648228;
    /* @4648052 constant */
    /* @4648056 cast */
    /* @4648060 constant */
    /* @4648064 cast */
    /* @4648068 constant */
    /* @4648072 cast */
    /* @4648076 constant */
    /* @4648080 cast */
    /* @4648084 constant */
    /* @4648088 cast */
    /* @4648092 load */
    /* @4648100 load */
    /* @4648108 constant */
    /* @4648112 cast */
    /* @4648116 constant */
    /* @4648120 cast */
    /* @4648124 call */
    GM_SITE(vm, 471, 4648124);
    /* @4648132 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4648136 constant */
    /* @4648140 cast */
    /* @4648144 call */
    GM_SITE(vm, 471, 4648144);
    /* @4648152 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4648156 constant */
    /* @4648164 cast */
    /* @4648168 call */
    GM_SITE(vm, 471, 4648168);
    /* @4648176 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4648180 string */
    /* @4648188 cast */
    /* @4648192 load */
    /* @4648200 load */
    /* @4648208 constant */
    /* @4648212 add */
    /* @4648216 call */
    GM_SITE(vm, 471, 4648216);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(25));
    /* @4648224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4648228: ;
    /* @4648228 load */
    /* @4648236 constant */
    /* @4648240 cmp */
    /* @4648244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4648504;
    /* @4648248 constant */
    /* @4648252 constant */
    /* @4648256 load */
    /* @4648264 constant */
    /* @4648268 add */
    /* @4648272 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(230));
    GM_WRITE(vm, -1, "x", v2);
    /* @4648280 constant */
    /* @4648284 constant */
    /* @4648288 load */
    /* @4648296 constant */
    /* @4648300 add */
    /* @4648304 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "y", v3);
    /* @4648312 constant */
    /* @4648316 cast */
    /* @4648320 constant */
    /* @4648324 cast */
    /* @4648328 constant */
    /* @4648332 cast */
    /* @4648336 constant */
    /* @4648348 cast */
    /* @4648352 constant */
    /* @4648364 cast */
    /* @4648368 load */
    /* @4648376 load */
    /* @4648384 constant */
    /* @4648388 cast */
    /* @4648392 constant */
    /* @4648396 cast */
    /* @4648400 call */
    GM_SITE(vm, 471, 4648400);
    /* @4648408 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4648412 constant */
    /* @4648416 cast */
    /* @4648420 call */
    GM_SITE(vm, 471, 4648420);
    /* @4648428 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4648432 constant */
    /* @4648440 cast */
    /* @4648444 call */
    GM_SITE(vm, 471, 4648444);
    /* @4648452 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4648456 string */
    /* @4648464 cast */
    /* @4648468 load */
    /* @4648476 load */
    /* @4648484 constant */
    /* @4648488 add */
    /* @4648492 call */
    GM_SITE(vm, 471, 4648492);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(22));
    /* @4648500 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v4, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4648504: ;
    /* @4648504 load */
    /* @4648512 constant */
    /* @4648516 cmp */
    /* @4648520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4648724;
    /* @4648524 constant */
    /* @4648528 constant */
    /* @4648532 load */
    /* @4648540 constant */
    /* @4648544 add */
    /* @4648548 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(300));
    GM_WRITE(vm, -1, "x", v5);
    /* @4648556 constant */
    /* @4648560 constant */
    /* @4648564 load */
    /* @4648572 constant */
    /* @4648576 add */
    /* @4648580 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "y", v6);
    /* @4648588 load */
    /* @4648596 load */
    /* @4648604 constant */
    /* @4648608 cast */
    /* @4648612 constant */
    /* @4648616 cast */
    /* @4648620 call */
    GM_SITE(vm, 471, 4648620);
    /* @4648628 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4648632 constant */
    /* @4648636 cast */
    /* @4648640 call */
    GM_SITE(vm, 471, 4648640);
    /* @4648648 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4648652 constant */
    /* @4648660 cast */
    /* @4648664 call */
    GM_SITE(vm, 471, 4648664);
    /* @4648672 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4648676 string */
    /* @4648684 cast */
    /* @4648688 load */
    /* @4648696 load */
    /* @4648704 constant */
    /* @4648708 add */
    /* @4648712 call */
    GM_SITE(vm, 471, 4648712);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(25));
    /* @4648720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v7, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4648724: ;
    /* @4648724 load */
    /* @4648732 constant */
    /* @4648736 cmp */
    /* @4648740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4648944;
    /* @4648744 constant */
    /* @4648748 constant */
    /* @4648752 load */
    /* @4648760 constant */
    /* @4648764 add */
    /* @4648768 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(300));
    GM_WRITE(vm, -1, "x", v8);
    /* @4648776 constant */
    /* @4648780 constant */
    /* @4648784 load */
    /* @4648792 constant */
    /* @4648796 add */
    /* @4648800 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "y", v9);
    /* @4648808 load */
    /* @4648816 load */
    /* @4648824 constant */
    /* @4648828 cast */
    /* @4648832 constant */
    /* @4648836 cast */
    /* @4648840 call */
    GM_SITE(vm, 471, 4648840);
    /* @4648848 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4648852 constant */
    /* @4648856 cast */
    /* @4648860 call */
    GM_SITE(vm, 471, 4648860);
    /* @4648868 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4648872 constant */
    /* @4648880 cast */
    /* @4648884 call */
    GM_SITE(vm, 471, 4648884);
    /* @4648892 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4648896 string */
    /* @4648904 cast */
    /* @4648908 load */
    /* @4648916 load */
    /* @4648924 constant */
    /* @4648928 add */
    /* @4648932 call */
    GM_SITE(vm, 471, 4648932);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(25));
    /* @4648940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4648944: ;
    /* @4648944 load */
    /* @4648952 constant */
    /* @4648956 cmp */
    /* @4648960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4649204;
    /* @4648964 constant */
    /* @4648968 constant */
    /* @4648972 load */
    /* @4648980 constant */
    /* @4648984 add */
    /* @4648988 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(290));
    GM_WRITE(vm, -1, "x", v11);
    /* @4648996 constant */
    /* @4649000 constant */
    /* @4649004 load */
    /* @4649012 constant */
    /* @4649016 add */
    /* @4649020 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v12);
    /* @4649028 constant */
    /* @4649032 cast */
    /* @4649036 constant */
    /* @4649040 cast */
    /* @4649044 constant */
    /* @4649048 cast */
    /* @4649052 constant */
    /* @4649056 cast */
    /* @4649060 constant */
    /* @4649064 cast */
    /* @4649068 load */
    /* @4649076 load */
    /* @4649084 constant */
    /* @4649088 cast */
    /* @4649092 constant */
    /* @4649096 cast */
    /* @4649100 call */
    GM_SITE(vm, 471, 4649100);
    /* @4649108 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4649112 constant */
    /* @4649116 cast */
    /* @4649120 call */
    GM_SITE(vm, 471, 4649120);
    /* @4649128 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4649132 constant */
    /* @4649140 cast */
    /* @4649144 call */
    GM_SITE(vm, 471, 4649144);
    /* @4649152 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4649156 string */
    /* @4649164 cast */
    /* @4649168 load */
    /* @4649176 load */
    /* @4649184 constant */
    /* @4649188 add */
    /* @4649192 call */
    GM_SITE(vm, 471, 4649192);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(25));
    /* @4649200 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4649204: ;
    /* @4649204 load */
    /* @4649212 constant */
    /* @4649216 cmp */
    /* @4649220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4649464;
    /* @4649224 constant */
    /* @4649228 constant */
    /* @4649232 load */
    /* @4649240 constant */
    /* @4649244 add */
    /* @4649248 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(290));
    GM_WRITE(vm, -1, "x", v14);
    /* @4649256 constant */
    /* @4649260 constant */
    /* @4649264 load */
    /* @4649272 constant */
    /* @4649276 add */
    /* @4649280 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    GM_WRITE(vm, -1, "y", v15);
    /* @4649288 constant */
    /* @4649292 cast */
    /* @4649296 constant */
    /* @4649300 cast */
    /* @4649304 constant */
    /* @4649308 cast */
    /* @4649312 constant */
    /* @4649316 cast */
    /* @4649320 constant */
    /* @4649324 cast */
    /* @4649328 load */
    /* @4649336 load */
    /* @4649344 constant */
    /* @4649348 cast */
    /* @4649352 constant */
    /* @4649356 cast */
    /* @4649360 call */
    GM_SITE(vm, 471, 4649360);
    /* @4649368 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4649372 constant */
    /* @4649376 cast */
    /* @4649380 call */
    GM_SITE(vm, 471, 4649380);
    /* @4649388 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4649392 constant */
    /* @4649400 cast */
    /* @4649404 call */
    GM_SITE(vm, 471, 4649404);
    /* @4649412 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4649416 string */
    /* @4649424 cast */
    /* @4649428 load */
    /* @4649436 load */
    /* @4649444 constant */
    /* @4649448 add */
    /* @4649452 call */
    GM_SITE(vm, 471, 4649452);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(25));
    /* @4649460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(859)));
    L_4649464: ;
    return;
}
