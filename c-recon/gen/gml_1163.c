/* generated from CODE 1163 (gml_RoomCC_rm_mapview3_1163_Create), source start 5059868, end 5059912. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1163(GmVM* vm) {
    /* @5059868 load */
    /* @5059876 constant */
    /* @5059880 cmp */
    /* @5059884 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room56visited") == VAL(0)))) goto L_5059900;
    /* @5059888 call */
    GM_SITE(vm, 1163, 5059888);
    /* @5059896 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059900: ;
    /* @5059900 constant */
    /* @5059904 store */
    GM_WRITE(vm, -1, "goto", VAL(54));
    L_5059912: ;
    return;
}
