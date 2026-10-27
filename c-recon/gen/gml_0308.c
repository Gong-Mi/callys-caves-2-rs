/* generated from CODE 308 (gml_Object_obj_energywave_Step_0), source start 4156768, end 4163572. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0308(GmVM* vm) {
    Val v1;
    Val v2;
    Val p4156928_0;
    Val v3;
    Val v4;
    Val p4157280_0;
    Val v5;
    Val v6;
    Val p4157632_0;
    Val v7;
    Val v8;
    Val p4157984_0;
    Val v9;
    Val v10;
    Val p4158336_0;
    Val v11;
    Val v12;
    Val p4158636_0;
    Val v13;
    Val v14;
    Val p4158988_0;
    Val v15;
    Val v16;
    Val p4159340_0;
    Val v17;
    Val v18;
    Val p4159692_0;
    Val v19;
    Val v20;
    Val p4160044_0;
    Val v21;
    Val v22;
    Val p4160396_0;
    Val v23;
    Val v24;
    Val p4160748_0;
    Val v25;
    Val v26;
    Val p4161100_0;
    Val v27;
    Val v28;
    Val p4161452_0;
    Val v29;
    Val v30;
    Val p4161804_0;
    Val v31;
    Val v32;
    Val p4162156_0;
    Val v33;
    Val v34;
    Val p4162456_0;
    Val v35;
    Val v36;
    Val p4162756_0;
    Val v37;
    Val v38;
    Val p4163056_0;
    Val v39;
    Val v40;
    Val p4163356_0;
    Val v41;
    /* @4156768 constant */
    /* @4156772 cast */
    /* @4156776 load */
    /* @4156784 load */
    /* @4156792 call */
    GM_SITE(vm, 308, 4156792);
    /* @4156800 cast */
    /* @4156804 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v1)) goto L_4156828;
    /* @4156808 constant */
    /* @4156812 constant */
    /* @4156816 constant */
    /* @4156820 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4156828: ;
    /* @4156828 load */
    /* @4156836 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4156844 constant */
    /* @4156848 cast */
    /* @4156852 load */
    /* @4156860 load */
    /* @4156868 call */
    GM_SITE(vm, 308, 4156868);
    /* @4156876 store */
    v2 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v2);
    /* @4156884 load */
    /* @4156892 constant */
    /* @4156896 cmp */
    /* @4156900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4156924;
    /* @4156904 load */
    /* @4156912 constant */
    /* @4156916 cmp */
    /* @4156920 b */
    p4156928_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4156928;
    L_4156924: ;
    /* @4156924 constant */
    p4156928_0 = VAL(0);
    L_4156928: ;
    /* @4156928 bf */
    if (!TRUTH(p4156928_0)) goto L_4157196;
    /* @4156932 constant */
    /* @4156936 load */
    /* @4156944 cast */
    /* @4156948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4156956 constant */
    /* @4156960 cast */
    /* @4156964 load */
    /* @4156972 load */
    /* @4156980 load */
    /* @4156988 load */
    /* @4156996 call */
    GM_SITE(vm, 308, 4156996);
    /* @4157004 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4157008 load */
    /* @4157016 cast */
    /* @4157020 dup */
    /* @4157024 load */
    /* @4157032 constant */
    /* @4157036 sub */
    /* @4157040 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - VAL(3)));
    /* @4157048 constant */
    /* @4157052 cast */
    /* @4157056 load */
    /* @4157064 load */
    /* @4157072 call */
    GM_SITE(vm, 308, 4157072);
    /* @4157080 store */
    v3 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v3);
    /* @4157088 constant */
    /* @4157092 load */
    /* @4157100 cast */
    /* @4157104 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4157112 constant */
    /* @4157116 constant */
    /* @4157120 constant */
    /* @4157124 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4157132 constant */
    /* @4157136 load */
    /* @4157144 cast */
    /* @4157148 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "stunned", VAL(1));
    /* @4157156 constant */
    /* @4157160 load */
    /* @4157168 cast */
    /* @4157172 constant */
    /* @4157176 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(4), VAL(10));
    /* @4157184 constant */
    /* @4157188 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4157196: ;
    /* @4157196 constant */
    /* @4157200 cast */
    /* @4157204 load */
    /* @4157212 load */
    /* @4157220 call */
    GM_SITE(vm, 308, 4157220);
    /* @4157228 store */
    v4 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v4);
    /* @4157236 load */
    /* @4157244 constant */
    /* @4157248 cmp */
    /* @4157252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4157276;
    /* @4157256 load */
    /* @4157264 constant */
    /* @4157268 cmp */
    /* @4157272 b */
    p4157280_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4157280;
    L_4157276: ;
    /* @4157276 constant */
    p4157280_0 = VAL(0);
    L_4157280: ;
    /* @4157280 bf */
    if (!TRUTH(p4157280_0)) goto L_4157548;
    /* @4157284 constant */
    /* @4157288 load */
    /* @4157296 cast */
    /* @4157300 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4157308 constant */
    /* @4157312 cast */
    /* @4157316 load */
    /* @4157324 load */
    /* @4157332 load */
    /* @4157340 load */
    /* @4157348 call */
    GM_SITE(vm, 308, 4157348);
    /* @4157356 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4157360 load */
    /* @4157368 cast */
    /* @4157372 dup */
    /* @4157376 load */
    /* @4157384 constant */
    /* @4157388 sub */
    /* @4157392 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - VAL(3)));
    /* @4157400 constant */
    /* @4157404 cast */
    /* @4157408 load */
    /* @4157416 load */
    /* @4157424 call */
    GM_SITE(vm, 308, 4157424);
    /* @4157432 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v5);
    /* @4157440 constant */
    /* @4157444 load */
    /* @4157452 cast */
    /* @4157456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4157464 constant */
    /* @4157468 constant */
    /* @4157472 constant */
    /* @4157476 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4157484 constant */
    /* @4157488 load */
    /* @4157496 cast */
    /* @4157500 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "stunned", VAL(1));
    /* @4157508 constant */
    /* @4157512 load */
    /* @4157520 cast */
    /* @4157524 constant */
    /* @4157528 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(4), VAL(10));
    /* @4157536 constant */
    /* @4157540 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4157548: ;
    /* @4157548 constant */
    /* @4157552 cast */
    /* @4157556 load */
    /* @4157564 load */
    /* @4157572 call */
    GM_SITE(vm, 308, 4157572);
    /* @4157580 store */
    v6 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v6);
    /* @4157588 load */
    /* @4157596 constant */
    /* @4157600 cmp */
    /* @4157604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4157628;
    /* @4157608 load */
    /* @4157616 constant */
    /* @4157620 cmp */
    /* @4157624 b */
    p4157632_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4157632;
    L_4157628: ;
    /* @4157628 constant */
    p4157632_0 = VAL(0);
    L_4157632: ;
    /* @4157632 bf */
    if (!TRUTH(p4157632_0)) goto L_4157900;
    /* @4157636 constant */
    /* @4157640 load */
    /* @4157648 cast */
    /* @4157652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4157660 constant */
    /* @4157664 cast */
    /* @4157668 load */
    /* @4157676 load */
    /* @4157684 load */
    /* @4157692 load */
    /* @4157700 call */
    GM_SITE(vm, 308, 4157700);
    /* @4157708 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4157712 load */
    /* @4157720 cast */
    /* @4157724 dup */
    /* @4157728 load */
    /* @4157736 constant */
    /* @4157740 sub */
    /* @4157744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - VAL(3)));
    /* @4157752 constant */
    /* @4157756 cast */
    /* @4157760 load */
    /* @4157768 load */
    /* @4157776 call */
    GM_SITE(vm, 308, 4157776);
    /* @4157784 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v7);
    /* @4157792 constant */
    /* @4157796 load */
    /* @4157804 cast */
    /* @4157808 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4157816 constant */
    /* @4157820 constant */
    /* @4157824 constant */
    /* @4157828 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4157836 constant */
    /* @4157840 load */
    /* @4157848 cast */
    /* @4157852 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "stunned", VAL(1));
    /* @4157860 constant */
    /* @4157864 load */
    /* @4157872 cast */
    /* @4157876 constant */
    /* @4157880 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(4), VAL(10));
    /* @4157888 constant */
    /* @4157892 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4157900: ;
    /* @4157900 constant */
    /* @4157904 cast */
    /* @4157908 load */
    /* @4157916 load */
    /* @4157924 call */
    GM_SITE(vm, 308, 4157924);
    /* @4157932 store */
    v8 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v8);
    /* @4157940 load */
    /* @4157948 constant */
    /* @4157952 cmp */
    /* @4157956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4157980;
    /* @4157960 load */
    /* @4157968 constant */
    /* @4157972 cmp */
    /* @4157976 b */
    p4157984_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4157984;
    L_4157980: ;
    /* @4157980 constant */
    p4157984_0 = VAL(0);
    L_4157984: ;
    /* @4157984 bf */
    if (!TRUTH(p4157984_0)) goto L_4158252;
    /* @4157988 constant */
    /* @4157992 load */
    /* @4158000 cast */
    /* @4158004 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4158012 constant */
    /* @4158016 cast */
    /* @4158020 load */
    /* @4158028 load */
    /* @4158036 load */
    /* @4158044 load */
    /* @4158052 call */
    GM_SITE(vm, 308, 4158052);
    /* @4158060 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4158064 load */
    /* @4158072 cast */
    /* @4158076 dup */
    /* @4158080 load */
    /* @4158088 constant */
    /* @4158092 sub */
    /* @4158096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - VAL(3)));
    /* @4158104 constant */
    /* @4158108 cast */
    /* @4158112 load */
    /* @4158120 load */
    /* @4158128 call */
    GM_SITE(vm, 308, 4158128);
    /* @4158136 store */
    v9 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v9);
    /* @4158144 constant */
    /* @4158148 load */
    /* @4158156 cast */
    /* @4158160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4158168 constant */
    /* @4158172 constant */
    /* @4158176 constant */
    /* @4158180 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4158188 constant */
    /* @4158192 load */
    /* @4158200 cast */
    /* @4158204 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "stunned", VAL(1));
    /* @4158212 constant */
    /* @4158216 load */
    /* @4158224 cast */
    /* @4158228 constant */
    /* @4158232 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(4), VAL(10));
    /* @4158240 constant */
    /* @4158244 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4158252: ;
    /* @4158252 constant */
    /* @4158256 cast */
    /* @4158260 load */
    /* @4158268 load */
    /* @4158276 call */
    GM_SITE(vm, 308, 4158276);
    /* @4158284 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v10);
    /* @4158292 load */
    /* @4158300 constant */
    /* @4158304 cmp */
    /* @4158308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4158332;
    /* @4158312 load */
    /* @4158320 constant */
    /* @4158324 cmp */
    /* @4158328 b */
    p4158336_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4158336;
    L_4158332: ;
    /* @4158332 constant */
    p4158336_0 = VAL(0);
    L_4158336: ;
    /* @4158336 bf */
    if (!TRUTH(p4158336_0)) goto L_4158552;
    /* @4158340 constant */
    /* @4158344 load */
    /* @4158352 cast */
    /* @4158356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4158364 constant */
    /* @4158368 cast */
    /* @4158372 load */
    /* @4158380 load */
    /* @4158388 load */
    /* @4158396 load */
    /* @4158404 call */
    GM_SITE(vm, 308, 4158404);
    /* @4158412 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4158416 load */
    /* @4158424 cast */
    /* @4158428 dup */
    /* @4158432 load */
    /* @4158440 constant */
    /* @4158444 sub */
    /* @4158448 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - VAL(3)));
    /* @4158456 constant */
    /* @4158460 cast */
    /* @4158464 load */
    /* @4158472 load */
    /* @4158480 call */
    GM_SITE(vm, 308, 4158480);
    /* @4158488 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4158496 constant */
    /* @4158500 load */
    /* @4158508 cast */
    /* @4158512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4158520 constant */
    /* @4158524 constant */
    /* @4158528 constant */
    /* @4158532 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4158540 constant */
    /* @4158544 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4158552: ;
    /* @4158552 constant */
    /* @4158556 cast */
    /* @4158560 load */
    /* @4158568 load */
    /* @4158576 call */
    GM_SITE(vm, 308, 4158576);
    /* @4158584 store */
    v12 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v12);
    /* @4158592 load */
    /* @4158600 constant */
    /* @4158604 cmp */
    /* @4158608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4158632;
    /* @4158612 load */
    /* @4158620 constant */
    /* @4158624 cmp */
    /* @4158628 b */
    p4158636_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4158636;
    L_4158632: ;
    /* @4158632 constant */
    p4158636_0 = VAL(0);
    L_4158636: ;
    /* @4158636 bf */
    if (!TRUTH(p4158636_0)) goto L_4158904;
    /* @4158640 constant */
    /* @4158644 load */
    /* @4158652 cast */
    /* @4158656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4158664 constant */
    /* @4158668 cast */
    /* @4158672 load */
    /* @4158680 load */
    /* @4158688 load */
    /* @4158696 load */
    /* @4158704 call */
    GM_SITE(vm, 308, 4158704);
    /* @4158712 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4158716 load */
    /* @4158724 cast */
    /* @4158728 dup */
    /* @4158732 load */
    /* @4158740 constant */
    /* @4158744 sub */
    /* @4158748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - VAL(3)));
    /* @4158756 constant */
    /* @4158760 cast */
    /* @4158764 load */
    /* @4158772 load */
    /* @4158780 call */
    GM_SITE(vm, 308, 4158780);
    /* @4158788 store */
    v13 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v13);
    /* @4158796 constant */
    /* @4158800 load */
    /* @4158808 cast */
    /* @4158812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4158820 constant */
    /* @4158824 constant */
    /* @4158828 constant */
    /* @4158832 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4158840 constant */
    /* @4158844 load */
    /* @4158852 cast */
    /* @4158856 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "stunned", VAL(1));
    /* @4158864 constant */
    /* @4158868 load */
    /* @4158876 cast */
    /* @4158880 constant */
    /* @4158884 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(4), VAL(10));
    /* @4158892 constant */
    /* @4158896 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4158904: ;
    /* @4158904 constant */
    /* @4158908 cast */
    /* @4158912 load */
    /* @4158920 load */
    /* @4158928 call */
    GM_SITE(vm, 308, 4158928);
    /* @4158936 store */
    v14 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v14);
    /* @4158944 load */
    /* @4158952 constant */
    /* @4158956 cmp */
    /* @4158960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4158984;
    /* @4158964 load */
    /* @4158972 constant */
    /* @4158976 cmp */
    /* @4158980 b */
    p4158988_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4158988;
    L_4158984: ;
    /* @4158984 constant */
    p4158988_0 = VAL(0);
    L_4158988: ;
    /* @4158988 bf */
    if (!TRUTH(p4158988_0)) goto L_4159256;
    /* @4158992 constant */
    /* @4158996 load */
    /* @4159004 cast */
    /* @4159008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4159016 constant */
    /* @4159020 cast */
    /* @4159024 load */
    /* @4159032 load */
    /* @4159040 load */
    /* @4159048 load */
    /* @4159056 call */
    GM_SITE(vm, 308, 4159056);
    /* @4159064 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4159068 load */
    /* @4159076 cast */
    /* @4159080 dup */
    /* @4159084 load */
    /* @4159092 constant */
    /* @4159096 sub */
    /* @4159100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - VAL(3)));
    /* @4159108 constant */
    /* @4159112 cast */
    /* @4159116 load */
    /* @4159124 load */
    /* @4159132 call */
    GM_SITE(vm, 308, 4159132);
    /* @4159140 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v15);
    /* @4159148 constant */
    /* @4159152 load */
    /* @4159160 cast */
    /* @4159164 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4159172 constant */
    /* @4159176 constant */
    /* @4159180 constant */
    /* @4159184 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4159192 constant */
    /* @4159196 load */
    /* @4159204 cast */
    /* @4159208 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "stunned", VAL(1));
    /* @4159216 constant */
    /* @4159220 load */
    /* @4159228 cast */
    /* @4159232 constant */
    /* @4159236 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(4), VAL(10));
    /* @4159244 constant */
    /* @4159248 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4159256: ;
    /* @4159256 constant */
    /* @4159260 cast */
    /* @4159264 load */
    /* @4159272 load */
    /* @4159280 call */
    GM_SITE(vm, 308, 4159280);
    /* @4159288 store */
    v16 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v16);
    /* @4159296 load */
    /* @4159304 constant */
    /* @4159308 cmp */
    /* @4159312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4159336;
    /* @4159316 load */
    /* @4159324 constant */
    /* @4159328 cmp */
    /* @4159332 b */
    p4159340_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4159340;
    L_4159336: ;
    /* @4159336 constant */
    p4159340_0 = VAL(0);
    L_4159340: ;
    /* @4159340 bf */
    if (!TRUTH(p4159340_0)) goto L_4159608;
    /* @4159344 constant */
    /* @4159348 load */
    /* @4159356 cast */
    /* @4159360 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4159368 constant */
    /* @4159372 cast */
    /* @4159376 load */
    /* @4159384 load */
    /* @4159392 load */
    /* @4159400 load */
    /* @4159408 call */
    GM_SITE(vm, 308, 4159408);
    /* @4159416 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4159420 load */
    /* @4159428 cast */
    /* @4159432 dup */
    /* @4159436 load */
    /* @4159444 constant */
    /* @4159448 sub */
    /* @4159452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - VAL(3)));
    /* @4159460 constant */
    /* @4159464 cast */
    /* @4159468 load */
    /* @4159476 load */
    /* @4159484 call */
    GM_SITE(vm, 308, 4159484);
    /* @4159492 store */
    v17 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v17);
    /* @4159500 constant */
    /* @4159504 load */
    /* @4159512 cast */
    /* @4159516 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4159524 constant */
    /* @4159528 constant */
    /* @4159532 constant */
    /* @4159536 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4159544 constant */
    /* @4159548 load */
    /* @4159556 cast */
    /* @4159560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "stunned", VAL(1));
    /* @4159568 constant */
    /* @4159572 load */
    /* @4159580 cast */
    /* @4159584 constant */
    /* @4159588 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(4), VAL(10));
    /* @4159596 constant */
    /* @4159600 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4159608: ;
    /* @4159608 constant */
    /* @4159612 cast */
    /* @4159616 load */
    /* @4159624 load */
    /* @4159632 call */
    GM_SITE(vm, 308, 4159632);
    /* @4159640 store */
    v18 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v18);
    /* @4159648 load */
    /* @4159656 constant */
    /* @4159660 cmp */
    /* @4159664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4159688;
    /* @4159668 load */
    /* @4159676 constant */
    /* @4159680 cmp */
    /* @4159684 b */
    p4159692_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4159692;
    L_4159688: ;
    /* @4159688 constant */
    p4159692_0 = VAL(0);
    L_4159692: ;
    /* @4159692 bf */
    if (!TRUTH(p4159692_0)) goto L_4159960;
    /* @4159696 constant */
    /* @4159700 load */
    /* @4159708 cast */
    /* @4159712 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4159720 constant */
    /* @4159724 cast */
    /* @4159728 load */
    /* @4159736 load */
    /* @4159744 load */
    /* @4159752 load */
    /* @4159760 call */
    GM_SITE(vm, 308, 4159760);
    /* @4159768 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4159772 load */
    /* @4159780 cast */
    /* @4159784 dup */
    /* @4159788 load */
    /* @4159796 constant */
    /* @4159800 sub */
    /* @4159804 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - VAL(3)));
    /* @4159812 constant */
    /* @4159816 cast */
    /* @4159820 load */
    /* @4159828 load */
    /* @4159836 call */
    GM_SITE(vm, 308, 4159836);
    /* @4159844 store */
    v19 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v19);
    /* @4159852 constant */
    /* @4159856 load */
    /* @4159864 cast */
    /* @4159868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4159876 constant */
    /* @4159880 constant */
    /* @4159884 constant */
    /* @4159888 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4159896 constant */
    /* @4159900 load */
    /* @4159908 cast */
    /* @4159912 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "stunned", VAL(1));
    /* @4159920 constant */
    /* @4159924 load */
    /* @4159932 cast */
    /* @4159936 constant */
    /* @4159940 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(4), VAL(10));
    /* @4159948 constant */
    /* @4159952 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4159960: ;
    /* @4159960 constant */
    /* @4159964 cast */
    /* @4159968 load */
    /* @4159976 load */
    /* @4159984 call */
    GM_SITE(vm, 308, 4159984);
    /* @4159992 store */
    v20 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v20);
    /* @4160000 load */
    /* @4160008 constant */
    /* @4160012 cmp */
    /* @4160016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4160040;
    /* @4160020 load */
    /* @4160028 constant */
    /* @4160032 cmp */
    /* @4160036 b */
    p4160044_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4160044;
    L_4160040: ;
    /* @4160040 constant */
    p4160044_0 = VAL(0);
    L_4160044: ;
    /* @4160044 bf */
    if (!TRUTH(p4160044_0)) goto L_4160312;
    /* @4160048 constant */
    /* @4160052 load */
    /* @4160060 cast */
    /* @4160064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4160072 constant */
    /* @4160076 cast */
    /* @4160080 load */
    /* @4160088 load */
    /* @4160096 load */
    /* @4160104 load */
    /* @4160112 call */
    GM_SITE(vm, 308, 4160112);
    /* @4160120 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4160124 load */
    /* @4160132 cast */
    /* @4160136 dup */
    /* @4160140 load */
    /* @4160148 constant */
    /* @4160152 sub */
    /* @4160156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - VAL(3)));
    /* @4160164 constant */
    /* @4160168 cast */
    /* @4160172 load */
    /* @4160180 load */
    /* @4160188 call */
    GM_SITE(vm, 308, 4160188);
    /* @4160196 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v21);
    /* @4160204 constant */
    /* @4160208 load */
    /* @4160216 cast */
    /* @4160220 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4160228 constant */
    /* @4160232 constant */
    /* @4160236 constant */
    /* @4160240 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4160248 constant */
    /* @4160252 load */
    /* @4160260 cast */
    /* @4160264 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "stunned", VAL(1));
    /* @4160272 constant */
    /* @4160276 load */
    /* @4160284 cast */
    /* @4160288 constant */
    /* @4160292 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(4), VAL(10));
    /* @4160300 constant */
    /* @4160304 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4160312: ;
    /* @4160312 constant */
    /* @4160316 cast */
    /* @4160320 load */
    /* @4160328 load */
    /* @4160336 call */
    GM_SITE(vm, 308, 4160336);
    /* @4160344 store */
    v22 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v22);
    /* @4160352 load */
    /* @4160360 constant */
    /* @4160364 cmp */
    /* @4160368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4160392;
    /* @4160372 load */
    /* @4160380 constant */
    /* @4160384 cmp */
    /* @4160388 b */
    p4160396_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4160396;
    L_4160392: ;
    /* @4160392 constant */
    p4160396_0 = VAL(0);
    L_4160396: ;
    /* @4160396 bf */
    if (!TRUTH(p4160396_0)) goto L_4160664;
    /* @4160400 constant */
    /* @4160404 load */
    /* @4160412 cast */
    /* @4160416 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4160424 constant */
    /* @4160428 cast */
    /* @4160432 load */
    /* @4160440 load */
    /* @4160448 load */
    /* @4160456 load */
    /* @4160464 call */
    GM_SITE(vm, 308, 4160464);
    /* @4160472 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4160476 load */
    /* @4160484 cast */
    /* @4160488 dup */
    /* @4160492 load */
    /* @4160500 constant */
    /* @4160504 sub */
    /* @4160508 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - VAL(3)));
    /* @4160516 constant */
    /* @4160520 cast */
    /* @4160524 load */
    /* @4160532 load */
    /* @4160540 call */
    GM_SITE(vm, 308, 4160540);
    /* @4160548 store */
    v23 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v23);
    /* @4160556 constant */
    /* @4160560 load */
    /* @4160568 cast */
    /* @4160572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4160580 constant */
    /* @4160584 constant */
    /* @4160588 constant */
    /* @4160592 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4160600 constant */
    /* @4160604 load */
    /* @4160612 cast */
    /* @4160616 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "stunned", VAL(1));
    /* @4160624 constant */
    /* @4160628 load */
    /* @4160636 cast */
    /* @4160640 constant */
    /* @4160644 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(4), VAL(10));
    /* @4160652 constant */
    /* @4160656 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4160664: ;
    /* @4160664 constant */
    /* @4160668 cast */
    /* @4160672 load */
    /* @4160680 load */
    /* @4160688 call */
    GM_SITE(vm, 308, 4160688);
    /* @4160696 store */
    v24 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v24);
    /* @4160704 load */
    /* @4160712 constant */
    /* @4160716 cmp */
    /* @4160720 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4160744;
    /* @4160724 load */
    /* @4160732 constant */
    /* @4160736 cmp */
    /* @4160740 b */
    p4160748_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4160748;
    L_4160744: ;
    /* @4160744 constant */
    p4160748_0 = VAL(0);
    L_4160748: ;
    /* @4160748 bf */
    if (!TRUTH(p4160748_0)) goto L_4161016;
    /* @4160752 constant */
    /* @4160756 load */
    /* @4160764 cast */
    /* @4160768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4160776 constant */
    /* @4160780 cast */
    /* @4160784 load */
    /* @4160792 load */
    /* @4160800 load */
    /* @4160808 load */
    /* @4160816 call */
    GM_SITE(vm, 308, 4160816);
    /* @4160824 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4160828 load */
    /* @4160836 cast */
    /* @4160840 dup */
    /* @4160844 load */
    /* @4160852 constant */
    /* @4160856 sub */
    /* @4160860 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - VAL(3)));
    /* @4160868 constant */
    /* @4160872 cast */
    /* @4160876 load */
    /* @4160884 load */
    /* @4160892 call */
    GM_SITE(vm, 308, 4160892);
    /* @4160900 store */
    v25 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v25);
    /* @4160908 constant */
    /* @4160912 load */
    /* @4160920 cast */
    /* @4160924 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4160932 constant */
    /* @4160936 constant */
    /* @4160940 constant */
    /* @4160944 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4160952 constant */
    /* @4160956 load */
    /* @4160964 cast */
    /* @4160968 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "stunned", VAL(1));
    /* @4160976 constant */
    /* @4160980 load */
    /* @4160988 cast */
    /* @4160992 constant */
    /* @4160996 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(4), VAL(10));
    /* @4161004 constant */
    /* @4161008 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4161016: ;
    /* @4161016 constant */
    /* @4161020 cast */
    /* @4161024 load */
    /* @4161032 load */
    /* @4161040 call */
    GM_SITE(vm, 308, 4161040);
    /* @4161048 store */
    v26 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v26);
    /* @4161056 load */
    /* @4161064 constant */
    /* @4161068 cmp */
    /* @4161072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4161096;
    /* @4161076 load */
    /* @4161084 constant */
    /* @4161088 cmp */
    /* @4161092 b */
    p4161100_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4161100;
    L_4161096: ;
    /* @4161096 constant */
    p4161100_0 = VAL(0);
    L_4161100: ;
    /* @4161100 bf */
    if (!TRUTH(p4161100_0)) goto L_4161368;
    /* @4161104 constant */
    /* @4161108 load */
    /* @4161116 cast */
    /* @4161120 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4161128 constant */
    /* @4161132 cast */
    /* @4161136 load */
    /* @4161144 load */
    /* @4161152 load */
    /* @4161160 load */
    /* @4161168 call */
    GM_SITE(vm, 308, 4161168);
    /* @4161176 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4161180 load */
    /* @4161188 cast */
    /* @4161192 dup */
    /* @4161196 load */
    /* @4161204 constant */
    /* @4161208 sub */
    /* @4161212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - VAL(3)));
    /* @4161220 constant */
    /* @4161224 cast */
    /* @4161228 load */
    /* @4161236 load */
    /* @4161244 call */
    GM_SITE(vm, 308, 4161244);
    /* @4161252 store */
    v27 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v27);
    /* @4161260 constant */
    /* @4161264 load */
    /* @4161272 cast */
    /* @4161276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4161284 constant */
    /* @4161288 constant */
    /* @4161292 constant */
    /* @4161296 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4161304 constant */
    /* @4161308 load */
    /* @4161316 cast */
    /* @4161320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "stunned", VAL(1));
    /* @4161328 constant */
    /* @4161332 load */
    /* @4161340 cast */
    /* @4161344 constant */
    /* @4161348 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(4), VAL(10));
    /* @4161356 constant */
    /* @4161360 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4161368: ;
    /* @4161368 constant */
    /* @4161372 cast */
    /* @4161376 load */
    /* @4161384 load */
    /* @4161392 call */
    GM_SITE(vm, 308, 4161392);
    /* @4161400 store */
    v28 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v28);
    /* @4161408 load */
    /* @4161416 constant */
    /* @4161420 cmp */
    /* @4161424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4161448;
    /* @4161428 load */
    /* @4161436 constant */
    /* @4161440 cmp */
    /* @4161444 b */
    p4161452_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4161452;
    L_4161448: ;
    /* @4161448 constant */
    p4161452_0 = VAL(0);
    L_4161452: ;
    /* @4161452 bf */
    if (!TRUTH(p4161452_0)) goto L_4161720;
    /* @4161456 constant */
    /* @4161460 load */
    /* @4161468 cast */
    /* @4161472 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4161480 constant */
    /* @4161484 cast */
    /* @4161488 load */
    /* @4161496 load */
    /* @4161504 load */
    /* @4161512 load */
    /* @4161520 call */
    GM_SITE(vm, 308, 4161520);
    /* @4161528 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4161532 load */
    /* @4161540 cast */
    /* @4161544 dup */
    /* @4161548 load */
    /* @4161556 constant */
    /* @4161560 sub */
    /* @4161564 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - VAL(3)));
    /* @4161572 constant */
    /* @4161576 cast */
    /* @4161580 load */
    /* @4161588 load */
    /* @4161596 call */
    GM_SITE(vm, 308, 4161596);
    /* @4161604 store */
    v29 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v29);
    /* @4161612 constant */
    /* @4161616 load */
    /* @4161624 cast */
    /* @4161628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4161636 constant */
    /* @4161640 constant */
    /* @4161644 constant */
    /* @4161648 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4161656 constant */
    /* @4161660 load */
    /* @4161668 cast */
    /* @4161672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "stunned", VAL(1));
    /* @4161680 constant */
    /* @4161684 load */
    /* @4161692 cast */
    /* @4161696 constant */
    /* @4161700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(4), VAL(10));
    /* @4161708 constant */
    /* @4161712 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4161720: ;
    /* @4161720 constant */
    /* @4161724 cast */
    /* @4161728 load */
    /* @4161736 load */
    /* @4161744 call */
    GM_SITE(vm, 308, 4161744);
    /* @4161752 store */
    v30 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v30);
    /* @4161760 load */
    /* @4161768 constant */
    /* @4161772 cmp */
    /* @4161776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4161800;
    /* @4161780 load */
    /* @4161788 constant */
    /* @4161792 cmp */
    /* @4161796 b */
    p4161804_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4161804;
    L_4161800: ;
    /* @4161800 constant */
    p4161804_0 = VAL(0);
    L_4161804: ;
    /* @4161804 bf */
    if (!TRUTH(p4161804_0)) goto L_4162072;
    /* @4161808 constant */
    /* @4161812 load */
    /* @4161820 cast */
    /* @4161824 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4161832 constant */
    /* @4161836 cast */
    /* @4161840 load */
    /* @4161848 load */
    /* @4161856 load */
    /* @4161864 load */
    /* @4161872 call */
    GM_SITE(vm, 308, 4161872);
    /* @4161880 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4161884 load */
    /* @4161892 cast */
    /* @4161896 dup */
    /* @4161900 load */
    /* @4161908 constant */
    /* @4161912 sub */
    /* @4161916 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - VAL(3)));
    /* @4161924 constant */
    /* @4161928 cast */
    /* @4161932 load */
    /* @4161940 load */
    /* @4161948 call */
    GM_SITE(vm, 308, 4161948);
    /* @4161956 store */
    v31 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v31);
    /* @4161964 constant */
    /* @4161968 load */
    /* @4161976 cast */
    /* @4161980 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4161988 constant */
    /* @4161992 constant */
    /* @4161996 constant */
    /* @4162000 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4162008 constant */
    /* @4162012 load */
    /* @4162020 cast */
    /* @4162024 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "stunned", VAL(1));
    /* @4162032 constant */
    /* @4162036 load */
    /* @4162044 cast */
    /* @4162048 constant */
    /* @4162052 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(4), VAL(10));
    /* @4162060 constant */
    /* @4162064 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4162072: ;
    /* @4162072 constant */
    /* @4162076 cast */
    /* @4162080 load */
    /* @4162088 load */
    /* @4162096 call */
    GM_SITE(vm, 308, 4162096);
    /* @4162104 store */
    v32 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v32);
    /* @4162112 load */
    /* @4162120 constant */
    /* @4162124 cmp */
    /* @4162128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4162152;
    /* @4162132 load */
    /* @4162140 constant */
    /* @4162144 cmp */
    /* @4162148 b */
    p4162156_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4162156;
    L_4162152: ;
    /* @4162152 constant */
    p4162156_0 = VAL(0);
    L_4162156: ;
    /* @4162156 bf */
    if (!TRUTH(p4162156_0)) goto L_4162372;
    /* @4162160 constant */
    /* @4162164 load */
    /* @4162172 cast */
    /* @4162176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4162184 constant */
    /* @4162188 cast */
    /* @4162192 load */
    /* @4162200 load */
    /* @4162208 load */
    /* @4162216 load */
    /* @4162224 call */
    GM_SITE(vm, 308, 4162224);
    /* @4162232 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4162236 load */
    /* @4162244 cast */
    /* @4162248 dup */
    /* @4162252 load */
    /* @4162260 constant */
    /* @4162264 sub */
    /* @4162268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - VAL(3)));
    /* @4162276 constant */
    /* @4162280 cast */
    /* @4162284 load */
    /* @4162292 load */
    /* @4162300 call */
    GM_SITE(vm, 308, 4162300);
    /* @4162308 store */
    v33 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v33);
    /* @4162316 constant */
    /* @4162320 load */
    /* @4162328 cast */
    /* @4162332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4162340 constant */
    /* @4162344 constant */
    /* @4162348 constant */
    /* @4162352 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4162360 constant */
    /* @4162364 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4162372: ;
    /* @4162372 constant */
    /* @4162376 cast */
    /* @4162380 load */
    /* @4162388 load */
    /* @4162396 call */
    GM_SITE(vm, 308, 4162396);
    /* @4162404 store */
    v34 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v34);
    /* @4162412 load */
    /* @4162420 constant */
    /* @4162424 cmp */
    /* @4162428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4162452;
    /* @4162432 load */
    /* @4162440 constant */
    /* @4162444 cmp */
    /* @4162448 b */
    p4162456_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4162456;
    L_4162452: ;
    /* @4162452 constant */
    p4162456_0 = VAL(0);
    L_4162456: ;
    /* @4162456 bf */
    if (!TRUTH(p4162456_0)) goto L_4162672;
    /* @4162460 constant */
    /* @4162464 load */
    /* @4162472 cast */
    /* @4162476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4162484 constant */
    /* @4162488 cast */
    /* @4162492 load */
    /* @4162500 load */
    /* @4162508 load */
    /* @4162516 load */
    /* @4162524 call */
    GM_SITE(vm, 308, 4162524);
    /* @4162532 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4162536 load */
    /* @4162544 cast */
    /* @4162548 dup */
    /* @4162552 load */
    /* @4162560 constant */
    /* @4162564 sub */
    /* @4162568 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - VAL(3)));
    /* @4162576 constant */
    /* @4162580 cast */
    /* @4162584 load */
    /* @4162592 load */
    /* @4162600 call */
    GM_SITE(vm, 308, 4162600);
    /* @4162608 store */
    v35 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v35);
    /* @4162616 constant */
    /* @4162620 load */
    /* @4162628 cast */
    /* @4162632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4162640 constant */
    /* @4162644 constant */
    /* @4162648 constant */
    /* @4162652 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4162660 constant */
    /* @4162664 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4162672: ;
    /* @4162672 constant */
    /* @4162676 cast */
    /* @4162680 load */
    /* @4162688 load */
    /* @4162696 call */
    GM_SITE(vm, 308, 4162696);
    /* @4162704 store */
    v36 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v36);
    /* @4162712 load */
    /* @4162720 constant */
    /* @4162724 cmp */
    /* @4162728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4162752;
    /* @4162732 load */
    /* @4162740 constant */
    /* @4162744 cmp */
    /* @4162748 b */
    p4162756_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4162756;
    L_4162752: ;
    /* @4162752 constant */
    p4162756_0 = VAL(0);
    L_4162756: ;
    /* @4162756 bf */
    if (!TRUTH(p4162756_0)) goto L_4162972;
    /* @4162760 constant */
    /* @4162764 load */
    /* @4162772 cast */
    /* @4162776 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4162784 constant */
    /* @4162788 cast */
    /* @4162792 load */
    /* @4162800 load */
    /* @4162808 load */
    /* @4162816 load */
    /* @4162824 call */
    GM_SITE(vm, 308, 4162824);
    /* @4162832 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4162836 load */
    /* @4162844 cast */
    /* @4162848 dup */
    /* @4162852 load */
    /* @4162860 constant */
    /* @4162864 sub */
    /* @4162868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - VAL(3)));
    /* @4162876 constant */
    /* @4162880 cast */
    /* @4162884 load */
    /* @4162892 load */
    /* @4162900 call */
    GM_SITE(vm, 308, 4162900);
    /* @4162908 store */
    v37 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v37);
    /* @4162916 constant */
    /* @4162920 load */
    /* @4162928 cast */
    /* @4162932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4162940 constant */
    /* @4162944 constant */
    /* @4162948 constant */
    /* @4162952 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4162960 constant */
    /* @4162964 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4162972: ;
    /* @4162972 constant */
    /* @4162976 cast */
    /* @4162980 load */
    /* @4162988 load */
    /* @4162996 call */
    GM_SITE(vm, 308, 4162996);
    /* @4163004 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v38);
    /* @4163012 load */
    /* @4163020 constant */
    /* @4163024 cmp */
    /* @4163028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4163052;
    /* @4163032 load */
    /* @4163040 constant */
    /* @4163044 cmp */
    /* @4163048 b */
    p4163056_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4163056;
    L_4163052: ;
    /* @4163052 constant */
    p4163056_0 = VAL(0);
    L_4163056: ;
    /* @4163056 bf */
    if (!TRUTH(p4163056_0)) goto L_4163272;
    /* @4163060 constant */
    /* @4163064 load */
    /* @4163072 cast */
    /* @4163076 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4163084 constant */
    /* @4163088 cast */
    /* @4163092 load */
    /* @4163100 load */
    /* @4163108 load */
    /* @4163116 load */
    /* @4163124 call */
    GM_SITE(vm, 308, 4163124);
    /* @4163132 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4163136 load */
    /* @4163144 cast */
    /* @4163148 dup */
    /* @4163152 load */
    /* @4163160 constant */
    /* @4163164 sub */
    /* @4163168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - VAL(3)));
    /* @4163176 constant */
    /* @4163180 cast */
    /* @4163184 load */
    /* @4163192 load */
    /* @4163200 call */
    GM_SITE(vm, 308, 4163200);
    /* @4163208 store */
    v39 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v39);
    /* @4163216 constant */
    /* @4163220 load */
    /* @4163228 cast */
    /* @4163232 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4163240 constant */
    /* @4163244 constant */
    /* @4163248 constant */
    /* @4163252 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4163260 constant */
    /* @4163264 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4163272: ;
    /* @4163272 constant */
    /* @4163276 cast */
    /* @4163280 load */
    /* @4163288 load */
    /* @4163296 call */
    GM_SITE(vm, 308, 4163296);
    /* @4163304 store */
    v40 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v40);
    /* @4163312 load */
    /* @4163320 constant */
    /* @4163324 cmp */
    /* @4163328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4163352;
    /* @4163332 load */
    /* @4163340 constant */
    /* @4163344 cmp */
    /* @4163348 b */
    p4163356_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4163356;
    L_4163352: ;
    /* @4163352 constant */
    p4163356_0 = VAL(0);
    L_4163356: ;
    /* @4163356 bf */
    if (!TRUTH(p4163356_0)) goto L_4163572;
    /* @4163360 constant */
    /* @4163364 load */
    /* @4163372 cast */
    /* @4163376 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4163384 constant */
    /* @4163388 cast */
    /* @4163392 load */
    /* @4163400 load */
    /* @4163408 load */
    /* @4163416 load */
    /* @4163424 call */
    GM_SITE(vm, 308, 4163424);
    /* @4163432 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4163436 load */
    /* @4163444 cast */
    /* @4163448 dup */
    /* @4163452 load */
    /* @4163460 constant */
    /* @4163464 sub */
    /* @4163468 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - VAL(3)));
    /* @4163476 constant */
    /* @4163480 cast */
    /* @4163484 load */
    /* @4163492 load */
    /* @4163500 call */
    GM_SITE(vm, 308, 4163500);
    /* @4163508 store */
    v41 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v41);
    /* @4163516 constant */
    /* @4163520 load */
    /* @4163528 cast */
    /* @4163532 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(3));
    /* @4163540 constant */
    /* @4163544 constant */
    /* @4163548 constant */
    /* @4163552 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4163560 constant */
    /* @4163564 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4163572: ;
    return;
}
