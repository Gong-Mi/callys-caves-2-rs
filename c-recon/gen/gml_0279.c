/* generated from CODE 279 (gml_Object_obj_arrow_Create_0), source start 4080592, end 4080680. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0279(GmVM* vm) {
    /* @4080592 load */
    /* @4080600 constant */
    /* @4080604 cmp */
    /* @4080608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4080636;
    /* @4080612 constant */
    /* @4080616 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-15));
    /* @4080624 constant */
    /* @4080628 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-1));
    L_4080636: ;
    /* @4080636 load */
    /* @4080644 constant */
    /* @4080648 cmp */
    /* @4080652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4080680;
    /* @4080656 constant */
    /* @4080660 store */
    GM_WRITE(vm, -1, "hspeed", VAL(15));
    /* @4080668 constant */
    /* @4080672 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-1));
    L_4080680: ;
    return;
}
