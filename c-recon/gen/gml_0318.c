/* generated from CODE 318 (gml_Object_obj_finalbosslaser_Step_0), source start 4189196, end 4189936. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0318(GmVM* vm) {
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
    Val p4189572_0;
    /* @4189196 constant */
    /* @4189200 cast */
    /* @4189204 call */
    GM_SITE(vm, 318, 4189204);
    /* @4189212 cast */
    /* @4189216 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4189336;
    /* @4189220 constant */
    /* @4189224 cast */
    /* @4189228 load */
    /* @4189236 load */
    /* @4189244 add */
    /* @4189248 load */
    /* @4189256 load */
    /* @4189264 add */
    /* @4189268 call */
    GM_SITE(vm, 318, 4189268);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4189276 cast */
    /* @4189280 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4189336;
    /* @4189284 constant */
    /* @4189288 cast */
    /* @4189292 load */
    /* @4189300 load */
    /* @4189308 call */
    GM_SITE(vm, 318, 4189308);
    /* @4189316 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4189324 call */
    GM_SITE(vm, 318, 4189324);
    /* @4189332 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4189336: ;
    /* @4189336 constant */
    /* @4189340 cast */
    /* @4189344 load */
    /* @4189352 load */
    /* @4189360 call */
    GM_SITE(vm, 318, 4189360);
    /* @4189368 cast */
    /* @4189372 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4189428;
    /* @4189376 constant */
    /* @4189380 cast */
    /* @4189384 load */
    /* @4189392 load */
    /* @4189400 call */
    GM_SITE(vm, 318, 4189400);
    /* @4189408 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4189416 call */
    GM_SITE(vm, 318, 4189416);
    /* @4189424 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4189428: ;
    /* @4189428 load */
    /* @4189436 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4189444 constant */
    /* @4189448 cast */
    /* @4189452 load */
    /* @4189460 load */
    /* @4189468 add */
    /* @4189472 load */
    /* @4189480 load */
    /* @4189488 add */
    /* @4189492 call */
    GM_SITE(vm, 318, 4189492);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4189500 cast */
    /* @4189504 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4189568;
    /* @4189508 load */
    /* @4189516 constant */
    /* @4189520 cmp */
    /* @4189524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4189568;
    /* @4189528 load */
    /* @4189536 constant */
    /* @4189540 cmp */
    /* @4189544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0)))) goto L_4189568;
    /* @4189548 load */
    /* @4189556 constant */
    /* @4189560 cmp */
    /* @4189564 b */
    p4189572_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4189572;
    L_4189568: ;
    /* @4189568 constant */
    p4189572_0 = VAL(0);
    L_4189572: ;
    /* @4189572 bf */
    if (!TRUTH(p4189572_0)) goto L_4189936;
    /* @4189576 load */
    /* @4189584 constant */
    /* @4189588 cmp */
    /* @4189592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4189636;
    /* @4189596 constant */
    /* @4189600 cast */
    /* @4189604 constant */
    /* @4189608 cast */
    /* @4189612 constant */
    /* @4189616 cast */
    /* @4189620 call */
    GM_SITE(vm, 318, 4189620);
    /* @4189628 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4189632 b */
    goto L_4189656;
    L_4189636: ;
    /* @4189636 load */
    /* @4189644 constant */
    /* @4189648 cmp */
    /* @4189652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4189656;
    L_4189656: ;
    /* @4189656 constant */
    /* @4189660 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4189668 constant */
    /* @4189672 cast */
    /* @4189676 load */
    /* @4189684 load */
    /* @4189692 load */
    /* @4189700 load */
    /* @4189708 call */
    GM_SITE(vm, 318, 4189708);
    /* @4189716 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4189720 load */
    /* @4189728 load */
    /* @4189736 cmp */
    /* @4189740 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4189772;
    /* @4189744 constant */
    /* @4189748 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4189756 constant */
    /* @4189760 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4189768 b */
    goto L_4189820;
    L_4189772: ;
    /* @4189772 load */
    /* @4189780 load */
    /* @4189788 cmp */
    /* @4189792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4189820;
    /* @4189796 constant */
    /* @4189800 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4189808 constant */
    /* @4189812 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4189820: ;
    /* @4189820 constant */
    /* @4189824 constant */
    /* @4189828 constant */
    /* @4189832 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4189840 constant */
    /* @4189844 constant */
    /* @4189848 constant */
    /* @4189852 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4189860 constant */
    /* @4189864 constant */
    /* @4189868 constant */
    /* @4189872 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4189880 load */
    /* @4189888 constant */
    /* @4189892 sub */
    /* @4189896 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4189904 constant */
    /* @4189908 constant */
    /* @4189912 constant */
    /* @4189916 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4189924 constant */
    /* @4189928 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4189936: ;
    return;
}
