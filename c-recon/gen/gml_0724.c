/* generated from CODE 724 (gml_Object_obj_knifebanditintro_Create_0), source start 5033220, end 5033424. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0724(GmVM* vm) {
    Val v1;
    /* @5033220 load */
    /* @5033228 constant */
    /* @5033232 cmp */
    /* @5033236 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5033244;
    /* @5033240 b */
    goto L_5033300;
    L_5033244: ;
    /* @5033244 load */
    /* @5033252 constant */
    /* @5033256 cmp */
    /* @5033260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5033300;
    /* @5033264 constant */
    /* @5033268 cast */
    /* @5033272 constant */
    /* @5033276 cast */
    /* @5033280 constant */
    /* @5033284 cast */
    /* @5033288 call */
    GM_SITE(vm, 724, 5033288);
    /* @5033296 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5033300: ;
    /* @5033300 constant */
    /* @5033304 constant */
    /* @5033308 constant */
    /* @5033312 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5033320 constant */
    /* @5033324 cast */
    /* @5033328 load */
    /* @5033336 constant */
    /* @5033340 sub */
    /* @5033344 load */
    /* @5033352 constant */
    /* @5033356 add */
    /* @5033360 call */
    GM_SITE(vm, 724, 5033360);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5033368 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5033372 constant */
    /* @5033376 cast */
    /* @5033380 load */
    /* @5033388 constant */
    /* @5033392 sub */
    /* @5033396 load */
    /* @5033404 constant */
    /* @5033408 sub */
    /* @5033412 call */
    GM_SITE(vm, 724, 5033412);
    /* @5033420 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5033424: ;
    return;
}
