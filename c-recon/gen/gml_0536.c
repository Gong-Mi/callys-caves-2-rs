/* generated from CODE 536 (gml_Object_obj_coinadd_Draw_0), source start 4836256, end 4837512. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0536(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    /* @4836256 constant */
    /* @4836260 cast */
    /* @4836264 call */
    GM_SITE(vm, 536, 4836264);
    /* @4836272 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4836276 constant */
    /* @4836284 cast */
    /* @4836288 call */
    GM_SITE(vm, 536, 4836288);
    /* @4836296 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4836300 load */
    /* @4836308 constant */
    /* @4836312 cmp */
    /* @4836316 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4836484;
    /* @4836320 string */
    /* @4836328 load */
    /* @4836336 call */
    GM_SITE(vm, 536, 4836336);
    /* @4836344 add */
    /* @4836348 load */
    /* @4836356 constant */
    /* @4836360 sub */
    /* @4836364 load */
    /* @4836372 call */
    GM_SITE(vm, 536, 4836372);
    v1 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4836380 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v1));
    /* @4836384 constant */
    /* @4836388 cast */
    /* @4836392 constant */
    /* @4836396 cast */
    /* @4836400 constant */
    /* @4836404 cast */
    /* @4836408 constant */
    /* @4836412 cast */
    /* @4836416 constant */
    /* @4836420 cast */
    /* @4836424 load */
    /* @4836432 constant */
    /* @4836436 sub */
    /* @4836440 load */
    /* @4836448 constant */
    /* @4836452 sub */
    /* @4836456 constant */
    /* @4836460 cast */
    /* @4836464 constant */
    /* @4836468 cast */
    /* @4836472 call */
    GM_SITE(vm, 536, 4836472);
    /* @4836480 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4836484: ;
    /* @4836484 load */
    /* @4836492 constant */
    /* @4836496 cmp */
    /* @4836500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4836668;
    /* @4836504 string */
    /* @4836512 load */
    /* @4836520 call */
    GM_SITE(vm, 536, 4836520);
    /* @4836528 add */
    /* @4836532 load */
    /* @4836540 constant */
    /* @4836544 sub */
    /* @4836548 load */
    /* @4836556 call */
    GM_SITE(vm, 536, 4836556);
    v2 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4836564 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v2));
    /* @4836568 constant */
    /* @4836572 cast */
    /* @4836576 constant */
    /* @4836580 cast */
    /* @4836584 constant */
    /* @4836588 cast */
    /* @4836592 constant */
    /* @4836596 cast */
    /* @4836600 constant */
    /* @4836604 cast */
    /* @4836608 load */
    /* @4836616 constant */
    /* @4836620 sub */
    /* @4836624 load */
    /* @4836632 constant */
    /* @4836636 sub */
    /* @4836640 constant */
    /* @4836644 cast */
    /* @4836648 constant */
    /* @4836652 cast */
    /* @4836656 call */
    GM_SITE(vm, 536, 4836656);
    /* @4836664 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4836668: ;
    /* @4836668 load */
    /* @4836676 constant */
    /* @4836680 cmp */
    /* @4836684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(2)))) goto L_4836688;
    L_4836688: ;
    /* @4836688 load */
    /* @4836696 constant */
    /* @4836700 cmp */
    /* @4836704 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4836916;
    /* @4836708 constant */
    /* @4836712 cast */
    /* @4836716 call */
    GM_SITE(vm, 536, 4836716);
    /* @4836724 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(3)));
    /* @4836728 constant */
    /* @4836736 cast */
    /* @4836740 call */
    GM_SITE(vm, 536, 4836740);
    /* @4836748 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4836752 string */
    /* @4836760 load */
    /* @4836768 call */
    GM_SITE(vm, 536, 4836768);
    /* @4836776 add */
    /* @4836780 load */
    /* @4836788 constant */
    /* @4836792 sub */
    /* @4836796 load */
    /* @4836804 call */
    GM_SITE(vm, 536, 4836804);
    v3 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4836812 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v3));
    /* @4836816 constant */
    /* @4836820 cast */
    /* @4836824 constant */
    /* @4836828 cast */
    /* @4836832 constant */
    /* @4836836 cast */
    /* @4836840 constant */
    /* @4836844 cast */
    /* @4836848 constant */
    /* @4836852 cast */
    /* @4836856 load */
    /* @4836864 constant */
    /* @4836868 sub */
    /* @4836872 load */
    /* @4836880 constant */
    /* @4836884 sub */
    /* @4836888 constant */
    /* @4836892 cast */
    /* @4836896 constant */
    /* @4836900 cast */
    /* @4836904 call */
    GM_SITE(vm, 536, 4836904);
    /* @4836912 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4836916: ;
    /* @4836916 load */
    /* @4836924 constant */
    /* @4836928 cmp */
    /* @4836932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4837144;
    /* @4836936 constant */
    /* @4836940 cast */
    /* @4836944 call */
    GM_SITE(vm, 536, 4836944);
    /* @4836952 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(3)));
    /* @4836956 constant */
    /* @4836964 cast */
    /* @4836968 call */
    GM_SITE(vm, 536, 4836968);
    /* @4836976 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4836980 string */
    /* @4836988 load */
    /* @4836996 call */
    GM_SITE(vm, 536, 4836996);
    /* @4837004 add */
    /* @4837008 load */
    /* @4837016 constant */
    /* @4837020 sub */
    /* @4837024 load */
    /* @4837032 call */
    GM_SITE(vm, 536, 4837032);
    v4 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4837040 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v4));
    /* @4837044 constant */
    /* @4837048 cast */
    /* @4837052 constant */
    /* @4837056 cast */
    /* @4837060 constant */
    /* @4837064 cast */
    /* @4837068 constant */
    /* @4837072 cast */
    /* @4837076 constant */
    /* @4837080 cast */
    /* @4837084 load */
    /* @4837092 constant */
    /* @4837096 sub */
    /* @4837100 load */
    /* @4837108 constant */
    /* @4837112 sub */
    /* @4837116 constant */
    /* @4837120 cast */
    /* @4837124 constant */
    /* @4837128 cast */
    /* @4837132 call */
    GM_SITE(vm, 536, 4837132);
    /* @4837140 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4837144: ;
    /* @4837144 load */
    /* @4837152 constant */
    /* @4837156 cmp */
    /* @4837160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4837328;
    /* @4837164 string */
    /* @4837172 load */
    /* @4837180 call */
    GM_SITE(vm, 536, 4837180);
    /* @4837188 add */
    /* @4837192 load */
    /* @4837200 constant */
    /* @4837204 sub */
    /* @4837208 load */
    /* @4837216 call */
    GM_SITE(vm, 536, 4837216);
    v5 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4837224 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v5));
    /* @4837228 constant */
    /* @4837232 cast */
    /* @4837236 constant */
    /* @4837240 cast */
    /* @4837244 constant */
    /* @4837248 cast */
    /* @4837252 constant */
    /* @4837256 cast */
    /* @4837260 constant */
    /* @4837264 cast */
    /* @4837268 load */
    /* @4837276 constant */
    /* @4837280 sub */
    /* @4837284 load */
    /* @4837292 constant */
    /* @4837296 sub */
    /* @4837300 constant */
    /* @4837304 cast */
    /* @4837308 constant */
    /* @4837312 cast */
    /* @4837316 call */
    GM_SITE(vm, 536, 4837316);
    /* @4837324 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4837328: ;
    /* @4837328 load */
    /* @4837336 constant */
    /* @4837340 cmp */
    /* @4837344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4837512;
    /* @4837348 string */
    /* @4837356 load */
    /* @4837364 call */
    GM_SITE(vm, 536, 4837364);
    /* @4837372 add */
    /* @4837376 load */
    /* @4837384 constant */
    /* @4837388 sub */
    /* @4837392 load */
    /* @4837400 call */
    GM_SITE(vm, 536, 4837400);
    v6 = GM_ADD(STR_REF(1008), GM_CALL(vm, "string", 1, GM_READ(vm, -5, "coinpickup")));
    /* @4837408 popz */
    (void)(GM_CALL(vm, "draw_text", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(70)), v6));
    /* @4837412 constant */
    /* @4837416 cast */
    /* @4837420 constant */
    /* @4837424 cast */
    /* @4837428 constant */
    /* @4837432 cast */
    /* @4837436 constant */
    /* @4837440 cast */
    /* @4837444 constant */
    /* @4837448 cast */
    /* @4837452 load */
    /* @4837460 constant */
    /* @4837464 sub */
    /* @4837468 load */
    /* @4837476 constant */
    /* @4837480 sub */
    /* @4837484 constant */
    /* @4837488 cast */
    /* @4837492 constant */
    /* @4837496 cast */
    /* @4837500 call */
    GM_SITE(vm, 536, 4837500);
    /* @4837508 popz */
    (void)(GM_CALL(vm, "draw_sprite_ext", 9, VAL(88), VAL(0), (GM_READ(vm, 0, "x") - VAL(10)), (GM_READ(vm, 0, "y") - VAL(60)), VAL(1), VAL(1), VAL(0), VAL(-1), VAL(1)));
    L_4837512: ;
    return;
}
