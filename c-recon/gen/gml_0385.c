/* generated from CODE 385 (gml_Object_obj_spikegun_Step_0), source start 4516336, end 4516596. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0385(GmVM* vm) {
    Val v1;
    Val p4516388_0;
    /* @4516336 constant */
    /* @4516340 cast */
    /* @4516344 call */
    GM_SITE(vm, 385, 4516344);
    /* @4516352 constant */
    /* @4516356 cmp */
    /* @4516360 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4516384;
    /* @4516364 load */
    /* @4516372 constant */
    /* @4516376 cmp */
    /* @4516380 b */
    p4516388_0 = NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(0));
    goto L_4516388;
    L_4516384: ;
    /* @4516384 constant */
    p4516388_0 = VAL(0);
    L_4516388: ;
    /* @4516388 bf */
    if (!TRUTH(p4516388_0)) goto L_4516596;
    /* @4516392 constant */
    /* @4516396 cast */
    /* @4516400 load */
    /* @4516408 load */
    /* @4516416 call */
    GM_SITE(vm, 385, 4516416);
    /* @4516424 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4516428 constant */
    /* @4516432 store */
    GM_WRITE(vm, -5, "spikegunbought", VAL(1));
    /* @4516440 constant */
    /* @4516444 store */
    GM_WRITE(vm, -5, "spikegun", VAL(1));
    /* @4516452 constant */
    /* @4516456 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4516464 constant */
    /* @4516468 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4516476 constant */
    /* @4516480 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4516488 constant */
    /* @4516492 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4516500 constant */
    /* @4516504 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4516512 constant */
    /* @4516516 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4516524 constant */
    /* @4516528 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4516536 constant */
    /* @4516540 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4516548 constant */
    /* @4516552 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4516560 constant */
    /* @4516564 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4516572 constant */
    /* @4516576 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4516584 call */
    GM_SITE(vm, 385, 4516584);
    /* @4516592 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4516596: ;
    return;
}
