/* generated from CODE 424 (gml_Object_obj_swordupgrade_Draw_0), source start 4594060, end 4597412. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0424(GmVM* vm) {
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
    /* @4594060 load */
    /* @4594068 constant */
    /* @4594072 cmp */
    /* @4594076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4594564;
    /* @4594080 constant */
    /* @4594084 cast */
    /* @4594088 constant */
    /* @4594092 cast */
    /* @4594096 constant */
    /* @4594100 cast */
    /* @4594104 constant */
    /* @4594116 cast */
    /* @4594120 constant */
    /* @4594132 cast */
    /* @4594136 load */
    /* @4594144 load */
    /* @4594152 constant */
    /* @4594156 cast */
    /* @4594160 constant */
    /* @4594164 cast */
    /* @4594168 call */
    GM_SITE(vm, 424, 4594168);
    /* @4594176 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4594180 constant */
    /* @4594184 cast */
    /* @4594188 call */
    GM_SITE(vm, 424, 4594188);
    /* @4594196 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4594200 constant */
    /* @4594208 cast */
    /* @4594212 call */
    GM_SITE(vm, 424, 4594212);
    /* @4594220 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4594224 string */
    /* @4594232 cast */
    /* @4594236 load */
    /* @4594244 load */
    /* @4594252 constant */
    /* @4594256 add */
    /* @4594260 call */
    GM_SITE(vm, 424, 4594260);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4594268 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(804)));
    /* @4594272 string */
    /* @4594280 cast */
    /* @4594284 load */
    /* @4594292 constant */
    /* @4594296 add */
    /* @4594300 load */
    /* @4594308 constant */
    /* @4594312 add */
    /* @4594316 call */
    GM_SITE(vm, 424, 4594316);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4594324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(803)));
    /* @4594328 constant */
    /* @4594332 cast */
    /* @4594336 constant */
    /* @4594340 cast */
    /* @4594344 constant */
    /* @4594348 cast */
    /* @4594352 constant */
    /* @4594364 cast */
    /* @4594368 constant */
    /* @4594380 cast */
    /* @4594384 load */
    /* @4594392 constant */
    /* @4594396 add */
    /* @4594400 load */
    /* @4594408 constant */
    /* @4594412 add */
    /* @4594416 constant */
    /* @4594420 cast */
    /* @4594424 constant */
    /* @4594428 cast */
    /* @4594432 call */
    GM_SITE(vm, 424, 4594432);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(28));
    /* @4594440 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4594444 load */
    /* @4594452 constant */
    /* @4594456 cmp */
    /* @4594460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4594564;
    /* @4594464 constant */
    /* @4594468 cast */
    /* @4594472 constant */
    /* @4594476 cast */
    /* @4594480 constant */
    /* @4594484 cast */
    /* @4594488 constant */
    /* @4594500 cast */
    /* @4594504 constant */
    /* @4594516 cast */
    /* @4594520 load */
    /* @4594528 load */
    /* @4594536 constant */
    /* @4594540 cast */
    /* @4594544 constant */
    /* @4594548 cast */
    /* @4594552 call */
    GM_SITE(vm, 424, 4594552);
    /* @4594560 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4594564: ;
    /* @4594564 load */
    /* @4594572 constant */
    /* @4594576 cmp */
    /* @4594580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4595124;
    /* @4594584 constant */
    /* @4594588 constant */
    /* @4594592 load */
    /* @4594600 constant */
    /* @4594604 add */
    /* @4594608 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4594616 constant */
    /* @4594620 constant */
    /* @4594624 load */
    /* @4594632 constant */
    /* @4594636 add */
    /* @4594640 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    GM_WRITE(vm, -1, "y", v7);
    /* @4594648 constant */
    /* @4594652 cast */
    /* @4594656 constant */
    /* @4594660 cast */
    /* @4594664 constant */
    /* @4594668 cast */
    /* @4594672 constant */
    /* @4594676 cast */
    /* @4594680 constant */
    /* @4594684 cast */
    /* @4594688 load */
    /* @4594696 load */
    /* @4594704 constant */
    /* @4594708 cast */
    /* @4594712 constant */
    /* @4594716 cast */
    /* @4594720 call */
    GM_SITE(vm, 424, 4594720);
    /* @4594728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4594732 constant */
    /* @4594736 cast */
    /* @4594740 call */
    GM_SITE(vm, 424, 4594740);
    /* @4594748 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4594752 constant */
    /* @4594760 cast */
    /* @4594764 call */
    GM_SITE(vm, 424, 4594764);
    /* @4594772 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4594776 string */
    /* @4594784 cast */
    /* @4594788 load */
    /* @4594796 constant */
    /* @4594800 add */
    /* @4594804 load */
    /* @4594812 constant */
    /* @4594816 add */
    /* @4594820 call */
    GM_SITE(vm, 424, 4594820);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4594828 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(804)));
    /* @4594832 string */
    /* @4594840 cast */
    /* @4594844 load */
    /* @4594852 constant */
    /* @4594856 add */
    /* @4594860 load */
    /* @4594868 constant */
    /* @4594872 add */
    /* @4594876 call */
    GM_SITE(vm, 424, 4594876);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4594884 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(803)));
    /* @4594888 constant */
    /* @4594892 cast */
    /* @4594896 constant */
    /* @4594900 cast */
    /* @4594904 constant */
    /* @4594908 cast */
    /* @4594912 constant */
    /* @4594924 cast */
    /* @4594928 constant */
    /* @4594940 cast */
    /* @4594944 load */
    /* @4594952 constant */
    /* @4594956 add */
    /* @4594960 load */
    /* @4594968 constant */
    /* @4594972 add */
    /* @4594976 constant */
    /* @4594980 cast */
    /* @4594984 constant */
    /* @4594988 cast */
    /* @4594992 call */
    GM_SITE(vm, 424, 4594992);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(29));
    /* @4595000 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v12, v13, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4595004 load */
    /* @4595012 constant */
    /* @4595016 cmp */
    /* @4595020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4595124;
    /* @4595024 constant */
    /* @4595028 cast */
    /* @4595032 constant */
    /* @4595036 cast */
    /* @4595040 constant */
    /* @4595044 cast */
    /* @4595048 constant */
    /* @4595060 cast */
    /* @4595064 constant */
    /* @4595076 cast */
    /* @4595080 load */
    /* @4595088 load */
    /* @4595096 constant */
    /* @4595100 cast */
    /* @4595104 constant */
    /* @4595108 cast */
    /* @4595112 call */
    GM_SITE(vm, 424, 4595112);
    /* @4595120 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4595124: ;
    /* @4595124 load */
    /* @4595132 constant */
    /* @4595136 cmp */
    /* @4595140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4595700;
    /* @4595144 constant */
    /* @4595148 constant */
    /* @4595152 load */
    /* @4595160 constant */
    /* @4595164 add */
    /* @4595168 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4595176 constant */
    /* @4595180 constant */
    /* @4595184 load */
    /* @4595192 constant */
    /* @4595196 add */
    /* @4595200 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    GM_WRITE(vm, -1, "y", v15);
    /* @4595208 constant */
    /* @4595212 cast */
    /* @4595216 constant */
    /* @4595220 cast */
    /* @4595224 constant */
    /* @4595228 cast */
    /* @4595232 constant */
    /* @4595244 cast */
    /* @4595248 constant */
    /* @4595260 cast */
    /* @4595264 load */
    /* @4595272 load */
    /* @4595280 constant */
    /* @4595284 cast */
    /* @4595288 constant */
    /* @4595292 cast */
    /* @4595296 call */
    GM_SITE(vm, 424, 4595296);
    /* @4595304 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4595308 constant */
    /* @4595312 cast */
    /* @4595316 call */
    GM_SITE(vm, 424, 4595316);
    /* @4595324 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4595328 constant */
    /* @4595336 cast */
    /* @4595340 call */
    GM_SITE(vm, 424, 4595340);
    /* @4595348 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4595352 string */
    /* @4595360 cast */
    /* @4595364 load */
    /* @4595372 constant */
    /* @4595376 add */
    /* @4595380 load */
    /* @4595388 constant */
    /* @4595392 add */
    /* @4595396 call */
    GM_SITE(vm, 424, 4595396);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4595404 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(804)));
    /* @4595408 string */
    /* @4595416 cast */
    /* @4595420 load */
    /* @4595428 constant */
    /* @4595432 add */
    /* @4595436 load */
    /* @4595444 constant */
    /* @4595448 add */
    /* @4595452 call */
    GM_SITE(vm, 424, 4595452);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4595460 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(803)));
    /* @4595464 constant */
    /* @4595468 cast */
    /* @4595472 constant */
    /* @4595476 cast */
    /* @4595480 constant */
    /* @4595484 cast */
    /* @4595488 constant */
    /* @4595500 cast */
    /* @4595504 constant */
    /* @4595516 cast */
    /* @4595520 load */
    /* @4595528 constant */
    /* @4595532 add */
    /* @4595536 load */
    /* @4595544 constant */
    /* @4595548 add */
    /* @4595552 constant */
    /* @4595556 cast */
    /* @4595560 constant */
    /* @4595564 cast */
    /* @4595568 call */
    GM_SITE(vm, 424, 4595568);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4595576 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4595580 load */
    /* @4595588 constant */
    /* @4595592 cmp */
    /* @4595596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4595700;
    /* @4595600 constant */
    /* @4595604 cast */
    /* @4595608 constant */
    /* @4595612 cast */
    /* @4595616 constant */
    /* @4595620 cast */
    /* @4595624 constant */
    /* @4595636 cast */
    /* @4595640 constant */
    /* @4595652 cast */
    /* @4595656 load */
    /* @4595664 load */
    /* @4595672 constant */
    /* @4595676 cast */
    /* @4595680 constant */
    /* @4595684 cast */
    /* @4595688 call */
    GM_SITE(vm, 424, 4595688);
    /* @4595696 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4595700: ;
    /* @4595700 load */
    /* @4595708 constant */
    /* @4595712 cmp */
    /* @4595716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4596276;
    /* @4595720 constant */
    /* @4595724 constant */
    /* @4595728 load */
    /* @4595736 constant */
    /* @4595740 add */
    /* @4595744 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4595752 constant */
    /* @4595756 constant */
    /* @4595760 load */
    /* @4595768 constant */
    /* @4595772 add */
    /* @4595776 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    GM_WRITE(vm, -1, "y", v23);
    /* @4595784 constant */
    /* @4595788 cast */
    /* @4595792 constant */
    /* @4595796 cast */
    /* @4595800 constant */
    /* @4595804 cast */
    /* @4595808 constant */
    /* @4595820 cast */
    /* @4595824 constant */
    /* @4595836 cast */
    /* @4595840 load */
    /* @4595848 load */
    /* @4595856 constant */
    /* @4595860 cast */
    /* @4595864 constant */
    /* @4595868 cast */
    /* @4595872 call */
    GM_SITE(vm, 424, 4595872);
    /* @4595880 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4595884 constant */
    /* @4595888 cast */
    /* @4595892 call */
    GM_SITE(vm, 424, 4595892);
    /* @4595900 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4595904 constant */
    /* @4595912 cast */
    /* @4595916 call */
    GM_SITE(vm, 424, 4595916);
    /* @4595924 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4595928 string */
    /* @4595936 cast */
    /* @4595940 load */
    /* @4595948 constant */
    /* @4595952 add */
    /* @4595956 load */
    /* @4595964 constant */
    /* @4595968 add */
    /* @4595972 call */
    GM_SITE(vm, 424, 4595972);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4595980 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(804)));
    /* @4595984 string */
    /* @4595992 cast */
    /* @4595996 load */
    /* @4596004 constant */
    /* @4596008 add */
    /* @4596012 load */
    /* @4596020 constant */
    /* @4596024 add */
    /* @4596028 call */
    GM_SITE(vm, 424, 4596028);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4596036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(803)));
    /* @4596040 constant */
    /* @4596044 cast */
    /* @4596048 constant */
    /* @4596052 cast */
    /* @4596056 constant */
    /* @4596060 cast */
    /* @4596064 constant */
    /* @4596076 cast */
    /* @4596080 constant */
    /* @4596092 cast */
    /* @4596096 load */
    /* @4596104 constant */
    /* @4596108 add */
    /* @4596112 load */
    /* @4596120 constant */
    /* @4596124 add */
    /* @4596128 constant */
    /* @4596132 cast */
    /* @4596136 constant */
    /* @4596140 cast */
    /* @4596144 call */
    GM_SITE(vm, 424, 4596144);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(34));
    /* @4596152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v28, v29, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4596156 load */
    /* @4596164 constant */
    /* @4596168 cmp */
    /* @4596172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4596276;
    /* @4596176 constant */
    /* @4596180 cast */
    /* @4596184 constant */
    /* @4596188 cast */
    /* @4596192 constant */
    /* @4596196 cast */
    /* @4596200 constant */
    /* @4596212 cast */
    /* @4596216 constant */
    /* @4596228 cast */
    /* @4596232 load */
    /* @4596240 load */
    /* @4596248 constant */
    /* @4596252 cast */
    /* @4596256 constant */
    /* @4596260 cast */
    /* @4596264 call */
    GM_SITE(vm, 424, 4596264);
    /* @4596272 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4596276: ;
    /* @4596276 load */
    /* @4596284 constant */
    /* @4596288 cmp */
    /* @4596292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4596844;
    /* @4596296 constant */
    /* @4596300 constant */
    /* @4596304 load */
    /* @4596312 constant */
    /* @4596316 add */
    /* @4596320 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4596328 constant */
    /* @4596332 constant */
    /* @4596336 load */
    /* @4596344 constant */
    /* @4596348 add */
    /* @4596352 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    GM_WRITE(vm, -1, "y", v31);
    /* @4596360 constant */
    /* @4596364 cast */
    /* @4596368 constant */
    /* @4596372 cast */
    /* @4596376 constant */
    /* @4596380 cast */
    /* @4596384 constant */
    /* @4596396 cast */
    /* @4596400 constant */
    /* @4596412 cast */
    /* @4596416 load */
    /* @4596424 load */
    /* @4596432 constant */
    /* @4596436 cast */
    /* @4596440 constant */
    /* @4596444 cast */
    /* @4596448 call */
    GM_SITE(vm, 424, 4596448);
    /* @4596456 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4596460 constant */
    /* @4596464 cast */
    /* @4596468 call */
    GM_SITE(vm, 424, 4596468);
    /* @4596476 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4596480 constant */
    /* @4596488 cast */
    /* @4596492 call */
    GM_SITE(vm, 424, 4596492);
    /* @4596500 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4596504 string */
    /* @4596512 cast */
    /* @4596516 load */
    /* @4596524 load */
    /* @4596532 constant */
    /* @4596536 add */
    /* @4596540 call */
    GM_SITE(vm, 424, 4596540);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4596548 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(804)));
    /* @4596552 string */
    /* @4596560 cast */
    /* @4596564 load */
    /* @4596572 constant */
    /* @4596576 add */
    /* @4596580 load */
    /* @4596588 constant */
    /* @4596592 add */
    /* @4596596 call */
    GM_SITE(vm, 424, 4596596);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4596604 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(803)));
    /* @4596608 constant */
    /* @4596612 cast */
    /* @4596616 constant */
    /* @4596620 cast */
    /* @4596624 constant */
    /* @4596628 cast */
    /* @4596632 constant */
    /* @4596644 cast */
    /* @4596648 constant */
    /* @4596660 cast */
    /* @4596664 load */
    /* @4596672 constant */
    /* @4596676 add */
    /* @4596680 load */
    /* @4596688 constant */
    /* @4596692 add */
    /* @4596696 constant */
    /* @4596700 cast */
    /* @4596704 constant */
    /* @4596708 cast */
    /* @4596712 call */
    GM_SITE(vm, 424, 4596712);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(28));
    /* @4596720 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4596724 load */
    /* @4596732 constant */
    /* @4596736 cmp */
    /* @4596740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4596844;
    /* @4596744 constant */
    /* @4596748 cast */
    /* @4596752 constant */
    /* @4596756 cast */
    /* @4596760 constant */
    /* @4596764 cast */
    /* @4596768 constant */
    /* @4596780 cast */
    /* @4596784 constant */
    /* @4596796 cast */
    /* @4596800 load */
    /* @4596808 load */
    /* @4596816 constant */
    /* @4596820 cast */
    /* @4596824 constant */
    /* @4596828 cast */
    /* @4596832 call */
    GM_SITE(vm, 424, 4596832);
    /* @4596840 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4596844: ;
    /* @4596844 load */
    /* @4596852 constant */
    /* @4596856 cmp */
    /* @4596860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4597412;
    /* @4596864 constant */
    /* @4596868 constant */
    /* @4596872 load */
    /* @4596880 constant */
    /* @4596884 add */
    /* @4596888 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4596896 constant */
    /* @4596900 constant */
    /* @4596904 load */
    /* @4596912 constant */
    /* @4596916 add */
    /* @4596920 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    GM_WRITE(vm, -1, "y", v38);
    /* @4596928 constant */
    /* @4596932 cast */
    /* @4596936 constant */
    /* @4596940 cast */
    /* @4596944 constant */
    /* @4596948 cast */
    /* @4596952 constant */
    /* @4596964 cast */
    /* @4596968 constant */
    /* @4596980 cast */
    /* @4596984 load */
    /* @4596992 load */
    /* @4597000 constant */
    /* @4597004 cast */
    /* @4597008 constant */
    /* @4597012 cast */
    /* @4597016 call */
    GM_SITE(vm, 424, 4597016);
    /* @4597024 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4597028 constant */
    /* @4597032 cast */
    /* @4597036 call */
    GM_SITE(vm, 424, 4597036);
    /* @4597044 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4597048 constant */
    /* @4597056 cast */
    /* @4597060 call */
    GM_SITE(vm, 424, 4597060);
    /* @4597068 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4597072 string */
    /* @4597080 cast */
    /* @4597084 load */
    /* @4597092 load */
    /* @4597100 constant */
    /* @4597104 add */
    /* @4597108 call */
    GM_SITE(vm, 424, 4597108);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4597116 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(804)));
    /* @4597120 string */
    /* @4597128 cast */
    /* @4597132 load */
    /* @4597140 constant */
    /* @4597144 add */
    /* @4597148 load */
    /* @4597156 constant */
    /* @4597160 add */
    /* @4597164 call */
    GM_SITE(vm, 424, 4597164);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4597172 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(803)));
    /* @4597176 constant */
    /* @4597180 cast */
    /* @4597184 constant */
    /* @4597188 cast */
    /* @4597192 constant */
    /* @4597196 cast */
    /* @4597200 constant */
    /* @4597212 cast */
    /* @4597216 constant */
    /* @4597228 cast */
    /* @4597232 load */
    /* @4597240 constant */
    /* @4597244 add */
    /* @4597248 load */
    /* @4597256 constant */
    /* @4597260 add */
    /* @4597264 constant */
    /* @4597268 cast */
    /* @4597272 constant */
    /* @4597276 cast */
    /* @4597280 call */
    GM_SITE(vm, 424, 4597280);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(28));
    /* @4597288 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(46), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4597292 load */
    /* @4597300 constant */
    /* @4597304 cmp */
    /* @4597308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_4597412;
    /* @4597312 constant */
    /* @4597316 cast */
    /* @4597320 constant */
    /* @4597324 cast */
    /* @4597328 constant */
    /* @4597332 cast */
    /* @4597336 constant */
    /* @4597348 cast */
    /* @4597352 constant */
    /* @4597364 cast */
    /* @4597368 load */
    /* @4597376 load */
    /* @4597384 constant */
    /* @4597388 cast */
    /* @4597392 constant */
    /* @4597396 cast */
    /* @4597400 call */
    GM_SITE(vm, 424, 4597400);
    /* @4597408 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4597412: ;
    return;
}
