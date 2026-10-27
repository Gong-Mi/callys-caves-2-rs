/* generated from CODE 607 (gml_Object_obj_lloydtutorial8_Destroy_0), source start 4920340, end 4920652. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0607(GmVM* vm) {
    Val v1;
    /* @4920340 constant */
    /* @4920344 store */
    GM_WRITE(vm, -5, "talkedtolloyd8", VAL(1));
    /* @4920352 string */
    /* @4920360 cast */
    /* @4920364 call */
    GM_SITE(vm, 607, 4920364);
    /* @4920372 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4920376 load */
    /* @4920384 string */
    /* @4920392 cast */
    /* @4920396 string */
    /* @4920404 cast */
    /* @4920408 call */
    GM_SITE(vm, 607, 4920408);
    /* @4920416 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(157), GM_READ(vm, -5, "talkedtolloyd8")));
    /* @4920420 call */
    GM_SITE(vm, 607, 4920420);
    /* @4920428 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4920432 load */
    /* @4920440 constant */
    /* @4920444 cmp */
    /* @4920448 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4920456;
    /* @4920452 b */
    goto L_4920496;
    L_4920456: ;
    /* @4920456 load */
    /* @4920464 constant */
    /* @4920468 cmp */
    /* @4920472 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4920496;
    /* @4920476 constant */
    /* @4920480 cast */
    /* @4920484 call */
    GM_SITE(vm, 607, 4920484);
    /* @4920492 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4920496: ;
    /* @4920496 call */
    GM_SITE(vm, 607, 4920496);
    /* @4920504 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4920508 call */
    GM_SITE(vm, 607, 4920508);
    /* @4920516 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4920520 constant */
    /* @4920524 cast */
    /* @4920528 call */
    GM_SITE(vm, 607, 4920528);
    /* @4920536 cast */
    /* @4920540 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4920568;
    /* @4920544 constant */
    /* @4920548 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4920564;
    L_4920552: ;
    /* @4920552 call */
    GM_SITE(vm, 607, 4920552);
    /* @4920560 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4920564: ;
    /* @4920564 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4920552;
    L_4920568: ;
    /* @4920568 constant */
    /* @4920572 cast */
    /* @4920576 load */
    /* @4920584 load */
    /* @4920592 call */
    GM_SITE(vm, 607, 4920592);
    /* @4920600 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4920604 constant */
    /* @4920608 cast */
    /* @4920612 load */
    /* @4920620 load */
    /* @4920628 call */
    GM_SITE(vm, 607, 4920628);
    /* @4920636 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4920640 constant */
    /* @4920644 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4920652: ;
    return;
}
