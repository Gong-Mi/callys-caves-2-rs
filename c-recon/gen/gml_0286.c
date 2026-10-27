/* generated from CODE 286 (gml_Object_obj_iceball_Step_0), source start 4107092, end 4113336. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0286(GmVM* vm) {
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
    /* @4107092 constant */
    /* @4107096 cast */
    /* @4107100 load */
    /* @4107108 load */
    /* @4107116 call */
    GM_SITE(vm, 286, 4107116);
    /* @4107124 cast */
    /* @4107128 bf */
    v1 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v1)) goto L_4107184;
    /* @4107132 constant */
    /* @4107136 cast */
    /* @4107140 load */
    /* @4107148 load */
    /* @4107156 call */
    GM_SITE(vm, 286, 4107156);
    /* @4107164 store */
    v2 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v2);
    /* @4107172 call */
    GM_SITE(vm, 286, 4107172);
    /* @4107180 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4107184: ;
    /* @4107184 load */
    /* @4107192 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4107200 constant */
    /* @4107204 cast */
    /* @4107208 load */
    /* @4107216 load */
    /* @4107224 call */
    GM_SITE(vm, 286, 4107224);
    /* @4107232 store */
    v3 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v3);
    /* @4107240 load */
    /* @4107248 constant */
    /* @4107252 cmp */
    /* @4107256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4107616;
    /* @4107260 constant */
    /* @4107264 load */
    /* @4107272 cast */
    /* @4107276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4107284 constant */
    /* @4107288 cast */
    /* @4107292 load */
    /* @4107300 load */
    /* @4107308 load */
    /* @4107316 load */
    /* @4107324 call */
    GM_SITE(vm, 286, 4107324);
    /* @4107332 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4107336 constant */
    /* @4107340 load */
    /* @4107348 cast */
    /* @4107352 constant */
    /* @4107356 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(3), VAL(45));
    /* @4107364 constant */
    /* @4107368 load */
    /* @4107376 cast */
    /* @4107380 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpfrozen", VAL(1));
    /* @4107388 load */
    /* @4107396 cast */
    /* @4107400 dup */
    /* @4107404 load */
    /* @4107412 load */
    /* @4107420 sub */
    /* @4107424 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "icegundamage")));
    /* @4107432 constant */
    /* @4107436 cast */
    /* @4107440 load */
    /* @4107448 load */
    /* @4107456 call */
    GM_SITE(vm, 286, 4107456);
    /* @4107464 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v4);
    /* @4107472 load */
    /* @4107480 load */
    /* @4107488 cast */
    /* @4107492 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4107500 load */
    /* @4107508 constant */
    /* @4107512 cmp */
    /* @4107516 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4107524;
    /* @4107520 b */
    goto L_4107580;
    L_4107524: ;
    /* @4107524 load */
    /* @4107532 constant */
    /* @4107536 cmp */
    /* @4107540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4107580;
    /* @4107544 constant */
    /* @4107548 cast */
    /* @4107552 constant */
    /* @4107556 cast */
    /* @4107560 constant */
    /* @4107564 cast */
    /* @4107568 call */
    GM_SITE(vm, 286, 4107568);
    /* @4107576 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4107580: ;
    /* @4107580 load */
    /* @4107588 constant */
    /* @4107592 add */
    /* @4107596 store */
    v5 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v5);
    /* @4107604 call */
    GM_SITE(vm, 286, 4107604);
    /* @4107612 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4107616: ;
    /* @4107616 constant */
    /* @4107620 cast */
    /* @4107624 load */
    /* @4107632 load */
    /* @4107640 call */
    GM_SITE(vm, 286, 4107640);
    /* @4107648 store */
    v6 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v6);
    /* @4107656 load */
    /* @4107664 constant */
    /* @4107668 cmp */
    /* @4107672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4108032;
    /* @4107676 constant */
    /* @4107680 load */
    /* @4107688 cast */
    /* @4107692 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4107700 constant */
    /* @4107704 cast */
    /* @4107708 load */
    /* @4107716 load */
    /* @4107724 load */
    /* @4107732 load */
    /* @4107740 call */
    GM_SITE(vm, 286, 4107740);
    /* @4107748 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4107752 constant */
    /* @4107756 load */
    /* @4107764 cast */
    /* @4107768 constant */
    /* @4107772 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(3), VAL(45));
    /* @4107780 constant */
    /* @4107784 load */
    /* @4107792 cast */
    /* @4107796 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolffrozen", VAL(1));
    /* @4107804 load */
    /* @4107812 cast */
    /* @4107816 dup */
    /* @4107820 load */
    /* @4107828 load */
    /* @4107836 sub */
    /* @4107840 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "icegundamage")));
    /* @4107848 constant */
    /* @4107852 cast */
    /* @4107856 load */
    /* @4107864 load */
    /* @4107872 call */
    GM_SITE(vm, 286, 4107872);
    /* @4107880 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v7);
    /* @4107888 load */
    /* @4107896 load */
    /* @4107904 cast */
    /* @4107908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4107916 load */
    /* @4107924 constant */
    /* @4107928 cmp */
    /* @4107932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4107940;
    /* @4107936 b */
    goto L_4107996;
    L_4107940: ;
    /* @4107940 load */
    /* @4107948 constant */
    /* @4107952 cmp */
    /* @4107956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4107996;
    /* @4107960 constant */
    /* @4107964 cast */
    /* @4107968 constant */
    /* @4107972 cast */
    /* @4107976 constant */
    /* @4107980 cast */
    /* @4107984 call */
    GM_SITE(vm, 286, 4107984);
    /* @4107992 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4107996: ;
    /* @4107996 load */
    /* @4108004 constant */
    /* @4108008 add */
    /* @4108012 store */
    v8 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v8);
    /* @4108020 call */
    GM_SITE(vm, 286, 4108020);
    /* @4108028 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4108032: ;
    /* @4108032 constant */
    /* @4108036 cast */
    /* @4108040 load */
    /* @4108048 load */
    /* @4108056 call */
    GM_SITE(vm, 286, 4108056);
    /* @4108064 store */
    v9 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v9);
    /* @4108072 load */
    /* @4108080 constant */
    /* @4108084 cmp */
    /* @4108088 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4108448;
    /* @4108092 constant */
    /* @4108096 load */
    /* @4108104 cast */
    /* @4108108 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4108116 constant */
    /* @4108120 cast */
    /* @4108124 load */
    /* @4108132 load */
    /* @4108140 load */
    /* @4108148 load */
    /* @4108156 call */
    GM_SITE(vm, 286, 4108156);
    /* @4108164 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4108168 constant */
    /* @4108172 load */
    /* @4108180 cast */
    /* @4108184 constant */
    /* @4108188 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(3), VAL(45));
    /* @4108196 constant */
    /* @4108200 load */
    /* @4108208 cast */
    /* @4108212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hpfrozen", VAL(1));
    /* @4108220 load */
    /* @4108228 cast */
    /* @4108232 dup */
    /* @4108236 load */
    /* @4108244 load */
    /* @4108252 sub */
    /* @4108256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "icegundamage")));
    /* @4108264 constant */
    /* @4108268 cast */
    /* @4108272 load */
    /* @4108280 load */
    /* @4108288 call */
    GM_SITE(vm, 286, 4108288);
    /* @4108296 store */
    v10 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v10);
    /* @4108304 load */
    /* @4108312 load */
    /* @4108320 cast */
    /* @4108324 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4108332 load */
    /* @4108340 constant */
    /* @4108344 cmp */
    /* @4108348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4108356;
    /* @4108352 b */
    goto L_4108412;
    L_4108356: ;
    /* @4108356 load */
    /* @4108364 constant */
    /* @4108368 cmp */
    /* @4108372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4108412;
    /* @4108376 constant */
    /* @4108380 cast */
    /* @4108384 constant */
    /* @4108388 cast */
    /* @4108392 constant */
    /* @4108396 cast */
    /* @4108400 call */
    GM_SITE(vm, 286, 4108400);
    /* @4108408 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4108412: ;
    /* @4108412 load */
    /* @4108420 constant */
    /* @4108424 add */
    /* @4108428 store */
    v11 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v11);
    /* @4108436 call */
    GM_SITE(vm, 286, 4108436);
    /* @4108444 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4108448: ;
    /* @4108448 constant */
    /* @4108452 cast */
    /* @4108456 load */
    /* @4108464 load */
    /* @4108472 call */
    GM_SITE(vm, 286, 4108472);
    /* @4108480 store */
    v12 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v12);
    /* @4108488 load */
    /* @4108496 constant */
    /* @4108500 cmp */
    /* @4108504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4108864;
    /* @4108508 constant */
    /* @4108512 load */
    /* @4108520 cast */
    /* @4108524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4108532 constant */
    /* @4108536 cast */
    /* @4108540 load */
    /* @4108548 load */
    /* @4108556 load */
    /* @4108564 load */
    /* @4108572 call */
    GM_SITE(vm, 286, 4108572);
    /* @4108580 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4108584 constant */
    /* @4108588 load */
    /* @4108596 cast */
    /* @4108600 constant */
    /* @4108604 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(3), VAL(45));
    /* @4108612 constant */
    /* @4108616 load */
    /* @4108624 cast */
    /* @4108628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwofrozen", VAL(1));
    /* @4108636 load */
    /* @4108644 cast */
    /* @4108648 dup */
    /* @4108652 load */
    /* @4108660 load */
    /* @4108668 sub */
    /* @4108672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "icegundamage")));
    /* @4108680 constant */
    /* @4108684 cast */
    /* @4108688 load */
    /* @4108696 load */
    /* @4108704 call */
    GM_SITE(vm, 286, 4108704);
    /* @4108712 store */
    v13 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v13);
    /* @4108720 load */
    /* @4108728 load */
    /* @4108736 cast */
    /* @4108740 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4108748 load */
    /* @4108756 constant */
    /* @4108760 cmp */
    /* @4108764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4108772;
    /* @4108768 b */
    goto L_4108828;
    L_4108772: ;
    /* @4108772 load */
    /* @4108780 constant */
    /* @4108784 cmp */
    /* @4108788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4108828;
    /* @4108792 constant */
    /* @4108796 cast */
    /* @4108800 constant */
    /* @4108804 cast */
    /* @4108808 constant */
    /* @4108812 cast */
    /* @4108816 call */
    GM_SITE(vm, 286, 4108816);
    /* @4108824 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4108828: ;
    /* @4108828 load */
    /* @4108836 constant */
    /* @4108840 add */
    /* @4108844 store */
    v14 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v14);
    /* @4108852 call */
    GM_SITE(vm, 286, 4108852);
    /* @4108860 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4108864: ;
    /* @4108864 constant */
    /* @4108868 cast */
    /* @4108872 load */
    /* @4108880 load */
    /* @4108888 call */
    GM_SITE(vm, 286, 4108888);
    /* @4108896 store */
    v15 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v15);
    /* @4108904 load */
    /* @4108912 constant */
    /* @4108916 cmp */
    /* @4108920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4109228;
    /* @4108924 constant */
    /* @4108928 load */
    /* @4108936 cast */
    /* @4108940 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4108948 constant */
    /* @4108952 cast */
    /* @4108956 load */
    /* @4108964 load */
    /* @4108972 load */
    /* @4108980 load */
    /* @4108988 call */
    GM_SITE(vm, 286, 4108988);
    /* @4108996 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4109000 load */
    /* @4109008 cast */
    /* @4109012 dup */
    /* @4109016 load */
    /* @4109024 load */
    /* @4109032 sub */
    /* @4109036 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "icegundamage")));
    /* @4109044 constant */
    /* @4109048 cast */
    /* @4109052 load */
    /* @4109060 load */
    /* @4109068 call */
    GM_SITE(vm, 286, 4109068);
    /* @4109076 store */
    v16 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v16);
    /* @4109084 load */
    /* @4109092 load */
    /* @4109100 cast */
    /* @4109104 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4109112 load */
    /* @4109120 constant */
    /* @4109124 cmp */
    /* @4109128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4109136;
    /* @4109132 b */
    goto L_4109192;
    L_4109136: ;
    /* @4109136 load */
    /* @4109144 constant */
    /* @4109148 cmp */
    /* @4109152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4109192;
    /* @4109156 constant */
    /* @4109160 cast */
    /* @4109164 constant */
    /* @4109168 cast */
    /* @4109172 constant */
    /* @4109176 cast */
    /* @4109180 call */
    GM_SITE(vm, 286, 4109180);
    /* @4109188 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4109192: ;
    /* @4109192 load */
    /* @4109200 constant */
    /* @4109204 add */
    /* @4109208 store */
    v17 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v17);
    /* @4109216 call */
    GM_SITE(vm, 286, 4109216);
    /* @4109224 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4109228: ;
    /* @4109228 constant */
    /* @4109232 cast */
    /* @4109236 load */
    /* @4109244 load */
    /* @4109252 call */
    GM_SITE(vm, 286, 4109252);
    /* @4109260 store */
    v18 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v18);
    /* @4109268 load */
    /* @4109276 constant */
    /* @4109280 cmp */
    /* @4109284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4109644;
    /* @4109288 constant */
    /* @4109292 load */
    /* @4109300 cast */
    /* @4109304 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4109312 constant */
    /* @4109316 cast */
    /* @4109320 load */
    /* @4109328 load */
    /* @4109336 load */
    /* @4109344 load */
    /* @4109352 call */
    GM_SITE(vm, 286, 4109352);
    /* @4109360 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4109364 constant */
    /* @4109368 load */
    /* @4109376 cast */
    /* @4109380 constant */
    /* @4109384 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(3), VAL(90));
    /* @4109392 constant */
    /* @4109396 load */
    /* @4109404 cast */
    /* @4109408 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfourfrozen", VAL(1));
    /* @4109416 load */
    /* @4109424 cast */
    /* @4109428 dup */
    /* @4109432 load */
    /* @4109440 load */
    /* @4109448 sub */
    /* @4109452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "icegundamage")));
    /* @4109460 constant */
    /* @4109464 cast */
    /* @4109468 load */
    /* @4109476 load */
    /* @4109484 call */
    GM_SITE(vm, 286, 4109484);
    /* @4109492 store */
    v19 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v19);
    /* @4109500 load */
    /* @4109508 load */
    /* @4109516 cast */
    /* @4109520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4109528 load */
    /* @4109536 constant */
    /* @4109540 cmp */
    /* @4109544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4109552;
    /* @4109548 b */
    goto L_4109608;
    L_4109552: ;
    /* @4109552 load */
    /* @4109560 constant */
    /* @4109564 cmp */
    /* @4109568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4109608;
    /* @4109572 constant */
    /* @4109576 cast */
    /* @4109580 constant */
    /* @4109584 cast */
    /* @4109588 constant */
    /* @4109592 cast */
    /* @4109596 call */
    GM_SITE(vm, 286, 4109596);
    /* @4109604 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4109608: ;
    /* @4109608 load */
    /* @4109616 constant */
    /* @4109620 add */
    /* @4109624 store */
    v20 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v20);
    /* @4109632 call */
    GM_SITE(vm, 286, 4109632);
    /* @4109640 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4109644: ;
    /* @4109644 constant */
    /* @4109648 cast */
    /* @4109652 load */
    /* @4109660 load */
    /* @4109668 call */
    GM_SITE(vm, 286, 4109668);
    /* @4109676 store */
    v21 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v21);
    /* @4109684 load */
    /* @4109692 constant */
    /* @4109696 cmp */
    /* @4109700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4110060;
    /* @4109704 constant */
    /* @4109708 load */
    /* @4109716 cast */
    /* @4109720 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4109728 constant */
    /* @4109732 cast */
    /* @4109736 load */
    /* @4109744 load */
    /* @4109752 load */
    /* @4109760 load */
    /* @4109768 call */
    GM_SITE(vm, 286, 4109768);
    /* @4109776 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4109780 constant */
    /* @4109784 load */
    /* @4109792 cast */
    /* @4109796 constant */
    /* @4109800 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(3), VAL(45));
    /* @4109808 constant */
    /* @4109812 load */
    /* @4109820 cast */
    /* @4109824 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslimefrozen", VAL(1));
    /* @4109832 load */
    /* @4109840 cast */
    /* @4109844 dup */
    /* @4109848 load */
    /* @4109856 load */
    /* @4109864 sub */
    /* @4109868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "icegundamage")));
    /* @4109876 constant */
    /* @4109880 cast */
    /* @4109884 load */
    /* @4109892 load */
    /* @4109900 call */
    GM_SITE(vm, 286, 4109900);
    /* @4109908 store */
    v22 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v22);
    /* @4109916 load */
    /* @4109924 load */
    /* @4109932 cast */
    /* @4109936 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4109944 load */
    /* @4109952 constant */
    /* @4109956 cmp */
    /* @4109960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4109968;
    /* @4109964 b */
    goto L_4110024;
    L_4109968: ;
    /* @4109968 load */
    /* @4109976 constant */
    /* @4109980 cmp */
    /* @4109984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4110024;
    /* @4109988 constant */
    /* @4109992 cast */
    /* @4109996 constant */
    /* @4110000 cast */
    /* @4110004 constant */
    /* @4110008 cast */
    /* @4110012 call */
    GM_SITE(vm, 286, 4110012);
    /* @4110020 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4110024: ;
    /* @4110024 load */
    /* @4110032 constant */
    /* @4110036 add */
    /* @4110040 store */
    v23 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v23);
    /* @4110048 call */
    GM_SITE(vm, 286, 4110048);
    /* @4110056 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4110060: ;
    /* @4110060 constant */
    /* @4110064 cast */
    /* @4110068 load */
    /* @4110076 load */
    /* @4110084 call */
    GM_SITE(vm, 286, 4110084);
    /* @4110092 store */
    v24 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v24);
    /* @4110100 load */
    /* @4110108 constant */
    /* @4110112 cmp */
    /* @4110116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4110476;
    /* @4110120 constant */
    /* @4110124 load */
    /* @4110132 cast */
    /* @4110136 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4110144 constant */
    /* @4110148 cast */
    /* @4110152 load */
    /* @4110160 load */
    /* @4110168 load */
    /* @4110176 load */
    /* @4110184 call */
    GM_SITE(vm, 286, 4110184);
    /* @4110192 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4110196 constant */
    /* @4110200 load */
    /* @4110208 cast */
    /* @4110212 constant */
    /* @4110216 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(3), VAL(45));
    /* @4110224 constant */
    /* @4110228 load */
    /* @4110236 cast */
    /* @4110240 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghostfrozen", VAL(1));
    /* @4110248 load */
    /* @4110256 cast */
    /* @4110260 dup */
    /* @4110264 load */
    /* @4110272 load */
    /* @4110280 sub */
    /* @4110284 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "icegundamage")));
    /* @4110292 constant */
    /* @4110296 cast */
    /* @4110300 load */
    /* @4110308 load */
    /* @4110316 call */
    GM_SITE(vm, 286, 4110316);
    /* @4110324 store */
    v25 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v25);
    /* @4110332 load */
    /* @4110340 load */
    /* @4110348 cast */
    /* @4110352 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4110360 load */
    /* @4110368 constant */
    /* @4110372 cmp */
    /* @4110376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4110384;
    /* @4110380 b */
    goto L_4110440;
    L_4110384: ;
    /* @4110384 load */
    /* @4110392 constant */
    /* @4110396 cmp */
    /* @4110400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4110440;
    /* @4110404 constant */
    /* @4110408 cast */
    /* @4110412 constant */
    /* @4110416 cast */
    /* @4110420 constant */
    /* @4110424 cast */
    /* @4110428 call */
    GM_SITE(vm, 286, 4110428);
    /* @4110436 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4110440: ;
    /* @4110440 load */
    /* @4110448 constant */
    /* @4110452 add */
    /* @4110456 store */
    v26 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v26);
    /* @4110464 call */
    GM_SITE(vm, 286, 4110464);
    /* @4110472 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4110476: ;
    /* @4110476 constant */
    /* @4110480 cast */
    /* @4110484 load */
    /* @4110492 load */
    /* @4110500 call */
    GM_SITE(vm, 286, 4110500);
    /* @4110508 store */
    v27 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v27);
    /* @4110516 load */
    /* @4110524 constant */
    /* @4110528 cmp */
    /* @4110532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4110892;
    /* @4110536 constant */
    /* @4110540 load */
    /* @4110548 cast */
    /* @4110552 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4110560 constant */
    /* @4110564 cast */
    /* @4110568 load */
    /* @4110576 load */
    /* @4110584 load */
    /* @4110592 load */
    /* @4110600 call */
    GM_SITE(vm, 286, 4110600);
    /* @4110608 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4110612 constant */
    /* @4110616 load */
    /* @4110624 cast */
    /* @4110628 constant */
    /* @4110632 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(3), VAL(45));
    /* @4110640 constant */
    /* @4110644 load */
    /* @4110652 cast */
    /* @4110656 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1frozen", VAL(1));
    /* @4110664 load */
    /* @4110672 cast */
    /* @4110676 dup */
    /* @4110680 load */
    /* @4110688 load */
    /* @4110696 sub */
    /* @4110700 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "icegundamage")));
    /* @4110708 constant */
    /* @4110712 cast */
    /* @4110716 load */
    /* @4110724 load */
    /* @4110732 call */
    GM_SITE(vm, 286, 4110732);
    /* @4110740 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v28);
    /* @4110748 load */
    /* @4110756 load */
    /* @4110764 cast */
    /* @4110768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4110776 load */
    /* @4110784 constant */
    /* @4110788 cmp */
    /* @4110792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4110800;
    /* @4110796 b */
    goto L_4110856;
    L_4110800: ;
    /* @4110800 load */
    /* @4110808 constant */
    /* @4110812 cmp */
    /* @4110816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4110856;
    /* @4110820 constant */
    /* @4110824 cast */
    /* @4110828 constant */
    /* @4110832 cast */
    /* @4110836 constant */
    /* @4110840 cast */
    /* @4110844 call */
    GM_SITE(vm, 286, 4110844);
    /* @4110852 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4110856: ;
    /* @4110856 load */
    /* @4110864 constant */
    /* @4110868 add */
    /* @4110872 store */
    v29 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v29);
    /* @4110880 call */
    GM_SITE(vm, 286, 4110880);
    /* @4110888 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4110892: ;
    /* @4110892 constant */
    /* @4110896 cast */
    /* @4110900 load */
    /* @4110908 load */
    /* @4110916 call */
    GM_SITE(vm, 286, 4110916);
    /* @4110924 store */
    v30 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v30);
    /* @4110932 load */
    /* @4110940 constant */
    /* @4110944 cmp */
    /* @4110948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4111308;
    /* @4110952 constant */
    /* @4110956 load */
    /* @4110964 cast */
    /* @4110968 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4110976 constant */
    /* @4110980 cast */
    /* @4110984 load */
    /* @4110992 load */
    /* @4111000 load */
    /* @4111008 load */
    /* @4111016 call */
    GM_SITE(vm, 286, 4111016);
    /* @4111024 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4111028 constant */
    /* @4111032 load */
    /* @4111040 cast */
    /* @4111044 constant */
    /* @4111048 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(3), VAL(45));
    /* @4111056 constant */
    /* @4111060 load */
    /* @4111068 cast */
    /* @4111072 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2frozen", VAL(1));
    /* @4111080 load */
    /* @4111088 cast */
    /* @4111092 dup */
    /* @4111096 load */
    /* @4111104 load */
    /* @4111112 sub */
    /* @4111116 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "icegundamage")));
    /* @4111124 constant */
    /* @4111128 cast */
    /* @4111132 load */
    /* @4111140 load */
    /* @4111148 call */
    GM_SITE(vm, 286, 4111148);
    /* @4111156 store */
    v31 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v31);
    /* @4111164 load */
    /* @4111172 load */
    /* @4111180 cast */
    /* @4111184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4111192 load */
    /* @4111200 constant */
    /* @4111204 cmp */
    /* @4111208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4111216;
    /* @4111212 b */
    goto L_4111272;
    L_4111216: ;
    /* @4111216 load */
    /* @4111224 constant */
    /* @4111228 cmp */
    /* @4111232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4111272;
    /* @4111236 constant */
    /* @4111240 cast */
    /* @4111244 constant */
    /* @4111248 cast */
    /* @4111252 constant */
    /* @4111256 cast */
    /* @4111260 call */
    GM_SITE(vm, 286, 4111260);
    /* @4111268 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4111272: ;
    /* @4111272 load */
    /* @4111280 constant */
    /* @4111284 add */
    /* @4111288 store */
    v32 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v32);
    /* @4111296 call */
    GM_SITE(vm, 286, 4111296);
    /* @4111304 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4111308: ;
    /* @4111308 constant */
    /* @4111312 cast */
    /* @4111316 load */
    /* @4111324 load */
    /* @4111332 call */
    GM_SITE(vm, 286, 4111332);
    /* @4111340 store */
    v33 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v33);
    /* @4111348 load */
    /* @4111356 constant */
    /* @4111360 cmp */
    /* @4111364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4111724;
    /* @4111368 constant */
    /* @4111372 load */
    /* @4111380 cast */
    /* @4111384 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4111392 constant */
    /* @4111396 cast */
    /* @4111400 load */
    /* @4111408 load */
    /* @4111416 load */
    /* @4111424 load */
    /* @4111432 call */
    GM_SITE(vm, 286, 4111432);
    /* @4111440 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4111444 constant */
    /* @4111448 load */
    /* @4111456 cast */
    /* @4111460 constant */
    /* @4111464 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(3), VAL(45));
    /* @4111472 constant */
    /* @4111476 load */
    /* @4111484 cast */
    /* @4111488 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslimefrozen", VAL(1));
    /* @4111496 load */
    /* @4111504 cast */
    /* @4111508 dup */
    /* @4111512 load */
    /* @4111520 load */
    /* @4111528 sub */
    /* @4111532 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "icegundamage")));
    /* @4111540 constant */
    /* @4111544 cast */
    /* @4111548 load */
    /* @4111556 load */
    /* @4111564 call */
    GM_SITE(vm, 286, 4111564);
    /* @4111572 store */
    v34 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v34);
    /* @4111580 load */
    /* @4111588 load */
    /* @4111596 cast */
    /* @4111600 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4111608 load */
    /* @4111616 constant */
    /* @4111620 cmp */
    /* @4111624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4111632;
    /* @4111628 b */
    goto L_4111688;
    L_4111632: ;
    /* @4111632 load */
    /* @4111640 constant */
    /* @4111644 cmp */
    /* @4111648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4111688;
    /* @4111652 constant */
    /* @4111656 cast */
    /* @4111660 constant */
    /* @4111664 cast */
    /* @4111668 constant */
    /* @4111672 cast */
    /* @4111676 call */
    GM_SITE(vm, 286, 4111676);
    /* @4111684 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4111688: ;
    /* @4111688 load */
    /* @4111696 constant */
    /* @4111700 add */
    /* @4111704 store */
    v35 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v35);
    /* @4111712 call */
    GM_SITE(vm, 286, 4111712);
    /* @4111720 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4111724: ;
    /* @4111724 constant */
    /* @4111728 cast */
    /* @4111732 load */
    /* @4111740 load */
    /* @4111748 call */
    GM_SITE(vm, 286, 4111748);
    /* @4111756 store */
    v36 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v36);
    /* @4111764 load */
    /* @4111772 constant */
    /* @4111776 cmp */
    /* @4111780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4112140;
    /* @4111784 constant */
    /* @4111788 load */
    /* @4111796 cast */
    /* @4111800 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4111808 constant */
    /* @4111812 cast */
    /* @4111816 load */
    /* @4111824 load */
    /* @4111832 load */
    /* @4111840 load */
    /* @4111848 call */
    GM_SITE(vm, 286, 4111848);
    /* @4111856 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4111860 constant */
    /* @4111864 load */
    /* @4111872 cast */
    /* @4111876 constant */
    /* @4111880 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(3), VAL(45));
    /* @4111888 constant */
    /* @4111892 load */
    /* @4111900 cast */
    /* @4111904 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbanditfrozen", VAL(1));
    /* @4111912 load */
    /* @4111920 cast */
    /* @4111924 dup */
    /* @4111928 load */
    /* @4111936 load */
    /* @4111944 sub */
    /* @4111948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "icegundamage")));
    /* @4111956 constant */
    /* @4111960 cast */
    /* @4111964 load */
    /* @4111972 load */
    /* @4111980 call */
    GM_SITE(vm, 286, 4111980);
    /* @4111988 store */
    v37 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v37);
    /* @4111996 load */
    /* @4112004 load */
    /* @4112012 cast */
    /* @4112016 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4112024 load */
    /* @4112032 constant */
    /* @4112036 cmp */
    /* @4112040 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4112048;
    /* @4112044 b */
    goto L_4112104;
    L_4112048: ;
    /* @4112048 load */
    /* @4112056 constant */
    /* @4112060 cmp */
    /* @4112064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4112104;
    /* @4112068 constant */
    /* @4112072 cast */
    /* @4112076 constant */
    /* @4112080 cast */
    /* @4112084 constant */
    /* @4112088 cast */
    /* @4112092 call */
    GM_SITE(vm, 286, 4112092);
    /* @4112100 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4112104: ;
    /* @4112104 load */
    /* @4112112 constant */
    /* @4112116 add */
    /* @4112120 store */
    v38 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v38);
    /* @4112128 call */
    GM_SITE(vm, 286, 4112128);
    /* @4112136 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4112140: ;
    /* @4112140 constant */
    /* @4112144 cast */
    /* @4112148 load */
    /* @4112156 load */
    /* @4112164 call */
    GM_SITE(vm, 286, 4112164);
    /* @4112172 store */
    v39 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v39);
    /* @4112180 load */
    /* @4112188 constant */
    /* @4112192 cmp */
    /* @4112196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4112556;
    /* @4112200 constant */
    /* @4112204 load */
    /* @4112212 cast */
    /* @4112216 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4112224 constant */
    /* @4112228 cast */
    /* @4112232 load */
    /* @4112240 load */
    /* @4112248 load */
    /* @4112256 load */
    /* @4112264 call */
    GM_SITE(vm, 286, 4112264);
    /* @4112272 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4112276 constant */
    /* @4112280 load */
    /* @4112288 cast */
    /* @4112292 constant */
    /* @4112296 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(3), VAL(45));
    /* @4112304 constant */
    /* @4112308 load */
    /* @4112316 cast */
    /* @4112320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombiefrozen", VAL(1));
    /* @4112328 load */
    /* @4112336 cast */
    /* @4112340 dup */
    /* @4112344 load */
    /* @4112352 load */
    /* @4112360 sub */
    /* @4112364 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "icegundamage")));
    /* @4112372 constant */
    /* @4112376 cast */
    /* @4112380 load */
    /* @4112388 load */
    /* @4112396 call */
    GM_SITE(vm, 286, 4112396);
    /* @4112404 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v40);
    /* @4112412 load */
    /* @4112420 load */
    /* @4112428 cast */
    /* @4112432 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4112440 load */
    /* @4112448 constant */
    /* @4112452 cmp */
    /* @4112456 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4112464;
    /* @4112460 b */
    goto L_4112520;
    L_4112464: ;
    /* @4112464 load */
    /* @4112472 constant */
    /* @4112476 cmp */
    /* @4112480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4112520;
    /* @4112484 constant */
    /* @4112488 cast */
    /* @4112492 constant */
    /* @4112496 cast */
    /* @4112500 constant */
    /* @4112504 cast */
    /* @4112508 call */
    GM_SITE(vm, 286, 4112508);
    /* @4112516 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4112520: ;
    /* @4112520 load */
    /* @4112528 constant */
    /* @4112532 add */
    /* @4112536 store */
    v41 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v41);
    /* @4112544 call */
    GM_SITE(vm, 286, 4112544);
    /* @4112552 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4112556: ;
    /* @4112556 constant */
    /* @4112560 cast */
    /* @4112564 load */
    /* @4112572 load */
    /* @4112580 call */
    GM_SITE(vm, 286, 4112580);
    /* @4112588 store */
    v42 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v42);
    /* @4112596 load */
    /* @4112604 constant */
    /* @4112608 cmp */
    /* @4112612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4112972;
    /* @4112616 constant */
    /* @4112620 load */
    /* @4112628 cast */
    /* @4112632 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4112640 constant */
    /* @4112644 cast */
    /* @4112648 load */
    /* @4112656 load */
    /* @4112664 load */
    /* @4112672 load */
    /* @4112680 call */
    GM_SITE(vm, 286, 4112680);
    /* @4112688 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4112692 constant */
    /* @4112696 load */
    /* @4112704 cast */
    /* @4112708 constant */
    /* @4112712 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(3), VAL(45));
    /* @4112720 constant */
    /* @4112724 load */
    /* @4112732 cast */
    /* @4112736 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulkfrozen", VAL(1));
    /* @4112744 load */
    /* @4112752 cast */
    /* @4112756 dup */
    /* @4112760 load */
    /* @4112768 load */
    /* @4112776 sub */
    /* @4112780 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "icegundamage")));
    /* @4112788 constant */
    /* @4112792 cast */
    /* @4112796 load */
    /* @4112804 load */
    /* @4112812 call */
    GM_SITE(vm, 286, 4112812);
    /* @4112820 store */
    v43 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v43);
    /* @4112828 load */
    /* @4112836 load */
    /* @4112844 cast */
    /* @4112848 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4112856 load */
    /* @4112864 constant */
    /* @4112868 cmp */
    /* @4112872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4112880;
    /* @4112876 b */
    goto L_4112936;
    L_4112880: ;
    /* @4112880 load */
    /* @4112888 constant */
    /* @4112892 cmp */
    /* @4112896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4112936;
    /* @4112900 constant */
    /* @4112904 cast */
    /* @4112908 constant */
    /* @4112912 cast */
    /* @4112916 constant */
    /* @4112920 cast */
    /* @4112924 call */
    GM_SITE(vm, 286, 4112924);
    /* @4112932 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4112936: ;
    /* @4112936 load */
    /* @4112944 constant */
    /* @4112948 add */
    /* @4112952 store */
    v44 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v44);
    /* @4112960 call */
    GM_SITE(vm, 286, 4112960);
    /* @4112968 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4112972: ;
    /* @4112972 constant */
    /* @4112976 cast */
    /* @4112980 load */
    /* @4112988 load */
    /* @4112996 call */
    GM_SITE(vm, 286, 4112996);
    /* @4113004 store */
    v45 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v45);
    /* @4113012 load */
    /* @4113020 constant */
    /* @4113024 cmp */
    /* @4113028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4113336;
    /* @4113032 constant */
    /* @4113036 load */
    /* @4113044 cast */
    /* @4113048 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4113056 constant */
    /* @4113060 cast */
    /* @4113064 load */
    /* @4113072 load */
    /* @4113080 load */
    /* @4113088 load */
    /* @4113096 call */
    GM_SITE(vm, 286, 4113096);
    /* @4113104 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4113108 load */
    /* @4113116 cast */
    /* @4113120 dup */
    /* @4113124 load */
    /* @4113132 load */
    /* @4113140 sub */
    /* @4113144 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "icegundamage")));
    /* @4113152 constant */
    /* @4113156 cast */
    /* @4113160 load */
    /* @4113168 load */
    /* @4113176 call */
    GM_SITE(vm, 286, 4113176);
    /* @4113184 store */
    v46 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v46);
    /* @4113192 load */
    /* @4113200 load */
    /* @4113208 cast */
    /* @4113212 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "icegundamage"));
    /* @4113220 load */
    /* @4113228 constant */
    /* @4113232 cmp */
    /* @4113236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4113244;
    /* @4113240 b */
    goto L_4113300;
    L_4113244: ;
    /* @4113244 load */
    /* @4113252 constant */
    /* @4113256 cmp */
    /* @4113260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4113300;
    /* @4113264 constant */
    /* @4113268 cast */
    /* @4113272 constant */
    /* @4113276 cast */
    /* @4113280 constant */
    /* @4113284 cast */
    /* @4113288 call */
    GM_SITE(vm, 286, 4113288);
    /* @4113296 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4113300: ;
    /* @4113300 load */
    /* @4113308 constant */
    /* @4113312 add */
    /* @4113316 store */
    v47 = GM_ADD(GM_READ(vm, -5, "icegunxp"), VAL(1));
    GM_WRITE(vm, -5, "icegunxp", v47);
    /* @4113324 call */
    GM_SITE(vm, 286, 4113324);
    /* @4113332 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4113336: ;
    return;
}
