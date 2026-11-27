/* generated from CODE 382 (gml_Object_obj_boomerang_Create_0), source start 4515876, end 4515976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0382(GmVM* vm) {
    /* @4515876 constant */
    /* @4515880 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4515888 load */
    /* @4515896 constant */
    /* @4515900 cmp */
    /* @4515904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomerangbought") == VAL(1)))) goto L_4515924;
    /* @4515908 call */
    GM_SITE(vm, 382, 4515908);
    /* @4515916 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4515920 b */
    goto L_4515976;
    L_4515924: ;
    /* @4515924 constant */
    /* @4515928 cast */
    /* @4515932 load */
    /* @4515940 constant */
    /* @4515944 sub */
    /* @4515948 load */
    /* @4515956 constant */
    /* @4515960 sub */
    /* @4515964 call */
    GM_SITE(vm, 382, 4515964);
    /* @4515972 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), (GM_READ(vm, -1, "y") - VAL(16)), VAL(70)));
    L_4515976: ;
    return;
}
