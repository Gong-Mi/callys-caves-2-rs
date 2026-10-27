/* generated from CODE 347 (gml_Object_obj_XPorb_Create_0), source start 4198048, end 4198188. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0347(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4198048 constant */
    /* @4198052 store */
    GM_WRITE(vm, -1, "xpadd", VAL(1));
    /* @4198060 constant */
    /* @4198072 store */
    GM_WRITE(vm, -1, "friction", VAL(0.3));
    /* @4198080 constant */
    /* @4198084 store */
    GM_WRITE(vm, -1, "type", VAL(4));
    /* @4198092 constant */
    /* @4198096 cast */
    /* @4198100 load */
    /* @4198108 constant */
    /* @4198112 sub */
    /* @4198116 load */
    /* @4198124 call */
    GM_SITE(vm, 347, 4198124);
    /* @4198132 cast */
    /* @4198136 not */
    /* @4198140 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(1)), VAL(34))));
    if (!TRUTH(v1)) goto L_4198164;
    /* @4198144 load */
    /* @4198152 store */
    GM_WRITE(vm, -1, "yorigin", GM_READ(vm, -1, "y"));
    /* @4198160 b */
    goto L_4198188;
    L_4198164: ;
    /* @4198164 load */
    /* @4198172 constant */
    /* @4198176 add */
    /* @4198180 store */
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "yorigin", v2);
    L_4198188: ;
    return;
}
