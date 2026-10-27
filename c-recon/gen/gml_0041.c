/* generated from CODE 41 (gml_Object_obj_enemy_Destroy_0), source start 3889840, end 3889924. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0041(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3889840 load */
    /* @3889848 constant */
    /* @3889852 add */
    /* @3889856 store */
    v1 = GM_ADD(GM_READ(vm, -5, "bearskilled"), VAL(1));
    GM_WRITE(vm, -5, "bearskilled", v1);
    /* @3889864 load */
    /* @3889872 constant */
    /* @3889876 add */
    /* @3889880 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3889888 constant */
    /* @3889892 cast */
    /* @3889896 load */
    /* @3889904 load */
    /* @3889912 call */
    GM_SITE(vm, 41, 3889912);
    /* @3889920 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(187)));
    L_3889924: ;
    return;
}
