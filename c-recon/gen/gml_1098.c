/* generated from CODE 1098 (gml_RoomCC_rm_map_1098_Create), source start 5057008, end 5057052. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1098(GmVM* vm) {
    /* @5057008 load */
    /* @5057016 constant */
    /* @5057020 cmp */
    /* @5057024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room73visited") == VAL(0)))) goto L_5057040;
    /* @5057028 call */
    GM_SITE(vm, 1098, 5057028);
    /* @5057036 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5057040: ;
    /* @5057040 constant */
    /* @5057044 store */
    GM_WRITE(vm, -1, "goto", VAL(72));
    L_5057052: ;
    return;
}
