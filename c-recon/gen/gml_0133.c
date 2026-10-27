/* generated from CODE 133 (gml_Object_obj_enemy2_Step_0), source start 3956368, end 3957468. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0133(GmVM* vm) {
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
    /* @3956368 load */
    /* @3956376 constant */
    /* @3956380 cmp */
    /* @3956384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptwo") >= VAL(0)))) goto L_3956408;
    /* @3956388 constant */
    /* @3956392 constant */
    /* @3956396 constant */
    /* @3956400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3956408: ;
    /* @3956408 load */
    /* @3956416 constant */
    /* @3956420 cmp */
    /* @3956424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptwo") <= VAL(0)))) goto L_3956448;
    /* @3956428 constant */
    /* @3956432 constant */
    /* @3956436 constant */
    /* @3956440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3956448: ;
    /* @3956448 constant */
    /* @3956452 cast */
    /* @3956456 load */
    /* @3956464 load */
    /* @3956472 add */
    /* @3956476 load */
    /* @3956484 call */
    GM_SITE(vm, 133, 3956484);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3956492 cast */
    /* @3956496 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3956540;
    /* @3956500 constant */
    /* @3956504 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3956512 constant */
    /* @3956516 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3956524 constant */
    /* @3956528 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3956536 b */
    goto L_3956572;
    L_3956540: ;
    /* @3956540 constant */
    /* @3956552 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3956560 constant */
    /* @3956564 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3956572: ;
    /* @3956572 load */
    /* @3956580 constant */
    /* @3956584 cmp */
    /* @3956588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3956656;
    /* @3956592 load */
    /* @3956600 constant */
    /* @3956604 cmp */
    /* @3956608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(0)))) goto L_3956656;
    /* @3956612 load */
    /* @3956620 constant */
    /* @3956624 cmp */
    /* @3956628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(0)))) goto L_3956656;
    /* @3956632 constant */
    /* @3956636 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @3956644 constant */
    /* @3956648 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(62));
    L_3956656: ;
    /* @3956656 load */
    /* @3956664 constant */
    /* @3956668 cmp */
    /* @3956672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3956740;
    /* @3956676 load */
    /* @3956684 constant */
    /* @3956688 cmp */
    /* @3956692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(0)))) goto L_3956740;
    /* @3956696 load */
    /* @3956704 constant */
    /* @3956708 cmp */
    /* @3956712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(0)))) goto L_3956740;
    /* @3956716 constant */
    /* @3956720 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3956728 constant */
    /* @3956732 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(62));
    L_3956740: ;
    /* @3956740 constant */
    /* @3956744 cast */
    /* @3956748 load */
    /* @3956756 load */
    /* @3956764 constant */
    /* @3956768 add */
    /* @3956772 call */
    GM_SITE(vm, 133, 3956772);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3956780 cast */
    /* @3956784 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_3956820;
    /* @3956788 load */
    /* @3956796 constant */
    /* @3956800 cmp */
    /* @3956804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 34, "type") != VAL(2)))) goto L_3956820;
    /* @3956808 constant */
    /* @3956812 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3956820: ;
    /* @3956820 constant */
    /* @3956824 cast */
    /* @3956828 load */
    /* @3956836 load */
    /* @3956844 constant */
    /* @3956848 sub */
    /* @3956852 call */
    GM_SITE(vm, 133, 3956852);
    /* @3956860 cast */
    /* @3956864 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v5)) goto L_3956900;
    /* @3956868 load */
    /* @3956876 constant */
    /* @3956880 cmp */
    /* @3956884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 34, "type") != VAL(2)))) goto L_3956900;
    /* @3956888 constant */
    /* @3956892 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3956900: ;
    /* @3956900 load */
    /* @3956908 constant */
    /* @3956912 cmp */
    /* @3956916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") != VAL(0)))) goto L_3956992;
    /* @3956920 constant */
    /* @3956924 cast */
    /* @3956928 load */
    /* @3956936 constant */
    /* @3956940 sub */
    /* @3956944 load */
    /* @3956952 load */
    /* @3956960 add */
    /* @3956964 call */
    GM_SITE(vm, 133, 3956964);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @3956972 cast */
    /* @3956976 bf */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, v6, (GM_READ(vm, -1, "y") - VAL(5)), VAL(34)));
    if (!TRUTH(v7)) goto L_3956992;
    /* @3956980 constant */
    /* @3956984 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3956992: ;
    /* @3956992 load */
    /* @3957000 constant */
    /* @3957004 cmp */
    /* @3957008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hptwofrozen") == VAL(1)))) goto L_3957056;
    /* @3957012 constant */
    /* @3957020 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3957028 constant */
    /* @3957032 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3957040 constant */
    /* @3957044 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3957052 b */
    goto L_3957072;
    L_3957056: ;
    /* @3957056 constant */
    /* @3957064 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3957072: ;
    /* @3957072 constant */
    /* @3957076 cast */
    /* @3957080 load */
    /* @3957088 constant */
    /* @3957092 add */
    /* @3957096 load */
    /* @3957104 constant */
    /* @3957108 add */
    /* @3957112 call */
    GM_SITE(vm, 133, 3957112);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(27));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3957120 cast */
    /* @3957124 not */
    /* @3957128 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(34))));
    if (!TRUTH(v10)) goto L_3957192;
    /* @3957132 constant */
    /* @3957136 cast */
    /* @3957140 load */
    /* @3957148 constant */
    /* @3957152 add */
    /* @3957156 load */
    /* @3957164 call */
    GM_SITE(vm, 133, 3957164);
    v11 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3957172 cast */
    /* @3957176 bf */
    v12 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v11, VAL(34)));
    if (!TRUTH(v12)) goto L_3957192;
    /* @3957180 constant */
    /* @3957184 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_3957192: ;
    /* @3957192 constant */
    /* @3957196 cast */
    /* @3957200 load */
    /* @3957208 constant */
    /* @3957212 add */
    /* @3957216 load */
    /* @3957224 constant */
    /* @3957228 sub */
    /* @3957232 call */
    GM_SITE(vm, 133, 3957232);
    v13 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3957240 cast */
    /* @3957244 not */
    /* @3957248 bf */
    v14 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(26)), v13, VAL(34))));
    if (!TRUTH(v14)) goto L_3957312;
    /* @3957252 constant */
    /* @3957256 cast */
    /* @3957260 load */
    /* @3957268 constant */
    /* @3957272 add */
    /* @3957276 load */
    /* @3957284 call */
    GM_SITE(vm, 133, 3957284);
    v15 = GM_ADD(GM_READ(vm, -1, "y"), VAL(27));
    /* @3957292 cast */
    /* @3957296 bf */
    v16 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v15, VAL(34)));
    if (!TRUTH(v16)) goto L_3957312;
    /* @3957300 constant */
    /* @3957304 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_3957312: ;
    /* @3957312 load */
    /* @3957320 constant */
    /* @3957324 cmp */
    /* @3957328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3957344;
    /* @3957332 constant */
    /* @3957336 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(60));
    L_3957344: ;
    /* @3957344 load */
    /* @3957352 constant */
    /* @3957356 cmp */
    /* @3957360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3957388;
    /* @3957364 constant */
    /* @3957368 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(60));
    /* @3957376 constant */
    /* @3957380 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3957388: ;
    /* @3957388 load */
    /* @3957396 constant */
    /* @3957400 cmp */
    /* @3957404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3957424;
    /* @3957408 constant */
    /* @3957416 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3957424: ;
    /* @3957424 load */
    /* @3957432 constant */
    /* @3957436 cmp */
    /* @3957440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3957468;
    /* @3957444 constant */
    /* @3957448 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3957456 constant */
    /* @3957460 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3957468: ;
    return;
}
