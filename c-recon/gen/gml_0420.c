/* generated from CODE 420 (gml_Object_obj_triplejump_Create_0), source start 4590304, end 4590388. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0420(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4590304 load */
    /* @4590312 constant */
    /* @4590316 cmp */
    /* @4590320 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4590388;
    /* @4590324 constant */
    /* @4590328 constant */
    /* @4590332 load */
    /* @4590340 constant */
    /* @4590344 add */
    /* @4590348 store */
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(3)), VAL(20));
    GM_WRITE(vm, -1, "x", v1);
    /* @4590356 constant */
    /* @4590360 constant */
    /* @4590364 load */
    /* @4590372 constant */
    /* @4590376 add */
    /* @4590380 store */
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(3)), VAL(80));
    GM_WRITE(vm, -1, "y", v2);
    L_4590388: ;
    return;
}
