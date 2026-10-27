/* generated from CODE 352 (gml_Object_obj_levelup_Create_0), source start 4198980, end 4199148. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0352(GmVM* vm) {
    Val v1;
    /* @4198980 load */
    /* @4198988 constant */
    /* @4198992 add */
    /* @4198996 store */
    v1 = GM_ADD(GM_READ(vm, 66, "x"), VAL(50));
    GM_WRITE(vm, -1, "xposition", v1);
    /* @4199004 constant */
    /* @4199008 store */
    GM_WRITE(vm, -1, "showpart", VAL(1));
    /* @4199016 constant */
    /* @4199020 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-1));
    /* @4199028 load */
    /* @4199036 constant */
    /* @4199040 cmp */
    /* @4199044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_4199052;
    /* @4199048 b */
    goto L_4199108;
    L_4199052: ;
    /* @4199052 load */
    /* @4199060 constant */
    /* @4199064 cmp */
    /* @4199068 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_4199108;
    /* @4199072 constant */
    /* @4199076 cast */
    /* @4199080 constant */
    /* @4199084 cast */
    /* @4199088 constant */
    /* @4199092 cast */
    /* @4199096 call */
    GM_SITE(vm, 352, 4199096);
    /* @4199104 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(27), VAL(0), VAL(0)));
    L_4199108: ;
    /* @4199108 constant */
    /* @4199112 constant */
    /* @4199116 constant */
    /* @4199120 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(94));
    /* @4199128 constant */
    /* @4199132 constant */
    /* @4199136 constant */
    /* @4199140 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(40));
    L_4199148: ;
    return;
}
