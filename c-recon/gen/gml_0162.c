/* generated from CODE 162 (gml_Object_obj_trex_Draw_0), source start 3983164, end 3983356. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0162(GmVM* vm) {
    /* @3983164 load */
    /* @3983172 constant */
    /* @3983176 cmp */
    /* @3983180 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3983292;
    /* @3983184 constant */
    /* @3983188 cast */
    /* @3983192 constant */
    /* @3983196 cast */
    /* @3983200 constant */
    /* @3983208 cast */
    /* @3983212 constant */
    /* @3983216 cast */
    /* @3983220 call */
    GM_SITE(vm, 162, 3983220);
    /* @3983228 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3983232 call */
    GM_SITE(vm, 162, 3983232);
    /* @3983240 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3983244 constant */
    /* @3983248 cast */
    /* @3983252 constant */
    /* @3983256 cast */
    /* @3983260 constant */
    /* @3983264 cast */
    /* @3983268 constant */
    /* @3983272 cast */
    /* @3983276 call */
    GM_SITE(vm, 162, 3983276);
    /* @3983284 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3983288 b */
    goto L_3983324;
    L_3983292: ;
    /* @3983292 load */
    /* @3983300 constant */
    /* @3983304 cmp */
    /* @3983308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3983324;
    /* @3983312 call */
    GM_SITE(vm, 162, 3983312);
    /* @3983320 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3983324: ;
    /* @3983324 load */
    /* @3983332 constant */
    /* @3983336 cmp */
    /* @3983340 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3983356;
    /* @3983344 constant */
    /* @3983348 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3983356: ;
    return;
}
