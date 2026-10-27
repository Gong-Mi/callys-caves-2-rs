/* generated from CODE 692 (gml_Object_obj_maptile_Mouse_7), source start 5017220, end 5018084. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0692(GmVM* vm) {
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
    /* @5017220 load */
    /* @5017228 constant */
    /* @5017232 cmp */
    /* @5017236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_5017244;
    /* @5017240 b */
    goto L_5017276;
    L_5017244: ;
    /* @5017244 load */
    /* @5017252 constant */
    /* @5017256 cmp */
    /* @5017260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_5017276;
    /* @5017264 call */
    GM_SITE(vm, 692, 5017264);
    /* @5017272 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    L_5017276: ;
    /* @5017276 constant */
    /* @5017280 cast */
    /* @5017284 call */
    GM_SITE(vm, 692, 5017284);
    /* @5017292 cast */
    /* @5017296 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(99)));
    if (!TRUTH(v1)) goto L_5017324;
    /* @5017300 constant */
    /* @5017304 pushenv */
    if (!GM_PUSHENV(vm, VAL(99))) goto L_5017320;
    L_5017308: ;
    /* @5017308 call */
    GM_SITE(vm, 692, 5017308);
    /* @5017316 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017320: ;
    /* @5017320 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017308;
    L_5017324: ;
    /* @5017324 constant */
    /* @5017328 cast */
    /* @5017332 call */
    GM_SITE(vm, 692, 5017332);
    /* @5017340 cast */
    /* @5017344 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(115)));
    if (!TRUTH(v2)) goto L_5017372;
    /* @5017348 constant */
    /* @5017352 pushenv */
    if (!GM_PUSHENV(vm, VAL(115))) goto L_5017368;
    L_5017356: ;
    /* @5017356 call */
    GM_SITE(vm, 692, 5017356);
    /* @5017364 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017368: ;
    /* @5017368 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017356;
    L_5017372: ;
    /* @5017372 constant */
    /* @5017376 cast */
    /* @5017380 call */
    GM_SITE(vm, 692, 5017380);
    /* @5017388 cast */
    /* @5017392 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(122)));
    if (!TRUTH(v3)) goto L_5017420;
    /* @5017396 constant */
    /* @5017400 pushenv */
    if (!GM_PUSHENV(vm, VAL(122))) goto L_5017416;
    L_5017404: ;
    /* @5017404 call */
    GM_SITE(vm, 692, 5017404);
    /* @5017412 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017416: ;
    /* @5017416 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017404;
    L_5017420: ;
    /* @5017420 constant */
    /* @5017424 cast */
    /* @5017428 call */
    GM_SITE(vm, 692, 5017428);
    /* @5017436 cast */
    /* @5017440 bf */
    v4 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(110)));
    if (!TRUTH(v4)) goto L_5017468;
    /* @5017444 constant */
    /* @5017448 pushenv */
    if (!GM_PUSHENV(vm, VAL(110))) goto L_5017464;
    L_5017452: ;
    /* @5017452 call */
    GM_SITE(vm, 692, 5017452);
    /* @5017460 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017464: ;
    /* @5017464 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017452;
    L_5017468: ;
    /* @5017468 constant */
    /* @5017472 cast */
    /* @5017476 call */
    GM_SITE(vm, 692, 5017476);
    /* @5017484 cast */
    /* @5017488 bf */
    v5 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(107)));
    if (!TRUTH(v5)) goto L_5017516;
    /* @5017492 constant */
    /* @5017496 pushenv */
    if (!GM_PUSHENV(vm, VAL(107))) goto L_5017512;
    L_5017500: ;
    /* @5017500 call */
    GM_SITE(vm, 692, 5017500);
    /* @5017508 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017512: ;
    /* @5017512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017500;
    L_5017516: ;
    /* @5017516 constant */
    /* @5017520 cast */
    /* @5017524 call */
    GM_SITE(vm, 692, 5017524);
    /* @5017532 cast */
    /* @5017536 bf */
    v6 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(109)));
    if (!TRUTH(v6)) goto L_5017564;
    /* @5017540 constant */
    /* @5017544 pushenv */
    if (!GM_PUSHENV(vm, VAL(109))) goto L_5017560;
    L_5017548: ;
    /* @5017548 call */
    GM_SITE(vm, 692, 5017548);
    /* @5017556 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017560: ;
    /* @5017560 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017548;
    L_5017564: ;
    /* @5017564 constant */
    /* @5017568 cast */
    /* @5017572 call */
    GM_SITE(vm, 692, 5017572);
    /* @5017580 cast */
    /* @5017584 bf */
    v7 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(118)));
    if (!TRUTH(v7)) goto L_5017612;
    /* @5017588 constant */
    /* @5017592 pushenv */
    if (!GM_PUSHENV(vm, VAL(118))) goto L_5017608;
    L_5017596: ;
    /* @5017596 call */
    GM_SITE(vm, 692, 5017596);
    /* @5017604 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017608: ;
    /* @5017608 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017596;
    L_5017612: ;
    /* @5017612 constant */
    /* @5017616 cast */
    /* @5017620 call */
    GM_SITE(vm, 692, 5017620);
    /* @5017628 cast */
    /* @5017632 bf */
    v8 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(108)));
    if (!TRUTH(v8)) goto L_5017660;
    /* @5017636 constant */
    /* @5017640 pushenv */
    if (!GM_PUSHENV(vm, VAL(108))) goto L_5017656;
    L_5017644: ;
    /* @5017644 call */
    GM_SITE(vm, 692, 5017644);
    /* @5017652 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017656: ;
    /* @5017656 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017644;
    L_5017660: ;
    /* @5017660 constant */
    /* @5017664 cast */
    /* @5017668 call */
    GM_SITE(vm, 692, 5017668);
    /* @5017676 cast */
    /* @5017680 bf */
    v9 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(116)));
    if (!TRUTH(v9)) goto L_5017708;
    /* @5017684 constant */
    /* @5017688 pushenv */
    if (!GM_PUSHENV(vm, VAL(116))) goto L_5017704;
    L_5017692: ;
    /* @5017692 call */
    GM_SITE(vm, 692, 5017692);
    /* @5017700 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017704: ;
    /* @5017704 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017692;
    L_5017708: ;
    /* @5017708 constant */
    /* @5017712 cast */
    /* @5017716 call */
    GM_SITE(vm, 692, 5017716);
    /* @5017724 cast */
    /* @5017728 bf */
    v10 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(123)));
    if (!TRUTH(v10)) goto L_5017756;
    /* @5017732 constant */
    /* @5017736 pushenv */
    if (!GM_PUSHENV(vm, VAL(123))) goto L_5017752;
    L_5017740: ;
    /* @5017740 call */
    GM_SITE(vm, 692, 5017740);
    /* @5017748 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017752: ;
    /* @5017752 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017740;
    L_5017756: ;
    /* @5017756 constant */
    /* @5017760 cast */
    /* @5017764 call */
    GM_SITE(vm, 692, 5017764);
    /* @5017772 cast */
    /* @5017776 bf */
    v11 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(119)));
    if (!TRUTH(v11)) goto L_5017804;
    /* @5017780 constant */
    /* @5017784 pushenv */
    if (!GM_PUSHENV(vm, VAL(119))) goto L_5017800;
    L_5017788: ;
    /* @5017788 call */
    GM_SITE(vm, 692, 5017788);
    /* @5017796 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017800: ;
    /* @5017800 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017788;
    L_5017804: ;
    /* @5017804 constant */
    /* @5017808 cast */
    /* @5017812 call */
    GM_SITE(vm, 692, 5017812);
    /* @5017820 cast */
    /* @5017824 bf */
    v12 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(120)));
    if (!TRUTH(v12)) goto L_5017852;
    /* @5017828 constant */
    /* @5017832 pushenv */
    if (!GM_PUSHENV(vm, VAL(120))) goto L_5017848;
    L_5017836: ;
    /* @5017836 call */
    GM_SITE(vm, 692, 5017836);
    /* @5017844 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017848: ;
    /* @5017848 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017836;
    L_5017852: ;
    /* @5017852 constant */
    /* @5017856 cast */
    /* @5017860 call */
    GM_SITE(vm, 692, 5017860);
    /* @5017868 cast */
    /* @5017872 bf */
    v13 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114)));
    if (!TRUTH(v13)) goto L_5017900;
    /* @5017876 constant */
    /* @5017880 pushenv */
    if (!GM_PUSHENV(vm, VAL(114))) goto L_5017896;
    L_5017884: ;
    /* @5017884 call */
    GM_SITE(vm, 692, 5017884);
    /* @5017892 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017896: ;
    /* @5017896 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017884;
    L_5017900: ;
    /* @5017900 constant */
    /* @5017904 cast */
    /* @5017908 call */
    GM_SITE(vm, 692, 5017908);
    /* @5017916 cast */
    /* @5017920 bf */
    v14 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(112)));
    if (!TRUTH(v14)) goto L_5017948;
    /* @5017924 constant */
    /* @5017928 pushenv */
    if (!GM_PUSHENV(vm, VAL(112))) goto L_5017944;
    L_5017932: ;
    /* @5017932 call */
    GM_SITE(vm, 692, 5017932);
    /* @5017940 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017944: ;
    /* @5017944 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017932;
    L_5017948: ;
    /* @5017948 constant */
    /* @5017952 cast */
    /* @5017956 call */
    GM_SITE(vm, 692, 5017956);
    /* @5017964 cast */
    /* @5017968 bf */
    v15 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(113)));
    if (!TRUTH(v15)) goto L_5017996;
    /* @5017972 constant */
    /* @5017976 pushenv */
    if (!GM_PUSHENV(vm, VAL(113))) goto L_5017992;
    L_5017980: ;
    /* @5017980 call */
    GM_SITE(vm, 692, 5017980);
    /* @5017988 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5017992: ;
    /* @5017992 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5017980;
    L_5017996: ;
    /* @5017996 call */
    GM_SITE(vm, 692, 5017996);
    /* @5018004 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @5018008 constant */
    /* @5018012 store */
    GM_WRITE(vm, -5, "warpfrommap", VAL(1));
    /* @5018020 load */
    /* @5018028 cast */
    /* @5018032 load */
    /* @5018040 call */
    GM_SITE(vm, 692, 5018040);
    /* @5018048 popz */
    (void)(GM_CALL(vm, "room_goto", 1, GM_READ(vm, TO_INT(GM_READ(vm, -1, "id")), "goto")));
    /* @5018052 load */
    /* @5018060 store */
    GM_WRITE(vm, 0, "x", GM_READ(vm, -5, "startx"));
    /* @5018068 load */
    /* @5018076 store */
    GM_WRITE(vm, 0, "y", GM_READ(vm, -5, "starty"));
    L_5018084: ;
    return;
}
