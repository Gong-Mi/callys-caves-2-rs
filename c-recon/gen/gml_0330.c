/* generated from CODE 330 (gml_Object_obj_fireball_Step_0), source start 4192156, end 4193048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0330(GmVM* vm) {
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
    Val p4192580_0;
    Val v11;
    Val v12;
    /* @4192156 constant */
    /* @4192160 cast */
    /* @4192164 call */
    GM_SITE(vm, 330, 4192164);
    /* @4192172 cast */
    /* @4192176 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4192296;
    /* @4192180 constant */
    /* @4192184 cast */
    /* @4192188 load */
    /* @4192196 load */
    /* @4192204 add */
    /* @4192208 load */
    /* @4192216 load */
    /* @4192224 add */
    /* @4192228 call */
    GM_SITE(vm, 330, 4192228);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4192236 cast */
    /* @4192240 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4192296;
    /* @4192244 constant */
    /* @4192248 cast */
    /* @4192252 load */
    /* @4192260 load */
    /* @4192268 call */
    GM_SITE(vm, 330, 4192268);
    /* @4192276 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4192284 call */
    GM_SITE(vm, 330, 4192284);
    /* @4192292 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4192296: ;
    /* @4192296 constant */
    /* @4192300 cast */
    /* @4192304 load */
    /* @4192312 load */
    /* @4192320 call */
    GM_SITE(vm, 330, 4192320);
    /* @4192328 cast */
    /* @4192332 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4192452;
    /* @4192336 constant */
    /* @4192340 cast */
    /* @4192344 load */
    /* @4192352 load */
    /* @4192360 call */
    GM_SITE(vm, 330, 4192360);
    /* @4192368 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4192376 constant */
    /* @4192388 load */
    /* @4192396 cast */
    /* @4192400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(0.5));
    /* @4192408 constant */
    /* @4192420 load */
    /* @4192428 cast */
    /* @4192432 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_yscale", VAL(0.5));
    /* @4192440 call */
    GM_SITE(vm, 330, 4192440);
    /* @4192448 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4192452: ;
    /* @4192452 constant */
    /* @4192456 cast */
    /* @4192460 load */
    /* @4192468 load */
    /* @4192476 add */
    /* @4192480 load */
    /* @4192488 load */
    /* @4192496 add */
    /* @4192500 call */
    GM_SITE(vm, 330, 4192500);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4192508 cast */
    /* @4192512 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4193048;
    /* @4192516 load */
    /* @4192524 constant */
    /* @4192528 cmp */
    /* @4192532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4192576;
    /* @4192536 load */
    /* @4192544 constant */
    /* @4192548 cmp */
    /* @4192552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4192576;
    /* @4192556 load */
    /* @4192564 constant */
    /* @4192568 cmp */
    /* @4192572 b */
    p4192580_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4192580;
    L_4192576: ;
    /* @4192576 constant */
    p4192580_0 = VAL(0);
    L_4192580: ;
    /* @4192580 bf */
    if (!TRUTH(p4192580_0)) goto L_4192928;
    /* @4192584 load */
    /* @4192592 constant */
    /* @4192596 cmp */
    /* @4192600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4192644;
    /* @4192604 constant */
    /* @4192608 cast */
    /* @4192612 constant */
    /* @4192616 cast */
    /* @4192620 constant */
    /* @4192624 cast */
    /* @4192628 call */
    GM_SITE(vm, 330, 4192628);
    /* @4192636 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4192640 b */
    goto L_4192664;
    L_4192644: ;
    /* @4192644 load */
    /* @4192652 constant */
    /* @4192656 cmp */
    /* @4192660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4192664;
    L_4192664: ;
    /* @4192664 constant */
    /* @4192668 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4192676 constant */
    /* @4192680 cast */
    /* @4192684 load */
    /* @4192692 load */
    /* @4192700 load */
    /* @4192708 load */
    /* @4192716 call */
    GM_SITE(vm, 330, 4192716);
    /* @4192724 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4192728 load */
    /* @4192736 load */
    /* @4192744 cmp */
    /* @4192748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4192780;
    /* @4192752 constant */
    /* @4192756 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4192764 constant */
    /* @4192768 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4192776 b */
    goto L_4192828;
    L_4192780: ;
    /* @4192780 load */
    /* @4192788 load */
    /* @4192796 cmp */
    /* @4192800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4192828;
    /* @4192804 constant */
    /* @4192808 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4192816 constant */
    /* @4192820 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4192828: ;
    /* @4192828 constant */
    /* @4192832 constant */
    /* @4192836 constant */
    /* @4192840 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4192848 constant */
    /* @4192852 constant */
    /* @4192856 constant */
    /* @4192860 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4192868 constant */
    /* @4192872 constant */
    /* @4192876 constant */
    /* @4192880 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4192888 load */
    /* @4192896 constant */
    /* @4192900 sub */
    /* @4192904 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4192912 call */
    GM_SITE(vm, 330, 4192912);
    /* @4192920 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4192924 b */
    goto L_4193048;
    L_4192928: ;
    /* @4192928 load */
    /* @4192936 constant */
    /* @4192940 cmp */
    /* @4192944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4193048;
    /* @4192948 constant */
    /* @4192952 cast */
    /* @4192956 call */
    GM_SITE(vm, 330, 4192956);
    /* @4192964 constant */
    /* @4192968 cmp */
    /* @4192972 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v11)) goto L_4193048;
    /* @4192976 constant */
    /* @4192980 cast */
    /* @4192984 call */
    GM_SITE(vm, 330, 4192984);
    /* @4192992 cast */
    /* @4192996 not */
    /* @4193000 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v12)) goto L_4193048;
    /* @4193004 constant */
    /* @4193008 cast */
    /* @4193012 load */
    /* @4193020 constant */
    /* @4193024 sub */
    /* @4193028 load */
    /* @4193036 call */
    GM_SITE(vm, 330, 4193036);
    /* @4193044 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4193048: ;
    return;
}
