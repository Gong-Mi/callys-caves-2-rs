/* generated from CODE 470 (gml_Object_obj_backtogame_Mouse_7), source start 4646480, end 4648032. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0470(GmVM* vm) {
    Val p4646544_0;
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
    /* @4646480 load */
    /* @4646488 constant */
    /* @4646492 cmp */
    /* @4646496 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(111)))) goto L_4646540;
    /* @4646500 load */
    /* @4646508 constant */
    /* @4646512 cmp */
    /* @4646516 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4646540;
    /* @4646520 load */
    /* @4646528 constant */
    /* @4646532 cmp */
    /* @4646536 b */
    p4646544_0 = NUMBOOL(GM_READ(vm, -1, "room") == VAL(112));
    goto L_4646544;
    L_4646540: ;
    /* @4646540 constant */
    p4646544_0 = VAL(1);
    L_4646544: ;
    /* @4646544 bf */
    if (!TRUTH(p4646544_0)) goto L_4646672;
    /* @4646548 load */
    /* @4646556 call */
    GM_SITE(vm, 470, 4646556);
    /* @4646564 popz */
    (void)(GM_CALL(vm, "room_goto", 1, GM_READ(vm, -5, "roomcamefrom")));
    /* @4646568 load */
    /* @4646576 constant */
    /* @4646580 cmp */
    /* @4646584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4646592;
    /* @4646588 b */
    goto L_4646624;
    L_4646592: ;
    /* @4646592 load */
    /* @4646600 constant */
    /* @4646604 cmp */
    /* @4646608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4646624;
    /* @4646612 call */
    GM_SITE(vm, 470, 4646612);
    /* @4646620 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    L_4646624: ;
    /* @4646624 load */
    /* @4646632 store */
    GM_WRITE(vm, 0, "x", GM_READ(vm, -5, "startx"));
    /* @4646640 load */
    /* @4646648 store */
    GM_WRITE(vm, 0, "y", GM_READ(vm, -5, "starty"));
    /* @4646656 call */
    GM_SITE(vm, 470, 4646656);
    /* @4646664 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4646668 b */
    goto L_4647460;
    L_4646672: ;
    /* @4646672 load */
    /* @4646680 constant */
    /* @4646684 cmp */
    /* @4646688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4646696;
    /* @4646692 b */
    goto L_4646728;
    L_4646696: ;
    /* @4646696 load */
    /* @4646704 constant */
    /* @4646708 cmp */
    /* @4646712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4646728;
    /* @4646716 call */
    GM_SITE(vm, 470, 4646716);
    /* @4646724 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    L_4646728: ;
    /* @4646728 call */
    GM_SITE(vm, 470, 4646728);
    /* @4646736 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4646740 constant */
    /* @4646744 cast */
    /* @4646748 call */
    GM_SITE(vm, 470, 4646748);
    /* @4646756 cast */
    /* @4646760 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(99)));
    if (!TRUTH(v1)) goto L_4646788;
    /* @4646764 constant */
    /* @4646768 pushenv */
    if (!GM_PUSHENV(vm, VAL(99))) goto L_4646784;
    L_4646772: ;
    /* @4646772 call */
    GM_SITE(vm, 470, 4646772);
    /* @4646780 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4646784: ;
    /* @4646784 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4646772;
    L_4646788: ;
    /* @4646788 constant */
    /* @4646792 cast */
    /* @4646796 call */
    GM_SITE(vm, 470, 4646796);
    /* @4646804 cast */
    /* @4646808 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(115)));
    if (!TRUTH(v2)) goto L_4646836;
    /* @4646812 constant */
    /* @4646816 pushenv */
    if (!GM_PUSHENV(vm, VAL(115))) goto L_4646832;
    L_4646820: ;
    /* @4646820 call */
    GM_SITE(vm, 470, 4646820);
    /* @4646828 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4646832: ;
    /* @4646832 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4646820;
    L_4646836: ;
    /* @4646836 constant */
    /* @4646840 cast */
    /* @4646844 call */
    GM_SITE(vm, 470, 4646844);
    /* @4646852 cast */
    /* @4646856 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(122)));
    if (!TRUTH(v3)) goto L_4646884;
    /* @4646860 constant */
    /* @4646864 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_4646880;
    L_4646868: ;
    /* @4646868 call */
    GM_SITE(vm, 470, 4646868);
    /* @4646876 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4646880: ;
    /* @4646880 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4646868;
    L_4646884: ;
    /* @4646884 constant */
    /* @4646888 cast */
    /* @4646892 call */
    GM_SITE(vm, 470, 4646892);
    /* @4646900 cast */
    /* @4646904 bf */
    v4 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(110)));
    if (!TRUTH(v4)) goto L_4646932;
    /* @4646908 constant */
    /* @4646912 pushenv */
    if (!GM_PUSHENV(vm, VAL(110))) goto L_4646928;
    L_4646916: ;
    /* @4646916 call */
    GM_SITE(vm, 470, 4646916);
    /* @4646924 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4646928: ;
    /* @4646928 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4646916;
    L_4646932: ;
    /* @4646932 constant */
    /* @4646936 cast */
    /* @4646940 call */
    GM_SITE(vm, 470, 4646940);
    /* @4646948 cast */
    /* @4646952 bf */
    v5 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(107)));
    if (!TRUTH(v5)) goto L_4646980;
    /* @4646956 constant */
    /* @4646960 pushenv */
    if (!GM_PUSHENV(vm, VAL(107))) goto L_4646976;
    L_4646964: ;
    /* @4646964 call */
    GM_SITE(vm, 470, 4646964);
    /* @4646972 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4646976: ;
    /* @4646976 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4646964;
    L_4646980: ;
    /* @4646980 constant */
    /* @4646984 cast */
    /* @4646988 call */
    GM_SITE(vm, 470, 4646988);
    /* @4646996 cast */
    /* @4647000 bf */
    v6 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(109)));
    if (!TRUTH(v6)) goto L_4647028;
    /* @4647004 constant */
    /* @4647008 pushenv */
    if (!GM_PUSHENV(vm, VAL(109))) goto L_4647024;
    L_4647012: ;
    /* @4647012 call */
    GM_SITE(vm, 470, 4647012);
    /* @4647020 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647024: ;
    /* @4647024 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647012;
    L_4647028: ;
    /* @4647028 constant */
    /* @4647032 cast */
    /* @4647036 call */
    GM_SITE(vm, 470, 4647036);
    /* @4647044 cast */
    /* @4647048 bf */
    v7 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(118)));
    if (!TRUTH(v7)) goto L_4647076;
    /* @4647052 constant */
    /* @4647056 pushenv */
    if (!GM_PUSHENV(vm, VAL(118))) goto L_4647072;
    L_4647060: ;
    /* @4647060 call */
    GM_SITE(vm, 470, 4647060);
    /* @4647068 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647072: ;
    /* @4647072 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647060;
    L_4647076: ;
    /* @4647076 constant */
    /* @4647080 cast */
    /* @4647084 call */
    GM_SITE(vm, 470, 4647084);
    /* @4647092 cast */
    /* @4647096 bf */
    v8 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(108)));
    if (!TRUTH(v8)) goto L_4647124;
    /* @4647100 constant */
    /* @4647104 pushenv */
    if (!GM_PUSHENV(vm, VAL(108))) goto L_4647120;
    L_4647108: ;
    /* @4647108 call */
    GM_SITE(vm, 470, 4647108);
    /* @4647116 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647120: ;
    /* @4647120 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647108;
    L_4647124: ;
    /* @4647124 constant */
    /* @4647128 cast */
    /* @4647132 call */
    GM_SITE(vm, 470, 4647132);
    /* @4647140 cast */
    /* @4647144 bf */
    v9 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(116)));
    if (!TRUTH(v9)) goto L_4647172;
    /* @4647148 constant */
    /* @4647152 pushenv */
    if (!GM_PUSHENV(vm, VAL(116))) goto L_4647168;
    L_4647156: ;
    /* @4647156 call */
    GM_SITE(vm, 470, 4647156);
    /* @4647164 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647168: ;
    /* @4647168 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647156;
    L_4647172: ;
    /* @4647172 constant */
    /* @4647176 cast */
    /* @4647180 call */
    GM_SITE(vm, 470, 4647180);
    /* @4647188 cast */
    /* @4647192 bf */
    v10 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(123)));
    if (!TRUTH(v10)) goto L_4647220;
    /* @4647196 constant */
    /* @4647200 pushenv */
    if (!GM_PUSHENV(vm, VAL(123))) goto L_4647216;
    L_4647204: ;
    /* @4647204 call */
    GM_SITE(vm, 470, 4647204);
    /* @4647212 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647216: ;
    /* @4647216 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647204;
    L_4647220: ;
    /* @4647220 constant */
    /* @4647224 cast */
    /* @4647228 call */
    GM_SITE(vm, 470, 4647228);
    /* @4647236 cast */
    /* @4647240 bf */
    v11 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(119)));
    if (!TRUTH(v11)) goto L_4647268;
    /* @4647244 constant */
    /* @4647248 pushenv */
    if (!GM_PUSHENV(vm, VAL(119))) goto L_4647264;
    L_4647252: ;
    /* @4647252 call */
    GM_SITE(vm, 470, 4647252);
    /* @4647260 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647264: ;
    /* @4647264 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647252;
    L_4647268: ;
    /* @4647268 constant */
    /* @4647272 cast */
    /* @4647276 call */
    GM_SITE(vm, 470, 4647276);
    /* @4647284 cast */
    /* @4647288 bf */
    v12 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(120)));
    if (!TRUTH(v12)) goto L_4647316;
    /* @4647292 constant */
    /* @4647296 pushenv */
    if (!GM_PUSHENV(vm, VAL(120))) goto L_4647312;
    L_4647300: ;
    /* @4647300 call */
    GM_SITE(vm, 470, 4647300);
    /* @4647308 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647312: ;
    /* @4647312 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647300;
    L_4647316: ;
    /* @4647316 constant */
    /* @4647320 cast */
    /* @4647324 call */
    GM_SITE(vm, 470, 4647324);
    /* @4647332 cast */
    /* @4647336 bf */
    v13 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114)));
    if (!TRUTH(v13)) goto L_4647364;
    /* @4647340 constant */
    /* @4647344 pushenv */
    if (!GM_PUSHENV(vm, VAL(114))) goto L_4647360;
    L_4647348: ;
    /* @4647348 call */
    GM_SITE(vm, 470, 4647348);
    /* @4647356 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647360: ;
    /* @4647360 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647348;
    L_4647364: ;
    /* @4647364 constant */
    /* @4647368 cast */
    /* @4647372 call */
    GM_SITE(vm, 470, 4647372);
    /* @4647380 cast */
    /* @4647384 bf */
    v14 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(112)));
    if (!TRUTH(v14)) goto L_4647412;
    /* @4647388 constant */
    /* @4647392 pushenv */
    if (!GM_PUSHENV(vm, VAL(112))) goto L_4647408;
    L_4647396: ;
    /* @4647396 call */
    GM_SITE(vm, 470, 4647396);
    /* @4647404 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647408: ;
    /* @4647408 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647396;
    L_4647412: ;
    /* @4647412 constant */
    /* @4647416 cast */
    /* @4647420 call */
    GM_SITE(vm, 470, 4647420);
    /* @4647428 cast */
    /* @4647432 bf */
    v15 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(113)));
    if (!TRUTH(v15)) goto L_4647460;
    /* @4647436 constant */
    /* @4647440 pushenv */
    if (!GM_PUSHENV(vm, VAL(113))) goto L_4647456;
    L_4647444: ;
    /* @4647444 call */
    GM_SITE(vm, 470, 4647444);
    /* @4647452 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4647456: ;
    /* @4647456 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4647444;
    L_4647460: ;
    /* @4647460 load */
    /* @4647468 constant */
    /* @4647472 cmp */
    /* @4647476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4647484;
    /* @4647480 b */
    goto L_4648032;
    L_4647484: ;
    /* @4647484 load */
    /* @4647492 constant */
    /* @4647496 cmp */
    /* @4647500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4648032;
    /* @4647504 load */
    /* @4647512 constant */
    /* @4647516 cmp */
    /* @4647520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(10)))) goto L_4647592;
    /* @4647524 load */
    /* @4647532 constant */
    /* @4647536 cmp */
    /* @4647540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss1dead") == VAL(0)))) goto L_4647592;
    /* @4647544 call */
    GM_SITE(vm, 470, 4647544);
    /* @4647552 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647556 constant */
    /* @4647560 cast */
    /* @4647564 constant */
    /* @4647568 cast */
    /* @4647572 constant */
    /* @4647576 cast */
    /* @4647580 call */
    GM_SITE(vm, 470, 4647580);
    /* @4647588 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4647592: ;
    /* @4647592 load */
    /* @4647600 constant */
    /* @4647604 cmp */
    /* @4647608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(27)))) goto L_4647680;
    /* @4647612 load */
    /* @4647620 constant */
    /* @4647624 cmp */
    /* @4647628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss2dead") == VAL(0)))) goto L_4647680;
    /* @4647632 call */
    GM_SITE(vm, 470, 4647632);
    /* @4647640 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647644 constant */
    /* @4647648 cast */
    /* @4647652 constant */
    /* @4647656 cast */
    /* @4647660 constant */
    /* @4647664 cast */
    /* @4647668 call */
    GM_SITE(vm, 470, 4647668);
    /* @4647676 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4647680: ;
    /* @4647680 load */
    /* @4647688 constant */
    /* @4647692 cmp */
    /* @4647696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(48)))) goto L_4647768;
    /* @4647700 load */
    /* @4647708 constant */
    /* @4647712 cmp */
    /* @4647716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss3dead") == VAL(0)))) goto L_4647768;
    /* @4647720 call */
    GM_SITE(vm, 470, 4647720);
    /* @4647728 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647732 constant */
    /* @4647736 cast */
    /* @4647740 constant */
    /* @4647744 cast */
    /* @4647748 constant */
    /* @4647752 cast */
    /* @4647756 call */
    GM_SITE(vm, 470, 4647756);
    /* @4647764 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4647768: ;
    /* @4647768 load */
    /* @4647776 constant */
    /* @4647780 cmp */
    /* @4647784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(64)))) goto L_4647856;
    /* @4647788 load */
    /* @4647796 constant */
    /* @4647800 cmp */
    /* @4647804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss4dead") == VAL(0)))) goto L_4647856;
    /* @4647808 call */
    GM_SITE(vm, 470, 4647808);
    /* @4647816 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647820 constant */
    /* @4647824 cast */
    /* @4647828 constant */
    /* @4647832 cast */
    /* @4647836 constant */
    /* @4647840 cast */
    /* @4647844 call */
    GM_SITE(vm, 470, 4647844);
    /* @4647852 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4647856: ;
    /* @4647856 load */
    /* @4647864 constant */
    /* @4647868 cmp */
    /* @4647872 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(82)))) goto L_4647944;
    /* @4647876 load */
    /* @4647884 constant */
    /* @4647888 cmp */
    /* @4647892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss5dead") == VAL(0)))) goto L_4647944;
    /* @4647896 call */
    GM_SITE(vm, 470, 4647896);
    /* @4647904 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647908 constant */
    /* @4647912 cast */
    /* @4647916 constant */
    /* @4647920 cast */
    /* @4647924 constant */
    /* @4647928 cast */
    /* @4647932 call */
    GM_SITE(vm, 470, 4647932);
    /* @4647940 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(51), VAL(0), VAL(1)));
    L_4647944: ;
    /* @4647944 load */
    /* @4647952 constant */
    /* @4647956 cmp */
    /* @4647960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(104)))) goto L_4648032;
    /* @4647964 load */
    /* @4647972 constant */
    /* @4647976 cmp */
    /* @4647980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss6dead") == VAL(0)))) goto L_4648032;
    /* @4647984 call */
    GM_SITE(vm, 470, 4647984);
    /* @4647992 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4647996 constant */
    /* @4648000 cast */
    /* @4648004 constant */
    /* @4648008 cast */
    /* @4648012 constant */
    /* @4648016 cast */
    /* @4648020 call */
    GM_SITE(vm, 470, 4648020);
    /* @4648028 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(48), VAL(0), VAL(1)));
    L_4648032: ;
    return;
}
