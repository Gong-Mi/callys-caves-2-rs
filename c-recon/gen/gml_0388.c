/* generated from CODE 388 (gml_Object_obj_assaultrifle_Create_0), source start 4516948, end 4517048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0388(GmVM* vm) {
    Val v1;
    /* @4516948 constant */
    /* @4516952 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4516960 load */
    /* @4516968 constant */
    /* @4516972 cmp */
    /* @4516976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "assaultriflebought") == VAL(1)))) goto L_4516996;
    /* @4516980 call */
    GM_SITE(vm, 388, 4516980);
    /* @4516988 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4516992 b */
    goto L_4517048;
    L_4516996: ;
    /* @4516996 constant */
    /* @4517000 cast */
    /* @4517004 load */
    /* @4517012 constant */
    /* @4517016 sub */
    /* @4517020 load */
    /* @4517028 constant */
    /* @4517032 add */
    /* @4517036 call */
    GM_SITE(vm, 388, 4517036);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4517044 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(14)), VAL(70)));
    L_4517048: ;
    return;
}
