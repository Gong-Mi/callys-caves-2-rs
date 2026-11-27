/* generated from CODE 242 (gml_Object_obj_bat_Step_0), source start 4040000, end 4040680. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0242(GmVM* vm) {
    Val v1;
    Val p4040260_0;
    Val v2;
    Val p4040452_0;
    Val p4040516_0;
    /* @4040000 load */
    /* @4040008 constant */
    /* @4040012 cmp */
    /* @4040016 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfour") >= VAL(0)))) goto L_4040040;
    /* @4040020 constant */
    /* @4040024 constant */
    /* @4040028 constant */
    /* @4040032 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(0));
    L_4040040: ;
    /* @4040040 load */
    /* @4040048 constant */
    /* @4040052 cmp */
    /* @4040056 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfour") <= VAL(0)))) goto L_4040080;
    /* @4040060 constant */
    /* @4040064 constant */
    /* @4040068 constant */
    /* @4040072 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4040080: ;
    /* @4040080 load */
    /* @4040088 constant */
    /* @4040092 cmp */
    /* @4040096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "awake") == VAL(1)))) goto L_4040120;
    /* @4040100 constant */
    /* @4040104 constant */
    /* @4040108 constant */
    /* @4040112 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(1));
    L_4040120: ;
    /* @4040120 load */
    /* @4040128 constant */
    /* @4040132 cmp */
    /* @4040136 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "moving") == VAL(1)))) goto L_4040188;
    /* @4040140 constant */
    /* @4040144 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(67));
    /* @4040152 constant */
    /* @4040156 cast */
    /* @4040160 load */
    /* @4040168 load */
    /* @4040176 call */
    GM_SITE(vm, 242, 4040176);
    /* @4040184 popz */
    (void)(GM_CALL(vm, "move_towards_point", 3, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(3)));
    L_4040188: ;
    /* @4040188 constant */
    /* @4040192 cast */
    /* @4040196 call */
    GM_SITE(vm, 242, 4040196);
    /* @4040204 constant */
    /* @4040208 cmp */
    /* @4040212 bf */
    v1 = NUMBOOL(GM_CALL(vm, "distance_to_object", 1, VAL(0)) <= VAL(50));
    if (!TRUTH(v1)) goto L_4040288;
    /* @4040216 load */
    /* @4040224 constant */
    /* @4040228 cmp */
    /* @4040232 bt */
    if (TRUTH(NUMBOOL(GM_READ(vm, 0, "invulnerable") == VAL(1)))) goto L_4040256;
    /* @4040236 load */
    /* @4040244 constant */
    /* @4040248 cmp */
    /* @4040252 b */
    p4040260_0 = NUMBOOL(GM_READ(vm, 0, "invulnerable2") == VAL(1));
    goto L_4040260;
    L_4040256: ;
    /* @4040256 constant */
    p4040260_0 = VAL(1);
    L_4040260: ;
    /* @4040260 bf */
    if (!TRUTH(p4040260_0)) goto L_4040288;
    /* @4040264 constant */
    /* @4040268 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4040276 constant */
    /* @4040280 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4040288: ;
    /* @4040288 load */
    /* @4040296 constant */
    /* @4040300 cmp */
    /* @4040304 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpfourfrozen") == VAL(1)))) goto L_4040408;
    /* @4040308 constant */
    /* @4040316 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @4040324 constant */
    /* @4040328 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4040336 constant */
    /* @4040340 store */
    GM_WRITE(vm, -1, "gravity", VAL(2));
    /* @4040348 constant */
    /* @4040352 cast */
    /* @4040356 load */
    /* @4040364 load */
    /* @4040372 call */
    GM_SITE(vm, 242, 4040372);
    /* @4040380 cast */
    /* @4040384 bf */
    v2 = BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34)));
    if (!TRUTH(v2)) goto L_4040408;
    /* @4040388 constant */
    /* @4040392 constant */
    /* @4040396 constant */
    /* @4040400 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(1));
    L_4040408: ;
    /* @4040408 load */
    /* @4040416 constant */
    /* @4040420 cmp */
    /* @4040424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_4040448;
    /* @4040428 load */
    /* @4040436 constant */
    /* @4040440 cmp */
    /* @4040444 b */
    p4040452_0 = NUMBOOL(GM_READ(vm, -1, "moving") == VAL(1));
    goto L_4040452;
    L_4040448: ;
    /* @4040448 constant */
    p4040452_0 = VAL(0);
    L_4040452: ;
    /* @4040452 bf */
    if (!TRUTH(p4040452_0)) goto L_4040472;
    /* @4040456 constant */
    /* @4040460 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(64));
    /* @4040468 b */
    goto L_4040532;
    L_4040472: ;
    /* @4040472 load */
    /* @4040480 constant */
    /* @4040484 cmp */
    /* @4040488 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_4040512;
    /* @4040492 load */
    /* @4040500 constant */
    /* @4040504 cmp */
    /* @4040508 b */
    p4040516_0 = NUMBOOL(GM_READ(vm, -1, "moving") == VAL(0));
    goto L_4040516;
    L_4040512: ;
    /* @4040512 constant */
    p4040516_0 = VAL(0);
    L_4040516: ;
    /* @4040516 bf */
    if (!TRUTH(p4040516_0)) goto L_4040532;
    /* @4040520 constant */
    /* @4040524 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(66));
    L_4040532: ;
    /* @4040532 load */
    /* @4040540 constant */
    /* @4040544 cmp */
    /* @4040548 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4040588;
    /* @4040552 constant */
    /* @4040556 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(64));
    /* @4040564 constant */
    /* @4040568 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4040576 constant */
    /* @4040580 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4040588: ;
    /* @4040588 load */
    /* @4040596 constant */
    /* @4040600 cmp */
    /* @4040604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4040624;
    /* @4040608 constant */
    /* @4040616 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4040624: ;
    /* @4040624 load */
    /* @4040632 constant */
    /* @4040636 cmp */
    /* @4040640 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4040680;
    /* @4040644 constant */
    /* @4040648 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4040656 constant */
    /* @4040660 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4040668 constant */
    /* @4040672 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(67));
    L_4040680: ;
    return;
}
