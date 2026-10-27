/* generated from CODE 763 (gml_Object_obj_beeintro_Create_0), source start 5037120, end 5037324. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0763(GmVM* vm) {
    Val v1;
    /* @5037120 load */
    /* @5037128 constant */
    /* @5037132 cmp */
    /* @5037136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5037144;
    /* @5037140 b */
    goto L_5037200;
    L_5037144: ;
    /* @5037144 load */
    /* @5037152 constant */
    /* @5037156 cmp */
    /* @5037160 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5037200;
    /* @5037164 constant */
    /* @5037168 cast */
    /* @5037172 constant */
    /* @5037176 cast */
    /* @5037180 constant */
    /* @5037184 cast */
    /* @5037188 call */
    GM_SITE(vm, 763, 5037188);
    /* @5037196 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5037200: ;
    /* @5037200 constant */
    /* @5037204 constant */
    /* @5037208 constant */
    /* @5037212 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5037220 constant */
    /* @5037224 cast */
    /* @5037228 load */
    /* @5037236 constant */
    /* @5037240 sub */
    /* @5037244 load */
    /* @5037252 constant */
    /* @5037256 add */
    /* @5037260 call */
    GM_SITE(vm, 763, 5037260);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5037268 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5037272 constant */
    /* @5037276 cast */
    /* @5037280 load */
    /* @5037288 constant */
    /* @5037292 sub */
    /* @5037296 load */
    /* @5037304 constant */
    /* @5037308 sub */
    /* @5037312 call */
    GM_SITE(vm, 763, 5037312);
    /* @5037320 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5037324: ;
    return;
}
