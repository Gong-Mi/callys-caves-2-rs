/* generated from CODE 1300 (gml_RoomCC_rm_mapview0_1300_Create), source start 5065896, end 5065940. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1300(GmVM* vm) {
    /* @5065896 load */
    /* @5065904 constant */
    /* @5065908 cmp */
    /* @5065912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room70visited") == VAL(0)))) goto L_5065928;
    /* @5065916 call */
    GM_SITE(vm, 1300, 5065916);
    /* @5065924 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065928: ;
    /* @5065928 constant */
    /* @5065932 store */
    GM_WRITE(vm, -1, "goto", VAL(69));
    L_5065940: ;
    return;
}
