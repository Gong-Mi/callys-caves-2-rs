/* generated from CODE 1237 (gml_RoomCC_rm_mapview3_1237_Create), source start 5063124, end 5063168. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1237(GmVM* vm) {
    /* @5063124 load */
    /* @5063132 constant */
    /* @5063136 cmp */
    /* @5063140 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "levelchallenge1visited") == VAL(0)))) goto L_5063156;
    /* @5063144 call */
    GM_SITE(vm, 1237, 5063144);
    /* @5063152 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5063156: ;
    /* @5063156 constant */
    /* @5063160 store */
    GM_WRITE(vm, -1, "goto", VAL(105));
    L_5063168: ;
    return;
}
