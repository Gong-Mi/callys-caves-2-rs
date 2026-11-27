/* generated from CODE 524 (gml_Object_obj_shootbutton_Mouse_3), source start 4812628, end 4812672. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0524(GmVM* vm) {
    Val v1;
    /* @4812628 constant */
    /* @4812632 cast */
    /* @4812636 call */
    GM_SITE(vm, 524, 4812636);
    /* @4812644 cast */
    /* @4812648 bf */
    v1 = BOOL(GM_CALL(vm, "audio_is_playing", 1, VAL(9)));
    if (!TRUTH(v1)) goto L_4812672;
    /* @4812652 constant */
    /* @4812656 cast */
    /* @4812660 call */
    GM_SITE(vm, 524, 4812660);
    /* @4812668 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(9)));
    L_4812672: ;
    return;
}
