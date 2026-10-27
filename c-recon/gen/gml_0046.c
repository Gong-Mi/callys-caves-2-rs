/* generated from CODE 46 (gml_Object_obj_enemy_Alarm_0), source start 3890148, end 3893516. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0046(GmVM* vm) {
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
    /* @3890148 load */
    /* @3890156 constant */
    /* @3890160 cmp */
    /* @3890164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3890172;
    /* @3890168 b */
    goto L_3890228;
    L_3890172: ;
    /* @3890172 load */
    /* @3890180 constant */
    /* @3890184 cmp */
    /* @3890188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3890228;
    /* @3890192 constant */
    /* @3890196 cast */
    /* @3890200 constant */
    /* @3890204 cast */
    /* @3890208 constant */
    /* @3890212 cast */
    /* @3890216 call */
    GM_SITE(vm, 46, 3890216);
    /* @3890224 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3890228: ;
    /* @3890228 load */
    /* @3890236 constant */
    /* @3890240 cmp */
    /* @3890244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3890292;
    /* @3890248 constant */
    /* @3890252 cast */
    /* @3890256 load */
    /* @3890264 constant */
    /* @3890268 sub */
    /* @3890272 load */
    /* @3890280 call */
    GM_SITE(vm, 46, 3890280);
    /* @3890288 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3890292: ;
    /* @3890292 load */
    /* @3890300 constant */
    /* @3890304 cmp */
    /* @3890308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3890356;
    /* @3890312 constant */
    /* @3890316 cast */
    /* @3890320 load */
    /* @3890328 constant */
    /* @3890332 sub */
    /* @3890336 load */
    /* @3890344 call */
    GM_SITE(vm, 46, 3890344);
    /* @3890352 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3890356: ;
    /* @3890356 load */
    /* @3890364 constant */
    /* @3890368 cmp */
    /* @3890372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3890472;
    /* @3890376 constant */
    /* @3890380 cast */
    /* @3890384 load */
    /* @3890392 constant */
    /* @3890396 sub */
    /* @3890400 load */
    /* @3890408 call */
    GM_SITE(vm, 46, 3890408);
    /* @3890416 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3890424 load */
    /* @3890432 cast */
    /* @3890436 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3890468;
    L_3890440: ;
    /* @3890440 constant */
    /* @3890444 cast */
    /* @3890448 load */
    /* @3890456 call */
    GM_SITE(vm, 46, 3890456);
    /* @3890464 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3890468: ;
    /* @3890468 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3890440;
    L_3890472: ;
    /* @3890472 constant */
    /* @3890476 cast */
    /* @3890480 call */
    GM_SITE(vm, 46, 3890480);
    /* @3890488 constant */
    /* @3890492 cmp */
    /* @3890496 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3890504;
    /* @3890500 b */
    goto L_3893504;
    L_3890504: ;
    /* @3890504 constant */
    /* @3890508 cast */
    /* @3890512 call */
    GM_SITE(vm, 46, 3890512);
    /* @3890520 constant */
    /* @3890524 cmp */
    /* @3890528 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3893504;
    /* @3890532 load */
    /* @3890540 constant */
    /* @3890544 cmp */
    /* @3890548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3890856;
    /* @3890552 constant */
    /* @3890556 cast */
    /* @3890560 load */
    /* @3890568 constant */
    /* @3890572 sub */
    /* @3890576 load */
    /* @3890584 call */
    GM_SITE(vm, 46, 3890584);
    /* @3890592 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3890600 load */
    /* @3890608 cast */
    /* @3890612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3890644;
    L_3890616: ;
    /* @3890616 constant */
    /* @3890620 cast */
    /* @3890624 load */
    /* @3890632 call */
    GM_SITE(vm, 46, 3890632);
    /* @3890640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3890644: ;
    /* @3890644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3890616;
    /* @3890648 constant */
    /* @3890652 cast */
    /* @3890656 load */
    /* @3890664 constant */
    /* @3890668 sub */
    /* @3890672 load */
    /* @3890680 constant */
    /* @3890684 add */
    /* @3890688 call */
    GM_SITE(vm, 46, 3890688);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3890696 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3890704 load */
    /* @3890712 cast */
    /* @3890716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3890748;
    L_3890720: ;
    /* @3890720 constant */
    /* @3890724 cast */
    /* @3890728 load */
    /* @3890736 call */
    GM_SITE(vm, 46, 3890736);
    /* @3890744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3890748: ;
    /* @3890748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3890720;
    /* @3890752 constant */
    /* @3890756 cast */
    /* @3890760 load */
    /* @3890768 constant */
    /* @3890772 sub */
    /* @3890776 load */
    /* @3890784 constant */
    /* @3890788 sub */
    /* @3890792 call */
    GM_SITE(vm, 46, 3890792);
    /* @3890800 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3890808 load */
    /* @3890816 cast */
    /* @3890820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3890852;
    L_3890824: ;
    /* @3890824 constant */
    /* @3890828 cast */
    /* @3890832 load */
    /* @3890840 call */
    GM_SITE(vm, 46, 3890840);
    /* @3890848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3890852: ;
    /* @3890852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3890824;
    L_3890856: ;
    /* @3890856 load */
    /* @3890864 constant */
    /* @3890868 cmp */
    /* @3890872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3891388;
    /* @3890876 constant */
    /* @3890880 cast */
    /* @3890884 load */
    /* @3890892 constant */
    /* @3890896 sub */
    /* @3890900 load */
    /* @3890908 call */
    GM_SITE(vm, 46, 3890908);
    /* @3890916 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v8);
    /* @3890924 load */
    /* @3890932 cast */
    /* @3890936 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3890968;
    L_3890940: ;
    /* @3890940 constant */
    /* @3890944 cast */
    /* @3890948 load */
    /* @3890956 call */
    GM_SITE(vm, 46, 3890956);
    /* @3890964 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3890968: ;
    /* @3890968 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3890940;
    /* @3890972 constant */
    /* @3890976 cast */
    /* @3890980 load */
    /* @3890988 constant */
    /* @3890992 sub */
    /* @3890996 load */
    /* @3891004 constant */
    /* @3891008 add */
    /* @3891012 call */
    GM_SITE(vm, 46, 3891012);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3891020 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v10);
    /* @3891028 load */
    /* @3891036 cast */
    /* @3891040 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3891072;
    L_3891044: ;
    /* @3891044 constant */
    /* @3891048 cast */
    /* @3891052 load */
    /* @3891060 call */
    GM_SITE(vm, 46, 3891060);
    /* @3891068 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3891072: ;
    /* @3891072 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891044;
    /* @3891076 constant */
    /* @3891080 cast */
    /* @3891084 load */
    /* @3891092 constant */
    /* @3891096 sub */
    /* @3891100 load */
    /* @3891108 constant */
    /* @3891112 sub */
    /* @3891116 call */
    GM_SITE(vm, 46, 3891116);
    /* @3891124 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v11);
    /* @3891132 load */
    /* @3891140 cast */
    /* @3891144 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3891176;
    L_3891148: ;
    /* @3891148 constant */
    /* @3891152 cast */
    /* @3891156 load */
    /* @3891164 call */
    GM_SITE(vm, 46, 3891164);
    /* @3891172 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3891176: ;
    /* @3891176 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891148;
    /* @3891180 constant */
    /* @3891184 cast */
    /* @3891188 load */
    /* @3891196 constant */
    /* @3891200 sub */
    /* @3891204 load */
    /* @3891212 constant */
    /* @3891216 add */
    /* @3891220 call */
    GM_SITE(vm, 46, 3891220);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3891228 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v13);
    /* @3891236 load */
    /* @3891244 cast */
    /* @3891248 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3891280;
    L_3891252: ;
    /* @3891252 constant */
    /* @3891256 cast */
    /* @3891260 load */
    /* @3891268 call */
    GM_SITE(vm, 46, 3891268);
    /* @3891276 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3891280: ;
    /* @3891280 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891252;
    /* @3891284 constant */
    /* @3891288 cast */
    /* @3891292 load */
    /* @3891300 constant */
    /* @3891304 sub */
    /* @3891308 load */
    /* @3891316 constant */
    /* @3891320 sub */
    /* @3891324 call */
    GM_SITE(vm, 46, 3891324);
    /* @3891332 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v14);
    /* @3891340 load */
    /* @3891348 cast */
    /* @3891352 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3891384;
    L_3891356: ;
    /* @3891356 constant */
    /* @3891360 cast */
    /* @3891364 load */
    /* @3891372 call */
    GM_SITE(vm, 46, 3891372);
    /* @3891380 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3891384: ;
    /* @3891384 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891356;
    L_3891388: ;
    /* @3891388 load */
    /* @3891396 constant */
    /* @3891400 cmp */
    /* @3891404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3892024;
    /* @3891408 constant */
    /* @3891412 cast */
    /* @3891416 load */
    /* @3891424 constant */
    /* @3891428 sub */
    /* @3891432 load */
    /* @3891440 call */
    GM_SITE(vm, 46, 3891440);
    /* @3891448 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3891456 load */
    /* @3891464 cast */
    /* @3891468 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3891500;
    L_3891472: ;
    /* @3891472 constant */
    /* @3891476 cast */
    /* @3891480 load */
    /* @3891488 call */
    GM_SITE(vm, 46, 3891488);
    /* @3891496 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3891500: ;
    /* @3891500 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891472;
    /* @3891504 constant */
    /* @3891508 cast */
    /* @3891512 load */
    /* @3891520 constant */
    /* @3891524 sub */
    /* @3891528 load */
    /* @3891536 constant */
    /* @3891540 add */
    /* @3891544 call */
    GM_SITE(vm, 46, 3891544);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3891552 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3891560 load */
    /* @3891568 cast */
    /* @3891572 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3891604;
    L_3891576: ;
    /* @3891576 constant */
    /* @3891580 cast */
    /* @3891584 load */
    /* @3891592 call */
    GM_SITE(vm, 46, 3891592);
    /* @3891600 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3891604: ;
    /* @3891604 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891576;
    /* @3891608 constant */
    /* @3891612 cast */
    /* @3891616 load */
    /* @3891624 constant */
    /* @3891628 sub */
    /* @3891632 load */
    /* @3891640 constant */
    /* @3891644 sub */
    /* @3891648 call */
    GM_SITE(vm, 46, 3891648);
    /* @3891656 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3891664 load */
    /* @3891672 cast */
    /* @3891676 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3891708;
    L_3891680: ;
    /* @3891680 constant */
    /* @3891684 cast */
    /* @3891688 load */
    /* @3891696 call */
    GM_SITE(vm, 46, 3891696);
    /* @3891704 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3891708: ;
    /* @3891708 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891680;
    /* @3891712 constant */
    /* @3891716 cast */
    /* @3891720 load */
    /* @3891728 constant */
    /* @3891732 sub */
    /* @3891736 load */
    /* @3891744 constant */
    /* @3891748 add */
    /* @3891752 call */
    GM_SITE(vm, 46, 3891752);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3891760 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3891768 load */
    /* @3891776 cast */
    /* @3891780 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3891812;
    L_3891784: ;
    /* @3891784 constant */
    /* @3891788 cast */
    /* @3891792 load */
    /* @3891800 call */
    GM_SITE(vm, 46, 3891800);
    /* @3891808 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3891812: ;
    /* @3891812 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891784;
    /* @3891816 constant */
    /* @3891820 cast */
    /* @3891824 load */
    /* @3891832 constant */
    /* @3891836 sub */
    /* @3891840 load */
    /* @3891848 constant */
    /* @3891852 sub */
    /* @3891856 call */
    GM_SITE(vm, 46, 3891856);
    /* @3891864 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3891872 load */
    /* @3891880 cast */
    /* @3891884 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3891916;
    L_3891888: ;
    /* @3891888 constant */
    /* @3891892 cast */
    /* @3891896 load */
    /* @3891904 call */
    GM_SITE(vm, 46, 3891904);
    /* @3891912 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3891916: ;
    /* @3891916 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891888;
    /* @3891920 constant */
    /* @3891924 cast */
    /* @3891928 load */
    /* @3891936 constant */
    /* @3891940 sub */
    /* @3891944 load */
    /* @3891952 constant */
    /* @3891956 sub */
    /* @3891960 call */
    GM_SITE(vm, 46, 3891960);
    /* @3891968 store */
    v22 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v22);
    /* @3891976 load */
    /* @3891984 cast */
    /* @3891988 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3892020;
    L_3891992: ;
    /* @3891992 constant */
    /* @3891996 cast */
    /* @3892000 load */
    /* @3892008 call */
    GM_SITE(vm, 46, 3892008);
    /* @3892016 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3892020: ;
    /* @3892020 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3891992;
    L_3892024: ;
    /* @3892024 load */
    /* @3892032 constant */
    /* @3892036 cmp */
    /* @3892040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3892764;
    /* @3892044 constant */
    /* @3892048 cast */
    /* @3892052 load */
    /* @3892060 constant */
    /* @3892064 sub */
    /* @3892068 load */
    /* @3892076 call */
    GM_SITE(vm, 46, 3892076);
    /* @3892084 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v23);
    /* @3892092 load */
    /* @3892100 cast */
    /* @3892104 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3892136;
    L_3892108: ;
    /* @3892108 constant */
    /* @3892112 cast */
    /* @3892116 load */
    /* @3892124 call */
    GM_SITE(vm, 46, 3892124);
    /* @3892132 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3892136: ;
    /* @3892136 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892108;
    /* @3892140 constant */
    /* @3892144 cast */
    /* @3892148 load */
    /* @3892156 constant */
    /* @3892160 sub */
    /* @3892164 load */
    /* @3892172 constant */
    /* @3892176 add */
    /* @3892180 call */
    GM_SITE(vm, 46, 3892180);
    v24 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3892188 store */
    v25 = GM_CALL(vm, "instance_create", 3, v24, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v25);
    /* @3892196 load */
    /* @3892204 cast */
    /* @3892208 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3892240;
    L_3892212: ;
    /* @3892212 constant */
    /* @3892216 cast */
    /* @3892220 load */
    /* @3892228 call */
    GM_SITE(vm, 46, 3892228);
    /* @3892236 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3892240: ;
    /* @3892240 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892212;
    /* @3892244 constant */
    /* @3892248 cast */
    /* @3892252 load */
    /* @3892260 constant */
    /* @3892264 sub */
    /* @3892268 load */
    /* @3892276 constant */
    /* @3892280 sub */
    /* @3892284 call */
    GM_SITE(vm, 46, 3892284);
    /* @3892292 store */
    v26 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v26);
    /* @3892300 load */
    /* @3892308 cast */
    /* @3892312 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3892344;
    L_3892316: ;
    /* @3892316 constant */
    /* @3892320 cast */
    /* @3892324 load */
    /* @3892332 call */
    GM_SITE(vm, 46, 3892332);
    /* @3892340 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3892344: ;
    /* @3892344 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892316;
    /* @3892348 constant */
    /* @3892352 cast */
    /* @3892356 load */
    /* @3892364 constant */
    /* @3892368 sub */
    /* @3892372 load */
    /* @3892380 constant */
    /* @3892384 add */
    /* @3892388 call */
    GM_SITE(vm, 46, 3892388);
    v27 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3892396 store */
    v28 = GM_CALL(vm, "instance_create", 3, v27, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v28);
    /* @3892404 load */
    /* @3892412 cast */
    /* @3892416 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3892448;
    L_3892420: ;
    /* @3892420 constant */
    /* @3892424 cast */
    /* @3892428 load */
    /* @3892436 call */
    GM_SITE(vm, 46, 3892436);
    /* @3892444 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3892448: ;
    /* @3892448 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892420;
    /* @3892452 constant */
    /* @3892456 cast */
    /* @3892460 load */
    /* @3892468 constant */
    /* @3892472 sub */
    /* @3892476 load */
    /* @3892484 constant */
    /* @3892488 sub */
    /* @3892492 call */
    GM_SITE(vm, 46, 3892492);
    /* @3892500 store */
    v29 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v29);
    /* @3892508 load */
    /* @3892516 cast */
    /* @3892520 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3892552;
    L_3892524: ;
    /* @3892524 constant */
    /* @3892528 cast */
    /* @3892532 load */
    /* @3892540 call */
    GM_SITE(vm, 46, 3892540);
    /* @3892548 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3892552: ;
    /* @3892552 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892524;
    /* @3892556 constant */
    /* @3892560 cast */
    /* @3892564 load */
    /* @3892572 constant */
    /* @3892576 sub */
    /* @3892580 load */
    /* @3892588 constant */
    /* @3892592 add */
    /* @3892596 call */
    GM_SITE(vm, 46, 3892596);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3892604 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v31);
    /* @3892612 load */
    /* @3892620 cast */
    /* @3892624 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3892656;
    L_3892628: ;
    /* @3892628 constant */
    /* @3892632 cast */
    /* @3892636 load */
    /* @3892644 call */
    GM_SITE(vm, 46, 3892644);
    /* @3892652 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3892656: ;
    /* @3892656 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892628;
    /* @3892660 constant */
    /* @3892664 cast */
    /* @3892668 load */
    /* @3892676 constant */
    /* @3892680 sub */
    /* @3892684 load */
    /* @3892692 constant */
    /* @3892696 add */
    /* @3892700 call */
    GM_SITE(vm, 46, 3892700);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3892708 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v33);
    /* @3892716 load */
    /* @3892724 cast */
    /* @3892728 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3892760;
    L_3892732: ;
    /* @3892732 constant */
    /* @3892736 cast */
    /* @3892740 load */
    /* @3892748 call */
    GM_SITE(vm, 46, 3892748);
    /* @3892756 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3892760: ;
    /* @3892760 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892732;
    L_3892764: ;
    /* @3892764 load */
    /* @3892772 constant */
    /* @3892776 cmp */
    /* @3892780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3893504;
    /* @3892784 constant */
    /* @3892788 cast */
    /* @3892792 load */
    /* @3892800 constant */
    /* @3892804 sub */
    /* @3892808 load */
    /* @3892816 call */
    GM_SITE(vm, 46, 3892816);
    /* @3892824 store */
    v34 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v34);
    /* @3892832 load */
    /* @3892840 cast */
    /* @3892844 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3892876;
    L_3892848: ;
    /* @3892848 constant */
    /* @3892852 cast */
    /* @3892856 load */
    /* @3892864 call */
    GM_SITE(vm, 46, 3892864);
    /* @3892872 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3892876: ;
    /* @3892876 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892848;
    /* @3892880 constant */
    /* @3892884 cast */
    /* @3892888 load */
    /* @3892896 constant */
    /* @3892900 sub */
    /* @3892904 load */
    /* @3892912 constant */
    /* @3892916 add */
    /* @3892920 call */
    GM_SITE(vm, 46, 3892920);
    v35 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3892928 store */
    v36 = GM_CALL(vm, "instance_create", 3, v35, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v36);
    /* @3892936 load */
    /* @3892944 cast */
    /* @3892948 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3892980;
    L_3892952: ;
    /* @3892952 constant */
    /* @3892956 cast */
    /* @3892960 load */
    /* @3892968 call */
    GM_SITE(vm, 46, 3892968);
    /* @3892976 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3892980: ;
    /* @3892980 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3892952;
    /* @3892984 constant */
    /* @3892988 cast */
    /* @3892992 load */
    /* @3893000 constant */
    /* @3893004 sub */
    /* @3893008 load */
    /* @3893016 constant */
    /* @3893020 sub */
    /* @3893024 call */
    GM_SITE(vm, 46, 3893024);
    /* @3893032 store */
    v37 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v37);
    /* @3893040 load */
    /* @3893048 cast */
    /* @3893052 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3893084;
    L_3893056: ;
    /* @3893056 constant */
    /* @3893060 cast */
    /* @3893064 load */
    /* @3893072 call */
    GM_SITE(vm, 46, 3893072);
    /* @3893080 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3893084: ;
    /* @3893084 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3893056;
    /* @3893088 constant */
    /* @3893092 cast */
    /* @3893096 load */
    /* @3893104 constant */
    /* @3893108 sub */
    /* @3893112 load */
    /* @3893120 constant */
    /* @3893124 add */
    /* @3893128 call */
    GM_SITE(vm, 46, 3893128);
    v38 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3893136 store */
    v39 = GM_CALL(vm, "instance_create", 3, v38, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v39);
    /* @3893144 load */
    /* @3893152 cast */
    /* @3893156 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3893188;
    L_3893160: ;
    /* @3893160 constant */
    /* @3893164 cast */
    /* @3893168 load */
    /* @3893176 call */
    GM_SITE(vm, 46, 3893176);
    /* @3893184 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3893188: ;
    /* @3893188 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3893160;
    /* @3893192 constant */
    /* @3893196 cast */
    /* @3893200 load */
    /* @3893208 constant */
    /* @3893212 sub */
    /* @3893216 load */
    /* @3893224 constant */
    /* @3893228 sub */
    /* @3893232 call */
    GM_SITE(vm, 46, 3893232);
    /* @3893240 store */
    v40 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v40);
    /* @3893248 load */
    /* @3893256 cast */
    /* @3893260 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3893292;
    L_3893264: ;
    /* @3893264 constant */
    /* @3893268 cast */
    /* @3893272 load */
    /* @3893280 call */
    GM_SITE(vm, 46, 3893280);
    /* @3893288 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3893292: ;
    /* @3893292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3893264;
    /* @3893296 constant */
    /* @3893300 cast */
    /* @3893304 load */
    /* @3893312 constant */
    /* @3893316 sub */
    /* @3893320 load */
    /* @3893328 constant */
    /* @3893332 add */
    /* @3893336 call */
    GM_SITE(vm, 46, 3893336);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3893344 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v42);
    /* @3893352 load */
    /* @3893360 cast */
    /* @3893364 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3893396;
    L_3893368: ;
    /* @3893368 constant */
    /* @3893372 cast */
    /* @3893376 load */
    /* @3893384 call */
    GM_SITE(vm, 46, 3893384);
    /* @3893392 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3893396: ;
    /* @3893396 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3893368;
    /* @3893400 constant */
    /* @3893404 cast */
    /* @3893408 load */
    /* @3893416 constant */
    /* @3893420 sub */
    /* @3893424 load */
    /* @3893432 constant */
    /* @3893436 add */
    /* @3893440 call */
    GM_SITE(vm, 46, 3893440);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3893448 store */
    v44 = GM_CALL(vm, "instance_create", 3, v43, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v44);
    /* @3893456 load */
    /* @3893464 cast */
    /* @3893468 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3893500;
    L_3893472: ;
    /* @3893472 constant */
    /* @3893476 cast */
    /* @3893480 load */
    /* @3893488 call */
    GM_SITE(vm, 46, 3893488);
    /* @3893496 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3893500: ;
    /* @3893500 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3893472;
    L_3893504: ;
    /* @3893504 call */
    GM_SITE(vm, 46, 3893504);
    /* @3893512 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3893516: ;
    return;
}
