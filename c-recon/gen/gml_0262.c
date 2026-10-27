/* generated from CODE 262 (gml_Object_obj_fireslime_Alarm_2), source start 4049176, end 4054480. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0262(GmVM* vm) {
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
    /* @4049176 load */
    /* @4049184 constant */
    /* @4049188 cmp */
    /* @4049192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4049200;
    /* @4049196 b */
    goto L_4049256;
    L_4049200: ;
    /* @4049200 load */
    /* @4049208 constant */
    /* @4049212 cmp */
    /* @4049216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4049256;
    /* @4049220 constant */
    /* @4049224 cast */
    /* @4049228 constant */
    /* @4049232 cast */
    /* @4049236 constant */
    /* @4049240 cast */
    /* @4049244 call */
    GM_SITE(vm, 262, 4049244);
    /* @4049252 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_4049256: ;
    /* @4049256 load */
    /* @4049264 constant */
    /* @4049268 cmp */
    /* @4049272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4049320;
    /* @4049276 constant */
    /* @4049280 cast */
    /* @4049284 load */
    /* @4049292 constant */
    /* @4049296 sub */
    /* @4049300 load */
    /* @4049308 call */
    GM_SITE(vm, 262, 4049308);
    /* @4049316 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_4049320: ;
    /* @4049320 load */
    /* @4049328 constant */
    /* @4049332 cmp */
    /* @4049336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_4049384;
    /* @4049340 constant */
    /* @4049344 cast */
    /* @4049348 load */
    /* @4049356 constant */
    /* @4049360 sub */
    /* @4049364 load */
    /* @4049372 call */
    GM_SITE(vm, 262, 4049372);
    /* @4049380 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_4049384: ;
    /* @4049384 load */
    /* @4049392 constant */
    /* @4049396 cmp */
    /* @4049400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_4049448;
    /* @4049404 constant */
    /* @4049408 cast */
    /* @4049412 load */
    /* @4049420 constant */
    /* @4049424 sub */
    /* @4049428 load */
    /* @4049436 call */
    GM_SITE(vm, 262, 4049436);
    /* @4049444 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), VAL(62)));
    L_4049448: ;
    /* @4049448 load */
    /* @4049456 constant */
    /* @4049460 cmp */
    /* @4049464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_4049564;
    /* @4049468 constant */
    /* @4049472 cast */
    /* @4049476 load */
    /* @4049484 constant */
    /* @4049488 sub */
    /* @4049492 load */
    /* @4049500 call */
    GM_SITE(vm, 262, 4049500);
    /* @4049508 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @4049516 load */
    /* @4049524 cast */
    /* @4049528 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4049560;
    L_4049532: ;
    /* @4049532 constant */
    /* @4049536 cast */
    /* @4049540 load */
    /* @4049548 call */
    GM_SITE(vm, 262, 4049548);
    /* @4049556 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_4049560: ;
    /* @4049560 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4049532;
    L_4049564: ;
    /* @4049564 constant */
    /* @4049568 cast */
    /* @4049572 call */
    GM_SITE(vm, 262, 4049572);
    /* @4049580 constant */
    /* @4049584 cmp */
    /* @4049588 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_4049596;
    /* @4049592 b */
    goto L_4054468;
    L_4049596: ;
    /* @4049596 constant */
    /* @4049600 cast */
    /* @4049604 call */
    GM_SITE(vm, 262, 4049604);
    /* @4049612 constant */
    /* @4049616 cmp */
    /* @4049620 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_4054468;
    /* @4049624 load */
    /* @4049632 constant */
    /* @4049636 cmp */
    /* @4049640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_4050156;
    /* @4049644 constant */
    /* @4049648 cast */
    /* @4049652 load */
    /* @4049660 constant */
    /* @4049664 sub */
    /* @4049668 load */
    /* @4049676 call */
    GM_SITE(vm, 262, 4049676);
    /* @4049684 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @4049692 load */
    /* @4049700 cast */
    /* @4049704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4049736;
    L_4049708: ;
    /* @4049708 constant */
    /* @4049712 cast */
    /* @4049716 load */
    /* @4049724 call */
    GM_SITE(vm, 262, 4049724);
    /* @4049732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4049736: ;
    /* @4049736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4049708;
    /* @4049740 constant */
    /* @4049744 cast */
    /* @4049748 load */
    /* @4049756 constant */
    /* @4049760 sub */
    /* @4049764 load */
    /* @4049772 constant */
    /* @4049776 add */
    /* @4049780 call */
    GM_SITE(vm, 262, 4049780);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4049788 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @4049796 load */
    /* @4049804 cast */
    /* @4049808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4049840;
    L_4049812: ;
    /* @4049812 constant */
    /* @4049816 cast */
    /* @4049820 load */
    /* @4049828 call */
    GM_SITE(vm, 262, 4049828);
    /* @4049836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4049840: ;
    /* @4049840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4049812;
    /* @4049844 constant */
    /* @4049848 cast */
    /* @4049852 load */
    /* @4049860 constant */
    /* @4049864 sub */
    /* @4049868 load */
    /* @4049876 constant */
    /* @4049880 sub */
    /* @4049884 call */
    GM_SITE(vm, 262, 4049884);
    /* @4049892 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @4049900 load */
    /* @4049908 cast */
    /* @4049912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4049944;
    L_4049916: ;
    /* @4049916 constant */
    /* @4049920 cast */
    /* @4049924 load */
    /* @4049932 call */
    GM_SITE(vm, 262, 4049932);
    /* @4049940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4049944: ;
    /* @4049944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4049916;
    /* @4049948 constant */
    /* @4049952 cast */
    /* @4049956 load */
    /* @4049964 constant */
    /* @4049968 sub */
    /* @4049972 load */
    /* @4049980 constant */
    /* @4049984 add */
    /* @4049988 call */
    GM_SITE(vm, 262, 4049988);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4049996 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @4050004 load */
    /* @4050012 cast */
    /* @4050016 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4050048;
    L_4050020: ;
    /* @4050020 constant */
    /* @4050024 cast */
    /* @4050028 load */
    /* @4050036 call */
    GM_SITE(vm, 262, 4050036);
    /* @4050044 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4050048: ;
    /* @4050048 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050020;
    /* @4050052 constant */
    /* @4050056 cast */
    /* @4050060 load */
    /* @4050068 constant */
    /* @4050072 sub */
    /* @4050076 load */
    /* @4050084 constant */
    /* @4050088 sub */
    /* @4050092 call */
    GM_SITE(vm, 262, 4050092);
    /* @4050100 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @4050108 load */
    /* @4050116 cast */
    /* @4050120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4050152;
    L_4050124: ;
    /* @4050124 constant */
    /* @4050128 cast */
    /* @4050132 load */
    /* @4050140 call */
    GM_SITE(vm, 262, 4050140);
    /* @4050148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4050152: ;
    /* @4050152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050124;
    L_4050156: ;
    /* @4050156 load */
    /* @4050164 constant */
    /* @4050168 cmp */
    /* @4050172 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_4051000;
    /* @4050176 constant */
    /* @4050180 cast */
    /* @4050184 load */
    /* @4050192 constant */
    /* @4050196 sub */
    /* @4050200 load */
    /* @4050208 call */
    GM_SITE(vm, 262, 4050208);
    /* @4050216 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @4050224 load */
    /* @4050232 cast */
    /* @4050236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4050268;
    L_4050240: ;
    /* @4050240 constant */
    /* @4050244 cast */
    /* @4050248 load */
    /* @4050256 call */
    GM_SITE(vm, 262, 4050256);
    /* @4050264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4050268: ;
    /* @4050268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050240;
    /* @4050272 constant */
    /* @4050276 cast */
    /* @4050280 load */
    /* @4050288 constant */
    /* @4050292 sub */
    /* @4050296 load */
    /* @4050304 constant */
    /* @4050308 add */
    /* @4050312 call */
    GM_SITE(vm, 262, 4050312);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4050320 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @4050328 load */
    /* @4050336 cast */
    /* @4050340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4050372;
    L_4050344: ;
    /* @4050344 constant */
    /* @4050348 cast */
    /* @4050352 load */
    /* @4050360 call */
    GM_SITE(vm, 262, 4050360);
    /* @4050368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4050372: ;
    /* @4050372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050344;
    /* @4050376 constant */
    /* @4050380 cast */
    /* @4050384 load */
    /* @4050392 constant */
    /* @4050396 sub */
    /* @4050400 load */
    /* @4050408 constant */
    /* @4050412 sub */
    /* @4050416 call */
    GM_SITE(vm, 262, 4050416);
    /* @4050424 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @4050432 load */
    /* @4050440 cast */
    /* @4050444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4050476;
    L_4050448: ;
    /* @4050448 constant */
    /* @4050452 cast */
    /* @4050456 load */
    /* @4050464 call */
    GM_SITE(vm, 262, 4050464);
    /* @4050472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4050476: ;
    /* @4050476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050448;
    /* @4050480 constant */
    /* @4050484 cast */
    /* @4050488 load */
    /* @4050496 constant */
    /* @4050500 sub */
    /* @4050504 load */
    /* @4050512 constant */
    /* @4050516 add */
    /* @4050520 call */
    GM_SITE(vm, 262, 4050520);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4050528 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @4050536 load */
    /* @4050544 cast */
    /* @4050548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4050580;
    L_4050552: ;
    /* @4050552 constant */
    /* @4050556 cast */
    /* @4050560 load */
    /* @4050568 call */
    GM_SITE(vm, 262, 4050568);
    /* @4050576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4050580: ;
    /* @4050580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050552;
    /* @4050584 constant */
    /* @4050588 cast */
    /* @4050592 load */
    /* @4050600 constant */
    /* @4050604 sub */
    /* @4050608 load */
    /* @4050616 constant */
    /* @4050620 sub */
    /* @4050624 call */
    GM_SITE(vm, 262, 4050624);
    /* @4050632 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @4050640 load */
    /* @4050648 cast */
    /* @4050652 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4050684;
    L_4050656: ;
    /* @4050656 constant */
    /* @4050660 cast */
    /* @4050664 load */
    /* @4050672 call */
    GM_SITE(vm, 262, 4050672);
    /* @4050680 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4050684: ;
    /* @4050684 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050656;
    /* @4050688 constant */
    /* @4050692 cast */
    /* @4050696 load */
    /* @4050704 constant */
    /* @4050708 sub */
    /* @4050712 load */
    /* @4050720 constant */
    /* @4050724 sub */
    /* @4050728 call */
    GM_SITE(vm, 262, 4050728);
    /* @4050736 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @4050744 load */
    /* @4050752 cast */
    /* @4050756 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4050788;
    L_4050760: ;
    /* @4050760 constant */
    /* @4050764 cast */
    /* @4050768 load */
    /* @4050776 call */
    GM_SITE(vm, 262, 4050776);
    /* @4050784 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4050788: ;
    /* @4050788 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050760;
    /* @4050792 constant */
    /* @4050796 cast */
    /* @4050800 load */
    /* @4050808 constant */
    /* @4050812 sub */
    /* @4050816 load */
    /* @4050824 constant */
    /* @4050828 add */
    /* @4050832 call */
    GM_SITE(vm, 262, 4050832);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4050840 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @4050848 load */
    /* @4050856 cast */
    /* @4050860 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4050892;
    L_4050864: ;
    /* @4050864 constant */
    /* @4050868 cast */
    /* @4050872 load */
    /* @4050880 call */
    GM_SITE(vm, 262, 4050880);
    /* @4050888 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4050892: ;
    /* @4050892 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050864;
    /* @4050896 constant */
    /* @4050900 cast */
    /* @4050904 load */
    /* @4050912 constant */
    /* @4050916 sub */
    /* @4050920 load */
    /* @4050928 constant */
    /* @4050932 sub */
    /* @4050936 call */
    GM_SITE(vm, 262, 4050936);
    /* @4050944 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v21);
    /* @4050952 load */
    /* @4050960 cast */
    /* @4050964 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4050996;
    L_4050968: ;
    /* @4050968 constant */
    /* @4050972 cast */
    /* @4050976 load */
    /* @4050984 call */
    GM_SITE(vm, 262, 4050984);
    /* @4050992 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4050996: ;
    /* @4050996 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4050968;
    L_4051000: ;
    /* @4051000 load */
    /* @4051008 constant */
    /* @4051012 cmp */
    /* @4051016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4051844;
    /* @4051020 constant */
    /* @4051024 cast */
    /* @4051028 load */
    /* @4051036 constant */
    /* @4051040 sub */
    /* @4051044 load */
    /* @4051052 call */
    GM_SITE(vm, 262, 4051052);
    /* @4051060 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @4051068 load */
    /* @4051076 cast */
    /* @4051080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4051112;
    L_4051084: ;
    /* @4051084 constant */
    /* @4051088 cast */
    /* @4051092 load */
    /* @4051100 call */
    GM_SITE(vm, 262, 4051100);
    /* @4051108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4051112: ;
    /* @4051112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051084;
    /* @4051116 constant */
    /* @4051120 cast */
    /* @4051124 load */
    /* @4051132 constant */
    /* @4051136 sub */
    /* @4051140 load */
    /* @4051148 constant */
    /* @4051152 add */
    /* @4051156 call */
    GM_SITE(vm, 262, 4051156);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4051164 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @4051172 load */
    /* @4051180 cast */
    /* @4051184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4051216;
    L_4051188: ;
    /* @4051188 constant */
    /* @4051192 cast */
    /* @4051196 load */
    /* @4051204 call */
    GM_SITE(vm, 262, 4051204);
    /* @4051212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4051216: ;
    /* @4051216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051188;
    /* @4051220 constant */
    /* @4051224 cast */
    /* @4051228 load */
    /* @4051236 constant */
    /* @4051240 sub */
    /* @4051244 load */
    /* @4051252 constant */
    /* @4051256 sub */
    /* @4051260 call */
    GM_SITE(vm, 262, 4051260);
    /* @4051268 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @4051276 load */
    /* @4051284 cast */
    /* @4051288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4051320;
    L_4051292: ;
    /* @4051292 constant */
    /* @4051296 cast */
    /* @4051300 load */
    /* @4051308 call */
    GM_SITE(vm, 262, 4051308);
    /* @4051316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4051320: ;
    /* @4051320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051292;
    /* @4051324 constant */
    /* @4051328 cast */
    /* @4051332 load */
    /* @4051340 constant */
    /* @4051344 sub */
    /* @4051348 load */
    /* @4051356 constant */
    /* @4051360 add */
    /* @4051364 call */
    GM_SITE(vm, 262, 4051364);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4051372 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @4051380 load */
    /* @4051388 cast */
    /* @4051392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4051424;
    L_4051396: ;
    /* @4051396 constant */
    /* @4051400 cast */
    /* @4051404 load */
    /* @4051412 call */
    GM_SITE(vm, 262, 4051412);
    /* @4051420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4051424: ;
    /* @4051424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051396;
    /* @4051428 constant */
    /* @4051432 cast */
    /* @4051436 load */
    /* @4051444 constant */
    /* @4051448 sub */
    /* @4051452 load */
    /* @4051460 constant */
    /* @4051464 sub */
    /* @4051468 call */
    GM_SITE(vm, 262, 4051468);
    /* @4051476 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @4051484 load */
    /* @4051492 cast */
    /* @4051496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4051528;
    L_4051500: ;
    /* @4051500 constant */
    /* @4051504 cast */
    /* @4051508 load */
    /* @4051516 call */
    GM_SITE(vm, 262, 4051516);
    /* @4051524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4051528: ;
    /* @4051528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051500;
    /* @4051532 constant */
    /* @4051536 cast */
    /* @4051540 load */
    /* @4051548 constant */
    /* @4051552 sub */
    /* @4051556 load */
    /* @4051564 constant */
    /* @4051568 sub */
    /* @4051572 call */
    GM_SITE(vm, 262, 4051572);
    /* @4051580 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @4051588 load */
    /* @4051596 cast */
    /* @4051600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4051632;
    L_4051604: ;
    /* @4051604 constant */
    /* @4051608 cast */
    /* @4051612 load */
    /* @4051620 call */
    GM_SITE(vm, 262, 4051620);
    /* @4051628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4051632: ;
    /* @4051632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051604;
    /* @4051636 constant */
    /* @4051640 cast */
    /* @4051644 load */
    /* @4051652 constant */
    /* @4051656 sub */
    /* @4051660 load */
    /* @4051668 constant */
    /* @4051672 add */
    /* @4051676 call */
    GM_SITE(vm, 262, 4051676);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4051684 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @4051692 load */
    /* @4051700 cast */
    /* @4051704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4051736;
    L_4051708: ;
    /* @4051708 constant */
    /* @4051712 cast */
    /* @4051716 load */
    /* @4051724 call */
    GM_SITE(vm, 262, 4051724);
    /* @4051732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4051736: ;
    /* @4051736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051708;
    /* @4051740 constant */
    /* @4051744 cast */
    /* @4051748 load */
    /* @4051756 constant */
    /* @4051760 sub */
    /* @4051764 load */
    /* @4051772 constant */
    /* @4051776 sub */
    /* @4051780 call */
    GM_SITE(vm, 262, 4051780);
    /* @4051788 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @4051796 load */
    /* @4051804 cast */
    /* @4051808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4051840;
    L_4051812: ;
    /* @4051812 constant */
    /* @4051816 cast */
    /* @4051820 load */
    /* @4051828 call */
    GM_SITE(vm, 262, 4051828);
    /* @4051836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4051840: ;
    /* @4051840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051812;
    L_4051844: ;
    /* @4051844 load */
    /* @4051852 constant */
    /* @4051856 cmp */
    /* @4051860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4053208;
    /* @4051864 constant */
    /* @4051868 cast */
    /* @4051872 load */
    /* @4051880 constant */
    /* @4051884 sub */
    /* @4051888 load */
    /* @4051896 call */
    GM_SITE(vm, 262, 4051896);
    /* @4051904 store */
    v33 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v33);
    /* @4051912 load */
    /* @4051920 cast */
    /* @4051924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4051956;
    L_4051928: ;
    /* @4051928 constant */
    /* @4051932 cast */
    /* @4051936 load */
    /* @4051944 call */
    GM_SITE(vm, 262, 4051944);
    /* @4051952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4051956: ;
    /* @4051956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4051928;
    /* @4051960 constant */
    /* @4051964 cast */
    /* @4051968 load */
    /* @4051976 constant */
    /* @4051980 sub */
    /* @4051984 load */
    /* @4051992 constant */
    /* @4051996 add */
    /* @4052000 call */
    GM_SITE(vm, 262, 4052000);
    v34 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4052008 store */
    v35 = GM_CALL(vm, "instance_create", 3, v34, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v35);
    /* @4052016 load */
    /* @4052024 cast */
    /* @4052028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4052060;
    L_4052032: ;
    /* @4052032 constant */
    /* @4052036 cast */
    /* @4052040 load */
    /* @4052048 call */
    GM_SITE(vm, 262, 4052048);
    /* @4052056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4052060: ;
    /* @4052060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052032;
    /* @4052064 constant */
    /* @4052068 cast */
    /* @4052072 load */
    /* @4052080 constant */
    /* @4052084 sub */
    /* @4052088 load */
    /* @4052096 constant */
    /* @4052100 sub */
    /* @4052104 call */
    GM_SITE(vm, 262, 4052104);
    /* @4052112 store */
    v36 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v36);
    /* @4052120 load */
    /* @4052128 cast */
    /* @4052132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4052164;
    L_4052136: ;
    /* @4052136 constant */
    /* @4052140 cast */
    /* @4052144 load */
    /* @4052152 call */
    GM_SITE(vm, 262, 4052152);
    /* @4052160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4052164: ;
    /* @4052164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052136;
    /* @4052168 constant */
    /* @4052172 cast */
    /* @4052176 load */
    /* @4052184 constant */
    /* @4052188 sub */
    /* @4052192 load */
    /* @4052200 constant */
    /* @4052204 add */
    /* @4052208 call */
    GM_SITE(vm, 262, 4052208);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4052216 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v38);
    /* @4052224 load */
    /* @4052232 cast */
    /* @4052236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4052268;
    L_4052240: ;
    /* @4052240 constant */
    /* @4052244 cast */
    /* @4052248 load */
    /* @4052256 call */
    GM_SITE(vm, 262, 4052256);
    /* @4052264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4052268: ;
    /* @4052268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052240;
    /* @4052272 constant */
    /* @4052276 cast */
    /* @4052280 load */
    /* @4052288 constant */
    /* @4052292 sub */
    /* @4052296 load */
    /* @4052304 constant */
    /* @4052308 sub */
    /* @4052312 call */
    GM_SITE(vm, 262, 4052312);
    /* @4052320 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v39);
    /* @4052328 load */
    /* @4052336 cast */
    /* @4052340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4052372;
    L_4052344: ;
    /* @4052344 constant */
    /* @4052348 cast */
    /* @4052352 load */
    /* @4052360 call */
    GM_SITE(vm, 262, 4052360);
    /* @4052368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4052372: ;
    /* @4052372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052344;
    /* @4052376 constant */
    /* @4052380 cast */
    /* @4052384 load */
    /* @4052392 constant */
    /* @4052396 sub */
    /* @4052400 load */
    /* @4052408 constant */
    /* @4052412 add */
    /* @4052416 call */
    GM_SITE(vm, 262, 4052416);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4052424 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v41);
    /* @4052432 load */
    /* @4052440 cast */
    /* @4052444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4052476;
    L_4052448: ;
    /* @4052448 constant */
    /* @4052452 cast */
    /* @4052456 load */
    /* @4052464 call */
    GM_SITE(vm, 262, 4052464);
    /* @4052472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4052476: ;
    /* @4052476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052448;
    /* @4052480 constant */
    /* @4052484 cast */
    /* @4052488 load */
    /* @4052496 constant */
    /* @4052500 sub */
    /* @4052504 load */
    /* @4052512 constant */
    /* @4052516 add */
    /* @4052520 call */
    GM_SITE(vm, 262, 4052520);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4052528 store */
    v43 = GM_CALL(vm, "instance_create", 3, v42, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v43);
    /* @4052536 load */
    /* @4052544 cast */
    /* @4052548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4052580;
    L_4052552: ;
    /* @4052552 constant */
    /* @4052556 cast */
    /* @4052560 load */
    /* @4052568 call */
    GM_SITE(vm, 262, 4052568);
    /* @4052576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4052580: ;
    /* @4052580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052552;
    /* @4052584 constant */
    /* @4052588 cast */
    /* @4052592 load */
    /* @4052600 constant */
    /* @4052604 sub */
    /* @4052608 load */
    /* @4052616 constant */
    /* @4052620 sub */
    /* @4052624 call */
    GM_SITE(vm, 262, 4052624);
    /* @4052632 store */
    v44 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v44);
    /* @4052640 load */
    /* @4052648 cast */
    /* @4052652 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4052684;
    L_4052656: ;
    /* @4052656 constant */
    /* @4052660 cast */
    /* @4052664 load */
    /* @4052672 call */
    GM_SITE(vm, 262, 4052672);
    /* @4052680 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4052684: ;
    /* @4052684 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052656;
    /* @4052688 constant */
    /* @4052692 cast */
    /* @4052696 load */
    /* @4052704 constant */
    /* @4052708 sub */
    /* @4052712 load */
    /* @4052720 constant */
    /* @4052724 add */
    /* @4052728 call */
    GM_SITE(vm, 262, 4052728);
    v45 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4052736 store */
    v46 = GM_CALL(vm, "instance_create", 3, v45, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v46);
    /* @4052744 load */
    /* @4052752 cast */
    /* @4052756 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4052788;
    L_4052760: ;
    /* @4052760 constant */
    /* @4052764 cast */
    /* @4052768 load */
    /* @4052776 call */
    GM_SITE(vm, 262, 4052776);
    /* @4052784 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4052788: ;
    /* @4052788 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052760;
    /* @4052792 constant */
    /* @4052796 cast */
    /* @4052800 load */
    /* @4052808 constant */
    /* @4052812 sub */
    /* @4052816 load */
    /* @4052824 constant */
    /* @4052828 sub */
    /* @4052832 call */
    GM_SITE(vm, 262, 4052832);
    /* @4052840 store */
    v47 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v47);
    /* @4052848 load */
    /* @4052856 cast */
    /* @4052860 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4052892;
    L_4052864: ;
    /* @4052864 constant */
    /* @4052868 cast */
    /* @4052872 load */
    /* @4052880 call */
    GM_SITE(vm, 262, 4052880);
    /* @4052888 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4052892: ;
    /* @4052892 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052864;
    /* @4052896 constant */
    /* @4052900 cast */
    /* @4052904 load */
    /* @4052912 constant */
    /* @4052916 sub */
    /* @4052920 load */
    /* @4052928 constant */
    /* @4052932 sub */
    /* @4052936 call */
    GM_SITE(vm, 262, 4052936);
    /* @4052944 store */
    v48 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v48);
    /* @4052952 load */
    /* @4052960 cast */
    /* @4052964 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4052996;
    L_4052968: ;
    /* @4052968 constant */
    /* @4052972 cast */
    /* @4052976 load */
    /* @4052984 call */
    GM_SITE(vm, 262, 4052984);
    /* @4052992 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4052996: ;
    /* @4052996 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4052968;
    /* @4053000 constant */
    /* @4053004 cast */
    /* @4053008 load */
    /* @4053016 constant */
    /* @4053020 sub */
    /* @4053024 load */
    /* @4053032 constant */
    /* @4053036 add */
    /* @4053040 call */
    GM_SITE(vm, 262, 4053040);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4053048 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v50);
    /* @4053056 load */
    /* @4053064 cast */
    /* @4053068 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4053100;
    L_4053072: ;
    /* @4053072 constant */
    /* @4053076 cast */
    /* @4053080 load */
    /* @4053088 call */
    GM_SITE(vm, 262, 4053088);
    /* @4053096 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4053100: ;
    /* @4053100 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053072;
    /* @4053104 constant */
    /* @4053108 cast */
    /* @4053112 load */
    /* @4053120 constant */
    /* @4053124 sub */
    /* @4053128 load */
    /* @4053136 constant */
    /* @4053140 sub */
    /* @4053144 call */
    GM_SITE(vm, 262, 4053144);
    /* @4053152 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v51);
    /* @4053160 load */
    /* @4053168 cast */
    /* @4053172 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4053204;
    L_4053176: ;
    /* @4053176 constant */
    /* @4053180 cast */
    /* @4053184 load */
    /* @4053192 call */
    GM_SITE(vm, 262, 4053192);
    /* @4053200 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4053204: ;
    /* @4053204 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053176;
    L_4053208: ;
    /* @4053208 load */
    /* @4053216 constant */
    /* @4053220 cmp */
    /* @4053224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4054468;
    /* @4053228 constant */
    /* @4053232 cast */
    /* @4053236 load */
    /* @4053244 constant */
    /* @4053248 sub */
    /* @4053252 load */
    /* @4053260 call */
    GM_SITE(vm, 262, 4053260);
    /* @4053268 store */
    v52 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v52);
    /* @4053276 load */
    /* @4053284 cast */
    /* @4053288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4053320;
    L_4053292: ;
    /* @4053292 constant */
    /* @4053296 cast */
    /* @4053300 load */
    /* @4053308 call */
    GM_SITE(vm, 262, 4053308);
    /* @4053316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4053320: ;
    /* @4053320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053292;
    /* @4053324 constant */
    /* @4053328 cast */
    /* @4053332 load */
    /* @4053340 constant */
    /* @4053344 sub */
    /* @4053348 load */
    /* @4053356 constant */
    /* @4053360 add */
    /* @4053364 call */
    GM_SITE(vm, 262, 4053364);
    v53 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4053372 store */
    v54 = GM_CALL(vm, "instance_create", 3, v53, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v54);
    /* @4053380 load */
    /* @4053388 cast */
    /* @4053392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4053424;
    L_4053396: ;
    /* @4053396 constant */
    /* @4053400 cast */
    /* @4053404 load */
    /* @4053412 call */
    GM_SITE(vm, 262, 4053412);
    /* @4053420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4053424: ;
    /* @4053424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053396;
    /* @4053428 constant */
    /* @4053432 cast */
    /* @4053436 load */
    /* @4053444 constant */
    /* @4053448 sub */
    /* @4053452 load */
    /* @4053460 constant */
    /* @4053464 sub */
    /* @4053468 call */
    GM_SITE(vm, 262, 4053468);
    /* @4053476 store */
    v55 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v55);
    /* @4053484 load */
    /* @4053492 cast */
    /* @4053496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4053528;
    L_4053500: ;
    /* @4053500 constant */
    /* @4053504 cast */
    /* @4053508 load */
    /* @4053516 call */
    GM_SITE(vm, 262, 4053516);
    /* @4053524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4053528: ;
    /* @4053528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053500;
    /* @4053532 constant */
    /* @4053536 cast */
    /* @4053540 load */
    /* @4053548 constant */
    /* @4053552 sub */
    /* @4053556 load */
    /* @4053564 constant */
    /* @4053568 add */
    /* @4053572 call */
    GM_SITE(vm, 262, 4053572);
    v56 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4053580 store */
    v57 = GM_CALL(vm, "instance_create", 3, v56, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v57);
    /* @4053588 load */
    /* @4053596 cast */
    /* @4053600 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4053632;
    L_4053604: ;
    /* @4053604 constant */
    /* @4053608 cast */
    /* @4053612 load */
    /* @4053620 call */
    GM_SITE(vm, 262, 4053620);
    /* @4053628 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4053632: ;
    /* @4053632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053604;
    /* @4053636 constant */
    /* @4053640 cast */
    /* @4053644 load */
    /* @4053652 constant */
    /* @4053656 sub */
    /* @4053660 load */
    /* @4053668 constant */
    /* @4053672 sub */
    /* @4053676 call */
    GM_SITE(vm, 262, 4053676);
    /* @4053684 store */
    v58 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v58);
    /* @4053692 load */
    /* @4053700 cast */
    /* @4053704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4053736;
    L_4053708: ;
    /* @4053708 constant */
    /* @4053712 cast */
    /* @4053716 load */
    /* @4053724 call */
    GM_SITE(vm, 262, 4053724);
    /* @4053732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4053736: ;
    /* @4053736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053708;
    /* @4053740 constant */
    /* @4053744 cast */
    /* @4053748 load */
    /* @4053756 constant */
    /* @4053760 sub */
    /* @4053764 load */
    /* @4053772 constant */
    /* @4053776 add */
    /* @4053780 call */
    GM_SITE(vm, 262, 4053780);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4053788 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v60);
    /* @4053796 load */
    /* @4053804 cast */
    /* @4053808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4053840;
    L_4053812: ;
    /* @4053812 constant */
    /* @4053816 cast */
    /* @4053820 load */
    /* @4053828 call */
    GM_SITE(vm, 262, 4053828);
    /* @4053836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4053840: ;
    /* @4053840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053812;
    /* @4053844 constant */
    /* @4053848 cast */
    /* @4053852 load */
    /* @4053860 constant */
    /* @4053864 sub */
    /* @4053868 load */
    /* @4053876 constant */
    /* @4053880 add */
    /* @4053884 call */
    GM_SITE(vm, 262, 4053884);
    v61 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4053892 store */
    v62 = GM_CALL(vm, "instance_create", 3, v61, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v62);
    /* @4053900 load */
    /* @4053908 cast */
    /* @4053912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4053944;
    L_4053916: ;
    /* @4053916 constant */
    /* @4053920 cast */
    /* @4053924 load */
    /* @4053932 call */
    GM_SITE(vm, 262, 4053932);
    /* @4053940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4053944: ;
    /* @4053944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4053916;
    /* @4053948 constant */
    /* @4053952 cast */
    /* @4053956 load */
    /* @4053964 constant */
    /* @4053968 sub */
    /* @4053972 load */
    /* @4053980 constant */
    /* @4053984 sub */
    /* @4053988 call */
    GM_SITE(vm, 262, 4053988);
    /* @4053996 store */
    v63 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v63);
    /* @4054004 load */
    /* @4054012 cast */
    /* @4054016 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4054048;
    L_4054020: ;
    /* @4054020 constant */
    /* @4054024 cast */
    /* @4054028 load */
    /* @4054036 call */
    GM_SITE(vm, 262, 4054036);
    /* @4054044 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4054048: ;
    /* @4054048 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4054020;
    /* @4054052 constant */
    /* @4054056 cast */
    /* @4054060 load */
    /* @4054068 constant */
    /* @4054072 sub */
    /* @4054076 load */
    /* @4054084 constant */
    /* @4054088 add */
    /* @4054092 call */
    GM_SITE(vm, 262, 4054092);
    v64 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4054100 store */
    v65 = GM_CALL(vm, "instance_create", 3, v64, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v65);
    /* @4054108 load */
    /* @4054116 cast */
    /* @4054120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4054152;
    L_4054124: ;
    /* @4054124 constant */
    /* @4054128 cast */
    /* @4054132 load */
    /* @4054140 call */
    GM_SITE(vm, 262, 4054140);
    /* @4054148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4054152: ;
    /* @4054152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4054124;
    /* @4054156 constant */
    /* @4054160 cast */
    /* @4054164 load */
    /* @4054172 constant */
    /* @4054176 sub */
    /* @4054180 load */
    /* @4054188 constant */
    /* @4054192 sub */
    /* @4054196 call */
    GM_SITE(vm, 262, 4054196);
    /* @4054204 store */
    v66 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v66);
    /* @4054212 load */
    /* @4054220 cast */
    /* @4054224 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4054256;
    L_4054228: ;
    /* @4054228 constant */
    /* @4054232 cast */
    /* @4054236 load */
    /* @4054244 call */
    GM_SITE(vm, 262, 4054244);
    /* @4054252 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4054256: ;
    /* @4054256 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4054228;
    /* @4054260 constant */
    /* @4054264 cast */
    /* @4054268 load */
    /* @4054276 constant */
    /* @4054280 sub */
    /* @4054284 load */
    /* @4054292 constant */
    /* @4054296 sub */
    /* @4054300 call */
    GM_SITE(vm, 262, 4054300);
    /* @4054308 store */
    v67 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v67);
    /* @4054316 load */
    /* @4054324 cast */
    /* @4054328 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4054360;
    L_4054332: ;
    /* @4054332 constant */
    /* @4054336 cast */
    /* @4054340 load */
    /* @4054348 call */
    GM_SITE(vm, 262, 4054348);
    /* @4054356 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4054360: ;
    /* @4054360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4054332;
    /* @4054364 constant */
    /* @4054368 cast */
    /* @4054372 load */
    /* @4054380 constant */
    /* @4054384 sub */
    /* @4054388 load */
    /* @4054396 constant */
    /* @4054400 add */
    /* @4054404 call */
    GM_SITE(vm, 262, 4054404);
    v68 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4054412 store */
    v69 = GM_CALL(vm, "instance_create", 3, v68, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v69);
    /* @4054420 load */
    /* @4054428 cast */
    /* @4054432 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4054464;
    L_4054436: ;
    /* @4054436 constant */
    /* @4054440 cast */
    /* @4054444 load */
    /* @4054452 call */
    GM_SITE(vm, 262, 4054452);
    /* @4054460 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4054464: ;
    /* @4054464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4054436;
    L_4054468: ;
    /* @4054468 call */
    GM_SITE(vm, 262, 4054468);
    /* @4054476 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4054480: ;
    return;
}
