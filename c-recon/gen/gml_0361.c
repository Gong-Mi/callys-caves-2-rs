/* generated from CODE 361 (gml_Object_obj_bg_Alarm_2), source start 4216204, end 4216996. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0361(GmVM* vm) {
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
    /* @4216204 constant */
    /* @4216208 cast */
    /* @4216212 constant */
    /* @4216216 cast */
    /* @4216220 constant */
    /* @4216224 cast */
    /* @4216228 load */
    /* @4216236 constant */
    /* @4216240 sub */
    /* @4216244 load */
    /* @4216252 constant */
    /* @4216256 sub */
    /* @4216260 call */
    GM_SITE(vm, 361, 4216260);
    /* @4216268 popz */
    (void)(GM_CALL(vm, "instance_activate_region", 5, (GM_READ(vm, 0, "x") - VAL(400)), (GM_READ(vm, 0, "y") - VAL(400)), VAL(800), VAL(800), VAL(1)));
    /* @4216272 constant */
    /* @4216276 pushenv */
    if (!GM_PUSHENV(vm, VAL(11))) goto L_4216328;
    L_4216280: ;
    /* @4216280 constant */
    /* @4216284 cast */
    /* @4216288 call */
    GM_SITE(vm, 361, 4216288);
    /* @4216296 constant */
    /* @4216300 cmp */
    /* @4216304 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(450));
    if (!TRUTH(v1)) goto L_4216328;
    /* @4216308 load */
    /* @4216316 call */
    GM_SITE(vm, 361, 4216316);
    /* @4216324 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216328: ;
    /* @4216328 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216280;
    /* @4216332 constant */
    /* @4216336 pushenv */
    if (!GM_PUSHENV(vm, VAL(4))) goto L_4216420;
    L_4216340: ;
    /* @4216340 load */
    /* @4216348 cast */
    /* @4216352 load */
    /* @4216360 constant */
    /* @4216364 cmp */
    /* @4216368 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, TO_INT(GM_READ(vm, -1, "id")), "image_yscale") == VAL(-1)))) goto L_4216420;
    /* @4216372 constant */
    /* @4216376 cast */
    /* @4216380 call */
    GM_SITE(vm, 361, 4216380);
    /* @4216388 constant */
    /* @4216392 cmp */
    /* @4216396 bf */
    v2 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v2)) goto L_4216420;
    /* @4216400 load */
    /* @4216408 call */
    GM_SITE(vm, 361, 4216408);
    /* @4216416 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216420: ;
    /* @4216420 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216340;
    /* @4216424 constant */
    /* @4216428 pushenv */
    if (!GM_PUSHENV(vm, VAL(58))) goto L_4216480;
    L_4216432: ;
    /* @4216432 constant */
    /* @4216436 cast */
    /* @4216440 call */
    GM_SITE(vm, 361, 4216440);
    /* @4216448 constant */
    /* @4216452 cmp */
    /* @4216456 bf */
    v3 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(400));
    if (!TRUTH(v3)) goto L_4216480;
    /* @4216460 load */
    /* @4216468 call */
    GM_SITE(vm, 361, 4216468);
    /* @4216476 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216480: ;
    /* @4216480 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216432;
    /* @4216484 constant */
    /* @4216488 pushenv */
    if (!GM_PUSHENV(vm, VAL(60))) goto L_4216552;
    L_4216492: ;
    /* @4216492 constant */
    /* @4216496 cast */
    /* @4216500 call */
    GM_SITE(vm, 361, 4216500);
    /* @4216508 constant */
    /* @4216512 cmp */
    /* @4216516 bf */
    v4 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(400));
    if (!TRUTH(v4)) goto L_4216552;
    /* @4216520 load */
    /* @4216528 cast */
    /* @4216532 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -1, "id")))) goto L_4216548;
    L_4216536: ;
    /* @4216536 call */
    GM_SITE(vm, 361, 4216536);
    /* @4216544 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4216548: ;
    /* @4216548 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216536;
    L_4216552: ;
    /* @4216552 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216492;
    /* @4216556 constant */
    /* @4216560 pushenv */
    if (!GM_PUSHENV(vm, VAL(59))) goto L_4216612;
    L_4216564: ;
    /* @4216564 constant */
    /* @4216568 cast */
    /* @4216572 call */
    GM_SITE(vm, 361, 4216572);
    /* @4216580 constant */
    /* @4216584 cmp */
    /* @4216588 bf */
    v5 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(400));
    if (!TRUTH(v5)) goto L_4216612;
    /* @4216592 load */
    /* @4216600 call */
    GM_SITE(vm, 361, 4216600);
    /* @4216608 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216612: ;
    /* @4216612 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216564;
    /* @4216616 constant */
    /* @4216620 pushenv */
    if (!GM_PUSHENV(vm, VAL(5))) goto L_4216672;
    L_4216624: ;
    /* @4216624 constant */
    /* @4216628 cast */
    /* @4216632 call */
    GM_SITE(vm, 361, 4216632);
    /* @4216640 constant */
    /* @4216644 cmp */
    /* @4216648 bf */
    v6 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v6)) goto L_4216672;
    /* @4216652 load */
    /* @4216660 call */
    GM_SITE(vm, 361, 4216660);
    /* @4216668 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216672: ;
    /* @4216672 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216624;
    /* @4216676 constant */
    /* @4216680 pushenv */
    if (!GM_PUSHENV(vm, VAL(10))) goto L_4216732;
    L_4216684: ;
    /* @4216684 constant */
    /* @4216688 cast */
    /* @4216692 call */
    GM_SITE(vm, 361, 4216692);
    /* @4216700 constant */
    /* @4216704 cmp */
    /* @4216708 bf */
    v7 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v7)) goto L_4216732;
    /* @4216712 load */
    /* @4216720 call */
    GM_SITE(vm, 361, 4216720);
    /* @4216728 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216732: ;
    /* @4216732 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216684;
    /* @4216736 constant */
    /* @4216740 pushenv */
    if (!GM_PUSHENV(vm, VAL(8))) goto L_4216792;
    L_4216744: ;
    /* @4216744 constant */
    /* @4216748 cast */
    /* @4216752 call */
    GM_SITE(vm, 361, 4216752);
    /* @4216760 constant */
    /* @4216764 cmp */
    /* @4216768 bf */
    v8 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v8)) goto L_4216792;
    /* @4216772 load */
    /* @4216780 call */
    GM_SITE(vm, 361, 4216780);
    /* @4216788 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216792: ;
    /* @4216792 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216744;
    /* @4216796 constant */
    /* @4216800 pushenv */
    if (!GM_PUSHENV(vm, VAL(7))) goto L_4216852;
    L_4216804: ;
    /* @4216804 constant */
    /* @4216808 cast */
    /* @4216812 call */
    GM_SITE(vm, 361, 4216812);
    /* @4216820 constant */
    /* @4216824 cmp */
    /* @4216828 bf */
    v9 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v9)) goto L_4216852;
    /* @4216832 load */
    /* @4216840 call */
    GM_SITE(vm, 361, 4216840);
    /* @4216848 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216852: ;
    /* @4216852 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216804;
    /* @4216856 constant */
    /* @4216860 pushenv */
    if (!GM_PUSHENV(vm, VAL(69))) goto L_4216912;
    L_4216864: ;
    /* @4216864 constant */
    /* @4216868 cast */
    /* @4216872 call */
    GM_SITE(vm, 361, 4216872);
    /* @4216880 constant */
    /* @4216884 cmp */
    /* @4216888 bf */
    v10 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v10)) goto L_4216912;
    /* @4216892 load */
    /* @4216900 call */
    GM_SITE(vm, 361, 4216900);
    /* @4216908 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216912: ;
    /* @4216912 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216864;
    /* @4216916 constant */
    /* @4216920 pushenv */
    if (!GM_PUSHENV(vm, VAL(100))) goto L_4216972;
    L_4216924: ;
    /* @4216924 constant */
    /* @4216928 cast */
    /* @4216932 call */
    GM_SITE(vm, 361, 4216932);
    /* @4216940 constant */
    /* @4216944 cmp */
    /* @4216948 bf */
    v11 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) >= VAL(480));
    if (!TRUTH(v11)) goto L_4216972;
    /* @4216952 load */
    /* @4216960 call */
    GM_SITE(vm, 361, 4216960);
    /* @4216968 popz */
    (void)(GM_CALL(vm, "instance_deactivate_object", 1, GM_READ(vm, -1, "id")));
    L_4216972: ;
    /* @4216972 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4216924;
    /* @4216976 constant */
    /* @4216980 constant */
    /* @4216984 constant */
    /* @4216988 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(15));
    L_4216996: ;
    return;
}
