/* generated from CODE 1164 (gml_RoomCC_rm_mapview3_1164_Create), source start 5059912, end 5059956. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1164(GmVM* vm) {
    /* @5059912 load */
    /* @5059920 constant */
    /* @5059924 cmp */
    /* @5059928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "level3visited") == VAL(0)))) goto L_5059944;
    /* @5059932 call */
    GM_SITE(vm, 1164, 5059932);
    /* @5059940 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059944: ;
    /* @5059944 constant */
    /* @5059948 store */
    GM_WRITE(vm, -1, "goto", VAL(3));
    L_5059956: ;
    return;
}
