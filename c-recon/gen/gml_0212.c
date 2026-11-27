/* generated from CODE 212 (gml_Object_obj_boss5_Alarm_0), source start 4019040, end 4028176. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0212(GmVM* vm) {
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
    Val v109;
    Val v110;
    Val v111;
    Val v112;
    Val v113;
    Val v114;
    Val v115;
    Val v116;
    Val v117;
    Val v118;
    Val v119;
    Val v120;
    Val v121;
    Val v122;
    Val v123;
    /* @4019040 load */
    /* @4019048 constant */
    /* @4019052 cmp */
    /* @4019056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4019064;
    /* @4019060 b */
    goto L_4019120;
    L_4019064: ;
    /* @4019064 load */
    /* @4019072 constant */
    /* @4019076 cmp */
    /* @4019080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4019120;
    /* @4019084 constant */
    /* @4019088 cast */
    /* @4019092 constant */
    /* @4019096 cast */
    /* @4019100 constant */
    /* @4019104 cast */
    /* @4019108 call */
    GM_SITE(vm, 212, 4019108);
    /* @4019116 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4019120: ;
    /* @4019120 load */
    /* @4019128 constant */
    /* @4019132 cmp */
    /* @4019136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4019184;
    /* @4019140 constant */
    /* @4019144 cast */
    /* @4019148 load */
    /* @4019156 constant */
    /* @4019160 sub */
    /* @4019164 load */
    /* @4019172 call */
    GM_SITE(vm, 212, 4019172);
    /* @4019180 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_4019184: ;
    /* @4019184 constant */
    /* @4019188 store */
    GM_WRITE(vm, -5, "boss5dead", VAL(1));
    /* @4019196 load */
    /* @4019204 constant */
    /* @4019208 cmp */
    /* @4019212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4019260;
    /* @4019216 constant */
    /* @4019220 cast */
    /* @4019224 load */
    /* @4019232 constant */
    /* @4019236 sub */
    /* @4019240 load */
    /* @4019248 call */
    GM_SITE(vm, 212, 4019248);
    /* @4019256 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_4019260: ;
    /* @4019260 load */
    /* @4019268 constant */
    /* @4019272 cmp */
    /* @4019276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4020304;
    /* @4019280 constant */
    /* @4019284 cast */
    /* @4019288 load */
    /* @4019296 constant */
    /* @4019300 sub */
    /* @4019304 load */
    /* @4019312 call */
    GM_SITE(vm, 212, 4019312);
    /* @4019320 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @4019328 load */
    /* @4019336 cast */
    /* @4019340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4019372;
    L_4019344: ;
    /* @4019344 constant */
    /* @4019348 cast */
    /* @4019352 load */
    /* @4019360 call */
    GM_SITE(vm, 212, 4019360);
    /* @4019368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4019372: ;
    /* @4019372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019344;
    /* @4019376 constant */
    /* @4019380 cast */
    /* @4019384 load */
    /* @4019392 constant */
    /* @4019396 sub */
    /* @4019400 load */
    /* @4019408 constant */
    /* @4019412 add */
    /* @4019416 call */
    GM_SITE(vm, 212, 4019416);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @4019424 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @4019432 load */
    /* @4019440 cast */
    /* @4019444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4019476;
    L_4019448: ;
    /* @4019448 constant */
    /* @4019452 cast */
    /* @4019456 load */
    /* @4019464 call */
    GM_SITE(vm, 212, 4019464);
    /* @4019472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4019476: ;
    /* @4019476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019448;
    /* @4019480 constant */
    /* @4019484 cast */
    /* @4019488 load */
    /* @4019496 constant */
    /* @4019500 sub */
    /* @4019504 load */
    /* @4019512 constant */
    /* @4019516 sub */
    /* @4019520 call */
    GM_SITE(vm, 212, 4019520);
    /* @4019528 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @4019536 load */
    /* @4019544 cast */
    /* @4019548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4019580;
    L_4019552: ;
    /* @4019552 constant */
    /* @4019556 cast */
    /* @4019560 load */
    /* @4019568 call */
    GM_SITE(vm, 212, 4019568);
    /* @4019576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4019580: ;
    /* @4019580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019552;
    /* @4019584 constant */
    /* @4019588 cast */
    /* @4019592 load */
    /* @4019600 constant */
    /* @4019604 sub */
    /* @4019608 load */
    /* @4019616 constant */
    /* @4019620 add */
    /* @4019624 call */
    GM_SITE(vm, 212, 4019624);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4019632 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @4019640 load */
    /* @4019648 cast */
    /* @4019652 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4019684;
    L_4019656: ;
    /* @4019656 constant */
    /* @4019660 cast */
    /* @4019664 load */
    /* @4019672 call */
    GM_SITE(vm, 212, 4019672);
    /* @4019680 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4019684: ;
    /* @4019684 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019656;
    /* @4019688 constant */
    /* @4019692 cast */
    /* @4019696 load */
    /* @4019704 constant */
    /* @4019708 sub */
    /* @4019712 load */
    /* @4019720 constant */
    /* @4019724 sub */
    /* @4019728 call */
    GM_SITE(vm, 212, 4019728);
    /* @4019736 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @4019744 load */
    /* @4019752 cast */
    /* @4019756 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4019788;
    L_4019760: ;
    /* @4019760 constant */
    /* @4019764 cast */
    /* @4019768 load */
    /* @4019776 call */
    GM_SITE(vm, 212, 4019776);
    /* @4019784 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4019788: ;
    /* @4019788 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019760;
    /* @4019792 constant */
    /* @4019796 cast */
    /* @4019800 load */
    /* @4019808 constant */
    /* @4019812 sub */
    /* @4019816 load */
    /* @4019824 call */
    GM_SITE(vm, 212, 4019824);
    /* @4019832 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID6", v8);
    /* @4019840 load */
    /* @4019848 cast */
    /* @4019852 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4019884;
    L_4019856: ;
    /* @4019856 constant */
    /* @4019860 cast */
    /* @4019864 load */
    /* @4019872 call */
    GM_SITE(vm, 212, 4019872);
    /* @4019880 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4019884: ;
    /* @4019884 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019856;
    /* @4019888 constant */
    /* @4019892 cast */
    /* @4019896 load */
    /* @4019904 constant */
    /* @4019908 sub */
    /* @4019912 load */
    /* @4019920 constant */
    /* @4019924 add */
    /* @4019928 call */
    GM_SITE(vm, 212, 4019928);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4019936 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID7", v10);
    /* @4019944 load */
    /* @4019952 cast */
    /* @4019956 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4019988;
    L_4019960: ;
    /* @4019960 constant */
    /* @4019964 cast */
    /* @4019968 load */
    /* @4019976 call */
    GM_SITE(vm, 212, 4019976);
    /* @4019984 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4019988: ;
    /* @4019988 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4019960;
    /* @4019992 constant */
    /* @4019996 cast */
    /* @4020000 load */
    /* @4020008 constant */
    /* @4020012 sub */
    /* @4020016 load */
    /* @4020024 constant */
    /* @4020028 sub */
    /* @4020032 call */
    GM_SITE(vm, 212, 4020032);
    /* @4020040 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(17)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID8", v11);
    /* @4020048 load */
    /* @4020056 cast */
    /* @4020060 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4020092;
    L_4020064: ;
    /* @4020064 constant */
    /* @4020068 cast */
    /* @4020072 load */
    /* @4020080 call */
    GM_SITE(vm, 212, 4020080);
    /* @4020088 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4020092: ;
    /* @4020092 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020064;
    /* @4020096 constant */
    /* @4020100 cast */
    /* @4020104 load */
    /* @4020112 constant */
    /* @4020116 sub */
    /* @4020120 load */
    /* @4020128 constant */
    /* @4020132 add */
    /* @4020136 call */
    GM_SITE(vm, 212, 4020136);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4020144 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID9", v13);
    /* @4020152 load */
    /* @4020160 cast */
    /* @4020164 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4020196;
    L_4020168: ;
    /* @4020168 constant */
    /* @4020172 cast */
    /* @4020176 load */
    /* @4020184 call */
    GM_SITE(vm, 212, 4020184);
    /* @4020192 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4020196: ;
    /* @4020196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020168;
    /* @4020200 constant */
    /* @4020204 cast */
    /* @4020208 load */
    /* @4020216 constant */
    /* @4020220 sub */
    /* @4020224 load */
    /* @4020232 constant */
    /* @4020236 sub */
    /* @4020240 call */
    GM_SITE(vm, 212, 4020240);
    /* @4020248 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(21)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID10", v14);
    /* @4020256 load */
    /* @4020264 cast */
    /* @4020268 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4020300;
    L_4020272: ;
    /* @4020272 constant */
    /* @4020276 cast */
    /* @4020280 load */
    /* @4020288 call */
    GM_SITE(vm, 212, 4020288);
    /* @4020296 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4020300: ;
    /* @4020300 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020272;
    L_4020304: ;
    /* @4020304 load */
    /* @4020312 constant */
    /* @4020316 cmp */
    /* @4020320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4020836;
    /* @4020324 constant */
    /* @4020328 cast */
    /* @4020332 load */
    /* @4020340 constant */
    /* @4020344 sub */
    /* @4020348 load */
    /* @4020356 call */
    GM_SITE(vm, 212, 4020356);
    /* @4020364 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @4020372 load */
    /* @4020380 cast */
    /* @4020384 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4020416;
    L_4020388: ;
    /* @4020388 constant */
    /* @4020392 cast */
    /* @4020396 load */
    /* @4020404 call */
    GM_SITE(vm, 212, 4020404);
    /* @4020412 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4020416: ;
    /* @4020416 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020388;
    /* @4020420 constant */
    /* @4020424 cast */
    /* @4020428 load */
    /* @4020436 constant */
    /* @4020440 sub */
    /* @4020444 load */
    /* @4020452 constant */
    /* @4020456 add */
    /* @4020460 call */
    GM_SITE(vm, 212, 4020460);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4020468 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @4020476 load */
    /* @4020484 cast */
    /* @4020488 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4020520;
    L_4020492: ;
    /* @4020492 constant */
    /* @4020496 cast */
    /* @4020500 load */
    /* @4020508 call */
    GM_SITE(vm, 212, 4020508);
    /* @4020516 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4020520: ;
    /* @4020520 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020492;
    /* @4020524 constant */
    /* @4020528 cast */
    /* @4020532 load */
    /* @4020540 constant */
    /* @4020544 sub */
    /* @4020548 load */
    /* @4020556 constant */
    /* @4020560 sub */
    /* @4020564 call */
    GM_SITE(vm, 212, 4020564);
    /* @4020572 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @4020580 load */
    /* @4020588 cast */
    /* @4020592 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4020624;
    L_4020596: ;
    /* @4020596 constant */
    /* @4020600 cast */
    /* @4020604 load */
    /* @4020612 call */
    GM_SITE(vm, 212, 4020612);
    /* @4020620 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4020624: ;
    /* @4020624 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020596;
    /* @4020628 constant */
    /* @4020632 cast */
    /* @4020636 load */
    /* @4020644 constant */
    /* @4020648 sub */
    /* @4020652 load */
    /* @4020660 constant */
    /* @4020664 add */
    /* @4020668 call */
    GM_SITE(vm, 212, 4020668);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4020676 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @4020684 load */
    /* @4020692 cast */
    /* @4020696 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4020728;
    L_4020700: ;
    /* @4020700 constant */
    /* @4020704 cast */
    /* @4020708 load */
    /* @4020716 call */
    GM_SITE(vm, 212, 4020716);
    /* @4020724 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4020728: ;
    /* @4020728 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020700;
    /* @4020732 constant */
    /* @4020736 cast */
    /* @4020740 load */
    /* @4020748 constant */
    /* @4020752 sub */
    /* @4020756 load */
    /* @4020764 constant */
    /* @4020768 sub */
    /* @4020772 call */
    GM_SITE(vm, 212, 4020772);
    /* @4020780 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @4020788 load */
    /* @4020796 cast */
    /* @4020800 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4020832;
    L_4020804: ;
    /* @4020804 constant */
    /* @4020808 cast */
    /* @4020812 load */
    /* @4020820 call */
    GM_SITE(vm, 212, 4020820);
    /* @4020828 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4020832: ;
    /* @4020832 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020804;
    L_4020836: ;
    /* @4020836 load */
    /* @4020844 constant */
    /* @4020848 cmp */
    /* @4020852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4021888;
    /* @4020856 constant */
    /* @4020860 cast */
    /* @4020864 load */
    /* @4020872 constant */
    /* @4020876 sub */
    /* @4020880 load */
    /* @4020888 call */
    GM_SITE(vm, 212, 4020888);
    /* @4020896 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @4020904 load */
    /* @4020912 cast */
    /* @4020916 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4020948;
    L_4020920: ;
    /* @4020920 constant */
    /* @4020924 cast */
    /* @4020928 load */
    /* @4020936 call */
    GM_SITE(vm, 212, 4020936);
    /* @4020944 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4020948: ;
    /* @4020948 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4020920;
    /* @4020952 constant */
    /* @4020956 cast */
    /* @4020960 load */
    /* @4020968 constant */
    /* @4020972 sub */
    /* @4020976 load */
    /* @4020984 constant */
    /* @4020988 add */
    /* @4020992 call */
    GM_SITE(vm, 212, 4020992);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4021000 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @4021008 load */
    /* @4021016 cast */
    /* @4021020 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4021052;
    L_4021024: ;
    /* @4021024 constant */
    /* @4021028 cast */
    /* @4021032 load */
    /* @4021040 call */
    GM_SITE(vm, 212, 4021040);
    /* @4021048 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4021052: ;
    /* @4021052 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021024;
    /* @4021056 constant */
    /* @4021060 cast */
    /* @4021064 load */
    /* @4021072 constant */
    /* @4021076 sub */
    /* @4021080 load */
    /* @4021088 constant */
    /* @4021092 sub */
    /* @4021096 call */
    GM_SITE(vm, 212, 4021096);
    /* @4021104 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @4021112 load */
    /* @4021120 cast */
    /* @4021124 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4021156;
    L_4021128: ;
    /* @4021128 constant */
    /* @4021132 cast */
    /* @4021136 load */
    /* @4021144 call */
    GM_SITE(vm, 212, 4021144);
    /* @4021152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4021156: ;
    /* @4021156 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021128;
    /* @4021160 constant */
    /* @4021164 cast */
    /* @4021168 load */
    /* @4021176 constant */
    /* @4021180 sub */
    /* @4021184 load */
    /* @4021192 constant */
    /* @4021196 add */
    /* @4021200 call */
    GM_SITE(vm, 212, 4021200);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4021208 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @4021216 load */
    /* @4021224 cast */
    /* @4021228 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4021260;
    L_4021232: ;
    /* @4021232 constant */
    /* @4021236 cast */
    /* @4021240 load */
    /* @4021248 call */
    GM_SITE(vm, 212, 4021248);
    /* @4021256 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4021260: ;
    /* @4021260 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021232;
    /* @4021264 constant */
    /* @4021268 cast */
    /* @4021272 load */
    /* @4021280 constant */
    /* @4021284 sub */
    /* @4021288 load */
    /* @4021296 constant */
    /* @4021300 sub */
    /* @4021304 call */
    GM_SITE(vm, 212, 4021304);
    /* @4021312 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @4021320 load */
    /* @4021328 cast */
    /* @4021332 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4021364;
    L_4021336: ;
    /* @4021336 constant */
    /* @4021340 cast */
    /* @4021344 load */
    /* @4021352 call */
    GM_SITE(vm, 212, 4021352);
    /* @4021360 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4021364: ;
    /* @4021364 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021336;
    /* @4021368 constant */
    /* @4021372 cast */
    /* @4021376 load */
    /* @4021384 constant */
    /* @4021388 sub */
    /* @4021392 load */
    /* @4021400 constant */
    /* @4021404 sub */
    /* @4021408 call */
    GM_SITE(vm, 212, 4021408);
    /* @4021416 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @4021424 load */
    /* @4021432 cast */
    /* @4021436 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4021468;
    L_4021440: ;
    /* @4021440 constant */
    /* @4021444 cast */
    /* @4021448 load */
    /* @4021456 call */
    GM_SITE(vm, 212, 4021456);
    /* @4021464 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4021468: ;
    /* @4021468 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021440;
    /* @4021472 constant */
    /* @4021476 cast */
    /* @4021480 load */
    /* @4021488 constant */
    /* @4021492 sub */
    /* @4021496 load */
    /* @4021504 constant */
    /* @4021508 add */
    /* @4021512 call */
    GM_SITE(vm, 212, 4021512);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4021520 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @4021528 load */
    /* @4021536 cast */
    /* @4021540 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4021572;
    L_4021544: ;
    /* @4021544 constant */
    /* @4021548 cast */
    /* @4021552 load */
    /* @4021560 call */
    GM_SITE(vm, 212, 4021560);
    /* @4021568 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4021572: ;
    /* @4021572 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021544;
    /* @4021576 constant */
    /* @4021580 cast */
    /* @4021584 load */
    /* @4021592 constant */
    /* @4021596 sub */
    /* @4021600 load */
    /* @4021608 constant */
    /* @4021612 sub */
    /* @4021616 call */
    GM_SITE(vm, 212, 4021616);
    /* @4021624 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @4021632 load */
    /* @4021640 cast */
    /* @4021644 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4021676;
    L_4021648: ;
    /* @4021648 constant */
    /* @4021652 cast */
    /* @4021656 load */
    /* @4021664 call */
    GM_SITE(vm, 212, 4021664);
    /* @4021672 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4021676: ;
    /* @4021676 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021648;
    /* @4021680 constant */
    /* @4021684 cast */
    /* @4021688 load */
    /* @4021696 constant */
    /* @4021700 sub */
    /* @4021704 load */
    /* @4021712 constant */
    /* @4021716 add */
    /* @4021720 call */
    GM_SITE(vm, 212, 4021720);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4021728 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @4021736 load */
    /* @4021744 cast */
    /* @4021748 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4021780;
    L_4021752: ;
    /* @4021752 constant */
    /* @4021756 cast */
    /* @4021760 load */
    /* @4021768 call */
    GM_SITE(vm, 212, 4021768);
    /* @4021776 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4021780: ;
    /* @4021780 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021752;
    /* @4021784 constant */
    /* @4021788 cast */
    /* @4021792 load */
    /* @4021800 constant */
    /* @4021804 sub */
    /* @4021808 load */
    /* @4021816 constant */
    /* @4021820 sub */
    /* @4021824 call */
    GM_SITE(vm, 212, 4021824);
    /* @4021832 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v35);
    /* @4021840 load */
    /* @4021848 cast */
    /* @4021852 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4021884;
    L_4021856: ;
    /* @4021856 constant */
    /* @4021860 cast */
    /* @4021864 load */
    /* @4021872 call */
    GM_SITE(vm, 212, 4021872);
    /* @4021880 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4021884: ;
    /* @4021884 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021856;
    L_4021888: ;
    /* @4021888 load */
    /* @4021896 constant */
    /* @4021900 cmp */
    /* @4021904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4023460;
    /* @4021908 constant */
    /* @4021912 cast */
    /* @4021916 load */
    /* @4021924 constant */
    /* @4021928 sub */
    /* @4021932 load */
    /* @4021940 call */
    GM_SITE(vm, 212, 4021940);
    /* @4021948 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v36);
    /* @4021956 load */
    /* @4021964 cast */
    /* @4021968 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4022000;
    L_4021972: ;
    /* @4021972 constant */
    /* @4021976 cast */
    /* @4021980 load */
    /* @4021988 call */
    GM_SITE(vm, 212, 4021988);
    /* @4021996 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4022000: ;
    /* @4022000 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4021972;
    /* @4022004 constant */
    /* @4022008 cast */
    /* @4022012 load */
    /* @4022020 constant */
    /* @4022024 sub */
    /* @4022028 load */
    /* @4022036 constant */
    /* @4022040 add */
    /* @4022044 call */
    GM_SITE(vm, 212, 4022044);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4022052 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v38);
    /* @4022060 load */
    /* @4022068 cast */
    /* @4022072 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4022104;
    L_4022076: ;
    /* @4022076 constant */
    /* @4022080 cast */
    /* @4022084 load */
    /* @4022092 call */
    GM_SITE(vm, 212, 4022092);
    /* @4022100 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4022104: ;
    /* @4022104 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022076;
    /* @4022108 constant */
    /* @4022112 cast */
    /* @4022116 load */
    /* @4022124 constant */
    /* @4022128 sub */
    /* @4022132 load */
    /* @4022140 constant */
    /* @4022144 sub */
    /* @4022148 call */
    GM_SITE(vm, 212, 4022148);
    /* @4022156 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v39);
    /* @4022164 load */
    /* @4022172 cast */
    /* @4022176 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4022208;
    L_4022180: ;
    /* @4022180 constant */
    /* @4022184 cast */
    /* @4022188 load */
    /* @4022196 call */
    GM_SITE(vm, 212, 4022196);
    /* @4022204 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4022208: ;
    /* @4022208 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022180;
    /* @4022212 constant */
    /* @4022216 cast */
    /* @4022220 load */
    /* @4022228 constant */
    /* @4022232 sub */
    /* @4022236 load */
    /* @4022244 constant */
    /* @4022248 add */
    /* @4022252 call */
    GM_SITE(vm, 212, 4022252);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4022260 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v41);
    /* @4022268 load */
    /* @4022276 cast */
    /* @4022280 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4022312;
    L_4022284: ;
    /* @4022284 constant */
    /* @4022288 cast */
    /* @4022292 load */
    /* @4022300 call */
    GM_SITE(vm, 212, 4022300);
    /* @4022308 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4022312: ;
    /* @4022312 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022284;
    /* @4022316 constant */
    /* @4022320 cast */
    /* @4022324 load */
    /* @4022332 constant */
    /* @4022336 sub */
    /* @4022340 load */
    /* @4022348 constant */
    /* @4022352 sub */
    /* @4022356 call */
    GM_SITE(vm, 212, 4022356);
    /* @4022364 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v42);
    /* @4022372 load */
    /* @4022380 cast */
    /* @4022384 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4022416;
    L_4022388: ;
    /* @4022388 constant */
    /* @4022392 cast */
    /* @4022396 load */
    /* @4022404 call */
    GM_SITE(vm, 212, 4022404);
    /* @4022412 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4022416: ;
    /* @4022416 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022388;
    /* @4022420 constant */
    /* @4022424 cast */
    /* @4022428 load */
    /* @4022436 constant */
    /* @4022440 sub */
    /* @4022444 load */
    /* @4022452 constant */
    /* @4022456 sub */
    /* @4022460 call */
    GM_SITE(vm, 212, 4022460);
    /* @4022468 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @4022476 load */
    /* @4022484 cast */
    /* @4022488 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4022520;
    L_4022492: ;
    /* @4022492 constant */
    /* @4022496 cast */
    /* @4022500 load */
    /* @4022508 call */
    GM_SITE(vm, 212, 4022508);
    /* @4022516 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4022520: ;
    /* @4022520 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022492;
    /* @4022524 constant */
    /* @4022528 cast */
    /* @4022532 load */
    /* @4022540 constant */
    /* @4022544 sub */
    /* @4022548 load */
    /* @4022556 constant */
    /* @4022560 add */
    /* @4022564 call */
    GM_SITE(vm, 212, 4022564);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4022572 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @4022580 load */
    /* @4022588 cast */
    /* @4022592 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4022624;
    L_4022596: ;
    /* @4022596 constant */
    /* @4022600 cast */
    /* @4022604 load */
    /* @4022612 call */
    GM_SITE(vm, 212, 4022612);
    /* @4022620 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4022624: ;
    /* @4022624 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022596;
    /* @4022628 constant */
    /* @4022632 cast */
    /* @4022636 load */
    /* @4022644 constant */
    /* @4022648 sub */
    /* @4022652 load */
    /* @4022660 constant */
    /* @4022664 sub */
    /* @4022668 call */
    GM_SITE(vm, 212, 4022668);
    /* @4022676 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @4022684 load */
    /* @4022692 cast */
    /* @4022696 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4022728;
    L_4022700: ;
    /* @4022700 constant */
    /* @4022704 cast */
    /* @4022708 load */
    /* @4022716 call */
    GM_SITE(vm, 212, 4022716);
    /* @4022724 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4022728: ;
    /* @4022728 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022700;
    /* @4022732 constant */
    /* @4022736 cast */
    /* @4022740 load */
    /* @4022748 constant */
    /* @4022752 sub */
    /* @4022756 load */
    /* @4022764 constant */
    /* @4022768 add */
    /* @4022772 call */
    GM_SITE(vm, 212, 4022772);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4022780 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @4022788 load */
    /* @4022796 cast */
    /* @4022800 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4022832;
    L_4022804: ;
    /* @4022804 constant */
    /* @4022808 cast */
    /* @4022812 load */
    /* @4022820 call */
    GM_SITE(vm, 212, 4022820);
    /* @4022828 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4022832: ;
    /* @4022832 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022804;
    /* @4022836 constant */
    /* @4022840 cast */
    /* @4022844 load */
    /* @4022852 constant */
    /* @4022856 sub */
    /* @4022860 load */
    /* @4022868 constant */
    /* @4022872 sub */
    /* @4022876 call */
    GM_SITE(vm, 212, 4022876);
    /* @4022884 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @4022892 load */
    /* @4022900 cast */
    /* @4022904 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4022936;
    L_4022908: ;
    /* @4022908 constant */
    /* @4022912 cast */
    /* @4022916 load */
    /* @4022924 call */
    GM_SITE(vm, 212, 4022924);
    /* @4022932 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4022936: ;
    /* @4022936 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4022908;
    /* @4022940 constant */
    /* @4022944 cast */
    /* @4022948 load */
    /* @4022956 constant */
    /* @4022960 sub */
    /* @4022964 load */
    /* @4022972 constant */
    /* @4022976 add */
    /* @4022980 call */
    GM_SITE(vm, 212, 4022980);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4022988 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v51);
    /* @4022996 load */
    /* @4023004 cast */
    /* @4023008 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4023040;
    L_4023012: ;
    /* @4023012 constant */
    /* @4023016 cast */
    /* @4023020 load */
    /* @4023028 call */
    GM_SITE(vm, 212, 4023028);
    /* @4023036 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4023040: ;
    /* @4023040 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023012;
    /* @4023044 constant */
    /* @4023048 cast */
    /* @4023052 load */
    /* @4023060 constant */
    /* @4023064 sub */
    /* @4023068 load */
    /* @4023076 constant */
    /* @4023080 add */
    /* @4023084 call */
    GM_SITE(vm, 212, 4023084);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4023092 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v53);
    /* @4023100 load */
    /* @4023108 cast */
    /* @4023112 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4023144;
    L_4023116: ;
    /* @4023116 constant */
    /* @4023120 cast */
    /* @4023124 load */
    /* @4023132 call */
    GM_SITE(vm, 212, 4023132);
    /* @4023140 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4023144: ;
    /* @4023144 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023116;
    /* @4023148 constant */
    /* @4023152 cast */
    /* @4023156 load */
    /* @4023164 constant */
    /* @4023168 sub */
    /* @4023172 load */
    /* @4023180 constant */
    /* @4023184 sub */
    /* @4023188 call */
    GM_SITE(vm, 212, 4023188);
    /* @4023196 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v54);
    /* @4023204 load */
    /* @4023212 cast */
    /* @4023216 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4023248;
    L_4023220: ;
    /* @4023220 constant */
    /* @4023224 cast */
    /* @4023228 load */
    /* @4023236 call */
    GM_SITE(vm, 212, 4023236);
    /* @4023244 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4023248: ;
    /* @4023248 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023220;
    /* @4023252 constant */
    /* @4023256 cast */
    /* @4023260 load */
    /* @4023268 constant */
    /* @4023272 sub */
    /* @4023276 load */
    /* @4023284 constant */
    /* @4023288 add */
    /* @4023292 call */
    GM_SITE(vm, 212, 4023292);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4023300 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v56);
    /* @4023308 load */
    /* @4023316 cast */
    /* @4023320 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4023352;
    L_4023324: ;
    /* @4023324 constant */
    /* @4023328 cast */
    /* @4023332 load */
    /* @4023340 call */
    GM_SITE(vm, 212, 4023340);
    /* @4023348 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4023352: ;
    /* @4023352 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023324;
    /* @4023356 constant */
    /* @4023360 cast */
    /* @4023364 load */
    /* @4023372 constant */
    /* @4023376 sub */
    /* @4023380 load */
    /* @4023388 constant */
    /* @4023392 sub */
    /* @4023396 call */
    GM_SITE(vm, 212, 4023396);
    /* @4023404 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v57);
    /* @4023412 load */
    /* @4023420 cast */
    /* @4023424 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4023456;
    L_4023428: ;
    /* @4023428 constant */
    /* @4023432 cast */
    /* @4023436 load */
    /* @4023444 call */
    GM_SITE(vm, 212, 4023444);
    /* @4023452 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4023456: ;
    /* @4023456 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023428;
    L_4023460: ;
    /* @4023460 load */
    /* @4023468 constant */
    /* @4023472 cmp */
    /* @4023476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4025552;
    /* @4023480 constant */
    /* @4023484 cast */
    /* @4023488 load */
    /* @4023496 constant */
    /* @4023500 sub */
    /* @4023504 load */
    /* @4023512 call */
    GM_SITE(vm, 212, 4023512);
    /* @4023520 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v58);
    /* @4023528 load */
    /* @4023536 cast */
    /* @4023540 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4023572;
    L_4023544: ;
    /* @4023544 constant */
    /* @4023548 cast */
    /* @4023552 load */
    /* @4023560 call */
    GM_SITE(vm, 212, 4023560);
    /* @4023568 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4023572: ;
    /* @4023572 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023544;
    /* @4023576 constant */
    /* @4023580 cast */
    /* @4023584 load */
    /* @4023592 constant */
    /* @4023596 sub */
    /* @4023600 load */
    /* @4023608 constant */
    /* @4023612 add */
    /* @4023616 call */
    GM_SITE(vm, 212, 4023616);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4023624 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v60);
    /* @4023632 load */
    /* @4023640 cast */
    /* @4023644 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4023676;
    L_4023648: ;
    /* @4023648 constant */
    /* @4023652 cast */
    /* @4023656 load */
    /* @4023664 call */
    GM_SITE(vm, 212, 4023664);
    /* @4023672 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4023676: ;
    /* @4023676 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023648;
    /* @4023680 constant */
    /* @4023684 cast */
    /* @4023688 load */
    /* @4023696 constant */
    /* @4023700 sub */
    /* @4023704 load */
    /* @4023712 constant */
    /* @4023716 sub */
    /* @4023720 call */
    GM_SITE(vm, 212, 4023720);
    /* @4023728 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v61);
    /* @4023736 load */
    /* @4023744 cast */
    /* @4023748 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4023780;
    L_4023752: ;
    /* @4023752 constant */
    /* @4023756 cast */
    /* @4023760 load */
    /* @4023768 call */
    GM_SITE(vm, 212, 4023768);
    /* @4023776 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4023780: ;
    /* @4023780 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023752;
    /* @4023784 constant */
    /* @4023788 cast */
    /* @4023792 load */
    /* @4023800 constant */
    /* @4023804 sub */
    /* @4023808 load */
    /* @4023816 constant */
    /* @4023820 add */
    /* @4023824 call */
    GM_SITE(vm, 212, 4023824);
    v62 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4023832 store */
    v63 = GM_CALL(vm, "instance_create", 3, v62, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v63);
    /* @4023840 load */
    /* @4023848 cast */
    /* @4023852 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4023884;
    L_4023856: ;
    /* @4023856 constant */
    /* @4023860 cast */
    /* @4023864 load */
    /* @4023872 call */
    GM_SITE(vm, 212, 4023872);
    /* @4023880 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4023884: ;
    /* @4023884 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023856;
    /* @4023888 constant */
    /* @4023892 cast */
    /* @4023896 load */
    /* @4023904 constant */
    /* @4023908 sub */
    /* @4023912 load */
    /* @4023920 constant */
    /* @4023924 sub */
    /* @4023928 call */
    GM_SITE(vm, 212, 4023928);
    /* @4023936 store */
    v64 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v64);
    /* @4023944 load */
    /* @4023952 cast */
    /* @4023956 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4023988;
    L_4023960: ;
    /* @4023960 constant */
    /* @4023964 cast */
    /* @4023968 load */
    /* @4023976 call */
    GM_SITE(vm, 212, 4023976);
    /* @4023984 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4023988: ;
    /* @4023988 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4023960;
    /* @4023992 constant */
    /* @4023996 cast */
    /* @4024000 load */
    /* @4024008 constant */
    /* @4024012 sub */
    /* @4024016 load */
    /* @4024024 constant */
    /* @4024028 add */
    /* @4024032 call */
    GM_SITE(vm, 212, 4024032);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4024040 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v66);
    /* @4024048 load */
    /* @4024056 cast */
    /* @4024060 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4024092;
    L_4024064: ;
    /* @4024064 constant */
    /* @4024068 cast */
    /* @4024072 load */
    /* @4024080 call */
    GM_SITE(vm, 212, 4024080);
    /* @4024088 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4024092: ;
    /* @4024092 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024064;
    /* @4024096 constant */
    /* @4024100 cast */
    /* @4024104 load */
    /* @4024112 constant */
    /* @4024116 sub */
    /* @4024120 load */
    /* @4024128 constant */
    /* @4024132 add */
    /* @4024136 call */
    GM_SITE(vm, 212, 4024136);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4024144 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v68);
    /* @4024152 load */
    /* @4024160 cast */
    /* @4024164 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4024196;
    L_4024168: ;
    /* @4024168 constant */
    /* @4024172 cast */
    /* @4024176 load */
    /* @4024184 call */
    GM_SITE(vm, 212, 4024184);
    /* @4024192 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4024196: ;
    /* @4024196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024168;
    /* @4024200 constant */
    /* @4024204 cast */
    /* @4024208 load */
    /* @4024216 constant */
    /* @4024220 sub */
    /* @4024224 load */
    /* @4024232 constant */
    /* @4024236 sub */
    /* @4024240 call */
    GM_SITE(vm, 212, 4024240);
    /* @4024248 store */
    v69 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v69);
    /* @4024256 load */
    /* @4024264 cast */
    /* @4024268 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4024300;
    L_4024272: ;
    /* @4024272 constant */
    /* @4024276 cast */
    /* @4024280 load */
    /* @4024288 call */
    GM_SITE(vm, 212, 4024288);
    /* @4024296 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4024300: ;
    /* @4024300 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024272;
    /* @4024304 constant */
    /* @4024308 cast */
    /* @4024312 load */
    /* @4024320 constant */
    /* @4024324 sub */
    /* @4024328 load */
    /* @4024336 constant */
    /* @4024340 add */
    /* @4024344 call */
    GM_SITE(vm, 212, 4024344);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4024352 store */
    v71 = GM_CALL(vm, "instance_create", 3, v70, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v71);
    /* @4024360 load */
    /* @4024368 cast */
    /* @4024372 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4024404;
    L_4024376: ;
    /* @4024376 constant */
    /* @4024380 cast */
    /* @4024384 load */
    /* @4024392 call */
    GM_SITE(vm, 212, 4024392);
    /* @4024400 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4024404: ;
    /* @4024404 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024376;
    /* @4024408 constant */
    /* @4024412 cast */
    /* @4024416 load */
    /* @4024424 constant */
    /* @4024428 sub */
    /* @4024432 load */
    /* @4024440 constant */
    /* @4024444 sub */
    /* @4024448 call */
    GM_SITE(vm, 212, 4024448);
    /* @4024456 store */
    v72 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v72);
    /* @4024464 load */
    /* @4024472 cast */
    /* @4024476 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4024508;
    L_4024480: ;
    /* @4024480 constant */
    /* @4024484 cast */
    /* @4024488 load */
    /* @4024496 call */
    GM_SITE(vm, 212, 4024496);
    /* @4024504 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4024508: ;
    /* @4024508 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024480;
    /* @4024512 constant */
    /* @4024516 cast */
    /* @4024520 load */
    /* @4024528 constant */
    /* @4024532 sub */
    /* @4024536 load */
    /* @4024544 constant */
    /* @4024548 sub */
    /* @4024552 call */
    GM_SITE(vm, 212, 4024552);
    /* @4024560 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v73);
    /* @4024568 load */
    /* @4024576 cast */
    /* @4024580 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4024612;
    L_4024584: ;
    /* @4024584 constant */
    /* @4024588 cast */
    /* @4024592 load */
    /* @4024600 call */
    GM_SITE(vm, 212, 4024600);
    /* @4024608 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4024612: ;
    /* @4024612 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024584;
    /* @4024616 constant */
    /* @4024620 cast */
    /* @4024624 load */
    /* @4024632 constant */
    /* @4024636 sub */
    /* @4024640 load */
    /* @4024648 constant */
    /* @4024652 add */
    /* @4024656 call */
    GM_SITE(vm, 212, 4024656);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4024664 store */
    v75 = GM_CALL(vm, "instance_create", 3, v74, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v75);
    /* @4024672 load */
    /* @4024680 cast */
    /* @4024684 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4024716;
    L_4024688: ;
    /* @4024688 constant */
    /* @4024692 cast */
    /* @4024696 load */
    /* @4024704 call */
    GM_SITE(vm, 212, 4024704);
    /* @4024712 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4024716: ;
    /* @4024716 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024688;
    /* @4024720 constant */
    /* @4024724 cast */
    /* @4024728 load */
    /* @4024736 constant */
    /* @4024740 sub */
    /* @4024744 load */
    /* @4024752 constant */
    /* @4024756 sub */
    /* @4024760 call */
    GM_SITE(vm, 212, 4024760);
    /* @4024768 store */
    v76 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v76);
    /* @4024776 load */
    /* @4024784 cast */
    /* @4024788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4024820;
    L_4024792: ;
    /* @4024792 constant */
    /* @4024796 cast */
    /* @4024800 load */
    /* @4024808 call */
    GM_SITE(vm, 212, 4024808);
    /* @4024816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4024820: ;
    /* @4024820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024792;
    /* @4024824 constant */
    /* @4024828 cast */
    /* @4024832 load */
    /* @4024840 constant */
    /* @4024844 sub */
    /* @4024848 load */
    /* @4024856 constant */
    /* @4024860 add */
    /* @4024864 call */
    GM_SITE(vm, 212, 4024864);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4024872 store */
    v78 = GM_CALL(vm, "instance_create", 3, v77, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v78);
    /* @4024880 load */
    /* @4024888 cast */
    /* @4024892 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4024924;
    L_4024896: ;
    /* @4024896 constant */
    /* @4024900 cast */
    /* @4024904 load */
    /* @4024912 call */
    GM_SITE(vm, 212, 4024912);
    /* @4024920 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4024924: ;
    /* @4024924 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4024896;
    /* @4024928 constant */
    /* @4024932 cast */
    /* @4024936 load */
    /* @4024944 constant */
    /* @4024948 sub */
    /* @4024952 load */
    /* @4024960 constant */
    /* @4024964 sub */
    /* @4024968 call */
    GM_SITE(vm, 212, 4024968);
    /* @4024976 store */
    v79 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v79);
    /* @4024984 load */
    /* @4024992 cast */
    /* @4024996 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4025028;
    L_4025000: ;
    /* @4025000 constant */
    /* @4025004 cast */
    /* @4025008 load */
    /* @4025016 call */
    GM_SITE(vm, 212, 4025016);
    /* @4025024 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4025028: ;
    /* @4025028 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025000;
    /* @4025032 constant */
    /* @4025036 cast */
    /* @4025040 load */
    /* @4025048 constant */
    /* @4025052 sub */
    /* @4025056 load */
    /* @4025064 constant */
    /* @4025068 sub */
    /* @4025072 call */
    GM_SITE(vm, 212, 4025072);
    /* @4025080 store */
    v80 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v80);
    /* @4025088 load */
    /* @4025096 cast */
    /* @4025100 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4025132;
    L_4025104: ;
    /* @4025104 constant */
    /* @4025108 cast */
    /* @4025112 load */
    /* @4025120 call */
    GM_SITE(vm, 212, 4025120);
    /* @4025128 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4025132: ;
    /* @4025132 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025104;
    /* @4025136 constant */
    /* @4025140 cast */
    /* @4025144 load */
    /* @4025152 constant */
    /* @4025156 sub */
    /* @4025160 load */
    /* @4025168 constant */
    /* @4025172 add */
    /* @4025176 call */
    GM_SITE(vm, 212, 4025176);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4025184 store */
    v82 = GM_CALL(vm, "instance_create", 3, v81, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v82);
    /* @4025192 load */
    /* @4025200 cast */
    /* @4025204 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4025236;
    L_4025208: ;
    /* @4025208 constant */
    /* @4025212 cast */
    /* @4025216 load */
    /* @4025224 call */
    GM_SITE(vm, 212, 4025224);
    /* @4025232 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4025236: ;
    /* @4025236 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025208;
    /* @4025240 constant */
    /* @4025244 cast */
    /* @4025248 load */
    /* @4025256 constant */
    /* @4025260 sub */
    /* @4025264 load */
    /* @4025272 constant */
    /* @4025276 sub */
    /* @4025280 call */
    GM_SITE(vm, 212, 4025280);
    /* @4025288 store */
    v83 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v83);
    /* @4025296 load */
    /* @4025304 cast */
    /* @4025308 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4025340;
    L_4025312: ;
    /* @4025312 constant */
    /* @4025316 cast */
    /* @4025320 load */
    /* @4025328 call */
    GM_SITE(vm, 212, 4025328);
    /* @4025336 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4025340: ;
    /* @4025340 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025312;
    /* @4025344 constant */
    /* @4025348 cast */
    /* @4025352 load */
    /* @4025360 constant */
    /* @4025364 sub */
    /* @4025368 load */
    /* @4025376 constant */
    /* @4025380 add */
    /* @4025384 call */
    GM_SITE(vm, 212, 4025384);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4025392 store */
    v85 = GM_CALL(vm, "instance_create", 3, v84, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v85);
    /* @4025400 load */
    /* @4025408 cast */
    /* @4025412 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4025444;
    L_4025416: ;
    /* @4025416 constant */
    /* @4025420 cast */
    /* @4025424 load */
    /* @4025432 call */
    GM_SITE(vm, 212, 4025432);
    /* @4025440 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4025444: ;
    /* @4025444 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025416;
    /* @4025448 constant */
    /* @4025452 cast */
    /* @4025456 load */
    /* @4025464 constant */
    /* @4025468 sub */
    /* @4025472 load */
    /* @4025480 constant */
    /* @4025484 sub */
    /* @4025488 call */
    GM_SITE(vm, 212, 4025488);
    /* @4025496 store */
    v86 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v86);
    /* @4025504 load */
    /* @4025512 cast */
    /* @4025516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4025548;
    L_4025520: ;
    /* @4025520 constant */
    /* @4025524 cast */
    /* @4025528 load */
    /* @4025536 call */
    GM_SITE(vm, 212, 4025536);
    /* @4025544 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4025548: ;
    /* @4025548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025520;
    L_4025552: ;
    /* @4025552 load */
    /* @4025560 constant */
    /* @4025564 cmp */
    /* @4025568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4028164;
    /* @4025572 constant */
    /* @4025576 cast */
    /* @4025580 load */
    /* @4025588 constant */
    /* @4025592 sub */
    /* @4025596 load */
    /* @4025604 call */
    GM_SITE(vm, 212, 4025604);
    /* @4025612 store */
    v87 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v87);
    /* @4025620 load */
    /* @4025628 cast */
    /* @4025632 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4025664;
    L_4025636: ;
    /* @4025636 constant */
    /* @4025640 cast */
    /* @4025644 load */
    /* @4025652 call */
    GM_SITE(vm, 212, 4025652);
    /* @4025660 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4025664: ;
    /* @4025664 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025636;
    /* @4025668 constant */
    /* @4025672 cast */
    /* @4025676 load */
    /* @4025684 constant */
    /* @4025688 sub */
    /* @4025692 load */
    /* @4025700 constant */
    /* @4025704 add */
    /* @4025708 call */
    GM_SITE(vm, 212, 4025708);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4025716 store */
    v89 = GM_CALL(vm, "instance_create", 3, v88, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v89);
    /* @4025724 load */
    /* @4025732 cast */
    /* @4025736 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4025768;
    L_4025740: ;
    /* @4025740 constant */
    /* @4025744 cast */
    /* @4025748 load */
    /* @4025756 call */
    GM_SITE(vm, 212, 4025756);
    /* @4025764 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4025768: ;
    /* @4025768 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025740;
    /* @4025772 constant */
    /* @4025776 cast */
    /* @4025780 load */
    /* @4025788 constant */
    /* @4025792 sub */
    /* @4025796 load */
    /* @4025804 constant */
    /* @4025808 sub */
    /* @4025812 call */
    GM_SITE(vm, 212, 4025812);
    /* @4025820 store */
    v90 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v90);
    /* @4025828 load */
    /* @4025836 cast */
    /* @4025840 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4025872;
    L_4025844: ;
    /* @4025844 constant */
    /* @4025848 cast */
    /* @4025852 load */
    /* @4025860 call */
    GM_SITE(vm, 212, 4025860);
    /* @4025868 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4025872: ;
    /* @4025872 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025844;
    /* @4025876 constant */
    /* @4025880 cast */
    /* @4025884 load */
    /* @4025892 constant */
    /* @4025896 sub */
    /* @4025900 load */
    /* @4025908 constant */
    /* @4025912 add */
    /* @4025916 call */
    GM_SITE(vm, 212, 4025916);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4025924 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v92);
    /* @4025932 load */
    /* @4025940 cast */
    /* @4025944 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4025976;
    L_4025948: ;
    /* @4025948 constant */
    /* @4025952 cast */
    /* @4025956 load */
    /* @4025964 call */
    GM_SITE(vm, 212, 4025964);
    /* @4025972 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4025976: ;
    /* @4025976 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4025948;
    /* @4025980 constant */
    /* @4025984 cast */
    /* @4025988 load */
    /* @4025996 constant */
    /* @4026000 sub */
    /* @4026004 load */
    /* @4026012 constant */
    /* @4026016 sub */
    /* @4026020 call */
    GM_SITE(vm, 212, 4026020);
    /* @4026028 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v93);
    /* @4026036 load */
    /* @4026044 cast */
    /* @4026048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4026080;
    L_4026052: ;
    /* @4026052 constant */
    /* @4026056 cast */
    /* @4026060 load */
    /* @4026068 call */
    GM_SITE(vm, 212, 4026068);
    /* @4026076 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4026080: ;
    /* @4026080 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026052;
    /* @4026084 constant */
    /* @4026088 cast */
    /* @4026092 load */
    /* @4026100 constant */
    /* @4026104 sub */
    /* @4026108 load */
    /* @4026116 constant */
    /* @4026120 add */
    /* @4026124 call */
    GM_SITE(vm, 212, 4026124);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4026132 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v95);
    /* @4026140 load */
    /* @4026148 cast */
    /* @4026152 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4026184;
    L_4026156: ;
    /* @4026156 constant */
    /* @4026160 cast */
    /* @4026164 load */
    /* @4026172 call */
    GM_SITE(vm, 212, 4026172);
    /* @4026180 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4026184: ;
    /* @4026184 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026156;
    /* @4026188 constant */
    /* @4026192 cast */
    /* @4026196 load */
    /* @4026204 constant */
    /* @4026208 sub */
    /* @4026212 load */
    /* @4026220 constant */
    /* @4026224 add */
    /* @4026228 call */
    GM_SITE(vm, 212, 4026228);
    v96 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4026236 store */
    v97 = GM_CALL(vm, "instance_create", 3, v96, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v97);
    /* @4026244 load */
    /* @4026252 cast */
    /* @4026256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4026288;
    L_4026260: ;
    /* @4026260 constant */
    /* @4026264 cast */
    /* @4026268 load */
    /* @4026276 call */
    GM_SITE(vm, 212, 4026276);
    /* @4026284 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4026288: ;
    /* @4026288 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026260;
    /* @4026292 constant */
    /* @4026296 cast */
    /* @4026300 load */
    /* @4026308 constant */
    /* @4026312 sub */
    /* @4026316 load */
    /* @4026324 constant */
    /* @4026328 sub */
    /* @4026332 call */
    GM_SITE(vm, 212, 4026332);
    /* @4026340 store */
    v98 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v98);
    /* @4026348 load */
    /* @4026356 cast */
    /* @4026360 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4026392;
    L_4026364: ;
    /* @4026364 constant */
    /* @4026368 cast */
    /* @4026372 load */
    /* @4026380 call */
    GM_SITE(vm, 212, 4026380);
    /* @4026388 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4026392: ;
    /* @4026392 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026364;
    /* @4026396 constant */
    /* @4026400 cast */
    /* @4026404 load */
    /* @4026412 constant */
    /* @4026416 sub */
    /* @4026420 load */
    /* @4026428 constant */
    /* @4026432 add */
    /* @4026436 call */
    GM_SITE(vm, 212, 4026436);
    v99 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4026444 store */
    v100 = GM_CALL(vm, "instance_create", 3, v99, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v100);
    /* @4026452 load */
    /* @4026460 cast */
    /* @4026464 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4026496;
    L_4026468: ;
    /* @4026468 constant */
    /* @4026472 cast */
    /* @4026476 load */
    /* @4026484 call */
    GM_SITE(vm, 212, 4026484);
    /* @4026492 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4026496: ;
    /* @4026496 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026468;
    /* @4026500 constant */
    /* @4026504 cast */
    /* @4026508 load */
    /* @4026516 constant */
    /* @4026520 sub */
    /* @4026524 load */
    /* @4026532 constant */
    /* @4026536 sub */
    /* @4026540 call */
    GM_SITE(vm, 212, 4026540);
    /* @4026548 store */
    v101 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v101);
    /* @4026556 load */
    /* @4026564 cast */
    /* @4026568 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4026600;
    L_4026572: ;
    /* @4026572 constant */
    /* @4026576 cast */
    /* @4026580 load */
    /* @4026588 call */
    GM_SITE(vm, 212, 4026588);
    /* @4026596 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4026600: ;
    /* @4026600 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026572;
    /* @4026604 constant */
    /* @4026608 cast */
    /* @4026612 load */
    /* @4026620 constant */
    /* @4026624 sub */
    /* @4026628 load */
    /* @4026636 constant */
    /* @4026640 sub */
    /* @4026644 call */
    GM_SITE(vm, 212, 4026644);
    /* @4026652 store */
    v102 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v102);
    /* @4026660 load */
    /* @4026668 cast */
    /* @4026672 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4026704;
    L_4026676: ;
    /* @4026676 constant */
    /* @4026680 cast */
    /* @4026684 load */
    /* @4026692 call */
    GM_SITE(vm, 212, 4026692);
    /* @4026700 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4026704: ;
    /* @4026704 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026676;
    /* @4026708 constant */
    /* @4026712 cast */
    /* @4026716 load */
    /* @4026724 constant */
    /* @4026728 sub */
    /* @4026732 load */
    /* @4026740 constant */
    /* @4026744 add */
    /* @4026748 call */
    GM_SITE(vm, 212, 4026748);
    v103 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4026756 store */
    v104 = GM_CALL(vm, "instance_create", 3, v103, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v104);
    /* @4026764 load */
    /* @4026772 cast */
    /* @4026776 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4026808;
    L_4026780: ;
    /* @4026780 constant */
    /* @4026784 cast */
    /* @4026788 load */
    /* @4026796 call */
    GM_SITE(vm, 212, 4026796);
    /* @4026804 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4026808: ;
    /* @4026808 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026780;
    /* @4026812 constant */
    /* @4026816 cast */
    /* @4026820 load */
    /* @4026828 constant */
    /* @4026832 sub */
    /* @4026836 load */
    /* @4026844 constant */
    /* @4026848 sub */
    /* @4026852 call */
    GM_SITE(vm, 212, 4026852);
    /* @4026860 store */
    v105 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v105);
    /* @4026868 load */
    /* @4026876 cast */
    /* @4026880 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4026912;
    L_4026884: ;
    /* @4026884 constant */
    /* @4026888 cast */
    /* @4026892 load */
    /* @4026900 call */
    GM_SITE(vm, 212, 4026900);
    /* @4026908 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4026912: ;
    /* @4026912 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026884;
    /* @4026916 constant */
    /* @4026920 cast */
    /* @4026924 load */
    /* @4026932 constant */
    /* @4026936 sub */
    /* @4026940 load */
    /* @4026948 constant */
    /* @4026952 add */
    /* @4026956 call */
    GM_SITE(vm, 212, 4026956);
    v106 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4026964 store */
    v107 = GM_CALL(vm, "instance_create", 3, v106, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v107);
    /* @4026972 load */
    /* @4026980 cast */
    /* @4026984 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4027016;
    L_4026988: ;
    /* @4026988 constant */
    /* @4026992 cast */
    /* @4026996 load */
    /* @4027004 call */
    GM_SITE(vm, 212, 4027004);
    /* @4027012 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4027016: ;
    /* @4027016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4026988;
    /* @4027020 constant */
    /* @4027024 cast */
    /* @4027028 load */
    /* @4027036 constant */
    /* @4027040 sub */
    /* @4027044 load */
    /* @4027052 constant */
    /* @4027056 sub */
    /* @4027060 call */
    GM_SITE(vm, 212, 4027060);
    /* @4027068 store */
    v108 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v108);
    /* @4027076 load */
    /* @4027084 cast */
    /* @4027088 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4027120;
    L_4027092: ;
    /* @4027092 constant */
    /* @4027096 cast */
    /* @4027100 load */
    /* @4027108 call */
    GM_SITE(vm, 212, 4027108);
    /* @4027116 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4027120: ;
    /* @4027120 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027092;
    /* @4027124 constant */
    /* @4027128 cast */
    /* @4027132 load */
    /* @4027140 constant */
    /* @4027144 sub */
    /* @4027148 load */
    /* @4027156 constant */
    /* @4027160 add */
    /* @4027164 call */
    GM_SITE(vm, 212, 4027164);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), VAL(15));
    /* @4027172 store */
    v110 = GM_CALL(vm, "instance_create", 3, v109, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v110);
    /* @4027180 load */
    /* @4027188 cast */
    /* @4027192 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4027224;
    L_4027196: ;
    /* @4027196 constant */
    /* @4027200 cast */
    /* @4027204 load */
    /* @4027212 call */
    GM_SITE(vm, 212, 4027212);
    /* @4027220 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4027224: ;
    /* @4027224 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027196;
    /* @4027228 constant */
    /* @4027232 cast */
    /* @4027236 load */
    /* @4027244 constant */
    /* @4027248 sub */
    /* @4027252 load */
    /* @4027260 constant */
    /* @4027264 add */
    /* @4027268 call */
    GM_SITE(vm, 212, 4027268);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4027276 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v112);
    /* @4027284 load */
    /* @4027292 cast */
    /* @4027296 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4027328;
    L_4027300: ;
    /* @4027300 constant */
    /* @4027304 cast */
    /* @4027308 load */
    /* @4027316 call */
    GM_SITE(vm, 212, 4027316);
    /* @4027324 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4027328: ;
    /* @4027328 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027300;
    /* @4027332 constant */
    /* @4027336 cast */
    /* @4027340 load */
    /* @4027348 constant */
    /* @4027352 sub */
    /* @4027356 load */
    /* @4027364 constant */
    /* @4027368 sub */
    /* @4027372 call */
    GM_SITE(vm, 212, 4027372);
    /* @4027380 store */
    v113 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v113);
    /* @4027388 load */
    /* @4027396 cast */
    /* @4027400 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4027432;
    L_4027404: ;
    /* @4027404 constant */
    /* @4027408 cast */
    /* @4027412 load */
    /* @4027420 call */
    GM_SITE(vm, 212, 4027420);
    /* @4027428 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4027432: ;
    /* @4027432 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027404;
    /* @4027436 constant */
    /* @4027440 cast */
    /* @4027444 load */
    /* @4027452 constant */
    /* @4027456 sub */
    /* @4027460 load */
    /* @4027468 constant */
    /* @4027472 add */
    /* @4027476 call */
    GM_SITE(vm, 212, 4027476);
    v114 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4027484 store */
    v115 = GM_CALL(vm, "instance_create", 3, v114, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v115);
    /* @4027492 load */
    /* @4027500 cast */
    /* @4027504 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4027536;
    L_4027508: ;
    /* @4027508 constant */
    /* @4027512 cast */
    /* @4027516 load */
    /* @4027524 call */
    GM_SITE(vm, 212, 4027524);
    /* @4027532 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4027536: ;
    /* @4027536 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027508;
    /* @4027540 constant */
    /* @4027544 cast */
    /* @4027548 load */
    /* @4027556 constant */
    /* @4027560 sub */
    /* @4027564 load */
    /* @4027572 constant */
    /* @4027576 sub */
    /* @4027580 call */
    GM_SITE(vm, 212, 4027580);
    /* @4027588 store */
    v116 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v116);
    /* @4027596 load */
    /* @4027604 cast */
    /* @4027608 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4027640;
    L_4027612: ;
    /* @4027612 constant */
    /* @4027616 cast */
    /* @4027620 load */
    /* @4027628 call */
    GM_SITE(vm, 212, 4027628);
    /* @4027636 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4027640: ;
    /* @4027640 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027612;
    /* @4027644 constant */
    /* @4027648 cast */
    /* @4027652 load */
    /* @4027660 constant */
    /* @4027664 sub */
    /* @4027668 load */
    /* @4027676 constant */
    /* @4027680 sub */
    /* @4027684 call */
    GM_SITE(vm, 212, 4027684);
    /* @4027692 store */
    v117 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(15)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID21", v117);
    /* @4027700 load */
    /* @4027708 cast */
    /* @4027712 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID21")))) goto L_4027744;
    L_4027716: ;
    /* @4027716 constant */
    /* @4027720 cast */
    /* @4027724 load */
    /* @4027732 call */
    GM_SITE(vm, 212, 4027732);
    /* @4027740 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread21"), VAL(5)));
    L_4027744: ;
    /* @4027744 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027716;
    /* @4027748 constant */
    /* @4027752 cast */
    /* @4027756 load */
    /* @4027764 constant */
    /* @4027768 sub */
    /* @4027772 load */
    /* @4027780 constant */
    /* @4027784 add */
    /* @4027788 call */
    GM_SITE(vm, 212, 4027788);
    v118 = GM_ADD(GM_READ(vm, -1, "x"), VAL(18));
    /* @4027796 store */
    v119 = GM_CALL(vm, "instance_create", 3, v118, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID22", v119);
    /* @4027804 load */
    /* @4027812 cast */
    /* @4027816 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID22")))) goto L_4027848;
    L_4027820: ;
    /* @4027820 constant */
    /* @4027824 cast */
    /* @4027828 load */
    /* @4027836 call */
    GM_SITE(vm, 212, 4027836);
    /* @4027844 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread22"), VAL(5)));
    L_4027848: ;
    /* @4027848 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027820;
    /* @4027852 constant */
    /* @4027856 cast */
    /* @4027860 load */
    /* @4027868 constant */
    /* @4027872 sub */
    /* @4027876 load */
    /* @4027884 constant */
    /* @4027888 sub */
    /* @4027892 call */
    GM_SITE(vm, 212, 4027892);
    /* @4027900 store */
    v120 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID23", v120);
    /* @4027908 load */
    /* @4027916 cast */
    /* @4027920 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID23")))) goto L_4027952;
    L_4027924: ;
    /* @4027924 constant */
    /* @4027928 cast */
    /* @4027932 load */
    /* @4027940 call */
    GM_SITE(vm, 212, 4027940);
    /* @4027948 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(5)));
    L_4027952: ;
    /* @4027952 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4027924;
    /* @4027956 constant */
    /* @4027960 cast */
    /* @4027964 load */
    /* @4027972 constant */
    /* @4027976 sub */
    /* @4027980 load */
    /* @4027988 constant */
    /* @4027992 add */
    /* @4027996 call */
    GM_SITE(vm, 212, 4027996);
    v121 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4028004 store */
    v122 = GM_CALL(vm, "instance_create", 3, v121, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID24", v122);
    /* @4028012 load */
    /* @4028020 cast */
    /* @4028024 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID24")))) goto L_4028056;
    L_4028028: ;
    /* @4028028 constant */
    /* @4028032 cast */
    /* @4028036 load */
    /* @4028044 call */
    GM_SITE(vm, 212, 4028044);
    /* @4028052 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread24"), VAL(5)));
    L_4028056: ;
    /* @4028056 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4028028;
    /* @4028060 constant */
    /* @4028064 cast */
    /* @4028068 load */
    /* @4028076 constant */
    /* @4028080 sub */
    /* @4028084 load */
    /* @4028092 constant */
    /* @4028096 sub */
    /* @4028100 call */
    GM_SITE(vm, 212, 4028100);
    /* @4028108 store */
    v123 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID25", v123);
    /* @4028116 load */
    /* @4028124 cast */
    /* @4028128 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID25")))) goto L_4028160;
    L_4028132: ;
    /* @4028132 constant */
    /* @4028136 cast */
    /* @4028140 load */
    /* @4028148 call */
    GM_SITE(vm, 212, 4028148);
    /* @4028156 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(5)));
    L_4028160: ;
    /* @4028160 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4028132;
    L_4028164: ;
    /* @4028164 call */
    GM_SITE(vm, 212, 4028164);
    /* @4028172 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_4028176: ;
    return;
}
