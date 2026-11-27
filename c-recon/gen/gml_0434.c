/* generated from CODE 434 (gml_Object_obj_strengthupgrade_Draw_0), source start 4611656, end 4615008. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0434(GmVM* vm) {
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
    /* @4611656 load */
    /* @4611664 constant */
    /* @4611668 cmp */
    /* @4611672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4612160;
    /* @4611676 constant */
    /* @4611680 cast */
    /* @4611684 constant */
    /* @4611688 cast */
    /* @4611692 constant */
    /* @4611696 cast */
    /* @4611700 constant */
    /* @4611712 cast */
    /* @4611716 constant */
    /* @4611728 cast */
    /* @4611732 load */
    /* @4611740 load */
    /* @4611748 constant */
    /* @4611752 cast */
    /* @4611756 constant */
    /* @4611760 cast */
    /* @4611764 call */
    GM_SITE(vm, 434, 4611764);
    /* @4611772 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4611776 constant */
    /* @4611780 cast */
    /* @4611784 call */
    GM_SITE(vm, 434, 4611784);
    /* @4611792 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4611796 constant */
    /* @4611804 cast */
    /* @4611808 call */
    GM_SITE(vm, 434, 4611808);
    /* @4611816 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4611820 string */
    /* @4611828 cast */
    /* @4611832 load */
    /* @4611840 load */
    /* @4611848 constant */
    /* @4611852 add */
    /* @4611856 call */
    GM_SITE(vm, 434, 4611856);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4611864 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v1, GM_READ(vm, -1, "y"), STR_REF(813)));
    /* @4611868 string */
    /* @4611876 cast */
    /* @4611880 load */
    /* @4611888 constant */
    /* @4611892 add */
    /* @4611896 load */
    /* @4611904 constant */
    /* @4611908 add */
    /* @4611912 call */
    GM_SITE(vm, 434, 4611912);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4611920 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, v3, STR_REF(803)));
    /* @4611924 constant */
    /* @4611928 cast */
    /* @4611932 constant */
    /* @4611936 cast */
    /* @4611940 constant */
    /* @4611944 cast */
    /* @4611948 constant */
    /* @4611960 cast */
    /* @4611964 constant */
    /* @4611976 cast */
    /* @4611980 load */
    /* @4611988 constant */
    /* @4611992 add */
    /* @4611996 load */
    /* @4612004 constant */
    /* @4612008 add */
    /* @4612012 constant */
    /* @4612016 cast */
    /* @4612020 constant */
    /* @4612024 cast */
    /* @4612028 call */
    GM_SITE(vm, 434, 4612028);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4612036 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v4, v5, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4612040 load */
    /* @4612048 constant */
    /* @4612052 cmp */
    /* @4612056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4612160;
    /* @4612060 constant */
    /* @4612064 cast */
    /* @4612068 constant */
    /* @4612072 cast */
    /* @4612076 constant */
    /* @4612080 cast */
    /* @4612084 constant */
    /* @4612096 cast */
    /* @4612100 constant */
    /* @4612112 cast */
    /* @4612116 load */
    /* @4612124 load */
    /* @4612132 constant */
    /* @4612136 cast */
    /* @4612140 constant */
    /* @4612144 cast */
    /* @4612148 call */
    GM_SITE(vm, 434, 4612148);
    /* @4612156 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4612160: ;
    /* @4612160 load */
    /* @4612168 constant */
    /* @4612172 cmp */
    /* @4612176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4612720;
    /* @4612180 constant */
    /* @4612184 constant */
    /* @4612188 load */
    /* @4612196 constant */
    /* @4612200 add */
    /* @4612204 store */
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(210));
    GM_WRITE(vm, -1, "x", v6);
    /* @4612212 constant */
    /* @4612216 constant */
    /* @4612220 load */
    /* @4612228 constant */
    /* @4612232 add */
    /* @4612236 store */
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    GM_WRITE(vm, -1, "y", v7);
    /* @4612244 constant */
    /* @4612248 cast */
    /* @4612252 constant */
    /* @4612256 cast */
    /* @4612260 constant */
    /* @4612264 cast */
    /* @4612268 constant */
    /* @4612272 cast */
    /* @4612276 constant */
    /* @4612280 cast */
    /* @4612284 load */
    /* @4612292 load */
    /* @4612300 constant */
    /* @4612304 cast */
    /* @4612308 constant */
    /* @4612312 cast */
    /* @4612316 call */
    GM_SITE(vm, 434, 4612316);
    /* @4612324 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4612328 constant */
    /* @4612332 cast */
    /* @4612336 call */
    GM_SITE(vm, 434, 4612336);
    /* @4612344 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(4)));
    /* @4612348 constant */
    /* @4612356 cast */
    /* @4612360 call */
    GM_SITE(vm, 434, 4612360);
    /* @4612368 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4612372 string */
    /* @4612380 cast */
    /* @4612384 load */
    /* @4612392 constant */
    /* @4612396 add */
    /* @4612400 load */
    /* @4612408 constant */
    /* @4612412 add */
    /* @4612416 call */
    GM_SITE(vm, 434, 4612416);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4612424 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v8, v9, STR_REF(813)));
    /* @4612428 string */
    /* @4612436 cast */
    /* @4612440 load */
    /* @4612448 constant */
    /* @4612452 add */
    /* @4612456 load */
    /* @4612464 constant */
    /* @4612468 add */
    /* @4612472 call */
    GM_SITE(vm, 434, 4612472);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @4612480 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v10, v11, STR_REF(803)));
    /* @4612484 constant */
    /* @4612488 cast */
    /* @4612492 constant */
    /* @4612496 cast */
    /* @4612500 constant */
    /* @4612504 cast */
    /* @4612508 constant */
    /* @4612520 cast */
    /* @4612524 constant */
    /* @4612536 cast */
    /* @4612540 load */
    /* @4612548 constant */
    /* @4612552 add */
    /* @4612556 load */
    /* @4612564 constant */
    /* @4612568 add */
    /* @4612572 constant */
    /* @4612576 cast */
    /* @4612580 constant */
    /* @4612584 cast */
    /* @4612588 call */
    GM_SITE(vm, 434, 4612588);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(110));
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4612596 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v12, v13, VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    /* @4612600 load */
    /* @4612608 constant */
    /* @4612612 cmp */
    /* @4612616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4612720;
    /* @4612620 constant */
    /* @4612624 cast */
    /* @4612628 constant */
    /* @4612632 cast */
    /* @4612636 constant */
    /* @4612640 cast */
    /* @4612644 constant */
    /* @4612656 cast */
    /* @4612660 constant */
    /* @4612672 cast */
    /* @4612676 load */
    /* @4612684 load */
    /* @4612692 constant */
    /* @4612696 cast */
    /* @4612700 constant */
    /* @4612704 cast */
    /* @4612708 call */
    GM_SITE(vm, 434, 4612708);
    /* @4612716 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.5), VAL(0.5), VAL(0), VAL(-1), VAL(1)));
    L_4612720: ;
    /* @4612720 load */
    /* @4612728 constant */
    /* @4612732 cmp */
    /* @4612736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4613296;
    /* @4612740 constant */
    /* @4612744 constant */
    /* @4612748 load */
    /* @4612756 constant */
    /* @4612760 add */
    /* @4612764 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(280));
    GM_WRITE(vm, -1, "x", v14);
    /* @4612772 constant */
    /* @4612776 constant */
    /* @4612780 load */
    /* @4612788 constant */
    /* @4612792 add */
    /* @4612796 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    GM_WRITE(vm, -1, "y", v15);
    /* @4612804 constant */
    /* @4612808 cast */
    /* @4612812 constant */
    /* @4612816 cast */
    /* @4612820 constant */
    /* @4612824 cast */
    /* @4612828 constant */
    /* @4612840 cast */
    /* @4612844 constant */
    /* @4612856 cast */
    /* @4612860 load */
    /* @4612868 load */
    /* @4612876 constant */
    /* @4612880 cast */
    /* @4612884 constant */
    /* @4612888 cast */
    /* @4612892 call */
    GM_SITE(vm, 434, 4612892);
    /* @4612900 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4612904 constant */
    /* @4612908 cast */
    /* @4612912 call */
    GM_SITE(vm, 434, 4612912);
    /* @4612920 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4612924 constant */
    /* @4612932 cast */
    /* @4612936 call */
    GM_SITE(vm, 434, 4612936);
    /* @4612944 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4612948 string */
    /* @4612956 cast */
    /* @4612960 load */
    /* @4612968 constant */
    /* @4612972 add */
    /* @4612976 load */
    /* @4612984 constant */
    /* @4612988 add */
    /* @4612992 call */
    GM_SITE(vm, 434, 4612992);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4613000 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v16, v17, STR_REF(813)));
    /* @4613004 string */
    /* @4613012 cast */
    /* @4613016 load */
    /* @4613024 constant */
    /* @4613028 add */
    /* @4613032 load */
    /* @4613040 constant */
    /* @4613044 add */
    /* @4613048 call */
    GM_SITE(vm, 434, 4613048);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4613056 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v18, v19, STR_REF(803)));
    /* @4613060 constant */
    /* @4613064 cast */
    /* @4613068 constant */
    /* @4613072 cast */
    /* @4613076 constant */
    /* @4613080 cast */
    /* @4613084 constant */
    /* @4613096 cast */
    /* @4613100 constant */
    /* @4613112 cast */
    /* @4613116 load */
    /* @4613124 constant */
    /* @4613128 add */
    /* @4613132 load */
    /* @4613140 constant */
    /* @4613144 add */
    /* @4613148 constant */
    /* @4613152 cast */
    /* @4613156 constant */
    /* @4613160 cast */
    /* @4613164 call */
    GM_SITE(vm, 434, 4613164);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4613172 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v20, v21, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4613176 load */
    /* @4613184 constant */
    /* @4613188 cmp */
    /* @4613192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4613296;
    /* @4613196 constant */
    /* @4613200 cast */
    /* @4613204 constant */
    /* @4613208 cast */
    /* @4613212 constant */
    /* @4613216 cast */
    /* @4613220 constant */
    /* @4613232 cast */
    /* @4613236 constant */
    /* @4613248 cast */
    /* @4613252 load */
    /* @4613260 load */
    /* @4613268 constant */
    /* @4613272 cast */
    /* @4613276 constant */
    /* @4613280 cast */
    /* @4613284 call */
    GM_SITE(vm, 434, 4613284);
    /* @4613292 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4613296: ;
    /* @4613296 load */
    /* @4613304 constant */
    /* @4613308 cmp */
    /* @4613312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4613872;
    /* @4613316 constant */
    /* @4613320 constant */
    /* @4613324 load */
    /* @4613332 constant */
    /* @4613336 add */
    /* @4613340 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(280));
    GM_WRITE(vm, -1, "x", v22);
    /* @4613348 constant */
    /* @4613352 constant */
    /* @4613356 load */
    /* @4613364 constant */
    /* @4613368 add */
    /* @4613372 store */
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(100));
    GM_WRITE(vm, -1, "y", v23);
    /* @4613380 constant */
    /* @4613384 cast */
    /* @4613388 constant */
    /* @4613392 cast */
    /* @4613396 constant */
    /* @4613400 cast */
    /* @4613404 constant */
    /* @4613416 cast */
    /* @4613420 constant */
    /* @4613432 cast */
    /* @4613436 load */
    /* @4613444 load */
    /* @4613452 constant */
    /* @4613456 cast */
    /* @4613460 constant */
    /* @4613464 cast */
    /* @4613468 call */
    GM_SITE(vm, 434, 4613468);
    /* @4613476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4613480 constant */
    /* @4613484 cast */
    /* @4613488 call */
    GM_SITE(vm, 434, 4613488);
    /* @4613496 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4613500 constant */
    /* @4613508 cast */
    /* @4613512 call */
    GM_SITE(vm, 434, 4613512);
    /* @4613520 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4613524 string */
    /* @4613532 cast */
    /* @4613536 load */
    /* @4613544 constant */
    /* @4613548 add */
    /* @4613552 load */
    /* @4613560 constant */
    /* @4613564 add */
    /* @4613568 call */
    GM_SITE(vm, 434, 4613568);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4613576 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v24, v25, STR_REF(813)));
    /* @4613580 string */
    /* @4613588 cast */
    /* @4613592 load */
    /* @4613600 constant */
    /* @4613604 add */
    /* @4613608 load */
    /* @4613616 constant */
    /* @4613620 add */
    /* @4613624 call */
    GM_SITE(vm, 434, 4613624);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4613632 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v26, v27, STR_REF(803)));
    /* @4613636 constant */
    /* @4613640 cast */
    /* @4613644 constant */
    /* @4613648 cast */
    /* @4613652 constant */
    /* @4613656 cast */
    /* @4613660 constant */
    /* @4613672 cast */
    /* @4613676 constant */
    /* @4613688 cast */
    /* @4613692 load */
    /* @4613700 constant */
    /* @4613704 add */
    /* @4613708 load */
    /* @4613716 constant */
    /* @4613720 add */
    /* @4613724 constant */
    /* @4613728 cast */
    /* @4613732 constant */
    /* @4613736 cast */
    /* @4613740 call */
    GM_SITE(vm, 434, 4613740);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(17));
    /* @4613748 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v28, v29, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4613752 load */
    /* @4613760 constant */
    /* @4613764 cmp */
    /* @4613768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4613872;
    /* @4613772 constant */
    /* @4613776 cast */
    /* @4613780 constant */
    /* @4613784 cast */
    /* @4613788 constant */
    /* @4613792 cast */
    /* @4613796 constant */
    /* @4613808 cast */
    /* @4613812 constant */
    /* @4613824 cast */
    /* @4613828 load */
    /* @4613836 load */
    /* @4613844 constant */
    /* @4613848 cast */
    /* @4613852 constant */
    /* @4613856 cast */
    /* @4613860 call */
    GM_SITE(vm, 434, 4613860);
    /* @4613868 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.6), VAL(0), VAL(-1), VAL(1)));
    L_4613872: ;
    /* @4613872 load */
    /* @4613880 constant */
    /* @4613884 cmp */
    /* @4613888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4614440;
    /* @4613892 constant */
    /* @4613896 constant */
    /* @4613900 load */
    /* @4613908 constant */
    /* @4613912 add */
    /* @4613916 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    GM_WRITE(vm, -1, "x", v30);
    /* @4613924 constant */
    /* @4613928 constant */
    /* @4613932 load */
    /* @4613940 constant */
    /* @4613944 add */
    /* @4613948 store */
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    GM_WRITE(vm, -1, "y", v31);
    /* @4613956 constant */
    /* @4613960 cast */
    /* @4613964 constant */
    /* @4613968 cast */
    /* @4613972 constant */
    /* @4613976 cast */
    /* @4613980 constant */
    /* @4613992 cast */
    /* @4613996 constant */
    /* @4614008 cast */
    /* @4614012 load */
    /* @4614020 load */
    /* @4614028 constant */
    /* @4614032 cast */
    /* @4614036 constant */
    /* @4614040 cast */
    /* @4614044 call */
    GM_SITE(vm, 434, 4614044);
    /* @4614052 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4614056 constant */
    /* @4614060 cast */
    /* @4614064 call */
    GM_SITE(vm, 434, 4614064);
    /* @4614072 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4614076 constant */
    /* @4614084 cast */
    /* @4614088 call */
    GM_SITE(vm, 434, 4614088);
    /* @4614096 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4614100 string */
    /* @4614108 cast */
    /* @4614112 load */
    /* @4614120 load */
    /* @4614128 constant */
    /* @4614132 add */
    /* @4614136 call */
    GM_SITE(vm, 434, 4614136);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4614144 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v32, GM_READ(vm, -1, "y"), STR_REF(813)));
    /* @4614148 string */
    /* @4614156 cast */
    /* @4614160 load */
    /* @4614168 constant */
    /* @4614172 add */
    /* @4614176 load */
    /* @4614184 constant */
    /* @4614188 add */
    /* @4614192 call */
    GM_SITE(vm, 434, 4614192);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v34 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4614200 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v33, v34, STR_REF(803)));
    /* @4614204 constant */
    /* @4614208 cast */
    /* @4614212 constant */
    /* @4614216 cast */
    /* @4614220 constant */
    /* @4614224 cast */
    /* @4614228 constant */
    /* @4614240 cast */
    /* @4614244 constant */
    /* @4614256 cast */
    /* @4614260 load */
    /* @4614268 constant */
    /* @4614272 add */
    /* @4614276 load */
    /* @4614284 constant */
    /* @4614288 add */
    /* @4614292 constant */
    /* @4614296 cast */
    /* @4614300 constant */
    /* @4614304 cast */
    /* @4614308 call */
    GM_SITE(vm, 434, 4614308);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v36 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4614316 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v35, v36, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4614320 load */
    /* @4614328 constant */
    /* @4614332 cmp */
    /* @4614336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4614440;
    /* @4614340 constant */
    /* @4614344 cast */
    /* @4614348 constant */
    /* @4614352 cast */
    /* @4614356 constant */
    /* @4614360 cast */
    /* @4614364 constant */
    /* @4614376 cast */
    /* @4614380 constant */
    /* @4614392 cast */
    /* @4614396 load */
    /* @4614404 load */
    /* @4614412 constant */
    /* @4614416 cast */
    /* @4614420 constant */
    /* @4614424 cast */
    /* @4614428 call */
    GM_SITE(vm, 434, 4614428);
    /* @4614436 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4614440: ;
    /* @4614440 load */
    /* @4614448 constant */
    /* @4614452 cmp */
    /* @4614456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4615008;
    /* @4614460 constant */
    /* @4614464 constant */
    /* @4614468 load */
    /* @4614476 constant */
    /* @4614480 add */
    /* @4614484 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    GM_WRITE(vm, -1, "x", v37);
    /* @4614492 constant */
    /* @4614496 constant */
    /* @4614500 load */
    /* @4614508 constant */
    /* @4614512 add */
    /* @4614516 store */
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    GM_WRITE(vm, -1, "y", v38);
    /* @4614524 constant */
    /* @4614528 cast */
    /* @4614532 constant */
    /* @4614536 cast */
    /* @4614540 constant */
    /* @4614544 cast */
    /* @4614548 constant */
    /* @4614560 cast */
    /* @4614564 constant */
    /* @4614576 cast */
    /* @4614580 load */
    /* @4614588 load */
    /* @4614596 constant */
    /* @4614600 cast */
    /* @4614604 constant */
    /* @4614608 cast */
    /* @4614612 call */
    GM_SITE(vm, 434, 4614612);
    /* @4614620 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(154), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(1.2), VAL(1.1), VAL(0), VAL(-1), VAL(1)));
    /* @4614624 constant */
    /* @4614628 cast */
    /* @4614632 call */
    GM_SITE(vm, 434, 4614632);
    /* @4614640 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4614644 constant */
    /* @4614652 cast */
    /* @4614656 call */
    GM_SITE(vm, 434, 4614656);
    /* @4614664 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4614668 string */
    /* @4614676 cast */
    /* @4614680 load */
    /* @4614688 load */
    /* @4614696 constant */
    /* @4614700 add */
    /* @4614704 call */
    GM_SITE(vm, 434, 4614704);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4614712 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, GM_READ(vm, -1, "y"), STR_REF(813)));
    /* @4614716 string */
    /* @4614724 cast */
    /* @4614728 load */
    /* @4614736 constant */
    /* @4614740 add */
    /* @4614744 load */
    /* @4614752 constant */
    /* @4614756 add */
    /* @4614760 call */
    GM_SITE(vm, 434, 4614760);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v41 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4614768 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v40, v41, STR_REF(803)));
    /* @4614772 constant */
    /* @4614776 cast */
    /* @4614780 constant */
    /* @4614784 cast */
    /* @4614788 constant */
    /* @4614792 cast */
    /* @4614796 constant */
    /* @4614808 cast */
    /* @4614812 constant */
    /* @4614824 cast */
    /* @4614828 load */
    /* @4614836 constant */
    /* @4614840 add */
    /* @4614844 load */
    /* @4614852 constant */
    /* @4614856 add */
    /* @4614860 constant */
    /* @4614864 cast */
    /* @4614868 constant */
    /* @4614872 cast */
    /* @4614876 call */
    GM_SITE(vm, 434, 4614876);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(135));
    v43 = GM_ADD(GM_READ(vm, -1, "y"), VAL(15));
    /* @4614884 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(31), VAL(2), v42, v43, VAL(0.7), VAL(0.7), VAL(0), VAL(-1), VAL(1)));
    /* @4614888 load */
    /* @4614896 constant */
    /* @4614900 cmp */
    /* @4614904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "strengthupgradebought") == VAL(1)))) goto L_4615008;
    /* @4614908 constant */
    /* @4614912 cast */
    /* @4614916 constant */
    /* @4614920 cast */
    /* @4614924 constant */
    /* @4614928 cast */
    /* @4614932 constant */
    /* @4614944 cast */
    /* @4614948 constant */
    /* @4614960 cast */
    /* @4614964 load */
    /* @4614972 load */
    /* @4614980 constant */
    /* @4614984 cast */
    /* @4614988 constant */
    /* @4614992 cast */
    /* @4614996 call */
    GM_SITE(vm, 434, 4614996);
    /* @4615004 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(148), VAL(1), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0.6), VAL(0.55), VAL(0), VAL(-1), VAL(1)));
    L_4615008: ;
    return;
}
