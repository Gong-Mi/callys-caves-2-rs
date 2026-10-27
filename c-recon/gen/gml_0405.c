/* generated from CODE 405 (gml_Object_obj_foundweapon_Destroy_0), source start 4519964, end 4520032. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0405(GmVM* vm) {
    /* @4519964 load */
    /* @4519972 constant */
    /* @4519976 cmp */
    /* @4519980 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4519988;
    /* @4519984 b */
    goto L_4520020;
    L_4519988: ;
    /* @4519988 load */
    /* @4519996 constant */
    /* @4520000 cmp */
    /* @4520004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4520020;
    /* @4520008 call */
    GM_SITE(vm, 405, 4520008);
    /* @4520016 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    L_4520020: ;
    /* @4520020 call */
    GM_SITE(vm, 405, 4520020);
    /* @4520028 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    L_4520032: ;
    return;
}
