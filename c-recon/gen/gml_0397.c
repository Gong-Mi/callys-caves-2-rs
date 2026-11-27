/* generated from CODE 397 (gml_Object_obj_bow_Step_0), source start 4518488, end 4518748. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0397(GmVM* vm) {
    Val v1;
    Val p4518540_0;
    /* @4518488 constant */
    /* @4518492 cast */
    /* @4518496 call */
    GM_SITE(vm, 397, 4518496);
    /* @4518504 constant */
    /* @4518508 cmp */
    /* @4518512 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4518536;
    /* @4518516 load */
    /* @4518524 constant */
    /* @4518528 cmp */
    /* @4518532 b */
    p4518540_0 = NUMBOOL(GM_READ(vm, -5, "bowbought") == VAL(0));
    goto L_4518540;
    L_4518536: ;
    /* @4518536 constant */
    p4518540_0 = VAL(0);
    L_4518540: ;
    /* @4518540 bf */
    if (!TRUTH(p4518540_0)) goto L_4518748;
    /* @4518544 constant */
    /* @4518548 cast */
    /* @4518552 load */
    /* @4518560 load */
    /* @4518568 call */
    GM_SITE(vm, 397, 4518568);
    /* @4518576 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4518580 constant */
    /* @4518584 store */
    GM_WRITE(vm, -5, "bowbought", VAL(1));
    /* @4518592 constant */
    /* @4518596 store */
    GM_WRITE(vm, -5, "bow", VAL(1));
    /* @4518604 constant */
    /* @4518608 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4518616 constant */
    /* @4518620 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4518628 constant */
    /* @4518632 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4518640 constant */
    /* @4518644 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4518652 constant */
    /* @4518656 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4518664 constant */
    /* @4518668 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4518676 constant */
    /* @4518680 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4518688 constant */
    /* @4518692 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4518700 constant */
    /* @4518704 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4518712 constant */
    /* @4518716 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4518724 constant */
    /* @4518728 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4518736 call */
    GM_SITE(vm, 397, 4518736);
    /* @4518744 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4518748: ;
    return;
}
