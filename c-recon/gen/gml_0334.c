/* generated from CODE 334 (gml_Object_obj_fireprojectile_Step_0), source start 4194268, end 4195160. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0334(GmVM* vm) {
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
    Val p4194692_0;
    Val v11;
    Val v12;
    /* @4194268 constant */
    /* @4194272 cast */
    /* @4194276 call */
    GM_SITE(vm, 334, 4194276);
    /* @4194284 cast */
    /* @4194288 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4194408;
    /* @4194292 constant */
    /* @4194296 cast */
    /* @4194300 load */
    /* @4194308 load */
    /* @4194316 add */
    /* @4194320 load */
    /* @4194328 load */
    /* @4194336 add */
    /* @4194340 call */
    GM_SITE(vm, 334, 4194340);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4194348 cast */
    /* @4194352 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4194408;
    /* @4194356 constant */
    /* @4194360 cast */
    /* @4194364 load */
    /* @4194372 load */
    /* @4194380 call */
    GM_SITE(vm, 334, 4194380);
    /* @4194388 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4194396 call */
    GM_SITE(vm, 334, 4194396);
    /* @4194404 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4194408: ;
    /* @4194408 constant */
    /* @4194412 cast */
    /* @4194416 load */
    /* @4194424 load */
    /* @4194432 call */
    GM_SITE(vm, 334, 4194432);
    /* @4194440 cast */
    /* @4194444 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4194564;
    /* @4194448 constant */
    /* @4194452 cast */
    /* @4194456 load */
    /* @4194464 load */
    /* @4194472 call */
    GM_SITE(vm, 334, 4194472);
    /* @4194480 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4194488 constant */
    /* @4194500 load */
    /* @4194508 cast */
    /* @4194512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(0.5));
    /* @4194520 constant */
    /* @4194532 load */
    /* @4194540 cast */
    /* @4194544 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_yscale", VAL(0.5));
    /* @4194552 call */
    GM_SITE(vm, 334, 4194552);
    /* @4194560 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4194564: ;
    /* @4194564 constant */
    /* @4194568 cast */
    /* @4194572 load */
    /* @4194580 load */
    /* @4194588 add */
    /* @4194592 load */
    /* @4194600 load */
    /* @4194608 add */
    /* @4194612 call */
    GM_SITE(vm, 334, 4194612);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4194620 cast */
    /* @4194624 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4195160;
    /* @4194628 load */
    /* @4194636 constant */
    /* @4194640 cmp */
    /* @4194644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4194688;
    /* @4194648 load */
    /* @4194656 constant */
    /* @4194660 cmp */
    /* @4194664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4194688;
    /* @4194668 load */
    /* @4194676 constant */
    /* @4194680 cmp */
    /* @4194684 b */
    p4194692_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4194692;
    L_4194688: ;
    /* @4194688 constant */
    p4194692_0 = VAL(0);
    L_4194692: ;
    /* @4194692 bf */
    if (!TRUTH(p4194692_0)) goto L_4195040;
    /* @4194696 load */
    /* @4194704 constant */
    /* @4194708 cmp */
    /* @4194712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4194756;
    /* @4194716 constant */
    /* @4194720 cast */
    /* @4194724 constant */
    /* @4194728 cast */
    /* @4194732 constant */
    /* @4194736 cast */
    /* @4194740 call */
    GM_SITE(vm, 334, 4194740);
    /* @4194748 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4194752 b */
    goto L_4194776;
    L_4194756: ;
    /* @4194756 load */
    /* @4194764 constant */
    /* @4194768 cmp */
    /* @4194772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4194776;
    L_4194776: ;
    /* @4194776 constant */
    /* @4194780 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4194788 constant */
    /* @4194792 cast */
    /* @4194796 load */
    /* @4194804 load */
    /* @4194812 load */
    /* @4194820 load */
    /* @4194828 call */
    GM_SITE(vm, 334, 4194828);
    /* @4194836 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4194840 load */
    /* @4194848 load */
    /* @4194856 cmp */
    /* @4194860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4194892;
    /* @4194864 constant */
    /* @4194868 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4194876 constant */
    /* @4194880 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4194888 b */
    goto L_4194940;
    L_4194892: ;
    /* @4194892 load */
    /* @4194900 load */
    /* @4194908 cmp */
    /* @4194912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4194940;
    /* @4194916 constant */
    /* @4194920 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4194928 constant */
    /* @4194932 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4194940: ;
    /* @4194940 constant */
    /* @4194944 constant */
    /* @4194948 constant */
    /* @4194952 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4194960 constant */
    /* @4194964 constant */
    /* @4194968 constant */
    /* @4194972 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4194980 constant */
    /* @4194984 constant */
    /* @4194988 constant */
    /* @4194992 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4195000 load */
    /* @4195008 constant */
    /* @4195012 sub */
    /* @4195016 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4195024 call */
    GM_SITE(vm, 334, 4195024);
    /* @4195032 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4195036 b */
    goto L_4195160;
    L_4195040: ;
    /* @4195040 load */
    /* @4195048 constant */
    /* @4195052 cmp */
    /* @4195056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4195160;
    /* @4195060 constant */
    /* @4195064 cast */
    /* @4195068 call */
    GM_SITE(vm, 334, 4195068);
    /* @4195076 constant */
    /* @4195080 cmp */
    /* @4195084 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v11)) goto L_4195160;
    /* @4195088 constant */
    /* @4195092 cast */
    /* @4195096 call */
    GM_SITE(vm, 334, 4195096);
    /* @4195104 cast */
    /* @4195108 not */
    /* @4195112 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v12)) goto L_4195160;
    /* @4195116 constant */
    /* @4195120 cast */
    /* @4195124 load */
    /* @4195132 constant */
    /* @4195136 sub */
    /* @4195140 load */
    /* @4195148 call */
    GM_SITE(vm, 334, 4195148);
    /* @4195156 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4195160: ;
    return;
}
