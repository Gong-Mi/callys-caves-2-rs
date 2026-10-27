/* generated from CODE 1050 (gml_RoomCC_rm_map_1050_Create), source start 5054896, end 5054940. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1050(GmVM* vm) {
    /* @5054896 load */
    /* @5054904 constant */
    /* @5054908 cmp */
    /* @5054912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room99visited") == VAL(0)))) goto L_5054928;
    /* @5054916 call */
    GM_SITE(vm, 1050, 5054916);
    /* @5054924 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054928: ;
    /* @5054928 constant */
    /* @5054932 store */
    GM_WRITE(vm, -1, "goto", VAL(99));
    L_5054940: ;
    return;
}
