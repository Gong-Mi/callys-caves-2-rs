/* generated from CODE 303 (gml_Object_obj_rocket_Step_0), source start 4148180, end 4156548. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0303(GmVM* vm) {
    Val v1;
    Val v2;
    Val p4148276_0;
    Val v3;
    Val p4148408_0;
    Val v4;
    Val p4148544_0;
    Val v5;
    Val v6;
    Val v7;
    Val p4148976_0;
    Val v8;
    Val v9;
    Val v10;
    Val p4149408_0;
    Val v11;
    Val v12;
    Val v13;
    Val p4149840_0;
    Val v14;
    Val v15;
    Val v16;
    Val p4150272_0;
    Val v17;
    Val v18;
    Val v19;
    Val p4150652_0;
    Val v20;
    Val v21;
    Val v22;
    Val p4151084_0;
    Val v23;
    Val v24;
    Val v25;
    Val p4151516_0;
    Val v26;
    Val v27;
    Val v28;
    Val p4151948_0;
    Val v29;
    Val v30;
    Val v31;
    Val p4152380_0;
    Val v32;
    Val v33;
    Val v34;
    Val p4152812_0;
    Val v35;
    Val v36;
    Val v37;
    Val p4153244_0;
    Val v38;
    Val v39;
    Val v40;
    Val p4153676_0;
    Val v41;
    Val v42;
    Val v43;
    Val p4154108_0;
    Val v44;
    Val v45;
    Val v46;
    Val p4154540_0;
    Val v47;
    Val v48;
    Val v49;
    Val p4154972_0;
    Val v50;
    Val v51;
    Val v52;
    Val p4155304_0;
    Val v53;
    Val v54;
    Val v55;
    Val p4155636_0;
    Val v56;
    Val v57;
    Val v58;
    Val p4155968_0;
    Val v59;
    Val v60;
    Val v61;
    Val p4156300_0;
    Val v62;
    Val v63;
    /* @4148180 constant */
    /* @4148184 cast */
    /* @4148188 load */
    /* @4148196 load */
    /* @4148204 load */
    /* @4148212 add */
    /* @4148216 call */
    GM_SITE(vm, 303, 4148216);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4148224 store */
    v2 = GM_CALL(vm, "instance_place", 3, v1, GM_READ(vm, -1, "y"), VAL(156));
    GM_WRITE(vm, -1, "hitblock", v2);
    /* @4148232 load */
    /* @4148240 constant */
    /* @4148244 cmp */
    /* @4148248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitblock") != VAL(-4)))) goto L_4148272;
    /* @4148252 load */
    /* @4148260 constant */
    /* @4148264 cmp */
    /* @4148268 b */
    p4148276_0 = NUMBOOL(GM_READ(vm, -1, "hitboulder") == VAL(0));
    goto L_4148276;
    L_4148272: ;
    /* @4148272 constant */
    p4148276_0 = VAL(0);
    L_4148276: ;
    /* @4148276 bf */
    if (!TRUTH(p4148276_0)) goto L_4148344;
    /* @4148280 load */
    /* @4148288 cast */
    /* @4148292 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitblock")))) goto L_4148308;
    L_4148296: ;
    /* @4148296 call */
    GM_SITE(vm, 303, 4148296);
    /* @4148304 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4148308: ;
    /* @4148308 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4148296;
    /* @4148312 constant */
    /* @4148316 constant */
    /* @4148320 constant */
    /* @4148324 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4148332 constant */
    /* @4148336 store */
    GM_WRITE(vm, -1, "hitboulder", VAL(1));
    L_4148344: ;
    /* @4148344 constant */
    /* @4148348 cast */
    /* @4148352 load */
    /* @4148360 load */
    /* @4148368 call */
    GM_SITE(vm, 303, 4148368);
    /* @4148376 cast */
    /* @4148380 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v3)) goto L_4148404;
    /* @4148384 load */
    /* @4148392 constant */
    /* @4148396 cmp */
    /* @4148400 b */
    p4148408_0 = NUMBOOL(GM_READ(vm, -1, "hitwall") == VAL(0));
    goto L_4148408;
    L_4148404: ;
    /* @4148404 constant */
    p4148408_0 = VAL(0);
    L_4148408: ;
    /* @4148408 bf */
    if (!TRUTH(p4148408_0)) goto L_4148444;
    /* @4148412 constant */
    /* @4148416 constant */
    /* @4148420 constant */
    /* @4148424 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4148432 constant */
    /* @4148436 store */
    GM_WRITE(vm, -1, "hitwall", VAL(1));
    L_4148444: ;
    /* @4148444 load */
    /* @4148452 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4148460 constant */
    /* @4148464 cast */
    /* @4148468 load */
    /* @4148476 load */
    /* @4148484 call */
    GM_SITE(vm, 303, 4148484);
    /* @4148492 store */
    v4 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v4);
    /* @4148500 load */
    /* @4148508 constant */
    /* @4148512 cmp */
    /* @4148516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4148540;
    /* @4148520 load */
    /* @4148528 constant */
    /* @4148532 cmp */
    /* @4148536 b */
    p4148544_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4148544;
    L_4148540: ;
    /* @4148540 constant */
    p4148544_0 = VAL(0);
    L_4148544: ;
    /* @4148544 bf */
    if (!TRUTH(p4148544_0)) goto L_4148892;
    /* @4148548 constant */
    /* @4148552 load */
    /* @4148560 cast */
    /* @4148564 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4148572 constant */
    /* @4148576 cast */
    /* @4148580 load */
    /* @4148588 load */
    /* @4148596 load */
    /* @4148604 load */
    /* @4148612 call */
    GM_SITE(vm, 303, 4148612);
    /* @4148620 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4148624 load */
    /* @4148632 cast */
    /* @4148636 dup */
    /* @4148640 load */
    /* @4148648 load */
    /* @4148656 sub */
    /* @4148660 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "rocketdamage")));
    /* @4148668 constant */
    /* @4148672 cast */
    /* @4148676 load */
    /* @4148684 load */
    /* @4148692 call */
    GM_SITE(vm, 303, 4148692);
    /* @4148700 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v5);
    /* @4148708 load */
    /* @4148716 load */
    /* @4148724 cast */
    /* @4148728 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4148736 constant */
    /* @4148740 constant */
    /* @4148744 constant */
    /* @4148748 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4148756 constant */
    /* @4148760 load */
    /* @4148768 cast */
    /* @4148772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4148780 constant */
    /* @4148784 load */
    /* @4148792 cast */
    /* @4148796 constant */
    /* @4148800 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4148808 load */
    /* @4148816 constant */
    /* @4148820 add */
    /* @4148824 store */
    v6 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v6);
    /* @4148832 load */
    /* @4148840 constant */
    /* @4148844 cmp */
    /* @4148848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4148880;
    /* @4148852 constant */
    /* @4148856 load */
    /* @4148864 cast */
    /* @4148868 constant */
    /* @4148872 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4148880: ;
    /* @4148880 constant */
    /* @4148884 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4148892: ;
    /* @4148892 constant */
    /* @4148896 cast */
    /* @4148900 load */
    /* @4148908 load */
    /* @4148916 call */
    GM_SITE(vm, 303, 4148916);
    /* @4148924 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v7);
    /* @4148932 load */
    /* @4148940 constant */
    /* @4148944 cmp */
    /* @4148948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4148972;
    /* @4148952 load */
    /* @4148960 constant */
    /* @4148964 cmp */
    /* @4148968 b */
    p4148976_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4148976;
    L_4148972: ;
    /* @4148972 constant */
    p4148976_0 = VAL(0);
    L_4148976: ;
    /* @4148976 bf */
    if (!TRUTH(p4148976_0)) goto L_4149324;
    /* @4148980 constant */
    /* @4148984 load */
    /* @4148992 cast */
    /* @4148996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4149004 constant */
    /* @4149008 cast */
    /* @4149012 load */
    /* @4149020 load */
    /* @4149028 load */
    /* @4149036 load */
    /* @4149044 call */
    GM_SITE(vm, 303, 4149044);
    /* @4149052 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4149056 load */
    /* @4149064 cast */
    /* @4149068 dup */
    /* @4149072 load */
    /* @4149080 load */
    /* @4149088 sub */
    /* @4149092 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "rocketdamage")));
    /* @4149100 constant */
    /* @4149104 cast */
    /* @4149108 load */
    /* @4149116 load */
    /* @4149124 call */
    GM_SITE(vm, 303, 4149124);
    /* @4149132 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4149140 load */
    /* @4149148 load */
    /* @4149156 cast */
    /* @4149160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4149168 constant */
    /* @4149172 constant */
    /* @4149176 constant */
    /* @4149180 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4149188 constant */
    /* @4149192 load */
    /* @4149200 cast */
    /* @4149204 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4149212 constant */
    /* @4149216 load */
    /* @4149224 cast */
    /* @4149228 constant */
    /* @4149232 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4149240 load */
    /* @4149248 constant */
    /* @4149252 add */
    /* @4149256 store */
    v9 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v9);
    /* @4149264 constant */
    /* @4149268 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4149276 load */
    /* @4149284 constant */
    /* @4149288 cmp */
    /* @4149292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4149324;
    /* @4149296 constant */
    /* @4149300 load */
    /* @4149308 cast */
    /* @4149312 constant */
    /* @4149316 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4149324: ;
    /* @4149324 constant */
    /* @4149328 cast */
    /* @4149332 load */
    /* @4149340 load */
    /* @4149348 call */
    GM_SITE(vm, 303, 4149348);
    /* @4149356 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v10);
    /* @4149364 load */
    /* @4149372 constant */
    /* @4149376 cmp */
    /* @4149380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4149404;
    /* @4149384 load */
    /* @4149392 constant */
    /* @4149396 cmp */
    /* @4149400 b */
    p4149408_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4149408;
    L_4149404: ;
    /* @4149404 constant */
    p4149408_0 = VAL(0);
    L_4149408: ;
    /* @4149408 bf */
    if (!TRUTH(p4149408_0)) goto L_4149756;
    /* @4149412 constant */
    /* @4149416 load */
    /* @4149424 cast */
    /* @4149428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4149436 constant */
    /* @4149440 cast */
    /* @4149444 load */
    /* @4149452 load */
    /* @4149460 load */
    /* @4149468 load */
    /* @4149476 call */
    GM_SITE(vm, 303, 4149476);
    /* @4149484 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4149488 load */
    /* @4149496 cast */
    /* @4149500 dup */
    /* @4149504 load */
    /* @4149512 load */
    /* @4149520 sub */
    /* @4149524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "rocketdamage")));
    /* @4149532 constant */
    /* @4149536 cast */
    /* @4149540 load */
    /* @4149548 load */
    /* @4149556 call */
    GM_SITE(vm, 303, 4149556);
    /* @4149564 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4149572 load */
    /* @4149580 load */
    /* @4149588 cast */
    /* @4149592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4149600 constant */
    /* @4149604 constant */
    /* @4149608 constant */
    /* @4149612 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4149620 constant */
    /* @4149624 load */
    /* @4149632 cast */
    /* @4149636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4149644 constant */
    /* @4149648 load */
    /* @4149656 cast */
    /* @4149660 constant */
    /* @4149664 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4149672 load */
    /* @4149680 constant */
    /* @4149684 add */
    /* @4149688 store */
    v12 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v12);
    /* @4149696 constant */
    /* @4149700 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4149708 load */
    /* @4149716 constant */
    /* @4149720 cmp */
    /* @4149724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4149756;
    /* @4149728 constant */
    /* @4149732 load */
    /* @4149740 cast */
    /* @4149744 constant */
    /* @4149748 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4149756: ;
    /* @4149756 constant */
    /* @4149760 cast */
    /* @4149764 load */
    /* @4149772 load */
    /* @4149780 call */
    GM_SITE(vm, 303, 4149780);
    /* @4149788 store */
    v13 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v13);
    /* @4149796 load */
    /* @4149804 constant */
    /* @4149808 cmp */
    /* @4149812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4149836;
    /* @4149816 load */
    /* @4149824 constant */
    /* @4149828 cmp */
    /* @4149832 b */
    p4149840_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4149840;
    L_4149836: ;
    /* @4149836 constant */
    p4149840_0 = VAL(0);
    L_4149840: ;
    /* @4149840 bf */
    if (!TRUTH(p4149840_0)) goto L_4150188;
    /* @4149844 constant */
    /* @4149848 load */
    /* @4149856 cast */
    /* @4149860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4149868 constant */
    /* @4149872 cast */
    /* @4149876 load */
    /* @4149884 load */
    /* @4149892 load */
    /* @4149900 load */
    /* @4149908 call */
    GM_SITE(vm, 303, 4149908);
    /* @4149916 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4149920 load */
    /* @4149928 cast */
    /* @4149932 dup */
    /* @4149936 load */
    /* @4149944 load */
    /* @4149952 sub */
    /* @4149956 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "rocketdamage")));
    /* @4149964 constant */
    /* @4149968 cast */
    /* @4149972 load */
    /* @4149980 load */
    /* @4149988 call */
    GM_SITE(vm, 303, 4149988);
    /* @4149996 store */
    v14 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v14);
    /* @4150004 load */
    /* @4150012 load */
    /* @4150020 cast */
    /* @4150024 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4150032 constant */
    /* @4150036 constant */
    /* @4150040 constant */
    /* @4150044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4150052 constant */
    /* @4150056 load */
    /* @4150064 cast */
    /* @4150068 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4150076 constant */
    /* @4150080 load */
    /* @4150088 cast */
    /* @4150092 constant */
    /* @4150096 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4150104 load */
    /* @4150112 constant */
    /* @4150116 add */
    /* @4150120 store */
    v15 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v15);
    /* @4150128 constant */
    /* @4150132 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4150140 load */
    /* @4150148 constant */
    /* @4150152 cmp */
    /* @4150156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4150188;
    /* @4150160 constant */
    /* @4150164 load */
    /* @4150172 cast */
    /* @4150176 constant */
    /* @4150180 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4150188: ;
    /* @4150188 constant */
    /* @4150192 cast */
    /* @4150196 load */
    /* @4150204 load */
    /* @4150212 call */
    GM_SITE(vm, 303, 4150212);
    /* @4150220 store */
    v16 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v16);
    /* @4150228 load */
    /* @4150236 constant */
    /* @4150240 cmp */
    /* @4150244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4150268;
    /* @4150248 load */
    /* @4150256 constant */
    /* @4150260 cmp */
    /* @4150264 b */
    p4150272_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4150272;
    L_4150268: ;
    /* @4150268 constant */
    p4150272_0 = VAL(0);
    L_4150272: ;
    /* @4150272 bf */
    if (!TRUTH(p4150272_0)) goto L_4150568;
    /* @4150276 constant */
    /* @4150280 load */
    /* @4150288 cast */
    /* @4150292 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4150300 constant */
    /* @4150304 cast */
    /* @4150308 load */
    /* @4150316 load */
    /* @4150324 load */
    /* @4150332 load */
    /* @4150340 call */
    GM_SITE(vm, 303, 4150340);
    /* @4150348 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4150352 load */
    /* @4150360 cast */
    /* @4150364 dup */
    /* @4150368 load */
    /* @4150376 load */
    /* @4150384 sub */
    /* @4150388 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "rocketdamage")));
    /* @4150396 constant */
    /* @4150400 cast */
    /* @4150404 load */
    /* @4150412 load */
    /* @4150420 call */
    GM_SITE(vm, 303, 4150420);
    /* @4150428 store */
    v17 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v17);
    /* @4150436 load */
    /* @4150444 load */
    /* @4150452 cast */
    /* @4150456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4150464 constant */
    /* @4150468 constant */
    /* @4150472 constant */
    /* @4150476 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4150484 load */
    /* @4150492 constant */
    /* @4150496 add */
    /* @4150500 store */
    v18 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v18);
    /* @4150508 constant */
    /* @4150512 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4150520 load */
    /* @4150528 constant */
    /* @4150532 cmp */
    /* @4150536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4150568;
    /* @4150540 constant */
    /* @4150544 load */
    /* @4150552 cast */
    /* @4150556 constant */
    /* @4150560 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4150568: ;
    /* @4150568 constant */
    /* @4150572 cast */
    /* @4150576 load */
    /* @4150584 load */
    /* @4150592 call */
    GM_SITE(vm, 303, 4150592);
    /* @4150600 store */
    v19 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v19);
    /* @4150608 load */
    /* @4150616 constant */
    /* @4150620 cmp */
    /* @4150624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4150648;
    /* @4150628 load */
    /* @4150636 constant */
    /* @4150640 cmp */
    /* @4150644 b */
    p4150652_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4150652;
    L_4150648: ;
    /* @4150648 constant */
    p4150652_0 = VAL(0);
    L_4150652: ;
    /* @4150652 bf */
    if (!TRUTH(p4150652_0)) goto L_4151000;
    /* @4150656 constant */
    /* @4150660 load */
    /* @4150668 cast */
    /* @4150672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4150680 constant */
    /* @4150684 cast */
    /* @4150688 load */
    /* @4150696 load */
    /* @4150704 load */
    /* @4150712 load */
    /* @4150720 call */
    GM_SITE(vm, 303, 4150720);
    /* @4150728 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4150732 load */
    /* @4150740 cast */
    /* @4150744 dup */
    /* @4150748 load */
    /* @4150756 load */
    /* @4150764 sub */
    /* @4150768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "rocketdamage")));
    /* @4150776 constant */
    /* @4150780 cast */
    /* @4150784 load */
    /* @4150792 load */
    /* @4150800 call */
    GM_SITE(vm, 303, 4150800);
    /* @4150808 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4150816 load */
    /* @4150824 load */
    /* @4150832 cast */
    /* @4150836 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4150844 constant */
    /* @4150848 constant */
    /* @4150852 constant */
    /* @4150856 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4150864 constant */
    /* @4150868 load */
    /* @4150876 cast */
    /* @4150880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4150888 constant */
    /* @4150892 load */
    /* @4150900 cast */
    /* @4150904 constant */
    /* @4150908 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4150916 load */
    /* @4150924 constant */
    /* @4150928 add */
    /* @4150932 store */
    v21 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v21);
    /* @4150940 constant */
    /* @4150944 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4150952 load */
    /* @4150960 constant */
    /* @4150964 cmp */
    /* @4150968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4151000;
    /* @4150972 constant */
    /* @4150976 load */
    /* @4150984 cast */
    /* @4150988 constant */
    /* @4150992 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4151000: ;
    /* @4151000 constant */
    /* @4151004 cast */
    /* @4151008 load */
    /* @4151016 load */
    /* @4151024 call */
    GM_SITE(vm, 303, 4151024);
    /* @4151032 store */
    v22 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v22);
    /* @4151040 load */
    /* @4151048 constant */
    /* @4151052 cmp */
    /* @4151056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4151080;
    /* @4151060 load */
    /* @4151068 constant */
    /* @4151072 cmp */
    /* @4151076 b */
    p4151084_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4151084;
    L_4151080: ;
    /* @4151080 constant */
    p4151084_0 = VAL(0);
    L_4151084: ;
    /* @4151084 bf */
    if (!TRUTH(p4151084_0)) goto L_4151432;
    /* @4151088 constant */
    /* @4151092 load */
    /* @4151100 cast */
    /* @4151104 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4151112 constant */
    /* @4151116 cast */
    /* @4151120 load */
    /* @4151128 load */
    /* @4151136 load */
    /* @4151144 load */
    /* @4151152 call */
    GM_SITE(vm, 303, 4151152);
    /* @4151160 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4151164 load */
    /* @4151172 cast */
    /* @4151176 dup */
    /* @4151180 load */
    /* @4151188 load */
    /* @4151196 sub */
    /* @4151200 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "rocketdamage")));
    /* @4151208 constant */
    /* @4151212 cast */
    /* @4151216 load */
    /* @4151224 load */
    /* @4151232 call */
    GM_SITE(vm, 303, 4151232);
    /* @4151240 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4151248 load */
    /* @4151256 load */
    /* @4151264 cast */
    /* @4151268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4151276 constant */
    /* @4151280 constant */
    /* @4151284 constant */
    /* @4151288 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4151296 constant */
    /* @4151300 load */
    /* @4151308 cast */
    /* @4151312 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4151320 constant */
    /* @4151324 load */
    /* @4151332 cast */
    /* @4151336 constant */
    /* @4151340 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4151348 load */
    /* @4151356 constant */
    /* @4151360 add */
    /* @4151364 store */
    v24 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v24);
    /* @4151372 constant */
    /* @4151376 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4151384 load */
    /* @4151392 constant */
    /* @4151396 cmp */
    /* @4151400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4151432;
    /* @4151404 constant */
    /* @4151408 load */
    /* @4151416 cast */
    /* @4151420 constant */
    /* @4151424 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4151432: ;
    /* @4151432 constant */
    /* @4151436 cast */
    /* @4151440 load */
    /* @4151448 load */
    /* @4151456 call */
    GM_SITE(vm, 303, 4151456);
    /* @4151464 store */
    v25 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v25);
    /* @4151472 load */
    /* @4151480 constant */
    /* @4151484 cmp */
    /* @4151488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4151512;
    /* @4151492 load */
    /* @4151500 constant */
    /* @4151504 cmp */
    /* @4151508 b */
    p4151516_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4151516;
    L_4151512: ;
    /* @4151512 constant */
    p4151516_0 = VAL(0);
    L_4151516: ;
    /* @4151516 bf */
    if (!TRUTH(p4151516_0)) goto L_4151864;
    /* @4151520 constant */
    /* @4151524 load */
    /* @4151532 cast */
    /* @4151536 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4151544 constant */
    /* @4151548 cast */
    /* @4151552 load */
    /* @4151560 load */
    /* @4151568 load */
    /* @4151576 load */
    /* @4151584 call */
    GM_SITE(vm, 303, 4151584);
    /* @4151592 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4151596 load */
    /* @4151604 cast */
    /* @4151608 dup */
    /* @4151612 load */
    /* @4151620 load */
    /* @4151628 sub */
    /* @4151632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "rocketdamage")));
    /* @4151640 constant */
    /* @4151644 cast */
    /* @4151648 load */
    /* @4151656 load */
    /* @4151664 call */
    GM_SITE(vm, 303, 4151664);
    /* @4151672 store */
    v26 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v26);
    /* @4151680 load */
    /* @4151688 load */
    /* @4151696 cast */
    /* @4151700 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4151708 constant */
    /* @4151712 constant */
    /* @4151716 constant */
    /* @4151720 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4151728 constant */
    /* @4151732 load */
    /* @4151740 cast */
    /* @4151744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "stunned", VAL(1));
    /* @4151752 constant */
    /* @4151756 load */
    /* @4151764 cast */
    /* @4151768 constant */
    /* @4151772 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(4), VAL(10));
    /* @4151780 load */
    /* @4151788 constant */
    /* @4151792 add */
    /* @4151796 store */
    v27 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v27);
    /* @4151804 constant */
    /* @4151808 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4151816 load */
    /* @4151824 constant */
    /* @4151828 cmp */
    /* @4151832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4151864;
    /* @4151836 constant */
    /* @4151840 load */
    /* @4151848 cast */
    /* @4151852 constant */
    /* @4151856 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4151864: ;
    /* @4151864 constant */
    /* @4151868 cast */
    /* @4151872 load */
    /* @4151880 load */
    /* @4151888 call */
    GM_SITE(vm, 303, 4151888);
    /* @4151896 store */
    v28 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v28);
    /* @4151904 load */
    /* @4151912 constant */
    /* @4151916 cmp */
    /* @4151920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4151944;
    /* @4151924 load */
    /* @4151932 constant */
    /* @4151936 cmp */
    /* @4151940 b */
    p4151948_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4151948;
    L_4151944: ;
    /* @4151944 constant */
    p4151948_0 = VAL(0);
    L_4151948: ;
    /* @4151948 bf */
    if (!TRUTH(p4151948_0)) goto L_4152296;
    /* @4151952 constant */
    /* @4151956 load */
    /* @4151964 cast */
    /* @4151968 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4151976 constant */
    /* @4151980 cast */
    /* @4151984 load */
    /* @4151992 load */
    /* @4152000 load */
    /* @4152008 load */
    /* @4152016 call */
    GM_SITE(vm, 303, 4152016);
    /* @4152024 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4152028 load */
    /* @4152036 cast */
    /* @4152040 dup */
    /* @4152044 load */
    /* @4152052 load */
    /* @4152060 sub */
    /* @4152064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "rocketdamage")));
    /* @4152072 constant */
    /* @4152076 cast */
    /* @4152080 load */
    /* @4152088 load */
    /* @4152096 call */
    GM_SITE(vm, 303, 4152096);
    /* @4152104 store */
    v29 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v29);
    /* @4152112 load */
    /* @4152120 load */
    /* @4152128 cast */
    /* @4152132 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4152140 constant */
    /* @4152144 constant */
    /* @4152148 constant */
    /* @4152152 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4152160 constant */
    /* @4152164 load */
    /* @4152172 cast */
    /* @4152176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4152184 constant */
    /* @4152188 load */
    /* @4152196 cast */
    /* @4152200 constant */
    /* @4152204 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4152212 load */
    /* @4152220 constant */
    /* @4152224 add */
    /* @4152228 store */
    v30 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v30);
    /* @4152236 constant */
    /* @4152240 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4152248 load */
    /* @4152256 constant */
    /* @4152260 cmp */
    /* @4152264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4152296;
    /* @4152268 constant */
    /* @4152272 load */
    /* @4152280 cast */
    /* @4152284 constant */
    /* @4152288 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4152296: ;
    /* @4152296 constant */
    /* @4152300 cast */
    /* @4152304 load */
    /* @4152312 load */
    /* @4152320 call */
    GM_SITE(vm, 303, 4152320);
    /* @4152328 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v31);
    /* @4152336 load */
    /* @4152344 constant */
    /* @4152348 cmp */
    /* @4152352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4152376;
    /* @4152356 load */
    /* @4152364 constant */
    /* @4152368 cmp */
    /* @4152372 b */
    p4152380_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4152380;
    L_4152376: ;
    /* @4152376 constant */
    p4152380_0 = VAL(0);
    L_4152380: ;
    /* @4152380 bf */
    if (!TRUTH(p4152380_0)) goto L_4152728;
    /* @4152384 constant */
    /* @4152388 load */
    /* @4152396 cast */
    /* @4152400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4152408 constant */
    /* @4152412 cast */
    /* @4152416 load */
    /* @4152424 load */
    /* @4152432 load */
    /* @4152440 load */
    /* @4152448 call */
    GM_SITE(vm, 303, 4152448);
    /* @4152456 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4152460 load */
    /* @4152468 cast */
    /* @4152472 dup */
    /* @4152476 load */
    /* @4152484 load */
    /* @4152492 sub */
    /* @4152496 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "rocketdamage")));
    /* @4152504 constant */
    /* @4152508 cast */
    /* @4152512 load */
    /* @4152520 load */
    /* @4152528 call */
    GM_SITE(vm, 303, 4152528);
    /* @4152536 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4152544 load */
    /* @4152552 load */
    /* @4152560 cast */
    /* @4152564 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4152572 constant */
    /* @4152576 constant */
    /* @4152580 constant */
    /* @4152584 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4152592 constant */
    /* @4152596 load */
    /* @4152604 cast */
    /* @4152608 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4152616 constant */
    /* @4152620 load */
    /* @4152628 cast */
    /* @4152632 constant */
    /* @4152636 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4152644 load */
    /* @4152652 constant */
    /* @4152656 add */
    /* @4152660 store */
    v33 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v33);
    /* @4152668 constant */
    /* @4152672 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4152680 load */
    /* @4152688 constant */
    /* @4152692 cmp */
    /* @4152696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4152728;
    /* @4152700 constant */
    /* @4152704 load */
    /* @4152712 cast */
    /* @4152716 constant */
    /* @4152720 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4152728: ;
    /* @4152728 constant */
    /* @4152732 cast */
    /* @4152736 load */
    /* @4152744 load */
    /* @4152752 call */
    GM_SITE(vm, 303, 4152752);
    /* @4152760 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v34);
    /* @4152768 load */
    /* @4152776 constant */
    /* @4152780 cmp */
    /* @4152784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4152808;
    /* @4152788 load */
    /* @4152796 constant */
    /* @4152800 cmp */
    /* @4152804 b */
    p4152812_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4152812;
    L_4152808: ;
    /* @4152808 constant */
    p4152812_0 = VAL(0);
    L_4152812: ;
    /* @4152812 bf */
    if (!TRUTH(p4152812_0)) goto L_4153160;
    /* @4152816 constant */
    /* @4152820 load */
    /* @4152828 cast */
    /* @4152832 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4152840 constant */
    /* @4152844 cast */
    /* @4152848 load */
    /* @4152856 load */
    /* @4152864 load */
    /* @4152872 load */
    /* @4152880 call */
    GM_SITE(vm, 303, 4152880);
    /* @4152888 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4152892 load */
    /* @4152900 cast */
    /* @4152904 dup */
    /* @4152908 load */
    /* @4152916 load */
    /* @4152924 sub */
    /* @4152928 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "rocketdamage")));
    /* @4152936 constant */
    /* @4152940 cast */
    /* @4152944 load */
    /* @4152952 load */
    /* @4152960 call */
    GM_SITE(vm, 303, 4152960);
    /* @4152968 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v35);
    /* @4152976 load */
    /* @4152984 load */
    /* @4152992 cast */
    /* @4152996 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4153004 constant */
    /* @4153008 constant */
    /* @4153012 constant */
    /* @4153016 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4153024 constant */
    /* @4153028 load */
    /* @4153036 cast */
    /* @4153040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4153048 constant */
    /* @4153052 load */
    /* @4153060 cast */
    /* @4153064 constant */
    /* @4153068 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4153076 load */
    /* @4153084 constant */
    /* @4153088 add */
    /* @4153092 store */
    v36 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v36);
    /* @4153100 constant */
    /* @4153104 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4153112 load */
    /* @4153120 constant */
    /* @4153124 cmp */
    /* @4153128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4153160;
    /* @4153132 constant */
    /* @4153136 load */
    /* @4153144 cast */
    /* @4153148 constant */
    /* @4153152 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4153160: ;
    /* @4153160 constant */
    /* @4153164 cast */
    /* @4153168 load */
    /* @4153176 load */
    /* @4153184 call */
    GM_SITE(vm, 303, 4153184);
    /* @4153192 store */
    v37 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v37);
    /* @4153200 load */
    /* @4153208 constant */
    /* @4153212 cmp */
    /* @4153216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4153240;
    /* @4153220 load */
    /* @4153228 constant */
    /* @4153232 cmp */
    /* @4153236 b */
    p4153244_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4153244;
    L_4153240: ;
    /* @4153240 constant */
    p4153244_0 = VAL(0);
    L_4153244: ;
    /* @4153244 bf */
    if (!TRUTH(p4153244_0)) goto L_4153592;
    /* @4153248 constant */
    /* @4153252 load */
    /* @4153260 cast */
    /* @4153264 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4153272 constant */
    /* @4153276 cast */
    /* @4153280 load */
    /* @4153288 load */
    /* @4153296 load */
    /* @4153304 load */
    /* @4153312 call */
    GM_SITE(vm, 303, 4153312);
    /* @4153320 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4153324 load */
    /* @4153332 cast */
    /* @4153336 dup */
    /* @4153340 load */
    /* @4153348 load */
    /* @4153356 sub */
    /* @4153360 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "rocketdamage")));
    /* @4153368 constant */
    /* @4153372 cast */
    /* @4153376 load */
    /* @4153384 load */
    /* @4153392 call */
    GM_SITE(vm, 303, 4153392);
    /* @4153400 store */
    v38 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v38);
    /* @4153408 load */
    /* @4153416 load */
    /* @4153424 cast */
    /* @4153428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4153436 constant */
    /* @4153440 constant */
    /* @4153444 constant */
    /* @4153448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4153456 constant */
    /* @4153460 load */
    /* @4153468 cast */
    /* @4153472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4153480 constant */
    /* @4153484 load */
    /* @4153492 cast */
    /* @4153496 constant */
    /* @4153500 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4153508 load */
    /* @4153516 constant */
    /* @4153520 add */
    /* @4153524 store */
    v39 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v39);
    /* @4153532 constant */
    /* @4153536 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4153544 load */
    /* @4153552 constant */
    /* @4153556 cmp */
    /* @4153560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4153592;
    /* @4153564 constant */
    /* @4153568 load */
    /* @4153576 cast */
    /* @4153580 constant */
    /* @4153584 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4153592: ;
    /* @4153592 constant */
    /* @4153596 cast */
    /* @4153600 load */
    /* @4153608 load */
    /* @4153616 call */
    GM_SITE(vm, 303, 4153616);
    /* @4153624 store */
    v40 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v40);
    /* @4153632 load */
    /* @4153640 constant */
    /* @4153644 cmp */
    /* @4153648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4153672;
    /* @4153652 load */
    /* @4153660 constant */
    /* @4153664 cmp */
    /* @4153668 b */
    p4153676_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4153676;
    L_4153672: ;
    /* @4153672 constant */
    p4153676_0 = VAL(0);
    L_4153676: ;
    /* @4153676 bf */
    if (!TRUTH(p4153676_0)) goto L_4154024;
    /* @4153680 constant */
    /* @4153684 load */
    /* @4153692 cast */
    /* @4153696 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4153704 constant */
    /* @4153708 cast */
    /* @4153712 load */
    /* @4153720 load */
    /* @4153728 load */
    /* @4153736 load */
    /* @4153744 call */
    GM_SITE(vm, 303, 4153744);
    /* @4153752 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4153756 load */
    /* @4153764 cast */
    /* @4153768 dup */
    /* @4153772 load */
    /* @4153780 load */
    /* @4153788 sub */
    /* @4153792 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "rocketdamage")));
    /* @4153800 constant */
    /* @4153804 cast */
    /* @4153808 load */
    /* @4153816 load */
    /* @4153824 call */
    GM_SITE(vm, 303, 4153824);
    /* @4153832 store */
    v41 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v41);
    /* @4153840 load */
    /* @4153848 load */
    /* @4153856 cast */
    /* @4153860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4153868 constant */
    /* @4153872 constant */
    /* @4153876 constant */
    /* @4153880 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4153888 constant */
    /* @4153892 load */
    /* @4153900 cast */
    /* @4153904 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4153912 constant */
    /* @4153916 load */
    /* @4153924 cast */
    /* @4153928 constant */
    /* @4153932 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4153940 load */
    /* @4153948 constant */
    /* @4153952 add */
    /* @4153956 store */
    v42 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v42);
    /* @4153964 constant */
    /* @4153968 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4153976 load */
    /* @4153984 constant */
    /* @4153988 cmp */
    /* @4153992 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4154024;
    /* @4153996 constant */
    /* @4154000 load */
    /* @4154008 cast */
    /* @4154012 constant */
    /* @4154016 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4154024: ;
    /* @4154024 constant */
    /* @4154028 cast */
    /* @4154032 load */
    /* @4154040 load */
    /* @4154048 call */
    GM_SITE(vm, 303, 4154048);
    /* @4154056 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v43);
    /* @4154064 load */
    /* @4154072 constant */
    /* @4154076 cmp */
    /* @4154080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4154104;
    /* @4154084 load */
    /* @4154092 constant */
    /* @4154096 cmp */
    /* @4154100 b */
    p4154108_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4154108;
    L_4154104: ;
    /* @4154104 constant */
    p4154108_0 = VAL(0);
    L_4154108: ;
    /* @4154108 bf */
    if (!TRUTH(p4154108_0)) goto L_4154456;
    /* @4154112 constant */
    /* @4154116 load */
    /* @4154124 cast */
    /* @4154128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4154136 constant */
    /* @4154140 cast */
    /* @4154144 load */
    /* @4154152 load */
    /* @4154160 load */
    /* @4154168 load */
    /* @4154176 call */
    GM_SITE(vm, 303, 4154176);
    /* @4154184 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4154188 load */
    /* @4154196 cast */
    /* @4154200 dup */
    /* @4154204 load */
    /* @4154212 load */
    /* @4154220 sub */
    /* @4154224 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "rocketdamage")));
    /* @4154232 constant */
    /* @4154236 cast */
    /* @4154240 load */
    /* @4154248 load */
    /* @4154256 call */
    GM_SITE(vm, 303, 4154256);
    /* @4154264 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4154272 load */
    /* @4154280 load */
    /* @4154288 cast */
    /* @4154292 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4154300 constant */
    /* @4154304 constant */
    /* @4154308 constant */
    /* @4154312 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4154320 constant */
    /* @4154324 load */
    /* @4154332 cast */
    /* @4154336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4154344 constant */
    /* @4154348 load */
    /* @4154356 cast */
    /* @4154360 constant */
    /* @4154364 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4154372 load */
    /* @4154380 constant */
    /* @4154384 add */
    /* @4154388 store */
    v45 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v45);
    /* @4154396 constant */
    /* @4154400 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4154408 load */
    /* @4154416 constant */
    /* @4154420 cmp */
    /* @4154424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4154456;
    /* @4154428 constant */
    /* @4154432 load */
    /* @4154440 cast */
    /* @4154444 constant */
    /* @4154448 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4154456: ;
    /* @4154456 constant */
    /* @4154460 cast */
    /* @4154464 load */
    /* @4154472 load */
    /* @4154480 call */
    GM_SITE(vm, 303, 4154480);
    /* @4154488 store */
    v46 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v46);
    /* @4154496 load */
    /* @4154504 constant */
    /* @4154508 cmp */
    /* @4154512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4154536;
    /* @4154516 load */
    /* @4154524 constant */
    /* @4154528 cmp */
    /* @4154532 b */
    p4154540_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4154540;
    L_4154536: ;
    /* @4154536 constant */
    p4154540_0 = VAL(0);
    L_4154540: ;
    /* @4154540 bf */
    if (!TRUTH(p4154540_0)) goto L_4154888;
    /* @4154544 constant */
    /* @4154548 load */
    /* @4154556 cast */
    /* @4154560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4154568 constant */
    /* @4154572 cast */
    /* @4154576 load */
    /* @4154584 load */
    /* @4154592 load */
    /* @4154600 load */
    /* @4154608 call */
    GM_SITE(vm, 303, 4154608);
    /* @4154616 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4154620 load */
    /* @4154628 cast */
    /* @4154632 dup */
    /* @4154636 load */
    /* @4154644 load */
    /* @4154652 sub */
    /* @4154656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "rocketdamage")));
    /* @4154664 constant */
    /* @4154668 cast */
    /* @4154672 load */
    /* @4154680 load */
    /* @4154688 call */
    GM_SITE(vm, 303, 4154688);
    /* @4154696 store */
    v47 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v47);
    /* @4154704 load */
    /* @4154712 load */
    /* @4154720 cast */
    /* @4154724 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4154732 constant */
    /* @4154736 constant */
    /* @4154740 constant */
    /* @4154744 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4154752 constant */
    /* @4154756 load */
    /* @4154764 cast */
    /* @4154768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4154776 constant */
    /* @4154780 load */
    /* @4154788 cast */
    /* @4154792 constant */
    /* @4154796 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4154804 load */
    /* @4154812 constant */
    /* @4154816 add */
    /* @4154820 store */
    v48 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v48);
    /* @4154828 constant */
    /* @4154832 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    /* @4154840 load */
    /* @4154848 constant */
    /* @4154852 cmp */
    /* @4154856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4154888;
    /* @4154860 constant */
    /* @4154864 load */
    /* @4154872 cast */
    /* @4154876 constant */
    /* @4154880 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4154888: ;
    /* @4154888 constant */
    /* @4154892 cast */
    /* @4154896 load */
    /* @4154904 load */
    /* @4154912 call */
    GM_SITE(vm, 303, 4154912);
    /* @4154920 store */
    v49 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v49);
    /* @4154928 load */
    /* @4154936 constant */
    /* @4154940 cmp */
    /* @4154944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4154968;
    /* @4154948 load */
    /* @4154956 constant */
    /* @4154960 cmp */
    /* @4154964 b */
    p4154972_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4154972;
    L_4154968: ;
    /* @4154968 constant */
    p4154972_0 = VAL(0);
    L_4154972: ;
    /* @4154972 bf */
    if (!TRUTH(p4154972_0)) goto L_4155220;
    /* @4154976 constant */
    /* @4154980 load */
    /* @4154988 cast */
    /* @4154992 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4155000 constant */
    /* @4155004 cast */
    /* @4155008 load */
    /* @4155016 load */
    /* @4155024 load */
    /* @4155032 load */
    /* @4155040 call */
    GM_SITE(vm, 303, 4155040);
    /* @4155048 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4155052 load */
    /* @4155060 cast */
    /* @4155064 dup */
    /* @4155068 load */
    /* @4155076 load */
    /* @4155084 sub */
    /* @4155088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "rocketdamage")));
    /* @4155096 constant */
    /* @4155100 cast */
    /* @4155104 load */
    /* @4155112 load */
    /* @4155120 call */
    GM_SITE(vm, 303, 4155120);
    /* @4155128 store */
    v50 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v50);
    /* @4155136 load */
    /* @4155144 load */
    /* @4155152 cast */
    /* @4155156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4155164 constant */
    /* @4155168 constant */
    /* @4155172 constant */
    /* @4155176 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4155184 load */
    /* @4155192 constant */
    /* @4155196 add */
    /* @4155200 store */
    v51 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v51);
    /* @4155208 constant */
    /* @4155212 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4155220: ;
    /* @4155220 constant */
    /* @4155224 cast */
    /* @4155228 load */
    /* @4155236 load */
    /* @4155244 call */
    GM_SITE(vm, 303, 4155244);
    /* @4155252 store */
    v52 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v52);
    /* @4155260 load */
    /* @4155268 constant */
    /* @4155272 cmp */
    /* @4155276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4155300;
    /* @4155280 load */
    /* @4155288 constant */
    /* @4155292 cmp */
    /* @4155296 b */
    p4155304_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4155304;
    L_4155300: ;
    /* @4155300 constant */
    p4155304_0 = VAL(0);
    L_4155304: ;
    /* @4155304 bf */
    if (!TRUTH(p4155304_0)) goto L_4155552;
    /* @4155308 constant */
    /* @4155312 load */
    /* @4155320 cast */
    /* @4155324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4155332 constant */
    /* @4155336 cast */
    /* @4155340 load */
    /* @4155348 load */
    /* @4155356 load */
    /* @4155364 load */
    /* @4155372 call */
    GM_SITE(vm, 303, 4155372);
    /* @4155380 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4155384 load */
    /* @4155392 cast */
    /* @4155396 dup */
    /* @4155400 load */
    /* @4155408 load */
    /* @4155416 sub */
    /* @4155420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "rocketdamage")));
    /* @4155428 constant */
    /* @4155432 cast */
    /* @4155436 load */
    /* @4155444 load */
    /* @4155452 call */
    GM_SITE(vm, 303, 4155452);
    /* @4155460 store */
    v53 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v53);
    /* @4155468 load */
    /* @4155476 load */
    /* @4155484 cast */
    /* @4155488 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4155496 constant */
    /* @4155500 constant */
    /* @4155504 constant */
    /* @4155508 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4155516 load */
    /* @4155524 constant */
    /* @4155528 add */
    /* @4155532 store */
    v54 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v54);
    /* @4155540 constant */
    /* @4155544 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4155552: ;
    /* @4155552 constant */
    /* @4155556 cast */
    /* @4155560 load */
    /* @4155568 load */
    /* @4155576 call */
    GM_SITE(vm, 303, 4155576);
    /* @4155584 store */
    v55 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v55);
    /* @4155592 load */
    /* @4155600 constant */
    /* @4155604 cmp */
    /* @4155608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4155632;
    /* @4155612 load */
    /* @4155620 constant */
    /* @4155624 cmp */
    /* @4155628 b */
    p4155636_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4155636;
    L_4155632: ;
    /* @4155632 constant */
    p4155636_0 = VAL(0);
    L_4155636: ;
    /* @4155636 bf */
    if (!TRUTH(p4155636_0)) goto L_4155884;
    /* @4155640 constant */
    /* @4155644 load */
    /* @4155652 cast */
    /* @4155656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4155664 constant */
    /* @4155668 cast */
    /* @4155672 load */
    /* @4155680 load */
    /* @4155688 load */
    /* @4155696 load */
    /* @4155704 call */
    GM_SITE(vm, 303, 4155704);
    /* @4155712 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4155716 load */
    /* @4155724 cast */
    /* @4155728 dup */
    /* @4155732 load */
    /* @4155740 load */
    /* @4155748 sub */
    /* @4155752 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "rocketdamage")));
    /* @4155760 constant */
    /* @4155764 cast */
    /* @4155768 load */
    /* @4155776 load */
    /* @4155784 call */
    GM_SITE(vm, 303, 4155784);
    /* @4155792 store */
    v56 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v56);
    /* @4155800 load */
    /* @4155808 load */
    /* @4155816 cast */
    /* @4155820 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4155828 constant */
    /* @4155832 constant */
    /* @4155836 constant */
    /* @4155840 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4155848 load */
    /* @4155856 constant */
    /* @4155860 add */
    /* @4155864 store */
    v57 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v57);
    /* @4155872 constant */
    /* @4155876 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4155884: ;
    /* @4155884 constant */
    /* @4155888 cast */
    /* @4155892 load */
    /* @4155900 load */
    /* @4155908 call */
    GM_SITE(vm, 303, 4155908);
    /* @4155916 store */
    v58 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v58);
    /* @4155924 load */
    /* @4155932 constant */
    /* @4155936 cmp */
    /* @4155940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4155964;
    /* @4155944 load */
    /* @4155952 constant */
    /* @4155956 cmp */
    /* @4155960 b */
    p4155968_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4155968;
    L_4155964: ;
    /* @4155964 constant */
    p4155968_0 = VAL(0);
    L_4155968: ;
    /* @4155968 bf */
    if (!TRUTH(p4155968_0)) goto L_4156216;
    /* @4155972 constant */
    /* @4155976 load */
    /* @4155984 cast */
    /* @4155988 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4155996 constant */
    /* @4156000 cast */
    /* @4156004 load */
    /* @4156012 load */
    /* @4156020 load */
    /* @4156028 load */
    /* @4156036 call */
    GM_SITE(vm, 303, 4156036);
    /* @4156044 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4156048 load */
    /* @4156056 cast */
    /* @4156060 dup */
    /* @4156064 load */
    /* @4156072 load */
    /* @4156080 sub */
    /* @4156084 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "rocketdamage")));
    /* @4156092 constant */
    /* @4156096 cast */
    /* @4156100 load */
    /* @4156108 load */
    /* @4156116 call */
    GM_SITE(vm, 303, 4156116);
    /* @4156124 store */
    v59 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v59);
    /* @4156132 load */
    /* @4156140 load */
    /* @4156148 cast */
    /* @4156152 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4156160 constant */
    /* @4156164 constant */
    /* @4156168 constant */
    /* @4156172 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4156180 load */
    /* @4156188 constant */
    /* @4156192 add */
    /* @4156196 store */
    v60 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v60);
    /* @4156204 constant */
    /* @4156208 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4156216: ;
    /* @4156216 constant */
    /* @4156220 cast */
    /* @4156224 load */
    /* @4156232 load */
    /* @4156240 call */
    GM_SITE(vm, 303, 4156240);
    /* @4156248 store */
    v61 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v61);
    /* @4156256 load */
    /* @4156264 constant */
    /* @4156268 cmp */
    /* @4156272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4156296;
    /* @4156276 load */
    /* @4156284 constant */
    /* @4156288 cmp */
    /* @4156292 b */
    p4156300_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4156300;
    L_4156296: ;
    /* @4156296 constant */
    p4156300_0 = VAL(0);
    L_4156300: ;
    /* @4156300 bf */
    if (!TRUTH(p4156300_0)) goto L_4156548;
    /* @4156304 constant */
    /* @4156308 load */
    /* @4156316 cast */
    /* @4156320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4156328 constant */
    /* @4156332 cast */
    /* @4156336 load */
    /* @4156344 load */
    /* @4156352 load */
    /* @4156360 load */
    /* @4156368 call */
    GM_SITE(vm, 303, 4156368);
    /* @4156376 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4156380 load */
    /* @4156388 cast */
    /* @4156392 dup */
    /* @4156396 load */
    /* @4156404 load */
    /* @4156412 sub */
    /* @4156416 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "rocketdamage")));
    /* @4156424 constant */
    /* @4156428 cast */
    /* @4156432 load */
    /* @4156440 load */
    /* @4156448 call */
    GM_SITE(vm, 303, 4156448);
    /* @4156456 store */
    v62 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v62);
    /* @4156464 load */
    /* @4156472 load */
    /* @4156480 cast */
    /* @4156484 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "rocketdamage"));
    /* @4156492 constant */
    /* @4156496 constant */
    /* @4156500 constant */
    /* @4156504 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4156512 load */
    /* @4156520 constant */
    /* @4156524 add */
    /* @4156528 store */
    v63 = GM_ADD(GM_READ(vm, -5, "rocketxp"), VAL(1));
    GM_WRITE(vm, -5, "rocketxp", v63);
    /* @4156536 constant */
    /* @4156540 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4156548: ;
    return;
}
