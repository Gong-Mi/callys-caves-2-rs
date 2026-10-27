/* generated from CODE 18 (gml_Object_obj_player_Draw_0), source start 3861316, end 3861516. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0018(GmVM* vm) {
    GM_WRITE(vm, -1, "mask_index", VAL(29));
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3861452;
    GM_SITE(vm, 18, 3861380);
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(255), VAL(0), VAL(0)));
    GM_SITE(vm, 18, 3861392);
    (void)(GM_CALL(vm, "draw_self", 0));
    GM_SITE(vm, 18, 3861436);
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    goto L_3861484;
    L_3861452: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3861484;
    GM_SITE(vm, 18, 3861472);
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3861484: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3861516;
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3861516: ;
    return;
}
