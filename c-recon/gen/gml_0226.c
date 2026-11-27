/* generated from CODE 226 (gml_Object_obj_finalboss_Alarm_2), source start 4030204, end 4030680. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0226(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val v9;
    /* @4030204 load */
    /* @4030212 constant */
    /* @4030216 cmp */
    /* @4030220 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") != VAL(110)))) goto L_4030680;
    /* @4030224 constant */
    /* @4030228 cast */
    /* @4030232 load */
    /* @4030240 load */
    /* @4030248 constant */
    /* @4030252 sub */
    /* @4030256 call */
    GM_SITE(vm, 226, 4030256);
    /* @4030264 store */
    v1 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(100)), GM_READ(vm, -1, "y"), VAL(49));
    GM_WRITE(vm, -1, "bullet1", v1);
    /* @4030272 constant */
    /* @4030276 load */
    /* @4030284 cast */
    /* @4030288 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet1")), "direction", VAL(180));
    /* @4030296 constant */
    /* @4030300 cast */
    /* @4030304 load */
    /* @4030312 constant */
    /* @4030316 sub */
    /* @4030320 load */
    /* @4030328 constant */
    /* @4030332 sub */
    /* @4030336 call */
    GM_SITE(vm, 226, 4030336);
    /* @4030344 store */
    v2 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(80)), (GM_READ(vm, -1, "y") - VAL(20)), VAL(49));
    GM_WRITE(vm, -1, "bullet2", v2);
    /* @4030352 constant */
    /* @4030356 load */
    /* @4030364 cast */
    /* @4030368 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet2")), "direction", VAL(135));
    /* @4030376 constant */
    /* @4030380 cast */
    /* @4030384 load */
    /* @4030392 constant */
    /* @4030396 add */
    /* @4030400 load */
    /* @4030408 constant */
    /* @4030412 sub */
    /* @4030416 call */
    GM_SITE(vm, 226, 4030416);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4030424 store */
    v4 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(80)), v3, VAL(49));
    GM_WRITE(vm, -1, "bullet3", v4);
    /* @4030432 constant */
    /* @4030436 load */
    /* @4030444 cast */
    /* @4030448 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet3")), "direction", VAL(225));
    /* @4030456 constant */
    /* @4030460 cast */
    /* @4030464 load */
    /* @4030472 constant */
    /* @4030476 sub */
    /* @4030480 load */
    /* @4030488 call */
    GM_SITE(vm, 226, 4030488);
    /* @4030496 store */
    v5 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(20)), VAL(49));
    GM_WRITE(vm, -1, "bullet4", v5);
    /* @4030504 constant */
    /* @4030508 load */
    /* @4030516 cast */
    /* @4030520 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet4")), "direction", VAL(90));
    /* @4030528 constant */
    /* @4030532 cast */
    /* @4030536 load */
    /* @4030544 constant */
    /* @4030548 add */
    /* @4030552 load */
    /* @4030560 call */
    GM_SITE(vm, 226, 4030560);
    v6 = GM_ADD(GM_READ(vm, -1, "y"), VAL(20));
    /* @4030568 store */
    v7 = GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v6, VAL(49));
    GM_WRITE(vm, -1, "bullet5", v7);
    /* @4030576 constant */
    /* @4030580 load */
    /* @4030588 cast */
    /* @4030592 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet5")), "direction", VAL(270));
    /* @4030600 constant */
    /* @4030604 cast */
    /* @4030608 load */
    /* @4030616 constant */
    /* @4030620 sub */
    /* @4030624 load */
    /* @4030632 constant */
    /* @4030636 add */
    /* @4030640 call */
    GM_SITE(vm, 226, 4030640);
    v8 = GM_ADD(GM_READ(vm, -1, "x"), VAL(80));
    /* @4030648 store */
    v9 = GM_CALL(vm, "instance_create", 3, v8, (GM_READ(vm, -1, "y") - VAL(20)), VAL(49));
    GM_WRITE(vm, -1, "bullet6", v9);
    /* @4030656 constant */
    /* @4030660 load */
    /* @4030668 cast */
    /* @4030672 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "bullet6")), "direction", VAL(45));
    L_4030680: ;
    return;
}
