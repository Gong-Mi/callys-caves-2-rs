/* generated from CODE 663 (gml_Object_obj_lloydtutorial16_Destroy_0), source start 5002164, end 5002476. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0663(GmVM* vm) {
    Val v1;
    /* @5002164 constant */
    /* @5002168 store */
    GM_WRITE(vm, -5, "talkedtolloyd16", VAL(1));
    /* @5002176 string */
    /* @5002184 cast */
    /* @5002188 call */
    GM_SITE(vm, 663, 5002188);
    /* @5002196 popz */
    (void)(GM_CALL(vm, "ini_open", 1, STR_REF(422)));
    /* @5002200 load */
    /* @5002208 string */
    /* @5002216 cast */
    /* @5002220 string */
    /* @5002228 cast */
    /* @5002232 call */
    GM_SITE(vm, 663, 5002232);
    /* @5002240 popz */
    (void)(GM_CALL(vm, "ini_write_real", 3, STR_REF(149), STR_REF(482), GM_READ(vm, -5, "talkedtolloyd16")));
    /* @5002244 call */
    GM_SITE(vm, 663, 5002244);
    /* @5002252 popz */
    (void)(GM_CALL(vm, "ini_close", 0));
    /* @5002256 load */
    /* @5002264 constant */
    /* @5002268 cmp */
    /* @5002272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(1)))) goto L_5002280;
    /* @5002276 b */
    goto L_5002320;
    L_5002280: ;
    /* @5002280 load */
    /* @5002288 constant */
    /* @5002292 cmp */
    /* @5002296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "musicmute") == VAL(0)))) goto L_5002320;
    /* @5002300 constant */
    /* @5002304 cast */
    /* @5002308 call */
    GM_SITE(vm, 663, 5002308);
    /* @5002316 popz */
    (void)(GM_CALL(vm, "audio_stop_sound", 1, VAL(32)));
    L_5002320: ;
    /* @5002320 call */
    GM_SITE(vm, 663, 5002320);
    /* @5002328 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @5002332 call */
    GM_SITE(vm, 663, 5002332);
    /* @5002340 popz */
    (void)(GM_CALL(vm, "audio_resume_all", 0));
    /* @5002344 constant */
    /* @5002348 cast */
    /* @5002352 load */
    /* @5002360 load */
    /* @5002368 call */
    GM_SITE(vm, 663, 5002368);
    /* @5002376 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(130)));
    /* @5002380 constant */
    /* @5002384 cast */
    /* @5002388 load */
    /* @5002396 load */
    /* @5002404 call */
    GM_SITE(vm, 663, 5002404);
    /* @5002412 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(131)));
    /* @5002416 constant */
    /* @5002420 cast */
    /* @5002424 call */
    GM_SITE(vm, 663, 5002424);
    /* @5002432 cast */
    /* @5002436 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(154)));
    if (!TRUTH(v1)) goto L_5002464;
    /* @5002440 constant */
    /* @5002444 pushenv */
    if (!GM_PUSHENV(vm, VAL(154))) goto L_5002460;
    L_5002448: ;
    /* @5002448 call */
    GM_SITE(vm, 663, 5002448);
    /* @5002456 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_5002460: ;
    /* @5002460 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_5002448;
    L_5002464: ;
    /* @5002464 constant */
    /* @5002468 store */
    GM_WRITE(vm, -5, "roomstart", VAL(0));
    L_5002476: ;
    return;
}
