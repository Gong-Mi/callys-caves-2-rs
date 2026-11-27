/* generated from CODE 483 (gml_Object_obj_areyousure_Create_0), source start 4675500, end 4675636. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0483(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @4675500 constant */
    /* @4675504 cast */
    /* @4675508 constant */
    /* @4675512 constant */
    /* @4675516 load */
    /* @4675524 constant */
    /* @4675528 add */
    /* @4675532 constant */
    /* @4675536 constant */
    /* @4675540 load */
    /* @4675548 constant */
    /* @4675552 add */
    /* @4675556 call */
    GM_SITE(vm, 483, 4675556);
    v1 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(40));
    v2 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(155));
    /* @4675564 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, v2, VAL(112)));
    /* @4675568 constant */
    /* @4675572 cast */
    /* @4675576 constant */
    /* @4675580 constant */
    /* @4675584 load */
    /* @4675592 constant */
    /* @4675596 add */
    /* @4675600 constant */
    /* @4675604 constant */
    /* @4675608 load */
    /* @4675616 constant */
    /* @4675620 add */
    /* @4675624 call */
    GM_SITE(vm, 483, 4675624);
    v3 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_xview", VAL(0)), VAL(180));
    v4 = GM_ADD(GM_READ_ARR(vm, VAL(-1), "view_yview", VAL(0)), VAL(155));
    /* @4675632 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v3, v4, VAL(113)));
    L_4675636: ;
    return;
}
