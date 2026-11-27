/* generated from CODE 88 (gml_Object_obj_firehulk_Alarm_0), source start 3919660, end 3924484. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0088(GmVM* vm) {
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
    /* @3919660 load */
    /* @3919668 constant */
    /* @3919672 cmp */
    /* @3919676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3919684;
    /* @3919680 b */
    goto L_3919740;
    L_3919684: ;
    /* @3919684 load */
    /* @3919692 constant */
    /* @3919696 cmp */
    /* @3919700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3919740;
    /* @3919704 constant */
    /* @3919708 cast */
    /* @3919712 constant */
    /* @3919716 cast */
    /* @3919720 constant */
    /* @3919724 cast */
    /* @3919728 call */
    GM_SITE(vm, 88, 3919728);
    /* @3919736 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3919740: ;
    /* @3919740 load */
    /* @3919748 constant */
    /* @3919752 cmp */
    /* @3919756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3919804;
    /* @3919760 constant */
    /* @3919764 cast */
    /* @3919768 load */
    /* @3919776 constant */
    /* @3919780 sub */
    /* @3919784 load */
    /* @3919792 call */
    GM_SITE(vm, 88, 3919792);
    /* @3919800 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3919804: ;
    /* @3919804 load */
    /* @3919812 constant */
    /* @3919816 cmp */
    /* @3919820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3919868;
    /* @3919824 constant */
    /* @3919828 cast */
    /* @3919832 load */
    /* @3919840 constant */
    /* @3919844 sub */
    /* @3919848 load */
    /* @3919856 call */
    GM_SITE(vm, 88, 3919856);
    /* @3919864 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3919868: ;
    /* @3919868 load */
    /* @3919876 constant */
    /* @3919880 cmp */
    /* @3919884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3919984;
    /* @3919888 constant */
    /* @3919892 cast */
    /* @3919896 load */
    /* @3919904 constant */
    /* @3919908 sub */
    /* @3919912 load */
    /* @3919920 call */
    GM_SITE(vm, 88, 3919920);
    /* @3919928 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3919936 load */
    /* @3919944 cast */
    /* @3919948 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3919980;
    L_3919952: ;
    /* @3919952 constant */
    /* @3919956 cast */
    /* @3919960 load */
    /* @3919968 call */
    GM_SITE(vm, 88, 3919968);
    /* @3919976 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3919980: ;
    /* @3919980 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3919952;
    L_3919984: ;
    /* @3919984 constant */
    /* @3919988 cast */
    /* @3919992 call */
    GM_SITE(vm, 88, 3919992);
    /* @3920000 constant */
    /* @3920004 cmp */
    /* @3920008 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3920016;
    /* @3920012 b */
    goto L_3924472;
    L_3920016: ;
    /* @3920016 constant */
    /* @3920020 cast */
    /* @3920024 call */
    GM_SITE(vm, 88, 3920024);
    /* @3920032 constant */
    /* @3920036 cmp */
    /* @3920040 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3924472;
    /* @3920044 load */
    /* @3920052 constant */
    /* @3920056 cmp */
    /* @3920060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3920576;
    /* @3920064 constant */
    /* @3920068 cast */
    /* @3920072 load */
    /* @3920080 constant */
    /* @3920084 sub */
    /* @3920088 load */
    /* @3920096 call */
    GM_SITE(vm, 88, 3920096);
    /* @3920104 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3920112 load */
    /* @3920120 cast */
    /* @3920124 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3920156;
    L_3920128: ;
    /* @3920128 constant */
    /* @3920132 cast */
    /* @3920136 load */
    /* @3920144 call */
    GM_SITE(vm, 88, 3920144);
    /* @3920152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3920156: ;
    /* @3920156 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920128;
    /* @3920160 constant */
    /* @3920164 cast */
    /* @3920168 load */
    /* @3920176 constant */
    /* @3920180 sub */
    /* @3920184 load */
    /* @3920192 constant */
    /* @3920196 add */
    /* @3920200 call */
    GM_SITE(vm, 88, 3920200);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3920208 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3920216 load */
    /* @3920224 cast */
    /* @3920228 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3920260;
    L_3920232: ;
    /* @3920232 constant */
    /* @3920236 cast */
    /* @3920240 load */
    /* @3920248 call */
    GM_SITE(vm, 88, 3920248);
    /* @3920256 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3920260: ;
    /* @3920260 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920232;
    /* @3920264 constant */
    /* @3920268 cast */
    /* @3920272 load */
    /* @3920280 constant */
    /* @3920284 sub */
    /* @3920288 load */
    /* @3920296 constant */
    /* @3920300 sub */
    /* @3920304 call */
    GM_SITE(vm, 88, 3920304);
    /* @3920312 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3920320 load */
    /* @3920328 cast */
    /* @3920332 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3920364;
    L_3920336: ;
    /* @3920336 constant */
    /* @3920340 cast */
    /* @3920344 load */
    /* @3920352 call */
    GM_SITE(vm, 88, 3920352);
    /* @3920360 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3920364: ;
    /* @3920364 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920336;
    /* @3920368 constant */
    /* @3920372 cast */
    /* @3920376 load */
    /* @3920384 constant */
    /* @3920388 sub */
    /* @3920392 load */
    /* @3920400 constant */
    /* @3920404 add */
    /* @3920408 call */
    GM_SITE(vm, 88, 3920408);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3920416 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v9);
    /* @3920424 load */
    /* @3920432 cast */
    /* @3920436 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3920468;
    L_3920440: ;
    /* @3920440 constant */
    /* @3920444 cast */
    /* @3920448 load */
    /* @3920456 call */
    GM_SITE(vm, 88, 3920456);
    /* @3920464 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3920468: ;
    /* @3920468 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920440;
    /* @3920472 constant */
    /* @3920476 cast */
    /* @3920480 load */
    /* @3920488 constant */
    /* @3920492 sub */
    /* @3920496 load */
    /* @3920504 constant */
    /* @3920508 sub */
    /* @3920512 call */
    GM_SITE(vm, 88, 3920512);
    /* @3920520 store */
    v10 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v10);
    /* @3920528 load */
    /* @3920536 cast */
    /* @3920540 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3920572;
    L_3920544: ;
    /* @3920544 constant */
    /* @3920548 cast */
    /* @3920552 load */
    /* @3920560 call */
    GM_SITE(vm, 88, 3920560);
    /* @3920568 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3920572: ;
    /* @3920572 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920544;
    L_3920576: ;
    /* @3920576 load */
    /* @3920584 constant */
    /* @3920588 cmp */
    /* @3920592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3921316;
    /* @3920596 constant */
    /* @3920600 cast */
    /* @3920604 load */
    /* @3920612 constant */
    /* @3920616 sub */
    /* @3920620 load */
    /* @3920628 call */
    GM_SITE(vm, 88, 3920628);
    /* @3920636 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v11);
    /* @3920644 load */
    /* @3920652 cast */
    /* @3920656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3920688;
    L_3920660: ;
    /* @3920660 constant */
    /* @3920664 cast */
    /* @3920668 load */
    /* @3920676 call */
    GM_SITE(vm, 88, 3920676);
    /* @3920684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3920688: ;
    /* @3920688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920660;
    /* @3920692 constant */
    /* @3920696 cast */
    /* @3920700 load */
    /* @3920708 constant */
    /* @3920712 sub */
    /* @3920716 load */
    /* @3920724 constant */
    /* @3920728 add */
    /* @3920732 call */
    GM_SITE(vm, 88, 3920732);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3920740 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v13);
    /* @3920748 load */
    /* @3920756 cast */
    /* @3920760 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3920792;
    L_3920764: ;
    /* @3920764 constant */
    /* @3920768 cast */
    /* @3920772 load */
    /* @3920780 call */
    GM_SITE(vm, 88, 3920780);
    /* @3920788 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3920792: ;
    /* @3920792 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920764;
    /* @3920796 constant */
    /* @3920800 cast */
    /* @3920804 load */
    /* @3920812 constant */
    /* @3920816 sub */
    /* @3920820 load */
    /* @3920828 constant */
    /* @3920832 sub */
    /* @3920836 call */
    GM_SITE(vm, 88, 3920836);
    /* @3920844 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v14);
    /* @3920852 load */
    /* @3920860 cast */
    /* @3920864 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3920896;
    L_3920868: ;
    /* @3920868 constant */
    /* @3920872 cast */
    /* @3920876 load */
    /* @3920884 call */
    GM_SITE(vm, 88, 3920884);
    /* @3920892 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3920896: ;
    /* @3920896 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920868;
    /* @3920900 constant */
    /* @3920904 cast */
    /* @3920908 load */
    /* @3920916 constant */
    /* @3920920 sub */
    /* @3920924 load */
    /* @3920932 constant */
    /* @3920936 add */
    /* @3920940 call */
    GM_SITE(vm, 88, 3920940);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3920948 store */
    v16 = GM_CALL(vm, "instance_create", 3, v15, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v16);
    /* @3920956 load */
    /* @3920964 cast */
    /* @3920968 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3921000;
    L_3920972: ;
    /* @3920972 constant */
    /* @3920976 cast */
    /* @3920980 load */
    /* @3920988 call */
    GM_SITE(vm, 88, 3920988);
    /* @3920996 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3921000: ;
    /* @3921000 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3920972;
    /* @3921004 constant */
    /* @3921008 cast */
    /* @3921012 load */
    /* @3921020 constant */
    /* @3921024 sub */
    /* @3921028 load */
    /* @3921036 constant */
    /* @3921040 sub */
    /* @3921044 call */
    GM_SITE(vm, 88, 3921044);
    /* @3921052 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v17);
    /* @3921060 load */
    /* @3921068 cast */
    /* @3921072 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3921104;
    L_3921076: ;
    /* @3921076 constant */
    /* @3921080 cast */
    /* @3921084 load */
    /* @3921092 call */
    GM_SITE(vm, 88, 3921092);
    /* @3921100 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3921104: ;
    /* @3921104 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921076;
    /* @3921108 constant */
    /* @3921112 cast */
    /* @3921116 load */
    /* @3921124 constant */
    /* @3921128 sub */
    /* @3921132 load */
    /* @3921140 constant */
    /* @3921144 sub */
    /* @3921148 call */
    GM_SITE(vm, 88, 3921148);
    /* @3921156 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v18);
    /* @3921164 load */
    /* @3921172 cast */
    /* @3921176 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3921208;
    L_3921180: ;
    /* @3921180 constant */
    /* @3921184 cast */
    /* @3921188 load */
    /* @3921196 call */
    GM_SITE(vm, 88, 3921196);
    /* @3921204 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3921208: ;
    /* @3921208 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921180;
    /* @3921212 constant */
    /* @3921216 cast */
    /* @3921220 load */
    /* @3921228 constant */
    /* @3921232 sub */
    /* @3921236 load */
    /* @3921244 constant */
    /* @3921248 add */
    /* @3921252 call */
    GM_SITE(vm, 88, 3921252);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3921260 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v20);
    /* @3921268 load */
    /* @3921276 cast */
    /* @3921280 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3921312;
    L_3921284: ;
    /* @3921284 constant */
    /* @3921288 cast */
    /* @3921292 load */
    /* @3921300 call */
    GM_SITE(vm, 88, 3921300);
    /* @3921308 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3921312: ;
    /* @3921312 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921284;
    L_3921316: ;
    /* @3921316 load */
    /* @3921324 constant */
    /* @3921328 cmp */
    /* @3921332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3922264;
    /* @3921336 constant */
    /* @3921340 cast */
    /* @3921344 load */
    /* @3921352 constant */
    /* @3921356 sub */
    /* @3921360 load */
    /* @3921368 call */
    GM_SITE(vm, 88, 3921368);
    /* @3921376 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v21);
    /* @3921384 load */
    /* @3921392 cast */
    /* @3921396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3921428;
    L_3921400: ;
    /* @3921400 constant */
    /* @3921404 cast */
    /* @3921408 load */
    /* @3921416 call */
    GM_SITE(vm, 88, 3921416);
    /* @3921424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3921428: ;
    /* @3921428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921400;
    /* @3921432 constant */
    /* @3921436 cast */
    /* @3921440 load */
    /* @3921448 constant */
    /* @3921452 sub */
    /* @3921456 load */
    /* @3921464 constant */
    /* @3921468 add */
    /* @3921472 call */
    GM_SITE(vm, 88, 3921472);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3921480 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v23);
    /* @3921488 load */
    /* @3921496 cast */
    /* @3921500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3921532;
    L_3921504: ;
    /* @3921504 constant */
    /* @3921508 cast */
    /* @3921512 load */
    /* @3921520 call */
    GM_SITE(vm, 88, 3921520);
    /* @3921528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3921532: ;
    /* @3921532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921504;
    /* @3921536 constant */
    /* @3921540 cast */
    /* @3921544 load */
    /* @3921552 constant */
    /* @3921556 sub */
    /* @3921560 load */
    /* @3921568 constant */
    /* @3921572 sub */
    /* @3921576 call */
    GM_SITE(vm, 88, 3921576);
    /* @3921584 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v24);
    /* @3921592 load */
    /* @3921600 cast */
    /* @3921604 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3921636;
    L_3921608: ;
    /* @3921608 constant */
    /* @3921612 cast */
    /* @3921616 load */
    /* @3921624 call */
    GM_SITE(vm, 88, 3921624);
    /* @3921632 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3921636: ;
    /* @3921636 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921608;
    /* @3921640 constant */
    /* @3921644 cast */
    /* @3921648 load */
    /* @3921656 constant */
    /* @3921660 sub */
    /* @3921664 load */
    /* @3921672 constant */
    /* @3921676 add */
    /* @3921680 call */
    GM_SITE(vm, 88, 3921680);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3921688 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v26);
    /* @3921696 load */
    /* @3921704 cast */
    /* @3921708 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3921740;
    L_3921712: ;
    /* @3921712 constant */
    /* @3921716 cast */
    /* @3921720 load */
    /* @3921728 call */
    GM_SITE(vm, 88, 3921728);
    /* @3921736 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3921740: ;
    /* @3921740 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921712;
    /* @3921744 constant */
    /* @3921748 cast */
    /* @3921752 load */
    /* @3921760 constant */
    /* @3921764 sub */
    /* @3921768 load */
    /* @3921776 constant */
    /* @3921780 sub */
    /* @3921784 call */
    GM_SITE(vm, 88, 3921784);
    /* @3921792 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v27);
    /* @3921800 load */
    /* @3921808 cast */
    /* @3921812 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3921844;
    L_3921816: ;
    /* @3921816 constant */
    /* @3921820 cast */
    /* @3921824 load */
    /* @3921832 call */
    GM_SITE(vm, 88, 3921832);
    /* @3921840 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3921844: ;
    /* @3921844 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921816;
    /* @3921848 constant */
    /* @3921852 cast */
    /* @3921856 load */
    /* @3921864 constant */
    /* @3921868 sub */
    /* @3921872 load */
    /* @3921880 constant */
    /* @3921884 sub */
    /* @3921888 call */
    GM_SITE(vm, 88, 3921888);
    /* @3921896 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v28);
    /* @3921904 load */
    /* @3921912 cast */
    /* @3921916 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3921948;
    L_3921920: ;
    /* @3921920 constant */
    /* @3921924 cast */
    /* @3921928 load */
    /* @3921936 call */
    GM_SITE(vm, 88, 3921936);
    /* @3921944 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3921948: ;
    /* @3921948 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3921920;
    /* @3921952 constant */
    /* @3921956 cast */
    /* @3921960 load */
    /* @3921968 constant */
    /* @3921972 sub */
    /* @3921976 load */
    /* @3921984 constant */
    /* @3921988 add */
    /* @3921992 call */
    GM_SITE(vm, 88, 3921992);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3922000 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v30);
    /* @3922008 load */
    /* @3922016 cast */
    /* @3922020 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3922052;
    L_3922024: ;
    /* @3922024 constant */
    /* @3922028 cast */
    /* @3922032 load */
    /* @3922040 call */
    GM_SITE(vm, 88, 3922040);
    /* @3922048 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3922052: ;
    /* @3922052 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922024;
    /* @3922056 constant */
    /* @3922060 cast */
    /* @3922064 load */
    /* @3922072 constant */
    /* @3922076 sub */
    /* @3922080 load */
    /* @3922088 constant */
    /* @3922092 sub */
    /* @3922096 call */
    GM_SITE(vm, 88, 3922096);
    /* @3922104 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v31);
    /* @3922112 load */
    /* @3922120 cast */
    /* @3922124 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3922156;
    L_3922128: ;
    /* @3922128 constant */
    /* @3922132 cast */
    /* @3922136 load */
    /* @3922144 call */
    GM_SITE(vm, 88, 3922144);
    /* @3922152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3922156: ;
    /* @3922156 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922128;
    /* @3922160 constant */
    /* @3922164 cast */
    /* @3922168 load */
    /* @3922176 constant */
    /* @3922180 sub */
    /* @3922184 load */
    /* @3922192 constant */
    /* @3922196 add */
    /* @3922200 call */
    GM_SITE(vm, 88, 3922200);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3922208 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v33);
    /* @3922216 load */
    /* @3922224 cast */
    /* @3922228 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3922260;
    L_3922232: ;
    /* @3922232 constant */
    /* @3922236 cast */
    /* @3922240 load */
    /* @3922248 call */
    GM_SITE(vm, 88, 3922248);
    /* @3922256 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3922260: ;
    /* @3922260 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922232;
    L_3922264: ;
    /* @3922264 load */
    /* @3922272 constant */
    /* @3922276 cmp */
    /* @3922280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3923212;
    /* @3922284 constant */
    /* @3922288 cast */
    /* @3922292 load */
    /* @3922300 constant */
    /* @3922304 sub */
    /* @3922308 load */
    /* @3922316 call */
    GM_SITE(vm, 88, 3922316);
    /* @3922324 store */
    v34 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v34);
    /* @3922332 load */
    /* @3922340 cast */
    /* @3922344 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3922376;
    L_3922348: ;
    /* @3922348 constant */
    /* @3922352 cast */
    /* @3922356 load */
    /* @3922364 call */
    GM_SITE(vm, 88, 3922364);
    /* @3922372 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3922376: ;
    /* @3922376 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922348;
    /* @3922380 constant */
    /* @3922384 cast */
    /* @3922388 load */
    /* @3922396 constant */
    /* @3922400 sub */
    /* @3922404 load */
    /* @3922412 constant */
    /* @3922416 add */
    /* @3922420 call */
    GM_SITE(vm, 88, 3922420);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3922428 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v36);
    /* @3922436 load */
    /* @3922444 cast */
    /* @3922448 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3922480;
    L_3922452: ;
    /* @3922452 constant */
    /* @3922456 cast */
    /* @3922460 load */
    /* @3922468 call */
    GM_SITE(vm, 88, 3922468);
    /* @3922476 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3922480: ;
    /* @3922480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922452;
    /* @3922484 constant */
    /* @3922488 cast */
    /* @3922492 load */
    /* @3922500 constant */
    /* @3922504 sub */
    /* @3922508 load */
    /* @3922516 constant */
    /* @3922520 sub */
    /* @3922524 call */
    GM_SITE(vm, 88, 3922524);
    /* @3922532 store */
    v37 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v37);
    /* @3922540 load */
    /* @3922548 cast */
    /* @3922552 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3922584;
    L_3922556: ;
    /* @3922556 constant */
    /* @3922560 cast */
    /* @3922564 load */
    /* @3922572 call */
    GM_SITE(vm, 88, 3922572);
    /* @3922580 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3922584: ;
    /* @3922584 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922556;
    /* @3922588 constant */
    /* @3922592 cast */
    /* @3922596 load */
    /* @3922604 constant */
    /* @3922608 sub */
    /* @3922612 load */
    /* @3922620 constant */
    /* @3922624 add */
    /* @3922628 call */
    GM_SITE(vm, 88, 3922628);
    v38 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3922636 store */
    v39 = GM_CALL(vm, "instance_create", 3, v38, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v39);
    /* @3922644 load */
    /* @3922652 cast */
    /* @3922656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3922688;
    L_3922660: ;
    /* @3922660 constant */
    /* @3922664 cast */
    /* @3922668 load */
    /* @3922676 call */
    GM_SITE(vm, 88, 3922676);
    /* @3922684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3922688: ;
    /* @3922688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922660;
    /* @3922692 constant */
    /* @3922696 cast */
    /* @3922700 load */
    /* @3922708 constant */
    /* @3922712 sub */
    /* @3922716 load */
    /* @3922724 constant */
    /* @3922728 sub */
    /* @3922732 call */
    GM_SITE(vm, 88, 3922732);
    /* @3922740 store */
    v40 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v40);
    /* @3922748 load */
    /* @3922756 cast */
    /* @3922760 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3922792;
    L_3922764: ;
    /* @3922764 constant */
    /* @3922768 cast */
    /* @3922772 load */
    /* @3922780 call */
    GM_SITE(vm, 88, 3922780);
    /* @3922788 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3922792: ;
    /* @3922792 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922764;
    /* @3922796 constant */
    /* @3922800 cast */
    /* @3922804 load */
    /* @3922812 constant */
    /* @3922816 sub */
    /* @3922820 load */
    /* @3922828 constant */
    /* @3922832 add */
    /* @3922836 call */
    GM_SITE(vm, 88, 3922836);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3922844 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v42);
    /* @3922852 load */
    /* @3922860 cast */
    /* @3922864 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3922896;
    L_3922868: ;
    /* @3922868 constant */
    /* @3922872 cast */
    /* @3922876 load */
    /* @3922884 call */
    GM_SITE(vm, 88, 3922884);
    /* @3922892 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3922896: ;
    /* @3922896 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922868;
    /* @3922900 constant */
    /* @3922904 cast */
    /* @3922908 load */
    /* @3922916 constant */
    /* @3922920 sub */
    /* @3922924 load */
    /* @3922932 constant */
    /* @3922936 add */
    /* @3922940 call */
    GM_SITE(vm, 88, 3922940);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3922948 store */
    v44 = GM_CALL(vm, "instance_create", 3, v43, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v44);
    /* @3922956 load */
    /* @3922964 cast */
    /* @3922968 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3923000;
    L_3922972: ;
    /* @3922972 constant */
    /* @3922976 cast */
    /* @3922980 load */
    /* @3922988 call */
    GM_SITE(vm, 88, 3922988);
    /* @3922996 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3923000: ;
    /* @3923000 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3922972;
    /* @3923004 constant */
    /* @3923008 cast */
    /* @3923012 load */
    /* @3923020 constant */
    /* @3923024 sub */
    /* @3923028 load */
    /* @3923036 constant */
    /* @3923040 sub */
    /* @3923044 call */
    GM_SITE(vm, 88, 3923044);
    /* @3923052 store */
    v45 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v45);
    /* @3923060 load */
    /* @3923068 cast */
    /* @3923072 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3923104;
    L_3923076: ;
    /* @3923076 constant */
    /* @3923080 cast */
    /* @3923084 load */
    /* @3923092 call */
    GM_SITE(vm, 88, 3923092);
    /* @3923100 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3923104: ;
    /* @3923104 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923076;
    /* @3923108 constant */
    /* @3923112 cast */
    /* @3923116 load */
    /* @3923124 constant */
    /* @3923128 sub */
    /* @3923132 load */
    /* @3923140 constant */
    /* @3923144 add */
    /* @3923148 call */
    GM_SITE(vm, 88, 3923148);
    v46 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3923156 store */
    v47 = GM_CALL(vm, "instance_create", 3, v46, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v47);
    /* @3923164 load */
    /* @3923172 cast */
    /* @3923176 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3923208;
    L_3923180: ;
    /* @3923180 constant */
    /* @3923184 cast */
    /* @3923188 load */
    /* @3923196 call */
    GM_SITE(vm, 88, 3923196);
    /* @3923204 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3923208: ;
    /* @3923208 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923180;
    L_3923212: ;
    /* @3923212 load */
    /* @3923220 constant */
    /* @3923224 cmp */
    /* @3923228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3924472;
    /* @3923232 constant */
    /* @3923236 cast */
    /* @3923240 load */
    /* @3923248 constant */
    /* @3923252 sub */
    /* @3923256 load */
    /* @3923264 call */
    GM_SITE(vm, 88, 3923264);
    /* @3923272 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v48);
    /* @3923280 load */
    /* @3923288 cast */
    /* @3923292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3923324;
    L_3923296: ;
    /* @3923296 constant */
    /* @3923300 cast */
    /* @3923304 load */
    /* @3923312 call */
    GM_SITE(vm, 88, 3923312);
    /* @3923320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3923324: ;
    /* @3923324 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923296;
    /* @3923328 constant */
    /* @3923332 cast */
    /* @3923336 load */
    /* @3923344 constant */
    /* @3923348 sub */
    /* @3923352 load */
    /* @3923360 constant */
    /* @3923364 add */
    /* @3923368 call */
    GM_SITE(vm, 88, 3923368);
    v49 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3923376 store */
    v50 = GM_CALL(vm, "instance_create", 3, v49, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v50);
    /* @3923384 load */
    /* @3923392 cast */
    /* @3923396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3923428;
    L_3923400: ;
    /* @3923400 constant */
    /* @3923404 cast */
    /* @3923408 load */
    /* @3923416 call */
    GM_SITE(vm, 88, 3923416);
    /* @3923424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3923428: ;
    /* @3923428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923400;
    /* @3923432 constant */
    /* @3923436 cast */
    /* @3923440 load */
    /* @3923448 constant */
    /* @3923452 sub */
    /* @3923456 load */
    /* @3923464 constant */
    /* @3923468 sub */
    /* @3923472 call */
    GM_SITE(vm, 88, 3923472);
    /* @3923480 store */
    v51 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v51);
    /* @3923488 load */
    /* @3923496 cast */
    /* @3923500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3923532;
    L_3923504: ;
    /* @3923504 constant */
    /* @3923508 cast */
    /* @3923512 load */
    /* @3923520 call */
    GM_SITE(vm, 88, 3923520);
    /* @3923528 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3923532: ;
    /* @3923532 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923504;
    /* @3923536 constant */
    /* @3923540 cast */
    /* @3923544 load */
    /* @3923552 constant */
    /* @3923556 sub */
    /* @3923560 load */
    /* @3923568 constant */
    /* @3923572 add */
    /* @3923576 call */
    GM_SITE(vm, 88, 3923576);
    v52 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3923584 store */
    v53 = GM_CALL(vm, "instance_create", 3, v52, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v53);
    /* @3923592 load */
    /* @3923600 cast */
    /* @3923604 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3923636;
    L_3923608: ;
    /* @3923608 constant */
    /* @3923612 cast */
    /* @3923616 load */
    /* @3923624 call */
    GM_SITE(vm, 88, 3923624);
    /* @3923632 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3923636: ;
    /* @3923636 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923608;
    /* @3923640 constant */
    /* @3923644 cast */
    /* @3923648 load */
    /* @3923656 constant */
    /* @3923660 sub */
    /* @3923664 load */
    /* @3923672 constant */
    /* @3923676 sub */
    /* @3923680 call */
    GM_SITE(vm, 88, 3923680);
    /* @3923688 store */
    v54 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v54);
    /* @3923696 load */
    /* @3923704 cast */
    /* @3923708 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3923740;
    L_3923712: ;
    /* @3923712 constant */
    /* @3923716 cast */
    /* @3923720 load */
    /* @3923728 call */
    GM_SITE(vm, 88, 3923728);
    /* @3923736 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3923740: ;
    /* @3923740 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923712;
    /* @3923744 constant */
    /* @3923748 cast */
    /* @3923752 load */
    /* @3923760 constant */
    /* @3923764 sub */
    /* @3923768 load */
    /* @3923776 constant */
    /* @3923780 add */
    /* @3923784 call */
    GM_SITE(vm, 88, 3923784);
    v55 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3923792 store */
    v56 = GM_CALL(vm, "instance_create", 3, v55, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v56);
    /* @3923800 load */
    /* @3923808 cast */
    /* @3923812 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3923844;
    L_3923816: ;
    /* @3923816 constant */
    /* @3923820 cast */
    /* @3923824 load */
    /* @3923832 call */
    GM_SITE(vm, 88, 3923832);
    /* @3923840 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3923844: ;
    /* @3923844 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923816;
    /* @3923848 constant */
    /* @3923852 cast */
    /* @3923856 load */
    /* @3923864 constant */
    /* @3923868 sub */
    /* @3923872 load */
    /* @3923880 constant */
    /* @3923884 add */
    /* @3923888 call */
    GM_SITE(vm, 88, 3923888);
    v57 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3923896 store */
    v58 = GM_CALL(vm, "instance_create", 3, v57, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v58);
    /* @3923904 load */
    /* @3923912 cast */
    /* @3923916 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3923948;
    L_3923920: ;
    /* @3923920 constant */
    /* @3923924 cast */
    /* @3923928 load */
    /* @3923936 call */
    GM_SITE(vm, 88, 3923936);
    /* @3923944 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3923948: ;
    /* @3923948 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3923920;
    /* @3923952 constant */
    /* @3923956 cast */
    /* @3923960 load */
    /* @3923968 constant */
    /* @3923972 sub */
    /* @3923976 load */
    /* @3923984 constant */
    /* @3923988 sub */
    /* @3923992 call */
    GM_SITE(vm, 88, 3923992);
    /* @3924000 store */
    v59 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v59);
    /* @3924008 load */
    /* @3924016 cast */
    /* @3924020 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3924052;
    L_3924024: ;
    /* @3924024 constant */
    /* @3924028 cast */
    /* @3924032 load */
    /* @3924040 call */
    GM_SITE(vm, 88, 3924040);
    /* @3924048 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3924052: ;
    /* @3924052 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3924024;
    /* @3924056 constant */
    /* @3924060 cast */
    /* @3924064 load */
    /* @3924072 constant */
    /* @3924076 sub */
    /* @3924080 load */
    /* @3924088 constant */
    /* @3924092 add */
    /* @3924096 call */
    GM_SITE(vm, 88, 3924096);
    v60 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @3924104 store */
    v61 = GM_CALL(vm, "instance_create", 3, v60, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID9", v61);
    /* @3924112 load */
    /* @3924120 cast */
    /* @3924124 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3924156;
    L_3924128: ;
    /* @3924128 constant */
    /* @3924132 cast */
    /* @3924136 load */
    /* @3924144 call */
    GM_SITE(vm, 88, 3924144);
    /* @3924152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_3924156: ;
    /* @3924156 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3924128;
    /* @3924160 constant */
    /* @3924164 cast */
    /* @3924168 load */
    /* @3924176 constant */
    /* @3924180 sub */
    /* @3924184 load */
    /* @3924192 constant */
    /* @3924196 sub */
    /* @3924200 call */
    GM_SITE(vm, 88, 3924200);
    /* @3924208 store */
    v62 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID10", v62);
    /* @3924216 load */
    /* @3924224 cast */
    /* @3924228 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3924260;
    L_3924232: ;
    /* @3924232 constant */
    /* @3924236 cast */
    /* @3924240 load */
    /* @3924248 call */
    GM_SITE(vm, 88, 3924248);
    /* @3924256 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_3924260: ;
    /* @3924260 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3924232;
    /* @3924264 constant */
    /* @3924268 cast */
    /* @3924272 load */
    /* @3924280 constant */
    /* @3924284 sub */
    /* @3924288 load */
    /* @3924296 constant */
    /* @3924300 sub */
    /* @3924304 call */
    GM_SITE(vm, 88, 3924304);
    /* @3924312 store */
    v63 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID11", v63);
    /* @3924320 load */
    /* @3924328 cast */
    /* @3924332 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID11")))) goto L_3924364;
    L_3924336: ;
    /* @3924336 constant */
    /* @3924340 cast */
    /* @3924344 load */
    /* @3924352 call */
    GM_SITE(vm, 88, 3924352);
    /* @3924360 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_3924364: ;
    /* @3924364 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3924336;
    /* @3924368 constant */
    /* @3924372 cast */
    /* @3924376 load */
    /* @3924384 constant */
    /* @3924388 sub */
    /* @3924392 load */
    /* @3924400 constant */
    /* @3924404 add */
    /* @3924408 call */
    GM_SITE(vm, 88, 3924408);
    v64 = GM_ADD(GM_READ(vm, -1, "x"), VAL(10));
    /* @3924416 store */
    v65 = GM_CALL(vm, "instance_create", 3, v64, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID12", v65);
    /* @3924424 load */
    /* @3924432 cast */
    /* @3924436 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID12")))) goto L_3924468;
    L_3924440: ;
    /* @3924440 constant */
    /* @3924444 cast */
    /* @3924448 load */
    /* @3924456 call */
    GM_SITE(vm, 88, 3924456);
    /* @3924464 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread12"), VAL(5)));
    L_3924468: ;
    /* @3924468 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3924440;
    L_3924472: ;
    /* @3924472 call */
    GM_SITE(vm, 88, 3924472);
    /* @3924480 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3924484: ;
    return;
}
