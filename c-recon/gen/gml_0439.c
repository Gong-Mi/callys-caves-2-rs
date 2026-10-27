/* generated from CODE 439 (gml_Object_obj_coinmultiplier2_Mouse_0), source start 4621988, end 4622164. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0439(GmVM* vm) {
    Val p4622032_0;
    /* @4621988 load */
    /* @4621996 constant */
    /* @4622000 cmp */
    /* @4622004 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(2000)))) goto L_4622028;
    /* @4622008 load */
    /* @4622016 constant */
    /* @4622020 cmp */
    /* @4622024 b */
    p4622032_0 = NUMBOOL(GM_READ(vm, -5, "coinmultiplier2bought") == VAL(0));
    goto L_4622032;
    L_4622028: ;
    /* @4622028 constant */
    p4622032_0 = VAL(0);
    L_4622032: ;
    /* @4622032 bf */
    if (!TRUTH(p4622032_0)) goto L_4622164;
    /* @4622036 load */
    /* @4622044 constant */
    /* @4622048 sub */
    /* @4622052 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(2000)));
    /* @4622060 constant */
    /* @4622064 store */
    GM_WRITE(vm, -5, "coinmultiply", VAL(2));
    /* @4622072 constant */
    /* @4622076 store */
    GM_WRITE(vm, -5, "coinmultiplier2bought", VAL(1));
    /* @4622084 load */
    /* @4622092 constant */
    /* @4622096 cmp */
    /* @4622100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4622108;
    /* @4622104 b */
    goto L_4622164;
    L_4622108: ;
    /* @4622108 load */
    /* @4622116 constant */
    /* @4622120 cmp */
    /* @4622124 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4622164;
    /* @4622128 constant */
    /* @4622132 cast */
    /* @4622136 constant */
    /* @4622140 cast */
    /* @4622144 constant */
    /* @4622148 cast */
    /* @4622152 call */
    GM_SITE(vm, 439, 4622152);
    /* @4622160 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4622164: ;
    return;
}
