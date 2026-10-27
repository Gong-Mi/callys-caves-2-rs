/* generated from CODE 507 (gml_Object_obj_pause_Create_0), source start 4699820, end 4703684. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0507(GmVM* vm) {
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
    Val v85;
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
    Val v98;
    Val v99;
    Val v100;
    Val v101;
    Val v102;
    Val v103;
    Val v104;
    Val v105;
    Val v106;
    Val v107;
    Val v108;
    /* @4699820 constant */
    /* @4699824 store */
    GM_WRITE(vm, -5, "storemenu", VAL(1));
    /* @4699832 constant */
    /* @4699836 cast */
    /* @4699840 call */
    GM_SITE(vm, 507, 4699840);
    /* @4699848 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4699852 constant */
    /* @4699856 cast */
    /* @4699860 call */
    GM_SITE(vm, 507, 4699860);
    /* @4699868 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4699872 constant */
    /* @4699876 cast */
    /* @4699880 call */
    GM_SITE(vm, 507, 4699880);
    /* @4699888 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(133)));
    /* @4699892 load */
    /* @4699900 constant */
    /* @4699904 cmp */
    /* @4699908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4700524;
    /* @4699912 constant */
    /* @4699916 cast */
    /* @4699920 constant */
    /* @4699924 constant */
    /* @4699928 load */
    /* @4699936 constant */
    /* @4699940 add */
    /* @4699944 constant */
    /* @4699948 constant */
    /* @4699952 load */
    /* @4699960 constant */
    /* @4699964 add */
    /* @4699968 call */
    GM_SITE(vm, 507, 4699968);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(30));
    /* @4699976 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, v2, VAL(99)));
    /* @4699980 constant */
    /* @4699984 cast */
    /* @4699988 constant */
    /* @4699992 constant */
    /* @4699996 load */
    /* @4700004 constant */
    /* @4700008 add */
    /* @4700012 constant */
    /* @4700016 constant */
    /* @4700020 load */
    /* @4700028 constant */
    /* @4700032 add */
    /* @4700036 call */
    GM_SITE(vm, 507, 4700036);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(70));
    /* @4700044 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, v4, VAL(96)));
    /* @4700048 constant */
    /* @4700052 cast */
    /* @4700056 constant */
    /* @4700060 constant */
    /* @4700064 load */
    /* @4700072 constant */
    /* @4700076 add */
    /* @4700080 constant */
    /* @4700084 constant */
    /* @4700088 load */
    /* @4700096 constant */
    /* @4700100 add */
    /* @4700104 call */
    GM_SITE(vm, 507, 4700104);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(110));
    /* @4700112 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v5, v6, VAL(87)));
    /* @4700116 constant */
    /* @4700120 cast */
    /* @4700124 constant */
    /* @4700128 constant */
    /* @4700132 load */
    /* @4700140 constant */
    /* @4700144 add */
    /* @4700148 constant */
    /* @4700152 constant */
    /* @4700156 load */
    /* @4700164 constant */
    /* @4700168 add */
    /* @4700172 call */
    GM_SITE(vm, 507, 4700172);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4700180 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v7, v8, VAL(84)));
    /* @4700184 constant */
    /* @4700188 cast */
    /* @4700192 constant */
    /* @4700196 constant */
    /* @4700200 load */
    /* @4700208 constant */
    /* @4700212 add */
    /* @4700216 constant */
    /* @4700220 constant */
    /* @4700224 load */
    /* @4700232 constant */
    /* @4700236 add */
    /* @4700240 call */
    GM_SITE(vm, 507, 4700240);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(30));
    /* @4700248 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v9, v10, VAL(88)));
    /* @4700252 constant */
    /* @4700256 cast */
    /* @4700260 constant */
    /* @4700264 constant */
    /* @4700268 load */
    /* @4700276 constant */
    /* @4700280 add */
    /* @4700284 constant */
    /* @4700288 constant */
    /* @4700292 load */
    /* @4700300 constant */
    /* @4700304 add */
    /* @4700308 call */
    GM_SITE(vm, 507, 4700308);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(70));
    /* @4700316 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v11, v12, VAL(93)));
    /* @4700320 constant */
    /* @4700324 cast */
    /* @4700328 constant */
    /* @4700332 constant */
    /* @4700336 load */
    /* @4700344 constant */
    /* @4700348 add */
    /* @4700352 constant */
    /* @4700356 constant */
    /* @4700360 load */
    /* @4700368 constant */
    /* @4700372 add */
    /* @4700376 call */
    GM_SITE(vm, 507, 4700376);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(110));
    /* @4700384 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v13, v14, VAL(89)));
    /* @4700388 constant */
    /* @4700392 cast */
    /* @4700396 constant */
    /* @4700400 constant */
    /* @4700404 load */
    /* @4700412 constant */
    /* @4700416 add */
    /* @4700420 constant */
    /* @4700424 constant */
    /* @4700428 load */
    /* @4700436 constant */
    /* @4700440 add */
    /* @4700444 call */
    GM_SITE(vm, 507, 4700444);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4700452 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v15, v16, VAL(92)));
    /* @4700456 constant */
    /* @4700460 cast */
    /* @4700464 constant */
    /* @4700468 constant */
    /* @4700472 load */
    /* @4700480 constant */
    /* @4700484 add */
    /* @4700488 constant */
    /* @4700492 constant */
    /* @4700496 load */
    /* @4700504 constant */
    /* @4700508 add */
    /* @4700512 call */
    GM_SITE(vm, 507, 4700512);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(150));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4700520 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v17, v18, VAL(116)));
    L_4700524: ;
    /* @4700524 load */
    /* @4700532 constant */
    /* @4700536 cmp */
    /* @4700540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4701156;
    /* @4700544 constant */
    /* @4700548 cast */
    /* @4700552 constant */
    /* @4700556 constant */
    /* @4700560 load */
    /* @4700568 constant */
    /* @4700572 add */
    /* @4700576 constant */
    /* @4700580 constant */
    /* @4700584 load */
    /* @4700592 constant */
    /* @4700596 add */
    /* @4700600 call */
    GM_SITE(vm, 507, 4700600);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    /* @4700608 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v19, v20, VAL(99)));
    /* @4700612 constant */
    /* @4700616 cast */
    /* @4700620 constant */
    /* @4700624 constant */
    /* @4700628 load */
    /* @4700636 constant */
    /* @4700640 add */
    /* @4700644 constant */
    /* @4700648 constant */
    /* @4700652 load */
    /* @4700660 constant */
    /* @4700664 add */
    /* @4700668 call */
    GM_SITE(vm, 507, 4700668);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    /* @4700676 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v21, v22, VAL(96)));
    /* @4700680 constant */
    /* @4700684 cast */
    /* @4700688 constant */
    /* @4700692 constant */
    /* @4700696 load */
    /* @4700704 constant */
    /* @4700708 add */
    /* @4700712 constant */
    /* @4700716 constant */
    /* @4700720 load */
    /* @4700728 constant */
    /* @4700732 add */
    /* @4700736 call */
    GM_SITE(vm, 507, 4700736);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @4700744 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v23, v24, VAL(87)));
    /* @4700748 constant */
    /* @4700752 cast */
    /* @4700756 constant */
    /* @4700760 constant */
    /* @4700764 load */
    /* @4700772 constant */
    /* @4700776 add */
    /* @4700780 constant */
    /* @4700784 constant */
    /* @4700788 load */
    /* @4700796 constant */
    /* @4700800 add */
    /* @4700804 call */
    GM_SITE(vm, 507, 4700804);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    /* @4700812 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v25, v26, VAL(84)));
    /* @4700816 constant */
    /* @4700820 cast */
    /* @4700824 constant */
    /* @4700828 constant */
    /* @4700832 load */
    /* @4700840 constant */
    /* @4700844 add */
    /* @4700848 constant */
    /* @4700852 constant */
    /* @4700856 load */
    /* @4700864 constant */
    /* @4700868 add */
    /* @4700872 call */
    GM_SITE(vm, 507, 4700872);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    /* @4700880 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v27, v28, VAL(88)));
    /* @4700884 constant */
    /* @4700888 cast */
    /* @4700892 constant */
    /* @4700896 constant */
    /* @4700900 load */
    /* @4700908 constant */
    /* @4700912 add */
    /* @4700916 constant */
    /* @4700920 constant */
    /* @4700924 load */
    /* @4700932 constant */
    /* @4700936 add */
    /* @4700940 call */
    GM_SITE(vm, 507, 4700940);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    /* @4700948 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v29, v30, VAL(93)));
    /* @4700952 constant */
    /* @4700956 cast */
    /* @4700960 constant */
    /* @4700964 constant */
    /* @4700968 load */
    /* @4700976 constant */
    /* @4700980 add */
    /* @4700984 constant */
    /* @4700988 constant */
    /* @4700992 load */
    /* @4701000 constant */
    /* @4701004 add */
    /* @4701008 call */
    GM_SITE(vm, 507, 4701008);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @4701016 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v31, v32, VAL(89)));
    /* @4701020 constant */
    /* @4701024 cast */
    /* @4701028 constant */
    /* @4701032 constant */
    /* @4701036 load */
    /* @4701044 constant */
    /* @4701048 add */
    /* @4701052 constant */
    /* @4701056 constant */
    /* @4701060 load */
    /* @4701068 constant */
    /* @4701072 add */
    /* @4701076 call */
    GM_SITE(vm, 507, 4701076);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    /* @4701084 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v33, v34, VAL(92)));
    /* @4701088 constant */
    /* @4701092 cast */
    /* @4701096 constant */
    /* @4701100 constant */
    /* @4701104 load */
    /* @4701112 constant */
    /* @4701116 add */
    /* @4701120 constant */
    /* @4701124 constant */
    /* @4701128 load */
    /* @4701136 constant */
    /* @4701140 add */
    /* @4701144 call */
    GM_SITE(vm, 507, 4701144);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(100));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4701152 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v35, v36, VAL(116)));
    L_4701156: ;
    /* @4701156 load */
    /* @4701164 constant */
    /* @4701168 cmp */
    /* @4701172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4701788;
    /* @4701176 constant */
    /* @4701180 cast */
    /* @4701184 constant */
    /* @4701188 constant */
    /* @4701192 load */
    /* @4701200 constant */
    /* @4701204 add */
    /* @4701208 constant */
    /* @4701212 constant */
    /* @4701216 load */
    /* @4701224 constant */
    /* @4701228 add */
    /* @4701232 call */
    GM_SITE(vm, 507, 4701232);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    /* @4701240 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v37, v38, VAL(99)));
    /* @4701244 constant */
    /* @4701248 cast */
    /* @4701252 constant */
    /* @4701256 constant */
    /* @4701260 load */
    /* @4701268 constant */
    /* @4701272 add */
    /* @4701276 constant */
    /* @4701280 constant */
    /* @4701284 load */
    /* @4701292 constant */
    /* @4701296 add */
    /* @4701300 call */
    GM_SITE(vm, 507, 4701300);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    /* @4701308 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v39, v40, VAL(96)));
    /* @4701312 constant */
    /* @4701316 cast */
    /* @4701320 constant */
    /* @4701324 constant */
    /* @4701328 load */
    /* @4701336 constant */
    /* @4701340 add */
    /* @4701344 constant */
    /* @4701348 constant */
    /* @4701352 load */
    /* @4701360 constant */
    /* @4701364 add */
    /* @4701368 call */
    GM_SITE(vm, 507, 4701368);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(80));
    /* @4701376 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v41, v42, VAL(87)));
    /* @4701380 constant */
    /* @4701384 cast */
    /* @4701388 constant */
    /* @4701392 constant */
    /* @4701396 load */
    /* @4701404 constant */
    /* @4701408 add */
    /* @4701412 constant */
    /* @4701416 constant */
    /* @4701420 load */
    /* @4701428 constant */
    /* @4701432 add */
    /* @4701436 call */
    GM_SITE(vm, 507, 4701436);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(120));
    /* @4701444 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v43, v44, VAL(84)));
    /* @4701448 constant */
    /* @4701452 cast */
    /* @4701456 constant */
    /* @4701460 constant */
    /* @4701464 load */
    /* @4701472 constant */
    /* @4701476 add */
    /* @4701480 constant */
    /* @4701484 constant */
    /* @4701488 load */
    /* @4701496 constant */
    /* @4701500 add */
    /* @4701504 call */
    GM_SITE(vm, 507, 4701504);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(20));
    /* @4701512 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v45, v46, VAL(88)));
    /* @4701516 constant */
    /* @4701520 cast */
    /* @4701524 constant */
    /* @4701528 constant */
    /* @4701532 load */
    /* @4701540 constant */
    /* @4701544 add */
    /* @4701548 constant */
    /* @4701552 constant */
    /* @4701556 load */
    /* @4701564 constant */
    /* @4701568 add */
    /* @4701572 call */
    GM_SITE(vm, 507, 4701572);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    /* @4701580 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v47, v48, VAL(93)));
    /* @4701584 constant */
    /* @4701588 cast */
    /* @4701592 constant */
    /* @4701596 constant */
    /* @4701600 load */
    /* @4701608 constant */
    /* @4701612 add */
    /* @4701616 constant */
    /* @4701620 constant */
    /* @4701624 load */
    /* @4701632 constant */
    /* @4701636 add */
    /* @4701640 call */
    GM_SITE(vm, 507, 4701640);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(80));
    /* @4701648 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v49, v50, VAL(89)));
    /* @4701652 constant */
    /* @4701656 cast */
    /* @4701660 constant */
    /* @4701664 constant */
    /* @4701668 load */
    /* @4701676 constant */
    /* @4701680 add */
    /* @4701684 constant */
    /* @4701688 constant */
    /* @4701692 load */
    /* @4701700 constant */
    /* @4701704 add */
    /* @4701708 call */
    GM_SITE(vm, 507, 4701708);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(120));
    /* @4701716 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v51, v52, VAL(92)));
    /* @4701720 constant */
    /* @4701724 cast */
    /* @4701728 constant */
    /* @4701732 constant */
    /* @4701736 load */
    /* @4701744 constant */
    /* @4701748 add */
    /* @4701752 constant */
    /* @4701756 constant */
    /* @4701760 load */
    /* @4701768 constant */
    /* @4701772 add */
    /* @4701776 call */
    GM_SITE(vm, 507, 4701776);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(170));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    /* @4701784 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v53, v54, VAL(116)));
    L_4701788: ;
    /* @4701788 load */
    /* @4701796 constant */
    /* @4701800 cmp */
    /* @4701804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4702420;
    /* @4701808 constant */
    /* @4701812 cast */
    /* @4701816 constant */
    /* @4701820 constant */
    /* @4701824 load */
    /* @4701832 constant */
    /* @4701836 add */
    /* @4701840 constant */
    /* @4701844 constant */
    /* @4701848 load */
    /* @4701856 constant */
    /* @4701860 add */
    /* @4701864 call */
    GM_SITE(vm, 507, 4701864);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(20));
    /* @4701872 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v55, v56, VAL(99)));
    /* @4701876 constant */
    /* @4701880 cast */
    /* @4701884 constant */
    /* @4701888 constant */
    /* @4701892 load */
    /* @4701900 constant */
    /* @4701904 add */
    /* @4701908 constant */
    /* @4701912 constant */
    /* @4701916 load */
    /* @4701924 constant */
    /* @4701928 add */
    /* @4701932 call */
    GM_SITE(vm, 507, 4701932);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    /* @4701940 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v57, v58, VAL(96)));
    /* @4701944 constant */
    /* @4701948 cast */
    /* @4701952 constant */
    /* @4701956 constant */
    /* @4701960 load */
    /* @4701968 constant */
    /* @4701972 add */
    /* @4701976 constant */
    /* @4701980 constant */
    /* @4701984 load */
    /* @4701992 constant */
    /* @4701996 add */
    /* @4702000 call */
    GM_SITE(vm, 507, 4702000);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(80));
    /* @4702008 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v59, v60, VAL(87)));
    /* @4702012 constant */
    /* @4702016 cast */
    /* @4702020 constant */
    /* @4702024 constant */
    /* @4702028 load */
    /* @4702036 constant */
    /* @4702040 add */
    /* @4702044 constant */
    /* @4702048 constant */
    /* @4702052 load */
    /* @4702060 constant */
    /* @4702064 add */
    /* @4702068 call */
    GM_SITE(vm, 507, 4702068);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(120));
    /* @4702076 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v61, v62, VAL(84)));
    /* @4702080 constant */
    /* @4702084 cast */
    /* @4702088 constant */
    /* @4702092 constant */
    /* @4702096 load */
    /* @4702104 constant */
    /* @4702108 add */
    /* @4702112 constant */
    /* @4702116 constant */
    /* @4702120 load */
    /* @4702128 constant */
    /* @4702132 add */
    /* @4702136 call */
    GM_SITE(vm, 507, 4702136);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(20));
    /* @4702144 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v63, v64, VAL(88)));
    /* @4702148 constant */
    /* @4702152 cast */
    /* @4702156 constant */
    /* @4702160 constant */
    /* @4702164 load */
    /* @4702172 constant */
    /* @4702176 add */
    /* @4702180 constant */
    /* @4702184 constant */
    /* @4702188 load */
    /* @4702196 constant */
    /* @4702200 add */
    /* @4702204 call */
    GM_SITE(vm, 507, 4702204);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    /* @4702212 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v65, v66, VAL(93)));
    /* @4702216 constant */
    /* @4702220 cast */
    /* @4702224 constant */
    /* @4702228 constant */
    /* @4702232 load */
    /* @4702240 constant */
    /* @4702244 add */
    /* @4702248 constant */
    /* @4702252 constant */
    /* @4702256 load */
    /* @4702264 constant */
    /* @4702268 add */
    /* @4702272 call */
    GM_SITE(vm, 507, 4702272);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(80));
    /* @4702280 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v67, v68, VAL(89)));
    /* @4702284 constant */
    /* @4702288 cast */
    /* @4702292 constant */
    /* @4702296 constant */
    /* @4702300 load */
    /* @4702308 constant */
    /* @4702312 add */
    /* @4702316 constant */
    /* @4702320 constant */
    /* @4702324 load */
    /* @4702332 constant */
    /* @4702336 add */
    /* @4702340 call */
    GM_SITE(vm, 507, 4702340);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(120));
    /* @4702348 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v69, v70, VAL(92)));
    /* @4702352 constant */
    /* @4702356 cast */
    /* @4702360 constant */
    /* @4702364 constant */
    /* @4702368 load */
    /* @4702376 constant */
    /* @4702380 add */
    /* @4702384 constant */
    /* @4702388 constant */
    /* @4702392 load */
    /* @4702400 constant */
    /* @4702404 add */
    /* @4702408 call */
    GM_SITE(vm, 507, 4702408);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(170));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    /* @4702416 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v71, v72, VAL(116)));
    L_4702420: ;
    /* @4702420 load */
    /* @4702428 constant */
    /* @4702432 cmp */
    /* @4702436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4703052;
    /* @4702440 constant */
    /* @4702444 cast */
    /* @4702448 constant */
    /* @4702452 constant */
    /* @4702456 load */
    /* @4702464 constant */
    /* @4702468 add */
    /* @4702472 constant */
    /* @4702476 constant */
    /* @4702480 load */
    /* @4702488 constant */
    /* @4702492 add */
    /* @4702496 call */
    GM_SITE(vm, 507, 4702496);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(20));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(20));
    /* @4702504 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v73, v74, VAL(99)));
    /* @4702508 constant */
    /* @4702512 cast */
    /* @4702516 constant */
    /* @4702520 constant */
    /* @4702524 load */
    /* @4702532 constant */
    /* @4702536 add */
    /* @4702540 constant */
    /* @4702544 constant */
    /* @4702548 load */
    /* @4702556 constant */
    /* @4702560 add */
    /* @4702564 call */
    GM_SITE(vm, 507, 4702564);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(20));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(60));
    /* @4702572 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v75, v76, VAL(96)));
    /* @4702576 constant */
    /* @4702580 cast */
    /* @4702584 constant */
    /* @4702588 constant */
    /* @4702592 load */
    /* @4702600 constant */
    /* @4702604 add */
    /* @4702608 constant */
    /* @4702612 constant */
    /* @4702616 load */
    /* @4702624 constant */
    /* @4702628 add */
    /* @4702632 call */
    GM_SITE(vm, 507, 4702632);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(20));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(80));
    /* @4702640 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v77, v78, VAL(87)));
    /* @4702644 constant */
    /* @4702648 cast */
    /* @4702652 constant */
    /* @4702656 constant */
    /* @4702660 load */
    /* @4702668 constant */
    /* @4702672 add */
    /* @4702676 constant */
    /* @4702680 constant */
    /* @4702684 load */
    /* @4702692 constant */
    /* @4702696 add */
    /* @4702700 call */
    GM_SITE(vm, 507, 4702700);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(20));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(120));
    /* @4702708 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v79, v80, VAL(84)));
    /* @4702712 constant */
    /* @4702716 cast */
    /* @4702720 constant */
    /* @4702724 constant */
    /* @4702728 load */
    /* @4702736 constant */
    /* @4702740 add */
    /* @4702744 constant */
    /* @4702748 constant */
    /* @4702752 load */
    /* @4702760 constant */
    /* @4702764 add */
    /* @4702768 call */
    GM_SITE(vm, 507, 4702768);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(20));
    /* @4702776 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v81, v82, VAL(88)));
    /* @4702780 constant */
    /* @4702784 cast */
    /* @4702788 constant */
    /* @4702792 constant */
    /* @4702796 load */
    /* @4702804 constant */
    /* @4702808 add */
    /* @4702812 constant */
    /* @4702816 constant */
    /* @4702820 load */
    /* @4702828 constant */
    /* @4702832 add */
    /* @4702836 call */
    GM_SITE(vm, 507, 4702836);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(60));
    /* @4702844 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v83, v84, VAL(93)));
    /* @4702848 constant */
    /* @4702852 cast */
    /* @4702856 constant */
    /* @4702860 constant */
    /* @4702864 load */
    /* @4702872 constant */
    /* @4702876 add */
    /* @4702880 constant */
    /* @4702884 constant */
    /* @4702888 load */
    /* @4702896 constant */
    /* @4702900 add */
    /* @4702904 call */
    GM_SITE(vm, 507, 4702904);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(80));
    /* @4702912 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v85, v86, VAL(89)));
    /* @4702916 constant */
    /* @4702920 cast */
    /* @4702924 constant */
    /* @4702928 constant */
    /* @4702932 load */
    /* @4702940 constant */
    /* @4702944 add */
    /* @4702948 constant */
    /* @4702952 constant */
    /* @4702956 load */
    /* @4702964 constant */
    /* @4702968 add */
    /* @4702972 call */
    GM_SITE(vm, 507, 4702972);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(240));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(120));
    /* @4702980 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v87, v88, VAL(92)));
    /* @4702984 constant */
    /* @4702988 cast */
    /* @4702992 constant */
    /* @4702996 constant */
    /* @4703000 load */
    /* @4703008 constant */
    /* @4703012 add */
    /* @4703016 constant */
    /* @4703020 constant */
    /* @4703024 load */
    /* @4703032 constant */
    /* @4703036 add */
    /* @4703040 call */
    GM_SITE(vm, 507, 4703040);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(170));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(280));
    /* @4703048 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v89, v90, VAL(116)));
    L_4703052: ;
    /* @4703052 load */
    /* @4703060 constant */
    /* @4703064 cmp */
    /* @4703068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4703684;
    /* @4703072 constant */
    /* @4703076 cast */
    /* @4703080 constant */
    /* @4703084 constant */
    /* @4703088 load */
    /* @4703096 constant */
    /* @4703100 add */
    /* @4703104 constant */
    /* @4703108 constant */
    /* @4703112 load */
    /* @4703120 constant */
    /* @4703124 add */
    /* @4703128 call */
    GM_SITE(vm, 507, 4703128);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(20));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(20));
    /* @4703136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v91, v92, VAL(99)));
    /* @4703140 constant */
    /* @4703144 cast */
    /* @4703148 constant */
    /* @4703152 constant */
    /* @4703156 load */
    /* @4703164 constant */
    /* @4703168 add */
    /* @4703172 constant */
    /* @4703176 constant */
    /* @4703180 load */
    /* @4703188 constant */
    /* @4703192 add */
    /* @4703196 call */
    GM_SITE(vm, 507, 4703196);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(20));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(60));
    /* @4703204 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v93, v94, VAL(96)));
    /* @4703208 constant */
    /* @4703212 cast */
    /* @4703216 constant */
    /* @4703220 constant */
    /* @4703224 load */
    /* @4703232 constant */
    /* @4703236 add */
    /* @4703240 constant */
    /* @4703244 constant */
    /* @4703248 load */
    /* @4703256 constant */
    /* @4703260 add */
    /* @4703264 call */
    GM_SITE(vm, 507, 4703264);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(20));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(80));
    /* @4703272 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v95, v96, VAL(87)));
    /* @4703276 constant */
    /* @4703280 cast */
    /* @4703284 constant */
    /* @4703288 constant */
    /* @4703292 load */
    /* @4703300 constant */
    /* @4703304 add */
    /* @4703308 constant */
    /* @4703312 constant */
    /* @4703316 load */
    /* @4703324 constant */
    /* @4703328 add */
    /* @4703332 call */
    GM_SITE(vm, 507, 4703332);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(20));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(120));
    /* @4703340 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v97, v98, VAL(84)));
    /* @4703344 constant */
    /* @4703348 cast */
    /* @4703352 constant */
    /* @4703356 constant */
    /* @4703360 load */
    /* @4703368 constant */
    /* @4703372 add */
    /* @4703376 constant */
    /* @4703380 constant */
    /* @4703384 load */
    /* @4703392 constant */
    /* @4703396 add */
    /* @4703400 call */
    GM_SITE(vm, 507, 4703400);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(20));
    /* @4703408 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v99, v100, VAL(88)));
    /* @4703412 constant */
    /* @4703416 cast */
    /* @4703420 constant */
    /* @4703424 constant */
    /* @4703428 load */
    /* @4703436 constant */
    /* @4703440 add */
    /* @4703444 constant */
    /* @4703448 constant */
    /* @4703452 load */
    /* @4703460 constant */
    /* @4703464 add */
    /* @4703468 call */
    GM_SITE(vm, 507, 4703468);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(60));
    /* @4703476 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v101, v102, VAL(93)));
    /* @4703480 constant */
    /* @4703484 cast */
    /* @4703488 constant */
    /* @4703492 constant */
    /* @4703496 load */
    /* @4703504 constant */
    /* @4703508 add */
    /* @4703512 constant */
    /* @4703516 constant */
    /* @4703520 load */
    /* @4703528 constant */
    /* @4703532 add */
    /* @4703536 call */
    GM_SITE(vm, 507, 4703536);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(80));
    /* @4703544 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v103, v104, VAL(89)));
    /* @4703548 constant */
    /* @4703552 cast */
    /* @4703556 constant */
    /* @4703560 constant */
    /* @4703564 load */
    /* @4703572 constant */
    /* @4703576 add */
    /* @4703580 constant */
    /* @4703584 constant */
    /* @4703588 load */
    /* @4703596 constant */
    /* @4703600 add */
    /* @4703604 call */
    GM_SITE(vm, 507, 4703604);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(240));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(120));
    /* @4703612 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v105, v106, VAL(92)));
    /* @4703616 constant */
    /* @4703620 cast */
    /* @4703624 constant */
    /* @4703628 constant */
    /* @4703632 load */
    /* @4703640 constant */
    /* @4703644 add */
    /* @4703648 constant */
    /* @4703652 constant */
    /* @4703656 load */
    /* @4703664 constant */
    /* @4703668 add */
    /* @4703672 call */
    GM_SITE(vm, 507, 4703672);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(170));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(280));
    /* @4703680 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v107, v108, VAL(116)));
    L_4703684: ;
    return;
}
