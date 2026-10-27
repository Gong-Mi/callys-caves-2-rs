/* generated from CODE 585 (gml_Object_obj_lloydtutorial5_Destroy_0), source start 4888600, end 4888836. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0585(GmVM* vm) {
    Val v1;
    /* @4888600 constant */
    /* @4888604 store */
    GM_WRITE(vm, -5, "talkedtolloyd5", VAL(1));
    /* @4888612 string */
    /* @4888620 cast */
    /* @4888624 call */
    GM_SITE(vm, 585, 4888624);
    /* @4888632 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4888636 load */
    /* @4888644 string */
    /* @4888652 cast */
    /* @4888656 string */
    /* @4888664 cast */
    /* @4888668 call */
    GM_SITE(vm, 585, 4888668);
    /* @4888676 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(154), GM_READ(vm, -5, "talkedtolloyd5")));
    /* @4888680 call */
    GM_SITE(vm, 585, 4888680);
    /* @4888688 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4888692 call */
    GM_SITE(vm, 585, 4888692);
    /* @4888700 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4888704 constant */
    /* @4888708 cast */
    /* @4888712 call */
    GM_SITE(vm, 585, 4888712);
    /* @4888720 cast */
    /* @4888724 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4888752;
    /* @4888728 constant */
    /* @4888732 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4888748;
    L_4888736: ;
    /* @4888736 call */
    GM_SITE(vm, 585, 4888736);
    /* @4888744 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4888748: ;
    /* @4888748 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4888736;
    L_4888752: ;
    /* @4888752 constant */
    /* @4888756 cast */
    /* @4888760 load */
    /* @4888768 load */
    /* @4888776 call */
    GM_SITE(vm, 585, 4888776);
    /* @4888784 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4888788 constant */
    /* @4888792 cast */
    /* @4888796 load */
    /* @4888804 load */
    /* @4888812 call */
    GM_SITE(vm, 585, 4888812);
    /* @4888820 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4888824 constant */
    /* @4888828 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4888836: ;
    return;
}
