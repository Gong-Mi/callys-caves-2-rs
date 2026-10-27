/* generated from CODE 448 (gml_Object_obj_healthrefill_Draw_0), source start 4632732, end 4635740. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0448(GmVM* vm) {
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
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    Val v55;
    /* @4632732 load */
    /* @4632740 constant */
    /* @4632744 cmp */
    /* @4632748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4633176;
    /* @4632752 constant */
    /* @4632756 cast */
    /* @4632760 constant */
    /* @4632764 cast */
    /* @4632768 constant */
    /* @4632772 cast */
    /* @4632776 constant */
    /* @4632788 cast */
    /* @4632792 constant */
    /* @4632804 cast */
    /* @4632808 load */
    /* @4632816 load */
    /* @4632824 constant */
    /* @4632828 cast */
    /* @4632832 constant */
    /* @4632836 cast */
    /* @4632840 call */
    GM_SITE(vm, 448, 4632840);
    /* @4632848 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4632852 constant */
    /* @4632856 cast */
    /* @4632860 call */
    GM_SITE(vm, 448, 4632860);
    /* @4632868 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4632872 constant */
    /* @4632880 cast */
    /* @4632884 call */
    GM_SITE(vm, 448, 4632884);
    /* @4632892 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4632896 string */
    /* @4632904 cast */
    /* @4632908 load */
    /* @4632916 load */
    /* @4632924 constant */
    /* @4632928 add */
    /* @4632932 call */
    GM_SITE(vm, 448, 4632932);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4632940 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(822)));
    /* @4632944 string */
    /* @4632952 cast */
    /* @4632956 load */
    /* @4632964 constant */
    /* @4632968 add */
    /* @4632972 load */
    /* @4632980 constant */
    /* @4632984 add */
    /* @4632988 call */
    GM_SITE(vm, 448, 4632988);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4632996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(823)));
    /* @4633000 constant */
    /* @4633004 cast */
    /* @4633008 constant */
    /* @4633012 cast */
    /* @4633016 constant */
    /* @4633020 cast */
    /* @4633024 constant */
    /* @4633028 cast */
    /* @4633032 constant */
    /* @4633036 cast */
    /* @4633040 load */
    /* @4633048 constant */
    /* @4633052 add */
    /* @4633056 load */
    /* @4633064 constant */
    /* @4633068 add */
    /* @4633072 constant */
    /* @4633076 cast */
    /* @4633080 constant */
    /* @4633084 cast */
    /* @4633088 call */
    GM_SITE(vm, 448, 4633088);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4633096 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v4, v5, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4633100 load */
    /* @4633108 constant */
    /* @4633112 cmp */
    /* @4633116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4633176;
    /* @4633120 string */
    /* @4633128 cast */
    /* @4633132 load */
    /* @4633140 constant */
    /* @4633144 add */
    /* @4633148 load */
    /* @4633156 constant */
    /* @4633160 add */
    /* @4633164 call */
    GM_SITE(vm, 448, 4633164);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4633172 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v6, v7, STR_REF(824)));
    L_4633176: ;
    /* @4633176 load */
    /* @4633184 constant */
    /* @4633188 cmp */
    /* @4633192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4633692;
    /* @4633196 constant */
    /* @4633200 constant */
    /* @4633204 load */
    /* @4633212 constant */
    /* @4633216 add */
    /* @4633220 store */
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(45));
    GM_WRITE(vm, -1, "x", v8);
    /* @4633228 constant */
    /* @4633232 constant */
    /* @4633236 load */
    /* @4633244 constant */
    /* @4633248 add */
    /* @4633252 store */
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    GM_WRITE(vm, -1, "y", v9);
    /* @4633260 constant */
    /* @4633264 cast */
    /* @4633268 constant */
    /* @4633272 cast */
    /* @4633276 constant */
    /* @4633280 cast */
    /* @4633284 constant */
    /* @4633288 cast */
    /* @4633292 constant */
    /* @4633296 cast */
    /* @4633300 load */
    /* @4633308 load */
    /* @4633316 constant */
    /* @4633320 cast */
    /* @4633324 constant */
    /* @4633328 cast */
    /* @4633332 call */
    GM_SITE(vm, 448, 4633332);
    /* @4633340 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4633344 constant */
    /* @4633348 cast */
    /* @4633352 call */
    GM_SITE(vm, 448, 4633352);
    /* @4633360 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4633364 constant */
    /* @4633372 cast */
    /* @4633376 call */
    GM_SITE(vm, 448, 4633376);
    /* @4633384 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4633388 string */
    /* @4633396 cast */
    /* @4633400 load */
    /* @4633408 constant */
    /* @4633412 add */
    /* @4633416 load */
    /* @4633424 constant */
    /* @4633428 add */
    /* @4633432 call */
    GM_SITE(vm, 448, 4633432);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4633440 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(822)));
    /* @4633444 string */
    /* @4633452 cast */
    /* @4633456 load */
    /* @4633464 constant */
    /* @4633468 add */
    /* @4633472 load */
    /* @4633480 constant */
    /* @4633484 add */
    /* @4633488 call */
    GM_SITE(vm, 448, 4633488);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4633496 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v12, v13, STR_REF(823)));
    /* @4633500 constant */
    /* @4633504 cast */
    /* @4633508 constant */
    /* @4633512 cast */
    /* @4633516 constant */
    /* @4633520 cast */
    /* @4633524 constant */
    /* @4633536 cast */
    /* @4633540 constant */
    /* @4633552 cast */
    /* @4633556 load */
    /* @4633564 constant */
    /* @4633568 add */
    /* @4633572 load */
    /* @4633580 constant */
    /* @4633584 add */
    /* @4633588 constant */
    /* @4633592 cast */
    /* @4633596 constant */
    /* @4633600 cast */
    /* @4633604 call */
    GM_SITE(vm, 448, 4633604);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4633612 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v14, v15, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4633616 load */
    /* @4633624 constant */
    /* @4633628 cmp */
    /* @4633632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4633692;
    /* @4633636 string */
    /* @4633644 cast */
    /* @4633648 load */
    /* @4633656 constant */
    /* @4633660 add */
    /* @4633664 load */
    /* @4633672 constant */
    /* @4633676 add */
    /* @4633680 call */
    GM_SITE(vm, 448, 4633680);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(35));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4633688 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(824)));
    L_4633692: ;
    /* @4633692 load */
    /* @4633700 constant */
    /* @4633704 cmp */
    /* @4633708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4634208;
    /* @4633712 constant */
    /* @4633716 constant */
    /* @4633720 load */
    /* @4633728 constant */
    /* @4633732 add */
    /* @4633736 store */
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "x", v18);
    /* @4633744 constant */
    /* @4633748 constant */
    /* @4633752 load */
    /* @4633760 constant */
    /* @4633764 add */
    /* @4633768 store */
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    GM_WRITE(vm, -1, "y", v19);
    /* @4633776 constant */
    /* @4633780 cast */
    /* @4633784 constant */
    /* @4633788 cast */
    /* @4633792 constant */
    /* @4633796 cast */
    /* @4633800 constant */
    /* @4633812 cast */
    /* @4633816 constant */
    /* @4633828 cast */
    /* @4633832 load */
    /* @4633840 load */
    /* @4633848 constant */
    /* @4633852 cast */
    /* @4633856 constant */
    /* @4633860 cast */
    /* @4633864 call */
    GM_SITE(vm, 448, 4633864);
    /* @4633872 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4633876 constant */
    /* @4633880 cast */
    /* @4633884 call */
    GM_SITE(vm, 448, 4633884);
    /* @4633892 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4633896 constant */
    /* @4633904 cast */
    /* @4633908 call */
    GM_SITE(vm, 448, 4633908);
    /* @4633916 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4633920 string */
    /* @4633928 cast */
    /* @4633932 load */
    /* @4633940 constant */
    /* @4633944 add */
    /* @4633948 load */
    /* @4633956 constant */
    /* @4633960 add */
    /* @4633964 call */
    GM_SITE(vm, 448, 4633964);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4633972 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v20, v21, STR_REF(822)));
    /* @4633976 string */
    /* @4633984 cast */
    /* @4633988 load */
    /* @4633996 constant */
    /* @4634000 add */
    /* @4634004 load */
    /* @4634012 constant */
    /* @4634016 add */
    /* @4634020 call */
    GM_SITE(vm, 448, 4634020);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4634028 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v22, v23, STR_REF(823)));
    /* @4634032 constant */
    /* @4634036 cast */
    /* @4634040 constant */
    /* @4634044 cast */
    /* @4634048 constant */
    /* @4634052 cast */
    /* @4634056 constant */
    /* @4634060 cast */
    /* @4634064 constant */
    /* @4634068 cast */
    /* @4634072 load */
    /* @4634080 constant */
    /* @4634084 add */
    /* @4634088 load */
    /* @4634096 constant */
    /* @4634100 add */
    /* @4634104 constant */
    /* @4634108 cast */
    /* @4634112 constant */
    /* @4634116 cast */
    /* @4634120 call */
    GM_SITE(vm, 448, 4634120);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4634128 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v24, v25, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4634132 load */
    /* @4634140 constant */
    /* @4634144 cmp */
    /* @4634148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4634208;
    /* @4634152 string */
    /* @4634160 cast */
    /* @4634164 load */
    /* @4634172 constant */
    /* @4634176 add */
    /* @4634180 load */
    /* @4634188 constant */
    /* @4634192 add */
    /* @4634196 call */
    GM_SITE(vm, 448, 4634196);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4634204 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(824)));
    L_4634208: ;
    /* @4634208 load */
    /* @4634216 constant */
    /* @4634220 cmp */
    /* @4634224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4634724;
    /* @4634228 constant */
    /* @4634232 constant */
    /* @4634236 load */
    /* @4634244 constant */
    /* @4634248 add */
    /* @4634252 store */
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(80));
    GM_WRITE(vm, -1, "x", v28);
    /* @4634260 constant */
    /* @4634264 constant */
    /* @4634268 load */
    /* @4634276 constant */
    /* @4634280 add */
    /* @4634284 store */
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    GM_WRITE(vm, -1, "y", v29);
    /* @4634292 constant */
    /* @4634296 cast */
    /* @4634300 constant */
    /* @4634304 cast */
    /* @4634308 constant */
    /* @4634312 cast */
    /* @4634316 constant */
    /* @4634328 cast */
    /* @4634332 constant */
    /* @4634344 cast */
    /* @4634348 load */
    /* @4634356 load */
    /* @4634364 constant */
    /* @4634368 cast */
    /* @4634372 constant */
    /* @4634376 cast */
    /* @4634380 call */
    GM_SITE(vm, 448, 4634380);
    /* @4634388 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4634392 constant */
    /* @4634396 cast */
    /* @4634400 call */
    GM_SITE(vm, 448, 4634400);
    /* @4634408 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4634412 constant */
    /* @4634420 cast */
    /* @4634424 call */
    GM_SITE(vm, 448, 4634424);
    /* @4634432 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4634436 string */
    /* @4634444 cast */
    /* @4634448 load */
    /* @4634456 constant */
    /* @4634460 add */
    /* @4634464 load */
    /* @4634472 constant */
    /* @4634476 add */
    /* @4634480 call */
    GM_SITE(vm, 448, 4634480);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4634488 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v30, v31, STR_REF(822)));
    /* @4634492 string */
    /* @4634500 cast */
    /* @4634504 load */
    /* @4634512 constant */
    /* @4634516 add */
    /* @4634520 load */
    /* @4634528 constant */
    /* @4634532 add */
    /* @4634536 call */
    GM_SITE(vm, 448, 4634536);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4634544 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, v33, STR_REF(823)));
    /* @4634548 constant */
    /* @4634552 cast */
    /* @4634556 constant */
    /* @4634560 cast */
    /* @4634564 constant */
    /* @4634568 cast */
    /* @4634572 constant */
    /* @4634576 cast */
    /* @4634580 constant */
    /* @4634584 cast */
    /* @4634588 load */
    /* @4634596 constant */
    /* @4634600 add */
    /* @4634604 load */
    /* @4634612 constant */
    /* @4634616 add */
    /* @4634620 constant */
    /* @4634624 cast */
    /* @4634628 constant */
    /* @4634632 cast */
    /* @4634636 call */
    GM_SITE(vm, 448, 4634636);
    v34 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4634644 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v34, v35, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4634648 load */
    /* @4634656 constant */
    /* @4634660 cmp */
    /* @4634664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4634724;
    /* @4634668 string */
    /* @4634676 cast */
    /* @4634680 load */
    /* @4634688 constant */
    /* @4634692 add */
    /* @4634696 load */
    /* @4634704 constant */
    /* @4634708 add */
    /* @4634712 call */
    GM_SITE(vm, 448, 4634712);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v37 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4634720 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v36, v37, STR_REF(824)));
    L_4634724: ;
    /* @4634724 load */
    /* @4634732 constant */
    /* @4634736 cmp */
    /* @4634740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4635232;
    /* @4634744 constant */
    /* @4634748 constant */
    /* @4634752 load */
    /* @4634760 constant */
    /* @4634764 add */
    /* @4634768 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    GM_WRITE(vm, -1, "x", v38);
    /* @4634776 constant */
    /* @4634780 constant */
    /* @4634784 load */
    /* @4634792 constant */
    /* @4634796 add */
    /* @4634800 store */
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    GM_WRITE(vm, -1, "y", v39);
    /* @4634808 constant */
    /* @4634812 cast */
    /* @4634816 constant */
    /* @4634820 cast */
    /* @4634824 constant */
    /* @4634828 cast */
    /* @4634832 constant */
    /* @4634844 cast */
    /* @4634848 constant */
    /* @4634860 cast */
    /* @4634864 load */
    /* @4634872 load */
    /* @4634880 constant */
    /* @4634884 cast */
    /* @4634888 constant */
    /* @4634892 cast */
    /* @4634896 call */
    GM_SITE(vm, 448, 4634896);
    /* @4634904 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4634908 constant */
    /* @4634912 cast */
    /* @4634916 call */
    GM_SITE(vm, 448, 4634916);
    /* @4634924 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4634928 constant */
    /* @4634936 cast */
    /* @4634940 call */
    GM_SITE(vm, 448, 4634940);
    /* @4634948 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4634952 string */
    /* @4634960 cast */
    /* @4634964 load */
    /* @4634972 load */
    /* @4634980 constant */
    /* @4634984 add */
    /* @4634988 call */
    GM_SITE(vm, 448, 4634988);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4634996 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, GM_READ(vm, -1, "y"), STR_REF(822)));
    /* @4635000 string */
    /* @4635008 cast */
    /* @4635012 load */
    /* @4635020 constant */
    /* @4635024 add */
    /* @4635028 load */
    /* @4635036 constant */
    /* @4635040 add */
    /* @4635044 call */
    GM_SITE(vm, 448, 4635044);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v42 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635052 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(823)));
    /* @4635056 constant */
    /* @4635060 cast */
    /* @4635064 constant */
    /* @4635068 cast */
    /* @4635072 constant */
    /* @4635076 cast */
    /* @4635080 constant */
    /* @4635084 cast */
    /* @4635088 constant */
    /* @4635092 cast */
    /* @4635096 load */
    /* @4635104 constant */
    /* @4635108 add */
    /* @4635112 load */
    /* @4635120 constant */
    /* @4635124 add */
    /* @4635128 constant */
    /* @4635132 cast */
    /* @4635136 constant */
    /* @4635140 cast */
    /* @4635144 call */
    GM_SITE(vm, 448, 4635144);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v44 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635152 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v43, v44, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4635156 load */
    /* @4635164 constant */
    /* @4635168 cmp */
    /* @4635172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4635232;
    /* @4635176 string */
    /* @4635184 cast */
    /* @4635188 load */
    /* @4635196 constant */
    /* @4635200 add */
    /* @4635204 load */
    /* @4635212 constant */
    /* @4635216 add */
    /* @4635220 call */
    GM_SITE(vm, 448, 4635220);
    v45 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v46 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635228 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(824)));
    L_4635232: ;
    /* @4635232 load */
    /* @4635240 constant */
    /* @4635244 cmp */
    /* @4635248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4635740;
    /* @4635252 constant */
    /* @4635256 constant */
    /* @4635260 load */
    /* @4635268 constant */
    /* @4635272 add */
    /* @4635276 store */
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    GM_WRITE(vm, -1, "x", v47);
    /* @4635284 constant */
    /* @4635288 constant */
    /* @4635292 load */
    /* @4635300 constant */
    /* @4635304 add */
    /* @4635308 store */
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    GM_WRITE(vm, -1, "y", v48);
    /* @4635316 constant */
    /* @4635320 cast */
    /* @4635324 constant */
    /* @4635328 cast */
    /* @4635332 constant */
    /* @4635336 cast */
    /* @4635340 constant */
    /* @4635352 cast */
    /* @4635356 constant */
    /* @4635368 cast */
    /* @4635372 load */
    /* @4635380 load */
    /* @4635388 constant */
    /* @4635392 cast */
    /* @4635396 constant */
    /* @4635400 cast */
    /* @4635404 call */
    GM_SITE(vm, 448, 4635404);
    /* @4635412 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4635416 constant */
    /* @4635420 cast */
    /* @4635424 call */
    GM_SITE(vm, 448, 4635424);
    /* @4635432 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4635436 constant */
    /* @4635444 cast */
    /* @4635448 call */
    GM_SITE(vm, 448, 4635448);
    /* @4635456 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4635460 string */
    /* @4635468 cast */
    /* @4635472 load */
    /* @4635480 load */
    /* @4635488 constant */
    /* @4635492 add */
    /* @4635496 call */
    GM_SITE(vm, 448, 4635496);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4635504 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, GM_READ(vm, -1, "y"), STR_REF(822)));
    /* @4635508 string */
    /* @4635516 cast */
    /* @4635520 load */
    /* @4635528 constant */
    /* @4635532 add */
    /* @4635536 load */
    /* @4635544 constant */
    /* @4635548 add */
    /* @4635552 call */
    GM_SITE(vm, 448, 4635552);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v51 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635560 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v50, v51, STR_REF(823)));
    /* @4635564 constant */
    /* @4635568 cast */
    /* @4635572 constant */
    /* @4635576 cast */
    /* @4635580 constant */
    /* @4635584 cast */
    /* @4635588 constant */
    /* @4635592 cast */
    /* @4635596 constant */
    /* @4635600 cast */
    /* @4635604 load */
    /* @4635612 constant */
    /* @4635616 add */
    /* @4635620 load */
    /* @4635628 constant */
    /* @4635632 add */
    /* @4635636 constant */
    /* @4635640 cast */
    /* @4635644 constant */
    /* @4635648 cast */
    /* @4635652 call */
    GM_SITE(vm, 448, 4635652);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v53 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635660 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(86), VAL(1), v52, v53, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4635664 load */
    /* @4635672 constant */
    /* @4635676 cmp */
    /* @4635680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawhealthfull") == VAL(1)))) goto L_4635740;
    /* @4635684 string */
    /* @4635692 cast */
    /* @4635696 load */
    /* @4635704 constant */
    /* @4635708 add */
    /* @4635712 load */
    /* @4635720 constant */
    /* @4635724 add */
    /* @4635728 call */
    GM_SITE(vm, 448, 4635728);
    v54 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v55 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4635736 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v54, v55, STR_REF(824)));
    L_4635740: ;
    return;
}
