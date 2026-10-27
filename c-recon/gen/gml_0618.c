/* generated from CODE 618 (gml_Object_obj_lloydtutorial9_Draw_0), source start 4931888, end 4938208. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0618(GmVM* vm) {
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
    Val v56;
    Val v57;
    Val v58;
    Val v59;
    Val v60;
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val p4938192_0;
    Val v85;
    /* @4931888 constant */
    /* @4931892 load */
    /* @4931900 cast */
    /* @4931904 load */
    /* @4931912 store */
    GM_WRITE(vm, -1, "x", GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4931920 constant */
    /* @4931924 load */
    /* @4931932 cast */
    /* @4931936 load */
    /* @4931944 store */
    GM_WRITE(vm, -1, "y", GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))));
    /* @4931952 load */
    /* @4931960 constant */
    /* @4931964 cmp */
    /* @4931968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4932496;
    /* @4931972 constant */
    /* @4931976 cast */
    /* @4931980 constant */
    /* @4931984 cast */
    /* @4931988 constant */
    /* @4931992 cast */
    /* @4931996 constant */
    /* @4932008 cast */
    /* @4932012 constant */
    /* @4932024 cast */
    /* @4932028 constant */
    /* @4932032 constant */
    /* @4932036 load */
    /* @4932044 constant */
    /* @4932048 constant */
    /* @4932052 load */
    /* @4932060 constant */
    /* @4932064 sub */
    /* @4932068 constant */
    /* @4932072 cast */
    /* @4932076 constant */
    /* @4932080 cast */
    /* @4932084 call */
    GM_SITE(vm, 618, 4932084);
    /* @4932092 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(0.96), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4932096 constant */
    /* @4932100 cast */
    /* @4932104 constant */
    /* @4932108 cast */
    /* @4932112 constant */
    /* @4932116 cast */
    /* @4932120 constant */
    /* @4932124 cast */
    /* @4932128 constant */
    /* @4932132 cast */
    /* @4932136 constant */
    /* @4932140 load */
    /* @4932148 cast */
    /* @4932152 load */
    /* @4932160 constant */
    /* @4932164 add */
    /* @4932168 constant */
    /* @4932172 load */
    /* @4932180 cast */
    /* @4932184 load */
    /* @4932192 constant */
    /* @4932196 add */
    /* @4932200 constant */
    /* @4932204 cast */
    /* @4932208 constant */
    /* @4932212 cast */
    /* @4932216 call */
    GM_SITE(vm, 618, 4932216);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4932224 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v1, v2, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4932228 constant */
    /* @4932232 cast */
    /* @4932236 constant */
    /* @4932240 cast */
    /* @4932244 constant */
    /* @4932248 cast */
    /* @4932252 constant */
    /* @4932256 cast */
    /* @4932260 constant */
    /* @4932264 cast */
    /* @4932268 constant */
    /* @4932272 load */
    /* @4932280 cast */
    /* @4932284 load */
    /* @4932292 constant */
    /* @4932296 add */
    /* @4932300 constant */
    /* @4932304 load */
    /* @4932312 cast */
    /* @4932316 load */
    /* @4932324 constant */
    /* @4932328 add */
    /* @4932332 constant */
    /* @4932336 cast */
    /* @4932340 constant */
    /* @4932344 cast */
    /* @4932348 call */
    GM_SITE(vm, 618, 4932348);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4932356 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v3, v4, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4932360 load */
    /* @4932368 constant */
    /* @4932372 cmp */
    /* @4932376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4932496;
    /* @4932380 constant */
    /* @4932384 cast */
    /* @4932388 call */
    GM_SITE(vm, 618, 4932388);
    /* @4932396 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4932400 constant */
    /* @4932408 cast */
    /* @4932412 call */
    GM_SITE(vm, 618, 4932412);
    /* @4932420 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4932424 string */
    /* @4932432 cast */
    /* @4932436 constant */
    /* @4932440 constant */
    /* @4932444 load */
    /* @4932452 constant */
    /* @4932456 add */
    /* @4932460 constant */
    /* @4932464 constant */
    /* @4932468 load */
    /* @4932476 constant */
    /* @4932480 add */
    /* @4932484 call */
    GM_SITE(vm, 618, 4932484);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(200));
    /* @4932492 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v5, v6, STR_REF(743)));
    L_4932496: ;
    /* @4932496 load */
    /* @4932504 constant */
    /* @4932508 cmp */
    /* @4932512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4933040;
    /* @4932516 constant */
    /* @4932520 cast */
    /* @4932524 constant */
    /* @4932528 cast */
    /* @4932532 constant */
    /* @4932536 cast */
    /* @4932540 constant */
    /* @4932552 cast */
    /* @4932556 constant */
    /* @4932568 cast */
    /* @4932572 constant */
    /* @4932576 constant */
    /* @4932580 load */
    /* @4932588 constant */
    /* @4932592 constant */
    /* @4932596 load */
    /* @4932604 constant */
    /* @4932608 sub */
    /* @4932612 constant */
    /* @4932616 cast */
    /* @4932620 constant */
    /* @4932624 cast */
    /* @4932628 call */
    GM_SITE(vm, 618, 4932628);
    /* @4932636 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(0.82), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4932640 constant */
    /* @4932644 cast */
    /* @4932648 constant */
    /* @4932652 cast */
    /* @4932656 constant */
    /* @4932660 cast */
    /* @4932664 constant */
    /* @4932668 cast */
    /* @4932672 constant */
    /* @4932676 cast */
    /* @4932680 constant */
    /* @4932684 load */
    /* @4932692 cast */
    /* @4932696 load */
    /* @4932704 constant */
    /* @4932708 add */
    /* @4932712 constant */
    /* @4932716 load */
    /* @4932724 cast */
    /* @4932728 load */
    /* @4932736 constant */
    /* @4932740 add */
    /* @4932744 constant */
    /* @4932748 cast */
    /* @4932752 constant */
    /* @4932756 cast */
    /* @4932760 call */
    GM_SITE(vm, 618, 4932760);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4932768 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v7, v8, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4932772 constant */
    /* @4932776 cast */
    /* @4932780 constant */
    /* @4932784 cast */
    /* @4932788 constant */
    /* @4932792 cast */
    /* @4932796 constant */
    /* @4932800 cast */
    /* @4932804 constant */
    /* @4932808 cast */
    /* @4932812 constant */
    /* @4932816 load */
    /* @4932824 cast */
    /* @4932828 load */
    /* @4932836 constant */
    /* @4932840 add */
    /* @4932844 constant */
    /* @4932848 load */
    /* @4932856 cast */
    /* @4932860 load */
    /* @4932868 constant */
    /* @4932872 add */
    /* @4932876 constant */
    /* @4932880 cast */
    /* @4932884 constant */
    /* @4932888 cast */
    /* @4932892 call */
    GM_SITE(vm, 618, 4932892);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(320));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4932900 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v9, v10, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4932904 load */
    /* @4932912 constant */
    /* @4932916 cmp */
    /* @4932920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4933040;
    /* @4932924 constant */
    /* @4932928 cast */
    /* @4932932 call */
    GM_SITE(vm, 618, 4932932);
    /* @4932940 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4932944 constant */
    /* @4932952 cast */
    /* @4932956 call */
    GM_SITE(vm, 618, 4932956);
    /* @4932964 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4932968 string */
    /* @4932976 cast */
    /* @4932980 constant */
    /* @4932984 constant */
    /* @4932988 load */
    /* @4932996 constant */
    /* @4933000 add */
    /* @4933004 constant */
    /* @4933008 constant */
    /* @4933012 load */
    /* @4933020 constant */
    /* @4933024 add */
    /* @4933028 call */
    GM_SITE(vm, 618, 4933028);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(110));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4933036 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v11, v12, STR_REF(743)));
    L_4933040: ;
    /* @4933040 load */
    /* @4933048 constant */
    /* @4933052 cmp */
    /* @4933056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4933584;
    /* @4933060 constant */
    /* @4933064 cast */
    /* @4933068 constant */
    /* @4933072 cast */
    /* @4933076 constant */
    /* @4933080 cast */
    /* @4933084 constant */
    /* @4933096 cast */
    /* @4933100 constant */
    /* @4933112 cast */
    /* @4933116 constant */
    /* @4933120 constant */
    /* @4933124 load */
    /* @4933132 constant */
    /* @4933136 constant */
    /* @4933140 load */
    /* @4933148 constant */
    /* @4933152 sub */
    /* @4933156 constant */
    /* @4933160 cast */
    /* @4933164 constant */
    /* @4933168 cast */
    /* @4933172 call */
    GM_SITE(vm, 618, 4933172);
    /* @4933180 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4933184 constant */
    /* @4933188 cast */
    /* @4933192 constant */
    /* @4933196 cast */
    /* @4933200 constant */
    /* @4933204 cast */
    /* @4933208 constant */
    /* @4933212 cast */
    /* @4933216 constant */
    /* @4933220 cast */
    /* @4933224 constant */
    /* @4933228 load */
    /* @4933236 cast */
    /* @4933240 load */
    /* @4933248 constant */
    /* @4933252 add */
    /* @4933256 constant */
    /* @4933260 load */
    /* @4933268 cast */
    /* @4933272 load */
    /* @4933280 constant */
    /* @4933284 add */
    /* @4933288 constant */
    /* @4933292 cast */
    /* @4933296 constant */
    /* @4933300 cast */
    /* @4933304 call */
    GM_SITE(vm, 618, 4933304);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4933312 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v13, v14, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4933316 constant */
    /* @4933320 cast */
    /* @4933324 constant */
    /* @4933328 cast */
    /* @4933332 constant */
    /* @4933336 cast */
    /* @4933340 constant */
    /* @4933344 cast */
    /* @4933348 constant */
    /* @4933352 cast */
    /* @4933356 constant */
    /* @4933360 load */
    /* @4933368 cast */
    /* @4933372 load */
    /* @4933380 constant */
    /* @4933384 add */
    /* @4933388 constant */
    /* @4933392 load */
    /* @4933400 cast */
    /* @4933404 load */
    /* @4933412 constant */
    /* @4933416 add */
    /* @4933420 constant */
    /* @4933424 cast */
    /* @4933428 constant */
    /* @4933432 cast */
    /* @4933436 call */
    GM_SITE(vm, 618, 4933436);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4933444 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v15, v16, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4933448 load */
    /* @4933456 constant */
    /* @4933460 cmp */
    /* @4933464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4933584;
    /* @4933468 constant */
    /* @4933472 cast */
    /* @4933476 call */
    GM_SITE(vm, 618, 4933476);
    /* @4933484 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4933488 constant */
    /* @4933496 cast */
    /* @4933500 call */
    GM_SITE(vm, 618, 4933500);
    /* @4933508 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4933512 string */
    /* @4933520 cast */
    /* @4933524 constant */
    /* @4933528 constant */
    /* @4933532 load */
    /* @4933540 constant */
    /* @4933544 add */
    /* @4933548 constant */
    /* @4933552 constant */
    /* @4933556 load */
    /* @4933564 constant */
    /* @4933568 add */
    /* @4933572 call */
    GM_SITE(vm, 618, 4933572);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(180));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(300));
    /* @4933580 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v17, v18, STR_REF(743)));
    L_4933584: ;
    /* @4933584 load */
    /* @4933592 constant */
    /* @4933596 cmp */
    /* @4933600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4934128;
    /* @4933604 constant */
    /* @4933608 cast */
    /* @4933612 constant */
    /* @4933616 cast */
    /* @4933620 constant */
    /* @4933624 cast */
    /* @4933628 constant */
    /* @4933640 cast */
    /* @4933644 constant */
    /* @4933656 cast */
    /* @4933660 constant */
    /* @4933664 constant */
    /* @4933668 load */
    /* @4933676 constant */
    /* @4933680 constant */
    /* @4933684 load */
    /* @4933692 constant */
    /* @4933696 sub */
    /* @4933700 constant */
    /* @4933704 cast */
    /* @4933708 constant */
    /* @4933712 cast */
    /* @4933716 call */
    GM_SITE(vm, 618, 4933716);
    /* @4933724 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(1.08), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4933728 constant */
    /* @4933732 cast */
    /* @4933736 constant */
    /* @4933740 cast */
    /* @4933744 constant */
    /* @4933748 cast */
    /* @4933752 constant */
    /* @4933756 cast */
    /* @4933760 constant */
    /* @4933764 cast */
    /* @4933768 constant */
    /* @4933772 load */
    /* @4933780 cast */
    /* @4933784 load */
    /* @4933792 constant */
    /* @4933796 add */
    /* @4933800 constant */
    /* @4933804 load */
    /* @4933812 cast */
    /* @4933816 load */
    /* @4933824 constant */
    /* @4933828 add */
    /* @4933832 constant */
    /* @4933836 cast */
    /* @4933840 constant */
    /* @4933844 cast */
    /* @4933848 call */
    GM_SITE(vm, 618, 4933848);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4933856 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v19, v20, VAL(3), VAL(3), VAL(0), VAL(-1), VAL(1)));
    /* @4933860 constant */
    /* @4933864 cast */
    /* @4933868 constant */
    /* @4933872 cast */
    /* @4933876 constant */
    /* @4933880 cast */
    /* @4933884 constant */
    /* @4933888 cast */
    /* @4933892 constant */
    /* @4933896 cast */
    /* @4933900 constant */
    /* @4933904 load */
    /* @4933912 cast */
    /* @4933916 load */
    /* @4933924 constant */
    /* @4933928 add */
    /* @4933932 constant */
    /* @4933936 load */
    /* @4933944 cast */
    /* @4933948 load */
    /* @4933956 constant */
    /* @4933960 add */
    /* @4933964 constant */
    /* @4933968 cast */
    /* @4933972 constant */
    /* @4933976 cast */
    /* @4933980 call */
    GM_SITE(vm, 618, 4933980);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(420));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(240));
    /* @4933988 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v21, v22, VAL(-3), VAL(3), VAL(1), VAL(-1), VAL(1)));
    /* @4933992 load */
    /* @4934000 constant */
    /* @4934004 cmp */
    /* @4934008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4934128;
    /* @4934012 constant */
    /* @4934016 cast */
    /* @4934020 call */
    GM_SITE(vm, 618, 4934020);
    /* @4934028 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4934032 constant */
    /* @4934040 cast */
    /* @4934044 call */
    GM_SITE(vm, 618, 4934044);
    /* @4934052 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4934056 string */
    /* @4934064 cast */
    /* @4934068 constant */
    /* @4934072 constant */
    /* @4934076 load */
    /* @4934084 constant */
    /* @4934088 add */
    /* @4934092 constant */
    /* @4934096 constant */
    /* @4934100 load */
    /* @4934108 constant */
    /* @4934112 add */
    /* @4934116 call */
    GM_SITE(vm, 618, 4934116);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(180));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(300));
    /* @4934124 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v23, v24, STR_REF(743)));
    L_4934128: ;
    /* @4934128 load */
    /* @4934136 constant */
    /* @4934140 cmp */
    /* @4934144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4934672;
    /* @4934148 constant */
    /* @4934152 cast */
    /* @4934156 constant */
    /* @4934160 cast */
    /* @4934164 constant */
    /* @4934168 cast */
    /* @4934172 constant */
    /* @4934184 cast */
    /* @4934188 constant */
    /* @4934200 cast */
    /* @4934204 constant */
    /* @4934208 constant */
    /* @4934212 load */
    /* @4934220 constant */
    /* @4934224 constant */
    /* @4934228 load */
    /* @4934236 constant */
    /* @4934240 sub */
    /* @4934244 constant */
    /* @4934248 cast */
    /* @4934252 constant */
    /* @4934256 cast */
    /* @4934260 call */
    GM_SITE(vm, 618, 4934260);
    /* @4934268 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(0.97), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4934272 constant */
    /* @4934276 cast */
    /* @4934280 constant */
    /* @4934284 cast */
    /* @4934288 constant */
    /* @4934292 cast */
    /* @4934296 constant */
    /* @4934300 cast */
    /* @4934304 constant */
    /* @4934308 cast */
    /* @4934312 constant */
    /* @4934316 load */
    /* @4934324 cast */
    /* @4934328 load */
    /* @4934336 constant */
    /* @4934340 add */
    /* @4934344 constant */
    /* @4934348 load */
    /* @4934356 cast */
    /* @4934360 load */
    /* @4934368 constant */
    /* @4934372 add */
    /* @4934376 constant */
    /* @4934380 cast */
    /* @4934384 constant */
    /* @4934388 cast */
    /* @4934392 call */
    GM_SITE(vm, 618, 4934392);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4934400 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v25, v26, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4934404 constant */
    /* @4934408 cast */
    /* @4934412 constant */
    /* @4934416 cast */
    /* @4934420 constant */
    /* @4934424 cast */
    /* @4934428 constant */
    /* @4934432 cast */
    /* @4934436 constant */
    /* @4934440 cast */
    /* @4934444 constant */
    /* @4934448 load */
    /* @4934456 cast */
    /* @4934460 load */
    /* @4934468 constant */
    /* @4934472 add */
    /* @4934476 constant */
    /* @4934480 load */
    /* @4934488 cast */
    /* @4934492 load */
    /* @4934500 constant */
    /* @4934504 add */
    /* @4934508 constant */
    /* @4934512 cast */
    /* @4934516 constant */
    /* @4934520 cast */
    /* @4934524 call */
    GM_SITE(vm, 618, 4934524);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(380));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4934532 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v27, v28, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4934536 load */
    /* @4934544 constant */
    /* @4934548 cmp */
    /* @4934552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4934672;
    /* @4934556 constant */
    /* @4934560 cast */
    /* @4934564 call */
    GM_SITE(vm, 618, 4934564);
    /* @4934572 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4934576 constant */
    /* @4934584 cast */
    /* @4934588 call */
    GM_SITE(vm, 618, 4934588);
    /* @4934596 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4934600 string */
    /* @4934608 cast */
    /* @4934612 constant */
    /* @4934616 constant */
    /* @4934620 load */
    /* @4934628 constant */
    /* @4934632 add */
    /* @4934636 constant */
    /* @4934640 constant */
    /* @4934644 load */
    /* @4934652 constant */
    /* @4934656 add */
    /* @4934660 call */
    GM_SITE(vm, 618, 4934660);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(150));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(200));
    /* @4934668 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v29, v30, STR_REF(743)));
    L_4934672: ;
    /* @4934672 load */
    /* @4934680 constant */
    /* @4934684 cmp */
    /* @4934688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4935216;
    /* @4934692 constant */
    /* @4934696 cast */
    /* @4934700 constant */
    /* @4934704 cast */
    /* @4934708 constant */
    /* @4934712 cast */
    /* @4934716 constant */
    /* @4934728 cast */
    /* @4934732 constant */
    /* @4934744 cast */
    /* @4934748 constant */
    /* @4934752 constant */
    /* @4934756 load */
    /* @4934764 constant */
    /* @4934768 constant */
    /* @4934772 load */
    /* @4934780 constant */
    /* @4934784 sub */
    /* @4934788 constant */
    /* @4934792 cast */
    /* @4934796 constant */
    /* @4934800 cast */
    /* @4934804 call */
    GM_SITE(vm, 618, 4934804);
    /* @4934812 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(123), VAL(1), (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(1)), GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(1.06), VAL(0.86), VAL(0), VAL(-1), VAL(1)));
    /* @4934816 constant */
    /* @4934820 cast */
    /* @4934824 constant */
    /* @4934828 cast */
    /* @4934832 constant */
    /* @4934836 cast */
    /* @4934840 constant */
    /* @4934844 cast */
    /* @4934848 constant */
    /* @4934852 cast */
    /* @4934856 constant */
    /* @4934860 load */
    /* @4934868 cast */
    /* @4934872 load */
    /* @4934880 constant */
    /* @4934884 add */
    /* @4934888 constant */
    /* @4934892 load */
    /* @4934900 cast */
    /* @4934904 load */
    /* @4934912 constant */
    /* @4934916 add */
    /* @4934920 constant */
    /* @4934924 cast */
    /* @4934928 constant */
    /* @4934932 cast */
    /* @4934936 call */
    GM_SITE(vm, 618, 4934936);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4934944 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(1), VAL(-3), v31, v32, VAL(2), VAL(2), VAL(0), VAL(-1), VAL(1)));
    /* @4934948 constant */
    /* @4934952 cast */
    /* @4934956 constant */
    /* @4934960 cast */
    /* @4934964 constant */
    /* @4934968 cast */
    /* @4934972 constant */
    /* @4934976 cast */
    /* @4934980 constant */
    /* @4934984 cast */
    /* @4934988 constant */
    /* @4934992 load */
    /* @4935000 cast */
    /* @4935004 load */
    /* @4935012 constant */
    /* @4935016 add */
    /* @4935020 constant */
    /* @4935024 load */
    /* @4935032 cast */
    /* @4935036 load */
    /* @4935044 constant */
    /* @4935048 add */
    /* @4935052 constant */
    /* @4935056 cast */
    /* @4935060 constant */
    /* @4935064 cast */
    /* @4935068 call */
    GM_SITE(vm, 618, 4935068);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(390));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(180));
    /* @4935076 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(29), VAL(-3), v33, v34, VAL(-2), VAL(2), VAL(1), VAL(-1), VAL(1)));
    /* @4935080 load */
    /* @4935088 constant */
    /* @4935092 cmp */
    /* @4935096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4935216;
    /* @4935100 constant */
    /* @4935104 cast */
    /* @4935108 call */
    GM_SITE(vm, 618, 4935108);
    /* @4935116 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(0)));
    /* @4935120 constant */
    /* @4935128 cast */
    /* @4935132 call */
    GM_SITE(vm, 618, 4935132);
    /* @4935140 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4935144 string */
    /* @4935152 cast */
    /* @4935156 constant */
    /* @4935160 constant */
    /* @4935164 load */
    /* @4935172 constant */
    /* @4935176 add */
    /* @4935180 constant */
    /* @4935184 constant */
    /* @4935188 load */
    /* @4935196 constant */
    /* @4935200 add */
    /* @4935204 call */
    GM_SITE(vm, 618, 4935204);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(160));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(200));
    /* @4935212 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v35, v36, STR_REF(743)));
    L_4935216: ;
    /* @4935216 load */
    /* @4935224 constant */
    /* @4935228 cmp */
    /* @4935232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel1") == VAL(1)))) goto L_4936676;
    /* @4935236 load */
    /* @4935244 constant */
    /* @4935248 cmp */
    /* @4935252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4935476;
    /* @4935256 constant */
    /* @4935260 cast */
    /* @4935264 call */
    GM_SITE(vm, 618, 4935264);
    /* @4935272 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4935276 constant */
    /* @4935284 cast */
    /* @4935288 call */
    GM_SITE(vm, 618, 4935288);
    /* @4935296 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4935300 string */
    /* @4935308 cast */
    /* @4935312 constant */
    /* @4935316 load */
    /* @4935324 cast */
    /* @4935328 load */
    /* @4935336 constant */
    /* @4935340 add */
    /* @4935344 constant */
    /* @4935348 load */
    /* @4935356 cast */
    /* @4935360 load */
    /* @4935368 constant */
    /* @4935372 add */
    /* @4935376 call */
    GM_SITE(vm, 618, 4935376);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4935384 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v37, v38, STR_REF(1102)));
    /* @4935388 string */
    /* @4935396 cast */
    /* @4935400 constant */
    /* @4935404 load */
    /* @4935412 cast */
    /* @4935416 load */
    /* @4935424 constant */
    /* @4935428 add */
    /* @4935432 constant */
    /* @4935436 load */
    /* @4935444 cast */
    /* @4935448 load */
    /* @4935456 constant */
    /* @4935460 add */
    /* @4935464 call */
    GM_SITE(vm, 618, 4935464);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4935472 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v39, v40, STR_REF(1103)));
    L_4935476: ;
    /* @4935476 load */
    /* @4935484 constant */
    /* @4935488 cmp */
    /* @4935492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4935716;
    /* @4935496 constant */
    /* @4935500 cast */
    /* @4935504 call */
    GM_SITE(vm, 618, 4935504);
    /* @4935512 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4935516 constant */
    /* @4935524 cast */
    /* @4935528 call */
    GM_SITE(vm, 618, 4935528);
    /* @4935536 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4935540 string */
    /* @4935548 cast */
    /* @4935552 constant */
    /* @4935556 load */
    /* @4935564 cast */
    /* @4935568 load */
    /* @4935576 constant */
    /* @4935580 add */
    /* @4935584 constant */
    /* @4935588 load */
    /* @4935596 cast */
    /* @4935600 load */
    /* @4935608 constant */
    /* @4935612 add */
    /* @4935616 call */
    GM_SITE(vm, 618, 4935616);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4935624 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v41, v42, STR_REF(1102)));
    /* @4935628 string */
    /* @4935636 cast */
    /* @4935640 constant */
    /* @4935644 load */
    /* @4935652 cast */
    /* @4935656 load */
    /* @4935664 constant */
    /* @4935668 add */
    /* @4935672 constant */
    /* @4935676 load */
    /* @4935684 cast */
    /* @4935688 load */
    /* @4935696 constant */
    /* @4935700 add */
    /* @4935704 call */
    GM_SITE(vm, 618, 4935704);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4935712 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v43, v44, STR_REF(1103)));
    L_4935716: ;
    /* @4935716 load */
    /* @4935724 constant */
    /* @4935728 cmp */
    /* @4935732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4935956;
    /* @4935736 constant */
    /* @4935740 cast */
    /* @4935744 call */
    GM_SITE(vm, 618, 4935744);
    /* @4935752 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4935756 constant */
    /* @4935764 cast */
    /* @4935768 call */
    GM_SITE(vm, 618, 4935768);
    /* @4935776 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4935780 string */
    /* @4935788 cast */
    /* @4935792 constant */
    /* @4935796 load */
    /* @4935804 cast */
    /* @4935808 load */
    /* @4935816 constant */
    /* @4935820 add */
    /* @4935824 constant */
    /* @4935828 load */
    /* @4935836 cast */
    /* @4935840 load */
    /* @4935848 constant */
    /* @4935852 add */
    /* @4935856 call */
    GM_SITE(vm, 618, 4935856);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4935864 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v45, v46, STR_REF(1102)));
    /* @4935868 string */
    /* @4935876 cast */
    /* @4935880 constant */
    /* @4935884 load */
    /* @4935892 cast */
    /* @4935896 load */
    /* @4935904 constant */
    /* @4935908 add */
    /* @4935912 constant */
    /* @4935916 load */
    /* @4935924 cast */
    /* @4935928 load */
    /* @4935936 constant */
    /* @4935940 add */
    /* @4935944 call */
    GM_SITE(vm, 618, 4935944);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4935952 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v47, v48, STR_REF(1103)));
    L_4935956: ;
    /* @4935956 load */
    /* @4935964 constant */
    /* @4935968 cmp */
    /* @4935972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4936196;
    /* @4935976 constant */
    /* @4935980 cast */
    /* @4935984 call */
    GM_SITE(vm, 618, 4935984);
    /* @4935992 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4935996 constant */
    /* @4936004 cast */
    /* @4936008 call */
    GM_SITE(vm, 618, 4936008);
    /* @4936016 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4936020 string */
    /* @4936028 cast */
    /* @4936032 constant */
    /* @4936036 load */
    /* @4936044 cast */
    /* @4936048 load */
    /* @4936056 constant */
    /* @4936060 add */
    /* @4936064 constant */
    /* @4936068 load */
    /* @4936076 cast */
    /* @4936080 load */
    /* @4936088 constant */
    /* @4936092 add */
    /* @4936096 call */
    GM_SITE(vm, 618, 4936096);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4936104 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v49, v50, STR_REF(1102)));
    /* @4936108 string */
    /* @4936116 cast */
    /* @4936120 constant */
    /* @4936124 load */
    /* @4936132 cast */
    /* @4936136 load */
    /* @4936144 constant */
    /* @4936148 add */
    /* @4936152 constant */
    /* @4936156 load */
    /* @4936164 cast */
    /* @4936168 load */
    /* @4936176 constant */
    /* @4936180 add */
    /* @4936184 call */
    GM_SITE(vm, 618, 4936184);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4936192 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v51, v52, STR_REF(1103)));
    L_4936196: ;
    /* @4936196 load */
    /* @4936204 constant */
    /* @4936208 cmp */
    /* @4936212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4936436;
    /* @4936216 constant */
    /* @4936220 cast */
    /* @4936224 call */
    GM_SITE(vm, 618, 4936224);
    /* @4936232 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4936236 constant */
    /* @4936244 cast */
    /* @4936248 call */
    GM_SITE(vm, 618, 4936248);
    /* @4936256 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4936260 string */
    /* @4936268 cast */
    /* @4936272 constant */
    /* @4936276 load */
    /* @4936284 cast */
    /* @4936288 load */
    /* @4936296 constant */
    /* @4936300 add */
    /* @4936304 constant */
    /* @4936308 load */
    /* @4936316 cast */
    /* @4936320 load */
    /* @4936328 constant */
    /* @4936332 add */
    /* @4936336 call */
    GM_SITE(vm, 618, 4936336);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4936344 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v53, v54, STR_REF(1102)));
    /* @4936348 string */
    /* @4936356 cast */
    /* @4936360 constant */
    /* @4936364 load */
    /* @4936372 cast */
    /* @4936376 load */
    /* @4936384 constant */
    /* @4936388 add */
    /* @4936392 constant */
    /* @4936396 load */
    /* @4936404 cast */
    /* @4936408 load */
    /* @4936416 constant */
    /* @4936420 add */
    /* @4936424 call */
    GM_SITE(vm, 618, 4936424);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4936432 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v55, v56, STR_REF(1103)));
    L_4936436: ;
    /* @4936436 load */
    /* @4936444 constant */
    /* @4936448 cmp */
    /* @4936452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4936676;
    /* @4936456 constant */
    /* @4936460 cast */
    /* @4936464 call */
    GM_SITE(vm, 618, 4936464);
    /* @4936472 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4936476 constant */
    /* @4936484 cast */
    /* @4936488 call */
    GM_SITE(vm, 618, 4936488);
    /* @4936496 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4936500 string */
    /* @4936508 cast */
    /* @4936512 constant */
    /* @4936516 load */
    /* @4936524 cast */
    /* @4936528 load */
    /* @4936536 constant */
    /* @4936540 add */
    /* @4936544 constant */
    /* @4936548 load */
    /* @4936556 cast */
    /* @4936560 load */
    /* @4936568 constant */
    /* @4936572 add */
    /* @4936576 call */
    GM_SITE(vm, 618, 4936576);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4936584 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v57, v58, STR_REF(1102)));
    /* @4936588 string */
    /* @4936596 cast */
    /* @4936600 constant */
    /* @4936604 load */
    /* @4936612 cast */
    /* @4936616 load */
    /* @4936624 constant */
    /* @4936628 add */
    /* @4936632 constant */
    /* @4936636 load */
    /* @4936644 cast */
    /* @4936648 load */
    /* @4936656 constant */
    /* @4936660 add */
    /* @4936664 call */
    GM_SITE(vm, 618, 4936664);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4936672 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v59, v60, STR_REF(1103)));
    L_4936676: ;
    /* @4936676 load */
    /* @4936684 constant */
    /* @4936688 cmp */
    /* @4936692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "drawpanel2") == VAL(1)))) goto L_4938136;
    /* @4936696 load */
    /* @4936704 constant */
    /* @4936708 cmp */
    /* @4936712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4936936;
    /* @4936716 constant */
    /* @4936720 cast */
    /* @4936724 call */
    GM_SITE(vm, 618, 4936724);
    /* @4936732 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4936736 constant */
    /* @4936744 cast */
    /* @4936748 call */
    GM_SITE(vm, 618, 4936748);
    /* @4936756 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4936760 string */
    /* @4936768 cast */
    /* @4936772 constant */
    /* @4936776 load */
    /* @4936784 cast */
    /* @4936788 load */
    /* @4936796 constant */
    /* @4936800 add */
    /* @4936804 constant */
    /* @4936808 load */
    /* @4936816 cast */
    /* @4936820 load */
    /* @4936828 constant */
    /* @4936832 add */
    /* @4936836 call */
    GM_SITE(vm, 618, 4936836);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4936844 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v61, v62, STR_REF(1104)));
    /* @4936848 string */
    /* @4936856 cast */
    /* @4936860 constant */
    /* @4936864 load */
    /* @4936872 cast */
    /* @4936876 load */
    /* @4936884 constant */
    /* @4936888 add */
    /* @4936892 constant */
    /* @4936896 load */
    /* @4936904 cast */
    /* @4936908 load */
    /* @4936916 constant */
    /* @4936920 add */
    /* @4936924 call */
    GM_SITE(vm, 618, 4936924);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4936932 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v63, v64, STR_REF(1105)));
    L_4936936: ;
    /* @4936936 load */
    /* @4936944 constant */
    /* @4936948 cmp */
    /* @4936952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4937176;
    /* @4936956 constant */
    /* @4936960 cast */
    /* @4936964 call */
    GM_SITE(vm, 618, 4936964);
    /* @4936972 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4936976 constant */
    /* @4936984 cast */
    /* @4936988 call */
    GM_SITE(vm, 618, 4936988);
    /* @4936996 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4937000 string */
    /* @4937008 cast */
    /* @4937012 constant */
    /* @4937016 load */
    /* @4937024 cast */
    /* @4937028 load */
    /* @4937036 constant */
    /* @4937040 add */
    /* @4937044 constant */
    /* @4937048 load */
    /* @4937056 cast */
    /* @4937060 load */
    /* @4937068 constant */
    /* @4937072 add */
    /* @4937076 call */
    GM_SITE(vm, 618, 4937076);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4937084 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v65, v66, STR_REF(1104)));
    /* @4937088 string */
    /* @4937096 cast */
    /* @4937100 constant */
    /* @4937104 load */
    /* @4937112 cast */
    /* @4937116 load */
    /* @4937124 constant */
    /* @4937128 add */
    /* @4937132 constant */
    /* @4937136 load */
    /* @4937144 cast */
    /* @4937148 load */
    /* @4937156 constant */
    /* @4937160 add */
    /* @4937164 call */
    GM_SITE(vm, 618, 4937164);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4937172 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v67, v68, STR_REF(1105)));
    L_4937176: ;
    /* @4937176 load */
    /* @4937184 constant */
    /* @4937188 cmp */
    /* @4937192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4937416;
    /* @4937196 constant */
    /* @4937200 cast */
    /* @4937204 call */
    GM_SITE(vm, 618, 4937204);
    /* @4937212 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4937216 constant */
    /* @4937224 cast */
    /* @4937228 call */
    GM_SITE(vm, 618, 4937228);
    /* @4937236 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4937240 string */
    /* @4937248 cast */
    /* @4937252 constant */
    /* @4937256 load */
    /* @4937264 cast */
    /* @4937268 load */
    /* @4937276 constant */
    /* @4937280 add */
    /* @4937284 constant */
    /* @4937288 load */
    /* @4937296 cast */
    /* @4937300 load */
    /* @4937308 constant */
    /* @4937312 add */
    /* @4937316 call */
    GM_SITE(vm, 618, 4937316);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4937324 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v69, v70, STR_REF(1104)));
    /* @4937328 string */
    /* @4937336 cast */
    /* @4937340 constant */
    /* @4937344 load */
    /* @4937352 cast */
    /* @4937356 load */
    /* @4937364 constant */
    /* @4937368 add */
    /* @4937372 constant */
    /* @4937376 load */
    /* @4937384 cast */
    /* @4937388 load */
    /* @4937396 constant */
    /* @4937400 add */
    /* @4937404 call */
    GM_SITE(vm, 618, 4937404);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4937412 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v71, v72, STR_REF(1105)));
    L_4937416: ;
    /* @4937416 load */
    /* @4937424 constant */
    /* @4937428 cmp */
    /* @4937432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4937656;
    /* @4937436 constant */
    /* @4937440 cast */
    /* @4937444 call */
    GM_SITE(vm, 618, 4937444);
    /* @4937452 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(1)));
    /* @4937456 constant */
    /* @4937464 cast */
    /* @4937468 call */
    GM_SITE(vm, 618, 4937468);
    /* @4937476 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4937480 string */
    /* @4937488 cast */
    /* @4937492 constant */
    /* @4937496 load */
    /* @4937504 cast */
    /* @4937508 load */
    /* @4937516 constant */
    /* @4937520 add */
    /* @4937524 constant */
    /* @4937528 load */
    /* @4937536 cast */
    /* @4937540 load */
    /* @4937548 constant */
    /* @4937552 add */
    /* @4937556 call */
    GM_SITE(vm, 618, 4937556);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(80));
    /* @4937564 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v73, v74, STR_REF(1104)));
    /* @4937568 string */
    /* @4937576 cast */
    /* @4937580 constant */
    /* @4937584 load */
    /* @4937592 cast */
    /* @4937596 load */
    /* @4937604 constant */
    /* @4937608 add */
    /* @4937612 constant */
    /* @4937616 load */
    /* @4937624 cast */
    /* @4937628 load */
    /* @4937636 constant */
    /* @4937640 add */
    /* @4937644 call */
    GM_SITE(vm, 618, 4937644);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(130));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    /* @4937652 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v75, v76, STR_REF(1105)));
    L_4937656: ;
    /* @4937656 load */
    /* @4937664 constant */
    /* @4937668 cmp */
    /* @4937672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4937896;
    /* @4937676 constant */
    /* @4937680 cast */
    /* @4937684 call */
    GM_SITE(vm, 618, 4937684);
    /* @4937692 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4937696 constant */
    /* @4937704 cast */
    /* @4937708 call */
    GM_SITE(vm, 618, 4937708);
    /* @4937716 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4937720 string */
    /* @4937728 cast */
    /* @4937732 constant */
    /* @4937736 load */
    /* @4937744 cast */
    /* @4937748 load */
    /* @4937756 constant */
    /* @4937760 add */
    /* @4937764 constant */
    /* @4937768 load */
    /* @4937776 cast */
    /* @4937780 load */
    /* @4937788 constant */
    /* @4937792 add */
    /* @4937796 call */
    GM_SITE(vm, 618, 4937796);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4937804 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v77, v78, STR_REF(1104)));
    /* @4937808 string */
    /* @4937816 cast */
    /* @4937820 constant */
    /* @4937824 load */
    /* @4937832 cast */
    /* @4937836 load */
    /* @4937844 constant */
    /* @4937848 add */
    /* @4937852 constant */
    /* @4937856 load */
    /* @4937864 cast */
    /* @4937868 load */
    /* @4937876 constant */
    /* @4937880 add */
    /* @4937884 call */
    GM_SITE(vm, 618, 4937884);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4937892 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v79, v80, STR_REF(1105)));
    L_4937896: ;
    /* @4937896 load */
    /* @4937904 constant */
    /* @4937908 cmp */
    /* @4937912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4938136;
    /* @4937916 constant */
    /* @4937920 cast */
    /* @4937924 call */
    GM_SITE(vm, 618, 4937924);
    /* @4937932 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4937936 constant */
    /* @4937944 cast */
    /* @4937948 call */
    GM_SITE(vm, 618, 4937948);
    /* @4937956 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4937960 string */
    /* @4937968 cast */
    /* @4937972 constant */
    /* @4937976 load */
    /* @4937984 cast */
    /* @4937988 load */
    /* @4937996 constant */
    /* @4938000 add */
    /* @4938004 constant */
    /* @4938008 load */
    /* @4938016 cast */
    /* @4938020 load */
    /* @4938028 constant */
    /* @4938032 add */
    /* @4938036 call */
    GM_SITE(vm, 618, 4938036);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(50));
    /* @4938044 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v81, v82, STR_REF(1104)));
    /* @4938048 string */
    /* @4938056 cast */
    /* @4938060 constant */
    /* @4938064 load */
    /* @4938072 cast */
    /* @4938076 load */
    /* @4938084 constant */
    /* @4938088 add */
    /* @4938092 constant */
    /* @4938096 load */
    /* @4938104 cast */
    /* @4938108 load */
    /* @4938116 constant */
    /* @4938120 add */
    /* @4938124 call */
    GM_SITE(vm, 618, 4938124);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(100));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))), VAL(70));
    /* @4938132 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v83, v84, STR_REF(1105)));
    L_4938136: ;
    /* @4938136 load */
    /* @4938144 constant */
    /* @4938148 cmp */
    /* @4938152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4938188;
    /* @4938156 constant */
    /* @4938160 cast */
    /* @4938164 constant */
    /* @4938168 cast */
    /* @4938172 call */
    GM_SITE(vm, 618, 4938172);
    /* @4938180 cast */
    /* @4938184 b */
    v85 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, VAL(0), VAL(1)));
    p4938192_0 = v85;
    goto L_4938192;
    L_4938188: ;
    /* @4938188 constant */
    p4938192_0 = VAL(0);
    L_4938192: ;
    /* @4938192 bf */
    if (!TRUTH(p4938192_0)) goto L_4938208;
    /* @4938196 call */
    GM_SITE(vm, 618, 4938196);
    /* @4938204 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4938208: ;
    return;
}
