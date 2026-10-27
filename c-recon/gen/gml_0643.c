/* generated from CODE 643 (gml_Object_obj_lloydtutorial13_Destroy_0), source start 4970720, end 4971032. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0643(GmVM* vm) {
    Val v1;
    /* @4970720 constant */
    /* @4970724 store */
    GM_WRITE(vm, -5, "talkedtolloyd13", VAL(1));
    /* @4970732 string */
    /* @4970740 cast */
    /* @4970744 call */
    GM_SITE(vm, 643, 4970744);
    /* @4970752 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4970756 load */
    /* @4970764 string */
    /* @4970772 cast */
    /* @4970776 string */
    /* @4970784 cast */
    /* @4970788 call */
    GM_SITE(vm, 643, 4970788);
    /* @4970796 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(162), GM_READ(vm, -5, "talkedtolloyd13")));
    /* @4970800 call */
    GM_SITE(vm, 643, 4970800);
    /* @4970808 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4970812 load */
    /* @4970820 constant */
    /* @4970824 cmp */
    /* @4970828 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4970836;
    /* @4970832 b */
    goto L_4970876;
    L_4970836: ;
    /* @4970836 load */
    /* @4970844 constant */
    /* @4970848 cmp */
    /* @4970852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4970876;
    /* @4970856 constant */
    /* @4970860 cast */
    /* @4970864 call */
    GM_SITE(vm, 643, 4970864);
    /* @4970872 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4970876: ;
    /* @4970876 call */
    GM_SITE(vm, 643, 4970876);
    /* @4970884 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4970888 call */
    GM_SITE(vm, 643, 4970888);
    /* @4970896 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4970900 constant */
    /* @4970904 cast */
    /* @4970908 load */
    /* @4970916 load */
    /* @4970924 call */
    GM_SITE(vm, 643, 4970924);
    /* @4970932 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4970936 constant */
    /* @4970940 cast */
    /* @4970944 load */
    /* @4970952 load */
    /* @4970960 call */
    GM_SITE(vm, 643, 4970960);
    /* @4970968 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4970972 constant */
    /* @4970976 cast */
    /* @4970980 call */
    GM_SITE(vm, 643, 4970980);
    /* @4970988 cast */
    /* @4970992 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4971020;
    /* @4970996 constant */
    /* @4971000 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4971016;
    L_4971004: ;
    /* @4971004 call */
    GM_SITE(vm, 643, 4971004);
    /* @4971012 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4971016: ;
    /* @4971016 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4971004;
    L_4971020: ;
    /* @4971020 constant */
    /* @4971024 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4971032: ;
    return;
}
