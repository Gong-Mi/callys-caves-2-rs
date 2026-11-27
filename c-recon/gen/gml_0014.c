/* generated from CODE 14 (gml_Object_obj_player_Collision_60), source start 3803436, end 3803608. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0014(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @3803436 load */
    /* @3803444 constant */
    /* @3803448 load */
    /* @3803456 mul */
    /* @3803460 add */
    /* @3803464 store */
    v1 = GM_ADD(GM_READ(vm, -1, "score"), (VAL(4) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -1, "score", v1);
    /* @3803472 load */
    /* @3803480 constant */
    /* @3803484 load */
    /* @3803492 mul */
    /* @3803496 add */
    /* @3803500 store */
    v2 = GM_ADD(GM_READ(vm, -5, "coinpickup"), (VAL(4) * GM_READ(vm, -5, "coinmultiply")));
    GM_WRITE(vm, -5, "coinpickup", v2);
    /* @3803508 constant */
    /* @3803512 cast */
    /* @3803516 constant */
    /* @3803520 constant */
    /* @3803524 load */
    /* @3803532 constant */
    /* @3803536 add */
    /* @3803540 constant */
    /* @3803544 constant */
    /* @3803548 load */
    /* @3803556 constant */
    /* @3803560 add */
    /* @3803564 call */
    GM_SITE(vm, 14, 3803564);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(225));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(4));
    /* @3803572 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, v4, VAL(132)));
    /* @3803576 load */
    /* @3803584 cast */
    /* @3803588 pushenv */
    if (!GM_PUSHENV(vm, TO_INT(GM_READ(vm, -2, "id")))) goto L_3803604;
    L_3803592: ;
    /* @3803592 call */
    GM_SITE(vm, 14, 3803592);
    /* @3803600 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_3803604: ;
    /* @3803604 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_3803592;
    L_3803608: ;
    return;
}
