/* generated from CODE 346 (gml_Object_obj_silvercoin_Step_0), source start 4197788, end 4198048. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0346(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @4197788 constant */
    /* @4197792 cast */
    /* @4197796 load */
    /* @4197804 constant */
    /* @4197808 add */
    /* @4197812 load */
    /* @4197820 call */
    GM_SITE(vm, 346, 4197820);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4197828 cast */
    /* @4197832 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4197912;
    /* @4197836 load */
    /* @4197844 load */
    /* @4197852 cmp */
    /* @4197856 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "y") >= GM_READ(vm, -1, "yorigin")))) goto L_4197888;
    /* @4197860 constant */
    /* @4197864 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4197872 constant */
    /* @4197876 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4197884 b */
    goto L_4197908;
    L_4197888: ;
    /* @4197888 constant */
    /* @4197900 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4197908: ;
    /* @4197908 b */
    goto L_4197932;
    L_4197912: ;
    /* @4197912 constant */
    /* @4197924 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.6));
    L_4197932: ;
    /* @4197932 constant */
    /* @4197936 cast */
    /* @4197940 load */
    /* @4197948 load */
    /* @4197956 load */
    /* @4197964 add */
    /* @4197968 call */
    GM_SITE(vm, 346, 4197968);
    v3 = GM_ADD(GM_READ(vm, -1, "x"), GM_READ(vm, -1, "hspeed"));
    /* @4197976 cast */
    /* @4197980 bf */
    v4 = BOOL(GM_CALL(vm, "instance_place", 3, v3, GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v4)) goto L_4197996;
    /* @4197984 constant */
    /* @4197988 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    L_4197996: ;
    /* @4197996 constant */
    /* @4198000 cast */
    /* @4198004 load */
    /* @4198012 load */
    /* @4198020 call */
    GM_SITE(vm, 346, 4198020);
    /* @4198028 cast */
    /* @4198032 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(9)));
    if (!TRUTH(v5)) goto L_4198048;
    /* @4198036 call */
    GM_SITE(vm, 346, 4198036);
    /* @4198044 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4198048: ;
    return;
}
