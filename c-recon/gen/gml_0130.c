/* generated from CODE 130 (gml_Object_obj_enemy2_Alarm_2), source start 3951260, end 3951404. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0130(GmVM* vm) {
    Val v1;
    Val p3951312_0;
    /* @3951260 constant */
    /* @3951264 cast */
    /* @3951268 call */
    GM_SITE(vm, 130, 3951268);
    /* @3951276 constant */
    /* @3951280 cmp */
    /* @3951284 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(192));
    if (!TRUTH(v1)) goto L_3951308;
    /* @3951288 load */
    /* @3951296 constant */
    /* @3951300 cmp */
    /* @3951304 b */
    p3951312_0 = NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(0));
    goto L_3951312;
    L_3951308: ;
    /* @3951308 constant */
    p3951312_0 = VAL(0);
    L_3951312: ;
    /* @3951312 bf */
    if (!TRUTH(p3951312_0)) goto L_3951352;
    /* @3951316 constant */
    /* @3951320 store */
    GM_WRITE(vm, -1, "jumping", VAL(1));
    /* @3951328 constant */
    /* @3951332 constant */
    /* @3951336 constant */
    /* @3951340 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    /* @3951348 b */
    goto L_3951384;
    L_3951352: ;
    /* @3951352 constant */
    /* @3951356 store */
    GM_WRITE(vm, -1, "jumping", VAL(0));
    /* @3951364 constant */
    /* @3951368 constant */
    /* @3951372 constant */
    /* @3951376 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    L_3951384: ;
    /* @3951384 constant */
    /* @3951388 constant */
    /* @3951392 constant */
    /* @3951396 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(15));
    L_3951404: ;
    return;
}
