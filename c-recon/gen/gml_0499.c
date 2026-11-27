/* generated from CODE 499 (gml_Object_obj_iapmenu_Destroy_0), source start 4692848, end 4692992. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0499(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4692848 constant */
    /* @4692852 cast */
    /* @4692856 call */
    GM_SITE(vm, 499, 4692856);
    /* @4692864 cast */
    /* @4692868 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(119)));
    if (!TRUTH(v1)) goto L_4692896;
    /* @4692872 constant */
    /* @4692876 pushenv */
    if (!GM_PUSHENV(vm, VAL(119))) goto L_4692892;
    L_4692880: ;
    /* @4692880 call */
    GM_SITE(vm, 499, 4692880);
    /* @4692888 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4692892: ;
    /* @4692892 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4692880;
    L_4692896: ;
    /* @4692896 constant */
    /* @4692900 cast */
    /* @4692904 call */
    GM_SITE(vm, 499, 4692904);
    /* @4692912 cast */
    /* @4692916 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(120)));
    if (!TRUTH(v2)) goto L_4692944;
    /* @4692920 constant */
    /* @4692924 pushenv */
    if (!GM_PUSHENV(vm, VAL(120))) goto L_4692940;
    L_4692928: ;
    /* @4692928 call */
    GM_SITE(vm, 499, 4692928);
    /* @4692936 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4692940: ;
    /* @4692940 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4692928;
    L_4692944: ;
    /* @4692944 constant */
    /* @4692948 cast */
    /* @4692952 call */
    GM_SITE(vm, 499, 4692952);
    /* @4692960 cast */
    /* @4692964 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(121)));
    if (!TRUTH(v3)) goto L_4692992;
    /* @4692968 constant */
    /* @4692972 pushenv */
    if (!GM_PUSHENV(vm, VAL(121))) goto L_4692988;
    L_4692976: ;
    /* @4692976 call */
    GM_SITE(vm, 499, 4692976);
    /* @4692984 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4692988: ;
    /* @4692988 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4692976;
    L_4692992: ;
    return;
}
