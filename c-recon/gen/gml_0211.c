/* generated from CODE 211 (gml_Object_obj_boss5_Alarm_1), source start 4018808, end 4019040. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0211(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4018808 load */
    /* @4018816 constant */
    /* @4018820 cmp */
    /* @4018824 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4019040;
    /* @4018828 load */
    /* @4018836 constant */
    /* @4018840 cmp */
    /* @4018844 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4018908;
    /* @4018848 constant */
    /* @4018852 cast */
    /* @4018856 load */
    /* @4018864 constant */
    /* @4018868 sub */
    /* @4018872 load */
    /* @4018880 constant */
    /* @4018884 sub */
    /* @4018888 call */
    GM_SITE(vm, 211, 4018888);
    /* @4018896 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4018904 b */
    goto L_4018984;
    L_4018908: ;
    /* @4018908 load */
    /* @4018916 constant */
    /* @4018920 cmp */
    /* @4018924 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4018984;
    /* @4018928 constant */
    /* @4018932 cast */
    /* @4018936 load */
    /* @4018944 constant */
    /* @4018948 sub */
    /* @4018952 load */
    /* @4018960 constant */
    /* @4018964 add */
    /* @4018968 call */
    GM_SITE(vm, 211, 4018968);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4018976 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4018984: ;
    /* @4018984 constant */
    /* @4018988 cast */
    /* @4018992 constant */
    /* @4018996 cast */
    /* @4019000 constant */
    /* @4019004 cast */
    /* @4019008 call */
    GM_SITE(vm, 211, 4019008);
    /* @4019016 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4019020 constant */
    /* @4019024 constant */
    /* @4019028 constant */
    /* @4019032 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(10));
    L_4019040: ;
    return;
}
