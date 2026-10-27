/* generated from CODE 435 (gml_Object_obj_strengthupgrade2_Mouse_0), source start 4615008, end 4615172. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0435(GmVM* vm) {
    Val p4615052_0;
    /* @4615008 load */
    /* @4615016 constant */
    /* @4615020 cmp */
    /* @4615024 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(20000)))) goto L_4615048;
    /* @4615028 load */
    /* @4615036 constant */
    /* @4615040 cmp */
    /* @4615044 b */
    p4615052_0 = NUMBOOL(GM_READ(vm, -5, "strengthupgrade2bought") == VAL(0));
    goto L_4615052;
    L_4615048: ;
    /* @4615048 constant */
    p4615052_0 = VAL(0);
    L_4615052: ;
    /* @4615052 bf */
    if (!TRUTH(p4615052_0)) goto L_4615172;
    /* @4615056 load */
    /* @4615064 constant */
    /* @4615068 sub */
    /* @4615072 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(20000)));
    /* @4615080 constant */
    /* @4615084 store */
    GM_WRITE(vm, -5, "strengthupgrade2bought", VAL(1));
    /* @4615092 load */
    /* @4615100 constant */
    /* @4615104 cmp */
    /* @4615108 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4615116;
    /* @4615112 b */
    goto L_4615172;
    L_4615116: ;
    /* @4615116 load */
    /* @4615124 constant */
    /* @4615128 cmp */
    /* @4615132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4615172;
    /* @4615136 constant */
    /* @4615140 cast */
    /* @4615144 constant */
    /* @4615148 cast */
    /* @4615152 constant */
    /* @4615156 cast */
    /* @4615160 call */
    GM_SITE(vm, 435, 4615160);
    /* @4615168 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4615172: ;
    return;
}
