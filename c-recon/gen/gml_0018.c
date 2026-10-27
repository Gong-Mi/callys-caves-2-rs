/* generated from CODE 18 (gml_Object_obj_player_Draw_0), source start 3861316, end 3861516. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0018(GmVM* vm) {
    /* @3861316 constant */
    /* @3861320 store */
    GM_WRITE(vm, -1, "mask_index", VAL(29));
    /* @3861328 load */
    /* @3861336 constant */
    /* @3861340 cmp */
    /* @3861344 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3861452;
    /* @3861348 constant */
    /* @3861352 cast */
    /* @3861356 constant */
    /* @3861360 cast */
    /* @3861364 constant */
    /* @3861368 cast */
    /* @3861372 constant */
    /* @3861376 cast */
    /* @3861380 call */
    GM_SITE(vm, 18, 3861380);
    /* @3861388 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(255), VAL(0), VAL(0)));
    /* @3861392 call */
    GM_SITE(vm, 18, 3861392);
    /* @3861400 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3861404 constant */
    /* @3861408 cast */
    /* @3861412 constant */
    /* @3861416 cast */
    /* @3861420 constant */
    /* @3861424 cast */
    /* @3861428 constant */
    /* @3861432 cast */
    /* @3861436 call */
    GM_SITE(vm, 18, 3861436);
    /* @3861444 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3861448 b */
    goto L_3861484;
    L_3861452: ;
    /* @3861452 load */
    /* @3861460 constant */
    /* @3861464 cmp */
    /* @3861468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3861484;
    /* @3861472 call */
    GM_SITE(vm, 18, 3861472);
    /* @3861480 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3861484: ;
    /* @3861484 load */
    /* @3861492 constant */
    /* @3861496 cmp */
    /* @3861500 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3861516;
    /* @3861504 constant */
    /* @3861508 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3861516: ;
    return;
}
