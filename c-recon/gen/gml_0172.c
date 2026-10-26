/* generated from CODE 172 (gml_Object_obj_boss3_Destroy_0), source start 3994656, end 3994836. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0172(GmVM* vm) {
    Val v1;
    Val v2;
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(24)));
    if (!TRUTH(v1)) goto L_3994704;
    if (!GM_PUSHENV(vm, VAL(24))) goto L_3994700;
    L_3994688: ;
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3994700: ;
    if (GM_POPENV_NEXT(vm)) goto L_3994688;
    L_3994704: ;
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(55)));
    if (!TRUTH(v2)) goto L_3994752;
    if (!GM_PUSHENV(vm, VAL(55))) goto L_3994748;
    L_3994736: ;
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3994748: ;
    if (GM_POPENV_NEXT(vm)) goto L_3994736;
    L_3994752: ;
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(50), VAL(0), VAL(0)));
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(190)));
    L_3994836: ;
    return;
}
