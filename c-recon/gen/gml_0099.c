/* generated from CODE 99 (gml_Object_obj_zombie_Draw_0), source start 3932928, end 3933120. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0099(GmVM* vm) {
    /* @3932928 load */
    /* @3932936 constant */
    /* @3932940 cmp */
    /* @3932944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3933056;
    /* @3932948 constant */
    /* @3932952 cast */
    /* @3932956 constant */
    /* @3932960 cast */
    /* @3932964 constant */
    /* @3932972 cast */
    /* @3932976 constant */
    /* @3932980 cast */
    /* @3932984 call */
    GM_SITE(vm, 99, 3932984);
    /* @3932992 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3932996 call */
    GM_SITE(vm, 99, 3932996);
    /* @3933004 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3933008 constant */
    /* @3933012 cast */
    /* @3933016 constant */
    /* @3933020 cast */
    /* @3933024 constant */
    /* @3933028 cast */
    /* @3933032 constant */
    /* @3933036 cast */
    /* @3933040 call */
    GM_SITE(vm, 99, 3933040);
    /* @3933048 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3933052 b */
    goto L_3933088;
    L_3933056: ;
    /* @3933056 load */
    /* @3933064 constant */
    /* @3933068 cmp */
    /* @3933072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3933088;
    /* @3933076 call */
    GM_SITE(vm, 99, 3933076);
    /* @3933084 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3933088: ;
    /* @3933088 load */
    /* @3933096 constant */
    /* @3933100 cmp */
    /* @3933104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3933120;
    /* @3933108 constant */
    /* @3933112 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3933120: ;
    return;
}
