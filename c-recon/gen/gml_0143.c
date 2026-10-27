/* generated from CODE 143 (gml_Object_obj_wolf_Step_0), source start 3963704, end 3965340. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0143(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p3964068_0;
    Val v4;
    Val v5;
    Val v6;
    Val p3964200_0;
    Val v7;
    Val v8;
    Val p3964332_0;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p3964532_0;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val p3964684_0;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val p3964884_0;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val p3965036_0;
    Val v36;
    Val v37;
    Val v38;
    /* @3963704 load */
    /* @3963712 constant */
    /* @3963716 cmp */
    /* @3963720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpwolf") >= VAL(0)))) goto L_3963744;
    /* @3963724 constant */
    /* @3963728 constant */
    /* @3963732 constant */
    /* @3963736 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3963744: ;
    /* @3963744 load */
    /* @3963752 constant */
    /* @3963756 cmp */
    /* @3963760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpwolf") <= VAL(0)))) goto L_3963784;
    /* @3963764 constant */
    /* @3963768 constant */
    /* @3963772 constant */
    /* @3963776 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3963784: ;
    /* @3963784 constant */
    /* @3963788 cast */
    /* @3963792 load */
    /* @3963800 load */
    /* @3963808 add */
    /* @3963812 load */
    /* @3963820 call */
    GM_SITE(vm, 143, 3963820);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3963828 cast */
    /* @3963832 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3963876;
    /* @3963836 constant */
    /* @3963840 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3963848 constant */
    /* @3963852 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3963860 constant */
    /* @3963864 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3963872 b */
    goto L_3963908;
    L_3963876: ;
    /* @3963876 constant */
    /* @3963888 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3963896 constant */
    /* @3963900 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3963908: ;
    /* @3963908 load */
    /* @3963916 constant */
    /* @3963920 cmp */
    /* @3963924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3963952;
    /* @3963928 constant */
    /* @3963932 store */
    GM_WRITE(vm, -1, "hspeed", VAL(4));
    /* @3963940 constant */
    /* @3963944 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3963952: ;
    /* @3963952 load */
    /* @3963960 constant */
    /* @3963964 cmp */
    /* @3963968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3963996;
    /* @3963972 constant */
    /* @3963976 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-4));
    /* @3963984 constant */
    /* @3963988 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3963996: ;
    /* @3963996 constant */
    /* @3964000 cast */
    /* @3964004 call */
    GM_SITE(vm, 143, 3964004);
    /* @3964012 constant */
    /* @3964016 cmp */
    /* @3964020 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v3)) goto L_3964084;
    /* @3964024 load */
    /* @3964032 constant */
    /* @3964036 cmp */
    /* @3964040 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_3964064;
    /* @3964044 load */
    /* @3964052 constant */
    /* @3964056 cmp */
    /* @3964060 b */
    p3964068_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_3964068;
    L_3964064: ;
    /* @3964064 constant */
    p3964068_0 = VAL(1);
    L_3964068: ;
    /* @3964068 bf */
    if (!TRUTH(p3964068_0)) goto L_3964084;
    /* @3964072 constant */
    /* @3964076 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3964084: ;
    /* @3964084 constant */
    /* @3964088 cast */
    /* @3964092 load */
    /* @3964100 constant */
    /* @3964104 sub */
    /* @3964108 load */
    /* @3964116 constant */
    /* @3964120 add */
    /* @3964124 call */
    GM_SITE(vm, 143, 3964124);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3964132 cast */
    /* @3964136 bt */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v5)) goto L_3964196;
    /* @3964140 constant */
    /* @3964144 cast */
    /* @3964148 load */
    /* @3964156 constant */
    /* @3964160 sub */
    /* @3964164 load */
    /* @3964172 constant */
    /* @3964176 add */
    /* @3964180 call */
    GM_SITE(vm, 143, 3964180);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3964188 cast */
    /* @3964192 b */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3964200_0 = v7;
    goto L_3964200;
    L_3964196: ;
    /* @3964196 constant */
    p3964200_0 = VAL(1);
    L_3964200: ;
    /* @3964200 bf */
    if (!TRUTH(p3964200_0)) goto L_3964216;
    /* @3964204 constant */
    /* @3964208 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3964216: ;
    /* @3964216 constant */
    /* @3964220 cast */
    /* @3964224 load */
    /* @3964232 constant */
    /* @3964236 sub */
    /* @3964240 load */
    /* @3964248 constant */
    /* @3964252 sub */
    /* @3964256 call */
    GM_SITE(vm, 143, 3964256);
    /* @3964264 cast */
    /* @3964268 bt */
    v8 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(4)));
    if (TRUTH(v8)) goto L_3964328;
    /* @3964272 constant */
    /* @3964276 cast */
    /* @3964280 load */
    /* @3964288 constant */
    /* @3964292 sub */
    /* @3964296 load */
    /* @3964304 constant */
    /* @3964308 sub */
    /* @3964312 call */
    GM_SITE(vm, 143, 3964312);
    /* @3964320 cast */
    /* @3964324 b */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(6)));
    p3964332_0 = v9;
    goto L_3964332;
    L_3964328: ;
    /* @3964328 constant */
    p3964332_0 = VAL(1);
    L_3964332: ;
    /* @3964332 bf */
    if (!TRUTH(p3964332_0)) goto L_3964348;
    /* @3964336 constant */
    /* @3964340 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3964348: ;
    /* @3964348 constant */
    /* @3964352 cast */
    /* @3964356 load */
    /* @3964364 constant */
    /* @3964368 add */
    /* @3964372 load */
    /* @3964380 constant */
    /* @3964384 add */
    /* @3964388 call */
    GM_SITE(vm, 143, 3964388);
    v10 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964396 cast */
    /* @3964400 not */
    /* @3964404 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v10, v11, VAL(4))));
    if (!TRUTH(v12)) goto L_3964528;
    /* @3964408 constant */
    /* @3964412 cast */
    /* @3964416 load */
    /* @3964424 constant */
    /* @3964428 add */
    /* @3964432 load */
    /* @3964440 constant */
    /* @3964444 add */
    /* @3964448 call */
    GM_SITE(vm, 143, 3964448);
    v13 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v14 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964456 cast */
    /* @3964460 not */
    /* @3964464 bf */
    v15 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v13, v14, VAL(6))));
    if (!TRUTH(v15)) goto L_3964528;
    /* @3964468 constant */
    /* @3964472 cast */
    /* @3964476 load */
    /* @3964484 constant */
    /* @3964488 add */
    /* @3964492 load */
    /* @3964500 constant */
    /* @3964504 add */
    /* @3964508 call */
    GM_SITE(vm, 143, 3964508);
    v16 = GM_ADD(GM_READ(vm, -1, "x"), VAL(40));
    v17 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964516 cast */
    /* @3964520 not */
    /* @3964524 b */
    v18 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v16, v17, VAL(7))));
    p3964532_0 = v18;
    goto L_3964532;
    L_3964528: ;
    /* @3964528 constant */
    p3964532_0 = VAL(0);
    L_3964532: ;
    /* @3964532 bf */
    if (!TRUTH(p3964532_0)) goto L_3964700;
    /* @3964536 constant */
    /* @3964540 cast */
    /* @3964544 load */
    /* @3964552 constant */
    /* @3964556 add */
    /* @3964560 load */
    /* @3964568 call */
    GM_SITE(vm, 143, 3964568);
    v19 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964576 cast */
    /* @3964580 bt */
    v20 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v19, VAL(4)));
    if (TRUTH(v20)) goto L_3964680;
    /* @3964584 constant */
    /* @3964588 cast */
    /* @3964592 load */
    /* @3964600 constant */
    /* @3964604 add */
    /* @3964608 load */
    /* @3964616 call */
    GM_SITE(vm, 143, 3964616);
    v21 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964624 cast */
    /* @3964628 bt */
    v22 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v21, VAL(6)));
    if (TRUTH(v22)) goto L_3964680;
    /* @3964632 constant */
    /* @3964636 cast */
    /* @3964640 load */
    /* @3964648 constant */
    /* @3964652 add */
    /* @3964656 load */
    /* @3964664 call */
    GM_SITE(vm, 143, 3964664);
    v23 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964672 cast */
    /* @3964676 b */
    v24 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v23, VAL(7)));
    p3964684_0 = v24;
    goto L_3964684;
    L_3964680: ;
    /* @3964680 constant */
    p3964684_0 = VAL(1);
    L_3964684: ;
    /* @3964684 bf */
    if (!TRUTH(p3964684_0)) goto L_3964700;
    /* @3964688 constant */
    /* @3964692 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3964700: ;
    /* @3964700 constant */
    /* @3964704 cast */
    /* @3964708 load */
    /* @3964716 constant */
    /* @3964720 add */
    /* @3964724 load */
    /* @3964732 constant */
    /* @3964736 sub */
    /* @3964740 call */
    GM_SITE(vm, 143, 3964740);
    v25 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964748 cast */
    /* @3964752 not */
    /* @3964756 bf */
    v26 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(40)), v25, VAL(4))));
    if (!TRUTH(v26)) goto L_3964880;
    /* @3964760 constant */
    /* @3964764 cast */
    /* @3964768 load */
    /* @3964776 constant */
    /* @3964780 add */
    /* @3964784 load */
    /* @3964792 constant */
    /* @3964796 sub */
    /* @3964800 call */
    GM_SITE(vm, 143, 3964800);
    v27 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964808 cast */
    /* @3964812 not */
    /* @3964816 bf */
    v28 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(40)), v27, VAL(6))));
    if (!TRUTH(v28)) goto L_3964880;
    /* @3964820 constant */
    /* @3964824 cast */
    /* @3964828 load */
    /* @3964836 constant */
    /* @3964840 add */
    /* @3964844 load */
    /* @3964852 constant */
    /* @3964856 sub */
    /* @3964860 call */
    GM_SITE(vm, 143, 3964860);
    v29 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964868 cast */
    /* @3964872 not */
    /* @3964876 b */
    v30 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(40)), v29, VAL(7))));
    p3964884_0 = v30;
    goto L_3964884;
    L_3964880: ;
    /* @3964880 constant */
    p3964884_0 = VAL(0);
    L_3964884: ;
    /* @3964884 bf */
    if (!TRUTH(p3964884_0)) goto L_3965052;
    /* @3964888 constant */
    /* @3964892 cast */
    /* @3964896 load */
    /* @3964904 constant */
    /* @3964908 add */
    /* @3964912 load */
    /* @3964920 call */
    GM_SITE(vm, 143, 3964920);
    v31 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964928 cast */
    /* @3964932 bt */
    v32 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v31, VAL(4)));
    if (TRUTH(v32)) goto L_3965032;
    /* @3964936 constant */
    /* @3964940 cast */
    /* @3964944 load */
    /* @3964952 constant */
    /* @3964956 add */
    /* @3964960 load */
    /* @3964968 call */
    GM_SITE(vm, 143, 3964968);
    v33 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3964976 cast */
    /* @3964980 bt */
    v34 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v33, VAL(6)));
    if (TRUTH(v34)) goto L_3965032;
    /* @3964984 constant */
    /* @3964988 cast */
    /* @3964992 load */
    /* @3965000 constant */
    /* @3965004 add */
    /* @3965008 load */
    /* @3965016 call */
    GM_SITE(vm, 143, 3965016);
    v35 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3965024 cast */
    /* @3965028 b */
    v36 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v35, VAL(7)));
    p3965036_0 = v36;
    goto L_3965036;
    L_3965032: ;
    /* @3965032 constant */
    p3965036_0 = VAL(1);
    L_3965036: ;
    /* @3965036 bf */
    if (!TRUTH(p3965036_0)) goto L_3965052;
    /* @3965040 constant */
    /* @3965044 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3965052: ;
    /* @3965052 load */
    /* @3965060 constant */
    /* @3965064 cmp */
    /* @3965068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpwolffrozen") == VAL(1)))) goto L_3965116;
    /* @3965072 constant */
    /* @3965080 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3965088 constant */
    /* @3965092 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3965100 constant */
    /* @3965104 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3965112 b */
    goto L_3965132;
    L_3965116: ;
    /* @3965116 constant */
    /* @3965124 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3965132: ;
    /* @3965132 load */
    /* @3965140 constant */
    /* @3965144 cmp */
    /* @3965148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3965196;
    /* @3965152 constant */
    /* @3965156 cast */
    /* @3965160 constant */
    /* @3965164 cast */
    /* @3965168 call */
    GM_SITE(vm, 143, 3965168);
    /* @3965176 store */
    v37 = GM_CALL(vm, "choose", 2, VAL(105), VAL(106));
    GM_WRITE(vm, -1, "sprite_index", v37);
    /* @3965184 constant */
    /* @3965188 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3965196: ;
    /* @3965196 load */
    /* @3965204 constant */
    /* @3965208 cmp */
    /* @3965212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3965260;
    /* @3965216 constant */
    /* @3965220 cast */
    /* @3965224 constant */
    /* @3965228 cast */
    /* @3965232 call */
    GM_SITE(vm, 143, 3965232);
    /* @3965240 store */
    v38 = GM_CALL(vm, "choose", 2, VAL(105), VAL(106));
    GM_WRITE(vm, -1, "sprite_index", v38);
    /* @3965248 constant */
    /* @3965252 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3965260: ;
    /* @3965260 load */
    /* @3965268 constant */
    /* @3965272 cmp */
    /* @3965276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3965296;
    /* @3965280 constant */
    /* @3965288 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3965296: ;
    /* @3965296 load */
    /* @3965304 constant */
    /* @3965308 cmp */
    /* @3965312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3965340;
    /* @3965316 constant */
    /* @3965320 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3965328 constant */
    /* @3965332 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3965340: ;
    return;
}
