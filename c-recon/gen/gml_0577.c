/* generated from CODE 577 (gml_Object_obj_lloydtutorial4_Destroy_0), source start 4877252, end 4877564. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0577(GmVM* vm) {
    Val v1;
    /* @4877252 constant */
    /* @4877256 store */
    GM_WRITE(vm, -5, "talkedtolloyd4", VAL(1));
    /* @4877264 string */
    /* @4877272 cast */
    /* @4877276 call */
    GM_SITE(vm, 577, 4877276);
    /* @4877284 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4877288 load */
    /* @4877296 string */
    /* @4877304 cast */
    /* @4877308 string */
    /* @4877316 cast */
    /* @4877320 call */
    GM_SITE(vm, 577, 4877320);
    /* @4877328 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(153), GM_READ(vm, -5, "talkedtolloyd4")));
    /* @4877332 call */
    GM_SITE(vm, 577, 4877332);
    /* @4877340 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4877344 load */
    /* @4877352 constant */
    /* @4877356 cmp */
    /* @4877360 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4877368;
    /* @4877364 b */
    goto L_4877408;
    L_4877368: ;
    /* @4877368 load */
    /* @4877376 constant */
    /* @4877380 cmp */
    /* @4877384 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4877408;
    /* @4877388 constant */
    /* @4877392 cast */
    /* @4877396 call */
    GM_SITE(vm, 577, 4877396);
    /* @4877404 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4877408: ;
    /* @4877408 call */
    GM_SITE(vm, 577, 4877408);
    /* @4877416 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4877420 call */
    GM_SITE(vm, 577, 4877420);
    /* @4877428 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4877432 constant */
    /* @4877436 cast */
    /* @4877440 call */
    GM_SITE(vm, 577, 4877440);
    /* @4877448 cast */
    /* @4877452 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4877480;
    /* @4877456 constant */
    /* @4877460 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4877476;
    L_4877464: ;
    /* @4877464 call */
    GM_SITE(vm, 577, 4877464);
    /* @4877472 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4877476: ;
    /* @4877476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4877464;
    L_4877480: ;
    /* @4877480 constant */
    /* @4877484 cast */
    /* @4877488 load */
    /* @4877496 load */
    /* @4877504 call */
    GM_SITE(vm, 577, 4877504);
    /* @4877512 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4877516 constant */
    /* @4877520 cast */
    /* @4877524 load */
    /* @4877532 load */
    /* @4877540 call */
    GM_SITE(vm, 577, 4877540);
    /* @4877548 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4877552 constant */
    /* @4877556 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4877564: ;
    return;
}
