/* generated from CODE 446 (gml_Object_obj_healthrefill_Alarm_0), source start 4632416, end 4632464. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0446(GmVM* vm) {
    /* @4632416 constant */
    /* @4632420 store */
    GM_WRITE(vm, -1, "drawhealthfull", VAL(0));
    /* @4632428 constant */
    /* @4632432 cast */
    /* @4632436 constant */
    /* @4632440 cast */
    /* @4632444 constant */
    /* @4632448 cast */
    /* @4632452 call */
    GM_SITE(vm, 446, 4632452);
    /* @4632460 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(22), VAL(0), VAL(0)));
    L_4632464: ;
    return;
}
