/* generated from CODE 229 (gml_Object_obj_finalboss_Step_0), source start 4030772, end 4031520. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0229(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val p4031304_0;
    Val v5;
    Val p4031392_0;
    /* @4030772 load */
    /* @4030780 constant */
    /* @4030784 cmp */
    /* @4030788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4030816;
    /* @4030792 constant */
    /* @4030796 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4030804 constant */
    /* @4030808 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4030816: ;
    /* @4030816 load */
    /* @4030824 constant */
    /* @4030828 cmp */
    /* @4030832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4031520;
    /* @4030836 load */
    /* @4030844 constant */
    /* @4030848 cmp */
    /* @4030852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfinalboss") >= VAL(0)))) goto L_4030876;
    /* @4030856 constant */
    /* @4030860 constant */
    /* @4030864 constant */
    /* @4030868 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_4030876: ;
    /* @4030876 load */
    /* @4030884 constant */
    /* @4030888 cmp */
    /* @4030892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfinalboss") <= VAL(0)))) goto L_4030916;
    /* @4030896 constant */
    /* @4030900 constant */
    /* @4030904 constant */
    /* @4030908 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4030916: ;
    /* @4030916 constant */
    /* @4030920 constant */
    /* @4030924 load */
    /* @4030932 constant */
    /* @4030936 cmp */
    /* @4030940 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(1)) <= VAL(0)))) goto L_4030964;
    /* @4030944 constant */
    /* @4030948 constant */
    /* @4030952 constant */
    /* @4030956 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(180));
    L_4030964: ;
    /* @4030964 constant */
    /* @4030968 constant */
    /* @4030972 load */
    /* @4030980 constant */
    /* @4030984 cmp */
    /* @4030988 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(2)) <= VAL(0)))) goto L_4031012;
    /* @4030992 constant */
    /* @4030996 constant */
    /* @4031000 constant */
    /* @4031004 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(180));
    L_4031012: ;
    /* @4031012 constant */
    /* @4031016 constant */
    /* @4031020 load */
    /* @4031028 constant */
    /* @4031032 cmp */
    /* @4031036 bf */
    if (!TRUTH(NUMBOOL(GM_READ_ARR(vm, VAL(-1), "alarm", VAL(3)) <= VAL(0)))) goto L_4031060;
    /* @4031040 constant */
    /* @4031044 constant */
    /* @4031048 constant */
    /* @4031052 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(120));
    L_4031060: ;
    /* @4031060 constant */
    /* @4031064 cast */
    /* @4031068 load */
    /* @4031076 constant */
    /* @4031080 add */
    /* @4031084 load */
    /* @4031092 call */
    GM_SITE(vm, 229, 4031092);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4031100 cast */
    /* @4031104 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4031136;
    /* @4031108 constant */
    /* @4031112 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4031120 constant */
    /* @4031124 store */
    GM_WRITE(vm, -1, "falling", VAL(0));
    /* @4031132 b */
    goto L_4031168;
    L_4031136: ;
    /* @4031136 constant */
    /* @4031148 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    /* @4031156 constant */
    /* @4031160 store */
    GM_WRITE(vm, -1, "falling", VAL(1));
    L_4031168: ;
    /* @4031168 load */
    /* @4031176 constant */
    /* @4031180 cmp */
    /* @4031184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4031200;
    /* @4031188 constant */
    /* @4031192 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4031200: ;
    /* @4031200 load */
    /* @4031208 constant */
    /* @4031212 cmp */
    /* @4031216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4031232;
    /* @4031220 constant */
    /* @4031224 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4031232: ;
    /* @4031232 constant */
    /* @4031236 cast */
    /* @4031240 load */
    /* @4031248 load */
    /* @4031256 constant */
    /* @4031260 add */
    /* @4031264 call */
    GM_SITE(vm, 229, 4031264);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4031272 cast */
    /* @4031276 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_4031300;
    /* @4031280 load */
    /* @4031288 constant */
    /* @4031292 cmp */
    /* @4031296 b */
    p4031304_0 = NUMBOOL(GM_READ(vm, 34, "type") != VAL(2));
    goto L_4031304;
    L_4031300: ;
    /* @4031300 constant */
    p4031304_0 = VAL(0);
    L_4031304: ;
    /* @4031304 bf */
    if (!TRUTH(p4031304_0)) goto L_4031320;
    /* @4031308 constant */
    /* @4031312 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    L_4031320: ;
    /* @4031320 constant */
    /* @4031324 cast */
    /* @4031328 load */
    /* @4031336 load */
    /* @4031344 constant */
    /* @4031348 sub */
    /* @4031352 call */
    GM_SITE(vm, 229, 4031352);
    /* @4031360 cast */
    /* @4031364 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v5)) goto L_4031388;
    /* @4031368 load */
    /* @4031376 constant */
    /* @4031380 cmp */
    /* @4031384 b */
    p4031392_0 = NUMBOOL(GM_READ(vm, 34, "type") != VAL(2));
    goto L_4031392;
    L_4031388: ;
    /* @4031388 constant */
    p4031392_0 = VAL(0);
    L_4031392: ;
    /* @4031392 bf */
    if (!TRUTH(p4031392_0)) goto L_4031408;
    /* @4031396 constant */
    /* @4031400 store */
    GM_WRITE(vm, -1, "facing", VAL(1));
    L_4031408: ;
    /* @4031408 load */
    /* @4031416 constant */
    /* @4031420 cmp */
    /* @4031424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4031440;
    /* @4031428 constant */
    /* @4031432 store */
    GM_WRITE(vm, -1, "image_blend", VAL(255));
    L_4031440: ;
    /* @4031440 load */
    /* @4031448 constant */
    /* @4031452 cmp */
    /* @4031456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4031476;
    /* @4031460 constant */
    /* @4031468 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4031476: ;
    /* @4031476 load */
    /* @4031484 constant */
    /* @4031488 cmp */
    /* @4031492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4031520;
    /* @4031496 constant */
    /* @4031500 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4031508 constant */
    /* @4031512 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4031520: ;
    return;
}
