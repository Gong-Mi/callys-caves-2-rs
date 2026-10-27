/* generated from CODE 338 (gml_Object_obj_bone_Step_0), source start 4196108, end 4197000. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0338(GmVM* vm) {
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
    Val p4196468_0;
    Val v11;
    Val v12;
    Val v13;
    /* @4196108 constant */
    /* @4196112 cast */
    /* @4196116 call */
    GM_SITE(vm, 338, 4196116);
    /* @4196124 cast */
    /* @4196128 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4196248;
    /* @4196132 constant */
    /* @4196136 cast */
    /* @4196140 load */
    /* @4196148 load */
    /* @4196156 add */
    /* @4196160 load */
    /* @4196168 load */
    /* @4196176 add */
    /* @4196180 call */
    GM_SITE(vm, 338, 4196180);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4196188 cast */
    /* @4196192 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4196248;
    /* @4196196 constant */
    /* @4196200 cast */
    /* @4196204 load */
    /* @4196212 load */
    /* @4196220 call */
    GM_SITE(vm, 338, 4196220);
    /* @4196228 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4196236 call */
    GM_SITE(vm, 338, 4196236);
    /* @4196244 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4196248: ;
    /* @4196248 constant */
    /* @4196252 cast */
    /* @4196256 load */
    /* @4196264 load */
    /* @4196272 call */
    GM_SITE(vm, 338, 4196272);
    /* @4196280 cast */
    /* @4196284 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4196340;
    /* @4196288 constant */
    /* @4196292 cast */
    /* @4196296 load */
    /* @4196304 load */
    /* @4196312 call */
    GM_SITE(vm, 338, 4196312);
    /* @4196320 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4196328 call */
    GM_SITE(vm, 338, 4196328);
    /* @4196336 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4196340: ;
    /* @4196340 constant */
    /* @4196344 cast */
    /* @4196348 load */
    /* @4196356 load */
    /* @4196364 add */
    /* @4196368 load */
    /* @4196376 load */
    /* @4196384 add */
    /* @4196388 call */
    GM_SITE(vm, 338, 4196388);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4196396 cast */
    /* @4196400 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4196936;
    /* @4196404 load */
    /* @4196412 constant */
    /* @4196416 cmp */
    /* @4196420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4196464;
    /* @4196424 load */
    /* @4196432 constant */
    /* @4196436 cmp */
    /* @4196440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4196464;
    /* @4196444 load */
    /* @4196452 constant */
    /* @4196456 cmp */
    /* @4196460 b */
    p4196468_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4196468;
    L_4196464: ;
    /* @4196464 constant */
    p4196468_0 = VAL(0);
    L_4196468: ;
    /* @4196468 bf */
    if (!TRUTH(p4196468_0)) goto L_4196816;
    /* @4196472 load */
    /* @4196480 constant */
    /* @4196484 cmp */
    /* @4196488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4196532;
    /* @4196492 constant */
    /* @4196496 cast */
    /* @4196500 constant */
    /* @4196504 cast */
    /* @4196508 constant */
    /* @4196512 cast */
    /* @4196516 call */
    GM_SITE(vm, 338, 4196516);
    /* @4196524 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4196528 b */
    goto L_4196552;
    L_4196532: ;
    /* @4196532 load */
    /* @4196540 constant */
    /* @4196544 cmp */
    /* @4196548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4196552;
    L_4196552: ;
    /* @4196552 constant */
    /* @4196556 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4196564 constant */
    /* @4196568 cast */
    /* @4196572 load */
    /* @4196580 load */
    /* @4196588 load */
    /* @4196596 load */
    /* @4196604 call */
    GM_SITE(vm, 338, 4196604);
    /* @4196612 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4196616 load */
    /* @4196624 load */
    /* @4196632 cmp */
    /* @4196636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4196668;
    /* @4196640 constant */
    /* @4196644 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4196652 constant */
    /* @4196656 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4196664 b */
    goto L_4196716;
    L_4196668: ;
    /* @4196668 load */
    /* @4196676 load */
    /* @4196684 cmp */
    /* @4196688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4196716;
    /* @4196692 constant */
    /* @4196696 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4196704 constant */
    /* @4196708 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4196716: ;
    /* @4196716 constant */
    /* @4196720 constant */
    /* @4196724 constant */
    /* @4196728 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4196736 constant */
    /* @4196740 constant */
    /* @4196744 constant */
    /* @4196748 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4196756 constant */
    /* @4196760 constant */
    /* @4196764 constant */
    /* @4196768 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4196776 load */
    /* @4196784 constant */
    /* @4196788 sub */
    /* @4196792 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4196800 call */
    GM_SITE(vm, 338, 4196800);
    /* @4196808 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4196812 b */
    goto L_4196936;
    L_4196816: ;
    /* @4196816 load */
    /* @4196824 constant */
    /* @4196828 cmp */
    /* @4196832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4196936;
    /* @4196836 constant */
    /* @4196840 cast */
    /* @4196844 call */
    GM_SITE(vm, 338, 4196844);
    /* @4196852 constant */
    /* @4196856 cmp */
    /* @4196860 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v11)) goto L_4196936;
    /* @4196864 constant */
    /* @4196868 cast */
    /* @4196872 call */
    GM_SITE(vm, 338, 4196872);
    /* @4196880 cast */
    /* @4196884 not */
    /* @4196888 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v12)) goto L_4196936;
    /* @4196892 constant */
    /* @4196896 cast */
    /* @4196900 load */
    /* @4196908 constant */
    /* @4196912 sub */
    /* @4196916 load */
    /* @4196924 call */
    GM_SITE(vm, 338, 4196924);
    /* @4196932 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4196936: ;
    /* @4196936 constant */
    /* @4196940 cast */
    /* @4196944 call */
    GM_SITE(vm, 338, 4196944);
    /* @4196952 constant */
    /* @4196956 cmp */
    /* @4196960 bf */
    v13 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(34)) <= VAL(1));
    if (!TRUTH(v13)) goto L_4196976;
    /* @4196964 call */
    GM_SITE(vm, 338, 4196964);
    /* @4196972 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4196976: ;
    /* @4196976 load */
    /* @4196984 constant */
    /* @4196988 sub */
    /* @4196992 store */
    GM_WRITE(vm, -1, "image_angle", (GM_READ(vm, -1, "image_angle") - VAL(40)));
    L_4197000: ;
    return;
}
