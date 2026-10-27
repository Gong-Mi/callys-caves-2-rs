/* generated from CODE 153 (gml_Object_obj_ghost_Draw_0), source start 3972292, end 3972484. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0153(GmVM* vm) {
    /* @3972292 load */
    /* @3972300 constant */
    /* @3972304 cmp */
    /* @3972308 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3972420;
    /* @3972312 constant */
    /* @3972316 cast */
    /* @3972320 constant */
    /* @3972324 cast */
    /* @3972328 constant */
    /* @3972336 cast */
    /* @3972340 constant */
    /* @3972344 cast */
    /* @3972348 call */
    GM_SITE(vm, 153, 3972348);
    /* @3972356 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(1), VAL(16777215), VAL(0), VAL(0)));
    /* @3972360 call */
    GM_SITE(vm, 153, 3972360);
    /* @3972368 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    /* @3972372 constant */
    /* @3972376 cast */
    /* @3972380 constant */
    /* @3972384 cast */
    /* @3972388 constant */
    /* @3972392 cast */
    /* @3972396 constant */
    /* @3972400 cast */
    /* @3972404 call */
    GM_SITE(vm, 153, 3972404);
    /* @3972412 popz */
    (void)(GM_CALL(vm, "d3d_set_fog", 4, VAL(0), VAL(0), VAL(0), VAL(0)));
    /* @3972416 b */
    goto L_3972452;
    L_3972420: ;
    /* @3972420 load */
    /* @3972428 constant */
    /* @3972432 cmp */
    /* @3972436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(0)))) goto L_3972452;
    /* @3972440 call */
    GM_SITE(vm, 153, 3972440);
    /* @3972448 popz */
    (void)(GM_CALL(vm, "draw_self", 0));
    L_3972452: ;
    /* @3972452 load */
    /* @3972460 constant */
    /* @3972464 cmp */
    /* @3972468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "flashing") == VAL(1)))) goto L_3972484;
    /* @3972472 constant */
    /* @3972476 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    L_3972484: ;
    return;
}
