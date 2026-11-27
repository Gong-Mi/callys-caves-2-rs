/* generated from CODE 522 (gml_Object_obj_jumpbutton_Draw_0), source start 4809364, end 4812608. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0522(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val p4809728_0;
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
    Val p4810276_0;
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
    Val p4810828_0;
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
    Val p4811344_0;
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
    Val p4811876_0;
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
    Val p4812424_0;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    /* @4809364 load */
    /* @4809372 constant */
    /* @4809376 cmp */
    /* @4809380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4809912;
    /* @4809384 constant */
    /* @4809396 cast */
    /* @4809400 constant */
    /* @4809404 cast */
    /* @4809408 constant */
    /* @4809412 cast */
    /* @4809416 constant */
    /* @4809428 cast */
    /* @4809432 constant */
    /* @4809444 cast */
    /* @4809448 constant */
    /* @4809452 constant */
    /* @4809456 load */
    /* @4809464 constant */
    /* @4809468 add */
    /* @4809472 constant */
    /* @4809476 constant */
    /* @4809480 load */
    /* @4809488 constant */
    /* @4809492 add */
    /* @4809496 constant */
    /* @4809500 cast */
    /* @4809504 constant */
    /* @4809508 cast */
    /* @4809512 call */
    GM_SITE(vm, 522, 4809512);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4809520 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v1, v2, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4809524 constant */
    /* @4809528 constant */
    /* @4809532 load */
    /* @4809540 constant */
    /* @4809544 add */
    /* @4809548 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    GM_WRITE(vm, -1, "x", v3);
    /* @4809556 constant */
    /* @4809560 constant */
    /* @4809564 load */
    /* @4809572 constant */
    /* @4809576 add */
    /* @4809580 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    GM_WRITE(vm, -1, "y", v4);
    /* @4809588 constant */
    /* @4809592 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4809600: ;
    /* @4809600 load */
    /* @4809608 constant */
    /* @4809612 cmp */
    /* @4809616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4809912;
    /* @4809620 constant */
    /* @4809624 cast */
    /* @4809628 load */
    /* @4809636 call */
    GM_SITE(vm, 522, 4809636);
    /* @4809644 cast */
    /* @4809648 bf */
    v5 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v5)) goto L_4809724;
    /* @4809652 constant */
    /* @4809656 cast */
    /* @4809660 constant */
    /* @4809664 cast */
    /* @4809668 constant */
    /* @4809672 cast */
    /* @4809676 load */
    /* @4809684 call */
    GM_SITE(vm, 522, 4809684);
    /* @4809692 load */
    /* @4809700 call */
    GM_SITE(vm, 522, 4809700);
    /* @4809708 call */
    GM_SITE(vm, 522, 4809708);
    v6 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v7 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4809716 cast */
    /* @4809720 b */
    v8 = BOOL(GM_CALL(vm, "collision_point", 5, v6, v7, VAL(127), VAL(0), VAL(0)));
    p4809728_0 = v8;
    goto L_4809728;
    L_4809724: ;
    /* @4809724 constant */
    p4809728_0 = VAL(0);
    L_4809728: ;
    /* @4809728 bf */
    if (!TRUTH(p4809728_0)) goto L_4809884;
    /* @4809732 constant */
    /* @4809736 constant */
    /* @4809740 constant */
    /* @4809744 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4809752 constant */
    /* @4809756 cast */
    /* @4809760 constant */
    /* @4809764 cast */
    /* @4809768 constant */
    /* @4809772 cast */
    /* @4809776 constant */
    /* @4809788 cast */
    /* @4809792 constant */
    /* @4809804 cast */
    /* @4809808 constant */
    /* @4809812 constant */
    /* @4809816 load */
    /* @4809824 constant */
    /* @4809828 add */
    /* @4809832 constant */
    /* @4809836 constant */
    /* @4809840 load */
    /* @4809848 constant */
    /* @4809852 add */
    /* @4809856 constant */
    /* @4809860 cast */
    /* @4809864 constant */
    /* @4809868 cast */
    /* @4809872 call */
    GM_SITE(vm, 522, 4809872);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(380));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4809880 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v9, v10, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4809884: ;
    /* @4809884 load */
    /* @4809892 constant */
    /* @4809896 add */
    /* @4809900 store */
    v11 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v11);
    /* @4809908 b */
    goto L_4809600;
    L_4809912: ;
    /* @4809912 load */
    /* @4809920 constant */
    /* @4809924 cmp */
    /* @4809928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4810460;
    /* @4809932 constant */
    /* @4809944 cast */
    /* @4809948 constant */
    /* @4809952 cast */
    /* @4809956 constant */
    /* @4809960 cast */
    /* @4809964 constant */
    /* @4809976 cast */
    /* @4809980 constant */
    /* @4809992 cast */
    /* @4809996 constant */
    /* @4810000 constant */
    /* @4810004 load */
    /* @4810012 constant */
    /* @4810016 add */
    /* @4810020 constant */
    /* @4810024 constant */
    /* @4810028 load */
    /* @4810036 constant */
    /* @4810040 add */
    /* @4810044 constant */
    /* @4810048 cast */
    /* @4810052 constant */
    /* @4810056 cast */
    /* @4810060 call */
    GM_SITE(vm, 522, 4810060);
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4810068 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v12, v13, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(0.6)));
    /* @4810072 constant */
    /* @4810076 constant */
    /* @4810080 load */
    /* @4810088 constant */
    /* @4810092 add */
    /* @4810096 store */
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    GM_WRITE(vm, -1, "x", v14);
    /* @4810104 constant */
    /* @4810108 constant */
    /* @4810112 load */
    /* @4810120 constant */
    /* @4810124 add */
    /* @4810128 store */
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(202));
    GM_WRITE(vm, -1, "y", v15);
    /* @4810136 constant */
    /* @4810140 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4810148: ;
    /* @4810148 load */
    /* @4810156 constant */
    /* @4810160 cmp */
    /* @4810164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4810460;
    /* @4810168 constant */
    /* @4810172 cast */
    /* @4810176 load */
    /* @4810184 call */
    GM_SITE(vm, 522, 4810184);
    /* @4810192 cast */
    /* @4810196 bf */
    v16 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v16)) goto L_4810272;
    /* @4810200 constant */
    /* @4810204 cast */
    /* @4810208 constant */
    /* @4810212 cast */
    /* @4810216 constant */
    /* @4810220 cast */
    /* @4810224 load */
    /* @4810232 call */
    GM_SITE(vm, 522, 4810232);
    /* @4810240 load */
    /* @4810248 call */
    GM_SITE(vm, 522, 4810248);
    /* @4810256 call */
    GM_SITE(vm, 522, 4810256);
    v17 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v18 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4810264 cast */
    /* @4810268 b */
    v19 = BOOL(GM_CALL(vm, "collision_point", 5, v17, v18, VAL(127), VAL(0), VAL(0)));
    p4810276_0 = v19;
    goto L_4810276;
    L_4810272: ;
    /* @4810272 constant */
    p4810276_0 = VAL(0);
    L_4810276: ;
    /* @4810276 bf */
    if (!TRUTH(p4810276_0)) goto L_4810432;
    /* @4810280 constant */
    /* @4810284 constant */
    /* @4810288 constant */
    /* @4810292 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4810300 constant */
    /* @4810304 cast */
    /* @4810308 constant */
    /* @4810312 cast */
    /* @4810316 constant */
    /* @4810320 cast */
    /* @4810324 constant */
    /* @4810336 cast */
    /* @4810340 constant */
    /* @4810352 cast */
    /* @4810356 constant */
    /* @4810360 constant */
    /* @4810364 load */
    /* @4810372 constant */
    /* @4810376 add */
    /* @4810380 constant */
    /* @4810384 constant */
    /* @4810388 load */
    /* @4810396 constant */
    /* @4810400 add */
    /* @4810404 constant */
    /* @4810408 cast */
    /* @4810412 constant */
    /* @4810416 cast */
    /* @4810420 call */
    GM_SITE(vm, 522, 4810420);
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(330));
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4810428 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v20, v21, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    L_4810432: ;
    /* @4810432 load */
    /* @4810440 constant */
    /* @4810444 add */
    /* @4810448 store */
    v22 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v22);
    /* @4810456 b */
    goto L_4810148;
    L_4810460: ;
    /* @4810460 load */
    /* @4810468 constant */
    /* @4810472 cmp */
    /* @4810476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4810480;
    L_4810480: ;
    /* @4810480 load */
    /* @4810488 constant */
    /* @4810492 cmp */
    /* @4810496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4810996;
    /* @4810500 constant */
    /* @4810512 cast */
    /* @4810516 constant */
    /* @4810520 cast */
    /* @4810524 constant */
    /* @4810528 cast */
    /* @4810532 constant */
    /* @4810536 cast */
    /* @4810540 constant */
    /* @4810544 cast */
    /* @4810548 constant */
    /* @4810552 constant */
    /* @4810556 load */
    /* @4810564 constant */
    /* @4810568 add */
    /* @4810572 constant */
    /* @4810576 constant */
    /* @4810580 load */
    /* @4810588 constant */
    /* @4810592 add */
    /* @4810596 constant */
    /* @4810600 cast */
    /* @4810604 constant */
    /* @4810608 cast */
    /* @4810612 call */
    GM_SITE(vm, 522, 4810612);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4810620 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v23, v24, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4810624 constant */
    /* @4810628 constant */
    /* @4810632 load */
    /* @4810640 constant */
    /* @4810644 add */
    /* @4810648 store */
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    GM_WRITE(vm, -1, "x", v25);
    /* @4810656 constant */
    /* @4810660 constant */
    /* @4810664 load */
    /* @4810672 constant */
    /* @4810676 add */
    /* @4810680 store */
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(320));
    GM_WRITE(vm, -1, "y", v26);
    /* @4810688 constant */
    /* @4810692 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4810700: ;
    /* @4810700 load */
    /* @4810708 constant */
    /* @4810712 cmp */
    /* @4810716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4810996;
    /* @4810720 constant */
    /* @4810724 cast */
    /* @4810728 load */
    /* @4810736 call */
    GM_SITE(vm, 522, 4810736);
    /* @4810744 cast */
    /* @4810748 bf */
    v27 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v27)) goto L_4810824;
    /* @4810752 constant */
    /* @4810756 cast */
    /* @4810760 constant */
    /* @4810764 cast */
    /* @4810768 constant */
    /* @4810772 cast */
    /* @4810776 load */
    /* @4810784 call */
    GM_SITE(vm, 522, 4810784);
    /* @4810792 load */
    /* @4810800 call */
    GM_SITE(vm, 522, 4810800);
    /* @4810808 call */
    GM_SITE(vm, 522, 4810808);
    v28 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v29 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4810816 cast */
    /* @4810820 b */
    v30 = BOOL(GM_CALL(vm, "collision_point", 5, v28, v29, VAL(127), VAL(0), VAL(0)));
    p4810828_0 = v30;
    goto L_4810828;
    L_4810824: ;
    /* @4810824 constant */
    p4810828_0 = VAL(0);
    L_4810828: ;
    /* @4810828 bf */
    if (!TRUTH(p4810828_0)) goto L_4810968;
    /* @4810832 constant */
    /* @4810836 constant */
    /* @4810840 constant */
    /* @4810844 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4810852 constant */
    /* @4810856 cast */
    /* @4810860 constant */
    /* @4810864 cast */
    /* @4810868 constant */
    /* @4810872 cast */
    /* @4810876 constant */
    /* @4810880 cast */
    /* @4810884 constant */
    /* @4810888 cast */
    /* @4810892 constant */
    /* @4810896 constant */
    /* @4810900 load */
    /* @4810908 constant */
    /* @4810912 add */
    /* @4810916 constant */
    /* @4810920 constant */
    /* @4810924 load */
    /* @4810932 constant */
    /* @4810936 add */
    /* @4810940 constant */
    /* @4810944 cast */
    /* @4810948 constant */
    /* @4810952 cast */
    /* @4810956 call */
    GM_SITE(vm, 522, 4810956);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(445));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4810964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v31, v32, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4810968: ;
    /* @4810968 load */
    /* @4810976 constant */
    /* @4810980 add */
    /* @4810984 store */
    v33 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v33);
    /* @4810992 b */
    goto L_4810700;
    L_4810996: ;
    /* @4810996 load */
    /* @4811004 constant */
    /* @4811008 cmp */
    /* @4811012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4811512;
    /* @4811016 constant */
    /* @4811028 cast */
    /* @4811032 constant */
    /* @4811036 cast */
    /* @4811040 constant */
    /* @4811044 cast */
    /* @4811048 constant */
    /* @4811052 cast */
    /* @4811056 constant */
    /* @4811060 cast */
    /* @4811064 constant */
    /* @4811068 constant */
    /* @4811072 load */
    /* @4811080 constant */
    /* @4811084 add */
    /* @4811088 constant */
    /* @4811092 constant */
    /* @4811096 load */
    /* @4811104 constant */
    /* @4811108 add */
    /* @4811112 constant */
    /* @4811116 cast */
    /* @4811120 constant */
    /* @4811124 cast */
    /* @4811128 call */
    GM_SITE(vm, 522, 4811128);
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4811136 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v34, v35, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4811140 constant */
    /* @4811144 constant */
    /* @4811148 load */
    /* @4811156 constant */
    /* @4811160 add */
    /* @4811164 store */
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    GM_WRITE(vm, -1, "x", v36);
    /* @4811172 constant */
    /* @4811176 constant */
    /* @4811180 load */
    /* @4811188 constant */
    /* @4811192 add */
    /* @4811196 store */
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(320));
    GM_WRITE(vm, -1, "y", v37);
    /* @4811204 constant */
    /* @4811208 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4811216: ;
    /* @4811216 load */
    /* @4811224 constant */
    /* @4811228 cmp */
    /* @4811232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4811512;
    /* @4811236 constant */
    /* @4811240 cast */
    /* @4811244 load */
    /* @4811252 call */
    GM_SITE(vm, 522, 4811252);
    /* @4811260 cast */
    /* @4811264 bf */
    v38 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v38)) goto L_4811340;
    /* @4811268 constant */
    /* @4811272 cast */
    /* @4811276 constant */
    /* @4811280 cast */
    /* @4811284 constant */
    /* @4811288 cast */
    /* @4811292 load */
    /* @4811300 call */
    GM_SITE(vm, 522, 4811300);
    /* @4811308 load */
    /* @4811316 call */
    GM_SITE(vm, 522, 4811316);
    /* @4811324 call */
    GM_SITE(vm, 522, 4811324);
    v39 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v40 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4811332 cast */
    /* @4811336 b */
    v41 = BOOL(GM_CALL(vm, "collision_point", 5, v39, v40, VAL(127), VAL(0), VAL(0)));
    p4811344_0 = v41;
    goto L_4811344;
    L_4811340: ;
    /* @4811340 constant */
    p4811344_0 = VAL(0);
    L_4811344: ;
    /* @4811344 bf */
    if (!TRUTH(p4811344_0)) goto L_4811484;
    /* @4811348 constant */
    /* @4811352 constant */
    /* @4811356 constant */
    /* @4811360 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4811368 constant */
    /* @4811372 cast */
    /* @4811376 constant */
    /* @4811380 cast */
    /* @4811384 constant */
    /* @4811388 cast */
    /* @4811392 constant */
    /* @4811396 cast */
    /* @4811400 constant */
    /* @4811404 cast */
    /* @4811408 constant */
    /* @4811412 constant */
    /* @4811416 load */
    /* @4811424 constant */
    /* @4811428 add */
    /* @4811432 constant */
    /* @4811436 constant */
    /* @4811440 load */
    /* @4811448 constant */
    /* @4811452 add */
    /* @4811456 constant */
    /* @4811460 cast */
    /* @4811464 constant */
    /* @4811468 cast */
    /* @4811472 call */
    GM_SITE(vm, 522, 4811472);
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(445));
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4811480 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v42, v43, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4811484: ;
    /* @4811484 load */
    /* @4811492 constant */
    /* @4811496 add */
    /* @4811500 store */
    v44 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v44);
    /* @4811508 b */
    goto L_4811216;
    L_4811512: ;
    /* @4811512 load */
    /* @4811520 constant */
    /* @4811524 cmp */
    /* @4811528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4812060;
    /* @4811532 constant */
    /* @4811544 cast */
    /* @4811548 constant */
    /* @4811552 cast */
    /* @4811556 constant */
    /* @4811560 cast */
    /* @4811564 constant */
    /* @4811576 cast */
    /* @4811580 constant */
    /* @4811592 cast */
    /* @4811596 constant */
    /* @4811600 constant */
    /* @4811604 load */
    /* @4811612 constant */
    /* @4811616 add */
    /* @4811620 constant */
    /* @4811624 constant */
    /* @4811628 load */
    /* @4811636 constant */
    /* @4811640 add */
    /* @4811644 constant */
    /* @4811648 cast */
    /* @4811652 constant */
    /* @4811656 cast */
    /* @4811660 call */
    GM_SITE(vm, 522, 4811660);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4811668 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v45, v46, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4811672 constant */
    /* @4811676 constant */
    /* @4811680 load */
    /* @4811688 constant */
    /* @4811692 add */
    /* @4811696 store */
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    GM_WRITE(vm, -1, "x", v47);
    /* @4811704 constant */
    /* @4811708 constant */
    /* @4811712 load */
    /* @4811720 constant */
    /* @4811724 add */
    /* @4811728 store */
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v48);
    /* @4811736 constant */
    /* @4811740 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4811748: ;
    /* @4811748 load */
    /* @4811756 constant */
    /* @4811760 cmp */
    /* @4811764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4812060;
    /* @4811768 constant */
    /* @4811772 cast */
    /* @4811776 load */
    /* @4811784 call */
    GM_SITE(vm, 522, 4811784);
    /* @4811792 cast */
    /* @4811796 bf */
    v49 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v49)) goto L_4811872;
    /* @4811800 constant */
    /* @4811804 cast */
    /* @4811808 constant */
    /* @4811812 cast */
    /* @4811816 constant */
    /* @4811820 cast */
    /* @4811824 load */
    /* @4811832 call */
    GM_SITE(vm, 522, 4811832);
    /* @4811840 load */
    /* @4811848 call */
    GM_SITE(vm, 522, 4811848);
    /* @4811856 call */
    GM_SITE(vm, 522, 4811856);
    v50 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v51 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4811864 cast */
    /* @4811868 b */
    v52 = BOOL(GM_CALL(vm, "collision_point", 5, v50, v51, VAL(127), VAL(0), VAL(0)));
    p4811876_0 = v52;
    goto L_4811876;
    L_4811872: ;
    /* @4811872 constant */
    p4811876_0 = VAL(0);
    L_4811876: ;
    /* @4811876 bf */
    if (!TRUTH(p4811876_0)) goto L_4812032;
    /* @4811880 constant */
    /* @4811884 constant */
    /* @4811888 constant */
    /* @4811892 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4811900 constant */
    /* @4811904 cast */
    /* @4811908 constant */
    /* @4811912 cast */
    /* @4811916 constant */
    /* @4811920 cast */
    /* @4811924 constant */
    /* @4811936 cast */
    /* @4811940 constant */
    /* @4811952 cast */
    /* @4811956 constant */
    /* @4811960 constant */
    /* @4811964 load */
    /* @4811972 constant */
    /* @4811976 add */
    /* @4811980 constant */
    /* @4811984 constant */
    /* @4811988 load */
    /* @4811996 constant */
    /* @4812000 add */
    /* @4812004 constant */
    /* @4812008 cast */
    /* @4812012 constant */
    /* @4812016 cast */
    /* @4812020 call */
    GM_SITE(vm, 522, 4812020);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(380));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4812028 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v53, v54, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4812032: ;
    /* @4812032 load */
    /* @4812040 constant */
    /* @4812044 add */
    /* @4812048 store */
    v55 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v55);
    /* @4812056 b */
    goto L_4811748;
    L_4812060: ;
    /* @4812060 load */
    /* @4812068 constant */
    /* @4812072 cmp */
    /* @4812076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4812608;
    /* @4812080 constant */
    /* @4812092 cast */
    /* @4812096 constant */
    /* @4812100 cast */
    /* @4812104 constant */
    /* @4812108 cast */
    /* @4812112 constant */
    /* @4812124 cast */
    /* @4812128 constant */
    /* @4812140 cast */
    /* @4812144 constant */
    /* @4812148 constant */
    /* @4812152 load */
    /* @4812160 constant */
    /* @4812164 add */
    /* @4812168 constant */
    /* @4812172 constant */
    /* @4812176 load */
    /* @4812184 constant */
    /* @4812188 add */
    /* @4812192 constant */
    /* @4812196 cast */
    /* @4812200 constant */
    /* @4812204 cast */
    /* @4812208 call */
    GM_SITE(vm, 522, 4812208);
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4812216 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(0), v56, v57, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4812220 constant */
    /* @4812224 constant */
    /* @4812228 load */
    /* @4812236 constant */
    /* @4812240 add */
    /* @4812244 store */
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    GM_WRITE(vm, -1, "x", v58);
    /* @4812252 constant */
    /* @4812256 constant */
    /* @4812260 load */
    /* @4812268 constant */
    /* @4812272 add */
    /* @4812276 store */
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    GM_WRITE(vm, -1, "y", v59);
    /* @4812284 constant */
    /* @4812288 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4812296: ;
    /* @4812296 load */
    /* @4812304 constant */
    /* @4812308 cmp */
    /* @4812312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4812608;
    /* @4812316 constant */
    /* @4812320 cast */
    /* @4812324 load */
    /* @4812332 call */
    GM_SITE(vm, 522, 4812332);
    /* @4812340 cast */
    /* @4812344 bf */
    v60 = BOOL(GM_CALL(vm, "device_mouse_check_button_pressed", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v60)) goto L_4812420;
    /* @4812348 constant */
    /* @4812352 cast */
    /* @4812356 constant */
    /* @4812360 cast */
    /* @4812364 constant */
    /* @4812368 cast */
    /* @4812372 load */
    /* @4812380 call */
    GM_SITE(vm, 522, 4812380);
    /* @4812388 load */
    /* @4812396 call */
    GM_SITE(vm, 522, 4812396);
    /* @4812404 call */
    GM_SITE(vm, 522, 4812404);
    v61 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v62 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4812412 cast */
    /* @4812416 b */
    v63 = BOOL(GM_CALL(vm, "collision_point", 5, v61, v62, VAL(127), VAL(0), VAL(0)));
    p4812424_0 = v63;
    goto L_4812424;
    L_4812420: ;
    /* @4812420 constant */
    p4812424_0 = VAL(0);
    L_4812424: ;
    /* @4812424 bf */
    if (!TRUTH(p4812424_0)) goto L_4812580;
    /* @4812428 constant */
    /* @4812432 constant */
    /* @4812436 constant */
    /* @4812440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4812448 constant */
    /* @4812452 cast */
    /* @4812456 constant */
    /* @4812460 cast */
    /* @4812464 constant */
    /* @4812468 cast */
    /* @4812472 constant */
    /* @4812484 cast */
    /* @4812488 constant */
    /* @4812500 cast */
    /* @4812504 constant */
    /* @4812508 constant */
    /* @4812512 load */
    /* @4812520 constant */
    /* @4812524 add */
    /* @4812528 constant */
    /* @4812532 constant */
    /* @4812536 load */
    /* @4812544 constant */
    /* @4812548 add */
    /* @4812552 constant */
    /* @4812556 cast */
    /* @4812560 constant */
    /* @4812564 cast */
    /* @4812568 call */
    GM_SITE(vm, 522, 4812568);
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(410));
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4812576 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(155), VAL(1), v64, v65, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    L_4812580: ;
    /* @4812580 load */
    /* @4812588 constant */
    /* @4812592 add */
    /* @4812596 store */
    v66 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v66);
    /* @4812604 b */
    goto L_4812296;
    L_4812608: ;
    return;
}
