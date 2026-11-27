/* generated from CODE 155 (gml_Object_obj_trex_Destroy_0), source start 3972828, end 3972956. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0155(GmVM* vm) {
    /* @3972828 call */
    GM_SITE(vm, 155, 3972828);
    /* @3972836 popz */
    (void)(GM_CALL(vm, "audio_stop_all", 0));
    /* @3972840 constant */
    /* @3972844 cast */
    /* @3972848 constant */
    /* @3972852 cast */
    /* @3972856 constant */
    /* @3972860 cast */
    /* @3972864 call */
    GM_SITE(vm, 155, 3972864);
    /* @3972872 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(50), VAL(0), VAL(0)));
    /* @3972876 constant */
    /* @3972880 cast */
    /* @3972884 constant */
    /* @3972888 cast */
    /* @3972892 constant */
    /* @3972896 cast */
    /* @3972900 call */
    GM_SITE(vm, 155, 3972900);
    /* @3972908 popz */
    (void)(GM_CALL(vm, "instance_create", 3, VAL(962), VAL(352), VAL(154)));
    /* @3972912 constant */
    /* @3972916 cast */
    /* @3972920 load */
    /* @3972928 constant */
    /* @3972932 sub */
    /* @3972936 load */
    /* @3972944 call */
    GM_SITE(vm, 155, 3972944);
    /* @3972952 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(32)), VAL(190)));
    L_3972956: ;
    return;
}
