/* generated from CODE 700 (gml_Object_obj_tease_Create_0), source start 5020848, end 5020972. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0700(GmVM* vm) {
    /* @5020848 constant */
    /* @5020852 cast */
    /* @5020856 call */
    GM_SITE(vm, 700, 5020856);
    /* @5020864 popz */
    (void)(GM_CALL(vm, "instance_deactivate_all", 1, VAL(1)));
    /* @5020868 call */
    GM_SITE(vm, 700, 5020868);
    /* @5020876 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @5020880 constant */
    /* @5020884 cast */
    /* @5020888 constant */
    /* @5020892 cast */
    /* @5020896 constant */
    /* @5020900 cast */
    /* @5020904 call */
    GM_SITE(vm, 700, 5020904);
    /* @5020912 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(53), VAL(0), VAL(0)));
    /* @5020916 constant */
    /* @5020920 store */
    GM_WRITE(vm, -1, "taplock", VAL(0));
    /* @5020928 constant */
    /* @5020932 store */
    GM_WRITE(vm, -1, "drawpanel1", VAL(1));
    /* @5020940 constant */
    /* @5020944 store */
    GM_WRITE(vm, -1, "drawpanel3", VAL(0));
    /* @5020952 constant */
    /* @5020956 constant */
    /* @5020960 constant */
    /* @5020964 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(600));
    L_5020972: ;
    return;
}
