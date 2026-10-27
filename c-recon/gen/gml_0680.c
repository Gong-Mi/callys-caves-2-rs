/* generated from CODE 680 (gml_Object_obj_boulderblock_Destroy_0), source start 5015616, end 5015976. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0680(GmVM* vm) {
    Val v1;
    Val v2;
    Val v3;
    Val v4;
    Val v5;
    /* @5015616 constant */
    /* @5015620 cast */
    /* @5015624 load */
    /* @5015632 constant */
    /* @5015636 sub */
    /* @5015640 load */
    /* @5015648 call */
    GM_SITE(vm, 680, 5015648);
    /* @5015656 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), (GM_READ(vm, -1, "y") - VAL(8)), VAL(157)));
    /* @5015660 constant */
    /* @5015664 cast */
    /* @5015668 load */
    /* @5015676 load */
    /* @5015684 constant */
    /* @5015688 add */
    /* @5015692 call */
    GM_SITE(vm, 680, 5015692);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    /* @5015700 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, GM_READ(vm, -1, "y"), VAL(157)));
    /* @5015704 constant */
    /* @5015708 cast */
    /* @5015712 load */
    /* @5015720 load */
    /* @5015728 constant */
    /* @5015732 sub */
    /* @5015736 call */
    GM_SITE(vm, 680, 5015736);
    /* @5015744 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), GM_READ(vm, -1, "y"), VAL(157)));
    /* @5015748 constant */
    /* @5015752 cast */
    /* @5015756 load */
    /* @5015764 constant */
    /* @5015768 add */
    /* @5015772 load */
    /* @5015780 call */
    GM_SITE(vm, 680, 5015780);
    v2 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5015788 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v2, VAL(157)));
    /* @5015792 constant */
    /* @5015796 cast */
    /* @5015800 load */
    /* @5015808 constant */
    /* @5015812 add */
    /* @5015816 load */
    /* @5015824 constant */
    /* @5015828 sub */
    /* @5015832 call */
    GM_SITE(vm, 680, 5015832);
    v3 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5015840 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(8)), v3, VAL(157)));
    /* @5015844 constant */
    /* @5015848 cast */
    /* @5015852 load */
    /* @5015860 constant */
    /* @5015864 add */
    /* @5015868 load */
    /* @5015876 constant */
    /* @5015880 add */
    /* @5015884 call */
    GM_SITE(vm, 680, 5015884);
    v4 = GM_ADD(GM_READ(vm, -1, "x"), VAL(8));
    v5 = GM_ADD(GM_READ(vm, -1, "y"), VAL(8));
    /* @5015892 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v4, v5, VAL(157)));
    /* @5015896 load */
    /* @5015904 constant */
    /* @5015908 cmp */
    /* @5015912 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5015920;
    /* @5015916 b */
    goto L_5015976;
    L_5015920: ;
    /* @5015920 load */
    /* @5015928 constant */
    /* @5015932 cmp */
    /* @5015936 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5015976;
    /* @5015940 constant */
    /* @5015944 cast */
    /* @5015948 constant */
    /* @5015952 cast */
    /* @5015956 constant */
    /* @5015960 cast */
    /* @5015964 call */
    GM_SITE(vm, 680, 5015964);
    /* @5015972 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(7), VAL(0), VAL(0)));
    L_5015976: ;
    return;
}
