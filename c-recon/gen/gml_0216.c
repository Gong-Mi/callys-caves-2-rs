/* generated from CODE 216 (gml_Object_obj_finalboss_Destroy_0), source start 4029272, end 4029356. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0216(GmVM* vm) {
    /* @4029272 call */
    GM_SITE(vm, 216, 4029272);
    /* @4029280 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4029284 constant */
    /* @4029288 cast */
    /* @4029292 constant */
    /* @4029296 cast */
    /* @4029300 constant */
    /* @4029304 cast */
    /* @4029308 call */
    GM_SITE(vm, 216, 4029308);
    /* @4029316 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(49), VAL(0), VAL(0)));
    /* @4029320 constant */
    /* @4029324 cast */
    /* @4029328 load */
    /* @4029336 load */
    /* @4029344 call */
    GM_SITE(vm, 216, 4029344);
    /* @4029352 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(189)));
    L_4029356: ;
    return;
}
