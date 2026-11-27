/* generated from CODE 315 (gml_Object_obj_enemybullet2_Step_0), source start 4188236, end 4189080. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0315(GmVM* vm) {
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
    Val p4188612_0;
    Val v11;
    Val v12;
    /* @4188236 constant */
    /* @4188240 cast */
    /* @4188244 call */
    GM_SITE(vm, 315, 4188244);
    /* @4188252 cast */
    /* @4188256 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4188376;
    /* @4188260 constant */
    /* @4188264 cast */
    /* @4188268 load */
    /* @4188276 load */
    /* @4188284 add */
    /* @4188288 load */
    /* @4188296 load */
    /* @4188304 add */
    /* @4188308 call */
    GM_SITE(vm, 315, 4188308);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4188316 cast */
    /* @4188320 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4188376;
    /* @4188324 constant */
    /* @4188328 cast */
    /* @4188332 load */
    /* @4188340 load */
    /* @4188348 call */
    GM_SITE(vm, 315, 4188348);
    /* @4188356 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4188364 call */
    GM_SITE(vm, 315, 4188364);
    /* @4188372 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4188376: ;
    /* @4188376 constant */
    /* @4188380 cast */
    /* @4188384 load */
    /* @4188392 load */
    /* @4188400 call */
    GM_SITE(vm, 315, 4188400);
    /* @4188408 cast */
    /* @4188412 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4188468;
    /* @4188416 constant */
    /* @4188420 cast */
    /* @4188424 load */
    /* @4188432 load */
    /* @4188440 call */
    GM_SITE(vm, 315, 4188440);
    /* @4188448 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4188456 call */
    GM_SITE(vm, 315, 4188456);
    /* @4188464 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4188468: ;
    /* @4188468 load */
    /* @4188476 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4188484 constant */
    /* @4188488 cast */
    /* @4188492 load */
    /* @4188500 load */
    /* @4188508 add */
    /* @4188512 load */
    /* @4188520 load */
    /* @4188528 add */
    /* @4188532 call */
    GM_SITE(vm, 315, 4188532);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4188540 cast */
    /* @4188544 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4189080;
    /* @4188548 load */
    /* @4188556 constant */
    /* @4188560 cmp */
    /* @4188564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4188608;
    /* @4188568 load */
    /* @4188576 constant */
    /* @4188580 cmp */
    /* @4188584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4188608;
    /* @4188588 load */
    /* @4188596 constant */
    /* @4188600 cmp */
    /* @4188604 b */
    p4188612_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4188612;
    L_4188608: ;
    /* @4188608 constant */
    p4188612_0 = VAL(0);
    L_4188612: ;
    /* @4188612 bf */
    if (!TRUTH(p4188612_0)) goto L_4188960;
    /* @4188616 load */
    /* @4188624 constant */
    /* @4188628 cmp */
    /* @4188632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4188676;
    /* @4188636 constant */
    /* @4188640 cast */
    /* @4188644 constant */
    /* @4188648 cast */
    /* @4188652 constant */
    /* @4188656 cast */
    /* @4188660 call */
    GM_SITE(vm, 315, 4188660);
    /* @4188668 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4188672 b */
    goto L_4188696;
    L_4188676: ;
    /* @4188676 load */
    /* @4188684 constant */
    /* @4188688 cmp */
    /* @4188692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4188696;
    L_4188696: ;
    /* @4188696 constant */
    /* @4188700 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4188708 constant */
    /* @4188712 cast */
    /* @4188716 load */
    /* @4188724 load */
    /* @4188732 load */
    /* @4188740 load */
    /* @4188748 call */
    GM_SITE(vm, 315, 4188748);
    /* @4188756 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4188760 load */
    /* @4188768 load */
    /* @4188776 cmp */
    /* @4188780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4188812;
    /* @4188784 constant */
    /* @4188788 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4188796 constant */
    /* @4188800 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4188808 b */
    goto L_4188860;
    L_4188812: ;
    /* @4188812 load */
    /* @4188820 load */
    /* @4188828 cmp */
    /* @4188832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4188860;
    /* @4188836 constant */
    /* @4188840 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4188848 constant */
    /* @4188852 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4188860: ;
    /* @4188860 constant */
    /* @4188864 constant */
    /* @4188868 constant */
    /* @4188872 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4188880 constant */
    /* @4188884 constant */
    /* @4188888 constant */
    /* @4188892 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4188900 constant */
    /* @4188904 constant */
    /* @4188908 constant */
    /* @4188912 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4188920 load */
    /* @4188928 constant */
    /* @4188932 sub */
    /* @4188936 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4188944 call */
    GM_SITE(vm, 315, 4188944);
    /* @4188952 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4188956 b */
    goto L_4189080;
    L_4188960: ;
    /* @4188960 load */
    /* @4188968 constant */
    /* @4188972 cmp */
    /* @4188976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4189080;
    /* @4188980 constant */
    /* @4188984 cast */
    /* @4188988 call */
    GM_SITE(vm, 315, 4188988);
    /* @4188996 constant */
    /* @4189000 cmp */
    /* @4189004 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v11)) goto L_4189080;
    /* @4189008 constant */
    /* @4189012 cast */
    /* @4189016 call */
    GM_SITE(vm, 315, 4189016);
    /* @4189024 cast */
    /* @4189028 not */
    /* @4189032 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v12)) goto L_4189080;
    /* @4189036 constant */
    /* @4189040 cast */
    /* @4189044 load */
    /* @4189052 constant */
    /* @4189056 sub */
    /* @4189060 load */
    /* @4189068 call */
    GM_SITE(vm, 315, 4189068);
    /* @4189076 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4189080: ;
    return;
}
