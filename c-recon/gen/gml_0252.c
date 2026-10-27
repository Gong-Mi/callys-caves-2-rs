/* generated from CODE 252 (gml_Object_obj_slime_Alarm_0), source start 4046560, end 4046692. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0252(GmVM* vm) {
    Val v1;
    Val v2;
    Val p4046632_0;
    /* @4046560 constant */
    /* @4046564 cast */
    /* @4046568 load */
    /* @4046576 constant */
    /* @4046580 add */
    /* @4046584 load */
    /* @4046592 call */
    GM_SITE(vm, 252, 4046592);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4046600 cast */
    /* @4046604 bf */
    v2 = BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4046628;
    /* @4046608 load */
    /* @4046616 constant */
    /* @4046620 cmp */
    /* @4046624 b */
    p4046632_0 = NUMBOOL(GM_READ(vm, -1, "hpslimefrozen") == VAL(0));
    goto L_4046632;
    L_4046628: ;
    /* @4046628 constant */
    p4046632_0 = VAL(0);
    L_4046632: ;
    /* @4046632 bf */
    if (!TRUTH(p4046632_0)) goto L_4046672;
    /* @4046636 constant */
    /* @4046640 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-5));
    /* @4046648 constant */
    /* @4046652 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(73));
    /* @4046660 constant */
    /* @4046664 store */
    GM_WRITE(vm, -1, "jumping", VAL(1));
    L_4046672: ;
    /* @4046672 constant */
    /* @4046676 constant */
    /* @4046680 constant */
    /* @4046684 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    L_4046692: ;
    return;
}
