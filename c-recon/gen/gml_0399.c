/* generated from CODE 399 (gml_Object_obj_bombgun_Step_0), source start 4518848, end 4519108. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0399(GmVM* vm) {
    Val v1;
    Val p4518900_0;
    /* @4518848 constant */
    /* @4518852 cast */
    /* @4518856 call */
    GM_SITE(vm, 399, 4518856);
    /* @4518864 constant */
    /* @4518868 cmp */
    /* @4518872 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4518896;
    /* @4518876 load */
    /* @4518884 constant */
    /* @4518888 cmp */
    /* @4518892 b */
    p4518900_0 = NUMBOOL(GM_READ(vm, -5, "bombgunbought") == VAL(0));
    goto L_4518900;
    L_4518896: ;
    /* @4518896 constant */
    p4518900_0 = VAL(0);
    L_4518900: ;
    /* @4518900 bf */
    if (!TRUTH(p4518900_0)) goto L_4519108;
    /* @4518904 constant */
    /* @4518908 cast */
    /* @4518912 load */
    /* @4518920 load */
    /* @4518928 call */
    GM_SITE(vm, 399, 4518928);
    /* @4518936 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4518940 constant */
    /* @4518944 store */
    GM_WRITE(vm, -5, "bombgunbought", VAL(1));
    /* @4518952 constant */
    /* @4518956 store */
    GM_WRITE(vm, -5, "bombgun", VAL(1));
    /* @4518964 constant */
    /* @4518968 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4518976 constant */
    /* @4518980 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4518988 constant */
    /* @4518992 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4519000 constant */
    /* @4519004 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4519012 constant */
    /* @4519016 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4519024 constant */
    /* @4519028 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4519036 constant */
    /* @4519040 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4519048 constant */
    /* @4519052 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4519060 constant */
    /* @4519064 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4519072 constant */
    /* @4519076 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4519084 constant */
    /* @4519088 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4519096 call */
    GM_SITE(vm, 399, 4519096);
    /* @4519104 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4519108: ;
    return;
}
