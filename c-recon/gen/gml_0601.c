/* generated from CODE 601 (gml_Object_obj_lloydtutorial7_Destroy_0), source start 4911340, end 4911652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0601(GmVM* vm) {
    Val v1;
    /* @4911340 constant */
    /* @4911344 store */
    GM_WRITE(vm, -5, "talkedtolloyd7", VAL(1));
    /* @4911352 string */
    /* @4911360 cast */
    /* @4911364 call */
    GM_SITE(vm, 601, 4911364);
    /* @4911372 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4911376 load */
    /* @4911384 string */
    /* @4911392 cast */
    /* @4911396 string */
    /* @4911404 cast */
    /* @4911408 call */
    GM_SITE(vm, 601, 4911408);
    /* @4911416 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(156), GM_READ(vm, -5, "talkedtolloyd7")));
    /* @4911420 call */
    GM_SITE(vm, 601, 4911420);
    /* @4911428 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4911432 load */
    /* @4911440 constant */
    /* @4911444 cmp */
    /* @4911448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4911456;
    /* @4911452 b */
    goto L_4911496;
    L_4911456: ;
    /* @4911456 load */
    /* @4911464 constant */
    /* @4911468 cmp */
    /* @4911472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4911496;
    /* @4911476 constant */
    /* @4911480 cast */
    /* @4911484 call */
    GM_SITE(vm, 601, 4911484);
    /* @4911492 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4911496: ;
    /* @4911496 call */
    GM_SITE(vm, 601, 4911496);
    /* @4911504 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4911508 call */
    GM_SITE(vm, 601, 4911508);
    /* @4911516 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4911520 constant */
    /* @4911524 cast */
    /* @4911528 call */
    GM_SITE(vm, 601, 4911528);
    /* @4911536 cast */
    /* @4911540 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4911568;
    /* @4911544 constant */
    /* @4911548 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4911564;
    L_4911552: ;
    /* @4911552 call */
    GM_SITE(vm, 601, 4911552);
    /* @4911560 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4911564: ;
    /* @4911564 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4911552;
    L_4911568: ;
    /* @4911568 constant */
    /* @4911572 cast */
    /* @4911576 load */
    /* @4911584 load */
    /* @4911592 call */
    GM_SITE(vm, 601, 4911592);
    /* @4911600 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4911604 constant */
    /* @4911608 cast */
    /* @4911612 load */
    /* @4911620 load */
    /* @4911628 call */
    GM_SITE(vm, 601, 4911628);
    /* @4911636 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4911640 constant */
    /* @4911644 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4911652: ;
    return;
}
