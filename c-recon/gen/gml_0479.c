/* generated from CODE 479 (gml_Object_obj_yesrestoredata_Draw_0), source start 4672540, end 4673924. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0479(GmVM* vm) {
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
    /* @4672540 load */
    /* @4672548 constant */
    /* @4672552 cmp */
    /* @4672556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4672760;
    /* @4672560 constant */
    /* @4672564 constant */
    /* @4672568 load */
    /* @4672576 constant */
    /* @4672580 add */
    /* @4672584 store */
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    GM_WRITE(vm, -1, "x", v1);
    /* @4672592 constant */
    /* @4672596 constant */
    /* @4672600 load */
    /* @4672608 constant */
    /* @4672612 add */
    /* @4672616 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(155));
    GM_WRITE(vm, -1, "y", v2);
    /* @4672624 load */
    /* @4672632 load */
    /* @4672640 constant */
    /* @4672644 cast */
    /* @4672648 constant */
    /* @4672652 cast */
    /* @4672656 call */
    GM_SITE(vm, 479, 4672656);
    /* @4672664 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4672668 constant */
    /* @4672672 cast */
    /* @4672676 call */
    GM_SITE(vm, 479, 4672676);
    /* @4672684 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4672688 constant */
    /* @4672696 cast */
    /* @4672700 call */
    GM_SITE(vm, 479, 4672700);
    /* @4672708 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4672712 string */
    /* @4672720 cast */
    /* @4672724 load */
    /* @4672732 load */
    /* @4672740 constant */
    /* @4672744 add */
    /* @4672748 call */
    GM_SITE(vm, 479, 4672748);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(44));
    /* @4672756 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v3, GM_READ(vm, -1, "y"), STR_REF(869)));
    L_4672760: ;
    /* @4672760 load */
    /* @4672768 constant */
    /* @4672772 cmp */
    /* @4672776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4673044;
    /* @4672780 constant */
    /* @4672784 constant */
    /* @4672788 load */
    /* @4672796 constant */
    /* @4672800 add */
    /* @4672804 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(80));
    GM_WRITE(vm, -1, "x", v4);
    /* @4672812 constant */
    /* @4672816 constant */
    /* @4672820 load */
    /* @4672828 constant */
    /* @4672832 add */
    /* @4672836 store */
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(160));
    GM_WRITE(vm, -1, "y", v5);
    /* @4672844 constant */
    /* @4672848 cast */
    /* @4672852 constant */
    /* @4672856 cast */
    /* @4672860 constant */
    /* @4672864 cast */
    /* @4672868 constant */
    /* @4672880 cast */
    /* @4672884 constant */
    /* @4672896 cast */
    /* @4672900 load */
    /* @4672908 load */
    /* @4672916 constant */
    /* @4672920 cast */
    /* @4672924 constant */
    /* @4672928 cast */
    /* @4672932 call */
    GM_SITE(vm, 479, 4672932);
    /* @4672940 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4672944 constant */
    /* @4672948 cast */
    /* @4672952 call */
    GM_SITE(vm, 479, 4672952);
    /* @4672960 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4672964 constant */
    /* @4672972 cast */
    /* @4672976 call */
    GM_SITE(vm, 479, 4672976);
    /* @4672984 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4672988 string */
    /* @4672996 cast */
    /* @4673000 load */
    /* @4673008 constant */
    /* @4673012 add */
    /* @4673016 load */
    /* @4673024 constant */
    /* @4673028 add */
    /* @4673032 call */
    GM_SITE(vm, 479, 4673032);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(30));
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(2));
    /* @4673040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, v7, STR_REF(869)));
    L_4673044: ;
    /* @4673044 load */
    /* @4673052 constant */
    /* @4673056 cmp */
    /* @4673060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4673264;
    /* @4673064 constant */
    /* @4673068 constant */
    /* @4673072 load */
    /* @4673080 constant */
    /* @4673084 add */
    /* @4673088 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(120));
    GM_WRITE(vm, -1, "x", v8);
    /* @4673096 constant */
    /* @4673100 constant */
    /* @4673104 load */
    /* @4673112 constant */
    /* @4673116 add */
    /* @4673120 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(240));
    GM_WRITE(vm, -1, "y", v9);
    /* @4673128 load */
    /* @4673136 load */
    /* @4673144 constant */
    /* @4673148 cast */
    /* @4673152 constant */
    /* @4673156 cast */
    /* @4673160 call */
    GM_SITE(vm, 479, 4673160);
    /* @4673168 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4673172 constant */
    /* @4673176 cast */
    /* @4673180 call */
    GM_SITE(vm, 479, 4673180);
    /* @4673188 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4673192 constant */
    /* @4673200 cast */
    /* @4673204 call */
    GM_SITE(vm, 479, 4673204);
    /* @4673212 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4673216 string */
    /* @4673224 cast */
    /* @4673228 load */
    /* @4673236 load */
    /* @4673244 constant */
    /* @4673248 add */
    /* @4673252 call */
    GM_SITE(vm, 479, 4673252);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(44));
    /* @4673260 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, GM_READ(vm, -1, "y"), STR_REF(869)));
    L_4673264: ;
    /* @4673264 load */
    /* @4673272 constant */
    /* @4673276 cmp */
    /* @4673280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4673484;
    /* @4673284 constant */
    /* @4673288 constant */
    /* @4673292 load */
    /* @4673300 constant */
    /* @4673304 add */
    /* @4673308 store */
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(120));
    GM_WRITE(vm, -1, "x", v11);
    /* @4673316 constant */
    /* @4673320 constant */
    /* @4673324 load */
    /* @4673332 constant */
    /* @4673336 add */
    /* @4673340 store */
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(240));
    GM_WRITE(vm, -1, "y", v12);
    /* @4673348 load */
    /* @4673356 load */
    /* @4673364 constant */
    /* @4673368 cast */
    /* @4673372 constant */
    /* @4673376 cast */
    /* @4673380 call */
    GM_SITE(vm, 479, 4673380);
    /* @4673388 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4673392 constant */
    /* @4673396 cast */
    /* @4673400 call */
    GM_SITE(vm, 479, 4673400);
    /* @4673408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4673412 constant */
    /* @4673420 cast */
    /* @4673424 call */
    GM_SITE(vm, 479, 4673424);
    /* @4673432 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4673436 string */
    /* @4673444 cast */
    /* @4673448 load */
    /* @4673456 load */
    /* @4673464 constant */
    /* @4673468 add */
    /* @4673472 call */
    GM_SITE(vm, 479, 4673472);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(44));
    /* @4673480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v13, GM_READ(vm, -1, "y"), STR_REF(869)));
    L_4673484: ;
    /* @4673484 load */
    /* @4673492 constant */
    /* @4673496 cmp */
    /* @4673500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4673704;
    /* @4673504 constant */
    /* @4673508 constant */
    /* @4673512 load */
    /* @4673520 constant */
    /* @4673524 add */
    /* @4673528 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(40));
    GM_WRITE(vm, -1, "x", v14);
    /* @4673536 constant */
    /* @4673540 constant */
    /* @4673544 load */
    /* @4673552 constant */
    /* @4673556 add */
    /* @4673560 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(155));
    GM_WRITE(vm, -1, "y", v15);
    /* @4673568 load */
    /* @4673576 load */
    /* @4673584 constant */
    /* @4673588 cast */
    /* @4673592 constant */
    /* @4673596 cast */
    /* @4673600 call */
    GM_SITE(vm, 479, 4673600);
    /* @4673608 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4673612 constant */
    /* @4673616 cast */
    /* @4673620 call */
    GM_SITE(vm, 479, 4673620);
    /* @4673628 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4673632 constant */
    /* @4673640 cast */
    /* @4673644 call */
    GM_SITE(vm, 479, 4673644);
    /* @4673652 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4673656 string */
    /* @4673664 cast */
    /* @4673668 load */
    /* @4673676 load */
    /* @4673684 constant */
    /* @4673688 add */
    /* @4673692 call */
    GM_SITE(vm, 479, 4673692);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(44));
    /* @4673700 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, GM_READ(vm, -1, "y"), STR_REF(869)));
    L_4673704: ;
    /* @4673704 load */
    /* @4673712 constant */
    /* @4673716 cmp */
    /* @4673720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4673924;
    /* @4673724 constant */
    /* @4673728 constant */
    /* @4673732 load */
    /* @4673740 constant */
    /* @4673744 add */
    /* @4673748 store */
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(40));
    GM_WRITE(vm, -1, "x", v17);
    /* @4673756 constant */
    /* @4673760 constant */
    /* @4673764 load */
    /* @4673772 constant */
    /* @4673776 add */
    /* @4673780 store */
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(155));
    GM_WRITE(vm, -1, "y", v18);
    /* @4673788 load */
    /* @4673796 load */
    /* @4673804 constant */
    /* @4673808 cast */
    /* @4673812 constant */
    /* @4673816 cast */
    /* @4673820 call */
    GM_SITE(vm, 479, 4673820);
    /* @4673828 popz */
    (void)(GM_CALL(vm, "draw_sprite", 4, VAL(153), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y")));
    /* @4673832 constant */
    /* @4673836 cast */
    /* @4673840 call */
    GM_SITE(vm, 479, 4673840);
    /* @4673848 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4673852 constant */
    /* @4673860 cast */
    /* @4673864 call */
    GM_SITE(vm, 479, 4673864);
    /* @4673872 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4673876 string */
    /* @4673884 cast */
    /* @4673888 load */
    /* @4673896 load */
    /* @4673904 constant */
    /* @4673908 add */
    /* @4673912 call */
    GM_SITE(vm, 479, 4673912);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(44));
    /* @4673920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v19, GM_READ(vm, -1, "y"), STR_REF(869)));
    L_4673924: ;
    return;
}
