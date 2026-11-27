/* generated from CODE 186 (gml_Object_obj_boss3_Draw_0), source start 4005256, end 4005448. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0186(GmVM* vm) {
    /* @4005256 load */
    /* @4005264 constant */
    /* @4005268 cmp */
    /* @4005272 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4005384;
    /* @4005276 constant */
    /* @4005280 cast */
    /* @4005284 constant */
    /* @4005288 cast */
    /* @4005292 constant */
    /* @4005300 cast */
    /* @4005304 constant */
    /* @4005308 cast */
    /* @4005312 call */
    GM_SITE(vm, 186, 4005312);
    /* @4005320 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @4005324 call */
    GM_SITE(vm, 186, 4005324);
    /* @4005332 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @4005336 constant */
    /* @4005340 cast */
    /* @4005344 constant */
    /* @4005348 cast */
    /* @4005352 constant */
    /* @4005356 cast */
    /* @4005360 constant */
    /* @4005364 cast */
    /* @4005368 call */
    GM_SITE(vm, 186, 4005368);
    /* @4005376 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @4005380 b */
    goto L_4005416;
    L_4005384: ;
    /* @4005384 load */
    /* @4005392 constant */
    /* @4005396 cmp */
    /* @4005400 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_4005416;
    /* @4005404 call */
    GM_SITE(vm, 186, 4005404);
    /* @4005412 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_4005416: ;
    /* @4005416 load */
    /* @4005424 constant */
    /* @4005428 cmp */
    /* @4005432 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_4005448;
    /* @4005436 constant */
    /* @4005440 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_4005448: ;
    return;
}
