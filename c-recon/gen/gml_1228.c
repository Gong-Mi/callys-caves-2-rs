/* generated from CODE 1228 (gml_RoomCC_rm_mapview3_1228_Create), source start 5062728, end 5062772. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1228(GmVM* vm) {
    /* @5062728 load */
    /* @5062736 constant */
    /* @5062740 cmp */
    /* @5062744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room39visited") == VAL(0)))) goto L_5062760;
    /* @5062748 call */
    GM_SITE(vm, 1228, 5062748);
    /* @5062756 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5062760: ;
    /* @5062760 constant */
    /* @5062764 store */
    GM_WRITE(vm, -1, "goto", VAL(36));
    L_5062772: ;
    return;
}
