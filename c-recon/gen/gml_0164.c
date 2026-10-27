/* generated from CODE 164 (gml_Object_obj_boss2_Destroy_0), source start 3983680, end 3983908. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0164(GmVM* vm) {
    Val v1;
    Val v2;
    GM_SITE(vm, 164, 3983680);
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    GM_SITE(vm, 164, 3983700);
    v1 = BOOL(GM_CALL(vm, "object_exists", 1, VAL(32)));
    if (!TRUTH(v1)) goto L_3983740;
    if (!GM_PUSHENV(vm, VAL(32))) goto L_3983736;
    L_3983724: ;
    GM_SITE(vm, 164, 3983724);
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3983736: ;
    if (GM_POPENV_NEXT(vm)) goto L_3983724;
    L_3983740: ;
    GM_SITE(vm, 164, 3983748);
    v2 = BOOL(GM_CALL(vm, "object_exists", 1, VAL(33)));
    if (!TRUTH(v2)) goto L_3983788;
    if (!GM_PUSHENV(vm, VAL(33))) goto L_3983784;
    L_3983772: ;
    GM_SITE(vm, 164, 3983772);
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3983784: ;
    if (GM_POPENV_NEXT(vm)) goto L_3983772;
    L_3983788: ;
    GM_SITE(vm, 164, 3983812);
    (void)(GM_CALL(vm, "instance_create", 3, VAL(1024), VAL(256), VAL(154)));
    GM_SITE(vm, 164, 3983824);
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    GM_SITE(vm, 164, 3983860);
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(49), VAL(0), VAL(0)));
    GM_SITE(vm, 164, 3983896);
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_3983908: ;
    return;
}
