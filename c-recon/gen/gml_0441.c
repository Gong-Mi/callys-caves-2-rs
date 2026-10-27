/* generated from CODE 441 (gml_Object_obj_maxhpupgrade_Mouse_0), source start 4625452, end 4625656. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0441(GmVM* vm) {
    Val p4625496_0;
    Val v1;
    /* @4625452 load */
    /* @4625460 constant */
    /* @4625464 cmp */
    /* @4625468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(10000)))) goto L_4625492;
    /* @4625472 load */
    /* @4625480 constant */
    /* @4625484 cmp */
    /* @4625488 b */
    p4625496_0 = NUMBOOL(GM_READ(vm, -5, "maxhpupgradebought") == VAL(0));
    goto L_4625496;
    L_4625492: ;
    /* @4625492 constant */
    p4625496_0 = VAL(0);
    L_4625496: ;
    /* @4625496 bf */
    if (!TRUTH(p4625496_0)) goto L_4625656;
    /* @4625500 load */
    /* @4625508 constant */
    /* @4625512 sub */
    /* @4625516 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(10000)));
    /* @4625524 load */
    /* @4625532 constant */
    /* @4625536 add */
    /* @4625540 store */
    v1 = GM_ADD(GM_READ(vm, -5, "level"), VAL(1));
    GM_WRITE(vm, -5, "level", v1);
    /* @4625548 load */
    /* @4625556 store */
    GM_WRITE(vm, -5, "health1", GM_READ(vm, -5, "maxhp"));
    /* @4625564 constant */
    /* @4625568 store */
    GM_WRITE(vm, -5, "maxhpupgradebought", VAL(1));
    /* @4625576 load */
    /* @4625584 constant */
    /* @4625588 cmp */
    /* @4625592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4625600;
    /* @4625596 b */
    goto L_4625656;
    L_4625600: ;
    /* @4625600 load */
    /* @4625608 constant */
    /* @4625612 cmp */
    /* @4625616 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4625656;
    /* @4625620 constant */
    /* @4625624 cast */
    /* @4625628 constant */
    /* @4625632 cast */
    /* @4625636 constant */
    /* @4625640 cast */
    /* @4625644 call */
    GM_SITE(vm, 441, 4625644);
    /* @4625652 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4625656: ;
    return;
}
