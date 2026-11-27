/* generated from CODE 447 (gml_Object_obj_healthrefill_Mouse_7), source start 4632464, end 4632732. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0447(GmVM* vm) {
    Val p4632512_0;
    Val v1;
    Val p4632696_0;
    /* @4632464 load */
    /* @4632472 constant */
    /* @4632476 cmp */
    /* @4632480 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(250)))) goto L_4632508;
    /* @4632484 load */
    /* @4632492 load */
    /* @4632500 cmp */
    /* @4632504 b */
    p4632512_0 = NUMBOOL(GM_READ(vm, -5, "health1") != GM_READ(vm, -5, "maxhp"));
    goto L_4632512;
    L_4632508: ;
    /* @4632508 constant */
    p4632512_0 = VAL(0);
    L_4632512: ;
    /* @4632512 bf */
    if (!TRUTH(p4632512_0)) goto L_4632648;
    /* @4632516 load */
    /* @4632524 constant */
    /* @4632528 sub */
    /* @4632532 store */
    GM_WRITE(vm, -1, "score", (GM_READ(vm, -1, "score") - VAL(250)));
    /* @4632540 load */
    /* @4632548 constant */
    /* @4632552 add */
    /* @4632556 store */
    v1 = GM_ADD(GM_READ(vm, -5, "health1"), VAL(1));
    GM_WRITE(vm, -5, "health1", v1);
    /* @4632564 load */
    /* @4632572 constant */
    /* @4632576 cmp */
    /* @4632580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4632588;
    /* @4632584 b */
    goto L_4632644;
    L_4632588: ;
    /* @4632588 load */
    /* @4632596 constant */
    /* @4632600 cmp */
    /* @4632604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4632644;
    /* @4632608 constant */
    /* @4632612 cast */
    /* @4632616 constant */
    /* @4632620 cast */
    /* @4632624 constant */
    /* @4632628 cast */
    /* @4632632 call */
    GM_SITE(vm, 447, 4632632);
    /* @4632640 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(19), VAL(0), VAL(0)));
    L_4632644: ;
    /* @4632644 b */
    goto L_4632732;
    L_4632648: ;
    /* @4632648 load */
    /* @4632656 constant */
    /* @4632660 cmp */
    /* @4632664 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "score") >= VAL(250)))) goto L_4632692;
    /* @4632668 load */
    /* @4632676 load */
    /* @4632684 cmp */
    /* @4632688 b */
    p4632696_0 = NUMBOOL(GM_READ(vm, -5, "health1") == GM_READ(vm, -5, "maxhp"));
    goto L_4632696;
    L_4632692: ;
    /* @4632692 constant */
    p4632696_0 = VAL(0);
    L_4632696: ;
    /* @4632696 bf */
    if (!TRUTH(p4632696_0)) goto L_4632732;
    /* @4632700 constant */
    /* @4632704 store */
    GM_WRITE(vm, -1, "drawhealthfull", VAL(1));
    /* @4632712 constant */
    /* @4632716 constant */
    /* @4632720 constant */
    /* @4632724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_4632732: ;
    return;
}
