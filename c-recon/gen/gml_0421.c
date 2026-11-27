/* generated from CODE 421 (gml_Object_obj_triplejump_Mouse_0), source start 4590388, end 4590564. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0421(GmVM* vm) {
    Val p4590432_0;
    /* @4590388 load */
    /* @4590396 constant */
    /* @4590400 cmp */
    /* @4590404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(3000)))) goto L_4590428;
    /* @4590408 load */
    /* @4590416 constant */
    /* @4590420 cmp */
    /* @4590424 b */
    p4590432_0 = NUMBOOL(GM_READ(vm, -5, "triplejumpbought") == VAL(0));
    goto L_4590432;
    L_4590428: ;
    /* @4590428 constant */
    p4590432_0 = VAL(0);
    L_4590432: ;
    /* @4590432 bf */
    if (!TRUTH(p4590432_0)) goto L_4590564;
    /* @4590436 load */
    /* @4590444 constant */
    /* @4590448 sub */
    /* @4590452 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(3000)));
    /* @4590460 constant */
    /* @4590464 store */
    GM_WRITE(vm, -5, "tjumpactive", VAL(1));
    /* @4590472 constant */
    /* @4590476 store */
    GM_WRITE(vm, -5, "triplejumpbought", VAL(1));
    /* @4590484 load */
    /* @4590492 constant */
    /* @4590496 cmp */
    /* @4590500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4590508;
    /* @4590504 b */
    goto L_4590564;
    L_4590508: ;
    /* @4590508 load */
    /* @4590516 constant */
    /* @4590520 cmp */
    /* @4590524 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4590564;
    /* @4590528 constant */
    /* @4590532 cast */
    /* @4590536 constant */
    /* @4590540 cast */
    /* @4590544 constant */
    /* @4590548 cast */
    /* @4590552 call */
    GM_SITE(vm, 421, 4590552);
    /* @4590560 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4590564: ;
    return;
}
