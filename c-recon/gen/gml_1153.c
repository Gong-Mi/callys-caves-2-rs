/* generated from CODE 1153 (gml_RoomCC_rm_mapview3_1153_Create), source start 5059428, end 5059472. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1153(GmVM* vm) {
    /* @5059428 load */
    /* @5059436 constant */
    /* @5059440 cmp */
    /* @5059444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room51visited") == VAL(0)))) goto L_5059460;
    /* @5059448 call */
    GM_SITE(vm, 1153, 5059448);
    /* @5059456 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059460: ;
    /* @5059460 constant */
    /* @5059464 store */
    GM_WRITE(vm, -1, "goto", VAL(49));
    L_5059472: ;
    return;
}
