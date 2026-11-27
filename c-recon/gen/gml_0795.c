/* generated from CODE 795 (gml_Object_obj_bosspuff_Alarm_7), source start 5042280, end 5042404. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0795(GmVM* vm) {
    /* @5042280 constant */
    /* @5042284 cast */
    /* @5042288 load */
    /* @5042296 constant */
    /* @5042300 sub */
    /* @5042304 load */
    /* @5042312 call */
    GM_SITE(vm, 795, 5042312);
    /* @5042320 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(10)), VAL(188)));
    /* @5042324 load */
    /* @5042332 constant */
    /* @5042336 cmp */
    /* @5042340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042348;
    /* @5042344 b */
    goto L_5042404;
    L_5042348: ;
    /* @5042348 load */
    /* @5042356 constant */
    /* @5042360 cmp */
    /* @5042364 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042404;
    /* @5042368 constant */
    /* @5042372 cast */
    /* @5042376 constant */
    /* @5042380 cast */
    /* @5042384 constant */
    /* @5042388 cast */
    /* @5042392 call */
    GM_SITE(vm, 795, 5042392);
    /* @5042400 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042404: ;
    return;
}
