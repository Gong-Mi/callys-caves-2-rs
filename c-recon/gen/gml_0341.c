/* generated from CODE 341 (gml_Object_obj_gem_Create_0), source start 4197112, end 4197240. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0341(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4197112 constant */
    /* @4197116 store */
    GM_WRITE(vm, -1, "type", VAL(2));
    /* @4197124 constant */
    /* @4197136 store */
    GM_WRITE(vm, -1, "friction", VAL(0.3));
    /* @4197144 constant */
    /* @4197148 cast */
    /* @4197152 load */
    /* @4197160 constant */
    /* @4197164 sub */
    /* @4197168 load */
    /* @4197176 call */
    GM_SITE(vm, 341, 4197176);
    /* @4197184 cast */
    /* @4197188 not */
    /* @4197192 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(1)), VAL(34))));
    if (!TRUTH(v1)) goto L_4197216;
    /* @4197196 load */
    /* @4197204 store */
    GM_WRITE(vm, -1, "yorigin", GM_READ(vm, -1, "y"));
    /* @4197212 b */
    goto L_4197240;
    L_4197216: ;
    /* @4197216 load */
    /* @4197224 constant */
    /* @4197228 add */
    /* @4197232 store */
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(32));
    GM_WRITE(vm, -1, "yorigin", v2);
    L_4197240: ;
    return;
}
