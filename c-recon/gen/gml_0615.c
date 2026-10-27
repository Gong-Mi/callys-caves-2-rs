/* generated from CODE 615 (gml_Object_obj_lloydtutorial9_Destroy_0), source start 4931604, end 4931852. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0615(GmVM* vm) {
    Val v1;
    /* @4931604 constant */
    /* @4931608 store */
    GM_WRITE(vm, -5, "talkedtolloyd9", VAL(1));
    /* @4931616 string */
    /* @4931624 cast */
    /* @4931628 call */
    GM_SITE(vm, 615, 4931628);
    /* @4931636 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4931640 load */
    /* @4931648 string */
    /* @4931656 cast */
    /* @4931660 string */
    /* @4931668 cast */
    /* @4931672 call */
    GM_SITE(vm, 615, 4931672);
    /* @4931680 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(158), GM_READ(vm, -5, "talkedtolloyd9")));
    /* @4931684 call */
    GM_SITE(vm, 615, 4931684);
    /* @4931692 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4931696 call */
    GM_SITE(vm, 615, 4931696);
    /* @4931704 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4931708 call */
    GM_SITE(vm, 615, 4931708);
    /* @4931716 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4931720 constant */
    /* @4931724 cast */
    /* @4931728 load */
    /* @4931736 load */
    /* @4931744 call */
    GM_SITE(vm, 615, 4931744);
    /* @4931752 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4931756 constant */
    /* @4931760 cast */
    /* @4931764 load */
    /* @4931772 load */
    /* @4931780 call */
    GM_SITE(vm, 615, 4931780);
    /* @4931788 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4931792 constant */
    /* @4931796 cast */
    /* @4931800 call */
    GM_SITE(vm, 615, 4931800);
    /* @4931808 cast */
    /* @4931812 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4931840;
    /* @4931816 constant */
    /* @4931820 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4931836;
    L_4931824: ;
    /* @4931824 call */
    GM_SITE(vm, 615, 4931824);
    /* @4931832 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4931836: ;
    /* @4931836 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4931824;
    L_4931840: ;
    /* @4931840 constant */
    /* @4931844 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4931852: ;
    return;
}
