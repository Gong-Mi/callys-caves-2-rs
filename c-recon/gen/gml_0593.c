/* generated from CODE 593 (gml_Object_obj_lloydtutorial6_Destroy_0), source start 4899964, end 4900276. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0593(GmVM* vm) {
    Val v1;
    /* @4899964 constant */
    /* @4899968 store */
    GM_WRITE(vm, -5, "talkedtolloyd6", VAL(1));
    /* @4899976 string */
    /* @4899984 cast */
    /* @4899988 call */
    GM_SITE(vm, 593, 4899988);
    /* @4899996 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4900000 load */
    /* @4900008 string */
    /* @4900016 cast */
    /* @4900020 string */
    /* @4900028 cast */
    /* @4900032 call */
    GM_SITE(vm, 593, 4900032);
    /* @4900040 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(155), GM_READ(vm, -5, "talkedtolloyd6")));
    /* @4900044 call */
    GM_SITE(vm, 593, 4900044);
    /* @4900052 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4900056 load */
    /* @4900064 constant */
    /* @4900068 cmp */
    /* @4900072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4900080;
    /* @4900076 b */
    goto L_4900120;
    L_4900080: ;
    /* @4900080 load */
    /* @4900088 constant */
    /* @4900092 cmp */
    /* @4900096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4900120;
    /* @4900100 constant */
    /* @4900104 cast */
    /* @4900108 call */
    GM_SITE(vm, 593, 4900108);
    /* @4900116 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4900120: ;
    /* @4900120 call */
    GM_SITE(vm, 593, 4900120);
    /* @4900128 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4900132 call */
    GM_SITE(vm, 593, 4900132);
    /* @4900140 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4900144 constant */
    /* @4900148 cast */
    /* @4900152 call */
    GM_SITE(vm, 593, 4900152);
    /* @4900160 cast */
    /* @4900164 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4900192;
    /* @4900168 constant */
    /* @4900172 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4900188;
    L_4900176: ;
    /* @4900176 call */
    GM_SITE(vm, 593, 4900176);
    /* @4900184 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4900188: ;
    /* @4900188 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4900176;
    L_4900192: ;
    /* @4900192 constant */
    /* @4900196 cast */
    /* @4900200 load */
    /* @4900208 load */
    /* @4900216 call */
    GM_SITE(vm, 593, 4900216);
    /* @4900224 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4900228 constant */
    /* @4900232 cast */
    /* @4900236 load */
    /* @4900244 load */
    /* @4900252 call */
    GM_SITE(vm, 593, 4900252);
    /* @4900260 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4900264 constant */
    /* @4900268 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4900276: ;
    return;
}
