/* generated from CODE 122 (gml_Object_obj_hulkingbandit_Draw_0), source start 3949928, end 3950120. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0122(GmVM* vm) {
    /* @3949928 load */
    /* @3949936 constant */
    /* @3949940 cmp */
    /* @3949944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3950056;
    /* @3949948 constant */
    /* @3949952 cast */
    /* @3949956 constant */
    /* @3949960 cast */
    /* @3949964 constant */
    /* @3949972 cast */
    /* @3949976 constant */
    /* @3949980 cast */
    /* @3949984 call */
    GM_SITE(vm, 122, 3949984);
    /* @3949992 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3949996 call */
    GM_SITE(vm, 122, 3949996);
    /* @3950004 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3950008 constant */
    /* @3950012 cast */
    /* @3950016 constant */
    /* @3950020 cast */
    /* @3950024 constant */
    /* @3950028 cast */
    /* @3950032 constant */
    /* @3950036 cast */
    /* @3950040 call */
    GM_SITE(vm, 122, 3950040);
    /* @3950048 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3950052 b */
    goto L_3950088;
    L_3950056: ;
    /* @3950056 load */
    /* @3950064 constant */
    /* @3950068 cmp */
    /* @3950072 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3950088;
    /* @3950076 call */
    GM_SITE(vm, 122, 3950076);
    /* @3950084 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3950088: ;
    /* @3950088 load */
    /* @3950096 constant */
    /* @3950100 cmp */
    /* @3950104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3950120;
    /* @3950108 constant */
    /* @3950112 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3950120: ;
    return;
}
