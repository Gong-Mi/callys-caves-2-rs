/* generated from CODE 274 (gml_Object_obj_blade_Step_0), source start 4064580, end 4073340. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0274(GmVM* vm) {
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
    /* @4064580 constant */
    /* @4064584 cast */
    /* @4064588 load */
    /* @4064596 load */
    /* @4064604 load */
    /* @4064612 add */
    /* @4064616 call */
    GM_SITE(vm, 274, 4064616);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4064624 store */
    v2 = GM_CALL(vm, "instance_place", 3, v1, GM_READ(vm, -1, "y"), VAL(158));
    GM_WRITE(vm, -1, "hitblock", v2);
    /* @4064632 load */
    /* @4064640 constant */
    /* @4064644 cmp */
    /* @4064648 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitblock") != VAL(-4)))) goto L_4064696;
    /* @4064652 load */
    /* @4064660 cast */
    /* @4064664 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitblock")))) goto L_4064680;
    L_4064668: ;
    /* @4064668 call */
    GM_SITE(vm, 274, 4064668);
    /* @4064676 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4064680: ;
    /* @4064680 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4064668;
    /* @4064684 call */
    GM_SITE(vm, 274, 4064684);
    /* @4064692 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4064696: ;
    /* @4064696 constant */
    /* @4064700 cast */
    /* @4064704 load */
    /* @4064712 load */
    /* @4064720 call */
    GM_SITE(vm, 274, 4064720);
    /* @4064728 cast */
    /* @4064732 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v3)) goto L_4064788;
    /* @4064736 constant */
    /* @4064740 cast */
    /* @4064744 load */
    /* @4064752 load */
    /* @4064760 call */
    GM_SITE(vm, 274, 4064760);
    /* @4064768 store */
    v4 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(13));
    GM_WRITE(vm, -1, "i1", v4);
    /* @4064776 call */
    GM_SITE(vm, 274, 4064776);
    /* @4064784 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4064788: ;
    /* @4064788 load */
    /* @4064796 store */
    GM_WRITE(vm, -1, "image_angle", GM_READ(vm, -1, "direction"));
    /* @4064804 constant */
    /* @4064808 cast */
    /* @4064812 load */
    /* @4064820 load */
    /* @4064828 call */
    GM_SITE(vm, 274, 4064828);
    /* @4064836 store */
    v5 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v5);
    /* @4064844 load */
    /* @4064852 constant */
    /* @4064856 cmp */
    /* @4064860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4065256;
    /* @4064864 constant */
    /* @4064868 load */
    /* @4064876 cast */
    /* @4064880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4064888 constant */
    /* @4064892 cast */
    /* @4064896 load */
    /* @4064904 load */
    /* @4064912 load */
    /* @4064920 load */
    /* @4064928 call */
    GM_SITE(vm, 274, 4064928);
    /* @4064936 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4064940 load */
    /* @4064948 cast */
    /* @4064952 dup */
    /* @4064956 load */
    /* @4064964 load */
    /* @4064972 sub */
    /* @4064976 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "bladegundamage")));
    /* @4064984 constant */
    /* @4064988 cast */
    /* @4064992 load */
    /* @4065000 load */
    /* @4065008 call */
    GM_SITE(vm, 274, 4065008);
    /* @4065016 store */
    v6 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v6);
    /* @4065024 load */
    /* @4065032 load */
    /* @4065040 cast */
    /* @4065044 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4065052 load */
    /* @4065060 constant */
    /* @4065064 cmp */
    /* @4065068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4065076;
    /* @4065072 b */
    goto L_4065132;
    L_4065076: ;
    /* @4065076 load */
    /* @4065084 constant */
    /* @4065088 cmp */
    /* @4065092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4065132;
    /* @4065096 constant */
    /* @4065100 cast */
    /* @4065104 constant */
    /* @4065108 cast */
    /* @4065112 constant */
    /* @4065116 cast */
    /* @4065120 call */
    GM_SITE(vm, 274, 4065120);
    /* @4065128 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4065132: ;
    /* @4065132 load */
    /* @4065140 cast */
    /* @4065144 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitknife")))) goto L_4065180;
    L_4065148: ;
    /* @4065148 constant */
    /* @4065152 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4065160 constant */
    /* @4065164 constant */
    /* @4065168 constant */
    /* @4065172 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4065180: ;
    /* @4065180 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4065148;
    /* @4065184 load */
    /* @4065192 constant */
    /* @4065196 add */
    /* @4065200 store */
    v7 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v7);
    /* @4065208 load */
    /* @4065216 constant */
    /* @4065220 cmp */
    /* @4065224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4065256;
    /* @4065228 constant */
    /* @4065232 load */
    /* @4065240 cast */
    /* @4065244 constant */
    /* @4065248 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4065256: ;
    /* @4065256 constant */
    /* @4065260 cast */
    /* @4065264 load */
    /* @4065272 load */
    /* @4065280 call */
    GM_SITE(vm, 274, 4065280);
    /* @4065288 store */
    v8 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v8);
    /* @4065296 load */
    /* @4065304 constant */
    /* @4065308 cmp */
    /* @4065312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4065708;
    /* @4065316 constant */
    /* @4065320 load */
    /* @4065328 cast */
    /* @4065332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4065340 constant */
    /* @4065344 cast */
    /* @4065348 load */
    /* @4065356 load */
    /* @4065364 load */
    /* @4065372 load */
    /* @4065380 call */
    GM_SITE(vm, 274, 4065380);
    /* @4065388 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4065392 load */
    /* @4065400 cast */
    /* @4065404 dup */
    /* @4065408 load */
    /* @4065416 load */
    /* @4065424 sub */
    /* @4065428 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "bladegundamage")));
    /* @4065436 constant */
    /* @4065440 cast */
    /* @4065444 load */
    /* @4065452 load */
    /* @4065460 call */
    GM_SITE(vm, 274, 4065460);
    /* @4065468 store */
    v9 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v9);
    /* @4065476 load */
    /* @4065484 load */
    /* @4065492 cast */
    /* @4065496 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4065504 load */
    /* @4065512 constant */
    /* @4065516 cmp */
    /* @4065520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4065528;
    /* @4065524 b */
    goto L_4065584;
    L_4065528: ;
    /* @4065528 load */
    /* @4065536 constant */
    /* @4065540 cmp */
    /* @4065544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4065584;
    /* @4065548 constant */
    /* @4065552 cast */
    /* @4065556 constant */
    /* @4065560 cast */
    /* @4065564 constant */
    /* @4065568 cast */
    /* @4065572 call */
    GM_SITE(vm, 274, 4065572);
    /* @4065580 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4065584: ;
    /* @4065584 load */
    /* @4065592 cast */
    /* @4065596 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit")))) goto L_4065632;
    L_4065600: ;
    /* @4065600 constant */
    /* @4065604 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4065612 constant */
    /* @4065616 constant */
    /* @4065620 constant */
    /* @4065624 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4065632: ;
    /* @4065632 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4065600;
    /* @4065636 load */
    /* @4065644 constant */
    /* @4065648 add */
    /* @4065652 store */
    v10 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v10);
    /* @4065660 load */
    /* @4065668 constant */
    /* @4065672 cmp */
    /* @4065676 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4065708;
    /* @4065680 constant */
    /* @4065684 load */
    /* @4065692 cast */
    /* @4065696 constant */
    /* @4065700 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4065708: ;
    /* @4065708 constant */
    /* @4065712 cast */
    /* @4065716 load */
    /* @4065724 load */
    /* @4065732 call */
    GM_SITE(vm, 274, 4065732);
    /* @4065740 store */
    v11 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v11);
    /* @4065748 load */
    /* @4065756 constant */
    /* @4065760 cmp */
    /* @4065764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4066160;
    /* @4065768 constant */
    /* @4065772 load */
    /* @4065780 cast */
    /* @4065784 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4065792 constant */
    /* @4065796 cast */
    /* @4065800 load */
    /* @4065808 load */
    /* @4065816 load */
    /* @4065824 load */
    /* @4065832 call */
    GM_SITE(vm, 274, 4065832);
    /* @4065840 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4065844 load */
    /* @4065852 cast */
    /* @4065856 dup */
    /* @4065860 load */
    /* @4065868 load */
    /* @4065876 sub */
    /* @4065880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "bladegundamage")));
    /* @4065888 constant */
    /* @4065892 cast */
    /* @4065896 load */
    /* @4065904 load */
    /* @4065912 call */
    GM_SITE(vm, 274, 4065912);
    /* @4065920 store */
    v12 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v12);
    /* @4065928 load */
    /* @4065936 load */
    /* @4065944 cast */
    /* @4065948 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4065956 load */
    /* @4065964 constant */
    /* @4065968 cmp */
    /* @4065972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4065980;
    /* @4065976 b */
    goto L_4066036;
    L_4065980: ;
    /* @4065980 load */
    /* @4065988 constant */
    /* @4065992 cmp */
    /* @4065996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4066036;
    /* @4066000 constant */
    /* @4066004 cast */
    /* @4066008 constant */
    /* @4066012 cast */
    /* @4066016 constant */
    /* @4066020 cast */
    /* @4066024 call */
    GM_SITE(vm, 274, 4066024);
    /* @4066032 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4066036: ;
    /* @4066036 load */
    /* @4066044 cast */
    /* @4066048 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hitwolf")))) goto L_4066084;
    L_4066052: ;
    /* @4066052 constant */
    /* @4066056 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4066064 constant */
    /* @4066068 constant */
    /* @4066072 constant */
    /* @4066076 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4066084: ;
    /* @4066084 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4066052;
    /* @4066088 load */
    /* @4066096 constant */
    /* @4066100 add */
    /* @4066104 store */
    v13 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v13);
    /* @4066112 load */
    /* @4066120 constant */
    /* @4066124 cmp */
    /* @4066128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4066160;
    /* @4066132 constant */
    /* @4066136 load */
    /* @4066144 cast */
    /* @4066148 constant */
    /* @4066152 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4066160: ;
    /* @4066160 constant */
    /* @4066164 cast */
    /* @4066168 load */
    /* @4066176 load */
    /* @4066184 call */
    GM_SITE(vm, 274, 4066184);
    /* @4066192 store */
    v14 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v14);
    /* @4066200 load */
    /* @4066208 constant */
    /* @4066212 cmp */
    /* @4066216 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4066612;
    /* @4066220 constant */
    /* @4066224 load */
    /* @4066232 cast */
    /* @4066236 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4066244 constant */
    /* @4066248 cast */
    /* @4066252 load */
    /* @4066260 load */
    /* @4066268 load */
    /* @4066276 load */
    /* @4066284 call */
    GM_SITE(vm, 274, 4066284);
    /* @4066292 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4066296 load */
    /* @4066304 cast */
    /* @4066308 dup */
    /* @4066312 load */
    /* @4066320 load */
    /* @4066328 sub */
    /* @4066332 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "bladegundamage")));
    /* @4066340 constant */
    /* @4066344 cast */
    /* @4066348 load */
    /* @4066356 load */
    /* @4066364 call */
    GM_SITE(vm, 274, 4066364);
    /* @4066372 store */
    v15 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v15);
    /* @4066380 load */
    /* @4066388 load */
    /* @4066396 cast */
    /* @4066400 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4066408 load */
    /* @4066416 constant */
    /* @4066420 cmp */
    /* @4066424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4066432;
    /* @4066428 b */
    goto L_4066488;
    L_4066432: ;
    /* @4066432 load */
    /* @4066440 constant */
    /* @4066444 cmp */
    /* @4066448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4066488;
    /* @4066452 constant */
    /* @4066456 cast */
    /* @4066460 constant */
    /* @4066464 cast */
    /* @4066468 constant */
    /* @4066472 cast */
    /* @4066476 call */
    GM_SITE(vm, 274, 4066476);
    /* @4066484 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4066488: ;
    /* @4066488 load */
    /* @4066496 cast */
    /* @4066500 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit2")))) goto L_4066536;
    L_4066504: ;
    /* @4066504 constant */
    /* @4066508 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4066516 constant */
    /* @4066520 constant */
    /* @4066524 constant */
    /* @4066528 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4066536: ;
    /* @4066536 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4066504;
    /* @4066540 load */
    /* @4066548 constant */
    /* @4066552 add */
    /* @4066556 store */
    v16 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v16);
    /* @4066564 load */
    /* @4066572 constant */
    /* @4066576 cmp */
    /* @4066580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4066612;
    /* @4066584 constant */
    /* @4066588 load */
    /* @4066596 cast */
    /* @4066600 constant */
    /* @4066604 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4066612: ;
    /* @4066612 constant */
    /* @4066616 cast */
    /* @4066620 load */
    /* @4066628 load */
    /* @4066636 call */
    GM_SITE(vm, 274, 4066636);
    /* @4066644 store */
    v17 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v17);
    /* @4066652 load */
    /* @4066660 constant */
    /* @4066664 cmp */
    /* @4066668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4067012;
    /* @4066672 constant */
    /* @4066676 load */
    /* @4066684 cast */
    /* @4066688 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "flashing", VAL(1));
    /* @4066696 constant */
    /* @4066700 cast */
    /* @4066704 load */
    /* @4066712 load */
    /* @4066720 load */
    /* @4066728 load */
    /* @4066736 call */
    GM_SITE(vm, 274, 4066736);
    /* @4066744 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4066748 load */
    /* @4066756 cast */
    /* @4066760 dup */
    /* @4066764 load */
    /* @4066772 load */
    /* @4066780 sub */
    /* @4066784 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "hptrex") - GM_READ(vm, -5, "bladegundamage")));
    /* @4066792 constant */
    /* @4066796 cast */
    /* @4066800 load */
    /* @4066808 load */
    /* @4066816 call */
    GM_SITE(vm, 274, 4066816);
    /* @4066824 store */
    v18 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v18);
    /* @4066832 load */
    /* @4066840 load */
    /* @4066848 cast */
    /* @4066852 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4066860 load */
    /* @4066868 constant */
    /* @4066872 cmp */
    /* @4066876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4066884;
    /* @4066880 b */
    goto L_4066940;
    L_4066884: ;
    /* @4066884 load */
    /* @4066892 constant */
    /* @4066896 cmp */
    /* @4066900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4066940;
    /* @4066904 constant */
    /* @4066908 cast */
    /* @4066912 constant */
    /* @4066916 cast */
    /* @4066920 constant */
    /* @4066924 cast */
    /* @4066928 call */
    GM_SITE(vm, 274, 4066928);
    /* @4066936 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4066940: ;
    /* @4066940 load */
    /* @4066948 constant */
    /* @4066952 add */
    /* @4066956 store */
    v19 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v19);
    /* @4066964 load */
    /* @4066972 constant */
    /* @4066976 cmp */
    /* @4066980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4067012;
    /* @4066984 constant */
    /* @4066988 load */
    /* @4066996 cast */
    /* @4067000 constant */
    /* @4067004 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hittrex")), "alarm", VAL(6), VAL(1));
    L_4067012: ;
    /* @4067012 constant */
    /* @4067016 cast */
    /* @4067020 load */
    /* @4067028 load */
    /* @4067036 call */
    GM_SITE(vm, 274, 4067036);
    /* @4067044 store */
    v20 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v20);
    /* @4067052 load */
    /* @4067060 constant */
    /* @4067064 cmp */
    /* @4067068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4067464;
    /* @4067072 constant */
    /* @4067076 load */
    /* @4067084 cast */
    /* @4067088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4067096 constant */
    /* @4067100 cast */
    /* @4067104 load */
    /* @4067112 load */
    /* @4067120 load */
    /* @4067128 load */
    /* @4067136 call */
    GM_SITE(vm, 274, 4067136);
    /* @4067144 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4067148 load */
    /* @4067156 cast */
    /* @4067160 dup */
    /* @4067164 load */
    /* @4067172 load */
    /* @4067180 sub */
    /* @4067184 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "bladegundamage")));
    /* @4067192 constant */
    /* @4067196 cast */
    /* @4067200 load */
    /* @4067208 load */
    /* @4067216 call */
    GM_SITE(vm, 274, 4067216);
    /* @4067224 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v21);
    /* @4067232 load */
    /* @4067240 load */
    /* @4067248 cast */
    /* @4067252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4067260 load */
    /* @4067268 constant */
    /* @4067272 cmp */
    /* @4067276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4067284;
    /* @4067280 b */
    goto L_4067340;
    L_4067284: ;
    /* @4067284 load */
    /* @4067292 constant */
    /* @4067296 cmp */
    /* @4067300 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4067340;
    /* @4067304 constant */
    /* @4067308 cast */
    /* @4067312 constant */
    /* @4067316 cast */
    /* @4067320 constant */
    /* @4067324 cast */
    /* @4067328 call */
    GM_SITE(vm, 274, 4067328);
    /* @4067336 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4067340: ;
    /* @4067340 load */
    /* @4067348 cast */
    /* @4067352 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit4")))) goto L_4067388;
    L_4067356: ;
    /* @4067356 constant */
    /* @4067360 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4067368 constant */
    /* @4067372 constant */
    /* @4067376 constant */
    /* @4067380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4067388: ;
    /* @4067388 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4067356;
    /* @4067392 load */
    /* @4067400 constant */
    /* @4067404 add */
    /* @4067408 store */
    v22 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v22);
    /* @4067416 load */
    /* @4067424 constant */
    /* @4067428 cmp */
    /* @4067432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4067464;
    /* @4067436 constant */
    /* @4067440 load */
    /* @4067448 cast */
    /* @4067452 constant */
    /* @4067456 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4067464: ;
    /* @4067464 constant */
    /* @4067468 cast */
    /* @4067472 load */
    /* @4067480 load */
    /* @4067488 call */
    GM_SITE(vm, 274, 4067488);
    /* @4067496 store */
    v23 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v23);
    /* @4067504 load */
    /* @4067512 constant */
    /* @4067516 cmp */
    /* @4067520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4067916;
    /* @4067524 constant */
    /* @4067528 load */
    /* @4067536 cast */
    /* @4067540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4067548 constant */
    /* @4067552 cast */
    /* @4067556 load */
    /* @4067564 load */
    /* @4067572 load */
    /* @4067580 load */
    /* @4067588 call */
    GM_SITE(vm, 274, 4067588);
    /* @4067596 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4067600 load */
    /* @4067608 cast */
    /* @4067612 dup */
    /* @4067616 load */
    /* @4067624 load */
    /* @4067632 sub */
    /* @4067636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "bladegundamage")));
    /* @4067644 constant */
    /* @4067648 cast */
    /* @4067652 load */
    /* @4067660 load */
    /* @4067668 call */
    GM_SITE(vm, 274, 4067668);
    /* @4067676 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v24);
    /* @4067684 load */
    /* @4067692 load */
    /* @4067700 cast */
    /* @4067704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4067712 load */
    /* @4067720 constant */
    /* @4067724 cmp */
    /* @4067728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4067736;
    /* @4067732 b */
    goto L_4067792;
    L_4067736: ;
    /* @4067736 load */
    /* @4067744 constant */
    /* @4067748 cmp */
    /* @4067752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4067792;
    /* @4067756 constant */
    /* @4067760 cast */
    /* @4067764 constant */
    /* @4067768 cast */
    /* @4067772 constant */
    /* @4067776 cast */
    /* @4067780 call */
    GM_SITE(vm, 274, 4067780);
    /* @4067788 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4067792: ;
    /* @4067792 load */
    /* @4067800 cast */
    /* @4067804 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit5")))) goto L_4067840;
    L_4067808: ;
    /* @4067808 constant */
    /* @4067812 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4067820 constant */
    /* @4067824 constant */
    /* @4067828 constant */
    /* @4067832 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4067840: ;
    /* @4067840 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4067808;
    /* @4067844 load */
    /* @4067852 constant */
    /* @4067856 add */
    /* @4067860 store */
    v25 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v25);
    /* @4067868 load */
    /* @4067876 constant */
    /* @4067880 cmp */
    /* @4067884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4067916;
    /* @4067888 constant */
    /* @4067892 load */
    /* @4067900 cast */
    /* @4067904 constant */
    /* @4067908 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4067916: ;
    /* @4067916 constant */
    /* @4067920 cast */
    /* @4067924 load */
    /* @4067932 load */
    /* @4067940 call */
    GM_SITE(vm, 274, 4067940);
    /* @4067948 store */
    v26 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v26);
    /* @4067956 load */
    /* @4067964 constant */
    /* @4067968 cmp */
    /* @4067972 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4068368;
    /* @4067976 constant */
    /* @4067980 load */
    /* @4067988 cast */
    /* @4067992 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4068000 constant */
    /* @4068004 cast */
    /* @4068008 load */
    /* @4068016 load */
    /* @4068024 load */
    /* @4068032 load */
    /* @4068040 call */
    GM_SITE(vm, 274, 4068040);
    /* @4068048 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4068052 load */
    /* @4068060 cast */
    /* @4068064 dup */
    /* @4068068 load */
    /* @4068076 load */
    /* @4068084 sub */
    /* @4068088 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "bladegundamage")));
    /* @4068096 constant */
    /* @4068100 cast */
    /* @4068104 load */
    /* @4068112 load */
    /* @4068120 call */
    GM_SITE(vm, 274, 4068120);
    /* @4068128 store */
    v27 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v27);
    /* @4068136 load */
    /* @4068144 load */
    /* @4068152 cast */
    /* @4068156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4068164 load */
    /* @4068172 constant */
    /* @4068176 cmp */
    /* @4068180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4068188;
    /* @4068184 b */
    goto L_4068244;
    L_4068188: ;
    /* @4068188 load */
    /* @4068196 constant */
    /* @4068200 cmp */
    /* @4068204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4068244;
    /* @4068208 constant */
    /* @4068212 cast */
    /* @4068216 constant */
    /* @4068220 cast */
    /* @4068224 constant */
    /* @4068228 cast */
    /* @4068232 call */
    GM_SITE(vm, 274, 4068232);
    /* @4068240 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4068244: ;
    /* @4068244 load */
    /* @4068252 cast */
    /* @4068256 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit7")))) goto L_4068292;
    L_4068260: ;
    /* @4068260 constant */
    /* @4068264 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4068272 constant */
    /* @4068276 constant */
    /* @4068280 constant */
    /* @4068284 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4068292: ;
    /* @4068292 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4068260;
    /* @4068296 load */
    /* @4068304 constant */
    /* @4068308 add */
    /* @4068312 store */
    v28 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v28);
    /* @4068320 load */
    /* @4068328 constant */
    /* @4068332 cmp */
    /* @4068336 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4068368;
    /* @4068340 constant */
    /* @4068344 load */
    /* @4068352 cast */
    /* @4068356 constant */
    /* @4068360 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4068368: ;
    /* @4068368 constant */
    /* @4068372 cast */
    /* @4068376 load */
    /* @4068384 load */
    /* @4068392 call */
    GM_SITE(vm, 274, 4068392);
    /* @4068400 store */
    v29 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v29);
    /* @4068408 load */
    /* @4068416 constant */
    /* @4068420 cmp */
    /* @4068424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4068820;
    /* @4068428 constant */
    /* @4068432 load */
    /* @4068440 cast */
    /* @4068444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4068452 constant */
    /* @4068456 cast */
    /* @4068460 load */
    /* @4068468 load */
    /* @4068476 load */
    /* @4068484 load */
    /* @4068492 call */
    GM_SITE(vm, 274, 4068492);
    /* @4068500 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4068504 load */
    /* @4068512 cast */
    /* @4068516 dup */
    /* @4068520 load */
    /* @4068528 load */
    /* @4068536 sub */
    /* @4068540 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "bladegundamage")));
    /* @4068548 constant */
    /* @4068552 cast */
    /* @4068556 load */
    /* @4068564 load */
    /* @4068572 call */
    GM_SITE(vm, 274, 4068572);
    /* @4068580 store */
    v30 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v30);
    /* @4068588 load */
    /* @4068596 load */
    /* @4068604 cast */
    /* @4068608 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4068616 load */
    /* @4068624 constant */
    /* @4068628 cmp */
    /* @4068632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4068640;
    /* @4068636 b */
    goto L_4068696;
    L_4068640: ;
    /* @4068640 load */
    /* @4068648 constant */
    /* @4068652 cmp */
    /* @4068656 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4068696;
    /* @4068660 constant */
    /* @4068664 cast */
    /* @4068668 constant */
    /* @4068672 cast */
    /* @4068676 constant */
    /* @4068680 cast */
    /* @4068684 call */
    GM_SITE(vm, 274, 4068684);
    /* @4068692 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4068696: ;
    /* @4068696 load */
    /* @4068704 cast */
    /* @4068708 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit8")))) goto L_4068744;
    L_4068712: ;
    /* @4068712 constant */
    /* @4068716 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4068724 constant */
    /* @4068728 constant */
    /* @4068732 constant */
    /* @4068736 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4068744: ;
    /* @4068744 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4068712;
    /* @4068748 load */
    /* @4068756 constant */
    /* @4068760 add */
    /* @4068764 store */
    v31 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v31);
    /* @4068772 load */
    /* @4068780 constant */
    /* @4068784 cmp */
    /* @4068788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4068820;
    /* @4068792 constant */
    /* @4068796 load */
    /* @4068804 cast */
    /* @4068808 constant */
    /* @4068812 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4068820: ;
    /* @4068820 constant */
    /* @4068824 cast */
    /* @4068828 load */
    /* @4068836 load */
    /* @4068844 call */
    GM_SITE(vm, 274, 4068844);
    /* @4068852 store */
    v32 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v32);
    /* @4068860 load */
    /* @4068868 constant */
    /* @4068872 cmp */
    /* @4068876 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4069272;
    /* @4068880 constant */
    /* @4068884 load */
    /* @4068892 cast */
    /* @4068896 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4068904 constant */
    /* @4068908 cast */
    /* @4068912 load */
    /* @4068920 load */
    /* @4068928 load */
    /* @4068936 load */
    /* @4068944 call */
    GM_SITE(vm, 274, 4068944);
    /* @4068952 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4068956 load */
    /* @4068964 cast */
    /* @4068968 dup */
    /* @4068972 load */
    /* @4068980 load */
    /* @4068988 sub */
    /* @4068992 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "bladegundamage")));
    /* @4069000 constant */
    /* @4069004 cast */
    /* @4069008 load */
    /* @4069016 load */
    /* @4069024 call */
    GM_SITE(vm, 274, 4069024);
    /* @4069032 store */
    v33 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v33);
    /* @4069040 load */
    /* @4069048 load */
    /* @4069056 cast */
    /* @4069060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4069068 load */
    /* @4069076 constant */
    /* @4069080 cmp */
    /* @4069084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4069092;
    /* @4069088 b */
    goto L_4069148;
    L_4069092: ;
    /* @4069092 load */
    /* @4069100 constant */
    /* @4069104 cmp */
    /* @4069108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4069148;
    /* @4069112 constant */
    /* @4069116 cast */
    /* @4069120 constant */
    /* @4069124 cast */
    /* @4069128 constant */
    /* @4069132 cast */
    /* @4069136 call */
    GM_SITE(vm, 274, 4069136);
    /* @4069144 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4069148: ;
    /* @4069148 load */
    /* @4069156 cast */
    /* @4069160 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit9")))) goto L_4069196;
    L_4069164: ;
    /* @4069164 constant */
    /* @4069168 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4069176 constant */
    /* @4069180 constant */
    /* @4069184 constant */
    /* @4069188 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4069196: ;
    /* @4069196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4069164;
    /* @4069200 load */
    /* @4069208 constant */
    /* @4069212 add */
    /* @4069216 store */
    v34 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v34);
    /* @4069224 load */
    /* @4069232 constant */
    /* @4069236 cmp */
    /* @4069240 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4069272;
    /* @4069244 constant */
    /* @4069248 load */
    /* @4069256 cast */
    /* @4069260 constant */
    /* @4069264 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4069272: ;
    /* @4069272 constant */
    /* @4069276 cast */
    /* @4069280 load */
    /* @4069288 load */
    /* @4069296 call */
    GM_SITE(vm, 274, 4069296);
    /* @4069304 store */
    v35 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v35);
    /* @4069312 load */
    /* @4069320 constant */
    /* @4069324 cmp */
    /* @4069328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4069724;
    /* @4069332 constant */
    /* @4069336 load */
    /* @4069344 cast */
    /* @4069348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4069356 constant */
    /* @4069360 cast */
    /* @4069364 load */
    /* @4069372 load */
    /* @4069380 load */
    /* @4069388 load */
    /* @4069396 call */
    GM_SITE(vm, 274, 4069396);
    /* @4069404 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4069408 load */
    /* @4069416 cast */
    /* @4069420 dup */
    /* @4069424 load */
    /* @4069432 load */
    /* @4069440 sub */
    /* @4069444 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "bladegundamage")));
    /* @4069452 constant */
    /* @4069456 cast */
    /* @4069460 load */
    /* @4069468 load */
    /* @4069476 call */
    GM_SITE(vm, 274, 4069476);
    /* @4069484 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v36);
    /* @4069492 load */
    /* @4069500 load */
    /* @4069508 cast */
    /* @4069512 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4069520 load */
    /* @4069528 constant */
    /* @4069532 cmp */
    /* @4069536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4069544;
    /* @4069540 b */
    goto L_4069600;
    L_4069544: ;
    /* @4069544 load */
    /* @4069552 constant */
    /* @4069556 cmp */
    /* @4069560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4069600;
    /* @4069564 constant */
    /* @4069568 cast */
    /* @4069572 constant */
    /* @4069576 cast */
    /* @4069580 constant */
    /* @4069584 cast */
    /* @4069588 call */
    GM_SITE(vm, 274, 4069588);
    /* @4069596 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4069600: ;
    /* @4069600 load */
    /* @4069608 cast */
    /* @4069612 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit10")))) goto L_4069648;
    L_4069616: ;
    /* @4069616 constant */
    /* @4069620 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4069628 constant */
    /* @4069632 constant */
    /* @4069636 constant */
    /* @4069640 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4069648: ;
    /* @4069648 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4069616;
    /* @4069652 load */
    /* @4069660 constant */
    /* @4069664 add */
    /* @4069668 store */
    v37 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v37);
    /* @4069676 load */
    /* @4069684 constant */
    /* @4069688 cmp */
    /* @4069692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4069724;
    /* @4069696 constant */
    /* @4069700 load */
    /* @4069708 cast */
    /* @4069712 constant */
    /* @4069716 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4069724: ;
    /* @4069724 constant */
    /* @4069728 cast */
    /* @4069732 load */
    /* @4069740 load */
    /* @4069748 call */
    GM_SITE(vm, 274, 4069748);
    /* @4069756 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v38);
    /* @4069764 load */
    /* @4069772 constant */
    /* @4069776 cmp */
    /* @4069780 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4070176;
    /* @4069784 constant */
    /* @4069788 load */
    /* @4069796 cast */
    /* @4069800 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4069808 constant */
    /* @4069812 cast */
    /* @4069816 load */
    /* @4069824 load */
    /* @4069832 load */
    /* @4069840 load */
    /* @4069848 call */
    GM_SITE(vm, 274, 4069848);
    /* @4069856 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4069860 load */
    /* @4069868 cast */
    /* @4069872 dup */
    /* @4069876 load */
    /* @4069884 load */
    /* @4069892 sub */
    /* @4069896 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "bladegundamage")));
    /* @4069904 constant */
    /* @4069908 cast */
    /* @4069912 load */
    /* @4069920 load */
    /* @4069928 call */
    GM_SITE(vm, 274, 4069928);
    /* @4069936 store */
    v39 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v39);
    /* @4069944 load */
    /* @4069952 load */
    /* @4069960 cast */
    /* @4069964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4069972 load */
    /* @4069980 constant */
    /* @4069984 cmp */
    /* @4069988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4069996;
    /* @4069992 b */
    goto L_4070052;
    L_4069996: ;
    /* @4069996 load */
    /* @4070004 constant */
    /* @4070008 cmp */
    /* @4070012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4070052;
    /* @4070016 constant */
    /* @4070020 cast */
    /* @4070024 constant */
    /* @4070028 cast */
    /* @4070032 constant */
    /* @4070036 cast */
    /* @4070040 call */
    GM_SITE(vm, 274, 4070040);
    /* @4070048 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4070052: ;
    /* @4070052 load */
    /* @4070060 cast */
    /* @4070064 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit11")))) goto L_4070100;
    L_4070068: ;
    /* @4070068 constant */
    /* @4070072 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4070080 constant */
    /* @4070084 constant */
    /* @4070088 constant */
    /* @4070092 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4070100: ;
    /* @4070100 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4070068;
    /* @4070104 load */
    /* @4070112 constant */
    /* @4070116 add */
    /* @4070120 store */
    v40 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v40);
    /* @4070128 load */
    /* @4070136 constant */
    /* @4070140 cmp */
    /* @4070144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4070176;
    /* @4070148 constant */
    /* @4070152 load */
    /* @4070160 cast */
    /* @4070164 constant */
    /* @4070168 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4070176: ;
    /* @4070176 constant */
    /* @4070180 cast */
    /* @4070184 load */
    /* @4070192 load */
    /* @4070200 call */
    GM_SITE(vm, 274, 4070200);
    /* @4070208 store */
    v41 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v41);
    /* @4070216 load */
    /* @4070224 constant */
    /* @4070228 cmp */
    /* @4070232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4070628;
    /* @4070236 constant */
    /* @4070240 load */
    /* @4070248 cast */
    /* @4070252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4070260 constant */
    /* @4070264 cast */
    /* @4070268 load */
    /* @4070276 load */
    /* @4070284 load */
    /* @4070292 load */
    /* @4070300 call */
    GM_SITE(vm, 274, 4070300);
    /* @4070308 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4070312 load */
    /* @4070320 cast */
    /* @4070324 dup */
    /* @4070328 load */
    /* @4070336 load */
    /* @4070344 sub */
    /* @4070348 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "bladegundamage")));
    /* @4070356 constant */
    /* @4070360 cast */
    /* @4070364 load */
    /* @4070372 load */
    /* @4070380 call */
    GM_SITE(vm, 274, 4070380);
    /* @4070388 store */
    v42 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v42);
    /* @4070396 load */
    /* @4070404 load */
    /* @4070412 cast */
    /* @4070416 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4070424 load */
    /* @4070432 constant */
    /* @4070436 cmp */
    /* @4070440 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4070448;
    /* @4070444 b */
    goto L_4070504;
    L_4070448: ;
    /* @4070448 load */
    /* @4070456 constant */
    /* @4070460 cmp */
    /* @4070464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4070504;
    /* @4070468 constant */
    /* @4070472 cast */
    /* @4070476 constant */
    /* @4070480 cast */
    /* @4070484 constant */
    /* @4070488 cast */
    /* @4070492 call */
    GM_SITE(vm, 274, 4070492);
    /* @4070500 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4070504: ;
    /* @4070504 load */
    /* @4070512 cast */
    /* @4070516 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit12")))) goto L_4070552;
    L_4070520: ;
    /* @4070520 constant */
    /* @4070524 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4070532 constant */
    /* @4070536 constant */
    /* @4070540 constant */
    /* @4070544 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4070552: ;
    /* @4070552 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4070520;
    /* @4070556 load */
    /* @4070564 constant */
    /* @4070568 add */
    /* @4070572 store */
    v43 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v43);
    /* @4070580 load */
    /* @4070588 constant */
    /* @4070592 cmp */
    /* @4070596 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4070628;
    /* @4070600 constant */
    /* @4070604 load */
    /* @4070612 cast */
    /* @4070616 constant */
    /* @4070620 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4070628: ;
    /* @4070628 constant */
    /* @4070632 cast */
    /* @4070636 load */
    /* @4070644 load */
    /* @4070652 call */
    GM_SITE(vm, 274, 4070652);
    /* @4070660 store */
    v44 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v44);
    /* @4070668 load */
    /* @4070676 constant */
    /* @4070680 cmp */
    /* @4070684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4071080;
    /* @4070688 constant */
    /* @4070692 load */
    /* @4070700 cast */
    /* @4070704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4070712 constant */
    /* @4070716 cast */
    /* @4070720 load */
    /* @4070728 load */
    /* @4070736 load */
    /* @4070744 load */
    /* @4070752 call */
    GM_SITE(vm, 274, 4070752);
    /* @4070760 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4070764 load */
    /* @4070772 cast */
    /* @4070776 dup */
    /* @4070780 load */
    /* @4070788 load */
    /* @4070796 sub */
    /* @4070800 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "bladegundamage")));
    /* @4070808 constant */
    /* @4070812 cast */
    /* @4070816 load */
    /* @4070824 load */
    /* @4070832 call */
    GM_SITE(vm, 274, 4070832);
    /* @4070840 store */
    v45 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v45);
    /* @4070848 load */
    /* @4070856 load */
    /* @4070864 cast */
    /* @4070868 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4070876 load */
    /* @4070884 constant */
    /* @4070888 cmp */
    /* @4070892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4070900;
    /* @4070896 b */
    goto L_4070956;
    L_4070900: ;
    /* @4070900 load */
    /* @4070908 constant */
    /* @4070912 cmp */
    /* @4070916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4070956;
    /* @4070920 constant */
    /* @4070924 cast */
    /* @4070928 constant */
    /* @4070932 cast */
    /* @4070936 constant */
    /* @4070940 cast */
    /* @4070944 call */
    GM_SITE(vm, 274, 4070944);
    /* @4070952 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4070956: ;
    /* @4070956 load */
    /* @4070964 cast */
    /* @4070968 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit13")))) goto L_4071004;
    L_4070972: ;
    /* @4070972 constant */
    /* @4070976 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4070984 constant */
    /* @4070988 constant */
    /* @4070992 constant */
    /* @4070996 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4071004: ;
    /* @4071004 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4070972;
    /* @4071008 load */
    /* @4071016 constant */
    /* @4071020 add */
    /* @4071024 store */
    v46 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v46);
    /* @4071032 load */
    /* @4071040 constant */
    /* @4071044 cmp */
    /* @4071048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4071080;
    /* @4071052 constant */
    /* @4071056 load */
    /* @4071064 cast */
    /* @4071068 constant */
    /* @4071072 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4071080: ;
    /* @4071080 constant */
    /* @4071084 cast */
    /* @4071088 load */
    /* @4071096 load */
    /* @4071104 call */
    GM_SITE(vm, 274, 4071104);
    /* @4071112 store */
    v47 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v47);
    /* @4071120 load */
    /* @4071128 constant */
    /* @4071132 cmp */
    /* @4071136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4071532;
    /* @4071140 constant */
    /* @4071144 load */
    /* @4071152 cast */
    /* @4071156 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4071164 constant */
    /* @4071168 cast */
    /* @4071172 load */
    /* @4071180 load */
    /* @4071188 load */
    /* @4071196 load */
    /* @4071204 call */
    GM_SITE(vm, 274, 4071204);
    /* @4071212 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4071216 load */
    /* @4071224 cast */
    /* @4071228 dup */
    /* @4071232 load */
    /* @4071240 load */
    /* @4071248 sub */
    /* @4071252 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "bladegundamage")));
    /* @4071260 constant */
    /* @4071264 cast */
    /* @4071268 load */
    /* @4071276 load */
    /* @4071284 call */
    GM_SITE(vm, 274, 4071284);
    /* @4071292 store */
    v48 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v48);
    /* @4071300 load */
    /* @4071308 load */
    /* @4071316 cast */
    /* @4071320 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4071328 load */
    /* @4071336 constant */
    /* @4071340 cmp */
    /* @4071344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4071352;
    /* @4071348 b */
    goto L_4071408;
    L_4071352: ;
    /* @4071352 load */
    /* @4071360 constant */
    /* @4071364 cmp */
    /* @4071368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4071408;
    /* @4071372 constant */
    /* @4071376 cast */
    /* @4071380 constant */
    /* @4071384 cast */
    /* @4071388 constant */
    /* @4071392 cast */
    /* @4071396 call */
    GM_SITE(vm, 274, 4071396);
    /* @4071404 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4071408: ;
    /* @4071408 load */
    /* @4071416 cast */
    /* @4071420 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "hit14")))) goto L_4071456;
    L_4071424: ;
    /* @4071424 constant */
    /* @4071428 store */
    GM_WRITE(vm, -1, "stunned", VAL(1));
    /* @4071436 constant */
    /* @4071440 constant */
    /* @4071444 constant */
    /* @4071448 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(10));
    L_4071456: ;
    /* @4071456 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4071424;
    /* @4071460 load */
    /* @4071468 constant */
    /* @4071472 add */
    /* @4071476 store */
    v49 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v49);
    /* @4071484 load */
    /* @4071492 constant */
    /* @4071496 cmp */
    /* @4071500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4071532;
    /* @4071504 constant */
    /* @4071508 load */
    /* @4071516 cast */
    /* @4071520 constant */
    /* @4071524 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4071532: ;
    /* @4071532 constant */
    /* @4071536 cast */
    /* @4071540 load */
    /* @4071548 load */
    /* @4071556 call */
    GM_SITE(vm, 274, 4071556);
    /* @4071564 store */
    v50 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v50);
    /* @4071572 load */
    /* @4071580 constant */
    /* @4071584 cmp */
    /* @4071588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4071932;
    /* @4071592 constant */
    /* @4071596 load */
    /* @4071604 cast */
    /* @4071608 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "flashing", VAL(1));
    /* @4071616 constant */
    /* @4071620 cast */
    /* @4071624 load */
    /* @4071632 load */
    /* @4071640 load */
    /* @4071648 load */
    /* @4071656 call */
    GM_SITE(vm, 274, 4071656);
    /* @4071664 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4071668 load */
    /* @4071676 cast */
    /* @4071680 dup */
    /* @4071684 load */
    /* @4071692 load */
    /* @4071700 sub */
    /* @4071704 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit15")), "hpboss2") - GM_READ(vm, -5, "bladegundamage")));
    /* @4071712 constant */
    /* @4071716 cast */
    /* @4071720 load */
    /* @4071728 load */
    /* @4071736 call */
    GM_SITE(vm, 274, 4071736);
    /* @4071744 store */
    v51 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v51);
    /* @4071752 load */
    /* @4071760 load */
    /* @4071768 cast */
    /* @4071772 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4071780 load */
    /* @4071788 constant */
    /* @4071792 cmp */
    /* @4071796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4071804;
    /* @4071800 b */
    goto L_4071860;
    L_4071804: ;
    /* @4071804 load */
    /* @4071812 constant */
    /* @4071816 cmp */
    /* @4071820 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4071860;
    /* @4071824 constant */
    /* @4071828 cast */
    /* @4071832 constant */
    /* @4071836 cast */
    /* @4071840 constant */
    /* @4071844 cast */
    /* @4071848 call */
    GM_SITE(vm, 274, 4071848);
    /* @4071856 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4071860: ;
    /* @4071860 load */
    /* @4071868 constant */
    /* @4071872 add */
    /* @4071876 store */
    v52 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v52);
    /* @4071884 load */
    /* @4071892 constant */
    /* @4071896 cmp */
    /* @4071900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4071932;
    /* @4071904 constant */
    /* @4071908 load */
    /* @4071916 cast */
    /* @4071920 constant */
    /* @4071924 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit15")), "alarm", VAL(6), VAL(1));
    L_4071932: ;
    /* @4071932 constant */
    /* @4071936 cast */
    /* @4071940 load */
    /* @4071948 load */
    /* @4071956 call */
    GM_SITE(vm, 274, 4071956);
    /* @4071964 store */
    v53 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v53);
    /* @4071972 load */
    /* @4071980 constant */
    /* @4071984 cmp */
    /* @4071988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4072284;
    /* @4071992 constant */
    /* @4071996 load */
    /* @4072004 cast */
    /* @4072008 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "flashing", VAL(1));
    /* @4072016 constant */
    /* @4072020 cast */
    /* @4072024 load */
    /* @4072032 load */
    /* @4072040 load */
    /* @4072048 load */
    /* @4072056 call */
    GM_SITE(vm, 274, 4072056);
    /* @4072064 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4072068 load */
    /* @4072076 cast */
    /* @4072080 dup */
    /* @4072084 load */
    /* @4072092 load */
    /* @4072100 sub */
    /* @4072104 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit16")), "hpboss3") - GM_READ(vm, -5, "bladegundamage")));
    /* @4072112 constant */
    /* @4072116 cast */
    /* @4072120 load */
    /* @4072128 load */
    /* @4072136 call */
    GM_SITE(vm, 274, 4072136);
    /* @4072144 store */
    v54 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v54);
    /* @4072152 load */
    /* @4072160 load */
    /* @4072168 cast */
    /* @4072172 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4072180 load */
    /* @4072188 constant */
    /* @4072192 cmp */
    /* @4072196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4072204;
    /* @4072200 b */
    goto L_4072260;
    L_4072204: ;
    /* @4072204 load */
    /* @4072212 constant */
    /* @4072216 cmp */
    /* @4072220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4072260;
    /* @4072224 constant */
    /* @4072228 cast */
    /* @4072232 constant */
    /* @4072236 cast */
    /* @4072240 constant */
    /* @4072244 cast */
    /* @4072248 call */
    GM_SITE(vm, 274, 4072248);
    /* @4072256 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4072260: ;
    /* @4072260 load */
    /* @4072268 constant */
    /* @4072272 add */
    /* @4072276 store */
    v55 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v55);
    L_4072284: ;
    /* @4072284 constant */
    /* @4072288 cast */
    /* @4072292 load */
    /* @4072300 load */
    /* @4072308 call */
    GM_SITE(vm, 274, 4072308);
    /* @4072316 store */
    v56 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v56);
    /* @4072324 load */
    /* @4072332 constant */
    /* @4072336 cmp */
    /* @4072340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4072636;
    /* @4072344 constant */
    /* @4072348 load */
    /* @4072356 cast */
    /* @4072360 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "flashing", VAL(1));
    /* @4072368 constant */
    /* @4072372 cast */
    /* @4072376 load */
    /* @4072384 load */
    /* @4072392 load */
    /* @4072400 load */
    /* @4072408 call */
    GM_SITE(vm, 274, 4072408);
    /* @4072416 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4072420 load */
    /* @4072428 cast */
    /* @4072432 dup */
    /* @4072436 load */
    /* @4072444 load */
    /* @4072452 sub */
    /* @4072456 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss4")), "hpboss4") - GM_READ(vm, -5, "bladegundamage")));
    /* @4072464 constant */
    /* @4072468 cast */
    /* @4072472 load */
    /* @4072480 load */
    /* @4072488 call */
    GM_SITE(vm, 274, 4072488);
    /* @4072496 store */
    v57 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v57);
    /* @4072504 load */
    /* @4072512 load */
    /* @4072520 cast */
    /* @4072524 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4072532 load */
    /* @4072540 constant */
    /* @4072544 cmp */
    /* @4072548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4072556;
    /* @4072552 b */
    goto L_4072612;
    L_4072556: ;
    /* @4072556 load */
    /* @4072564 constant */
    /* @4072568 cmp */
    /* @4072572 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4072612;
    /* @4072576 constant */
    /* @4072580 cast */
    /* @4072584 constant */
    /* @4072588 cast */
    /* @4072592 constant */
    /* @4072596 cast */
    /* @4072600 call */
    GM_SITE(vm, 274, 4072600);
    /* @4072608 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4072612: ;
    /* @4072612 load */
    /* @4072620 constant */
    /* @4072624 add */
    /* @4072628 store */
    v58 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v58);
    L_4072636: ;
    /* @4072636 constant */
    /* @4072640 cast */
    /* @4072644 load */
    /* @4072652 load */
    /* @4072660 call */
    GM_SITE(vm, 274, 4072660);
    /* @4072668 store */
    v59 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v59);
    /* @4072676 load */
    /* @4072684 constant */
    /* @4072688 cmp */
    /* @4072692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4072988;
    /* @4072696 constant */
    /* @4072700 load */
    /* @4072708 cast */
    /* @4072712 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "flashing", VAL(1));
    /* @4072720 constant */
    /* @4072724 cast */
    /* @4072728 load */
    /* @4072736 load */
    /* @4072744 load */
    /* @4072752 load */
    /* @4072760 call */
    GM_SITE(vm, 274, 4072760);
    /* @4072768 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4072772 load */
    /* @4072780 cast */
    /* @4072784 dup */
    /* @4072788 load */
    /* @4072796 load */
    /* @4072804 sub */
    /* @4072808 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitboss5")), "hpboss5") - GM_READ(vm, -5, "bladegundamage")));
    /* @4072816 constant */
    /* @4072820 cast */
    /* @4072824 load */
    /* @4072832 load */
    /* @4072840 call */
    GM_SITE(vm, 274, 4072840);
    /* @4072848 store */
    v60 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v60);
    /* @4072856 load */
    /* @4072864 load */
    /* @4072872 cast */
    /* @4072876 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4072884 load */
    /* @4072892 constant */
    /* @4072896 cmp */
    /* @4072900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4072908;
    /* @4072904 b */
    goto L_4072964;
    L_4072908: ;
    /* @4072908 load */
    /* @4072916 constant */
    /* @4072920 cmp */
    /* @4072924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4072964;
    /* @4072928 constant */
    /* @4072932 cast */
    /* @4072936 constant */
    /* @4072940 cast */
    /* @4072944 constant */
    /* @4072948 cast */
    /* @4072952 call */
    GM_SITE(vm, 274, 4072952);
    /* @4072960 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4072964: ;
    /* @4072964 load */
    /* @4072972 constant */
    /* @4072976 add */
    /* @4072980 store */
    v61 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v61);
    L_4072988: ;
    /* @4072988 constant */
    /* @4072992 cast */
    /* @4072996 load */
    /* @4073004 load */
    /* @4073012 call */
    GM_SITE(vm, 274, 4073012);
    /* @4073020 store */
    v62 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v62);
    /* @4073028 load */
    /* @4073036 constant */
    /* @4073040 cmp */
    /* @4073044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4073340;
    /* @4073048 constant */
    /* @4073052 load */
    /* @4073060 cast */
    /* @4073064 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "flashing", VAL(1));
    /* @4073072 constant */
    /* @4073076 cast */
    /* @4073080 load */
    /* @4073088 load */
    /* @4073096 load */
    /* @4073104 load */
    /* @4073112 call */
    GM_SITE(vm, 274, 4073112);
    /* @4073120 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(3)));
    /* @4073124 load */
    /* @4073132 cast */
    /* @4073136 dup */
    /* @4073140 load */
    /* @4073148 load */
    /* @4073156 sub */
    /* @4073160 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit17")), "hpfinalboss") - GM_READ(vm, -5, "bladegundamage")));
    /* @4073168 constant */
    /* @4073172 cast */
    /* @4073176 load */
    /* @4073184 load */
    /* @4073192 call */
    GM_SITE(vm, 274, 4073192);
    /* @4073200 store */
    v63 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v63);
    /* @4073208 load */
    /* @4073216 load */
    /* @4073224 cast */
    /* @4073228 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bladegundamage"));
    /* @4073236 load */
    /* @4073244 constant */
    /* @4073248 cmp */
    /* @4073252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4073260;
    /* @4073256 b */
    goto L_4073316;
    L_4073260: ;
    /* @4073260 load */
    /* @4073268 constant */
    /* @4073272 cmp */
    /* @4073276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4073316;
    /* @4073280 constant */
    /* @4073284 cast */
    /* @4073288 constant */
    /* @4073292 cast */
    /* @4073296 constant */
    /* @4073300 cast */
    /* @4073304 call */
    GM_SITE(vm, 274, 4073304);
    /* @4073312 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4073316: ;
    /* @4073316 load */
    /* @4073324 constant */
    /* @4073328 add */
    /* @4073332 store */
    v64 = GM_ADD(GM_READ(vm, -5, "bladegunxp"), VAL(1));
    GM_WRITE(vm, -5, "bladegunxp", v64);
    L_4073340: ;
    return;
}
