/* generated from CODE 438 (gml_Object_obj_coinmultiplier5_Draw_0), source start 4618700, end 4621988. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0438(GmVM* vm) {
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
    /* @4618700 load */
    /* @4618708 constant */
    /* @4618712 cmp */
    /* @4618716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4619188;
    /* @4618720 constant */
    /* @4618724 cast */
    /* @4618728 constant */
    /* @4618732 cast */
    /* @4618736 constant */
    /* @4618740 cast */
    /* @4618744 constant */
    /* @4618756 cast */
    /* @4618760 constant */
    /* @4618772 cast */
    /* @4618776 load */
    /* @4618784 load */
    /* @4618792 constant */
    /* @4618796 cast */
    /* @4618800 constant */
    /* @4618804 cast */
    /* @4618808 call */
    GM_SITE(vm, 438, 4618808);
    /* @4618816 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4618820 constant */
    /* @4618824 cast */
    /* @4618828 call */
    GM_SITE(vm, 438, 4618828);
    /* @4618836 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4618840 constant */
    /* @4618848 cast */
    /* @4618852 call */
    GM_SITE(vm, 438, 4618852);
    /* @4618860 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4618864 string */
    /* @4618872 cast */
    /* @4618876 load */
    /* @4618884 load */
    /* @4618892 constant */
    /* @4618896 add */
    /* @4618900 call */
    GM_SITE(vm, 438, 4618900);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4618908 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(816)));
    /* @4618912 string */
    /* @4618920 cast */
    /* @4618924 load */
    /* @4618932 constant */
    /* @4618936 add */
    /* @4618940 load */
    /* @4618948 constant */
    /* @4618952 add */
    /* @4618956 call */
    GM_SITE(vm, 438, 4618956);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4618964 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(815)));
    /* @4618968 constant */
    /* @4618972 cast */
    /* @4618976 constant */
    /* @4618980 cast */
    /* @4618984 constant */
    /* @4618988 cast */
    /* @4618992 constant */
    /* @4618996 cast */
    /* @4619000 constant */
    /* @4619004 cast */
    /* @4619008 load */
    /* @4619016 constant */
    /* @4619020 add */
    /* @4619024 load */
    /* @4619032 constant */
    /* @4619036 add */
    /* @4619040 constant */
    /* @4619044 cast */
    /* @4619048 constant */
    /* @4619052 cast */
    /* @4619056 call */
    GM_SITE(vm, 438, 4619056);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4619064 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4619068 load */
    /* @4619076 constant */
    /* @4619080 cmp */
    /* @4619084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4619188;
    /* @4619088 constant */
    /* @4619092 cast */
    /* @4619096 constant */
    /* @4619100 cast */
    /* @4619104 constant */
    /* @4619108 cast */
    /* @4619112 constant */
    /* @4619124 cast */
    /* @4619128 constant */
    /* @4619140 cast */
    /* @4619144 load */
    /* @4619152 load */
    /* @4619160 constant */
    /* @4619164 cast */
    /* @4619168 constant */
    /* @4619172 cast */
    /* @4619176 call */
    GM_SITE(vm, 438, 4619176);
    /* @4619184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4619188: ;
    /* @4619188 load */
    /* @4619196 constant */
    /* @4619200 cmp */
    /* @4619204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4619732;
    /* @4619208 constant */
    /* @4619212 constant */
    /* @4619216 load */
    /* @4619224 constant */
    /* @4619228 add */
    /* @4619232 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4619240 constant */
    /* @4619244 constant */
    /* @4619248 load */
    /* @4619256 constant */
    /* @4619260 add */
    /* @4619264 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    GM_WRITE(vm, -1, "y", v7);
    /* @4619272 constant */
    /* @4619276 cast */
    /* @4619280 constant */
    /* @4619284 cast */
    /* @4619288 constant */
    /* @4619292 cast */
    /* @4619296 constant */
    /* @4619300 cast */
    /* @4619304 constant */
    /* @4619308 cast */
    /* @4619312 load */
    /* @4619320 load */
    /* @4619328 constant */
    /* @4619332 cast */
    /* @4619336 constant */
    /* @4619340 cast */
    /* @4619344 call */
    GM_SITE(vm, 438, 4619344);
    /* @4619352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4619356 constant */
    /* @4619360 cast */
    /* @4619364 call */
    GM_SITE(vm, 438, 4619364);
    /* @4619372 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4619376 constant */
    /* @4619384 cast */
    /* @4619388 call */
    GM_SITE(vm, 438, 4619388);
    /* @4619396 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4619400 string */
    /* @4619408 cast */
    /* @4619412 load */
    /* @4619420 constant */
    /* @4619424 add */
    /* @4619428 load */
    /* @4619436 constant */
    /* @4619440 add */
    /* @4619444 call */
    GM_SITE(vm, 438, 4619444);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4619452 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(816)));
    /* @4619456 string */
    /* @4619464 cast */
    /* @4619468 load */
    /* @4619476 constant */
    /* @4619480 add */
    /* @4619484 load */
    /* @4619492 constant */
    /* @4619496 add */
    /* @4619500 call */
    GM_SITE(vm, 438, 4619500);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4619508 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(815)));
    /* @4619512 constant */
    /* @4619516 cast */
    /* @4619520 constant */
    /* @4619524 cast */
    /* @4619528 constant */
    /* @4619532 cast */
    /* @4619536 constant */
    /* @4619540 cast */
    /* @4619544 constant */
    /* @4619548 cast */
    /* @4619552 load */
    /* @4619560 constant */
    /* @4619564 add */
    /* @4619568 load */
    /* @4619576 constant */
    /* @4619580 add */
    /* @4619584 constant */
    /* @4619588 cast */
    /* @4619592 constant */
    /* @4619596 cast */
    /* @4619600 call */
    GM_SITE(vm, 438, 4619600);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4619608 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v12, v13, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4619612 load */
    /* @4619620 constant */
    /* @4619624 cmp */
    /* @4619628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4619732;
    /* @4619632 constant */
    /* @4619636 cast */
    /* @4619640 constant */
    /* @4619644 cast */
    /* @4619648 constant */
    /* @4619652 cast */
    /* @4619656 constant */
    /* @4619668 cast */
    /* @4619672 constant */
    /* @4619684 cast */
    /* @4619688 load */
    /* @4619696 load */
    /* @4619704 constant */
    /* @4619708 cast */
    /* @4619712 constant */
    /* @4619716 cast */
    /* @4619720 call */
    GM_SITE(vm, 438, 4619720);
    /* @4619728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4619732: ;
    /* @4619732 load */
    /* @4619740 constant */
    /* @4619744 cmp */
    /* @4619748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4620308;
    /* @4619752 constant */
    /* @4619756 constant */
    /* @4619760 load */
    /* @4619768 constant */
    /* @4619772 add */
    /* @4619776 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4619784 constant */
    /* @4619788 constant */
    /* @4619792 load */
    /* @4619800 constant */
    /* @4619804 add */
    /* @4619808 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    GM_WRITE(vm, -1, "y", v15);
    /* @4619816 constant */
    /* @4619820 cast */
    /* @4619824 constant */
    /* @4619828 cast */
    /* @4619832 constant */
    /* @4619836 cast */
    /* @4619840 constant */
    /* @4619852 cast */
    /* @4619856 constant */
    /* @4619868 cast */
    /* @4619872 load */
    /* @4619880 load */
    /* @4619888 constant */
    /* @4619892 cast */
    /* @4619896 constant */
    /* @4619900 cast */
    /* @4619904 call */
    GM_SITE(vm, 438, 4619904);
    /* @4619912 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4619916 constant */
    /* @4619920 cast */
    /* @4619924 call */
    GM_SITE(vm, 438, 4619924);
    /* @4619932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4619936 constant */
    /* @4619944 cast */
    /* @4619948 call */
    GM_SITE(vm, 438, 4619948);
    /* @4619956 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4619960 string */
    /* @4619968 cast */
    /* @4619972 load */
    /* @4619980 constant */
    /* @4619984 add */
    /* @4619988 load */
    /* @4619996 constant */
    /* @4620000 add */
    /* @4620004 call */
    GM_SITE(vm, 438, 4620004);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4620012 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(816)));
    /* @4620016 string */
    /* @4620024 cast */
    /* @4620028 load */
    /* @4620036 constant */
    /* @4620040 add */
    /* @4620044 load */
    /* @4620052 constant */
    /* @4620056 add */
    /* @4620060 call */
    GM_SITE(vm, 438, 4620060);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4620068 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(815)));
    /* @4620072 constant */
    /* @4620076 cast */
    /* @4620080 constant */
    /* @4620084 cast */
    /* @4620088 constant */
    /* @4620092 cast */
    /* @4620096 constant */
    /* @4620108 cast */
    /* @4620112 constant */
    /* @4620124 cast */
    /* @4620128 load */
    /* @4620136 constant */
    /* @4620140 add */
    /* @4620144 load */
    /* @4620152 constant */
    /* @4620156 add */
    /* @4620160 constant */
    /* @4620164 cast */
    /* @4620168 constant */
    /* @4620172 cast */
    /* @4620176 call */
    GM_SITE(vm, 438, 4620176);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4620184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v20, v21, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4620188 load */
    /* @4620196 constant */
    /* @4620200 cmp */
    /* @4620204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4620308;
    /* @4620208 constant */
    /* @4620212 cast */
    /* @4620216 constant */
    /* @4620220 cast */
    /* @4620224 constant */
    /* @4620228 cast */
    /* @4620232 constant */
    /* @4620244 cast */
    /* @4620248 constant */
    /* @4620260 cast */
    /* @4620264 load */
    /* @4620272 load */
    /* @4620280 constant */
    /* @4620284 cast */
    /* @4620288 constant */
    /* @4620292 cast */
    /* @4620296 call */
    GM_SITE(vm, 438, 4620296);
    /* @4620304 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4620308: ;
    /* @4620308 load */
    /* @4620316 constant */
    /* @4620320 cmp */
    /* @4620324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4620884;
    /* @4620328 constant */
    /* @4620332 constant */
    /* @4620336 load */
    /* @4620344 constant */
    /* @4620348 add */
    /* @4620352 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4620360 constant */
    /* @4620364 constant */
    /* @4620368 load */
    /* @4620376 constant */
    /* @4620380 add */
    /* @4620384 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(140));
    GM_WRITE(vm, -1, "y", v23);
    /* @4620392 constant */
    /* @4620396 cast */
    /* @4620400 constant */
    /* @4620404 cast */
    /* @4620408 constant */
    /* @4620412 cast */
    /* @4620416 constant */
    /* @4620428 cast */
    /* @4620432 constant */
    /* @4620444 cast */
    /* @4620448 load */
    /* @4620456 load */
    /* @4620464 constant */
    /* @4620468 cast */
    /* @4620472 constant */
    /* @4620476 cast */
    /* @4620480 call */
    GM_SITE(vm, 438, 4620480);
    /* @4620488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4620492 constant */
    /* @4620496 cast */
    /* @4620500 call */
    GM_SITE(vm, 438, 4620500);
    /* @4620508 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4620512 constant */
    /* @4620520 cast */
    /* @4620524 call */
    GM_SITE(vm, 438, 4620524);
    /* @4620532 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4620536 string */
    /* @4620544 cast */
    /* @4620548 load */
    /* @4620556 constant */
    /* @4620560 add */
    /* @4620564 load */
    /* @4620572 constant */
    /* @4620576 add */
    /* @4620580 call */
    GM_SITE(vm, 438, 4620580);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4620588 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(816)));
    /* @4620592 string */
    /* @4620600 cast */
    /* @4620604 load */
    /* @4620612 constant */
    /* @4620616 add */
    /* @4620620 load */
    /* @4620628 constant */
    /* @4620632 add */
    /* @4620636 call */
    GM_SITE(vm, 438, 4620636);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4620644 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(815)));
    /* @4620648 constant */
    /* @4620652 cast */
    /* @4620656 constant */
    /* @4620660 cast */
    /* @4620664 constant */
    /* @4620668 cast */
    /* @4620672 constant */
    /* @4620684 cast */
    /* @4620688 constant */
    /* @4620700 cast */
    /* @4620704 load */
    /* @4620712 constant */
    /* @4620716 add */
    /* @4620720 load */
    /* @4620728 constant */
    /* @4620732 add */
    /* @4620736 constant */
    /* @4620740 cast */
    /* @4620744 constant */
    /* @4620748 cast */
    /* @4620752 call */
    GM_SITE(vm, 438, 4620752);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4620760 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v28, v29, VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4620764 load */
    /* @4620772 constant */
    /* @4620776 cmp */
    /* @4620780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4620884;
    /* @4620784 constant */
    /* @4620788 cast */
    /* @4620792 constant */
    /* @4620796 cast */
    /* @4620800 constant */
    /* @4620804 cast */
    /* @4620808 constant */
    /* @4620820 cast */
    /* @4620824 constant */
    /* @4620836 cast */
    /* @4620840 load */
    /* @4620848 load */
    /* @4620856 constant */
    /* @4620860 cast */
    /* @4620864 constant */
    /* @4620868 cast */
    /* @4620872 call */
    GM_SITE(vm, 438, 4620872);
    /* @4620880 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4620884: ;
    /* @4620884 load */
    /* @4620892 constant */
    /* @4620896 cmp */
    /* @4620900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4621436;
    /* @4620904 constant */
    /* @4620908 constant */
    /* @4620912 load */
    /* @4620920 constant */
    /* @4620924 add */
    /* @4620928 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4620936 constant */
    /* @4620940 constant */
    /* @4620944 load */
    /* @4620952 constant */
    /* @4620956 add */
    /* @4620960 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    GM_WRITE(vm, -1, "y", v31);
    /* @4620968 constant */
    /* @4620972 cast */
    /* @4620976 constant */
    /* @4620980 cast */
    /* @4620984 constant */
    /* @4620988 cast */
    /* @4620992 constant */
    /* @4621004 cast */
    /* @4621008 constant */
    /* @4621020 cast */
    /* @4621024 load */
    /* @4621032 load */
    /* @4621040 constant */
    /* @4621044 cast */
    /* @4621048 constant */
    /* @4621052 cast */
    /* @4621056 call */
    GM_SITE(vm, 438, 4621056);
    /* @4621064 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4621068 constant */
    /* @4621072 cast */
    /* @4621076 call */
    GM_SITE(vm, 438, 4621076);
    /* @4621084 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4621088 constant */
    /* @4621096 cast */
    /* @4621100 call */
    GM_SITE(vm, 438, 4621100);
    /* @4621108 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4621112 string */
    /* @4621120 cast */
    /* @4621124 load */
    /* @4621132 load */
    /* @4621140 constant */
    /* @4621144 add */
    /* @4621148 call */
    GM_SITE(vm, 438, 4621148);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4621156 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(816)));
    /* @4621160 string */
    /* @4621168 cast */
    /* @4621172 load */
    /* @4621180 constant */
    /* @4621184 add */
    /* @4621188 load */
    /* @4621196 constant */
    /* @4621200 add */
    /* @4621204 call */
    GM_SITE(vm, 438, 4621204);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4621212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(815)));
    /* @4621216 constant */
    /* @4621220 cast */
    /* @4621224 constant */
    /* @4621228 cast */
    /* @4621232 constant */
    /* @4621236 cast */
    /* @4621240 constant */
    /* @4621244 cast */
    /* @4621248 constant */
    /* @4621252 cast */
    /* @4621256 load */
    /* @4621264 constant */
    /* @4621268 add */
    /* @4621272 load */
    /* @4621280 constant */
    /* @4621284 add */
    /* @4621288 constant */
    /* @4621292 cast */
    /* @4621296 constant */
    /* @4621300 cast */
    /* @4621304 call */
    GM_SITE(vm, 438, 4621304);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4621312 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4621316 load */
    /* @4621324 constant */
    /* @4621328 cmp */
    /* @4621332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4621436;
    /* @4621336 constant */
    /* @4621340 cast */
    /* @4621344 constant */
    /* @4621348 cast */
    /* @4621352 constant */
    /* @4621356 cast */
    /* @4621360 constant */
    /* @4621372 cast */
    /* @4621376 constant */
    /* @4621388 cast */
    /* @4621392 load */
    /* @4621400 load */
    /* @4621408 constant */
    /* @4621412 cast */
    /* @4621416 constant */
    /* @4621420 cast */
    /* @4621424 call */
    GM_SITE(vm, 438, 4621424);
    /* @4621432 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4621436: ;
    /* @4621436 load */
    /* @4621444 constant */
    /* @4621448 cmp */
    /* @4621452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4621988;
    /* @4621456 constant */
    /* @4621460 constant */
    /* @4621464 load */
    /* @4621472 constant */
    /* @4621476 add */
    /* @4621480 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4621488 constant */
    /* @4621492 constant */
    /* @4621496 load */
    /* @4621504 constant */
    /* @4621508 add */
    /* @4621512 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    GM_WRITE(vm, -1, "y", v38);
    /* @4621520 constant */
    /* @4621524 cast */
    /* @4621528 constant */
    /* @4621532 cast */
    /* @4621536 constant */
    /* @4621540 cast */
    /* @4621544 constant */
    /* @4621556 cast */
    /* @4621560 constant */
    /* @4621572 cast */
    /* @4621576 load */
    /* @4621584 load */
    /* @4621592 constant */
    /* @4621596 cast */
    /* @4621600 constant */
    /* @4621604 cast */
    /* @4621608 call */
    GM_SITE(vm, 438, 4621608);
    /* @4621616 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4621620 constant */
    /* @4621624 cast */
    /* @4621628 call */
    GM_SITE(vm, 438, 4621628);
    /* @4621636 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4621640 constant */
    /* @4621648 cast */
    /* @4621652 call */
    GM_SITE(vm, 438, 4621652);
    /* @4621660 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4621664 string */
    /* @4621672 cast */
    /* @4621676 load */
    /* @4621684 load */
    /* @4621692 constant */
    /* @4621696 add */
    /* @4621700 call */
    GM_SITE(vm, 438, 4621700);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4621708 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(816)));
    /* @4621712 string */
    /* @4621720 cast */
    /* @4621724 load */
    /* @4621732 constant */
    /* @4621736 add */
    /* @4621740 load */
    /* @4621748 constant */
    /* @4621752 add */
    /* @4621756 call */
    GM_SITE(vm, 438, 4621756);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4621764 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(815)));
    /* @4621768 constant */
    /* @4621772 cast */
    /* @4621776 constant */
    /* @4621780 cast */
    /* @4621784 constant */
    /* @4621788 cast */
    /* @4621792 constant */
    /* @4621796 cast */
    /* @4621800 constant */
    /* @4621804 cast */
    /* @4621808 load */
    /* @4621816 constant */
    /* @4621820 add */
    /* @4621824 load */
    /* @4621832 constant */
    /* @4621836 add */
    /* @4621840 constant */
    /* @4621844 cast */
    /* @4621848 constant */
    /* @4621852 cast */
    /* @4621856 call */
    GM_SITE(vm, 438, 4621856);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4621864 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(87), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4621868 load */
    /* @4621876 constant */
    /* @4621880 cmp */
    /* @4621884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "coinmultiplier5bought") == VAL(1)))) goto L_4621988;
    /* @4621888 constant */
    /* @4621892 cast */
    /* @4621896 constant */
    /* @4621900 cast */
    /* @4621904 constant */
    /* @4621908 cast */
    /* @4621912 constant */
    /* @4621924 cast */
    /* @4621928 constant */
    /* @4621940 cast */
    /* @4621944 load */
    /* @4621952 load */
    /* @4621960 constant */
    /* @4621964 cast */
    /* @4621968 constant */
    /* @4621972 cast */
    /* @4621976 call */
    GM_SITE(vm, 438, 4621976);
    /* @4621984 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4621988: ;
    return;
}
