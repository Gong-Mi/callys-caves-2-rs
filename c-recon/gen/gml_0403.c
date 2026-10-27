/* generated from CODE 403 (gml_Object_obj_icegun_Step_0), source start 4519560, end 4519820. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0403(GmVM* vm) {
    Val v1;
    Val p4519612_0;
    /* @4519560 constant */
    /* @4519564 cast */
    /* @4519568 call */
    GM_SITE(vm, 403, 4519568);
    /* @4519576 constant */
    /* @4519580 cmp */
    /* @4519584 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4519608;
    /* @4519588 load */
    /* @4519596 constant */
    /* @4519600 cmp */
    /* @4519604 b */
    p4519612_0 = NUMBOOL(GM_READ(vm, -5, "icegunbought") == VAL(0));
    goto L_4519612;
    L_4519608: ;
    /* @4519608 constant */
    p4519612_0 = VAL(0);
    L_4519612: ;
    /* @4519612 bf */
    if (!TRUTH(p4519612_0)) goto L_4519820;
    /* @4519616 constant */
    /* @4519620 cast */
    /* @4519624 load */
    /* @4519632 load */
    /* @4519640 call */
    GM_SITE(vm, 403, 4519640);
    /* @4519648 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4519652 constant */
    /* @4519656 store */
    GM_WRITE(vm, -5, "icegunbought", VAL(1));
    /* @4519664 constant */
    /* @4519668 store */
    GM_WRITE(vm, -5, "icegun", VAL(1));
    /* @4519676 constant */
    /* @4519680 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4519688 constant */
    /* @4519692 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4519700 constant */
    /* @4519704 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4519712 constant */
    /* @4519716 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4519724 constant */
    /* @4519728 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4519736 constant */
    /* @4519740 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4519748 constant */
    /* @4519752 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4519760 constant */
    /* @4519764 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4519772 constant */
    /* @4519776 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4519784 constant */
    /* @4519788 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4519796 constant */
    /* @4519800 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4519808 call */
    GM_SITE(vm, 403, 4519808);
    /* @4519816 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4519820: ;
    return;
}
