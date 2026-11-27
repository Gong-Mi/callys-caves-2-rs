/* generated from CODE 264 (gml_Object_obj_fireslime_Alarm_0), source start 4054524, end 4054656. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0264(GmVM* vm) {
    Val v1;
    Val v2;
    Val p4054596_0;
    /* @4054524 constant */
    /* @4054528 cast */
    /* @4054532 load */
    /* @4054540 constant */
    /* @4054544 add */
    /* @4054548 load */
    /* @4054556 call */
    GM_SITE(vm, 264, 4054556);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4054564 cast */
    /* @4054568 bf */
    v2 = BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4054592;
    /* @4054572 load */
    /* @4054580 constant */
    /* @4054584 cmp */
    /* @4054588 b */
    p4054596_0 = NUMBOOL(GM_READ(vm, -1, "hpfireslimefrozen") == VAL(0));
    goto L_4054596;
    L_4054592: ;
    /* @4054592 constant */
    p4054596_0 = VAL(0);
    L_4054596: ;
    /* @4054596 bf */
    if (!TRUTH(p4054596_0)) goto L_4054636;
    /* @4054600 constant */
    /* @4054604 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-5));
    /* @4054612 constant */
    /* @4054616 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(75));
    /* @4054624 constant */
    /* @4054628 store */
    GM_WRITE(vm, -1, "jumping", VAL(1));
    L_4054636: ;
    /* @4054636 constant */
    /* @4054640 constant */
    /* @4054644 constant */
    /* @4054648 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    L_4054656: ;
    return;
}
