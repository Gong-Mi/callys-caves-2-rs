/* generated from CODE 572 (gml_Object_obj_lloydtutorial3_Destroy_0), source start 4870288, end 4870600. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0572(GmVM* vm) {
    Val v1;
    /* @4870288 constant */
    /* @4870292 store */
    GM_WRITE(vm, -5, "talkedtolloyd3", VAL(1));
    /* @4870300 string */
    /* @4870308 cast */
    /* @4870312 call */
    GM_SITE(vm, 572, 4870312);
    /* @4870320 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4870324 load */
    /* @4870332 string */
    /* @4870340 cast */
    /* @4870344 string */
    /* @4870352 cast */
    /* @4870356 call */
    GM_SITE(vm, 572, 4870356);
    /* @4870364 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(152), GM_READ(vm, -5, "talkedtolloyd3")));
    /* @4870368 call */
    GM_SITE(vm, 572, 4870368);
    /* @4870376 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4870380 load */
    /* @4870388 constant */
    /* @4870392 cmp */
    /* @4870396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4870404;
    /* @4870400 b */
    goto L_4870444;
    L_4870404: ;
    /* @4870404 load */
    /* @4870412 constant */
    /* @4870416 cmp */
    /* @4870420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4870444;
    /* @4870424 constant */
    /* @4870428 cast */
    /* @4870432 call */
    GM_SITE(vm, 572, 4870432);
    /* @4870440 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4870444: ;
    /* @4870444 call */
    GM_SITE(vm, 572, 4870444);
    /* @4870452 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4870456 call */
    GM_SITE(vm, 572, 4870456);
    /* @4870464 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4870468 constant */
    /* @4870472 cast */
    /* @4870476 call */
    GM_SITE(vm, 572, 4870476);
    /* @4870484 cast */
    /* @4870488 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4870516;
    /* @4870492 constant */
    /* @4870496 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4870512;
    L_4870500: ;
    /* @4870500 call */
    GM_SITE(vm, 572, 4870500);
    /* @4870508 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4870512: ;
    /* @4870512 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4870500;
    L_4870516: ;
    /* @4870516 constant */
    /* @4870520 cast */
    /* @4870524 load */
    /* @4870532 load */
    /* @4870540 call */
    GM_SITE(vm, 572, 4870540);
    /* @4870548 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4870552 constant */
    /* @4870556 cast */
    /* @4870560 load */
    /* @4870568 load */
    /* @4870576 call */
    GM_SITE(vm, 572, 4870576);
    /* @4870584 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4870588 constant */
    /* @4870592 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4870600: ;
    return;
}
