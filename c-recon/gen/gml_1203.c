/* generated from CODE 1203 (gml_RoomCC_rm_mapview3_1203_Create), source start 5061628, end 5061672. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1203(GmVM* vm) {
    /* @5061628 load */
    /* @5061636 constant */
    /* @5061640 cmp */
    /* @5061644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level16visited") == VAL(0)))) goto L_5061660;
    /* @5061648 call */
    GM_SITE(vm, 1203, 5061648);
    /* @5061656 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061660: ;
    /* @5061660 constant */
    /* @5061664 store */
    GM_WRITE(vm, -1, "goto", VAL(23));
    L_5061672: ;
    return;
}
