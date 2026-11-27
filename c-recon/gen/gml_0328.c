/* generated from CODE 328 (gml_Object_obj_hulkingbanditbullet_Step_0), source start 4191112, end 4192080. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0328(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val p4191336_0;
    Val v7;
    Val v8;
    Val v9;
    Val p4191500_0;
    Val p4191568_0;
    Val v10;
    Val v11;
    /* @4191112 constant */
    /* @4191116 cast */
    /* @4191120 call */
    GM_SITE(vm, 328, 4191120);
    /* @4191128 cast */
    /* @4191132 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4191252;
    /* @4191136 constant */
    /* @4191140 cast */
    /* @4191144 load */
    /* @4191152 load */
    /* @4191160 add */
    /* @4191164 load */
    /* @4191172 load */
    /* @4191180 add */
    /* @4191184 call */
    GM_SITE(vm, 328, 4191184);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4191192 cast */
    /* @4191196 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4191252;
    /* @4191200 constant */
    /* @4191204 cast */
    /* @4191208 load */
    /* @4191216 load */
    /* @4191224 call */
    GM_SITE(vm, 328, 4191224);
    /* @4191232 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4191240 call */
    GM_SITE(vm, 328, 4191240);
    /* @4191248 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4191252: ;
    /* @4191252 constant */
    /* @4191256 cast */
    /* @4191260 load */
    /* @4191268 load */
    /* @4191276 call */
    GM_SITE(vm, 328, 4191276);
    /* @4191284 cast */
    /* @4191288 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4191332;
    /* @4191292 load */
    /* @4191300 constant */
    /* @4191304 cmp */
    /* @4191308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "checkwall") == VAL(0)))) goto L_4191332;
    /* @4191312 load */
    /* @4191320 constant */
    /* @4191324 cmp */
    /* @4191328 b */
    p4191336_0 = NUMBOOL(GM_READ(vm, -1, "hurtplayer") == VAL(0));
    goto L_4191336;
    L_4191332: ;
    /* @4191332 constant */
    p4191336_0 = VAL(0);
    L_4191336: ;
    /* @4191336 bf */
    if (!TRUTH(p4191336_0)) goto L_4191396;
    /* @4191340 constant */
    /* @4191344 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4191352 constant */
    /* @4191356 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4191364 constant */
    /* @4191368 constant */
    /* @4191372 constant */
    /* @4191376 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4191384 constant */
    /* @4191388 store */
    GM_WRITE(vm, -1, "checkwall", VAL(1));
    L_4191396: ;
    /* @4191396 load */
    /* @4191404 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4191412 constant */
    /* @4191416 cast */
    /* @4191420 load */
    /* @4191428 load */
    /* @4191436 add */
    /* @4191440 load */
    /* @4191448 load */
    /* @4191456 add */
    /* @4191460 call */
    GM_SITE(vm, 328, 4191460);
    v7 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v8 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4191468 cast */
    /* @4191472 bf */
    v9 = BOOL(GM_CALL(vm, "instance_place", 3, v7, v8, VAL(0)));
    if (!TRUTH(v9)) goto L_4191496;
    /* @4191476 load */
    /* @4191484 constant */
    /* @4191488 cmp */
    /* @4191492 b */
    p4191500_0 = NUMBOOL(GM_READ(vm, -1, "hurtplayer") == VAL(0));
    goto L_4191500;
    L_4191496: ;
    /* @4191496 constant */
    p4191500_0 = VAL(0);
    L_4191500: ;
    /* @4191500 bf */
    if (!TRUTH(p4191500_0)) goto L_4192080;
    /* @4191504 load */
    /* @4191512 constant */
    /* @4191516 cmp */
    /* @4191520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4191564;
    /* @4191524 load */
    /* @4191532 constant */
    /* @4191536 cmp */
    /* @4191540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4191564;
    /* @4191544 load */
    /* @4191552 constant */
    /* @4191556 cmp */
    /* @4191560 b */
    p4191568_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4191568;
    L_4191564: ;
    /* @4191564 constant */
    p4191568_0 = VAL(0);
    L_4191568: ;
    /* @4191568 bf */
    if (!TRUTH(p4191568_0)) goto L_4191960;
    /* @4191572 constant */
    /* @4191576 constant */
    /* @4191580 constant */
    /* @4191584 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @4191592 constant */
    /* @4191596 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4191604 constant */
    /* @4191608 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4191616 constant */
    /* @4191620 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4191628 constant */
    /* @4191632 cast */
    /* @4191636 load */
    /* @4191644 load */
    /* @4191652 load */
    /* @4191660 load */
    /* @4191668 call */
    GM_SITE(vm, 328, 4191668);
    /* @4191676 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4191680 load */
    /* @4191688 load */
    /* @4191696 cmp */
    /* @4191700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4191732;
    /* @4191704 constant */
    /* @4191708 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4191716 constant */
    /* @4191720 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4191728 b */
    goto L_4191780;
    L_4191732: ;
    /* @4191732 load */
    /* @4191740 load */
    /* @4191748 cmp */
    /* @4191752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4191780;
    /* @4191756 constant */
    /* @4191760 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4191768 constant */
    /* @4191772 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4191780: ;
    /* @4191780 constant */
    /* @4191784 constant */
    /* @4191788 constant */
    /* @4191792 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4191800 constant */
    /* @4191804 constant */
    /* @4191808 constant */
    /* @4191812 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4191820 constant */
    /* @4191824 constant */
    /* @4191828 constant */
    /* @4191832 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4191840 load */
    /* @4191848 constant */
    /* @4191852 sub */
    /* @4191856 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4191864 constant */
    /* @4191868 store */
    GM_WRITE(vm, -1, "hurtplayer", VAL(1));
    /* @4191876 load */
    /* @4191884 constant */
    /* @4191888 cmp */
    /* @4191892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4191936;
    /* @4191896 constant */
    /* @4191900 cast */
    /* @4191904 constant */
    /* @4191908 cast */
    /* @4191912 constant */
    /* @4191916 cast */
    /* @4191920 call */
    GM_SITE(vm, 328, 4191920);
    /* @4191928 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4191932 b */
    goto L_4191956;
    L_4191936: ;
    /* @4191936 load */
    /* @4191944 constant */
    /* @4191948 cmp */
    /* @4191952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4191956;
    L_4191956: ;
    /* @4191956 b */
    goto L_4192080;
    L_4191960: ;
    /* @4191960 load */
    /* @4191968 constant */
    /* @4191972 cmp */
    /* @4191976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4192080;
    /* @4191980 constant */
    /* @4191984 cast */
    /* @4191988 call */
    GM_SITE(vm, 328, 4191988);
    /* @4191996 constant */
    /* @4192000 cmp */
    /* @4192004 bf */
    v10 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v10)) goto L_4192080;
    /* @4192008 constant */
    /* @4192012 cast */
    /* @4192016 call */
    GM_SITE(vm, 328, 4192016);
    /* @4192024 cast */
    /* @4192028 not */
    /* @4192032 bf */
    v11 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v11)) goto L_4192080;
    /* @4192036 constant */
    /* @4192040 cast */
    /* @4192044 load */
    /* @4192052 constant */
    /* @4192056 sub */
    /* @4192060 load */
    /* @4192068 call */
    GM_SITE(vm, 328, 4192068);
    /* @4192076 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4192080: ;
    return;
}
