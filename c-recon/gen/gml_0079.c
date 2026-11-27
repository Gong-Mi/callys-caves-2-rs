/* generated from CODE 79 (gml_Object_obj_skeleton_Draw_0), source start 3918084, end 3918276. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0079(GmVM* vm) {
    /* @3918084 load */
    /* @3918092 constant */
    /* @3918096 cmp */
    /* @3918100 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3918212;
    /* @3918104 constant */
    /* @3918108 cast */
    /* @3918112 constant */
    /* @3918116 cast */
    /* @3918120 constant */
    /* @3918128 cast */
    /* @3918132 constant */
    /* @3918136 cast */
    /* @3918140 call */
    GM_SITE(vm, 79, 3918140);
    /* @3918148 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3918152 call */
    GM_SITE(vm, 79, 3918152);
    /* @3918160 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3918164 constant */
    /* @3918168 cast */
    /* @3918172 constant */
    /* @3918176 cast */
    /* @3918180 constant */
    /* @3918184 cast */
    /* @3918188 constant */
    /* @3918192 cast */
    /* @3918196 call */
    GM_SITE(vm, 79, 3918196);
    /* @3918204 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3918208 b */
    goto L_3918244;
    L_3918212: ;
    /* @3918212 load */
    /* @3918220 constant */
    /* @3918224 cmp */
    /* @3918228 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3918244;
    /* @3918232 call */
    GM_SITE(vm, 79, 3918232);
    /* @3918240 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3918244: ;
    /* @3918244 load */
    /* @3918252 constant */
    /* @3918256 cmp */
    /* @3918260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3918276;
    /* @3918264 constant */
    /* @3918268 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3918276: ;
    return;
}
