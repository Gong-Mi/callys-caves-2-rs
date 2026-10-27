/* generated from CODE 410 (gml_Object_obj_weaponchange_Destroy_0), source start 4536696, end 4536764. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0410(GmVM* vm) {
    /* @4536696 load */
    /* @4536704 constant */
    /* @4536708 cmp */
    /* @4536712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4536720;
    /* @4536716 b */
    goto L_4536752;
    L_4536720: ;
    /* @4536720 load */
    /* @4536728 constant */
    /* @4536732 cmp */
    /* @4536736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4536752;
    /* @4536740 call */
    GM_SITE(vm, 410, 4536740);
    /* @4536748 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    L_4536752: ;
    /* @4536752 call */
    GM_SITE(vm, 410, 4536752);
    /* @4536760 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    L_4536764: ;
    return;
}
