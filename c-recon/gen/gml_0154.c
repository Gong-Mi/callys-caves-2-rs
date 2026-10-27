/* generated from CODE 154 (gml_Object_obj_trex_Create_0), source start 3972484, end 3972828. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0154(GmVM* vm) {
    Val v1;
    /* @3972484 constant */
    /* @3972488 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3972496 constant */
    /* @3972500 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3972508 constant */
    /* @3972512 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3972520 constant */
    /* @3972524 constant */
    /* @3972528 constant */
    /* @3972532 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(80));
    /* @3972540 constant */
    /* @3972544 constant */
    /* @3972548 constant */
    /* @3972552 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(100));
    /* @3972560 constant */
    /* @3972564 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3972572 constant */
    /* @3972576 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3972584 constant */
    /* @3972588 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @3972596 constant */
    /* @3972600 cast */
    /* @3972604 constant */
    /* @3972608 cast */
    /* @3972612 constant */
    /* @3972616 cast */
    /* @3972620 constant */
    /* @3972624 cast */
    /* @3972628 constant */
    /* @3972632 cast */
    /* @3972636 call */
    GM_SITE(vm, 154, 3972636);
    /* @3972644 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3972652 load */
    /* @3972660 constant */
    /* @3972664 cmp */
    /* @3972668 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3972696;
    /* @3972672 constant */
    /* @3972676 store */
    GM_WRITE(vm, -1, "hptrex", VAL(275));
    /* @3972684 constant */
    /* @3972688 store */
    GM_WRITE(vm, -1, "boss1maxhp", VAL(275));
    L_3972696: ;
    /* @3972696 load */
    /* @3972704 constant */
    /* @3972708 cmp */
    /* @3972712 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3972740;
    /* @3972716 constant */
    /* @3972720 store */
    GM_WRITE(vm, -1, "hptrex", VAL(225));
    /* @3972728 constant */
    /* @3972732 store */
    GM_WRITE(vm, -1, "boss1maxhp", VAL(225));
    L_3972740: ;
    /* @3972740 load */
    /* @3972748 constant */
    /* @3972752 cmp */
    /* @3972756 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3972784;
    /* @3972760 constant */
    /* @3972764 store */
    GM_WRITE(vm, -1, "hptrex", VAL(150));
    /* @3972772 constant */
    /* @3972776 store */
    GM_WRITE(vm, -1, "boss1maxhp", VAL(150));
    L_3972784: ;
    /* @3972784 load */
    /* @3972792 constant */
    /* @3972796 cmp */
    /* @3972800 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3972828;
    /* @3972804 constant */
    /* @3972808 store */
    GM_WRITE(vm, -1, "hptrex", VAL(100));
    /* @3972816 constant */
    /* @3972820 store */
    GM_WRITE(vm, -1, "boss1maxhp", VAL(100));
    L_3972828: ;
    return;
}
