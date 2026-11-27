/* generated from CODE 396 (gml_Object_obj_bow_Create_0), source start 4518388, end 4518488. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0396(GmVM* vm) {
    /* @4518388 constant */
    /* @4518392 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4518400 load */
    /* @4518408 constant */
    /* @4518412 cmp */
    /* @4518416 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(1)))) goto L_4518436;
    /* @4518420 call */
    GM_SITE(vm, 396, 4518420);
    /* @4518428 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4518432 b */
    goto L_4518488;
    L_4518436: ;
    /* @4518436 constant */
    /* @4518440 cast */
    /* @4518444 load */
    /* @4518452 constant */
    /* @4518456 sub */
    /* @4518460 load */
    /* @4518468 constant */
    /* @4518472 sub */
    /* @4518476 call */
    GM_SITE(vm, 396, 4518476);
    /* @4518484 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4518488: ;
    return;
}
