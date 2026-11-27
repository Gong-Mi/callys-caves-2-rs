/* generated from CODE 1287 (gml_RoomCC_rm_mapview0_1287_Create), source start 5065324, end 5065368. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1287(GmVM* vm) {
    /* @5065324 load */
    /* @5065332 constant */
    /* @5065336 cmp */
    /* @5065340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room64visited") == VAL(0)))) goto L_5065356;
    /* @5065344 call */
    GM_SITE(vm, 1287, 5065344);
    /* @5065352 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5065356: ;
    /* @5065356 constant */
    /* @5065360 store */
    GM_WRITE(vm, -1, "goto", VAL(62));
    L_5065368: ;
    return;
}
