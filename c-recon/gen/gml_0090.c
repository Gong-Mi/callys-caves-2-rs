/* generated from CODE 90 (gml_Object_obj_firehulk_Draw_0), source start 3926116, end 3926308. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0090(GmVM* vm) {
    /* @3926116 load */
    /* @3926124 constant */
    /* @3926128 cmp */
    /* @3926132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3926244;
    /* @3926136 constant */
    /* @3926140 cast */
    /* @3926144 constant */
    /* @3926148 cast */
    /* @3926152 constant */
    /* @3926160 cast */
    /* @3926164 constant */
    /* @3926168 cast */
    /* @3926172 call */
    GM_SITE(vm, 90, 3926172);
    /* @3926180 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3926184 call */
    GM_SITE(vm, 90, 3926184);
    /* @3926192 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3926196 constant */
    /* @3926200 cast */
    /* @3926204 constant */
    /* @3926208 cast */
    /* @3926212 constant */
    /* @3926216 cast */
    /* @3926220 constant */
    /* @3926224 cast */
    /* @3926228 call */
    GM_SITE(vm, 90, 3926228);
    /* @3926236 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3926240 b */
    goto L_3926276;
    L_3926244: ;
    /* @3926244 load */
    /* @3926252 constant */
    /* @3926256 cmp */
    /* @3926260 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3926276;
    /* @3926264 call */
    GM_SITE(vm, 90, 3926264);
    /* @3926272 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3926276: ;
    /* @3926276 load */
    /* @3926284 constant */
    /* @3926288 cmp */
    /* @3926292 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3926308;
    /* @3926296 constant */
    /* @3926300 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3926308: ;
    return;
}
