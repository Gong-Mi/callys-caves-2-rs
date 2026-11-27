/* generated from CODE 289 (gml_Object_obj_laserbeam_Step_0), source start 4113416, end 4122012. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0289(GmVM* vm) {
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
    Val v58;
    Val v59;
    Val v60;
    /* @4113416 load */
    /* @4113424 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4113432 constant */
    /* @4113436 cast */
    /* @4113440 load */
    /* @4113448 load */
    /* @4113456 call */
    GM_SITE(vm, 289, 4113456);
    /* @4113464 store */
    v1 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v1);
    /* @4113472 load */
    /* @4113480 constant */
    /* @4113484 cmp */
    /* @4113488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4113916;
    /* @4113492 constant */
    /* @4113496 load */
    /* @4113504 cast */
    /* @4113508 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4113516 constant */
    /* @4113520 cast */
    /* @4113524 load */
    /* @4113532 load */
    /* @4113540 load */
    /* @4113548 load */
    /* @4113556 call */
    GM_SITE(vm, 289, 4113556);
    /* @4113564 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4113568 load */
    /* @4113576 constant */
    /* @4113580 cmp */
    /* @4113584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4113724;
    /* @4113588 load */
    /* @4113596 cast */
    /* @4113600 dup */
    /* @4113604 load */
    /* @4113612 load */
    /* @4113620 sub */
    /* @4113624 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "laserdamage")));
    /* @4113632 constant */
    /* @4113636 cast */
    /* @4113640 load */
    /* @4113648 load */
    /* @4113656 call */
    GM_SITE(vm, 289, 4113656);
    /* @4113664 store */
    v2 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v2);
    /* @4113672 load */
    /* @4113680 load */
    /* @4113688 cast */
    /* @4113692 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4113700 load */
    /* @4113708 constant */
    /* @4113712 add */
    /* @4113716 store */
    v3 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v3);
    L_4113724: ;
    /* @4113724 constant */
    /* @4113728 load */
    /* @4113736 cast */
    /* @4113740 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4113748 constant */
    /* @4113752 load */
    /* @4113760 cast */
    /* @4113764 constant */
    /* @4113768 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(5));
    /* @4113776 load */
    /* @4113784 constant */
    /* @4113788 cmp */
    /* @4113792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4113800;
    /* @4113796 b */
    goto L_4113856;
    L_4113800: ;
    /* @4113800 load */
    /* @4113808 constant */
    /* @4113812 cmp */
    /* @4113816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4113856;
    /* @4113820 constant */
    /* @4113824 cast */
    /* @4113828 constant */
    /* @4113832 cast */
    /* @4113836 constant */
    /* @4113840 cast */
    /* @4113844 call */
    GM_SITE(vm, 289, 4113844);
    /* @4113852 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4113856: ;
    /* @4113856 load */
    /* @4113864 constant */
    /* @4113868 cmp */
    /* @4113872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4113904;
    /* @4113876 constant */
    /* @4113880 load */
    /* @4113888 cast */
    /* @4113892 constant */
    /* @4113896 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4113904: ;
    /* @4113904 call */
    GM_SITE(vm, 289, 4113904);
    /* @4113912 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4113916: ;
    /* @4113916 constant */
    /* @4113920 cast */
    /* @4113924 load */
    /* @4113932 load */
    /* @4113940 call */
    GM_SITE(vm, 289, 4113940);
    /* @4113948 store */
    v4 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v4);
    /* @4113956 load */
    /* @4113964 constant */
    /* @4113968 cmp */
    /* @4113972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4114400;
    /* @4113976 constant */
    /* @4113980 load */
    /* @4113988 cast */
    /* @4113992 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4114000 constant */
    /* @4114004 cast */
    /* @4114008 load */
    /* @4114016 load */
    /* @4114024 load */
    /* @4114032 load */
    /* @4114040 call */
    GM_SITE(vm, 289, 4114040);
    /* @4114048 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4114052 load */
    /* @4114060 constant */
    /* @4114064 cmp */
    /* @4114068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4114208;
    /* @4114072 load */
    /* @4114080 cast */
    /* @4114084 dup */
    /* @4114088 load */
    /* @4114096 load */
    /* @4114104 sub */
    /* @4114108 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "laserdamage")));
    /* @4114116 constant */
    /* @4114120 cast */
    /* @4114124 load */
    /* @4114132 load */
    /* @4114140 call */
    GM_SITE(vm, 289, 4114140);
    /* @4114148 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v5);
    /* @4114156 load */
    /* @4114164 load */
    /* @4114172 cast */
    /* @4114176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4114184 load */
    /* @4114192 constant */
    /* @4114196 add */
    /* @4114200 store */
    v6 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v6);
    L_4114208: ;
    /* @4114208 constant */
    /* @4114212 load */
    /* @4114220 cast */
    /* @4114224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4114232 constant */
    /* @4114236 load */
    /* @4114244 cast */
    /* @4114248 constant */
    /* @4114252 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4114260 load */
    /* @4114268 constant */
    /* @4114272 cmp */
    /* @4114276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4114284;
    /* @4114280 b */
    goto L_4114340;
    L_4114284: ;
    /* @4114284 load */
    /* @4114292 constant */
    /* @4114296 cmp */
    /* @4114300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4114340;
    /* @4114304 constant */
    /* @4114308 cast */
    /* @4114312 constant */
    /* @4114316 cast */
    /* @4114320 constant */
    /* @4114324 cast */
    /* @4114328 call */
    GM_SITE(vm, 289, 4114328);
    /* @4114336 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4114340: ;
    /* @4114340 load */
    /* @4114348 constant */
    /* @4114352 cmp */
    /* @4114356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4114388;
    /* @4114360 constant */
    /* @4114364 load */
    /* @4114372 cast */
    /* @4114376 constant */
    /* @4114380 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4114388: ;
    /* @4114388 call */
    GM_SITE(vm, 289, 4114388);
    /* @4114396 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4114400: ;
    /* @4114400 constant */
    /* @4114404 cast */
    /* @4114408 load */
    /* @4114416 load */
    /* @4114424 call */
    GM_SITE(vm, 289, 4114424);
    /* @4114432 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v7);
    /* @4114440 load */
    /* @4114448 constant */
    /* @4114452 cmp */
    /* @4114456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4114832;
    /* @4114460 constant */
    /* @4114464 load */
    /* @4114472 cast */
    /* @4114476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4114484 constant */
    /* @4114488 cast */
    /* @4114492 load */
    /* @4114500 load */
    /* @4114508 load */
    /* @4114516 load */
    /* @4114524 call */
    GM_SITE(vm, 289, 4114524);
    /* @4114532 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4114536 load */
    /* @4114544 constant */
    /* @4114548 cmp */
    /* @4114552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4114692;
    /* @4114556 load */
    /* @4114564 cast */
    /* @4114568 dup */
    /* @4114572 load */
    /* @4114580 load */
    /* @4114588 sub */
    /* @4114592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "laserdamage")));
    /* @4114600 constant */
    /* @4114604 cast */
    /* @4114608 load */
    /* @4114616 load */
    /* @4114624 call */
    GM_SITE(vm, 289, 4114624);
    /* @4114632 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4114640 load */
    /* @4114648 load */
    /* @4114656 cast */
    /* @4114660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4114668 load */
    /* @4114676 constant */
    /* @4114680 add */
    /* @4114684 store */
    v9 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v9);
    L_4114692: ;
    /* @4114692 load */
    /* @4114700 constant */
    /* @4114704 cmp */
    /* @4114708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4114716;
    /* @4114712 b */
    goto L_4114772;
    L_4114716: ;
    /* @4114716 load */
    /* @4114724 constant */
    /* @4114728 cmp */
    /* @4114732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4114772;
    /* @4114736 constant */
    /* @4114740 cast */
    /* @4114744 constant */
    /* @4114748 cast */
    /* @4114752 constant */
    /* @4114756 cast */
    /* @4114760 call */
    GM_SITE(vm, 289, 4114760);
    /* @4114768 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4114772: ;
    /* @4114772 load */
    /* @4114780 constant */
    /* @4114784 cmp */
    /* @4114788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4114820;
    /* @4114792 constant */
    /* @4114796 load */
    /* @4114804 cast */
    /* @4114808 constant */
    /* @4114812 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4114820: ;
    /* @4114820 call */
    GM_SITE(vm, 289, 4114820);
    /* @4114828 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4114832: ;
    /* @4114832 constant */
    /* @4114836 cast */
    /* @4114840 load */
    /* @4114848 load */
    /* @4114856 call */
    GM_SITE(vm, 289, 4114856);
    /* @4114864 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v10);
    /* @4114872 load */
    /* @4114880 constant */
    /* @4114884 cmp */
    /* @4114888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4115264;
    /* @4114892 constant */
    /* @4114896 load */
    /* @4114904 cast */
    /* @4114908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4114916 constant */
    /* @4114920 cast */
    /* @4114924 load */
    /* @4114932 load */
    /* @4114940 load */
    /* @4114948 load */
    /* @4114956 call */
    GM_SITE(vm, 289, 4114956);
    /* @4114964 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4114968 load */
    /* @4114976 constant */
    /* @4114980 cmp */
    /* @4114984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4115124;
    /* @4114988 load */
    /* @4114996 cast */
    /* @4115000 dup */
    /* @4115004 load */
    /* @4115012 load */
    /* @4115020 sub */
    /* @4115024 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "laserdamage")));
    /* @4115032 constant */
    /* @4115036 cast */
    /* @4115040 load */
    /* @4115048 load */
    /* @4115056 call */
    GM_SITE(vm, 289, 4115056);
    /* @4115064 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4115072 load */
    /* @4115080 load */
    /* @4115088 cast */
    /* @4115092 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4115100 load */
    /* @4115108 constant */
    /* @4115112 add */
    /* @4115116 store */
    v12 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v12);
    L_4115124: ;
    /* @4115124 load */
    /* @4115132 constant */
    /* @4115136 cmp */
    /* @4115140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4115148;
    /* @4115144 b */
    goto L_4115204;
    L_4115148: ;
    /* @4115148 load */
    /* @4115156 constant */
    /* @4115160 cmp */
    /* @4115164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4115204;
    /* @4115168 constant */
    /* @4115172 cast */
    /* @4115176 constant */
    /* @4115180 cast */
    /* @4115184 constant */
    /* @4115188 cast */
    /* @4115192 call */
    GM_SITE(vm, 289, 4115192);
    /* @4115200 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4115204: ;
    /* @4115204 load */
    /* @4115212 constant */
    /* @4115216 cmp */
    /* @4115220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4115252;
    /* @4115224 constant */
    /* @4115228 load */
    /* @4115236 cast */
    /* @4115240 constant */
    /* @4115244 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4115252: ;
    /* @4115252 call */
    GM_SITE(vm, 289, 4115252);
    /* @4115260 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4115264: ;
    /* @4115264 constant */
    /* @4115268 cast */
    /* @4115272 load */
    /* @4115280 load */
    /* @4115288 call */
    GM_SITE(vm, 289, 4115288);
    /* @4115296 store */
    v13 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v13);
    /* @4115304 load */
    /* @4115312 constant */
    /* @4115316 cmp */
    /* @4115320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4115696;
    /* @4115324 constant */
    /* @4115328 load */
    /* @4115336 cast */
    /* @4115340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4115348 constant */
    /* @4115352 cast */
    /* @4115356 load */
    /* @4115364 load */
    /* @4115372 load */
    /* @4115380 load */
    /* @4115388 call */
    GM_SITE(vm, 289, 4115388);
    /* @4115396 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4115400 load */
    /* @4115408 constant */
    /* @4115412 cmp */
    /* @4115416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4115556;
    /* @4115420 load */
    /* @4115428 cast */
    /* @4115432 dup */
    /* @4115436 load */
    /* @4115444 load */
    /* @4115452 sub */
    /* @4115456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "laserdamage")));
    /* @4115464 constant */
    /* @4115468 cast */
    /* @4115472 load */
    /* @4115480 load */
    /* @4115488 call */
    GM_SITE(vm, 289, 4115488);
    /* @4115496 store */
    v14 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v14);
    /* @4115504 load */
    /* @4115512 load */
    /* @4115520 cast */
    /* @4115524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4115532 load */
    /* @4115540 constant */
    /* @4115544 add */
    /* @4115548 store */
    v15 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v15);
    L_4115556: ;
    /* @4115556 load */
    /* @4115564 constant */
    /* @4115568 cmp */
    /* @4115572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4115580;
    /* @4115576 b */
    goto L_4115636;
    L_4115580: ;
    /* @4115580 load */
    /* @4115588 constant */
    /* @4115592 cmp */
    /* @4115596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4115636;
    /* @4115600 constant */
    /* @4115604 cast */
    /* @4115608 constant */
    /* @4115612 cast */
    /* @4115616 constant */
    /* @4115620 cast */
    /* @4115624 call */
    GM_SITE(vm, 289, 4115624);
    /* @4115632 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4115636: ;
    /* @4115636 load */
    /* @4115644 constant */
    /* @4115648 cmp */
    /* @4115652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4115684;
    /* @4115656 constant */
    /* @4115660 load */
    /* @4115668 cast */
    /* @4115672 constant */
    /* @4115676 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4115684: ;
    /* @4115684 call */
    GM_SITE(vm, 289, 4115684);
    /* @4115692 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4115696: ;
    /* @4115696 constant */
    /* @4115700 cast */
    /* @4115704 load */
    /* @4115712 load */
    /* @4115720 call */
    GM_SITE(vm, 289, 4115720);
    /* @4115728 store */
    v16 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v16);
    /* @4115736 load */
    /* @4115744 constant */
    /* @4115748 cmp */
    /* @4115752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4116128;
    /* @4115756 constant */
    /* @4115760 load */
    /* @4115768 cast */
    /* @4115772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4115780 constant */
    /* @4115784 cast */
    /* @4115788 load */
    /* @4115796 load */
    /* @4115804 load */
    /* @4115812 load */
    /* @4115820 call */
    GM_SITE(vm, 289, 4115820);
    /* @4115828 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4115832 load */
    /* @4115840 constant */
    /* @4115844 cmp */
    /* @4115848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4115988;
    /* @4115852 load */
    /* @4115860 cast */
    /* @4115864 dup */
    /* @4115868 load */
    /* @4115876 load */
    /* @4115884 sub */
    /* @4115888 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "laserdamage")));
    /* @4115896 constant */
    /* @4115900 cast */
    /* @4115904 load */
    /* @4115912 load */
    /* @4115920 call */
    GM_SITE(vm, 289, 4115920);
    /* @4115928 store */
    v17 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v17);
    /* @4115936 load */
    /* @4115944 load */
    /* @4115952 cast */
    /* @4115956 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4115964 load */
    /* @4115972 constant */
    /* @4115976 add */
    /* @4115980 store */
    v18 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v18);
    L_4115988: ;
    /* @4115988 load */
    /* @4115996 constant */
    /* @4116000 cmp */
    /* @4116004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4116012;
    /* @4116008 b */
    goto L_4116068;
    L_4116012: ;
    /* @4116012 load */
    /* @4116020 constant */
    /* @4116024 cmp */
    /* @4116028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4116068;
    /* @4116032 constant */
    /* @4116036 cast */
    /* @4116040 constant */
    /* @4116044 cast */
    /* @4116048 constant */
    /* @4116052 cast */
    /* @4116056 call */
    GM_SITE(vm, 289, 4116056);
    /* @4116064 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4116068: ;
    /* @4116068 load */
    /* @4116076 constant */
    /* @4116080 cmp */
    /* @4116084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4116116;
    /* @4116088 constant */
    /* @4116092 load */
    /* @4116100 cast */
    /* @4116104 constant */
    /* @4116108 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4116116: ;
    /* @4116116 call */
    GM_SITE(vm, 289, 4116116);
    /* @4116124 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4116128: ;
    /* @4116128 constant */
    /* @4116132 cast */
    /* @4116136 load */
    /* @4116144 load */
    /* @4116152 call */
    GM_SITE(vm, 289, 4116152);
    /* @4116160 store */
    v19 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v19);
    /* @4116168 load */
    /* @4116176 constant */
    /* @4116180 cmp */
    /* @4116184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4116560;
    /* @4116188 constant */
    /* @4116192 load */
    /* @4116200 cast */
    /* @4116204 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4116212 constant */
    /* @4116216 cast */
    /* @4116220 load */
    /* @4116228 load */
    /* @4116236 load */
    /* @4116244 load */
    /* @4116252 call */
    GM_SITE(vm, 289, 4116252);
    /* @4116260 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4116264 load */
    /* @4116272 constant */
    /* @4116276 cmp */
    /* @4116280 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4116420;
    /* @4116284 load */
    /* @4116292 cast */
    /* @4116296 dup */
    /* @4116300 load */
    /* @4116308 load */
    /* @4116316 sub */
    /* @4116320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "laserdamage")));
    /* @4116328 constant */
    /* @4116332 cast */
    /* @4116336 load */
    /* @4116344 load */
    /* @4116352 call */
    GM_SITE(vm, 289, 4116352);
    /* @4116360 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4116368 load */
    /* @4116376 load */
    /* @4116384 cast */
    /* @4116388 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4116396 load */
    /* @4116404 constant */
    /* @4116408 add */
    /* @4116412 store */
    v21 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v21);
    L_4116420: ;
    /* @4116420 load */
    /* @4116428 constant */
    /* @4116432 cmp */
    /* @4116436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4116444;
    /* @4116440 b */
    goto L_4116500;
    L_4116444: ;
    /* @4116444 load */
    /* @4116452 constant */
    /* @4116456 cmp */
    /* @4116460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4116500;
    /* @4116464 constant */
    /* @4116468 cast */
    /* @4116472 constant */
    /* @4116476 cast */
    /* @4116480 constant */
    /* @4116484 cast */
    /* @4116488 call */
    GM_SITE(vm, 289, 4116488);
    /* @4116496 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4116500: ;
    /* @4116500 load */
    /* @4116508 constant */
    /* @4116512 cmp */
    /* @4116516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4116548;
    /* @4116520 constant */
    /* @4116524 load */
    /* @4116532 cast */
    /* @4116536 constant */
    /* @4116540 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4116548: ;
    /* @4116548 call */
    GM_SITE(vm, 289, 4116548);
    /* @4116556 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4116560: ;
    /* @4116560 constant */
    /* @4116564 cast */
    /* @4116568 load */
    /* @4116576 load */
    /* @4116584 call */
    GM_SITE(vm, 289, 4116584);
    /* @4116592 store */
    v22 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v22);
    /* @4116600 load */
    /* @4116608 constant */
    /* @4116612 cmp */
    /* @4116616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4116992;
    /* @4116620 constant */
    /* @4116624 load */
    /* @4116632 cast */
    /* @4116636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4116644 constant */
    /* @4116648 cast */
    /* @4116652 load */
    /* @4116660 load */
    /* @4116668 load */
    /* @4116676 load */
    /* @4116684 call */
    GM_SITE(vm, 289, 4116684);
    /* @4116692 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4116696 load */
    /* @4116704 constant */
    /* @4116708 cmp */
    /* @4116712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4116852;
    /* @4116716 load */
    /* @4116724 cast */
    /* @4116728 dup */
    /* @4116732 load */
    /* @4116740 load */
    /* @4116748 sub */
    /* @4116752 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "laserdamage")));
    /* @4116760 constant */
    /* @4116764 cast */
    /* @4116768 load */
    /* @4116776 load */
    /* @4116784 call */
    GM_SITE(vm, 289, 4116784);
    /* @4116792 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4116800 load */
    /* @4116808 load */
    /* @4116816 cast */
    /* @4116820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4116828 load */
    /* @4116836 constant */
    /* @4116840 add */
    /* @4116844 store */
    v24 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v24);
    L_4116852: ;
    /* @4116852 load */
    /* @4116860 constant */
    /* @4116864 cmp */
    /* @4116868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4116876;
    /* @4116872 b */
    goto L_4116932;
    L_4116876: ;
    /* @4116876 load */
    /* @4116884 constant */
    /* @4116888 cmp */
    /* @4116892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4116932;
    /* @4116896 constant */
    /* @4116900 cast */
    /* @4116904 constant */
    /* @4116908 cast */
    /* @4116912 constant */
    /* @4116916 cast */
    /* @4116920 call */
    GM_SITE(vm, 289, 4116920);
    /* @4116928 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4116932: ;
    /* @4116932 load */
    /* @4116940 constant */
    /* @4116944 cmp */
    /* @4116948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4116980;
    /* @4116952 constant */
    /* @4116956 load */
    /* @4116964 cast */
    /* @4116968 constant */
    /* @4116972 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4116980: ;
    /* @4116980 call */
    GM_SITE(vm, 289, 4116980);
    /* @4116988 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4116992: ;
    /* @4116992 constant */
    /* @4116996 cast */
    /* @4117000 load */
    /* @4117008 load */
    /* @4117016 call */
    GM_SITE(vm, 289, 4117016);
    /* @4117024 store */
    v25 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v25);
    /* @4117032 load */
    /* @4117040 constant */
    /* @4117044 cmp */
    /* @4117048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4117424;
    /* @4117052 constant */
    /* @4117056 load */
    /* @4117064 cast */
    /* @4117068 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4117076 constant */
    /* @4117080 cast */
    /* @4117084 load */
    /* @4117092 load */
    /* @4117100 load */
    /* @4117108 load */
    /* @4117116 call */
    GM_SITE(vm, 289, 4117116);
    /* @4117124 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4117128 load */
    /* @4117136 constant */
    /* @4117140 cmp */
    /* @4117144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4117284;
    /* @4117148 load */
    /* @4117156 cast */
    /* @4117160 dup */
    /* @4117164 load */
    /* @4117172 load */
    /* @4117180 sub */
    /* @4117184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "laserdamage")));
    /* @4117192 constant */
    /* @4117196 cast */
    /* @4117200 load */
    /* @4117208 load */
    /* @4117216 call */
    GM_SITE(vm, 289, 4117216);
    /* @4117224 store */
    v26 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v26);
    /* @4117232 load */
    /* @4117240 load */
    /* @4117248 cast */
    /* @4117252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4117260 load */
    /* @4117268 constant */
    /* @4117272 add */
    /* @4117276 store */
    v27 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v27);
    L_4117284: ;
    /* @4117284 load */
    /* @4117292 constant */
    /* @4117296 cmp */
    /* @4117300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4117308;
    /* @4117304 b */
    goto L_4117364;
    L_4117308: ;
    /* @4117308 load */
    /* @4117316 constant */
    /* @4117320 cmp */
    /* @4117324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4117364;
    /* @4117328 constant */
    /* @4117332 cast */
    /* @4117336 constant */
    /* @4117340 cast */
    /* @4117344 constant */
    /* @4117348 cast */
    /* @4117352 call */
    GM_SITE(vm, 289, 4117352);
    /* @4117360 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4117364: ;
    /* @4117364 load */
    /* @4117372 constant */
    /* @4117376 cmp */
    /* @4117380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4117412;
    /* @4117384 constant */
    /* @4117388 load */
    /* @4117396 cast */
    /* @4117400 constant */
    /* @4117404 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4117412: ;
    /* @4117412 call */
    GM_SITE(vm, 289, 4117412);
    /* @4117420 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4117424: ;
    /* @4117424 constant */
    /* @4117428 cast */
    /* @4117432 load */
    /* @4117440 load */
    /* @4117448 call */
    GM_SITE(vm, 289, 4117448);
    /* @4117456 store */
    v28 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v28);
    /* @4117464 load */
    /* @4117472 constant */
    /* @4117476 cmp */
    /* @4117480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4117856;
    /* @4117484 constant */
    /* @4117488 load */
    /* @4117496 cast */
    /* @4117500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4117508 constant */
    /* @4117512 cast */
    /* @4117516 load */
    /* @4117524 load */
    /* @4117532 load */
    /* @4117540 load */
    /* @4117548 call */
    GM_SITE(vm, 289, 4117548);
    /* @4117556 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4117560 load */
    /* @4117568 constant */
    /* @4117572 cmp */
    /* @4117576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4117716;
    /* @4117580 load */
    /* @4117588 cast */
    /* @4117592 dup */
    /* @4117596 load */
    /* @4117604 load */
    /* @4117612 sub */
    /* @4117616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "laserdamage")));
    /* @4117624 constant */
    /* @4117628 cast */
    /* @4117632 load */
    /* @4117640 load */
    /* @4117648 call */
    GM_SITE(vm, 289, 4117648);
    /* @4117656 store */
    v29 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v29);
    /* @4117664 load */
    /* @4117672 load */
    /* @4117680 cast */
    /* @4117684 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4117692 load */
    /* @4117700 constant */
    /* @4117704 add */
    /* @4117708 store */
    v30 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v30);
    L_4117716: ;
    /* @4117716 load */
    /* @4117724 constant */
    /* @4117728 cmp */
    /* @4117732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4117740;
    /* @4117736 b */
    goto L_4117796;
    L_4117740: ;
    /* @4117740 load */
    /* @4117748 constant */
    /* @4117752 cmp */
    /* @4117756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4117796;
    /* @4117760 constant */
    /* @4117764 cast */
    /* @4117768 constant */
    /* @4117772 cast */
    /* @4117776 constant */
    /* @4117780 cast */
    /* @4117784 call */
    GM_SITE(vm, 289, 4117784);
    /* @4117792 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4117796: ;
    /* @4117796 load */
    /* @4117804 constant */
    /* @4117808 cmp */
    /* @4117812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4117844;
    /* @4117816 constant */
    /* @4117820 load */
    /* @4117828 cast */
    /* @4117832 constant */
    /* @4117836 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4117844: ;
    /* @4117844 call */
    GM_SITE(vm, 289, 4117844);
    /* @4117852 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4117856: ;
    /* @4117856 constant */
    /* @4117860 cast */
    /* @4117864 load */
    /* @4117872 load */
    /* @4117880 call */
    GM_SITE(vm, 289, 4117880);
    /* @4117888 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v31);
    /* @4117896 load */
    /* @4117904 constant */
    /* @4117908 cmp */
    /* @4117912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4118288;
    /* @4117916 constant */
    /* @4117920 load */
    /* @4117928 cast */
    /* @4117932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4117940 constant */
    /* @4117944 cast */
    /* @4117948 load */
    /* @4117956 load */
    /* @4117964 load */
    /* @4117972 load */
    /* @4117980 call */
    GM_SITE(vm, 289, 4117980);
    /* @4117988 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4117992 load */
    /* @4118000 constant */
    /* @4118004 cmp */
    /* @4118008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4118148;
    /* @4118012 load */
    /* @4118020 cast */
    /* @4118024 dup */
    /* @4118028 load */
    /* @4118036 load */
    /* @4118044 sub */
    /* @4118048 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "laserdamage")));
    /* @4118056 constant */
    /* @4118060 cast */
    /* @4118064 load */
    /* @4118072 load */
    /* @4118080 call */
    GM_SITE(vm, 289, 4118080);
    /* @4118088 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4118096 load */
    /* @4118104 load */
    /* @4118112 cast */
    /* @4118116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4118124 load */
    /* @4118132 constant */
    /* @4118136 add */
    /* @4118140 store */
    v33 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v33);
    L_4118148: ;
    /* @4118148 load */
    /* @4118156 constant */
    /* @4118160 cmp */
    /* @4118164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4118172;
    /* @4118168 b */
    goto L_4118228;
    L_4118172: ;
    /* @4118172 load */
    /* @4118180 constant */
    /* @4118184 cmp */
    /* @4118188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4118228;
    /* @4118192 constant */
    /* @4118196 cast */
    /* @4118200 constant */
    /* @4118204 cast */
    /* @4118208 constant */
    /* @4118212 cast */
    /* @4118216 call */
    GM_SITE(vm, 289, 4118216);
    /* @4118224 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4118228: ;
    /* @4118228 load */
    /* @4118236 constant */
    /* @4118240 cmp */
    /* @4118244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4118276;
    /* @4118248 constant */
    /* @4118252 load */
    /* @4118260 cast */
    /* @4118264 constant */
    /* @4118268 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4118276: ;
    /* @4118276 call */
    GM_SITE(vm, 289, 4118276);
    /* @4118284 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4118288: ;
    /* @4118288 constant */
    /* @4118292 cast */
    /* @4118296 load */
    /* @4118304 load */
    /* @4118312 call */
    GM_SITE(vm, 289, 4118312);
    /* @4118320 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v34);
    /* @4118328 load */
    /* @4118336 constant */
    /* @4118340 cmp */
    /* @4118344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4118720;
    /* @4118348 constant */
    /* @4118352 load */
    /* @4118360 cast */
    /* @4118364 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4118372 constant */
    /* @4118376 cast */
    /* @4118380 load */
    /* @4118388 load */
    /* @4118396 load */
    /* @4118404 load */
    /* @4118412 call */
    GM_SITE(vm, 289, 4118412);
    /* @4118420 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4118424 load */
    /* @4118432 constant */
    /* @4118436 cmp */
    /* @4118440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4118580;
    /* @4118444 load */
    /* @4118452 cast */
    /* @4118456 dup */
    /* @4118460 load */
    /* @4118468 load */
    /* @4118476 sub */
    /* @4118480 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "laserdamage")));
    /* @4118488 constant */
    /* @4118492 cast */
    /* @4118496 load */
    /* @4118504 load */
    /* @4118512 call */
    GM_SITE(vm, 289, 4118512);
    /* @4118520 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v35);
    /* @4118528 load */
    /* @4118536 load */
    /* @4118544 cast */
    /* @4118548 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4118556 load */
    /* @4118564 constant */
    /* @4118568 add */
    /* @4118572 store */
    v36 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v36);
    L_4118580: ;
    /* @4118580 load */
    /* @4118588 constant */
    /* @4118592 cmp */
    /* @4118596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4118604;
    /* @4118600 b */
    goto L_4118660;
    L_4118604: ;
    /* @4118604 load */
    /* @4118612 constant */
    /* @4118616 cmp */
    /* @4118620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4118660;
    /* @4118624 constant */
    /* @4118628 cast */
    /* @4118632 constant */
    /* @4118636 cast */
    /* @4118640 constant */
    /* @4118644 cast */
    /* @4118648 call */
    GM_SITE(vm, 289, 4118648);
    /* @4118656 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4118660: ;
    /* @4118660 load */
    /* @4118668 constant */
    /* @4118672 cmp */
    /* @4118676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4118708;
    /* @4118680 constant */
    /* @4118684 load */
    /* @4118692 cast */
    /* @4118696 constant */
    /* @4118700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4118708: ;
    /* @4118708 call */
    GM_SITE(vm, 289, 4118708);
    /* @4118716 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4118720: ;
    /* @4118720 constant */
    /* @4118724 cast */
    /* @4118728 load */
    /* @4118736 load */
    /* @4118744 call */
    GM_SITE(vm, 289, 4118744);
    /* @4118752 store */
    v37 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v37);
    /* @4118760 load */
    /* @4118768 constant */
    /* @4118772 cmp */
    /* @4118776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4119152;
    /* @4118780 constant */
    /* @4118784 load */
    /* @4118792 cast */
    /* @4118796 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4118804 constant */
    /* @4118808 cast */
    /* @4118812 load */
    /* @4118820 load */
    /* @4118828 load */
    /* @4118836 load */
    /* @4118844 call */
    GM_SITE(vm, 289, 4118844);
    /* @4118852 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4118856 load */
    /* @4118864 constant */
    /* @4118868 cmp */
    /* @4118872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4119012;
    /* @4118876 load */
    /* @4118884 cast */
    /* @4118888 dup */
    /* @4118892 load */
    /* @4118900 load */
    /* @4118908 sub */
    /* @4118912 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "laserdamage")));
    /* @4118920 constant */
    /* @4118924 cast */
    /* @4118928 load */
    /* @4118936 load */
    /* @4118944 call */
    GM_SITE(vm, 289, 4118944);
    /* @4118952 store */
    v38 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v38);
    /* @4118960 load */
    /* @4118968 load */
    /* @4118976 cast */
    /* @4118980 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4118988 load */
    /* @4118996 constant */
    /* @4119000 add */
    /* @4119004 store */
    v39 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v39);
    L_4119012: ;
    /* @4119012 load */
    /* @4119020 constant */
    /* @4119024 cmp */
    /* @4119028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4119036;
    /* @4119032 b */
    goto L_4119092;
    L_4119036: ;
    /* @4119036 load */
    /* @4119044 constant */
    /* @4119048 cmp */
    /* @4119052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4119092;
    /* @4119056 constant */
    /* @4119060 cast */
    /* @4119064 constant */
    /* @4119068 cast */
    /* @4119072 constant */
    /* @4119076 cast */
    /* @4119080 call */
    GM_SITE(vm, 289, 4119080);
    /* @4119088 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4119092: ;
    /* @4119092 load */
    /* @4119100 constant */
    /* @4119104 cmp */
    /* @4119108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4119140;
    /* @4119112 constant */
    /* @4119116 load */
    /* @4119124 cast */
    /* @4119128 constant */
    /* @4119132 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4119140: ;
    /* @4119140 call */
    GM_SITE(vm, 289, 4119140);
    /* @4119148 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4119152: ;
    /* @4119152 constant */
    /* @4119156 cast */
    /* @4119160 load */
    /* @4119168 load */
    /* @4119176 call */
    GM_SITE(vm, 289, 4119176);
    /* @4119184 store */
    v40 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v40);
    /* @4119192 load */
    /* @4119200 constant */
    /* @4119204 cmp */
    /* @4119208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4119584;
    /* @4119212 constant */
    /* @4119216 load */
    /* @4119224 cast */
    /* @4119228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4119236 constant */
    /* @4119240 cast */
    /* @4119244 load */
    /* @4119252 load */
    /* @4119260 load */
    /* @4119268 load */
    /* @4119276 call */
    GM_SITE(vm, 289, 4119276);
    /* @4119284 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4119288 load */
    /* @4119296 constant */
    /* @4119300 cmp */
    /* @4119304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4119444;
    /* @4119308 load */
    /* @4119316 cast */
    /* @4119320 dup */
    /* @4119324 load */
    /* @4119332 load */
    /* @4119340 sub */
    /* @4119344 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "laserdamage")));
    /* @4119352 constant */
    /* @4119356 cast */
    /* @4119360 load */
    /* @4119368 load */
    /* @4119376 call */
    GM_SITE(vm, 289, 4119376);
    /* @4119384 store */
    v41 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v41);
    /* @4119392 load */
    /* @4119400 load */
    /* @4119408 cast */
    /* @4119412 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4119420 load */
    /* @4119428 constant */
    /* @4119432 add */
    /* @4119436 store */
    v42 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v42);
    L_4119444: ;
    /* @4119444 load */
    /* @4119452 constant */
    /* @4119456 cmp */
    /* @4119460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4119468;
    /* @4119464 b */
    goto L_4119524;
    L_4119468: ;
    /* @4119468 load */
    /* @4119476 constant */
    /* @4119480 cmp */
    /* @4119484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4119524;
    /* @4119488 constant */
    /* @4119492 cast */
    /* @4119496 constant */
    /* @4119500 cast */
    /* @4119504 constant */
    /* @4119508 cast */
    /* @4119512 call */
    GM_SITE(vm, 289, 4119512);
    /* @4119520 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4119524: ;
    /* @4119524 load */
    /* @4119532 constant */
    /* @4119536 cmp */
    /* @4119540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4119572;
    /* @4119544 constant */
    /* @4119548 load */
    /* @4119556 cast */
    /* @4119560 constant */
    /* @4119564 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4119572: ;
    /* @4119572 call */
    GM_SITE(vm, 289, 4119572);
    /* @4119580 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4119584: ;
    /* @4119584 constant */
    /* @4119588 cast */
    /* @4119592 load */
    /* @4119600 load */
    /* @4119608 call */
    GM_SITE(vm, 289, 4119608);
    /* @4119616 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v43);
    /* @4119624 load */
    /* @4119632 constant */
    /* @4119636 cmp */
    /* @4119640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4120044;
    /* @4119644 constant */
    /* @4119648 load */
    /* @4119656 cast */
    /* @4119660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4119668 constant */
    /* @4119672 cast */
    /* @4119676 load */
    /* @4119684 load */
    /* @4119692 load */
    /* @4119700 load */
    /* @4119708 call */
    GM_SITE(vm, 289, 4119708);
    /* @4119716 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4119720 load */
    /* @4119728 constant */
    /* @4119732 cmp */
    /* @4119736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4119904;
    /* @4119740 load */
    /* @4119748 cast */
    /* @4119752 dup */
    /* @4119756 load */
    /* @4119764 load */
    /* @4119772 sub */
    /* @4119776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "laserdamage")));
    /* @4119784 constant */
    /* @4119788 cast */
    /* @4119792 load */
    /* @4119800 load */
    /* @4119808 call */
    GM_SITE(vm, 289, 4119808);
    /* @4119816 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4119824 load */
    /* @4119832 load */
    /* @4119840 cast */
    /* @4119844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4119852 load */
    /* @4119860 constant */
    /* @4119864 add */
    /* @4119868 store */
    v45 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v45);
    /* @4119876 constant */
    /* @4119880 load */
    /* @4119888 cast */
    /* @4119892 constant */
    /* @4119896 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    L_4119904: ;
    /* @4119904 load */
    /* @4119912 constant */
    /* @4119916 cmp */
    /* @4119920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4119928;
    /* @4119924 b */
    goto L_4119984;
    L_4119928: ;
    /* @4119928 load */
    /* @4119936 constant */
    /* @4119940 cmp */
    /* @4119944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4119984;
    /* @4119948 constant */
    /* @4119952 cast */
    /* @4119956 constant */
    /* @4119960 cast */
    /* @4119964 constant */
    /* @4119968 cast */
    /* @4119972 call */
    GM_SITE(vm, 289, 4119972);
    /* @4119980 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4119984: ;
    /* @4119984 load */
    /* @4119992 constant */
    /* @4119996 cmp */
    /* @4120000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4120032;
    /* @4120004 constant */
    /* @4120008 load */
    /* @4120016 cast */
    /* @4120020 constant */
    /* @4120024 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4120032: ;
    /* @4120032 call */
    GM_SITE(vm, 289, 4120032);
    /* @4120040 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4120044: ;
    /* @4120044 constant */
    /* @4120048 cast */
    /* @4120052 load */
    /* @4120060 load */
    /* @4120068 call */
    GM_SITE(vm, 289, 4120068);
    /* @4120076 store */
    v46 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v46);
    /* @4120084 load */
    /* @4120092 constant */
    /* @4120096 cmp */
    /* @4120100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4120476;
    /* @4120104 constant */
    /* @4120108 load */
    /* @4120116 cast */
    /* @4120120 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4120128 constant */
    /* @4120132 cast */
    /* @4120136 load */
    /* @4120144 load */
    /* @4120152 load */
    /* @4120160 load */
    /* @4120168 call */
    GM_SITE(vm, 289, 4120168);
    /* @4120176 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4120180 load */
    /* @4120188 constant */
    /* @4120192 cmp */
    /* @4120196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4120336;
    /* @4120200 load */
    /* @4120208 cast */
    /* @4120212 dup */
    /* @4120216 load */
    /* @4120224 load */
    /* @4120232 sub */
    /* @4120236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "laserdamage")));
    /* @4120244 constant */
    /* @4120248 cast */
    /* @4120252 load */
    /* @4120260 load */
    /* @4120268 call */
    GM_SITE(vm, 289, 4120268);
    /* @4120276 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v47);
    /* @4120284 load */
    /* @4120292 load */
    /* @4120300 cast */
    /* @4120304 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4120312 load */
    /* @4120320 constant */
    /* @4120324 add */
    /* @4120328 store */
    v48 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v48);
    L_4120336: ;
    /* @4120336 load */
    /* @4120344 constant */
    /* @4120348 cmp */
    /* @4120352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4120360;
    /* @4120356 b */
    goto L_4120416;
    L_4120360: ;
    /* @4120360 load */
    /* @4120368 constant */
    /* @4120372 cmp */
    /* @4120376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4120416;
    /* @4120380 constant */
    /* @4120384 cast */
    /* @4120388 constant */
    /* @4120392 cast */
    /* @4120396 constant */
    /* @4120400 cast */
    /* @4120404 call */
    GM_SITE(vm, 289, 4120404);
    /* @4120412 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4120416: ;
    /* @4120416 load */
    /* @4120424 constant */
    /* @4120428 cmp */
    /* @4120432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4120464;
    /* @4120436 constant */
    /* @4120440 load */
    /* @4120448 cast */
    /* @4120452 constant */
    /* @4120456 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4120464: ;
    /* @4120464 call */
    GM_SITE(vm, 289, 4120464);
    /* @4120472 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4120476: ;
    /* @4120476 constant */
    /* @4120480 cast */
    /* @4120484 load */
    /* @4120492 load */
    /* @4120500 call */
    GM_SITE(vm, 289, 4120500);
    /* @4120508 store */
    v49 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v49);
    /* @4120516 load */
    /* @4120524 constant */
    /* @4120528 cmp */
    /* @4120532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4120860;
    /* @4120536 constant */
    /* @4120540 load */
    /* @4120548 cast */
    /* @4120552 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4120560 constant */
    /* @4120564 cast */
    /* @4120568 load */
    /* @4120576 load */
    /* @4120584 load */
    /* @4120592 load */
    /* @4120600 call */
    GM_SITE(vm, 289, 4120600);
    /* @4120608 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4120612 load */
    /* @4120620 constant */
    /* @4120624 cmp */
    /* @4120628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4120768;
    /* @4120632 load */
    /* @4120640 cast */
    /* @4120644 dup */
    /* @4120648 load */
    /* @4120656 load */
    /* @4120664 sub */
    /* @4120668 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "laserdamage")));
    /* @4120676 constant */
    /* @4120680 cast */
    /* @4120684 load */
    /* @4120692 load */
    /* @4120700 call */
    GM_SITE(vm, 289, 4120700);
    /* @4120708 store */
    v50 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v50);
    /* @4120716 load */
    /* @4120724 load */
    /* @4120732 cast */
    /* @4120736 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4120744 load */
    /* @4120752 constant */
    /* @4120756 add */
    /* @4120760 store */
    v51 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v51);
    L_4120768: ;
    /* @4120768 load */
    /* @4120776 constant */
    /* @4120780 cmp */
    /* @4120784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4120792;
    /* @4120788 b */
    goto L_4120848;
    L_4120792: ;
    /* @4120792 load */
    /* @4120800 constant */
    /* @4120804 cmp */
    /* @4120808 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4120848;
    /* @4120812 constant */
    /* @4120816 cast */
    /* @4120820 constant */
    /* @4120824 cast */
    /* @4120828 constant */
    /* @4120832 cast */
    /* @4120836 call */
    GM_SITE(vm, 289, 4120836);
    /* @4120844 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4120848: ;
    /* @4120848 call */
    GM_SITE(vm, 289, 4120848);
    /* @4120856 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4120860: ;
    /* @4120860 constant */
    /* @4120864 cast */
    /* @4120868 load */
    /* @4120876 load */
    /* @4120884 call */
    GM_SITE(vm, 289, 4120884);
    /* @4120892 store */
    v52 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v52);
    /* @4120900 load */
    /* @4120908 constant */
    /* @4120912 cmp */
    /* @4120916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4121244;
    /* @4120920 constant */
    /* @4120924 load */
    /* @4120932 cast */
    /* @4120936 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4120944 constant */
    /* @4120948 cast */
    /* @4120952 load */
    /* @4120960 load */
    /* @4120968 load */
    /* @4120976 load */
    /* @4120984 call */
    GM_SITE(vm, 289, 4120984);
    /* @4120992 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4120996 load */
    /* @4121004 constant */
    /* @4121008 cmp */
    /* @4121012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4121152;
    /* @4121016 load */
    /* @4121024 cast */
    /* @4121028 dup */
    /* @4121032 load */
    /* @4121040 load */
    /* @4121048 sub */
    /* @4121052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "laserdamage")));
    /* @4121060 constant */
    /* @4121064 cast */
    /* @4121068 load */
    /* @4121076 load */
    /* @4121084 call */
    GM_SITE(vm, 289, 4121084);
    /* @4121092 store */
    v53 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v53);
    /* @4121100 load */
    /* @4121108 load */
    /* @4121116 cast */
    /* @4121120 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4121128 load */
    /* @4121136 constant */
    /* @4121140 add */
    /* @4121144 store */
    v54 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v54);
    L_4121152: ;
    /* @4121152 load */
    /* @4121160 constant */
    /* @4121164 cmp */
    /* @4121168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4121176;
    /* @4121172 b */
    goto L_4121232;
    L_4121176: ;
    /* @4121176 load */
    /* @4121184 constant */
    /* @4121188 cmp */
    /* @4121192 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4121232;
    /* @4121196 constant */
    /* @4121200 cast */
    /* @4121204 constant */
    /* @4121208 cast */
    /* @4121212 constant */
    /* @4121216 cast */
    /* @4121220 call */
    GM_SITE(vm, 289, 4121220);
    /* @4121228 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4121232: ;
    /* @4121232 call */
    GM_SITE(vm, 289, 4121232);
    /* @4121240 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4121244: ;
    /* @4121244 constant */
    /* @4121248 cast */
    /* @4121252 load */
    /* @4121260 load */
    /* @4121268 call */
    GM_SITE(vm, 289, 4121268);
    /* @4121276 store */
    v55 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v55);
    /* @4121284 load */
    /* @4121292 constant */
    /* @4121296 cmp */
    /* @4121300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4121628;
    /* @4121304 constant */
    /* @4121308 load */
    /* @4121316 cast */
    /* @4121320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4121328 constant */
    /* @4121332 cast */
    /* @4121336 load */
    /* @4121344 load */
    /* @4121352 load */
    /* @4121360 load */
    /* @4121368 call */
    GM_SITE(vm, 289, 4121368);
    /* @4121376 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4121380 load */
    /* @4121388 constant */
    /* @4121392 cmp */
    /* @4121396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4121536;
    /* @4121400 load */
    /* @4121408 cast */
    /* @4121412 dup */
    /* @4121416 load */
    /* @4121424 load */
    /* @4121432 sub */
    /* @4121436 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "laserdamage")));
    /* @4121444 constant */
    /* @4121448 cast */
    /* @4121452 load */
    /* @4121460 load */
    /* @4121468 call */
    GM_SITE(vm, 289, 4121468);
    /* @4121476 store */
    v56 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v56);
    /* @4121484 load */
    /* @4121492 load */
    /* @4121500 cast */
    /* @4121504 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4121512 load */
    /* @4121520 constant */
    /* @4121524 add */
    /* @4121528 store */
    v57 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v57);
    L_4121536: ;
    /* @4121536 load */
    /* @4121544 constant */
    /* @4121548 cmp */
    /* @4121552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4121560;
    /* @4121556 b */
    goto L_4121616;
    L_4121560: ;
    /* @4121560 load */
    /* @4121568 constant */
    /* @4121572 cmp */
    /* @4121576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4121616;
    /* @4121580 constant */
    /* @4121584 cast */
    /* @4121588 constant */
    /* @4121592 cast */
    /* @4121596 constant */
    /* @4121600 cast */
    /* @4121604 call */
    GM_SITE(vm, 289, 4121604);
    /* @4121612 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4121616: ;
    /* @4121616 call */
    GM_SITE(vm, 289, 4121616);
    /* @4121624 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4121628: ;
    /* @4121628 constant */
    /* @4121632 cast */
    /* @4121636 load */
    /* @4121644 load */
    /* @4121652 call */
    GM_SITE(vm, 289, 4121652);
    /* @4121660 store */
    v58 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v58);
    /* @4121668 load */
    /* @4121676 constant */
    /* @4121680 cmp */
    /* @4121684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4122012;
    /* @4121688 constant */
    /* @4121692 load */
    /* @4121700 cast */
    /* @4121704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4121712 constant */
    /* @4121716 cast */
    /* @4121720 load */
    /* @4121728 load */
    /* @4121736 load */
    /* @4121744 load */
    /* @4121752 call */
    GM_SITE(vm, 289, 4121752);
    /* @4121760 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4121764 load */
    /* @4121772 constant */
    /* @4121776 cmp */
    /* @4121780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laser") == VAL(1)))) goto L_4121920;
    /* @4121784 load */
    /* @4121792 cast */
    /* @4121796 dup */
    /* @4121800 load */
    /* @4121808 load */
    /* @4121816 sub */
    /* @4121820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "laserdamage")));
    /* @4121828 constant */
    /* @4121832 cast */
    /* @4121836 load */
    /* @4121844 load */
    /* @4121852 call */
    GM_SITE(vm, 289, 4121852);
    /* @4121860 store */
    v59 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v59);
    /* @4121868 load */
    /* @4121876 load */
    /* @4121884 cast */
    /* @4121888 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "laserdamage"));
    /* @4121896 load */
    /* @4121904 constant */
    /* @4121908 add */
    /* @4121912 store */
    v60 = GM_ADD(GM_READ(vm, -5, "laserxp"), VAL(1));
    GM_WRITE(vm, -5, "laserxp", v60);
    L_4121920: ;
    /* @4121920 load */
    /* @4121928 constant */
    /* @4121932 cmp */
    /* @4121936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4121944;
    /* @4121940 b */
    goto L_4122000;
    L_4121944: ;
    /* @4121944 load */
    /* @4121952 constant */
    /* @4121956 cmp */
    /* @4121960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4122000;
    /* @4121964 constant */
    /* @4121968 cast */
    /* @4121972 constant */
    /* @4121976 cast */
    /* @4121980 constant */
    /* @4121984 cast */
    /* @4121988 call */
    GM_SITE(vm, 289, 4121988);
    /* @4121996 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4122000: ;
    /* @4122000 call */
    GM_SITE(vm, 289, 4122000);
    /* @4122008 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4122012: ;
    return;
}
