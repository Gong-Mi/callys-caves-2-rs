/* generated from CODE 533 (gml_Object_obj_rightbutton_Draw_0), source start 4829148, end 4836176. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0533(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val p4829512_0;
    Val v8;
    Val p4829540_0;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val p4829812_0;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val p4829996_0;
    Val v19;
    Val p4830024_0;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val p4830288_0;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val p4830696_0;
    Val v34;
    Val p4830724_0;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val v39;
    Val p4830996_0;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val p4831180_0;
    Val v45;
    Val p4831208_0;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val p4831472_0;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    Val v55;
    Val v56;
    Val v57;
    Val v58;
    Val v59;
    Val p4831884_0;
    Val v60;
    Val p4831912_0;
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val p4832168_0;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val p4832352_0;
    Val v71;
    Val p4832380_0;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val p4832628_0;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    Val v83;
    Val v84;
    Val v85;
    Val p4833020_0;
    Val v86;
    Val p4833048_0;
    Val v87;
    Val v88;
    Val v89;
    Val v90;
    Val v91;
    Val p4833304_0;
    Val v92;
    Val v93;
    Val v94;
    Val v95;
    Val v96;
    Val p4833488_0;
    Val v97;
    Val p4833516_0;
    Val v98;
    Val v99;
    Val v100;
    Val v101;
    Val v102;
    Val p4833764_0;
    Val v103;
    Val v104;
    Val v105;
    Val v106;
    Val v107;
    Val v108;
    Val v109;
    Val v110;
    Val v111;
    Val p4834172_0;
    Val v112;
    Val p4834200_0;
    Val v113;
    Val v114;
    Val v115;
    Val v116;
    Val v117;
    Val p4834472_0;
    Val v118;
    Val v119;
    Val v120;
    Val v121;
    Val v122;
    Val p4834656_0;
    Val v123;
    Val p4834684_0;
    Val v124;
    Val v125;
    Val v126;
    Val v127;
    Val v128;
    Val p4834948_0;
    Val v129;
    Val v130;
    Val v131;
    Val v132;
    Val v133;
    Val v134;
    Val v135;
    Val v136;
    Val v137;
    Val p4835356_0;
    Val v138;
    Val p4835384_0;
    Val v139;
    Val v140;
    Val v141;
    Val v142;
    Val v143;
    Val p4835656_0;
    Val v144;
    Val v145;
    Val v146;
    Val v147;
    Val v148;
    Val p4835840_0;
    Val v149;
    Val p4835868_0;
    Val v150;
    Val v151;
    Val v152;
    Val v153;
    Val v154;
    Val p4836132_0;
    Val v155;
    Val v156;
    /* @4829148 load */
    /* @4829156 constant */
    /* @4829160 cmp */
    /* @4829164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4830332;
    /* @4829168 constant */
    /* @4829180 cast */
    /* @4829184 constant */
    /* @4829188 cast */
    /* @4829192 constant */
    /* @4829196 cast */
    /* @4829200 constant */
    /* @4829212 cast */
    /* @4829216 constant */
    /* @4829228 cast */
    /* @4829232 constant */
    /* @4829236 constant */
    /* @4829240 load */
    /* @4829248 constant */
    /* @4829252 add */
    /* @4829256 constant */
    /* @4829260 constant */
    /* @4829264 load */
    /* @4829272 constant */
    /* @4829276 add */
    /* @4829280 constant */
    /* @4829284 cast */
    /* @4829288 constant */
    /* @4829292 cast */
    /* @4829296 call */
    GM_SITE(vm, 533, 4829296);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(86));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4829304 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v1, v2, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4829308 constant */
    /* @4829312 constant */
    /* @4829316 load */
    /* @4829324 constant */
    /* @4829328 add */
    /* @4829332 store */
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(88));
    GM_WRITE(vm, -1, "x", v3);
    /* @4829340 constant */
    /* @4829344 constant */
    /* @4829348 load */
    /* @4829356 constant */
    /* @4829360 add */
    /* @4829364 store */
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    GM_WRITE(vm, -1, "y", v4);
    /* @4829372 constant */
    /* @4829376 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4829384: ;
    /* @4829384 load */
    /* @4829392 constant */
    /* @4829396 cmp */
    /* @4829400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4829856;
    /* @4829404 constant */
    /* @4829408 cast */
    /* @4829412 load */
    /* @4829420 call */
    GM_SITE(vm, 533, 4829420);
    /* @4829428 cast */
    /* @4829432 bf */
    v5 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v5)) goto L_4829508;
    /* @4829436 constant */
    /* @4829440 cast */
    /* @4829444 constant */
    /* @4829448 cast */
    /* @4829452 constant */
    /* @4829456 cast */
    /* @4829460 load */
    /* @4829468 call */
    GM_SITE(vm, 533, 4829468);
    /* @4829476 load */
    /* @4829484 call */
    GM_SITE(vm, 533, 4829484);
    /* @4829492 call */
    GM_SITE(vm, 533, 4829492);
    v6 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v7 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4829500 cast */
    /* @4829504 b */
    v8 = BOOL(GM_CALL(vm, "collision_point", 5, v6, v7, VAL(131), VAL(0), VAL(0)));
    p4829512_0 = v8;
    goto L_4829512;
    L_4829508: ;
    /* @4829508 constant */
    p4829512_0 = VAL(0);
    L_4829512: ;
    /* @4829512 bf */
    if (!TRUTH(p4829512_0)) goto L_4829536;
    /* @4829516 load */
    /* @4829524 constant */
    /* @4829528 cmp */
    /* @4829532 b */
    p4829540_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4829540;
    L_4829536: ;
    /* @4829536 constant */
    p4829540_0 = VAL(0);
    L_4829540: ;
    /* @4829540 bf */
    if (!TRUTH(p4829540_0)) goto L_4829700;
    /* @4829544 constant */
    /* @4829548 constant */
    /* @4829552 constant */
    /* @4829556 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4829564 constant */
    /* @4829568 cast */
    /* @4829572 constant */
    /* @4829576 cast */
    /* @4829580 constant */
    /* @4829584 cast */
    /* @4829588 constant */
    /* @4829600 cast */
    /* @4829604 constant */
    /* @4829616 cast */
    /* @4829620 constant */
    /* @4829624 constant */
    /* @4829628 load */
    /* @4829636 constant */
    /* @4829640 add */
    /* @4829644 constant */
    /* @4829648 constant */
    /* @4829652 load */
    /* @4829660 constant */
    /* @4829664 add */
    /* @4829668 constant */
    /* @4829672 cast */
    /* @4829676 constant */
    /* @4829680 cast */
    /* @4829684 call */
    GM_SITE(vm, 533, 4829684);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(86));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4829692 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v9, v10, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4829696 b */
    goto L_4829828;
    L_4829700: ;
    /* @4829700 constant */
    /* @4829704 cast */
    /* @4829708 load */
    /* @4829716 call */
    GM_SITE(vm, 533, 4829716);
    /* @4829724 cast */
    /* @4829728 bf */
    v11 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v11)) goto L_4829808;
    /* @4829732 constant */
    /* @4829736 cast */
    /* @4829740 constant */
    /* @4829744 cast */
    /* @4829748 constant */
    /* @4829752 cast */
    /* @4829756 load */
    /* @4829764 call */
    GM_SITE(vm, 533, 4829764);
    /* @4829772 load */
    /* @4829780 call */
    GM_SITE(vm, 533, 4829780);
    /* @4829788 call */
    GM_SITE(vm, 533, 4829788);
    v12 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v13 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4829796 cast */
    /* @4829800 not */
    /* @4829804 b */
    v14 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v12, v13, VAL(131), VAL(0), VAL(0))));
    p4829812_0 = v14;
    goto L_4829812;
    L_4829808: ;
    /* @4829808 constant */
    p4829812_0 = VAL(0);
    L_4829812: ;
    /* @4829812 bf */
    if (!TRUTH(p4829812_0)) goto L_4829828;
    /* @4829816 constant */
    /* @4829820 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4829828: ;
    /* @4829828 load */
    /* @4829836 constant */
    /* @4829840 add */
    /* @4829844 store */
    v15 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v15);
    /* @4829852 b */
    goto L_4829384;
    L_4829856: ;
    /* @4829856 constant */
    /* @4829860 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4829868: ;
    /* @4829868 load */
    /* @4829876 constant */
    /* @4829880 cmp */
    /* @4829884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4830332;
    /* @4829888 constant */
    /* @4829892 cast */
    /* @4829896 load */
    /* @4829904 call */
    GM_SITE(vm, 533, 4829904);
    /* @4829912 cast */
    /* @4829916 bf */
    v16 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v16)) goto L_4829992;
    /* @4829920 constant */
    /* @4829924 cast */
    /* @4829928 constant */
    /* @4829932 cast */
    /* @4829936 constant */
    /* @4829940 cast */
    /* @4829944 load */
    /* @4829952 call */
    GM_SITE(vm, 533, 4829952);
    /* @4829960 load */
    /* @4829968 call */
    GM_SITE(vm, 533, 4829968);
    /* @4829976 call */
    GM_SITE(vm, 533, 4829976);
    v17 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v18 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4829984 cast */
    /* @4829988 b */
    v19 = BOOL(GM_CALL(vm, "collision_point", 5, v17, v18, VAL(131), VAL(0), VAL(0)));
    p4829996_0 = v19;
    goto L_4829996;
    L_4829992: ;
    /* @4829992 constant */
    p4829996_0 = VAL(0);
    L_4829996: ;
    /* @4829996 bf */
    if (!TRUTH(p4829996_0)) goto L_4830020;
    /* @4830000 load */
    /* @4830008 constant */
    /* @4830012 cmp */
    /* @4830016 b */
    p4830024_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4830024;
    L_4830020: ;
    /* @4830020 constant */
    p4830024_0 = VAL(0);
    L_4830024: ;
    /* @4830024 bf */
    if (!TRUTH(p4830024_0)) goto L_4830176;
    /* @4830028 constant */
    /* @4830032 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4830040 constant */
    /* @4830044 cast */
    /* @4830048 constant */
    /* @4830052 cast */
    /* @4830056 constant */
    /* @4830060 cast */
    /* @4830064 constant */
    /* @4830076 cast */
    /* @4830080 constant */
    /* @4830092 cast */
    /* @4830096 constant */
    /* @4830100 constant */
    /* @4830104 load */
    /* @4830112 constant */
    /* @4830116 add */
    /* @4830120 constant */
    /* @4830124 constant */
    /* @4830128 load */
    /* @4830136 constant */
    /* @4830140 add */
    /* @4830144 constant */
    /* @4830148 cast */
    /* @4830152 constant */
    /* @4830156 cast */
    /* @4830160 call */
    GM_SITE(vm, 533, 4830160);
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(86));
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4830168 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v20, v21, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4830172 b */
    goto L_4830304;
    L_4830176: ;
    /* @4830176 constant */
    /* @4830180 cast */
    /* @4830184 load */
    /* @4830192 call */
    GM_SITE(vm, 533, 4830192);
    /* @4830200 cast */
    /* @4830204 bf */
    v22 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v22)) goto L_4830284;
    /* @4830208 constant */
    /* @4830212 cast */
    /* @4830216 constant */
    /* @4830220 cast */
    /* @4830224 constant */
    /* @4830228 cast */
    /* @4830232 load */
    /* @4830240 call */
    GM_SITE(vm, 533, 4830240);
    /* @4830248 load */
    /* @4830256 call */
    GM_SITE(vm, 533, 4830256);
    /* @4830264 call */
    GM_SITE(vm, 533, 4830264);
    v23 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v24 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4830272 cast */
    /* @4830276 not */
    /* @4830280 b */
    v25 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v23, v24, VAL(131), VAL(0), VAL(0))));
    p4830288_0 = v25;
    goto L_4830288;
    L_4830284: ;
    /* @4830284 constant */
    p4830288_0 = VAL(0);
    L_4830288: ;
    /* @4830288 bf */
    if (!TRUTH(p4830288_0)) goto L_4830304;
    /* @4830292 constant */
    /* @4830296 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4830304: ;
    /* @4830304 load */
    /* @4830312 constant */
    /* @4830316 add */
    /* @4830320 store */
    v26 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v26);
    /* @4830328 b */
    goto L_4829868;
    L_4830332: ;
    /* @4830332 load */
    /* @4830340 constant */
    /* @4830344 cmp */
    /* @4830348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4831516;
    /* @4830352 constant */
    /* @4830364 cast */
    /* @4830368 constant */
    /* @4830372 cast */
    /* @4830376 constant */
    /* @4830380 cast */
    /* @4830384 constant */
    /* @4830396 cast */
    /* @4830400 constant */
    /* @4830412 cast */
    /* @4830416 constant */
    /* @4830420 constant */
    /* @4830424 load */
    /* @4830432 constant */
    /* @4830436 add */
    /* @4830440 constant */
    /* @4830444 constant */
    /* @4830448 load */
    /* @4830456 constant */
    /* @4830460 add */
    /* @4830464 constant */
    /* @4830468 cast */
    /* @4830472 constant */
    /* @4830476 cast */
    /* @4830480 call */
    GM_SITE(vm, 533, 4830480);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(77));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4830488 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v27, v28, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(0.6)));
    /* @4830492 constant */
    /* @4830496 constant */
    /* @4830500 load */
    /* @4830508 constant */
    /* @4830512 add */
    /* @4830516 store */
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(77));
    GM_WRITE(vm, -1, "x", v29);
    /* @4830524 constant */
    /* @4830528 constant */
    /* @4830532 load */
    /* @4830540 constant */
    /* @4830544 add */
    /* @4830548 store */
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    GM_WRITE(vm, -1, "y", v30);
    /* @4830556 constant */
    /* @4830560 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4830568: ;
    /* @4830568 load */
    /* @4830576 constant */
    /* @4830580 cmp */
    /* @4830584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4831040;
    /* @4830588 constant */
    /* @4830592 cast */
    /* @4830596 load */
    /* @4830604 call */
    GM_SITE(vm, 533, 4830604);
    /* @4830612 cast */
    /* @4830616 bf */
    v31 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v31)) goto L_4830692;
    /* @4830620 constant */
    /* @4830624 cast */
    /* @4830628 constant */
    /* @4830632 cast */
    /* @4830636 constant */
    /* @4830640 cast */
    /* @4830644 load */
    /* @4830652 call */
    GM_SITE(vm, 533, 4830652);
    /* @4830660 load */
    /* @4830668 call */
    GM_SITE(vm, 533, 4830668);
    /* @4830676 call */
    GM_SITE(vm, 533, 4830676);
    v32 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v33 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4830684 cast */
    /* @4830688 b */
    v34 = BOOL(GM_CALL(vm, "collision_point", 5, v32, v33, VAL(131), VAL(0), VAL(0)));
    p4830696_0 = v34;
    goto L_4830696;
    L_4830692: ;
    /* @4830692 constant */
    p4830696_0 = VAL(0);
    L_4830696: ;
    /* @4830696 bf */
    if (!TRUTH(p4830696_0)) goto L_4830720;
    /* @4830700 load */
    /* @4830708 constant */
    /* @4830712 cmp */
    /* @4830716 b */
    p4830724_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4830724;
    L_4830720: ;
    /* @4830720 constant */
    p4830724_0 = VAL(0);
    L_4830724: ;
    /* @4830724 bf */
    if (!TRUTH(p4830724_0)) goto L_4830884;
    /* @4830728 constant */
    /* @4830732 constant */
    /* @4830736 constant */
    /* @4830740 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4830748 constant */
    /* @4830752 cast */
    /* @4830756 constant */
    /* @4830760 cast */
    /* @4830764 constant */
    /* @4830768 cast */
    /* @4830772 constant */
    /* @4830784 cast */
    /* @4830788 constant */
    /* @4830800 cast */
    /* @4830804 constant */
    /* @4830808 constant */
    /* @4830812 load */
    /* @4830820 constant */
    /* @4830824 add */
    /* @4830828 constant */
    /* @4830832 constant */
    /* @4830836 load */
    /* @4830844 constant */
    /* @4830848 add */
    /* @4830852 constant */
    /* @4830856 cast */
    /* @4830860 constant */
    /* @4830864 cast */
    /* @4830868 call */
    GM_SITE(vm, 533, 4830868);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(77));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4830876 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v35, v36, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4830880 b */
    goto L_4831012;
    L_4830884: ;
    /* @4830884 constant */
    /* @4830888 cast */
    /* @4830892 load */
    /* @4830900 call */
    GM_SITE(vm, 533, 4830900);
    /* @4830908 cast */
    /* @4830912 bf */
    v37 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v37)) goto L_4830992;
    /* @4830916 constant */
    /* @4830920 cast */
    /* @4830924 constant */
    /* @4830928 cast */
    /* @4830932 constant */
    /* @4830936 cast */
    /* @4830940 load */
    /* @4830948 call */
    GM_SITE(vm, 533, 4830948);
    /* @4830956 load */
    /* @4830964 call */
    GM_SITE(vm, 533, 4830964);
    /* @4830972 call */
    GM_SITE(vm, 533, 4830972);
    v38 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v39 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4830980 cast */
    /* @4830984 not */
    /* @4830988 b */
    v40 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v38, v39, VAL(131), VAL(0), VAL(0))));
    p4830996_0 = v40;
    goto L_4830996;
    L_4830992: ;
    /* @4830992 constant */
    p4830996_0 = VAL(0);
    L_4830996: ;
    /* @4830996 bf */
    if (!TRUTH(p4830996_0)) goto L_4831012;
    /* @4831000 constant */
    /* @4831004 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4831012: ;
    /* @4831012 load */
    /* @4831020 constant */
    /* @4831024 add */
    /* @4831028 store */
    v41 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v41);
    /* @4831036 b */
    goto L_4830568;
    L_4831040: ;
    /* @4831040 constant */
    /* @4831044 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4831052: ;
    /* @4831052 load */
    /* @4831060 constant */
    /* @4831064 cmp */
    /* @4831068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4831516;
    /* @4831072 constant */
    /* @4831076 cast */
    /* @4831080 load */
    /* @4831088 call */
    GM_SITE(vm, 533, 4831088);
    /* @4831096 cast */
    /* @4831100 bf */
    v42 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v42)) goto L_4831176;
    /* @4831104 constant */
    /* @4831108 cast */
    /* @4831112 constant */
    /* @4831116 cast */
    /* @4831120 constant */
    /* @4831124 cast */
    /* @4831128 load */
    /* @4831136 call */
    GM_SITE(vm, 533, 4831136);
    /* @4831144 load */
    /* @4831152 call */
    GM_SITE(vm, 533, 4831152);
    /* @4831160 call */
    GM_SITE(vm, 533, 4831160);
    v43 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v44 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4831168 cast */
    /* @4831172 b */
    v45 = BOOL(GM_CALL(vm, "collision_point", 5, v43, v44, VAL(131), VAL(0), VAL(0)));
    p4831180_0 = v45;
    goto L_4831180;
    L_4831176: ;
    /* @4831176 constant */
    p4831180_0 = VAL(0);
    L_4831180: ;
    /* @4831180 bf */
    if (!TRUTH(p4831180_0)) goto L_4831204;
    /* @4831184 load */
    /* @4831192 constant */
    /* @4831196 cmp */
    /* @4831200 b */
    p4831208_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4831208;
    L_4831204: ;
    /* @4831204 constant */
    p4831208_0 = VAL(0);
    L_4831208: ;
    /* @4831208 bf */
    if (!TRUTH(p4831208_0)) goto L_4831360;
    /* @4831212 constant */
    /* @4831216 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4831224 constant */
    /* @4831228 cast */
    /* @4831232 constant */
    /* @4831236 cast */
    /* @4831240 constant */
    /* @4831244 cast */
    /* @4831248 constant */
    /* @4831260 cast */
    /* @4831264 constant */
    /* @4831276 cast */
    /* @4831280 constant */
    /* @4831284 constant */
    /* @4831288 load */
    /* @4831296 constant */
    /* @4831300 add */
    /* @4831304 constant */
    /* @4831308 constant */
    /* @4831312 load */
    /* @4831320 constant */
    /* @4831324 add */
    /* @4831328 constant */
    /* @4831332 cast */
    /* @4831336 constant */
    /* @4831340 cast */
    /* @4831344 call */
    GM_SITE(vm, 533, 4831344);
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(77));
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4831352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v46, v47, VAL(0.8), VAL(0.8), VAL(0), VAL(-1), VAL(1)));
    /* @4831356 b */
    goto L_4831488;
    L_4831360: ;
    /* @4831360 constant */
    /* @4831364 cast */
    /* @4831368 load */
    /* @4831376 call */
    GM_SITE(vm, 533, 4831376);
    /* @4831384 cast */
    /* @4831388 bf */
    v48 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v48)) goto L_4831468;
    /* @4831392 constant */
    /* @4831396 cast */
    /* @4831400 constant */
    /* @4831404 cast */
    /* @4831408 constant */
    /* @4831412 cast */
    /* @4831416 load */
    /* @4831424 call */
    GM_SITE(vm, 533, 4831424);
    /* @4831432 load */
    /* @4831440 call */
    GM_SITE(vm, 533, 4831440);
    /* @4831448 call */
    GM_SITE(vm, 533, 4831448);
    v49 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v50 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4831456 cast */
    /* @4831460 not */
    /* @4831464 b */
    v51 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v49, v50, VAL(131), VAL(0), VAL(0))));
    p4831472_0 = v51;
    goto L_4831472;
    L_4831468: ;
    /* @4831468 constant */
    p4831472_0 = VAL(0);
    L_4831472: ;
    /* @4831472 bf */
    if (!TRUTH(p4831472_0)) goto L_4831488;
    /* @4831476 constant */
    /* @4831480 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4831488: ;
    /* @4831488 load */
    /* @4831496 constant */
    /* @4831500 add */
    /* @4831504 store */
    v52 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v52);
    /* @4831512 b */
    goto L_4831052;
    L_4831516: ;
    /* @4831516 load */
    /* @4831524 constant */
    /* @4831528 cmp */
    /* @4831532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4831536;
    L_4831536: ;
    /* @4831536 load */
    /* @4831544 constant */
    /* @4831548 cmp */
    /* @4831552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4832672;
    /* @4831556 constant */
    /* @4831568 cast */
    /* @4831572 constant */
    /* @4831576 cast */
    /* @4831580 constant */
    /* @4831584 cast */
    /* @4831588 constant */
    /* @4831592 cast */
    /* @4831596 constant */
    /* @4831600 cast */
    /* @4831604 constant */
    /* @4831608 constant */
    /* @4831612 load */
    /* @4831620 constant */
    /* @4831624 add */
    /* @4831628 constant */
    /* @4831632 constant */
    /* @4831636 load */
    /* @4831644 constant */
    /* @4831648 add */
    /* @4831652 constant */
    /* @4831656 cast */
    /* @4831660 constant */
    /* @4831664 cast */
    /* @4831668 call */
    GM_SITE(vm, 533, 4831668);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(97));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4831676 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v53, v54, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4831680 constant */
    /* @4831684 constant */
    /* @4831688 load */
    /* @4831696 constant */
    /* @4831700 add */
    /* @4831704 store */
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(97));
    GM_WRITE(vm, -1, "x", v55);
    /* @4831712 constant */
    /* @4831716 constant */
    /* @4831720 load */
    /* @4831728 constant */
    /* @4831732 add */
    /* @4831736 store */
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    GM_WRITE(vm, -1, "y", v56);
    /* @4831744 constant */
    /* @4831748 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4831756: ;
    /* @4831756 load */
    /* @4831764 constant */
    /* @4831768 cmp */
    /* @4831772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4832212;
    /* @4831776 constant */
    /* @4831780 cast */
    /* @4831784 load */
    /* @4831792 call */
    GM_SITE(vm, 533, 4831792);
    /* @4831800 cast */
    /* @4831804 bf */
    v57 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v57)) goto L_4831880;
    /* @4831808 constant */
    /* @4831812 cast */
    /* @4831816 constant */
    /* @4831820 cast */
    /* @4831824 constant */
    /* @4831828 cast */
    /* @4831832 load */
    /* @4831840 call */
    GM_SITE(vm, 533, 4831840);
    /* @4831848 load */
    /* @4831856 call */
    GM_SITE(vm, 533, 4831856);
    /* @4831864 call */
    GM_SITE(vm, 533, 4831864);
    v58 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v59 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4831872 cast */
    /* @4831876 b */
    v60 = BOOL(GM_CALL(vm, "collision_point", 5, v58, v59, VAL(131), VAL(0), VAL(0)));
    p4831884_0 = v60;
    goto L_4831884;
    L_4831880: ;
    /* @4831880 constant */
    p4831884_0 = VAL(0);
    L_4831884: ;
    /* @4831884 bf */
    if (!TRUTH(p4831884_0)) goto L_4831908;
    /* @4831888 load */
    /* @4831896 constant */
    /* @4831900 cmp */
    /* @4831904 b */
    p4831912_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4831912;
    L_4831908: ;
    /* @4831908 constant */
    p4831912_0 = VAL(0);
    L_4831912: ;
    /* @4831912 bf */
    if (!TRUTH(p4831912_0)) goto L_4832056;
    /* @4831916 constant */
    /* @4831920 constant */
    /* @4831924 constant */
    /* @4831928 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4831936 constant */
    /* @4831940 cast */
    /* @4831944 constant */
    /* @4831948 cast */
    /* @4831952 constant */
    /* @4831956 cast */
    /* @4831960 constant */
    /* @4831964 cast */
    /* @4831968 constant */
    /* @4831972 cast */
    /* @4831976 constant */
    /* @4831980 constant */
    /* @4831984 load */
    /* @4831992 constant */
    /* @4831996 add */
    /* @4832000 constant */
    /* @4832004 constant */
    /* @4832008 load */
    /* @4832016 constant */
    /* @4832020 add */
    /* @4832024 constant */
    /* @4832028 cast */
    /* @4832032 constant */
    /* @4832036 cast */
    /* @4832040 call */
    GM_SITE(vm, 533, 4832040);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(97));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4832048 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v61, v62, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4832052 b */
    goto L_4832184;
    L_4832056: ;
    /* @4832056 constant */
    /* @4832060 cast */
    /* @4832064 load */
    /* @4832072 call */
    GM_SITE(vm, 533, 4832072);
    /* @4832080 cast */
    /* @4832084 bf */
    v63 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v63)) goto L_4832164;
    /* @4832088 constant */
    /* @4832092 cast */
    /* @4832096 constant */
    /* @4832100 cast */
    /* @4832104 constant */
    /* @4832108 cast */
    /* @4832112 load */
    /* @4832120 call */
    GM_SITE(vm, 533, 4832120);
    /* @4832128 load */
    /* @4832136 call */
    GM_SITE(vm, 533, 4832136);
    /* @4832144 call */
    GM_SITE(vm, 533, 4832144);
    v64 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v65 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4832152 cast */
    /* @4832156 not */
    /* @4832160 b */
    v66 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v64, v65, VAL(131), VAL(0), VAL(0))));
    p4832168_0 = v66;
    goto L_4832168;
    L_4832164: ;
    /* @4832164 constant */
    p4832168_0 = VAL(0);
    L_4832168: ;
    /* @4832168 bf */
    if (!TRUTH(p4832168_0)) goto L_4832184;
    /* @4832172 constant */
    /* @4832176 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4832184: ;
    /* @4832184 load */
    /* @4832192 constant */
    /* @4832196 add */
    /* @4832200 store */
    v67 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v67);
    /* @4832208 b */
    goto L_4831756;
    L_4832212: ;
    /* @4832212 constant */
    /* @4832216 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4832224: ;
    /* @4832224 load */
    /* @4832232 constant */
    /* @4832236 cmp */
    /* @4832240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4832672;
    /* @4832244 constant */
    /* @4832248 cast */
    /* @4832252 load */
    /* @4832260 call */
    GM_SITE(vm, 533, 4832260);
    /* @4832268 cast */
    /* @4832272 bf */
    v68 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v68)) goto L_4832348;
    /* @4832276 constant */
    /* @4832280 cast */
    /* @4832284 constant */
    /* @4832288 cast */
    /* @4832292 constant */
    /* @4832296 cast */
    /* @4832300 load */
    /* @4832308 call */
    GM_SITE(vm, 533, 4832308);
    /* @4832316 load */
    /* @4832324 call */
    GM_SITE(vm, 533, 4832324);
    /* @4832332 call */
    GM_SITE(vm, 533, 4832332);
    v69 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v70 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4832340 cast */
    /* @4832344 b */
    v71 = BOOL(GM_CALL(vm, "collision_point", 5, v69, v70, VAL(131), VAL(0), VAL(0)));
    p4832352_0 = v71;
    goto L_4832352;
    L_4832348: ;
    /* @4832348 constant */
    p4832352_0 = VAL(0);
    L_4832352: ;
    /* @4832352 bf */
    if (!TRUTH(p4832352_0)) goto L_4832376;
    /* @4832356 load */
    /* @4832364 constant */
    /* @4832368 cmp */
    /* @4832372 b */
    p4832380_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4832380;
    L_4832376: ;
    /* @4832376 constant */
    p4832380_0 = VAL(0);
    L_4832380: ;
    /* @4832380 bf */
    if (!TRUTH(p4832380_0)) goto L_4832516;
    /* @4832384 constant */
    /* @4832388 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4832396 constant */
    /* @4832400 cast */
    /* @4832404 constant */
    /* @4832408 cast */
    /* @4832412 constant */
    /* @4832416 cast */
    /* @4832420 constant */
    /* @4832424 cast */
    /* @4832428 constant */
    /* @4832432 cast */
    /* @4832436 constant */
    /* @4832440 constant */
    /* @4832444 load */
    /* @4832452 constant */
    /* @4832456 add */
    /* @4832460 constant */
    /* @4832464 constant */
    /* @4832468 load */
    /* @4832476 constant */
    /* @4832480 add */
    /* @4832484 constant */
    /* @4832488 cast */
    /* @4832492 constant */
    /* @4832496 cast */
    /* @4832500 call */
    GM_SITE(vm, 533, 4832500);
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(97));
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(310));
    /* @4832508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v72, v73, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4832512 b */
    goto L_4832644;
    L_4832516: ;
    /* @4832516 constant */
    /* @4832520 cast */
    /* @4832524 load */
    /* @4832532 call */
    GM_SITE(vm, 533, 4832532);
    /* @4832540 cast */
    /* @4832544 bf */
    v74 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v74)) goto L_4832624;
    /* @4832548 constant */
    /* @4832552 cast */
    /* @4832556 constant */
    /* @4832560 cast */
    /* @4832564 constant */
    /* @4832568 cast */
    /* @4832572 load */
    /* @4832580 call */
    GM_SITE(vm, 533, 4832580);
    /* @4832588 load */
    /* @4832596 call */
    GM_SITE(vm, 533, 4832596);
    /* @4832604 call */
    GM_SITE(vm, 533, 4832604);
    v75 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v76 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4832612 cast */
    /* @4832616 not */
    /* @4832620 b */
    v77 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v75, v76, VAL(131), VAL(0), VAL(0))));
    p4832628_0 = v77;
    goto L_4832628;
    L_4832624: ;
    /* @4832624 constant */
    p4832628_0 = VAL(0);
    L_4832628: ;
    /* @4832628 bf */
    if (!TRUTH(p4832628_0)) goto L_4832644;
    /* @4832632 constant */
    /* @4832636 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4832644: ;
    /* @4832644 load */
    /* @4832652 constant */
    /* @4832656 add */
    /* @4832660 store */
    v78 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v78);
    /* @4832668 b */
    goto L_4832224;
    L_4832672: ;
    /* @4832672 load */
    /* @4832680 constant */
    /* @4832684 cmp */
    /* @4832688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4833808;
    /* @4832692 constant */
    /* @4832704 cast */
    /* @4832708 constant */
    /* @4832712 cast */
    /* @4832716 constant */
    /* @4832720 cast */
    /* @4832724 constant */
    /* @4832728 cast */
    /* @4832732 constant */
    /* @4832736 cast */
    /* @4832740 constant */
    /* @4832744 constant */
    /* @4832748 load */
    /* @4832756 constant */
    /* @4832760 add */
    /* @4832764 constant */
    /* @4832768 constant */
    /* @4832772 load */
    /* @4832780 constant */
    /* @4832784 add */
    /* @4832788 constant */
    /* @4832792 cast */
    /* @4832796 constant */
    /* @4832800 cast */
    /* @4832804 call */
    GM_SITE(vm, 533, 4832804);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(97));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4832812 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v79, v80, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(0.6)));
    /* @4832816 constant */
    /* @4832820 constant */
    /* @4832824 load */
    /* @4832832 constant */
    /* @4832836 add */
    /* @4832840 store */
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(97));
    GM_WRITE(vm, -1, "x", v81);
    /* @4832848 constant */
    /* @4832852 constant */
    /* @4832856 load */
    /* @4832864 constant */
    /* @4832868 add */
    /* @4832872 store */
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    GM_WRITE(vm, -1, "y", v82);
    /* @4832880 constant */
    /* @4832884 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4832892: ;
    /* @4832892 load */
    /* @4832900 constant */
    /* @4832904 cmp */
    /* @4832908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4833348;
    /* @4832912 constant */
    /* @4832916 cast */
    /* @4832920 load */
    /* @4832928 call */
    GM_SITE(vm, 533, 4832928);
    /* @4832936 cast */
    /* @4832940 bf */
    v83 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v83)) goto L_4833016;
    /* @4832944 constant */
    /* @4832948 cast */
    /* @4832952 constant */
    /* @4832956 cast */
    /* @4832960 constant */
    /* @4832964 cast */
    /* @4832968 load */
    /* @4832976 call */
    GM_SITE(vm, 533, 4832976);
    /* @4832984 load */
    /* @4832992 call */
    GM_SITE(vm, 533, 4832992);
    /* @4833000 call */
    GM_SITE(vm, 533, 4833000);
    v84 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v85 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4833008 cast */
    /* @4833012 b */
    v86 = BOOL(GM_CALL(vm, "collision_point", 5, v84, v85, VAL(131), VAL(0), VAL(0)));
    p4833020_0 = v86;
    goto L_4833020;
    L_4833016: ;
    /* @4833016 constant */
    p4833020_0 = VAL(0);
    L_4833020: ;
    /* @4833020 bf */
    if (!TRUTH(p4833020_0)) goto L_4833044;
    /* @4833024 load */
    /* @4833032 constant */
    /* @4833036 cmp */
    /* @4833040 b */
    p4833048_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4833048;
    L_4833044: ;
    /* @4833044 constant */
    p4833048_0 = VAL(0);
    L_4833048: ;
    /* @4833048 bf */
    if (!TRUTH(p4833048_0)) goto L_4833192;
    /* @4833052 constant */
    /* @4833056 constant */
    /* @4833060 constant */
    /* @4833064 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4833072 constant */
    /* @4833076 cast */
    /* @4833080 constant */
    /* @4833084 cast */
    /* @4833088 constant */
    /* @4833092 cast */
    /* @4833096 constant */
    /* @4833100 cast */
    /* @4833104 constant */
    /* @4833108 cast */
    /* @4833112 constant */
    /* @4833116 constant */
    /* @4833120 load */
    /* @4833128 constant */
    /* @4833132 add */
    /* @4833136 constant */
    /* @4833140 constant */
    /* @4833144 load */
    /* @4833152 constant */
    /* @4833156 add */
    /* @4833160 constant */
    /* @4833164 cast */
    /* @4833168 constant */
    /* @4833172 cast */
    /* @4833176 call */
    GM_SITE(vm, 533, 4833176);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(97));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4833184 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v87, v88, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4833188 b */
    goto L_4833320;
    L_4833192: ;
    /* @4833192 constant */
    /* @4833196 cast */
    /* @4833200 load */
    /* @4833208 call */
    GM_SITE(vm, 533, 4833208);
    /* @4833216 cast */
    /* @4833220 bf */
    v89 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v89)) goto L_4833300;
    /* @4833224 constant */
    /* @4833228 cast */
    /* @4833232 constant */
    /* @4833236 cast */
    /* @4833240 constant */
    /* @4833244 cast */
    /* @4833248 load */
    /* @4833256 call */
    GM_SITE(vm, 533, 4833256);
    /* @4833264 load */
    /* @4833272 call */
    GM_SITE(vm, 533, 4833272);
    /* @4833280 call */
    GM_SITE(vm, 533, 4833280);
    v90 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v91 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4833288 cast */
    /* @4833292 not */
    /* @4833296 b */
    v92 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v90, v91, VAL(131), VAL(0), VAL(0))));
    p4833304_0 = v92;
    goto L_4833304;
    L_4833300: ;
    /* @4833300 constant */
    p4833304_0 = VAL(0);
    L_4833304: ;
    /* @4833304 bf */
    if (!TRUTH(p4833304_0)) goto L_4833320;
    /* @4833308 constant */
    /* @4833312 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4833320: ;
    /* @4833320 load */
    /* @4833328 constant */
    /* @4833332 add */
    /* @4833336 store */
    v93 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v93);
    /* @4833344 b */
    goto L_4832892;
    L_4833348: ;
    /* @4833348 constant */
    /* @4833352 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4833360: ;
    /* @4833360 load */
    /* @4833368 constant */
    /* @4833372 cmp */
    /* @4833376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4833808;
    /* @4833380 constant */
    /* @4833384 cast */
    /* @4833388 load */
    /* @4833396 call */
    GM_SITE(vm, 533, 4833396);
    /* @4833404 cast */
    /* @4833408 bf */
    v94 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v94)) goto L_4833484;
    /* @4833412 constant */
    /* @4833416 cast */
    /* @4833420 constant */
    /* @4833424 cast */
    /* @4833428 constant */
    /* @4833432 cast */
    /* @4833436 load */
    /* @4833444 call */
    GM_SITE(vm, 533, 4833444);
    /* @4833452 load */
    /* @4833460 call */
    GM_SITE(vm, 533, 4833460);
    /* @4833468 call */
    GM_SITE(vm, 533, 4833468);
    v95 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v96 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4833476 cast */
    /* @4833480 b */
    v97 = BOOL(GM_CALL(vm, "collision_point", 5, v95, v96, VAL(131), VAL(0), VAL(0)));
    p4833488_0 = v97;
    goto L_4833488;
    L_4833484: ;
    /* @4833484 constant */
    p4833488_0 = VAL(0);
    L_4833488: ;
    /* @4833488 bf */
    if (!TRUTH(p4833488_0)) goto L_4833512;
    /* @4833492 load */
    /* @4833500 constant */
    /* @4833504 cmp */
    /* @4833508 b */
    p4833516_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4833516;
    L_4833512: ;
    /* @4833512 constant */
    p4833516_0 = VAL(0);
    L_4833516: ;
    /* @4833516 bf */
    if (!TRUTH(p4833516_0)) goto L_4833652;
    /* @4833520 constant */
    /* @4833524 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4833532 constant */
    /* @4833536 cast */
    /* @4833540 constant */
    /* @4833544 cast */
    /* @4833548 constant */
    /* @4833552 cast */
    /* @4833556 constant */
    /* @4833560 cast */
    /* @4833564 constant */
    /* @4833568 cast */
    /* @4833572 constant */
    /* @4833576 constant */
    /* @4833580 load */
    /* @4833588 constant */
    /* @4833592 add */
    /* @4833596 constant */
    /* @4833600 constant */
    /* @4833604 load */
    /* @4833612 constant */
    /* @4833616 add */
    /* @4833620 constant */
    /* @4833624 cast */
    /* @4833628 constant */
    /* @4833632 cast */
    /* @4833636 call */
    GM_SITE(vm, 533, 4833636);
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(97));
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(310));
    /* @4833644 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v98, v99, VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    /* @4833648 b */
    goto L_4833780;
    L_4833652: ;
    /* @4833652 constant */
    /* @4833656 cast */
    /* @4833660 load */
    /* @4833668 call */
    GM_SITE(vm, 533, 4833668);
    /* @4833676 cast */
    /* @4833680 bf */
    v100 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v100)) goto L_4833760;
    /* @4833684 constant */
    /* @4833688 cast */
    /* @4833692 constant */
    /* @4833696 cast */
    /* @4833700 constant */
    /* @4833704 cast */
    /* @4833708 load */
    /* @4833716 call */
    GM_SITE(vm, 533, 4833716);
    /* @4833724 load */
    /* @4833732 call */
    GM_SITE(vm, 533, 4833732);
    /* @4833740 call */
    GM_SITE(vm, 533, 4833740);
    v101 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v102 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4833748 cast */
    /* @4833752 not */
    /* @4833756 b */
    v103 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v101, v102, VAL(131), VAL(0), VAL(0))));
    p4833764_0 = v103;
    goto L_4833764;
    L_4833760: ;
    /* @4833760 constant */
    p4833764_0 = VAL(0);
    L_4833764: ;
    /* @4833764 bf */
    if (!TRUTH(p4833764_0)) goto L_4833780;
    /* @4833768 constant */
    /* @4833772 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4833780: ;
    /* @4833780 load */
    /* @4833788 constant */
    /* @4833792 add */
    /* @4833796 store */
    v104 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v104);
    /* @4833804 b */
    goto L_4833360;
    L_4833808: ;
    /* @4833808 load */
    /* @4833816 constant */
    /* @4833820 cmp */
    /* @4833824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4834992;
    /* @4833828 constant */
    /* @4833840 cast */
    /* @4833844 constant */
    /* @4833848 cast */
    /* @4833852 constant */
    /* @4833856 cast */
    /* @4833860 constant */
    /* @4833872 cast */
    /* @4833876 constant */
    /* @4833888 cast */
    /* @4833892 constant */
    /* @4833896 constant */
    /* @4833900 load */
    /* @4833908 constant */
    /* @4833912 add */
    /* @4833916 constant */
    /* @4833920 constant */
    /* @4833924 load */
    /* @4833932 constant */
    /* @4833936 add */
    /* @4833940 constant */
    /* @4833944 cast */
    /* @4833948 constant */
    /* @4833952 cast */
    /* @4833956 call */
    GM_SITE(vm, 533, 4833956);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(86));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4833964 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v105, v106, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4833968 constant */
    /* @4833972 constant */
    /* @4833976 load */
    /* @4833984 constant */
    /* @4833988 add */
    /* @4833992 store */
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(88));
    GM_WRITE(vm, -1, "x", v107);
    /* @4834000 constant */
    /* @4834004 constant */
    /* @4834008 load */
    /* @4834016 constant */
    /* @4834020 add */
    /* @4834024 store */
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    GM_WRITE(vm, -1, "y", v108);
    /* @4834032 constant */
    /* @4834036 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4834044: ;
    /* @4834044 load */
    /* @4834052 constant */
    /* @4834056 cmp */
    /* @4834060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4834516;
    /* @4834064 constant */
    /* @4834068 cast */
    /* @4834072 load */
    /* @4834080 call */
    GM_SITE(vm, 533, 4834080);
    /* @4834088 cast */
    /* @4834092 bf */
    v109 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v109)) goto L_4834168;
    /* @4834096 constant */
    /* @4834100 cast */
    /* @4834104 constant */
    /* @4834108 cast */
    /* @4834112 constant */
    /* @4834116 cast */
    /* @4834120 load */
    /* @4834128 call */
    GM_SITE(vm, 533, 4834128);
    /* @4834136 load */
    /* @4834144 call */
    GM_SITE(vm, 533, 4834144);
    /* @4834152 call */
    GM_SITE(vm, 533, 4834152);
    v110 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v111 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4834160 cast */
    /* @4834164 b */
    v112 = BOOL(GM_CALL(vm, "collision_point", 5, v110, v111, VAL(131), VAL(0), VAL(0)));
    p4834172_0 = v112;
    goto L_4834172;
    L_4834168: ;
    /* @4834168 constant */
    p4834172_0 = VAL(0);
    L_4834172: ;
    /* @4834172 bf */
    if (!TRUTH(p4834172_0)) goto L_4834196;
    /* @4834176 load */
    /* @4834184 constant */
    /* @4834188 cmp */
    /* @4834192 b */
    p4834200_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4834200;
    L_4834196: ;
    /* @4834196 constant */
    p4834200_0 = VAL(0);
    L_4834200: ;
    /* @4834200 bf */
    if (!TRUTH(p4834200_0)) goto L_4834360;
    /* @4834204 constant */
    /* @4834208 constant */
    /* @4834212 constant */
    /* @4834216 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4834224 constant */
    /* @4834228 cast */
    /* @4834232 constant */
    /* @4834236 cast */
    /* @4834240 constant */
    /* @4834244 cast */
    /* @4834248 constant */
    /* @4834260 cast */
    /* @4834264 constant */
    /* @4834276 cast */
    /* @4834280 constant */
    /* @4834284 constant */
    /* @4834288 load */
    /* @4834296 constant */
    /* @4834300 add */
    /* @4834304 constant */
    /* @4834308 constant */
    /* @4834312 load */
    /* @4834320 constant */
    /* @4834324 add */
    /* @4834328 constant */
    /* @4834332 cast */
    /* @4834336 constant */
    /* @4834340 cast */
    /* @4834344 call */
    GM_SITE(vm, 533, 4834344);
    v113 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(86));
    v114 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4834352 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v113, v114, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4834356 b */
    goto L_4834488;
    L_4834360: ;
    /* @4834360 constant */
    /* @4834364 cast */
    /* @4834368 load */
    /* @4834376 call */
    GM_SITE(vm, 533, 4834376);
    /* @4834384 cast */
    /* @4834388 bf */
    v115 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v115)) goto L_4834468;
    /* @4834392 constant */
    /* @4834396 cast */
    /* @4834400 constant */
    /* @4834404 cast */
    /* @4834408 constant */
    /* @4834412 cast */
    /* @4834416 load */
    /* @4834424 call */
    GM_SITE(vm, 533, 4834424);
    /* @4834432 load */
    /* @4834440 call */
    GM_SITE(vm, 533, 4834440);
    /* @4834448 call */
    GM_SITE(vm, 533, 4834448);
    v116 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v117 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4834456 cast */
    /* @4834460 not */
    /* @4834464 b */
    v118 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v116, v117, VAL(131), VAL(0), VAL(0))));
    p4834472_0 = v118;
    goto L_4834472;
    L_4834468: ;
    /* @4834468 constant */
    p4834472_0 = VAL(0);
    L_4834472: ;
    /* @4834472 bf */
    if (!TRUTH(p4834472_0)) goto L_4834488;
    /* @4834476 constant */
    /* @4834480 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4834488: ;
    /* @4834488 load */
    /* @4834496 constant */
    /* @4834500 add */
    /* @4834504 store */
    v119 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v119);
    /* @4834512 b */
    goto L_4834044;
    L_4834516: ;
    /* @4834516 constant */
    /* @4834520 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4834528: ;
    /* @4834528 load */
    /* @4834536 constant */
    /* @4834540 cmp */
    /* @4834544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4834992;
    /* @4834548 constant */
    /* @4834552 cast */
    /* @4834556 load */
    /* @4834564 call */
    GM_SITE(vm, 533, 4834564);
    /* @4834572 cast */
    /* @4834576 bf */
    v120 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v120)) goto L_4834652;
    /* @4834580 constant */
    /* @4834584 cast */
    /* @4834588 constant */
    /* @4834592 cast */
    /* @4834596 constant */
    /* @4834600 cast */
    /* @4834604 load */
    /* @4834612 call */
    GM_SITE(vm, 533, 4834612);
    /* @4834620 load */
    /* @4834628 call */
    GM_SITE(vm, 533, 4834628);
    /* @4834636 call */
    GM_SITE(vm, 533, 4834636);
    v121 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v122 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4834644 cast */
    /* @4834648 b */
    v123 = BOOL(GM_CALL(vm, "collision_point", 5, v121, v122, VAL(131), VAL(0), VAL(0)));
    p4834656_0 = v123;
    goto L_4834656;
    L_4834652: ;
    /* @4834652 constant */
    p4834656_0 = VAL(0);
    L_4834656: ;
    /* @4834656 bf */
    if (!TRUTH(p4834656_0)) goto L_4834680;
    /* @4834660 load */
    /* @4834668 constant */
    /* @4834672 cmp */
    /* @4834676 b */
    p4834684_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4834684;
    L_4834680: ;
    /* @4834680 constant */
    p4834684_0 = VAL(0);
    L_4834684: ;
    /* @4834684 bf */
    if (!TRUTH(p4834684_0)) goto L_4834836;
    /* @4834688 constant */
    /* @4834692 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4834700 constant */
    /* @4834704 cast */
    /* @4834708 constant */
    /* @4834712 cast */
    /* @4834716 constant */
    /* @4834720 cast */
    /* @4834724 constant */
    /* @4834736 cast */
    /* @4834740 constant */
    /* @4834752 cast */
    /* @4834756 constant */
    /* @4834760 constant */
    /* @4834764 load */
    /* @4834772 constant */
    /* @4834776 add */
    /* @4834780 constant */
    /* @4834784 constant */
    /* @4834788 load */
    /* @4834796 constant */
    /* @4834800 add */
    /* @4834804 constant */
    /* @4834808 cast */
    /* @4834812 constant */
    /* @4834816 cast */
    /* @4834820 call */
    GM_SITE(vm, 533, 4834820);
    v124 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(86));
    v125 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4834828 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v124, v125, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4834832 b */
    goto L_4834964;
    L_4834836: ;
    /* @4834836 constant */
    /* @4834840 cast */
    /* @4834844 load */
    /* @4834852 call */
    GM_SITE(vm, 533, 4834852);
    /* @4834860 cast */
    /* @4834864 bf */
    v126 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v126)) goto L_4834944;
    /* @4834868 constant */
    /* @4834872 cast */
    /* @4834876 constant */
    /* @4834880 cast */
    /* @4834884 constant */
    /* @4834888 cast */
    /* @4834892 load */
    /* @4834900 call */
    GM_SITE(vm, 533, 4834900);
    /* @4834908 load */
    /* @4834916 call */
    GM_SITE(vm, 533, 4834916);
    /* @4834924 call */
    GM_SITE(vm, 533, 4834924);
    v127 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v128 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4834932 cast */
    /* @4834936 not */
    /* @4834940 b */
    v129 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v127, v128, VAL(131), VAL(0), VAL(0))));
    p4834948_0 = v129;
    goto L_4834948;
    L_4834944: ;
    /* @4834944 constant */
    p4834948_0 = VAL(0);
    L_4834948: ;
    /* @4834948 bf */
    if (!TRUTH(p4834948_0)) goto L_4834964;
    /* @4834952 constant */
    /* @4834956 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4834964: ;
    /* @4834964 load */
    /* @4834972 constant */
    /* @4834976 add */
    /* @4834980 store */
    v130 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v130);
    /* @4834988 b */
    goto L_4834528;
    L_4834992: ;
    /* @4834992 load */
    /* @4835000 constant */
    /* @4835004 cmp */
    /* @4835008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4836176;
    /* @4835012 constant */
    /* @4835024 cast */
    /* @4835028 constant */
    /* @4835032 cast */
    /* @4835036 constant */
    /* @4835040 cast */
    /* @4835044 constant */
    /* @4835056 cast */
    /* @4835060 constant */
    /* @4835072 cast */
    /* @4835076 constant */
    /* @4835080 constant */
    /* @4835084 load */
    /* @4835092 constant */
    /* @4835096 add */
    /* @4835100 constant */
    /* @4835104 constant */
    /* @4835108 load */
    /* @4835116 constant */
    /* @4835120 add */
    /* @4835124 constant */
    /* @4835128 cast */
    /* @4835132 constant */
    /* @4835136 cast */
    /* @4835140 call */
    GM_SITE(vm, 533, 4835140);
    v131 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(86));
    v132 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4835148 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v131, v132, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(0.6)));
    /* @4835152 constant */
    /* @4835156 constant */
    /* @4835160 load */
    /* @4835168 constant */
    /* @4835172 add */
    /* @4835176 store */
    v133 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(88));
    GM_WRITE(vm, -1, "x", v133);
    /* @4835184 constant */
    /* @4835188 constant */
    /* @4835192 load */
    /* @4835200 constant */
    /* @4835204 add */
    /* @4835208 store */
    v134 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    GM_WRITE(vm, -1, "y", v134);
    /* @4835216 constant */
    /* @4835220 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4835228: ;
    /* @4835228 load */
    /* @4835236 constant */
    /* @4835240 cmp */
    /* @4835244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4835700;
    /* @4835248 constant */
    /* @4835252 cast */
    /* @4835256 load */
    /* @4835264 call */
    GM_SITE(vm, 533, 4835264);
    /* @4835272 cast */
    /* @4835276 bf */
    v135 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v135)) goto L_4835352;
    /* @4835280 constant */
    /* @4835284 cast */
    /* @4835288 constant */
    /* @4835292 cast */
    /* @4835296 constant */
    /* @4835300 cast */
    /* @4835304 load */
    /* @4835312 call */
    GM_SITE(vm, 533, 4835312);
    /* @4835320 load */
    /* @4835328 call */
    GM_SITE(vm, 533, 4835328);
    /* @4835336 call */
    GM_SITE(vm, 533, 4835336);
    v136 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v137 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4835344 cast */
    /* @4835348 b */
    v138 = BOOL(GM_CALL(vm, "collision_point", 5, v136, v137, VAL(131), VAL(0), VAL(0)));
    p4835356_0 = v138;
    goto L_4835356;
    L_4835352: ;
    /* @4835352 constant */
    p4835356_0 = VAL(0);
    L_4835356: ;
    /* @4835356 bf */
    if (!TRUTH(p4835356_0)) goto L_4835380;
    /* @4835360 load */
    /* @4835368 constant */
    /* @4835372 cmp */
    /* @4835376 b */
    p4835384_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4835384;
    L_4835380: ;
    /* @4835380 constant */
    p4835384_0 = VAL(0);
    L_4835384: ;
    /* @4835384 bf */
    if (!TRUTH(p4835384_0)) goto L_4835544;
    /* @4835388 constant */
    /* @4835392 constant */
    /* @4835396 constant */
    /* @4835400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4835408 constant */
    /* @4835412 cast */
    /* @4835416 constant */
    /* @4835420 cast */
    /* @4835424 constant */
    /* @4835428 cast */
    /* @4835432 constant */
    /* @4835444 cast */
    /* @4835448 constant */
    /* @4835460 cast */
    /* @4835464 constant */
    /* @4835468 constant */
    /* @4835472 load */
    /* @4835480 constant */
    /* @4835484 add */
    /* @4835488 constant */
    /* @4835492 constant */
    /* @4835496 load */
    /* @4835504 constant */
    /* @4835508 add */
    /* @4835512 constant */
    /* @4835516 cast */
    /* @4835520 constant */
    /* @4835524 cast */
    /* @4835528 call */
    GM_SITE(vm, 533, 4835528);
    v139 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(86));
    v140 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4835536 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(1), v139, v140, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4835540 b */
    goto L_4835672;
    L_4835544: ;
    /* @4835544 constant */
    /* @4835548 cast */
    /* @4835552 load */
    /* @4835560 call */
    GM_SITE(vm, 533, 4835560);
    /* @4835568 cast */
    /* @4835572 bf */
    v141 = BOOL(GM_CALL(vm, "device_mouse_check_button", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v141)) goto L_4835652;
    /* @4835576 constant */
    /* @4835580 cast */
    /* @4835584 constant */
    /* @4835588 cast */
    /* @4835592 constant */
    /* @4835596 cast */
    /* @4835600 load */
    /* @4835608 call */
    GM_SITE(vm, 533, 4835608);
    /* @4835616 load */
    /* @4835624 call */
    GM_SITE(vm, 533, 4835624);
    /* @4835632 call */
    GM_SITE(vm, 533, 4835632);
    v142 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v143 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4835640 cast */
    /* @4835644 not */
    /* @4835648 b */
    v144 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v142, v143, VAL(131), VAL(0), VAL(0))));
    p4835656_0 = v144;
    goto L_4835656;
    L_4835652: ;
    /* @4835652 constant */
    p4835656_0 = VAL(0);
    L_4835656: ;
    /* @4835656 bf */
    if (!TRUTH(p4835656_0)) goto L_4835672;
    /* @4835660 constant */
    /* @4835664 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4835672: ;
    /* @4835672 load */
    /* @4835680 constant */
    /* @4835684 add */
    /* @4835688 store */
    v145 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v145);
    /* @4835696 b */
    goto L_4835228;
    L_4835700: ;
    /* @4835700 constant */
    /* @4835704 store */
    GM_WRITE(vm, -1, "i", VAL(0));
    L_4835712: ;
    /* @4835712 load */
    /* @4835720 constant */
    /* @4835724 cmp */
    /* @4835728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "i") <= VAL(4)))) goto L_4836176;
    /* @4835732 constant */
    /* @4835736 cast */
    /* @4835740 load */
    /* @4835748 call */
    GM_SITE(vm, 533, 4835748);
    /* @4835756 cast */
    /* @4835760 bf */
    v146 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v146)) goto L_4835836;
    /* @4835764 constant */
    /* @4835768 cast */
    /* @4835772 constant */
    /* @4835776 cast */
    /* @4835780 constant */
    /* @4835784 cast */
    /* @4835788 load */
    /* @4835796 call */
    GM_SITE(vm, 533, 4835796);
    /* @4835804 load */
    /* @4835812 call */
    GM_SITE(vm, 533, 4835812);
    /* @4835820 call */
    GM_SITE(vm, 533, 4835820);
    v147 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v148 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4835828 cast */
    /* @4835832 b */
    v149 = BOOL(GM_CALL(vm, "collision_point", 5, v147, v148, VAL(131), VAL(0), VAL(0)));
    p4835840_0 = v149;
    goto L_4835840;
    L_4835836: ;
    /* @4835836 constant */
    p4835840_0 = VAL(0);
    L_4835840: ;
    /* @4835840 bf */
    if (!TRUTH(p4835840_0)) goto L_4835864;
    /* @4835844 load */
    /* @4835852 constant */
    /* @4835856 cmp */
    /* @4835860 b */
    p4835868_0 = NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1));
    goto L_4835868;
    L_4835864: ;
    /* @4835864 constant */
    p4835868_0 = VAL(0);
    L_4835868: ;
    /* @4835868 bf */
    if (!TRUTH(p4835868_0)) goto L_4836020;
    /* @4835872 constant */
    /* @4835876 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    /* @4835884 constant */
    /* @4835888 cast */
    /* @4835892 constant */
    /* @4835896 cast */
    /* @4835900 constant */
    /* @4835904 cast */
    /* @4835908 constant */
    /* @4835920 cast */
    /* @4835924 constant */
    /* @4835936 cast */
    /* @4835940 constant */
    /* @4835944 constant */
    /* @4835948 load */
    /* @4835956 constant */
    /* @4835960 add */
    /* @4835964 constant */
    /* @4835968 constant */
    /* @4835972 load */
    /* @4835980 constant */
    /* @4835984 add */
    /* @4835988 constant */
    /* @4835992 cast */
    /* @4835996 constant */
    /* @4836000 cast */
    /* @4836004 call */
    GM_SITE(vm, 533, 4836004);
    v150 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(86));
    v151 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(210));
    /* @4836012 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(159), VAL(0), v150, v151, VAL(0.9), VAL(0.9), VAL(0), VAL(-1), VAL(1)));
    /* @4836016 b */
    goto L_4836148;
    L_4836020: ;
    /* @4836020 constant */
    /* @4836024 cast */
    /* @4836028 load */
    /* @4836036 call */
    GM_SITE(vm, 533, 4836036);
    /* @4836044 cast */
    /* @4836048 bf */
    v152 = BOOL(GM_CALL(vm, "device_mouse_check_button_released", 2, GM_READ(vm, -1, "i"), VAL(1)));
    if (!TRUTH(v152)) goto L_4836128;
    /* @4836052 constant */
    /* @4836056 cast */
    /* @4836060 constant */
    /* @4836064 cast */
    /* @4836068 constant */
    /* @4836072 cast */
    /* @4836076 load */
    /* @4836084 call */
    GM_SITE(vm, 533, 4836084);
    /* @4836092 load */
    /* @4836100 call */
    GM_SITE(vm, 533, 4836100);
    /* @4836108 call */
    GM_SITE(vm, 533, 4836108);
    v153 = GM_CALL(vm, "device_mouse_x", 1, GM_READ(vm, -1, "i"));
    v154 = GM_CALL(vm, "device_mouse_y", 1, GM_READ(vm, -1, "i"));
    /* @4836116 cast */
    /* @4836120 not */
    /* @4836124 b */
    v155 = NOT(BOOL(GM_CALL(vm, "collision_point", 5, v153, v154, VAL(131), VAL(0), VAL(0))));
    p4836132_0 = v155;
    goto L_4836132;
    L_4836128: ;
    /* @4836128 constant */
    p4836132_0 = VAL(0);
    L_4836132: ;
    /* @4836132 bf */
    if (!TRUTH(p4836132_0)) goto L_4836148;
    /* @4836136 constant */
    /* @4836140 store */
    GM_WRITE(vm, 0, "hsp", VAL(0));
    L_4836148: ;
    /* @4836148 load */
    /* @4836156 constant */
    /* @4836160 add */
    /* @4836164 store */
    v156 = GM_ADD(GM_READ(vm, -1, "i"), VAL(1));
    GM_WRITE(vm, -1, "i", v156);
    /* @4836172 b */
    goto L_4835712;
    L_4836176: ;
    return;
}
