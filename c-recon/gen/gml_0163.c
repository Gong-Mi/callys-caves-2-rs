/* generated from CODE 163 (gml_Object_obj_boss2_Create_0), source start 3983356, end 3983680. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0163(GmVM* vm) {
    Val v1;
    /* @3983356 constant */
    /* @3983360 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3983368 constant */
    /* @3983372 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3983380 constant */
    /* @3983384 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3983392 constant */
    /* @3983396 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3983404 constant */
    /* @3983408 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3983416 constant */
    /* @3983420 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @3983428 constant */
    /* @3983432 constant */
    /* @3983436 constant */
    /* @3983440 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(100));
    /* @3983448 constant */
    /* @3983452 cast */
    /* @3983456 constant */
    /* @3983460 cast */
    /* @3983464 constant */
    /* @3983468 cast */
    /* @3983472 constant */
    /* @3983476 cast */
    /* @3983480 constant */
    /* @3983484 cast */
    /* @3983488 call */
    GM_SITE(vm, 163, 3983488);
    /* @3983496 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3983504 load */
    /* @3983512 constant */
    /* @3983516 cmp */
    /* @3983520 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3983548;
    /* @3983524 constant */
    /* @3983528 store */
    GM_WRITE(vm, -1, "hpboss2", VAL(750));
    /* @3983536 constant */
    /* @3983540 store */
    GM_WRITE(vm, -1, "boss2maxhp", VAL(750));
    L_3983548: ;
    /* @3983548 load */
    /* @3983556 constant */
    /* @3983560 cmp */
    /* @3983564 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3983592;
    /* @3983568 constant */
    /* @3983572 store */
    GM_WRITE(vm, -1, "hpboss2", VAL(700));
    /* @3983580 constant */
    /* @3983584 store */
    GM_WRITE(vm, -1, "boss2maxhp", VAL(700));
    L_3983592: ;
    /* @3983592 load */
    /* @3983600 constant */
    /* @3983604 cmp */
    /* @3983608 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3983636;
    /* @3983612 constant */
    /* @3983616 store */
    GM_WRITE(vm, -1, "hpboss2", VAL(625));
    /* @3983624 constant */
    /* @3983628 store */
    GM_WRITE(vm, -1, "boss2maxhp", VAL(625));
    L_3983636: ;
    /* @3983636 load */
    /* @3983644 constant */
    /* @3983648 cmp */
    /* @3983652 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3983680;
    /* @3983656 constant */
    /* @3983660 store */
    GM_WRITE(vm, -1, "hpboss2", VAL(525));
    /* @3983668 constant */
    /* @3983672 store */
    GM_WRITE(vm, -1, "boss2maxhp", VAL(525));
    L_3983680: ;
    return;
}
