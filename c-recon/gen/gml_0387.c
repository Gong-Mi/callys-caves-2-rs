/* generated from CODE 387 (gml_Object_obj_shotgun_Step_0), source start 4516688, end 4516948. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0387(GmVM* vm) {
    Val v1;
    Val p4516740_0;
    /* @4516688 constant */
    /* @4516692 cast */
    /* @4516696 call */
    GM_SITE(vm, 387, 4516696);
    /* @4516704 constant */
    /* @4516708 cmp */
    /* @4516712 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4516736;
    /* @4516716 load */
    /* @4516724 constant */
    /* @4516728 cmp */
    /* @4516732 b */
    p4516740_0 = NUMBOOL(GM_READ(vm, -5, "shotgunbought") == VAL(0));
    goto L_4516740;
    L_4516736: ;
    /* @4516736 constant */
    p4516740_0 = VAL(0);
    L_4516740: ;
    /* @4516740 bf */
    if (!TRUTH(p4516740_0)) goto L_4516948;
    /* @4516744 constant */
    /* @4516748 cast */
    /* @4516752 load */
    /* @4516760 load */
    /* @4516768 call */
    GM_SITE(vm, 387, 4516768);
    /* @4516776 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4516780 constant */
    /* @4516784 store */
    GM_WRITE(vm, -5, "shotgunbought", VAL(1));
    /* @4516792 constant */
    /* @4516796 store */
    GM_WRITE(vm, -5, "shotgun", VAL(1));
    /* @4516804 constant */
    /* @4516808 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4516816 constant */
    /* @4516820 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4516828 constant */
    /* @4516832 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4516840 constant */
    /* @4516844 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4516852 constant */
    /* @4516856 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4516864 constant */
    /* @4516868 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4516876 constant */
    /* @4516880 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4516888 constant */
    /* @4516892 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4516900 constant */
    /* @4516904 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4516912 constant */
    /* @4516916 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4516924 constant */
    /* @4516928 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4516936 call */
    GM_SITE(vm, 387, 4516936);
    /* @4516944 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4516948: ;
    return;
}
