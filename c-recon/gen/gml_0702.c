/* generated from CODE 702 (gml_Object_obj_tease_Mouse_7), source start 5020996, end 5021040. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0702(GmVM* vm) {
    /* @5020996 load */
    /* @5021004 constant */
    /* @5021008 cmp */
    /* @5021012 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_5021040;
    /* @5021016 call */
    GM_SITE(vm, 702, 5021016);
    /* @5021024 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @5021028 call */
    GM_SITE(vm, 702, 5021028);
    /* @5021036 popz */
    (void)(GM_CALL(vm, "game_restart", 0));
    L_5021040: ;
    return;
}
