/* generated from CODE 151 (gml_Object_obj_ghost_Alarm_0), source start 3966616, end 3971544. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0151(GmVM* vm) {
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
    /* @3966616 load */
    /* @3966624 constant */
    /* @3966628 cmp */
    /* @3966632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3966640;
    /* @3966636 b */
    goto L_3966696;
    L_3966640: ;
    /* @3966640 load */
    /* @3966648 constant */
    /* @3966652 cmp */
    /* @3966656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3966696;
    /* @3966660 constant */
    /* @3966664 cast */
    /* @3966668 constant */
    /* @3966672 cast */
    /* @3966676 constant */
    /* @3966680 cast */
    /* @3966684 call */
    GM_SITE(vm, 151, 3966684);
    /* @3966692 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(0), VAL(0), VAL(0)));
    L_3966696: ;
    /* @3966696 load */
    /* @3966704 constant */
    /* @3966708 cmp */
    /* @3966712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3966760;
    /* @3966716 constant */
    /* @3966720 cast */
    /* @3966724 load */
    /* @3966732 constant */
    /* @3966736 sub */
    /* @3966740 load */
    /* @3966748 call */
    GM_SITE(vm, 151, 3966748);
    /* @3966756 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3966760: ;
    /* @3966760 constant */
    /* @3966764 cast */
    /* @3966768 call */
    GM_SITE(vm, 151, 3966768);
    /* @3966776 constant */
    /* @3966780 cmp */
    /* @3966784 bf */
    v1 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v1)) goto L_3966792;
    /* @3966788 b */
    goto L_3971532;
    L_3966792: ;
    /* @3966792 constant */
    /* @3966796 cast */
    /* @3966800 call */
    GM_SITE(vm, 151, 3966800);
    /* @3966808 constant */
    /* @3966812 cmp */
    /* @3966816 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v2)) goto L_3971532;
    /* @3966820 load */
    /* @3966828 constant */
    /* @3966832 cmp */
    /* @3966836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3966884;
    /* @3966840 constant */
    /* @3966844 cast */
    /* @3966848 load */
    /* @3966856 constant */
    /* @3966860 sub */
    /* @3966864 load */
    /* @3966872 call */
    GM_SITE(vm, 151, 3966872);
    /* @3966880 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3966884: ;
    /* @3966884 load */
    /* @3966892 constant */
    /* @3966896 cmp */
    /* @3966900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3967000;
    /* @3966904 constant */
    /* @3966908 cast */
    /* @3966912 load */
    /* @3966920 constant */
    /* @3966924 sub */
    /* @3966928 load */
    /* @3966936 call */
    GM_SITE(vm, 151, 3966936);
    /* @3966944 store */
    v3 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v3);
    /* @3966952 load */
    /* @3966960 cast */
    /* @3966964 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3966996;
    L_3966968: ;
    /* @3966968 constant */
    /* @3966972 cast */
    /* @3966976 load */
    /* @3966984 call */
    GM_SITE(vm, 151, 3966984);
    /* @3966992 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3966996: ;
    /* @3966996 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3966968;
    L_3967000: ;
    /* @3967000 load */
    /* @3967008 constant */
    /* @3967012 cmp */
    /* @3967016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3967532;
    /* @3967020 constant */
    /* @3967024 cast */
    /* @3967028 load */
    /* @3967036 constant */
    /* @3967040 sub */
    /* @3967044 load */
    /* @3967052 call */
    GM_SITE(vm, 151, 3967052);
    /* @3967060 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3967068 load */
    /* @3967076 cast */
    /* @3967080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3967112;
    L_3967084: ;
    /* @3967084 constant */
    /* @3967088 cast */
    /* @3967092 load */
    /* @3967100 call */
    GM_SITE(vm, 151, 3967100);
    /* @3967108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3967112: ;
    /* @3967112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967084;
    /* @3967116 constant */
    /* @3967120 cast */
    /* @3967124 load */
    /* @3967132 constant */
    /* @3967136 sub */
    /* @3967140 load */
    /* @3967148 constant */
    /* @3967152 add */
    /* @3967156 call */
    GM_SITE(vm, 151, 3967156);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3967164 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3967172 load */
    /* @3967180 cast */
    /* @3967184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3967216;
    L_3967188: ;
    /* @3967188 constant */
    /* @3967192 cast */
    /* @3967196 load */
    /* @3967204 call */
    GM_SITE(vm, 151, 3967204);
    /* @3967212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3967216: ;
    /* @3967216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967188;
    /* @3967220 constant */
    /* @3967224 cast */
    /* @3967228 load */
    /* @3967236 constant */
    /* @3967240 sub */
    /* @3967244 load */
    /* @3967252 constant */
    /* @3967256 sub */
    /* @3967260 call */
    GM_SITE(vm, 151, 3967260);
    /* @3967268 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3967276 load */
    /* @3967284 cast */
    /* @3967288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3967320;
    L_3967292: ;
    /* @3967292 constant */
    /* @3967296 cast */
    /* @3967300 load */
    /* @3967308 call */
    GM_SITE(vm, 151, 3967308);
    /* @3967316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3967320: ;
    /* @3967320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967292;
    /* @3967324 constant */
    /* @3967328 cast */
    /* @3967332 load */
    /* @3967340 constant */
    /* @3967344 sub */
    /* @3967348 load */
    /* @3967356 constant */
    /* @3967360 add */
    /* @3967364 call */
    GM_SITE(vm, 151, 3967364);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3967372 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3967380 load */
    /* @3967388 cast */
    /* @3967392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3967424;
    L_3967396: ;
    /* @3967396 constant */
    /* @3967400 cast */
    /* @3967404 load */
    /* @3967412 call */
    GM_SITE(vm, 151, 3967412);
    /* @3967420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3967424: ;
    /* @3967424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967396;
    /* @3967428 constant */
    /* @3967432 cast */
    /* @3967436 load */
    /* @3967444 constant */
    /* @3967448 sub */
    /* @3967452 load */
    /* @3967460 constant */
    /* @3967464 sub */
    /* @3967468 call */
    GM_SITE(vm, 151, 3967468);
    /* @3967476 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3967484 load */
    /* @3967492 cast */
    /* @3967496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3967528;
    L_3967500: ;
    /* @3967500 constant */
    /* @3967504 cast */
    /* @3967508 load */
    /* @3967516 call */
    GM_SITE(vm, 151, 3967516);
    /* @3967524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3967528: ;
    /* @3967528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967500;
    L_3967532: ;
    /* @3967532 load */
    /* @3967540 constant */
    /* @3967544 cmp */
    /* @3967548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3968480;
    /* @3967552 constant */
    /* @3967556 cast */
    /* @3967560 load */
    /* @3967568 constant */
    /* @3967572 sub */
    /* @3967576 load */
    /* @3967584 call */
    GM_SITE(vm, 151, 3967584);
    /* @3967592 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3967600 load */
    /* @3967608 cast */
    /* @3967612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3967644;
    L_3967616: ;
    /* @3967616 constant */
    /* @3967620 cast */
    /* @3967624 load */
    /* @3967632 call */
    GM_SITE(vm, 151, 3967632);
    /* @3967640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3967644: ;
    /* @3967644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967616;
    /* @3967648 constant */
    /* @3967652 cast */
    /* @3967656 load */
    /* @3967664 constant */
    /* @3967668 sub */
    /* @3967672 load */
    /* @3967680 constant */
    /* @3967684 add */
    /* @3967688 call */
    GM_SITE(vm, 151, 3967688);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3967696 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3967704 load */
    /* @3967712 cast */
    /* @3967716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3967748;
    L_3967720: ;
    /* @3967720 constant */
    /* @3967724 cast */
    /* @3967728 load */
    /* @3967736 call */
    GM_SITE(vm, 151, 3967736);
    /* @3967744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3967748: ;
    /* @3967748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967720;
    /* @3967752 constant */
    /* @3967756 cast */
    /* @3967760 load */
    /* @3967768 constant */
    /* @3967772 sub */
    /* @3967776 load */
    /* @3967784 constant */
    /* @3967788 sub */
    /* @3967792 call */
    GM_SITE(vm, 151, 3967792);
    /* @3967800 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3967808 load */
    /* @3967816 cast */
    /* @3967820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3967852;
    L_3967824: ;
    /* @3967824 constant */
    /* @3967828 cast */
    /* @3967832 load */
    /* @3967840 call */
    GM_SITE(vm, 151, 3967840);
    /* @3967848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3967852: ;
    /* @3967852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967824;
    /* @3967856 constant */
    /* @3967860 cast */
    /* @3967864 load */
    /* @3967872 constant */
    /* @3967876 sub */
    /* @3967880 load */
    /* @3967888 constant */
    /* @3967892 add */
    /* @3967896 call */
    GM_SITE(vm, 151, 3967896);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3967904 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3967912 load */
    /* @3967920 cast */
    /* @3967924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3967956;
    L_3967928: ;
    /* @3967928 constant */
    /* @3967932 cast */
    /* @3967936 load */
    /* @3967944 call */
    GM_SITE(vm, 151, 3967944);
    /* @3967952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3967956: ;
    /* @3967956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3967928;
    /* @3967960 constant */
    /* @3967964 cast */
    /* @3967968 load */
    /* @3967976 constant */
    /* @3967980 sub */
    /* @3967984 load */
    /* @3967992 constant */
    /* @3967996 sub */
    /* @3968000 call */
    GM_SITE(vm, 151, 3968000);
    /* @3968008 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3968016 load */
    /* @3968024 cast */
    /* @3968028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3968060;
    L_3968032: ;
    /* @3968032 constant */
    /* @3968036 cast */
    /* @3968040 load */
    /* @3968048 call */
    GM_SITE(vm, 151, 3968048);
    /* @3968056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3968060: ;
    /* @3968060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968032;
    /* @3968064 constant */
    /* @3968068 cast */
    /* @3968072 load */
    /* @3968080 constant */
    /* @3968084 sub */
    /* @3968088 load */
    /* @3968096 constant */
    /* @3968100 sub */
    /* @3968104 call */
    GM_SITE(vm, 151, 3968104);
    /* @3968112 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3968120 load */
    /* @3968128 cast */
    /* @3968132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3968164;
    L_3968136: ;
    /* @3968136 constant */
    /* @3968140 cast */
    /* @3968144 load */
    /* @3968152 call */
    GM_SITE(vm, 151, 3968152);
    /* @3968160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3968164: ;
    /* @3968164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968136;
    /* @3968168 constant */
    /* @3968172 cast */
    /* @3968176 load */
    /* @3968184 constant */
    /* @3968188 sub */
    /* @3968192 load */
    /* @3968200 constant */
    /* @3968204 add */
    /* @3968208 call */
    GM_SITE(vm, 151, 3968208);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3968216 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @3968224 load */
    /* @3968232 cast */
    /* @3968236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3968268;
    L_3968240: ;
    /* @3968240 constant */
    /* @3968244 cast */
    /* @3968248 load */
    /* @3968256 call */
    GM_SITE(vm, 151, 3968256);
    /* @3968264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3968268: ;
    /* @3968268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968240;
    /* @3968272 constant */
    /* @3968276 cast */
    /* @3968280 load */
    /* @3968288 constant */
    /* @3968292 sub */
    /* @3968296 load */
    /* @3968304 constant */
    /* @3968308 sub */
    /* @3968312 call */
    GM_SITE(vm, 151, 3968312);
    /* @3968320 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v21);
    /* @3968328 load */
    /* @3968336 cast */
    /* @3968340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3968372;
    L_3968344: ;
    /* @3968344 constant */
    /* @3968348 cast */
    /* @3968352 load */
    /* @3968360 call */
    GM_SITE(vm, 151, 3968360);
    /* @3968368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3968372: ;
    /* @3968372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968344;
    /* @3968376 constant */
    /* @3968380 cast */
    /* @3968384 load */
    /* @3968392 constant */
    /* @3968396 sub */
    /* @3968400 load */
    /* @3968408 constant */
    /* @3968412 add */
    /* @3968416 call */
    GM_SITE(vm, 151, 3968416);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3968424 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v23);
    /* @3968432 load */
    /* @3968440 cast */
    /* @3968444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3968476;
    L_3968448: ;
    /* @3968448 constant */
    /* @3968452 cast */
    /* @3968456 load */
    /* @3968464 call */
    GM_SITE(vm, 151, 3968464);
    /* @3968472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3968476: ;
    /* @3968476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968448;
    L_3968480: ;
    /* @3968480 load */
    /* @3968488 constant */
    /* @3968492 cmp */
    /* @3968496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3969324;
    /* @3968500 constant */
    /* @3968504 cast */
    /* @3968508 load */
    /* @3968516 constant */
    /* @3968520 sub */
    /* @3968524 load */
    /* @3968532 call */
    GM_SITE(vm, 151, 3968532);
    /* @3968540 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v24);
    /* @3968548 load */
    /* @3968556 cast */
    /* @3968560 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3968592;
    L_3968564: ;
    /* @3968564 constant */
    /* @3968568 cast */
    /* @3968572 load */
    /* @3968580 call */
    GM_SITE(vm, 151, 3968580);
    /* @3968588 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3968592: ;
    /* @3968592 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968564;
    /* @3968596 constant */
    /* @3968600 cast */
    /* @3968604 load */
    /* @3968612 constant */
    /* @3968616 sub */
    /* @3968620 load */
    /* @3968628 constant */
    /* @3968632 add */
    /* @3968636 call */
    GM_SITE(vm, 151, 3968636);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3968644 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v26);
    /* @3968652 load */
    /* @3968660 cast */
    /* @3968664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3968696;
    L_3968668: ;
    /* @3968668 constant */
    /* @3968672 cast */
    /* @3968676 load */
    /* @3968684 call */
    GM_SITE(vm, 151, 3968684);
    /* @3968692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3968696: ;
    /* @3968696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968668;
    /* @3968700 constant */
    /* @3968704 cast */
    /* @3968708 load */
    /* @3968716 constant */
    /* @3968720 sub */
    /* @3968724 load */
    /* @3968732 constant */
    /* @3968736 sub */
    /* @3968740 call */
    GM_SITE(vm, 151, 3968740);
    /* @3968748 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v27);
    /* @3968756 load */
    /* @3968764 cast */
    /* @3968768 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3968800;
    L_3968772: ;
    /* @3968772 constant */
    /* @3968776 cast */
    /* @3968780 load */
    /* @3968788 call */
    GM_SITE(vm, 151, 3968788);
    /* @3968796 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3968800: ;
    /* @3968800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968772;
    /* @3968804 constant */
    /* @3968808 cast */
    /* @3968812 load */
    /* @3968820 constant */
    /* @3968824 sub */
    /* @3968828 load */
    /* @3968836 constant */
    /* @3968840 add */
    /* @3968844 call */
    GM_SITE(vm, 151, 3968844);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3968852 store */
    v29 = GM_CALL(vm, "instance_create", 3, v28, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v29);
    /* @3968860 load */
    /* @3968868 cast */
    /* @3968872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3968904;
    L_3968876: ;
    /* @3968876 constant */
    /* @3968880 cast */
    /* @3968884 load */
    /* @3968892 call */
    GM_SITE(vm, 151, 3968892);
    /* @3968900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3968904: ;
    /* @3968904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968876;
    /* @3968908 constant */
    /* @3968912 cast */
    /* @3968916 load */
    /* @3968924 constant */
    /* @3968928 sub */
    /* @3968932 load */
    /* @3968940 constant */
    /* @3968944 sub */
    /* @3968948 call */
    GM_SITE(vm, 151, 3968948);
    /* @3968956 store */
    v30 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v30);
    /* @3968964 load */
    /* @3968972 cast */
    /* @3968976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3969008;
    L_3968980: ;
    /* @3968980 constant */
    /* @3968984 cast */
    /* @3968988 load */
    /* @3968996 call */
    GM_SITE(vm, 151, 3968996);
    /* @3969004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3969008: ;
    /* @3969008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3968980;
    /* @3969012 constant */
    /* @3969016 cast */
    /* @3969020 load */
    /* @3969028 constant */
    /* @3969032 sub */
    /* @3969036 load */
    /* @3969044 constant */
    /* @3969048 sub */
    /* @3969052 call */
    GM_SITE(vm, 151, 3969052);
    /* @3969060 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v31);
    /* @3969068 load */
    /* @3969076 cast */
    /* @3969080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3969112;
    L_3969084: ;
    /* @3969084 constant */
    /* @3969088 cast */
    /* @3969092 load */
    /* @3969100 call */
    GM_SITE(vm, 151, 3969100);
    /* @3969108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3969112: ;
    /* @3969112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969084;
    /* @3969116 constant */
    /* @3969120 cast */
    /* @3969124 load */
    /* @3969132 constant */
    /* @3969136 sub */
    /* @3969140 load */
    /* @3969148 constant */
    /* @3969152 add */
    /* @3969156 call */
    GM_SITE(vm, 151, 3969156);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3969164 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v33);
    /* @3969172 load */
    /* @3969180 cast */
    /* @3969184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3969216;
    L_3969188: ;
    /* @3969188 constant */
    /* @3969192 cast */
    /* @3969196 load */
    /* @3969204 call */
    GM_SITE(vm, 151, 3969204);
    /* @3969212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3969216: ;
    /* @3969216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969188;
    /* @3969220 constant */
    /* @3969224 cast */
    /* @3969228 load */
    /* @3969236 constant */
    /* @3969240 sub */
    /* @3969244 load */
    /* @3969252 constant */
    /* @3969256 sub */
    /* @3969260 call */
    GM_SITE(vm, 151, 3969260);
    /* @3969268 store */
    v34 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v34);
    /* @3969276 load */
    /* @3969284 cast */
    /* @3969288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3969320;
    L_3969292: ;
    /* @3969292 constant */
    /* @3969296 cast */
    /* @3969300 load */
    /* @3969308 call */
    GM_SITE(vm, 151, 3969308);
    /* @3969316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3969320: ;
    /* @3969320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969292;
    L_3969324: ;
    /* @3969324 load */
    /* @3969332 constant */
    /* @3969336 cmp */
    /* @3969340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3970480;
    /* @3969344 constant */
    /* @3969348 cast */
    /* @3969352 load */
    /* @3969360 constant */
    /* @3969364 sub */
    /* @3969368 load */
    /* @3969376 call */
    GM_SITE(vm, 151, 3969376);
    /* @3969384 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v35);
    /* @3969392 load */
    /* @3969400 cast */
    /* @3969404 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3969436;
    L_3969408: ;
    /* @3969408 constant */
    /* @3969412 cast */
    /* @3969416 load */
    /* @3969424 call */
    GM_SITE(vm, 151, 3969424);
    /* @3969432 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3969436: ;
    /* @3969436 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969408;
    /* @3969440 constant */
    /* @3969444 cast */
    /* @3969448 load */
    /* @3969456 constant */
    /* @3969460 sub */
    /* @3969464 load */
    /* @3969472 constant */
    /* @3969476 add */
    /* @3969480 call */
    GM_SITE(vm, 151, 3969480);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3969488 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v37);
    /* @3969496 load */
    /* @3969504 cast */
    /* @3969508 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3969540;
    L_3969512: ;
    /* @3969512 constant */
    /* @3969516 cast */
    /* @3969520 load */
    /* @3969528 call */
    GM_SITE(vm, 151, 3969528);
    /* @3969536 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3969540: ;
    /* @3969540 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969512;
    /* @3969544 constant */
    /* @3969548 cast */
    /* @3969552 load */
    /* @3969560 constant */
    /* @3969564 sub */
    /* @3969568 load */
    /* @3969576 constant */
    /* @3969580 sub */
    /* @3969584 call */
    GM_SITE(vm, 151, 3969584);
    /* @3969592 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v38);
    /* @3969600 load */
    /* @3969608 cast */
    /* @3969612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3969644;
    L_3969616: ;
    /* @3969616 constant */
    /* @3969620 cast */
    /* @3969624 load */
    /* @3969632 call */
    GM_SITE(vm, 151, 3969632);
    /* @3969640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3969644: ;
    /* @3969644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969616;
    /* @3969648 constant */
    /* @3969652 cast */
    /* @3969656 load */
    /* @3969664 constant */
    /* @3969668 sub */
    /* @3969672 load */
    /* @3969680 constant */
    /* @3969684 add */
    /* @3969688 call */
    GM_SITE(vm, 151, 3969688);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3969696 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v40);
    /* @3969704 load */
    /* @3969712 cast */
    /* @3969716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3969748;
    L_3969720: ;
    /* @3969720 constant */
    /* @3969724 cast */
    /* @3969728 load */
    /* @3969736 call */
    GM_SITE(vm, 151, 3969736);
    /* @3969744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3969748: ;
    /* @3969748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969720;
    /* @3969752 constant */
    /* @3969756 cast */
    /* @3969760 load */
    /* @3969768 constant */
    /* @3969772 sub */
    /* @3969776 load */
    /* @3969784 constant */
    /* @3969788 sub */
    /* @3969792 call */
    GM_SITE(vm, 151, 3969792);
    /* @3969800 store */
    v41 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v41);
    /* @3969808 load */
    /* @3969816 cast */
    /* @3969820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3969852;
    L_3969824: ;
    /* @3969824 constant */
    /* @3969828 cast */
    /* @3969832 load */
    /* @3969840 call */
    GM_SITE(vm, 151, 3969840);
    /* @3969848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3969852: ;
    /* @3969852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969824;
    /* @3969856 constant */
    /* @3969860 cast */
    /* @3969864 load */
    /* @3969872 constant */
    /* @3969876 sub */
    /* @3969880 load */
    /* @3969888 constant */
    /* @3969892 add */
    /* @3969896 call */
    GM_SITE(vm, 151, 3969896);
    v42 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3969904 store */
    v43 = GM_CALL(vm, "instance_create", 3, v42, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @3969912 load */
    /* @3969920 cast */
    /* @3969924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3969956;
    L_3969928: ;
    /* @3969928 constant */
    /* @3969932 cast */
    /* @3969936 load */
    /* @3969944 call */
    GM_SITE(vm, 151, 3969944);
    /* @3969952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3969956: ;
    /* @3969956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3969928;
    /* @3969960 constant */
    /* @3969964 cast */
    /* @3969968 load */
    /* @3969976 constant */
    /* @3969980 sub */
    /* @3969984 load */
    /* @3969992 constant */
    /* @3969996 add */
    /* @3970000 call */
    GM_SITE(vm, 151, 3970000);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3970008 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @3970016 load */
    /* @3970024 cast */
    /* @3970028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3970060;
    L_3970032: ;
    /* @3970032 constant */
    /* @3970036 cast */
    /* @3970040 load */
    /* @3970048 call */
    GM_SITE(vm, 151, 3970048);
    /* @3970056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3970060: ;
    /* @3970060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970032;
    /* @3970064 constant */
    /* @3970068 cast */
    /* @3970072 load */
    /* @3970080 constant */
    /* @3970084 sub */
    /* @3970088 load */
    /* @3970096 constant */
    /* @3970100 sub */
    /* @3970104 call */
    GM_SITE(vm, 151, 3970104);
    /* @3970112 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @3970120 load */
    /* @3970128 cast */
    /* @3970132 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3970164;
    L_3970136: ;
    /* @3970136 constant */
    /* @3970140 cast */
    /* @3970144 load */
    /* @3970152 call */
    GM_SITE(vm, 151, 3970152);
    /* @3970160 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3970164: ;
    /* @3970164 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970136;
    /* @3970168 constant */
    /* @3970172 cast */
    /* @3970176 load */
    /* @3970184 constant */
    /* @3970188 sub */
    /* @3970192 load */
    /* @3970200 constant */
    /* @3970204 add */
    /* @3970208 call */
    GM_SITE(vm, 151, 3970208);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3970216 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @3970224 load */
    /* @3970232 cast */
    /* @3970236 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3970268;
    L_3970240: ;
    /* @3970240 constant */
    /* @3970244 cast */
    /* @3970248 load */
    /* @3970256 call */
    GM_SITE(vm, 151, 3970256);
    /* @3970264 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3970268: ;
    /* @3970268 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970240;
    /* @3970272 constant */
    /* @3970276 cast */
    /* @3970280 load */
    /* @3970288 constant */
    /* @3970292 sub */
    /* @3970296 load */
    /* @3970304 constant */
    /* @3970308 sub */
    /* @3970312 call */
    GM_SITE(vm, 151, 3970312);
    /* @3970320 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @3970328 load */
    /* @3970336 cast */
    /* @3970340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3970372;
    L_3970344: ;
    /* @3970344 constant */
    /* @3970348 cast */
    /* @3970352 load */
    /* @3970360 call */
    GM_SITE(vm, 151, 3970360);
    /* @3970368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3970372: ;
    /* @3970372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970344;
    /* @3970376 constant */
    /* @3970380 cast */
    /* @3970384 load */
    /* @3970392 constant */
    /* @3970396 sub */
    /* @3970400 load */
    /* @3970408 constant */
    /* @3970412 sub */
    /* @3970416 call */
    GM_SITE(vm, 151, 3970416);
    /* @3970424 store */
    v50 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v50);
    /* @3970432 load */
    /* @3970440 cast */
    /* @3970444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3970476;
    L_3970448: ;
    /* @3970448 constant */
    /* @3970452 cast */
    /* @3970456 load */
    /* @3970464 call */
    GM_SITE(vm, 151, 3970464);
    /* @3970472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3970476: ;
    /* @3970476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970448;
    L_3970480: ;
    /* @3970480 load */
    /* @3970488 constant */
    /* @3970492 cmp */
    /* @3970496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3971532;
    /* @3970500 constant */
    /* @3970504 cast */
    /* @3970508 load */
    /* @3970516 constant */
    /* @3970520 sub */
    /* @3970524 load */
    /* @3970532 call */
    GM_SITE(vm, 151, 3970532);
    /* @3970540 store */
    v51 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v51);
    /* @3970548 load */
    /* @3970556 cast */
    /* @3970560 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3970592;
    L_3970564: ;
    /* @3970564 constant */
    /* @3970568 cast */
    /* @3970572 load */
    /* @3970580 call */
    GM_SITE(vm, 151, 3970580);
    /* @3970588 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3970592: ;
    /* @3970592 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970564;
    /* @3970596 constant */
    /* @3970600 cast */
    /* @3970604 load */
    /* @3970612 constant */
    /* @3970616 sub */
    /* @3970620 load */
    /* @3970628 constant */
    /* @3970632 add */
    /* @3970636 call */
    GM_SITE(vm, 151, 3970636);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3970644 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v53);
    /* @3970652 load */
    /* @3970660 cast */
    /* @3970664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3970696;
    L_3970668: ;
    /* @3970668 constant */
    /* @3970672 cast */
    /* @3970676 load */
    /* @3970684 call */
    GM_SITE(vm, 151, 3970684);
    /* @3970692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3970696: ;
    /* @3970696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970668;
    /* @3970700 constant */
    /* @3970704 cast */
    /* @3970708 load */
    /* @3970716 constant */
    /* @3970720 sub */
    /* @3970724 load */
    /* @3970732 constant */
    /* @3970736 sub */
    /* @3970740 call */
    GM_SITE(vm, 151, 3970740);
    /* @3970748 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v54);
    /* @3970756 load */
    /* @3970764 cast */
    /* @3970768 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3970800;
    L_3970772: ;
    /* @3970772 constant */
    /* @3970776 cast */
    /* @3970780 load */
    /* @3970788 call */
    GM_SITE(vm, 151, 3970788);
    /* @3970796 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3970800: ;
    /* @3970800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970772;
    /* @3970804 constant */
    /* @3970808 cast */
    /* @3970812 load */
    /* @3970820 constant */
    /* @3970824 sub */
    /* @3970828 load */
    /* @3970836 constant */
    /* @3970840 add */
    /* @3970844 call */
    GM_SITE(vm, 151, 3970844);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3970852 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v56);
    /* @3970860 load */
    /* @3970868 cast */
    /* @3970872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3970904;
    L_3970876: ;
    /* @3970876 constant */
    /* @3970880 cast */
    /* @3970884 load */
    /* @3970892 call */
    GM_SITE(vm, 151, 3970892);
    /* @3970900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3970904: ;
    /* @3970904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970876;
    /* @3970908 constant */
    /* @3970912 cast */
    /* @3970916 load */
    /* @3970924 constant */
    /* @3970928 sub */
    /* @3970932 load */
    /* @3970940 constant */
    /* @3970944 sub */
    /* @3970948 call */
    GM_SITE(vm, 151, 3970948);
    /* @3970956 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v57);
    /* @3970964 load */
    /* @3970972 cast */
    /* @3970976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3971008;
    L_3970980: ;
    /* @3970980 constant */
    /* @3970984 cast */
    /* @3970988 load */
    /* @3970996 call */
    GM_SITE(vm, 151, 3970996);
    /* @3971004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3971008: ;
    /* @3971008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3970980;
    /* @3971012 constant */
    /* @3971016 cast */
    /* @3971020 load */
    /* @3971028 constant */
    /* @3971032 sub */
    /* @3971036 load */
    /* @3971044 constant */
    /* @3971048 add */
    /* @3971052 call */
    GM_SITE(vm, 151, 3971052);
    v58 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3971060 store */
    v59 = GM_CALL(vm, "instance_create", 3, v58, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v59);
    /* @3971068 load */
    /* @3971076 cast */
    /* @3971080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3971112;
    L_3971084: ;
    /* @3971084 constant */
    /* @3971088 cast */
    /* @3971092 load */
    /* @3971100 call */
    GM_SITE(vm, 151, 3971100);
    /* @3971108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3971112: ;
    /* @3971112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3971084;
    /* @3971116 constant */
    /* @3971120 cast */
    /* @3971124 load */
    /* @3971132 constant */
    /* @3971136 sub */
    /* @3971140 load */
    /* @3971148 constant */
    /* @3971152 add */
    /* @3971156 call */
    GM_SITE(vm, 151, 3971156);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3971164 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v61);
    /* @3971172 load */
    /* @3971180 cast */
    /* @3971184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3971216;
    L_3971188: ;
    /* @3971188 constant */
    /* @3971192 cast */
    /* @3971196 load */
    /* @3971204 call */
    GM_SITE(vm, 151, 3971204);
    /* @3971212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3971216: ;
    /* @3971216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3971188;
    /* @3971220 constant */
    /* @3971224 cast */
    /* @3971228 load */
    /* @3971236 constant */
    /* @3971240 sub */
    /* @3971244 load */
    /* @3971252 constant */
    /* @3971256 sub */
    /* @3971260 call */
    GM_SITE(vm, 151, 3971260);
    /* @3971268 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v62);
    /* @3971276 load */
    /* @3971284 cast */
    /* @3971288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3971320;
    L_3971292: ;
    /* @3971292 constant */
    /* @3971296 cast */
    /* @3971300 load */
    /* @3971308 call */
    GM_SITE(vm, 151, 3971308);
    /* @3971316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3971320: ;
    /* @3971320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3971292;
    /* @3971324 constant */
    /* @3971328 cast */
    /* @3971332 load */
    /* @3971340 constant */
    /* @3971344 sub */
    /* @3971348 load */
    /* @3971356 constant */
    /* @3971360 add */
    /* @3971364 call */
    GM_SITE(vm, 151, 3971364);
    v63 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3971372 store */
    v64 = GM_CALL(vm, "instance_create", 3, v63, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v64);
    /* @3971380 load */
    /* @3971388 cast */
    /* @3971392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3971424;
    L_3971396: ;
    /* @3971396 constant */
    /* @3971400 cast */
    /* @3971404 load */
    /* @3971412 call */
    GM_SITE(vm, 151, 3971412);
    /* @3971420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3971424: ;
    /* @3971424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3971396;
    /* @3971428 constant */
    /* @3971432 cast */
    /* @3971436 load */
    /* @3971444 constant */
    /* @3971448 sub */
    /* @3971452 load */
    /* @3971460 constant */
    /* @3971464 sub */
    /* @3971468 call */
    GM_SITE(vm, 151, 3971468);
    /* @3971476 store */
    v65 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v65);
    /* @3971484 load */
    /* @3971492 cast */
    /* @3971496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3971528;
    L_3971500: ;
    /* @3971500 constant */
    /* @3971504 cast */
    /* @3971508 load */
    /* @3971516 call */
    GM_SITE(vm, 151, 3971516);
    /* @3971524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3971528: ;
    /* @3971528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3971500;
    L_3971532: ;
    /* @3971532 call */
    GM_SITE(vm, 151, 3971532);
    /* @3971540 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3971544: ;
    return;
}
