/* generated from CODE 651 (gml_Object_obj_lloydtutorial14_Destroy_0), source start 4982100, end 4982412. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0651(GmVM* vm) {
    Val v1;
    /* @4982100 constant */
    /* @4982104 store */
    GM_WRITE(vm, -5, "talkedtolloyd14", VAL(1));
    /* @4982112 string */
    /* @4982120 cast */
    /* @4982124 call */
    GM_SITE(vm, 651, 4982124);
    /* @4982132 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4982136 load */
    /* @4982144 string */
    /* @4982152 cast */
    /* @4982156 string */
    /* @4982164 cast */
    /* @4982168 call */
    GM_SITE(vm, 651, 4982168);
    /* @4982176 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(163), GM_READ(vm, -5, "talkedtolloyd14")));
    /* @4982180 call */
    GM_SITE(vm, 651, 4982180);
    /* @4982188 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4982192 load */
    /* @4982200 constant */
    /* @4982204 cmp */
    /* @4982208 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4982216;
    /* @4982212 b */
    goto L_4982256;
    L_4982216: ;
    /* @4982216 load */
    /* @4982224 constant */
    /* @4982228 cmp */
    /* @4982232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4982256;
    /* @4982236 constant */
    /* @4982240 cast */
    /* @4982244 call */
    GM_SITE(vm, 651, 4982244);
    /* @4982252 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4982256: ;
    /* @4982256 call */
    GM_SITE(vm, 651, 4982256);
    /* @4982264 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4982268 call */
    GM_SITE(vm, 651, 4982268);
    /* @4982276 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4982280 constant */
    /* @4982284 cast */
    /* @4982288 load */
    /* @4982296 load */
    /* @4982304 call */
    GM_SITE(vm, 651, 4982304);
    /* @4982312 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4982316 constant */
    /* @4982320 cast */
    /* @4982324 load */
    /* @4982332 load */
    /* @4982340 call */
    GM_SITE(vm, 651, 4982340);
    /* @4982348 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4982352 constant */
    /* @4982356 cast */
    /* @4982360 call */
    GM_SITE(vm, 651, 4982360);
    /* @4982368 cast */
    /* @4982372 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4982400;
    /* @4982376 constant */
    /* @4982380 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4982396;
    L_4982384: ;
    /* @4982384 call */
    GM_SITE(vm, 651, 4982384);
    /* @4982392 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4982396: ;
    /* @4982396 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4982384;
    L_4982400: ;
    /* @4982400 constant */
    /* @4982404 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4982412: ;
    return;
}
