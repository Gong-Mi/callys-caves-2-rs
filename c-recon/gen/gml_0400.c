/* generated from CODE 400 (gml_Object_obj_laser_Create_0), source start 4519108, end 4519200. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0400(GmVM* vm) {
    /* @4519108 constant */
    /* @4519112 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4519120 load */
    /* @4519128 constant */
    /* @4519132 cmp */
    /* @4519136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(1)))) goto L_4519156;
    /* @4519140 call */
    GM_SITE(vm, 400, 4519140);
    /* @4519148 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4519152 b */
    goto L_4519200;
    L_4519156: ;
    /* @4519156 constant */
    /* @4519160 cast */
    /* @4519164 load */
    /* @4519172 constant */
    /* @4519176 sub */
    /* @4519180 load */
    /* @4519188 call */
    GM_SITE(vm, 400, 4519188);
    /* @4519196 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4519200: ;
    return;
}
