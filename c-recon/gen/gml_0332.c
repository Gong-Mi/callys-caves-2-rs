/* generated from CODE 332 (gml_Object_obj_firehulkflame_Step_0), source start 4193108, end 4194208. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0332(GmVM* vm) {
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
    Val v11;
    Val p4193636_0;
    Val v12;
    Val v13;
    Val v14;
    /* @4193108 constant */
    /* @4193112 cast */
    /* @4193116 call */
    GM_SITE(vm, 332, 4193116);
    /* @4193124 cast */
    /* @4193128 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(46)));
    if (!TRUTH(v1)) goto L_4193352;
    /* @4193132 constant */
    /* @4193136 cast */
    /* @4193140 load */
    /* @4193148 load */
    /* @4193156 add */
    /* @4193160 load */
    /* @4193168 load */
    /* @4193176 add */
    /* @4193180 call */
    GM_SITE(vm, 332, 4193180);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4193188 cast */
    /* @4193192 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v2, v3, VAL(46)));
    if (!TRUTH(v4)) goto L_4193352;
    /* @4193196 constant */
    /* @4193200 cast */
    /* @4193204 load */
    /* @4193212 load */
    /* @4193220 call */
    GM_SITE(vm, 332, 4193220);
    /* @4193228 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187));
    GM_WRITE(vm, -1, "i1", v5);
    /* @4193236 constant */
    /* @4193248 load */
    /* @4193256 cast */
    /* @4193260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(0.5));
    /* @4193268 constant */
    /* @4193280 load */
    /* @4193288 cast */
    /* @4193292 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_yscale", VAL(0.5));
    /* @4193300 constant */
    /* @4193304 cast */
    /* @4193308 load */
    /* @4193316 load */
    /* @4193324 call */
    GM_SITE(vm, 332, 4193324);
    /* @4193332 store */
    v6 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(12));
    GM_WRITE(vm, -1, "i2", v6);
    /* @4193340 call */
    GM_SITE(vm, 332, 4193340);
    /* @4193348 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4193352: ;
    /* @4193352 constant */
    /* @4193356 cast */
    /* @4193360 load */
    /* @4193368 load */
    /* @4193376 call */
    GM_SITE(vm, 332, 4193376);
    /* @4193384 cast */
    /* @4193388 bf */
    v7 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v7)) goto L_4193508;
    /* @4193392 constant */
    /* @4193396 cast */
    /* @4193400 load */
    /* @4193408 load */
    /* @4193416 call */
    GM_SITE(vm, 332, 4193416);
    /* @4193424 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187));
    GM_WRITE(vm, -1, "i1", v8);
    /* @4193432 constant */
    /* @4193444 load */
    /* @4193452 cast */
    /* @4193456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(0.5));
    /* @4193464 constant */
    /* @4193476 load */
    /* @4193484 cast */
    /* @4193488 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_yscale", VAL(0.5));
    /* @4193496 call */
    GM_SITE(vm, 332, 4193496);
    /* @4193504 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4193508: ;
    /* @4193508 constant */
    /* @4193512 cast */
    /* @4193516 load */
    /* @4193524 load */
    /* @4193532 add */
    /* @4193536 load */
    /* @4193544 load */
    /* @4193552 add */
    /* @4193556 call */
    GM_SITE(vm, 332, 4193556);
    v9 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v10 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4193564 cast */
    /* @4193568 bf */
    v11 = BOOL(GM_CALL(vm, "instance_place", 3, v9, v10, VAL(0)));
    if (!TRUTH(v11)) goto L_4194208;
    /* @4193572 load */
    /* @4193580 constant */
    /* @4193584 cmp */
    /* @4193588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") != VAL(1)))) goto L_4193632;
    /* @4193592 load */
    /* @4193600 constant */
    /* @4193604 cmp */
    /* @4193608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(0)))) goto L_4193632;
    /* @4193612 load */
    /* @4193620 constant */
    /* @4193624 cmp */
    /* @4193628 b */
    p4193636_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(0));
    goto L_4193636;
    L_4193632: ;
    /* @4193632 constant */
    p4193636_0 = VAL(0);
    L_4193636: ;
    /* @4193636 bf */
    if (!TRUTH(p4193636_0)) goto L_4194088;
    /* @4193640 load */
    /* @4193648 constant */
    /* @4193652 cmp */
    /* @4193656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4193700;
    /* @4193660 constant */
    /* @4193664 cast */
    /* @4193668 constant */
    /* @4193672 cast */
    /* @4193676 constant */
    /* @4193680 cast */
    /* @4193684 call */
    GM_SITE(vm, 332, 4193684);
    /* @4193692 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    /* @4193696 b */
    goto L_4193720;
    L_4193700: ;
    /* @4193700 load */
    /* @4193708 constant */
    /* @4193712 cmp */
    /* @4193716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4193720;
    L_4193720: ;
    /* @4193720 constant */
    /* @4193724 cast */
    /* @4193728 load */
    /* @4193736 load */
    /* @4193744 call */
    GM_SITE(vm, 332, 4193744);
    /* @4193752 store */
    v12 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187));
    GM_WRITE(vm, -1, "i1", v12);
    /* @4193760 constant */
    /* @4193772 load */
    /* @4193780 cast */
    /* @4193784 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_xscale", VAL(0.5));
    /* @4193792 constant */
    /* @4193804 load */
    /* @4193812 cast */
    /* @4193816 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "image_yscale", VAL(0.5));
    /* @4193824 constant */
    /* @4193828 store */
    GM_WRITE(vm, 0, "flashing", VAL(1));
    /* @4193836 constant */
    /* @4193840 cast */
    /* @4193844 load */
    /* @4193852 load */
    /* @4193860 load */
    /* @4193868 load */
    /* @4193876 call */
    GM_SITE(vm, 332, 4193876);
    /* @4193884 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4193888 load */
    /* @4193896 load */
    /* @4193904 cmp */
    /* @4193908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > GM_READ(vm, 0, "x")))) goto L_4193940;
    /* @4193912 constant */
    /* @4193916 store */
    GM_WRITE(vm, 0, "invulnerable", VAL(1));
    /* @4193924 constant */
    /* @4193928 store */
    GM_WRITE(vm, 0, "sliding1", VAL(1));
    /* @4193936 b */
    goto L_4193988;
    L_4193940: ;
    /* @4193940 load */
    /* @4193948 load */
    /* @4193956 cmp */
    /* @4193960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4193988;
    /* @4193964 constant */
    /* @4193968 store */
    GM_WRITE(vm, 0, "invulnerable2", VAL(1));
    /* @4193976 constant */
    /* @4193980 store */
    GM_WRITE(vm, 0, "sliding2", VAL(1));
    L_4193988: ;
    /* @4193988 constant */
    /* @4193992 constant */
    /* @4193996 constant */
    /* @4194000 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(7), VAL(22));
    /* @4194008 constant */
    /* @4194012 constant */
    /* @4194016 constant */
    /* @4194020 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(4), VAL(10));
    /* @4194028 constant */
    /* @4194032 constant */
    /* @4194036 constant */
    /* @4194040 store */
    GM_WRITE_ARR(vm, VAL(0), "alarm", VAL(8), VAL(25));
    /* @4194048 load */
    /* @4194056 constant */
    /* @4194060 sub */
    /* @4194064 store */
    GM_WRITE(vm, -5, "health1", (GM_READ(vm, -5, "health1") - VAL(2)));
    /* @4194072 call */
    GM_SITE(vm, 332, 4194072);
    /* @4194080 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4194084 b */
    goto L_4194208;
    L_4194088: ;
    /* @4194088 load */
    /* @4194096 constant */
    /* @4194100 cmp */
    /* @4194104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rebuff") == VAL(1)))) goto L_4194208;
    /* @4194108 constant */
    /* @4194112 cast */
    /* @4194116 call */
    GM_SITE(vm, 332, 4194116);
    /* @4194124 constant */
    /* @4194128 cmp */
    /* @4194132 bf */
    v13 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(2));
    if (!TRUTH(v13)) goto L_4194208;
    /* @4194136 constant */
    /* @4194140 cast */
    /* @4194144 call */
    GM_SITE(vm, 332, 4194144);
    /* @4194152 cast */
    /* @4194156 not */
    /* @4194160 bf */
    v14 = NOT(BOOL(GM_CALL(vm, "instance_exists", 1, VAL(106))));
    if (!TRUTH(v14)) goto L_4194208;
    /* @4194164 constant */
    /* @4194168 cast */
    /* @4194172 load */
    /* @4194180 constant */
    /* @4194184 sub */
    /* @4194188 load */
    /* @4194196 call */
    GM_SITE(vm, 332, 4194196);
    /* @4194204 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(10)), VAL(106)));
    L_4194208: ;
    return;
}
