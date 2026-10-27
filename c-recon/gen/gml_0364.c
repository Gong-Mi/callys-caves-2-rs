/* generated from CODE 364 (gml_Object_obj_bg_Draw_0), source start 4217056, end 4218520. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0364(GmVM* vm) {
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4217088;
    GM_WRITE(vm, -1, "drawview0", VAL(1));
    L_4217088: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4217120;
    GM_WRITE(vm, -1, "drawview1", VAL(1));
    L_4217120: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4217152;
    GM_WRITE(vm, -1, "drawview3", VAL(1));
    L_4217152: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4217184;
    GM_WRITE(vm, -1, "drawview4", VAL(1));
    L_4217184: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4217216;
    GM_WRITE(vm, -1, "drawview5", VAL(1));
    L_4217216: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4217248;
    GM_WRITE(vm, -1, "drawview6", VAL(1));
    L_4217248: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(0)))) goto L_4217520;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4217368;
    GM_SITE(vm, 364, 4217352);
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    goto L_4217520;
    L_4217368: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4217520;
    GM_SITE(vm, 364, 4217508);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4217520: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(1)))) goto L_4217616;
    GM_SITE(vm, 364, 4217604);
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    L_4217616: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(3)))) goto L_4217768;
    GM_SITE(vm, 364, 4217756);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.4), VAL(1.4), VAL(0), VAL(-1), VAL(1)));
    L_4217768: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(4)))) goto L_4217920;
    GM_SITE(vm, 364, 4217908);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.4), VAL(1.4), VAL(0), VAL(-1), VAL(1)));
    L_4217920: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(5)))) goto L_4218192;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4218040;
    GM_SITE(vm, 364, 4218024);
    (void)(GM_CALL(vm, "draw_background", 3, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48))));
    goto L_4218192;
    L_4218040: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4218192;
    GM_SITE(vm, 364, 4218180);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4218192: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "view_current") == VAL(6)))) goto L_4218520;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(113)))) goto L_4218368;
    GM_SITE(vm, 364, 4218352);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    goto L_4218520;
    L_4218368: ;
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(113)))) goto L_4218520;
    GM_SITE(vm, 364, 4218508);
    (void)(GM_CALL(vm, "draw_background_ext", 8, GM_READ(vm, -1, "bg"), GM_READ_ARR(vm, VAL(-1), "view_xview", TO_INT(GM_READ(vm, -1, "view_current"))), (GM_READ_ARR(vm, VAL(-1), "view_yview", TO_INT(GM_READ(vm, -1, "view_current"))) - VAL(48)), VAL(1.2), VAL(1.2), VAL(0), VAL(-1), VAL(1)));
    L_4218520: ;
    return;
}
