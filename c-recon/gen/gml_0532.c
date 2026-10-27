/* generated from CODE 532 (gml_Object_obj_rightbutton_Alarm_1), source start 4828180, end 4829148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0532(GmVM* vm) {
    Val p4828244_0;
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
    Val p4828676_0;
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
    Val p4829128_0;
    Val v28;
    /* @4828180 load */
    /* @4828188 constant */
    /* @4828192 cmp */
    /* @4828196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1)))) goto L_4829148;
    /* @4828200 load */
    /* @4828208 constant */
    /* @4828212 cmp */
    /* @4828216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "sliding1") == VAL(0)))) goto L_4828240;
    /* @4828220 load */
    /* @4828228 constant */
    /* @4828232 cmp */
    /* @4828236 b */
    p4828244_0 = NUMBOOL(GM_READ(vm, 0, "sliding2") == VAL(0));
    goto L_4828244;
    L_4828240: ;
    /* @4828240 constant */
    p4828244_0 = VAL(0);
    L_4828244: ;
    /* @4828244 bf */
    if (!TRUTH(p4828244_0)) goto L_4829148;
    /* @4828248 load */
    /* @4828256 cast */
    /* @4828260 bf */
    if (!TRUTH(BOOL(GM_READ(vm, 0, "grounded")))) goto L_4828696;
    /* @4828264 constant */
    /* @4828268 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(30));
    /* @4828276 constant */
    /* @4828280 store */
    GM_WRITE(vm, 0, "image_xscale", VAL(1));
    /* @4828288 constant */
    /* @4828292 store */
    GM_WRITE(vm, 0, "facing", VAL(0));
    /* @4828300 constant */
    /* @4828304 pushenv */
    if (!GM_PUSHENV(vm, VAL(0))) goto L_4828692;
    L_4828308: ;
    /* @4828308 constant */
    /* @4828312 cast */
    /* @4828316 load */
    /* @4828324 load */
    /* @4828332 constant */
    /* @4828336 add */
    /* @4828340 call */
    GM_SITE(vm, 532, 4828340);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828348 cast */
    /* @4828352 not */
    /* @4828356 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v1, GM_READ(vm, -1, "y"), VAL(4))));
    if (!TRUTH(v2)) goto L_4828672;
    /* @4828360 constant */
    /* @4828364 cast */
    /* @4828368 load */
    /* @4828376 load */
    /* @4828384 constant */
    /* @4828388 add */
    /* @4828392 call */
    GM_SITE(vm, 532, 4828392);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828400 cast */
    /* @4828404 not */
    /* @4828408 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(6))));
    if (!TRUTH(v4)) goto L_4828672;
    /* @4828412 constant */
    /* @4828416 cast */
    /* @4828420 load */
    /* @4828428 load */
    /* @4828436 constant */
    /* @4828440 add */
    /* @4828444 call */
    GM_SITE(vm, 532, 4828444);
    v5 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828452 cast */
    /* @4828456 not */
    /* @4828460 bf */
    v6 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v5, GM_READ(vm, -1, "y"), VAL(5))));
    if (!TRUTH(v6)) goto L_4828672;
    /* @4828464 constant */
    /* @4828468 cast */
    /* @4828472 load */
    /* @4828480 load */
    /* @4828488 constant */
    /* @4828492 add */
    /* @4828496 call */
    GM_SITE(vm, 532, 4828496);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828504 cast */
    /* @4828508 not */
    /* @4828512 bf */
    v8 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v7, GM_READ(vm, -1, "y"), VAL(3))));
    if (!TRUTH(v8)) goto L_4828672;
    /* @4828516 constant */
    /* @4828520 cast */
    /* @4828524 load */
    /* @4828532 load */
    /* @4828540 constant */
    /* @4828544 add */
    /* @4828548 call */
    GM_SITE(vm, 532, 4828548);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828556 cast */
    /* @4828560 not */
    /* @4828564 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v9, GM_READ(vm, -1, "y"), VAL(156))));
    if (!TRUTH(v10)) goto L_4828672;
    /* @4828568 constant */
    /* @4828572 cast */
    /* @4828576 load */
    /* @4828584 load */
    /* @4828592 constant */
    /* @4828596 add */
    /* @4828600 call */
    GM_SITE(vm, 532, 4828600);
    v11 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828608 cast */
    /* @4828612 not */
    /* @4828616 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v11, GM_READ(vm, -1, "y"), VAL(158))));
    if (!TRUTH(v12)) goto L_4828672;
    /* @4828620 constant */
    /* @4828624 cast */
    /* @4828628 load */
    /* @4828636 load */
    /* @4828644 constant */
    /* @4828648 add */
    /* @4828652 call */
    GM_SITE(vm, 532, 4828652);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828660 cast */
    /* @4828664 not */
    /* @4828668 b */
    v14 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, GM_READ(vm, -1, "y"), VAL(159))));
    p4828676_0 = v14;
    goto L_4828676;
    L_4828672: ;
    /* @4828672 constant */
    p4828676_0 = VAL(0);
    L_4828676: ;
    /* @4828676 bf */
    if (!TRUTH(p4828676_0)) goto L_4828692;
    /* @4828680 constant */
    /* @4828684 store */
    GM_WRITE(vm, 0, "hsp", VAL(7));
    L_4828692: ;
    /* @4828692 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4828308;
    L_4828696: ;
    /* @4828696 load */
    /* @4828704 cast */
    /* @4828708 not */
    /* @4828712 bf */
    if (!TRUTH(NOT(BOOL(GM_READ(vm, 0, "grounded"))))) goto L_4829148;
    /* @4828716 constant */
    /* @4828720 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(32));
    /* @4828728 constant */
    /* @4828732 store */
    GM_WRITE(vm, 0, "image_xscale", VAL(1));
    /* @4828740 constant */
    /* @4828744 store */
    GM_WRITE(vm, 0, "facing", VAL(0));
    /* @4828752 constant */
    /* @4828756 pushenv */
    if (!GM_PUSHENV(vm, VAL(0))) goto L_4829144;
    L_4828760: ;
    /* @4828760 constant */
    /* @4828764 cast */
    /* @4828768 load */
    /* @4828776 load */
    /* @4828784 constant */
    /* @4828788 add */
    /* @4828792 call */
    GM_SITE(vm, 532, 4828792);
    v15 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828800 cast */
    /* @4828804 not */
    /* @4828808 bf */
    v16 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v15, GM_READ(vm, -1, "y"), VAL(4))));
    if (!TRUTH(v16)) goto L_4829124;
    /* @4828812 constant */
    /* @4828816 cast */
    /* @4828820 load */
    /* @4828828 load */
    /* @4828836 constant */
    /* @4828840 add */
    /* @4828844 call */
    GM_SITE(vm, 532, 4828844);
    v17 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828852 cast */
    /* @4828856 not */
    /* @4828860 bf */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v17, GM_READ(vm, -1, "y"), VAL(6))));
    if (!TRUTH(v18)) goto L_4829124;
    /* @4828864 constant */
    /* @4828868 cast */
    /* @4828872 load */
    /* @4828880 load */
    /* @4828888 constant */
    /* @4828892 add */
    /* @4828896 call */
    GM_SITE(vm, 532, 4828896);
    v19 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828904 cast */
    /* @4828908 not */
    /* @4828912 bf */
    v20 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v19, GM_READ(vm, -1, "y"), VAL(5))));
    if (!TRUTH(v20)) goto L_4829124;
    /* @4828916 constant */
    /* @4828920 cast */
    /* @4828924 load */
    /* @4828932 load */
    /* @4828940 constant */
    /* @4828944 add */
    /* @4828948 call */
    GM_SITE(vm, 532, 4828948);
    v21 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4828956 cast */
    /* @4828960 not */
    /* @4828964 bf */
    v22 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v21, GM_READ(vm, -1, "y"), VAL(3))));
    if (!TRUTH(v22)) goto L_4829124;
    /* @4828968 constant */
    /* @4828972 cast */
    /* @4828976 load */
    /* @4828984 load */
    /* @4828992 constant */
    /* @4828996 add */
    /* @4829000 call */
    GM_SITE(vm, 532, 4829000);
    v23 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4829008 cast */
    /* @4829012 not */
    /* @4829016 bf */
    v24 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v23, GM_READ(vm, -1, "y"), VAL(156))));
    if (!TRUTH(v24)) goto L_4829124;
    /* @4829020 constant */
    /* @4829024 cast */
    /* @4829028 load */
    /* @4829036 load */
    /* @4829044 constant */
    /* @4829048 add */
    /* @4829052 call */
    GM_SITE(vm, 532, 4829052);
    v25 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4829060 cast */
    /* @4829064 not */
    /* @4829068 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v25, GM_READ(vm, -1, "y"), VAL(158))));
    if (!TRUTH(v26)) goto L_4829124;
    /* @4829072 constant */
    /* @4829076 cast */
    /* @4829080 load */
    /* @4829088 load */
    /* @4829096 constant */
    /* @4829100 add */
    /* @4829104 call */
    GM_SITE(vm, 532, 4829104);
    v27 = GM_ADD(GM_READ(vm, -1, "x"), VAL(1));
    /* @4829112 cast */
    /* @4829116 not */
    /* @4829120 b */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v27, GM_READ(vm, -1, "y"), VAL(159))));
    p4829128_0 = v28;
    goto L_4829128;
    L_4829124: ;
    /* @4829124 constant */
    p4829128_0 = VAL(0);
    L_4829128: ;
    /* @4829128 bf */
    if (!TRUTH(p4829128_0)) goto L_4829144;
    /* @4829132 constant */
    /* @4829136 store */
    GM_WRITE(vm, 0, "hsp", VAL(7));
    L_4829144: ;
    /* @4829144 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4828760;
    L_4829148: ;
    return;
}
