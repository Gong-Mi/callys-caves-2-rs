/* generated from CODE 66 (gml_Object_obj_shooter1_Alarm_0), source start 3903932, end 3908236. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0066(GmVM* vm) {
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
    /* @3903932 load */
    /* @3903940 constant */
    /* @3903944 cmp */
    /* @3903948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3903956;
    /* @3903952 b */
    goto L_3904012;
    L_3903956: ;
    /* @3903956 load */
    /* @3903964 constant */
    /* @3903968 cmp */
    /* @3903972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3904012;
    /* @3903976 constant */
    /* @3903980 cast */
    /* @3903984 constant */
    /* @3903988 cast */
    /* @3903992 constant */
    /* @3903996 cast */
    /* @3904000 call */
    GM_SITE(vm, 66, 3904000);
    /* @3904008 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3904012: ;
    /* @3904012 load */
    /* @3904020 constant */
    /* @3904024 cmp */
    /* @3904028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3904076;
    /* @3904032 constant */
    /* @3904036 cast */
    /* @3904040 load */
    /* @3904048 constant */
    /* @3904052 sub */
    /* @3904056 load */
    /* @3904064 call */
    GM_SITE(vm, 66, 3904064);
    /* @3904072 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3904076: ;
    /* @3904076 load */
    /* @3904084 constant */
    /* @3904088 cmp */
    /* @3904092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3904140;
    /* @3904096 constant */
    /* @3904100 cast */
    /* @3904104 load */
    /* @3904112 constant */
    /* @3904116 sub */
    /* @3904120 load */
    /* @3904128 call */
    GM_SITE(vm, 66, 3904128);
    /* @3904136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3904140: ;
    /* @3904140 load */
    /* @3904148 constant */
    /* @3904152 cmp */
    /* @3904156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3904256;
    /* @3904160 constant */
    /* @3904164 cast */
    /* @3904168 load */
    /* @3904176 constant */
    /* @3904180 sub */
    /* @3904184 load */
    /* @3904192 call */
    GM_SITE(vm, 66, 3904192);
    /* @3904200 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3904208 load */
    /* @3904216 cast */
    /* @3904220 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3904252;
    L_3904224: ;
    /* @3904224 constant */
    /* @3904228 cast */
    /* @3904232 load */
    /* @3904240 call */
    GM_SITE(vm, 66, 3904240);
    /* @3904248 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3904252: ;
    /* @3904252 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904224;
    L_3904256: ;
    /* @3904256 constant */
    /* @3904260 cast */
    /* @3904264 call */
    GM_SITE(vm, 66, 3904264);
    /* @3904272 constant */
    /* @3904276 cmp */
    /* @3904280 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3904288;
    /* @3904284 b */
    goto L_3908224;
    L_3904288: ;
    /* @3904288 constant */
    /* @3904292 cast */
    /* @3904296 call */
    GM_SITE(vm, 66, 3904296);
    /* @3904304 constant */
    /* @3904308 cmp */
    /* @3904312 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3908224;
    /* @3904316 load */
    /* @3904324 constant */
    /* @3904328 cmp */
    /* @3904332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3904640;
    /* @3904336 constant */
    /* @3904340 cast */
    /* @3904344 load */
    /* @3904352 constant */
    /* @3904356 sub */
    /* @3904360 load */
    /* @3904368 call */
    GM_SITE(vm, 66, 3904368);
    /* @3904376 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3904384 load */
    /* @3904392 cast */
    /* @3904396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3904428;
    L_3904400: ;
    /* @3904400 constant */
    /* @3904404 cast */
    /* @3904408 load */
    /* @3904416 call */
    GM_SITE(vm, 66, 3904416);
    /* @3904424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3904428: ;
    /* @3904428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904400;
    /* @3904432 constant */
    /* @3904436 cast */
    /* @3904440 load */
    /* @3904448 constant */
    /* @3904452 sub */
    /* @3904456 load */
    /* @3904464 constant */
    /* @3904468 add */
    /* @3904472 call */
    GM_SITE(vm, 66, 3904472);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3904480 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3904488 load */
    /* @3904496 cast */
    /* @3904500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3904532;
    L_3904504: ;
    /* @3904504 constant */
    /* @3904508 cast */
    /* @3904512 load */
    /* @3904520 call */
    GM_SITE(vm, 66, 3904520);
    /* @3904528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3904532: ;
    /* @3904532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904504;
    /* @3904536 constant */
    /* @3904540 cast */
    /* @3904544 load */
    /* @3904552 constant */
    /* @3904556 sub */
    /* @3904560 load */
    /* @3904568 constant */
    /* @3904572 sub */
    /* @3904576 call */
    GM_SITE(vm, 66, 3904576);
    /* @3904584 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3904592 load */
    /* @3904600 cast */
    /* @3904604 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3904636;
    L_3904608: ;
    /* @3904608 constant */
    /* @3904612 cast */
    /* @3904616 load */
    /* @3904624 call */
    GM_SITE(vm, 66, 3904624);
    /* @3904632 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3904636: ;
    /* @3904636 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904608;
    L_3904640: ;
    /* @3904640 load */
    /* @3904648 constant */
    /* @3904652 cmp */
    /* @3904656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3905172;
    /* @3904660 constant */
    /* @3904664 cast */
    /* @3904668 load */
    /* @3904676 constant */
    /* @3904680 sub */
    /* @3904684 load */
    /* @3904692 call */
    GM_SITE(vm, 66, 3904692);
    /* @3904700 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v8);
    /* @3904708 load */
    /* @3904716 cast */
    /* @3904720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3904752;
    L_3904724: ;
    /* @3904724 constant */
    /* @3904728 cast */
    /* @3904732 load */
    /* @3904740 call */
    GM_SITE(vm, 66, 3904740);
    /* @3904748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3904752: ;
    /* @3904752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904724;
    /* @3904756 constant */
    /* @3904760 cast */
    /* @3904764 load */
    /* @3904772 constant */
    /* @3904776 sub */
    /* @3904780 load */
    /* @3904788 constant */
    /* @3904792 add */
    /* @3904796 call */
    GM_SITE(vm, 66, 3904796);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3904804 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v10);
    /* @3904812 load */
    /* @3904820 cast */
    /* @3904824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3904856;
    L_3904828: ;
    /* @3904828 constant */
    /* @3904832 cast */
    /* @3904836 load */
    /* @3904844 call */
    GM_SITE(vm, 66, 3904844);
    /* @3904852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3904856: ;
    /* @3904856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904828;
    /* @3904860 constant */
    /* @3904864 cast */
    /* @3904868 load */
    /* @3904876 constant */
    /* @3904880 sub */
    /* @3904884 load */
    /* @3904892 constant */
    /* @3904896 sub */
    /* @3904900 call */
    GM_SITE(vm, 66, 3904900);
    /* @3904908 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v11);
    /* @3904916 load */
    /* @3904924 cast */
    /* @3904928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3904960;
    L_3904932: ;
    /* @3904932 constant */
    /* @3904936 cast */
    /* @3904940 load */
    /* @3904948 call */
    GM_SITE(vm, 66, 3904948);
    /* @3904956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3904960: ;
    /* @3904960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3904932;
    /* @3904964 constant */
    /* @3904968 cast */
    /* @3904972 load */
    /* @3904980 constant */
    /* @3904984 sub */
    /* @3904988 load */
    /* @3904996 constant */
    /* @3905000 add */
    /* @3905004 call */
    GM_SITE(vm, 66, 3905004);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3905012 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v13);
    /* @3905020 load */
    /* @3905028 cast */
    /* @3905032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3905064;
    L_3905036: ;
    /* @3905036 constant */
    /* @3905040 cast */
    /* @3905044 load */
    /* @3905052 call */
    GM_SITE(vm, 66, 3905052);
    /* @3905060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3905064: ;
    /* @3905064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905036;
    /* @3905068 constant */
    /* @3905072 cast */
    /* @3905076 load */
    /* @3905084 constant */
    /* @3905088 sub */
    /* @3905092 load */
    /* @3905100 constant */
    /* @3905104 sub */
    /* @3905108 call */
    GM_SITE(vm, 66, 3905108);
    /* @3905116 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v14);
    /* @3905124 load */
    /* @3905132 cast */
    /* @3905136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3905168;
    L_3905140: ;
    /* @3905140 constant */
    /* @3905144 cast */
    /* @3905148 load */
    /* @3905156 call */
    GM_SITE(vm, 66, 3905156);
    /* @3905164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3905168: ;
    /* @3905168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905140;
    L_3905172: ;
    /* @3905172 load */
    /* @3905180 constant */
    /* @3905184 cmp */
    /* @3905188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3906120;
    /* @3905192 constant */
    /* @3905196 cast */
    /* @3905200 load */
    /* @3905208 constant */
    /* @3905212 sub */
    /* @3905216 load */
    /* @3905224 call */
    GM_SITE(vm, 66, 3905224);
    /* @3905232 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3905240 load */
    /* @3905248 cast */
    /* @3905252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3905284;
    L_3905256: ;
    /* @3905256 constant */
    /* @3905260 cast */
    /* @3905264 load */
    /* @3905272 call */
    GM_SITE(vm, 66, 3905272);
    /* @3905280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3905284: ;
    /* @3905284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905256;
    /* @3905288 constant */
    /* @3905292 cast */
    /* @3905296 load */
    /* @3905304 constant */
    /* @3905308 sub */
    /* @3905312 load */
    /* @3905320 constant */
    /* @3905324 add */
    /* @3905328 call */
    GM_SITE(vm, 66, 3905328);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3905336 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3905344 load */
    /* @3905352 cast */
    /* @3905356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3905388;
    L_3905360: ;
    /* @3905360 constant */
    /* @3905364 cast */
    /* @3905368 load */
    /* @3905376 call */
    GM_SITE(vm, 66, 3905376);
    /* @3905384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3905388: ;
    /* @3905388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905360;
    /* @3905392 constant */
    /* @3905396 cast */
    /* @3905400 load */
    /* @3905408 constant */
    /* @3905412 sub */
    /* @3905416 load */
    /* @3905424 constant */
    /* @3905428 sub */
    /* @3905432 call */
    GM_SITE(vm, 66, 3905432);
    /* @3905440 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3905448 load */
    /* @3905456 cast */
    /* @3905460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3905492;
    L_3905464: ;
    /* @3905464 constant */
    /* @3905468 cast */
    /* @3905472 load */
    /* @3905480 call */
    GM_SITE(vm, 66, 3905480);
    /* @3905488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3905492: ;
    /* @3905492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905464;
    /* @3905496 constant */
    /* @3905500 cast */
    /* @3905504 load */
    /* @3905512 constant */
    /* @3905516 sub */
    /* @3905520 load */
    /* @3905528 constant */
    /* @3905532 add */
    /* @3905536 call */
    GM_SITE(vm, 66, 3905536);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3905544 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3905552 load */
    /* @3905560 cast */
    /* @3905564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3905596;
    L_3905568: ;
    /* @3905568 constant */
    /* @3905572 cast */
    /* @3905576 load */
    /* @3905584 call */
    GM_SITE(vm, 66, 3905584);
    /* @3905592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3905596: ;
    /* @3905596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905568;
    /* @3905600 constant */
    /* @3905604 cast */
    /* @3905608 load */
    /* @3905616 constant */
    /* @3905620 sub */
    /* @3905624 load */
    /* @3905632 constant */
    /* @3905636 sub */
    /* @3905640 call */
    GM_SITE(vm, 66, 3905640);
    /* @3905648 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3905656 load */
    /* @3905664 cast */
    /* @3905668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3905700;
    L_3905672: ;
    /* @3905672 constant */
    /* @3905676 cast */
    /* @3905680 load */
    /* @3905688 call */
    GM_SITE(vm, 66, 3905688);
    /* @3905696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3905700: ;
    /* @3905700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905672;
    /* @3905704 constant */
    /* @3905708 cast */
    /* @3905712 load */
    /* @3905720 constant */
    /* @3905724 sub */
    /* @3905728 load */
    /* @3905736 constant */
    /* @3905740 sub */
    /* @3905744 call */
    GM_SITE(vm, 66, 3905744);
    /* @3905752 store */
    v22 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v22);
    /* @3905760 load */
    /* @3905768 cast */
    /* @3905772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3905804;
    L_3905776: ;
    /* @3905776 constant */
    /* @3905780 cast */
    /* @3905784 load */
    /* @3905792 call */
    GM_SITE(vm, 66, 3905792);
    /* @3905800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3905804: ;
    /* @3905804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905776;
    /* @3905808 constant */
    /* @3905812 cast */
    /* @3905816 load */
    /* @3905824 constant */
    /* @3905828 sub */
    /* @3905832 load */
    /* @3905840 constant */
    /* @3905844 add */
    /* @3905848 call */
    GM_SITE(vm, 66, 3905848);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3905856 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v24);
    /* @3905864 load */
    /* @3905872 cast */
    /* @3905876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3905908;
    L_3905880: ;
    /* @3905880 constant */
    /* @3905884 cast */
    /* @3905888 load */
    /* @3905896 call */
    GM_SITE(vm, 66, 3905896);
    /* @3905904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3905908: ;
    /* @3905908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905880;
    /* @3905912 constant */
    /* @3905916 cast */
    /* @3905920 load */
    /* @3905928 constant */
    /* @3905932 sub */
    /* @3905936 load */
    /* @3905944 constant */
    /* @3905948 sub */
    /* @3905952 call */
    GM_SITE(vm, 66, 3905952);
    /* @3905960 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v25);
    /* @3905968 load */
    /* @3905976 cast */
    /* @3905980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3906012;
    L_3905984: ;
    /* @3905984 constant */
    /* @3905988 cast */
    /* @3905992 load */
    /* @3906000 call */
    GM_SITE(vm, 66, 3906000);
    /* @3906008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3906012: ;
    /* @3906012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3905984;
    /* @3906016 constant */
    /* @3906020 cast */
    /* @3906024 load */
    /* @3906032 constant */
    /* @3906036 sub */
    /* @3906040 load */
    /* @3906048 constant */
    /* @3906052 add */
    /* @3906056 call */
    GM_SITE(vm, 66, 3906056);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3906064 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v27);
    /* @3906072 load */
    /* @3906080 cast */
    /* @3906084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3906116;
    L_3906088: ;
    /* @3906088 constant */
    /* @3906092 cast */
    /* @3906096 load */
    /* @3906104 call */
    GM_SITE(vm, 66, 3906104);
    /* @3906112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3906116: ;
    /* @3906116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906088;
    L_3906120: ;
    /* @3906120 load */
    /* @3906128 constant */
    /* @3906132 cmp */
    /* @3906136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3906964;
    /* @3906140 constant */
    /* @3906144 cast */
    /* @3906148 load */
    /* @3906156 constant */
    /* @3906160 sub */
    /* @3906164 load */
    /* @3906172 call */
    GM_SITE(vm, 66, 3906172);
    /* @3906180 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v28);
    /* @3906188 load */
    /* @3906196 cast */
    /* @3906200 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3906232;
    L_3906204: ;
    /* @3906204 constant */
    /* @3906208 cast */
    /* @3906212 load */
    /* @3906220 call */
    GM_SITE(vm, 66, 3906220);
    /* @3906228 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3906232: ;
    /* @3906232 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906204;
    /* @3906236 constant */
    /* @3906240 cast */
    /* @3906244 load */
    /* @3906252 constant */
    /* @3906256 sub */
    /* @3906260 load */
    /* @3906268 constant */
    /* @3906272 add */
    /* @3906276 call */
    GM_SITE(vm, 66, 3906276);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3906284 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v30);
    /* @3906292 load */
    /* @3906300 cast */
    /* @3906304 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3906336;
    L_3906308: ;
    /* @3906308 constant */
    /* @3906312 cast */
    /* @3906316 load */
    /* @3906324 call */
    GM_SITE(vm, 66, 3906324);
    /* @3906332 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3906336: ;
    /* @3906336 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906308;
    /* @3906340 constant */
    /* @3906344 cast */
    /* @3906348 load */
    /* @3906356 constant */
    /* @3906360 sub */
    /* @3906364 load */
    /* @3906372 constant */
    /* @3906376 sub */
    /* @3906380 call */
    GM_SITE(vm, 66, 3906380);
    /* @3906388 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v31);
    /* @3906396 load */
    /* @3906404 cast */
    /* @3906408 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3906440;
    L_3906412: ;
    /* @3906412 constant */
    /* @3906416 cast */
    /* @3906420 load */
    /* @3906428 call */
    GM_SITE(vm, 66, 3906428);
    /* @3906436 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3906440: ;
    /* @3906440 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906412;
    /* @3906444 constant */
    /* @3906448 cast */
    /* @3906452 load */
    /* @3906460 constant */
    /* @3906464 sub */
    /* @3906468 load */
    /* @3906476 constant */
    /* @3906480 add */
    /* @3906484 call */
    GM_SITE(vm, 66, 3906484);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3906492 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v33);
    /* @3906500 load */
    /* @3906508 cast */
    /* @3906512 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3906544;
    L_3906516: ;
    /* @3906516 constant */
    /* @3906520 cast */
    /* @3906524 load */
    /* @3906532 call */
    GM_SITE(vm, 66, 3906532);
    /* @3906540 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3906544: ;
    /* @3906544 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906516;
    /* @3906548 constant */
    /* @3906552 cast */
    /* @3906556 load */
    /* @3906564 constant */
    /* @3906568 sub */
    /* @3906572 load */
    /* @3906580 constant */
    /* @3906584 sub */
    /* @3906588 call */
    GM_SITE(vm, 66, 3906588);
    /* @3906596 store */
    v34 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v34);
    /* @3906604 load */
    /* @3906612 cast */
    /* @3906616 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3906648;
    L_3906620: ;
    /* @3906620 constant */
    /* @3906624 cast */
    /* @3906628 load */
    /* @3906636 call */
    GM_SITE(vm, 66, 3906636);
    /* @3906644 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3906648: ;
    /* @3906648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906620;
    /* @3906652 constant */
    /* @3906656 cast */
    /* @3906660 load */
    /* @3906668 constant */
    /* @3906672 sub */
    /* @3906676 load */
    /* @3906684 constant */
    /* @3906688 add */
    /* @3906692 call */
    GM_SITE(vm, 66, 3906692);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3906700 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v36);
    /* @3906708 load */
    /* @3906716 cast */
    /* @3906720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3906752;
    L_3906724: ;
    /* @3906724 constant */
    /* @3906728 cast */
    /* @3906732 load */
    /* @3906740 call */
    GM_SITE(vm, 66, 3906740);
    /* @3906748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3906752: ;
    /* @3906752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906724;
    /* @3906756 constant */
    /* @3906760 cast */
    /* @3906764 load */
    /* @3906772 constant */
    /* @3906776 sub */
    /* @3906780 load */
    /* @3906788 constant */
    /* @3906792 add */
    /* @3906796 call */
    GM_SITE(vm, 66, 3906796);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3906804 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v38);
    /* @3906812 load */
    /* @3906820 cast */
    /* @3906824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3906856;
    L_3906828: ;
    /* @3906828 constant */
    /* @3906832 cast */
    /* @3906836 load */
    /* @3906844 call */
    GM_SITE(vm, 66, 3906844);
    /* @3906852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3906856: ;
    /* @3906856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906828;
    /* @3906860 constant */
    /* @3906864 cast */
    /* @3906868 load */
    /* @3906876 constant */
    /* @3906880 sub */
    /* @3906884 load */
    /* @3906892 constant */
    /* @3906896 sub */
    /* @3906900 call */
    GM_SITE(vm, 66, 3906900);
    /* @3906908 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v39);
    /* @3906916 load */
    /* @3906924 cast */
    /* @3906928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3906960;
    L_3906932: ;
    /* @3906932 constant */
    /* @3906936 cast */
    /* @3906940 load */
    /* @3906948 call */
    GM_SITE(vm, 66, 3906948);
    /* @3906956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3906960: ;
    /* @3906960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3906932;
    L_3906964: ;
    /* @3906964 load */
    /* @3906972 constant */
    /* @3906976 cmp */
    /* @3906980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3908224;
    /* @3906984 constant */
    /* @3906988 cast */
    /* @3906992 load */
    /* @3907000 constant */
    /* @3907004 sub */
    /* @3907008 load */
    /* @3907016 call */
    GM_SITE(vm, 66, 3907016);
    /* @3907024 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v40);
    /* @3907032 load */
    /* @3907040 cast */
    /* @3907044 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3907076;
    L_3907048: ;
    /* @3907048 constant */
    /* @3907052 cast */
    /* @3907056 load */
    /* @3907064 call */
    GM_SITE(vm, 66, 3907064);
    /* @3907072 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3907076: ;
    /* @3907076 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907048;
    /* @3907080 constant */
    /* @3907084 cast */
    /* @3907088 load */
    /* @3907096 constant */
    /* @3907100 sub */
    /* @3907104 load */
    /* @3907112 constant */
    /* @3907116 add */
    /* @3907120 call */
    GM_SITE(vm, 66, 3907120);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3907128 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v42);
    /* @3907136 load */
    /* @3907144 cast */
    /* @3907148 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3907180;
    L_3907152: ;
    /* @3907152 constant */
    /* @3907156 cast */
    /* @3907160 load */
    /* @3907168 call */
    GM_SITE(vm, 66, 3907168);
    /* @3907176 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3907180: ;
    /* @3907180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907152;
    /* @3907184 constant */
    /* @3907188 cast */
    /* @3907192 load */
    /* @3907200 constant */
    /* @3907204 sub */
    /* @3907208 load */
    /* @3907216 constant */
    /* @3907220 sub */
    /* @3907224 call */
    GM_SITE(vm, 66, 3907224);
    /* @3907232 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v43);
    /* @3907240 load */
    /* @3907248 cast */
    /* @3907252 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3907284;
    L_3907256: ;
    /* @3907256 constant */
    /* @3907260 cast */
    /* @3907264 load */
    /* @3907272 call */
    GM_SITE(vm, 66, 3907272);
    /* @3907280 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3907284: ;
    /* @3907284 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907256;
    /* @3907288 constant */
    /* @3907292 cast */
    /* @3907296 load */
    /* @3907304 constant */
    /* @3907308 sub */
    /* @3907312 load */
    /* @3907320 constant */
    /* @3907324 add */
    /* @3907328 call */
    GM_SITE(vm, 66, 3907328);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3907336 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v45);
    /* @3907344 load */
    /* @3907352 cast */
    /* @3907356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3907388;
    L_3907360: ;
    /* @3907360 constant */
    /* @3907364 cast */
    /* @3907368 load */
    /* @3907376 call */
    GM_SITE(vm, 66, 3907376);
    /* @3907384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3907388: ;
    /* @3907388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907360;
    /* @3907392 constant */
    /* @3907396 cast */
    /* @3907400 load */
    /* @3907408 constant */
    /* @3907412 sub */
    /* @3907416 load */
    /* @3907424 constant */
    /* @3907428 sub */
    /* @3907432 call */
    GM_SITE(vm, 66, 3907432);
    /* @3907440 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v46);
    /* @3907448 load */
    /* @3907456 cast */
    /* @3907460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3907492;
    L_3907464: ;
    /* @3907464 constant */
    /* @3907468 cast */
    /* @3907472 load */
    /* @3907480 call */
    GM_SITE(vm, 66, 3907480);
    /* @3907488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3907492: ;
    /* @3907492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907464;
    /* @3907496 constant */
    /* @3907500 cast */
    /* @3907504 load */
    /* @3907512 constant */
    /* @3907516 sub */
    /* @3907520 load */
    /* @3907528 constant */
    /* @3907532 add */
    /* @3907536 call */
    GM_SITE(vm, 66, 3907536);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3907544 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v48);
    /* @3907552 load */
    /* @3907560 cast */
    /* @3907564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3907596;
    L_3907568: ;
    /* @3907568 constant */
    /* @3907572 cast */
    /* @3907576 load */
    /* @3907584 call */
    GM_SITE(vm, 66, 3907584);
    /* @3907592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3907596: ;
    /* @3907596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907568;
    /* @3907600 constant */
    /* @3907604 cast */
    /* @3907608 load */
    /* @3907616 constant */
    /* @3907620 sub */
    /* @3907624 load */
    /* @3907632 constant */
    /* @3907636 add */
    /* @3907640 call */
    GM_SITE(vm, 66, 3907640);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3907648 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v50);
    /* @3907656 load */
    /* @3907664 cast */
    /* @3907668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3907700;
    L_3907672: ;
    /* @3907672 constant */
    /* @3907676 cast */
    /* @3907680 load */
    /* @3907688 call */
    GM_SITE(vm, 66, 3907688);
    /* @3907696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3907700: ;
    /* @3907700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907672;
    /* @3907704 constant */
    /* @3907708 cast */
    /* @3907712 load */
    /* @3907720 constant */
    /* @3907724 sub */
    /* @3907728 load */
    /* @3907736 constant */
    /* @3907740 sub */
    /* @3907744 call */
    GM_SITE(vm, 66, 3907744);
    /* @3907752 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v51);
    /* @3907760 load */
    /* @3907768 cast */
    /* @3907772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3907804;
    L_3907776: ;
    /* @3907776 constant */
    /* @3907780 cast */
    /* @3907784 load */
    /* @3907792 call */
    GM_SITE(vm, 66, 3907792);
    /* @3907800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3907804: ;
    /* @3907804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907776;
    /* @3907808 constant */
    /* @3907812 cast */
    /* @3907816 load */
    /* @3907824 constant */
    /* @3907828 sub */
    /* @3907832 load */
    /* @3907840 constant */
    /* @3907844 add */
    /* @3907848 call */
    GM_SITE(vm, 66, 3907848);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3907856 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v53);
    /* @3907864 load */
    /* @3907872 cast */
    /* @3907876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3907908;
    L_3907880: ;
    /* @3907880 constant */
    /* @3907884 cast */
    /* @3907888 load */
    /* @3907896 call */
    GM_SITE(vm, 66, 3907896);
    /* @3907904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3907908: ;
    /* @3907908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907880;
    /* @3907912 constant */
    /* @3907916 cast */
    /* @3907920 load */
    /* @3907928 constant */
    /* @3907932 sub */
    /* @3907936 load */
    /* @3907944 constant */
    /* @3907948 sub */
    /* @3907952 call */
    GM_SITE(vm, 66, 3907952);
    /* @3907960 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v54);
    /* @3907968 load */
    /* @3907976 cast */
    /* @3907980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3908012;
    L_3907984: ;
    /* @3907984 constant */
    /* @3907988 cast */
    /* @3907992 load */
    /* @3908000 call */
    GM_SITE(vm, 66, 3908000);
    /* @3908008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3908012: ;
    /* @3908012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3907984;
    /* @3908016 constant */
    /* @3908020 cast */
    /* @3908024 load */
    /* @3908032 constant */
    /* @3908036 sub */
    /* @3908040 load */
    /* @3908048 constant */
    /* @3908052 sub */
    /* @3908056 call */
    GM_SITE(vm, 66, 3908056);
    /* @3908064 store */
    v55 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v55);
    /* @3908072 load */
    /* @3908080 cast */
    /* @3908084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3908116;
    L_3908088: ;
    /* @3908088 constant */
    /* @3908092 cast */
    /* @3908096 load */
    /* @3908104 call */
    GM_SITE(vm, 66, 3908104);
    /* @3908112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3908116: ;
    /* @3908116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3908088;
    /* @3908120 constant */
    /* @3908124 cast */
    /* @3908128 load */
    /* @3908136 constant */
    /* @3908140 sub */
    /* @3908144 load */
    /* @3908152 constant */
    /* @3908156 add */
    /* @3908160 call */
    GM_SITE(vm, 66, 3908160);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3908168 store */
    v57 = GM_CALL(vm, "instance_create", 3, v56, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v57);
    /* @3908176 load */
    /* @3908184 cast */
    /* @3908188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3908220;
    L_3908192: ;
    /* @3908192 constant */
    /* @3908196 cast */
    /* @3908200 load */
    /* @3908208 call */
    GM_SITE(vm, 66, 3908208);
    /* @3908216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3908220: ;
    /* @3908220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3908192;
    L_3908224: ;
    /* @3908224 call */
    GM_SITE(vm, 66, 3908224);
    /* @3908232 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3908236: ;
    return;
}
