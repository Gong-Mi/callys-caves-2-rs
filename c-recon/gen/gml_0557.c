/* generated from CODE 557 (gml_Object_obj_lloydtutorial1_Destroy_0), source start 4847984, end 4848296. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0557(GmVM* vm) {
    Val v1;
    /* @4847984 constant */
    /* @4847988 store */
    GM_WRITE(vm, -5, "talkedtolloyd1", VAL(1));
    /* @4847996 string */
    /* @4848004 cast */
    /* @4848008 call */
    GM_SITE(vm, 557, 4848008);
    /* @4848016 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(146)));
    /* @4848020 load */
    /* @4848028 string */
    /* @4848036 cast */
    /* @4848040 string */
    /* @4848048 cast */
    /* @4848052 call */
    GM_SITE(vm, 557, 4848052);
    /* @4848060 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(148), GM_READ(vm, -5, "talkedtolloyd1")));
    /* @4848064 call */
    GM_SITE(vm, 557, 4848064);
    /* @4848072 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @4848076 load */
    /* @4848084 constant */
    /* @4848088 cmp */
    /* @4848092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_4848100;
    /* @4848096 b */
    goto L_4848140;
    L_4848100: ;
    /* @4848100 load */
    /* @4848108 constant */
    /* @4848112 cmp */
    /* @4848116 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_4848140;
    /* @4848120 constant */
    /* @4848124 cast */
    /* @4848128 call */
    GM_SITE(vm, 557, 4848128);
    /* @4848136 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_4848140: ;
    /* @4848140 call */
    GM_SITE(vm, 557, 4848140);
    /* @4848148 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4848152 call */
    GM_SITE(vm, 557, 4848152);
    /* @4848160 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @4848164 constant */
    /* @4848168 cast */
    /* @4848172 call */
    GM_SITE(vm, 557, 4848172);
    /* @4848180 cast */
    /* @4848184 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_4848212;
    /* @4848188 constant */
    /* @4848192 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_4848208;
    L_4848196: ;
    /* @4848196 call */
    GM_SITE(vm, 557, 4848196);
    /* @4848204 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4848208: ;
    /* @4848208 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4848196;
    L_4848212: ;
    /* @4848212 constant */
    /* @4848216 cast */
    /* @4848220 load */
    /* @4848228 load */
    /* @4848236 call */
    GM_SITE(vm, 557, 4848236);
    /* @4848244 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @4848248 constant */
    /* @4848252 cast */
    /* @4848256 load */
    /* @4848264 load */
    /* @4848272 call */
    GM_SITE(vm, 557, 4848272);
    /* @4848280 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @4848284 constant */
    /* @4848288 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_4848296: ;
    return;
}
