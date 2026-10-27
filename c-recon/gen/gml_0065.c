/* generated from CODE 65 (gml_Object_obj_shooter1_Alarm_1), source start 3903428, end 3903932. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0065(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @3903428 load */
    /* @3903436 constant */
    /* @3903440 cmp */
    /* @3903444 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_3903452;
    /* @3903448 b */
    goto L_3903932;
    L_3903452: ;
    /* @3903452 load */
    /* @3903460 constant */
    /* @3903464 cmp */
    /* @3903468 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "image_xscale") == VAL(1)))) goto L_3903664;
    /* @3903472 constant */
    /* @3903476 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(115));
    /* @3903484 constant */
    /* @3903488 cast */
    /* @3903492 load */
    /* @3903500 constant */
    /* @3903504 add */
    /* @3903508 load */
    /* @3903516 constant */
    /* @3903520 add */
    /* @3903524 call */
    GM_SITE(vm, 65, 3903524);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3903532 store */
    v3 = GM_CALL(vm, "instance_create", 3, v1, v2, VAL(47));
    GM_WRITE(vm, -1, "i1", v3);
    /* @3903540 constant */
    /* @3903544 load */
    /* @3903552 cast */
    /* @3903556 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(10));
    /* @3903564 load */
    /* @3903572 constant */
    /* @3903576 cmp */
    /* @3903580 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3903588;
    /* @3903584 b */
    goto L_3903644;
    L_3903588: ;
    /* @3903588 load */
    /* @3903596 constant */
    /* @3903600 cmp */
    /* @3903604 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3903644;
    /* @3903608 constant */
    /* @3903612 cast */
    /* @3903616 constant */
    /* @3903620 cast */
    /* @3903624 constant */
    /* @3903628 cast */
    /* @3903632 call */
    GM_SITE(vm, 65, 3903632);
    /* @3903640 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3903644: ;
    /* @3903644 constant */
    /* @3903648 constant */
    /* @3903652 constant */
    /* @3903656 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(10));
    L_3903664: ;
    /* @3903664 load */
    /* @3903672 constant */
    /* @3903676 cmp */
    /* @3903680 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "image_xscale") == VAL(-1)))) goto L_3903876;
    /* @3903684 constant */
    /* @3903688 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(115));
    /* @3903696 constant */
    /* @3903700 cast */
    /* @3903704 load */
    /* @3903712 constant */
    /* @3903716 add */
    /* @3903720 load */
    /* @3903728 constant */
    /* @3903732 sub */
    /* @3903736 call */
    GM_SITE(vm, 65, 3903736);
    v4 = GM_ADD(GM_READ(vm, -1, "y"), VAL(6));
    /* @3903744 store */
    v5 = GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v4, VAL(47));
    GM_WRITE(vm, -1, "i1", v5);
    /* @3903752 constant */
    /* @3903756 load */
    /* @3903764 cast */
    /* @3903768 store */
    GM_WRITE(vm, TO_INT(GM_READ(vm, -1, "i1")), "hspeed", VAL(-10));
    /* @3903776 constant */
    /* @3903780 constant */
    /* @3903784 constant */
    /* @3903788 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(10));
    /* @3903796 load */
    /* @3903804 constant */
    /* @3903808 cmp */
    /* @3903812 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_3903820;
    /* @3903816 b */
    goto L_3903876;
    L_3903820: ;
    /* @3903820 load */
    /* @3903828 constant */
    /* @3903832 cmp */
    /* @3903836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_3903876;
    /* @3903840 constant */
    /* @3903844 cast */
    /* @3903848 constant */
    /* @3903852 cast */
    /* @3903856 constant */
    /* @3903860 cast */
    /* @3903864 call */
    GM_SITE(vm, 65, 3903864);
    /* @3903872 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(24), VAL(0), VAL(0)));
    L_3903876: ;
    /* @3903876 constant */
    /* @3903880 cast */
    /* @3903884 constant */
    /* @3903888 cast */
    /* @3903892 constant */
    /* @3903896 cast */
    /* @3903900 constant */
    /* @3903904 cast */
    /* @3903908 call */
    GM_SITE(vm, 65, 3903908);
    /* @3903916 constant */
    /* @3903920 constant */
    /* @3903924 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(1), GM_CALL(vm, "choose", 4, VAL(45), VAL(50), VAL(55), VAL(60)));
    L_3903932: ;
    return;
}
