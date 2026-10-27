/* generated from CODE 685 (gml_Object_obj_woodblock_Destroy_0), source start 5016140, end 5016500. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0685(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @5016140 constant */
    /* @5016144 cast */
    /* @5016148 load */
    /* @5016156 constant */
    /* @5016160 sub */
    /* @5016164 load */
    /* @5016172 call */
    GM_SITE(vm, 685, 5016172);
    /* @5016180 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(8)), VAL(155)));
    /* @5016184 constant */
    /* @5016188 cast */
    /* @5016192 load */
    /* @5016200 load */
    /* @5016208 constant */
    /* @5016212 add */
    /* @5016216 call */
    GM_SITE(vm, 685, 5016216);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @5016224 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(155)));
    /* @5016228 constant */
    /* @5016232 cast */
    /* @5016236 load */
    /* @5016244 load */
    /* @5016252 constant */
    /* @5016256 sub */
    /* @5016260 call */
    GM_SITE(vm, 685, 5016260);
    /* @5016268 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), GM_READ(vm, -1, "y"), VAL(155)));
    /* @5016272 constant */
    /* @5016276 cast */
    /* @5016280 load */
    /* @5016288 constant */
    /* @5016292 add */
    /* @5016296 load */
    /* @5016304 call */
    GM_SITE(vm, 685, 5016304);
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5016312 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v2, VAL(155)));
    /* @5016316 constant */
    /* @5016320 cast */
    /* @5016324 load */
    /* @5016332 constant */
    /* @5016336 add */
    /* @5016340 load */
    /* @5016348 constant */
    /* @5016352 sub */
    /* @5016356 call */
    GM_SITE(vm, 685, 5016356);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5016364 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v3, VAL(155)));
    /* @5016368 constant */
    /* @5016372 cast */
    /* @5016376 load */
    /* @5016384 constant */
    /* @5016388 add */
    /* @5016392 load */
    /* @5016400 constant */
    /* @5016404 add */
    /* @5016408 call */
    GM_SITE(vm, 685, 5016408);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5016416 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v4, v5, VAL(155)));
    /* @5016420 load */
    /* @5016428 constant */
    /* @5016432 cmp */
    /* @5016436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5016444;
    /* @5016440 b */
    goto L_5016500;
    L_5016444: ;
    /* @5016444 load */
    /* @5016452 constant */
    /* @5016456 cmp */
    /* @5016460 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5016500;
    /* @5016464 constant */
    /* @5016468 cast */
    /* @5016472 constant */
    /* @5016476 cast */
    /* @5016480 constant */
    /* @5016484 cast */
    /* @5016488 call */
    GM_SITE(vm, 685, 5016488);
    /* @5016496 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_5016500: ;
    return;
}
