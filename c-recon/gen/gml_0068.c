/* generated from CODE 68 (gml_Object_obj_shooter1_Draw_0), source start 3909916, end 3910108. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0068(GmVM* vm) {
    /* @3909916 load */
    /* @3909924 constant */
    /* @3909928 cmp */
    /* @3909932 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3910044;
    /* @3909936 constant */
    /* @3909940 cast */
    /* @3909944 constant */
    /* @3909948 cast */
    /* @3909952 constant */
    /* @3909960 cast */
    /* @3909964 constant */
    /* @3909968 cast */
    /* @3909972 call */
    GM_SITE(vm, 68, 3909972);
    /* @3909980 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3909984 call */
    GM_SITE(vm, 68, 3909984);
    /* @3909992 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3909996 constant */
    /* @3910000 cast */
    /* @3910004 constant */
    /* @3910008 cast */
    /* @3910012 constant */
    /* @3910016 cast */
    /* @3910020 constant */
    /* @3910024 cast */
    /* @3910028 call */
    GM_SITE(vm, 68, 3910028);
    /* @3910036 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3910040 b */
    goto L_3910076;
    L_3910044: ;
    /* @3910044 load */
    /* @3910052 constant */
    /* @3910056 cmp */
    /* @3910060 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3910076;
    /* @3910064 call */
    GM_SITE(vm, 68, 3910064);
    /* @3910072 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3910076: ;
    /* @3910076 load */
    /* @3910084 constant */
    /* @3910088 cmp */
    /* @3910092 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3910108;
    /* @3910096 constant */
    /* @3910100 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3910108: ;
    return;
}
