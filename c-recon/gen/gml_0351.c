/* generated from CODE 351 (gml_Object_obj_health_Step_0), source start 4198720, end 4198980. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0351(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4198720 constant */
    /* @4198724 cast */
    /* @4198728 load */
    /* @4198736 constant */
    /* @4198740 add */
    /* @4198744 load */
    /* @4198752 call */
    GM_SITE(vm, 351, 4198752);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4198760 cast */
    /* @4198764 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4198844;
    /* @4198768 load */
    /* @4198776 load */
    /* @4198784 cmp */
    /* @4198788 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "y") >= GM_READ(vm, -1, "yorigin")))) goto L_4198820;
    /* @4198792 constant */
    /* @4198796 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4198804 constant */
    /* @4198808 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4198816 b */
    goto L_4198840;
    L_4198820: ;
    /* @4198820 constant */
    /* @4198832 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4198840: ;
    /* @4198840 b */
    goto L_4198864;
    L_4198844: ;
    /* @4198844 constant */
    /* @4198856 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4198864: ;
    /* @4198864 constant */
    /* @4198868 cast */
    /* @4198872 load */
    /* @4198880 load */
    /* @4198888 load */
    /* @4198896 add */
    /* @4198900 call */
    GM_SITE(vm, 351, 4198900);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4198908 cast */
    /* @4198912 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_4198928;
    /* @4198916 constant */
    /* @4198920 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_4198928: ;
    /* @4198928 constant */
    /* @4198932 cast */
    /* @4198936 load */
    /* @4198944 load */
    /* @4198952 call */
    GM_SITE(vm, 351, 4198952);
    /* @4198960 cast */
    /* @4198964 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(9)));
    if (!TRUTH(v5)) goto L_4198980;
    /* @4198968 call */
    GM_SITE(vm, 351, 4198968);
    /* @4198976 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4198980: ;
    return;
}
