/* generated from CODE 171 (gml_Object_obj_boss3_Create_0), source start 3994212, end 3994656. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0171(GmVM* vm) {
    Val v1;
    /* @3994212 constant */
    /* @3994216 store */
    GM_WRITE(vm, -1, "flashing", VAL(0));
    /* @3994224 constant */
    /* @3994228 constant */
    /* @3994232 constant */
    /* @3994236 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(9), VAL(400));
    /* @3994244 constant */
    /* @3994248 store */
    GM_WRITE(vm, -1, "poisoned", VAL(0));
    /* @3994256 constant */
    /* @3994260 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @3994268 constant */
    /* @3994272 store */
    GM_WRITE(vm, -1, "swordstunned", VAL(0));
    /* @3994280 constant */
    /* @3994284 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    /* @3994292 constant */
    /* @3994296 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @3994304 constant */
    /* @3994308 store */
    GM_WRITE(vm, -1, "xpdrop", VAL(1));
    /* @3994316 constant */
    /* @3994320 store */
    GM_WRITE(vm, -1, "facing", VAL(0));
    /* @3994328 constant */
    /* @3994332 store */
    GM_WRITE(vm, -1, "hpdrop", VAL(1));
    /* @3994340 load */
    /* @3994348 constant */
    /* @3994352 cmp */
    /* @3994356 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3994364;
    /* @3994360 b */
    goto L_3994404;
    L_3994364: ;
    /* @3994364 load */
    /* @3994372 constant */
    /* @3994376 cmp */
    /* @3994380 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_3994404;
    /* @3994384 constant */
    /* @3994388 constant */
    /* @3994392 constant */
    /* @3994396 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(90));
    L_3994404: ;
    /* @3994404 constant */
    /* @3994408 cast */
    /* @3994412 constant */
    /* @3994416 cast */
    /* @3994420 constant */
    /* @3994424 cast */
    /* @3994428 constant */
    /* @3994432 cast */
    /* @3994436 constant */
    /* @3994440 cast */
    /* @3994444 call */
    GM_SITE(vm, 171, 3994444);
    /* @3994452 store */
    v1 = GM_CALL(vm, "choose", 5, VAL(1), VAL(2), VAL(3), VAL(4), VAL(5));
    GM_WRITE(vm, -1, "coindrop", v1);
    /* @3994460 constant */
    /* @3994464 constant */
    /* @3994468 constant */
    /* @3994472 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(11), VAL(60));
    /* @3994480 load */
    /* @3994488 constant */
    /* @3994492 cmp */
    /* @3994496 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(1)))) goto L_3994524;
    /* @3994500 constant */
    /* @3994504 store */
    GM_WRITE(vm, -1, "hpboss3", VAL(850));
    /* @3994512 constant */
    /* @3994516 store */
    GM_WRITE(vm, -1, "boss3maxhp", VAL(850));
    L_3994524: ;
    /* @3994524 load */
    /* @3994532 constant */
    /* @3994536 cmp */
    /* @3994540 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(2)))) goto L_3994568;
    /* @3994544 constant */
    /* @3994548 store */
    GM_WRITE(vm, -1, "hpboss3", VAL(800));
    /* @3994556 constant */
    /* @3994560 store */
    GM_WRITE(vm, -1, "boss3maxhp", VAL(800));
    L_3994568: ;
    /* @3994568 load */
    /* @3994576 constant */
    /* @3994580 cmp */
    /* @3994584 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(3)))) goto L_3994612;
    /* @3994588 constant */
    /* @3994592 store */
    GM_WRITE(vm, -1, "hpboss3", VAL(725));
    /* @3994600 constant */
    /* @3994604 store */
    GM_WRITE(vm, -1, "boss3maxhp", VAL(725));
    L_3994612: ;
    /* @3994612 load */
    /* @3994620 constant */
    /* @3994624 cmp */
    /* @3994628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "pwr") == VAL(4)))) goto L_3994656;
    /* @3994632 constant */
    /* @3994636 store */
    GM_WRITE(vm, -1, "hpboss3", VAL(600));
    /* @3994644 constant */
    /* @3994648 store */
    GM_WRITE(vm, -1, "boss3maxhp", VAL(600));
    L_3994656: ;
    return;
}
