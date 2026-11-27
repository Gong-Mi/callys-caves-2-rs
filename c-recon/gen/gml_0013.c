/* generated from CODE 13 (gml_Object_obj_player_Collision_69), source start 3803116, end 3803436. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0013(GmVM* vm) {
    Val p3803160_0;
    Val p3803324_0;
    /* @3803116 load */
    /* @3803124 constant */
    /* @3803128 cmp */
    /* @3803132 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "haskey") >= VAL(1)))) goto L_3803156;
    /* @3803136 load */
    /* @3803144 constant */
    /* @3803148 cmp */
    /* @3803152 b */
    p3803160_0 = NUMBOOL(GM_READ(vm, -2, "unlocked") == VAL(0));
    goto L_3803160;
    L_3803156: ;
    /* @3803156 constant */
    p3803160_0 = VAL(0);
    L_3803160: ;
    /* @3803160 bf */
    if (!TRUTH(p3803160_0)) goto L_3803280;
    /* @3803164 load */
    /* @3803172 call */
    GM_SITE(vm, 13, 3803172);
    /* @3803180 popz */
    (void)(GM_CALL(vm, "room_goto", 1, GM_READ(vm, -2, "warproom")));
    /* @3803184 load */
    /* @3803192 store */
    GM_WRITE(vm, 0, "x", GM_READ(vm, -2, "warpx"));
    /* @3803200 load */
    /* @3803208 store */
    GM_WRITE(vm, 0, "y", GM_READ(vm, -2, "warpy"));
    /* @3803216 constant */
    /* @3803220 store */
    GM_WRITE(vm, 0, "hspeed", VAL(0));
    /* @3803228 constant */
    /* @3803232 store */
    GM_WRITE(vm, 0, "vspeed", VAL(0));
    /* @3803240 load */
    /* @3803248 constant */
    /* @3803252 sub */
    /* @3803256 store */
    GM_WRITE(vm, -5, "haskey", (GM_READ(vm, -5, "haskey") - VAL(1)));
    /* @3803264 constant */
    /* @3803268 store */
    GM_WRITE(vm, -2, "unlocked", VAL(1));
    /* @3803276 b */
    goto L_3803340;
    L_3803280: ;
    /* @3803280 load */
    /* @3803288 constant */
    /* @3803292 cmp */
    /* @3803296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "haskey") == VAL(0)))) goto L_3803320;
    /* @3803300 load */
    /* @3803308 constant */
    /* @3803312 cmp */
    /* @3803316 b */
    p3803324_0 = NUMBOOL(GM_READ(vm, -2, "unlocked") == VAL(0));
    goto L_3803324;
    L_3803320: ;
    /* @3803320 constant */
    p3803324_0 = VAL(0);
    L_3803324: ;
    /* @3803324 bf */
    if (!TRUTH(p3803324_0)) goto L_3803340;
    /* @3803328 constant */
    /* @3803332 store */
    GM_WRITE(vm, -5, "warplock", VAL(1));
    L_3803340: ;
    /* @3803340 load */
    /* @3803348 constant */
    /* @3803352 cmp */
    /* @3803356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -2, "unlocked") == VAL(1)))) goto L_3803436;
    /* @3803360 load */
    /* @3803368 call */
    GM_SITE(vm, 13, 3803368);
    /* @3803376 popz */
    (void)(GM_CALL(vm, "room_goto", 1, GM_READ(vm, -2, "warproom")));
    /* @3803380 load */
    /* @3803388 store */
    GM_WRITE(vm, 0, "x", GM_READ(vm, -2, "warpx"));
    /* @3803396 load */
    /* @3803404 store */
    GM_WRITE(vm, 0, "y", GM_READ(vm, -2, "warpy"));
    /* @3803412 constant */
    /* @3803416 store */
    GM_WRITE(vm, 0, "hspeed", VAL(0));
    /* @3803424 constant */
    /* @3803428 store */
    GM_WRITE(vm, 0, "vspeed", VAL(0));
    L_3803436: ;
    return;
}
