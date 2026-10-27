/* generated from CODE 634 (gml_Object_obj_lloydtutorial12_Destroy_0), source start 4957820, end 4958132. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0634(GmVM* vm) {
    Val v1;
    /* @4957820 constant */
    /* @4957824 store */
    GM_WRITE(vm, -5, "talkedtolloyd12", VAL(1));
    /* @4957832 string */
    /* @4957840 cast */
    /* @4957844 call */
    GM_SITE(vm, 634, 4957844);
    /* @4957852 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4957856 load */
    /* @4957864 string */
    /* @4957872 cast */
    /* @4957876 string */
    /* @4957884 cast */
    /* @4957888 call */
    GM_SITE(vm, 634, 4957888);
    /* @4957896 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(161), GM_READ(vm, -5, "talkedtolloyd12")));
    /* @4957900 call */
    GM_SITE(vm, 634, 4957900);
    /* @4957908 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4957912 load */
    /* @4957920 constant */
    /* @4957924 cmp */
    /* @4957928 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4957936;
    /* @4957932 b */
    goto L_4957976;
    L_4957936: ;
    /* @4957936 load */
    /* @4957944 constant */
    /* @4957948 cmp */
    /* @4957952 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4957976;
    /* @4957956 constant */
    /* @4957960 cast */
    /* @4957964 call */
    GM_SITE(vm, 634, 4957964);
    /* @4957972 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4957976: ;
    /* @4957976 call */
    GM_SITE(vm, 634, 4957976);
    /* @4957984 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4957988 call */
    GM_SITE(vm, 634, 4957988);
    /* @4957996 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4958000 constant */
    /* @4958004 cast */
    /* @4958008 load */
    /* @4958016 load */
    /* @4958024 call */
    GM_SITE(vm, 634, 4958024);
    /* @4958032 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4958036 constant */
    /* @4958040 cast */
    /* @4958044 load */
    /* @4958052 load */
    /* @4958060 call */
    GM_SITE(vm, 634, 4958060);
    /* @4958068 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4958072 constant */
    /* @4958076 cast */
    /* @4958080 call */
    GM_SITE(vm, 634, 4958080);
    /* @4958088 cast */
    /* @4958092 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4958120;
    /* @4958096 constant */
    /* @4958100 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4958116;
    L_4958104: ;
    /* @4958104 call */
    GM_SITE(vm, 634, 4958104);
    /* @4958112 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4958116: ;
    /* @4958116 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4958104;
    L_4958120: ;
    /* @4958120 constant */
    /* @4958124 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4958132: ;
    return;
}
