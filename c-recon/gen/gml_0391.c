/* generated from CODE 391 (gml_Object_obj_rocketlauncher_Step_0), source start 4517408, end 4517668. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0391(GmVM* vm) {
    Val v1;
    Val p4517460_0;
    /* @4517408 constant */
    /* @4517412 cast */
    /* @4517416 call */
    GM_SITE(vm, 391, 4517416);
    /* @4517424 constant */
    /* @4517428 cmp */
    /* @4517432 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4517456;
    /* @4517436 load */
    /* @4517444 constant */
    /* @4517448 cmp */
    /* @4517452 b */
    p4517460_0 = NUMBOOL(GM_READ(vm, -5, "rocketbought") == VAL(0));
    goto L_4517460;
    L_4517456: ;
    /* @4517456 constant */
    p4517460_0 = VAL(0);
    L_4517460: ;
    /* @4517460 bf */
    if (!TRUTH(p4517460_0)) goto L_4517668;
    /* @4517464 constant */
    /* @4517468 cast */
    /* @4517472 load */
    /* @4517480 load */
    /* @4517488 call */
    GM_SITE(vm, 391, 4517488);
    /* @4517496 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4517500 constant */
    /* @4517504 store */
    GM_WRITE(vm, -5, "rocketbought", VAL(1));
    /* @4517512 constant */
    /* @4517516 store */
    GM_WRITE(vm, -5, "rocket", VAL(1));
    /* @4517524 constant */
    /* @4517528 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4517536 constant */
    /* @4517540 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4517548 constant */
    /* @4517552 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4517560 constant */
    /* @4517564 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4517572 constant */
    /* @4517576 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4517584 constant */
    /* @4517588 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4517596 constant */
    /* @4517600 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4517608 constant */
    /* @4517612 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4517620 constant */
    /* @4517624 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4517632 constant */
    /* @4517636 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4517644 constant */
    /* @4517648 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4517656 call */
    GM_SITE(vm, 391, 4517656);
    /* @4517664 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4517668: ;
    return;
}
