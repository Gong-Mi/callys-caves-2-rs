/* generated from CODE 1039 (gml_RoomCC_rm_map_1039_Create), source start 5054412, end 5054456. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1039(GmVM* vm) {
    /* @5054412 load */
    /* @5054420 constant */
    /* @5054424 cmp */
    /* @5054428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boss4visited") == VAL(0)))) goto L_5054444;
    /* @5054432 call */
    GM_SITE(vm, 1039, 5054432);
    /* @5054440 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5054444: ;
    /* @5054444 constant */
    /* @5054448 store */
    GM_WRITE(vm, -1, "goto", VAL(64));
    L_5054456: ;
    return;
}
