/* generated from CODE 1192 (gml_RoomCC_rm_mapview3_1192_Create), source start 5061144, end 5061188. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1192(GmVM* vm) {
    /* @5061144 load */
    /* @5061152 constant */
    /* @5061156 cmp */
    /* @5061160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room70visited") == VAL(0)))) goto L_5061176;
    /* @5061164 call */
    GM_SITE(vm, 1192, 5061164);
    /* @5061172 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5061176: ;
    /* @5061176 constant */
    /* @5061180 store */
    GM_WRITE(vm, -1, "goto", VAL(69));
    L_5061188: ;
    return;
}
