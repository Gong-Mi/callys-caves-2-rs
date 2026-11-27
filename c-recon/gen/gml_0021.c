/* generated from CODE 21 (gml_Object_obj_house_Alarm_6), source start 3861568, end 3862816. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0021(GmVM* vm) {
    Val v1;
    Val p3861632_0;
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
    /* @3861568 constant */
    /* @3861572 cast */
    /* @3861576 load */
    /* @3861584 load */
    /* @3861592 call */
    GM_SITE(vm, 21, 3861592);
    /* @3861600 cast */
    /* @3861604 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    if (!TRUTH(v1)) goto L_3861628;
    /* @3861608 load */
    /* @3861616 constant */
    /* @3861620 cmp */
    /* @3861624 b */
    p3861632_0 = NUMBOOL(GM_READ(vm, -5, "gemsfromhouse") == VAL(0));
    goto L_3861632;
    L_3861628: ;
    /* @3861628 constant */
    p3861632_0 = VAL(0);
    L_3861632: ;
    /* @3861632 bf */
    if (!TRUTH(p3861632_0)) goto L_3862772;
    /* @3861636 constant */
    /* @3861640 cast */
    /* @3861644 load */
    /* @3861652 constant */
    /* @3861656 add */
    /* @3861660 load */
    /* @3861668 constant */
    /* @3861672 add */
    /* @3861676 call */
    GM_SITE(vm, 21, 3861676);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(350));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3861684 store */
    v4 = GM_CALL(vm, "instance_create", 3, v2, v3, VAL(59));
    GM_WRITE(vm, -1, "ID", v4);
    /* @3861692 load */
    /* @3861700 cast */
    /* @3861704 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID")))) goto L_3861736;
    L_3861708: ;
    /* @3861708 constant */
    /* @3861712 cast */
    /* @3861716 load */
    /* @3861724 call */
    GM_SITE(vm, 21, 3861724);
    /* @3861732 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread"), VAL(8)));
    L_3861736: ;
    /* @3861736 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3861708;
    /* @3861740 constant */
    /* @3861744 cast */
    /* @3861748 load */
    /* @3861756 constant */
    /* @3861760 add */
    /* @3861764 load */
    /* @3861772 constant */
    /* @3861776 add */
    /* @3861780 call */
    GM_SITE(vm, 21, 3861780);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(352));
    v6 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3861788 store */
    v7 = GM_CALL(vm, "instance_create", 3, v5, v6, VAL(59));
    GM_WRITE(vm, -1, "ID2", v7);
    /* @3861796 load */
    /* @3861804 cast */
    /* @3861808 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID2")))) goto L_3861840;
    L_3861812: ;
    /* @3861812 constant */
    /* @3861816 cast */
    /* @3861820 load */
    /* @3861828 call */
    GM_SITE(vm, 21, 3861828);
    /* @3861836 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread2"), VAL(8)));
    L_3861840: ;
    /* @3861840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3861812;
    /* @3861844 constant */
    /* @3861848 cast */
    /* @3861852 load */
    /* @3861860 constant */
    /* @3861864 add */
    /* @3861868 load */
    /* @3861876 constant */
    /* @3861880 add */
    /* @3861884 call */
    GM_SITE(vm, 21, 3861884);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(355));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3861892 store */
    v10 = GM_CALL(vm, "instance_create", 3, v8, v9, VAL(59));
    GM_WRITE(vm, -1, "ID3", v10);
    /* @3861900 load */
    /* @3861908 cast */
    /* @3861912 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID3")))) goto L_3861944;
    L_3861916: ;
    /* @3861916 constant */
    /* @3861920 cast */
    /* @3861924 load */
    /* @3861932 call */
    GM_SITE(vm, 21, 3861932);
    /* @3861940 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread3"), VAL(8)));
    L_3861944: ;
    /* @3861944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3861916;
    /* @3861948 constant */
    /* @3861952 cast */
    /* @3861956 load */
    /* @3861964 constant */
    /* @3861968 add */
    /* @3861972 load */
    /* @3861980 constant */
    /* @3861984 add */
    /* @3861988 call */
    GM_SITE(vm, 21, 3861988);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(345));
    v12 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3861996 store */
    v13 = GM_CALL(vm, "instance_create", 3, v11, v12, VAL(59));
    GM_WRITE(vm, -1, "ID4", v13);
    /* @3862004 load */
    /* @3862012 cast */
    /* @3862016 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID4")))) goto L_3862048;
    L_3862020: ;
    /* @3862020 constant */
    /* @3862024 cast */
    /* @3862028 load */
    /* @3862036 call */
    GM_SITE(vm, 21, 3862036);
    /* @3862044 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread4"), VAL(8)));
    L_3862048: ;
    /* @3862048 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862020;
    /* @3862052 constant */
    /* @3862056 cast */
    /* @3862060 load */
    /* @3862068 constant */
    /* @3862072 add */
    /* @3862076 load */
    /* @3862084 constant */
    /* @3862088 add */
    /* @3862092 call */
    GM_SITE(vm, 21, 3862092);
    v14 = GM_ADD(GM_READ(vm, -1, "x"), VAL(360));
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862100 store */
    v16 = GM_CALL(vm, "instance_create", 3, v14, v15, VAL(59));
    GM_WRITE(vm, -1, "ID5", v16);
    /* @3862108 load */
    /* @3862116 cast */
    /* @3862120 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID5")))) goto L_3862152;
    L_3862124: ;
    /* @3862124 constant */
    /* @3862128 cast */
    /* @3862132 load */
    /* @3862140 call */
    GM_SITE(vm, 21, 3862140);
    /* @3862148 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread5"), VAL(8)));
    L_3862152: ;
    /* @3862152 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862124;
    /* @3862156 constant */
    /* @3862160 cast */
    /* @3862164 load */
    /* @3862172 constant */
    /* @3862176 add */
    /* @3862180 load */
    /* @3862188 constant */
    /* @3862192 add */
    /* @3862196 call */
    GM_SITE(vm, 21, 3862196);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(340));
    v18 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862204 store */
    v19 = GM_CALL(vm, "instance_create", 3, v17, v18, VAL(59));
    GM_WRITE(vm, -1, "ID6", v19);
    /* @3862212 load */
    /* @3862220 cast */
    /* @3862224 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID6")))) goto L_3862256;
    L_3862228: ;
    /* @3862228 constant */
    /* @3862232 cast */
    /* @3862236 load */
    /* @3862244 call */
    GM_SITE(vm, 21, 3862244);
    /* @3862252 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread6"), VAL(8)));
    L_3862256: ;
    /* @3862256 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862228;
    /* @3862260 constant */
    /* @3862264 cast */
    /* @3862268 load */
    /* @3862276 constant */
    /* @3862280 add */
    /* @3862284 load */
    /* @3862292 constant */
    /* @3862296 add */
    /* @3862300 call */
    GM_SITE(vm, 21, 3862300);
    v20 = GM_ADD(GM_READ(vm, -1, "x"), VAL(335));
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862308 store */
    v22 = GM_CALL(vm, "instance_create", 3, v20, v21, VAL(59));
    GM_WRITE(vm, -1, "ID7", v22);
    /* @3862316 load */
    /* @3862324 cast */
    /* @3862328 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID7")))) goto L_3862360;
    L_3862332: ;
    /* @3862332 constant */
    /* @3862336 cast */
    /* @3862340 load */
    /* @3862348 call */
    GM_SITE(vm, 21, 3862348);
    /* @3862356 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread7"), VAL(8)));
    L_3862360: ;
    /* @3862360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862332;
    /* @3862364 constant */
    /* @3862368 cast */
    /* @3862372 load */
    /* @3862380 constant */
    /* @3862384 add */
    /* @3862388 load */
    /* @3862396 constant */
    /* @3862400 add */
    /* @3862404 call */
    GM_SITE(vm, 21, 3862404);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(365));
    v24 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862412 store */
    v25 = GM_CALL(vm, "instance_create", 3, v23, v24, VAL(59));
    GM_WRITE(vm, -1, "ID8", v25);
    /* @3862420 load */
    /* @3862428 cast */
    /* @3862432 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID8")))) goto L_3862464;
    L_3862436: ;
    /* @3862436 constant */
    /* @3862440 cast */
    /* @3862444 load */
    /* @3862452 call */
    GM_SITE(vm, 21, 3862452);
    /* @3862460 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread8"), VAL(8)));
    L_3862464: ;
    /* @3862464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862436;
    /* @3862468 constant */
    /* @3862472 cast */
    /* @3862476 load */
    /* @3862484 constant */
    /* @3862488 add */
    /* @3862492 load */
    /* @3862500 constant */
    /* @3862504 add */
    /* @3862508 call */
    GM_SITE(vm, 21, 3862508);
    v26 = GM_ADD(GM_READ(vm, -1, "x"), VAL(370));
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862516 store */
    v28 = GM_CALL(vm, "instance_create", 3, v26, v27, VAL(59));
    GM_WRITE(vm, -1, "ID9", v28);
    /* @3862524 load */
    /* @3862532 cast */
    /* @3862536 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID9")))) goto L_3862568;
    L_3862540: ;
    /* @3862540 constant */
    /* @3862544 cast */
    /* @3862548 load */
    /* @3862556 call */
    GM_SITE(vm, 21, 3862556);
    /* @3862564 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread9"), VAL(8)));
    L_3862568: ;
    /* @3862568 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862540;
    /* @3862572 constant */
    /* @3862576 cast */
    /* @3862580 load */
    /* @3862588 constant */
    /* @3862592 add */
    /* @3862596 load */
    /* @3862604 constant */
    /* @3862608 add */
    /* @3862612 call */
    GM_SITE(vm, 21, 3862612);
    v29 = GM_ADD(GM_READ(vm, -1, "x"), VAL(330));
    v30 = GM_ADD(GM_READ(vm, -1, "y"), VAL(100));
    /* @3862620 store */
    v31 = GM_CALL(vm, "instance_create", 3, v29, v30, VAL(59));
    GM_WRITE(vm, -1, "ID10", v31);
    /* @3862628 load */
    /* @3862636 cast */
    /* @3862640 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "ID10")))) goto L_3862672;
    L_3862644: ;
    /* @3862644 constant */
    /* @3862648 cast */
    /* @3862652 load */
    /* @3862660 call */
    GM_SITE(vm, 21, 3862660);
    /* @3862668 popz */
    (void)(GM_CALL(vm, "motion_set", 2, GM_READ(vm, -5, "coinspread10"), VAL(8)));
    L_3862672: ;
    /* @3862672 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3862644;
    /* @3862676 constant */
    /* @3862680 store */
    GM_WRITE(vm, -5, "gemsfromhouse", VAL(1));
    /* @3862688 load */
    /* @3862696 constant */
    /* @3862700 cmp */
    /* @3862704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3862712;
    /* @3862708 b */
    goto L_3862768;
    L_3862712: ;
    /* @3862712 load */
    /* @3862720 constant */
    /* @3862724 cmp */
    /* @3862728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3862768;
    /* @3862732 constant */
    /* @3862736 cast */
    /* @3862740 constant */
    /* @3862744 cast */
    /* @3862748 constant */
    /* @3862752 cast */
    /* @3862756 call */
    GM_SITE(vm, 21, 3862756);
    /* @3862764 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(28), VAL(0), VAL(0)));
    L_3862768: ;
    /* @3862768 b */
    goto L_3862816;
    L_3862772: ;
    /* @3862772 constant */
    /* @3862776 cast */
    /* @3862780 load */
    /* @3862788 load */
    /* @3862796 call */
    GM_SITE(vm, 21, 3862796);
    /* @3862804 cast */
    /* @3862808 not */
    /* @3862812 bf */
    v32 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0))));
    if (!TRUTH(v32)) goto L_3862816;
    L_3862816: ;
    return;
}
