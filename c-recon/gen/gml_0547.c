/* generated from CODE 547 (gml_Object_obj_phone_Draw_0), source start 4845704, end 4846044. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0547(GmVM* vm) {
    /* @4845704 call */
    GM_SITE(vm, 547, 4845704);
    /* @4845712 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4845716 load */
    /* @4845724 constant */
    /* @4845728 cmp */
    /* @4845732 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4845776;
    /* @4845736 constant */
    /* @4845748 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(0.8));
    /* @4845756 constant */
    /* @4845768 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(0.8));
    L_4845776: ;
    /* @4845776 load */
    /* @4845784 constant */
    /* @4845788 cmp */
    /* @4845792 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4845836;
    /* @4845796 constant */
    /* @4845808 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(0.8));
    /* @4845816 constant */
    /* @4845828 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(0.8));
    L_4845836: ;
    /* @4845836 load */
    /* @4845844 constant */
    /* @4845848 cmp */
    /* @4845852 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4845880;
    /* @4845856 constant */
    /* @4845860 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4845868 constant */
    /* @4845872 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(1));
    L_4845880: ;
    /* @4845880 load */
    /* @4845888 constant */
    /* @4845892 cmp */
    /* @4845896 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4845924;
    /* @4845900 constant */
    /* @4845904 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4845912 constant */
    /* @4845916 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(1));
    L_4845924: ;
    /* @4845924 load */
    /* @4845932 constant */
    /* @4845936 cmp */
    /* @4845940 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4845984;
    /* @4845944 constant */
    /* @4845956 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(0.8));
    /* @4845964 constant */
    /* @4845976 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(0.8));
    L_4845984: ;
    /* @4845984 load */
    /* @4845992 constant */
    /* @4845996 cmp */
    /* @4846000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4846044;
    /* @4846004 constant */
    /* @4846016 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(0.8));
    /* @4846024 constant */
    /* @4846036 store */
    GM_WRITE(vm, -1, "image_yscale", VAL(0.8));
    L_4846044: ;
    return;
}
