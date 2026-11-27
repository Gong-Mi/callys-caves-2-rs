/* generated from CODE 12 (gml_Object_obj_player_Step_0), source start 3770532, end 3803116. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0012(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3770912_0;
    Val p3771100_0;
    Val v4;
    Val v5;
    Val loc_hcollide;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val loc_vcollide;
    Val v13;
    Val v14;
    Val v15;
    Val p3771884_0;
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
    Val p3773192_0;
    Val v46;
    Val v47;
    Val p3773688_0;
    Val v48;
    Val p3773848_0;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val p3774500_0;
    Val v53;
    Val v54;
    Val p3774996_0;
    Val v55;
    Val p3775156_0;
    Val v56;
    Val v57;
    Val p3775652_0;
    Val v58;
    Val v59;
    Val p3775836_0;
    Val v60;
    Val v61;
    Val p3776332_0;
    Val v62;
    Val p3776492_0;
    Val v63;
    Val v64;
    Val p3776988_0;
    Val v65;
    Val v66;
    Val p3777172_0;
    Val v67;
    Val v68;
    Val p3777668_0;
    Val v69;
    Val p3777828_0;
    Val v70;
    Val v71;
    Val p3778324_0;
    Val v72;
    Val v73;
    Val p3778508_0;
    Val v74;
    Val v75;
    Val p3779004_0;
    Val v76;
    Val p3779164_0;
    Val v77;
    Val v78;
    Val p3779660_0;
    Val v79;
    Val v80;
    Val p3779844_0;
    Val v81;
    Val v82;
    Val p3780340_0;
    Val v83;
    Val p3780500_0;
    Val v84;
    Val v85;
    Val p3780996_0;
    Val v86;
    Val v87;
    Val p3781180_0;
    Val v88;
    Val v89;
    Val p3781676_0;
    Val v90;
    Val p3781836_0;
    Val v91;
    Val v92;
    Val p3782332_0;
    Val v93;
    Val v94;
    Val p3782516_0;
    Val v95;
    Val v96;
    Val p3783012_0;
    Val v97;
    Val p3783172_0;
    Val v98;
    Val v99;
    Val p3783668_0;
    Val v100;
    Val v101;
    Val p3783852_0;
    Val v102;
    Val v103;
    Val p3784348_0;
    Val v104;
    Val p3784508_0;
    Val v105;
    Val v106;
    Val p3785024_0;
    Val v107;
    Val v108;
    Val p3785208_0;
    Val v109;
    Val v110;
    Val p3785724_0;
    Val v111;
    Val p3785884_0;
    Val v112;
    Val v113;
    Val p3786380_0;
    Val v114;
    Val v115;
    Val p3786564_0;
    Val v116;
    Val v117;
    Val p3787060_0;
    Val v118;
    Val p3787220_0;
    Val v119;
    Val v120;
    Val p3787716_0;
    Val v121;
    Val v122;
    Val p3787900_0;
    Val v123;
    Val v124;
    Val p3788396_0;
    Val v125;
    Val p3788556_0;
    Val v126;
    Val v127;
    Val p3789052_0;
    Val v128;
    Val v129;
    Val p3789236_0;
    Val v130;
    Val v131;
    Val p3789732_0;
    Val v132;
    Val p3789892_0;
    Val v133;
    Val v134;
    Val p3790388_0;
    Val v135;
    Val v136;
    Val p3790572_0;
    Val v137;
    Val v138;
    Val p3791068_0;
    Val v139;
    Val p3791228_0;
    Val v140;
    Val v141;
    Val p3791724_0;
    Val v142;
    Val v143;
    Val p3791908_0;
    Val v144;
    Val v145;
    Val p3792404_0;
    Val v146;
    Val p3792564_0;
    Val v147;
    Val v148;
    Val p3793060_0;
    Val v149;
    Val v150;
    Val p3793244_0;
    Val v151;
    Val v152;
    Val p3793740_0;
    Val v153;
    Val p3793900_0;
    Val v154;
    Val v155;
    Val p3794396_0;
    Val v156;
    Val v157;
    Val p3794580_0;
    Val v158;
    Val v159;
    Val p3795076_0;
    Val v160;
    Val p3795236_0;
    Val v161;
    Val v162;
    Val p3795732_0;
    Val v163;
    Val v164;
    Val p3795916_0;
    Val v165;
    Val v166;
    Val p3796412_0;
    Val v167;
    Val p3796572_0;
    Val v168;
    Val v169;
    Val p3797068_0;
    Val v170;
    Val v171;
    Val p3797252_0;
    Val v172;
    Val v173;
    Val p3797748_0;
    Val v174;
    Val p3797908_0;
    Val v175;
    Val v176;
    Val p3798404_0;
    Val v177;
    Val v178;
    Val p3798588_0;
    Val v179;
    Val v180;
    Val p3799084_0;
    Val v181;
    Val p3799244_0;
    Val v182;
    Val v183;
    Val p3799740_0;
    Val v184;
    Val v185;
    Val v186;
    Val v187;
    Val v188;
    Val v189;
    Val v190;
    Val v191;
    Val v192;
    Val v193;
    Val v194;
    Val v195;
    Val v196;
    Val v197;
    Val v198;
    Val v199;
    Val v200;
    Val v201;
    Val v202;
    Val v203;
    Val v204;
    Val v205;
    /* @3770532 load */
    /* @3770540 constant */
    /* @3770544 cmp */
    /* @3770548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(1)))) goto L_3770572;
    /* @3770552 load */
    /* @3770560 constant */
    /* @3770564 cmp */
    /* @3770568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "roomstart") == VAL(0)))) goto L_3770572;
    L_3770572: ;
    /* @3770572 load */
    /* @3770580 constant */
    /* @3770584 cmp */
    /* @3770588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sliding1") == VAL(1)))) goto L_3770680;
    /* @3770592 constant */
    /* @3770596 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(36));
    /* @3770604 constant */
    /* @3770608 cast */
    /* @3770612 load */
    /* @3770620 load */
    /* @3770628 constant */
    /* @3770632 sub */
    /* @3770636 call */
    GM_SITE(vm, 12, 3770636);
    /* @3770644 cast */
    /* @3770648 not */
    /* @3770652 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v1)) goto L_3770680;
    /* @3770656 constant */
    /* @3770660 store */
    GM_WRITE(vm, -1, "hsp", VAL(-4));
    /* @3770668 constant */
    /* @3770672 store */
    GM_WRITE(vm, -1, "friction", VAL(3));
    L_3770680: ;
    /* @3770680 load */
    /* @3770688 constant */
    /* @3770692 cmp */
    /* @3770696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(1)))) goto L_3770720;
    /* @3770700 load */
    /* @3770708 constant */
    /* @3770712 cmp */
    /* @3770716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "roomstart") == VAL(0)))) goto L_3770720;
    L_3770720: ;
    /* @3770720 load */
    /* @3770728 constant */
    /* @3770732 cmp */
    /* @3770736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sliding2") == VAL(1)))) goto L_3770828;
    /* @3770740 constant */
    /* @3770744 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(36));
    /* @3770752 constant */
    /* @3770756 cast */
    /* @3770760 load */
    /* @3770768 load */
    /* @3770776 constant */
    /* @3770780 add */
    /* @3770784 call */
    GM_SITE(vm, 12, 3770784);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @3770792 cast */
    /* @3770796 not */
    /* @3770800 bf */
    v3 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v2, GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v3)) goto L_3770828;
    /* @3770804 constant */
    /* @3770808 store */
    GM_WRITE(vm, -1, "hspeed", VAL(4));
    /* @3770816 constant */
    /* @3770820 store */
    GM_WRITE(vm, -1, "friction", VAL(3));
    L_3770828: ;
    /* @3770828 load */
    /* @3770836 constant */
    /* @3770840 cmp */
    /* @3770844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hsp") == VAL(0)))) goto L_3770928;
    /* @3770848 load */
    /* @3770856 constant */
    /* @3770860 cmp */
    /* @3770864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "grounded") == VAL(1)))) goto L_3770928;
    /* @3770868 load */
    /* @3770876 constant */
    /* @3770880 cmp */
    /* @3770884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3770908;
    /* @3770888 load */
    /* @3770896 constant */
    /* @3770900 cmp */
    /* @3770904 b */
    p3770912_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3770912;
    L_3770908: ;
    /* @3770908 constant */
    p3770912_0 = VAL(0);
    L_3770912: ;
    /* @3770912 bf */
    if (!TRUTH(p3770912_0)) goto L_3770928;
    /* @3770916 constant */
    /* @3770920 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(29));
    L_3770928: ;
    /* @3770928 load */
    /* @3770936 constant */
    /* @3770940 cmp */
    /* @3770944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "throwingboomerang") == VAL(1)))) goto L_3770992;
    /* @3770948 load */
    /* @3770956 constant */
    /* @3770960 cmp */
    /* @3770964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(31)))) goto L_3770992;
    /* @3770968 constant */
    /* @3770972 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @3770980 constant */
    /* @3770984 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(31));
    L_3770992: ;
    /* @3770992 load */
    /* @3771000 constant */
    /* @3771004 cmp */
    /* @3771008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "vsp") <= VAL(-1)))) goto L_3771056;
    /* @3771012 load */
    /* @3771020 constant */
    /* @3771024 cmp */
    /* @3771028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(32)))) goto L_3771056;
    /* @3771032 constant */
    /* @3771036 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @3771044 constant */
    /* @3771048 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(32));
    L_3771056: ;
    /* @3771056 load */
    /* @3771064 constant */
    /* @3771068 cmp */
    /* @3771072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "vsp") >= VAL(2)))) goto L_3771096;
    /* @3771076 load */
    /* @3771084 constant */
    /* @3771088 cmp */
    /* @3771092 b */
    p3771100_0 = NUMBOOL(GM_READ(vm, -1, "grounded") == VAL(0));
    goto L_3771100;
    L_3771096: ;
    /* @3771096 constant */
    p3771100_0 = VAL(0);
    L_3771100: ;
    /* @3771100 bf */
    if (!TRUTH(p3771100_0)) goto L_3771148;
    /* @3771104 load */
    /* @3771112 constant */
    /* @3771116 cmp */
    /* @3771120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(33)))) goto L_3771148;
    /* @3771124 constant */
    /* @3771128 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @3771136 constant */
    /* @3771140 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(33));
    L_3771148: ;
    /* @3771148 load */
    /* @3771156 constant */
    /* @3771160 cmp */
    /* @3771164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swing") == VAL(0)))) goto L_3771180;
    /* @3771168 constant */
    /* @3771172 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(31));
    L_3771180: ;
    /* @3771180 load */
    /* @3771188 load */
    /* @3771196 add */
    /* @3771200 store */
    v4 = GM_ADD(GM_READ(vm, -1, "vsp"), GM_READ(vm, -1, "grav"));
    GM_WRITE(vm, -1, "vsp", v4);
    /* @3771208 constant */
    /* @3771212 cast */
    /* @3771216 load */
    /* @3771224 load */
    /* @3771232 load */
    /* @3771240 add */
    /* @3771244 call */
    GM_SITE(vm, 12, 3771244);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hsp"));
    /* @3771252 store_local */
    loc_hcollide = GM_CALL(vm, "instance_place", 3, v5, GM_READ(vm, -1, "y"), VAL(34));
    /* @3771260 constant */
    /* @3771264 cast */
    /* @3771268 load */
    /* @3771276 load */
    /* @3771284 load */
    /* @3771292 add */
    /* @3771296 call */
    GM_SITE(vm, 12, 3771296);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hsp"));
    /* @3771304 cast */
    /* @3771308 bf */
    v7 = BOOL(GM_CALL(vm, "place_meeting", 3, v6, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v7)) goto L_3771460;
    /* @3771312 load_local */
    /* @3771320 cast */
    /* @3771324 load */
    /* @3771332 constant */
    /* @3771336 cmp */
    /* @3771340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(loc_hcollide), "type") == VAL(1)))) goto L_3771460;
    L_3771344: ;
    /* @3771344 constant */
    /* @3771348 cast */
    /* @3771352 load */
    /* @3771360 load */
    /* @3771368 load */
    /* @3771376 call */
    GM_SITE(vm, 12, 3771376);
    /* @3771384 add */
    /* @3771388 call */
    GM_SITE(vm, 12, 3771388);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "hsp")));
    /* @3771396 cast */
    /* @3771400 not */
    /* @3771404 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "place_meeting", 3, v8, GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v9)) goto L_3771448;
    /* @3771408 load */
    /* @3771416 load */
    /* @3771424 call */
    GM_SITE(vm, 12, 3771424);
    /* @3771432 add */
    /* @3771436 store */
    v10 = GM_ADD(GM_READ(vm, -1, "x"), GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "hsp")));
    GM_WRITE(vm, -1, "x", v10);
    /* @3771444 b */
    goto L_3771344;
    L_3771448: ;
    /* @3771448 constant */
    /* @3771452 store */
    GM_WRITE(vm, -1, "hsp", VAL(0));
    L_3771460: ;
    /* @3771460 load */
    /* @3771468 load */
    /* @3771476 add */
    /* @3771480 store */
    v11 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hsp"));
    GM_WRITE(vm, -1, "x", v11);
    /* @3771488 constant */
    /* @3771492 cast */
    /* @3771496 load */
    /* @3771504 load */
    /* @3771512 add */
    /* @3771516 load */
    /* @3771524 call */
    GM_SITE(vm, 12, 3771524);
    v12 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vsp"));
    /* @3771532 store_local */
    loc_vcollide = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v12, VAL(34));
    /* @3771540 load_local */
    /* @3771548 constant */
    /* @3771552 cmp */
    /* @3771556 bf */
    if (!TRUTH(NUMBOOL(loc_vcollide != VAL(-4)))) goto L_3772076;
    /* @3771560 load_local */
    /* @3771568 cast */
    /* @3771572 load */
    /* @3771580 constant */
    /* @3771584 cmp */
    /* @3771588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(loc_vcollide), "type") == VAL(1)))) goto L_3771820;
    L_3771592: ;
    /* @3771592 constant */
    /* @3771596 cast */
    /* @3771600 load */
    /* @3771608 load */
    /* @3771616 call */
    GM_SITE(vm, 12, 3771616);
    /* @3771624 add */
    /* @3771628 load */
    /* @3771636 call */
    GM_SITE(vm, 12, 3771636);
    v13 = GM_ADD(GM_READ(vm, -1, "y"), GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "vsp")));
    /* @3771644 cast */
    /* @3771648 not */
    /* @3771652 bf */
    v14 = NOT(BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v13, VAL(34))));
    if (!TRUTH(v14)) goto L_3771696;
    /* @3771656 load */
    /* @3771664 load */
    /* @3771672 call */
    GM_SITE(vm, 12, 3771672);
    /* @3771680 add */
    /* @3771684 store */
    v15 = GM_ADD(GM_READ(vm, -1, "y"), GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "vsp")));
    GM_WRITE(vm, -1, "y", v15);
    /* @3771692 b */
    goto L_3771592;
    L_3771696: ;
    /* @3771696 load_local */
    /* @3771704 cast */
    /* @3771708 load */
    /* @3771716 load */
    /* @3771724 cmp */
    /* @3771728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(loc_vcollide), "y") < GM_READ(vm, -1, "y")))) goto L_3771736;
    /* @3771732 b */
    goto L_3771796;
    L_3771736: ;
    /* @3771736 load_local */
    /* @3771744 cast */
    /* @3771748 load */
    /* @3771756 load */
    /* @3771764 cmp */
    /* @3771768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(loc_vcollide), "y") >= GM_READ(vm, -1, "y")))) goto L_3771796;
    /* @3771772 constant */
    /* @3771776 store */
    GM_WRITE(vm, -1, "tjump", VAL(1));
    /* @3771784 constant */
    /* @3771788 store */
    GM_WRITE(vm, -1, "djump", VAL(1));
    L_3771796: ;
    /* @3771796 constant */
    /* @3771800 store */
    GM_WRITE(vm, -1, "grounded", VAL(1));
    /* @3771808 constant */
    /* @3771812 store */
    GM_WRITE(vm, -1, "vsp", VAL(0));
    L_3771820: ;
    /* @3771820 load_local */
    /* @3771828 cast */
    /* @3771832 load */
    /* @3771840 constant */
    /* @3771844 cmp */
    /* @3771848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(loc_vcollide), "type") == VAL(2)))) goto L_3771880;
    /* @3771852 load */
    /* @3771860 call */
    GM_SITE(vm, 12, 3771860);
    /* @3771868 constant */
    /* @3771872 cmp */
    /* @3771876 b */
    v16 = NUMBOOL(GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "vsp")) == VAL(1));
    p3771884_0 = v16;
    goto L_3771884;
    L_3771880: ;
    /* @3771880 constant */
    p3771884_0 = VAL(0);
    L_3771884: ;
    /* @3771884 bf */
    if (!TRUTH(p3771884_0)) goto L_3772072;
    /* @3771888 constant */
    /* @3771892 cast */
    /* @3771896 load */
    /* @3771904 load */
    /* @3771912 call */
    GM_SITE(vm, 12, 3771912);
    /* @3771920 cast */
    /* @3771924 not */
    /* @3771928 bf */
    v17 = NOT(BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34))));
    if (!TRUTH(v17)) goto L_3772072;
    L_3771932: ;
    /* @3771932 constant */
    /* @3771936 cast */
    /* @3771940 load */
    /* @3771948 load */
    /* @3771956 call */
    GM_SITE(vm, 12, 3771956);
    /* @3771964 add */
    /* @3771968 load */
    /* @3771976 call */
    GM_SITE(vm, 12, 3771976);
    v18 = GM_ADD(GM_READ(vm, -1, "y"), GM_CALL(vm, "sign", 1, GM_READ(vm, -1, "vsp")));
    /* @3771984 cast */
    /* @3771988 not */
    /* @3771992 bf */
    v19 = NOT(BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v18, VAL(34))));
    if (!TRUTH(v19)) goto L_3772024;
    /* @3771996 load */
    /* @3772004 constant */
    /* @3772008 add */
    /* @3772012 store */
    v20 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    GM_WRITE(vm, -1, "y", v20);
    /* @3772020 b */
    goto L_3771932;
    L_3772024: ;
    /* @3772024 constant */
    /* @3772028 store */
    GM_WRITE(vm, -1, "vsp", VAL(0));
    /* @3772036 constant */
    /* @3772040 store */
    GM_WRITE(vm, -1, "grounded", VAL(1));
    /* @3772048 constant */
    /* @3772052 store */
    GM_WRITE(vm, -1, "djump", VAL(1));
    /* @3772060 constant */
    /* @3772064 store */
    GM_WRITE(vm, -1, "tjump", VAL(1));
    L_3772072: ;
    /* @3772072 b */
    goto L_3772088;
    L_3772076: ;
    /* @3772076 constant */
    /* @3772080 store */
    GM_WRITE(vm, -1, "grounded", VAL(0));
    L_3772088: ;
    /* @3772088 load */
    /* @3772096 load */
    /* @3772104 add */
    /* @3772108 store */
    v21 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vsp"));
    GM_WRITE(vm, -1, "y", v21);
    /* @3772116 constant */
    /* @3772120 cast */
    /* @3772124 load */
    /* @3772132 constant */
    /* @3772136 sub */
    /* @3772140 load */
    /* @3772148 call */
    GM_SITE(vm, 12, 3772148);
    /* @3772156 cast */
    /* @3772160 bf */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(12)), VAL(34)));
    if (!TRUTH(v22)) goto L_3772176;
    /* @3772164 constant */
    /* @3772168 store */
    GM_WRITE(vm, -1, "grounded", VAL(0));
    L_3772176: ;
    /* @3772176 load */
    /* @3772184 constant */
    /* @3772188 sub */
    /* @3772192 load */
    /* @3772200 call */
    GM_SITE(vm, 12, 3772200);
    /* @3772208 store */
    v23 = GM_CALL(vm, "min", 2, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "room_width") - VAL(1)));
    GM_WRITE(vm, -1, "x", v23);
    /* @3772216 constant */
    /* @3772220 cast */
    /* @3772224 load */
    /* @3772232 call */
    GM_SITE(vm, 12, 3772232);
    /* @3772240 store */
    v24 = GM_CALL(vm, "max", 2, GM_READ(vm, -1, "x"), VAL(1));
    GM_WRITE(vm, -1, "x", v24);
    /* @3772248 load */
    /* @3772256 constant */
    /* @3772260 cmp */
    /* @3772264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3772284;
    /* @3772268 constant */
    /* @3772276 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3772284: ;
    /* @3772284 constant */
    /* @3772288 cast */
    /* @3772292 load */
    /* @3772300 load */
    /* @3772308 call */
    GM_SITE(vm, 12, 3772308);
    /* @3772316 store */
    v25 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hitenemy", v25);
    /* @3772324 constant */
    /* @3772328 cast */
    /* @3772332 load */
    /* @3772340 load */
    /* @3772348 call */
    GM_SITE(vm, 12, 3772348);
    /* @3772356 store */
    v26 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hitenemy2", v26);
    /* @3772364 constant */
    /* @3772368 cast */
    /* @3772372 load */
    /* @3772380 load */
    /* @3772388 call */
    GM_SITE(vm, 12, 3772388);
    /* @3772396 store */
    v27 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hitenemytrex", v27);
    /* @3772404 constant */
    /* @3772408 cast */
    /* @3772412 load */
    /* @3772420 load */
    /* @3772428 call */
    GM_SITE(vm, 12, 3772428);
    /* @3772436 store */
    v28 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hitenemybat", v28);
    /* @3772444 constant */
    /* @3772448 cast */
    /* @3772452 load */
    /* @3772460 load */
    /* @3772468 call */
    GM_SITE(vm, 12, 3772468);
    /* @3772476 store */
    v29 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hitenemyslime", v29);
    /* @3772484 constant */
    /* @3772488 cast */
    /* @3772492 load */
    /* @3772500 load */
    /* @3772508 call */
    GM_SITE(vm, 12, 3772508);
    /* @3772516 store */
    v30 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hitenemyghost", v30);
    /* @3772524 constant */
    /* @3772528 cast */
    /* @3772532 load */
    /* @3772540 load */
    /* @3772548 call */
    GM_SITE(vm, 12, 3772548);
    /* @3772556 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hitenemyshooter1", v31);
    /* @3772564 constant */
    /* @3772568 cast */
    /* @3772572 load */
    /* @3772580 load */
    /* @3772588 call */
    GM_SITE(vm, 12, 3772588);
    /* @3772596 store */
    v32 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hitenemyshooter2", v32);
    /* @3772604 constant */
    /* @3772608 cast */
    /* @3772612 load */
    /* @3772620 load */
    /* @3772628 call */
    GM_SITE(vm, 12, 3772628);
    /* @3772636 store */
    v33 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hitenemyfireslime", v33);
    /* @3772644 constant */
    /* @3772648 cast */
    /* @3772652 load */
    /* @3772660 load */
    /* @3772668 call */
    GM_SITE(vm, 12, 3772668);
    /* @3772676 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hitenemyhulkingbandit", v34);
    /* @3772684 constant */
    /* @3772688 cast */
    /* @3772692 load */
    /* @3772700 load */
    /* @3772708 call */
    GM_SITE(vm, 12, 3772708);
    /* @3772716 store */
    v35 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hitenemyzombie", v35);
    /* @3772724 constant */
    /* @3772728 cast */
    /* @3772732 load */
    /* @3772740 load */
    /* @3772748 call */
    GM_SITE(vm, 12, 3772748);
    /* @3772756 store */
    v36 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hitfirehulk", v36);
    /* @3772764 constant */
    /* @3772768 cast */
    /* @3772772 load */
    /* @3772780 load */
    /* @3772788 call */
    GM_SITE(vm, 12, 3772788);
    /* @3772796 store */
    v37 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hitenemyskeleton", v37);
    /* @3772804 constant */
    /* @3772808 cast */
    /* @3772812 load */
    /* @3772820 load */
    /* @3772828 call */
    GM_SITE(vm, 12, 3772828);
    /* @3772836 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hitboss2", v38);
    /* @3772844 constant */
    /* @3772848 cast */
    /* @3772852 load */
    /* @3772860 load */
    /* @3772868 call */
    GM_SITE(vm, 12, 3772868);
    /* @3772876 store */
    v39 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hitboss3", v39);
    /* @3772884 constant */
    /* @3772888 cast */
    /* @3772892 load */
    /* @3772900 load */
    /* @3772908 call */
    GM_SITE(vm, 12, 3772908);
    /* @3772916 store */
    v40 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v40);
    /* @3772924 constant */
    /* @3772928 cast */
    /* @3772932 load */
    /* @3772940 load */
    /* @3772948 call */
    GM_SITE(vm, 12, 3772948);
    /* @3772956 store */
    v41 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v41);
    /* @3772964 constant */
    /* @3772968 cast */
    /* @3772972 load */
    /* @3772980 load */
    /* @3772988 call */
    GM_SITE(vm, 12, 3772988);
    /* @3772996 store */
    v42 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hitfinalboss", v42);
    /* @3773004 constant */
    /* @3773008 cast */
    /* @3773012 load */
    /* @3773020 load */
    /* @3773028 call */
    GM_SITE(vm, 12, 3773028);
    /* @3773036 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknifebandit", v43);
    /* @3773044 constant */
    /* @3773048 cast */
    /* @3773052 load */
    /* @3773060 load */
    /* @3773068 call */
    GM_SITE(vm, 12, 3773068);
    /* @3773076 store */
    v44 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v44);
    /* @3773084 constant */
    /* @3773088 cast */
    /* @3773092 call */
    GM_SITE(vm, 12, 3773092);
    /* @3773100 cast */
    /* @3773104 bf */
    v45 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(15)));
    if (!TRUTH(v45)) goto L_3774392;
    /* @3773108 load */
    /* @3773116 constant */
    /* @3773120 cmp */
    /* @3773124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknifebandit") != VAL(-4)))) goto L_3773764;
    /* @3773128 load */
    /* @3773136 constant */
    /* @3773140 cmp */
    /* @3773144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3773764;
    /* @3773148 load */
    /* @3773156 constant */
    /* @3773160 cmp */
    /* @3773164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3773188;
    /* @3773168 load */
    /* @3773176 constant */
    /* @3773180 cmp */
    /* @3773184 b */
    p3773192_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3773192;
    L_3773188: ;
    /* @3773188 constant */
    p3773192_0 = VAL(0);
    L_3773192: ;
    /* @3773192 bf */
    if (!TRUTH(p3773192_0)) goto L_3773764;
    /* @3773196 load */
    /* @3773204 constant */
    /* @3773208 cmp */
    /* @3773212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3773584;
    /* @3773216 constant */
    /* @3773220 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3773228 load */
    /* @3773236 constant */
    /* @3773240 sub */
    /* @3773244 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3773252 load */
    /* @3773260 cast */
    /* @3773264 load */
    /* @3773272 load */
    /* @3773280 cmp */
    /* @3773284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknifebandit")), "x") > GM_READ(vm, -1, "x")))) goto L_3773316;
    /* @3773288 constant */
    /* @3773292 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3773300 constant */
    /* @3773304 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3773312 b */
    goto L_3773376;
    L_3773316: ;
    /* @3773316 load */
    /* @3773324 cast */
    /* @3773328 load */
    /* @3773336 load */
    /* @3773344 cmp */
    /* @3773348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknifebandit")), "x") < GM_READ(vm, -1, "x")))) goto L_3773376;
    /* @3773352 constant */
    /* @3773356 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3773364 constant */
    /* @3773368 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    L_3773376: ;
    /* @3773376 constant */
    /* @3773380 constant */
    /* @3773384 constant */
    /* @3773388 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3773396 constant */
    /* @3773400 constant */
    /* @3773404 constant */
    /* @3773408 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3773416 constant */
    /* @3773420 constant */
    /* @3773424 constant */
    /* @3773428 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3773436 load */
    /* @3773444 constant */
    /* @3773448 cmp */
    /* @3773452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3773460;
    /* @3773456 b */
    goto L_3773516;
    L_3773460: ;
    /* @3773460 load */
    /* @3773468 constant */
    /* @3773472 cmp */
    /* @3773476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3773516;
    /* @3773480 constant */
    /* @3773484 cast */
    /* @3773488 constant */
    /* @3773492 cast */
    /* @3773496 constant */
    /* @3773500 cast */
    /* @3773504 call */
    GM_SITE(vm, 12, 3773504);
    /* @3773512 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3773516: ;
    /* @3773516 constant */
    /* @3773520 cast */
    /* @3773524 load */
    /* @3773532 load */
    /* @3773540 load */
    /* @3773548 add */
    /* @3773552 call */
    GM_SITE(vm, 12, 3773552);
    v46 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3773560 cast */
    /* @3773564 bf */
    v47 = BOOL(GM_CALL(vm, "place_meeting", 3, v46, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v47)) goto L_3773580;
    /* @3773568 constant */
    /* @3773572 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3773580: ;
    /* @3773580 b */
    goto L_3773764;
    L_3773584: ;
    /* @3773584 load */
    /* @3773592 constant */
    /* @3773596 cmp */
    /* @3773600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3773764;
    /* @3773604 load */
    /* @3773612 constant */
    /* @3773616 cmp */
    /* @3773620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknifebandit") != VAL(-4)))) goto L_3773764;
    /* @3773624 load */
    /* @3773632 constant */
    /* @3773636 cmp */
    /* @3773640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3773764;
    /* @3773644 load */
    /* @3773652 constant */
    /* @3773656 cmp */
    /* @3773660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3773684;
    /* @3773664 load */
    /* @3773672 constant */
    /* @3773676 cmp */
    /* @3773680 b */
    p3773688_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3773688;
    L_3773684: ;
    /* @3773684 constant */
    p3773688_0 = VAL(0);
    L_3773688: ;
    /* @3773688 bf */
    if (!TRUTH(p3773688_0)) goto L_3773764;
    /* @3773692 constant */
    /* @3773696 cast */
    /* @3773700 call */
    GM_SITE(vm, 12, 3773700);
    /* @3773708 cast */
    /* @3773712 not */
    /* @3773716 bf */
    v48 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v48)) goto L_3773764;
    /* @3773720 constant */
    /* @3773724 cast */
    /* @3773728 load */
    /* @3773736 constant */
    /* @3773740 sub */
    /* @3773744 load */
    /* @3773752 call */
    GM_SITE(vm, 12, 3773752);
    /* @3773760 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3773764: ;
    /* @3773764 load */
    /* @3773772 constant */
    /* @3773776 cmp */
    /* @3773780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknifebandit") != VAL(-4)))) goto L_3774392;
    /* @3773784 load */
    /* @3773792 constant */
    /* @3773796 cmp */
    /* @3773800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3774392;
    /* @3773804 load */
    /* @3773812 constant */
    /* @3773816 cmp */
    /* @3773820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3773844;
    /* @3773824 load */
    /* @3773832 constant */
    /* @3773836 cmp */
    /* @3773840 b */
    p3773848_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3773848;
    L_3773844: ;
    /* @3773844 constant */
    p3773848_0 = VAL(0);
    L_3773848: ;
    /* @3773848 bf */
    if (!TRUTH(p3773848_0)) goto L_3774392;
    /* @3773852 load */
    /* @3773860 constant */
    /* @3773864 cmp */
    /* @3773868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3774240;
    /* @3773872 constant */
    /* @3773876 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3773884 load */
    /* @3773892 constant */
    /* @3773896 sub */
    /* @3773900 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3773908 load */
    /* @3773916 cast */
    /* @3773920 load */
    /* @3773928 load */
    /* @3773936 cmp */
    /* @3773940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknifebandit")), "x") > GM_READ(vm, -1, "x")))) goto L_3773972;
    /* @3773944 constant */
    /* @3773948 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3773956 constant */
    /* @3773960 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3773968 b */
    goto L_3774032;
    L_3773972: ;
    /* @3773972 load */
    /* @3773980 cast */
    /* @3773984 load */
    /* @3773992 load */
    /* @3774000 cmp */
    /* @3774004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknifebandit")), "x") < GM_READ(vm, -1, "x")))) goto L_3774032;
    /* @3774008 constant */
    /* @3774012 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3774020 constant */
    /* @3774024 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3774032: ;
    /* @3774032 constant */
    /* @3774036 constant */
    /* @3774040 constant */
    /* @3774044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3774052 constant */
    /* @3774056 constant */
    /* @3774060 constant */
    /* @3774064 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3774072 constant */
    /* @3774076 constant */
    /* @3774080 constant */
    /* @3774084 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3774092 load */
    /* @3774100 constant */
    /* @3774104 cmp */
    /* @3774108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3774116;
    /* @3774112 b */
    goto L_3774172;
    L_3774116: ;
    /* @3774116 load */
    /* @3774124 constant */
    /* @3774128 cmp */
    /* @3774132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3774172;
    /* @3774136 constant */
    /* @3774140 cast */
    /* @3774144 constant */
    /* @3774148 cast */
    /* @3774152 constant */
    /* @3774156 cast */
    /* @3774160 call */
    GM_SITE(vm, 12, 3774160);
    /* @3774168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3774172: ;
    /* @3774172 constant */
    /* @3774176 cast */
    /* @3774180 load */
    /* @3774188 load */
    /* @3774196 load */
    /* @3774204 add */
    /* @3774208 call */
    GM_SITE(vm, 12, 3774208);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3774216 cast */
    /* @3774220 bf */
    v50 = BOOL(GM_CALL(vm, "place_meeting", 3, v49, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v50)) goto L_3774236;
    /* @3774224 constant */
    /* @3774228 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3774236: ;
    /* @3774236 b */
    goto L_3774392;
    L_3774240: ;
    /* @3774240 load */
    /* @3774248 constant */
    /* @3774252 cmp */
    /* @3774256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3774392;
    /* @3774260 load */
    /* @3774268 constant */
    /* @3774272 cmp */
    /* @3774276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknifebandit") != VAL(-4)))) goto L_3774392;
    /* @3774280 load */
    /* @3774288 constant */
    /* @3774292 cmp */
    /* @3774296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3774392;
    /* @3774300 load */
    /* @3774308 constant */
    /* @3774312 cmp */
    /* @3774316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3774392;
    /* @3774320 constant */
    /* @3774324 cast */
    /* @3774328 call */
    GM_SITE(vm, 12, 3774328);
    /* @3774336 cast */
    /* @3774340 not */
    /* @3774344 bf */
    v51 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v51)) goto L_3774392;
    /* @3774348 constant */
    /* @3774352 cast */
    /* @3774356 load */
    /* @3774364 constant */
    /* @3774368 sub */
    /* @3774372 load */
    /* @3774380 call */
    GM_SITE(vm, 12, 3774380);
    /* @3774388 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3774392: ;
    /* @3774392 constant */
    /* @3774396 cast */
    /* @3774400 call */
    GM_SITE(vm, 12, 3774400);
    /* @3774408 cast */
    /* @3774412 bf */
    v52 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(23)));
    if (!TRUTH(v52)) goto L_3775728;
    /* @3774416 load */
    /* @3774424 constant */
    /* @3774428 cmp */
    /* @3774432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_3775072;
    /* @3774436 load */
    /* @3774444 constant */
    /* @3774448 cmp */
    /* @3774452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3775072;
    /* @3774456 load */
    /* @3774464 constant */
    /* @3774468 cmp */
    /* @3774472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3774496;
    /* @3774476 load */
    /* @3774484 constant */
    /* @3774488 cmp */
    /* @3774492 b */
    p3774500_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3774500;
    L_3774496: ;
    /* @3774496 constant */
    p3774500_0 = VAL(0);
    L_3774500: ;
    /* @3774500 bf */
    if (!TRUTH(p3774500_0)) goto L_3775072;
    /* @3774504 load */
    /* @3774512 constant */
    /* @3774516 cmp */
    /* @3774520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3774892;
    /* @3774524 constant */
    /* @3774528 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3774536 load */
    /* @3774544 constant */
    /* @3774548 sub */
    /* @3774552 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3774560 load */
    /* @3774568 cast */
    /* @3774572 load */
    /* @3774580 load */
    /* @3774588 cmp */
    /* @3774592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x") > GM_READ(vm, -1, "x")))) goto L_3774624;
    /* @3774596 constant */
    /* @3774600 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3774608 constant */
    /* @3774612 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3774620 b */
    goto L_3774684;
    L_3774624: ;
    /* @3774624 load */
    /* @3774632 cast */
    /* @3774636 load */
    /* @3774644 load */
    /* @3774652 cmp */
    /* @3774656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x") < GM_READ(vm, -1, "x")))) goto L_3774684;
    /* @3774660 constant */
    /* @3774664 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3774672 constant */
    /* @3774676 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3774684: ;
    /* @3774684 constant */
    /* @3774688 constant */
    /* @3774692 constant */
    /* @3774696 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3774704 constant */
    /* @3774708 constant */
    /* @3774712 constant */
    /* @3774716 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3774724 constant */
    /* @3774728 constant */
    /* @3774732 constant */
    /* @3774736 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3774744 load */
    /* @3774752 constant */
    /* @3774756 cmp */
    /* @3774760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3774768;
    /* @3774764 b */
    goto L_3774824;
    L_3774768: ;
    /* @3774768 load */
    /* @3774776 constant */
    /* @3774780 cmp */
    /* @3774784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3774824;
    /* @3774788 constant */
    /* @3774792 cast */
    /* @3774796 constant */
    /* @3774800 cast */
    /* @3774804 constant */
    /* @3774808 cast */
    /* @3774812 call */
    GM_SITE(vm, 12, 3774812);
    /* @3774820 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3774824: ;
    /* @3774824 constant */
    /* @3774828 cast */
    /* @3774832 load */
    /* @3774840 load */
    /* @3774848 load */
    /* @3774856 add */
    /* @3774860 call */
    GM_SITE(vm, 12, 3774860);
    v53 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3774868 cast */
    /* @3774872 bf */
    v54 = BOOL(GM_CALL(vm, "place_meeting", 3, v53, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v54)) goto L_3774888;
    /* @3774876 constant */
    /* @3774880 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3774888: ;
    /* @3774888 b */
    goto L_3775072;
    L_3774892: ;
    /* @3774892 load */
    /* @3774900 constant */
    /* @3774904 cmp */
    /* @3774908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3775072;
    /* @3774912 load */
    /* @3774920 constant */
    /* @3774924 cmp */
    /* @3774928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_3775072;
    /* @3774932 load */
    /* @3774940 constant */
    /* @3774944 cmp */
    /* @3774948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3775072;
    /* @3774952 load */
    /* @3774960 constant */
    /* @3774964 cmp */
    /* @3774968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3774992;
    /* @3774972 load */
    /* @3774980 constant */
    /* @3774984 cmp */
    /* @3774988 b */
    p3774996_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3774996;
    L_3774992: ;
    /* @3774992 constant */
    p3774996_0 = VAL(0);
    L_3774996: ;
    /* @3774996 bf */
    if (!TRUTH(p3774996_0)) goto L_3775072;
    /* @3775000 constant */
    /* @3775004 cast */
    /* @3775008 call */
    GM_SITE(vm, 12, 3775008);
    /* @3775016 cast */
    /* @3775020 not */
    /* @3775024 bf */
    v55 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v55)) goto L_3775072;
    /* @3775028 constant */
    /* @3775032 cast */
    /* @3775036 load */
    /* @3775044 constant */
    /* @3775048 sub */
    /* @3775052 load */
    /* @3775060 call */
    GM_SITE(vm, 12, 3775060);
    /* @3775068 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3775072: ;
    /* @3775072 load */
    /* @3775080 constant */
    /* @3775084 cmp */
    /* @3775088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_3775728;
    /* @3775092 load */
    /* @3775100 constant */
    /* @3775104 cmp */
    /* @3775108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3775728;
    /* @3775112 load */
    /* @3775120 constant */
    /* @3775124 cmp */
    /* @3775128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3775152;
    /* @3775132 load */
    /* @3775140 constant */
    /* @3775144 cmp */
    /* @3775148 b */
    p3775156_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3775156;
    L_3775152: ;
    /* @3775152 constant */
    p3775156_0 = VAL(0);
    L_3775156: ;
    /* @3775156 bf */
    if (!TRUTH(p3775156_0)) goto L_3775728;
    /* @3775160 load */
    /* @3775168 constant */
    /* @3775172 cmp */
    /* @3775176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3775548;
    /* @3775180 constant */
    /* @3775184 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3775192 load */
    /* @3775200 constant */
    /* @3775204 sub */
    /* @3775208 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3775216 load */
    /* @3775224 cast */
    /* @3775228 load */
    /* @3775236 load */
    /* @3775244 cmp */
    /* @3775248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x") > GM_READ(vm, -1, "x")))) goto L_3775280;
    /* @3775252 constant */
    /* @3775256 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3775264 constant */
    /* @3775268 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3775276 b */
    goto L_3775340;
    L_3775280: ;
    /* @3775280 load */
    /* @3775288 cast */
    /* @3775292 load */
    /* @3775300 load */
    /* @3775308 cmp */
    /* @3775312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "x") < GM_READ(vm, -1, "x")))) goto L_3775340;
    /* @3775316 constant */
    /* @3775320 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3775328 constant */
    /* @3775332 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3775340: ;
    /* @3775340 constant */
    /* @3775344 constant */
    /* @3775348 constant */
    /* @3775352 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3775360 constant */
    /* @3775364 constant */
    /* @3775368 constant */
    /* @3775372 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3775380 constant */
    /* @3775384 constant */
    /* @3775388 constant */
    /* @3775392 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3775400 load */
    /* @3775408 constant */
    /* @3775412 cmp */
    /* @3775416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3775424;
    /* @3775420 b */
    goto L_3775480;
    L_3775424: ;
    /* @3775424 load */
    /* @3775432 constant */
    /* @3775436 cmp */
    /* @3775440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3775480;
    /* @3775444 constant */
    /* @3775448 cast */
    /* @3775452 constant */
    /* @3775456 cast */
    /* @3775460 constant */
    /* @3775464 cast */
    /* @3775468 call */
    GM_SITE(vm, 12, 3775468);
    /* @3775476 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3775480: ;
    /* @3775480 constant */
    /* @3775484 cast */
    /* @3775488 load */
    /* @3775496 load */
    /* @3775504 load */
    /* @3775512 add */
    /* @3775516 call */
    GM_SITE(vm, 12, 3775516);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3775524 cast */
    /* @3775528 bf */
    v57 = BOOL(GM_CALL(vm, "place_meeting", 3, v56, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v57)) goto L_3775544;
    /* @3775532 constant */
    /* @3775536 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3775544: ;
    /* @3775544 b */
    goto L_3775728;
    L_3775548: ;
    /* @3775548 load */
    /* @3775556 constant */
    /* @3775560 cmp */
    /* @3775564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3775728;
    /* @3775568 load */
    /* @3775576 constant */
    /* @3775580 cmp */
    /* @3775584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_3775728;
    /* @3775588 load */
    /* @3775596 constant */
    /* @3775600 cmp */
    /* @3775604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3775728;
    /* @3775608 load */
    /* @3775616 constant */
    /* @3775620 cmp */
    /* @3775624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3775648;
    /* @3775628 load */
    /* @3775636 constant */
    /* @3775640 cmp */
    /* @3775644 b */
    p3775652_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3775652;
    L_3775648: ;
    /* @3775648 constant */
    p3775652_0 = VAL(0);
    L_3775652: ;
    /* @3775652 bf */
    if (!TRUTH(p3775652_0)) goto L_3775728;
    /* @3775656 constant */
    /* @3775660 cast */
    /* @3775664 call */
    GM_SITE(vm, 12, 3775664);
    /* @3775672 cast */
    /* @3775676 not */
    /* @3775680 bf */
    v58 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v58)) goto L_3775728;
    /* @3775684 constant */
    /* @3775688 cast */
    /* @3775692 load */
    /* @3775700 constant */
    /* @3775704 sub */
    /* @3775708 load */
    /* @3775716 call */
    GM_SITE(vm, 12, 3775716);
    /* @3775724 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3775728: ;
    /* @3775728 constant */
    /* @3775732 cast */
    /* @3775736 call */
    GM_SITE(vm, 12, 3775736);
    /* @3775744 cast */
    /* @3775748 bf */
    v59 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(14)));
    if (!TRUTH(v59)) goto L_3777064;
    /* @3775752 load */
    /* @3775760 constant */
    /* @3775764 cmp */
    /* @3775768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy") != VAL(-4)))) goto L_3776408;
    /* @3775772 load */
    /* @3775780 constant */
    /* @3775784 cmp */
    /* @3775788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3776408;
    /* @3775792 load */
    /* @3775800 constant */
    /* @3775804 cmp */
    /* @3775808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3775832;
    /* @3775812 load */
    /* @3775820 constant */
    /* @3775824 cmp */
    /* @3775828 b */
    p3775836_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3775836;
    L_3775832: ;
    /* @3775832 constant */
    p3775836_0 = VAL(0);
    L_3775836: ;
    /* @3775836 bf */
    if (!TRUTH(p3775836_0)) goto L_3776408;
    /* @3775840 load */
    /* @3775848 constant */
    /* @3775852 cmp */
    /* @3775856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3776228;
    /* @3775860 constant */
    /* @3775864 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3775872 load */
    /* @3775880 constant */
    /* @3775884 sub */
    /* @3775888 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3775896 load */
    /* @3775904 cast */
    /* @3775908 load */
    /* @3775916 load */
    /* @3775924 cmp */
    /* @3775928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy")), "x") > GM_READ(vm, -1, "x")))) goto L_3775960;
    /* @3775932 constant */
    /* @3775936 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3775944 constant */
    /* @3775948 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3775956 b */
    goto L_3776020;
    L_3775960: ;
    /* @3775960 load */
    /* @3775968 cast */
    /* @3775972 load */
    /* @3775980 load */
    /* @3775988 cmp */
    /* @3775992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy")), "x") < GM_READ(vm, -1, "x")))) goto L_3776020;
    /* @3775996 constant */
    /* @3776000 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3776008 constant */
    /* @3776012 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3776020: ;
    /* @3776020 constant */
    /* @3776024 constant */
    /* @3776028 constant */
    /* @3776032 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3776040 constant */
    /* @3776044 constant */
    /* @3776048 constant */
    /* @3776052 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3776060 constant */
    /* @3776064 constant */
    /* @3776068 constant */
    /* @3776072 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3776080 load */
    /* @3776088 constant */
    /* @3776092 cmp */
    /* @3776096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3776104;
    /* @3776100 b */
    goto L_3776160;
    L_3776104: ;
    /* @3776104 load */
    /* @3776112 constant */
    /* @3776116 cmp */
    /* @3776120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3776160;
    /* @3776124 constant */
    /* @3776128 cast */
    /* @3776132 constant */
    /* @3776136 cast */
    /* @3776140 constant */
    /* @3776144 cast */
    /* @3776148 call */
    GM_SITE(vm, 12, 3776148);
    /* @3776156 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3776160: ;
    /* @3776160 constant */
    /* @3776164 cast */
    /* @3776168 load */
    /* @3776176 load */
    /* @3776184 load */
    /* @3776192 add */
    /* @3776196 call */
    GM_SITE(vm, 12, 3776196);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3776204 cast */
    /* @3776208 bf */
    v61 = BOOL(GM_CALL(vm, "place_meeting", 3, v60, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v61)) goto L_3776224;
    /* @3776212 constant */
    /* @3776216 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3776224: ;
    /* @3776224 b */
    goto L_3776408;
    L_3776228: ;
    /* @3776228 load */
    /* @3776236 constant */
    /* @3776240 cmp */
    /* @3776244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3776408;
    /* @3776248 load */
    /* @3776256 constant */
    /* @3776260 cmp */
    /* @3776264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy") != VAL(-4)))) goto L_3776408;
    /* @3776268 load */
    /* @3776276 constant */
    /* @3776280 cmp */
    /* @3776284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3776408;
    /* @3776288 load */
    /* @3776296 constant */
    /* @3776300 cmp */
    /* @3776304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3776328;
    /* @3776308 load */
    /* @3776316 constant */
    /* @3776320 cmp */
    /* @3776324 b */
    p3776332_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3776332;
    L_3776328: ;
    /* @3776328 constant */
    p3776332_0 = VAL(0);
    L_3776332: ;
    /* @3776332 bf */
    if (!TRUTH(p3776332_0)) goto L_3776408;
    /* @3776336 constant */
    /* @3776340 cast */
    /* @3776344 call */
    GM_SITE(vm, 12, 3776344);
    /* @3776352 cast */
    /* @3776356 not */
    /* @3776360 bf */
    v62 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v62)) goto L_3776408;
    /* @3776364 constant */
    /* @3776368 cast */
    /* @3776372 load */
    /* @3776380 constant */
    /* @3776384 sub */
    /* @3776388 load */
    /* @3776396 call */
    GM_SITE(vm, 12, 3776396);
    /* @3776404 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3776408: ;
    /* @3776408 load */
    /* @3776416 constant */
    /* @3776420 cmp */
    /* @3776424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy") != VAL(-4)))) goto L_3777064;
    /* @3776428 load */
    /* @3776436 constant */
    /* @3776440 cmp */
    /* @3776444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3777064;
    /* @3776448 load */
    /* @3776456 constant */
    /* @3776460 cmp */
    /* @3776464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3776488;
    /* @3776468 load */
    /* @3776476 constant */
    /* @3776480 cmp */
    /* @3776484 b */
    p3776492_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3776492;
    L_3776488: ;
    /* @3776488 constant */
    p3776492_0 = VAL(0);
    L_3776492: ;
    /* @3776492 bf */
    if (!TRUTH(p3776492_0)) goto L_3777064;
    /* @3776496 load */
    /* @3776504 constant */
    /* @3776508 cmp */
    /* @3776512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3776884;
    /* @3776516 constant */
    /* @3776520 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3776528 load */
    /* @3776536 constant */
    /* @3776540 sub */
    /* @3776544 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3776552 load */
    /* @3776560 cast */
    /* @3776564 load */
    /* @3776572 load */
    /* @3776580 cmp */
    /* @3776584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy")), "x") > GM_READ(vm, -1, "x")))) goto L_3776616;
    /* @3776588 constant */
    /* @3776592 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3776600 constant */
    /* @3776604 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3776612 b */
    goto L_3776676;
    L_3776616: ;
    /* @3776616 load */
    /* @3776624 cast */
    /* @3776628 load */
    /* @3776636 load */
    /* @3776644 cmp */
    /* @3776648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy")), "x") < GM_READ(vm, -1, "x")))) goto L_3776676;
    /* @3776652 constant */
    /* @3776656 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3776664 constant */
    /* @3776668 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3776676: ;
    /* @3776676 constant */
    /* @3776680 constant */
    /* @3776684 constant */
    /* @3776688 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3776696 constant */
    /* @3776700 constant */
    /* @3776704 constant */
    /* @3776708 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3776716 constant */
    /* @3776720 constant */
    /* @3776724 constant */
    /* @3776728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3776736 load */
    /* @3776744 constant */
    /* @3776748 cmp */
    /* @3776752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3776760;
    /* @3776756 b */
    goto L_3776816;
    L_3776760: ;
    /* @3776760 load */
    /* @3776768 constant */
    /* @3776772 cmp */
    /* @3776776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3776816;
    /* @3776780 constant */
    /* @3776784 cast */
    /* @3776788 constant */
    /* @3776792 cast */
    /* @3776796 constant */
    /* @3776800 cast */
    /* @3776804 call */
    GM_SITE(vm, 12, 3776804);
    /* @3776812 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3776816: ;
    /* @3776816 constant */
    /* @3776820 cast */
    /* @3776824 load */
    /* @3776832 load */
    /* @3776840 load */
    /* @3776848 add */
    /* @3776852 call */
    GM_SITE(vm, 12, 3776852);
    v63 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3776860 cast */
    /* @3776864 bf */
    v64 = BOOL(GM_CALL(vm, "place_meeting", 3, v63, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v64)) goto L_3776880;
    /* @3776868 constant */
    /* @3776872 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3776880: ;
    /* @3776880 b */
    goto L_3777064;
    L_3776884: ;
    /* @3776884 load */
    /* @3776892 constant */
    /* @3776896 cmp */
    /* @3776900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3777064;
    /* @3776904 load */
    /* @3776912 constant */
    /* @3776916 cmp */
    /* @3776920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy") != VAL(-4)))) goto L_3777064;
    /* @3776924 load */
    /* @3776932 constant */
    /* @3776936 cmp */
    /* @3776940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3777064;
    /* @3776944 load */
    /* @3776952 constant */
    /* @3776956 cmp */
    /* @3776960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3776984;
    /* @3776964 load */
    /* @3776972 constant */
    /* @3776976 cmp */
    /* @3776980 b */
    p3776988_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3776988;
    L_3776984: ;
    /* @3776984 constant */
    p3776988_0 = VAL(0);
    L_3776988: ;
    /* @3776988 bf */
    if (!TRUTH(p3776988_0)) goto L_3777064;
    /* @3776992 constant */
    /* @3776996 cast */
    /* @3777000 call */
    GM_SITE(vm, 12, 3777000);
    /* @3777008 cast */
    /* @3777012 not */
    /* @3777016 bf */
    v65 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v65)) goto L_3777064;
    /* @3777020 constant */
    /* @3777024 cast */
    /* @3777028 load */
    /* @3777036 constant */
    /* @3777040 sub */
    /* @3777044 load */
    /* @3777052 call */
    GM_SITE(vm, 12, 3777052);
    /* @3777060 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3777064: ;
    /* @3777064 constant */
    /* @3777068 cast */
    /* @3777072 call */
    GM_SITE(vm, 12, 3777072);
    /* @3777080 cast */
    /* @3777084 bf */
    v66 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(22)));
    if (!TRUTH(v66)) goto L_3778400;
    /* @3777088 load */
    /* @3777096 constant */
    /* @3777100 cmp */
    /* @3777104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy2") != VAL(-4)))) goto L_3777744;
    /* @3777108 load */
    /* @3777116 constant */
    /* @3777120 cmp */
    /* @3777124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3777744;
    /* @3777128 load */
    /* @3777136 constant */
    /* @3777140 cmp */
    /* @3777144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3777168;
    /* @3777148 load */
    /* @3777156 constant */
    /* @3777160 cmp */
    /* @3777164 b */
    p3777172_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3777172;
    L_3777168: ;
    /* @3777168 constant */
    p3777172_0 = VAL(0);
    L_3777172: ;
    /* @3777172 bf */
    if (!TRUTH(p3777172_0)) goto L_3777744;
    /* @3777176 load */
    /* @3777184 constant */
    /* @3777188 cmp */
    /* @3777192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3777564;
    /* @3777196 constant */
    /* @3777200 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3777208 load */
    /* @3777216 constant */
    /* @3777220 sub */
    /* @3777224 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3777232 load */
    /* @3777240 cast */
    /* @3777244 load */
    /* @3777252 load */
    /* @3777260 cmp */
    /* @3777264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy2")), "x") > GM_READ(vm, -1, "x")))) goto L_3777296;
    /* @3777268 constant */
    /* @3777272 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3777280 constant */
    /* @3777284 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3777292 b */
    goto L_3777356;
    L_3777296: ;
    /* @3777296 load */
    /* @3777304 cast */
    /* @3777308 load */
    /* @3777316 load */
    /* @3777324 cmp */
    /* @3777328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy2")), "x") < GM_READ(vm, -1, "x")))) goto L_3777356;
    /* @3777332 constant */
    /* @3777336 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3777344 constant */
    /* @3777348 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3777356: ;
    /* @3777356 constant */
    /* @3777360 constant */
    /* @3777364 constant */
    /* @3777368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3777376 constant */
    /* @3777380 constant */
    /* @3777384 constant */
    /* @3777388 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3777396 constant */
    /* @3777400 constant */
    /* @3777404 constant */
    /* @3777408 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3777416 load */
    /* @3777424 constant */
    /* @3777428 cmp */
    /* @3777432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3777440;
    /* @3777436 b */
    goto L_3777496;
    L_3777440: ;
    /* @3777440 load */
    /* @3777448 constant */
    /* @3777452 cmp */
    /* @3777456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3777496;
    /* @3777460 constant */
    /* @3777464 cast */
    /* @3777468 constant */
    /* @3777472 cast */
    /* @3777476 constant */
    /* @3777480 cast */
    /* @3777484 call */
    GM_SITE(vm, 12, 3777484);
    /* @3777492 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3777496: ;
    /* @3777496 constant */
    /* @3777500 cast */
    /* @3777504 load */
    /* @3777512 load */
    /* @3777520 load */
    /* @3777528 add */
    /* @3777532 call */
    GM_SITE(vm, 12, 3777532);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3777540 cast */
    /* @3777544 bf */
    v68 = BOOL(GM_CALL(vm, "place_meeting", 3, v67, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v68)) goto L_3777560;
    /* @3777548 constant */
    /* @3777552 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3777560: ;
    /* @3777560 b */
    goto L_3777744;
    L_3777564: ;
    /* @3777564 load */
    /* @3777572 constant */
    /* @3777576 cmp */
    /* @3777580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3777744;
    /* @3777584 load */
    /* @3777592 constant */
    /* @3777596 cmp */
    /* @3777600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy2") != VAL(-4)))) goto L_3777744;
    /* @3777604 load */
    /* @3777612 constant */
    /* @3777616 cmp */
    /* @3777620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3777744;
    /* @3777624 load */
    /* @3777632 constant */
    /* @3777636 cmp */
    /* @3777640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3777664;
    /* @3777644 load */
    /* @3777652 constant */
    /* @3777656 cmp */
    /* @3777660 b */
    p3777668_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3777668;
    L_3777664: ;
    /* @3777664 constant */
    p3777668_0 = VAL(0);
    L_3777668: ;
    /* @3777668 bf */
    if (!TRUTH(p3777668_0)) goto L_3777744;
    /* @3777672 constant */
    /* @3777676 cast */
    /* @3777680 call */
    GM_SITE(vm, 12, 3777680);
    /* @3777688 cast */
    /* @3777692 not */
    /* @3777696 bf */
    v69 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v69)) goto L_3777744;
    /* @3777700 constant */
    /* @3777704 cast */
    /* @3777708 load */
    /* @3777716 constant */
    /* @3777720 sub */
    /* @3777724 load */
    /* @3777732 call */
    GM_SITE(vm, 12, 3777732);
    /* @3777740 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3777744: ;
    /* @3777744 load */
    /* @3777752 constant */
    /* @3777756 cmp */
    /* @3777760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy2") != VAL(-4)))) goto L_3778400;
    /* @3777764 load */
    /* @3777772 constant */
    /* @3777776 cmp */
    /* @3777780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3778400;
    /* @3777784 load */
    /* @3777792 constant */
    /* @3777796 cmp */
    /* @3777800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3777824;
    /* @3777804 load */
    /* @3777812 constant */
    /* @3777816 cmp */
    /* @3777820 b */
    p3777828_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3777828;
    L_3777824: ;
    /* @3777824 constant */
    p3777828_0 = VAL(0);
    L_3777828: ;
    /* @3777828 bf */
    if (!TRUTH(p3777828_0)) goto L_3778400;
    /* @3777832 load */
    /* @3777840 constant */
    /* @3777844 cmp */
    /* @3777848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3778220;
    /* @3777852 constant */
    /* @3777856 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3777864 load */
    /* @3777872 constant */
    /* @3777876 sub */
    /* @3777880 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3777888 load */
    /* @3777896 cast */
    /* @3777900 load */
    /* @3777908 load */
    /* @3777916 cmp */
    /* @3777920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy2")), "x") > GM_READ(vm, -1, "x")))) goto L_3777952;
    /* @3777924 constant */
    /* @3777928 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3777936 constant */
    /* @3777940 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3777948 b */
    goto L_3778012;
    L_3777952: ;
    /* @3777952 load */
    /* @3777960 cast */
    /* @3777964 load */
    /* @3777972 load */
    /* @3777980 cmp */
    /* @3777984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemy2")), "x") < GM_READ(vm, -1, "x")))) goto L_3778012;
    /* @3777988 constant */
    /* @3777992 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3778000 constant */
    /* @3778004 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3778012: ;
    /* @3778012 constant */
    /* @3778016 constant */
    /* @3778020 constant */
    /* @3778024 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3778032 constant */
    /* @3778036 constant */
    /* @3778040 constant */
    /* @3778044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3778052 constant */
    /* @3778056 constant */
    /* @3778060 constant */
    /* @3778064 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3778072 load */
    /* @3778080 constant */
    /* @3778084 cmp */
    /* @3778088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3778096;
    /* @3778092 b */
    goto L_3778152;
    L_3778096: ;
    /* @3778096 load */
    /* @3778104 constant */
    /* @3778108 cmp */
    /* @3778112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3778152;
    /* @3778116 constant */
    /* @3778120 cast */
    /* @3778124 constant */
    /* @3778128 cast */
    /* @3778132 constant */
    /* @3778136 cast */
    /* @3778140 call */
    GM_SITE(vm, 12, 3778140);
    /* @3778148 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3778152: ;
    /* @3778152 constant */
    /* @3778156 cast */
    /* @3778160 load */
    /* @3778168 load */
    /* @3778176 load */
    /* @3778184 add */
    /* @3778188 call */
    GM_SITE(vm, 12, 3778188);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3778196 cast */
    /* @3778200 bf */
    v71 = BOOL(GM_CALL(vm, "place_meeting", 3, v70, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v71)) goto L_3778216;
    /* @3778204 constant */
    /* @3778208 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3778216: ;
    /* @3778216 b */
    goto L_3778400;
    L_3778220: ;
    /* @3778220 load */
    /* @3778228 constant */
    /* @3778232 cmp */
    /* @3778236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3778400;
    /* @3778240 load */
    /* @3778248 constant */
    /* @3778252 cmp */
    /* @3778256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemy2") != VAL(-4)))) goto L_3778400;
    /* @3778260 load */
    /* @3778268 constant */
    /* @3778272 cmp */
    /* @3778276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3778400;
    /* @3778280 load */
    /* @3778288 constant */
    /* @3778292 cmp */
    /* @3778296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3778320;
    /* @3778300 load */
    /* @3778308 constant */
    /* @3778312 cmp */
    /* @3778316 b */
    p3778324_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3778324;
    L_3778320: ;
    /* @3778320 constant */
    p3778324_0 = VAL(0);
    L_3778324: ;
    /* @3778324 bf */
    if (!TRUTH(p3778324_0)) goto L_3778400;
    /* @3778328 constant */
    /* @3778332 cast */
    /* @3778336 call */
    GM_SITE(vm, 12, 3778336);
    /* @3778344 cast */
    /* @3778348 not */
    /* @3778352 bf */
    v72 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v72)) goto L_3778400;
    /* @3778356 constant */
    /* @3778360 cast */
    /* @3778364 load */
    /* @3778372 constant */
    /* @3778376 sub */
    /* @3778380 load */
    /* @3778388 call */
    GM_SITE(vm, 12, 3778388);
    /* @3778396 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3778400: ;
    /* @3778400 constant */
    /* @3778404 cast */
    /* @3778408 call */
    GM_SITE(vm, 12, 3778408);
    /* @3778416 cast */
    /* @3778420 bf */
    v73 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(25)));
    if (!TRUTH(v73)) goto L_3779736;
    /* @3778424 load */
    /* @3778432 constant */
    /* @3778436 cmp */
    /* @3778440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemytrex") != VAL(-4)))) goto L_3779080;
    /* @3778444 load */
    /* @3778452 constant */
    /* @3778456 cmp */
    /* @3778460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3779080;
    /* @3778464 load */
    /* @3778472 constant */
    /* @3778476 cmp */
    /* @3778480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3778504;
    /* @3778484 load */
    /* @3778492 constant */
    /* @3778496 cmp */
    /* @3778500 b */
    p3778508_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3778508;
    L_3778504: ;
    /* @3778504 constant */
    p3778508_0 = VAL(0);
    L_3778508: ;
    /* @3778508 bf */
    if (!TRUTH(p3778508_0)) goto L_3779080;
    /* @3778512 load */
    /* @3778520 constant */
    /* @3778524 cmp */
    /* @3778528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3778900;
    /* @3778532 constant */
    /* @3778536 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3778544 load */
    /* @3778552 constant */
    /* @3778556 sub */
    /* @3778560 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3778568 load */
    /* @3778576 cast */
    /* @3778580 load */
    /* @3778588 load */
    /* @3778596 cmp */
    /* @3778600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemytrex")), "x") > GM_READ(vm, -1, "x")))) goto L_3778632;
    /* @3778604 constant */
    /* @3778608 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3778616 constant */
    /* @3778620 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3778628 b */
    goto L_3778692;
    L_3778632: ;
    /* @3778632 load */
    /* @3778640 cast */
    /* @3778644 load */
    /* @3778652 load */
    /* @3778660 cmp */
    /* @3778664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemytrex")), "x") < GM_READ(vm, -1, "x")))) goto L_3778692;
    /* @3778668 constant */
    /* @3778672 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3778680 constant */
    /* @3778684 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3778692: ;
    /* @3778692 constant */
    /* @3778696 constant */
    /* @3778700 constant */
    /* @3778704 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3778712 constant */
    /* @3778716 constant */
    /* @3778720 constant */
    /* @3778724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3778732 constant */
    /* @3778736 constant */
    /* @3778740 constant */
    /* @3778744 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3778752 load */
    /* @3778760 constant */
    /* @3778764 cmp */
    /* @3778768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3778776;
    /* @3778772 b */
    goto L_3778832;
    L_3778776: ;
    /* @3778776 load */
    /* @3778784 constant */
    /* @3778788 cmp */
    /* @3778792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3778832;
    /* @3778796 constant */
    /* @3778800 cast */
    /* @3778804 constant */
    /* @3778808 cast */
    /* @3778812 constant */
    /* @3778816 cast */
    /* @3778820 call */
    GM_SITE(vm, 12, 3778820);
    /* @3778828 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3778832: ;
    /* @3778832 constant */
    /* @3778836 cast */
    /* @3778840 load */
    /* @3778848 load */
    /* @3778856 load */
    /* @3778864 add */
    /* @3778868 call */
    GM_SITE(vm, 12, 3778868);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3778876 cast */
    /* @3778880 bf */
    v75 = BOOL(GM_CALL(vm, "place_meeting", 3, v74, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v75)) goto L_3778896;
    /* @3778884 constant */
    /* @3778888 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3778896: ;
    /* @3778896 b */
    goto L_3779080;
    L_3778900: ;
    /* @3778900 load */
    /* @3778908 constant */
    /* @3778912 cmp */
    /* @3778916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3779080;
    /* @3778920 load */
    /* @3778928 constant */
    /* @3778932 cmp */
    /* @3778936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemytrex") != VAL(-4)))) goto L_3779080;
    /* @3778940 load */
    /* @3778948 constant */
    /* @3778952 cmp */
    /* @3778956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3779080;
    /* @3778960 load */
    /* @3778968 constant */
    /* @3778972 cmp */
    /* @3778976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3779000;
    /* @3778980 load */
    /* @3778988 constant */
    /* @3778992 cmp */
    /* @3778996 b */
    p3779004_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3779004;
    L_3779000: ;
    /* @3779000 constant */
    p3779004_0 = VAL(0);
    L_3779004: ;
    /* @3779004 bf */
    if (!TRUTH(p3779004_0)) goto L_3779080;
    /* @3779008 constant */
    /* @3779012 cast */
    /* @3779016 call */
    GM_SITE(vm, 12, 3779016);
    /* @3779024 cast */
    /* @3779028 not */
    /* @3779032 bf */
    v76 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v76)) goto L_3779080;
    /* @3779036 constant */
    /* @3779040 cast */
    /* @3779044 load */
    /* @3779052 constant */
    /* @3779056 sub */
    /* @3779060 load */
    /* @3779068 call */
    GM_SITE(vm, 12, 3779068);
    /* @3779076 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3779080: ;
    /* @3779080 load */
    /* @3779088 constant */
    /* @3779092 cmp */
    /* @3779096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemytrex") != VAL(-4)))) goto L_3779736;
    /* @3779100 load */
    /* @3779108 constant */
    /* @3779112 cmp */
    /* @3779116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3779736;
    /* @3779120 load */
    /* @3779128 constant */
    /* @3779132 cmp */
    /* @3779136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3779160;
    /* @3779140 load */
    /* @3779148 constant */
    /* @3779152 cmp */
    /* @3779156 b */
    p3779164_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3779164;
    L_3779160: ;
    /* @3779160 constant */
    p3779164_0 = VAL(0);
    L_3779164: ;
    /* @3779164 bf */
    if (!TRUTH(p3779164_0)) goto L_3779736;
    /* @3779168 load */
    /* @3779176 constant */
    /* @3779180 cmp */
    /* @3779184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3779556;
    /* @3779188 constant */
    /* @3779192 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3779200 load */
    /* @3779208 constant */
    /* @3779212 sub */
    /* @3779216 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3779224 load */
    /* @3779232 cast */
    /* @3779236 load */
    /* @3779244 load */
    /* @3779252 cmp */
    /* @3779256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemytrex")), "x") > GM_READ(vm, -1, "x")))) goto L_3779288;
    /* @3779260 constant */
    /* @3779264 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3779272 constant */
    /* @3779276 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3779284 b */
    goto L_3779348;
    L_3779288: ;
    /* @3779288 load */
    /* @3779296 cast */
    /* @3779300 load */
    /* @3779308 load */
    /* @3779316 cmp */
    /* @3779320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemytrex")), "x") < GM_READ(vm, -1, "x")))) goto L_3779348;
    /* @3779324 constant */
    /* @3779328 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3779336 constant */
    /* @3779340 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3779348: ;
    /* @3779348 constant */
    /* @3779352 constant */
    /* @3779356 constant */
    /* @3779360 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3779368 constant */
    /* @3779372 constant */
    /* @3779376 constant */
    /* @3779380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3779388 constant */
    /* @3779392 constant */
    /* @3779396 constant */
    /* @3779400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3779408 load */
    /* @3779416 constant */
    /* @3779420 cmp */
    /* @3779424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3779432;
    /* @3779428 b */
    goto L_3779488;
    L_3779432: ;
    /* @3779432 load */
    /* @3779440 constant */
    /* @3779444 cmp */
    /* @3779448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3779488;
    /* @3779452 constant */
    /* @3779456 cast */
    /* @3779460 constant */
    /* @3779464 cast */
    /* @3779468 constant */
    /* @3779472 cast */
    /* @3779476 call */
    GM_SITE(vm, 12, 3779476);
    /* @3779484 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3779488: ;
    /* @3779488 constant */
    /* @3779492 cast */
    /* @3779496 load */
    /* @3779504 load */
    /* @3779512 load */
    /* @3779520 add */
    /* @3779524 call */
    GM_SITE(vm, 12, 3779524);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3779532 cast */
    /* @3779536 bf */
    v78 = BOOL(GM_CALL(vm, "place_meeting", 3, v77, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v78)) goto L_3779552;
    /* @3779540 constant */
    /* @3779544 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3779552: ;
    /* @3779552 b */
    goto L_3779736;
    L_3779556: ;
    /* @3779556 load */
    /* @3779564 constant */
    /* @3779568 cmp */
    /* @3779572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3779736;
    /* @3779576 load */
    /* @3779584 constant */
    /* @3779588 cmp */
    /* @3779592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemytrex") != VAL(-4)))) goto L_3779736;
    /* @3779596 load */
    /* @3779604 constant */
    /* @3779608 cmp */
    /* @3779612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3779736;
    /* @3779616 load */
    /* @3779624 constant */
    /* @3779628 cmp */
    /* @3779632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3779656;
    /* @3779636 load */
    /* @3779644 constant */
    /* @3779648 cmp */
    /* @3779652 b */
    p3779660_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3779660;
    L_3779656: ;
    /* @3779656 constant */
    p3779660_0 = VAL(0);
    L_3779660: ;
    /* @3779660 bf */
    if (!TRUTH(p3779660_0)) goto L_3779736;
    /* @3779664 constant */
    /* @3779668 cast */
    /* @3779672 call */
    GM_SITE(vm, 12, 3779672);
    /* @3779680 cast */
    /* @3779684 not */
    /* @3779688 bf */
    v79 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v79)) goto L_3779736;
    /* @3779692 constant */
    /* @3779696 cast */
    /* @3779700 load */
    /* @3779708 constant */
    /* @3779712 sub */
    /* @3779716 load */
    /* @3779724 call */
    GM_SITE(vm, 12, 3779724);
    /* @3779732 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3779736: ;
    /* @3779736 constant */
    /* @3779740 cast */
    /* @3779744 call */
    GM_SITE(vm, 12, 3779744);
    /* @3779752 cast */
    /* @3779756 bf */
    v80 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(31)));
    if (!TRUTH(v80)) goto L_3781072;
    /* @3779760 load */
    /* @3779768 constant */
    /* @3779772 cmp */
    /* @3779776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemybat") != VAL(-4)))) goto L_3780416;
    /* @3779780 load */
    /* @3779788 constant */
    /* @3779792 cmp */
    /* @3779796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3780416;
    /* @3779800 load */
    /* @3779808 constant */
    /* @3779812 cmp */
    /* @3779816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3779840;
    /* @3779820 load */
    /* @3779828 constant */
    /* @3779832 cmp */
    /* @3779836 b */
    p3779844_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3779844;
    L_3779840: ;
    /* @3779840 constant */
    p3779844_0 = VAL(0);
    L_3779844: ;
    /* @3779844 bf */
    if (!TRUTH(p3779844_0)) goto L_3780416;
    /* @3779848 load */
    /* @3779856 constant */
    /* @3779860 cmp */
    /* @3779864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3780236;
    /* @3779868 constant */
    /* @3779872 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3779880 load */
    /* @3779888 constant */
    /* @3779892 sub */
    /* @3779896 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3779904 load */
    /* @3779912 cast */
    /* @3779916 load */
    /* @3779924 load */
    /* @3779932 cmp */
    /* @3779936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemybat")), "x") > GM_READ(vm, -1, "x")))) goto L_3779968;
    /* @3779940 constant */
    /* @3779944 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3779952 constant */
    /* @3779956 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3779964 b */
    goto L_3780028;
    L_3779968: ;
    /* @3779968 load */
    /* @3779976 cast */
    /* @3779980 load */
    /* @3779988 load */
    /* @3779996 cmp */
    /* @3780000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemybat")), "x") < GM_READ(vm, -1, "x")))) goto L_3780028;
    /* @3780004 constant */
    /* @3780008 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3780016 constant */
    /* @3780020 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3780028: ;
    /* @3780028 constant */
    /* @3780032 constant */
    /* @3780036 constant */
    /* @3780040 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3780048 constant */
    /* @3780052 constant */
    /* @3780056 constant */
    /* @3780060 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3780068 constant */
    /* @3780072 constant */
    /* @3780076 constant */
    /* @3780080 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3780088 load */
    /* @3780096 constant */
    /* @3780100 cmp */
    /* @3780104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3780112;
    /* @3780108 b */
    goto L_3780168;
    L_3780112: ;
    /* @3780112 load */
    /* @3780120 constant */
    /* @3780124 cmp */
    /* @3780128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3780168;
    /* @3780132 constant */
    /* @3780136 cast */
    /* @3780140 constant */
    /* @3780144 cast */
    /* @3780148 constant */
    /* @3780152 cast */
    /* @3780156 call */
    GM_SITE(vm, 12, 3780156);
    /* @3780164 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3780168: ;
    /* @3780168 constant */
    /* @3780172 cast */
    /* @3780176 load */
    /* @3780184 load */
    /* @3780192 load */
    /* @3780200 add */
    /* @3780204 call */
    GM_SITE(vm, 12, 3780204);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3780212 cast */
    /* @3780216 bf */
    v82 = BOOL(GM_CALL(vm, "place_meeting", 3, v81, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v82)) goto L_3780232;
    /* @3780220 constant */
    /* @3780224 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3780232: ;
    /* @3780232 b */
    goto L_3780416;
    L_3780236: ;
    /* @3780236 load */
    /* @3780244 constant */
    /* @3780248 cmp */
    /* @3780252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3780416;
    /* @3780256 load */
    /* @3780264 constant */
    /* @3780268 cmp */
    /* @3780272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemybat") != VAL(-4)))) goto L_3780416;
    /* @3780276 load */
    /* @3780284 constant */
    /* @3780288 cmp */
    /* @3780292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3780416;
    /* @3780296 load */
    /* @3780304 constant */
    /* @3780308 cmp */
    /* @3780312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3780336;
    /* @3780316 load */
    /* @3780324 constant */
    /* @3780328 cmp */
    /* @3780332 b */
    p3780340_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3780340;
    L_3780336: ;
    /* @3780336 constant */
    p3780340_0 = VAL(0);
    L_3780340: ;
    /* @3780340 bf */
    if (!TRUTH(p3780340_0)) goto L_3780416;
    /* @3780344 constant */
    /* @3780348 cast */
    /* @3780352 call */
    GM_SITE(vm, 12, 3780352);
    /* @3780360 cast */
    /* @3780364 not */
    /* @3780368 bf */
    v83 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v83)) goto L_3780416;
    /* @3780372 constant */
    /* @3780376 cast */
    /* @3780380 load */
    /* @3780388 constant */
    /* @3780392 sub */
    /* @3780396 load */
    /* @3780404 call */
    GM_SITE(vm, 12, 3780404);
    /* @3780412 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3780416: ;
    /* @3780416 load */
    /* @3780424 constant */
    /* @3780428 cmp */
    /* @3780432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemybat") != VAL(-4)))) goto L_3781072;
    /* @3780436 load */
    /* @3780444 constant */
    /* @3780448 cmp */
    /* @3780452 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3781072;
    /* @3780456 load */
    /* @3780464 constant */
    /* @3780468 cmp */
    /* @3780472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3780496;
    /* @3780476 load */
    /* @3780484 constant */
    /* @3780488 cmp */
    /* @3780492 b */
    p3780500_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3780500;
    L_3780496: ;
    /* @3780496 constant */
    p3780500_0 = VAL(0);
    L_3780500: ;
    /* @3780500 bf */
    if (!TRUTH(p3780500_0)) goto L_3781072;
    /* @3780504 load */
    /* @3780512 constant */
    /* @3780516 cmp */
    /* @3780520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3780892;
    /* @3780524 constant */
    /* @3780528 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3780536 load */
    /* @3780544 constant */
    /* @3780548 sub */
    /* @3780552 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3780560 load */
    /* @3780568 cast */
    /* @3780572 load */
    /* @3780580 load */
    /* @3780588 cmp */
    /* @3780592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemybat")), "x") > GM_READ(vm, -1, "x")))) goto L_3780624;
    /* @3780596 constant */
    /* @3780600 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3780608 constant */
    /* @3780612 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3780620 b */
    goto L_3780684;
    L_3780624: ;
    /* @3780624 load */
    /* @3780632 cast */
    /* @3780636 load */
    /* @3780644 load */
    /* @3780652 cmp */
    /* @3780656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemybat")), "x") < GM_READ(vm, -1, "x")))) goto L_3780684;
    /* @3780660 constant */
    /* @3780664 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3780672 constant */
    /* @3780676 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3780684: ;
    /* @3780684 constant */
    /* @3780688 constant */
    /* @3780692 constant */
    /* @3780696 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3780704 constant */
    /* @3780708 constant */
    /* @3780712 constant */
    /* @3780716 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3780724 constant */
    /* @3780728 constant */
    /* @3780732 constant */
    /* @3780736 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3780744 load */
    /* @3780752 constant */
    /* @3780756 cmp */
    /* @3780760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3780768;
    /* @3780764 b */
    goto L_3780824;
    L_3780768: ;
    /* @3780768 load */
    /* @3780776 constant */
    /* @3780780 cmp */
    /* @3780784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3780824;
    /* @3780788 constant */
    /* @3780792 cast */
    /* @3780796 constant */
    /* @3780800 cast */
    /* @3780804 constant */
    /* @3780808 cast */
    /* @3780812 call */
    GM_SITE(vm, 12, 3780812);
    /* @3780820 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3780824: ;
    /* @3780824 constant */
    /* @3780828 cast */
    /* @3780832 load */
    /* @3780840 load */
    /* @3780848 load */
    /* @3780856 add */
    /* @3780860 call */
    GM_SITE(vm, 12, 3780860);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3780868 cast */
    /* @3780872 bf */
    v85 = BOOL(GM_CALL(vm, "place_meeting", 3, v84, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v85)) goto L_3780888;
    /* @3780876 constant */
    /* @3780880 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3780888: ;
    /* @3780888 b */
    goto L_3781072;
    L_3780892: ;
    /* @3780892 load */
    /* @3780900 constant */
    /* @3780904 cmp */
    /* @3780908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3781072;
    /* @3780912 load */
    /* @3780920 constant */
    /* @3780924 cmp */
    /* @3780928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemybat") != VAL(-4)))) goto L_3781072;
    /* @3780932 load */
    /* @3780940 constant */
    /* @3780944 cmp */
    /* @3780948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3781072;
    /* @3780952 load */
    /* @3780960 constant */
    /* @3780964 cmp */
    /* @3780968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3780992;
    /* @3780972 load */
    /* @3780980 constant */
    /* @3780984 cmp */
    /* @3780988 b */
    p3780996_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3780996;
    L_3780992: ;
    /* @3780992 constant */
    p3780996_0 = VAL(0);
    L_3780996: ;
    /* @3780996 bf */
    if (!TRUTH(p3780996_0)) goto L_3781072;
    /* @3781000 constant */
    /* @3781004 cast */
    /* @3781008 call */
    GM_SITE(vm, 12, 3781008);
    /* @3781016 cast */
    /* @3781020 not */
    /* @3781024 bf */
    v86 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v86)) goto L_3781072;
    /* @3781028 constant */
    /* @3781032 cast */
    /* @3781036 load */
    /* @3781044 constant */
    /* @3781048 sub */
    /* @3781052 load */
    /* @3781060 call */
    GM_SITE(vm, 12, 3781060);
    /* @3781068 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3781072: ;
    /* @3781072 constant */
    /* @3781076 cast */
    /* @3781080 call */
    GM_SITE(vm, 12, 3781080);
    /* @3781088 cast */
    /* @3781092 bf */
    v87 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(32)));
    if (!TRUTH(v87)) goto L_3782408;
    /* @3781096 load */
    /* @3781104 constant */
    /* @3781108 cmp */
    /* @3781112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyslime") != VAL(-4)))) goto L_3781752;
    /* @3781116 load */
    /* @3781124 constant */
    /* @3781128 cmp */
    /* @3781132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3781752;
    /* @3781136 load */
    /* @3781144 constant */
    /* @3781148 cmp */
    /* @3781152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3781176;
    /* @3781156 load */
    /* @3781164 constant */
    /* @3781168 cmp */
    /* @3781172 b */
    p3781180_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3781180;
    L_3781176: ;
    /* @3781176 constant */
    p3781180_0 = VAL(0);
    L_3781180: ;
    /* @3781180 bf */
    if (!TRUTH(p3781180_0)) goto L_3781752;
    /* @3781184 load */
    /* @3781192 constant */
    /* @3781196 cmp */
    /* @3781200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3781572;
    /* @3781204 constant */
    /* @3781208 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3781216 load */
    /* @3781224 constant */
    /* @3781228 sub */
    /* @3781232 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3781240 load */
    /* @3781248 cast */
    /* @3781252 load */
    /* @3781260 load */
    /* @3781268 cmp */
    /* @3781272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyslime")), "x") > GM_READ(vm, -1, "x")))) goto L_3781304;
    /* @3781276 constant */
    /* @3781280 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3781288 constant */
    /* @3781292 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3781300 b */
    goto L_3781364;
    L_3781304: ;
    /* @3781304 load */
    /* @3781312 cast */
    /* @3781316 load */
    /* @3781324 load */
    /* @3781332 cmp */
    /* @3781336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyslime")), "x") < GM_READ(vm, -1, "x")))) goto L_3781364;
    /* @3781340 constant */
    /* @3781344 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3781352 constant */
    /* @3781356 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3781364: ;
    /* @3781364 constant */
    /* @3781368 constant */
    /* @3781372 constant */
    /* @3781376 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3781384 constant */
    /* @3781388 constant */
    /* @3781392 constant */
    /* @3781396 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3781404 constant */
    /* @3781408 constant */
    /* @3781412 constant */
    /* @3781416 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3781424 load */
    /* @3781432 constant */
    /* @3781436 cmp */
    /* @3781440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3781448;
    /* @3781444 b */
    goto L_3781504;
    L_3781448: ;
    /* @3781448 load */
    /* @3781456 constant */
    /* @3781460 cmp */
    /* @3781464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3781504;
    /* @3781468 constant */
    /* @3781472 cast */
    /* @3781476 constant */
    /* @3781480 cast */
    /* @3781484 constant */
    /* @3781488 cast */
    /* @3781492 call */
    GM_SITE(vm, 12, 3781492);
    /* @3781500 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3781504: ;
    /* @3781504 constant */
    /* @3781508 cast */
    /* @3781512 load */
    /* @3781520 load */
    /* @3781528 load */
    /* @3781536 add */
    /* @3781540 call */
    GM_SITE(vm, 12, 3781540);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3781548 cast */
    /* @3781552 bf */
    v89 = BOOL(GM_CALL(vm, "place_meeting", 3, v88, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v89)) goto L_3781568;
    /* @3781556 constant */
    /* @3781560 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3781568: ;
    /* @3781568 b */
    goto L_3781752;
    L_3781572: ;
    /* @3781572 load */
    /* @3781580 constant */
    /* @3781584 cmp */
    /* @3781588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3781752;
    /* @3781592 load */
    /* @3781600 constant */
    /* @3781604 cmp */
    /* @3781608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyslime") != VAL(-4)))) goto L_3781752;
    /* @3781612 load */
    /* @3781620 constant */
    /* @3781624 cmp */
    /* @3781628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3781752;
    /* @3781632 load */
    /* @3781640 constant */
    /* @3781644 cmp */
    /* @3781648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3781672;
    /* @3781652 load */
    /* @3781660 constant */
    /* @3781664 cmp */
    /* @3781668 b */
    p3781676_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3781676;
    L_3781672: ;
    /* @3781672 constant */
    p3781676_0 = VAL(0);
    L_3781676: ;
    /* @3781676 bf */
    if (!TRUTH(p3781676_0)) goto L_3781752;
    /* @3781680 constant */
    /* @3781684 cast */
    /* @3781688 call */
    GM_SITE(vm, 12, 3781688);
    /* @3781696 cast */
    /* @3781700 not */
    /* @3781704 bf */
    v90 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v90)) goto L_3781752;
    /* @3781708 constant */
    /* @3781712 cast */
    /* @3781716 load */
    /* @3781724 constant */
    /* @3781728 sub */
    /* @3781732 load */
    /* @3781740 call */
    GM_SITE(vm, 12, 3781740);
    /* @3781748 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3781752: ;
    /* @3781752 load */
    /* @3781760 constant */
    /* @3781764 cmp */
    /* @3781768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyslime") != VAL(-4)))) goto L_3782408;
    /* @3781772 load */
    /* @3781780 constant */
    /* @3781784 cmp */
    /* @3781788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3782408;
    /* @3781792 load */
    /* @3781800 constant */
    /* @3781804 cmp */
    /* @3781808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3781832;
    /* @3781812 load */
    /* @3781820 constant */
    /* @3781824 cmp */
    /* @3781828 b */
    p3781836_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3781836;
    L_3781832: ;
    /* @3781832 constant */
    p3781836_0 = VAL(0);
    L_3781836: ;
    /* @3781836 bf */
    if (!TRUTH(p3781836_0)) goto L_3782408;
    /* @3781840 load */
    /* @3781848 constant */
    /* @3781852 cmp */
    /* @3781856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3782228;
    /* @3781860 constant */
    /* @3781864 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3781872 load */
    /* @3781880 constant */
    /* @3781884 sub */
    /* @3781888 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3781896 load */
    /* @3781904 cast */
    /* @3781908 load */
    /* @3781916 load */
    /* @3781924 cmp */
    /* @3781928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyslime")), "x") > GM_READ(vm, -1, "x")))) goto L_3781960;
    /* @3781932 constant */
    /* @3781936 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3781944 constant */
    /* @3781948 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3781956 b */
    goto L_3782020;
    L_3781960: ;
    /* @3781960 load */
    /* @3781968 cast */
    /* @3781972 load */
    /* @3781980 load */
    /* @3781988 cmp */
    /* @3781992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyslime")), "x") < GM_READ(vm, -1, "x")))) goto L_3782020;
    /* @3781996 constant */
    /* @3782000 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3782008 constant */
    /* @3782012 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3782020: ;
    /* @3782020 constant */
    /* @3782024 constant */
    /* @3782028 constant */
    /* @3782032 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3782040 constant */
    /* @3782044 constant */
    /* @3782048 constant */
    /* @3782052 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3782060 constant */
    /* @3782064 constant */
    /* @3782068 constant */
    /* @3782072 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3782080 load */
    /* @3782088 constant */
    /* @3782092 cmp */
    /* @3782096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3782104;
    /* @3782100 b */
    goto L_3782160;
    L_3782104: ;
    /* @3782104 load */
    /* @3782112 constant */
    /* @3782116 cmp */
    /* @3782120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3782160;
    /* @3782124 constant */
    /* @3782128 cast */
    /* @3782132 constant */
    /* @3782136 cast */
    /* @3782140 constant */
    /* @3782144 cast */
    /* @3782148 call */
    GM_SITE(vm, 12, 3782148);
    /* @3782156 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3782160: ;
    /* @3782160 constant */
    /* @3782164 cast */
    /* @3782168 load */
    /* @3782176 load */
    /* @3782184 load */
    /* @3782192 add */
    /* @3782196 call */
    GM_SITE(vm, 12, 3782196);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3782204 cast */
    /* @3782208 bf */
    v92 = BOOL(GM_CALL(vm, "place_meeting", 3, v91, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v92)) goto L_3782224;
    /* @3782212 constant */
    /* @3782216 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3782224: ;
    /* @3782224 b */
    goto L_3782408;
    L_3782228: ;
    /* @3782228 load */
    /* @3782236 constant */
    /* @3782240 cmp */
    /* @3782244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3782408;
    /* @3782248 load */
    /* @3782256 constant */
    /* @3782260 cmp */
    /* @3782264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyslime") != VAL(-4)))) goto L_3782408;
    /* @3782268 load */
    /* @3782276 constant */
    /* @3782280 cmp */
    /* @3782284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3782408;
    /* @3782288 load */
    /* @3782296 constant */
    /* @3782300 cmp */
    /* @3782304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3782328;
    /* @3782308 load */
    /* @3782316 constant */
    /* @3782320 cmp */
    /* @3782324 b */
    p3782332_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3782332;
    L_3782328: ;
    /* @3782328 constant */
    p3782332_0 = VAL(0);
    L_3782332: ;
    /* @3782332 bf */
    if (!TRUTH(p3782332_0)) goto L_3782408;
    /* @3782336 constant */
    /* @3782340 cast */
    /* @3782344 call */
    GM_SITE(vm, 12, 3782344);
    /* @3782352 cast */
    /* @3782356 not */
    /* @3782360 bf */
    v93 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v93)) goto L_3782408;
    /* @3782364 constant */
    /* @3782368 cast */
    /* @3782372 load */
    /* @3782380 constant */
    /* @3782384 sub */
    /* @3782388 load */
    /* @3782396 call */
    GM_SITE(vm, 12, 3782396);
    /* @3782404 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3782408: ;
    /* @3782408 constant */
    /* @3782412 cast */
    /* @3782416 call */
    GM_SITE(vm, 12, 3782416);
    /* @3782424 cast */
    /* @3782428 bf */
    v94 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(24)));
    if (!TRUTH(v94)) goto L_3783744;
    /* @3782432 load */
    /* @3782440 constant */
    /* @3782444 cmp */
    /* @3782448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyghost") != VAL(-4)))) goto L_3783088;
    /* @3782452 load */
    /* @3782460 constant */
    /* @3782464 cmp */
    /* @3782468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3783088;
    /* @3782472 load */
    /* @3782480 constant */
    /* @3782484 cmp */
    /* @3782488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3782512;
    /* @3782492 load */
    /* @3782500 constant */
    /* @3782504 cmp */
    /* @3782508 b */
    p3782516_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3782516;
    L_3782512: ;
    /* @3782512 constant */
    p3782516_0 = VAL(0);
    L_3782516: ;
    /* @3782516 bf */
    if (!TRUTH(p3782516_0)) goto L_3783088;
    /* @3782520 load */
    /* @3782528 constant */
    /* @3782532 cmp */
    /* @3782536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3782908;
    /* @3782540 constant */
    /* @3782544 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3782552 load */
    /* @3782560 constant */
    /* @3782564 sub */
    /* @3782568 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3782576 load */
    /* @3782584 cast */
    /* @3782588 load */
    /* @3782596 load */
    /* @3782604 cmp */
    /* @3782608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyghost")), "x") > GM_READ(vm, -1, "x")))) goto L_3782640;
    /* @3782612 constant */
    /* @3782616 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3782624 constant */
    /* @3782628 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3782636 b */
    goto L_3782700;
    L_3782640: ;
    /* @3782640 load */
    /* @3782648 cast */
    /* @3782652 load */
    /* @3782660 load */
    /* @3782668 cmp */
    /* @3782672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyghost")), "x") < GM_READ(vm, -1, "x")))) goto L_3782700;
    /* @3782676 constant */
    /* @3782680 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3782688 constant */
    /* @3782692 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3782700: ;
    /* @3782700 constant */
    /* @3782704 constant */
    /* @3782708 constant */
    /* @3782712 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3782720 constant */
    /* @3782724 constant */
    /* @3782728 constant */
    /* @3782732 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3782740 constant */
    /* @3782744 constant */
    /* @3782748 constant */
    /* @3782752 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3782760 load */
    /* @3782768 constant */
    /* @3782772 cmp */
    /* @3782776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3782784;
    /* @3782780 b */
    goto L_3782840;
    L_3782784: ;
    /* @3782784 load */
    /* @3782792 constant */
    /* @3782796 cmp */
    /* @3782800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3782840;
    /* @3782804 constant */
    /* @3782808 cast */
    /* @3782812 constant */
    /* @3782816 cast */
    /* @3782820 constant */
    /* @3782824 cast */
    /* @3782828 call */
    GM_SITE(vm, 12, 3782828);
    /* @3782836 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3782840: ;
    /* @3782840 constant */
    /* @3782844 cast */
    /* @3782848 load */
    /* @3782856 load */
    /* @3782864 load */
    /* @3782872 add */
    /* @3782876 call */
    GM_SITE(vm, 12, 3782876);
    v95 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3782884 cast */
    /* @3782888 bf */
    v96 = BOOL(GM_CALL(vm, "place_meeting", 3, v95, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v96)) goto L_3782904;
    /* @3782892 constant */
    /* @3782896 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3782904: ;
    /* @3782904 b */
    goto L_3783088;
    L_3782908: ;
    /* @3782908 load */
    /* @3782916 constant */
    /* @3782920 cmp */
    /* @3782924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3783088;
    /* @3782928 load */
    /* @3782936 constant */
    /* @3782940 cmp */
    /* @3782944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyghost") != VAL(-4)))) goto L_3783088;
    /* @3782948 load */
    /* @3782956 constant */
    /* @3782960 cmp */
    /* @3782964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3783088;
    /* @3782968 load */
    /* @3782976 constant */
    /* @3782980 cmp */
    /* @3782984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3783008;
    /* @3782988 load */
    /* @3782996 constant */
    /* @3783000 cmp */
    /* @3783004 b */
    p3783012_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3783012;
    L_3783008: ;
    /* @3783008 constant */
    p3783012_0 = VAL(0);
    L_3783012: ;
    /* @3783012 bf */
    if (!TRUTH(p3783012_0)) goto L_3783088;
    /* @3783016 constant */
    /* @3783020 cast */
    /* @3783024 call */
    GM_SITE(vm, 12, 3783024);
    /* @3783032 cast */
    /* @3783036 not */
    /* @3783040 bf */
    v97 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v97)) goto L_3783088;
    /* @3783044 constant */
    /* @3783048 cast */
    /* @3783052 load */
    /* @3783060 constant */
    /* @3783064 sub */
    /* @3783068 load */
    /* @3783076 call */
    GM_SITE(vm, 12, 3783076);
    /* @3783084 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3783088: ;
    /* @3783088 load */
    /* @3783096 constant */
    /* @3783100 cmp */
    /* @3783104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyghost") != VAL(-4)))) goto L_3783744;
    /* @3783108 load */
    /* @3783116 constant */
    /* @3783120 cmp */
    /* @3783124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3783744;
    /* @3783128 load */
    /* @3783136 constant */
    /* @3783140 cmp */
    /* @3783144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3783168;
    /* @3783148 load */
    /* @3783156 constant */
    /* @3783160 cmp */
    /* @3783164 b */
    p3783172_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3783172;
    L_3783168: ;
    /* @3783168 constant */
    p3783172_0 = VAL(0);
    L_3783172: ;
    /* @3783172 bf */
    if (!TRUTH(p3783172_0)) goto L_3783744;
    /* @3783176 load */
    /* @3783184 constant */
    /* @3783188 cmp */
    /* @3783192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3783564;
    /* @3783196 constant */
    /* @3783200 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3783208 load */
    /* @3783216 constant */
    /* @3783220 sub */
    /* @3783224 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3783232 load */
    /* @3783240 cast */
    /* @3783244 load */
    /* @3783252 load */
    /* @3783260 cmp */
    /* @3783264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyghost")), "x") > GM_READ(vm, -1, "x")))) goto L_3783296;
    /* @3783268 constant */
    /* @3783272 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3783280 constant */
    /* @3783284 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3783292 b */
    goto L_3783356;
    L_3783296: ;
    /* @3783296 load */
    /* @3783304 cast */
    /* @3783308 load */
    /* @3783316 load */
    /* @3783324 cmp */
    /* @3783328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyghost")), "x") < GM_READ(vm, -1, "x")))) goto L_3783356;
    /* @3783332 constant */
    /* @3783336 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3783344 constant */
    /* @3783348 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3783356: ;
    /* @3783356 constant */
    /* @3783360 constant */
    /* @3783364 constant */
    /* @3783368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3783376 constant */
    /* @3783380 constant */
    /* @3783384 constant */
    /* @3783388 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3783396 constant */
    /* @3783400 constant */
    /* @3783404 constant */
    /* @3783408 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3783416 load */
    /* @3783424 constant */
    /* @3783428 cmp */
    /* @3783432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3783440;
    /* @3783436 b */
    goto L_3783496;
    L_3783440: ;
    /* @3783440 load */
    /* @3783448 constant */
    /* @3783452 cmp */
    /* @3783456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3783496;
    /* @3783460 constant */
    /* @3783464 cast */
    /* @3783468 constant */
    /* @3783472 cast */
    /* @3783476 constant */
    /* @3783480 cast */
    /* @3783484 call */
    GM_SITE(vm, 12, 3783484);
    /* @3783492 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3783496: ;
    /* @3783496 constant */
    /* @3783500 cast */
    /* @3783504 load */
    /* @3783512 load */
    /* @3783520 load */
    /* @3783528 add */
    /* @3783532 call */
    GM_SITE(vm, 12, 3783532);
    v98 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3783540 cast */
    /* @3783544 bf */
    v99 = BOOL(GM_CALL(vm, "place_meeting", 3, v98, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v99)) goto L_3783560;
    /* @3783548 constant */
    /* @3783552 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3783560: ;
    /* @3783560 b */
    goto L_3783744;
    L_3783564: ;
    /* @3783564 load */
    /* @3783572 constant */
    /* @3783576 cmp */
    /* @3783580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3783744;
    /* @3783584 load */
    /* @3783592 constant */
    /* @3783596 cmp */
    /* @3783600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyghost") != VAL(-4)))) goto L_3783744;
    /* @3783604 load */
    /* @3783612 constant */
    /* @3783616 cmp */
    /* @3783620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3783744;
    /* @3783624 load */
    /* @3783632 constant */
    /* @3783636 cmp */
    /* @3783640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3783664;
    /* @3783644 load */
    /* @3783652 constant */
    /* @3783656 cmp */
    /* @3783660 b */
    p3783668_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3783668;
    L_3783664: ;
    /* @3783664 constant */
    p3783668_0 = VAL(0);
    L_3783668: ;
    /* @3783668 bf */
    if (!TRUTH(p3783668_0)) goto L_3783744;
    /* @3783672 constant */
    /* @3783676 cast */
    /* @3783680 call */
    GM_SITE(vm, 12, 3783680);
    /* @3783688 cast */
    /* @3783692 not */
    /* @3783696 bf */
    v100 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v100)) goto L_3783744;
    /* @3783700 constant */
    /* @3783704 cast */
    /* @3783708 load */
    /* @3783716 constant */
    /* @3783720 sub */
    /* @3783724 load */
    /* @3783732 call */
    GM_SITE(vm, 12, 3783732);
    /* @3783740 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3783744: ;
    /* @3783744 constant */
    /* @3783748 cast */
    /* @3783752 call */
    GM_SITE(vm, 12, 3783752);
    /* @3783760 cast */
    /* @3783764 bf */
    v101 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(16)));
    if (!TRUTH(v101)) goto L_3785100;
    /* @3783768 load */
    /* @3783776 constant */
    /* @3783780 cmp */
    /* @3783784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter1") != VAL(-4)))) goto L_3784424;
    /* @3783788 load */
    /* @3783796 constant */
    /* @3783800 cmp */
    /* @3783804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3784424;
    /* @3783808 load */
    /* @3783816 constant */
    /* @3783820 cmp */
    /* @3783824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3783848;
    /* @3783828 load */
    /* @3783836 constant */
    /* @3783840 cmp */
    /* @3783844 b */
    p3783852_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3783852;
    L_3783848: ;
    /* @3783848 constant */
    p3783852_0 = VAL(0);
    L_3783852: ;
    /* @3783852 bf */
    if (!TRUTH(p3783852_0)) goto L_3784424;
    /* @3783856 load */
    /* @3783864 constant */
    /* @3783868 cmp */
    /* @3783872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3784244;
    /* @3783876 constant */
    /* @3783880 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3783888 load */
    /* @3783896 constant */
    /* @3783900 sub */
    /* @3783904 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3783912 load */
    /* @3783920 cast */
    /* @3783924 load */
    /* @3783932 load */
    /* @3783940 cmp */
    /* @3783944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter1")), "x") > GM_READ(vm, -1, "x")))) goto L_3783976;
    /* @3783948 constant */
    /* @3783952 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3783960 constant */
    /* @3783964 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3783972 b */
    goto L_3784036;
    L_3783976: ;
    /* @3783976 load */
    /* @3783984 cast */
    /* @3783988 load */
    /* @3783996 load */
    /* @3784004 cmp */
    /* @3784008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter1")), "x") < GM_READ(vm, -1, "x")))) goto L_3784036;
    /* @3784012 constant */
    /* @3784016 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3784024 constant */
    /* @3784028 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3784036: ;
    /* @3784036 constant */
    /* @3784040 constant */
    /* @3784044 constant */
    /* @3784048 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3784056 constant */
    /* @3784060 constant */
    /* @3784064 constant */
    /* @3784068 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3784076 constant */
    /* @3784080 constant */
    /* @3784084 constant */
    /* @3784088 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3784096 load */
    /* @3784104 constant */
    /* @3784108 cmp */
    /* @3784112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3784120;
    /* @3784116 b */
    goto L_3784176;
    L_3784120: ;
    /* @3784120 load */
    /* @3784128 constant */
    /* @3784132 cmp */
    /* @3784136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3784176;
    /* @3784140 constant */
    /* @3784144 cast */
    /* @3784148 constant */
    /* @3784152 cast */
    /* @3784156 constant */
    /* @3784160 cast */
    /* @3784164 call */
    GM_SITE(vm, 12, 3784164);
    /* @3784172 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3784176: ;
    /* @3784176 constant */
    /* @3784180 cast */
    /* @3784184 load */
    /* @3784192 load */
    /* @3784200 load */
    /* @3784208 add */
    /* @3784212 call */
    GM_SITE(vm, 12, 3784212);
    v102 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3784220 cast */
    /* @3784224 bf */
    v103 = BOOL(GM_CALL(vm, "place_meeting", 3, v102, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v103)) goto L_3784240;
    /* @3784228 constant */
    /* @3784232 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3784240: ;
    /* @3784240 b */
    goto L_3784424;
    L_3784244: ;
    /* @3784244 load */
    /* @3784252 constant */
    /* @3784256 cmp */
    /* @3784260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3784424;
    /* @3784264 load */
    /* @3784272 constant */
    /* @3784276 cmp */
    /* @3784280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter1") != VAL(-4)))) goto L_3784424;
    /* @3784284 load */
    /* @3784292 constant */
    /* @3784296 cmp */
    /* @3784300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3784424;
    /* @3784304 load */
    /* @3784312 constant */
    /* @3784316 cmp */
    /* @3784320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3784344;
    /* @3784324 load */
    /* @3784332 constant */
    /* @3784336 cmp */
    /* @3784340 b */
    p3784348_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3784348;
    L_3784344: ;
    /* @3784344 constant */
    p3784348_0 = VAL(0);
    L_3784348: ;
    /* @3784348 bf */
    if (!TRUTH(p3784348_0)) goto L_3784424;
    /* @3784352 constant */
    /* @3784356 cast */
    /* @3784360 call */
    GM_SITE(vm, 12, 3784360);
    /* @3784368 cast */
    /* @3784372 not */
    /* @3784376 bf */
    v104 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v104)) goto L_3784424;
    /* @3784380 constant */
    /* @3784384 cast */
    /* @3784388 load */
    /* @3784396 constant */
    /* @3784400 sub */
    /* @3784404 load */
    /* @3784412 call */
    GM_SITE(vm, 12, 3784412);
    /* @3784420 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3784424: ;
    /* @3784424 load */
    /* @3784432 constant */
    /* @3784436 cmp */
    /* @3784440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter1") != VAL(-4)))) goto L_3785100;
    /* @3784444 load */
    /* @3784452 constant */
    /* @3784456 cmp */
    /* @3784460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3785100;
    /* @3784464 load */
    /* @3784472 constant */
    /* @3784476 cmp */
    /* @3784480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3784504;
    /* @3784484 load */
    /* @3784492 constant */
    /* @3784496 cmp */
    /* @3784500 b */
    p3784508_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3784508;
    L_3784504: ;
    /* @3784504 constant */
    p3784508_0 = VAL(0);
    L_3784508: ;
    /* @3784508 bf */
    if (!TRUTH(p3784508_0)) goto L_3785100;
    /* @3784512 load */
    /* @3784520 constant */
    /* @3784524 cmp */
    /* @3784528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3784920;
    /* @3784532 constant */
    /* @3784536 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3784544 load */
    /* @3784552 constant */
    /* @3784556 sub */
    /* @3784560 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3784568 load */
    /* @3784576 cast */
    /* @3784580 load */
    /* @3784588 load */
    /* @3784596 cmp */
    /* @3784600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter1")), "x") > GM_READ(vm, -1, "x")))) goto L_3784632;
    /* @3784604 constant */
    /* @3784608 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3784616 constant */
    /* @3784620 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3784628 b */
    goto L_3784692;
    L_3784632: ;
    /* @3784632 load */
    /* @3784640 cast */
    /* @3784644 load */
    /* @3784652 load */
    /* @3784660 cmp */
    /* @3784664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter1")), "x") < GM_READ(vm, -1, "x")))) goto L_3784692;
    /* @3784668 constant */
    /* @3784672 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3784680 constant */
    /* @3784684 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3784692: ;
    /* @3784692 constant */
    /* @3784696 constant */
    /* @3784700 constant */
    /* @3784704 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3784712 constant */
    /* @3784716 constant */
    /* @3784720 constant */
    /* @3784724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3784732 constant */
    /* @3784736 constant */
    /* @3784740 constant */
    /* @3784744 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3784752 load */
    /* @3784760 constant */
    /* @3784764 cmp */
    /* @3784768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3784776;
    /* @3784772 b */
    goto L_3784832;
    L_3784776: ;
    /* @3784776 load */
    /* @3784784 constant */
    /* @3784788 cmp */
    /* @3784792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3784832;
    /* @3784796 constant */
    /* @3784800 cast */
    /* @3784804 constant */
    /* @3784808 cast */
    /* @3784812 constant */
    /* @3784816 cast */
    /* @3784820 call */
    GM_SITE(vm, 12, 3784820);
    /* @3784828 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3784832: ;
    /* @3784832 constant */
    /* @3784844 store */
    GM_WRITE(vm, -1, "friction", VAL(0.6));
    /* @3784852 constant */
    /* @3784856 cast */
    /* @3784860 load */
    /* @3784868 load */
    /* @3784876 load */
    /* @3784884 add */
    /* @3784888 call */
    GM_SITE(vm, 12, 3784888);
    v105 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3784896 cast */
    /* @3784900 bf */
    v106 = BOOL(GM_CALL(vm, "place_meeting", 3, v105, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v106)) goto L_3784916;
    /* @3784904 constant */
    /* @3784908 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3784916: ;
    /* @3784916 b */
    goto L_3785100;
    L_3784920: ;
    /* @3784920 load */
    /* @3784928 constant */
    /* @3784932 cmp */
    /* @3784936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3785100;
    /* @3784940 load */
    /* @3784948 constant */
    /* @3784952 cmp */
    /* @3784956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter1") != VAL(-4)))) goto L_3785100;
    /* @3784960 load */
    /* @3784968 constant */
    /* @3784972 cmp */
    /* @3784976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3785100;
    /* @3784980 load */
    /* @3784988 constant */
    /* @3784992 cmp */
    /* @3784996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3785020;
    /* @3785000 load */
    /* @3785008 constant */
    /* @3785012 cmp */
    /* @3785016 b */
    p3785024_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3785024;
    L_3785020: ;
    /* @3785020 constant */
    p3785024_0 = VAL(0);
    L_3785024: ;
    /* @3785024 bf */
    if (!TRUTH(p3785024_0)) goto L_3785100;
    /* @3785028 constant */
    /* @3785032 cast */
    /* @3785036 call */
    GM_SITE(vm, 12, 3785036);
    /* @3785044 cast */
    /* @3785048 not */
    /* @3785052 bf */
    v107 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v107)) goto L_3785100;
    /* @3785056 constant */
    /* @3785060 cast */
    /* @3785064 load */
    /* @3785072 constant */
    /* @3785076 sub */
    /* @3785080 load */
    /* @3785088 call */
    GM_SITE(vm, 12, 3785088);
    /* @3785096 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3785100: ;
    /* @3785100 constant */
    /* @3785104 cast */
    /* @3785108 call */
    GM_SITE(vm, 12, 3785108);
    /* @3785116 cast */
    /* @3785120 bf */
    v108 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(20)));
    if (!TRUTH(v108)) goto L_3786456;
    /* @3785124 load */
    /* @3785132 constant */
    /* @3785136 cmp */
    /* @3785140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter2") != VAL(-4)))) goto L_3785800;
    /* @3785144 load */
    /* @3785152 constant */
    /* @3785156 cmp */
    /* @3785160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3785800;
    /* @3785164 load */
    /* @3785172 constant */
    /* @3785176 cmp */
    /* @3785180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3785204;
    /* @3785184 load */
    /* @3785192 constant */
    /* @3785196 cmp */
    /* @3785200 b */
    p3785208_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3785208;
    L_3785204: ;
    /* @3785204 constant */
    p3785208_0 = VAL(0);
    L_3785208: ;
    /* @3785208 bf */
    if (!TRUTH(p3785208_0)) goto L_3785800;
    /* @3785212 load */
    /* @3785220 constant */
    /* @3785224 cmp */
    /* @3785228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3785620;
    /* @3785232 constant */
    /* @3785236 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3785244 load */
    /* @3785252 constant */
    /* @3785256 sub */
    /* @3785260 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3785268 load */
    /* @3785276 cast */
    /* @3785280 load */
    /* @3785288 load */
    /* @3785296 cmp */
    /* @3785300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter2")), "x") > GM_READ(vm, -1, "x")))) goto L_3785332;
    /* @3785304 constant */
    /* @3785308 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3785316 constant */
    /* @3785320 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3785328 b */
    goto L_3785392;
    L_3785332: ;
    /* @3785332 load */
    /* @3785340 cast */
    /* @3785344 load */
    /* @3785352 load */
    /* @3785360 cmp */
    /* @3785364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter2")), "x") < GM_READ(vm, -1, "x")))) goto L_3785392;
    /* @3785368 constant */
    /* @3785372 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3785380 constant */
    /* @3785384 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3785392: ;
    /* @3785392 constant */
    /* @3785396 constant */
    /* @3785400 constant */
    /* @3785404 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3785412 constant */
    /* @3785416 constant */
    /* @3785420 constant */
    /* @3785424 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3785432 constant */
    /* @3785436 constant */
    /* @3785440 constant */
    /* @3785444 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3785452 load */
    /* @3785460 constant */
    /* @3785464 cmp */
    /* @3785468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3785476;
    /* @3785472 b */
    goto L_3785532;
    L_3785476: ;
    /* @3785476 load */
    /* @3785484 constant */
    /* @3785488 cmp */
    /* @3785492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3785532;
    /* @3785496 constant */
    /* @3785500 cast */
    /* @3785504 constant */
    /* @3785508 cast */
    /* @3785512 constant */
    /* @3785516 cast */
    /* @3785520 call */
    GM_SITE(vm, 12, 3785520);
    /* @3785528 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3785532: ;
    /* @3785532 constant */
    /* @3785544 store */
    GM_WRITE(vm, -1, "friction", VAL(0.6));
    /* @3785552 constant */
    /* @3785556 cast */
    /* @3785560 load */
    /* @3785568 load */
    /* @3785576 load */
    /* @3785584 add */
    /* @3785588 call */
    GM_SITE(vm, 12, 3785588);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3785596 cast */
    /* @3785600 bf */
    v110 = BOOL(GM_CALL(vm, "place_meeting", 3, v109, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v110)) goto L_3785616;
    /* @3785604 constant */
    /* @3785608 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3785616: ;
    /* @3785616 b */
    goto L_3785800;
    L_3785620: ;
    /* @3785620 load */
    /* @3785628 constant */
    /* @3785632 cmp */
    /* @3785636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3785800;
    /* @3785640 load */
    /* @3785648 constant */
    /* @3785652 cmp */
    /* @3785656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter2") != VAL(-4)))) goto L_3785800;
    /* @3785660 load */
    /* @3785668 constant */
    /* @3785672 cmp */
    /* @3785676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3785800;
    /* @3785680 load */
    /* @3785688 constant */
    /* @3785692 cmp */
    /* @3785696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3785720;
    /* @3785700 load */
    /* @3785708 constant */
    /* @3785712 cmp */
    /* @3785716 b */
    p3785724_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3785724;
    L_3785720: ;
    /* @3785720 constant */
    p3785724_0 = VAL(0);
    L_3785724: ;
    /* @3785724 bf */
    if (!TRUTH(p3785724_0)) goto L_3785800;
    /* @3785728 constant */
    /* @3785732 cast */
    /* @3785736 call */
    GM_SITE(vm, 12, 3785736);
    /* @3785744 cast */
    /* @3785748 not */
    /* @3785752 bf */
    v111 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v111)) goto L_3785800;
    /* @3785756 constant */
    /* @3785760 cast */
    /* @3785764 load */
    /* @3785772 constant */
    /* @3785776 sub */
    /* @3785780 load */
    /* @3785788 call */
    GM_SITE(vm, 12, 3785788);
    /* @3785796 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3785800: ;
    /* @3785800 load */
    /* @3785808 constant */
    /* @3785812 cmp */
    /* @3785816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter2") != VAL(-4)))) goto L_3786456;
    /* @3785820 load */
    /* @3785828 constant */
    /* @3785832 cmp */
    /* @3785836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3786456;
    /* @3785840 load */
    /* @3785848 constant */
    /* @3785852 cmp */
    /* @3785856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3785880;
    /* @3785860 load */
    /* @3785868 constant */
    /* @3785872 cmp */
    /* @3785876 b */
    p3785884_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3785884;
    L_3785880: ;
    /* @3785880 constant */
    p3785884_0 = VAL(0);
    L_3785884: ;
    /* @3785884 bf */
    if (!TRUTH(p3785884_0)) goto L_3786456;
    /* @3785888 load */
    /* @3785896 constant */
    /* @3785900 cmp */
    /* @3785904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3786276;
    /* @3785908 constant */
    /* @3785912 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3785920 load */
    /* @3785928 constant */
    /* @3785932 sub */
    /* @3785936 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3785944 load */
    /* @3785952 cast */
    /* @3785956 load */
    /* @3785964 load */
    /* @3785972 cmp */
    /* @3785976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter2")), "x") > GM_READ(vm, -1, "x")))) goto L_3786008;
    /* @3785980 constant */
    /* @3785984 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3785992 constant */
    /* @3785996 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3786004 b */
    goto L_3786068;
    L_3786008: ;
    /* @3786008 load */
    /* @3786016 cast */
    /* @3786020 load */
    /* @3786028 load */
    /* @3786036 cmp */
    /* @3786040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyshooter2")), "x") < GM_READ(vm, -1, "x")))) goto L_3786068;
    /* @3786044 constant */
    /* @3786048 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3786056 constant */
    /* @3786060 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3786068: ;
    /* @3786068 constant */
    /* @3786072 constant */
    /* @3786076 constant */
    /* @3786080 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3786088 constant */
    /* @3786092 constant */
    /* @3786096 constant */
    /* @3786100 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3786108 constant */
    /* @3786112 constant */
    /* @3786116 constant */
    /* @3786120 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3786128 load */
    /* @3786136 constant */
    /* @3786140 cmp */
    /* @3786144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3786152;
    /* @3786148 b */
    goto L_3786208;
    L_3786152: ;
    /* @3786152 load */
    /* @3786160 constant */
    /* @3786164 cmp */
    /* @3786168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3786208;
    /* @3786172 constant */
    /* @3786176 cast */
    /* @3786180 constant */
    /* @3786184 cast */
    /* @3786188 constant */
    /* @3786192 cast */
    /* @3786196 call */
    GM_SITE(vm, 12, 3786196);
    /* @3786204 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3786208: ;
    /* @3786208 constant */
    /* @3786212 cast */
    /* @3786216 load */
    /* @3786224 load */
    /* @3786232 load */
    /* @3786240 add */
    /* @3786244 call */
    GM_SITE(vm, 12, 3786244);
    v112 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3786252 cast */
    /* @3786256 bf */
    v113 = BOOL(GM_CALL(vm, "place_meeting", 3, v112, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v113)) goto L_3786272;
    /* @3786260 constant */
    /* @3786264 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3786272: ;
    /* @3786272 b */
    goto L_3786456;
    L_3786276: ;
    /* @3786276 load */
    /* @3786284 constant */
    /* @3786288 cmp */
    /* @3786292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3786456;
    /* @3786296 load */
    /* @3786304 constant */
    /* @3786308 cmp */
    /* @3786312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyshooter2") != VAL(-4)))) goto L_3786456;
    /* @3786316 load */
    /* @3786324 constant */
    /* @3786328 cmp */
    /* @3786332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3786456;
    /* @3786336 load */
    /* @3786344 constant */
    /* @3786348 cmp */
    /* @3786352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3786376;
    /* @3786356 load */
    /* @3786364 constant */
    /* @3786368 cmp */
    /* @3786372 b */
    p3786380_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3786380;
    L_3786376: ;
    /* @3786376 constant */
    p3786380_0 = VAL(0);
    L_3786380: ;
    /* @3786380 bf */
    if (!TRUTH(p3786380_0)) goto L_3786456;
    /* @3786384 constant */
    /* @3786388 cast */
    /* @3786392 call */
    GM_SITE(vm, 12, 3786392);
    /* @3786400 cast */
    /* @3786404 not */
    /* @3786408 bf */
    v114 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v114)) goto L_3786456;
    /* @3786412 constant */
    /* @3786416 cast */
    /* @3786420 load */
    /* @3786428 constant */
    /* @3786432 sub */
    /* @3786436 load */
    /* @3786444 call */
    GM_SITE(vm, 12, 3786444);
    /* @3786452 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3786456: ;
    /* @3786456 constant */
    /* @3786460 cast */
    /* @3786464 call */
    GM_SITE(vm, 12, 3786464);
    /* @3786472 cast */
    /* @3786476 bf */
    v115 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(33)));
    if (!TRUTH(v115)) goto L_3787792;
    /* @3786480 load */
    /* @3786488 constant */
    /* @3786492 cmp */
    /* @3786496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyfireslime") != VAL(-4)))) goto L_3787136;
    /* @3786500 load */
    /* @3786508 constant */
    /* @3786512 cmp */
    /* @3786516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3787136;
    /* @3786520 load */
    /* @3786528 constant */
    /* @3786532 cmp */
    /* @3786536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3786560;
    /* @3786540 load */
    /* @3786548 constant */
    /* @3786552 cmp */
    /* @3786556 b */
    p3786564_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3786564;
    L_3786560: ;
    /* @3786560 constant */
    p3786564_0 = VAL(0);
    L_3786564: ;
    /* @3786564 bf */
    if (!TRUTH(p3786564_0)) goto L_3787136;
    /* @3786568 load */
    /* @3786576 constant */
    /* @3786580 cmp */
    /* @3786584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3786956;
    /* @3786588 constant */
    /* @3786592 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3786600 load */
    /* @3786608 constant */
    /* @3786612 sub */
    /* @3786616 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3786624 load */
    /* @3786632 cast */
    /* @3786636 load */
    /* @3786644 load */
    /* @3786652 cmp */
    /* @3786656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyfireslime")), "x") > GM_READ(vm, -1, "x")))) goto L_3786688;
    /* @3786660 constant */
    /* @3786664 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3786672 constant */
    /* @3786676 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3786684 b */
    goto L_3786748;
    L_3786688: ;
    /* @3786688 load */
    /* @3786696 cast */
    /* @3786700 load */
    /* @3786708 load */
    /* @3786716 cmp */
    /* @3786720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyfireslime")), "x") < GM_READ(vm, -1, "x")))) goto L_3786748;
    /* @3786724 constant */
    /* @3786728 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3786736 constant */
    /* @3786740 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3786748: ;
    /* @3786748 constant */
    /* @3786752 constant */
    /* @3786756 constant */
    /* @3786760 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3786768 constant */
    /* @3786772 constant */
    /* @3786776 constant */
    /* @3786780 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3786788 constant */
    /* @3786792 constant */
    /* @3786796 constant */
    /* @3786800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3786808 load */
    /* @3786816 constant */
    /* @3786820 cmp */
    /* @3786824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3786832;
    /* @3786828 b */
    goto L_3786888;
    L_3786832: ;
    /* @3786832 load */
    /* @3786840 constant */
    /* @3786844 cmp */
    /* @3786848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3786888;
    /* @3786852 constant */
    /* @3786856 cast */
    /* @3786860 constant */
    /* @3786864 cast */
    /* @3786868 constant */
    /* @3786872 cast */
    /* @3786876 call */
    GM_SITE(vm, 12, 3786876);
    /* @3786884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3786888: ;
    /* @3786888 constant */
    /* @3786892 cast */
    /* @3786896 load */
    /* @3786904 load */
    /* @3786912 load */
    /* @3786920 add */
    /* @3786924 call */
    GM_SITE(vm, 12, 3786924);
    v116 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3786932 cast */
    /* @3786936 bf */
    v117 = BOOL(GM_CALL(vm, "place_meeting", 3, v116, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v117)) goto L_3786952;
    /* @3786940 constant */
    /* @3786944 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3786952: ;
    /* @3786952 b */
    goto L_3787136;
    L_3786956: ;
    /* @3786956 load */
    /* @3786964 constant */
    /* @3786968 cmp */
    /* @3786972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3787136;
    /* @3786976 load */
    /* @3786984 constant */
    /* @3786988 cmp */
    /* @3786992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyfireslime") != VAL(-4)))) goto L_3787136;
    /* @3786996 load */
    /* @3787004 constant */
    /* @3787008 cmp */
    /* @3787012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3787136;
    /* @3787016 load */
    /* @3787024 constant */
    /* @3787028 cmp */
    /* @3787032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3787056;
    /* @3787036 load */
    /* @3787044 constant */
    /* @3787048 cmp */
    /* @3787052 b */
    p3787060_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3787060;
    L_3787056: ;
    /* @3787056 constant */
    p3787060_0 = VAL(0);
    L_3787060: ;
    /* @3787060 bf */
    if (!TRUTH(p3787060_0)) goto L_3787136;
    /* @3787064 constant */
    /* @3787068 cast */
    /* @3787072 call */
    GM_SITE(vm, 12, 3787072);
    /* @3787080 cast */
    /* @3787084 not */
    /* @3787088 bf */
    v118 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v118)) goto L_3787136;
    /* @3787092 constant */
    /* @3787096 cast */
    /* @3787100 load */
    /* @3787108 constant */
    /* @3787112 sub */
    /* @3787116 load */
    /* @3787124 call */
    GM_SITE(vm, 12, 3787124);
    /* @3787132 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3787136: ;
    /* @3787136 load */
    /* @3787144 constant */
    /* @3787148 cmp */
    /* @3787152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyfireslime") != VAL(-4)))) goto L_3787792;
    /* @3787156 load */
    /* @3787164 constant */
    /* @3787168 cmp */
    /* @3787172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3787792;
    /* @3787176 load */
    /* @3787184 constant */
    /* @3787188 cmp */
    /* @3787192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3787216;
    /* @3787196 load */
    /* @3787204 constant */
    /* @3787208 cmp */
    /* @3787212 b */
    p3787220_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3787220;
    L_3787216: ;
    /* @3787216 constant */
    p3787220_0 = VAL(0);
    L_3787220: ;
    /* @3787220 bf */
    if (!TRUTH(p3787220_0)) goto L_3787792;
    /* @3787224 load */
    /* @3787232 constant */
    /* @3787236 cmp */
    /* @3787240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3787612;
    /* @3787244 constant */
    /* @3787248 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3787256 load */
    /* @3787264 constant */
    /* @3787268 sub */
    /* @3787272 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3787280 load */
    /* @3787288 cast */
    /* @3787292 load */
    /* @3787300 load */
    /* @3787308 cmp */
    /* @3787312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyfireslime")), "x") > GM_READ(vm, -1, "x")))) goto L_3787344;
    /* @3787316 constant */
    /* @3787320 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3787328 constant */
    /* @3787332 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3787340 b */
    goto L_3787404;
    L_3787344: ;
    /* @3787344 load */
    /* @3787352 cast */
    /* @3787356 load */
    /* @3787364 load */
    /* @3787372 cmp */
    /* @3787376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyfireslime")), "x") < GM_READ(vm, -1, "x")))) goto L_3787404;
    /* @3787380 constant */
    /* @3787384 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3787392 constant */
    /* @3787396 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3787404: ;
    /* @3787404 constant */
    /* @3787408 constant */
    /* @3787412 constant */
    /* @3787416 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3787424 constant */
    /* @3787428 constant */
    /* @3787432 constant */
    /* @3787436 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3787444 constant */
    /* @3787448 constant */
    /* @3787452 constant */
    /* @3787456 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3787464 load */
    /* @3787472 constant */
    /* @3787476 cmp */
    /* @3787480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3787488;
    /* @3787484 b */
    goto L_3787544;
    L_3787488: ;
    /* @3787488 load */
    /* @3787496 constant */
    /* @3787500 cmp */
    /* @3787504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3787544;
    /* @3787508 constant */
    /* @3787512 cast */
    /* @3787516 constant */
    /* @3787520 cast */
    /* @3787524 constant */
    /* @3787528 cast */
    /* @3787532 call */
    GM_SITE(vm, 12, 3787532);
    /* @3787540 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3787544: ;
    /* @3787544 constant */
    /* @3787548 cast */
    /* @3787552 load */
    /* @3787560 load */
    /* @3787568 load */
    /* @3787576 add */
    /* @3787580 call */
    GM_SITE(vm, 12, 3787580);
    v119 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3787588 cast */
    /* @3787592 bf */
    v120 = BOOL(GM_CALL(vm, "place_meeting", 3, v119, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v120)) goto L_3787608;
    /* @3787596 constant */
    /* @3787600 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3787608: ;
    /* @3787608 b */
    goto L_3787792;
    L_3787612: ;
    /* @3787612 load */
    /* @3787620 constant */
    /* @3787624 cmp */
    /* @3787628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3787792;
    /* @3787632 load */
    /* @3787640 constant */
    /* @3787644 cmp */
    /* @3787648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyfireslime") != VAL(-4)))) goto L_3787792;
    /* @3787652 load */
    /* @3787660 constant */
    /* @3787664 cmp */
    /* @3787668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3787792;
    /* @3787672 load */
    /* @3787680 constant */
    /* @3787684 cmp */
    /* @3787688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3787712;
    /* @3787692 load */
    /* @3787700 constant */
    /* @3787704 cmp */
    /* @3787708 b */
    p3787716_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3787716;
    L_3787712: ;
    /* @3787712 constant */
    p3787716_0 = VAL(0);
    L_3787716: ;
    /* @3787716 bf */
    if (!TRUTH(p3787716_0)) goto L_3787792;
    /* @3787720 constant */
    /* @3787724 cast */
    /* @3787728 call */
    GM_SITE(vm, 12, 3787728);
    /* @3787736 cast */
    /* @3787740 not */
    /* @3787744 bf */
    v121 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v121)) goto L_3787792;
    /* @3787748 constant */
    /* @3787752 cast */
    /* @3787756 load */
    /* @3787764 constant */
    /* @3787768 sub */
    /* @3787772 load */
    /* @3787780 call */
    GM_SITE(vm, 12, 3787780);
    /* @3787788 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3787792: ;
    /* @3787792 constant */
    /* @3787796 cast */
    /* @3787800 call */
    GM_SITE(vm, 12, 3787800);
    /* @3787808 cast */
    /* @3787812 bf */
    v122 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(21)));
    if (!TRUTH(v122)) goto L_3789128;
    /* @3787816 load */
    /* @3787824 constant */
    /* @3787828 cmp */
    /* @3787832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyhulkingbandit") != VAL(-4)))) goto L_3788472;
    /* @3787836 load */
    /* @3787844 constant */
    /* @3787848 cmp */
    /* @3787852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3788472;
    /* @3787856 load */
    /* @3787864 constant */
    /* @3787868 cmp */
    /* @3787872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3787896;
    /* @3787876 load */
    /* @3787884 constant */
    /* @3787888 cmp */
    /* @3787892 b */
    p3787900_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3787900;
    L_3787896: ;
    /* @3787896 constant */
    p3787900_0 = VAL(0);
    L_3787900: ;
    /* @3787900 bf */
    if (!TRUTH(p3787900_0)) goto L_3788472;
    /* @3787904 load */
    /* @3787912 constant */
    /* @3787916 cmp */
    /* @3787920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3788292;
    /* @3787924 constant */
    /* @3787928 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3787936 load */
    /* @3787944 constant */
    /* @3787948 sub */
    /* @3787952 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3787960 load */
    /* @3787968 cast */
    /* @3787972 load */
    /* @3787980 load */
    /* @3787988 cmp */
    /* @3787992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyhulkingbandit")), "x") > GM_READ(vm, -1, "x")))) goto L_3788024;
    /* @3787996 constant */
    /* @3788000 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3788008 constant */
    /* @3788012 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3788020 b */
    goto L_3788084;
    L_3788024: ;
    /* @3788024 load */
    /* @3788032 cast */
    /* @3788036 load */
    /* @3788044 load */
    /* @3788052 cmp */
    /* @3788056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyhulkingbandit")), "x") < GM_READ(vm, -1, "x")))) goto L_3788084;
    /* @3788060 constant */
    /* @3788064 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3788072 constant */
    /* @3788076 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3788084: ;
    /* @3788084 constant */
    /* @3788088 constant */
    /* @3788092 constant */
    /* @3788096 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3788104 constant */
    /* @3788108 constant */
    /* @3788112 constant */
    /* @3788116 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3788124 constant */
    /* @3788128 constant */
    /* @3788132 constant */
    /* @3788136 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3788144 load */
    /* @3788152 constant */
    /* @3788156 cmp */
    /* @3788160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3788168;
    /* @3788164 b */
    goto L_3788224;
    L_3788168: ;
    /* @3788168 load */
    /* @3788176 constant */
    /* @3788180 cmp */
    /* @3788184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3788224;
    /* @3788188 constant */
    /* @3788192 cast */
    /* @3788196 constant */
    /* @3788200 cast */
    /* @3788204 constant */
    /* @3788208 cast */
    /* @3788212 call */
    GM_SITE(vm, 12, 3788212);
    /* @3788220 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3788224: ;
    /* @3788224 constant */
    /* @3788228 cast */
    /* @3788232 load */
    /* @3788240 load */
    /* @3788248 load */
    /* @3788256 add */
    /* @3788260 call */
    GM_SITE(vm, 12, 3788260);
    v123 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3788268 cast */
    /* @3788272 bf */
    v124 = BOOL(GM_CALL(vm, "place_meeting", 3, v123, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v124)) goto L_3788288;
    /* @3788276 constant */
    /* @3788280 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3788288: ;
    /* @3788288 b */
    goto L_3788472;
    L_3788292: ;
    /* @3788292 load */
    /* @3788300 constant */
    /* @3788304 cmp */
    /* @3788308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3788472;
    /* @3788312 load */
    /* @3788320 constant */
    /* @3788324 cmp */
    /* @3788328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyhulkingbandit") != VAL(-4)))) goto L_3788472;
    /* @3788332 load */
    /* @3788340 constant */
    /* @3788344 cmp */
    /* @3788348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3788472;
    /* @3788352 load */
    /* @3788360 constant */
    /* @3788364 cmp */
    /* @3788368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3788392;
    /* @3788372 load */
    /* @3788380 constant */
    /* @3788384 cmp */
    /* @3788388 b */
    p3788396_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3788396;
    L_3788392: ;
    /* @3788392 constant */
    p3788396_0 = VAL(0);
    L_3788396: ;
    /* @3788396 bf */
    if (!TRUTH(p3788396_0)) goto L_3788472;
    /* @3788400 constant */
    /* @3788404 cast */
    /* @3788408 call */
    GM_SITE(vm, 12, 3788408);
    /* @3788416 cast */
    /* @3788420 not */
    /* @3788424 bf */
    v125 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v125)) goto L_3788472;
    /* @3788428 constant */
    /* @3788432 cast */
    /* @3788436 load */
    /* @3788444 constant */
    /* @3788448 sub */
    /* @3788452 load */
    /* @3788460 call */
    GM_SITE(vm, 12, 3788460);
    /* @3788468 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3788472: ;
    /* @3788472 load */
    /* @3788480 constant */
    /* @3788484 cmp */
    /* @3788488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyhulkingbandit") != VAL(-4)))) goto L_3789128;
    /* @3788492 load */
    /* @3788500 constant */
    /* @3788504 cmp */
    /* @3788508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3789128;
    /* @3788512 load */
    /* @3788520 constant */
    /* @3788524 cmp */
    /* @3788528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3788552;
    /* @3788532 load */
    /* @3788540 constant */
    /* @3788544 cmp */
    /* @3788548 b */
    p3788556_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3788556;
    L_3788552: ;
    /* @3788552 constant */
    p3788556_0 = VAL(0);
    L_3788556: ;
    /* @3788556 bf */
    if (!TRUTH(p3788556_0)) goto L_3789128;
    /* @3788560 load */
    /* @3788568 constant */
    /* @3788572 cmp */
    /* @3788576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3788948;
    /* @3788580 constant */
    /* @3788584 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3788592 load */
    /* @3788600 constant */
    /* @3788604 sub */
    /* @3788608 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3788616 load */
    /* @3788624 cast */
    /* @3788628 load */
    /* @3788636 load */
    /* @3788644 cmp */
    /* @3788648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyhulkingbandit")), "x") > GM_READ(vm, -1, "x")))) goto L_3788680;
    /* @3788652 constant */
    /* @3788656 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3788664 constant */
    /* @3788668 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3788676 b */
    goto L_3788740;
    L_3788680: ;
    /* @3788680 load */
    /* @3788688 cast */
    /* @3788692 load */
    /* @3788700 load */
    /* @3788708 cmp */
    /* @3788712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyhulkingbandit")), "x") < GM_READ(vm, -1, "x")))) goto L_3788740;
    /* @3788716 constant */
    /* @3788720 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3788728 constant */
    /* @3788732 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3788740: ;
    /* @3788740 constant */
    /* @3788744 constant */
    /* @3788748 constant */
    /* @3788752 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3788760 constant */
    /* @3788764 constant */
    /* @3788768 constant */
    /* @3788772 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3788780 constant */
    /* @3788784 constant */
    /* @3788788 constant */
    /* @3788792 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3788800 load */
    /* @3788808 constant */
    /* @3788812 cmp */
    /* @3788816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3788824;
    /* @3788820 b */
    goto L_3788880;
    L_3788824: ;
    /* @3788824 load */
    /* @3788832 constant */
    /* @3788836 cmp */
    /* @3788840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3788880;
    /* @3788844 constant */
    /* @3788848 cast */
    /* @3788852 constant */
    /* @3788856 cast */
    /* @3788860 constant */
    /* @3788864 cast */
    /* @3788868 call */
    GM_SITE(vm, 12, 3788868);
    /* @3788876 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3788880: ;
    /* @3788880 constant */
    /* @3788884 cast */
    /* @3788888 load */
    /* @3788896 load */
    /* @3788904 load */
    /* @3788912 add */
    /* @3788916 call */
    GM_SITE(vm, 12, 3788916);
    v126 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3788924 cast */
    /* @3788928 bf */
    v127 = BOOL(GM_CALL(vm, "place_meeting", 3, v126, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v127)) goto L_3788944;
    /* @3788932 constant */
    /* @3788936 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3788944: ;
    /* @3788944 b */
    goto L_3789128;
    L_3788948: ;
    /* @3788948 load */
    /* @3788956 constant */
    /* @3788960 cmp */
    /* @3788964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3789128;
    /* @3788968 load */
    /* @3788976 constant */
    /* @3788980 cmp */
    /* @3788984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyhulkingbandit") != VAL(-4)))) goto L_3789128;
    /* @3788988 load */
    /* @3788996 constant */
    /* @3789000 cmp */
    /* @3789004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3789128;
    /* @3789008 load */
    /* @3789016 constant */
    /* @3789020 cmp */
    /* @3789024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3789048;
    /* @3789028 load */
    /* @3789036 constant */
    /* @3789040 cmp */
    /* @3789044 b */
    p3789052_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3789052;
    L_3789048: ;
    /* @3789048 constant */
    p3789052_0 = VAL(0);
    L_3789052: ;
    /* @3789052 bf */
    if (!TRUTH(p3789052_0)) goto L_3789128;
    /* @3789056 constant */
    /* @3789060 cast */
    /* @3789064 call */
    GM_SITE(vm, 12, 3789064);
    /* @3789072 cast */
    /* @3789076 not */
    /* @3789080 bf */
    v128 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v128)) goto L_3789128;
    /* @3789084 constant */
    /* @3789088 cast */
    /* @3789092 load */
    /* @3789100 constant */
    /* @3789104 sub */
    /* @3789108 load */
    /* @3789116 call */
    GM_SITE(vm, 12, 3789116);
    /* @3789124 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3789128: ;
    /* @3789128 constant */
    /* @3789132 cast */
    /* @3789136 call */
    GM_SITE(vm, 12, 3789136);
    /* @3789144 cast */
    /* @3789148 bf */
    v129 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(19)));
    if (!TRUTH(v129)) goto L_3790464;
    /* @3789152 load */
    /* @3789160 constant */
    /* @3789164 cmp */
    /* @3789168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyzombie") != VAL(-4)))) goto L_3789808;
    /* @3789172 load */
    /* @3789180 constant */
    /* @3789184 cmp */
    /* @3789188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3789808;
    /* @3789192 load */
    /* @3789200 constant */
    /* @3789204 cmp */
    /* @3789208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3789232;
    /* @3789212 load */
    /* @3789220 constant */
    /* @3789224 cmp */
    /* @3789228 b */
    p3789236_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3789236;
    L_3789232: ;
    /* @3789232 constant */
    p3789236_0 = VAL(0);
    L_3789236: ;
    /* @3789236 bf */
    if (!TRUTH(p3789236_0)) goto L_3789808;
    /* @3789240 load */
    /* @3789248 constant */
    /* @3789252 cmp */
    /* @3789256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3789628;
    /* @3789260 constant */
    /* @3789264 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3789272 load */
    /* @3789280 constant */
    /* @3789284 sub */
    /* @3789288 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3789296 load */
    /* @3789304 cast */
    /* @3789308 load */
    /* @3789316 load */
    /* @3789324 cmp */
    /* @3789328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyzombie")), "x") > GM_READ(vm, -1, "x")))) goto L_3789360;
    /* @3789332 constant */
    /* @3789336 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3789344 constant */
    /* @3789348 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3789356 b */
    goto L_3789420;
    L_3789360: ;
    /* @3789360 load */
    /* @3789368 cast */
    /* @3789372 load */
    /* @3789380 load */
    /* @3789388 cmp */
    /* @3789392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyzombie")), "x") < GM_READ(vm, -1, "x")))) goto L_3789420;
    /* @3789396 constant */
    /* @3789400 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3789408 constant */
    /* @3789412 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3789420: ;
    /* @3789420 constant */
    /* @3789424 constant */
    /* @3789428 constant */
    /* @3789432 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3789440 constant */
    /* @3789444 constant */
    /* @3789448 constant */
    /* @3789452 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3789460 constant */
    /* @3789464 constant */
    /* @3789468 constant */
    /* @3789472 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3789480 load */
    /* @3789488 constant */
    /* @3789492 cmp */
    /* @3789496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3789504;
    /* @3789500 b */
    goto L_3789560;
    L_3789504: ;
    /* @3789504 load */
    /* @3789512 constant */
    /* @3789516 cmp */
    /* @3789520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3789560;
    /* @3789524 constant */
    /* @3789528 cast */
    /* @3789532 constant */
    /* @3789536 cast */
    /* @3789540 constant */
    /* @3789544 cast */
    /* @3789548 call */
    GM_SITE(vm, 12, 3789548);
    /* @3789556 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3789560: ;
    /* @3789560 constant */
    /* @3789564 cast */
    /* @3789568 load */
    /* @3789576 load */
    /* @3789584 load */
    /* @3789592 add */
    /* @3789596 call */
    GM_SITE(vm, 12, 3789596);
    v130 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3789604 cast */
    /* @3789608 bf */
    v131 = BOOL(GM_CALL(vm, "place_meeting", 3, v130, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v131)) goto L_3789624;
    /* @3789612 constant */
    /* @3789616 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3789624: ;
    /* @3789624 b */
    goto L_3789808;
    L_3789628: ;
    /* @3789628 load */
    /* @3789636 constant */
    /* @3789640 cmp */
    /* @3789644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3789808;
    /* @3789648 load */
    /* @3789656 constant */
    /* @3789660 cmp */
    /* @3789664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyzombie") != VAL(-4)))) goto L_3789808;
    /* @3789668 load */
    /* @3789676 constant */
    /* @3789680 cmp */
    /* @3789684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3789808;
    /* @3789688 load */
    /* @3789696 constant */
    /* @3789700 cmp */
    /* @3789704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3789728;
    /* @3789708 load */
    /* @3789716 constant */
    /* @3789720 cmp */
    /* @3789724 b */
    p3789732_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3789732;
    L_3789728: ;
    /* @3789728 constant */
    p3789732_0 = VAL(0);
    L_3789732: ;
    /* @3789732 bf */
    if (!TRUTH(p3789732_0)) goto L_3789808;
    /* @3789736 constant */
    /* @3789740 cast */
    /* @3789744 call */
    GM_SITE(vm, 12, 3789744);
    /* @3789752 cast */
    /* @3789756 not */
    /* @3789760 bf */
    v132 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v132)) goto L_3789808;
    /* @3789764 constant */
    /* @3789768 cast */
    /* @3789772 load */
    /* @3789780 constant */
    /* @3789784 sub */
    /* @3789788 load */
    /* @3789796 call */
    GM_SITE(vm, 12, 3789796);
    /* @3789804 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3789808: ;
    /* @3789808 load */
    /* @3789816 constant */
    /* @3789820 cmp */
    /* @3789824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyzombie") != VAL(-4)))) goto L_3790464;
    /* @3789828 load */
    /* @3789836 constant */
    /* @3789840 cmp */
    /* @3789844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3790464;
    /* @3789848 load */
    /* @3789856 constant */
    /* @3789860 cmp */
    /* @3789864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3789888;
    /* @3789868 load */
    /* @3789876 constant */
    /* @3789880 cmp */
    /* @3789884 b */
    p3789892_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3789892;
    L_3789888: ;
    /* @3789888 constant */
    p3789892_0 = VAL(0);
    L_3789892: ;
    /* @3789892 bf */
    if (!TRUTH(p3789892_0)) goto L_3790464;
    /* @3789896 load */
    /* @3789904 constant */
    /* @3789908 cmp */
    /* @3789912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3790284;
    /* @3789916 constant */
    /* @3789920 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3789928 load */
    /* @3789936 constant */
    /* @3789940 sub */
    /* @3789944 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3789952 load */
    /* @3789960 cast */
    /* @3789964 load */
    /* @3789972 load */
    /* @3789980 cmp */
    /* @3789984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyzombie")), "x") > GM_READ(vm, -1, "x")))) goto L_3790016;
    /* @3789988 constant */
    /* @3789992 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3790000 constant */
    /* @3790004 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3790012 b */
    goto L_3790076;
    L_3790016: ;
    /* @3790016 load */
    /* @3790024 cast */
    /* @3790028 load */
    /* @3790036 load */
    /* @3790044 cmp */
    /* @3790048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyzombie")), "x") < GM_READ(vm, -1, "x")))) goto L_3790076;
    /* @3790052 constant */
    /* @3790056 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3790064 constant */
    /* @3790068 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3790076: ;
    /* @3790076 constant */
    /* @3790080 constant */
    /* @3790084 constant */
    /* @3790088 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3790096 constant */
    /* @3790100 constant */
    /* @3790104 constant */
    /* @3790108 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3790116 constant */
    /* @3790120 constant */
    /* @3790124 constant */
    /* @3790128 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3790136 load */
    /* @3790144 constant */
    /* @3790148 cmp */
    /* @3790152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3790160;
    /* @3790156 b */
    goto L_3790216;
    L_3790160: ;
    /* @3790160 load */
    /* @3790168 constant */
    /* @3790172 cmp */
    /* @3790176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3790216;
    /* @3790180 constant */
    /* @3790184 cast */
    /* @3790188 constant */
    /* @3790192 cast */
    /* @3790196 constant */
    /* @3790200 cast */
    /* @3790204 call */
    GM_SITE(vm, 12, 3790204);
    /* @3790212 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3790216: ;
    /* @3790216 constant */
    /* @3790220 cast */
    /* @3790224 load */
    /* @3790232 load */
    /* @3790240 load */
    /* @3790248 add */
    /* @3790252 call */
    GM_SITE(vm, 12, 3790252);
    v133 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3790260 cast */
    /* @3790264 bf */
    v134 = BOOL(GM_CALL(vm, "place_meeting", 3, v133, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v134)) goto L_3790280;
    /* @3790268 constant */
    /* @3790272 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3790280: ;
    /* @3790280 b */
    goto L_3790464;
    L_3790284: ;
    /* @3790284 load */
    /* @3790292 constant */
    /* @3790296 cmp */
    /* @3790300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3790464;
    /* @3790304 load */
    /* @3790312 constant */
    /* @3790316 cmp */
    /* @3790320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyzombie") != VAL(-4)))) goto L_3790464;
    /* @3790324 load */
    /* @3790332 constant */
    /* @3790336 cmp */
    /* @3790340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3790464;
    /* @3790344 load */
    /* @3790352 constant */
    /* @3790356 cmp */
    /* @3790360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3790384;
    /* @3790364 load */
    /* @3790372 constant */
    /* @3790376 cmp */
    /* @3790380 b */
    p3790388_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3790388;
    L_3790384: ;
    /* @3790384 constant */
    p3790388_0 = VAL(0);
    L_3790388: ;
    /* @3790388 bf */
    if (!TRUTH(p3790388_0)) goto L_3790464;
    /* @3790392 constant */
    /* @3790396 cast */
    /* @3790400 call */
    GM_SITE(vm, 12, 3790400);
    /* @3790408 cast */
    /* @3790412 not */
    /* @3790416 bf */
    v135 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v135)) goto L_3790464;
    /* @3790420 constant */
    /* @3790424 cast */
    /* @3790428 load */
    /* @3790436 constant */
    /* @3790440 sub */
    /* @3790444 load */
    /* @3790452 call */
    GM_SITE(vm, 12, 3790452);
    /* @3790460 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3790464: ;
    /* @3790464 constant */
    /* @3790468 cast */
    /* @3790472 call */
    GM_SITE(vm, 12, 3790472);
    /* @3790480 cast */
    /* @3790484 bf */
    v136 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(18)));
    if (!TRUTH(v136)) goto L_3791800;
    /* @3790488 load */
    /* @3790496 constant */
    /* @3790500 cmp */
    /* @3790504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfirehulk") != VAL(-4)))) goto L_3791144;
    /* @3790508 load */
    /* @3790516 constant */
    /* @3790520 cmp */
    /* @3790524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3791144;
    /* @3790528 load */
    /* @3790536 constant */
    /* @3790540 cmp */
    /* @3790544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3790568;
    /* @3790548 load */
    /* @3790556 constant */
    /* @3790560 cmp */
    /* @3790564 b */
    p3790572_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3790572;
    L_3790568: ;
    /* @3790568 constant */
    p3790572_0 = VAL(0);
    L_3790572: ;
    /* @3790572 bf */
    if (!TRUTH(p3790572_0)) goto L_3791144;
    /* @3790576 load */
    /* @3790584 constant */
    /* @3790588 cmp */
    /* @3790592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3790964;
    /* @3790596 constant */
    /* @3790600 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3790608 load */
    /* @3790616 constant */
    /* @3790620 sub */
    /* @3790624 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3790632 load */
    /* @3790640 cast */
    /* @3790644 load */
    /* @3790652 load */
    /* @3790660 cmp */
    /* @3790664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfirehulk")), "x") > GM_READ(vm, -1, "x")))) goto L_3790696;
    /* @3790668 constant */
    /* @3790672 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3790680 constant */
    /* @3790684 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3790692 b */
    goto L_3790756;
    L_3790696: ;
    /* @3790696 load */
    /* @3790704 cast */
    /* @3790708 load */
    /* @3790716 load */
    /* @3790724 cmp */
    /* @3790728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfirehulk")), "x") < GM_READ(vm, -1, "x")))) goto L_3790756;
    /* @3790732 constant */
    /* @3790736 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3790744 constant */
    /* @3790748 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3790756: ;
    /* @3790756 constant */
    /* @3790760 constant */
    /* @3790764 constant */
    /* @3790768 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3790776 constant */
    /* @3790780 constant */
    /* @3790784 constant */
    /* @3790788 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3790796 constant */
    /* @3790800 constant */
    /* @3790804 constant */
    /* @3790808 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3790816 load */
    /* @3790824 constant */
    /* @3790828 cmp */
    /* @3790832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3790840;
    /* @3790836 b */
    goto L_3790896;
    L_3790840: ;
    /* @3790840 load */
    /* @3790848 constant */
    /* @3790852 cmp */
    /* @3790856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3790896;
    /* @3790860 constant */
    /* @3790864 cast */
    /* @3790868 constant */
    /* @3790872 cast */
    /* @3790876 constant */
    /* @3790880 cast */
    /* @3790884 call */
    GM_SITE(vm, 12, 3790884);
    /* @3790892 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3790896: ;
    /* @3790896 constant */
    /* @3790900 cast */
    /* @3790904 load */
    /* @3790912 load */
    /* @3790920 load */
    /* @3790928 add */
    /* @3790932 call */
    GM_SITE(vm, 12, 3790932);
    v137 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3790940 cast */
    /* @3790944 bf */
    v138 = BOOL(GM_CALL(vm, "place_meeting", 3, v137, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v138)) goto L_3790960;
    /* @3790948 constant */
    /* @3790952 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3790960: ;
    /* @3790960 b */
    goto L_3791144;
    L_3790964: ;
    /* @3790964 load */
    /* @3790972 constant */
    /* @3790976 cmp */
    /* @3790980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3791144;
    /* @3790984 load */
    /* @3790992 constant */
    /* @3790996 cmp */
    /* @3791000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfirehulk") != VAL(-4)))) goto L_3791144;
    /* @3791004 load */
    /* @3791012 constant */
    /* @3791016 cmp */
    /* @3791020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3791144;
    /* @3791024 load */
    /* @3791032 constant */
    /* @3791036 cmp */
    /* @3791040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3791064;
    /* @3791044 load */
    /* @3791052 constant */
    /* @3791056 cmp */
    /* @3791060 b */
    p3791068_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3791068;
    L_3791064: ;
    /* @3791064 constant */
    p3791068_0 = VAL(0);
    L_3791068: ;
    /* @3791068 bf */
    if (!TRUTH(p3791068_0)) goto L_3791144;
    /* @3791072 constant */
    /* @3791076 cast */
    /* @3791080 call */
    GM_SITE(vm, 12, 3791080);
    /* @3791088 cast */
    /* @3791092 not */
    /* @3791096 bf */
    v139 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v139)) goto L_3791144;
    /* @3791100 constant */
    /* @3791104 cast */
    /* @3791108 load */
    /* @3791116 constant */
    /* @3791120 sub */
    /* @3791124 load */
    /* @3791132 call */
    GM_SITE(vm, 12, 3791132);
    /* @3791140 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3791144: ;
    /* @3791144 load */
    /* @3791152 constant */
    /* @3791156 cmp */
    /* @3791160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfirehulk") != VAL(-4)))) goto L_3791800;
    /* @3791164 load */
    /* @3791172 constant */
    /* @3791176 cmp */
    /* @3791180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3791800;
    /* @3791184 load */
    /* @3791192 constant */
    /* @3791196 cmp */
    /* @3791200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3791224;
    /* @3791204 load */
    /* @3791212 constant */
    /* @3791216 cmp */
    /* @3791220 b */
    p3791228_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3791228;
    L_3791224: ;
    /* @3791224 constant */
    p3791228_0 = VAL(0);
    L_3791228: ;
    /* @3791228 bf */
    if (!TRUTH(p3791228_0)) goto L_3791800;
    /* @3791232 load */
    /* @3791240 constant */
    /* @3791244 cmp */
    /* @3791248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3791620;
    /* @3791252 constant */
    /* @3791256 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3791264 load */
    /* @3791272 constant */
    /* @3791276 sub */
    /* @3791280 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3791288 load */
    /* @3791296 cast */
    /* @3791300 load */
    /* @3791308 load */
    /* @3791316 cmp */
    /* @3791320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfirehulk")), "x") > GM_READ(vm, -1, "x")))) goto L_3791352;
    /* @3791324 constant */
    /* @3791328 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3791336 constant */
    /* @3791340 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3791348 b */
    goto L_3791412;
    L_3791352: ;
    /* @3791352 load */
    /* @3791360 cast */
    /* @3791364 load */
    /* @3791372 load */
    /* @3791380 cmp */
    /* @3791384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfirehulk")), "x") < GM_READ(vm, -1, "x")))) goto L_3791412;
    /* @3791388 constant */
    /* @3791392 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3791400 constant */
    /* @3791404 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3791412: ;
    /* @3791412 constant */
    /* @3791416 constant */
    /* @3791420 constant */
    /* @3791424 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3791432 constant */
    /* @3791436 constant */
    /* @3791440 constant */
    /* @3791444 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3791452 constant */
    /* @3791456 constant */
    /* @3791460 constant */
    /* @3791464 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3791472 load */
    /* @3791480 constant */
    /* @3791484 cmp */
    /* @3791488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3791496;
    /* @3791492 b */
    goto L_3791552;
    L_3791496: ;
    /* @3791496 load */
    /* @3791504 constant */
    /* @3791508 cmp */
    /* @3791512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3791552;
    /* @3791516 constant */
    /* @3791520 cast */
    /* @3791524 constant */
    /* @3791528 cast */
    /* @3791532 constant */
    /* @3791536 cast */
    /* @3791540 call */
    GM_SITE(vm, 12, 3791540);
    /* @3791548 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3791552: ;
    /* @3791552 constant */
    /* @3791556 cast */
    /* @3791560 load */
    /* @3791568 load */
    /* @3791576 load */
    /* @3791584 add */
    /* @3791588 call */
    GM_SITE(vm, 12, 3791588);
    v140 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3791596 cast */
    /* @3791600 bf */
    v141 = BOOL(GM_CALL(vm, "place_meeting", 3, v140, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v141)) goto L_3791616;
    /* @3791604 constant */
    /* @3791608 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3791616: ;
    /* @3791616 b */
    goto L_3791800;
    L_3791620: ;
    /* @3791620 load */
    /* @3791628 constant */
    /* @3791632 cmp */
    /* @3791636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3791800;
    /* @3791640 load */
    /* @3791648 constant */
    /* @3791652 cmp */
    /* @3791656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfirehulk") != VAL(-4)))) goto L_3791800;
    /* @3791660 load */
    /* @3791668 constant */
    /* @3791672 cmp */
    /* @3791676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3791800;
    /* @3791680 load */
    /* @3791688 constant */
    /* @3791692 cmp */
    /* @3791696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3791720;
    /* @3791700 load */
    /* @3791708 constant */
    /* @3791712 cmp */
    /* @3791716 b */
    p3791724_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3791724;
    L_3791720: ;
    /* @3791720 constant */
    p3791724_0 = VAL(0);
    L_3791724: ;
    /* @3791724 bf */
    if (!TRUTH(p3791724_0)) goto L_3791800;
    /* @3791728 constant */
    /* @3791732 cast */
    /* @3791736 call */
    GM_SITE(vm, 12, 3791736);
    /* @3791744 cast */
    /* @3791748 not */
    /* @3791752 bf */
    v142 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v142)) goto L_3791800;
    /* @3791756 constant */
    /* @3791760 cast */
    /* @3791764 load */
    /* @3791772 constant */
    /* @3791776 sub */
    /* @3791780 load */
    /* @3791788 call */
    GM_SITE(vm, 12, 3791788);
    /* @3791796 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3791800: ;
    /* @3791800 constant */
    /* @3791804 cast */
    /* @3791808 call */
    GM_SITE(vm, 12, 3791808);
    /* @3791816 cast */
    /* @3791820 bf */
    v143 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(17)));
    if (!TRUTH(v143)) goto L_3793136;
    /* @3791824 load */
    /* @3791832 constant */
    /* @3791836 cmp */
    /* @3791840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyskeleton") != VAL(-4)))) goto L_3792480;
    /* @3791844 load */
    /* @3791852 constant */
    /* @3791856 cmp */
    /* @3791860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3792480;
    /* @3791864 load */
    /* @3791872 constant */
    /* @3791876 cmp */
    /* @3791880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3791904;
    /* @3791884 load */
    /* @3791892 constant */
    /* @3791896 cmp */
    /* @3791900 b */
    p3791908_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3791908;
    L_3791904: ;
    /* @3791904 constant */
    p3791908_0 = VAL(0);
    L_3791908: ;
    /* @3791908 bf */
    if (!TRUTH(p3791908_0)) goto L_3792480;
    /* @3791912 load */
    /* @3791920 constant */
    /* @3791924 cmp */
    /* @3791928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3792300;
    /* @3791932 constant */
    /* @3791936 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3791944 load */
    /* @3791952 constant */
    /* @3791956 sub */
    /* @3791960 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3791968 load */
    /* @3791976 cast */
    /* @3791980 load */
    /* @3791988 load */
    /* @3791996 cmp */
    /* @3792000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyskeleton")), "x") > GM_READ(vm, -1, "x")))) goto L_3792032;
    /* @3792004 constant */
    /* @3792008 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3792016 constant */
    /* @3792020 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3792028 b */
    goto L_3792092;
    L_3792032: ;
    /* @3792032 load */
    /* @3792040 cast */
    /* @3792044 load */
    /* @3792052 load */
    /* @3792060 cmp */
    /* @3792064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyskeleton")), "x") < GM_READ(vm, -1, "x")))) goto L_3792092;
    /* @3792068 constant */
    /* @3792072 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3792080 constant */
    /* @3792084 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3792092: ;
    /* @3792092 constant */
    /* @3792096 constant */
    /* @3792100 constant */
    /* @3792104 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3792112 constant */
    /* @3792116 constant */
    /* @3792120 constant */
    /* @3792124 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3792132 constant */
    /* @3792136 constant */
    /* @3792140 constant */
    /* @3792144 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3792152 load */
    /* @3792160 constant */
    /* @3792164 cmp */
    /* @3792168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3792176;
    /* @3792172 b */
    goto L_3792232;
    L_3792176: ;
    /* @3792176 load */
    /* @3792184 constant */
    /* @3792188 cmp */
    /* @3792192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3792232;
    /* @3792196 constant */
    /* @3792200 cast */
    /* @3792204 constant */
    /* @3792208 cast */
    /* @3792212 constant */
    /* @3792216 cast */
    /* @3792220 call */
    GM_SITE(vm, 12, 3792220);
    /* @3792228 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3792232: ;
    /* @3792232 constant */
    /* @3792236 cast */
    /* @3792240 load */
    /* @3792248 load */
    /* @3792256 load */
    /* @3792264 add */
    /* @3792268 call */
    GM_SITE(vm, 12, 3792268);
    v144 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3792276 cast */
    /* @3792280 bf */
    v145 = BOOL(GM_CALL(vm, "place_meeting", 3, v144, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v145)) goto L_3792296;
    /* @3792284 constant */
    /* @3792288 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3792296: ;
    /* @3792296 b */
    goto L_3792480;
    L_3792300: ;
    /* @3792300 load */
    /* @3792308 constant */
    /* @3792312 cmp */
    /* @3792316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3792480;
    /* @3792320 load */
    /* @3792328 constant */
    /* @3792332 cmp */
    /* @3792336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyskeleton") != VAL(-4)))) goto L_3792480;
    /* @3792340 load */
    /* @3792348 constant */
    /* @3792352 cmp */
    /* @3792356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3792480;
    /* @3792360 load */
    /* @3792368 constant */
    /* @3792372 cmp */
    /* @3792376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3792400;
    /* @3792380 load */
    /* @3792388 constant */
    /* @3792392 cmp */
    /* @3792396 b */
    p3792404_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3792404;
    L_3792400: ;
    /* @3792400 constant */
    p3792404_0 = VAL(0);
    L_3792404: ;
    /* @3792404 bf */
    if (!TRUTH(p3792404_0)) goto L_3792480;
    /* @3792408 constant */
    /* @3792412 cast */
    /* @3792416 call */
    GM_SITE(vm, 12, 3792416);
    /* @3792424 cast */
    /* @3792428 not */
    /* @3792432 bf */
    v146 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v146)) goto L_3792480;
    /* @3792436 constant */
    /* @3792440 cast */
    /* @3792444 load */
    /* @3792452 constant */
    /* @3792456 sub */
    /* @3792460 load */
    /* @3792468 call */
    GM_SITE(vm, 12, 3792468);
    /* @3792476 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3792480: ;
    /* @3792480 load */
    /* @3792488 constant */
    /* @3792492 cmp */
    /* @3792496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyskeleton") != VAL(-4)))) goto L_3793136;
    /* @3792500 load */
    /* @3792508 constant */
    /* @3792512 cmp */
    /* @3792516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3793136;
    /* @3792520 load */
    /* @3792528 constant */
    /* @3792532 cmp */
    /* @3792536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3792560;
    /* @3792540 load */
    /* @3792548 constant */
    /* @3792552 cmp */
    /* @3792556 b */
    p3792564_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3792564;
    L_3792560: ;
    /* @3792560 constant */
    p3792564_0 = VAL(0);
    L_3792564: ;
    /* @3792564 bf */
    if (!TRUTH(p3792564_0)) goto L_3793136;
    /* @3792568 load */
    /* @3792576 constant */
    /* @3792580 cmp */
    /* @3792584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3792956;
    /* @3792588 constant */
    /* @3792592 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3792600 load */
    /* @3792608 constant */
    /* @3792612 sub */
    /* @3792616 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3792624 load */
    /* @3792632 cast */
    /* @3792636 load */
    /* @3792644 load */
    /* @3792652 cmp */
    /* @3792656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyskeleton")), "x") > GM_READ(vm, -1, "x")))) goto L_3792688;
    /* @3792660 constant */
    /* @3792664 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3792672 constant */
    /* @3792676 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3792684 b */
    goto L_3792748;
    L_3792688: ;
    /* @3792688 load */
    /* @3792696 cast */
    /* @3792700 load */
    /* @3792708 load */
    /* @3792716 cmp */
    /* @3792720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitenemyskeleton")), "x") < GM_READ(vm, -1, "x")))) goto L_3792748;
    /* @3792724 constant */
    /* @3792728 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3792736 constant */
    /* @3792740 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3792748: ;
    /* @3792748 constant */
    /* @3792752 constant */
    /* @3792756 constant */
    /* @3792760 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3792768 constant */
    /* @3792772 constant */
    /* @3792776 constant */
    /* @3792780 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3792788 constant */
    /* @3792792 constant */
    /* @3792796 constant */
    /* @3792800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3792808 load */
    /* @3792816 constant */
    /* @3792820 cmp */
    /* @3792824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3792832;
    /* @3792828 b */
    goto L_3792888;
    L_3792832: ;
    /* @3792832 load */
    /* @3792840 constant */
    /* @3792844 cmp */
    /* @3792848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3792888;
    /* @3792852 constant */
    /* @3792856 cast */
    /* @3792860 constant */
    /* @3792864 cast */
    /* @3792868 constant */
    /* @3792872 cast */
    /* @3792876 call */
    GM_SITE(vm, 12, 3792876);
    /* @3792884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3792888: ;
    /* @3792888 constant */
    /* @3792892 cast */
    /* @3792896 load */
    /* @3792904 load */
    /* @3792912 load */
    /* @3792920 add */
    /* @3792924 call */
    GM_SITE(vm, 12, 3792924);
    v147 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3792932 cast */
    /* @3792936 bf */
    v148 = BOOL(GM_CALL(vm, "place_meeting", 3, v147, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v148)) goto L_3792952;
    /* @3792940 constant */
    /* @3792944 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3792952: ;
    /* @3792952 b */
    goto L_3793136;
    L_3792956: ;
    /* @3792956 load */
    /* @3792964 constant */
    /* @3792968 cmp */
    /* @3792972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3793136;
    /* @3792976 load */
    /* @3792984 constant */
    /* @3792988 cmp */
    /* @3792992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitenemyskeleton") != VAL(-4)))) goto L_3793136;
    /* @3792996 load */
    /* @3793004 constant */
    /* @3793008 cmp */
    /* @3793012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3793136;
    /* @3793016 load */
    /* @3793024 constant */
    /* @3793028 cmp */
    /* @3793032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3793056;
    /* @3793036 load */
    /* @3793044 constant */
    /* @3793048 cmp */
    /* @3793052 b */
    p3793060_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3793060;
    L_3793056: ;
    /* @3793056 constant */
    p3793060_0 = VAL(0);
    L_3793060: ;
    /* @3793060 bf */
    if (!TRUTH(p3793060_0)) goto L_3793136;
    /* @3793064 constant */
    /* @3793068 cast */
    /* @3793072 call */
    GM_SITE(vm, 12, 3793072);
    /* @3793080 cast */
    /* @3793084 not */
    /* @3793088 bf */
    v149 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v149)) goto L_3793136;
    /* @3793092 constant */
    /* @3793096 cast */
    /* @3793100 load */
    /* @3793108 constant */
    /* @3793112 sub */
    /* @3793116 load */
    /* @3793124 call */
    GM_SITE(vm, 12, 3793124);
    /* @3793132 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3793136: ;
    /* @3793136 constant */
    /* @3793140 cast */
    /* @3793144 call */
    GM_SITE(vm, 12, 3793144);
    /* @3793152 cast */
    /* @3793156 bf */
    v150 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(26)));
    if (!TRUTH(v150)) goto L_3794472;
    /* @3793160 load */
    /* @3793168 constant */
    /* @3793172 cmp */
    /* @3793176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss2") != VAL(-4)))) goto L_3793816;
    /* @3793180 load */
    /* @3793188 constant */
    /* @3793192 cmp */
    /* @3793196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3793816;
    /* @3793200 load */
    /* @3793208 constant */
    /* @3793212 cmp */
    /* @3793216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3793240;
    /* @3793220 load */
    /* @3793228 constant */
    /* @3793232 cmp */
    /* @3793236 b */
    p3793244_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3793244;
    L_3793240: ;
    /* @3793240 constant */
    p3793244_0 = VAL(0);
    L_3793244: ;
    /* @3793244 bf */
    if (!TRUTH(p3793244_0)) goto L_3793816;
    /* @3793248 load */
    /* @3793256 constant */
    /* @3793260 cmp */
    /* @3793264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3793636;
    /* @3793268 constant */
    /* @3793272 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3793280 load */
    /* @3793288 constant */
    /* @3793292 sub */
    /* @3793296 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3793304 load */
    /* @3793312 cast */
    /* @3793316 load */
    /* @3793324 load */
    /* @3793332 cmp */
    /* @3793336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss2")), "x") > GM_READ(vm, -1, "x")))) goto L_3793368;
    /* @3793340 constant */
    /* @3793344 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3793352 constant */
    /* @3793356 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3793364 b */
    goto L_3793428;
    L_3793368: ;
    /* @3793368 load */
    /* @3793376 cast */
    /* @3793380 load */
    /* @3793388 load */
    /* @3793396 cmp */
    /* @3793400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss2")), "x") < GM_READ(vm, -1, "x")))) goto L_3793428;
    /* @3793404 constant */
    /* @3793408 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3793416 constant */
    /* @3793420 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3793428: ;
    /* @3793428 constant */
    /* @3793432 constant */
    /* @3793436 constant */
    /* @3793440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3793448 constant */
    /* @3793452 constant */
    /* @3793456 constant */
    /* @3793460 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3793468 constant */
    /* @3793472 constant */
    /* @3793476 constant */
    /* @3793480 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3793488 load */
    /* @3793496 constant */
    /* @3793500 cmp */
    /* @3793504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3793512;
    /* @3793508 b */
    goto L_3793568;
    L_3793512: ;
    /* @3793512 load */
    /* @3793520 constant */
    /* @3793524 cmp */
    /* @3793528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3793568;
    /* @3793532 constant */
    /* @3793536 cast */
    /* @3793540 constant */
    /* @3793544 cast */
    /* @3793548 constant */
    /* @3793552 cast */
    /* @3793556 call */
    GM_SITE(vm, 12, 3793556);
    /* @3793564 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3793568: ;
    /* @3793568 constant */
    /* @3793572 cast */
    /* @3793576 load */
    /* @3793584 load */
    /* @3793592 load */
    /* @3793600 add */
    /* @3793604 call */
    GM_SITE(vm, 12, 3793604);
    v151 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3793612 cast */
    /* @3793616 bf */
    v152 = BOOL(GM_CALL(vm, "place_meeting", 3, v151, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v152)) goto L_3793632;
    /* @3793620 constant */
    /* @3793624 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3793632: ;
    /* @3793632 b */
    goto L_3793816;
    L_3793636: ;
    /* @3793636 load */
    /* @3793644 constant */
    /* @3793648 cmp */
    /* @3793652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3793816;
    /* @3793656 load */
    /* @3793664 constant */
    /* @3793668 cmp */
    /* @3793672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss2") != VAL(-4)))) goto L_3793816;
    /* @3793676 load */
    /* @3793684 constant */
    /* @3793688 cmp */
    /* @3793692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3793816;
    /* @3793696 load */
    /* @3793704 constant */
    /* @3793708 cmp */
    /* @3793712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3793736;
    /* @3793716 load */
    /* @3793724 constant */
    /* @3793728 cmp */
    /* @3793732 b */
    p3793740_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3793740;
    L_3793736: ;
    /* @3793736 constant */
    p3793740_0 = VAL(0);
    L_3793740: ;
    /* @3793740 bf */
    if (!TRUTH(p3793740_0)) goto L_3793816;
    /* @3793744 constant */
    /* @3793748 cast */
    /* @3793752 call */
    GM_SITE(vm, 12, 3793752);
    /* @3793760 cast */
    /* @3793764 not */
    /* @3793768 bf */
    v153 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v153)) goto L_3793816;
    /* @3793772 constant */
    /* @3793776 cast */
    /* @3793780 load */
    /* @3793788 constant */
    /* @3793792 sub */
    /* @3793796 load */
    /* @3793804 call */
    GM_SITE(vm, 12, 3793804);
    /* @3793812 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3793816: ;
    /* @3793816 load */
    /* @3793824 constant */
    /* @3793828 cmp */
    /* @3793832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss2") != VAL(-4)))) goto L_3794472;
    /* @3793836 load */
    /* @3793844 constant */
    /* @3793848 cmp */
    /* @3793852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3794472;
    /* @3793856 load */
    /* @3793864 constant */
    /* @3793868 cmp */
    /* @3793872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3793896;
    /* @3793876 load */
    /* @3793884 constant */
    /* @3793888 cmp */
    /* @3793892 b */
    p3793900_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3793900;
    L_3793896: ;
    /* @3793896 constant */
    p3793900_0 = VAL(0);
    L_3793900: ;
    /* @3793900 bf */
    if (!TRUTH(p3793900_0)) goto L_3794472;
    /* @3793904 load */
    /* @3793912 constant */
    /* @3793916 cmp */
    /* @3793920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3794292;
    /* @3793924 constant */
    /* @3793928 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3793936 load */
    /* @3793944 constant */
    /* @3793948 sub */
    /* @3793952 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3793960 load */
    /* @3793968 cast */
    /* @3793972 load */
    /* @3793980 load */
    /* @3793988 cmp */
    /* @3793992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss2")), "x") > GM_READ(vm, -1, "x")))) goto L_3794024;
    /* @3793996 constant */
    /* @3794000 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3794008 constant */
    /* @3794012 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3794020 b */
    goto L_3794084;
    L_3794024: ;
    /* @3794024 load */
    /* @3794032 cast */
    /* @3794036 load */
    /* @3794044 load */
    /* @3794052 cmp */
    /* @3794056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss2")), "x") < GM_READ(vm, -1, "x")))) goto L_3794084;
    /* @3794060 constant */
    /* @3794064 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3794072 constant */
    /* @3794076 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3794084: ;
    /* @3794084 constant */
    /* @3794088 constant */
    /* @3794092 constant */
    /* @3794096 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3794104 constant */
    /* @3794108 constant */
    /* @3794112 constant */
    /* @3794116 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3794124 constant */
    /* @3794128 constant */
    /* @3794132 constant */
    /* @3794136 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3794144 load */
    /* @3794152 constant */
    /* @3794156 cmp */
    /* @3794160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3794168;
    /* @3794164 b */
    goto L_3794224;
    L_3794168: ;
    /* @3794168 load */
    /* @3794176 constant */
    /* @3794180 cmp */
    /* @3794184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3794224;
    /* @3794188 constant */
    /* @3794192 cast */
    /* @3794196 constant */
    /* @3794200 cast */
    /* @3794204 constant */
    /* @3794208 cast */
    /* @3794212 call */
    GM_SITE(vm, 12, 3794212);
    /* @3794220 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3794224: ;
    /* @3794224 constant */
    /* @3794228 cast */
    /* @3794232 load */
    /* @3794240 load */
    /* @3794248 load */
    /* @3794256 add */
    /* @3794260 call */
    GM_SITE(vm, 12, 3794260);
    v154 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3794268 cast */
    /* @3794272 bf */
    v155 = BOOL(GM_CALL(vm, "place_meeting", 3, v154, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v155)) goto L_3794288;
    /* @3794276 constant */
    /* @3794280 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3794288: ;
    /* @3794288 b */
    goto L_3794472;
    L_3794292: ;
    /* @3794292 load */
    /* @3794300 constant */
    /* @3794304 cmp */
    /* @3794308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3794472;
    /* @3794312 load */
    /* @3794320 constant */
    /* @3794324 cmp */
    /* @3794328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss2") != VAL(-4)))) goto L_3794472;
    /* @3794332 load */
    /* @3794340 constant */
    /* @3794344 cmp */
    /* @3794348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3794472;
    /* @3794352 load */
    /* @3794360 constant */
    /* @3794364 cmp */
    /* @3794368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3794392;
    /* @3794372 load */
    /* @3794380 constant */
    /* @3794384 cmp */
    /* @3794388 b */
    p3794396_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3794396;
    L_3794392: ;
    /* @3794392 constant */
    p3794396_0 = VAL(0);
    L_3794396: ;
    /* @3794396 bf */
    if (!TRUTH(p3794396_0)) goto L_3794472;
    /* @3794400 constant */
    /* @3794404 cast */
    /* @3794408 call */
    GM_SITE(vm, 12, 3794408);
    /* @3794416 cast */
    /* @3794420 not */
    /* @3794424 bf */
    v156 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v156)) goto L_3794472;
    /* @3794428 constant */
    /* @3794432 cast */
    /* @3794436 load */
    /* @3794444 constant */
    /* @3794448 sub */
    /* @3794452 load */
    /* @3794460 call */
    GM_SITE(vm, 12, 3794460);
    /* @3794468 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3794472: ;
    /* @3794472 constant */
    /* @3794476 cast */
    /* @3794480 call */
    GM_SITE(vm, 12, 3794480);
    /* @3794488 cast */
    /* @3794492 bf */
    v157 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(27)));
    if (!TRUTH(v157)) goto L_3795808;
    /* @3794496 load */
    /* @3794504 constant */
    /* @3794508 cmp */
    /* @3794512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss3") != VAL(-4)))) goto L_3795152;
    /* @3794516 load */
    /* @3794524 constant */
    /* @3794528 cmp */
    /* @3794532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3795152;
    /* @3794536 load */
    /* @3794544 constant */
    /* @3794548 cmp */
    /* @3794552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3794576;
    /* @3794556 load */
    /* @3794564 constant */
    /* @3794568 cmp */
    /* @3794572 b */
    p3794580_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3794580;
    L_3794576: ;
    /* @3794576 constant */
    p3794580_0 = VAL(0);
    L_3794580: ;
    /* @3794580 bf */
    if (!TRUTH(p3794580_0)) goto L_3795152;
    /* @3794584 load */
    /* @3794592 constant */
    /* @3794596 cmp */
    /* @3794600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3794972;
    /* @3794604 constant */
    /* @3794608 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3794616 load */
    /* @3794624 constant */
    /* @3794628 sub */
    /* @3794632 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3794640 load */
    /* @3794648 cast */
    /* @3794652 load */
    /* @3794660 load */
    /* @3794668 cmp */
    /* @3794672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss3")), "x") > GM_READ(vm, -1, "x")))) goto L_3794704;
    /* @3794676 constant */
    /* @3794680 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3794688 constant */
    /* @3794692 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3794700 b */
    goto L_3794764;
    L_3794704: ;
    /* @3794704 load */
    /* @3794712 cast */
    /* @3794716 load */
    /* @3794724 load */
    /* @3794732 cmp */
    /* @3794736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss3")), "x") < GM_READ(vm, -1, "x")))) goto L_3794764;
    /* @3794740 constant */
    /* @3794744 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3794752 constant */
    /* @3794756 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3794764: ;
    /* @3794764 constant */
    /* @3794768 constant */
    /* @3794772 constant */
    /* @3794776 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3794784 constant */
    /* @3794788 constant */
    /* @3794792 constant */
    /* @3794796 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3794804 constant */
    /* @3794808 constant */
    /* @3794812 constant */
    /* @3794816 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3794824 load */
    /* @3794832 constant */
    /* @3794836 cmp */
    /* @3794840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3794848;
    /* @3794844 b */
    goto L_3794904;
    L_3794848: ;
    /* @3794848 load */
    /* @3794856 constant */
    /* @3794860 cmp */
    /* @3794864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3794904;
    /* @3794868 constant */
    /* @3794872 cast */
    /* @3794876 constant */
    /* @3794880 cast */
    /* @3794884 constant */
    /* @3794888 cast */
    /* @3794892 call */
    GM_SITE(vm, 12, 3794892);
    /* @3794900 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3794904: ;
    /* @3794904 constant */
    /* @3794908 cast */
    /* @3794912 load */
    /* @3794920 load */
    /* @3794928 load */
    /* @3794936 add */
    /* @3794940 call */
    GM_SITE(vm, 12, 3794940);
    v158 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3794948 cast */
    /* @3794952 bf */
    v159 = BOOL(GM_CALL(vm, "place_meeting", 3, v158, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v159)) goto L_3794968;
    /* @3794956 constant */
    /* @3794960 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3794968: ;
    /* @3794968 b */
    goto L_3795152;
    L_3794972: ;
    /* @3794972 load */
    /* @3794980 constant */
    /* @3794984 cmp */
    /* @3794988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3795152;
    /* @3794992 load */
    /* @3795000 constant */
    /* @3795004 cmp */
    /* @3795008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss3") != VAL(-4)))) goto L_3795152;
    /* @3795012 load */
    /* @3795020 constant */
    /* @3795024 cmp */
    /* @3795028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3795152;
    /* @3795032 load */
    /* @3795040 constant */
    /* @3795044 cmp */
    /* @3795048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3795072;
    /* @3795052 load */
    /* @3795060 constant */
    /* @3795064 cmp */
    /* @3795068 b */
    p3795076_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3795076;
    L_3795072: ;
    /* @3795072 constant */
    p3795076_0 = VAL(0);
    L_3795076: ;
    /* @3795076 bf */
    if (!TRUTH(p3795076_0)) goto L_3795152;
    /* @3795080 constant */
    /* @3795084 cast */
    /* @3795088 call */
    GM_SITE(vm, 12, 3795088);
    /* @3795096 cast */
    /* @3795100 not */
    /* @3795104 bf */
    v160 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v160)) goto L_3795152;
    /* @3795108 constant */
    /* @3795112 cast */
    /* @3795116 load */
    /* @3795124 constant */
    /* @3795128 sub */
    /* @3795132 load */
    /* @3795140 call */
    GM_SITE(vm, 12, 3795140);
    /* @3795148 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3795152: ;
    /* @3795152 load */
    /* @3795160 constant */
    /* @3795164 cmp */
    /* @3795168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss3") != VAL(-4)))) goto L_3795808;
    /* @3795172 load */
    /* @3795180 constant */
    /* @3795184 cmp */
    /* @3795188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3795808;
    /* @3795192 load */
    /* @3795200 constant */
    /* @3795204 cmp */
    /* @3795208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3795232;
    /* @3795212 load */
    /* @3795220 constant */
    /* @3795224 cmp */
    /* @3795228 b */
    p3795236_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3795236;
    L_3795232: ;
    /* @3795232 constant */
    p3795236_0 = VAL(0);
    L_3795236: ;
    /* @3795236 bf */
    if (!TRUTH(p3795236_0)) goto L_3795808;
    /* @3795240 load */
    /* @3795248 constant */
    /* @3795252 cmp */
    /* @3795256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3795628;
    /* @3795260 constant */
    /* @3795264 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3795272 load */
    /* @3795280 constant */
    /* @3795284 sub */
    /* @3795288 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3795296 load */
    /* @3795304 cast */
    /* @3795308 load */
    /* @3795316 load */
    /* @3795324 cmp */
    /* @3795328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss3")), "x") > GM_READ(vm, -1, "x")))) goto L_3795360;
    /* @3795332 constant */
    /* @3795336 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3795344 constant */
    /* @3795348 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3795356 b */
    goto L_3795420;
    L_3795360: ;
    /* @3795360 load */
    /* @3795368 cast */
    /* @3795372 load */
    /* @3795380 load */
    /* @3795388 cmp */
    /* @3795392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss3")), "x") < GM_READ(vm, -1, "x")))) goto L_3795420;
    /* @3795396 constant */
    /* @3795400 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3795408 constant */
    /* @3795412 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3795420: ;
    /* @3795420 constant */
    /* @3795424 constant */
    /* @3795428 constant */
    /* @3795432 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3795440 constant */
    /* @3795444 constant */
    /* @3795448 constant */
    /* @3795452 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3795460 constant */
    /* @3795464 constant */
    /* @3795468 constant */
    /* @3795472 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3795480 load */
    /* @3795488 constant */
    /* @3795492 cmp */
    /* @3795496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3795504;
    /* @3795500 b */
    goto L_3795560;
    L_3795504: ;
    /* @3795504 load */
    /* @3795512 constant */
    /* @3795516 cmp */
    /* @3795520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3795560;
    /* @3795524 constant */
    /* @3795528 cast */
    /* @3795532 constant */
    /* @3795536 cast */
    /* @3795540 constant */
    /* @3795544 cast */
    /* @3795548 call */
    GM_SITE(vm, 12, 3795548);
    /* @3795556 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3795560: ;
    /* @3795560 constant */
    /* @3795564 cast */
    /* @3795568 load */
    /* @3795576 load */
    /* @3795584 load */
    /* @3795592 add */
    /* @3795596 call */
    GM_SITE(vm, 12, 3795596);
    v161 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3795604 cast */
    /* @3795608 bf */
    v162 = BOOL(GM_CALL(vm, "place_meeting", 3, v161, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v162)) goto L_3795624;
    /* @3795612 constant */
    /* @3795616 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3795624: ;
    /* @3795624 b */
    goto L_3795808;
    L_3795628: ;
    /* @3795628 load */
    /* @3795636 constant */
    /* @3795640 cmp */
    /* @3795644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3795808;
    /* @3795648 load */
    /* @3795656 constant */
    /* @3795660 cmp */
    /* @3795664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss3") != VAL(-4)))) goto L_3795808;
    /* @3795668 load */
    /* @3795676 constant */
    /* @3795680 cmp */
    /* @3795684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3795808;
    /* @3795688 load */
    /* @3795696 constant */
    /* @3795700 cmp */
    /* @3795704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3795728;
    /* @3795708 load */
    /* @3795716 constant */
    /* @3795720 cmp */
    /* @3795724 b */
    p3795732_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3795732;
    L_3795728: ;
    /* @3795728 constant */
    p3795732_0 = VAL(0);
    L_3795732: ;
    /* @3795732 bf */
    if (!TRUTH(p3795732_0)) goto L_3795808;
    /* @3795736 constant */
    /* @3795740 cast */
    /* @3795744 call */
    GM_SITE(vm, 12, 3795744);
    /* @3795752 cast */
    /* @3795756 not */
    /* @3795760 bf */
    v163 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v163)) goto L_3795808;
    /* @3795764 constant */
    /* @3795768 cast */
    /* @3795772 load */
    /* @3795780 constant */
    /* @3795784 sub */
    /* @3795788 load */
    /* @3795796 call */
    GM_SITE(vm, 12, 3795796);
    /* @3795804 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3795808: ;
    /* @3795808 constant */
    /* @3795812 cast */
    /* @3795816 call */
    GM_SITE(vm, 12, 3795816);
    /* @3795824 cast */
    /* @3795828 bf */
    v164 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(28)));
    if (!TRUTH(v164)) goto L_3797144;
    /* @3795832 load */
    /* @3795840 constant */
    /* @3795844 cmp */
    /* @3795848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_3796488;
    /* @3795852 load */
    /* @3795860 constant */
    /* @3795864 cmp */
    /* @3795868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3796488;
    /* @3795872 load */
    /* @3795880 constant */
    /* @3795884 cmp */
    /* @3795888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3795912;
    /* @3795892 load */
    /* @3795900 constant */
    /* @3795904 cmp */
    /* @3795908 b */
    p3795916_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3795916;
    L_3795912: ;
    /* @3795912 constant */
    p3795916_0 = VAL(0);
    L_3795916: ;
    /* @3795916 bf */
    if (!TRUTH(p3795916_0)) goto L_3796488;
    /* @3795920 load */
    /* @3795928 constant */
    /* @3795932 cmp */
    /* @3795936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3796308;
    /* @3795940 constant */
    /* @3795944 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3795952 load */
    /* @3795960 constant */
    /* @3795964 sub */
    /* @3795968 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3795976 load */
    /* @3795984 cast */
    /* @3795988 load */
    /* @3795996 load */
    /* @3796004 cmp */
    /* @3796008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x") > GM_READ(vm, -1, "x")))) goto L_3796040;
    /* @3796012 constant */
    /* @3796016 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3796024 constant */
    /* @3796028 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3796036 b */
    goto L_3796100;
    L_3796040: ;
    /* @3796040 load */
    /* @3796048 cast */
    /* @3796052 load */
    /* @3796060 load */
    /* @3796068 cmp */
    /* @3796072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x") < GM_READ(vm, -1, "x")))) goto L_3796100;
    /* @3796076 constant */
    /* @3796080 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3796088 constant */
    /* @3796092 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3796100: ;
    /* @3796100 constant */
    /* @3796104 constant */
    /* @3796108 constant */
    /* @3796112 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3796120 constant */
    /* @3796124 constant */
    /* @3796128 constant */
    /* @3796132 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3796140 constant */
    /* @3796144 constant */
    /* @3796148 constant */
    /* @3796152 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3796160 load */
    /* @3796168 constant */
    /* @3796172 cmp */
    /* @3796176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3796184;
    /* @3796180 b */
    goto L_3796240;
    L_3796184: ;
    /* @3796184 load */
    /* @3796192 constant */
    /* @3796196 cmp */
    /* @3796200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3796240;
    /* @3796204 constant */
    /* @3796208 cast */
    /* @3796212 constant */
    /* @3796216 cast */
    /* @3796220 constant */
    /* @3796224 cast */
    /* @3796228 call */
    GM_SITE(vm, 12, 3796228);
    /* @3796236 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3796240: ;
    /* @3796240 constant */
    /* @3796244 cast */
    /* @3796248 load */
    /* @3796256 load */
    /* @3796264 load */
    /* @3796272 add */
    /* @3796276 call */
    GM_SITE(vm, 12, 3796276);
    v165 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3796284 cast */
    /* @3796288 bf */
    v166 = BOOL(GM_CALL(vm, "place_meeting", 3, v165, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v166)) goto L_3796304;
    /* @3796292 constant */
    /* @3796296 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3796304: ;
    /* @3796304 b */
    goto L_3796488;
    L_3796308: ;
    /* @3796308 load */
    /* @3796316 constant */
    /* @3796320 cmp */
    /* @3796324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3796488;
    /* @3796328 load */
    /* @3796336 constant */
    /* @3796340 cmp */
    /* @3796344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_3796488;
    /* @3796348 load */
    /* @3796356 constant */
    /* @3796360 cmp */
    /* @3796364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3796488;
    /* @3796368 load */
    /* @3796376 constant */
    /* @3796380 cmp */
    /* @3796384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3796408;
    /* @3796388 load */
    /* @3796396 constant */
    /* @3796400 cmp */
    /* @3796404 b */
    p3796412_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3796412;
    L_3796408: ;
    /* @3796408 constant */
    p3796412_0 = VAL(0);
    L_3796412: ;
    /* @3796412 bf */
    if (!TRUTH(p3796412_0)) goto L_3796488;
    /* @3796416 constant */
    /* @3796420 cast */
    /* @3796424 call */
    GM_SITE(vm, 12, 3796424);
    /* @3796432 cast */
    /* @3796436 not */
    /* @3796440 bf */
    v167 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v167)) goto L_3796488;
    /* @3796444 constant */
    /* @3796448 cast */
    /* @3796452 load */
    /* @3796460 constant */
    /* @3796464 sub */
    /* @3796468 load */
    /* @3796476 call */
    GM_SITE(vm, 12, 3796476);
    /* @3796484 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3796488: ;
    /* @3796488 load */
    /* @3796496 constant */
    /* @3796500 cmp */
    /* @3796504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_3797144;
    /* @3796508 load */
    /* @3796516 constant */
    /* @3796520 cmp */
    /* @3796524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3797144;
    /* @3796528 load */
    /* @3796536 constant */
    /* @3796540 cmp */
    /* @3796544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3796568;
    /* @3796548 load */
    /* @3796556 constant */
    /* @3796560 cmp */
    /* @3796564 b */
    p3796572_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3796572;
    L_3796568: ;
    /* @3796568 constant */
    p3796572_0 = VAL(0);
    L_3796572: ;
    /* @3796572 bf */
    if (!TRUTH(p3796572_0)) goto L_3797144;
    /* @3796576 load */
    /* @3796584 constant */
    /* @3796588 cmp */
    /* @3796592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3796964;
    /* @3796596 constant */
    /* @3796600 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3796608 load */
    /* @3796616 constant */
    /* @3796620 sub */
    /* @3796624 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3796632 load */
    /* @3796640 cast */
    /* @3796644 load */
    /* @3796652 load */
    /* @3796660 cmp */
    /* @3796664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x") > GM_READ(vm, -1, "x")))) goto L_3796696;
    /* @3796668 constant */
    /* @3796672 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3796680 constant */
    /* @3796684 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3796692 b */
    goto L_3796756;
    L_3796696: ;
    /* @3796696 load */
    /* @3796704 cast */
    /* @3796708 load */
    /* @3796716 load */
    /* @3796724 cmp */
    /* @3796728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "x") < GM_READ(vm, -1, "x")))) goto L_3796756;
    /* @3796732 constant */
    /* @3796736 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3796744 constant */
    /* @3796748 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3796756: ;
    /* @3796756 constant */
    /* @3796760 constant */
    /* @3796764 constant */
    /* @3796768 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3796776 constant */
    /* @3796780 constant */
    /* @3796784 constant */
    /* @3796788 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3796796 constant */
    /* @3796800 constant */
    /* @3796804 constant */
    /* @3796808 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3796816 load */
    /* @3796824 constant */
    /* @3796828 cmp */
    /* @3796832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3796840;
    /* @3796836 b */
    goto L_3796896;
    L_3796840: ;
    /* @3796840 load */
    /* @3796848 constant */
    /* @3796852 cmp */
    /* @3796856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3796896;
    /* @3796860 constant */
    /* @3796864 cast */
    /* @3796868 constant */
    /* @3796872 cast */
    /* @3796876 constant */
    /* @3796880 cast */
    /* @3796884 call */
    GM_SITE(vm, 12, 3796884);
    /* @3796892 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3796896: ;
    /* @3796896 constant */
    /* @3796900 cast */
    /* @3796904 load */
    /* @3796912 load */
    /* @3796920 load */
    /* @3796928 add */
    /* @3796932 call */
    GM_SITE(vm, 12, 3796932);
    v168 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3796940 cast */
    /* @3796944 bf */
    v169 = BOOL(GM_CALL(vm, "place_meeting", 3, v168, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v169)) goto L_3796960;
    /* @3796948 constant */
    /* @3796952 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3796960: ;
    /* @3796960 b */
    goto L_3797144;
    L_3796964: ;
    /* @3796964 load */
    /* @3796972 constant */
    /* @3796976 cmp */
    /* @3796980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3797144;
    /* @3796984 load */
    /* @3796992 constant */
    /* @3796996 cmp */
    /* @3797000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_3797144;
    /* @3797004 load */
    /* @3797012 constant */
    /* @3797016 cmp */
    /* @3797020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3797144;
    /* @3797024 load */
    /* @3797032 constant */
    /* @3797036 cmp */
    /* @3797040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3797064;
    /* @3797044 load */
    /* @3797052 constant */
    /* @3797056 cmp */
    /* @3797060 b */
    p3797068_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3797068;
    L_3797064: ;
    /* @3797064 constant */
    p3797068_0 = VAL(0);
    L_3797068: ;
    /* @3797068 bf */
    if (!TRUTH(p3797068_0)) goto L_3797144;
    /* @3797072 constant */
    /* @3797076 cast */
    /* @3797080 call */
    GM_SITE(vm, 12, 3797080);
    /* @3797088 cast */
    /* @3797092 not */
    /* @3797096 bf */
    v170 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v170)) goto L_3797144;
    /* @3797100 constant */
    /* @3797104 cast */
    /* @3797108 load */
    /* @3797116 constant */
    /* @3797120 sub */
    /* @3797124 load */
    /* @3797132 call */
    GM_SITE(vm, 12, 3797132);
    /* @3797140 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3797144: ;
    /* @3797144 constant */
    /* @3797148 cast */
    /* @3797152 call */
    GM_SITE(vm, 12, 3797152);
    /* @3797160 cast */
    /* @3797164 bf */
    v171 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(29)));
    if (!TRUTH(v171)) goto L_3798480;
    /* @3797168 load */
    /* @3797176 constant */
    /* @3797180 cmp */
    /* @3797184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_3797824;
    /* @3797188 load */
    /* @3797196 constant */
    /* @3797200 cmp */
    /* @3797204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3797824;
    /* @3797208 load */
    /* @3797216 constant */
    /* @3797220 cmp */
    /* @3797224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3797248;
    /* @3797228 load */
    /* @3797236 constant */
    /* @3797240 cmp */
    /* @3797244 b */
    p3797252_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3797252;
    L_3797248: ;
    /* @3797248 constant */
    p3797252_0 = VAL(0);
    L_3797252: ;
    /* @3797252 bf */
    if (!TRUTH(p3797252_0)) goto L_3797824;
    /* @3797256 load */
    /* @3797264 constant */
    /* @3797268 cmp */
    /* @3797272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3797644;
    /* @3797276 constant */
    /* @3797280 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3797288 load */
    /* @3797296 constant */
    /* @3797300 sub */
    /* @3797304 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3797312 load */
    /* @3797320 cast */
    /* @3797324 load */
    /* @3797332 load */
    /* @3797340 cmp */
    /* @3797344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x") > GM_READ(vm, -1, "x")))) goto L_3797376;
    /* @3797348 constant */
    /* @3797352 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3797360 constant */
    /* @3797364 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3797372 b */
    goto L_3797436;
    L_3797376: ;
    /* @3797376 load */
    /* @3797384 cast */
    /* @3797388 load */
    /* @3797396 load */
    /* @3797404 cmp */
    /* @3797408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x") < GM_READ(vm, -1, "x")))) goto L_3797436;
    /* @3797412 constant */
    /* @3797416 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3797424 constant */
    /* @3797428 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3797436: ;
    /* @3797436 constant */
    /* @3797440 constant */
    /* @3797444 constant */
    /* @3797448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3797456 constant */
    /* @3797460 constant */
    /* @3797464 constant */
    /* @3797468 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3797476 constant */
    /* @3797480 constant */
    /* @3797484 constant */
    /* @3797488 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3797496 load */
    /* @3797504 constant */
    /* @3797508 cmp */
    /* @3797512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3797520;
    /* @3797516 b */
    goto L_3797576;
    L_3797520: ;
    /* @3797520 load */
    /* @3797528 constant */
    /* @3797532 cmp */
    /* @3797536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3797576;
    /* @3797540 constant */
    /* @3797544 cast */
    /* @3797548 constant */
    /* @3797552 cast */
    /* @3797556 constant */
    /* @3797560 cast */
    /* @3797564 call */
    GM_SITE(vm, 12, 3797564);
    /* @3797572 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3797576: ;
    /* @3797576 constant */
    /* @3797580 cast */
    /* @3797584 load */
    /* @3797592 load */
    /* @3797600 load */
    /* @3797608 add */
    /* @3797612 call */
    GM_SITE(vm, 12, 3797612);
    v172 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3797620 cast */
    /* @3797624 bf */
    v173 = BOOL(GM_CALL(vm, "place_meeting", 3, v172, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v173)) goto L_3797640;
    /* @3797628 constant */
    /* @3797632 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3797640: ;
    /* @3797640 b */
    goto L_3797824;
    L_3797644: ;
    /* @3797644 load */
    /* @3797652 constant */
    /* @3797656 cmp */
    /* @3797660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3797824;
    /* @3797664 load */
    /* @3797672 constant */
    /* @3797676 cmp */
    /* @3797680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_3797824;
    /* @3797684 load */
    /* @3797692 constant */
    /* @3797696 cmp */
    /* @3797700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3797824;
    /* @3797704 load */
    /* @3797712 constant */
    /* @3797716 cmp */
    /* @3797720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3797744;
    /* @3797724 load */
    /* @3797732 constant */
    /* @3797736 cmp */
    /* @3797740 b */
    p3797748_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3797748;
    L_3797744: ;
    /* @3797744 constant */
    p3797748_0 = VAL(0);
    L_3797748: ;
    /* @3797748 bf */
    if (!TRUTH(p3797748_0)) goto L_3797824;
    /* @3797752 constant */
    /* @3797756 cast */
    /* @3797760 call */
    GM_SITE(vm, 12, 3797760);
    /* @3797768 cast */
    /* @3797772 not */
    /* @3797776 bf */
    v174 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v174)) goto L_3797824;
    /* @3797780 constant */
    /* @3797784 cast */
    /* @3797788 load */
    /* @3797796 constant */
    /* @3797800 sub */
    /* @3797804 load */
    /* @3797812 call */
    GM_SITE(vm, 12, 3797812);
    /* @3797820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3797824: ;
    /* @3797824 load */
    /* @3797832 constant */
    /* @3797836 cmp */
    /* @3797840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_3798480;
    /* @3797844 load */
    /* @3797852 constant */
    /* @3797856 cmp */
    /* @3797860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3798480;
    /* @3797864 load */
    /* @3797872 constant */
    /* @3797876 cmp */
    /* @3797880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3797904;
    /* @3797884 load */
    /* @3797892 constant */
    /* @3797896 cmp */
    /* @3797900 b */
    p3797908_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3797908;
    L_3797904: ;
    /* @3797904 constant */
    p3797908_0 = VAL(0);
    L_3797908: ;
    /* @3797908 bf */
    if (!TRUTH(p3797908_0)) goto L_3798480;
    /* @3797912 load */
    /* @3797920 constant */
    /* @3797924 cmp */
    /* @3797928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3798300;
    /* @3797932 constant */
    /* @3797936 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3797944 load */
    /* @3797952 constant */
    /* @3797956 sub */
    /* @3797960 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3797968 load */
    /* @3797976 cast */
    /* @3797980 load */
    /* @3797988 load */
    /* @3797996 cmp */
    /* @3798000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x") > GM_READ(vm, -1, "x")))) goto L_3798032;
    /* @3798004 constant */
    /* @3798008 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3798016 constant */
    /* @3798020 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3798028 b */
    goto L_3798092;
    L_3798032: ;
    /* @3798032 load */
    /* @3798040 cast */
    /* @3798044 load */
    /* @3798052 load */
    /* @3798060 cmp */
    /* @3798064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "x") < GM_READ(vm, -1, "x")))) goto L_3798092;
    /* @3798068 constant */
    /* @3798072 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3798080 constant */
    /* @3798084 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3798092: ;
    /* @3798092 constant */
    /* @3798096 constant */
    /* @3798100 constant */
    /* @3798104 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3798112 constant */
    /* @3798116 constant */
    /* @3798120 constant */
    /* @3798124 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3798132 constant */
    /* @3798136 constant */
    /* @3798140 constant */
    /* @3798144 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3798152 load */
    /* @3798160 constant */
    /* @3798164 cmp */
    /* @3798168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3798176;
    /* @3798172 b */
    goto L_3798232;
    L_3798176: ;
    /* @3798176 load */
    /* @3798184 constant */
    /* @3798188 cmp */
    /* @3798192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3798232;
    /* @3798196 constant */
    /* @3798200 cast */
    /* @3798204 constant */
    /* @3798208 cast */
    /* @3798212 constant */
    /* @3798216 cast */
    /* @3798220 call */
    GM_SITE(vm, 12, 3798220);
    /* @3798228 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3798232: ;
    /* @3798232 constant */
    /* @3798236 cast */
    /* @3798240 load */
    /* @3798248 load */
    /* @3798256 load */
    /* @3798264 add */
    /* @3798268 call */
    GM_SITE(vm, 12, 3798268);
    v175 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3798276 cast */
    /* @3798280 bf */
    v176 = BOOL(GM_CALL(vm, "place_meeting", 3, v175, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v176)) goto L_3798296;
    /* @3798284 constant */
    /* @3798288 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3798296: ;
    /* @3798296 b */
    goto L_3798480;
    L_3798300: ;
    /* @3798300 load */
    /* @3798308 constant */
    /* @3798312 cmp */
    /* @3798316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3798480;
    /* @3798320 load */
    /* @3798328 constant */
    /* @3798332 cmp */
    /* @3798336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_3798480;
    /* @3798340 load */
    /* @3798348 constant */
    /* @3798352 cmp */
    /* @3798356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3798480;
    /* @3798360 load */
    /* @3798368 constant */
    /* @3798372 cmp */
    /* @3798376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3798400;
    /* @3798380 load */
    /* @3798388 constant */
    /* @3798392 cmp */
    /* @3798396 b */
    p3798404_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3798404;
    L_3798400: ;
    /* @3798400 constant */
    p3798404_0 = VAL(0);
    L_3798404: ;
    /* @3798404 bf */
    if (!TRUTH(p3798404_0)) goto L_3798480;
    /* @3798408 constant */
    /* @3798412 cast */
    /* @3798416 call */
    GM_SITE(vm, 12, 3798416);
    /* @3798424 cast */
    /* @3798428 not */
    /* @3798432 bf */
    v177 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v177)) goto L_3798480;
    /* @3798436 constant */
    /* @3798440 cast */
    /* @3798444 load */
    /* @3798452 constant */
    /* @3798456 sub */
    /* @3798460 load */
    /* @3798468 call */
    GM_SITE(vm, 12, 3798468);
    /* @3798476 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3798480: ;
    /* @3798480 constant */
    /* @3798484 cast */
    /* @3798488 call */
    GM_SITE(vm, 12, 3798488);
    /* @3798496 cast */
    /* @3798500 bf */
    v178 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(30)));
    if (!TRUTH(v178)) goto L_3799816;
    /* @3798504 load */
    /* @3798512 constant */
    /* @3798516 cmp */
    /* @3798520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfinalboss") != VAL(-4)))) goto L_3799160;
    /* @3798524 load */
    /* @3798532 constant */
    /* @3798536 cmp */
    /* @3798540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3799160;
    /* @3798544 load */
    /* @3798552 constant */
    /* @3798556 cmp */
    /* @3798560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3798584;
    /* @3798564 load */
    /* @3798572 constant */
    /* @3798576 cmp */
    /* @3798580 b */
    p3798588_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3798588;
    L_3798584: ;
    /* @3798584 constant */
    p3798588_0 = VAL(0);
    L_3798588: ;
    /* @3798588 bf */
    if (!TRUTH(p3798588_0)) goto L_3799160;
    /* @3798592 load */
    /* @3798600 constant */
    /* @3798604 cmp */
    /* @3798608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3798980;
    /* @3798612 constant */
    /* @3798616 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3798624 load */
    /* @3798632 constant */
    /* @3798636 sub */
    /* @3798640 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3798648 load */
    /* @3798656 cast */
    /* @3798660 load */
    /* @3798668 load */
    /* @3798676 cmp */
    /* @3798680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfinalboss")), "x") > GM_READ(vm, -1, "x")))) goto L_3798712;
    /* @3798684 constant */
    /* @3798688 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3798696 constant */
    /* @3798700 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3798708 b */
    goto L_3798772;
    L_3798712: ;
    /* @3798712 load */
    /* @3798720 cast */
    /* @3798724 load */
    /* @3798732 load */
    /* @3798740 cmp */
    /* @3798744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfinalboss")), "x") < GM_READ(vm, -1, "x")))) goto L_3798772;
    /* @3798748 constant */
    /* @3798752 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3798760 constant */
    /* @3798764 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3798772: ;
    /* @3798772 constant */
    /* @3798776 constant */
    /* @3798780 constant */
    /* @3798784 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3798792 constant */
    /* @3798796 constant */
    /* @3798800 constant */
    /* @3798804 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3798812 constant */
    /* @3798816 constant */
    /* @3798820 constant */
    /* @3798824 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3798832 load */
    /* @3798840 constant */
    /* @3798844 cmp */
    /* @3798848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3798856;
    /* @3798852 b */
    goto L_3798912;
    L_3798856: ;
    /* @3798856 load */
    /* @3798864 constant */
    /* @3798868 cmp */
    /* @3798872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3798912;
    /* @3798876 constant */
    /* @3798880 cast */
    /* @3798884 constant */
    /* @3798888 cast */
    /* @3798892 constant */
    /* @3798896 cast */
    /* @3798900 call */
    GM_SITE(vm, 12, 3798900);
    /* @3798908 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3798912: ;
    /* @3798912 constant */
    /* @3798916 cast */
    /* @3798920 load */
    /* @3798928 load */
    /* @3798936 load */
    /* @3798944 add */
    /* @3798948 call */
    GM_SITE(vm, 12, 3798948);
    v179 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3798956 cast */
    /* @3798960 bf */
    v180 = BOOL(GM_CALL(vm, "place_meeting", 3, v179, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v180)) goto L_3798976;
    /* @3798964 constant */
    /* @3798968 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3798976: ;
    /* @3798976 b */
    goto L_3799160;
    L_3798980: ;
    /* @3798980 load */
    /* @3798988 constant */
    /* @3798992 cmp */
    /* @3798996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3799160;
    /* @3799000 load */
    /* @3799008 constant */
    /* @3799012 cmp */
    /* @3799016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfinalboss") != VAL(-4)))) goto L_3799160;
    /* @3799020 load */
    /* @3799028 constant */
    /* @3799032 cmp */
    /* @3799036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3799160;
    /* @3799040 load */
    /* @3799048 constant */
    /* @3799052 cmp */
    /* @3799056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3799080;
    /* @3799060 load */
    /* @3799068 constant */
    /* @3799072 cmp */
    /* @3799076 b */
    p3799084_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3799084;
    L_3799080: ;
    /* @3799080 constant */
    p3799084_0 = VAL(0);
    L_3799084: ;
    /* @3799084 bf */
    if (!TRUTH(p3799084_0)) goto L_3799160;
    /* @3799088 constant */
    /* @3799092 cast */
    /* @3799096 call */
    GM_SITE(vm, 12, 3799096);
    /* @3799104 cast */
    /* @3799108 not */
    /* @3799112 bf */
    v181 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v181)) goto L_3799160;
    /* @3799116 constant */
    /* @3799120 cast */
    /* @3799124 load */
    /* @3799132 constant */
    /* @3799136 sub */
    /* @3799140 load */
    /* @3799148 call */
    GM_SITE(vm, 12, 3799148);
    /* @3799156 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3799160: ;
    /* @3799160 load */
    /* @3799168 constant */
    /* @3799172 cmp */
    /* @3799176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfinalboss") != VAL(-4)))) goto L_3799816;
    /* @3799180 load */
    /* @3799188 constant */
    /* @3799192 cmp */
    /* @3799196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3799816;
    /* @3799200 load */
    /* @3799208 constant */
    /* @3799212 cmp */
    /* @3799216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3799240;
    /* @3799220 load */
    /* @3799228 constant */
    /* @3799232 cmp */
    /* @3799236 b */
    p3799244_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3799244;
    L_3799240: ;
    /* @3799240 constant */
    p3799244_0 = VAL(0);
    L_3799244: ;
    /* @3799244 bf */
    if (!TRUTH(p3799244_0)) goto L_3799816;
    /* @3799248 load */
    /* @3799256 constant */
    /* @3799260 cmp */
    /* @3799264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_3799636;
    /* @3799268 constant */
    /* @3799272 store */
    GM_WRITE(vm, -1, "flashing", VAL(1));
    /* @3799280 load */
    /* @3799288 constant */
    /* @3799292 sub */
    /* @3799296 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @3799304 load */
    /* @3799312 cast */
    /* @3799316 load */
    /* @3799324 load */
    /* @3799332 cmp */
    /* @3799336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfinalboss")), "x") > GM_READ(vm, -1, "x")))) goto L_3799368;
    /* @3799340 constant */
    /* @3799344 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(1));
    /* @3799352 constant */
    /* @3799356 store */
    GM_WRITE(vm, -1, "sliding1", VAL(1));
    /* @3799364 b */
    goto L_3799428;
    L_3799368: ;
    /* @3799368 load */
    /* @3799376 cast */
    /* @3799380 load */
    /* @3799388 load */
    /* @3799396 cmp */
    /* @3799400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitfinalboss")), "x") < GM_READ(vm, -1, "x")))) goto L_3799428;
    /* @3799404 constant */
    /* @3799408 store */
    GM_WRITE(vm, -1, "invulnerable2", VAL(1));
    /* @3799416 constant */
    /* @3799420 store */
    GM_WRITE(vm, -1, "sliding2", VAL(1));
    L_3799428: ;
    /* @3799428 constant */
    /* @3799432 constant */
    /* @3799436 constant */
    /* @3799440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    /* @3799448 constant */
    /* @3799452 constant */
    /* @3799456 constant */
    /* @3799460 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(20));
    /* @3799468 constant */
    /* @3799472 constant */
    /* @3799476 constant */
    /* @3799480 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(23));
    /* @3799488 load */
    /* @3799496 constant */
    /* @3799500 cmp */
    /* @3799504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3799512;
    /* @3799508 b */
    goto L_3799568;
    L_3799512: ;
    /* @3799512 load */
    /* @3799520 constant */
    /* @3799524 cmp */
    /* @3799528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3799568;
    /* @3799532 constant */
    /* @3799536 cast */
    /* @3799540 constant */
    /* @3799544 cast */
    /* @3799548 constant */
    /* @3799552 cast */
    /* @3799556 call */
    GM_SITE(vm, 12, 3799556);
    /* @3799564 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3799568: ;
    /* @3799568 constant */
    /* @3799572 cast */
    /* @3799576 load */
    /* @3799584 load */
    /* @3799592 load */
    /* @3799600 add */
    /* @3799604 call */
    GM_SITE(vm, 12, 3799604);
    v182 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3799612 cast */
    /* @3799616 bf */
    v183 = BOOL(GM_CALL(vm, "place_meeting", 3, v182, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v183)) goto L_3799632;
    /* @3799620 constant */
    /* @3799624 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3799632: ;
    /* @3799632 b */
    goto L_3799816;
    L_3799636: ;
    /* @3799636 load */
    /* @3799644 constant */
    /* @3799648 cmp */
    /* @3799652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_3799816;
    /* @3799656 load */
    /* @3799664 constant */
    /* @3799668 cmp */
    /* @3799672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitfinalboss") != VAL(-4)))) goto L_3799816;
    /* @3799676 load */
    /* @3799684 constant */
    /* @3799688 cmp */
    /* @3799692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3799816;
    /* @3799696 load */
    /* @3799704 constant */
    /* @3799708 cmp */
    /* @3799712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "invulnerable") == VAL(0)))) goto L_3799736;
    /* @3799716 load */
    /* @3799724 constant */
    /* @3799728 cmp */
    /* @3799732 b */
    p3799740_0 = NUMBOOL(GM_READ(vm, -1, "invulnerable2") == VAL(0));
    goto L_3799740;
    L_3799736: ;
    /* @3799736 constant */
    p3799740_0 = VAL(0);
    L_3799740: ;
    /* @3799740 bf */
    if (!TRUTH(p3799740_0)) goto L_3799816;
    /* @3799744 constant */
    /* @3799748 cast */
    /* @3799752 call */
    GM_SITE(vm, 12, 3799752);
    /* @3799760 cast */
    /* @3799764 not */
    /* @3799768 bf */
    v184 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v184)) goto L_3799816;
    /* @3799772 constant */
    /* @3799776 cast */
    /* @3799780 load */
    /* @3799788 constant */
    /* @3799792 sub */
    /* @3799796 load */
    /* @3799804 call */
    GM_SITE(vm, 12, 3799804);
    /* @3799812 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(106)));
    L_3799816: ;
    /* @3799816 load */
    /* @3799824 constant */
    /* @3799828 cmp */
    /* @3799832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") == VAL(1)))) goto L_3799988;
    /* @3799836 constant */
    /* @3799840 cast */
    /* @3799844 load */
    /* @3799852 load */
    /* @3799860 call */
    GM_SITE(vm, 12, 3799860);
    /* @3799868 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(134)));
    /* @3799872 load */
    /* @3799880 constant */
    /* @3799884 cmp */
    /* @3799888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3799896;
    /* @3799892 b */
    goto L_3799952;
    L_3799896: ;
    /* @3799896 load */
    /* @3799904 constant */
    /* @3799908 cmp */
    /* @3799912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3799952;
    /* @3799916 constant */
    /* @3799920 cast */
    /* @3799924 constant */
    /* @3799928 cast */
    /* @3799932 constant */
    /* @3799936 cast */
    /* @3799940 call */
    GM_SITE(vm, 12, 3799940);
    /* @3799948 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(26), VAL(0), VAL(0)));
    L_3799952: ;
    /* @3799952 load */
    /* @3799960 constant */
    /* @3799964 add */
    /* @3799968 store */
    v185 = GM_ADD(GM_READ(vm, -5, "playerdied"), VAL(1));
    GM_WRITE(vm, -5, "playerdied", v185);
    /* @3799976 constant */
    /* @3799980 store */
    GM_WRITE(vm, -1, "invulnerable", VAL(0));
    L_3799988: ;
    /* @3799988 load */
    /* @3799996 constant */
    /* @3800000 cmp */
    /* @3800004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") <= VAL(1)))) goto L_3800020;
    /* @3800008 constant */
    /* @3800012 store */
    GM_WRITE(vm, -5, "health1", VAL(1));
    L_3800020: ;
    /* @3800020 load */
    /* @3800028 constant */
    /* @3800032 cmp */
    /* @3800036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") <= VAL(0)))) goto L_3800052;
    /* @3800040 constant */
    /* @3800044 store */
    GM_WRITE(vm, -5, "health1", VAL(1));
    L_3800052: ;
    /* @3800052 load */
    /* @3800060 load */
    /* @3800068 cmp */
    /* @3800072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") >= GM_READ(vm, -5, "maxhp")))) goto L_3800092;
    /* @3800076 load */
    /* @3800084 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    L_3800092: ;
    /* @3800092 load */
    /* @3800100 constant */
    /* @3800104 cmp */
    /* @3800108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "maxhp") >= VAL(23)))) goto L_3800124;
    /* @3800112 constant */
    /* @3800116 store */
    GM_WRITE(vm, -5, "maxhp", VAL(23));
    L_3800124: ;
    /* @3800124 load */
    /* @3800132 constant */
    /* @3800136 cmp */
    /* @3800140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(2)))) goto L_3800204;
    /* @3800144 load */
    /* @3800152 constant */
    /* @3800156 cmp */
    /* @3800160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade2") != VAL(1)))) goto L_3800204;
    /* @3800164 constant */
    /* @3800168 store */
    GM_WRITE(vm, -5, "maxhp", VAL(5));
    /* @3800176 load */
    /* @3800184 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800192 constant */
    /* @3800196 store */
    GM_WRITE(vm, -1, "hpupgrade2", VAL(1));
    L_3800204: ;
    /* @3800204 load */
    /* @3800212 constant */
    /* @3800216 cmp */
    /* @3800220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(3)))) goto L_3800284;
    /* @3800224 load */
    /* @3800232 constant */
    /* @3800236 cmp */
    /* @3800240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade3") != VAL(1)))) goto L_3800284;
    /* @3800244 constant */
    /* @3800248 store */
    GM_WRITE(vm, -5, "maxhp", VAL(6));
    /* @3800256 load */
    /* @3800264 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800272 constant */
    /* @3800276 store */
    GM_WRITE(vm, -1, "hpupgrade3", VAL(1));
    L_3800284: ;
    /* @3800284 load */
    /* @3800292 constant */
    /* @3800296 cmp */
    /* @3800300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(4)))) goto L_3800364;
    /* @3800304 load */
    /* @3800312 constant */
    /* @3800316 cmp */
    /* @3800320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade4") != VAL(1)))) goto L_3800364;
    /* @3800324 constant */
    /* @3800328 store */
    GM_WRITE(vm, -5, "maxhp", VAL(7));
    /* @3800336 load */
    /* @3800344 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800352 constant */
    /* @3800356 store */
    GM_WRITE(vm, -1, "hpupgrade4", VAL(1));
    L_3800364: ;
    /* @3800364 load */
    /* @3800372 constant */
    /* @3800376 cmp */
    /* @3800380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(5)))) goto L_3800444;
    /* @3800384 load */
    /* @3800392 constant */
    /* @3800396 cmp */
    /* @3800400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade5") != VAL(1)))) goto L_3800444;
    /* @3800404 constant */
    /* @3800408 store */
    GM_WRITE(vm, -5, "maxhp", VAL(8));
    /* @3800416 load */
    /* @3800424 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800432 constant */
    /* @3800436 store */
    GM_WRITE(vm, -1, "hpupgrade5", VAL(1));
    L_3800444: ;
    /* @3800444 load */
    /* @3800452 constant */
    /* @3800456 cmp */
    /* @3800460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(6)))) goto L_3800524;
    /* @3800464 load */
    /* @3800472 constant */
    /* @3800476 cmp */
    /* @3800480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade6") != VAL(1)))) goto L_3800524;
    /* @3800484 constant */
    /* @3800488 store */
    GM_WRITE(vm, -5, "maxhp", VAL(9));
    /* @3800496 load */
    /* @3800504 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800512 constant */
    /* @3800516 store */
    GM_WRITE(vm, -1, "hpupgrade6", VAL(1));
    L_3800524: ;
    /* @3800524 load */
    /* @3800532 constant */
    /* @3800536 cmp */
    /* @3800540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(7)))) goto L_3800604;
    /* @3800544 load */
    /* @3800552 constant */
    /* @3800556 cmp */
    /* @3800560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade7") != VAL(1)))) goto L_3800604;
    /* @3800564 constant */
    /* @3800568 store */
    GM_WRITE(vm, -5, "maxhp", VAL(10));
    /* @3800576 load */
    /* @3800584 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800592 constant */
    /* @3800596 store */
    GM_WRITE(vm, -1, "hpupgrade7", VAL(1));
    L_3800604: ;
    /* @3800604 load */
    /* @3800612 constant */
    /* @3800616 cmp */
    /* @3800620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(8)))) goto L_3800684;
    /* @3800624 load */
    /* @3800632 constant */
    /* @3800636 cmp */
    /* @3800640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade8") != VAL(1)))) goto L_3800684;
    /* @3800644 constant */
    /* @3800648 store */
    GM_WRITE(vm, -5, "maxhp", VAL(11));
    /* @3800656 load */
    /* @3800664 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800672 constant */
    /* @3800676 store */
    GM_WRITE(vm, -1, "hpupgrade8", VAL(1));
    L_3800684: ;
    /* @3800684 load */
    /* @3800692 constant */
    /* @3800696 cmp */
    /* @3800700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(9)))) goto L_3800764;
    /* @3800704 load */
    /* @3800712 constant */
    /* @3800716 cmp */
    /* @3800720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade9") != VAL(1)))) goto L_3800764;
    /* @3800724 constant */
    /* @3800728 store */
    GM_WRITE(vm, -5, "maxhp", VAL(12));
    /* @3800736 load */
    /* @3800744 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800752 constant */
    /* @3800756 store */
    GM_WRITE(vm, -1, "hpupgrade9", VAL(1));
    L_3800764: ;
    /* @3800764 load */
    /* @3800772 constant */
    /* @3800776 cmp */
    /* @3800780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(10)))) goto L_3800844;
    /* @3800784 load */
    /* @3800792 constant */
    /* @3800796 cmp */
    /* @3800800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade10") != VAL(1)))) goto L_3800844;
    /* @3800804 constant */
    /* @3800808 store */
    GM_WRITE(vm, -5, "maxhp", VAL(13));
    /* @3800816 load */
    /* @3800824 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800832 constant */
    /* @3800836 store */
    GM_WRITE(vm, -1, "hpupgrade10", VAL(1));
    L_3800844: ;
    /* @3800844 load */
    /* @3800852 constant */
    /* @3800856 cmp */
    /* @3800860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(11)))) goto L_3800924;
    /* @3800864 load */
    /* @3800872 constant */
    /* @3800876 cmp */
    /* @3800880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade11") != VAL(1)))) goto L_3800924;
    /* @3800884 constant */
    /* @3800888 store */
    GM_WRITE(vm, -5, "maxhp", VAL(14));
    /* @3800896 load */
    /* @3800904 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800912 constant */
    /* @3800916 store */
    GM_WRITE(vm, -1, "hpupgrade11", VAL(1));
    L_3800924: ;
    /* @3800924 load */
    /* @3800932 constant */
    /* @3800936 cmp */
    /* @3800940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(12)))) goto L_3801004;
    /* @3800944 load */
    /* @3800952 constant */
    /* @3800956 cmp */
    /* @3800960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade12") != VAL(1)))) goto L_3801004;
    /* @3800964 constant */
    /* @3800968 store */
    GM_WRITE(vm, -5, "maxhp", VAL(15));
    /* @3800976 load */
    /* @3800984 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3800992 constant */
    /* @3800996 store */
    GM_WRITE(vm, -1, "hpupgrade12", VAL(1));
    L_3801004: ;
    /* @3801004 load */
    /* @3801012 constant */
    /* @3801016 cmp */
    /* @3801020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(13)))) goto L_3801084;
    /* @3801024 load */
    /* @3801032 constant */
    /* @3801036 cmp */
    /* @3801040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade13") != VAL(1)))) goto L_3801084;
    /* @3801044 constant */
    /* @3801048 store */
    GM_WRITE(vm, -5, "maxhp", VAL(16));
    /* @3801056 load */
    /* @3801064 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801072 constant */
    /* @3801076 store */
    GM_WRITE(vm, -1, "hpupgrade13", VAL(1));
    L_3801084: ;
    /* @3801084 load */
    /* @3801092 constant */
    /* @3801096 cmp */
    /* @3801100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(14)))) goto L_3801164;
    /* @3801104 load */
    /* @3801112 constant */
    /* @3801116 cmp */
    /* @3801120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade14") != VAL(1)))) goto L_3801164;
    /* @3801124 constant */
    /* @3801128 store */
    GM_WRITE(vm, -5, "maxhp", VAL(17));
    /* @3801136 load */
    /* @3801144 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801152 constant */
    /* @3801156 store */
    GM_WRITE(vm, -1, "hpupgrade14", VAL(1));
    L_3801164: ;
    /* @3801164 load */
    /* @3801172 constant */
    /* @3801176 cmp */
    /* @3801180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(15)))) goto L_3801244;
    /* @3801184 load */
    /* @3801192 constant */
    /* @3801196 cmp */
    /* @3801200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade15") != VAL(1)))) goto L_3801244;
    /* @3801204 constant */
    /* @3801208 store */
    GM_WRITE(vm, -5, "maxhp", VAL(18));
    /* @3801216 load */
    /* @3801224 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801232 constant */
    /* @3801236 store */
    GM_WRITE(vm, -1, "hpupgrade15", VAL(1));
    L_3801244: ;
    /* @3801244 load */
    /* @3801252 constant */
    /* @3801256 cmp */
    /* @3801260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(16)))) goto L_3801324;
    /* @3801264 load */
    /* @3801272 constant */
    /* @3801276 cmp */
    /* @3801280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade16") != VAL(1)))) goto L_3801324;
    /* @3801284 constant */
    /* @3801288 store */
    GM_WRITE(vm, -5, "maxhp", VAL(19));
    /* @3801296 load */
    /* @3801304 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801312 constant */
    /* @3801316 store */
    GM_WRITE(vm, -1, "hpupgrade16", VAL(1));
    L_3801324: ;
    /* @3801324 load */
    /* @3801332 constant */
    /* @3801336 cmp */
    /* @3801340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(17)))) goto L_3801404;
    /* @3801344 load */
    /* @3801352 constant */
    /* @3801356 cmp */
    /* @3801360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade17") != VAL(1)))) goto L_3801404;
    /* @3801364 constant */
    /* @3801368 store */
    GM_WRITE(vm, -5, "maxhp", VAL(20));
    /* @3801376 load */
    /* @3801384 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801392 constant */
    /* @3801396 store */
    GM_WRITE(vm, -1, "hpupgrade17", VAL(1));
    L_3801404: ;
    /* @3801404 load */
    /* @3801412 constant */
    /* @3801416 cmp */
    /* @3801420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(18)))) goto L_3801484;
    /* @3801424 load */
    /* @3801432 constant */
    /* @3801436 cmp */
    /* @3801440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade18") != VAL(1)))) goto L_3801484;
    /* @3801444 constant */
    /* @3801448 store */
    GM_WRITE(vm, -5, "maxhp", VAL(21));
    /* @3801456 load */
    /* @3801464 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801472 constant */
    /* @3801476 store */
    GM_WRITE(vm, -1, "hpupgrade18", VAL(1));
    L_3801484: ;
    /* @3801484 load */
    /* @3801492 constant */
    /* @3801496 cmp */
    /* @3801500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(19)))) goto L_3801564;
    /* @3801504 load */
    /* @3801512 constant */
    /* @3801516 cmp */
    /* @3801520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade19") != VAL(1)))) goto L_3801564;
    /* @3801524 constant */
    /* @3801528 store */
    GM_WRITE(vm, -5, "maxhp", VAL(22));
    /* @3801536 load */
    /* @3801544 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801552 constant */
    /* @3801556 store */
    GM_WRITE(vm, -1, "hpupgrade19", VAL(1));
    L_3801564: ;
    /* @3801564 load */
    /* @3801572 constant */
    /* @3801576 cmp */
    /* @3801580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") == VAL(20)))) goto L_3801644;
    /* @3801584 load */
    /* @3801592 constant */
    /* @3801596 cmp */
    /* @3801600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpupgrade20") != VAL(1)))) goto L_3801644;
    /* @3801604 constant */
    /* @3801608 store */
    GM_WRITE(vm, -5, "maxhp", VAL(23));
    /* @3801616 load */
    /* @3801624 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @3801632 constant */
    /* @3801636 store */
    GM_WRITE(vm, -1, "hpupgrade20", VAL(1));
    L_3801644: ;
    /* @3801644 constant */
    /* @3801648 cast */
    /* @3801652 call */
    GM_SITE(vm, 12, 3801652);
    /* @3801660 constant */
    /* @3801664 cmp */
    /* @3801668 bf */
    v186 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(8)) <= VAL(1));
    if (!TRUTH(v186)) goto L_3801696;
    /* @3801672 constant */
    /* @3801676 store */
    GM_WRITE(vm, -5, "health1", VAL(1));
    /* @3801684 constant */
    /* @3801688 store */
    GM_WRITE(vm, 0, "playerhp", VAL(1));
    L_3801696: ;
    /* @3801696 constant */
    /* @3801700 cast */
    /* @3801704 call */
    GM_SITE(vm, 12, 3801704);
    /* @3801712 constant */
    /* @3801716 cmp */
    /* @3801720 bf */
    v187 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(9)) <= VAL(1));
    if (!TRUTH(v187)) goto L_3801748;
    /* @3801724 constant */
    /* @3801728 store */
    GM_WRITE(vm, -5, "health1", VAL(1));
    /* @3801736 constant */
    /* @3801740 store */
    GM_WRITE(vm, 0, "playerhp", VAL(1));
    L_3801748: ;
    /* @3801748 constant */
    /* @3801752 cast */
    /* @3801756 constant */
    /* @3801760 cast */
    /* @3801764 call */
    GM_SITE(vm, 12, 3801764);
    /* @3801772 store */
    v188 = GM_CALL(vm, "random_range", 2, VAL(-10), VAL(10));
    GM_WRITE(vm, -1, "shotgunspread", v188);
    /* @3801780 constant */
    /* @3801784 cast */
    /* @3801788 constant */
    /* @3801792 cast */
    /* @3801796 call */
    GM_SITE(vm, 12, 3801796);
    /* @3801804 store */
    v189 = GM_CALL(vm, "random_range", 2, VAL(-5), VAL(5));
    GM_WRITE(vm, -1, "assaultriflespread", v189);
    /* @3801812 constant */
    /* @3801816 cast */
    /* @3801820 constant */
    /* @3801824 cast */
    /* @3801828 call */
    GM_SITE(vm, 12, 3801828);
    /* @3801836 store */
    v190 = GM_CALL(vm, "random_range", 2, VAL(30), VAL(99));
    GM_WRITE(vm, -1, "coindeduct", v190);
    /* @3801844 load */
    /* @3801852 constant */
    /* @3801856 cmp */
    /* @3801860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgradebought") == VAL(1)))) goto L_3801876;
    /* @3801864 constant */
    /* @3801868 store */
    GM_WRITE(vm, -5, "sword", VAL(1));
    L_3801876: ;
    /* @3801876 load */
    /* @3801884 constant */
    /* @3801888 cmp */
    /* @3801892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade2bought") == VAL(1)))) goto L_3801908;
    /* @3801896 constant */
    /* @3801900 store */
    GM_WRITE(vm, -5, "sword", VAL(2));
    L_3801908: ;
    /* @3801908 load */
    /* @3801916 constant */
    /* @3801920 cmp */
    /* @3801924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "swordupgrade3bought") == VAL(1)))) goto L_3801940;
    /* @3801928 constant */
    /* @3801932 store */
    GM_WRITE(vm, -5, "sword", VAL(3));
    L_3801940: ;
    /* @3801940 load */
    /* @3801948 constant */
    /* @3801952 cmp */
    /* @3801956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") < VAL(0)))) goto L_3801972;
    /* @3801960 constant */
    /* @3801964 store */
    GM_WRITE(vm, -1, "score", VAL(0));
    L_3801972: ;
    /* @3801972 load */
    /* @3801980 constant */
    /* @3801984 cmp */
    /* @3801988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3802044;
    /* @3801992 constant */
    /* @3802004 store */
    GM_WRITE(vm, -1, "hspeed", VAL(1.1));
    /* @3802012 constant */
    /* @3802016 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(30));
    /* @3802024 constant */
    /* @3802036 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0.6));
    L_3802044: ;
    /* @3802044 constant */
    /* @3802048 cast */
    /* @3802052 load */
    /* @3802060 load */
    /* @3802068 call */
    GM_SITE(vm, 12, 3802068);
    /* @3802076 store */
    v191 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(57));
    GM_WRITE(vm, -1, "hitpickup", v191);
    /* @3802084 load */
    /* @3802092 constant */
    /* @3802096 cmp */
    /* @3802100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitpickup") != VAL(-4)))) goto L_3803040;
    /* @3802104 load */
    /* @3802112 cast */
    /* @3802116 load */
    /* @3802124 constant */
    /* @3802128 cmp */
    /* @3802132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitpickup")), "type") == VAL(1)))) goto L_3802312;
    /* @3802136 load */
    /* @3802144 constant */
    /* @3802148 load */
    /* @3802156 mul */
    /* @3802160 add */
    /* @3802164 store */
    v192 = GM_ADD(GM_READ(vm, -1, "score"), (VAL(1) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -1, "score", v192);
    /* @3802172 load */
    /* @3802180 constant */
    /* @3802184 load */
    /* @3802192 mul */
    /* @3802196 add */
    /* @3802200 store */
    v193 = GM_ADD(GM_READ(vm, -5, "coinpickup"), (VAL(1) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -5, "coinpickup", v193);
    /* @3802208 constant */
    /* @3802212 cast */
    /* @3802216 constant */
    /* @3802220 constant */
    /* @3802224 load */
    /* @3802232 constant */
    /* @3802236 add */
    /* @3802240 constant */
    /* @3802244 constant */
    /* @3802248 load */
    /* @3802256 constant */
    /* @3802260 add */
    /* @3802264 call */
    GM_SITE(vm, 12, 3802264);
    v194 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(225));
    v195 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(4));
    /* @3802272 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v194, v195, VAL(132)));
    /* @3802276 load */
    /* @3802284 cast */
    /* @3802288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitpickup")))) goto L_3802304;
    L_3802292: ;
    /* @3802292 call */
    GM_SITE(vm, 12, 3802292);
    /* @3802300 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3802304: ;
    /* @3802304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3802292;
    /* @3802308 b */
    goto L_3803040;
    L_3802312: ;
    /* @3802312 load */
    /* @3802320 cast */
    /* @3802324 load */
    /* @3802332 constant */
    /* @3802336 cmp */
    /* @3802340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitpickup")), "type") == VAL(2)))) goto L_3802520;
    /* @3802344 load */
    /* @3802352 constant */
    /* @3802356 load */
    /* @3802364 mul */
    /* @3802368 add */
    /* @3802372 store */
    v196 = GM_ADD(GM_READ(vm, -1, "score"), (VAL(100) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -1, "score", v196);
    /* @3802380 load */
    /* @3802388 constant */
    /* @3802392 load */
    /* @3802400 mul */
    /* @3802404 add */
    /* @3802408 store */
    v197 = GM_ADD(GM_READ(vm, -5, "coinpickup"), (VAL(100) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -5, "coinpickup", v197);
    /* @3802416 constant */
    /* @3802420 cast */
    /* @3802424 constant */
    /* @3802428 constant */
    /* @3802432 load */
    /* @3802440 constant */
    /* @3802444 add */
    /* @3802448 constant */
    /* @3802452 constant */
    /* @3802456 load */
    /* @3802464 constant */
    /* @3802468 add */
    /* @3802472 call */
    GM_SITE(vm, 12, 3802472);
    v198 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(225));
    v199 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(4));
    /* @3802480 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v198, v199, VAL(132)));
    /* @3802484 load */
    /* @3802492 cast */
    /* @3802496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitpickup")))) goto L_3802512;
    L_3802500: ;
    /* @3802500 call */
    GM_SITE(vm, 12, 3802500);
    /* @3802508 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3802512: ;
    /* @3802512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3802500;
    /* @3802516 b */
    goto L_3803040;
    L_3802520: ;
    /* @3802520 load */
    /* @3802528 cast */
    /* @3802532 load */
    /* @3802540 constant */
    /* @3802544 cmp */
    /* @3802548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitpickup")), "type") == VAL(3)))) goto L_3802728;
    /* @3802552 load */
    /* @3802560 constant */
    /* @3802564 load */
    /* @3802572 mul */
    /* @3802576 add */
    /* @3802580 store */
    v200 = GM_ADD(GM_READ(vm, -1, "score"), (VAL(4) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -1, "score", v200);
    /* @3802588 load */
    /* @3802596 constant */
    /* @3802600 load */
    /* @3802608 mul */
    /* @3802612 add */
    /* @3802616 store */
    v201 = GM_ADD(GM_READ(vm, -5, "coinpickup"), (VAL(4) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -5, "coinpickup", v201);
    /* @3802624 constant */
    /* @3802628 cast */
    /* @3802632 constant */
    /* @3802636 constant */
    /* @3802640 load */
    /* @3802648 constant */
    /* @3802652 add */
    /* @3802656 constant */
    /* @3802660 constant */
    /* @3802664 load */
    /* @3802672 constant */
    /* @3802676 add */
    /* @3802680 call */
    GM_SITE(vm, 12, 3802680);
    v202 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(225));
    v203 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(4));
    /* @3802688 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v202, v203, VAL(132)));
    /* @3802692 load */
    /* @3802700 cast */
    /* @3802704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitpickup")))) goto L_3802720;
    L_3802708: ;
    /* @3802708 call */
    GM_SITE(vm, 12, 3802708);
    /* @3802716 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3802720: ;
    /* @3802720 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3802708;
    /* @3802724 b */
    goto L_3803040;
    L_3802728: ;
    /* @3802728 load */
    /* @3802736 cast */
    /* @3802740 load */
    /* @3802748 constant */
    /* @3802752 cmp */
    /* @3802756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitpickup")), "type") == VAL(4)))) goto L_3802900;
    /* @3802760 load */
    /* @3802768 constant */
    /* @3802772 add */
    /* @3802776 store */
    v204 = GM_ADD(GM_READ(vm, -5, "experience"), VAL(1));
    GM_WRITE(vm, -5, "experience", v204);
    /* @3802784 load */
    /* @3802792 constant */
    /* @3802796 cmp */
    /* @3802800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3802808;
    /* @3802804 b */
    goto L_3802864;
    L_3802808: ;
    /* @3802808 load */
    /* @3802816 constant */
    /* @3802820 cmp */
    /* @3802824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3802864;
    /* @3802828 constant */
    /* @3802832 cast */
    /* @3802836 constant */
    /* @3802840 cast */
    /* @3802844 constant */
    /* @3802848 cast */
    /* @3802852 call */
    GM_SITE(vm, 12, 3802852);
    /* @3802860 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_3802864: ;
    /* @3802864 load */
    /* @3802872 cast */
    /* @3802876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitpickup")))) goto L_3802892;
    L_3802880: ;
    /* @3802880 call */
    GM_SITE(vm, 12, 3802880);
    /* @3802888 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3802892: ;
    /* @3802892 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3802880;
    /* @3802896 b */
    goto L_3803040;
    L_3802900: ;
    /* @3802900 load */
    /* @3802908 cast */
    /* @3802912 load */
    /* @3802920 constant */
    /* @3802924 cmp */
    /* @3802928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitpickup")), "type") == VAL(5)))) goto L_3803040;
    /* @3802932 load */
    /* @3802940 load */
    /* @3802948 cmp */
    /* @3802952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") != GM_READ(vm, -5, "maxhp")))) goto L_3802984;
    /* @3802956 load */
    /* @3802964 constant */
    /* @3802968 add */
    /* @3802972 store */
    v205 = GM_ADD(GM_READ(vm, -5, "health1"), VAL(1));
    GM_WRITE(vm, -5, "health1", v205);
    /* @3802980 b */
    goto L_3803008;
    L_3802984: ;
    /* @3802984 load */
    /* @3802992 load */
    /* @3803000 cmp */
    /* @3803004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "health1") == GM_READ(vm, -5, "maxhp")))) goto L_3803008;
    L_3803008: ;
    /* @3803008 load */
    /* @3803016 cast */
    /* @3803020 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitpickup")))) goto L_3803036;
    L_3803024: ;
    /* @3803024 call */
    GM_SITE(vm, 12, 3803024);
    /* @3803032 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3803036: ;
    /* @3803036 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3803024;
    L_3803040: ;
    /* @3803040 load */
    /* @3803048 constant */
    /* @3803052 cmp */
    /* @3803056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "assaultfire") <= VAL(0)))) goto L_3803072;
    /* @3803060 constant */
    /* @3803064 store */
    GM_WRITE(vm, -1, "assaultfire", VAL(4));
    L_3803072: ;
    /* @3803072 load */
    /* @3803080 constant */
    /* @3803084 cmp */
    /* @3803088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "assaultfire") > VAL(0)))) goto L_3803116;
    /* @3803092 load */
    /* @3803100 constant */
    /* @3803104 sub */
    /* @3803108 store */
    GM_WRITE(vm, -1, "assaultfire", (GM_READ(vm, -1, "assaultfire") - VAL(1)));
    L_3803116: ;
    return;
}
