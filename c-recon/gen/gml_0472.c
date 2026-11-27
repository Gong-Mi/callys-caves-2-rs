/* generated from CODE 472 (gml_Object_obj_volumemusic_Mouse_4), source start 4649464, end 4649512. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0472(GmVM* vm) {
    /* @4649464 load */
    /* @4649472 constant */
    /* @4649476 cmp */
    /* @4649480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4649500;
    /* @4649484 constant */
    /* @4649488 store */
    GM_WRITE(vm, -5, "musicmute", VAL(1));
    /* @4649496 b */
    goto L_4649512;
    L_4649500: ;
    /* @4649500 constant */
    /* @4649504 store */
    GM_WRITE(vm, -5, "musicmute", VAL(0));
    L_4649512: ;
    return;
}
