/* generated from CODE 540 (gml_Object_obj_youhavedied_Create_0), source start 4840904, end 4841092. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0540(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4840904 constant */
    /* @4840908 cast */
    /* @4840912 constant */
    /* @4840916 cast */
    /* @4840920 call */
    GM_SITE(vm, 540, 4840920);
    /* @4840928 store */
    v1 = GM_CALL(vm, "irandom_range", 2, VAL(30), VAL(99));
    GM_WRITE(vm, -1, "coindeduct", v1);
    /* @4840936 load */
    /* @4840944 store */
    GM_WRITE(vm, 0, "x", GM_READ(vm, -5, "startx"));
    /* @4840952 load */
    /* @4840960 store */
    GM_WRITE(vm, 0, "y", GM_READ(vm, -5, "starty"));
    /* @4840968 constant */
    /* @4840972 cast */
    /* @4840976 call */
    GM_SITE(vm, 540, 4840976);
    /* @4840984 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @4840988 constant */
    /* @4840992 cast */
    /* @4840996 call */
    GM_SITE(vm, 540, 4840996);
    /* @4841004 popz */
    (void)(GM_CALL(vm, "instance_activate_object", 1, VAL(134)));
    /* @4841008 call */
    GM_SITE(vm, 540, 4841008);
    /* @4841016 popz */
    (void)(GM_CALL(vm, "audio_pause_all", 0));
    /* @4841020 constant */
    /* @4841024 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @4841032 constant */
    /* @4841036 constant */
    /* @4841040 constant */
    /* @4841044 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(70));
    /* @4841052 constant */
    /* @4841056 cast */
    /* @4841060 constant */
    /* @4841064 cast */
    /* @4841068 load */
    /* @4841076 call */
    GM_SITE(vm, 540, 4841076);
    /* @4841084 store */
    v2 = GM_CALL(vm, "string_format", 3, GM_READ(vm, -1, "coindeduct"), VAL(2), VAL(0));
    GM_WRITE(vm, -1, "str1", v2);
    L_4841092: ;
    return;
}
