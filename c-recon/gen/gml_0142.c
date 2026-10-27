/* generated from CODE 142 (gml_Object_obj_wolf_Alarm_0), source start 3958824, end 3963704. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0142(GmVM* vm) {
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
    /* @3958824 load */
    /* @3958832 constant */
    /* @3958836 cmp */
    /* @3958840 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3958848;
    /* @3958844 b */
    goto L_3958904;
    L_3958848: ;
    /* @3958848 load */
    /* @3958856 constant */
    /* @3958860 cmp */
    /* @3958864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3958904;
    /* @3958868 constant */
    /* @3958872 cast */
    /* @3958876 constant */
    /* @3958880 cast */
    /* @3958884 constant */
    /* @3958888 cast */
    /* @3958892 call */
    GM_SITE(vm, 142, 3958892);
    /* @3958900 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3958904: ;
    /* @3958904 load */
    /* @3958912 constant */
    /* @3958916 cmp */
    /* @3958920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3958968;
    /* @3958924 constant */
    /* @3958928 cast */
    /* @3958932 load */
    /* @3958940 constant */
    /* @3958944 sub */
    /* @3958948 load */
    /* @3958956 call */
    GM_SITE(vm, 142, 3958956);
    /* @3958964 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3958968: ;
    /* @3958968 load */
    /* @3958976 constant */
    /* @3958980 cmp */
    /* @3958984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3959032;
    /* @3958988 constant */
    /* @3958992 cast */
    /* @3958996 load */
    /* @3959004 constant */
    /* @3959008 sub */
    /* @3959012 load */
    /* @3959020 call */
    GM_SITE(vm, 142, 3959020);
    /* @3959028 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3959032: ;
    /* @3959032 load */
    /* @3959040 constant */
    /* @3959044 cmp */
    /* @3959048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3959148;
    /* @3959052 constant */
    /* @3959056 cast */
    /* @3959060 load */
    /* @3959068 constant */
    /* @3959072 sub */
    /* @3959076 load */
    /* @3959084 call */
    GM_SITE(vm, 142, 3959084);
    /* @3959092 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3959100 load */
    /* @3959108 cast */
    /* @3959112 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3959144;
    L_3959116: ;
    /* @3959116 constant */
    /* @3959120 cast */
    /* @3959124 load */
    /* @3959132 call */
    GM_SITE(vm, 142, 3959132);
    /* @3959140 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3959144: ;
    /* @3959144 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959116;
    L_3959148: ;
    /* @3959148 constant */
    /* @3959152 cast */
    /* @3959156 call */
    GM_SITE(vm, 142, 3959156);
    /* @3959164 constant */
    /* @3959168 cmp */
    /* @3959172 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3959180;
    /* @3959176 b */
    goto L_3963692;
    L_3959180: ;
    /* @3959180 constant */
    /* @3959184 cast */
    /* @3959188 call */
    GM_SITE(vm, 142, 3959188);
    /* @3959196 constant */
    /* @3959200 cmp */
    /* @3959204 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3963692;
    /* @3959208 load */
    /* @3959216 constant */
    /* @3959220 cmp */
    /* @3959224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3959740;
    /* @3959228 constant */
    /* @3959232 cast */
    /* @3959236 load */
    /* @3959244 constant */
    /* @3959248 sub */
    /* @3959252 load */
    /* @3959260 call */
    GM_SITE(vm, 142, 3959260);
    /* @3959268 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3959276 load */
    /* @3959284 cast */
    /* @3959288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3959320;
    L_3959292: ;
    /* @3959292 constant */
    /* @3959296 cast */
    /* @3959300 load */
    /* @3959308 call */
    GM_SITE(vm, 142, 3959308);
    /* @3959316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3959320: ;
    /* @3959320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959292;
    /* @3959324 constant */
    /* @3959328 cast */
    /* @3959332 load */
    /* @3959340 constant */
    /* @3959344 sub */
    /* @3959348 load */
    /* @3959356 constant */
    /* @3959360 add */
    /* @3959364 call */
    GM_SITE(vm, 142, 3959364);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3959372 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3959380 load */
    /* @3959388 cast */
    /* @3959392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3959424;
    L_3959396: ;
    /* @3959396 constant */
    /* @3959400 cast */
    /* @3959404 load */
    /* @3959412 call */
    GM_SITE(vm, 142, 3959412);
    /* @3959420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3959424: ;
    /* @3959424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959396;
    /* @3959428 constant */
    /* @3959432 cast */
    /* @3959436 load */
    /* @3959444 constant */
    /* @3959448 sub */
    /* @3959452 load */
    /* @3959460 constant */
    /* @3959464 sub */
    /* @3959468 call */
    GM_SITE(vm, 142, 3959468);
    /* @3959476 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3959484 load */
    /* @3959492 cast */
    /* @3959496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3959528;
    L_3959500: ;
    /* @3959500 constant */
    /* @3959504 cast */
    /* @3959508 load */
    /* @3959516 call */
    GM_SITE(vm, 142, 3959516);
    /* @3959524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3959528: ;
    /* @3959528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959500;
    /* @3959532 constant */
    /* @3959536 cast */
    /* @3959540 load */
    /* @3959548 constant */
    /* @3959552 sub */
    /* @3959556 load */
    /* @3959564 constant */
    /* @3959568 add */
    /* @3959572 call */
    GM_SITE(vm, 142, 3959572);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3959580 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3959588 load */
    /* @3959596 cast */
    /* @3959600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3959632;
    L_3959604: ;
    /* @3959604 constant */
    /* @3959608 cast */
    /* @3959612 load */
    /* @3959620 call */
    GM_SITE(vm, 142, 3959620);
    /* @3959628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3959632: ;
    /* @3959632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959604;
    /* @3959636 constant */
    /* @3959640 cast */
    /* @3959644 load */
    /* @3959652 constant */
    /* @3959656 sub */
    /* @3959660 load */
    /* @3959668 constant */
    /* @3959672 sub */
    /* @3959676 call */
    GM_SITE(vm, 142, 3959676);
    /* @3959684 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3959692 load */
    /* @3959700 cast */
    /* @3959704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3959736;
    L_3959708: ;
    /* @3959708 constant */
    /* @3959712 cast */
    /* @3959716 load */
    /* @3959724 call */
    GM_SITE(vm, 142, 3959724);
    /* @3959732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3959736: ;
    /* @3959736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959708;
    L_3959740: ;
    /* @3959740 load */
    /* @3959748 constant */
    /* @3959752 cmp */
    /* @3959756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3960688;
    /* @3959760 constant */
    /* @3959764 cast */
    /* @3959768 load */
    /* @3959776 constant */
    /* @3959780 sub */
    /* @3959784 load */
    /* @3959792 call */
    GM_SITE(vm, 142, 3959792);
    /* @3959800 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3959808 load */
    /* @3959816 cast */
    /* @3959820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3959852;
    L_3959824: ;
    /* @3959824 constant */
    /* @3959828 cast */
    /* @3959832 load */
    /* @3959840 call */
    GM_SITE(vm, 142, 3959840);
    /* @3959848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3959852: ;
    /* @3959852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959824;
    /* @3959856 constant */
    /* @3959860 cast */
    /* @3959864 load */
    /* @3959872 constant */
    /* @3959876 sub */
    /* @3959880 load */
    /* @3959888 constant */
    /* @3959892 add */
    /* @3959896 call */
    GM_SITE(vm, 142, 3959896);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3959904 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3959912 load */
    /* @3959920 cast */
    /* @3959924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3959956;
    L_3959928: ;
    /* @3959928 constant */
    /* @3959932 cast */
    /* @3959936 load */
    /* @3959944 call */
    GM_SITE(vm, 142, 3959944);
    /* @3959952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3959956: ;
    /* @3959956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3959928;
    /* @3959960 constant */
    /* @3959964 cast */
    /* @3959968 load */
    /* @3959976 constant */
    /* @3959980 sub */
    /* @3959984 load */
    /* @3959992 constant */
    /* @3959996 sub */
    /* @3960000 call */
    GM_SITE(vm, 142, 3960000);
    /* @3960008 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3960016 load */
    /* @3960024 cast */
    /* @3960028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3960060;
    L_3960032: ;
    /* @3960032 constant */
    /* @3960036 cast */
    /* @3960040 load */
    /* @3960048 call */
    GM_SITE(vm, 142, 3960048);
    /* @3960056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3960060: ;
    /* @3960060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960032;
    /* @3960064 constant */
    /* @3960068 cast */
    /* @3960072 load */
    /* @3960080 constant */
    /* @3960084 sub */
    /* @3960088 load */
    /* @3960096 constant */
    /* @3960100 add */
    /* @3960104 call */
    GM_SITE(vm, 142, 3960104);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3960112 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3960120 load */
    /* @3960128 cast */
    /* @3960132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3960164;
    L_3960136: ;
    /* @3960136 constant */
    /* @3960140 cast */
    /* @3960144 load */
    /* @3960152 call */
    GM_SITE(vm, 142, 3960152);
    /* @3960160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3960164: ;
    /* @3960164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960136;
    /* @3960168 constant */
    /* @3960172 cast */
    /* @3960176 load */
    /* @3960184 constant */
    /* @3960188 sub */
    /* @3960192 load */
    /* @3960200 constant */
    /* @3960204 sub */
    /* @3960208 call */
    GM_SITE(vm, 142, 3960208);
    /* @3960216 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3960224 load */
    /* @3960232 cast */
    /* @3960236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3960268;
    L_3960240: ;
    /* @3960240 constant */
    /* @3960244 cast */
    /* @3960248 load */
    /* @3960256 call */
    GM_SITE(vm, 142, 3960256);
    /* @3960264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3960268: ;
    /* @3960268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960240;
    /* @3960272 constant */
    /* @3960276 cast */
    /* @3960280 load */
    /* @3960288 constant */
    /* @3960292 sub */
    /* @3960296 load */
    /* @3960304 constant */
    /* @3960308 sub */
    /* @3960312 call */
    GM_SITE(vm, 142, 3960312);
    /* @3960320 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3960328 load */
    /* @3960336 cast */
    /* @3960340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3960372;
    L_3960344: ;
    /* @3960344 constant */
    /* @3960348 cast */
    /* @3960352 load */
    /* @3960360 call */
    GM_SITE(vm, 142, 3960360);
    /* @3960368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3960372: ;
    /* @3960372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960344;
    /* @3960376 constant */
    /* @3960380 cast */
    /* @3960384 load */
    /* @3960392 constant */
    /* @3960396 sub */
    /* @3960400 load */
    /* @3960408 constant */
    /* @3960412 add */
    /* @3960416 call */
    GM_SITE(vm, 142, 3960416);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3960424 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @3960432 load */
    /* @3960440 cast */
    /* @3960444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3960476;
    L_3960448: ;
    /* @3960448 constant */
    /* @3960452 cast */
    /* @3960456 load */
    /* @3960464 call */
    GM_SITE(vm, 142, 3960464);
    /* @3960472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3960476: ;
    /* @3960476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960448;
    /* @3960480 constant */
    /* @3960484 cast */
    /* @3960488 load */
    /* @3960496 constant */
    /* @3960500 sub */
    /* @3960504 load */
    /* @3960512 constant */
    /* @3960516 sub */
    /* @3960520 call */
    GM_SITE(vm, 142, 3960520);
    /* @3960528 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v21);
    /* @3960536 load */
    /* @3960544 cast */
    /* @3960548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3960580;
    L_3960552: ;
    /* @3960552 constant */
    /* @3960556 cast */
    /* @3960560 load */
    /* @3960568 call */
    GM_SITE(vm, 142, 3960568);
    /* @3960576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3960580: ;
    /* @3960580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960552;
    /* @3960584 constant */
    /* @3960588 cast */
    /* @3960592 load */
    /* @3960600 constant */
    /* @3960604 sub */
    /* @3960608 load */
    /* @3960616 constant */
    /* @3960620 add */
    /* @3960624 call */
    GM_SITE(vm, 142, 3960624);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3960632 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v23);
    /* @3960640 load */
    /* @3960648 cast */
    /* @3960652 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3960684;
    L_3960656: ;
    /* @3960656 constant */
    /* @3960660 cast */
    /* @3960664 load */
    /* @3960672 call */
    GM_SITE(vm, 142, 3960672);
    /* @3960680 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3960684: ;
    /* @3960684 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960656;
    L_3960688: ;
    /* @3960688 load */
    /* @3960696 constant */
    /* @3960700 cmp */
    /* @3960704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3961692;
    /* @3960708 constant */
    /* @3960712 cast */
    /* @3960716 load */
    /* @3960724 constant */
    /* @3960728 sub */
    /* @3960732 load */
    /* @3960740 call */
    GM_SITE(vm, 142, 3960740);
    /* @3960748 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v24);
    /* @3960756 load */
    /* @3960764 cast */
    /* @3960768 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3960800;
    L_3960772: ;
    /* @3960772 constant */
    /* @3960776 cast */
    /* @3960780 load */
    /* @3960788 call */
    GM_SITE(vm, 142, 3960788);
    /* @3960796 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3960800: ;
    /* @3960800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960772;
    /* @3960804 constant */
    /* @3960808 cast */
    /* @3960812 load */
    /* @3960820 constant */
    /* @3960824 sub */
    /* @3960828 load */
    /* @3960836 constant */
    /* @3960840 add */
    /* @3960844 call */
    GM_SITE(vm, 142, 3960844);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3960852 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v26);
    /* @3960860 load */
    /* @3960868 cast */
    /* @3960872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3960904;
    L_3960876: ;
    /* @3960876 constant */
    /* @3960880 cast */
    /* @3960884 load */
    /* @3960892 call */
    GM_SITE(vm, 142, 3960892);
    /* @3960900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3960904: ;
    /* @3960904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960876;
    /* @3960908 constant */
    /* @3960912 cast */
    /* @3960916 load */
    /* @3960924 constant */
    /* @3960928 sub */
    /* @3960932 load */
    /* @3960940 constant */
    /* @3960944 sub */
    /* @3960948 call */
    GM_SITE(vm, 142, 3960948);
    /* @3960956 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v27);
    /* @3960964 load */
    /* @3960972 cast */
    /* @3960976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3961008;
    L_3960980: ;
    /* @3960980 constant */
    /* @3960984 cast */
    /* @3960988 load */
    /* @3960996 call */
    GM_SITE(vm, 142, 3960996);
    /* @3961004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3961008: ;
    /* @3961008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3960980;
    /* @3961012 constant */
    /* @3961016 cast */
    /* @3961020 load */
    /* @3961028 constant */
    /* @3961032 sub */
    /* @3961036 load */
    /* @3961044 constant */
    /* @3961048 add */
    /* @3961052 call */
    GM_SITE(vm, 142, 3961052);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3961060 store */
    v29 = GM_CALL(vm, "instance_create", 3, v28, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v29);
    /* @3961068 load */
    /* @3961076 cast */
    /* @3961080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3961112;
    L_3961084: ;
    /* @3961084 constant */
    /* @3961088 cast */
    /* @3961092 load */
    /* @3961100 call */
    GM_SITE(vm, 142, 3961100);
    /* @3961108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3961112: ;
    /* @3961112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961084;
    /* @3961116 constant */
    /* @3961120 cast */
    /* @3961124 load */
    /* @3961132 constant */
    /* @3961136 sub */
    /* @3961140 load */
    /* @3961148 constant */
    /* @3961152 sub */
    /* @3961156 call */
    GM_SITE(vm, 142, 3961156);
    /* @3961164 store */
    v30 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v30);
    /* @3961172 load */
    /* @3961180 cast */
    /* @3961184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3961216;
    L_3961188: ;
    /* @3961188 constant */
    /* @3961192 cast */
    /* @3961196 load */
    /* @3961204 call */
    GM_SITE(vm, 142, 3961204);
    /* @3961212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3961216: ;
    /* @3961216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961188;
    /* @3961220 constant */
    /* @3961224 cast */
    /* @3961228 load */
    /* @3961236 constant */
    /* @3961240 sub */
    /* @3961244 load */
    /* @3961252 constant */
    /* @3961256 sub */
    /* @3961260 call */
    GM_SITE(vm, 142, 3961260);
    /* @3961268 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v31);
    /* @3961276 load */
    /* @3961284 cast */
    /* @3961288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3961320;
    L_3961292: ;
    /* @3961292 constant */
    /* @3961296 cast */
    /* @3961300 load */
    /* @3961308 call */
    GM_SITE(vm, 142, 3961308);
    /* @3961316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3961320: ;
    /* @3961320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961292;
    /* @3961324 constant */
    /* @3961328 cast */
    /* @3961332 load */
    /* @3961340 constant */
    /* @3961344 sub */
    /* @3961348 load */
    /* @3961356 constant */
    /* @3961360 add */
    /* @3961364 call */
    GM_SITE(vm, 142, 3961364);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3961372 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v33);
    /* @3961380 load */
    /* @3961388 cast */
    /* @3961392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3961424;
    L_3961396: ;
    /* @3961396 constant */
    /* @3961400 cast */
    /* @3961404 load */
    /* @3961412 call */
    GM_SITE(vm, 142, 3961412);
    /* @3961420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3961424: ;
    /* @3961424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961396;
    /* @3961428 constant */
    /* @3961432 cast */
    /* @3961436 load */
    /* @3961444 constant */
    /* @3961448 sub */
    /* @3961452 load */
    /* @3961460 constant */
    /* @3961464 sub */
    /* @3961468 call */
    GM_SITE(vm, 142, 3961468);
    /* @3961476 store */
    v34 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v34);
    /* @3961484 load */
    /* @3961492 cast */
    /* @3961496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3961528;
    L_3961500: ;
    /* @3961500 constant */
    /* @3961504 cast */
    /* @3961508 load */
    /* @3961516 call */
    GM_SITE(vm, 142, 3961516);
    /* @3961524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3961528: ;
    /* @3961528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961500;
    /* @3961532 constant */
    /* @3961536 cast */
    /* @3961540 load */
    /* @3961548 constant */
    /* @3961552 sub */
    /* @3961556 load */
    /* @3961564 constant */
    /* @3961568 add */
    /* @3961572 call */
    GM_SITE(vm, 142, 3961572);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3961580 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v36);
    /* @3961588 load */
    /* @3961596 cast */
    /* @3961600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3961632;
    L_3961604: ;
    /* @3961604 constant */
    /* @3961608 cast */
    /* @3961612 load */
    /* @3961620 call */
    GM_SITE(vm, 142, 3961620);
    /* @3961628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3961632: ;
    /* @3961632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961604;
    /* @3961636 constant */
    /* @3961640 cast */
    /* @3961644 load */
    /* @3961652 constant */
    /* @3961656 sub */
    /* @3961660 load */
    /* @3961668 constant */
    /* @3961672 sub */
    /* @3961676 call */
    GM_SITE(vm, 142, 3961676);
    /* @3961684 store */
    v37 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v37);
    L_3961692: ;
    /* @3961692 load */
    /* @3961700 constant */
    /* @3961704 cmp */
    /* @3961708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3962640;
    /* @3961712 constant */
    /* @3961716 cast */
    /* @3961720 load */
    /* @3961728 constant */
    /* @3961732 sub */
    /* @3961736 load */
    /* @3961744 call */
    GM_SITE(vm, 142, 3961744);
    /* @3961752 store */
    v38 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v38);
    /* @3961760 load */
    /* @3961768 cast */
    /* @3961772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3961804;
    L_3961776: ;
    /* @3961776 constant */
    /* @3961780 cast */
    /* @3961784 load */
    /* @3961792 call */
    GM_SITE(vm, 142, 3961792);
    /* @3961800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3961804: ;
    /* @3961804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961776;
    /* @3961808 constant */
    /* @3961812 cast */
    /* @3961816 load */
    /* @3961824 constant */
    /* @3961828 sub */
    /* @3961832 load */
    /* @3961840 constant */
    /* @3961844 add */
    /* @3961848 call */
    GM_SITE(vm, 142, 3961848);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3961856 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v40);
    /* @3961864 load */
    /* @3961872 cast */
    /* @3961876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3961908;
    L_3961880: ;
    /* @3961880 constant */
    /* @3961884 cast */
    /* @3961888 load */
    /* @3961896 call */
    GM_SITE(vm, 142, 3961896);
    /* @3961904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3961908: ;
    /* @3961908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961880;
    /* @3961912 constant */
    /* @3961916 cast */
    /* @3961920 load */
    /* @3961928 constant */
    /* @3961932 sub */
    /* @3961936 load */
    /* @3961944 constant */
    /* @3961948 sub */
    /* @3961952 call */
    GM_SITE(vm, 142, 3961952);
    /* @3961960 store */
    v41 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v41);
    /* @3961968 load */
    /* @3961976 cast */
    /* @3961980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3962012;
    L_3961984: ;
    /* @3961984 constant */
    /* @3961988 cast */
    /* @3961992 load */
    /* @3962000 call */
    GM_SITE(vm, 142, 3962000);
    /* @3962008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3962012: ;
    /* @3962012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3961984;
    /* @3962016 constant */
    /* @3962020 cast */
    /* @3962024 load */
    /* @3962032 constant */
    /* @3962036 sub */
    /* @3962040 load */
    /* @3962048 constant */
    /* @3962052 add */
    /* @3962056 call */
    GM_SITE(vm, 142, 3962056);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3962064 store */
    v43 = GM_CALL(vm, "instance_create", 3, v42, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v43);
    /* @3962072 load */
    /* @3962080 cast */
    /* @3962084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3962116;
    L_3962088: ;
    /* @3962088 constant */
    /* @3962092 cast */
    /* @3962096 load */
    /* @3962104 call */
    GM_SITE(vm, 142, 3962104);
    /* @3962112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3962116: ;
    /* @3962116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962088;
    /* @3962120 constant */
    /* @3962124 cast */
    /* @3962128 load */
    /* @3962136 constant */
    /* @3962140 sub */
    /* @3962144 load */
    /* @3962152 constant */
    /* @3962156 sub */
    /* @3962160 call */
    GM_SITE(vm, 142, 3962160);
    /* @3962168 store */
    v44 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v44);
    /* @3962176 load */
    /* @3962184 cast */
    /* @3962188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3962220;
    L_3962192: ;
    /* @3962192 constant */
    /* @3962196 cast */
    /* @3962200 load */
    /* @3962208 call */
    GM_SITE(vm, 142, 3962208);
    /* @3962216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3962220: ;
    /* @3962220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962192;
    /* @3962224 constant */
    /* @3962228 cast */
    /* @3962232 load */
    /* @3962240 constant */
    /* @3962244 sub */
    /* @3962248 load */
    /* @3962256 constant */
    /* @3962260 add */
    /* @3962264 call */
    GM_SITE(vm, 142, 3962264);
    v45 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3962272 store */
    v46 = GM_CALL(vm, "instance_create", 3, v45, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v46);
    /* @3962280 load */
    /* @3962288 cast */
    /* @3962292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3962324;
    L_3962296: ;
    /* @3962296 constant */
    /* @3962300 cast */
    /* @3962304 load */
    /* @3962312 call */
    GM_SITE(vm, 142, 3962312);
    /* @3962320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3962324: ;
    /* @3962324 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962296;
    /* @3962328 constant */
    /* @3962332 cast */
    /* @3962336 load */
    /* @3962344 constant */
    /* @3962348 sub */
    /* @3962352 load */
    /* @3962360 constant */
    /* @3962364 add */
    /* @3962368 call */
    GM_SITE(vm, 142, 3962368);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3962376 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v48);
    /* @3962384 load */
    /* @3962392 cast */
    /* @3962396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3962428;
    L_3962400: ;
    /* @3962400 constant */
    /* @3962404 cast */
    /* @3962408 load */
    /* @3962416 call */
    GM_SITE(vm, 142, 3962416);
    /* @3962424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3962428: ;
    /* @3962428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962400;
    /* @3962432 constant */
    /* @3962436 cast */
    /* @3962440 load */
    /* @3962448 constant */
    /* @3962452 sub */
    /* @3962456 load */
    /* @3962464 constant */
    /* @3962468 sub */
    /* @3962472 call */
    GM_SITE(vm, 142, 3962472);
    /* @3962480 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v49);
    /* @3962488 load */
    /* @3962496 cast */
    /* @3962500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3962532;
    L_3962504: ;
    /* @3962504 constant */
    /* @3962508 cast */
    /* @3962512 load */
    /* @3962520 call */
    GM_SITE(vm, 142, 3962520);
    /* @3962528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3962532: ;
    /* @3962532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962504;
    /* @3962536 constant */
    /* @3962540 cast */
    /* @3962544 load */
    /* @3962552 constant */
    /* @3962556 sub */
    /* @3962560 load */
    /* @3962568 constant */
    /* @3962572 add */
    /* @3962576 call */
    GM_SITE(vm, 142, 3962576);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3962584 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v51);
    /* @3962592 load */
    /* @3962600 cast */
    /* @3962604 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3962636;
    L_3962608: ;
    /* @3962608 constant */
    /* @3962612 cast */
    /* @3962616 load */
    /* @3962624 call */
    GM_SITE(vm, 142, 3962624);
    /* @3962632 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3962636: ;
    /* @3962636 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962608;
    L_3962640: ;
    /* @3962640 load */
    /* @3962648 constant */
    /* @3962652 cmp */
    /* @3962656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3963692;
    /* @3962660 constant */
    /* @3962664 cast */
    /* @3962668 load */
    /* @3962676 constant */
    /* @3962680 sub */
    /* @3962684 load */
    /* @3962692 call */
    GM_SITE(vm, 142, 3962692);
    /* @3962700 store */
    v52 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v52);
    /* @3962708 load */
    /* @3962716 cast */
    /* @3962720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3962752;
    L_3962724: ;
    /* @3962724 constant */
    /* @3962728 cast */
    /* @3962732 load */
    /* @3962740 call */
    GM_SITE(vm, 142, 3962740);
    /* @3962748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3962752: ;
    /* @3962752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962724;
    /* @3962756 constant */
    /* @3962760 cast */
    /* @3962764 load */
    /* @3962772 constant */
    /* @3962776 sub */
    /* @3962780 load */
    /* @3962788 constant */
    /* @3962792 add */
    /* @3962796 call */
    GM_SITE(vm, 142, 3962796);
    v53 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3962804 store */
    v54 = GM_CALL(vm, "instance_create", 3, v53, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v54);
    /* @3962812 load */
    /* @3962820 cast */
    /* @3962824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3962856;
    L_3962828: ;
    /* @3962828 constant */
    /* @3962832 cast */
    /* @3962836 load */
    /* @3962844 call */
    GM_SITE(vm, 142, 3962844);
    /* @3962852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3962856: ;
    /* @3962856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962828;
    /* @3962860 constant */
    /* @3962864 cast */
    /* @3962868 load */
    /* @3962876 constant */
    /* @3962880 sub */
    /* @3962884 load */
    /* @3962892 constant */
    /* @3962896 sub */
    /* @3962900 call */
    GM_SITE(vm, 142, 3962900);
    /* @3962908 store */
    v55 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v55);
    /* @3962916 load */
    /* @3962924 cast */
    /* @3962928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3962960;
    L_3962932: ;
    /* @3962932 constant */
    /* @3962936 cast */
    /* @3962940 load */
    /* @3962948 call */
    GM_SITE(vm, 142, 3962948);
    /* @3962956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3962960: ;
    /* @3962960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3962932;
    /* @3962964 constant */
    /* @3962968 cast */
    /* @3962972 load */
    /* @3962980 constant */
    /* @3962984 sub */
    /* @3962988 load */
    /* @3962996 constant */
    /* @3963000 add */
    /* @3963004 call */
    GM_SITE(vm, 142, 3963004);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3963012 store */
    v57 = GM_CALL(vm, "instance_create", 3, v56, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v57);
    /* @3963020 load */
    /* @3963028 cast */
    /* @3963032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3963064;
    L_3963036: ;
    /* @3963036 constant */
    /* @3963040 cast */
    /* @3963044 load */
    /* @3963052 call */
    GM_SITE(vm, 142, 3963052);
    /* @3963060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3963064: ;
    /* @3963064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963036;
    /* @3963068 constant */
    /* @3963072 cast */
    /* @3963076 load */
    /* @3963084 constant */
    /* @3963088 sub */
    /* @3963092 load */
    /* @3963100 constant */
    /* @3963104 sub */
    /* @3963108 call */
    GM_SITE(vm, 142, 3963108);
    /* @3963116 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v58);
    /* @3963124 load */
    /* @3963132 cast */
    /* @3963136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3963168;
    L_3963140: ;
    /* @3963140 constant */
    /* @3963144 cast */
    /* @3963148 load */
    /* @3963156 call */
    GM_SITE(vm, 142, 3963156);
    /* @3963164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3963168: ;
    /* @3963168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963140;
    /* @3963172 constant */
    /* @3963176 cast */
    /* @3963180 load */
    /* @3963188 constant */
    /* @3963192 sub */
    /* @3963196 load */
    /* @3963204 constant */
    /* @3963208 add */
    /* @3963212 call */
    GM_SITE(vm, 142, 3963212);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3963220 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v60);
    /* @3963228 load */
    /* @3963236 cast */
    /* @3963240 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3963272;
    L_3963244: ;
    /* @3963244 constant */
    /* @3963248 cast */
    /* @3963252 load */
    /* @3963260 call */
    GM_SITE(vm, 142, 3963260);
    /* @3963268 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3963272: ;
    /* @3963272 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963244;
    /* @3963276 constant */
    /* @3963280 cast */
    /* @3963284 load */
    /* @3963292 constant */
    /* @3963296 sub */
    /* @3963300 load */
    /* @3963308 constant */
    /* @3963312 add */
    /* @3963316 call */
    GM_SITE(vm, 142, 3963316);
    v61 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3963324 store */
    v62 = GM_CALL(vm, "instance_create", 3, v61, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v62);
    /* @3963332 load */
    /* @3963340 cast */
    /* @3963344 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3963376;
    L_3963348: ;
    /* @3963348 constant */
    /* @3963352 cast */
    /* @3963356 load */
    /* @3963364 call */
    GM_SITE(vm, 142, 3963364);
    /* @3963372 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3963376: ;
    /* @3963376 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963348;
    /* @3963380 constant */
    /* @3963384 cast */
    /* @3963388 load */
    /* @3963396 constant */
    /* @3963400 sub */
    /* @3963404 load */
    /* @3963412 constant */
    /* @3963416 sub */
    /* @3963420 call */
    GM_SITE(vm, 142, 3963420);
    /* @3963428 store */
    v63 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v63);
    /* @3963436 load */
    /* @3963444 cast */
    /* @3963448 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3963480;
    L_3963452: ;
    /* @3963452 constant */
    /* @3963456 cast */
    /* @3963460 load */
    /* @3963468 call */
    GM_SITE(vm, 142, 3963468);
    /* @3963476 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3963480: ;
    /* @3963480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963452;
    /* @3963484 constant */
    /* @3963488 cast */
    /* @3963492 load */
    /* @3963500 constant */
    /* @3963504 sub */
    /* @3963508 load */
    /* @3963516 constant */
    /* @3963520 add */
    /* @3963524 call */
    GM_SITE(vm, 142, 3963524);
    v64 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3963532 store */
    v65 = GM_CALL(vm, "instance_create", 3, v64, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v65);
    /* @3963540 load */
    /* @3963548 cast */
    /* @3963552 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3963584;
    L_3963556: ;
    /* @3963556 constant */
    /* @3963560 cast */
    /* @3963564 load */
    /* @3963572 call */
    GM_SITE(vm, 142, 3963572);
    /* @3963580 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3963584: ;
    /* @3963584 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963556;
    /* @3963588 constant */
    /* @3963592 cast */
    /* @3963596 load */
    /* @3963604 constant */
    /* @3963608 sub */
    /* @3963612 load */
    /* @3963620 constant */
    /* @3963624 sub */
    /* @3963628 call */
    GM_SITE(vm, 142, 3963628);
    /* @3963636 store */
    v66 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v66);
    /* @3963644 load */
    /* @3963652 cast */
    /* @3963656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3963688;
    L_3963660: ;
    /* @3963660 constant */
    /* @3963664 cast */
    /* @3963668 load */
    /* @3963676 call */
    GM_SITE(vm, 142, 3963676);
    /* @3963684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3963688: ;
    /* @3963688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3963660;
    L_3963692: ;
    /* @3963692 call */
    GM_SITE(vm, 142, 3963692);
    /* @3963700 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3963704: ;
    return;
}
