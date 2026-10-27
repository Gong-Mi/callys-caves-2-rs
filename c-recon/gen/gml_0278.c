/* generated from CODE 278 (gml_Object_obj_bomb_Step_0), source start 4073640, end 4080592. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0278(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val p4073728_0;
    Val v4;
    Val p4073876_0;
    Val v5;
    Val v6;
    Val v7;
    Val p4074336_0;
    Val v8;
    Val v9;
    Val v10;
    Val p4074796_0;
    Val v11;
    Val v12;
    Val v13;
    Val p4075256_0;
    Val v14;
    Val v15;
    Val v16;
    Val v17;
    Val p4075776_0;
    Val v18;
    Val v19;
    Val v20;
    Val p4076236_0;
    Val v21;
    Val v22;
    Val v23;
    Val p4076696_0;
    Val v24;
    Val v25;
    Val v26;
    Val p4077156_0;
    Val v27;
    Val v28;
    Val v29;
    Val p4077616_0;
    Val v30;
    Val v31;
    Val v32;
    Val p4078076_0;
    Val v33;
    Val v34;
    Val v35;
    Val p4078536_0;
    Val v36;
    Val v37;
    Val v38;
    Val p4078996_0;
    Val v39;
    Val v40;
    Val v41;
    Val p4079456_0;
    Val v42;
    Val v43;
    Val v44;
    Val p4079916_0;
    Val v45;
    Val v46;
    Val v47;
    Val v48;
    Val v49;
    Val v50;
    Val v51;
    /* @4073640 constant */
    /* @4073644 cast */
    /* @4073648 load */
    /* @4073656 load */
    /* @4073664 add */
    /* @4073668 load */
    /* @4073676 load */
    /* @4073684 add */
    /* @4073688 call */
    GM_SITE(vm, 278, 4073688);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4073696 cast */
    /* @4073700 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, v1, v2, VAL(34)));
    if (!TRUTH(v3)) goto L_4073724;
    /* @4073704 load */
    /* @4073712 constant */
    /* @4073716 cmp */
    /* @4073720 b */
    p4073728_0 = NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50));
    goto L_4073728;
    L_4073724: ;
    /* @4073724 constant */
    p4073728_0 = VAL(0);
    L_4073728: ;
    /* @4073728 bf */
    if (!TRUTH(p4073728_0)) goto L_4073752;
    /* @4073732 constant */
    /* @4073736 cast */
    /* @4073740 call */
    GM_SITE(vm, 278, 4073740);
    /* @4073748 popz */
    (void)(GM_CALL(vm, "move_bounce_solid", 1, VAL(0)));
    L_4073752: ;
    /* @4073752 load */
    /* @4073760 constant */
    /* @4073764 cmp */
    /* @4073768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50)))) goto L_4073792;
    /* @4073772 constant */
    /* @4073784 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.3));
    L_4073792: ;
    /* @4073792 constant */
    /* @4073796 cast */
    /* @4073800 load */
    /* @4073808 load */
    /* @4073816 call */
    GM_SITE(vm, 278, 4073816);
    /* @4073824 store */
    v4 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(15));
    GM_WRITE(vm, -1, "hitknife", v4);
    /* @4073832 load */
    /* @4073840 constant */
    /* @4073844 cmp */
    /* @4073848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitknife") != VAL(-4)))) goto L_4073872;
    /* @4073852 load */
    /* @4073860 constant */
    /* @4073864 cmp */
    /* @4073868 b */
    p4073876_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4073876;
    L_4073872: ;
    /* @4073872 constant */
    p4073876_0 = VAL(0);
    L_4073876: ;
    /* @4073876 bf */
    if (!TRUTH(p4073876_0)) goto L_4074252;
    /* @4073880 constant */
    /* @4073884 load */
    /* @4073892 cast */
    /* @4073896 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "flashing", VAL(1));
    /* @4073904 constant */
    /* @4073908 cast */
    /* @4073912 load */
    /* @4073920 load */
    /* @4073928 load */
    /* @4073936 load */
    /* @4073944 call */
    GM_SITE(vm, 278, 4073944);
    /* @4073952 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4073956 load */
    /* @4073964 cast */
    /* @4073968 dup */
    /* @4073972 load */
    /* @4073980 load */
    /* @4073988 sub */
    /* @4073992 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "hpknife") - GM_READ(vm, -5, "bombgundamage")));
    /* @4074000 constant */
    /* @4074004 cast */
    /* @4074008 load */
    /* @4074016 load */
    /* @4074024 call */
    GM_SITE(vm, 278, 4074024);
    /* @4074032 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v5);
    /* @4074040 load */
    /* @4074048 load */
    /* @4074056 cast */
    /* @4074060 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4074068 constant */
    /* @4074072 constant */
    /* @4074076 constant */
    /* @4074080 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4074088 load */
    /* @4074096 constant */
    /* @4074100 cmp */
    /* @4074104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4074112;
    /* @4074108 b */
    goto L_4074168;
    L_4074112: ;
    /* @4074112 load */
    /* @4074120 constant */
    /* @4074124 cmp */
    /* @4074128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4074168;
    /* @4074132 constant */
    /* @4074136 cast */
    /* @4074140 constant */
    /* @4074144 cast */
    /* @4074148 constant */
    /* @4074152 cast */
    /* @4074156 call */
    GM_SITE(vm, 278, 4074156);
    /* @4074164 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4074168: ;
    /* @4074168 load */
    /* @4074176 constant */
    /* @4074180 add */
    /* @4074184 store */
    v6 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v6);
    /* @4074192 load */
    /* @4074200 constant */
    /* @4074204 cmp */
    /* @4074208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4074240;
    /* @4074212 constant */
    /* @4074216 load */
    /* @4074224 cast */
    /* @4074228 constant */
    /* @4074232 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitknife")), "alarm", VAL(6), VAL(1));
    L_4074240: ;
    /* @4074240 constant */
    /* @4074244 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4074252: ;
    /* @4074252 constant */
    /* @4074256 cast */
    /* @4074260 load */
    /* @4074268 load */
    /* @4074276 call */
    GM_SITE(vm, 278, 4074276);
    /* @4074284 store */
    v7 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(14));
    GM_WRITE(vm, -1, "hit", v7);
    /* @4074292 load */
    /* @4074300 constant */
    /* @4074304 cmp */
    /* @4074308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit") != VAL(-4)))) goto L_4074332;
    /* @4074312 load */
    /* @4074320 constant */
    /* @4074324 cmp */
    /* @4074328 b */
    p4074336_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4074336;
    L_4074332: ;
    /* @4074332 constant */
    p4074336_0 = VAL(0);
    L_4074336: ;
    /* @4074336 bf */
    if (!TRUTH(p4074336_0)) goto L_4074712;
    /* @4074340 constant */
    /* @4074344 load */
    /* @4074352 cast */
    /* @4074356 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "flashing", VAL(1));
    /* @4074364 constant */
    /* @4074368 cast */
    /* @4074372 load */
    /* @4074380 load */
    /* @4074388 load */
    /* @4074396 load */
    /* @4074404 call */
    GM_SITE(vm, 278, 4074404);
    /* @4074412 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4074416 load */
    /* @4074424 cast */
    /* @4074428 dup */
    /* @4074432 load */
    /* @4074440 load */
    /* @4074448 sub */
    /* @4074452 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit")), "hp") - GM_READ(vm, -5, "bombgundamage")));
    /* @4074460 constant */
    /* @4074464 cast */
    /* @4074468 load */
    /* @4074476 load */
    /* @4074484 call */
    GM_SITE(vm, 278, 4074484);
    /* @4074492 store */
    v8 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v8);
    /* @4074500 load */
    /* @4074508 load */
    /* @4074516 cast */
    /* @4074520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4074528 constant */
    /* @4074532 constant */
    /* @4074536 constant */
    /* @4074540 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4074548 load */
    /* @4074556 constant */
    /* @4074560 cmp */
    /* @4074564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4074572;
    /* @4074568 b */
    goto L_4074628;
    L_4074572: ;
    /* @4074572 load */
    /* @4074580 constant */
    /* @4074584 cmp */
    /* @4074588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4074628;
    /* @4074592 constant */
    /* @4074596 cast */
    /* @4074600 constant */
    /* @4074604 cast */
    /* @4074608 constant */
    /* @4074612 cast */
    /* @4074616 call */
    GM_SITE(vm, 278, 4074616);
    /* @4074624 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4074628: ;
    /* @4074628 load */
    /* @4074636 constant */
    /* @4074640 add */
    /* @4074644 store */
    v9 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v9);
    /* @4074652 load */
    /* @4074660 constant */
    /* @4074664 cmp */
    /* @4074668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4074700;
    /* @4074672 constant */
    /* @4074676 load */
    /* @4074684 cast */
    /* @4074688 constant */
    /* @4074692 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit")), "alarm", VAL(6), VAL(1));
    L_4074700: ;
    /* @4074700 constant */
    /* @4074704 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4074712: ;
    /* @4074712 constant */
    /* @4074716 cast */
    /* @4074720 load */
    /* @4074728 load */
    /* @4074736 call */
    GM_SITE(vm, 278, 4074736);
    /* @4074744 store */
    v10 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(23));
    GM_WRITE(vm, -1, "hitwolf", v10);
    /* @4074752 load */
    /* @4074760 constant */
    /* @4074764 cmp */
    /* @4074768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitwolf") != VAL(-4)))) goto L_4074792;
    /* @4074772 load */
    /* @4074780 constant */
    /* @4074784 cmp */
    /* @4074788 b */
    p4074796_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4074796;
    L_4074792: ;
    /* @4074792 constant */
    p4074796_0 = VAL(0);
    L_4074796: ;
    /* @4074796 bf */
    if (!TRUTH(p4074796_0)) goto L_4075172;
    /* @4074800 constant */
    /* @4074804 load */
    /* @4074812 cast */
    /* @4074816 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "flashing", VAL(1));
    /* @4074824 constant */
    /* @4074828 cast */
    /* @4074832 load */
    /* @4074840 load */
    /* @4074848 load */
    /* @4074856 load */
    /* @4074864 call */
    GM_SITE(vm, 278, 4074864);
    /* @4074872 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4074876 load */
    /* @4074884 cast */
    /* @4074888 dup */
    /* @4074892 load */
    /* @4074900 load */
    /* @4074908 sub */
    /* @4074912 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "hpwolf") - GM_READ(vm, -5, "bombgundamage")));
    /* @4074920 constant */
    /* @4074924 cast */
    /* @4074928 load */
    /* @4074936 load */
    /* @4074944 call */
    GM_SITE(vm, 278, 4074944);
    /* @4074952 store */
    v11 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v11);
    /* @4074960 load */
    /* @4074968 load */
    /* @4074976 cast */
    /* @4074980 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4074988 constant */
    /* @4074992 constant */
    /* @4074996 constant */
    /* @4075000 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4075008 load */
    /* @4075016 constant */
    /* @4075020 cmp */
    /* @4075024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4075032;
    /* @4075028 b */
    goto L_4075088;
    L_4075032: ;
    /* @4075032 load */
    /* @4075040 constant */
    /* @4075044 cmp */
    /* @4075048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4075088;
    /* @4075052 constant */
    /* @4075056 cast */
    /* @4075060 constant */
    /* @4075064 cast */
    /* @4075068 constant */
    /* @4075072 cast */
    /* @4075076 call */
    GM_SITE(vm, 278, 4075076);
    /* @4075084 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4075088: ;
    /* @4075088 load */
    /* @4075096 constant */
    /* @4075100 add */
    /* @4075104 store */
    v12 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v12);
    /* @4075112 load */
    /* @4075120 constant */
    /* @4075124 cmp */
    /* @4075128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4075160;
    /* @4075132 constant */
    /* @4075136 load */
    /* @4075144 cast */
    /* @4075148 constant */
    /* @4075152 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hitwolf")), "alarm", VAL(6), VAL(1));
    L_4075160: ;
    /* @4075160 constant */
    /* @4075164 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4075172: ;
    /* @4075172 constant */
    /* @4075176 cast */
    /* @4075180 load */
    /* @4075188 load */
    /* @4075196 call */
    GM_SITE(vm, 278, 4075196);
    /* @4075204 store */
    v13 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(22));
    GM_WRITE(vm, -1, "hit2", v13);
    /* @4075212 load */
    /* @4075220 constant */
    /* @4075224 cmp */
    /* @4075228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit2") != VAL(-4)))) goto L_4075252;
    /* @4075232 load */
    /* @4075240 constant */
    /* @4075244 cmp */
    /* @4075248 b */
    p4075256_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4075256;
    L_4075252: ;
    /* @4075252 constant */
    p4075256_0 = VAL(0);
    L_4075256: ;
    /* @4075256 bf */
    if (!TRUTH(p4075256_0)) goto L_4075632;
    /* @4075260 constant */
    /* @4075264 load */
    /* @4075272 cast */
    /* @4075276 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "flashing", VAL(1));
    /* @4075284 constant */
    /* @4075288 cast */
    /* @4075292 load */
    /* @4075300 load */
    /* @4075308 load */
    /* @4075316 load */
    /* @4075324 call */
    GM_SITE(vm, 278, 4075324);
    /* @4075332 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4075336 load */
    /* @4075344 cast */
    /* @4075348 dup */
    /* @4075352 load */
    /* @4075360 load */
    /* @4075368 sub */
    /* @4075372 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit2")), "hptwo") - GM_READ(vm, -5, "bombgundamage")));
    /* @4075380 constant */
    /* @4075384 cast */
    /* @4075388 load */
    /* @4075396 load */
    /* @4075404 call */
    GM_SITE(vm, 278, 4075404);
    /* @4075412 store */
    v14 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v14);
    /* @4075420 load */
    /* @4075428 load */
    /* @4075436 cast */
    /* @4075440 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4075448 constant */
    /* @4075452 constant */
    /* @4075456 constant */
    /* @4075460 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4075468 load */
    /* @4075476 constant */
    /* @4075480 cmp */
    /* @4075484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4075492;
    /* @4075488 b */
    goto L_4075548;
    L_4075492: ;
    /* @4075492 load */
    /* @4075500 constant */
    /* @4075504 cmp */
    /* @4075508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4075548;
    /* @4075512 constant */
    /* @4075516 cast */
    /* @4075520 constant */
    /* @4075524 cast */
    /* @4075528 constant */
    /* @4075532 cast */
    /* @4075536 call */
    GM_SITE(vm, 278, 4075536);
    /* @4075544 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4075548: ;
    /* @4075548 load */
    /* @4075556 constant */
    /* @4075560 add */
    /* @4075564 store */
    v15 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v15);
    /* @4075572 load */
    /* @4075580 constant */
    /* @4075584 cmp */
    /* @4075588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4075620;
    /* @4075592 constant */
    /* @4075596 load */
    /* @4075604 cast */
    /* @4075608 constant */
    /* @4075612 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit2")), "alarm", VAL(6), VAL(1));
    L_4075620: ;
    /* @4075620 constant */
    /* @4075624 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4075632: ;
    /* @4075632 constant */
    /* @4075636 cast */
    /* @4075640 load */
    /* @4075648 load */
    /* @4075656 call */
    GM_SITE(vm, 278, 4075656);
    /* @4075664 store */
    v16 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(25));
    GM_WRITE(vm, -1, "hittrex", v16);
    /* @4075672 load */
    /* @4075680 constant */
    /* @4075684 cmp */
    /* @4075688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hittrex") != VAL(-4)))) goto L_4075692;
    L_4075692: ;
    /* @4075692 constant */
    /* @4075696 cast */
    /* @4075700 load */
    /* @4075708 load */
    /* @4075716 call */
    GM_SITE(vm, 278, 4075716);
    /* @4075724 store */
    v17 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(31));
    GM_WRITE(vm, -1, "hit4", v17);
    /* @4075732 load */
    /* @4075740 constant */
    /* @4075744 cmp */
    /* @4075748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit4") != VAL(-4)))) goto L_4075772;
    /* @4075752 load */
    /* @4075760 constant */
    /* @4075764 cmp */
    /* @4075768 b */
    p4075776_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4075776;
    L_4075772: ;
    /* @4075772 constant */
    p4075776_0 = VAL(0);
    L_4075776: ;
    /* @4075776 bf */
    if (!TRUTH(p4075776_0)) goto L_4076152;
    /* @4075780 constant */
    /* @4075784 load */
    /* @4075792 cast */
    /* @4075796 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "flashing", VAL(1));
    /* @4075804 constant */
    /* @4075808 cast */
    /* @4075812 load */
    /* @4075820 load */
    /* @4075828 load */
    /* @4075836 load */
    /* @4075844 call */
    GM_SITE(vm, 278, 4075844);
    /* @4075852 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4075856 load */
    /* @4075864 cast */
    /* @4075868 dup */
    /* @4075872 load */
    /* @4075880 load */
    /* @4075888 sub */
    /* @4075892 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit4")), "hpfour") - GM_READ(vm, -5, "bombgundamage")));
    /* @4075900 constant */
    /* @4075904 cast */
    /* @4075908 load */
    /* @4075916 load */
    /* @4075924 call */
    GM_SITE(vm, 278, 4075924);
    /* @4075932 store */
    v18 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v18);
    /* @4075940 load */
    /* @4075948 load */
    /* @4075956 cast */
    /* @4075960 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4075968 constant */
    /* @4075972 constant */
    /* @4075976 constant */
    /* @4075980 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4075988 load */
    /* @4075996 constant */
    /* @4076000 cmp */
    /* @4076004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4076012;
    /* @4076008 b */
    goto L_4076068;
    L_4076012: ;
    /* @4076012 load */
    /* @4076020 constant */
    /* @4076024 cmp */
    /* @4076028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4076068;
    /* @4076032 constant */
    /* @4076036 cast */
    /* @4076040 constant */
    /* @4076044 cast */
    /* @4076048 constant */
    /* @4076052 cast */
    /* @4076056 call */
    GM_SITE(vm, 278, 4076056);
    /* @4076064 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4076068: ;
    /* @4076068 load */
    /* @4076076 constant */
    /* @4076080 add */
    /* @4076084 store */
    v19 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v19);
    /* @4076092 load */
    /* @4076100 constant */
    /* @4076104 cmp */
    /* @4076108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4076140;
    /* @4076112 constant */
    /* @4076116 load */
    /* @4076124 cast */
    /* @4076128 constant */
    /* @4076132 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit4")), "alarm", VAL(6), VAL(1));
    L_4076140: ;
    /* @4076140 constant */
    /* @4076144 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4076152: ;
    /* @4076152 constant */
    /* @4076156 cast */
    /* @4076160 load */
    /* @4076168 load */
    /* @4076176 call */
    GM_SITE(vm, 278, 4076176);
    /* @4076184 store */
    v20 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "hit5", v20);
    /* @4076192 load */
    /* @4076200 constant */
    /* @4076204 cmp */
    /* @4076208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit5") != VAL(-4)))) goto L_4076232;
    /* @4076212 load */
    /* @4076220 constant */
    /* @4076224 cmp */
    /* @4076228 b */
    p4076236_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4076236;
    L_4076232: ;
    /* @4076232 constant */
    p4076236_0 = VAL(0);
    L_4076236: ;
    /* @4076236 bf */
    if (!TRUTH(p4076236_0)) goto L_4076612;
    /* @4076240 constant */
    /* @4076244 load */
    /* @4076252 cast */
    /* @4076256 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "flashing", VAL(1));
    /* @4076264 constant */
    /* @4076268 cast */
    /* @4076272 load */
    /* @4076280 load */
    /* @4076288 load */
    /* @4076296 load */
    /* @4076304 call */
    GM_SITE(vm, 278, 4076304);
    /* @4076312 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4076316 load */
    /* @4076324 cast */
    /* @4076328 dup */
    /* @4076332 load */
    /* @4076340 load */
    /* @4076348 sub */
    /* @4076352 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit5")), "hpslime") - GM_READ(vm, -5, "bombgundamage")));
    /* @4076360 constant */
    /* @4076364 cast */
    /* @4076368 load */
    /* @4076376 load */
    /* @4076384 call */
    GM_SITE(vm, 278, 4076384);
    /* @4076392 store */
    v21 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v21);
    /* @4076400 load */
    /* @4076408 load */
    /* @4076416 cast */
    /* @4076420 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4076428 constant */
    /* @4076432 constant */
    /* @4076436 constant */
    /* @4076440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4076448 load */
    /* @4076456 constant */
    /* @4076460 cmp */
    /* @4076464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4076472;
    /* @4076468 b */
    goto L_4076528;
    L_4076472: ;
    /* @4076472 load */
    /* @4076480 constant */
    /* @4076484 cmp */
    /* @4076488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4076528;
    /* @4076492 constant */
    /* @4076496 cast */
    /* @4076500 constant */
    /* @4076504 cast */
    /* @4076508 constant */
    /* @4076512 cast */
    /* @4076516 call */
    GM_SITE(vm, 278, 4076516);
    /* @4076524 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4076528: ;
    /* @4076528 load */
    /* @4076536 constant */
    /* @4076540 add */
    /* @4076544 store */
    v22 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v22);
    /* @4076552 load */
    /* @4076560 constant */
    /* @4076564 cmp */
    /* @4076568 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4076600;
    /* @4076572 constant */
    /* @4076576 load */
    /* @4076584 cast */
    /* @4076588 constant */
    /* @4076592 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit5")), "alarm", VAL(6), VAL(1));
    L_4076600: ;
    /* @4076600 constant */
    /* @4076604 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4076612: ;
    /* @4076612 constant */
    /* @4076616 cast */
    /* @4076620 load */
    /* @4076628 load */
    /* @4076636 call */
    GM_SITE(vm, 278, 4076636);
    /* @4076644 store */
    v23 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(24));
    GM_WRITE(vm, -1, "hit7", v23);
    /* @4076652 load */
    /* @4076660 constant */
    /* @4076664 cmp */
    /* @4076668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit7") != VAL(-4)))) goto L_4076692;
    /* @4076672 load */
    /* @4076680 constant */
    /* @4076684 cmp */
    /* @4076688 b */
    p4076696_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4076696;
    L_4076692: ;
    /* @4076692 constant */
    p4076696_0 = VAL(0);
    L_4076696: ;
    /* @4076696 bf */
    if (!TRUTH(p4076696_0)) goto L_4077072;
    /* @4076700 constant */
    /* @4076704 load */
    /* @4076712 cast */
    /* @4076716 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "flashing", VAL(1));
    /* @4076724 constant */
    /* @4076728 cast */
    /* @4076732 load */
    /* @4076740 load */
    /* @4076748 load */
    /* @4076756 load */
    /* @4076764 call */
    GM_SITE(vm, 278, 4076764);
    /* @4076772 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4076776 load */
    /* @4076784 cast */
    /* @4076788 dup */
    /* @4076792 load */
    /* @4076800 load */
    /* @4076808 sub */
    /* @4076812 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit7")), "hpghost") - GM_READ(vm, -5, "bombgundamage")));
    /* @4076820 constant */
    /* @4076824 cast */
    /* @4076828 load */
    /* @4076836 load */
    /* @4076844 call */
    GM_SITE(vm, 278, 4076844);
    /* @4076852 store */
    v24 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v24);
    /* @4076860 load */
    /* @4076868 load */
    /* @4076876 cast */
    /* @4076880 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4076888 constant */
    /* @4076892 constant */
    /* @4076896 constant */
    /* @4076900 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4076908 load */
    /* @4076916 constant */
    /* @4076920 cmp */
    /* @4076924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4076932;
    /* @4076928 b */
    goto L_4076988;
    L_4076932: ;
    /* @4076932 load */
    /* @4076940 constant */
    /* @4076944 cmp */
    /* @4076948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4076988;
    /* @4076952 constant */
    /* @4076956 cast */
    /* @4076960 constant */
    /* @4076964 cast */
    /* @4076968 constant */
    /* @4076972 cast */
    /* @4076976 call */
    GM_SITE(vm, 278, 4076976);
    /* @4076984 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4076988: ;
    /* @4076988 load */
    /* @4076996 constant */
    /* @4077000 add */
    /* @4077004 store */
    v25 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v25);
    /* @4077012 load */
    /* @4077020 constant */
    /* @4077024 cmp */
    /* @4077028 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4077060;
    /* @4077032 constant */
    /* @4077036 load */
    /* @4077044 cast */
    /* @4077048 constant */
    /* @4077052 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit7")), "alarm", VAL(6), VAL(1));
    L_4077060: ;
    /* @4077060 constant */
    /* @4077064 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4077072: ;
    /* @4077072 constant */
    /* @4077076 cast */
    /* @4077080 load */
    /* @4077088 load */
    /* @4077096 call */
    GM_SITE(vm, 278, 4077096);
    /* @4077104 store */
    v26 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(16));
    GM_WRITE(vm, -1, "hit8", v26);
    /* @4077112 load */
    /* @4077120 constant */
    /* @4077124 cmp */
    /* @4077128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit8") != VAL(-4)))) goto L_4077152;
    /* @4077132 load */
    /* @4077140 constant */
    /* @4077144 cmp */
    /* @4077148 b */
    p4077156_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4077156;
    L_4077152: ;
    /* @4077152 constant */
    p4077156_0 = VAL(0);
    L_4077156: ;
    /* @4077156 bf */
    if (!TRUTH(p4077156_0)) goto L_4077532;
    /* @4077160 constant */
    /* @4077164 load */
    /* @4077172 cast */
    /* @4077176 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "flashing", VAL(1));
    /* @4077184 constant */
    /* @4077188 cast */
    /* @4077192 load */
    /* @4077200 load */
    /* @4077208 load */
    /* @4077216 load */
    /* @4077224 call */
    GM_SITE(vm, 278, 4077224);
    /* @4077232 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4077236 load */
    /* @4077244 cast */
    /* @4077248 dup */
    /* @4077252 load */
    /* @4077260 load */
    /* @4077268 sub */
    /* @4077272 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit8")), "hpshooter1") - GM_READ(vm, -5, "bombgundamage")));
    /* @4077280 constant */
    /* @4077284 cast */
    /* @4077288 load */
    /* @4077296 load */
    /* @4077304 call */
    GM_SITE(vm, 278, 4077304);
    /* @4077312 store */
    v27 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v27);
    /* @4077320 load */
    /* @4077328 load */
    /* @4077336 cast */
    /* @4077340 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4077348 constant */
    /* @4077352 constant */
    /* @4077356 constant */
    /* @4077360 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4077368 load */
    /* @4077376 constant */
    /* @4077380 cmp */
    /* @4077384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4077392;
    /* @4077388 b */
    goto L_4077448;
    L_4077392: ;
    /* @4077392 load */
    /* @4077400 constant */
    /* @4077404 cmp */
    /* @4077408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4077448;
    /* @4077412 constant */
    /* @4077416 cast */
    /* @4077420 constant */
    /* @4077424 cast */
    /* @4077428 constant */
    /* @4077432 cast */
    /* @4077436 call */
    GM_SITE(vm, 278, 4077436);
    /* @4077444 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4077448: ;
    /* @4077448 load */
    /* @4077456 constant */
    /* @4077460 add */
    /* @4077464 store */
    v28 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v28);
    /* @4077472 load */
    /* @4077480 constant */
    /* @4077484 cmp */
    /* @4077488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4077520;
    /* @4077492 constant */
    /* @4077496 load */
    /* @4077504 cast */
    /* @4077508 constant */
    /* @4077512 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit8")), "alarm", VAL(6), VAL(1));
    L_4077520: ;
    /* @4077520 constant */
    /* @4077524 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4077532: ;
    /* @4077532 constant */
    /* @4077536 cast */
    /* @4077540 load */
    /* @4077548 load */
    /* @4077556 call */
    GM_SITE(vm, 278, 4077556);
    /* @4077564 store */
    v29 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(20));
    GM_WRITE(vm, -1, "hit9", v29);
    /* @4077572 load */
    /* @4077580 constant */
    /* @4077584 cmp */
    /* @4077588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit9") != VAL(-4)))) goto L_4077612;
    /* @4077592 load */
    /* @4077600 constant */
    /* @4077604 cmp */
    /* @4077608 b */
    p4077616_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4077616;
    L_4077612: ;
    /* @4077612 constant */
    p4077616_0 = VAL(0);
    L_4077616: ;
    /* @4077616 bf */
    if (!TRUTH(p4077616_0)) goto L_4077992;
    /* @4077620 constant */
    /* @4077624 load */
    /* @4077632 cast */
    /* @4077636 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "flashing", VAL(1));
    /* @4077644 constant */
    /* @4077648 cast */
    /* @4077652 load */
    /* @4077660 load */
    /* @4077668 load */
    /* @4077676 load */
    /* @4077684 call */
    GM_SITE(vm, 278, 4077684);
    /* @4077692 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4077696 load */
    /* @4077704 cast */
    /* @4077708 dup */
    /* @4077712 load */
    /* @4077720 load */
    /* @4077728 sub */
    /* @4077732 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit9")), "hpshooter2") - GM_READ(vm, -5, "bombgundamage")));
    /* @4077740 constant */
    /* @4077744 cast */
    /* @4077748 load */
    /* @4077756 load */
    /* @4077764 call */
    GM_SITE(vm, 278, 4077764);
    /* @4077772 store */
    v30 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v30);
    /* @4077780 load */
    /* @4077788 load */
    /* @4077796 cast */
    /* @4077800 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4077808 constant */
    /* @4077812 constant */
    /* @4077816 constant */
    /* @4077820 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4077828 load */
    /* @4077836 constant */
    /* @4077840 cmp */
    /* @4077844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4077852;
    /* @4077848 b */
    goto L_4077908;
    L_4077852: ;
    /* @4077852 load */
    /* @4077860 constant */
    /* @4077864 cmp */
    /* @4077868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4077908;
    /* @4077872 constant */
    /* @4077876 cast */
    /* @4077880 constant */
    /* @4077884 cast */
    /* @4077888 constant */
    /* @4077892 cast */
    /* @4077896 call */
    GM_SITE(vm, 278, 4077896);
    /* @4077904 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4077908: ;
    /* @4077908 load */
    /* @4077916 constant */
    /* @4077920 add */
    /* @4077924 store */
    v31 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v31);
    /* @4077932 load */
    /* @4077940 constant */
    /* @4077944 cmp */
    /* @4077948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4077980;
    /* @4077952 constant */
    /* @4077956 load */
    /* @4077964 cast */
    /* @4077968 constant */
    /* @4077972 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit9")), "alarm", VAL(7), VAL(1));
    L_4077980: ;
    /* @4077980 constant */
    /* @4077984 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4077992: ;
    /* @4077992 constant */
    /* @4077996 cast */
    /* @4078000 load */
    /* @4078008 load */
    /* @4078016 call */
    GM_SITE(vm, 278, 4078016);
    /* @4078024 store */
    v32 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(33));
    GM_WRITE(vm, -1, "hit10", v32);
    /* @4078032 load */
    /* @4078040 constant */
    /* @4078044 cmp */
    /* @4078048 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit10") != VAL(-4)))) goto L_4078072;
    /* @4078052 load */
    /* @4078060 constant */
    /* @4078064 cmp */
    /* @4078068 b */
    p4078076_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4078076;
    L_4078072: ;
    /* @4078072 constant */
    p4078076_0 = VAL(0);
    L_4078076: ;
    /* @4078076 bf */
    if (!TRUTH(p4078076_0)) goto L_4078452;
    /* @4078080 constant */
    /* @4078084 load */
    /* @4078092 cast */
    /* @4078096 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "flashing", VAL(1));
    /* @4078104 constant */
    /* @4078108 cast */
    /* @4078112 load */
    /* @4078120 load */
    /* @4078128 load */
    /* @4078136 load */
    /* @4078144 call */
    GM_SITE(vm, 278, 4078144);
    /* @4078152 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4078156 load */
    /* @4078164 cast */
    /* @4078168 dup */
    /* @4078172 load */
    /* @4078180 load */
    /* @4078188 sub */
    /* @4078192 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit10")), "hpfireslime") - GM_READ(vm, -5, "bombgundamage")));
    /* @4078200 constant */
    /* @4078204 cast */
    /* @4078208 load */
    /* @4078216 load */
    /* @4078224 call */
    GM_SITE(vm, 278, 4078224);
    /* @4078232 store */
    v33 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v33);
    /* @4078240 load */
    /* @4078248 load */
    /* @4078256 cast */
    /* @4078260 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4078268 constant */
    /* @4078272 constant */
    /* @4078276 constant */
    /* @4078280 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4078288 load */
    /* @4078296 constant */
    /* @4078300 cmp */
    /* @4078304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4078312;
    /* @4078308 b */
    goto L_4078368;
    L_4078312: ;
    /* @4078312 load */
    /* @4078320 constant */
    /* @4078324 cmp */
    /* @4078328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4078368;
    /* @4078332 constant */
    /* @4078336 cast */
    /* @4078340 constant */
    /* @4078344 cast */
    /* @4078348 constant */
    /* @4078352 cast */
    /* @4078356 call */
    GM_SITE(vm, 278, 4078356);
    /* @4078364 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4078368: ;
    /* @4078368 load */
    /* @4078376 constant */
    /* @4078380 add */
    /* @4078384 store */
    v34 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v34);
    /* @4078392 load */
    /* @4078400 constant */
    /* @4078404 cmp */
    /* @4078408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4078440;
    /* @4078412 constant */
    /* @4078416 load */
    /* @4078424 cast */
    /* @4078428 constant */
    /* @4078432 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit10")), "alarm", VAL(6), VAL(1));
    L_4078440: ;
    /* @4078440 constant */
    /* @4078444 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4078452: ;
    /* @4078452 constant */
    /* @4078456 cast */
    /* @4078460 load */
    /* @4078468 load */
    /* @4078476 call */
    GM_SITE(vm, 278, 4078476);
    /* @4078484 store */
    v35 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(21));
    GM_WRITE(vm, -1, "hit11", v35);
    /* @4078492 load */
    /* @4078500 constant */
    /* @4078504 cmp */
    /* @4078508 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit11") != VAL(-4)))) goto L_4078532;
    /* @4078512 load */
    /* @4078520 constant */
    /* @4078524 cmp */
    /* @4078528 b */
    p4078536_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4078536;
    L_4078532: ;
    /* @4078532 constant */
    p4078536_0 = VAL(0);
    L_4078536: ;
    /* @4078536 bf */
    if (!TRUTH(p4078536_0)) goto L_4078912;
    /* @4078540 constant */
    /* @4078544 load */
    /* @4078552 cast */
    /* @4078556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "flashing", VAL(1));
    /* @4078564 constant */
    /* @4078568 cast */
    /* @4078572 load */
    /* @4078580 load */
    /* @4078588 load */
    /* @4078596 load */
    /* @4078604 call */
    GM_SITE(vm, 278, 4078604);
    /* @4078612 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4078616 load */
    /* @4078624 cast */
    /* @4078628 dup */
    /* @4078632 load */
    /* @4078640 load */
    /* @4078648 sub */
    /* @4078652 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit11")), "hphulkingbandit") - GM_READ(vm, -5, "bombgundamage")));
    /* @4078660 constant */
    /* @4078664 cast */
    /* @4078668 load */
    /* @4078676 load */
    /* @4078684 call */
    GM_SITE(vm, 278, 4078684);
    /* @4078692 store */
    v36 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v36);
    /* @4078700 load */
    /* @4078708 load */
    /* @4078716 cast */
    /* @4078720 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4078728 constant */
    /* @4078732 constant */
    /* @4078736 constant */
    /* @4078740 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4078748 load */
    /* @4078756 constant */
    /* @4078760 cmp */
    /* @4078764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4078772;
    /* @4078768 b */
    goto L_4078828;
    L_4078772: ;
    /* @4078772 load */
    /* @4078780 constant */
    /* @4078784 cmp */
    /* @4078788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4078828;
    /* @4078792 constant */
    /* @4078796 cast */
    /* @4078800 constant */
    /* @4078804 cast */
    /* @4078808 constant */
    /* @4078812 cast */
    /* @4078816 call */
    GM_SITE(vm, 278, 4078816);
    /* @4078824 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4078828: ;
    /* @4078828 load */
    /* @4078836 constant */
    /* @4078840 add */
    /* @4078844 store */
    v37 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v37);
    /* @4078852 load */
    /* @4078860 constant */
    /* @4078864 cmp */
    /* @4078868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4078900;
    /* @4078872 constant */
    /* @4078876 load */
    /* @4078884 cast */
    /* @4078888 constant */
    /* @4078892 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit11")), "alarm", VAL(6), VAL(1));
    L_4078900: ;
    /* @4078900 constant */
    /* @4078904 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4078912: ;
    /* @4078912 constant */
    /* @4078916 cast */
    /* @4078920 load */
    /* @4078928 load */
    /* @4078936 call */
    GM_SITE(vm, 278, 4078936);
    /* @4078944 store */
    v38 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(19));
    GM_WRITE(vm, -1, "hit12", v38);
    /* @4078952 load */
    /* @4078960 constant */
    /* @4078964 cmp */
    /* @4078968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit12") != VAL(-4)))) goto L_4078992;
    /* @4078972 load */
    /* @4078980 constant */
    /* @4078984 cmp */
    /* @4078988 b */
    p4078996_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4078996;
    L_4078992: ;
    /* @4078992 constant */
    p4078996_0 = VAL(0);
    L_4078996: ;
    /* @4078996 bf */
    if (!TRUTH(p4078996_0)) goto L_4079372;
    /* @4079000 constant */
    /* @4079004 load */
    /* @4079012 cast */
    /* @4079016 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "flashing", VAL(1));
    /* @4079024 constant */
    /* @4079028 cast */
    /* @4079032 load */
    /* @4079040 load */
    /* @4079048 load */
    /* @4079056 load */
    /* @4079064 call */
    GM_SITE(vm, 278, 4079064);
    /* @4079072 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4079076 load */
    /* @4079084 cast */
    /* @4079088 dup */
    /* @4079092 load */
    /* @4079100 load */
    /* @4079108 sub */
    /* @4079112 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit12")), "hpzombie") - GM_READ(vm, -5, "bombgundamage")));
    /* @4079120 constant */
    /* @4079124 cast */
    /* @4079128 load */
    /* @4079136 load */
    /* @4079144 call */
    GM_SITE(vm, 278, 4079144);
    /* @4079152 store */
    v39 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v39);
    /* @4079160 load */
    /* @4079168 load */
    /* @4079176 cast */
    /* @4079180 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4079188 constant */
    /* @4079192 constant */
    /* @4079196 constant */
    /* @4079200 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4079208 load */
    /* @4079216 constant */
    /* @4079220 cmp */
    /* @4079224 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4079232;
    /* @4079228 b */
    goto L_4079288;
    L_4079232: ;
    /* @4079232 load */
    /* @4079240 constant */
    /* @4079244 cmp */
    /* @4079248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4079288;
    /* @4079252 constant */
    /* @4079256 cast */
    /* @4079260 constant */
    /* @4079264 cast */
    /* @4079268 constant */
    /* @4079272 cast */
    /* @4079276 call */
    GM_SITE(vm, 278, 4079276);
    /* @4079284 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4079288: ;
    /* @4079288 load */
    /* @4079296 constant */
    /* @4079300 add */
    /* @4079304 store */
    v40 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v40);
    /* @4079312 load */
    /* @4079320 constant */
    /* @4079324 cmp */
    /* @4079328 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4079360;
    /* @4079332 constant */
    /* @4079336 load */
    /* @4079344 cast */
    /* @4079348 constant */
    /* @4079352 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit12")), "alarm", VAL(6), VAL(1));
    L_4079360: ;
    /* @4079360 constant */
    /* @4079364 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4079372: ;
    /* @4079372 constant */
    /* @4079376 cast */
    /* @4079380 load */
    /* @4079388 load */
    /* @4079396 call */
    GM_SITE(vm, 278, 4079396);
    /* @4079404 store */
    v41 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(18));
    GM_WRITE(vm, -1, "hit13", v41);
    /* @4079412 load */
    /* @4079420 constant */
    /* @4079424 cmp */
    /* @4079428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit13") != VAL(-4)))) goto L_4079452;
    /* @4079432 load */
    /* @4079440 constant */
    /* @4079444 cmp */
    /* @4079448 b */
    p4079456_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4079456;
    L_4079452: ;
    /* @4079452 constant */
    p4079456_0 = VAL(0);
    L_4079456: ;
    /* @4079456 bf */
    if (!TRUTH(p4079456_0)) goto L_4079832;
    /* @4079460 constant */
    /* @4079464 load */
    /* @4079472 cast */
    /* @4079476 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "flashing", VAL(1));
    /* @4079484 constant */
    /* @4079488 cast */
    /* @4079492 load */
    /* @4079500 load */
    /* @4079508 load */
    /* @4079516 load */
    /* @4079524 call */
    GM_SITE(vm, 278, 4079524);
    /* @4079532 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4079536 load */
    /* @4079544 cast */
    /* @4079548 dup */
    /* @4079552 load */
    /* @4079560 load */
    /* @4079568 sub */
    /* @4079572 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit13")), "hpfirehulk") - GM_READ(vm, -5, "bombgundamage")));
    /* @4079580 constant */
    /* @4079584 cast */
    /* @4079588 load */
    /* @4079596 load */
    /* @4079604 call */
    GM_SITE(vm, 278, 4079604);
    /* @4079612 store */
    v42 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v42);
    /* @4079620 load */
    /* @4079628 load */
    /* @4079636 cast */
    /* @4079640 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4079648 constant */
    /* @4079652 constant */
    /* @4079656 constant */
    /* @4079660 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4079668 load */
    /* @4079676 constant */
    /* @4079680 cmp */
    /* @4079684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4079692;
    /* @4079688 b */
    goto L_4079748;
    L_4079692: ;
    /* @4079692 load */
    /* @4079700 constant */
    /* @4079704 cmp */
    /* @4079708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4079748;
    /* @4079712 constant */
    /* @4079716 cast */
    /* @4079720 constant */
    /* @4079724 cast */
    /* @4079728 constant */
    /* @4079732 cast */
    /* @4079736 call */
    GM_SITE(vm, 278, 4079736);
    /* @4079744 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4079748: ;
    /* @4079748 load */
    /* @4079756 constant */
    /* @4079760 add */
    /* @4079764 store */
    v43 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v43);
    /* @4079772 load */
    /* @4079780 constant */
    /* @4079784 cmp */
    /* @4079788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4079820;
    /* @4079792 constant */
    /* @4079796 load */
    /* @4079804 cast */
    /* @4079808 constant */
    /* @4079812 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit13")), "alarm", VAL(7), VAL(1));
    L_4079820: ;
    /* @4079820 constant */
    /* @4079824 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4079832: ;
    /* @4079832 constant */
    /* @4079836 cast */
    /* @4079840 load */
    /* @4079848 load */
    /* @4079856 call */
    GM_SITE(vm, 278, 4079856);
    /* @4079864 store */
    v44 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(17));
    GM_WRITE(vm, -1, "hit14", v44);
    /* @4079872 load */
    /* @4079880 constant */
    /* @4079884 cmp */
    /* @4079888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit14") != VAL(-4)))) goto L_4079912;
    /* @4079892 load */
    /* @4079900 constant */
    /* @4079904 cmp */
    /* @4079908 b */
    p4079916_0 = NUMBOOL(GM_READ(vm, -1, "canhit") == VAL(0));
    goto L_4079916;
    L_4079912: ;
    /* @4079912 constant */
    p4079916_0 = VAL(0);
    L_4079916: ;
    /* @4079916 bf */
    if (!TRUTH(p4079916_0)) goto L_4080292;
    /* @4079920 constant */
    /* @4079924 load */
    /* @4079932 cast */
    /* @4079936 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "flashing", VAL(1));
    /* @4079944 constant */
    /* @4079948 cast */
    /* @4079952 load */
    /* @4079960 load */
    /* @4079968 load */
    /* @4079976 load */
    /* @4079984 call */
    GM_SITE(vm, 278, 4079984);
    /* @4079992 popz */
    (void)(GM_CALL(vm, "part_particles_create", 5, GM_READ(vm, -5, "P_System"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, -5, "Particle1"), VAL(4)));
    /* @4079996 load */
    /* @4080004 cast */
    /* @4080008 dup */
    /* @4080012 load */
    /* @4080020 load */
    /* @4080028 sub */
    /* @4080032 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton", (GM_READ(vm, TO_INT(GM_READ(vm, -1, "hit14")), "hpskeleton") - GM_READ(vm, -5, "bombgundamage")));
    /* @4080040 constant */
    /* @4080044 cast */
    /* @4080048 load */
    /* @4080056 load */
    /* @4080064 call */
    GM_SITE(vm, 278, 4080064);
    /* @4080072 store */
    v45 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v45);
    /* @4080080 load */
    /* @4080088 load */
    /* @4080096 cast */
    /* @4080100 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", GM_READ(vm, -5, "bombgundamage"));
    /* @4080108 constant */
    /* @4080112 constant */
    /* @4080116 constant */
    /* @4080120 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    /* @4080128 load */
    /* @4080136 constant */
    /* @4080140 cmp */
    /* @4080144 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4080152;
    /* @4080148 b */
    goto L_4080208;
    L_4080152: ;
    /* @4080152 load */
    /* @4080160 constant */
    /* @4080164 cmp */
    /* @4080168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4080208;
    /* @4080172 constant */
    /* @4080176 cast */
    /* @4080180 constant */
    /* @4080184 cast */
    /* @4080188 constant */
    /* @4080192 cast */
    /* @4080196 call */
    GM_SITE(vm, 278, 4080196);
    /* @4080204 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_4080208: ;
    /* @4080208 load */
    /* @4080216 constant */
    /* @4080220 add */
    /* @4080224 store */
    v46 = GM_ADD(GM_READ(vm, -5, "bombgunxp"), VAL(1));
    GM_WRITE(vm, -5, "bombgunxp", v46);
    /* @4080232 load */
    /* @4080240 constant */
    /* @4080244 cmp */
    /* @4080248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "poisonenabled") == VAL(1)))) goto L_4080280;
    /* @4080252 constant */
    /* @4080256 load */
    /* @4080264 cast */
    /* @4080268 constant */
    /* @4080272 store */
    GM_WRITE_ARR(vm, TO_INT(GM_READ(vm, -1, "hit14")), "alarm", VAL(6), VAL(1));
    L_4080280: ;
    /* @4080280 constant */
    /* @4080284 store */
    GM_WRITE(vm, -1, "canhit", VAL(1));
    L_4080292: ;
    /* @4080292 constant */
    /* @4080296 cast */
    /* @4080300 load */
    /* @4080308 load */
    /* @4080316 call */
    GM_SITE(vm, 278, 4080316);
    /* @4080324 store */
    v47 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(26));
    GM_WRITE(vm, -1, "hit15", v47);
    /* @4080332 load */
    /* @4080340 constant */
    /* @4080344 cmp */
    /* @4080348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit15") != VAL(-4)))) goto L_4080352;
    L_4080352: ;
    /* @4080352 constant */
    /* @4080356 cast */
    /* @4080360 load */
    /* @4080368 load */
    /* @4080376 call */
    GM_SITE(vm, 278, 4080376);
    /* @4080384 store */
    v48 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(27));
    GM_WRITE(vm, -1, "hit16", v48);
    /* @4080392 load */
    /* @4080400 constant */
    /* @4080404 cmp */
    /* @4080408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit16") != VAL(-4)))) goto L_4080412;
    L_4080412: ;
    /* @4080412 constant */
    /* @4080416 cast */
    /* @4080420 load */
    /* @4080428 load */
    /* @4080436 call */
    GM_SITE(vm, 278, 4080436);
    /* @4080444 store */
    v49 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(28));
    GM_WRITE(vm, -1, "hitboss4", v49);
    /* @4080452 load */
    /* @4080460 constant */
    /* @4080464 cmp */
    /* @4080468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss4") != VAL(-4)))) goto L_4080472;
    L_4080472: ;
    /* @4080472 constant */
    /* @4080476 cast */
    /* @4080480 load */
    /* @4080488 load */
    /* @4080496 call */
    GM_SITE(vm, 278, 4080496);
    /* @4080504 store */
    v50 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(29));
    GM_WRITE(vm, -1, "hitboss5", v50);
    /* @4080512 load */
    /* @4080520 constant */
    /* @4080524 cmp */
    /* @4080528 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hitboss5") != VAL(-4)))) goto L_4080532;
    L_4080532: ;
    /* @4080532 constant */
    /* @4080536 cast */
    /* @4080540 load */
    /* @4080548 load */
    /* @4080556 call */
    GM_SITE(vm, 278, 4080556);
    /* @4080564 store */
    v51 = GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(30));
    GM_WRITE(vm, -1, "hit17", v51);
    /* @4080572 load */
    /* @4080580 constant */
    /* @4080584 cmp */
    /* @4080588 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hit17") != VAL(-4)))) goto L_4080592;
    L_4080592: ;
    return;
}
