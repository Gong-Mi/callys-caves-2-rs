/* generated from CODE 781 (gml_Object_obj_triggerintro_Step_0), source start 5038920, end 5040912. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0781(GmVM* vm) {
    Val v1;
    Val p5039012_0;
    Val p5039132_0;
    Val p5039228_0;
    Val p5039324_0;
    Val p5039420_0;
    Val p5039516_0;
    Val p5039612_0;
    Val p5039708_0;
    Val p5039804_0;
    Val p5039900_0;
    Val p5039996_0;
    Val p5040092_0;
    Val p5040188_0;
    Val p5040284_0;
    Val p5040380_0;
    Val p5040476_0;
    Val p5040572_0;
    Val p5040668_0;
    Val p5040764_0;
    Val p5040860_0;
    /* @5038920 constant */
    /* @5038924 cast */
    /* @5038928 call */
    GM_SITE(vm, 781, 5038928);
    /* @5038936 constant */
    /* @5038940 cmp */
    /* @5038944 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(32));
    if (!TRUTH(v1)) goto L_5040912;
    /* @5038948 load */
    /* @5038956 constant */
    /* @5038960 cmp */
    /* @5038964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_5039008;
    /* @5038968 load */
    /* @5038976 constant */
    /* @5038980 cmp */
    /* @5038984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < VAL(1000)))) goto L_5039008;
    /* @5038988 load */
    /* @5038996 constant */
    /* @5039000 cmp */
    /* @5039004 b */
    p5039012_0 = NUMBOOL(GM_READ(vm, -5, "beartouched") == VAL(0));
    goto L_5039012;
    L_5039008: ;
    /* @5039008 constant */
    p5039012_0 = VAL(0);
    L_5039012: ;
    /* @5039012 bf */
    if (!TRUTH(p5039012_0)) goto L_5039068;
    /* @5039016 constant */
    /* @5039020 cast */
    /* @5039024 load */
    /* @5039032 load */
    /* @5039040 call */
    GM_SITE(vm, 781, 5039040);
    /* @5039048 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(166)));
    /* @5039052 constant */
    /* @5039056 store */
    GM_WRITE(vm, -5, "beartouched", VAL(1));
    /* @5039064 b */
    goto L_5039184;
    L_5039068: ;
    /* @5039068 load */
    /* @5039076 constant */
    /* @5039080 cmp */
    /* @5039084 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(1)))) goto L_5039128;
    /* @5039088 load */
    /* @5039096 constant */
    /* @5039100 cmp */
    /* @5039104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") > VAL(1000)))) goto L_5039128;
    /* @5039108 load */
    /* @5039116 constant */
    /* @5039120 cmp */
    /* @5039124 b */
    p5039132_0 = NUMBOOL(GM_READ(vm, -5, "knifetouched") == VAL(0));
    goto L_5039132;
    L_5039128: ;
    /* @5039128 constant */
    p5039132_0 = VAL(0);
    L_5039132: ;
    /* @5039132 bf */
    if (!TRUTH(p5039132_0)) goto L_5039184;
    /* @5039136 constant */
    /* @5039140 cast */
    /* @5039144 load */
    /* @5039152 load */
    /* @5039160 call */
    GM_SITE(vm, 781, 5039160);
    /* @5039168 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(167)));
    /* @5039172 constant */
    /* @5039176 store */
    GM_WRITE(vm, -5, "knifetouched", VAL(1));
    L_5039184: ;
    /* @5039184 load */
    /* @5039192 constant */
    /* @5039196 cmp */
    /* @5039200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(2)))) goto L_5039224;
    /* @5039204 load */
    /* @5039212 constant */
    /* @5039216 cmp */
    /* @5039220 b */
    p5039228_0 = NUMBOOL(GM_READ(vm, -5, "spidertouched") == VAL(0));
    goto L_5039228;
    L_5039224: ;
    /* @5039224 constant */
    p5039228_0 = VAL(0);
    L_5039228: ;
    /* @5039228 bf */
    if (!TRUTH(p5039228_0)) goto L_5039280;
    /* @5039232 constant */
    /* @5039236 cast */
    /* @5039240 load */
    /* @5039248 load */
    /* @5039256 call */
    GM_SITE(vm, 781, 5039256);
    /* @5039264 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(168)));
    /* @5039268 constant */
    /* @5039272 store */
    GM_WRITE(vm, -5, "spidertouched", VAL(1));
    L_5039280: ;
    /* @5039280 load */
    /* @5039288 constant */
    /* @5039292 cmp */
    /* @5039296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(3)))) goto L_5039320;
    /* @5039300 load */
    /* @5039308 constant */
    /* @5039312 cmp */
    /* @5039316 b */
    p5039324_0 = NUMBOOL(GM_READ(vm, -5, "battouched") == VAL(0));
    goto L_5039324;
    L_5039320: ;
    /* @5039320 constant */
    p5039324_0 = VAL(0);
    L_5039324: ;
    /* @5039324 bf */
    if (!TRUTH(p5039324_0)) goto L_5039376;
    /* @5039328 constant */
    /* @5039332 cast */
    /* @5039336 load */
    /* @5039344 load */
    /* @5039352 call */
    GM_SITE(vm, 781, 5039352);
    /* @5039360 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(169)));
    /* @5039364 constant */
    /* @5039368 store */
    GM_WRITE(vm, -5, "battouched", VAL(1));
    L_5039376: ;
    /* @5039376 load */
    /* @5039384 constant */
    /* @5039388 cmp */
    /* @5039392 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(4)))) goto L_5039416;
    /* @5039396 load */
    /* @5039404 constant */
    /* @5039408 cmp */
    /* @5039412 b */
    p5039420_0 = NUMBOOL(GM_READ(vm, -5, "wolftouched") == VAL(0));
    goto L_5039420;
    L_5039416: ;
    /* @5039416 constant */
    p5039420_0 = VAL(0);
    L_5039420: ;
    /* @5039420 bf */
    if (!TRUTH(p5039420_0)) goto L_5039472;
    /* @5039424 constant */
    /* @5039428 cast */
    /* @5039432 load */
    /* @5039440 load */
    /* @5039448 call */
    GM_SITE(vm, 781, 5039448);
    /* @5039456 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(170)));
    /* @5039460 constant */
    /* @5039464 store */
    GM_WRITE(vm, -5, "wolftouched", VAL(1));
    L_5039472: ;
    /* @5039472 load */
    /* @5039480 constant */
    /* @5039484 cmp */
    /* @5039488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(5)))) goto L_5039512;
    /* @5039492 load */
    /* @5039500 constant */
    /* @5039504 cmp */
    /* @5039508 b */
    p5039516_0 = NUMBOOL(GM_READ(vm, -5, "pistolbandittouched") == VAL(0));
    goto L_5039516;
    L_5039512: ;
    /* @5039512 constant */
    p5039516_0 = VAL(0);
    L_5039516: ;
    /* @5039516 bf */
    if (!TRUTH(p5039516_0)) goto L_5039568;
    /* @5039520 constant */
    /* @5039524 cast */
    /* @5039528 load */
    /* @5039536 load */
    /* @5039544 call */
    GM_SITE(vm, 781, 5039544);
    /* @5039552 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(171)));
    /* @5039556 constant */
    /* @5039560 store */
    GM_WRITE(vm, -5, "pistolbandittouched", VAL(1));
    L_5039568: ;
    /* @5039568 load */
    /* @5039576 constant */
    /* @5039580 cmp */
    /* @5039584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_5039608;
    /* @5039588 load */
    /* @5039596 constant */
    /* @5039600 cmp */
    /* @5039604 b */
    p5039612_0 = NUMBOOL(GM_READ(vm, -5, "boss1touched") == VAL(0));
    goto L_5039612;
    L_5039608: ;
    /* @5039608 constant */
    p5039612_0 = VAL(0);
    L_5039612: ;
    /* @5039612 bf */
    if (!TRUTH(p5039612_0)) goto L_5039664;
    /* @5039616 constant */
    /* @5039620 cast */
    /* @5039624 load */
    /* @5039632 load */
    /* @5039640 call */
    GM_SITE(vm, 781, 5039640);
    /* @5039648 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(172)));
    /* @5039652 constant */
    /* @5039656 store */
    GM_WRITE(vm, -5, "boss1touched", VAL(1));
    L_5039664: ;
    /* @5039664 load */
    /* @5039672 constant */
    /* @5039676 cmp */
    /* @5039680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(13)))) goto L_5039704;
    /* @5039684 load */
    /* @5039692 constant */
    /* @5039696 cmp */
    /* @5039700 b */
    p5039708_0 = NUMBOOL(GM_READ(vm, -5, "turrettouched") == VAL(0));
    goto L_5039708;
    L_5039704: ;
    /* @5039704 constant */
    p5039708_0 = VAL(0);
    L_5039708: ;
    /* @5039708 bf */
    if (!TRUTH(p5039708_0)) goto L_5039760;
    /* @5039712 constant */
    /* @5039716 cast */
    /* @5039720 load */
    /* @5039728 load */
    /* @5039736 call */
    GM_SITE(vm, 781, 5039736);
    /* @5039744 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(173)));
    /* @5039748 constant */
    /* @5039752 store */
    GM_WRITE(vm, -5, "turrettouched", VAL(1));
    L_5039760: ;
    /* @5039760 load */
    /* @5039768 constant */
    /* @5039772 cmp */
    /* @5039776 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(15)))) goto L_5039800;
    /* @5039780 load */
    /* @5039788 constant */
    /* @5039792 cmp */
    /* @5039796 b */
    p5039804_0 = NUMBOOL(GM_READ(vm, -5, "slimetouched") == VAL(0));
    goto L_5039804;
    L_5039800: ;
    /* @5039800 constant */
    p5039804_0 = VAL(0);
    L_5039804: ;
    /* @5039804 bf */
    if (!TRUTH(p5039804_0)) goto L_5039856;
    /* @5039808 constant */
    /* @5039812 cast */
    /* @5039816 load */
    /* @5039824 load */
    /* @5039832 call */
    GM_SITE(vm, 781, 5039832);
    /* @5039840 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(174)));
    /* @5039844 constant */
    /* @5039848 store */
    GM_WRITE(vm, -5, "slimetouched", VAL(1));
    L_5039856: ;
    /* @5039856 load */
    /* @5039864 constant */
    /* @5039868 cmp */
    /* @5039872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_5039896;
    /* @5039876 load */
    /* @5039884 constant */
    /* @5039888 cmp */
    /* @5039892 b */
    p5039900_0 = NUMBOOL(GM_READ(vm, -5, "boss2touched") == VAL(0));
    goto L_5039900;
    L_5039896: ;
    /* @5039896 constant */
    p5039900_0 = VAL(0);
    L_5039900: ;
    /* @5039900 bf */
    if (!TRUTH(p5039900_0)) goto L_5039952;
    /* @5039904 constant */
    /* @5039908 cast */
    /* @5039912 load */
    /* @5039920 load */
    /* @5039928 call */
    GM_SITE(vm, 781, 5039928);
    /* @5039936 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(175)));
    /* @5039940 constant */
    /* @5039944 store */
    GM_WRITE(vm, -5, "boss2touched", VAL(1));
    L_5039952: ;
    /* @5039952 load */
    /* @5039960 constant */
    /* @5039964 cmp */
    /* @5039968 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(28)))) goto L_5039992;
    /* @5039972 load */
    /* @5039980 constant */
    /* @5039984 cmp */
    /* @5039988 b */
    p5039996_0 = NUMBOOL(GM_READ(vm, -5, "zombietouched") == VAL(0));
    goto L_5039996;
    L_5039992: ;
    /* @5039992 constant */
    p5039996_0 = VAL(0);
    L_5039996: ;
    /* @5039996 bf */
    if (!TRUTH(p5039996_0)) goto L_5040048;
    /* @5040000 constant */
    /* @5040004 cast */
    /* @5040008 load */
    /* @5040016 load */
    /* @5040024 call */
    GM_SITE(vm, 781, 5040024);
    /* @5040032 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(176)));
    /* @5040036 constant */
    /* @5040040 store */
    GM_WRITE(vm, -5, "zombietouched", VAL(1));
    L_5040048: ;
    /* @5040048 load */
    /* @5040056 constant */
    /* @5040060 cmp */
    /* @5040064 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(30)))) goto L_5040088;
    /* @5040068 load */
    /* @5040076 constant */
    /* @5040080 cmp */
    /* @5040084 b */
    p5040092_0 = NUMBOOL(GM_READ(vm, -5, "redslimetouched") == VAL(0));
    goto L_5040092;
    L_5040088: ;
    /* @5040088 constant */
    p5040092_0 = VAL(0);
    L_5040092: ;
    /* @5040092 bf */
    if (!TRUTH(p5040092_0)) goto L_5040144;
    /* @5040096 constant */
    /* @5040100 cast */
    /* @5040104 load */
    /* @5040112 load */
    /* @5040120 call */
    GM_SITE(vm, 781, 5040120);
    /* @5040128 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(177)));
    /* @5040132 constant */
    /* @5040136 store */
    GM_WRITE(vm, -5, "redslimetouched", VAL(1));
    L_5040144: ;
    /* @5040144 load */
    /* @5040152 constant */
    /* @5040156 cmp */
    /* @5040160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(32)))) goto L_5040184;
    /* @5040164 load */
    /* @5040172 constant */
    /* @5040176 cmp */
    /* @5040180 b */
    p5040188_0 = NUMBOOL(GM_READ(vm, -5, "skeletontouched") == VAL(0));
    goto L_5040188;
    L_5040184: ;
    /* @5040184 constant */
    p5040188_0 = VAL(0);
    L_5040188: ;
    /* @5040188 bf */
    if (!TRUTH(p5040188_0)) goto L_5040240;
    /* @5040192 constant */
    /* @5040196 cast */
    /* @5040200 load */
    /* @5040208 load */
    /* @5040216 call */
    GM_SITE(vm, 781, 5040216);
    /* @5040224 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(178)));
    /* @5040228 constant */
    /* @5040232 store */
    GM_WRITE(vm, -5, "skeletontouched", VAL(1));
    L_5040240: ;
    /* @5040240 load */
    /* @5040248 constant */
    /* @5040252 cmp */
    /* @5040256 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(36)))) goto L_5040280;
    /* @5040260 load */
    /* @5040268 constant */
    /* @5040272 cmp */
    /* @5040276 b */
    p5040284_0 = NUMBOOL(GM_READ(vm, -5, "hulkingbandittouched") == VAL(0));
    goto L_5040284;
    L_5040280: ;
    /* @5040280 constant */
    p5040284_0 = VAL(0);
    L_5040284: ;
    /* @5040284 bf */
    if (!TRUTH(p5040284_0)) goto L_5040336;
    /* @5040288 constant */
    /* @5040292 cast */
    /* @5040296 load */
    /* @5040304 load */
    /* @5040312 call */
    GM_SITE(vm, 781, 5040312);
    /* @5040320 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(179)));
    /* @5040324 constant */
    /* @5040328 store */
    GM_WRITE(vm, -5, "hulkingbandittouched", VAL(1));
    L_5040336: ;
    /* @5040336 load */
    /* @5040344 constant */
    /* @5040348 cmp */
    /* @5040352 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(39)))) goto L_5040376;
    /* @5040356 load */
    /* @5040364 constant */
    /* @5040368 cmp */
    /* @5040372 b */
    p5040380_0 = NUMBOOL(GM_READ(vm, -5, "beetouched") == VAL(0));
    goto L_5040380;
    L_5040376: ;
    /* @5040376 constant */
    p5040380_0 = VAL(0);
    L_5040380: ;
    /* @5040380 bf */
    if (!TRUTH(p5040380_0)) goto L_5040432;
    /* @5040384 constant */
    /* @5040388 cast */
    /* @5040392 load */
    /* @5040400 load */
    /* @5040408 call */
    GM_SITE(vm, 781, 5040408);
    /* @5040416 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(180)));
    /* @5040420 constant */
    /* @5040424 store */
    GM_WRITE(vm, -5, "beetouched", VAL(1));
    L_5040432: ;
    /* @5040432 load */
    /* @5040440 constant */
    /* @5040444 cmp */
    /* @5040448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_5040472;
    /* @5040452 load */
    /* @5040460 constant */
    /* @5040464 cmp */
    /* @5040468 b */
    p5040476_0 = NUMBOOL(GM_READ(vm, -5, "boss3touched") == VAL(0));
    goto L_5040476;
    L_5040472: ;
    /* @5040472 constant */
    p5040476_0 = VAL(0);
    L_5040476: ;
    /* @5040476 bf */
    if (!TRUTH(p5040476_0)) goto L_5040528;
    /* @5040480 constant */
    /* @5040484 cast */
    /* @5040488 load */
    /* @5040496 load */
    /* @5040504 call */
    GM_SITE(vm, 781, 5040504);
    /* @5040512 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(181)));
    /* @5040516 constant */
    /* @5040520 store */
    GM_WRITE(vm, -5, "boss3touched", VAL(1));
    L_5040528: ;
    /* @5040528 load */
    /* @5040536 constant */
    /* @5040540 cmp */
    /* @5040544 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(49)))) goto L_5040568;
    /* @5040548 load */
    /* @5040556 constant */
    /* @5040560 cmp */
    /* @5040564 b */
    p5040572_0 = NUMBOOL(GM_READ(vm, -5, "firehulktouched") == VAL(0));
    goto L_5040572;
    L_5040568: ;
    /* @5040568 constant */
    p5040572_0 = VAL(0);
    L_5040572: ;
    /* @5040572 bf */
    if (!TRUTH(p5040572_0)) goto L_5040624;
    /* @5040576 constant */
    /* @5040580 cast */
    /* @5040584 load */
    /* @5040592 load */
    /* @5040600 call */
    GM_SITE(vm, 781, 5040600);
    /* @5040608 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(182)));
    /* @5040612 constant */
    /* @5040616 store */
    GM_WRITE(vm, -5, "firehulktouched", VAL(1));
    L_5040624: ;
    /* @5040624 load */
    /* @5040632 constant */
    /* @5040636 cmp */
    /* @5040640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_5040664;
    /* @5040644 load */
    /* @5040652 constant */
    /* @5040656 cmp */
    /* @5040660 b */
    p5040668_0 = NUMBOOL(GM_READ(vm, -5, "boss4touched") == VAL(0));
    goto L_5040668;
    L_5040664: ;
    /* @5040664 constant */
    p5040668_0 = VAL(0);
    L_5040668: ;
    /* @5040668 bf */
    if (!TRUTH(p5040668_0)) goto L_5040720;
    /* @5040672 constant */
    /* @5040676 cast */
    /* @5040680 load */
    /* @5040688 load */
    /* @5040696 call */
    GM_SITE(vm, 781, 5040696);
    /* @5040704 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(183)));
    /* @5040708 constant */
    /* @5040712 store */
    GM_WRITE(vm, -5, "boss4touched", VAL(1));
    L_5040720: ;
    /* @5040720 load */
    /* @5040728 constant */
    /* @5040732 cmp */
    /* @5040736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_5040760;
    /* @5040740 load */
    /* @5040748 constant */
    /* @5040752 cmp */
    /* @5040756 b */
    p5040764_0 = NUMBOOL(GM_READ(vm, -5, "boss5touched") == VAL(0));
    goto L_5040764;
    L_5040760: ;
    /* @5040760 constant */
    p5040764_0 = VAL(0);
    L_5040764: ;
    /* @5040764 bf */
    if (!TRUTH(p5040764_0)) goto L_5040816;
    /* @5040768 constant */
    /* @5040772 cast */
    /* @5040776 load */
    /* @5040784 load */
    /* @5040792 call */
    GM_SITE(vm, 781, 5040792);
    /* @5040800 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(184)));
    /* @5040804 constant */
    /* @5040808 store */
    GM_WRITE(vm, -5, "boss5touched", VAL(1));
    L_5040816: ;
    /* @5040816 load */
    /* @5040824 constant */
    /* @5040828 cmp */
    /* @5040832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_5040856;
    /* @5040836 load */
    /* @5040844 constant */
    /* @5040848 cmp */
    /* @5040852 b */
    p5040860_0 = NUMBOOL(GM_READ(vm, -5, "boss6touched") == VAL(0));
    goto L_5040860;
    L_5040856: ;
    /* @5040856 constant */
    p5040860_0 = VAL(0);
    L_5040860: ;
    /* @5040860 bf */
    if (!TRUTH(p5040860_0)) goto L_5040912;
    /* @5040864 constant */
    /* @5040868 cast */
    /* @5040872 load */
    /* @5040880 load */
    /* @5040888 call */
    GM_SITE(vm, 781, 5040888);
    /* @5040896 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(185)));
    /* @5040900 constant */
    /* @5040904 store */
    GM_WRITE(vm, -5, "boss6touched", VAL(1));
    L_5040912: ;
    return;
}
