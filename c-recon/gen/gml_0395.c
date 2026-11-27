/* generated from CODE 395 (gml_Object_obj_flamethrower_Step_0), source start 4518128, end 4518388. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0395(GmVM* vm) {
    Val v1;
    Val p4518180_0;
    /* @4518128 constant */
    /* @4518132 cast */
    /* @4518136 call */
    GM_SITE(vm, 395, 4518136);
    /* @4518144 constant */
    /* @4518148 cmp */
    /* @4518152 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4518176;
    /* @4518156 load */
    /* @4518164 constant */
    /* @4518168 cmp */
    /* @4518172 b */
    p4518180_0 = NUMBOOL(GM_READ(vm, -5, "flamethrowerbought") == VAL(0));
    goto L_4518180;
    L_4518176: ;
    /* @4518176 constant */
    p4518180_0 = VAL(0);
    L_4518180: ;
    /* @4518180 bf */
    if (!TRUTH(p4518180_0)) goto L_4518388;
    /* @4518184 constant */
    /* @4518188 cast */
    /* @4518192 load */
    /* @4518200 load */
    /* @4518208 call */
    GM_SITE(vm, 395, 4518208);
    /* @4518216 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4518220 constant */
    /* @4518224 store */
    GM_WRITE(vm, -5, "flamethrowerbought", VAL(1));
    /* @4518232 constant */
    /* @4518236 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(1));
    /* @4518244 constant */
    /* @4518248 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4518256 constant */
    /* @4518260 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4518268 constant */
    /* @4518272 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4518280 constant */
    /* @4518284 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4518292 constant */
    /* @4518296 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4518304 constant */
    /* @4518308 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4518316 constant */
    /* @4518320 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4518328 constant */
    /* @4518332 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4518340 constant */
    /* @4518344 store */
    GM_WRITE(vm, -5, "laser", VAL(0));
    /* @4518352 constant */
    /* @4518356 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4518364 constant */
    /* @4518368 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4518376 call */
    GM_SITE(vm, 395, 4518376);
    /* @4518384 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4518388: ;
    return;
}
