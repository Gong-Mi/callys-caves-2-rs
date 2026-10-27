/* generated from CODE 231 (gml_Object_obj_finalboss_Draw_0), source start 4031548, end 4031740. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0231(GmVM* vm) {
    /* @4031548 load */
    /* @4031556 constant */
    /* @4031560 cmp */
    /* @4031564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4031676;
    /* @4031568 constant */
    /* @4031572 cast */
    /* @4031576 constant */
    /* @4031580 cast */
    /* @4031584 constant */
    /* @4031592 cast */
    /* @4031596 constant */
    /* @4031600 cast */
    /* @4031604 call */
    GM_SITE(vm, 231, 4031604);
    /* @4031612 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4031616 call */
    GM_SITE(vm, 231, 4031616);
    /* @4031624 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4031628 constant */
    /* @4031632 cast */
    /* @4031636 constant */
    /* @4031640 cast */
    /* @4031644 constant */
    /* @4031648 cast */
    /* @4031652 constant */
    /* @4031656 cast */
    /* @4031660 call */
    GM_SITE(vm, 231, 4031660);
    /* @4031668 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4031672 b */
    goto L_4031708;
    L_4031676: ;
    /* @4031676 load */
    /* @4031684 constant */
    /* @4031688 cmp */
    /* @4031692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4031708;
    /* @4031696 call */
    GM_SITE(vm, 231, 4031696);
    /* @4031704 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4031708: ;
    /* @4031708 load */
    /* @4031716 constant */
    /* @4031720 cmp */
    /* @4031724 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4031740;
    /* @4031728 constant */
    /* @4031732 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4031740: ;
    return;
}
