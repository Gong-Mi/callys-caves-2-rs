/* generated from CODE 59 (gml_Object_obj_shooter1_Destroy_0), source start 3903132, end 3903216. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0059(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3903132 load */
    /* @3903140 constant */
    /* @3903144 add */
    /* @3903148 store */
    v1 = GM_ADD(GM_READ(vm, -5, "pistolthugskilled"), VAL(1));
    GM_WRITE(vm, -5, "pistolthugskilled", v1);
    /* @3903156 load */
    /* @3903164 constant */
    /* @3903168 add */
    /* @3903172 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3903180 constant */
    /* @3903184 cast */
    /* @3903188 load */
    /* @3903196 load */
    /* @3903204 call */
    GM_SITE(vm, 59, 3903204);
    /* @3903212 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3903216: ;
    return;
}
