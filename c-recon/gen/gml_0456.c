/* generated from CODE 456 (gml_Object_obj_treasurechestopen_Alarm_0), source start 4636096, end 4641280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0456(GmVM* vm) {
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
    /* @4636096 load */
    /* @4636104 constant */
    /* @4636108 cmp */
    /* @4636112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(1)))) goto L_4637252;
    /* @4636116 constant */
    /* @4636120 cast */
    /* @4636124 load */
    /* @4636132 constant */
    /* @4636136 sub */
    /* @4636140 load */
    /* @4636148 call */
    GM_SITE(vm, 456, 4636148);
    /* @4636156 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v1);
    /* @4636164 load */
    /* @4636172 cast */
    /* @4636176 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4636208;
    L_4636180: ;
    /* @4636180 constant */
    /* @4636184 cast */
    /* @4636188 load */
    /* @4636196 call */
    GM_SITE(vm, 456, 4636196);
    /* @4636204 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(5)));
    L_4636208: ;
    /* @4636208 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636180;
    /* @4636212 constant */
    /* @4636216 cast */
    /* @4636220 load */
    /* @4636228 constant */
    /* @4636232 sub */
    /* @4636236 load */
    /* @4636244 constant */
    /* @4636248 add */
    /* @4636252 call */
    GM_SITE(vm, 456, 4636252);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4636260 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v3);
    /* @4636268 load */
    /* @4636276 cast */
    /* @4636280 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4636312;
    L_4636284: ;
    /* @4636284 constant */
    /* @4636288 cast */
    /* @4636292 load */
    /* @4636300 call */
    GM_SITE(vm, 456, 4636300);
    /* @4636308 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4636312: ;
    /* @4636312 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636284;
    /* @4636316 constant */
    /* @4636320 cast */
    /* @4636324 load */
    /* @4636332 constant */
    /* @4636336 sub */
    /* @4636340 load */
    /* @4636348 constant */
    /* @4636352 sub */
    /* @4636356 call */
    GM_SITE(vm, 456, 4636356);
    /* @4636364 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v4);
    /* @4636372 load */
    /* @4636380 cast */
    /* @4636384 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4636416;
    L_4636388: ;
    /* @4636388 constant */
    /* @4636392 cast */
    /* @4636396 load */
    /* @4636404 call */
    GM_SITE(vm, 456, 4636404);
    /* @4636412 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4636416: ;
    /* @4636416 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636388;
    /* @4636420 constant */
    /* @4636424 cast */
    /* @4636428 load */
    /* @4636436 constant */
    /* @4636440 sub */
    /* @4636444 load */
    /* @4636452 constant */
    /* @4636456 add */
    /* @4636460 call */
    GM_SITE(vm, 456, 4636460);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4636468 store */
    v6 = GM_CALL(vm, "instance_create", 3, v5, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v6);
    /* @4636476 load */
    /* @4636484 cast */
    /* @4636488 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4636520;
    L_4636492: ;
    /* @4636492 constant */
    /* @4636496 cast */
    /* @4636500 load */
    /* @4636508 call */
    GM_SITE(vm, 456, 4636508);
    /* @4636516 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4636520: ;
    /* @4636520 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636492;
    /* @4636524 constant */
    /* @4636528 cast */
    /* @4636532 load */
    /* @4636540 constant */
    /* @4636544 sub */
    /* @4636548 load */
    /* @4636556 constant */
    /* @4636560 sub */
    /* @4636564 call */
    GM_SITE(vm, 456, 4636564);
    /* @4636572 store */
    v7 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v7);
    /* @4636580 load */
    /* @4636588 cast */
    /* @4636592 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4636624;
    L_4636596: ;
    /* @4636596 constant */
    /* @4636600 cast */
    /* @4636604 load */
    /* @4636612 call */
    GM_SITE(vm, 456, 4636612);
    /* @4636620 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4636624: ;
    /* @4636624 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636596;
    /* @4636628 constant */
    /* @4636632 cast */
    /* @4636636 load */
    /* @4636644 constant */
    /* @4636648 sub */
    /* @4636652 load */
    /* @4636660 constant */
    /* @4636664 add */
    /* @4636668 call */
    GM_SITE(vm, 456, 4636668);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4636676 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v9);
    /* @4636684 load */
    /* @4636692 cast */
    /* @4636696 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4636728;
    L_4636700: ;
    /* @4636700 constant */
    /* @4636704 cast */
    /* @4636708 load */
    /* @4636716 call */
    GM_SITE(vm, 456, 4636716);
    /* @4636724 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4636728: ;
    /* @4636728 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636700;
    /* @4636732 constant */
    /* @4636736 cast */
    /* @4636740 load */
    /* @4636748 constant */
    /* @4636752 sub */
    /* @4636756 load */
    /* @4636764 constant */
    /* @4636768 add */
    /* @4636772 call */
    GM_SITE(vm, 456, 4636772);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4636780 store */
    v11 = GM_CALL(vm, "instance_create", 3, v10, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v11);
    /* @4636788 load */
    /* @4636796 cast */
    /* @4636800 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4636832;
    L_4636804: ;
    /* @4636804 constant */
    /* @4636808 cast */
    /* @4636812 load */
    /* @4636820 call */
    GM_SITE(vm, 456, 4636820);
    /* @4636828 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4636832: ;
    /* @4636832 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636804;
    /* @4636836 constant */
    /* @4636840 cast */
    /* @4636844 load */
    /* @4636852 constant */
    /* @4636856 sub */
    /* @4636860 load */
    /* @4636868 constant */
    /* @4636872 sub */
    /* @4636876 call */
    GM_SITE(vm, 456, 4636876);
    /* @4636884 store */
    v12 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID3", v12);
    /* @4636892 load */
    /* @4636900 cast */
    /* @4636904 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4636936;
    L_4636908: ;
    /* @4636908 constant */
    /* @4636912 cast */
    /* @4636916 load */
    /* @4636924 call */
    GM_SITE(vm, 456, 4636924);
    /* @4636932 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4636936: ;
    /* @4636936 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4636908;
    /* @4636940 constant */
    /* @4636944 cast */
    /* @4636948 load */
    /* @4636956 constant */
    /* @4636960 sub */
    /* @4636964 load */
    /* @4636972 constant */
    /* @4636976 add */
    /* @4636980 call */
    GM_SITE(vm, 456, 4636980);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4636988 store */
    v14 = GM_CALL(vm, "instance_create", 3, v13, (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID4", v14);
    /* @4636996 load */
    /* @4637004 cast */
    /* @4637008 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4637040;
    L_4637012: ;
    /* @4637012 constant */
    /* @4637016 cast */
    /* @4637020 load */
    /* @4637028 call */
    GM_SITE(vm, 456, 4637028);
    /* @4637036 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(5)));
    L_4637040: ;
    /* @4637040 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637012;
    /* @4637044 constant */
    /* @4637048 cast */
    /* @4637052 load */
    /* @4637060 constant */
    /* @4637064 sub */
    /* @4637068 load */
    /* @4637076 constant */
    /* @4637080 sub */
    /* @4637084 call */
    GM_SITE(vm, 456, 4637084);
    /* @4637092 store */
    v15 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v15);
    /* @4637100 load */
    /* @4637108 cast */
    /* @4637112 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4637144;
    L_4637116: ;
    /* @4637116 constant */
    /* @4637120 cast */
    /* @4637124 load */
    /* @4637132 call */
    GM_SITE(vm, 456, 4637132);
    /* @4637140 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(5)));
    L_4637144: ;
    /* @4637144 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637116;
    /* @4637148 constant */
    /* @4637152 cast */
    /* @4637156 load */
    /* @4637164 constant */
    /* @4637168 sub */
    /* @4637172 load */
    /* @4637180 constant */
    /* @4637184 sub */
    /* @4637188 call */
    GM_SITE(vm, 456, 4637188);
    /* @4637196 store */
    v16 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(11)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v16);
    /* @4637204 load */
    /* @4637212 cast */
    /* @4637216 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4637248;
    L_4637220: ;
    /* @4637220 constant */
    /* @4637224 cast */
    /* @4637228 load */
    /* @4637236 call */
    GM_SITE(vm, 456, 4637236);
    /* @4637244 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread11"), VAL(5)));
    L_4637248: ;
    /* @4637248 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637220;
    L_4637252: ;
    /* @4637252 load */
    /* @4637260 constant */
    /* @4637264 cmp */
    /* @4637268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(2)))) goto L_4637584;
    /* @4637272 constant */
    /* @4637276 cast */
    /* @4637280 load */
    /* @4637288 constant */
    /* @4637292 sub */
    /* @4637296 load */
    /* @4637304 constant */
    /* @4637308 sub */
    /* @4637312 call */
    GM_SITE(vm, 456, 4637312);
    /* @4637320 store */
    v17 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(18)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v17);
    /* @4637328 load */
    /* @4637336 cast */
    /* @4637340 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4637372;
    L_4637344: ;
    /* @4637344 constant */
    /* @4637348 cast */
    /* @4637352 load */
    /* @4637360 call */
    GM_SITE(vm, 456, 4637360);
    /* @4637368 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread23"), VAL(8)));
    L_4637372: ;
    /* @4637372 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637344;
    /* @4637376 constant */
    /* @4637380 cast */
    /* @4637384 load */
    /* @4637392 constant */
    /* @4637396 sub */
    /* @4637400 load */
    /* @4637408 constant */
    /* @4637412 add */
    /* @4637416 call */
    GM_SITE(vm, 456, 4637416);
    v18 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4637424 store */
    v19 = GM_CALL(vm, "instance_create", 3, v18, (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID4", v19);
    /* @4637432 load */
    /* @4637440 cast */
    /* @4637444 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4637476;
    L_4637448: ;
    /* @4637448 constant */
    /* @4637452 cast */
    /* @4637456 load */
    /* @4637464 call */
    GM_SITE(vm, 456, 4637464);
    /* @4637472 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4637476: ;
    /* @4637476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637448;
    /* @4637480 constant */
    /* @4637484 cast */
    /* @4637488 load */
    /* @4637496 constant */
    /* @4637500 sub */
    /* @4637504 load */
    /* @4637512 constant */
    /* @4637516 sub */
    /* @4637520 call */
    GM_SITE(vm, 456, 4637520);
    /* @4637528 store */
    v20 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID5", v20);
    /* @4637536 load */
    /* @4637544 cast */
    /* @4637548 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4637580;
    L_4637552: ;
    /* @4637552 constant */
    /* @4637556 cast */
    /* @4637560 load */
    /* @4637568 call */
    GM_SITE(vm, 456, 4637568);
    /* @4637576 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread25"), VAL(8)));
    L_4637580: ;
    /* @4637580 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637552;
    L_4637584: ;
    /* @4637584 load */
    /* @4637592 constant */
    /* @4637596 cmp */
    /* @4637600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(3)))) goto L_4638532;
    /* @4637604 constant */
    /* @4637608 cast */
    /* @4637612 load */
    /* @4637620 constant */
    /* @4637624 sub */
    /* @4637628 load */
    /* @4637636 call */
    GM_SITE(vm, 456, 4637636);
    /* @4637644 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v21);
    /* @4637652 load */
    /* @4637660 cast */
    /* @4637664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4637696;
    L_4637668: ;
    /* @4637668 constant */
    /* @4637672 cast */
    /* @4637676 load */
    /* @4637684 call */
    GM_SITE(vm, 456, 4637684);
    /* @4637692 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_4637696: ;
    /* @4637696 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637668;
    /* @4637700 constant */
    /* @4637704 cast */
    /* @4637708 load */
    /* @4637716 constant */
    /* @4637720 sub */
    /* @4637724 load */
    /* @4637732 constant */
    /* @4637736 add */
    /* @4637740 call */
    GM_SITE(vm, 456, 4637740);
    v22 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4637748 store */
    v23 = GM_CALL(vm, "instance_create", 3, v22, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v23);
    /* @4637756 load */
    /* @4637764 cast */
    /* @4637768 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4637800;
    L_4637772: ;
    /* @4637772 constant */
    /* @4637776 cast */
    /* @4637780 load */
    /* @4637788 call */
    GM_SITE(vm, 456, 4637788);
    /* @4637796 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(8)));
    L_4637800: ;
    /* @4637800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637772;
    /* @4637804 constant */
    /* @4637808 cast */
    /* @4637812 load */
    /* @4637820 constant */
    /* @4637824 sub */
    /* @4637828 load */
    /* @4637836 constant */
    /* @4637840 sub */
    /* @4637844 call */
    GM_SITE(vm, 456, 4637844);
    /* @4637852 store */
    v24 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v24);
    /* @4637860 load */
    /* @4637868 cast */
    /* @4637872 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4637904;
    L_4637876: ;
    /* @4637876 constant */
    /* @4637880 cast */
    /* @4637884 load */
    /* @4637892 call */
    GM_SITE(vm, 456, 4637892);
    /* @4637900 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(8)));
    L_4637904: ;
    /* @4637904 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637876;
    /* @4637908 constant */
    /* @4637912 cast */
    /* @4637916 load */
    /* @4637924 constant */
    /* @4637928 sub */
    /* @4637932 load */
    /* @4637940 constant */
    /* @4637944 add */
    /* @4637948 call */
    GM_SITE(vm, 456, 4637948);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4637956 store */
    v26 = GM_CALL(vm, "instance_create", 3, v25, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v26);
    /* @4637964 load */
    /* @4637972 cast */
    /* @4637976 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4638008;
    L_4637980: ;
    /* @4637980 constant */
    /* @4637984 cast */
    /* @4637988 load */
    /* @4637996 call */
    GM_SITE(vm, 456, 4637996);
    /* @4638004 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(8)));
    L_4638008: ;
    /* @4638008 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4637980;
    /* @4638012 constant */
    /* @4638016 cast */
    /* @4638020 load */
    /* @4638028 constant */
    /* @4638032 sub */
    /* @4638036 load */
    /* @4638044 constant */
    /* @4638048 sub */
    /* @4638052 call */
    GM_SITE(vm, 456, 4638052);
    /* @4638060 store */
    v27 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v27);
    /* @4638068 load */
    /* @4638076 cast */
    /* @4638080 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4638112;
    L_4638084: ;
    /* @4638084 constant */
    /* @4638088 cast */
    /* @4638092 load */
    /* @4638100 call */
    GM_SITE(vm, 456, 4638100);
    /* @4638108 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(8)));
    L_4638112: ;
    /* @4638112 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638084;
    /* @4638116 constant */
    /* @4638120 cast */
    /* @4638124 load */
    /* @4638132 constant */
    /* @4638136 sub */
    /* @4638140 load */
    /* @4638148 constant */
    /* @4638152 add */
    /* @4638156 call */
    GM_SITE(vm, 456, 4638156);
    v28 = GM_ADD(GM_READ(vm, -1, "x"), VAL(11));
    /* @4638164 store */
    v29 = GM_CALL(vm, "instance_create", 3, v28, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v29);
    /* @4638172 load */
    /* @4638180 cast */
    /* @4638184 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4638216;
    L_4638188: ;
    /* @4638188 constant */
    /* @4638192 cast */
    /* @4638196 load */
    /* @4638204 call */
    GM_SITE(vm, 456, 4638204);
    /* @4638212 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(8)));
    L_4638216: ;
    /* @4638216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638188;
    /* @4638220 constant */
    /* @4638224 cast */
    /* @4638228 load */
    /* @4638236 constant */
    /* @4638240 sub */
    /* @4638244 load */
    /* @4638252 constant */
    /* @4638256 add */
    /* @4638260 call */
    GM_SITE(vm, 456, 4638260);
    v30 = GM_ADD(GM_READ(vm, -1, "x"), VAL(6));
    /* @4638268 store */
    v31 = GM_CALL(vm, "instance_create", 3, v30, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID7", v31);
    /* @4638276 load */
    /* @4638284 cast */
    /* @4638288 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4638320;
    L_4638292: ;
    /* @4638292 constant */
    /* @4638296 cast */
    /* @4638300 load */
    /* @4638308 call */
    GM_SITE(vm, 456, 4638308);
    /* @4638316 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(8)));
    L_4638320: ;
    /* @4638320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638292;
    /* @4638324 constant */
    /* @4638328 cast */
    /* @4638332 load */
    /* @4638340 constant */
    /* @4638344 sub */
    /* @4638348 load */
    /* @4638356 constant */
    /* @4638360 sub */
    /* @4638364 call */
    GM_SITE(vm, 456, 4638364);
    /* @4638372 store */
    v32 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(6)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(59));
    GM_WRITE(vm, -1, "ID8", v32);
    /* @4638380 load */
    /* @4638388 cast */
    /* @4638392 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4638424;
    L_4638396: ;
    /* @4638396 constant */
    /* @4638400 cast */
    /* @4638404 load */
    /* @4638412 call */
    GM_SITE(vm, 456, 4638412);
    /* @4638420 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(8)));
    L_4638424: ;
    /* @4638424 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638396;
    /* @4638428 constant */
    /* @4638432 cast */
    /* @4638436 load */
    /* @4638444 constant */
    /* @4638448 sub */
    /* @4638452 load */
    /* @4638460 constant */
    /* @4638464 add */
    /* @4638468 call */
    GM_SITE(vm, 456, 4638468);
    v33 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4638476 store */
    v34 = GM_CALL(vm, "instance_create", 3, v33, (GM_READ(vm, -1, "y") - VAL(64)), VAL(59));
    GM_WRITE(vm, -1, "ID9", v34);
    /* @4638484 load */
    /* @4638492 cast */
    /* @4638496 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_4638528;
    L_4638500: ;
    /* @4638500 constant */
    /* @4638504 cast */
    /* @4638508 constant */
    /* @4638512 cast */
    /* @4638516 call */
    GM_SITE(vm, 456, 4638516);
    /* @4638524 popz */
    (void)(GM_CALL(vm, "motion_set", 2, VAL(90), VAL(5)));
    L_4638528: ;
    /* @4638528 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638500;
    L_4638532: ;
    /* @4638532 load */
    /* @4638540 constant */
    /* @4638544 cmp */
    /* @4638548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(4)))) goto L_4639064;
    /* @4638552 constant */
    /* @4638556 cast */
    /* @4638560 load */
    /* @4638568 constant */
    /* @4638572 sub */
    /* @4638576 load */
    /* @4638584 call */
    GM_SITE(vm, 456, 4638584);
    /* @4638592 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v35);
    /* @4638600 load */
    /* @4638608 cast */
    /* @4638612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4638644;
    L_4638616: ;
    /* @4638616 constant */
    /* @4638620 cast */
    /* @4638624 load */
    /* @4638632 call */
    GM_SITE(vm, 456, 4638632);
    /* @4638640 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_4638644: ;
    /* @4638644 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638616;
    /* @4638648 constant */
    /* @4638652 cast */
    /* @4638656 load */
    /* @4638664 constant */
    /* @4638668 sub */
    /* @4638672 load */
    /* @4638680 constant */
    /* @4638684 add */
    /* @4638688 call */
    GM_SITE(vm, 456, 4638688);
    v36 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4638696 store */
    v37 = GM_CALL(vm, "instance_create", 3, v36, (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID2", v37);
    /* @4638704 load */
    /* @4638712 cast */
    /* @4638716 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4638748;
    L_4638720: ;
    /* @4638720 constant */
    /* @4638724 cast */
    /* @4638728 load */
    /* @4638736 call */
    GM_SITE(vm, 456, 4638736);
    /* @4638744 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(8)));
    L_4638748: ;
    /* @4638748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638720;
    /* @4638752 constant */
    /* @4638756 cast */
    /* @4638760 load */
    /* @4638768 constant */
    /* @4638772 sub */
    /* @4638776 load */
    /* @4638784 constant */
    /* @4638788 sub */
    /* @4638792 call */
    GM_SITE(vm, 456, 4638792);
    /* @4638800 store */
    v38 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID3", v38);
    /* @4638808 load */
    /* @4638816 cast */
    /* @4638820 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4638852;
    L_4638824: ;
    /* @4638824 constant */
    /* @4638828 cast */
    /* @4638832 load */
    /* @4638840 call */
    GM_SITE(vm, 456, 4638840);
    /* @4638848 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4638852: ;
    /* @4638852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638824;
    /* @4638856 constant */
    /* @4638860 cast */
    /* @4638864 load */
    /* @4638872 constant */
    /* @4638876 sub */
    /* @4638880 load */
    /* @4638888 constant */
    /* @4638892 add */
    /* @4638896 call */
    GM_SITE(vm, 456, 4638896);
    v39 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4638904 store */
    v40 = GM_CALL(vm, "instance_create", 3, v39, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v40);
    /* @4638912 load */
    /* @4638920 cast */
    /* @4638924 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4638956;
    L_4638928: ;
    /* @4638928 constant */
    /* @4638932 cast */
    /* @4638936 load */
    /* @4638944 call */
    GM_SITE(vm, 456, 4638944);
    /* @4638952 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4638956: ;
    /* @4638956 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4638928;
    /* @4638960 constant */
    /* @4638964 cast */
    /* @4638968 load */
    /* @4638976 constant */
    /* @4638980 sub */
    /* @4638984 load */
    /* @4638992 constant */
    /* @4638996 sub */
    /* @4639000 call */
    GM_SITE(vm, 456, 4639000);
    /* @4639008 store */
    v41 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v41);
    /* @4639016 load */
    /* @4639024 cast */
    /* @4639028 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4639060;
    L_4639032: ;
    /* @4639032 constant */
    /* @4639036 cast */
    /* @4639040 load */
    /* @4639048 call */
    GM_SITE(vm, 456, 4639048);
    /* @4639056 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4639060: ;
    /* @4639060 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639032;
    L_4639064: ;
    /* @4639064 load */
    /* @4639072 constant */
    /* @4639076 cmp */
    /* @4639080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(5)))) goto L_4639900;
    /* @4639084 constant */
    /* @4639088 cast */
    /* @4639092 load */
    /* @4639100 constant */
    /* @4639104 sub */
    /* @4639108 load */
    /* @4639116 call */
    GM_SITE(vm, 456, 4639116);
    /* @4639124 store */
    v42 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID", v42);
    /* @4639132 load */
    /* @4639140 cast */
    /* @4639144 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4639176;
    L_4639148: ;
    /* @4639148 constant */
    /* @4639152 cast */
    /* @4639156 load */
    /* @4639164 call */
    GM_SITE(vm, 456, 4639164);
    /* @4639172 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_4639176: ;
    /* @4639176 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639148;
    /* @4639180 constant */
    /* @4639184 cast */
    /* @4639188 load */
    /* @4639196 constant */
    /* @4639200 sub */
    /* @4639204 load */
    /* @4639212 constant */
    /* @4639216 add */
    /* @4639220 call */
    GM_SITE(vm, 456, 4639220);
    v43 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4639228 store */
    v44 = GM_CALL(vm, "instance_create", 3, v43, (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID2", v44);
    /* @4639236 load */
    /* @4639244 cast */
    /* @4639248 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4639280;
    L_4639252: ;
    /* @4639252 constant */
    /* @4639256 cast */
    /* @4639260 load */
    /* @4639268 call */
    GM_SITE(vm, 456, 4639268);
    /* @4639276 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4639280: ;
    /* @4639280 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639252;
    /* @4639284 constant */
    /* @4639288 cast */
    /* @4639292 load */
    /* @4639300 constant */
    /* @4639304 sub */
    /* @4639308 load */
    /* @4639316 constant */
    /* @4639320 sub */
    /* @4639324 call */
    GM_SITE(vm, 456, 4639324);
    /* @4639332 store */
    v45 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v45);
    /* @4639340 load */
    /* @4639348 cast */
    /* @4639352 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4639384;
    L_4639356: ;
    /* @4639356 constant */
    /* @4639360 cast */
    /* @4639364 load */
    /* @4639372 call */
    GM_SITE(vm, 456, 4639372);
    /* @4639380 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(8)));
    L_4639384: ;
    /* @4639384 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639356;
    /* @4639388 constant */
    /* @4639392 cast */
    /* @4639396 load */
    /* @4639404 constant */
    /* @4639408 sub */
    /* @4639412 load */
    /* @4639420 call */
    GM_SITE(vm, 456, 4639420);
    /* @4639428 store */
    v46 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v46);
    /* @4639436 load */
    /* @4639444 cast */
    /* @4639448 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4639480;
    L_4639452: ;
    /* @4639452 constant */
    /* @4639456 cast */
    /* @4639460 load */
    /* @4639468 call */
    GM_SITE(vm, 456, 4639468);
    /* @4639476 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4639480: ;
    /* @4639480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639452;
    /* @4639484 constant */
    /* @4639488 cast */
    /* @4639492 load */
    /* @4639500 constant */
    /* @4639504 sub */
    /* @4639508 load */
    /* @4639516 constant */
    /* @4639520 add */
    /* @4639524 call */
    GM_SITE(vm, 456, 4639524);
    v47 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4639532 store */
    v48 = GM_CALL(vm, "instance_create", 3, v47, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v48);
    /* @4639540 load */
    /* @4639548 cast */
    /* @4639552 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4639584;
    L_4639556: ;
    /* @4639556 constant */
    /* @4639560 cast */
    /* @4639564 load */
    /* @4639572 call */
    GM_SITE(vm, 456, 4639572);
    /* @4639580 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4639584: ;
    /* @4639584 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639556;
    /* @4639588 constant */
    /* @4639592 cast */
    /* @4639596 load */
    /* @4639604 constant */
    /* @4639608 sub */
    /* @4639612 load */
    /* @4639620 constant */
    /* @4639624 sub */
    /* @4639628 call */
    GM_SITE(vm, 456, 4639628);
    /* @4639636 store */
    v49 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v49);
    /* @4639644 load */
    /* @4639652 cast */
    /* @4639656 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4639688;
    L_4639660: ;
    /* @4639660 constant */
    /* @4639664 cast */
    /* @4639668 load */
    /* @4639676 call */
    GM_SITE(vm, 456, 4639676);
    /* @4639684 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4639688: ;
    /* @4639688 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639660;
    /* @4639692 constant */
    /* @4639696 cast */
    /* @4639700 load */
    /* @4639708 constant */
    /* @4639712 sub */
    /* @4639716 load */
    /* @4639724 constant */
    /* @4639728 add */
    /* @4639732 call */
    GM_SITE(vm, 456, 4639732);
    v50 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4639740 store */
    v51 = GM_CALL(vm, "instance_create", 3, v50, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID8", v51);
    /* @4639748 load */
    /* @4639756 cast */
    /* @4639760 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_4639792;
    L_4639764: ;
    /* @4639764 constant */
    /* @4639768 cast */
    /* @4639772 load */
    /* @4639780 call */
    GM_SITE(vm, 456, 4639780);
    /* @4639788 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4639792: ;
    /* @4639792 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639764;
    /* @4639796 constant */
    /* @4639800 cast */
    /* @4639804 load */
    /* @4639812 constant */
    /* @4639816 sub */
    /* @4639820 load */
    /* @4639828 constant */
    /* @4639832 sub */
    /* @4639836 call */
    GM_SITE(vm, 456, 4639836);
    /* @4639844 store */
    v52 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID7", v52);
    /* @4639852 load */
    /* @4639860 cast */
    /* @4639864 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_4639896;
    L_4639868: ;
    /* @4639868 constant */
    /* @4639872 cast */
    /* @4639876 load */
    /* @4639884 call */
    GM_SITE(vm, 456, 4639884);
    /* @4639892 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4639896: ;
    /* @4639896 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639868;
    L_4639900: ;
    /* @4639900 load */
    /* @4639908 constant */
    /* @4639912 cmp */
    /* @4639916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(6)))) goto L_4640736;
    /* @4639920 constant */
    /* @4639924 cast */
    /* @4639928 load */
    /* @4639936 constant */
    /* @4639940 sub */
    /* @4639944 load */
    /* @4639952 call */
    GM_SITE(vm, 456, 4639952);
    /* @4639960 store */
    v53 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID", v53);
    /* @4639968 load */
    /* @4639976 cast */
    /* @4639980 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4640012;
    L_4639984: ;
    /* @4639984 constant */
    /* @4639988 cast */
    /* @4639992 load */
    /* @4640000 call */
    GM_SITE(vm, 456, 4640000);
    /* @4640008 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_4640012: ;
    /* @4640012 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4639984;
    /* @4640016 constant */
    /* @4640020 cast */
    /* @4640024 load */
    /* @4640032 constant */
    /* @4640036 sub */
    /* @4640040 load */
    /* @4640048 constant */
    /* @4640052 add */
    /* @4640056 call */
    GM_SITE(vm, 456, 4640056);
    v54 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4640064 store */
    v55 = GM_CALL(vm, "instance_create", 3, v54, (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID2", v55);
    /* @4640072 load */
    /* @4640080 cast */
    /* @4640084 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4640116;
    L_4640088: ;
    /* @4640088 constant */
    /* @4640092 cast */
    /* @4640096 load */
    /* @4640104 call */
    GM_SITE(vm, 456, 4640104);
    /* @4640112 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(5)));
    L_4640116: ;
    /* @4640116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640088;
    /* @4640120 constant */
    /* @4640124 cast */
    /* @4640128 load */
    /* @4640136 constant */
    /* @4640140 sub */
    /* @4640144 load */
    /* @4640152 constant */
    /* @4640156 sub */
    /* @4640160 call */
    GM_SITE(vm, 456, 4640160);
    /* @4640168 store */
    v56 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v56);
    /* @4640176 load */
    /* @4640184 cast */
    /* @4640188 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4640220;
    L_4640192: ;
    /* @4640192 constant */
    /* @4640196 cast */
    /* @4640200 load */
    /* @4640208 call */
    GM_SITE(vm, 456, 4640208);
    /* @4640216 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(8)));
    L_4640220: ;
    /* @4640220 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640192;
    /* @4640224 constant */
    /* @4640228 cast */
    /* @4640232 load */
    /* @4640240 constant */
    /* @4640244 sub */
    /* @4640248 load */
    /* @4640256 call */
    GM_SITE(vm, 456, 4640256);
    /* @4640264 store */
    v57 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID", v57);
    /* @4640272 load */
    /* @4640280 cast */
    /* @4640284 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4640316;
    L_4640288: ;
    /* @4640288 constant */
    /* @4640292 cast */
    /* @4640296 load */
    /* @4640304 call */
    GM_SITE(vm, 456, 4640304);
    /* @4640312 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(5)));
    L_4640316: ;
    /* @4640316 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640288;
    /* @4640320 constant */
    /* @4640324 cast */
    /* @4640328 load */
    /* @4640336 constant */
    /* @4640340 sub */
    /* @4640344 load */
    /* @4640352 constant */
    /* @4640356 add */
    /* @4640360 call */
    GM_SITE(vm, 456, 4640360);
    v58 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4640368 store */
    v59 = GM_CALL(vm, "instance_create", 3, v58, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID2", v59);
    /* @4640376 load */
    /* @4640384 cast */
    /* @4640388 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4640420;
    L_4640392: ;
    /* @4640392 constant */
    /* @4640396 cast */
    /* @4640400 load */
    /* @4640408 call */
    GM_SITE(vm, 456, 4640408);
    /* @4640416 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(5)));
    L_4640420: ;
    /* @4640420 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640392;
    /* @4640424 constant */
    /* @4640428 cast */
    /* @4640432 load */
    /* @4640440 constant */
    /* @4640444 sub */
    /* @4640448 load */
    /* @4640456 constant */
    /* @4640460 sub */
    /* @4640464 call */
    GM_SITE(vm, 456, 4640464);
    /* @4640472 store */
    v60 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(2)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID3", v60);
    /* @4640480 load */
    /* @4640488 cast */
    /* @4640492 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_4640524;
    L_4640496: ;
    /* @4640496 constant */
    /* @4640500 cast */
    /* @4640504 load */
    /* @4640512 call */
    GM_SITE(vm, 456, 4640512);
    /* @4640520 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(5)));
    L_4640524: ;
    /* @4640524 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640496;
    /* @4640528 constant */
    /* @4640532 cast */
    /* @4640536 load */
    /* @4640544 constant */
    /* @4640548 sub */
    /* @4640552 load */
    /* @4640560 constant */
    /* @4640564 add */
    /* @4640568 call */
    GM_SITE(vm, 456, 4640568);
    v61 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4640576 store */
    v62 = GM_CALL(vm, "instance_create", 3, v61, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID4", v62);
    /* @4640584 load */
    /* @4640592 cast */
    /* @4640596 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4640628;
    L_4640600: ;
    /* @4640600 constant */
    /* @4640604 cast */
    /* @4640608 load */
    /* @4640616 call */
    GM_SITE(vm, 456, 4640616);
    /* @4640624 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4640628: ;
    /* @4640628 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640600;
    /* @4640632 constant */
    /* @4640636 cast */
    /* @4640640 load */
    /* @4640648 constant */
    /* @4640652 sub */
    /* @4640656 load */
    /* @4640664 constant */
    /* @4640668 sub */
    /* @4640672 call */
    GM_SITE(vm, 456, 4640672);
    /* @4640680 store */
    v63 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v63);
    /* @4640688 load */
    /* @4640696 cast */
    /* @4640700 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4640732;
    L_4640704: ;
    /* @4640704 constant */
    /* @4640708 cast */
    /* @4640712 load */
    /* @4640720 call */
    GM_SITE(vm, 456, 4640720);
    /* @4640728 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4640732: ;
    /* @4640732 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640704;
    L_4640736: ;
    /* @4640736 load */
    /* @4640744 constant */
    /* @4640748 cmp */
    /* @4640752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chestcontents") == VAL(7)))) goto L_4641268;
    /* @4640756 constant */
    /* @4640760 cast */
    /* @4640764 load */
    /* @4640772 constant */
    /* @4640776 sub */
    /* @4640780 load */
    /* @4640788 call */
    GM_SITE(vm, 456, 4640788);
    /* @4640796 store */
    v64 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID", v64);
    /* @4640804 load */
    /* @4640812 cast */
    /* @4640816 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_4640848;
    L_4640820: ;
    /* @4640820 constant */
    /* @4640824 cast */
    /* @4640828 load */
    /* @4640836 call */
    GM_SITE(vm, 456, 4640836);
    /* @4640844 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_4640848: ;
    /* @4640848 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640820;
    /* @4640852 constant */
    /* @4640856 cast */
    /* @4640860 load */
    /* @4640868 constant */
    /* @4640872 sub */
    /* @4640876 load */
    /* @4640884 constant */
    /* @4640888 add */
    /* @4640892 call */
    GM_SITE(vm, 456, 4640892);
    v65 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4640900 store */
    v66 = GM_CALL(vm, "instance_create", 3, v65, (GM_READ(vm, -1, "y") - VAL(35)), VAL(59));
    GM_WRITE(vm, -1, "ID2", v66);
    /* @4640908 load */
    /* @4640916 cast */
    /* @4640920 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_4640952;
    L_4640924: ;
    /* @4640924 constant */
    /* @4640928 cast */
    /* @4640932 load */
    /* @4640940 call */
    GM_SITE(vm, 456, 4640940);
    /* @4640948 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(8)));
    L_4640952: ;
    /* @4640952 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4640924;
    /* @4640956 constant */
    /* @4640960 cast */
    /* @4640964 load */
    /* @4640972 constant */
    /* @4640976 sub */
    /* @4640980 load */
    /* @4640988 constant */
    /* @4640992 add */
    /* @4640996 call */
    GM_SITE(vm, 456, 4640996);
    v67 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @4641004 store */
    v68 = GM_CALL(vm, "instance_create", 3, v67, (GM_READ(vm, -1, "y") - VAL(35)), VAL(62));
    GM_WRITE(vm, -1, "ID4", v68);
    /* @4641012 load */
    /* @4641020 cast */
    /* @4641024 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_4641056;
    L_4641028: ;
    /* @4641028 constant */
    /* @4641032 cast */
    /* @4641036 load */
    /* @4641044 call */
    GM_SITE(vm, 456, 4641044);
    /* @4641052 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(5)));
    L_4641056: ;
    /* @4641056 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4641028;
    /* @4641060 constant */
    /* @4641064 cast */
    /* @4641068 load */
    /* @4641076 constant */
    /* @4641080 sub */
    /* @4641084 load */
    /* @4641092 constant */
    /* @4641096 add */
    /* @4641100 call */
    GM_SITE(vm, 456, 4641100);
    v69 = GM_ADD(GM_READ(vm, -1, "x"), VAL(4));
    /* @4641108 store */
    v70 = GM_CALL(vm, "instance_create", 3, v69, (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID6", v70);
    /* @4641116 load */
    /* @4641124 cast */
    /* @4641128 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_4641160;
    L_4641132: ;
    /* @4641132 constant */
    /* @4641136 cast */
    /* @4641140 load */
    /* @4641148 call */
    GM_SITE(vm, 456, 4641148);
    /* @4641156 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(5)));
    L_4641160: ;
    /* @4641160 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4641132;
    /* @4641164 constant */
    /* @4641168 cast */
    /* @4641172 load */
    /* @4641180 constant */
    /* @4641184 sub */
    /* @4641188 load */
    /* @4641196 constant */
    /* @4641200 sub */
    /* @4641204 call */
    GM_SITE(vm, 456, 4641204);
    /* @4641212 store */
    v71 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(64)), VAL(60));
    GM_WRITE(vm, -1, "ID5", v71);
    /* @4641220 load */
    /* @4641228 cast */
    /* @4641232 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_4641264;
    L_4641236: ;
    /* @4641236 constant */
    /* @4641240 cast */
    /* @4641244 load */
    /* @4641252 call */
    GM_SITE(vm, 456, 4641252);
    /* @4641260 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(5)));
    L_4641264: ;
    /* @4641264 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4641236;
    L_4641268: ;
    /* @4641268 call */
    GM_SITE(vm, 456, 4641268);
    /* @4641276 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4641280: ;
    return;
}
