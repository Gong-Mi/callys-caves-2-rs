/* generated from CODE 554 (gml_Object_obj_introduction_Step_0), source start 4846612, end 4846900. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0554(GmVM* vm) {
    Val v1;
    /* @4846612 load */
    /* @4846620 constant */
    /* @4846624 cmp */
    /* @4846628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "moving") == VAL(1)))) goto L_4846728;
    /* @4846632 load */
    /* @4846640 constant */
    /* @4846644 sub */
    /* @4846648 store */
    GM_WRITE(vm, -1, "xx1", (GM_READ(vm, -1, "xx1") - VAL(2)));
    /* @4846656 load */
    /* @4846664 constant */
    /* @4846668 sub */
    /* @4846672 store */
    GM_WRITE(vm, -1, "xx2", (GM_READ(vm, -1, "xx2") - VAL(2)));
    /* @4846680 load */
    /* @4846688 constant */
    /* @4846692 sub */
    /* @4846696 store */
    GM_WRITE(vm, -1, "xx3", (GM_READ(vm, -1, "xx3") - VAL(2)));
    /* @4846704 load */
    /* @4846712 constant */
    /* @4846716 sub */
    /* @4846720 store */
    GM_WRITE(vm, -1, "xx4", (GM_READ(vm, -1, "xx4") - VAL(2)));
    L_4846728: ;
    /* @4846728 load */
    /* @4846736 constant */
    /* @4846740 cmp */
    /* @4846744 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "moving2") == VAL(1)))) goto L_4846844;
    /* @4846748 load */
    /* @4846756 constant */
    /* @4846760 sub */
    /* @4846764 store */
    GM_WRITE(vm, -1, "xx1", (GM_READ(vm, -1, "xx1") - VAL(1)));
    /* @4846772 load */
    /* @4846780 constant */
    /* @4846784 sub */
    /* @4846788 store */
    GM_WRITE(vm, -1, "xx2", (GM_READ(vm, -1, "xx2") - VAL(1)));
    /* @4846796 load */
    /* @4846804 constant */
    /* @4846808 sub */
    /* @4846812 store */
    GM_WRITE(vm, -1, "xx3", (GM_READ(vm, -1, "xx3") - VAL(1)));
    /* @4846820 load */
    /* @4846828 constant */
    /* @4846832 sub */
    /* @4846836 store */
    GM_WRITE(vm, -1, "xx4", (GM_READ(vm, -1, "xx4") - VAL(1)));
    L_4846844: ;
    /* @4846844 load */
    /* @4846852 constant */
    /* @4846856 cmp */
    /* @4846860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "taplock") == VAL(1)))) goto L_4846900;
    /* @4846864 constant */
    /* @4846868 cast */
    /* @4846872 call */
    GM_SITE(vm, 554, 4846872);
    /* @4846880 cast */
    /* @4846884 bf */
    v1 = BOOL(GM_CALL(vm, "mouse_check_button_pressed", 1, VAL(1)));
    if (!TRUTH(v1)) goto L_4846900;
    /* @4846888 call */
    GM_SITE(vm, 554, 4846888);
    /* @4846896 popz */
    (void)(GM_CALL(vm, "instance_destroy", 0));
    L_4846900: ;
    return;
}
