/* generated from CODE 481 (gml_Object_obj_norestoredata_Mouse_7), source start 4673960, end 4674116. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0481(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4673960 constant */
    /* @4673964 cast */
    /* @4673968 call */
    GM_SITE(vm, 481, 4673968);
    /* @4673976 cast */
    /* @4673980 bf */
    v1 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(114)));
    if (!TRUTH(v1)) goto L_4674008;
    /* @4673984 constant */
    /* @4673988 pushenv */
    if (!GM_PUSHENV(vm, VAL(114))) goto L_4674004;
    L_4673992: ;
    /* @4673992 call */
    GM_SITE(vm, 481, 4673992);
    /* @4674000 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4674004: ;
    /* @4674004 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4673992;
    L_4674008: ;
    /* @4674008 constant */
    /* @4674012 cast */
    /* @4674016 call */
    GM_SITE(vm, 481, 4674016);
    /* @4674024 cast */
    /* @4674028 bf */
    v2 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(112)));
    if (!TRUTH(v2)) goto L_4674056;
    /* @4674032 constant */
    /* @4674036 pushenv */
    if (!GM_PUSHENV(vm, VAL(112))) goto L_4674052;
    L_4674040: ;
    /* @4674040 call */
    GM_SITE(vm, 481, 4674040);
    /* @4674048 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4674052: ;
    /* @4674052 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4674040;
    L_4674056: ;
    /* @4674056 constant */
    /* @4674060 cast */
    /* @4674064 call */
    GM_SITE(vm, 481, 4674064);
    /* @4674072 cast */
    /* @4674076 bf */
    v3 = BOOL(GM_CALL(vm, "instance_exists", 1, VAL(113)));
    if (!TRUTH(v3)) goto L_4674104;
    /* @4674080 constant */
    /* @4674084 pushenv */
    if (!GM_PUSHENV(vm, VAL(113))) goto L_4674100;
    L_4674088: ;
    /* @4674088 call */
    GM_SITE(vm, 481, 4674088);
    /* @4674096 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4674100: ;
    /* @4674100 popenv */
    if (GM_POPENV_NEXT(vm)) goto L_4674088;
    L_4674104: ;
    /* @4674104 call */
    GM_SITE(vm, 481, 4674104);
    /* @4674112 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4674116: ;
    return;
}
