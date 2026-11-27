/* generated from CODE 620 (gml_Object_obj_lloydtutorial10_Destroy_0), source start 4938444, end 4938756. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0620(GmVM* vm) {
    Val v1;
    /* @4938444 constant */
    /* @4938448 store */
    GM_WRITE(vm, -5, "talkedtolloyd10", VAL(1));
    /* @4938456 string */
    /* @4938464 cast */
    /* @4938468 call */
    GM_SITE(vm, 620, 4938468);
    /* @4938476 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4938480 load */
    /* @4938488 string */
    /* @4938496 cast */
    /* @4938500 string */
    /* @4938508 cast */
    /* @4938512 call */
    GM_SITE(vm, 620, 4938512);
    /* @4938520 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(159), GM_READ(vm, -5, "talkedtolloyd10")));
    /* @4938524 call */
    GM_SITE(vm, 620, 4938524);
    /* @4938532 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4938536 load */
    /* @4938544 constant */
    /* @4938548 cmp */
    /* @4938552 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4938560;
    /* @4938556 b */
    goto L_4938600;
    L_4938560: ;
    /* @4938560 load */
    /* @4938568 constant */
    /* @4938572 cmp */
    /* @4938576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4938600;
    /* @4938580 constant */
    /* @4938584 cast */
    /* @4938588 call */
    GM_SITE(vm, 620, 4938588);
    /* @4938596 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4938600: ;
    /* @4938600 call */
    GM_SITE(vm, 620, 4938600);
    /* @4938608 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4938612 call */
    GM_SITE(vm, 620, 4938612);
    /* @4938620 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4938624 constant */
    /* @4938628 cast */
    /* @4938632 load */
    /* @4938640 load */
    /* @4938648 call */
    GM_SITE(vm, 620, 4938648);
    /* @4938656 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4938660 constant */
    /* @4938664 cast */
    /* @4938668 load */
    /* @4938676 load */
    /* @4938684 call */
    GM_SITE(vm, 620, 4938684);
    /* @4938692 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4938696 constant */
    /* @4938700 cast */
    /* @4938704 call */
    GM_SITE(vm, 620, 4938704);
    /* @4938712 cast */
    /* @4938716 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4938744;
    /* @4938720 constant */
    /* @4938724 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4938740;
    L_4938728: ;
    /* @4938728 call */
    GM_SITE(vm, 620, 4938728);
    /* @4938736 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4938740: ;
    /* @4938740 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4938728;
    L_4938744: ;
    /* @4938744 constant */
    /* @4938748 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4938756: ;
    return;
}
