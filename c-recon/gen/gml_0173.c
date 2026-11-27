/* generated from CODE 173 (gml_Object_obj_boss3_Alarm_11), source start 3994836, end 3995008. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0173(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3994836 load */
    /* @3994844 load */
    /* @3994852 cmp */
    /* @3994856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") <= GM_READ(vm, -1, "x")))) goto L_3994928;
    /* @3994860 constant */
    /* @3994864 cast */
    /* @3994868 constant */
    /* @3994872 cast */
    /* @3994876 call */
    GM_SITE(vm, 173, 3994876);
    /* @3994884 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(-3), VAL(3));
    GM_WRITE(vm, -1, "vspeed", v1);
    /* @3994892 constant */
    /* @3994896 cast */
    /* @3994900 constant */
    /* @3994904 cast */
    /* @3994908 call */
    GM_SITE(vm, 173, 3994908);
    /* @3994916 store */
    v2 = GM_CALL(vm, "choose", 2, VAL(-2), VAL(2));
    GM_WRITE(vm, -1, "hspeed", v2);
    /* @3994924 b */
    goto L_3994988;
    L_3994928: ;
    /* @3994928 load */
    /* @3994936 load */
    /* @3994944 cmp */
    /* @3994948 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") >= GM_READ(vm, -1, "x")))) goto L_3994988;
    /* @3994952 constant */
    /* @3994956 cast */
    /* @3994960 load */
    /* @3994968 load */
    /* @3994976 call */
    GM_SITE(vm, 173, 3994976);
    /* @3994984 popz */
    (void)(GM_CALL(vm, "move_towards_point", 3, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(2)));
    L_3994988: ;
    /* @3994988 constant */
    /* @3994992 constant */
    /* @3994996 constant */
    /* @3995000 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(11), VAL(20));
    L_3995008: ;
    return;
}
