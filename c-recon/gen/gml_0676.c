/* generated from CODE 676 (gml_Object_obj_logparts_Create_0), source start 5015356, end 5015580. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0676(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    /* @5015356 constant */
    /* @5015360 cast */
    /* @5015364 constant */
    /* @5015368 cast */
    /* @5015372 call */
    GM_SITE(vm, 676, 5015372);
    /* @5015380 store */
    v1 = GM_CALL(vm, "choose", 2, VAL(1), VAL(2));
    GM_WRITE(vm, -1, "spritechoose", v1);
    /* @5015388 load */
    /* @5015396 constant */
    /* @5015400 cmp */
    /* @5015404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "spritechoose") == VAL(1)))) goto L_5015420;
    /* @5015408 constant */
    /* @5015412 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(167));
    L_5015420: ;
    /* @5015420 load */
    /* @5015428 constant */
    /* @5015432 cmp */
    /* @5015436 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "spritechoose") == VAL(2)))) goto L_5015452;
    /* @5015440 constant */
    /* @5015444 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(168));
    L_5015452: ;
    /* @5015452 constant */
    /* @5015456 cast */
    /* @5015460 constant */
    /* @5015464 cast */
    /* @5015468 call */
    GM_SITE(vm, 676, 5015468);
    /* @5015476 store */
    v2 = GM_CALL(vm, "choose", 2, VAL(1), VAL(-1));
    GM_WRITE(vm, -1, "image_xscale", v2);
    /* @5015484 constant */
    /* @5015488 cast */
    /* @5015492 constant */
    /* @5015496 cast */
    /* @5015500 call */
    GM_SITE(vm, 676, 5015500);
    /* @5015508 store */
    v3 = GM_CALL(vm, "choose", 2, VAL(1), VAL(-1));
    GM_WRITE(vm, -1, "image_yscale", v3);
    /* @5015516 constant */
    /* @5015520 store */
    GM_WRITE(vm, -1, "speed", VAL(7));
    /* @5015528 constant */
    /* @5015532 cast */
    /* @5015536 constant */
    /* @5015540 cast */
    /* @5015544 call */
    GM_SITE(vm, 676, 5015544);
    /* @5015552 store */
    v4 = GM_CALL(vm, "choose", 2, VAL(70), VAL(110));
    GM_WRITE(vm, -1, "direction", v4);
    /* @5015560 constant */
    /* @5015564 constant */
    /* @5015568 constant */
    /* @5015572 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(30));
    L_5015580: ;
    return;
}
