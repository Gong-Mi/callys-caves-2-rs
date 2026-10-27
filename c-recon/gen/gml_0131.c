/* generated from CODE 131 (gml_Object_obj_enemy2_Alarm_1), source start 3951404, end 3951696. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0131(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3951404 constant */
    /* @3951408 cast */
    /* @3951412 load */
    /* @3951420 constant */
    /* @3951424 add */
    /* @3951428 load */
    /* @3951436 call */
    GM_SITE(vm, 131, 3951436);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @3951444 cast */
    /* @3951448 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_3951696;
    /* @3951452 load */
    /* @3951460 constant */
    /* @3951464 cmp */
    /* @3951468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(1)))) goto L_3951696;
    /* @3951472 load */
    /* @3951480 load */
    /* @3951488 cmp */
    /* @3951492 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") > GM_READ(vm, -1, "x")))) goto L_3951584;
    /* @3951496 constant */
    /* @3951500 cast */
    /* @3951504 load */
    /* @3951512 constant */
    /* @3951516 sub */
    /* @3951520 load */
    /* @3951528 call */
    GM_SITE(vm, 131, 3951528);
    /* @3951536 popz */
    (void)(GM_CALL(vm, "move_towards_point", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(15)), VAL(4)));
    /* @3951540 constant */
    /* @3951544 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-8));
    /* @3951552 constant */
    /* @3951556 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(61));
    /* @3951564 constant */
    /* @3951568 constant */
    /* @3951572 constant */
    /* @3951576 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(60));
    L_3951584: ;
    /* @3951584 load */
    /* @3951592 load */
    /* @3951600 cmp */
    /* @3951604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "x") < GM_READ(vm, -1, "x")))) goto L_3951676;
    /* @3951608 constant */
    /* @3951612 cast */
    /* @3951616 load */
    /* @3951624 constant */
    /* @3951628 sub */
    /* @3951632 load */
    /* @3951640 call */
    GM_SITE(vm, 131, 3951640);
    /* @3951648 popz */
    (void)(GM_CALL(vm, "move_towards_point", 3, GM_READ(vm, 0, "x"), (GM_READ(vm, 0, "y") - VAL(15)), VAL(4)));
    /* @3951652 constant */
    /* @3951656 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-8));
    /* @3951664 constant */
    /* @3951668 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(61));
    L_3951676: ;
    /* @3951676 constant */
    /* @3951680 constant */
    /* @3951684 constant */
    /* @3951688 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(7), VAL(60));
    L_3951696: ;
    return;
}
