/* generated from CODE 119 (gml_Object_obj_hulkingbandit_Alarm_1), source start 3942760, end 3943584. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0119(GmVM* vm) {
    Val v1;
    Val p3942884_0;
    Val v2;
    Val v3;
    Val v4;
    Val p3943256_0;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    /* @3942760 load */
    /* @3942768 constant */
    /* @3942772 cmp */
    /* @3942776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3942784;
    /* @3942780 b */
    goto L_3943584;
    L_3942784: ;
    /* @3942784 constant */
    /* @3942788 cast */
    /* @3942792 constant */
    /* @3942796 cast */
    /* @3942800 constant */
    /* @3942804 cast */
    /* @3942808 load */
    /* @3942816 load */
    /* @3942824 load */
    /* @3942832 load */
    /* @3942840 call */
    GM_SITE(vm, 119, 3942840);
    /* @3942848 cast */
    /* @3942852 not */
    /* @3942856 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "collision_line", 7, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(34), VAL(1), VAL(1))));
    if (!TRUTH(v1)) goto L_3942880;
    /* @3942860 load */
    /* @3942868 constant */
    /* @3942872 cmp */
    /* @3942876 b */
    p3942884_0 = NUMBOOL(GM_READ(vm, -1, "image_xscale") == VAL(1));
    goto L_3942884;
    L_3942880: ;
    /* @3942880 constant */
    p3942884_0 = VAL(0);
    L_3942884: ;
    /* @3942884 bf */
    if (!TRUTH(p3942884_0)) goto L_3943156;
    /* @3942888 constant */
    /* @3942892 cast */
    /* @3942896 call */
    GM_SITE(vm, 119, 3942896);
    /* @3942904 constant */
    /* @3942908 cmp */
    /* @3942912 bf */
    v2 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(200));
    if (!TRUTH(v2)) goto L_3943152;
    /* @3942916 load */
    /* @3942924 constant */
    /* @3942928 cmp */
    /* @3942932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hphulkingbanditfrozen") == VAL(0)))) goto L_3943152;
    /* @3942936 constant */
    /* @3942940 store */
    GM_WRITE(vm, -1, "shooting", VAL(1));
    /* @3942948 constant */
    /* @3942952 constant */
    /* @3942956 constant */
    /* @3942960 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(8));
    /* @3942968 constant */
    /* @3942972 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3942980 constant */
    /* @3942984 store */
    GM_WRITE(vm, -1, "friction", VAL(0));
    /* @3942992 load */
    /* @3943000 constant */
    /* @3943004 cmp */
    /* @3943008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3943016;
    /* @3943012 b */
    goto L_3943072;
    L_3943016: ;
    /* @3943016 load */
    /* @3943024 constant */
    /* @3943028 cmp */
    /* @3943032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3943072;
    /* @3943036 constant */
    /* @3943040 cast */
    /* @3943044 constant */
    /* @3943048 cast */
    /* @3943052 constant */
    /* @3943056 cast */
    /* @3943060 call */
    GM_SITE(vm, 119, 3943060);
    /* @3943068 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    L_3943072: ;
    /* @3943072 constant */
    /* @3943076 cast */
    /* @3943080 load */
    /* @3943088 constant */
    /* @3943092 sub */
    /* @3943096 load */
    /* @3943104 constant */
    /* @3943108 sub */
    /* @3943112 call */
    GM_SITE(vm, 119, 3943112);
    /* @3943120 store */
    v3 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), (GM_READ(vm, -1, "y") - VAL(15)), VAL(51));
    GM_WRITE(vm, -1, "i1", v3);
    /* @3943128 constant */
    /* @3943132 load */
    /* @3943140 cast */
    /* @3943144 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(10));
    L_3943152: ;
    /* @3943152 b */
    goto L_3943524;
    L_3943156: ;
    /* @3943156 constant */
    /* @3943160 cast */
    /* @3943164 constant */
    /* @3943168 cast */
    /* @3943172 constant */
    /* @3943176 cast */
    /* @3943180 load */
    /* @3943188 load */
    /* @3943196 load */
    /* @3943204 load */
    /* @3943212 call */
    GM_SITE(vm, 119, 3943212);
    /* @3943220 cast */
    /* @3943224 not */
    /* @3943228 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "collision_line", 7, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(34), VAL(1), VAL(1))));
    if (!TRUTH(v4)) goto L_3943252;
    /* @3943232 load */
    /* @3943240 constant */
    /* @3943244 cmp */
    /* @3943248 b */
    p3943256_0 = NUMBOOL(GM_READ(vm, -1, "image_xscale") == VAL(-1));
    goto L_3943256;
    L_3943252: ;
    /* @3943252 constant */
    p3943256_0 = VAL(0);
    L_3943256: ;
    /* @3943256 bf */
    if (!TRUTH(p3943256_0)) goto L_3943524;
    /* @3943260 constant */
    /* @3943264 cast */
    /* @3943268 call */
    GM_SITE(vm, 119, 3943268);
    /* @3943276 constant */
    /* @3943280 cmp */
    /* @3943284 bf */
    v5 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(200));
    if (!TRUTH(v5)) goto L_3943524;
    /* @3943288 load */
    /* @3943296 constant */
    /* @3943300 cmp */
    /* @3943304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hphulkingbanditfrozen") == VAL(0)))) goto L_3943524;
    /* @3943308 constant */
    /* @3943312 store */
    GM_WRITE(vm, -1, "shooting", VAL(1));
    /* @3943320 constant */
    /* @3943324 constant */
    /* @3943328 constant */
    /* @3943332 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(8));
    /* @3943340 constant */
    /* @3943344 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3943352 constant */
    /* @3943356 store */
    GM_WRITE(vm, -1, "friction", VAL(0));
    /* @3943364 load */
    /* @3943372 constant */
    /* @3943376 cmp */
    /* @3943380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3943388;
    /* @3943384 b */
    goto L_3943444;
    L_3943388: ;
    /* @3943388 load */
    /* @3943396 constant */
    /* @3943400 cmp */
    /* @3943404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3943444;
    /* @3943408 constant */
    /* @3943412 cast */
    /* @3943416 constant */
    /* @3943420 cast */
    /* @3943424 constant */
    /* @3943428 cast */
    /* @3943432 call */
    GM_SITE(vm, 119, 3943432);
    /* @3943440 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    L_3943444: ;
    /* @3943444 constant */
    /* @3943448 cast */
    /* @3943452 load */
    /* @3943460 constant */
    /* @3943464 sub */
    /* @3943468 load */
    /* @3943476 constant */
    /* @3943480 add */
    /* @3943484 call */
    GM_SITE(vm, 119, 3943484);
    v6 = GM_ADD(GM_READ(vm, -1, "x"), VAL(20));
    /* @3943492 store */
    v7 = GM_CALL(vm, "instance_create", 3, v6, (GM_READ(vm, -1, "y") - VAL(15)), VAL(51));
    GM_WRITE(vm, -1, "i1", v7);
    /* @3943500 constant */
    /* @3943504 load */
    /* @3943512 cast */
    /* @3943516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(-10));
    L_3943524: ;
    /* @3943524 constant */
    /* @3943528 cast */
    /* @3943532 call */
    GM_SITE(vm, 119, 3943532);
    /* @3943540 constant */
    /* @3943544 cmp */
    /* @3943548 bf */
    v8 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(200));
    if (!TRUTH(v8)) goto L_3943564;
    /* @3943552 constant */
    /* @3943556 store */
    GM_WRITE(vm, -1, "shooting", VAL(0));
    L_3943564: ;
    /* @3943564 constant */
    /* @3943568 constant */
    /* @3943572 constant */
    /* @3943576 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(45));
    L_3943584: ;
    return;
}
