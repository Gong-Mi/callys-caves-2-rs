/* generated from CODE 757 (gml_Object_obj_skeletonintro_Create_0), source start 5036520, end 5036724. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0757(GmVM* vm) {
    Val v1;
    /* @5036520 load */
    /* @5036528 constant */
    /* @5036532 cmp */
    /* @5036536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5036544;
    /* @5036540 b */
    goto L_5036600;
    L_5036544: ;
    /* @5036544 load */
    /* @5036552 constant */
    /* @5036556 cmp */
    /* @5036560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5036600;
    /* @5036564 constant */
    /* @5036568 cast */
    /* @5036572 constant */
    /* @5036576 cast */
    /* @5036580 constant */
    /* @5036584 cast */
    /* @5036588 call */
    GM_SITE(vm, 757, 5036588);
    /* @5036596 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5036600: ;
    /* @5036600 constant */
    /* @5036604 constant */
    /* @5036608 constant */
    /* @5036612 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5036620 constant */
    /* @5036624 cast */
    /* @5036628 load */
    /* @5036636 constant */
    /* @5036640 sub */
    /* @5036644 load */
    /* @5036652 constant */
    /* @5036656 add */
    /* @5036660 call */
    GM_SITE(vm, 757, 5036660);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5036668 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5036672 constant */
    /* @5036676 cast */
    /* @5036680 load */
    /* @5036688 constant */
    /* @5036692 sub */
    /* @5036696 load */
    /* @5036704 constant */
    /* @5036708 sub */
    /* @5036712 call */
    GM_SITE(vm, 757, 5036712);
    /* @5036720 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5036724: ;
    return;
}
