/* generated from CODE 281 (gml_Object_obj_arrow_Step_0), source start 4080692, end 4089820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0281(GmVM* vm) {
    Val v1;
    Val p4080764_0;
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
    Val v61;
    Val v62;
    Val v63;
    /* @4080692 constant */
    /* @4080696 cast */
    /* @4080700 load */
    /* @4080708 load */
    /* @4080716 call */
    GM_SITE(vm, 281, 4080716);
    /* @4080724 cast */
    /* @4080728 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v1)) goto L_4080760;
    /* @4080732 constant */
    /* @4080736 cast */
    /* @4080740 call */
    GM_SITE(vm, 281, 4080740);
    /* @4080748 constant */
    /* @4080752 cmp */
    /* @4080756 b */
    v2 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(16));
    p4080764_0 = v2;
    goto L_4080764;
    L_4080760: ;
    /* @4080760 constant */
    p4080764_0 = VAL(0);
    L_4080764: ;
    /* @4080764 bf */
    if (!TRUTH(p4080764_0)) goto L_4080820;
    /* @4080768 constant */
    /* @4080772 cast */
    /* @4080776 load */
    /* @4080784 load */
    /* @4080792 call */
    GM_SITE(vm, 281, 4080792);
    /* @4080800 store */
    v3 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v3);
    /* @4080808 call */
    GM_SITE(vm, 281, 4080808);
    /* @4080816 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4080820: ;
    /* @4080820 constant */
    /* @4080832 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.3));
    /* @4080840 load */
    /* @4080848 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4080856 constant */
    /* @4080860 cast */
    /* @4080864 load */
    /* @4080872 load */
    /* @4080880 call */
    GM_SITE(vm, 281, 4080880);
    /* @4080888 store */
    v4 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v4);
    /* @4080896 load */
    /* @4080904 constant */
    /* @4080908 cmp */
    /* @4080912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4081328;
    /* @4080916 constant */
    /* @4080920 load */
    /* @4080928 cast */
    /* @4080932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4080940 constant */
    /* @4080944 cast */
    /* @4080948 load */
    /* @4080956 load */
    /* @4080964 load */
    /* @4080972 load */
    /* @4080980 call */
    GM_SITE(vm, 281, 4080980);
    /* @4080988 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4080992 load */
    /* @4081000 cast */
    /* @4081004 dup */
    /* @4081008 load */
    /* @4081016 load */
    /* @4081024 sub */
    /* @4081028 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "bowdamage")));
    /* @4081036 constant */
    /* @4081040 cast */
    /* @4081044 load */
    /* @4081052 load */
    /* @4081060 call */
    GM_SITE(vm, 281, 4081060);
    /* @4081068 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v5);
    /* @4081076 load */
    /* @4081084 load */
    /* @4081092 cast */
    /* @4081096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4081104 constant */
    /* @4081108 constant */
    /* @4081112 constant */
    /* @4081116 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4081124 constant */
    /* @4081128 load */
    /* @4081136 cast */
    /* @4081140 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4081148 constant */
    /* @4081152 load */
    /* @4081160 cast */
    /* @4081164 constant */
    /* @4081168 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4081176 load */
    /* @4081184 constant */
    /* @4081188 add */
    /* @4081192 store */
    v6 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v6);
    /* @4081200 load */
    /* @4081208 constant */
    /* @4081212 cmp */
    /* @4081216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4081224;
    /* @4081220 b */
    goto L_4081280;
    L_4081224: ;
    /* @4081224 load */
    /* @4081232 constant */
    /* @4081236 cmp */
    /* @4081240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4081280;
    /* @4081244 constant */
    /* @4081248 cast */
    /* @4081252 constant */
    /* @4081256 cast */
    /* @4081260 constant */
    /* @4081264 cast */
    /* @4081268 call */
    GM_SITE(vm, 281, 4081268);
    /* @4081276 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4081280: ;
    /* @4081280 load */
    /* @4081288 constant */
    /* @4081292 cmp */
    /* @4081296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4081328;
    /* @4081300 constant */
    /* @4081304 load */
    /* @4081312 cast */
    /* @4081316 constant */
    /* @4081320 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4081328: ;
    /* @4081328 constant */
    /* @4081332 cast */
    /* @4081336 load */
    /* @4081344 load */
    /* @4081352 call */
    GM_SITE(vm, 281, 4081352);
    /* @4081360 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v7);
    /* @4081368 load */
    /* @4081376 constant */
    /* @4081380 cmp */
    /* @4081384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4081800;
    /* @4081388 constant */
    /* @4081392 load */
    /* @4081400 cast */
    /* @4081404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4081412 constant */
    /* @4081416 cast */
    /* @4081420 load */
    /* @4081428 load */
    /* @4081436 load */
    /* @4081444 load */
    /* @4081452 call */
    GM_SITE(vm, 281, 4081452);
    /* @4081460 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4081464 load */
    /* @4081472 cast */
    /* @4081476 dup */
    /* @4081480 load */
    /* @4081488 load */
    /* @4081496 sub */
    /* @4081500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "bowdamage")));
    /* @4081508 constant */
    /* @4081512 cast */
    /* @4081516 load */
    /* @4081524 load */
    /* @4081532 call */
    GM_SITE(vm, 281, 4081532);
    /* @4081540 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4081548 load */
    /* @4081556 load */
    /* @4081564 cast */
    /* @4081568 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4081576 constant */
    /* @4081580 constant */
    /* @4081584 constant */
    /* @4081588 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4081596 constant */
    /* @4081600 load */
    /* @4081608 cast */
    /* @4081612 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4081620 constant */
    /* @4081624 load */
    /* @4081632 cast */
    /* @4081636 constant */
    /* @4081640 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4081648 load */
    /* @4081656 constant */
    /* @4081660 add */
    /* @4081664 store */
    v9 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v9);
    /* @4081672 load */
    /* @4081680 constant */
    /* @4081684 cmp */
    /* @4081688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4081696;
    /* @4081692 b */
    goto L_4081752;
    L_4081696: ;
    /* @4081696 load */
    /* @4081704 constant */
    /* @4081708 cmp */
    /* @4081712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4081752;
    /* @4081716 constant */
    /* @4081720 cast */
    /* @4081724 constant */
    /* @4081728 cast */
    /* @4081732 constant */
    /* @4081736 cast */
    /* @4081740 call */
    GM_SITE(vm, 281, 4081740);
    /* @4081748 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4081752: ;
    /* @4081752 load */
    /* @4081760 constant */
    /* @4081764 cmp */
    /* @4081768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4081800;
    /* @4081772 constant */
    /* @4081776 load */
    /* @4081784 cast */
    /* @4081788 constant */
    /* @4081792 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4081800: ;
    /* @4081800 constant */
    /* @4081804 cast */
    /* @4081808 load */
    /* @4081816 load */
    /* @4081824 call */
    GM_SITE(vm, 281, 4081824);
    /* @4081832 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v10);
    /* @4081840 load */
    /* @4081848 constant */
    /* @4081852 cmp */
    /* @4081856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4082272;
    /* @4081860 constant */
    /* @4081864 load */
    /* @4081872 cast */
    /* @4081876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4081884 constant */
    /* @4081888 cast */
    /* @4081892 load */
    /* @4081900 load */
    /* @4081908 load */
    /* @4081916 load */
    /* @4081924 call */
    GM_SITE(vm, 281, 4081924);
    /* @4081932 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4081936 load */
    /* @4081944 cast */
    /* @4081948 dup */
    /* @4081952 load */
    /* @4081960 load */
    /* @4081968 sub */
    /* @4081972 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "bowdamage")));
    /* @4081980 constant */
    /* @4081984 cast */
    /* @4081988 load */
    /* @4081996 load */
    /* @4082004 call */
    GM_SITE(vm, 281, 4082004);
    /* @4082012 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4082020 load */
    /* @4082028 load */
    /* @4082036 cast */
    /* @4082040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4082048 constant */
    /* @4082052 constant */
    /* @4082056 constant */
    /* @4082060 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4082068 constant */
    /* @4082072 load */
    /* @4082080 cast */
    /* @4082084 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4082092 constant */
    /* @4082096 load */
    /* @4082104 cast */
    /* @4082108 constant */
    /* @4082112 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4082120 load */
    /* @4082128 constant */
    /* @4082132 add */
    /* @4082136 store */
    v12 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v12);
    /* @4082144 load */
    /* @4082152 constant */
    /* @4082156 cmp */
    /* @4082160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4082168;
    /* @4082164 b */
    goto L_4082224;
    L_4082168: ;
    /* @4082168 load */
    /* @4082176 constant */
    /* @4082180 cmp */
    /* @4082184 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4082224;
    /* @4082188 constant */
    /* @4082192 cast */
    /* @4082196 constant */
    /* @4082200 cast */
    /* @4082204 constant */
    /* @4082208 cast */
    /* @4082212 call */
    GM_SITE(vm, 281, 4082212);
    /* @4082220 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4082224: ;
    /* @4082224 load */
    /* @4082232 constant */
    /* @4082236 cmp */
    /* @4082240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4082272;
    /* @4082244 constant */
    /* @4082248 load */
    /* @4082256 cast */
    /* @4082260 constant */
    /* @4082264 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4082272: ;
    /* @4082272 constant */
    /* @4082276 cast */
    /* @4082280 load */
    /* @4082288 load */
    /* @4082296 call */
    GM_SITE(vm, 281, 4082296);
    /* @4082304 store */
    v13 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v13);
    /* @4082312 load */
    /* @4082320 constant */
    /* @4082324 cmp */
    /* @4082328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4082744;
    /* @4082332 constant */
    /* @4082336 load */
    /* @4082344 cast */
    /* @4082348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4082356 constant */
    /* @4082360 cast */
    /* @4082364 load */
    /* @4082372 load */
    /* @4082380 load */
    /* @4082388 load */
    /* @4082396 call */
    GM_SITE(vm, 281, 4082396);
    /* @4082404 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4082408 load */
    /* @4082416 cast */
    /* @4082420 dup */
    /* @4082424 load */
    /* @4082432 load */
    /* @4082440 sub */
    /* @4082444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "bowdamage")));
    /* @4082452 constant */
    /* @4082456 cast */
    /* @4082460 load */
    /* @4082468 load */
    /* @4082476 call */
    GM_SITE(vm, 281, 4082476);
    /* @4082484 store */
    v14 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v14);
    /* @4082492 load */
    /* @4082500 load */
    /* @4082508 cast */
    /* @4082512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4082520 constant */
    /* @4082524 constant */
    /* @4082528 constant */
    /* @4082532 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4082540 constant */
    /* @4082544 load */
    /* @4082552 cast */
    /* @4082556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4082564 constant */
    /* @4082568 load */
    /* @4082576 cast */
    /* @4082580 constant */
    /* @4082584 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4082592 load */
    /* @4082600 constant */
    /* @4082604 add */
    /* @4082608 store */
    v15 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v15);
    /* @4082616 load */
    /* @4082624 constant */
    /* @4082628 cmp */
    /* @4082632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4082640;
    /* @4082636 b */
    goto L_4082696;
    L_4082640: ;
    /* @4082640 load */
    /* @4082648 constant */
    /* @4082652 cmp */
    /* @4082656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4082696;
    /* @4082660 constant */
    /* @4082664 cast */
    /* @4082668 constant */
    /* @4082672 cast */
    /* @4082676 constant */
    /* @4082680 cast */
    /* @4082684 call */
    GM_SITE(vm, 281, 4082684);
    /* @4082692 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4082696: ;
    /* @4082696 load */
    /* @4082704 constant */
    /* @4082708 cmp */
    /* @4082712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4082744;
    /* @4082716 constant */
    /* @4082720 load */
    /* @4082728 cast */
    /* @4082732 constant */
    /* @4082736 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4082744: ;
    /* @4082744 constant */
    /* @4082748 cast */
    /* @4082752 load */
    /* @4082760 load */
    /* @4082768 call */
    GM_SITE(vm, 281, 4082768);
    /* @4082776 store */
    v16 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v16);
    /* @4082784 load */
    /* @4082792 constant */
    /* @4082796 cmp */
    /* @4082800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4083164;
    /* @4082804 constant */
    /* @4082808 load */
    /* @4082816 cast */
    /* @4082820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4082828 constant */
    /* @4082832 cast */
    /* @4082836 load */
    /* @4082844 load */
    /* @4082852 load */
    /* @4082860 load */
    /* @4082868 call */
    GM_SITE(vm, 281, 4082868);
    /* @4082876 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4082880 load */
    /* @4082888 cast */
    /* @4082892 dup */
    /* @4082896 load */
    /* @4082904 load */
    /* @4082912 sub */
    /* @4082916 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "bowdamage")));
    /* @4082924 constant */
    /* @4082928 cast */
    /* @4082932 load */
    /* @4082940 load */
    /* @4082948 call */
    GM_SITE(vm, 281, 4082948);
    /* @4082956 store */
    v17 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v17);
    /* @4082964 load */
    /* @4082972 load */
    /* @4082980 cast */
    /* @4082984 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4082992 constant */
    /* @4082996 constant */
    /* @4083000 constant */
    /* @4083004 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4083012 load */
    /* @4083020 constant */
    /* @4083024 add */
    /* @4083028 store */
    v18 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v18);
    /* @4083036 load */
    /* @4083044 constant */
    /* @4083048 cmp */
    /* @4083052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4083060;
    /* @4083056 b */
    goto L_4083116;
    L_4083060: ;
    /* @4083060 load */
    /* @4083068 constant */
    /* @4083072 cmp */
    /* @4083076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4083116;
    /* @4083080 constant */
    /* @4083084 cast */
    /* @4083088 constant */
    /* @4083092 cast */
    /* @4083096 constant */
    /* @4083100 cast */
    /* @4083104 call */
    GM_SITE(vm, 281, 4083104);
    /* @4083112 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4083116: ;
    /* @4083116 load */
    /* @4083124 constant */
    /* @4083128 cmp */
    /* @4083132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4083164;
    /* @4083136 constant */
    /* @4083140 load */
    /* @4083148 cast */
    /* @4083152 constant */
    /* @4083156 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4083164: ;
    /* @4083164 constant */
    /* @4083168 cast */
    /* @4083172 load */
    /* @4083180 load */
    /* @4083188 call */
    GM_SITE(vm, 281, 4083188);
    /* @4083196 store */
    v19 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v19);
    /* @4083204 load */
    /* @4083212 constant */
    /* @4083216 cmp */
    /* @4083220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4083636;
    /* @4083224 constant */
    /* @4083228 load */
    /* @4083236 cast */
    /* @4083240 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4083248 constant */
    /* @4083252 cast */
    /* @4083256 load */
    /* @4083264 load */
    /* @4083272 load */
    /* @4083280 load */
    /* @4083288 call */
    GM_SITE(vm, 281, 4083288);
    /* @4083296 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4083300 load */
    /* @4083308 cast */
    /* @4083312 dup */
    /* @4083316 load */
    /* @4083324 load */
    /* @4083332 sub */
    /* @4083336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "bowdamage")));
    /* @4083344 constant */
    /* @4083348 cast */
    /* @4083352 load */
    /* @4083360 load */
    /* @4083368 call */
    GM_SITE(vm, 281, 4083368);
    /* @4083376 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4083384 load */
    /* @4083392 load */
    /* @4083400 cast */
    /* @4083404 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4083412 constant */
    /* @4083416 constant */
    /* @4083420 constant */
    /* @4083424 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4083432 constant */
    /* @4083436 load */
    /* @4083444 cast */
    /* @4083448 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4083456 constant */
    /* @4083460 load */
    /* @4083468 cast */
    /* @4083472 constant */
    /* @4083476 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4083484 load */
    /* @4083492 constant */
    /* @4083496 add */
    /* @4083500 store */
    v21 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v21);
    /* @4083508 load */
    /* @4083516 constant */
    /* @4083520 cmp */
    /* @4083524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4083532;
    /* @4083528 b */
    goto L_4083588;
    L_4083532: ;
    /* @4083532 load */
    /* @4083540 constant */
    /* @4083544 cmp */
    /* @4083548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4083588;
    /* @4083552 constant */
    /* @4083556 cast */
    /* @4083560 constant */
    /* @4083564 cast */
    /* @4083568 constant */
    /* @4083572 cast */
    /* @4083576 call */
    GM_SITE(vm, 281, 4083576);
    /* @4083584 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4083588: ;
    /* @4083588 load */
    /* @4083596 constant */
    /* @4083600 cmp */
    /* @4083604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4083636;
    /* @4083608 constant */
    /* @4083612 load */
    /* @4083620 cast */
    /* @4083624 constant */
    /* @4083628 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4083636: ;
    /* @4083636 constant */
    /* @4083640 cast */
    /* @4083644 load */
    /* @4083652 load */
    /* @4083660 call */
    GM_SITE(vm, 281, 4083660);
    /* @4083668 store */
    v22 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v22);
    /* @4083676 load */
    /* @4083684 constant */
    /* @4083688 cmp */
    /* @4083692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4084108;
    /* @4083696 constant */
    /* @4083700 load */
    /* @4083708 cast */
    /* @4083712 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4083720 constant */
    /* @4083724 cast */
    /* @4083728 load */
    /* @4083736 load */
    /* @4083744 load */
    /* @4083752 load */
    /* @4083760 call */
    GM_SITE(vm, 281, 4083760);
    /* @4083768 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4083772 load */
    /* @4083780 cast */
    /* @4083784 dup */
    /* @4083788 load */
    /* @4083796 load */
    /* @4083804 sub */
    /* @4083808 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "bowdamage")));
    /* @4083816 constant */
    /* @4083820 cast */
    /* @4083824 load */
    /* @4083832 load */
    /* @4083840 call */
    GM_SITE(vm, 281, 4083840);
    /* @4083848 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4083856 load */
    /* @4083864 load */
    /* @4083872 cast */
    /* @4083876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4083884 constant */
    /* @4083888 constant */
    /* @4083892 constant */
    /* @4083896 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4083904 constant */
    /* @4083908 load */
    /* @4083916 cast */
    /* @4083920 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4083928 constant */
    /* @4083932 load */
    /* @4083940 cast */
    /* @4083944 constant */
    /* @4083948 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4083956 load */
    /* @4083964 constant */
    /* @4083968 add */
    /* @4083972 store */
    v24 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v24);
    /* @4083980 load */
    /* @4083988 constant */
    /* @4083992 cmp */
    /* @4083996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4084004;
    /* @4084000 b */
    goto L_4084060;
    L_4084004: ;
    /* @4084004 load */
    /* @4084012 constant */
    /* @4084016 cmp */
    /* @4084020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4084060;
    /* @4084024 constant */
    /* @4084028 cast */
    /* @4084032 constant */
    /* @4084036 cast */
    /* @4084040 constant */
    /* @4084044 cast */
    /* @4084048 call */
    GM_SITE(vm, 281, 4084048);
    /* @4084056 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4084060: ;
    /* @4084060 load */
    /* @4084068 constant */
    /* @4084072 cmp */
    /* @4084076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4084108;
    /* @4084080 constant */
    /* @4084084 load */
    /* @4084092 cast */
    /* @4084096 constant */
    /* @4084100 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4084108: ;
    /* @4084108 constant */
    /* @4084112 cast */
    /* @4084116 load */
    /* @4084124 load */
    /* @4084132 call */
    GM_SITE(vm, 281, 4084132);
    /* @4084140 store */
    v25 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v25);
    /* @4084148 load */
    /* @4084156 constant */
    /* @4084160 cmp */
    /* @4084164 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4084580;
    /* @4084168 constant */
    /* @4084172 load */
    /* @4084180 cast */
    /* @4084184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4084192 constant */
    /* @4084196 cast */
    /* @4084200 load */
    /* @4084208 load */
    /* @4084216 load */
    /* @4084224 load */
    /* @4084232 call */
    GM_SITE(vm, 281, 4084232);
    /* @4084240 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4084244 load */
    /* @4084252 cast */
    /* @4084256 dup */
    /* @4084260 load */
    /* @4084268 load */
    /* @4084276 sub */
    /* @4084280 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "bowdamage")));
    /* @4084288 constant */
    /* @4084292 cast */
    /* @4084296 load */
    /* @4084304 load */
    /* @4084312 call */
    GM_SITE(vm, 281, 4084312);
    /* @4084320 store */
    v26 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v26);
    /* @4084328 load */
    /* @4084336 load */
    /* @4084344 cast */
    /* @4084348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4084356 constant */
    /* @4084360 constant */
    /* @4084364 constant */
    /* @4084368 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4084376 constant */
    /* @4084380 load */
    /* @4084388 cast */
    /* @4084392 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "stunned", VAL(1));
    /* @4084400 constant */
    /* @4084404 load */
    /* @4084412 cast */
    /* @4084416 constant */
    /* @4084420 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(4), VAL(10));
    /* @4084428 load */
    /* @4084436 constant */
    /* @4084440 add */
    /* @4084444 store */
    v27 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v27);
    /* @4084452 load */
    /* @4084460 constant */
    /* @4084464 cmp */
    /* @4084468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4084476;
    /* @4084472 b */
    goto L_4084532;
    L_4084476: ;
    /* @4084476 load */
    /* @4084484 constant */
    /* @4084488 cmp */
    /* @4084492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4084532;
    /* @4084496 constant */
    /* @4084500 cast */
    /* @4084504 constant */
    /* @4084508 cast */
    /* @4084512 constant */
    /* @4084516 cast */
    /* @4084520 call */
    GM_SITE(vm, 281, 4084520);
    /* @4084528 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4084532: ;
    /* @4084532 load */
    /* @4084540 constant */
    /* @4084544 cmp */
    /* @4084548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4084580;
    /* @4084552 constant */
    /* @4084556 load */
    /* @4084564 cast */
    /* @4084568 constant */
    /* @4084572 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4084580: ;
    /* @4084580 constant */
    /* @4084584 cast */
    /* @4084588 load */
    /* @4084596 load */
    /* @4084604 call */
    GM_SITE(vm, 281, 4084604);
    /* @4084612 store */
    v28 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v28);
    /* @4084620 load */
    /* @4084628 constant */
    /* @4084632 cmp */
    /* @4084636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4085052;
    /* @4084640 constant */
    /* @4084644 load */
    /* @4084652 cast */
    /* @4084656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4084664 constant */
    /* @4084668 cast */
    /* @4084672 load */
    /* @4084680 load */
    /* @4084688 load */
    /* @4084696 load */
    /* @4084704 call */
    GM_SITE(vm, 281, 4084704);
    /* @4084712 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4084716 load */
    /* @4084724 cast */
    /* @4084728 dup */
    /* @4084732 load */
    /* @4084740 load */
    /* @4084748 sub */
    /* @4084752 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "bowdamage")));
    /* @4084760 constant */
    /* @4084764 cast */
    /* @4084768 load */
    /* @4084776 load */
    /* @4084784 call */
    GM_SITE(vm, 281, 4084784);
    /* @4084792 store */
    v29 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v29);
    /* @4084800 load */
    /* @4084808 load */
    /* @4084816 cast */
    /* @4084820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4084828 constant */
    /* @4084832 constant */
    /* @4084836 constant */
    /* @4084840 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4084848 constant */
    /* @4084852 load */
    /* @4084860 cast */
    /* @4084864 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4084872 constant */
    /* @4084876 load */
    /* @4084884 cast */
    /* @4084888 constant */
    /* @4084892 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4084900 load */
    /* @4084908 constant */
    /* @4084912 add */
    /* @4084916 store */
    v30 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v30);
    /* @4084924 load */
    /* @4084932 constant */
    /* @4084936 cmp */
    /* @4084940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4084948;
    /* @4084944 b */
    goto L_4085004;
    L_4084948: ;
    /* @4084948 load */
    /* @4084956 constant */
    /* @4084960 cmp */
    /* @4084964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4085004;
    /* @4084968 constant */
    /* @4084972 cast */
    /* @4084976 constant */
    /* @4084980 cast */
    /* @4084984 constant */
    /* @4084988 cast */
    /* @4084992 call */
    GM_SITE(vm, 281, 4084992);
    /* @4085000 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4085004: ;
    /* @4085004 load */
    /* @4085012 constant */
    /* @4085016 cmp */
    /* @4085020 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4085052;
    /* @4085024 constant */
    /* @4085028 load */
    /* @4085036 cast */
    /* @4085040 constant */
    /* @4085044 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4085052: ;
    /* @4085052 constant */
    /* @4085056 cast */
    /* @4085060 load */
    /* @4085068 load */
    /* @4085076 call */
    GM_SITE(vm, 281, 4085076);
    /* @4085084 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v31);
    /* @4085092 load */
    /* @4085100 constant */
    /* @4085104 cmp */
    /* @4085108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4085524;
    /* @4085112 constant */
    /* @4085116 load */
    /* @4085124 cast */
    /* @4085128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4085136 constant */
    /* @4085140 cast */
    /* @4085144 load */
    /* @4085152 load */
    /* @4085160 load */
    /* @4085168 load */
    /* @4085176 call */
    GM_SITE(vm, 281, 4085176);
    /* @4085184 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4085188 load */
    /* @4085196 cast */
    /* @4085200 dup */
    /* @4085204 load */
    /* @4085212 load */
    /* @4085220 sub */
    /* @4085224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "bowdamage")));
    /* @4085232 constant */
    /* @4085236 cast */
    /* @4085240 load */
    /* @4085248 load */
    /* @4085256 call */
    GM_SITE(vm, 281, 4085256);
    /* @4085264 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4085272 load */
    /* @4085280 load */
    /* @4085288 cast */
    /* @4085292 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4085300 constant */
    /* @4085304 constant */
    /* @4085308 constant */
    /* @4085312 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4085320 constant */
    /* @4085324 load */
    /* @4085332 cast */
    /* @4085336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4085344 constant */
    /* @4085348 load */
    /* @4085356 cast */
    /* @4085360 constant */
    /* @4085364 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4085372 load */
    /* @4085380 constant */
    /* @4085384 add */
    /* @4085388 store */
    v33 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v33);
    /* @4085396 load */
    /* @4085404 constant */
    /* @4085408 cmp */
    /* @4085412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4085420;
    /* @4085416 b */
    goto L_4085476;
    L_4085420: ;
    /* @4085420 load */
    /* @4085428 constant */
    /* @4085432 cmp */
    /* @4085436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4085476;
    /* @4085440 constant */
    /* @4085444 cast */
    /* @4085448 constant */
    /* @4085452 cast */
    /* @4085456 constant */
    /* @4085460 cast */
    /* @4085464 call */
    GM_SITE(vm, 281, 4085464);
    /* @4085472 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4085476: ;
    /* @4085476 load */
    /* @4085484 constant */
    /* @4085488 cmp */
    /* @4085492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4085524;
    /* @4085496 constant */
    /* @4085500 load */
    /* @4085508 cast */
    /* @4085512 constant */
    /* @4085516 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4085524: ;
    /* @4085524 constant */
    /* @4085528 cast */
    /* @4085532 load */
    /* @4085540 load */
    /* @4085548 call */
    GM_SITE(vm, 281, 4085548);
    /* @4085556 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v34);
    /* @4085564 load */
    /* @4085572 constant */
    /* @4085576 cmp */
    /* @4085580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4085996;
    /* @4085584 constant */
    /* @4085588 load */
    /* @4085596 cast */
    /* @4085600 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4085608 constant */
    /* @4085612 cast */
    /* @4085616 load */
    /* @4085624 load */
    /* @4085632 load */
    /* @4085640 load */
    /* @4085648 call */
    GM_SITE(vm, 281, 4085648);
    /* @4085656 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4085660 load */
    /* @4085668 cast */
    /* @4085672 dup */
    /* @4085676 load */
    /* @4085684 load */
    /* @4085692 sub */
    /* @4085696 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "bowdamage")));
    /* @4085704 constant */
    /* @4085708 cast */
    /* @4085712 load */
    /* @4085720 load */
    /* @4085728 call */
    GM_SITE(vm, 281, 4085728);
    /* @4085736 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v35);
    /* @4085744 load */
    /* @4085752 load */
    /* @4085760 cast */
    /* @4085764 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4085772 constant */
    /* @4085776 constant */
    /* @4085780 constant */
    /* @4085784 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4085792 constant */
    /* @4085796 load */
    /* @4085804 cast */
    /* @4085808 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4085816 constant */
    /* @4085820 load */
    /* @4085828 cast */
    /* @4085832 constant */
    /* @4085836 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4085844 load */
    /* @4085852 constant */
    /* @4085856 add */
    /* @4085860 store */
    v36 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v36);
    /* @4085868 load */
    /* @4085876 constant */
    /* @4085880 cmp */
    /* @4085884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4085892;
    /* @4085888 b */
    goto L_4085948;
    L_4085892: ;
    /* @4085892 load */
    /* @4085900 constant */
    /* @4085904 cmp */
    /* @4085908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4085948;
    /* @4085912 constant */
    /* @4085916 cast */
    /* @4085920 constant */
    /* @4085924 cast */
    /* @4085928 constant */
    /* @4085932 cast */
    /* @4085936 call */
    GM_SITE(vm, 281, 4085936);
    /* @4085944 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4085948: ;
    /* @4085948 load */
    /* @4085956 constant */
    /* @4085960 cmp */
    /* @4085964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4085996;
    /* @4085968 constant */
    /* @4085972 load */
    /* @4085980 cast */
    /* @4085984 constant */
    /* @4085988 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4085996: ;
    /* @4085996 constant */
    /* @4086000 cast */
    /* @4086004 load */
    /* @4086012 load */
    /* @4086020 call */
    GM_SITE(vm, 281, 4086020);
    /* @4086028 store */
    v37 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v37);
    /* @4086036 load */
    /* @4086044 constant */
    /* @4086048 cmp */
    /* @4086052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4086468;
    /* @4086056 constant */
    /* @4086060 load */
    /* @4086068 cast */
    /* @4086072 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4086080 constant */
    /* @4086084 cast */
    /* @4086088 load */
    /* @4086096 load */
    /* @4086104 load */
    /* @4086112 load */
    /* @4086120 call */
    GM_SITE(vm, 281, 4086120);
    /* @4086128 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4086132 load */
    /* @4086140 cast */
    /* @4086144 dup */
    /* @4086148 load */
    /* @4086156 load */
    /* @4086164 sub */
    /* @4086168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "bowdamage")));
    /* @4086176 constant */
    /* @4086180 cast */
    /* @4086184 load */
    /* @4086192 load */
    /* @4086200 call */
    GM_SITE(vm, 281, 4086200);
    /* @4086208 store */
    v38 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v38);
    /* @4086216 load */
    /* @4086224 load */
    /* @4086232 cast */
    /* @4086236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4086244 constant */
    /* @4086248 constant */
    /* @4086252 constant */
    /* @4086256 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4086264 constant */
    /* @4086268 load */
    /* @4086276 cast */
    /* @4086280 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4086288 constant */
    /* @4086292 load */
    /* @4086300 cast */
    /* @4086304 constant */
    /* @4086308 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4086316 load */
    /* @4086324 constant */
    /* @4086328 add */
    /* @4086332 store */
    v39 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v39);
    /* @4086340 load */
    /* @4086348 constant */
    /* @4086352 cmp */
    /* @4086356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4086364;
    /* @4086360 b */
    goto L_4086420;
    L_4086364: ;
    /* @4086364 load */
    /* @4086372 constant */
    /* @4086376 cmp */
    /* @4086380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4086420;
    /* @4086384 constant */
    /* @4086388 cast */
    /* @4086392 constant */
    /* @4086396 cast */
    /* @4086400 constant */
    /* @4086404 cast */
    /* @4086408 call */
    GM_SITE(vm, 281, 4086408);
    /* @4086416 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4086420: ;
    /* @4086420 load */
    /* @4086428 constant */
    /* @4086432 cmp */
    /* @4086436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4086468;
    /* @4086440 constant */
    /* @4086444 load */
    /* @4086452 cast */
    /* @4086456 constant */
    /* @4086460 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4086468: ;
    /* @4086468 constant */
    /* @4086472 cast */
    /* @4086476 load */
    /* @4086484 load */
    /* @4086492 call */
    GM_SITE(vm, 281, 4086492);
    /* @4086500 store */
    v40 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v40);
    /* @4086508 load */
    /* @4086516 constant */
    /* @4086520 cmp */
    /* @4086524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4086940;
    /* @4086528 constant */
    /* @4086532 load */
    /* @4086540 cast */
    /* @4086544 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4086552 constant */
    /* @4086556 cast */
    /* @4086560 load */
    /* @4086568 load */
    /* @4086576 load */
    /* @4086584 load */
    /* @4086592 call */
    GM_SITE(vm, 281, 4086592);
    /* @4086600 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4086604 load */
    /* @4086612 cast */
    /* @4086616 dup */
    /* @4086620 load */
    /* @4086628 load */
    /* @4086636 sub */
    /* @4086640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "bowdamage")));
    /* @4086648 constant */
    /* @4086652 cast */
    /* @4086656 load */
    /* @4086664 load */
    /* @4086672 call */
    GM_SITE(vm, 281, 4086672);
    /* @4086680 store */
    v41 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v41);
    /* @4086688 load */
    /* @4086696 load */
    /* @4086704 cast */
    /* @4086708 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4086716 constant */
    /* @4086720 constant */
    /* @4086724 constant */
    /* @4086728 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4086736 constant */
    /* @4086740 load */
    /* @4086748 cast */
    /* @4086752 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4086760 constant */
    /* @4086764 load */
    /* @4086772 cast */
    /* @4086776 constant */
    /* @4086780 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4086788 load */
    /* @4086796 constant */
    /* @4086800 add */
    /* @4086804 store */
    v42 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v42);
    /* @4086812 load */
    /* @4086820 constant */
    /* @4086824 cmp */
    /* @4086828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4086836;
    /* @4086832 b */
    goto L_4086892;
    L_4086836: ;
    /* @4086836 load */
    /* @4086844 constant */
    /* @4086848 cmp */
    /* @4086852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4086892;
    /* @4086856 constant */
    /* @4086860 cast */
    /* @4086864 constant */
    /* @4086868 cast */
    /* @4086872 constant */
    /* @4086876 cast */
    /* @4086880 call */
    GM_SITE(vm, 281, 4086880);
    /* @4086888 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4086892: ;
    /* @4086892 load */
    /* @4086900 constant */
    /* @4086904 cmp */
    /* @4086908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4086940;
    /* @4086912 constant */
    /* @4086916 load */
    /* @4086924 cast */
    /* @4086928 constant */
    /* @4086932 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4086940: ;
    /* @4086940 constant */
    /* @4086944 cast */
    /* @4086948 load */
    /* @4086956 load */
    /* @4086964 call */
    GM_SITE(vm, 281, 4086964);
    /* @4086972 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v43);
    /* @4086980 load */
    /* @4086988 constant */
    /* @4086992 cmp */
    /* @4086996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4087412;
    /* @4087000 constant */
    /* @4087004 load */
    /* @4087012 cast */
    /* @4087016 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4087024 constant */
    /* @4087028 cast */
    /* @4087032 load */
    /* @4087040 load */
    /* @4087048 load */
    /* @4087056 load */
    /* @4087064 call */
    GM_SITE(vm, 281, 4087064);
    /* @4087072 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4087076 load */
    /* @4087084 cast */
    /* @4087088 dup */
    /* @4087092 load */
    /* @4087100 load */
    /* @4087108 sub */
    /* @4087112 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "bowdamage")));
    /* @4087120 constant */
    /* @4087124 cast */
    /* @4087128 load */
    /* @4087136 load */
    /* @4087144 call */
    GM_SITE(vm, 281, 4087144);
    /* @4087152 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4087160 load */
    /* @4087168 load */
    /* @4087176 cast */
    /* @4087180 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4087188 constant */
    /* @4087192 constant */
    /* @4087196 constant */
    /* @4087200 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4087208 constant */
    /* @4087212 load */
    /* @4087220 cast */
    /* @4087224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4087232 constant */
    /* @4087236 load */
    /* @4087244 cast */
    /* @4087248 constant */
    /* @4087252 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4087260 load */
    /* @4087268 constant */
    /* @4087272 add */
    /* @4087276 store */
    v45 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v45);
    /* @4087284 load */
    /* @4087292 constant */
    /* @4087296 cmp */
    /* @4087300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4087308;
    /* @4087304 b */
    goto L_4087364;
    L_4087308: ;
    /* @4087308 load */
    /* @4087316 constant */
    /* @4087320 cmp */
    /* @4087324 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4087364;
    /* @4087328 constant */
    /* @4087332 cast */
    /* @4087336 constant */
    /* @4087340 cast */
    /* @4087344 constant */
    /* @4087348 cast */
    /* @4087352 call */
    GM_SITE(vm, 281, 4087352);
    /* @4087360 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4087364: ;
    /* @4087364 load */
    /* @4087372 constant */
    /* @4087376 cmp */
    /* @4087380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4087412;
    /* @4087384 constant */
    /* @4087388 load */
    /* @4087396 cast */
    /* @4087400 constant */
    /* @4087404 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4087412: ;
    /* @4087412 constant */
    /* @4087416 cast */
    /* @4087420 load */
    /* @4087428 load */
    /* @4087436 call */
    GM_SITE(vm, 281, 4087436);
    /* @4087444 store */
    v46 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v46);
    /* @4087452 load */
    /* @4087460 constant */
    /* @4087464 cmp */
    /* @4087468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4087912;
    /* @4087472 constant */
    /* @4087476 load */
    /* @4087484 cast */
    /* @4087488 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4087496 constant */
    /* @4087500 cast */
    /* @4087504 load */
    /* @4087512 load */
    /* @4087520 load */
    /* @4087528 load */
    /* @4087536 call */
    GM_SITE(vm, 281, 4087536);
    /* @4087544 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4087548 load */
    /* @4087556 cast */
    /* @4087560 dup */
    /* @4087564 load */
    /* @4087572 load */
    /* @4087580 sub */
    /* @4087584 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "bowdamage")));
    /* @4087592 constant */
    /* @4087596 cast */
    /* @4087600 load */
    /* @4087608 load */
    /* @4087616 call */
    GM_SITE(vm, 281, 4087616);
    /* @4087624 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v47);
    /* @4087632 load */
    /* @4087640 load */
    /* @4087648 cast */
    /* @4087652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4087660 constant */
    /* @4087664 constant */
    /* @4087668 constant */
    /* @4087672 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4087680 constant */
    /* @4087684 load */
    /* @4087692 cast */
    /* @4087696 constant */
    /* @4087700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4087708 constant */
    /* @4087712 load */
    /* @4087720 cast */
    /* @4087724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4087732 constant */
    /* @4087736 load */
    /* @4087744 cast */
    /* @4087748 constant */
    /* @4087752 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4087760 load */
    /* @4087768 constant */
    /* @4087772 add */
    /* @4087776 store */
    v48 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v48);
    /* @4087784 load */
    /* @4087792 constant */
    /* @4087796 cmp */
    /* @4087800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4087808;
    /* @4087804 b */
    goto L_4087864;
    L_4087808: ;
    /* @4087808 load */
    /* @4087816 constant */
    /* @4087820 cmp */
    /* @4087824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4087864;
    /* @4087828 constant */
    /* @4087832 cast */
    /* @4087836 constant */
    /* @4087840 cast */
    /* @4087844 constant */
    /* @4087848 cast */
    /* @4087852 call */
    GM_SITE(vm, 281, 4087852);
    /* @4087860 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4087864: ;
    /* @4087864 load */
    /* @4087872 constant */
    /* @4087876 cmp */
    /* @4087880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4087912;
    /* @4087884 constant */
    /* @4087888 load */
    /* @4087896 cast */
    /* @4087900 constant */
    /* @4087904 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4087912: ;
    /* @4087912 constant */
    /* @4087916 cast */
    /* @4087920 load */
    /* @4087928 load */
    /* @4087936 call */
    GM_SITE(vm, 281, 4087936);
    /* @4087944 store */
    v49 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v49);
    /* @4087952 load */
    /* @4087960 constant */
    /* @4087964 cmp */
    /* @4087968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4088332;
    /* @4087972 constant */
    /* @4087976 load */
    /* @4087984 cast */
    /* @4087988 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4087996 constant */
    /* @4088000 cast */
    /* @4088004 load */
    /* @4088012 load */
    /* @4088020 load */
    /* @4088028 load */
    /* @4088036 call */
    GM_SITE(vm, 281, 4088036);
    /* @4088044 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4088048 load */
    /* @4088056 cast */
    /* @4088060 dup */
    /* @4088064 load */
    /* @4088072 load */
    /* @4088080 sub */
    /* @4088084 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "bowdamage")));
    /* @4088092 constant */
    /* @4088096 cast */
    /* @4088100 load */
    /* @4088108 load */
    /* @4088116 call */
    GM_SITE(vm, 281, 4088116);
    /* @4088124 store */
    v50 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v50);
    /* @4088132 load */
    /* @4088140 load */
    /* @4088148 cast */
    /* @4088152 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4088160 constant */
    /* @4088164 constant */
    /* @4088168 constant */
    /* @4088172 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4088180 load */
    /* @4088188 constant */
    /* @4088192 add */
    /* @4088196 store */
    v51 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v51);
    /* @4088204 load */
    /* @4088212 constant */
    /* @4088216 cmp */
    /* @4088220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4088228;
    /* @4088224 b */
    goto L_4088284;
    L_4088228: ;
    /* @4088228 load */
    /* @4088236 constant */
    /* @4088240 cmp */
    /* @4088244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4088284;
    /* @4088248 constant */
    /* @4088252 cast */
    /* @4088256 constant */
    /* @4088260 cast */
    /* @4088264 constant */
    /* @4088268 cast */
    /* @4088272 call */
    GM_SITE(vm, 281, 4088272);
    /* @4088280 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4088284: ;
    /* @4088284 load */
    /* @4088292 constant */
    /* @4088296 cmp */
    /* @4088300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4088332;
    /* @4088304 constant */
    /* @4088308 load */
    /* @4088316 cast */
    /* @4088320 constant */
    /* @4088324 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4088332: ;
    /* @4088332 constant */
    /* @4088336 cast */
    /* @4088340 load */
    /* @4088348 load */
    /* @4088356 call */
    GM_SITE(vm, 281, 4088356);
    /* @4088364 store */
    v52 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v52);
    /* @4088372 load */
    /* @4088380 constant */
    /* @4088384 cmp */
    /* @4088388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4088704;
    /* @4088392 constant */
    /* @4088396 load */
    /* @4088404 cast */
    /* @4088408 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4088416 constant */
    /* @4088420 cast */
    /* @4088424 load */
    /* @4088432 load */
    /* @4088440 load */
    /* @4088448 load */
    /* @4088456 call */
    GM_SITE(vm, 281, 4088456);
    /* @4088464 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4088468 load */
    /* @4088476 cast */
    /* @4088480 dup */
    /* @4088484 load */
    /* @4088492 load */
    /* @4088500 sub */
    /* @4088504 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "bowdamage")));
    /* @4088512 constant */
    /* @4088516 cast */
    /* @4088520 load */
    /* @4088528 load */
    /* @4088536 call */
    GM_SITE(vm, 281, 4088536);
    /* @4088544 store */
    v53 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v53);
    /* @4088552 load */
    /* @4088560 load */
    /* @4088568 cast */
    /* @4088572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4088580 constant */
    /* @4088584 constant */
    /* @4088588 constant */
    /* @4088592 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4088600 load */
    /* @4088608 constant */
    /* @4088612 add */
    /* @4088616 store */
    v54 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v54);
    /* @4088624 load */
    /* @4088632 constant */
    /* @4088636 cmp */
    /* @4088640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4088648;
    /* @4088644 b */
    goto L_4088704;
    L_4088648: ;
    /* @4088648 load */
    /* @4088656 constant */
    /* @4088660 cmp */
    /* @4088664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4088704;
    /* @4088668 constant */
    /* @4088672 cast */
    /* @4088676 constant */
    /* @4088680 cast */
    /* @4088684 constant */
    /* @4088688 cast */
    /* @4088692 call */
    GM_SITE(vm, 281, 4088692);
    /* @4088700 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4088704: ;
    /* @4088704 constant */
    /* @4088708 cast */
    /* @4088712 load */
    /* @4088720 load */
    /* @4088728 call */
    GM_SITE(vm, 281, 4088728);
    /* @4088736 store */
    v55 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v55);
    /* @4088744 load */
    /* @4088752 constant */
    /* @4088756 cmp */
    /* @4088760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4089076;
    /* @4088764 constant */
    /* @4088768 load */
    /* @4088776 cast */
    /* @4088780 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4088788 constant */
    /* @4088792 cast */
    /* @4088796 load */
    /* @4088804 load */
    /* @4088812 load */
    /* @4088820 load */
    /* @4088828 call */
    GM_SITE(vm, 281, 4088828);
    /* @4088836 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4088840 load */
    /* @4088848 cast */
    /* @4088852 dup */
    /* @4088856 load */
    /* @4088864 load */
    /* @4088872 sub */
    /* @4088876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "bowdamage")));
    /* @4088884 constant */
    /* @4088888 cast */
    /* @4088892 load */
    /* @4088900 load */
    /* @4088908 call */
    GM_SITE(vm, 281, 4088908);
    /* @4088916 store */
    v56 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v56);
    /* @4088924 load */
    /* @4088932 load */
    /* @4088940 cast */
    /* @4088944 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4088952 constant */
    /* @4088956 constant */
    /* @4088960 constant */
    /* @4088964 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4088972 load */
    /* @4088980 constant */
    /* @4088984 add */
    /* @4088988 store */
    v57 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v57);
    /* @4088996 load */
    /* @4089004 constant */
    /* @4089008 cmp */
    /* @4089012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4089020;
    /* @4089016 b */
    goto L_4089076;
    L_4089020: ;
    /* @4089020 load */
    /* @4089028 constant */
    /* @4089032 cmp */
    /* @4089036 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4089076;
    /* @4089040 constant */
    /* @4089044 cast */
    /* @4089048 constant */
    /* @4089052 cast */
    /* @4089056 constant */
    /* @4089060 cast */
    /* @4089064 call */
    GM_SITE(vm, 281, 4089064);
    /* @4089072 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4089076: ;
    /* @4089076 constant */
    /* @4089080 cast */
    /* @4089084 load */
    /* @4089092 load */
    /* @4089100 call */
    GM_SITE(vm, 281, 4089100);
    /* @4089108 store */
    v58 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v58);
    /* @4089116 load */
    /* @4089124 constant */
    /* @4089128 cmp */
    /* @4089132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4089448;
    /* @4089136 constant */
    /* @4089140 load */
    /* @4089148 cast */
    /* @4089152 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4089160 constant */
    /* @4089164 cast */
    /* @4089168 load */
    /* @4089176 load */
    /* @4089184 load */
    /* @4089192 load */
    /* @4089200 call */
    GM_SITE(vm, 281, 4089200);
    /* @4089208 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4089212 load */
    /* @4089220 cast */
    /* @4089224 dup */
    /* @4089228 load */
    /* @4089236 load */
    /* @4089244 sub */
    /* @4089248 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "bowdamage")));
    /* @4089256 constant */
    /* @4089260 cast */
    /* @4089264 load */
    /* @4089272 load */
    /* @4089280 call */
    GM_SITE(vm, 281, 4089280);
    /* @4089288 store */
    v59 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v59);
    /* @4089296 load */
    /* @4089304 load */
    /* @4089312 cast */
    /* @4089316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4089324 constant */
    /* @4089328 constant */
    /* @4089332 constant */
    /* @4089336 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4089344 load */
    /* @4089352 constant */
    /* @4089356 add */
    /* @4089360 store */
    v60 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v60);
    /* @4089368 load */
    /* @4089376 constant */
    /* @4089380 cmp */
    /* @4089384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4089392;
    /* @4089388 b */
    goto L_4089448;
    L_4089392: ;
    /* @4089392 load */
    /* @4089400 constant */
    /* @4089404 cmp */
    /* @4089408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4089448;
    /* @4089412 constant */
    /* @4089416 cast */
    /* @4089420 constant */
    /* @4089424 cast */
    /* @4089428 constant */
    /* @4089432 cast */
    /* @4089436 call */
    GM_SITE(vm, 281, 4089436);
    /* @4089444 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4089448: ;
    /* @4089448 constant */
    /* @4089452 cast */
    /* @4089456 load */
    /* @4089464 load */
    /* @4089472 call */
    GM_SITE(vm, 281, 4089472);
    /* @4089480 store */
    v61 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v61);
    /* @4089488 load */
    /* @4089496 constant */
    /* @4089500 cmp */
    /* @4089504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4089820;
    /* @4089508 constant */
    /* @4089512 load */
    /* @4089520 cast */
    /* @4089524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4089532 constant */
    /* @4089536 cast */
    /* @4089540 load */
    /* @4089548 load */
    /* @4089556 load */
    /* @4089564 load */
    /* @4089572 call */
    GM_SITE(vm, 281, 4089572);
    /* @4089580 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4089584 load */
    /* @4089592 cast */
    /* @4089596 dup */
    /* @4089600 load */
    /* @4089608 load */
    /* @4089616 sub */
    /* @4089620 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "bowdamage")));
    /* @4089628 constant */
    /* @4089632 cast */
    /* @4089636 load */
    /* @4089644 load */
    /* @4089652 call */
    GM_SITE(vm, 281, 4089652);
    /* @4089660 store */
    v62 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v62);
    /* @4089668 load */
    /* @4089676 load */
    /* @4089684 cast */
    /* @4089688 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bowdamage"));
    /* @4089696 constant */
    /* @4089700 constant */
    /* @4089704 constant */
    /* @4089708 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4089716 load */
    /* @4089724 constant */
    /* @4089728 add */
    /* @4089732 store */
    v63 = GM_ADD(GM_READ(vm, -5, "bowxp"), VAL(1));
    GM_WRITE(vm, -5, "bowxp", v63);
    /* @4089740 load */
    /* @4089748 constant */
    /* @4089752 cmp */
    /* @4089756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4089764;
    /* @4089760 b */
    goto L_4089820;
    L_4089764: ;
    /* @4089764 load */
    /* @4089772 constant */
    /* @4089776 cmp */
    /* @4089780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4089820;
    /* @4089784 constant */
    /* @4089788 cast */
    /* @4089792 constant */
    /* @4089796 cast */
    /* @4089800 constant */
    /* @4089804 cast */
    /* @4089808 call */
    GM_SITE(vm, 281, 4089808);
    /* @4089816 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4089820: ;
    return;
}
