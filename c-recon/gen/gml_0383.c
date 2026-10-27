/* generated from CODE 383 (gml_Object_obj_boomerang_Step_0), source start 4515976, end 4516236. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0383(GmVM* vm) {
    Val v1;
    Val p4516028_0;
    /* @4515976 constant */
    /* @4515980 cast */
    /* @4515984 call */
    GM_SITE(vm, 383, 4515984);
    /* @4515992 constant */
    /* @4515996 cmp */
    /* @4516000 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4516024;
    /* @4516004 load */
    /* @4516012 constant */
    /* @4516016 cmp */
    /* @4516020 b */
    p4516028_0 = NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(0));
    goto L_4516028;
    L_4516024: ;
    /* @4516024 constant */
    p4516028_0 = VAL(0);
    L_4516028: ;
    /* @4516028 bf */
    if (!TRUTH(p4516028_0)) goto L_4516236;
    /* @4516032 constant */
    /* @4516036 cast */
    /* @4516040 load */
    /* @4516048 load */
    /* @4516056 call */
    GM_SITE(vm, 383, 4516056);
    /* @4516064 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4516068 constant */
    /* @4516072 store */
    GM_WRITE(vm, -5, "boomerangbought", VAL(1));
    /* @4516080 constant */
    /* @4516084 store */
    GM_WRITE(vm, -5, "boomerang", VAL(1));
    /* @4516092 constant */
    /* @4516096 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4516104 constant */
    /* @4516108 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4516116 constant */
    /* @4516120 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4516128 constant */
    /* @4516132 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4516140 constant */
    /* @4516144 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4516152 constant */
    /* @4516156 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4516164 constant */
    /* @4516168 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4516176 constant */
    /* @4516180 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4516188 constant */
    /* @4516192 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4516200 constant */
    /* @4516204 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4516212 constant */
    /* @4516216 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4516224 call */
    GM_SITE(vm, 383, 4516224);
    /* @4516232 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4516236: ;
    return;
}
