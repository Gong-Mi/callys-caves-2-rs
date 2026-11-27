/* generated from CODE 188 (gml_Object_obj_boss4_Destroy_0), source start 4005884, end 4005968. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0188(GmVM* vm) {
    /* @4005884 call */
    GM_SITE(vm, 188, 4005884);
    /* @4005892 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @4005896 constant */
    /* @4005900 cast */
    /* @4005904 constant */
    /* @4005908 cast */
    /* @4005912 constant */
    /* @4005916 cast */
    /* @4005920 call */
    GM_SITE(vm, 188, 4005920);
    /* @4005928 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(49), VAL(0), VAL(0)));
    /* @4005932 constant */
    /* @4005936 cast */
    /* @4005940 load */
    /* @4005948 load */
    /* @4005956 call */
    GM_SITE(vm, 188, 4005956);
    /* @4005964 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_4005968: ;
    return;
}
