/* generated from CODE 246 (gml_Object_obj_slime_Alarm_6), source start 4041856, end 4041992. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0246(GmVM* vm) {
    Val v1;
    /* @4041856 constant */
    /* @4041860 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4041868 load */
    /* @4041876 constant */
    /* @4041888 sub */
    /* @4041892 store */
    GM_WRITE(vm, -1, "hpslime", (GM_READ(vm, -1, "hpslime") - VAL(0.25)));
    /* @4041900 constant */
    /* @4041904 cast */
    /* @4041908 load */
    /* @4041916 load */
    /* @4041924 call */
    GM_SITE(vm, 246, 4041924);
    /* @4041932 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4041940 constant */
    /* @4041952 load */
    /* @4041960 cast */
    /* @4041964 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4041972 constant */
    /* @4041976 constant */
    /* @4041980 constant */
    /* @4041984 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_4041992: ;
    return;
}
