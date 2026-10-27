/* generated from CODE 47 (gml_Object_obj_enemy_Step_0), source start 3893516, end 3895132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0047(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3893880_0;
    Val v4;
    Val v5;
    Val v6;
    Val p3894012_0;
    Val v7;
    Val v8;
    Val p3894144_0;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p3894344_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val p3894496_0;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val p3894696_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p3894848_0;
    Val v36;
    Val v37;
    Val v38;
    /* @3893516 load */
    /* @3893524 constant */
    /* @3893528 cmp */
    /* @3893532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hp") >= VAL(0)))) goto L_3893556;
    /* @3893536 constant */
    /* @3893540 constant */
    /* @3893544 constant */
    /* @3893548 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3893556: ;
    /* @3893556 load */
    /* @3893564 constant */
    /* @3893568 cmp */
    /* @3893572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hp") <= VAL(0)))) goto L_3893596;
    /* @3893576 constant */
    /* @3893580 constant */
    /* @3893584 constant */
    /* @3893588 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3893596: ;
    /* @3893596 constant */
    /* @3893600 cast */
    /* @3893604 load */
    /* @3893612 load */
    /* @3893620 add */
    /* @3893624 load */
    /* @3893632 call */
    GM_SITE(vm, 47, 3893632);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3893640 cast */
    /* @3893644 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3893688;
    /* @3893648 constant */
    /* @3893652 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3893660 constant */
    /* @3893664 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3893672 constant */
    /* @3893676 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3893684 b */
    goto L_3893720;
    L_3893688: ;
    /* @3893688 constant */
    /* @3893700 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3893708 constant */
    /* @3893712 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3893720: ;
    /* @3893720 load */
    /* @3893728 constant */
    /* @3893732 cmp */
    /* @3893736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3893764;
    /* @3893740 constant */
    /* @3893744 store */
    GM_WRITE(vm, -1, "hspeed", VAL(4));
    /* @3893752 constant */
    /* @3893756 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3893764: ;
    /* @3893764 load */
    /* @3893772 constant */
    /* @3893776 cmp */
    /* @3893780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3893808;
    /* @3893784 constant */
    /* @3893788 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-4));
    /* @3893796 constant */
    /* @3893800 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3893808: ;
    /* @3893808 constant */
    /* @3893812 cast */
    /* @3893816 call */
    GM_SITE(vm, 47, 3893816);
    /* @3893824 constant */
    /* @3893828 cmp */
    /* @3893832 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v3)) goto L_3893896;
    /* @3893836 load */
    /* @3893844 constant */
    /* @3893848 cmp */
    /* @3893852 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3893876;
    /* @3893856 load */
    /* @3893864 constant */
    /* @3893868 cmp */
    /* @3893872 b */
    p3893880_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3893880;
    L_3893876: ;
    /* @3893876 constant */
    p3893880_0 = VAL(1);
    L_3893880: ;
    /* @3893880 bf */
    if (!TRUTH(p3893880_0)) goto L_3893896;
    /* @3893884 constant */
    /* @3893888 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3893896: ;
    /* @3893896 constant */
    /* @3893900 cast */
    /* @3893904 load */
    /* @3893912 constant */
    /* @3893916 sub */
    /* @3893920 load */
    /* @3893928 constant */
    /* @3893932 add */
    /* @3893936 call */
    GM_SITE(vm, 47, 3893936);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3893944 cast */
    /* @3893948 bt */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(2)), VAL(4)));
    if (TRUTH(v5)) goto L_3894008;
    /* @3893952 constant */
    /* @3893956 cast */
    /* @3893960 load */
    /* @3893968 constant */
    /* @3893972 sub */
    /* @3893976 load */
    /* @3893984 constant */
    /* @3893988 add */
    /* @3893992 call */
    GM_SITE(vm, 47, 3893992);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3894000 cast */
    /* @3894004 b */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, (GM_READ(vm, -1, "y") - VAL(2)), VAL(6)));
    p3894012_0 = v7;
    goto L_3894012;
    L_3894008: ;
    /* @3894008 constant */
    p3894012_0 = VAL(1);
    L_3894012: ;
    /* @3894012 bf */
    if (!TRUTH(p3894012_0)) goto L_3894028;
    /* @3894016 constant */
    /* @3894020 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3894028: ;
    /* @3894028 constant */
    /* @3894032 cast */
    /* @3894036 load */
    /* @3894044 constant */
    /* @3894048 sub */
    /* @3894052 load */
    /* @3894060 constant */
    /* @3894064 sub */
    /* @3894068 call */
    GM_SITE(vm, 47, 3894068);
    /* @3894076 cast */
    /* @3894080 bt */
    v8 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(2)), VAL(4)));
    if (TRUTH(v8)) goto L_3894140;
    /* @3894084 constant */
    /* @3894088 cast */
    /* @3894092 load */
    /* @3894100 constant */
    /* @3894104 sub */
    /* @3894108 load */
    /* @3894116 constant */
    /* @3894120 sub */
    /* @3894124 call */
    GM_SITE(vm, 47, 3894124);
    /* @3894132 cast */
    /* @3894136 b */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(2)), VAL(6)));
    p3894144_0 = v9;
    goto L_3894144;
    L_3894140: ;
    /* @3894140 constant */
    p3894144_0 = VAL(1);
    L_3894144: ;
    /* @3894144 bf */
    if (!TRUTH(p3894144_0)) goto L_3894160;
    /* @3894148 constant */
    /* @3894152 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3894160: ;
    /* @3894160 constant */
    /* @3894164 cast */
    /* @3894168 load */
    /* @3894176 constant */
    /* @3894180 add */
    /* @3894184 load */
    /* @3894192 constant */
    /* @3894196 add */
    /* @3894200 call */
    GM_SITE(vm, 47, 3894200);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894208 cast */
    /* @3894212 not */
    /* @3894216 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v10, v11, VAL(4))));
    if (!TRUTH(v12)) goto L_3894340;
    /* @3894220 constant */
    /* @3894224 cast */
    /* @3894228 load */
    /* @3894236 constant */
    /* @3894240 add */
    /* @3894244 load */
    /* @3894252 constant */
    /* @3894256 add */
    /* @3894260 call */
    GM_SITE(vm, 47, 3894260);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894268 cast */
    /* @3894272 not */
    /* @3894276 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, v14, VAL(6))));
    if (!TRUTH(v15)) goto L_3894340;
    /* @3894280 constant */
    /* @3894284 cast */
    /* @3894288 load */
    /* @3894296 constant */
    /* @3894300 add */
    /* @3894304 load */
    /* @3894312 constant */
    /* @3894316 add */
    /* @3894320 call */
    GM_SITE(vm, 47, 3894320);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894328 cast */
    /* @3894332 not */
    /* @3894336 b */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v16, v17, VAL(7))));
    p3894344_0 = v18;
    goto L_3894344;
    L_3894340: ;
    /* @3894340 constant */
    p3894344_0 = VAL(0);
    L_3894344: ;
    /* @3894344 bf */
    if (!TRUTH(p3894344_0)) goto L_3894512;
    /* @3894348 constant */
    /* @3894352 cast */
    /* @3894356 load */
    /* @3894364 constant */
    /* @3894368 add */
    /* @3894372 load */
    /* @3894380 call */
    GM_SITE(vm, 47, 3894380);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894388 cast */
    /* @3894392 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(4)));
    if (TRUTH(v20)) goto L_3894492;
    /* @3894396 constant */
    /* @3894400 cast */
    /* @3894404 load */
    /* @3894412 constant */
    /* @3894416 add */
    /* @3894420 load */
    /* @3894428 call */
    GM_SITE(vm, 47, 3894428);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894436 cast */
    /* @3894440 bt */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(6)));
    if (TRUTH(v22)) goto L_3894492;
    /* @3894444 constant */
    /* @3894448 cast */
    /* @3894452 load */
    /* @3894460 constant */
    /* @3894464 add */
    /* @3894468 load */
    /* @3894476 call */
    GM_SITE(vm, 47, 3894476);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894484 cast */
    /* @3894488 b */
    v24 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v23, VAL(7)));
    p3894496_0 = v24;
    goto L_3894496;
    L_3894492: ;
    /* @3894492 constant */
    p3894496_0 = VAL(1);
    L_3894496: ;
    /* @3894496 bf */
    if (!TRUTH(p3894496_0)) goto L_3894512;
    /* @3894500 constant */
    /* @3894504 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3894512: ;
    /* @3894512 constant */
    /* @3894516 cast */
    /* @3894520 load */
    /* @3894528 constant */
    /* @3894532 add */
    /* @3894536 load */
    /* @3894544 constant */
    /* @3894548 sub */
    /* @3894552 call */
    GM_SITE(vm, 47, 3894552);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894560 cast */
    /* @3894564 not */
    /* @3894568 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v25, VAL(4))));
    if (!TRUTH(v26)) goto L_3894692;
    /* @3894572 constant */
    /* @3894576 cast */
    /* @3894580 load */
    /* @3894588 constant */
    /* @3894592 add */
    /* @3894596 load */
    /* @3894604 constant */
    /* @3894608 sub */
    /* @3894612 call */
    GM_SITE(vm, 47, 3894612);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894620 cast */
    /* @3894624 not */
    /* @3894628 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v27, VAL(6))));
    if (!TRUTH(v28)) goto L_3894692;
    /* @3894632 constant */
    /* @3894636 cast */
    /* @3894640 load */
    /* @3894648 constant */
    /* @3894652 add */
    /* @3894656 load */
    /* @3894664 constant */
    /* @3894668 sub */
    /* @3894672 call */
    GM_SITE(vm, 47, 3894672);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894680 cast */
    /* @3894684 not */
    /* @3894688 b */
    v30 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v29, VAL(7))));
    p3894696_0 = v30;
    goto L_3894696;
    L_3894692: ;
    /* @3894692 constant */
    p3894696_0 = VAL(0);
    L_3894696: ;
    /* @3894696 bf */
    if (!TRUTH(p3894696_0)) goto L_3894864;
    /* @3894700 constant */
    /* @3894704 cast */
    /* @3894708 load */
    /* @3894716 constant */
    /* @3894720 add */
    /* @3894724 load */
    /* @3894732 call */
    GM_SITE(vm, 47, 3894732);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894740 cast */
    /* @3894744 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(4)));
    if (TRUTH(v32)) goto L_3894844;
    /* @3894748 constant */
    /* @3894752 cast */
    /* @3894756 load */
    /* @3894764 constant */
    /* @3894768 add */
    /* @3894772 load */
    /* @3894780 call */
    GM_SITE(vm, 47, 3894780);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894788 cast */
    /* @3894792 bt */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(6)));
    if (TRUTH(v34)) goto L_3894844;
    /* @3894796 constant */
    /* @3894800 cast */
    /* @3894804 load */
    /* @3894812 constant */
    /* @3894816 add */
    /* @3894820 load */
    /* @3894828 call */
    GM_SITE(vm, 47, 3894828);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3894836 cast */
    /* @3894840 b */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(7)));
    p3894848_0 = v36;
    goto L_3894848;
    L_3894844: ;
    /* @3894844 constant */
    p3894848_0 = VAL(1);
    L_3894848: ;
    /* @3894848 bf */
    if (!TRUTH(p3894848_0)) goto L_3894864;
    /* @3894852 constant */
    /* @3894856 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3894864: ;
    /* @3894864 load */
    /* @3894872 constant */
    /* @3894876 cmp */
    /* @3894880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3894916;
    /* @3894884 constant */
    /* @3894888 cast */
    /* @3894892 constant */
    /* @3894896 cast */
    /* @3894900 call */
    GM_SITE(vm, 47, 3894900);
    /* @3894908 store */
    v37 = GM_CALL(vm, "choose", 2, VAL(51), VAL(52));
    GM_WRITE(vm, -1, "sprite_index", v37);
    L_3894916: ;
    /* @3894916 load */
    /* @3894924 constant */
    /* @3894928 cmp */
    /* @3894932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3894992;
    /* @3894936 constant */
    /* @3894940 cast */
    /* @3894944 constant */
    /* @3894948 cast */
    /* @3894952 call */
    GM_SITE(vm, 47, 3894952);
    /* @3894960 store */
    v38 = GM_CALL(vm, "choose", 2, VAL(51), VAL(52));
    GM_WRITE(vm, -1, "sprite_index", v38);
    /* @3894968 constant */
    /* @3894972 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3894980 constant */
    /* @3894984 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3894992: ;
    /* @3894992 load */
    /* @3895000 constant */
    /* @3895004 cmp */
    /* @3895008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfrozen") == VAL(1)))) goto L_3895052;
    /* @3895012 constant */
    /* @3895020 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3895028 constant */
    /* @3895032 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3895040 constant */
    /* @3895044 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3895052: ;
    /* @3895052 load */
    /* @3895060 constant */
    /* @3895064 cmp */
    /* @3895068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3895088;
    /* @3895072 constant */
    /* @3895080 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3895088: ;
    /* @3895088 load */
    /* @3895096 constant */
    /* @3895100 cmp */
    /* @3895104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3895132;
    /* @3895108 constant */
    /* @3895112 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3895120 constant */
    /* @3895124 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3895132: ;
    return;
}
