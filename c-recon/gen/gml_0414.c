/* generated from CODE 414 (gml_Object_obj_powerupgrade_Mouse_0), source start 4579712, end 4579888. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0414(GmVM* vm) {
    Val p4579756_0;
    /* @4579712 load */
    /* @4579720 constant */
    /* @4579724 cmp */
    /* @4579728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(5000)))) goto L_4579752;
    /* @4579732 load */
    /* @4579740 constant */
    /* @4579744 cmp */
    /* @4579748 b */
    p4579756_0 = NUMBOOL(GM_READ(vm, -5, "powerupgradebought") == VAL(0));
    goto L_4579756;
    L_4579752: ;
    /* @4579752 constant */
    p4579756_0 = VAL(0);
    L_4579756: ;
    /* @4579756 bf */
    if (!TRUTH(p4579756_0)) goto L_4579888;
    /* @4579760 load */
    /* @4579768 constant */
    /* @4579772 sub */
    /* @4579776 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(5000)));
    /* @4579784 constant */
    /* @4579788 store */
    GM_WRITE(vm, -5, "pwr", VAL(2));
    /* @4579796 constant */
    /* @4579800 store */
    GM_WRITE(vm, -5, "powerupgradebought", VAL(1));
    /* @4579808 load */
    /* @4579816 constant */
    /* @4579820 cmp */
    /* @4579824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4579832;
    /* @4579828 b */
    goto L_4579888;
    L_4579832: ;
    /* @4579832 load */
    /* @4579840 constant */
    /* @4579844 cmp */
    /* @4579848 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4579888;
    /* @4579852 constant */
    /* @4579856 cast */
    /* @4579860 constant */
    /* @4579864 cast */
    /* @4579868 constant */
    /* @4579872 cast */
    /* @4579876 call */
    GM_SITE(vm, 414, 4579876);
    /* @4579884 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4579888: ;
    return;
}
