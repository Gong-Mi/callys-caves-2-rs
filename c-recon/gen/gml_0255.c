/* generated from CODE 255 (gml_Object_obj_slime_Draw_0), source start 4047800, end 4047992. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0255(GmVM* vm) {
    /* @4047800 load */
    /* @4047808 constant */
    /* @4047812 cmp */
    /* @4047816 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4047928;
    /* @4047820 constant */
    /* @4047824 cast */
    /* @4047828 constant */
    /* @4047832 cast */
    /* @4047836 constant */
    /* @4047844 cast */
    /* @4047848 constant */
    /* @4047852 cast */
    /* @4047856 call */
    GM_SITE(vm, 255, 4047856);
    /* @4047864 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4047868 call */
    GM_SITE(vm, 255, 4047868);
    /* @4047876 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4047880 constant */
    /* @4047884 cast */
    /* @4047888 constant */
    /* @4047892 cast */
    /* @4047896 constant */
    /* @4047900 cast */
    /* @4047904 constant */
    /* @4047908 cast */
    /* @4047912 call */
    GM_SITE(vm, 255, 4047912);
    /* @4047920 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4047924 b */
    goto L_4047960;
    L_4047928: ;
    /* @4047928 load */
    /* @4047936 constant */
    /* @4047940 cmp */
    /* @4047944 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4047960;
    /* @4047948 call */
    GM_SITE(vm, 255, 4047948);
    /* @4047956 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4047960: ;
    /* @4047960 load */
    /* @4047968 constant */
    /* @4047972 cmp */
    /* @4047976 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4047992;
    /* @4047980 constant */
    /* @4047984 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4047992: ;
    return;
}
