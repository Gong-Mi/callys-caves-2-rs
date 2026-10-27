/* generated from CODE 389 (gml_Object_obj_assaultrifle_Step_0), source start 4517048, end 4517308. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0389(GmVM* vm) {
    Val v1;
    Val p4517100_0;
    /* @4517048 constant */
    /* @4517052 cast */
    /* @4517056 call */
    GM_SITE(vm, 389, 4517056);
    /* @4517064 constant */
    /* @4517068 cmp */
    /* @4517072 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4517096;
    /* @4517076 load */
    /* @4517084 constant */
    /* @4517088 cmp */
    /* @4517092 b */
    p4517100_0 = NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(0));
    goto L_4517100;
    L_4517096: ;
    /* @4517096 constant */
    p4517100_0 = VAL(0);
    L_4517100: ;
    /* @4517100 bf */
    if (!TRUTH(p4517100_0)) goto L_4517308;
    /* @4517104 constant */
    /* @4517108 cast */
    /* @4517112 load */
    /* @4517120 load */
    /* @4517128 call */
    GM_SITE(vm, 389, 4517128);
    /* @4517136 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4517140 constant */
    /* @4517144 store */
    GM_WRITE(vm, -5, "assaultriflebought", VAL(1));
    /* @4517152 constant */
    /* @4517156 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(1));
    /* @4517164 constant */
    /* @4517168 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4517176 constant */
    /* @4517180 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4517188 constant */
    /* @4517192 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4517200 constant */
    /* @4517204 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4517212 constant */
    /* @4517216 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4517224 constant */
    /* @4517228 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4517236 constant */
    /* @4517240 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4517248 constant */
    /* @4517252 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4517260 constant */
    /* @4517264 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4517272 constant */
    /* @4517276 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4517284 constant */
    /* @4517288 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4517296 call */
    GM_SITE(vm, 389, 4517296);
    /* @4517304 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4517308: ;
    return;
}
