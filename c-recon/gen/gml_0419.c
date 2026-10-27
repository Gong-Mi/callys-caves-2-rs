/* generated from CODE 419 (gml_Object_obj_powerupgrade3_Draw_0), source start 4586952, end 4590304. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0419(GmVM* vm) {
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
    /* @4586952 load */
    /* @4586960 constant */
    /* @4586964 cmp */
    /* @4586968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4587456;
    /* @4586972 constant */
    /* @4586976 cast */
    /* @4586980 constant */
    /* @4586984 cast */
    /* @4586988 constant */
    /* @4586992 cast */
    /* @4586996 constant */
    /* @4587008 cast */
    /* @4587012 constant */
    /* @4587024 cast */
    /* @4587028 load */
    /* @4587036 load */
    /* @4587044 constant */
    /* @4587048 cast */
    /* @4587052 constant */
    /* @4587056 cast */
    /* @4587060 call */
    GM_SITE(vm, 419, 4587060);
    /* @4587068 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4587072 constant */
    /* @4587076 cast */
    /* @4587080 call */
    GM_SITE(vm, 419, 4587080);
    /* @4587088 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4587092 constant */
    /* @4587100 cast */
    /* @4587104 call */
    GM_SITE(vm, 419, 4587104);
    /* @4587112 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4587116 string */
    /* @4587124 cast */
    /* @4587128 load */
    /* @4587136 load */
    /* @4587144 constant */
    /* @4587148 add */
    /* @4587152 call */
    GM_SITE(vm, 419, 4587152);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4587160 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(800)));
    /* @4587164 string */
    /* @4587172 cast */
    /* @4587176 load */
    /* @4587184 constant */
    /* @4587188 add */
    /* @4587192 load */
    /* @4587200 constant */
    /* @4587204 add */
    /* @4587208 call */
    GM_SITE(vm, 419, 4587208);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4587216 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(801)));
    /* @4587220 constant */
    /* @4587224 cast */
    /* @4587228 constant */
    /* @4587232 cast */
    /* @4587236 constant */
    /* @4587240 cast */
    /* @4587244 constant */
    /* @4587256 cast */
    /* @4587260 constant */
    /* @4587272 cast */
    /* @4587276 load */
    /* @4587284 constant */
    /* @4587288 add */
    /* @4587292 load */
    /* @4587300 constant */
    /* @4587304 add */
    /* @4587308 constant */
    /* @4587312 cast */
    /* @4587316 constant */
    /* @4587320 cast */
    /* @4587324 call */
    GM_SITE(vm, 419, 4587324);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4587332 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4587336 load */
    /* @4587344 constant */
    /* @4587348 cmp */
    /* @4587352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4587456;
    /* @4587356 constant */
    /* @4587360 cast */
    /* @4587364 constant */
    /* @4587368 cast */
    /* @4587372 constant */
    /* @4587376 cast */
    /* @4587380 constant */
    /* @4587392 cast */
    /* @4587396 constant */
    /* @4587408 cast */
    /* @4587412 load */
    /* @4587420 load */
    /* @4587428 constant */
    /* @4587432 cast */
    /* @4587436 constant */
    /* @4587440 cast */
    /* @4587444 call */
    GM_SITE(vm, 419, 4587444);
    /* @4587452 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4587456: ;
    /* @4587456 load */
    /* @4587464 constant */
    /* @4587468 cmp */
    /* @4587472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4588016;
    /* @4587476 constant */
    /* @4587480 constant */
    /* @4587484 load */
    /* @4587492 constant */
    /* @4587496 add */
    /* @4587500 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4587508 constant */
    /* @4587512 constant */
    /* @4587516 load */
    /* @4587524 constant */
    /* @4587528 add */
    /* @4587532 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    GM_WRITE(vm, -1, "y", v7);
    /* @4587540 constant */
    /* @4587544 cast */
    /* @4587548 constant */
    /* @4587552 cast */
    /* @4587556 constant */
    /* @4587560 cast */
    /* @4587564 constant */
    /* @4587568 cast */
    /* @4587572 constant */
    /* @4587576 cast */
    /* @4587580 load */
    /* @4587588 load */
    /* @4587596 constant */
    /* @4587600 cast */
    /* @4587604 constant */
    /* @4587608 cast */
    /* @4587612 call */
    GM_SITE(vm, 419, 4587612);
    /* @4587620 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4587624 constant */
    /* @4587628 cast */
    /* @4587632 call */
    GM_SITE(vm, 419, 4587632);
    /* @4587640 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4587644 constant */
    /* @4587652 cast */
    /* @4587656 call */
    GM_SITE(vm, 419, 4587656);
    /* @4587664 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4587668 string */
    /* @4587676 cast */
    /* @4587680 load */
    /* @4587688 constant */
    /* @4587692 add */
    /* @4587696 load */
    /* @4587704 constant */
    /* @4587708 add */
    /* @4587712 call */
    GM_SITE(vm, 419, 4587712);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4587720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(800)));
    /* @4587724 string */
    /* @4587732 cast */
    /* @4587736 load */
    /* @4587744 constant */
    /* @4587748 add */
    /* @4587752 load */
    /* @4587760 constant */
    /* @4587764 add */
    /* @4587768 call */
    GM_SITE(vm, 419, 4587768);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4587776 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(801)));
    /* @4587780 constant */
    /* @4587784 cast */
    /* @4587788 constant */
    /* @4587792 cast */
    /* @4587796 constant */
    /* @4587800 cast */
    /* @4587804 constant */
    /* @4587816 cast */
    /* @4587820 constant */
    /* @4587832 cast */
    /* @4587836 load */
    /* @4587844 constant */
    /* @4587848 add */
    /* @4587852 load */
    /* @4587860 constant */
    /* @4587864 add */
    /* @4587868 constant */
    /* @4587872 cast */
    /* @4587876 constant */
    /* @4587880 cast */
    /* @4587884 call */
    GM_SITE(vm, 419, 4587884);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4587892 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v12, v13, VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    /* @4587896 load */
    /* @4587904 constant */
    /* @4587908 cmp */
    /* @4587912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4588016;
    /* @4587916 constant */
    /* @4587920 cast */
    /* @4587924 constant */
    /* @4587928 cast */
    /* @4587932 constant */
    /* @4587936 cast */
    /* @4587940 constant */
    /* @4587952 cast */
    /* @4587956 constant */
    /* @4587968 cast */
    /* @4587972 load */
    /* @4587980 load */
    /* @4587988 constant */
    /* @4587992 cast */
    /* @4587996 constant */
    /* @4588000 cast */
    /* @4588004 call */
    GM_SITE(vm, 419, 4588004);
    /* @4588012 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4588016: ;
    /* @4588016 load */
    /* @4588024 constant */
    /* @4588028 cmp */
    /* @4588032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4588592;
    /* @4588036 constant */
    /* @4588040 constant */
    /* @4588044 load */
    /* @4588052 constant */
    /* @4588056 add */
    /* @4588060 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4588068 constant */
    /* @4588072 constant */
    /* @4588076 load */
    /* @4588084 constant */
    /* @4588088 add */
    /* @4588092 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    GM_WRITE(vm, -1, "y", v15);
    /* @4588100 constant */
    /* @4588104 cast */
    /* @4588108 constant */
    /* @4588112 cast */
    /* @4588116 constant */
    /* @4588120 cast */
    /* @4588124 constant */
    /* @4588136 cast */
    /* @4588140 constant */
    /* @4588152 cast */
    /* @4588156 load */
    /* @4588164 load */
    /* @4588172 constant */
    /* @4588176 cast */
    /* @4588180 constant */
    /* @4588184 cast */
    /* @4588188 call */
    GM_SITE(vm, 419, 4588188);
    /* @4588196 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4588200 constant */
    /* @4588204 cast */
    /* @4588208 call */
    GM_SITE(vm, 419, 4588208);
    /* @4588216 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4588220 constant */
    /* @4588228 cast */
    /* @4588232 call */
    GM_SITE(vm, 419, 4588232);
    /* @4588240 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4588244 string */
    /* @4588252 cast */
    /* @4588256 load */
    /* @4588264 constant */
    /* @4588268 add */
    /* @4588272 load */
    /* @4588280 constant */
    /* @4588284 add */
    /* @4588288 call */
    GM_SITE(vm, 419, 4588288);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4588296 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(800)));
    /* @4588300 string */
    /* @4588308 cast */
    /* @4588312 load */
    /* @4588320 constant */
    /* @4588324 add */
    /* @4588328 load */
    /* @4588336 constant */
    /* @4588340 add */
    /* @4588344 call */
    GM_SITE(vm, 419, 4588344);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4588352 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(801)));
    /* @4588356 constant */
    /* @4588360 cast */
    /* @4588364 constant */
    /* @4588368 cast */
    /* @4588372 constant */
    /* @4588376 cast */
    /* @4588380 constant */
    /* @4588392 cast */
    /* @4588396 constant */
    /* @4588408 cast */
    /* @4588412 load */
    /* @4588420 constant */
    /* @4588424 add */
    /* @4588428 load */
    /* @4588436 constant */
    /* @4588440 add */
    /* @4588444 constant */
    /* @4588448 cast */
    /* @4588452 constant */
    /* @4588456 cast */
    /* @4588460 call */
    GM_SITE(vm, 419, 4588460);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4588468 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v20, v21, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4588472 load */
    /* @4588480 constant */
    /* @4588484 cmp */
    /* @4588488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4588592;
    /* @4588492 constant */
    /* @4588496 cast */
    /* @4588500 constant */
    /* @4588504 cast */
    /* @4588508 constant */
    /* @4588512 cast */
    /* @4588516 constant */
    /* @4588528 cast */
    /* @4588532 constant */
    /* @4588544 cast */
    /* @4588548 load */
    /* @4588556 load */
    /* @4588564 constant */
    /* @4588568 cast */
    /* @4588572 constant */
    /* @4588576 cast */
    /* @4588580 call */
    GM_SITE(vm, 419, 4588580);
    /* @4588588 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4588592: ;
    /* @4588592 load */
    /* @4588600 constant */
    /* @4588604 cmp */
    /* @4588608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4589168;
    /* @4588612 constant */
    /* @4588616 constant */
    /* @4588620 load */
    /* @4588628 constant */
    /* @4588632 add */
    /* @4588636 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4588644 constant */
    /* @4588648 constant */
    /* @4588652 load */
    /* @4588660 constant */
    /* @4588664 add */
    /* @4588668 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    GM_WRITE(vm, -1, "y", v23);
    /* @4588676 constant */
    /* @4588680 cast */
    /* @4588684 constant */
    /* @4588688 cast */
    /* @4588692 constant */
    /* @4588696 cast */
    /* @4588700 constant */
    /* @4588712 cast */
    /* @4588716 constant */
    /* @4588728 cast */
    /* @4588732 load */
    /* @4588740 load */
    /* @4588748 constant */
    /* @4588752 cast */
    /* @4588756 constant */
    /* @4588760 cast */
    /* @4588764 call */
    GM_SITE(vm, 419, 4588764);
    /* @4588772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4588776 constant */
    /* @4588780 cast */
    /* @4588784 call */
    GM_SITE(vm, 419, 4588784);
    /* @4588792 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4588796 constant */
    /* @4588804 cast */
    /* @4588808 call */
    GM_SITE(vm, 419, 4588808);
    /* @4588816 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4588820 string */
    /* @4588828 cast */
    /* @4588832 load */
    /* @4588840 constant */
    /* @4588844 add */
    /* @4588848 load */
    /* @4588856 constant */
    /* @4588860 add */
    /* @4588864 call */
    GM_SITE(vm, 419, 4588864);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4588872 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(800)));
    /* @4588876 string */
    /* @4588884 cast */
    /* @4588888 load */
    /* @4588896 constant */
    /* @4588900 add */
    /* @4588904 load */
    /* @4588912 constant */
    /* @4588916 add */
    /* @4588920 call */
    GM_SITE(vm, 419, 4588920);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4588928 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(801)));
    /* @4588932 constant */
    /* @4588936 cast */
    /* @4588940 constant */
    /* @4588944 cast */
    /* @4588948 constant */
    /* @4588952 cast */
    /* @4588956 constant */
    /* @4588968 cast */
    /* @4588972 constant */
    /* @4588984 cast */
    /* @4588988 load */
    /* @4588996 constant */
    /* @4589000 add */
    /* @4589004 load */
    /* @4589012 constant */
    /* @4589016 add */
    /* @4589020 constant */
    /* @4589024 cast */
    /* @4589028 constant */
    /* @4589032 cast */
    /* @4589036 call */
    GM_SITE(vm, 419, 4589036);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(16));
    /* @4589044 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v28, v29, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4589048 load */
    /* @4589056 constant */
    /* @4589060 cmp */
    /* @4589064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4589168;
    /* @4589068 constant */
    /* @4589072 cast */
    /* @4589076 constant */
    /* @4589080 cast */
    /* @4589084 constant */
    /* @4589088 cast */
    /* @4589092 constant */
    /* @4589104 cast */
    /* @4589108 constant */
    /* @4589120 cast */
    /* @4589124 load */
    /* @4589132 load */
    /* @4589140 constant */
    /* @4589144 cast */
    /* @4589148 constant */
    /* @4589152 cast */
    /* @4589156 call */
    GM_SITE(vm, 419, 4589156);
    /* @4589164 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4589168: ;
    /* @4589168 load */
    /* @4589176 constant */
    /* @4589180 cmp */
    /* @4589184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4589736;
    /* @4589188 constant */
    /* @4589192 constant */
    /* @4589196 load */
    /* @4589204 constant */
    /* @4589208 add */
    /* @4589212 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4589220 constant */
    /* @4589224 constant */
    /* @4589228 load */
    /* @4589236 constant */
    /* @4589240 add */
    /* @4589244 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    GM_WRITE(vm, -1, "y", v31);
    /* @4589252 constant */
    /* @4589256 cast */
    /* @4589260 constant */
    /* @4589264 cast */
    /* @4589268 constant */
    /* @4589272 cast */
    /* @4589276 constant */
    /* @4589288 cast */
    /* @4589292 constant */
    /* @4589304 cast */
    /* @4589308 load */
    /* @4589316 load */
    /* @4589324 constant */
    /* @4589328 cast */
    /* @4589332 constant */
    /* @4589336 cast */
    /* @4589340 call */
    GM_SITE(vm, 419, 4589340);
    /* @4589348 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4589352 constant */
    /* @4589356 cast */
    /* @4589360 call */
    GM_SITE(vm, 419, 4589360);
    /* @4589368 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4589372 constant */
    /* @4589380 cast */
    /* @4589384 call */
    GM_SITE(vm, 419, 4589384);
    /* @4589392 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4589396 string */
    /* @4589404 cast */
    /* @4589408 load */
    /* @4589416 load */
    /* @4589424 constant */
    /* @4589428 add */
    /* @4589432 call */
    GM_SITE(vm, 419, 4589432);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4589440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(800)));
    /* @4589444 string */
    /* @4589452 cast */
    /* @4589456 load */
    /* @4589464 constant */
    /* @4589468 add */
    /* @4589472 load */
    /* @4589480 constant */
    /* @4589484 add */
    /* @4589488 call */
    GM_SITE(vm, 419, 4589488);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4589496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(801)));
    /* @4589500 constant */
    /* @4589504 cast */
    /* @4589508 constant */
    /* @4589512 cast */
    /* @4589516 constant */
    /* @4589520 cast */
    /* @4589524 constant */
    /* @4589536 cast */
    /* @4589540 constant */
    /* @4589552 cast */
    /* @4589556 load */
    /* @4589564 constant */
    /* @4589568 add */
    /* @4589572 load */
    /* @4589580 constant */
    /* @4589584 add */
    /* @4589588 constant */
    /* @4589592 cast */
    /* @4589596 constant */
    /* @4589600 cast */
    /* @4589604 call */
    GM_SITE(vm, 419, 4589604);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4589612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4589616 load */
    /* @4589624 constant */
    /* @4589628 cmp */
    /* @4589632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4589736;
    /* @4589636 constant */
    /* @4589640 cast */
    /* @4589644 constant */
    /* @4589648 cast */
    /* @4589652 constant */
    /* @4589656 cast */
    /* @4589660 constant */
    /* @4589672 cast */
    /* @4589676 constant */
    /* @4589688 cast */
    /* @4589692 load */
    /* @4589700 load */
    /* @4589708 constant */
    /* @4589712 cast */
    /* @4589716 constant */
    /* @4589720 cast */
    /* @4589724 call */
    GM_SITE(vm, 419, 4589724);
    /* @4589732 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4589736: ;
    /* @4589736 load */
    /* @4589744 constant */
    /* @4589748 cmp */
    /* @4589752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4590304;
    /* @4589756 constant */
    /* @4589760 constant */
    /* @4589764 load */
    /* @4589772 constant */
    /* @4589776 add */
    /* @4589780 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4589788 constant */
    /* @4589792 constant */
    /* @4589796 load */
    /* @4589804 constant */
    /* @4589808 add */
    /* @4589812 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    GM_WRITE(vm, -1, "y", v38);
    /* @4589820 constant */
    /* @4589824 cast */
    /* @4589828 constant */
    /* @4589832 cast */
    /* @4589836 constant */
    /* @4589840 cast */
    /* @4589844 constant */
    /* @4589856 cast */
    /* @4589860 constant */
    /* @4589872 cast */
    /* @4589876 load */
    /* @4589884 load */
    /* @4589892 constant */
    /* @4589896 cast */
    /* @4589900 constant */
    /* @4589904 cast */
    /* @4589908 call */
    GM_SITE(vm, 419, 4589908);
    /* @4589916 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4589920 constant */
    /* @4589924 cast */
    /* @4589928 call */
    GM_SITE(vm, 419, 4589928);
    /* @4589936 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4589940 constant */
    /* @4589948 cast */
    /* @4589952 call */
    GM_SITE(vm, 419, 4589952);
    /* @4589960 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4589964 string */
    /* @4589972 cast */
    /* @4589976 load */
    /* @4589984 load */
    /* @4589992 constant */
    /* @4589996 add */
    /* @4590000 call */
    GM_SITE(vm, 419, 4590000);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4590008 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(800)));
    /* @4590012 string */
    /* @4590020 cast */
    /* @4590024 load */
    /* @4590032 constant */
    /* @4590036 add */
    /* @4590040 load */
    /* @4590048 constant */
    /* @4590052 add */
    /* @4590056 call */
    GM_SITE(vm, 419, 4590056);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4590064 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(801)));
    /* @4590068 constant */
    /* @4590072 cast */
    /* @4590076 constant */
    /* @4590080 cast */
    /* @4590084 constant */
    /* @4590088 cast */
    /* @4590092 constant */
    /* @4590104 cast */
    /* @4590108 constant */
    /* @4590120 cast */
    /* @4590124 load */
    /* @4590132 constant */
    /* @4590136 add */
    /* @4590140 load */
    /* @4590148 constant */
    /* @4590152 add */
    /* @4590156 constant */
    /* @4590160 cast */
    /* @4590164 constant */
    /* @4590168 cast */
    /* @4590172 call */
    GM_SITE(vm, 419, 4590172);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4590180 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(1), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4590184 load */
    /* @4590192 constant */
    /* @4590196 cmp */
    /* @4590200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(1)))) goto L_4590304;
    /* @4590204 constant */
    /* @4590208 cast */
    /* @4590212 constant */
    /* @4590216 cast */
    /* @4590220 constant */
    /* @4590224 cast */
    /* @4590228 constant */
    /* @4590240 cast */
    /* @4590244 constant */
    /* @4590256 cast */
    /* @4590260 load */
    /* @4590268 load */
    /* @4590276 constant */
    /* @4590280 cast */
    /* @4590284 constant */
    /* @4590288 cast */
    /* @4590292 call */
    GM_SITE(vm, 419, 4590292);
    /* @4590300 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4590304: ;
    return;
}
