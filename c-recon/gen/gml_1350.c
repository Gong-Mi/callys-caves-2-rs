/* generated from CODE 1350 (gml_RoomCC_rm_mapview0_1350_Create), source start 5068096, end 5068140. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1350(GmVM* vm) {
    /* @5068096 load */
    /* @5068104 constant */
    /* @5068108 cmp */
    /* @5068112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge2visited") == VAL(0)))) goto L_5068128;
    /* @5068116 call */
    GM_SITE(vm, 1350, 5068116);
    /* @5068124 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5068128: ;
    /* @5068128 constant */
    /* @5068132 store */
    GM_WRITE(vm, -1, "goto", VAL(106));
    L_5068140: ;
    return;
}
