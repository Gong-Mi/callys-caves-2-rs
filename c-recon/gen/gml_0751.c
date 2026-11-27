/* generated from CODE 751 (gml_Object_obj_zombieintro_Create_0), source start 5035920, end 5036124. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0751(GmVM* vm) {
    Val v1;
    /* @5035920 load */
    /* @5035928 constant */
    /* @5035932 cmp */
    /* @5035936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5035944;
    /* @5035940 b */
    goto L_5036000;
    L_5035944: ;
    /* @5035944 load */
    /* @5035952 constant */
    /* @5035956 cmp */
    /* @5035960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5036000;
    /* @5035964 constant */
    /* @5035968 cast */
    /* @5035972 constant */
    /* @5035976 cast */
    /* @5035980 constant */
    /* @5035984 cast */
    /* @5035988 call */
    GM_SITE(vm, 751, 5035988);
    /* @5035996 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5036000: ;
    /* @5036000 constant */
    /* @5036004 constant */
    /* @5036008 constant */
    /* @5036012 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5036020 constant */
    /* @5036024 cast */
    /* @5036028 load */
    /* @5036036 constant */
    /* @5036040 sub */
    /* @5036044 load */
    /* @5036052 constant */
    /* @5036056 add */
    /* @5036060 call */
    GM_SITE(vm, 751, 5036060);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5036068 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5036072 constant */
    /* @5036076 cast */
    /* @5036080 load */
    /* @5036088 constant */
    /* @5036092 sub */
    /* @5036096 load */
    /* @5036104 constant */
    /* @5036108 sub */
    /* @5036112 call */
    GM_SITE(vm, 751, 5036112);
    /* @5036120 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5036124: ;
    return;
}
