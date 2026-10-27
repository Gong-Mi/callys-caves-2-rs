/* generated from CODE 267 (gml_Object_obj_fireslime_Draw_0), source start 4055668, end 4055860. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0267(GmVM* vm) {
    /* @4055668 load */
    /* @4055676 constant */
    /* @4055680 cmp */
    /* @4055684 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4055796;
    /* @4055688 constant */
    /* @4055692 cast */
    /* @4055696 constant */
    /* @4055700 cast */
    /* @4055704 constant */
    /* @4055712 cast */
    /* @4055716 constant */
    /* @4055720 cast */
    /* @4055724 call */
    GM_SITE(vm, 267, 4055724);
    /* @4055732 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4055736 call */
    GM_SITE(vm, 267, 4055736);
    /* @4055744 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4055748 constant */
    /* @4055752 cast */
    /* @4055756 constant */
    /* @4055760 cast */
    /* @4055764 constant */
    /* @4055768 cast */
    /* @4055772 constant */
    /* @4055776 cast */
    /* @4055780 call */
    GM_SITE(vm, 267, 4055780);
    /* @4055788 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4055792 b */
    goto L_4055828;
    L_4055796: ;
    /* @4055796 load */
    /* @4055804 constant */
    /* @4055808 cmp */
    /* @4055812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4055828;
    /* @4055816 call */
    GM_SITE(vm, 267, 4055816);
    /* @4055824 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4055828: ;
    /* @4055828 load */
    /* @4055836 constant */
    /* @4055840 cmp */
    /* @4055844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4055860;
    /* @4055848 constant */
    /* @4055852 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4055860: ;
    return;
}
