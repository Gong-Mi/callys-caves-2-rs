/* generated from CODE 364 (gml_Object_obj_bg_Draw_0), source start 4217056, end 4218520. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0364(GmVM* vm) {
    /* @4217056 load */
    /* @4217064 constant */
    /* @4217068 cmp */
    /* @4217072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4217088;
    /* @4217076 constant */
    /* @4217080 store */
    GM_WRITE(vm, -1, "drawview0", VAL(1));
    L_4217088: ;
    /* @4217088 load */
    /* @4217096 constant */
    /* @4217100 cmp */
    /* @4217104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4217120;
    /* @4217108 constant */
    /* @4217112 store */
    GM_WRITE(vm, -1, "drawview1", VAL(1));
    L_4217120: ;
    /* @4217120 load */
    /* @4217128 constant */
    /* @4217132 cmp */
    /* @4217136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4217152;
    /* @4217140 constant */
    /* @4217144 store */
    GM_WRITE(vm, -1, "drawview3", VAL(1));
    L_4217152: ;
    /* @4217152 load */
    /* @4217160 constant */
    /* @4217164 cmp */
    /* @4217168 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4217184;
    /* @4217172 constant */
    /* @4217176 store */
    GM_WRITE(vm, -1, "drawview4", VAL(1));
    L_4217184: ;
    /* @4217184 load */
    /* @4217192 constant */
    /* @4217196 cmp */
    /* @4217200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4217216;
    /* @4217204 constant */
    /* @4217208 store */
    GM_WRITE(vm, -1, "drawview5", VAL(1));
    L_4217216: ;
    /* @4217216 load */
    /* @4217224 constant */
    /* @4217228 cmp */
    /* @4217232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4217248;
    /* @4217236 constant */
    /* @4217240 store */
    GM_WRITE(vm, -1, "drawview6", VAL(1));
    L_4217248: ;
    /* @4217248 load */
    /* @4217256 constant */
    /* @4217260 cmp */
    /* @4217264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4217520;
    /* @4217268 load */
    /* @4217276 constant */
    /* @4217280 cmp */
    /* @4217284 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4217368;
    /* @4217288 constant */
    /* @4217292 load */
    /* @4217300 cast */
    /* @4217304 load */
    /* @4217312 constant */
    /* @4217316 sub */
    /* @4217320 constant */
    /* @4217324 load */
    /* @4217332 cast */
    /* @4217336 load */
    /* @4217344 load */
    /* @4217352 call */
    GM_SITE(vm, 364, 4217352);
    /* @4217360 popz */
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    /* @4217364 b */
    goto L_4217520;
    L_4217368: ;
    /* @4217368 load */
    /* @4217376 constant */
    /* @4217380 cmp */
    /* @4217384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4217520;
    /* @4217388 constant */
    /* @4217392 cast */
    /* @4217396 constant */
    /* @4217400 cast */
    /* @4217404 constant */
    /* @4217408 cast */
    /* @4217412 constant */
    /* @4217424 cast */
    /* @4217428 constant */
    /* @4217440 cast */
    /* @4217444 constant */
    /* @4217448 load */
    /* @4217456 cast */
    /* @4217460 load */
    /* @4217468 constant */
    /* @4217472 sub */
    /* @4217476 constant */
    /* @4217480 load */
    /* @4217488 cast */
    /* @4217492 load */
    /* @4217500 load */
    /* @4217508 call */
    GM_SITE(vm, 364, 4217508);
    /* @4217516 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4217520: ;
    /* @4217520 load */
    /* @4217528 constant */
    /* @4217532 cmp */
    /* @4217536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4217616;
    /* @4217540 constant */
    /* @4217544 load */
    /* @4217552 cast */
    /* @4217556 load */
    /* @4217564 constant */
    /* @4217568 sub */
    /* @4217572 constant */
    /* @4217576 load */
    /* @4217584 cast */
    /* @4217588 load */
    /* @4217596 load */
    /* @4217604 call */
    GM_SITE(vm, 364, 4217604);
    /* @4217612 popz */
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    L_4217616: ;
    /* @4217616 load */
    /* @4217624 constant */
    /* @4217628 cmp */
    /* @4217632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4217768;
    /* @4217636 constant */
    /* @4217640 cast */
    /* @4217644 constant */
    /* @4217648 cast */
    /* @4217652 constant */
    /* @4217656 cast */
    /* @4217660 constant */
    /* @4217672 cast */
    /* @4217676 constant */
    /* @4217688 cast */
    /* @4217692 constant */
    /* @4217696 load */
    /* @4217704 cast */
    /* @4217708 load */
    /* @4217716 constant */
    /* @4217720 sub */
    /* @4217724 constant */
    /* @4217728 load */
    /* @4217736 cast */
    /* @4217740 load */
    /* @4217748 load */
    /* @4217756 call */
    GM_SITE(vm, 364, 4217756);
    /* @4217764 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.4), VAL(1.4), VAL(0), VAL(-1), VAL(1)));
    L_4217768: ;
    /* @4217768 load */
    /* @4217776 constant */
    /* @4217780 cmp */
    /* @4217784 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4217920;
    /* @4217788 constant */
    /* @4217792 cast */
    /* @4217796 constant */
    /* @4217800 cast */
    /* @4217804 constant */
    /* @4217808 cast */
    /* @4217812 constant */
    /* @4217824 cast */
    /* @4217828 constant */
    /* @4217840 cast */
    /* @4217844 constant */
    /* @4217848 load */
    /* @4217856 cast */
    /* @4217860 load */
    /* @4217868 constant */
    /* @4217872 sub */
    /* @4217876 constant */
    /* @4217880 load */
    /* @4217888 cast */
    /* @4217892 load */
    /* @4217900 load */
    /* @4217908 call */
    GM_SITE(vm, 364, 4217908);
    /* @4217916 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.4), VAL(1.4), VAL(0), VAL(-1), VAL(1)));
    L_4217920: ;
    /* @4217920 load */
    /* @4217928 constant */
    /* @4217932 cmp */
    /* @4217936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4218192;
    /* @4217940 load */
    /* @4217948 constant */
    /* @4217952 cmp */
    /* @4217956 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4218040;
    /* @4217960 constant */
    /* @4217964 load */
    /* @4217972 cast */
    /* @4217976 load */
    /* @4217984 constant */
    /* @4217988 sub */
    /* @4217992 constant */
    /* @4217996 load */
    /* @4218004 cast */
    /* @4218008 load */
    /* @4218016 load */
    /* @4218024 call */
    GM_SITE(vm, 364, 4218024);
    /* @4218032 popz */
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    /* @4218036 b */
    goto L_4218192;
    L_4218040: ;
    /* @4218040 load */
    /* @4218048 constant */
    /* @4218052 cmp */
    /* @4218056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4218192;
    /* @4218060 constant */
    /* @4218064 cast */
    /* @4218068 constant */
    /* @4218072 cast */
    /* @4218076 constant */
    /* @4218080 cast */
    /* @4218084 constant */
    /* @4218096 cast */
    /* @4218100 constant */
    /* @4218112 cast */
    /* @4218116 constant */
    /* @4218120 load */
    /* @4218128 cast */
    /* @4218132 load */
    /* @4218140 constant */
    /* @4218144 sub */
    /* @4218148 constant */
    /* @4218152 load */
    /* @4218160 cast */
    /* @4218164 load */
    /* @4218172 load */
    /* @4218180 call */
    GM_SITE(vm, 364, 4218180);
    /* @4218188 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4218192: ;
    /* @4218192 load */
    /* @4218200 constant */
    /* @4218204 cmp */
    /* @4218208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4218520;
    /* @4218212 load */
    /* @4218220 constant */
    /* @4218224 cmp */
    /* @4218228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4218368;
    /* @4218232 constant */
    /* @4218236 cast */
    /* @4218240 constant */
    /* @4218244 cast */
    /* @4218248 constant */
    /* @4218252 cast */
    /* @4218256 constant */
    /* @4218268 cast */
    /* @4218272 constant */
    /* @4218284 cast */
    /* @4218288 constant */
    /* @4218292 load */
    /* @4218300 cast */
    /* @4218304 load */
    /* @4218312 constant */
    /* @4218316 sub */
    /* @4218320 constant */
    /* @4218324 load */
    /* @4218332 cast */
    /* @4218336 load */
    /* @4218344 load */
    /* @4218352 call */
    GM_SITE(vm, 364, 4218352);
    /* @4218360 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    /* @4218364 b */
    goto L_4218520;
    L_4218368: ;
    /* @4218368 load */
    /* @4218376 constant */
    /* @4218380 cmp */
    /* @4218384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4218520;
    /* @4218388 constant */
    /* @4218392 cast */
    /* @4218396 constant */
    /* @4218400 cast */
    /* @4218404 constant */
    /* @4218408 cast */
    /* @4218412 constant */
    /* @4218424 cast */
    /* @4218428 constant */
    /* @4218440 cast */
    /* @4218444 constant */
    /* @4218448 load */
    /* @4218456 cast */
    /* @4218460 load */
    /* @4218468 constant */
    /* @4218472 sub */
    /* @4218476 constant */
    /* @4218480 load */
    /* @4218488 cast */
    /* @4218492 load */
    /* @4218500 load */
    /* @4218508 call */
    GM_SITE(vm, 364, 4218508);
    /* @4218516 popz */
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4218520: ;
    return;
}
