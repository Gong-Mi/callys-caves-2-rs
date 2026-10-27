/* generated from CODE 727 (gml_Object_obj_spiderintro_Create_0), source start 5033520, end 5033724. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0727(GmVM* vm) {
    Val v1;
    /* @5033520 load */
    /* @5033528 constant */
    /* @5033532 cmp */
    /* @5033536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5033544;
    /* @5033540 b */
    goto L_5033600;
    L_5033544: ;
    /* @5033544 load */
    /* @5033552 constant */
    /* @5033556 cmp */
    /* @5033560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5033600;
    /* @5033564 constant */
    /* @5033568 cast */
    /* @5033572 constant */
    /* @5033576 cast */
    /* @5033580 constant */
    /* @5033584 cast */
    /* @5033588 call */
    GM_SITE(vm, 727, 5033588);
    /* @5033596 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5033600: ;
    /* @5033600 constant */
    /* @5033604 constant */
    /* @5033608 constant */
    /* @5033612 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5033620 constant */
    /* @5033624 cast */
    /* @5033628 load */
    /* @5033636 constant */
    /* @5033640 sub */
    /* @5033644 load */
    /* @5033652 constant */
    /* @5033656 add */
    /* @5033660 call */
    GM_SITE(vm, 727, 5033660);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5033668 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5033672 constant */
    /* @5033676 cast */
    /* @5033680 load */
    /* @5033688 constant */
    /* @5033692 sub */
    /* @5033696 load */
    /* @5033704 constant */
    /* @5033708 sub */
    /* @5033712 call */
    GM_SITE(vm, 727, 5033712);
    /* @5033720 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5033724: ;
    return;
}
