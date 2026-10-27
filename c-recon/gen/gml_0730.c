/* generated from CODE 730 (gml_Object_obj_batintro_Create_0), source start 5033820, end 5034024. */
/* Regenerate with scripts/ir_to_c.py; do not hand-edit. */
#include "gml.h"

void gml_0730(GmVM* vm) {
    Val v1;
    /* @5033820 load */
    /* @5033828 constant */
    /* @5033832 cmp */
    /* @5033836 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(1)))) goto L_5033844;
    /* @5033840 b */
    goto L_5033900;
    L_5033844: ;
    /* @5033844 load */
    /* @5033852 constant */
    /* @5033856 cmp */
    /* @5033860 bf */
    if (!TRUTH(NUMBOOL(GM_READ(vm, -5, "soundmute") == VAL(0)))) goto L_5033900;
    /* @5033864 constant */
    /* @5033868 cast */
    /* @5033872 constant */
    /* @5033876 cast */
    /* @5033880 constant */
    /* @5033884 cast */
    /* @5033888 call */
    GM_SITE(vm, 730, 5033888);
    /* @5033896 popz */
    (void)(GM_CALL(vm, "audio_play_sound", 3, VAL(4), VAL(0), VAL(0)));
    L_5033900: ;
    /* @5033900 constant */
    /* @5033904 constant */
    /* @5033908 constant */
    /* @5033912 store */
    GM_WRITE_ARR(vm, VAL(-1), "alarm", VAL(0), VAL(60));
    /* @5033920 constant */
    /* @5033924 cast */
    /* @5033928 load */
    /* @5033936 constant */
    /* @5033940 sub */
    /* @5033944 load */
    /* @5033952 constant */
    /* @5033956 add */
    /* @5033960 call */
    GM_SITE(vm, 730, 5033960);
    v1 = GM_ADD(GM_READ(vm, -1, "x"), VAL(320));
    /* @5033968 popz */
    (void)(GM_CALL(vm, "instance_create", 3, v1, (GM_READ(vm, -1, "y") - VAL(30)), VAL(164)));
    /* @5033972 constant */
    /* @5033976 cast */
    /* @5033980 load */
    /* @5033988 constant */
    /* @5033992 sub */
    /* @5033996 load */
    /* @5034004 constant */
    /* @5034008 sub */
    /* @5034012 call */
    GM_SITE(vm, 730, 5034012);
    /* @5034020 popz */
    (void)(GM_CALL(vm, "instance_create", 3, (GM_READ(vm, -1, "x") - VAL(320)), (GM_READ(vm, -1, "y") - VAL(5)), VAL(165)));
    L_5034024: ;
    return;
}
