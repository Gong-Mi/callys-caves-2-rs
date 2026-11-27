/* generated from CODE 277 (gml_Object_obj_bomb_Alarm_0), source start 4073460, end 4073640. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0277(GmVM* vm) {
    /* @4073460 load */
    /* @4073468 constant */
    /* @4073472 cmp */
    /* @4073476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "sprite_index") != VAL(50)))) goto L_4073504;
    /* @4073480 constant */
    /* @4073484 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @4073492 constant */
    /* @4073496 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(50));
    L_4073504: ;
    /* @4073504 constant */
    /* @4073508 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4073516 constant */
    /* @4073520 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4073528 constant */
    /* @4073532 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4073540 constant */
    /* @4073544 constant */
    /* @4073548 constant */
    /* @4073552 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(18));
    /* @4073560 load */
    /* @4073568 constant */
    /* @4073572 cmp */
    /* @4073576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4073584;
    /* @4073580 b */
    goto L_4073640;
    L_4073584: ;
    /* @4073584 load */
    /* @4073592 constant */
    /* @4073596 cmp */
    /* @4073600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4073640;
    /* @4073604 constant */
    /* @4073608 cast */
    /* @4073612 constant */
    /* @4073616 cast */
    /* @4073620 constant */
    /* @4073624 cast */
    /* @4073628 call */
    GM_SITE(vm, 277, 4073628);
    /* @4073636 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(23), VAL(0), VAL(0)));
    L_4073640: ;
    return;
}
