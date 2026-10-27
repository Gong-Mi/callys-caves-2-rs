/* generated from CODE 530 (gml_Object_obj_leftbutton_Draw_0), source start 4822200, end 4828160. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0530(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val p4822556_0;
    Val v6;
    Val p4822584_0;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val p4822848_0;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val p4823032_0;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val p4823288_0;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val p4823684_0;
    Val v29;
    Val p4823712_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p4824036_0;
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
    Val p4824580_0;
    Val v46;
    Val p4824608_0;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val p4824916_0;
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
    Val p4825424_0;
    Val v63;
    Val p4825452_0;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val p4825760_0;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val p4826276_0;
    Val v79;
    Val p4826304_0;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val p4826568_0;
    Val v84;
    Val v85;
    Val v86;
    Val v87;
    Val v88;
    Val p4826752_0;
    Val v89;
    Val v90;
    Val v91;
    Val v92;
    Val v93;
    Val p4827008_0;
    Val v94;
    Val v95;
    Val v96;
    Val v97;
    Val v98;
    Val v99;
    Val v100;
    Val p4827396_0;
    Val v101;
    Val p4827424_0;
    Val v102;
    Val v103;
    Val v104;
    Val v105;
    Val p4827688_0;
    Val v106;
    Val v107;
    Val v108;
    Val v109;
    Val v110;
    Val p4827872_0;
    Val v111;
    Val v112;
    Val v113;
    Val v114;
    Val v115;
    Val p4828128_0;
    Val v116;
    Val v117;
    /* @4822200 load */
    /* @4822208 constant */
    /* @4822212 cmp */
    /* @4822216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4823320;
    /* @4822220 constant */
    /* @4822232 cast */
    /* @4822236 constant */
    /* @4822240 cast */
    /* @4822244 constant */
    /* @4822248 cast */
    /* @4822252 constant */
    /* @4822264 cast */
    /* @4822268 constant */
    /* @4822280 cast */
    /* @4822284 constant */
    /* @4822288 constant */
    /* @4822292 load */
    /* @4822300 constant */
    /* @4822304 add */
    /* @4822308 constant */
    /* @4822312 constant */
    /* @4822316 load */
    /* @4822324 constant */
    /* @4822328 cast */
    /* @4822332 constant */
    /* @4822336 cast */
    /* @4822340 call */
    GM_SITE(vm, 530, 4822340);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4822348 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), v1, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4822352 constant */
    /* @4822356 constant */
    /* @4822360 load */
    /* @4822368 constant */
    /* @4822372 sub */
    /* @4822376 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)) - VAL(10)));
    /* @4822384 constant */
    /* @4822388 constant */
    /* @4822392 load */
    /* @4822400 constant */
    /* @4822404 add */
    /* @4822408 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    GM_WRITE(vm, -1, "y", v2);
    /* @4822416 constant */
    /* @4822420 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4822428: ;
    /* @4822428 load */
    /* @4822436 constant */
    /* @4822440 cmp */
    /* @4822444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4822892;
    /* @4822448 constant */
    /* @4822452 cast */
    /* @4822456 load */
    /* @4822464 call */
    GM_SITE(vm, 530, 4822464);
    /* @4822472 cast */
    /* @4822476 bf */
    v3 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v3)) goto L_4822552;
    /* @4822480 constant */
    /* @4822484 cast */
    /* @4822488 constant */
    /* @4822492 cast */
    /* @4822496 constant */
    /* @4822500 cast */
    /* @4822504 load */
    /* @4822512 call */
    GM_SITE(vm, 530, 4822512);
    /* @4822520 load */
    /* @4822528 call */
    GM_SITE(vm, 530, 4822528);
    /* @4822536 call */
    GM_SITE(vm, 530, 4822536);
    v4 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v5 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4822544 cast */
    /* @4822548 b */
    v6 = BOOL(GM_CALL(vm, "collision_point", 5, v4, v5, VAL(130), VAL(0), VAL(0)));
    p4822556_0 = v6;
    goto L_4822556;
    L_4822552: ;
    /* @4822552 constant */
    p4822556_0 = VAL(0);
    L_4822556: ;
    /* @4822556 bf */
    if (!TRUTH(p4822556_0)) goto L_4822580;
    /* @4822560 load */
    /* @4822568 constant */
    /* @4822572 cmp */
    /* @4822576 b */
    p4822584_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4822584;
    L_4822580: ;
    /* @4822580 constant */
    p4822584_0 = VAL(0);
    L_4822584: ;
    /* @4822584 bf */
    if (!TRUTH(p4822584_0)) goto L_4822736;
    /* @4822588 constant */
    /* @4822592 constant */
    /* @4822596 constant */
    /* @4822600 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4822608 constant */
    /* @4822612 cast */
    /* @4822616 constant */
    /* @4822620 cast */
    /* @4822624 constant */
    /* @4822628 cast */
    /* @4822632 constant */
    /* @4822644 cast */
    /* @4822648 constant */
    /* @4822660 cast */
    /* @4822664 constant */
    /* @4822668 constant */
    /* @4822672 load */
    /* @4822680 constant */
    /* @4822684 add */
    /* @4822688 constant */
    /* @4822692 constant */
    /* @4822696 load */
    /* @4822704 constant */
    /* @4822708 cast */
    /* @4822712 constant */
    /* @4822716 cast */
    /* @4822720 call */
    GM_SITE(vm, 530, 4822720);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4822728 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), v7, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4822732 b */
    goto L_4822864;
    L_4822736: ;
    /* @4822736 constant */
    /* @4822740 cast */
    /* @4822744 load */
    /* @4822752 call */
    GM_SITE(vm, 530, 4822752);
    /* @4822760 cast */
    /* @4822764 bf */
    v8 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v8)) goto L_4822844;
    /* @4822768 constant */
    /* @4822772 cast */
    /* @4822776 constant */
    /* @4822780 cast */
    /* @4822784 constant */
    /* @4822788 cast */
    /* @4822792 load */
    /* @4822800 call */
    GM_SITE(vm, 530, 4822800);
    /* @4822808 load */
    /* @4822816 call */
    GM_SITE(vm, 530, 4822816);
    /* @4822824 call */
    GM_SITE(vm, 530, 4822824);
    v9 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v10 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4822832 cast */
    /* @4822836 not */
    /* @4822840 b */
    v11 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v9, v10, VAL(130), VAL(0), VAL(0))));
    p4822848_0 = v11;
    goto L_4822848;
    L_4822844: ;
    /* @4822844 constant */
    p4822848_0 = VAL(0);
    L_4822848: ;
    /* @4822848 bf */
    if (!TRUTH(p4822848_0)) goto L_4822864;
    /* @4822852 constant */
    /* @4822856 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4822864: ;
    /* @4822864 load */
    /* @4822872 constant */
    /* @4822876 add */
    /* @4822880 store */
    v12 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v12);
    /* @4822888 b */
    goto L_4822428;
    L_4822892: ;
    /* @4822892 constant */
    /* @4822896 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4822904: ;
    /* @4822904 load */
    /* @4822912 constant */
    /* @4822916 cmp */
    /* @4822920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4823320;
    /* @4822924 constant */
    /* @4822928 cast */
    /* @4822932 load */
    /* @4822940 call */
    GM_SITE(vm, 530, 4822940);
    /* @4822948 cast */
    /* @4822952 bf */
    v13 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v13)) goto L_4823028;
    /* @4822956 constant */
    /* @4822960 cast */
    /* @4822964 constant */
    /* @4822968 cast */
    /* @4822972 constant */
    /* @4822976 cast */
    /* @4822980 load */
    /* @4822988 call */
    GM_SITE(vm, 530, 4822988);
    /* @4822996 load */
    /* @4823004 call */
    GM_SITE(vm, 530, 4823004);
    /* @4823012 call */
    GM_SITE(vm, 530, 4823012);
    v14 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v15 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4823020 cast */
    /* @4823024 b */
    v16 = BOOL(GM_CALL(vm, "collision_point", 5, v14, v15, VAL(130), VAL(0), VAL(0)));
    p4823032_0 = v16;
    goto L_4823032;
    L_4823028: ;
    /* @4823028 constant */
    p4823032_0 = VAL(0);
    L_4823032: ;
    /* @4823032 bf */
    if (!TRUTH(p4823032_0)) goto L_4823176;
    /* @4823036 constant */
    /* @4823040 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4823048 constant */
    /* @4823052 cast */
    /* @4823056 constant */
    /* @4823060 cast */
    /* @4823064 constant */
    /* @4823068 cast */
    /* @4823072 constant */
    /* @4823084 cast */
    /* @4823088 constant */
    /* @4823100 cast */
    /* @4823104 constant */
    /* @4823108 constant */
    /* @4823112 load */
    /* @4823120 constant */
    /* @4823124 add */
    /* @4823128 constant */
    /* @4823132 constant */
    /* @4823136 load */
    /* @4823144 constant */
    /* @4823148 cast */
    /* @4823152 constant */
    /* @4823156 cast */
    /* @4823160 call */
    GM_SITE(vm, 530, 4823160);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4823168 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), v17, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4823172 b */
    goto L_4823292;
    L_4823176: ;
    /* @4823176 constant */
    /* @4823180 cast */
    /* @4823184 load */
    /* @4823192 call */
    GM_SITE(vm, 530, 4823192);
    /* @4823200 cast */
    /* @4823204 bf */
    v18 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v18)) goto L_4823284;
    /* @4823208 constant */
    /* @4823212 cast */
    /* @4823216 constant */
    /* @4823220 cast */
    /* @4823224 constant */
    /* @4823228 cast */
    /* @4823232 load */
    /* @4823240 call */
    GM_SITE(vm, 530, 4823240);
    /* @4823248 load */
    /* @4823256 call */
    GM_SITE(vm, 530, 4823256);
    /* @4823264 call */
    GM_SITE(vm, 530, 4823264);
    v19 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v20 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4823272 cast */
    /* @4823276 not */
    /* @4823280 b */
    v21 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v19, v20, VAL(130), VAL(0), VAL(0))));
    p4823288_0 = v21;
    goto L_4823288;
    L_4823284: ;
    /* @4823284 constant */
    p4823288_0 = VAL(0);
    L_4823288: ;
    /* @4823288 bf */
    if (!TRUTH(p4823288_0)) goto L_4823292;
    L_4823292: ;
    /* @4823292 load */
    /* @4823300 constant */
    /* @4823304 add */
    /* @4823308 store */
    v22 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v22);
    /* @4823316 b */
    goto L_4822904;
    L_4823320: ;
    /* @4823320 load */
    /* @4823328 constant */
    /* @4823332 cmp */
    /* @4823336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4824212;
    /* @4823340 constant */
    /* @4823352 cast */
    /* @4823356 constant */
    /* @4823360 cast */
    /* @4823364 constant */
    /* @4823368 cast */
    /* @4823372 constant */
    /* @4823384 cast */
    /* @4823388 constant */
    /* @4823400 cast */
    /* @4823404 constant */
    /* @4823408 constant */
    /* @4823412 load */
    /* @4823420 constant */
    /* @4823424 add */
    /* @4823428 constant */
    /* @4823432 constant */
    /* @4823436 load */
    /* @4823444 constant */
    /* @4823448 add */
    /* @4823452 constant */
    /* @4823456 cast */
    /* @4823460 constant */
    /* @4823464 cast */
    /* @4823468 call */
    GM_SITE(vm, 530, 4823468);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(2));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4823476 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v23, v24, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(0.6)));
    /* @4823480 constant */
    /* @4823484 constant */
    /* @4823488 load */
    /* @4823496 constant */
    /* @4823500 sub */
    /* @4823504 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)) - VAL(21)));
    /* @4823512 constant */
    /* @4823516 constant */
    /* @4823520 load */
    /* @4823528 constant */
    /* @4823532 add */
    /* @4823536 store */
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    GM_WRITE(vm, -1, "y", v25);
    /* @4823544 constant */
    /* @4823548 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4823556: ;
    /* @4823556 load */
    /* @4823564 constant */
    /* @4823568 cmp */
    /* @4823572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4823896;
    /* @4823576 constant */
    /* @4823580 cast */
    /* @4823584 load */
    /* @4823592 call */
    GM_SITE(vm, 530, 4823592);
    /* @4823600 cast */
    /* @4823604 bf */
    v26 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v26)) goto L_4823680;
    /* @4823608 constant */
    /* @4823612 cast */
    /* @4823616 constant */
    /* @4823620 cast */
    /* @4823624 constant */
    /* @4823628 cast */
    /* @4823632 load */
    /* @4823640 call */
    GM_SITE(vm, 530, 4823640);
    /* @4823648 load */
    /* @4823656 call */
    GM_SITE(vm, 530, 4823656);
    /* @4823664 call */
    GM_SITE(vm, 530, 4823664);
    v27 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v28 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4823672 cast */
    /* @4823676 b */
    v29 = BOOL(GM_CALL(vm, "collision_point", 5, v27, v28, VAL(130), VAL(0), VAL(0)));
    p4823684_0 = v29;
    goto L_4823684;
    L_4823680: ;
    /* @4823680 constant */
    p4823684_0 = VAL(0);
    L_4823684: ;
    /* @4823684 bf */
    if (!TRUTH(p4823684_0)) goto L_4823708;
    /* @4823688 load */
    /* @4823696 constant */
    /* @4823700 cmp */
    /* @4823704 b */
    p4823712_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4823712;
    L_4823708: ;
    /* @4823708 constant */
    p4823712_0 = VAL(0);
    L_4823712: ;
    /* @4823712 bf */
    if (!TRUTH(p4823712_0)) goto L_4823868;
    /* @4823716 constant */
    /* @4823720 constant */
    /* @4823724 constant */
    /* @4823728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4823736 constant */
    /* @4823740 cast */
    /* @4823744 constant */
    /* @4823748 cast */
    /* @4823752 constant */
    /* @4823756 cast */
    /* @4823760 constant */
    /* @4823772 cast */
    /* @4823776 constant */
    /* @4823788 cast */
    /* @4823792 constant */
    /* @4823796 constant */
    /* @4823800 load */
    /* @4823808 constant */
    /* @4823812 add */
    /* @4823816 constant */
    /* @4823820 constant */
    /* @4823824 load */
    /* @4823832 constant */
    /* @4823836 add */
    /* @4823840 constant */
    /* @4823844 cast */
    /* @4823848 constant */
    /* @4823852 cast */
    /* @4823856 call */
    GM_SITE(vm, 530, 4823856);
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(2));
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4823864 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), v30, v31, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4823868: ;
    /* @4823868 load */
    /* @4823876 constant */
    /* @4823880 add */
    /* @4823884 store */
    v32 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v32);
    /* @4823892 b */
    goto L_4823556;
    L_4823896: ;
    /* @4823896 constant */
    /* @4823900 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4823908: ;
    /* @4823908 load */
    /* @4823916 constant */
    /* @4823920 cmp */
    /* @4823924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4824212;
    /* @4823928 constant */
    /* @4823932 cast */
    /* @4823936 load */
    /* @4823944 call */
    GM_SITE(vm, 530, 4823944);
    /* @4823952 cast */
    /* @4823956 bf */
    v33 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v33)) goto L_4824032;
    /* @4823960 constant */
    /* @4823964 cast */
    /* @4823968 constant */
    /* @4823972 cast */
    /* @4823976 constant */
    /* @4823980 cast */
    /* @4823984 load */
    /* @4823992 call */
    GM_SITE(vm, 530, 4823992);
    /* @4824000 load */
    /* @4824008 call */
    GM_SITE(vm, 530, 4824008);
    /* @4824016 call */
    GM_SITE(vm, 530, 4824016);
    v34 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v35 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4824024 cast */
    /* @4824028 b */
    v36 = BOOL(GM_CALL(vm, "collision_point", 5, v34, v35, VAL(130), VAL(0), VAL(0)));
    p4824036_0 = v36;
    goto L_4824036;
    L_4824032: ;
    /* @4824032 constant */
    p4824036_0 = VAL(0);
    L_4824036: ;
    /* @4824036 bf */
    if (!TRUTH(p4824036_0)) goto L_4824184;
    /* @4824040 constant */
    /* @4824044 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4824052 constant */
    /* @4824056 cast */
    /* @4824060 constant */
    /* @4824064 cast */
    /* @4824068 constant */
    /* @4824072 cast */
    /* @4824076 constant */
    /* @4824088 cast */
    /* @4824092 constant */
    /* @4824104 cast */
    /* @4824108 constant */
    /* @4824112 constant */
    /* @4824116 load */
    /* @4824124 constant */
    /* @4824128 add */
    /* @4824132 constant */
    /* @4824136 constant */
    /* @4824140 load */
    /* @4824148 constant */
    /* @4824152 add */
    /* @4824156 constant */
    /* @4824160 cast */
    /* @4824164 constant */
    /* @4824168 cast */
    /* @4824172 call */
    GM_SITE(vm, 530, 4824172);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(2));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4824180 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v37, v38, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4824184: ;
    /* @4824184 load */
    /* @4824192 constant */
    /* @4824196 add */
    /* @4824200 store */
    v39 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v39);
    /* @4824208 b */
    goto L_4823908;
    L_4824212: ;
    /* @4824212 load */
    /* @4824220 constant */
    /* @4824224 cmp */
    /* @4824228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4824232;
    L_4824232: ;
    /* @4824232 load */
    /* @4824240 constant */
    /* @4824244 cmp */
    /* @4824248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4825076;
    /* @4824252 constant */
    /* @4824264 cast */
    /* @4824268 constant */
    /* @4824272 cast */
    /* @4824276 constant */
    /* @4824280 cast */
    /* @4824284 constant */
    /* @4824288 cast */
    /* @4824292 constant */
    /* @4824296 cast */
    /* @4824300 constant */
    /* @4824304 constant */
    /* @4824308 load */
    /* @4824316 constant */
    /* @4824320 add */
    /* @4824324 constant */
    /* @4824328 constant */
    /* @4824332 load */
    /* @4824340 constant */
    /* @4824344 add */
    /* @4824348 constant */
    /* @4824352 cast */
    /* @4824356 constant */
    /* @4824360 cast */
    /* @4824364 call */
    GM_SITE(vm, 530, 4824364);
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(2));
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4824372 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v40, v41, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4824376 constant */
    /* @4824380 constant */
    /* @4824384 load */
    /* @4824392 constant */
    /* @4824396 sub */
    /* @4824400 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)) - VAL(17)));
    /* @4824408 constant */
    /* @4824412 constant */
    /* @4824416 load */
    /* @4824424 constant */
    /* @4824428 add */
    /* @4824432 store */
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    GM_WRITE(vm, -1, "y", v42);
    /* @4824440 constant */
    /* @4824444 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4824452: ;
    /* @4824452 load */
    /* @4824460 constant */
    /* @4824464 cmp */
    /* @4824468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4824776;
    /* @4824472 constant */
    /* @4824476 cast */
    /* @4824480 load */
    /* @4824488 call */
    GM_SITE(vm, 530, 4824488);
    /* @4824496 cast */
    /* @4824500 bf */
    v43 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v43)) goto L_4824576;
    /* @4824504 constant */
    /* @4824508 cast */
    /* @4824512 constant */
    /* @4824516 cast */
    /* @4824520 constant */
    /* @4824524 cast */
    /* @4824528 load */
    /* @4824536 call */
    GM_SITE(vm, 530, 4824536);
    /* @4824544 load */
    /* @4824552 call */
    GM_SITE(vm, 530, 4824552);
    /* @4824560 call */
    GM_SITE(vm, 530, 4824560);
    v44 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v45 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4824568 cast */
    /* @4824572 b */
    v46 = BOOL(GM_CALL(vm, "collision_point", 5, v44, v45, VAL(130), VAL(0), VAL(0)));
    p4824580_0 = v46;
    goto L_4824580;
    L_4824576: ;
    /* @4824576 constant */
    p4824580_0 = VAL(0);
    L_4824580: ;
    /* @4824580 bf */
    if (!TRUTH(p4824580_0)) goto L_4824604;
    /* @4824584 load */
    /* @4824592 constant */
    /* @4824596 cmp */
    /* @4824600 b */
    p4824608_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4824608;
    L_4824604: ;
    /* @4824604 constant */
    p4824608_0 = VAL(0);
    L_4824608: ;
    /* @4824608 bf */
    if (!TRUTH(p4824608_0)) goto L_4824748;
    /* @4824612 constant */
    /* @4824616 constant */
    /* @4824620 constant */
    /* @4824624 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4824632 constant */
    /* @4824636 cast */
    /* @4824640 constant */
    /* @4824644 cast */
    /* @4824648 constant */
    /* @4824652 cast */
    /* @4824656 constant */
    /* @4824660 cast */
    /* @4824664 constant */
    /* @4824668 cast */
    /* @4824672 constant */
    /* @4824676 constant */
    /* @4824680 load */
    /* @4824688 constant */
    /* @4824692 add */
    /* @4824696 constant */
    /* @4824700 constant */
    /* @4824704 load */
    /* @4824712 constant */
    /* @4824716 add */
    /* @4824720 constant */
    /* @4824724 cast */
    /* @4824728 constant */
    /* @4824732 cast */
    /* @4824736 call */
    GM_SITE(vm, 530, 4824736);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(2));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4824744 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), v47, v48, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4824748: ;
    /* @4824748 load */
    /* @4824756 constant */
    /* @4824760 add */
    /* @4824764 store */
    v49 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v49);
    /* @4824772 b */
    goto L_4824452;
    L_4824776: ;
    /* @4824776 constant */
    /* @4824780 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4824788: ;
    /* @4824788 load */
    /* @4824796 constant */
    /* @4824800 cmp */
    /* @4824804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4825076;
    /* @4824808 constant */
    /* @4824812 cast */
    /* @4824816 load */
    /* @4824824 call */
    GM_SITE(vm, 530, 4824824);
    /* @4824832 cast */
    /* @4824836 bf */
    v50 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v50)) goto L_4824912;
    /* @4824840 constant */
    /* @4824844 cast */
    /* @4824848 constant */
    /* @4824852 cast */
    /* @4824856 constant */
    /* @4824860 cast */
    /* @4824864 load */
    /* @4824872 call */
    GM_SITE(vm, 530, 4824872);
    /* @4824880 load */
    /* @4824888 call */
    GM_SITE(vm, 530, 4824888);
    /* @4824896 call */
    GM_SITE(vm, 530, 4824896);
    v51 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v52 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4824904 cast */
    /* @4824908 b */
    v53 = BOOL(GM_CALL(vm, "collision_point", 5, v51, v52, VAL(130), VAL(0), VAL(0)));
    p4824916_0 = v53;
    goto L_4824916;
    L_4824912: ;
    /* @4824912 constant */
    p4824916_0 = VAL(0);
    L_4824916: ;
    /* @4824916 bf */
    if (!TRUTH(p4824916_0)) goto L_4825048;
    /* @4824920 constant */
    /* @4824924 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4824932 constant */
    /* @4824936 cast */
    /* @4824940 constant */
    /* @4824944 cast */
    /* @4824948 constant */
    /* @4824952 cast */
    /* @4824956 constant */
    /* @4824960 cast */
    /* @4824964 constant */
    /* @4824968 cast */
    /* @4824972 constant */
    /* @4824976 constant */
    /* @4824980 load */
    /* @4824988 constant */
    /* @4824992 add */
    /* @4824996 constant */
    /* @4825000 constant */
    /* @4825004 load */
    /* @4825012 constant */
    /* @4825016 add */
    /* @4825020 constant */
    /* @4825024 cast */
    /* @4825028 constant */
    /* @4825032 cast */
    /* @4825036 call */
    GM_SITE(vm, 530, 4825036);
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(2));
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4825044 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v54, v55, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4825048: ;
    /* @4825048 load */
    /* @4825056 constant */
    /* @4825060 add */
    /* @4825064 store */
    v56 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v56);
    /* @4825072 b */
    goto L_4824788;
    L_4825076: ;
    /* @4825076 load */
    /* @4825084 constant */
    /* @4825088 cmp */
    /* @4825092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4825920;
    /* @4825096 constant */
    /* @4825108 cast */
    /* @4825112 constant */
    /* @4825116 cast */
    /* @4825120 constant */
    /* @4825124 cast */
    /* @4825128 constant */
    /* @4825132 cast */
    /* @4825136 constant */
    /* @4825140 cast */
    /* @4825144 constant */
    /* @4825148 constant */
    /* @4825152 load */
    /* @4825160 constant */
    /* @4825164 add */
    /* @4825168 constant */
    /* @4825172 constant */
    /* @4825176 load */
    /* @4825184 constant */
    /* @4825188 add */
    /* @4825192 constant */
    /* @4825196 cast */
    /* @4825200 constant */
    /* @4825204 cast */
    /* @4825208 call */
    GM_SITE(vm, 530, 4825208);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(2));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4825216 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v57, v58, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4825220 constant */
    /* @4825224 constant */
    /* @4825228 load */
    /* @4825236 constant */
    /* @4825240 sub */
    /* @4825244 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)) - VAL(17)));
    /* @4825252 constant */
    /* @4825256 constant */
    /* @4825260 load */
    /* @4825268 constant */
    /* @4825272 add */
    /* @4825276 store */
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    GM_WRITE(vm, -1, "y", v59);
    /* @4825284 constant */
    /* @4825288 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4825296: ;
    /* @4825296 load */
    /* @4825304 constant */
    /* @4825308 cmp */
    /* @4825312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4825620;
    /* @4825316 constant */
    /* @4825320 cast */
    /* @4825324 load */
    /* @4825332 call */
    GM_SITE(vm, 530, 4825332);
    /* @4825340 cast */
    /* @4825344 bf */
    v60 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v60)) goto L_4825420;
    /* @4825348 constant */
    /* @4825352 cast */
    /* @4825356 constant */
    /* @4825360 cast */
    /* @4825364 constant */
    /* @4825368 cast */
    /* @4825372 load */
    /* @4825380 call */
    GM_SITE(vm, 530, 4825380);
    /* @4825388 load */
    /* @4825396 call */
    GM_SITE(vm, 530, 4825396);
    /* @4825404 call */
    GM_SITE(vm, 530, 4825404);
    v61 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v62 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4825412 cast */
    /* @4825416 b */
    v63 = BOOL(GM_CALL(vm, "collision_point", 5, v61, v62, VAL(130), VAL(0), VAL(0)));
    p4825424_0 = v63;
    goto L_4825424;
    L_4825420: ;
    /* @4825420 constant */
    p4825424_0 = VAL(0);
    L_4825424: ;
    /* @4825424 bf */
    if (!TRUTH(p4825424_0)) goto L_4825448;
    /* @4825428 load */
    /* @4825436 constant */
    /* @4825440 cmp */
    /* @4825444 b */
    p4825452_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4825452;
    L_4825448: ;
    /* @4825448 constant */
    p4825452_0 = VAL(0);
    L_4825452: ;
    /* @4825452 bf */
    if (!TRUTH(p4825452_0)) goto L_4825592;
    /* @4825456 constant */
    /* @4825460 constant */
    /* @4825464 constant */
    /* @4825468 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4825476 constant */
    /* @4825480 cast */
    /* @4825484 constant */
    /* @4825488 cast */
    /* @4825492 constant */
    /* @4825496 cast */
    /* @4825500 constant */
    /* @4825504 cast */
    /* @4825508 constant */
    /* @4825512 cast */
    /* @4825516 constant */
    /* @4825520 constant */
    /* @4825524 load */
    /* @4825532 constant */
    /* @4825536 add */
    /* @4825540 constant */
    /* @4825544 constant */
    /* @4825548 load */
    /* @4825556 constant */
    /* @4825560 add */
    /* @4825564 constant */
    /* @4825568 cast */
    /* @4825572 constant */
    /* @4825576 cast */
    /* @4825580 call */
    GM_SITE(vm, 530, 4825580);
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(2));
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4825588 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), v64, v65, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4825592: ;
    /* @4825592 load */
    /* @4825600 constant */
    /* @4825604 add */
    /* @4825608 store */
    v66 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v66);
    /* @4825616 b */
    goto L_4825296;
    L_4825620: ;
    /* @4825620 constant */
    /* @4825624 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4825632: ;
    /* @4825632 load */
    /* @4825640 constant */
    /* @4825644 cmp */
    /* @4825648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4825920;
    /* @4825652 constant */
    /* @4825656 cast */
    /* @4825660 load */
    /* @4825668 call */
    GM_SITE(vm, 530, 4825668);
    /* @4825676 cast */
    /* @4825680 bf */
    v67 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v67)) goto L_4825756;
    /* @4825684 constant */
    /* @4825688 cast */
    /* @4825692 constant */
    /* @4825696 cast */
    /* @4825700 constant */
    /* @4825704 cast */
    /* @4825708 load */
    /* @4825716 call */
    GM_SITE(vm, 530, 4825716);
    /* @4825724 load */
    /* @4825732 call */
    GM_SITE(vm, 530, 4825732);
    /* @4825740 call */
    GM_SITE(vm, 530, 4825740);
    v68 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v69 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4825748 cast */
    /* @4825752 b */
    v70 = BOOL(GM_CALL(vm, "collision_point", 5, v68, v69, VAL(130), VAL(0), VAL(0)));
    p4825760_0 = v70;
    goto L_4825760;
    L_4825756: ;
    /* @4825756 constant */
    p4825760_0 = VAL(0);
    L_4825760: ;
    /* @4825760 bf */
    if (!TRUTH(p4825760_0)) goto L_4825892;
    /* @4825764 constant */
    /* @4825768 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4825776 constant */
    /* @4825780 cast */
    /* @4825784 constant */
    /* @4825788 cast */
    /* @4825792 constant */
    /* @4825796 cast */
    /* @4825800 constant */
    /* @4825804 cast */
    /* @4825808 constant */
    /* @4825812 cast */
    /* @4825816 constant */
    /* @4825820 constant */
    /* @4825824 load */
    /* @4825832 constant */
    /* @4825836 add */
    /* @4825840 constant */
    /* @4825844 constant */
    /* @4825848 load */
    /* @4825856 constant */
    /* @4825860 add */
    /* @4825864 constant */
    /* @4825868 cast */
    /* @4825872 constant */
    /* @4825876 cast */
    /* @4825880 call */
    GM_SITE(vm, 530, 4825880);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(2));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4825888 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), v71, v72, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4825892: ;
    /* @4825892 load */
    /* @4825900 constant */
    /* @4825904 add */
    /* @4825908 store */
    v73 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v73);
    /* @4825916 b */
    goto L_4825632;
    L_4825920: ;
    /* @4825920 load */
    /* @4825928 constant */
    /* @4825932 cmp */
    /* @4825936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4827040;
    /* @4825940 constant */
    /* @4825952 cast */
    /* @4825956 constant */
    /* @4825960 cast */
    /* @4825964 constant */
    /* @4825968 cast */
    /* @4825972 constant */
    /* @4825984 cast */
    /* @4825988 constant */
    /* @4826000 cast */
    /* @4826004 constant */
    /* @4826008 constant */
    /* @4826012 load */
    /* @4826020 constant */
    /* @4826024 add */
    /* @4826028 constant */
    /* @4826032 constant */
    /* @4826036 load */
    /* @4826044 constant */
    /* @4826048 cast */
    /* @4826052 constant */
    /* @4826056 cast */
    /* @4826060 call */
    GM_SITE(vm, 530, 4826060);
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4826068 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), v74, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4826072 constant */
    /* @4826076 constant */
    /* @4826080 load */
    /* @4826088 constant */
    /* @4826092 sub */
    /* @4826096 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)) - VAL(10)));
    /* @4826104 constant */
    /* @4826108 constant */
    /* @4826112 load */
    /* @4826120 constant */
    /* @4826124 add */
    /* @4826128 store */
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v75);
    /* @4826136 constant */
    /* @4826140 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4826148: ;
    /* @4826148 load */
    /* @4826156 constant */
    /* @4826160 cmp */
    /* @4826164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4826612;
    /* @4826168 constant */
    /* @4826172 cast */
    /* @4826176 load */
    /* @4826184 call */
    GM_SITE(vm, 530, 4826184);
    /* @4826192 cast */
    /* @4826196 bf */
    v76 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v76)) goto L_4826272;
    /* @4826200 constant */
    /* @4826204 cast */
    /* @4826208 constant */
    /* @4826212 cast */
    /* @4826216 constant */
    /* @4826220 cast */
    /* @4826224 load */
    /* @4826232 call */
    GM_SITE(vm, 530, 4826232);
    /* @4826240 load */
    /* @4826248 call */
    GM_SITE(vm, 530, 4826248);
    /* @4826256 call */
    GM_SITE(vm, 530, 4826256);
    v77 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v78 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4826264 cast */
    /* @4826268 b */
    v79 = BOOL(GM_CALL(vm, "collision_point", 5, v77, v78, VAL(130), VAL(0), VAL(0)));
    p4826276_0 = v79;
    goto L_4826276;
    L_4826272: ;
    /* @4826272 constant */
    p4826276_0 = VAL(0);
    L_4826276: ;
    /* @4826276 bf */
    if (!TRUTH(p4826276_0)) goto L_4826300;
    /* @4826280 load */
    /* @4826288 constant */
    /* @4826292 cmp */
    /* @4826296 b */
    p4826304_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4826304;
    L_4826300: ;
    /* @4826300 constant */
    p4826304_0 = VAL(0);
    L_4826304: ;
    /* @4826304 bf */
    if (!TRUTH(p4826304_0)) goto L_4826456;
    /* @4826308 constant */
    /* @4826312 constant */
    /* @4826316 constant */
    /* @4826320 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4826328 constant */
    /* @4826332 cast */
    /* @4826336 constant */
    /* @4826340 cast */
    /* @4826344 constant */
    /* @4826348 cast */
    /* @4826352 constant */
    /* @4826364 cast */
    /* @4826368 constant */
    /* @4826380 cast */
    /* @4826384 constant */
    /* @4826388 constant */
    /* @4826392 load */
    /* @4826400 constant */
    /* @4826404 add */
    /* @4826408 constant */
    /* @4826412 constant */
    /* @4826416 load */
    /* @4826424 constant */
    /* @4826428 cast */
    /* @4826432 constant */
    /* @4826436 cast */
    /* @4826440 call */
    GM_SITE(vm, 530, 4826440);
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4826448 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), v80, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4826452 b */
    goto L_4826584;
    L_4826456: ;
    /* @4826456 constant */
    /* @4826460 cast */
    /* @4826464 load */
    /* @4826472 call */
    GM_SITE(vm, 530, 4826472);
    /* @4826480 cast */
    /* @4826484 bf */
    v81 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v81)) goto L_4826564;
    /* @4826488 constant */
    /* @4826492 cast */
    /* @4826496 constant */
    /* @4826500 cast */
    /* @4826504 constant */
    /* @4826508 cast */
    /* @4826512 load */
    /* @4826520 call */
    GM_SITE(vm, 530, 4826520);
    /* @4826528 load */
    /* @4826536 call */
    GM_SITE(vm, 530, 4826536);
    /* @4826544 call */
    GM_SITE(vm, 530, 4826544);
    v82 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v83 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4826552 cast */
    /* @4826556 not */
    /* @4826560 b */
    v84 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v82, v83, VAL(130), VAL(0), VAL(0))));
    p4826568_0 = v84;
    goto L_4826568;
    L_4826564: ;
    /* @4826564 constant */
    p4826568_0 = VAL(0);
    L_4826568: ;
    /* @4826568 bf */
    if (!TRUTH(p4826568_0)) goto L_4826584;
    /* @4826572 constant */
    /* @4826576 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4826584: ;
    /* @4826584 load */
    /* @4826592 constant */
    /* @4826596 add */
    /* @4826600 store */
    v85 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v85);
    /* @4826608 b */
    goto L_4826148;
    L_4826612: ;
    /* @4826612 constant */
    /* @4826616 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4826624: ;
    /* @4826624 load */
    /* @4826632 constant */
    /* @4826636 cmp */
    /* @4826640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4827040;
    /* @4826644 constant */
    /* @4826648 cast */
    /* @4826652 load */
    /* @4826660 call */
    GM_SITE(vm, 530, 4826660);
    /* @4826668 cast */
    /* @4826672 bf */
    v86 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v86)) goto L_4826748;
    /* @4826676 constant */
    /* @4826680 cast */
    /* @4826684 constant */
    /* @4826688 cast */
    /* @4826692 constant */
    /* @4826696 cast */
    /* @4826700 load */
    /* @4826708 call */
    GM_SITE(vm, 530, 4826708);
    /* @4826716 load */
    /* @4826724 call */
    GM_SITE(vm, 530, 4826724);
    /* @4826732 call */
    GM_SITE(vm, 530, 4826732);
    v87 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v88 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4826740 cast */
    /* @4826744 b */
    v89 = BOOL(GM_CALL(vm, "collision_point", 5, v87, v88, VAL(130), VAL(0), VAL(0)));
    p4826752_0 = v89;
    goto L_4826752;
    L_4826748: ;
    /* @4826748 constant */
    p4826752_0 = VAL(0);
    L_4826752: ;
    /* @4826752 bf */
    if (!TRUTH(p4826752_0)) goto L_4826896;
    /* @4826756 constant */
    /* @4826760 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4826768 constant */
    /* @4826772 cast */
    /* @4826776 constant */
    /* @4826780 cast */
    /* @4826784 constant */
    /* @4826788 cast */
    /* @4826792 constant */
    /* @4826804 cast */
    /* @4826808 constant */
    /* @4826820 cast */
    /* @4826824 constant */
    /* @4826828 constant */
    /* @4826832 load */
    /* @4826840 constant */
    /* @4826844 add */
    /* @4826848 constant */
    /* @4826852 constant */
    /* @4826856 load */
    /* @4826864 constant */
    /* @4826868 cast */
    /* @4826872 constant */
    /* @4826876 cast */
    /* @4826880 call */
    GM_SITE(vm, 530, 4826880);
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4826888 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), v90, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4826892 b */
    goto L_4827012;
    L_4826896: ;
    /* @4826896 constant */
    /* @4826900 cast */
    /* @4826904 load */
    /* @4826912 call */
    GM_SITE(vm, 530, 4826912);
    /* @4826920 cast */
    /* @4826924 bf */
    v91 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v91)) goto L_4827004;
    /* @4826928 constant */
    /* @4826932 cast */
    /* @4826936 constant */
    /* @4826940 cast */
    /* @4826944 constant */
    /* @4826948 cast */
    /* @4826952 load */
    /* @4826960 call */
    GM_SITE(vm, 530, 4826960);
    /* @4826968 load */
    /* @4826976 call */
    GM_SITE(vm, 530, 4826976);
    /* @4826984 call */
    GM_SITE(vm, 530, 4826984);
    v92 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v93 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4826992 cast */
    /* @4826996 not */
    /* @4827000 b */
    v94 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v92, v93, VAL(130), VAL(0), VAL(0))));
    p4827008_0 = v94;
    goto L_4827008;
    L_4827004: ;
    /* @4827004 constant */
    p4827008_0 = VAL(0);
    L_4827008: ;
    /* @4827008 bf */
    if (!TRUTH(p4827008_0)) goto L_4827012;
    L_4827012: ;
    /* @4827012 load */
    /* @4827020 constant */
    /* @4827024 add */
    /* @4827028 store */
    v95 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v95);
    /* @4827036 b */
    goto L_4826624;
    L_4827040: ;
    /* @4827040 load */
    /* @4827048 constant */
    /* @4827052 cmp */
    /* @4827056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4828160;
    /* @4827060 constant */
    /* @4827072 cast */
    /* @4827076 constant */
    /* @4827080 cast */
    /* @4827084 constant */
    /* @4827088 cast */
    /* @4827092 constant */
    /* @4827104 cast */
    /* @4827108 constant */
    /* @4827120 cast */
    /* @4827124 constant */
    /* @4827128 constant */
    /* @4827132 load */
    /* @4827140 constant */
    /* @4827144 add */
    /* @4827148 constant */
    /* @4827152 constant */
    /* @4827156 load */
    /* @4827164 constant */
    /* @4827168 cast */
    /* @4827172 constant */
    /* @4827176 cast */
    /* @4827180 call */
    GM_SITE(vm, 530, 4827180);
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4827188 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), v96, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4827192 constant */
    /* @4827196 constant */
    /* @4827200 load */
    /* @4827208 constant */
    /* @4827212 sub */
    /* @4827216 store */
    GM_WRITE(vm, -1, "x", (GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)) - VAL(10)));
    /* @4827224 constant */
    /* @4827228 constant */
    /* @4827232 load */
    /* @4827240 constant */
    /* @4827244 add */
    /* @4827248 store */
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    GM_WRITE(vm, -1, "y", v97);
    /* @4827256 constant */
    /* @4827260 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4827268: ;
    /* @4827268 load */
    /* @4827276 constant */
    /* @4827280 cmp */
    /* @4827284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4827732;
    /* @4827288 constant */
    /* @4827292 cast */
    /* @4827296 load */
    /* @4827304 call */
    GM_SITE(vm, 530, 4827304);
    /* @4827312 cast */
    /* @4827316 bf */
    v98 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v98)) goto L_4827392;
    /* @4827320 constant */
    /* @4827324 cast */
    /* @4827328 constant */
    /* @4827332 cast */
    /* @4827336 constant */
    /* @4827340 cast */
    /* @4827344 load */
    /* @4827352 call */
    GM_SITE(vm, 530, 4827352);
    /* @4827360 load */
    /* @4827368 call */
    GM_SITE(vm, 530, 4827368);
    /* @4827376 call */
    GM_SITE(vm, 530, 4827376);
    v99 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v100 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4827384 cast */
    /* @4827388 b */
    v101 = BOOL(GM_CALL(vm, "collision_point", 5, v99, v100, VAL(130), VAL(0), VAL(0)));
    p4827396_0 = v101;
    goto L_4827396;
    L_4827392: ;
    /* @4827392 constant */
    p4827396_0 = VAL(0);
    L_4827396: ;
    /* @4827396 bf */
    if (!TRUTH(p4827396_0)) goto L_4827420;
    /* @4827400 load */
    /* @4827408 constant */
    /* @4827412 cmp */
    /* @4827416 b */
    p4827424_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4827424;
    L_4827420: ;
    /* @4827420 constant */
    p4827424_0 = VAL(0);
    L_4827424: ;
    /* @4827424 bf */
    if (!TRUTH(p4827424_0)) goto L_4827576;
    /* @4827428 constant */
    /* @4827432 constant */
    /* @4827436 constant */
    /* @4827440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4827448 constant */
    /* @4827452 cast */
    /* @4827456 constant */
    /* @4827460 cast */
    /* @4827464 constant */
    /* @4827468 cast */
    /* @4827472 constant */
    /* @4827484 cast */
    /* @4827488 constant */
    /* @4827500 cast */
    /* @4827504 constant */
    /* @4827508 constant */
    /* @4827512 load */
    /* @4827520 constant */
    /* @4827524 add */
    /* @4827528 constant */
    /* @4827532 constant */
    /* @4827536 load */
    /* @4827544 constant */
    /* @4827548 cast */
    /* @4827552 constant */
    /* @4827556 cast */
    /* @4827560 call */
    GM_SITE(vm, 530, 4827560);
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4827568 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(1), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), v102, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4827572 b */
    goto L_4827704;
    L_4827576: ;
    /* @4827576 constant */
    /* @4827580 cast */
    /* @4827584 load */
    /* @4827592 call */
    GM_SITE(vm, 530, 4827592);
    /* @4827600 cast */
    /* @4827604 bf */
    v103 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v103)) goto L_4827684;
    /* @4827608 constant */
    /* @4827612 cast */
    /* @4827616 constant */
    /* @4827620 cast */
    /* @4827624 constant */
    /* @4827628 cast */
    /* @4827632 load */
    /* @4827640 call */
    GM_SITE(vm, 530, 4827640);
    /* @4827648 load */
    /* @4827656 call */
    GM_SITE(vm, 530, 4827656);
    /* @4827664 call */
    GM_SITE(vm, 530, 4827664);
    v104 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v105 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4827672 cast */
    /* @4827676 not */
    /* @4827680 b */
    v106 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v104, v105, VAL(130), VAL(0), VAL(0))));
    p4827688_0 = v106;
    goto L_4827688;
    L_4827684: ;
    /* @4827684 constant */
    p4827688_0 = VAL(0);
    L_4827688: ;
    /* @4827688 bf */
    if (!TRUTH(p4827688_0)) goto L_4827704;
    /* @4827692 constant */
    /* @4827696 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4827704: ;
    /* @4827704 load */
    /* @4827712 constant */
    /* @4827716 add */
    /* @4827720 store */
    v107 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v107);
    /* @4827728 b */
    goto L_4827268;
    L_4827732: ;
    /* @4827732 constant */
    /* @4827736 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4827744: ;
    /* @4827744 load */
    /* @4827752 constant */
    /* @4827756 cmp */
    /* @4827760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4828160;
    /* @4827764 constant */
    /* @4827768 cast */
    /* @4827772 load */
    /* @4827780 call */
    GM_SITE(vm, 530, 4827780);
    /* @4827788 cast */
    /* @4827792 bf */
    v108 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v108)) goto L_4827868;
    /* @4827796 constant */
    /* @4827800 cast */
    /* @4827804 constant */
    /* @4827808 cast */
    /* @4827812 constant */
    /* @4827816 cast */
    /* @4827820 load */
    /* @4827828 call */
    GM_SITE(vm, 530, 4827828);
    /* @4827836 load */
    /* @4827844 call */
    GM_SITE(vm, 530, 4827844);
    /* @4827852 call */
    GM_SITE(vm, 530, 4827852);
    v109 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v110 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4827860 cast */
    /* @4827864 b */
    v111 = BOOL(GM_CALL(vm, "collision_point", 5, v109, v110, VAL(130), VAL(0), VAL(0)));
    p4827872_0 = v111;
    goto L_4827872;
    L_4827868: ;
    /* @4827868 constant */
    p4827872_0 = VAL(0);
    L_4827872: ;
    /* @4827872 bf */
    if (!TRUTH(p4827872_0)) goto L_4828016;
    /* @4827876 constant */
    /* @4827880 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4827888 constant */
    /* @4827892 cast */
    /* @4827896 constant */
    /* @4827900 cast */
    /* @4827904 constant */
    /* @4827908 cast */
    /* @4827912 constant */
    /* @4827924 cast */
    /* @4827928 constant */
    /* @4827940 cast */
    /* @4827944 constant */
    /* @4827948 constant */
    /* @4827952 load */
    /* @4827960 constant */
    /* @4827964 add */
    /* @4827968 constant */
    /* @4827972 constant */
    /* @4827976 load */
    /* @4827984 constant */
    /* @4827988 cast */
    /* @4827992 constant */
    /* @4827996 cast */
    /* @4828000 call */
    GM_SITE(vm, 530, 4828000);
    v112 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4828008 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(158), VAL(0), GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), v112, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4828012 b */
    goto L_4828132;
    L_4828016: ;
    /* @4828016 constant */
    /* @4828020 cast */
    /* @4828024 load */
    /* @4828032 call */
    GM_SITE(vm, 530, 4828032);
    /* @4828040 cast */
    /* @4828044 bf */
    v113 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v113)) goto L_4828124;
    /* @4828048 constant */
    /* @4828052 cast */
    /* @4828056 constant */
    /* @4828060 cast */
    /* @4828064 constant */
    /* @4828068 cast */
    /* @4828072 load */
    /* @4828080 call */
    GM_SITE(vm, 530, 4828080);
    /* @4828088 load */
    /* @4828096 call */
    GM_SITE(vm, 530, 4828096);
    /* @4828104 call */
    GM_SITE(vm, 530, 4828104);
    v114 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v115 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4828112 cast */
    /* @4828116 not */
    /* @4828120 b */
    v116 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v114, v115, VAL(130), VAL(0), VAL(0))));
    p4828128_0 = v116;
    goto L_4828128;
    L_4828124: ;
    /* @4828124 constant */
    p4828128_0 = VAL(0);
    L_4828128: ;
    /* @4828128 bf */
    if (!TRUTH(p4828128_0)) goto L_4828132;
    L_4828132: ;
    /* @4828132 load */
    /* @4828140 constant */
    /* @4828144 add */
    /* @4828148 store */
    v117 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v117);
    /* @4828156 b */
    goto L_4827744;
    L_4828160: ;
    return;
}
