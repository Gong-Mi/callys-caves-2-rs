/* generated from CODE 48 (gml_Object_obj_enemy_Draw_0), source start 3895132, end 3895324. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0048(GmVM* vm) {
    /* @3895132 load */
    /* @3895140 constant */
    /* @3895144 cmp */
    /* @3895148 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3895260;
    /* @3895152 constant */
    /* @3895156 cast */
    /* @3895160 constant */
    /* @3895164 cast */
    /* @3895168 constant */
    /* @3895176 cast */
    /* @3895180 constant */
    /* @3895184 cast */
    /* @3895188 call */
    GM_SITE(vm, 48, 3895188);
    /* @3895196 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3895200 call */
    GM_SITE(vm, 48, 3895200);
    /* @3895208 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3895212 constant */
    /* @3895216 cast */
    /* @3895220 constant */
    /* @3895224 cast */
    /* @3895228 constant */
    /* @3895232 cast */
    /* @3895236 constant */
    /* @3895240 cast */
    /* @3895244 call */
    GM_SITE(vm, 48, 3895244);
    /* @3895252 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3895256 b */
    goto L_3895292;
    L_3895260: ;
    /* @3895260 load */
    /* @3895268 constant */
    /* @3895272 cmp */
    /* @3895276 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3895292;
    /* @3895280 call */
    GM_SITE(vm, 48, 3895280);
    /* @3895288 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3895292: ;
    /* @3895292 load */
    /* @3895300 constant */
    /* @3895304 cmp */
    /* @3895308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3895324;
    /* @3895312 constant */
    /* @3895316 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3895324: ;
    return;
}
