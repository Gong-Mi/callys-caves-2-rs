/* generated from CODE 404 (gml_Object_obj_foundweapon_Create_0), source start 4519820, end 4519964. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0404(GmVM* vm) {
    /* @4519820 call */
    GM_SITE(vm, 404, 4519820);
    /* @4519828 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4519832 constant */
    /* @4519836 cast */
    /* @4519840 call */
    GM_SITE(vm, 404, 4519840);
    /* @4519848 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4519852 load */
    /* @4519860 constant */
    /* @4519864 cmp */
    /* @4519868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4519876;
    /* @4519872 b */
    goto L_4519932;
    L_4519876: ;
    /* @4519876 load */
    /* @4519884 constant */
    /* @4519888 cmp */
    /* @4519892 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4519932;
    /* @4519896 constant */
    /* @4519900 cast */
    /* @4519904 constant */
    /* @4519908 cast */
    /* @4519912 constant */
    /* @4519916 cast */
    /* @4519920 call */
    GM_SITE(vm, 404, 4519920);
    /* @4519928 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(27), VAL(0), VAL(0)));
    L_4519932: ;
    /* @4519932 constant */
    /* @4519936 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4519944 constant */
    /* @4519948 constant */
    /* @4519952 constant */
    /* @4519956 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(70));
    L_4519964: ;
    return;
}
