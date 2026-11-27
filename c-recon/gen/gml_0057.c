/* generated from CODE 57 (gml_Object_obj_knifebandit_Draw_0), source start 3902088, end 3902280. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0057(GmVM* vm) {
    /* @3902088 load */
    /* @3902096 constant */
    /* @3902100 cmp */
    /* @3902104 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3902216;
    /* @3902108 constant */
    /* @3902112 cast */
    /* @3902116 constant */
    /* @3902120 cast */
    /* @3902124 constant */
    /* @3902132 cast */
    /* @3902136 constant */
    /* @3902140 cast */
    /* @3902144 call */
    GM_SITE(vm, 57, 3902144);
    /* @3902152 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3902156 call */
    GM_SITE(vm, 57, 3902156);
    /* @3902164 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3902168 constant */
    /* @3902172 cast */
    /* @3902176 constant */
    /* @3902180 cast */
    /* @3902184 constant */
    /* @3902188 cast */
    /* @3902192 constant */
    /* @3902196 cast */
    /* @3902200 call */
    GM_SITE(vm, 57, 3902200);
    /* @3902208 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3902212 b */
    goto L_3902248;
    L_3902216: ;
    /* @3902216 load */
    /* @3902224 constant */
    /* @3902228 cmp */
    /* @3902232 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3902248;
    /* @3902236 call */
    GM_SITE(vm, 57, 3902236);
    /* @3902244 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3902248: ;
    /* @3902248 load */
    /* @3902256 constant */
    /* @3902260 cmp */
    /* @3902264 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3902280;
    /* @3902268 constant */
    /* @3902272 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3902280: ;
    return;
}
