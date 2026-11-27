/* generated from CODE 121 (gml_Object_obj_hulkingbandit_Step_0), source start 3948200, end 3949928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0121(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3948380_0;
    Val v4;
    Val v5;
    Val p3948496_0;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val p3948960_0;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p3949272_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val p3949424_0;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val p3949624_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p3949776_0;
    Val v36;
    /* @3948200 load */
    /* @3948208 constant */
    /* @3948212 cmp */
    /* @3948216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hphulkingbandit") >= VAL(0)))) goto L_3948240;
    /* @3948220 constant */
    /* @3948224 constant */
    /* @3948228 constant */
    /* @3948232 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3948240: ;
    /* @3948240 load */
    /* @3948248 constant */
    /* @3948252 cmp */
    /* @3948256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hphulkingbandit") <= VAL(0)))) goto L_3948280;
    /* @3948260 constant */
    /* @3948264 constant */
    /* @3948268 constant */
    /* @3948272 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3948280: ;
    /* @3948280 constant */
    /* @3948284 cast */
    /* @3948288 load */
    /* @3948296 load */
    /* @3948304 constant */
    /* @3948308 add */
    /* @3948312 call */
    GM_SITE(vm, 121, 3948312);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3948320 cast */
    /* @3948324 bt */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, v1, GM_READ(vm, -1, "y"), VAL(4)));
    if (TRUTH(v2)) goto L_3948376;
    /* @3948328 constant */
    /* @3948332 cast */
    /* @3948336 load */
    /* @3948344 load */
    /* @3948352 constant */
    /* @3948356 add */
    /* @3948360 call */
    GM_SITE(vm, 121, 3948360);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3948368 cast */
    /* @3948372 b */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(6)));
    p3948380_0 = v4;
    goto L_3948380;
    L_3948376: ;
    /* @3948376 constant */
    p3948380_0 = VAL(1);
    L_3948380: ;
    /* @3948380 bf */
    if (!TRUTH(p3948380_0)) goto L_3948396;
    /* @3948384 constant */
    /* @3948388 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3948396: ;
    /* @3948396 constant */
    /* @3948400 cast */
    /* @3948404 load */
    /* @3948412 load */
    /* @3948420 constant */
    /* @3948424 sub */
    /* @3948428 call */
    GM_SITE(vm, 121, 3948428);
    /* @3948436 cast */
    /* @3948440 bt */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(4)));
    if (TRUTH(v5)) goto L_3948492;
    /* @3948444 constant */
    /* @3948448 cast */
    /* @3948452 load */
    /* @3948460 load */
    /* @3948468 constant */
    /* @3948472 sub */
    /* @3948476 call */
    GM_SITE(vm, 121, 3948476);
    /* @3948484 cast */
    /* @3948488 b */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(6)));
    p3948496_0 = v6;
    goto L_3948496;
    L_3948492: ;
    /* @3948492 constant */
    p3948496_0 = VAL(1);
    L_3948496: ;
    /* @3948496 bf */
    if (!TRUTH(p3948496_0)) goto L_3948512;
    /* @3948500 constant */
    /* @3948504 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3948512: ;
    /* @3948512 constant */
    /* @3948516 cast */
    /* @3948520 load */
    /* @3948528 constant */
    /* @3948532 add */
    /* @3948536 load */
    /* @3948544 call */
    GM_SITE(vm, 121, 3948544);
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3948552 cast */
    /* @3948556 bf */
    v8 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v7, VAL(34)));
    if (!TRUTH(v8)) goto L_3948600;
    /* @3948560 constant */
    /* @3948564 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3948572 constant */
    /* @3948576 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3948584 constant */
    /* @3948588 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3948596 b */
    goto L_3948632;
    L_3948600: ;
    /* @3948600 constant */
    /* @3948612 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3948620 constant */
    /* @3948624 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3948632: ;
    /* @3948632 load */
    /* @3948640 constant */
    /* @3948644 cmp */
    /* @3948648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3948696;
    /* @3948652 load */
    /* @3948660 constant */
    /* @3948664 cmp */
    /* @3948668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "shooting") == VAL(0)))) goto L_3948696;
    /* @3948672 constant */
    /* @3948676 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @3948684 constant */
    /* @3948688 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_3948696: ;
    /* @3948696 load */
    /* @3948704 constant */
    /* @3948708 cmp */
    /* @3948712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3948760;
    /* @3948716 load */
    /* @3948724 constant */
    /* @3948728 cmp */
    /* @3948732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "shooting") == VAL(0)))) goto L_3948760;
    /* @3948736 constant */
    /* @3948740 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3948748 constant */
    /* @3948752 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_3948760: ;
    /* @3948760 load */
    /* @3948768 constant */
    /* @3948772 cmp */
    /* @3948776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3948824;
    /* @3948780 load */
    /* @3948788 constant */
    /* @3948792 cmp */
    /* @3948796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "shooting") == VAL(1)))) goto L_3948824;
    /* @3948800 constant */
    /* @3948804 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @3948812 constant */
    /* @3948816 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_3948824: ;
    /* @3948824 load */
    /* @3948832 constant */
    /* @3948836 cmp */
    /* @3948840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3948888;
    /* @3948844 load */
    /* @3948852 constant */
    /* @3948856 cmp */
    /* @3948860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "shooting") == VAL(1)))) goto L_3948888;
    /* @3948864 constant */
    /* @3948868 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3948876 constant */
    /* @3948880 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_3948888: ;
    /* @3948888 constant */
    /* @3948892 cast */
    /* @3948896 call */
    GM_SITE(vm, 121, 3948896);
    /* @3948904 constant */
    /* @3948908 cmp */
    /* @3948912 bf */
    v9 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v9)) goto L_3948976;
    /* @3948916 load */
    /* @3948924 constant */
    /* @3948928 cmp */
    /* @3948932 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3948956;
    /* @3948936 load */
    /* @3948944 constant */
    /* @3948948 cmp */
    /* @3948952 b */
    p3948960_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3948960;
    L_3948956: ;
    /* @3948956 constant */
    p3948960_0 = VAL(1);
    L_3948960: ;
    /* @3948960 bf */
    if (!TRUTH(p3948960_0)) goto L_3948976;
    /* @3948964 constant */
    /* @3948968 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3948976: ;
    /* @3948976 load */
    /* @3948984 constant */
    /* @3948988 cmp */
    /* @3948992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hphulkingbanditfrozen") == VAL(1)))) goto L_3949040;
    /* @3948996 constant */
    /* @3949004 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3949012 constant */
    /* @3949016 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3949024 constant */
    /* @3949028 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3949036 b */
    goto L_3949056;
    L_3949040: ;
    /* @3949040 constant */
    /* @3949048 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3949056: ;
    /* @3949056 load */
    /* @3949064 constant */
    /* @3949068 cmp */
    /* @3949072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3949088;
    /* @3949076 constant */
    /* @3949080 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(116));
    L_3949088: ;
    /* @3949088 constant */
    /* @3949092 cast */
    /* @3949096 load */
    /* @3949104 constant */
    /* @3949108 add */
    /* @3949112 load */
    /* @3949120 constant */
    /* @3949124 add */
    /* @3949128 call */
    GM_SITE(vm, 121, 3949128);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949136 cast */
    /* @3949140 not */
    /* @3949144 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v10, v11, VAL(4))));
    if (!TRUTH(v12)) goto L_3949268;
    /* @3949148 constant */
    /* @3949152 cast */
    /* @3949156 load */
    /* @3949164 constant */
    /* @3949168 add */
    /* @3949172 load */
    /* @3949180 constant */
    /* @3949184 add */
    /* @3949188 call */
    GM_SITE(vm, 121, 3949188);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949196 cast */
    /* @3949200 not */
    /* @3949204 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, v14, VAL(6))));
    if (!TRUTH(v15)) goto L_3949268;
    /* @3949208 constant */
    /* @3949212 cast */
    /* @3949216 load */
    /* @3949224 constant */
    /* @3949228 add */
    /* @3949232 load */
    /* @3949240 constant */
    /* @3949244 add */
    /* @3949248 call */
    GM_SITE(vm, 121, 3949248);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949256 cast */
    /* @3949260 not */
    /* @3949264 b */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v16, v17, VAL(7))));
    p3949272_0 = v18;
    goto L_3949272;
    L_3949268: ;
    /* @3949268 constant */
    p3949272_0 = VAL(0);
    L_3949272: ;
    /* @3949272 bf */
    if (!TRUTH(p3949272_0)) goto L_3949440;
    /* @3949276 constant */
    /* @3949280 cast */
    /* @3949284 load */
    /* @3949292 constant */
    /* @3949296 add */
    /* @3949300 load */
    /* @3949308 call */
    GM_SITE(vm, 121, 3949308);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949316 cast */
    /* @3949320 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(4)));
    if (TRUTH(v20)) goto L_3949420;
    /* @3949324 constant */
    /* @3949328 cast */
    /* @3949332 load */
    /* @3949340 constant */
    /* @3949344 add */
    /* @3949348 load */
    /* @3949356 call */
    GM_SITE(vm, 121, 3949356);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949364 cast */
    /* @3949368 bt */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(6)));
    if (TRUTH(v22)) goto L_3949420;
    /* @3949372 constant */
    /* @3949376 cast */
    /* @3949380 load */
    /* @3949388 constant */
    /* @3949392 add */
    /* @3949396 load */
    /* @3949404 call */
    GM_SITE(vm, 121, 3949404);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949412 cast */
    /* @3949416 b */
    v24 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v23, VAL(7)));
    p3949424_0 = v24;
    goto L_3949424;
    L_3949420: ;
    /* @3949420 constant */
    p3949424_0 = VAL(1);
    L_3949424: ;
    /* @3949424 bf */
    if (!TRUTH(p3949424_0)) goto L_3949440;
    /* @3949428 constant */
    /* @3949432 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3949440: ;
    /* @3949440 constant */
    /* @3949444 cast */
    /* @3949448 load */
    /* @3949456 constant */
    /* @3949460 add */
    /* @3949464 load */
    /* @3949472 constant */
    /* @3949476 sub */
    /* @3949480 call */
    GM_SITE(vm, 121, 3949480);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949488 cast */
    /* @3949492 not */
    /* @3949496 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v25, VAL(4))));
    if (!TRUTH(v26)) goto L_3949620;
    /* @3949500 constant */
    /* @3949504 cast */
    /* @3949508 load */
    /* @3949516 constant */
    /* @3949520 add */
    /* @3949524 load */
    /* @3949532 constant */
    /* @3949536 sub */
    /* @3949540 call */
    GM_SITE(vm, 121, 3949540);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949548 cast */
    /* @3949552 not */
    /* @3949556 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v27, VAL(6))));
    if (!TRUTH(v28)) goto L_3949620;
    /* @3949560 constant */
    /* @3949564 cast */
    /* @3949568 load */
    /* @3949576 constant */
    /* @3949580 add */
    /* @3949584 load */
    /* @3949592 constant */
    /* @3949596 sub */
    /* @3949600 call */
    GM_SITE(vm, 121, 3949600);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949608 cast */
    /* @3949612 not */
    /* @3949616 b */
    v30 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(50)), v29, VAL(7))));
    p3949624_0 = v30;
    goto L_3949624;
    L_3949620: ;
    /* @3949620 constant */
    p3949624_0 = VAL(0);
    L_3949624: ;
    /* @3949624 bf */
    if (!TRUTH(p3949624_0)) goto L_3949792;
    /* @3949628 constant */
    /* @3949632 cast */
    /* @3949636 load */
    /* @3949644 constant */
    /* @3949648 add */
    /* @3949652 load */
    /* @3949660 call */
    GM_SITE(vm, 121, 3949660);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949668 cast */
    /* @3949672 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(4)));
    if (TRUTH(v32)) goto L_3949772;
    /* @3949676 constant */
    /* @3949680 cast */
    /* @3949684 load */
    /* @3949692 constant */
    /* @3949696 add */
    /* @3949700 load */
    /* @3949708 call */
    GM_SITE(vm, 121, 3949708);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949716 cast */
    /* @3949720 bt */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(6)));
    if (TRUTH(v34)) goto L_3949772;
    /* @3949724 constant */
    /* @3949728 cast */
    /* @3949732 load */
    /* @3949740 constant */
    /* @3949744 add */
    /* @3949748 load */
    /* @3949756 call */
    GM_SITE(vm, 121, 3949756);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3949764 cast */
    /* @3949768 b */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(7)));
    p3949776_0 = v36;
    goto L_3949776;
    L_3949772: ;
    /* @3949772 constant */
    p3949776_0 = VAL(1);
    L_3949776: ;
    /* @3949776 bf */
    if (!TRUTH(p3949776_0)) goto L_3949792;
    /* @3949780 constant */
    /* @3949784 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3949792: ;
    /* @3949792 load */
    /* @3949800 constant */
    /* @3949804 cmp */
    /* @3949808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3949848;
    /* @3949812 constant */
    /* @3949816 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(116));
    /* @3949824 constant */
    /* @3949828 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3949836 constant */
    /* @3949840 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3949848: ;
    /* @3949848 load */
    /* @3949856 constant */
    /* @3949860 cmp */
    /* @3949864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3949884;
    /* @3949868 constant */
    /* @3949876 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3949884: ;
    /* @3949884 load */
    /* @3949892 constant */
    /* @3949896 cmp */
    /* @3949900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3949928;
    /* @3949904 constant */
    /* @3949908 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3949916 constant */
    /* @3949920 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3949928: ;
    return;
}
