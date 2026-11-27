/* generated from CODE 512 (gml_Object_obj_pause2_Create_0), source start 4706656, end 4710500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0512(GmVM* vm) {
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
    /* @4706656 constant */
    /* @4706660 store */
    GM_WRITE(vm, -5, "storemenu", VAL(2));
    /* @4706668 constant */
    /* @4706672 cast */
    /* @4706676 call */
    GM_SITE(vm, 512, 4706676);
    /* @4706684 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4706688 constant */
    /* @4706692 cast */
    /* @4706696 call */
    GM_SITE(vm, 512, 4706696);
    /* @4706704 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(108)));
    /* @4706708 load */
    /* @4706716 constant */
    /* @4706720 cmp */
    /* @4706724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4707340;
    /* @4706728 constant */
    /* @4706732 cast */
    /* @4706736 constant */
    /* @4706740 constant */
    /* @4706744 load */
    /* @4706752 constant */
    /* @4706756 add */
    /* @4706760 constant */
    /* @4706764 constant */
    /* @4706768 load */
    /* @4706776 constant */
    /* @4706780 add */
    /* @4706784 call */
    GM_SITE(vm, 512, 4706784);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(30));
    /* @4706792 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, v2, VAL(97)));
    /* @4706796 constant */
    /* @4706800 cast */
    /* @4706804 constant */
    /* @4706808 constant */
    /* @4706812 load */
    /* @4706820 constant */
    /* @4706824 add */
    /* @4706828 constant */
    /* @4706832 constant */
    /* @4706836 load */
    /* @4706844 constant */
    /* @4706848 add */
    /* @4706852 call */
    GM_SITE(vm, 512, 4706852);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(70));
    /* @4706860 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, v4, VAL(98)));
    /* @4706864 constant */
    /* @4706868 cast */
    /* @4706872 constant */
    /* @4706876 constant */
    /* @4706880 load */
    /* @4706888 constant */
    /* @4706892 add */
    /* @4706896 constant */
    /* @4706900 constant */
    /* @4706904 load */
    /* @4706912 constant */
    /* @4706916 add */
    /* @4706920 call */
    GM_SITE(vm, 512, 4706920);
    v5 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v6 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(110));
    /* @4706928 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v5, v6, VAL(95)));
    /* @4706932 constant */
    /* @4706936 cast */
    /* @4706940 constant */
    /* @4706944 constant */
    /* @4706948 load */
    /* @4706956 constant */
    /* @4706960 add */
    /* @4706964 constant */
    /* @4706968 constant */
    /* @4706972 load */
    /* @4706980 constant */
    /* @4706984 add */
    /* @4706988 call */
    GM_SITE(vm, 512, 4706988);
    v7 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(65));
    v8 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4706996 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v7, v8, VAL(85)));
    /* @4707000 constant */
    /* @4707004 cast */
    /* @4707008 constant */
    /* @4707012 constant */
    /* @4707016 load */
    /* @4707024 constant */
    /* @4707028 add */
    /* @4707032 constant */
    /* @4707036 constant */
    /* @4707040 load */
    /* @4707048 constant */
    /* @4707052 add */
    /* @4707056 call */
    GM_SITE(vm, 512, 4707056);
    v9 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v10 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(30));
    /* @4707064 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v9, v10, VAL(86)));
    /* @4707068 constant */
    /* @4707072 cast */
    /* @4707076 constant */
    /* @4707080 constant */
    /* @4707084 load */
    /* @4707092 constant */
    /* @4707096 add */
    /* @4707100 constant */
    /* @4707104 constant */
    /* @4707108 load */
    /* @4707116 constant */
    /* @4707120 add */
    /* @4707124 call */
    GM_SITE(vm, 512, 4707124);
    v11 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v12 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(70));
    /* @4707132 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v11, v12, VAL(90)));
    /* @4707136 constant */
    /* @4707140 cast */
    /* @4707144 constant */
    /* @4707148 constant */
    /* @4707152 load */
    /* @4707160 constant */
    /* @4707164 add */
    /* @4707168 constant */
    /* @4707172 constant */
    /* @4707176 load */
    /* @4707184 constant */
    /* @4707188 add */
    /* @4707192 call */
    GM_SITE(vm, 512, 4707192);
    v13 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v14 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(110));
    /* @4707200 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v13, v14, VAL(91)));
    /* @4707204 constant */
    /* @4707208 cast */
    /* @4707212 constant */
    /* @4707216 constant */
    /* @4707220 load */
    /* @4707228 constant */
    /* @4707232 add */
    /* @4707236 constant */
    /* @4707240 constant */
    /* @4707244 load */
    /* @4707252 constant */
    /* @4707256 add */
    /* @4707260 call */
    GM_SITE(vm, 512, 4707260);
    v15 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(245));
    v16 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(150));
    /* @4707268 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v15, v16, VAL(94)));
    /* @4707272 constant */
    /* @4707276 cast */
    /* @4707280 constant */
    /* @4707284 constant */
    /* @4707288 load */
    /* @4707296 constant */
    /* @4707300 add */
    /* @4707304 constant */
    /* @4707308 constant */
    /* @4707312 load */
    /* @4707320 constant */
    /* @4707324 add */
    /* @4707328 call */
    GM_SITE(vm, 512, 4707328);
    v17 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(5));
    v18 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(190));
    /* @4707336 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v17, v18, VAL(117)));
    L_4707340: ;
    /* @4707340 load */
    /* @4707348 constant */
    /* @4707352 cmp */
    /* @4707356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4707972;
    /* @4707360 constant */
    /* @4707364 cast */
    /* @4707368 constant */
    /* @4707372 constant */
    /* @4707376 load */
    /* @4707384 constant */
    /* @4707388 add */
    /* @4707392 constant */
    /* @4707396 constant */
    /* @4707400 load */
    /* @4707408 constant */
    /* @4707412 add */
    /* @4707416 call */
    GM_SITE(vm, 512, 4707416);
    v19 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v20 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    /* @4707424 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v19, v20, VAL(97)));
    /* @4707428 constant */
    /* @4707432 cast */
    /* @4707436 constant */
    /* @4707440 constant */
    /* @4707444 load */
    /* @4707452 constant */
    /* @4707456 add */
    /* @4707460 constant */
    /* @4707464 constant */
    /* @4707468 load */
    /* @4707476 constant */
    /* @4707480 add */
    /* @4707484 call */
    GM_SITE(vm, 512, 4707484);
    v21 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v22 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    /* @4707492 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v21, v22, VAL(98)));
    /* @4707496 constant */
    /* @4707500 cast */
    /* @4707504 constant */
    /* @4707508 constant */
    /* @4707512 load */
    /* @4707520 constant */
    /* @4707524 add */
    /* @4707528 constant */
    /* @4707532 constant */
    /* @4707536 load */
    /* @4707544 constant */
    /* @4707548 add */
    /* @4707552 call */
    GM_SITE(vm, 512, 4707552);
    v23 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v24 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @4707560 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v23, v24, VAL(95)));
    /* @4707564 constant */
    /* @4707568 cast */
    /* @4707572 constant */
    /* @4707576 constant */
    /* @4707580 load */
    /* @4707588 constant */
    /* @4707592 add */
    /* @4707596 constant */
    /* @4707600 constant */
    /* @4707604 load */
    /* @4707612 constant */
    /* @4707616 add */
    /* @4707620 call */
    GM_SITE(vm, 512, 4707620);
    v25 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(40));
    v26 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    /* @4707628 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v25, v26, VAL(85)));
    /* @4707632 constant */
    /* @4707636 cast */
    /* @4707640 constant */
    /* @4707644 constant */
    /* @4707648 load */
    /* @4707656 constant */
    /* @4707660 add */
    /* @4707664 constant */
    /* @4707668 constant */
    /* @4707672 load */
    /* @4707680 constant */
    /* @4707684 add */
    /* @4707688 call */
    GM_SITE(vm, 512, 4707688);
    v27 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v28 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(50));
    /* @4707696 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v27, v28, VAL(86)));
    /* @4707700 constant */
    /* @4707704 cast */
    /* @4707708 constant */
    /* @4707712 constant */
    /* @4707716 load */
    /* @4707724 constant */
    /* @4707728 add */
    /* @4707732 constant */
    /* @4707736 constant */
    /* @4707740 load */
    /* @4707748 constant */
    /* @4707752 add */
    /* @4707756 call */
    GM_SITE(vm, 512, 4707756);
    v29 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v30 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(90));
    /* @4707764 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v29, v30, VAL(90)));
    /* @4707768 constant */
    /* @4707772 cast */
    /* @4707776 constant */
    /* @4707780 constant */
    /* @4707784 load */
    /* @4707792 constant */
    /* @4707796 add */
    /* @4707800 constant */
    /* @4707804 constant */
    /* @4707808 load */
    /* @4707816 constant */
    /* @4707820 add */
    /* @4707824 call */
    GM_SITE(vm, 512, 4707824);
    v31 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v32 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(130));
    /* @4707832 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v31, v32, VAL(91)));
    /* @4707836 constant */
    /* @4707840 cast */
    /* @4707844 constant */
    /* @4707848 constant */
    /* @4707852 load */
    /* @4707860 constant */
    /* @4707864 add */
    /* @4707868 constant */
    /* @4707872 constant */
    /* @4707876 load */
    /* @4707884 constant */
    /* @4707888 add */
    /* @4707892 call */
    GM_SITE(vm, 512, 4707892);
    v33 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(205));
    v34 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(170));
    /* @4707900 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v33, v34, VAL(94)));
    /* @4707904 constant */
    /* @4707908 cast */
    /* @4707912 constant */
    /* @4707916 constant */
    /* @4707920 load */
    /* @4707928 constant */
    /* @4707932 add */
    /* @4707936 constant */
    /* @4707940 constant */
    /* @4707944 load */
    /* @4707952 constant */
    /* @4707956 add */
    /* @4707960 call */
    GM_SITE(vm, 512, 4707960);
    v35 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(1)), VAL(1));
    v36 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(1)), VAL(200));
    /* @4707968 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v35, v36, VAL(117)));
    L_4707972: ;
    /* @4707972 load */
    /* @4707980 constant */
    /* @4707984 cmp */
    /* @4707988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4708604;
    /* @4707992 constant */
    /* @4707996 cast */
    /* @4708000 constant */
    /* @4708004 constant */
    /* @4708008 load */
    /* @4708016 constant */
    /* @4708020 add */
    /* @4708024 constant */
    /* @4708028 constant */
    /* @4708032 load */
    /* @4708040 constant */
    /* @4708044 add */
    /* @4708048 call */
    GM_SITE(vm, 512, 4708048);
    v37 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v38 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(20));
    /* @4708056 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v37, v38, VAL(97)));
    /* @4708060 constant */
    /* @4708064 cast */
    /* @4708068 constant */
    /* @4708072 constant */
    /* @4708076 load */
    /* @4708084 constant */
    /* @4708088 add */
    /* @4708092 constant */
    /* @4708096 constant */
    /* @4708100 load */
    /* @4708108 constant */
    /* @4708112 add */
    /* @4708116 call */
    GM_SITE(vm, 512, 4708116);
    v39 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v40 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    /* @4708124 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v39, v40, VAL(98)));
    /* @4708128 constant */
    /* @4708132 cast */
    /* @4708136 constant */
    /* @4708140 constant */
    /* @4708144 load */
    /* @4708152 constant */
    /* @4708156 add */
    /* @4708160 constant */
    /* @4708164 constant */
    /* @4708168 load */
    /* @4708176 constant */
    /* @4708180 add */
    /* @4708184 call */
    GM_SITE(vm, 512, 4708184);
    v41 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v42 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    /* @4708192 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v41, v42, VAL(95)));
    /* @4708196 constant */
    /* @4708200 cast */
    /* @4708204 constant */
    /* @4708208 constant */
    /* @4708212 load */
    /* @4708220 constant */
    /* @4708224 add */
    /* @4708228 constant */
    /* @4708232 constant */
    /* @4708236 load */
    /* @4708244 constant */
    /* @4708248 add */
    /* @4708252 call */
    GM_SITE(vm, 512, 4708252);
    v43 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(40));
    v44 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    /* @4708260 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v43, v44, VAL(85)));
    /* @4708264 constant */
    /* @4708268 cast */
    /* @4708272 constant */
    /* @4708276 constant */
    /* @4708280 load */
    /* @4708288 constant */
    /* @4708292 add */
    /* @4708296 constant */
    /* @4708300 constant */
    /* @4708304 load */
    /* @4708312 constant */
    /* @4708316 add */
    /* @4708320 call */
    GM_SITE(vm, 512, 4708320);
    v45 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v46 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(20));
    /* @4708328 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v45, v46, VAL(86)));
    /* @4708332 constant */
    /* @4708336 cast */
    /* @4708340 constant */
    /* @4708344 constant */
    /* @4708348 load */
    /* @4708356 constant */
    /* @4708360 add */
    /* @4708364 constant */
    /* @4708368 constant */
    /* @4708372 load */
    /* @4708380 constant */
    /* @4708384 add */
    /* @4708388 call */
    GM_SITE(vm, 512, 4708388);
    v47 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v48 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(60));
    /* @4708396 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v47, v48, VAL(90)));
    /* @4708400 constant */
    /* @4708404 cast */
    /* @4708408 constant */
    /* @4708412 constant */
    /* @4708416 load */
    /* @4708424 constant */
    /* @4708428 add */
    /* @4708432 constant */
    /* @4708436 constant */
    /* @4708440 load */
    /* @4708448 constant */
    /* @4708452 add */
    /* @4708456 call */
    GM_SITE(vm, 512, 4708456);
    v49 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v50 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(100));
    /* @4708464 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v49, v50, VAL(91)));
    /* @4708468 constant */
    /* @4708472 cast */
    /* @4708476 constant */
    /* @4708480 constant */
    /* @4708484 load */
    /* @4708492 constant */
    /* @4708496 add */
    /* @4708500 constant */
    /* @4708504 constant */
    /* @4708508 load */
    /* @4708516 constant */
    /* @4708520 add */
    /* @4708524 call */
    GM_SITE(vm, 512, 4708524);
    v51 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(240));
    v52 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(140));
    /* @4708532 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v51, v52, VAL(94)));
    /* @4708536 constant */
    /* @4708540 cast */
    /* @4708544 constant */
    /* @4708548 constant */
    /* @4708552 load */
    /* @4708560 constant */
    /* @4708564 add */
    /* @4708568 constant */
    /* @4708572 constant */
    /* @4708576 load */
    /* @4708584 constant */
    /* @4708588 add */
    /* @4708592 call */
    GM_SITE(vm, 512, 4708592);
    v53 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    v54 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(280));
    /* @4708600 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v53, v54, VAL(117)));
    L_4708604: ;
    /* @4708604 load */
    /* @4708612 constant */
    /* @4708616 cmp */
    /* @4708620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4709236;
    /* @4708624 constant */
    /* @4708628 cast */
    /* @4708632 constant */
    /* @4708636 constant */
    /* @4708640 load */
    /* @4708648 constant */
    /* @4708652 add */
    /* @4708656 constant */
    /* @4708660 constant */
    /* @4708664 load */
    /* @4708672 constant */
    /* @4708676 add */
    /* @4708680 call */
    GM_SITE(vm, 512, 4708680);
    v55 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v56 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(20));
    /* @4708688 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v55, v56, VAL(97)));
    /* @4708692 constant */
    /* @4708696 cast */
    /* @4708700 constant */
    /* @4708704 constant */
    /* @4708708 load */
    /* @4708716 constant */
    /* @4708720 add */
    /* @4708724 constant */
    /* @4708728 constant */
    /* @4708732 load */
    /* @4708740 constant */
    /* @4708744 add */
    /* @4708748 call */
    GM_SITE(vm, 512, 4708748);
    v57 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v58 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    /* @4708756 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v57, v58, VAL(98)));
    /* @4708760 constant */
    /* @4708764 cast */
    /* @4708768 constant */
    /* @4708772 constant */
    /* @4708776 load */
    /* @4708784 constant */
    /* @4708788 add */
    /* @4708792 constant */
    /* @4708796 constant */
    /* @4708800 load */
    /* @4708808 constant */
    /* @4708812 add */
    /* @4708816 call */
    GM_SITE(vm, 512, 4708816);
    v59 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v60 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(80));
    /* @4708824 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v59, v60, VAL(95)));
    /* @4708828 constant */
    /* @4708832 cast */
    /* @4708836 constant */
    /* @4708840 constant */
    /* @4708844 load */
    /* @4708852 constant */
    /* @4708856 add */
    /* @4708860 constant */
    /* @4708864 constant */
    /* @4708868 load */
    /* @4708876 constant */
    /* @4708880 add */
    /* @4708884 call */
    GM_SITE(vm, 512, 4708884);
    v61 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(40));
    v62 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(120));
    /* @4708892 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v61, v62, VAL(85)));
    /* @4708896 constant */
    /* @4708900 cast */
    /* @4708904 constant */
    /* @4708908 constant */
    /* @4708912 load */
    /* @4708920 constant */
    /* @4708924 add */
    /* @4708928 constant */
    /* @4708932 constant */
    /* @4708936 load */
    /* @4708944 constant */
    /* @4708948 add */
    /* @4708952 call */
    GM_SITE(vm, 512, 4708952);
    v63 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v64 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(20));
    /* @4708960 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v63, v64, VAL(86)));
    /* @4708964 constant */
    /* @4708968 cast */
    /* @4708972 constant */
    /* @4708976 constant */
    /* @4708980 load */
    /* @4708988 constant */
    /* @4708992 add */
    /* @4708996 constant */
    /* @4709000 constant */
    /* @4709004 load */
    /* @4709012 constant */
    /* @4709016 add */
    /* @4709020 call */
    GM_SITE(vm, 512, 4709020);
    v65 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v66 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(60));
    /* @4709028 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v65, v66, VAL(90)));
    /* @4709032 constant */
    /* @4709036 cast */
    /* @4709040 constant */
    /* @4709044 constant */
    /* @4709048 load */
    /* @4709056 constant */
    /* @4709060 add */
    /* @4709064 constant */
    /* @4709068 constant */
    /* @4709072 load */
    /* @4709080 constant */
    /* @4709084 add */
    /* @4709088 call */
    GM_SITE(vm, 512, 4709088);
    v67 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v68 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(80));
    /* @4709096 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v67, v68, VAL(91)));
    /* @4709100 constant */
    /* @4709104 cast */
    /* @4709108 constant */
    /* @4709112 constant */
    /* @4709116 load */
    /* @4709124 constant */
    /* @4709128 add */
    /* @4709132 constant */
    /* @4709136 constant */
    /* @4709140 load */
    /* @4709148 constant */
    /* @4709152 add */
    /* @4709156 call */
    GM_SITE(vm, 512, 4709156);
    v69 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(240));
    v70 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(120));
    /* @4709164 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v69, v70, VAL(94)));
    /* @4709168 constant */
    /* @4709172 cast */
    /* @4709176 constant */
    /* @4709180 constant */
    /* @4709184 load */
    /* @4709192 constant */
    /* @4709196 add */
    /* @4709200 constant */
    /* @4709204 constant */
    /* @4709208 load */
    /* @4709216 constant */
    /* @4709220 add */
    /* @4709224 call */
    GM_SITE(vm, 512, 4709224);
    v71 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(4)), VAL(20));
    v72 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(4)), VAL(280));
    /* @4709232 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v71, v72, VAL(117)));
    L_4709236: ;
    /* @4709236 load */
    /* @4709244 constant */
    /* @4709248 cmp */
    /* @4709252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4709868;
    /* @4709256 constant */
    /* @4709260 cast */
    /* @4709264 constant */
    /* @4709268 constant */
    /* @4709272 load */
    /* @4709280 constant */
    /* @4709284 add */
    /* @4709288 constant */
    /* @4709292 constant */
    /* @4709296 load */
    /* @4709304 constant */
    /* @4709308 add */
    /* @4709312 call */
    GM_SITE(vm, 512, 4709312);
    v73 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    v74 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    /* @4709320 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v73, v74, VAL(97)));
    /* @4709324 constant */
    /* @4709328 cast */
    /* @4709332 constant */
    /* @4709336 constant */
    /* @4709340 load */
    /* @4709348 constant */
    /* @4709352 add */
    /* @4709356 constant */
    /* @4709360 constant */
    /* @4709364 load */
    /* @4709372 constant */
    /* @4709376 add */
    /* @4709380 call */
    GM_SITE(vm, 512, 4709380);
    v75 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    v76 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    /* @4709388 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v75, v76, VAL(98)));
    /* @4709392 constant */
    /* @4709396 cast */
    /* @4709400 constant */
    /* @4709404 constant */
    /* @4709408 load */
    /* @4709416 constant */
    /* @4709420 add */
    /* @4709424 constant */
    /* @4709428 constant */
    /* @4709432 load */
    /* @4709440 constant */
    /* @4709444 add */
    /* @4709448 call */
    GM_SITE(vm, 512, 4709448);
    v77 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    v78 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    /* @4709456 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v77, v78, VAL(95)));
    /* @4709460 constant */
    /* @4709464 cast */
    /* @4709468 constant */
    /* @4709472 constant */
    /* @4709476 load */
    /* @4709484 constant */
    /* @4709488 add */
    /* @4709492 constant */
    /* @4709496 constant */
    /* @4709500 load */
    /* @4709508 constant */
    /* @4709512 add */
    /* @4709516 call */
    GM_SITE(vm, 512, 4709516);
    v79 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(65));
    v80 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @4709524 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v79, v80, VAL(85)));
    /* @4709528 constant */
    /* @4709532 cast */
    /* @4709536 constant */
    /* @4709540 constant */
    /* @4709544 load */
    /* @4709552 constant */
    /* @4709556 add */
    /* @4709560 constant */
    /* @4709564 constant */
    /* @4709568 load */
    /* @4709576 constant */
    /* @4709580 add */
    /* @4709584 call */
    GM_SITE(vm, 512, 4709584);
    v81 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    v82 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(30));
    /* @4709592 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v81, v82, VAL(86)));
    /* @4709596 constant */
    /* @4709600 cast */
    /* @4709604 constant */
    /* @4709608 constant */
    /* @4709612 load */
    /* @4709620 constant */
    /* @4709624 add */
    /* @4709628 constant */
    /* @4709632 constant */
    /* @4709636 load */
    /* @4709644 constant */
    /* @4709648 add */
    /* @4709652 call */
    GM_SITE(vm, 512, 4709652);
    v83 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    v84 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(70));
    /* @4709660 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v83, v84, VAL(90)));
    /* @4709664 constant */
    /* @4709668 cast */
    /* @4709672 constant */
    /* @4709676 constant */
    /* @4709680 load */
    /* @4709688 constant */
    /* @4709692 add */
    /* @4709696 constant */
    /* @4709700 constant */
    /* @4709704 load */
    /* @4709712 constant */
    /* @4709716 add */
    /* @4709720 call */
    GM_SITE(vm, 512, 4709720);
    v85 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    v86 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(110));
    /* @4709728 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v85, v86, VAL(91)));
    /* @4709732 constant */
    /* @4709736 cast */
    /* @4709740 constant */
    /* @4709744 constant */
    /* @4709748 load */
    /* @4709756 constant */
    /* @4709760 add */
    /* @4709764 constant */
    /* @4709768 constant */
    /* @4709772 load */
    /* @4709780 constant */
    /* @4709784 add */
    /* @4709788 call */
    GM_SITE(vm, 512, 4709788);
    v87 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(245));
    v88 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(150));
    /* @4709796 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v87, v88, VAL(94)));
    /* @4709800 constant */
    /* @4709804 cast */
    /* @4709808 constant */
    /* @4709812 constant */
    /* @4709816 load */
    /* @4709824 constant */
    /* @4709828 add */
    /* @4709832 constant */
    /* @4709836 constant */
    /* @4709840 load */
    /* @4709848 constant */
    /* @4709852 add */
    /* @4709856 call */
    GM_SITE(vm, 512, 4709856);
    v89 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(5)), VAL(5));
    v90 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(5)), VAL(190));
    /* @4709864 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v89, v90, VAL(117)));
    L_4709868: ;
    /* @4709868 load */
    /* @4709876 constant */
    /* @4709880 cmp */
    /* @4709884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4710500;
    /* @4709888 constant */
    /* @4709892 cast */
    /* @4709896 constant */
    /* @4709900 constant */
    /* @4709904 load */
    /* @4709912 constant */
    /* @4709916 add */
    /* @4709920 constant */
    /* @4709924 constant */
    /* @4709928 load */
    /* @4709936 constant */
    /* @4709940 add */
    /* @4709944 call */
    GM_SITE(vm, 512, 4709944);
    v91 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    v92 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    /* @4709952 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v91, v92, VAL(97)));
    /* @4709956 constant */
    /* @4709960 cast */
    /* @4709964 constant */
    /* @4709968 constant */
    /* @4709972 load */
    /* @4709980 constant */
    /* @4709984 add */
    /* @4709988 constant */
    /* @4709992 constant */
    /* @4709996 load */
    /* @4710004 constant */
    /* @4710008 add */
    /* @4710012 call */
    GM_SITE(vm, 512, 4710012);
    v93 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    v94 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    /* @4710020 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v93, v94, VAL(98)));
    /* @4710024 constant */
    /* @4710028 cast */
    /* @4710032 constant */
    /* @4710036 constant */
    /* @4710040 load */
    /* @4710048 constant */
    /* @4710052 add */
    /* @4710056 constant */
    /* @4710060 constant */
    /* @4710064 load */
    /* @4710072 constant */
    /* @4710076 add */
    /* @4710080 call */
    GM_SITE(vm, 512, 4710080);
    v95 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    v96 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    /* @4710088 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v95, v96, VAL(95)));
    /* @4710092 constant */
    /* @4710096 cast */
    /* @4710100 constant */
    /* @4710104 constant */
    /* @4710108 load */
    /* @4710116 constant */
    /* @4710120 add */
    /* @4710124 constant */
    /* @4710128 constant */
    /* @4710132 load */
    /* @4710140 constant */
    /* @4710144 add */
    /* @4710148 call */
    GM_SITE(vm, 512, 4710148);
    v97 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(65));
    v98 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    /* @4710156 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v97, v98, VAL(85)));
    /* @4710160 constant */
    /* @4710164 cast */
    /* @4710168 constant */
    /* @4710172 constant */
    /* @4710176 load */
    /* @4710184 constant */
    /* @4710188 add */
    /* @4710192 constant */
    /* @4710196 constant */
    /* @4710200 load */
    /* @4710208 constant */
    /* @4710212 add */
    /* @4710216 call */
    GM_SITE(vm, 512, 4710216);
    v99 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    v100 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(30));
    /* @4710224 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v99, v100, VAL(86)));
    /* @4710228 constant */
    /* @4710232 cast */
    /* @4710236 constant */
    /* @4710240 constant */
    /* @4710244 load */
    /* @4710252 constant */
    /* @4710256 add */
    /* @4710260 constant */
    /* @4710264 constant */
    /* @4710268 load */
    /* @4710276 constant */
    /* @4710280 add */
    /* @4710284 call */
    GM_SITE(vm, 512, 4710284);
    v101 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    v102 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(70));
    /* @4710292 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v101, v102, VAL(90)));
    /* @4710296 constant */
    /* @4710300 cast */
    /* @4710304 constant */
    /* @4710308 constant */
    /* @4710312 load */
    /* @4710320 constant */
    /* @4710324 add */
    /* @4710328 constant */
    /* @4710332 constant */
    /* @4710336 load */
    /* @4710344 constant */
    /* @4710348 add */
    /* @4710352 call */
    GM_SITE(vm, 512, 4710352);
    v103 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    v104 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(110));
    /* @4710360 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v103, v104, VAL(91)));
    /* @4710364 constant */
    /* @4710368 cast */
    /* @4710372 constant */
    /* @4710376 constant */
    /* @4710380 load */
    /* @4710388 constant */
    /* @4710392 add */
    /* @4710396 constant */
    /* @4710400 constant */
    /* @4710404 load */
    /* @4710412 constant */
    /* @4710416 add */
    /* @4710420 call */
    GM_SITE(vm, 512, 4710420);
    v105 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(245));
    v106 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(150));
    /* @4710428 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v105, v106, VAL(94)));
    /* @4710432 constant */
    /* @4710436 cast */
    /* @4710440 constant */
    /* @4710444 constant */
    /* @4710448 load */
    /* @4710456 constant */
    /* @4710460 add */
    /* @4710464 constant */
    /* @4710468 constant */
    /* @4710472 load */
    /* @4710480 constant */
    /* @4710484 add */
    /* @4710488 call */
    GM_SITE(vm, 512, 4710488);
    v107 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(6)), VAL(5));
    v108 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(6)), VAL(190));
    /* @4710496 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v107, v108, VAL(117)));
    L_4710500: ;
    return;
}
