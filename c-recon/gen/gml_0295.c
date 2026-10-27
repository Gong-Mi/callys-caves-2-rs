/* generated from CODE 295 (gml_Object_obj_boomerangthrow_Create_0), source start 4140672, end 4140920. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0295(GmVM* vm) {
    /* @4140672 constant */
    /* @4140676 store */
    GM_WRITE(vm, -1, "image_speed", VAL(0));
    /* @4140684 load */
    /* @4140692 constant */
    /* @4140696 cmp */
    /* @4140700 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(1)))) goto L_4140716;
    /* @4140704 constant */
    /* @4140708 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-5));
    L_4140716: ;
    /* @4140716 load */
    /* @4140724 constant */
    /* @4140728 cmp */
    /* @4140732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, 0, "facing") == VAL(0)))) goto L_4140748;
    /* @4140736 constant */
    /* @4140740 store */
    GM_WRITE(vm, -1, "hspeed", VAL(5));
    L_4140748: ;
    /* @4140748 constant */
    /* @4140752 constant */
    /* @4140756 constant */
    /* @4140760 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(30));
    /* @4140768 constant */
    /* @4140772 store */
    GM_WRITE(vm, -1, "boomerangreturn", VAL(0));
    /* @4140780 load */
    /* @4140788 constant */
    /* @4140792 cmp */
    /* @4140796 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") <= VAL(3)))) goto L_4140816;
    /* @4140800 constant */
    /* @4140804 store */
    GM_WRITE(vm, -1, "image_index", VAL(0));
    /* @4140812 b */
    goto L_4140920;
    L_4140816: ;
    /* @4140816 load */
    /* @4140824 constant */
    /* @4140828 cmp */
    /* @4140832 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") <= VAL(6)))) goto L_4140852;
    /* @4140836 constant */
    /* @4140840 store */
    GM_WRITE(vm, -1, "image_index", VAL(1));
    /* @4140848 b */
    goto L_4140920;
    L_4140852: ;
    /* @4140852 load */
    /* @4140860 constant */
    /* @4140864 cmp */
    /* @4140868 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") <= VAL(9)))) goto L_4140888;
    /* @4140872 constant */
    /* @4140876 store */
    GM_WRITE(vm, -1, "image_index", VAL(2));
    /* @4140884 b */
    goto L_4140920;
    L_4140888: ;
    /* @4140888 load */
    /* @4140896 constant */
    /* @4140900 cmp */
    /* @4140904 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "boomeranglevel") >= VAL(10)))) goto L_4140920;
    /* @4140908 constant */
    /* @4140912 store */
    GM_WRITE(vm, -1, "image_index", VAL(3));
    L_4140920: ;
    return;
}
