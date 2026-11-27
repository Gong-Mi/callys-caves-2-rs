/* generated from CODE 394 (gml_Object_obj_flamethrower_Create_0), source start 4518028, end 4518128. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0394(GmVM* vm) {
    /* @4518028 constant */
    /* @4518032 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4518040 load */
    /* @4518048 constant */
    /* @4518052 cmp */
    /* @4518056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(1)))) goto L_4518076;
    /* @4518060 call */
    GM_SITE(vm, 394, 4518060);
    /* @4518068 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4518072 b */
    goto L_4518128;
    L_4518076: ;
    /* @4518076 constant */
    /* @4518080 cast */
    /* @4518084 load */
    /* @4518092 constant */
    /* @4518096 sub */
    /* @4518100 load */
    /* @4518108 constant */
    /* @4518112 sub */
    /* @4518116 call */
    GM_SITE(vm, 394, 4518116);
    /* @4518124 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(4)), (GM_READ(vm, -1, "y") - VAL(12)), VAL(70)));
    L_4518128: ;
    return;
}
