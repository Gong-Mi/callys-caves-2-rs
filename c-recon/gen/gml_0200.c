/* generated from CODE 200 (gml_Object_obj_boss5_Destroy_0), source start 4017072, end 4017156. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0200(GmVM* vm) {
    /* @4017072 call */
    GM_SITE(vm, 200, 4017072);
    /* @4017080 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4017084 constant */
    /* @4017088 cast */
    /* @4017092 constant */
    /* @4017096 cast */
    /* @4017100 constant */
    /* @4017104 cast */
    /* @4017108 call */
    GM_SITE(vm, 200, 4017108);
    /* @4017116 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(50), VAL(0), VAL(0)));
    /* @4017120 constant */
    /* @4017124 cast */
    /* @4017128 load */
    /* @4017136 load */
    /* @4017144 call */
    GM_SITE(vm, 200, 4017144);
    /* @4017152 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_4017156: ;
    return;
}
