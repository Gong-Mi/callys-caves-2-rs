/* generated from CODE 336 (gml_Object_obj_boss3projectile_Step_0), source start 4195244, end 4196048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0336(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    Val p4195580_0;
    Val v10;
    Val v11;
    /* @4195244 constant */
    /* @4195248 cast */
    /* @4195252 call */
    GM_SITE(vm, 336, 4195252);
    /* @4195260 cast */
    /* @4195264 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4195384;
    /* @4195268 constant */
    /* @4195272 cast */
    /* @4195276 load */
    /* @4195284 load */
    /* @4195292 add */
    /* @4195296 load */
    /* @4195304 load */
    /* @4195312 add */
    /* @4195316 call */
    GM_SITE(vm, 336, 4195316);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4195324 cast */
    /* @4195328 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4195384;
    /* @4195332 constant */
    /* @4195336 cast */
    /* @4195340 load */
    /* @4195348 load */
    /* @4195356 call */
    GM_SITE(vm, 336, 4195356);
    /* @4195364 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4195372 call */
    GM_SITE(vm, 336, 4195372);
    /* @4195380 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4195384: ;
    /* @4195384 constant */
    /* @4195388 cast */
    /* @4195392 load */
    /* @4195400 load */
    /* @4195408 call */
    GM_SITE(vm, 336, 4195408);
    /* @4195416 cast */
    /* @4195420 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4195436;
    /* @4195424 call */
    GM_SITE(vm, 336, 4195424);
    /* @4195432 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4195436: ;
    /* @4195436 load */
    /* @4195444 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4195452 constant */
    /* @4195456 cast */
    /* @4195460 load */
    /* @4195468 load */
    /* @4195476 add */
    /* @4195480 load */
    /* @4195488 load */
    /* @4195496 add */
    /* @4195500 call */
    GM_SITE(vm, 336, 4195500);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v8 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4195508 cast */
    /* @4195512 bf */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, v7, v8, VAL(0)));
    if (!TRUTH(v9)) goto L_4196048;
    /* @4195516 load */
    /* @4195524 constant */
    /* @4195528 cmp */
    /* @4195532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4195576;
    /* @4195536 load */
    /* @4195544 constant */
    /* @4195548 cmp */
    /* @4195552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4195576;
    /* @4195556 load */
    /* @4195564 constant */
    /* @4195568 cmp */
    /* @4195572 b */
    p4195580_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4195580;
    L_4195576: ;
    /* @4195576 constant */
    p4195580_0 = VAL(0);
    L_4195580: ;
    /* @4195580 bf */
    if (!TRUTH(p4195580_0)) goto L_4195928;
    /* @4195584 load */
    /* @4195592 constant */
    /* @4195596 cmp */
    /* @4195600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4195644;
    /* @4195604 constant */
    /* @4195608 cast */
    /* @4195612 constant */
    /* @4195616 cast */
    /* @4195620 constant */
    /* @4195624 cast */
    /* @4195628 call */
    GM_SITE(vm, 336, 4195628);
    /* @4195636 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4195640 b */
    goto L_4195664;
    L_4195644: ;
    /* @4195644 load */
    /* @4195652 constant */
    /* @4195656 cmp */
    /* @4195660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4195664;
    L_4195664: ;
    /* @4195664 constant */
    /* @4195668 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4195676 constant */
    /* @4195680 cast */
    /* @4195684 load */
    /* @4195692 load */
    /* @4195700 load */
    /* @4195708 load */
    /* @4195716 call */
    GM_SITE(vm, 336, 4195716);
    /* @4195724 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4195728 load */
    /* @4195736 load */
    /* @4195744 cmp */
    /* @4195748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4195780;
    /* @4195752 constant */
    /* @4195756 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4195764 constant */
    /* @4195768 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4195776 b */
    goto L_4195828;
    L_4195780: ;
    /* @4195780 load */
    /* @4195788 load */
    /* @4195796 cmp */
    /* @4195800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4195828;
    /* @4195804 constant */
    /* @4195808 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4195816 constant */
    /* @4195820 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4195828: ;
    /* @4195828 constant */
    /* @4195832 constant */
    /* @4195836 constant */
    /* @4195840 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4195848 constant */
    /* @4195852 constant */
    /* @4195856 constant */
    /* @4195860 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4195868 constant */
    /* @4195872 constant */
    /* @4195876 constant */
    /* @4195880 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4195888 load */
    /* @4195896 constant */
    /* @4195900 sub */
    /* @4195904 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4195912 call */
    GM_SITE(vm, 336, 4195912);
    /* @4195920 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4195924 b */
    goto L_4196048;
    L_4195928: ;
    /* @4195928 constant */
    /* @4195932 cast */
    /* @4195936 call */
    GM_SITE(vm, 336, 4195936);
    /* @4195944 constant */
    /* @4195948 cmp */
    /* @4195952 bf */
    v10 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v10)) goto L_4196048;
    /* @4195956 load */
    /* @4195964 constant */
    /* @4195968 cmp */
    /* @4195972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4196048;
    /* @4195976 constant */
    /* @4195980 cast */
    /* @4195984 call */
    GM_SITE(vm, 336, 4195984);
    /* @4195992 cast */
    /* @4195996 not */
    /* @4196000 bf */
    v11 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v11)) goto L_4196048;
    /* @4196004 constant */
    /* @4196008 cast */
    /* @4196012 load */
    /* @4196020 constant */
    /* @4196024 sub */
    /* @4196028 load */
    /* @4196036 call */
    GM_SITE(vm, 336, 4196036);
    /* @4196044 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4196048: ;
    return;
}
