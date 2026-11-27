/* generated from CODE 253 (gml_Object_obj_slime_Step_0), source start 4046692, end 4047772. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0253(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    Val v6;
    Val v7;
    Val v8;
    Val p4047292_0;
    Val v9;
    Val p4047756_0;
    /* @4046692 load */
    /* @4046700 constant */
    /* @4046704 cmp */
    /* @4046708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpslime") >= VAL(0)))) goto L_4046732;
    /* @4046712 constant */
    /* @4046716 constant */
    /* @4046720 constant */
    /* @4046724 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(0));
    L_4046732: ;
    /* @4046732 load */
    /* @4046740 constant */
    /* @4046744 cmp */
    /* @4046748 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpslime") <= VAL(0)))) goto L_4046772;
    /* @4046752 constant */
    /* @4046756 constant */
    /* @4046760 constant */
    /* @4046764 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(2), VAL(1));
    L_4046772: ;
    /* @4046772 constant */
    /* @4046776 cast */
    /* @4046780 load */
    /* @4046788 load */
    /* @4046796 add */
    /* @4046800 load */
    /* @4046808 call */
    GM_SITE(vm, 253, 4046808);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), GM_READ(vm, -1, "vspeed"));
    /* @4046816 cast */
    /* @4046820 bf */
    v2 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), v1, VAL(34)));
    if (!TRUTH(v2)) goto L_4046864;
    /* @4046824 constant */
    /* @4046828 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4046836 constant */
    /* @4046840 store */
    GM_WRITE(vm, -1, "gravity", VAL(0));
    /* @4046848 constant */
    /* @4046852 store */
    GM_WRITE(vm, -1, "gravity_direction", VAL(270));
    /* @4046860 b */
    goto L_4046896;
    L_4046864: ;
    /* @4046864 constant */
    /* @4046876 store */
    GM_WRITE(vm, -1, "gravity", VAL(0.7));
    /* @4046884 constant */
    /* @4046888 store */
    GM_WRITE(vm, -1, "gravity_direction", VAL(270));
    L_4046896: ;
    /* @4046896 constant */
    /* @4046900 cast */
    /* @4046904 load */
    /* @4046912 constant */
    /* @4046916 sub */
    /* @4046920 load */
    /* @4046928 call */
    GM_SITE(vm, 253, 4046928);
    /* @4046936 cast */
    /* @4046940 bf */
    v3 = BOOL(GM_CALL(vm, "instance_place", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(3)), VAL(34)));
    if (!TRUTH(v3)) goto L_4046976;
    /* @4046944 load */
    /* @4046952 constant */
    /* @4046956 cmp */
    /* @4046960 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpslimefrozen") == VAL(0)))) goto L_4046976;
    /* @4046964 constant */
    /* @4046968 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4046976: ;
    /* @4046976 load */
    /* @4046984 constant */
    /* @4046996 cmp */
    /* @4047000 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") >= VAL(0.01)))) goto L_4047072;
    /* @4047004 constant */
    /* @4047008 cast */
    /* @4047012 load */
    /* @4047020 constant */
    /* @4047024 sub */
    /* @4047028 load */
    /* @4047036 constant */
    /* @4047040 add */
    /* @4047044 call */
    GM_SITE(vm, 253, 4047044);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(5));
    /* @4047052 cast */
    /* @4047056 bf */
    v5 = BOOL(GM_CALL(vm, "instance_place", 3, v4, (GM_READ(vm, -1, "y") - VAL(2)), VAL(34)));
    if (!TRUTH(v5)) goto L_4047072;
    /* @4047060 constant */
    /* @4047064 store */
    GM_WRITE(vm, -1, "hspeed", VAL(-2));
    L_4047072: ;
    /* @4047072 load */
    /* @4047080 constant */
    /* @4047092 cmp */
    /* @4047096 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hspeed") <= VAL(-0.01)))) goto L_4047168;
    /* @4047100 constant */
    /* @4047104 cast */
    /* @4047108 load */
    /* @4047116 constant */
    /* @4047120 sub */
    /* @4047124 load */
    /* @4047132 constant */
    /* @4047136 sub */
    /* @4047140 call */
    GM_SITE(vm, 253, 4047140);
    /* @4047148 cast */
    /* @4047152 bf */
    v6 = BOOL(GM_CALL(vm, "instance_place", 3, (GM_READ(vm, -1, "x") - VAL(5)), (GM_READ(vm, -1, "y") - VAL(2)), VAL(34)));
    if (!TRUTH(v6)) goto L_4047168;
    /* @4047156 constant */
    /* @4047160 store */
    GM_WRITE(vm, -1, "hspeed", VAL(2));
    L_4047168: ;
    /* @4047168 load */
    /* @4047176 load */
    /* @4047184 cmp */
    /* @4047188 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "x") < GM_READ(vm, 0, "x")))) goto L_4047208;
    /* @4047192 constant */
    /* @4047196 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(1));
    /* @4047204 b */
    goto L_4047220;
    L_4047208: ;
    /* @4047208 constant */
    /* @4047212 store */
    GM_WRITE(vm, -1, "image_xscale", VAL(-1));
    L_4047220: ;
    /* @4047220 constant */
    /* @4047224 cast */
    /* @4047228 load */
    /* @4047236 constant */
    /* @4047240 add */
    /* @4047244 load */
    /* @4047252 call */
    GM_SITE(vm, 253, 4047252);
    v7 = GM_ADD(GM_READ(vm, -1, "y"), VAL(1));
    /* @4047260 cast */
    /* @4047264 bf */
    v8 = BOOL(GM_CALL(vm, "place_meeting", 3, GM_READ(vm, -1, "x"), v7, VAL(34)));
    if (!TRUTH(v8)) goto L_4047288;
    /* @4047268 load */
    /* @4047276 constant */
    /* @4047280 cmp */
    /* @4047284 b */
    p4047292_0 = NUMBOOL(GM_READ(vm, -1, "hpslimefrozen") == VAL(0));
    goto L_4047292;
    L_4047288: ;
    /* @4047288 constant */
    p4047292_0 = VAL(0);
    L_4047292: ;
    /* @4047292 bf */
    if (!TRUTH(p4047292_0)) goto L_4047408;
    /* @4047296 constant */
    /* @4047300 cast */
    /* @4047304 constant */
    /* @4047308 cast */
    /* @4047312 constant */
    /* @4047316 cast */
    /* @4047320 load */
    /* @4047328 load */
    /* @4047336 load */
    /* @4047344 load */
    /* @4047352 call */
    GM_SITE(vm, 253, 4047352);
    /* @4047360 cast */
    /* @4047364 not */
    /* @4047368 bf */
    v9 = NOT(BOOL(GM_CALL(vm, "collision_line", 7, GM_READ(vm, 0, "x"), GM_READ(vm, 0, "y"), GM_READ(vm, -1, "x"), GM_READ(vm, -1, "y"), VAL(34), VAL(0), VAL(0))));
    if (!TRUTH(v9)) goto L_4047408;
    /* @4047372 constant */
    /* @4047376 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(73));
    /* @4047384 constant */
    /* @4047388 store */
    GM_WRITE(vm, -1, "vspeed", VAL(-8));
    /* @4047396 constant */
    /* @4047400 store */
    GM_WRITE(vm, -1, "jumping", VAL(1));
    L_4047408: ;
    /* @4047408 load */
    /* @4047416 constant */
    /* @4047420 cmp */
    /* @4047424 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "hpslimefrozen") == VAL(1)))) goto L_4047472;
    /* @4047428 constant */
    /* @4047436 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16711680));
    /* @4047444 constant */
    /* @4047448 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4047456 constant */
    /* @4047460 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    /* @4047468 b */
    goto L_4047488;
    L_4047472: ;
    /* @4047472 constant */
    /* @4047480 store */
    GM_WRITE(vm, -1, "image_blend", VAL(16777215));
    L_4047488: ;
    /* @4047488 load */
    /* @4047496 constant */
    /* @4047500 cmp */
    /* @4047504 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(1)))) goto L_4047520;
    /* @4047508 constant */
    /* @4047512 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(71));
    L_4047520: ;
    /* @4047520 load */
    /* @4047528 constant */
    /* @4047532 cmp */
    /* @4047536 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(1)))) goto L_4047576;
    /* @4047540 constant */
    /* @4047544 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(71));
    /* @4047552 constant */
    /* @4047556 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4047564 constant */
    /* @4047568 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4047576: ;
    /* @4047576 load */
    /* @4047584 constant */
    /* @4047588 cmp */
    /* @4047592 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "poisoned") == VAL(1)))) goto L_4047612;
    /* @4047596 constant */
    /* @4047604 store */
    GM_WRITE(vm, -1, "image_blend", VAL(32768));
    L_4047612: ;
    /* @4047612 load */
    /* @4047620 constant */
    /* @4047624 cmp */
    /* @4047628 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "room") == VAL(110)))) goto L_4047656;
    /* @4047632 constant */
    /* @4047636 store */
    GM_WRITE(vm, -1, "hspeed", VAL(0));
    /* @4047644 constant */
    /* @4047648 store */
    GM_WRITE(vm, -1, "vspeed", VAL(0));
    L_4047656: ;
    /* @4047656 load */
    /* @4047664 constant */
    /* @4047668 cmp */
    /* @4047672 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(1)))) goto L_4047692;
    /* @4047676 constant */
    /* @4047680 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(73));
    /* @4047688 b */
    goto L_4047772;
    L_4047692: ;
    /* @4047692 load */
    /* @4047700 constant */
    /* @4047704 cmp */
    /* @4047708 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "jumping") == VAL(0)))) goto L_4047752;
    /* @4047712 load */
    /* @4047720 constant */
    /* @4047724 cmp */
    /* @4047728 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -1, "stunned") == VAL(0)))) goto L_4047752;
    /* @4047732 load */
    /* @4047740 constant */
    /* @4047744 cmp */
    /* @4047748 b */
    p4047756_0 = NUMBOOL(GM_READ(vm, -1, "swordstunned") == VAL(0));
    goto L_4047756;
    L_4047752: ;
    /* @4047752 constant */
    p4047756_0 = VAL(0);
    L_4047756: ;
    /* @4047756 bf */
    if (!TRUTH(p4047756_0)) goto L_4047772;
    /* @4047760 constant */
    /* @4047764 store */
    GM_WRITE(vm, -1, "sprite_index", VAL(68));
    L_4047772: ;
    return;
}
