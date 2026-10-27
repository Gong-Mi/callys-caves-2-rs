/* generated from CODE 525 (gml_Object_obj_shootbutton_Draw_0), source start 4812672, end 4817948. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0525(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val p4813036_0;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val p4813352_0;
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
    Val p4813928_0;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val p4814244_0;
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
    Val p4814824_0;
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val p4815124_0;
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
    Val p4815668_0;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val p4815968_0;
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
    Val p4816528_0;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val v85;
    Val p4816844_0;
    Val v86;
    Val v87;
    Val v88;
    Val v89;
    Val v90;
    Val v91;
    Val v92;
    Val v93;
    Val v94;
    Val v95;
    Val v96;
    Val v97;
    Val p4817420_0;
    Val v98;
    Val v99;
    Val v100;
    Val v101;
    Val v102;
    Val v103;
    Val p4817736_0;
    Val v104;
    Val v105;
    Val v106;
    Val v107;
    Val v108;
    /* @4812672 load */
    /* @4812680 constant */
    /* @4812684 cmp */
    /* @4812688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4813564;
    /* @4812692 constant */
    /* @4812704 cast */
    /* @4812708 constant */
    /* @4812712 cast */
    /* @4812716 constant */
    /* @4812720 cast */
    /* @4812724 constant */
    /* @4812736 cast */
    /* @4812740 constant */
    /* @4812752 cast */
    /* @4812756 constant */
    /* @4812760 constant */
    /* @4812764 load */
    /* @4812772 constant */
    /* @4812776 add */
    /* @4812780 constant */
    /* @4812784 constant */
    /* @4812788 load */
    /* @4812796 constant */
    /* @4812800 add */
    /* @4812804 constant */
    /* @4812808 cast */
    /* @4812812 constant */
    /* @4812816 cast */
    /* @4812820 call */
    GM_SITE(vm, 525, 4812820);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(315));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4812828 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v1, v2, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4812832 constant */
    /* @4812836 constant */
    /* @4812840 load */
    /* @4812848 constant */
    /* @4812852 add */
    /* @4812856 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(315));
    GM_WRITE(vm, -1, "x", v3);
    /* @4812864 constant */
    /* @4812868 constant */
    /* @4812872 load */
    /* @4812880 constant */
    /* @4812884 add */
    /* @4812888 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    GM_WRITE(vm, -1, "y", v4);
    /* @4812896 constant */
    /* @4812900 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4812908: ;
    /* @4812908 load */
    /* @4812916 constant */
    /* @4812920 cmp */
    /* @4812924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4813564;
    /* @4812928 constant */
    /* @4812932 cast */
    /* @4812936 load */
    /* @4812944 call */
    GM_SITE(vm, 525, 4812944);
    /* @4812952 cast */
    /* @4812956 bf */
    v5 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v5)) goto L_4813032;
    /* @4812960 constant */
    /* @4812964 cast */
    /* @4812968 constant */
    /* @4812972 cast */
    /* @4812976 constant */
    /* @4812980 cast */
    /* @4812984 load */
    /* @4812992 call */
    GM_SITE(vm, 525, 4812992);
    /* @4813000 load */
    /* @4813008 call */
    GM_SITE(vm, 525, 4813008);
    /* @4813016 call */
    GM_SITE(vm, 525, 4813016);
    v6 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v7 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4813024 cast */
    /* @4813028 b */
    v8 = BOOL(GM_CALL(vm, "collision_point", 5, v6, v7, VAL(128), VAL(0), VAL(0)));
    p4813036_0 = v8;
    goto L_4813036;
    L_4813032: ;
    /* @4813032 constant */
    p4813036_0 = VAL(0);
    L_4813036: ;
    /* @4813036 bf */
    if (!TRUTH(p4813036_0)) goto L_4813192;
    /* @4813040 constant */
    /* @4813044 constant */
    /* @4813048 constant */
    /* @4813052 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4813060 constant */
    /* @4813064 cast */
    /* @4813068 constant */
    /* @4813072 cast */
    /* @4813076 constant */
    /* @4813080 cast */
    /* @4813084 constant */
    /* @4813096 cast */
    /* @4813100 constant */
    /* @4813112 cast */
    /* @4813116 constant */
    /* @4813120 constant */
    /* @4813124 load */
    /* @4813132 constant */
    /* @4813136 add */
    /* @4813140 constant */
    /* @4813144 constant */
    /* @4813148 load */
    /* @4813156 constant */
    /* @4813160 add */
    /* @4813164 constant */
    /* @4813168 cast */
    /* @4813172 constant */
    /* @4813176 cast */
    /* @4813180 call */
    GM_SITE(vm, 525, 4813180);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(315));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4813188 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v9, v10, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4813192: ;
    /* @4813192 load */
    /* @4813200 constant */
    /* @4813204 cmp */
    /* @4813208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4813536;
    /* @4813212 constant */
    /* @4813216 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4813224: ;
    /* @4813224 load */
    /* @4813232 constant */
    /* @4813236 cmp */
    /* @4813240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4813536;
    /* @4813244 constant */
    /* @4813248 cast */
    /* @4813252 load */
    /* @4813260 call */
    GM_SITE(vm, 525, 4813260);
    /* @4813268 cast */
    /* @4813272 bf */
    v11 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v11)) goto L_4813348;
    /* @4813276 constant */
    /* @4813280 cast */
    /* @4813284 constant */
    /* @4813288 cast */
    /* @4813292 constant */
    /* @4813296 cast */
    /* @4813300 load */
    /* @4813308 call */
    GM_SITE(vm, 525, 4813308);
    /* @4813316 load */
    /* @4813324 call */
    GM_SITE(vm, 525, 4813324);
    /* @4813332 call */
    GM_SITE(vm, 525, 4813332);
    v12 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v13 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4813340 cast */
    /* @4813344 b */
    v14 = BOOL(GM_CALL(vm, "collision_point", 5, v12, v13, VAL(128), VAL(0), VAL(0)));
    p4813352_0 = v14;
    goto L_4813352;
    L_4813348: ;
    /* @4813348 constant */
    p4813352_0 = VAL(0);
    L_4813352: ;
    /* @4813352 bf */
    if (!TRUTH(p4813352_0)) goto L_4813508;
    /* @4813356 constant */
    /* @4813360 constant */
    /* @4813364 constant */
    /* @4813368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4813376 constant */
    /* @4813380 cast */
    /* @4813384 constant */
    /* @4813388 cast */
    /* @4813392 constant */
    /* @4813396 cast */
    /* @4813400 constant */
    /* @4813412 cast */
    /* @4813416 constant */
    /* @4813428 cast */
    /* @4813432 constant */
    /* @4813436 constant */
    /* @4813440 load */
    /* @4813448 constant */
    /* @4813452 add */
    /* @4813456 constant */
    /* @4813460 constant */
    /* @4813464 load */
    /* @4813472 constant */
    /* @4813476 add */
    /* @4813480 constant */
    /* @4813484 cast */
    /* @4813488 constant */
    /* @4813492 cast */
    /* @4813496 call */
    GM_SITE(vm, 525, 4813496);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(315));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4813504 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v15, v16, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4813508: ;
    /* @4813508 load */
    /* @4813516 constant */
    /* @4813520 add */
    /* @4813524 store */
    v17 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v17);
    /* @4813532 b */
    goto L_4813224;
    L_4813536: ;
    /* @4813536 load */
    /* @4813544 constant */
    /* @4813548 add */
    /* @4813552 store */
    v18 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v18);
    /* @4813560 b */
    goto L_4812908;
    L_4813564: ;
    /* @4813564 load */
    /* @4813572 constant */
    /* @4813576 cmp */
    /* @4813580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4814456;
    /* @4813584 constant */
    /* @4813596 cast */
    /* @4813600 constant */
    /* @4813604 cast */
    /* @4813608 constant */
    /* @4813612 cast */
    /* @4813616 constant */
    /* @4813628 cast */
    /* @4813632 constant */
    /* @4813644 cast */
    /* @4813648 constant */
    /* @4813652 constant */
    /* @4813656 load */
    /* @4813664 constant */
    /* @4813668 add */
    /* @4813672 constant */
    /* @4813676 constant */
    /* @4813680 load */
    /* @4813688 constant */
    /* @4813692 add */
    /* @4813696 constant */
    /* @4813700 cast */
    /* @4813704 constant */
    /* @4813708 cast */
    /* @4813712 call */
    GM_SITE(vm, 525, 4813712);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(275));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4813720 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v19, v20, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(0.6)));
    /* @4813724 constant */
    /* @4813728 constant */
    /* @4813732 load */
    /* @4813740 constant */
    /* @4813744 add */
    /* @4813748 store */
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(265));
    GM_WRITE(vm, -1, "x", v21);
    /* @4813756 constant */
    /* @4813760 constant */
    /* @4813764 load */
    /* @4813772 constant */
    /* @4813776 add */
    /* @4813780 store */
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    GM_WRITE(vm, -1, "y", v22);
    /* @4813788 constant */
    /* @4813792 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4813800: ;
    /* @4813800 load */
    /* @4813808 constant */
    /* @4813812 cmp */
    /* @4813816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4814456;
    /* @4813820 constant */
    /* @4813824 cast */
    /* @4813828 load */
    /* @4813836 call */
    GM_SITE(vm, 525, 4813836);
    /* @4813844 cast */
    /* @4813848 bf */
    v23 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v23)) goto L_4813924;
    /* @4813852 constant */
    /* @4813856 cast */
    /* @4813860 constant */
    /* @4813864 cast */
    /* @4813868 constant */
    /* @4813872 cast */
    /* @4813876 load */
    /* @4813884 call */
    GM_SITE(vm, 525, 4813884);
    /* @4813892 load */
    /* @4813900 call */
    GM_SITE(vm, 525, 4813900);
    /* @4813908 call */
    GM_SITE(vm, 525, 4813908);
    v24 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v25 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4813916 cast */
    /* @4813920 b */
    v26 = BOOL(GM_CALL(vm, "collision_point", 5, v24, v25, VAL(128), VAL(0), VAL(0)));
    p4813928_0 = v26;
    goto L_4813928;
    L_4813924: ;
    /* @4813924 constant */
    p4813928_0 = VAL(0);
    L_4813928: ;
    /* @4813928 bf */
    if (!TRUTH(p4813928_0)) goto L_4814084;
    /* @4813932 constant */
    /* @4813936 constant */
    /* @4813940 constant */
    /* @4813944 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4813952 constant */
    /* @4813956 cast */
    /* @4813960 constant */
    /* @4813964 cast */
    /* @4813968 constant */
    /* @4813972 cast */
    /* @4813976 constant */
    /* @4813988 cast */
    /* @4813992 constant */
    /* @4814004 cast */
    /* @4814008 constant */
    /* @4814012 constant */
    /* @4814016 load */
    /* @4814024 constant */
    /* @4814028 add */
    /* @4814032 constant */
    /* @4814036 constant */
    /* @4814040 load */
    /* @4814048 constant */
    /* @4814052 add */
    /* @4814056 constant */
    /* @4814060 cast */
    /* @4814064 constant */
    /* @4814068 cast */
    /* @4814072 call */
    GM_SITE(vm, 525, 4814072);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(275));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4814080 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v27, v28, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4814084: ;
    /* @4814084 load */
    /* @4814092 constant */
    /* @4814096 cmp */
    /* @4814100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4814428;
    /* @4814104 constant */
    /* @4814108 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4814116: ;
    /* @4814116 load */
    /* @4814124 constant */
    /* @4814128 cmp */
    /* @4814132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4814428;
    /* @4814136 constant */
    /* @4814140 cast */
    /* @4814144 load */
    /* @4814152 call */
    GM_SITE(vm, 525, 4814152);
    /* @4814160 cast */
    /* @4814164 bf */
    v29 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v29)) goto L_4814240;
    /* @4814168 constant */
    /* @4814172 cast */
    /* @4814176 constant */
    /* @4814180 cast */
    /* @4814184 constant */
    /* @4814188 cast */
    /* @4814192 load */
    /* @4814200 call */
    GM_SITE(vm, 525, 4814200);
    /* @4814208 load */
    /* @4814216 call */
    GM_SITE(vm, 525, 4814216);
    /* @4814224 call */
    GM_SITE(vm, 525, 4814224);
    v30 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v31 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4814232 cast */
    /* @4814236 b */
    v32 = BOOL(GM_CALL(vm, "collision_point", 5, v30, v31, VAL(128), VAL(0), VAL(0)));
    p4814244_0 = v32;
    goto L_4814244;
    L_4814240: ;
    /* @4814240 constant */
    p4814244_0 = VAL(0);
    L_4814244: ;
    /* @4814244 bf */
    if (!TRUTH(p4814244_0)) goto L_4814400;
    /* @4814248 constant */
    /* @4814252 constant */
    /* @4814256 constant */
    /* @4814260 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4814268 constant */
    /* @4814272 cast */
    /* @4814276 constant */
    /* @4814280 cast */
    /* @4814284 constant */
    /* @4814288 cast */
    /* @4814292 constant */
    /* @4814304 cast */
    /* @4814308 constant */
    /* @4814320 cast */
    /* @4814324 constant */
    /* @4814328 constant */
    /* @4814332 load */
    /* @4814340 constant */
    /* @4814344 add */
    /* @4814348 constant */
    /* @4814352 constant */
    /* @4814356 load */
    /* @4814364 constant */
    /* @4814368 add */
    /* @4814372 constant */
    /* @4814376 cast */
    /* @4814380 constant */
    /* @4814384 cast */
    /* @4814388 call */
    GM_SITE(vm, 525, 4814388);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(275));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4814396 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v33, v34, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4814400: ;
    /* @4814400 load */
    /* @4814408 constant */
    /* @4814412 add */
    /* @4814416 store */
    v35 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v35);
    /* @4814424 b */
    goto L_4814116;
    L_4814428: ;
    /* @4814428 load */
    /* @4814436 constant */
    /* @4814440 add */
    /* @4814444 store */
    v36 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v36);
    /* @4814452 b */
    goto L_4813800;
    L_4814456: ;
    /* @4814456 load */
    /* @4814464 constant */
    /* @4814468 cmp */
    /* @4814472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4814476;
    L_4814476: ;
    /* @4814476 load */
    /* @4814484 constant */
    /* @4814488 cmp */
    /* @4814492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4815320;
    /* @4814496 constant */
    /* @4814508 cast */
    /* @4814512 constant */
    /* @4814516 cast */
    /* @4814520 constant */
    /* @4814524 cast */
    /* @4814528 constant */
    /* @4814532 cast */
    /* @4814536 constant */
    /* @4814540 cast */
    /* @4814544 constant */
    /* @4814548 constant */
    /* @4814552 load */
    /* @4814560 constant */
    /* @4814564 add */
    /* @4814568 constant */
    /* @4814572 constant */
    /* @4814576 load */
    /* @4814584 constant */
    /* @4814588 add */
    /* @4814592 constant */
    /* @4814596 cast */
    /* @4814600 constant */
    /* @4814604 cast */
    /* @4814608 call */
    GM_SITE(vm, 525, 4814608);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(380));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4814616 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v37, v38, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4814620 constant */
    /* @4814624 constant */
    /* @4814628 load */
    /* @4814636 constant */
    /* @4814640 add */
    /* @4814644 store */
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(380));
    GM_WRITE(vm, -1, "x", v39);
    /* @4814652 constant */
    /* @4814656 constant */
    /* @4814660 load */
    /* @4814668 constant */
    /* @4814672 add */
    /* @4814676 store */
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    GM_WRITE(vm, -1, "y", v40);
    /* @4814684 constant */
    /* @4814688 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4814696: ;
    /* @4814696 load */
    /* @4814704 constant */
    /* @4814708 cmp */
    /* @4814712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4815320;
    /* @4814716 constant */
    /* @4814720 cast */
    /* @4814724 load */
    /* @4814732 call */
    GM_SITE(vm, 525, 4814732);
    /* @4814740 cast */
    /* @4814744 bf */
    v41 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v41)) goto L_4814820;
    /* @4814748 constant */
    /* @4814752 cast */
    /* @4814756 constant */
    /* @4814760 cast */
    /* @4814764 constant */
    /* @4814768 cast */
    /* @4814772 load */
    /* @4814780 call */
    GM_SITE(vm, 525, 4814780);
    /* @4814788 load */
    /* @4814796 call */
    GM_SITE(vm, 525, 4814796);
    /* @4814804 call */
    GM_SITE(vm, 525, 4814804);
    v42 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v43 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4814812 cast */
    /* @4814816 b */
    v44 = BOOL(GM_CALL(vm, "collision_point", 5, v42, v43, VAL(128), VAL(0), VAL(0)));
    p4814824_0 = v44;
    goto L_4814824;
    L_4814820: ;
    /* @4814820 constant */
    p4814824_0 = VAL(0);
    L_4814824: ;
    /* @4814824 bf */
    if (!TRUTH(p4814824_0)) goto L_4814964;
    /* @4814828 constant */
    /* @4814832 constant */
    /* @4814836 constant */
    /* @4814840 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4814848 constant */
    /* @4814852 cast */
    /* @4814856 constant */
    /* @4814860 cast */
    /* @4814864 constant */
    /* @4814868 cast */
    /* @4814872 constant */
    /* @4814876 cast */
    /* @4814880 constant */
    /* @4814884 cast */
    /* @4814888 constant */
    /* @4814892 constant */
    /* @4814896 load */
    /* @4814904 constant */
    /* @4814908 add */
    /* @4814912 constant */
    /* @4814916 constant */
    /* @4814920 load */
    /* @4814928 constant */
    /* @4814932 add */
    /* @4814936 constant */
    /* @4814940 cast */
    /* @4814944 constant */
    /* @4814948 cast */
    /* @4814952 call */
    GM_SITE(vm, 525, 4814952);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(380));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4814960 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v45, v46, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4814964: ;
    /* @4814964 load */
    /* @4814972 constant */
    /* @4814976 cmp */
    /* @4814980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4815292;
    /* @4814984 constant */
    /* @4814988 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4814996: ;
    /* @4814996 load */
    /* @4815004 constant */
    /* @4815008 cmp */
    /* @4815012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4815292;
    /* @4815016 constant */
    /* @4815020 cast */
    /* @4815024 load */
    /* @4815032 call */
    GM_SITE(vm, 525, 4815032);
    /* @4815040 cast */
    /* @4815044 bf */
    v47 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v47)) goto L_4815120;
    /* @4815048 constant */
    /* @4815052 cast */
    /* @4815056 constant */
    /* @4815060 cast */
    /* @4815064 constant */
    /* @4815068 cast */
    /* @4815072 load */
    /* @4815080 call */
    GM_SITE(vm, 525, 4815080);
    /* @4815088 load */
    /* @4815096 call */
    GM_SITE(vm, 525, 4815096);
    /* @4815104 call */
    GM_SITE(vm, 525, 4815104);
    v48 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v49 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4815112 cast */
    /* @4815116 b */
    v50 = BOOL(GM_CALL(vm, "collision_point", 5, v48, v49, VAL(128), VAL(0), VAL(0)));
    p4815124_0 = v50;
    goto L_4815124;
    L_4815120: ;
    /* @4815120 constant */
    p4815124_0 = VAL(0);
    L_4815124: ;
    /* @4815124 bf */
    if (!TRUTH(p4815124_0)) goto L_4815264;
    /* @4815128 constant */
    /* @4815132 constant */
    /* @4815136 constant */
    /* @4815140 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4815148 constant */
    /* @4815152 cast */
    /* @4815156 constant */
    /* @4815160 cast */
    /* @4815164 constant */
    /* @4815168 cast */
    /* @4815172 constant */
    /* @4815176 cast */
    /* @4815180 constant */
    /* @4815184 cast */
    /* @4815188 constant */
    /* @4815192 constant */
    /* @4815196 load */
    /* @4815204 constant */
    /* @4815208 add */
    /* @4815212 constant */
    /* @4815216 constant */
    /* @4815220 load */
    /* @4815228 constant */
    /* @4815232 add */
    /* @4815236 constant */
    /* @4815240 cast */
    /* @4815244 constant */
    /* @4815248 cast */
    /* @4815252 call */
    GM_SITE(vm, 525, 4815252);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(380));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4815260 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v51, v52, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4815264: ;
    /* @4815264 load */
    /* @4815272 constant */
    /* @4815276 add */
    /* @4815280 store */
    v53 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v53);
    /* @4815288 b */
    goto L_4814996;
    L_4815292: ;
    /* @4815292 load */
    /* @4815300 constant */
    /* @4815304 add */
    /* @4815308 store */
    v54 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v54);
    /* @4815316 b */
    goto L_4814696;
    L_4815320: ;
    /* @4815320 load */
    /* @4815328 constant */
    /* @4815332 cmp */
    /* @4815336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4816164;
    /* @4815340 constant */
    /* @4815352 cast */
    /* @4815356 constant */
    /* @4815360 cast */
    /* @4815364 constant */
    /* @4815368 cast */
    /* @4815372 constant */
    /* @4815376 cast */
    /* @4815380 constant */
    /* @4815384 cast */
    /* @4815388 constant */
    /* @4815392 constant */
    /* @4815396 load */
    /* @4815404 constant */
    /* @4815408 add */
    /* @4815412 constant */
    /* @4815416 constant */
    /* @4815420 load */
    /* @4815428 constant */
    /* @4815432 add */
    /* @4815436 constant */
    /* @4815440 cast */
    /* @4815444 constant */
    /* @4815448 cast */
    /* @4815452 call */
    GM_SITE(vm, 525, 4815452);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(380));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4815460 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v55, v56, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4815464 constant */
    /* @4815468 constant */
    /* @4815472 load */
    /* @4815480 constant */
    /* @4815484 add */
    /* @4815488 store */
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(380));
    GM_WRITE(vm, -1, "x", v57);
    /* @4815496 constant */
    /* @4815500 constant */
    /* @4815504 load */
    /* @4815512 constant */
    /* @4815516 add */
    /* @4815520 store */
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    GM_WRITE(vm, -1, "y", v58);
    /* @4815528 constant */
    /* @4815532 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4815540: ;
    /* @4815540 load */
    /* @4815548 constant */
    /* @4815552 cmp */
    /* @4815556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4816164;
    /* @4815560 constant */
    /* @4815564 cast */
    /* @4815568 load */
    /* @4815576 call */
    GM_SITE(vm, 525, 4815576);
    /* @4815584 cast */
    /* @4815588 bf */
    v59 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v59)) goto L_4815664;
    /* @4815592 constant */
    /* @4815596 cast */
    /* @4815600 constant */
    /* @4815604 cast */
    /* @4815608 constant */
    /* @4815612 cast */
    /* @4815616 load */
    /* @4815624 call */
    GM_SITE(vm, 525, 4815624);
    /* @4815632 load */
    /* @4815640 call */
    GM_SITE(vm, 525, 4815640);
    /* @4815648 call */
    GM_SITE(vm, 525, 4815648);
    v60 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v61 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4815656 cast */
    /* @4815660 b */
    v62 = BOOL(GM_CALL(vm, "collision_point", 5, v60, v61, VAL(128), VAL(0), VAL(0)));
    p4815668_0 = v62;
    goto L_4815668;
    L_4815664: ;
    /* @4815664 constant */
    p4815668_0 = VAL(0);
    L_4815668: ;
    /* @4815668 bf */
    if (!TRUTH(p4815668_0)) goto L_4815808;
    /* @4815672 constant */
    /* @4815676 constant */
    /* @4815680 constant */
    /* @4815684 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4815692 constant */
    /* @4815696 cast */
    /* @4815700 constant */
    /* @4815704 cast */
    /* @4815708 constant */
    /* @4815712 cast */
    /* @4815716 constant */
    /* @4815720 cast */
    /* @4815724 constant */
    /* @4815728 cast */
    /* @4815732 constant */
    /* @4815736 constant */
    /* @4815740 load */
    /* @4815748 constant */
    /* @4815752 add */
    /* @4815756 constant */
    /* @4815760 constant */
    /* @4815764 load */
    /* @4815772 constant */
    /* @4815776 add */
    /* @4815780 constant */
    /* @4815784 cast */
    /* @4815788 constant */
    /* @4815792 cast */
    /* @4815796 call */
    GM_SITE(vm, 525, 4815796);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(380));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4815804 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v63, v64, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4815808: ;
    /* @4815808 load */
    /* @4815816 constant */
    /* @4815820 cmp */
    /* @4815824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4816136;
    /* @4815828 constant */
    /* @4815832 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4815840: ;
    /* @4815840 load */
    /* @4815848 constant */
    /* @4815852 cmp */
    /* @4815856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4816136;
    /* @4815860 constant */
    /* @4815864 cast */
    /* @4815868 load */
    /* @4815876 call */
    GM_SITE(vm, 525, 4815876);
    /* @4815884 cast */
    /* @4815888 bf */
    v65 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v65)) goto L_4815964;
    /* @4815892 constant */
    /* @4815896 cast */
    /* @4815900 constant */
    /* @4815904 cast */
    /* @4815908 constant */
    /* @4815912 cast */
    /* @4815916 load */
    /* @4815924 call */
    GM_SITE(vm, 525, 4815924);
    /* @4815932 load */
    /* @4815940 call */
    GM_SITE(vm, 525, 4815940);
    /* @4815948 call */
    GM_SITE(vm, 525, 4815948);
    v66 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v67 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4815956 cast */
    /* @4815960 b */
    v68 = BOOL(GM_CALL(vm, "collision_point", 5, v66, v67, VAL(128), VAL(0), VAL(0)));
    p4815968_0 = v68;
    goto L_4815968;
    L_4815964: ;
    /* @4815964 constant */
    p4815968_0 = VAL(0);
    L_4815968: ;
    /* @4815968 bf */
    if (!TRUTH(p4815968_0)) goto L_4816108;
    /* @4815972 constant */
    /* @4815976 constant */
    /* @4815980 constant */
    /* @4815984 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4815992 constant */
    /* @4815996 cast */
    /* @4816000 constant */
    /* @4816004 cast */
    /* @4816008 constant */
    /* @4816012 cast */
    /* @4816016 constant */
    /* @4816020 cast */
    /* @4816024 constant */
    /* @4816028 cast */
    /* @4816032 constant */
    /* @4816036 constant */
    /* @4816040 load */
    /* @4816048 constant */
    /* @4816052 add */
    /* @4816056 constant */
    /* @4816060 constant */
    /* @4816064 load */
    /* @4816072 constant */
    /* @4816076 add */
    /* @4816080 constant */
    /* @4816084 cast */
    /* @4816088 constant */
    /* @4816092 cast */
    /* @4816096 call */
    GM_SITE(vm, 525, 4816096);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(380));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4816104 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v69, v70, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4816108: ;
    /* @4816108 load */
    /* @4816116 constant */
    /* @4816120 add */
    /* @4816124 store */
    v71 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v71);
    /* @4816132 b */
    goto L_4815840;
    L_4816136: ;
    /* @4816136 load */
    /* @4816144 constant */
    /* @4816148 add */
    /* @4816152 store */
    v72 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v72);
    /* @4816160 b */
    goto L_4815540;
    L_4816164: ;
    /* @4816164 load */
    /* @4816172 constant */
    /* @4816176 cmp */
    /* @4816180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4817056;
    /* @4816184 constant */
    /* @4816196 cast */
    /* @4816200 constant */
    /* @4816204 cast */
    /* @4816208 constant */
    /* @4816212 cast */
    /* @4816216 constant */
    /* @4816228 cast */
    /* @4816232 constant */
    /* @4816244 cast */
    /* @4816248 constant */
    /* @4816252 constant */
    /* @4816256 load */
    /* @4816264 constant */
    /* @4816268 add */
    /* @4816272 constant */
    /* @4816276 constant */
    /* @4816280 load */
    /* @4816288 constant */
    /* @4816292 add */
    /* @4816296 constant */
    /* @4816300 cast */
    /* @4816304 constant */
    /* @4816308 cast */
    /* @4816312 call */
    GM_SITE(vm, 525, 4816312);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(315));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4816320 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v73, v74, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4816324 constant */
    /* @4816328 constant */
    /* @4816332 load */
    /* @4816340 constant */
    /* @4816344 add */
    /* @4816348 store */
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(315));
    GM_WRITE(vm, -1, "x", v75);
    /* @4816356 constant */
    /* @4816360 constant */
    /* @4816364 load */
    /* @4816372 constant */
    /* @4816376 add */
    /* @4816380 store */
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v76);
    /* @4816388 constant */
    /* @4816392 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4816400: ;
    /* @4816400 load */
    /* @4816408 constant */
    /* @4816412 cmp */
    /* @4816416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4817056;
    /* @4816420 constant */
    /* @4816424 cast */
    /* @4816428 load */
    /* @4816436 call */
    GM_SITE(vm, 525, 4816436);
    /* @4816444 cast */
    /* @4816448 bf */
    v77 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v77)) goto L_4816524;
    /* @4816452 constant */
    /* @4816456 cast */
    /* @4816460 constant */
    /* @4816464 cast */
    /* @4816468 constant */
    /* @4816472 cast */
    /* @4816476 load */
    /* @4816484 call */
    GM_SITE(vm, 525, 4816484);
    /* @4816492 load */
    /* @4816500 call */
    GM_SITE(vm, 525, 4816500);
    /* @4816508 call */
    GM_SITE(vm, 525, 4816508);
    v78 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v79 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4816516 cast */
    /* @4816520 b */
    v80 = BOOL(GM_CALL(vm, "collision_point", 5, v78, v79, VAL(128), VAL(0), VAL(0)));
    p4816528_0 = v80;
    goto L_4816528;
    L_4816524: ;
    /* @4816524 constant */
    p4816528_0 = VAL(0);
    L_4816528: ;
    /* @4816528 bf */
    if (!TRUTH(p4816528_0)) goto L_4816684;
    /* @4816532 constant */
    /* @4816536 constant */
    /* @4816540 constant */
    /* @4816544 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4816552 constant */
    /* @4816556 cast */
    /* @4816560 constant */
    /* @4816564 cast */
    /* @4816568 constant */
    /* @4816572 cast */
    /* @4816576 constant */
    /* @4816588 cast */
    /* @4816592 constant */
    /* @4816604 cast */
    /* @4816608 constant */
    /* @4816612 constant */
    /* @4816616 load */
    /* @4816624 constant */
    /* @4816628 add */
    /* @4816632 constant */
    /* @4816636 constant */
    /* @4816640 load */
    /* @4816648 constant */
    /* @4816652 add */
    /* @4816656 constant */
    /* @4816660 cast */
    /* @4816664 constant */
    /* @4816668 cast */
    /* @4816672 call */
    GM_SITE(vm, 525, 4816672);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(315));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4816680 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v81, v82, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4816684: ;
    /* @4816684 load */
    /* @4816692 constant */
    /* @4816696 cmp */
    /* @4816700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4817028;
    /* @4816704 constant */
    /* @4816708 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4816716: ;
    /* @4816716 load */
    /* @4816724 constant */
    /* @4816728 cmp */
    /* @4816732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4817028;
    /* @4816736 constant */
    /* @4816740 cast */
    /* @4816744 load */
    /* @4816752 call */
    GM_SITE(vm, 525, 4816752);
    /* @4816760 cast */
    /* @4816764 bf */
    v83 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v83)) goto L_4816840;
    /* @4816768 constant */
    /* @4816772 cast */
    /* @4816776 constant */
    /* @4816780 cast */
    /* @4816784 constant */
    /* @4816788 cast */
    /* @4816792 load */
    /* @4816800 call */
    GM_SITE(vm, 525, 4816800);
    /* @4816808 load */
    /* @4816816 call */
    GM_SITE(vm, 525, 4816816);
    /* @4816824 call */
    GM_SITE(vm, 525, 4816824);
    v84 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v85 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4816832 cast */
    /* @4816836 b */
    v86 = BOOL(GM_CALL(vm, "collision_point", 5, v84, v85, VAL(128), VAL(0), VAL(0)));
    p4816844_0 = v86;
    goto L_4816844;
    L_4816840: ;
    /* @4816840 constant */
    p4816844_0 = VAL(0);
    L_4816844: ;
    /* @4816844 bf */
    if (!TRUTH(p4816844_0)) goto L_4817000;
    /* @4816848 constant */
    /* @4816852 constant */
    /* @4816856 constant */
    /* @4816860 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4816868 constant */
    /* @4816872 cast */
    /* @4816876 constant */
    /* @4816880 cast */
    /* @4816884 constant */
    /* @4816888 cast */
    /* @4816892 constant */
    /* @4816904 cast */
    /* @4816908 constant */
    /* @4816920 cast */
    /* @4816924 constant */
    /* @4816928 constant */
    /* @4816932 load */
    /* @4816940 constant */
    /* @4816944 add */
    /* @4816948 constant */
    /* @4816952 constant */
    /* @4816956 load */
    /* @4816964 constant */
    /* @4816968 add */
    /* @4816972 constant */
    /* @4816976 cast */
    /* @4816980 constant */
    /* @4816984 cast */
    /* @4816988 call */
    GM_SITE(vm, 525, 4816988);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(315));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4816996 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v87, v88, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4817000: ;
    /* @4817000 load */
    /* @4817008 constant */
    /* @4817012 add */
    /* @4817016 store */
    v89 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v89);
    /* @4817024 b */
    goto L_4816716;
    L_4817028: ;
    /* @4817028 load */
    /* @4817036 constant */
    /* @4817040 add */
    /* @4817044 store */
    v90 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v90);
    /* @4817052 b */
    goto L_4816400;
    L_4817056: ;
    /* @4817056 load */
    /* @4817064 constant */
    /* @4817068 cmp */
    /* @4817072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4817948;
    /* @4817076 constant */
    /* @4817088 cast */
    /* @4817092 constant */
    /* @4817096 cast */
    /* @4817100 constant */
    /* @4817104 cast */
    /* @4817108 constant */
    /* @4817120 cast */
    /* @4817124 constant */
    /* @4817136 cast */
    /* @4817140 constant */
    /* @4817144 constant */
    /* @4817148 load */
    /* @4817156 constant */
    /* @4817160 add */
    /* @4817164 constant */
    /* @4817168 constant */
    /* @4817172 load */
    /* @4817180 constant */
    /* @4817184 add */
    /* @4817188 constant */
    /* @4817192 cast */
    /* @4817196 constant */
    /* @4817200 cast */
    /* @4817204 call */
    GM_SITE(vm, 525, 4817204);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(345));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4817212 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(0), v91, v92, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4817216 constant */
    /* @4817220 constant */
    /* @4817224 load */
    /* @4817232 constant */
    /* @4817236 add */
    /* @4817240 store */
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(345));
    GM_WRITE(vm, -1, "x", v93);
    /* @4817248 constant */
    /* @4817252 constant */
    /* @4817256 load */
    /* @4817264 constant */
    /* @4817268 add */
    /* @4817272 store */
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    GM_WRITE(vm, -1, "y", v94);
    /* @4817280 constant */
    /* @4817284 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4817292: ;
    /* @4817292 load */
    /* @4817300 constant */
    /* @4817304 cmp */
    /* @4817308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4817948;
    /* @4817312 constant */
    /* @4817316 cast */
    /* @4817320 load */
    /* @4817328 call */
    GM_SITE(vm, 525, 4817328);
    /* @4817336 cast */
    /* @4817340 bf */
    v95 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v95)) goto L_4817416;
    /* @4817344 constant */
    /* @4817348 cast */
    /* @4817352 constant */
    /* @4817356 cast */
    /* @4817360 constant */
    /* @4817364 cast */
    /* @4817368 load */
    /* @4817376 call */
    GM_SITE(vm, 525, 4817376);
    /* @4817384 load */
    /* @4817392 call */
    GM_SITE(vm, 525, 4817392);
    /* @4817400 call */
    GM_SITE(vm, 525, 4817400);
    v96 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v97 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4817408 cast */
    /* @4817412 b */
    v98 = BOOL(GM_CALL(vm, "collision_point", 5, v96, v97, VAL(128), VAL(0), VAL(0)));
    p4817420_0 = v98;
    goto L_4817420;
    L_4817416: ;
    /* @4817416 constant */
    p4817420_0 = VAL(0);
    L_4817420: ;
    /* @4817420 bf */
    if (!TRUTH(p4817420_0)) goto L_4817576;
    /* @4817424 constant */
    /* @4817428 constant */
    /* @4817432 constant */
    /* @4817436 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4817444 constant */
    /* @4817448 cast */
    /* @4817452 constant */
    /* @4817456 cast */
    /* @4817460 constant */
    /* @4817464 cast */
    /* @4817468 constant */
    /* @4817480 cast */
    /* @4817484 constant */
    /* @4817496 cast */
    /* @4817500 constant */
    /* @4817504 constant */
    /* @4817508 load */
    /* @4817516 constant */
    /* @4817520 add */
    /* @4817524 constant */
    /* @4817528 constant */
    /* @4817532 load */
    /* @4817540 constant */
    /* @4817544 add */
    /* @4817548 constant */
    /* @4817552 cast */
    /* @4817556 constant */
    /* @4817560 cast */
    /* @4817564 call */
    GM_SITE(vm, 525, 4817564);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(345));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4817572 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v99, v100, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4817576: ;
    /* @4817576 load */
    /* @4817584 constant */
    /* @4817588 cmp */
    /* @4817592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultrifle") == VAL(1)))) goto L_4817920;
    /* @4817596 constant */
    /* @4817600 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4817608: ;
    /* @4817608 load */
    /* @4817616 constant */
    /* @4817620 cmp */
    /* @4817624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4817920;
    /* @4817628 constant */
    /* @4817632 cast */
    /* @4817636 load */
    /* @4817644 call */
    GM_SITE(vm, 525, 4817644);
    /* @4817652 cast */
    /* @4817656 bf */
    v101 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v101)) goto L_4817732;
    /* @4817660 constant */
    /* @4817664 cast */
    /* @4817668 constant */
    /* @4817672 cast */
    /* @4817676 constant */
    /* @4817680 cast */
    /* @4817684 load */
    /* @4817692 call */
    GM_SITE(vm, 525, 4817692);
    /* @4817700 load */
    /* @4817708 call */
    GM_SITE(vm, 525, 4817708);
    /* @4817716 call */
    GM_SITE(vm, 525, 4817716);
    v102 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v103 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4817724 cast */
    /* @4817728 b */
    v104 = BOOL(GM_CALL(vm, "collision_point", 5, v102, v103, VAL(128), VAL(0), VAL(0)));
    p4817736_0 = v104;
    goto L_4817736;
    L_4817732: ;
    /* @4817732 constant */
    p4817736_0 = VAL(0);
    L_4817736: ;
    /* @4817736 bf */
    if (!TRUTH(p4817736_0)) goto L_4817892;
    /* @4817740 constant */
    /* @4817744 constant */
    /* @4817748 constant */
    /* @4817752 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @4817760 constant */
    /* @4817764 cast */
    /* @4817768 constant */
    /* @4817772 cast */
    /* @4817776 constant */
    /* @4817780 cast */
    /* @4817784 constant */
    /* @4817796 cast */
    /* @4817800 constant */
    /* @4817812 cast */
    /* @4817816 constant */
    /* @4817820 constant */
    /* @4817824 load */
    /* @4817832 constant */
    /* @4817836 add */
    /* @4817840 constant */
    /* @4817844 constant */
    /* @4817848 load */
    /* @4817856 constant */
    /* @4817860 add */
    /* @4817864 constant */
    /* @4817868 cast */
    /* @4817872 constant */
    /* @4817876 cast */
    /* @4817880 call */
    GM_SITE(vm, 525, 4817880);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(345));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4817888 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(156), VAL(1), v105, v106, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4817892: ;
    /* @4817892 load */
    /* @4817900 constant */
    /* @4817904 add */
    /* @4817908 store */
    v107 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v107);
    /* @4817916 b */
    goto L_4817608;
    L_4817920: ;
    /* @4817920 load */
    /* @4817928 constant */
    /* @4817932 add */
    /* @4817936 store */
    v108 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v108);
    /* @4817944 b */
    goto L_4817292;
    L_4817948: ;
    return;
}
