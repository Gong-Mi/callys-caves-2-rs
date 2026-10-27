/* generated from CODE 287 (gml_Object_obj_laserbeam_Create_0), source start 4113336, end 4113404. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0287(GmVM* vm) {
    /* @4113336 constant */
    /* @4113340 constant */
    /* @4113344 constant */
    /* @4113348 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(120));
    /* @4113356 load */
    /* @4113364 constant */
    /* @4113368 cmp */
    /* @4113372 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4113392;
    /* @4113376 constant */
    /* @4113380 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-20));
    /* @4113388 b */
    goto L_4113404;
    L_4113392: ;
    /* @4113392 constant */
    /* @4113396 store */
    GM_WRITE(vm, -1, "hspeed", VAL(20));
    L_4113404: ;
    return;
}
