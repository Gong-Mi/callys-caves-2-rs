/* generated from CODE 108 (gml_Object_obj_shooter2_Alarm_1), source start 3934280, end 3934932. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0108(GmVM* vm) {
    Val v1;
    Val p3934504_0;
    Val v2;
    Val v3;
    Val v4;
    Val p3934672_0;
    Val v5;
    Val v6;
    /* @3934280 load */
    /* @3934288 constant */
    /* @3934292 cmp */
    /* @3934296 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3934304;
    /* @3934300 b */
    goto L_3934932;
    L_3934304: ;
    /* @3934304 constant */
    /* @3934308 cast */
    /* @3934312 constant */
    /* @3934316 cast */
    /* @3934320 constant */
    /* @3934324 cast */
    /* @3934328 load */
    /* @3934336 load */
    /* @3934344 load */
    /* @3934352 load */
    /* @3934360 call */
    GM_SITE(vm, 108, 3934360);
    /* @3934368 cast */
    /* @3934372 not */
    /* @3934376 bf */
    v1 = NOT(BOOL(GM_CALL(vm, "collision_line", 7, GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), VAL(34), VAL(1), VAL(1))));
    if (!TRUTH(v1)) goto L_3934876;
    /* @3934380 load */
    /* @3934388 constant */
    /* @3934392 cmp */
    /* @3934396 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3934404;
    /* @3934400 b */
    goto L_3934460;
    L_3934404: ;
    /* @3934404 load */
    /* @3934412 constant */
    /* @3934416 cmp */
    /* @3934420 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3934460;
    /* @3934424 constant */
    /* @3934428 cast */
    /* @3934432 constant */
    /* @3934436 cast */
    /* @3934440 constant */
    /* @3934444 cast */
    /* @3934448 call */
    GM_SITE(vm, 108, 3934448);
    /* @3934456 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(10), VAL(0), VAL(0)));
    L_3934460: ;
    /* @3934460 load */
    /* @3934468 constant */
    /* @3934472 cmp */
    /* @3934476 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(0)))) goto L_3934500;
    /* @3934480 load */
    /* @3934488 constant */
    /* @3934492 cmp */
    /* @3934496 b */
    p3934504_0 = NUMBOOL(GM_READ(vm, -1, "hpshooter2frozen") == VAL(0));
    goto L_3934504;
    L_3934500: ;
    /* @3934500 constant */
    p3934504_0 = VAL(0);
    L_3934504: ;
    /* @3934504 bf */
    if (!TRUTH(p3934504_0)) goto L_3934628;
    /* @3934508 constant */
    /* @3934512 constant */
    /* @3934516 constant */
    /* @3934520 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @3934528 constant */
    /* @3934532 cast */
    /* @3934536 load */
    /* @3934544 constant */
    /* @3934548 add */
    /* @3934552 load */
    /* @3934560 constant */
    /* @3934564 add */
    /* @3934568 call */
    GM_SITE(vm, 108, 3934568);
    v2 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @3934576 store */
    v4 = GM_CALL(vm, "instance_create", 3, v2, v3, VAL(48));
    GM_WRITE(vm, -1, "i1", v4);
    /* @3934584 constant */
    /* @3934588 load */
    /* @3934596 cast */
    /* @3934600 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(10));
    /* @3934608 constant */
    /* @3934612 constant */
    /* @3934616 constant */
    /* @3934620 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(8));
    L_3934628: ;
    /* @3934628 load */
    /* @3934636 constant */
    /* @3934640 cmp */
    /* @3934644 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "facing") == VAL(1)))) goto L_3934668;
    /* @3934648 load */
    /* @3934656 constant */
    /* @3934660 cmp */
    /* @3934664 b */
    p3934672_0 = NUMBOOL(GM_READ(vm, -1, "hpshooter2frozen") == VAL(0));
    goto L_3934672;
    L_3934668: ;
    /* @3934668 constant */
    p3934672_0 = VAL(0);
    L_3934672: ;
    /* @3934672 bf */
    if (!TRUTH(p3934672_0)) goto L_3934876;
    /* @3934676 load */
    /* @3934684 constant */
    /* @3934688 cmp */
    /* @3934692 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3934700;
    /* @3934696 b */
    goto L_3934756;
    L_3934700: ;
    /* @3934700 load */
    /* @3934708 constant */
    /* @3934712 cmp */
    /* @3934716 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3934756;
    /* @3934720 constant */
    /* @3934724 cast */
    /* @3934728 constant */
    /* @3934732 cast */
    /* @3934736 constant */
    /* @3934740 cast */
    /* @3934744 call */
    GM_SITE(vm, 108, 3934744);
    /* @3934752 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(10), VAL(0), VAL(0)));
    L_3934756: ;
    /* @3934756 constant */
    /* @3934760 constant */
    /* @3934764 constant */
    /* @3934768 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    /* @3934776 constant */
    /* @3934780 cast */
    /* @3934784 load */
    /* @3934792 constant */
    /* @3934796 add */
    /* @3934800 load */
    /* @3934808 constant */
    /* @3934812 sub */
    /* @3934816 call */
    GM_SITE(vm, 108, 3934816);
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(11));
    /* @3934824 store */
    v6 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(5)), v5, VAL(48));
    GM_WRITE(vm, -1, "i1", v6);
    /* @3934832 constant */
    /* @3934836 load */
    /* @3934844 cast */
    /* @3934848 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(-10));
    /* @3934856 constant */
    /* @3934860 constant */
    /* @3934864 constant */
    /* @3934868 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(6), VAL(8));
    L_3934876: ;
    /* @3934876 constant */
    /* @3934880 cast */
    /* @3934884 constant */
    /* @3934888 cast */
    /* @3934892 constant */
    /* @3934896 cast */
    /* @3934900 constant */
    /* @3934904 cast */
    /* @3934908 call */
    GM_SITE(vm, 108, 3934908);
    /* @3934916 constant */
    /* @3934920 constant */
    /* @3934924 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), GM_CALL(vm, "choose", 4, VAL(30), VAL(45), VAL(60), VAL(75)));
    L_3934932: ;
    return;
}
