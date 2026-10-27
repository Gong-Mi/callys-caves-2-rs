/* generated from CODE 655 (gml_Object_obj_lloydtutorial15_Destroy_0), source start 4987580, end 4987892. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0655(GmVM* vm) {
    Val v1;
    /* @4987580 constant */
    /* @4987584 store */
    GM_WRITE(vm, -5, "talkedtolloyd15", VAL(1));
    /* @4987592 string */
    /* @4987600 cast */
    /* @4987604 call */
    GM_SITE(vm, 655, 4987604);
    /* @4987612 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4987616 load */
    /* @4987624 string */
    /* @4987632 cast */
    /* @4987636 string */
    /* @4987644 cast */
    /* @4987648 call */
    GM_SITE(vm, 655, 4987648);
    /* @4987656 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(164), GM_READ(vm, -5, "talkedtolloyd15")));
    /* @4987660 call */
    GM_SITE(vm, 655, 4987660);
    /* @4987668 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4987672 load */
    /* @4987680 constant */
    /* @4987684 cmp */
    /* @4987688 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4987696;
    /* @4987692 b */
    goto L_4987736;
    L_4987696: ;
    /* @4987696 load */
    /* @4987704 constant */
    /* @4987708 cmp */
    /* @4987712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4987736;
    /* @4987716 constant */
    /* @4987720 cast */
    /* @4987724 call */
    GM_SITE(vm, 655, 4987724);
    /* @4987732 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4987736: ;
    /* @4987736 call */
    GM_SITE(vm, 655, 4987736);
    /* @4987744 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4987748 call */
    GM_SITE(vm, 655, 4987748);
    /* @4987756 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4987760 constant */
    /* @4987764 cast */
    /* @4987768 load */
    /* @4987776 load */
    /* @4987784 call */
    GM_SITE(vm, 655, 4987784);
    /* @4987792 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4987796 constant */
    /* @4987800 cast */
    /* @4987804 load */
    /* @4987812 load */
    /* @4987820 call */
    GM_SITE(vm, 655, 4987820);
    /* @4987828 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4987832 constant */
    /* @4987836 cast */
    /* @4987840 call */
    GM_SITE(vm, 655, 4987840);
    /* @4987848 cast */
    /* @4987852 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4987880;
    /* @4987856 constant */
    /* @4987860 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4987876;
    L_4987864: ;
    /* @4987864 call */
    GM_SITE(vm, 655, 4987864);
    /* @4987872 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4987876: ;
    /* @4987876 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4987864;
    L_4987880: ;
    /* @4987880 constant */
    /* @4987884 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4987892: ;
    return;
}
