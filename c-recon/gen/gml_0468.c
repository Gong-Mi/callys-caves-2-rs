/* generated from CODE 468 (gml_Object_obj_volume_Mouse_4), source start 4644616, end 4644664. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0468(GmVM* vm) {
    /* @4644616 load */
    /* @4644624 constant */
    /* @4644628 cmp */
    /* @4644632 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4644652;
    /* @4644636 constant */
    /* @4644640 store */
    GM_WRITE(vm, -5, "soundmute", VAL(1));
    /* @4644648 b */
    goto L_4644664;
    L_4644652: ;
    /* @4644652 constant */
    /* @4644656 store */
    GM_WRITE(vm, -5, "soundmute", VAL(0));
    L_4644664: ;
    return;
}
