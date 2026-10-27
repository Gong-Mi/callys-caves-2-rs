/* generated from CODE 418 (gml_Object_obj_powerupgrade3_Mouse_0), source start 4586768, end 4586952. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0418(GmVM* vm) {
    Val p4586816_0;
    /* @4586768 load */
    /* @4586776 constant */
    /* @4586784 cmp */
    /* @4586788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(35000)))) goto L_4586812;
    /* @4586792 load */
    /* @4586800 constant */
    /* @4586804 cmp */
    /* @4586808 b */
    p4586816_0 = NUMBOOL(GM_READ(vm, -5, "powerupgrade3bought") == VAL(0));
    goto L_4586816;
    L_4586812: ;
    /* @4586812 constant */
    p4586816_0 = VAL(0);
    L_4586816: ;
    /* @4586816 bf */
    if (!TRUTH(p4586816_0)) goto L_4586952;
    /* @4586820 load */
    /* @4586828 constant */
    /* @4586836 sub */
    /* @4586840 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(35000)));
    /* @4586848 constant */
    /* @4586852 store */
    GM_WRITE(vm, -5, "pwr", VAL(4));
    /* @4586860 constant */
    /* @4586864 store */
    GM_WRITE(vm, -5, "powerupgrade3bought", VAL(1));
    /* @4586872 load */
    /* @4586880 constant */
    /* @4586884 cmp */
    /* @4586888 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4586896;
    /* @4586892 b */
    goto L_4586952;
    L_4586896: ;
    /* @4586896 load */
    /* @4586904 constant */
    /* @4586908 cmp */
    /* @4586912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4586952;
    /* @4586916 constant */
    /* @4586920 cast */
    /* @4586924 constant */
    /* @4586928 cast */
    /* @4586932 constant */
    /* @4586936 cast */
    /* @4586940 call */
    GM_SITE(vm, 418, 4586940);
    /* @4586948 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4586952: ;
    return;
}
