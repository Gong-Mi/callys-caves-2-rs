/* generated from CODE 98 (gml_Object_obj_zombie_Step_0), source start 3931916, end 3932928. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0098(GmVM* vm) {
    Val v1;
    Val p3932004_0;
    Val p3932092_0;
    Val v2;
    Val v3;
    Val v4;
    Val p3932544_0;
    Val v5;
    Val p3932640_0;
    Val v6;
    /* @3931916 constant */
    /* @3931920 cast */
    /* @3931924 call */
    GM_SITE(vm, 98, 3931924);
    /* @3931932 constant */
    /* @3931936 cmp */
    /* @3931940 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(50));
    if (!TRUTH(v1)) goto L_3931956;
    /* @3931944 constant */
    /* @3931948 store */
    GM_WRITE(vm, -1, "chasing", VAL(1));
    L_3931956: ;
    /* @3931956 load */
    /* @3931964 constant */
    /* @3931968 cmp */
    /* @3931972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(1)))) goto L_3932000;
    /* @3931976 load */
    /* @3931984 load */
    /* @3931992 cmp */
    /* @3931996 b */
    p3932004_0 = NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x"));
    goto L_3932004;
    L_3932000: ;
    /* @3932000 constant */
    p3932004_0 = VAL(0);
    L_3932004: ;
    /* @3932004 bf */
    if (!TRUTH(p3932004_0)) goto L_3932044;
    /* @3932008 constant */
    /* @3932012 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3932020 constant */
    /* @3932024 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @3932032 constant */
    /* @3932036 store */
    GM_WRITE(vm, -1, "hspeed", VAL(1));
    L_3932044: ;
    /* @3932044 load */
    /* @3932052 constant */
    /* @3932056 cmp */
    /* @3932060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(1)))) goto L_3932088;
    /* @3932064 load */
    /* @3932072 load */
    /* @3932080 cmp */
    /* @3932084 b */
    p3932092_0 = NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x"));
    goto L_3932092;
    L_3932088: ;
    /* @3932088 constant */
    p3932092_0 = VAL(0);
    L_3932092: ;
    /* @3932092 bf */
    if (!TRUTH(p3932092_0)) goto L_3932132;
    /* @3932096 constant */
    /* @3932100 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    /* @3932108 constant */
    /* @3932112 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3932120 constant */
    /* @3932124 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-1));
    L_3932132: ;
    /* @3932132 load */
    /* @3932140 constant */
    /* @3932144 cmp */
    /* @3932148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpzombie") >= VAL(0)))) goto L_3932172;
    /* @3932152 constant */
    /* @3932156 constant */
    /* @3932160 constant */
    /* @3932164 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_3932172: ;
    /* @3932172 load */
    /* @3932180 constant */
    /* @3932184 cmp */
    /* @3932188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpzombie") <= VAL(0)))) goto L_3932212;
    /* @3932192 constant */
    /* @3932196 constant */
    /* @3932200 constant */
    /* @3932204 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_3932212: ;
    /* @3932212 constant */
    /* @3932216 cast */
    /* @3932220 load */
    /* @3932228 load */
    /* @3932236 add */
    /* @3932240 load */
    /* @3932248 call */
    GM_SITE(vm, 98, 3932248);
    v2 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @3932256 cast */
    /* @3932260 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v2, VAL(34)));
    if (!TRUTH(v3)) goto L_3932304;
    /* @3932264 constant */
    /* @3932268 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @3932276 constant */
    /* @3932280 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3932288 constant */
    /* @3932292 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @3932300 b */
    goto L_3932336;
    L_3932304: ;
    /* @3932304 constant */
    /* @3932316 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @3932324 constant */
    /* @3932328 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_3932336: ;
    /* @3932336 load */
    /* @3932344 constant */
    /* @3932348 cmp */
    /* @3932352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3932400;
    /* @3932356 load */
    /* @3932364 constant */
    /* @3932368 cmp */
    /* @3932372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(0)))) goto L_3932400;
    /* @3932376 constant */
    /* @3932380 store */
    GM_WRITE(vm, -1, "hspeed", VAL(3));
    /* @3932388 constant */
    /* @3932392 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    L_3932400: ;
    /* @3932400 load */
    /* @3932408 constant */
    /* @3932412 cmp */
    /* @3932416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3932464;
    /* @3932420 load */
    /* @3932428 constant */
    /* @3932432 cmp */
    /* @3932436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "chasing") == VAL(0)))) goto L_3932464;
    /* @3932440 constant */
    /* @3932444 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-3));
    /* @3932452 constant */
    /* @3932456 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_3932464: ;
    /* @3932464 load */
    /* @3932472 constant */
    /* @3932476 cmp */
    /* @3932480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3932540;
    /* @3932484 constant */
    /* @3932488 cast */
    /* @3932492 load */
    /* @3932500 constant */
    /* @3932504 sub */
    /* @3932508 load */
    /* @3932516 constant */
    /* @3932520 add */
    /* @3932524 call */
    GM_SITE(vm, 98, 3932524);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3932532 cast */
    /* @3932536 b */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(4)), VAL(34)));
    p3932544_0 = v5;
    goto L_3932544;
    L_3932540: ;
    /* @3932540 constant */
    p3932544_0 = VAL(0);
    L_3932544: ;
    /* @3932544 bf */
    if (!TRUTH(p3932544_0)) goto L_3932560;
    /* @3932548 constant */
    /* @3932552 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3932560: ;
    /* @3932560 load */
    /* @3932568 constant */
    /* @3932572 cmp */
    /* @3932576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3932636;
    /* @3932580 constant */
    /* @3932584 cast */
    /* @3932588 load */
    /* @3932596 constant */
    /* @3932600 sub */
    /* @3932604 load */
    /* @3932612 constant */
    /* @3932616 sub */
    /* @3932620 call */
    GM_SITE(vm, 98, 3932620);
    /* @3932628 cast */
    /* @3932632 b */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(4)), VAL(34)));
    p3932640_0 = v6;
    goto L_3932640;
    L_3932636: ;
    /* @3932636 constant */
    p3932640_0 = VAL(0);
    L_3932640: ;
    /* @3932640 bf */
    if (!TRUTH(p3932640_0)) goto L_3932656;
    /* @3932644 constant */
    /* @3932648 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_3932656: ;
    /* @3932656 load */
    /* @3932664 constant */
    /* @3932668 cmp */
    /* @3932672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpzombiefrozen") == VAL(1)))) goto L_3932720;
    /* @3932676 constant */
    /* @3932684 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @3932692 constant */
    /* @3932696 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3932704 constant */
    /* @3932708 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3932716 b */
    goto L_3932736;
    L_3932720: ;
    /* @3932720 constant */
    /* @3932728 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_3932736: ;
    /* @3932736 load */
    /* @3932744 constant */
    /* @3932748 cmp */
    /* @3932752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_3932772;
    /* @3932756 constant */
    /* @3932760 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(108));
    /* @3932768 b */
    goto L_3932788;
    L_3932772: ;
    /* @3932772 load */
    /* @3932780 store */
    GM_WRITE(vm, -1, "sprite_index", GM_READ(vm, -1, "zombiesprite"));
    L_3932788: ;
    /* @3932788 load */
    /* @3932796 constant */
    /* @3932800 cmp */
    /* @3932804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_3932848;
    /* @3932808 constant */
    /* @3932812 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(108));
    /* @3932820 constant */
    /* @3932824 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3932832 constant */
    /* @3932836 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3932844 b */
    goto L_3932848;
    L_3932848: ;
    /* @3932848 load */
    /* @3932856 constant */
    /* @3932860 cmp */
    /* @3932864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_3932884;
    /* @3932868 constant */
    /* @3932876 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_3932884: ;
    /* @3932884 load */
    /* @3932892 constant */
    /* @3932896 cmp */
    /* @3932900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3932928;
    /* @3932904 constant */
    /* @3932908 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @3932916 constant */
    /* @3932920 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_3932928: ;
    return;
}
