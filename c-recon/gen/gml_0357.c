/* generated from CODE 357 (gml_Object_obj_weaponlevelup_Create_0), source start 4209596, end 4209696. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0357(GmVM* vm) {
    /* @4209596 load */
    /* @4209604 constant */
    /* @4209608 cmp */
    /* @4209612 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4209620;
    /* @4209616 b */
    goto L_4209676;
    L_4209620: ;
    /* @4209620 load */
    /* @4209628 constant */
    /* @4209632 cmp */
    /* @4209636 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4209676;
    /* @4209640 constant */
    /* @4209644 cast */
    /* @4209648 constant */
    /* @4209652 cast */
    /* @4209656 constant */
    /* @4209660 cast */
    /* @4209664 call */
    GM_SITE(vm, 357, 4209664);
    /* @4209672 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(25), VAL(0), VAL(0)));
    L_4209676: ;
    /* @4209676 constant */
    /* @4209680 constant */
    /* @4209684 constant */
    /* @4209688 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(90));
    L_4209696: ;
    return;
}
