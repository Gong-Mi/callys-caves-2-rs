/* generated from CODE 769 (gml_Object_obj_firehulkintro_Create_0), source start 5037720, end 5037924. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0769(GmVM* vm) {
    Val v1;
    /* @5037720 load */
    /* @5037728 constant */
    /* @5037732 cmp */
    /* @5037736 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5037744;
    /* @5037740 b */
    goto L_5037800;
    L_5037744: ;
    /* @5037744 load */
    /* @5037752 constant */
    /* @5037756 cmp */
    /* @5037760 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5037800;
    /* @5037764 constant */
    /* @5037768 cast */
    /* @5037772 constant */
    /* @5037776 cast */
    /* @5037780 constant */
    /* @5037784 cast */
    /* @5037788 call */
    GM_SITE(vm, 769, 5037788);
    /* @5037796 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5037800: ;
    /* @5037800 constant */
    /* @5037804 constant */
    /* @5037808 constant */
    /* @5037812 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5037820 constant */
    /* @5037824 cast */
    /* @5037828 load */
    /* @5037836 constant */
    /* @5037840 sub */
    /* @5037844 load */
    /* @5037852 constant */
    /* @5037856 add */
    /* @5037860 call */
    GM_SITE(vm, 769, 5037860);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5037868 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5037872 constant */
    /* @5037876 cast */
    /* @5037880 load */
    /* @5037888 constant */
    /* @5037892 sub */
    /* @5037896 load */
    /* @5037904 constant */
    /* @5037908 sub */
    /* @5037912 call */
    GM_SITE(vm, 769, 5037912);
    /* @5037920 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5037924: ;
    return;
}
