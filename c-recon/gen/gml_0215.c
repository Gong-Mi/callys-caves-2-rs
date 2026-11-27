/* generated from CODE 215 (gml_Object_obj_finalboss_Create_0), source start 4028820, end 4029272. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0215(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4028820 constant */
    /* @4028824 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @4028832 constant */
    /* @4028836 constant */
    /* @4028840 constant */
    /* @4028844 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(4), VAL(100));
    /* @4028852 constant */
    /* @4028856 cast */
    /* @4028860 constant */
    /* @4028864 cast */
    /* @4028868 constant */
    /* @4028872 cast */
    /* @4028876 constant */
    /* @4028880 cast */
    /* @4028884 constant */
    /* @4028888 cast */
    /* @4028892 call */
    GM_SITE(vm, 215, 4028892);
    /* @4028900 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "hpdrop", v1);
    /* @4028908 constant */
    /* @4028912 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @4028920 constant */
    /* @4028924 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @4028932 constant */
    /* @4028936 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @4028944 constant */
    /* @4028948 cast */
    /* @4028952 constant */
    /* @4028956 cast */
    /* @4028960 constant */
    /* @4028964 cast */
    /* @4028968 constant */
    /* @4028972 cast */
    /* @4028976 constant */
    /* @4028980 cast */
    /* @4028984 call */
    GM_SITE(vm, 215, 4028984);
    /* @4028992 store */
    v2 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v2);
    /* @4029000 constant */
    /* @4029004 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-1));
    /* @4029012 constant */
    /* @4029016 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @4029024 constant */
    /* @4029028 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @4029036 constant */
    /* @4029040 constant */
    /* @4029044 constant */
    /* @4029048 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(180));
    /* @4029056 constant */
    /* @4029060 constant */
    /* @4029064 constant */
    /* @4029068 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(270));
    /* @4029076 constant */
    /* @4029080 constant */
    /* @4029084 constant */
    /* @4029088 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(3), VAL(120));
    /* @4029096 load */
    /* @4029104 constant */
    /* @4029108 cmp */
    /* @4029112 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_4029140;
    /* @4029116 constant */
    /* @4029120 store */
    GM_WRITE(vm, -1, "hpfinalboss", VAL(1750));
    /* @4029128 constant */
    /* @4029132 store */
    GM_WRITE(vm, -1, "finalbossmaxhp", VAL(1750));
    L_4029140: ;
    /* @4029140 load */
    /* @4029148 constant */
    /* @4029152 cmp */
    /* @4029156 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_4029184;
    /* @4029160 constant */
    /* @4029164 store */
    GM_WRITE(vm, -1, "hpfinalboss", VAL(1650));
    /* @4029172 constant */
    /* @4029176 store */
    GM_WRITE(vm, -1, "finalbossmaxhp", VAL(1650));
    L_4029184: ;
    /* @4029184 load */
    /* @4029192 constant */
    /* @4029196 cmp */
    /* @4029200 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_4029228;
    /* @4029204 constant */
    /* @4029208 store */
    GM_WRITE(vm, -1, "hpfinalboss", VAL(1550));
    /* @4029216 constant */
    /* @4029220 store */
    GM_WRITE(vm, -1, "finalbossmaxhp", VAL(1550));
    L_4029228: ;
    /* @4029228 load */
    /* @4029236 constant */
    /* @4029240 cmp */
    /* @4029244 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_4029272;
    /* @4029248 constant */
    /* @4029252 store */
    GM_WRITE(vm, -1, "hpfinalboss", VAL(1350));
    /* @4029260 constant */
    /* @4029264 store */
    GM_WRITE(vm, -1, "finalbossmaxhp", VAL(1350));
    L_4029272: ;
    return;
}
