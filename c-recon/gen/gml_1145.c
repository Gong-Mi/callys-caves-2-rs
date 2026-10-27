/* generated from CODE 1145 (gml_RoomCC_rm_mapview3_1145_Create), source start 5059076, end 5059120. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_1145(GmVM* vm) {
    /* @5059076 load */
    /* @5059084 constant */
    /* @5059088 cmp */
    /* @5059092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "room48visited") == VAL(0)))) goto L_5059108;
    /* @5059096 call */
    GM_SITE(vm, 1145, 5059096);
    /* @5059104 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5059108: ;
    /* @5059108 constant */
    /* @5059112 store */
    GM_WRITE(vm, -1, "goto", VAL(45));
    L_5059120: ;
    return;
}
