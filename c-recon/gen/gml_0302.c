/* generated from CODE 302 (gml_Object_obj_rocket_Alarm_0), source start 4148092, end 4148180. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0302(GmVM* vm) {
    /* @4148092 constant */
    /* @4148096 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4148104 constant */
    /* @4148108 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4148116 load */
    /* @4148124 constant */
    /* @4148128 cmp */
    /* @4148132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50)))) goto L_4148160;
    /* @4148136 constant */
    /* @4148140 store */
    GM_WRITE(vm, -1, "image_index", VAL(1));
    /* @4148148 constant */
    /* @4148152 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(50));
    L_4148160: ;
    /* @4148160 constant */
    /* @4148164 constant */
    /* @4148168 constant */
    /* @4148172 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(18));
    L_4148180: ;
    return;
}
