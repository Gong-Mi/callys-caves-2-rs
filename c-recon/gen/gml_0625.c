/* generated from CODE 625 (gml_Object_obj_lloydtutorial11_Destroy_0), source start 4945428, end 4945740. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0625(GmVM* vm) {
    Val v1;
    /* @4945428 constant */
    /* @4945432 store */
    GM_WRITE(vm, -5, "talkedtolloyd11", VAL(1));
    /* @4945440 string */
    /* @4945448 cast */
    /* @4945452 call */
    GM_SITE(vm, 625, 4945452);
    /* @4945460 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4945464 load */
    /* @4945472 string */
    /* @4945480 cast */
    /* @4945484 string */
    /* @4945492 cast */
    /* @4945496 call */
    GM_SITE(vm, 625, 4945496);
    /* @4945504 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(160), GM_READ(vm, -5, "talkedtolloyd11")));
    /* @4945508 call */
    GM_SITE(vm, 625, 4945508);
    /* @4945516 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4945520 load */
    /* @4945528 constant */
    /* @4945532 cmp */
    /* @4945536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4945544;
    /* @4945540 b */
    goto L_4945584;
    L_4945544: ;
    /* @4945544 load */
    /* @4945552 constant */
    /* @4945556 cmp */
    /* @4945560 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4945584;
    /* @4945564 constant */
    /* @4945568 cast */
    /* @4945572 call */
    GM_SITE(vm, 625, 4945572);
    /* @4945580 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4945584: ;
    /* @4945584 call */
    GM_SITE(vm, 625, 4945584);
    /* @4945592 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4945596 call */
    GM_SITE(vm, 625, 4945596);
    /* @4945604 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4945608 constant */
    /* @4945612 cast */
    /* @4945616 load */
    /* @4945624 load */
    /* @4945632 call */
    GM_SITE(vm, 625, 4945632);
    /* @4945640 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4945644 constant */
    /* @4945648 cast */
    /* @4945652 load */
    /* @4945660 load */
    /* @4945668 call */
    GM_SITE(vm, 625, 4945668);
    /* @4945676 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4945680 constant */
    /* @4945684 cast */
    /* @4945688 call */
    GM_SITE(vm, 625, 4945688);
    /* @4945696 cast */
    /* @4945700 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4945728;
    /* @4945704 constant */
    /* @4945708 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4945724;
    L_4945712: ;
    /* @4945712 call */
    GM_SITE(vm, 625, 4945712);
    /* @4945720 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4945724: ;
    /* @4945724 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4945712;
    L_4945728: ;
    /* @4945728 constant */
    /* @4945732 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4945740: ;
    return;
}
