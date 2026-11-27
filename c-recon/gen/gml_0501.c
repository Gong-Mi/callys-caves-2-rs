/* generated from CODE 501 (gml_Object_obj_poisoniap_Mouse_7), source start 4693848, end 4694028. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0501(GmVM* vm) {
    Val v1;
    Val v2;
    /* @4693848 string */
    /* @4693856 cast */
    /* @4693860 load */
    /* @4693868 call */
    GM_SITE(vm, 501, 4693868);
    /* @4693876 constant */
    /* @4693880 cmp */
    /* @4693884 bf */
    v1 = NUMBOOL(GM_CALL(vm, "ds_map_find_value", 2, GM_READ(vm, -5, "purchaseMap"), STR_REF(971)) == VAL(0));
    if (!TRUTH(v1)) goto L_4693928;
    /* @4693888 string */
    /* @4693896 cast */
    /* @4693900 string */
    /* @4693908 cast */
    /* @4693912 call */
    GM_SITE(vm, 501, 4693912);
    /* @4693920 popz */
    (void)(GM_CALL(vm, "iap_acquire", 2, STR_REF(971), STR_REF(470)));
    /* @4693924 b */
    goto L_4694028;
    L_4693928: ;
    /* @4693928 constant */
    /* @4693932 cast */
    /* @4693936 call */
    GM_SITE(vm, 501, 4693936);
    /* @4693944 popz */
    (void)(GM_CALL(vm, "draw_set_font", 1, VAL(2)));
    /* @4693948 constant */
    /* @4693956 cast */
    /* @4693960 call */
    GM_SITE(vm, 501, 4693960);
    /* @4693968 popz */
    (void)(GM_CALL(vm, "draw_set_color", 1, VAL(16777215)));
    /* @4693972 string */
    /* @4693980 cast */
    /* @4693984 load */
    /* @4693992 constant */
    /* @4693996 sub */
    /* @4694000 load */
    /* @4694008 constant */
    /* @4694012 add */
    /* @4694016 call */
    GM_SITE(vm, 501, 4694016);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(2));
    /* @4694024 popz */
    (void)(GM_CALL(vm, "draw_text", 3, v2, (GM_READ(vm, -1, "y") - VAL(30)), STR_REF(975)));
    L_4694028: ;
    return;
}
