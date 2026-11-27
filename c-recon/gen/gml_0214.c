/* generated from CODE 214 (gml_Object_obj_boss5_Draw_0), source start 4028628, end 4028820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0214(GmVM* vm) {
    /* @4028628 load */
    /* @4028636 constant */
    /* @4028640 cmp */
    /* @4028644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4028756;
    /* @4028648 constant */
    /* @4028652 cast */
    /* @4028656 constant */
    /* @4028660 cast */
    /* @4028664 constant */
    /* @4028672 cast */
    /* @4028676 constant */
    /* @4028680 cast */
    /* @4028684 call */
    GM_SITE(vm, 214, 4028684);
    /* @4028692 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4028696 call */
    GM_SITE(vm, 214, 4028696);
    /* @4028704 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4028708 constant */
    /* @4028712 cast */
    /* @4028716 constant */
    /* @4028720 cast */
    /* @4028724 constant */
    /* @4028728 cast */
    /* @4028732 constant */
    /* @4028736 cast */
    /* @4028740 call */
    GM_SITE(vm, 214, 4028740);
    /* @4028748 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4028752 b */
    goto L_4028788;
    L_4028756: ;
    /* @4028756 load */
    /* @4028764 constant */
    /* @4028768 cmp */
    /* @4028772 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4028788;
    /* @4028776 call */
    GM_SITE(vm, 214, 4028776);
    /* @4028784 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4028788: ;
    /* @4028788 load */
    /* @4028796 constant */
    /* @4028800 cmp */
    /* @4028804 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4028820;
    /* @4028808 constant */
    /* @4028812 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4028820: ;
    return;
}
