/* generated from CODE 205 (gml_Object_obj_boss5_Alarm_7), source start 4017736, end 4017948. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0205(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    /* @4017736 load */
    /* @4017744 constant */
    /* @4017748 cmp */
    /* @4017752 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_4017816;
    /* @4017756 constant */
    /* @4017760 cast */
    /* @4017764 load */
    /* @4017772 constant */
    /* @4017776 sub */
    /* @4017780 load */
    /* @4017788 constant */
    /* @4017792 sub */
    /* @4017796 call */
    GM_SITE(vm, 205, 4017796);
    /* @4017804 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(50)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4017812 b */
    goto L_4017892;
    L_4017816: ;
    /* @4017816 load */
    /* @4017824 constant */
    /* @4017828 cmp */
    /* @4017832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_4017892;
    /* @4017836 constant */
    /* @4017840 cast */
    /* @4017844 load */
    /* @4017852 constant */
    /* @4017856 sub */
    /* @4017860 load */
    /* @4017868 constant */
    /* @4017872 add */
    /* @4017876 call */
    GM_SITE(vm, 205, 4017876);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(50));
    /* @4017884 store */
    v3 = GM_CALL(vm, "instance_create", 3, v2, (GM_READ(vm, -1, "y") - VAL(5)), VAL(54));
    GM_WRITE(vm, -1, "bullet1", v3);
    L_4017892: ;
    /* @4017892 constant */
    /* @4017896 cast */
    /* @4017900 constant */
    /* @4017904 cast */
    /* @4017908 constant */
    /* @4017912 cast */
    /* @4017916 call */
    GM_SITE(vm, 205, 4017916);
    /* @4017924 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(12), VAL(0), VAL(0)));
    /* @4017928 constant */
    /* @4017932 constant */
    /* @4017936 constant */
    /* @4017940 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(8), VAL(10));
    L_4017948: ;
    return;
}
