/* generated from CODE 243 (gml_Object_obj_bat_Draw_0), source start 4040680, end 4040872. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0243(GmVM* vm) {
    /* @4040680 load */
    /* @4040688 constant */
    /* @4040692 cmp */
    /* @4040696 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4040808;
    /* @4040700 constant */
    /* @4040704 cast */
    /* @4040708 constant */
    /* @4040712 cast */
    /* @4040716 constant */
    /* @4040724 cast */
    /* @4040728 constant */
    /* @4040732 cast */
    /* @4040736 call */
    GM_SITE(vm, 243, 4040736);
    /* @4040744 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4040748 call */
    GM_SITE(vm, 243, 4040748);
    /* @4040756 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4040760 constant */
    /* @4040764 cast */
    /* @4040768 constant */
    /* @4040772 cast */
    /* @4040776 constant */
    /* @4040780 cast */
    /* @4040784 constant */
    /* @4040788 cast */
    /* @4040792 call */
    GM_SITE(vm, 243, 4040792);
    /* @4040800 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4040804 b */
    goto L_4040840;
    L_4040808: ;
    /* @4040808 load */
    /* @4040816 constant */
    /* @4040820 cmp */
    /* @4040824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4040840;
    /* @4040828 call */
    GM_SITE(vm, 243, 4040828);
    /* @4040836 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4040840: ;
    /* @4040840 load */
    /* @4040848 constant */
    /* @4040852 cmp */
    /* @4040856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4040872;
    /* @4040860 constant */
    /* @4040864 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4040872: ;
    return;
}
