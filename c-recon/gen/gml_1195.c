/* generated from CODE 1195 (gml_RoomCC_rm_mapview3_1195_Create), source start 5061276, end 5061320. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1195(GmVM* vm) {
    /* @5061276 load */
    /* @5061284 constant */
    /* @5061288 cmp */
    /* @5061292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level14visited") == VAL(0)))) goto L_5061308;
    /* @5061296 call */
    GM_SITE(vm, 1195, 5061296);
    /* @5061304 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061308: ;
    /* @5061308 constant */
    /* @5061312 store */
    GM_WRITE(vm, -1, "goto", VAL(19));
    L_5061320: ;
    return;
}
