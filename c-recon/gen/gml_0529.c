/* generated from CODE 529 (gml_Object_obj_leftbutton_Alarm_1), source start 4821232, end 4822200. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0529(GmVM* vm) {
    Val p4821296_0;
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val p4821728_0;
    Val v7;
    Val v8;
    Val v9;
    Val v10;
    Val v11;
    Val v12;
    Val v13;
    Val p4822180_0;
    Val v14;
    /* @4821232 load */
    /* @4821240 constant */
    /* @4821244 cmp */
    /* @4821248 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "roomstart") != VAL(1)))) goto L_4822200;
    /* @4821252 load */
    /* @4821260 constant */
    /* @4821264 cmp */
    /* @4821268 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "sliding1") == VAL(0)))) goto L_4821292;
    /* @4821272 load */
    /* @4821280 constant */
    /* @4821284 cmp */
    /* @4821288 b */
    p4821296_0 = NUMBOOL(GM_READ(vm, 0, "sliding2") == VAL(0));
    goto L_4821296;
    L_4821292: ;
    /* @4821292 constant */
    p4821296_0 = VAL(0);
    L_4821296: ;
    /* @4821296 bf */
    if (!TRUTH(p4821296_0)) goto L_4822200;
    /* @4821300 load */
    /* @4821308 cast */
    /* @4821312 bf */
    if (!TRUTH(BOOL(GM_READ(vm, 0, "grounded")))) goto L_4821748;
    /* @4821316 constant */
    /* @4821320 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(30));
    /* @4821328 constant */
    /* @4821332 store */
    GM_WRITE(vm, 0, "image_xscale", VAL(-1));
    /* @4821340 constant */
    /* @4821344 store */
    GM_WRITE(vm, 0, "facing", VAL(1));
    /* @4821352 constant */
    /* @4821356 pushenv */
    if (!GM_PUSHENV(vm, VAL(0))) goto L_4821744;
    L_4821360: ;
    /* @4821360 constant */
    /* @4821364 cast */
    /* @4821368 load */
    /* @4821376 load */
    /* @4821384 constant */
    /* @4821388 sub */
    /* @4821392 call */
    GM_SITE(vm, 529, 4821392);
    /* @4821400 cast */
    /* @4821404 not */
    /* @4821408 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(6))));
    if (!TRUTH(v1)) goto L_4821724;
    /* @4821412 constant */
    /* @4821416 cast */
    /* @4821420 load */
    /* @4821428 load */
    /* @4821436 constant */
    /* @4821440 sub */
    /* @4821444 call */
    GM_SITE(vm, 529, 4821444);
    /* @4821452 cast */
    /* @4821456 not */
    /* @4821460 bf */
    v2 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(4))));
    if (!TRUTH(v2)) goto L_4821724;
    /* @4821464 constant */
    /* @4821468 cast */
    /* @4821472 load */
    /* @4821480 load */
    /* @4821488 constant */
    /* @4821492 sub */
    /* @4821496 call */
    GM_SITE(vm, 529, 4821496);
    /* @4821504 cast */
    /* @4821508 not */
    /* @4821512 bf */
    v3 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(5))));
    if (!TRUTH(v3)) goto L_4821724;
    /* @4821516 constant */
    /* @4821520 cast */
    /* @4821524 load */
    /* @4821532 load */
    /* @4821540 constant */
    /* @4821544 sub */
    /* @4821548 call */
    GM_SITE(vm, 529, 4821548);
    /* @4821556 cast */
    /* @4821560 not */
    /* @4821564 bf */
    v4 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(3))));
    if (!TRUTH(v4)) goto L_4821724;
    /* @4821568 constant */
    /* @4821572 cast */
    /* @4821576 load */
    /* @4821584 load */
    /* @4821592 constant */
    /* @4821596 sub */
    /* @4821600 call */
    GM_SITE(vm, 529, 4821600);
    /* @4821608 cast */
    /* @4821612 not */
    /* @4821616 bf */
    v5 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(156))));
    if (!TRUTH(v5)) goto L_4821724;
    /* @4821620 constant */
    /* @4821624 cast */
    /* @4821628 load */
    /* @4821636 load */
    /* @4821644 constant */
    /* @4821648 sub */
    /* @4821652 call */
    GM_SITE(vm, 529, 4821652);
    /* @4821660 cast */
    /* @4821664 not */
    /* @4821668 bf */
    v6 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(158))));
    if (!TRUTH(v6)) goto L_4821724;
    /* @4821672 constant */
    /* @4821676 cast */
    /* @4821680 load */
    /* @4821688 load */
    /* @4821696 constant */
    /* @4821700 sub */
    /* @4821704 call */
    GM_SITE(vm, 529, 4821704);
    /* @4821712 cast */
    /* @4821716 not */
    /* @4821720 b */
    v7 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(159))));
    p4821728_0 = v7;
    goto L_4821728;
    L_4821724: ;
    /* @4821724 constant */
    p4821728_0 = VAL(0);
    L_4821728: ;
    /* @4821728 bf */
    if (!TRUTH(p4821728_0)) goto L_4821744;
    /* @4821732 constant */
    /* @4821736 store */
    GM_WRITE(vm, 0, "hsp", VAL(-7));
    L_4821744: ;
    /* @4821744 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4821360;
    L_4821748: ;
    /* @4821748 load */
    /* @4821756 cast */
    /* @4821760 not */
    /* @4821764 bf */
    if (!TRUTH(NOT(BOOL(GM_READ(vm, 0, "grounded"))))) goto L_4822200;
    /* @4821768 constant */
    /* @4821772 store */
    GM_WRITE(vm, 0, "sprite_index", VAL(32));
    /* @4821780 constant */
    /* @4821784 store */
    GM_WRITE(vm, 0, "image_xscale", VAL(-1));
    /* @4821792 constant */
    /* @4821796 store */
    GM_WRITE(vm, 0, "facing", VAL(1));
    /* @4821804 constant */
    /* @4821808 pushenv */
    if (!GM_PUSHENV(vm, VAL(0))) goto L_4822196;
    L_4821812: ;
    /* @4821812 constant */
    /* @4821816 cast */
    /* @4821820 load */
    /* @4821828 load */
    /* @4821836 constant */
    /* @4821840 sub */
    /* @4821844 call */
    GM_SITE(vm, 529, 4821844);
    /* @4821852 cast */
    /* @4821856 not */
    /* @4821860 bf */
    v8 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(6))));
    if (!TRUTH(v8)) goto L_4822176;
    /* @4821864 constant */
    /* @4821868 cast */
    /* @4821872 load */
    /* @4821880 load */
    /* @4821888 constant */
    /* @4821892 sub */
    /* @4821896 call */
    GM_SITE(vm, 529, 4821896);
    /* @4821904 cast */
    /* @4821908 not */
    /* @4821912 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(4))));
    if (!TRUTH(v9)) goto L_4822176;
    /* @4821916 constant */
    /* @4821920 cast */
    /* @4821924 load */
    /* @4821932 load */
    /* @4821940 constant */
    /* @4821944 sub */
    /* @4821948 call */
    GM_SITE(vm, 529, 4821948);
    /* @4821956 cast */
    /* @4821960 not */
    /* @4821964 bf */
    v10 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(5))));
    if (!TRUTH(v10)) goto L_4822176;
    /* @4821968 constant */
    /* @4821972 cast */
    /* @4821976 load */
    /* @4821984 load */
    /* @4821992 constant */
    /* @4821996 sub */
    /* @4822000 call */
    GM_SITE(vm, 529, 4822000);
    /* @4822008 cast */
    /* @4822012 not */
    /* @4822016 bf */
    v11 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(3))));
    if (!TRUTH(v11)) goto L_4822176;
    /* @4822020 constant */
    /* @4822024 cast */
    /* @4822028 load */
    /* @4822036 load */
    /* @4822044 constant */
    /* @4822048 sub */
    /* @4822052 call */
    GM_SITE(vm, 529, 4822052);
    /* @4822060 cast */
    /* @4822064 not */
    /* @4822068 bf */
    v12 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(156))));
    if (!TRUTH(v12)) goto L_4822176;
    /* @4822072 constant */
    /* @4822076 cast */
    /* @4822080 load */
    /* @4822088 load */
    /* @4822096 constant */
    /* @4822100 sub */
    /* @4822104 call */
    GM_SITE(vm, 529, 4822104);
    /* @4822112 cast */
    /* @4822116 not */
    /* @4822120 bf */
    v13 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(158))));
    if (!TRUTH(v13)) goto L_4822176;
    /* @4822124 constant */
    /* @4822128 cast */
    /* @4822132 load */
    /* @4822140 load */
    /* @4822148 constant */
    /* @4822152 sub */
    /* @4822156 call */
    GM_SITE(vm, 529, 4822156);
    /* @4822164 cast */
    /* @4822168 not */
    /* @4822172 b */
    v14 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(1)), GM_READ(vm, -1, "y"), VAL(159))));
    p4822180_0 = v14;
    goto L_4822180;
    L_4822176: ;
    /* @4822176 constant */
    p4822180_0 = VAL(0);
    L_4822180: ;
    /* @4822180 bf */
    if (!TRUTH(p4822180_0)) goto L_4822196;
    /* @4822184 constant */
    /* @4822188 store */
    GM_WRITE(vm, 0, "hsp", VAL(-7));
    L_4822196: ;
    /* @4822196 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4821812;
    L_4822200: ;
    return;
}
