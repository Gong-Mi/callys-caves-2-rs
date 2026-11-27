/* generated from CODE 799 (gml_Object_obj_bosspuff_Alarm_3), source start 5042776, end 5042900. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0799(GmVM* vm) {
    Val v1;
    /* @5042776 constant */
    /* @5042780 cast */
    /* @5042784 load */
    /* @5042792 constant */
    /* @5042796 add */
    /* @5042800 load */
    /* @5042808 call */
    GM_SITE(vm, 799, 5042808);
    v1 = GM_ADD(GM_READ(vm, -1, "y"), VAL(10));
    /* @5042816 popz */
    (void)(GM_CALL(vm, "instance_create", 3, GM_READ(vm, -1, "x"), v1, VAL(188)));
    /* @5042820 load */
    /* @5042828 constant */
    /* @5042832 cmp */
    /* @5042836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5042844;
    /* @5042840 b */
    goto L_5042900;
    L_5042844: ;
    /* @5042844 load */
    /* @5042852 constant */
    /* @5042856 cmp */
    /* @5042860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5042900;
    /* @5042864 constant */
    /* @5042868 cast */
    /* @5042872 constant */
    /* @5042876 cast */
    /* @5042880 constant */
    /* @5042884 cast */
    /* @5042888 call */
    GM_SITE(vm, 799, 5042888);
    /* @5042896 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(8), VAL(0), VAL(0)));
    L_5042900: ;
    return;
}
