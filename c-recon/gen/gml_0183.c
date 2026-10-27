/* generated from CODE 183 (gml_Object_obj_boss3_Alarm_1), source start 3995740, end 3995808. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0183(GmVM* vm) {
    Val v1;
    /* @3995740 constant */
    /* @3995744 cast */
    /* @3995748 load */
    /* @3995756 load */
    /* @3995764 constant */
    /* @3995768 sub */
    /* @3995772 call */
    GM_SITE(vm, 183, 3995772);
    /* @3995780 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), GM_READ(vm, -1, "y"), VAL(55));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @3995788 constant */
    /* @3995792 constant */
    /* @3995796 constant */
    /* @3995800 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(10));
    L_3995808: ;
    return;
}
