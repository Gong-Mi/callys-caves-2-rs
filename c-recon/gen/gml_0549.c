/* generated from CODE 549 (gml_Object_obj_introduction_Destroy_0), source start 4846408, end 4846528. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0549(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4846408 call */
    GM_SITE(vm, 549, 4846408);
    /* @4846416 popz */
    (void)(GM_CALL(vm, "instance_activate_all", 0));
    /* @4846420 constant */
    /* @4846424 store */
    GM_WRITE(vm, -5, "health1", VAL(4));
    /* @4846432 constant */
    /* @4846436 cast */
    /* @4846440 call */
    GM_SITE(vm, 549, 4846440);
    /* @4846448 cast */
    /* @4846452 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(136)));
    if (!TRUTH(v1)) goto L_4846480;
    /* @4846456 constant */
    /* @4846460 pushenv */
    if (!GM_PUSHENV(vm, VAL(136))) goto L_4846476;
    L_4846464: ;
    /* @4846464 call */
    GM_SITE(vm, 549, 4846464);
    /* @4846472 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4846476: ;
    /* @4846476 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4846464;
    L_4846480: ;
    /* @4846480 constant */
    /* @4846484 cast */
    /* @4846488 call */
    GM_SITE(vm, 549, 4846488);
    /* @4846496 cast */
    /* @4846500 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(135)));
    if (!TRUTH(v2)) goto L_4846528;
    /* @4846504 constant */
    /* @4846508 pushenv */
    if (!GM_PUSHENV(vm, VAL(135))) goto L_4846524;
    L_4846512: ;
    /* @4846512 call */
    GM_SITE(vm, 549, 4846512);
    /* @4846520 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4846524: ;
    /* @4846524 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4846512;
    L_4846528: ;
    return;
}
