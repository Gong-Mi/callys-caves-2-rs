/* generated from CODE 298 (gml_Object_obj_boomerangthrow_Step_0), source start 4140992, end 4147884. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0298(GmVM* vm) {
    Val p4141112_0;
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
    Val v12;
    Val v13;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val v18;
    Val v19;
    Val v20;
    Val v21;
    Val v22;
    Val v23;
    Val v24;
    Val v25;
    Val v26;
    Val v27;
    Val v28;
    Val v29;
    Val v30;
    Val v31;
    Val v32;
    Val v33;
    Val v34;
    Val v35;
    Val v36;
    Val v37;
    Val v38;
    Val v39;
    Val v40;
    Val v41;
    Val v42;
    Val v43;
    Val v44;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    Val v52;
    Val v53;
    Val v54;
    Val v55;
    Val v56;
    Val v57;
    /* @4140992 load */
    /* @4141000 constant */
    /* @4141004 cmp */
    /* @4141008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "boomerangreturn") == VAL(1)))) goto L_4141048;
    /* @4141012 constant */
    /* @4141016 cast */
    /* @4141020 load */
    /* @4141028 load */
    /* @4141036 call */
    GM_SITE(vm, 298, 4141036);
    /* @4141044 popz */
    (void)(GM_CALL(vm, "move_towards_point", 3, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(5)));
    L_4141048: ;
    /* @4141048 load */
    /* @4141056 constant */
    /* @4141060 cmp */
    /* @4141064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "boomerangreturn") == VAL(1)))) goto L_4141108;
    /* @4141068 constant */
    /* @4141072 cast */
    /* @4141076 load */
    /* @4141084 load */
    /* @4141092 call */
    GM_SITE(vm, 298, 4141092);
    /* @4141100 cast */
    /* @4141104 b */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(0)));
    p4141112_0 = v1;
    goto L_4141112;
    L_4141108: ;
    /* @4141108 constant */
    p4141112_0 = VAL(0);
    L_4141112: ;
    /* @4141112 bf */
    if (!TRUTH(p4141112_0)) goto L_4141140;
    /* @4141116 call */
    GM_SITE(vm, 298, 4141116);
    /* @4141124 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4141128 constant */
    /* @4141132 store */
    GM_WRITE(vm, -1, "boomerangreturn", VAL(0));
    L_4141140: ;
    /* @4141140 load */
    /* @4141148 constant */
    /* @4141152 sub */
    /* @4141156 store */
    GM_WRITE(vm, -1, "image_angle", (GM_READ(vm, -1, "image_angle") - VAL(40)));
    /* @4141164 constant */
    /* @4141168 cast */
    /* @4141172 load */
    /* @4141180 load */
    /* @4141188 call */
    GM_SITE(vm, 298, 4141188);
    /* @4141196 store */
    v2 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v2);
    /* @4141204 load */
    /* @4141212 constant */
    /* @4141216 cmp */
    /* @4141220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4141644;
    /* @4141224 constant */
    /* @4141228 load */
    /* @4141236 cast */
    /* @4141240 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4141248 constant */
    /* @4141252 cast */
    /* @4141256 load */
    /* @4141264 load */
    /* @4141272 load */
    /* @4141280 load */
    /* @4141288 call */
    GM_SITE(vm, 298, 4141288);
    /* @4141296 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4141300 load */
    /* @4141308 cast */
    /* @4141312 dup */
    /* @4141316 load */
    /* @4141324 load */
    /* @4141332 sub */
    /* @4141336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4141344 constant */
    /* @4141348 cast */
    /* @4141352 load */
    /* @4141360 load */
    /* @4141368 call */
    GM_SITE(vm, 298, 4141368);
    /* @4141376 store */
    v3 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v3);
    /* @4141384 load */
    /* @4141392 load */
    /* @4141400 cast */
    /* @4141404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4141412 constant */
    /* @4141416 load */
    /* @4141424 cast */
    /* @4141428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4141436 constant */
    /* @4141440 load */
    /* @4141448 cast */
    /* @4141452 constant */
    /* @4141456 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4141464 load */
    /* @4141472 constant */
    /* @4141476 add */
    /* @4141480 store */
    v4 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v4);
    /* @4141488 load */
    /* @4141496 constant */
    /* @4141500 cmp */
    /* @4141504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4141536;
    /* @4141508 constant */
    /* @4141512 load */
    /* @4141520 cast */
    /* @4141524 constant */
    /* @4141528 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4141536: ;
    /* @4141536 load */
    /* @4141544 constant */
    /* @4141548 cmp */
    /* @4141552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4141560;
    /* @4141556 b */
    goto L_4141644;
    L_4141560: ;
    /* @4141560 load */
    /* @4141568 constant */
    /* @4141572 cmp */
    /* @4141576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4141644;
    /* @4141580 constant */
    /* @4141584 cast */
    /* @4141588 call */
    GM_SITE(vm, 298, 4141588);
    /* @4141596 cast */
    /* @4141600 not */
    /* @4141604 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v5)) goto L_4141644;
    /* @4141608 constant */
    /* @4141612 cast */
    /* @4141616 constant */
    /* @4141620 cast */
    /* @4141624 constant */
    /* @4141628 cast */
    /* @4141632 call */
    GM_SITE(vm, 298, 4141632);
    /* @4141640 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4141644: ;
    /* @4141644 constant */
    /* @4141648 cast */
    /* @4141652 load */
    /* @4141660 load */
    /* @4141668 call */
    GM_SITE(vm, 298, 4141668);
    /* @4141676 store */
    v6 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v6);
    /* @4141684 load */
    /* @4141692 constant */
    /* @4141696 cmp */
    /* @4141700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4142124;
    /* @4141704 constant */
    /* @4141708 load */
    /* @4141716 cast */
    /* @4141720 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4141728 constant */
    /* @4141732 cast */
    /* @4141736 load */
    /* @4141744 load */
    /* @4141752 load */
    /* @4141760 load */
    /* @4141768 call */
    GM_SITE(vm, 298, 4141768);
    /* @4141776 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4141780 load */
    /* @4141788 cast */
    /* @4141792 dup */
    /* @4141796 load */
    /* @4141804 load */
    /* @4141812 sub */
    /* @4141816 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4141824 constant */
    /* @4141828 cast */
    /* @4141832 load */
    /* @4141840 load */
    /* @4141848 call */
    GM_SITE(vm, 298, 4141848);
    /* @4141856 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v7);
    /* @4141864 load */
    /* @4141872 load */
    /* @4141880 cast */
    /* @4141884 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4141892 constant */
    /* @4141896 load */
    /* @4141904 cast */
    /* @4141908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4141916 constant */
    /* @4141920 load */
    /* @4141928 cast */
    /* @4141932 constant */
    /* @4141936 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4141944 load */
    /* @4141952 constant */
    /* @4141956 add */
    /* @4141960 store */
    v8 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v8);
    /* @4141968 load */
    /* @4141976 constant */
    /* @4141980 cmp */
    /* @4141984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4142016;
    /* @4141988 constant */
    /* @4141992 load */
    /* @4142000 cast */
    /* @4142004 constant */
    /* @4142008 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4142016: ;
    /* @4142016 load */
    /* @4142024 constant */
    /* @4142028 cmp */
    /* @4142032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4142040;
    /* @4142036 b */
    goto L_4142124;
    L_4142040: ;
    /* @4142040 load */
    /* @4142048 constant */
    /* @4142052 cmp */
    /* @4142056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4142124;
    /* @4142060 constant */
    /* @4142064 cast */
    /* @4142068 call */
    GM_SITE(vm, 298, 4142068);
    /* @4142076 cast */
    /* @4142080 not */
    /* @4142084 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v9)) goto L_4142124;
    /* @4142088 constant */
    /* @4142092 cast */
    /* @4142096 constant */
    /* @4142100 cast */
    /* @4142104 constant */
    /* @4142108 cast */
    /* @4142112 call */
    GM_SITE(vm, 298, 4142112);
    /* @4142120 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4142124: ;
    /* @4142124 constant */
    /* @4142128 cast */
    /* @4142132 load */
    /* @4142140 load */
    /* @4142148 call */
    GM_SITE(vm, 298, 4142148);
    /* @4142156 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v10);
    /* @4142164 load */
    /* @4142172 constant */
    /* @4142176 cmp */
    /* @4142180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4142604;
    /* @4142184 constant */
    /* @4142188 load */
    /* @4142196 cast */
    /* @4142200 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4142208 constant */
    /* @4142212 cast */
    /* @4142216 load */
    /* @4142224 load */
    /* @4142232 load */
    /* @4142240 load */
    /* @4142248 call */
    GM_SITE(vm, 298, 4142248);
    /* @4142256 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4142260 load */
    /* @4142268 cast */
    /* @4142272 dup */
    /* @4142276 load */
    /* @4142284 load */
    /* @4142292 sub */
    /* @4142296 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4142304 constant */
    /* @4142308 cast */
    /* @4142312 load */
    /* @4142320 load */
    /* @4142328 call */
    GM_SITE(vm, 298, 4142328);
    /* @4142336 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4142344 load */
    /* @4142352 load */
    /* @4142360 cast */
    /* @4142364 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4142372 constant */
    /* @4142376 load */
    /* @4142384 cast */
    /* @4142388 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4142396 constant */
    /* @4142400 load */
    /* @4142408 cast */
    /* @4142412 constant */
    /* @4142416 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4142424 load */
    /* @4142432 constant */
    /* @4142436 add */
    /* @4142440 store */
    v12 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v12);
    /* @4142448 load */
    /* @4142456 constant */
    /* @4142460 cmp */
    /* @4142464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4142496;
    /* @4142468 constant */
    /* @4142472 load */
    /* @4142480 cast */
    /* @4142484 constant */
    /* @4142488 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4142496: ;
    /* @4142496 load */
    /* @4142504 constant */
    /* @4142508 cmp */
    /* @4142512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4142520;
    /* @4142516 b */
    goto L_4142604;
    L_4142520: ;
    /* @4142520 load */
    /* @4142528 constant */
    /* @4142532 cmp */
    /* @4142536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4142604;
    /* @4142540 constant */
    /* @4142544 cast */
    /* @4142548 call */
    GM_SITE(vm, 298, 4142548);
    /* @4142556 cast */
    /* @4142560 not */
    /* @4142564 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v13)) goto L_4142604;
    /* @4142568 constant */
    /* @4142572 cast */
    /* @4142576 constant */
    /* @4142580 cast */
    /* @4142584 constant */
    /* @4142588 cast */
    /* @4142592 call */
    GM_SITE(vm, 298, 4142592);
    /* @4142600 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4142604: ;
    /* @4142604 constant */
    /* @4142608 cast */
    /* @4142612 load */
    /* @4142620 load */
    /* @4142628 call */
    GM_SITE(vm, 298, 4142628);
    /* @4142636 store */
    v14 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v14);
    /* @4142644 load */
    /* @4142652 constant */
    /* @4142656 cmp */
    /* @4142660 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4143084;
    /* @4142664 constant */
    /* @4142668 load */
    /* @4142676 cast */
    /* @4142680 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4142688 constant */
    /* @4142692 cast */
    /* @4142696 load */
    /* @4142704 load */
    /* @4142712 load */
    /* @4142720 load */
    /* @4142728 call */
    GM_SITE(vm, 298, 4142728);
    /* @4142736 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4142740 load */
    /* @4142748 cast */
    /* @4142752 dup */
    /* @4142756 load */
    /* @4142764 load */
    /* @4142772 sub */
    /* @4142776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4142784 constant */
    /* @4142788 cast */
    /* @4142792 load */
    /* @4142800 load */
    /* @4142808 call */
    GM_SITE(vm, 298, 4142808);
    /* @4142816 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v15);
    /* @4142824 load */
    /* @4142832 load */
    /* @4142840 cast */
    /* @4142844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4142852 constant */
    /* @4142856 load */
    /* @4142864 cast */
    /* @4142868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4142876 constant */
    /* @4142880 load */
    /* @4142888 cast */
    /* @4142892 constant */
    /* @4142896 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4142904 load */
    /* @4142912 constant */
    /* @4142916 add */
    /* @4142920 store */
    v16 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v16);
    /* @4142928 load */
    /* @4142936 constant */
    /* @4142940 cmp */
    /* @4142944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4142976;
    /* @4142948 constant */
    /* @4142952 load */
    /* @4142960 cast */
    /* @4142964 constant */
    /* @4142968 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4142976: ;
    /* @4142976 load */
    /* @4142984 constant */
    /* @4142988 cmp */
    /* @4142992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4143000;
    /* @4142996 b */
    goto L_4143084;
    L_4143000: ;
    /* @4143000 load */
    /* @4143008 constant */
    /* @4143012 cmp */
    /* @4143016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4143084;
    /* @4143020 constant */
    /* @4143024 cast */
    /* @4143028 call */
    GM_SITE(vm, 298, 4143028);
    /* @4143036 cast */
    /* @4143040 not */
    /* @4143044 bf */
    v17 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v17)) goto L_4143084;
    /* @4143048 constant */
    /* @4143052 cast */
    /* @4143056 constant */
    /* @4143060 cast */
    /* @4143064 constant */
    /* @4143068 cast */
    /* @4143072 call */
    GM_SITE(vm, 298, 4143072);
    /* @4143080 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4143084: ;
    /* @4143084 constant */
    /* @4143088 cast */
    /* @4143092 load */
    /* @4143100 load */
    /* @4143108 call */
    GM_SITE(vm, 298, 4143108);
    /* @4143116 store */
    v18 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v18);
    /* @4143124 load */
    /* @4143132 constant */
    /* @4143136 cmp */
    /* @4143140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4143564;
    /* @4143144 constant */
    /* @4143148 load */
    /* @4143156 cast */
    /* @4143160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4143168 constant */
    /* @4143172 cast */
    /* @4143176 load */
    /* @4143184 load */
    /* @4143192 load */
    /* @4143200 load */
    /* @4143208 call */
    GM_SITE(vm, 298, 4143208);
    /* @4143216 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4143220 load */
    /* @4143228 cast */
    /* @4143232 dup */
    /* @4143236 load */
    /* @4143244 load */
    /* @4143252 sub */
    /* @4143256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4143264 constant */
    /* @4143268 cast */
    /* @4143272 load */
    /* @4143280 load */
    /* @4143288 call */
    GM_SITE(vm, 298, 4143288);
    /* @4143296 store */
    v19 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v19);
    /* @4143304 load */
    /* @4143312 load */
    /* @4143320 cast */
    /* @4143324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4143332 constant */
    /* @4143336 load */
    /* @4143344 cast */
    /* @4143348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4143356 constant */
    /* @4143360 load */
    /* @4143368 cast */
    /* @4143372 constant */
    /* @4143376 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4143384 load */
    /* @4143392 constant */
    /* @4143396 add */
    /* @4143400 store */
    v20 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v20);
    /* @4143408 load */
    /* @4143416 constant */
    /* @4143420 cmp */
    /* @4143424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4143456;
    /* @4143428 constant */
    /* @4143432 load */
    /* @4143440 cast */
    /* @4143444 constant */
    /* @4143448 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4143456: ;
    /* @4143456 load */
    /* @4143464 constant */
    /* @4143468 cmp */
    /* @4143472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4143480;
    /* @4143476 b */
    goto L_4143564;
    L_4143480: ;
    /* @4143480 load */
    /* @4143488 constant */
    /* @4143492 cmp */
    /* @4143496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4143564;
    /* @4143500 constant */
    /* @4143504 cast */
    /* @4143508 call */
    GM_SITE(vm, 298, 4143508);
    /* @4143516 cast */
    /* @4143520 not */
    /* @4143524 bf */
    v21 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v21)) goto L_4143564;
    /* @4143528 constant */
    /* @4143532 cast */
    /* @4143536 constant */
    /* @4143540 cast */
    /* @4143544 constant */
    /* @4143548 cast */
    /* @4143552 call */
    GM_SITE(vm, 298, 4143552);
    /* @4143560 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4143564: ;
    /* @4143564 constant */
    /* @4143568 cast */
    /* @4143572 load */
    /* @4143580 load */
    /* @4143588 call */
    GM_SITE(vm, 298, 4143588);
    /* @4143596 store */
    v22 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v22);
    /* @4143604 load */
    /* @4143612 constant */
    /* @4143616 cmp */
    /* @4143620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4144044;
    /* @4143624 constant */
    /* @4143628 load */
    /* @4143636 cast */
    /* @4143640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4143648 constant */
    /* @4143652 cast */
    /* @4143656 load */
    /* @4143664 load */
    /* @4143672 load */
    /* @4143680 load */
    /* @4143688 call */
    GM_SITE(vm, 298, 4143688);
    /* @4143696 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4143700 load */
    /* @4143708 cast */
    /* @4143712 dup */
    /* @4143716 load */
    /* @4143724 load */
    /* @4143732 sub */
    /* @4143736 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4143744 constant */
    /* @4143748 cast */
    /* @4143752 load */
    /* @4143760 load */
    /* @4143768 call */
    GM_SITE(vm, 298, 4143768);
    /* @4143776 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4143784 load */
    /* @4143792 load */
    /* @4143800 cast */
    /* @4143804 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4143812 constant */
    /* @4143816 load */
    /* @4143824 cast */
    /* @4143828 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4143836 constant */
    /* @4143840 load */
    /* @4143848 cast */
    /* @4143852 constant */
    /* @4143856 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4143864 load */
    /* @4143872 constant */
    /* @4143876 add */
    /* @4143880 store */
    v24 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v24);
    /* @4143888 load */
    /* @4143896 constant */
    /* @4143900 cmp */
    /* @4143904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4143936;
    /* @4143908 constant */
    /* @4143912 load */
    /* @4143920 cast */
    /* @4143924 constant */
    /* @4143928 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4143936: ;
    /* @4143936 load */
    /* @4143944 constant */
    /* @4143948 cmp */
    /* @4143952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4143960;
    /* @4143956 b */
    goto L_4144044;
    L_4143960: ;
    /* @4143960 load */
    /* @4143968 constant */
    /* @4143972 cmp */
    /* @4143976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4144044;
    /* @4143980 constant */
    /* @4143984 cast */
    /* @4143988 call */
    GM_SITE(vm, 298, 4143988);
    /* @4143996 cast */
    /* @4144000 not */
    /* @4144004 bf */
    v25 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v25)) goto L_4144044;
    /* @4144008 constant */
    /* @4144012 cast */
    /* @4144016 constant */
    /* @4144020 cast */
    /* @4144024 constant */
    /* @4144028 cast */
    /* @4144032 call */
    GM_SITE(vm, 298, 4144032);
    /* @4144040 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4144044: ;
    /* @4144044 constant */
    /* @4144048 cast */
    /* @4144052 load */
    /* @4144060 load */
    /* @4144068 call */
    GM_SITE(vm, 298, 4144068);
    /* @4144076 store */
    v26 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v26);
    /* @4144084 load */
    /* @4144092 constant */
    /* @4144096 cmp */
    /* @4144100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4144524;
    /* @4144104 constant */
    /* @4144108 load */
    /* @4144116 cast */
    /* @4144120 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4144128 constant */
    /* @4144132 cast */
    /* @4144136 load */
    /* @4144144 load */
    /* @4144152 load */
    /* @4144160 load */
    /* @4144168 call */
    GM_SITE(vm, 298, 4144168);
    /* @4144176 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4144180 load */
    /* @4144188 cast */
    /* @4144192 dup */
    /* @4144196 load */
    /* @4144204 load */
    /* @4144212 sub */
    /* @4144216 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4144224 constant */
    /* @4144228 cast */
    /* @4144232 load */
    /* @4144240 load */
    /* @4144248 call */
    GM_SITE(vm, 298, 4144248);
    /* @4144256 store */
    v27 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v27);
    /* @4144264 load */
    /* @4144272 load */
    /* @4144280 cast */
    /* @4144284 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4144292 constant */
    /* @4144296 load */
    /* @4144304 cast */
    /* @4144308 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "stunned", VAL(1));
    /* @4144316 constant */
    /* @4144320 load */
    /* @4144328 cast */
    /* @4144332 constant */
    /* @4144336 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(4), VAL(10));
    /* @4144344 load */
    /* @4144352 constant */
    /* @4144356 add */
    /* @4144360 store */
    v28 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v28);
    /* @4144368 load */
    /* @4144376 constant */
    /* @4144380 cmp */
    /* @4144384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4144416;
    /* @4144388 constant */
    /* @4144392 load */
    /* @4144400 cast */
    /* @4144404 constant */
    /* @4144408 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4144416: ;
    /* @4144416 load */
    /* @4144424 constant */
    /* @4144428 cmp */
    /* @4144432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4144440;
    /* @4144436 b */
    goto L_4144524;
    L_4144440: ;
    /* @4144440 load */
    /* @4144448 constant */
    /* @4144452 cmp */
    /* @4144456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4144524;
    /* @4144460 constant */
    /* @4144464 cast */
    /* @4144468 call */
    GM_SITE(vm, 298, 4144468);
    /* @4144476 cast */
    /* @4144480 not */
    /* @4144484 bf */
    v29 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v29)) goto L_4144524;
    /* @4144488 constant */
    /* @4144492 cast */
    /* @4144496 constant */
    /* @4144500 cast */
    /* @4144504 constant */
    /* @4144508 cast */
    /* @4144512 call */
    GM_SITE(vm, 298, 4144512);
    /* @4144520 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4144524: ;
    /* @4144524 constant */
    /* @4144528 cast */
    /* @4144532 load */
    /* @4144540 load */
    /* @4144548 call */
    GM_SITE(vm, 298, 4144548);
    /* @4144556 store */
    v30 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v30);
    /* @4144564 load */
    /* @4144572 constant */
    /* @4144576 cmp */
    /* @4144580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4145004;
    /* @4144584 constant */
    /* @4144588 load */
    /* @4144596 cast */
    /* @4144600 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4144608 constant */
    /* @4144612 cast */
    /* @4144616 load */
    /* @4144624 load */
    /* @4144632 load */
    /* @4144640 load */
    /* @4144648 call */
    GM_SITE(vm, 298, 4144648);
    /* @4144656 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4144660 load */
    /* @4144668 cast */
    /* @4144672 dup */
    /* @4144676 load */
    /* @4144684 load */
    /* @4144692 sub */
    /* @4144696 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4144704 constant */
    /* @4144708 cast */
    /* @4144712 load */
    /* @4144720 load */
    /* @4144728 call */
    GM_SITE(vm, 298, 4144728);
    /* @4144736 store */
    v31 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v31);
    /* @4144744 load */
    /* @4144752 load */
    /* @4144760 cast */
    /* @4144764 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4144772 constant */
    /* @4144776 load */
    /* @4144784 cast */
    /* @4144788 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4144796 constant */
    /* @4144800 load */
    /* @4144808 cast */
    /* @4144812 constant */
    /* @4144816 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4144824 load */
    /* @4144832 constant */
    /* @4144836 add */
    /* @4144840 store */
    v32 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v32);
    /* @4144848 load */
    /* @4144856 constant */
    /* @4144860 cmp */
    /* @4144864 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4144896;
    /* @4144868 constant */
    /* @4144872 load */
    /* @4144880 cast */
    /* @4144884 constant */
    /* @4144888 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4144896: ;
    /* @4144896 load */
    /* @4144904 constant */
    /* @4144908 cmp */
    /* @4144912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4144920;
    /* @4144916 b */
    goto L_4145004;
    L_4144920: ;
    /* @4144920 load */
    /* @4144928 constant */
    /* @4144932 cmp */
    /* @4144936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4145004;
    /* @4144940 constant */
    /* @4144944 cast */
    /* @4144948 call */
    GM_SITE(vm, 298, 4144948);
    /* @4144956 cast */
    /* @4144960 not */
    /* @4144964 bf */
    v33 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v33)) goto L_4145004;
    /* @4144968 constant */
    /* @4144972 cast */
    /* @4144976 constant */
    /* @4144980 cast */
    /* @4144984 constant */
    /* @4144988 cast */
    /* @4144992 call */
    GM_SITE(vm, 298, 4144992);
    /* @4145000 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4145004: ;
    /* @4145004 constant */
    /* @4145008 cast */
    /* @4145012 load */
    /* @4145020 load */
    /* @4145028 call */
    GM_SITE(vm, 298, 4145028);
    /* @4145036 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v34);
    /* @4145044 load */
    /* @4145052 constant */
    /* @4145056 cmp */
    /* @4145060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4145484;
    /* @4145064 constant */
    /* @4145068 load */
    /* @4145076 cast */
    /* @4145080 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4145088 constant */
    /* @4145092 cast */
    /* @4145096 load */
    /* @4145104 load */
    /* @4145112 load */
    /* @4145120 load */
    /* @4145128 call */
    GM_SITE(vm, 298, 4145128);
    /* @4145136 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4145140 load */
    /* @4145148 cast */
    /* @4145152 dup */
    /* @4145156 load */
    /* @4145164 load */
    /* @4145172 sub */
    /* @4145176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4145184 constant */
    /* @4145188 cast */
    /* @4145192 load */
    /* @4145200 load */
    /* @4145208 call */
    GM_SITE(vm, 298, 4145208);
    /* @4145216 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v35);
    /* @4145224 load */
    /* @4145232 load */
    /* @4145240 cast */
    /* @4145244 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4145252 constant */
    /* @4145256 load */
    /* @4145264 cast */
    /* @4145268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4145276 constant */
    /* @4145280 load */
    /* @4145288 cast */
    /* @4145292 constant */
    /* @4145296 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4145304 load */
    /* @4145312 constant */
    /* @4145316 add */
    /* @4145320 store */
    v36 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v36);
    /* @4145328 load */
    /* @4145336 constant */
    /* @4145340 cmp */
    /* @4145344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4145376;
    /* @4145348 constant */
    /* @4145352 load */
    /* @4145360 cast */
    /* @4145364 constant */
    /* @4145368 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4145376: ;
    /* @4145376 load */
    /* @4145384 constant */
    /* @4145388 cmp */
    /* @4145392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4145400;
    /* @4145396 b */
    goto L_4145484;
    L_4145400: ;
    /* @4145400 load */
    /* @4145408 constant */
    /* @4145412 cmp */
    /* @4145416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4145484;
    /* @4145420 constant */
    /* @4145424 cast */
    /* @4145428 call */
    GM_SITE(vm, 298, 4145428);
    /* @4145436 cast */
    /* @4145440 not */
    /* @4145444 bf */
    v37 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v37)) goto L_4145484;
    /* @4145448 constant */
    /* @4145452 cast */
    /* @4145456 constant */
    /* @4145460 cast */
    /* @4145464 constant */
    /* @4145468 cast */
    /* @4145472 call */
    GM_SITE(vm, 298, 4145472);
    /* @4145480 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4145484: ;
    /* @4145484 constant */
    /* @4145488 cast */
    /* @4145492 load */
    /* @4145500 load */
    /* @4145508 call */
    GM_SITE(vm, 298, 4145508);
    /* @4145516 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v38);
    /* @4145524 load */
    /* @4145532 constant */
    /* @4145536 cmp */
    /* @4145540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4145964;
    /* @4145544 constant */
    /* @4145548 load */
    /* @4145556 cast */
    /* @4145560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4145568 constant */
    /* @4145572 cast */
    /* @4145576 load */
    /* @4145584 load */
    /* @4145592 load */
    /* @4145600 load */
    /* @4145608 call */
    GM_SITE(vm, 298, 4145608);
    /* @4145616 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4145620 load */
    /* @4145628 cast */
    /* @4145632 dup */
    /* @4145636 load */
    /* @4145644 load */
    /* @4145652 sub */
    /* @4145656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4145664 constant */
    /* @4145668 cast */
    /* @4145672 load */
    /* @4145680 load */
    /* @4145688 call */
    GM_SITE(vm, 298, 4145688);
    /* @4145696 store */
    v39 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v39);
    /* @4145704 load */
    /* @4145712 load */
    /* @4145720 cast */
    /* @4145724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4145732 constant */
    /* @4145736 load */
    /* @4145744 cast */
    /* @4145748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4145756 constant */
    /* @4145760 load */
    /* @4145768 cast */
    /* @4145772 constant */
    /* @4145776 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4145784 load */
    /* @4145792 constant */
    /* @4145796 add */
    /* @4145800 store */
    v40 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v40);
    /* @4145808 load */
    /* @4145816 constant */
    /* @4145820 cmp */
    /* @4145824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4145856;
    /* @4145828 constant */
    /* @4145832 load */
    /* @4145840 cast */
    /* @4145844 constant */
    /* @4145848 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4145856: ;
    /* @4145856 load */
    /* @4145864 constant */
    /* @4145868 cmp */
    /* @4145872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4145880;
    /* @4145876 b */
    goto L_4145964;
    L_4145880: ;
    /* @4145880 load */
    /* @4145888 constant */
    /* @4145892 cmp */
    /* @4145896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4145964;
    /* @4145900 constant */
    /* @4145904 cast */
    /* @4145908 call */
    GM_SITE(vm, 298, 4145908);
    /* @4145916 cast */
    /* @4145920 not */
    /* @4145924 bf */
    v41 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v41)) goto L_4145964;
    /* @4145928 constant */
    /* @4145932 cast */
    /* @4145936 constant */
    /* @4145940 cast */
    /* @4145944 constant */
    /* @4145948 cast */
    /* @4145952 call */
    GM_SITE(vm, 298, 4145952);
    /* @4145960 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4145964: ;
    /* @4145964 constant */
    /* @4145968 cast */
    /* @4145972 load */
    /* @4145980 load */
    /* @4145988 call */
    GM_SITE(vm, 298, 4145988);
    /* @4145996 store */
    v42 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v42);
    /* @4146004 load */
    /* @4146012 constant */
    /* @4146016 cmp */
    /* @4146020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4146444;
    /* @4146024 constant */
    /* @4146028 load */
    /* @4146036 cast */
    /* @4146040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4146048 constant */
    /* @4146052 cast */
    /* @4146056 load */
    /* @4146064 load */
    /* @4146072 load */
    /* @4146080 load */
    /* @4146088 call */
    GM_SITE(vm, 298, 4146088);
    /* @4146096 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4146100 load */
    /* @4146108 cast */
    /* @4146112 dup */
    /* @4146116 load */
    /* @4146124 load */
    /* @4146132 sub */
    /* @4146136 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4146144 constant */
    /* @4146148 cast */
    /* @4146152 load */
    /* @4146160 load */
    /* @4146168 call */
    GM_SITE(vm, 298, 4146168);
    /* @4146176 store */
    v43 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v43);
    /* @4146184 load */
    /* @4146192 load */
    /* @4146200 cast */
    /* @4146204 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4146212 constant */
    /* @4146216 load */
    /* @4146224 cast */
    /* @4146228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4146236 constant */
    /* @4146240 load */
    /* @4146248 cast */
    /* @4146252 constant */
    /* @4146256 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4146264 load */
    /* @4146272 constant */
    /* @4146276 add */
    /* @4146280 store */
    v44 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v44);
    /* @4146288 load */
    /* @4146296 constant */
    /* @4146300 cmp */
    /* @4146304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4146336;
    /* @4146308 constant */
    /* @4146312 load */
    /* @4146320 cast */
    /* @4146324 constant */
    /* @4146328 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4146336: ;
    /* @4146336 load */
    /* @4146344 constant */
    /* @4146348 cmp */
    /* @4146352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4146360;
    /* @4146356 b */
    goto L_4146444;
    L_4146360: ;
    /* @4146360 load */
    /* @4146368 constant */
    /* @4146372 cmp */
    /* @4146376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4146444;
    /* @4146380 constant */
    /* @4146384 cast */
    /* @4146388 call */
    GM_SITE(vm, 298, 4146388);
    /* @4146396 cast */
    /* @4146400 not */
    /* @4146404 bf */
    v45 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v45)) goto L_4146444;
    /* @4146408 constant */
    /* @4146412 cast */
    /* @4146416 constant */
    /* @4146420 cast */
    /* @4146424 constant */
    /* @4146428 cast */
    /* @4146432 call */
    GM_SITE(vm, 298, 4146432);
    /* @4146440 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4146444: ;
    /* @4146444 constant */
    /* @4146448 cast */
    /* @4146452 load */
    /* @4146460 load */
    /* @4146468 call */
    GM_SITE(vm, 298, 4146468);
    /* @4146476 store */
    v46 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v46);
    /* @4146484 load */
    /* @4146492 constant */
    /* @4146496 cmp */
    /* @4146500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4146924;
    /* @4146504 constant */
    /* @4146508 load */
    /* @4146516 cast */
    /* @4146520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4146528 constant */
    /* @4146532 cast */
    /* @4146536 load */
    /* @4146544 load */
    /* @4146552 load */
    /* @4146560 load */
    /* @4146568 call */
    GM_SITE(vm, 298, 4146568);
    /* @4146576 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4146580 load */
    /* @4146588 cast */
    /* @4146592 dup */
    /* @4146596 load */
    /* @4146604 load */
    /* @4146612 sub */
    /* @4146616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4146624 constant */
    /* @4146628 cast */
    /* @4146632 load */
    /* @4146640 load */
    /* @4146648 call */
    GM_SITE(vm, 298, 4146648);
    /* @4146656 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v47);
    /* @4146664 load */
    /* @4146672 load */
    /* @4146680 cast */
    /* @4146684 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4146692 constant */
    /* @4146696 load */
    /* @4146704 cast */
    /* @4146708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4146716 constant */
    /* @4146720 load */
    /* @4146728 cast */
    /* @4146732 constant */
    /* @4146736 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4146744 load */
    /* @4146752 constant */
    /* @4146756 add */
    /* @4146760 store */
    v48 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v48);
    /* @4146768 load */
    /* @4146776 constant */
    /* @4146780 cmp */
    /* @4146784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4146816;
    /* @4146788 constant */
    /* @4146792 load */
    /* @4146800 cast */
    /* @4146804 constant */
    /* @4146808 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4146816: ;
    /* @4146816 load */
    /* @4146824 constant */
    /* @4146828 cmp */
    /* @4146832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4146840;
    /* @4146836 b */
    goto L_4146924;
    L_4146840: ;
    /* @4146840 load */
    /* @4146848 constant */
    /* @4146852 cmp */
    /* @4146856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4146924;
    /* @4146860 constant */
    /* @4146864 cast */
    /* @4146868 call */
    GM_SITE(vm, 298, 4146868);
    /* @4146876 cast */
    /* @4146880 not */
    /* @4146884 bf */
    v49 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v49)) goto L_4146924;
    /* @4146888 constant */
    /* @4146892 cast */
    /* @4146896 constant */
    /* @4146900 cast */
    /* @4146904 constant */
    /* @4146908 cast */
    /* @4146912 call */
    GM_SITE(vm, 298, 4146912);
    /* @4146920 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4146924: ;
    /* @4146924 constant */
    /* @4146928 cast */
    /* @4146932 load */
    /* @4146940 load */
    /* @4146948 call */
    GM_SITE(vm, 298, 4146948);
    /* @4146956 store */
    v50 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v50);
    /* @4146964 load */
    /* @4146972 constant */
    /* @4146976 cmp */
    /* @4146980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4147404;
    /* @4146984 constant */
    /* @4146988 load */
    /* @4146996 cast */
    /* @4147000 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4147008 constant */
    /* @4147012 cast */
    /* @4147016 load */
    /* @4147024 load */
    /* @4147032 load */
    /* @4147040 load */
    /* @4147048 call */
    GM_SITE(vm, 298, 4147048);
    /* @4147056 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4147060 load */
    /* @4147068 cast */
    /* @4147072 dup */
    /* @4147076 load */
    /* @4147084 load */
    /* @4147092 sub */
    /* @4147096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4147104 constant */
    /* @4147108 cast */
    /* @4147112 load */
    /* @4147120 load */
    /* @4147128 call */
    GM_SITE(vm, 298, 4147128);
    /* @4147136 store */
    v51 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v51);
    /* @4147144 load */
    /* @4147152 load */
    /* @4147160 cast */
    /* @4147164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4147172 constant */
    /* @4147176 load */
    /* @4147184 cast */
    /* @4147188 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4147196 constant */
    /* @4147200 load */
    /* @4147208 cast */
    /* @4147212 constant */
    /* @4147216 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4147224 load */
    /* @4147232 constant */
    /* @4147236 add */
    /* @4147240 store */
    v52 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v52);
    /* @4147248 load */
    /* @4147256 constant */
    /* @4147260 cmp */
    /* @4147264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4147296;
    /* @4147268 constant */
    /* @4147272 load */
    /* @4147280 cast */
    /* @4147284 constant */
    /* @4147288 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4147296: ;
    /* @4147296 load */
    /* @4147304 constant */
    /* @4147308 cmp */
    /* @4147312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4147320;
    /* @4147316 b */
    goto L_4147404;
    L_4147320: ;
    /* @4147320 load */
    /* @4147328 constant */
    /* @4147332 cmp */
    /* @4147336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4147404;
    /* @4147340 constant */
    /* @4147344 cast */
    /* @4147348 call */
    GM_SITE(vm, 298, 4147348);
    /* @4147356 cast */
    /* @4147360 not */
    /* @4147364 bf */
    v53 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v53)) goto L_4147404;
    /* @4147368 constant */
    /* @4147372 cast */
    /* @4147376 constant */
    /* @4147380 cast */
    /* @4147384 constant */
    /* @4147388 cast */
    /* @4147392 call */
    GM_SITE(vm, 298, 4147392);
    /* @4147400 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4147404: ;
    /* @4147404 constant */
    /* @4147408 cast */
    /* @4147412 load */
    /* @4147420 load */
    /* @4147428 call */
    GM_SITE(vm, 298, 4147428);
    /* @4147436 store */
    v54 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v54);
    /* @4147444 load */
    /* @4147452 constant */
    /* @4147456 cmp */
    /* @4147460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4147884;
    /* @4147464 constant */
    /* @4147468 load */
    /* @4147476 cast */
    /* @4147480 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4147488 constant */
    /* @4147492 cast */
    /* @4147496 load */
    /* @4147504 load */
    /* @4147512 load */
    /* @4147520 load */
    /* @4147528 call */
    GM_SITE(vm, 298, 4147528);
    /* @4147536 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4147540 load */
    /* @4147548 cast */
    /* @4147552 dup */
    /* @4147556 load */
    /* @4147564 load */
    /* @4147572 sub */
    /* @4147576 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "boomerangdamage")));
    /* @4147584 constant */
    /* @4147588 cast */
    /* @4147592 load */
    /* @4147600 load */
    /* @4147608 call */
    GM_SITE(vm, 298, 4147608);
    /* @4147616 store */
    v55 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v55);
    /* @4147624 load */
    /* @4147632 load */
    /* @4147640 cast */
    /* @4147644 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "boomerangdamage"));
    /* @4147652 constant */
    /* @4147656 load */
    /* @4147664 cast */
    /* @4147668 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4147676 constant */
    /* @4147680 load */
    /* @4147688 cast */
    /* @4147692 constant */
    /* @4147696 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4147704 load */
    /* @4147712 constant */
    /* @4147716 add */
    /* @4147720 store */
    v56 = GM_ADD(GM_READ(vm, -5, "boomerangxp"), VAL(1));
    GM_WRITE(vm, -5, "boomerangxp", v56);
    /* @4147728 load */
    /* @4147736 constant */
    /* @4147740 cmp */
    /* @4147744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4147776;
    /* @4147748 constant */
    /* @4147752 load */
    /* @4147760 cast */
    /* @4147764 constant */
    /* @4147768 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4147776: ;
    /* @4147776 load */
    /* @4147784 constant */
    /* @4147788 cmp */
    /* @4147792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4147800;
    /* @4147796 b */
    goto L_4147884;
    L_4147800: ;
    /* @4147800 load */
    /* @4147808 constant */
    /* @4147812 cmp */
    /* @4147816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4147884;
    /* @4147820 constant */
    /* @4147824 cast */
    /* @4147828 call */
    GM_SITE(vm, 298, 4147828);
    /* @4147836 cast */
    /* @4147840 not */
    /* @4147844 bf */
    v57 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v57)) goto L_4147884;
    /* @4147848 constant */
    /* @4147852 cast */
    /* @4147856 constant */
    /* @4147860 cast */
    /* @4147864 constant */
    /* @4147868 cast */
    /* @4147872 call */
    GM_SITE(vm, 298, 4147872);
    /* @4147880 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4147884: ;
    return;
}
