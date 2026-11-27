/* generated from CODE 299 (gml_Object_obj_rocket_Create_0), source start 4147884, end 4148000. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0299(GmVM* vm) {
    /* @4147884 constant */
    /* @4147888 store */
    GM_WRITE(vm, -1, "hitblock", VAL(0));
    /* @4147896 constant */
    /* @4147900 store */
    GM_WRITE(vm, -1, "hitwall", VAL(0));
    /* @4147908 constant */
    /* @4147912 store */
    GM_WRITE(vm, -1, "canhit", VAL(0));
    /* @4147920 constant */
    /* @4147924 store */
    GM_WRITE(vm, -1, "hitboulder", VAL(0));
    /* @4147932 load */
    /* @4147940 constant */
    /* @4147944 cmp */
    /* @4147948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4147968;
    /* @4147952 constant */
    /* @4147956 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-16));
    /* @4147964 b */
    goto L_4147980;
    L_4147968: ;
    /* @4147968 constant */
    /* @4147972 store */
    GM_WRITE(vm, -1, "hspeed", VAL(16));
    L_4147980: ;
    /* @4147980 constant */
    /* @4147984 constant */
    /* @4147988 constant */
    /* @4147992 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(10));
    L_4148000: ;
    return;
}
