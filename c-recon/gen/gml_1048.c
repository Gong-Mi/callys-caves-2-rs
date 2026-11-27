/* generated from CODE 1048 (gml_RoomCC_rm_map_1048_Create), source start 5054808, end 5054852. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1048(GmVM* vm) {
    /* @5054808 load */
    /* @5054816 constant */
    /* @5054820 cmp */
    /* @5054824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room98visited") == VAL(0)))) goto L_5054840;
    /* @5054828 call */
    GM_SITE(vm, 1048, 5054828);
    /* @5054836 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054840: ;
    /* @5054840 constant */
    /* @5054844 store */
    GM_WRITE(vm, -1, "goto", VAL(98));
    L_5054852: ;
    return;
}
