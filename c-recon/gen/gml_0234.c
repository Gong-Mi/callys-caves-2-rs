/* generated from CODE 234 (gml_Object_obj_bat_Alarm_7), source start 4032732, end 4032824. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0234(GmVM* vm) {
    Val v1;
    Val p4032788_0;
    /* @4032732 constant */
    /* @4032736 cast */
    /* @4032740 call */
    GM_SITE(vm, 234, 4032740);
    /* @4032748 constant */
    /* @4032752 cmp */
    /* @4032756 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(150));
    if (!TRUTH(v1)) goto L_4032784;
    /* @4032760 load */
    /* @4032768 load */
    /* @4032776 cmp */
    /* @4032780 b */
    p4032788_0 = NUMBOOL(GM_READ(vm, 0, "y") > GM_READ(vm, -1, "y"));
    goto L_4032788;
    L_4032784: ;
    /* @4032784 constant */
    p4032788_0 = VAL(0);
    L_4032788: ;
    /* @4032788 bf */
    if (!TRUTH(p4032788_0)) goto L_4032804;
    /* @4032792 constant */
    /* @4032796 store */
    GM_WRITE(vm, -1, "awake", VAL(1));
    L_4032804: ;
    /* @4032804 constant */
    /* @4032808 constant */
    /* @4032812 constant */
    /* @4032816 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(30));
    L_4032824: ;
    return;
}
