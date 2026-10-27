/* generated from CODE 235 (gml_Object_obj_bat_Alarm_6), source start 4032824, end 4032960. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0235(GmVM* vm) {
    Val v1;
    /* @4032824 constant */
    /* @4032828 store */
    GM_WRITE(vm, -1, "poisoned", VAL(1));
    /* @4032836 load */
    /* @4032844 constant */
    /* @4032856 sub */
    /* @4032860 store */
    GM_WRITE(vm, -1, "hpfour", (GM_READ(vm, -1, "hpfour") - VAL(0.25)));
    /* @4032868 constant */
    /* @4032872 cast */
    /* @4032876 load */
    /* @4032884 load */
    /* @4032892 call */
    GM_SITE(vm, 235, 4032892);
    /* @4032900 store */
    v1 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(104));
    GM_WRITE(vm, -1, "i", v1);
    /* @4032908 constant */
    /* @4032920 load */
    /* @4032928 cast */
    /* @4032932 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i")), "damage", VAL(0.25));
    /* @4032940 constant */
    /* @4032944 constant */
    /* @4032948 constant */
    /* @4032952 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(30));
    L_4032960: ;
    return;
}
