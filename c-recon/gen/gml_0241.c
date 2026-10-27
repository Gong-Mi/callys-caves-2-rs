/* generated from CODE 241 (gml_Object_obj_bat_Alarm_0), source start 4033092, end 4040000. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0241(GmVM* vm) {
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
    Val v124;
    Val v125;
    Val v126;
    Val v127;
    Val v128;
    Val v129;
    /* @4033092 load */
    /* @4033100 constant */
    /* @4033104 cmp */
    /* @4033108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4033116;
    /* @4033112 b */
    goto L_4033172;
    L_4033116: ;
    /* @4033116 load */
    /* @4033124 constant */
    /* @4033128 cmp */
    /* @4033132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4033172;
    /* @4033136 constant */
    /* @4033140 cast */
    /* @4033144 constant */
    /* @4033148 cast */
    /* @4033152 constant */
    /* @4033156 cast */
    /* @4033160 call */
    GM_SITE(vm, 241, 4033160);
    /* @4033168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4033172: ;
    /* @4033172 constant */
    /* @4033176 cast */
    /* @4033180 load */
    /* @4033188 constant */
    /* @4033192 sub */
    /* @4033196 load */
    /* @4033204 call */
    GM_SITE(vm, 241, 4033204);
    /* @4033212 cast */
    /* @4033216 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(4)), VAL(34)));
    if (!TRUTH(v1)) goto L_4036708;
    /* @4033220 load */
    /* @4033228 constant */
    /* @4033232 cmp */
    /* @4033236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4033284;
    /* @4033240 constant */
    /* @4033244 cast */
    /* @4033248 load */
    /* @4033256 constant */
    /* @4033260 add */
    /* @4033264 load */
    /* @4033272 call */
    GM_SITE(vm, 241, 4033272);
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033280 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v2, VAL(62)));
    L_4033284: ;
    /* @4033284 load */
    /* @4033292 constant */
    /* @4033296 cmp */
    /* @4033300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4033348;
    /* @4033304 constant */
    /* @4033308 cast */
    /* @4033312 load */
    /* @4033320 constant */
    /* @4033324 add */
    /* @4033328 load */
    /* @4033336 call */
    GM_SITE(vm, 241, 4033336);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033344 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v3, VAL(59)));
    L_4033348: ;
    /* @4033348 load */
    /* @4033356 constant */
    /* @4033360 cmp */
    /* @4033364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4033464;
    /* @4033368 constant */
    /* @4033372 cast */
    /* @4033376 load */
    /* @4033384 constant */
    /* @4033388 add */
    /* @4033392 load */
    /* @4033400 call */
    GM_SITE(vm, 241, 4033400);
    v4 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033408 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v4, VAL(61));
    GM_WRITE(vm, -1, "ID", v5);
    /* @4033416 load */
    /* @4033424 cast */
    /* @4033428 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4033460;
    L_4033432: ;
    /* @4033432 constant */
    /* @4033436 cast */
    /* @4033440 load */
    /* @4033448 call */
    GM_SITE(vm, 241, 4033448);
    /* @4033456 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_4033460: ;
    /* @4033460 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4033432;
    L_4033464: ;
    /* @4033464 constant */
    /* @4033468 cast */
    /* @4033472 call */
    GM_SITE(vm, 241, 4033472);
    /* @4033480 constant */
    /* @4033484 cmp */
    /* @4033488 bf */
    v6 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v6)) goto L_4033496;
    /* @4033492 b */
    goto L_4036704;
    L_4033496: ;
    /* @4033496 constant */
    /* @4033500 cast */
    /* @4033504 call */
    GM_SITE(vm, 241, 4033504);
    /* @4033512 constant */
    /* @4033516 cmp */
    /* @4033520 bf */
    v7 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v7)) goto L_4036704;
    /* @4033524 load */
    /* @4033532 constant */
    /* @4033536 cmp */
    /* @4033540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4033848;
    /* @4033544 constant */
    /* @4033548 cast */
    /* @4033552 load */
    /* @4033560 constant */
    /* @4033564 add */
    /* @4033568 load */
    /* @4033576 call */
    GM_SITE(vm, 241, 4033576);
    v8 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033584 store */
    v9 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v8, VAL(60));
    GM_WRITE(vm, -1, "ID", v9);
    /* @4033592 load */
    /* @4033600 cast */
    /* @4033604 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4033636;
    L_4033608: ;
    /* @4033608 constant */
    /* @4033612 cast */
    /* @4033616 load */
    /* @4033624 call */
    GM_SITE(vm, 241, 4033624);
    /* @4033632 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4033636: ;
    /* @4033636 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4033608;
    /* @4033640 constant */
    /* @4033644 cast */
    /* @4033648 load */
    /* @4033656 constant */
    /* @4033660 add */
    /* @4033664 load */
    /* @4033672 constant */
    /* @4033676 add */
    /* @4033680 call */
    GM_SITE(vm, 241, 4033680);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033688 store */
    v12 = GM_CALL(vm, "instance_create", 3, v10, v11, VAL(60));
    GM_WRITE(vm, -1, "ID2", v12);
    /* @4033696 load */
    /* @4033704 cast */
    /* @4033708 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4033740;
    L_4033712: ;
    /* @4033712 constant */
    /* @4033716 cast */
    /* @4033720 load */
    /* @4033728 call */
    GM_SITE(vm, 241, 4033728);
    /* @4033736 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4033740: ;
    /* @4033740 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4033712;
    /* @4033744 constant */
    /* @4033748 cast */
    /* @4033752 load */
    /* @4033760 constant */
    /* @4033764 add */
    /* @4033768 load */
    /* @4033776 constant */
    /* @4033780 sub */
    /* @4033784 call */
    GM_SITE(vm, 241, 4033784);
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033792 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), v13, VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @4033800 load */
    /* @4033808 cast */
    /* @4033812 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4033844;
    L_4033816: ;
    /* @4033816 constant */
    /* @4033820 cast */
    /* @4033824 load */
    /* @4033832 call */
    GM_SITE(vm, 241, 4033832);
    /* @4033840 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4033844: ;
    /* @4033844 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4033816;
    L_4033848: ;
    /* @4033848 load */
    /* @4033856 constant */
    /* @4033860 cmp */
    /* @4033864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4034380;
    /* @4033868 constant */
    /* @4033872 cast */
    /* @4033876 load */
    /* @4033884 constant */
    /* @4033888 add */
    /* @4033892 load */
    /* @4033900 call */
    GM_SITE(vm, 241, 4033900);
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4033908 store */
    v16 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v15, VAL(60));
    GM_WRITE(vm, -1, "ID", v16);
    /* @4033916 load */
    /* @4033924 cast */
    /* @4033928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4033960;
    L_4033932: ;
    /* @4033932 constant */
    /* @4033936 cast */
    /* @4033940 load */
    /* @4033948 call */
    GM_SITE(vm, 241, 4033948);
    /* @4033956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4033960: ;
    /* @4033960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4033932;
    /* @4033964 constant */
    /* @4033968 cast */
    /* @4033972 load */
    /* @4033980 constant */
    /* @4033984 add */
    /* @4033988 load */
    /* @4033996 constant */
    /* @4034000 add */
    /* @4034004 call */
    GM_SITE(vm, 241, 4034004);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    v18 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034012 store */
    v19 = GM_CALL(vm, "instance_create", 3, v17, v18, VAL(60));
    GM_WRITE(vm, -1, "ID2", v19);
    /* @4034020 load */
    /* @4034028 cast */
    /* @4034032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4034064;
    L_4034036: ;
    /* @4034036 constant */
    /* @4034040 cast */
    /* @4034044 load */
    /* @4034052 call */
    GM_SITE(vm, 241, 4034052);
    /* @4034060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4034064: ;
    /* @4034064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034036;
    /* @4034068 constant */
    /* @4034072 cast */
    /* @4034076 load */
    /* @4034084 constant */
    /* @4034088 add */
    /* @4034092 load */
    /* @4034100 constant */
    /* @4034104 sub */
    /* @4034108 call */
    GM_SITE(vm, 241, 4034108);
    v20 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034116 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), v20, VAL(60));
    GM_WRITE(vm, -1, "ID3", v21);
    /* @4034124 load */
    /* @4034132 cast */
    /* @4034136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4034168;
    L_4034140: ;
    /* @4034140 constant */
    /* @4034144 cast */
    /* @4034148 load */
    /* @4034156 call */
    GM_SITE(vm, 241, 4034156);
    /* @4034164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4034168: ;
    /* @4034168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034140;
    /* @4034172 constant */
    /* @4034176 cast */
    /* @4034180 load */
    /* @4034188 constant */
    /* @4034192 add */
    /* @4034196 load */
    /* @4034204 constant */
    /* @4034208 add */
    /* @4034212 call */
    GM_SITE(vm, 241, 4034212);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034220 store */
    v24 = GM_CALL(vm, "instance_create", 3, v22, v23, VAL(60));
    GM_WRITE(vm, -1, "ID4", v24);
    /* @4034228 load */
    /* @4034236 cast */
    /* @4034240 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4034272;
    L_4034244: ;
    /* @4034244 constant */
    /* @4034248 cast */
    /* @4034252 load */
    /* @4034260 call */
    GM_SITE(vm, 241, 4034260);
    /* @4034268 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4034272: ;
    /* @4034272 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034244;
    /* @4034276 constant */
    /* @4034280 cast */
    /* @4034284 load */
    /* @4034292 constant */
    /* @4034296 add */
    /* @4034300 load */
    /* @4034308 constant */
    /* @4034312 sub */
    /* @4034316 call */
    GM_SITE(vm, 241, 4034316);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034324 store */
    v26 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), v25, VAL(60));
    GM_WRITE(vm, -1, "ID5", v26);
    /* @4034332 load */
    /* @4034340 cast */
    /* @4034344 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4034376;
    L_4034348: ;
    /* @4034348 constant */
    /* @4034352 cast */
    /* @4034356 load */
    /* @4034364 call */
    GM_SITE(vm, 241, 4034364);
    /* @4034372 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4034376: ;
    /* @4034376 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034348;
    L_4034380: ;
    /* @4034380 load */
    /* @4034388 constant */
    /* @4034392 cmp */
    /* @4034396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4034912;
    /* @4034400 constant */
    /* @4034404 cast */
    /* @4034408 load */
    /* @4034416 constant */
    /* @4034420 add */
    /* @4034424 load */
    /* @4034432 call */
    GM_SITE(vm, 241, 4034432);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034440 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v27, VAL(60));
    GM_WRITE(vm, -1, "ID", v28);
    /* @4034448 load */
    /* @4034456 cast */
    /* @4034460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4034492;
    L_4034464: ;
    /* @4034464 constant */
    /* @4034468 cast */
    /* @4034472 load */
    /* @4034480 call */
    GM_SITE(vm, 241, 4034480);
    /* @4034488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4034492: ;
    /* @4034492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034464;
    /* @4034496 constant */
    /* @4034500 cast */
    /* @4034504 load */
    /* @4034512 constant */
    /* @4034516 add */
    /* @4034520 load */
    /* @4034528 constant */
    /* @4034532 add */
    /* @4034536 call */
    GM_SITE(vm, 241, 4034536);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    v30 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034544 store */
    v31 = GM_CALL(vm, "instance_create", 3, v29, v30, VAL(60));
    GM_WRITE(vm, -1, "ID2", v31);
    /* @4034552 load */
    /* @4034560 cast */
    /* @4034564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4034596;
    L_4034568: ;
    /* @4034568 constant */
    /* @4034572 cast */
    /* @4034576 load */
    /* @4034584 call */
    GM_SITE(vm, 241, 4034584);
    /* @4034592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4034596: ;
    /* @4034596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034568;
    /* @4034600 constant */
    /* @4034604 cast */
    /* @4034608 load */
    /* @4034616 constant */
    /* @4034620 add */
    /* @4034624 load */
    /* @4034632 constant */
    /* @4034636 sub */
    /* @4034640 call */
    GM_SITE(vm, 241, 4034640);
    v32 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034648 store */
    v33 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), v32, VAL(60));
    GM_WRITE(vm, -1, "ID3", v33);
    /* @4034656 load */
    /* @4034664 cast */
    /* @4034668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4034700;
    L_4034672: ;
    /* @4034672 constant */
    /* @4034676 cast */
    /* @4034680 load */
    /* @4034688 call */
    GM_SITE(vm, 241, 4034688);
    /* @4034696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4034700: ;
    /* @4034700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034672;
    /* @4034704 constant */
    /* @4034708 cast */
    /* @4034712 load */
    /* @4034720 constant */
    /* @4034724 add */
    /* @4034728 load */
    /* @4034736 constant */
    /* @4034740 add */
    /* @4034744 call */
    GM_SITE(vm, 241, 4034744);
    v34 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034752 store */
    v36 = GM_CALL(vm, "instance_create", 3, v34, v35, VAL(60));
    GM_WRITE(vm, -1, "ID4", v36);
    /* @4034760 load */
    /* @4034768 cast */
    /* @4034772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4034804;
    L_4034776: ;
    /* @4034776 constant */
    /* @4034780 cast */
    /* @4034784 load */
    /* @4034792 call */
    GM_SITE(vm, 241, 4034792);
    /* @4034800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4034804: ;
    /* @4034804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034776;
    /* @4034808 constant */
    /* @4034812 cast */
    /* @4034816 load */
    /* @4034824 constant */
    /* @4034828 add */
    /* @4034832 load */
    /* @4034840 constant */
    /* @4034844 sub */
    /* @4034848 call */
    GM_SITE(vm, 241, 4034848);
    v37 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034856 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), v37, VAL(60));
    GM_WRITE(vm, -1, "ID5", v38);
    /* @4034864 load */
    /* @4034872 cast */
    /* @4034876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4034908;
    L_4034880: ;
    /* @4034880 constant */
    /* @4034884 cast */
    /* @4034888 load */
    /* @4034896 call */
    GM_SITE(vm, 241, 4034896);
    /* @4034904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4034908: ;
    /* @4034908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034880;
    L_4034912: ;
    /* @4034912 load */
    /* @4034920 constant */
    /* @4034924 cmp */
    /* @4034928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4035860;
    /* @4034932 constant */
    /* @4034936 cast */
    /* @4034940 load */
    /* @4034948 constant */
    /* @4034952 add */
    /* @4034956 load */
    /* @4034964 call */
    GM_SITE(vm, 241, 4034964);
    v39 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4034972 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v39, VAL(60));
    GM_WRITE(vm, -1, "ID", v40);
    /* @4034980 load */
    /* @4034988 cast */
    /* @4034992 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4035024;
    L_4034996: ;
    /* @4034996 constant */
    /* @4035000 cast */
    /* @4035004 load */
    /* @4035012 call */
    GM_SITE(vm, 241, 4035012);
    /* @4035020 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4035024: ;
    /* @4035024 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4034996;
    /* @4035028 constant */
    /* @4035032 cast */
    /* @4035036 load */
    /* @4035044 constant */
    /* @4035048 add */
    /* @4035052 load */
    /* @4035060 constant */
    /* @4035064 add */
    /* @4035068 call */
    GM_SITE(vm, 241, 4035068);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    v42 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035076 store */
    v43 = GM_CALL(vm, "instance_create", 3, v41, v42, VAL(60));
    GM_WRITE(vm, -1, "ID2", v43);
    /* @4035084 load */
    /* @4035092 cast */
    /* @4035096 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4035128;
    L_4035100: ;
    /* @4035100 constant */
    /* @4035104 cast */
    /* @4035108 load */
    /* @4035116 call */
    GM_SITE(vm, 241, 4035116);
    /* @4035124 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4035128: ;
    /* @4035128 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035100;
    /* @4035132 constant */
    /* @4035136 cast */
    /* @4035140 load */
    /* @4035148 constant */
    /* @4035152 add */
    /* @4035156 load */
    /* @4035164 constant */
    /* @4035168 sub */
    /* @4035172 call */
    GM_SITE(vm, 241, 4035172);
    v44 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035180 store */
    v45 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), v44, VAL(60));
    GM_WRITE(vm, -1, "ID3", v45);
    /* @4035188 load */
    /* @4035196 cast */
    /* @4035200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4035232;
    L_4035204: ;
    /* @4035204 constant */
    /* @4035208 cast */
    /* @4035212 load */
    /* @4035220 call */
    GM_SITE(vm, 241, 4035220);
    /* @4035228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4035232: ;
    /* @4035232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035204;
    /* @4035236 constant */
    /* @4035240 cast */
    /* @4035244 load */
    /* @4035252 constant */
    /* @4035256 add */
    /* @4035260 load */
    /* @4035268 constant */
    /* @4035272 add */
    /* @4035276 call */
    GM_SITE(vm, 241, 4035276);
    v46 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    v47 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035284 store */
    v48 = GM_CALL(vm, "instance_create", 3, v46, v47, VAL(60));
    GM_WRITE(vm, -1, "ID4", v48);
    /* @4035292 load */
    /* @4035300 cast */
    /* @4035304 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4035336;
    L_4035308: ;
    /* @4035308 constant */
    /* @4035312 cast */
    /* @4035316 load */
    /* @4035324 call */
    GM_SITE(vm, 241, 4035324);
    /* @4035332 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4035336: ;
    /* @4035336 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035308;
    /* @4035340 constant */
    /* @4035344 cast */
    /* @4035348 load */
    /* @4035356 constant */
    /* @4035360 add */
    /* @4035364 load */
    /* @4035372 constant */
    /* @4035376 sub */
    /* @4035380 call */
    GM_SITE(vm, 241, 4035380);
    v49 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035388 store */
    v50 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), v49, VAL(60));
    GM_WRITE(vm, -1, "ID5", v50);
    /* @4035396 load */
    /* @4035404 cast */
    /* @4035408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4035440;
    L_4035412: ;
    /* @4035412 constant */
    /* @4035416 cast */
    /* @4035420 load */
    /* @4035428 call */
    GM_SITE(vm, 241, 4035428);
    /* @4035436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4035440: ;
    /* @4035440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035412;
    /* @4035444 constant */
    /* @4035448 cast */
    /* @4035452 load */
    /* @4035460 constant */
    /* @4035464 add */
    /* @4035468 load */
    /* @4035476 constant */
    /* @4035480 add */
    /* @4035484 call */
    GM_SITE(vm, 241, 4035484);
    v51 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    v52 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035492 store */
    v53 = GM_CALL(vm, "instance_create", 3, v51, v52, VAL(60));
    GM_WRITE(vm, -1, "ID", v53);
    /* @4035500 load */
    /* @4035508 cast */
    /* @4035512 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4035544;
    L_4035516: ;
    /* @4035516 constant */
    /* @4035520 cast */
    /* @4035524 load */
    /* @4035532 call */
    GM_SITE(vm, 241, 4035532);
    /* @4035540 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4035544: ;
    /* @4035544 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035516;
    /* @4035548 constant */
    /* @4035552 cast */
    /* @4035556 load */
    /* @4035564 constant */
    /* @4035568 add */
    /* @4035572 load */
    /* @4035580 constant */
    /* @4035584 add */
    /* @4035588 call */
    GM_SITE(vm, 241, 4035588);
    v54 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    v55 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035596 store */
    v56 = GM_CALL(vm, "instance_create", 3, v54, v55, VAL(60));
    GM_WRITE(vm, -1, "ID2", v56);
    /* @4035604 load */
    /* @4035612 cast */
    /* @4035616 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4035648;
    L_4035620: ;
    /* @4035620 constant */
    /* @4035624 cast */
    /* @4035628 load */
    /* @4035636 call */
    GM_SITE(vm, 241, 4035636);
    /* @4035644 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4035648: ;
    /* @4035648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035620;
    /* @4035652 constant */
    /* @4035656 cast */
    /* @4035660 load */
    /* @4035668 constant */
    /* @4035672 add */
    /* @4035676 load */
    /* @4035684 constant */
    /* @4035688 sub */
    /* @4035692 call */
    GM_SITE(vm, 241, 4035692);
    v57 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035700 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), v57, VAL(60));
    GM_WRITE(vm, -1, "ID3", v58);
    /* @4035708 load */
    /* @4035716 cast */
    /* @4035720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4035752;
    L_4035724: ;
    /* @4035724 constant */
    /* @4035728 cast */
    /* @4035732 load */
    /* @4035740 call */
    GM_SITE(vm, 241, 4035740);
    /* @4035748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4035752: ;
    /* @4035752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035724;
    /* @4035756 constant */
    /* @4035760 cast */
    /* @4035764 load */
    /* @4035772 constant */
    /* @4035776 add */
    /* @4035780 load */
    /* @4035788 constant */
    /* @4035792 add */
    /* @4035796 call */
    GM_SITE(vm, 241, 4035796);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v60 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035804 store */
    v61 = GM_CALL(vm, "instance_create", 3, v59, v60, VAL(60));
    GM_WRITE(vm, -1, "ID4", v61);
    /* @4035812 load */
    /* @4035820 cast */
    /* @4035824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4035856;
    L_4035828: ;
    /* @4035828 constant */
    /* @4035832 cast */
    /* @4035836 load */
    /* @4035844 call */
    GM_SITE(vm, 241, 4035844);
    /* @4035852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4035856: ;
    /* @4035856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035828;
    L_4035860: ;
    /* @4035860 load */
    /* @4035868 constant */
    /* @4035872 cmp */
    /* @4035876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4036704;
    /* @4035880 constant */
    /* @4035884 cast */
    /* @4035888 load */
    /* @4035896 constant */
    /* @4035900 add */
    /* @4035904 load */
    /* @4035912 call */
    GM_SITE(vm, 241, 4035912);
    v62 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4035920 store */
    v63 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v62, VAL(60));
    GM_WRITE(vm, -1, "ID", v63);
    /* @4035928 load */
    /* @4035936 cast */
    /* @4035940 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4035972;
    L_4035944: ;
    /* @4035944 constant */
    /* @4035948 cast */
    /* @4035952 load */
    /* @4035960 call */
    GM_SITE(vm, 241, 4035960);
    /* @4035968 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4035972: ;
    /* @4035972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4035944;
    /* @4035976 constant */
    /* @4035980 cast */
    /* @4035984 load */
    /* @4035992 constant */
    /* @4035996 add */
    /* @4036000 load */
    /* @4036008 constant */
    /* @4036012 add */
    /* @4036016 call */
    GM_SITE(vm, 241, 4036016);
    v64 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    v65 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036024 store */
    v66 = GM_CALL(vm, "instance_create", 3, v64, v65, VAL(60));
    GM_WRITE(vm, -1, "ID2", v66);
    /* @4036032 load */
    /* @4036040 cast */
    /* @4036044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4036076;
    L_4036048: ;
    /* @4036048 constant */
    /* @4036052 cast */
    /* @4036056 load */
    /* @4036064 call */
    GM_SITE(vm, 241, 4036064);
    /* @4036072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4036076: ;
    /* @4036076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036048;
    /* @4036080 constant */
    /* @4036084 cast */
    /* @4036088 load */
    /* @4036096 constant */
    /* @4036100 add */
    /* @4036104 load */
    /* @4036112 constant */
    /* @4036116 sub */
    /* @4036120 call */
    GM_SITE(vm, 241, 4036120);
    v67 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036128 store */
    v68 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), v67, VAL(60));
    GM_WRITE(vm, -1, "ID3", v68);
    /* @4036136 load */
    /* @4036144 cast */
    /* @4036148 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4036180;
    L_4036152: ;
    /* @4036152 constant */
    /* @4036156 cast */
    /* @4036160 load */
    /* @4036168 call */
    GM_SITE(vm, 241, 4036168);
    /* @4036176 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4036180: ;
    /* @4036180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036152;
    /* @4036184 constant */
    /* @4036188 cast */
    /* @4036192 load */
    /* @4036200 constant */
    /* @4036204 add */
    /* @4036208 load */
    /* @4036216 constant */
    /* @4036220 add */
    /* @4036224 call */
    GM_SITE(vm, 241, 4036224);
    v69 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    v70 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036232 store */
    v71 = GM_CALL(vm, "instance_create", 3, v69, v70, VAL(60));
    GM_WRITE(vm, -1, "ID4", v71);
    /* @4036240 load */
    /* @4036248 cast */
    /* @4036252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4036284;
    L_4036256: ;
    /* @4036256 constant */
    /* @4036260 cast */
    /* @4036264 load */
    /* @4036272 call */
    GM_SITE(vm, 241, 4036272);
    /* @4036280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4036284: ;
    /* @4036284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036256;
    /* @4036288 constant */
    /* @4036292 cast */
    /* @4036296 load */
    /* @4036304 constant */
    /* @4036308 add */
    /* @4036312 load */
    /* @4036320 constant */
    /* @4036324 sub */
    /* @4036328 call */
    GM_SITE(vm, 241, 4036328);
    v72 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036336 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), v72, VAL(60));
    GM_WRITE(vm, -1, "ID5", v73);
    /* @4036344 load */
    /* @4036352 cast */
    /* @4036356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4036388;
    L_4036360: ;
    /* @4036360 constant */
    /* @4036364 cast */
    /* @4036368 load */
    /* @4036376 call */
    GM_SITE(vm, 241, 4036376);
    /* @4036384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4036388: ;
    /* @4036388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036360;
    /* @4036392 constant */
    /* @4036396 cast */
    /* @4036400 load */
    /* @4036408 constant */
    /* @4036412 add */
    /* @4036416 load */
    /* @4036424 constant */
    /* @4036428 add */
    /* @4036432 call */
    GM_SITE(vm, 241, 4036432);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    v75 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036440 store */
    v76 = GM_CALL(vm, "instance_create", 3, v74, v75, VAL(60));
    GM_WRITE(vm, -1, "ID", v76);
    /* @4036448 load */
    /* @4036456 cast */
    /* @4036460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4036492;
    L_4036464: ;
    /* @4036464 constant */
    /* @4036468 cast */
    /* @4036472 load */
    /* @4036480 call */
    GM_SITE(vm, 241, 4036480);
    /* @4036488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4036492: ;
    /* @4036492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036464;
    /* @4036496 constant */
    /* @4036500 cast */
    /* @4036504 load */
    /* @4036512 constant */
    /* @4036516 add */
    /* @4036520 load */
    /* @4036528 constant */
    /* @4036532 add */
    /* @4036536 call */
    GM_SITE(vm, 241, 4036536);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    v78 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036544 store */
    v79 = GM_CALL(vm, "instance_create", 3, v77, v78, VAL(60));
    GM_WRITE(vm, -1, "ID2", v79);
    /* @4036552 load */
    /* @4036560 cast */
    /* @4036564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4036596;
    L_4036568: ;
    /* @4036568 constant */
    /* @4036572 cast */
    /* @4036576 load */
    /* @4036584 call */
    GM_SITE(vm, 241, 4036584);
    /* @4036592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4036596: ;
    /* @4036596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036568;
    /* @4036600 constant */
    /* @4036604 cast */
    /* @4036608 load */
    /* @4036616 constant */
    /* @4036620 add */
    /* @4036624 load */
    /* @4036632 constant */
    /* @4036636 sub */
    /* @4036640 call */
    GM_SITE(vm, 241, 4036640);
    v80 = GM_ADD(GM_READ(vm, -1, "y"), VAL(35));
    /* @4036648 store */
    v81 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), v80, VAL(60));
    GM_WRITE(vm, -1, "ID3", v81);
    /* @4036656 load */
    /* @4036664 cast */
    /* @4036668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4036700;
    L_4036672: ;
    /* @4036672 constant */
    /* @4036676 cast */
    /* @4036680 load */
    /* @4036688 call */
    GM_SITE(vm, 241, 4036688);
    /* @4036696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4036700: ;
    /* @4036700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036672;
    L_4036704: ;
    /* @4036704 b */
    goto L_4039988;
    L_4036708: ;
    /* @4036708 constant */
    /* @4036712 cast */
    /* @4036716 load */
    /* @4036724 constant */
    /* @4036728 sub */
    /* @4036732 load */
    /* @4036740 call */
    GM_SITE(vm, 241, 4036740);
    /* @4036748 cast */
    /* @4036752 not */
    /* @4036756 bf */
    v82 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(4)), VAL(34))));
    if (!TRUTH(v82)) goto L_4039988;
    /* @4036760 load */
    /* @4036768 constant */
    /* @4036772 cmp */
    /* @4036776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4036824;
    /* @4036780 constant */
    /* @4036784 cast */
    /* @4036788 load */
    /* @4036796 constant */
    /* @4036800 sub */
    /* @4036804 load */
    /* @4036812 call */
    GM_SITE(vm, 241, 4036812);
    /* @4036820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_4036824: ;
    /* @4036824 load */
    /* @4036832 constant */
    /* @4036836 cmp */
    /* @4036840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4036880;
    /* @4036844 constant */
    /* @4036848 cast */
    /* @4036852 load */
    /* @4036860 load */
    /* @4036868 call */
    GM_SITE(vm, 241, 4036868);
    /* @4036876 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(59)));
    L_4036880: ;
    /* @4036880 load */
    /* @4036888 constant */
    /* @4036892 cmp */
    /* @4036896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4036988;
    /* @4036900 constant */
    /* @4036904 cast */
    /* @4036908 load */
    /* @4036916 load */
    /* @4036924 call */
    GM_SITE(vm, 241, 4036924);
    /* @4036932 store */
    v83 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(61));
    GM_WRITE(vm, -1, "ID", v83);
    /* @4036940 load */
    /* @4036948 cast */
    /* @4036952 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4036984;
    L_4036956: ;
    /* @4036956 constant */
    /* @4036960 cast */
    /* @4036964 load */
    /* @4036972 call */
    GM_SITE(vm, 241, 4036972);
    /* @4036980 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_4036984: ;
    /* @4036984 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4036956;
    L_4036988: ;
    /* @4036988 constant */
    /* @4036992 cast */
    /* @4036996 call */
    GM_SITE(vm, 241, 4036996);
    /* @4037004 constant */
    /* @4037008 cmp */
    /* @4037012 bf */
    v84 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v84)) goto L_4037020;
    /* @4037016 b */
    goto L_4039988;
    L_4037020: ;
    /* @4037020 constant */
    /* @4037024 cast */
    /* @4037028 call */
    GM_SITE(vm, 241, 4037028);
    /* @4037036 constant */
    /* @4037040 cmp */
    /* @4037044 bf */
    v85 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v85)) goto L_4039988;
    /* @4037048 load */
    /* @4037056 constant */
    /* @4037060 cmp */
    /* @4037064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4037348;
    /* @4037068 constant */
    /* @4037072 cast */
    /* @4037076 load */
    /* @4037084 load */
    /* @4037092 call */
    GM_SITE(vm, 241, 4037092);
    /* @4037100 store */
    v86 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v86);
    /* @4037108 load */
    /* @4037116 cast */
    /* @4037120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4037152;
    L_4037124: ;
    /* @4037124 constant */
    /* @4037128 cast */
    /* @4037132 load */
    /* @4037140 call */
    GM_SITE(vm, 241, 4037140);
    /* @4037148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4037152: ;
    /* @4037152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037124;
    /* @4037156 constant */
    /* @4037160 cast */
    /* @4037164 load */
    /* @4037172 load */
    /* @4037180 constant */
    /* @4037184 add */
    /* @4037188 call */
    GM_SITE(vm, 241, 4037188);
    v87 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4037196 store */
    v88 = GM_CALL(vm, "instance_create", 3, v87, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v88);
    /* @4037204 load */
    /* @4037212 cast */
    /* @4037216 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4037248;
    L_4037220: ;
    /* @4037220 constant */
    /* @4037224 cast */
    /* @4037228 load */
    /* @4037236 call */
    GM_SITE(vm, 241, 4037236);
    /* @4037244 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4037248: ;
    /* @4037248 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037220;
    /* @4037252 constant */
    /* @4037256 cast */
    /* @4037260 load */
    /* @4037268 load */
    /* @4037276 constant */
    /* @4037280 sub */
    /* @4037284 call */
    GM_SITE(vm, 241, 4037284);
    /* @4037292 store */
    v89 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v89);
    /* @4037300 load */
    /* @4037308 cast */
    /* @4037312 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4037344;
    L_4037316: ;
    /* @4037316 constant */
    /* @4037320 cast */
    /* @4037324 load */
    /* @4037332 call */
    GM_SITE(vm, 241, 4037332);
    /* @4037340 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4037344: ;
    /* @4037344 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037316;
    L_4037348: ;
    /* @4037348 load */
    /* @4037356 constant */
    /* @4037360 cmp */
    /* @4037364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4037840;
    /* @4037368 constant */
    /* @4037372 cast */
    /* @4037376 load */
    /* @4037384 load */
    /* @4037392 call */
    GM_SITE(vm, 241, 4037392);
    /* @4037400 store */
    v90 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v90);
    /* @4037408 load */
    /* @4037416 cast */
    /* @4037420 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4037452;
    L_4037424: ;
    /* @4037424 constant */
    /* @4037428 cast */
    /* @4037432 load */
    /* @4037440 call */
    GM_SITE(vm, 241, 4037440);
    /* @4037448 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4037452: ;
    /* @4037452 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037424;
    /* @4037456 constant */
    /* @4037460 cast */
    /* @4037464 load */
    /* @4037472 load */
    /* @4037480 constant */
    /* @4037484 add */
    /* @4037488 call */
    GM_SITE(vm, 241, 4037488);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4037496 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v92);
    /* @4037504 load */
    /* @4037512 cast */
    /* @4037516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4037548;
    L_4037520: ;
    /* @4037520 constant */
    /* @4037524 cast */
    /* @4037528 load */
    /* @4037536 call */
    GM_SITE(vm, 241, 4037536);
    /* @4037544 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4037548: ;
    /* @4037548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037520;
    /* @4037552 constant */
    /* @4037556 cast */
    /* @4037560 load */
    /* @4037568 load */
    /* @4037576 constant */
    /* @4037580 sub */
    /* @4037584 call */
    GM_SITE(vm, 241, 4037584);
    /* @4037592 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v93);
    /* @4037600 load */
    /* @4037608 cast */
    /* @4037612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4037644;
    L_4037616: ;
    /* @4037616 constant */
    /* @4037620 cast */
    /* @4037624 load */
    /* @4037632 call */
    GM_SITE(vm, 241, 4037632);
    /* @4037640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4037644: ;
    /* @4037644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037616;
    /* @4037648 constant */
    /* @4037652 cast */
    /* @4037656 load */
    /* @4037664 load */
    /* @4037672 constant */
    /* @4037676 add */
    /* @4037680 call */
    GM_SITE(vm, 241, 4037680);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4037688 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID4", v95);
    /* @4037696 load */
    /* @4037704 cast */
    /* @4037708 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4037740;
    L_4037712: ;
    /* @4037712 constant */
    /* @4037716 cast */
    /* @4037720 load */
    /* @4037728 call */
    GM_SITE(vm, 241, 4037728);
    /* @4037736 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4037740: ;
    /* @4037740 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037712;
    /* @4037744 constant */
    /* @4037748 cast */
    /* @4037752 load */
    /* @4037760 load */
    /* @4037768 constant */
    /* @4037772 sub */
    /* @4037776 call */
    GM_SITE(vm, 241, 4037776);
    /* @4037784 store */
    v96 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID5", v96);
    /* @4037792 load */
    /* @4037800 cast */
    /* @4037804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4037836;
    L_4037808: ;
    /* @4037808 constant */
    /* @4037812 cast */
    /* @4037816 load */
    /* @4037824 call */
    GM_SITE(vm, 241, 4037824);
    /* @4037832 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4037836: ;
    /* @4037836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037808;
    L_4037840: ;
    /* @4037840 load */
    /* @4037848 constant */
    /* @4037852 cmp */
    /* @4037856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4038332;
    /* @4037860 constant */
    /* @4037864 cast */
    /* @4037868 load */
    /* @4037876 load */
    /* @4037884 call */
    GM_SITE(vm, 241, 4037884);
    /* @4037892 store */
    v97 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v97);
    /* @4037900 load */
    /* @4037908 cast */
    /* @4037912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4037944;
    L_4037916: ;
    /* @4037916 constant */
    /* @4037920 cast */
    /* @4037924 load */
    /* @4037932 call */
    GM_SITE(vm, 241, 4037932);
    /* @4037940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4037944: ;
    /* @4037944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4037916;
    /* @4037948 constant */
    /* @4037952 cast */
    /* @4037956 load */
    /* @4037964 load */
    /* @4037972 constant */
    /* @4037976 add */
    /* @4037980 call */
    GM_SITE(vm, 241, 4037980);
    v98 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4037988 store */
    v99 = GM_CALL(vm, "instance_create", 3, v98, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v99);
    /* @4037996 load */
    /* @4038004 cast */
    /* @4038008 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4038040;
    L_4038012: ;
    /* @4038012 constant */
    /* @4038016 cast */
    /* @4038020 load */
    /* @4038028 call */
    GM_SITE(vm, 241, 4038028);
    /* @4038036 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4038040: ;
    /* @4038040 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038012;
    /* @4038044 constant */
    /* @4038048 cast */
    /* @4038052 load */
    /* @4038060 load */
    /* @4038068 constant */
    /* @4038072 sub */
    /* @4038076 call */
    GM_SITE(vm, 241, 4038076);
    /* @4038084 store */
    v100 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v100);
    /* @4038092 load */
    /* @4038100 cast */
    /* @4038104 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4038136;
    L_4038108: ;
    /* @4038108 constant */
    /* @4038112 cast */
    /* @4038116 load */
    /* @4038124 call */
    GM_SITE(vm, 241, 4038124);
    /* @4038132 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4038136: ;
    /* @4038136 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038108;
    /* @4038140 constant */
    /* @4038144 cast */
    /* @4038148 load */
    /* @4038156 load */
    /* @4038164 constant */
    /* @4038168 add */
    /* @4038172 call */
    GM_SITE(vm, 241, 4038172);
    v101 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4038180 store */
    v102 = GM_CALL(vm, "instance_create", 3, v101, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID4", v102);
    /* @4038188 load */
    /* @4038196 cast */
    /* @4038200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4038232;
    L_4038204: ;
    /* @4038204 constant */
    /* @4038208 cast */
    /* @4038212 load */
    /* @4038220 call */
    GM_SITE(vm, 241, 4038220);
    /* @4038228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4038232: ;
    /* @4038232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038204;
    /* @4038236 constant */
    /* @4038240 cast */
    /* @4038244 load */
    /* @4038252 load */
    /* @4038260 constant */
    /* @4038264 sub */
    /* @4038268 call */
    GM_SITE(vm, 241, 4038268);
    /* @4038276 store */
    v103 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID5", v103);
    /* @4038284 load */
    /* @4038292 cast */
    /* @4038296 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4038328;
    L_4038300: ;
    /* @4038300 constant */
    /* @4038304 cast */
    /* @4038308 load */
    /* @4038316 call */
    GM_SITE(vm, 241, 4038316);
    /* @4038324 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4038328: ;
    /* @4038328 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038300;
    L_4038332: ;
    /* @4038332 load */
    /* @4038340 constant */
    /* @4038344 cmp */
    /* @4038348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4039208;
    /* @4038352 constant */
    /* @4038356 cast */
    /* @4038360 load */
    /* @4038368 load */
    /* @4038376 call */
    GM_SITE(vm, 241, 4038376);
    /* @4038384 store */
    v104 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v104);
    /* @4038392 load */
    /* @4038400 cast */
    /* @4038404 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4038436;
    L_4038408: ;
    /* @4038408 constant */
    /* @4038412 cast */
    /* @4038416 load */
    /* @4038424 call */
    GM_SITE(vm, 241, 4038424);
    /* @4038432 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4038436: ;
    /* @4038436 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038408;
    /* @4038440 constant */
    /* @4038444 cast */
    /* @4038448 load */
    /* @4038456 load */
    /* @4038464 constant */
    /* @4038468 add */
    /* @4038472 call */
    GM_SITE(vm, 241, 4038472);
    v105 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4038480 store */
    v106 = GM_CALL(vm, "instance_create", 3, v105, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v106);
    /* @4038488 load */
    /* @4038496 cast */
    /* @4038500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4038532;
    L_4038504: ;
    /* @4038504 constant */
    /* @4038508 cast */
    /* @4038512 load */
    /* @4038520 call */
    GM_SITE(vm, 241, 4038520);
    /* @4038528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4038532: ;
    /* @4038532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038504;
    /* @4038536 constant */
    /* @4038540 cast */
    /* @4038544 load */
    /* @4038552 load */
    /* @4038560 constant */
    /* @4038564 sub */
    /* @4038568 call */
    GM_SITE(vm, 241, 4038568);
    /* @4038576 store */
    v107 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v107);
    /* @4038584 load */
    /* @4038592 cast */
    /* @4038596 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4038628;
    L_4038600: ;
    /* @4038600 constant */
    /* @4038604 cast */
    /* @4038608 load */
    /* @4038616 call */
    GM_SITE(vm, 241, 4038616);
    /* @4038624 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4038628: ;
    /* @4038628 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038600;
    /* @4038632 constant */
    /* @4038636 cast */
    /* @4038640 load */
    /* @4038648 load */
    /* @4038656 constant */
    /* @4038660 add */
    /* @4038664 call */
    GM_SITE(vm, 241, 4038664);
    v108 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4038672 store */
    v109 = GM_CALL(vm, "instance_create", 3, v108, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID4", v109);
    /* @4038680 load */
    /* @4038688 cast */
    /* @4038692 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4038724;
    L_4038696: ;
    /* @4038696 constant */
    /* @4038700 cast */
    /* @4038704 load */
    /* @4038712 call */
    GM_SITE(vm, 241, 4038712);
    /* @4038720 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4038724: ;
    /* @4038724 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038696;
    /* @4038728 constant */
    /* @4038732 cast */
    /* @4038736 load */
    /* @4038744 load */
    /* @4038752 constant */
    /* @4038756 sub */
    /* @4038760 call */
    GM_SITE(vm, 241, 4038760);
    /* @4038768 store */
    v110 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID5", v110);
    /* @4038776 load */
    /* @4038784 cast */
    /* @4038788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4038820;
    L_4038792: ;
    /* @4038792 constant */
    /* @4038796 cast */
    /* @4038800 load */
    /* @4038808 call */
    GM_SITE(vm, 241, 4038808);
    /* @4038816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4038820: ;
    /* @4038820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038792;
    /* @4038824 constant */
    /* @4038828 cast */
    /* @4038832 load */
    /* @4038840 load */
    /* @4038848 constant */
    /* @4038852 add */
    /* @4038856 call */
    GM_SITE(vm, 241, 4038856);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4038864 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v112);
    /* @4038872 load */
    /* @4038880 cast */
    /* @4038884 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4038916;
    L_4038888: ;
    /* @4038888 constant */
    /* @4038892 cast */
    /* @4038896 load */
    /* @4038904 call */
    GM_SITE(vm, 241, 4038904);
    /* @4038912 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4038916: ;
    /* @4038916 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038888;
    /* @4038920 constant */
    /* @4038924 cast */
    /* @4038928 load */
    /* @4038936 load */
    /* @4038944 constant */
    /* @4038948 add */
    /* @4038952 call */
    GM_SITE(vm, 241, 4038952);
    v113 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4038960 store */
    v114 = GM_CALL(vm, "instance_create", 3, v113, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v114);
    /* @4038968 load */
    /* @4038976 cast */
    /* @4038980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4039012;
    L_4038984: ;
    /* @4038984 constant */
    /* @4038988 cast */
    /* @4038992 load */
    /* @4039000 call */
    GM_SITE(vm, 241, 4039000);
    /* @4039008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4039012: ;
    /* @4039012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4038984;
    /* @4039016 constant */
    /* @4039020 cast */
    /* @4039024 load */
    /* @4039032 load */
    /* @4039040 constant */
    /* @4039044 sub */
    /* @4039048 call */
    GM_SITE(vm, 241, 4039048);
    /* @4039056 store */
    v115 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v115);
    /* @4039064 load */
    /* @4039072 cast */
    /* @4039076 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4039108;
    L_4039080: ;
    /* @4039080 constant */
    /* @4039084 cast */
    /* @4039088 load */
    /* @4039096 call */
    GM_SITE(vm, 241, 4039096);
    /* @4039104 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4039108: ;
    /* @4039108 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039080;
    /* @4039112 constant */
    /* @4039116 cast */
    /* @4039120 load */
    /* @4039128 load */
    /* @4039136 constant */
    /* @4039140 add */
    /* @4039144 call */
    GM_SITE(vm, 241, 4039144);
    v116 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4039152 store */
    v117 = GM_CALL(vm, "instance_create", 3, v116, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID4", v117);
    /* @4039160 load */
    /* @4039168 cast */
    /* @4039172 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4039204;
    L_4039176: ;
    /* @4039176 constant */
    /* @4039180 cast */
    /* @4039184 load */
    /* @4039192 call */
    GM_SITE(vm, 241, 4039192);
    /* @4039200 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4039204: ;
    /* @4039204 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039176;
    L_4039208: ;
    /* @4039208 load */
    /* @4039216 constant */
    /* @4039220 cmp */
    /* @4039224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4039988;
    /* @4039228 constant */
    /* @4039232 cast */
    /* @4039236 load */
    /* @4039244 load */
    /* @4039252 call */
    GM_SITE(vm, 241, 4039252);
    /* @4039260 store */
    v118 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v118);
    /* @4039268 load */
    /* @4039276 cast */
    /* @4039280 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4039312;
    L_4039284: ;
    /* @4039284 constant */
    /* @4039288 cast */
    /* @4039292 load */
    /* @4039300 call */
    GM_SITE(vm, 241, 4039300);
    /* @4039308 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4039312: ;
    /* @4039312 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039284;
    /* @4039316 constant */
    /* @4039320 cast */
    /* @4039324 load */
    /* @4039332 load */
    /* @4039340 constant */
    /* @4039344 add */
    /* @4039348 call */
    GM_SITE(vm, 241, 4039348);
    v119 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4039356 store */
    v120 = GM_CALL(vm, "instance_create", 3, v119, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v120);
    /* @4039364 load */
    /* @4039372 cast */
    /* @4039376 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4039408;
    L_4039380: ;
    /* @4039380 constant */
    /* @4039384 cast */
    /* @4039388 load */
    /* @4039396 call */
    GM_SITE(vm, 241, 4039396);
    /* @4039404 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4039408: ;
    /* @4039408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039380;
    /* @4039412 constant */
    /* @4039416 cast */
    /* @4039420 load */
    /* @4039428 load */
    /* @4039436 constant */
    /* @4039440 sub */
    /* @4039444 call */
    GM_SITE(vm, 241, 4039444);
    /* @4039452 store */
    v121 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v121);
    /* @4039460 load */
    /* @4039468 cast */
    /* @4039472 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4039504;
    L_4039476: ;
    /* @4039476 constant */
    /* @4039480 cast */
    /* @4039484 load */
    /* @4039492 call */
    GM_SITE(vm, 241, 4039492);
    /* @4039500 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4039504: ;
    /* @4039504 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039476;
    /* @4039508 constant */
    /* @4039512 cast */
    /* @4039516 load */
    /* @4039524 load */
    /* @4039532 constant */
    /* @4039536 add */
    /* @4039540 call */
    GM_SITE(vm, 241, 4039540);
    v122 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4039548 store */
    v123 = GM_CALL(vm, "instance_create", 3, v122, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID4", v123);
    /* @4039556 load */
    /* @4039564 cast */
    /* @4039568 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4039600;
    L_4039572: ;
    /* @4039572 constant */
    /* @4039576 cast */
    /* @4039580 load */
    /* @4039588 call */
    GM_SITE(vm, 241, 4039588);
    /* @4039596 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4039600: ;
    /* @4039600 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039572;
    /* @4039604 constant */
    /* @4039608 cast */
    /* @4039612 load */
    /* @4039620 load */
    /* @4039628 constant */
    /* @4039632 sub */
    /* @4039636 call */
    GM_SITE(vm, 241, 4039636);
    /* @4039644 store */
    v124 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID5", v124);
    /* @4039652 load */
    /* @4039660 cast */
    /* @4039664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4039696;
    L_4039668: ;
    /* @4039668 constant */
    /* @4039672 cast */
    /* @4039676 load */
    /* @4039684 call */
    GM_SITE(vm, 241, 4039684);
    /* @4039692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4039696: ;
    /* @4039696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039668;
    /* @4039700 constant */
    /* @4039704 cast */
    /* @4039708 load */
    /* @4039716 load */
    /* @4039724 constant */
    /* @4039728 add */
    /* @4039732 call */
    GM_SITE(vm, 241, 4039732);
    v125 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4039740 store */
    v126 = GM_CALL(vm, "instance_create", 3, v125, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID", v126);
    /* @4039748 load */
    /* @4039756 cast */
    /* @4039760 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4039792;
    L_4039764: ;
    /* @4039764 constant */
    /* @4039768 cast */
    /* @4039772 load */
    /* @4039780 call */
    GM_SITE(vm, 241, 4039780);
    /* @4039788 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4039792: ;
    /* @4039792 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039764;
    /* @4039796 constant */
    /* @4039800 cast */
    /* @4039804 load */
    /* @4039812 load */
    /* @4039820 constant */
    /* @4039824 add */
    /* @4039828 call */
    GM_SITE(vm, 241, 4039828);
    v127 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4039836 store */
    v128 = GM_CALL(vm, "instance_create", 3, v127, GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID2", v128);
    /* @4039844 load */
    /* @4039852 cast */
    /* @4039856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4039888;
    L_4039860: ;
    /* @4039860 constant */
    /* @4039864 cast */
    /* @4039868 load */
    /* @4039876 call */
    GM_SITE(vm, 241, 4039876);
    /* @4039884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4039888: ;
    /* @4039888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039860;
    /* @4039892 constant */
    /* @4039896 cast */
    /* @4039900 load */
    /* @4039908 load */
    /* @4039916 constant */
    /* @4039920 sub */
    /* @4039924 call */
    GM_SITE(vm, 241, 4039924);
    /* @4039932 store */
    v129 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), GM_READ(vm, -1, "y"), VAL(60));
    GM_WRITE(vm, -1, "ID3", v129);
    /* @4039940 load */
    /* @4039948 cast */
    /* @4039952 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4039984;
    L_4039956: ;
    /* @4039956 constant */
    /* @4039960 cast */
    /* @4039964 load */
    /* @4039972 call */
    GM_SITE(vm, 241, 4039972);
    /* @4039980 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4039984: ;
    /* @4039984 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4039956;
    L_4039988: ;
    /* @4039988 call */
    GM_SITE(vm, 241, 4039988);
    /* @4039996 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4040000: ;
    return;
}
