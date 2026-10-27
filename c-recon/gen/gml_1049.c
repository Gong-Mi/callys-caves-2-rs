/* generated from CODE 1049 (gml_RoomCC_rm_map_1049_Create), source start 5054852, end 5054896. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1049(GmVM* vm) {
    /* @5054852 load */
    /* @5054860 constant */
    /* @5054864 cmp */
    /* @5054868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room50visited") == VAL(0)))) goto L_5054884;
    /* @5054872 call */
    GM_SITE(vm, 1049, 5054872);
    /* @5054880 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054884: ;
    /* @5054884 constant */
    /* @5054888 store */
    GM_WRITE(vm, -1, "goto", VAL(47));
    L_5054896: ;
    return;
}
