/* generated from CODE 313 (gml_Object_obj_enemybullet_Step_0), source start 4187380, end 4188224. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0313(GmVM* vm) {
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
    Val p4187756_0;
    Val v11;
    Val v12;
    /* @4187380 constant */
    /* @4187384 cast */
    /* @4187388 call */
    GM_SITE(vm, 313, 4187388);
    /* @4187396 cast */
    /* @4187400 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4187520;
    /* @4187404 constant */
    /* @4187408 cast */
    /* @4187412 load */
    /* @4187420 load */
    /* @4187428 add */
    /* @4187432 load */
    /* @4187440 load */
    /* @4187448 add */
    /* @4187452 call */
    GM_SITE(vm, 313, 4187452);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4187460 cast */
    /* @4187464 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4187520;
    /* @4187468 constant */
    /* @4187472 cast */
    /* @4187476 load */
    /* @4187484 load */
    /* @4187492 call */
    GM_SITE(vm, 313, 4187492);
    /* @4187500 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4187508 call */
    GM_SITE(vm, 313, 4187508);
    /* @4187516 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4187520: ;
    /* @4187520 constant */
    /* @4187524 cast */
    /* @4187528 load */
    /* @4187536 load */
    /* @4187544 call */
    GM_SITE(vm, 313, 4187544);
    /* @4187552 cast */
    /* @4187556 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v6)) goto L_4187612;
    /* @4187560 constant */
    /* @4187564 cast */
    /* @4187568 load */
    /* @4187576 load */
    /* @4187584 call */
    GM_SITE(vm, 313, 4187584);
    /* @4187592 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v7);
    /* @4187600 call */
    GM_SITE(vm, 313, 4187600);
    /* @4187608 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4187612: ;
    /* @4187612 load */
    /* @4187620 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4187628 constant */
    /* @4187632 cast */
    /* @4187636 load */
    /* @4187644 load */
    /* @4187652 add */
    /* @4187656 load */
    /* @4187664 load */
    /* @4187672 add */
    /* @4187676 call */
    GM_SITE(vm, 313, 4187676);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v9 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4187684 cast */
    /* @4187688 bf */
    v10 = BOOL(GM_CALL(vm, "instance_place", 3, v8, v9, VAL(0)));
    if (!TRUTH(v10)) goto L_4188224;
    /* @4187692 load */
    /* @4187700 constant */
    /* @4187704 cmp */
    /* @4187708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4187752;
    /* @4187712 load */
    /* @4187720 constant */
    /* @4187724 cmp */
    /* @4187728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4187752;
    /* @4187732 load */
    /* @4187740 constant */
    /* @4187744 cmp */
    /* @4187748 b */
    p4187756_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4187756;
    L_4187752: ;
    /* @4187752 constant */
    p4187756_0 = VAL(0);
    L_4187756: ;
    /* @4187756 bf */
    if (!TRUTH(p4187756_0)) goto L_4188104;
    /* @4187760 load */
    /* @4187768 constant */
    /* @4187772 cmp */
    /* @4187776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4187820;
    /* @4187780 constant */
    /* @4187784 cast */
    /* @4187788 constant */
    /* @4187792 cast */
    /* @4187796 constant */
    /* @4187800 cast */
    /* @4187804 call */
    GM_SITE(vm, 313, 4187804);
    /* @4187812 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4187816 b */
    goto L_4187840;
    L_4187820: ;
    /* @4187820 load */
    /* @4187828 constant */
    /* @4187832 cmp */
    /* @4187836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4187840;
    L_4187840: ;
    /* @4187840 constant */
    /* @4187844 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4187852 constant */
    /* @4187856 cast */
    /* @4187860 load */
    /* @4187868 load */
    /* @4187876 load */
    /* @4187884 load */
    /* @4187892 call */
    GM_SITE(vm, 313, 4187892);
    /* @4187900 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4187904 load */
    /* @4187912 load */
    /* @4187920 cmp */
    /* @4187924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4187956;
    /* @4187928 constant */
    /* @4187932 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4187940 constant */
    /* @4187944 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4187952 b */
    goto L_4188004;
    L_4187956: ;
    /* @4187956 load */
    /* @4187964 load */
    /* @4187972 cmp */
    /* @4187976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4188004;
    /* @4187980 constant */
    /* @4187984 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4187992 constant */
    /* @4187996 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4188004: ;
    /* @4188004 constant */
    /* @4188008 constant */
    /* @4188012 constant */
    /* @4188016 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4188024 constant */
    /* @4188028 constant */
    /* @4188032 constant */
    /* @4188036 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4188044 constant */
    /* @4188048 constant */
    /* @4188052 constant */
    /* @4188056 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4188064 load */
    /* @4188072 constant */
    /* @4188076 sub */
    /* @4188080 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(1)));
    /* @4188088 call */
    GM_SITE(vm, 313, 4188088);
    /* @4188096 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4188100 b */
    goto L_4188224;
    L_4188104: ;
    /* @4188104 load */
    /* @4188112 constant */
    /* @4188116 cmp */
    /* @4188120 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4188224;
    /* @4188124 constant */
    /* @4188128 cast */
    /* @4188132 call */
    GM_SITE(vm, 313, 4188132);
    /* @4188140 constant */
    /* @4188144 cmp */
    /* @4188148 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v11)) goto L_4188224;
    /* @4188152 constant */
    /* @4188156 cast */
    /* @4188160 call */
    GM_SITE(vm, 313, 4188160);
    /* @4188168 cast */
    /* @4188172 not */
    /* @4188176 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v12)) goto L_4188224;
    /* @4188180 constant */
    /* @4188184 cast */
    /* @4188188 load */
    /* @4188196 constant */
    /* @4188200 sub */
    /* @4188204 load */
    /* @4188212 call */
    GM_SITE(vm, 313, 4188212);
    /* @4188220 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4188224: ;
    return;
}
