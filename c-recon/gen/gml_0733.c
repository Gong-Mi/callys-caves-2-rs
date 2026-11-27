/* generated from CODE 733 (gml_Object_obj_wolfintro_Create_0), source start 5034120, end 5034324. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0733(GmVM* vm) {
    Val v1;
    /* @5034120 load */
    /* @5034128 constant */
    /* @5034132 cmp */
    /* @5034136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5034144;
    /* @5034140 b */
    goto L_5034200;
    L_5034144: ;
    /* @5034144 load */
    /* @5034152 constant */
    /* @5034156 cmp */
    /* @5034160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5034200;
    /* @5034164 constant */
    /* @5034168 cast */
    /* @5034172 constant */
    /* @5034176 cast */
    /* @5034180 constant */
    /* @5034184 cast */
    /* @5034188 call */
    GM_SITE(vm, 733, 5034188);
    /* @5034196 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5034200: ;
    /* @5034200 constant */
    /* @5034204 constant */
    /* @5034208 constant */
    /* @5034212 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5034220 constant */
    /* @5034224 cast */
    /* @5034228 load */
    /* @5034236 constant */
    /* @5034240 sub */
    /* @5034244 load */
    /* @5034252 constant */
    /* @5034256 add */
    /* @5034260 call */
    GM_SITE(vm, 733, 5034260);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5034268 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5034272 constant */
    /* @5034276 cast */
    /* @5034280 load */
    /* @5034288 constant */
    /* @5034292 sub */
    /* @5034296 load */
    /* @5034304 constant */
    /* @5034308 sub */
    /* @5034312 call */
    GM_SITE(vm, 733, 5034312);
    /* @5034320 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5034324: ;
    return;
}
