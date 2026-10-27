/* generated from CODE 440 (gml_Object_obj_coinmultiplier2_Draw_0), source start 4622164, end 4625452. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0440(GmVM* vm) {
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
    /* @4622164 load */
    /* @4622172 constant */
    /* @4622176 cmp */
    /* @4622180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4622652;
    /* @4622184 constant */
    /* @4622188 cast */
    /* @4622192 constant */
    /* @4622196 cast */
    /* @4622200 constant */
    /* @4622204 cast */
    /* @4622208 constant */
    /* @4622220 cast */
    /* @4622224 constant */
    /* @4622236 cast */
    /* @4622240 load */
    /* @4622248 load */
    /* @4622256 constant */
    /* @4622260 cast */
    /* @4622264 constant */
    /* @4622268 cast */
    /* @4622272 call */
    GM_SITE(vm, 440, 4622272);
    /* @4622280 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4622284 constant */
    /* @4622288 cast */
    /* @4622292 call */
    GM_SITE(vm, 440, 4622292);
    /* @4622300 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4622304 constant */
    /* @4622312 cast */
    /* @4622316 call */
    GM_SITE(vm, 440, 4622316);
    /* @4622324 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4622328 string */
    /* @4622336 cast */
    /* @4622340 load */
    /* @4622348 load */
    /* @4622356 constant */
    /* @4622360 add */
    /* @4622364 call */
    GM_SITE(vm, 440, 4622364);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4622372 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(817)));
    /* @4622376 string */
    /* @4622384 cast */
    /* @4622388 load */
    /* @4622396 constant */
    /* @4622400 add */
    /* @4622404 load */
    /* @4622412 constant */
    /* @4622416 add */
    /* @4622420 call */
    GM_SITE(vm, 440, 4622420);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4622428 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(818)));
    /* @4622432 constant */
    /* @4622436 cast */
    /* @4622440 constant */
    /* @4622444 cast */
    /* @4622448 constant */
    /* @4622452 cast */
    /* @4622456 constant */
    /* @4622460 cast */
    /* @4622464 constant */
    /* @4622468 cast */
    /* @4622472 load */
    /* @4622480 constant */
    /* @4622484 add */
    /* @4622488 load */
    /* @4622496 constant */
    /* @4622500 add */
    /* @4622504 constant */
    /* @4622508 cast */
    /* @4622512 constant */
    /* @4622516 cast */
    /* @4622520 call */
    GM_SITE(vm, 440, 4622520);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4622528 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4622532 load */
    /* @4622540 constant */
    /* @4622544 cmp */
    /* @4622548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4622652;
    /* @4622552 constant */
    /* @4622556 cast */
    /* @4622560 constant */
    /* @4622564 cast */
    /* @4622568 constant */
    /* @4622572 cast */
    /* @4622576 constant */
    /* @4622588 cast */
    /* @4622592 constant */
    /* @4622604 cast */
    /* @4622608 load */
    /* @4622616 load */
    /* @4622624 constant */
    /* @4622628 cast */
    /* @4622632 constant */
    /* @4622636 cast */
    /* @4622640 call */
    GM_SITE(vm, 440, 4622640);
    /* @4622648 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4622652: ;
    /* @4622652 load */
    /* @4622660 constant */
    /* @4622664 cmp */
    /* @4622668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4623196;
    /* @4622672 constant */
    /* @4622676 constant */
    /* @4622680 load */
    /* @4622688 constant */
    /* @4622692 add */
    /* @4622696 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4622704 constant */
    /* @4622708 constant */
    /* @4622712 load */
    /* @4622720 constant */
    /* @4622724 add */
    /* @4622728 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    GM_WRITE(vm, -1, "y", v7);
    /* @4622736 constant */
    /* @4622740 cast */
    /* @4622744 constant */
    /* @4622748 cast */
    /* @4622752 constant */
    /* @4622756 cast */
    /* @4622760 constant */
    /* @4622764 cast */
    /* @4622768 constant */
    /* @4622772 cast */
    /* @4622776 load */
    /* @4622784 load */
    /* @4622792 constant */
    /* @4622796 cast */
    /* @4622800 constant */
    /* @4622804 cast */
    /* @4622808 call */
    GM_SITE(vm, 440, 4622808);
    /* @4622816 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4622820 constant */
    /* @4622824 cast */
    /* @4622828 call */
    GM_SITE(vm, 440, 4622828);
    /* @4622836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4622840 constant */
    /* @4622848 cast */
    /* @4622852 call */
    GM_SITE(vm, 440, 4622852);
    /* @4622860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4622864 string */
    /* @4622872 cast */
    /* @4622876 load */
    /* @4622884 constant */
    /* @4622888 add */
    /* @4622892 load */
    /* @4622900 constant */
    /* @4622904 add */
    /* @4622908 call */
    GM_SITE(vm, 440, 4622908);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4622916 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(817)));
    /* @4622920 string */
    /* @4622928 cast */
    /* @4622932 load */
    /* @4622940 constant */
    /* @4622944 add */
    /* @4622948 load */
    /* @4622956 constant */
    /* @4622960 add */
    /* @4622964 call */
    GM_SITE(vm, 440, 4622964);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4622972 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(818)));
    /* @4622976 constant */
    /* @4622980 cast */
    /* @4622984 constant */
    /* @4622988 cast */
    /* @4622992 constant */
    /* @4622996 cast */
    /* @4623000 constant */
    /* @4623004 cast */
    /* @4623008 constant */
    /* @4623012 cast */
    /* @4623016 load */
    /* @4623024 constant */
    /* @4623028 add */
    /* @4623032 load */
    /* @4623040 constant */
    /* @4623044 add */
    /* @4623048 constant */
    /* @4623052 cast */
    /* @4623056 constant */
    /* @4623060 cast */
    /* @4623064 call */
    GM_SITE(vm, 440, 4623064);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4623072 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v12, v13, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4623076 load */
    /* @4623084 constant */
    /* @4623088 cmp */
    /* @4623092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4623196;
    /* @4623096 constant */
    /* @4623100 cast */
    /* @4623104 constant */
    /* @4623108 cast */
    /* @4623112 constant */
    /* @4623116 cast */
    /* @4623120 constant */
    /* @4623132 cast */
    /* @4623136 constant */
    /* @4623148 cast */
    /* @4623152 load */
    /* @4623160 load */
    /* @4623168 constant */
    /* @4623172 cast */
    /* @4623176 constant */
    /* @4623180 cast */
    /* @4623184 call */
    GM_SITE(vm, 440, 4623184);
    /* @4623192 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4623196: ;
    /* @4623196 load */
    /* @4623204 constant */
    /* @4623208 cmp */
    /* @4623212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4623772;
    /* @4623216 constant */
    /* @4623220 constant */
    /* @4623224 load */
    /* @4623232 constant */
    /* @4623236 add */
    /* @4623240 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4623248 constant */
    /* @4623252 constant */
    /* @4623256 load */
    /* @4623264 constant */
    /* @4623268 add */
    /* @4623272 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    GM_WRITE(vm, -1, "y", v15);
    /* @4623280 constant */
    /* @4623284 cast */
    /* @4623288 constant */
    /* @4623292 cast */
    /* @4623296 constant */
    /* @4623300 cast */
    /* @4623304 constant */
    /* @4623316 cast */
    /* @4623320 constant */
    /* @4623332 cast */
    /* @4623336 load */
    /* @4623344 load */
    /* @4623352 constant */
    /* @4623356 cast */
    /* @4623360 constant */
    /* @4623364 cast */
    /* @4623368 call */
    GM_SITE(vm, 440, 4623368);
    /* @4623376 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4623380 constant */
    /* @4623384 cast */
    /* @4623388 call */
    GM_SITE(vm, 440, 4623388);
    /* @4623396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4623400 constant */
    /* @4623408 cast */
    /* @4623412 call */
    GM_SITE(vm, 440, 4623412);
    /* @4623420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4623424 string */
    /* @4623432 cast */
    /* @4623436 load */
    /* @4623444 constant */
    /* @4623448 add */
    /* @4623452 load */
    /* @4623460 constant */
    /* @4623464 add */
    /* @4623468 call */
    GM_SITE(vm, 440, 4623468);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4623476 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(817)));
    /* @4623480 string */
    /* @4623488 cast */
    /* @4623492 load */
    /* @4623500 constant */
    /* @4623504 add */
    /* @4623508 load */
    /* @4623516 constant */
    /* @4623520 add */
    /* @4623524 call */
    GM_SITE(vm, 440, 4623524);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4623532 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(818)));
    /* @4623536 constant */
    /* @4623540 cast */
    /* @4623544 constant */
    /* @4623548 cast */
    /* @4623552 constant */
    /* @4623556 cast */
    /* @4623560 constant */
    /* @4623572 cast */
    /* @4623576 constant */
    /* @4623588 cast */
    /* @4623592 load */
    /* @4623600 constant */
    /* @4623604 add */
    /* @4623608 load */
    /* @4623616 constant */
    /* @4623620 add */
    /* @4623624 constant */
    /* @4623628 cast */
    /* @4623632 constant */
    /* @4623636 cast */
    /* @4623640 call */
    GM_SITE(vm, 440, 4623640);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4623648 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v20, v21, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4623652 load */
    /* @4623660 constant */
    /* @4623664 cmp */
    /* @4623668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4623772;
    /* @4623672 constant */
    /* @4623676 cast */
    /* @4623680 constant */
    /* @4623684 cast */
    /* @4623688 constant */
    /* @4623692 cast */
    /* @4623696 constant */
    /* @4623708 cast */
    /* @4623712 constant */
    /* @4623724 cast */
    /* @4623728 load */
    /* @4623736 load */
    /* @4623744 constant */
    /* @4623748 cast */
    /* @4623752 constant */
    /* @4623756 cast */
    /* @4623760 call */
    GM_SITE(vm, 440, 4623760);
    /* @4623768 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4623772: ;
    /* @4623772 load */
    /* @4623780 constant */
    /* @4623784 cmp */
    /* @4623788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4624348;
    /* @4623792 constant */
    /* @4623796 constant */
    /* @4623800 load */
    /* @4623808 constant */
    /* @4623812 add */
    /* @4623816 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4623824 constant */
    /* @4623828 constant */
    /* @4623832 load */
    /* @4623840 constant */
    /* @4623844 add */
    /* @4623848 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(100));
    GM_WRITE(vm, -1, "y", v23);
    /* @4623856 constant */
    /* @4623860 cast */
    /* @4623864 constant */
    /* @4623868 cast */
    /* @4623872 constant */
    /* @4623876 cast */
    /* @4623880 constant */
    /* @4623892 cast */
    /* @4623896 constant */
    /* @4623908 cast */
    /* @4623912 load */
    /* @4623920 load */
    /* @4623928 constant */
    /* @4623932 cast */
    /* @4623936 constant */
    /* @4623940 cast */
    /* @4623944 call */
    GM_SITE(vm, 440, 4623944);
    /* @4623952 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4623956 constant */
    /* @4623960 cast */
    /* @4623964 call */
    GM_SITE(vm, 440, 4623964);
    /* @4623972 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4623976 constant */
    /* @4623984 cast */
    /* @4623988 call */
    GM_SITE(vm, 440, 4623988);
    /* @4623996 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4624000 string */
    /* @4624008 cast */
    /* @4624012 load */
    /* @4624020 constant */
    /* @4624024 add */
    /* @4624028 load */
    /* @4624036 constant */
    /* @4624040 add */
    /* @4624044 call */
    GM_SITE(vm, 440, 4624044);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4624052 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(817)));
    /* @4624056 string */
    /* @4624064 cast */
    /* @4624068 load */
    /* @4624076 constant */
    /* @4624080 add */
    /* @4624084 load */
    /* @4624092 constant */
    /* @4624096 add */
    /* @4624100 call */
    GM_SITE(vm, 440, 4624100);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4624108 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(818)));
    /* @4624112 constant */
    /* @4624116 cast */
    /* @4624120 constant */
    /* @4624124 cast */
    /* @4624128 constant */
    /* @4624132 cast */
    /* @4624136 constant */
    /* @4624148 cast */
    /* @4624152 constant */
    /* @4624164 cast */
    /* @4624168 load */
    /* @4624176 constant */
    /* @4624180 add */
    /* @4624184 load */
    /* @4624192 constant */
    /* @4624196 add */
    /* @4624200 constant */
    /* @4624204 cast */
    /* @4624208 constant */
    /* @4624212 cast */
    /* @4624216 call */
    GM_SITE(vm, 440, 4624216);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4624224 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v28, v29, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4624228 load */
    /* @4624236 constant */
    /* @4624240 cmp */
    /* @4624244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4624348;
    /* @4624248 constant */
    /* @4624252 cast */
    /* @4624256 constant */
    /* @4624260 cast */
    /* @4624264 constant */
    /* @4624268 cast */
    /* @4624272 constant */
    /* @4624284 cast */
    /* @4624288 constant */
    /* @4624300 cast */
    /* @4624304 load */
    /* @4624312 load */
    /* @4624320 constant */
    /* @4624324 cast */
    /* @4624328 constant */
    /* @4624332 cast */
    /* @4624336 call */
    GM_SITE(vm, 440, 4624336);
    /* @4624344 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4624348: ;
    /* @4624348 load */
    /* @4624356 constant */
    /* @4624360 cmp */
    /* @4624364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4624900;
    /* @4624368 constant */
    /* @4624372 constant */
    /* @4624376 load */
    /* @4624384 constant */
    /* @4624388 add */
    /* @4624392 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4624400 constant */
    /* @4624404 constant */
    /* @4624408 load */
    /* @4624416 constant */
    /* @4624420 add */
    /* @4624424 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    GM_WRITE(vm, -1, "y", v31);
    /* @4624432 constant */
    /* @4624436 cast */
    /* @4624440 constant */
    /* @4624444 cast */
    /* @4624448 constant */
    /* @4624452 cast */
    /* @4624456 constant */
    /* @4624468 cast */
    /* @4624472 constant */
    /* @4624484 cast */
    /* @4624488 load */
    /* @4624496 load */
    /* @4624504 constant */
    /* @4624508 cast */
    /* @4624512 constant */
    /* @4624516 cast */
    /* @4624520 call */
    GM_SITE(vm, 440, 4624520);
    /* @4624528 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4624532 constant */
    /* @4624536 cast */
    /* @4624540 call */
    GM_SITE(vm, 440, 4624540);
    /* @4624548 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4624552 constant */
    /* @4624560 cast */
    /* @4624564 call */
    GM_SITE(vm, 440, 4624564);
    /* @4624572 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4624576 string */
    /* @4624584 cast */
    /* @4624588 load */
    /* @4624596 load */
    /* @4624604 constant */
    /* @4624608 add */
    /* @4624612 call */
    GM_SITE(vm, 440, 4624612);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4624620 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(817)));
    /* @4624624 string */
    /* @4624632 cast */
    /* @4624636 load */
    /* @4624644 constant */
    /* @4624648 add */
    /* @4624652 load */
    /* @4624660 constant */
    /* @4624664 add */
    /* @4624668 call */
    GM_SITE(vm, 440, 4624668);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4624676 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(818)));
    /* @4624680 constant */
    /* @4624684 cast */
    /* @4624688 constant */
    /* @4624692 cast */
    /* @4624696 constant */
    /* @4624700 cast */
    /* @4624704 constant */
    /* @4624708 cast */
    /* @4624712 constant */
    /* @4624716 cast */
    /* @4624720 load */
    /* @4624728 constant */
    /* @4624732 add */
    /* @4624736 load */
    /* @4624744 constant */
    /* @4624748 add */
    /* @4624752 constant */
    /* @4624756 cast */
    /* @4624760 constant */
    /* @4624764 cast */
    /* @4624768 call */
    GM_SITE(vm, 440, 4624768);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4624776 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4624780 load */
    /* @4624788 constant */
    /* @4624792 cmp */
    /* @4624796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4624900;
    /* @4624800 constant */
    /* @4624804 cast */
    /* @4624808 constant */
    /* @4624812 cast */
    /* @4624816 constant */
    /* @4624820 cast */
    /* @4624824 constant */
    /* @4624836 cast */
    /* @4624840 constant */
    /* @4624852 cast */
    /* @4624856 load */
    /* @4624864 load */
    /* @4624872 constant */
    /* @4624876 cast */
    /* @4624880 constant */
    /* @4624884 cast */
    /* @4624888 call */
    GM_SITE(vm, 440, 4624888);
    /* @4624896 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4624900: ;
    /* @4624900 load */
    /* @4624908 constant */
    /* @4624912 cmp */
    /* @4624916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4625452;
    /* @4624920 constant */
    /* @4624924 constant */
    /* @4624928 load */
    /* @4624936 constant */
    /* @4624940 add */
    /* @4624944 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4624952 constant */
    /* @4624956 constant */
    /* @4624960 load */
    /* @4624968 constant */
    /* @4624972 add */
    /* @4624976 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    GM_WRITE(vm, -1, "y", v38);
    /* @4624984 constant */
    /* @4624988 cast */
    /* @4624992 constant */
    /* @4624996 cast */
    /* @4625000 constant */
    /* @4625004 cast */
    /* @4625008 constant */
    /* @4625020 cast */
    /* @4625024 constant */
    /* @4625036 cast */
    /* @4625040 load */
    /* @4625048 load */
    /* @4625056 constant */
    /* @4625060 cast */
    /* @4625064 constant */
    /* @4625068 cast */
    /* @4625072 call */
    GM_SITE(vm, 440, 4625072);
    /* @4625080 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4625084 constant */
    /* @4625088 cast */
    /* @4625092 call */
    GM_SITE(vm, 440, 4625092);
    /* @4625100 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4625104 constant */
    /* @4625112 cast */
    /* @4625116 call */
    GM_SITE(vm, 440, 4625116);
    /* @4625124 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4625128 string */
    /* @4625136 cast */
    /* @4625140 load */
    /* @4625148 load */
    /* @4625156 constant */
    /* @4625160 add */
    /* @4625164 call */
    GM_SITE(vm, 440, 4625164);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4625172 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(817)));
    /* @4625176 string */
    /* @4625184 cast */
    /* @4625188 load */
    /* @4625196 constant */
    /* @4625200 add */
    /* @4625204 load */
    /* @4625212 constant */
    /* @4625216 add */
    /* @4625220 call */
    GM_SITE(vm, 440, 4625220);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4625228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(818)));
    /* @4625232 constant */
    /* @4625236 cast */
    /* @4625240 constant */
    /* @4625244 cast */
    /* @4625248 constant */
    /* @4625252 cast */
    /* @4625256 constant */
    /* @4625260 cast */
    /* @4625264 constant */
    /* @4625268 cast */
    /* @4625272 load */
    /* @4625280 constant */
    /* @4625284 add */
    /* @4625288 load */
    /* @4625296 constant */
    /* @4625300 add */
    /* @4625304 constant */
    /* @4625308 cast */
    /* @4625312 constant */
    /* @4625316 cast */
    /* @4625320 call */
    GM_SITE(vm, 440, 4625320);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4625328 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4625332 load */
    /* @4625340 constant */
    /* @4625344 cmp */
    /* @4625348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(1)))) goto L_4625452;
    /* @4625352 constant */
    /* @4625356 cast */
    /* @4625360 constant */
    /* @4625364 cast */
    /* @4625368 constant */
    /* @4625372 cast */
    /* @4625376 constant */
    /* @4625388 cast */
    /* @4625392 constant */
    /* @4625404 cast */
    /* @4625408 load */
    /* @4625416 load */
    /* @4625424 constant */
    /* @4625428 cast */
    /* @4625432 constant */
    /* @4625436 cast */
    /* @4625440 call */
    GM_SITE(vm, 440, 4625440);
    /* @4625448 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4625452: ;
    return;
}
