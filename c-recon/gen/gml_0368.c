/* generated from CODE 368 (gml_Object_obj_UI_Alarm_0), source start 4224184, end 4228760. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0368(GmVM* vm) {
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
    Val p4226144_0;
    Val p4226216_0;
    Val p4226288_0;
    Val p4226360_0;
    Val p4226432_0;
    Val p4226504_0;
    Val p4226576_0;
    Val p4226648_0;
    Val p4226720_0;
    Val p4226792_0;
    Val p4226864_0;
    Val p4226936_0;
    Val p4227008_0;
    Val p4227080_0;
    Val p4227152_0;
    Val p4227224_0;
    Val p4227296_0;
    Val p4227368_0;
    Val p4227440_0;
    Val p4227512_0;
    Val p4227584_0;
    Val p4227656_0;
    Val p4227728_0;
    Val p4227800_0;
    Val p4227872_0;
    Val p4227944_0;
    Val p4228016_0;
    Val p4228088_0;
    Val p4228160_0;
    Val p4228232_0;
    Val p4228304_0;
    Val p4228376_0;
    Val p4228448_0;
    Val p4228520_0;
    Val p4228592_0;
    Val p4228664_0;
    /* @4224184 load */
    /* @4224192 constant */
    /* @4224196 cmp */
    /* @4224200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "drawweaponlevelup") == VAL(1)))) goto L_4224268;
    /* @4224204 constant */
    /* @4224208 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(0));
    /* @4224216 constant */
    /* @4224220 cast */
    /* @4224224 load */
    /* @4224232 constant */
    /* @4224236 add */
    /* @4224240 load */
    /* @4224248 constant */
    /* @4224252 sub */
    /* @4224256 call */
    GM_SITE(vm, 368, 4224256);
    v1 = GM_ADD(GM_READ(vm, 126, "y"), VAL(132));
    /* @4224264 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, 126, "x") - VAL(32)), v1, VAL(64)));
    L_4224268: ;
    /* @4224268 load */
    /* @4224276 load */
    /* @4224284 cmp */
    /* @4224288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "experience") >= GM_READ(vm, -5, "xptolevelup")))) goto L_4224392;
    /* @4224292 load */
    /* @4224300 constant */
    /* @4224304 cmp */
    /* @4224308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_4224392;
    /* @4224312 constant */
    /* @4224316 store */
    GM_WRITE(vm, -5, "experience", VAL(1));
    /* @4224324 load */
    /* @4224332 constant */
    /* @4224336 add */
    /* @4224340 store */
    v2 = GM_ADD(GM_READ(vm, -5, "level"), VAL(1));
    GM_WRITE(vm, -5, "level", v2);
    /* @4224348 load */
    /* @4224356 constant */
    /* @4224368 mul */
    /* @4224372 store */
    GM_WRITE(vm, -5, "xptolevelup", (GM_READ(vm, -5, "xptolevelup") * VAL(1.12)));
    /* @4224380 constant */
    /* @4224384 store */
    GM_WRITE(vm, -5, "drawlevelup", VAL(1));
    L_4224392: ;
    /* @4224392 load */
    /* @4224400 constant */
    /* @4224404 cmp */
    /* @4224408 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "drawlevelup") == VAL(1)))) goto L_4224496;
    /* @4224412 load */
    /* @4224420 constant */
    /* @4224424 cmp */
    /* @4224428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") <= VAL(20)))) goto L_4224484;
    /* @4224432 constant */
    /* @4224436 cast */
    /* @4224440 load */
    /* @4224448 constant */
    /* @4224452 sub */
    /* @4224456 load */
    /* @4224464 constant */
    /* @4224468 sub */
    /* @4224472 call */
    GM_SITE(vm, 368, 4224472);
    /* @4224480 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, 0, "x") - VAL(45)), (GM_READ(vm, 0, "y") - VAL(32)), VAL(63)));
    L_4224484: ;
    /* @4224484 constant */
    /* @4224488 store */
    GM_WRITE(vm, -5, "drawlevelup", VAL(0));
    L_4224496: ;
    /* @4224496 load */
    /* @4224504 constant */
    /* @4224508 cmp */
    /* @4224512 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level") >= VAL(20)))) goto L_4224528;
    /* @4224516 constant */
    /* @4224520 store */
    GM_WRITE(vm, -5, "level", VAL(20));
    L_4224528: ;
    /* @4224528 constant */
    /* @4224532 cast */
    /* @4224536 constant */
    /* @4224540 cast */
    /* @4224544 call */
    GM_SITE(vm, 368, 4224544);
    /* @4224552 store */
    v3 = GM_CALL(vm, "choose", 2, VAL(19), VAL(20));
    GM_WRITE(vm, -5, "coinsound", v3);
    /* @4224560 constant */
    /* @4224564 cast */
    /* @4224568 constant */
    /* @4224572 cast */
    /* @4224576 call */
    GM_SITE(vm, 368, 4224576);
    /* @4224584 store */
    v4 = GM_CALL(vm, "choose", 2, VAL(13), VAL(14));
    GM_WRITE(vm, -5, "swordsound", v4);
    /* @4224592 constant */
    /* @4224596 constant */
    /* @4224600 constant */
    /* @4224604 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    /* @4224612 load */
    /* @4224620 load */
    /* @4224628 cmp */
    /* @4224632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistolxp") >= GM_READ(vm, -5, "pistolxptolevelup")))) goto L_4224736;
    /* @4224636 load */
    /* @4224644 constant */
    /* @4224648 cmp */
    /* @4224652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") < VAL(10)))) goto L_4224668;
    /* @4224656 constant */
    /* @4224660 store */
    GM_WRITE(vm, -5, "pistolxp", VAL(1));
    L_4224668: ;
    /* @4224668 load */
    /* @4224676 constant */
    /* @4224680 add */
    /* @4224684 store */
    v5 = GM_ADD(GM_READ(vm, -5, "pistollevel"), VAL(1));
    GM_WRITE(vm, -5, "pistollevel", v5);
    /* @4224692 load */
    /* @4224700 constant */
    /* @4224712 mul */
    /* @4224716 store */
    GM_WRITE(vm, -5, "pistolxptolevelup", (GM_READ(vm, -5, "pistolxptolevelup") * VAL(1.5)));
    /* @4224724 constant */
    /* @4224728 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4224736: ;
    /* @4224736 load */
    /* @4224744 load */
    /* @4224752 cmp */
    /* @4224756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunxp") >= GM_READ(vm, -5, "shotgunxptolevelup")))) goto L_4224860;
    /* @4224760 load */
    /* @4224768 constant */
    /* @4224772 cmp */
    /* @4224776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") < VAL(10)))) goto L_4224860;
    /* @4224780 constant */
    /* @4224784 store */
    GM_WRITE(vm, -5, "shotgunxp", VAL(1));
    /* @4224792 load */
    /* @4224800 constant */
    /* @4224804 add */
    /* @4224808 store */
    v6 = GM_ADD(GM_READ(vm, -5, "shotgunlevel"), VAL(1));
    GM_WRITE(vm, -5, "shotgunlevel", v6);
    /* @4224816 load */
    /* @4224824 constant */
    /* @4224836 mul */
    /* @4224840 store */
    GM_WRITE(vm, -5, "shotgunxptolevelup", (GM_READ(vm, -5, "shotgunxptolevelup") * VAL(1.5)));
    /* @4224848 constant */
    /* @4224852 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4224860: ;
    /* @4224860 load */
    /* @4224868 load */
    /* @4224876 cmp */
    /* @4224880 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflexp") >= GM_READ(vm, -5, "assaultriflexptolevelup")))) goto L_4224984;
    /* @4224884 load */
    /* @4224892 constant */
    /* @4224896 cmp */
    /* @4224900 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") < VAL(10)))) goto L_4224984;
    /* @4224904 constant */
    /* @4224908 store */
    GM_WRITE(vm, -5, "assaultriflexp", VAL(1));
    /* @4224916 load */
    /* @4224924 constant */
    /* @4224928 add */
    /* @4224932 store */
    v7 = GM_ADD(GM_READ(vm, -5, "assaultriflelevel"), VAL(1));
    GM_WRITE(vm, -5, "assaultriflelevel", v7);
    /* @4224940 load */
    /* @4224948 constant */
    /* @4224960 mul */
    /* @4224964 store */
    GM_WRITE(vm, -5, "assaultriflexptolevelup", (GM_READ(vm, -5, "assaultriflexptolevelup") * VAL(1.5)));
    /* @4224972 constant */
    /* @4224976 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4224984: ;
    /* @4224984 load */
    /* @4224992 load */
    /* @4225000 cmp */
    /* @4225004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketxp") >= GM_READ(vm, -5, "rocketxptolevelup")))) goto L_4225108;
    /* @4225008 load */
    /* @4225016 constant */
    /* @4225020 cmp */
    /* @4225024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") < VAL(10)))) goto L_4225108;
    /* @4225028 constant */
    /* @4225032 store */
    GM_WRITE(vm, -5, "rocketxp", VAL(1));
    /* @4225040 load */
    /* @4225048 constant */
    /* @4225052 add */
    /* @4225056 store */
    v8 = GM_ADD(GM_READ(vm, -5, "rocketlevel"), VAL(1));
    GM_WRITE(vm, -5, "rocketlevel", v8);
    /* @4225064 load */
    /* @4225072 constant */
    /* @4225084 mul */
    /* @4225088 store */
    GM_WRITE(vm, -5, "rocketxptolevelup", (GM_READ(vm, -5, "rocketxptolevelup") * VAL(1.5)));
    /* @4225096 constant */
    /* @4225100 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225108: ;
    /* @4225108 load */
    /* @4225116 load */
    /* @4225124 cmp */
    /* @4225128 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserxp") >= GM_READ(vm, -5, "laserxptolevelup")))) goto L_4225232;
    /* @4225132 load */
    /* @4225140 constant */
    /* @4225144 cmp */
    /* @4225148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") < VAL(10)))) goto L_4225232;
    /* @4225152 constant */
    /* @4225156 store */
    GM_WRITE(vm, -5, "laserxp", VAL(1));
    /* @4225164 load */
    /* @4225172 constant */
    /* @4225176 add */
    /* @4225180 store */
    v9 = GM_ADD(GM_READ(vm, -5, "laserlevel"), VAL(1));
    GM_WRITE(vm, -5, "laserlevel", v9);
    /* @4225188 load */
    /* @4225196 constant */
    /* @4225208 mul */
    /* @4225212 store */
    GM_WRITE(vm, -5, "laserxptolevelup", (GM_READ(vm, -5, "laserxptolevelup") * VAL(1.5)));
    /* @4225220 constant */
    /* @4225224 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225232: ;
    /* @4225232 load */
    /* @4225240 load */
    /* @4225248 cmp */
    /* @4225252 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunxp") >= GM_READ(vm, -5, "icegunxptolevelup")))) goto L_4225356;
    /* @4225256 load */
    /* @4225264 constant */
    /* @4225268 cmp */
    /* @4225272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") < VAL(10)))) goto L_4225356;
    /* @4225276 constant */
    /* @4225280 store */
    GM_WRITE(vm, -5, "icegunxp", VAL(1));
    /* @4225288 load */
    /* @4225296 constant */
    /* @4225300 add */
    /* @4225304 store */
    v10 = GM_ADD(GM_READ(vm, -5, "icegunlevel"), VAL(1));
    GM_WRITE(vm, -5, "icegunlevel", v10);
    /* @4225312 load */
    /* @4225320 constant */
    /* @4225332 mul */
    /* @4225336 store */
    GM_WRITE(vm, -5, "icegunxptolevelup", (GM_READ(vm, -5, "icegunxptolevelup") * VAL(1.5)));
    /* @4225344 constant */
    /* @4225348 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225356: ;
    /* @4225356 load */
    /* @4225364 load */
    /* @4225372 cmp */
    /* @4225376 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowxp") >= GM_READ(vm, -5, "bowxptolevelup")))) goto L_4225480;
    /* @4225380 load */
    /* @4225388 constant */
    /* @4225392 cmp */
    /* @4225396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") < VAL(10)))) goto L_4225480;
    /* @4225400 constant */
    /* @4225404 store */
    GM_WRITE(vm, -5, "bowxp", VAL(1));
    /* @4225412 load */
    /* @4225420 constant */
    /* @4225424 add */
    /* @4225428 store */
    v11 = GM_ADD(GM_READ(vm, -5, "bowlevel"), VAL(1));
    GM_WRITE(vm, -5, "bowlevel", v11);
    /* @4225436 load */
    /* @4225444 constant */
    /* @4225456 mul */
    /* @4225460 store */
    GM_WRITE(vm, -5, "bowxptolevelup", (GM_READ(vm, -5, "bowxptolevelup") * VAL(1.5)));
    /* @4225468 constant */
    /* @4225472 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225480: ;
    /* @4225480 load */
    /* @4225488 load */
    /* @4225496 cmp */
    /* @4225500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunxp") >= GM_READ(vm, -5, "bladegunxptolevelup")))) goto L_4225604;
    /* @4225504 load */
    /* @4225512 constant */
    /* @4225516 cmp */
    /* @4225520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") < VAL(10)))) goto L_4225604;
    /* @4225524 constant */
    /* @4225528 store */
    GM_WRITE(vm, -5, "bladegunxp", VAL(1));
    /* @4225536 load */
    /* @4225544 constant */
    /* @4225548 add */
    /* @4225552 store */
    v12 = GM_ADD(GM_READ(vm, -5, "bladegunlevel"), VAL(1));
    GM_WRITE(vm, -5, "bladegunlevel", v12);
    /* @4225560 load */
    /* @4225568 constant */
    /* @4225580 mul */
    /* @4225584 store */
    GM_WRITE(vm, -5, "bladegunxpxptolevelup", (GM_READ(vm, -5, "bladegunxptolevelup") * VAL(1.5)));
    /* @4225592 constant */
    /* @4225596 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225604: ;
    /* @4225604 load */
    /* @4225612 load */
    /* @4225620 cmp */
    /* @4225624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerxp") >= GM_READ(vm, -5, "flamethrowerxptolevelup")))) goto L_4225728;
    /* @4225628 load */
    /* @4225636 constant */
    /* @4225640 cmp */
    /* @4225644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") < VAL(10)))) goto L_4225728;
    /* @4225648 constant */
    /* @4225652 store */
    GM_WRITE(vm, -5, "flamethrowerxp", VAL(1));
    /* @4225660 load */
    /* @4225668 constant */
    /* @4225672 add */
    /* @4225676 store */
    v13 = GM_ADD(GM_READ(vm, -5, "flamethrowerlevel"), VAL(1));
    GM_WRITE(vm, -5, "flamethrowerlevel", v13);
    /* @4225684 load */
    /* @4225692 constant */
    /* @4225704 mul */
    /* @4225708 store */
    GM_WRITE(vm, -5, "flamethrowerxptolevelup", (GM_READ(vm, -5, "flamethrowerxptolevelup") * VAL(1.5)));
    /* @4225716 constant */
    /* @4225720 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225728: ;
    /* @4225728 load */
    /* @4225736 load */
    /* @4225744 cmp */
    /* @4225748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangxp") >= GM_READ(vm, -5, "boomerangxptolevelup")))) goto L_4225852;
    /* @4225752 load */
    /* @4225760 constant */
    /* @4225764 cmp */
    /* @4225768 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") < VAL(10)))) goto L_4225852;
    /* @4225772 constant */
    /* @4225776 store */
    GM_WRITE(vm, -5, "boomerangxp", VAL(1));
    /* @4225784 load */
    /* @4225792 constant */
    /* @4225796 add */
    /* @4225800 store */
    v14 = GM_ADD(GM_READ(vm, -5, "boomeranglevel"), VAL(1));
    GM_WRITE(vm, -5, "boomeranglevel", v14);
    /* @4225808 load */
    /* @4225816 constant */
    /* @4225828 mul */
    /* @4225832 store */
    GM_WRITE(vm, -5, "boomerangxptolevelup", (GM_READ(vm, -5, "boomerangxptolevelup") * VAL(1.5)));
    /* @4225840 constant */
    /* @4225844 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225852: ;
    /* @4225852 load */
    /* @4225860 load */
    /* @4225868 cmp */
    /* @4225872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunxp") >= GM_READ(vm, -5, "spikegunxptolevelup")))) goto L_4225976;
    /* @4225876 load */
    /* @4225884 constant */
    /* @4225888 cmp */
    /* @4225892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") < VAL(10)))) goto L_4225976;
    /* @4225896 constant */
    /* @4225900 store */
    GM_WRITE(vm, -5, "spikegunxp", VAL(1));
    /* @4225908 load */
    /* @4225916 constant */
    /* @4225920 add */
    /* @4225924 store */
    v15 = GM_ADD(GM_READ(vm, -5, "spikegunlevel"), VAL(1));
    GM_WRITE(vm, -5, "spikegunlevel", v15);
    /* @4225932 load */
    /* @4225940 constant */
    /* @4225952 mul */
    /* @4225956 store */
    GM_WRITE(vm, -5, "spikegunxptolevelup", (GM_READ(vm, -5, "spikegunxptolevelup") * VAL(1.5)));
    /* @4225964 constant */
    /* @4225968 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4225976: ;
    /* @4225976 load */
    /* @4225984 load */
    /* @4225992 cmp */
    /* @4225996 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunxp") >= GM_READ(vm, -5, "bombgunxptolevelup")))) goto L_4226100;
    /* @4226000 load */
    /* @4226008 constant */
    /* @4226012 cmp */
    /* @4226016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") < VAL(10)))) goto L_4226100;
    /* @4226020 constant */
    /* @4226024 store */
    GM_WRITE(vm, -5, "bombgunxp", VAL(1));
    /* @4226032 load */
    /* @4226040 constant */
    /* @4226044 add */
    /* @4226048 store */
    v16 = GM_ADD(GM_READ(vm, -5, "bombgunlevel"), VAL(1));
    GM_WRITE(vm, -5, "bombgunlevel", v16);
    /* @4226056 load */
    /* @4226064 constant */
    /* @4226076 mul */
    /* @4226080 store */
    GM_WRITE(vm, -5, "bombgunxptolevelup", (GM_READ(vm, -5, "bombgunxptolevelup") * VAL(1.5)));
    /* @4226088 constant */
    /* @4226092 store */
    GM_WRITE(vm, -5, "drawweaponlevelup", VAL(1));
    L_4226100: ;
    /* @4226100 load */
    /* @4226108 constant */
    /* @4226112 cmp */
    /* @4226116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(4)))) goto L_4226140;
    /* @4226120 load */
    /* @4226128 constant */
    /* @4226132 cmp */
    /* @4226136 b */
    p4226144_0 = NUMBOOL(GM_READ(vm, -5, "drawchangepistol4") == VAL(1));
    goto L_4226144;
    L_4226140: ;
    /* @4226140 constant */
    p4226144_0 = VAL(0);
    L_4226144: ;
    /* @4226144 bf */
    if (!TRUTH(p4226144_0)) goto L_4226172;
    /* @4226148 constant */
    /* @4226152 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226160 constant */
    /* @4226164 store */
    GM_WRITE(vm, -5, "drawchangepistol4", VAL(0));
    L_4226172: ;
    /* @4226172 load */
    /* @4226180 constant */
    /* @4226184 cmp */
    /* @4226188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(4)))) goto L_4226212;
    /* @4226192 load */
    /* @4226200 constant */
    /* @4226204 cmp */
    /* @4226208 b */
    p4226216_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeshotgun4") == VAL(1));
    goto L_4226216;
    L_4226212: ;
    /* @4226212 constant */
    p4226216_0 = VAL(0);
    L_4226216: ;
    /* @4226216 bf */
    if (!TRUTH(p4226216_0)) goto L_4226244;
    /* @4226220 constant */
    /* @4226224 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226232 constant */
    /* @4226236 store */
    GM_WRITE(vm, -5, "drawchangeshotgun4", VAL(0));
    L_4226244: ;
    /* @4226244 load */
    /* @4226252 constant */
    /* @4226256 cmp */
    /* @4226260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(4)))) goto L_4226284;
    /* @4226264 load */
    /* @4226272 constant */
    /* @4226276 cmp */
    /* @4226280 b */
    p4226288_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeassaultrifle4") == VAL(1));
    goto L_4226288;
    L_4226284: ;
    /* @4226284 constant */
    p4226288_0 = VAL(0);
    L_4226288: ;
    /* @4226288 bf */
    if (!TRUTH(p4226288_0)) goto L_4226316;
    /* @4226292 constant */
    /* @4226296 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226304 constant */
    /* @4226308 store */
    GM_WRITE(vm, -5, "drawchangeassaultrifle4", VAL(0));
    L_4226316: ;
    /* @4226316 load */
    /* @4226324 constant */
    /* @4226328 cmp */
    /* @4226332 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(4)))) goto L_4226356;
    /* @4226336 load */
    /* @4226344 constant */
    /* @4226348 cmp */
    /* @4226352 b */
    p4226360_0 = NUMBOOL(GM_READ(vm, -5, "drawchangerocket4") == VAL(1));
    goto L_4226360;
    L_4226356: ;
    /* @4226356 constant */
    p4226360_0 = VAL(0);
    L_4226360: ;
    /* @4226360 bf */
    if (!TRUTH(p4226360_0)) goto L_4226388;
    /* @4226364 constant */
    /* @4226368 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226376 constant */
    /* @4226380 store */
    GM_WRITE(vm, -5, "drawchangerocket4", VAL(0));
    L_4226388: ;
    /* @4226388 load */
    /* @4226396 constant */
    /* @4226400 cmp */
    /* @4226404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(4)))) goto L_4226428;
    /* @4226408 load */
    /* @4226416 constant */
    /* @4226420 cmp */
    /* @4226424 b */
    p4226432_0 = NUMBOOL(GM_READ(vm, -5, "drawchangelaser4") == VAL(1));
    goto L_4226432;
    L_4226428: ;
    /* @4226428 constant */
    p4226432_0 = VAL(0);
    L_4226432: ;
    /* @4226432 bf */
    if (!TRUTH(p4226432_0)) goto L_4226460;
    /* @4226436 constant */
    /* @4226440 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226448 constant */
    /* @4226452 store */
    GM_WRITE(vm, -5, "drawchangelaser4", VAL(0));
    L_4226460: ;
    /* @4226460 load */
    /* @4226468 constant */
    /* @4226472 cmp */
    /* @4226476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(4)))) goto L_4226500;
    /* @4226480 load */
    /* @4226488 constant */
    /* @4226492 cmp */
    /* @4226496 b */
    p4226504_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeicegun4") == VAL(1));
    goto L_4226504;
    L_4226500: ;
    /* @4226500 constant */
    p4226504_0 = VAL(0);
    L_4226504: ;
    /* @4226504 bf */
    if (!TRUTH(p4226504_0)) goto L_4226532;
    /* @4226508 constant */
    /* @4226512 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226520 constant */
    /* @4226524 store */
    GM_WRITE(vm, -5, "drawchangeicegun4", VAL(0));
    L_4226532: ;
    /* @4226532 load */
    /* @4226540 constant */
    /* @4226544 cmp */
    /* @4226548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(4)))) goto L_4226572;
    /* @4226552 load */
    /* @4226560 constant */
    /* @4226564 cmp */
    /* @4226568 b */
    p4226576_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebow4") == VAL(1));
    goto L_4226576;
    L_4226572: ;
    /* @4226572 constant */
    p4226576_0 = VAL(0);
    L_4226576: ;
    /* @4226576 bf */
    if (!TRUTH(p4226576_0)) goto L_4226604;
    /* @4226580 constant */
    /* @4226584 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226592 constant */
    /* @4226596 store */
    GM_WRITE(vm, -5, "drawchangebow4", VAL(0));
    L_4226604: ;
    /* @4226604 load */
    /* @4226612 constant */
    /* @4226616 cmp */
    /* @4226620 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(4)))) goto L_4226644;
    /* @4226624 load */
    /* @4226632 constant */
    /* @4226636 cmp */
    /* @4226640 b */
    p4226648_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebladegun4") == VAL(1));
    goto L_4226648;
    L_4226644: ;
    /* @4226644 constant */
    p4226648_0 = VAL(0);
    L_4226648: ;
    /* @4226648 bf */
    if (!TRUTH(p4226648_0)) goto L_4226676;
    /* @4226652 constant */
    /* @4226656 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226664 constant */
    /* @4226668 store */
    GM_WRITE(vm, -5, "drawchangebladegun4", VAL(0));
    L_4226676: ;
    /* @4226676 load */
    /* @4226684 constant */
    /* @4226688 cmp */
    /* @4226692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(4)))) goto L_4226716;
    /* @4226696 load */
    /* @4226704 constant */
    /* @4226708 cmp */
    /* @4226712 b */
    p4226720_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeflamethrower4") == VAL(1));
    goto L_4226720;
    L_4226716: ;
    /* @4226716 constant */
    p4226720_0 = VAL(0);
    L_4226720: ;
    /* @4226720 bf */
    if (!TRUTH(p4226720_0)) goto L_4226748;
    /* @4226724 constant */
    /* @4226728 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226736 constant */
    /* @4226740 store */
    GM_WRITE(vm, -5, "drawchangeflamethrower4", VAL(0));
    L_4226748: ;
    /* @4226748 load */
    /* @4226756 constant */
    /* @4226760 cmp */
    /* @4226764 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(4)))) goto L_4226788;
    /* @4226768 load */
    /* @4226776 constant */
    /* @4226780 cmp */
    /* @4226784 b */
    p4226792_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeboomerang4") == VAL(1));
    goto L_4226792;
    L_4226788: ;
    /* @4226788 constant */
    p4226792_0 = VAL(0);
    L_4226792: ;
    /* @4226792 bf */
    if (!TRUTH(p4226792_0)) goto L_4226820;
    /* @4226796 constant */
    /* @4226800 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226808 constant */
    /* @4226812 store */
    GM_WRITE(vm, -5, "drawchangeboomerang4", VAL(0));
    L_4226820: ;
    /* @4226820 load */
    /* @4226828 constant */
    /* @4226832 cmp */
    /* @4226836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(4)))) goto L_4226860;
    /* @4226840 load */
    /* @4226848 constant */
    /* @4226852 cmp */
    /* @4226856 b */
    p4226864_0 = NUMBOOL(GM_READ(vm, -5, "drawchangespikegun4") == VAL(1));
    goto L_4226864;
    L_4226860: ;
    /* @4226860 constant */
    p4226864_0 = VAL(0);
    L_4226864: ;
    /* @4226864 bf */
    if (!TRUTH(p4226864_0)) goto L_4226892;
    /* @4226868 constant */
    /* @4226872 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226880 constant */
    /* @4226884 store */
    GM_WRITE(vm, -5, "drawchangespikegun4", VAL(0));
    L_4226892: ;
    /* @4226892 load */
    /* @4226900 constant */
    /* @4226904 cmp */
    /* @4226908 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(4)))) goto L_4226932;
    /* @4226912 load */
    /* @4226920 constant */
    /* @4226924 cmp */
    /* @4226928 b */
    p4226936_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebombgun4") == VAL(1));
    goto L_4226936;
    L_4226932: ;
    /* @4226932 constant */
    p4226936_0 = VAL(0);
    L_4226936: ;
    /* @4226936 bf */
    if (!TRUTH(p4226936_0)) goto L_4226964;
    /* @4226940 constant */
    /* @4226944 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4226952 constant */
    /* @4226956 store */
    GM_WRITE(vm, -5, "drawchangebombgun4", VAL(0));
    L_4226964: ;
    /* @4226964 load */
    /* @4226972 constant */
    /* @4226976 cmp */
    /* @4226980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(7)))) goto L_4227004;
    /* @4226984 load */
    /* @4226992 constant */
    /* @4226996 cmp */
    /* @4227000 b */
    p4227008_0 = NUMBOOL(GM_READ(vm, -5, "drawchangepistol7") == VAL(1));
    goto L_4227008;
    L_4227004: ;
    /* @4227004 constant */
    p4227008_0 = VAL(0);
    L_4227008: ;
    /* @4227008 bf */
    if (!TRUTH(p4227008_0)) goto L_4227036;
    /* @4227012 constant */
    /* @4227016 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227024 constant */
    /* @4227028 store */
    GM_WRITE(vm, -5, "drawchangepistol7", VAL(0));
    L_4227036: ;
    /* @4227036 load */
    /* @4227044 constant */
    /* @4227048 cmp */
    /* @4227052 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(7)))) goto L_4227076;
    /* @4227056 load */
    /* @4227064 constant */
    /* @4227068 cmp */
    /* @4227072 b */
    p4227080_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeshotgun7") == VAL(1));
    goto L_4227080;
    L_4227076: ;
    /* @4227076 constant */
    p4227080_0 = VAL(0);
    L_4227080: ;
    /* @4227080 bf */
    if (!TRUTH(p4227080_0)) goto L_4227108;
    /* @4227084 constant */
    /* @4227088 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227096 constant */
    /* @4227100 store */
    GM_WRITE(vm, -5, "drawchangeshotgun7", VAL(0));
    L_4227108: ;
    /* @4227108 load */
    /* @4227116 constant */
    /* @4227120 cmp */
    /* @4227124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(7)))) goto L_4227148;
    /* @4227128 load */
    /* @4227136 constant */
    /* @4227140 cmp */
    /* @4227144 b */
    p4227152_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeassaultrifle7") == VAL(1));
    goto L_4227152;
    L_4227148: ;
    /* @4227148 constant */
    p4227152_0 = VAL(0);
    L_4227152: ;
    /* @4227152 bf */
    if (!TRUTH(p4227152_0)) goto L_4227180;
    /* @4227156 constant */
    /* @4227160 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227168 constant */
    /* @4227172 store */
    GM_WRITE(vm, -5, "drawchangeassaultrifle7", VAL(0));
    L_4227180: ;
    /* @4227180 load */
    /* @4227188 constant */
    /* @4227192 cmp */
    /* @4227196 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(7)))) goto L_4227220;
    /* @4227200 load */
    /* @4227208 constant */
    /* @4227212 cmp */
    /* @4227216 b */
    p4227224_0 = NUMBOOL(GM_READ(vm, -5, "drawchangerocket7") == VAL(1));
    goto L_4227224;
    L_4227220: ;
    /* @4227220 constant */
    p4227224_0 = VAL(0);
    L_4227224: ;
    /* @4227224 bf */
    if (!TRUTH(p4227224_0)) goto L_4227252;
    /* @4227228 constant */
    /* @4227232 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227240 constant */
    /* @4227244 store */
    GM_WRITE(vm, -5, "drawchangerocket7", VAL(0));
    L_4227252: ;
    /* @4227252 load */
    /* @4227260 constant */
    /* @4227264 cmp */
    /* @4227268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(7)))) goto L_4227292;
    /* @4227272 load */
    /* @4227280 constant */
    /* @4227284 cmp */
    /* @4227288 b */
    p4227296_0 = NUMBOOL(GM_READ(vm, -5, "drawchangelaser7") == VAL(1));
    goto L_4227296;
    L_4227292: ;
    /* @4227292 constant */
    p4227296_0 = VAL(0);
    L_4227296: ;
    /* @4227296 bf */
    if (!TRUTH(p4227296_0)) goto L_4227324;
    /* @4227300 constant */
    /* @4227304 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227312 constant */
    /* @4227316 store */
    GM_WRITE(vm, -5, "drawchangelaser7", VAL(0));
    L_4227324: ;
    /* @4227324 load */
    /* @4227332 constant */
    /* @4227336 cmp */
    /* @4227340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(7)))) goto L_4227364;
    /* @4227344 load */
    /* @4227352 constant */
    /* @4227356 cmp */
    /* @4227360 b */
    p4227368_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeicegun7") == VAL(1));
    goto L_4227368;
    L_4227364: ;
    /* @4227364 constant */
    p4227368_0 = VAL(0);
    L_4227368: ;
    /* @4227368 bf */
    if (!TRUTH(p4227368_0)) goto L_4227396;
    /* @4227372 constant */
    /* @4227376 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227384 constant */
    /* @4227388 store */
    GM_WRITE(vm, -5, "drawchangeicegun7", VAL(0));
    L_4227396: ;
    /* @4227396 load */
    /* @4227404 constant */
    /* @4227408 cmp */
    /* @4227412 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(7)))) goto L_4227436;
    /* @4227416 load */
    /* @4227424 constant */
    /* @4227428 cmp */
    /* @4227432 b */
    p4227440_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebow7") == VAL(1));
    goto L_4227440;
    L_4227436: ;
    /* @4227436 constant */
    p4227440_0 = VAL(0);
    L_4227440: ;
    /* @4227440 bf */
    if (!TRUTH(p4227440_0)) goto L_4227468;
    /* @4227444 constant */
    /* @4227448 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227456 constant */
    /* @4227460 store */
    GM_WRITE(vm, -5, "drawchangebow7", VAL(0));
    L_4227468: ;
    /* @4227468 load */
    /* @4227476 constant */
    /* @4227480 cmp */
    /* @4227484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(7)))) goto L_4227508;
    /* @4227488 load */
    /* @4227496 constant */
    /* @4227500 cmp */
    /* @4227504 b */
    p4227512_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebladegun7") == VAL(1));
    goto L_4227512;
    L_4227508: ;
    /* @4227508 constant */
    p4227512_0 = VAL(0);
    L_4227512: ;
    /* @4227512 bf */
    if (!TRUTH(p4227512_0)) goto L_4227540;
    /* @4227516 constant */
    /* @4227520 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227528 constant */
    /* @4227532 store */
    GM_WRITE(vm, -5, "drawchangebladegun7", VAL(0));
    L_4227540: ;
    /* @4227540 load */
    /* @4227548 constant */
    /* @4227552 cmp */
    /* @4227556 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(7)))) goto L_4227580;
    /* @4227560 load */
    /* @4227568 constant */
    /* @4227572 cmp */
    /* @4227576 b */
    p4227584_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeflamethrower7") == VAL(1));
    goto L_4227584;
    L_4227580: ;
    /* @4227580 constant */
    p4227584_0 = VAL(0);
    L_4227584: ;
    /* @4227584 bf */
    if (!TRUTH(p4227584_0)) goto L_4227612;
    /* @4227588 constant */
    /* @4227592 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227600 constant */
    /* @4227604 store */
    GM_WRITE(vm, -5, "drawchangeflamethrower7", VAL(0));
    L_4227612: ;
    /* @4227612 load */
    /* @4227620 constant */
    /* @4227624 cmp */
    /* @4227628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(7)))) goto L_4227652;
    /* @4227632 load */
    /* @4227640 constant */
    /* @4227644 cmp */
    /* @4227648 b */
    p4227656_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeboomerang7") == VAL(1));
    goto L_4227656;
    L_4227652: ;
    /* @4227652 constant */
    p4227656_0 = VAL(0);
    L_4227656: ;
    /* @4227656 bf */
    if (!TRUTH(p4227656_0)) goto L_4227684;
    /* @4227660 constant */
    /* @4227664 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227672 constant */
    /* @4227676 store */
    GM_WRITE(vm, -5, "drawchangeboomerang7", VAL(0));
    L_4227684: ;
    /* @4227684 load */
    /* @4227692 constant */
    /* @4227696 cmp */
    /* @4227700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(7)))) goto L_4227724;
    /* @4227704 load */
    /* @4227712 constant */
    /* @4227716 cmp */
    /* @4227720 b */
    p4227728_0 = NUMBOOL(GM_READ(vm, -5, "drawchangespikegun7") == VAL(1));
    goto L_4227728;
    L_4227724: ;
    /* @4227724 constant */
    p4227728_0 = VAL(0);
    L_4227728: ;
    /* @4227728 bf */
    if (!TRUTH(p4227728_0)) goto L_4227756;
    /* @4227732 constant */
    /* @4227736 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227744 constant */
    /* @4227748 store */
    GM_WRITE(vm, -5, "drawchangespikegun7", VAL(0));
    L_4227756: ;
    /* @4227756 load */
    /* @4227764 constant */
    /* @4227768 cmp */
    /* @4227772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(7)))) goto L_4227796;
    /* @4227776 load */
    /* @4227784 constant */
    /* @4227788 cmp */
    /* @4227792 b */
    p4227800_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebombgun7") == VAL(1));
    goto L_4227800;
    L_4227796: ;
    /* @4227796 constant */
    p4227800_0 = VAL(0);
    L_4227800: ;
    /* @4227800 bf */
    if (!TRUTH(p4227800_0)) goto L_4227828;
    /* @4227804 constant */
    /* @4227808 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227816 constant */
    /* @4227820 store */
    GM_WRITE(vm, -5, "drawchangebombgun7", VAL(0));
    L_4227828: ;
    /* @4227828 load */
    /* @4227836 constant */
    /* @4227840 cmp */
    /* @4227844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pistollevel") == VAL(10)))) goto L_4227868;
    /* @4227848 load */
    /* @4227856 constant */
    /* @4227860 cmp */
    /* @4227864 b */
    p4227872_0 = NUMBOOL(GM_READ(vm, -5, "drawchangepistol10") == VAL(1));
    goto L_4227872;
    L_4227868: ;
    /* @4227868 constant */
    p4227872_0 = VAL(0);
    L_4227872: ;
    /* @4227872 bf */
    if (!TRUTH(p4227872_0)) goto L_4227900;
    /* @4227876 constant */
    /* @4227880 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227888 constant */
    /* @4227892 store */
    GM_WRITE(vm, -5, "drawchangepistol10", VAL(0));
    L_4227900: ;
    /* @4227900 load */
    /* @4227908 constant */
    /* @4227912 cmp */
    /* @4227916 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "shotgunlevel") == VAL(10)))) goto L_4227940;
    /* @4227920 load */
    /* @4227928 constant */
    /* @4227932 cmp */
    /* @4227936 b */
    p4227944_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeshotgun10") == VAL(1));
    goto L_4227944;
    L_4227940: ;
    /* @4227940 constant */
    p4227944_0 = VAL(0);
    L_4227944: ;
    /* @4227944 bf */
    if (!TRUTH(p4227944_0)) goto L_4227972;
    /* @4227948 constant */
    /* @4227952 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4227960 constant */
    /* @4227964 store */
    GM_WRITE(vm, -5, "drawchangeshotgun10", VAL(0));
    L_4227972: ;
    /* @4227972 load */
    /* @4227980 constant */
    /* @4227984 cmp */
    /* @4227988 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflelevel") == VAL(10)))) goto L_4228012;
    /* @4227992 load */
    /* @4228000 constant */
    /* @4228004 cmp */
    /* @4228008 b */
    p4228016_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeassaultrifle10") == VAL(1));
    goto L_4228016;
    L_4228012: ;
    /* @4228012 constant */
    p4228016_0 = VAL(0);
    L_4228016: ;
    /* @4228016 bf */
    if (!TRUTH(p4228016_0)) goto L_4228044;
    /* @4228020 constant */
    /* @4228024 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228032 constant */
    /* @4228036 store */
    GM_WRITE(vm, -5, "drawchangeassaultrifle10", VAL(0));
    L_4228044: ;
    /* @4228044 load */
    /* @4228052 constant */
    /* @4228056 cmp */
    /* @4228060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "rocketlevel") == VAL(10)))) goto L_4228084;
    /* @4228064 load */
    /* @4228072 constant */
    /* @4228076 cmp */
    /* @4228080 b */
    p4228088_0 = NUMBOOL(GM_READ(vm, -5, "drawchangerocket10") == VAL(1));
    goto L_4228088;
    L_4228084: ;
    /* @4228084 constant */
    p4228088_0 = VAL(0);
    L_4228088: ;
    /* @4228088 bf */
    if (!TRUTH(p4228088_0)) goto L_4228116;
    /* @4228092 constant */
    /* @4228096 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228104 constant */
    /* @4228108 store */
    GM_WRITE(vm, -5, "drawchangerocket10", VAL(0));
    L_4228116: ;
    /* @4228116 load */
    /* @4228124 constant */
    /* @4228128 cmp */
    /* @4228132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserlevel") == VAL(10)))) goto L_4228156;
    /* @4228136 load */
    /* @4228144 constant */
    /* @4228148 cmp */
    /* @4228152 b */
    p4228160_0 = NUMBOOL(GM_READ(vm, -5, "drawchangelaser10") == VAL(1));
    goto L_4228160;
    L_4228156: ;
    /* @4228156 constant */
    p4228160_0 = VAL(0);
    L_4228160: ;
    /* @4228160 bf */
    if (!TRUTH(p4228160_0)) goto L_4228188;
    /* @4228164 constant */
    /* @4228168 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228176 constant */
    /* @4228180 store */
    GM_WRITE(vm, -5, "drawchangelaser10", VAL(0));
    L_4228188: ;
    /* @4228188 load */
    /* @4228196 constant */
    /* @4228200 cmp */
    /* @4228204 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "icegunlevel") == VAL(10)))) goto L_4228228;
    /* @4228208 load */
    /* @4228216 constant */
    /* @4228220 cmp */
    /* @4228224 b */
    p4228232_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeicegun10") == VAL(1));
    goto L_4228232;
    L_4228228: ;
    /* @4228228 constant */
    p4228232_0 = VAL(0);
    L_4228232: ;
    /* @4228232 bf */
    if (!TRUTH(p4228232_0)) goto L_4228260;
    /* @4228236 constant */
    /* @4228240 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228248 constant */
    /* @4228252 store */
    GM_WRITE(vm, -5, "drawchangeicegun10", VAL(0));
    L_4228260: ;
    /* @4228260 load */
    /* @4228268 constant */
    /* @4228272 cmp */
    /* @4228276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowlevel") == VAL(10)))) goto L_4228300;
    /* @4228280 load */
    /* @4228288 constant */
    /* @4228292 cmp */
    /* @4228296 b */
    p4228304_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebow10") == VAL(1));
    goto L_4228304;
    L_4228300: ;
    /* @4228300 constant */
    p4228304_0 = VAL(0);
    L_4228304: ;
    /* @4228304 bf */
    if (!TRUTH(p4228304_0)) goto L_4228332;
    /* @4228308 constant */
    /* @4228312 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228320 constant */
    /* @4228324 store */
    GM_WRITE(vm, -5, "drawchangebow10", VAL(0));
    L_4228332: ;
    /* @4228332 load */
    /* @4228340 constant */
    /* @4228344 cmp */
    /* @4228348 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bladegunlevel") == VAL(10)))) goto L_4228372;
    /* @4228352 load */
    /* @4228360 constant */
    /* @4228364 cmp */
    /* @4228368 b */
    p4228376_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebladegun10") == VAL(1));
    goto L_4228376;
    L_4228372: ;
    /* @4228372 constant */
    p4228376_0 = VAL(0);
    L_4228376: ;
    /* @4228376 bf */
    if (!TRUTH(p4228376_0)) goto L_4228404;
    /* @4228380 constant */
    /* @4228384 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228392 constant */
    /* @4228396 store */
    GM_WRITE(vm, -5, "drawchangebladegun10", VAL(0));
    L_4228404: ;
    /* @4228404 load */
    /* @4228412 constant */
    /* @4228416 cmp */
    /* @4228420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerlevel") == VAL(10)))) goto L_4228444;
    /* @4228424 load */
    /* @4228432 constant */
    /* @4228436 cmp */
    /* @4228440 b */
    p4228448_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeflamethrower10") == VAL(1));
    goto L_4228448;
    L_4228444: ;
    /* @4228444 constant */
    p4228448_0 = VAL(0);
    L_4228448: ;
    /* @4228448 bf */
    if (!TRUTH(p4228448_0)) goto L_4228476;
    /* @4228452 constant */
    /* @4228456 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228464 constant */
    /* @4228468 store */
    GM_WRITE(vm, -5, "drawchangeflamethrower10", VAL(0));
    L_4228476: ;
    /* @4228476 load */
    /* @4228484 constant */
    /* @4228488 cmp */
    /* @4228492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") == VAL(10)))) goto L_4228516;
    /* @4228496 load */
    /* @4228504 constant */
    /* @4228508 cmp */
    /* @4228512 b */
    p4228520_0 = NUMBOOL(GM_READ(vm, -5, "drawchangeboomerang10") == VAL(1));
    goto L_4228520;
    L_4228516: ;
    /* @4228516 constant */
    p4228520_0 = VAL(0);
    L_4228520: ;
    /* @4228520 bf */
    if (!TRUTH(p4228520_0)) goto L_4228548;
    /* @4228524 constant */
    /* @4228528 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228536 constant */
    /* @4228540 store */
    GM_WRITE(vm, -5, "drawchangeboomerang10", VAL(0));
    L_4228548: ;
    /* @4228548 load */
    /* @4228556 constant */
    /* @4228560 cmp */
    /* @4228564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunlevel") == VAL(10)))) goto L_4228588;
    /* @4228568 load */
    /* @4228576 constant */
    /* @4228580 cmp */
    /* @4228584 b */
    p4228592_0 = NUMBOOL(GM_READ(vm, -5, "drawchangespikegun10") == VAL(1));
    goto L_4228592;
    L_4228588: ;
    /* @4228588 constant */
    p4228592_0 = VAL(0);
    L_4228592: ;
    /* @4228592 bf */
    if (!TRUTH(p4228592_0)) goto L_4228620;
    /* @4228596 constant */
    /* @4228600 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228608 constant */
    /* @4228612 store */
    GM_WRITE(vm, -5, "drawchangespikegun10", VAL(0));
    L_4228620: ;
    /* @4228620 load */
    /* @4228628 constant */
    /* @4228632 cmp */
    /* @4228636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bombgunlevel") == VAL(10)))) goto L_4228660;
    /* @4228640 load */
    /* @4228648 constant */
    /* @4228652 cmp */
    /* @4228656 b */
    p4228664_0 = NUMBOOL(GM_READ(vm, -5, "drawchangebombgun10") == VAL(1));
    goto L_4228664;
    L_4228660: ;
    /* @4228660 constant */
    p4228664_0 = VAL(0);
    L_4228664: ;
    /* @4228664 bf */
    if (!TRUTH(p4228664_0)) goto L_4228692;
    /* @4228668 constant */
    /* @4228672 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(1));
    /* @4228680 constant */
    /* @4228684 store */
    GM_WRITE(vm, -5, "drawchangebombgun10", VAL(0));
    L_4228692: ;
    /* @4228692 load */
    /* @4228700 constant */
    /* @4228704 cmp */
    /* @4228708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "drawweaponchange") == VAL(1)))) goto L_4228760;
    /* @4228712 constant */
    /* @4228716 store */
    GM_WRITE(vm, -5, "drawweaponchange", VAL(0));
    /* @4228724 constant */
    /* @4228728 cast */
    /* @4228732 load */
    /* @4228740 load */
    /* @4228748 call */
    GM_SITE(vm, 368, 4228748);
    /* @4228756 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(83)));
    L_4228760: ;
    return;
}
