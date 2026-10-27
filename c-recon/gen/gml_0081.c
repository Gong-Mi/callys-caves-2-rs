/* generated from CODE 81 (gml_Object_obj_firehulk_Destroy_0), source start 3918976, end 3919060. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0081(GmVM* vm) {
    Val v1;
    Val v2;
    /* @3918976 load */
    /* @3918984 constant */
    /* @3918988 add */
    /* @3918992 store */
    v1 = GM_ADD(GM_READ(vm, -5, "firehulkskilled"), VAL(1));
    GM_WRITE(vm, -5, "firehulkskilled", v1);
    /* @3919000 load */
    /* @3919008 constant */
    /* @3919012 add */
    /* @3919016 store */
    v2 = GM_ADD(GM_READ(vm, -5, "enemieskilled"), VAL(1));
    GM_WRITE(vm, -5, "enemieskilled", v2);
    /* @3919024 constant */
    /* @3919028 cast */
    /* @3919032 load */
    /* @3919040 load */
    /* @3919048 call */
    GM_SITE(vm, 81, 3919048);
    /* @3919056 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(188)));
    L_3919060: ;
    return;
}
