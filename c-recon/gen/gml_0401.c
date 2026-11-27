/* generated from CODE 401 (gml_Object_obj_laser_Step_0), source start 4519200, end 4519460. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0401(GmVM* vm) {
    Val v1;
    Val p4519252_0;
    /* @4519200 constant */
    /* @4519204 cast */
    /* @4519208 call */
    GM_SITE(vm, 401, 4519208);
    /* @4519216 constant */
    /* @4519220 cmp */
    /* @4519224 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(1));
    if (!TRUTH(v1)) goto L_4519248;
    /* @4519228 load */
    /* @4519236 constant */
    /* @4519240 cmp */
    /* @4519244 b */
    p4519252_0 = NUMBOOL(GM_READ(vm, -5, "laserbought") == VAL(0));
    goto L_4519252;
    L_4519248: ;
    /* @4519248 constant */
    p4519252_0 = VAL(0);
    L_4519252: ;
    /* @4519252 bf */
    if (!TRUTH(p4519252_0)) goto L_4519460;
    /* @4519256 constant */
    /* @4519260 cast */
    /* @4519264 load */
    /* @4519272 load */
    /* @4519280 call */
    GM_SITE(vm, 401, 4519280);
    /* @4519288 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(82)));
    /* @4519292 constant */
    /* @4519296 store */
    GM_WRITE(vm, -5, "laserbought", VAL(1));
    /* @4519304 constant */
    /* @4519308 store */
    GM_WRITE(vm, -5, "laser", VAL(1));
    /* @4519316 constant */
    /* @4519320 store */
    GM_WRITE(vm, -5, "icegun", VAL(0));
    /* @4519328 constant */
    /* @4519332 store */
    GM_WRITE(vm, -5, "pistol", VAL(0));
    /* @4519340 constant */
    /* @4519344 store */
    GM_WRITE(vm, -5, "shotgun", VAL(0));
    /* @4519352 constant */
    /* @4519356 store */
    GM_WRITE(vm, -5, "assaultrifle", VAL(0));
    /* @4519364 constant */
    /* @4519368 store */
    GM_WRITE(vm, -5, "rocket", VAL(0));
    /* @4519376 constant */
    /* @4519380 store */
    GM_WRITE(vm, -5, "bladegun", VAL(0));
    /* @4519388 constant */
    /* @4519392 store */
    GM_WRITE(vm, -5, "flamethrower", VAL(0));
    /* @4519400 constant */
    /* @4519404 store */
    GM_WRITE(vm, -5, "bow", VAL(0));
    /* @4519412 constant */
    /* @4519416 store */
    GM_WRITE(vm, -5, "bombgun", VAL(0));
    /* @4519424 constant */
    /* @4519428 store */
    GM_WRITE(vm, -5, "spikegun", VAL(0));
    /* @4519436 constant */
    /* @4519440 store */
    GM_WRITE(vm, -5, "boomerang", VAL(0));
    /* @4519448 call */
    GM_SITE(vm, 401, 4519448);
    /* @4519456 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4519460: ;
    return;
}
