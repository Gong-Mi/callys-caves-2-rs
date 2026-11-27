/* generated from CODE 55 (gml_Object_obj_knifebandit_Alarm_0), source start 3896452, end 3900132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0055(GmVM* vm) {
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
    /* @3896452 load */
    /* @3896460 constant */
    /* @3896464 cmp */
    /* @3896468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3896476;
    /* @3896472 b */
    goto L_3896532;
    L_3896476: ;
    /* @3896476 load */
    /* @3896484 constant */
    /* @3896488 cmp */
    /* @3896492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3896532;
    /* @3896496 constant */
    /* @3896500 cast */
    /* @3896504 constant */
    /* @3896508 cast */
    /* @3896512 constant */
    /* @3896516 cast */
    /* @3896520 call */
    GM_SITE(vm, 55, 3896520);
    /* @3896528 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_3896532: ;
    /* @3896532 load */
    /* @3896540 constant */
    /* @3896544 cmp */
    /* @3896548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpdrop") == VAL(1)))) goto L_3896596;
    /* @3896552 constant */
    /* @3896556 cast */
    /* @3896560 load */
    /* @3896568 constant */
    /* @3896572 sub */
    /* @3896576 load */
    /* @3896584 call */
    GM_SITE(vm, 55, 3896584);
    /* @3896592 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62)));
    L_3896596: ;
    /* @3896596 load */
    /* @3896604 constant */
    /* @3896608 cmp */
    /* @3896612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "gemdropenabled") == VAL(1)))) goto L_3896660;
    /* @3896616 constant */
    /* @3896620 cast */
    /* @3896624 load */
    /* @3896632 constant */
    /* @3896636 sub */
    /* @3896640 load */
    /* @3896648 call */
    GM_SITE(vm, 55, 3896648);
    /* @3896656 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59)));
    L_3896660: ;
    /* @3896660 load */
    /* @3896668 constant */
    /* @3896672 cmp */
    /* @3896676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "xpdrop") == VAL(1)))) goto L_3896776;
    /* @3896680 constant */
    /* @3896684 cast */
    /* @3896688 load */
    /* @3896696 constant */
    /* @3896700 sub */
    /* @3896704 load */
    /* @3896712 call */
    GM_SITE(vm, 55, 3896712);
    /* @3896720 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(61));
    GM_WRITE(vm, -1, "ID", v1);
    /* @3896728 load */
    /* @3896736 cast */
    /* @3896740 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3896772;
    L_3896744: ;
    /* @3896744 constant */
    /* @3896748 cast */
    /* @3896752 load */
    /* @3896760 call */
    GM_SITE(vm, 55, 3896760);
    /* @3896768 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "xpspread"), VAL(5)));
    L_3896772: ;
    /* @3896772 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3896744;
    L_3896776: ;
    /* @3896776 constant */
    /* @3896780 cast */
    /* @3896784 call */
    GM_SITE(vm, 55, 3896784);
    /* @3896792 constant */
    /* @3896796 cmp */
    /* @3896800 bf */
    v2 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) >= VAL(20));
    if (!TRUTH(v2)) goto L_3896808;
    /* @3896804 b */
    goto L_3900120;
    L_3896808: ;
    /* @3896808 constant */
    /* @3896812 cast */
    /* @3896816 call */
    GM_SITE(vm, 55, 3896816);
    /* @3896824 constant */
    /* @3896828 cmp */
    /* @3896832 bf */
    v3 = NUMBOOL(GM_CALL(vm, "instance_number", 1, VAL(60)) < VAL(20));
    if (!TRUTH(v3)) goto L_3900120;
    /* @3896836 load */
    /* @3896844 constant */
    /* @3896848 cmp */
    /* @3896852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(1)))) goto L_3897160;
    /* @3896856 constant */
    /* @3896860 cast */
    /* @3896864 load */
    /* @3896872 constant */
    /* @3896876 sub */
    /* @3896880 load */
    /* @3896888 call */
    GM_SITE(vm, 55, 3896888);
    /* @3896896 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3896904 load */
    /* @3896912 cast */
    /* @3896916 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3896948;
    L_3896920: ;
    /* @3896920 constant */
    /* @3896924 cast */
    /* @3896928 load */
    /* @3896936 call */
    GM_SITE(vm, 55, 3896936);
    /* @3896944 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3896948: ;
    /* @3896948 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3896920;
    /* @3896952 constant */
    /* @3896956 cast */
    /* @3896960 load */
    /* @3896968 constant */
    /* @3896972 sub */
    /* @3896976 load */
    /* @3896984 constant */
    /* @3896988 add */
    /* @3896992 call */
    GM_SITE(vm, 55, 3896992);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3897000 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v6);
    /* @3897008 load */
    /* @3897016 cast */
    /* @3897020 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3897052;
    L_3897024: ;
    /* @3897024 constant */
    /* @3897028 cast */
    /* @3897032 load */
    /* @3897040 call */
    GM_SITE(vm, 55, 3897040);
    /* @3897048 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3897052: ;
    /* @3897052 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897024;
    /* @3897056 constant */
    /* @3897060 cast */
    /* @3897064 load */
    /* @3897072 constant */
    /* @3897076 sub */
    /* @3897080 load */
    /* @3897088 constant */
    /* @3897092 sub */
    /* @3897096 call */
    GM_SITE(vm, 55, 3897096);
    /* @3897104 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v7);
    /* @3897112 load */
    /* @3897120 cast */
    /* @3897124 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3897156;
    L_3897128: ;
    /* @3897128 constant */
    /* @3897132 cast */
    /* @3897136 load */
    /* @3897144 call */
    GM_SITE(vm, 55, 3897144);
    /* @3897152 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3897156: ;
    /* @3897156 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897128;
    L_3897160: ;
    /* @3897160 load */
    /* @3897168 constant */
    /* @3897172 cmp */
    /* @3897176 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(2)))) goto L_3897692;
    /* @3897180 constant */
    /* @3897184 cast */
    /* @3897188 load */
    /* @3897196 constant */
    /* @3897200 sub */
    /* @3897204 load */
    /* @3897212 call */
    GM_SITE(vm, 55, 3897212);
    /* @3897220 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v8);
    /* @3897228 load */
    /* @3897236 cast */
    /* @3897240 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3897272;
    L_3897244: ;
    /* @3897244 constant */
    /* @3897248 cast */
    /* @3897252 load */
    /* @3897260 call */
    GM_SITE(vm, 55, 3897260);
    /* @3897268 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3897272: ;
    /* @3897272 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897244;
    /* @3897276 constant */
    /* @3897280 cast */
    /* @3897284 load */
    /* @3897292 constant */
    /* @3897296 sub */
    /* @3897300 load */
    /* @3897308 constant */
    /* @3897312 add */
    /* @3897316 call */
    GM_SITE(vm, 55, 3897316);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3897324 store */
    v10 = GM_CALL(vm, "instance_create", 3, v9, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v10);
    /* @3897332 load */
    /* @3897340 cast */
    /* @3897344 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3897376;
    L_3897348: ;
    /* @3897348 constant */
    /* @3897352 cast */
    /* @3897356 load */
    /* @3897364 call */
    GM_SITE(vm, 55, 3897364);
    /* @3897372 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3897376: ;
    /* @3897376 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897348;
    /* @3897380 constant */
    /* @3897384 cast */
    /* @3897388 load */
    /* @3897396 constant */
    /* @3897400 sub */
    /* @3897404 load */
    /* @3897412 constant */
    /* @3897416 sub */
    /* @3897420 call */
    GM_SITE(vm, 55, 3897420);
    /* @3897428 store */
    v11 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v11);
    /* @3897436 load */
    /* @3897444 cast */
    /* @3897448 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3897480;
    L_3897452: ;
    /* @3897452 constant */
    /* @3897456 cast */
    /* @3897460 load */
    /* @3897468 call */
    GM_SITE(vm, 55, 3897468);
    /* @3897476 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3897480: ;
    /* @3897480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897452;
    /* @3897484 constant */
    /* @3897488 cast */
    /* @3897492 load */
    /* @3897500 constant */
    /* @3897504 sub */
    /* @3897508 load */
    /* @3897516 constant */
    /* @3897520 add */
    /* @3897524 call */
    GM_SITE(vm, 55, 3897524);
    v12 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3897532 store */
    v13 = GM_CALL(vm, "instance_create", 3, v12, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v13);
    /* @3897540 load */
    /* @3897548 cast */
    /* @3897552 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3897584;
    L_3897556: ;
    /* @3897556 constant */
    /* @3897560 cast */
    /* @3897564 load */
    /* @3897572 call */
    GM_SITE(vm, 55, 3897572);
    /* @3897580 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3897584: ;
    /* @3897584 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897556;
    /* @3897588 constant */
    /* @3897592 cast */
    /* @3897596 load */
    /* @3897604 constant */
    /* @3897608 sub */
    /* @3897612 load */
    /* @3897620 constant */
    /* @3897624 sub */
    /* @3897628 call */
    GM_SITE(vm, 55, 3897628);
    /* @3897636 store */
    v14 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v14);
    /* @3897644 load */
    /* @3897652 cast */
    /* @3897656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3897688;
    L_3897660: ;
    /* @3897660 constant */
    /* @3897664 cast */
    /* @3897668 load */
    /* @3897676 call */
    GM_SITE(vm, 55, 3897676);
    /* @3897684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3897688: ;
    /* @3897688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897660;
    L_3897692: ;
    /* @3897692 load */
    /* @3897700 constant */
    /* @3897704 cmp */
    /* @3897708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(3)))) goto L_3898432;
    /* @3897712 constant */
    /* @3897716 cast */
    /* @3897720 load */
    /* @3897728 constant */
    /* @3897732 sub */
    /* @3897736 load */
    /* @3897744 call */
    GM_SITE(vm, 55, 3897744);
    /* @3897752 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v15);
    /* @3897760 load */
    /* @3897768 cast */
    /* @3897772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3897804;
    L_3897776: ;
    /* @3897776 constant */
    /* @3897780 cast */
    /* @3897784 load */
    /* @3897792 call */
    GM_SITE(vm, 55, 3897792);
    /* @3897800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3897804: ;
    /* @3897804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897776;
    /* @3897808 constant */
    /* @3897812 cast */
    /* @3897816 load */
    /* @3897824 constant */
    /* @3897828 sub */
    /* @3897832 load */
    /* @3897840 constant */
    /* @3897844 add */
    /* @3897848 call */
    GM_SITE(vm, 55, 3897848);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3897856 store */
    v17 = GM_CALL(vm, "instance_create", 3, v16, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v17);
    /* @3897864 load */
    /* @3897872 cast */
    /* @3897876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3897908;
    L_3897880: ;
    /* @3897880 constant */
    /* @3897884 cast */
    /* @3897888 load */
    /* @3897896 call */
    GM_SITE(vm, 55, 3897896);
    /* @3897904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3897908: ;
    /* @3897908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897880;
    /* @3897912 constant */
    /* @3897916 cast */
    /* @3897920 load */
    /* @3897928 constant */
    /* @3897932 sub */
    /* @3897936 load */
    /* @3897944 constant */
    /* @3897948 sub */
    /* @3897952 call */
    GM_SITE(vm, 55, 3897952);
    /* @3897960 store */
    v18 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v18);
    /* @3897968 load */
    /* @3897976 cast */
    /* @3897980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3898012;
    L_3897984: ;
    /* @3897984 constant */
    /* @3897988 cast */
    /* @3897992 load */
    /* @3898000 call */
    GM_SITE(vm, 55, 3898000);
    /* @3898008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3898012: ;
    /* @3898012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3897984;
    /* @3898016 constant */
    /* @3898020 cast */
    /* @3898024 load */
    /* @3898032 constant */
    /* @3898036 sub */
    /* @3898040 load */
    /* @3898048 constant */
    /* @3898052 add */
    /* @3898056 call */
    GM_SITE(vm, 55, 3898056);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3898064 store */
    v20 = GM_CALL(vm, "instance_create", 3, v19, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v20);
    /* @3898072 load */
    /* @3898080 cast */
    /* @3898084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3898116;
    L_3898088: ;
    /* @3898088 constant */
    /* @3898092 cast */
    /* @3898096 load */
    /* @3898104 call */
    GM_SITE(vm, 55, 3898104);
    /* @3898112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3898116: ;
    /* @3898116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898088;
    /* @3898120 constant */
    /* @3898124 cast */
    /* @3898128 load */
    /* @3898136 constant */
    /* @3898140 sub */
    /* @3898144 load */
    /* @3898152 constant */
    /* @3898156 sub */
    /* @3898160 call */
    GM_SITE(vm, 55, 3898160);
    /* @3898168 store */
    v21 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v21);
    /* @3898176 load */
    /* @3898184 cast */
    /* @3898188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3898220;
    L_3898192: ;
    /* @3898192 constant */
    /* @3898196 cast */
    /* @3898200 load */
    /* @3898208 call */
    GM_SITE(vm, 55, 3898208);
    /* @3898216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3898220: ;
    /* @3898220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898192;
    /* @3898224 constant */
    /* @3898228 cast */
    /* @3898232 load */
    /* @3898240 constant */
    /* @3898244 sub */
    /* @3898248 load */
    /* @3898256 constant */
    /* @3898260 sub */
    /* @3898264 call */
    GM_SITE(vm, 55, 3898264);
    /* @3898272 store */
    v22 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v22);
    /* @3898280 load */
    /* @3898288 cast */
    /* @3898292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3898324;
    L_3898296: ;
    /* @3898296 constant */
    /* @3898300 cast */
    /* @3898304 load */
    /* @3898312 call */
    GM_SITE(vm, 55, 3898312);
    /* @3898320 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3898324: ;
    /* @3898324 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898296;
    /* @3898328 constant */
    /* @3898332 cast */
    /* @3898336 load */
    /* @3898344 constant */
    /* @3898348 sub */
    /* @3898352 load */
    /* @3898360 constant */
    /* @3898364 add */
    /* @3898368 call */
    GM_SITE(vm, 55, 3898368);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3898376 store */
    v24 = GM_CALL(vm, "instance_create", 3, v23, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v24);
    /* @3898384 load */
    /* @3898392 cast */
    /* @3898396 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3898428;
    L_3898400: ;
    /* @3898400 constant */
    /* @3898404 cast */
    /* @3898408 load */
    /* @3898416 call */
    GM_SITE(vm, 55, 3898416);
    /* @3898424 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3898428: ;
    /* @3898428 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898400;
    L_3898432: ;
    /* @3898432 load */
    /* @3898440 constant */
    /* @3898444 cmp */
    /* @3898448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(4)))) goto L_3899276;
    /* @3898452 constant */
    /* @3898456 cast */
    /* @3898460 load */
    /* @3898468 constant */
    /* @3898472 sub */
    /* @3898476 load */
    /* @3898484 call */
    GM_SITE(vm, 55, 3898484);
    /* @3898492 store */
    v25 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v25);
    /* @3898500 load */
    /* @3898508 cast */
    /* @3898512 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3898544;
    L_3898516: ;
    /* @3898516 constant */
    /* @3898520 cast */
    /* @3898524 load */
    /* @3898532 call */
    GM_SITE(vm, 55, 3898532);
    /* @3898540 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3898544: ;
    /* @3898544 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898516;
    /* @3898548 constant */
    /* @3898552 cast */
    /* @3898556 load */
    /* @3898564 constant */
    /* @3898568 sub */
    /* @3898572 load */
    /* @3898580 constant */
    /* @3898584 add */
    /* @3898588 call */
    GM_SITE(vm, 55, 3898588);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3898596 store */
    v27 = GM_CALL(vm, "instance_create", 3, v26, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v27);
    /* @3898604 load */
    /* @3898612 cast */
    /* @3898616 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3898648;
    L_3898620: ;
    /* @3898620 constant */
    /* @3898624 cast */
    /* @3898628 load */
    /* @3898636 call */
    GM_SITE(vm, 55, 3898636);
    /* @3898644 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3898648: ;
    /* @3898648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898620;
    /* @3898652 constant */
    /* @3898656 cast */
    /* @3898660 load */
    /* @3898668 constant */
    /* @3898672 sub */
    /* @3898676 load */
    /* @3898684 constant */
    /* @3898688 sub */
    /* @3898692 call */
    GM_SITE(vm, 55, 3898692);
    /* @3898700 store */
    v28 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v28);
    /* @3898708 load */
    /* @3898716 cast */
    /* @3898720 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3898752;
    L_3898724: ;
    /* @3898724 constant */
    /* @3898728 cast */
    /* @3898732 load */
    /* @3898740 call */
    GM_SITE(vm, 55, 3898740);
    /* @3898748 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3898752: ;
    /* @3898752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898724;
    /* @3898756 constant */
    /* @3898760 cast */
    /* @3898764 load */
    /* @3898772 constant */
    /* @3898776 sub */
    /* @3898780 load */
    /* @3898788 constant */
    /* @3898792 add */
    /* @3898796 call */
    GM_SITE(vm, 55, 3898796);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3898804 store */
    v30 = GM_CALL(vm, "instance_create", 3, v29, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v30);
    /* @3898812 load */
    /* @3898820 cast */
    /* @3898824 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3898856;
    L_3898828: ;
    /* @3898828 constant */
    /* @3898832 cast */
    /* @3898836 load */
    /* @3898844 call */
    GM_SITE(vm, 55, 3898844);
    /* @3898852 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3898856: ;
    /* @3898856 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898828;
    /* @3898860 constant */
    /* @3898864 cast */
    /* @3898868 load */
    /* @3898876 constant */
    /* @3898880 sub */
    /* @3898884 load */
    /* @3898892 constant */
    /* @3898896 sub */
    /* @3898900 call */
    GM_SITE(vm, 55, 3898900);
    /* @3898908 store */
    v31 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v31);
    /* @3898916 load */
    /* @3898924 cast */
    /* @3898928 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3898960;
    L_3898932: ;
    /* @3898932 constant */
    /* @3898936 cast */
    /* @3898940 load */
    /* @3898948 call */
    GM_SITE(vm, 55, 3898948);
    /* @3898956 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3898960: ;
    /* @3898960 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3898932;
    /* @3898964 constant */
    /* @3898968 cast */
    /* @3898972 load */
    /* @3898980 constant */
    /* @3898984 sub */
    /* @3898988 load */
    /* @3898996 constant */
    /* @3899000 add */
    /* @3899004 call */
    GM_SITE(vm, 55, 3899004);
    v32 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3899012 store */
    v33 = GM_CALL(vm, "instance_create", 3, v32, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v33);
    /* @3899020 load */
    /* @3899028 cast */
    /* @3899032 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3899064;
    L_3899036: ;
    /* @3899036 constant */
    /* @3899040 cast */
    /* @3899044 load */
    /* @3899052 call */
    GM_SITE(vm, 55, 3899052);
    /* @3899060 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3899064: ;
    /* @3899064 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899036;
    /* @3899068 constant */
    /* @3899072 cast */
    /* @3899076 load */
    /* @3899084 constant */
    /* @3899088 sub */
    /* @3899092 load */
    /* @3899100 constant */
    /* @3899104 add */
    /* @3899108 call */
    GM_SITE(vm, 55, 3899108);
    v34 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3899116 store */
    v35 = GM_CALL(vm, "instance_create", 3, v34, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v35);
    /* @3899124 load */
    /* @3899132 cast */
    /* @3899136 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3899168;
    L_3899140: ;
    /* @3899140 constant */
    /* @3899144 cast */
    /* @3899148 load */
    /* @3899156 call */
    GM_SITE(vm, 55, 3899156);
    /* @3899164 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3899168: ;
    /* @3899168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899140;
    /* @3899172 constant */
    /* @3899176 cast */
    /* @3899180 load */
    /* @3899188 constant */
    /* @3899192 sub */
    /* @3899196 load */
    /* @3899204 constant */
    /* @3899208 sub */
    /* @3899212 call */
    GM_SITE(vm, 55, 3899212);
    /* @3899220 store */
    v36 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v36);
    /* @3899228 load */
    /* @3899236 cast */
    /* @3899240 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3899272;
    L_3899244: ;
    /* @3899244 constant */
    /* @3899248 cast */
    /* @3899252 load */
    /* @3899260 call */
    GM_SITE(vm, 55, 3899260);
    /* @3899268 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3899272: ;
    /* @3899272 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899244;
    L_3899276: ;
    /* @3899276 load */
    /* @3899284 constant */
    /* @3899288 cmp */
    /* @3899292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "coindrop") == VAL(5)))) goto L_3900120;
    /* @3899296 constant */
    /* @3899300 cast */
    /* @3899304 load */
    /* @3899312 constant */
    /* @3899316 sub */
    /* @3899320 load */
    /* @3899328 call */
    GM_SITE(vm, 55, 3899328);
    /* @3899336 store */
    v37 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID", v37);
    /* @3899344 load */
    /* @3899352 cast */
    /* @3899356 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3899388;
    L_3899360: ;
    /* @3899360 constant */
    /* @3899364 cast */
    /* @3899368 load */
    /* @3899376 call */
    GM_SITE(vm, 55, 3899376);
    /* @3899384 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_3899388: ;
    /* @3899388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899360;
    /* @3899392 constant */
    /* @3899396 cast */
    /* @3899400 load */
    /* @3899408 constant */
    /* @3899412 sub */
    /* @3899416 load */
    /* @3899424 constant */
    /* @3899428 add */
    /* @3899432 call */
    GM_SITE(vm, 55, 3899432);
    v38 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @3899440 store */
    v39 = GM_CALL(vm, "instance_create", 3, v38, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v39);
    /* @3899448 load */
    /* @3899456 cast */
    /* @3899460 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3899492;
    L_3899464: ;
    /* @3899464 constant */
    /* @3899468 cast */
    /* @3899472 load */
    /* @3899480 call */
    GM_SITE(vm, 55, 3899480);
    /* @3899488 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_3899492: ;
    /* @3899492 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899464;
    /* @3899496 constant */
    /* @3899500 cast */
    /* @3899504 load */
    /* @3899512 constant */
    /* @3899516 sub */
    /* @3899520 load */
    /* @3899528 constant */
    /* @3899532 sub */
    /* @3899536 call */
    GM_SITE(vm, 55, 3899536);
    /* @3899544 store */
    v40 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v40);
    /* @3899552 load */
    /* @3899560 cast */
    /* @3899564 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3899596;
    L_3899568: ;
    /* @3899568 constant */
    /* @3899572 cast */
    /* @3899576 load */
    /* @3899584 call */
    GM_SITE(vm, 55, 3899584);
    /* @3899592 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_3899596: ;
    /* @3899596 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899568;
    /* @3899600 constant */
    /* @3899604 cast */
    /* @3899608 load */
    /* @3899616 constant */
    /* @3899620 sub */
    /* @3899624 load */
    /* @3899632 constant */
    /* @3899636 add */
    /* @3899640 call */
    GM_SITE(vm, 55, 3899640);
    v41 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @3899648 store */
    v42 = GM_CALL(vm, "instance_create", 3, v41, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v42);
    /* @3899656 load */
    /* @3899664 cast */
    /* @3899668 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3899700;
    L_3899672: ;
    /* @3899672 constant */
    /* @3899676 cast */
    /* @3899680 load */
    /* @3899688 call */
    GM_SITE(vm, 55, 3899688);
    /* @3899696 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_3899700: ;
    /* @3899700 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899672;
    /* @3899704 constant */
    /* @3899708 cast */
    /* @3899712 load */
    /* @3899720 constant */
    /* @3899724 sub */
    /* @3899728 load */
    /* @3899736 constant */
    /* @3899740 sub */
    /* @3899744 call */
    GM_SITE(vm, 55, 3899744);
    /* @3899752 store */
    v43 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v43);
    /* @3899760 load */
    /* @3899768 cast */
    /* @3899772 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3899804;
    L_3899776: ;
    /* @3899776 constant */
    /* @3899780 cast */
    /* @3899784 load */
    /* @3899792 call */
    GM_SITE(vm, 55, 3899792);
    /* @3899800 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_3899804: ;
    /* @3899804 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899776;
    /* @3899808 constant */
    /* @3899812 cast */
    /* @3899816 load */
    /* @3899824 constant */
    /* @3899828 sub */
    /* @3899832 load */
    /* @3899840 constant */
    /* @3899844 add */
    /* @3899848 call */
    GM_SITE(vm, 55, 3899848);
    v44 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @3899856 store */
    v45 = GM_CALL(vm, "instance_create", 3, v44, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v45);
    /* @3899864 load */
    /* @3899872 cast */
    /* @3899876 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3899908;
    L_3899880: ;
    /* @3899880 constant */
    /* @3899884 cast */
    /* @3899888 load */
    /* @3899896 call */
    GM_SITE(vm, 55, 3899896);
    /* @3899904 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_3899908: ;
    /* @3899908 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899880;
    /* @3899912 constant */
    /* @3899916 cast */
    /* @3899920 load */
    /* @3899928 constant */
    /* @3899932 sub */
    /* @3899936 load */
    /* @3899944 constant */
    /* @3899948 add */
    /* @3899952 call */
    GM_SITE(vm, 55, 3899952);
    v46 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @3899960 store */
    v47 = GM_CALL(vm, "instance_create", 3, v46, (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v47);
    /* @3899968 load */
    /* @3899976 cast */
    /* @3899980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3900012;
    L_3899984: ;
    /* @3899984 constant */
    /* @3899988 cast */
    /* @3899992 load */
    /* @3900000 call */
    GM_SITE(vm, 55, 3900000);
    /* @3900008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_3900012: ;
    /* @3900012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3899984;
    /* @3900016 constant */
    /* @3900020 cast */
    /* @3900024 load */
    /* @3900032 constant */
    /* @3900036 sub */
    /* @3900040 load */
    /* @3900048 constant */
    /* @3900052 sub */
    /* @3900056 call */
    GM_SITE(vm, 55, 3900056);
    /* @3900064 store */
    v48 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v48);
    /* @3900072 load */
    /* @3900080 cast */
    /* @3900084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3900116;
    L_3900088: ;
    /* @3900088 constant */
    /* @3900092 cast */
    /* @3900096 load */
    /* @3900104 call */
    GM_SITE(vm, 55, 3900104);
    /* @3900112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_3900116: ;
    /* @3900116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3900088;
    L_3900120: ;
    /* @3900120 call */
    GM_SITE(vm, 55, 3900120);
    /* @3900128 popz */
    (void)(GM_CALL(vm, "action_kill_object", 0));
    L_3900132: ;
    return;
}
