/* generated from CODE 206 (gml_Object_obj_boss5_Alarm_6), source start 4017948, end 4018160. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0206(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4017948 load */
    /* @4017956 constant */
    /* @4017960 cmp */
    /* @4017964 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4018028;
    /* @4017968 constant */
    /* @4017972 cast */
    /* @4017976 load */
    /* @4017984 constant */
    /* @4017988 sub */
    /* @4017992 load */
    /* @4018000 constant */
    /* @4018004 sub */
    /* @4018008 call */
    GM_SITE(vm, 206, 4018008);
    /* @4018016 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4018024 b */
    goto L_4018104;
    L_4018028: ;
    /* @4018028 load */
    /* @4018036 constant */
    /* @4018040 cmp */
    /* @4018044 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4018104;
    /* @4018048 constant */
    /* @4018052 cast */
    /* @4018056 load */
    /* @4018064 constant */
    /* @4018068 sub */
    /* @4018072 load */
    /* @4018080 constant */
    /* @4018084 add */
    /* @4018088 call */
    GM_SITE(vm, 206, 4018088);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4018096 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4018104: ;
    /* @4018104 constant */
    /* @4018108 cast */
    /* @4018112 constant */
    /* @4018116 cast */
    /* @4018120 constant */
    /* @4018124 cast */
    /* @4018128 call */
    GM_SITE(vm, 206, 4018128);
    /* @4018136 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4018140 constant */
    /* @4018144 constant */
    /* @4018148 constant */
    /* @4018152 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(10));
    L_4018160: ;
    return;
}
