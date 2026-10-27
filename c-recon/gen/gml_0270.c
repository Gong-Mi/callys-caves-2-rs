/* generated from CODE 270 (gml_Object_obj_flame_Step_0), source start 4055980, end 4064472. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0270(GmVM* vm) {
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
    Val v61;
    Val v62;
    Val v63;
    Val v64;
    Val v65;
    Val v66;
    Val v67;
    Val v68;
    Val v69;
    Val v70;
    Val v71;
    Val v72;
    Val v73;
    Val v74;
    Val v75;
    Val v76;
    Val v77;
    Val v78;
    Val v79;
    Val v80;
    Val v81;
    Val v82;
    /* @4055980 load */
    /* @4055988 constant */
    /* @4055992 cmp */
    /* @4055996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4056024;
    /* @4056000 constant */
    /* @4056004 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4056012 constant */
    /* @4056016 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4056024: ;
    /* @4056024 load */
    /* @4056032 constant */
    /* @4056044 add */
    /* @4056048 store */
    v1 = GM_ADD(GM_READ(vm, -1, "image_xscale"), VAL(0.1));
    GM_WRITE(vm, -1, "image_xscale", v1);
    /* @4056056 load */
    /* @4056064 constant */
    /* @4056076 add */
    /* @4056080 store */
    v2 = GM_ADD(GM_READ(vm, -1, "image_yscale"), VAL(0.1));
    GM_WRITE(vm, -1, "image_yscale", v2);
    /* @4056088 load */
    /* @4056096 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4056104 constant */
    /* @4056108 cast */
    /* @4056112 load */
    /* @4056120 load */
    /* @4056128 call */
    GM_SITE(vm, 270, 4056128);
    /* @4056136 store */
    v3 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v3);
    /* @4056144 load */
    /* @4056152 constant */
    /* @4056156 cmp */
    /* @4056160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4056532;
    /* @4056164 constant */
    /* @4056168 load */
    /* @4056176 cast */
    /* @4056180 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4056188 constant */
    /* @4056192 cast */
    /* @4056196 load */
    /* @4056204 load */
    /* @4056212 load */
    /* @4056220 load */
    /* @4056228 call */
    GM_SITE(vm, 270, 4056228);
    /* @4056236 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4056240 load */
    /* @4056248 cast */
    /* @4056252 dup */
    /* @4056256 load */
    /* @4056264 load */
    /* @4056272 sub */
    /* @4056276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4056284 constant */
    /* @4056288 cast */
    /* @4056292 load */
    /* @4056300 load */
    /* @4056308 call */
    GM_SITE(vm, 270, 4056308);
    /* @4056316 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v4);
    /* @4056324 load */
    /* @4056332 load */
    /* @4056340 cast */
    /* @4056344 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4056352 load */
    /* @4056360 constant */
    /* @4056364 cmp */
    /* @4056368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4056376;
    /* @4056372 b */
    goto L_4056460;
    L_4056376: ;
    /* @4056376 load */
    /* @4056384 constant */
    /* @4056388 cmp */
    /* @4056392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4056460;
    /* @4056396 constant */
    /* @4056400 cast */
    /* @4056404 call */
    GM_SITE(vm, 270, 4056404);
    /* @4056412 cast */
    /* @4056416 not */
    /* @4056420 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v5)) goto L_4056460;
    /* @4056424 constant */
    /* @4056428 cast */
    /* @4056432 constant */
    /* @4056436 cast */
    /* @4056440 constant */
    /* @4056444 cast */
    /* @4056448 call */
    GM_SITE(vm, 270, 4056448);
    /* @4056456 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4056460: ;
    /* @4056460 load */
    /* @4056468 constant */
    /* @4056472 add */
    /* @4056476 store */
    v6 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v6);
    /* @4056484 load */
    /* @4056492 constant */
    /* @4056496 cmp */
    /* @4056500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4056532;
    /* @4056504 constant */
    /* @4056508 load */
    /* @4056516 cast */
    /* @4056520 constant */
    /* @4056524 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4056532: ;
    /* @4056532 constant */
    /* @4056536 cast */
    /* @4056540 load */
    /* @4056548 load */
    /* @4056556 call */
    GM_SITE(vm, 270, 4056556);
    /* @4056564 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v7);
    /* @4056572 load */
    /* @4056580 constant */
    /* @4056584 cmp */
    /* @4056588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4056960;
    /* @4056592 constant */
    /* @4056596 load */
    /* @4056604 cast */
    /* @4056608 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4056616 constant */
    /* @4056620 cast */
    /* @4056624 load */
    /* @4056632 load */
    /* @4056640 load */
    /* @4056648 load */
    /* @4056656 call */
    GM_SITE(vm, 270, 4056656);
    /* @4056664 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4056668 load */
    /* @4056676 cast */
    /* @4056680 dup */
    /* @4056684 load */
    /* @4056692 load */
    /* @4056700 sub */
    /* @4056704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4056712 constant */
    /* @4056716 cast */
    /* @4056720 load */
    /* @4056728 load */
    /* @4056736 call */
    GM_SITE(vm, 270, 4056736);
    /* @4056744 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4056752 load */
    /* @4056760 load */
    /* @4056768 cast */
    /* @4056772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4056780 load */
    /* @4056788 constant */
    /* @4056792 cmp */
    /* @4056796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4056804;
    /* @4056800 b */
    goto L_4056888;
    L_4056804: ;
    /* @4056804 load */
    /* @4056812 constant */
    /* @4056816 cmp */
    /* @4056820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4056888;
    /* @4056824 constant */
    /* @4056828 cast */
    /* @4056832 call */
    GM_SITE(vm, 270, 4056832);
    /* @4056840 cast */
    /* @4056844 not */
    /* @4056848 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v9)) goto L_4056888;
    /* @4056852 constant */
    /* @4056856 cast */
    /* @4056860 constant */
    /* @4056864 cast */
    /* @4056868 constant */
    /* @4056872 cast */
    /* @4056876 call */
    GM_SITE(vm, 270, 4056876);
    /* @4056884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4056888: ;
    /* @4056888 load */
    /* @4056896 constant */
    /* @4056900 add */
    /* @4056904 store */
    v10 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v10);
    /* @4056912 load */
    /* @4056920 constant */
    /* @4056924 cmp */
    /* @4056928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4056960;
    /* @4056932 constant */
    /* @4056936 load */
    /* @4056944 cast */
    /* @4056948 constant */
    /* @4056952 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4056960: ;
    /* @4056960 constant */
    /* @4056964 cast */
    /* @4056968 load */
    /* @4056976 load */
    /* @4056984 call */
    GM_SITE(vm, 270, 4056984);
    /* @4056992 store */
    v11 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v11);
    /* @4057000 load */
    /* @4057008 constant */
    /* @4057012 cmp */
    /* @4057016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4057388;
    /* @4057020 constant */
    /* @4057024 load */
    /* @4057032 cast */
    /* @4057036 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4057044 constant */
    /* @4057048 cast */
    /* @4057052 load */
    /* @4057060 load */
    /* @4057068 load */
    /* @4057076 load */
    /* @4057084 call */
    GM_SITE(vm, 270, 4057084);
    /* @4057092 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4057096 load */
    /* @4057104 cast */
    /* @4057108 dup */
    /* @4057112 load */
    /* @4057120 load */
    /* @4057128 sub */
    /* @4057132 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4057140 constant */
    /* @4057144 cast */
    /* @4057148 load */
    /* @4057156 load */
    /* @4057164 call */
    GM_SITE(vm, 270, 4057164);
    /* @4057172 store */
    v12 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v12);
    /* @4057180 load */
    /* @4057188 load */
    /* @4057196 cast */
    /* @4057200 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4057208 load */
    /* @4057216 constant */
    /* @4057220 cmp */
    /* @4057224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4057232;
    /* @4057228 b */
    goto L_4057316;
    L_4057232: ;
    /* @4057232 load */
    /* @4057240 constant */
    /* @4057244 cmp */
    /* @4057248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4057316;
    /* @4057252 constant */
    /* @4057256 cast */
    /* @4057260 call */
    GM_SITE(vm, 270, 4057260);
    /* @4057268 cast */
    /* @4057272 not */
    /* @4057276 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v13)) goto L_4057316;
    /* @4057280 constant */
    /* @4057284 cast */
    /* @4057288 constant */
    /* @4057292 cast */
    /* @4057296 constant */
    /* @4057300 cast */
    /* @4057304 call */
    GM_SITE(vm, 270, 4057304);
    /* @4057312 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4057316: ;
    /* @4057316 load */
    /* @4057324 constant */
    /* @4057328 add */
    /* @4057332 store */
    v14 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v14);
    /* @4057340 load */
    /* @4057348 constant */
    /* @4057352 cmp */
    /* @4057356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4057388;
    /* @4057360 constant */
    /* @4057364 load */
    /* @4057372 cast */
    /* @4057376 constant */
    /* @4057380 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4057388: ;
    /* @4057388 constant */
    /* @4057392 cast */
    /* @4057396 load */
    /* @4057404 load */
    /* @4057412 call */
    GM_SITE(vm, 270, 4057412);
    /* @4057420 store */
    v15 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v15);
    /* @4057428 load */
    /* @4057436 constant */
    /* @4057440 cmp */
    /* @4057444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4057816;
    /* @4057448 constant */
    /* @4057452 load */
    /* @4057460 cast */
    /* @4057464 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4057472 constant */
    /* @4057476 cast */
    /* @4057480 load */
    /* @4057488 load */
    /* @4057496 load */
    /* @4057504 load */
    /* @4057512 call */
    GM_SITE(vm, 270, 4057512);
    /* @4057520 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4057524 load */
    /* @4057532 cast */
    /* @4057536 dup */
    /* @4057540 load */
    /* @4057548 load */
    /* @4057556 sub */
    /* @4057560 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4057568 constant */
    /* @4057572 cast */
    /* @4057576 load */
    /* @4057584 load */
    /* @4057592 call */
    GM_SITE(vm, 270, 4057592);
    /* @4057600 store */
    v16 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v16);
    /* @4057608 load */
    /* @4057616 load */
    /* @4057624 cast */
    /* @4057628 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4057636 load */
    /* @4057644 constant */
    /* @4057648 cmp */
    /* @4057652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4057660;
    /* @4057656 b */
    goto L_4057744;
    L_4057660: ;
    /* @4057660 load */
    /* @4057668 constant */
    /* @4057672 cmp */
    /* @4057676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4057744;
    /* @4057680 constant */
    /* @4057684 cast */
    /* @4057688 call */
    GM_SITE(vm, 270, 4057688);
    /* @4057696 cast */
    /* @4057700 not */
    /* @4057704 bf */
    v17 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v17)) goto L_4057744;
    /* @4057708 constant */
    /* @4057712 cast */
    /* @4057716 constant */
    /* @4057720 cast */
    /* @4057724 constant */
    /* @4057728 cast */
    /* @4057732 call */
    GM_SITE(vm, 270, 4057732);
    /* @4057740 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4057744: ;
    /* @4057744 load */
    /* @4057752 constant */
    /* @4057756 add */
    /* @4057760 store */
    v18 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v18);
    /* @4057768 load */
    /* @4057776 constant */
    /* @4057780 cmp */
    /* @4057784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4057816;
    /* @4057788 constant */
    /* @4057792 load */
    /* @4057800 cast */
    /* @4057804 constant */
    /* @4057808 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4057816: ;
    /* @4057816 constant */
    /* @4057820 cast */
    /* @4057824 load */
    /* @4057832 load */
    /* @4057840 call */
    GM_SITE(vm, 270, 4057840);
    /* @4057848 store */
    v19 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v19);
    /* @4057856 load */
    /* @4057864 constant */
    /* @4057868 cmp */
    /* @4057872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4058244;
    /* @4057876 constant */
    /* @4057880 load */
    /* @4057888 cast */
    /* @4057892 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4057900 constant */
    /* @4057904 cast */
    /* @4057908 load */
    /* @4057916 load */
    /* @4057924 load */
    /* @4057932 load */
    /* @4057940 call */
    GM_SITE(vm, 270, 4057940);
    /* @4057948 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4057952 load */
    /* @4057960 cast */
    /* @4057964 dup */
    /* @4057968 load */
    /* @4057976 load */
    /* @4057984 sub */
    /* @4057988 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4057996 constant */
    /* @4058000 cast */
    /* @4058004 load */
    /* @4058012 load */
    /* @4058020 call */
    GM_SITE(vm, 270, 4058020);
    /* @4058028 store */
    v20 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v20);
    /* @4058036 load */
    /* @4058044 load */
    /* @4058052 cast */
    /* @4058056 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4058064 load */
    /* @4058072 constant */
    /* @4058076 cmp */
    /* @4058080 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4058088;
    /* @4058084 b */
    goto L_4058172;
    L_4058088: ;
    /* @4058088 load */
    /* @4058096 constant */
    /* @4058100 cmp */
    /* @4058104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4058172;
    /* @4058108 constant */
    /* @4058112 cast */
    /* @4058116 call */
    GM_SITE(vm, 270, 4058116);
    /* @4058124 cast */
    /* @4058128 not */
    /* @4058132 bf */
    v21 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v21)) goto L_4058172;
    /* @4058136 constant */
    /* @4058140 cast */
    /* @4058144 constant */
    /* @4058148 cast */
    /* @4058152 constant */
    /* @4058156 cast */
    /* @4058160 call */
    GM_SITE(vm, 270, 4058160);
    /* @4058168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4058172: ;
    /* @4058172 load */
    /* @4058180 constant */
    /* @4058184 add */
    /* @4058188 store */
    v22 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v22);
    /* @4058196 load */
    /* @4058204 constant */
    /* @4058208 cmp */
    /* @4058212 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4058244;
    /* @4058216 constant */
    /* @4058220 load */
    /* @4058228 cast */
    /* @4058232 constant */
    /* @4058236 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4058244: ;
    /* @4058244 constant */
    /* @4058248 cast */
    /* @4058252 load */
    /* @4058260 load */
    /* @4058268 call */
    GM_SITE(vm, 270, 4058268);
    /* @4058276 store */
    v23 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v23);
    /* @4058284 load */
    /* @4058292 constant */
    /* @4058296 cmp */
    /* @4058300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4058672;
    /* @4058304 constant */
    /* @4058308 load */
    /* @4058316 cast */
    /* @4058320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4058328 constant */
    /* @4058332 cast */
    /* @4058336 load */
    /* @4058344 load */
    /* @4058352 load */
    /* @4058360 load */
    /* @4058368 call */
    GM_SITE(vm, 270, 4058368);
    /* @4058376 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4058380 load */
    /* @4058388 cast */
    /* @4058392 dup */
    /* @4058396 load */
    /* @4058404 load */
    /* @4058412 sub */
    /* @4058416 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4058424 constant */
    /* @4058428 cast */
    /* @4058432 load */
    /* @4058440 load */
    /* @4058448 call */
    GM_SITE(vm, 270, 4058448);
    /* @4058456 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v24);
    /* @4058464 load */
    /* @4058472 load */
    /* @4058480 cast */
    /* @4058484 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4058492 load */
    /* @4058500 constant */
    /* @4058504 cmp */
    /* @4058508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4058516;
    /* @4058512 b */
    goto L_4058600;
    L_4058516: ;
    /* @4058516 load */
    /* @4058524 constant */
    /* @4058528 cmp */
    /* @4058532 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4058600;
    /* @4058536 constant */
    /* @4058540 cast */
    /* @4058544 call */
    GM_SITE(vm, 270, 4058544);
    /* @4058552 cast */
    /* @4058556 not */
    /* @4058560 bf */
    v25 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v25)) goto L_4058600;
    /* @4058564 constant */
    /* @4058568 cast */
    /* @4058572 constant */
    /* @4058576 cast */
    /* @4058580 constant */
    /* @4058584 cast */
    /* @4058588 call */
    GM_SITE(vm, 270, 4058588);
    /* @4058596 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4058600: ;
    /* @4058600 load */
    /* @4058608 constant */
    /* @4058612 add */
    /* @4058616 store */
    v26 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v26);
    /* @4058624 load */
    /* @4058632 constant */
    /* @4058636 cmp */
    /* @4058640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4058672;
    /* @4058644 constant */
    /* @4058648 load */
    /* @4058656 cast */
    /* @4058660 constant */
    /* @4058664 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4058672: ;
    /* @4058672 constant */
    /* @4058676 cast */
    /* @4058680 load */
    /* @4058688 load */
    /* @4058696 call */
    GM_SITE(vm, 270, 4058696);
    /* @4058704 store */
    v27 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v27);
    /* @4058712 load */
    /* @4058720 constant */
    /* @4058724 cmp */
    /* @4058728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4059100;
    /* @4058732 constant */
    /* @4058736 load */
    /* @4058744 cast */
    /* @4058748 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4058756 constant */
    /* @4058760 cast */
    /* @4058764 load */
    /* @4058772 load */
    /* @4058780 load */
    /* @4058788 load */
    /* @4058796 call */
    GM_SITE(vm, 270, 4058796);
    /* @4058804 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4058808 load */
    /* @4058816 cast */
    /* @4058820 dup */
    /* @4058824 load */
    /* @4058832 load */
    /* @4058840 sub */
    /* @4058844 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4058852 constant */
    /* @4058856 cast */
    /* @4058860 load */
    /* @4058868 load */
    /* @4058876 call */
    GM_SITE(vm, 270, 4058876);
    /* @4058884 store */
    v28 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v28);
    /* @4058892 load */
    /* @4058900 load */
    /* @4058908 cast */
    /* @4058912 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4058920 load */
    /* @4058928 constant */
    /* @4058932 cmp */
    /* @4058936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4058944;
    /* @4058940 b */
    goto L_4059028;
    L_4058944: ;
    /* @4058944 load */
    /* @4058952 constant */
    /* @4058956 cmp */
    /* @4058960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4059028;
    /* @4058964 constant */
    /* @4058968 cast */
    /* @4058972 call */
    GM_SITE(vm, 270, 4058972);
    /* @4058980 cast */
    /* @4058984 not */
    /* @4058988 bf */
    v29 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v29)) goto L_4059028;
    /* @4058992 constant */
    /* @4058996 cast */
    /* @4059000 constant */
    /* @4059004 cast */
    /* @4059008 constant */
    /* @4059012 cast */
    /* @4059016 call */
    GM_SITE(vm, 270, 4059016);
    /* @4059024 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4059028: ;
    /* @4059028 load */
    /* @4059036 constant */
    /* @4059040 add */
    /* @4059044 store */
    v30 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v30);
    /* @4059052 load */
    /* @4059060 constant */
    /* @4059064 cmp */
    /* @4059068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4059100;
    /* @4059072 constant */
    /* @4059076 load */
    /* @4059084 cast */
    /* @4059088 constant */
    /* @4059092 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4059100: ;
    /* @4059100 constant */
    /* @4059104 cast */
    /* @4059108 load */
    /* @4059116 load */
    /* @4059124 call */
    GM_SITE(vm, 270, 4059124);
    /* @4059132 store */
    v31 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v31);
    /* @4059140 load */
    /* @4059148 constant */
    /* @4059152 cmp */
    /* @4059156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4059528;
    /* @4059160 constant */
    /* @4059164 load */
    /* @4059172 cast */
    /* @4059176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4059184 constant */
    /* @4059188 cast */
    /* @4059192 load */
    /* @4059200 load */
    /* @4059208 load */
    /* @4059216 load */
    /* @4059224 call */
    GM_SITE(vm, 270, 4059224);
    /* @4059232 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4059236 load */
    /* @4059244 cast */
    /* @4059248 dup */
    /* @4059252 load */
    /* @4059260 load */
    /* @4059268 sub */
    /* @4059272 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4059280 constant */
    /* @4059284 cast */
    /* @4059288 load */
    /* @4059296 load */
    /* @4059304 call */
    GM_SITE(vm, 270, 4059304);
    /* @4059312 store */
    v32 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v32);
    /* @4059320 load */
    /* @4059328 load */
    /* @4059336 cast */
    /* @4059340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4059348 load */
    /* @4059356 constant */
    /* @4059360 cmp */
    /* @4059364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4059372;
    /* @4059368 b */
    goto L_4059456;
    L_4059372: ;
    /* @4059372 load */
    /* @4059380 constant */
    /* @4059384 cmp */
    /* @4059388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4059456;
    /* @4059392 constant */
    /* @4059396 cast */
    /* @4059400 call */
    GM_SITE(vm, 270, 4059400);
    /* @4059408 cast */
    /* @4059412 not */
    /* @4059416 bf */
    v33 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v33)) goto L_4059456;
    /* @4059420 constant */
    /* @4059424 cast */
    /* @4059428 constant */
    /* @4059432 cast */
    /* @4059436 constant */
    /* @4059440 cast */
    /* @4059444 call */
    GM_SITE(vm, 270, 4059444);
    /* @4059452 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4059456: ;
    /* @4059456 load */
    /* @4059464 constant */
    /* @4059468 add */
    /* @4059472 store */
    v34 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v34);
    /* @4059480 load */
    /* @4059488 constant */
    /* @4059492 cmp */
    /* @4059496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4059528;
    /* @4059500 constant */
    /* @4059504 load */
    /* @4059512 cast */
    /* @4059516 constant */
    /* @4059520 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4059528: ;
    /* @4059528 constant */
    /* @4059532 cast */
    /* @4059536 load */
    /* @4059544 load */
    /* @4059552 call */
    GM_SITE(vm, 270, 4059552);
    /* @4059560 store */
    v35 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v35);
    /* @4059568 load */
    /* @4059576 constant */
    /* @4059580 cmp */
    /* @4059584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4059956;
    /* @4059588 constant */
    /* @4059592 load */
    /* @4059600 cast */
    /* @4059604 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4059612 constant */
    /* @4059616 cast */
    /* @4059620 load */
    /* @4059628 load */
    /* @4059636 load */
    /* @4059644 load */
    /* @4059652 call */
    GM_SITE(vm, 270, 4059652);
    /* @4059660 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4059664 load */
    /* @4059672 cast */
    /* @4059676 dup */
    /* @4059680 load */
    /* @4059688 load */
    /* @4059696 sub */
    /* @4059700 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4059708 constant */
    /* @4059712 cast */
    /* @4059716 load */
    /* @4059724 load */
    /* @4059732 call */
    GM_SITE(vm, 270, 4059732);
    /* @4059740 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v36);
    /* @4059748 load */
    /* @4059756 load */
    /* @4059764 cast */
    /* @4059768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4059776 load */
    /* @4059784 constant */
    /* @4059788 cmp */
    /* @4059792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4059800;
    /* @4059796 b */
    goto L_4059884;
    L_4059800: ;
    /* @4059800 load */
    /* @4059808 constant */
    /* @4059812 cmp */
    /* @4059816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4059884;
    /* @4059820 constant */
    /* @4059824 cast */
    /* @4059828 call */
    GM_SITE(vm, 270, 4059828);
    /* @4059836 cast */
    /* @4059840 not */
    /* @4059844 bf */
    v37 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v37)) goto L_4059884;
    /* @4059848 constant */
    /* @4059852 cast */
    /* @4059856 constant */
    /* @4059860 cast */
    /* @4059864 constant */
    /* @4059868 cast */
    /* @4059872 call */
    GM_SITE(vm, 270, 4059872);
    /* @4059880 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4059884: ;
    /* @4059884 load */
    /* @4059892 constant */
    /* @4059896 add */
    /* @4059900 store */
    v38 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v38);
    /* @4059908 load */
    /* @4059916 constant */
    /* @4059920 cmp */
    /* @4059924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4059956;
    /* @4059928 constant */
    /* @4059932 load */
    /* @4059940 cast */
    /* @4059944 constant */
    /* @4059948 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4059956: ;
    /* @4059956 constant */
    /* @4059960 cast */
    /* @4059964 load */
    /* @4059972 load */
    /* @4059980 call */
    GM_SITE(vm, 270, 4059980);
    /* @4059988 store */
    v39 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v39);
    /* @4059996 load */
    /* @4060004 constant */
    /* @4060008 cmp */
    /* @4060012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4060384;
    /* @4060016 constant */
    /* @4060020 load */
    /* @4060028 cast */
    /* @4060032 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4060040 constant */
    /* @4060044 cast */
    /* @4060048 load */
    /* @4060056 load */
    /* @4060064 load */
    /* @4060072 load */
    /* @4060080 call */
    GM_SITE(vm, 270, 4060080);
    /* @4060088 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4060092 load */
    /* @4060100 cast */
    /* @4060104 dup */
    /* @4060108 load */
    /* @4060116 load */
    /* @4060124 sub */
    /* @4060128 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4060136 constant */
    /* @4060140 cast */
    /* @4060144 load */
    /* @4060152 load */
    /* @4060160 call */
    GM_SITE(vm, 270, 4060160);
    /* @4060168 store */
    v40 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v40);
    /* @4060176 load */
    /* @4060184 load */
    /* @4060192 cast */
    /* @4060196 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4060204 load */
    /* @4060212 constant */
    /* @4060216 cmp */
    /* @4060220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4060228;
    /* @4060224 b */
    goto L_4060312;
    L_4060228: ;
    /* @4060228 load */
    /* @4060236 constant */
    /* @4060240 cmp */
    /* @4060244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4060312;
    /* @4060248 constant */
    /* @4060252 cast */
    /* @4060256 call */
    GM_SITE(vm, 270, 4060256);
    /* @4060264 cast */
    /* @4060268 not */
    /* @4060272 bf */
    v41 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v41)) goto L_4060312;
    /* @4060276 constant */
    /* @4060280 cast */
    /* @4060284 constant */
    /* @4060288 cast */
    /* @4060292 constant */
    /* @4060296 cast */
    /* @4060300 call */
    GM_SITE(vm, 270, 4060300);
    /* @4060308 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4060312: ;
    /* @4060312 load */
    /* @4060320 constant */
    /* @4060324 add */
    /* @4060328 store */
    v42 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v42);
    /* @4060336 load */
    /* @4060344 constant */
    /* @4060348 cmp */
    /* @4060352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4060384;
    /* @4060356 constant */
    /* @4060360 load */
    /* @4060368 cast */
    /* @4060372 constant */
    /* @4060376 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4060384: ;
    /* @4060384 constant */
    /* @4060388 cast */
    /* @4060392 load */
    /* @4060400 load */
    /* @4060408 call */
    GM_SITE(vm, 270, 4060408);
    /* @4060416 store */
    v43 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v43);
    /* @4060424 load */
    /* @4060432 constant */
    /* @4060436 cmp */
    /* @4060440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4060812;
    /* @4060444 constant */
    /* @4060448 load */
    /* @4060456 cast */
    /* @4060460 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4060468 constant */
    /* @4060472 cast */
    /* @4060476 load */
    /* @4060484 load */
    /* @4060492 load */
    /* @4060500 load */
    /* @4060508 call */
    GM_SITE(vm, 270, 4060508);
    /* @4060516 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4060520 load */
    /* @4060528 cast */
    /* @4060532 dup */
    /* @4060536 load */
    /* @4060544 load */
    /* @4060552 sub */
    /* @4060556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4060564 constant */
    /* @4060568 cast */
    /* @4060572 load */
    /* @4060580 load */
    /* @4060588 call */
    GM_SITE(vm, 270, 4060588);
    /* @4060596 store */
    v44 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v44);
    /* @4060604 load */
    /* @4060612 load */
    /* @4060620 cast */
    /* @4060624 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4060632 load */
    /* @4060640 constant */
    /* @4060644 cmp */
    /* @4060648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4060656;
    /* @4060652 b */
    goto L_4060740;
    L_4060656: ;
    /* @4060656 load */
    /* @4060664 constant */
    /* @4060668 cmp */
    /* @4060672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4060740;
    /* @4060676 constant */
    /* @4060680 cast */
    /* @4060684 call */
    GM_SITE(vm, 270, 4060684);
    /* @4060692 cast */
    /* @4060696 not */
    /* @4060700 bf */
    v45 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v45)) goto L_4060740;
    /* @4060704 constant */
    /* @4060708 cast */
    /* @4060712 constant */
    /* @4060716 cast */
    /* @4060720 constant */
    /* @4060724 cast */
    /* @4060728 call */
    GM_SITE(vm, 270, 4060728);
    /* @4060736 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4060740: ;
    /* @4060740 load */
    /* @4060748 constant */
    /* @4060752 add */
    /* @4060756 store */
    v46 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v46);
    /* @4060764 load */
    /* @4060772 constant */
    /* @4060776 cmp */
    /* @4060780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4060812;
    /* @4060784 constant */
    /* @4060788 load */
    /* @4060796 cast */
    /* @4060800 constant */
    /* @4060804 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4060812: ;
    /* @4060812 constant */
    /* @4060816 cast */
    /* @4060820 load */
    /* @4060828 load */
    /* @4060836 call */
    GM_SITE(vm, 270, 4060836);
    /* @4060844 store */
    v47 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v47);
    /* @4060852 load */
    /* @4060860 constant */
    /* @4060864 cmp */
    /* @4060868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4061240;
    /* @4060872 constant */
    /* @4060876 load */
    /* @4060884 cast */
    /* @4060888 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4060896 constant */
    /* @4060900 cast */
    /* @4060904 load */
    /* @4060912 load */
    /* @4060920 load */
    /* @4060928 load */
    /* @4060936 call */
    GM_SITE(vm, 270, 4060936);
    /* @4060944 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4060948 load */
    /* @4060956 cast */
    /* @4060960 dup */
    /* @4060964 load */
    /* @4060972 load */
    /* @4060980 sub */
    /* @4060984 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4060992 constant */
    /* @4060996 cast */
    /* @4061000 load */
    /* @4061008 load */
    /* @4061016 call */
    GM_SITE(vm, 270, 4061016);
    /* @4061024 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v48);
    /* @4061032 load */
    /* @4061040 load */
    /* @4061048 cast */
    /* @4061052 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4061060 load */
    /* @4061068 constant */
    /* @4061072 cmp */
    /* @4061076 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4061084;
    /* @4061080 b */
    goto L_4061168;
    L_4061084: ;
    /* @4061084 load */
    /* @4061092 constant */
    /* @4061096 cmp */
    /* @4061100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4061168;
    /* @4061104 constant */
    /* @4061108 cast */
    /* @4061112 call */
    GM_SITE(vm, 270, 4061112);
    /* @4061120 cast */
    /* @4061124 not */
    /* @4061128 bf */
    v49 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v49)) goto L_4061168;
    /* @4061132 constant */
    /* @4061136 cast */
    /* @4061140 constant */
    /* @4061144 cast */
    /* @4061148 constant */
    /* @4061152 cast */
    /* @4061156 call */
    GM_SITE(vm, 270, 4061156);
    /* @4061164 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4061168: ;
    /* @4061168 load */
    /* @4061176 constant */
    /* @4061180 add */
    /* @4061184 store */
    v50 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v50);
    /* @4061192 load */
    /* @4061200 constant */
    /* @4061204 cmp */
    /* @4061208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4061240;
    /* @4061212 constant */
    /* @4061216 load */
    /* @4061224 cast */
    /* @4061228 constant */
    /* @4061232 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4061240: ;
    /* @4061240 constant */
    /* @4061244 cast */
    /* @4061248 load */
    /* @4061256 load */
    /* @4061264 call */
    GM_SITE(vm, 270, 4061264);
    /* @4061272 store */
    v51 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v51);
    /* @4061280 load */
    /* @4061288 constant */
    /* @4061292 cmp */
    /* @4061296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4061668;
    /* @4061300 constant */
    /* @4061304 load */
    /* @4061312 cast */
    /* @4061316 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4061324 constant */
    /* @4061328 cast */
    /* @4061332 load */
    /* @4061340 load */
    /* @4061348 load */
    /* @4061356 load */
    /* @4061364 call */
    GM_SITE(vm, 270, 4061364);
    /* @4061372 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4061376 load */
    /* @4061384 cast */
    /* @4061388 dup */
    /* @4061392 load */
    /* @4061400 load */
    /* @4061408 sub */
    /* @4061412 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4061420 constant */
    /* @4061424 cast */
    /* @4061428 load */
    /* @4061436 load */
    /* @4061444 call */
    GM_SITE(vm, 270, 4061444);
    /* @4061452 store */
    v52 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v52);
    /* @4061460 load */
    /* @4061468 load */
    /* @4061476 cast */
    /* @4061480 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4061488 load */
    /* @4061496 constant */
    /* @4061500 cmp */
    /* @4061504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4061512;
    /* @4061508 b */
    goto L_4061596;
    L_4061512: ;
    /* @4061512 load */
    /* @4061520 constant */
    /* @4061524 cmp */
    /* @4061528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4061596;
    /* @4061532 constant */
    /* @4061536 cast */
    /* @4061540 call */
    GM_SITE(vm, 270, 4061540);
    /* @4061548 cast */
    /* @4061552 not */
    /* @4061556 bf */
    v53 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v53)) goto L_4061596;
    /* @4061560 constant */
    /* @4061564 cast */
    /* @4061568 constant */
    /* @4061572 cast */
    /* @4061576 constant */
    /* @4061580 cast */
    /* @4061584 call */
    GM_SITE(vm, 270, 4061584);
    /* @4061592 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4061596: ;
    /* @4061596 load */
    /* @4061604 constant */
    /* @4061608 add */
    /* @4061612 store */
    v54 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v54);
    /* @4061620 load */
    /* @4061628 constant */
    /* @4061632 cmp */
    /* @4061636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4061668;
    /* @4061640 constant */
    /* @4061644 load */
    /* @4061652 cast */
    /* @4061656 constant */
    /* @4061660 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4061668: ;
    /* @4061668 constant */
    /* @4061672 cast */
    /* @4061676 load */
    /* @4061684 load */
    /* @4061692 call */
    GM_SITE(vm, 270, 4061692);
    /* @4061700 store */
    v55 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v55);
    /* @4061708 load */
    /* @4061716 constant */
    /* @4061720 cmp */
    /* @4061724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4062096;
    /* @4061728 constant */
    /* @4061732 load */
    /* @4061740 cast */
    /* @4061744 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4061752 constant */
    /* @4061756 cast */
    /* @4061760 load */
    /* @4061768 load */
    /* @4061776 load */
    /* @4061784 load */
    /* @4061792 call */
    GM_SITE(vm, 270, 4061792);
    /* @4061800 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4061804 load */
    /* @4061812 cast */
    /* @4061816 dup */
    /* @4061820 load */
    /* @4061828 load */
    /* @4061836 sub */
    /* @4061840 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4061848 constant */
    /* @4061852 cast */
    /* @4061856 load */
    /* @4061864 load */
    /* @4061872 call */
    GM_SITE(vm, 270, 4061872);
    /* @4061880 store */
    v56 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v56);
    /* @4061888 load */
    /* @4061896 load */
    /* @4061904 cast */
    /* @4061908 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4061916 load */
    /* @4061924 constant */
    /* @4061928 cmp */
    /* @4061932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4061940;
    /* @4061936 b */
    goto L_4062024;
    L_4061940: ;
    /* @4061940 load */
    /* @4061948 constant */
    /* @4061952 cmp */
    /* @4061956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4062024;
    /* @4061960 constant */
    /* @4061964 cast */
    /* @4061968 call */
    GM_SITE(vm, 270, 4061968);
    /* @4061976 cast */
    /* @4061980 not */
    /* @4061984 bf */
    v57 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v57)) goto L_4062024;
    /* @4061988 constant */
    /* @4061992 cast */
    /* @4061996 constant */
    /* @4062000 cast */
    /* @4062004 constant */
    /* @4062008 cast */
    /* @4062012 call */
    GM_SITE(vm, 270, 4062012);
    /* @4062020 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4062024: ;
    /* @4062024 load */
    /* @4062032 constant */
    /* @4062036 add */
    /* @4062040 store */
    v58 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v58);
    /* @4062048 load */
    /* @4062056 constant */
    /* @4062060 cmp */
    /* @4062064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4062096;
    /* @4062068 constant */
    /* @4062072 load */
    /* @4062080 cast */
    /* @4062084 constant */
    /* @4062088 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4062096: ;
    /* @4062096 constant */
    /* @4062100 cast */
    /* @4062104 load */
    /* @4062112 load */
    /* @4062120 call */
    GM_SITE(vm, 270, 4062120);
    /* @4062128 store */
    v59 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v59);
    /* @4062136 load */
    /* @4062144 constant */
    /* @4062148 cmp */
    /* @4062152 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4062524;
    /* @4062156 constant */
    /* @4062160 load */
    /* @4062168 cast */
    /* @4062172 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4062180 constant */
    /* @4062184 cast */
    /* @4062188 load */
    /* @4062196 load */
    /* @4062204 load */
    /* @4062212 load */
    /* @4062220 call */
    GM_SITE(vm, 270, 4062220);
    /* @4062228 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4062232 load */
    /* @4062240 cast */
    /* @4062244 dup */
    /* @4062248 load */
    /* @4062256 load */
    /* @4062264 sub */
    /* @4062268 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4062276 constant */
    /* @4062280 cast */
    /* @4062284 load */
    /* @4062292 load */
    /* @4062300 call */
    GM_SITE(vm, 270, 4062300);
    /* @4062308 store */
    v60 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v60);
    /* @4062316 load */
    /* @4062324 load */
    /* @4062332 cast */
    /* @4062336 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4062344 load */
    /* @4062352 constant */
    /* @4062356 cmp */
    /* @4062360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4062368;
    /* @4062364 b */
    goto L_4062452;
    L_4062368: ;
    /* @4062368 load */
    /* @4062376 constant */
    /* @4062380 cmp */
    /* @4062384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4062452;
    /* @4062388 constant */
    /* @4062392 cast */
    /* @4062396 call */
    GM_SITE(vm, 270, 4062396);
    /* @4062404 cast */
    /* @4062408 not */
    /* @4062412 bf */
    v61 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v61)) goto L_4062452;
    /* @4062416 constant */
    /* @4062420 cast */
    /* @4062424 constant */
    /* @4062428 cast */
    /* @4062432 constant */
    /* @4062436 cast */
    /* @4062440 call */
    GM_SITE(vm, 270, 4062440);
    /* @4062448 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4062452: ;
    /* @4062452 load */
    /* @4062460 constant */
    /* @4062464 add */
    /* @4062468 store */
    v62 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v62);
    /* @4062476 load */
    /* @4062484 constant */
    /* @4062488 cmp */
    /* @4062492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4062524;
    /* @4062496 constant */
    /* @4062500 load */
    /* @4062508 cast */
    /* @4062512 constant */
    /* @4062516 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4062524: ;
    /* @4062524 constant */
    /* @4062528 cast */
    /* @4062532 load */
    /* @4062540 load */
    /* @4062548 call */
    GM_SITE(vm, 270, 4062548);
    /* @4062556 store */
    v63 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v63);
    /* @4062564 load */
    /* @4062572 constant */
    /* @4062576 cmp */
    /* @4062580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4062952;
    /* @4062584 constant */
    /* @4062588 load */
    /* @4062596 cast */
    /* @4062600 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4062608 constant */
    /* @4062612 cast */
    /* @4062616 load */
    /* @4062624 load */
    /* @4062632 load */
    /* @4062640 load */
    /* @4062648 call */
    GM_SITE(vm, 270, 4062648);
    /* @4062656 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4062660 load */
    /* @4062668 cast */
    /* @4062672 dup */
    /* @4062676 load */
    /* @4062684 load */
    /* @4062692 sub */
    /* @4062696 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4062704 constant */
    /* @4062708 cast */
    /* @4062712 load */
    /* @4062720 load */
    /* @4062728 call */
    GM_SITE(vm, 270, 4062728);
    /* @4062736 store */
    v64 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v64);
    /* @4062744 load */
    /* @4062752 load */
    /* @4062760 cast */
    /* @4062764 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4062772 load */
    /* @4062780 constant */
    /* @4062784 cmp */
    /* @4062788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4062796;
    /* @4062792 b */
    goto L_4062880;
    L_4062796: ;
    /* @4062796 load */
    /* @4062804 constant */
    /* @4062808 cmp */
    /* @4062812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4062880;
    /* @4062816 constant */
    /* @4062820 cast */
    /* @4062824 call */
    GM_SITE(vm, 270, 4062824);
    /* @4062832 cast */
    /* @4062836 not */
    /* @4062840 bf */
    v65 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v65)) goto L_4062880;
    /* @4062844 constant */
    /* @4062848 cast */
    /* @4062852 constant */
    /* @4062856 cast */
    /* @4062860 constant */
    /* @4062864 cast */
    /* @4062868 call */
    GM_SITE(vm, 270, 4062868);
    /* @4062876 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4062880: ;
    /* @4062880 load */
    /* @4062888 constant */
    /* @4062892 add */
    /* @4062896 store */
    v66 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v66);
    /* @4062904 load */
    /* @4062912 constant */
    /* @4062916 cmp */
    /* @4062920 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4062952;
    /* @4062924 constant */
    /* @4062928 load */
    /* @4062936 cast */
    /* @4062940 constant */
    /* @4062944 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4062952: ;
    /* @4062952 constant */
    /* @4062956 cast */
    /* @4062960 load */
    /* @4062968 load */
    /* @4062976 call */
    GM_SITE(vm, 270, 4062976);
    /* @4062984 store */
    v67 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v67);
    /* @4062992 load */
    /* @4063000 constant */
    /* @4063004 cmp */
    /* @4063008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4063332;
    /* @4063012 constant */
    /* @4063016 load */
    /* @4063024 cast */
    /* @4063028 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4063036 constant */
    /* @4063040 cast */
    /* @4063044 load */
    /* @4063052 load */
    /* @4063060 load */
    /* @4063068 load */
    /* @4063076 call */
    GM_SITE(vm, 270, 4063076);
    /* @4063084 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4063088 load */
    /* @4063096 cast */
    /* @4063100 dup */
    /* @4063104 load */
    /* @4063112 load */
    /* @4063120 sub */
    /* @4063124 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4063132 constant */
    /* @4063136 cast */
    /* @4063140 load */
    /* @4063148 load */
    /* @4063156 call */
    GM_SITE(vm, 270, 4063156);
    /* @4063164 store */
    v68 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v68);
    /* @4063172 load */
    /* @4063180 load */
    /* @4063188 cast */
    /* @4063192 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4063200 load */
    /* @4063208 constant */
    /* @4063212 cmp */
    /* @4063216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4063224;
    /* @4063220 b */
    goto L_4063308;
    L_4063224: ;
    /* @4063224 load */
    /* @4063232 constant */
    /* @4063236 cmp */
    /* @4063240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4063308;
    /* @4063244 constant */
    /* @4063248 cast */
    /* @4063252 call */
    GM_SITE(vm, 270, 4063252);
    /* @4063260 cast */
    /* @4063264 not */
    /* @4063268 bf */
    v69 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v69)) goto L_4063308;
    /* @4063272 constant */
    /* @4063276 cast */
    /* @4063280 constant */
    /* @4063284 cast */
    /* @4063288 constant */
    /* @4063292 cast */
    /* @4063296 call */
    GM_SITE(vm, 270, 4063296);
    /* @4063304 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4063308: ;
    /* @4063308 load */
    /* @4063316 constant */
    /* @4063320 add */
    /* @4063324 store */
    v70 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v70);
    L_4063332: ;
    /* @4063332 constant */
    /* @4063336 cast */
    /* @4063340 load */
    /* @4063348 load */
    /* @4063356 call */
    GM_SITE(vm, 270, 4063356);
    /* @4063364 store */
    v71 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v71);
    /* @4063372 load */
    /* @4063380 constant */
    /* @4063384 cmp */
    /* @4063388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4063712;
    /* @4063392 constant */
    /* @4063396 load */
    /* @4063404 cast */
    /* @4063408 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4063416 constant */
    /* @4063420 cast */
    /* @4063424 load */
    /* @4063432 load */
    /* @4063440 load */
    /* @4063448 load */
    /* @4063456 call */
    GM_SITE(vm, 270, 4063456);
    /* @4063464 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4063468 load */
    /* @4063476 cast */
    /* @4063480 dup */
    /* @4063484 load */
    /* @4063492 load */
    /* @4063500 sub */
    /* @4063504 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4063512 constant */
    /* @4063516 cast */
    /* @4063520 load */
    /* @4063528 load */
    /* @4063536 call */
    GM_SITE(vm, 270, 4063536);
    /* @4063544 store */
    v72 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v72);
    /* @4063552 load */
    /* @4063560 load */
    /* @4063568 cast */
    /* @4063572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4063580 load */
    /* @4063588 constant */
    /* @4063592 cmp */
    /* @4063596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4063604;
    /* @4063600 b */
    goto L_4063688;
    L_4063604: ;
    /* @4063604 load */
    /* @4063612 constant */
    /* @4063616 cmp */
    /* @4063620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4063688;
    /* @4063624 constant */
    /* @4063628 cast */
    /* @4063632 call */
    GM_SITE(vm, 270, 4063632);
    /* @4063640 cast */
    /* @4063644 not */
    /* @4063648 bf */
    v73 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v73)) goto L_4063688;
    /* @4063652 constant */
    /* @4063656 cast */
    /* @4063660 constant */
    /* @4063664 cast */
    /* @4063668 constant */
    /* @4063672 cast */
    /* @4063676 call */
    GM_SITE(vm, 270, 4063676);
    /* @4063684 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4063688: ;
    /* @4063688 load */
    /* @4063696 constant */
    /* @4063700 add */
    /* @4063704 store */
    v74 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v74);
    L_4063712: ;
    /* @4063712 constant */
    /* @4063716 cast */
    /* @4063720 load */
    /* @4063728 load */
    /* @4063736 call */
    GM_SITE(vm, 270, 4063736);
    /* @4063744 store */
    v75 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v75);
    /* @4063752 load */
    /* @4063760 constant */
    /* @4063764 cmp */
    /* @4063768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4064092;
    /* @4063772 constant */
    /* @4063776 load */
    /* @4063784 cast */
    /* @4063788 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4063796 constant */
    /* @4063800 cast */
    /* @4063804 load */
    /* @4063812 load */
    /* @4063820 load */
    /* @4063828 load */
    /* @4063836 call */
    GM_SITE(vm, 270, 4063836);
    /* @4063844 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4063848 load */
    /* @4063856 cast */
    /* @4063860 dup */
    /* @4063864 load */
    /* @4063872 load */
    /* @4063880 sub */
    /* @4063884 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4063892 constant */
    /* @4063896 cast */
    /* @4063900 load */
    /* @4063908 load */
    /* @4063916 call */
    GM_SITE(vm, 270, 4063916);
    /* @4063924 store */
    v76 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v76);
    /* @4063932 load */
    /* @4063940 load */
    /* @4063948 cast */
    /* @4063952 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4063960 load */
    /* @4063968 constant */
    /* @4063972 cmp */
    /* @4063976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4063984;
    /* @4063980 b */
    goto L_4064068;
    L_4063984: ;
    /* @4063984 load */
    /* @4063992 constant */
    /* @4063996 cmp */
    /* @4064000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4064068;
    /* @4064004 constant */
    /* @4064008 cast */
    /* @4064012 call */
    GM_SITE(vm, 270, 4064012);
    /* @4064020 cast */
    /* @4064024 not */
    /* @4064028 bf */
    v77 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v77)) goto L_4064068;
    /* @4064032 constant */
    /* @4064036 cast */
    /* @4064040 constant */
    /* @4064044 cast */
    /* @4064048 constant */
    /* @4064052 cast */
    /* @4064056 call */
    GM_SITE(vm, 270, 4064056);
    /* @4064064 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4064068: ;
    /* @4064068 load */
    /* @4064076 constant */
    /* @4064080 add */
    /* @4064084 store */
    v78 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v78);
    L_4064092: ;
    /* @4064092 constant */
    /* @4064096 cast */
    /* @4064100 load */
    /* @4064108 load */
    /* @4064116 call */
    GM_SITE(vm, 270, 4064116);
    /* @4064124 store */
    v79 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v79);
    /* @4064132 load */
    /* @4064140 constant */
    /* @4064144 cmp */
    /* @4064148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4064472;
    /* @4064152 constant */
    /* @4064156 load */
    /* @4064164 cast */
    /* @4064168 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4064176 constant */
    /* @4064180 cast */
    /* @4064184 load */
    /* @4064192 load */
    /* @4064200 load */
    /* @4064208 load */
    /* @4064216 call */
    GM_SITE(vm, 270, 4064216);
    /* @4064224 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(2)));
    /* @4064228 load */
    /* @4064236 cast */
    /* @4064240 dup */
    /* @4064244 load */
    /* @4064252 load */
    /* @4064260 sub */
    /* @4064264 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "flamethrowerdamage")));
    /* @4064272 constant */
    /* @4064276 cast */
    /* @4064280 load */
    /* @4064288 load */
    /* @4064296 call */
    GM_SITE(vm, 270, 4064296);
    /* @4064304 store */
    v80 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v80);
    /* @4064312 load */
    /* @4064320 load */
    /* @4064328 cast */
    /* @4064332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "flamethrowerdamage"));
    /* @4064340 load */
    /* @4064348 constant */
    /* @4064352 cmp */
    /* @4064356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4064364;
    /* @4064360 b */
    goto L_4064448;
    L_4064364: ;
    /* @4064364 load */
    /* @4064372 constant */
    /* @4064376 cmp */
    /* @4064380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4064448;
    /* @4064384 constant */
    /* @4064388 cast */
    /* @4064392 call */
    GM_SITE(vm, 270, 4064392);
    /* @4064400 cast */
    /* @4064404 not */
    /* @4064408 bf */
    v81 = NOT(BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(23))));
    if (!TRUTH(v81)) goto L_4064448;
    /* @4064412 constant */
    /* @4064416 cast */
    /* @4064420 constant */
    /* @4064424 cast */
    /* @4064428 constant */
    /* @4064432 cast */
    /* @4064436 call */
    GM_SITE(vm, 270, 4064436);
    /* @4064444 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4064448: ;
    /* @4064448 load */
    /* @4064456 constant */
    /* @4064460 add */
    /* @4064464 store */
    v82 = GM_ADD(GM_READ(vm, -5, "flamethrowerxp"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerxp", v82);
    L_4064472: ;
    return;
}
