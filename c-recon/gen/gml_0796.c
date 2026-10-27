/* generated from CODE 796 (gml_Object_obj_bosspuff_Alarm_6), source start 5042404, end 5042528. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0796(GmVM* vm) {
    /* @5042404 constant */
    /* @5042408 cast */
    /* @5042412 load */
    /* @5042420 load */
    /* @5042428 constant */
    /* @5042432 sub */
    /* @5042436 call */
    GM_SITE(vm, 796, 5042436);
    /* @5042444 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(20)), GM_READ(vm, -1, "y"), VAL(188)));
    /* @5042448 load */
    /* @5042456 constant */
    /* @5042460 cmp */
    /* @5042464 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042472;
    /* @5042468 b */
    goto L_5042528;
    L_5042472: ;
    /* @5042472 load */
    /* @5042480 constant */
    /* @5042484 cmp */
    /* @5042488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042528;
    /* @5042492 constant */
    /* @5042496 cast */
    /* @5042500 constant */
    /* @5042504 cast */
    /* @5042508 constant */
    /* @5042512 cast */
    /* @5042516 call */
    GM_SITE(vm, 796, 5042516);
    /* @5042524 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042528: ;
    return;
}
