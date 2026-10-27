/* generated from CODE 442 (gml_Object_obj_maxhpupgrade_Draw_0), source start 4625656, end 4628928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0442(GmVM* vm) {
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
    /* @4625656 load */
    /* @4625664 constant */
    /* @4625668 cmp */
    /* @4625672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4626144;
    /* @4625676 constant */
    /* @4625680 cast */
    /* @4625684 constant */
    /* @4625688 cast */
    /* @4625692 constant */
    /* @4625696 cast */
    /* @4625700 constant */
    /* @4625712 cast */
    /* @4625716 constant */
    /* @4625728 cast */
    /* @4625732 load */
    /* @4625740 load */
    /* @4625748 constant */
    /* @4625752 cast */
    /* @4625756 constant */
    /* @4625760 cast */
    /* @4625764 call */
    GM_SITE(vm, 442, 4625764);
    /* @4625772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4625776 constant */
    /* @4625780 cast */
    /* @4625784 call */
    GM_SITE(vm, 442, 4625784);
    /* @4625792 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4625796 constant */
    /* @4625804 cast */
    /* @4625808 call */
    GM_SITE(vm, 442, 4625808);
    /* @4625816 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4625820 string */
    /* @4625828 cast */
    /* @4625832 load */
    /* @4625840 load */
    /* @4625848 constant */
    /* @4625852 add */
    /* @4625856 call */
    GM_SITE(vm, 442, 4625856);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4625864 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(819)));
    /* @4625868 string */
    /* @4625876 cast */
    /* @4625880 load */
    /* @4625888 constant */
    /* @4625892 add */
    /* @4625896 load */
    /* @4625904 constant */
    /* @4625908 add */
    /* @4625912 call */
    GM_SITE(vm, 442, 4625912);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4625920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(806)));
    /* @4625924 constant */
    /* @4625928 cast */
    /* @4625932 constant */
    /* @4625936 cast */
    /* @4625940 constant */
    /* @4625944 cast */
    /* @4625948 constant */
    /* @4625952 cast */
    /* @4625956 constant */
    /* @4625960 cast */
    /* @4625964 load */
    /* @4625972 constant */
    /* @4625976 add */
    /* @4625980 load */
    /* @4625988 constant */
    /* @4625992 add */
    /* @4625996 constant */
    /* @4626000 cast */
    /* @4626004 constant */
    /* @4626008 cast */
    /* @4626012 call */
    GM_SITE(vm, 442, 4626012);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4626020 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4626024 load */
    /* @4626032 constant */
    /* @4626036 cmp */
    /* @4626040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4626144;
    /* @4626044 constant */
    /* @4626048 cast */
    /* @4626052 constant */
    /* @4626056 cast */
    /* @4626060 constant */
    /* @4626064 cast */
    /* @4626068 constant */
    /* @4626080 cast */
    /* @4626084 constant */
    /* @4626096 cast */
    /* @4626100 load */
    /* @4626108 load */
    /* @4626116 constant */
    /* @4626120 cast */
    /* @4626124 constant */
    /* @4626128 cast */
    /* @4626132 call */
    GM_SITE(vm, 442, 4626132);
    /* @4626140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4626144: ;
    /* @4626144 load */
    /* @4626152 constant */
    /* @4626156 cmp */
    /* @4626160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4626704;
    /* @4626164 constant */
    /* @4626168 constant */
    /* @4626172 load */
    /* @4626180 constant */
    /* @4626184 add */
    /* @4626188 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v6);
    /* @4626196 constant */
    /* @4626200 constant */
    /* @4626204 load */
    /* @4626212 constant */
    /* @4626216 add */
    /* @4626220 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    GM_WRITE(vm, -1, "y", v7);
    /* @4626228 constant */
    /* @4626232 cast */
    /* @4626236 constant */
    /* @4626240 cast */
    /* @4626244 constant */
    /* @4626248 cast */
    /* @4626252 constant */
    /* @4626256 cast */
    /* @4626260 constant */
    /* @4626264 cast */
    /* @4626268 load */
    /* @4626276 load */
    /* @4626284 constant */
    /* @4626288 cast */
    /* @4626292 constant */
    /* @4626296 cast */
    /* @4626300 call */
    GM_SITE(vm, 442, 4626300);
    /* @4626308 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4626312 constant */
    /* @4626316 cast */
    /* @4626320 call */
    GM_SITE(vm, 442, 4626320);
    /* @4626328 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4626332 constant */
    /* @4626340 cast */
    /* @4626344 call */
    GM_SITE(vm, 442, 4626344);
    /* @4626352 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4626356 string */
    /* @4626364 cast */
    /* @4626368 load */
    /* @4626376 constant */
    /* @4626380 add */
    /* @4626384 load */
    /* @4626392 constant */
    /* @4626396 add */
    /* @4626400 call */
    GM_SITE(vm, 442, 4626400);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4626408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(819)));
    /* @4626412 string */
    /* @4626420 cast */
    /* @4626424 load */
    /* @4626432 constant */
    /* @4626436 add */
    /* @4626440 load */
    /* @4626448 constant */
    /* @4626452 add */
    /* @4626456 call */
    GM_SITE(vm, 442, 4626456);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4626464 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(806)));
    /* @4626468 constant */
    /* @4626472 cast */
    /* @4626476 constant */
    /* @4626480 cast */
    /* @4626484 constant */
    /* @4626488 cast */
    /* @4626492 constant */
    /* @4626504 cast */
    /* @4626508 constant */
    /* @4626520 cast */
    /* @4626524 load */
    /* @4626532 constant */
    /* @4626536 add */
    /* @4626540 load */
    /* @4626548 constant */
    /* @4626552 add */
    /* @4626556 constant */
    /* @4626560 cast */
    /* @4626564 constant */
    /* @4626568 cast */
    /* @4626572 call */
    GM_SITE(vm, 442, 4626572);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4626580 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4626584 load */
    /* @4626592 constant */
    /* @4626596 cmp */
    /* @4626600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4626704;
    /* @4626604 constant */
    /* @4626608 cast */
    /* @4626612 constant */
    /* @4626616 cast */
    /* @4626620 constant */
    /* @4626624 cast */
    /* @4626628 constant */
    /* @4626640 cast */
    /* @4626644 constant */
    /* @4626656 cast */
    /* @4626660 load */
    /* @4626668 load */
    /* @4626676 constant */
    /* @4626680 cast */
    /* @4626684 constant */
    /* @4626688 cast */
    /* @4626692 call */
    GM_SITE(vm, 442, 4626692);
    /* @4626700 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4626704: ;
    /* @4626704 load */
    /* @4626712 constant */
    /* @4626716 cmp */
    /* @4626720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4627264;
    /* @4626724 constant */
    /* @4626728 constant */
    /* @4626732 load */
    /* @4626740 constant */
    /* @4626744 add */
    /* @4626748 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v14);
    /* @4626756 constant */
    /* @4626760 constant */
    /* @4626764 load */
    /* @4626772 constant */
    /* @4626776 add */
    /* @4626780 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    GM_WRITE(vm, -1, "y", v15);
    /* @4626788 constant */
    /* @4626792 cast */
    /* @4626796 constant */
    /* @4626800 cast */
    /* @4626804 constant */
    /* @4626808 cast */
    /* @4626812 constant */
    /* @4626824 cast */
    /* @4626828 constant */
    /* @4626840 cast */
    /* @4626844 load */
    /* @4626852 load */
    /* @4626860 constant */
    /* @4626864 cast */
    /* @4626868 constant */
    /* @4626872 cast */
    /* @4626876 call */
    GM_SITE(vm, 442, 4626876);
    /* @4626884 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4626888 constant */
    /* @4626892 cast */
    /* @4626896 call */
    GM_SITE(vm, 442, 4626896);
    /* @4626904 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4626908 constant */
    /* @4626916 cast */
    /* @4626920 call */
    GM_SITE(vm, 442, 4626920);
    /* @4626928 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4626932 string */
    /* @4626940 cast */
    /* @4626944 load */
    /* @4626952 constant */
    /* @4626956 add */
    /* @4626960 load */
    /* @4626968 constant */
    /* @4626972 add */
    /* @4626976 call */
    GM_SITE(vm, 442, 4626976);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4626984 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(819)));
    /* @4626988 string */
    /* @4626996 cast */
    /* @4627000 load */
    /* @4627008 constant */
    /* @4627012 add */
    /* @4627016 load */
    /* @4627024 constant */
    /* @4627028 add */
    /* @4627032 call */
    GM_SITE(vm, 442, 4627032);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4627040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(806)));
    /* @4627044 constant */
    /* @4627048 cast */
    /* @4627052 constant */
    /* @4627056 cast */
    /* @4627060 constant */
    /* @4627064 cast */
    /* @4627068 constant */
    /* @4627072 cast */
    /* @4627076 constant */
    /* @4627080 cast */
    /* @4627084 load */
    /* @4627092 constant */
    /* @4627096 add */
    /* @4627100 load */
    /* @4627108 constant */
    /* @4627112 add */
    /* @4627116 constant */
    /* @4627120 cast */
    /* @4627124 constant */
    /* @4627128 cast */
    /* @4627132 call */
    GM_SITE(vm, 442, 4627132);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4627140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v20, v21, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4627144 load */
    /* @4627152 constant */
    /* @4627156 cmp */
    /* @4627160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4627264;
    /* @4627164 constant */
    /* @4627168 cast */
    /* @4627172 constant */
    /* @4627176 cast */
    /* @4627180 constant */
    /* @4627184 cast */
    /* @4627188 constant */
    /* @4627200 cast */
    /* @4627204 constant */
    /* @4627216 cast */
    /* @4627220 load */
    /* @4627228 load */
    /* @4627236 constant */
    /* @4627240 cast */
    /* @4627244 constant */
    /* @4627248 cast */
    /* @4627252 call */
    GM_SITE(vm, 442, 4627252);
    /* @4627260 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4627264: ;
    /* @4627264 load */
    /* @4627272 constant */
    /* @4627276 cmp */
    /* @4627280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4627824;
    /* @4627284 constant */
    /* @4627288 constant */
    /* @4627292 load */
    /* @4627300 constant */
    /* @4627304 add */
    /* @4627308 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v22);
    /* @4627316 constant */
    /* @4627320 constant */
    /* @4627324 load */
    /* @4627332 constant */
    /* @4627336 add */
    /* @4627340 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    GM_WRITE(vm, -1, "y", v23);
    /* @4627348 constant */
    /* @4627352 cast */
    /* @4627356 constant */
    /* @4627360 cast */
    /* @4627364 constant */
    /* @4627368 cast */
    /* @4627372 constant */
    /* @4627384 cast */
    /* @4627388 constant */
    /* @4627400 cast */
    /* @4627404 load */
    /* @4627412 load */
    /* @4627420 constant */
    /* @4627424 cast */
    /* @4627428 constant */
    /* @4627432 cast */
    /* @4627436 call */
    GM_SITE(vm, 442, 4627436);
    /* @4627444 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4627448 constant */
    /* @4627452 cast */
    /* @4627456 call */
    GM_SITE(vm, 442, 4627456);
    /* @4627464 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4627468 constant */
    /* @4627476 cast */
    /* @4627480 call */
    GM_SITE(vm, 442, 4627480);
    /* @4627488 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4627492 string */
    /* @4627500 cast */
    /* @4627504 load */
    /* @4627512 constant */
    /* @4627516 add */
    /* @4627520 load */
    /* @4627528 constant */
    /* @4627532 add */
    /* @4627536 call */
    GM_SITE(vm, 442, 4627536);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4627544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(819)));
    /* @4627548 string */
    /* @4627556 cast */
    /* @4627560 load */
    /* @4627568 constant */
    /* @4627572 add */
    /* @4627576 load */
    /* @4627584 constant */
    /* @4627588 add */
    /* @4627592 call */
    GM_SITE(vm, 442, 4627592);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4627600 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(806)));
    /* @4627604 constant */
    /* @4627608 cast */
    /* @4627612 constant */
    /* @4627616 cast */
    /* @4627620 constant */
    /* @4627624 cast */
    /* @4627628 constant */
    /* @4627632 cast */
    /* @4627636 constant */
    /* @4627640 cast */
    /* @4627644 load */
    /* @4627652 constant */
    /* @4627656 add */
    /* @4627660 load */
    /* @4627668 constant */
    /* @4627672 add */
    /* @4627676 constant */
    /* @4627680 cast */
    /* @4627684 constant */
    /* @4627688 cast */
    /* @4627692 call */
    GM_SITE(vm, 442, 4627692);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4627700 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v28, v29, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4627704 load */
    /* @4627712 constant */
    /* @4627716 cmp */
    /* @4627720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4627824;
    /* @4627724 constant */
    /* @4627728 cast */
    /* @4627732 constant */
    /* @4627736 cast */
    /* @4627740 constant */
    /* @4627744 cast */
    /* @4627748 constant */
    /* @4627760 cast */
    /* @4627764 constant */
    /* @4627776 cast */
    /* @4627780 load */
    /* @4627788 load */
    /* @4627796 constant */
    /* @4627800 cast */
    /* @4627804 constant */
    /* @4627808 cast */
    /* @4627812 call */
    GM_SITE(vm, 442, 4627812);
    /* @4627820 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4627824: ;
    /* @4627824 load */
    /* @4627832 constant */
    /* @4627836 cmp */
    /* @4627840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4628376;
    /* @4627844 constant */
    /* @4627848 constant */
    /* @4627852 load */
    /* @4627860 constant */
    /* @4627864 add */
    /* @4627868 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v30);
    /* @4627876 constant */
    /* @4627880 constant */
    /* @4627884 load */
    /* @4627892 constant */
    /* @4627896 add */
    /* @4627900 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    GM_WRITE(vm, -1, "y", v31);
    /* @4627908 constant */
    /* @4627912 cast */
    /* @4627916 constant */
    /* @4627920 cast */
    /* @4627924 constant */
    /* @4627928 cast */
    /* @4627932 constant */
    /* @4627944 cast */
    /* @4627948 constant */
    /* @4627960 cast */
    /* @4627964 load */
    /* @4627972 load */
    /* @4627980 constant */
    /* @4627984 cast */
    /* @4627988 constant */
    /* @4627992 cast */
    /* @4627996 call */
    GM_SITE(vm, 442, 4627996);
    /* @4628004 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4628008 constant */
    /* @4628012 cast */
    /* @4628016 call */
    GM_SITE(vm, 442, 4628016);
    /* @4628024 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4628028 constant */
    /* @4628036 cast */
    /* @4628040 call */
    GM_SITE(vm, 442, 4628040);
    /* @4628048 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4628052 string */
    /* @4628060 cast */
    /* @4628064 load */
    /* @4628072 load */
    /* @4628080 constant */
    /* @4628084 add */
    /* @4628088 call */
    GM_SITE(vm, 442, 4628088);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4628096 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(819)));
    /* @4628100 string */
    /* @4628108 cast */
    /* @4628112 load */
    /* @4628120 constant */
    /* @4628124 add */
    /* @4628128 load */
    /* @4628136 constant */
    /* @4628140 add */
    /* @4628144 call */
    GM_SITE(vm, 442, 4628144);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4628152 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(806)));
    /* @4628156 constant */
    /* @4628160 cast */
    /* @4628164 constant */
    /* @4628168 cast */
    /* @4628172 constant */
    /* @4628176 cast */
    /* @4628180 constant */
    /* @4628184 cast */
    /* @4628188 constant */
    /* @4628192 cast */
    /* @4628196 load */
    /* @4628204 constant */
    /* @4628208 add */
    /* @4628212 load */
    /* @4628220 constant */
    /* @4628224 add */
    /* @4628228 constant */
    /* @4628232 cast */
    /* @4628236 constant */
    /* @4628240 cast */
    /* @4628244 call */
    GM_SITE(vm, 442, 4628244);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4628252 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v35, v36, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4628256 load */
    /* @4628264 constant */
    /* @4628268 cmp */
    /* @4628272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4628376;
    /* @4628276 constant */
    /* @4628280 cast */
    /* @4628284 constant */
    /* @4628288 cast */
    /* @4628292 constant */
    /* @4628296 cast */
    /* @4628300 constant */
    /* @4628312 cast */
    /* @4628316 constant */
    /* @4628328 cast */
    /* @4628332 load */
    /* @4628340 load */
    /* @4628348 constant */
    /* @4628352 cast */
    /* @4628356 constant */
    /* @4628360 cast */
    /* @4628364 call */
    GM_SITE(vm, 442, 4628364);
    /* @4628372 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4628376: ;
    /* @4628376 load */
    /* @4628384 constant */
    /* @4628388 cmp */
    /* @4628392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4628928;
    /* @4628396 constant */
    /* @4628400 constant */
    /* @4628404 load */
    /* @4628412 constant */
    /* @4628416 add */
    /* @4628420 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v37);
    /* @4628428 constant */
    /* @4628432 constant */
    /* @4628436 load */
    /* @4628444 constant */
    /* @4628448 add */
    /* @4628452 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    GM_WRITE(vm, -1, "y", v38);
    /* @4628460 constant */
    /* @4628464 cast */
    /* @4628468 constant */
    /* @4628472 cast */
    /* @4628476 constant */
    /* @4628480 cast */
    /* @4628484 constant */
    /* @4628496 cast */
    /* @4628500 constant */
    /* @4628512 cast */
    /* @4628516 load */
    /* @4628524 load */
    /* @4628532 constant */
    /* @4628536 cast */
    /* @4628540 constant */
    /* @4628544 cast */
    /* @4628548 call */
    GM_SITE(vm, 442, 4628548);
    /* @4628556 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4628560 constant */
    /* @4628564 cast */
    /* @4628568 call */
    GM_SITE(vm, 442, 4628568);
    /* @4628576 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4628580 constant */
    /* @4628588 cast */
    /* @4628592 call */
    GM_SITE(vm, 442, 4628592);
    /* @4628600 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4628604 string */
    /* @4628612 cast */
    /* @4628616 load */
    /* @4628624 load */
    /* @4628632 constant */
    /* @4628636 add */
    /* @4628640 call */
    GM_SITE(vm, 442, 4628640);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4628648 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(819)));
    /* @4628652 string */
    /* @4628660 cast */
    /* @4628664 load */
    /* @4628672 constant */
    /* @4628676 add */
    /* @4628680 load */
    /* @4628688 constant */
    /* @4628692 add */
    /* @4628696 call */
    GM_SITE(vm, 442, 4628696);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4628704 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(806)));
    /* @4628708 constant */
    /* @4628712 cast */
    /* @4628716 constant */
    /* @4628720 cast */
    /* @4628724 constant */
    /* @4628728 cast */
    /* @4628732 constant */
    /* @4628736 cast */
    /* @4628740 constant */
    /* @4628744 cast */
    /* @4628748 load */
    /* @4628756 constant */
    /* @4628760 add */
    /* @4628764 load */
    /* @4628772 constant */
    /* @4628776 add */
    /* @4628780 constant */
    /* @4628784 cast */
    /* @4628788 constant */
    /* @4628792 cast */
    /* @4628796 call */
    GM_SITE(vm, 442, 4628796);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4628804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4628808 load */
    /* @4628816 constant */
    /* @4628820 cmp */
    /* @4628824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(1)))) goto L_4628928;
    /* @4628828 constant */
    /* @4628832 cast */
    /* @4628836 constant */
    /* @4628840 cast */
    /* @4628844 constant */
    /* @4628848 cast */
    /* @4628852 constant */
    /* @4628864 cast */
    /* @4628868 constant */
    /* @4628880 cast */
    /* @4628884 load */
    /* @4628892 load */
    /* @4628900 constant */
    /* @4628904 cast */
    /* @4628908 constant */
    /* @4628912 cast */
    /* @4628916 call */
    GM_SITE(vm, 442, 4628916);
    /* @4628924 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4628928: ;
    return;
}
