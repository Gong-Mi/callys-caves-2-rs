/* generated from CODE 384 (gml_Object_obj_spikegun_Create_0), source start 4516236, end 4516336. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0384(GmVM* vm) {
    Val v1;
    /* @4516236 constant */
    /* @4516240 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4516248 load */
    /* @4516256 constant */
    /* @4516260 cmp */
    /* @4516264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "spikegunbought") == VAL(1)))) goto L_4516284;
    /* @4516268 call */
    GM_SITE(vm, 384, 4516268);
    /* @4516276 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    /* @4516280 b */
    goto L_4516336;
    L_4516284: ;
    /* @4516284 constant */
    /* @4516288 cast */
    /* @4516292 load */
    /* @4516300 constant */
    /* @4516304 sub */
    /* @4516308 load */
    /* @4516316 constant */
    /* @4516320 add */
    /* @4516324 call */
    GM_SITE(vm, 384, 4516324);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @4516332 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(12)), VAL(70)));
    L_4516336: ;
    return;
}
