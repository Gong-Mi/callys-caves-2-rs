/* generated from CODE 800 (gml_Object_obj_bosspuff_Alarm_2), source start 5042900, end 5043024. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0800(GmVM* vm) {
    /* @5042900 constant */
    /* @5042904 cast */
    /* @5042908 load */
    /* @5042916 load */
    /* @5042924 constant */
    /* @5042928 sub */
    /* @5042932 call */
    GM_SITE(vm, 800, 5042932);
    /* @5042940 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(10)), GM_READ(vm, -1, "y"), VAL(188)));
    /* @5042944 load */
    /* @5042952 constant */
    /* @5042956 cmp */
    /* @5042960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042968;
    /* @5042964 b */
    goto L_5043024;
    L_5042968: ;
    /* @5042968 load */
    /* @5042976 constant */
    /* @5042980 cmp */
    /* @5042984 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5043024;
    /* @5042988 constant */
    /* @5042992 cast */
    /* @5042996 constant */
    /* @5043000 cast */
    /* @5043004 constant */
    /* @5043008 cast */
    /* @5043012 call */
    GM_SITE(vm, 800, 5043012);
    /* @5043020 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5043024: ;
    return;
}
