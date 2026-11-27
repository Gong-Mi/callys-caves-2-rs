/* generated from CODE 409 (gml_Object_obj_weaponchange_Create_0), source start 4536552, end 4536696. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0409(GmVM* vm) {
    /* @4536552 call */
    GM_SITE(vm, 409, 4536552);
    /* @4536560 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4536564 constant */
    /* @4536568 cast */
    /* @4536572 call */
    GM_SITE(vm, 409, 4536572);
    /* @4536580 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4536584 load */
    /* @4536592 constant */
    /* @4536596 cmp */
    /* @4536600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4536608;
    /* @4536604 b */
    goto L_4536664;
    L_4536608: ;
    /* @4536608 load */
    /* @4536616 constant */
    /* @4536620 cmp */
    /* @4536624 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4536664;
    /* @4536628 constant */
    /* @4536632 cast */
    /* @4536636 constant */
    /* @4536640 cast */
    /* @4536644 constant */
    /* @4536648 cast */
    /* @4536652 call */
    GM_SITE(vm, 409, 4536652);
    /* @4536660 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(28), VAL(0), VAL(0)));
    L_4536664: ;
    /* @4536664 constant */
    /* @4536668 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4536676 constant */
    /* @4536680 constant */
    /* @4536684 constant */
    /* @4536688 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(70));
    L_4536696: ;
    return;
}
