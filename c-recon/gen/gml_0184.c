/* generated from CODE 184 (gml_Object_obj_boss3_Alarm_0), source start 3995808, end 4004944. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0184(GmVM* vm) {
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
    /* @3995808 load */
    /* @3995816 constant */
    /* @3995820 cmp */
    /* @3995824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3995832;
    /* @3995828 b */
    goto L_3995888;
    L_3995832: ;
    /* @3995832 load */
    /* @3995840 constant */
    /* @3995844 cmp */
    /* @3995848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3995888;
    /* @3995852 constant */
    /* @3995856 cast */
    /* @3995860 constant */
    /* @3995864 cast */
    /* @3995868 constant */
    /* @3995872 cast */
    /* @3995876 call */
    GM_SITE(vm, 184, 3995876);
    /* @3995884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3995888: ;
    /* @3995888 load */
    /* @3995896 constant */
    /* @3995900 cmp */
    /* @3995904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3995952;
    /* @3995908 constant */
    /* @3995912 cast */
    /* @3995916 load */
    /* @3995924 constant */
    /* @3995928 sub */
    /* @3995932 load */
    /* @3995940 call */
    GM_SITE(vm, 184, 3995940);
    /* @3995948 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3995952: ;
    /* @3995952 constant */
    /* @3995956 store */
    GM_WRITE(vm, -5, "boss3dead", VAL(1));
    /* @3995964 load */
    /* @3995972 constant */
    /* @3995976 cmp */
    /* @3995980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3996028;
    /* @3995984 constant */
    /* @3995988 cast */
    /* @3995992 load */
    /* @3996000 constant */
    /* @3996004 sub */
    /* @3996008 load */
    /* @3996016 call */
    GM_SITE(vm, 184, 3996016);
    /* @3996024 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3996028: ;
    /* @3996028 load */
    /* @3996036 constant */
    /* @3996040 cmp */
    /* @3996044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3997072;
    /* @3996048 constant */
    /* @3996052 cast */
    /* @3996056 load */
    /* @3996064 constant */
    /* @3996068 sub */
    /* @3996072 load */
    /* @3996080 call */
    GM_SITE(vm, 184, 3996080);
    /* @3996088 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3996096 load */
    /* @3996104 cast */
    /* @3996108 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3996140;
    L_3996112: ;
    /* @3996112 constant */
    /* @3996116 cast */
    /* @3996120 load */
    /* @3996128 call */
    GM_SITE(vm, 184, 3996128);
    /* @3996136 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3996140: ;
    /* @3996140 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996112;
    /* @3996144 constant */
    /* @3996148 cast */
    /* @3996152 load */
    /* @3996160 constant */
    /* @3996164 sub */
    /* @3996168 load */
    /* @3996176 constant */
    /* @3996180 add */
    /* @3996184 call */
    GM_SITE(vm, 184, 3996184);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(7));
    /* @3996192 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @3996200 load */
    /* @3996208 cast */
    /* @3996212 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3996244;
    L_3996216: ;
    /* @3996216 constant */
    /* @3996220 cast */
    /* @3996224 load */
    /* @3996232 call */
    GM_SITE(vm, 184, 3996232);
    /* @3996240 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3996244: ;
    /* @3996244 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996216;
    /* @3996248 constant */
    /* @3996252 cast */
    /* @3996256 load */
    /* @3996264 constant */
    /* @3996268 sub */
    /* @3996272 load */
    /* @3996280 constant */
    /* @3996284 sub */
    /* @3996288 call */
    GM_SITE(vm, 184, 3996288);
    /* @3996296 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(7)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @3996304 load */
    /* @3996312 cast */
    /* @3996316 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3996348;
    L_3996320: ;
    /* @3996320 constant */
    /* @3996324 cast */
    /* @3996328 load */
    /* @3996336 call */
    GM_SITE(vm, 184, 3996336);
    /* @3996344 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3996348: ;
    /* @3996348 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996320;
    /* @3996352 constant */
    /* @3996356 cast */
    /* @3996360 load */
    /* @3996368 constant */
    /* @3996372 sub */
    /* @3996376 load */
    /* @3996384 constant */
    /* @3996388 add */
    /* @3996392 call */
    GM_SITE(vm, 184, 3996392);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @3996400 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @3996408 load */
    /* @3996416 cast */
    /* @3996420 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3996452;
    L_3996424: ;
    /* @3996424 constant */
    /* @3996428 cast */
    /* @3996432 load */
    /* @3996440 call */
    GM_SITE(vm, 184, 3996440);
    /* @3996448 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3996452: ;
    /* @3996452 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996424;
    /* @3996456 constant */
    /* @3996460 cast */
    /* @3996464 load */
    /* @3996472 constant */
    /* @3996476 sub */
    /* @3996480 load */
    /* @3996488 constant */
    /* @3996492 sub */
    /* @3996496 call */
    GM_SITE(vm, 184, 3996496);
    /* @3996504 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @3996512 load */
    /* @3996520 cast */
    /* @3996524 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3996556;
    L_3996528: ;
    /* @3996528 constant */
    /* @3996532 cast */
    /* @3996536 load */
    /* @3996544 call */
    GM_SITE(vm, 184, 3996544);
    /* @3996552 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3996556: ;
    /* @3996556 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996528;
    /* @3996560 constant */
    /* @3996564 cast */
    /* @3996568 load */
    /* @3996576 constant */
    /* @3996580 sub */
    /* @3996584 load */
    /* @3996592 call */
    GM_SITE(vm, 184, 3996592);
    /* @3996600 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID6", v8);
    /* @3996608 load */
    /* @3996616 cast */
    /* @3996620 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3996652;
    L_3996624: ;
    /* @3996624 constant */
    /* @3996628 cast */
    /* @3996632 load */
    /* @3996640 call */
    GM_SITE(vm, 184, 3996640);
    /* @3996648 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3996652: ;
    /* @3996652 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996624;
    /* @3996656 constant */
    /* @3996660 cast */
    /* @3996664 load */
    /* @3996672 constant */
    /* @3996676 sub */
    /* @3996680 load */
    /* @3996688 constant */
    /* @3996692 add */
    /* @3996696 call */
    GM_SITE(vm, 184, 3996696);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @3996704 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID7", v10);
    /* @3996712 load */
    /* @3996720 cast */
    /* @3996724 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3996756;
    L_3996728: ;
    /* @3996728 constant */
    /* @3996732 cast */
    /* @3996736 load */
    /* @3996744 call */
    GM_SITE(vm, 184, 3996744);
    /* @3996752 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3996756: ;
    /* @3996756 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996728;
    /* @3996760 constant */
    /* @3996764 cast */
    /* @3996768 load */
    /* @3996776 constant */
    /* @3996780 sub */
    /* @3996784 load */
    /* @3996792 constant */
    /* @3996796 sub */
    /* @3996800 call */
    GM_SITE(vm, 184, 3996800);
    /* @3996808 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(17)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID8", v11);
    /* @3996816 load */
    /* @3996824 cast */
    /* @3996828 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3996860;
    L_3996832: ;
    /* @3996832 constant */
    /* @3996836 cast */
    /* @3996840 load */
    /* @3996848 call */
    GM_SITE(vm, 184, 3996848);
    /* @3996856 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3996860: ;
    /* @3996860 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996832;
    /* @3996864 constant */
    /* @3996868 cast */
    /* @3996872 load */
    /* @3996880 constant */
    /* @3996884 sub */
    /* @3996888 load */
    /* @3996896 constant */
    /* @3996900 add */
    /* @3996904 call */
    GM_SITE(vm, 184, 3996904);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3996912 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID9", v13);
    /* @3996920 load */
    /* @3996928 cast */
    /* @3996932 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3996964;
    L_3996936: ;
    /* @3996936 constant */
    /* @3996940 cast */
    /* @3996944 load */
    /* @3996952 call */
    GM_SITE(vm, 184, 3996952);
    /* @3996960 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3996964: ;
    /* @3996964 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3996936;
    /* @3996968 constant */
    /* @3996972 cast */
    /* @3996976 load */
    /* @3996984 constant */
    /* @3996988 sub */
    /* @3996992 load */
    /* @3997000 constant */
    /* @3997004 sub */
    /* @3997008 call */
    GM_SITE(vm, 184, 3997008);
    /* @3997016 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(21)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID10", v14);
    /* @3997024 load */
    /* @3997032 cast */
    /* @3997036 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3997068;
    L_3997040: ;
    /* @3997040 constant */
    /* @3997044 cast */
    /* @3997048 load */
    /* @3997056 call */
    GM_SITE(vm, 184, 3997056);
    /* @3997064 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3997068: ;
    /* @3997068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997040;
    L_3997072: ;
    /* @3997072 load */
    /* @3997080 constant */
    /* @3997084 cmp */
    /* @3997088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3997604;
    /* @3997092 constant */
    /* @3997096 cast */
    /* @3997100 load */
    /* @3997108 constant */
    /* @3997112 sub */
    /* @3997116 load */
    /* @3997124 call */
    GM_SITE(vm, 184, 3997124);
    /* @3997132 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3997140 load */
    /* @3997148 cast */
    /* @3997152 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3997184;
    L_3997156: ;
    /* @3997156 constant */
    /* @3997160 cast */
    /* @3997164 load */
    /* @3997172 call */
    GM_SITE(vm, 184, 3997172);
    /* @3997180 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3997184: ;
    /* @3997184 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997156;
    /* @3997188 constant */
    /* @3997192 cast */
    /* @3997196 load */
    /* @3997204 constant */
    /* @3997208 sub */
    /* @3997212 load */
    /* @3997220 constant */
    /* @3997224 add */
    /* @3997228 call */
    GM_SITE(vm, 184, 3997228);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3997236 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3997244 load */
    /* @3997252 cast */
    /* @3997256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3997288;
    L_3997260: ;
    /* @3997260 constant */
    /* @3997264 cast */
    /* @3997268 load */
    /* @3997276 call */
    GM_SITE(vm, 184, 3997276);
    /* @3997284 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3997288: ;
    /* @3997288 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997260;
    /* @3997292 constant */
    /* @3997296 cast */
    /* @3997300 load */
    /* @3997308 constant */
    /* @3997312 sub */
    /* @3997316 load */
    /* @3997324 constant */
    /* @3997328 sub */
    /* @3997332 call */
    GM_SITE(vm, 184, 3997332);
    /* @3997340 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3997348 load */
    /* @3997356 cast */
    /* @3997360 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3997392;
    L_3997364: ;
    /* @3997364 constant */
    /* @3997368 cast */
    /* @3997372 load */
    /* @3997380 call */
    GM_SITE(vm, 184, 3997380);
    /* @3997388 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3997392: ;
    /* @3997392 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997364;
    /* @3997396 constant */
    /* @3997400 cast */
    /* @3997404 load */
    /* @3997412 constant */
    /* @3997416 sub */
    /* @3997420 load */
    /* @3997428 constant */
    /* @3997432 add */
    /* @3997436 call */
    GM_SITE(vm, 184, 3997436);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3997444 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3997452 load */
    /* @3997460 cast */
    /* @3997464 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3997496;
    L_3997468: ;
    /* @3997468 constant */
    /* @3997472 cast */
    /* @3997476 load */
    /* @3997484 call */
    GM_SITE(vm, 184, 3997484);
    /* @3997492 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3997496: ;
    /* @3997496 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997468;
    /* @3997500 constant */
    /* @3997504 cast */
    /* @3997508 load */
    /* @3997516 constant */
    /* @3997520 sub */
    /* @3997524 load */
    /* @3997532 constant */
    /* @3997536 sub */
    /* @3997540 call */
    GM_SITE(vm, 184, 3997540);
    /* @3997548 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3997556 load */
    /* @3997564 cast */
    /* @3997568 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3997600;
    L_3997572: ;
    /* @3997572 constant */
    /* @3997576 cast */
    /* @3997580 load */
    /* @3997588 call */
    GM_SITE(vm, 184, 3997588);
    /* @3997596 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3997600: ;
    /* @3997600 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997572;
    L_3997604: ;
    /* @3997604 load */
    /* @3997612 constant */
    /* @3997616 cmp */
    /* @3997620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3998656;
    /* @3997624 constant */
    /* @3997628 cast */
    /* @3997632 load */
    /* @3997640 constant */
    /* @3997644 sub */
    /* @3997648 load */
    /* @3997656 call */
    GM_SITE(vm, 184, 3997656);
    /* @3997664 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v22);
    /* @3997672 load */
    /* @3997680 cast */
    /* @3997684 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3997716;
    L_3997688: ;
    /* @3997688 constant */
    /* @3997692 cast */
    /* @3997696 load */
    /* @3997704 call */
    GM_SITE(vm, 184, 3997704);
    /* @3997712 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3997716: ;
    /* @3997716 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997688;
    /* @3997720 constant */
    /* @3997724 cast */
    /* @3997728 load */
    /* @3997736 constant */
    /* @3997740 sub */
    /* @3997744 load */
    /* @3997752 constant */
    /* @3997756 add */
    /* @3997760 call */
    GM_SITE(vm, 184, 3997760);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3997768 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v24);
    /* @3997776 load */
    /* @3997784 cast */
    /* @3997788 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3997820;
    L_3997792: ;
    /* @3997792 constant */
    /* @3997796 cast */
    /* @3997800 load */
    /* @3997808 call */
    GM_SITE(vm, 184, 3997808);
    /* @3997816 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3997820: ;
    /* @3997820 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997792;
    /* @3997824 constant */
    /* @3997828 cast */
    /* @3997832 load */
    /* @3997840 constant */
    /* @3997844 sub */
    /* @3997848 load */
    /* @3997856 constant */
    /* @3997860 sub */
    /* @3997864 call */
    GM_SITE(vm, 184, 3997864);
    /* @3997872 store */
    v25 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v25);
    /* @3997880 load */
    /* @3997888 cast */
    /* @3997892 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3997924;
    L_3997896: ;
    /* @3997896 constant */
    /* @3997900 cast */
    /* @3997904 load */
    /* @3997912 call */
    GM_SITE(vm, 184, 3997912);
    /* @3997920 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3997924: ;
    /* @3997924 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3997896;
    /* @3997928 constant */
    /* @3997932 cast */
    /* @3997936 load */
    /* @3997944 constant */
    /* @3997948 sub */
    /* @3997952 load */
    /* @3997960 constant */
    /* @3997964 add */
    /* @3997968 call */
    GM_SITE(vm, 184, 3997968);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3997976 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v27);
    /* @3997984 load */
    /* @3997992 cast */
    /* @3997996 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3998028;
    L_3998000: ;
    /* @3998000 constant */
    /* @3998004 cast */
    /* @3998008 load */
    /* @3998016 call */
    GM_SITE(vm, 184, 3998016);
    /* @3998024 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3998028: ;
    /* @3998028 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998000;
    /* @3998032 constant */
    /* @3998036 cast */
    /* @3998040 load */
    /* @3998048 constant */
    /* @3998052 sub */
    /* @3998056 load */
    /* @3998064 constant */
    /* @3998068 sub */
    /* @3998072 call */
    GM_SITE(vm, 184, 3998072);
    /* @3998080 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v28);
    /* @3998088 load */
    /* @3998096 cast */
    /* @3998100 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3998132;
    L_3998104: ;
    /* @3998104 constant */
    /* @3998108 cast */
    /* @3998112 load */
    /* @3998120 call */
    GM_SITE(vm, 184, 3998120);
    /* @3998128 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3998132: ;
    /* @3998132 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998104;
    /* @3998136 constant */
    /* @3998140 cast */
    /* @3998144 load */
    /* @3998152 constant */
    /* @3998156 sub */
    /* @3998160 load */
    /* @3998168 constant */
    /* @3998172 sub */
    /* @3998176 call */
    GM_SITE(vm, 184, 3998176);
    /* @3998184 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @3998192 load */
    /* @3998200 cast */
    /* @3998204 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3998236;
    L_3998208: ;
    /* @3998208 constant */
    /* @3998212 cast */
    /* @3998216 load */
    /* @3998224 call */
    GM_SITE(vm, 184, 3998224);
    /* @3998232 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3998236: ;
    /* @3998236 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998208;
    /* @3998240 constant */
    /* @3998244 cast */
    /* @3998248 load */
    /* @3998256 constant */
    /* @3998260 sub */
    /* @3998264 load */
    /* @3998272 constant */
    /* @3998276 add */
    /* @3998280 call */
    GM_SITE(vm, 184, 3998280);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3998288 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @3998296 load */
    /* @3998304 cast */
    /* @3998308 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3998340;
    L_3998312: ;
    /* @3998312 constant */
    /* @3998316 cast */
    /* @3998320 load */
    /* @3998328 call */
    GM_SITE(vm, 184, 3998328);
    /* @3998336 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3998340: ;
    /* @3998340 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998312;
    /* @3998344 constant */
    /* @3998348 cast */
    /* @3998352 load */
    /* @3998360 constant */
    /* @3998364 sub */
    /* @3998368 load */
    /* @3998376 constant */
    /* @3998380 sub */
    /* @3998384 call */
    GM_SITE(vm, 184, 3998384);
    /* @3998392 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @3998400 load */
    /* @3998408 cast */
    /* @3998412 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3998444;
    L_3998416: ;
    /* @3998416 constant */
    /* @3998420 cast */
    /* @3998424 load */
    /* @3998432 call */
    GM_SITE(vm, 184, 3998432);
    /* @3998440 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3998444: ;
    /* @3998444 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998416;
    /* @3998448 constant */
    /* @3998452 cast */
    /* @3998456 load */
    /* @3998464 constant */
    /* @3998468 sub */
    /* @3998472 load */
    /* @3998480 constant */
    /* @3998484 add */
    /* @3998488 call */
    GM_SITE(vm, 184, 3998488);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3998496 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @3998504 load */
    /* @3998512 cast */
    /* @3998516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3998548;
    L_3998520: ;
    /* @3998520 constant */
    /* @3998524 cast */
    /* @3998528 load */
    /* @3998536 call */
    GM_SITE(vm, 184, 3998536);
    /* @3998544 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3998548: ;
    /* @3998548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998520;
    /* @3998552 constant */
    /* @3998556 cast */
    /* @3998560 load */
    /* @3998568 constant */
    /* @3998572 sub */
    /* @3998576 load */
    /* @3998584 constant */
    /* @3998588 sub */
    /* @3998592 call */
    GM_SITE(vm, 184, 3998592);
    /* @3998600 store */
    v35 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v35);
    /* @3998608 load */
    /* @3998616 cast */
    /* @3998620 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3998652;
    L_3998624: ;
    /* @3998624 constant */
    /* @3998628 cast */
    /* @3998632 load */
    /* @3998640 call */
    GM_SITE(vm, 184, 3998640);
    /* @3998648 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3998652: ;
    /* @3998652 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998624;
    L_3998656: ;
    /* @3998656 load */
    /* @3998664 constant */
    /* @3998668 cmp */
    /* @3998672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_4000228;
    /* @3998676 constant */
    /* @3998680 cast */
    /* @3998684 load */
    /* @3998692 constant */
    /* @3998696 sub */
    /* @3998700 load */
    /* @3998708 call */
    GM_SITE(vm, 184, 3998708);
    /* @3998716 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v36);
    /* @3998724 load */
    /* @3998732 cast */
    /* @3998736 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3998768;
    L_3998740: ;
    /* @3998740 constant */
    /* @3998744 cast */
    /* @3998748 load */
    /* @3998756 call */
    GM_SITE(vm, 184, 3998756);
    /* @3998764 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3998768: ;
    /* @3998768 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998740;
    /* @3998772 constant */
    /* @3998776 cast */
    /* @3998780 load */
    /* @3998788 constant */
    /* @3998792 sub */
    /* @3998796 load */
    /* @3998804 constant */
    /* @3998808 add */
    /* @3998812 call */
    GM_SITE(vm, 184, 3998812);
    v37 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3998820 store */
    v38 = GM_CALL(vm, "instance_create", 3, v37, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v38);
    /* @3998828 load */
    /* @3998836 cast */
    /* @3998840 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3998872;
    L_3998844: ;
    /* @3998844 constant */
    /* @3998848 cast */
    /* @3998852 load */
    /* @3998860 call */
    GM_SITE(vm, 184, 3998860);
    /* @3998868 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3998872: ;
    /* @3998872 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998844;
    /* @3998876 constant */
    /* @3998880 cast */
    /* @3998884 load */
    /* @3998892 constant */
    /* @3998896 sub */
    /* @3998900 load */
    /* @3998908 constant */
    /* @3998912 sub */
    /* @3998916 call */
    GM_SITE(vm, 184, 3998916);
    /* @3998924 store */
    v39 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v39);
    /* @3998932 load */
    /* @3998940 cast */
    /* @3998944 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3998976;
    L_3998948: ;
    /* @3998948 constant */
    /* @3998952 cast */
    /* @3998956 load */
    /* @3998964 call */
    GM_SITE(vm, 184, 3998964);
    /* @3998972 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3998976: ;
    /* @3998976 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3998948;
    /* @3998980 constant */
    /* @3998984 cast */
    /* @3998988 load */
    /* @3998996 constant */
    /* @3999000 sub */
    /* @3999004 load */
    /* @3999012 constant */
    /* @3999016 add */
    /* @3999020 call */
    GM_SITE(vm, 184, 3999020);
    v40 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3999028 store */
    v41 = GM_CALL(vm, "instance_create", 3, v40, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v41);
    /* @3999036 load */
    /* @3999044 cast */
    /* @3999048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3999080;
    L_3999052: ;
    /* @3999052 constant */
    /* @3999056 cast */
    /* @3999060 load */
    /* @3999068 call */
    GM_SITE(vm, 184, 3999068);
    /* @3999076 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3999080: ;
    /* @3999080 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999052;
    /* @3999084 constant */
    /* @3999088 cast */
    /* @3999092 load */
    /* @3999100 constant */
    /* @3999104 sub */
    /* @3999108 load */
    /* @3999116 constant */
    /* @3999120 sub */
    /* @3999124 call */
    GM_SITE(vm, 184, 3999124);
    /* @3999132 store */
    v42 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v42);
    /* @3999140 load */
    /* @3999148 cast */
    /* @3999152 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3999184;
    L_3999156: ;
    /* @3999156 constant */
    /* @3999160 cast */
    /* @3999164 load */
    /* @3999172 call */
    GM_SITE(vm, 184, 3999172);
    /* @3999180 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3999184: ;
    /* @3999184 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999156;
    /* @3999188 constant */
    /* @3999192 cast */
    /* @3999196 load */
    /* @3999204 constant */
    /* @3999208 sub */
    /* @3999212 load */
    /* @3999220 constant */
    /* @3999224 sub */
    /* @3999228 call */
    GM_SITE(vm, 184, 3999228);
    /* @3999236 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v43);
    /* @3999244 load */
    /* @3999252 cast */
    /* @3999256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3999288;
    L_3999260: ;
    /* @3999260 constant */
    /* @3999264 cast */
    /* @3999268 load */
    /* @3999276 call */
    GM_SITE(vm, 184, 3999276);
    /* @3999284 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3999288: ;
    /* @3999288 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999260;
    /* @3999292 constant */
    /* @3999296 cast */
    /* @3999300 load */
    /* @3999308 constant */
    /* @3999312 sub */
    /* @3999316 load */
    /* @3999324 constant */
    /* @3999328 add */
    /* @3999332 call */
    GM_SITE(vm, 184, 3999332);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3999340 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v45);
    /* @3999348 load */
    /* @3999356 cast */
    /* @3999360 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3999392;
    L_3999364: ;
    /* @3999364 constant */
    /* @3999368 cast */
    /* @3999372 load */
    /* @3999380 call */
    GM_SITE(vm, 184, 3999380);
    /* @3999388 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3999392: ;
    /* @3999392 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999364;
    /* @3999396 constant */
    /* @3999400 cast */
    /* @3999404 load */
    /* @3999412 constant */
    /* @3999416 sub */
    /* @3999420 load */
    /* @3999428 constant */
    /* @3999432 sub */
    /* @3999436 call */
    GM_SITE(vm, 184, 3999436);
    /* @3999444 store */
    v46 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v46);
    /* @3999452 load */
    /* @3999460 cast */
    /* @3999464 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3999496;
    L_3999468: ;
    /* @3999468 constant */
    /* @3999472 cast */
    /* @3999476 load */
    /* @3999484 call */
    GM_SITE(vm, 184, 3999484);
    /* @3999492 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3999496: ;
    /* @3999496 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999468;
    /* @3999500 constant */
    /* @3999504 cast */
    /* @3999508 load */
    /* @3999516 constant */
    /* @3999520 sub */
    /* @3999524 load */
    /* @3999532 constant */
    /* @3999536 add */
    /* @3999540 call */
    GM_SITE(vm, 184, 3999540);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3999548 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v48);
    /* @3999556 load */
    /* @3999564 cast */
    /* @3999568 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3999600;
    L_3999572: ;
    /* @3999572 constant */
    /* @3999576 cast */
    /* @3999580 load */
    /* @3999588 call */
    GM_SITE(vm, 184, 3999588);
    /* @3999596 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3999600: ;
    /* @3999600 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999572;
    /* @3999604 constant */
    /* @3999608 cast */
    /* @3999612 load */
    /* @3999620 constant */
    /* @3999624 sub */
    /* @3999628 load */
    /* @3999636 constant */
    /* @3999640 sub */
    /* @3999644 call */
    GM_SITE(vm, 184, 3999644);
    /* @3999652 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v49);
    /* @3999660 load */
    /* @3999668 cast */
    /* @3999672 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3999704;
    L_3999676: ;
    /* @3999676 constant */
    /* @3999680 cast */
    /* @3999684 load */
    /* @3999692 call */
    GM_SITE(vm, 184, 3999692);
    /* @3999700 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3999704: ;
    /* @3999704 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999676;
    /* @3999708 constant */
    /* @3999712 cast */
    /* @3999716 load */
    /* @3999724 constant */
    /* @3999728 sub */
    /* @3999732 load */
    /* @3999740 constant */
    /* @3999744 add */
    /* @3999748 call */
    GM_SITE(vm, 184, 3999748);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3999756 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v51);
    /* @3999764 load */
    /* @3999772 cast */
    /* @3999776 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3999808;
    L_3999780: ;
    /* @3999780 constant */
    /* @3999784 cast */
    /* @3999788 load */
    /* @3999796 call */
    GM_SITE(vm, 184, 3999796);
    /* @3999804 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3999808: ;
    /* @3999808 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999780;
    /* @3999812 constant */
    /* @3999816 cast */
    /* @3999820 load */
    /* @3999828 constant */
    /* @3999832 sub */
    /* @3999836 load */
    /* @3999844 constant */
    /* @3999848 add */
    /* @3999852 call */
    GM_SITE(vm, 184, 3999852);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3999860 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v53);
    /* @3999868 load */
    /* @3999876 cast */
    /* @3999880 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3999912;
    L_3999884: ;
    /* @3999884 constant */
    /* @3999888 cast */
    /* @3999892 load */
    /* @3999900 call */
    GM_SITE(vm, 184, 3999900);
    /* @3999908 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3999912: ;
    /* @3999912 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999884;
    /* @3999916 constant */
    /* @3999920 cast */
    /* @3999924 load */
    /* @3999932 constant */
    /* @3999936 sub */
    /* @3999940 load */
    /* @3999948 constant */
    /* @3999952 sub */
    /* @3999956 call */
    GM_SITE(vm, 184, 3999956);
    /* @3999964 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v54);
    /* @3999972 load */
    /* @3999980 cast */
    /* @3999984 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4000016;
    L_3999988: ;
    /* @3999988 constant */
    /* @3999992 cast */
    /* @3999996 load */
    /* @4000004 call */
    GM_SITE(vm, 184, 4000004);
    /* @4000012 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4000016: ;
    /* @4000016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3999988;
    /* @4000020 constant */
    /* @4000024 cast */
    /* @4000028 load */
    /* @4000036 constant */
    /* @4000040 sub */
    /* @4000044 load */
    /* @4000052 constant */
    /* @4000056 add */
    /* @4000060 call */
    GM_SITE(vm, 184, 4000060);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4000068 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v56);
    /* @4000076 load */
    /* @4000084 cast */
    /* @4000088 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4000120;
    L_4000092: ;
    /* @4000092 constant */
    /* @4000096 cast */
    /* @4000100 load */
    /* @4000108 call */
    GM_SITE(vm, 184, 4000108);
    /* @4000116 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4000120: ;
    /* @4000120 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000092;
    /* @4000124 constant */
    /* @4000128 cast */
    /* @4000132 load */
    /* @4000140 constant */
    /* @4000144 sub */
    /* @4000148 load */
    /* @4000156 constant */
    /* @4000160 sub */
    /* @4000164 call */
    GM_SITE(vm, 184, 4000164);
    /* @4000172 store */
    v57 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v57);
    /* @4000180 load */
    /* @4000188 cast */
    /* @4000192 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4000224;
    L_4000196: ;
    /* @4000196 constant */
    /* @4000200 cast */
    /* @4000204 load */
    /* @4000212 call */
    GM_SITE(vm, 184, 4000212);
    /* @4000220 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4000224: ;
    /* @4000224 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000196;
    L_4000228: ;
    /* @4000228 load */
    /* @4000236 constant */
    /* @4000240 cmp */
    /* @4000244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_4002320;
    /* @4000248 constant */
    /* @4000252 cast */
    /* @4000256 load */
    /* @4000264 constant */
    /* @4000268 sub */
    /* @4000272 load */
    /* @4000280 call */
    GM_SITE(vm, 184, 4000280);
    /* @4000288 store */
    v58 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v58);
    /* @4000296 load */
    /* @4000304 cast */
    /* @4000308 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4000340;
    L_4000312: ;
    /* @4000312 constant */
    /* @4000316 cast */
    /* @4000320 load */
    /* @4000328 call */
    GM_SITE(vm, 184, 4000328);
    /* @4000336 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4000340: ;
    /* @4000340 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000312;
    /* @4000344 constant */
    /* @4000348 cast */
    /* @4000352 load */
    /* @4000360 constant */
    /* @4000364 sub */
    /* @4000368 load */
    /* @4000376 constant */
    /* @4000380 add */
    /* @4000384 call */
    GM_SITE(vm, 184, 4000384);
    v59 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4000392 store */
    v60 = GM_CALL(vm, "instance_create", 3, v59, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v60);
    /* @4000400 load */
    /* @4000408 cast */
    /* @4000412 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4000444;
    L_4000416: ;
    /* @4000416 constant */
    /* @4000420 cast */
    /* @4000424 load */
    /* @4000432 call */
    GM_SITE(vm, 184, 4000432);
    /* @4000440 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4000444: ;
    /* @4000444 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000416;
    /* @4000448 constant */
    /* @4000452 cast */
    /* @4000456 load */
    /* @4000464 constant */
    /* @4000468 sub */
    /* @4000472 load */
    /* @4000480 constant */
    /* @4000484 sub */
    /* @4000488 call */
    GM_SITE(vm, 184, 4000488);
    /* @4000496 store */
    v61 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v61);
    /* @4000504 load */
    /* @4000512 cast */
    /* @4000516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4000548;
    L_4000520: ;
    /* @4000520 constant */
    /* @4000524 cast */
    /* @4000528 load */
    /* @4000536 call */
    GM_SITE(vm, 184, 4000536);
    /* @4000544 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4000548: ;
    /* @4000548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000520;
    /* @4000552 constant */
    /* @4000556 cast */
    /* @4000560 load */
    /* @4000568 constant */
    /* @4000572 sub */
    /* @4000576 load */
    /* @4000584 constant */
    /* @4000588 add */
    /* @4000592 call */
    GM_SITE(vm, 184, 4000592);
    v62 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4000600 store */
    v63 = GM_CALL(vm, "instance_create", 3, v62, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v63);
    /* @4000608 load */
    /* @4000616 cast */
    /* @4000620 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4000652;
    L_4000624: ;
    /* @4000624 constant */
    /* @4000628 cast */
    /* @4000632 load */
    /* @4000640 call */
    GM_SITE(vm, 184, 4000640);
    /* @4000648 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4000652: ;
    /* @4000652 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000624;
    /* @4000656 constant */
    /* @4000660 cast */
    /* @4000664 load */
    /* @4000672 constant */
    /* @4000676 sub */
    /* @4000680 load */
    /* @4000688 constant */
    /* @4000692 sub */
    /* @4000696 call */
    GM_SITE(vm, 184, 4000696);
    /* @4000704 store */
    v64 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v64);
    /* @4000712 load */
    /* @4000720 cast */
    /* @4000724 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4000756;
    L_4000728: ;
    /* @4000728 constant */
    /* @4000732 cast */
    /* @4000736 load */
    /* @4000744 call */
    GM_SITE(vm, 184, 4000744);
    /* @4000752 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4000756: ;
    /* @4000756 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000728;
    /* @4000760 constant */
    /* @4000764 cast */
    /* @4000768 load */
    /* @4000776 constant */
    /* @4000780 sub */
    /* @4000784 load */
    /* @4000792 constant */
    /* @4000796 add */
    /* @4000800 call */
    GM_SITE(vm, 184, 4000800);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4000808 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v66);
    /* @4000816 load */
    /* @4000824 cast */
    /* @4000828 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4000860;
    L_4000832: ;
    /* @4000832 constant */
    /* @4000836 cast */
    /* @4000840 load */
    /* @4000848 call */
    GM_SITE(vm, 184, 4000848);
    /* @4000856 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4000860: ;
    /* @4000860 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000832;
    /* @4000864 constant */
    /* @4000868 cast */
    /* @4000872 load */
    /* @4000880 constant */
    /* @4000884 sub */
    /* @4000888 load */
    /* @4000896 constant */
    /* @4000900 add */
    /* @4000904 call */
    GM_SITE(vm, 184, 4000904);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4000912 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v68);
    /* @4000920 load */
    /* @4000928 cast */
    /* @4000932 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4000964;
    L_4000936: ;
    /* @4000936 constant */
    /* @4000940 cast */
    /* @4000944 load */
    /* @4000952 call */
    GM_SITE(vm, 184, 4000952);
    /* @4000960 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4000964: ;
    /* @4000964 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4000936;
    /* @4000968 constant */
    /* @4000972 cast */
    /* @4000976 load */
    /* @4000984 constant */
    /* @4000988 sub */
    /* @4000992 load */
    /* @4001000 constant */
    /* @4001004 sub */
    /* @4001008 call */
    GM_SITE(vm, 184, 4001008);
    /* @4001016 store */
    v69 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v69);
    /* @4001024 load */
    /* @4001032 cast */
    /* @4001036 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4001068;
    L_4001040: ;
    /* @4001040 constant */
    /* @4001044 cast */
    /* @4001048 load */
    /* @4001056 call */
    GM_SITE(vm, 184, 4001056);
    /* @4001064 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4001068: ;
    /* @4001068 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001040;
    /* @4001072 constant */
    /* @4001076 cast */
    /* @4001080 load */
    /* @4001088 constant */
    /* @4001092 sub */
    /* @4001096 load */
    /* @4001104 constant */
    /* @4001108 add */
    /* @4001112 call */
    GM_SITE(vm, 184, 4001112);
    v70 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4001120 store */
    v71 = GM_CALL(vm, "instance_create", 3, v70, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v71);
    /* @4001128 load */
    /* @4001136 cast */
    /* @4001140 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4001172;
    L_4001144: ;
    /* @4001144 constant */
    /* @4001148 cast */
    /* @4001152 load */
    /* @4001160 call */
    GM_SITE(vm, 184, 4001160);
    /* @4001168 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4001172: ;
    /* @4001172 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001144;
    /* @4001176 constant */
    /* @4001180 cast */
    /* @4001184 load */
    /* @4001192 constant */
    /* @4001196 sub */
    /* @4001200 load */
    /* @4001208 constant */
    /* @4001212 sub */
    /* @4001216 call */
    GM_SITE(vm, 184, 4001216);
    /* @4001224 store */
    v72 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v72);
    /* @4001232 load */
    /* @4001240 cast */
    /* @4001244 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4001276;
    L_4001248: ;
    /* @4001248 constant */
    /* @4001252 cast */
    /* @4001256 load */
    /* @4001264 call */
    GM_SITE(vm, 184, 4001264);
    /* @4001272 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4001276: ;
    /* @4001276 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001248;
    /* @4001280 constant */
    /* @4001284 cast */
    /* @4001288 load */
    /* @4001296 constant */
    /* @4001300 sub */
    /* @4001304 load */
    /* @4001312 constant */
    /* @4001316 sub */
    /* @4001320 call */
    GM_SITE(vm, 184, 4001320);
    /* @4001328 store */
    v73 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v73);
    /* @4001336 load */
    /* @4001344 cast */
    /* @4001348 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4001380;
    L_4001352: ;
    /* @4001352 constant */
    /* @4001356 cast */
    /* @4001360 load */
    /* @4001368 call */
    GM_SITE(vm, 184, 4001368);
    /* @4001376 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4001380: ;
    /* @4001380 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001352;
    /* @4001384 constant */
    /* @4001388 cast */
    /* @4001392 load */
    /* @4001400 constant */
    /* @4001404 sub */
    /* @4001408 load */
    /* @4001416 constant */
    /* @4001420 add */
    /* @4001424 call */
    GM_SITE(vm, 184, 4001424);
    v74 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4001432 store */
    v75 = GM_CALL(vm, "instance_create", 3, v74, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v75);
    /* @4001440 load */
    /* @4001448 cast */
    /* @4001452 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4001484;
    L_4001456: ;
    /* @4001456 constant */
    /* @4001460 cast */
    /* @4001464 load */
    /* @4001472 call */
    GM_SITE(vm, 184, 4001472);
    /* @4001480 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4001484: ;
    /* @4001484 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001456;
    /* @4001488 constant */
    /* @4001492 cast */
    /* @4001496 load */
    /* @4001504 constant */
    /* @4001508 sub */
    /* @4001512 load */
    /* @4001520 constant */
    /* @4001524 sub */
    /* @4001528 call */
    GM_SITE(vm, 184, 4001528);
    /* @4001536 store */
    v76 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v76);
    /* @4001544 load */
    /* @4001552 cast */
    /* @4001556 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4001588;
    L_4001560: ;
    /* @4001560 constant */
    /* @4001564 cast */
    /* @4001568 load */
    /* @4001576 call */
    GM_SITE(vm, 184, 4001576);
    /* @4001584 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4001588: ;
    /* @4001588 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001560;
    /* @4001592 constant */
    /* @4001596 cast */
    /* @4001600 load */
    /* @4001608 constant */
    /* @4001612 sub */
    /* @4001616 load */
    /* @4001624 constant */
    /* @4001628 add */
    /* @4001632 call */
    GM_SITE(vm, 184, 4001632);
    v77 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4001640 store */
    v78 = GM_CALL(vm, "instance_create", 3, v77, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v78);
    /* @4001648 load */
    /* @4001656 cast */
    /* @4001660 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4001692;
    L_4001664: ;
    /* @4001664 constant */
    /* @4001668 cast */
    /* @4001672 load */
    /* @4001680 call */
    GM_SITE(vm, 184, 4001680);
    /* @4001688 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4001692: ;
    /* @4001692 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001664;
    /* @4001696 constant */
    /* @4001700 cast */
    /* @4001704 load */
    /* @4001712 constant */
    /* @4001716 sub */
    /* @4001720 load */
    /* @4001728 constant */
    /* @4001732 sub */
    /* @4001736 call */
    GM_SITE(vm, 184, 4001736);
    /* @4001744 store */
    v79 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v79);
    /* @4001752 load */
    /* @4001760 cast */
    /* @4001764 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4001796;
    L_4001768: ;
    /* @4001768 constant */
    /* @4001772 cast */
    /* @4001776 load */
    /* @4001784 call */
    GM_SITE(vm, 184, 4001784);
    /* @4001792 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4001796: ;
    /* @4001796 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001768;
    /* @4001800 constant */
    /* @4001804 cast */
    /* @4001808 load */
    /* @4001816 constant */
    /* @4001820 sub */
    /* @4001824 load */
    /* @4001832 constant */
    /* @4001836 sub */
    /* @4001840 call */
    GM_SITE(vm, 184, 4001840);
    /* @4001848 store */
    v80 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v80);
    /* @4001856 load */
    /* @4001864 cast */
    /* @4001868 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4001900;
    L_4001872: ;
    /* @4001872 constant */
    /* @4001876 cast */
    /* @4001880 load */
    /* @4001888 call */
    GM_SITE(vm, 184, 4001888);
    /* @4001896 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4001900: ;
    /* @4001900 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001872;
    /* @4001904 constant */
    /* @4001908 cast */
    /* @4001912 load */
    /* @4001920 constant */
    /* @4001924 sub */
    /* @4001928 load */
    /* @4001936 constant */
    /* @4001940 add */
    /* @4001944 call */
    GM_SITE(vm, 184, 4001944);
    v81 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4001952 store */
    v82 = GM_CALL(vm, "instance_create", 3, v81, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v82);
    /* @4001960 load */
    /* @4001968 cast */
    /* @4001972 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4002004;
    L_4001976: ;
    /* @4001976 constant */
    /* @4001980 cast */
    /* @4001984 load */
    /* @4001992 call */
    GM_SITE(vm, 184, 4001992);
    /* @4002000 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4002004: ;
    /* @4002004 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4001976;
    /* @4002008 constant */
    /* @4002012 cast */
    /* @4002016 load */
    /* @4002024 constant */
    /* @4002028 sub */
    /* @4002032 load */
    /* @4002040 constant */
    /* @4002044 sub */
    /* @4002048 call */
    GM_SITE(vm, 184, 4002048);
    /* @4002056 store */
    v83 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v83);
    /* @4002064 load */
    /* @4002072 cast */
    /* @4002076 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4002108;
    L_4002080: ;
    /* @4002080 constant */
    /* @4002084 cast */
    /* @4002088 load */
    /* @4002096 call */
    GM_SITE(vm, 184, 4002096);
    /* @4002104 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4002108: ;
    /* @4002108 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002080;
    /* @4002112 constant */
    /* @4002116 cast */
    /* @4002120 load */
    /* @4002128 constant */
    /* @4002132 sub */
    /* @4002136 load */
    /* @4002144 constant */
    /* @4002148 add */
    /* @4002152 call */
    GM_SITE(vm, 184, 4002152);
    v84 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4002160 store */
    v85 = GM_CALL(vm, "instance_create", 3, v84, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v85);
    /* @4002168 load */
    /* @4002176 cast */
    /* @4002180 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4002212;
    L_4002184: ;
    /* @4002184 constant */
    /* @4002188 cast */
    /* @4002192 load */
    /* @4002200 call */
    GM_SITE(vm, 184, 4002200);
    /* @4002208 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4002212: ;
    /* @4002212 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002184;
    /* @4002216 constant */
    /* @4002220 cast */
    /* @4002224 load */
    /* @4002232 constant */
    /* @4002236 sub */
    /* @4002240 load */
    /* @4002248 constant */
    /* @4002252 sub */
    /* @4002256 call */
    GM_SITE(vm, 184, 4002256);
    /* @4002264 store */
    v86 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v86);
    /* @4002272 load */
    /* @4002280 cast */
    /* @4002284 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4002316;
    L_4002288: ;
    /* @4002288 constant */
    /* @4002292 cast */
    /* @4002296 load */
    /* @4002304 call */
    GM_SITE(vm, 184, 4002304);
    /* @4002312 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4002316: ;
    /* @4002316 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002288;
    L_4002320: ;
    /* @4002320 load */
    /* @4002328 constant */
    /* @4002332 cmp */
    /* @4002336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_4004932;
    /* @4002340 constant */
    /* @4002344 cast */
    /* @4002348 load */
    /* @4002356 constant */
    /* @4002360 sub */
    /* @4002364 load */
    /* @4002372 call */
    GM_SITE(vm, 184, 4002372);
    /* @4002380 store */
    v87 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v87);
    /* @4002388 load */
    /* @4002396 cast */
    /* @4002400 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4002432;
    L_4002404: ;
    /* @4002404 constant */
    /* @4002408 cast */
    /* @4002412 load */
    /* @4002420 call */
    GM_SITE(vm, 184, 4002420);
    /* @4002428 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4002432: ;
    /* @4002432 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002404;
    /* @4002436 constant */
    /* @4002440 cast */
    /* @4002444 load */
    /* @4002452 constant */
    /* @4002456 sub */
    /* @4002460 load */
    /* @4002468 constant */
    /* @4002472 add */
    /* @4002476 call */
    GM_SITE(vm, 184, 4002476);
    v88 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4002484 store */
    v89 = GM_CALL(vm, "instance_create", 3, v88, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v89);
    /* @4002492 load */
    /* @4002500 cast */
    /* @4002504 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4002536;
    L_4002508: ;
    /* @4002508 constant */
    /* @4002512 cast */
    /* @4002516 load */
    /* @4002524 call */
    GM_SITE(vm, 184, 4002524);
    /* @4002532 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4002536: ;
    /* @4002536 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002508;
    /* @4002540 constant */
    /* @4002544 cast */
    /* @4002548 load */
    /* @4002556 constant */
    /* @4002560 sub */
    /* @4002564 load */
    /* @4002572 constant */
    /* @4002576 sub */
    /* @4002580 call */
    GM_SITE(vm, 184, 4002580);
    /* @4002588 store */
    v90 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v90);
    /* @4002596 load */
    /* @4002604 cast */
    /* @4002608 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4002640;
    L_4002612: ;
    /* @4002612 constant */
    /* @4002616 cast */
    /* @4002620 load */
    /* @4002628 call */
    GM_SITE(vm, 184, 4002628);
    /* @4002636 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4002640: ;
    /* @4002640 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002612;
    /* @4002644 constant */
    /* @4002648 cast */
    /* @4002652 load */
    /* @4002660 constant */
    /* @4002664 sub */
    /* @4002668 load */
    /* @4002676 constant */
    /* @4002680 add */
    /* @4002684 call */
    GM_SITE(vm, 184, 4002684);
    v91 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4002692 store */
    v92 = GM_CALL(vm, "instance_create", 3, v91, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v92);
    /* @4002700 load */
    /* @4002708 cast */
    /* @4002712 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4002744;
    L_4002716: ;
    /* @4002716 constant */
    /* @4002720 cast */
    /* @4002724 load */
    /* @4002732 call */
    GM_SITE(vm, 184, 4002732);
    /* @4002740 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4002744: ;
    /* @4002744 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002716;
    /* @4002748 constant */
    /* @4002752 cast */
    /* @4002756 load */
    /* @4002764 constant */
    /* @4002768 sub */
    /* @4002772 load */
    /* @4002780 constant */
    /* @4002784 sub */
    /* @4002788 call */
    GM_SITE(vm, 184, 4002788);
    /* @4002796 store */
    v93 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v93);
    /* @4002804 load */
    /* @4002812 cast */
    /* @4002816 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4002848;
    L_4002820: ;
    /* @4002820 constant */
    /* @4002824 cast */
    /* @4002828 load */
    /* @4002836 call */
    GM_SITE(vm, 184, 4002836);
    /* @4002844 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4002848: ;
    /* @4002848 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002820;
    /* @4002852 constant */
    /* @4002856 cast */
    /* @4002860 load */
    /* @4002868 constant */
    /* @4002872 sub */
    /* @4002876 load */
    /* @4002884 constant */
    /* @4002888 add */
    /* @4002892 call */
    GM_SITE(vm, 184, 4002892);
    v94 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4002900 store */
    v95 = GM_CALL(vm, "instance_create", 3, v94, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v95);
    /* @4002908 load */
    /* @4002916 cast */
    /* @4002920 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4002952;
    L_4002924: ;
    /* @4002924 constant */
    /* @4002928 cast */
    /* @4002932 load */
    /* @4002940 call */
    GM_SITE(vm, 184, 4002940);
    /* @4002948 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4002952: ;
    /* @4002952 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4002924;
    /* @4002956 constant */
    /* @4002960 cast */
    /* @4002964 load */
    /* @4002972 constant */
    /* @4002976 sub */
    /* @4002980 load */
    /* @4002988 constant */
    /* @4002992 add */
    /* @4002996 call */
    GM_SITE(vm, 184, 4002996);
    v96 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4003004 store */
    v97 = GM_CALL(vm, "instance_create", 3, v96, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v97);
    /* @4003012 load */
    /* @4003020 cast */
    /* @4003024 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4003056;
    L_4003028: ;
    /* @4003028 constant */
    /* @4003032 cast */
    /* @4003036 load */
    /* @4003044 call */
    GM_SITE(vm, 184, 4003044);
    /* @4003052 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4003056: ;
    /* @4003056 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003028;
    /* @4003060 constant */
    /* @4003064 cast */
    /* @4003068 load */
    /* @4003076 constant */
    /* @4003080 sub */
    /* @4003084 load */
    /* @4003092 constant */
    /* @4003096 sub */
    /* @4003100 call */
    GM_SITE(vm, 184, 4003100);
    /* @4003108 store */
    v98 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v98);
    /* @4003116 load */
    /* @4003124 cast */
    /* @4003128 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4003160;
    L_4003132: ;
    /* @4003132 constant */
    /* @4003136 cast */
    /* @4003140 load */
    /* @4003148 call */
    GM_SITE(vm, 184, 4003148);
    /* @4003156 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4003160: ;
    /* @4003160 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003132;
    /* @4003164 constant */
    /* @4003168 cast */
    /* @4003172 load */
    /* @4003180 constant */
    /* @4003184 sub */
    /* @4003188 load */
    /* @4003196 constant */
    /* @4003200 add */
    /* @4003204 call */
    GM_SITE(vm, 184, 4003204);
    v99 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4003212 store */
    v100 = GM_CALL(vm, "instance_create", 3, v99, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v100);
    /* @4003220 load */
    /* @4003228 cast */
    /* @4003232 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4003264;
    L_4003236: ;
    /* @4003236 constant */
    /* @4003240 cast */
    /* @4003244 load */
    /* @4003252 call */
    GM_SITE(vm, 184, 4003252);
    /* @4003260 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4003264: ;
    /* @4003264 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003236;
    /* @4003268 constant */
    /* @4003272 cast */
    /* @4003276 load */
    /* @4003284 constant */
    /* @4003288 sub */
    /* @4003292 load */
    /* @4003300 constant */
    /* @4003304 sub */
    /* @4003308 call */
    GM_SITE(vm, 184, 4003308);
    /* @4003316 store */
    v101 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v101);
    /* @4003324 load */
    /* @4003332 cast */
    /* @4003336 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_4003368;
    L_4003340: ;
    /* @4003340 constant */
    /* @4003344 cast */
    /* @4003348 load */
    /* @4003356 call */
    GM_SITE(vm, 184, 4003356);
    /* @4003364 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4003368: ;
    /* @4003368 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003340;
    /* @4003372 constant */
    /* @4003376 cast */
    /* @4003380 load */
    /* @4003388 constant */
    /* @4003392 sub */
    /* @4003396 load */
    /* @4003404 constant */
    /* @4003408 sub */
    /* @4003412 call */
    GM_SITE(vm, 184, 4003412);
    /* @4003420 store */
    v102 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v102);
    /* @4003428 load */
    /* @4003436 cast */
    /* @4003440 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_4003472;
    L_4003444: ;
    /* @4003444 constant */
    /* @4003448 cast */
    /* @4003452 load */
    /* @4003460 call */
    GM_SITE(vm, 184, 4003460);
    /* @4003468 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4003472: ;
    /* @4003472 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003444;
    /* @4003476 constant */
    /* @4003480 cast */
    /* @4003484 load */
    /* @4003492 constant */
    /* @4003496 sub */
    /* @4003500 load */
    /* @4003508 constant */
    /* @4003512 add */
    /* @4003516 call */
    GM_SITE(vm, 184, 4003516);
    v103 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @4003524 store */
    v104 = GM_CALL(vm, "instance_create", 3, v103, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v104);
    /* @4003532 load */
    /* @4003540 cast */
    /* @4003544 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_4003576;
    L_4003548: ;
    /* @4003548 constant */
    /* @4003552 cast */
    /* @4003556 load */
    /* @4003564 call */
    GM_SITE(vm, 184, 4003564);
    /* @4003572 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_4003576: ;
    /* @4003576 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003548;
    /* @4003580 constant */
    /* @4003584 cast */
    /* @4003588 load */
    /* @4003596 constant */
    /* @4003600 sub */
    /* @4003604 load */
    /* @4003612 constant */
    /* @4003616 sub */
    /* @4003620 call */
    GM_SITE(vm, 184, 4003620);
    /* @4003628 store */
    v105 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID13", v105);
    /* @4003636 load */
    /* @4003644 cast */
    /* @4003648 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID13")))) goto L_4003680;
    L_4003652: ;
    /* @4003652 constant */
    /* @4003656 cast */
    /* @4003660 load */
    /* @4003668 call */
    GM_SITE(vm, 184, 4003668);
    /* @4003676 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread13"), VAL(5)));
    L_4003680: ;
    /* @4003680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003652;
    /* @4003684 constant */
    /* @4003688 cast */
    /* @4003692 load */
    /* @4003700 constant */
    /* @4003704 sub */
    /* @4003708 load */
    /* @4003716 constant */
    /* @4003720 add */
    /* @4003724 call */
    GM_SITE(vm, 184, 4003724);
    v106 = GM_ADD(GM_READ(vm, -1, "x"), VAL(12));
    /* @4003732 store */
    v107 = GM_CALL(vm, "instance_create", 3, v106, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID14", v107);
    /* @4003740 load */
    /* @4003748 cast */
    /* @4003752 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID14")))) goto L_4003784;
    L_4003756: ;
    /* @4003756 constant */
    /* @4003760 cast */
    /* @4003764 load */
    /* @4003772 call */
    GM_SITE(vm, 184, 4003772);
    /* @4003780 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread14"), VAL(5)));
    L_4003784: ;
    /* @4003784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003756;
    /* @4003788 constant */
    /* @4003792 cast */
    /* @4003796 load */
    /* @4003804 constant */
    /* @4003808 sub */
    /* @4003812 load */
    /* @4003820 constant */
    /* @4003824 sub */
    /* @4003828 call */
    GM_SITE(vm, 184, 4003828);
    /* @4003836 store */
    v108 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(12)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID15", v108);
    /* @4003844 load */
    /* @4003852 cast */
    /* @4003856 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID15")))) goto L_4003888;
    L_4003860: ;
    /* @4003860 constant */
    /* @4003864 cast */
    /* @4003868 load */
    /* @4003876 call */
    GM_SITE(vm, 184, 4003876);
    /* @4003884 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread15"), VAL(5)));
    L_4003888: ;
    /* @4003888 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003860;
    /* @4003892 constant */
    /* @4003896 cast */
    /* @4003900 load */
    /* @4003908 constant */
    /* @4003912 sub */
    /* @4003916 load */
    /* @4003924 constant */
    /* @4003928 add */
    /* @4003932 call */
    GM_SITE(vm, 184, 4003932);
    v109 = GM_ADD(GM_READ(vm, -1, "x"), VAL(15));
    /* @4003940 store */
    v110 = GM_CALL(vm, "instance_create", 3, v109, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID16", v110);
    /* @4003948 load */
    /* @4003956 cast */
    /* @4003960 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID16")))) goto L_4003992;
    L_4003964: ;
    /* @4003964 constant */
    /* @4003968 cast */
    /* @4003972 load */
    /* @4003980 call */
    GM_SITE(vm, 184, 4003980);
    /* @4003988 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread16"), VAL(5)));
    L_4003992: ;
    /* @4003992 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4003964;
    /* @4003996 constant */
    /* @4004000 cast */
    /* @4004004 load */
    /* @4004012 constant */
    /* @4004016 sub */
    /* @4004020 load */
    /* @4004028 constant */
    /* @4004032 add */
    /* @4004036 call */
    GM_SITE(vm, 184, 4004036);
    v111 = GM_ADD(GM_READ(vm, -1, "x"), VAL(14));
    /* @4004044 store */
    v112 = GM_CALL(vm, "instance_create", 3, v111, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID17", v112);
    /* @4004052 load */
    /* @4004060 cast */
    /* @4004064 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID17")))) goto L_4004096;
    L_4004068: ;
    /* @4004068 constant */
    /* @4004072 cast */
    /* @4004076 load */
    /* @4004084 call */
    GM_SITE(vm, 184, 4004084);
    /* @4004092 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread17"), VAL(5)));
    L_4004096: ;
    /* @4004096 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004068;
    /* @4004100 constant */
    /* @4004104 cast */
    /* @4004108 load */
    /* @4004116 constant */
    /* @4004120 sub */
    /* @4004124 load */
    /* @4004132 constant */
    /* @4004136 sub */
    /* @4004140 call */
    GM_SITE(vm, 184, 4004140);
    /* @4004148 store */
    v113 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(14)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID18", v113);
    /* @4004156 load */
    /* @4004164 cast */
    /* @4004168 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID18")))) goto L_4004200;
    L_4004172: ;
    /* @4004172 constant */
    /* @4004176 cast */
    /* @4004180 load */
    /* @4004188 call */
    GM_SITE(vm, 184, 4004188);
    /* @4004196 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread18"), VAL(5)));
    L_4004200: ;
    /* @4004200 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004172;
    /* @4004204 constant */
    /* @4004208 cast */
    /* @4004212 load */
    /* @4004220 constant */
    /* @4004224 sub */
    /* @4004228 load */
    /* @4004236 constant */
    /* @4004240 add */
    /* @4004244 call */
    GM_SITE(vm, 184, 4004244);
    v114 = GM_ADD(GM_READ(vm, -1, "x"), VAL(16));
    /* @4004252 store */
    v115 = GM_CALL(vm, "instance_create", 3, v114, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID19", v115);
    /* @4004260 load */
    /* @4004268 cast */
    /* @4004272 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID19")))) goto L_4004304;
    L_4004276: ;
    /* @4004276 constant */
    /* @4004280 cast */
    /* @4004284 load */
    /* @4004292 call */
    GM_SITE(vm, 184, 4004292);
    /* @4004300 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread19"), VAL(5)));
    L_4004304: ;
    /* @4004304 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004276;
    /* @4004308 constant */
    /* @4004312 cast */
    /* @4004316 load */
    /* @4004324 constant */
    /* @4004328 sub */
    /* @4004332 load */
    /* @4004340 constant */
    /* @4004344 sub */
    /* @4004348 call */
    GM_SITE(vm, 184, 4004348);
    /* @4004356 store */
    v116 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(16)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID20", v116);
    /* @4004364 load */
    /* @4004372 cast */
    /* @4004376 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID20")))) goto L_4004408;
    L_4004380: ;
    /* @4004380 constant */
    /* @4004384 cast */
    /* @4004388 load */
    /* @4004396 call */
    GM_SITE(vm, 184, 4004396);
    /* @4004404 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread20"), VAL(5)));
    L_4004408: ;
    /* @4004408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004380;
    /* @4004412 constant */
    /* @4004416 cast */
    /* @4004420 load */
    /* @4004428 constant */
    /* @4004432 sub */
    /* @4004436 load */
    /* @4004444 constant */
    /* @4004448 sub */
    /* @4004452 call */
    GM_SITE(vm, 184, 4004452);
    /* @4004460 store */
    v117 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(15)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID21", v117);
    /* @4004468 load */
    /* @4004476 cast */
    /* @4004480 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID21")))) goto L_4004512;
    L_4004484: ;
    /* @4004484 constant */
    /* @4004488 cast */
    /* @4004492 load */
    /* @4004500 call */
    GM_SITE(vm, 184, 4004500);
    /* @4004508 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread21"), VAL(5)));
    L_4004512: ;
    /* @4004512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004484;
    /* @4004516 constant */
    /* @4004520 cast */
    /* @4004524 load */
    /* @4004532 constant */
    /* @4004536 sub */
    /* @4004540 load */
    /* @4004548 constant */
    /* @4004552 add */
    /* @4004556 call */
    GM_SITE(vm, 184, 4004556);
    v118 = GM_ADD(GM_READ(vm, -1, "x"), VAL(18));
    /* @4004564 store */
    v119 = GM_CALL(vm, "instance_create", 3, v118, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID22", v119);
    /* @4004572 load */
    /* @4004580 cast */
    /* @4004584 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID22")))) goto L_4004616;
    L_4004588: ;
    /* @4004588 constant */
    /* @4004592 cast */
    /* @4004596 load */
    /* @4004604 call */
    GM_SITE(vm, 184, 4004604);
    /* @4004612 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread22"), VAL(5)));
    L_4004616: ;
    /* @4004616 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004588;
    /* @4004620 constant */
    /* @4004624 cast */
    /* @4004628 load */
    /* @4004636 constant */
    /* @4004640 sub */
    /* @4004644 load */
    /* @4004652 constant */
    /* @4004656 sub */
    /* @4004660 call */
    GM_SITE(vm, 184, 4004660);
    /* @4004668 store */
    v120 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID23", v120);
    /* @4004676 load */
    /* @4004684 cast */
    /* @4004688 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID23")))) goto L_4004720;
    L_4004692: ;
    /* @4004692 constant */
    /* @4004696 cast */
    /* @4004700 load */
    /* @4004708 call */
    GM_SITE(vm, 184, 4004708);
    /* @4004716 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(5)));
    L_4004720: ;
    /* @4004720 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004692;
    /* @4004724 constant */
    /* @4004728 cast */
    /* @4004732 load */
    /* @4004740 constant */
    /* @4004744 sub */
    /* @4004748 load */
    /* @4004756 constant */
    /* @4004760 add */
    /* @4004764 call */
    GM_SITE(vm, 184, 4004764);
    v121 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4004772 store */
    v122 = GM_CALL(vm, "instance_create", 3, v121, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID24", v122);
    /* @4004780 load */
    /* @4004788 cast */
    /* @4004792 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID24")))) goto L_4004824;
    L_4004796: ;
    /* @4004796 constant */
    /* @4004800 cast */
    /* @4004804 load */
    /* @4004812 call */
    GM_SITE(vm, 184, 4004812);
    /* @4004820 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread24"), VAL(5)));
    L_4004824: ;
    /* @4004824 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004796;
    /* @4004828 constant */
    /* @4004832 cast */
    /* @4004836 load */
    /* @4004844 constant */
    /* @4004848 sub */
    /* @4004852 load */
    /* @4004860 constant */
    /* @4004864 sub */
    /* @4004868 call */
    GM_SITE(vm, 184, 4004868);
    /* @4004876 store */
    v123 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID25", v123);
    /* @4004884 load */
    /* @4004892 cast */
    /* @4004896 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID25")))) goto L_4004928;
    L_4004900: ;
    /* @4004900 constant */
    /* @4004904 cast */
    /* @4004908 load */
    /* @4004916 call */
    GM_SITE(vm, 184, 4004916);
    /* @4004924 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(5)));
    L_4004928: ;
    /* @4004928 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4004900;
    L_4004932: ;
    /* @4004932 call */
    GM_SITE(vm, 184, 4004932);
    /* @4004940 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_4004944: ;
    return;
}
