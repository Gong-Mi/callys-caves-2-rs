/* generated from CODE 698 (gml_Object_obj_final_Mouse_7), source start 5018372, end 5018436. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0698(GmVM* vm) {
    /* @5018372 load */
    /* @5018380 constant */
    /* @5018384 cmp */
    /* @5018388 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5018436;
    /* @5018392 call */
    GM_SITE(vm, 698, 5018392);
    /* @5018400 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @5018404 constant */
    /* @5018408 store */
    GM_WRITE(vm, -5, "warpfrommap", VAL(1));
    /* @5018416 constant */
    /* @5018420 cast */
    /* @5018424 call */
    GM_SITE(vm, 698, 5018424);
    /* @5018432 popz */
    (void)(GM_CALL(vm, "room_goto", 1, VAL(105)));
    L_5018436: ;
    return;
}
