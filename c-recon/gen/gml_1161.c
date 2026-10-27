/* generated from CODE 1161 (gml_RoomCC_rm_mapview3_1161_Create), source start 5059780, end 5059824. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1161(GmVM* vm) {
    /* @5059780 load */
    /* @5059788 constant */
    /* @5059792 cmp */
    /* @5059796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room55visited") == VAL(0)))) goto L_5059812;
    /* @5059800 call */
    GM_SITE(vm, 1161, 5059800);
    /* @5059808 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059812: ;
    /* @5059812 constant */
    /* @5059816 store */
    GM_WRITE(vm, -1, "goto", VAL(53));
    L_5059824: ;
    return;
}
