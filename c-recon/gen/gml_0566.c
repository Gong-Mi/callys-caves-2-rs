/* generated from CODE 566 (gml_Object_obj_lloydtutorial2_Destroy_0), source start 4861900, end 4862212. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0566(GmVM* vm) {
    Val v1;
    /* @4861900 constant */
    /* @4861904 store */
    GM_WRITE(vm, -5, "talkedtolloyd2", VAL(1));
    /* @4861912 string */
    /* @4861920 cast */
    /* @4861924 call */
    GM_SITE(vm, 566, 4861924);
    /* @4861932 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4861936 load */
    /* @4861944 string */
    /* @4861952 cast */
    /* @4861956 string */
    /* @4861964 cast */
    /* @4861968 call */
    GM_SITE(vm, 566, 4861968);
    /* @4861976 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(151), GM_READ(vm, -5, "talkedtolloyd2")));
    /* @4861980 call */
    GM_SITE(vm, 566, 4861980);
    /* @4861988 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4861992 load */
    /* @4862000 constant */
    /* @4862004 cmp */
    /* @4862008 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4862016;
    /* @4862012 b */
    goto L_4862056;
    L_4862016: ;
    /* @4862016 load */
    /* @4862024 constant */
    /* @4862028 cmp */
    /* @4862032 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4862056;
    /* @4862036 constant */
    /* @4862040 cast */
    /* @4862044 call */
    GM_SITE(vm, 566, 4862044);
    /* @4862052 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4862056: ;
    /* @4862056 call */
    GM_SITE(vm, 566, 4862056);
    /* @4862064 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4862068 call */
    GM_SITE(vm, 566, 4862068);
    /* @4862076 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4862080 constant */
    /* @4862084 cast */
    /* @4862088 call */
    GM_SITE(vm, 566, 4862088);
    /* @4862096 cast */
    /* @4862100 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4862128;
    /* @4862104 constant */
    /* @4862108 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4862124;
    L_4862112: ;
    /* @4862112 call */
    GM_SITE(vm, 566, 4862112);
    /* @4862120 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4862124: ;
    /* @4862124 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4862112;
    L_4862128: ;
    /* @4862128 constant */
    /* @4862132 cast */
    /* @4862136 load */
    /* @4862144 load */
    /* @4862152 call */
    GM_SITE(vm, 566, 4862152);
    /* @4862160 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4862164 constant */
    /* @4862168 cast */
    /* @4862172 load */
    /* @4862180 load */
    /* @4862188 call */
    GM_SITE(vm, 566, 4862188);
    /* @4862196 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4862200 constant */
    /* @4862204 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4862212: ;
    return;
}
