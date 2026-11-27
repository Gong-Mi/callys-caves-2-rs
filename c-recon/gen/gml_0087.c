/* generated from CODE 87 (gml_Object_obj_firehulk_Alarm_1), source start 3919272, end 3919660. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0087(GmVM* vm) {
    Val v1;
    /* @3919272 load */
    /* @3919280 constant */
    /* @3919284 cmp */
    /* @3919288 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3919296;
    /* @3919292 b */
    goto L_3919660;
    L_3919296: ;
    /* @3919296 load */
    /* @3919304 constant */
    /* @3919308 cmp */
    /* @3919312 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3919468;
    /* @3919316 constant */
    /* @3919320 cast */
    /* @3919324 load */
    /* @3919332 constant */
    /* @3919336 sub */
    /* @3919340 load */
    /* @3919348 constant */
    /* @3919352 add */
    /* @3919356 call */
    GM_SITE(vm, 87, 3919356);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @3919364 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(8)), VAL(53)));
    /* @3919368 constant */
    /* @3919372 constant */
    /* @3919376 constant */
    /* @3919380 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(8));
    /* @3919388 load */
    /* @3919396 constant */
    /* @3919400 cmp */
    /* @3919404 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3919412;
    /* @3919408 b */
    goto L_3919468;
    L_3919412: ;
    /* @3919412 load */
    /* @3919420 constant */
    /* @3919424 cmp */
    /* @3919428 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3919468;
    /* @3919432 constant */
    /* @3919436 cast */
    /* @3919440 constant */
    /* @3919444 cast */
    /* @3919448 constant */
    /* @3919452 cast */
    /* @3919456 call */
    GM_SITE(vm, 87, 3919456);
    /* @3919464 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(14), VAL(0), VAL(0)));
    L_3919468: ;
    /* @3919468 load */
    /* @3919476 constant */
    /* @3919480 cmp */
    /* @3919484 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3919640;
    /* @3919488 constant */
    /* @3919492 cast */
    /* @3919496 load */
    /* @3919504 constant */
    /* @3919508 sub */
    /* @3919512 load */
    /* @3919520 constant */
    /* @3919524 sub */
    /* @3919528 call */
    GM_SITE(vm, 87, 3919528);
    /* @3919536 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(8)), VAL(53)));
    /* @3919540 constant */
    /* @3919544 constant */
    /* @3919548 constant */
    /* @3919552 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(8));
    /* @3919560 load */
    /* @3919568 constant */
    /* @3919572 cmp */
    /* @3919576 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3919584;
    /* @3919580 b */
    goto L_3919640;
    L_3919584: ;
    /* @3919584 load */
    /* @3919592 constant */
    /* @3919596 cmp */
    /* @3919600 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3919640;
    /* @3919604 constant */
    /* @3919608 cast */
    /* @3919612 constant */
    /* @3919616 cast */
    /* @3919620 constant */
    /* @3919624 cast */
    /* @3919628 call */
    GM_SITE(vm, 87, 3919628);
    /* @3919636 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(14), VAL(0), VAL(0)));
    L_3919640: ;
    /* @3919640 constant */
    /* @3919644 constant */
    /* @3919648 constant */
    /* @3919652 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), VAL(60));
    L_3919660: ;
    return;
}
