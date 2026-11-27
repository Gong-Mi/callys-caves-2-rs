/* generated from CODE 67 (gml_Object_obj_shooter1_Step_0), source start 3908236, end 3909916. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0067(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3908612_0;
    Val v4;
    Val v5;
    Val v6;
    Val p3908744_0;
    Val v7;
    Val v8;
    Val p3908876_0;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p3909156_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val p3909308_0;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val p3909508_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p3909660_0;
    Val v36;
    Val v37;
    /* @3908236 constant */
    /* @3908240 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(114));
    /* @3908248 load */
    /* @3908256 constant */
    /* @3908260 cmp */
    /* @3908264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter1") >= VAL(0)))) goto L_3908288;
    /* @3908268 constant */
    /* @3908272 constant */
    /* @3908276 constant */
    /* @3908280 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3908288: ;
    /* @3908288 load */
    /* @3908296 constant */
    /* @3908300 cmp */
    /* @3908304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter1") <= VAL(0)))) goto L_3908328;
    /* @3908308 constant */
    /* @3908312 constant */
    /* @3908316 constant */
    /* @3908320 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3908328: ;
    /* @3908328 constant */
    /* @3908332 cast */
    /* @3908336 load */
    /* @3908344 load */
    /* @3908352 add */
    /* @3908356 load */
    /* @3908364 call */
    GM_SITE(vm, 67, 3908364);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3908372 cast */
    /* @3908376 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3908420;
    /* @3908380 constant */
    /* @3908384 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3908392 constant */
    /* @3908396 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3908404 constant */
    /* @3908408 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3908416 b */
    goto L_3908452;
    L_3908420: ;
    /* @3908420 constant */
    /* @3908432 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3908440 constant */
    /* @3908444 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3908452: ;
    /* @3908452 load */
    /* @3908460 constant */
    /* @3908464 cmp */
    /* @3908468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3908496;
    /* @3908472 constant */
    /* @3908476 store */
    GM_WRITE(vm, -1, "hspeed", VAL(3));
    /* @3908484 constant */
    /* @3908488 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3908496: ;
    /* @3908496 load */
    /* @3908504 constant */
    /* @3908508 cmp */
    /* @3908512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3908540;
    /* @3908516 constant */
    /* @3908520 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-3));
    /* @3908528 constant */
    /* @3908532 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3908540: ;
    /* @3908540 constant */
    /* @3908544 cast */
    /* @3908548 call */
    GM_SITE(vm, 67, 3908548);
    /* @3908556 constant */
    /* @3908560 cmp */
    /* @3908564 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v3)) goto L_3908628;
    /* @3908568 load */
    /* @3908576 constant */
    /* @3908580 cmp */
    /* @3908584 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3908608;
    /* @3908588 load */
    /* @3908596 constant */
    /* @3908600 cmp */
    /* @3908604 b */
    p3908612_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3908612;
    L_3908608: ;
    /* @3908608 constant */
    p3908612_0 = VAL(1);
    L_3908612: ;
    /* @3908612 bf */
    if (!TRUTH(p3908612_0)) goto L_3908628;
    /* @3908616 constant */
    /* @3908620 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3908628: ;
    /* @3908628 constant */
    /* @3908632 cast */
    /* @3908636 load */
    /* @3908644 constant */
    /* @3908648 sub */
    /* @3908652 load */
    /* @3908660 constant */
    /* @3908664 add */
    /* @3908668 call */
    GM_SITE(vm, 67, 3908668);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3908676 cast */
    /* @3908680 bt */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v5)) goto L_3908740;
    /* @3908684 constant */
    /* @3908688 cast */
    /* @3908692 load */
    /* @3908700 constant */
    /* @3908704 sub */
    /* @3908708 load */
    /* @3908716 constant */
    /* @3908720 add */
    /* @3908724 call */
    GM_SITE(vm, 67, 3908724);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3908732 cast */
    /* @3908736 b */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3908744_0 = v7;
    goto L_3908744;
    L_3908740: ;
    /* @3908740 constant */
    p3908744_0 = VAL(1);
    L_3908744: ;
    /* @3908744 bf */
    if (!TRUTH(p3908744_0)) goto L_3908760;
    /* @3908748 constant */
    /* @3908752 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3908760: ;
    /* @3908760 constant */
    /* @3908764 cast */
    /* @3908768 load */
    /* @3908776 constant */
    /* @3908780 sub */
    /* @3908784 load */
    /* @3908792 constant */
    /* @3908796 sub */
    /* @3908800 call */
    GM_SITE(vm, 67, 3908800);
    /* @3908808 cast */
    /* @3908812 bt */
    v8 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v8)) goto L_3908872;
    /* @3908816 constant */
    /* @3908820 cast */
    /* @3908824 load */
    /* @3908832 constant */
    /* @3908836 sub */
    /* @3908840 load */
    /* @3908848 constant */
    /* @3908852 sub */
    /* @3908856 call */
    GM_SITE(vm, 67, 3908856);
    /* @3908864 cast */
    /* @3908868 b */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3908876_0 = v9;
    goto L_3908876;
    L_3908872: ;
    /* @3908872 constant */
    p3908876_0 = VAL(1);
    L_3908876: ;
    /* @3908876 bf */
    if (!TRUTH(p3908876_0)) goto L_3908892;
    /* @3908880 constant */
    /* @3908884 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3908892: ;
    /* @3908892 load */
    /* @3908900 constant */
    /* @3908904 cmp */
    /* @3908908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpshooter1frozen") == VAL(1)))) goto L_3908956;
    /* @3908912 constant */
    /* @3908920 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3908928 constant */
    /* @3908932 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3908940 constant */
    /* @3908944 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3908952 b */
    goto L_3908972;
    L_3908956: ;
    /* @3908956 constant */
    /* @3908964 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3908972: ;
    /* @3908972 constant */
    /* @3908976 cast */
    /* @3908980 load */
    /* @3908988 constant */
    /* @3908992 add */
    /* @3908996 load */
    /* @3909004 constant */
    /* @3909008 add */
    /* @3909012 call */
    GM_SITE(vm, 67, 3909012);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(34));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909020 cast */
    /* @3909024 not */
    /* @3909028 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v10, v11, VAL(4))));
    if (!TRUTH(v12)) goto L_3909152;
    /* @3909032 constant */
    /* @3909036 cast */
    /* @3909040 load */
    /* @3909048 constant */
    /* @3909052 add */
    /* @3909056 load */
    /* @3909064 constant */
    /* @3909068 add */
    /* @3909072 call */
    GM_SITE(vm, 67, 3909072);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(34));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909080 cast */
    /* @3909084 not */
    /* @3909088 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, v14, VAL(6))));
    if (!TRUTH(v15)) goto L_3909152;
    /* @3909092 constant */
    /* @3909096 cast */
    /* @3909100 load */
    /* @3909108 constant */
    /* @3909112 add */
    /* @3909116 load */
    /* @3909124 constant */
    /* @3909128 add */
    /* @3909132 call */
    GM_SITE(vm, 67, 3909132);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(34));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909140 cast */
    /* @3909144 not */
    /* @3909148 b */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v16, v17, VAL(7))));
    p3909156_0 = v18;
    goto L_3909156;
    L_3909152: ;
    /* @3909152 constant */
    p3909156_0 = VAL(0);
    L_3909156: ;
    /* @3909156 bf */
    if (!TRUTH(p3909156_0)) goto L_3909324;
    /* @3909160 constant */
    /* @3909164 cast */
    /* @3909168 load */
    /* @3909176 constant */
    /* @3909180 add */
    /* @3909184 load */
    /* @3909192 call */
    GM_SITE(vm, 67, 3909192);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909200 cast */
    /* @3909204 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(4)));
    if (TRUTH(v20)) goto L_3909304;
    /* @3909208 constant */
    /* @3909212 cast */
    /* @3909216 load */
    /* @3909224 constant */
    /* @3909228 add */
    /* @3909232 load */
    /* @3909240 call */
    GM_SITE(vm, 67, 3909240);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909248 cast */
    /* @3909252 bt */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(6)));
    if (TRUTH(v22)) goto L_3909304;
    /* @3909256 constant */
    /* @3909260 cast */
    /* @3909264 load */
    /* @3909272 constant */
    /* @3909276 add */
    /* @3909280 load */
    /* @3909288 call */
    GM_SITE(vm, 67, 3909288);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909296 cast */
    /* @3909300 b */
    v24 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v23, VAL(7)));
    p3909308_0 = v24;
    goto L_3909308;
    L_3909304: ;
    /* @3909304 constant */
    p3909308_0 = VAL(1);
    L_3909308: ;
    /* @3909308 bf */
    if (!TRUTH(p3909308_0)) goto L_3909324;
    /* @3909312 constant */
    /* @3909316 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3909324: ;
    /* @3909324 constant */
    /* @3909328 cast */
    /* @3909332 load */
    /* @3909340 constant */
    /* @3909344 add */
    /* @3909348 load */
    /* @3909356 constant */
    /* @3909360 sub */
    /* @3909364 call */
    GM_SITE(vm, 67, 3909364);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909372 cast */
    /* @3909376 not */
    /* @3909380 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(34)), v25, VAL(4))));
    if (!TRUTH(v26)) goto L_3909504;
    /* @3909384 constant */
    /* @3909388 cast */
    /* @3909392 load */
    /* @3909400 constant */
    /* @3909404 add */
    /* @3909408 load */
    /* @3909416 constant */
    /* @3909420 sub */
    /* @3909424 call */
    GM_SITE(vm, 67, 3909424);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909432 cast */
    /* @3909436 not */
    /* @3909440 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(34)), v27, VAL(6))));
    if (!TRUTH(v28)) goto L_3909504;
    /* @3909444 constant */
    /* @3909448 cast */
    /* @3909452 load */
    /* @3909460 constant */
    /* @3909464 add */
    /* @3909468 load */
    /* @3909476 constant */
    /* @3909480 sub */
    /* @3909484 call */
    GM_SITE(vm, 67, 3909484);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909492 cast */
    /* @3909496 not */
    /* @3909500 b */
    v30 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(34)), v29, VAL(7))));
    p3909508_0 = v30;
    goto L_3909508;
    L_3909504: ;
    /* @3909504 constant */
    p3909508_0 = VAL(0);
    L_3909508: ;
    /* @3909508 bf */
    if (!TRUTH(p3909508_0)) goto L_3909676;
    /* @3909512 constant */
    /* @3909516 cast */
    /* @3909520 load */
    /* @3909528 constant */
    /* @3909532 add */
    /* @3909536 load */
    /* @3909544 call */
    GM_SITE(vm, 67, 3909544);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909552 cast */
    /* @3909556 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(4)));
    if (TRUTH(v32)) goto L_3909656;
    /* @3909560 constant */
    /* @3909564 cast */
    /* @3909568 load */
    /* @3909576 constant */
    /* @3909580 add */
    /* @3909584 load */
    /* @3909592 call */
    GM_SITE(vm, 67, 3909592);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909600 cast */
    /* @3909604 bt */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(6)));
    if (TRUTH(v34)) goto L_3909656;
    /* @3909608 constant */
    /* @3909612 cast */
    /* @3909616 load */
    /* @3909624 constant */
    /* @3909628 add */
    /* @3909632 load */
    /* @3909640 call */
    GM_SITE(vm, 67, 3909640);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3909648 cast */
    /* @3909652 b */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(7)));
    p3909660_0 = v36;
    goto L_3909660;
    L_3909656: ;
    /* @3909656 constant */
    p3909660_0 = VAL(1);
    L_3909660: ;
    /* @3909660 bf */
    if (!TRUTH(p3909660_0)) goto L_3909676;
    /* @3909664 constant */
    /* @3909668 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3909676: ;
    /* @3909676 load */
    /* @3909684 constant */
    /* @3909688 cmp */
    /* @3909692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3909720;
    /* @3909696 constant */
    /* @3909700 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(113));
    /* @3909708 constant */
    /* @3909712 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3909720: ;
    /* @3909720 load */
    /* @3909728 constant */
    /* @3909732 cmp */
    /* @3909736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3909776;
    /* @3909740 constant */
    /* @3909744 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(113));
    /* @3909752 constant */
    /* @3909756 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3909764 constant */
    /* @3909768 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3909776: ;
    /* @3909776 load */
    /* @3909784 constant */
    /* @3909788 cmp */
    /* @3909792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3909812;
    /* @3909796 constant */
    /* @3909804 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3909812: ;
    /* @3909812 load */
    /* @3909820 constant */
    /* @3909824 cmp */
    /* @3909828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3909856;
    /* @3909832 constant */
    /* @3909836 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3909844 constant */
    /* @3909848 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3909856: ;
    /* @3909856 constant */
    /* @3909860 cast */
    /* @3909864 load */
    /* @3909872 load */
    /* @3909880 call */
    GM_SITE(vm, 67, 3909880);
    /* @3909888 cast */
    /* @3909892 bf */
    v37 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(9)));
    if (!TRUTH(v37)) goto L_3909916;
    /* @3909896 constant */
    /* @3909900 constant */
    /* @3909904 constant */
    /* @3909908 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3909916: ;
    return;
}
